//クラシックルール
//prefix:ars

// クラシックルール ブロックデータ
int arsBlkDataX[7 * 4 * 4] =	// ユニットを構成するブロックの相対Ｘ位置(7種類/4角度/4ブロック)
{
	0, 1, 2, 3,			2, 2, 2, 2,			3, 2, 1, 0,			2, 2, 2, 2,	// I
	1, 0, 0, 2,			1, 0, 1, 1,			1, 2, 2, 0,			1, 2, 1, 1,	// L
	1, 2, 2, 1,			2, 2, 1, 1,			2, 1, 1, 2,			1, 1, 2, 2,	// O
	1, 0, 1, 2,			2, 2, 1, 1,			1, 2, 1, 0,			1, 1, 2, 2,	// Z
	1, 0, 1, 2,			1, 1, 0, 1,			1, 2, 1, 0,			1, 1, 2, 1,	// T
	1, 0, 2, 2,			1, 1, 1, 0,			1, 2, 0, 0,			1, 1, 1, 2,	// J
	1, 2, 1, 0,			1, 1, 0, 0,			1, 0, 1, 2,			0, 0, 1, 1,	// S
};

int arsBlkDataY[7 * 4 * 4] =	// ユニットを構成するブロックの相対Ｙ位置(7種類/4角度/4ブロック)
{
	1, 1, 1, 1,			0, 1, 2, 3,			1, 1, 1, 1,			3, 2, 1, 0,	// I
	1, 2, 1, 1,			1, 0, 0, 2,			2, 1, 2, 2,			1, 2, 2, 0,	// L
	1, 1, 2, 2,			1, 2, 2, 1,			2, 2, 1, 1,			2, 1, 1, 2,	// O
	1, 1, 2, 2,			1, 0, 1, 2,			2, 2, 1, 1,			1, 2, 1, 0,	// Z
	1, 1, 2, 1,			1, 0, 1, 2,			2, 2, 1, 2,			1, 2, 1, 0,	// T
	1, 1, 1, 2,			1, 0, 2, 2,			2, 2, 2, 1,			1, 2, 0, 0,	// J
	1, 1, 2, 2,			1, 2, 1, 0,			2, 2, 1, 1,			1, 0, 1, 2,	// S
};

// ブロック出現位置（通常）
int arsSpawnX[7]   = { 3, 3, 3, 3, 3, 3, 3};	// X座標
int arsSpawnYU[7]  = { 1, 1, 1, 1, 1, 1, 1};	// Y座標（枠内出現）
int arsSpawnYA[7]  = { 0,-1,-1,-1,-1,-1,-1};	// Y座標（枠外出現）
int arsNDelay[7]   = { 0, 0, 0, 0, 0, 0, 0};	// 枠外出現でNEXT遅延を解除するY座標

// ブロック出現位置（ビッグ）
int arsBSpawnX[7]  = { 1, 2, 1, 2, 2, 2, 2};	// X座標（1マス移動）
int arsBSpawnX2[7] = { 2, 2, 2, 2, 2, 2, 2};	// X座標（2マス移動）
int arsBSpawnYU[7] = { 0, 0, 0, 0, 0, 0, 0};	// Y座標（枠内出現）
int arsBSpawnYA[7] = {-1,-2,-2,-2,-2,-2,-2};	// Y座標（枠外出現）
int arsBNDelay[7]  = {-1,-1,-1,-1,-1,-1,-1};	// 枠外出現でNEXT遅延を解除するY座標

// ブロックの色と表示名
int arsColor[7 * 2];
str arsStrColor[8] = {"GRAY", "RED", "ORANGE", "YELLOW", "GREEN", "CYAN", "BLUE", "PURPLE"};

int arsRuleNumber = -1;		// ルール番号

int arsExtRotate[2];		// 赤の壁蹴り床蹴り
int arsLockReset[2];		// 固定時間リセット
int arsRotLimit[2];			// 回転制限
int arsMoveLimit[2];		// 移動制限
int arsGraphics[2];			// グラフィック番号
int arsAre[2];				// 出現待ち時間の有無
int arsLockUp[2];			// 上で即固定
int arsLockDown[2];			// 下で即固定
int arsRotReverse[2];		// 回転方向を逆転させる
int arsSoftSpeed[2];		// ソフトドロップの速度
int arsMaxWaitt[2];			// 最大横溜め
int arsFastlrmove[2];		// 先行横移動
int arsOBlkBG[2];			// ご先祖様登場中の背景
int arsInitRotate[2];		// 先行回転
int arsInitHold[2];			// 先行ホールド
int arsEnableKick[2];		// 壁蹴り有効
int arsSelfLockSound[2];	// 自分で固定させたときに音を出す
int arsLockflash[2];		// ブロックを固定させた瞬間、ブロックが光るフレーム数
int arsRepeatDelay[2];		// RepeatDelay

int arsPreset[30 * 5];		// プリセット
int arsLastPresetNo[2];		// 最後に選択したプリセット番号

// イベント発生時に呼ばれる
void arsPluginEvent(int player, int event, int *param) {
	// ルールがARSじゃなかったら戻る（ルールを登録するタイミング以外の場合）
	if((event != 0) && (rots[player] != arsRuleNumber)) return;
	
	if(event == 0) {
		arsRuleNumber = addRulePlugin("ARS");	// ルールを登録する
	} else if(event == 8) {
		arsBlockMove(player);	// ブロック移動中
	} else if(event == 9) {
		arsWallKick(player, param);	// 壁蹴り
	} else if(event == 16) {
		arsSetting(player, param);	// 設定画面
	} else if(event == 18) {
		arsPlayerInitial(player);	// ゲーム開始前の初期化
	} else if(event == 19) {
		arsBlockSpawn(player);	// ブロック出現時
	} else if(event == 54) {
		arsReplayDetail(param[0]);	// リプレイ詳細
	} else if(event == 58) {
		arsIsTSpin3Corner(player, param);	// 3-CORNERタイプのT-SPIN判定
	}
}

// ゲーム開始前の初期化
void arsPlayerInitial(int player) {
	int i;
	
	// ブロックデータをコピー
	for(i = 0; i < 112; i++) {
		blkDataX[player * 112 + i] = arsBlkDataX[i];
		blkDataY[player * 112 + i] = arsBlkDataY[i];
	}
	makeBlockLinkData(player); // ブロックの繋がりデータを自動生成
	
	// 棒はNEXTでの位置をずらす
	next_offset[player * 7 + 0] = 8;
	
	// 設定を反映させる
	kicktype[player] = arsExtRotate[player];
	lockreset[player] = arsLockReset[player];
	rotlimit[player] = arsRotLimit[player];
	movelimit[player] = arsMoveLimit[player];
	blockgraphics[player] = arsGraphics[player];
	are[player] = arsAre[player];
	lock_up[player] = arsLockUp[player];
	lock_down[player] = arsLockDown[player];
	rot_reverse[player] = arsRotReverse[player];
	softspeed[player] = arsSoftSpeed[player];
	max_waitt[player] = arsMaxWaitt[player];
	fastlrmove[player] = arsFastlrmove[player];
	oblk_bg[player] = arsOBlkBG[player];
	for(i = 0; i < 7; i++) blockcolor[player * 7 + i] = arsColor[player * 7 + i];
	initial_rotate[player] = arsInitRotate[player];
	initial_hold[player] = arsInitHold[player];
	enable_wallkick[player] = arsEnableKick[player];
	self_lock_sound[player] = arsSelfLockSound[player];
	lockflash[player] = arsLockflash[player];
	RepeatDelay[player] = arsRepeatDelay[player];
}

// 壁蹴り
void arsWallKick(int player, int *param) {
	int i, temp, bak, move;
	bak = param[1];
	move = param[2];
	
	// 棒以外
	if(blk[player] != 0) {
		// 重なっている部分が真中の列だけではなければ
		if(judgeBlockRotate(player, bx[player], by[player], blk[player], bak)) {
			temp = 0;
			
			for(i = 0; i <= IsBig[player]; i++) {
				// 左
				if(judgeBlock(player, bx[player] - 1 - i, by[player], blk[player], bak) == 0) temp = -1 - i;
				// 右
				if(judgeBlock(player, bx[player] + 1 + i, by[player], blk[player], bak) == 0) temp = 1 + i;
				
				if(temp) {
					bx[player] = bx[player] + temp;
					param[0] = 1;
					return;
				}
			}
		}
	}
	
	// Ｔ字の脱出（1回だけ）
	if((kicktype[player]) && (blk[player] == 4) && (!kickc[player]) && (bak == 2)) {
		for(i = 0; i <= IsBig[player]; i++) {
			if(judgeBlock(player, bx[player], by[player] - 1 - i, blk[player], bak) == 0) {
				by[player] = by[player] - 1 - i;
				kickc[player]++;
				bk[player] = 0;
				bfallflag[player] = 1;
				param[0] = 1;
				return;
			}
		}
	}
	
	// ヘボリス棒の壁蹴り
	if((kicktype[player]) && (blk[player] == 0) && ((bak == 0) || (bak == 2))) {
		for(i = 0; i <= IsBig[player] * 2; i++) {
			temp = 0;
			
			if(judgeBlock(player, bx[player] - 1 - i, by[player], blk[player], bak) == 0) {
				temp = -1 - i;
			} else if(judgeBlock(player, bx[player] + 1 + i, by[player], blk[player], bak) == 0) {
				temp = 1 + i;
			} else if(judgeBlock(player, bx[player] + 2 + i, by[player], blk[player], bak) == 0) {
				temp = 2 + i;
			}
			
			// 壁蹴り実行
			if(temp) {
				bx[player] = bx[player] + temp;
				param[0] = 1;
				return;
			}
		}
	}
	
	// ヘボリス棒の床蹴り（1回だけ、接地している場合のみ）
	if( (kicktype[player]) && (blk[player] == 0) && ((bak == 1) || (bak == 3)) && (!kickc[player]) && 
	    (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0) )
	{
		for(i = 0; i <= IsBig[player] * 2; i++) {
			temp = 0;
			
			if(judgeBlock(player, bx[player], by[player] - 1 - i, blk[player], bak) == 0) {
				temp = -1 - i;
			} else if(judgeBlock(player, bx[player], by[player] - 2 - i, blk[player], bak) == 0) {
				temp = -2 - i;
			}
			
			// 床蹴り実行
			if(temp) {
				by[player] = by[player] + temp;
				kickc[player]++;
				bk[player] = 0;
				bfallflag[player] = 1;
				param[0] = 1;
				return;
			}
		}
	}
}

// ブロック移動中
void arsBlockMove(int player) {
	int temp;
	
	// NEXT遅延を解除
	if(spawntype[player]) {
		if(!IsBig[player]) temp = arsNDelay[blk[player]];
		else temp = arsBNDelay[blk[player]];
		
		if(by[player] >= temp) ndelay[player] = 1;
	}
}

// ブロック出現時
void arsBlockSpawn(int player) {
	// 出現位置を設定
	if(!IsBig[player]) {
		// 非ビッグ
		block_init_x_pos[player] = arsSpawnX[blk[player]];
		
		if(!spawntype[player])
			block_init_y_pos[player] = arsSpawnYU[blk[player]];
		else
			block_init_y_pos[player] = arsSpawnYA[blk[player]];
	} else {
		// ビッグ
		if(!BigMove[player])
			block_init_x_pos[player] = arsBSpawnX[blk[player]];
		else
			block_init_x_pos[player] = arsBSpawnX2[blk[player]];
		
		if(!spawntype[player])
			block_init_y_pos[player] = arsBSpawnYU[blk[player]];
		else
			block_init_y_pos[player] = arsBSpawnYA[blk[player]];
	}
}

// 3-CORNERタイプのT-SPIN判定
void arsIsTSpin3Corner(int player, int *param) {
	int i, cnt, tx[4], ty[4];
	int tmp_x, tmp_y;
	
	// 判定用相対座標を設定
	if(IsBig[player]) {
		tx[0] = 1;
		ty[0] = 1;
		tx[1] = 4;
		ty[1] = 1;
		tx[2] = 1;
		ty[2] = 4;
		tx[3] = 4;
		ty[3] = 4;
	} else {
		tx[0] = 0;
		ty[0] = 0;
		tx[1] = 2;
		ty[1] = 0;
		tx[2] = 0;
		ty[2] = 2;
		tx[3] = 2;
		ty[3] = 2;
	}
	
	// 判定処理
	cnt = 0;
	
	for(i = 0; i < 4; i++) {
		tmp_x = bx[player] + tx[i];
		tmp_y = by[player] + ty[i];
		
		// Tが上向きの場合
		// ◇　◇
		// 　■
		// ◆■◆
		// こんな判定にならないようにY座標を１つずらす
		if(rt[player] == 2) tmp_y = tmp_y + 1 + IsBig[player];
		
		if(tmp_y >= 0) {
			if(getFieldBlock(player, tmp_x, tmp_y) != 0) {
				cnt++;
				
				if(cnt >= 3) {
					param[0] = 1;
					return;
				}
			}
		}
	}
}

// 設定画面
void arsSetting(int player, int *param) {
	int i, temp, cursor, move;
	cursor = 0;
	
	// 設定を読み込み
	if(arsLoadConfig(player) == 0) {
		arsMakeDefaultSetting(player);
		arsMakeDefaultPreset();
	}
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		sprintf(string[0], "%dP ARS OPTIONS", player + 1);
		printFontGrid(1, 1, string[0], 2 - player);
		
		if(cursor <= 25) {
			printFontGrid(31, 1, "PAGE 1/2", 6);
			
			// カーソル表示
			printFontGrid(1, 3 + cursor, "b", 7);
			
			// メニュー表示
			printFontGrid(2,  3, "EXT-ROTATE",       7 * (cursor ==  0));
			printFontGrid(2,  4, "LOCK RESET",       7 * (cursor ==  1));
			printFontGrid(2,  5, "ROTATE LIMIT",     7 * (cursor ==  2));
			printFontGrid(2,  6, "MOVE LIMIT",       7 * (cursor ==  3));
			printFontGrid(2,  7, "BLOCK GRAPHICS",   7 * (cursor ==  4));
			printFontGrid(2,  8, "ARE",              7 * (cursor ==  5));
			printFontGrid(2,  9, "LOCK BY UP KEY",   7 * (cursor ==  6));
			printFontGrid(2, 10, "LOCK BY DOWN KEY", 7 * (cursor ==  7));
			printFontGrid(2, 11, "ROTATE REVERSE",   7 * (cursor ==  8));
			printFontGrid(2, 12, "SOFT DROP SPEED",  7 * (cursor ==  9));
			if(!english) printFontGrid(2, 13, "MAX YOKOTAME", 7 * (cursor == 10));
			else printFontGrid(2, 13, "MAX DAS", 7 * (cursor == 10));
			printFontGrid(2, 14, "INIT LR MOVE",     7 * (cursor == 11));
			printFontGrid(2, 15, "[] BACKGROUND",    7 * (cursor == 12));
			printFontGrid(2, 16, "I BLOCK COLOR",    7 * (cursor == 13));
			printFontGrid(2, 17, "L BLOCK COLOR",    7 * (cursor == 14));
			printFontGrid(2, 18, "O BLOCK COLOR",    7 * (cursor == 15));
			printFontGrid(2, 19, "Z BLOCK COLOR",    7 * (cursor == 16));
			printFontGrid(2, 20, "T BLOCK COLOR",    7 * (cursor == 17));
			printFontGrid(2, 21, "J BLOCK COLOR",    7 * (cursor == 18));
			printFontGrid(2, 22, "S BLOCK COLOR",    7 * (cursor == 19));
			printFontGrid(2, 23, "INITIAL ROTATE",   7 * (cursor == 20));
			printFontGrid(2, 24, "INITIAL HOLD",     7 * (cursor == 21));
			printFontGrid(2, 25, "ENABLE WALLKICK",  7 * (cursor == 22));
			printFontGrid(2, 26, "SELF LOCK SOUND",  7 * (cursor == 23));
			printFontGrid(2, 27, "LOCK FLASH",       7 * (cursor == 24));
			printFontGrid(2, 28, "REPEAT DELAY",     7 * (cursor == 25));
			
			// 設定値表示
			if(!arsExtRotate[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 3, string[0], 7 * (cursor == 0));
			
			if(!arsLockReset[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 4, string[0], 7 * (cursor == 1));
			
			if(!arsRotLimit[player]) sprintf(string[0], "INFINITE");
			else sprintf(string[0], "%d", arsRotLimit[player]);
			printFontGrid(22, 5, string[0], 7 * (cursor == 2));
			
			if(!arsMoveLimit[player]) sprintf(string[0], "INFINITE");
			else sprintf(string[0], "%d", arsMoveLimit[player]);
			printFontGrid(22, 6, string[0], 7 * (cursor == 3));
			
			sprintf(string[0], "%d", arsGraphics[player]);
			printFontGrid(22, 7, string[0], 7 * (cursor == 4));
			
			if(arsAre[player] == 0) sprintf(string[0], "OFF");
			else if(arsAre[player] == 1) sprintf(string[0], "ON");
			else sprintf(string[0], "ON (ENABLE SKIP)");
			printFontGrid(22, 8, string[0], 7 * (cursor == 5));
			
			if(arsLockUp[player] == 0) sprintf(string[0], "OFF");
			else if(arsLockUp[player] == 1) sprintf(string[0], "ON");
			else sprintf(string[0], "NO HARD DROP");
			printFontGrid(22, 9, string[0], 7 * (cursor == 6));
			
			if(arsLockDown[player] == 0) sprintf(string[0], "OFF");
			else if(arsLockDown[player] == 1) sprintf(string[0], "ON");
			else if(arsLockDown[player] == 2) sprintf(string[0], "SLOW LOCK");
			else if(arsLockDown[player] == 3) sprintf(string[0], "FAST LOCK");
			else if(arsLockDown[player] == 4) sprintf(string[0], "1G OR FASTER");
			else if(arsLockDown[player] == 5) sprintf(string[0], "PUSH AGAIN TO LOCK");
			else sprintf(string[0], "NO SOFT DROP");
			printFontGrid(22, 10, string[0], 7 * (cursor == 7));
			
			if(arsRotReverse[player] == 0) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 11, string[0], 7 * (cursor == 8));
			
			if(arsSoftSpeed[player] % 2 == 0) sprintf(string[0], "e %d.5", arsSoftSpeed[player] / 2);
			else sprintf(string[0], "e %d.0", (arsSoftSpeed[player] + 1) / 2);
			printFontGrid(22, 12, string[0], 7 * (cursor == 9));
			
			if(arsMaxWaitt[player] >= 99) sprintf(string[0], "INFINITE");
			else sprintf(string[0], "%d", arsMaxWaitt[player]);
			printFontGrid(22, 13, string[0], 7 * (cursor == 10));
			
			if(!arsFastlrmove[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 14, string[0], 7 * (cursor == 11));
			
			if(arsOBlkBG[player] == 0) sprintf(string[0], "OFF");
			else if(arsOBlkBG[player] == 1) sprintf(string[0], "BLACK");
			else sprintf(string[0], "WHITE");
			printFontGrid(22, 15, string[0], 7 * (cursor == 12));
			
			for(i = 0; i < 7; i++) printFontGrid(22, 16 + i, arsStrColor[arsColor[player * 7 + i]], 7 * (cursor == 13 + i));
			
			if(!arsInitRotate[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 23, string[0], 7 * (cursor == 20));
			
			if(!arsInitHold[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 24, string[0], 7 * (cursor == 21));
			
			if(!arsEnableKick[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 25, string[0], 7 * (cursor == 22));
			
			if(!arsSelfLockSound[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 26, string[0], 7 * (cursor == 23));
			
			sprintf(string[0], "%d FRAMES", arsLockflash[player]);
			printFontGrid(22, 27, string[0], 7 * (cursor == 24));
			
			if(!arsRepeatDelay[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "%d", arsRepeatDelay[player]);
			printFontGrid(22, 28, string[0], 7 * (cursor == 25));
		} else {
			printFontGrid(31, 1, "PAGE 2/2", 6);
			
			// カーソル表示
			printFontGrid(1, 3 + cursor - 26, "b", 7);
			
			// メニュー表示
			printFontGrid(2,  3, "[SAVE PRESET]",    7 * (cursor == 26));
			printFontGrid(2,  4, "[LOAD PRESET]",    7 * (cursor == 27));
			
			// 設定値表示
			sprintf(string[0], "PRESET NO.%d", arsLastPresetNo[player] + 1);
			printFontGrid(22, 3, string[0], 7 * (cursor >= 26));
		}
		
		// カーソル移動
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 27;
			if(cursor > 27) cursor = 0;
		}
		
		// 値を変更
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) arsExtRotate[player] = !arsExtRotate[player];
			if(cursor == 1) arsLockReset[player] = !arsLockReset[player];
			if(cursor == 2) {
				arsRotLimit[player] = arsRotLimit[player] + move;
				if(arsRotLimit[player] < 0) arsRotLimit[player] = 128;
				if(arsRotLimit[player] > 128) arsRotLimit[player] = 0;
			}
			if(cursor == 3) {
				arsMoveLimit[player] = arsMoveLimit[player] + move;
				if(arsMoveLimit[player] < 0) arsMoveLimit[player] = 128;
				if(arsMoveLimit[player] > 128) arsMoveLimit[player] = 0;
			}
			if(cursor == 4) {
				arsGraphics[player] = arsGraphics[player] + move;
				if(arsGraphics[player] < 0) arsGraphics[player] = 7;
				if(arsGraphics[player] > 7) arsGraphics[player] = 0;
			}
			if(cursor == 5) {
				arsAre[player] = arsAre[player] + move;
				if(arsAre[player] < 0) arsAre[player] = 2;
				if(arsAre[player] > 2) arsAre[player] = 0;
			}
			if(cursor == 6) {
				arsLockUp[player] = arsLockUp[player] + move;
				if(arsLockUp[player] < 0) arsLockUp[player] = 2;
				if(arsLockUp[player] > 2) arsLockUp[player] = 0;
			}
			if(cursor == 7) {
				arsLockDown[player] = arsLockDown[player] + move;
				if(arsLockDown[player] < 0) arsLockDown[player] = 6;
				if(arsLockDown[player] > 6) arsLockDown[player] = 0;
			}
			if(cursor == 8) arsRotReverse[player] = !arsRotReverse[player];
			if(cursor == 9) {
				arsSoftSpeed[player] = arsSoftSpeed[player] + move;
				if(arsSoftSpeed[player] < 0) arsSoftSpeed[player] = 39;
				if(arsSoftSpeed[player] > 39) arsSoftSpeed[player] = 0;
			}
			if(cursor == 10) {
				arsMaxWaitt[player] = arsMaxWaitt[player] + move;
				if(arsMaxWaitt[player] < 0) arsMaxWaitt[player] = 99;
				if(arsMaxWaitt[player] > 99) arsMaxWaitt[player] = 0;
			}
			if(cursor == 11) arsFastlrmove[player] = !arsFastlrmove[player];
			if(cursor == 12) {
				arsOBlkBG[player] = arsOBlkBG[player] + move;
				if(arsOBlkBG[player] < 0) arsOBlkBG[player] = 2;
				if(arsOBlkBG[player] > 2) arsOBlkBG[player] = 0;
			}
			if((cursor >= 13) && (cursor <= 19)) {
				temp = cursor - 13;
				arsColor[player * 7 + temp] = arsColor[player * 7 + temp] + move;
				if(arsColor[player * 7 + temp] < 0) arsColor[player * 7 + temp] = 7;
				if(arsColor[player * 7 + temp] > 7) arsColor[player * 7 + temp] = 0;
			}
			if(cursor == 20) arsInitRotate[player] = !arsInitRotate[player];
			if(cursor == 21) arsInitHold[player] = !arsInitHold[player];
			if(cursor == 22) arsEnableKick[player] = !arsEnableKick[player];
			if(cursor == 23) arsSelfLockSound[player] = !arsSelfLockSound[player];
			if(cursor == 24) {
				arsLockflash[player] = arsLockflash[player] + move;
				if(arsLockflash[player] < 0) arsLockflash[player] = 99;
				if(arsLockflash[player] > 99) arsLockflash[player] = 0;
			}
			if(cursor == 25) {
				arsRepeatDelay[player] = arsRepeatDelay[player] + move;
				if(arsRepeatDelay[player] < 0) arsRepeatDelay[player] = 99;
				if(arsRepeatDelay[player] > 99) arsRepeatDelay[player] = 0;
			}
			if(cursor >= 26) {
				arsLastPresetNo[player] = arsLastPresetNo[player] + move;
				if(arsLastPresetNo[player] < 0) arsLastPresetNo[player] = 4;
				if(arsLastPresetNo[player] > 4) arsLastPresetNo[player] = 0;
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
			PlaySE(se_kettei);
			
			if(cursor == 26) {
				arsSavePreset(player, arsLastPresetNo[player]);
				arsSaveConfig(player);
			} else if(cursor == 27) {
				arsLoadPreset(player, arsLastPresetNo[player]);
			} else {
				arsSaveConfig(player);
				return;
			}
		}
	}
}

// リプレイ詳細
void arsReplayDetail(int number) {
	int i;
	
	printFontGrid(1, 4, "EXT-ROTATE", 0);
	if(!saveBuf[207]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 4, string[0], 0);
	
	printFontGrid(1, 5, "LOCK RESET", 0);
	if(!saveBuf[208]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "ROTATE LIMIT", 0);
	if(!saveBuf[209]) sprintf(string[0], "INFINITE");
	else sprintf(string[0], "%d", saveBuf[209]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "MOVE LIMIT", 0);
	if(!saveBuf[210]) sprintf(string[0], "INFINITE");
	else sprintf(string[0], "%d", saveBuf[210]);
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 8, "BLOCK GRAPHICS", 0);
	sprintf(string[0], "%d", saveBuf[211]);
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "ARE", 0);
	if(saveBuf[212] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[212] == 1) sprintf(string[0], "ON");
	else sprintf(string[0], "ON (ENABLE SKIP)");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "LOCK BY UP KEY", 0);
	if(saveBuf[213] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[213] == 1) sprintf(string[0], "ON");
	else sprintf(string[0], "NO HARD DROP");
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "LOCK BY DOWN KEY", 0);
	if(saveBuf[214] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[214] == 1) sprintf(string[0], "ON");
	else if(saveBuf[214] == 2) sprintf(string[0], "SLOW LOCK");
	else if(saveBuf[214] == 3) sprintf(string[0], "FAST LOCK");
	else if(saveBuf[214] == 4) sprintf(string[0], "1G OR FASTER");
	else if(saveBuf[214] == 5) sprintf(string[0], "PUSH AGAIN TO LOCK");
	else sprintf(string[0], "NO SOFT DROP");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "ROTATE REVERSE", 0);
	if(!saveBuf[215]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 12, string[0], 0);
	
	printFontGrid(1, 13, "SOFT DROP SPEED", 0);
	if(saveBuf[216] % 2 == 0) sprintf(string[0], "e %d.5", saveBuf[216] / 2);
	else sprintf(string[0], "e %d.0", (saveBuf[216] + 1) / 2);
	printFontGrid(22, 13, string[0], 0);
	
	if(!english) printFontGrid(1, 14, "MAX YOKOTAME", 0);
	else printFontGrid(1, 14, "MAX DAS", 0);
	if(saveBuf[217] >= 99) sprintf(string[0], "INFINITE");
	else sprintf(string[0], "%d", saveBuf[217]);
	printFontGrid(22, 14, string[0], 0);
	
	printFontGrid(1, 15, "INIT LR MOVE", 0);
	if(!saveBuf[218]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 15, string[0], 0);
	
	printFontGrid(1, 16, "[] BACKGROUND", 0);
	if(saveBuf[219] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[219] == 1) sprintf(string[0], "BLACK");
	else sprintf(string[0], "WHITE");
	printFontGrid(22, 16, string[0], 0);
	
	printFontGrid(1, 17, "BLOCK COLORS", 0);
	for(i = 0; i < 7; i++) {
		sprintf(string[0], "%d", saveBuf[222 + i]);
		printFontGrid(22 + i, 17, string[0], 0);
	}
	
	printFontGrid(1, 18, "INITIAL ROTATE", 0);
	if(!saveBuf[229]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 18, string[0], 0);
	
	printFontGrid(1, 19, "INITIAL HOLD", 0);
	if(!saveBuf[230]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 19, string[0], 0);
	
	printFontGrid(1, 20, "ENABLE WALLKICK", 0);
	if(!saveBuf[231]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 20, string[0], 0);
	
	printFontGrid(1, 21, "SELF LOCK SOUND", 0);
	if(!saveBuf[232]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 21, string[0], 0);
	
	printFontGrid(1, 22, "LOCK FLASH", 0);
	sprintf(string[0], "%d FRAMES", saveBuf[233]);
	printFontGrid(22, 22, string[0], 0);
	
	printFontGrid(1, 22, "REPEAT DELAY", 0);
	if(!saveBuf[244]) sprintf(string[0], "OFF");
	else sprintf(string[0], "%d", saveBuf[244]);
	printFontGrid(22, 22, string[0], 0);
}

// 設定を保存
void arsSaveConfig(int player) {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x43535241;
	saveBuf[3] = 0x32764746;
	
	// 設定内容
	saveBuf[4] = arsExtRotate[player];
	saveBuf[5] = arsLockReset[player];
	saveBuf[6] = arsRotLimit[player];
	saveBuf[7] = arsMoveLimit[player];
	saveBuf[8] = arsGraphics[player];
	saveBuf[9] = arsAre[player];
	saveBuf[10] = arsLockUp[player];
	saveBuf[11] = arsLockDown[player];
	saveBuf[12] = arsRotReverse[player];
	saveBuf[13] = arsSoftSpeed[player];
	saveBuf[14] = arsMaxWaitt[player];
	saveBuf[15] = arsFastlrmove[player];
	saveBuf[16] = arsOBlkBG[player];
	for(i = 0; i < 7; i++) saveBuf[17 + i] = arsColor[player * 7 + i];
	saveBuf[24] = arsInitRotate[player];
	saveBuf[25] = arsInitHold[player];
	saveBuf[26] = arsEnableKick[player];
	saveBuf[27] = arsSelfLockSound[player];
	saveBuf[28] = arsLockflash[player];
	saveBuf[29] = arsRepeatDelay[player];
	
	saveBuf[49] = arsLastPresetNo[player];
	for(i = 0; i < 30 * 5; i++) saveBuf[50 + i] = arsPreset[i];
	
	if(!player) SaveFile("config/ARS_CONFIG.SAV", &saveBuf, 200 * 4);
	else SaveFile("config/ARS_CONFIG_2P.SAV", &saveBuf, 200 * 4);
}

// 設定を読み込み
int arsLoadConfig(int player) {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	if(!player) LoadFile("config/ARS_CONFIG.SAV", &saveBuf, 200 * 4);
	else LoadFile("config/ARS_CONFIG_2P.SAV", &saveBuf, 200 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x43535241) return 0;
	if(saveBuf[3] != 0x32764746) return 0;
	
	// 設定内容
	arsExtRotate[player] = saveBuf[4];
	arsLockReset[player] = saveBuf[5];
	arsRotLimit[player] = saveBuf[6];
	arsMoveLimit[player] = saveBuf[7];
	arsGraphics[player] = saveBuf[8];
	arsAre[player] = saveBuf[9];
	arsLockUp[player] = saveBuf[10];
	arsLockDown[player] = saveBuf[11];
	arsRotReverse[player] = saveBuf[12];
	arsSoftSpeed[player] = saveBuf[13];
	arsMaxWaitt[player] = saveBuf[14];
	arsFastlrmove[player] = saveBuf[15];
	arsOBlkBG[player] = saveBuf[16];
	for(i = 0; i < 7; i++) arsColor[player * 7 + i] = saveBuf[17 + i];
	arsInitRotate[player] = saveBuf[24];
	arsInitHold[player] = saveBuf[25];
	arsEnableKick[player] = saveBuf[26];
	arsSelfLockSound[player] = saveBuf[27];
	arsLockflash[player] = saveBuf[28];
	arsRepeatDelay[player] = saveBuf[29];
	
	arsLastPresetNo[player] = saveBuf[49];
	for(i = 0; i < 30 * 5; i++) arsPreset[i] = saveBuf[50 + i];
	
	return 1;
}

// デフォルトの設定を作成
void arsMakeDefaultSetting(int player) {
	arsExtRotate[player] = 1;		// 赤の壁蹴り床蹴り
	arsLockReset[player] = 0;		// 固定時間リセット
	arsRotLimit[player] = 0;		// 回転制限
	arsMoveLimit[player] = 0;		// 移動制限
	arsGraphics[player] = 1;		// グラフィック番号
	arsAre[player] = 1;				// 出現待ち時間の有無
	arsLockUp[player] = 0;			// 上で即固定
	arsLockDown[player] = 1;		// 下で即固定
	arsRotReverse[player] = 0;		// 回転方向を逆転させる
	arsSoftSpeed[player] = 1;		// ソフトドロップの速度
	arsMaxWaitt[player] = 99;		// 最大横溜め
	arsFastlrmove[player] = 0;		// 先行横移動
	arsOBlkBG[player] = 0;			// ご先祖様登場中の背景
	arsInitRotate[player] = 1;		// 先行回転
	arsInitHold[player] = 1;		// 先行ホールド
	arsEnableKick[player] = 1;		// 壁蹴り有効
	arsSelfLockSound[player] = 0;	// 自分で固定させたときに音を出す
	arsLockflash[player] = 2;		// ブロックを固定させた瞬間、ブロックが光るフレーム数
	arsRepeatDelay[player] = 0;		// RepeatDelay
	
	// ブロックの色
	arsColor[player * 7 + 0] = 1;
	arsColor[player * 7 + 1] = 2;
	arsColor[player * 7 + 2] = 3;
	arsColor[player * 7 + 3] = 4;
	arsColor[player * 7 + 4] = 5;
	arsColor[player * 7 + 5] = 6;
	arsColor[player * 7 + 6] = 7;
	
	// プリセット番号
	arsLastPresetNo[player] = 0;
}

// プリセット初期化
void arsMakeDefaultPreset() {
	int i;
	
	for(i = 0; i < 30 * 5; i++) arsPreset[i] = 0;
	
	// プリセット1
	arsPreset[0 * 30 + 0] = 1;		// 赤の壁蹴り床蹴り
	arsPreset[0 * 30 + 1] = 0;		// 固定時間リセット
	arsPreset[0 * 30 + 2] = 0;		// 回転制限
	arsPreset[0 * 30 + 3] = 0;		// 移動制限
	arsPreset[0 * 30 + 4] = 1;		// グラフィック番号
	arsPreset[0 * 30 + 5] = 1;		// 出現待ち時間の有無
	arsPreset[0 * 30 + 6] = 0;		// 上で即固定
	arsPreset[0 * 30 + 7] = 1;		// 下で即固定
	arsPreset[0 * 30 + 8] = 0;		// 回転方向を逆転させる
	arsPreset[0 * 30 + 9] = 1;		// ソフトドロップの速度
	arsPreset[0 * 30 + 10] = 99;	// 最大横溜め
	arsPreset[0 * 30 + 11] = 0;		// 先行横移動
	arsPreset[0 * 30 + 12] = 0;		// ご先祖様登場中の背景
	for(i = 0; i < 7; i++) arsPreset[0 * 30 + (13 + i)] = i + 1;
	arsPreset[0 * 30 + 20] = 1;		// 先行回転
	arsPreset[0 * 30 + 21] = 1;		// 先行ホールド
	arsPreset[0 * 30 + 22] = 1;		// 壁蹴り有効
	arsPreset[0 * 30 + 23] = 0;		// 自分で固定させたときに音を出す
	arsPreset[0 * 30 + 24] = 2;		// ブロックを固定させた瞬間、ブロックが光るフレーム数
	arsPreset[0 * 30 + 25] = 0;		// RepeatDelay
	
	// プリセット2
	arsPreset[1 * 30 + 0] = 0;
	arsPreset[1 * 30 + 1] = 0;
	arsPreset[1 * 30 + 2] = 0;
	arsPreset[1 * 30 + 3] = 0;
	arsPreset[1 * 30 + 4] = 0;
	arsPreset[1 * 30 + 5] = 1;
	arsPreset[1 * 30 + 6] = 0;
	arsPreset[1 * 30 + 7] = 1;
	arsPreset[1 * 30 + 8] = 0;
	arsPreset[1 * 30 + 9] = 1;
	arsPreset[1 * 30 + 10] = 99;
	arsPreset[1 * 30 + 11] = 0;
	arsPreset[1 * 30 + 12] = 0;
	for(i = 0; i < 7; i++) arsPreset[1 * 30 + (13 + i)] = i + 1;
	arsPreset[1 * 30 + 20] = 1;
	arsPreset[1 * 30 + 21] = 1;
	arsPreset[1 * 30 + 22] = 1;
	arsPreset[1 * 30 + 23] = 0;
	arsPreset[1 * 30 + 24] = 2;
	arsPreset[1 * 30 + 25] = 0;
	
	// プリセット3
	arsPreset[2 * 30 + 0] = 1;
	arsPreset[2 * 30 + 1] = 1;
	arsPreset[2 * 30 + 2] = 128;
	arsPreset[2 * 30 + 3] = 128;
	arsPreset[2 * 30 + 4] = 1;
	arsPreset[2 * 30 + 5] = 1;
	arsPreset[2 * 30 + 6] = 1;
	arsPreset[2 * 30 + 7] = 0;
	arsPreset[2 * 30 + 8] = 0;
	arsPreset[2 * 30 + 9] = 0;
	arsPreset[2 * 30 + 10] = 99;
	arsPreset[2 * 30 + 11] = 0;
	arsPreset[2 * 30 + 12] = 0;
	arsPreset[2 * 30 + 13] = 5;
	arsPreset[2 * 30 + 14] = 2;
	arsPreset[2 * 30 + 15] = 3;
	arsPreset[2 * 30 + 16] = 1;
	arsPreset[2 * 30 + 17] = 7;
	arsPreset[2 * 30 + 18] = 6;
	arsPreset[2 * 30 + 19] = 4;
	arsPreset[2 * 30 + 20] = 1;
	arsPreset[2 * 30 + 21] = 1;
	arsPreset[2 * 30 + 22] = 1;
	arsPreset[2 * 30 + 23] = 1;
	arsPreset[2 * 30 + 24] = 2;
	arsPreset[2 * 30 + 25] = 0;
	
	// プリセット4
	arsPreset[3 * 30 + 0] = 1;
	arsPreset[3 * 30 + 1] = 1;
	arsPreset[3 * 30 + 2] = 128;
	arsPreset[3 * 30 + 3] = 128;
	arsPreset[3 * 30 + 4] = 1;
	arsPreset[3 * 30 + 5] = 1;
	arsPreset[3 * 30 + 6] = 0;
	arsPreset[3 * 30 + 7] = 1;
	arsPreset[3 * 30 + 8] = 0;
	arsPreset[3 * 30 + 9] = 0;
	arsPreset[3 * 30 + 10] = 99;
	arsPreset[3 * 30 + 11] = 0;
	arsPreset[3 * 30 + 12] = 0;
	arsPreset[3 * 30 + 13] = 5;
	arsPreset[3 * 30 + 14] = 2;
	arsPreset[3 * 30 + 15] = 3;
	arsPreset[3 * 30 + 16] = 1;
	arsPreset[3 * 30 + 17] = 7;
	arsPreset[3 * 30 + 18] = 6;
	arsPreset[3 * 30 + 19] = 4;
	arsPreset[3 * 30 + 20] = 1;
	arsPreset[3 * 30 + 21] = 1;
	arsPreset[3 * 30 + 22] = 1;
	arsPreset[3 * 30 + 23] = 1;
	arsPreset[3 * 30 + 24] = 2;
	arsPreset[3 * 30 + 25] = 0;
}

// プリセットを保存
void arsSavePreset(int player, int number) {
	int i;
	
	arsPreset[number * 30 + 0] = arsExtRotate[player];
	arsPreset[number * 30 + 1] = arsLockReset[player];
	arsPreset[number * 30 + 2] = arsRotLimit[player];
	arsPreset[number * 30 + 3] = arsMoveLimit[player];
	arsPreset[number * 30 + 4] = arsGraphics[player];
	arsPreset[number * 30 + 5] = arsAre[player];
	arsPreset[number * 30 + 6] = arsLockUp[player];
	arsPreset[number * 30 + 7] = arsLockDown[player];
	arsPreset[number * 30 + 8] = arsRotReverse[player];
	arsPreset[number * 30 + 9] = arsSoftSpeed[player];
	arsPreset[number * 30 + 10] = arsMaxWaitt[player];
	arsPreset[number * 30 + 11] = arsFastlrmove[player];
	arsPreset[number * 30 + 12] = arsOBlkBG[player];
	for(i = 0; i < 7; i++) arsPreset[number * 30 + (13 + i)] = arsColor[player * 7 + i];
	arsPreset[number * 30 + 20] = arsInitRotate[player];
	arsPreset[number * 30 + 21] = arsInitHold[player];
	arsPreset[number * 30 + 22] = arsEnableKick[player];
	arsPreset[number * 30 + 23] = arsSelfLockSound[player];
	arsPreset[number * 30 + 24] = arsLockflash[player];
	arsPreset[number * 30 + 25] = arsRepeatDelay[player];
}

// プリセットを読み込み
void arsLoadPreset(int player, int number) {
	int i;
	
	arsExtRotate[player] = arsPreset[number * 30 + 0];
	arsLockReset[player] = arsPreset[number * 30 + 1];
	arsRotLimit[player] = arsPreset[number * 30 + 2];
	arsMoveLimit[player] = arsPreset[number * 30 + 3];
	arsGraphics[player] = arsPreset[number * 30 + 4];
	arsAre[player] = arsPreset[number * 30 + 5];
	arsLockUp[player] = arsPreset[number * 30 + 6];
	arsLockDown[player] = arsPreset[number * 30 + 7];
	arsRotReverse[player] = arsPreset[number * 30 + 8];
	arsSoftSpeed[player] = arsPreset[number * 30 + 9];
	arsMaxWaitt[player] = arsPreset[number * 30 + 10];
	arsFastlrmove[player] = arsPreset[number * 30 + 11];
	arsOBlkBG[player] = arsPreset[number * 30 + 12];
	for(i = 0; i < 7; i++) arsColor[player * 7 + i] = arsPreset[number * 30 + (13 + i)];
	arsInitRotate[player] = arsPreset[number * 30 + 20];
	arsInitHold[player] = arsPreset[number * 30 + 21];
	arsEnableKick[player] = arsPreset[number * 30 + 22];
	arsSelfLockSound[player] = arsPreset[number * 30 + 23];
	arsLockflash[player] = arsPreset[number * 30 + 24];
	arsRepeatDelay[player] = arsPreset[number * 30 + 25];
}
