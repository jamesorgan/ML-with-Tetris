// �őP���T���i�z�[���h�Ȃ��j
void cpu_setBestSpot(int player, int block) {
	cpu_hold[player] = 0;
	cpu_setBestSpot_normal(player, block);
	if(!cpu_best_p[player]) cpu_setBestSpot_recover(player, block);
	if(!cpu_best_p[player]) cpu_setBestSpot_compromise(player, block);
}

// �őP���T���i�z�[���h����j
void cpu_setBestSpotWithHold(int player, int block, int hblock) {
	int clv[2], bak[4];
	
	// �ʏ�u���b�N
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
	
	// ���ʂ��o�b�N�A�b�v
	bak[0] = cpu_best_x[player];
	bak[1] = cpu_best_y[player];
	bak[2] = cpu_best_r[player];
	bak[3] = cpu_best_p[player];
	
	// �z�[���h
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
		// �z�[���h���̗p
		cpu_hold[player] = 1;
	} else {
		// �ʏ�u���b�N���̗p
		cpu_hold[player] = 0;
		cpu_best_x[player] = bak[0];
		cpu_best_y[player] = bak[1];
		cpu_best_r[player] = bak[2];
		cpu_best_p[player] = bak[3];
	}
}

// �v�l���[�`���i�m�[�}���j
void cpu_setBestSpot_normal(int player, int block) {
	int i, j, rotate, bottom, point, hole, iblkneed, temp;
	
	cpu_best_x[player] = -3;
	cpu_best_y[player] = 0;
	cpu_best_r[player] = 0;
	cpu_best_p[player] = 0;
	
	for(rotate = 0; rotate < 4; rotate++)
		for(j = -2; j < fldsizex; j++) {
			// ���_��������
			point = 0;
			
			// �t�B�[���h����
			cpu_copyField(player);
			
			// ��𒲂ׂ�
			for(bottom = -2; cpu_judgeBlock(player, j, bottom, block, rotate) == 0; bottom++);
			bottom--;
			
			// �u���b�N��u���Ȃ��Ȃ�p��
			if(cpu_judgeBlock(player, j, bottom, block, rotate) != 0) goto skip;
			
			// �����E�ɕǂ�����Ε]��UP
			if(cpu_judgeBlock(player, j - 1, bottom, block, rotate) != 0) point = point + 1;
			if(cpu_judgeBlock(player, j + 1, bottom, block, rotate) != 0) point = point + 1;
			
			// ���݂̌��Ԃ̐��𐔂���
			hole = cpu_checkHowManyHoles();
			
			// ���݂̃w�{���X�_�̌��̐��𐔂���
			iblkneed = cpu_checkHowManyNeedIblock();
			
			// �u���b�N��u��
			if(cpu_setBlock(player, j, bottom, block, rotate)) goto skip;
			
			// ���ɒu���قǉ��_
			point = point + bottom;
			
			// ���C������
			temp = cpu_doLineErase();
			if(temp == 1) {
				point = point - 1;
			} else {
				point = point + (temp * 10);
			}
			
			// ���Ԃ̐��ɉ����ē_��ς���
			temp = cpu_checkHowManyHoles();
			if(temp > hole) {
				// �V���Ɍ��Ԃ��ł����NG
				goto skip;
			} else if(temp < hole) {
				// �V���ɖ��߂����Ԃ̐��ŉ��_
				point = point + ((hole - temp) * 2);
			}
			
			// �w�{���X�_���K�v�Ȍ��̐��ɉ����ē_��������
			temp = cpu_checkHowManyNeedIblock();
			
			if((iblkneed <= 1) && (temp >= 2)) {
				// 2�ȏ�V���ɂł���ƌ��_
				point = point - (temp - iblkneed);
			} else if(temp < iblkneed) {
				// �������炷�ƃ{�[�i�X
				point = point + ((iblkneed - temp) * 2);
			}
			
			// �őP��̏ꍇ
			if(point > cpu_best_p[player]) {
				cpu_best_x[player] = j;
				cpu_best_y[player] = bottom;
				cpu_best_r[player] = rotate;
				cpu_best_p[player] = point;
			}
			
			skip:
		}
}

// �v�l���[�`���i�Ë��P�j
void cpu_setBestSpot_recover(int player, int block) {
	int i, j, rotate, bottom, point, hole, iblkneed, temp;
	
	cpu_best_x[player] = -3;
	cpu_best_y[player] = 0;
	cpu_best_r[player] = 0;
	cpu_best_p[player] = 0;
	
	for(rotate = 0; rotate < 4; rotate++)
		for(j = -2; j < fldsizex; j++) {
			// ���_��������
			point = 0;
			
			// �t�B�[���h����
			cpu_copyField(player);
			
			// ��𒲂ׂ�
			for(bottom = -2; cpu_judgeBlock(player, j, bottom, block, rotate) == 0; bottom++);
			bottom--;
			
			// �u���b�N��u���Ȃ��Ȃ�p��
			if(cpu_judgeBlock(player, j, bottom, block, rotate) != 0) goto skip;
			
			// �����E�ɕǂ�����Ε]��UP
			if(cpu_judgeBlock(player, j - 1, bottom, block, rotate) != 0) point = point + 1;
			if(cpu_judgeBlock(player, j + 1, bottom, block, rotate) != 0) point = point + 1;
			
			// ���݂̌��Ԃ̐��𐔂���
			hole = cpu_checkHowManyHoles();
			
			// ���݂̃w�{���X�_�̌��̐��𐔂���
			iblkneed = cpu_checkHowManyNeedIblock();
			
			// �u���b�N��u��
			if(cpu_setBlock(player, j, bottom, block, rotate)) goto skip;
			
			// ���ɒu���قǉ��_
			point = point + bottom * 3;
			
			// ���C������
			temp = cpu_doLineErase();
			point = point + (temp * 200);
			
			// ���Ԃ̐��ɉ����ē_��ς���
			temp = cpu_checkHowManyHoles();
			
			if(temp > hole) {
				// �V���Ɍ��Ԃ��ł���ƌ��_
				point = point - ((temp - hole) * 30);
			} else if(temp < hole) {
				// �V���ɖ��߂����Ԃ̐��ŉ��_
				point = point + ((hole - temp) * 10);
			}
			
			// �w�{���X�_���K�v�Ȍ��̐��ɉ����ē_��������
			temp = cpu_checkHowManyNeedIblock();
			
			if(temp > iblkneed) {
				// �V�����������ƌ��_
				point = point - ((temp - iblkneed) * 30);
			} else if(temp < iblkneed) {
				// �������炷�ƃ{�[�i�X
				point = point + ((iblkneed - temp) * 10);
			}
			
			// �őP��̏ꍇ
			if(point > cpu_best_p[player]) {
				cpu_best_x[player] = j;
				cpu_best_y[player] = bottom;
				cpu_best_r[player] = rotate;
				cpu_best_p[player] = point;
			}
			
			skip:
		}
}

// �v�l���[�`���i�Ë��Q�j
void cpu_setBestSpot_compromise(int player, int block) {
	int i, j, rotate, bottom, point, hole, iblkneed, temp;
	
	cpu_best_x[player] = -3;
	cpu_best_y[player] = 0;
	cpu_best_r[player] = 0;
	cpu_best_p[player] = 0;
	
	for(rotate = 0; rotate < 4; rotate++)
		for(j = -2; j < fldsizex; j++) {
			// ���_��������
			point = 0;
			
			// �t�B�[���h����
			cpu_copyField(player);
			
			// ��𒲂ׂ�
			for(bottom = -2; cpu_judgeBlock(player, j, bottom, block, rotate) == 0; bottom++);
			bottom--;
			
			// �u���b�N��u���Ȃ��Ȃ�p��
			if(cpu_judgeBlock(player, j, bottom, block, rotate) != 0) goto skip;
			
			// �����E�ɕǂ�����Ε]��UP
			if(cpu_judgeBlock(player, j - 1, bottom, block, rotate) != 0) point = point + 1;
			if(cpu_judgeBlock(player, j + 1, bottom, block, rotate) != 0) point = point + 1;
			
			// ���݂̌��Ԃ̐��𐔂���
			hole = cpu_checkHowManyHoles();
			
			// ���݂̃w�{���X�_�̌��̐��𐔂���
			iblkneed = cpu_checkHowManyNeedIblock();
			
			// �u���b�N��u��
			if(cpu_setBlock(player, j, bottom, block, rotate)) goto skip;
			
			// ���ɒu���قǉ��_
			point = point + bottom * 5;
			
			// ���C������
			temp = cpu_doLineErase();
			point = point + (temp * 100);
			
			// ���Ԃ̐��ɉ����ē_��ς���
			temp = cpu_checkHowManyHoles();
			
			if(temp > hole) {
				// �V���Ɍ��Ԃ��ł���ƌ��_
				point = point - ((temp - hole) / 2);
			} else if(temp < hole) {
				// �V���ɖ��߂����Ԃ̐��ŉ��_
				point = point + ((hole - temp) * 10);
			}
			
			// �w�{���X�_���K�v�Ȍ��̐��ɉ����ē_��������
			temp = cpu_checkHowManyNeedIblock();
			
			if(temp < iblkneed) {
				// �������炷�ƃ{�[�i�X
				point = point + ((iblkneed - temp) * 5);
			}
			
			// �őP��̏ꍇ
			if(point > cpu_best_p[player]) {
				cpu_best_x[player] = j;
				cpu_best_y[player] = bottom;
				cpu_best_r[player] = rotate;
				cpu_best_p[player] = point;
			}
			
			skip:
		}
}

// �����̃t�B�[���h�𓪂̒��̃t�B�[���h�ɃR�s�[
void cpu_copyField(int player) {
	int i, j;
	
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++)
			cpu_fld[j + i * fldsizex] = getFieldBlock(player, j, i);
}

// ���̒��̃t�B�[���h�̏�Ԃ��擾
int cpu_getFieldBlock(int x, int y) {
	if((x < 0) || (x >= fldsizex) || (y >= fldsizey)) return -1;
	if(y < 0) return -2;
	return cpu_fld[x + y * fldsizex];
}

// ���̒��̃t�B�[���h�̏�Ԃ�����������
void cpu_setFieldBlock(int player, int x, int y, int block) {
	if((x >= 0) && (x < fldsizex) && (y >= (spawntype[player] == 0)) && (y < fldsizey)) {
		cpu_fld[x + y * fldsizex] = block;
	}
}

// �t�B�[���h�̍ŏ�i��Ԃ�
int cpu_checkFieldTop() {
	int i, j;
	
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++) 
			if(cpu_fld[j + i * fldsizex])
				return i;
	
	// ����ۂ̏ꍇ
	return fldsizey;
}

// �t�B�[���h�̍ŏ�i��Ԃ��iX���W���w��ł���o�[�W�����j
int cpu_checkFieldTopEx(int j) {
	int i;
	
	for(i = 0; i < fldsizey; i++)
		if(cpu_fld[j + i * fldsizex])
			return i;
	
	// ����ۂ̏ꍇ
	return fldsizey;
}

// ���Ԃ��󂢂ĂȂ������ׂ�
int cpu_checkHole(int bx1, int by1) {
	if( (by1 + 1 >= 0) && (by1 + 1 < fldsizey) && (cpu_fld[bx1 + (by1 + 1) * fldsizex] == 0) )
	{
		return 1;
	}
	
	return 0;
}

// �t�B�[���h���ɂǂꂮ�炢���Ԃ����邩���ׂ�
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

// ���̃u���b�N�����邩���ׂ�
int cpu_checkHowManyBlocks() {
	int i, j, count;
	count = 0;
	
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++) {
			if(cpu_fld[j + i * fldsizex] != 0) count++;
		}
	
	return count;
}

// �����牽�̃u���b�N������ł��邩���ׂ�
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

// �w�{���X�_���K�v�Ȍ�����������̂����ׂ�
// ���@��
// ���@������ȏ�ԂȂ�K�v�Ɣ��f
// ���@��
int cpu_checkHowManyNeedIblock() {
	int i, j, count_left, count_right, total, by, by2;
	
	count_left = 0;
	count_right = 0;
	total = 0;
	
	for(j = 0; j < fldsizex; j++) {
		by = cpu_checkHoleStart(j);
		by2 = cpu_checkFieldTopEx(j);
		
		for(i = by; i < by2; i++) {
			// �����Ƀu���b�N������i�܂��͒[�j
			if((j == 0) || (cpu_fld[(j - 1) + i * fldsizex] != 0))
				count_left++;
			
			// �E���Ƀu���b�N������
			if((j == 9) || (cpu_fld[(j + 1) + i * fldsizex] != 0))
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

// �����C�������邩���ׂ�
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

// ���C������
int cpu_doLineErase() {
	int i, j, k, l, y, lines, full;
	int eraseflag[22];
	
	lines = 0;
	
	// ���C��������
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
	
	// ��ɂ������u���b�N�����܂ŉ��낷
	y = fldsizey - 1;
	
	for(i = 0; i < fldsizey; i++) {
		if(eraseflag[y]) {
			// �u���b�N��1�i�ォ��R�s�[
			for(k = y; k > 0; k--) {
				for(l = 0; l < fldsizex; l++) {
					cpu_fld[l + k * fldsizex] = cpu_fld[l + (k - 1) * fldsizex];
				}
				eraseflag[k] = eraseflag[(k - 1)];
			}
			
			// ��ԏ���󔒂ɂ���
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

// �u���b�N�̂����蔻��
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

// �u���b�N��ݒu����
int cpu_setBlock(int player, int bx1, int by1, int kind, int rotate) {
	int i, bx2, by2, puted;
	puted = 0;
	
	for(i = 0; i < 4; i++) {
		bx2 = bx1 + blkDataX[kind * 16 + rotate * 4 + player * 112 + i];
		by2 = by1 + blkDataY[kind * 16 + rotate * 4 + player * 112 + i];
		if(by2 >= 2) puted++;	// �g���ɒu�������{�P
		
		cpu_setFieldBlock(player, bx2, by2, 1);
	}
	
	if(!puted) return 1;
	
	return 0;
}

// ������e�����߂�
void cpu_setCtrl(int player) {
	// ������x�点��
	cpu_frame[player]++;
	if(cpu_frame[player] < cpu_speed[player]) return;
	if(cpu_frame[player] >= cpu_speed[player] * 2) cpu_frame[player] = 0;
	
	// �z�[���h
	if(cpu_hold[player]) {
		cpu_ctrl[player * 10 + 7] = 1;
	}
	// ��]
	else if(rt[player] != cpu_best_r[player]) {
		cpu_ctrl[player * 10 + 4] = 1;
	}
	// ���ړ�
	else if(bx[player] > cpu_best_x[player]) {
		if((stat[player] == 4) && (judgeBlock(player, bx[player] - 1, by[player], blk[player], rt[player]) != 0)) {
			// �ǂ�����Ȃ炠����߂�
			if(!up_flag[player]) cpu_ctrl[player * 10 + 0] = 1;
			if((!down_flag[player]) && (lock_down[player] != 0)) cpu_ctrl[player * 10 + 1] = 1;
		} else {
			if((cpu_speed[player] != 0) || (mpc[player] < 2)) cpu_ctrl[player * 10 + 2] = 1;
		}
	}
	// �E�ړ�
	else if(bx[player] < cpu_best_x[player]) {
		if((stat[player] == 4) && (judgeBlock(player, bx[player] + 1, by[player], blk[player], rt[player]) != 0)) {
			// �ǂ�����Ȃ炠����߂�
			if(!up_flag[player]) cpu_ctrl[player * 10 + 0] = 1;
			if((!down_flag[player]) && (lock_down[player] != 0)) cpu_ctrl[player * 10 + 1] = 1;
		} else {
			if((cpu_speed[player] != 0) || (mpc[player] < 2)) cpu_ctrl[player * 10 + 3] = 1;
		}
	}
	// �ݒu
	else {
		if(!up_flag[player]) cpu_ctrl[player * 10 + 0] = 1;
		if((!down_flag[player]) && (lock_down[player] != 0)) cpu_ctrl[player * 10 + 1] = 1;
	}
}
