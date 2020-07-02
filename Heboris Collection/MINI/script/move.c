//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.04 - �u���b�N�ړ���
//������������������������������������������������������������������������������
void statMove(int player) {
	int param, temp;
	
	param = 0;
	executePlugin(player, 6, &param);	// �v���O�C���Ăяo��
	if(param) return;
	
	hiddenProc(player);
	
	// ����ꐧ���������ꐧ������
	if( !getPressState(player, 0) || (!downtype) || ((downtype == 1) && (!is20G(player)) && (are[player] != 0)) )
		up_flag[player] = 0;
	if( !getPressState(player, 1) || (!downtype) || ((downtype == 1) && (!is20G(player)) && (are[player] != 0)) )
		down_flag[player] = 0;
	
	if(!statc[player * 10 + 1]) {
		// �z�[���h
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
		// �z�[���h�����̍ŏ��̃t���[��
		else if(!statc[player * 10 + 0]) {
			if(subMoveInit(player, 0)) return;
		}
		
		// �u���b�N�ړ�����
		subMoveMain(player);
		
		// �Œ肵���u�Ԃ̏���
		if( ((lockflash[player] == 0) || (engineVer >= 12)) && (statc[player * 10 + 1] != 0) ) subMoveLock(player);
	} else {
		// �Œ肵���u�Ԃ̏���
		subMoveLock(player);
	}
}

// �ŏ���1�t���[���^�z�[���h���ɍs���鏈��
// �u���b�N���߂荞��ł���ꍇ�͖߂�l��1�ɂȂ�
int subMoveInit(int player, int ishold) {
	int i, temp;
	int param[2];
	
	param[0] = 0;
	param[1] = ishold;
	executePlugin(player, 7, &param);	// �v���O�C���Ăяo��
	if(param[0]) return param[0] - 1;
	
	// �ʏ�^����z�[���h
	if((!ishold) || (hold[player] == -1)) {
		// �z�[���h�u���b�N��ݒ�
		if(ishold) {
			if(!statc[player * 10 + 0]) {
				// ��s�z�[���h
				hold[player] = getNextBlock(player, 0);
				for(i = 0; i < 4; i++) hold_color[i + player * 4] = next_color[player * 24 + i];
				hold_oblk[player] = next_oblk[player * 6];
				if(enable_item_hold[player]) hold_item[player] = next_item[player * 6];
				else hold_item[player] = 0;
				nextc[player] = (nextc[player] + 1) % nextc_max[player];
				setNextBlockColor(player, 0);
			} else {
				// �ʏ�z�[���h
				hold[player] = blk[player];
				for(i = 0; i < 4; i++) hold_color[i + player * 4] = current_color[i + player * 4];
				hold_oblk[player] = current_oblk[player];
				if(enable_item_hold[player]) hold_item[player] = current_item[player];
				else hold_item[player] = 0;
			}
			hold_count[player]++;
			dhold[player] = 1;
		}
		
		// ���݂̃u���b�N��ݒ�
		blk[player] = getNextBlock(player, 0);
		for(i = 0; i < 4; i++) {
			current_color[i + player * 4] = next_color[player * 24 + i];
			current_color_m[i + player * 4] = next_color[player * 24 + i];
		}
		current_oblk[player] = next_oblk[player * 6];
		current_item[player] = next_item[player * 6];
		
		// NEXT�𓮂���
		nextc[player] = (nextc[player] + 1) % nextc_max[player];
		setNextBlockColor(player, 0);
	}
	// �z�[���h2��ڈȍ~
	else {
		if(!statc[player * 10 + 0]) {
			// ��s�z�[���h
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
			// �ʏ�z�[���h
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
	
	executePlugin(player, 19, &param);	// �v���O�C���Ăяo��
	
	// �����ʒu�Ȃǂ�ݒ�
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
	
	// �A�C�e�����݂̃`�F�b�N
	scanItem(player);
	
	// NEXT�x��
	if((spawntype[player]) && (!is20G(player)) && (are[player] != 0)) ndelay[player] = 0;
	
	// ��s���ړ�
	if(fastlrmove[player]) initialMove(player);
	
	// ��s��]
	if(initial_rotate[player]) initialRotate(player);
	
	// �u���b�N���߂荞��ł�����Q�[���I�[�o�[
	if(judgeBlock(player, bx[player], by[player], blk[player], rt[player])) {
		setBlock(player, bx[player], by[player], blk[player], rt[player]);
		stat[player] = 7;
		resetStatc(player);
		return 1;
	} else if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player])) {
		PlaySE(se_kon);
	}
	
	statc[player * 10 + 3] = 1;	// 2��ڈȍ~�Ɏ��s����Ƃ���1�ɂȂ�
	return 0;
}

// ��s���ړ�
void initialMove(int player) {
	int move;
	
	// �L�[���͂��擾���Ĉړ�������ݒ�
	move = getPressState(player, 3) - getPressState(player, 2);
	
	// 2�}�X�P�ʂ�BIG�ł͈ړ��ʂ�2�{�ɂ���
	if(IsBig[player] && BigMove[player]) move = move * 2;
	
	if(judgeBlock(player, bx[player] + move, by[player], blk[player], rt[player]) == 0) {
		// �ړ�����
		if(move_sound) PlaySE(se_move);
		bx[player] = bx[player] + move;
	} else {
		// �ړ����s
		PlaySE(se_movefail);
	}
}

// ��s��]
void initialRotate(int player) {
	int move, bak;
	
	// ��]���������߂�
	if(!rot_reverse[player])
		move = (getPressState(player, 5) || getPressState(player, 8)) - (getPressState(player, 4) || getPressState(player, 6));
	else
		move = (getPressState(player, 4) || getPressState(player, 6)) - (getPressState(player, 5) || getPressState(player, 8));
	
	// 180�x��]
	if(getPressState(player, 8) && !disable180) move = 2;
	
	if(move) {
		PlaySE(se_shaki);
		
		bak = rt[player] + move;
		
		if(move == 2) {
			// 180�x��]
			if(bak > 3) bak = bak - 4;
			if(bak < 0) bak = bak + 4;
		} else {
			// ���ʉ�]
			if(bak < 0) bak = 3;
			if(bak > 3) bak = 0;
		}
		
		if(judgeBlock(player, bx[player], by[player], blk[player], bak) == 0) {
			// ��]����
			if(rotate_sound) PlaySE(se_rotate);
			brotcount[player]++;
			rt[player] = bak;
		} else {
			// ��]���s
			PlaySE(se_rotfail);
		}
	}
}

// �u���b�N�ړ�����
void subMoveMain(int player) {
	int i, j, k, move, bak, bottom, allowmove, kosa, temp, rolling, lockdelay, cwaitt;
	int param;
	
	param = 0;
	executePlugin(player, 8, &param);	// �v���O�C���Ăяo��
	if(param) return;
	
	// �u���b�N�𑀍삵�Ă��鎞��+1
	bactivetime[player]++;
	
	if(!statc[player * 10 + 0]) allowmove = 0;
	else allowmove = 1;
	
	if(speedtype[player] == 0) {
		bs[player] = bs[player] + sp[player];
		if((spawntype[player]) && (sp[player] >= 1200)) bs[player] = 1320;	// �g�O�o������20G
	} else if(speedtype[player] == 1) {
		bs[player]++;
	} else if(speedtype[player] == 2) {
		bs[player] = bs[player] + sp[player];
		if((spawntype[player]) && (sp[player] >= 5120)) bs[player] = 5632;	// �g�O�o������20G
	}
	
	if((softd_score[player] > 0) && (engineVer >= 13)) {
		qdrop[player] = qdrop[player] + softd_score[player];
	}
	
	softd_dropflag[player] = 0;
	softd_score[player] = 0;
	
	statc[player * 10 + 0]++;
	
	if(allowmove) {
		// ���[�����[������
		rolling = 0;
		if((current_rollroll[player] != 0) && (rollroll_interval[player] != 0)) {
			if(recTimer[player] % rollroll_interval[player] == 0)
				rolling = 1;
		}
		
		// ��]
		if(!rot_reverse[player])
			move = (getPushState(player, 5) || getPushState(player, 8) || rolling) - (getPushState(player, 4) || getPushState(player, 6));
		else
			move = (getPushState(player, 4) || getPushState(player, 6) || rolling) - (getPushState(player, 5) || getPushState(player, 8));
		
		// 180�x��]
		if(getPushState(player, 8) && !disable180) move = 2;
		
		if(move) {
			bak = rt[player] + move;
			
			if(move == 2) {
				// 180�x��]
				if(bak > 3) bak = bak - 4;
				if(bak < 0) bak = bak + 4;
			} else {
				// ���ʉ�]
				if(bak < 0) bak = 3;
				if(bak > 3) bak = 0;
			}
			
			// �ڒn��Ԃ��ǂ����`�F�b�N
			k = judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]);
			
			if(judgeBlock(player, bx[player], by[player], blk[player], bak) == 0) {
				// �ǂɏd�Ȃ炸�ɉ�]
				j = 0;
				rt[player] = bak;
			} else if(enable_wallkick[player]) {
				// �ǏR��
				j = 1;
				if(wallKick(player, bak, move)) {
					rt[player] = bak;
				}
			}
			
			if(rt[player] == bak) {
				// ��]����
				if(rotate_sound) PlaySE(se_rotate);
				last_command[player] = 1 + j + ((k != 0) * 2);	// �Ō�̑���
				bk_D[player] = 0;
				brotcount[player]++;
				
				if(k) {
					rotcount[player]++;
					resetLockDelay(player);
				}
			} else {
				// ��]���s
				PlaySE(se_rotfail);
			}
		}
		
		// ���E�Ɉړ�
		move = getPressState(player, 3) - getPressState(player, 2);
		if(IsBig[player] && BigMove[player]) move = move * 2;
		
		if(move) {
			// �ڒn��Ԃ��ǂ����`�F�b�N
			k = judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]);
			
			if(max_waitt[player] < waitt[player]) cwaitt = max_waitt[player];
			else cwaitt = waitt[player];
			
			if((mpc[player] == 1) || (mpc[player] >= cwaitt)) {
				if((repeatcount[player] < RepeatDelay[player]) && (RepeatDelay[player] > 0) && (mpc[player] >= cwaitt)) {
					// RepeatDelay
					repeatcount[player]++;
				} else if(judgeBlock(player, bx[player] + move, by[player], blk[player], rt[player]) == 0) {
					// �ړ�����
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
					// �ړ����s
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
	
	// �n�ʂɂ�������
	if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0) {
		bs[player] = 0;
		if( (lockdelay < 99) && ((allowmove) || (engineVer <= 11)) ) bk[player]++;
		
		// ���L�[
		if((!move) && (getPressState(player, 1)) && (allowmove)) softDrop(player, 0);
		
		// ��L�[
		if((!move) && (getPressState(player, 0)) && (allowmove)) hardDrop(player, bottom);
		
		// �Œ�
		if(bk[player] >= lockdelay) {
			blockLock(player);
			return;
		}
	}
	// ��
	else {
		// �S�[�X�g�u���b�N
		drawGBlock(player, bottom);
		
		if(allowmove) {
			// ���L�[
			if((!move) && (getPressState(player, 1))) softDrop(player, 1);
			
			// ��L�[
			if((!move) && (getPressState(player, 0))) hardDrop(player, bottom);
		}
	}
	
	// �u���b�N��������
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
		
		// ���ɋ󔒂�����ꍇ�͗���
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
		
		// �n�ʂɂ�������
		if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0) {
			bs[player] = 0;
			bfallcount[player]++;
			if( (lockdelay < 99) && ((allowmove) || (engineVer <= 11)) ) bk[player]++;
			PlaySE(se_kon);
			
			// ���L�[
			if((!move) && (getPressState(player, 1)) && (allowmove)) softDrop(player, 2);
			
			// ��L�[
			if((!move) && (getPressState(player, 0)) && (allowmove)) hardDrop(player, bottom);
			
			// �Œ�
			if(bk[player] >= lockdelay) {
				PlaySE(se_kon);
				blockLock(player);
				return;
			}
		}
	}
	
	// �u���b�N��`��
	if((bk[player] >= lockdelay - 1) && (!IsBig[player])) {
		kosa = 12;
	} else {
		kosa = bk[player] * 7 / (lockdelay + (lockdelay == 0));
		if(kosa > 6) kosa = 6;
	}
	drawCBlock(player, kosa, 0);
}

// �\�t�g�h���b�v
void softDrop(int player, int type) {
	int param[2], temp;
	
	param[0] = 0;
	param[1] = type;
	executePlugin(player, 48, &param);
	if(param[0]) return;
	
	if(down_flag[player]) return;
	if(lock_down[player] == 6) return;
	
	if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) {
		// ��
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
		// �ڒn
		if(lock_down[player] == 1) {
			// ���Œ�
			bk[player] = 100;
		} else if(lock_down[player] == 2) {
			// �������Œ�1
			bk[player]++;
		} else if(lock_down[player] == 3) {
			// �������Œ�2
			bk[player] = bk[player] + 2;
		} else if(lock_down[player] == 4) {
			// 1G�ȏ�ŌŒ�
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
			// �n�ʂŉ����������Ƃ������Œ�
			bk[player] = 100;
		}
		if((bk[player] >= 100) && (engineVer >= 2)) qput[player] = 1;
		if((bk[player] >= 100) && (self_lock_sound[player])) PlaySE(se_self_lock);
		softdrop[player] = 1;
	}
}

// �n�[�h�h���b�v
void hardDrop(int player, int bottom) {
	int temp, param[2];
	
	param[0] = 0;
	param[1] = bottom;
	executePlugin(player, 49, &param);
	if(param[0]) return;
	
	if(up_flag[player]) return;
	if(lock_up[player] == 2) return;
	
	if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) {
		// ��
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
		// �ڒn
		if(lock_up[player] == 1) {
			bk[player] = 100;
			if(engineVer >= 2) qput[player] = 1;
			if(self_lock_sound[player]) PlaySE(se_self_lock);
		}
		harddrop[player] = 1;
	}
}

// �Œ莞�ԃ��Z�b�g
// �K��񐔃I�[�o�[�̏ꍇ�͖߂�l��1
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

// �u���b�N���Œ肳����
void blockLock(int player) {
	int bottom;
	
	if(statc[player * 10 + 1]) return;
	
	// ���݂̃u���b�N�������I�ɐڒn������
	for(bottom = by[player]; judgeBlock(player, bx[player], bottom, blk[player], rt[player]) == 0; bottom++);
	bottom--;
	by[player] = bottom;
	
	// NEXT�x������
	ndelay[player] = 1;
	
	// ���ʉ���炷
	PlaySE(se_kachi);
	
	// ����ꉺ����t���OON
	if(harddrop[player] && getPressState(player, 0)) up_flag[player] = 1;
	if(softdrop[player] && getPressState(player, 1)) down_flag[player] = 1;
	
	// �u���b�N��`��
	if(engineVer <= 11) drawCBlock(player, 6, 0);
	
	// �u���b�N���Œ肵���u�Ԃ̏�����
	statc[player * 10 + 1] = 1;
}

// �ǏR��
// ��������Ɩ߂�l��1
int wallKick(int player, int bak, int move) {
	int param[3];
	param[0] = 0;
	param[1] = bak;
	param[2] = move;
	executePlugin(player, 9, &param);	// �v���O�C���Ăяo��
	return param[0];
}

// �u���b�N���Œ肵���u�Ԃ̏���
void subMoveLock(int player) {
	int i, temp, param;
	
	statc[player * 10 + 2]++;
	drawCBlock(player, 0, 1);
	
	// HOLD�g�p�\��
	if(dhold[player] == 1) dhold[player] = 0;
	
	if(statc[player * 10 + 2] >= lockflash[player]) {
		// �J�E���^������
		resetStatc(player);
		
		// T-SPIN����
		if((last_command[player] >= 3) && (blk[player] == 4))
			tspin_flag[player] = isTSpin(player);
		
		// �u���b�N�ݒu
		bdowncnt[player]++;
		if(setBlock(player, bx[player], by[player], blk[player], rt[player])) {
			// �g�O�o���̂Ƃ���1���u���b�N��g���ɒu���Ȃ������瑦��
			if(spawntype[player]) {
				stat[player] = 7;
				return;
			}
		}
		
		// ���C���������邩�ǂ�������
		temp = blockEraseJudge(player);
		
		if(temp) {
			// ���C����������
			stat[player] = 6;	// �u���b�N������
			
			// LINE CLEAR��T-SPIN����
			if((tspin_type[player] == 1) && (last_command[player] >= 3) && (blk[player] == 4))
				tspin_flag[player] = 1;
			
			statEraseBlock(player);
		} else {
			// ���C�������Ȃ�
			param = 0;
			executePlugin(player, 60, &param);
			if(param) return;
			
			combo[player] = 0;
			combo2[player] = 0;
			combo3[player] = 0;
			hebocombo[player] = 0;
			if(engineVer <= 5) cmbpts[player] = 0;
			else cmbpts[player] = 1;
			
			// ���C�������Ȃ���T-SPIN�������Ƃ�
			if(tspin_flag[player]) executePlugin(player, 59, &dummy);
			
			pinchCheck(player);
			
			stat[player] = 5;	// �҂����ԏ�����
			statc[player * 10] = wait1[player] - lockflash[player];
			statErase(player);
		}
	}
}

// T-SPIN����iIMMOBILE/3-CORNER/3-CORNER NO KICK�j
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
