//ACE200-BASIC
//prefix:ace200b

// レベルアップテーブル
int ace200bLevelTable[20] =		// 落下速度
{
	   1,   3,  15,  30,  60, 120, 180, 240, 300, 300,1200,1200,1200,1200,1200,1200,1200,1200,1200,1200
};
int ace200bWait1[20] =		// 固定→次
{
	  26,  26,  26,  26,  26,  26,  26,  26,  26,  26,  15,  11,  11,  11,  11,  10,   9,   5,   3,   2
};
int ace200bWait2[20] =		// ブロック消去
{
	  40,  40,  40,  30,  30,  25,  25,  25,  25,  25,  20,  15,  12,  10,   6,   5,   4,   3,   3,   3
};
int ace200bWait3[20] =		// 接地→固定
{
	  28,  28,  28,  26,  26,  26,  26,  26,  25,  25,  25,  23,  23,  23,  20,  20,  18,  18,  14,  11
};
int ace200bWaitt[20] =		// 横溜め
{
	  15,  15,  15,  15,  15,  15,  15,  15,  15,  15,  10,   9,   9,   8,   8,   7,   7,   7,   7,   7
};

// レベルごとの制限時間
int ace200bTimeLimit[20] =
{
	1800, 1800, 1800, 1800, 1800, 1500, 1500, 1500, 1500, 1500, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 900
};

// BGM関連
int ace200bBgm = 0;									// 現在のBGM番号
int ace200bBgmListTable[3]   = {0, 1, 2};			// 使用するBGM
int ace200bBgmFadeTable[3]   = {45, 145, 195};		// BGMがフェードアウトするライン
int ace200bBgmChangeTable[3] = {50, 150, 10000};	// BGMを切り替えるライン

// 変数
int ace200bModeNo = -1;			// モード番号
int ace200bLines[2];			// ライン
int ace200bLevel[2];			// レベル
int ace200bTimer[2];			// 制限時間

// 設定
int ace200bIsBig = 0;			// BIGかどうか
int ace200bBigMove = 1;			// BIG時の横移動単位
int ace200bGhost = 1;			// ゴーストの有無
int ace200bStartLevel = 0;		// スタート時のレベル

// ランキング用変数
int ace200bRankingTime[20];		// タイム
int ace200bRankingLines[20];	// ライン
int ace200bRankingYear[20];		// ランクイン日時（年）
int ace200bRankingMonth[20];	// ランクイン日時（月）
int ace200bRankingDay[20];		// ランクイン日時（日）
int ace200bRankingHour[20];		// ランクイン日時（時）
int ace200bRankingMinute[20];	// ランクイン日時（分）
int ace200bRankingSecond[20];	// ランクイン日時（秒）

// イベント発生
void ace200bPluginEvent(int player, int event, int *param) {
	int i;
	
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != ace200bModeNo)) return;
	
	if(event == 0) {
		ace200bModeNo = addModePlugin("ACE200-BASIC");	// モードを登録する
	} else if(event == 7) {
		timeOn[player] = 1;	// ブロック出現と同時にタイマー再開
	} else if(event == 12) {
		ace200bLineErase(player, param[0]);	// ライン消去
	} else if(event == 15) {
		ace200bViewScore(player);	// スコア表示
	} else if(event == 17) {
		ace200bSetting(player, param);	// 設定画面
	} else if(event == 18) {
		ace200bPlayerInitial(player);	// 初期化
	} else if(event == 21) {
		ace200bResult(player);	// 結果表示
	} else if(event == 24) {
		ending[player] = 3;	// エンディング突入
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		ace200bExcellent(player, param);	// EXCELLENT画面
	} else if(event == 28) {
		ace200bIncrementTime(player);	// 時間を進める
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		ace200bSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		ace200bLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		ace200bLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		ace200bReplayDetail(param[0]);	// リプレイ詳細
	}
}

// 初期化
void ace200bPlayerInitial(int player) {
	// 枠の色を灰色にする
	framecolor[player] = 5;
	frame_decoration[player] = 1;
	
	// 変数を初期化
	ace200bLines[player] = ace200bStartLevel * 10;
	ace200bLevel[player] = ace200bStartLevel;
	backno = ace200bStartLevel;
	
	// 初期BGMを設定
	ace200bBgm = 0;
	while(ace200bLines[player] >= ace200bBgmChangeTable[ace200bBgm]) ace200bBgm++;
	bgmlv = ace200bBgmListTable[ace200bBgm];
	
	// 初期スピードを設定
	sp[player] = ace200bLevelTable[ace200bLevel[player]];
	ace200bTimer[player] = ace200bTimeLimit[ace200bLevel[player]];
	wait1[player] = ace200bWait1[ace200bLevel[player]];
	wait2[player] = ace200bWait2[ace200bLevel[player]];
	wait3[player] = ace200bWait3[ace200bLevel[player]];
	waitt[player] = ace200bWaitt[ace200bLevel[player]];
	
	// 設定を反映させる
	IsBig[player] = ace200bIsBig;
	BigMove[player] = ace200bBigMove;
	if(ace200bGhost == 0) ghost[player] = 0;
}

// ライン消去
void ace200bLineErase(int player, int lines) {
	// ライン数加算
	ace200bLines[player] = ace200bLines[player] + lines;
	
	// 全消し
	if(isBravo(player)) {
		PlaySE(se_levelup);
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
	}
	
	// BGMフェードアウト
	if((ace200bLines[player] >= ace200bBgmFadeTable[ace200bBgm]) && (ace200bLines[player] < ace200bBgmChangeTable[ace200bBgm]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// エンディング
	if(ace200bLines[player] >= 200) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		ace200bLines[player] = 200;
		ending[player] = 1;
	}
	// レベルアップ
	else if(ace200bLines[player] >= (ace200bLevel[player] + 1) * 10) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		// スピードアップ
		ace200bLevel[player]++;
		sp[player] = ace200bLevelTable[ace200bLevel[player]];
		ace200bTimer[player] = ace200bTimeLimit[ace200bLevel[player]];
		wait1[player] = ace200bWait1[ace200bLevel[player]];
		wait2[player] = ace200bWait2[ace200bLevel[player]];
		wait3[player] = ace200bWait3[ace200bLevel[player]];
		waitt[player] = ace200bWaitt[ace200bLevel[player]];
		
		// 背景切り替え
		bgfadesw = 1;
		bgfadebg = ace200bLevel[player];
		
		// 音楽切り替え
		if(ace200bLines[player] >= ace200bBgmChangeTable[ace200bBgm]) {
			ace200bBgm++;
			bgmlv = ace200bBgmListTable[ace200bBgm];
			PlayBGM();
		}
	}
}

// スコア表示
void ace200bViewScore(int player) {
	int color, color2;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// レベル
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "LEVEL");
	sprintf(string[0], "%d", ace200bLevel[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// トータルタイム
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "TOTAL TIME");
	getTime(gameTimer[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// ノルマ（分子）
	ExBltRect(sg_smallfont, foffset[player] + 107, fyoffset[player] + 161, 0, 14, 22, 7);
	sprintf(string[0], "%4d", ace200bLines[player]);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 169, string[0], color);
	
	// ノルマ（横線）
	ExBltRect(sg_spr, foffset[player] + 105, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 106, fyoffset[player] + 181, 22, 143, 22, 1);
	
	// ノルマ（分母）
	if(ending[player]) sprintf(string[0], "%4d", ace200bLines[player]);
	else sprintf(string[0], "%4d", (ace200bLevel[player] + 1) * 10);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 185, string[0], color);
	
	// 残り時間
	if((ace200bTimer[player] <= 60 * 10) && (timeOn[player])) color2 = 2;
	else color2 = color;
	getTime(ace200bTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
}

// EXCELLENT画面
void ace200bExcellent(int player, int *param) {
	param[0] = 3;
	onRecord[player] = 0;
	
	// 花火
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// 時間を進める
void ace200bIncrementTime(int player) {
	int i;
	
	if(timeOn[player]) {
		// 制限時間減少
		ace200bTimer[player]--;
		
		// 時間切れ
		if(ace200bTimer[player] <= 0) {
			PlaySE(se_timeover);
			ace200bTimer[player] = 0;
			
			timeOn[player] = 0;
			onRecord[player] = 0;
			
			stat[player] = 7;
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		}
		// 残り10秒
		else if(ace200bTimer[player] == 10 * 60) {
			PlaySE(se_hurryup);
		}
	}
}

// BGM読み込み
void ace200bLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 3; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/3)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(ace200bBgmListTable[i]);
		}
	}
}

// 結果表示
void ace200bResult(int player) {
	// ランキング登録
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = ace200bRegistRanking(player);
		if(statc[player * 10 + 1] != -1) ace200bSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", ace200bLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", ace200bLevel[player] + 1);
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
void ace200bSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(ace200bLoadConfig() == 0) ace200bSaveConfig();
	
	// ランキングを読み込み
	if(ace200bLoadRanking(player) == 0) ace200bInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE200-BASIC OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",         7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",    7 * (cursor == 1));
		printFontGrid(2, 5, "GHOST BLOCK", 7 * (cursor == 2));
		printFontGrid(2, 6, "START LEVEL", 7 * (cursor == 3));
		
		// 設定値表示
		if(!ace200bIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!ace200bBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!ace200bGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "LV%d", ace200bStartLevel + 1);
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
			if(cursor == 0) ace200bIsBig = !ace200bIsBig;
			if(cursor == 1) ace200bBigMove = !ace200bBigMove;
			if(cursor == 2) ace200bGhost = !ace200bGhost;
			if(cursor == 3) {
				ace200bStartLevel = ace200bStartLevel + move;
				if(ace200bStartLevel < 0) ace200bStartLevel = 19;
				if(ace200bStartLevel > 19) ace200bStartLevel = 0;
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
			ace200bSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			ace200bViewRanking(player);
		}
	}
}

// リプレイ保存
void ace200bSaveReplay(int player) {
	saveBuf[900] = ace200bIsBig;
	saveBuf[901] = ace200bBigMove;
	saveBuf[902] = ace200bLines[player];
	saveBuf[903] = ace200bLevel[player];
	saveBuf[904] = ace200bGhost;
	saveBuf[905] = ace200bStartLevel;
}

// リプレイ読み込み
void ace200bLoadReplay(int player) {
	ace200bIsBig = saveBuf[900];
	ace200bBigMove = saveBuf[901];
	ace200bGhost = saveBuf[904];
	ace200bStartLevel = saveBuf[905];
	
	ace200bPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void ace200bReplayDetail(int number) {
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
void ace200bSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// 設定内容
	saveBuf[1] = ace200bIsBig;
	saveBuf[2] = ace200bBigMove;
	saveBuf[3] = ace200bGhost;
	saveBuf[4] = ace200bStartLevel;
	
	SaveFile("config/ACE200_BASIC_CONFIG.SAV", &saveBuf, 50 * 4);
}

// 設定を読み込み
int ace200bLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/ACE200_BASIC_CONFIG.SAV", &saveBuf, 50 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// 設定内容
	ace200bIsBig = saveBuf[1];
	ace200bBigMove = saveBuf[2];
	ace200bGhost = saveBuf[3];
	ace200bStartLevel = saveBuf[4];
	
	return 1;
}

// ランキング保存
void ace200bSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		saveBuf[1 + (i * 10) + 0] = ace200bRankingTime[i];
		saveBuf[1 + (i * 10) + 1] = ace200bRankingLines[i];
		saveBuf[1 + (i * 10) + 2] = ace200bRankingYear[i];
		saveBuf[1 + (i * 10) + 3] = ace200bRankingMonth[i];
		saveBuf[1 + (i * 10) + 4] = ace200bRankingDay[i];
		saveBuf[1 + (i * 10) + 5] = ace200bRankingHour[i];
		saveBuf[1 + (i * 10) + 6] = ace200bRankingMinute[i];
		saveBuf[1 + (i * 10) + 7] = ace200bRankingSecond[i];
	}
	
	sprintf(string[0], "config/ACE200_BASIC_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 211 * 4);
}

// ランキング読み込み
int ace200bLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/ACE200_BASIC_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 211 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		ace200bRankingTime[i]   = saveBuf[1 + (i * 10) + 0];
		ace200bRankingLines[i]  = saveBuf[1 + (i * 10) + 1];
		ace200bRankingYear[i]   = saveBuf[1 + (i * 10) + 2];
		ace200bRankingMonth[i]  = saveBuf[1 + (i * 10) + 3];
		ace200bRankingDay[i]    = saveBuf[1 + (i * 10) + 4];
		ace200bRankingHour[i]   = saveBuf[1 + (i * 10) + 5];
		ace200bRankingMinute[i] = saveBuf[1 + (i * 10) + 6];
		ace200bRankingSecond[i] = saveBuf[1 + (i * 10) + 7];
	}
}

// ランキング初期化
void ace200bInitRanking() {
	int i;
	
	for(i = 0; i < 20; i++) {
		ace200bRankingTime[i] = 0;
		ace200bRankingLines[i] = 0;
		ace200bRankingYear[i] = 0;
		ace200bRankingMonth[i] = 0;
		ace200bRankingDay[i] = 0;
		ace200bRankingHour[i] = 0;
		ace200bRankingMinute[i] = 0;
		ace200bRankingSecond[i] = 0;
	}
}

// ランキング登録
int ace200bRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (ace200bStartLevel)) return -1;
	
	for(i = 0; i < 20; i++) {
		// ランクイン
		if((ace200bLines[player] > ace200bRankingLines[i]) || 
		   ((ace200bLines[player] == ace200bRankingLines[i]) && (gameTimer[player] < ace200bRankingTime[i])))
		{
			// ランキングをずらす
			for(j = 19; j > i; j--) {
				ace200bRankingTime[j]   = ace200bRankingTime[j - 1];
				ace200bRankingLines[j]  = ace200bRankingLines[j - 1];
				ace200bRankingYear[j]   = ace200bRankingYear[j - 1];
				ace200bRankingMonth[j]  = ace200bRankingMonth[j - 1];
				ace200bRankingDay[j]    = ace200bRankingDay[j - 1];
				ace200bRankingHour[j]   = ace200bRankingHour[j - 1];
				ace200bRankingMinute[j] = ace200bRankingMinute[j - 1];
				ace200bRankingSecond[j] = ace200bRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			ace200bRankingTime[i]   = gameTimer[player];
			ace200bRankingLines[i]  = ace200bLines[player];
			
			GetDateAndTime(&timebuf);
			ace200bRankingYear[i]   = timebuf[0];
			ace200bRankingMonth[i]  = timebuf[1];
			ace200bRankingDay[i]    = timebuf[2];
			ace200bRankingHour[i]   = timebuf[4];
			ace200bRankingMinute[i] = timebuf[5];
			ace200bRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void ace200bViewRanking(int player) {
	int i, erasemode;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE200-BASIC MODE RANKING", 6);
		printFontGrid(1, 3, "RANK LINE TIME     DATE", 4);
		
		for(i = 0; i < 20; i++) {
			if(ace200bRankingLines[i] >= 200) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, 2, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 0);
			
			sprintf(string[0], "%d", ace200bRankingLines[i]);
			printFontGrid(6, 4 + i, string[0], 0);
			
			getTime(ace200bRankingTime[i]);
			printFontGrid(11, 4 + i, string[0], 0);
			
			sprintf(string[0], "%04d/%02d/%02d", ace200bRankingYear[i], ace200bRankingMonth[i], ace200bRankingDay[i]);
			printFontGrid(20, 4 + i, string[0], 0);
			
			sprintf(string[0], "%02d:%02d:%02d", ace200bRankingHour[i], ace200bRankingMinute[i], ace200bRankingSecond[i]);
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
				ace200bInitRanking();
				ace200bSaveRanking(player);
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
