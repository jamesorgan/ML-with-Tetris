//ACE-HI SPEED 1
//prefix:ahsp1

// レベルアップテーブル
int ahsp1LevelTable[15] =
{
	20, 30, 60, 120, 180, 240, 300, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200
};

// BGM関連
int ahsp1Bgm = 0;								// 現在のBGM番号
int ahsp1BgmListTable[3] = {0, 2, 5};			// 使用するBGM
int ahsp1BgmFadeTable[3] = {45, 95, 145};		// フェードアウトするライン
int ahsp1BgmChangeTable[3] = {50, 100, 10000};	// BGMを切り替えるライン

// 変数
int ahsp1ModeNo = -1;		// モード番号
int ahsp1Lines[2];			// ライン
int ahsp1Level[2];			// レベル
int ahsp1Timer[2];			// 制限時間

// 設定
int ahsp1IsBig = 0;			// BIGかどうか
int ahsp1BigMove = 1;		// BIG時の横移動単位
int ahsp1Ghost = 1;			// ゴーストの有無
int ahsp1StartLevel = 0;	// スタート時のレベル

// ランキング用変数
int ahsp1RankingTime[20];	// タイム
int ahsp1RankingLines[20];	// ライン
int ahsp1RankingYear[20];	// ランクイン日時（年）
int ahsp1RankingMonth[20];	// ランクイン日時（月）
int ahsp1RankingDay[20];	// ランクイン日時（日）
int ahsp1RankingHour[20];	// ランクイン日時（時）
int ahsp1RankingMinute[20];	// ランクイン日時（分）
int ahsp1RankingSecond[20];	// ランクイン日時（秒）

// イベント発生
void ahsp1PluginEvent(int player, int event, int *param) {
	int i;
	
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != ahsp1ModeNo)) return;
	
	if(event == 0) {
		// モードを登録する
		ahsp1ModeNo = addModePlugin("ACE-HI SPEED 1");
	} else if(event == 7) {
		timeOn[player] = 1;	// ブロック出現と同時にタイマー再開
	} else if(event == 12) {
		ahsp1LineErase(player, param[0]);	// ライン消去
	} else if(event == 15) {
		ahsp1ViewScore(player);	// スコア表示
	} else if(event == 17) {
		ahsp1Setting(player, param);	// 設定画面
	} else if(event == 18) {
		ahsp1PlayerInitial(player);	// 初期化
	} else if(event == 21) {
		ahsp1Result(player);	// 結果表示
	} else if(event == 24) {
		ending[player] = 3;	// エンディング突入
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		ahsp1Excellent(player, param);	// EXCELLENT画面
	} else if(event == 28) {
		ahsp1IncrementTime(player);	// 時間を進める
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		ahsp1SaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		ahsp1LoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		ahsp1LoadBGM();	// BGM読み込み
	} else if(event == 55) {
		ahsp1ReplayDetail(param[0]);	// リプレイ詳細
	}
}

// 初期化
void ahsp1PlayerInitial(int player) {
	// 枠の色を灰色にする
	framecolor[player] = 5;
	frame_decoration[player] = 1;
	
	// 変数を初期化
	ahsp1Lines[player] = ahsp1StartLevel * 10;
	ahsp1Level[player] = ahsp1StartLevel;
	backno = ahsp1StartLevel;
	
	// 初期BGMを設定
	ahsp1Bgm = 0;
	while(ahsp1Lines[player] >= ahsp1BgmChangeTable[ahsp1Bgm]) ahsp1Bgm++;
	bgmlv = ahsp1BgmListTable[ahsp1Bgm];
	
	// 初期スピードを設定
	sp[player] = ahsp1LevelTable[ahsp1Level[player]];
	ahsp1Timer[player] = 3600;
	
	// 設定を反映させる
	IsBig[player] = ahsp1IsBig;
	BigMove[player] = ahsp1BigMove;
	if(ahsp1Ghost == 0) ghost[player] = 0;
}

// ライン消去
void ahsp1LineErase(int player, int lines) {
	// ライン数加算
	ahsp1Lines[player] = ahsp1Lines[player] + lines;
	
	// 全消し
	if(isBravo(player)) {
		PlaySE(se_levelup);
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
	}
	
	// BGMフェードアウト
	if((ahsp1Lines[player] >= ahsp1BgmFadeTable[ahsp1Bgm]) && (ahsp1Lines[player] < ahsp1BgmChangeTable[ahsp1Bgm]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// エンディング
	if(ahsp1Lines[player] >= 150) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		ahsp1Lines[player] = 150;
		ending[player] = 1;
	}
	// レベルアップ
	else if(ahsp1Lines[player] >= (ahsp1Level[player] + 1) * 10) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		// スピードアップ
		ahsp1Level[player]++;
		sp[player] = ahsp1LevelTable[ahsp1Level[player]];
		ahsp1Timer[player] = 3600;
		
		// 背景切り替え
		bgfadesw = 1;
		bgfadebg = ahsp1Level[player];
		
		// 音楽切り替え
		if(ahsp1Lines[player] >= ahsp1BgmChangeTable[ahsp1Bgm]) {
			ahsp1Bgm++;
			bgmlv = ahsp1BgmListTable[ahsp1Bgm];
			PlayBGM();
		}
	}
}

// スコア表示
void ahsp1ViewScore(int player) {
	int color, color2;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// レベル
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "LEVEL");
	sprintf(string[0], "%d", ahsp1Level[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// トータルタイム
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "TOTAL TIME");
	getTime(gameTimer[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// ベストタイム
	if((!playback) && (!IsBig[player]) && (!ahsp1StartLevel)) {
		printTinyFont(foffset[player] + 96, fyoffset[player] + 76, "BEST TIME");
		if(ahsp1RankingLines[0] >= 150) getTime(ahsp1RankingTime[0]);
		else getTime(0);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 84, string[0], color);
	}
	
	// ノルマ（分子）
	ExBltRect(sg_smallfont, foffset[player] + 107, fyoffset[player] + 161, 0, 14, 22, 7);
	sprintf(string[0], "%4d", ahsp1Lines[player]);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 169, string[0], color);
	
	// ノルマ（横線）
	ExBltRect(sg_spr, foffset[player] + 105, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 106, fyoffset[player] + 181, 22, 143, 22, 1);
	
	// ノルマ（分母）
	if(ending[player]) sprintf(string[0], "%4d", ahsp1Lines[player]);
	else sprintf(string[0], "%4d", (ahsp1Level[player] + 1) * 10);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 185, string[0], color);
	
	// 残り時間
	if((ahsp1Timer[player] <= 60 * 10) && (timeOn[player])) color2 = 2;
	else color2 = color;
	getTime(ahsp1Timer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
}

// EXCELLENT画面
void ahsp1Excellent(int player, int *param) {
	param[0] = 3;
	onRecord[player] = 0;
	
	// 花火
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// 時間を進める
void ahsp1IncrementTime(int player) {
	int i;
	
	if(timeOn[player]) {
		// 制限時間減少
		ahsp1Timer[player]--;
		
		// 時間切れ
		if(ahsp1Timer[player] <= 0) {
			PlaySE(se_timeover);
			ahsp1Timer[player] = 0;
			
			timeOn[player] = 0;
			onRecord[player] = 0;
			
			stat[player] = 7;
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		}
		// 残り10秒
		else if(ahsp1Timer[player] == 10 * 60) {
			PlaySE(se_hurryup);
		}
	}
}

// BGM読み込み
void ahsp1LoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 3; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/3)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(ahsp1BgmListTable[i]);
		}
	}
}

// 結果表示
void ahsp1Result(int player) {
	// ランキング登録
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = ahsp1RegistRanking(player);
		if(statc[player * 10 + 1] != -1) ahsp1SaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", ahsp1Lines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", ahsp1Level[player] + 1);
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
void ahsp1Setting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(ahsp1LoadConfig() == 0) ahsp1SaveConfig();
	
	// ランキングを読み込み
	if(ahsp1LoadRanking(player) == 0) ahsp1InitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE-HI SPEED 1 OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",         7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",    7 * (cursor == 1));
		printFontGrid(2, 5, "GHOST BLOCK", 7 * (cursor == 2));
		printFontGrid(2, 6, "START LEVEL", 7 * (cursor == 3));
		
		// 設定値表示
		if(!ahsp1IsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!ahsp1BigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!ahsp1Ghost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "LV%d", ahsp1StartLevel + 1);
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		// カーソル移動
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 3;
			if(cursor > 3) cursor = 0;
		}
		
		// 値を変更
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			if(cursor == 0) ahsp1IsBig = !ahsp1IsBig;
			if(cursor == 1) ahsp1BigMove = !ahsp1BigMove;
			if(cursor == 2) ahsp1Ghost = !ahsp1Ghost;
			if(cursor == 3) {
				ahsp1StartLevel = ahsp1StartLevel + move;
				if(ahsp1StartLevel < 0) ahsp1StartLevel = 14;
				if(ahsp1StartLevel > 14) ahsp1StartLevel = 0;
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
			ahsp1SaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			ahsp1ViewRanking(player);
		}
	}
}

// リプレイ保存
void ahsp1SaveReplay(int player) {
	saveBuf[900] = ahsp1IsBig;
	saveBuf[901] = ahsp1BigMove;
	saveBuf[902] = ahsp1Lines[player];
	saveBuf[903] = ahsp1Level[player];
	saveBuf[904] = ahsp1Ghost;
	saveBuf[905] = ahsp1StartLevel;
}

// リプレイ読み込み
void ahsp1LoadReplay(int player) {
	ahsp1IsBig = saveBuf[900];
	ahsp1BigMove = saveBuf[901];
	ahsp1Ghost = saveBuf[904];
	ahsp1StartLevel = saveBuf[905];
	
	ahsp1PlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void ahsp1ReplayDetail(int number) {
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
	
	printFontGrid(1, 9, "GHOST BLOCK", 0);
	if(!saveBuf[904]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "START LEVEL", 0);
	sprintf(string[0], "LV%d", saveBuf[905] + 1);
	printFontGrid(22, 10, string[0], 0);
}

// 設定を保存
void ahsp1SaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x48454341;
	saveBuf[3] = 0x31763153;
	
	// 設定内容
	saveBuf[4] = ahsp1IsBig;
	saveBuf[5] = ahsp1BigMove;
	saveBuf[6] = ahsp1Ghost;
	saveBuf[7] = ahsp1StartLevel;
	
	SaveFile("config/ACE_HI_SPEED_1_CONFIG.SAV", &saveBuf, 100 * 4);
}

// 設定を読み込み
int ahsp1LoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/ACE_HI_SPEED_1_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x48454341) return 0;
	if(saveBuf[3] != 0x31763153) return 0;
	
	// 設定内容
	ahsp1IsBig = saveBuf[4];
	ahsp1BigMove = saveBuf[5];
	ahsp1Ghost = saveBuf[6];
	ahsp1StartLevel = saveBuf[7];
	
	return 1;
}

// ランキング保存
void ahsp1SaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		saveBuf[1 + (i * 10) + 0] = ahsp1RankingTime[i];
		saveBuf[1 + (i * 10) + 1] = ahsp1RankingLines[i];
		saveBuf[1 + (i * 10) + 2] = ahsp1RankingYear[i];
		saveBuf[1 + (i * 10) + 3] = ahsp1RankingMonth[i];
		saveBuf[1 + (i * 10) + 4] = ahsp1RankingDay[i];
		saveBuf[1 + (i * 10) + 5] = ahsp1RankingHour[i];
		saveBuf[1 + (i * 10) + 6] = ahsp1RankingMinute[i];
		saveBuf[1 + (i * 10) + 7] = ahsp1RankingSecond[i];
	}
	
	sprintf(string[0], "config/ACE_HI_SPEED_1_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 211 * 4);
}

// ランキング読み込み
int ahsp1LoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/ACE_HI_SPEED_1_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 211 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		ahsp1RankingTime[i]   = saveBuf[1 + (i * 10) + 0];
		ahsp1RankingLines[i]  = saveBuf[1 + (i * 10) + 1];
		ahsp1RankingYear[i]   = saveBuf[1 + (i * 10) + 2];
		ahsp1RankingMonth[i]  = saveBuf[1 + (i * 10) + 3];
		ahsp1RankingDay[i]    = saveBuf[1 + (i * 10) + 4];
		ahsp1RankingHour[i]   = saveBuf[1 + (i * 10) + 5];
		ahsp1RankingMinute[i] = saveBuf[1 + (i * 10) + 6];
		ahsp1RankingSecond[i] = saveBuf[1 + (i * 10) + 7];
	}
}

// ランキング初期化
void ahsp1InitRanking() {
	int i;
	
	for(i = 0; i < 20; i++) {
		ahsp1RankingTime[i] = 0;
		ahsp1RankingLines[i] = 0;
		ahsp1RankingYear[i] = 0;
		ahsp1RankingMonth[i] = 0;
		ahsp1RankingDay[i] = 0;
		ahsp1RankingHour[i] = 0;
		ahsp1RankingMinute[i] = 0;
		ahsp1RankingSecond[i] = 0;
	}
}

// ランキング登録
int ahsp1RegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (ahsp1StartLevel)) return -1;
	
	for(i = 0; i < 20; i++) {
		// ランクイン
		if((ahsp1Lines[player] > ahsp1RankingLines[i]) || 
		   ((ahsp1Lines[player] == ahsp1RankingLines[i]) && (gameTimer[player] < ahsp1RankingTime[i])))
		{
			// ランキングをずらす
			for(j = 19; j > i; j--) {
				ahsp1RankingTime[j]   = ahsp1RankingTime[j - 1];
				ahsp1RankingLines[j]  = ahsp1RankingLines[j - 1];
				ahsp1RankingYear[j]   = ahsp1RankingYear[j - 1];
				ahsp1RankingMonth[j]  = ahsp1RankingMonth[j - 1];
				ahsp1RankingDay[j]    = ahsp1RankingDay[j - 1];
				ahsp1RankingHour[j]   = ahsp1RankingHour[j - 1];
				ahsp1RankingMinute[j] = ahsp1RankingMinute[j - 1];
				ahsp1RankingSecond[j] = ahsp1RankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			ahsp1RankingTime[i]   = gameTimer[player];
			ahsp1RankingLines[i]  = ahsp1Lines[player];
			
			GetDateAndTime(&timebuf);
			ahsp1RankingYear[i]   = timebuf[0];
			ahsp1RankingMonth[i]  = timebuf[1];
			ahsp1RankingDay[i]    = timebuf[2];
			ahsp1RankingHour[i]   = timebuf[4];
			ahsp1RankingMinute[i] = timebuf[5];
			ahsp1RankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void ahsp1ViewRanking(int player) {
	int i, erasemode;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE-HI SPEED 1 MODE RANKING", 6);
		printFontGrid(1, 3, "RANK LINE TIME     DATE", 4);
		
		for(i = 0; i < 20; i++) {
			if(ahsp1RankingLines[i] >= 150) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, 2, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 0);
			
			sprintf(string[0], "%d", ahsp1RankingLines[i]);
			printFontGrid(6, 4 + i, string[0], 0);
			
			getTime(ahsp1RankingTime[i]);
			printFontGrid(11, 4 + i, string[0], 0);
			
			sprintf(string[0], "%04d/%02d/%02d", ahsp1RankingYear[i], ahsp1RankingMonth[i], ahsp1RankingDay[i]);
			printFontGrid(20, 4 + i, string[0], 0);
			
			sprintf(string[0], "%02d:%02d:%02d", ahsp1RankingHour[i], ahsp1RankingMinute[i], ahsp1RankingSecond[i]);
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
				ahsp1InitRanking();
				ahsp1SaveRanking(player);
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
