//SQUARE
//prefix:squ

// レベルアップテーブル（LV12でスピードタイプが通常モードになる）
int squLevelTable[15] = 
{
//   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15
    60,  48,  36,  28,  22,  16,  12,   8,   6,   4,   2,  60, 180, 300,1200
};

// 変数
int squModeNo = -1;			// モード番号

int squScore[2];			// スコア
int squSquares[2];			// 作った正方形の数
int squLevel[2];			// 現在のレベル
int squGoal[2];				// レベルアップまでのポイント数

int squTSpinFrame[2];		// T-SPIN表示の残り時間
int squTSpinLine[2];		// 最後のT-SPINライン消しの種類
int squScoreGet[2];			// 今入ったスコア表示の点数
int squScoreFrame[2];		// 今入ったスコア表示の残り時間
int squGoalGet[2];			// 今入ったポイント表示の点数
int squGoalFrame[2];		// 今入ったポイント表示の残り時間

int squMarkFld[10 * 22];	// T-SPINでの落下処理で使用するブロック識別用フィールド
int squTFallFlag[2];		// T-SPINでの落下フラグ
int squMarkCount;			// 繋がっているブロックの数

int squSilverCount[2];		// ラインの中に含まれる銀の正方形の数（正方形ボーナスカウンタ）
int squGoldCount[2];		// ラインの中に含まれる金の正方形の数（正方形ボーナスカウンタ）

int squBgm = 20;			// 使用するBGM
int squGhost = 1;			// ゴーストの設定
int squFieldView = 0;		// フィールドの表示タイプ
int squTSpin = 3;			// T-SPINの種類
int squStartLevel = 0;		// スタート時のレベル

// ランキング用変数
int squRankingScore[10];	// スコア
int squRankingSquares[10];	// 作った正方形の数
int squRankingLevel[10];	// レベル
int squRankingTime[10];		// タイム
int squRankingYear[10];		// ランクイン日時（年）
int squRankingMonth[10];	// ランクイン日時（月）
int squRankingDay[10];		// ランクイン日時（日）
int squRankingHour[10];		// ランクイン日時（時）
int squRankingMinute[10];	// ランクイン日時（分）
int squRankingSecond[10];	// ランクイン日時（秒）

// イベント発生
void squPluginEvent(int player, int event, int *param) {
	int i;
	
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != squModeNo)) return;
	
	if(event == 0) {
		squModeNo = addModePlugin("SQUARE");	// モードを登録する
	} else if(event == 8) {
		squSoftDropScore(player);	// ソフトドロップで入った点数を加算
	} else if(event == 11) {
		squAfterErase(player, param);	// ライン消去
	} else if(event == 12) {
		squCalcScore(player, param[0]);	// スコア計算
	} else if(event == 15) {
		squViewScore(player);	// スコア表示
	} else if(event == 17) {
		squSetting(player, param);	// 設定画面
	} else if(event == 18) {
		squPlayerInitial(player);	// 初期化
	} else if(event == 21) {
		squResult(player);	// 結果表示
	} else if(event == 24) {
		onRecord[player] = 0;	// エンディング突入
		ending[player] = 3;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		squExcellent(player, param);	// EXCELLENT画面
	} else if(event == 34) {
		if(squFieldView) squViewFieldBlock(player, param);	// フィールドのブロックを表示
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		squSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		squLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		squLoadBGM();	// BGM読み込み
	} else if(event == 48) {
		squSoftDropOld(player);	// ソフトドロップ（旧）
	} else if(event == 49) {
		squHardDrop(player, param[1]);	// ハードドロップ
	} else if(event == 53) {
		squOnBlockErase(player, param[0], param[1]);	// ブロックが消えるとき
	} else if(event == 55) {
		squReplayDetail();	// リプレイ詳細
	} else if(event == 59) {
		squTSpinZero(player);	// ライン消しなしのT-SPIN
	} else if(event == 60) {
		squMakeSquare(player);	// ブロックを置いた瞬間に正方形判定をする
	}
}

// 正方形ができるか判定
int squCheckSquare(int player, int x, int y, int gold) {
	int i, j, color, temp;
	
	// 始点の色を取得
	color = getFieldBlock(player, x, y);
	
	// 4x4のエリアをチェック
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 4; j++) {
			// ブロックを取得
			temp = getFieldBlock(player, x + i, y + j);
			
			// 破片があったら終了
			if(temp <= 1) return 0;
			
			// 全部同じ色でなかったら終了（gold == 1の場合）
			if((gold) && (temp != color)) return 0;
			
			// アイテムフラグを取得
			temp = getFieldBlockI(player, x + i, y + j);
			
			// すでに正方形になってたら終了
			if((temp == fldisno) || (temp == fldigsno)) return 0;
		}
	}
	
	// 外側に繋がっていたら終了
	// 上下
	for(i = 0; i < 4; i++) {
		if(BitTest(getFieldBlockL(player, x + i, y    ), 0)) return 0;
		if(BitTest(getFieldBlockL(player, x + i, y + 3), 1)) return 0;
	}
	
	// 左右
	for(j = 0; j < 4; j++) {
		if(BitTest(getFieldBlockL(player, x    , y + j), 2)) return 0;
		if(BitTest(getFieldBlockL(player, x + 3, y + j), 3)) return 0;
	}
	
	// 成功
	return 1;
}

// 正方形を作る
int squMakeSquare(int player) {
	int i, j, k, l, result;
	result = 0;
	
	for(i = 0; i < 22 - 3; i++) {
		for(j = 0; j < 10 - 3; j++) {
			if(squCheckSquare(player, j, i, 1)) {
				// 金色
				if(result < 2) result = 2;
				PlaySE(se_cheer);
				squSquares[player] = squSquares[player] + 2;
				
				// マークを付ける
				for(k = 0; k < 4; k++) {
					for(l = 0; l < 4; l++) {
						setFieldBlockI(player, l + j, i + k, fldigsno);
					}
				}
				
				// 繋がりを変える
				setFieldBlockL(player, j    , i    , 10);
				setFieldBlockL(player, j + 1, i    , 14);
				setFieldBlockL(player, j + 2, i    , 14);
				setFieldBlockL(player, j + 3, i    ,  6);
				setFieldBlockL(player, j    , i + 1, 11);
				setFieldBlockL(player, j + 1, i + 1, 15);
				setFieldBlockL(player, j + 2, i + 1, 15);
				setFieldBlockL(player, j + 3, i + 1,  7);
				setFieldBlockL(player, j    , i + 2, 11);
				setFieldBlockL(player, j + 1, i + 2, 15);
				setFieldBlockL(player, j + 2, i + 2, 15);
				setFieldBlockL(player, j + 3, i + 2,  7);
				setFieldBlockL(player, j    , i + 3,  9);
				setFieldBlockL(player, j + 1, i + 3, 13);
				setFieldBlockL(player, j + 2, i + 3, 13);
				setFieldBlockL(player, j + 3, i + 3,  5);
			} else if(squCheckSquare(player, j, i, 0)) {
				// 銀色
				if(result < 1) result = 1;
				PlaySE(se_applause);
				squSquares[player]++;
				
				// マークを付ける
				for(k = 0; k < 4; k++) {
					for(l = 0; l < 4; l++) {
						setFieldBlockI(player, l + j, i + k, fldisno);
					}
				}
				
				// 繋がりを変える
				setFieldBlockL(player, j    , i    , 10);
				setFieldBlockL(player, j + 1, i    , 14);
				setFieldBlockL(player, j + 2, i    , 14);
				setFieldBlockL(player, j + 3, i    ,  6);
				setFieldBlockL(player, j    , i + 1, 11);
				setFieldBlockL(player, j + 1, i + 1, 15);
				setFieldBlockL(player, j + 2, i + 1, 15);
				setFieldBlockL(player, j + 3, i + 1,  7);
				setFieldBlockL(player, j    , i + 2, 11);
				setFieldBlockL(player, j + 1, i + 2, 15);
				setFieldBlockL(player, j + 2, i + 2, 15);
				setFieldBlockL(player, j + 3, i + 2,  7);
				setFieldBlockL(player, j    , i + 3,  9);
				setFieldBlockL(player, j + 1, i + 3, 13);
				setFieldBlockL(player, j + 2, i + 3, 13);
				setFieldBlockL(player, j + 3, i + 3,  5);
			}
		} /* for(j = 0; j < 6; j++) */
	} /* for(i = 0; i < 18; i++) */
	
	return result;
}

// ライン消去
void squAfterErase(int player, int *param) {
	int i, j, temp, fall;
	
	if(statc[player * 10] == wait2[player]) {
		param[0] = 1;	// 通常のライン消去後の処理をスキップする
		
		for(i = 21; i >= 0; i--) {
			if(erase[i + player * 22]) {
				// 消したラインの1マス上下のブロックの繋がりを外し、破片（繋がっている数が3つ以下）を灰色にする
				for(j = 0; j < 10; j++) {
					// 上
					temp = getFieldBlockL(player, j, i - 1);
					temp = BitSet(temp, 1, 0);
					setFieldBlockL(player, j, i - 1, temp);
					
					if(squHowManyBlockLink(player, j, i - 1) <= 3) {
						squGrayoutBlockLink(player, j, i - 1);
					}
					
					// 下
					temp = getFieldBlockL(player, j, i + 1);
					temp = BitSet(temp, 0, 0);
					setFieldBlockL(player, j, i + 1, temp);
					
					if(squHowManyBlockLink(player, j, i + 1) <= 3) {
						squGrayoutBlockLink(player, j, i + 1);
					}
				}
			}
		}
	}
	
	if((statc[player * 10] >= wait2[player]) && (squTFallFlag[player])) {
		param[0] = 1;	// 通常のライン消去後の処理をスキップする
		
		// T-SPINで落下
		fall = 0;
		
		for(i = 21; i >= 0; i--) {
			for(j = 0; j < 10; j++) {
				if(squFallBlock(player, j, i)) fall = 1;
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
				squTFallFlag[player] = 0;
				stat[player] = 5;
				statc[player * 10] = wait1[player];
			}
			return;
		}
	}
	
	if(param[0]) statc[player * 10]++;
}

// T-SPIN時の部分／全体フリーフォール開始処理
void squTSpinFall(int player, int lines) {
	int i, j, start;
	
	if(lines == 1) {
		// 始点を調べる
		for(i = 0; i < 22; i++) {
			if(erase[i + player * 22]) {
				start = i;
				break;
			}
		}
	} else {
		start = 0;
	}
	
	// 始点から下のブロックの結合を解除
	for(i = start; i < 22; i++) {
		for(j = 0; j < 10; j++) {
			if(getFieldBlock(player, j, i) >= 1) {
				setFieldBlock(player, j, i, 1);
				setFieldBlockL(player, j, i, 0);
				setFieldBlockI(player, j, i, 0);
			}
		}
	}
	
	// 落下フラグON
	squTFallFlag[player] = 1;
}

// T-SPINで浮いたブロックを落とす（落ちた場合は戻り値が1になる）
int squFallBlock(int player, int x, int y) {
	int i, j, fall, temp;
	
	fall = 0;
	
	if((!squMarkFld[x + y * 10]) && (getFieldBlock(player, x, y) > 0)) {
		fall = 1;
		
		for(i = 0; i < 220; i++) squMarkFld[i] = 0;
		squMarkCount = 0;
		squCheckBlockLink(player, x, y);
		
		// ブロックの下に空間があるかチェック（無かったら中止）
		for(i = 21; i >= 0; i--) {
			for(j = 0; j < 10; j++) {
				if(squMarkFld[j + i * 10] == 1) {
					if( (i == 21) || ((getFieldBlock(player, j, i + 1) != 0) && (squMarkFld[j + (i + 1) * 10] != 1)) ) {
						fall = 0;
					}
				}
			}
		}
		
		// 1マス下に落とす
		if(fall) {
			for(i = 21; i >= 0; i--) {
				for(j = 0; j < 10; j++) {
					if(squMarkFld[j + i * 10] == 1) {
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
void squCheckBlockLink(int player, int x, int y) {
	int temp;
	
	if((x >= 0) && (x < 10) && (y >= 0) && (y < 22)) {
		if((getFieldBlock(player, x, y) > 0) && (squMarkFld[x + y * 10] == 0)) {
			squMarkFld[x + y * 10] = 1;
			squMarkCount++;
			
			temp = getFieldBlockL(player, x, y);
			if(BitTest(temp, 0)) squCheckBlockLink(player, x, y - 1);
			if(BitTest(temp, 1)) squCheckBlockLink(player, x, y + 1);
			if(BitTest(temp, 2)) squCheckBlockLink(player, x - 1, y);
			if(BitTest(temp, 3)) squCheckBlockLink(player, x + 1, y);
		}
	}
}

// 繋がっているブロックを灰色にする
void squGrayoutBlockLink(int player, int x, int y) {
	int temp;
	
	if((x >= 0) && (x < 10) && (y >= 0) && (y < 22)) {
		if(getFieldBlock(player, x, y) >= 2) {
			setFieldBlock(player, x, y, 1);
			
			temp = getFieldBlockL(player, x, y);
			if(BitTest(temp, 0)) squGrayoutBlockLink(player, x, y - 1);
			if(BitTest(temp, 1)) squGrayoutBlockLink(player, x, y + 1);
			if(BitTest(temp, 2)) squGrayoutBlockLink(player, x - 1, y);
			if(BitTest(temp, 3)) squGrayoutBlockLink(player, x + 1, y);
		}
	}
}

// 繋がっているブロックの数を数える
int squHowManyBlockLink(int player, int x, int y) {
	int i;
	for(i = 0; i < 220; i++) squMarkFld[i] = 0;
	squMarkCount = 0;
	squCheckBlockLink(player, x, y);
	return squMarkCount;
}

// 初期化
void squPlayerInitial(int player) {
	// 変数を初期化
	squScore[player] = 0;
	squSquares[player] = 0;
	squLevel[player] = squStartLevel;
	squGoal[player] = 5 * (squLevel[player] + 1);
	
	squTSpinFrame[player] = 0;
	squTSpinLine[player] = 0;
	squScoreGet[player] = 0;
	squScoreFrame[player] = 0;
	squGoalGet[player] = 0;
	squGoalFrame[player] = 0;
	
	squTFallFlag[player] = 0;
	
	squSilverCount[player] = 0;
	squGoldCount[player] = 0;
	
	// 初期速度
	sp[player] = squLevelTable[squLevel[player]];
	if(squLevel[player] >= 11) speedtype[player] = 0;
	else speedtype[player] = 1;
	
	// 枠の色を変える
	framecolor[player] = 5;
	frame_decoration[player] = 1;
	
	// 設定を反映させる
	bgmlv = squBgm;
	if(squGhost == 0) ghost[player] = 0;
	tspin_type[player] = squTSpin;
	backno = squLevel[player];
}

// ブロックが消えるとき
void squOnBlockErase(int player, int x, int y) {
	int temp;
	temp = getFieldBlockI(player, x, y);
	
	// 消える正方形の数をカウント
	if(temp == fldisno) squSilverCount[player]++;
	if(temp == fldigsno) squGoldCount[player]++;
}

// スコア計算
void squCalcScore(int player, int lines) {
	int bo, points;
	
	// T-SPIN落下時はカウントしない
	if(squTFallFlag[player]) return;
	
	// T-SPIN
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		squTSpinFall(player, lines);
		
		squTSpinFrame[player] = 60;
		squTSpinLine[player] = lines;
		
		if(lines == 1) bo = 3;	// T-SPIN Single
		if(lines == 2) bo = 7;	// T-SPIN Double
		if(lines == 3) bo = 6;	// T-SPIN Triple
	}
	// 普通のライン消し
	else {
		if(lines == 1) bo = 1;
		if(lines == 2) bo = 3;
		if(lines == 3) bo = 5;
		if(lines == 4) {
			bo = 8;
			squTSpinFrame[player] = 60;
			squTSpinLine[player] = lines;
		}
	}
	
	// 正方形ボーナス
	bo = bo + ((squSilverCount[player] / 4) * 5);
	bo = bo + ((squGoldCount[player] / 4) * 10);
	
	// 全消しボーナス
	if(isBravo(player)) {
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		bo = bo + 50;
	}
	
	// スコア加算
	points = (bo * 100) * (squLevel[player] + 1);
	squScore[player] = squScore[player] + points;
	squScoreGet[player] = points;
	squScoreFrame[player] = 120;
	
	// ゴール減少
	squGoal[player] = squGoal[player] - bo;
	squGoalGet[player] = bo;
	squGoalFrame[player] = 120;
	
	// 正方形ボーナスカウンタをリセット
	squSilverCount[player] = 0;
	squGoldCount[player] = 0;
	
	// レベルアップ
	squLevelUp(player);
}

// ライン消しなしのT-SPIN
void squTSpinZero(int player) {
	PlaySE(se_tspin);
	squTSpinFrame[player] = 60;
	squTSpinLine[player] = 0;
	
	squScore[player] = squScore[player] + (100 * (squLevel[player] + 1));
	squScoreGet[player] = 100 * (squLevel[player] + 1);
	squScoreFrame[player] = 120;
	
	squGoal[player] = squGoal[player] - 1;
	squGoalGet[player] = 1;
	squGoalFrame[player] = 120;
	
	// レベルアップ
	squLevelUp(player);
}

// レベルアップ
void squLevelUp(int player) {
	if(squGoal[player] <= 0) {
		if(squLevel[player] >= 14) {
			// エンディング
			squGoal[player] = 0;
			ending[player] = 1;
			timeOn[player] = 0;
		} else {
			// レベルアップ
			squLevel[player]++;
			squGoal[player] = 5 * (squLevel[player] + 1);
			sp[player] = squLevelTable[squLevel[player]];
			if(squLevel[player] >= 11) speedtype[player] = 0;
			
			PlaySE(se_rankup);
			bgfadesw = 1;
			bgfadebg = squLevel[player];
		}
	}
}

// ソフトドロップ（旧）
void squSoftDropOld(int player) {
	if((!down_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) && (engineVer <= 12)) {
		if((speedtype[player] == 1) || (sp[player] < (softspeed[player] + 1) * 30)) {
			squScore[player]++;
		}
	}
}

// ハードドロップ
void squHardDrop(int player, int bottom) {
	if((!up_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0)) {
		squScore[player] = squScore[player] + (bottom - by[player]) * 2;
	}
}

// ソフトドロップで入った点数を加算
void squSoftDropScore(int player) {
	if(softd_score[player] > 0) {
		squScore[player] = squScore[player] + softd_score[player];
	}
}

// スコア表示
void squViewScore(int player) {
	int color;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// スコア
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "SCORE");
	sprintf(string[0], "%d", squScore[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// 今入った得点
	if(squScoreFrame[player] > 0) {
		squScoreFrame[player]--;
		sprintf(string[0], "%d", squScoreGet[player]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 58, string[0], (count % 4 / 2) * (1 + (b_to_b_count[player] != 0)));
	}
	
	// レベル
	printTinyFont(foffset[player] + 96, fyoffset[player] + 68, "LEVEL");
	sprintf(string[0], "%d", squLevel[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 76, string[0], color);
	
	// ゴール
	printTinyFont(foffset[player] + 96, fyoffset[player] + 86, "GOAL");
	sprintf(string[0], "%d", squGoal[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 94, string[0], color);
	
	// 今入ったポイント
	if(squGoalFrame[player] > 0) {
		squGoalFrame[player]--;
		sprintf(string[0], "%d", squGoalGet[player]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 104, string[0], (count % 4 / 2) * (1 + (b_to_b_count[player] != 0)));
	}
	
	// タイム
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
	
	// T-SPIN
	if(squTSpinFrame[player] > 0) {
		squTSpinFrame[player]--;
		
		if(squTSpinLine[player] == 0)
			printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "T-SPIN");
		else if(squTSpinLine[player] == 1)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN SINGLE");
		else if(squTSpinLine[player] == 2)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN DOUBLE");
		else if(squTSpinLine[player] == 3)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN TRIPLE");
		else if(squTSpinLine[player] == 4)
			printTinyFont(foffset[player] + 30, fyoffset[player] + 208, "HEBORIS");
	}
}

// 結果表示
void squResult(int player) {
	// ランキング登録
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = squRegistRanking(player);
		if(statc[player * 10 + 1] != -1) squSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "SCORE");
	sprintf(string[0], "%13d", squScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "SQUARES");
	sprintf(string[0], "%13d", squSquares[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "LEVEL");
	sprintf(string[0], "%13d", squLevel[player] + 1);
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
void squExcellent(int player, int *param) {
	printTinyFont(foffset[player] + 20, fyoffset[player] + 116, "SQUARE MODE");
	printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
	
	// 花火
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// BGM読み込み
void squLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(squBgm);
	}
}

// フィールドのブロックを表示
void squViewFieldBlock(int player, int *param) {
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
void squSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(squLoadConfig() == 0) squSaveConfig();
	
	// ランキングを読み込み
	if(squLoadRanking(player) == 0) squInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "SQUARE OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BGM",          7 * (cursor == 0));
		printFontGrid(2, 4, "GHOST BLOCK",  7 * (cursor == 1));
		printFontGrid(2, 5, "FIELD VIEW",   7 * (cursor == 2));
		printFontGrid(2, 6, "T-SPIN",       7 * (cursor == 3));
		printFontGrid(2, 7, "START LEVEL",  7 * (cursor == 4));
		
		// 設定値表示
		sprintf(string[0], "%d", squBgm);
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!squGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!squFieldView) sprintf(string[0], "NORMAL");
		else sprintf(string[0], "SPECIAL");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(squTSpin == 0) sprintf(string[0], "OFF");
		else if(squTSpin == 1) sprintf(string[0], "LINE CLEAR");
		else if(squTSpin == 2) sprintf(string[0], "IMMOBILE");
		else if(squTSpin == 3) sprintf(string[0], "3-CORNER");
		else sprintf(string[0], "3-CORNER NO KICK");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		sprintf(string[0], "%d", squStartLevel + 1);
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
			
			if(cursor == 0) {
				squBgm = squBgm + move;
				if(squBgm < 0) squBgm = 29;
				if(squBgm > 29) squBgm = 0;
			}
			if(cursor == 1) squGhost = !squGhost;
			if(cursor == 2) squFieldView = !squFieldView;
			if(cursor == 3) {
				squTSpin = squTSpin + move;
				if(squTSpin < 0) squTSpin = 4;
				if(squTSpin > 4) squTSpin = 0;
			}
			if(cursor == 4) {
				squStartLevel = squStartLevel + move;
				if(squStartLevel < 0) squStartLevel = 14;
				if(squStartLevel > 14) squStartLevel = 0;
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
			squSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			squViewRanking(player);
		}
	}
}

// 設定を保存
void squSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// 設定内容
	saveBuf[1] = squBgm;
	saveBuf[2] = squGhost;
	saveBuf[3] = squFieldView;
	saveBuf[4] = squTSpin;
	saveBuf[5] = squStartLevel;
	
	SaveFile("config/SQUARE_CONFIG.SAV", &saveBuf, 100 * 4);
}

// 設定を読み込み
int squLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/SQUARE_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// 設定内容
	squBgm = saveBuf[1];
	squGhost = saveBuf[2];
	squFieldView = saveBuf[3];
	squTSpin = saveBuf[4];
	squStartLevel = saveBuf[5];
	
	return 1;
}

// リプレイ保存
void squSaveReplay(int player) {
	saveBuf[900] = squScore[player];
	saveBuf[901] = squSquares[player];
	saveBuf[902] = squLevel[player];
	saveBuf[903] = squBgm;
	saveBuf[904] = squGhost;
	saveBuf[905] = squFieldView;
	saveBuf[906] = squTSpin;
	saveBuf[907] = squStartLevel;
}

// リプレイ読み込み
void squLoadReplay(int player) {
	squBgm = saveBuf[903];
	squGhost = saveBuf[904];
	squFieldView = saveBuf[905];
	squTSpin = saveBuf[906];
	squStartLevel = saveBuf[907];
	
	squPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void squReplayDetail() {
	printFontGrid(1, 5, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[900]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "SQUARES", 0);
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
	
	printFontGrid(1, 12, "T-SPIN", 0);
	if(saveBuf[906] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[906] == 1) sprintf(string[0], "LINE CLEAR");
	else if(saveBuf[906] == 2) sprintf(string[0], "IMMOBILE");
	else if(saveBuf[906] == 3) sprintf(string[0], "3-CORNER");
	else sprintf(string[0], "3-CORNER NO KICK");
	printFontGrid(22, 12, string[0], 0);
	
	printFontGrid(1, 13, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[907] + 1);
	printFontGrid(22, 13, string[0], 0);
}

// ランキング保存
void squSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0] = squRankingScore[i];
		saveBuf[1 + (i * 20) + 1] = squRankingSquares[i];
		saveBuf[1 + (i * 20) + 2] = squRankingLevel[i];
		saveBuf[1 + (i * 20) + 3] = squRankingTime[i];
		saveBuf[1 + (i * 20) + 4] = squRankingYear[i];
		saveBuf[1 + (i * 20) + 5] = squRankingMonth[i];
		saveBuf[1 + (i * 20) + 6] = squRankingDay[i];
		saveBuf[1 + (i * 20) + 7] = squRankingHour[i];
		saveBuf[1 + (i * 20) + 8] = squRankingMinute[i];
		saveBuf[1 + (i * 20) + 9] = squRankingSecond[i];
	}
	
	sprintf(string[0], "config/SQUARE_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 221 * 4);
}

// ランキング読み込み
int squLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/SQUARE_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 221 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 10; i++) {
		squRankingScore[i]   = saveBuf[1 + (i * 20) + 0];
		squRankingSquares[i] = saveBuf[1 + (i * 20) + 1];
		squRankingLevel[i]   = saveBuf[1 + (i * 20) + 2];
		squRankingTime[i]    = saveBuf[1 + (i * 20) + 3];
		squRankingYear[i]    = saveBuf[1 + (i * 20) + 4];
		squRankingMonth[i]   = saveBuf[1 + (i * 20) + 5];
		squRankingDay[i]     = saveBuf[1 + (i * 20) + 6];
		squRankingHour[i]    = saveBuf[1 + (i * 20) + 7];
		squRankingMinute[i]  = saveBuf[1 + (i * 20) + 8];
		squRankingSecond[i]  = saveBuf[1 + (i * 20) + 9];
	}
	
	return 1;
}

// ランキング初期化
void squInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		squRankingScore[i]   = 0;
		squRankingSquares[i] = 0;
		squRankingLevel[i]   = 0;
		squRankingTime[i]    = 0;
		squRankingYear[i]    = 0;
		squRankingMonth[i]   = 0;
		squRankingDay[i]     = 0;
		squRankingHour[i]    = 0;
		squRankingMinute[i]  = 0;
		squRankingSecond[i]  = 0;
	}
}

// ランキング登録
int squRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if(playback) return -1;
	
	for(i = 0; i < 10; i++) {
		// ランクイン
		if((squScore[player] > squRankingScore[i]) || 
		   ((squScore[player] == squRankingScore[i]) && (gameTimer[player] < squRankingTime[i])))
		{
			// ランキングをずらす
			for(j = 9; j > i; j--) {
				squRankingScore[j]   = squRankingScore[j - 1];
				squRankingSquares[j] = squRankingSquares[j - 1];
				squRankingLevel[j]   = squRankingLevel[j - 1];
				squRankingTime[j]    = squRankingTime[j - 1];
				squRankingYear[j]    = squRankingYear[j - 1];
				squRankingMonth[j]   = squRankingMonth[j - 1];
				squRankingDay[j]     = squRankingDay[j - 1];
				squRankingHour[j]    = squRankingHour[j - 1];
				squRankingMinute[j]  = squRankingMinute[j - 1];
				squRankingSecond[j]  = squRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			squRankingScore[i]   = squScore[player];
			squRankingSquares[i] = squSquares[player];
			squRankingLevel[i]   = squLevel[player];
			squRankingTime[i]    = gameTimer[player];
			
			GetDateAndTime(&timebuf);
			squRankingYear[i]    = timebuf[0];
			squRankingMonth[i]   = timebuf[1];
			squRankingDay[i]     = timebuf[2];
			squRankingHour[i]    = timebuf[4];
			squRankingMinute[i]  = timebuf[5];
			squRankingSecond[i]  = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void squViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "SQUARE MODE RANKING", 6);
		printFontGrid(1, 3, "RANK SCORE    SQUARES LEVEL TIME", 4);
		
		for(i = 0; i < 10; i++) {
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", squRankingScore[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", squRankingSquares[i]);
			printFontGrid(15, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", squRankingLevel[i] + 1);
			printFontGrid(23, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(squRankingTime[i]);
			printFontGrid(29, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// 日付と時刻
			sprintf(string[0],
			        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
			        squRankingYear[cursor], squRankingMonth[cursor], squRankingDay[cursor],
			        squRankingHour[cursor], squRankingMinute[cursor], squRankingSecond[cursor]);
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
				squInitRanking();
				squSaveRanking(player);
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
