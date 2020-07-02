//SIMPLE-100LINES
//prefix:simph
//Original program by DIGITAL
//Fixed the compatibility with 40Lines mode
//Fixed the position of "LINES" display in game

// 変数
int simphVersion;			// バージョン番号
int simphCVersion = 2;		// 現在のバージョン

int simphModeNo = -1;		// モード番号
int simphLines[2];			// ライン

int simphSpeed = 1;			// 落下速度
int simphSpType = 0;		// スピードタイプ
int simphWait1 = 25;		// ARE
int simphWait2 = 25;		// ライン消去待ち時間
int simphWait3 = 30;		// ブロックが固定されるまでの猶予時間
int simphWaitt = 16;		// DAS
int simphIsBig = 0;			// BIGかどうか
int simphBigMove = 1;		// BIG時の横移動単位
int simphBgm = 0;			// 使用するBGM
int simphGhost = 1;			// ゴーストの設定
int simphWait4 = -1;		// ブロックが固定されるまでの猶予時間（段差から落下後）
int simphWait5 = -1;		// ライン消去後のARE

int simphPreset[20 * 10];	// プリセット
int simphLastPresetNo = 0;	// 最後に選択したプリセット番号

// ランキング用変数
int simphRankingTime[10];	// クリアタイム
int simphRankingSpeed[10];	// 落下速度
int simphRankingSpType[10];	// スピードタイプ
int simphRankingWait1[10];	// ARE
int simphRankingWait2[10];	// ライン消去待ち時間
int simphRankingWait3[10];	// ブロックが固定されるまでの猶予時間
int simphRankingWaitt[10];	// DAS
int simphRankingYear[10];	// ランクイン日時（年）
int simphRankingMonth[10];	// ランクイン日時（月）
int simphRankingDay[10];	// ランクイン日時（日）
int simphRankingHour[10];	// ランクイン日時（時）
int simphRankingMinute[10];	// ランクイン日時（分）
int simphRankingSecond[10];	// ランクイン日時（秒）
int simphRankingWait4[10];	// ブロックが固定されるまでの猶予時間（段差から落下後）
int simphRankingWait5[10];	// ライン消去後のARE

// イベント発生
void simphPluginEvent(int player, int event, int *param) {
	int i;
	
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != simphModeNo)) return;
	
	if(event == 0) {
		simphModeNo = addModePlugin("SIMPLE-100LINES");	// モードを登録する
	} else if(event == 12) {
		simphCalcScore(player, param[0]);	// スコア計算
	} else if(event == 15) {
		simphViewScore(player);	// スコア表示
	} else if(event == 17) {
		simphSetting(player, param);	// 設定画面
	} else if(event == 18) {
		simphPlayerInitial(player);	// 初期化
	} else if(event == 21) {
		simphResult(player);	// 結果表示
	} else if(event == 24) {
		onRecord[player] = 0;	// エンディング突入
		ending[player] = 3;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		param[0] = 5;	// EXCELLENT画面を省略
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		simphSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		simphLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		simphLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		simphReplayDetail();	// リプレイ詳細
	}
}

// 初期化
void simphPlayerInitial(int player) {
	// バージョン
	if(!playback) simphVersion = simphCVersion;
	
	// ライン数を初期化
	simphLines[player] = 0;
	
	// 枠の色を変える
	framecolor[player] = 3;
	
	// 設定を反映させる
	sp[player] = simphSpeed;
	speedtype[player] = simphSpType;
	wait1[player] = simphWait1;
	wait2[player] = simphWait2;
	wait3[player] = simphWait3;
	waitt[player] = simphWaitt;
	IsBig[player] = simphIsBig;
	BigMove[player] = simphBigMove;
	bgmlv = simphBgm;
	if(simphGhost == 0) ghost[player] = 0;
	
	if(simphVersion >= 1) wait4[player] = simphWait4;
	else wait4[player] = -1;
	
	if(simphVersion >= 2) wait5[player] = simphWait5;
	else wait5[player] = -1;
}

// スコア計算
void simphCalcScore(int player, int lines) {
	// ライン数増加
	simphLines[player] = simphLines[player] + lines;
	
	// クリア
	if(simphLines[player] >= 100) {
		ending[player] = 1;
		timeOn[player] = 0;
	}
}

// スコア表示
void simphViewScore(int player) {
	int temp, color;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// 残りライン
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "LINES");
	if(simphLines[player] > 100) sprintf(string[0], "%d", 0);
	else sprintf(string[0], "%d", 100 - simphLines[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// ベストタイム
	if(!playback) {
		printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "BEST TIME");
		getTime(simphRankingTime[0]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	}
	
	// スピード
	printTinyFont(foffset[player] + 96, fyoffset[player] + 153, "SPEED");
	sprintf(string[0], "%d", simphSpeed);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 161, string[0], color);
	
	sprintf(string[0], "TYPE %d", simphSpType + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 171, string[0], color);
	
	// wait値
	ExBltRect(sg_smallfont, foffset[player] + 96, fyoffset[player] + 181, 68, 14, 24, 7);	// WAITS
	sprintf(string[0], "%2d %2d\n%2d %2d", simphWait1, simphWait2, simphWait3, simphWaitt);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 189, string[0], color);
	
	if(wait4[player] != -1) {
		sprintf(string[0], "%2d", simphWait4);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 207, string[0], color);
	}
	
	if(wait5[player] != -1) {
		sprintf(string[0], "%2d", simphWait5);
		printSMALLFont(foffset[player] + 114, fyoffset[player] + 207, string[0], color);
	}
	
	// BLOCK/SEC
	printTinyFont(foffset[player] + 96, fyoffset[player] + 76, "BLOCK/SEC");
	if(gameTimer[player] > 0) {
		temp = (bdowncnt[player] * 10000 * 60) / gameTimer[player];
	} else {
		temp = 0;
	}
	sprintf(string[0], "%d.%04d", temp / 10000, temp % 10000);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 84, string[0], color);
	
	// LINES/MIN
	printTinyFont(foffset[player] + 96, fyoffset[player] + 94, "LINES/MIN");
	if(gameTimer[player] > 0) {
		temp = (simphLines[player] * 100 * 3600) / gameTimer[player];
	} else {
		temp = 0;
	}
	sprintf(string[0], "%d.%02d", temp / 100, temp % 100);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 102, string[0], color);
	
	// 時間
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
}

// 結果表示
void simphResult(int player) {
	// ランキング登録
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = simphRegistRanking(player);
		if(statc[player * 10 + 1] != -1) simphSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", simphLines[player]);
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
}

// BGM読み込み
void simphLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(simphBgm);
	}
}

// 設定画面
void simphSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(simphLoadConfig() == 0) simphMakeDefaultPreset();
	
	// ランキングを読み込み
	if(simphLoadRanking(player) == 0) simphInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "SIMPLE-100LINES OPTIONS", 4);
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
		printFontGrid(2, 15, "[SAVE PRESET]", 7 * (cursor == 12));
		printFontGrid(2, 16, "[LOAD PRESET]", 7 * (cursor == 13));
		
		// 設定値表示
		sprintf(string[0], "%d", simphSpeed);
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(simphSpType == 0) sprintf(string[0], "1/60");
		else if(simphSpType == 1) sprintf(string[0], "FRAMES PER ROW");
		else sprintf(string[0], "1/256");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "%d", simphWait1);
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "%d", simphWait2);
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		sprintf(string[0], "%d", simphWait3);
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		sprintf(string[0], "%d", simphWaitt);
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		if(simphWait4 == -1) {
			if(!english) sprintf(string[0], "USE SETTYAKU");
			else sprintf(string[0], "USE LOCK DELAY");
		} else {
			sprintf(string[0], "%d", simphWait4);
		}
		printFontGrid(22, 9, string[0], 7 * (cursor == 6));
		
		if(simphWait5 == -1) {
			if(!english) sprintf(string[0], "USE SYUTUGEN");
			else sprintf(string[0], "USE ARE");
		} else {
			sprintf(string[0], "%d", simphWait5);
		}
		printFontGrid(22, 10, string[0], 7 * (cursor == 7));
		
		if(!simphIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 11, string[0], 7 * (cursor == 8));
		
		if(!simphBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 12, string[0], 7 * (cursor == 9));
		
		sprintf(string[0], "%d", simphBgm);
		printFontGrid(22, 13, string[0], 7 * (cursor == 10));
		
		if(!simphGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 14, string[0], 7 * (cursor == 11));
		
		sprintf(string[0], "PRESET NO.%d", simphLastPresetNo + 1);
		printFontGrid(22, 15, string[0], 7 * (cursor >= 12));
		
		// カーソル移動
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 13;
			if(cursor > 13) cursor = 0;
		}
		
		// 値を変更
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) {
				simphSpeed = simphSpeed + move;
				if(simphSpeed < 0) simphSpeed = 5120;
				if(simphSpeed > 5120) simphSpeed = 0;
			}
			if(cursor == 1) {
				simphSpType = simphSpType + move;
				if(simphSpType < 0) simphSpType = 2;
				if(simphSpType > 2) simphSpType = 0;
			}
			if(cursor == 2) {
				simphWait1 = simphWait1 + move;
				if(simphWait1 < 0) simphWait1 = 99;
				if(simphWait1 > 99) simphWait1 = 0;
			}
			if(cursor == 3) {
				simphWait2 = simphWait2 + move;
				if(simphWait2 < 0) simphWait2 = 99;
				if(simphWait2 > 99) simphWait2 = 0;
			}
			if(cursor == 4) {
				simphWait3 = simphWait3 + move;
				if(simphWait3 < 0) simphWait3 = 99;
				if(simphWait3 > 99) simphWait3 = 0;
			}
			if(cursor == 5) {
				simphWaitt = simphWaitt + move;
				if(simphWaitt < 0) simphWaitt = 99;
				if(simphWaitt > 99) simphWaitt = 0;
			}
			if(cursor == 6) {
				simphWait4 = simphWait4 + move;
				if(simphWait4 < -1) simphWait4 = 99;
				if(simphWait4 > 99) simphWait4 = -1;
			}
			if(cursor == 7) {
				simphWait5 = simphWait5 + move;
				if(simphWait5 < -1) simphWait5 = 99;
				if(simphWait5 > 99) simphWait5 = -1;
			}
			if(cursor == 8) simphIsBig = !simphIsBig;
			if(cursor == 9) simphBigMove = !simphBigMove;
			if(cursor == 10) {
				simphBgm = simphBgm + move;
				if(simphBgm < 0) simphBgm = 29;
				if(simphBgm > 29) simphBgm = 0;
			}
			if(cursor == 11) simphGhost = !simphGhost;
			if(cursor >= 12) {
				simphLastPresetNo = simphLastPresetNo + move;
				if(simphLastPresetNo < 0) simphLastPresetNo = 9;
				if(simphLastPresetNo > 9) simphLastPresetNo = 0;
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
			
			if(cursor == 12) {
				simphSavePreset(simphLastPresetNo);
				simphSaveConfig();
			} else if(cursor == 13) {
				simphLoadPreset(simphLastPresetNo);
			} else {
				simphSaveConfig();
				return;
			}
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			simphViewRanking(player);
		}
	}
}

// 設定を保存
void simphSaveConfig() {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x504D4953;
	saveBuf[1] = 0x342D454C;
	saveBuf[2] = 0x4E494C30;
	saveBuf[3] = 0x32765345;
	
	// 設定内容
	saveBuf[4] = simphSpeed;
	saveBuf[5] = simphSpType;
	saveBuf[6] = simphWait1;
	saveBuf[7] = simphWait2;
	saveBuf[8] = simphWait3;
	saveBuf[9] = simphWaitt;
	saveBuf[10] = simphIsBig;
	saveBuf[11] = simphBigMove;
	saveBuf[12] = simphBgm;
	saveBuf[13] = simphGhost;
	saveBuf[14] = simphWait4;
	saveBuf[15] = simphWait5;
	
	saveBuf[99] = simphLastPresetNo;
	for(i = 0; i < 20 * 10; i++) saveBuf[100 + i] = simphPreset[i];
	
	SaveFile("config/SIMPLE_100LINES_CONFIG.SAV", &saveBuf, 300 * 4);
}

// 設定を読み込み
int simphLoadConfig() {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダだけ読み込み
	LoadFile("config/SIMPLE_100LINES_CONFIG.SAV", &saveBuf, 4 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x504D4953) return 0;
	if(saveBuf[1] != 0x342D454C) return 0;
	if(saveBuf[2] != 0x4E494C30) return 0;
	if(saveBuf[3] != 0x32765345) return 0;
	
	// 全部読み込み
	LoadFile("config/SIMPLE_100LINES_CONFIG.SAV", &saveBuf, 300 * 4);
	
	// 設定内容
	simphSpeed = saveBuf[4];
	simphSpType = saveBuf[5];
	simphWait1 = saveBuf[6];
	simphWait2 = saveBuf[7];
	simphWait3 = saveBuf[8];
	simphWaitt = saveBuf[9];
	simphIsBig = saveBuf[10];
	simphBigMove = saveBuf[11];
	simphBgm = saveBuf[12];
	simphGhost = saveBuf[13];
	simphWait4 = saveBuf[14];
	simphWait5 = saveBuf[15];
	
	simphLastPresetNo = saveBuf[99];
	for(i = 0; i < 20 * 10; i++) simphPreset[i] = saveBuf[100 + i];
	
	return 1;
}

// プリセットを初期化
void simphMakeDefaultPreset() {
	int i;
	
	for(i = 0; i < 20 * 10; i++) simphPreset[i] = 0;
}

// プリセットを保存
void simphSavePreset(int number) {
	simphPreset[number * 20 + 0]  = simphSpeed;
	simphPreset[number * 20 + 1]  = simphSpType;
	simphPreset[number * 20 + 2]  = simphWait1;
	simphPreset[number * 20 + 3]  = simphWait2;
	simphPreset[number * 20 + 4]  = simphWait3;
	simphPreset[number * 20 + 5]  = simphWaitt;
	simphPreset[number * 20 + 6]  = simphIsBig;
	simphPreset[number * 20 + 7]  = simphBigMove;
	simphPreset[number * 20 + 8]  = simphBgm;
	simphPreset[number * 20 + 9]  = simphGhost;
	simphPreset[number * 20 + 10] = simphWait4;
	simphPreset[number * 20 + 11] = simphWait5;
}

// プリセットを読み込み
void simphLoadPreset(int number) {
	simphSpeed = simphPreset[number * 20 + 0];
	simphSpType = simphPreset[number * 20 + 1];
	simphWait1 = simphPreset[number * 20 + 2];
	simphWait2 = simphPreset[number * 20 + 3];
	simphWait3 = simphPreset[number * 20 + 4];
	simphWaitt = simphPreset[number * 20 + 5];
	simphIsBig = simphPreset[number * 20 + 6];
	simphBigMove = simphPreset[number * 20 + 7];
	simphBgm = simphPreset[number * 20 + 8];
	simphGhost = simphPreset[number * 20 + 9];
	simphWait4 = simphPreset[number * 20 + 10];
	simphWait5 = simphPreset[number * 20 + 11];
}

// リプレイ保存
void simphSaveReplay(int player) {
	saveBuf[900] = simphLines[player];
	saveBuf[901] = simphSpeed;
	saveBuf[902] = simphSpType;
	saveBuf[903] = simphWait1;
	saveBuf[904] = simphWait2;
	saveBuf[905] = simphWait3;
	saveBuf[906] = simphWaitt;
	saveBuf[907] = simphIsBig;
	saveBuf[908] = simphBigMove;
	saveBuf[909] = simphBgm;
	saveBuf[910] = simphGhost;
	saveBuf[911] = simphVersion;
	saveBuf[912] = simphWait4;
	saveBuf[913] = simphWait5;
}

// リプレイ読み込み
void simphLoadReplay(int player) {
	simphSpeed = saveBuf[901];
	simphSpType = saveBuf[902];
	simphWait1 = saveBuf[903];
	simphWait2 = saveBuf[904];
	simphWait3 = saveBuf[905];
	simphWaitt = saveBuf[906];
	simphIsBig = saveBuf[907];
	simphBigMove = saveBuf[908];
	simphBgm = saveBuf[909];
	simphGhost = saveBuf[910];
	simphVersion = saveBuf[911];
	simphWait4 = saveBuf[912];
	simphWait5 = saveBuf[913];
	
	// 設定を反映させる
	simphPlayerInitial(player);
}

// リプレイ詳細
void simphReplayDetail() {
	printFontGrid(1, 4, "LINES", 0);
	sprintf(string[0], "%d", saveBuf[900]);
	printFontGrid(22, 4, string[0], 0);
	
	printFontGrid(1, 5, "SPEED", 0);
	sprintf(string[0], "%d", saveBuf[901]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "SPEED TYPE", 0);
	if(saveBuf[902] == 0) sprintf(string[0], "1/60");
	else if(saveBuf[902] == 1) sprintf(string[0], "FRAMES PER ROW");
	else sprintf(string[0], "1/256");
	printFontGrid(22, 6, string[0], 0);
	
	if(!english) printFontGrid(1, 7, "SYUTUGEN", 0);
	else printFontGrid(1, 7, "ARE", 0);
	sprintf(string[0], "%d", saveBuf[903]);
	printFontGrid(22, 7, string[0], 0);
	
	if(!english) printFontGrid(1, 8, "SYOUKYO", 0);
	else printFontGrid(1, 8, "LINE DELAY", 0);
	sprintf(string[0], "%d", saveBuf[904]);
	printFontGrid(22, 8, string[0], 0);
	
	if(!english) printFontGrid(1, 9, "SETTYAKU", 0);
	else printFontGrid(1, 9, "LOCK DELAY", 0);
	sprintf(string[0], "%d", saveBuf[905]);
	printFontGrid(22, 9, string[0], 0);
	
	if(!english) printFontGrid(1, 10, "YOKOTAME", 0);
	else printFontGrid(1, 10, "DAS", 0);
	sprintf(string[0], "%d", saveBuf[906]);
	printFontGrid(22, 10, string[0], 0);
	
	if(!english) printFontGrid(1, 11, "SETTYAKU2", 0);
	else printFontGrid(1, 11, "LOCK DELAY2", 0);
	if((saveBuf[912] == -1) || (saveBuf[911] <= 0)) {
		if(!english) sprintf(string[0], "USE SETTYAKU");
		else sprintf(string[0], "USE LOCK DELAY");
	} else {
		sprintf(string[0], "%d", saveBuf[912]);
	}
	printFontGrid(22, 11, string[0], 0);
	
	if(!english) printFontGrid(1, 12, "SYUTUGEN2", 0);
	else printFontGrid(1, 12, "ARE2", 0);
	if((saveBuf[913] == -1) || (saveBuf[911] <= 1)) {
		if(!english) sprintf(string[0], "USE SYUTUGEN");
		else sprintf(string[0], "USE ARE");
	} else {
		sprintf(string[0], "%d", saveBuf[913]);
	}
	printFontGrid(22, 12, string[0], 0);
	
	printFontGrid(1, 13, "BIG", 0);
	if(!saveBuf[907]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 13, string[0], 0);
	
	printFontGrid(1, 14, "BIG MOVE", 0);
	if(!saveBuf[908]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 14, string[0], 0);
	
	printFontGrid(1, 15, "BGM", 0);
	sprintf(string[0], "%d", saveBuf[909]);
	printFontGrid(22, 15, string[0], 0);
	
	printFontGrid(1, 16, "GHOST BLOCK", 0);
	if(!saveBuf[910]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 16, string[0], 0);
	
	printFontGrid(1, 17, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[911]);
	printFontGrid(22, 17, string[0], 0);
}

// ランキング保存
void simphSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0]  = simphRankingTime[i];
		saveBuf[1 + (i * 20) + 1]  = simphRankingSpeed[i];
		saveBuf[1 + (i * 20) + 2]  = simphRankingSpType[i];
		saveBuf[1 + (i * 20) + 3]  = simphRankingWait1[i];
		saveBuf[1 + (i * 20) + 4]  = simphRankingWait2[i];
		saveBuf[1 + (i * 20) + 5]  = simphRankingWait3[i];
		saveBuf[1 + (i * 20) + 6]  = simphRankingWaitt[i];
		saveBuf[1 + (i * 20) + 7]  = simphRankingYear[i];
		saveBuf[1 + (i * 20) + 8]  = simphRankingMonth[i];
		saveBuf[1 + (i * 20) + 9]  = simphRankingDay[i];
		saveBuf[1 + (i * 20) + 10] = simphRankingHour[i];
		saveBuf[1 + (i * 20) + 11] = simphRankingMinute[i];
		saveBuf[1 + (i * 20) + 12] = simphRankingSecond[i];
		saveBuf[1 + (i * 20) + 13] = simphRankingWait4[i];
		saveBuf[1 + (i * 20) + 14] = simphRankingWait5[i];
	}
	
	sprintf(string[0], "config/SIMPLE_100LINES_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 221 * 4);
}

// ランキング読み込み
int simphLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/SIMPLE_100LINES_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 221 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 10; i++) {
		simphRankingTime[i]   = saveBuf[1 + (i * 20) + 0];
		simphRankingSpeed[i]  = saveBuf[1 + (i * 20) + 1];
		simphRankingSpType[i] = saveBuf[1 + (i * 20) + 2];
		simphRankingWait1[i]  = saveBuf[1 + (i * 20) + 3];
		simphRankingWait2[i]  = saveBuf[1 + (i * 20) + 4];
		simphRankingWait3[i]  = saveBuf[1 + (i * 20) + 5];
		simphRankingWaitt[i]  = saveBuf[1 + (i * 20) + 6];
		simphRankingYear[i]   = saveBuf[1 + (i * 20) + 7];
		simphRankingMonth[i]  = saveBuf[1 + (i * 20) + 8];
		simphRankingDay[i]    = saveBuf[1 + (i * 20) + 9];
		simphRankingHour[i]   = saveBuf[1 + (i * 20) + 10];
		simphRankingMinute[i] = saveBuf[1 + (i * 20) + 11];
		simphRankingSecond[i] = saveBuf[1 + (i * 20) + 12];
		simphRankingWait4[i]  = saveBuf[1 + (i * 20) + 13];
		simphRankingWait5[i]  = saveBuf[1 + (i * 20) + 14];
	}
	
	return 1;
}

// ランキング初期化
void simphInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		simphRankingTime[i]   = 0;
		simphRankingSpeed[i]  = 0;
		simphRankingSpType[i] = 0;
		simphRankingWait1[i]  = 0;
		simphRankingWait2[i]  = 0;
		simphRankingWait3[i]  = 0;
		simphRankingWaitt[i]  = 0;
		simphRankingYear[i]   = 0;
		simphRankingMonth[i]  = 0;
		simphRankingDay[i]    = 0;
		simphRankingHour[i]   = 0;
		simphRankingMinute[i] = 0;
		simphRankingSecond[i] = 0;
		simphRankingWait4[i]  = 0;
		simphRankingWait5[i]  = 0;
	}
}

// ランキング登録
int simphRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (!ending[player])) return -1;
	
	for(i = 0; i < 10; i++) {
		// ランクイン
		if((gameTimer[player] < simphRankingTime[i]) || (simphRankingTime[i] == 0)) {
			// ランキングをずらす
			for(j = 9; j > i; j--) {
				simphRankingTime[j]   = simphRankingTime[j - 1];
				simphRankingSpeed[j]  = simphRankingSpeed[j - 1];
				simphRankingSpType[j] = simphRankingSpType[j - 1];
				simphRankingWait1[j]  = simphRankingWait1[j - 1];
				simphRankingWait2[j]  = simphRankingWait2[j - 1];
				simphRankingWait3[j]  = simphRankingWait3[j - 1];
				simphRankingWaitt[j]  = simphRankingWaitt[j - 1];
				simphRankingYear[j]   = simphRankingYear[j - 1];
				simphRankingMonth[j]  = simphRankingMonth[j - 1];
				simphRankingDay[j]    = simphRankingDay[j - 1];
				simphRankingHour[j]   = simphRankingHour[j - 1];
				simphRankingMinute[j] = simphRankingMinute[j - 1];
				simphRankingSecond[j] = simphRankingSecond[j - 1];
				simphRankingWait4[j]  = simphRankingWait4[j - 1];
				simphRankingWait5[j]  = simphRankingWait5[j - 1];
			}
			
			// 新しいデータを登録
			simphRankingTime[i]   = gameTimer[player];
			simphRankingSpeed[i]  = simphSpeed;
			simphRankingSpType[i] = simphSpType;
			simphRankingWait1[i]  = simphWait1;
			simphRankingWait2[i]  = simphWait2;
			simphRankingWait3[i]  = simphWait3;
			simphRankingWaitt[i]  = simphWaitt;
			
			GetDateAndTime(&timebuf);
			simphRankingYear[i]   = timebuf[0];
			simphRankingMonth[i]  = timebuf[1];
			simphRankingDay[i]    = timebuf[2];
			simphRankingHour[i]   = timebuf[4];
			simphRankingMinute[i] = timebuf[5];
			simphRankingSecond[i] = timebuf[6];
			
			simphRankingWait4[i]  = simphWait4;
			simphRankingWait5[i]  = simphWait5;
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void simphViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "100LINES MODE RANKING", 6);
		printFontGrid(1, 3, "RANK TIME          DATE", 4);
		
		for(i = 0; i < 10; i++) {
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(simphRankingTime[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%04d/%02d/%02d", simphRankingYear[i], simphRankingMonth[i], simphRankingDay[i]);
			printFontGrid(20, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%02d:%02d:%02d", simphRankingHour[i], simphRankingMinute[i], simphRankingSecond[i]);
			printFontGrid(31, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// スピードデータ
			sprintf(string[0], "SPEED:%d", simphRankingSpeed[cursor]);
			printFontGrid(1, 24, string[0], 0);
			
			if(simphRankingSpType[cursor] == 0) sprintf(string[0], "(1/60)");
			if(simphRankingSpType[cursor] == 1) sprintf(string[0], "(FRAMES PER ROW)");
			if(simphRankingSpType[cursor] == 2) sprintf(string[0], "(1/256)");
			printFontGrid(11, 24, string[0], 0);
			
			sprintf(string[0], "W1:%2d W2:%2d W3:%2d WT:%2d W4:%2d W5:%2d",
			        simphRankingWait1[cursor], simphRankingWait2[cursor], simphRankingWait3[cursor], simphRankingWaitt[cursor],
			        simphRankingWait4[cursor], simphRankingWait5[cursor]);
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
				simphInitRanking();
				simphSaveRanking(player);
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
