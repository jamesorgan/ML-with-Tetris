//PUZZLE
//prefix:pzl

int pzlModeNo = -1;			// モード番号

int pzlStage[2];			// ステージ番号
int pzlClearFlag[2];		// ステージクリアフラグ
int pzlScreen[2];			// 現在の画面（0=ステージセレクト 1=ステージクリア 2=エディット）
int pzlStart[2];			// ゲームスタートフラグ
int pzlPBlock[2];			// 残りプラチナブロック数
int pzlRestLines[2];		// 残りライン数

int pzlFld[10 * 22 * 2];	// フィールド
int pzlNextb[256 * 2];		// 出現するブロックのパターン
int pzlNextc[2];			// 出現するブロックの数
int pzlCondition[2];		// クリア条件
int pzlSpeed[2];			// 落下速度
int pzlWait1[2];			// 固定→次
int pzlWait2[2];			// ブロック消去
int pzlWait3[2];			// 接地→固定
int pzlWaitt[2];			// 横溜め
int pzlBigFlag[2];			// BIGかどうか
int pzlBigMove[2];			// BIG時の移動単位
int pzlNoHold[2];			// HOLD禁止
int pzlNorm[2];				// ノルマライン数

int pzlEditStage = 0;		// エディット面かどうか
int pzlGhost = 1;			// ゴーストが有効かどうか
int pzlBgm = 8;				// 使用するBGM

// イベント発生
void pzlPluginEvent(int player, int event, int *param) {
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != pzlModeNo)) return;
	
	if(event == 0) {
		pzlModeNo = addModePlugin("PUZZLE");	// モードを登録する
	} else if(event == 5) {
		pzlReady(player, param);	// Ready
	} else if(event == 6) {
		pzlBeforeMove(player);	// ブロック出現の直前
	} else if(event == 7) {
		pzlMoveInit(player, param);	// ブロック出現
	} else if(event == 12) {
		pzlCalcScore(player, param[0]);	// ライン消去時
	} else if(event == 15) {
		pzlViewScore(player);	// ステータス表示
	} else if(event == 18) {
		pzlPlayerInitial(player);	// 初期化
	} else if(event == 19) {
		pzlPlayNextBlockSE(player);	// NEXTブロック効果音再生
	} else if(event == 28) {
		pzlIncrementTime(player);	// 時間を進める
	} else if(event == 21) {
		pzlTryAgain(player, param);	// リトライ画面
	} else if(event == 32) {
		pzlViewNextBlock(player, param);	// NEXTブロック表示
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 41) {
		pzlLoadBGM();	// BGM読み込み
	} else if(event == 65) {
		param[0] = 1;	// ピンチチェックなし
	} else if(event == 68) {
		// stat[player] == 2のとき
		if(pzlScreen[player] == 0) pzlStatStageSelect(player);	// ステージセレクト
		if(pzlScreen[player] == 1) pzlStatStageClear(player);	// ステージクリア
		if(pzlScreen[player] == 2) pzlStatStageEdit(player);	// ステージエディット
	}
}

// 初期化
void pzlPlayerInitial(int player) {
	pzlStage[player] = 0;
	pzlScreen[player] = 0;
	pzlStart[player] = 0;
	pzlPBlock[player] = 0;
	
	if(!pzlGhost) ghost[player] = 0;
	bgmlv = pzlBgm;
	
	framecolor[player] = 4;
	hnext[player] = 0;
}

// Ready
void pzlReady(int player, int *param) {
	if(!pzlStart[player]) {
		// ステージセレクト
		param[0] = 1;
		stat[player] = 2;
		pzlScreen[player] = 0;
		return;
	}
}

// NEXTブロック表示
void pzlViewNextBlock(int player, int *param) {
	int i, y, block, tmp_color[4];
	
	param[0] = 1;	// 通常の処理をスキップする
	
	printTinyFont(foffset[player] + 97, fyoffset[player] + 10, "NEXT");
	
	sprintf(string[0], "%3d/%3d", nextc[player], pzlNextc[player] + 1);
	printTinyFont(foffset[player] + 97, fyoffset[player] + 18, string[0]);
	
	// NEXT1
	if(nextc[player] <= pzlNextc[player]) {
		block = getNextBlock(player, 0);
		y = fyoffset[player] + 32 + next_offset[player * 7 + block];
		tmp_color[0] = blockcolor[player * 7 + block];
		tmp_color[1] = blockcolor[player * 7 + block];
		tmp_color[2] = blockcolor[player * 7 + block];
		tmp_color[3] = blockcolor[player * 7 + block];
		
		drawBlock(player, foffset[player] + 98, y, block, 0, &tmp_color, 0, 0);
		
		if(blockshadow != 0) {
			drawBlockShadow(player, foffset[player] + 98, y, block, 0, &tmp_color, 0, blockshadow - 1, 0, 0, 1);
		}
	}
	
	// NEXT2～10
	for(i = 0; i < 9; i++) {
		if(nextc[player] + 1 + i <= pzlNextc[player]) {
			block = getNextBlock(player, i + 1);
			y = fyoffset[player] + 64 + (i * 16);
			tmp_color[0] = blockcolor[player * 7 + block];
			tmp_color[1] = blockcolor[player * 7 + block];
			tmp_color[2] = blockcolor[player * 7 + block];
			tmp_color[3] = blockcolor[player * 7 + block];
			
			drawSmallBlock(player, foffset[player] + 100, y, block, 0, &tmp_color, 0);
			
			if(blockshadow != 0) {
				drawBlockShadowSmall(player, foffset[player] + 100, y, block, 0, &tmp_color, blockshadow - 1);
			}
		}
	}
}

// ステータス表示
void pzlViewScore(int player) {
	if(timeOn[player]) {
		// ステージ
		sprintf(string[0], "STAGE %2d", pzlStage[player] + 1);
		printFont(foffset[player] + 16, fyoffset[player] + 216, string[0], 4);
		
		// 残りプラチナブロック数
		if(pzlCondition[player] == 0) {
			sprintf(string[0], "REST %d", pzlPBlock[player]);
			printFont(foffset[player] + 24, fyoffset[player] + 224, string[0], 4);
		}
		
		// 残りライン数
		if(pzlCondition[player] == 2) {
			sprintf(string[0], "LINE  %2d", pzlRestLines[player]);
			printFont(foffset[player] + 16, fyoffset[player] + 224, string[0], 4);
		}
	}
}

// NEXTブロック効果音再生
void pzlPlayNextBlockSE(int player) {
	if(nextc[player] <= pzlNextc[player]) PlaySE(se_blockse[getNextBlock(player, 0)]);
}

// 時間を進める
void pzlIncrementTime(int player) {
	// Fボタンでリトライ
	if(timeOn[player] && getPushState(player, 9)) {
		stat[player] = 7;
		resetStatc(player);
	}
}

// ブロック出現の直前
void pzlBeforeMove(int player) {
	// 最後のブロックでホールド未使用の場合はホールド使用不可能に
	if((nextc[player] >= pzlNextc[player]) && (hold[player] == -1) && (statc[player * 10 + 1])) {
		dhold[player] = 2;
	}
}

// ブロック出現
void pzlMoveInit(int player, int *param) {
	int i;
	
	// ステージクリア
	if(pzlClearFlag[player]) {
		param[0] = 2;
		pzlScreen[player] = 1;
		stat[player] = 2;
		resetStatc(player);
		return;
	}
	
	// NEXTブロックを使い果たすとゲームオーバー
	if((nextc[player] > pzlNextc[player]) && (!param[1])) {
		param[0] = 2;
		stat[player] = 7;
		resetStatc(player);
		return;
	}
}

// ライン消去時
void pzlCalcScore(int player, int lines) {
	// プラチナブロック消去クリア
	if(pzlCondition[player] == 0) {
		pzlPBlock[player] = checkHowManyPBlocks(player);
		if(pzlPBlock[player] == 0) pzlClearFlag[player] = 1;
	}
	
	// 全消しクリア
	if((pzlCondition[player] == 1) && (isBravo(player))) {
		pzlClearFlag[player] = 1;
	}
	
	// ライン消去クリア
	if(pzlCondition[player] == 2) {
		pzlRestLines[player] = pzlRestLines[player] - lines;
		
		if(pzlRestLines[player] <= 0) {
			pzlRestLines[player] = 0;
			pzlClearFlag[player] = 1;
		}
	}
}

// リトライ画面
void pzlTryAgain(int player, int *param) {
	int i;
	
	param[0] = 1;	// 通常の処理をスキップする
	
	printFont(foffset[player] + 8, fyoffset[player] + 88, "TRY AGAIN?", 3);
	
	printFont(foffset[player] + 36, fyoffset[player] + 104, "YES", (statc[player * 10 + 1] == 0) * 2);
	printFont(foffset[player] + 36, fyoffset[player] + 120, "NO", (statc[player * 10 + 1] == 1) * 2);
	
	// 選択
	if(getPushState(player, 0) || getPushState(player, 1)) {
		PlaySE(se_move);
		statc[player * 10 + 1] = !statc[player * 10 + 1];
	}
	
	// 決定
	if(getPushState(player, 4)) {
		PlaySE(se_kettei);
		
		if(statc[player * 10 + 1] == 0) {
			// YES
			pzlStageRead(player);
			stat[player] = 3;
		} else {
			// NO
			pzlScreen[player] = 0;
			stat[player] = 2;
		}
		
		resetStatc(player);
	}
}

// BGM読み込み
void pzlLoadBGM() {
	// BGM読み込み
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(pzlBgm);
	}
}

// ステージセレクト画面
void pzlStatStageSelect(int player) {
	int i, move;
	
	padRepeat2(player);
	
	// ステージ読み込み
	if(statc[player * 10] == 0) {
		pzlLoadStage(player, pzlStage[player], pzlEditStage);
		pzlStageRead(player);
		statc[player * 10] = 1;
	}
	
	printFont(foffset[player], fyoffset[player] + 88, "STAGE SELECT", 3);
	
	sprintf(string[0], "kSTAGE %2dn", pzlStage[player] + 1);
	printFont(foffset[player] + 8, fyoffset[player] + 112, string[0], (count % 4 / 2) * 7);
	
	if(pzlCondition[player] == 0) sprintf(string[0], "TARGET");
	if(pzlCondition[player] == 1) sprintf(string[0], "BRAVO");
	if(pzlCondition[player] == 2) sprintf(string[0], "%dLINE", pzlNorm[player]);
	printFont(foffset[player] + 24, fyoffset[player] + 128, string[0], 1);
	
	printFont(foffset[player] + 16, fyoffset[player] + 144, "A:START!", 0);
	printFont(foffset[player] + 24, fyoffset[player] + 152, "B:EXIT", 0);
	printFont(foffset[player] + 24, fyoffset[player] + 160, "D:EDIT", 0);
	
	// Aボタンで開始
	if(getPushState(player, 4)) {
		PlaySE(se_kettei);
		stat[player] = 3;
		resetStatc(player);
		pzlStart[player] = 1;
		return;
	}
	
	// Bボタンで終了
	if(getPushState(player, 5)) {
		stat[player] = 0;
		return;
	}
	
	// Dボタンでエディット画面へ
	if(getPushState(player, 7)) {
		PlaySE(se_shaki);
		pzlScreen[player] = 2;
		resetStatc(player);
		return;
	}
	
	// ステージ移動
	move = 0;
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
		move = getPressState(player, 1) - getPressState(player, 0);
	
	if(move) {
		PlaySE(se_move);
		pzlStage[player] = pzlStage[player] + move;
		if(pzlStage[player] < 0) pzlStage[player] = 98;
		if(pzlStage[player] > 98) pzlStage[player] = 0;
		statc[player * 10] = 0;
	}
}

// ステージクリア画面
void pzlStatStageClear(int player) {
	int i;
	
	statc[player * 10 + 1]++;
	
	timeOn[player] = 0;
	onRecord[player] = 0;
	
	// 効果音
	if(statc[player * 10 + 1] == 1) PlaySE(se_cheer);
	
	// 花火
	if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 10)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 2]++;
	}
	
	if(statc[player * 10 + 2] >= 10) {
		printFont(foffset[player] + 8, fyoffset[player] + 88, "GREAT JOB!", (count % 4 / 2) * 3);
		
		sprintf(string[0], "STAGE %2d", pzlStage[player] + 1);
		printFont(foffset[player] + 16, fyoffset[player] + 112, string[0], 0);
		
		printFont(foffset[player] + 24, fyoffset[player] + 128, "CLEAR!", 0);
		
		// Aボタンでステージセレクトへ
		if(getPushState(player, 4)) {
			pzlScreen[player] = 0;
			resetStatc(player);
		}
	}
}

// ステージエディット画面
void pzlStatStageEdit(int player) {
	int i, move, cx, cy, color;
	
	padRepeat2(player);
	
	if(statc[player * 10] == 0) {
		// メニュー画面
		printFont(foffset[player] + 8, fyoffset[player] + 56, "STAGE EDIT", 4);
		sprintf(string[0], "STAGE %2d", pzlStage[player] + 1);
		printFont(foffset[player] + 16, fyoffset[player] + 64, string[0], 4);
		
		printFont(foffset[player] + 8, fyoffset[player] +  80, "FIELD EDIT", (statc[player * 10 + 1] == 0) * 2);
		printFont(foffset[player] + 8, fyoffset[player] +  88, "NEXT BLOCK", (statc[player * 10 + 1] == 1) * 2);
		printFont(foffset[player] + 8, fyoffset[player] +  96, "PARAMETER",  (statc[player * 10 + 1] == 2) * 2);
		printFont(foffset[player] + 8, fyoffset[player] + 104, "LOAD",       (statc[player * 10 + 1] == 3) * 2);
		printFont(foffset[player] + 8, fyoffset[player] + 112, "SAVE",       (statc[player * 10 + 1] == 4) * 2);
		
		// カーソル移動
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			statc[player * 10 + 1] = statc[player * 10 + 1] + move;
			if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = 4;
			if(statc[player * 10 + 1] > 4) statc[player * 10 + 1] = 0;
		}
		
		// Aボタン
		if(getPushState(player, 4)) {
			PlaySE(se_kettei);
			
			// FIELD EDIT
			if(statc[player * 10 + 1] == 0) {
				resetStatc(player);
				statc[player * 10] = 1;
				statc[player * 10 + 4] = 1;
			}
			// NEXT BLOCK
			if(statc[player * 10 + 1] == 1) {
				resetStatc(player);
				statc[player * 10] = 2;
			}
			// PARAMETER
			if(statc[player * 10 + 1] == 2) {
				resetStatc(player);
				statc[player * 10] = 3;
			}
			// LOAD
			if(statc[player * 10 + 1] == 3) {
				pzlLoadStage(player, pzlStage[player], pzlEditStage);
				pzlStageRead(player);
			}
			// SAVE
			if(statc[player * 10 + 1] == 4) {
				pzlStageWrite(player);
				pzlSaveStage(player, pzlStage[player], pzlEditStage);
			}
		}
		
		// Bボタン
		if(getPushState(player, 5)) {
			pzlScreen[player] = 0;
			resetStatc(player);
		}
	} else if(statc[player * 10] == 1) {
		// FIELD EDIT
		// statc[player * 10 + 1] : X座標
		// statc[player * 10 + 2] : Y座標
		// statc[player * 10 + 3] : ブロックの色
		// statc[player * 10 + 4] : 画面を切り替えた瞬間いきなりブロックを置くのを防ぐフラグ
		
		// カーソル移動（左右）／ブロック選択
		move = 0;
		if( (mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) )
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_move);
			
			if(getPressState(player, 6)) {
				statc[player * 10 + 3] = statc[player * 10 + 3] + move;
				if(statc[player * 10 + 3] < 0) statc[player * 10 + 3] = 16;
				if(statc[player * 10 + 3] > 16) statc[player * 10 + 3] = 0;
			} else {
				statc[player * 10 + 1] = statc[player * 10 + 1] + move;
				if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = 9;
				if(statc[player * 10 + 1] > 9) statc[player * 10 + 1] = 0;
			}
		}
		
		// カーソル移動（上下）
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			statc[player * 10 + 2] = statc[player * 10 + 2] + move;
			if(statc[player * 10 + 2] < 0) statc[player * 10 + 2] = 21;
			if(statc[player * 10 + 2] > 21) statc[player * 10 + 2] = 0;
		}
		
		cx = statc[player * 10 + 1];
		cy = statc[player * 10 + 2];
		color = statc[player * 10 + 3];
		
		// カーソル表示
		drawSBlock(player, foffset[player] + 8 + (cx * 8), fyoffset[player] + (cy + 3) * 8, color, 0, 0, 0, 0);
		ExBltFastRect(sg_blkline, foffset[player] + 8 + (cx * 8)    , fyoffset[player] + (cy + 3) * 8    , 16,  0, 8, 1);
		ExBltFastRect(sg_blkline, foffset[player] + 8 + (cx * 8)    , fyoffset[player] + (cy + 3) * 8 + 7, 16, 15, 8, 1);
		ExBltFastRect(sg_blkline, foffset[player] + 8 + (cx * 8)    , fyoffset[player] + (cy + 3) * 8    , 16, 16, 1, 8);
		ExBltFastRect(sg_blkline, foffset[player] + 8 + (cx * 8) + 7, fyoffset[player] + (cy + 3) * 8    , 23, 24, 1, 8);
		
		// 座標
		sprintf(string[0], "X:%2d  Y:%2d", cx, cy);
		printFont(foffset[player] + 8, fyoffset[player] + 200, string[0], 0);
		
		// 操作方法
		printFont(foffset[player], fyoffset[player] + 216, "A:PUT D:ERASE", 4);
		printFont(foffset[player], fyoffset[player] + 224, "C+<>:COLOR", 4);
		
		// Aでブロック配置
		if(getPressState(player, 4) && !statc[player * 10 + 4]) {
			if(getFieldBlock(player, cx, cy) != color + 1) {
				PlaySE(se_kachi);
				setFieldBlock(player, cx, cy, color + 1);
				setFieldBlockT(player, cx, cy, -1);
			}
		}
		if(!getPressState(player, 4)) {
			statc[player * 10 + 4] = 0;
		}
		
		// Dでブロック消去
		if(getPressState(player, 7)) {
			if(getFieldBlock(player, cx, cy) != 0) {
				PlaySE(se_kachi);
				setFieldBlock(player, cx, cy, 0);
				setFieldBlockT(player, cx, cy, 0);
			}
		}
		
		// Bボタンで終わり
		if(getPushState(player, 5)) {
			PlaySE(se_move);
			resetStatc(player);
		}
	} else if(statc[player * 10] == 2) {
		// NEXT BLOCK
		printFont(foffset[player] + 8, fyoffset[player] + 56, "kn SELECT", 7);
		printFont(foffset[player] + 8, fyoffset[player] + 64, "<> CHANGE", 7);
		printFont(foffset[player] + 8, fyoffset[player] + 72, "C+<> MAX", 7);
		
		// 上下
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			nextc[player] = nextc[player] + move;
			if(nextc[player] < 0) nextc[player] = pzlNextc[player];
			if(nextc[player] > pzlNextc[player]) nextc[player] = 0;
		}
		
		// 左右
		move = 0;
		if( (mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) )
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(getPressState(player, 6)) {
				// NEXT最大数
				pzlNextc[player] = pzlNextc[player] + move;
				if(pzlNextc[player] < 0) pzlNextc[player] = 255;
				if(pzlNextc[player] > 255) pzlNextc[player] = 0;
				
				if(nextc[player] > pzlNextc[player]) nextc[player] = pzlNextc[player];
			} else {
				// ブロック種類
				nextb[nextc[player] + player * 1400] = nextb[nextc[player] + player * 1400] + move;
				if(nextb[nextc[player] + player * 1400] < 0) nextb[nextc[player] + player * 1400] = 6;
				if(nextb[nextc[player] + player * 1400] > 6) nextb[nextc[player] + player * 1400] = 0;
			}
		}
		
		// AかBボタンで終わり
		if(getPushState(player, 4) || getPushState(player, 5)) {
			PlaySE(se_move);
			nextc[player] = 0;
			resetStatc(player);
		}
	} else if(statc[player * 10] == 3) {
		// PARAMETER
		printFont(foffset[player] + 8, fyoffset[player] + 48, "CONDITION", 4);
		if(pzlCondition[player] == 0) sprintf(string[0], "TARGET");
		if(pzlCondition[player] == 1) sprintf(string[0], "BRAVO");
		if(pzlCondition[player] == 2) sprintf(string[0], "LINE");
		printFont(foffset[player] + 8, fyoffset[player] + 56, string[0], (statc[player * 10 + 1] == 0) * 2);
		
		printFont(foffset[player] + 8, fyoffset[player] + 72, "GAME SPEED", 4);
		sprintf(string[0], "SPEED %4d", pzlSpeed[player]);
		printFont(foffset[player] + 8, fyoffset[player] + 80, string[0], (statc[player * 10 + 1] == 1) * 2);
		if(!english) sprintf(string[0], "SYUTUGEN%2d", pzlWait1[player]);
		else sprintf(string[0], "ARE     %2d", pzlWait1[player]);
		printFont(foffset[player] + 8, fyoffset[player] + 88, string[0], (statc[player * 10 + 1] == 2) * 2);
		if(!english) sprintf(string[0], "SYOUKYO %2d", pzlWait2[player]);
		else sprintf(string[0], "LINE    %2d", pzlWait2[player]);
		printFont(foffset[player] + 8, fyoffset[player] + 96, string[0], (statc[player * 10 + 1] == 3) * 2);
		if(!english) sprintf(string[0], "SETTYAKU%2d", pzlWait3[player]);
		else sprintf(string[0], "LOCK    %2d", pzlWait3[player]);
		printFont(foffset[player] + 8, fyoffset[player] + 104, string[0], (statc[player * 10 + 1] == 4) * 2);
		if(!english) sprintf(string[0], "YOKOTAME%2d", pzlWaitt[player]);
		else sprintf(string[0], "DAS     %2d", pzlWaitt[player]);
		printFont(foffset[player] + 8, fyoffset[player] + 112, string[0], (statc[player * 10 + 1] == 5) * 2);
		
		printFont(foffset[player] + 8, fyoffset[player] + 128, "BIG MODE", 4);
		sprintf(string[0], "BIG FLAG %d", pzlBigFlag[player]);
		printFont(foffset[player] + 8, fyoffset[player] + 136, string[0], (statc[player * 10 + 1] == 6) * 2);
		sprintf(string[0], "BIG MOVE %d", pzlBigMove[player] + 1);
		printFont(foffset[player] + 8, fyoffset[player] + 144, string[0], (statc[player * 10 + 1] == 7) * 2);
		
		printFont(foffset[player] + 8, fyoffset[player] + 160, "OTHERS", 4);
		sprintf(string[0], "NOHOLD   %d", pzlNoHold[player]);
		printFont(foffset[player] + 8, fyoffset[player] + 168, string[0], (statc[player * 10 + 1] == 8) * 2);
		sprintf(string[0], "NORM    %2d", pzlNorm[player]);
		printFont(foffset[player] + 8, fyoffset[player] + 176, string[0], (statc[player * 10 + 1] == 9) * 2);
		
		// カーソル移動
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			statc[player * 10 + 1] = statc[player * 10 + 1] + move;
			if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = 9;
			if(statc[player * 10 + 1] > 9) statc[player * 10 + 1] = 0;
		}
		
		// 左右
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(statc[player * 10 + 1] == 0) {
				pzlCondition[player] = pzlCondition[player] + move;
				if(pzlCondition[player] < 0) pzlCondition[player] = 2;
				if(pzlCondition[player] > 2) pzlCondition[player] = 0;
			}
			if(statc[player * 10 + 1] == 1) {
				pzlSpeed[player] = pzlSpeed[player] + move;
				if(pzlSpeed[player] < 0) pzlSpeed[player] = 1200;
				if(pzlSpeed[player] > 1200) pzlSpeed[player] = 0;
			}
			if(statc[player * 10 + 1] == 2) {
				pzlWait1[player] = pzlWait1[player] + move;
				if(pzlWait1[player] < 0) pzlWait1[player] = 99;
				if(pzlWait1[player] > 99) pzlWait1[player] = 0;
			}
			if(statc[player * 10 + 1] == 3) {
				pzlWait2[player] = pzlWait2[player] + move;
				if(pzlWait2[player] < 0) pzlWait2[player] = 99;
				if(pzlWait2[player] > 99) pzlWait2[player] = 0;
			}
			if(statc[player * 10 + 1] == 4) {
				pzlWait3[player] = pzlWait3[player] + move;
				if(pzlWait3[player] < 0) pzlWait3[player] = 99;
				if(pzlWait3[player] > 99) pzlWait3[player] = 0;
			}
			if(statc[player * 10 + 1] == 5) {
				pzlWaitt[player] = pzlWaitt[player] + move;
				if(pzlWaitt[player] < 0) pzlWaitt[player] = 99;
				if(pzlWaitt[player] > 99) pzlWaitt[player] = 0;
			}
			if(statc[player * 10 + 1] == 6) pzlBigFlag[player] = !pzlBigFlag[player];
			if(statc[player * 10 + 1] == 7) pzlBigMove[player] = !pzlBigMove[player];
			if(statc[player * 10 + 1] == 8) pzlNoHold[player] = !pzlNoHold[player];
			if(statc[player * 10 + 1] == 9) {
				pzlNorm[player] = pzlNorm[player] + move;
				if(pzlNorm[player] < 0) pzlNorm[player] = 99;
				if(pzlNorm[player] > 99) pzlNorm[player] = 0;
			}
		}
		
		// AかBボタンで終わり
		if(getPushState(player, 4) || getPushState(player, 5)) {
			if(getPushState(player, 4)) PlaySE(se_kettei);
			nextc[player] = 0;
			resetStatc(player);
		}
	}
}

// ステージ保存
void pzlSaveStage(int player, int number, int type) {
	int i, j, temp;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// 地形データ
	for(i = 0; i < 55; i++) {
		saveBuf[i + 1] = (pzlFld[(i * 4) + 0 + player * 220]);
		saveBuf[i + 1] = saveBuf[i + 1] | (pzlFld[(i * 4) + 1 + player * 220] << 8);
		saveBuf[i + 1] = saveBuf[i + 1] | (pzlFld[(i * 4) + 2 + player * 220] << 16);
		saveBuf[i + 1] = saveBuf[i + 1] | (pzlFld[(i * 4) + 3 + player * 220] << 24);
	}
	
	// NEXTブロック
	for(i = 0; i < 32; i++) {
		temp = 0;
		for(j = 0; j < 8; j++) {
			temp = temp | (pzlNextb[(i << 3) + j + player * 256] << (j * 4));
		}
		saveBuf[56 + i] = temp;
	}
	
	// 設定データ
	saveBuf[88] = pzlNextc[player];
	saveBuf[89] = pzlCondition[player];
	saveBuf[90] = pzlSpeed[player];
	saveBuf[91] = pzlWait1[player];
	saveBuf[92] = pzlWait2[player];
	saveBuf[93] = pzlWait3[player];
	saveBuf[94] = pzlWaitt[player];
	saveBuf[95] = pzlBigFlag[player];
	saveBuf[96] = pzlBigMove[player];
	saveBuf[97] = pzlNoHold[player];
	saveBuf[98] = pzlNorm[player];
	
	// 保存
	if(!type) sprintf(string[0], "stage/puzzle/stage%02d.sav", number);
	else sprintf(string[0], "stage/puzzle/edit%02d.sav", number);
	SaveFile(string[0], &saveBuf, 150 * 4);
}

// ステージ読み込み
int pzlLoadStage(int player, int number, int type) {
	int i, j;
	
	// 読み込み失敗しても大丈夫なようにダミーでデフォルト値を設定
	for(i = 0; i < 220; i++) pzlFld[i + player * 220] = 0;
	for(i = 0; i < 256; i++) pzlNextb[i + player * 256] = 0;
	pzlNextc[player] = 0;
	pzlCondition[player] = 0;
	pzlSpeed[player] = 1;
	pzlWait1[player] = 25;
	pzlWait2[player] = 40;
	pzlWait3[player] = 99;
	pzlWaitt[player] = 16;
	pzlBigFlag[player] = 0;
	pzlBigMove[player] = 1;
	pzlNoHold[player] = 0;
	pzlNorm[player] = 0;
	
	// 読み込み開始
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	if(!type) sprintf(string[0], "stage/puzzle/stage%02d.sav", number);
	else sprintf(string[0], "stage/puzzle/edit%02d.sav", number);
	LoadFile(string[0], &saveBuf, 150 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// 地形データ
	for(i = 0; i < 55; i++) {
		pzlFld[(i * 4) + 0 + player * 220] = (saveBuf[1 + i] & 0x000000FF);
		pzlFld[(i * 4) + 1 + player * 220] = (saveBuf[1 + i] & 0x0000FF00) >> 8;
		pzlFld[(i * 4) + 2 + player * 220] = (saveBuf[1 + i] & 0x00FF0000) >> 16;
		pzlFld[(i * 4) + 3 + player * 220] = (saveBuf[1 + i] & 0xFF000000) >> 24;
	}
	
	// NEXTブロックデータ
	for(i = 0; i < 32; i++) {
		for(j = 0; j < 8; j++) {
			pzlNextb[(i << 3) + j + player * 256] = ((saveBuf[56 + i]) >> (j * 4)) & 15;
		}
	}
	
	// 設定データ
	pzlNextc[player] = saveBuf[88];
	pzlCondition[player] = saveBuf[89];
	pzlSpeed[player] = saveBuf[90];
	pzlWait1[player] = saveBuf[91];
	pzlWait2[player] = saveBuf[92];
	pzlWait3[player] = saveBuf[93];
	pzlWaitt[player] = saveBuf[94];
	pzlBigFlag[player] = saveBuf[95];
	pzlBigMove[player] = saveBuf[96];
	pzlNoHold[player] = saveBuf[97];
	pzlNorm[player] = saveBuf[98];
	
	return 1;
}

// ステージの内容を書き換える
void pzlStageWrite(int player) {
	int i;
	
	// フィールド
	for(i = 0; i < 220; i++) pzlFld[i + player * 220] = fld[i + player * 220];
	
	// NEXTブロック
	for(i = 0; i < 256; i++) pzlNextb[i + player * 256] = nextb[i + player * 1400];
}

// ステージの内容をゲームに反映させる
void pzlStageRead(int player) {
	int i;
	
	// フィールド
	for(i = 0; i < 220; i++) fld[i + player * 220] = pzlFld[i + player * 220];
	disableShadowTimer(player);	// ブロックを見えるようにする
	
	// NEXTブロック
	for(i = 0; i < 256; i++) nextb[i + player * 1400] = pzlNextb[i + player * 256];
	
	// 速度
	sp[player] = pzlSpeed[player];
	wait1[player] = pzlWait1[player];
	wait2[player] = pzlWait2[player];
	wait3[player] = pzlWait3[player];
	waitt[player] = pzlWaitt[player];
	
	// BIG
	IsBig[player] = pzlBigFlag[player];
	BigMove[player] = pzlBigMove[player];
	
	// ホールド禁止
	if(pzlNoHold[player]) dhold[player] = 2;
	else dhold[player] = 0;
	if(!pzlNextc[player]) dhold[player] = 2;
	
	// いろいろ初期化
	nextc[player] = 0;
	hold[player] = -1;
	disp_blkline[player] = 1;
	pzlClearFlag[player] = 0;
	pzlPBlock[player] = checkHowManyPBlocks(player);
	pzlRestLines[player] = pzlNorm[player];
	gameTimer[player] = 0;
	recTimer[player] = 0;
	setNextBlockColor(player, 1);
}
