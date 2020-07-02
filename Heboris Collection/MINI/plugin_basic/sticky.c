//STICKY
//prefix:sti

// レベルアップテーブル（LV12でスピードタイプが通常モードになる）
int stiLevelTable[15] = 
{
//   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15
    60,  48,  36,  28,  22,  16,  12,   8,   6,   4,   2,  60, 180, 300,1200
};

// 変数
int stiModeNo = -1;			// モード番号

int stiMarkFld[10 * 22];	// 落下処理で使用するブロック識別用フィールド
int stiMarkCount;			// ブロックが繋がっている数

int stiLevel[2];			// 現在のレベル
int stiScore[2];			// スコア
int stiBonus[2];			// ボーナス得点

int stiRatio = 20;			// マルチカラーブロック出現率
int stiBgm = 14;			// BGM
int stiGhost = 1;			// ゴースト
int stiStartLevel = 0;		// スタート時のレベル

// ランキング変数
int stiRankingScore[10];	// スコア
int stiRankingLevel[10];	// レベル
int stiRankingRatio[10];	// マルチカラーブロック出現率
int stiRankingTime[10];		// タイム
int stiRankingYear[10];		// ランクイン日時（年）
int stiRankingMonth[10];	// ランクイン日時（月）
int stiRankingDay[10];		// ランクイン日時（日）
int stiRankingHour[10];		// ランクイン日時（時）
int stiRankingMinute[10];	// ランクイン日時（分）
int stiRankingSecond[10];	// ランクイン日時（秒）

// イベント発生
void stiPluginEvent(int player, int event, int *param) {
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != stiModeNo)) return;
	
	if(event == 0) {
		stiModeNo = addModePlugin("STICKY");	// モードを登録する
	} else if(event == 5) {
		stiReady(player, param);	// Ready表示時
	} else if(event == 10) {
		stiARE(player, param);	// ARE中の処理
	} else if(event == 11) {
		stiAfterErase(player, param);	// ライン消去
	} else if(event == 15) {
		stiViewScore(player);	// スコア表示
	} else if(event == 17) {
		stiSetting(player, param);	// 設定画面
	} else if(event == 18) {
		stiPlayerInitial(player);	// 初期化
	} else if(event == 21) {
		stiResult(player);	// 結果表示
	} else if(event == 24) {
		stiStartEnding(player);	// エンディング突入
	} else if(event == 25) {
		stiExcellent(player, param);	// EXCELLENT画面
	} else if(event == 28) {
		stiIncrementTime(player);	// 時間を進める
	} else if(event == 34) {
		stiViewFieldBlock(player, param);	// フィールドのブロックを表示
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		stiSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		stiLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		stiLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		stiReplayDetail();	// リプレイ詳細
	} else if(event == 60) {
		stiMoveLock(player, param);	// ライン消しなしでブロックを置いたとき
	} else if(event == 68) {
		stiLevelClear(player);	// レベルクリア
	}
}

// 同じ色のブロックの繋がりを調べる
void stiCheckBlockColorLink(int player, int x, int y) {
	int color;
	
	if((x >= 0) && (x < 10) && (y >= 0) && (y < 22)) {
		color = getFieldBlock(player, x, y);
		
		if((color > 1) && (color < 11) && (stiMarkFld[x + y * 10] == 0)) {
			stiMarkFld[x + y * 10] = 1;
			stiMarkCount++;
			
			if(getFieldBlock(player, x, y - 1) == color) stiCheckBlockColorLink(player, x, y - 1);
			if(getFieldBlock(player, x, y + 1) == color) stiCheckBlockColorLink(player, x, y + 1);
			if(getFieldBlock(player, x - 1, y) == color) stiCheckBlockColorLink(player, x - 1, y);
			if(getFieldBlock(player, x + 1, y) == color) stiCheckBlockColorLink(player, x + 1, y);
		}
	}
}

// 繋がっているブロックを調べる
void stiCheckBlockRealLink(int player, int x, int y) {
	int temp;
	
	if((x >= 0) && (x < 10) && (y >= 0) && (y < 22)) {
		if((getFieldBlock(player, x, y) > 1) && (getFieldBlock(player, x, y) < 11) && (stiMarkFld[x + y * 10] == 0)) {
			stiMarkFld[x + y * 10] = 1;
			
			temp = getFieldBlockL(player, x, y);
			if(BitTest(temp, 0)) stiCheckBlockRealLink(player, x, y - 1);
			if(BitTest(temp, 1)) stiCheckBlockRealLink(player, x, y + 1);
			if(BitTest(temp, 2)) stiCheckBlockRealLink(player, x - 1, y);
			if(BitTest(temp, 3)) stiCheckBlockRealLink(player, x + 1, y);
		}
	}
}

// ブロックの繋がり状況を更新
void stiUpdateBlockLink(int player, int x, int y) {
	int color, temp;
	
	if((x >= 0) && (x < 10) && (y >= 0) && (y < 22)) {
		color = getFieldBlock(player, x, y);
		
		if((color > 1) && (color < 11) && (stiMarkFld[x + y * 10] == 0)) {
			stiMarkFld[x + y * 10] = 1;
			stiMarkCount++;
			
			temp = 0;
			
			if(getFieldBlock(player, x, y - 1) == color) {
				stiUpdateBlockLink(player, x, y - 1);
				temp = BitSet(temp, 0, 1);
			}
			if(getFieldBlock(player, x, y + 1) == color) {
				stiUpdateBlockLink(player, x, y + 1);
				temp = BitSet(temp, 1, 1);
			}
			if(getFieldBlock(player, x - 1, y) == color) {
				stiUpdateBlockLink(player, x - 1, y);
				temp = BitSet(temp, 2, 1);
			}
			if(getFieldBlock(player, x + 1, y) == color) {
				stiUpdateBlockLink(player, x + 1, y);
				temp = BitSet(temp, 3, 1);
			}
			
			setFieldBlockL(player, x, y, temp);
		}
	}
}

// ブロックの繋がり状況を更新（フィールド全体）
void stiUpdateBlockLinkAll(int player) {
	int i, j;
	
	for(i = 0; i < 220; i++) stiMarkFld[i] = 0;
	
	for(i = 0; i < 22; i++) {
		for(j = 0; j < 10; j++) {
			stiUpdateBlockLink(player, j, i);
		}
	}
}

// 浮いたブロックを落とす（落ちた場合は戻り値が1になる）
int stiFallBlock(int player, int x, int y) {
	int i, j, fall, temp, color;
	
	fall = 0;
	color = getFieldBlock(player, x, y);
	
	if((color > 1) && (color < 11)) {
		fall = 1;
		
		for(i = 0; i < 220; i++) stiMarkFld[i] = 0;
		stiCheckBlockRealLink(player, x, y);
		
		// ブロックの下に空間があるかチェック（無かったら中止）
		for(i = 21; i >= 0; i--) {
			for(j = 0; j < 10; j++) {
				if(stiMarkFld[j + i * 10] == 1) {
					if( (i == 21) || ((getFieldBlock(player, j, i + 1) != 0) && (stiMarkFld[j + (i + 1) * 10] == 0)) ) {
						fall = 0;
					}
				}
			}
		}
		
		// 1マス下に落とす
		if(fall) {
			for(i = 21; i >= 0; i--) {
				for(j = 0; j < 10; j++) {
					if(stiMarkFld[j + i * 10] == 1) {
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

// 25個以上繋がっているブロックを消す
int stiErase25Block(int player, int x, int y) {
	int i, j, result, temp;
	
	result = 0;
	
	if((getFieldBlock(player, x, y) > 1) && (getFieldBlock(player, x, y) < 11)) {
		for(i = 0; i < 220; i++) stiMarkFld[i] = 0;
		stiMarkCount = 0;
		stiCheckBlockColorLink(player, x, y);
		
		if(stiMarkCount >= 25) {
			result = 1;
			
			for(i = 0; i < 22; i++) {
				for(j = 0; j < 10; j++) {
					if(stiMarkFld[j + i * 10] == 1) {
						temp = getFieldBlock(player, j, i);
						objectCreate(player, 1, foffset[player] + 8 + (j * 8), fyoffset[player] + (i + 3) * 8, (j - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + 1 * 250, temp - 1, 100);
						PlaySE(se_erase[0]);
						
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
	
	return result;
}

// ライン消去
void stiAfterErase(int player, int *param) {
	int i, j, temp, fall;
	
	if(statc[player * 10] >= wait2[player]) {
		param[0] = 1;	// 通常のライン消去後の処理をスキップする
		
		if(statc[player * 10] == wait2[player]) {
			// 通常通りにブロックを落とす
			temp = downFloatingBlocks(player);
			if(temp) statc[player * 10 + 1] = 1;
			for(i = 0; i < 22; i++) erase[i + player * 22] = 0;
			
			// ブロックの繋がり状況を更新
			stiUpdateBlockLinkAll(player);
		}
		
		// 落下
		fall = 0;
		
		for(i = 21; i >= 0; i--) {
			for(j = 0; j < 10; j++) {
				if(stiFallBlock(player, j, i)) fall = 1;
				
				if(fall) statc[player * 10 + 1] = 1;
			}
		}
		
		// 落ちなくなったら
		if(!fall) {
			if(statc[player * 10 + 1]) PlaySE(se_gon);
			pinchCheck(player);
			
			// 25個以上繋がっているブロックを消す
			temp = 0;
			
			for(i = 21; i >= 0; i--) {
				for(j = 0; j < 10; j++) {
					if(stiErase25Block(player, j, i)) temp = 1;
				}
			}
			
			// 25個以上繋がっているブロックが無い場合
			if(!temp) {
				stiUpdateBlockLinkAll(player);
				
				if(blockEraseJudge(player)) {
					// 連鎖
					statc[player * 10] = 0;
				} else {
					// 終了
					stat[player] = 5;
					resetStatc(player);
					statc[player * 10] = wait1[player];
				}
			} else {
				statc[player * 10] = 0;
			}
			return;
		}
	}
	
	if(param[0]) statc[player * 10]++;
}

// フィールドのブロックを表示
void stiViewFieldBlock(int player, int *param) {
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

// 初期化
void stiPlayerInitial(int player) {
	// 変数を初期化
	stiLevel[player] = stiStartLevel;
	stiScore[player] = 0;
	stiBonus[player] = 0;
	
	// 枠の色を変える
	framecolor[player] = 5;
	frame_decoration[player] = 1;
	
	// マルチカラーブロック有効
	if(stiRatio) {
		multicolor_enable[player] = 1;
		multicolor_ratio[player] = stiRatio;
	} else {
		multicolor_enable[player] = 0;
	}
	
	// BGM
	bgmlv = stiBgm;
	
	// ゴースト
	if(stiGhost == 0) ghost[player] = 0;
	
	// 初期速度
	sp[player] = stiLevelTable[stiLevel[player]];
	if(stiLevel[player] >= 11) speedtype[player] = 0;
	else speedtype[player] = 1;
	wait2[player] = 20;
	
	backno = stiLevel[player];
}

// ライン消しなしでブロックを置いたとき
void stiMoveLock(int player, int *param) {
	param[0] = 1;
	stat[player] = 6;
	resetStatc(player);
	statc[player * 10] = wait2[player];
}

// フィールドをリセット＆邪魔ブロックを作る
void stiMakeGarbage(int player) {
	int i, j, k, x, block;
	
	// フィールドリセット
	resetField(player);
	
	// 邪魔ブロック作成
	k = 21 - (stiLevel[player] + 1);
	
	for(i = 21; i >= k; i--) {
		for(j = 0; j < 5; j++) {
			retry:
			
			x = GiziRand(player, 10);
			
			if(getFieldBlock(player, x, i) == 0) {
				if(i == 21) block = Rand(7) + 11;
				else block = 1;
				setFieldBlock(player, x, i, block);
				setFieldBlockT(player, x, i, -1);
			} else {
				goto retry;
			}
		}
	}
	
	// ボーナス得点リセット
	stiBonus[player] = (3600 * 2) * ((110 - stiRatio) / 10);
}

// レベルクリア
void stiLevelClear(int player) {
	int i, j;
	
	// ブロックを消す
	i = 21 - statc[player * 10];
	
	if(i == 0) PlaySE(se_applause);
	
	for(j = 0; j < 10; j++) {
		if(getFieldBlock(player, j, i) > 0) {
			objectCreate(player, 1, foffset[player] + 8 + (j * 8), fyoffset[player] + (i + 3) * 8, (j - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + 1 * 250, getFieldBlock(player, j, i) - 1, 100);
			
			setFieldBlock(player, j, i, 0);
			setFieldBlockT(player, j, i, 0);
			setFieldBlockO(player, j, i, 0);
			setFieldBlockL(player, j, i, 0);
			setFieldBlockI(player, j, i, 0);
		}
	}
	
	if(statc[player * 10] >= 21) {
		// 次のレベルへ
		PlaySE(se_rankup);
		
		stiLevel[player]++;
		stiMakeGarbage(player);
		
		sp[player] = stiLevelTable[stiLevel[player]];
		if(stiLevel[player] >= 11) speedtype[player] = 0;
		
		bgfadesw = 1;
		bgfadebg = stiLevel[player];
		
		timeOn[player] = 1;
		
		stat[player] = 4;
		resetStatc(player);
	} else {
		statc[player * 10]++;
	}
}

// ARE中の処理
void stiARE(int player, int *param) {
	// レベルクリア判定
	if(checkHowManyPBlocks(player) == 0) {
		timeOn[player] = 0;
		stiScore[player] = stiScore[player] + stiBonus[player];
		
		if(stiLevel[player] >= 14) {
			ending[player] = 1;
		} else {
			param[0] = 1;
			stat[player] = 2;
			resetStatc(player);
		}
	}
}

// Ready表示時
void stiReady(int player, int *param) {
	if(!statc[player * 10]) stiMakeGarbage(player);
}

// 時間を進める
void stiIncrementTime(int player) {
	// ボーナス減少
	if(timeOn[player]) {
		if(stiBonus[player] > 0) stiBonus[player] = stiBonus[player] - (1 * ((110 - stiRatio) / 10));
	}
}

// エンディング突入
void stiStartEnding(int player) {
	onRecord[player] = 0;
	ending[player] = 3;
	resetStatc(player);
}

// EXCELLENT画面
void stiExcellent(int player, int *param) {
	printTinyFont(foffset[player] + 19, fyoffset[player] + 116, "STICKY MODE");
	printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
	
	// 花火
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// スコア表示
void stiViewScore(int player) {
	int color;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// スコア
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "SCORE");
	sprintf(string[0], "%d", stiScore[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// ボーナス
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "BONUS");
	sprintf(string[0], "%d", stiBonus[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// レベル
	printTinyFont(foffset[player] + 96, fyoffset[player] + 76, "LEVEL");
	sprintf(string[0], "%d", stiLevel[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 84, string[0], color);
	
	// タイム
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
}

// 結果表示
void stiResult(int player) {
	// ランキング登録
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = stiRegistRanking(player);
		if(statc[player * 10 + 1] != -1) stiSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "SCORE");
	sprintf(string[0], "%13d", stiScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", stiLevel[player] + 1);
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
void stiLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(stiBgm);
	}
}

// リプレイ保存
void stiSaveReplay(int player) {
	saveBuf[900] = stiLevel[player];
	saveBuf[901] = stiScore[player];
	saveBuf[902] = stiRatio;
	saveBuf[903] = stiBgm;
	saveBuf[904] = stiGhost;
	saveBuf[905] = stiStartLevel;
}

// リプレイ読み込み
void stiLoadReplay(int player) {
	stiRatio = saveBuf[902];
	stiBgm = saveBuf[903];
	stiGhost = saveBuf[904];
	stiStartLevel = saveBuf[905];
	
	// 設定を反映させる
	stiPlayerInitial(player);
}

// リプレイ詳細
void stiReplayDetail() {
	printFontGrid(1, 4, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[901]);
	printFontGrid(22, 4, string[0], 0);
	
	printFontGrid(1, 5, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[900]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 7, "MULTI-COLOR RATIO", 0);
	sprintf(string[0], "%d%%", saveBuf[902]);
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 8, "BGM", 0);
	sprintf(string[0], "%d", saveBuf[903]);
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "GHOST BLOCK", 0);
	sprintf(string[0], "%d", saveBuf[904]);
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[905] + 1);
	printFontGrid(22, 10, string[0], 0);
}

// 設定画面
void stiSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	stiLoadConfig();
	
	// ランキングを読み込み
	if(!stiLoadRanking(player)) stiInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "STICKY OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2,  3, "MULTI-COLOR RATIO", 7 * (cursor == 0));
		printFontGrid(2,  4, "BGM",               7 * (cursor == 1));
		printFontGrid(2,  5, "GHOST BLOCK",       7 * (cursor == 2));
		printFontGrid(2,  6, "START LEVEL",       7 * (cursor == 3));
		
		// 設定値表示
		sprintf(string[0], "%d%%", stiRatio);
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		sprintf(string[0], "%d", stiBgm);
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!stiGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "%d", stiStartLevel + 1);
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
				stiRatio = stiRatio + move;
				if(stiRatio < 0) stiRatio = 100;
				if(stiRatio > 100) stiRatio = 0;
			}
			if(cursor == 1) {
				stiBgm = stiBgm + move;
				if(stiBgm < 0) stiBgm = 29;
				if(stiBgm > 29) stiBgm = 0;
			}
			if(cursor == 2) stiGhost = !stiGhost;
			if(cursor == 3) {
				stiStartLevel = stiStartLevel + move;
				if(stiStartLevel < 0) stiStartLevel = 14;
				if(stiStartLevel > 14) stiStartLevel = 0;
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
			stiSaveConfig();
			PlayWave(se_kettei);
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			stiViewRanking(player);
		}
	}
}

// 設定を保存
void stiSaveConfig() {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// 設定内容
	saveBuf[1] = stiRatio;
	saveBuf[2] = stiBgm;
	saveBuf[3] = stiGhost;
	saveBuf[4] = stiStartLevel;
	
	SaveFile("config/STICKY_CONFIG.SAV", &saveBuf, 50 * 4);
}

// 設定を読み込み
int stiLoadConfig() {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/STICKY_CONFIG.SAV", &saveBuf, 50 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// 設定内容
	stiRatio = saveBuf[1];
	stiBgm = saveBuf[2];
	stiGhost = saveBuf[3];
	stiStartLevel = saveBuf[4];
	
	return 1;
}

// ランキング保存
void stiSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 10) + 0] = stiRankingScore[i];
		saveBuf[1 + (i * 10) + 1] = stiRankingLevel[i];
		saveBuf[1 + (i * 10) + 2] = stiRankingRatio[i];
		saveBuf[1 + (i * 10) + 3] = stiRankingTime[i];
		saveBuf[1 + (i * 10) + 4] = stiRankingYear[i];
		saveBuf[1 + (i * 10) + 5] = stiRankingMonth[i];
		saveBuf[1 + (i * 10) + 6] = stiRankingDay[i];
		saveBuf[1 + (i * 10) + 7] = stiRankingHour[i];
		saveBuf[1 + (i * 10) + 8] = stiRankingMinute[i];
		saveBuf[1 + (i * 10) + 9] = stiRankingSecond[i];
	}
	
	sprintf(string[0], "config/STICKY_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 111 * 4);
}

// ランキング読み込み
int stiLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/STICKY_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 111 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 10; i++) {
		stiRankingScore[i]  = saveBuf[1 + (i * 10) + 0];
		stiRankingLevel[i]  = saveBuf[1 + (i * 10) + 1];
		stiRankingRatio[i]  = saveBuf[1 + (i * 10) + 2];
		stiRankingTime[i]   = saveBuf[1 + (i * 10) + 3];
		stiRankingYear[i]   = saveBuf[1 + (i * 10) + 4];
		stiRankingMonth[i]  = saveBuf[1 + (i * 10) + 5];
		stiRankingDay[i]    = saveBuf[1 + (i * 10) + 6];
		stiRankingHour[i]   = saveBuf[1 + (i * 10) + 7];
		stiRankingMinute[i] = saveBuf[1 + (i * 10) + 8];
		stiRankingSecond[i] = saveBuf[1 + (i * 10) + 9];
	}
	
	return 1;
}

// ランキング初期化
void stiInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		stiRankingScore[i]  = 0;
		stiRankingLevel[i]  = 0;
		stiRankingRatio[i]  = 0;
		stiRankingTime[i]   = 0;
		stiRankingYear[i]   = 0;
		stiRankingMonth[i]  = 0;
		stiRankingDay[i]    = 0;
		stiRankingHour[i]   = 0;
		stiRankingMinute[i] = 0;
		stiRankingSecond[i] = 0;
	}
}

// ランキング登録
int stiRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if(playback) return -1;
	
	for(i = 0; i < 10; i++) {
		// ランクイン
		if((stiScore[player] > stiRankingScore[i]) || 
		   ((stiScore[player] == stiRankingScore[i]) && (gameTimer[player] < stiRankingTime[i])))
		{
			// ランキングをずらす
			for(j = 9; j > i; j--) {
				stiRankingScore[j]  = stiRankingScore[j - 1];
				stiRankingLevel[j]  = stiRankingLevel[j - 1];
				stiRankingRatio[j]  = stiRankingRatio[j - 1];
				stiRankingTime[j]   = stiRankingTime[j - 1];
				stiRankingYear[j]   = stiRankingYear[j - 1];
				stiRankingMonth[j]  = stiRankingMonth[j - 1];
				stiRankingDay[j]    = stiRankingDay[j - 1];
				stiRankingHour[j]   = stiRankingHour[j - 1];
				stiRankingMinute[j] = stiRankingMinute[j - 1];
				stiRankingSecond[j] = stiRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			stiRankingScore[i]   = stiScore[player];
			stiRankingLevel[i]   = stiLevel[player];
			stiRankingRatio[i]   = stiRatio;
			stiRankingTime[i]    = gameTimer[player];
			
			GetDateAndTime(&timebuf);
			stiRankingYear[i]    = timebuf[0];
			stiRankingMonth[i]   = timebuf[1];
			stiRankingDay[i]     = timebuf[2];
			stiRankingHour[i]    = timebuf[4];
			stiRankingMinute[i]  = timebuf[5];
			stiRankingSecond[i]  = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void stiViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "STICKY MODE RANKING", 6);
		printFontGrid(1, 3, "RANK SCORE    LEVEL RATIO TIME", 4);
		
		for(i = 0; i < 10; i++) {
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", stiRankingScore[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", stiRankingLevel[i] + 1);
			printFontGrid(15, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d%%", stiRankingRatio[i]);
			printFontGrid(21, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(stiRankingTime[i]);
			printFontGrid(27, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// 日付と時刻
			sprintf(string[0],
			        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
			        stiRankingYear[cursor], stiRankingMonth[cursor], stiRankingDay[cursor],
			        stiRankingHour[cursor], stiRankingMinute[cursor], stiRankingSecond[cursor]);
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
				stiInitRanking();
				stiSaveRanking(player);
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
