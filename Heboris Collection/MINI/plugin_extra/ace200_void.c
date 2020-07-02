//ACE200-VOID
//prefix:ace200v

// レベルアップテーブル
int ace200vWait1[20] =		// 固定→次
{
	   2,   2,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
};
int ace200vWait2[20] =		// ブロック消去
{
	   3,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
};
int ace200vWait3[20] =		// 接地→固定
{
	  11,  10,   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,   8,   8,   8,   8,   8
};
int ace200vWaitt[20] =		// 横溜め
{
	   7,   5,   5,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   2,   2,   2,   2,   2
};

// レベルごとの制限時間
int ace200vTimeLimit[20] =
{
	1800, 1200, 900, 900, 900, 840, 840, 840, 840, 840, 720, 720, 720, 720, 720, 540, 480, 420, 360, 300
};

// 使用するBGM
int ace200vBgmListTable[2] = {5, 6};

// 変数
int ace200vModeNo = -1;		// モード番号
int ace200vLines[2];		// ライン
int ace200vLevel[2];		// レベル
int ace200vTimer[2];		// 制限時間
int ace200vEndFlag[2];		// 完全クリアフラグ

// 設定
int ace200vIsBig = 0;		// BIGかどうか
int ace200vBigMove = 1;		// BIG時の横移動単位
int ace200vStartLevel = 0;	// スタート時のレベル

// ランキング用変数
int ace200vRankingTime[20];		// タイム
int ace200vRankingLines[20];	// ライン
int ace200vRankingEnd[20];		// 完全クリアフラグ
int ace200vRankingYear[20];		// ランクイン日時（年）
int ace200vRankingMonth[20];	// ランクイン日時（月）
int ace200vRankingDay[20];		// ランクイン日時（日）
int ace200vRankingHour[20];		// ランクイン日時（時）
int ace200vRankingMinute[20];	// ランクイン日時（分）
int ace200vRankingSecond[20];	// ランクイン日時（秒）

// イベント発生
void ace200vPluginEvent(int player, int event, int *param) {
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != ace200vModeNo)) return;
	
	if(event == 0) {
		// モードを登録する
		ace200vModeNo = addModePlugin("ACE200-VOID");
	} else if(event == 7) {
		if(!ending[player]) timeOn[player] = 1;	// ブロック出現と同時にタイマー再開
	} else if(event == 12) {
		if(!ending[player]) ace200vLineErase(player, param[0]);	// ライン消去
	} else if(event == 15) {
		ace200vViewScore(player);	// スコア表示
	} else if(event == 17) {
		ace200vSetting(player, param);	// 設定画面
	} else if(event == 18) {
		ace200vPlayerInitial(player);	// 初期化
	} else if(event == 21) {
		ace200vResult(player);	// 結果表示
	} else if(event == 24) {
		ace200vEndingStart(player);	// エンディング突入
	} else if(event == 25) {
		ace200vExcellent(player, param);	// EXCELLENT画面
	} else if(event == 28) {
		ace200vIncrementTime(player);	// 時間を進める
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		ace200vSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		ace200vLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		ace200vLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		ace200vReplayDetail(param[0]);	// リプレイ詳細
	}
}

// 初期化
void ace200vPlayerInitial(int player) {
	// 枠の色を変える
	framecolor[player] = 2;
	frame_decoration[player] = 1;
	
	// []
	oblk_spawn[player] = 1;
	
	// 変数を初期化
	ace200vLines[player] = ace200vStartLevel * 10;
	ace200vLevel[player] = ace200vStartLevel;
	backno = ace200vStartLevel;
	ace200vEndFlag[player] = 0;
	
	// 初期BGMを設定
	bgmlv = ace200vBgmListTable[0];
	
	// 初期スピードを設定
	sp[player] = 1200;
	ace200vTimer[player] = ace200vTimeLimit[ace200vLevel[player]];
	wait1[player] = ace200vWait1[ace200vLevel[player]];
	wait2[player] = ace200vWait2[ace200vLevel[player]];
	wait3[player] = ace200vWait3[ace200vLevel[player]];
	waitt[player] = ace200vWaitt[ace200vLevel[player]];
	
	// 設定を反映させる
	IsBig[player] = ace200vIsBig;
	BigMove[player] = ace200vBigMove;
}

// ライン消去
void ace200vLineErase(int player, int lines) {
	// ライン数加算
	ace200vLines[player] = ace200vLines[player] + lines;
	
	// 全消し
	if(isBravo(player)) {
		PlaySE(se_levelup);
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
	}
	
	// BGMフェードアウト
	if((ace200vLines[player] >= 195) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// エンディング
	if(ace200vLines[player] >= 200) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		ace200vLines[player] = 200;
		ending[player] = 1;
		
		ace200vEndFlag[player] = 1;
	}
	// レベルアップ
	else if(ace200vLines[player] >= (ace200vLevel[player] + 1) * 10) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		// スピードアップ
		ace200vLevel[player]++;
		ace200vTimer[player] = ace200vTimeLimit[ace200vLevel[player]];
		wait1[player] = ace200vWait1[ace200vLevel[player]];
		wait2[player] = ace200vWait2[ace200vLevel[player]];
		wait3[player] = ace200vWait3[ace200vLevel[player]];
		waitt[player] = ace200vWaitt[ace200vLevel[player]];
		
		// 背景切り替え
		bgfadesw = 1;
		bgfadebg = ace200vLevel[player];
	}
}

// スコア表示
void ace200vViewScore(int player) {
	int color, color2;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// レベル
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "LEVEL");
	sprintf(string[0], "%d", ace200vLevel[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// トータルタイム
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "TOTAL TIME");
	getTime(gameTimer[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// ノルマ（分子）
	ExBltRect(sg_smallfont, foffset[player] + 107, fyoffset[player] + 161, 0, 14, 22, 7);
	sprintf(string[0], "%4d", ace200vLines[player]);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 169, string[0], color);
	
	// ノルマ（横線）
	ExBltRect(sg_spr, foffset[player] + 105, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 106, fyoffset[player] + 181, 22, 143, 22, 1);
	
	// ノルマ（分母）
	if(ending[player]) sprintf(string[0], "%4d", ace200vLines[player]);
	else sprintf(string[0], "%4d", (ace200vLevel[player] + 1) * 10);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 185, string[0], color);
	
	// 残り時間
	if((ace200vTimer[player] <= 60 * 10) && (timeOn[player])) color2 = 2;
	else color2 = color;
	getTime(ace200vTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
}

// エンディング突入
void ace200vEndingStart(int player) {
	int i;
	
	for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	
	ending[player] = 2;
	stat[player] = 4;
	ending_timeOn[player] = 1;
	fastroll[player] = 0;
	
	hidden[player] = 10;
	
	bgmlv = ace200vBgmListTable[1];
	PlayBGM();
}

// EXCELLENT画面
void ace200vExcellent(int player, int *param) {
	param[0] = 2;
	onRecord[player] = 0;
	hidden[player] = 0;
	ace200vEndFlag[player] = 2;
	
	// 花火
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// 時間を進める
void ace200vIncrementTime(int player) {
	int i;
	
	if(timeOn[player]) {
		// 制限時間減少
		ace200vTimer[player]--;
		
		// 時間切れ
		if(ace200vTimer[player] <= 0) {
			PlaySE(se_timeover);
			ace200vTimer[player] = 0;
			
			timeOn[player] = 0;
			onRecord[player] = 0;
			
			stat[player] = 7;
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		}
		// 残り10秒
		else if(ace200vTimer[player] == 10 * 60) {
			PlaySE(se_hurryup);
		}
	}
	
	// ロール終了
	if((ending[player] == 2) && (edrec[player] >= 60 * 60)) {
		ending[player] = 3;
		stat[player] = 10;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
}

// BGM読み込み
void ace200vLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 2; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/2)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(ace200vBgmListTable[i]);
		}
	}
}

// 結果表示
void ace200vResult(int player) {
	// ランキング登録
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = ace200vRegistRanking(player);
		if(statc[player * 10 + 1] != -1) ace200vSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", ace200vLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", ace200vLevel[player] + 1);
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
void ace200vSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(ace200vLoadConfig() == 0) ace200vSaveConfig();
	
	// ランキングを読み込み
	if(ace200vLoadRanking(player) == 0) ace200vInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE200-VOID OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",         7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",    7 * (cursor == 1));
		printFontGrid(2, 5, "START LEVEL", 7 * (cursor == 2));
		
		// 設定値表示
		if(!ace200vIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!ace200vBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "LV%d", ace200vStartLevel + 1);
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
			if(cursor == 0) ace200vIsBig = !ace200vIsBig;
			if(cursor == 1) ace200vBigMove = !ace200vBigMove;
			if(cursor == 2) {
				ace200vStartLevel = ace200vStartLevel + move;
				if(ace200vStartLevel < 0) ace200vStartLevel = 19;
				if(ace200vStartLevel > 19) ace200vStartLevel = 0;
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
			ace200vSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			ace200vViewRanking(player);
		}
	}
}

// リプレイ保存
void ace200vSaveReplay(int player) {
	saveBuf[900] = ace200vIsBig;
	saveBuf[901] = ace200vBigMove;
	saveBuf[902] = ace200vLines[player];
	saveBuf[903] = ace200vLevel[player];
	saveBuf[904] = ace200vStartLevel;
}

// リプレイ読み込み
void ace200vLoadReplay(int player) {
	ace200vIsBig = saveBuf[900];
	ace200vBigMove = saveBuf[901];
	ace200vStartLevel = saveBuf[904];
	
	ace200vPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void ace200vReplayDetail(int number) {
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
void ace200vSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// 設定内容
	saveBuf[1] = ace200vIsBig;
	saveBuf[2] = ace200vBigMove;
	saveBuf[3] = ace200vStartLevel;
	
	SaveFile("config/ACE200_VOID_CONFIG.SAV", &saveBuf, 50 * 4);
}

// 設定を読み込み
int ace200vLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/ACE200_VOID_CONFIG.SAV", &saveBuf, 50 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// 設定内容
	ace200vIsBig = saveBuf[1];
	ace200vBigMove = saveBuf[2];
	ace200vStartLevel = saveBuf[3];
	
	return 1;
}

// ランキング保存
void ace200vSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		saveBuf[1 + (i * 10) + 0] = ace200vRankingTime[i];
		saveBuf[1 + (i * 10) + 1] = ace200vRankingLines[i];
		saveBuf[1 + (i * 10) + 2] = ace200vRankingEnd[i];
		saveBuf[1 + (i * 10) + 3] = ace200vRankingYear[i];
		saveBuf[1 + (i * 10) + 4] = ace200vRankingMonth[i];
		saveBuf[1 + (i * 10) + 5] = ace200vRankingDay[i];
		saveBuf[1 + (i * 10) + 6] = ace200vRankingHour[i];
		saveBuf[1 + (i * 10) + 7] = ace200vRankingMinute[i];
		saveBuf[1 + (i * 10) + 8] = ace200vRankingSecond[i];
	}
	
	sprintf(string[0], "config/ACE200_VOID_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 211 * 4);
}

// ランキング読み込み
int ace200vLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/ACE200_VOID_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 211 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		ace200vRankingTime[i]   = saveBuf[1 + (i * 10) + 0];
		ace200vRankingLines[i]  = saveBuf[1 + (i * 10) + 1];
		ace200vRankingEnd[i]    = saveBuf[1 + (i * 10) + 2];
		ace200vRankingYear[i]   = saveBuf[1 + (i * 10) + 3];
		ace200vRankingMonth[i]  = saveBuf[1 + (i * 10) + 4];
		ace200vRankingDay[i]    = saveBuf[1 + (i * 10) + 5];
		ace200vRankingHour[i]   = saveBuf[1 + (i * 10) + 6];
		ace200vRankingMinute[i] = saveBuf[1 + (i * 10) + 7];
		ace200vRankingSecond[i] = saveBuf[1 + (i * 10) + 8];
	}
}

// ランキング初期化
void ace200vInitRanking() {
	int i;
	
	for(i = 0; i < 20; i++) {
		ace200vRankingTime[i] = 0;
		ace200vRankingLines[i] = 0;
		ace200vRankingEnd[i] = 0;
		ace200vRankingYear[i] = 0;
		ace200vRankingMonth[i] = 0;
		ace200vRankingDay[i] = 0;
		ace200vRankingHour[i] = 0;
		ace200vRankingMinute[i] = 0;
		ace200vRankingSecond[i] = 0;
	}
}

// ランキング登録
int ace200vRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (ace200vStartLevel)) return -1;
	
	for(i = 0; i < 20; i++) {
		// ランクイン
		if((ace200vEndFlag[player] > ace200vRankingEnd[i]) || 
		   ((ace200vEndFlag[player] == ace200vRankingEnd[i]) && (ace200vLines[player] > ace200vRankingLines[i])) || 
		   ((ace200vEndFlag[player] == ace200vRankingEnd[i]) && (ace200vLines[player] == ace200vRankingLines[i]) && (gameTimer[player] < ace200vRankingTime[i])))
		{
			// ランキングをずらす
			for(j = 19; j > i; j--) {
				ace200vRankingTime[j]   = ace200vRankingTime[j - 1];
				ace200vRankingLines[j]  = ace200vRankingLines[j - 1];
				ace200vRankingEnd[j]    = ace200vRankingEnd[j - 1];
				ace200vRankingYear[j]   = ace200vRankingYear[j - 1];
				ace200vRankingMonth[j]  = ace200vRankingMonth[j - 1];
				ace200vRankingDay[j]    = ace200vRankingDay[j - 1];
				ace200vRankingHour[j]   = ace200vRankingHour[j - 1];
				ace200vRankingMinute[j] = ace200vRankingMinute[j - 1];
				ace200vRankingSecond[j] = ace200vRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			ace200vRankingTime[i]   = gameTimer[player];
			ace200vRankingLines[i]  = ace200vLines[player];
			ace200vRankingEnd[i]    = ace200vEndFlag[player];
			
			GetDateAndTime(&timebuf);
			ace200vRankingYear[i]   = timebuf[0];
			ace200vRankingMonth[i]  = timebuf[1];
			ace200vRankingDay[i]    = timebuf[2];
			ace200vRankingHour[i]   = timebuf[4];
			ace200vRankingMinute[i] = timebuf[5];
			ace200vRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void ace200vViewRanking(int player) {
	int i, erasemode;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE200-VOID MODE RANKING", 6);
		printFontGrid(1, 3, "RANK LINE TIME     DATE", 4);
		
		for(i = 0; i < 20; i++) {
			if(ace200vRankingEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (ace200vRankingEnd[i] - 1) * 2, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 0);
			
			sprintf(string[0], "%d", ace200vRankingLines[i]);
			printFontGrid(6, 4 + i, string[0], 0);
			
			getTime(ace200vRankingTime[i]);
			printFontGrid(11, 4 + i, string[0], 0);
			
			sprintf(string[0], "%04d/%02d/%02d", ace200vRankingYear[i], ace200vRankingMonth[i], ace200vRankingDay[i]);
			printFontGrid(20, 4 + i, string[0], 0);
			
			sprintf(string[0], "%02d:%02d:%02d", ace200vRankingHour[i], ace200vRankingMinute[i], ace200vRankingSecond[i]);
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
				ace200vInitRanking();
				ace200vSaveRanking(player);
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
