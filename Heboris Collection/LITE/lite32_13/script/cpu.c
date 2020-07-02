//������������������������������������������������������������������������������
//   �őP���T��
//������������������������������������������������������������������������������
// player�F�v���C���[�ԍ�
// block �F���삷��u���b�N
// mode  �F�Ë����x��
// block2�F���̃u���b�N
// navi�@�F�i�r�Q�[�V�����p���ǂ���
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
	
	// �t�B�[�o�[���͖_�̂�
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
			// ��𒲂ׂ�
			for(bottom = -2; judgeBlock(player, j, bottom, block, rotate) == 0; bottom++);
			bottom--;
			
			point = 0;
			
			if(judgeBlock(player, j, bottom, block, rotate) == 0) {
				// �����E�ɕǂ�����Ε]��UP
				if(judgeBlock(player, j - 1, bottom, block, rotate) != 0) point++;
				if(judgeBlock(player, j + 1, bottom, block, rotate) != 0) point++;
				
				// �u���b�N���ꎞ�I�Ƀt�B�[���h�ɒu��
				cpu_setBlock(player, j, bottom, block, rotate);
				
				for(i = 0; i < 4; i++) {
					getBlockData(player, j, bottom, block, rotate, i, &data);
					bx2 = data[0];
					by2 = data[1];
					
					// �����󂢂Ă��܂��ꍇ��NG
					if(cpu_checkHole(player, bx2, by2)) {
						if(mode != 1) {
							point = 0;
							break;
						} else {
							point = point - 5;
						}
					}
					
					// �����牽�̃u���b�N������ł��邩���ׂ�
					point = point + cpu_checkHowManyBlocksFromLeft(player, by2);
					
					// �S�̂ŉ��̃u���b�N�����邩���ׂ�
					point = point + cpu_checkHowManyBlocks(player, by2);
				}
				
				// �_���K�v�Ȍ��̐���2�ȏ゠��ƌ��_
				tmp = cpu_HowManyNeedIblock(player);
				
				if(tmp >= 2) {
					point = point - tmp * 10;
				}
				
				// �����郉�C�����𒲂ׂ�
				tmp = cpu_checkLineErase(player);
				
				if((tmp >= 2) || (mode == 1) || (pinch[player])) {
					point = point + (tmp * 10) + ((mode == 1) * 10);	// �{�[�i�X
				}
				
				// �u���b�N������
				cpu_removeBlock(player, j, bottom, block, rotate);
				
				// �őP��̏ꍇ
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
			// HOLD����Ƃǂ��Ȃ邩���l����
			if(hold[player] == -1)
				cpu_setBestSpot(player, block2, 2, 0, navi);
			else
				cpu_setBestSpot(player, hold[player], 2, 0, navi);
		} else if((!cpu_best_p[player]) && (!mode) && (!cpu_hold[player])) {
			// �Ë�
			cpu_setBestSpot(player, block, 1, block2, navi);
		}
	}
}

// �����󂢂ĂȂ������ׂ�
int cpu_checkHole(int player, int bx1, int by1) {
	if( ((by1 + 1 >= 0) && (by1 + 1 < 22) && (fld[bx1 + (by1 + 1) * 10 + player * 220] == 0)) ||
		((by1 + 2 >= 0) && (by1 + 2 < 22) && (fld[bx1 + (by1 + 2) * 10 + player * 220] == 0)) )
	{
		return -1;
	}
	
	return 0;
}

// ���̃u���b�N������ł��邩���ׂ�
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

// �����牽�̃u���b�N������ł��邩���ׂ�
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

// �����C�������邩���ׂ�
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

// �w�{���X�_���K�v�Ȍ�����������̂����ׂ�
// ���@��
// ���@������ȏ�ԂȂ�K�v�Ɣ��f
// ���@��
int cpu_HowManyNeedIblock(int player) {
	int i, j, count_left, count_right, total, by, by2;
	
	count_left = 0;
	count_right = 0;
	total = 0;
	
	for(j = 0; j < 10; j++) {
		by = cpu_checkHoleStart(player, j);
		by2 = checkFieldTopEx(player, j);
		
		for(i = by; i < by2; i++) {
			// �����Ƀu���b�N������i�܂��͒[�j
			if((j == 0) || (fld[(j - 1) + i * 10 + player * 220] != 0))
				count_left++;
			
			// �E���Ƀu���b�N������
			if((j == 9) || (fld[(j + 1) + i * 10 + player * 220] != 0))
				count_right++;
		}
		
		if((count_left >= 3) || (count_right >= 3)) total++;	// �_���v��Ɣ��f
		count_left = 0;
		count_right = 0;
	}
	
	return total;
}

// �����n�܂�ʒu��T��
// ���@��
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

//������������������������������������������������������������������������������
//   ������e�����߂�
//������������������������������������������������������������������������������
void cpu_setCtrl(int player) {
	int i, tmp;
	
	// 1�t���[����2��ȏ㑀�삷��̂�h��
	if((time2[player] == cpu_frame[player]) && (repversw >= 4)) {
		return;
	} else {
		cpu_frame[player] = time2[player];
	}
	
	for(i = 0; i < 10; i++) cpu_ctrl[i + player * 10] = 0;
	
	if(stat[player] == 5) tmp = bx[player];
	else tmp = 2 + IsBig[player];
	
	// ���x��4�ȉ��͓�����x�点��
	if(tmp != cpu_best_x[player]) {
		if((cpu_level[player] == 0) && (time2[player] % 10 != 0)) return;
		if((cpu_level[player] == 1) && (time2[player] %  8 != 0)) return;
		if((cpu_level[player] == 2) && (time2[player] %  5 != 0)) return;
		if((cpu_level[player] == 3) && (time2[player] %  2 != 0)) return;
	}
	
	if((rt[player] != cpu_best_r[player]) && (!isRotateLock[player]) && (cpu_level[player] >= 4)) {
		// ���x��5�̉�]
		cpu_ctrl[4 + player * 10] = 1;
	}
	
	if((cpu_best_x[player] == -3) || (cpu_hold[player])) {
		// �����肪�Ȃ��Ȃ�HOLD
		if((!dhold[player]) && (!disable_hold) && (!isholdlock[player])) {
			cpu_ctrl[7 + player * 10] = 1;
		} else {
			cpu_best_x[player] = bx[player];
		}
	} else if((rt[player] != cpu_best_r[player]) && (!isRotateLock[player]) && (cpu_level[player] <= 3)) {
		// ���x��4�܂ł̉�]
		cpu_ctrl[4 + player * 10] = 1;
	} else if(tmp > cpu_best_x[player]) {
		// ��
		cpu_ctrl[2 + player * 10] = 1;
		
		if( ((dhold[player]) || (rule_are[rots[player]] != 1)) && (mpc[player] >= 2) )
			cpu_ctrl[2 + player * 10] = 0;
		
		// �ǂ�����
		if((stat[player] == 5) && (judgeBlock(player, bx[player] - 1, by[player], blk[player], rt[player]) != 0)) {
			cpu_ctrl[2 + player * 10] = 0;
			cpu_ctrl[0 + player * 10] = 1;
			if(!rule_hard_lock[rots[player]]) cpu_ctrl[1 + player * 10] = 1;
		}
	} else if(tmp < cpu_best_x[player]) {
		// ��
		cpu_ctrl[3 + player * 10] = 1;
		
		if( ((dhold[player]) || (rule_are[rots[player]] != 1)) && (mpc[player] >= 2) )
			cpu_ctrl[3 + player * 10] = 0;
		
		// �ǂ�����
		if((stat[player] == 5) && (judgeBlock(player, bx[player] + 1, by[player], blk[player], rt[player]) != 0)) {
			cpu_ctrl[3 + player * 10] = 0;
			cpu_ctrl[0 + player * 10] = 1;
			if(!rule_hard_lock[rots[player]]) cpu_ctrl[1 + player * 10] = 1;
		}
	} else if( ((rt[player] == cpu_best_r[player]) || (isRotateLock[player])) && (!up_flag[player]) ) {
		// �ݒu
		cpu_ctrl[0 + player * 10] = 1;
		if(!rule_hard_lock[rots[player]]) cpu_ctrl[1 + player * 10] = 1;
	}
	
	if(!replayauto) {
		// ���E���씽�]
		if(isLRreverse[player] || isUDLRreverse[player]) {
			tmp = cpu_ctrl[2 + player * 10];
			cpu_ctrl[2 + player * 10] = cpu_ctrl[3 + player * 10];
			cpu_ctrl[3 + player * 10] = tmp;
		}
		
		// �㉺���씽�]
		if(isUDreverse[player] || isUDLRreverse[player]) {
			tmp = cpu_ctrl[0 + player * 10];
			cpu_ctrl[0 + player * 10] = cpu_ctrl[1 + player * 10];
			cpu_ctrl[1 + player * 10] = tmp;
		}
	}
}

//������������������������������������������������������������������������������
//   �u���b�N��ݒu����
//������������������������������������������������������������������������������
void cpu_setBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	int		data[2];
	
	// BIG�̏ꍇ�͐�p����
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

// BIG�p
void cpu_setBigBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	int		k, l, bx3, by3;
	int		data[2];
	
	for(i = 0; i < 4; i++) {
		getBlockData(player, 0, 0, kind, rotate, i, &data);
		bx2 = bx1 + (data[0] * 2);
		by2 = by1 + (data[1] * 2);
		
		/* 4�u���b�N���ݒu���� */
		for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
			bx3 = bx2 + k;
			by3 = by2 + l;
			
			if( ( bx3 >= 0 ) && ( bx3 <= 9 ) && ( by3 >= 0 ) && ( by3 < 22 ) ) {
				fld[bx3 + by3 * 10 + player * 220] = 1;
			}
		}
	}
}

//������������������������������������������������������������������������������
//   �u���b�N����������
//������������������������������������������������������������������������������
void cpu_removeBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	int		data[2];
	
	// BIG�̏ꍇ�͐�p����
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

// BIG�p
void cpu_removeBigBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	int		k, l, bx3, by3;
	int		data[2];
	
	for(i = 0; i < 4; i++) {
		getBlockData(player, 0, 0, kind, rotate, i, &data);
		bx2 = bx1 + (data[0] * 2);
		by2 = by1 + (data[1] * 2);
		
		/* 4�u���b�N������ */
		for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
			bx3 = bx2 + k;
			by3 = by2 + l;
			
			if( ( bx3 >= 0 ) && ( bx3 <= 9 ) && ( by3 >= 0 ) && ( by3 < 22 ) ) {
				fld[bx3 + by3 * 10 + player * 220] = 0;
			}
		}
	}
}
