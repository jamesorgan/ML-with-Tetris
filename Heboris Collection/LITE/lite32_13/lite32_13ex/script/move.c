//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.05 - �u���b�N�ړ���
//������������������������������������������������������������������������������
void statMove(int player) {
	int tmp;
	
	// CPU�̑���
	if( (cpu_flag[player]) && ((!replayauto) || (repversw <= 3)) ) {
		cpu_setCtrl(player);
	}
	
	// �i�r�Q�[�V�����V�X�e�����ǂ�
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
	
	// NEXT�u���b�N�\���̒x��
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
	
	// ��HIDDEN����
	hiddenProc(player);
	
	// �u���b�N�ړ�����
	if(!statc[player * 10 + 2]) {
		blockMoveMain(player);
		
		if((skip_blocklockflash != 0) && (skip_blocklockflash != 3) && (statc[player * 10 + 2] != 0))
			blockMoveFlash(player);
	} else {
		blockMoveFlash(player);
	}
}

// �u���b�N�ړ����C������
void blockMoveMain(int player) {
	int i, j, k, tmp, result;
	int bak, bottom, move, flash, kosa, rolling, move2, move3;
	int block;
	
	move2 = statc[player * 10 + 4];	// �ŏ���1�t���[���͏㉺�ړ��𖳌���
	
	move3 = 1;
	if(repversw >= 5) move3 = statc[player * 10 + 4];	// �ŏ���1�t���[���͉�]�ƃz�[���h�ƃu���b�N�̕\���𖳌�
	
	// �����ߏ���
	padRepeat(player);
	
	// HOLD
	if(move3) {
		doHold(player, 0);
		if(stat[player] == 7) return;	// HOLD���ăQ�[���I�[�o�[�ɂȂ����ꍇ�͂����Ŏ~�߂�
	}
	
	// �u���b�N�𑀍삵�Ă��鎞�Ԃ��J�E���g
	if(timeOn[player]) timeN[player]++;
	
	// �n�[�h�h���b�v�g�p�t���O������
	harddrop[player] = 0;
	softdrop[player] = 0;
	
	if(!speedtype[player]) {
		// �������x�ݒ�
		bs[player] = bs[player] + sp[player];
		
		// BOOST FIRE����20G
		if(isboost[player]) bs[player] = 1320;
		
		// spawn_y_type��1�̏ꍇ��20G
		if((spawn_y_type) && (sp[player] >= 1200)) bs[player] = 1320;
	} else {
		bs[player]++;
	}
	
	// ���[�����[������
	rolling = 0;
	if(isrollroll[player]) {
		if(!timeOn[player]) tmp = time2[player];
		else if(gameMode[player] == 6) tmp = stime[player];
		else tmp = gameTimer[player];
		
		if(tmp % p_rollroll_timer == 0) rolling = 1;
	}
	
	// �ڒn������Ԃ��ǂ����𔻒�i�V�Œ莞�ԃ��Z�b�g�p�j
	if(w_lockdown && rule_lock_reset[rots[player]]) {
		k = judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]);
	}
	
	// ��]
	move = 0;
	if(!isRotateLock[player] && move3) {
		if(w_reverse && isWRule(player))
			move = (getPushState(player, 4) || getPushState(player, 6) || rolling) - getPushState(player, 5);
		else
			move = (getPushState(player, 5) || rolling) - (getPushState(player, 4) || getPushState(player, 6));
		
		// 180�x��]
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
			// 180�x��]
			if(bak > 3) bak = bak - 4;
			if(bak < 0) bak = bak + 4;
		} else {
			// ���ʉ�]
			if(bak > 3) bak = 0;
			if(bak < 0) bak = 3;
		}
		
		tmp = blk[player];
		blk[player] = block;
		
		// ��]�����݂�
		if(judgeBlock(player, bx[player], by[player], blk[player], bak) == 0) {
			// �ǂɓ�����Ȃ��ꍇ
			rt[player] = bak;
			result = 1;
		} else if(!heboGB[player]) {
			// �ǂɓ�����ꍇ�͕ǏR�肷��
			if(rule_rot[rots[player]] == 0) result = wallkickARS(player, bak, rule_ars_extrot[rots[player]]);
			if(rule_rot[rots[player]] == 1) result = wallkickSRS(player, bak, move);
			if(rule_rot[rots[player]] == 2) result = wallkickDRS(player, bak, move);
			
			// �ǏR�肵����+1
			tspin_kick[player] = tspin_kick[player] + result;
		}
		
		if(result) {
			// �����
			if(rotate_sound) PlaySE(4);
			
			bk_D[player] = 0;
			
			// �Ō�̑���
			if(k != 0)
				last_command[player] = 2;	// �ڒn��Ԃŉ�]
			else
				last_command[player] = 1;	// �󒆂ŉ�]
			
			if(istrance[player]) {
				if(rule_color[rots[player]]) c_cblk_r[player] = wcol[block];
				else c_cblk_r[player] = ccol[block];
			}
		} else {
			// ���Ȃ�����
			if(!IsPlayWave(35)) PlaySE(35);
			blk[player] = tmp;
		}
		
		// �ڒn������Ԃ��ǂ����𔻒�i���Œ莞�ԃ��Z�b�g�p�j
		if(!w_lockdown && rule_lock_reset[rots[player]]) {
			k = judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]);
		}
		
		// �Œ莞�ԃ��Z�b�g
		if((rule_lock_reset[rots[player]]) && (result) && (k != 0) && (!heboGB[player]))
			blockLDelayReset(player, 1);
	}
	
	// ���E�Ɉړ�
	move = 0;
	
	if(statc[player * 10 + 4]) {
		// �L�[���͂��擾���Ĉړ�������ݒ�
		move = getPressState(player, 3) - getPressState(player, 2);
		
		// 2�}�X�P�ʂ�BIG�ł͈ړ��ʂ�2�{�ɂ���
		if(IsBig[player] && BigMove[player]) move = move * 2;
		
		// �����ߐݒ�
		if(rule_max_waitt[rots[player]] < waitt[player]) tmp = rule_max_waitt[rots[player]];
		else tmp = waitt[player];
		
		if( (move != 0) && ((mpc[player] == 1) || (mpc[player] >= tmp)) )
			if(judgeBlock(player, bx[player] + move, by[player], blk[player], rt[player]) == 0) {
				// �u���b�N���ړ�������
				bx[player] = bx[player] + move;
				if(move_sound) PlaySE(5);
				
				// �Ō�̑�����u�ړ��v�ɂ���
				last_command[player] = 0;
				
				// �ڒn������Ԃ��ǂ����𔻒�i���Œ莞�ԃ��Z�b�g�p�j
				if(!w_lockdown && rule_lock_reset[rots[player]]) {
					k = judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]);
				}
				
				// T-SPIN�����t���O������
				tspin_kick[player] = 0;
				
				bk_D[player] = 0;
				
				// �Œ莞�ԃ��Z�b�g
				if((rule_lock_reset[rots[player]]) && (k != 0) && (!heboGB[player]))
					blockLDelayReset(player, 0);
			} else {
				// �ړ��ł��Ȃ�����
				if(!IsPlayWave(34)) PlaySE(34);
			}
	}
	
	// �΂ߓ���ON�̂Ƃ��p
	if(!nanameallow) move = 0;
	
	// �㉺���͐�������
	if(!getPressState(player, 1)) down_flag[player] = 0;
	if(!getPressState(player, 0)) up_flag[player] = 0;
	
	// �\�t�g�h���b�v
	if(getPressState(player, 1) && !move && move2 && !down_flag[player])
		softDrop(player, rule_lock_sound[rots[player]]);
	
	// �n�[�h�h���b�v
	if(getPressState(player, 0) && !move && move2 && !up_flag[player] && !heboGB[player] && !sonicdrop)
		hardDrop(player, rule_lock_sound[rots[player]]);
	
	if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0) {
		// �ڒn���Ă���ꍇ
		bs[player] = 0;
		
		tmp = wait3[player];
		if((isboost[player]) && (sp[player] >= 1200)) tmp = tmp / 2;	// 20G����BOOST FIRE
		
		if(bk[player] != 100) {
			if(tmp < 99)
				bk[player]++;
			else if(repversw <= 5)
				bk[player] = 98;
		}
		
		// �����ꑦ�Œ�
		if(getPushState(player, 1) && !down_flag[player] && !move && move2 && (wsoftlock == 1)) {
			if(rule_lock_sound[rots[player]]) PlaySE(43);
			bk[player] = 100;
		}
		
		if(repversw <= 4) tmp = tmp + 3;	// repversw = 5����2�t���Z�k
		if(repversw == 5) tmp = tmp + 1;
		
		// �u���b�N�Œ�
		if((bk[player] >= tmp) || (bk_D[player] > 30) || (ismagnetblock[player])) {
			blockLock(player);
			return;
		}
	} else {
		// �ڒn���Ă��Ȃ��ꍇ
		if(!heboGB[player] && move3) {
			// T.L.S. (Temporary Landing System)  (c)1998 AR��KA(^^;
			for(bottom = by[player]; judgeBlock(player, bx[player], bottom, blk[player], rt[player]) == 0; bottom++);
			drawTLSBlock(player, bottom);
		}
		
		// T-SPIN�����t���O������
		tspin_kick[player] = 0;
		
		// �u���b�N��������
		if(!speedtype[player]) j = 60;
		else j = sp[player];
		
		while(bs[player] > j) {
			// �c��
			if((block_afterimage == 2) && (bs[player] > 90) && (!heboGB[player]))
				drawCBlock(player, c_cblk[player], 5, 0, 0, 0);
			
			bk[player] = 0;
			bk_D[player] = 0;
			bs[player] = bs[player] - j;
			
			// ���ɋ󔒂�����ꍇ�̓u���b�N�𗎉�������
			if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) {
				by[player]++;
				last_command[player] = 3;
			}
			
			// �n�ʂɂ�������
			if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0) {
				if(heboGB[player] != 1) PlaySE(1);
				bs[player] = 0;
				
				tmp = wait3[player];
				if((isboost[player]) && (sp[player] >= 1200)) tmp = tmp / 2;	// 20G����BOOST FIRE
				if(repversw <= 6) tmp++;
				
				if((repversw >= 6) && (tmp < 99)) bk[player]++;
				
				// �\�t�g�h���b�v
				if(getPressState(player, 1) && !move && move2 && !down_flag[player])
					softDrop(player, rule_lock_sound[rots[player]]);
				
				// �n�[�h�h���b�v
				if(getPressState(player, 0) && !move && move2 && !up_flag[player] && !heboGB[player] && !sonicdrop)
					hardDrop(player, rule_lock_sound[rots[player]]);
				
				// �u���b�N�Œ�
				if((bk[player] >= tmp) || (bk_D[player] > 30) || (ismagnetblock[player])) {
					blockLock(player);
					return;
				}
			}
		}
	}
	
	statc[player * 10 + 4] = 1;		// �ŏ���1�t���[���͈ړ������Ȃ��]
	
	// �u���b�N��`��
	if((move3) || (block_afterimage == 2)) blockShow(player);
}

// �u���b�N���Œ肵���u�Ԃ̏���
void blockMoveFlash(int player) {
	int tmp;
	
	statc[player * 10 + 2]++;
	ndelay[player] = 1;
	
	if(heboGB[player] == 2) {
		drawCBlock(player, c_cblk[player], 0, 0, 0, 1);
	} else {
		drawCBlock(player, c_cblk[player], 0, 0, 10, 1);
	}
	
	// �㉺���͐�������
	if(!getPressState(player, 1)) down_flag[player] = 0;
	if(!getPressState(player, 0)) up_flag[player] = 0;
	
	// HOLD�g�p�\��
	dhold[player] = 0;
	
	if((skip_blocklockflash == 0) || (skip_blocklockflash == 3) || (repversw <= 5)) {
		// �����ߏ���
		padRepeat(player);
		
		// �J�X�^��IRS
		if(ace_irs == 3) doNewIRS(player, 1);
		
		// HYPER����s�ړ�
		if(fastlrmove == 3) HyperLRMove(player);
	}
	
	// �Œ�A�j���I��
	if((statc[player * 10 + 2] >= 2 + (skip_blocklockflash == 3)) || 
	   (skip_blocklockflash == 1) || (skip_blocklockflash == 2))
	{
		// T-SPIN����
		if( (last_command[player] == 2) && (blk[player] == 4) && (isTSpinEnableMode(player)) && 
		    (isTSpinImmobile(player) || isTSpin3Corner(player)) )
		{
			tspin_frame[player] = 120;
			IsTspin[player] = 1;
		}
		
		// �u���b�N��u��
		setBlock(player, bx[player], by[player], blk[player], rt[player]);
		if(stat[player] == 7) return;	// �u���b�N��g�O�ɒu���Ď��񂾏ꍇ�͂����Ŏ~�߂�
		
		// �u������+1
		bdowncnt[player]++;
		s_bdowncnt[player]++;
		
		// ����オ��p�u������+1
		if( (r_enable[player]) && (tc[player] >= r_start[player]) && (tc[player] <= r_end[player]) && 
		    (gameMode[player] != 13) )
		{
			r_bdowncnt[player]++;
		}
		
		// DEVIL����オ��J�E���g-1
		if(risecount[player] > 0) {
			risecount[player]--;
		}
		
		// �����`����
		if(squaremode[player]) {
			tmp = makeSquare(player);
			
			if(gameMode[player] == 8) {
				if( ((mission_type[c_mission] == 41) && (tmp >= 1)) || ((mission_type[c_mission] == 42) && (tmp >= 2)) )
					missionNormUp(0);
			}
		}
		
		// �X�e�[�^�X�J�E���^��������
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = 0;
		statc[player * 10 + 3] = 0;
		statc[player * 10 + 4] = 0;
		statc[player * 10 + 5] = 0;
		
		// ���̃X�e�[�^�X��
		if(blockEraseJudge(player)) {
			// 1���C���ȏ������ꍇ
			
			// LINE CLEAR��T-SPIN�l������
			if((last_command[player] == 2) && (blk[player] == 4) && (tspin_type == 1) && (isTSpinEnableMode(player))) {
				tspin_frame[player] = 120;
				IsTspin[player] = 1;
			}
			
			// T-SPIN��
			if(IsTspin[player]) PlaySE(50);
			
			// ���C������������
			stat[player] = 8;
			statc[player * 10] = 0;
			
			if(skip_blocklockflash >= 2) statEraseBlock(player);
		} else {
			// �����郉�C�����Ȃ��ꍇ
			lastblkline[player] = 0;
			
			if(IsTspin[player]) {
				// T-SPIN��
				PlaySE(42);
				
				// ���C�������Ȃ���T-SPIN�񐔑���
				tspin_count[0 + player * 4]++;
				lasttspin[player] = 0;
				
				// SIMPLE/MARATHON���[�h�̃{�[�i�X
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
			
			// HEBO+�̂���オ��p
			if(gameMode[player] == 10) r_bdowncnt[player]++;
			
			// �R���{������
			combo[player] = 0;
			cmbpts[player] = 0;
			hebocombo[player] = 0;
			combo2[player] = 0;
			hanabi_combo[player] = 0;
			tcombo[player] = 0;
			if((gameMode[player] == 8) && (mission_type[c_mission] == 27)) c_norm[player] = 0;
			
			// �s���`���ǂ����`�F�b�N
			pinchCheck(player);
			
			// �҂����ԏ�����
			stat[player] = 6;
			statc[player * 10] = wait1[player] - (repversw >= 6);
			statc[player * 10 + 1] = 0;
			
			if(skip_blocklockflash >= 2) statErase(player);
		}
	}
}

// �u���b�N��`��
void blockShow(int player) {
	int flash, kosa, tmp;
	
	tmp = wait3[player];
	if((isboost[player]) && (sp[player] >= 1200)) tmp = tmp / 2;	// 20G����BOOST FIRE
	
	flash = (count % 2) * (blockflash == 0) + (blockflash == 1);
	kosa = bk[player] * 7 / (tmp + (tmp == 0));
	if(kosa > 6) kosa = 6;
	
	if(smooth && (sp[player] < 60))
		drawCBlock(player, c_cblk[player], kosa, (bs[player] * 8 / 60), flash, 1);
	else
		drawCBlock(player, c_cblk[player], kosa, 0, flash, 1);
}

// �u���b�N���Œ肳����
// player  �F �v���C���[�ԍ�
void blockLock(int player) {
	int bottom;
	
	if((statc[player * 10 + 2] != 0) && (repversw >= 7)) return;
	
	// �u���b�N�������I�ɐڒn������
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
		// ����ꐧ��
		if(getPressState(player, 0) && harddrop[player]) up_flag[player] = 1;
		
		// �����ꐧ��
		if(getPressState(player, 1) && softdrop[player]) down_flag[player] = 1;
	}
	
	// �Œ��̏�����
	statc[player * 10 + 2]++;
}

// �Œ莞�ԃ��Z�b�g
// player  �F �v���C���[�ԍ�
// rot     �F 0�ňړ��A1�ŉ�]
void blockLDelayReset(int player, int rot) {
	bk[player] = 0;						// �Œ莞�ԃ��Z�b�g
	bk_D[player] = 0;
	
	if(!rot) {
		kickc[player]++;	// �ڒn������Ԃł̈ړ��񐔂��J�E���g
	} else {
		kickc3[player]++;	// �ڒn������Ԃł̉�]�񐔂��J�E���g
	}
	
	if( ((rot == 0) && (rule_lock_limit[rots[player]] > 0) && (kickc[player] >= rule_lock_limit[rots[player]])) || 
	    ((rot != 0) && (rule_rot_limit[rots[player]] > 0) && (kickc3[player] >= rule_rot_limit[rots[player]])) )
	{
		// �����Œ�
		bk[player] = 100;	// �����Œ�
		blockLock(player);
	} else if(world_move_sound) {
		PlaySE(1);	// �ڒn��
	}
}

// �\�t�g�h���b�v
// player  �F �v���C���[�ԍ�
// locksnd �F �Œ肳�����Ƃ���ace_sonic_lock.wav��炷
void softDrop(int player, int locksnd) {
	int tmp;
	
	if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) {
		// �ڒn���Ă��Ȃ��ꍇ
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
			
			// OLD STYLE���[�h(ARCADE)�ł̓h���b�v�{�[�i�X���Z
			if((gameMode[player] == 9) && (heboGB[player] == 2) && (sp[player] > 1)) {
				sc[player]++;
			}
			
			// SIMPLE/MARATHON���[�h�ł̓h���b�v�{�[�i�X���Z
			if((gameMode[player] == 17) || (isMarathonMode(player))) {
				sc[player]++;
			}
		}
	} else {
		// �ڒn���Ă���ꍇ
		if((rule_soft_lock[rots[player]] == 1) || (heboGB[player])) {
			// ���Œ肠��
			bk[player] = 100;
			if(locksnd) PlaySE(43);
			
			// OLD STYLE���[�h(HANDHELD)�ł̓h���b�v�{�[�i�X���Z
			if((gameMode[player] == 9) && (heboGB[player] == 1)) {
				tmp = qdrop[player];
				if(rule_soft_speed[rots[player]] == 0) tmp = tmp / 2;
				if(rule_soft_speed[rots[player]] == 2) tmp = tmp + (tmp / 2);
				if(rule_soft_speed[rots[player]] == 3) tmp = tmp * 2;
				
				sc[player] = sc[player] + tmp;
			}
		} else if(rule_soft_lock[rots[player]] == 2) {
			// 1G�ȏ�ő��Œ�
			if((sp[player] >= 60) || (heboGB[player])) {
				bk[player] = 100;
				if(locksnd) PlaySE(43);
			} else {
				bk_D[player] = bk_D[player] + 4;
			}
		} else {
			// ���Œ�Ȃ�
			if(wsoftlock != 3) bk[player] = bk[player] + 1 + (wsoftlock == 2);
		}
		
		softdrop[player] = 1;
	}
}

// �n�[�h�h���b�v
// player  �F �v���C���[�ԍ�
// locksnd �F �Œ肳�����Ƃ���ace_sonic_lock.wav��炷
void hardDrop(int player, int locksnd) {
	int dheight, bottom, air;
	
	// �u���b�N����ԉ��܂ŗ��Ƃ�
	if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) {
		air = 1;
		for(bottom = by[player]; judgeBlock(player, bx[player], bottom, blk[player], rt[player]) == 0; bottom++);
		bottom--;
		
		dheight = bottom - by[player];
		sdrop[player] = dheight * 2;
		
		if(!block_afterimage || heboGB[player]) {
			by[player] = bottom;
		} else {
			// �c��
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
	
	// SIMPLE/MARATHON���[�h�ł̓h���b�v�{�[�i�X���Z
	if((gameMode[player] == 17) || (isMarathonMode(player))) {
		sc[player] = sc[player] + (dheight * 2);
	}
	
	if(rule_hard_lock[rots[player]]) {
		// ���Œ肠��
		bk[player] = 100;
		
		if(locksnd) {
			if(air) PlaySE(1);
			PlaySE(43);
		}
	} else if(air) {
		// ���Œ�Ȃ�
		PlaySE(1);
		bs[player] = 0;
		bk[player] = 0;
		bk_D[player] = 0;
	}
	
	harddrop[player] = 1;
}

// ARS�̕ǏR��
// ��]�ɐ��������1�A���s�����0���߂�l�ɂȂ�܂��B
// player  �F �v���C���[�ԍ�
// bak     �F ��]�������
// ext_rot �F 1�ɂ���Ƃs���E�o���w�{���X�_�ǏR�肪�L��
int wallkickARS(int player, int bak, int ext_rot) {
	int i, move;
	
	move = 0;
	
	// ��]�ł��Ȃ��Ƃ��́A���E�ɓ������Ă݂悤�i�w�{���X�_�ȊO�j
	if( (blk[player] != 0) && (judgeBlockRotate(player, bx[player], by[player], blk[player], bak) != 0) ) {
		// BIG�̏ꍇ��2�u���b�N�����ׂ�
		for(i = 0; i <= IsBig[player]; i++) {
			if(judgeBlock(player, bx[player] - 1 - i, by[player], blk[player], bak) == 0)
				move = -1 - i;
			if(judgeBlock(player, bx[player] + 1 + i, by[player], blk[player], bak) == 0)
				move = 1 + i;
			
			// �ǏR����s
			if(move) {
				bx[player] = bx[player] + move;
				rt[player] = bak;
				return 1;
			}
		}
	}
	
	// �s���̒E�o�i1�񂾂��j
	if( (blk[player] == 4) && (ext_rot) && (!kickc2[player]) && (bak == 2) ) {
		// BIG�̏ꍇ��2�u���b�N�����ׂ�
		for(i = 0; i <= IsBig[player]; i++) {
			if(judgeBlock(player, bx[player], by[player] - 1 - i, blk[player], bak) == 0) {
				by[player] = by[player] - 1 - i;
				rt[player] = bak;
				kickc2[player]++;
				bk[player] = 0;	// �Œ莞�ԃ��Z�b�g
				bk_D[player] = 0;
				return 1;
			}
		}
	}
	
	// �w�{���X�_�̕ǏR��
	if( (blk[player] == 0) && (ext_rot) && ((bak == 0) || (bak == 2)) ) {
		// BIG�̏ꍇ��3�u���b�N�����ׂ�
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
		
		// �ǏR����s
		if(move) {
			bx[player] = bx[player] + move;
			rt[player] = bak;
			return 1;
		}
	}
	
	// �w�{���X�_�̏��R��i1�񂾂��A�ڒn���Ă���ꍇ�̂݁j
	if( (blk[player] == 0) && (ext_rot) && (!kickc2[player]) && ((bak == 1) || (bak == 3)) && 
	    (judgeBlock(player, bx[player], by[player] + 1, blk[player], bak) != 0) )
	{
		// BIG�̏ꍇ��3�u���b�N�����ׂ�
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
		
		// �ǏR����s
		if(move) {
			by[player] = by[player] + move;
			rt[player] = bak;
			kickc2[player]++;
			bk[player] = 0;	// �Œ莞�ԃ��Z�b�g
			bk_D[player] = 0;
			return 1;
		}
	}
	
	return 0;
}

// SRS�̕ǏR��
// ��]�ɐ��������1�A���s�����0���߂�l�ɂȂ�܂��B
// player  �F �v���C���[�ԍ�
// bak     �F ��]�������
// move    �F -1�ō���]�A1�ŉE��]�A2��180�x��]
int wallkickSRS(int player, int bak, int move) {
	int i;
	int sx[11], sy[11];
	
	if(move == 2) {
		// 180�x��]
		if(blk[player] != 0) {	// I�ȊO�̎�
			for(i = 0; i < 11; i++) {
				sx[i] = otherBlock180KickTable[ (i * 2) + (rt[player] * 22) ];
				sy[i] = otherBlock180KickTable[ (i * 2) + (rt[player] * 22) + 1];
			}
		} else {				// I�̎�
			for(i = 0; i < 11; i++) {
				sx[i] = iBlock180KickTable[ (i * 2) + (rt[player] * 22) ];
				sy[i] = iBlock180KickTable[ (i * 2) + (rt[player] * 22) + 1 ];
			}
		}
	} else {
		// ���ʉ�]
		if(blk[player] != 0) {	// I�ȊO�̎�
			for(i = 0; i < 4; i++) {
				sx[i] = otherBlockKickTable[ (i * 2) + (rt[player] * 8) + ((move > 0) * 32) ];
				sy[i] = otherBlockKickTable[ (i * 2) + (rt[player] * 8) + ((move > 0) * 32) + 1 ];
			}
		} else {				// I�̎�
			for(i = 0; i < 4; i++) {
				sx[i] = iBlockKickTable[ (i * 2) + (rt[player] * 8) + ((move > 0) * 32) ];
				sy[i] = iBlockKickTable[ (i * 2) + (rt[player] * 8) + ((move > 0) * 32) + 1 ];
			}
		}
	}
	
	// BIG�̏ꍇ�͕␳��2�{
	if(IsBig[player]) {
		for(i = 0; i < 4 + ((move == 2) * 7); i++) {
			sx[i] = sx[i] * 2;
			sy[i] = sy[i] * 2;
		}
	}
	
	// �ǏR����s
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

// DRS�̕ǏR��
// ��]�ɐ��������1�A���s�����0���߂�l�ɂȂ�܂��B
// player  �F �v���C���[�ԍ�
// bak     �F ��]�������
// move    �F -1�ō���]�A1�ŉE��]�A2��180�x��]
int wallkickDRS(int player, int bak, int move) {
	int i, hosei_type, y_hosei;
	
	//�␳�^�C�v�����߂�@���΂̃{�^���������Ă���΃^�C�v�t�]
	if(move > 0)
		hosei_type = 1 - 0 * getPressState(player, 4);	// R
	else
		hosei_type = 0 + 1 * getPressState(player, 5);	// L
	
	move = 0;
	y_hosei = 0;
	
	for(i = 0; i <= IsBig[player]; i++) {
		// ���D�� �D��x�̒Ⴂ�ړ����璲�ׂ�
		if(!hosei_type) {
			// �E��
			if(judgeBlock(player, bx[player] + 1 + i, by[player] + 1 + i, blk[player], bak) == 0) {
				move = 1 + i;
				y_hosei = 1 + i;
			}
			// ����
			if(judgeBlock(player, bx[player] - 1 - i, by[player] + 1 + i, blk[player], bak) == 0) {
				move = -1 - i;
				y_hosei = 1 + i;
			}
			// ��
			if(judgeBlock(player, bx[player]        , by[player] + 1 + i, blk[player], bak) == 0) {
				move = 0;
				y_hosei = 1 + i;
			}
			// �E
			if(judgeBlock(player, bx[player] + 1 + i, by[player]    , blk[player], bak) == 0) {
				move = 1 + i;
				y_hosei = 0;
			}
			// ��
			if(judgeBlock(player, bx[player] - 1 - i, by[player]    , blk[player], bak) == 0) {
				move = -1 - i;
				y_hosei = 0;
			}
		}
		
		// �E�D��
		if(hosei_type) {
			// ����
			if(judgeBlock(player, bx[player] - 1 - i, by[player] + 1 + i, blk[player], bak) == 0) {
				move = -1 - i;
				y_hosei = 1 + i;
			}
			// �E��
			if(judgeBlock(player, bx[player] + 1 + i, by[player] + 1 + i, blk[player], bak) == 0) {
				move = 1 + i;
				y_hosei = 1 + i;
			}
			// ��
			if(judgeBlock(player, bx[player]        , by[player] + 1 + i, blk[player], bak) == 0) {
				move = 0;
				y_hosei = 1 + i;
			}
			// ��
			if(judgeBlock(player, bx[player] - 1 - i, by[player]    , blk[player], bak) == 0) {
				move = -1 - i;
				y_hosei = 0;
			}
			// �E
			if(judgeBlock(player, bx[player] + 1 + i, by[player]    , blk[player], bak) == 0) {
				move = 1 + i;
				y_hosei = 0;
			}
		}
		
		// �ǏR����s
		if(move || y_hosei) {
			rt[player] = bak;
			bx[player] = bx[player] + move;
			
			if(y_hosei) {
				PlaySE(1);
				by[player] = by[player] + y_hosei;
				bk[player] = 0;		// �Œ莞�ԃ��Z�b�g
				bk_D[player] = 0;
			}
			
			return 1;
		}
	}
	
	// �s���̒E�o�i1�񂾂��j
	if( (blk[player] == 4) && (drs_floorkick) && (!kickc2[player]) && (bak == 2) ) {
		// BIG�̏ꍇ��2�u���b�N�����ׂ�
		for(i = 0; i <= IsBig[player]; i++) {
			if(judgeBlock(player, bx[player], by[player] - 1 - i, blk[player], bak) == 0) {
				by[player] = by[player] - 1 - i;
				rt[player] = bak;
				kickc2[player]++;
				bk[player] = 0;	// �Œ莞�ԃ��Z�b�g
				bk_D[player] = 0;
				return 1;
			}
		}
	}
	
	// �w�{���X�_�̏��R��i1�񂾂��A�ڒn���Ă���ꍇ�̂݁j
	if( (blk[player] == 0) && (drs_floorkick) && (!kickc2[player]) && 
	    (judgeBlock(player, bx[player], by[player] + 1, blk[player], bak) != 0) )
	{
		// BIG�̏ꍇ��3�u���b�N�����ׂ�
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
		
		// �ǏR����s
		if(move) {
			by[player] = by[player] + move;
			rt[player] = bak;
			kickc2[player]++;
			bk[player] = 0;	// �Œ莞�ԃ��Z�b�g
			bk_D[player] = 0;
			return 1;
		}
	}
	
	return 0;
}
