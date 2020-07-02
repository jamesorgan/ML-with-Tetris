//ACE200-HELL
//prefix:ace200h

// レベルごとの制限時間
int ace200hTimeLimit[20] =
{
	1800, 1800, 1800, 1800, 1800, 1500, 1500, 1500, 1500, 1500, 1200, 1200, 1200, 1020, 900, 1200, 1020, 900, 840, 840
};

// BGM関連
int ace200hBgm = 0;									// 現在のBGM番号
int ace200hBgmListTable[3]   = {19, 18, 16};		// 使用するBGM
int ace200hBgmFadeTable[3]   = {45, 145, 195};		// BGMがフェードアウトするライン
int ace200hBgmChangeTable[3] = {50, 150, 10000};	// BGMを切り替えるライン

// 変数
int ace200hModeNo = -1;			// モード番号
int ace200hLines[2];			// ライン
int ace200hLevel[2];			// レベル
int ace200hTimer[2];			// 制限時間

// 設定
int ace200hIsBig = 0;			// BIGかどうか
int ace200hBigMove = 1;			// BIG時の横移動単位
int ace200hStartLevel = 0;		// スタート時のレベル

// ランキング用変数
int ace200hRankingTime[20];		// タイム
int ace200hRankingLines[20];	// ライン
int ace200hRankingYear[20];		// ランクイン日時（年）
int ace200hRankingMonth[20];	// ランクイン日時（月）
int ace200hRankingDay[20];		// ランクイン日時（日）
int ace200hRankingHour[20];		// ランクイン日時（時）
int ace200hRankingMinute[20];	// ランクイン日時（分）
int ace200hRankingSecond[20];	// ランクイン日時（秒）

// イベント発生
void ace200hPluginEvent(int player, int event, int *param) {
	int i;
	
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != ace200hModeNo)) return;
	
	if(event == 0) {
		// モードを登録する
		ace200hModeNo = addModePlugin("ACE200-HELL");
	} else if(event == 7) {
		timeOn[player] = 1;	// ブロック出現と同時にタイマー再開
	} else if(event == 12) {
		ace200hLineErase(player, param[0]);	// ライン消去
	} else if(event == 15) {
		ace200hViewScore(player);	// スコア表示
	} else if(event == 17) {
		ace200hSetting(player, param);	// 設定画面
	} else if(event == 18) {
		ace200hPlayerInitial(player);	// 初期化
	} else if(event == 21) {
		ace200hResult(player);	// 結果表示
	} else if(event == 24) {
		ending[player] = 3;	// エンディング突入
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		ace200hExcellent(player, param);	// EXCELLENT画面
	} else if(event == 28) {
		ace200hIncrementTime(player);	// 時間を進める
	} else if(event == 34) {
		ace200hViewFieldBlock(player, param);	// フィールド描画
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		ace200hSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		ace200hLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		ace200hLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		ace200hReplayDetail(param[0]);	// リプレイ詳細
	}
}

// 初期化
void ace200hPlayerInitial(int player) {
	// 枠の色を変える
	framecolor[player] = 2;
	frame_decoration[player] = 1;
	
	// 変数を初期化
	ace200hLines[player] = ace200hStartLevel * 10;
	ace200hLevel[player] = ace200hStartLevel;
	backno = ace200hStartLevel;
	
	// 初期BGMを設定
	ace200hBgm = 0;
	while(ace200hLines[player] >= ace200hBgmChangeTable[ace200hBgm]) ace200hBgm++;
	bgmlv = ace200hBgmListTable[ace200hBgm];
	
	// 初期スピードを設定
	sp[player] = 1200;
	ace200hTimer[player] = ace200hTimeLimit[ace200hLevel[player]];
	wait1[player] = 2;
	wait2[player] = 3;
	wait3[player] = 11;
	waitt[player] = 7;
	
	// 設定を反映させる
	IsBig[player] = ace200hIsBig;
	BigMove[player] = ace200hBigMove;
	
	// ギミック発動
	ace200hStartGimmick(player);
}

// ライン消去
void ace200hLineErase(int player, int lines) {
	// ライン数加算
	ace200hLines[player] = ace200hLines[player] + lines;
	
	// 全消し
	if(isBravo(player)) {
		PlaySE(se_levelup);
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
	}
	
	// BGMフェードアウト
	if((ace200hLines[player] >= ace200hBgmFadeTable[ace200hBgm]) && (ace200hLines[player] < ace200hBgmChangeTable[ace200hBgm]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// エンディング
	if(ace200hLines[player] >= 200) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		ace200hLines[player] = 200;
		ending[player] = 1;
	}
	// レベルアップ
	else if(ace200hLines[player] >= (ace200hLevel[player] + 1) * 10) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		// スピードアップ
		ace200hLevel[player]++;
		ace200hTimer[player] = ace200hTimeLimit[ace200hLevel[player]];
		
		// 背景切り替え
		bgfadesw = 1;
		bgfadebg = ace200hLevel[player];
		
		// 音楽切り替え
		if(ace200hLines[player] >= ace200hBgmChangeTable[ace200hBgm]) {
			ace200hBgm++;
			bgmlv = ace200hBgmListTable[ace200hBgm];
			PlayBGM();
		}
		
		// ギミック発動
		ace200hStartGimmick(player);
	}
}

// ギミック発動
void ace200hStartGimmick(int player) {
	if((ace200hLevel[player] >= 5) && (ace200hLevel[player] <= 6)) {
		hidden[player] = 4;	// レベル6～7
	} else if((ace200hLevel[player] >= 7) && (ace200hLevel[player] <= 14)) {
		hidden[player] = 5;	// レベル8～15
	} else if(ace200hLevel[player] >= 15) {
		hidden[player] = 0;
		oblk_spawn[player] = 1;	// レベル16以降は[]
	}
}

// スコア表示
void ace200hViewScore(int player) {
	int color, color2;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// レベル
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "LEVEL");
	sprintf(string[0], "%d", ace200hLevel[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// トータルタイム
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "TOTAL TIME");
	getTime(gameTimer[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// ノルマ（分子）
	ExBltRect(sg_smallfont, foffset[player] + 107, fyoffset[player] + 161, 0, 14, 22, 7);
	sprintf(string[0], "%4d", ace200hLines[player]);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 169, string[0], color);
	
	// ノルマ（横線）
	ExBltRect(sg_spr, foffset[player] + 105, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 106, fyoffset[player] + 181, 22, 143, 22, 1);
	
	// ノルマ（分母）
	if(ending[player]) sprintf(string[0], "%4d", ace200hLines[player]);
	else sprintf(string[0], "%4d", (ace200hLevel[player] + 1) * 10);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 185, string[0], color);
	
	// 残り時間
	if((ace200hTimer[player] <= 60 * 10) && (timeOn[player])) color2 = 2;
	else color2 = color;
	getTime(ace200hTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
}

// EXCELLENT画面
void ace200hExcellent(int player, int *param) {
	param[0] = 3;
	onRecord[player] = 0;
	
	// 花火
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// 時間を進める
void ace200hIncrementTime(int player) {
	int i;
	
	if(timeOn[player]) {
		// 制限時間減少
		ace200hTimer[player]--;
		
		// 時間切れ
		if(ace200hTimer[player] <= 0) {
			PlaySE(se_timeover);
			ace200hTimer[player] = 0;
			
			timeOn[player] = 0;
			onRecord[player] = 0;
			
			stat[player] = 7;
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		}
		// 残り10秒
		else if(ace200hTimer[player] == 10 * 60) {
			PlaySE(se_hurryup);
		}
	}
}

// BGM読み込み
void ace200hLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 3; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/3)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(ace200hBgmListTable[i]);
		}
	}
}

// 結果表示
void ace200hResult(int player) {
	// ランキング登録
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = ace200hRegistRanking(player);
		if(statc[player * 10 + 1] != -1) ace200hSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", ace200hLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", ace200hLevel[player] + 1);
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

// フィールドを描画
void ace200hViewFieldBlock(int player, int *param) {
	int i, j, fi, ft, temp, dx, dy;
	
	param[0] = 1;
	
	if(hidden[player] == 10) return;
	
	for(i = 0; i < hiddeny[player]; i++) {
		for(j = 0; j < 10; j++) {
			fi = getFieldBlock(player, j, i);
			
			if(fi > 0) {
				dx = foffset[player] + 8 + (j * 8);
				dy = fyoffset[player] + (i + 3) * 8;
				ft = getFieldBlockT(player, j, i);
				
				// 枠線を描画
				if(ft != 0) viewFieldBlockSub_DrawLine(player, j, i, dx, dy);
			}
		}
	}
	
	// HIDDEN
	viewFieldBlockSub_Hidden(player);
}

// 設定画面
void ace200hSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(ace200hLoadConfig() == 0) ace200hSaveConfig();
	
	// ランキングを読み込み
	if(ace200hLoadRanking(player) == 0) ace200hInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE200-HELL OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",         7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",    7 * (cursor == 1));
		printFontGrid(2, 5, "START LEVEL", 7 * (cursor == 2));
		
		// 設定値表示
		if(!ace200hIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!ace200hBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "LV%d", ace200hStartLevel + 1);
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
			if(cursor == 0) ace200hIsBig = !ace200hIsBig;
			if(cursor == 1) ace200hBigMove = !ace200hBigMove;
			if(cursor == 2) {
				ace200hStartLevel = ace200hStartLevel + move;
				if(ace200hStartLevel < 0) ace200hStartLevel = 19;
				if(ace200hStartLevel > 19) ace200hStartLevel = 0;
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
			ace200hSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			ace200hViewRanking(player);
		}
	}
}

// リプレイ保存
void ace200hSaveReplay(int player) {
	saveBuf[900] = ace200hIsBig;
	saveBuf[901] = ace200hBigMove;
	saveBuf[902] = ace200hLines[player];
	saveBuf[903] = ace200hLevel[player];
	saveBuf[904] = ace200hStartLevel;
}

// リプレイ読み込み
void ace200hLoadReplay(int player) {
	ace200hIsBig = saveBuf[900];
	ace200hBigMove = saveBuf[901];
	ace200hStartLevel = saveBuf[904];
	
	ace200hPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void ace200hReplayDetail(int number) {
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
void ace200hSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// 設定内容
	saveBuf[1] = ace200hIsBig;
	saveBuf[2] = ace200hBigMove;
	saveBuf[3] = ace200hStartLevel;
	
	SaveFile("config/ACE200_HELL_CONFIG.SAV", &saveBuf, 50 * 4);
}

// 設定を読み込み
int ace200hLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/ACE200_HELL_CONFIG.SAV", &saveBuf, 50 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// 設定内容
	ace200hIsBig = saveBuf[1];
	ace200hBigMove = saveBuf[2];
	ace200hStartLevel = saveBuf[3];
	
	return 1;
}

// ランキング保存
void ace200hSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		saveBuf[1 + (i * 10) + 0] = ace200hRankingTime[i];
		saveBuf[1 + (i * 10) + 1] = ace200hRankingLines[i];
		saveBuf[1 + (i * 10) + 2] = ace200hRankingYear[i];
		saveBuf[1 + (i * 10) + 3] = ace200hRankingMonth[i];
		saveBuf[1 + (i * 10) + 4] = ace200hRankingDay[i];
		saveBuf[1 + (i * 10) + 5] = ace200hRankingHour[i];
		saveBuf[1 + (i * 10) + 6] = ace200hRankingMinute[i];
		saveBuf[1 + (i * 10) + 7] = ace200hRankingSecond[i];
	}
	
	sprintf(string[0], "config/ACE200_HELL_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 211 * 4);
}

// ランキング読み込み
int ace200hLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/ACE200_HELL_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 211 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		ace200hRankingTime[i]   = saveBuf[1 + (i * 10) + 0];
		ace200hRankingLines[i]  = saveBuf[1 + (i * 10) + 1];
		ace200hRankingYear[i]   = saveBuf[1 + (i * 10) + 2];
		ace200hRankingMonth[i]  = saveBuf[1 + (i * 10) + 3];
		ace200hRankingDay[i]    = saveBuf[1 + (i * 10) + 4];
		ace200hRankingHour[i]   = saveBuf[1 + (i * 10) + 5];
		ace200hRankingMinute[i] = saveBuf[1 + (i * 10) + 6];
		ace200hRankingSecond[i] = saveBuf[1 + (i * 10) + 7];
	}
}

// ランキング初期化
void ace200hInitRanking() {
	int i;
	
	for(i = 0; i < 20; i++) {
		ace200hRankingTime[i] = 0;
		ace200hRankingLines[i] = 0;
		ace200hRankingYear[i] = 0;
		ace200hRankingMonth[i] = 0;
		ace200hRankingDay[i] = 0;
		ace200hRankingHour[i] = 0;
		ace200hRankingMinute[i] = 0;
		ace200hRankingSecond[i] = 0;
	}
}

// ランキング登録
int ace200hRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player])) return -1;
	
	for(i = 0; i < 20; i++) {
		// ランクイン
		if((ace200hLines[player] > ace200hRankingLines[i]) || 
		   ((ace200hLines[player] == ace200hRankingLines[i]) && (gameTimer[player] < ace200hRankingTime[i])))
		{
			// ランキングをずらす
			for(j = 19; j > i; j--) {
				ace200hRankingTime[j]   = ace200hRankingTime[j - 1];
				ace200hRankingLines[j]  = ace200hRankingLines[j - 1];
				ace200hRankingYear[j]   = ace200hRankingYear[j - 1];
				ace200hRankingMonth[j]  = ace200hRankingMonth[j - 1];
				ace200hRankingDay[j]    = ace200hRankingDay[j - 1];
				ace200hRankingHour[j]   = ace200hRankingHour[j - 1];
				ace200hRankingMinute[j] = ace200hRankingMinute[j - 1];
				ace200hRankingSecond[j] = ace200hRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			ace200hRankingTime[i]   = gameTimer[player];
			ace200hRankingLines[i]  = ace200hLines[player];
			
			GetDateAndTime(&timebuf);
			ace200hRankingYear[i]   = timebuf[0];
			ace200hRankingMonth[i]  = timebuf[1];
			ace200hRankingDay[i]    = timebuf[2];
			ace200hRankingHour[i]   = timebuf[4];
			ace200hRankingMinute[i] = timebuf[5];
			ace200hRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void ace200hViewRanking(int player) {
	int i, erasemode;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE200-HELL MODE RANKING", 6);
		printFontGrid(1, 3, "RANK LINE TIME     DATE", 4);
		
		for(i = 0; i < 20; i++) {
			if(ace200hRankingLines[i] >= 200) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, 2, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 0);
			
			sprintf(string[0], "%d", ace200hRankingLines[i]);
			printFontGrid(6, 4 + i, string[0], 0);
			
			getTime(ace200hRankingTime[i]);
			printFontGrid(11, 4 + i, string[0], 0);
			
			sprintf(string[0], "%04d/%02d/%02d", ace200hRankingYear[i], ace200hRankingMonth[i], ace200hRankingDay[i]);
			printFontGrid(20, 4 + i, string[0], 0);
			
			sprintf(string[0], "%02d:%02d:%02d", ace200hRankingHour[i], ace200hRankingMinute[i], ace200hRankingSecond[i]);
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
				ace200hInitRanking();
				ace200hSaveRanking(player);
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
