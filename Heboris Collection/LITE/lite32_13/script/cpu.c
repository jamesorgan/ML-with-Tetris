//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   最善手を探す
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// player：プレイヤー番号
// block ：操作するブロック
// mode  ：妥協レベル
// block2：次のブロック
// navi　：ナビゲーション用かどうか
void cpu_setBestSpot(int player, int block, int mode, int block2, int navi) {
	int i, j, rotate;
	int bottom;
	int point;
	int bx2, by2;
	int tmp;
	int data[2];
	int maxrot;
	
	if(!mode) {
		cpu_best_x[player] = -3;
		cpu_best_y[player] = 0;
		cpu_best_r[player] = 0;
		cpu_best_p[player] = 0;
		cpu_hold[player] = 0;
	}
	
	// フィーバー中は棒のみ
	if(isfever[player]) {
		block = 0;
		block2 = 0;
	}
	
	maxrot = 2;
	if(isRotateLock[player]) maxrot = 1;
	if(block == 2) maxrot = 1;
	if((block == 1) || (block == 4) || (block == 5)) maxrot = 4;
	
	for(rotate = 0; rotate < maxrot; rotate++)
		for(j = -2; j < 10; j++) {
			// 底を調べる
			for(bottom = -2; judgeBlock(player, j, bottom, block, rotate) == 0; bottom++);
			bottom--;
			
			point = 0;
			
			if(judgeBlock(player, j, bottom, block, rotate) == 0) {
				// 左か右に壁があれば評価UP
				if(judgeBlock(player, j - 1, bottom, block, rotate) != 0) point++;
				if(judgeBlock(player, j + 1, bottom, block, rotate) != 0) point++;
				
				// ブロックを一時的にフィールドに置く
				cpu_setBlock(player, j, bottom, block, rotate);
				
				for(i = 0; i < 4; i++) {
					getBlockData(player, j, bottom, block, rotate, i, &data);
					bx2 = data[0];
					by2 = data[1];
					
					// 穴が空いてしまう場合はNG
					if(cpu_checkHole(player, bx2, by2)) {
						if(mode != 1) {
							point = 0;
							break;
						} else {
							point = point - 5;
						}
					}
					
					// 左から何個のブロックが並んでいるか調べる
					point = point + cpu_checkHowManyBlocksFromLeft(player, by2);
					
					// 全体で何個のブロックがあるか調べる
					point = point + cpu_checkHowManyBlocks(player, by2);
				}
				
				// 棒が必要な穴の数が2つ以上あると減点
				tmp = cpu_HowManyNeedIblock(player);
				
				if(tmp >= 2) {
					point = point - tmp * 10;
				}
				
				// 消えるライン数を調べる
				tmp = cpu_checkLineErase(player);
				
				if((tmp >= 2) || (mode == 1) || (pinch[player])) {
					point = point + (tmp * 10) + ((mode == 1) * 10);	// ボーナス
				}
				
				// ブロックを消す
				cpu_removeBlock(player, j, bottom, block, rotate);
				
				// 最善手の場合
				if(point > cpu_best_p[player]) {
					cpu_best_x[player] = j;
					cpu_best_y[player] = bottom;
					cpu_best_r[player] = rotate;
					cpu_best_p[player] = point;
					if(mode == 2) cpu_hold[player] = 1;
				}
			}
		}
	
	if(!navi) {
		if(!mode && !cpu_hold[player] && !dhold[player] && !disable_hold && !isholdlock[player]) {
			// HOLDするとどうなるかを考える
			if(hold[player] == -1)
				cpu_setBestSpot(player, block2, 2, 0, navi);
			else
				cpu_setBestSpot(player, hold[player], 2, 0, navi);
		} else if((!cpu_best_p[player]) && (!mode) && (!cpu_hold[player])) {
			// 妥協
			cpu_setBestSpot(player, block, 1, block2, navi);
		}
	}
}

// 穴が空いてないか調べる
int cpu_checkHole(int player, int bx1, int by1) {
	if( ((by1 + 1 >= 0) && (by1 + 1 < 22) && (fld[bx1 + (by1 + 1) * 10 + player * 220] == 0)) ||
		((by1 + 2 >= 0) && (by1 + 2 < 22) && (fld[bx1 + (by1 + 2) * 10 + player * 220] == 0)) )
	{
		return -1;
	}
	
	return 0;
}

// 何個のブロックが並んでいるか調べる
int cpu_checkHowManyBlocks(int player, int by1) {
	int j, count;
	count = 0;
	
	if((by1 >= 0) && (by1 < 22)) {
		for(j = 0; j < 10; j++) {
			if(fld[j + by1 * 10 + player * 220] != 0)
				count++;
		}
	}
	
	return count;
}

// 左から何個のブロックが並んでいるか調べる
int cpu_checkHowManyBlocksFromLeft(int player, int by1) {
	int j, count;
	count = 0;
	
	if((by1 >= 0) && (by1 < 22)) {
		for(j = 0; j < 10; j++) {
			if(fld[j + by1 * 10 + player * 220] != 0)
				count++;
			else
				break;
		}
	}
	
	return count;
}

// 何ライン消えるか調べる
int cpu_checkLineErase(int player) {
	int i, j, lines, full;
	
	lines = 0;
	
	for(i = 0; i < 22; i++) {
		full = 1;
		
		for(j = 0; j < 10; j++) {
			if(fld[j + i * 10 + player * 220] == 0) {
				full = 0;
				break;
			}
		}
		
		lines = lines + full;
	}
	
	return lines;
}

// ヘボリス棒が必要な穴がいくつあるのか調べる
// ■　■
// ■　■こんな状態なら必要と判断
// ■　■
int cpu_HowManyNeedIblock(int player) {
	int i, j, count_left, count_right, total, by, by2;
	
	count_left = 0;
	count_right = 0;
	total = 0;
	
	for(j = 0; j < 10; j++) {
		by = cpu_checkHoleStart(player, j);
		by2 = checkFieldTopEx(player, j);
		
		for(i = by; i < by2; i++) {
			// 左側にブロックがある（または端）
			if((j == 0) || (fld[(j - 1) + i * 10 + player * 220] != 0))
				count_left++;
			
			// 右側にブロックがある
			if((j == 9) || (fld[(j + 1) + i * 10 + player * 220] != 0))
				count_right++;
		}
		
		if((count_left >= 3) || (count_right >= 3)) total++;	// 棒が要ると判断
		count_left = 0;
		count_right = 0;
	}
	
	return total;
}

// 穴が始まる位置を探す
// ■　■
int cpu_checkHoleStart(int player, int x) {
	int i, top;
	top = checkFieldTopEx(player, x);
	
	for(i = 0; i < top; i++) {
		if( ((x == 0) || (fld[(x - 1) + i * 10 + player * 220] != 0)) && 
		    ((x == 9) || (fld[(x + 1) + i * 10 + player * 220] != 0)) )
		{
			return i;
		}
	}
	
	return top;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   操作内容を決める
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void cpu_setCtrl(int player) {
	int i, tmp;
	
	// 1フレームに2回以上操作するのを防ぐ
	if((time2[player] == cpu_frame[player]) && (repversw >= 4)) {
		return;
	} else {
		cpu_frame[player] = time2[player];
	}
	
	for(i = 0; i < 10; i++) cpu_ctrl[i + player * 10] = 0;
	
	if(stat[player] == 5) tmp = bx[player];
	else tmp = 2 + IsBig[player];
	
	// レベル4以下は動きを遅らせる
	if(tmp != cpu_best_x[player]) {
		if((cpu_level[player] == 0) && (time2[player] % 10 != 0)) return;
		if((cpu_level[player] == 1) && (time2[player] %  8 != 0)) return;
		if((cpu_level[player] == 2) && (time2[player] %  5 != 0)) return;
		if((cpu_level[player] == 3) && (time2[player] %  2 != 0)) return;
	}
	
	if((rt[player] != cpu_best_r[player]) && (!isRotateLock[player]) && (cpu_level[player] >= 4)) {
		// レベル5の回転
		cpu_ctrl[4 + player * 10] = 1;
	}
	
	if((cpu_best_x[player] == -3) || (cpu_hold[player])) {
		// いい手がないならHOLD
		if((!dhold[player]) && (!disable_hold) && (!isholdlock[player])) {
			cpu_ctrl[7 + player * 10] = 1;
		} else {
			cpu_best_x[player] = bx[player];
		}
	} else if((rt[player] != cpu_best_r[player]) && (!isRotateLock[player]) && (cpu_level[player] <= 3)) {
		// レベル4までの回転
		cpu_ctrl[4 + player * 10] = 1;
	} else if(tmp > cpu_best_x[player]) {
		// ←
		cpu_ctrl[2 + player * 10] = 1;
		
		if( ((dhold[player]) || (rule_are[rots[player]] != 1)) && (mpc[player] >= 2) )
			cpu_ctrl[2 + player * 10] = 0;
		
		// 壁がある
		if((stat[player] == 5) && (judgeBlock(player, bx[player] - 1, by[player], blk[player], rt[player]) != 0)) {
			cpu_ctrl[2 + player * 10] = 0;
			cpu_ctrl[0 + player * 10] = 1;
			if(!rule_hard_lock[rots[player]]) cpu_ctrl[1 + player * 10] = 1;
		}
	} else if(tmp < cpu_best_x[player]) {
		// →
		cpu_ctrl[3 + player * 10] = 1;
		
		if( ((dhold[player]) || (rule_are[rots[player]] != 1)) && (mpc[player] >= 2) )
			cpu_ctrl[3 + player * 10] = 0;
		
		// 壁がある
		if((stat[player] == 5) && (judgeBlock(player, bx[player] + 1, by[player], blk[player], rt[player]) != 0)) {
			cpu_ctrl[3 + player * 10] = 0;
			cpu_ctrl[0 + player * 10] = 1;
			if(!rule_hard_lock[rots[player]]) cpu_ctrl[1 + player * 10] = 1;
		}
	} else if( ((rt[player] == cpu_best_r[player]) || (isRotateLock[player])) && (!up_flag[player]) ) {
		// 設置
		cpu_ctrl[0 + player * 10] = 1;
		if(!rule_hard_lock[rots[player]]) cpu_ctrl[1 + player * 10] = 1;
	}
	
	if(!replayauto) {
		// 左右操作反転
		if(isLRreverse[player] || isUDLRreverse[player]) {
			tmp = cpu_ctrl[2 + player * 10];
			cpu_ctrl[2 + player * 10] = cpu_ctrl[3 + player * 10];
			cpu_ctrl[3 + player * 10] = tmp;
		}
		
		// 上下操作反転
		if(isUDreverse[player] || isUDLRreverse[player]) {
			tmp = cpu_ctrl[0 + player * 10];
			cpu_ctrl[0 + player * 10] = cpu_ctrl[1 + player * 10];
			cpu_ctrl[1 + player * 10] = tmp;
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ブロックを設置する
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void cpu_setBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	int		data[2];
	
	// BIGの場合は専用処理
	if(IsBig[player]) {
		cpu_setBigBlock(player, bx1, by1, kind, rotate);
		return;
	}
	
	for(i = 0; i < 4; i++) {
		getBlockData(player, bx1, by1, kind, rotate, i, &data);
		bx2 = data[0];
		by2 = data[1];
		
		if( ( bx2 >= 0 ) && ( bx2 <= 9 ) && ( by2 >= 0 ) && ( by2 < 22 ) ) {
			fld[bx2 + by2 * 10 + player * 220] = 1;
		}
	}
}

// BIG用
void cpu_setBigBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	int		k, l, bx3, by3;
	int		data[2];
	
	for(i = 0; i < 4; i++) {
		getBlockData(player, 0, 0, kind, rotate, i, &data);
		bx2 = bx1 + (data[0] * 2);
		by2 = by1 + (data[1] * 2);
		
		/* 4ブロック分設置する */
		for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
			bx3 = bx2 + k;
			by3 = by2 + l;
			
			if( ( bx3 >= 0 ) && ( bx3 <= 9 ) && ( by3 >= 0 ) && ( by3 < 22 ) ) {
				fld[bx3 + by3 * 10 + player * 220] = 1;
			}
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ブロックを消去する
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void cpu_removeBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	int		data[2];
	
	// BIGの場合は専用処理
	if(IsBig[player]) {
		cpu_removeBigBlock(player, bx1, by1, kind, rotate);
		return;
	}
	
	for(i = 0; i < 4; i++) {
		getBlockData(player, bx1, by1, kind, rotate, i, &data);
		bx2 = data[0];
		by2 = data[1];
		
		if( ( bx2 >= 0 ) && ( bx2 <= 9 ) && ( by2 >= 0 ) && ( by2 < 22 ) ) {
			fld[bx2 + by2 * 10 + player * 220] = 0;
		}
	}
}

// BIG用
void cpu_removeBigBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	int		k, l, bx3, by3;
	int		data[2];
	
	for(i = 0; i < 4; i++) {
		getBlockData(player, 0, 0, kind, rotate, i, &data);
		bx2 = bx1 + (data[0] * 2);
		by2 = by1 + (data[1] * 2);
		
		/* 4ブロック分消す */
		for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
			bx3 = bx2 + k;
			by3 = by2 + l;
			
			if( ( bx3 >= 0 ) && ( bx3 <= 9 ) && ( by3 >= 0 ) && ( by3 < 22 ) ) {
				fld[bx3 + by3 * 10 + player * 220] = 0;
			}
		}
	}
}
