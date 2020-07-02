//BEGINNER-SCORE
//prefix:begs

// バージョン
int begsVersion;		// バージョン番号（古いリプレイ再生用）
int begsCVersion = 2;	// 現在のバージョン

// レベルアップテーブル
// 速度
int begsLevelTable[32] = 
{
	4,5,6,8,10,12,16,32,48,64,4,5,6,8,12,32,48,80,112,128,144,16,48,80,112,144,176,192,208,224,240,5120
};

// レベル
int begsLevelChange[32] = 
{
	8,19,35,40,50,60,70,80,90,100,108,119,125,131,139,149,156,164,174,180,200,212,221,232,244,256,267,277,287,295,300,10000
};

// BGM設定
int begsBgmNo[2] = {0,1};		// LV000～299,LV300
int begsFadeLv = 280;			// BGMをフェードアウトさせるレベル

// 裏段位の表示名
str begsStrSecretGradeName[19] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0～ 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9～17
	"GM"													// 18
};

// 変数
int begsModeNo = -1;			// モード番号

int begsScore[2];				// スコア

int begsLevel[2];				// レベル
int begsLevelIndex[2];			// 現在の速度番号
int begsLevelSection[2];		// 現在のセクション

int begsItemFlag[2 * 2];		// アイテム出現済みフラグ
int begsItemCounter[2];			// アイテム処理用カウンタ

int begsIsBig = 0;				// BIGかどうか
int begsBigMove = 1;			// BIG時の横移動単位
int begsGhost = 0;				// ゴーストの設定（0=LV0-99 1=常にON 2=常にOFF）
int begsLvUpBonus = 0;			// レベルアップボーナス
int begsItemHold = 0;			// アイテムをホールドできるかどうか
int begsStartLevel = 0;			// スタート時のレベル

// ランキング用変数
int begsRankingScore[10];		// スコア
int begsRankingLevel[10];		// レベル
int begsRankingTime[10];		// タイム
int begsRankingYear[10];		// ランクイン日時（年）
int begsRankingMonth[10];		// ランクイン日時（月）
int begsRankingDay[10];			// ランクイン日時（日）
int begsRankingHour[10];		// ランクイン日時（時）
int begsRankingMinute[10];		// ランクイン日時（分）
int begsRankingSecond[10];		// ランクイン日時（秒）

// イベント発生
void begsPluginEvent(int player, int event, int *param) {
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != begsModeNo)) return;
	
	if(event == 0) {
		begsModeNo = addModePlugin("BEGINNER-SCORE");	// モードを登録する
	} else if(event == 7) {
		if(!ending[player]) begsMoveInit(player);	// ブロック出現
	} else if(event == 10) {
		begsARE(player, param);	// ARE中（アイテム発動）
	} else if(event == 12) {
		if(!ending[player]) begsCalcScore(player, param[0], param[1]);	// スコア計算
	} else if(event == 15) {
		begsViewScore(player);	// スコア表示
	} else if(event == 17) {
		begsSetting(player, param);	// 設定画面
	} else if(event == 18) {
		begsPlayerInitial(player);	// 初期化処理
	} else if(event == 21) {
		begsResult(player);	// 結果表示
	} else if(event == 25) {
		begsExcellent(player, param);	// エンディング終了
	} else if(event == 28) {
		begsIncrementTime(player);	// 時間を進める
	} else if(event == 36) {
		begsStaffRoll(player);	// スタッフロール描画
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		begsSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		begsLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		begsLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		begsReplayDetail();	// リプレイ詳細
	}
}

// 初期化処理
void begsPlayerInitial(int player) {
	// バージョン
	if(!playback) begsVersion = begsCVersion;
	
	// 変数を初期化
	begsScore[player] = 0;
	
	begsItemFlag[player * 2 + 0] = 0;
	begsItemFlag[player * 2 + 1] = 0;
	begsItemCounter[player] = 0;
	
	if((begsVersion >= 2) && (begsStartLevel > 0)) {
		begsLevel[player] = begsStartLevel * 100;
		begsLevelSection[player] = begsStartLevel;
		backno = begsStartLevel;
		
		if(begsStartLevel >= 1) begsItemFlag[player * 2 + 0] = 1;
		if(begsStartLevel >= 2) begsItemFlag[player * 2 + 1] = 1;
	} else {
		begsLevel[player] = -1;
		begsLevelSection[player] = 0;
	}
	
	begsLevelIndex[player] = 0;
	
	bgmlv = begsBgmNo[0];
	framecolor[player] = 0;
	enable_combo[player] = 1;
	
	// 設定を反映させる
	IsBig[player] = begsIsBig;
	BigMove[player] = begsBigMove;
	if(begsGhost == 2) ghost[player] = 0;
	enable_item_hold[player] = begsItemHold;
	
	// 初期スピードを設定
	begsSpeedUp(player);
}

// スピードアップ
void begsSpeedUp(int player) {
	// スピードを変える
	speedtype[player] = 2;
	if(begsVersion >= 2) {
		while(begsLevel[player] >= begsLevelChange[begsLevelIndex[player]]) begsLevelIndex[player]++;
	} else {
		if(begsLevel[player] >= begsLevelChange[begsLevelIndex[player]]) begsLevelIndex[player]++;
	}
	sp[player] = begsLevelTable[begsLevelIndex[player]];
	
	// BGMフェードアウト
	if((begsLevel[player] >= begsFadeLv) && (fadelv == 0) && (!ending[player])) {
		fadelv = 1;
	}
	
	// ゴーストを消す
	if((begsLevel[player] >= 100) && (begsGhost == 0)) {
		ghost[player] = 0;
	}
}

// ブロック出現
void begsMoveInit(int player) {
	// 最初のフレームなら
	if(statc[player * 10 + 3] == 0) {
		// レベルアップ処理
		if(begsLevel[player] != 299) {
			begsLevel[player]++;
			if(begsLevel[player] == 299) PlaySE(se_lvstop);
			begsSpeedUp(player);
		}
		
		// FREE FALL出現
		if((!begsItemFlag[player * 2 + 0]) && (begsLevel[player] >= 100)) {
			PlaySE(se_lvstop);
			item_coming[player] = 28;
			begsItemFlag[player * 2 + 0] = 1;
		}
		// DEL EVEN出現
		else if((!begsItemFlag[player * 2 + 1]) && (begsLevel[player] >= 200)) {
			PlaySE(se_lvstop);
			item_coming[player] = 19;
			begsItemFlag[player * 2 + 1] = 1;
		}
	}
}

// ARE中（アイテム発動）
void begsARE(int player, int *param) {
	// FREE FALL発動中
	if(item_waiting[player] == 28) {
		begsFreeFall(player);
		param[0] = 1;
	}
	// DEL EVEN発動中
	else if(item_waiting[player] == 19) {
		begsDelEven(player);
		param[0] = 1;
	}
}

// スコア計算
void begsCalcScore(int player, int lines, int itemerase) {
	int temp, temp2, bo, bai;
	
	if(!itemerase) {
		if(begsVersion >= 1) {
			if(!begsLvUpBonus) temp = begsLevel[player] + lines;
			else temp = begsLevel[player] + lines + ((lines >= 3) * (lines - 2));
			if(temp > 300) temp = 300;
			
			temp2 = wait3[player] - bactivetime[player];
			if(temp2 < 0) temp2 = 0;
			
			bo = ((begsLevel[player] + lines) / 4 + sdrop[player] + qdrop[player] + qput[player]) * lines * cmbpts[player] + (temp / 2) + (temp2 * 7);
			bai = 6;
		} else {
			bo = (begsLevel[player] + lines) / 4 + sdrop[player] + qdrop[player] + qput[player];
			bai = (lines * 2 - 1 + cmbpts[player] - (lines * 2 - 2)) * lines * 6;
		}
		
		if(isBravo(player)) {
			// 全消しするとスコア4倍
			objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			bai = bai * 4;
		}
		
		// スコア加算
		begsScore[player] = begsScore[player] + bo * bai;
	}
	
	// レベルアップ
	if(!begsLvUpBonus) begsLevel[player] = begsLevel[player] + lines;
	else begsLevel[player] = begsLevel[player] + lines + ((lines >= 3) * (lines - 2));
	
	if(begsLevel[player] >= 300) {
		// エンディング
		PlaySE(se_ttclear);
		begsLevel[player] = 300;
		timeOn[player] = 0;
		ending[player] = 2;
		ending_timeOn[player] = 1;
		fastroll[player] = 1;
		
		// タイムボーナス
		if(gameTimer[player] < 18000) {
			temp = 1253 * (300 - (gameTimer[player] / 60));
			if(temp > 0) begsScore[player] = begsScore[player] + temp;
		}
		
		// 背景切り替え
		begsLevelSection[player]++;
		bgfadesw = 1;
		bgfadebg = begsLevelSection[player];
		
		// 音楽切り替え
		bgmlv = begsBgmNo[1];
		PlayBGM();
	} else {
		// レベルストップ音
		if(begsLevel[player] == 299) PlaySE(se_lvstop);
		
		if(begsLevel[player] >= (begsLevelSection[player] + 1) * 100) {
			// レベルアップ音
			PlaySE(se_levelup);
			
			// 背景切り替え
			begsLevelSection[player]++;
			bgfadesw = 1;
			bgfadebg = begsLevelSection[player];
		}
	}
	
	// スピードアップ
	begsSpeedUp(player);
}

// 時間を進める
void begsIncrementTime(int player) {
	int i;
	
	// Fボタンで高速ロール早送り
	if((ending_timeOn[player]) && (onRecord[player]) && (fastroll[player] == 1) && (getPressState(player, 9)))
		edrec[player] = edrec[player] + 2;
	
	// ロール終了
	if((ending[player] == 2) && (edrec[player] >= 60 * 60)) {
		ending[player] = 3;
		stat[player] = 10;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
}

// スタッフロール描画
void begsStaffRoll(int player) {
	// Fボタンで高速ロール早送り
	if((ending_timeOn[player]) && (onRecord[player]) && (fastroll[player] == 1) && (getPressState(player, 9))) {
		endtime[player] = endtime[player] + 2;
		if(endtime[player] < 3100) staff_c[player]++;
	}
}

// FREE FALL
void begsFreeFall(int player) {
	int i, j, x, y, tmp, lines, anim;
	
	// フィールド上に残っているアイテムすべて消す
	if(begsItemCounter[player] == 0) {
		cleanupItem(player);
		scanItem(player);
	}
	
	if(wait1[player] > 0) anim = wait1[player];
	else anim = 1;
	
	// アニメーション
	if(begsItemCounter[player] < anim + 25) {
		fyoffset[player] = fyoffset[player] - 2;
	} else if(begsItemCounter[player] < anim + 30) {
		fyoffset[player] = fyoffset[player] + 10;
	}
	
	// 自由落下処理
	if(begsItemCounter[player] == anim + 30) {
		PlaySE(se_gon);
		setFieldPosition(player, maxPlay);
		
		for(y = 20; y >= 0; y--) {
			for(i = 0; i < 10; i++) {
				// ブロックかつ1段下が空白なら
				if((fld[i + y * 10 + player * 220] != 0) && (fld[i + (y + 1) * 10 + player * 220] == 0)) {
					tmp = y;
					
					do {
						if(tmp + 1 > 21) break;	// 最下段に到達
						
						j = fld[i + tmp * 10 + player * 220];
						fld[i + tmp * 10 + player * 220] = 0;
						fld[i + (tmp + 1) * 10 + player * 220] = j;
						
						j = fldt[i + tmp * 10 + player * 220];
						fldt[i + tmp * 10 + player * 220] = 0;
						fldt[i + (tmp + 1) * 10 + player * 220] = j;
						
						j = fldo[i + tmp * 10 + player * 220];
						fldo[i + tmp * 10 + player * 220] = 0;
						fldo[i + (tmp + 1) * 10 + player * 220] = j;
						
						j = fldl[i + tmp * 10 + player * 220];
						fldl[i + tmp * 10 + player * 220] = 0;
						fldl[i + (tmp + 1) * 10 + player * 220] = j;
						
						j = fldi[i + tmp * 10 + player * 220];
						fldi[i + tmp * 10 + player * 220] = 0;
						fldi[i + (tmp + 1) * 10 + player * 220] = j;
						
						tmp++;
					} while(fld[i + (tmp + 1) * 10 + player * 220] == 0);
				}
			}
		}
	}
	
	// 消去判定（なければ次のステータスへ）
	if(begsItemCounter[player] == (anim * 2) + 30) {
		if(blockEraseJudge(player) == 0) {
			// 消去なし
			begsItemCounter[player] = -1;
		} else {
			// 消去あり
			PlaySE(se_erase[0]);
			lines = 0;
			
			// 消去処理
			for(i = 0; i < 22; i++) {
				if(erase[i + player * 22]) {
					lines++;
					
					for(x = 0; x < 10; x++) {
						// 消去エフェクト表示
						j = (show_all_break_effect[player] != 0);
						j = (j) || (fld[x + i * 10 + player * 220] >= 10);
						j = (j) || ((lines & 1 != 0) && (x & 1 == 1)) || ((lines & 1 == 0) && (x & 1 == 0));
						
						if((j != 0) && (breaktype != 0) && (!fldo[x + i * 10 + player * 220])) {
							objectCreate(player, 1, foffset[player] + 8 + (x * 8), fyoffset[player] + (i + 3) * 8, (x - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + lines * 250, fld[x + i * 10 + player * 220] - 1, 100);
						}
						
						// ブロックを消す
						fld[x + i * 10 + player * 220] = 0;
						fldt[x + i * 10 + player * 220] = 0;
						fldo[x + i * 10 + player * 220] = 0;
						fldl[x + i * 10 + player * 220] = 0;
						fldi[x + i * 10 + player * 220] = 0;
					}
				}
			}
		}
	}
	
	// 消去があった場合の落下処理
	if(begsItemCounter[player] == (anim * 2) + 30 + wait2[player]) {
		downFloatingBlocks(player);
		PlaySE(se_gon);
		begsItemCounter[player] = -1;
	}
	
	if(begsItemCounter[player] >= 0) {
		// カウンタ増加
		begsItemCounter[player]++;
	} else {
		// 終了
		pinchCheck(player);
		begsItemCounter[player] = 0;
		item_waiting[player] = 0;
	}
}

// DEL EVEN
void begsDelEven(int player) {
	int i, j, anim;
	
	if(wait1[player] > 0) {
		anim = wait1[player];
	} else {
		anim = 1;
	}
	
	begsItemCounter[player]++;
	
	if(begsItemCounter[player] == 1) {
		// どこを消去するか決める
		for(i = 22; i > checkFieldTop(player); i--) {
			erase[i + player * 22] = 1;
			i--;
		}
		
		// フィールド上に残っているアイテムすべて消す
		cleanupItem(player);
		scanItem(player);
		
		// 枠の色を変える
		framecolor[player] = 6;
	}
	
	// ライン消去
	if(begsItemCounter[player] < 15 + (anim * 2)) {
		for(i = 0; i < 22; i++) {
			if(erase[i + player * 22]) {
				if(begsItemCounter[player] < 16) {
					ExBltRect(sg_spr, foffset[player] + 8, fyoffset[player] + (i + 3) * 8, 8, 165 + (begsItemCounter[player] - 1) * 8, 80, 8);
				}
				
				if(begsItemCounter[player] == 1) {
					for(j = 0; j < 10; j++) {
						fld[j + i * 10 + player * 220] = 0;
						fldt[j + i * 10 + player * 220] = 0;
						fldo[j + i * 10 + player * 220] = 0;
						fldl[j + i * 10 + player * 220] = 0;
						fldi[j + i * 10 + player * 220] = 0;
					}
				}
			}
		}
	}
	
	// 落下処理
	if(begsItemCounter[player] == 15 + (anim * 2)) {
		downFloatingBlocks(player);
		PlaySE(se_gon);
	}
	
	// 終了
	if(begsItemCounter[player] > 15 + (anim * 2)) {
		for(i = 0; i < 22; i++) erase[i + player * 22] = 0;
		framecolor[player] = 0;
		pinchCheck(player);
		begsItemCounter[player] = 0;
		item_waiting[player] = 0;
	}
}

// BGM読み込み
void begsLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 2; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/2)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(begsBgmNo[i]);
		}
	}
}

// スコア表示
void begsViewScore(int player) {
	int color;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// スコア
	printTinyFont(foffset[player] + 96, fyoffset[player] + 135, "SCORE");
	sprintf(string[0], "%d", begsScore[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 143, string[0], color);
	
	// レベル（分子）
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(begsLevel[player] == -1) sprintf(string[0], "%4d", 0);	// -1なら0と表示する(内部的には最初は-1になっている)
	else sprintf(string[0], "%4d", begsLevel[player]);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// レベル（横線）
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	if(sp[player] <= 600) {
		ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22 - ((sp[player] * 24) / 660), 143, 22, 1);
	} else {
		ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 0, 143, 22, 1);
	}
	
	// レベル（分母）
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, " 300", color);
	
	// タイム
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
}

// エンディング終了
void begsExcellent(int player, int *param) {
	onRecord[player] = 0;
	statc[player * 10 + 1]++;
	
	printTinyFont(foffset[player] + 15, fyoffset[player] + 116, "BEGINNER MODE");
	printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
	
	// 花火
	if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 2]++;
	}
}

// 結果表示
void begsResult(int player) {
	if(statc[player * 10] == 0) {
		// ランキング登録
		statc[player * 10 + 1] = begsRegistRanking(player);
		if(statc[player * 10 + 1] != -1) begsSaveRanking(player);
		
		// 裏段位判定
		statc[player * 10 + 2] = checkSecretGrade(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "SCORE");
	sprintf(string[0], "%13d", begsScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", begsLevel[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "TIME");
	getTime(gameTimer[player]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[1], 0);
	
	if(statc[player * 10 + 1] != -1) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 139, "RANK");
		sprintf(string[0], "%13d", statc[player * 10 + 1] + 1);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 147, string[0], 0);
	}
	
	if(statc[player * 10 + 2] >= 4) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 159, "SECRET GRADE");
		sprintf(string[0], "%13s", begsStrSecretGradeName[statc[player * 10 + 2]]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
	}
}

// 設定画面
void begsSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(begsLoadConfig() == 0) begsSaveConfig();
	
	// ランキングを読み込み
	if(begsLoadRanking(player) == 0) begsInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "BEGINNER-SCORE OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",            7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",       7 * (cursor == 1));
		printFontGrid(2, 5, "GHOST BLOCK",    7 * (cursor == 2));
		printFontGrid(2, 6, "LEVEL UP BONUS", 7 * (cursor == 3));
		printFontGrid(2, 7, "ITEM HOLD",      7 * (cursor == 4));
		printFontGrid(2, 8, "START LEVEL",    7 * (cursor == 5));
		
		// 設定値表示
		if(!begsIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!begsBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(begsGhost == 0) sprintf(string[0], "LV100");
		else if(begsGhost == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(!begsLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(!begsItemHold) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		sprintf(string[0], "%d", begsStartLevel * 100);
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		// カーソル移動
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 5;
			if(cursor > 5) cursor = 0;
		}
		
		// 値を変更
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) begsIsBig = !begsIsBig;
			if(cursor == 1) begsBigMove = !begsBigMove;
			if(cursor == 2) {
				begsGhost = begsGhost + move;
				if(begsGhost < 0) begsGhost = 2;
				if(begsGhost > 2) begsGhost = 0;
			}
			if(cursor == 3) begsLvUpBonus = !begsLvUpBonus;
			if(cursor == 4) begsItemHold = !begsItemHold;
			if(cursor == 5) {
				begsStartLevel = begsStartLevel + move;
				if(begsStartLevel < 0) begsStartLevel = 2;
				if(begsStartLevel > 2) begsStartLevel = 0;
			}
		}
		
		// キャンセル
		if(getPushState(player, 5)) {
			PlaySE(se_move);
			param[0] = 0;
			return;
		}
		
		// 決定
		if(getPushState(player, 4)) {
			PlayWave(se_kettei);
			begsSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			begsViewRanking(player);
		}
	}
}

// 設定を保存
void begsSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x49474542;
	saveBuf[1] = 0x52454E4E;
	saveBuf[2] = 0x4F43532D;
	saveBuf[3] = 0x31764552;
	
	// 設定内容
	saveBuf[4] = begsIsBig;
	saveBuf[5] = begsBigMove;
	saveBuf[6] = begsGhost;
	saveBuf[7] = begsLvUpBonus;
	saveBuf[8] = begsItemHold;
	saveBuf[9] = begsStartLevel;
	
	SaveFile("config/BEGINNER_SCORE_CONFIG.SAV", &saveBuf, 100 * 4);
}

// 設定を読み込み
int begsLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/BEGINNER_SCORE_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x49474542) return 0;
	if(saveBuf[1] != 0x52454E4E) return 0;
	if(saveBuf[2] != 0x4F43532D) return 0;
	if(saveBuf[3] != 0x31764552) return 0;
	
	// 設定内容
	begsIsBig = saveBuf[4];
	begsBigMove = saveBuf[5];
	begsGhost = saveBuf[6];
	begsLvUpBonus = saveBuf[7];
	begsItemHold = saveBuf[8];
	begsStartLevel = saveBuf[9];
	
	return 1;
}

// リプレイ保存
void begsSaveReplay(int player) {
	saveBuf[900] = begsIsBig;
	saveBuf[901] = begsBigMove;
	saveBuf[902] = begsGhost;
	saveBuf[903] = begsLvUpBonus;
	saveBuf[904] = begsItemHold;
	saveBuf[905] = begsLevel[player];
	saveBuf[906] = begsScore[player];
	saveBuf[907] = begsVersion;
	saveBuf[908] = begsStartLevel;
}

// リプレイ読み込み
void begsLoadReplay(int player) {
	begsIsBig = saveBuf[900];
	begsBigMove = saveBuf[901];
	begsGhost = saveBuf[902];
	begsLvUpBonus = saveBuf[903];
	begsItemHold = saveBuf[904];
	begsVersion = saveBuf[907];
	begsStartLevel = saveBuf[908];
	
	begsPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void begsReplayDetail() {
	printFontGrid(1, 5, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[906]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[905]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 8, "BIG", 0);
	if(!saveBuf[900]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "BIG MOVE", 0);
	if(!saveBuf[901]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "GHOST BLOCK", 0);
	if(saveBuf[902] == 0) sprintf(string[0], "LV100");
	else if(saveBuf[902] == 1) sprintf(string[0], "ON");
	else sprintf(string[0], "OFF");
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "LEVEL UP BONUS", 0);
	if(!saveBuf[903]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "ITEM HOLD", 0);
	if(!saveBuf[904]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 12, string[0], 0);
	
	printFontGrid(1, 13, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[908] * 100);
	printFontGrid(22, 13, string[0], 0);
	
	printFontGrid(1, 14, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[907]);
	printFontGrid(22, 14, string[0], 0);
}

// ランキング保存
void begsSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 10) + 0] = begsRankingScore[i];
		saveBuf[1 + (i * 10) + 1] = begsRankingLevel[i];
		saveBuf[1 + (i * 10) + 2] = begsRankingTime[i];
		saveBuf[1 + (i * 10) + 3] = begsRankingYear[i];
		saveBuf[1 + (i * 10) + 4] = begsRankingMonth[i];
		saveBuf[1 + (i * 10) + 5] = begsRankingDay[i];
		saveBuf[1 + (i * 10) + 6] = begsRankingHour[i];
		saveBuf[1 + (i * 10) + 7] = begsRankingMinute[i];
		saveBuf[1 + (i * 10) + 8] = begsRankingSecond[i];
	}
	
	sprintf(string[0], "config/BEGINNER_SCORE_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 111 * 4);
}

// ランキング読み込み
int begsLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/BEGINNER_SCORE_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 111 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	for(i = 0; i < 10; i++) {
		begsRankingScore[i]  = saveBuf[1 + (i * 10) + 0];
		begsRankingLevel[i]  = saveBuf[1 + (i * 10) + 1];
		begsRankingTime[i]   = saveBuf[1 + (i * 10) + 2];
		begsRankingYear[i]   = saveBuf[1 + (i * 10) + 3];
		begsRankingMonth[i]  = saveBuf[1 + (i * 10) + 4];
		begsRankingDay[i]    = saveBuf[1 + (i * 10) + 5];
		begsRankingHour[i]   = saveBuf[1 + (i * 10) + 6];
		begsRankingMinute[i] = saveBuf[1 + (i * 10) + 7];
		begsRankingSecond[i] = saveBuf[1 + (i * 10) + 8];
	}
	
	return 1;
}

// ランキング初期化
void begsInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		begsRankingScore[i]  = 0;
		begsRankingLevel[i]  = 0;
		begsRankingTime[i]   = 0;
		begsRankingYear[i]   = 0;
		begsRankingMonth[i]  = 0;
		begsRankingDay[i]    = 0;
		begsRankingHour[i]   = 0;
		begsRankingMinute[i] = 0;
		begsRankingSecond[i] = 0;
	}
}

// ランキング登録
int begsRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (begsIsBig) || (begsLvUpBonus) || (begsStartLevel)) return -1;
	
	for(i = 0; i < 10; i++) {
		// ランクイン
		if( (begsScore[player] > begsRankingScore[i]) || 
		    ((begsScore[player] == begsRankingScore[i]) && (begsLevel[player] > begsRankingLevel[i])) || 
		    ((begsScore[player] == begsRankingScore[i]) && (begsLevel[player] == begsRankingLevel[i]) && (gameTimer[player] < begsRankingTime[i])) )
		{
			// ランキングをずらす
			for(j = 9; j > i; j--) {
				begsRankingScore[j]  = begsRankingScore[j - 1];
				begsRankingLevel[j]  = begsRankingLevel[j - 1];
				begsRankingTime[j]   = begsRankingTime[j - 1];
				begsRankingYear[j]   = begsRankingYear[j - 1];
				begsRankingMonth[j]  = begsRankingMonth[j - 1];
				begsRankingDay[j]    = begsRankingDay[j - 1];
				begsRankingHour[j]   = begsRankingHour[j - 1];
				begsRankingMinute[j] = begsRankingMinute[j - 1];
				begsRankingSecond[j] = begsRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			begsRankingScore[i]  = begsScore[player];
			begsRankingLevel[i]  = begsLevel[player];
			begsRankingTime[i]   = gameTimer[player];
			
			GetDateAndTime(&timebuf);
			begsRankingYear[i]   = timebuf[0];
			begsRankingMonth[i]  = timebuf[1];
			begsRankingDay[i]    = timebuf[2];
			begsRankingHour[i]   = timebuf[4];
			begsRankingMinute[i] = timebuf[5];
			begsRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void begsViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "BEGINNER-SCORE MODE RANKING", 6);
		printFontGrid(1, 3, "RANK SCORE              LEVEL TIME", 4);
		
		for(i = 0; i < 10; i++) {
			if(begsRankingLevel[i] >= 300) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, 0, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", begsRankingScore[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", begsRankingLevel[i]);
			printFontGrid(25, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(begsRankingTime[i]);
			printFontGrid(31, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// 日付と時刻
			sprintf(string[0],
			        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
			        begsRankingYear[cursor], begsRankingMonth[cursor], begsRankingDay[cursor],
			        begsRankingHour[cursor], begsRankingMinute[cursor], begsRankingSecond[cursor]);
			printFontGrid(1, 26, string[0], 0);
			
			printFontGrid(1, 28, "A/B:EXIT F:ERASE ALL", 6);
			
			// カーソル移動
			padRepeat2(player);
			
			move = 0;
			if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
				move = getPressState(player, 1) - getPressState(player, 0);
			
			if(move) {
				PlaySE(se_move);
				cursor = cursor + move;
				if(cursor < 0) cursor = 9;
				if(cursor > 9) cursor = 0;
			}
			
			// 戻る
			if(getPushState(player, 4) || getPushState(player, 5)) {
				PlaySE(se_move);
				return;
			}
			
			// ランキング消去モードへ
			if(getPushState(player, 9)) {
				PlaySE(se_shaki);
				erasemode = 1;
			}
		} else {
			printFontGrid(1, 24, "ERASE ALL RECORDS?", 2);
			printFontGrid(1, 26, "A:YES / B:NO", 2);
			
			// 消去
			if(getPushState(player, 4)) {
				PlayWave(se_kettei);
				begsInitRanking();
				begsSaveRanking(player);
				erasemode = 0;
			}
			
			// 戻る
			if(getPushState(player, 5)) {
				PlaySE(se_move);
				erasemode = 0;
			}
		}
	}
}
