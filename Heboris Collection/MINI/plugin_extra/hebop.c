//HEBO+
//prefix:hebop

// バージョン
int hebopVersion;		// バージョン番号（古いリプレイ再生用）
int hebopCVersion = 2;	// 現在のバージョン

// レベルアップテーブル(420での減速追加後)
// 速度
int hebopLevelTable[30] =
{
	4, 6, 8, 10, 12, 16, 32, 48, 64, 80, 96, 112, 128, 144, 4, 32, 64, 96, 128, 160,
	192, 224, 256, 512, 768, 1024, 1280, 1024, 768, 5120
};

// レベル
int hebopLevelChange[30] = 
{
	30, 35, 40, 50, 60, 70, 80, 90, 100, 120, 140, 160, 170, 200, 220, 230, 233, 236, 239, 243,
	247, 251, 300, 330, 360, 400, 420, 450, 500, 10000
};

// レベルアップテーブル(420での減速追加前)
// 速度
int hebopLevelTableOld[29] =
{
	4, 6, 8, 10, 12, 16, 32, 48, 64, 80, 96, 112, 128, 144, 4, 32, 64, 96, 128, 160,
	192, 224, 256, 512, 768, 1024, 1280, 768, 5120
};

// レベル
int hebopLevelChangeOld[29] = 
{
	30, 35, 40, 50, 60, 70, 80, 90, 100, 120, 140, 160, 170, 200, 220, 230, 233, 236, 239, 243,
	247, 251, 300, 330, 360, 400, 450, 500, 10000
};

// せり上がりパターン
int hebopGarbagePattern[10 * 24] = 
{
	0,1,1,1,1,1,1,1,1,1,
	0,1,1,1,1,1,1,1,1,1,
	0,1,1,1,1,1,1,1,1,1,
	0,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,0,
	1,1,1,1,1,1,1,1,1,0,
	1,1,1,1,1,1,1,1,1,0,
	1,1,1,1,1,1,1,1,1,0,
	0,0,1,1,1,1,1,1,1,1,
	0,1,1,1,1,1,1,1,1,1,
	0,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,0,0,
	1,1,1,1,1,1,1,1,1,0,
	1,1,1,1,1,1,1,1,1,0,
	1,1,0,1,1,1,1,1,1,1,
	1,0,0,1,1,1,1,1,1,1,
	1,0,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,0,1,1,
	1,1,1,1,1,1,1,0,0,1,
	1,1,1,1,1,1,1,1,0,1,
	1,1,1,1,0,0,1,1,1,1,
	1,1,1,1,0,0,1,1,1,1,
	1,1,1,1,0,1,1,1,1,1,
	1,1,1,0,0,0,1,1,1,1,
};

// 裏段位の表示名
str hebopStrSecretGradeName[19] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0～ 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9～17
	"GM"													// 18
};

// BGM設定
int hebopBgmNo[4]     = {0,1,2,3};				// BGM番号（000-499、500-699、700-899、900-999）
int hebopFadeLv[4]    = {495,695,880,10000};	// BGMをフェードアウトさせるレベル
int hebopBgmChange[4] = {500,700,900,10000};	// BGMを切り替えるレベル
int hebopBgmIndex     = 0;						// 現在のBGM番号

// 変数
int hebopModeNo = -1;		// モード番号
int hebopLevel[2];			// レベル
int hebopScore[2];			// スコア
int hebopLevelIndex[2];		// 現在の速度番号
int hebopGarbagePos[2];		// 現在のせり上がりパターンの位置（0～23）
int hebopGarbageCount[2];	// せり上がり用カウンタ（ラインを消さないと+1）

int hebopGhost = 0;			// ゴーストの設定（0=LV0-99 1=常にON 2=常にOFF）
int hebopLvUpBonus = 0;		// レベルアップボーナス
int hebop20G = 0;			// 20Gモード
int hebopStartLevel = 0;	// スタート時のレベル

// ランキング用変数
int hebopRankingTime[20];	// タイム
int hebopRankingLevel[20];	// レベル
int hebopRankingYear[20];	// ランクイン日時（年）
int hebopRankingMonth[20];	// ランクイン日時（月）
int hebopRankingDay[20];	// ランクイン日時（日）
int hebopRankingHour[20];	// ランクイン日時（時）
int hebopRankingMinute[20];	// ランクイン日時（分）
int hebopRankingSecond[20];	// ランクイン日時（秒）

// イベント発生
void hebopPluginEvent(int player, int event, int *param) {
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != hebopModeNo)) return;
	
	if(event == 0) {
		hebopModeNo = addModePlugin("HEBO+");	// モードを登録する
	} else if(event == 7) {
		if(!ending[player]) hebopMoveInit(player);	// ブロック出現
	} else if(event == 12) {
		if(!ending[player]) hebopCalcScore(player, param[0]);	// スコア計算
	} else if(event == 15) {
		hebopViewScore(player);	// スコア表示
	} else if(event == 17) {
		hebopSetting(player, param);	// 設定画面
	} else if(event == 18) {
		hebopPlayerInitial(player);	// 初期化処理
	} else if(event == 21) {
		hebopResult(player);	// 結果表示
	} else if(event == 25) {
		hebopExcellent(player, param);	// エンディング終了
	} else if(event == 28) {
		hebopIncrementTime(player);	// 時間を進める
	} else if(event == 36) {
		hebopStaffRoll(player);	// スタッフロール描画
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		hebopSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		hebopLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		hebopLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		hebopReplayDetail();	// リプレイ詳細
	} else if(event == 60) {
		hebopMoveLock(player);	// ライン消しなしでブロックを置いたとき
	}
}

// 初期化処理
void hebopPlayerInitial(int player) {
	// バージョン
	if(!playback) hebopVersion = hebopCVersion;
	
	// コンボ有効
	enable_combo[player] = 1;
	
	// 枠の色を変える
	framecolor[player] = 6;
	
	// 変数を初期化
	if((hebopStartLevel > 0) && (hebopVersion >= 1)) hebopLevel[player] = hebopStartLevel;
	else hebopLevel[player] = -1;
	backno = hebopLevel[player] / 100;
	
	hebopScore[player] = 0;
	hebopLevelIndex[player] = 0;
	hebopGarbagePos[player] = 0;
	hebopGarbageCount[player] = 0;
	hebopBgmIndex = 0;
	bgmlv = hebopBgmNo[0];
	if(hebopGhost == 2) ghost[player] = 0;
	
	// 初期速度を設定
	hebopSpeedUp(player);
}

// スピードアップ
void hebopSpeedUp(int player) {
	int temp;
	
	// スピードを変える
	speedtype[player] = 2;
	
	if(hebop20G) {
		sp[player] = 5120;
	} else {
		if(hebopVersion >= 2) {
			while(hebopLevel[player] >= hebopLevelChange[hebopLevelIndex[player]]) {
				hebopLevelIndex[player]++;
			}
		} else if(hebopVersion == 1) {
			while(hebopLevel[player] >= hebopLevelChangeOld[hebopLevelIndex[player]]) {
				hebopLevelIndex[player]++;
			}
		} else {
			if(hebopLevel[player] >= hebopLevelChangeOld[hebopLevelIndex[player]]) hebopLevelIndex[player]++;
		}
		
		if(hebopVersion >= 2) {
			sp[player] = hebopLevelTable[hebopLevelIndex[player]];
		} else {
			sp[player] = hebopLevelTableOld[hebopLevelIndex[player]];
		}
	}
	
	// ゴーストを消す
	if((hebopLevel[player] >= 100) && (hebopGhost == 0)) {
		ghost[player] = 0;
	}
	
	// BGMフェードアウト
	if((hebopLevel[player] >= hebopFadeLv[hebopBgmIndex]) && (hebopLevel[player] < hebopBgmChange[hebopBgmIndex]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// BGM切り替え
	temp = 0;
	while(hebopLevel[player] >= hebopBgmChange[hebopBgmIndex]) {
		hebopBgmIndex++;
		bgmlv = hebopBgmNo[hebopBgmIndex];
		if(onRecord[player]) temp = 1;
	}
	if(temp) PlayBGM();
}

// ブロック出現
void hebopMoveInit(int player) {
	int temp;
	
	// 最初のフレームなら
	if(statc[player * 10 + 3] == 0) {
		// レベルアップ処理
		if(hebopLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		
		if(hebopLevel[player] % 100 != temp) {
			hebopLevel[player]++;
			if(hebopLevel[player] % 100 == temp) PlaySE(se_lvstop);
			hebopSpeedUp(player);
		}
	}
}

// スコア計算
void hebopCalcScore(int player, int lines) {
	int temp, temp2, bo, bai, nextsec;
	
	if(!hebopLvUpBonus) temp = hebopLevel[player] + lines;
	else temp = hebopLevel[player] + lines + ((lines >= 3) * (lines - 2));
	if(temp > 999) temp = 999;
	
	temp2 = wait3[player] - bactivetime[player];
	if(temp2 < 0) temp2 = 0;
	
	bo = ((hebopLevel[player] + lines) / 4 + sdrop[player] + qdrop[player] + qput[player]) * lines * cmbpts[player] + (temp / 2) + (temp2 * 7);
	bai = 1;
	
	if(isBravo(player)) {
		// 全消しするとスコア4倍
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		bai = bai * 4;
	}
	
	// スコア加算
	hebopScore[player] = hebopScore[player] + bo * bai;
	
	// レベルアップ
	nextsec = hebopLevel[player] / 100 * 100 + 100;
	if(!hebopLvUpBonus) hebopLevel[player] = hebopLevel[player] + lines;
	else hebopLevel[player] = hebopLevel[player] + lines + ((lines >= 3) * (lines - 2));
	
	if(hebopLevel[player] >= 999) {
		// エンディング
		PlaySE(se_ttclear);
		hebopLevel[player] = 999;
		timeOn[player] = 0;
		ending[player] = 2;
		ending_timeOn[player] = 1;
		fastroll[player] = 1;
	} else {
		// レベルストップ音
		if(hebopLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		if(hebopLevel[player] % 100 == temp) PlaySE(se_lvstop);
		
		if(hebopLevel[player] >= nextsec) {
			// レベルアップ音
			PlaySE(se_levelup);
			
			// 背景切り替え
			bgfadesw = 1;
			bgfadebg = nextsec / 100;
		}
		
		// スピードアップ
		hebopSpeedUp(player);
	}
}

// 時間を進める
void hebopIncrementTime(int player) {
	int i;
	
	// Fボタンで高速ロール早送り
	if((ending_timeOn[player]) && (onRecord[player]) && (fastroll[player] == 1) && (getPressState(player, 9)))
		edrec[player] = edrec[player] + 2;
	
	// ロール終了
	if((ending[player] == 2) && (edrec[player] >= 60 * 60)) {
		ending[player] = 3;
		stat[player] = 10;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
}

// スタッフロール描画
void hebopStaffRoll(int player) {
	// Fボタンで高速ロール早送り
	if((ending_timeOn[player]) && (onRecord[player]) && (fastroll[player] == 1) && (getPressState(player, 9))) {
		endtime[player] = endtime[player] + 2;
		if(endtime[player] < 3100) staff_c[player]++;
	}
}

// ライン消しなしでブロックを置いたとき
void hebopMoveLock(int player) {
	int i;
	
	hebopGarbageCount[player]++;
	
	if(hebopGarbageCount[player] >= 13 - (hebopLevel[player] / 100)) {
		// せり上がり
		for(i = 0; i < 10; i++) fldu[i + player * 220] = hebopGarbagePattern[i + hebopGarbagePos[player] * 10];
		hebopGarbagePos[player]++;
		if(hebopGarbagePos[player] > 23) hebopGarbagePos[player] = 0;
		upLines[player]++;
		hebopGarbageCount[player] = 0;
	}
}

// BGM読み込み
void hebopLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 4; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/4)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(hebopBgmNo[i]);
		}
	}
}

// スコア表示
void hebopViewScore(int player) {
	int color, temp;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// スコア
	printTinyFont(foffset[player] + 96, fyoffset[player] + 135, "SCORE");
	sprintf(string[0], "%d", hebopScore[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 143, string[0], color);
	
	// レベル（分子）
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(hebopLevel[player] == -1) sprintf(string[0], "%4d", 0);	// -1なら0と表示する(内部的には最初は-1になっている)
	else sprintf(string[0], "%4d", hebopLevel[player]);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// レベル（横線）
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	temp = sp[player] / 128;
	if(temp > 22) temp = 22;
	ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22 - temp, 143, 22, 1);
	
	// レベル（分母）
	if(ending[player]) sprintf(string[0], "%4d", hebopLevel[player]);
	else if(hebopLevel[player] >= 900) sprintf(string[0], "%4d", 999);
	else sprintf(string[0], "%4d", hebopLevel[player] / 100 * 100 + 100);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, string[0], color);
	
	// タイム
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
}

// エンディング終了
void hebopExcellent(int player, int *param) {
	onRecord[player] = 0;
	statc[player * 10 + 1]++;
	
	// 花火
	if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 2]++;
	}
	
	// EXCELLENT
	param[0] = 0;
	printTinyFont(foffset[player] + 22, fyoffset[player] + 116, "HEBO+ MODE");
	printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
}

// 結果表示
void hebopResult(int player) {
	if(statc[player * 10] == 0) {
		// ランキング登録
		statc[player * 10 + 1] = hebopRegistRanking(player);
		if(statc[player * 10 + 1] != -1) hebopSaveRanking(player);
		
		// 裏段位判定
		statc[player * 10 + 2] = checkSecretGrade(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "SCORE");
	sprintf(string[0], "%13d", hebopScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", hebopLevel[player]);
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
	
	if(statc[player * 10 + 2] >= 4) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 159, "SECRET GRADE");
		sprintf(string[0], "%13s", hebopStrSecretGradeName[statc[player * 10 + 2]]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
	}
}

// 設定画面
void hebopSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(hebopLoadConfig() == 0) hebopSaveConfig();
	
	// ランキングを読み込み
	if(hebopLoadRanking(player) == 0) hebopInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "HEBO+ OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "GHOST BLOCK",    7 * (cursor == 0));
		printFontGrid(2, 4, "LEVEL UP BONUS", 7 * (cursor == 1));
		printFontGrid(2, 5, "20G MODE",       7 * (cursor == 2));
		printFontGrid(2, 6, "START LEVEL",    7 * (cursor == 3));
		
		// 設定値表示
		if(hebopGhost == 0) sprintf(string[0], "LV100");
		else if(hebopGhost == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!hebopLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!hebop20G) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "%d", hebopStartLevel);
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
			
			if(cursor == 0) {
				hebopGhost = hebopGhost + move;
				if(hebopGhost < 0) hebopGhost = 2;
				if(hebopGhost > 2) hebopGhost = 0;
			}
			if(cursor == 1) hebopLvUpBonus = !hebopLvUpBonus;
			if(cursor == 2) hebop20G = !hebop20G;
			if(cursor == 3) {
				hebopStartLevel = hebopStartLevel + (move * 100);
				if(hebopStartLevel < 0) hebopStartLevel = 900;
				if(hebopStartLevel > 900) hebopStartLevel = 0;
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
			hebopSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			hebopViewRanking(player);
		}
	}
}

// 設定を保存
void hebopSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// 設定内容
	saveBuf[1] = hebopGhost;
	saveBuf[2] = hebopLvUpBonus;
	saveBuf[3] = hebop20G;
	saveBuf[4] = hebopStartLevel;
	
	SaveFile("config/HEBOP_CONFIG.SAV", &saveBuf, 50 * 4);
}

// 設定を読み込み
int hebopLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/HEBOP_CONFIG.SAV", &saveBuf, 50 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// 設定内容
	hebopGhost = saveBuf[1];
	hebopLvUpBonus = saveBuf[2];
	hebop20G = saveBuf[3];
	hebopStartLevel = saveBuf[4];
	
	return 1;
}

// リプレイ保存
void hebopSaveReplay(int player) {
	saveBuf[900] = hebopLevel[player];
	saveBuf[901] = hebopScore[player];
	saveBuf[902] = hebopGhost;
	saveBuf[903] = hebopLvUpBonus;
	saveBuf[904] = hebop20G;
	saveBuf[905] = hebopStartLevel;
	saveBuf[906] = hebopVersion;
}

// リプレイ読み込み
void hebopLoadReplay(int player) {
	hebopGhost = saveBuf[902];
	hebopLvUpBonus = saveBuf[903];
	hebop20G = saveBuf[904];
	hebopStartLevel = saveBuf[905];
	hebopVersion = saveBuf[906];
	
	hebopPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void hebopReplayDetail() {
	printFontGrid(1, 4, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[901]);
	printFontGrid(22, 4, string[0], 0);
	
	printFontGrid(1, 5, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[900]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 7, "GHOST BLOCK", 0);
	if(saveBuf[902] == 0) sprintf(string[0], "LV100");
	else if(saveBuf[902] == 1) sprintf(string[0], "ON");
	else sprintf(string[0], "OFF");
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 8, "LEVEL UP BONUS", 0);
	if(!saveBuf[903]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "20G MODE", 0);
	if(!saveBuf[904]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[905]);
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[906]);
	printFontGrid(22, 11, string[0], 0);
}

// ランキング保存
void hebopSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		saveBuf[1 + (i * 10) + 0] = hebopRankingTime[i];
		saveBuf[1 + (i * 10) + 1] = hebopRankingLevel[i];
		saveBuf[1 + (i * 10) + 2] = hebopRankingYear[i];
		saveBuf[1 + (i * 10) + 3] = hebopRankingMonth[i];
		saveBuf[1 + (i * 10) + 4] = hebopRankingDay[i];
		saveBuf[1 + (i * 10) + 5] = hebopRankingHour[i];
		saveBuf[1 + (i * 10) + 6] = hebopRankingMinute[i];
		saveBuf[1 + (i * 10) + 7] = hebopRankingSecond[i];
	}
	
	sprintf(string[0], "config/HEBOP_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 211 * 4);
}

// ランキング読み込み
int hebopLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/HEBOP_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 211 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 20; i++) {
		hebopRankingTime[i]   = saveBuf[1 + (i * 10) + 0];
		hebopRankingLevel[i]  = saveBuf[1 + (i * 10) + 1];
		hebopRankingYear[i]   = saveBuf[1 + (i * 10) + 2];
		hebopRankingMonth[i]  = saveBuf[1 + (i * 10) + 3];
		hebopRankingDay[i]    = saveBuf[1 + (i * 10) + 4];
		hebopRankingHour[i]   = saveBuf[1 + (i * 10) + 5];
		hebopRankingMinute[i] = saveBuf[1 + (i * 10) + 6];
		hebopRankingSecond[i] = saveBuf[1 + (i * 10) + 7];
	}
}

// ランキング初期化
void hebopInitRanking() {
	int i;
	
	for(i = 0; i < 20; i++) {
		hebopRankingTime[i] = 0;
		hebopRankingLevel[i] = 0;
		hebopRankingYear[i] = 0;
		hebopRankingMonth[i] = 0;
		hebopRankingDay[i] = 0;
		hebopRankingHour[i] = 0;
		hebopRankingMinute[i] = 0;
		hebopRankingSecond[i] = 0;
	}
}

// ランキング登録
int hebopRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (hebopStartLevel)) return -1;
	
	for(i = 0; i < 20; i++) {
		// ランクイン
		if((hebopLevel[player] > hebopRankingLevel[i]) || 
		   ((hebopLevel[player] == hebopRankingLevel[i]) && (gameTimer[player] < hebopRankingTime[i])))
		{
			// ランキングをずらす
			for(j = 19; j > i; j--) {
				hebopRankingTime[j]   = hebopRankingTime[j - 1];
				hebopRankingLevel[j]  = hebopRankingLevel[j - 1];
				hebopRankingYear[j]   = hebopRankingYear[j - 1];
				hebopRankingMonth[j]  = hebopRankingMonth[j - 1];
				hebopRankingDay[j]    = hebopRankingDay[j - 1];
				hebopRankingHour[j]   = hebopRankingHour[j - 1];
				hebopRankingMinute[j] = hebopRankingMinute[j - 1];
				hebopRankingSecond[j] = hebopRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			hebopRankingTime[i]   = gameTimer[player];
			hebopRankingLevel[i]  = hebopLevel[player];
			
			GetDateAndTime(&timebuf);
			hebopRankingYear[i]   = timebuf[0];
			hebopRankingMonth[i]  = timebuf[1];
			hebopRankingDay[i]    = timebuf[2];
			hebopRankingHour[i]   = timebuf[4];
			hebopRankingMinute[i] = timebuf[5];
			hebopRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void hebopViewRanking(int player) {
	int i, erasemode;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "HEBO+ MODE RANKING", 6);
		printFontGrid(1, 3, "RANK LV.  TIME     DATE", 4);
		
		for(i = 0; i < 20; i++) {
			if(hebopRankingLevel[i] >= 999) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, 2, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 0);
			
			sprintf(string[0], "%d", hebopRankingLevel[i]);
			printFontGrid(6, 4 + i, string[0], 0);
			
			getTime(hebopRankingTime[i]);
			printFontGrid(11, 4 + i, string[0], 0);
			
			sprintf(string[0], "%04d/%02d/%02d", hebopRankingYear[i], hebopRankingMonth[i], hebopRankingDay[i]);
			printFontGrid(20, 4 + i, string[0], 0);
			
			sprintf(string[0], "%02d:%02d:%02d", hebopRankingHour[i], hebopRankingMinute[i], hebopRankingSecond[i]);
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
				hebopInitRanking();
				hebopSaveRanking(player);
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
