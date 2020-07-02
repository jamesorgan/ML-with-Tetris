//DEVIL-NORMAL
//Special Thanks to www.tetrisconcept.com's wiki
//prefix:dvl

int dvlVersion;				// バージョン（過去のリプレイとの互換性用）
int dvlCVersion = 3;		// 現在のバージョン（dvlVersionに代入される）

// レベルアップテーブル   0, 100, 200, 300, 400, 500
int dvlWait1Table[6] = { 18,  14,  14,   8,   7,   6};	// 固定→次
int dvlWait2Table[6] = {  8,   0,   0,   6,   5,   4};	// ブロック消去
int dvlWait3Table[6] = { 30,  26,  22,  18,  15,  15};	// 接地→固定
int dvlWaittTable[6] = { 12,  12,  11,  10,   8,   8};	// 横溜め

// BGM設定
int dvlBgmListTable[3]   = {1, 2, 3};			// 使用するBGM
int dvlBgmFadeTable[3]   = {280, 480, 10000};	// フェードアウトするレベル
int dvlBgmChangeTable[3] = {300, 500, 10000};	// 切り替えるレベル
int dvlBgmIndex          = 0;					// 現在のBGM番号

// 裏段位の表示名
str dvlStrSecretGradeName[19] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0～ 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9～17
	"GM"													// 18
};

int dvlModeNo = -1;			// モード番号

int dvlLevel[2];			// レベル
int dvlScore[2];			// スコア
int dvlEndFlag[2];			// クリアフラグ

int dvlMedalStat[6 * 2];	// メダルの状態(0=なし 1=銅 2=銀 3=金)
int dvlMedalAnim[6 * 2];	// メダル獲得アニメーション用カウンタ

int dvlSTimer[2];			// セクションタイマー
int dvlSkill[2];			// ヘボリス回数
int dvlREFlag[2];			// REメダル用フラグ（0=通常 1=リカバリ中）
int dvlTotalRotate[2];		// 回転した回数

int dvlSectionTime[10 * 2];	// このプレイのセクションタイム

int dvlIsBig = 0;			// BIGかどうか
int dvlBigMove = 1;			// BIG時の横移動単位
int dvlLvUpBonus = 0;		// レベルアップボーナス
int dvlTorikan = 12300;		// LV500とりカン基準タイム (3:25:00)
int dvlStartLevel = 0;		// スタート時のレベル

// ランキング変数
int dvlRankingLevel[10];			// レベル
int dvlRankingTime[10];				// タイム
int dvlRankingEnd[10];				// クリアフラグ
int dvlRankingMedal[6 * 10];		// メダル
int dvlRankingYear[10];				// ランクイン日時（年）
int dvlRankingMonth[10];			// ランクイン日時（月）
int dvlRankingDay[10];				// ランクイン日時（日）
int dvlRankingHour[10];				// ランクイン日時（時）
int dvlRankingMinute[10];			// ランクイン日時（分）
int dvlRankingSecond[10];			// ランクイン日時（秒）

// セクションタイムランキング変数
int dvlRankingSectionTime[10];		// タイム
int dvlRankingSectionEnd[10];		// クリアフラグ
int dvlRankingSectionYear[10];		// ランクイン日時（年）
int dvlRankingSectionMonth[10];		// ランクイン日時（月）
int dvlRankingSectionDay[10];		// ランクイン日時（日）
int dvlRankingSectionHour[10];		// ランクイン日時（時）
int dvlRankingSectionMinute[10];	// ランクイン日時（分）
int dvlRankingSectionSecond[10];	// ランクイン日時（秒）

// イベント発生
void dvlPluginEvent(int player, int event, int *param) {
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != dvlModeNo)) return;
	
	if(event == 0) {
		dvlModeNo = addModePlugin("DEVIL-NORMAL");	// モードを登録する
	} else if(event == 7) {
		if(!ending[player]) dvlMoveInit(player);	// ブロック出現
	} else if(event == 12) {
		if(!ending[player]) dvlCalcScore(player, param[0]);	// スコア計算
	} else if(event == 15) {
		dvlViewScore(player);	// スコア表示
	} else if(event == 17) {
		dvlSetting(player, param);	// 設定画面
	} else if(event == 18) {
		dvlPlayerInitial(player);	// 初期化
	} else if(event == 21) {
		dvlResult(player);	// 結果表示
	} else if(event == 25) {
		dvlExcellent(player, param);	// エンディング終了
	} else if(event == 28) {
		dvlIncrementTime(player);	// 時間を進める
	} else if(event == 36) {
		dvlStaffRoll(player);	// スタッフロール描画
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		dvlSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		dvlLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		dvlLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		dvlReplayDetail(param[0]);	// リプレイ詳細
	}
}

// 初期化処理
void dvlPlayerInitial(int player) {
	int i;
	
	// バージョン設定
	if(!playback) dvlVersion = dvlCVersion;
	
	// コンボ有効
	enable_combo[player] = 1;
	
	// 枠の色を赤にする
	framecolor[player] = 2;
	
	// 変数を初期化
	if(dvlVersion >= 3) {
		if(dvlStartLevel > 0) dvlLevel[player] = dvlStartLevel;
		else dvlLevel[player] = -1;
		
		backno = dvlLevel[player] / 100;
	} else {
		dvlLevel[player] = -1;
	}
	dvlScore[player] = 0;
	dvlEndFlag[player] = 0;
	dvlSTimer[player] = 0;
	dvlSkill[player] = 0;
	dvlREFlag[player] = 0;
	dvlTotalRotate[player] = 0;
	
	for(i = 0; i < 6; i++) {
		dvlMedalStat[player * 6 + i] = 0;
		dvlMedalAnim[player * 6 + i] = -1;
	}
	
	for(i = 0; i < 10; i++) dvlSectionTime[i + player * 10] = 0;
	
	dvlBgmIndex = 0;
	bgmlv = dvlBgmListTable[dvlBgmIndex];
	
	// 設定を反映させる
	IsBig[player] = dvlIsBig;
	BigMove[player] = dvlBigMove;
	
	// 初期スピードを設定
	dvlSpeedUp(player);
}

// ブロック出現
void dvlMoveInit(int player) {
	int temp;
	
	// 最初のフレームなら
	if(statc[player * 10 + 3] == 0) {
		// レベルアップ処理
		if(dvlLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		
		if(dvlLevel[player] % 100 != temp) {
			dvlLevel[player]++;
			if(dvlLevel[player] % 100 == temp) PlaySE(se_lvstop);
			dvlSpeedUp(player);
		}
		
		// REメダル
		if(dvlMedalStat[player * 6 + 3] < 3) {
			if(dvlREFlag[player] == 0) {
				if(checkHowManyBlocks(player) >= 150) dvlREFlag[player] = 1;
			} else {
				if(checkHowManyBlocks(player) <= 70) {
					dvlREFlag[player] = 0;
					PlaySE(se_medal);
					dvlMedalStat[player * 6 + 3]++;
					dvlMedalAnim[player * 6 + 3] = 0;
				}
			}
		}
		
		// ROメダル関連
		if(dvlMedalStat[player * 6 + 4] < 3) {
			temp = brotcount[player];
			if(temp > 4) temp = 4;
			dvlTotalRotate[player] = dvlTotalRotate[player] + temp;
		}
	}
}

// スコア計算
void dvlCalcScore(int player, int lines) {
	int i, temp, bo, bai, nextsec, lv;
	
	// 上がる前のレベル
	lv = dvlLevel[player];
	
	// ヘボリス回数増加
	if(lines >= 4) {
		dvlSkill[player]++;
		
		// SKメダル獲得
		if((dvlSkill[player] == 5) || (dvlSkill[player] == 10) || (dvlSkill[player] == 17)) {
			PlaySE(se_medal);
			dvlMedalStat[player * 6 + 2]++;
			dvlMedalAnim[player * 6 + 2] = 0;
		}
	}
	
	// COメダル獲得
	if(combo2[player] == 4) {
		if(dvlMedalStat[player * 6 + 5] < 1) {
			PlaySE(se_medal);
			dvlMedalStat[player * 6 + 5] = 1;
			dvlMedalAnim[player * 6 + 5] = 0;
		}
	} else if(combo2[player] == 5) {
		if(dvlMedalStat[player * 6 + 5] < 2) {
			PlaySE(se_medal);
			dvlMedalStat[player * 6 + 5] = 2;
			dvlMedalAnim[player * 6 + 5] = 0;
		}
	} else if(combo2[player] == 7) {
		if(dvlMedalStat[player * 6 + 5] < 3) {
			PlaySE(se_medal);
			dvlMedalStat[player * 6 + 5] = 3;
			dvlMedalAnim[player * 6 + 5] = 0;
		}
	}
	
	// レベルアップ
	nextsec = dvlLevel[player] / 100 * 100 + 100;
	if(!dvlLvUpBonus) dvlLevel[player] = dvlLevel[player] + lines;
	else dvlLevel[player] = dvlLevel[player] + lines + ((lines >= 3) * (lines - 2));
	
	if(dvlLevel[player] >= 999) {
		// エンディング
		PlaySE(se_ttclear);
		dvlLevel[player] = 999;
		timeOn[player] = 0;
		ending[player] = 2;
		ending_timeOn[player] = 1;
		fastroll[player] = 1;
		dvlEndFlag[player] = 2;
		
		// STメダル獲得
		dvlMedalST(player, (nextsec / 100) - 1);
		dvlSTimer[player] = 0;
		
		// ROメダル獲得
		dvlMedalRO(player);
	} else if((dvlLevel[player] >= nextsec) && (nextsec == 500) && (gameTimer[player] > dvlTorikan) && (dvlTorikan > 0)) {
		// LV500とりカン
		PlaySE(se_ttclear);
		dvlLevel[player] = 500;
		timeOn[player] = 0;
		ending[player] = 2;
		ending_timeOn[player] = 1;
		fastroll[player] = 1;
		
		// 音楽切り替え
		if((fadelv != 0) && (dvlVersion <= 2)) {
			dvlBgmIndex++;
			bgmlv = dvlBgmListTable[dvlBgmIndex];
			PlayBGM();
		}
		
		// STメダル獲得
		dvlMedalST(player, (nextsec / 100) - 1);
		dvlSTimer[player] = 0;
		
		// スピードアップ
		if(dvlVersion >= 3) dvlSpeedUp(player);
	} else {
		// レベルストップ音
		if(dvlLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		if(dvlLevel[player] % 100 == temp) PlaySE(se_lvstop);
		
		if(dvlLevel[player] >= nextsec) {
			// レベルアップ音
			PlaySE(se_levelup);
			
			// 背景切り替え
			bgfadesw = 1;
			bgfadebg = nextsec / 100;
			
			// STメダル獲得
			dvlMedalST(player, (nextsec / 100) - 1);
			dvlSTimer[player] = 0;
			
			// ROメダル獲得
			if((nextsec == 300) || (nextsec == 700)) {
				dvlMedalRO(player);
			}
		}
		
		// スピードアップ
		dvlSpeedUp(player);
	}
	
	// スコア計算
	if(dvlVersion >= 2) {
		temp = wait3[player] - bactivetime[player];
		if(temp < 0) temp = 0;
		
		bo = ((lv + lines) / 4 + sdrop[player] + qdrop[player] + qput[player]) * lines * cmbpts[player] + (dvlLevel[player] / 2) + (temp * 7);
		bai = 1;
	} else {
		bo = (lv + lines) / 4 + sdrop[player] + qdrop[player] + qput[player];
		bai = (lines * 2 - 1 + cmbpts[player] - (lines * 2 - 2)) * lines;
	}
	
	if(isBravo(player)) {
		// 全消しするとスコア4倍
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		bai = bai * 4;
		
		// ACメダル獲得
		if(dvlMedalStat[player * 6 + 0] < 3) {
			PlaySE(se_medal);
			dvlMedalStat[player * 6 + 0]++;
			dvlMedalAnim[player * 6 + 0] = 0;
		}
	}
	
	// スコア加算
	dvlScore[player] = dvlScore[player] + (bo * bai);
}

// STメダル獲得
void dvlMedalST(int player, int section) {
	// セクションタイムを記録
	dvlSectionTime[section + player * 10] = dvlSTimer[player];
	
	// STメダル獲得判定
	if((!playback) && (!IsBig[player]) && (!dvlLvUpBonus) && (!dvlStartLevel)) {
		if((dvlSTimer[player] < dvlRankingSectionTime[section]) && (dvlMedalStat[player * 6 + 1] < 3)) {
			PlaySE(se_medal);
			dvlMedalStat[player * 6 + 1] = 3;
			dvlMedalAnim[player * 6 + 1] = 0;
		} else if((dvlSTimer[player] < dvlRankingSectionTime[section] + 300) && (dvlMedalStat[player * 6 + 1] < 2)) {
			PlaySE(se_medal);
			dvlMedalStat[player * 6 + 1] = 2;
			dvlMedalAnim[player * 6 + 1] = 0;
		} else if((dvlSTimer[player] < dvlRankingSectionTime[section] + 600) && (dvlMedalStat[player * 6 + 1] < 1)) {
			PlaySE(se_medal);
			dvlMedalStat[player * 6 + 1] = 1;
			dvlMedalAnim[player * 6 + 1] = 0;
		}
	}
}

// ROメダル獲得
void dvlMedalRO(int player) {
	int temp, temp2;
	
	temp = bdowncnt[player];
	if(temp < 1) temp = 1;
	
	temp2 = dvlTotalRotate[player] / temp;
	
	if( (temp2 >= 2) || ((temp2 == 1) && (dvlTotalRotate[player] % temp >= 2)) ) {
		PlaySE(se_medal);
		dvlMedalStat[player * 6 + 4]++;
		dvlMedalAnim[player * 6 + 4] = 0;
	}
}

// スピードアップ
void dvlSpeedUp(int player) {
	int temp, index;
	
	// 20G
	sp[player] = 1200;
	
	// スピードを変える
	index = dvlLevel[player] / 100;
	if(index < 0) index = 0;
	if(index > 5) index = 5;
	
	wait1[player] = dvlWait1Table[index];
	wait2[player] = dvlWait2Table[index];
	wait3[player] = dvlWait3Table[index];
	waitt[player] = dvlWaittTable[index];
	
	// BGMフェードアウト
	if((dvlLevel[player] >= dvlBgmFadeTable[dvlBgmIndex]) && (dvlLevel[player] < dvlBgmChangeTable[dvlBgmIndex]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// BGM切り替え
	temp = 0;
	while(dvlLevel[player] >= dvlBgmChangeTable[dvlBgmIndex]) {
		dvlBgmIndex++;
		bgmlv = dvlBgmListTable[dvlBgmIndex];
		if(onRecord[player]) temp = 1;
	}
	if(temp) PlayBGM();
}

// BGM読み込み
void dvlLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 3; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/3)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(dvlBgmListTable[i]);
		}
	}
}

// スコア表示
void dvlViewScore(int player) {
	int i, x, y, color;
	color = (count % 4 / 2) * 7;
	
	// メダル（通常）
	for(i = 0; i < 6; i++) {
		if((dvlMedalAnim[player * 6 + i] < 0) || (dvlMedalAnim[player * 6 + i] > 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 16;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			dvlDrawMedal(x, y, i, dvlMedalStat[player * 6 + i], dvlMedalAnim[player * 6 + i]);
		}
	}
	
	// メダル（アニメ中）
	for(i = 0; i < 6; i++) {
		if((dvlMedalAnim[player * 6 + i] >= 0) && (dvlMedalAnim[player * 6 + i] <= 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 16;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			dvlDrawMedal(x, y, i, dvlMedalStat[player * 6 + i], dvlMedalAnim[player * 6 + i]);
			dvlMedalAnim[player * 6 + i]++;
		}
	}
	
	// スコア
	printTinyFont(foffset[player] + 96, fyoffset[player] + 135, "SCORE");
	sprintf(string[0], "%d", dvlScore[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 143, string[0], color);
	
	// レベル（分子）
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(dvlLevel[player] == -1) sprintf(string[0], "%4d", 0);	// -1なら0と表示する(内部的には最初は-1になっている)
	else sprintf(string[0], "%4d", dvlLevel[player]);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// レベル（横線）
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 0, 143, 22, 1);
	
	// レベル（分母）
	if(ending[player]) sprintf(string[0], "%4d", dvlLevel[player]);
	else if(dvlLevel[player] >= 900) sprintf(string[0], "%4d", 999);
	else sprintf(string[0], "%4d", dvlLevel[player] / 100 * 100 + 100);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, string[0], color);
	
	// タイム
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
}

// メダルを表示
void dvlDrawMedal(int x, int y, int kind, int color, int anim) {
	int i, j, k;
	
	if(color == 0) return;
	
	if((anim >= 0) && (anim < 16)) {
		k = 16 - anim;
		i = (15 * k / 3 - 15) / 2;
		j = (12 * k / 3 - 12) / 2;
		k = 65536 * k / 3;
		if(k < 65536) {
			k = 65536;
			i = 0;
			j = 0;
		}
		ExBltRectR(sg_medal[0], x - i, y - j, kind * 16, color * 13, 15, 12, k, k);
	} else {
		ExBltRect(sg_medal[0], x, y, kind * 16, color * 13, 15, 12);
	}
}

// エンディング終了
void dvlExcellent(int player, int *param) {
	onRecord[player] = 0;
	statc[player * 10 + 1]++;
	
	if(dvlLevel[player] >= 999) {
		// 完全クリア
		printTinyFont(foffset[player] + 22, fyoffset[player] + 116, "DEVIL MODE");
		printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
		
		// 花火
		if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 30)) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			statc[player * 10 + 2]++;
		}
	} else {
		// とりカン
		if(statc[player * 10] < 220) {
			// 花火
			if((statc[player * 10 + 1] % 40 == 0) && (statc[player * 10 + 2] < 4)) {
				objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
				statc[player * 10 + 2]++;
			}
			
			// ボタンでスキップ
			if(getPushState(player, 4)) {
				statc[player * 10] = 219;
			}
		} else {
			if(statc[player * 10] == 220) objectClearPl(player);	// 花火を消す
			
			printFont(foffset[player] + 12, fyoffset[player] + 112, "BUT...", 0);
			printFont(foffset[player] + 12, fyoffset[player] + 120, "LET'S GO", 0);
			printFont(foffset[player] + 12, fyoffset[player] + 128, "BETTER", 0);
			printFont(foffset[player] + 12, fyoffset[player] + 136, "NEXT TIME", 0);
			
			// ボタンでスキップ
			if(getPushState(player, 4)) {
				statc[player * 10] = 600;
			}
		}
	}
}

// 時間を進める
void dvlIncrementTime(int player) {
	int i;
	
	// セクションタイム増加
	if(timeOn[player]) dvlSTimer[player]++;
	
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
void dvlStaffRoll(int player) {
	// Fボタンで高速ロール早送り
	if((ending_timeOn[player]) && (onRecord[player]) && (fastroll[player] == 1) && (getPressState(player, 9))) {
		endtime[player] = endtime[player] + 2;
		if(endtime[player] < 3100) staff_c[player]++;
	}
}

// 結果表示
void dvlResult(int player) {
	if(statc[player * 10] == 0) {
		// ランキング登録
		statc[player * 10 + 1] = dvlRegistRanking(player);
		statc[player * 10 + 2] = dvlUpdateSectionTimeRanking(player);
		if((statc[player * 10 + 1] != -1) || (statc[player * 10 + 2] != 0)) dvlSaveRanking(player);
		
		// 裏段位判定
		statc[player * 10 + 3] = checkSecretGrade(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 45, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 59, "SCORE");
	sprintf(string[0], "%13d", dvlScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 67, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LEVEL");
	sprintf(string[0], "%13d", dvlLevel[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "TIME");
	getTime(gameTimer[player]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[1], 0);
	
	if(statc[player * 10 + 1] != -1) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "RANK");
		sprintf(string[0], "%13d", statc[player * 10 + 1] + 1);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[0], 0);
	}
	
	if(statc[player * 10 + 2] != 0) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 139, "ST RECORDS");
		sprintf(string[0], "%13d", statc[player * 10 + 2]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 147, string[0], 0);
	}
	
	if(statc[player * 10 + 3] >= 4) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 159, "SECRET GRADE");
		sprintf(string[0], "%13s", dvlStrSecretGradeName[statc[player * 10 + 3]]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
	}
}

// 設定画面
void dvlSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(dvlLoadConfig() == 0) dvlSaveConfig();
	
	// ランキングを読み込み
	if(dvlLoadRanking(player) == 0) dvlInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "DEVIL-NORMAL OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",              7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",         7 * (cursor == 1));
		printFontGrid(2, 5, "LEVEL UP BONUS",   7 * (cursor == 2));
		printFontGrid(2, 6, "LV500 TIME LIMIT", 7 * (cursor == 3));
		printFontGrid(2, 7, "START LEVEL",      7 * (cursor == 4));
		
		// 設定値表示
		if(!dvlIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!dvlBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!dvlLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(!dvlTorikan) sprintf(string[0], "OFF");
		else getTime(dvlTorikan);
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		sprintf(string[0], "%d", dvlStartLevel);
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		// カーソル移動
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 4;
			if(cursor > 4) cursor = 0;
		}
		
		// 値を変更
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			if(cursor == 0) dvlIsBig = !dvlIsBig;
			if(cursor == 1) dvlBigMove = !dvlBigMove;
			if(cursor == 2) dvlLvUpBonus = !dvlLvUpBonus;
			if(cursor == 3) {
				dvlTorikan = dvlTorikan + (move * 60);
				if(dvlTorikan < 0) dvlTorikan = 60 * 60 * 30;
				if(dvlTorikan > 60 * 60 * 30) dvlTorikan = 0;
			}
			if(cursor == 4) {
				dvlStartLevel = dvlStartLevel + (move * 100);
				if(dvlStartLevel < 0) dvlStartLevel = 900;
				if(dvlStartLevel > 900) dvlStartLevel = 0;
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
			dvlSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			dvlViewRanking(player);
		}
	}
}

// リプレイ保存
void dvlSaveReplay(int player) {
	saveBuf[900] = dvlIsBig;
	saveBuf[901] = dvlBigMove;
	saveBuf[902] = dvlLvUpBonus;
	saveBuf[903] = dvlTorikan;
	saveBuf[904] = dvlVersion;
	saveBuf[905] = dvlLevel[player];
	saveBuf[906] = dvlScore[player];
	saveBuf[907] = dvlStartLevel;
}

// リプレイ読み込み
void dvlLoadReplay(int player) {
	dvlIsBig = saveBuf[900];
	dvlBigMove = saveBuf[901];
	dvlLvUpBonus = saveBuf[902];
	dvlTorikan = saveBuf[903];
	dvlVersion = saveBuf[904];
	dvlStartLevel = saveBuf[907];
	
	dvlPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void dvlReplayDetail(int number) {
	printFontGrid(1, 4, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[904]);
	printFontGrid(22, 4, string[0], 0);
	
	if(saveBuf[904] >= 1) {
		printFontGrid(1, 6, "SCORE", 0);
		sprintf(string[0], "%d", saveBuf[906]);
		printFontGrid(22, 6, string[0], 0);
		
		printFontGrid(1, 7, "LEVEL", 0);
		sprintf(string[0], "%d", saveBuf[905]);
		printFontGrid(22, 7, string[0], 0);
	}
	
	printFontGrid(1, 9, "BIG", 0);
	if(!saveBuf[900]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "BIG MOVE", 0);
	if(!saveBuf[901]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "LEVEL UP BONUS", 0);
	if(!saveBuf[902]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "LV500 TIME LIMIT", 0);
	if(!saveBuf[903]) sprintf(string[0], "OFF");
	else getTime(saveBuf[903]);
	printFontGrid(22, 12, string[0], 0);
	
	if(saveBuf[904] >= 3) {
		printFontGrid(1, 13, "START LEVEL", 0);
		sprintf(string[0], "%d", saveBuf[907]);
		printFontGrid(22, 13, string[0], 0);
	}
}

// 設定を保存
void dvlSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x49564544;
	saveBuf[3] = 0x31764E4C;
	
	// 設定内容
	saveBuf[4] = dvlIsBig;
	saveBuf[5] = dvlBigMove;
	saveBuf[6] = dvlLvUpBonus;
	saveBuf[7] = dvlTorikan;
	saveBuf[8] = dvlStartLevel;
	
	SaveFile("config/DEVIL_NORMAL_CONFIG.SAV", &saveBuf, 100 * 4);
}

// 設定を読み込み
int dvlLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/DEVIL_NORMAL_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x49564544) return 0;
	if(saveBuf[3] != 0x31764E4C) return 0;
	
	// 設定内容
	dvlIsBig = saveBuf[4];
	dvlBigMove = saveBuf[5];
	dvlLvUpBonus = saveBuf[6];
	dvlTorikan = saveBuf[7];
	dvlStartLevel = saveBuf[8];
	
	return 1;
}

// ランキング保存
void dvlSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0]  = dvlRankingLevel[i];
		saveBuf[1 + (i * 20) + 1]  = dvlRankingTime[i];
		saveBuf[1 + (i * 20) + 2]  = dvlRankingEnd[i];
		saveBuf[1 + (i * 20) + 3]  = dvlRankingMedal[i * 6 + 0];
		saveBuf[1 + (i * 20) + 4]  = dvlRankingMedal[i * 6 + 1];
		saveBuf[1 + (i * 20) + 5]  = dvlRankingMedal[i * 6 + 2];
		saveBuf[1 + (i * 20) + 6]  = dvlRankingMedal[i * 6 + 3];
		saveBuf[1 + (i * 20) + 7]  = dvlRankingMedal[i * 6 + 4];
		saveBuf[1 + (i * 20) + 8]  = dvlRankingMedal[i * 6 + 5];
		saveBuf[1 + (i * 20) + 9]  = dvlRankingYear[i];
		saveBuf[1 + (i * 20) + 10] = dvlRankingMonth[i];
		saveBuf[1 + (i * 20) + 11] = dvlRankingDay[i];
		saveBuf[1 + (i * 20) + 12] = dvlRankingHour[i];
		saveBuf[1 + (i * 20) + 13] = dvlRankingMinute[i];
		saveBuf[1 + (i * 20) + 14] = dvlRankingSecond[i];
	}
	
	// セクションタイムランキング
	for(i = 0; i < 10; i++) {
		saveBuf[221 + (i * 10) + 0] = dvlRankingSectionTime[i];
		saveBuf[221 + (i * 10) + 1] = dvlRankingSectionEnd[i];
		saveBuf[221 + (i * 10) + 2] = dvlRankingSectionYear[i];
		saveBuf[221 + (i * 10) + 3] = dvlRankingSectionMonth[i];
		saveBuf[221 + (i * 10) + 4] = dvlRankingSectionDay[i];
		saveBuf[221 + (i * 10) + 5] = dvlRankingSectionHour[i];
		saveBuf[221 + (i * 10) + 6] = dvlRankingSectionMinute[i];
		saveBuf[221 + (i * 10) + 7] = dvlRankingSectionSecond[i];
	}
	
	sprintf(string[0], "config/DEVIL_NORMAL_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 331 * 4);
}

// ランキング読み込み
int dvlLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/DEVIL_NORMAL_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 331 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		dvlRankingLevel[i]         = saveBuf[1 + (i * 20) + 0];
		dvlRankingTime[i]          = saveBuf[1 + (i * 20) + 1];
		dvlRankingEnd[i]           = saveBuf[1 + (i * 20) + 2];
		dvlRankingMedal[i * 6 + 0] = saveBuf[1 + (i * 20) + 3];
		dvlRankingMedal[i * 6 + 1] = saveBuf[1 + (i * 20) + 4];
		dvlRankingMedal[i * 6 + 2] = saveBuf[1 + (i * 20) + 5];
		dvlRankingMedal[i * 6 + 3] = saveBuf[1 + (i * 20) + 6];
		dvlRankingMedal[i * 6 + 4] = saveBuf[1 + (i * 20) + 7];
		dvlRankingMedal[i * 6 + 5] = saveBuf[1 + (i * 20) + 8];
		dvlRankingYear[i]          = saveBuf[1 + (i * 20) + 9];
		dvlRankingMonth[i]         = saveBuf[1 + (i * 20) + 10];
		dvlRankingDay[i]           = saveBuf[1 + (i * 20) + 11];
		dvlRankingHour[i]          = saveBuf[1 + (i * 20) + 12];
		dvlRankingMinute[i]        = saveBuf[1 + (i * 20) + 13];
		dvlRankingSecond[i]        = saveBuf[1 + (i * 20) + 14];
	}
	
	// セクションタイムランキング
	for(i = 0; i < 10; i++) {
		dvlRankingSectionTime[i]   = saveBuf[221 + (i * 10) + 0];
		dvlRankingSectionEnd[i]    = saveBuf[221 + (i * 10) + 1];
		dvlRankingSectionYear[i]   = saveBuf[221 + (i * 10) + 2];
		dvlRankingSectionMonth[i]  = saveBuf[221 + (i * 10) + 3];
		dvlRankingSectionDay[i]    = saveBuf[221 + (i * 10) + 4];
		dvlRankingSectionHour[i]   = saveBuf[221 + (i * 10) + 5];
		dvlRankingSectionMinute[i] = saveBuf[221 + (i * 10) + 6];
		dvlRankingSectionSecond[i] = saveBuf[221 + (i * 10) + 7];
	}
	
	return 1;
}

// ランキング初期化
void dvlInitRanking() {
	int i;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		dvlRankingLevel[i]         = 0;
		dvlRankingTime[i]          = 0;
		dvlRankingEnd[i]           = 0;
		dvlRankingMedal[i * 6 + 0] = 0;
		dvlRankingMedal[i * 6 + 1] = 0;
		dvlRankingMedal[i * 6 + 2] = 0;
		dvlRankingMedal[i * 6 + 3] = 0;
		dvlRankingMedal[i * 6 + 4] = 0;
		dvlRankingMedal[i * 6 + 5] = 0;
		dvlRankingYear[i]          = 0;
		dvlRankingMonth[i]         = 0;
		dvlRankingDay[i]           = 0;
		dvlRankingHour[i]          = 0;
		dvlRankingMinute[i]        = 0;
		dvlRankingSecond[i]        = 0;
	}
	
	// セクションタイムランキング
	for(i = 0; i < 10; i++) {
		dvlRankingSectionTime[i]   = 5400;
		dvlRankingSectionEnd[i]    = 0;
		dvlRankingSectionYear[i]   = 0;
		dvlRankingSectionMonth[i]  = 0;
		dvlRankingSectionDay[i]    = 0;
		dvlRankingSectionHour[i]   = 0;
		dvlRankingSectionMinute[i] = 0;
		dvlRankingSectionSecond[i] = 0;
	}
}

// ランキング登録
int dvlRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (dvlLvUpBonus) || (dvlStartLevel)) return -1;
	
	for(i = 0; i < 10; i++) {
		// ランクイン
		if(
		    (dvlEndFlag[player] > dvlRankingEnd[i]) || 
		    ((dvlEndFlag[player] == dvlRankingEnd[i]) && (dvlLevel[player] > dvlRankingLevel[i])) || 
		    ((dvlEndFlag[player] == dvlRankingEnd[i]) && (dvlLevel[player] == dvlRankingLevel[i]) && (gameTimer[player] < dvlRankingTime[i]))
		  )
		{
			// ランキングをずらす
			for(j = 9; j > i; j--) {
				dvlRankingLevel[j]         = dvlRankingLevel[j - 1];
				dvlRankingTime[j]          = dvlRankingTime[j - 1];
				dvlRankingEnd[j]           = dvlRankingEnd[j - 1];
				dvlRankingMedal[j * 6 + 0] = dvlRankingMedal[(j - 1) * 6 + 0];
				dvlRankingMedal[j * 6 + 1] = dvlRankingMedal[(j - 1) * 6 + 1];
				dvlRankingMedal[j * 6 + 2] = dvlRankingMedal[(j - 1) * 6 + 2];
				dvlRankingMedal[j * 6 + 3] = dvlRankingMedal[(j - 1) * 6 + 3];
				dvlRankingMedal[j * 6 + 4] = dvlRankingMedal[(j - 1) * 6 + 4];
				dvlRankingMedal[j * 6 + 5] = dvlRankingMedal[(j - 1) * 6 + 5];
				dvlRankingYear[j]          = dvlRankingYear[j - 1];
				dvlRankingMonth[j]         = dvlRankingMonth[j - 1];
				dvlRankingDay[j]           = dvlRankingDay[j - 1];
				dvlRankingHour[j]          = dvlRankingHour[j - 1];
				dvlRankingMinute[j]        = dvlRankingMinute[j - 1];
				dvlRankingSecond[j]        = dvlRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			dvlRankingLevel[i]         = dvlLevel[player];
			dvlRankingTime[i]          = gameTimer[player];
			dvlRankingEnd[i]           = dvlEndFlag[player];
			dvlRankingMedal[i * 6 + 0] = dvlMedalStat[player * 6 + 0];
			dvlRankingMedal[i * 6 + 1] = dvlMedalStat[player * 6 + 1];
			dvlRankingMedal[i * 6 + 2] = dvlMedalStat[player * 6 + 2];
			dvlRankingMedal[i * 6 + 3] = dvlMedalStat[player * 6 + 3];
			dvlRankingMedal[i * 6 + 4] = dvlMedalStat[player * 6 + 4];
			dvlRankingMedal[i * 6 + 5] = dvlMedalStat[player * 6 + 5];
			
			GetDateAndTime(&timebuf);
			dvlRankingYear[i]          = timebuf[0];
			dvlRankingMonth[i]         = timebuf[1];
			dvlRankingDay[i]           = timebuf[2];
			dvlRankingHour[i]          = timebuf[4];
			dvlRankingMinute[i]        = timebuf[5];
			dvlRankingSecond[i]        = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// セクションタイムランキング更新
int dvlUpdateSectionTimeRanking(int player) {
	int i, timebuf[8], result;
	result = 0;
	
	if((playback) || (IsBig[player]) || (dvlLvUpBonus) || (dvlStartLevel)) return 0;
	
	for(i = 0; i < 10; i++) {
		if((dvlSectionTime[i + player * 10] < dvlRankingSectionTime[i]) && (dvlSectionTime[i + player * 10] != 0)) {
			result++;
			
			dvlRankingSectionTime[i] = dvlSectionTime[i + player * 10];
			dvlRankingSectionEnd[i] = dvlEndFlag[player];
			
			GetDateAndTime(&timebuf);
			dvlRankingSectionYear[i] = timebuf[0];
			dvlRankingSectionMonth[i] = timebuf[1];
			dvlRankingSectionDay[i] = timebuf[2];
			dvlRankingSectionHour[i] = timebuf[4];
			dvlRankingSectionMinute[i] = timebuf[5];
			dvlRankingSectionSecond[i] = timebuf[6];
		}
	}
	
	return result;
}

// ランキング表示
void dvlViewRanking(int player) {
	int i, cursor, move, erasemode, stmode, temp;
	cursor = 0;
	move = 0;
	erasemode = 0;
	stmode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		if(!stmode) {
			// ノーマルランキング
			printFontGrid(1, 1, "DEVIL-NORMAL MODE RANKING >>", 6);
			printFontGrid(1, 3, "RANK LEVEL TIME     DATE", 4);
			
			for(i = 0; i < 10; i++) {
				if(dvlRankingEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (dvlRankingEnd[i] - 1) * 2, 320, 2);
				
				if(i == 0) sprintf(string[0], " 1ST");
				if(i == 1) sprintf(string[0], " 2ND");
				if(i == 2) sprintf(string[0], " 3RD");
				if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
				printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
				
				sprintf(string[0], "%d", dvlRankingLevel[i]);
				printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
				
				getTime(dvlRankingTime[i]);
				printFontGrid(12, 4 + i, string[0], 7 * (cursor == i));
				
				temp = (dvlRankingYear[i] / 1000) * 1000;	// 年を下2桁だけ表示
				if(temp == 0) temp = 1;
				sprintf(string[0], "%02d/%02d/%02d", dvlRankingYear[i] % temp, dvlRankingMonth[i], dvlRankingDay[i]);
				printFontGrid(21, 4 + i, string[0], 7 * (cursor == i));
				
				sprintf(string[0], "%02d:%02d:%02d", dvlRankingHour[i], dvlRankingMinute[i], dvlRankingSecond[i]);
				printFontGrid(30, 4 + i, string[0], 7 * (cursor == i));
			}
			
			for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
			
			if(!erasemode) {
				// メダル
				for(i = 0; i < 6; i++) dvlDrawMedal(8 + i * 16, 192, i, dvlRankingMedal[cursor * 6 + i], -1);
				
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
				
				// ランキング切り替え
				if(getPushState(player, 2) || getPushState(player, 3)) {
					PlaySE(se_move);
					stmode = !stmode;
				}
			} else {
				printFontGrid(1, 24, "ERASE ALL RECORDS?", 2);
				printFontGrid(1, 26, "A:YES / B:NO", 2);
				
				// 消去
				if(getPushState(player, 4)) {
					PlayWave(se_kettei);
					dvlInitRanking();
					dvlSaveRanking(player);
					erasemode = 0;
				}
				
				// 戻る
				if(getPushState(player, 5)) {
					PlaySE(se_move);
					erasemode = 0;
				}
			}
		} else {
			// セクションタイムランキング
			printFontGrid(1, 1, "<< DEVIL-NORMAL MODE SECTION TIME", 6);
			printFontGrid(1, 3, "SECTION TIME     DATE", 4);
			printFontGrid(1, 28, "A/B:EXIT", 6);
			
			for(i = 0; i < 10; i++) {
				if(dvlRankingSectionEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (dvlRankingSectionEnd[i] - 1) * 2, 320, 2);
				
				sprintf(string[0], "%3d-%3d", i * 100, ((i + 1) * 100) - 1);
				printFontGrid(1, 4 + i, string[0], 0);
				
				getTime(dvlRankingSectionTime[i]);
				printFontGrid(9, 4 + i, string[0], 0);
				
				temp = (dvlRankingSectionYear[i] / 1000) * 1000;	// 年を下2桁だけ表示
				if(temp == 0) temp = 1;
				sprintf(string[0], "%02d/%02d/%02d", dvlRankingSectionYear[i] % temp, dvlRankingSectionMonth[i], dvlRankingSectionDay[i]);
				printFontGrid(18, 4 + i, string[0], 0);
				
				sprintf(string[0], "%02d:%02d:%02d", dvlRankingSectionHour[i], dvlRankingSectionMinute[i], dvlRankingSectionSecond[i]);
				printFontGrid(27, 4 + i, string[0], 0);
			}
			
			// 戻る
			if(getPushState(player, 4) || getPushState(player, 5)) {
				PlaySE(se_move);
				return;
			}
			
			// ランキング切り替え
			if(getPushState(player, 2) || getPushState(player, 3)) {
				PlaySE(se_move);
				stmode = !stmode;
			}
		}
	}
}
