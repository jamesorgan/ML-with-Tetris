//ORIGINAL-MASTER
//prefix:omas

// レベルアップテーブル
// フレーム関連の処理を大幅に変えたので、本家と微妙にタイミングが違うかも…
int omasLevelTable[30] = 
{
	  1,   3,   5,   6,   8,  10,  12,  15,  20,  30,
	 30,   1,   5,  12,  30,  60,  60,  60,  60,  60,
	120, 120, 180, 180, 240, 300, 300, 240, 180,1200
};
int omasWait1[12] =
{
	26, 27, 27, 27, 27, 18, 18, 16, 15, 14, 14, 13
};
int omasWait2[12] =
{
	40, 25, 22, 18, 15, 12, 10,  8,  6,  5,  4,  3
};
int omasWait3[12] =
{
	28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 22, 15
};
int omasWaitt[12] =
{
	15,  9,  9,  9,  9,  8,  8,  8,  8,  7,  7,  7
};

// 変数
int omasModeNo = -1;		// モード番号
int omasScore[2];			// スコア
int omasRate[2];			// コンボボーナス用変数
int omasLines[2];			// ライン
int omasLevel[2];			// レベル
int omasLc[2];				// レベルアップまでのカウンタ
int omasLvUpAnim[2];		// レベルアップ直後、数字を点滅させる時間

int omasIsBig = 0;			// BIGかどうか
int omasBigMove = 1;		// BIG時の横移動単位
int omasStartLevel = 0;		// 開始レベル
int omasBgm = 0;			// 使用するBGM
int omasGhost = 0;			// ゴーストの設定

// ランキング用変数
int omasRankingScore[10];	// スコア
int omasRankingLines[10];	// ライン
int omasRankingLevel[10];	// レベル
int omasRankingTime[10];	// タイム
int omasRankingYear[10];	// ランクイン日時（年）
int omasRankingMonth[10];	// ランクイン日時（月）
int omasRankingDay[10];		// ランクイン日時（日）
int omasRankingHour[10];	// ランクイン日時（時）
int omasRankingMinute[10];	// ランクイン日時（分）
int omasRankingSecond[10];	// ランクイン日時（秒）

// イベント発生
void omasPluginEvent(int player, int event, int *param) {
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != omasModeNo)) return;
	
	if(event == 0) {
		omasModeNo = addModePlugin("ORIGINAL-MASTER");	// モードを登録する
	} else if(event == 8) {
		omasSoftDropScore(player);	// ソフトドロップで入った点数を加算
	} else if(event == 10) {
		omasARE(player);	// ARE中
	} else if(event == 13) {
		omasCalcScore(player, param[0]);	// スコア計算
	} else if(event == 15) {
		omasViewScore(player);	// スコア表示
	} else if(event == 17) {
		omasSetting(player, param);	// 設定画面
	} else if(event == 18) {
		omasPlayerInitial(player);	// 初期化
	} else if(event == 21) {
		omasResult(player);	// 結果表示
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		omasSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		omasLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		omasLoadBGM();	// BGM読み込み
	} else if(event == 48) {
		omasSoftDropOld(player);	// ソフトドロップ
	} else if(event == 49) {
		omasHardDrop(player, param[1]);	// ハードドロップ
	} else if(event == 55) {
		omasReplayDetail();	// リプレイ詳細
	}
}

// 初期化
void omasPlayerInitial(int player) {
	// 変数を初期化
	omasScore[player] = 0;
	omasRate[player] = 0;
	omasLines[player] = 0;
	omasLevel[player] = omasStartLevel;
	omasLc[player] = 0;
	omasLvUpAnim[player] = 0;
	
	// コンボ有効
	enable_combo[player] = 1;
	
	// 枠の色を変える
	framecolor[player] = 9;
	
	// 初期速度
	omasChangeSpeed(player);
	backno = omasLevel[player] / 3;
	if(backno > 19) backno = 19;
	
	if( ((omasLevel[player] >= 12) && (!omasGhost)) || (omasGhost == 2) ) ghost[player] = 0;
	
	// 設定を反映させる
	IsBig[player] = omasIsBig;
	BigMove[player] = omasBigMove;
	bgmlv = omasBgm;
}

// ARE中
void omasARE(int player) {
	// レベルカウンタ＋１
	if(statc[player * 10] == wait1[player] - lockflash[player]) omasLc[player]++;
	
	// レベルアップ判定
	if(omasLc[player] > 100) {
		omasLc[player] = omasLc[player] - 100;
		
		omasLevel[player]++;
		omasLvUpAnim[player] = 180;
		
		omasChangeSpeed(player);
		
		if(omasLevel[player] % 3 == 0) {
			PlaySE(se_levelup);
			
			if(omasLevel[player] / 3 < 20) {
				bgfadesw = 1;
				bgfadebg = omasLevel[player] / 3;
			}
		}
		
		if((omasLevel[player] >= 12) && (!omasGhost)) ghost[player] = 0;
	}
}

// スピードを変える
void omasChangeSpeed(int player) {
	int temp;
	
	temp = omasLevel[player];
	if(temp > 29) temp = 29;
	sp[player] = omasLevelTable[temp];
	
	if(omasLevel[player] < 30) {
		wait1[player] = omasWait1[0] + 3;
		wait2[player] = omasWait2[0];
		wait3[player] = omasWait3[0] + 2;
		waitt[player] = omasWaitt[0];
	} else {
		temp = (omasLevel[player] - 30) / 3;
		if(temp > 10) temp = 10;
		wait1[player] = omasWait1[1 + temp] + 3;
		wait2[player] = omasWait2[1 + temp];
		wait3[player] = omasWait3[1 + temp] + 2;
		waitt[player] = omasWaitt[1 + temp];
	}
}

// スコア計算
void omasCalcScore(int player, int lines) {
	int bo, bai, all;
	
	// 基本点
	if(combo[player] == 1) omasRate[player] = 100;
	
	if(lines == 1) {
		bo = 1 * omasRate[player];
		omasRate[player] = omasRate[player] + 5;
	}
	if(lines == 2) {
		bo = 4 * omasRate[player];
		omasRate[player] = omasRate[player] + 10;
	}
	if(lines == 3) {
		bo = 9 * omasRate[player];
		omasRate[player] = omasRate[player] + 30;
	}
	if(lines == 4) {
		bo = 20 * omasRate[player];
		omasRate[player] = omasRate[player] + 50;
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
	omasScore[player] = omasScore[player] + bo * bai;
	omasLines[player] = omasLines[player] + lines;
	omasLc[player] = omasLc[player] + lines * 20;
}

// ソフトドロップ（旧）
void omasSoftDropOld(int player) {
	if((!down_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) && (engineVer <= 12)) {
		if(sp[player] < (softspeed[player] + 1) * 30) {
			omasScore[player]++;
		}
	}
}

// ハードドロップ
void omasHardDrop(int player, int bottom) {
	if((!up_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0)) {
		if(sp[player] <= 240) {
			omasScore[player] = omasScore[player] + (bottom - by[player]) * 23 / 20;	// 通常の15%増の点数獲得
		}
	}
}

// ソフトドロップで入った点数を加算
void omasSoftDropScore(int player) {
	if(softd_score[player] > 0) {
		omasScore[player] = omasScore[player] + softd_score[player];
	}
}

// スコア表示
void omasViewScore(int player) {
	int color, color2;
	color = (count % 4 / 2) * (sp[player] >= 1200) * 2;
	
	// スコア
	printFont(foffset[player] + 96, fyoffset[player] + 40, "SCORE", 2);
	if(omasScore[player] > 9999999) omasScore[player] = 9999999;
	sprintf(string[0], "%d", omasScore[player]);
	printFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// ライン
	printFont(foffset[player] + 96, fyoffset[player] + 64, "LINES", 2);
	if(omasLines[player] > 9999) omasLines[player] = 9999;
	sprintf(string[0], "%d", omasLines[player]);
	printFont(foffset[player] + 96, fyoffset[player] + 72, string[0], color);
	
	// レベル
	printFont(foffset[player] + 96, fyoffset[player] + 88, "LEVEL", 2);
	if(omasLevel[player] > 999) omasLevel[player] = 999;
	sprintf(string[0], "%d", omasLevel[player]);
	if(!omasLvUpAnim[player]) {
		color2 = color;
	} else {
		color2 = 7 * (count % 4 / 2);
		omasLvUpAnim[player]--;
	}
	printFont(foffset[player] + 96, fyoffset[player] + 96, string[0], color2);
	
	// タイム
	if(gameTimer[player] > 359999) gameTimer[player] = 359999;
	getTime(gameTimer[player]);
	printFont(foffset[player] + 16, fyoffset[player] + 224, string[0], color);
}

// 結果表示
void omasResult(int player) {
	// ランキング登録
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = omasRegistRanking(player);
		if(statc[player * 10 + 1] != -1) omasSaveRanking(player);
	}
	
	printFont(foffset[player] + 8, fyoffset[player] + 48, "PLAY DATA", 4);
	
	// スコア
	printFont(foffset[player] + 8, fyoffset[player] + 64, "SCORE", 2);
	sprintf(string[0], "%10d", omasScore[player]);
	printFont(foffset[player] + 8, fyoffset[player] + 72, string[0], 0);
	
	// ライン
	printFont(foffset[player] + 8, fyoffset[player] + 88, "LINES", 2);
	sprintf(string[0], "%10d", omasLines[player]);
	printFont(foffset[player] + 8, fyoffset[player] + 96, string[0], 0);
	
	// レベル
	printFont(foffset[player] + 8, fyoffset[player] + 112, "LEVEL", 2);
	sprintf(string[0], "%10d", omasLevel[player]);
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
void omasLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(omasBgm);
	}
}

// 設定画面
void omasSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(omasLoadConfig() == 0) omasSaveConfig();
	
	// ランキングを読み込み
	if(omasLoadRanking(player) == 0) omasInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ORIGINAL-MASTER OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",         7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",    7 * (cursor == 1));
		printFontGrid(2, 5, "START LEVEL", 7 * (cursor == 2));
		printFontGrid(2, 6, "BGM",         7 * (cursor == 3));
		printFontGrid(2, 7, "GHOST BLOCK", 7 * (cursor == 4));
		
		// 設定値表示
		if(!omasIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!omasBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "%d", omasStartLevel);
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "%d", omasBgm);
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(omasGhost == 0) sprintf(string[0], "LV12");
		else if(omasGhost == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
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
			if(cursor == 0) omasIsBig = !omasIsBig;
			if(cursor == 1) omasBigMove = !omasBigMove;
			if(cursor == 2) {
				omasStartLevel = omasStartLevel + move;
				if(omasStartLevel < 0) omasStartLevel = 60;
				if(omasStartLevel > 60) omasStartLevel = 0;
			}
			if(cursor == 3) {
				omasBgm = omasBgm + move;
				if(omasBgm < 0) omasBgm = 29;
				if(omasBgm > 29) omasBgm = 0;
			}
			if(cursor == 4) {
				omasGhost = omasGhost + move;
				if(omasGhost < 0) omasGhost = 2;
				if(omasGhost > 2) omasGhost = 0;
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
			omasSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			omasViewRanking(player);
		}
	}
}

// 設定を保存
void omasSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x53414D4F;
	saveBuf[1] = 0x43524554;
	saveBuf[2] = 0x49464E4F;
	saveBuf[3] = 0x31307647;
	
	// 設定内容
	saveBuf[4] = omasIsBig;
	saveBuf[5] = omasBigMove;
	saveBuf[6] = omasStartLevel;
	saveBuf[7] = omasBgm;
	saveBuf[8] = omasGhost;
	
	SaveFile("config/ORIGINAL_MASTER_CONFIG.SAV", &saveBuf, 100 * 4);
}

// 設定を読み込み
int omasLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/ORIGINAL_MASTER_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x53414D4F) return 0;
	if(saveBuf[1] != 0x43524554) return 0;
	if(saveBuf[2] != 0x49464E4F) return 0;
	if(saveBuf[3] != 0x31307647) return 0;
	
	// 設定内容
	omasIsBig = saveBuf[4];
	omasBigMove = saveBuf[5];
	omasStartLevel = saveBuf[6];
	omasBgm = saveBuf[7];
	omasGhost = saveBuf[8];
	
	return 1;
}

// リプレイ保存
void omasSaveReplay(int player) {
	saveBuf[900] = omasScore[player];
	saveBuf[901] = omasLines[player];
	saveBuf[902] = omasLevel[player];
	saveBuf[903] = omasIsBig;
	saveBuf[904] = omasBigMove;
	saveBuf[905] = omasStartLevel;
	saveBuf[906] = omasBgm;
	saveBuf[907] = omasGhost;
}

// リプレイ読み込み
void omasLoadReplay(int player) {
	omasIsBig = saveBuf[903];
	omasBigMove = saveBuf[904];
	omasStartLevel = saveBuf[905];
	omasBgm = saveBuf[906];
	omasGhost = saveBuf[907];
	
	omasPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void omasReplayDetail() {
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
	
	printFontGrid(1, 11, "GHOST BLOCK", 0);
	if(saveBuf[907] == 0) sprintf(string[0], "LV12");
	else if(saveBuf[907] == 1) sprintf(string[0], "ON");
	else sprintf(string[0], "OFF");
	printFontGrid(22, 11, string[0], 0);
}

// ランキング保存
void omasSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 10) + 0] = omasRankingScore[i];
		saveBuf[1 + (i * 10) + 1] = omasRankingLines[i];
		saveBuf[1 + (i * 10) + 2] = omasRankingLevel[i];
		saveBuf[1 + (i * 10) + 3] = omasRankingTime[i];
		saveBuf[1 + (i * 10) + 4] = omasRankingYear[i];
		saveBuf[1 + (i * 10) + 5] = omasRankingMonth[i];
		saveBuf[1 + (i * 10) + 6] = omasRankingDay[i];
		saveBuf[1 + (i * 10) + 7] = omasRankingHour[i];
		saveBuf[1 + (i * 10) + 8] = omasRankingMinute[i];
		saveBuf[1 + (i * 10) + 9] = omasRankingSecond[i];
	}
	
	sprintf(string[0], "config/ORIGINAL_MASTER_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 111 * 4);
}

// ランキング読み込み
int omasLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/ORIGINAL_MASTER_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 111 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 10; i++) {
		omasRankingScore[i]  = saveBuf[1 + (i * 10) + 0];
		omasRankingLines[i]  = saveBuf[1 + (i * 10) + 1];
		omasRankingLevel[i]  = saveBuf[1 + (i * 10) + 2];
		omasRankingTime[i]   = saveBuf[1 + (i * 10) + 3];
		omasRankingYear[i]   = saveBuf[1 + (i * 10) + 4];
		omasRankingMonth[i]  = saveBuf[1 + (i * 10) + 5];
		omasRankingDay[i]    = saveBuf[1 + (i * 10) + 6];
		omasRankingHour[i]   = saveBuf[1 + (i * 10) + 7];
		omasRankingMinute[i] = saveBuf[1 + (i * 10) + 8];
		omasRankingSecond[i] = saveBuf[1 + (i * 10) + 9];
	}
	
	return 1;
}

// ランキング初期化
void omasInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		omasRankingScore[i]  = 0;
		omasRankingLines[i]  = 0;
		omasRankingLevel[i]  = 0;
		omasRankingTime[i]   = 0;
		omasRankingYear[i]   = 0;
		omasRankingMonth[i]  = 0;
		omasRankingDay[i]    = 0;
		omasRankingHour[i]   = 0;
		omasRankingMinute[i] = 0;
		omasRankingSecond[i] = 0;
	}
}

// ランキング登録
int omasRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (omasIsBig)) return -1;
	
	for(i = 0; i < 10; i++) {
		// ランクイン
		if(omasScore[player] > omasRankingScore[i]) {
			// ランキングをずらす
			for(j = 9; j > i; j--) {
				omasRankingScore[j]  = omasRankingScore[j - 1];
				omasRankingLines[j]  = omasRankingLines[j - 1];
				omasRankingLevel[j]  = omasRankingLevel[j - 1];
				omasRankingTime[j]   = omasRankingTime[j - 1];
				omasRankingYear[j]   = omasRankingYear[j - 1];
				omasRankingMonth[j]  = omasRankingMonth[j - 1];
				omasRankingDay[j]    = omasRankingDay[j - 1];
				omasRankingHour[j]   = omasRankingHour[j - 1];
				omasRankingMinute[j] = omasRankingMinute[j - 1];
				omasRankingSecond[j] = omasRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			omasRankingScore[i]  = omasScore[player];
			omasRankingLines[i]  = omasLines[player];
			omasRankingLevel[i]  = omasLevel[player];
			omasRankingTime[i]   = gameTimer[player];
			
			GetDateAndTime(&timebuf);
			omasRankingYear[i]   = timebuf[0];
			omasRankingMonth[i]  = timebuf[1];
			omasRankingDay[i]    = timebuf[2];
			omasRankingHour[i]   = timebuf[4];
			omasRankingMinute[i] = timebuf[5];
			omasRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void omasViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ORIGINAL-MASTER MODE RANKING", 6);
		printFontGrid(1, 3, "RANK SCORE   LINES LEVEL TIME", 4);
		
		for(i = 0; i < 10; i++) {
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", omasRankingScore[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", omasRankingLines[i]);
			printFontGrid(14, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", omasRankingLevel[i]);
			printFontGrid(20, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(omasRankingTime[i]);
			printFontGrid(26, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// 日付と時刻
			sprintf(string[0],
			        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
			        omasRankingYear[cursor], omasRankingMonth[cursor], omasRankingDay[cursor],
			        omasRankingHour[cursor], omasRankingMinute[cursor], omasRankingSecond[cursor]);
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
				omasInitRanking();
				omasSaveRanking(player);
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
