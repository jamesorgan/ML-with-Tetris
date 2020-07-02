//ORIGINAL-DEVIL
//prefix:odvl

// レベルアップテーブル
// フレーム関連の処理を大幅に変えたので、本家と微妙にタイミングが違うかも…
int odvlWait1[11] =
{
	18, 16, 14, 12, 10,  9,  8,  8,  7,  6,  5
};
int odvlWait2[11] =
{
	13, 11, 10,  9,  8,  7,  7,  6,  6,  5,  5
};
int odvlWait3[11] =
{
	28, 26, 25, 23, 20, 16, 15, 14, 13, 13, 13
};
int odvlWaitt[11] =
{
	10, 10, 10,  9,  9,  9,  9,  8,  7,  7,  7
};

// 変数
int odvlModeNo = -1;		// モード番号
int odvlScore[2];			// スコア
int odvlRate[2];			// コンボボーナス用変数
int odvlLines[2];			// ライン
int odvlLevel[2];			// レベル
int odvlLc[2];				// レベルアップまでのカウンタ
int odvlLvUpAnim[2];		// レベルアップ直後、数字を点滅させる時間

int odvlIsBig = 0;			// BIGかどうか
int odvlBigMove = 1;		// BIG時の横移動単位
int odvlStartLevel = 0;		// 開始レベル
int odvlBgm = 2;			// 使用するBGM

// ランキング用変数
int odvlRankingScore[10];	// スコア
int odvlRankingLines[10];	// ライン
int odvlRankingLevel[10];	// レベル
int odvlRankingTime[10];	// タイム
int odvlRankingYear[10];	// ランクイン日時（年）
int odvlRankingMonth[10];	// ランクイン日時（月）
int odvlRankingDay[10];		// ランクイン日時（日）
int odvlRankingHour[10];	// ランクイン日時（時）
int odvlRankingMinute[10];	// ランクイン日時（分）
int odvlRankingSecond[10];	// ランクイン日時（秒）

// イベント発生
void odvlPluginEvent(int player, int event, int *param) {
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != odvlModeNo)) return;
	
	if(event == 0) {
		odvlModeNo = addModePlugin("ORIGINAL-DEVIL");	// モードを登録する
	} else if(event == 10) {
		odvlARE(player);	// ARE中
	} else if(event == 13) {
		odvlCalcScore(player, param[0]);	// スコア計算
	} else if(event == 15) {
		odvlViewScore(player);	// スコア表示
	} else if(event == 17) {
		odvlSetting(player, param);	// 設定画面
	} else if(event == 18) {
		odvlPlayerInitial(player);	// 初期化
	} else if(event == 21) {
		odvlResult(player);	// 結果表示
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		odvlSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		odvlLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		odvlLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		odvlReplayDetail();	// リプレイ詳細
	}
}

// 初期化
void odvlPlayerInitial(int player) {
	// 変数を初期化
	odvlScore[player] = 0;
	odvlRate[player] = 0;
	odvlLines[player] = 0;
	odvlLevel[player] = odvlStartLevel;
	odvlLc[player] = 0;
	odvlLvUpAnim[player] = 0;
	
	// コンボ有効
	enable_combo[player] = 1;
	
	// 枠の色を変える
	framecolor[player] = 9;
	
	// 初期速度
	odvlChangeSpeed(player);
	backno = odvlLevel[player] / 3;
	if(backno > 19) backno = 19;
	
	// 設定を反映させる
	IsBig[player] = odvlIsBig;
	BigMove[player] = odvlBigMove;
	bgmlv = odvlBgm;
}

// ARE中
void odvlARE(int player) {
	// レベルカウンタ＋１
	if(statc[player * 10] == wait1[player] - lockflash[player]) odvlLc[player]++;
	
	// レベルアップ判定
	if(odvlLc[player] > 100) {
		odvlLc[player] = odvlLc[player] - 100;
		
		odvlLevel[player]++;
		odvlLvUpAnim[player] = 180;
		
		odvlChangeSpeed(player);
		
		if(odvlLevel[player] % 3 == 0) {
			PlaySE(se_levelup);
			
			if(odvlLevel[player] / 3 < 20) {
				bgfadesw = 1;
				bgfadebg = odvlLevel[player] / 3;
			}
		}
	}
}

// スピードを変える
void odvlChangeSpeed(int player) {
	int temp;
	
	sp[player] = 1200;
	temp = odvlLevel[player] / 3;
	if(temp > 10) temp = 10;
	wait1[player] = odvlWait1[temp] + 3;
	wait2[player] = odvlWait2[temp];
	wait3[player] = odvlWait3[temp] + 2;
	waitt[player] = odvlWaitt[temp];
}

// スコア計算
void odvlCalcScore(int player, int lines) {
	int bo, bai, all;
	
	// 基本点
	if(combo[player] == 1) odvlRate[player] = 100;
	
	if(lines == 1) {
		bo = 1 * odvlRate[player];
		odvlRate[player] = odvlRate[player] + 5;
	}
	if(lines == 2) {
		bo = 4 * odvlRate[player];
		odvlRate[player] = odvlRate[player] + 10;
	}
	if(lines == 3) {
		bo = 9 * odvlRate[player];
		odvlRate[player] = odvlRate[player] + 30;
	}
	if(lines == 4) {
		bo = 20 * odvlRate[player];
		odvlRate[player] = odvlRate[player] + 50;
	}
	
	// 速度によるボーナス
	bai = 1 + (sp[player] >= 20) + (sp[player] >= 60) + (sp[player] >= 240) + (sp[player] >= 640);
	
	// 全消しするとスコア10倍
	if(isBravo(player)) {
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		bo = bo * 10;
	}
	
	// スコア加算
	odvlScore[player] = odvlScore[player] + bo * bai;
	odvlLines[player] = odvlLines[player] + lines;
	odvlLc[player] = odvlLc[player] + lines * 20;
}

// スコア表示
void odvlViewScore(int player) {
	int color, color2;
	color = (count % 4 / 2) * (sp[player] >= 1200) * 2;
	
	// スコア
	printFont(foffset[player] + 96, fyoffset[player] + 40, "SCORE", 2);
	if(odvlScore[player] > 9999999) odvlScore[player] = 9999999;
	sprintf(string[0], "%d", odvlScore[player]);
	printFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// ライン
	printFont(foffset[player] + 96, fyoffset[player] + 64, "LINES", 2);
	if(odvlLines[player] > 9999) odvlLines[player] = 9999;
	sprintf(string[0], "%d", odvlLines[player]);
	printFont(foffset[player] + 96, fyoffset[player] + 72, string[0], color);
	
	// レベル
	printFont(foffset[player] + 96, fyoffset[player] + 88, "LEVEL", 2);
	if(odvlLevel[player] > 999) odvlLevel[player] = 999;
	sprintf(string[0], "%d", odvlLevel[player]);
	if(!odvlLvUpAnim[player]) {
		color2 = color;
	} else {
		color2 = 7 * (count % 4 / 2);
		odvlLvUpAnim[player]--;
	}
	printFont(foffset[player] + 96, fyoffset[player] + 96, string[0], color2);
	
	// タイム
	if(gameTimer[player] > 359999) gameTimer[player] = 359999;
	getTime(gameTimer[player]);
	printFont(foffset[player] + 16, fyoffset[player] + 224, string[0], color);
}

// 結果表示
void odvlResult(int player) {
	// ランキング登録
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = odvlRegistRanking(player);
		if(statc[player * 10 + 1] != -1) odvlSaveRanking(player);
	}
	
	printFont(foffset[player] + 8, fyoffset[player] + 48, "PLAY DATA", 4);
	
	// スコア
	printFont(foffset[player] + 8, fyoffset[player] + 64, "SCORE", 2);
	sprintf(string[0], "%10d", odvlScore[player]);
	printFont(foffset[player] + 8, fyoffset[player] + 72, string[0], 0);
	
	// ライン
	printFont(foffset[player] + 8, fyoffset[player] + 88, "LINES", 2);
	sprintf(string[0], "%10d", odvlLines[player]);
	printFont(foffset[player] + 8, fyoffset[player] + 96, string[0], 0);
	
	// レベル
	printFont(foffset[player] + 8, fyoffset[player] + 112, "LEVEL", 2);
	sprintf(string[0], "%10d", odvlLevel[player]);
	printFont(foffset[player] + 8, fyoffset[player] + 120, string[0], 0);
	
	// タイム
	printFont(foffset[player] + 8, fyoffset[player] + 136, "TIME", 2);
	getTime(gameTimer[player]);
	printFont(foffset[player] + 24, fyoffset[player] + 144, string[0], 0);
	
	// ランキング順位
	if(statc[player * 10 + 1] != -1) {
		printFont(foffset[player] + 8, fyoffset[player] + 160, "RANK", 2);
		sprintf(string[0], "%10d", statc[player * 10 + 1] + 1);
		printFont(foffset[player] + 8, fyoffset[player] + 168, string[0], 0);
	}
}

// BGM読み込み
void odvlLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(odvlBgm);
	}
}

// 設定画面
void odvlSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(odvlLoadConfig() == 0) odvlSaveConfig();
	
	// ランキングを読み込み
	if(odvlLoadRanking(player) == 0) odvlInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ORIGINAL-DEVIL OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",         7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",    7 * (cursor == 1));
		printFontGrid(2, 5, "START LEVEL", 7 * (cursor == 2));
		printFontGrid(2, 6, "BGM",         7 * (cursor == 3));
		
		// 設定値表示
		if(!odvlIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!odvlBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "%d", odvlStartLevel);
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "%d", odvlBgm);
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
			if(cursor == 0) odvlIsBig = !odvlIsBig;
			if(cursor == 1) odvlBigMove = !odvlBigMove;
			if(cursor == 2) {
				odvlStartLevel = odvlStartLevel + move;
				if(odvlStartLevel < 0) odvlStartLevel = 30;
				if(odvlStartLevel > 30) odvlStartLevel = 0;
			}
			if(cursor == 3) {
				odvlBgm = odvlBgm + move;
				if(odvlBgm < 0) odvlBgm = 29;
				if(odvlBgm > 29) odvlBgm = 0;
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
			odvlSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			odvlViewRanking(player);
		}
	}
}

// 設定を保存
void odvlSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x5645444F;
	saveBuf[1] = 0x4F434C45;
	saveBuf[2] = 0x4749464E;
	saveBuf[3] = 0x31726576;
	
	// 設定内容
	saveBuf[4] = odvlIsBig;
	saveBuf[5] = odvlBigMove;
	saveBuf[6] = odvlStartLevel;
	saveBuf[7] = odvlBgm;
	
	SaveFile("config/ORIGINAL_DEVIL_CONFIG.SAV", &saveBuf, 100 * 4);
}

// 設定を読み込み
int odvlLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/ORIGINAL_DEVIL_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x5645444F) return 0;
	if(saveBuf[1] != 0x4F434C45) return 0;
	if(saveBuf[2] != 0x4749464E) return 0;
	if(saveBuf[3] != 0x31726576) return 0;
	
	// 設定内容
	odvlIsBig = saveBuf[4];
	odvlBigMove = saveBuf[5];
	odvlStartLevel = saveBuf[6];
	odvlBgm = saveBuf[7];
	
	return 1;
}

// リプレイ保存
void odvlSaveReplay(int player) {
	saveBuf[900] = odvlScore[player];
	saveBuf[901] = odvlLines[player];
	saveBuf[902] = odvlLevel[player];
	saveBuf[903] = odvlIsBig;
	saveBuf[904] = odvlBigMove;
	saveBuf[905] = odvlStartLevel;
	saveBuf[906] = odvlBgm;
}

// リプレイ読み込み
void odvlLoadReplay(int player) {
	odvlIsBig = saveBuf[903];
	odvlBigMove = saveBuf[904];
	odvlStartLevel = saveBuf[905];
	odvlBgm = saveBuf[906];
	
	odvlPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void odvlReplayDetail() {
	printFontGrid(1, 4, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[900]);
	printFontGrid(22, 4, string[0], 0);
	
	printFontGrid(1, 5, "LINES", 0);
	sprintf(string[0], "%d", saveBuf[901]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[902]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "BIG", 0);
	if(!saveBuf[903]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 8, "BIG MOVE", 0);
	if(!saveBuf[904]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[905]);
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "BGM", 0);
	sprintf(string[0], "%d", saveBuf[906]);
	printFontGrid(22, 10, string[0], 0);
}

// ランキング保存
void odvlSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 10) + 0] = odvlRankingScore[i];
		saveBuf[1 + (i * 10) + 1] = odvlRankingLines[i];
		saveBuf[1 + (i * 10) + 2] = odvlRankingLevel[i];
		saveBuf[1 + (i * 10) + 3] = odvlRankingTime[i];
		saveBuf[1 + (i * 10) + 4] = odvlRankingYear[i];
		saveBuf[1 + (i * 10) + 5] = odvlRankingMonth[i];
		saveBuf[1 + (i * 10) + 6] = odvlRankingDay[i];
		saveBuf[1 + (i * 10) + 7] = odvlRankingHour[i];
		saveBuf[1 + (i * 10) + 8] = odvlRankingMinute[i];
		saveBuf[1 + (i * 10) + 9] = odvlRankingSecond[i];
	}
	
	sprintf(string[0], "config/ORIGINAL_DEVIL_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 111 * 4);
}

// ランキング読み込み
int odvlLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/ORIGINAL_DEVIL_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 111 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 10; i++) {
		odvlRankingScore[i]  = saveBuf[1 + (i * 10) + 0];
		odvlRankingLines[i]  = saveBuf[1 + (i * 10) + 1];
		odvlRankingLevel[i]  = saveBuf[1 + (i * 10) + 2];
		odvlRankingTime[i]   = saveBuf[1 + (i * 10) + 3];
		odvlRankingYear[i]   = saveBuf[1 + (i * 10) + 4];
		odvlRankingMonth[i]  = saveBuf[1 + (i * 10) + 5];
		odvlRankingDay[i]    = saveBuf[1 + (i * 10) + 6];
		odvlRankingHour[i]   = saveBuf[1 + (i * 10) + 7];
		odvlRankingMinute[i] = saveBuf[1 + (i * 10) + 8];
		odvlRankingSecond[i] = saveBuf[1 + (i * 10) + 9];
	}
	
	return 1;
}

// ランキング初期化
void odvlInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		odvlRankingScore[i]  = 0;
		odvlRankingLines[i]  = 0;
		odvlRankingLevel[i]  = 0;
		odvlRankingTime[i]   = 0;
		odvlRankingYear[i]   = 0;
		odvlRankingMonth[i]  = 0;
		odvlRankingDay[i]    = 0;
		odvlRankingHour[i]   = 0;
		odvlRankingMinute[i] = 0;
		odvlRankingSecond[i] = 0;
	}
}

// ランキング登録
int odvlRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (odvlIsBig)) return -1;
	
	for(i = 0; i < 10; i++) {
		// ランクイン
		if(odvlScore[player] > odvlRankingScore[i]) {
			// ランキングをずらす
			for(j = 9; j > i; j--) {
				odvlRankingScore[j]  = odvlRankingScore[j - 1];
				odvlRankingLines[j]  = odvlRankingLines[j - 1];
				odvlRankingLevel[j]  = odvlRankingLevel[j - 1];
				odvlRankingTime[j]   = odvlRankingTime[j - 1];
				odvlRankingYear[j]   = odvlRankingYear[j - 1];
				odvlRankingMonth[j]  = odvlRankingMonth[j - 1];
				odvlRankingDay[j]    = odvlRankingDay[j - 1];
				odvlRankingHour[j]   = odvlRankingHour[j - 1];
				odvlRankingMinute[j] = odvlRankingMinute[j - 1];
				odvlRankingSecond[j] = odvlRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			odvlRankingScore[i]  = odvlScore[player];
			odvlRankingLines[i]  = odvlLines[player];
			odvlRankingLevel[i]  = odvlLevel[player];
			odvlRankingTime[i]   = gameTimer[player];
			
			GetDateAndTime(&timebuf);
			odvlRankingYear[i]   = timebuf[0];
			odvlRankingMonth[i]  = timebuf[1];
			odvlRankingDay[i]    = timebuf[2];
			odvlRankingHour[i]   = timebuf[4];
			odvlRankingMinute[i] = timebuf[5];
			odvlRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void odvlViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ORIGINAL-DEVIL MODE RANKING", 6);
		printFontGrid(1, 3, "RANK SCORE   LINES LEVEL TIME", 4);
		
		for(i = 0; i < 10; i++) {
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", odvlRankingScore[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", odvlRankingLines[i]);
			printFontGrid(14, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", odvlRankingLevel[i]);
			printFontGrid(20, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(odvlRankingTime[i]);
			printFontGrid(26, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// 日付と時刻
			sprintf(string[0],
			        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
			        odvlRankingYear[cursor], odvlRankingMonth[cursor], odvlRankingDay[cursor],
			        odvlRankingHour[cursor], odvlRankingMinute[cursor], odvlRankingSecond[cursor]);
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
				odvlInitRanking();
				odvlSaveRanking(player);
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
