//ACE-ANOTHER
//prefix:acea

// LITE版ベース

// レベルアップテーブル LV01,02,03,04,05,06,07,08,09,10,11,12,13,14,15
int aceaWait1Table[15] = {18,14,14,14,12,12,10, 8, 7, 6, 6, 6, 6, 6, 6};	// 固定→次
int aceaWait2Table[15] = {14, 8, 8, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4};	// ブロック消去
int aceaWait3Table[15] = {28,24,22,20,18,14,14,13,13,13,13,13,13,13,13};	// 接地→固定
int aceaWaittTable[15] = {10,10, 9, 9, 9, 8, 8, 7, 7, 7, 7, 7, 7, 7, 7};	// 横溜め

// BGM関連
int aceaBgm = 0;								// 現在のBGM番号
int aceaBgmListTable[3]   = {5, 3, 4};			// 使用するBGM
int aceaBgmFadeTable[3]   = {35, 95, 145};		// BGMがフェードアウトするライン
int aceaBgmChangeTable[3] = {40, 100, 10000};	// BGMを切り替えるライン

// 変数
int aceaModeNo = -1;		// モード番号
int aceaLines[2];			// ライン
int aceaLevel[2];			// レベル
int aceaTimer[2];			// 制限時間

// 設定
int aceaIsBig = 0;			// BIGかどうか
int aceaBigMove = 1;		// BIG時の横移動単位
int aceaStartLevel = 0;		// スタート時のレベル

// ランキング用変数
int aceaRankingTime[20];	// タイム
int aceaRankingLines[20];	// ライン
int aceaRankingYear[20];	// ランクイン日時（年）
int aceaRankingMonth[20];	// ランクイン日時（月）
int aceaRankingDay[20];		// ランクイン日時（日）
int aceaRankingHour[20];	// ランクイン日時（時）
int aceaRankingMinute[20];	// ランクイン日時（分）
int aceaRankingSecond[20];	// ランクイン日時（秒）

// イベント発生
void aceaPluginEvent(int player, int event, int *param) {
	int i;
	
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != aceaModeNo)) return;
	
	if(event == 0) {
		// モードを登録する
		aceaModeNo = addModePlugin("ACE-ANOTHER");
	} else if(event == 7) {
		timeOn[player] = 1;	// ブロック出現と同時にタイマー再開
	} else if(event == 12) {
		aceaLineErase(player, param[0]);	// ライン消去
	} else if(event == 15) {
		aceaViewScore(player);	// スコア表示
	} else if(event == 17) {
		aceaSetting(player, param);	// 設定画面
	} else if(event == 18) {
		aceaPlayerInitial(player);	// 初期化
	} else if(event == 21) {
		aceaResult(player);	// 結果表示
	} else if(event == 24) {
		ending[player] = 3;	// エンディング突入
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		aceaExcellent(player, param);	// EXCELLENT画面
	} else if(event == 28) {
		aceaIncrementTime(player);	// 時間を進める
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		aceaSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		aceaLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		aceaLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		aceaReplayDetail(param[0]);	// リプレイ詳細
	}
}

// 初期化
void aceaPlayerInitial(int player) {
	// 枠の色を灰色にする
	framecolor[player] = 5;
	frame_decoration[player] = 1;
	
	// 変数を初期化
	aceaLines[player] = aceaStartLevel * 10;
	aceaLevel[player] = aceaStartLevel;
	backno = aceaStartLevel;
	
	// 初期BGMを設定
	aceaBgm = 0;
	while(aceaLines[player] >= aceaBgmChangeTable[aceaBgm]) aceaBgm++;
	bgmlv = aceaBgmListTable[aceaBgm];
	
	// 初期スピードを設定
	sp[player] = 1200;
	wait1[player] = aceaWait1Table[aceaLevel[player]];
	wait2[player] = aceaWait2Table[aceaLevel[player]];
	wait3[player] = aceaWait3Table[aceaLevel[player]];
	waitt[player] = aceaWaittTable[aceaLevel[player]];
	aceaTimer[player] = 3600;
	
	// 設定を反映させる
	IsBig[player] = aceaIsBig;
	BigMove[player] = aceaBigMove;
}

// ライン消去
void aceaLineErase(int player, int lines) {
	// ライン数加算
	aceaLines[player] = aceaLines[player] + lines;
	
	// 全消し
	if(isBravo(player)) {
		PlaySE(se_levelup);
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
	}
	
	// BGMフェードアウト
	if((aceaLines[player] >= aceaBgmFadeTable[aceaBgm]) && (aceaLines[player] < aceaBgmChangeTable[aceaBgm]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// エンディング
	if(aceaLines[player] >= 150) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		aceaLines[player] = 150;
		ending[player] = 1;
	}
	// レベルアップ
	else if(aceaLines[player] >= (aceaLevel[player] + 1) * 10) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		// スピードアップ
		aceaLevel[player]++;
		wait1[player] = aceaWait1Table[aceaLevel[player]];
		wait2[player] = aceaWait2Table[aceaLevel[player]];
		wait3[player] = aceaWait3Table[aceaLevel[player]];
		waitt[player] = aceaWaittTable[aceaLevel[player]];
		aceaTimer[player] = 3600;
		
		// 背景切り替え
		bgfadesw = 1;
		bgfadebg = aceaLevel[player];
		
		// 音楽切り替え
		if(aceaLines[player] >= aceaBgmChangeTable[aceaBgm]) {
			aceaBgm++;
			bgmlv = aceaBgmListTable[aceaBgm];
			PlayBGM();
		}
	}
}

// スコア表示
void aceaViewScore(int player) {
	int color, color2;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// レベル
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "LEVEL");
	sprintf(string[0], "%d", aceaLevel[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// トータルタイム
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "TOTAL TIME");
	getTime(gameTimer[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// ベストタイム
	if((!playback) && (!IsBig[player]) && (!aceaStartLevel)) {
		printTinyFont(foffset[player] + 96, fyoffset[player] + 76, "BEST TIME");
		if(aceaRankingLines[0] >= 150) getTime(aceaRankingTime[0]);
		else getTime(0);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 84, string[0], color);
	}
	
	// ノルマ（分子）
	ExBltRect(sg_smallfont, foffset[player] + 107, fyoffset[player] + 161, 0, 14, 22, 7);
	sprintf(string[0], "%4d", aceaLines[player]);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 169, string[0], color);
	
	// ノルマ（横線）
	ExBltRect(sg_spr, foffset[player] + 105, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 106, fyoffset[player] + 181, 22, 143, 22, 1);
	
	// ノルマ（分母）
	if(ending[player]) sprintf(string[0], "%4d", aceaLines[player]);
	else sprintf(string[0], "%4d", (aceaLevel[player] + 1) * 10);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 185, string[0], color);
	
	// 残り時間
	if((aceaTimer[player] <= 60 * 10) && (timeOn[player])) color2 = 2;
	else color2 = color;
	getTime(aceaTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
}

// EXCELLENT画面
void aceaExcellent(int player, int *param) {
	param[0] = 3;
	onRecord[player] = 0;
	
	// 花火
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// 時間を進める
void aceaIncrementTime(int player) {
	int i;
	
	if(timeOn[player]) {
		// 制限時間減少
		aceaTimer[player]--;
		
		// 時間切れ
		if(aceaTimer[player] <= 0) {
			PlaySE(se_timeover);
			aceaTimer[player] = 0;
			
			timeOn[player] = 0;
			onRecord[player] = 0;
			
			stat[player] = 7;
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		}
		// 残り10秒
		else if(aceaTimer[player] == 10 * 60) {
			PlaySE(se_hurryup);
		}
	}
}

// BGM読み込み
void aceaLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 3; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/3)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(aceaBgmListTable[i]);
		}
	}
}

// 結果表示
void aceaResult(int player) {
	// ランキング登録
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = aceaRegistRanking(player);
		if(statc[player * 10 + 1] != -1) aceaSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", aceaLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", aceaLevel[player] + 1);
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

// 設定画面
void aceaSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(aceaLoadConfig() == 0) aceaSaveConfig();
	
	// ランキングを読み込み
	if(aceaLoadRanking(player) == 0) aceaInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE-ANOTHER OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",         7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",    7 * (cursor == 1));
		printFontGrid(2, 5, "START LEVEL", 7 * (cursor == 2));
		
		// 設定値表示
		if(!aceaIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!aceaBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "LV%d", aceaStartLevel + 1);
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		// カーソル移動
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 2;
			if(cursor > 2) cursor = 0;
		}
		
		// 値を変更
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			if(cursor == 0) aceaIsBig = !aceaIsBig;
			if(cursor == 1) aceaBigMove = !aceaBigMove;
			if(cursor == 2) {
				aceaStartLevel = aceaStartLevel + move;
				if(aceaStartLevel < 0) aceaStartLevel = 14;
				if(aceaStartLevel > 14) aceaStartLevel = 0;
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
			aceaSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			aceaViewRanking(player);
		}
	}
}

// リプレイ保存
void aceaSaveReplay(int player) {
	saveBuf[900] = aceaIsBig;
	saveBuf[901] = aceaBigMove;
	saveBuf[902] = aceaLines[player];
	saveBuf[903] = aceaLevel[player];
	saveBuf[904] = aceaStartLevel;
}

// リプレイ読み込み
void aceaLoadReplay(int player) {
	aceaIsBig = saveBuf[900];
	aceaBigMove = saveBuf[901];
	aceaStartLevel = saveBuf[904];
	
	aceaPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void aceaReplayDetail(int number) {
	printFontGrid(1, 4, "LINES", 0);
	sprintf(string[0], "%d", saveBuf[902]);
	printFontGrid(22, 4, string[0], 0);
	
	printFontGrid(1, 5, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[903] + 1);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 7, "BIG", 0);
	if(!saveBuf[900]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 8, "BIG MOVE", 0);
	if(!saveBuf[901]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "START LEVEL", 0);
	sprintf(string[0], "LV%d", saveBuf[904] + 1);
	printFontGrid(22, 9, string[0], 0);
}

// 設定を保存
void aceaSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x41454341;
	saveBuf[3] = 0x31726576;
	
	// 設定内容
	saveBuf[4] = aceaIsBig;
	saveBuf[5] = aceaBigMove;
	saveBuf[6] = aceaStartLevel;
	
	SaveFile("config/ACE_ANOTHER_CONFIG.SAV", &saveBuf, 100 * 4);
}

// 設定を読み込み
int aceaLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/ACE_ANOTHER_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x41454341) return 0;
	if(saveBuf[3] != 0x31726576) return 0;
	
	// 設定内容
	aceaIsBig = saveBuf[4];
	aceaBigMove = saveBuf[5];
	aceaStartLevel = saveBuf[6];
	
	return 1;
}

// ランキング保存
void aceaSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		saveBuf[1 + (i * 10) + 0] = aceaRankingTime[i];
		saveBuf[1 + (i * 10) + 1] = aceaRankingLines[i];
		saveBuf[1 + (i * 10) + 2] = aceaRankingYear[i];
		saveBuf[1 + (i * 10) + 3] = aceaRankingMonth[i];
		saveBuf[1 + (i * 10) + 4] = aceaRankingDay[i];
		saveBuf[1 + (i * 10) + 5] = aceaRankingHour[i];
		saveBuf[1 + (i * 10) + 6] = aceaRankingMinute[i];
		saveBuf[1 + (i * 10) + 7] = aceaRankingSecond[i];
	}
	
	sprintf(string[0], "config/ACE_ANOTHER_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 211 * 4);
}

// ランキング読み込み
int aceaLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/ACE_ANOTHER_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 211 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		aceaRankingTime[i]   = saveBuf[1 + (i * 10) + 0];
		aceaRankingLines[i]  = saveBuf[1 + (i * 10) + 1];
		aceaRankingYear[i]   = saveBuf[1 + (i * 10) + 2];
		aceaRankingMonth[i]  = saveBuf[1 + (i * 10) + 3];
		aceaRankingDay[i]    = saveBuf[1 + (i * 10) + 4];
		aceaRankingHour[i]   = saveBuf[1 + (i * 10) + 5];
		aceaRankingMinute[i] = saveBuf[1 + (i * 10) + 6];
		aceaRankingSecond[i] = saveBuf[1 + (i * 10) + 7];
	}
}

// ランキング初期化
void aceaInitRanking() {
	int i;
	
	for(i = 0; i < 20; i++) {
		aceaRankingTime[i] = 0;
		aceaRankingLines[i] = 0;
		aceaRankingYear[i] = 0;
		aceaRankingMonth[i] = 0;
		aceaRankingDay[i] = 0;
		aceaRankingHour[i] = 0;
		aceaRankingMinute[i] = 0;
		aceaRankingSecond[i] = 0;
	}
}

// ランキング登録
int aceaRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (aceaStartLevel)) return -1;
	
	for(i = 0; i < 20; i++) {
		// ランクイン
		if((aceaLines[player] > aceaRankingLines[i]) || 
		   ((aceaLines[player] == aceaRankingLines[i]) && (gameTimer[player] < aceaRankingTime[i])))
		{
			// ランキングをずらす
			for(j = 19; j > i; j--) {
				aceaRankingTime[j]   = aceaRankingTime[j - 1];
				aceaRankingLines[j]  = aceaRankingLines[j - 1];
				aceaRankingYear[j]   = aceaRankingYear[j - 1];
				aceaRankingMonth[j]  = aceaRankingMonth[j - 1];
				aceaRankingDay[j]    = aceaRankingDay[j - 1];
				aceaRankingHour[j]   = aceaRankingHour[j - 1];
				aceaRankingMinute[j] = aceaRankingMinute[j - 1];
				aceaRankingSecond[j] = aceaRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			aceaRankingTime[i]   = gameTimer[player];
			aceaRankingLines[i]  = aceaLines[player];
			
			GetDateAndTime(&timebuf);
			aceaRankingYear[i]   = timebuf[0];
			aceaRankingMonth[i]  = timebuf[1];
			aceaRankingDay[i]    = timebuf[2];
			aceaRankingHour[i]   = timebuf[4];
			aceaRankingMinute[i] = timebuf[5];
			aceaRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void aceaViewRanking(int player) {
	int i, erasemode;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE-ANOTHER MODE RANKING", 6);
		printFontGrid(1, 3, "RANK LINE TIME     DATE", 4);
		
		for(i = 0; i < 20; i++) {
			if(aceaRankingLines[i] >= 150) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, 2, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 0);
			
			sprintf(string[0], "%d", aceaRankingLines[i]);
			printFontGrid(6, 4 + i, string[0], 0);
			
			getTime(aceaRankingTime[i]);
			printFontGrid(11, 4 + i, string[0], 0);
			
			sprintf(string[0], "%04d/%02d/%02d", aceaRankingYear[i], aceaRankingMonth[i], aceaRankingDay[i]);
			printFontGrid(20, 4 + i, string[0], 0);
			
			sprintf(string[0], "%02d:%02d:%02d", aceaRankingHour[i], aceaRankingMinute[i], aceaRankingSecond[i]);
			printFontGrid(31, 4 + i, string[0], 0);
		}
		
		if(!erasemode) {
			printFontGrid(1, 27, "A/B:EXIT F:ERASE ALL", 6);
			
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
			printFontGrid(1, 25, "ERASE ALL RECORDS?", 2);
			printFontGrid(1, 27, "A:YES / B:NO", 2);
			
			// 消去
			if(getPushState(player, 4)) {
				PlayWave(se_kettei);
				aceaInitRanking();
				aceaSaveRanking(player);
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
