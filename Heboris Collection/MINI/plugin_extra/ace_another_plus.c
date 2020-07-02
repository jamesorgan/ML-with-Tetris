//ACE-ANOTHER+
//prefix:aceap

// C7版ベース

// レベルアップテーブル  LV01,02,03,04,05,06,07,08,09,10,11,12,13,14,15
int aceapWait1Table[15] = {18,14,14,14,12,12,10, 8, 7, 6, 5, 5, 4, 3, 2};	// 固定→次
int aceapWait2Table[15] = {14, 8, 8, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 3};	// ブロック消去
int aceapWait3Table[15] = {28,24,22,20,18,14,14,13,13,13,12,12,12,12,11};	// 接地→固定
int aceapWaittTable[15] = {10,10, 9, 9, 9, 8, 8, 7, 7, 7, 7, 7, 7, 7, 7};	// 横溜め

// レベルごとの制限時間
int aceapTimeLimit[15] =
{
	3600, 3600, 3600, 3600, 3600, 3600, 3600, 3300, 3000, 2700, 2400, 2100, 1800, 1500, 1000
};

// BGM関連
int aceapBgm = 0;								// 現在のBGM番号
int aceapBgmListTable[3] = {5, 3, 4};			// 使用するBGM
int aceapBgmFadeTable[3] = {35, 95, 145};		// BGMがフェードアウトするライン
int aceapBgmChangeTable[3] = {40, 100, 10000};	// BGMを切り替えるライン

// 変数
int aceapModeNo = -1;		// モード番号
int aceapLines[2];			// ライン
int aceapLevel[2];			// レベル
int aceapTimer[2];			// 制限時間

// 設定
int aceapIsBig = 0;			// BIGかどうか
int aceapBigMove = 1;		// BIG時の横移動単位
int aceapStartLevel = 0;	// スタート時のレベル

// ランキング用変数
int aceapRankingTime[20];	// タイム
int aceapRankingLines[20];	// ライン
int aceapRankingYear[20];	// ランクイン日時（年）
int aceapRankingMonth[20];	// ランクイン日時（月）
int aceapRankingDay[20];	// ランクイン日時（日）
int aceapRankingHour[20];	// ランクイン日時（時）
int aceapRankingMinute[20];	// ランクイン日時（分）
int aceapRankingSecond[20];	// ランクイン日時（秒）

// イベント発生
void aceapPluginEvent(int player, int event, int *param) {
	int i;
	
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != aceapModeNo)) return;
	
	if(event == 0) {
		// モードを登録する
		aceapModeNo = addModePlugin("ACE-ANOTHER+");
	} else if(event == 7) {
		timeOn[player] = 1;	// ブロック出現と同時にタイマー再開
	} else if(event == 12) {
		aceapLineErase(player, param[0]);	// ライン消去
	} else if(event == 15) {
		aceapViewScore(player);	// スコア表示
	} else if(event == 17) {
		aceapSetting(player, param);	// 設定画面
	} else if(event == 18) {
		aceapPlayerInitial(player);	// 初期化
	} else if(event == 21) {
		aceapResult(player);	// 結果表示
	} else if(event == 24) {
		ending[player] = 3;	// エンディング突入
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		aceapExcellent(player, param);	// EXCELLENT画面
	} else if(event == 28) {
		aceapIncrementTime(player);	// 時間を進める
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		aceapSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		aceapLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		aceapLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		aceapReplayDetail(param[0]);	// リプレイ詳細
	}
}

// 初期化
void aceapPlayerInitial(int player) {
	// 枠の色を灰色にする
	framecolor[player] = 5;
	frame_decoration[player] = 1;
	
	// 変数を初期化
	aceapLines[player] = aceapStartLevel * 10;
	aceapLevel[player] = aceapStartLevel;
	backno = aceapStartLevel;
	
	// 初期BGMを設定
	aceapBgm = 0;
	while(aceapLines[player] >= aceapBgmChangeTable[aceapBgm]) aceapBgm++;
	bgmlv = aceapBgmListTable[aceapBgm];
	
	// 初期スピードを設定
	sp[player] = 1200;
	wait1[player] = aceapWait1Table[aceapLevel[player]];
	wait2[player] = aceapWait2Table[aceapLevel[player]];
	wait3[player] = aceapWait3Table[aceapLevel[player]];
	waitt[player] = aceapWaittTable[aceapLevel[player]];
	aceapTimer[player] = aceapTimeLimit[aceapLevel[player]];
	
	// 設定を反映させる
	IsBig[player] = aceapIsBig;
	BigMove[player] = aceapBigMove;
}

// ライン消去
void aceapLineErase(int player, int lines) {
	// ライン数加算
	aceapLines[player] = aceapLines[player] + lines;
	
	// 全消し
	if(isBravo(player)) {
		PlaySE(se_levelup);
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
	}
	
	// BGMフェードアウト
	if((aceapLines[player] >= aceapBgmFadeTable[aceapBgm]) && (aceapLines[player] < aceapBgmChangeTable[aceapBgm]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// エンディング
	if(aceapLines[player] >= 150) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		aceapLines[player] = 150;
		ending[player] = 1;
	}
	// レベルアップ
	else if(aceapLines[player] >= (aceapLevel[player] + 1) * 10) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		// スピードアップ
		aceapLevel[player]++;
		wait1[player] = aceapWait1Table[aceapLevel[player]];
		wait2[player] = aceapWait2Table[aceapLevel[player]];
		wait3[player] = aceapWait3Table[aceapLevel[player]];
		waitt[player] = aceapWaittTable[aceapLevel[player]];
		aceapTimer[player] = aceapTimeLimit[aceapLevel[player]];
		
		// 背景切り替え
		bgfadesw = 1;
		bgfadebg = aceapLevel[player];
		
		// 音楽切り替え
		if(aceapLines[player] >= aceapBgmChangeTable[aceapBgm]) {
			aceapBgm++;
			bgmlv = aceapBgmListTable[aceapBgm];
			PlayBGM();
		}
	}
}

// スコア表示
void aceapViewScore(int player) {
	int color, color2;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// レベル
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "LEVEL");
	sprintf(string[0], "%d", aceapLevel[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// トータルタイム
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "TOTAL TIME");
	getTime(gameTimer[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// ベストタイム
	if((!playback) && (!IsBig[player]) && (!aceapStartLevel)) {
		printTinyFont(foffset[player] + 96, fyoffset[player] + 76, "BEST TIME");
		if(aceapRankingLines[0] >= 150) getTime(aceapRankingTime[0]);
		else getTime(0);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 84, string[0], color);
	}
	
	// ノルマ（分子）
	ExBltRect(sg_smallfont, foffset[player] + 107, fyoffset[player] + 161, 0, 14, 22, 7);
	sprintf(string[0], "%4d", aceapLines[player]);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 169, string[0], color);
	
	// ノルマ（横線）
	ExBltRect(sg_spr, foffset[player] + 105, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 106, fyoffset[player] + 181, 22, 143, 22, 1);
	
	// ノルマ（分母）
	if(ending[player]) sprintf(string[0], "%4d", aceapLines[player]);
	else sprintf(string[0], "%4d", (aceapLevel[player] + 1) * 10);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 185, string[0], color);
	
	// 残り時間
	if((aceapTimer[player] <= 60 * 10) && (timeOn[player])) color2 = 2;
	else color2 = color;
	getTime(aceapTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
}

// EXCELLENT画面
void aceapExcellent(int player, int *param) {
	param[0] = 3;
	onRecord[player] = 0;
	
	// 花火
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// 時間を進める
void aceapIncrementTime(int player) {
	int i;
	
	if(timeOn[player]) {
		// 制限時間減少
		aceapTimer[player]--;
		
		// 時間切れ
		if(aceapTimer[player] <= 0) {
			PlaySE(se_timeover);
			aceapTimer[player] = 0;
			
			timeOn[player] = 0;
			onRecord[player] = 0;
			
			stat[player] = 7;
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		}
		// 残り10秒
		else if(aceapTimer[player] == 10 * 60) {
			PlaySE(se_hurryup);
		}
	}
}

// BGM読み込み
void aceapLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 3; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/3)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(aceapBgmListTable[i]);
		}
	}
}

// 結果表示
void aceapResult(int player) {
	// ランキング登録
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = aceapRegistRanking(player);
		if(statc[player * 10 + 1] != -1) aceapSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", aceapLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", aceapLevel[player] + 1);
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
void aceapSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(aceapLoadConfig() == 0) aceapSaveConfig();
	
	// ランキングを読み込み
	if(aceapLoadRanking(player) == 0) aceapInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE-ANOTHER+ OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",         7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",    7 * (cursor == 1));
		printFontGrid(2, 5, "START LEVEL", 7 * (cursor == 2));
		
		// 設定値表示
		if(!aceapIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!aceapBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "LV%d", aceapStartLevel + 1);
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
			if(cursor == 0) aceapIsBig = !aceapIsBig;
			if(cursor == 1) aceapBigMove = !aceapBigMove;
			if(cursor == 2) {
				aceapStartLevel = aceapStartLevel + move;
				if(aceapStartLevel < 0) aceapStartLevel = 14;
				if(aceapStartLevel > 14) aceapStartLevel = 0;
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
			aceapSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			aceapViewRanking(player);
		}
	}
}

// リプレイ保存
void aceapSaveReplay(int player) {
	saveBuf[900] = aceapIsBig;
	saveBuf[901] = aceapBigMove;
	saveBuf[902] = aceapLines[player];
	saveBuf[903] = aceapLevel[player];
	saveBuf[904] = aceapStartLevel;
}

// リプレイ読み込み
void aceapLoadReplay(int player) {
	aceapIsBig = saveBuf[900];
	aceapBigMove = saveBuf[901];
	aceapStartLevel = saveBuf[904];
	
	aceapPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void aceapReplayDetail(int number) {
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
void aceapSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x41454341;
	saveBuf[3] = 0x3165762B;
	
	// 設定内容
	saveBuf[4] = aceapIsBig;
	saveBuf[5] = aceapBigMove;
	saveBuf[6] = aceapStartLevel;
	
	SaveFile("config/ACE_ANOTHER_PLUS_CONFIG.SAV", &saveBuf, 100 * 4);
}

// 設定を読み込み
int aceapLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/ACE_ANOTHER_PLUS_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x41454341) return 0;
	if(saveBuf[3] != 0x3165762B) return 0;
	
	// 設定内容
	aceapIsBig = saveBuf[4];
	aceapBigMove = saveBuf[5];
	aceapStartLevel = saveBuf[6];
	
	return 1;
}

// ランキング保存
void aceapSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		saveBuf[1 + (i * 10) + 0] = aceapRankingTime[i];
		saveBuf[1 + (i * 10) + 1] = aceapRankingLines[i];
		saveBuf[1 + (i * 10) + 2] = aceapRankingYear[i];
		saveBuf[1 + (i * 10) + 3] = aceapRankingMonth[i];
		saveBuf[1 + (i * 10) + 4] = aceapRankingDay[i];
		saveBuf[1 + (i * 10) + 5] = aceapRankingHour[i];
		saveBuf[1 + (i * 10) + 6] = aceapRankingMinute[i];
		saveBuf[1 + (i * 10) + 7] = aceapRankingSecond[i];
	}
	
	sprintf(string[0], "config/ACE_ANOTHER_PLUS_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 211 * 4);
}

// ランキング読み込み
int aceapLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/ACE_ANOTHER_PLUS_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 211 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		aceapRankingTime[i]   = saveBuf[1 + (i * 10) + 0];
		aceapRankingLines[i]  = saveBuf[1 + (i * 10) + 1];
		aceapRankingYear[i]   = saveBuf[1 + (i * 10) + 2];
		aceapRankingMonth[i]  = saveBuf[1 + (i * 10) + 3];
		aceapRankingDay[i]    = saveBuf[1 + (i * 10) + 4];
		aceapRankingHour[i]   = saveBuf[1 + (i * 10) + 5];
		aceapRankingMinute[i] = saveBuf[1 + (i * 10) + 6];
		aceapRankingSecond[i] = saveBuf[1 + (i * 10) + 7];
	}
}

// ランキング初期化
void aceapInitRanking() {
	int i;
	
	for(i = 0; i < 20; i++) {
		aceapRankingTime[i] = 0;
		aceapRankingLines[i] = 0;
		aceapRankingYear[i] = 0;
		aceapRankingMonth[i] = 0;
		aceapRankingDay[i] = 0;
		aceapRankingHour[i] = 0;
		aceapRankingMinute[i] = 0;
		aceapRankingSecond[i] = 0;
	}
}

// ランキング登録
int aceapRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (aceapStartLevel)) return -1;
	
	for(i = 0; i < 20; i++) {
		// ランクイン
		if((aceapLines[player] > aceapRankingLines[i]) || 
		   ((aceapLines[player] == aceapRankingLines[i]) && (gameTimer[player] < aceapRankingTime[i])))
		{
			// ランキングをずらす
			for(j = 19; j > i; j--) {
				aceapRankingTime[j]   = aceapRankingTime[j - 1];
				aceapRankingLines[j]  = aceapRankingLines[j - 1];
				aceapRankingYear[j]   = aceapRankingYear[j - 1];
				aceapRankingMonth[j]  = aceapRankingMonth[j - 1];
				aceapRankingDay[j]    = aceapRankingDay[j - 1];
				aceapRankingHour[j]   = aceapRankingHour[j - 1];
				aceapRankingMinute[j] = aceapRankingMinute[j - 1];
				aceapRankingSecond[j] = aceapRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			aceapRankingTime[i]   = gameTimer[player];
			aceapRankingLines[i]  = aceapLines[player];
			
			GetDateAndTime(&timebuf);
			aceapRankingYear[i]   = timebuf[0];
			aceapRankingMonth[i]  = timebuf[1];
			aceapRankingDay[i]    = timebuf[2];
			aceapRankingHour[i]   = timebuf[4];
			aceapRankingMinute[i] = timebuf[5];
			aceapRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void aceapViewRanking(int player) {
	int i, erasemode;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE-ANOTHER+ MODE RANKING", 6);
		printFontGrid(1, 3, "RANK LINE TIME     DATE", 4);
		
		for(i = 0; i < 20; i++) {
			if(aceapRankingLines[i] >= 150) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, 2, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 0);
			
			sprintf(string[0], "%d", aceapRankingLines[i]);
			printFontGrid(6, 4 + i, string[0], 0);
			
			getTime(aceapRankingTime[i]);
			printFontGrid(11, 4 + i, string[0], 0);
			
			sprintf(string[0], "%04d/%02d/%02d", aceapRankingYear[i], aceapRankingMonth[i], aceapRankingDay[i]);
			printFontGrid(20, 4 + i, string[0], 0);
			
			sprintf(string[0], "%02d:%02d:%02d", aceapRankingHour[i], aceapRankingMinute[i], aceapRankingSecond[i]);
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
				aceapInitRanking();
				aceapSaveRanking(player);
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
