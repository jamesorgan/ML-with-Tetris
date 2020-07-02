// 最善手を探す（ホールドなし）
void cpu_setBestSpot(int player, int block) {
	cpu_hold[player] = 0;
	cpu_setBestSpot_normal(player, block);
	if(!cpu_best_p[player]) cpu_setBestSpot_recover(player, block);
	if(!cpu_best_p[player]) cpu_setBestSpot_compromise(player, block);
}

// 最善手を探す（ホールドあり）
void cpu_setBestSpotWithHold(int player, int block, int hblock) {
	int clv[2], bak[4];
	
	// 通常ブロック
	clv[0] = 0;
	cpu_setBestSpot_normal(player, block);
	
	if(!cpu_best_p[player]) {
		clv[0] = 1;
		cpu_setBestSpot_recover(player, block);
	}
	if(!cpu_best_p[player]) {
		clv[0] = 2;
		cpu_setBestSpot_compromise(player, block);
	}
	
	// 結果をバックアップ
	bak[0] = cpu_best_x[player];
	bak[1] = cpu_best_y[player];
	bak[2] = cpu_best_r[player];
	bak[3] = cpu_best_p[player];
	
	// ホールド
	clv[1] = 0;
	cpu_setBestSpot_normal(player, hblock);
	
	if(!cpu_best_p[player]) {
		clv[1] = 1;
		cpu_setBestSpot_recover(player, hblock);
	}
	if(!cpu_best_p[player]) {
		clv[1] = 2;
		cpu_setBestSpot_compromise(player, hblock);
	}
	
	if((clv[1] < clv[0]) || (cpu_best_p[player] > bak[3])) {
		// ホールドを採用
		cpu_hold[player] = 1;
	} else {
		// 通常ブロックを採用
		cpu_hold[player] = 0;
		cpu_best_x[player] = bak[0];
		cpu_best_y[player] = bak[1];
		cpu_best_r[player] = bak[2];
		cpu_best_p[player] = bak[3];
	}
}

// 思考ルーチン（ノーマル）
void cpu_setBestSpot_normal(int player, int block) {
	int i, j, rotate, bottom, point, hole, iblkneed, temp;
	
	cpu_best_x[player] = -3;
	cpu_best_y[player] = 0;
	cpu_best_r[player] = 0;
	cpu_best_p[player] = 0;
	
	for(rotate = 0; rotate < 4; rotate++)
		for(j = -2; j < fldsizex; j++) {
			// 得点を初期化
			point = 0;
			
			// フィールド準備
			cpu_copyField(player);
			
			// 底を調べる
			for(bottom = -2; cpu_judgeBlock(player, j, bottom, block, rotate) == 0; bottom++);
			bottom--;
			
			// ブロックを置けないなら却下
			if(cpu_judgeBlock(player, j, bottom, block, rotate) != 0) goto skip;
			
			// 左か右に壁があれば評価UP
			if(cpu_judgeBlock(player, j - 1, bottom, block, rotate) != 0) point = point + 1;
			if(cpu_judgeBlock(player, j + 1, bottom, block, rotate) != 0) point = point + 1;
			
			// 現在の隙間の数を数える
			hole = cpu_checkHowManyHoles();
			
			// 現在のヘボリス棒の穴の数を数える
			iblkneed = cpu_checkHowManyNeedIblock();
			
			// ブロックを置く
			if(cpu_setBlock(player, j, bottom, block, rotate)) goto skip;
			
			// 下に置くほど加点
			point = point + bottom;
			
			// ライン消去
			temp = cpu_doLineErase();
			if(temp == 1) {
				point = point - 1;
			} else {
				point = point + (temp * 10);
			}
			
			// 隙間の数に応じて点を変える
			temp = cpu_checkHowManyHoles();
			if(temp > hole) {
				// 新たに隙間ができるとNG
				goto skip;
			} else if(temp < hole) {
				// 新たに埋めた隙間の数で加点
				point = point + ((hole - temp) * 2);
			}
			
			// ヘボリス棒が必要な穴の数に応じて点をかえる
			temp = cpu_checkHowManyNeedIblock();
			
			if((iblkneed <= 1) && (temp >= 2)) {
				// 2つ以上新たにできると減点
				point = point - (temp - iblkneed);
			} else if(temp < iblkneed) {
				// 穴を減らすとボーナス
				point = point + ((iblkneed - temp) * 2);
			}
			
			// 最善手の場合
			if(point > cpu_best_p[player]) {
				cpu_best_x[player] = j;
				cpu_best_y[player] = bottom;
				cpu_best_r[player] = rotate;
				cpu_best_p[player] = point;
			}
			
			skip:
		}
}

// 思考ルーチン（妥協１）
void cpu_setBestSpot_recover(int player, int block) {
	int i, j, rotate, bottom, point, hole, iblkneed, temp;
	
	cpu_best_x[player] = -3;
	cpu_best_y[player] = 0;
	cpu_best_r[player] = 0;
	cpu_best_p[player] = 0;
	
	for(rotate = 0; rotate < 4; rotate++)
		for(j = -2; j < fldsizex; j++) {
			// 得点を初期化
			point = 0;
			
			// フィールド準備
			cpu_copyField(player);
			
			// 底を調べる
			for(bottom = -2; cpu_judgeBlock(player, j, bottom, block, rotate) == 0; bottom++);
			bottom--;
			
			// ブロックを置けないなら却下
			if(cpu_judgeBlock(player, j, bottom, block, rotate) != 0) goto skip;
			
			// 左か右に壁があれば評価UP
			if(cpu_judgeBlock(player, j - 1, bottom, block, rotate) != 0) point = point + 1;
			if(cpu_judgeBlock(player, j + 1, bottom, block, rotate) != 0) point = point + 1;
			
			// 現在の隙間の数を数える
			hole = cpu_checkHowManyHoles();
			
			// 現在のヘボリス棒の穴の数を数える
			iblkneed = cpu_checkHowManyNeedIblock();
			
			// ブロックを置く
			if(cpu_setBlock(player, j, bottom, block, rotate)) goto skip;
			
			// 下に置くほど加点
			point = point + bottom * 3;
			
			// ライン消去
			temp = cpu_doLineErase();
			point = point + (temp * 200);
			
			// 隙間の数に応じて点を変える
			temp = cpu_checkHowManyHoles();
			
			if(temp > hole) {
				// 新たに隙間ができると減点
				point = point - ((temp - hole) * 30);
			} else if(temp < hole) {
				// 新たに埋めた隙間の数で加点
				point = point + ((hole - temp) * 10);
			}
			
			// ヘボリス棒が必要な穴の数に応じて点をかえる
			temp = cpu_checkHowManyNeedIblock();
			
			if(temp > iblkneed) {
				// 新しい穴を作ると減点
				point = point - ((temp - iblkneed) * 30);
			} else if(temp < iblkneed) {
				// 穴を減らすとボーナス
				point = point + ((iblkneed - temp) * 10);
			}
			
			// 最善手の場合
			if(point > cpu_best_p[player]) {
				cpu_best_x[player] = j;
				cpu_best_y[player] = bottom;
				cpu_best_r[player] = rotate;
				cpu_best_p[player] = point;
			}
			
			skip:
		}
}

// 思考ルーチン（妥協２）
void cpu_setBestSpot_compromise(int player, int block) {
	int i, j, rotate, bottom, point, hole, iblkneed, temp;
	
	cpu_best_x[player] = -3;
	cpu_best_y[player] = 0;
	cpu_best_r[player] = 0;
	cpu_best_p[player] = 0;
	
	for(rotate = 0; rotate < 4; rotate++)
		for(j = -2; j < fldsizex; j++) {
			// 得点を初期化
			point = 0;
			
			// フィールド準備
			cpu_copyField(player);
			
			// 底を調べる
			for(bottom = -2; cpu_judgeBlock(player, j, bottom, block, rotate) == 0; bottom++);
			bottom--;
			
			// ブロックを置けないなら却下
			if(cpu_judgeBlock(player, j, bottom, block, rotate) != 0) goto skip;
			
			// 左か右に壁があれば評価UP
			if(cpu_judgeBlock(player, j - 1, bottom, block, rotate) != 0) point = point + 1;
			if(cpu_judgeBlock(player, j + 1, bottom, block, rotate) != 0) point = point + 1;
			
			// 現在の隙間の数を数える
			hole = cpu_checkHowManyHoles();
			
			// 現在のヘボリス棒の穴の数を数える
			iblkneed = cpu_checkHowManyNeedIblock();
			
			// ブロックを置く
			if(cpu_setBlock(player, j, bottom, block, rotate)) goto skip;
			
			// 下に置くほど加点
			point = point + bottom * 5;
			
			// ライン消去
			temp = cpu_doLineErase();
			point = point + (temp * 100);
			
			// 隙間の数に応じて点を変える
			temp = cpu_checkHowManyHoles();
			
			if(temp > hole) {
				// 新たに隙間ができると減点
				point = point - ((temp - hole) / 2);
			} else if(temp < hole) {
				// 新たに埋めた隙間の数で加点
				point = point + ((hole - temp) * 10);
			}
			
			// ヘボリス棒が必要な穴の数に応じて点をかえる
			temp = cpu_checkHowManyNeedIblock();
			
			if(temp < iblkneed) {
				// 穴を減らすとボーナス
				point = point + ((iblkneed - temp) * 5);
			}
			
			// 最善手の場合
			if(point > cpu_best_p[player]) {
				cpu_best_x[player] = j;
				cpu_best_y[player] = bottom;
				cpu_best_r[player] = rotate;
				cpu_best_p[player] = point;
			}
			
			skip:
		}
}

// 現実のフィールドを頭の中のフィールドにコピー
void cpu_copyField(int player) {
	int i, j;
	
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++)
			cpu_fld[j + i * fldsizex] = getFieldBlock(player, j, i);
}

// 頭の中のフィールドの状態を取得
int cpu_getFieldBlock(int x, int y) {
	if((x < 0) || (x >= fldsizex) || (y >= fldsizey)) return -1;
	if(y < 0) return -2;
	return cpu_fld[x + y * fldsizex];
}

// 頭の中のフィールドの状態を書き換える
void cpu_setFieldBlock(int player, int x, int y, int block) {
	if((x >= 0) && (x < fldsizex) && (y >= (spawntype[player] == 0)) && (y < fldsizey)) {
		cpu_fld[x + y * fldsizex] = block;
	}
}

// フィールドの最上段を返す
int cpu_checkFieldTop() {
	int i, j;
	
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++) 
			if(cpu_fld[j + i * fldsizex])
				return i;
	
	// 空っぽの場合
	return fldsizey;
}

// フィールドの最上段を返す（X座標を指定できるバージョン）
int cpu_checkFieldTopEx(int j) {
	int i;
	
	for(i = 0; i < fldsizey; i++)
		if(cpu_fld[j + i * fldsizex])
			return i;
	
	// 空っぽの場合
	return fldsizey;
}

// 隙間が空いてないか調べる
int cpu_checkHole(int bx1, int by1) {
	if( (by1 + 1 >= 0) && (by1 + 1 < fldsizey) && (cpu_fld[bx1 + (by1 + 1) * fldsizex] == 0) )
	{
		return 1;
	}
	
	return 0;
}

// フィールド中にどれぐらい隙間があるか調べる
int cpu_checkHowManyHoles() {
	int i, j, count;
	count = 0;
	
	for(j = 0; j < fldsizex; j++) {
		for(i = 0; i < fldsizey; i++) {
			if(cpu_fld[j + i * fldsizex] != 0) {
				count = count + cpu_checkHole(j, i);
			}
		}
	}
	
	return count;
}

// 何個のブロックがあるか調べる
int cpu_checkHowManyBlocks() {
	int i, j, count;
	count = 0;
	
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++) {
			if(cpu_fld[j + i * fldsizex] != 0) count++;
		}
	
	return count;
}

// 左から何個のブロックが並んでいるか調べる
int cpu_checkHowManyBlocksFromLeft() {
	int i, j, count;
	count = 0;
	
	for(i = 0; i < fldsizey; i++) {
		for(j = 0; j < fldsizex; j++) {
			if(cpu_fld[j + i * fldsizex] != 0)
				count++;
			else
				break;
		}
	}
	
	return count;
}

// ヘボリス棒が必要な穴がいくつあるのか調べる
// ■　■
// ■　■こんな状態なら必要と判断
// ■　■
int cpu_checkHowManyNeedIblock() {
	int i, j, count_left, count_right, total, by, by2;
	
	count_left = 0;
	count_right = 0;
	total = 0;
	
	for(j = 0; j < fldsizex; j++) {
		by = cpu_checkHoleStart(j);
		by2 = cpu_checkFieldTopEx(j);
		
		for(i = by; i < by2; i++) {
			// 左側にブロックがある（または端）
			if((j == 0) || (cpu_fld[(j - 1) + i * fldsizex] != 0))
				count_left++;
			
			// 右側にブロックがある
			if((j == 9) || (cpu_fld[(j + 1) + i * fldsizex] != 0))
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
int cpu_checkHoleStart(int x) {
	int i, top;
	top = cpu_checkFieldTopEx(x);
	
	for(i = 0; i < top; i++) {
		if( ((x == 0) || (cpu_fld[(x - 1) + i * fldsizex] != 0)) && 
		    ((x == 9) || (cpu_fld[(x + 1) + i * fldsizex] != 0)) )
		{
			return i;
		}
	}
	
	return top;
}

// 何ライン消えるか調べる
int cpu_checkLineErase() {
	int i, j, lines, full;
	
	lines = 0;
	
	for(i = 0; i < fldsizey; i++) {
		full = 1;
		
		for(j = 0; j < fldsizex; j++) {
			if(cpu_fld[j + i * fldsizex] == 0) {
				full = 0;
				break;
			}
		}
		
		lines = lines + full;
	}
	
	return lines;
}

// ライン消去
int cpu_doLineErase() {
	int i, j, k, l, y, lines, full;
	int eraseflag[22];
	
	lines = 0;
	
	// ラインを消す
	for(i = 0; i < fldsizey; i++) {
		eraseflag[i] = 1;
		
		for(j = 0; j < fldsizex; j++) {
			if(cpu_fld[j + i * fldsizex] == 0) {
				eraseflag[i] = 0;
				break;
			}
		}
		
		if(eraseflag[i]) {
			for(j = 0; j < fldsizex; j++) {
				cpu_fld[j + i * fldsizex] = 0;
			}
			lines++;
		}
	}
	
	// 上にあったブロックを下まで下ろす
	y = fldsizey - 1;
	
	for(i = 0; i < fldsizey; i++) {
		if(eraseflag[y]) {
			// ブロックを1段上からコピー
			for(k = y; k > 0; k--) {
				for(l = 0; l < fldsizex; l++) {
					cpu_fld[l + k * fldsizex] = cpu_fld[l + (k - 1) * fldsizex];
				}
				eraseflag[k] = eraseflag[(k - 1)];
			}
			
			// 一番上を空白にする
			for(l = 0; l < fldsizex; l++) {
				cpu_fld[l] = 0;
				eraseflag[0] = 0;
			}
		} else {
			y--;
		}
	}
	
	return lines;
}

// ブロックのあたり判定
int cpu_judgeBlock(int player, int bx1, int by1, int kind, int rotate) {
	int i, bx2, by2, temp;
	
	for(i = 0; i < 4; i++) {
		bx2 = bx1 + blkDataX[kind * 16 + rotate * 4 + player * 112 + i];
		by2 = by1 + blkDataY[kind * 16 + rotate * 4 + player * 112 + i];
		
		temp = cpu_getFieldBlock(player, bx2, by2);
		if((temp != 0) && (temp != -2)) return -1;
	}
	
	return 0;
}

// ブロックを設置する
int cpu_setBlock(int player, int bx1, int by1, int kind, int rotate) {
	int i, bx2, by2, puted;
	puted = 0;
	
	for(i = 0; i < 4; i++) {
		bx2 = bx1 + blkDataX[kind * 16 + rotate * 4 + player * 112 + i];
		by2 = by1 + blkDataY[kind * 16 + rotate * 4 + player * 112 + i];
		if(by2 >= 2) puted++;	// 枠内に置いた数＋１
		
		cpu_setFieldBlock(player, bx2, by2, 1);
	}
	
	if(!puted) return 1;
	
	return 0;
}

// 操作内容を決める
void cpu_setCtrl(int player) {
	// 動きを遅らせる
	cpu_frame[player]++;
	if(cpu_frame[player] < cpu_speed[player]) return;
	if(cpu_frame[player] >= cpu_speed[player] * 2) cpu_frame[player] = 0;
	
	// ホールド
	if(cpu_hold[player]) {
		cpu_ctrl[player * 10 + 7] = 1;
	}
	// 回転
	else if(rt[player] != cpu_best_r[player]) {
		cpu_ctrl[player * 10 + 4] = 1;
	}
	// 左移動
	else if(bx[player] > cpu_best_x[player]) {
		if((stat[player] == 4) && (judgeBlock(player, bx[player] - 1, by[player], blk[player], rt[player]) != 0)) {
			// 壁があるならあきらめる
			if(!up_flag[player]) cpu_ctrl[player * 10 + 0] = 1;
			if((!down_flag[player]) && (lock_down[player] != 0)) cpu_ctrl[player * 10 + 1] = 1;
		} else {
			if((cpu_speed[player] != 0) || (mpc[player] < 2)) cpu_ctrl[player * 10 + 2] = 1;
		}
	}
	// 右移動
	else if(bx[player] < cpu_best_x[player]) {
		if((stat[player] == 4) && (judgeBlock(player, bx[player] + 1, by[player], blk[player], rt[player]) != 0)) {
			// 壁があるならあきらめる
			if(!up_flag[player]) cpu_ctrl[player * 10 + 0] = 1;
			if((!down_flag[player]) && (lock_down[player] != 0)) cpu_ctrl[player * 10 + 1] = 1;
		} else {
			if((cpu_speed[player] != 0) || (mpc[player] < 2)) cpu_ctrl[player * 10 + 3] = 1;
		}
	}
	// 設置
	else {
		if(!up_flag[player]) cpu_ctrl[player * 10 + 0] = 1;
		if((!down_flag[player]) && (lock_down[player] != 0)) cpu_ctrl[player * 10 + 1] = 1;
	}
}
