//RHYTHM（実験中）
//prefix:rhy

// 変数
int rhyModeNo = -1;			// モード番号

int rhyPut[2];				// 置いたブロックの数
int rhyActiveTime[2];		// ブロックを操作している時間
int rhyGameSpeed[2];		// ゲームスピード

// 設定
int rhyIsBig = 0;			// BIG
int rhyBigMove = 1;			// BIG時の横移動単位
int rhyBgm = 4;				// BGM
int rhyWaitt = 8;			// 横溜め速度
int rhyAREType = 1;			// 1でARE長くなる

// ランキング用変数
int rhyRankingPut[10];		// 置いたブロックの数
int rhyRankingGameSpeed[10];// ゲームスピード
int rhyRankingWaitt[10];	// 横溜め速度
int rhyRankingTime[10];		// タイム
int rhyRankingYear[10];		// ランクイン日時（年）
int rhyRankingMonth[10];	// ランクイン日時（月）
int rhyRankingDay[10];		// ランクイン日時（日）
int rhyRankingHour[10];		// ランクイン日時（時）
int rhyRankingMinute[10];	// ランクイン日時（分）
int rhyRankingSecond[10];	// ランクイン日時（秒）

// イベント発生
void rhyPluginEvent(int player, int event, int *param) {
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != rhyModeNo)) return;
	
	if(event == 0) {
		rhyModeNo = addModePlugin("RHYTHM");	// モードを登録する
	} else if(event == 8) {
		rhyMoveMain(player, param);	// ブロック移動中の処理
	} else if(event == 10) {
		rhyARE(player, param);	// ARE中の処理
	} else if(event == 15) {
		rhyViewScore(player);	// スコア表示
	} else if(event == 17) {
		rhySetting(player, param);	// 設定画面
	} else if(event == 18) {
		rhyPlayerInitial(player);	// 初期化
	} else if(event == 21) {
		rhyResult(player);	// 結果
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		rhySaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		rhyLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		rhyLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		rhyReplayDetail();	// リプレイ詳細
	}
}

// 初期化
void rhyPlayerInitial(int player) {
	rhyPut[player] = 0;
	rhyActiveTime[player] = 0;
	rhyGameSpeed[player] = 60;
	
	sp[player] = 1200;
	wait1[player] = 0;
	wait2[player] = 0;
	wait3[player] = 99;
	waitt[player] = rhyWaitt;
	
	IsBig[player] = rhyIsBig;
	BigMove[player] = rhyBigMove;
	bgmlv = rhyBgm;
}

// ブロック移動中の処理
void rhyMoveMain(int player, int *param) {
	rhyActiveTime[player]++;
	
	if(rhyActiveTime[player] >= rhyGameSpeed[player]) {
		param[0] = 1;	// 通常の処理をスキップする
		blockLock(player);	// 強制固定
		if(rhyAREType) rhyActiveTime[player] = 0;	// ブロック操作時間リセット
	}
}

// ARE中の処理
void rhyARE(int player, int *param) {
	statc[player * 10] = 1;	// 時間になるまでARE継続
	rhyActiveTime[player]++;	// ブロック操作時間+1
	
	// ARE終了
	if(rhyActiveTime[player] >= rhyGameSpeed[player]) {
		rhyActiveTime[player] = 0;
		
		rhyPut[player]++;
		if((rhyPut[player] % 6 == 0) && (rhyGameSpeed[player] > 1)) {
			rhyGameSpeed[player]--;
			if(rhyGameSpeed[player] % 3 == 0) {
				bgfadesw = 1;
				bgfadebg = backno + 1;
			}
			PlaySE(se_levelup);
		}
		
		statc[player * 10] = -1;
	}
}

// スコア表示
void rhyViewScore(int player) {
	int color;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// ゲームスピード
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "GAME SPEED");
	sprintf(string[0], "%d", rhyGameSpeed[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// ブロックを操作できる時間
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "ACTIVE TIME");
	if(rhyGameSpeed[player] - rhyActiveTime[player] >= 0)
		sprintf(string[0], "%d", rhyGameSpeed[player] - rhyActiveTime[player]);
	else
		sprintf(string[0], "%d", 0);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// 置いたブロック数
	printTinyFont(foffset[player] + 96, fyoffset[player] + 76, "BLOCK");
	sprintf(string[0], "%d", rhyPut[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 84, string[0], color);
	
	// 時間
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
}

// 結果表示
void rhyResult(int player) {
	// ランキング登録
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = rhyRegistRanking(player);
		if(statc[player * 10 + 1] != -1) rhySaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "BLOCK");
	sprintf(string[0], "%13d", rhyPut[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "GAME SPEED");
	sprintf(string[0], "%13d", rhyGameSpeed[player]);
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
void rhyLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(rhyBgm);
	}
}

// リプレイ保存
void rhySaveReplay(int player) {
	saveBuf[900] = rhyPut[player];
	saveBuf[901] = rhyGameSpeed[player];
	saveBuf[902] = rhyIsBig;
	saveBuf[903] = rhyBigMove;
	saveBuf[904] = rhyBgm;
	saveBuf[905] = rhyWaitt;
	saveBuf[906] = rhyAREType;
}

// リプレイ読み込み
void rhyLoadReplay(int player) {
	rhyPut[player] = saveBuf[900];
	rhyGameSpeed[player] = saveBuf[901];
	rhyIsBig = saveBuf[902];
	rhyBigMove = saveBuf[903];
	rhyBgm = saveBuf[904];
	rhyWaitt = saveBuf[905];
	rhyAREType = saveBuf[906];
	
	rhyPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void rhyReplayDetail() {
	printFontGrid(1, 5, "BLOCK", 0);
	sprintf(string[0], "%d", saveBuf[900]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "GAME SPEED", 0);
	sprintf(string[0], "%d", saveBuf[901]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 8, "BIG", 0);
	if(!saveBuf[902]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "BIG MOVE", 0);
	if(!saveBuf[903]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "BGM", 0);
	sprintf(string[0], "%d", saveBuf[904]);
	printFontGrid(22, 10, string[0], 0);
	
	if(!english) printFontGrid(1, 11, "YOKOTAME", 0);
	else printFontGrid(1, 11, "DAS", 0);
	sprintf(string[0], "%d", saveBuf[905]);
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "AFTER AUTO-LOCK", 0);
	if(!saveBuf[906]) sprintf(string[0], "NO ARE");
	else sprintf(string[0], "LONG ARE");
	printFontGrid(22, 12, string[0], 0);
}

// 設定画面
void rhySetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(rhyLoadConfig() == 0) rhySaveConfig();
	
	// ランキングを読み込み
	if(rhyLoadRanking(player) == 0) rhyInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "RHYTHM OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",          7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",     7 * (cursor == 1));
		printFontGrid(2, 5, "BGM",          7 * (cursor == 2));
		if(!english) printFontGrid(2, 6, "YOKOTAME", 7 * (cursor == 3));
		else printFontGrid(2, 6, "DAS", 7 * (cursor == 3));
		printFontGrid(2, 7, "AFTER AUTO-LOCK", 7 * (cursor == 4));
		
		// 設定値表示
		if(!rhyIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!rhyBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "%d", rhyBgm);
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "%d", rhyWaitt);
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(!rhyAREType) sprintf(string[0], "NO ARE");
		else sprintf(string[0], "LONG ARE");
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		// カーソル移動
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 4;
			if(cursor > 4) cursor = 0;
		}
		
		// 値を変更
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) rhyIsBig = !rhyIsBig;
			if(cursor == 1) rhyBigMove = !rhyBigMove;
			if(cursor == 2) {
				rhyBgm = rhyBgm + move;
				if(rhyBgm < 0) rhyBgm = 29;
				if(rhyBgm > 29) rhyBgm = 0;
			}
			if(cursor == 3) {
				rhyWaitt = rhyWaitt + move;
				if(rhyWaitt < 0) rhyWaitt = 99;
				if(rhyWaitt > 99) rhyWaitt = 0;
			}
			if(cursor == 4) rhyAREType = !rhyAREType;
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
			rhySaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			rhyViewRanking(player);
		}
	}
}

// 設定を保存
void rhySaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// 設定内容
	saveBuf[1] = rhyIsBig;
	saveBuf[2] = rhyBigMove;
	saveBuf[3] = rhyBgm;
	saveBuf[4] = rhyWaitt;
	saveBuf[5] = rhyAREType;
	
	SaveFile("config/RHYTHM_CONFIG.SAV", &saveBuf, 50 * 4);
}

// 設定を読み込み
int rhyLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/RHYTHM_CONFIG.SAV", &saveBuf, 50 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// 設定内容
	rhyIsBig = saveBuf[1];
	rhyBigMove = saveBuf[2];
	rhyBgm = saveBuf[3];
	rhyWaitt = saveBuf[4];
	rhyAREType = saveBuf[5];
	
	return 1;
}

// ランキング保存
void rhySaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0] = rhyRankingPut[i];
		saveBuf[1 + (i * 20) + 1] = rhyRankingGameSpeed[i];
		saveBuf[1 + (i * 20) + 2] = rhyRankingWaitt[i];
		saveBuf[1 + (i * 20) + 3] = rhyRankingTime[i];
		saveBuf[1 + (i * 20) + 4] = rhyRankingYear[i];
		saveBuf[1 + (i * 20) + 5] = rhyRankingMonth[i];
		saveBuf[1 + (i * 20) + 6] = rhyRankingDay[i];
		saveBuf[1 + (i * 20) + 7] = rhyRankingHour[i];
		saveBuf[1 + (i * 20) + 8] = rhyRankingMinute[i];
		saveBuf[1 + (i * 20) + 9] = rhyRankingSecond[i];
	}
	
	sprintf(string[0], "config/RHYTHM_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 221 * 4);
}

// ランキング読み込み
int rhyLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/RHYTHM_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 221 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 10; i++) {
		rhyRankingPut[i]       = saveBuf[1 + (i * 20) + 0];
		rhyRankingGameSpeed[i] = saveBuf[1 + (i * 20) + 1];
		rhyRankingWaitt[i]     = saveBuf[1 + (i * 20) + 2];
		rhyRankingTime[i]      = saveBuf[1 + (i * 20) + 3];
		rhyRankingYear[i]      = saveBuf[1 + (i * 20) + 4];
		rhyRankingMonth[i]     = saveBuf[1 + (i * 20) + 5];
		rhyRankingDay[i]       = saveBuf[1 + (i * 20) + 6];
		rhyRankingHour[i]      = saveBuf[1 + (i * 20) + 7];
		rhyRankingMinute[i]    = saveBuf[1 + (i * 20) + 8];
		rhyRankingSecond[i]    = saveBuf[1 + (i * 20) + 9];
	}
	
	return 1;
}

// ランキング初期化
void rhyInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		rhyRankingPut[i]       = 0;
		rhyRankingGameSpeed[i] = 0;
		rhyRankingWaitt[i]     = 0;
		rhyRankingTime[i]      = 0;
		rhyRankingYear[i]      = 0;
		rhyRankingMonth[i]     = 0;
		rhyRankingDay[i]       = 0;
		rhyRankingHour[i]      = 0;
		rhyRankingMinute[i]    = 0;
		rhyRankingSecond[i]    = 0;
	}
}

// ランキング登録
int rhyRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (rhyIsBig)) return -1;
	
	for(i = 0; i < 10; i++) {
		// ランクイン
		if(rhyPut[player] > rhyRankingPut[i]) {
			// ランキングをずらす
			for(j = 9; j > i; j--) {
				rhyRankingPut[j]       = rhyRankingPut[j - 1];
				rhyRankingGameSpeed[j] = rhyRankingGameSpeed[j - 1];
				rhyRankingWaitt[j]     = rhyRankingWaitt[j - 1];
				rhyRankingTime[j]      = rhyRankingTime[j - 1];
				rhyRankingYear[j]      = rhyRankingYear[j - 1];
				rhyRankingMonth[j]     = rhyRankingMonth[j - 1];
				rhyRankingDay[j]       = rhyRankingDay[j - 1];
				rhyRankingHour[j]      = rhyRankingHour[j - 1];
				rhyRankingMinute[j]    = rhyRankingMinute[j - 1];
				rhyRankingSecond[j]    = rhyRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			rhyRankingPut[i]       = rhyPut[player];
			rhyRankingGameSpeed[i] = rhyGameSpeed[player];
			rhyRankingWaitt[i]     = rhyWaitt;
			rhyRankingTime[i]      = gameTimer[player];
			
			GetDateAndTime(&timebuf);
			rhyRankingYear[i]    = timebuf[0];
			rhyRankingMonth[i]   = timebuf[1];
			rhyRankingDay[i]     = timebuf[2];
			rhyRankingHour[i]    = timebuf[4];
			rhyRankingMinute[i]  = timebuf[5];
			rhyRankingSecond[i]  = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void rhyViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "RHYTHM MODE RANKING", 6);
		printFontGrid(1, 3, "RANK BLOCK    SPEED DAS   TIME", 4);
		
		for(i = 0; i < 10; i++) {
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", rhyRankingPut[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", rhyRankingGameSpeed[i]);
			printFontGrid(15, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", rhyRankingWaitt[i]);
			printFontGrid(21, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(rhyRankingTime[i]);
			printFontGrid(27, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// 日付と時刻
			sprintf(string[0],
			        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
			        rhyRankingYear[cursor], rhyRankingMonth[cursor], rhyRankingDay[cursor],
			        rhyRankingHour[cursor], rhyRankingMinute[cursor], rhyRankingSecond[cursor]);
			printFontGrid(1, 26, string[0], 0);
			
			printFontGrid(1, 28, "A/B:EXIT F:ERASE ALL", 6);
			
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
				rhyInitRanking();
				rhySaveRanking(player);
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
