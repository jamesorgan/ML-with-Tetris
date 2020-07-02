//BEGINNER-TAMAYA
//prefix:begt

int begtVersion;			// バージョン（過去のリプレイとの互換性用）
int begtCVersion = 2;		// 現在のバージョン（begtVersionに代入される）

// レベルアップテーブル
int begtLevelTable[21] =
{
//   *00, *10, *20, *30, *40, *50, *60, *70, *80, *90
       1,   1,   2,   3,   4,   5,   6,   8,  12,  15,  // 0**
       1,   2,   3,   6,   8,  10,  12,  15,  20,  30,  // 1**
    1200                                                // 2**
};

// BGM設定
int begtBgmNo[2] = {0,7};		// LV000～199,LV200
int begtFadeLv = 185;			// BGMをフェードアウトさせるレベル

// 裏段位の表示名
str begtStrSecretGradeName[19] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0～ 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9～17
	"GM"													// 18
};

// 変数
int begtModeNo = -1;			// モード番号

int begtLevel[2];				// レベル
int begtScore[2];				// スコア

int begtHanabiWaiting[2];		// 発生待ち花火数
int begtHanabiFrame[2];			// 発生するまでのフレーム数
int begtHanabiCombo[2];			// HANABIコンボ補正用記憶域
int begtHanabiInt[2];			// BEGINNERロール中の花火打ち上げ間隔

int begtTSpinFrame[2];			// T-SPIN表示の残り時間

int begtNaviFrame[2];			// ナビゲーションの表示時間
int begtNaviAnim[2];			// ナビゲーションブロックの明るさ

int begtIsBig = 0;				// BIGかどうか
int begtBigMove = 1;			// BIG時の横移動単位
int begtGhost = 1;				// ゴーストの設定（0=LV0-99 1=常にON 2=常にOFF）
int begtLvUpBonus = 1;			// レベルアップボーナス
int begtTSpin = 1;				// T-SPINの種類
int begtNaviEnable = 0;			// ナビゲーションの設定（0=LV0-99 1=常にON 2=常にOFF）
int begtStartLevel = 0;			// スタート時のレベル

// ランキング用変数
int begtRankingScore[10];		// スコア
int begtRankingLevel[10];		// レベル
int begtRankingTime[10];		// タイム
int begtRankingYear[10];		// ランクイン日時（年）
int begtRankingMonth[10];		// ランクイン日時（月）
int begtRankingDay[10];			// ランクイン日時（日）
int begtRankingHour[10];		// ランクイン日時（時）
int begtRankingMinute[10];		// ランクイン日時（分）
int begtRankingSecond[10];		// ランクイン日時（秒）

// イベント発生
void begtPluginEvent(int player, int event, int *param) {
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != begtModeNo)) return;
	
	if(event == 0) {
		begtModeNo = addModePlugin("BEGINNER-TAMAYA");	// モードを登録する
	} else if(event == 7) {
		begtMoveInit(player);	// ブロック出現（ブロック確定前）
	} else if(event == 8) {
		begtMoveMain(player);	// ブロック操作中
	} else if(event == 12) {
		begtCalcScore(player, param[0]);	// スコア計算
	} else if(event == 15) {
		begtViewScore(player);	// スコア表示
	} else if(event == 17) {
		begtSetting(player, param);	// 設定画面
	} else if(event == 18) {
		begtPlayerInitial(player);	// 初期化処理
	} else if(event == 19) {
		begtMoveInit2(player);	// ブロック出現（ブロック確定後）
	} else if(event == 21) {
		begtResult(player);	// 結果表示
	} else if(event == 24) {
		begtEndingStart(player);	// エンディング突入
	} else if(event == 25) {
		begtExcellent(player, param);	// エンディング終了
	} else if(event == 28) {
		begtIncrementTime(player);	// 時間を進める
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		begtSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		begtLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		begtLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		begtReplayDetail();	// リプレイ詳細
	}
}

// 初期化処理
void begtPlayerInitial(int player) {
	// バージョン設定
	if(!playback) begtVersion = begtCVersion;
	
	// 変数を初期化
	if((begtVersion >= 2) && (begtStartLevel > 0)) {
		begtLevel[player] = begtStartLevel * 100;
		backno = begtStartLevel;
	} else {
		begtLevel[player] = -1;
	}
	begtScore[player] = 0;
	begtHanabiWaiting[player] = 0;
	begtHanabiFrame[player] = 0;
	begtHanabiCombo[player] = 0;
	begtHanabiInt[player] = 0;
	begtTSpinFrame[player] = 0;
	begtNaviFrame[player] = 0;
	begtNaviAnim[player] = 0;
	
	bgmlv = begtBgmNo[0];
	framecolor[player] = 0;
	enable_combo[player] = 1;
	
	// 設定を反映させる
	IsBig[player] = begtIsBig;
	BigMove[player] = begtBigMove;
	if(begtGhost == 2) ghost[player] = 0;
	tspin_type[player] = begtTSpin;
	
	// 初期スピードを設定
	begtSpeedUp(player);
}

// スピードアップ
void begtSpeedUp(int player) {
	int index;
	
	// スピードを変える
	index = begtLevel[player] / 10;
	if(index < 0) index = 0;
	if(index > 20) index = 20;
	sp[player] = begtLevelTable[index];
	
	// BGMフェードアウト
	if((begtLevel[player] >= begtFadeLv) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// ゴーストを消す
	if((begtLevel[player] >= 100) && (begtGhost == 0)) {
		ghost[player] = 0;
	}
}

// ブロック出現（ブロック確定前）
void begtMoveInit(int player) {
	int temp;
	
	// 最初のフレームなら
	if(!statc[player * 10 + 3] && !ending[player]) {
		// レベルアップ処理
		if(begtLevel[player] % 100 != 99) {
			begtLevel[player]++;
			if(begtLevel[player] % 100 == 99) PlaySE(se_lvstop);
			begtSpeedUp(player);
		}
	}
}

// ブロック出現（ブロック確定後）
void begtMoveInit2(int player) {
	// ナビゲーション
	if( ((begtNaviEnable == 0) && (begtLevel[player] < 100)) || (begtNaviEnable == 1) ) {
		cpu_setBestSpot(player, blk[player]);
		
		begtNaviFrame[player] = 0;
		begtNaviAnim[player] = 0;
	}
}

// ブロック操作中
void begtMoveMain(int player) {
	// ナビゲーション表示
	if( ((begtNaviEnable == 0) && (begtLevel[player] < 100)) || (begtNaviEnable == 1) ) {
		if((cpu_best_x[player] != -3) && (stat[player] == 4) && (begtNaviFrame[player] < 60)) {
			drawNaviBlock(player, foffset[player] + 8 + (cpu_best_x[player] * 8), fyoffset[player] + 24 + (cpu_best_y[player] * 8),
			              blk[player], cpu_best_r[player], &current_color_m, begtNaviAnim[player] / 2);
			
			begtNaviFrame[player]++;
			begtNaviAnim[player]++;
			if(begtNaviAnim[player] >= 20) begtNaviAnim[player] = 0;
		}
	}
}

// スコア計算
void begtCalcScore(int player, int lines) {
	int temp, nextsec;
	
	if(combo[player] == 1) begtHanabiCombo[player] = 0;
	
	if((lines >= 2) || (tspin_flag[player])) {
		// T-SPINボーナス
		if(tspin_flag[player]) {
			PlaySE(se_tserase);
			begtTSpinFrame[player] = 120;
			begtHanabiCombo[player] = ((begtHanabiCombo[player] + lines) * 5) / 2;
		}
		
		// 基本点
		temp = lines + begtHanabiCombo[player] + combo2[player];
		
		// 前に打ち上げた数を覚えておく（ただしLV150以降の倍率は除く）
		begtHanabiCombo[player] = temp;
		
		if(ending[player])
			temp = temp * 2;		// ロール中は2倍
		else if(begtLevel[player] >= 150)
			temp = temp + (temp / 2);	// LV150以降は1.5倍
	} else {
		// T-SPINなしの一列消しはコンボ中でも一発
		temp = 1;
	}
	
	// 全消しで4倍
	if(isBravo(player)) {
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		temp = temp * 4;
	}
	
	// スコア加算
	begtScore[player] = begtScore[player] + temp;
	begtHanabiWaiting[player] = begtHanabiWaiting[player] + temp;
	begtHanabiFrame[player] = 0;
	
	if(!ending[player]) {
		// レベルアップ
		nextsec = begtLevel[player] / 100 * 100 + 100;
		if(!begtLvUpBonus) begtLevel[player] = begtLevel[player] + lines;
		else begtLevel[player] = begtLevel[player] + lines + ((lines >= 3) * (lines - 2));
		
		if(begtLevel[player] >= 200) {
			// エンディング
			begtLevel[player] = 200;
			ending[player] = 1;
			timeOn[player] = 0;
		} else {
			// レベルストップ音
			if(begtLevel[player] % 100 == 99) PlaySE(se_lvstop);
		}
		
		if(begtLevel[player] >= nextsec) {
			// レベルアップ音
			PlaySE(se_levelup);
			
			// 背景切り替え
			bgfadesw = 1;
			bgfadebg = nextsec / 100;
		}
		
		// スピードアップ
		begtSpeedUp(player);
	}
}

// 時間を進める
void begtIncrementTime(int player) {
	int i;
	
	// ロール中の花火
	if(ending[player] == 2) {
		if(edrec[player] % begtHanabiInt[player] == 0) {
			begtScore[player]++;
			begtHanabiWaiting[player]++;
		}
	}
	
	// 花火発生
	if((begtHanabiWaiting[player] > 0) && (onRecord[player])) {
		begtHanabiFrame[player] = begtHanabiFrame[player] + 1 + (begtHanabiWaiting[player] > 60);
		
		if(begtHanabiFrame[player] >= 10) {
			begtHanabiWaiting[player]--;
			objectCreate(player, 3, -40 + Rand(80) + foffset[player],
			             16 + Rand(20) + 116 * ((checkFieldTop(player) < 12) && (by[player] < 12)), 0, 0, Rand(7), 0);
			begtHanabiFrame[player] = 0;
		}
	}
	
	if(begtHanabiWaiting[player] == 0) begtHanabiFrame[player] = 10;
	
	if(begtTSpinFrame[player] > 0) begtTSpinFrame[player]--;
	
	// ロール終了
	if((ending[player] == 2) && (edrec[player] >= 60 * 60)) {
		ending[player] = 3;
		stat[player] = 10;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		onRecord[player] = 0;
		
		// +30発ボーナス
		if(begtVersion >= 1) begtScore[player] = begtScore[player] + 30;
	}
}

// BGM読み込み
void begtLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 2; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/2)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(begtBgmNo[i]);
		}
	}
}

// スコア表示
void begtViewScore(int player) {
	int color;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// スコア
	printTinyFont(foffset[player] + 96, fyoffset[player] + 135, "SCORE");
	sprintf(string[0], "%d", begtScore[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 143, string[0], color);
	
	// レベル（分子）
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(begtLevel[player] == -1) sprintf(string[0], "%4d", 0);	// -1なら0と表示する(内部的には最初は-1になっている)
	else sprintf(string[0], "%4d", begtLevel[player]);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// レベル（横線）
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	if(sp[player] <= 600) {
		ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22 - ((sp[player] * 24) / 660), 143, 22, 1);
	} else {
		ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 0, 143, 22, 1);
	}
	
	// レベル（分母）
	if(ending[player]) sprintf(string[0], "%4d", begtLevel[player]);
	else sprintf(string[0], "%4d", begtLevel[player] / 100 * 100 + 100);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, string[0], color);
	
	// タイム
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
	
	// T-SPIN表示
	if(begtTSpinFrame[player] > 0) printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "T-SPIN");
}

// エンディング突入
void begtEndingStart(int player) {
	int i;
	
	for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	
	ending[player] = 2;
	stat[player] = 4;
	ending_timeOn[player] = 1;
	
	// ロール中の花火間隔を決定
	if(begtScore[player] >= 400) {
		begtHanabiInt[player] = 12;	// 400発以上で秒間5発
	} else if(begtScore[player] >= 200) {
		begtHanabiInt[player] = 15;	// 200～399発で秒間4発
	} else {
		begtHanabiInt[player] = 20;	// 199以下で秒間3発
	}
	
	bgmlv = begtBgmNo[1];
	PlayBGM();
}

// エンディング終了
void begtExcellent(int player, int *param) {
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
void begtResult(int player) {
	if(statc[player * 10] == 0) {
		// ランキング登録
		statc[player * 10 + 1] = begtRegistRanking(player);
		if(statc[player * 10 + 1] != -1) begtSaveRanking(player);
		
		// 裏段位判定
		statc[player * 10 + 2] = checkSecretGrade(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "SCORE");
	sprintf(string[0], "%13d", begtScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", begtLevel[player]);
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
		sprintf(string[0], "%13s", begtStrSecretGradeName[statc[player * 10 + 2]]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
	}
}

// 設定画面
void begtSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(begtLoadConfig() == 0) begtSaveConfig();
	
	// ランキングを読み込み
	if(begtLoadRanking(player) == 0) begtInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "BEGINNER-TAMAYA OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",            7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",       7 * (cursor == 1));
		printFontGrid(2, 5, "GHOST BLOCK",    7 * (cursor == 2));
		printFontGrid(2, 6, "LEVEL UP BONUS", 7 * (cursor == 3));
		printFontGrid(2, 7, "T-SPIN",         7 * (cursor == 4));
		printFontGrid(2, 8, "NAVIGATION",     7 * (cursor == 5));
		printFontGrid(2, 9, "START LEVEL",    7 * (cursor == 6));
		
		// 設定値表示
		if(!begtIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!begtBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(begtGhost == 0) sprintf(string[0], "LV100");
		else if(begtGhost == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(!begtLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(begtTSpin == 0) sprintf(string[0], "OFF");
		else if(begtTSpin == 1) sprintf(string[0], "LINE CLEAR");
		else if(begtTSpin == 2) sprintf(string[0], "IMMOBILE");
		else if(begtTSpin == 3) sprintf(string[0], "3-CORNER");
		else sprintf(string[0], "3-CORNER NO KICK");
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		if(begtNaviEnable == 0) sprintf(string[0], "LV100");
		else if(begtNaviEnable == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		sprintf(string[0], "%d", begtStartLevel * 100);
		printFontGrid(22, 9, string[0], 7 * (cursor == 6));
		
		// カーソル移動
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 6;
			if(cursor > 6) cursor = 0;
		}
		
		// 値を変更
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) begtIsBig = !begtIsBig;
			if(cursor == 1) begtBigMove = !begtBigMove;
			if(cursor == 2) {
				begtGhost = begtGhost + move;
				if(begtGhost < 0) begtGhost = 2;
				if(begtGhost > 2) begtGhost = 0;
			}
			if(cursor == 3) begtLvUpBonus = !begtLvUpBonus;
			if(cursor == 4) {
				begtTSpin = begtTSpin + move;
				if(begtTSpin < 0) begtTSpin = 4;
				if(begtTSpin > 4) begtTSpin = 0;
			}
			if(cursor == 5) {
				begtNaviEnable = begtNaviEnable + move;
				if(begtNaviEnable < 0) begtNaviEnable = 2;
				if(begtNaviEnable > 2) begtNaviEnable = 0;
			}
			if(cursor == 6) {
				begtStartLevel = begtStartLevel + move;
				if(begtStartLevel < 0) begtStartLevel = 1;
				if(begtStartLevel > 1) begtStartLevel = 0;
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
			begtSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			begtViewRanking(player);
		}
	}
}

// 設定を保存
void begtSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x49474542;
	saveBuf[1] = 0x52454E4E;
	saveBuf[2] = 0x414D4154;
	saveBuf[3] = 0x31764159;
	
	// 設定内容
	saveBuf[4] = begtIsBig;
	saveBuf[5] = begtBigMove;
	saveBuf[6] = begtGhost;
	saveBuf[7] = begtLvUpBonus;
	saveBuf[8] = begtTSpin;
	saveBuf[9] = begtNaviEnable;
	saveBuf[10] = begtStartLevel;
	
	SaveFile("config/BEGINNER_TAMAYA_CONFIG.SAV", &saveBuf, 100 * 4);
}

// 設定を読み込み
int begtLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/BEGINNER_TAMAYA_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x49474542) return 0;
	if(saveBuf[1] != 0x52454E4E) return 0;
	if(saveBuf[2] != 0x414D4154) return 0;
	if(saveBuf[3] != 0x31764159) return 0;
	
	// 設定内容
	begtIsBig = saveBuf[4];
	begtBigMove = saveBuf[5];
	begtGhost = saveBuf[6];
	begtLvUpBonus = saveBuf[7];
	begtTSpin = saveBuf[8];
	begtNaviEnable = saveBuf[9];
	begtStartLevel = saveBuf[10];
	
	return 1;
}

// リプレイ保存
void begtSaveReplay(int player) {
	saveBuf[900] = begtIsBig;
	saveBuf[901] = begtBigMove;
	saveBuf[902] = begtGhost;
	saveBuf[903] = begtLvUpBonus;
	saveBuf[904] = begtTSpin;
	saveBuf[905] = begtLevel[player];
	saveBuf[906] = begtScore[player];
	saveBuf[907] = begtVersion;
	saveBuf[908] = begtStartLevel;
}

// リプレイ読み込み
void begtLoadReplay(int player) {
	begtIsBig = saveBuf[900];
	begtBigMove = saveBuf[901];
	begtGhost = saveBuf[902];
	begtLvUpBonus = saveBuf[903];
	begtTSpin = saveBuf[904];
	begtVersion = saveBuf[907];
	begtStartLevel = saveBuf[908];
	
	begtPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void begtReplayDetail() {
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
	
	printFontGrid(1, 12, "T-SPIN", 0);
	if(saveBuf[904] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[904] == 1) sprintf(string[0], "LINE CLEAR");
	else if(saveBuf[904] == 2) sprintf(string[0], "IMMOBILE");
	else if(saveBuf[904] == 3) sprintf(string[0], "3-CORNER");
	else sprintf(string[0], "3-CORNER NO KICK");
	printFontGrid(22, 12, string[0], 0);
	
	printFontGrid(1, 13, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[908] * 100);
	printFontGrid(22, 13, string[0], 0);
	
	printFontGrid(1, 14, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[907]);
	printFontGrid(22, 14, string[0], 0);
}

// ランキング保存
void begtSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 10) + 0] = begtRankingScore[i];
		saveBuf[1 + (i * 10) + 1] = begtRankingLevel[i];
		saveBuf[1 + (i * 10) + 2] = begtRankingTime[i];
		saveBuf[1 + (i * 10) + 3] = begtRankingYear[i];
		saveBuf[1 + (i * 10) + 4] = begtRankingMonth[i];
		saveBuf[1 + (i * 10) + 5] = begtRankingDay[i];
		saveBuf[1 + (i * 10) + 6] = begtRankingHour[i];
		saveBuf[1 + (i * 10) + 7] = begtRankingMinute[i];
		saveBuf[1 + (i * 10) + 8] = begtRankingSecond[i];
	}
	
	sprintf(string[0], "config/BEGINNER_TAMAYA_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 111 * 4);
}

// ランキング読み込み
int begtLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/BEGINNER_TAMAYA_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 111 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	for(i = 0; i < 10; i++) {
		begtRankingScore[i]  = saveBuf[1 + (i * 10) + 0];
		begtRankingLevel[i]  = saveBuf[1 + (i * 10) + 1];
		begtRankingTime[i]   = saveBuf[1 + (i * 10) + 2];
		begtRankingYear[i]   = saveBuf[1 + (i * 10) + 3];
		begtRankingMonth[i]  = saveBuf[1 + (i * 10) + 4];
		begtRankingDay[i]    = saveBuf[1 + (i * 10) + 5];
		begtRankingHour[i]   = saveBuf[1 + (i * 10) + 6];
		begtRankingMinute[i] = saveBuf[1 + (i * 10) + 7];
		begtRankingSecond[i] = saveBuf[1 + (i * 10) + 8];
	}
	
	return 1;
}

// ランキング初期化
void begtInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		begtRankingScore[i]  = 0;
		begtRankingLevel[i]  = 0;
		begtRankingTime[i]   = 0;
		begtRankingYear[i]   = 0;
		begtRankingMonth[i]  = 0;
		begtRankingDay[i]    = 0;
		begtRankingHour[i]   = 0;
		begtRankingMinute[i] = 0;
		begtRankingSecond[i] = 0;
	}
}

// ランキング登録
int begtRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (begtIsBig) || (!begtLvUpBonus) || (begtStartLevel)) return -1;
	
	for(i = 0; i < 10; i++) {
		// ランクイン
		if( (begtScore[player] > begtRankingScore[i]) || 
		    ((begtScore[player] == begtRankingScore[i]) && (begtLevel[player] > begtRankingLevel[i])) || 
		    ((begtScore[player] == begtRankingScore[i]) && (begtLevel[player] == begtRankingLevel[i]) && (gameTimer[player] < begtRankingTime[i])) )
		{
			// ランキングをずらす
			for(j = 9; j > i; j--) {
				begtRankingScore[j]  = begtRankingScore[j - 1];
				begtRankingLevel[j]  = begtRankingLevel[j - 1];
				begtRankingTime[j]   = begtRankingTime[j - 1];
				begtRankingYear[j]   = begtRankingYear[j - 1];
				begtRankingMonth[j]  = begtRankingMonth[j - 1];
				begtRankingDay[j]    = begtRankingDay[j - 1];
				begtRankingHour[j]   = begtRankingHour[j - 1];
				begtRankingMinute[j] = begtRankingMinute[j - 1];
				begtRankingSecond[j] = begtRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			begtRankingScore[i]  = begtScore[player];
			begtRankingLevel[i]  = begtLevel[player];
			begtRankingTime[i]   = gameTimer[player];
			
			GetDateAndTime(&timebuf);
			begtRankingYear[i]   = timebuf[0];
			begtRankingMonth[i]  = timebuf[1];
			begtRankingDay[i]    = timebuf[2];
			begtRankingHour[i]   = timebuf[4];
			begtRankingMinute[i] = timebuf[5];
			begtRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void begtViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "BEGINNER-TAMAYA MODE RANKING", 6);
		printFontGrid(1, 3, "RANK SCORE              LEVEL TIME", 4);
		
		for(i = 0; i < 10; i++) {
			if(begtRankingLevel[i] >= 200) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, 0, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", begtRankingScore[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", begtRankingLevel[i]);
			printFontGrid(25, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(begtRankingTime[i]);
			printFontGrid(31, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// 日付と時刻
			sprintf(string[0],
			        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
			        begtRankingYear[cursor], begtRankingMonth[cursor], begtRankingDay[cursor],
			        begtRankingHour[cursor], begtRankingMinute[cursor], begtRankingSecond[cursor]);
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
				begtInitRanking();
				begtSaveRanking(player);
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
