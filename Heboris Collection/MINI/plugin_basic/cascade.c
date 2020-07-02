//CASCADE
//prefix:cas

// バージョン
int casVersion;			// バージョン番号（古いリプレイ再生用）
int casCVersion = 1;	// 現在のバージョン

// レベルアップテーブル（LV12でスピードタイプが通常モードになる）
int casLevelTable[15] = 
{
//   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15
    60,  48,  36,  28,  22,  16,  12,   8,   6,   4,   2,  60, 180, 300,1200
};

// 変数
int casModeNo = -1;			// モード番号

int casMarkFld[10 * 22];	// 落下処理で使用するブロック識別用フィールド

int casScore[2];			// スコア
int casNowChain[2];			// 現在の連鎖数
int casMaxChain[2];			// 最大連鎖数
int casLevel[2];			// 現在のレベル
int casGoal[2];				// レベルアップまでのポイント数

int casChainGet[2];			// 連鎖数表示
int casChainFrame[2];		// 連鎖数表示の残り時間
int casScoreGet[2];			// 今入ったスコア表示の点数
int casScoreFrame[2];		// 今入ったスコア表示の残り時間
int casGoalGet[2];			// 今入ったポイント表示の点数
int casGoalFrame[2];		// 今入ったポイント表示の残り時間

int casBgm = 20;			// 使用するBGM
int casGhost = 1;			// ゴーストの設定
int casFieldView = 0;		// フィールドの表示タイプ
int casStartLevel = 0;		// スタート時のレベル

// ランキング用変数
int casRankingScore[10];	// スコア
int casRankingChain[10];	// 最大連鎖数
int casRankingLevel[10];	// レベル
int casRankingTime[10];		// タイム
int casRankingYear[10];		// ランクイン日時（年）
int casRankingMonth[10];	// ランクイン日時（月）
int casRankingDay[10];		// ランクイン日時（日）
int casRankingHour[10];		// ランクイン日時（時）
int casRankingMinute[10];	// ランクイン日時（分）
int casRankingSecond[10];	// ランクイン日時（秒）

// イベント発生
void casPluginEvent(int player, int event, int *param) {
	int i;
	
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != casModeNo)) return;
	
	if(event == 0) {
		casModeNo = addModePlugin("CASCADE");	// モードを登録する
	} else if(event == 7) {
		casMoveInit(player, param);	// ブロック出現
	} else if(event == 8) {
		casSoftDropScore(player);	// ソフトドロップで入った点数を加算
	} else if(event == 11) {
		casAfterErase(player, param);	// ライン消去
	} else if(event == 12) {
		casCalcScore(player, param[0]);	// スコア計算
	} else if(event == 15) {
		casViewScore(player);	// スコア表示
	} else if(event == 17) {
		casSetting(player, param);	// 設定画面
	} else if(event == 18) {
		casPlayerInitial(player);	// 初期化
	} else if(event == 21) {
		casResult(player);	// 結果表示
	} else if(event == 24) {
		onRecord[player] = 0;	// エンディング突入
		ending[player] = 3;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		casExcellent(player, param);	// EXCELLENT画面
	} else if(event == 34) {
		if(casFieldView) casViewFieldBlock(player, param);	// フィールドのブロックを表示
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		casSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		casLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		casLoadBGM();	// BGM読み込み
	} else if(event == 48) {
		casSoftDropOld(player);	// ソフトドロップ
	} else if(event == 49) {
		casHardDrop(player, param[1]);	// ハードドロップ
	} else if(event == 55) {
		casReplayDetail();	// リプレイ詳細
	}
}

// ライン消去
void casAfterErase(int player, int *param) {
	int i, j, temp, fall;
	
	if(statc[player * 10] == 0) {
		// 連鎖数+1
		casNowChain[player]++;
		if(casNowChain[player] > casMaxChain[player]) casMaxChain[player] = casNowChain[player];
		casChainGet[player] = casNowChain[player];
		casChainFrame[player] = 120;
		return;
	}
	
	if(statc[player * 10] == wait2[player]) {
		param[0] = 1;	// 通常のライン消去後の処理をスキップする
		
		for(i = 21; i >= 0; i--) {
			if(erase[i + player * 22]) {
				// 消したラインの1マス上下のブロックの繋がりを外す
				for(j = 0; j < 10; j++) {
					// 上
					temp = getFieldBlockL(player, j, i - 1);
					temp = BitSet(temp, 1, 0);
					setFieldBlockL(player, j, i - 1, temp);
					
					// 下
					temp = getFieldBlockL(player, j, i + 1);
					temp = BitSet(temp, 0, 0);
					setFieldBlockL(player, j, i + 1, temp);
				}
			}
		}
	}
	
	if(statc[player * 10] >= wait2[player]) {
		param[0] = 1;	// 通常のライン消去後の処理をスキップする
		
		// 落下
		fall = 0;
		
		for(i = 21; i >= 0; i--) {
			for(j = 0; j < 10; j++) {
				if(casFallBlock(player, j, i)) fall = 1;
			}
		}
		
		// 落ちなくなったら終わり
		if(!fall) {
			PlaySE(se_gon);
			pinchCheck(player);
			
			if(blockEraseJudge(player)) {
				// 連鎖
				statc[player * 10] = 0;
			} else {
				// 終了
				stat[player] = 5;
				statc[player * 10] = wait1[player];
			}
			return;
		}
	}
	
	if(param[0]) statc[player * 10]++;
}

// 浮いたブロックを落とす（落ちた場合は戻り値が1になる）
int casFallBlock(int player, int x, int y) {
	int i, j, fall, temp;
	
	fall = 0;
	
	if( (getFieldBlock(player, x, y) > 0) && ((casVersion >= 1) || (!casMarkFld[x + y * 10])) ) {
		fall = 1;
		
		for(i = 0; i < 220; i++) casMarkFld[i] = 0;
		casCheckBlockLink(player, x, y);
		
		// ブロックの下に空間があるかチェック（無かったら中止）
		for(i = 21; i >= 0; i--) {
			for(j = 0; j < 10; j++) {
				if(casMarkFld[j + i * 10] == 1) {
					if( (i == 21) || ((getFieldBlock(player, j, i + 1) != 0) && (casMarkFld[j + (i + 1) * 10] != 1)) ) {
						fall = 0;
					}
				}
			}
		}
		
		// 1マス下に落とす
		if(fall) {
			for(i = 21; i >= 0; i--) {
				for(j = 0; j < 10; j++) {
					if(casMarkFld[j + i * 10] == 1) {
						temp = getFieldBlock(player, j, i);
						setFieldBlock(player, j, i + 1, temp);
						temp = getFieldBlockT(player, j, i);
						setFieldBlockT(player, j, i + 1, temp);
						temp = getFieldBlockO(player, j, i);
						setFieldBlockO(player, j, i + 1, temp);
						temp = getFieldBlockL(player, j, i);
						setFieldBlockL(player, j, i + 1, temp);
						temp = getFieldBlockI(player, j, i);
						setFieldBlockI(player, j, i + 1, temp);
						
						setFieldBlock(player, j, i, 0);
						setFieldBlockT(player, j, i, 0);
						setFieldBlockO(player, j, i, 0);
						setFieldBlockL(player, j, i, 0);
						setFieldBlockI(player, j, i, 0);
					}
				}
			}
		}
	}
	
	return fall;
}

// 繋がっているブロックを調べる
void casCheckBlockLink(int player, int x, int y) {
	int temp;
	
	if((x >= 0) && (x < 10) && (y >= 0) && (y < 22)) {
		if((getFieldBlock(player, x, y) > 0) && (casMarkFld[x + y * 10] == 0)) {
			casMarkFld[x + y * 10] = 1;
			
			temp = getFieldBlockL(player, x, y);
			if(BitTest(temp, 0)) casCheckBlockLink(player, x, y - 1);
			if(BitTest(temp, 1)) casCheckBlockLink(player, x, y + 1);
			if(BitTest(temp, 2)) casCheckBlockLink(player, x - 1, y);
			if(BitTest(temp, 3)) casCheckBlockLink(player, x + 1, y);
		}
	}
}

// 初期化
void casPlayerInitial(int player) {
	// バージョン
	if(!playback) casVersion = casCVersion;
	
	// 変数を初期化
	casScore[player] = 0;
	casNowChain[player] = 0;
	casMaxChain[player] = 0;
	casLevel[player] = casStartLevel;
	casGoal[player] = 5 * (casLevel[player] + 1);
	
	casChainGet[player] = 0;
	casChainFrame[player] = 0;
	casScoreGet[player] = 0;
	casScoreFrame[player] = 0;
	casGoalGet[player] = 0;
	casGoalFrame[player] = 0;
	
	// 初期速度
	sp[player] = casLevelTable[casLevel[player]];
	if(casLevel[player] >= 11) speedtype[player] = 0;
	else speedtype[player] = 1;
	wait2[player] = 20;
	
	// 枠の色を変える
	framecolor[player] = 5;
	frame_decoration[player] = 1;
	
	// 設定を反映させる
	bgmlv = casBgm;
	if(casGhost == 0) ghost[player] = 0;
	backno = casLevel[player];
}

// スコア計算
void casCalcScore(int player, int lines) {
	int sc, chain, bravo;
	
	// 全消しチェック
	if(isBravo(player)) {
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		bravo = 10;
	} else {
		bravo = 1;
	}
	
	// スコア
	chain = (casNowChain[player] - 1) * 10;
	if(chain < 1) chain = 1;
	sc = lines * chain * (casLevel[player] + 1) * 100 * bravo;
	casScoreGet[player] = sc;
	casScoreFrame[player] = 120;
	casScore[player] = casScore[player] + sc;
	
	// ゴール減少
	sc = (lines + casNowChain[player]) * 2 * bravo;
	casGoalGet[player] = sc;
	casGoalFrame[player] = 120;
	casGoal[player] = casGoal[player] - sc;
	if(casGoal[player] < 0) casGoal[player] = 0;
}

// ブロック出現
void casMoveInit(int player, int *param) {
	int i;
	
	// 最初のフレームなら
	if(statc[player * 10 + 3] == 0) {
		// 連鎖数初期化
		casNowChain[player] = 0;
		
		// レベルアップ
		if(casGoal[player] <= 0) {
			if(casLevel[player] >= 14) {
				// エンディング
				param[0] = 2;
				ending[player] = 1;
				timeOn[player] = 0;
				stat[player] = 10;
				for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
			} else {
				// レベルアップ
				casLevel[player]++;
				casGoal[player] = 5 * (casLevel[player] + 1);
				sp[player] = casLevelTable[casLevel[player]];
				if(casLevel[player] >= 11) speedtype[player] = 0;
				
				PlaySE(se_rankup);
				bgfadesw = 1;
				bgfadebg = casLevel[player];
			}
		}
	}
}

// ソフトドロップ（旧）
void casSoftDropOld(int player) {
	if((!down_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) && (engineVer <= 12)) {
		if((speedtype[player] == 1) || (sp[player] < (softspeed[player] + 1) * 30)) {
			casScore[player]++;
		}
	}
}

// ハードドロップ
void casHardDrop(int player, int bottom) {
	if((!up_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0)) {
		casScore[player] = casScore[player] + (bottom - by[player]) * 2;
	}
}

// ソフトドロップで入った点数を加算
void casSoftDropScore(int player) {
	if(softd_score[player] > 0) {
		casScore[player] = casScore[player] + softd_score[player];
	}
}

// スコア表示
void casViewScore(int player) {
	int color, color2;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// スコア
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "SCORE");
	sprintf(string[0], "%d", casScore[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// 今入った得点
	if(casScoreFrame[player] > 0) {
		casScoreFrame[player]--;
		sprintf(string[0], "%d", casScoreGet[player]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 58, string[0], (count % 4 / 2) * (1 + (casChainGet[player] >= 2)));
	}
	
	// レベル
	printTinyFont(foffset[player] + 96, fyoffset[player] + 68, "LEVEL");
	sprintf(string[0], "%d", casLevel[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 76, string[0], color);
	
	// ゴール
	printTinyFont(foffset[player] + 96, fyoffset[player] + 86, "GOAL");
	sprintf(string[0], "%d", casGoal[player]);
	color2 = color;
	if((casGoal[player] <= 0) && (onRecord[player])) color2 = 3 * (count % 4 / 2);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 94, string[0], color2);
	
	// 今入ったポイント
	if(casGoalFrame[player] > 0) {
		casGoalFrame[player]--;
		sprintf(string[0], "%d", casGoalGet[player]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 104, string[0], (count % 4 / 2) * (1 + (casChainGet[player] >= 2)));
	}
	
	// タイム
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
	
	// 連鎖
	if((casChainFrame[player] > 0) && (casChainGet[player] >= 1)) {
		casChainFrame[player]--;
		sprintf(string[0], "%d CHAIN", casChainGet[player]);
		printTinyFont(foffset[player] + 30, fyoffset[player] + 200, string[0]);
	}
}

// 結果表示
void casResult(int player) {
	// ランキング登録
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = casRegistRanking(player);
		if(statc[player * 10 + 1] != -1) casSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "SCORE");
	sprintf(string[0], "%13d", casScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "MAX CHAIN");
	sprintf(string[0], "%13d", casMaxChain[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "LEVEL");
	sprintf(string[0], "%13d", casLevel[player] + 1);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 139, "TIME");
	getTime(gameTimer[player]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 147, string[1], 0);
	
	if(statc[player * 10 + 1] != -1) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 159, "RANK");
		sprintf(string[0], "%13d", statc[player * 10 + 1] + 1);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
	}
}

// EXCELLENT画面
void casExcellent(int player, int *param) {
	printTinyFont(foffset[player] + 17, fyoffset[player] + 116, "CASCADE MODE");
	printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
	
	// 花火
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// BGM読み込み
void casLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(casBgm);
	}
}

// フィールドのブロックを表示
void casViewFieldBlock(int player, int *param) {
	int i, j, fi, ft, fo, it, temp, dx, dy, tmp_color, tmp_oblk;
	
	param[0] = 1;
	
	for(i = 0; i < hiddeny[player]; i++) {
		for(j = 0; j < 10; j++) {
			fi = getFieldBlock(player, j, i);
			
			if(fi > 0) {
				// ブロックを描画
				dx = foffset[player] + 8 + (j * 8);
				dy = fyoffset[player] + (i + 3) * 8;
				
				ft = getFieldBlockT(player, j, i);
				fo = getFieldBlockO(player, j, i);
				it = getFieldBlockI(player, j, i);
				
				// 色を決める
				if(it) {
					// アイテム
					tmp_color = it + 16;
					tmp_oblk = 0;
				} else {
					// 通常
					tmp_color = fi - 1;
					tmp_oblk = fo;
				}
				
				if((ft >= 1) && (ft <= 8)) {
					drawSBlock(player, dx, dy, tmp_color, 5 + tmp_oblk * 17, 0, 1, ft * 32);
				} else if((ft != 0) && (ft > -10)) {
					drawSBlock(player, dx, dy, tmp_color, 5 + tmp_oblk * 17, 0, 0, 0);
				}
				
				if( (disp_blkline[player]) && ((ft <= -1) || (ft >= 8)) && (!tmp_oblk) ) {
					// 枠線を描画
					temp = getFieldBlockL(player, j, i);
					
					if(!BitTest(temp, 0)) ExBltFastRect(sg_blkline, dx    , dy    ,  8,  0, 8, 1);
					if(!BitTest(temp, 1)) ExBltFastRect(sg_blkline, dx    , dy + 7,  8, 15, 8, 1);
					if(!BitTest(temp, 2)) ExBltFastRect(sg_blkline, dx    , dy    ,  8, 16, 1, 8);
					if(!BitTest(temp, 3)) ExBltFastRect(sg_blkline, dx + 7, dy    , 15, 24, 1, 8);
					
					// 影を描画
					if(blockshadow != 0) viewFieldBlockSub_DrawShadow(player, j, i, dx, dy, it, tmp_color);
				}
			}
		}
	}
}

// 設定画面
void casSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(casLoadConfig() == 0) casSaveConfig();
	
	// ランキングを読み込み
	if(casLoadRanking(player) == 0) casInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "CASCADE OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BGM",          7 * (cursor == 0));
		printFontGrid(2, 4, "GHOST BLOCK",  7 * (cursor == 1));
		printFontGrid(2, 5, "FIELD VIEW",   7 * (cursor == 2));
		printFontGrid(2, 6, "START LEVEL",  7 * (cursor == 3));
		
		// 設定値表示
		sprintf(string[0], "%d", casBgm);
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!casGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!casFieldView) sprintf(string[0], "NORMAL");
		else sprintf(string[0], "SPECIAL");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "%d", casStartLevel + 1);
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
				casBgm = casBgm + move;
				if(casBgm < 0) casBgm = 29;
				if(casBgm > 29) casBgm = 0;
			}
			if(cursor == 1) casGhost = !casGhost;
			if(cursor == 2) casFieldView = !casFieldView;
			if(cursor == 3) {
				casStartLevel = casStartLevel + move;
				if(casStartLevel < 0) casStartLevel = 14;
				if(casStartLevel > 14) casStartLevel = 0;
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
			casSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			casViewRanking(player);
		}
	}
}

// 設定を保存
void casSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x43534143;
	saveBuf[1] = 0x20454441;
	saveBuf[2] = 0x464E4F43;
	saveBuf[3] = 0x31764749;
	
	// 設定内容
	saveBuf[4] = casBgm;
	saveBuf[5] = casGhost;
	saveBuf[6] = casFieldView;
	saveBuf[7] = casStartLevel;
	
	SaveFile("config/CASCADE_CONFIG.SAV", &saveBuf, 100 * 4);
}

// 設定を読み込み
int casLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/CASCADE_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x43534143) return 0;
	if(saveBuf[1] != 0x20454441) return 0;
	if(saveBuf[2] != 0x464E4F43) return 0;
	if(saveBuf[3] != 0x31764749) return 0;
	
	// 設定内容
	casBgm = saveBuf[4];
	casGhost = saveBuf[5];
	casFieldView = saveBuf[6];
	casStartLevel = saveBuf[7];
	
	return 1;
}

// リプレイ保存
void casSaveReplay(int player) {
	saveBuf[900] = casScore[player];
	saveBuf[901] = casMaxChain[player];
	saveBuf[902] = casLevel[player];
	saveBuf[903] = casBgm;
	saveBuf[904] = casGhost;
	saveBuf[905] = casFieldView;
	saveBuf[906] = casVersion;
	saveBuf[907] = casStartLevel;
}

// リプレイ読み込み
void casLoadReplay(int player) {
	casBgm = saveBuf[903];
	casGhost = saveBuf[904];
	casFieldView = saveBuf[905];
	casVersion = saveBuf[906];
	casStartLevel = saveBuf[907];
	
	casPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void casReplayDetail() {
	printFontGrid(1, 5, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[900]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "MAX CHAIN", 0);
	sprintf(string[0], "%d", saveBuf[901]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[902] + 1);
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 9, "BGM", 0);
	sprintf(string[0], "%d", saveBuf[903]);
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "GHOST BLOCK", 0);
	if(!saveBuf[904]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "FIELD VIEW", 0);
	if(!saveBuf[905]) sprintf(string[0], "NORMAL");
	else sprintf(string[0], "SPECIAL");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[907] + 1);
	printFontGrid(22, 12, string[0], 0);
}

// ランキング保存
void casSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0] = casRankingScore[i];
		saveBuf[1 + (i * 20) + 1] = casRankingChain[i];
		saveBuf[1 + (i * 20) + 2] = casRankingLevel[i];
		saveBuf[1 + (i * 20) + 3] = casRankingTime[i];
		saveBuf[1 + (i * 20) + 4] = casRankingYear[i];
		saveBuf[1 + (i * 20) + 5] = casRankingMonth[i];
		saveBuf[1 + (i * 20) + 6] = casRankingDay[i];
		saveBuf[1 + (i * 20) + 7] = casRankingHour[i];
		saveBuf[1 + (i * 20) + 8] = casRankingMinute[i];
		saveBuf[1 + (i * 20) + 9] = casRankingSecond[i];
	}
	
	sprintf(string[0], "config/CASCADE_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 221 * 4);
}

// ランキング読み込み
int casLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/CASCADE_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 221 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 10; i++) {
		casRankingScore[i]  = saveBuf[1 + (i * 20) + 0];
		casRankingChain[i]  = saveBuf[1 + (i * 20) + 1];
		casRankingLevel[i]  = saveBuf[1 + (i * 20) + 2];
		casRankingTime[i]   = saveBuf[1 + (i * 20) + 3];
		casRankingYear[i]   = saveBuf[1 + (i * 20) + 4];
		casRankingMonth[i]  = saveBuf[1 + (i * 20) + 5];
		casRankingDay[i]    = saveBuf[1 + (i * 20) + 6];
		casRankingHour[i]   = saveBuf[1 + (i * 20) + 7];
		casRankingMinute[i] = saveBuf[1 + (i * 20) + 8];
		casRankingSecond[i] = saveBuf[1 + (i * 20) + 9];
	}
	
	return 1;
}

// ランキング初期化
void casInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		casRankingScore[i]  = 0;
		casRankingChain[i]  = 0;
		casRankingLevel[i]  = 0;
		casRankingTime[i]   = 0;
		casRankingYear[i]   = 0;
		casRankingMonth[i]  = 0;
		casRankingDay[i]    = 0;
		casRankingHour[i]   = 0;
		casRankingMinute[i] = 0;
		casRankingSecond[i] = 0;
	}
}

// ランキング登録
int casRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if(playback) return -1;
	
	for(i = 0; i < 10; i++) {
		// ランクイン
		if((casScore[player] > casRankingScore[i]) || 
		   ((casScore[player] == casRankingScore[i]) && (gameTimer[player] < casRankingTime[i])))
		{
			// ランキングをずらす
			for(j = 9; j > i; j--) {
				casRankingScore[j]  = casRankingScore[j - 1];
				casRankingChain[j]  = casRankingChain[j - 1];
				casRankingLevel[j]  = casRankingLevel[j - 1];
				casRankingTime[j]   = casRankingTime[j - 1];
				casRankingYear[j]   = casRankingYear[j - 1];
				casRankingMonth[j]  = casRankingMonth[j - 1];
				casRankingDay[j]    = casRankingDay[j - 1];
				casRankingHour[j]   = casRankingHour[j - 1];
				casRankingMinute[j] = casRankingMinute[j - 1];
				casRankingSecond[j] = casRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			casRankingScore[i]  = casScore[player];
			casRankingChain[i]  = casMaxChain[player];
			casRankingLevel[i]  = casLevel[player];
			casRankingTime[i]   = gameTimer[player];
			
			GetDateAndTime(&timebuf);
			casRankingYear[i]   = timebuf[0];
			casRankingMonth[i]  = timebuf[1];
			casRankingDay[i]    = timebuf[2];
			casRankingHour[i]   = timebuf[4];
			casRankingMinute[i] = timebuf[5];
			casRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void casViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "CASCADE MODE RANKING", 6);
		printFontGrid(1, 3, "RANK SCORE    CHAIN LEVEL TIME", 4);
		
		for(i = 0; i < 10; i++) {
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", casRankingScore[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", casRankingChain[i]);
			printFontGrid(15, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", casRankingLevel[i] + 1);
			printFontGrid(21, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(casRankingTime[i]);
			printFontGrid(27, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// 日付と時刻
			sprintf(string[0],
			        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
			        casRankingYear[cursor], casRankingMonth[cursor], casRankingDay[cursor],
			        casRankingHour[cursor], casRankingMinute[cursor], casRankingSecond[cursor]);
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
				casInitRanking();
				casSaveRanking(player);
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
