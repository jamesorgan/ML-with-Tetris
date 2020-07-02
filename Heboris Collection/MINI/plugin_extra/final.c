//FINAL
//prefix:final

// レベルアップテーブル (固定時間リセットあり)
int finalWait1[10] = { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
int finalWait2[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int finalWait3[10] = { 9, 8, 7, 6, 5, 5, 5, 4, 4, 3};
int finalWaitt[10] = { 4, 4, 3, 3, 2, 2, 2, 1, 1, 0};

// レベルアップテーブル (固定時間リセットなし)
int finalNoResetWait1[10] = { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
int finalNoResetWait2[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int finalNoResetWait3[10] = {10,10, 9, 8, 7, 7, 6, 5, 5, 4};
int finalNoResetWaitt[10] = { 4, 4, 3, 3, 2, 2, 2, 1, 1, 0};

// 使用するBGM（プレイ中,エンディング）
int finalBgmListTable[2] = {5, 6};

// 裏段位の表示名
str finalStrSecretGradeName[19] = 
{
	 "M1",  "M2",  "M3",  "M4",  "M5",  "M6",  "M7",  "M8",  "M9",	//  0～ 8
	"M10", "M11", "M12", "M13", "M14", "M15", "M16", "M17", "M18",	//  9～17
	"GOD"															// 18
};

// 変数
int finalModeNo = -1;			// モード番号

int finalLevel[2];				// レベル
int finalScore[2];				// スコア
int finalLines[2];				// ライン
int finalEndFlag[2];			// クリアフラグ

int finalSectionTime[10 * 2];	// このプレイのセクションタイム
int finalSTimer[2];				// セクションタイマー
int finalSkill[2];				// 合計ヘボリス回数

int finalMedalStat[4 * 2];		// メダルの状態(0=なし 1=銅 2=銀 3=金)
int finalMedalAnim[4 * 2];		// メダル獲得アニメーション用カウンタ

int finalIsBig = 0;				// BIGかどうか
int finalBigMove = 1;			// BIG時の横移動単位
int finalLvUpBonus = 1;			// レベルアップボーナス
int finalStartLevel = 0;		// スタート時のレベル

// ランキング変数
int finalRankingLevel[10];			// レベル
int finalRankingTime[10];			// タイム
int finalRankingEnd[10];			// クリアフラグ
int finalRankingMedal[4 * 10];		// メダル
int finalRankingYear[10];			// ランクイン日時（年）
int finalRankingMonth[10];			// ランクイン日時（月）
int finalRankingDay[10];			// ランクイン日時（日）
int finalRankingHour[10];			// ランクイン日時（時）
int finalRankingMinute[10];			// ランクイン日時（分）
int finalRankingSecond[10];			// ランクイン日時（秒）
int finalRankingLines[10];			// ライン
int finalRankingScore[10];			// スコア
int finalRankingLockReset[10];		// 固定時間リセット

// セクションタイムランキング変数
int finalRankingSectionTime[10];	// タイム
int finalRankingSectionEnd[10];		// クリアフラグ
int finalRankingSectionYear[10];	// ランクイン日時（年）
int finalRankingSectionMonth[10];	// ランクイン日時（月）
int finalRankingSectionDay[10];		// ランクイン日時（日）
int finalRankingSectionHour[10];	// ランクイン日時（時）
int finalRankingSectionMinute[10];	// ランクイン日時（分）
int finalRankingSectionSecond[10];	// ランクイン日時（秒）

// イベント発生
void finalPluginEvent(int player, int event, int *param) {
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != finalModeNo)) return;
	
	if(event == 0) {
		finalModeNo = addModePlugin("FINAL");	// モードを登録する
	} else if(event == 7) {
		if(!ending[player]) finalMoveInit(player);	// ブロック出現
	} else if(event == 12) {
		if(!ending[player]) finalCalcScore(player, param[0]);	// スコア計算
	} else if(event == 15) {
		finalViewScore(player);	// スコア表示
	} else if(event == 17) {
		finalSetting(player, param);	// 設定画面
	} else if(event == 18) {
		finalPlayerInitial(player);	// 初期化処理
	} else if(event == 21) {
		finalResult(player);	// 結果表示
	} else if(event == 24) {
		finalEndingStart(player);	// エンディング突入
	} else if(event == 25) {
		finalExcellent(player, param);	// エンディング終了
	} else if(event == 28) {
		finalIncrementTime(player);	// 時間を進める
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		finalSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		finalLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		finalLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		finalReplayDetail();	// リプレイ詳細
	} else if(event == 67) {
		//finalDebug();	// デバッグ
	}
}

// 初期化処理
void finalPlayerInitial(int player) {
	int i;
	
	// 変数の初期化
	if(finalStartLevel > 0) finalLevel[player] = finalStartLevel;
	else finalLevel[player] = -1;
	backno = finalLevel[player] / 100;
	
	finalScore[player] = 0;
	finalLines[player] = 0;
	finalEndFlag[player] = 0;
	
	finalSTimer[player] = 0;
	finalSkill[player] = 0;
	
	for(i = 0; i < 4; i++) {
		finalMedalStat[player * 4 + i] = 0;
		finalMedalAnim[player * 4 + i] = -1;
	}
	
	for(i = 0; i < 10; i++) finalSectionTime[i + player * 10] = 0;
	
	// システム変数の設定
	enable_combo[player] = 1;
	framecolor[player] = 2;
	oblk_spawn[player] = 1;
	bgmlv = finalBgmListTable[0];
	
	// 設定を反映させる
	IsBig[player] = finalIsBig;
	BigMove[player] = finalBigMove;
	
	// 初期スピードを設定
	finalSpeedUp(player);
}

// スピードアップ
void finalSpeedUp(int player) {
	int index;
	
	// 20G
	sp[player] = 1200;
	
	// スピードを変える
	index = finalLevel[player] / 100;
	if(index < 0) index = 0;
	if(index > 9) index = 9;
	
	if(lockreset[player]) {
		// 固定時間リセットあり
		wait1[player] = finalWait1[index];
		wait2[player] = finalWait2[index];
		wait3[player] = finalWait3[index];
		waitt[player] = finalWaitt[index];
	} else {
		// 固定時間リセットなし
		wait1[player] = finalNoResetWait1[index];
		wait2[player] = finalNoResetWait2[index];
		wait3[player] = finalNoResetWait3[index];
		waitt[player] = finalNoResetWaitt[index];
	}
}

// ブロック出現
void finalMoveInit(int player) {
	// 最初のフレームなら
	if(statc[player * 10 + 3] == 0) {
		// レベルアップ処理
		if(finalLevel[player] % 100 != 99) {
			finalLevel[player]++;
			if(finalLevel[player] % 100 == 99) PlaySE(se_lvstop);
		}
	}
}

// スコア計算
void finalCalcScore(int player, int lines) {
	int i, temp, bo, nextsec, lv;
	
	finalLines[player] = finalLines[player] + lines;	// ライン数増加
	
	lv = finalLevel[player];	// 上がる前のレベル
	
	// ヘボリス回数増加
	if(lines >= 4) {
		finalSkill[player]++;
		
		// SKメダル獲得
		if((finalSkill[player] == 5) || (finalSkill[player] == 10) || (finalSkill[player] == 17)) {
			PlaySE(se_medal);
			finalMedalStat[player * 4 + 3]++;
			finalMedalAnim[player * 4 + 3] = 0;
		}
	}
	
	// COメダル獲得
	if(combo2[player] == 4) {
		if(finalMedalStat[player * 4 + 2] < 1) {
			PlaySE(se_medal);
			finalMedalStat[player * 4 + 2] = 1;
			finalMedalAnim[player * 4 + 2] = 0;
		}
	} else if(combo2[player] == 5) {
		if(finalMedalStat[player * 4 + 2] < 2) {
			PlaySE(se_medal);
			finalMedalStat[player * 4 + 2] = 2;
			finalMedalAnim[player * 4 + 2] = 0;
		}
	} else if(combo2[player] == 7) {
		if(finalMedalStat[player * 4 + 2] < 3) {
			PlaySE(se_medal);
			finalMedalStat[player * 4 + 2] = 3;
			finalMedalAnim[player * 4 + 2] = 0;
		}
	}
	
	// 全消し
	if(isBravo(player)) {
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		
		// ACメダル獲得
		if(finalMedalStat[player * 4 + 1] < 3) {
			PlaySE(se_medal);
			finalMedalStat[player * 4 + 1]++;
			finalMedalAnim[player * 4 + 1] = 0;
		}
	}
	
	// レベルアップ
	nextsec = finalLevel[player] / 100 * 100 + 100;
	if(!finalLvUpBonus) finalLevel[player] = finalLevel[player] + lines;
	else finalLevel[player] = finalLevel[player] + lines + ((lines >= 3) * (lines - 2));
	
	if(finalLevel[player] >= 999) {
		// エンディング
		finalLevel[player] = 999;
		ending[player] = 1;
		timeOn[player] = 0;
		finalEndFlag[player] = 1;
		
		// STメダル獲得
		finalMedalST(player, 9);
		
		// セクションタイマーをリセット
		finalSTimer[player] = 0;
	} else {
		// レベルストップ音
		if(finalLevel[player] % 100 == 99) PlaySE(se_lvstop);
		
		if(finalLevel[player] >= nextsec) {
			// レベルアップ音
			PlaySE(se_levelup);
			
			// 背景切り替え
			bgfadesw = 1;
			bgfadebg = nextsec / 100;
			
			// STメダル獲得
			finalMedalST(player, (nextsec / 100) - 1);
			
			// セクションタイマーをリセット
			finalSTimer[player] = 0;
			
			// スピードアップ
			finalSpeedUp(player);
		}
	}
	
	// スコア計算
	temp = wait3[player] - bactivetime[player];
	if(temp < 0) temp = 0;
	
	bo = ((lv + lines) / 4 + (sdrop[player] / 2) + qdrop[player] + qput[player]) * lines * cmbpts[player] + (finalLevel[player] / 2) + temp;
	
	// スコア加算
	finalScore[player] = finalScore[player] + bo;
}

// STメダル獲得
void finalMedalST(int player, int section) {
	// セクションタイムを記録
	finalSectionTime[section + player * 10] = finalSTimer[player];
	
	// STメダル獲得判定
	if((!playback) && (!finalIsBig) && (finalLvUpBonus) && (!finalStartLevel)) {
		if((finalSTimer[player] < finalRankingSectionTime[section]) && (finalMedalStat[player * 4 + 0] < 3)) {
			PlaySE(se_medal);
			finalMedalStat[player * 4 + 0] = 3;
			finalMedalAnim[player * 4 + 0] = 0;
		} else if((finalSTimer[player] < finalRankingSectionTime[section] + 300) && (finalMedalStat[player * 4 + 0] < 2)) {
			PlaySE(se_medal);
			finalMedalStat[player * 4 + 0] = 2;
			finalMedalAnim[player * 4 + 0] = 0;
		} else if((finalSTimer[player] < finalRankingSectionTime[section] + 600) && (finalMedalStat[player * 4 + 0] < 1)) {
			PlaySE(se_medal);
			finalMedalStat[player * 4 + 0] = 1;
			finalMedalAnim[player * 4 + 0] = 0;
		}
	}
}

// 時間を進める
void finalIncrementTime(int player) {
	int i;
	
	// セクションタイム増加
	if(timeOn[player]) finalSTimer[player]++;
	
	// ロール終了
	if((ending[player] == 2) && (edrec[player] >= 60 * 60)) {
		ending[player] = 3;
		stat[player] = 10;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
}

// エンディング突入
void finalEndingStart(int player) {
	int i;
	
	for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	
	ending[player] = 2;
	stat[player] = 4;
	ending_timeOn[player] = 1;
	fastroll[player] = 0;
	
	hidden[player] = 10;
	
	bgmlv = finalBgmListTable[1];
	PlayBGM();
}

// エンディング終了
void finalExcellent(int player, int *param) {
	param[0] = 2;
	onRecord[player] = 0;
	hidden[player] = 0;
	finalEndFlag[player] = 2;
	
	// 花火
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// BGM読み込み
void finalLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 2; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/2)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(finalBgmListTable[i]);
		}
	}
}

// スコアを表示
void finalViewScore(int player) {
	int i, x, y, color, kind;
	color = (count % 4 / 2) * 7;
	
	// メダル（通常）
	for(i = 0; i < 4; i++) {
		if((finalMedalAnim[player * 4 + i] < 0) || (finalMedalAnim[player * 4 + i] > 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 17;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			if(i == 0) kind = 1;
			if(i == 1) kind = 0;
			if(i == 2) kind = 5;
			if(i == 3) kind = 2;
			finalDrawMedal(x, y, kind, finalMedalStat[player * 4 + i], finalMedalAnim[player * 4 + i]);
		}
	}
	
	// メダル（アニメ中）
	for(i = 0; i < 4; i++) {
		if((finalMedalAnim[player * 4 + i] >= 0) && (finalMedalAnim[player * 4 + i] <= 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 17;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			if(i == 0) kind = 1;
			if(i == 1) kind = 0;
			if(i == 2) kind = 5;
			if(i == 3) kind = 2;
			finalDrawMedal(x, y, kind, finalMedalStat[player * 4 + i], finalMedalAnim[player * 4 + i]);
			finalMedalAnim[player * 4 + i]++;
		}
	}
	
	// レベル（分子）
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(finalLevel[player] == -1) sprintf(string[0], "%4d", 0);	// -1なら0と表示する(内部的には最初は-1になっている)
	else sprintf(string[0], "%4d", finalLevel[player]);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// レベル（横線）
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 0, 143, 22, 1);
	
	// レベル（分母）
	if(finalLevel[player] >= 900) sprintf(string[0], "%4d", 999);
	else sprintf(string[0], "%4d", finalLevel[player] / 100 * 100 + 100);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, string[0], color);
	
	// タイム
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
}

// メダルを表示
void finalDrawMedal(int x, int y, int kind, int color, int anim) {
	int i, j, k;
	
	if(color == 0) return;
	
	if((anim >= 0) && (anim < 16)) {
		if(anim <= 8) {
			k = anim;
			i = (16 * k / 2 - 16) / 2;
			j = (12 * k / 2 - 12) / 2;
			k = 65536 * k / 2;
		} else {
			k = 16 - anim;
			i = (16 * k / 3 - 16) / 2;
			j = (12 * k / 3 - 12) / 2;
			k = 65536 * k / 3;
			
			if(k < 65536) {
				k = 65536;
				i = 0;
				j = 0;
			}
		}
		
		ExBltRectR(sg_medal[1], x - i, y - j, kind * 16, color * 12, 16, 12, k, k);
	} else {
		ExBltRect(sg_medal[1], x, y, kind * 16, color * 12, 16, 12);
	}
}

// 結果表示
void finalResult(int player) {
	if(statc[player * 10] == 0) {
		// ランキング登録
		statc[player * 10 + 1] = finalRegistRanking(player);
		statc[player * 10 + 2] = finalUpdateSectionTimeRanking(player);
		if((statc[player * 10 + 1] != -1) || (statc[player * 10 + 2] != 0)) finalSaveRanking(player);
		
		// 裏段位判定
		statc[player * 10 + 3] = checkSecretGrade(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 45, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 59, "SCORE");
	sprintf(string[0], "%13d", finalScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 67, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", finalLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", finalLevel[player]);
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
	
	if(statc[player * 10 + 2] != 0) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 159, "ST RECORDS");
		sprintf(string[0], "%13d", statc[player * 10 + 2]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
	}
	
	if(statc[player * 10 + 3] >= 4) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 179, "SECRET GRADE");
		sprintf(string[0], "%13s", finalStrSecretGradeName[statc[player * 10 + 3]]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 187, string[0], 0);
	}
}

// 設定画面
void finalSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(finalLoadConfig() == 0) finalSaveConfig();
	
	// ランキングを読み込み
	if(finalLoadRanking(player) == 0) finalInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "FINAL OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",            7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",       7 * (cursor == 1));
		printFontGrid(2, 5, "LEVEL UP BONUS", 7 * (cursor == 2));
		printFontGrid(2, 6, "START LEVEL",    7 * (cursor == 3));
		
		// 設定値表示
		if(!finalIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!finalBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!finalLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "%d", finalStartLevel);
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
			
			if(cursor == 0) finalIsBig = !finalIsBig;
			if(cursor == 1) finalBigMove = !finalBigMove;
			if(cursor == 2) finalLvUpBonus = !finalLvUpBonus;
			if(cursor == 3) {
				finalStartLevel = finalStartLevel + (move * 100);
				if(finalStartLevel < 0) finalStartLevel = 900;
				if(finalStartLevel > 900) finalStartLevel = 0;
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
			finalSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			finalViewRanking(player);
		}
	}
}

// 設定を保存
void finalSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// 設定内容
	saveBuf[1] = finalIsBig;
	saveBuf[2] = finalBigMove;
	saveBuf[3] = finalLvUpBonus;
	saveBuf[4] = finalStartLevel;
	
	SaveFile("config/FINAL_CONFIG.SAV", &saveBuf, 50 * 4);
}

// 設定を読み込み
int finalLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/FINAL_CONFIG.SAV", &saveBuf, 50 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// 設定内容
	finalIsBig = saveBuf[1];
	finalBigMove = saveBuf[2];
	finalLvUpBonus = saveBuf[3];
	finalStartLevel = saveBuf[4];
	
	return 1;
}

// リプレイ保存
void finalSaveReplay(int player) {
	saveBuf[900] = finalScore[player];
	saveBuf[901] = finalLevel[player];
	saveBuf[902] = finalIsBig;
	saveBuf[903] = finalBigMove;
	saveBuf[904] = finalLvUpBonus;
	saveBuf[905] = finalLines[player];
	saveBuf[906] = finalStartLevel;
}

// リプレイ読み込み
void finalLoadReplay(int player) {
	finalIsBig = saveBuf[902];
	finalBigMove = saveBuf[903];
	finalLvUpBonus = saveBuf[904];
	finalStartLevel = saveBuf[906];
	
	finalPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void finalReplayDetail() {
	printFontGrid(1, 5, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[900]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "LINES", 0);
	sprintf(string[0], "%d", saveBuf[905]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[901]);
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 9, "BIG", 0);
	if(!saveBuf[902]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "BIG MOVE", 0);
	if(!saveBuf[903]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "LEVEL UP BONUS", 0);
	if(!saveBuf[904]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[906]);
	printFontGrid(22, 12, string[0], 0);
}

// デバッグ
/*
void finalDebug() {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	loop {
		spriteTime();
		KeyInput();
		
		printFontGrid(1, 1, "FINAL MODE DEBUG MENU", 4);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "SLOW SPEED", 7 * (cursor == 0));
		printFontGrid(2, 4, "LEVEL WARP", 7 * (cursor == 1));
		printFontGrid(2, 5, "NO HIDDEN",  7 * (cursor == 2));
		
		// カーソル移動
		padRepeat2(0);
		
		move = 0;
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
			move = getPressState(0, 1) - getPressState(0, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 2;
			if(cursor > 2) cursor = 0;
		}
		
		// 戻る
		if(getPushState(0, 5)) {
			return;
		}
		
		// 決定
		if(getPushState(0, 4)) {
			PlayWave(se_kettei);
			
			if(cursor == 0) {
				wait1[0] = 25;
				wait2[0] = 5;
				wait3[0] = 30;
				waitt[0] = 12;
			}
			if(cursor == 1) {
				finalLevel[0] = 998;
			}
			if(cursor == 2) {
				hidden[0] = 0;
			}
		}
	}
}
*/

// ランキング保存
void finalSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0]  = finalRankingLevel[i];
		saveBuf[1 + (i * 20) + 1]  = finalRankingTime[i];
		saveBuf[1 + (i * 20) + 2]  = finalRankingEnd[i];
		saveBuf[1 + (i * 20) + 3]  = finalRankingMedal[i * 4 + 0];
		saveBuf[1 + (i * 20) + 4]  = finalRankingMedal[i * 4 + 1];
		saveBuf[1 + (i * 20) + 5]  = finalRankingMedal[i * 4 + 2];
		saveBuf[1 + (i * 20) + 6]  = finalRankingMedal[i * 4 + 3];
		saveBuf[1 + (i * 20) + 7]  = finalRankingYear[i];
		saveBuf[1 + (i * 20) + 8]  = finalRankingMonth[i];
		saveBuf[1 + (i * 20) + 9]  = finalRankingDay[i];
		saveBuf[1 + (i * 20) + 10] = finalRankingHour[i];
		saveBuf[1 + (i * 20) + 11] = finalRankingMinute[i];
		saveBuf[1 + (i * 20) + 12] = finalRankingSecond[i];
		saveBuf[1 + (i * 20) + 13] = finalRankingLines[i];
		saveBuf[1 + (i * 20) + 14] = finalRankingScore[i];
		saveBuf[1 + (i * 20) + 15] = finalRankingLockReset[i];
	}
	
	// セクションタイムランキング
	for(i = 0; i < 10; i++) {
		saveBuf[221 + (i * 10) + 0] = finalRankingSectionTime[i];
		saveBuf[221 + (i * 10) + 1] = finalRankingSectionEnd[i];
		saveBuf[221 + (i * 10) + 2] = finalRankingSectionYear[i];
		saveBuf[221 + (i * 10) + 3] = finalRankingSectionMonth[i];
		saveBuf[221 + (i * 10) + 4] = finalRankingSectionDay[i];
		saveBuf[221 + (i * 10) + 5] = finalRankingSectionHour[i];
		saveBuf[221 + (i * 10) + 6] = finalRankingSectionMinute[i];
		saveBuf[221 + (i * 10) + 7] = finalRankingSectionSecond[i];
	}
	
	sprintf(string[0], "config/FINAL_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 331 * 4);
}

// ランキング読み込み
int finalLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/FINAL_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 331 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		finalRankingLevel[i]         = saveBuf[1 + (i * 20) + 0];
		finalRankingTime[i]          = saveBuf[1 + (i * 20) + 1];
		finalRankingEnd[i]           = saveBuf[1 + (i * 20) + 2];
		finalRankingMedal[i * 4 + 0] = saveBuf[1 + (i * 20) + 3];
		finalRankingMedal[i * 4 + 1] = saveBuf[1 + (i * 20) + 4];
		finalRankingMedal[i * 4 + 2] = saveBuf[1 + (i * 20) + 5];
		finalRankingMedal[i * 4 + 3] = saveBuf[1 + (i * 20) + 6];
		finalRankingYear[i]          = saveBuf[1 + (i * 20) + 7];
		finalRankingMonth[i]         = saveBuf[1 + (i * 20) + 8];
		finalRankingDay[i]           = saveBuf[1 + (i * 20) + 9];
		finalRankingHour[i]          = saveBuf[1 + (i * 20) + 10];
		finalRankingMinute[i]        = saveBuf[1 + (i * 20) + 11];
		finalRankingSecond[i]        = saveBuf[1 + (i * 20) + 12];
		finalRankingLines[i]         = saveBuf[1 + (i * 20) + 13];
		finalRankingScore[i]         = saveBuf[1 + (i * 20) + 14];
		finalRankingLockReset[i]     = saveBuf[1 + (i * 20) + 15];
	}
	
	// セクションタイムランキング
	for(i = 0; i < 10; i++) {
		finalRankingSectionTime[i]   = saveBuf[221 + (i * 10) + 0];
		finalRankingSectionEnd[i]    = saveBuf[221 + (i * 10) + 1];
		finalRankingSectionYear[i]   = saveBuf[221 + (i * 10) + 2];
		finalRankingSectionMonth[i]  = saveBuf[221 + (i * 10) + 3];
		finalRankingSectionDay[i]    = saveBuf[221 + (i * 10) + 4];
		finalRankingSectionHour[i]   = saveBuf[221 + (i * 10) + 5];
		finalRankingSectionMinute[i] = saveBuf[221 + (i * 10) + 6];
		finalRankingSectionSecond[i] = saveBuf[221 + (i * 10) + 7];
	}
	
	return 1;
}

// ランキング初期化
void finalInitRanking() {
	int i;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		finalRankingLevel[i]         = 0;
		finalRankingTime[i]          = 0;
		finalRankingEnd[i]           = 0;
		finalRankingMedal[i * 4 + 0] = 0;
		finalRankingMedal[i * 4 + 1] = 0;
		finalRankingMedal[i * 4 + 2] = 0;
		finalRankingMedal[i * 4 + 3] = 0;
		finalRankingYear[i]          = 0;
		finalRankingMonth[i]         = 0;
		finalRankingDay[i]           = 0;
		finalRankingHour[i]          = 0;
		finalRankingMinute[i]        = 0;
		finalRankingSecond[i]        = 0;
		finalRankingLines[i]         = 0;
		finalRankingScore[i]         = 0;
		finalRankingLockReset[i]     = 0;
	}
	
	// セクションタイムランキング
	for(i = 0; i < 10; i++) {
		finalRankingSectionTime[i]   = 1800;
		finalRankingSectionEnd[i]    = 0;
		finalRankingSectionYear[i]   = 0;
		finalRankingSectionMonth[i]  = 0;
		finalRankingSectionDay[i]    = 0;
		finalRankingSectionHour[i]   = 0;
		finalRankingSectionMinute[i] = 0;
		finalRankingSectionSecond[i] = 0;
	}
}

// ランキング登録
int finalRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (finalIsBig) || (!finalLvUpBonus) || (finalStartLevel)) return -1;
	
	for(i = 0; i < 10; i++) {
		// ランクイン
		if(
		    (finalEndFlag[player] > finalRankingEnd[i]) || 
		    ((finalEndFlag[player] == finalRankingEnd[i]) && (finalLevel[player] > finalRankingLevel[i])) || 
		    ((finalEndFlag[player] == finalRankingEnd[i]) && (finalLevel[player] == finalRankingLevel[i]) && (gameTimer[player] < finalRankingTime[i]))
		  )
		{
			// ランキングをずらす
			for(j = 9; j > i; j--) {
				finalRankingLevel[j]         = finalRankingLevel[j - 1];
				finalRankingTime[j]          = finalRankingTime[j - 1];
				finalRankingEnd[j]           = finalRankingEnd[j - 1];
				finalRankingMedal[j * 4 + 0] = finalRankingMedal[(j - 1) * 4 + 0];
				finalRankingMedal[j * 4 + 1] = finalRankingMedal[(j - 1) * 4 + 1];
				finalRankingMedal[j * 4 + 2] = finalRankingMedal[(j - 1) * 4 + 2];
				finalRankingMedal[j * 4 + 3] = finalRankingMedal[(j - 1) * 4 + 3];
				finalRankingYear[j]          = finalRankingYear[j - 1];
				finalRankingMonth[j]         = finalRankingMonth[j - 1];
				finalRankingDay[j]           = finalRankingDay[j - 1];
				finalRankingHour[j]          = finalRankingHour[j - 1];
				finalRankingMinute[j]        = finalRankingMinute[j - 1];
				finalRankingSecond[j]        = finalRankingSecond[j - 1];
				finalRankingLines[j]         = finalRankingLines[j - 1];
				finalRankingScore[j]         = finalRankingScore[j - 1];
				finalRankingLockReset[j]     = finalRankingLockReset[j - 1];
			}
			
			// 新しいデータを登録
			finalRankingLevel[i]         = finalLevel[player];
			finalRankingTime[i]          = gameTimer[player];
			finalRankingEnd[i]           = finalEndFlag[player];
			finalRankingMedal[i * 4 + 0] = finalMedalStat[player * 4 + 0];
			finalRankingMedal[i * 4 + 1] = finalMedalStat[player * 4 + 1];
			finalRankingMedal[i * 4 + 2] = finalMedalStat[player * 4 + 2];
			finalRankingMedal[i * 4 + 3] = finalMedalStat[player * 4 + 3];
			finalRankingLines[i]         = finalLines[player];
			finalRankingScore[i]         = finalScore[player];
			finalRankingLockReset[i]     = lockreset[player];
			
			GetDateAndTime(&timebuf);
			finalRankingYear[i]          = timebuf[0];
			finalRankingMonth[i]         = timebuf[1];
			finalRankingDay[i]           = timebuf[2];
			finalRankingHour[i]          = timebuf[4];
			finalRankingMinute[i]        = timebuf[5];
			finalRankingSecond[i]        = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// セクションタイムランキング更新
int finalUpdateSectionTimeRanking(int player) {
	int i, timebuf[8], result;
	result = 0;
	
	if((playback) || (finalIsBig) || (!finalLvUpBonus) || (finalStartLevel)) return 0;
	
	for(i = 0; i < 10; i++) {
		if((finalSectionTime[i + player * 10] < finalRankingSectionTime[i]) && (finalSectionTime[i + player * 10] != 0)) {
			result++;
			
			finalRankingSectionTime[i] = finalSectionTime[i + player * 10];
			finalRankingSectionEnd[i] = finalEndFlag[player];
			
			GetDateAndTime(&timebuf);
			finalRankingSectionYear[i] = timebuf[0];
			finalRankingSectionMonth[i] = timebuf[1];
			finalRankingSectionDay[i] = timebuf[2];
			finalRankingSectionHour[i] = timebuf[4];
			finalRankingSectionMinute[i] = timebuf[5];
			finalRankingSectionSecond[i] = timebuf[6];
		}
	}
	
	return result;
}

// ランキング表示
void finalViewRanking(int player) {
	int i, cursor, move, erasemode, stmode, temp;
	cursor = 0;
	move = 0;
	erasemode = 0;
	stmode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		if(!stmode) {
			// ノーマルランキング
			printFontGrid(1, 1, "FINAL MODE RANKING >>", 6);
			printFontGrid(1, 3, "RANK LEVEL LINES SCORE  TIME     LOCK", 4);
			
			for(i = 0; i < 10; i++) {
				if(finalRankingEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (finalRankingEnd[i] - 1) * 2, 320, 2);
				
				if(i == 0) sprintf(string[0], " 1ST");
				if(i == 1) sprintf(string[0], " 2ND");
				if(i == 2) sprintf(string[0], " 3RD");
				if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
				printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
				
				sprintf(string[0], "%d", finalRankingLevel[i]);
				printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
				
				sprintf(string[0], "%d", finalRankingLines[i]);
				printFontGrid(12, 4 + i, string[0], 7 * (cursor == i));
				
				sprintf(string[0], "%d", finalRankingScore[i]);
				printFontGrid(18, 4 + i, string[0], 7 * (cursor == i));
				
				getTime(finalRankingTime[i]);
				printFontGrid(25, 4 + i, string[0], 7 * (cursor == i));
				
				if(finalRankingLockReset[i]) sprintf(string[0], "RESET");
				else sprintf(string[0], "NONE");
				printFontGrid(34, 4 + i, string[0], 7 * (cursor == i));
			}
			
			for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
			
			if(!erasemode) {
				// メダル
				finalDrawMedal(8 + 0 * 16, 192, 1, finalRankingMedal[cursor * 4 + 0], -1);
				finalDrawMedal(8 + 1 * 16, 192, 0, finalRankingMedal[cursor * 4 + 1], -1);
				finalDrawMedal(8 + 2 * 16, 192, 5, finalRankingMedal[cursor * 4 + 2], -1);
				finalDrawMedal(8 + 3 * 16, 192, 2, finalRankingMedal[cursor * 4 + 3], -1);
				
				// 日付と時刻
				sprintf(string[0],
				        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
				        finalRankingYear[cursor], finalRankingMonth[cursor], finalRankingDay[cursor],
				        finalRankingHour[cursor], finalRankingMinute[cursor], finalRankingSecond[cursor]);
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
				
				// ランキング切り替え
				if(getPushState(player, 2) || getPushState(player, 3)) {
					PlaySE(se_move);
					stmode = !stmode;
				}
			} else {
				printFontGrid(1, 24, "ERASE ALL RECORDS?", 2);
				printFontGrid(1, 26, "A:YES / B:NO", 2);
				
				// 消去
				if(getPushState(player, 4)) {
					PlayWave(se_kettei);
					finalInitRanking();
					finalSaveRanking(player);
					erasemode = 0;
				}
				
				// 戻る
				if(getPushState(player, 5)) {
					PlaySE(se_move);
					erasemode = 0;
				}
			}
		} else {
			// セクションタイムランキング
			printFontGrid(1, 1, "<< FINAL MODE SECTION TIME", 6);
			printFontGrid(1, 3, "SECTION TIME     DATE", 4);
			printFontGrid(1, 28, "A/B:EXIT", 6);
			
			for(i = 0; i < 10; i++) {
				if(finalRankingSectionEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (finalRankingSectionEnd[i] - 1) * 2, 320, 2);
				
				sprintf(string[0], "%3d-%3d", i * 100, ((i + 1) * 100) - 1);
				printFontGrid(1, 4 + i, string[0], 0);
				
				getTime(finalRankingSectionTime[i]);
				printFontGrid(9, 4 + i, string[0], 0);
				
				temp = (finalRankingSectionYear[i] / 1000) * 1000;	// 年を下2桁だけ表示
				if(temp == 0) temp = 1;
				sprintf(string[0], "%02d/%02d/%02d", finalRankingSectionYear[i] % temp, finalRankingSectionMonth[i], finalRankingSectionDay[i]);
				printFontGrid(18, 4 + i, string[0], 0);
				
				sprintf(string[0], "%02d:%02d:%02d", finalRankingSectionHour[i], finalRankingSectionMinute[i], finalRankingSectionSecond[i]);
				printFontGrid(27, 4 + i, string[0], 0);
			}
			
			// 戻る
			if(getPushState(player, 4) || getPushState(player, 5)) {
				PlaySE(se_move);
				return;
			}
			
			// ランキング切り替え
			if(getPushState(player, 2) || getPushState(player, 3)) {
				PlaySE(se_move);
				stmode = !stmode;
			}
		}
	}
}
