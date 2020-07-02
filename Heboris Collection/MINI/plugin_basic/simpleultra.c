//SIMPLE-ULTRA
//prefix:simpu

// 変数
int simpuVersion;			// バージョン番号
int simpuCVersion = 2;		// 現在のバージョン

int simpuModeNo = -1;		// モード番号
int simpuScore[2];			// スコア
int simpuLines[2];			// ライン
int simpuLimitTime[2];		// 残り時間

int simpuTSpinFrame[2];		// T-SPIN表示／ヘボリス表示の残り時間
int simpuTSpinLine[2];		// 最後のT-SPINライン消し／ヘボリス消しの種類
int simpuComboFrame[2];		// コンボ数表示の残り時間
int simpuB2BFrame[2];		// Back To Back表示の残り時間
int simpuTSpinWall[2];		// 壁蹴りありのT-SPINだったら1になる
int simpuScoreGet[2];		// 今入ったスコア表示の点数
int simpuScoreFrame[2];		// 今入ったスコア表示の残り時間

int simpuSpeed = 1;			// 落下速度
int simpuSpType = 0;		// スピードタイプ
int simpuWait1 = 25;		// ARE
int simpuWait2 = 25;		// ライン消去待ち時間
int simpuWait3 = 30;		// ブロックが固定されるまでの猶予時間
int simpuWaitt = 16;		// DAS
int simpuIsBig = 0;			// BIGかどうか
int simpuBigMove = 1;		// BIG時の横移動単位
int simpuBgm = 0;			// 使用するBGM
int simpuGhost = 1;			// ゴーストの設定
int simpuTSpin = 3;			// T-SPINの種類
int simpuEnableCombo = 1;	// コンボボーナスの有無
int simpuEnableB2B = 1;		// Back To Backの有無（0=なし 1=通常 2=ヘボリスのみ 3=T-SPINのみ）
int simpuGameType = 0;		// 0=2分間ラインアタック 1=3分間スコアアタック
int simpuWait4 = -1;		// ブロックが固定されるまでの猶予時間（段差から落下後）
int simpuWait5 = -1;		// ライン消去後のARE

int simpuPreset[20 * 10];	// プリセット
int simpuLastPresetNo = 0;	// 最後に選択したプリセット番号

// ランキング用変数
int simpuRankingScore[5*2];		// スコア
int simpuRankingLine[5*2];		// ライン
int simpuRankingSpeed[5*2];		// 落下速度
int simpuRankingSpType[5*2];	// スピードタイプ
int simpuRankingWait1[5*2];		// ARE
int simpuRankingWait2[5*2];		// ライン消去待ち時間
int simpuRankingWait3[5*2];		// ブロックが固定されるまでの猶予時間
int simpuRankingWaitt[5*2];		// DAS
int simpuRankingYear[5*2];		// ランクイン日時（年）
int simpuRankingMonth[5*2];		// ランクイン日時（月）
int simpuRankingDay[5*2];		// ランクイン日時（日）
int simpuRankingHour[5*2];		// ランクイン日時（時）
int simpuRankingMinute[5*2];	// ランクイン日時（分）
int simpuRankingSecond[5*2];	// ランクイン日時（秒）
int simpuRankingWait4[5*2];		// ブロックが固定されるまでの猶予時間（段差から落下後）
int simpuRankingWait5[5*2];		// ライン消去後のARE

// イベント発生
void simpuPluginEvent(int player, int event, int *param) {
	int i;
	
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != simpuModeNo)) return;
	
	if(event == 0) {
		simpuModeNo = addModePlugin("SIMPLE-ULTRA");	// モードを登録する
	} else if(event == 8) {
		simpuSoftDropScore(player);	// ソフトドロップで入った点数を加算
	} else if(event == 12) {
		simpuCalcScore(player, param[0]);	// スコア計算
	} else if(event == 15) {
		simpuViewScore(player);	// スコア表示
	} else if(event == 17) {
		simpuSetting(player, param);	// 設定画面
	} else if(event == 18) {
		simpuPlayerInitial(player);	// 初期化
	} else if(event == 21) {
		simpuResult(player);	// 結果表示
	} else if(event == 24) {
		ending[player] = 3;	// エンディング突入
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		param[0] = 5;	// EXCELLENT画面を省略
	} else if(event == 28) {
		simpuIncrementTime(player);	// 時間を進める
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 41) {
		simpuLoadBGM();	// BGM読み込み
	} else if(event == 39) {
		simpuSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		simpuLoadReplay(player);	// リプレイ読み込み
	} else if(event == 48) {
		simpuSoftDropOld(player);	// ソフトドロップ（旧）
	} else if(event == 49) {
		simpuHardDrop(player, param[1]);	// ハードドロップ
	} else if(event == 55) {
		simpuReplayDetail();	// リプレイ詳細
	} else if(event == 59) {
		simpuTSpinZero(player);	// ライン消しなしのT-SPIN
	}
}

// 初期化
void simpuPlayerInitial(int player) {
	// バージョン
	if(!playback) simpuVersion = simpuCVersion;
	
	// 変数を初期化
	simpuScore[player] = 0;
	simpuLines[player] = 0;
	simpuLimitTime[player] = 7200 + (simpuGameType * 3600);
	
	simpuTSpinFrame[player] = 0;
	simpuTSpinLine[player] = 0;
	simpuComboFrame[player] = 0;
	simpuB2BFrame[player] = 0;
	simpuTSpinWall[player] = 0;
	simpuScoreGet[player] = 0;
	simpuScoreFrame[player] = 0;
	
	// 枠の色を変える
	framecolor[player] = 3;
	
	// 初期速度
	sp[player] = simpuSpeed;
	speedtype[player] = simpuSpType;
	wait1[player] = simpuWait1;
	wait2[player] = simpuWait2;
	wait3[player] = simpuWait3;
	waitt[player] = simpuWaitt;
	
	if(simpuVersion >= 1) wait4[player] = simpuWait4;
	else wait4[player] = -1;
	
	if(simpuVersion >= 2) wait5[player] = simpuWait5;
	else wait5[player] = -1;
	
	// 設定を反映させる
	IsBig[player] = simpuIsBig;
	BigMove[player] = simpuBigMove;
	bgmlv = simpuBgm;
	if(simpuGhost == 0) ghost[player] = 0;
	tspin_type[player] = simpuTSpin;
	enable_combo[player] = simpuEnableCombo;
	b_to_b_type[player] = simpuEnableB2B;
}

// スコア計算
void simpuCalcScore(int player, int lines) {
	int bo, b2b, combopts, combogoal, points;
	
	// T-SPIN時
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		simpuTSpinFrame[player] = 60;
		simpuTSpinLine[player] = lines;
		simpuTSpinWall[player] = (last_command[player] == 4);
		
		if((lines == 1) && (simpuTSpinWall[player])) bo = 2;	// 壁蹴りありT-SPIN Single
		if((lines == 1) && (!simpuTSpinWall[player])) bo = 8;	// 壁蹴りなしT-SPIN Single
		if(lines == 2) bo = 12;	// T-SPIN Double
		if(lines == 3) bo = 16;	// T-SPIN Triple
	}
	// 普通のライン消し
	else {
		if(lines == 1) bo = 1;
		if(lines == 2) bo = 3;
		if(lines == 3) bo = 5;
		if(lines == 4) {
			simpuTSpinFrame[player] = 60;
			simpuTSpinLine[player] = lines;
			bo = 8;
		}
	}
	
	// B2Bボーナス（x 1.5）
	if((simpuEnableB2B != 0) && (b_to_b_count[player] >= 2)) {
		b2b = 1;
		simpuB2BFrame[player] = 60;
	} else {
		b2b = 0;
		simpuB2BFrame[player] = 0;
	}
	
	// コンボボーナス
	if((simpuEnableCombo != 0) && (combo[player] >= 2)) {
		combopts = (combo[player] - 1) * 50;
		
		if(combo[player] >= 12) combogoal = 5;
		else if(combo[player] >= 9) combogoal = 4;
		else if(combo[player] >= 7) combogoal = 3;
		else if(combo[player] >= 5) combogoal = 2;
		else if(combo[player] >= 3) combogoal = 1;
		else combogoal = 0;
		
		simpuComboFrame[player] = 60;
	} else {
		combopts = 0;
		combogoal = 0;
	}
	
	// 全消しボーナス
	if(isBravo(player)) {
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		simpuScore[player] = simpuScore[player] + 5000;
	}
	
	// スコア加算
	points = bo * 100;
	simpuScore[player] = simpuScore[player] + points;
	if(b2b) simpuScore[player] = simpuScore[player] + (points / 2);
	simpuScore[player] = simpuScore[player] + combopts;
	
	simpuScoreGet[player] = points + ((points / 2) * (b2b)) + combopts;
	simpuScoreFrame[player] = 120;
	
	// ライン加算
	simpuLines[player] = simpuLines[player] + lines;
}

// ライン消しなしのT-SPIN
void simpuTSpinZero(int player) {
	PlaySE(se_tspin);
	simpuTSpinFrame[player] = 60;
	simpuTSpinLine[player] = 0;
	
	// 壁蹴りあり
	if(last_command[player] == 4) {
		simpuScore[player] = simpuScore[player] + 100;
		simpuTSpinWall[player] = 1;
		
		simpuScoreGet[player] = 100;
		simpuScoreFrame[player] = 120;
	}
	// 壁蹴りなし
	else {
		simpuScore[player] = simpuScore[player] + 400;
		simpuTSpinWall[player] = 0;
		
		simpuScoreGet[player] = 400;
		simpuScoreFrame[player] = 120;
	}
}

// ソフトドロップ（旧）
void simpuSoftDropOld(int player) {
	if((!down_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) && (engineVer <= 12)) {
		if((speedtype[player] == 1) || (sp[player] < (softspeed[player] + 1) * 30)) {
			simpuScore[player]++;
		}
	}
}

// ハードドロップ
void simpuHardDrop(int player, int bottom) {
	if((!up_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0)) {
		simpuScore[player] = simpuScore[player] + (bottom - by[player]) * 2;
	}
}

// ソフトドロップで入った点数を加算
void simpuSoftDropScore(int player) {
	if(softd_score[player] > 0) {
		simpuScore[player] = simpuScore[player] + softd_score[player];
	}
}

// 時間を進める
void simpuIncrementTime(int player) {
	int i;
	
	if(timeOn[player]) {
		// 制限時間減少
		simpuLimitTime[player]--;
		
		// 時間切れ
		if(simpuLimitTime[player] <= 0) {
			simpuLimitTime[player] = 0;
			timeOn[player] = 0;
			onRecord[player] = 0;
			
			ending[player] = 1;
			stat[player] = 10;
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		}
		// 残り10秒
		else if(simpuLimitTime[player] == 10 * 60) {
			PlaySE(se_hurryup);
		}
	}
}

// スコア表示
void simpuViewScore(int player) {
	int color, color2, temp;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	if(simpuGameType) {
		// スコア
		printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "SCORE");
		sprintf(string[0], "%d", simpuScore[player]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
		
		// 今入った得点
		if(simpuScoreFrame[player] > 0) {
			simpuScoreFrame[player]--;
			sprintf(string[0], "%d", simpuScoreGet[player]);
			printSMALLFont(foffset[player] + 96, fyoffset[player] + 58, string[0], (count % 4 / 2) * (1 + (b_to_b_count[player] != 0)));
		}
	} else {
		// ライン
		printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "LINES");
		sprintf(string[0], "%d", simpuLines[player]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	}
	
	// ベストレコード
	if(!playback) {
		if(!simpuGameType) {
			printTinyFont(foffset[player] + 96, fyoffset[player] + 68, "BEST LINES");
			sprintf(string[0], "%d", simpuRankingLine[simpuGameType * 5]);
		} else {
			printTinyFont(foffset[player] + 96, fyoffset[player] + 68, "BEST SCORE");
			sprintf(string[0], "%d", simpuRankingScore[simpuGameType * 5]);
		}
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 76, string[0], color);
	}
	
	// スピード
	printTinyFont(foffset[player] + 96, fyoffset[player] + 153, "SPEED");
	sprintf(string[0], "%d", simpuSpeed);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 161, string[0], color);
	
	sprintf(string[0], "TYPE %d", simpuSpType + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 171, string[0], color);
	
	// wait値
	ExBltRect(sg_smallfont, foffset[player] + 96, fyoffset[player] + 181, 68, 14, 24, 7);	// WAITS
	sprintf(string[0], "%2d %2d\n%2d %2d", simpuWait1, simpuWait2, simpuWait3, simpuWaitt);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 189, string[0], color);
	
	if(wait4[player] != -1) {
		sprintf(string[0], "%d", simpuWait4);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 207, string[0], color);
	}
	
	if(wait5[player] != -1) {
		sprintf(string[0], "%2d", simpuWait5);
		printSMALLFont(foffset[player] + 114, fyoffset[player] + 207, string[0], color);
	}
	
	// 残りタイム
	if((simpuLimitTime[player] <= 10 * 60) && (timeOn[player])) color2 = (count % 4 / 2) * 2;
	else color2 = color;
	getTime(simpuLimitTime[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
	
	// BLOCK/SEC
	printTinyFont(foffset[player] + 96, fyoffset[player] + 86, "BLOCK/SEC");
	if(gameTimer[player] > 0) {
		temp = (bdowncnt[player] * 10000 * 60) / gameTimer[player];
	} else {
		temp = 0;
	}
	sprintf(string[0], "%d.%04d", temp / 10000, temp % 10000);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 94, string[0], color);
	
	// LINES/MIN
	printTinyFont(foffset[player] + 96, fyoffset[player] + 104, "LINES/MIN");
	if(gameTimer[player] > 0) {
		temp = (simpuLines[player] * 100 * 3600) / gameTimer[player];
	} else {
		temp = 0;
	}
	sprintf(string[0], "%d.%02d", temp / 100, temp % 100);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 112, string[0], color);
	
	// SCORE/LINE
	if(simpuGameType) {
		printTinyFont(foffset[player] + 96, fyoffset[player] + 122, "SCORE/LINE");
		if(simpuLines[player] > 0) {
			sprintf(string[0], "%d.%02d", simpuScore[player] / simpuLines[player], simpuScore[player] % simpuLines[player]);
		} else {
			sprintf(string[0], "0.0");
		}
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 130, string[0], color);
	}
	
	if(simpuGameType) {
		// T-SPIN
		if(simpuTSpinFrame[player] > 0) {
			simpuTSpinFrame[player]--;
			
			if((simpuTSpinLine[player] == 0) && (simpuTSpinWall[player]))
				printTinyFont(foffset[player] + 25, fyoffset[player] + 208, "EZ T-SPIN");
			else if((simpuTSpinLine[player] == 0) && (!simpuTSpinWall[player]))
				printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "T-SPIN");
			else if((simpuTSpinLine[player] == 1) && (simpuTSpinWall[player]))
				printTinyFont(foffset[player] + 20, fyoffset[player] + 208, "T-SPIN MINI");
			else if((simpuTSpinLine[player] == 1) && (!simpuTSpinWall[player]))
				printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN SINGLE");
			else if(simpuTSpinLine[player] == 2)
				printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN DOUBLE");
			else if(simpuTSpinLine[player] == 3)
				printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN TRIPLE");
			else if(simpuTSpinLine[player] == 4)
				printTinyFont(foffset[player] + 30, fyoffset[player] + 208, "HEBORIS");
		}
		
		// BACK TO BACK
		if(simpuB2BFrame[player] > 0) {
			simpuB2BFrame[player]--;
			printTinyFont(foffset[player] + 18, fyoffset[player] + 200, "BACK TO BACK");
		}
		// COMBO
		else if((simpuComboFrame[player] > 0) && (combo[player] >= 2)) {
			simpuComboFrame[player]--;
			sprintf(string[0], "COMBO %d", combo[player] - 1);
			printTinyFont(foffset[player] + 30, fyoffset[player] + 200, string[0]);
		}
	}
}

// 結果表示
void simpuResult(int player) {
	// ランキング登録
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = simpuRegistRanking(player);
		if(statc[player * 10 + 1] != -1) simpuSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "SCORE");
	sprintf(string[0], "%13d", simpuScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LINES");
	sprintf(string[0], "%13d", simpuLines[player]);
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
}

// BGM読み込み
void simpuLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(simpuBgm);
	}
}

// 設定画面
void simpuSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(simpuLoadConfig() == 0) simpuMakeDefaultPreset();
	
	// ランキングを読み込み
	if(simpuLoadRanking(player) == 0) simpuInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "SIMPLE-ULTRA OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2,  3, "SPEED",         7 * (cursor ==  0));
		printFontGrid(2,  4, "SPEED TYPE",    7 * (cursor ==  1));
		if(!english) {
			printFontGrid(2,  5, "SYUTUGEN",  7 * (cursor ==  2));
			printFontGrid(2,  6, "SYOUKYO",   7 * (cursor ==  3));
			printFontGrid(2,  7, "SETTYAKU",  7 * (cursor ==  4));
			printFontGrid(2,  8, "YOKOTAME",  7 * (cursor ==  5));
			printFontGrid(2,  9, "SETTYAKU2", 7 * (cursor ==  6));
			printFontGrid(2, 10, "SYUTUGEN2", 7 * (cursor ==  7));
		} else {
			printFontGrid(2,  5, "ARE",         7 * (cursor ==  2));
			printFontGrid(2,  6, "LINE DELAY",  7 * (cursor ==  3));
			printFontGrid(2,  7, "LOCK DELAY",  7 * (cursor ==  4));
			printFontGrid(2,  8, "DAS",         7 * (cursor ==  5));
			printFontGrid(2,  9, "LOCK DELAY2", 7 * (cursor ==  6));
			printFontGrid(2, 10, "ARE2",        7 * (cursor ==  7));
		}
		printFontGrid(2, 11, "BIG",           7 * (cursor ==  8));
		printFontGrid(2, 12, "BIG MOVE",      7 * (cursor ==  9));
		printFontGrid(2, 13, "BGM",           7 * (cursor == 10));
		printFontGrid(2, 14, "GHOST BLOCK",   7 * (cursor == 11));
		printFontGrid(2, 15, "T-SPIN",        7 * (cursor == 12));
		printFontGrid(2, 16, "COMBO",         7 * (cursor == 13));
		printFontGrid(2, 17, "BACK TO BACK",  7 * (cursor == 14));
		printFontGrid(2, 18, "GAME TYPE",     7 * (cursor == 15));
		printFontGrid(2, 19, "[SAVE PRESET]", 7 * (cursor == 16));
		printFontGrid(2, 20, "[LOAD PRESET]", 7 * (cursor == 17));
		
		// 設定値表示
		sprintf(string[0], "%d", simpuSpeed);
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(simpuSpType == 0) sprintf(string[0], "1/60");
		else if(simpuSpType == 1) sprintf(string[0], "FRAMES PER ROW");
		else sprintf(string[0], "1/256");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "%d", simpuWait1);
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "%d", simpuWait2);
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		sprintf(string[0], "%d", simpuWait3);
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		sprintf(string[0], "%d", simpuWaitt);
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		if(simpuWait4 == -1) {
			if(!english) sprintf(string[0], "USE SETTYAKU");
			else sprintf(string[0], "USE LOCK DELAY");
		} else {
			sprintf(string[0], "%d", simpuWait4);
		}
		printFontGrid(22, 9, string[0], 7 * (cursor == 6));
		
		if(simpuWait5 == -1) {
			if(!english) sprintf(string[0], "USE SYUTUGEN");
			else sprintf(string[0], "USE ARE");
		} else {
			sprintf(string[0], "%d", simpuWait5);
		}
		printFontGrid(22, 10, string[0], 7 * (cursor == 7));
		
		if(!simpuIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 11, string[0], 7 * (cursor == 8));
		
		if(!simpuBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 12, string[0], 7 * (cursor == 9));
		
		sprintf(string[0], "%d", simpuBgm);
		printFontGrid(22, 13, string[0], 7 * (cursor == 10));
		
		if(!simpuGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 14, string[0], 7 * (cursor == 11));
		
		if(simpuTSpin == 0) sprintf(string[0], "OFF");
		else if(simpuTSpin == 1) sprintf(string[0], "LINE CLEAR");
		else if(simpuTSpin == 2) sprintf(string[0], "IMMOBILE");
		else if(simpuTSpin == 3) sprintf(string[0], "3-CORNER");
		else sprintf(string[0], "3-CORNER NO KICK");
		printFontGrid(22, 15, string[0], 7 * (cursor == 12));
		
		if(!simpuEnableCombo) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 16, string[0], 7 * (cursor == 13));
		
		if(simpuEnableB2B == 0) sprintf(string[0], "OFF");
		else if(simpuEnableB2B == 1) sprintf(string[0], "ON");
		else if(simpuEnableB2B == 2) sprintf(string[0], "HEBORIS ONLY");
		else sprintf(string[0], "T-SPIN ONLY");
		printFontGrid(22, 17, string[0], 7 * (cursor == 14));
		
		if(!simpuGameType) sprintf(string[0], "2MIN LINE ATTACK");
		else sprintf(string[0], "3MIN SCORE ATTACK");
		printFontGrid(22, 18, string[0], 7 * (cursor == 15));
		
		sprintf(string[0], "PRESET NO.%d", simpuLastPresetNo + 1);
		printFontGrid(22, 19, string[0], 7 * (cursor >= 16));
		
		// カーソル移動
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 17;
			if(cursor > 17) cursor = 0;
		}
		
		// 値を変更
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) {
				simpuSpeed = simpuSpeed + move;
				if(simpuSpeed < 0) simpuSpeed = 5120;
				if(simpuSpeed > 5120) simpuSpeed = 0;
			}
			if(cursor == 1) {
				simpuSpType = simpuSpType + move;
				if(simpuSpType < 0) simpuSpType = 2;
				if(simpuSpType > 2) simpuSpType = 0;
			}
			if(cursor == 2) {
				simpuWait1 = simpuWait1 + move;
				if(simpuWait1 < 0) simpuWait1 = 99;
				if(simpuWait1 > 99) simpuWait1 = 0;
			}
			if(cursor == 3) {
				simpuWait2 = simpuWait2 + move;
				if(simpuWait2 < 0) simpuWait2 = 99;
				if(simpuWait2 > 99) simpuWait2 = 0;
			}
			if(cursor == 4) {
				simpuWait3 = simpuWait3 + move;
				if(simpuWait3 < 0) simpuWait3 = 99;
				if(simpuWait3 > 99) simpuWait3 = 0;
			}
			if(cursor == 5) {
				simpuWaitt = simpuWaitt + move;
				if(simpuWaitt < 0) simpuWaitt = 99;
				if(simpuWaitt > 99) simpuWaitt = 0;
			}
			if(cursor == 6) {
				simpuWait4 = simpuWait4 + move;
				if(simpuWait4 < -1) simpuWait4 = 99;
				if(simpuWait4 > 99) simpuWait4 = -1;
			}
			if(cursor == 7) {
				simpuWait5 = simpuWait5 + move;
				if(simpuWait5 < -1) simpuWait5 = 99;
				if(simpuWait5 > 99) simpuWait5 = -1;
			}
			if(cursor == 8) simpuIsBig = !simpuIsBig;
			if(cursor == 9) simpuBigMove = !simpuBigMove;
			if(cursor == 10) {
				simpuBgm = simpuBgm + move;
				if(simpuBgm < 0) simpuBgm = 29;
				if(simpuBgm > 29) simpuBgm = 0;
			}
			if(cursor == 11) simpuGhost = !simpuGhost;
			if(cursor == 12) {
				simpuTSpin = simpuTSpin + move;
				if(simpuTSpin < 0) simpuTSpin = 4;
				if(simpuTSpin > 4) simpuTSpin = 0;
			}
			if(cursor == 13) simpuEnableCombo = !simpuEnableCombo;
			if(cursor == 14) {
				simpuEnableB2B = simpuEnableB2B + move;
				if(simpuEnableB2B < 0) simpuEnableB2B = 3;
				if(simpuEnableB2B > 3) simpuEnableB2B = 0;
			}
			if(cursor == 15) simpuGameType = !simpuGameType;
			if(cursor >= 16) {
				simpuLastPresetNo = simpuLastPresetNo + move;
				if(simpuLastPresetNo < 0) simpuLastPresetNo = 9;
				if(simpuLastPresetNo > 9) simpuLastPresetNo = 0;
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
			
			if(cursor == 16) {
				simpuSavePreset(simpuLastPresetNo);
				simpuSaveConfig();
			} else if(cursor == 17) {
				simpuLoadPreset(simpuLastPresetNo);
			} else {
				simpuSaveConfig();
				return;
			}
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			simpuViewRanking(player);
		}
	}
}

// 設定を保存
void simpuSaveConfig() {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x504D4953;
	saveBuf[1] = 0x552D454C;
	saveBuf[2] = 0x4152544C;
	saveBuf[3] = 0x32726576;
	
	// 設定内容
	saveBuf[4] = simpuSpeed;
	saveBuf[5] = simpuSpType;
	saveBuf[6] = simpuWait1;
	saveBuf[7] = simpuWait2;
	saveBuf[8] = simpuWait3;
	saveBuf[9] = simpuWaitt;
	saveBuf[10] = simpuIsBig;
	saveBuf[11] = simpuBigMove;
	saveBuf[12] = simpuBgm;
	saveBuf[13] = simpuGhost;
	saveBuf[14] = simpuTSpin;
	saveBuf[15] = simpuEnableCombo;
	saveBuf[16] = simpuEnableB2B;
	saveBuf[17] = simpuGameType;
	saveBuf[18] = simpuWait4;
	saveBuf[19] = simpuLastPresetNo;
	saveBuf[20] = simpuWait5;
	
	// プリセット
	for(i = 0; i < 20 * 10; i++) saveBuf[100 + i] = simpuPreset[i];
	
	SaveFile("config/SIMPLE_ULTRA_CONFIG.SAV", &saveBuf, 300 * 4);
}

// 設定を読み込み
int simpuLoadConfig() {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダだけ読み込み
	LoadFile("config/SIMPLE_ULTRA_CONFIG.SAV", &saveBuf, 4 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x504D4953) return 0;
	if(saveBuf[1] != 0x552D454C) return 0;
	if(saveBuf[2] != 0x4152544C) return 0;
	if(saveBuf[3] != 0x32726576) return 0;
	
	// 全部読み込み
	LoadFile("config/SIMPLE_ULTRA_CONFIG.SAV", &saveBuf, 300 * 4);
	
	// 設定内容
	simpuSpeed = saveBuf[4];
	simpuSpType = saveBuf[5];
	simpuWait1 = saveBuf[6];
	simpuWait2 = saveBuf[7];
	simpuWait3 = saveBuf[8];
	simpuWaitt = saveBuf[9];
	simpuIsBig = saveBuf[10];
	simpuBigMove = saveBuf[11];
	simpuBgm = saveBuf[12];
	simpuGhost = saveBuf[13];
	simpuTSpin = saveBuf[14];
	simpuEnableCombo = saveBuf[15];
	simpuEnableB2B = saveBuf[16];
	simpuGameType = saveBuf[17];
	simpuWait4 = saveBuf[18];
	simpuLastPresetNo = saveBuf[19];
	simpuWait5 = saveBuf[20];
	
	// プリセット
	for(i = 0; i < 20 * 10; i++) simpuPreset[i] = saveBuf[100 + i];
	
	return 1;
}

// プリセットを初期化
void simpuMakeDefaultPreset() {
	int i;
	
	for(i = 0; i < 20 * 10; i++) simpuPreset[i] = 0;
}

// プリセットを保存
void simpuSavePreset(int number) {
	simpuPreset[number * 20 + 0] = simpuSpeed;
	simpuPreset[number * 20 + 1] = simpuSpType;
	simpuPreset[number * 20 + 2] = simpuWait1;
	simpuPreset[number * 20 + 3] = simpuWait2;
	simpuPreset[number * 20 + 4] = simpuWait3;
	simpuPreset[number * 20 + 5] = simpuWaitt;
	simpuPreset[number * 20 + 6] = simpuIsBig;
	simpuPreset[number * 20 + 7] = simpuBigMove;
	simpuPreset[number * 20 + 8] = simpuBgm;
	simpuPreset[number * 20 + 9] = simpuGhost;
	simpuPreset[number * 20 + 10] = simpuTSpin;
	simpuPreset[number * 20 + 11] = simpuEnableCombo;
	simpuPreset[number * 20 + 12] = simpuEnableB2B;
	simpuPreset[number * 20 + 13] = simpuGameType;
	simpuPreset[number * 20 + 14] = simpuWait4;
	simpuPreset[number * 20 + 15] = simpuWait5;
}

// プリセットを読み込み
void simpuLoadPreset(int number) {
	simpuSpeed = simpuPreset[number * 20 + 0];
	simpuSpType = simpuPreset[number * 20 + 1];
	simpuWait1 = simpuPreset[number * 20 + 2];
	simpuWait2 = simpuPreset[number * 20 + 3];
	simpuWait3 = simpuPreset[number * 20 + 4];
	simpuWaitt = simpuPreset[number * 20 + 5];
	simpuIsBig = simpuPreset[number * 20 + 6];
	simpuBigMove = simpuPreset[number * 20 + 7];
	simpuBgm = simpuPreset[number * 20 + 8];
	simpuGhost = simpuPreset[number * 20 + 9];
	simpuTSpin = simpuPreset[number * 20 + 10];
	simpuEnableCombo = simpuPreset[number * 20 + 11];
	simpuEnableB2B = simpuPreset[number * 20 + 12];
	simpuGameType = simpuPreset[number * 20 + 13];
	simpuWait4 = simpuPreset[number * 20 + 14];
	simpuWait5 = simpuPreset[number * 20 + 15];
}

// リプレイ保存
void simpuSaveReplay(int player) {
	saveBuf[900] = simpuSpeed;
	saveBuf[901] = simpuSpType;
	saveBuf[902] = simpuWait1;
	saveBuf[903] = simpuWait2;
	saveBuf[904] = simpuWait3;
	saveBuf[905] = simpuWaitt;
	saveBuf[906] = simpuIsBig;
	saveBuf[907] = simpuBigMove;
	saveBuf[908] = simpuBgm;
	saveBuf[909] = simpuGhost;
	saveBuf[910] = simpuTSpin;
	saveBuf[911] = simpuEnableCombo;
	saveBuf[912] = simpuEnableB2B;
	saveBuf[913] = simpuScore[player];
	saveBuf[914] = simpuLines[player];
	saveBuf[915] = simpuGameType;
	saveBuf[916] = simpuVersion;
	saveBuf[917] = simpuWait4;
	saveBuf[918] = simpuWait5;
}

// リプレイ読み込み
void simpuLoadReplay(int player) {
	simpuSpeed = saveBuf[900];
	simpuSpType = saveBuf[901];
	simpuWait1 = saveBuf[902];
	simpuWait2 = saveBuf[903];
	simpuWait3 = saveBuf[904];
	simpuWaitt = saveBuf[905];
	simpuIsBig = saveBuf[906];
	simpuBigMove = saveBuf[907];
	simpuBgm = saveBuf[908];
	simpuGhost = saveBuf[909];
	simpuTSpin = saveBuf[910];
	simpuEnableCombo = saveBuf[911];
	simpuEnableB2B = saveBuf[912];
	simpuGameType = saveBuf[915];
	simpuVersion = saveBuf[916];
	simpuWait4 = saveBuf[917];
	simpuWait5 = saveBuf[918];
	
	// 設定を反映させる
	simpuPlayerInitial(player);
}

// リプレイ詳細
void simpuReplayDetail() {
	printFontGrid(1, 4, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[913]);
	printFontGrid(22, 4, string[0], 0);
	
	printFontGrid(1, 5, "LINES", 0);
	sprintf(string[0], "%d", saveBuf[914]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 7, "SPEED", 0);
	sprintf(string[0], "%d", saveBuf[900]);
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 8, "SPEED TYPE", 0);
	if(saveBuf[901] == 0) sprintf(string[0], "1/60");
	else if(saveBuf[901] == 1) sprintf(string[0], "FRAMES PER ROW");
	else sprintf(string[0], "1/256");
	printFontGrid(22, 8, string[0], 0);
	
	if(!english) printFontGrid(1, 9, "SYUTUGEN", 0);
	else printFontGrid(1, 9, "ARE", 0);
	sprintf(string[0], "%d", saveBuf[902]);
	printFontGrid(22, 9, string[0], 0);
	
	if(!english) printFontGrid(1, 10, "SYOUKYO", 0);
	else printFontGrid(1, 10, "LINE DELAY", 0);
	sprintf(string[0], "%d", saveBuf[903]);
	printFontGrid(22, 10, string[0], 0);
	
	if(!english) printFontGrid(1, 11, "SETTYAKU", 0);
	else printFontGrid(1, 11, "LOCK DELAY", 0);
	sprintf(string[0], "%d", saveBuf[904]);
	printFontGrid(22, 11, string[0], 0);
	
	if(!english) printFontGrid(1, 12, "YOKOTAME", 0);
	else printFontGrid(1, 12, "DAS", 0);
	sprintf(string[0], "%d", saveBuf[905]);
	printFontGrid(22, 12, string[0], 0);
	
	if(!english) printFontGrid(1, 13, "SETTYAKU2", 0);
	else printFontGrid(1, 13, "LOCK DELAY2", 0);
	if((saveBuf[917] == -1) || (saveBuf[916] <= 0)) {
		if(!english) sprintf(string[0], "USE SETTYAKU");
		else sprintf(string[0], "USE LOCK DELAY");
	} else {
		sprintf(string[0], "%d", saveBuf[917]);
	}
	printFontGrid(22, 13, string[0], 0);
	
	if(!english) printFontGrid(1, 14, "SYUTUGEN2", 0);
	else printFontGrid(1, 14, "ARE2", 0);
	if((saveBuf[918] == -1) || (saveBuf[916] <= 1)) {
		if(!english) sprintf(string[0], "USE SYUTUGEN");
		else sprintf(string[0], "USE ARE");
	} else {
		sprintf(string[0], "%d", saveBuf[918]);
	}
	printFontGrid(22, 14, string[0], 0);
	
	printFontGrid(1, 15, "BIG", 0);
	if(!saveBuf[906]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 15, string[0], 0);
	
	printFontGrid(1, 16, "BIG MOVE", 0);
	if(!saveBuf[907]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 16, string[0], 0);
	
	printFontGrid(1, 17, "BGM", 0);
	sprintf(string[0], "%d", saveBuf[908]);
	printFontGrid(22, 17, string[0], 0);
	
	printFontGrid(1, 18, "GHOST BLOCK", 0);
	if(!saveBuf[909]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 18, string[0], 0);
	
	printFontGrid(1, 19, "T-SPIN", 0);
	if(saveBuf[910] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[910] == 1) sprintf(string[0], "LINE CLEAR");
	else if(saveBuf[910] == 2) sprintf(string[0], "IMMOBILE");
	else if(saveBuf[910] == 3) sprintf(string[0], "3-CORNER");
	else sprintf(string[0], "3-CORNER NO KICK");
	printFontGrid(22, 19, string[0], 0);
	
	printFontGrid(1, 20, "COMBO", 0);
	if(!saveBuf[911]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 20, string[0], 0);
	
	printFontGrid(1, 21, "BACK TO BACK", 0);
	if(saveBuf[912] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[912] == 1) sprintf(string[0], "ON");
	else if(saveBuf[912] == 2) sprintf(string[0], "HEBORIS ONLY");
	else sprintf(string[0], "T-SPIN ONLY");
	printFontGrid(22, 21, string[0], 0);
	
	printFontGrid(1, 22, "GAME TYPE", 0);
	if(!saveBuf[915]) sprintf(string[0], "2MIN LINE ATTACK");
	else sprintf(string[0], "3MIN SCORE ATTACK");
	printFontGrid(22, 22, string[0], 0);
	
	printFontGrid(1, 23, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[916]);
	printFontGrid(22, 23, string[0], 0);
}

// ランキング保存
void simpuSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 5*2; i++) {
		saveBuf[1 + (i * 20) + 0]  = simpuRankingScore[i];
		saveBuf[1 + (i * 20) + 1]  = simpuRankingLine[i];
		saveBuf[1 + (i * 20) + 2]  = simpuRankingSpeed[i];
		saveBuf[1 + (i * 20) + 3]  = simpuRankingSpType[i];
		saveBuf[1 + (i * 20) + 4]  = simpuRankingWait1[i];
		saveBuf[1 + (i * 20) + 5]  = simpuRankingWait2[i];
		saveBuf[1 + (i * 20) + 6]  = simpuRankingWait3[i];
		saveBuf[1 + (i * 20) + 7]  = simpuRankingWaitt[i];
		saveBuf[1 + (i * 20) + 8]  = simpuRankingYear[i];
		saveBuf[1 + (i * 20) + 9]  = simpuRankingMonth[i];
		saveBuf[1 + (i * 20) + 10] = simpuRankingDay[i];
		saveBuf[1 + (i * 20) + 11] = simpuRankingHour[i];
		saveBuf[1 + (i * 20) + 12] = simpuRankingMinute[i];
		saveBuf[1 + (i * 20) + 13] = simpuRankingSecond[i];
		saveBuf[1 + (i * 20) + 14] = simpuRankingWait4[i];
		saveBuf[1 + (i * 20) + 15] = simpuRankingWait5[i];
	}
	
	sprintf(string[0], "config/SIMPLE_ULTRA_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 221 * 4);
}

// ランキング読み込み
int simpuLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/SIMPLE_ULTRA_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 221 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 5*2; i++) {
		simpuRankingScore[i]  = saveBuf[1 + (i * 20) + 0];
		simpuRankingLine[i]   = saveBuf[1 + (i * 20) + 1];
		simpuRankingSpeed[i]  = saveBuf[1 + (i * 20) + 2];
		simpuRankingSpType[i] = saveBuf[1 + (i * 20) + 3];
		simpuRankingWait1[i]  = saveBuf[1 + (i * 20) + 4];
		simpuRankingWait2[i]  = saveBuf[1 + (i * 20) + 5];
		simpuRankingWait3[i]  = saveBuf[1 + (i * 20) + 6];
		simpuRankingWaitt[i]  = saveBuf[1 + (i * 20) + 7];
		simpuRankingYear[i]   = saveBuf[1 + (i * 20) + 8];
		simpuRankingMonth[i]  = saveBuf[1 + (i * 20) + 9];
		simpuRankingDay[i]    = saveBuf[1 + (i * 20) + 10];
		simpuRankingHour[i]   = saveBuf[1 + (i * 20) + 11];
		simpuRankingMinute[i] = saveBuf[1 + (i * 20) + 12];
		simpuRankingSecond[i] = saveBuf[1 + (i * 20) + 13];
		simpuRankingWait4[i]  = saveBuf[1 + (i * 20) + 14];
		simpuRankingWait5[i]  = saveBuf[1 + (i * 20) + 15];
	}
	
	return 1;
}

// ランキング初期化
void simpuInitRanking() {
	int i;
	
	for(i = 0; i < 5*2; i++) {
		simpuRankingScore[i]  = 0;
		simpuRankingLine[i]   = 0;
		simpuRankingSpeed[i]  = 0;
		simpuRankingSpType[i] = 0;
		simpuRankingWait1[i]  = 0;
		simpuRankingWait2[i]  = 0;
		simpuRankingWait3[i]  = 0;
		simpuRankingWaitt[i]  = 0;
		simpuRankingYear[i]   = 0;
		simpuRankingMonth[i]  = 0;
		simpuRankingDay[i]    = 0;
		simpuRankingHour[i]   = 0;
		simpuRankingMinute[i] = 0;
		simpuRankingSecond[i] = 0;
		simpuRankingWait4[i]  = 0;
		simpuRankingWait5[i]  = 0;
	}
}

// ランキング登録
int simpuRegistRanking(int player) {
	int i, j, temp, temp2, timebuf[8];
	
	if(playback || IsBig[player]) return -1;
	
	for(i = 0; i < 5; i++) {
		if(!simpuGameType) {
			temp = simpuLines[player];
			temp2 = simpuRankingLine[simpuGameType * 5 + i];
		} else {
			temp = simpuScore[player];
			temp2 = simpuRankingScore[simpuGameType * 5 + i];
		}
		
		// ランクイン
		if(temp > temp2) {
			// ランキングをずらす
			for(j = 4; j > i; j--) {
				simpuRankingScore[simpuGameType * 5 + j]  = simpuRankingScore[simpuGameType * 5 + j - 1];
				simpuRankingLine[simpuGameType * 5 + j]   = simpuRankingLine[simpuGameType * 5 + j - 1];
				simpuRankingSpeed[simpuGameType * 5 + j]  = simpuRankingSpeed[simpuGameType * 5 + j - 1];
				simpuRankingSpType[simpuGameType * 5 + j] = simpuRankingSpType[simpuGameType * 5 + j - 1];
				simpuRankingWait1[simpuGameType * 5 + j]  = simpuRankingWait1[simpuGameType * 5 + j - 1];
				simpuRankingWait2[simpuGameType * 5 + j]  = simpuRankingWait2[simpuGameType * 5 + j - 1];
				simpuRankingWait3[simpuGameType * 5 + j]  = simpuRankingWait3[simpuGameType * 5 + j - 1];
				simpuRankingWaitt[simpuGameType * 5 + j]  = simpuRankingWaitt[simpuGameType * 5 + j - 1];
				simpuRankingYear[simpuGameType * 5 + j]   = simpuRankingYear[simpuGameType * 5 + j - 1];
				simpuRankingMonth[simpuGameType * 5 + j]  = simpuRankingMonth[simpuGameType * 5 + j - 1];
				simpuRankingDay[simpuGameType * 5 + j]    = simpuRankingDay[simpuGameType * 5 + j - 1];
				simpuRankingHour[simpuGameType * 5 + j]   = simpuRankingHour[simpuGameType * 5 + j - 1];
				simpuRankingMinute[simpuGameType * 5 + j] = simpuRankingMinute[simpuGameType * 5 + j - 1];
				simpuRankingSecond[simpuGameType * 5 + j] = simpuRankingSecond[simpuGameType * 5 + j - 1];
				simpuRankingWait4[simpuGameType * 5 + j]  = simpuRankingWait4[simpuGameType * 5 + j - 1];
				simpuRankingWait5[simpuGameType * 5 + j]  = simpuRankingWait5[simpuGameType * 5 + j - 1];
			}
			
			// 新しいデータを登録
			simpuRankingScore[simpuGameType * 5 + i] = simpuScore[player];
			simpuRankingLine[simpuGameType * 5 + i] = simpuLines[player];
			simpuRankingSpeed[simpuGameType * 5 + i] = simpuSpeed;
			simpuRankingSpType[simpuGameType * 5 + i] = simpuSpType;
			simpuRankingWait1[simpuGameType * 5 + i] = simpuWait1;
			simpuRankingWait2[simpuGameType * 5 + i] = simpuWait2;
			simpuRankingWait3[simpuGameType * 5 + i] = simpuWait3;
			simpuRankingWaitt[simpuGameType * 5 + i] = simpuWaitt;
			
			GetDateAndTime(&timebuf);
			simpuRankingYear[simpuGameType * 5 + i] = timebuf[0];
			simpuRankingMonth[simpuGameType * 5 + i] = timebuf[1];
			simpuRankingDay[simpuGameType * 5 + i] = timebuf[2];
			simpuRankingHour[simpuGameType * 5 + i] = timebuf[4];
			simpuRankingMinute[simpuGameType * 5 + i] = timebuf[5];
			simpuRankingSecond[simpuGameType * 5 + i] = timebuf[6];
			
			simpuRankingWait4[simpuGameType * 5 + i] = simpuWait4;
			simpuRankingWait5[simpuGameType * 5 + i] = simpuWait5;
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void simpuViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		// 2分間モード
		printFontGrid(1, 1, "2MIN LINE ATTACK RANKING", 6);
		printFontGrid(1, 3, "RANK LINES SCORE   DATE", 4);
		
		for(i = 0; i < 5; i++) {
			if(i == 0) sprintf(string[0], "1ST");
			if(i == 1) sprintf(string[0], "2ND");
			if(i == 2) sprintf(string[0], "3RD");
			if(i == 3) sprintf(string[0], "4TH");
			if(i == 4) sprintf(string[0], "5TH");
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", simpuRankingLine[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", simpuRankingScore[i]);
			printFontGrid(12, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%04d/%02d/%02d", simpuRankingYear[i], simpuRankingMonth[i], simpuRankingDay[i]);
			printFontGrid(20, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%02d:%02d:%02d", simpuRankingHour[i], simpuRankingMinute[i], simpuRankingSecond[i]);
			printFontGrid(31, 4 + i, string[0], 7 * (cursor == i));
		}
		
		// 3分間モード
		printFontGrid(1, 11, "3MIN SCORE ATTACK RANKING", 6);
		printFontGrid(1, 13, "RANK LINES SCORE   DATE", 4);
		
		for(i = 0; i < 5; i++) {
			if(i == 0) sprintf(string[0], "1ST");
			if(i == 1) sprintf(string[0], "2ND");
			if(i == 2) sprintf(string[0], "3RD");
			if(i == 3) sprintf(string[0], "4TH");
			if(i == 4) sprintf(string[0], "5TH");
			printFontGrid(1, 14 + i, string[0], 7 * (cursor == i + 5));
			
			sprintf(string[0], "%d", simpuRankingLine[i + 5]);
			printFontGrid(6, 14 + i, string[0], 7 * (cursor == i + 5));
			
			sprintf(string[0], "%d", simpuRankingScore[i + 5]);
			printFontGrid(12, 14 + i, string[0], 7 * (cursor == i + 5));
			
			sprintf(string[0], "%04d/%02d/%02d", simpuRankingYear[i + 5], simpuRankingMonth[i + 5], simpuRankingDay[i + 5]);
			printFontGrid(20, 14 + i, string[0], 7 * (cursor == i + 5));
			
			sprintf(string[0], "%02d:%02d:%02d", simpuRankingHour[i + 5], simpuRankingMinute[i + 5], simpuRankingSecond[i + 5]);
			printFontGrid(31, 14 + i, string[0], 7 * (cursor == i + 5));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// スピードデータ
			sprintf(string[0], "SPEED:%d", simpuRankingSpeed[cursor]);
			printFontGrid(1, 24, string[0], 0);
			
			if(simpuRankingSpType[cursor] == 0) sprintf(string[0], "(1/60)");
			if(simpuRankingSpType[cursor] == 1) sprintf(string[0], "(FRAMES PER ROW)");
			if(simpuRankingSpType[cursor] == 2) sprintf(string[0], "(1/256)");
			printFontGrid(11, 24, string[0], 0);
			
			sprintf(string[0], "W1:%2d W2:%2d W3:%2d WT:%2d W4:%2d W5:%2d",
			        simpuRankingWait1[cursor], simpuRankingWait2[cursor], simpuRankingWait3[cursor], simpuRankingWaitt[cursor],
			        simpuRankingWait4[cursor], simpuRankingWait5[cursor]);
			printFontGrid(1, 25, string[0], 0);
			
			printFontGrid(1, 27, "A/B:EXIT F:ERASE ALL", 6);
			
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
				simpuInitRanking();
				simpuSaveRanking(player);
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
