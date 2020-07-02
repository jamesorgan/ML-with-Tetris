//ACE-ANOTHER2
//prefix:acea2

// LITE版ベース

// 使用するBGM
int acea2BgmToUse = 4;

// 変数
int acea2ModeNo = -1;		// モード番号
int acea2Lines[2];			// ライン
int acea2Level[2];			// レベル
int acea2Timer[2];			// 制限時間

// 設定
int acea2IsBig = 0;			// BIGかどうか
int acea2BigMove = 1;		// BIG時の横移動単位
int acea2StartLevel = 0;	// スタート時のレベル

// ランキング用変数
int acea2RankingTime[20];	// タイム
int acea2RankingLines[20];	// ライン
int acea2RankingYear[20];	// ランクイン日時（年）
int acea2RankingMonth[20];	// ランクイン日時（月）
int acea2RankingDay[20];	// ランクイン日時（日）
int acea2RankingHour[20];	// ランクイン日時（時）
int acea2RankingMinute[20];	// ランクイン日時（分）
int acea2RankingSecond[20];	// ランクイン日時（秒）

// イベント発生
void acea2PluginEvent(int player, int event, int *param) {
	int i;
	
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != acea2ModeNo)) return;
	
	if(event == 0) {
		// モードを登録する
		acea2ModeNo = addModePlugin("ACE-ANOTHER2");
	} else if(event == 7) {
		timeOn[player] = 1;	// ブロック出現と同時にタイマー再開
	} else if(event == 12) {
		acea2LineErase(player, param[0]);	// ライン消去
	} else if(event == 15) {
		acea2ViewScore(player);	// スコア表示
	} else if(event == 17) {
		acea2Setting(player, param);	// 設定画面
	} else if(event == 18) {
		acea2PlayerInitial(player);	// 初期化
	} else if(event == 21) {
		acea2Result(player);	// 結果表示
	} else if(event == 24) {
		ending[player] = 3;	// エンディング突入
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		acea2Excellent(player, param);	// EXCELLENT画面
	} else if(event == 28) {
		acea2IncrementTime(player);	// 時間を進める
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		acea2SaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		acea2LoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		acea2LoadBGM();	// BGM読み込み
	} else if(event == 55) {
		acea2ReplayDetail(param[0]);	// リプレイ詳細
	}
}

// 初期化
void acea2PlayerInitial(int player) {
	// 枠の色を灰色にする
	framecolor[player] = 5;
	frame_decoration[player] = 1;
	
	// 変数を初期化
	acea2Lines[player] = acea2StartLevel * 10;
	acea2Level[player] = acea2StartLevel;
	backno = acea2StartLevel;
	
	// 初期BGMを設定
	bgmlv = acea2BgmToUse;
	
	// 初期スピードを設定
	sp[player] = 1200;
	wait1[player] = 6;
	wait2[player] = 4;
	wait3[player] = 13;
	waitt[player] = 7;
	acea2Timer[player] = 3600;
	
	// 設定を反映させる
	IsBig[player] = acea2IsBig;
	BigMove[player] = acea2BigMove;
}

// ライン消去
void acea2LineErase(int player, int lines) {
	// ライン数加算
	acea2Lines[player] = acea2Lines[player] + lines;
	
	// 全消し
	if(isBravo(player)) {
		PlaySE(se_levelup);
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
	}
	
	// BGMフェードアウト
	if((acea2Lines[player] >= 145) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// エンディング
	if(acea2Lines[player] >= 150) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		acea2Lines[player] = 150;
		ending[player] = 1;
	}
	// レベルアップ
	else if(acea2Lines[player] >= (acea2Level[player] + 1) * 10) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		// スピードアップ
		acea2Level[player]++;
		acea2Timer[player] = 3600;
		
		// 背景切り替え
		bgfadesw = 1;
		bgfadebg = acea2Level[player];
	}
}

// スコア表示
void acea2ViewScore(int player) {
	int color, color2;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// レベル
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "LEVEL");
	sprintf(string[0], "%d", acea2Level[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// トータルタイム
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "TOTAL TIME");
	getTime(gameTimer[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// ベストタイム
	if((!playback) && (!IsBig[player]) && (!acea2StartLevel)) {
		printTinyFont(foffset[player] + 96, fyoffset[player] + 76, "BEST TIME");
		if(acea2RankingLines[0] >= 150) getTime(acea2RankingTime[0]);
		else getTime(0);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 84, string[0], color);
	}
	
	// ノルマ（分子）
	ExBltRect(sg_smallfont, foffset[player] + 107, fyoffset[player] + 161, 0, 14, 22, 7);
	sprintf(string[0], "%4d", acea2Lines[player]);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 169, string[0], color);
	
	// ノルマ（横線）
	ExBltRect(sg_spr, foffset[player] + 105, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 106, fyoffset[player] + 181, 22, 143, 22, 1);
	
	// ノルマ（分母）
	if(ending[player]) sprintf(string[0], "%4d", acea2Lines[player]);
	else sprintf(string[0], "%4d", (acea2Level[player] + 1) * 10);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 185, string[0], color);
	
	// 残り時間
	if((acea2Timer[player] <= 60 * 10) && (timeOn[player])) color2 = 2;
	else color2 = color;
	getTime(acea2Timer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
}

// EXCELLENT画面
void acea2Excellent(int player, int *param) {
	param[0] = 3;
	onRecord[player] = 0;
	
	// 花火
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// 時間を進める
void acea2IncrementTime(int player) {
	int i;
	
	if(timeOn[player]) {
		// 制限時間減少
		acea2Timer[player]--;
		
		// 時間切れ
		if(acea2Timer[player] <= 0) {
			PlaySE(se_timeover);
			acea2Timer[player] = 0;
			
			timeOn[player] = 0;
			onRecord[player] = 0;
			
			stat[player] = 7;
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		}
		// 残り10秒
		else if(acea2Timer[player] == 10 * 60) {
			PlaySE(se_hurryup);
		}
	}
}

// BGM読み込み
void acea2LoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(acea2BgmToUse);
	}
}

// 結果表示
void acea2Result(int player) {
	// ランキング登録
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = acea2RegistRanking(player);
		if(statc[player * 10 + 1] != -1) acea2SaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", acea2Lines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", acea2Level[player] + 1);
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
void acea2Setting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(acea2LoadConfig() == 0) acea2SaveConfig();
	
	// ランキングを読み込み
	if(acea2LoadRanking(player) == 0) acea2InitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE-ANOTHER2 OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",         7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",    7 * (cursor == 1));
		printFontGrid(2, 5, "START LEVEL", 7 * (cursor == 2));
		
		// 設定値表示
		if(!acea2IsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!acea2BigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "LV%d", acea2StartLevel + 1);
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
			if(cursor == 0) acea2IsBig = !acea2IsBig;
			if(cursor == 1) acea2BigMove = !acea2BigMove;
			if(cursor == 2) {
				acea2StartLevel = acea2StartLevel + move;
				if(acea2StartLevel < 0) acea2StartLevel = 14;
				if(acea2StartLevel > 14) acea2StartLevel = 0;
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
			acea2SaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			acea2ViewRanking(player);
		}
	}
}

// リプレイ保存
void acea2SaveReplay(int player) {
	saveBuf[900] = acea2IsBig;
	saveBuf[901] = acea2BigMove;
	saveBuf[902] = acea2Lines[player];
	saveBuf[903] = acea2Level[player];
	saveBuf[904] = acea2StartLevel;
}

// リプレイ読み込み
void acea2LoadReplay(int player) {
	acea2IsBig = saveBuf[900];
	acea2BigMove = saveBuf[901];
	acea2StartLevel = saveBuf[904];
	
	acea2PlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void acea2ReplayDetail(int number) {
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
void acea2SaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x41454341;
	saveBuf[3] = 0x31657632;
	
	// 設定内容
	saveBuf[4] = acea2IsBig;
	saveBuf[5] = acea2BigMove;
	saveBuf[6] = acea2StartLevel;
	
	SaveFile("config/ACE_ANOTHER2_CONFIG.SAV", &saveBuf, 100 * 4);
}

// 設定を読み込み
int acea2LoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/ACE_ANOTHER2_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x41454341) return 0;
	if(saveBuf[3] != 0x31657632) return 0;
	
	// 設定内容
	acea2IsBig = saveBuf[4];
	acea2BigMove = saveBuf[5];
	acea2StartLevel = saveBuf[6];
	
	return 1;
}

// ランキング保存
void acea2SaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		saveBuf[1 + (i * 10) + 0] = acea2RankingTime[i];
		saveBuf[1 + (i * 10) + 1] = acea2RankingLines[i];
		saveBuf[1 + (i * 10) + 2] = acea2RankingYear[i];
		saveBuf[1 + (i * 10) + 3] = acea2RankingMonth[i];
		saveBuf[1 + (i * 10) + 4] = acea2RankingDay[i];
		saveBuf[1 + (i * 10) + 5] = acea2RankingHour[i];
		saveBuf[1 + (i * 10) + 6] = acea2RankingMinute[i];
		saveBuf[1 + (i * 10) + 7] = acea2RankingSecond[i];
	}
	
	sprintf(string[0], "config/ACE_ANOTHER2_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 211 * 4);
}

// ランキング読み込み
int acea2LoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/ACE_ANOTHER2_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 211 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		acea2RankingTime[i]   = saveBuf[1 + (i * 10) + 0];
		acea2RankingLines[i]  = saveBuf[1 + (i * 10) + 1];
		acea2RankingYear[i]   = saveBuf[1 + (i * 10) + 2];
		acea2RankingMonth[i]  = saveBuf[1 + (i * 10) + 3];
		acea2RankingDay[i]    = saveBuf[1 + (i * 10) + 4];
		acea2RankingHour[i]   = saveBuf[1 + (i * 10) + 5];
		acea2RankingMinute[i] = saveBuf[1 + (i * 10) + 6];
		acea2RankingSecond[i] = saveBuf[1 + (i * 10) + 7];
	}
}

// ランキング初期化
void acea2InitRanking() {
	int i;
	
	for(i = 0; i < 20; i++) {
		acea2RankingTime[i] = 0;
		acea2RankingLines[i] = 0;
		acea2RankingYear[i] = 0;
		acea2RankingMonth[i] = 0;
		acea2RankingDay[i] = 0;
		acea2RankingHour[i] = 0;
		acea2RankingMinute[i] = 0;
		acea2RankingSecond[i] = 0;
	}
}

// ランキング登録
int acea2RegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (acea2StartLevel)) return -1;
	
	for(i = 0; i < 20; i++) {
		// ランクイン
		if((acea2Lines[player] > acea2RankingLines[i]) || 
		   ((acea2Lines[player] == acea2RankingLines[i]) && (gameTimer[player] < acea2RankingTime[i])))
		{
			// ランキングをずらす
			for(j = 19; j > i; j--) {
				acea2RankingTime[j]   = acea2RankingTime[j - 1];
				acea2RankingLines[j]  = acea2RankingLines[j - 1];
				acea2RankingYear[j]   = acea2RankingYear[j - 1];
				acea2RankingMonth[j]  = acea2RankingMonth[j - 1];
				acea2RankingDay[j]    = acea2RankingDay[j - 1];
				acea2RankingHour[j]   = acea2RankingHour[j - 1];
				acea2RankingMinute[j] = acea2RankingMinute[j - 1];
				acea2RankingSecond[j] = acea2RankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			acea2RankingTime[i]   = gameTimer[player];
			acea2RankingLines[i]  = acea2Lines[player];
			
			GetDateAndTime(&timebuf);
			acea2RankingYear[i]   = timebuf[0];
			acea2RankingMonth[i]  = timebuf[1];
			acea2RankingDay[i]    = timebuf[2];
			acea2RankingHour[i]   = timebuf[4];
			acea2RankingMinute[i] = timebuf[5];
			acea2RankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void acea2ViewRanking(int player) {
	int i, erasemode;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE-ANOTHER2 MODE RANKING", 6);
		printFontGrid(1, 3, "RANK LINE TIME     DATE", 4);
		
		for(i = 0; i < 20; i++) {
			if(acea2RankingLines[i] >= 150) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, 2, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 0);
			
			sprintf(string[0], "%d", acea2RankingLines[i]);
			printFontGrid(6, 4 + i, string[0], 0);
			
			getTime(acea2RankingTime[i]);
			printFontGrid(11, 4 + i, string[0], 0);
			
			sprintf(string[0], "%04d/%02d/%02d", acea2RankingYear[i], acea2RankingMonth[i], acea2RankingDay[i]);
			printFontGrid(20, 4 + i, string[0], 0);
			
			sprintf(string[0], "%02d:%02d:%02d", acea2RankingHour[i], acea2RankingMinute[i], acea2RankingSecond[i]);
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
				acea2InitRanking();
				acea2SaveRanking(player);
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
