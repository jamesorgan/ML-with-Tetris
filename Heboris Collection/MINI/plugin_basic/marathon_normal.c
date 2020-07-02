//MARATHON-NORMAL
//prefix:marn

// レベルアップテーブル（LV12でスピードタイプが通常モードになる）
int marnLevelTable[15] = 
{
//   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15
    60,  48,  36,  28,  22,  16,  12,   8,   6,   4,   2,  60, 180, 300,1200
};

// 変数
int marnModeNo = -1;		// モード番号

int marnVersion;			// バージョン番号
int marnCVersion = 1;		// 現在のバージョン

int marnScore[2];			// スコア
int marnLines[2];			// ライン
int marnLevel[2];			// レベル
int marnGoal[2];			// レベルアップまでのポイント数

int marnHeborisCount[2];	// ヘボリス回数
int marnTSpinCount[2];		// T-SPIN回数

int marnTSpinFrame[2];		// T-SPIN表示／ヘボリス表示の残り時間
int marnTSpinLine[2];		// 最後のT-SPINライン消し／ヘボリス消しの種類
int marnComboFrame[2];		// コンボ数表示の残り時間
int marnB2BFrame[2];		// Back To Back表示の残り時間
int marnTSpinWall[2];		// 壁蹴りありのT-SPINだったら1になる
int marnScoreGet[2];		// 今入ったスコア表示の点数
int marnScoreFrame[2];		// 今入ったスコア表示の残り時間
int marnGoalGet[2];			// 今入ったポイント表示の点数
int marnGoalFrame[2];		// 今入ったポイント表示の残り時間

int marnIsBig = 0;			// BIGかどうか
int marnBigMove = 1;		// BIG時の横移動単位
int marnBgm = 15;			// 使用するBGM
int marnGhost = 1;			// ゴーストの設定
int marnTSpin = 3;			// T-SPINの種類
int marnEnableCombo = 1;	// コンボボーナスの有無
int marnEnableB2B = 1;		// Back To Backの有無（0=なし 1=通常 2=ヘボリスのみ 3=T-SPINのみ）
int marnStartLevel = 0;		// スタート時のレベル
int marnCarryOver = 0;		// 目標ポイントの次レベルへの繰り越しの有無

// ランキング用変数
int marnRankingScore[10];	// スコア
int marnRankingLines[10];	// ライン
int marnRankingLevel[10];	// レベル
int marnRankingHeboris[10];	// ヘボリス回数
int marnRankingTSpin[10];	// T-SPIN回数
int marnRankingTime[10];	// タイム
int marnRankingYear[10];	// ランクイン日時（年）
int marnRankingMonth[10];	// ランクイン日時（月）
int marnRankingDay[10];		// ランクイン日時（日）
int marnRankingHour[10];	// ランクイン日時（時）
int marnRankingMinute[10];	// ランクイン日時（分）
int marnRankingSecond[10];	// ランクイン日時（秒）

// イベント発生
void marnPluginEvent(int player, int event, int *param) {
	int i;
	
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != marnModeNo)) return;
	
	if(event == 0) {
		marnModeNo = addModePlugin("MARATHON-NORMAL");	// モードを登録する
	} else if(event == 8) {
		marnSoftDropScore(player);	// ソフトドロップで入った点数を加算
	} else if(event == 12) {
		marnCalcScore(player, param[0]);	// スコア計算
	} else if(event == 15) {
		marnViewScore(player);	// スコア表示
	} else if(event == 17) {
		marnSetting(player, param);	// 設定画面
	} else if(event == 18) {
		marnPlayerInitial(player);	// 初期化
	} else if(event == 21) {
		marnResult(player);	// 結果表示
	} else if(event == 24) {
		onRecord[player] = 0;	// エンディング突入
		ending[player] = 3;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		marnExcellent(player, param);	// EXCELLENT画面
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		marnSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		marnLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		marnLoadBGM();	// BGM読み込み
	} else if(event == 48) {
		marnSoftDropOld(player);	// ソフトドロップ（旧）
	} else if(event == 49) {
		marnHardDrop(player, param[1]);	// ハードドロップ
	} else if(event == 55) {
		marnReplayDetail();	// リプレイ詳細
	} else if(event == 59) {
		marnTSpinZero(player);	// ライン消しなしのT-SPIN
	}
}

// 初期化
void marnPlayerInitial(int player) {
	// バージョン
	if(!playback) marnVersion = marnCVersion;
	
	// 変数を初期化
	marnScore[player] = 0;
	marnLines[player] = 0;
	marnLevel[player] = marnStartLevel;
	marnGoal[player] = 5 * (marnLevel[player] + 1);
	
	marnHeborisCount[player] = 0;
	marnTSpinCount[player] = 0;
	
	marnTSpinFrame[player] = 0;
	marnTSpinLine[player] = 0;
	marnComboFrame[player] = 0;
	marnB2BFrame[player] = 0;
	marnTSpinWall[player] = 0;
	marnScoreGet[player] = 0;
	marnScoreFrame[player] = 0;
	marnGoalGet[player] = 0;
	marnGoalFrame[player] = 0;
	
	// 初期速度
	sp[player] = marnLevelTable[marnLevel[player]];
	if(marnLevel[player] >= 11) speedtype[player] = 0;
	else speedtype[player] = 1;
	
	// 枠の色を変える
	framecolor[player] = 5;
	frame_decoration[player] = 1;
	
	// 設定を反映させる
	IsBig[player] = marnIsBig;
	BigMove[player] = marnBigMove;
	bgmlv = marnBgm;
	if(marnGhost == 0) ghost[player] = 0;
	tspin_type[player] = marnTSpin;
	enable_combo[player] = marnEnableCombo;
	b_to_b_type[player] = marnEnableB2B;
	backno = marnLevel[player];
}

// スコア計算
void marnCalcScore(int player, int lines) {
	int bo, b2b, combopts, combogoal, points;
	
	// T-SPIN時
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		marnTSpinFrame[player] = 60;
		marnTSpinLine[player] = lines;
		marnTSpinWall[player] = (last_command[player] == 4);
		marnTSpinCount[player]++;
		
		if((lines == 1) && (marnTSpinWall[player])) bo = 2;	// 壁蹴りありT-SPIN Single
		if((lines == 1) && (!marnTSpinWall[player])) bo = 8;	// 壁蹴りなしT-SPIN Single
		if(lines == 2) bo = 12;	// T-SPIN Double
		if(lines == 3) bo = 16;	// T-SPIN Triple
	}
	// 普通のライン消し
	else {
		if(lines == 1) bo = 1;
		if(lines == 2) bo = 3;
		if(lines == 3) bo = 5;
		if(lines == 4) {
			marnTSpinFrame[player] = 60;
			marnTSpinLine[player] = lines;
			bo = 8;
			marnHeborisCount[player]++;
		}
	}
	
	// B2Bボーナス（x 1.5）
	if((marnEnableB2B != 0) && (b_to_b_count[player] >= 2)) {
		b2b = 1;
		marnB2BFrame[player] = 60;
	} else {
		b2b = 0;
		marnB2BFrame[player] = 0;
	}
	
	// コンボボーナス
	if((marnEnableCombo != 0) && (combo[player] >= 2)) {
		combopts = (combo[player] - 1) * 50;
		if(marnVersion >= 1) combopts = combopts * (marnLevel[player] + 1);
		
		if(combo[player] >= 12) combogoal = 5;
		else if(combo[player] >= 9) combogoal = 4;
		else if(combo[player] >= 7) combogoal = 3;
		else if(combo[player] >= 5) combogoal = 2;
		else if(combo[player] >= 3) combogoal = 1;
		else combogoal = 0;
		
		marnComboFrame[player] = 60;
	} else {
		combopts = 0;
		combogoal = 0;
	}
	
	// 全消しボーナス
	if(isBravo(player)) {
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		bo = bo + 50;
	}
	
	// スコア加算
	points = (bo * 100) * (marnLevel[player] + 1);
	marnScore[player] = marnScore[player] + points;
	if(b2b) marnScore[player] = marnScore[player] + (points / 2);
	marnScore[player] = marnScore[player] + combopts;
	
	marnScoreGet[player] = points + ((points / 2) * (b2b)) + combopts;
	marnScoreFrame[player] = 120;
	
	// ライン加算
	marnLines[player] = marnLines[player] + lines;
	
	// ゴール減少
	marnGoal[player] = marnGoal[player] - bo;
	if(b2b) marnGoal[player] = marnGoal[player] - (bo / 2);
	marnGoal[player] = marnGoal[player] - combogoal;
	
	marnGoalGet[player] = bo + ((bo / 2) * (b2b)) + combogoal;
	marnGoalFrame[player] = 120;
	
	// レベルアップ
	marnLevelUp(player);
}

// ライン消しなしのT-SPIN
void marnTSpinZero(int player) {
	PlaySE(se_tspin);
	marnTSpinFrame[player] = 60;
	marnTSpinLine[player] = 0;
	marnTSpinCount[player]++;
	
	// 壁蹴りあり
	if(last_command[player] == 4) {
		marnScore[player] = marnScore[player] + (100 * (marnLevel[player] + 1));
		marnGoal[player] = marnGoal[player] - 1;
		marnTSpinWall[player] = 1;
		
		marnScoreGet[player] = 100 * (marnLevel[player] + 1);
		marnScoreFrame[player] = 120;
		
		marnGoalGet[player] = 1;
		marnGoalFrame[player] = 120;
	}
	// 壁蹴りなし
	else {
		marnScore[player] = marnScore[player] + (400 * (marnLevel[player] + 1));
		marnGoal[player] = marnGoal[player] - 4;
		marnTSpinWall[player] = 0;
		
		marnScoreGet[player] = 400 * (marnLevel[player] + 1);
		marnScoreFrame[player] = 120;
		
		marnGoalGet[player] = 4;
		marnGoalFrame[player] = 120;
	}
	
	// レベルアップ
	marnLevelUp(player);
}

// レベルアップ
void marnLevelUp(int player) {
	int carrypoints;
	
	while(marnGoal[player] <= 0) {
		// 次レベルへの繰り越しポイント
		if(marnCarryOver)
			carrypoints = abs(marnGoal[player]);
		else
			carrypoints = 0;
		
		if(marnLevel[player] >= 14) {
			// エンディング
			marnGoal[player] = 0;
			ending[player] = 1;
			timeOn[player] = 0;
			return;
		} else {
			// レベルアップ
			marnLevel[player]++;
			marnGoal[player] = (5 * (marnLevel[player] + 1)) - carrypoints;
			sp[player] = marnLevelTable[marnLevel[player]];
			if(marnLevel[player] >= 11) speedtype[player] = 0;
			
			PlaySE(se_rankup);
			bgfadesw = 1;
			bgfadebg = marnLevel[player];
		}
	}
}

// ソフトドロップ（旧）
void marnSoftDropOld(int player) {
	if((!down_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) && (engineVer <= 12)) {
		if((speedtype[player] == 1) || (sp[player] < (softspeed[player] + 1) * 30)) {
			marnScore[player]++;
		}
	}
}

// ハードドロップ
void marnHardDrop(int player, int bottom) {
	if((!up_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0)) {
		marnScore[player] = marnScore[player] + (bottom - by[player]) * 2;
	}
}

// ソフトドロップで入った点数を加算
void marnSoftDropScore(int player) {
	if(softd_score[player] > 0) {
		marnScore[player] = marnScore[player] + softd_score[player];
	}
}

// スコア表示
void marnViewScore(int player) {
	int color;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// スコア
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "SCORE");
	sprintf(string[0], "%d", marnScore[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// 今入った得点
	if(marnScoreFrame[player] > 0) {
		marnScoreFrame[player]--;
		sprintf(string[0], "%d", marnScoreGet[player]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 58, string[0], (count % 4 / 2) * (1 + (b_to_b_count[player] != 0)));
	}
	
	// レベル
	printTinyFont(foffset[player] + 96, fyoffset[player] + 68, "LEVEL");
	sprintf(string[0], "%d", marnLevel[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 76, string[0], color);
	
	// ゴール
	printTinyFont(foffset[player] + 96, fyoffset[player] + 86, "GOAL");
	sprintf(string[0], "%d", marnGoal[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 94, string[0], color);
	
	// 今入ったポイント
	if(marnGoalFrame[player] > 0) {
		marnGoalFrame[player]--;
		sprintf(string[0], "%d", marnGoalGet[player]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 104, string[0], (count % 4 / 2) * (1 + (b_to_b_count[player] != 0)));
	}
	
	// タイム
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
	
	// T-SPIN
	if(marnTSpinFrame[player] > 0) {
		marnTSpinFrame[player]--;
		
		if((marnTSpinLine[player] == 0) && (marnTSpinWall[player]))
			printTinyFont(foffset[player] + 25, fyoffset[player] + 208, "EZ T-SPIN");
		else if((marnTSpinLine[player] == 0) && (!marnTSpinWall[player]))
			printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "T-SPIN");
		else if((marnTSpinLine[player] == 1) && (marnTSpinWall[player]))
			printTinyFont(foffset[player] + 20, fyoffset[player] + 208, "T-SPIN MINI");
		else if((marnTSpinLine[player] == 1) && (!marnTSpinWall[player]))
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN SINGLE");
		else if(marnTSpinLine[player] == 2)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN DOUBLE");
		else if(marnTSpinLine[player] == 3)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN TRIPLE");
		else if(marnTSpinLine[player] == 4)
			printTinyFont(foffset[player] + 30, fyoffset[player] + 208, "HEBORIS");
	}
	
	// BACK TO BACK
	if(marnB2BFrame[player] > 0) {
		marnB2BFrame[player]--;
		printTinyFont(foffset[player] + 18, fyoffset[player] + 200, "BACK TO BACK");
	}
	// COMBO
	else if((marnComboFrame[player] > 0) && (combo[player] >= 2)) {
		marnComboFrame[player]--;
		sprintf(string[0], "COMBO %d", combo[player] - 1);
		printTinyFont(foffset[player] + 30, fyoffset[player] + 200, string[0]);
	}
}

// 結果表示
void marnResult(int player) {
	// ランキング登録
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = marnRegistRanking(player);
		if(statc[player * 10 + 1] != -1) marnSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 45, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 59, "SCORE");
	sprintf(string[0], "%13d", marnScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 67, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", marnLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", marnLevel[player] + 1);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "HEBORIS");
	sprintf(string[0], "%13d", marnHeborisCount[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 139, "T-SPIN");
	sprintf(string[0], "%13d", marnTSpinCount[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 147, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 159, "TIME");
	getTime(gameTimer[player]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[1], 0);
	
	if(statc[player * 10 + 1] != -1) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 179, "RANK");
		sprintf(string[0], "%13d", statc[player * 10 + 1] + 1);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 187, string[0], 0);
	}
}

// EXCELLENT画面
void marnExcellent(int player, int *param) {
	printTinyFont(foffset[player] + 15, fyoffset[player] + 116, "MARATHON MODE");
	printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
	
	// 花火
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// BGM読み込み
void marnLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(marnBgm);
	}
}

// 設定画面
void marnSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(marnLoadConfig() == 0) marnSaveConfig();
	
	// ランキングを読み込み
	if(marnLoadRanking(player) == 0) marnInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "MARATHON-NORMAL OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",          7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",     7 * (cursor == 1));
		printFontGrid(2, 5, "BGM",          7 * (cursor == 2));
		printFontGrid(2, 6, "GHOST BLOCK",  7 * (cursor == 3));
		printFontGrid(2, 7, "T-SPIN",       7 * (cursor == 4));
		printFontGrid(2, 8, "COMBO",        7 * (cursor == 5));
		printFontGrid(2, 9, "BACK TO BACK", 7 * (cursor == 6));
		printFontGrid(2, 10, "START LEVEL", 7 * (cursor == 7));
		printFontGrid(2, 11, "CARRY OVER",  7 * (cursor == 8));
		
		// 設定値表示
		if(!marnIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!marnBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "%d", marnBgm);
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(!marnGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(marnTSpin == 0) sprintf(string[0], "OFF");
		else if(marnTSpin == 1) sprintf(string[0], "LINE CLEAR");
		else if(marnTSpin == 2) sprintf(string[0], "IMMOBILE");
		else if(marnTSpin == 3) sprintf(string[0], "3-CORNER");
		else sprintf(string[0], "3-CORNER NO KICK");
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		if(!marnEnableCombo) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		if(marnEnableB2B == 0) sprintf(string[0], "OFF");
		else if(marnEnableB2B == 1) sprintf(string[0], "ON");
		else if(marnEnableB2B == 2) sprintf(string[0], "HEBORIS ONLY");
		else sprintf(string[0], "T-SPIN ONLY");
		printFontGrid(22, 9, string[0], 7 * (cursor == 6));
		
		sprintf(string[0], "%d", marnStartLevel + 1);
		printFontGrid(22, 10, string[0], 7 * (cursor == 7));
		
		if(!marnCarryOver) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 11, string[0], 7 * (cursor == 8));
		
		// カーソル移動
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 8;
			if(cursor > 8) cursor = 0;
		}
		
		// 値を変更
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) marnIsBig = !marnIsBig;
			if(cursor == 1) marnBigMove = !marnBigMove;
			if(cursor == 2) {
				marnBgm = marnBgm + move;
				if(marnBgm < 0) marnBgm = 29;
				if(marnBgm > 29) marnBgm = 0;
			}
			if(cursor == 3) marnGhost = !marnGhost;
			if(cursor == 4) {
				marnTSpin = marnTSpin + move;
				if(marnTSpin < 0) marnTSpin = 4;
				if(marnTSpin > 4) marnTSpin = 0;
			}
			if(cursor == 5) marnEnableCombo = !marnEnableCombo;
			if(cursor == 6) {
				marnEnableB2B = marnEnableB2B + move;
				if(marnEnableB2B < 0) marnEnableB2B = 3;
				if(marnEnableB2B > 3) marnEnableB2B = 0;
			}
			if(cursor == 7) {
				marnStartLevel = marnStartLevel + move;
				if(marnStartLevel < 0) marnStartLevel = 14;
				if(marnStartLevel > 14) marnStartLevel = 0;
			}
			if(cursor == 8) marnCarryOver = !marnCarryOver;
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
			marnSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			marnViewRanking(player);
		}
	}
}

// 設定を保存
void marnSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x4152414D;
	saveBuf[1] = 0x4E4F4854;
	saveBuf[2] = 0x4D524F4E;
	saveBuf[3] = 0x31764C41;
	
	// 設定内容
	saveBuf[4] = marnIsBig;
	saveBuf[5] = marnBigMove;
	saveBuf[6] = marnBgm;
	saveBuf[7] = marnGhost;
	saveBuf[8] = marnTSpin;
	saveBuf[9] = marnEnableCombo;
	saveBuf[10] = marnEnableB2B;
	saveBuf[11] = marnStartLevel;
	saveBuf[12] = marnCarryOver;
	
	SaveFile("config/MARATHON_NORMAL_CONFIG.SAV", &saveBuf, 100 * 4);
}

// 設定を読み込み
int marnLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/MARATHON_NORMAL_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x4152414D) return 0;
	if(saveBuf[1] != 0x4E4F4854) return 0;
	if(saveBuf[2] != 0x4D524F4E) return 0;
	if(saveBuf[3] != 0x31764C41) return 0;
	
	// 設定内容
	marnIsBig = saveBuf[4];
	marnBigMove = saveBuf[5];
	marnBgm = saveBuf[6];
	marnGhost = saveBuf[7];
	marnTSpin = saveBuf[8];
	marnEnableCombo = saveBuf[9];
	marnEnableB2B = saveBuf[10];
	marnStartLevel = saveBuf[11];
	marnCarryOver = saveBuf[12];
	
	return 1;
}

// リプレイ保存
void marnSaveReplay(int player) {
	saveBuf[900] = marnScore[player];
	saveBuf[901] = marnLines[player];
	saveBuf[902] = marnLevel[player];
	saveBuf[903] = marnIsBig;
	saveBuf[904] = marnBigMove;
	saveBuf[905] = marnBgm;
	saveBuf[906] = marnGhost;
	saveBuf[907] = marnTSpin;
	saveBuf[908] = marnEnableCombo;
	saveBuf[909] = marnEnableB2B;
	saveBuf[910] = marnHeborisCount[player];
	saveBuf[911] = marnTSpinCount[player];
	saveBuf[912] = marnStartLevel;
	saveBuf[913] = marnVersion;
	saveBuf[914] = marnCarryOver;
}

// リプレイ読み込み
void marnLoadReplay(int player) {
	marnIsBig = saveBuf[903];
	marnBigMove = saveBuf[904];
	marnBgm = saveBuf[905];
	marnGhost = saveBuf[906];
	marnTSpin = saveBuf[907];
	marnEnableCombo = saveBuf[908];
	marnEnableB2B = saveBuf[909];
	marnStartLevel = saveBuf[912];
	marnVersion = saveBuf[913];
	marnCarryOver = saveBuf[914];
	
	marnPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void marnReplayDetail() {
	printFontGrid(1, 5, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[900]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "LINES", 0);
	sprintf(string[0], "%d", saveBuf[901]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[902] + 1);
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 8, "TOTAL HEBORIS", 0);
	sprintf(string[0], "%d", saveBuf[910]);
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "TOTAL T-SPIN", 0);
	sprintf(string[0], "%d", saveBuf[911]);
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 11, "BIG", 0);
	if(!saveBuf[903]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "BIG MOVE", 0);
	if(!saveBuf[904]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 12, string[0], 0);
	
	printFontGrid(1, 13, "BGM", 0);
	sprintf(string[0], "%d", saveBuf[905]);
	printFontGrid(22, 13, string[0], 0);
	
	printFontGrid(1, 14, "GHOST BLOCK", 0);
	if(!saveBuf[906]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 14, string[0], 0);
	
	printFontGrid(1, 15, "T-SPIN", 0);
	if(saveBuf[907] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[907] == 1) sprintf(string[0], "LINE CLEAR");
	else if(saveBuf[907] == 2) sprintf(string[0], "IMMOBILE");
	else if(saveBuf[907] == 3) sprintf(string[0], "3-CORNER");
	else sprintf(string[0], "3-CORNER NO KICK");
	printFontGrid(22, 15, string[0], 0);
	
	printFontGrid(1, 16, "COMBO", 0);
	if(!saveBuf[908]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 16, string[0], 0);
	
	printFontGrid(1, 17, "BACK TO BACK", 0);
	if(saveBuf[909] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[909] == 1) sprintf(string[0], "ON");
	else if(saveBuf[909] == 2) sprintf(string[0], "HEBORIS ONLY");
	else sprintf(string[0], "T-SPIN ONLY");
	printFontGrid(22, 17, string[0], 0);
	
	printFontGrid(1, 18, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[912] + 1);
	printFontGrid(22, 18, string[0], 0);
	
	printFontGrid(1, 19, "CARRY OVER", 0);
	if(!saveBuf[914]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 19, string[0], 0);
	
	printFontGrid(1, 21, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[913]);
	printFontGrid(22, 21, string[0], 0);
}

// ランキング保存
void marnSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0]  = marnRankingScore[i];
		saveBuf[1 + (i * 20) + 1]  = marnRankingLines[i];
		saveBuf[1 + (i * 20) + 2]  = marnRankingLevel[i];
		saveBuf[1 + (i * 20) + 3]  = marnRankingHeboris[i];
		saveBuf[1 + (i * 20) + 4]  = marnRankingTSpin[i];
		saveBuf[1 + (i * 20) + 5]  = marnRankingTime[i];
		saveBuf[1 + (i * 20) + 6]  = marnRankingYear[i];
		saveBuf[1 + (i * 20) + 7]  = marnRankingMonth[i];
		saveBuf[1 + (i * 20) + 8]  = marnRankingDay[i];
		saveBuf[1 + (i * 20) + 9]  = marnRankingHour[i];
		saveBuf[1 + (i * 20) + 10] = marnRankingMinute[i];
		saveBuf[1 + (i * 20) + 11] = marnRankingSecond[i];
	}
	
	sprintf(string[0], "config/MARATHON_NORMAL_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 221 * 4);
}

// ランキング読み込み
int marnLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/MARATHON_NORMAL_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 221 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 10; i++) {
		marnRankingScore[i]   = saveBuf[1 + (i * 20) + 0];
		marnRankingLines[i]   = saveBuf[1 + (i * 20) + 1];
		marnRankingLevel[i]   = saveBuf[1 + (i * 20) + 2];
		marnRankingHeboris[i] = saveBuf[1 + (i * 20) + 3];
		marnRankingTSpin[i]   = saveBuf[1 + (i * 20) + 4];
		marnRankingTime[i]    = saveBuf[1 + (i * 20) + 5];
		marnRankingYear[i]    = saveBuf[1 + (i * 20) + 6];
		marnRankingMonth[i]   = saveBuf[1 + (i * 20) + 7];
		marnRankingDay[i]     = saveBuf[1 + (i * 20) + 8];
		marnRankingHour[i]    = saveBuf[1 + (i * 20) + 9];
		marnRankingMinute[i]  = saveBuf[1 + (i * 20) + 10];
		marnRankingSecond[i]  = saveBuf[1 + (i * 20) + 11];
	}
	
	return 1;
}

// ランキング初期化
void marnInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		marnRankingScore[i]   = 0;
		marnRankingLines[i]   = 0;
		marnRankingLevel[i]   = 0;
		marnRankingHeboris[i] = 0;
		marnRankingTSpin[i]   = 0;
		marnRankingTime[i]    = 0;
		marnRankingYear[i]    = 0;
		marnRankingMonth[i]   = 0;
		marnRankingDay[i]     = 0;
		marnRankingHour[i]    = 0;
		marnRankingMinute[i]  = 0;
		marnRankingSecond[i]  = 0;
	}
}

// ランキング登録
int marnRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (marnIsBig)) return -1;
	
	for(i = 0; i < 10; i++) {
		// ランクイン
		if((marnScore[player] > marnRankingScore[i]) || 
		   ((marnScore[player] == marnRankingScore[i]) && (gameTimer[player] < marnRankingTime[i])))
		{
			// ランキングをずらす
			for(j = 9; j > i; j--) {
				marnRankingScore[j]   = marnRankingScore[j - 1];
				marnRankingLines[j]   = marnRankingLines[j - 1];
				marnRankingLevel[j]   = marnRankingLevel[j - 1];
				marnRankingHeboris[j] = marnRankingHeboris[j - 1];
				marnRankingTSpin[j]   = marnRankingTSpin[j - 1];
				marnRankingTime[j]    = marnRankingTime[j - 1];
				marnRankingYear[j]    = marnRankingYear[j - 1];
				marnRankingMonth[j]   = marnRankingMonth[j - 1];
				marnRankingDay[j]     = marnRankingDay[j - 1];
				marnRankingHour[j]    = marnRankingHour[j - 1];
				marnRankingMinute[j]  = marnRankingMinute[j - 1];
				marnRankingSecond[j]  = marnRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			marnRankingScore[i]   = marnScore[player];
			marnRankingLines[i]   = marnLines[player];
			marnRankingLevel[i]   = marnLevel[player];
			marnRankingHeboris[i] = marnHeborisCount[player];
			marnRankingTSpin[i]   = marnTSpinCount[player];
			marnRankingTime[i]    = gameTimer[player];
			
			GetDateAndTime(&timebuf);
			marnRankingYear[i]    = timebuf[0];
			marnRankingMonth[i]   = timebuf[1];
			marnRankingDay[i]     = timebuf[2];
			marnRankingHour[i]    = timebuf[4];
			marnRankingMinute[i]  = timebuf[5];
			marnRankingSecond[i]  = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void marnViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "MARATHON-NORMAL MODE RANKING", 6);
		printFontGrid(1, 3, "RANK SCORE    LINES LEVEL TIME", 4);
		
		for(i = 0; i < 10; i++) {
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", marnRankingScore[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", marnRankingLines[i]);
			printFontGrid(15, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", marnRankingLevel[i] + 1);
			printFontGrid(21, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(marnRankingTime[i]);
			printFontGrid(27, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// ヘボリス回数とT-SPIN回数
			sprintf(string[0], "TOTAL HEBORIS:%d", marnRankingHeboris[cursor]);
			printFontGrid(1, 24, string[0], 0);
			sprintf(string[0], "TOTAL T-SPIN :%d", marnRankingTSpin[cursor]);
			printFontGrid(1, 25, string[0], 0);
			
			// 日付と時刻
			sprintf(string[0],
			        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
			        marnRankingYear[cursor], marnRankingMonth[cursor], marnRankingDay[cursor],
			        marnRankingHour[cursor], marnRankingMinute[cursor], marnRankingSecond[cursor]);
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
				marnInitRanking();
				marnSaveRanking(player);
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
