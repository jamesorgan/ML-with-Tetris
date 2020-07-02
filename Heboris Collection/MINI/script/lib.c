//������������������������������������������������������������������������������
//   �t�B�[���h�����Z�b�g
//������������������������������������������������������������������������������
void resetField(int player) {
	int i, j;
	
	for(i = 0; i < fldsizey; i++) {
		for(j = 0; j < fldsizex; j++) {
			setFieldBlock(player, j, i, 0);
			setFieldBlockT(player, j, i, 0);
			setFieldBlockO(player, j, i, 0);
			setFieldBlockL(player, j, i, 0);
			setFieldBlockI(player, j, i, 0);
		}
		erase[i + player * fldsizey] = 0;
	}
}

//������������������������������������������������������������������������������
//   �t�B�[���h�^�C�}�[�����i�S�u���b�N��������悤�ɂ���j
//������������������������������������������������������������������������������
void disableShadowTimer(int player) {
	int i, j;
	
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++) {
			if(getFieldBlock(player, j, i) != 0)
				setFieldBlockT(player, j, i, -1);
		}
}

//������������������������������������������������������������������������������
//   �X�e�[�^�X�J�E���^���Z�b�g
//������������������������������������������������������������������������������
void resetStatc(int player) {
	int i;
	for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
}

//������������������������������������������������������������������������������
//   NEXT�u���b�N�̐F��ݒ�
//������������������������������������������������������������������������������
void setNextBlockColor(int player, int first) {
	int i, j, block, color;
	
	if(!dispnext) return;
	
	if(first) {
		// �S�Ẵu���b�N�̐F��ݒ�
		for(i = 0; i < 6; i++) {
			block = getNextBlock(player, i);
			
			for(j = 0; j < 4; j++) next_color[player * 24 + i * 4 + j] = blockcolor[player * 7 + block];
			next_oblk[player * 6 + i] = oblk_spawn[player];
			next_item[player * 6 + i] = 0;
			
			// �}���`�J���[�u���b�N
			if(multicolor_enable[player]) {
				for(j = 0; j < 4; j++) {
					if(GiziRand(player, 100) < multicolor_ratio[player]) {
						color = next_color[player * 24 + i * 4 + j];
						
						do {
							next_color[player * 24 + i * 4 + j] = GiziRand(player, 7) + 1;
						} while(color == next_color[player * 24 + i * 4 + j]);
					}
				}
			}
		}
	} else {
		// �F�����炷
		for(i = 0; i < dispnext - 1; i++) {
			for(j = 0; j < 4; j++) next_color[player * 24 + i * 4 + j] = next_color[player * 24 + (i + 1) * 4 + j];
			next_oblk[player * 6 + i] = next_oblk[player * 6 + i + 1];
			next_item[player * 6 + i] = next_item[player * 6 + i + 1];
		}
		
		// ��ԍŌ�̃u���b�N�̐F��ݒ�
		block = getNextBlock(player, dispnext - 1);
		for(j = 0; j < 4; j++) next_color[player * 24 + (dispnext - 1) * 4 + j] = blockcolor[player * 7 + block];
		next_oblk[player * 6 + dispnext - 1] = oblk_spawn[player];
		next_item[player * 6 + dispnext - 1] = item_coming[player];
		item_coming[player] = 0;
		
		// �}���`�J���[�u���b�N
		if(multicolor_enable[player]) {
			for(j = 0; j < 4; j++) {
				if(GiziRand(player, 100) < multicolor_ratio[player]) {
					color = next_color[player * 24 + (dispnext - 1) * 4 + j];
					
					do {
						next_color[player * 24 + (dispnext - 1) * 4 + j] = GiziRand(player, 7) + 1;
					} while(color == next_color[player * 24 + (dispnext - 1) * 4 + j]);
				}
			}
		}
	}
}

//������������������������������������������������������������������������������
//   NEXT�u���b�N���擾
//������������������������������������������������������������������������������
int getNextBlock(int player, int offset) {
	int temp;
	
	temp = nextc[player] + offset;
	if(temp >= nextc_max[player]) temp = temp - nextc_max[player];
	
	return nextb[player * 1400 + temp];
}

//������������������������������������������������������������������������������
//   �s���`���ǂ����`�F�b�N
//������������������������������������������������������������������������������
void pinchCheck(int player) {
	int i, j, param, blocks;
	
	param = 0;
	executePlugin(player, 65, &param);
	if(param) return;
	
	pinch[player] = 0;
	
	if(engineVer >= 8) {
		blocks = checkHowManyBlocks(player);
		
		if((blocks >= ((fldsizex * fldsizey) - 70)) && (((fldsizex * fldsizey) - 70) > 0)) {
			pinch[player] = 1;
		}
	} else {
		for(i = 0; i <= 7; i++)
			for(j = 2; j <= 7; j++)
				if(fld[j + i * 7 + player * 220]) {
					pinch[player] = 1;
					return;
				}
	}
}

//������������������������������������������������������������������������������
//   �S�����`�F�b�N
//������������������������������������������������������������������������������
int isBravo(int player) {
	int i, j;
	
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++)
			if(getFieldBlock(player, j, i) != 0) return 0;
	
	return 1;
}

//������������������������������������������������������������������������������
//   ���݂̃X�s�[�h��20G���ǂ�������
//������������������������������������������������������������������������������
int is20G(int player) {
	if((speedtype[player] == 0) && (sp[player] >= 1200)) return 1;
	if((speedtype[player] == 2) && (sp[player] >= 5120)) return 1;
	return 0;
}

//������������������������������������������������������������������������������
//   �\������A�C�e����������
//������������������������������������������������������������������������������
void scanItem(int player) {
	int i, j;
	
	item_name[player] = 0;
	
	// �t�B�[���h�𒲂ׂ�
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++)
			if((getFieldBlockI(player, j, i) != 0) && (getFieldBlockI(player, j, i) < fldihardno)) {
				item_name[player] = getFieldBlockI(player, j, i);
			}
	
	// �z�[���h�𒲂ׂ�
	if((hold_item[player] != 0) && (hold_item[player] < fldihardno))
		item_name[player] = hold_item[player];
	
	// NEXT�𒲂ׂ�
	for(i = 0; i < 6; i++)
		if((next_item[i + player * 6] != 0) && (next_item[i + player * 6] < fldihardno)) {
			item_name[player] = next_item[i + player * 6];
		}
	
	// ���݂̃u���b�N�𒲂ׂ�
	if((current_item[player] != 0) && (current_item[player] < fldihardno))
		item_name[player] = current_item[player];
}

//������������������������������������������������������������������������������
//   �t�B�[���h�ォ�炷�ׂẴA�C�e��������
//������������������������������������������������������������������������������
void cleanupItem(int player) {
	int i, j;
	
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++)
			if((getFieldBlockI(player, j, i) != 0) && (getFieldBlockI(player, j, i) < fldihardno)) {
				setFieldBlockI(player, j, i, 0);
			}
}

//������������������������������������������������������������������������������
//   �u���b�N�̌q����f�[�^����������
//������������������������������������������������������������������������������
void makeBlockLinkData(int player) {
	int i, j;
	int kind, rotate;
	int bx, by, bx2, by2;
	int linkdata;
	
	for(kind = 0; kind < 7; kind++)
		for(rotate = 0; rotate < 4; rotate++)
			for(i = 0; i < 4; i++) {
				// ����X�ʒu�Ƒ���Y�ʒu
				bx = blkDataX[kind * 16 + rotate * 4 + player * 112 + i];
				by = blkDataY[kind * 16 + rotate * 4 + player * 112 + i];
				
				// ����3�̃u���b�N�Ƃ̌q����𒲂ׂ�
				linkdata = 0;
				for(j = 0; j < 4; j++) {
					if(j != i) {
						bx2 = blkDataX[kind * 16 + rotate * 4 + player * 112 + j];
						by2 = blkDataY[kind * 16 + rotate * 4 + player * 112 + j];
						
						if((bx == bx2) && (by - 1 == by2)) linkdata = BitSet(linkdata, 0, 1);	// ��
						if((bx == bx2) && (by + 1 == by2)) linkdata = BitSet(linkdata, 1, 1);	// ��
						if((by == by2) && (bx - 1 == bx2)) linkdata = BitSet(linkdata, 2, 1);	// ��
						if((by == by2) && (bx + 1 == bx2)) linkdata = BitSet(linkdata, 3, 1);	// �E
					}
				}
				
				// �q����f�[�^����
				blkDataL[kind * 16 + rotate * 4 + player * 112 + i] = linkdata;
			}
}

//������������������������������������������������������������������������������
//   �p�b�h���s�[�g���͏���
//������������������������������������������������������������������������������
void padRepeat(int player) {
	int param;
	param = 0;
	executePlugin(player, 61, &param);
	if(param) return;
	
	if(getPressState(player, 2) && getPressState(player, 3)) {
		mp[player] = 0;
		mpc[player] = 0;
	} else if(getPressState(player, 2)) {
		if(mp[player] != 2) {
			mp[player] = 2;
			mpc[player] = 0;
		}
		mpc[player]++;
	} else if(getPressState(player, 3)) {
		if(mp[player] != 3) {
			mp[player] = 3;
			mpc[player] = 0;
		}
		mpc[player]++;
	} else {
		mp[player] = 0;
		mpc[player] = 0;
	}
}

// hoge �㉺���̓o�[�W����
void padRepeat2(int player) {
	if(getPressState(player, 0) && getPressState(player, 1)) {
		mp2[player] = 0;
		mpc2[player] = 0;
	} else if(getPressState(player, 0)) {
		if(mp2[player] != 1) {
			mp2[player] = 1;
			mpc2[player] = 0;
		}
		mpc2[player]++;
	} else if(getPressState(player, 1)) {
		if(mp2[player] != 2) {
			mp2[player] = 2;
			mpc2[player] = 0;
		}
		mpc2[player]++;
	} else {
		mp2[player] = 0;
		mpc2[player] = 0;
	}
}

//������������������������������������������������������������������������������
//   �L�[��Ԃ̎擾
//������������������������������������������������������������������������������
// �����Â�����̃o�[�W����
int getPressState(int player, int key) {
	int param[2];
	param[0] = 0;
	param[1] = key;
	executePlugin(player, 62, &param);
	if(param[0]) return;
	
	if(!maxPlay && player) return 0;
	if(netplay && player) return 0;
	
	if(playback && replayauto) {
		// ���v���C
		if((onRecord[player]) && (recTimer[player] < 60 * 60 * 30) && (!pause[player]))
			return BitTest(replayData[player * 108000 + recTimer[player]], key);
		else
			return 0;
	} else if(cpu_flag[player] && onRecord[player] && !pause[player]) {
		// CPU
		return cpu_ctrl[player * 10 + key];
	} else {
		// �ʏ�
		SelectJoyStick(player);
		
		if(!keyAssign[key + player * 10])
			return IsPressJoyKey(joykeyAssign[key + player * 10]);
		else
			return (IsPressJoyKey(joykeyAssign[key + player * 10]) | IsPressKey(keyAssign[key + player * 10]));
	}
}

// �����Â��Ȃ��̃o�[�W����
int getPushState(int player, int key) {
	int param[2];
	param[0] = 0;
	param[1] = key;
	executePlugin(player, 63, &param);
	if(param[0]) return;
	
	if(!maxPlay && player) return 0;
	if(netplay && player) return 0;
	
	if(playback && replayauto) {
		// ���v���C
		if((onRecord[player]) && (recTimer[player] < 60 * 60 * 30) && (!pause[player]))
			return BitTest(replayData[player * 108000 + recTimer[player]], key + 10);
		else
			return 0;
	} else if(cpu_flag[player] && onRecord[player] && !pause[player]) {
		// CPU
		return cpu_ctrl[player * 10 + key];
	} else {
		// �ʏ�
		SelectJoyStick(player);
		
		if(!keyAssign[key + player * 10])
			return IsPushJoyKey(joykeyAssign[key + player * 10]);
		else
			return (IsPushJoyKey(joykeyAssign[key + player * 10]) | IsPushKey(keyAssign[key + player * 10]));
	}
}

// ����̃v���C���[�̃W���C�X�e�B�b�N���͂����o����֐��c�̂��� #LITE25
// �����Ɠ������͕s��
int getJoyPressState(int player, int key) {
	if(!maxPlay && player) return 0;
	if(netplay && player) return 0;
	SelectJoyStick(player);
	return IsPressJoyKey(key);
}

int getJoyPushState(int player, int key) {
	if(!maxPlay && player) return 0;
	if(netplay && player) return 0;
	SelectJoyStick(player);
	return IsPushJoyKey(key);
}

//������������������������������������������������������������������������������
//   �u���b�N�̂����蔻��
//������������������������������������������������������������������������������
int judgeBlock(int player, int bx1, int by1, int kind, int rotate) {
	int i, bx2, by2, temp;
	int param[5];
	param[0] = 0;
	param[1] = bx1;
	param[2] = by1;
	param[3] = kind;
	param[4] = rotate;
	executePlugin(player, 64, &param);
	if(param[0] == 1) return 0;
	if(param[0] == 2) return -1;
	
	// �r�b�O���͐�p����
	if(IsBig[player]) {
		return judgeBigBlock(player, bx1, by1, kind, rotate);
	}
	
	for(i = 0; i < 4; i++) {
		bx2 = bx1 + blkDataX[kind * 16 + rotate * 4 + player * 112 + i];
		by2 = by1 + blkDataY[kind * 16 + rotate * 4 + player * 112 + i];
		
		temp = getFieldBlock(player, bx2, by2);
		if((temp != 0) && (temp != -2)) return -1;
	}
	
	return 0;
}

// �r�b�O�p
int judgeBigBlock(int player, int bx1, int by1, int kind, int rotate) {
	int i, bx2, by2, temp;
	int k, l;
	
	for(i = 0; i < 4; i++) {
		bx2 = (bx1 + blkDataX[kind * 16 + rotate * 4 + player * 112 + i] * 2);
		by2 = (by1 + blkDataY[kind * 16 + rotate * 4 + player * 112 + i] * 2);
		
		// 4�u���b�N�����ׂ�
		for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
			temp = getFieldBlock(player, bx2 + k, by2 + l);
			if((temp != 0) && (temp != -2)) return -1;
		}
	}
	
	return 0;
}

// ARS�n�ŕǏR��ł��邩�ǂ�������
int judgeBlockRotate(int player, int bx1, int by1, int kind, int rotate) {
	int i, xx, bx2, by2, temp;
	
	// �r�b�O���͐�p����
	if(IsBig[player]) {
		return judgeBigBlockRotate(player, bx1, by1, kind, rotate);
	}
	
	for(i = 0; i < 4; i++) {
		xx = blkDataX[kind * 16 + rotate * 4 + player * 112 + i];
		
		// �����̗�ȊO���d�Ȃ��Ă���ꍇ�͕ǏR��\
		if(xx != 1) {
			bx2 = bx1 + xx;
			by2 = by1 + blkDataY[kind * 16 + rotate * 4 + i];
			temp = getFieldBlock(player, bx2, by2);
			if((temp != 0) && (temp != -2)) return 1;
		}
	}
	
	return 0;
}

// ARS�n�ŕǏR��ł��邩�ǂ�������i�r�b�O�p�j
int judgeBigBlockRotate(int player, int bx1, int by1, int kind, int rotate) {
	int i, xx, bx2, by2, temp;
	int k, l;
	
	for(i = 0; i < 4; i++) {
		xx = blkDataX[kind * 16 + rotate * 4 + player * 112 + i];
		
		// �����̗�ȊO���d�Ȃ��Ă���ꍇ�͕ǏR��\
		if(xx != 1) {
			bx2 = (bx1 + xx * 2);
			by2 = (by1 + blkDataY[kind * 16 + rotate * 4 + i] * 2);
			
			// 4�u���b�N�����ׂ�
			for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
				temp = getFieldBlock(player, bx2 + k, by2 + l);
				if((temp != 0) && (temp != -2)) return 1;
			}
		}
	}
	
	return 0;
}

//������������������������������������������������������������������������������
//   �u���b�N��ݒu����
//������������������������������������������������������������������������������
int setBlock(int player, int bx1, int by1, int kind, int rotate) {
	int i, bx2, by2, puted, linkdata;
	puted = 0;
	
	// �r�b�O���͐�p����
	if(IsBig[player]) {
		return setBigBlock(player, bx1, by1, kind, rotate);
	}
	
	for(i = 0; i < 4; i++) {
		bx2 = bx1 + blkDataX[kind * 16 + rotate * 4 + player * 112 + i];
		by2 = by1 + blkDataY[kind * 16 + rotate * 4 + player * 112 + i];
		if(by2 >= 2) puted++;	// �g���ɒu�������{�P
		linkdata = blkDataL[kind * 16 + rotate * 4 + player * 112 + i];
		
		setFieldBlock(player, bx2, by2, current_color[i + player * 4] + 1);
		setFieldBlockT(player, bx2, by2, shadowtime[player]);
		setFieldBlockO(player, bx2, by2, current_oblk[player]);
		setFieldBlockL(player, bx2, by2, linkdata);
		setFieldBlockI(player, bx2, by2, current_item[player]);
	}
	
	if(!puted) return 1;
	
	return 0;
}

// �r�b�O�p
int setBigBlock(int player, int bx1, int by1, int kind, int rotate) {
	int i, bx2, by2, puted;
	int k, l, bx3, by3;
	puted = 0;
	
	for(i = 0; i < 4; i++) {
		bx2 = (bx1 + blkDataX[kind * 16 + rotate * 4 + player * 112 + i] * 2);
		by2 = (by1 + blkDataY[kind * 16 + rotate * 4 + player * 112 + i] * 2);
		if(by2 >= 2) puted++;	// �g���ɒu�������{�P
		
		// 4�u���b�N���ݒu����
		for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
			bx3 = bx2 + k;
			by3 = by2 + l;
			
			setFieldBlock(player, bx3, by3, current_color[i + player * 4] + 1);
			setFieldBlockT(player, bx3, by3, shadowtime[player]);
			setFieldBlockO(player, bx3, by3, current_oblk[player]);
			setFieldBlockL(player, bx3, by3, 0);
			setFieldBlockI(player, bx3, by3, current_item[player]);
		}
	}
	
	if(!puted) return 1;
	
	return 0;
}

//������������������������������������������������������������������������������
//   �t�B�[���h�̏�Ԃ��擾
//������������������������������������������������������������������������������
// �t�B�[���h�O��-1
// �t�B�[���h�����-2
int getFieldBlock(int player, int x, int y) {
	if((x < 0) || (x >= fldsizex) || (y >= fldsizey)) return -1;
	if(y < 0) return -2;
	return fld[x + y * fldsizex + player * (fldsizex * fldsizey)];
}

// �t�B�[���h�^�C�}�[�p
int getFieldBlockT(int player, int x, int y) {
	if((x < 0) || (x >= fldsizex) || (y < 0) || (y >= fldsizey)) return 0;
	return fldt[x + y * fldsizex + player * (fldsizex * fldsizey)];
}

// ����c�l�t���O�p
int getFieldBlockO(int player, int x, int y) {
	if((x < 0) || (x >= fldsizex) || (y < 0) || (y >= fldsizey)) return 0;
	return fldo[x + y * fldsizex + player * (fldsizex * fldsizey)];
}

// �u���b�N�̌q����p
int getFieldBlockL(int player, int x, int y) {
	if((x < 0) || (x >= fldsizex) || (y < 0) || (y >= fldsizey)) return 0;
	return fldl[x + y * fldsizex + player * (fldsizex * fldsizey)];
}

// �A�C�e���p
int getFieldBlockI(int player, int x, int y) {
	if((x < 0) || (x >= fldsizex) || (y < 0) || (y >= fldsizey)) return 0;
	return fldi[x + y * fldsizex + player * (fldsizex * fldsizey)];
}

//������������������������������������������������������������������������������
//   �t�B�[���h�̏�Ԃ�����������
//������������������������������������������������������������������������������
void setFieldBlock(int player, int x, int y, int block) {
	if((x >= 0) && (x < fldsizex) && (y >= (spawntype[player] == 0)) && (y < fldsizey)) {
		fld[x + y * fldsizex + player * (fldsizex * fldsizey)] = block;
	}
}

// �t�B�[���h�^�C�}�[�p
void setFieldBlockT(int player, int x, int y, int block) {
	if((x >= 0) && (x < fldsizex) && (y >= (spawntype[player] == 0)) && (y < fldsizey)) {
		fldt[x + y * fldsizex + player * (fldsizex * fldsizey)] = block;
	}
}

// ����c�l�t���O�p
void setFieldBlockO(int player, int x, int y, int block) {
	if((x >= 0) && (x < fldsizex) && (y >= (spawntype[player] == 0)) && (y < fldsizey)) {
		fldo[x + y * fldsizex + player * (fldsizex * fldsizey)] = block;
	}
}

// �u���b�N�̌q����p
void setFieldBlockL(int player, int x, int y, int block) {
	if((x >= 0) && (x < fldsizex) && (y >= (spawntype[player] == 0)) && (y < fldsizey)) {
		fldl[x + y * fldsizex + player * (fldsizex * fldsizey)] = block;
	}
}

// �A�C�e���p
void setFieldBlockI(int player, int x, int y, int block) {
	if((x >= 0) && (x < fldsizex) && (y >= (spawntype[player] == 0)) && (y < fldsizey)) {
		fldi[x + y * fldsizex + player * (fldsizex * fldsizey)] = block;
	}
}

//������������������������������������������������������������������������������
//   �t�B�[���h�̍ŏ�i��Ԃ�
//������������������������������������������������������������������������������
int checkFieldTop(int player) {
	int i, j;
	
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++)
			if(getFieldBlock(player, j, i) != 0) return i;
	
	// ����ۂ̏ꍇ
	return fldsizey;
}

// �t�B�[���h�̍ŏ�i��Ԃ��iX���W���w��ł���o�[�W�����j
int checkFieldTopEx(int player, int j) {
	int i;
	
	for(i = 0; i < fldsizey; i++)
		if(getFieldBlock(player, j, i) != 0) return i;
	
	// ����ۂ̏ꍇ
	return fldsizey;
}

//������������������������������������������������������������������������������
//   �t�B�[���h�̃u���b�N�̐���Ԃ�
//������������������������������������������������������������������������������
int checkHowManyBlocks(int player) {
	int i, j, result;
	result = 0;
	
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++)
			if(getFieldBlock(player, j, i) != 0) result++;
	
	return result;
}

// �v���`�i�u���b�N����������
int checkHowManyPBlocks(int player) {
	int i, j, result;
	result = 0;
	
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++)
			if(getFieldBlock(player, j, i) >= 11) result++;
	
	return result;
}

//������������������������������������������������������������������������������
//   ���i�ʔ���
//������������������������������������������������������������������������������
int checkSecretGrade(int player) {
	int i, j, uhole, umode, result;
	
	if(fldsizex != 10) return -1;
	if(fldsizey != 22) return -1;
	
	uhole = 0;		// ���̈ʒu���������i�ŏ��͍��[�j
	umode = 0;		// 1���ƉE���獶�֌����ړ�
	result = -1;	// ���݂̗��i�ʂ�������
	
	// 9�`S9�܂ł̔���
	for(i = 21; i > 3; i--) {
		for(j = 0; j < 10; j++) {
			// ���܂��Ă���ׂ��ꏊ�����܂��ĂȂ��Ȃ�I��
			if((getFieldBlock(player, j, i) == 0) && (j != uhole)) return result;
		}
		
		// ���̌��̈ʒu�����߂�
		if(!umode) {
			uhole++;
			
			if(uhole > 9) {
				uhole = 8;
				umode = 1;
			}
		} else {
			uhole--;
		}
		
		// ���i�ʏ㏸
		result++;
	}
	
	// GM����
	// ����(X:0 Y:2)�����܂��Ă�����GM
	if(getFieldBlock(player, 0, 2) != 0) {
		result++;
	}
	
	return result;
}

//������������������������������������������������������������������������������
//  �[������
//������������������������������������������������������������������������������
// �V�[�h����
void GiziSRand(int player) {
	randseed[player] = Rand(65536);
	firstseed[player] = randseed[player];
}

// ���������i���v���C�ۑ��Ή��j
int GiziRand(int player, int max) {
	if(max == 0) return 0;
	randseed[player] = ((randseed[player] * 673 + 994) / 10) % 100000;
	return abs(randseed[player]) % max;
}

// ��Βl�����߂�
int abs(int i) {
	if(i < 0) return -i;
	return i;
}

//������������������������������������������������������������������������������
//   �r�b�g���Z
//������������������������������������������������������������������������������
// �ϐ�value��bit�ڂ̃r�b�g�̏�Ԃ𒲂ׂ�
int BitTest(int value, int bit) {
	int i;
	i = (value) & (1 << (bit));
	return (i != 0);
}

// �ϐ�value��bit�ڂ̃r�b�g�̏�Ԃ�ς���
int BitSet(int value, int bit, int status) {
	if(status) {
		value = (value) | (1 << (bit));
	} else {
		value = (value) & (~(1 << (bit)));
	}
	return value;
}
