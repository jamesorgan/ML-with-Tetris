//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.04 - ブロック移動中
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statMove(int player) {
	int param, temp;
	
	param = 0;
	executePlugin(player, 6, &param);	// プラグイン呼び出し
	if(param) return;
	
	hiddenProc(player);
	
	// 上入れ制限＆下入れ制限解除
	if( !getPressState(player, 0) || (!downtype) || ((downtype == 1) && (!is20G(player)) && (are[player] != 0)) )
		up_flag[player] = 0;
	if( !getPressState(player, 1) || (!downtype) || ((downtype == 1) && (!is20G(player)) && (are[player] != 0)) )
		down_flag[player] = 0;
	
	if(!statc[player * 10 + 1]) {
		// ホールド
		if(!statc[player * 10 + 0]) {
			temp = getPressState(player, 7) * initial_hold[player];
		} else {
			temp = getPushState(player, 7);
		}
		
		if(temp && !dhold[player]) {
			if((!statc[player * 10 + 0] && !hold_sound) || (hold_sound == 1)) PlaySE(se_hold);
			if(subMoveInit(player, 1)) return;
			statc[player * 10 + 0] = 0;
		}
		// ホールド無しの最初のフレーム
		else if(!statc[player * 10 + 0]) {
			if(subMoveInit(player, 0)) return;
		}
		
		// ブロック移動処理
		subMoveMain(player);
		
		// 固定した瞬間の処理
		if( ((lockflash[player] == 0) || (engineVer >= 12)) && (statc[player * 10 + 1] != 0) ) subMoveLock(player);
	} else {
		// 固定した瞬間の処理
		subMoveLock(player);
	}
}

// 最初の1フレーム／ホールド時に行われる処理
// ブロックがめり込んでいる場合は戻り値が1になる
int subMoveInit(int player, int ishold) {
	int i, temp;
	int param[2];
	
	param[0] = 0;
	param[1] = ishold;
	executePlugin(player, 7, &param);	// プラグイン呼び出し
	if(param[0]) return param[0] - 1;
	
	// 通常／初回ホールド
	if((!ishold) || (hold[player] == -1)) {
		// ホールドブロックを設定
		if(ishold) {
			if(!statc[player * 10 + 0]) {
				// 先行ホールド
				hold[player] = getNextBlock(player, 0);
				for(i = 0; i < 4; i++) hold_color[i + player * 4] = next_color[player * 24 + i];
				hold_oblk[player] = next_oblk[player * 6];
				if(enable_item_hold[player]) hold_item[player] = next_item[player * 6];
				else hold_item[player] = 0;
				nextc[player] = (nextc[player] + 1) % nextc_max[player];
				setNextBlockColor(player, 0);
			} else {
				// 通常ホールド
				hold[player] = blk[player];
				for(i = 0; i < 4; i++) hold_color[i + player * 4] = current_color[i + player * 4];
				hold_oblk[player] = current_oblk[player];
				if(enable_item_hold[player]) hold_item[player] = current_item[player];
				else hold_item[player] = 0;
			}
			hold_count[player]++;
			dhold[player] = 1;
		}
		
		// 現在のブロックを設定
		blk[player] = getNextBlock(player, 0);
		for(i = 0; i < 4; i++) {
			current_color[i + player * 4] = next_color[player * 24 + i];
			current_color_m[i + player * 4] = next_color[player * 24 + i];
		}
		current_oblk[player] = next_oblk[player * 6];
		current_item[player] = next_item[player * 6];
		
		// NEXTを動かす
		nextc[player] = (nextc[player] + 1) % nextc_max[player];
		setNextBlockColor(player, 0);
	}
	// ホールド2回目以降
	else {
		if(!statc[player * 10 + 0]) {
			// 先行ホールド
			temp = hold[player];
			hold[player] = getNextBlock(player, 0);
			blk[player] = temp;
			
			for(i = 0; i < 4; i++) {
				temp = hold_color[i + player * 4];
				hold_color[i + player * 4] = next_color[player * 24 + i];
				current_color[i + player * 4] = temp;
				current_color_m[i + player * 4] = temp;
			}
			
			temp = hold_oblk[player];
			hold_oblk[player] = next_oblk[player * 6];
			current_oblk[player] = temp;
			
			if(enable_item_hold[player]) {
				temp = hold_item[player];
				hold_item[player] = next_item[player * 6];
				current_item[player] = temp;
			} else {
				hold_item[player] = 0;
				current_item[player] = 0;
			}
			
			nextc[player] = (nextc[player] + 1) % nextc_max[player];
			setNextBlockColor(player, 0);
		} else {
			// 通常ホールド
			temp = hold[player];
			hold[player] = blk[player];
			blk[player] = temp;
			
			for(i = 0; i < 4; i++) {
				temp = hold_color[i + player * 4];
				hold_color[i + player * 4] = current_color[i + player * 4];
				current_color[i + player * 4] = temp;
				current_color_m[i + player * 4] = temp;
			}
			
			temp = hold_oblk[player];
			hold_oblk[player] = current_oblk[player];
			current_oblk[player] = temp;
			
			if(enable_item_hold[player]) {
				temp = hold_item[player];
				hold_item[player] = current_item[player];
				current_item[player] = temp;
			} else {
				hold_item[player] = 0;
				current_item[player] = 0;
			}
		}
		hold_count[player]++;
		dhold[player] = 1;
	}
	
	if(hnext[player]) PlaySE(se_blockse[getNextBlock(player, 0)]);
	
	executePlugin(player, 19, &param);	// プラグイン呼び出し
	
	// 初期位置などを設定
	bx[player] = block_init_x_pos[player];
	by[player] = block_init_y_pos[player];
	rt[player] = block_init_rt[player];
	
	bs[player] = 0;
	bk[player] = 0;
	bk_D[player] = 0;
	
	harddrop[player] = 0;
	softdrop[player] = 0;
	softd_dropflag[player] = 0;
	softd_score[player] = 0;
	
	last_command[player] = 0;
	
	rotcount[player] = 0;
	movecount[player] = 0;
	kickc[player] = 0;
	
	sdrop[player] = 0;
	qdrop[player] = 0;
	qput[player] = 0;
	
	brotcount[player] = 0;
	bactivetime[player] = 0;
	bfallflag[player] = 0;
	bfallcount[player] = 0;
	
	tspin_flag[player] = 0;
	
	repeatcount[player] = 0;
	
	// アイテム存在のチェック
	scanItem(player);
	
	// NEXT遅延
	if((spawntype[player]) && (!is20G(player)) && (are[player] != 0)) ndelay[player] = 0;
	
	// 先行横移動
	if(fastlrmove[player]) initialMove(player);
	
	// 先行回転
	if(initial_rotate[player]) initialRotate(player);
	
	// ブロックがめり込んでいたらゲームオーバー
	if(judgeBlock(player, bx[player], by[player], blk[player], rt[player])) {
		setBlock(player, bx[player], by[player], blk[player], rt[player]);
		stat[player] = 7;
		resetStatc(player);
		return 1;
	} else if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player])) {
		PlaySE(se_kon);
	}
	
	statc[player * 10 + 3] = 1;	// 2回目以降に実行するときは1になる
	return 0;
}

// 先行横移動
void initialMove(int player) {
	int move;
	
	// キー入力を取得して移動方向を設定
	move = getPressState(player, 3) - getPressState(player, 2);
	
	// 2マス単位のBIGでは移動量を2倍にする
	if(IsBig[player] && BigMove[player]) move = move * 2;
	
	if(judgeBlock(player, bx[player] + move, by[player], blk[player], rt[player]) == 0) {
		// 移動成功
		if(move_sound) PlaySE(se_move);
		bx[player] = bx[player] + move;
	} else {
		// 移動失敗
		PlaySE(se_movefail);
	}
}

// 先行回転
void initialRotate(int player) {
	int move, bak;
	
	// 回転方向を決める
	if(!rot_reverse[player])
		move = (getPressState(player, 5) || getPressState(player, 8)) - (getPressState(player, 4) || getPressState(player, 6));
	else
		move = (getPressState(player, 4) || getPressState(player, 6)) - (getPressState(player, 5) || getPressState(player, 8));
	
	// 180度回転
	if(getPressState(player, 8) && !disable180) move = 2;
	
	if(move) {
		PlaySE(se_shaki);
		
		bak = rt[player] + move;
		
		if(move == 2) {
			// 180度回転
			if(bak > 3) bak = bak - 4;
			if(bak < 0) bak = bak + 4;
		} else {
			// 普通回転
			if(bak < 0) bak = 3;
			if(bak > 3) bak = 0;
		}
		
		if(judgeBlock(player, bx[player], by[player], blk[player], bak) == 0) {
			// 回転成功
			if(rotate_sound) PlaySE(se_rotate);
			brotcount[player]++;
			rt[player] = bak;
		} else {
			// 回転失敗
			PlaySE(se_rotfail);
		}
	}
}

// ブロック移動処理
void subMoveMain(int player) {
	int i, j, k, move, bak, bottom, allowmove, kosa, temp, rolling, lockdelay, cwaitt;
	int param;
	
	param = 0;
	executePlugin(player, 8, &param);	// プラグイン呼び出し
	if(param) return;
	
	// ブロックを操作している時間+1
	bactivetime[player]++;
	
	if(!statc[player * 10 + 0]) allowmove = 0;
	else allowmove = 1;
	
	if(speedtype[player] == 0) {
		bs[player] = bs[player] + sp[player];
		if((spawntype[player]) && (sp[player] >= 1200)) bs[player] = 1320;	// 枠外出現時の20G
	} else if(speedtype[player] == 1) {
		bs[player]++;
	} else if(speedtype[player] == 2) {
		bs[player] = bs[player] + sp[player];
		if((spawntype[player]) && (sp[player] >= 5120)) bs[player] = 5632;	// 枠外出現時の20G
	}
	
	if((softd_score[player] > 0) && (engineVer >= 13)) {
		qdrop[player] = qdrop[player] + softd_score[player];
	}
	
	softd_dropflag[player] = 0;
	softd_score[player] = 0;
	
	statc[player * 10 + 0]++;
	
	if(allowmove) {
		// ロールロール処理
		rolling = 0;
		if((current_rollroll[player] != 0) && (rollroll_interval[player] != 0)) {
			if(recTimer[player] % rollroll_interval[player] == 0)
				rolling = 1;
		}
		
		// 回転
		if(!rot_reverse[player])
			move = (getPushState(player, 5) || getPushState(player, 8) || rolling) - (getPushState(player, 4) || getPushState(player, 6));
		else
			move = (getPushState(player, 4) || getPushState(player, 6) || rolling) - (getPushState(player, 5) || getPushState(player, 8));
		
		// 180度回転
		if(getPushState(player, 8) && !disable180) move = 2;
		
		if(move) {
			bak = rt[player] + move;
			
			if(move == 2) {
				// 180度回転
				if(bak > 3) bak = bak - 4;
				if(bak < 0) bak = bak + 4;
			} else {
				// 普通回転
				if(bak < 0) bak = 3;
				if(bak > 3) bak = 0;
			}
			
			// 接地状態かどうかチェック
			k = judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]);
			
			if(judgeBlock(player, bx[player], by[player], blk[player], bak) == 0) {
				// 壁に重ならずに回転
				j = 0;
				rt[player] = bak;
			} else if(enable_wallkick[player]) {
				// 壁蹴り
				j = 1;
				if(wallKick(player, bak, move)) {
					rt[player] = bak;
				}
			}
			
			if(rt[player] == bak) {
				// 回転成功
				if(rotate_sound) PlaySE(se_rotate);
				last_command[player] = 1 + j + ((k != 0) * 2);	// 最後の操作
				bk_D[player] = 0;
				brotcount[player]++;
				
				if(k) {
					rotcount[player]++;
					resetLockDelay(player);
				}
			} else {
				// 回転失敗
				PlaySE(se_rotfail);
			}
		}
		
		// 左右に移動
		move = getPressState(player, 3) - getPressState(player, 2);
		if(IsBig[player] && BigMove[player]) move = move * 2;
		
		if(move) {
			// 接地状態かどうかチェック
			k = judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]);
			
			if(max_waitt[player] < waitt[player]) cwaitt = max_waitt[player];
			else cwaitt = waitt[player];
			
			if((mpc[player] == 1) || (mpc[player] >= cwaitt)) {
				if((repeatcount[player] < RepeatDelay[player]) && (RepeatDelay[player] > 0) && (mpc[player] >= cwaitt)) {
					// RepeatDelay
					repeatcount[player]++;
				} else if(judgeBlock(player, bx[player] + move, by[player], blk[player], rt[player]) == 0) {
					// 移動成功
					if(move_sound) PlaySE(se_move);
					bx[player] = bx[player] + move;
					last_command[player] = 0;
					bk_D[player] = 0;
					repeatcount[player] = 0;
					
					if(k) {
						movecount[player]++;
						resetLockDelay(player);
					}
				} else {
					// 移動失敗
					PlaySE(se_movefail);
				}
			}
		}
	}
	
	if(statc[player * 10 + 1]) return;
	
	if(!nanameallow) move = 0;
	
	for(bottom = by[player]; judgeBlock(player, bx[player], bottom, blk[player], rt[player]) == 0; bottom++);
	bottom--;
	
	if((bfallflag[player] == 0) || (wait4[player] < 0) || (engineVer <= 10)) lockdelay = wait3[player];
	else lockdelay = wait4[player];
	
	// 地面にくっついた
	if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0) {
		bs[player] = 0;
		if( (lockdelay < 99) && ((allowmove) || (engineVer <= 11)) ) bk[player]++;
		
		// 下キー
		if((!move) && (getPressState(player, 1)) && (allowmove)) softDrop(player, 0);
		
		// 上キー
		if((!move) && (getPressState(player, 0)) && (allowmove)) hardDrop(player, bottom);
		
		// 固定
		if(bk[player] >= lockdelay) {
			blockLock(player);
			return;
		}
	}
	// 空中
	else {
		// ゴーストブロック
		drawGBlock(player, bottom);
		
		if(allowmove) {
			// 下キー
			if((!move) && (getPressState(player, 1))) softDrop(player, 1);
			
			// 上キー
			if((!move) && (getPressState(player, 0))) hardDrop(player, bottom);
		}
	}
	
	// ブロックが落ちる
	if(speedtype[player] == 0) temp = 61;
	if(speedtype[player] == 1) {
		temp = sp[player];
		if(temp < 1) temp = 1;
	}
	if(speedtype[player] == 2) temp = 256;
	
	while(bs[player] >= temp) {
		if(speedtype[player] == 0) bs[player] = bs[player] - 60;
		if(speedtype[player] == 1) {
			if(engineVer >= 10) bs[player] = bs[player] - temp;
			else bs[player] = 0;
		}
		if(speedtype[player] == 2) bs[player] = bs[player] - 256;
		bk[player] = 0;
		bk_D[player] = 0;
		
		// 下に空白がある場合は落下
		if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) {
			by[player]++;
			softdrop[player] = 0;
			harddrop[player] = 0;
			last_command[player] = 0;
			if((allowmove) && (bfallcount[player] != 0)) bfallflag[player] = 1;
			
			if((softd_dropflag[player]) && (engineVer >= 13)) {
				softd_score[player]++;
			}
		}
		
		// 地面にくっついた
		if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0) {
			bs[player] = 0;
			bfallcount[player]++;
			if( (lockdelay < 99) && ((allowmove) || (engineVer <= 11)) ) bk[player]++;
			PlaySE(se_kon);
			
			// 下キー
			if((!move) && (getPressState(player, 1)) && (allowmove)) softDrop(player, 2);
			
			// 上キー
			if((!move) && (getPressState(player, 0)) && (allowmove)) hardDrop(player, bottom);
			
			// 固定
			if(bk[player] >= lockdelay) {
				PlaySE(se_kon);
				blockLock(player);
				return;
			}
		}
	}
	
	// ブロックを描く
	if((bk[player] >= lockdelay - 1) && (!IsBig[player])) {
		kosa = 12;
	} else {
		kosa = bk[player] * 7 / (lockdelay + (lockdelay == 0));
		if(kosa > 6) kosa = 6;
	}
	drawCBlock(player, kosa, 0);
}

// ソフトドロップ
void softDrop(int player, int type) {
	int param[2], temp;
	
	param[0] = 0;
	param[1] = type;
	executePlugin(player, 48, &param);
	if(param[0]) return;
	
	if(down_flag[player]) return;
	if(lock_down[player] == 6) return;
	
	if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) {
		// 空中
		if((engineVer >= 5) && (speedtype[player] == 1)) {
			// FRAMES PER ROW
			last_command[player] = 0;
			if(engineVer <= 12) qdrop[player]++;
			softdrop[player] = 1;
			softd_dropflag[player] = 1;
			bs[player] = bs[player] + (softspeed[player] + 1) * (sp[player] / 2);
		} else if(speedtype[player] != 1) {
			// 1/60, 1/256
			if(speedtype[player] == 0) temp = 30;
			if(speedtype[player] == 2) temp = 128;
			
			if(sp[player] < (softspeed[player] + 1) * temp) {
				last_command[player] = 0;
				if(engineVer <= 12) qdrop[player]++;
				softdrop[player] = 1;
				softd_dropflag[player] = 1;
				
				if(softspeed[player] % 2 == 0) bs[player] = bs[player] + (softspeed[player] + 1) * temp;
				else bs[player] = (softspeed[player] + 1) * temp + (speedtype[player] == 0);
			}
		}
	} else {
		// 接地
		if(lock_down[player] == 1) {
			// 即固定
			bk[player] = 100;
		} else if(lock_down[player] == 2) {
			// ゆっくり固定1
			bk[player]++;
		} else if(lock_down[player] == 3) {
			// ゆっくり固定2
			bk[player] = bk[player] + 2;
		} else if(lock_down[player] == 4) {
			// 1G以上で固定
			if(speedtype[player] == 0) temp = 60;
			if(speedtype[player] == 1) temp = 10000;
			if(speedtype[player] == 2) temp = 256;
			if(engineVer <= 3) temp = 60;
			
			if((speedtype[player] == 1) && (sp[player] <= 1) && (engineVer >= 4)) {
				bk[player] = 100;
			} else if( (sp[player] >= temp) && ((speedtype[player] != 1) || (engineVer <= 6)) ) {
				bk[player] = 100;
			} else {
				bk_D[player]++;
				if(bk_D[player] >= 8) bk[player] = 100;
			}
		} else if((lock_down[player] == 5) && (type == 0) && getPushState(player, 1)) {
			// 地面で下を押したときだけ固定
			bk[player] = 100;
		}
		if((bk[player] >= 100) && (engineVer >= 2)) qput[player] = 1;
		if((bk[player] >= 100) && (self_lock_sound[player])) PlaySE(se_self_lock);
		softdrop[player] = 1;
	}
}

// ハードドロップ
void hardDrop(int player, int bottom) {
	int temp, param[2];
	
	param[0] = 0;
	param[1] = bottom;
	executePlugin(player, 49, &param);
	if(param[0]) return;
	
	if(up_flag[player]) return;
	if(lock_up[player] == 2) return;
	
	if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) {
		// 空中
		temp = (bottom - by[player]) * 2;
		if((engineVer <= 5) || (temp > sdrop[player])) sdrop[player] = temp;
		
		last_command[player] = 0;
		by[player] = bottom;
		bs[player] = 0;
		bk[player] = 0;
		bfallcount[player]++;
		harddrop[player] = 1;
		
		if(lock_up[player] == 1) {
			bk[player] = 100;
			
			if(self_lock_sound[player]) {
				PlaySE(se_kon);
				PlaySE(se_self_lock);
			}
		} else {
			PlaySE(se_kon);
		}
	} else {
		// 接地
		if(lock_up[player] == 1) {
			bk[player] = 100;
			if(engineVer >= 2) qput[player] = 1;
			if(self_lock_sound[player]) PlaySE(se_self_lock);
		}
		harddrop[player] = 1;
	}
}

// 固定時間リセット
// 規定回数オーバーの場合は戻り値は1
int resetLockDelay(int player) {
	int temp;
	
	if(!lockreset[player]) return 0;
	if(statc[player * 10 + 1]) return 0;
	
	temp = 0;
	if((rotcount[player] >= rotlimit[player]) && (rotlimit[player] > 0)) temp = 1;
	if((movecount[player] >= movelimit[player]) && (movelimit[player] > 0)) temp = 1;
	if(temp) {
		blockLock(player);
		return 1;
	}
	
	PlaySE(se_kon);
	bk[player] = 0;
	bfallflag[player] = 1;
	return 0;
}

// ブロックを固定させる
void blockLock(int player) {
	int bottom;
	
	if(statc[player * 10 + 1]) return;
	
	// 現在のブロックを強制的に接地させる
	for(bottom = by[player]; judgeBlock(player, bx[player], bottom, blk[player], rt[player]) == 0; bottom++);
	bottom--;
	by[player] = bottom;
	
	// NEXT遅延解除
	ndelay[player] = 1;
	
	// 効果音を鳴らす
	PlaySE(se_kachi);
	
	// 上入れ下入れフラグON
	if(harddrop[player] && getPressState(player, 0)) up_flag[player] = 1;
	if(softdrop[player] && getPressState(player, 1)) down_flag[player] = 1;
	
	// ブロックを描画
	if(engineVer <= 11) drawCBlock(player, 6, 0);
	
	// ブロックが固定した瞬間の処理へ
	statc[player * 10 + 1] = 1;
}

// 壁蹴り
// 成功すると戻り値は1
int wallKick(int player, int bak, int move) {
	int param[3];
	param[0] = 0;
	param[1] = bak;
	param[2] = move;
	executePlugin(player, 9, &param);	// プラグイン呼び出し
	return param[0];
}

// ブロックが固定した瞬間の処理
void subMoveLock(int player) {
	int i, temp, param;
	
	statc[player * 10 + 2]++;
	drawCBlock(player, 0, 1);
	
	// HOLD使用可能に
	if(dhold[player] == 1) dhold[player] = 0;
	
	if(statc[player * 10 + 2] >= lockflash[player]) {
		// カウンタ初期化
		resetStatc(player);
		
		// T-SPIN判定
		if((last_command[player] >= 3) && (blk[player] == 4))
			tspin_flag[player] = isTSpin(player);
		
		// ブロック設置
		bdowncnt[player]++;
		if(setBlock(player, bx[player], by[player], blk[player], rt[player])) {
			// 枠外出現のときは1つもブロックを枠内に置けなかったら即死
			if(spawntype[player]) {
				stat[player] = 7;
				return;
			}
		}
		
		// ラインが消えるかどうか判定
		temp = blockEraseJudge(player);
		
		if(temp) {
			// ライン消去あり
			stat[player] = 6;	// ブロック消去へ
			
			// LINE CLEAR式T-SPIN判定
			if((tspin_type[player] == 1) && (last_command[player] >= 3) && (blk[player] == 4))
				tspin_flag[player] = 1;
			
			statEraseBlock(player);
		} else {
			// ライン消去なし
			param = 0;
			executePlugin(player, 60, &param);
			if(param) return;
			
			combo[player] = 0;
			combo2[player] = 0;
			combo3[player] = 0;
			hebocombo[player] = 0;
			if(engineVer <= 5) cmbpts[player] = 0;
			else cmbpts[player] = 1;
			
			// ライン消しなしのT-SPINをしたとき
			if(tspin_flag[player]) executePlugin(player, 59, &dummy);
			
			pinchCheck(player);
			
			stat[player] = 5;	// 待ち時間処理へ
			statc[player * 10] = wait1[player] - lockflash[player];
			statErase(player);
		}
	}
}

// T-SPIN判定（IMMOBILE/3-CORNER/3-CORNER NO KICK）
int isTSpin(int player) {
	int param;
	
	// IMMOBILE
	if(tspin_type[player] == 2) {
		if(judgeBlock(player, bx[player] - 1, by[player]    , blk[player], rt[player]) && 
		   judgeBlock(player, bx[player] + 1, by[player]    , blk[player], rt[player]) && 
		   judgeBlock(player, bx[player]    , by[player] - 1, blk[player], rt[player]))
		{
			return 1;
		}
	}
	// 3-CORNER/3-CORNER NO KICK
	else if(tspin_type[player] >= 3) {
		param = 0;
		if((tspin_type[player] == 3) || (last_command[player] == 3)) executePlugin(player, 58, &param);
		if(param) return 1;
	}
	
	return 0;
}
