//ワールドルール
//prefix:srs
//All kick tables based on "TGM-ACE SRS study" (http://www.the-shell.net/img/srs_study.html)

// ワールドルール ブロックデータ
int srsBlkDataX[7 * 4 * 4] =	// ユニットを構成するブロックの相対Ｘ位置(7種類/4角度/4ブロック)
{
	0, 1, 2, 3, 		2, 2, 2, 2, 		3, 2, 1, 0, 		1, 1, 1, 1, // I
	2, 2, 1, 0, 		2, 1, 1, 1, 		0, 0, 1, 2, 		0, 1, 1, 1, // L
	1, 2, 2, 1, 		2, 2, 1, 1, 		2, 1, 1, 2, 		1, 1, 2, 2, // O
	0, 1, 1, 2, 		2, 2, 1, 1, 		2, 1, 1, 0, 		0, 0, 1, 1, // Z
	1, 0, 1, 2, 		2, 1, 1, 1, 		1, 2, 1, 0, 		0, 1, 1, 1, // T
	0, 0, 1, 2, 		2, 1, 1, 1, 		2, 2, 1, 0, 		0, 1, 1, 1, // J
	2, 1, 1, 0, 		2, 2, 1, 1, 		0, 1, 1, 2, 		0, 0, 1, 1, // S
};

int srsBlkDataY[7 * 4 * 4] =	// ユニットを構成するブロックの相対Ｙ位置(7種類/4角度/4ブロック)
{
	1, 1, 1, 1, 		0, 1, 2, 3, 		2, 2, 2, 2, 		3, 2, 1, 0, // I
	0, 1, 1, 1, 		2, 2, 1, 0, 		2, 1, 1, 1, 		0, 0, 1, 2, // L
	0, 0, 1, 1, 		0, 1, 1, 0, 		1, 1, 0, 0, 		1, 0, 0, 1, // O
	0, 0, 1, 1, 		0, 1, 1, 2, 		2, 2, 1, 1, 		2, 1, 1, 0, // Z
	0, 1, 1, 1, 		1, 0, 1, 2, 		2, 1, 1, 1, 		1, 2, 1, 0, // T
	0, 1, 1, 1, 		0, 0, 1, 2, 		2, 1, 1, 1, 		2, 2, 1, 0, // J
	0, 0, 1, 1, 		2, 1, 1, 0, 		2, 2, 1, 1, 		0, 1, 1, 2, // S
};

// I以外のブロックの壁蹴りテーブル
int srsOtherBlockKickTable[4 * 4 * 2 * 2] = {
	// 左回転
	 1, 0,		 1, -1,		 0,  2,		 1,  2,		// 0>>3
	 1, 0,		 1,  1,		 0, -2,		 1, -2,		// 1>>0
	-1, 0,		-1, -1,		 0,  2,		-1,  2,		// 2>>1
	-1, 0,		-1,  1,		 0, -2,		-1, -2,		// 3>>2
	
	// 右回転
	-1, 0,		-1, -1,		 0,  2,		-1,  2,		// 0>>1
	 1, 0,		 1,  1,		 0, -2,		 1, -2,		// 1>>2
	 1, 0,		 1, -1,		 0,  2,		 1,  2,		// 2>>3
	-1, 0,		-1,  1,		 0, -2,		-1, -2		// 3>>0
};

// I型ブロックの壁蹴りテーブル
int srsIBlockKickTable[4 * 4 * 2 * 2] = {
	// 左回転
	 2, 0,		-1, 0,		-1, -2,		 2,  1,		// 0>>3
	 2, 0,		-1, 0,		 2, -1,		-1,  2,		// 1>>0
	-2, 0,		 1, 0,		-2, -1,		 1,  1,		// 2>>1
	 1, 0,		-2, 0,		 1, -2,		-2,  1,		// 3>>2
	
	// 右回転
	-2, 0,		 1, 0,		-2,  1,		 1, -2,		// 0>>1
	-1, 0,		 2, 0,		 2,  1,		-1, -2,		// 1>>2
	 2, 0,		-1, 0,		-1,  1,		 2, -1,		// 2>>3
	-2, 0,		 1, 0,		 1,  2,		-2, -1		// 3>>0
};

// 180度回転壁蹴りテーブル（I以外）
int srsOtherBlock180KickTable[11 * 2 * 4] = {
	 1, 0,   2, 0,   1, 1,   2, 1,  -1, 0,  -2, 0,  -1, 1,  -2, 1,   0,-1,   3, 0,  -3, 0,		// 0>>2─┐
	 0, 1,   0, 2,  -1, 1,  -1, 2,   0,-1,   0,-2,  -1,-1,  -1,-2,   1, 0,   0, 3,   0,-3,		// 1>>3─┼┐
	-1, 0,  -2, 0,  -1,-1,  -2,-1,   1, 0,   2, 0,   1,-1,   2,-1,   0, 1,  -3, 0,   3, 0,		// 2>>0─┘│
	 0, 1,   0, 2,   1, 1,   1, 2,   0,-1,   0,-2,   1,-1,   1,-2,  -1, 0,   0, 3,   0,-3		// 3>>1──┘
};

// 180度回転壁蹴りテーブル（I）
int srsIBlock180KickTable[11 * 2 * 4] = {
	 -1, 0,  -2, 0,   1, 0,   2, 0,   0, 1,    0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
	  0, 1,   0, 2,   0,-1,   0,-2,  -1, 0,    0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
	  1, 0,   2, 0,  -1, 0,  -2, 0,   0,-1,    0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
	  0, 1,   0, 2,   0,-1,   0,-2,   1, 0,    0,0, 0,0, 0,0, 0,0, 0,0, 0,0
};

// ブロック出現位置（通常）
int srsSpawnX[7]   = { 3, 3, 3, 3, 3, 3, 3};	// X座標
int srsSpawnYU[7]  = { 1, 2, 2, 2, 2, 2, 2};	// Y座標（枠内出現）
int srsSpawnYA[7]  = { 0, 0, 0, 0, 0, 0, 0};	// Y座標（枠外出現）
int srsNDelay[7]   = { 0, 1, 1, 1, 1, 1, 1};	// 枠外出現でNEXT遅延を解除するY座標

// ブロック出現位置（ビッグ）
int srsBSpawnX[7]  = { 1, 2, 1, 2, 2, 2, 2};	// X座標（1マス移動）
int srsBSpawnX2[7] = { 2, 2, 2, 2, 2, 2, 2};	// X座標（2マス移動）
int srsBSpawnYU[7] = { 0, 2, 2, 2, 2, 2, 2};	// Y座標（枠内出現）
int srsBSpawnYA[7] = {-1, 0, 0, 0, 0, 0, 0};	// Y座標（枠外出現）
int srsBNDelay[7]  = {-1, 1, 1, 1, 1, 1, 1};	// 枠外出現でNEXT遅延を解除するY座標

// ブロックの色と表示名
int srsColor[7 * 2];
str srsStrColor[8] = {"GRAY", "RED", "ORANGE", "YELLOW", "GREEN", "CYAN", "BLUE", "PURPLE"};

int srsRuleNumber = -1;		// ルール番号

int srsLockReset[2];		// 固定時間リセット
int srsRotLimit[2];			// 回転制限
int srsMoveLimit[2];		// 移動制限
int srsGraphics[2];			// グラフィック番号
int srsAre[2];				// 出現待ち時間の有無
int srsLockUp[2];			// 上で即固定
int srsLockDown[2];			// 下で即固定
int srsRotReverse[2];		// 回転方向を逆転させる
int srsSoftSpeed[2];		// ソフトドロップの速度
int srsMaxWaitt[2];			// 最大横溜め
int srsFastlrmove[2];		// 先行横移動
int srsOBlkBG[2];			// ご先祖様登場中の背景
int srsInitRotate[2];		// 先行回転
int srsInitHold[2];			// 先行ホールド
int srsEnableKick[2];		// 壁蹴り有効
int srsSelfLockSound[2];	// 自分で固定させたときに音を出す
int srsLockflash[2];		// ブロックを固定させた瞬間、ブロックが光るフレーム数
int srsRepeatDelay[2];		// RepeatDelay

int srsPreset[30 * 5];		// プリセット
int srsLastPresetNo[2];		// 最後に選択したプリセット番号

// イベント発生時に呼ばれる
void srsPluginEvent(int player, int event, int *param) {
	// ルールがSRSじゃなかったら戻る（ルールを登録するタイミング以外の場合）
	if((event != 0) && (rots[player] != srsRuleNumber)) return;
	
	if(event == 0) {
		srsRuleNumber = addRulePlugin("SRS");	// ルールを登録する
	} else if(event == 8) {
		srsBlockMove(player);	// ブロック移動中
	} else if(event == 9) {
		srsWallKick(player, param);	// 壁蹴り
	} else if(event == 16) {
		srsSetting(player, param);	// 設定画面
	} else if(event == 18) {
		srsPlayerInitial(player);	// ゲーム開始前の初期化
	} else if(event == 19) {
		srsBlockSpawn(player);	// ブロック出現時
	} else if(event == 54) {
		srsReplayDetail(param[0]);	// リプレイ詳細
	} else if(event == 58) {
		srsIsTSpin3Corner(player, param);	// 3-CORNERタイプのT-SPIN判定
	}
}

// ゲーム開始前の初期化
void srsPlayerInitial(int player) {
	int i;
	
	// ブロックデータをコピー
	for(i = 0; i < 112; i++) {
		blkDataX[player * 112 + i] = srsBlkDataX[i];
		blkDataY[player * 112 + i] = srsBlkDataY[i];
	}
	makeBlockLinkData(player); // ブロックの繋がりデータを自動生成
	
	// NEXTでの位置をずらす
	for(i = 0; i < 7; i++) next_offset[player * 7 + i] = 8;
	for(i = 1; i < 7; i++) next_s_offset[player * 7 + i] = 4;
	
	// 設定を反映させる
	lockreset[player] = srsLockReset[player];
	rotlimit[player] = srsRotLimit[player];
	movelimit[player] = srsMoveLimit[player];
	blockgraphics[player] = srsGraphics[player];
	are[player] = srsAre[player];
	lock_up[player] = srsLockUp[player];
	lock_down[player] = srsLockDown[player];
	rot_reverse[player] = srsRotReverse[player];
	softspeed[player] = srsSoftSpeed[player];
	max_waitt[player] = srsMaxWaitt[player];
	fastlrmove[player] = srsFastlrmove[player];
	oblk_bg[player] = srsOBlkBG[player];
	for(i = 0; i < 7; i++) blockcolor[player * 7 + i] = srsColor[player * 7 + i];
	initial_rotate[player] = srsInitRotate[player];
	initial_hold[player] = srsInitHold[player];
	enable_wallkick[player] = srsEnableKick[player];
	self_lock_sound[player] = srsSelfLockSound[player];
	lockflash[player] = srsLockflash[player];
	RepeatDelay[player] = srsRepeatDelay[player];
}

// 壁蹴り
void srsWallKick(int player, int *param) {
	int i, bak, move, sx[11], sy[11];
	bak = param[1];
	move = param[2];
	
	if(move == 2) {
		// 180度回転
		if(blk[player] != 0) {	// I以外の時
			for(i = 0; i < 11; i++) {
				sx[i] = srsOtherBlock180KickTable[(i * 2) + (rt[player] * 22) + 0];
				sy[i] = srsOtherBlock180KickTable[(i * 2) + (rt[player] * 22) + 1];
			}
		} else {				// Iの時
			for(i = 0; i < 11; i++) {
				sx[i] = srsIBlock180KickTable[(i * 2) + (rt[player] * 22) + 0];
				sy[i] = srsIBlock180KickTable[(i * 2) + (rt[player] * 22) + 1];
			}
		}
	} else {
		// 普通回転
		if(blk[player] != 0) {	// I以外の時
			for(i = 0; i < 4; i++) {
				sx[i] = srsOtherBlockKickTable[(i * 2) + (rt[player] * 8) + ((move > 0) * 32)];
				sy[i] = srsOtherBlockKickTable[(i * 2) + (rt[player] * 8) + ((move > 0) * 32) + 1];
			}
		} else {				// Iの時
			for(i = 0; i < 4; i++) {
				sx[i] = srsIBlockKickTable[(i * 2) + (rt[player] * 8) + ((move > 0) * 32)];
				sy[i] = srsIBlockKickTable[(i * 2) + (rt[player] * 8) + ((move > 0) * 32) + 1];
			}
		}
	}
	
	// BIGの場合は補正量2倍
	if(IsBig[player]) {
		for(i = 0; i < 4 + ((move == 2) * 7); i++) {
			sx[i] = sx[i] * 2;
			sy[i] = sy[i] * 2;
		}
	}
	
	// 壁蹴り実行
	for(i = 0; i < 4 + ((move == 2) * 7); i++) {
		if(judgeBlock(player, bx[player] + sx[i], by[player] + sy[i], blk[player], bak) == 0) {
			bx[player] = bx[player] + sx[i];
			by[player] = by[player] + sy[i];
			param[0] = 1;
			return;
		}
	}
}

// ブロック移動中
void srsBlockMove(int player) {
	int temp;
	
	// NEXT遅延を解除
	if(spawntype[player]) {
		if(!IsBig[player]) temp = srsNDelay[blk[player]];
		else temp = srsBNDelay[blk[player]];
		
		if(by[player] >= temp) ndelay[player] = 1;
	}
}

// ブロック出現時
void srsBlockSpawn(int player) {
	// 出現位置を設定
	if(!IsBig[player]) {
		// 非ビッグ
		block_init_x_pos[player] = srsSpawnX[blk[player]];
		
		if(!spawntype[player])
			block_init_y_pos[player] = srsSpawnYU[blk[player]];
		else
			block_init_y_pos[player] = srsSpawnYA[blk[player]];
	} else {
		// ビッグ
		if(!BigMove[player])
			block_init_x_pos[player] = srsBSpawnX[blk[player]];
		else
			block_init_x_pos[player] = srsBSpawnX2[blk[player]];
		
		if(!spawntype[player])
			block_init_y_pos[player] = srsBSpawnYU[blk[player]];
		else
			block_init_y_pos[player] = srsBSpawnYA[blk[player]];
	}
}

// 3-CORNERタイプのT-SPIN判定
void srsIsTSpin3Corner(int player, int *param) {
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
void srsSetting(int player, int *param) {
	int i, temp, cursor, move;
	cursor = 0;
	
	// 設定を読み込み
	if(srsLoadConfig(player) == 0) {
		srsMakeDefaultSetting(player);
		srsMakeDefaultPreset();
	}
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		sprintf(string[0], "%dP SRS OPTIONS", player + 1);
		printFontGrid(1, 1, string[0], 2 - player);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2,  3, "LOCK RESET",       7 * (cursor ==  0));
		printFontGrid(2,  4, "ROTATE LIMIT",     7 * (cursor ==  1));
		printFontGrid(2,  5, "MOVE LIMIT",       7 * (cursor ==  2));
		printFontGrid(2,  6, "BLOCK GRAPHICS",   7 * (cursor ==  3));
		printFontGrid(2,  7, "ARE",              7 * (cursor ==  4));
		printFontGrid(2,  8, "LOCK BY UP KEY",   7 * (cursor ==  5));
		printFontGrid(2,  9, "LOCK BY DOWN KEY", 7 * (cursor ==  6));
		printFontGrid(2, 10, "ROTATE REVERSE",   7 * (cursor ==  7));
		printFontGrid(2, 11, "SOFT DROP SPEED",  7 * (cursor ==  8));
		if(!english) printFontGrid(2, 12, "MAX YOKOTAME", 7 * (cursor == 9));
		else printFontGrid(2, 12, "MAX DAS", 7 * (cursor == 9));
		printFontGrid(2, 13, "INIT LR MOVE",     7 * (cursor == 10));
		printFontGrid(2, 14, "[] BACKGROUND",    7 * (cursor == 11));
		printFontGrid(2, 15, "I BLOCK COLOR",    7 * (cursor == 12));
		printFontGrid(2, 16, "L BLOCK COLOR",    7 * (cursor == 13));
		printFontGrid(2, 17, "O BLOCK COLOR",    7 * (cursor == 14));
		printFontGrid(2, 18, "Z BLOCK COLOR",    7 * (cursor == 15));
		printFontGrid(2, 19, "T BLOCK COLOR",    7 * (cursor == 16));
		printFontGrid(2, 20, "J BLOCK COLOR",    7 * (cursor == 17));
		printFontGrid(2, 21, "S BLOCK COLOR",    7 * (cursor == 18));
		printFontGrid(2, 22, "INITIAL ROTATE",   7 * (cursor == 19));
		printFontGrid(2, 23, "INITIAL HOLD",     7 * (cursor == 20));
		printFontGrid(2, 24, "ENABLE WALLKICK",  7 * (cursor == 21));
		printFontGrid(2, 25, "SELF LOCK SOUND",  7 * (cursor == 22));
		printFontGrid(2, 26, "LOCK FLASH",       7 * (cursor == 23));
		printFontGrid(2, 27, "REPEAT DELAY",     7 * (cursor == 24));
		printFontGrid(2, 28, "[SAVE PRESET]",    7 * (cursor == 25));
		printFontGrid(2, 29, "[LOAD PRESET]",    7 * (cursor == 26));
		
		// 設定値表示
		if(!srsLockReset[player]) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!srsRotLimit[player]) sprintf(string[0], "INFINITE");
		else sprintf(string[0], "%d", srsRotLimit[player]);
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!srsMoveLimit[player]) sprintf(string[0], "INFINITE");
		else sprintf(string[0], "%d", srsMoveLimit[player]);
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "%d", srsGraphics[player]);
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(srsAre[player] == 0) sprintf(string[0], "OFF");
		else if(srsAre[player] == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "ON (ENABLE SKIP)");
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		if(srsLockUp[player] == 0) sprintf(string[0], "OFF");
		else if(srsLockUp[player] == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "NO HARD DROP");
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		if(srsLockDown[player] == 0) sprintf(string[0], "OFF");
		else if(srsLockDown[player] == 1) sprintf(string[0], "ON");
		else if(srsLockDown[player] == 2) sprintf(string[0], "SLOW LOCK");
		else if(srsLockDown[player] == 3) sprintf(string[0], "FAST LOCK");
		else if(srsLockDown[player] == 4) sprintf(string[0], "1G OR FASTER");
		else if(srsLockDown[player] == 5) sprintf(string[0], "PUSH AGAIN TO LOCK");
		else sprintf(string[0], "NO SOFT DROP");
		printFontGrid(22, 9, string[0], 7 * (cursor == 6));
		
		if(srsRotReverse[player] == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 10, string[0], 7 * (cursor == 7));
		
		if(srsSoftSpeed[player] % 2 == 0) sprintf(string[0], "e %d.5", srsSoftSpeed[player] / 2);
		else sprintf(string[0], "e %d.0", (srsSoftSpeed[player] + 1) / 2);
		printFontGrid(22, 11, string[0], 7 * (cursor == 8));
		
		if(srsMaxWaitt[player] >= 99) sprintf(string[0], "INFINITE");
		else sprintf(string[0], "%d", srsMaxWaitt[player]);
		printFontGrid(22, 12, string[0], 7 * (cursor == 9));
		
		if(!srsFastlrmove[player]) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 13, string[0], 7 * (cursor == 10));
		
		if(srsOBlkBG[player] == 0) sprintf(string[0], "OFF");
		else if(srsOBlkBG[player] == 1) sprintf(string[0], "BLACK");
		else sprintf(string[0], "WHITE");
		printFontGrid(22, 14, string[0], 7 * (cursor == 11));
		
		for(i = 0; i < 7; i++) printFontGrid(22, 15 + i, srsStrColor[srsColor[player * 7 + i]], 7 * (cursor == 12 + i));
		
		if(!srsInitRotate[player]) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 22, string[0], 7 * (cursor == 19));
		
		if(!srsInitHold[player]) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 23, string[0], 7 * (cursor == 20));
		
		if(!srsEnableKick[player]) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 24, string[0], 7 * (cursor == 21));
		
		if(!srsSelfLockSound[player]) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 25, string[0], 7 * (cursor == 22));
		
		sprintf(string[0], "%d FRAMES", srsLockflash[player]);
		printFontGrid(22, 26, string[0], 7 * (cursor == 23));
		
		if(!srsRepeatDelay[player]) sprintf(string[0], "OFF");
		else sprintf(string[0], "%d", srsRepeatDelay[player]);
		printFontGrid(22, 27, string[0], 7 * (cursor == 24));
		
		sprintf(string[0], "PRESET NO.%d", srsLastPresetNo[player] + 1);
		printFontGrid(22, 28, string[0], 7 * (cursor >= 25));
		
		// カーソル移動
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 26;
			if(cursor > 26) cursor = 0;
		}
		
		// 値を変更
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) srsLockReset[player] = !srsLockReset[player];
			if(cursor == 1) {
				srsRotLimit[player] = srsRotLimit[player] + move;
				if(srsRotLimit[player] < 0) srsRotLimit[player] = 128;
				if(srsRotLimit[player] > 128) srsRotLimit[player] = 0;
			}
			if(cursor == 2) {
				srsMoveLimit[player] = srsMoveLimit[player] + move;
				if(srsMoveLimit[player] < 0) srsMoveLimit[player] = 128;
				if(srsMoveLimit[player] > 128) srsMoveLimit[player] = 0;
			}
			if(cursor == 3) {
				srsGraphics[player] = srsGraphics[player] + move;
				if(srsGraphics[player] < 0) srsGraphics[player] = 7;
				if(srsGraphics[player] > 7) srsGraphics[player] = 0;
			}
			if(cursor == 4) {
				srsAre[player] = srsAre[player] + move;
				if(srsAre[player] < 0) srsAre[player] = 2;
				if(srsAre[player] > 2) srsAre[player] = 0;
			}
			if(cursor == 5) {
				srsLockUp[player] = srsLockUp[player] + move;
				if(srsLockUp[player] < 0) srsLockUp[player] = 2;
				if(srsLockUp[player] > 2) srsLockUp[player] = 0;
			}
			if(cursor == 6) {
				srsLockDown[player] = srsLockDown[player] + move;
				if(srsLockDown[player] < 0) srsLockDown[player] = 6;
				if(srsLockDown[player] > 6) srsLockDown[player] = 0;
			}
			if(cursor == 7) srsRotReverse[player] = !srsRotReverse[player];
			if(cursor == 8) {
				srsSoftSpeed[player] = srsSoftSpeed[player] + move;
				if(srsSoftSpeed[player] < 0) srsSoftSpeed[player] = 39;
				if(srsSoftSpeed[player] > 39) srsSoftSpeed[player] = 0;
			}
			if(cursor == 9) {
				srsMaxWaitt[player] = srsMaxWaitt[player] + move;
				if(srsMaxWaitt[player] < 0) srsMaxWaitt[player] = 99;
				if(srsMaxWaitt[player] > 99) srsMaxWaitt[player] = 0;
			}
			if(cursor == 10) srsFastlrmove[player] = !srsFastlrmove[player];
			if(cursor == 11) {
				srsOBlkBG[player] = srsOBlkBG[player] + move;
				if(srsOBlkBG[player] < 0) srsOBlkBG[player] = 2;
				if(srsOBlkBG[player] > 2) srsOBlkBG[player] = 0;
			}
			if((cursor >= 12) && (cursor <= 18)) {
				temp = cursor - 12;
				srsColor[player * 7 + temp] = srsColor[player * 7 + temp] + move;
				if(srsColor[player * 7 + temp] < 0) srsColor[player * 7 + temp] = 7;
				if(srsColor[player * 7 + temp] > 7) srsColor[player * 7 + temp] = 0;
			}
			if(cursor == 19) srsInitRotate[player] = !srsInitRotate[player];
			if(cursor == 20) srsInitHold[player] = !srsInitHold[player];
			if(cursor == 21) srsEnableKick[player] = !srsEnableKick[player];
			if(cursor == 22) srsSelfLockSound[player] = !srsSelfLockSound[player];
			if(cursor == 23) {
				srsLockflash[player] = srsLockflash[player] + move;
				if(srsLockflash[player] < 0) srsLockflash[player] = 99;
				if(srsLockflash[player] > 99) srsLockflash[player] = 0;
			}
			if(cursor == 24) {
				srsRepeatDelay[player] = srsRepeatDelay[player] + move;
				if(srsRepeatDelay[player] < 0) srsRepeatDelay[player] = 99;
				if(srsRepeatDelay[player] > 99) srsRepeatDelay[player] = 0;
			}
			if(cursor >= 25) {
				srsLastPresetNo[player] = srsLastPresetNo[player] + move;
				if(srsLastPresetNo[player] < 0) srsLastPresetNo[player] = 4;
				if(srsLastPresetNo[player] > 4) srsLastPresetNo[player] = 0;
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
			
			if(cursor == 25) {
				srsSavePreset(player, srsLastPresetNo[player]);
				srsSaveConfig(player);
			} else if(cursor == 26) {
				srsLoadPreset(player, srsLastPresetNo[player]);
			} else {
				srsSaveConfig(player);
				return;
			}
		}
	}
}

// リプレイ詳細
void srsReplayDetail(int number) {
	int i;
	
	printFontGrid(1, 4, "LOCK RESET", 0);
	if(!saveBuf[208]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 4, string[0], 0);
	
	printFontGrid(1, 5, "ROTATE LIMIT", 0);
	if(!saveBuf[209]) sprintf(string[0], "INFINITE");
	else sprintf(string[0], "%d", saveBuf[209]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "MOVE LIMIT", 0);
	if(!saveBuf[210]) sprintf(string[0], "INFINITE");
	else sprintf(string[0], "%d", saveBuf[210]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "BLOCK GRAPHICS", 0);
	sprintf(string[0], "%d", saveBuf[211]);
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 8, "ARE", 0);
	if(saveBuf[212] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[212] == 1) sprintf(string[0], "ON");
	else sprintf(string[0], "ON (ENABLE SKIP)");
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "LOCK BY UP KEY", 0);
	if(saveBuf[213] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[213] == 1) sprintf(string[0], "ON");
	else sprintf(string[0], "NO HARD DROP");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "LOCK BY DOWN KEY", 0);
	if(saveBuf[214] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[214] == 1) sprintf(string[0], "ON");
	else if(saveBuf[214] == 2) sprintf(string[0], "SLOW LOCK");
	else if(saveBuf[214] == 3) sprintf(string[0], "FAST LOCK");
	else if(saveBuf[215] == 4) sprintf(string[0], "1G OR FASTER");
	else if(saveBuf[215] == 5) sprintf(string[0], "PUSH AGAIN TO LOCK");
	else sprintf(string[0], "NO SOFT DROP");
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "ROTATE REVERSE", 0);
	if(!saveBuf[215]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "SOFT DROP SPEED", 0);
	if(saveBuf[216] % 2 == 0) sprintf(string[0], "e %d.5", saveBuf[216] / 2);
	else sprintf(string[0], "e %d.0", (saveBuf[216] + 1) / 2);
	printFontGrid(22, 12, string[0], 0);
	
	if(!english) printFontGrid(1, 13, "MAX YOKOTAME", 0);
	else printFontGrid(1, 13, "MAX DAS", 0);
	if(saveBuf[217] >= 99) sprintf(string[0], "INFINITE");
	else sprintf(string[0], "%d", saveBuf[217]);
	printFontGrid(22, 13, string[0], 0);
	
	printFontGrid(1, 14, "INIT LR MOVE", 0);
	if(!saveBuf[218]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 14, string[0], 0);
	
	printFontGrid(1, 15, "[] BACKGROUND", 0);
	if(saveBuf[219] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[219] == 1) sprintf(string[0], "BLACK");
	else sprintf(string[0], "WHITE");
	printFontGrid(22, 15, string[0], 0);
	
	printFontGrid(1, 16, "BLOCK COLORS", 0);
	for(i = 0; i < 7; i++) {
		sprintf(string[0], "%d", saveBuf[222 + i]);
		printFontGrid(22 + i, 16, string[0], 0);
	}
	
	printFontGrid(1, 17, "INITIAL ROTATE", 0);
	if(!saveBuf[229]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 17, string[0], 0);
	
	printFontGrid(1, 18, "INITIAL HOLD", 0);
	if(!saveBuf[230]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 18, string[0], 0);
	
	printFontGrid(1, 19, "ENABLE WALLKICK", 0);
	if(!saveBuf[231]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 19, string[0], 0);
	
	printFontGrid(1, 20, "SELF LOCK SOUND", 0);
	if(!saveBuf[232]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 20, string[0], 0);
	
	printFontGrid(1, 21, "LOCK FLASH", 0);
	sprintf(string[0], "%d FRAMES", saveBuf[233]);
	printFontGrid(22, 21, string[0], 0);
	
	printFontGrid(1, 22, "REPEAT DELAY", 0);
	if(!saveBuf[244]) sprintf(string[0], "OFF");
	else sprintf(string[0], "%d", saveBuf[244]);
	printFontGrid(22, 22, string[0], 0);
}

// 設定を保存
void srsSaveConfig(int player) {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x43535253;
	saveBuf[3] = 0x32764746;
	
	// 設定内容
	saveBuf[4] = srsLockReset[player];
	saveBuf[5] = srsRotLimit[player];
	saveBuf[6] = srsMoveLimit[player];
	saveBuf[7] = srsGraphics[player];
	saveBuf[8] = srsAre[player];
	saveBuf[9] = srsLockUp[player];
	saveBuf[10] = srsLockDown[player];
	saveBuf[11] = srsRotReverse[player];
	saveBuf[12] = srsSoftSpeed[player];
	saveBuf[13] = srsMaxWaitt[player];
	saveBuf[14] = srsFastlrmove[player];
	saveBuf[15] = srsOBlkBG[player];
	for(i = 0; i < 7; i++) saveBuf[16 + i] = srsColor[player * 7 + i];
	saveBuf[23] = srsInitRotate[player];
	saveBuf[24] = srsInitHold[player];
	saveBuf[25] = srsEnableKick[player];
	saveBuf[26] = srsSelfLockSound[player];
	saveBuf[27] = srsLockflash[player];
	saveBuf[28] = srsRepeatDelay[player];
	
	saveBuf[49] = srsLastPresetNo[player];
	for(i = 0; i < 30 * 5; i++) saveBuf[50 + i] = srsPreset[i];
	
	if(!player) SaveFile("config/SRS_CONFIG.SAV", &saveBuf, 200 * 4);
	else SaveFile("config/SRS_CONFIG_2P.SAV", &saveBuf, 200 * 4);
}

// 設定を読み込み
int srsLoadConfig(int player) {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	if(!player) LoadFile("config/SRS_CONFIG.SAV", &saveBuf, 200 * 4);
	else LoadFile("config/SRS_CONFIG_2P.SAV", &saveBuf, 200 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x43535253) return 0;
	if(saveBuf[3] != 0x32764746) return 0;
	
	// 設定内容
	srsLockReset[player] = saveBuf[4];
	srsRotLimit[player] = saveBuf[5];
	srsMoveLimit[player] = saveBuf[6];
	srsGraphics[player] = saveBuf[7];
	srsAre[player] = saveBuf[8];
	srsLockUp[player] = saveBuf[9];
	srsLockDown[player] = saveBuf[10];
	srsRotReverse[player] = saveBuf[11];
	srsSoftSpeed[player] = saveBuf[12];
	srsMaxWaitt[player] = saveBuf[13];
	srsFastlrmove[player] = saveBuf[14];
	srsOBlkBG[player] = saveBuf[15];
	for(i = 0; i < 7; i++) srsColor[player * 7 + i] = saveBuf[16 + i];
	srsInitRotate[player] = saveBuf[23];
	srsInitHold[player] = saveBuf[24];
	srsEnableKick[player] = saveBuf[25];
	srsSelfLockSound[player] = saveBuf[26];
	srsLockflash[player] = saveBuf[27];
	srsRepeatDelay[player] = saveBuf[28];
	
	srsLastPresetNo[player] = saveBuf[49];
	for(i = 0; i < 30 * 5; i++) srsPreset[i] = saveBuf[50 + i];
	
	return 1;
}

// デフォルトの設定を作成
void srsMakeDefaultSetting(int player) {
	srsLockReset[player] = 1;		// 固定時間リセット
	srsRotLimit[player] = 8;		// 回転制限
	srsMoveLimit[player] = 10;		// 移動制限
	srsGraphics[player] = 2;		// グラフィック番号
	srsAre[player] = 1;				// 出現待ち時間の有無
	srsLockUp[player] = 1;			// 上で即固定
	srsLockDown[player] = 3;		// 下で即固定
	srsRotReverse[player] = 1;		// 回転方向を逆転させる
	srsSoftSpeed[player] = 1;		// ソフトドロップの速度
	srsMaxWaitt[player] = 99;		// 最大横溜め
	srsFastlrmove[player] = 0;		// 先行横移動
	srsOBlkBG[player] = 0;			// ご先祖様登場中の背景
	srsInitRotate[player] = 1;		// 先行回転
	srsInitHold[player] = 1;		// 先行ホールド
	srsEnableKick[player] = 1;		// 壁蹴り有効
	srsSelfLockSound[player] = 0;	// 自分で固定させたときに音を出す
	srsLockflash[player] = 2;		// ブロックを固定させた瞬間、ブロックが光るフレーム数
	srsRepeatDelay[player] = 0;		// RepeatDelay
	
	// ブロックの色
	srsColor[player * 7 + 0] = 5;
	srsColor[player * 7 + 1] = 2;
	srsColor[player * 7 + 2] = 3;
	srsColor[player * 7 + 3] = 1;
	srsColor[player * 7 + 4] = 7;
	srsColor[player * 7 + 5] = 6;
	srsColor[player * 7 + 6] = 4;
	
	// プリセット番号
	srsLastPresetNo[player] = 0;
}

// プリセット初期化
void srsMakeDefaultPreset() {
	int i;
	
	for(i = 0; i < 30 * 5; i++) srsPreset[i] = 0;
	
	// プリセット1
	srsPreset[0 * 30 + 0] = 1;		// 固定時間リセット
	srsPreset[0 * 30 + 1] = 8;		// 回転制限
	srsPreset[0 * 30 + 2] = 10;		// 移動制限
	srsPreset[0 * 30 + 3] = 2;		// グラフィック番号
	srsPreset[0 * 30 + 4] = 1;		// 出現待ち時間の有無
	srsPreset[0 * 30 + 5] = 1;		// 上で即固定
	srsPreset[0 * 30 + 6] = 3;		// 下で即固定
	srsPreset[0 * 30 + 7] = 1;		// 回転方向を逆転させる
	srsPreset[0 * 30 + 8] = 1;		// ソフトドロップの速度
	srsPreset[0 * 30 + 9] = 99;		// 最大横溜め
	srsPreset[0 * 30 + 10] = 0;		// 先行横移動
	srsPreset[0 * 30 + 11] = 0;		// ご先祖様登場中の背景
	srsPreset[0 * 30 + 12] = 5;		// Iの色
	srsPreset[0 * 30 + 13] = 2;		// Lの色
	srsPreset[0 * 30 + 14] = 3;		// Oの色
	srsPreset[0 * 30 + 15] = 1;		// Zの色
	srsPreset[0 * 30 + 16] = 7;		// Tの色
	srsPreset[0 * 30 + 17] = 6;		// Jの色
	srsPreset[0 * 30 + 18] = 4;		// Sの色
	srsPreset[0 * 30 + 19] = 1;		// 先行回転
	srsPreset[0 * 30 + 20] = 1;		// 先行ホールド
	srsPreset[0 * 30 + 21] = 1;		// 壁蹴り有効
	srsPreset[0 * 30 + 22] = 0;		// 自分で固定させたときに音を出す
	srsPreset[0 * 30 + 23] = 2;		// ブロックを固定させた瞬間、ブロックが光るフレーム数
	srsPreset[0 * 30 + 24] = 0;		// RepeatDelay
	
	// プリセット2
	srsPreset[1 * 30 + 0] = 1;
	srsPreset[1 * 30 + 1] = 128;
	srsPreset[1 * 30 + 2] = 128;
	srsPreset[1 * 30 + 3] = 2;
	srsPreset[1 * 30 + 4] = 1;
	srsPreset[1 * 30 + 5] = 1;
	srsPreset[1 * 30 + 6] = 0;
	srsPreset[1 * 30 + 7] = 1;
	srsPreset[1 * 30 + 8] = 0;
	srsPreset[1 * 30 + 9] = 99;
	srsPreset[1 * 30 + 10] = 0;
	srsPreset[1 * 30 + 11] = 0;
	srsPreset[1 * 30 + 12] = 5;
	srsPreset[1 * 30 + 13] = 2;
	srsPreset[1 * 30 + 14] = 3;
	srsPreset[1 * 30 + 15] = 1;
	srsPreset[1 * 30 + 16] = 7;
	srsPreset[1 * 30 + 17] = 6;
	srsPreset[1 * 30 + 18] = 4;
	srsPreset[1 * 30 + 19] = 1;
	srsPreset[1 * 30 + 20] = 1;
	srsPreset[1 * 30 + 21] = 1;
	srsPreset[1 * 30 + 22] = 1;
	srsPreset[1 * 30 + 23] = 2;
	srsPreset[1 * 30 + 24] = 0;
	
	// プリセット3
	srsPreset[2 * 30 + 0] = 1;
	srsPreset[2 * 30 + 1] = 0;
	srsPreset[2 * 30 + 2] = 0;
	srsPreset[2 * 30 + 3] = 3;
	srsPreset[2 * 30 + 4] = 0;
	srsPreset[2 * 30 + 5] = 1;
	srsPreset[2 * 30 + 6] = 5;
	srsPreset[2 * 30 + 7] = 1;
	srsPreset[2 * 30 + 8] = 0;
	srsPreset[2 * 30 + 9] = 10;
	srsPreset[2 * 30 + 10] = 1;
	srsPreset[2 * 30 + 11] = 2;
	srsPreset[2 * 30 + 12] = 5;
	srsPreset[2 * 30 + 13] = 2;
	srsPreset[2 * 30 + 14] = 3;
	srsPreset[2 * 30 + 15] = 1;
	srsPreset[2 * 30 + 16] = 7;
	srsPreset[2 * 30 + 17] = 6;
	srsPreset[2 * 30 + 18] = 4;
	srsPreset[2 * 30 + 19] = 0;
	srsPreset[2 * 30 + 20] = 1;
	srsPreset[2 * 30 + 21] = 1;
	srsPreset[2 * 30 + 22] = 1;
	srsPreset[2 * 30 + 23] = 0;
	srsPreset[2 * 30 + 24] = 5;
	
	// プリセット4
	srsPreset[3 * 30 + 0] = 1;
	srsPreset[3 * 30 + 1] = 12;
	srsPreset[3 * 30 + 2] = 24;
	srsPreset[3 * 30 + 3] = 4;
	srsPreset[3 * 30 + 4] = 1;
	srsPreset[3 * 30 + 5] = 0;
	srsPreset[3 * 30 + 6] = 1;
	srsPreset[3 * 30 + 7] = 1;
	srsPreset[3 * 30 + 8] = 2;
	srsPreset[3 * 30 + 9] = 99;
	srsPreset[3 * 30 + 10] = 0;
	srsPreset[3 * 30 + 11] = 0;
	srsPreset[3 * 30 + 12] = 5;
	srsPreset[3 * 30 + 13] = 2;
	srsPreset[3 * 30 + 14] = 3;
	srsPreset[3 * 30 + 15] = 1;
	srsPreset[3 * 30 + 16] = 7;
	srsPreset[3 * 30 + 17] = 6;
	srsPreset[3 * 30 + 18] = 4;
	srsPreset[3 * 30 + 19] = 1;
	srsPreset[3 * 30 + 20] = 1;
	srsPreset[3 * 30 + 21] = 1;
	srsPreset[3 * 30 + 22] = 0;
	srsPreset[3 * 30 + 23] = 2;
	srsPreset[3 * 30 + 24] = 0;
}

// プリセットを保存
void srsSavePreset(int player, int number) {
	int i;
	
	srsPreset[number * 30 + 0] = srsLockReset[player];
	srsPreset[number * 30 + 1] = srsRotLimit[player];
	srsPreset[number * 30 + 2] = srsMoveLimit[player];
	srsPreset[number * 30 + 3] = srsGraphics[player];
	srsPreset[number * 30 + 4] = srsAre[player];
	srsPreset[number * 30 + 5] = srsLockUp[player];
	srsPreset[number * 30 + 6] = srsLockDown[player];
	srsPreset[number * 30 + 7] = srsRotReverse[player];
	srsPreset[number * 30 + 8] = srsSoftSpeed[player];
	srsPreset[number * 30 + 9] = srsMaxWaitt[player];
	srsPreset[number * 30 + 10] = srsFastlrmove[player];
	srsPreset[number * 30 + 11] = srsOBlkBG[player];
	for(i = 0; i < 7; i++) srsPreset[number * 30 + (12 + i)] = srsColor[player * 7 + i];
	srsPreset[number * 30 + 19] = srsInitRotate[player];
	srsPreset[number * 30 + 20] = srsInitHold[player];
	srsPreset[number * 30 + 21] = srsEnableKick[player];
	srsPreset[number * 30 + 22] = srsSelfLockSound[player];
	srsPreset[number * 30 + 23] = srsLockflash[player];
	srsPreset[number * 30 + 24] = srsRepeatDelay[player];
}

// プリセットを読み込み
void srsLoadPreset(int player, int number) {
	int i;
	
	srsLockReset[player] = srsPreset[number * 30 + 0];
	srsRotLimit[player] = srsPreset[number * 30 + 1];
	srsMoveLimit[player] = srsPreset[number * 30 + 2];
	srsGraphics[player] = srsPreset[number * 30 + 3];
	srsAre[player] = srsPreset[number * 30 + 4];
	srsLockUp[player] = srsPreset[number * 30 + 5];
	srsLockDown[player] = srsPreset[number * 30 + 6];
	srsRotReverse[player] = srsPreset[number * 30 + 7];
	srsSoftSpeed[player] = srsPreset[number * 30 + 8];
	srsMaxWaitt[player] = srsPreset[number * 30 + 9];
	srsFastlrmove[player] = srsPreset[number * 30 + 10];
	srsOBlkBG[player] = srsPreset[number * 30 + 11];
	for(i = 0; i < 7; i++) srsColor[player * 7 + i] = srsPreset[number * 30 + (12 + i)];
	srsInitRotate[player] = srsPreset[number * 30 + 19];
	srsInitHold[player] = srsPreset[number * 30 + 20];
	srsEnableKick[player] = srsPreset[number * 30 + 21];
	srsSelfLockSound[player] = srsPreset[number * 30 + 22];
	srsLockflash[player] = srsPreset[number * 30 + 23];
	srsRepeatDelay[player] = srsPreset[number * 30 + 24];
}
