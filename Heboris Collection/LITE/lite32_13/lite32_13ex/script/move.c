//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.05 - ブロック移動中
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statMove(int player) {
	int tmp;
	
	// CPUの操作
	if( (cpu_flag[player]) && ((!replayauto) || (repversw <= 3)) ) {
		cpu_setCtrl(player);
	}
	
	// ナビゲーションシステムもどき
	if( (tc[player] < limit_navigation) && 
	    ( (enable_navigation == 2) || ((enable_navigation == 1) && (gameMode[player] == 0)) ) && 
	    (cpu_best_x[player] != -3) && (!IsBig[player]) )
	{
		if(navigation_time[player] <= limit_time_navigation) {
			navigation_time[player]++;
			
			drawNaviBlock(cpu_best_x[player] + boffset[player], cpu_best_y[player] + 3, blk[player], cpu_best_r[player],
							c_cblk[player] - 1, (navigation_time[player] % 20) / 2, player);
		}
	}
	
	// NEXTブロック表示の遅延
	if(!IsBig[player]) {
		if(isWRule(player)) {
			tmp = (blk[player] != 0);
		} else if(isDRule(player)) {
			tmp = (blk[player] == 0) * -1;
		} else {
			tmp = 0;
		}
	} else {
		if(isWRule(player)) {
			if(blk[player] == 0) tmp = -1;
			else tmp = 1;
		} else if(isDRule(player)) {
			tmp = -1 + (blk[player] == 0) * -2;
		} else {
			tmp = -1;
		}
	}
	
	if((by[player] >= tmp) || (!spawn_y_type) || (!rule_are[rots[player]]))
		ndelay[player] = 1;
	
	// 旧HIDDEN処理
	hiddenProc(player);
	
	// ブロック移動処理
	if(!statc[player * 10 + 2]) {
		blockMoveMain(player);
		
		if((skip_blocklockflash != 0) && (skip_blocklockflash != 3) && (statc[player * 10 + 2] != 0))
			blockMoveFlash(player);
	} else {
		blockMoveFlash(player);
	}
}

// ブロック移動メイン処理
void blockMoveMain(int player) {
	int i, j, k, tmp, result;
	int bak, bottom, move, flash, kosa, rolling, move2, move3;
	int block;
	
	move2 = statc[player * 10 + 4];	// 最初の1フレームは上下移動を無効化
	
	move3 = 1;
	if(repversw >= 5) move3 = statc[player * 10 + 4];	// 最初の1フレームは回転とホールドとブロックの表示を無効
	
	// 横溜め処理
	padRepeat(player);
	
	// HOLD
	if(move3) {
		doHold(player, 0);
		if(stat[player] == 7) return;	// HOLDしてゲームオーバーになった場合はここで止める
	}
	
	// ブロックを操作している時間をカウント
	if(timeOn[player]) timeN[player]++;
	
	// ハードドロップ使用フラグ初期化
	harddrop[player] = 0;
	softdrop[player] = 0;
	
	if(!speedtype[player]) {
		// 落下速度設定
		bs[player] = bs[player] + sp[player];
		
		// BOOST FIRE時は20G
		if(isboost[player]) bs[player] = 1320;
		
		// spawn_y_typeが1の場合の20G
		if((spawn_y_type) && (sp[player] >= 1200)) bs[player] = 1320;
	} else {
		bs[player]++;
	}
	
	// ロールロール処理
	rolling = 0;
	if(isrollroll[player]) {
		if(!timeOn[player]) tmp = time2[player];
		else if(gameMode[player] == 6) tmp = stime[player];
		else tmp = gameTimer[player];
		
		if(tmp % p_rollroll_timer == 0) rolling = 1;
	}
	
	// 接地した状態かどうかを判定（新固定時間リセット用）
	if(w_lockdown && rule_lock_reset[rots[player]]) {
		k = judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]);
	}
	
	// 回転
	move = 0;
	if(!isRotateLock[player] && move3) {
		if(w_reverse && isWRule(player))
			move = (getPushState(player, 4) || getPushState(player, 6) || rolling) - getPushState(player, 5);
		else
			move = (getPushState(player, 5) || rolling) - (getPushState(player, 4) || getPushState(player, 6));
		
		// 180度回転
		if( ((rot180 == 1) || ((rot180 == 2) && (rule_180rot[rots[player]] != 0))) && getPushState(player, 6) ) {
			move = 2;
		}
	}
	
	if(move) {
		bak = rt[player] + move;
		
		if(istrance[player]) {
			// TRANCE FORM
			do {
				block = GiziRand(player, 7);
			} while(block == blk[player]);
		} else {
			block = blk[player];
		}
		
		if(move == 2) {
			// 180度回転
			if(bak > 3) bak = bak - 4;
			if(bak < 0) bak = bak + 4;
		} else {
			// 普通回転
			if(bak > 3) bak = 0;
			if(bak < 0) bak = 3;
		}
		
		tmp = blk[player];
		blk[player] = block;
		
		// 回転を試みる
		if(judgeBlock(player, bx[player], by[player], blk[player], bak) == 0) {
			// 壁に当たらない場合
			rt[player] = bak;
			result = 1;
		} else if(!heboGB[player]) {
			// 壁に当たる場合は壁蹴りする
			if(rule_rot[rots[player]] == 0) result = wallkickARS(player, bak, rule_ars_extrot[rots[player]]);
			if(rule_rot[rots[player]] == 1) result = wallkickSRS(player, bak, move);
			if(rule_rot[rots[player]] == 2) result = wallkickDRS(player, bak, move);
			
			// 壁蹴りした回数+1
			tspin_kick[player] = tspin_kick[player] + result;
		}
		
		if(result) {
			// 回った
			if(rotate_sound) PlaySE(4);
			
			bk_D[player] = 0;
			
			// 最後の操作
			if(k != 0)
				last_command[player] = 2;	// 接地状態で回転
			else
				last_command[player] = 1;	// 空中で回転
			
			if(istrance[player]) {
				if(rule_color[rots[player]]) c_cblk_r[player] = wcol[block];
				else c_cblk_r[player] = ccol[block];
			}
		} else {
			// 回らなかった
			if(!IsPlayWave(35)) PlaySE(35);
			blk[player] = tmp;
		}
		
		// 接地した状態かどうかを判定（旧固定時間リセット用）
		if(!w_lockdown && rule_lock_reset[rots[player]]) {
			k = judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]);
		}
		
		// 固定時間リセット
		if((rule_lock_reset[rots[player]]) && (result) && (k != 0) && (!heboGB[player]))
			blockLDelayReset(player, 1);
	}
	
	// 左右に移動
	move = 0;
	
	if(statc[player * 10 + 4]) {
		// キー入力を取得して移動方向を設定
		move = getPressState(player, 3) - getPressState(player, 2);
		
		// 2マス単位のBIGでは移動量を2倍にする
		if(IsBig[player] && BigMove[player]) move = move * 2;
		
		// 横溜め設定
		if(rule_max_waitt[rots[player]] < waitt[player]) tmp = rule_max_waitt[rots[player]];
		else tmp = waitt[player];
		
		if( (move != 0) && ((mpc[player] == 1) || (mpc[player] >= tmp)) )
			if(judgeBlock(player, bx[player] + move, by[player], blk[player], rt[player]) == 0) {
				// ブロックを移動させる
				bx[player] = bx[player] + move;
				if(move_sound) PlaySE(5);
				
				// 最後の操作を「移動」にする
				last_command[player] = 0;
				
				// 接地した状態かどうかを判定（旧固定時間リセット用）
				if(!w_lockdown && rule_lock_reset[rots[player]]) {
					k = judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]);
				}
				
				// T-SPIN無効フラグ初期化
				tspin_kick[player] = 0;
				
				bk_D[player] = 0;
				
				// 固定時間リセット
				if((rule_lock_reset[rots[player]]) && (k != 0) && (!heboGB[player]))
					blockLDelayReset(player, 0);
			} else {
				// 移動できなかった
				if(!IsPlayWave(34)) PlaySE(34);
			}
	}
	
	// 斜め入力ONのとき用
	if(!nanameallow) move = 0;
	
	// 上下入力制限解除
	if(!getPressState(player, 1)) down_flag[player] = 0;
	if(!getPressState(player, 0)) up_flag[player] = 0;
	
	// ソフトドロップ
	if(getPressState(player, 1) && !move && move2 && !down_flag[player])
		softDrop(player, rule_lock_sound[rots[player]]);
	
	// ハードドロップ
	if(getPressState(player, 0) && !move && move2 && !up_flag[player] && !heboGB[player] && !sonicdrop)
		hardDrop(player, rule_lock_sound[rots[player]]);
	
	if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0) {
		// 接地している場合
		bs[player] = 0;
		
		tmp = wait3[player];
		if((isboost[player]) && (sp[player] >= 1200)) tmp = tmp / 2;	// 20G中のBOOST FIRE
		
		if(bk[player] != 100) {
			if(tmp < 99)
				bk[player]++;
			else if(repversw <= 5)
				bk[player] = 98;
		}
		
		// 下入れ即固定
		if(getPushState(player, 1) && !down_flag[player] && !move && move2 && (wsoftlock == 1)) {
			if(rule_lock_sound[rots[player]]) PlaySE(43);
			bk[player] = 100;
		}
		
		if(repversw <= 4) tmp = tmp + 3;	// repversw = 5から2フレ短縮
		if(repversw == 5) tmp = tmp + 1;
		
		// ブロック固定
		if((bk[player] >= tmp) || (bk_D[player] > 30) || (ismagnetblock[player])) {
			blockLock(player);
			return;
		}
	} else {
		// 接地していない場合
		if(!heboGB[player] && move3) {
			// T.L.S. (Temporary Landing System)  (c)1998 AR●KA(^^;
			for(bottom = by[player]; judgeBlock(player, bx[player], bottom, blk[player], rt[player]) == 0; bottom++);
			drawTLSBlock(player, bottom);
		}
		
		// T-SPIN無効フラグ初期化
		tspin_kick[player] = 0;
		
		// ブロックが落ちる
		if(!speedtype[player]) j = 60;
		else j = sp[player];
		
		while(bs[player] > j) {
			// 残像
			if((block_afterimage == 2) && (bs[player] > 90) && (!heboGB[player]))
				drawCBlock(player, c_cblk[player], 5, 0, 0, 0);
			
			bk[player] = 0;
			bk_D[player] = 0;
			bs[player] = bs[player] - j;
			
			// 下に空白がある場合はブロックを落下させる
			if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) {
				by[player]++;
				last_command[player] = 3;
			}
			
			// 地面にくっついた
			if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0) {
				if(heboGB[player] != 1) PlaySE(1);
				bs[player] = 0;
				
				tmp = wait3[player];
				if((isboost[player]) && (sp[player] >= 1200)) tmp = tmp / 2;	// 20G中のBOOST FIRE
				if(repversw <= 6) tmp++;
				
				if((repversw >= 6) && (tmp < 99)) bk[player]++;
				
				// ソフトドロップ
				if(getPressState(player, 1) && !move && move2 && !down_flag[player])
					softDrop(player, rule_lock_sound[rots[player]]);
				
				// ハードドロップ
				if(getPressState(player, 0) && !move && move2 && !up_flag[player] && !heboGB[player] && !sonicdrop)
					hardDrop(player, rule_lock_sound[rots[player]]);
				
				// ブロック固定
				if((bk[player] >= tmp) || (bk_D[player] > 30) || (ismagnetblock[player])) {
					blockLock(player);
					return;
				}
			}
		}
	}
	
	statc[player * 10 + 4] = 1;		// 最初の1フレームは移動させないゾ
	
	// ブロックを描く
	if((move3) || (block_afterimage == 2)) blockShow(player);
}

// ブロックが固定した瞬間の処理
void blockMoveFlash(int player) {
	int tmp;
	
	statc[player * 10 + 2]++;
	ndelay[player] = 1;
	
	if(heboGB[player] == 2) {
		drawCBlock(player, c_cblk[player], 0, 0, 0, 1);
	} else {
		drawCBlock(player, c_cblk[player], 0, 0, 10, 1);
	}
	
	// 上下入力制限解除
	if(!getPressState(player, 1)) down_flag[player] = 0;
	if(!getPressState(player, 0)) up_flag[player] = 0;
	
	// HOLD使用可能に
	dhold[player] = 0;
	
	if((skip_blocklockflash == 0) || (skip_blocklockflash == 3) || (repversw <= 5)) {
		// 横溜め処理
		padRepeat(player);
		
		// カスタムIRS
		if(ace_irs == 3) doNewIRS(player, 1);
		
		// HYPER横先行移動
		if(fastlrmove == 3) HyperLRMove(player);
	}
	
	// 固定アニメ終了
	if((statc[player * 10 + 2] >= 2 + (skip_blocklockflash == 3)) || 
	   (skip_blocklockflash == 1) || (skip_blocklockflash == 2))
	{
		// T-SPIN判定
		if( (last_command[player] == 2) && (blk[player] == 4) && (isTSpinEnableMode(player)) && 
		    (isTSpinImmobile(player) || isTSpin3Corner(player)) )
		{
			tspin_frame[player] = 120;
			IsTspin[player] = 1;
		}
		
		// ブロックを置く
		setBlock(player, bx[player], by[player], blk[player], rt[player]);
		if(stat[player] == 7) return;	// ブロックを枠外に置いて死んだ場合はここで止める
		
		// 置いた回数+1
		bdowncnt[player]++;
		s_bdowncnt[player]++;
		
		// せり上がり用置いた回数+1
		if( (r_enable[player]) && (tc[player] >= r_start[player]) && (tc[player] <= r_end[player]) && 
		    (gameMode[player] != 13) )
		{
			r_bdowncnt[player]++;
		}
		
		// DEVILせり上がりカウント-1
		if(risecount[player] > 0) {
			risecount[player]--;
		}
		
		// 正方形判定
		if(squaremode[player]) {
			tmp = makeSquare(player);
			
			if(gameMode[player] == 8) {
				if( ((mission_type[c_mission] == 41) && (tmp >= 1)) || ((mission_type[c_mission] == 42) && (tmp >= 2)) )
					missionNormUp(0);
			}
		}
		
		// ステータスカウンタを初期化
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = 0;
		statc[player * 10 + 3] = 0;
		statc[player * 10 + 4] = 0;
		statc[player * 10 + 5] = 0;
		
		// 次のステータスへ
		if(blockEraseJudge(player)) {
			// 1ライン以上消える場合
			
			// LINE CLEAR式T-SPIN獲得判定
			if((last_command[player] == 2) && (blk[player] == 4) && (tspin_type == 1) && (isTSpinEnableMode(player))) {
				tspin_frame[player] = 120;
				IsTspin[player] = 1;
			}
			
			// T-SPIN音
			if(IsTspin[player]) PlaySE(50);
			
			// ライン消去処理へ
			stat[player] = 8;
			statc[player * 10] = 0;
			
			if(skip_blocklockflash >= 2) statEraseBlock(player);
		} else {
			// 消えるラインがない場合
			lastblkline[player] = 0;
			
			if(IsTspin[player]) {
				// T-SPIN音
				PlaySE(42);
				
				// ライン消しなしのT-SPIN回数増加
				tspin_count[0 + player * 4]++;
				lasttspin[player] = 0;
				
				// SIMPLE/MARATHONモードのボーナス
				if((bonus_tspin) && ((gameMode[player] == 17) || (isMarathonMode(player)))) {
					if(!tspin_kick[player]) tmp = 4;
					else tmp = 1;
					
					sc[player] = sc[player] + (tmp * 100 * (tc[player] + 1));
					if(isMarathonMode(player)) {
						c_norm[player] = c_norm[player] + tmp;
						if(c_norm[player] > m_norm[player]) c_norm[player] = m_norm[player];
					}
				}
			}
			
			// HEBO+のせり上がり用
			if(gameMode[player] == 10) r_bdowncnt[player]++;
			
			// コンボ初期化
			combo[player] = 0;
			cmbpts[player] = 0;
			hebocombo[player] = 0;
			combo2[player] = 0;
			hanabi_combo[player] = 0;
			tcombo[player] = 0;
			if((gameMode[player] == 8) && (mission_type[c_mission] == 27)) c_norm[player] = 0;
			
			// ピンチかどうかチェック
			pinchCheck(player);
			
			// 待ち時間処理へ
			stat[player] = 6;
			statc[player * 10] = wait1[player] - (repversw >= 6);
			statc[player * 10 + 1] = 0;
			
			if(skip_blocklockflash >= 2) statErase(player);
		}
	}
}

// ブロックを描く
void blockShow(int player) {
	int flash, kosa, tmp;
	
	tmp = wait3[player];
	if((isboost[player]) && (sp[player] >= 1200)) tmp = tmp / 2;	// 20G中のBOOST FIRE
	
	flash = (count % 2) * (blockflash == 0) + (blockflash == 1);
	kosa = bk[player] * 7 / (tmp + (tmp == 0));
	if(kosa > 6) kosa = 6;
	
	if(smooth && (sp[player] < 60))
		drawCBlock(player, c_cblk[player], kosa, (bs[player] * 8 / 60), flash, 1);
	else
		drawCBlock(player, c_cblk[player], kosa, 0, flash, 1);
}

// ブロックを固定させる
// player  ： プレイヤー番号
void blockLock(int player) {
	int bottom;
	
	if((statc[player * 10 + 2] != 0) && (repversw >= 7)) return;
	
	// ブロックを強制的に接地させる
	if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) {
		for(bottom = by[player]; judgeBlock(player, bx[player], bottom, blk[player], rt[player]) == 0; bottom++);
		by[player] = bottom - 1;
		last_command[player] = 3;
	}
	
	if(heboGB[player] != 2) {
		if(heboGB[player] == 1) PlaySE(1);
		else PlaySE(3);
	}
	
	if(heboGB[player] == 2) {
		drawCBlock(player, c_cblk[player], 0, 0, 0, 1);
	} else if(skip_blocklockflash == 3) {
		drawCBlock(player, c_cblk[player], 6, 0, 0, 1);
	} else {
		drawCBlock(player, c_cblk[player], 0, 0, 10, 1);
	}
	
	if( (downtype == 1) || 
	    ( (downtype == 2) && ((sp[player] >= 1200) || (!wait1[player]) || (!rule_are[rots[player]])) ) )
	{
		// 上入れ制限
		if(getPressState(player, 0) && harddrop[player]) up_flag[player] = 1;
		
		// 下入れ制限
		if(getPressState(player, 1) && softdrop[player]) down_flag[player] = 1;
	}
	
	// 固定後の処理へ
	statc[player * 10 + 2]++;
}

// 固定時間リセット
// player  ： プレイヤー番号
// rot     ： 0で移動、1で回転
void blockLDelayReset(int player, int rot) {
	bk[player] = 0;						// 固定時間リセット
	bk_D[player] = 0;
	
	if(!rot) {
		kickc[player]++;	// 接地した状態での移動回数をカウント
	} else {
		kickc3[player]++;	// 接地した状態での回転回数をカウント
	}
	
	if( ((rot == 0) && (rule_lock_limit[rots[player]] > 0) && (kickc[player] >= rule_lock_limit[rots[player]])) || 
	    ((rot != 0) && (rule_rot_limit[rots[player]] > 0) && (kickc3[player] >= rule_rot_limit[rots[player]])) )
	{
		// 強制固定
		bk[player] = 100;	// 強制固定
		blockLock(player);
	} else if(world_move_sound) {
		PlaySE(1);	// 接地音
	}
}

// ソフトドロップ
// player  ： プレイヤー番号
// locksnd ： 固定させたときにace_sonic_lock.wavを鳴らす
void softDrop(int player, int locksnd) {
	int tmp;
	
	if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) {
		// 接地していない場合
		if((sp[player] < 60) || (rule_soft_speed[rots[player]] >= 2) || (speedtype[player])) {
			if(!speedtype[player]) {
				if(rule_soft_speed[rots[player]] == 0) bs[player] = bs[player] + 31;
				if(rule_soft_speed[rots[player]] == 1) bs[player] = 61;
				if(rule_soft_speed[rots[player]] == 2) bs[player] = bs[player] + 90;
				if(rule_soft_speed[rots[player]] == 3) bs[player] = bs[player] + 120;
			} else {
				if(rule_soft_speed[rots[player]] == 0) bs[player] = bs[player] + (sp[player] / 2);
				if(rule_soft_speed[rots[player]] == 1) bs[player] = sp[player] + 1;
				if(rule_soft_speed[rots[player]] == 2) bs[player] = bs[player] + (sp[player] * 2);
				if(rule_soft_speed[rots[player]] == 3) bs[player] = bs[player] + (sp[player] * 3);
			}
			
			qdrop[player]++;
			last_command[player] = 3;
			
			// OLD STYLEモード(ARCADE)ではドロップボーナス加算
			if((gameMode[player] == 9) && (heboGB[player] == 2) && (sp[player] > 1)) {
				sc[player]++;
			}
			
			// SIMPLE/MARATHONモードではドロップボーナス加算
			if((gameMode[player] == 17) || (isMarathonMode(player))) {
				sc[player]++;
			}
		}
	} else {
		// 接地している場合
		if((rule_soft_lock[rots[player]] == 1) || (heboGB[player])) {
			// 即固定あり
			bk[player] = 100;
			if(locksnd) PlaySE(43);
			
			// OLD STYLEモード(HANDHELD)ではドロップボーナス加算
			if((gameMode[player] == 9) && (heboGB[player] == 1)) {
				tmp = qdrop[player];
				if(rule_soft_speed[rots[player]] == 0) tmp = tmp / 2;
				if(rule_soft_speed[rots[player]] == 2) tmp = tmp + (tmp / 2);
				if(rule_soft_speed[rots[player]] == 3) tmp = tmp * 2;
				
				sc[player] = sc[player] + tmp;
			}
		} else if(rule_soft_lock[rots[player]] == 2) {
			// 1G以上で即固定
			if((sp[player] >= 60) || (heboGB[player])) {
				bk[player] = 100;
				if(locksnd) PlaySE(43);
			} else {
				bk_D[player] = bk_D[player] + 4;
			}
		} else {
			// 即固定なし
			if(wsoftlock != 3) bk[player] = bk[player] + 1 + (wsoftlock == 2);
		}
		
		softdrop[player] = 1;
	}
}

// ハードドロップ
// player  ： プレイヤー番号
// locksnd ： 固定させたときにace_sonic_lock.wavを鳴らす
void hardDrop(int player, int locksnd) {
	int dheight, bottom, air;
	
	// ブロックを一番下まで落とす
	if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) {
		air = 1;
		for(bottom = by[player]; judgeBlock(player, bx[player], bottom, blk[player], rt[player]) == 0; bottom++);
		bottom--;
		
		dheight = bottom - by[player];
		sdrop[player] = dheight * 2;
		
		if(!block_afterimage || heboGB[player]) {
			by[player] = bottom;
		} else {
			// 残像
			while(by[player] != bottom) {
				drawCBlock(player, c_cblk[player], 5, 0, 0, 0);
				by[player]++;
			}
		}
		
		last_command[player] = 3;
	} else {
		air = 0;
		dheight = 0;
	}
	
	// SIMPLE/MARATHONモードではドロップボーナス加算
	if((gameMode[player] == 17) || (isMarathonMode(player))) {
		sc[player] = sc[player] + (dheight * 2);
	}
	
	if(rule_hard_lock[rots[player]]) {
		// 即固定あり
		bk[player] = 100;
		
		if(locksnd) {
			if(air) PlaySE(1);
			PlaySE(43);
		}
	} else if(air) {
		// 即固定なし
		PlaySE(1);
		bs[player] = 0;
		bk[player] = 0;
		bk_D[player] = 0;
	}
	
	harddrop[player] = 1;
}

// ARSの壁蹴り
// 回転に成功すると1、失敗すると0が戻り値になります。
// player  ： プレイヤー番号
// bak     ： 回転する方向
// ext_rot ： 1にするとＴ字脱出＆ヘボリス棒壁蹴りが有効
int wallkickARS(int player, int bak, int ext_rot) {
	int i, move;
	
	move = 0;
	
	// 回転できないときは、左右に動かしてみよう（ヘボリス棒以外）
	if( (blk[player] != 0) && (judgeBlockRotate(player, bx[player], by[player], blk[player], bak) != 0) ) {
		// BIGの場合は2ブロック分調べる
		for(i = 0; i <= IsBig[player]; i++) {
			if(judgeBlock(player, bx[player] - 1 - i, by[player], blk[player], bak) == 0)
				move = -1 - i;
			if(judgeBlock(player, bx[player] + 1 + i, by[player], blk[player], bak) == 0)
				move = 1 + i;
			
			// 壁蹴り実行
			if(move) {
				bx[player] = bx[player] + move;
				rt[player] = bak;
				return 1;
			}
		}
	}
	
	// Ｔ字の脱出（1回だけ）
	if( (blk[player] == 4) && (ext_rot) && (!kickc2[player]) && (bak == 2) ) {
		// BIGの場合は2ブロック分調べる
		for(i = 0; i <= IsBig[player]; i++) {
			if(judgeBlock(player, bx[player], by[player] - 1 - i, blk[player], bak) == 0) {
				by[player] = by[player] - 1 - i;
				rt[player] = bak;
				kickc2[player]++;
				bk[player] = 0;	// 固定時間リセット
				bk_D[player] = 0;
				return 1;
			}
		}
	}
	
	// ヘボリス棒の壁蹴り
	if( (blk[player] == 0) && (ext_rot) && ((bak == 0) || (bak == 2)) ) {
		// BIGの場合は3ブロック分調べる
		for(i = 0; i <= IsBig[player] * 2; i++) {
			if(judgeBlock(player, bx[player] - 1 - i, by[player], blk[player], bak) == 0) {
				move = -1 - i;
				break;
			}
			if(judgeBlock(player, bx[player] + 1 + i, by[player], blk[player], bak) == 0) {
				move = 1 + i;
				break;
			}
			if(judgeBlock(player, bx[player] + 2 + i, by[player], blk[player], bak) == 0) {
				move = 2 + i;
				break;
			}
		}
		
		// 壁蹴り実行
		if(move) {
			bx[player] = bx[player] + move;
			rt[player] = bak;
			return 1;
		}
	}
	
	// ヘボリス棒の床蹴り（1回だけ、接地している場合のみ）
	if( (blk[player] == 0) && (ext_rot) && (!kickc2[player]) && ((bak == 1) || (bak == 3)) && 
	    (judgeBlock(player, bx[player], by[player] + 1, blk[player], bak) != 0) )
	{
		// BIGの場合は3ブロック分調べる
		for(i = 0; i <= IsBig[player] * 2; i++) {
			if(judgeBlock(player, bx[player], by[player] - 1 - i, blk[player], bak) == 0) {
				move = -1 - i;
				break;
			}
			if(judgeBlock(player, bx[player], by[player] - 2 - i, blk[player], bak) == 0) {
				move = -2 - i;
				break;
			}
		}
		
		// 壁蹴り実行
		if(move) {
			by[player] = by[player] + move;
			rt[player] = bak;
			kickc2[player]++;
			bk[player] = 0;	// 固定時間リセット
			bk_D[player] = 0;
			return 1;
		}
	}
	
	return 0;
}

// SRSの壁蹴り
// 回転に成功すると1、失敗すると0が戻り値になります。
// player  ： プレイヤー番号
// bak     ： 回転する方向
// move    ： -1で左回転、1で右回転、2で180度回転
int wallkickSRS(int player, int bak, int move) {
	int i;
	int sx[11], sy[11];
	
	if(move == 2) {
		// 180度回転
		if(blk[player] != 0) {	// I以外の時
			for(i = 0; i < 11; i++) {
				sx[i] = otherBlock180KickTable[ (i * 2) + (rt[player] * 22) ];
				sy[i] = otherBlock180KickTable[ (i * 2) + (rt[player] * 22) + 1];
			}
		} else {				// Iの時
			for(i = 0; i < 11; i++) {
				sx[i] = iBlock180KickTable[ (i * 2) + (rt[player] * 22) ];
				sy[i] = iBlock180KickTable[ (i * 2) + (rt[player] * 22) + 1 ];
			}
		}
	} else {
		// 普通回転
		if(blk[player] != 0) {	// I以外の時
			for(i = 0; i < 4; i++) {
				sx[i] = otherBlockKickTable[ (i * 2) + (rt[player] * 8) + ((move > 0) * 32) ];
				sy[i] = otherBlockKickTable[ (i * 2) + (rt[player] * 8) + ((move > 0) * 32) + 1 ];
			}
		} else {				// Iの時
			for(i = 0; i < 4; i++) {
				sx[i] = iBlockKickTable[ (i * 2) + (rt[player] * 8) + ((move > 0) * 32) ];
				sy[i] = iBlockKickTable[ (i * 2) + (rt[player] * 8) + ((move > 0) * 32) + 1 ];
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
			rt[player] = bak;
			return 1;
		}
	}
	
	return 0;
}

// DRSの壁蹴り
// 回転に成功すると1、失敗すると0が戻り値になります。
// player  ： プレイヤー番号
// bak     ： 回転する方向
// move    ： -1で左回転、1で右回転、2で180度回転
int wallkickDRS(int player, int bak, int move) {
	int i, hosei_type, y_hosei;
	
	//補正タイプを決める　反対のボタンを押していればタイプ逆転
	if(move > 0)
		hosei_type = 1 - 0 * getPressState(player, 4);	// R
	else
		hosei_type = 0 + 1 * getPressState(player, 5);	// L
	
	move = 0;
	y_hosei = 0;
	
	for(i = 0; i <= IsBig[player]; i++) {
		// 左優先 優先度の低い移動から調べる
		if(!hosei_type) {
			// 右下
			if(judgeBlock(player, bx[player] + 1 + i, by[player] + 1 + i, blk[player], bak) == 0) {
				move = 1 + i;
				y_hosei = 1 + i;
			}
			// 左下
			if(judgeBlock(player, bx[player] - 1 - i, by[player] + 1 + i, blk[player], bak) == 0) {
				move = -1 - i;
				y_hosei = 1 + i;
			}
			// 下
			if(judgeBlock(player, bx[player]        , by[player] + 1 + i, blk[player], bak) == 0) {
				move = 0;
				y_hosei = 1 + i;
			}
			// 右
			if(judgeBlock(player, bx[player] + 1 + i, by[player]    , blk[player], bak) == 0) {
				move = 1 + i;
				y_hosei = 0;
			}
			// 左
			if(judgeBlock(player, bx[player] - 1 - i, by[player]    , blk[player], bak) == 0) {
				move = -1 - i;
				y_hosei = 0;
			}
		}
		
		// 右優先
		if(hosei_type) {
			// 左下
			if(judgeBlock(player, bx[player] - 1 - i, by[player] + 1 + i, blk[player], bak) == 0) {
				move = -1 - i;
				y_hosei = 1 + i;
			}
			// 右下
			if(judgeBlock(player, bx[player] + 1 + i, by[player] + 1 + i, blk[player], bak) == 0) {
				move = 1 + i;
				y_hosei = 1 + i;
			}
			// 下
			if(judgeBlock(player, bx[player]        , by[player] + 1 + i, blk[player], bak) == 0) {
				move = 0;
				y_hosei = 1 + i;
			}
			// 左
			if(judgeBlock(player, bx[player] - 1 - i, by[player]    , blk[player], bak) == 0) {
				move = -1 - i;
				y_hosei = 0;
			}
			// 右
			if(judgeBlock(player, bx[player] + 1 + i, by[player]    , blk[player], bak) == 0) {
				move = 1 + i;
				y_hosei = 0;
			}
		}
		
		// 壁蹴り実行
		if(move || y_hosei) {
			rt[player] = bak;
			bx[player] = bx[player] + move;
			
			if(y_hosei) {
				PlaySE(1);
				by[player] = by[player] + y_hosei;
				bk[player] = 0;		// 固定時間リセット
				bk_D[player] = 0;
			}
			
			return 1;
		}
	}
	
	// Ｔ字の脱出（1回だけ）
	if( (blk[player] == 4) && (drs_floorkick) && (!kickc2[player]) && (bak == 2) ) {
		// BIGの場合は2ブロック分調べる
		for(i = 0; i <= IsBig[player]; i++) {
			if(judgeBlock(player, bx[player], by[player] - 1 - i, blk[player], bak) == 0) {
				by[player] = by[player] - 1 - i;
				rt[player] = bak;
				kickc2[player]++;
				bk[player] = 0;	// 固定時間リセット
				bk_D[player] = 0;
				return 1;
			}
		}
	}
	
	// ヘボリス棒の床蹴り（1回だけ、接地している場合のみ）
	if( (blk[player] == 0) && (drs_floorkick) && (!kickc2[player]) && 
	    (judgeBlock(player, bx[player], by[player] + 1, blk[player], bak) != 0) )
	{
		// BIGの場合は3ブロック分調べる
		for(i = 0; i <= IsBig[player] * 2; i++) {
			if(judgeBlock(player, bx[player], by[player] - 1 - i, blk[player], bak) == 0) {
				move = -1 - i;
				break;
			}
			if(judgeBlock(player, bx[player], by[player] - 2 - i, blk[player], bak) == 0) {
				move = -2 - i;
				break;
			}
		}
		
		// 壁蹴り実行
		if(move) {
			by[player] = by[player] + move;
			rt[player] = bak;
			kickc2[player]++;
			bk[player] = 0;	// 固定時間リセット
			bk_D[player] = 0;
			return 1;
		}
	}
	
	return 0;
}
