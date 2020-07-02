//ACE200-HELL-X
//prefix:ace200hx

// レベルごとの制限時間
int ace200hxTimeLimit[20] =
{
	1800, 1800, 1800, 1800, 1800, 1500, 1500, 1500, 1500, 1500, 1200, 1200, 1200, 1020, 900, 1200, 1020, 900, 840, 840
};

// BGM関連
int ace200hxBgm = 0;								// 現在のBGM番号
int ace200hxBgmListTable[4]   = {3, 4, 17, 6};		// 使用するBGM
int ace200hxBgmFadeTable[3]   = {45, 145, 195};		// BGMがフェードアウトするライン
int ace200hxBgmChangeTable[3] = {50, 150, 10000};	// BGMを切り替えるライン

// 変数
int ace200hxModeNo = -1;		// モード番号
int ace200hxLines[2];			// ライン
int ace200hxLevel[2];			// レベル
int ace200hxTimer[2];			// 制限時間
int ace200hxEndFlag[2];			// 完全クリアフラグ

// 設定
int ace200hxIsBig = 0;			// BIGかどうか
int ace200hxBigMove = 1;		// BIG時の横移動単位
int ace200hxStartLevel = 0;		// スタート時のレベル

// ランキング用変数
int ace200hxRankingTime[20];	// タイム
int ace200hxRankingLines[20];	// ライン
int ace200hxRankingEnd[20];		// 完全クリアフラグ
int ace200hxRankingYear[20];	// ランクイン日時（年）
int ace200hxRankingMonth[20];	// ランクイン日時（月）
int ace200hxRankingDay[20];		// ランクイン日時（日）
int ace200hxRankingHour[20];	// ランクイン日時（時）
int ace200hxRankingMinute[20];	// ランクイン日時（分）
int ace200hxRankingSecond[20];	// ランクイン日時（秒）

// イベント発生
void ace200hxPluginEvent(int player, int event, int *param) {
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != ace200hxModeNo)) return;
	
	if(event == 0) {
		// モードを登録する
		ace200hxModeNo = addModePlugin("ACE200-HELL-X");
	} else if(event == 7) {
		if(!ending[player]) timeOn[player] = 1;	// ブロック出現と同時にタイマー再開
	} else if(event == 12) {
		if(!ending[player]) ace200hxLineErase(player, param[0]);	// ライン消去
	} else if(event == 15) {
		ace200hxViewScore(player);	// スコア表示
	} else if(event == 17) {
		ace200hxSetting(player, param);	// 設定画面
	} else if(event == 18) {
		ace200hxPlayerInitial(player);	// 初期化
	} else if(event == 21) {
		ace200hxResult(player);	// 結果表示
	} else if(event == 24) {
		ace200hxEndingStart(player);	// エンディング突入
	} else if(event == 25) {
		ace200hxExcellent(player, param);	// EXCELLENT画面
	} else if(event == 28) {
		ace200hxIncrementTime(player);	// 時間を進める
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		ace200hxSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		ace200hxLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		ace200hxLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		ace200hxReplayDetail(param[0]);	// リプレイ詳細
	}
}

// 初期化
void ace200hxPlayerInitial(int player) {
	// 枠の色を変える
	framecolor[player] = 2;
	frame_decoration[player] = 1;
	
	// []
	oblk_spawn[player] = 1;
	
	// 変数を初期化
	ace200hxLines[player] = ace200hxStartLevel * 10;
	ace200hxLevel[player] = ace200hxStartLevel;
	backno = ace200hxStartLevel;
	ace200hxEndFlag[player] = 0;
	
	// 初期BGMを設定
	ace200hxBgm = 0;
	while(ace200hxLines[player] >= ace200hxBgmChangeTable[ace200hxBgm]) ace200hxBgm++;
	bgmlv = ace200hxBgmListTable[ace200hxBgm];
	
	// 初期スピードを設定
	sp[player] = 1200;
	ace200hxTimer[player] = ace200hxTimeLimit[ace200hxLevel[player]];
	wait1[player] = 2;
	wait2[player] = 3;
	wait3[player] = 11;
	waitt[player] = 7;
	
	// 設定を反映させる
	IsBig[player] = ace200hxIsBig;
	BigMove[player] = ace200hxBigMove;
	
	// ギミック発動
	ace200hxStartGimmick(player);
}

// ライン消去
void ace200hxLineErase(int player, int lines) {
	// ライン数加算
	ace200hxLines[player] = ace200hxLines[player] + lines;
	
	// 全消し
	if(isBravo(player)) {
		PlaySE(se_levelup);
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
	}
	
	// BGMフェードアウト
	if((ace200hxLines[player] >= ace200hxBgmFadeTable[ace200hxBgm]) && (ace200hxLines[player] < ace200hxBgmChangeTable[ace200hxBgm]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// エンディング
	if(ace200hxLines[player] >= 200) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		ace200hxLines[player] = 200;
		ending[player] = 1;
		
		ace200hxEndFlag[player] = 1;
	}
	// レベルアップ
	else if(ace200hxLines[player] >= (ace200hxLevel[player] + 1) * 10) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		// スピードアップ
		ace200hxLevel[player]++;
		ace200hxTimer[player] = ace200hxTimeLimit[ace200hxLevel[player]];
		
		// 背景切り替え
		bgfadesw = 1;
		bgfadebg = ace200hxLevel[player];
		
		// 音楽切り替え
		if(ace200hxLines[player] >= ace200hxBgmChangeTable[ace200hxBgm]) {
			ace200hxBgm++;
			bgmlv = ace200hxBgmListTable[ace200hxBgm];
			PlayBGM();
		}
		
		// ギミック発動
		ace200hxStartGimmick(player);
	}
}

// ギミック発動
void ace200hxStartGimmick(int player) {
	if((ace200hxLevel[player] >= 5) && (ace200hxLevel[player] <= 14)) {
		hidden[player] = 8;
		shadowtime[player] = 150;
	} else if((ace200hxLevel[player] >= 15) && (ace200hxLevel[player] <= 18)) {
		hidden[player] = 8;
		shadowtime[player] = 120;
	} else if(ace200hxLevel[player] >= 19) {
		hidden[player] = 8;
		shadowtime[player] = 60;
	}
}

// スコア表示
void ace200hxViewScore(int player) {
	int color, color2;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// レベル
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "LEVEL");
	sprintf(string[0], "%d", ace200hxLevel[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// トータルタイム
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "TOTAL TIME");
	getTime(gameTimer[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// ノルマ（分子）
	ExBltRect(sg_smallfont, foffset[player] + 107, fyoffset[player] + 161, 0, 14, 22, 7);
	sprintf(string[0], "%4d", ace200hxLines[player]);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 169, string[0], color);
	
	// ノルマ（横線）
	ExBltRect(sg_spr, foffset[player] + 105, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 106, fyoffset[player] + 181, 22, 143, 22, 1);
	
	// ノルマ（分母）
	if(ending[player]) sprintf(string[0], "%4d", ace200hxLines[player]);
	else sprintf(string[0], "%4d", (ace200hxLevel[player] + 1) * 10);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 185, string[0], color);
	
	// 残り時間
	if((ace200hxTimer[player] <= 60 * 10) && (timeOn[player])) color2 = 2;
	else color2 = color;
	getTime(ace200hxTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
}

// エンディング突入
void ace200hxEndingStart(int player) {
	int i;
	
	for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	
	ending[player] = 2;
	stat[player] = 4;
	ending_timeOn[player] = 1;
	fastroll[player] = 0;
	
	hidden[player] = 10;
	
	bgmlv = ace200hxBgmListTable[3];
	PlayBGM();
}

// EXCELLENT画面
void ace200hxExcellent(int player, int *param) {
	param[0] = 1;
	onRecord[player] = 0;
	hidden[player] = 0;
	ace200hxEndFlag[player] = 2;
	
	// 花火
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// 時間を進める
void ace200hxIncrementTime(int player) {
	int i;
	
	if(timeOn[player]) {
		// 制限時間減少
		ace200hxTimer[player]--;
		
		// 時間切れ
		if(ace200hxTimer[player] <= 0) {
			PlaySE(se_timeover);
			ace200hxTimer[player] = 0;
			
			timeOn[player] = 0;
			onRecord[player] = 0;
			
			stat[player] = 7;
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		}
		// 残り10秒
		else if(ace200hxTimer[player] == 10 * 60) {
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
void ace200hxLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 4; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/4)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(ace200hxBgmListTable[i]);
		}
	}
}

// 結果表示
void ace200hxResult(int player) {
	// ランキング登録
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = ace200hxRegistRanking(player);
		if(statc[player * 10 + 1] != -1) ace200hxSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", ace200hxLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", ace200hxLevel[player] + 1);
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
void ace200hxSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(ace200hxLoadConfig() == 0) ace200hxSaveConfig();
	
	// ランキングを読み込み
	if(ace200hxLoadRanking(player) == 0) ace200hxInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE200-HELL-X OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",         7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",    7 * (cursor == 1));
		printFontGrid(2, 5, "START LEVEL", 7 * (cursor == 2));
		
		// 設定値表示
		if(!ace200hxIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!ace200hxBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "LV%d", ace200hxStartLevel + 1);
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
			if(cursor == 0) ace200hxIsBig = !ace200hxIsBig;
			if(cursor == 1) ace200hxBigMove = !ace200hxBigMove;
			if(cursor == 2) {
				ace200hxStartLevel = ace200hxStartLevel + move;
				if(ace200hxStartLevel < 0) ace200hxStartLevel = 19;
				if(ace200hxStartLevel > 19) ace200hxStartLevel = 0;
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
			ace200hxSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			ace200hxViewRanking(player);
		}
	}
}

// リプレイ保存
void ace200hxSaveReplay(int player) {
	saveBuf[900] = ace200hxIsBig;
	saveBuf[901] = ace200hxBigMove;
	saveBuf[902] = ace200hxLines[player];
	saveBuf[903] = ace200hxLevel[player];
	saveBuf[904] = ace200hxStartLevel;
}

// リプレイ読み込み
void ace200hxLoadReplay(int player) {
	ace200hxIsBig = saveBuf[900];
	ace200hxBigMove = saveBuf[901];
	ace200hxStartLevel = saveBuf[904];
	
	ace200hxPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void ace200hxReplayDetail(int number) {
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
void ace200hxSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// 設定内容
	saveBuf[1] = ace200hxIsBig;
	saveBuf[2] = ace200hxBigMove;
	saveBuf[3] = ace200hxStartLevel;
	
	SaveFile("config/ACE200_HELL_X_CONFIG.SAV", &saveBuf, 50 * 4);
}

// 設定を読み込み
int ace200hxLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/ACE200_HELL_X_CONFIG.SAV", &saveBuf, 50 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// 設定内容
	ace200hxIsBig = saveBuf[1];
	ace200hxBigMove = saveBuf[2];
	ace200hxStartLevel = saveBuf[3];
	
	return 1;
}

// ランキング保存
void ace200hxSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		saveBuf[1 + (i * 10) + 0] = ace200hxRankingTime[i];
		saveBuf[1 + (i * 10) + 1] = ace200hxRankingLines[i];
		saveBuf[1 + (i * 10) + 2] = ace200hxRankingEnd[i];
		saveBuf[1 + (i * 10) + 3] = ace200hxRankingYear[i];
		saveBuf[1 + (i * 10) + 4] = ace200hxRankingMonth[i];
		saveBuf[1 + (i * 10) + 5] = ace200hxRankingDay[i];
		saveBuf[1 + (i * 10) + 6] = ace200hxRankingHour[i];
		saveBuf[1 + (i * 10) + 7] = ace200hxRankingMinute[i];
		saveBuf[1 + (i * 10) + 8] = ace200hxRankingSecond[i];
	}
	
	sprintf(string[0], "config/ACE200_HELL_X_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 211 * 4);
}

// ランキング読み込み
int ace200hxLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/ACE200_HELL_X_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 211 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		ace200hxRankingTime[i]   = saveBuf[1 + (i * 10) + 0];
		ace200hxRankingLines[i]  = saveBuf[1 + (i * 10) + 1];
		ace200hxRankingEnd[i]    = saveBuf[1 + (i * 10) + 2];
		ace200hxRankingYear[i]   = saveBuf[1 + (i * 10) + 3];
		ace200hxRankingMonth[i]  = saveBuf[1 + (i * 10) + 4];
		ace200hxRankingDay[i]    = saveBuf[1 + (i * 10) + 5];
		ace200hxRankingHour[i]   = saveBuf[1 + (i * 10) + 6];
		ace200hxRankingMinute[i] = saveBuf[1 + (i * 10) + 7];
		ace200hxRankingSecond[i] = saveBuf[1 + (i * 10) + 8];
	}
}

// ランキング初期化
void ace200hxInitRanking() {
	int i;
	
	for(i = 0; i < 20; i++) {
		ace200hxRankingTime[i] = 0;
		ace200hxRankingLines[i] = 0;
		ace200hxRankingEnd[i] = 0;
		ace200hxRankingYear[i] = 0;
		ace200hxRankingMonth[i] = 0;
		ace200hxRankingDay[i] = 0;
		ace200hxRankingHour[i] = 0;
		ace200hxRankingMinute[i] = 0;
		ace200hxRankingSecond[i] = 0;
	}
}

// ランキング登録
int ace200hxRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (ace200hxStartLevel)) return -1;
	
	for(i = 0; i < 20; i++) {
		// ランクイン
		if((ace200hxEndFlag[player] > ace200hxRankingEnd[i]) || 
		   ((ace200hxEndFlag[player] == ace200hxRankingEnd[i]) && (ace200hxLines[player] > ace200hxRankingLines[i])) || 
		   ((ace200hxEndFlag[player] == ace200hxRankingEnd[i]) && (ace200hxLines[player] == ace200hxRankingLines[i]) && (gameTimer[player] < ace200hxRankingTime[i])))
		{
			// ランキングをずらす
			for(j = 19; j > i; j--) {
				ace200hxRankingTime[j]   = ace200hxRankingTime[j - 1];
				ace200hxRankingLines[j]  = ace200hxRankingLines[j - 1];
				ace200hxRankingEnd[j]    = ace200hxRankingEnd[j - 1];
				ace200hxRankingYear[j]   = ace200hxRankingYear[j - 1];
				ace200hxRankingMonth[j]  = ace200hxRankingMonth[j - 1];
				ace200hxRankingDay[j]    = ace200hxRankingDay[j - 1];
				ace200hxRankingHour[j]   = ace200hxRankingHour[j - 1];
				ace200hxRankingMinute[j] = ace200hxRankingMinute[j - 1];
				ace200hxRankingSecond[j] = ace200hxRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			ace200hxRankingTime[i]   = gameTimer[player];
			ace200hxRankingLines[i]  = ace200hxLines[player];
			ace200hxRankingEnd[i]    = ace200hxEndFlag[player];
			
			GetDateAndTime(&timebuf);
			ace200hxRankingYear[i]   = timebuf[0];
			ace200hxRankingMonth[i]  = timebuf[1];
			ace200hxRankingDay[i]    = timebuf[2];
			ace200hxRankingHour[i]   = timebuf[4];
			ace200hxRankingMinute[i] = timebuf[5];
			ace200hxRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void ace200hxViewRanking(int player) {
	int i, erasemode;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE200-HELL-X MODE RANKING", 6);
		printFontGrid(1, 3, "RANK LINE TIME     DATE", 4);
		
		for(i = 0; i < 20; i++) {
			if(ace200hxRankingEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (ace200hxRankingEnd[i] - 1) * 2, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 0);
			
			sprintf(string[0], "%d", ace200hxRankingLines[i]);
			printFontGrid(6, 4 + i, string[0], 0);
			
			getTime(ace200hxRankingTime[i]);
			printFontGrid(11, 4 + i, string[0], 0);
			
			sprintf(string[0], "%04d/%02d/%02d", ace200hxRankingYear[i], ace200hxRankingMonth[i], ace200hxRankingDay[i]);
			printFontGrid(20, 4 + i, string[0], 0);
			
			sprintf(string[0], "%02d:%02d:%02d", ace200hxRankingHour[i], ace200hxRankingMinute[i], ace200hxRankingSecond[i]);
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
				ace200hxInitRanking();
				ace200hxSaveRanking(player);
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
