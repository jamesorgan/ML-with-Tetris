//ACE-NORMAL+
//prefix:acep

// レベルアップテーブル
int acepLevelTable[15] =
{
	1,10,20,30,60,100,130,160,190,220,240,300,1200,1200,1200
};

// BGM関連
int acepBgm = 0;								// 現在のBGM番号
int acepBgmListTable[3] = {0, 1, 2};			// 使用するBGM
int acepBgmFadeTable[3] = {45, 95, 145};		// フェードアウトするライン
int acepBgmChangeTable[3] = {50, 100, 10000};	// BGMを切り替えるライン

// 変数
int acepModeNo = -1;		// モード番号
int acepLines[2];			// ライン
int acepLevel[2];			// レベル
int acepTimer[2];			// 制限時間

// 設定
int acepIsBig = 0;			// BIGかどうか
int acepBigMove = 1;		// BIG時の横移動単位
int acepGhost = 1;			// ゴーストの有無
int acepStartLevel = 0;		// スタート時のレベル

// ランキング用変数
int acepRankingTime[20];	// タイム
int acepRankingLines[20];	// ライン
int acepRankingYear[20];	// ランクイン日時（年）
int acepRankingMonth[20];	// ランクイン日時（月）
int acepRankingDay[20];		// ランクイン日時（日）
int acepRankingHour[20];	// ランクイン日時（時）
int acepRankingMinute[20];	// ランクイン日時（分）
int acepRankingSecond[20];	// ランクイン日時（秒）

// イベント発生
void acepPluginEvent(int player, int event, int *param) {
	int i;
	
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != acepModeNo)) return;
	
	if(event == 0) {
		// モードを登録する
		acepModeNo = addModePlugin("ACE-NORMAL+");
	} else if(event == 7) {
		timeOn[player] = 1;	// ブロック出現と同時にタイマー再開
	} else if(event == 12) {
		acepLineErase(player, param[0]);	// ライン消去
	} else if(event == 15) {
		acepViewScore(player);	// スコア表示
	} else if(event == 17) {
		acepSetting(player, param);	// 設定画面
	} else if(event == 18) {
		acepPlayerInitial(player);	// 初期化
	} else if(event == 21) {
		acepResult(player);	// 結果表示
	} else if(event == 24) {
		ending[player] = 3;	// エンディング突入
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		acepExcellent(player, param);	// EXCELLENT画面
	} else if(event == 28) {
		acepIncrementTime(player);	// 時間を進める
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		acepSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		acepLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		acepLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		acepReplayDetail(param[0]);	// リプレイ詳細
	}
}

// 初期化
void acepPlayerInitial(int player) {
	// 枠の色を灰色にする
	framecolor[player] = 5;
	frame_decoration[player] = 1;
	
	// 変数を初期化
	acepLines[player] = acepStartLevel * 10;
	acepLevel[player] = acepStartLevel;
	backno = acepStartLevel;
	
	// 初期BGMを設定
	acepBgm = 0;
	while(acepLines[player] >= acepBgmChangeTable[acepBgm]) acepBgm++;
	bgmlv = acepBgmListTable[acepBgm];
	
	// 初期スピードを設定
	sp[player] = acepLevelTable[acepLevel[player]];
	acepTimer[player] = 5400;
	
	// 設定を反映させる
	IsBig[player] = acepIsBig;
	BigMove[player] = acepBigMove;
	if(acepGhost == 0) ghost[player] = 0;
}

// ライン消去
void acepLineErase(int player, int lines) {
	// ライン数加算
	acepLines[player] = acepLines[player] + lines;
	
	// 全消し
	if(isBravo(player)) {
		PlaySE(se_levelup);
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
	}
	
	// BGMフェードアウト
	if((acepLines[player] >= acepBgmFadeTable[acepBgm]) && (acepLines[player] < acepBgmChangeTable[acepBgm]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// エンディング
	if(acepLines[player] >= 150) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		acepLines[player] = 150;
		ending[player] = 1;
	}
	// レベルアップ
	else if(acepLines[player] >= (acepLevel[player] + 1) * 10) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		// スピードアップ
		acepLevel[player]++;
		sp[player] = acepLevelTable[acepLevel[player]];
		acepTimer[player] = 5400;
		
		// 背景切り替え
		bgfadesw = 1;
		bgfadebg = acepLevel[player];
		
		// 音楽切り替え
		if(acepLines[player] >= acepBgmChangeTable[acepBgm]) {
			acepBgm++;
			bgmlv = acepBgmListTable[acepBgm];
			PlayBGM();
		}
	}
}

// スコア表示
void acepViewScore(int player) {
	int color, color2;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// レベル
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "LEVEL");
	sprintf(string[0], "%d", acepLevel[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// トータルタイム
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "TOTAL TIME");
	getTime(gameTimer[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// ベストタイム
	if((!playback) && (!IsBig[player]) && (!acepStartLevel)) {
		printTinyFont(foffset[player] + 96, fyoffset[player] + 76, "BEST TIME");
		if(acepRankingLines[0] >= 150) getTime(acepRankingTime[0]);
		else getTime(0);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 84, string[0], color);
	}
	
	// ノルマ（分子）
	ExBltRect(sg_smallfont, foffset[player] + 107, fyoffset[player] + 161, 0, 14, 22, 7);
	sprintf(string[0], "%4d", acepLines[player]);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 169, string[0], color);
	
	// ノルマ（横線）
	ExBltRect(sg_spr, foffset[player] + 105, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 106, fyoffset[player] + 181, 22, 143, 22, 1);
	
	// ノルマ（分母）
	if(ending[player]) sprintf(string[0], "%4d", acepLines[player]);
	else sprintf(string[0], "%4d", (acepLevel[player] + 1) * 10);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 185, string[0], color);
	
	// 残り時間
	if((acepTimer[player] <= 60 * 10) && (timeOn[player])) color2 = 2;
	else color2 = color;
	getTime(acepTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
}

// EXCELLENT画面
void acepExcellent(int player, int *param) {
	param[0] = 3;
	onRecord[player] = 0;
	
	// 花火
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// 時間を進める
void acepIncrementTime(int player) {
	int i;
	
	if(timeOn[player]) {
		// 制限時間減少
		acepTimer[player]--;
		
		// 時間切れ
		if(acepTimer[player] <= 0) {
			PlaySE(se_timeover);
			acepTimer[player] = 0;
			
			timeOn[player] = 0;
			onRecord[player] = 0;
			
			stat[player] = 7;
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		}
		// 残り10秒
		else if(acepTimer[player] == 10 * 60) {
			PlaySE(se_hurryup);
		}
	}
}

// BGM読み込み
void acepLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 3; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/3)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(acepBgmListTable[i]);
		}
	}
}

// 結果表示
void acepResult(int player) {
	// ランキング登録
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = acepRegistRanking(player);
		if(statc[player * 10 + 1] != -1) acepSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", acepLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", acepLevel[player] + 1);
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
void acepSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(acepLoadConfig() == 0) acepSaveConfig();
	
	// ランキングを読み込み
	if(acepLoadRanking(player) == 0) acepInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE-NORMAL+ OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",         7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",    7 * (cursor == 1));
		printFontGrid(2, 5, "GHOST BLOCK", 7 * (cursor == 2));
		printFontGrid(2, 6, "START LEVEL", 7 * (cursor == 3));
		
		// 設定値表示
		if(!acepIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!acepBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!acepGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "LV%d", acepStartLevel + 1);
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
			if(cursor == 0) acepIsBig = !acepIsBig;
			if(cursor == 1) acepBigMove = !acepBigMove;
			if(cursor == 2) acepGhost = !acepGhost;
			if(cursor == 3) {
				acepStartLevel = acepStartLevel + move;
				if(acepStartLevel < 0) acepStartLevel = 14;
				if(acepStartLevel > 14) acepStartLevel = 0;
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
			acepSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			acepViewRanking(player);
		}
	}
}

// リプレイ保存
void acepSaveReplay(int player) {
	saveBuf[900] = acepIsBig;
	saveBuf[901] = acepBigMove;
	saveBuf[902] = acepLines[player];
	saveBuf[903] = acepLevel[player];
	saveBuf[904] = acepGhost;
	saveBuf[905] = acepStartLevel;
}

// リプレイ読み込み
void acepLoadReplay(int player) {
	acepIsBig = saveBuf[900];
	acepBigMove = saveBuf[901];
	acepGhost = saveBuf[904];
	acepStartLevel = saveBuf[905];
	
	acepPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void acepReplayDetail(int number) {
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
void acepSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// 設定内容
	saveBuf[1] = acepIsBig;
	saveBuf[2] = acepBigMove;
	saveBuf[3] = acepGhost;
	saveBuf[4] = acepStartLevel;
	
	SaveFile("config/ACE_NORMAL_PLUS_CONFIG.SAV", &saveBuf, 50 * 4);
}

// 設定を読み込み
int acepLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/ACE_NORMAL_PLUS_CONFIG.SAV", &saveBuf, 50 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// 設定内容
	acepIsBig = saveBuf[1];
	acepBigMove = saveBuf[2];
	acepGhost = saveBuf[3];
	acepStartLevel = saveBuf[4];
	
	return 1;
}

// ランキング保存
void acepSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		saveBuf[1 + (i * 10) + 0] = acepRankingTime[i];
		saveBuf[1 + (i * 10) + 1] = acepRankingLines[i];
		saveBuf[1 + (i * 10) + 2] = acepRankingYear[i];
		saveBuf[1 + (i * 10) + 3] = acepRankingMonth[i];
		saveBuf[1 + (i * 10) + 4] = acepRankingDay[i];
		saveBuf[1 + (i * 10) + 5] = acepRankingHour[i];
		saveBuf[1 + (i * 10) + 6] = acepRankingMinute[i];
		saveBuf[1 + (i * 10) + 7] = acepRankingSecond[i];
	}
	
	sprintf(string[0], "config/ACE_NORMAL_PLUS_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 211 * 4);
}

// ランキング読み込み
int acepLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/ACE_NORMAL_PLUS_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 211 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		acepRankingTime[i]   = saveBuf[1 + (i * 10) + 0];
		acepRankingLines[i]  = saveBuf[1 + (i * 10) + 1];
		acepRankingYear[i]   = saveBuf[1 + (i * 10) + 2];
		acepRankingMonth[i]  = saveBuf[1 + (i * 10) + 3];
		acepRankingDay[i]    = saveBuf[1 + (i * 10) + 4];
		acepRankingHour[i]   = saveBuf[1 + (i * 10) + 5];
		acepRankingMinute[i] = saveBuf[1 + (i * 10) + 6];
		acepRankingSecond[i] = saveBuf[1 + (i * 10) + 7];
	}
}

// ランキング初期化
void acepInitRanking() {
	int i;
	
	for(i = 0; i < 20; i++) {
		acepRankingTime[i] = 0;
		acepRankingLines[i] = 0;
		acepRankingYear[i] = 0;
		acepRankingMonth[i] = 0;
		acepRankingDay[i] = 0;
		acepRankingHour[i] = 0;
		acepRankingMinute[i] = 0;
		acepRankingSecond[i] = 0;
	}
}

// ランキング登録
int acepRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (acepStartLevel)) return -1;
	
	for(i = 0; i < 20; i++) {
		// ランクイン
		if((acepLines[player] > acepRankingLines[i]) || 
		   ((acepLines[player] == acepRankingLines[i]) && (gameTimer[player] < acepRankingTime[i])))
		{
			// ランキングをずらす
			for(j = 19; j > i; j--) {
				acepRankingTime[j]   = acepRankingTime[j - 1];
				acepRankingLines[j]  = acepRankingLines[j - 1];
				acepRankingYear[j]   = acepRankingYear[j - 1];
				acepRankingMonth[j]  = acepRankingMonth[j - 1];
				acepRankingDay[j]    = acepRankingDay[j - 1];
				acepRankingHour[j]   = acepRankingHour[j - 1];
				acepRankingMinute[j] = acepRankingMinute[j - 1];
				acepRankingSecond[j] = acepRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			acepRankingTime[i]   = gameTimer[player];
			acepRankingLines[i]  = acepLines[player];
			
			GetDateAndTime(&timebuf);
			acepRankingYear[i]   = timebuf[0];
			acepRankingMonth[i]  = timebuf[1];
			acepRankingDay[i]    = timebuf[2];
			acepRankingHour[i]   = timebuf[4];
			acepRankingMinute[i] = timebuf[5];
			acepRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void acepViewRanking(int player) {
	int i, erasemode;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE-NORMAL+ MODE RANKING", 6);
		printFontGrid(1, 3, "RANK LINE TIME     DATE", 4);
		
		for(i = 0; i < 20; i++) {
			if(acepRankingLines[i] >= 150) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, 2, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 0);
			
			sprintf(string[0], "%d", acepRankingLines[i]);
			printFontGrid(6, 4 + i, string[0], 0);
			
			getTime(acepRankingTime[i]);
			printFontGrid(11, 4 + i, string[0], 0);
			
			sprintf(string[0], "%04d/%02d/%02d", acepRankingYear[i], acepRankingMonth[i], acepRankingDay[i]);
			printFontGrid(20, 4 + i, string[0], 0);
			
			sprintf(string[0], "%02d:%02d:%02d", acepRankingHour[i], acepRankingMinute[i], acepRankingSecond[i]);
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
				acepInitRanking();
				acepSaveRanking(player);
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
