//VS-ENDLESS
//prefix:vse

// �G�̍s���X�s�[�h�e�[�u��
int vseEnemySpeedTableWait1[20] = {60,55,50,45,40,35,30,25,20,15,10, 5, 5, 5, 5, 4, 3, 2, 1, 0};
int vseEnemySpeedTableWait2[20] = {40,40,40,40,40,35,35,35,35,35,30,25,20,15, 5, 4, 3, 2, 1, 0};

// ���x���A�b�v�e�[�u��
int vseLevelTable[20] =		// �������x
{
	   1,   3,  15,  30,  60, 120, 180, 240, 300, 300,1200,1200,1200,1200,1200,1200,1200,1200,1200,1200
};
int vseWait1[20] =		// �Œ聨��
{
	  26,  26,  26,  26,  26,  26,  26,  26,  26,  26,  15,  11,  11,  11,  11,  10,   9,   5,   3,   2
};
int vseWait2[20] =		// �u���b�N����
{
	  40,  40,  40,  30,  30,  25,  25,  25,  25,  25,  20,  15,  12,  10,   6,   5,   4,   3,   3,   3
};
int vseWait3[20] =		// �ڒn���Œ�
{
	  28,  28,  28,  26,  26,  26,  26,  26,  25,  25,  25,  23,  23,  23,  20,  20,  18,  18,  14,  11
};
int vseWaitt[20] =		// ������
{
	  15,  15,  15,  15,  15,  15,  15,  15,  15,  15,  10,   9,   9,   8,   8,   7,   7,   7,   7,   7
};

// �ϐ�
int vseModeNo = -1;				// ���[�h�ԍ�
int vseGraphicsHeboFldSmall;	// �������t�B�[���h�摜

int vseEnemyStat;				// �G�̏��
int vseEnemyNextc;				// �G�̎��ɍ~��u���b�N�J�E���^
int vseEnemyWait;				// �G�����ɍs������܂ł̎���
int vseEnemyHold;				// �G��HOLD�u���b�N
int vseEnemyLevel;				// �G�̃��x��

int vseScore;					// �X�R�A
int vseLines;					// ���C����
int vseTotalAttack;				// �G�ɑ���������オ��u���b�N�̐�
int vseWin;						// �G��|������

int vseGHole[2];				// ����オ��u���b�N�̌��̈ʒu

int vseTSpinFrame;				// T-SPIN�\���^�w�{���X�\���̎c�莞��
int vseTSpinLine;				// �Ō��T-SPIN���C�������^�w�{���X�����̎��
int vseTSpinWall;				// �ǏR�肠���T-SPIN��������1�ɂȂ�
int vseComboFrame;				// �R���{���\���̎c�莞��
int vseB2BFrame;				// Back To Back�\���̎c�莞��
int vseScoreGet;				// ���������X�R�A�\���̓_��
int vseScoreFrame;				// ���������X�R�A�\���̎c�莞��

int vseTSpin = 3;				// T-SPIN�̎��
int vseEnableCombo = 1;			// �R���{�{�[�i�X�̗L��
int vseEnableB2B = 1;			// Back To Back�̗L���i0=�Ȃ� 1=�ʏ� 2=�w�{���X�̂� 3=T-SPIN�̂݁j
int vseGhost = 1;				// �S�[�X�g�̐ݒ�
int vseStartLevel = 0;			// �X�^�[�g���̃��x��

// �����L���O�p�ϐ�
int vseRankingScore[10];		// �X�R�A
int vseRankingLines[10];		// ���C��
int vseRankingAttack[10];		// �U����
int vseRankingWin[10];			// ������
int vseRankingLevel[10];		// ���x��
int vseRankingTime[10];			// �^�C��
int vseRankingYear[10];			// �����N�C�������i�N�j
int vseRankingMonth[10];		// �����N�C�������i���j
int vseRankingDay[10];			// �����N�C�������i���j
int vseRankingHour[10];			// �����N�C�������i���j
int vseRankingMinute[10];		// �����N�C�������i���j
int vseRankingSecond[10];		// �����N�C�������i�b�j

// �C�x���g����
void vsePluginEvent(int player, int event, int *param) {
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�^�摜�ǂݍ��݃^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (event != 56) && (gameMode[player] != vseModeNo)) return;
	
	if(event == 0) {
		// ���[�h��o�^����
		vseModeNo = addModePlugin("VS-ENDLESS");
	} else if(event == 56) {
		// �������t�B�[���h�摜��ǂݍ���
		vseGraphicsHeboFldSmall = loadGraphics(3, "hebofld_small.png");
		SetColorKeyRGB(vseGraphicsHeboFldSmall, 255, 0, 255);
	} else if(event == 8) {
		vseSoftDropScore(player);	// �\�t�g�h���b�v�œ������_�������Z
	} else if(event == 12) {
		vseCalcScorePlayer(player, param[0]);	// ���C������
	} else if(event == 15) {
		vseViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		vseSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		vsePlayerInitial(player);	// ������
	} else if(event == 21) {
		vseResult(player);	// ���ʕ\��
	} else if(event == 27) {
		vseIncrementTime(player);	// �^�C���𑝉�������i�G�̍s�������s�j
	} else if(event == 30) {
		vseViewEnemyField(player);	// �G�̃t�B�[���h��\��
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		vseSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		vseLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		vseLoadBGM();	// BGM�ǂݍ���
	} else if(event == 48) {
		vseSoftDropOld(player);	// �\�t�g�h���b�v�i���j
	} else if(event == 49) {
		vseHardDrop(player, param[1]);	// �n�[�h�h���b�v
	} else if(event == 55) {
		vseReplayDetail();	// ���v���C�ڍ�
	} else if(event == 59) {
		vseTSpinZero(player);	// ���C�������Ȃ���T-SPIN
	} else if(event == 69) {
		vseUpLineProcPlayer(player);	// ����オ��i�v���C���[���j
	}
}

// ������
void vsePlayerInitial(int player) {
	int i;
	
	// �G�̕ϐ���������
	vseEnemyStat = 0;
	vseEnemyNextc = -1;
	vseEnemyWait = 0;
	vseEnemyHold = -1;
	vseEnemyLevel = vseStartLevel;
	
	// 2P�̃t�B�[���h�����Z�b�g
	resetField(1);
	
	// 1P�̃u���b�N�f�[�^��2P�ɃR�s�[
	for(i = 0; i < 112; i++) {
		blkDataX[112 + i] = blkDataX[i];
		blkDataY[112 + i] = blkDataY[i];
	}
	
	// �������2P�ɃR�s�[
	firstseed[1] = firstseed[0];
	randseed[1] = randseed[0];
	
	// ���̈ʒu��ݒ�
	vseGHole[0] = GiziRand(0, 10);
	vseGHole[1] = GiziRand(1, 10);
	
	// ���̑��̕ϐ���������
	vseScore = 0;
	vseLines = 0;
	vseTotalAttack = 0;
	vseWin = 0;
	vseGHole[player] = 0;
	vseTSpinFrame = 0;
	vseTSpinLine = 0;
	vseTSpinWall = 0;
	vseComboFrame = 0;
	vseB2BFrame = 0;
	vseScoreGet = 0;
	vseScoreFrame = 0;
	
	bgmlv = 10;
	tspin_type[player] = vseTSpin;
	enable_combo[player] = vseEnableCombo;
	b_to_b_type[player] = vseEnableB2B;
	if(!vseGhost) ghost[player] = 0;
	backno = vseStartLevel;
	
	sp[player] = vseLevelTable[vseEnemyLevel];
	vseWait1[player] = vseWait1[vseEnemyLevel];
	vseWait2[player] = vseWait2[vseEnemyLevel];
	vseWait3[player] = vseWait3[vseEnemyLevel];
	vseWaitt[player] = vseWaitt[vseEnemyLevel];
}

// �G�̃t�B�[���h��\��
void vseViewEnemyField(int player) {
	int i, j, fi, dx, dy;
	
	// �w�i
	ExBltFastRect(sg_black, foffset[player] + 108, fyoffset[player] + 124, 0, 0, 40, 80);
	
	// �u�����u���b�N
	for(i = 1; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++) {
			fi = getFieldBlock(1, j, i);
			
			if(fi > 0) {
				// �u���b�N��`��
				dx = foffset[player] + 108 + (j * 4);
				dy = fyoffset[player] + 116 + (i * 4);
				
				drawSBlock(player, dx, dy, fi - 1, 0, 2, 0, 0);
			}
		}
	
	// �g
	ExBltRect(vseGraphicsHeboFldSmall, foffset[player] + 104, fyoffset[player] + 120, framecolor[player] * 48, 0, 48, 92);
}

// �^�C���𑝉�������i�G�̍s�������s�j
void vseIncrementTime(int player) {
	int i, j, block, block2, temp;
	
	if(onRecord[player]) {
		vseEnemyWait++;
		
		if(vseEnemyStat == 0) {
			// ����オ��
			if(vseEnemyWait == 1) {
				temp = vseUpLineProcEnemy(1);
				
				if(temp) {
					vseEnemyStat = 4;
					vseEnemyWait = 0;
				}
			}
			// �u���b�N�ݒu
			else if(vseEnemyWait >= vseEnemySpeedTableWait1[vseEnemyLevel]) {
				block = getNextBlock(0, vseEnemyNextc);
				block2 = getNextBlock(0, vseEnemyNextc + 1);
				
				if(vseEnemyHold == -1)
					cpu_setBestSpotWithHold(1, block, block2);
				else
					cpu_setBestSpotWithHold(1, block, vseEnemyHold);
				
				if(!cpu_hold[1]) {
					i = block;
				} else {
					if(vseEnemyHold == -1) {
						i = block2;
						vseEnemyHold = block;
						vseEnemyNextc = (vseEnemyNextc + 1) % nextc_max[0];
					} else {
						i = vseEnemyHold;
						vseEnemyHold = block;
					}
				}
				
				temp = vseSetEnemyBlock(cpu_best_x[1], cpu_best_y[1], i, cpu_best_r[1]);
				vseEnemyNextc = (vseEnemyNextc + 1) % nextc_max[0];
				
				if(temp) {
					vseEnemyStat = 4;
				} else if(blockEraseJudge(1)) {
					vseEnemyStat = 1;
				} else {
					combo[1] = 0;
				}
				vseEnemyWait = 0;
			}
		} else if(vseEnemyStat == 1) {
			// ���C�������̍ŏ�
			temp = 0;
			for(i = 0; i < fldsizey; i++) {
				if(erase[i + fldsizey]) {
					temp++;
					for(j = 0; j < fldsizex; j++) {
						setFieldBlock(1, j, i, 0);
					}
				}
			}
			PlaySE(se_erase[temp - 1]);
			combo[1]++;
			vseCalcScoreEnemy(1, temp);
			vseEnemyStat = 2;
		} else if(vseEnemyStat == 2) {
			// ���C��������̑҂�����
			if(vseEnemyWait >= vseEnemySpeedTableWait2[vseEnemyLevel]) {
				vseEnemyStat = 3;
			}
		} else if(vseEnemyStat == 3) {
			// �����Ă���u���b�N�𗎂Ƃ�
			temp = downFloatingBlocks(1);
			PlaySE(se_gon);
			vseEnemyStat = 0;
			vseEnemyWait = 0;
		} else if(vseEnemyStat == 4) {
			// ���S�����u��
			PlaySE(se_cheer);
			PlaySE(se_rankup);
			
			vseScore = vseScore + (vseEnemyLevel + 1) * 5000;
			vseScoreGet = (vseEnemyLevel + 1) * 5000;
			vseScoreFrame = 120;
			
			vseWin++;
			if(vseEnemyLevel < 19) {
				vseEnemyLevel++;
				
				bgfadesw = 1;
				bgfadebg = vseEnemyLevel;
				
				sp[player] = vseLevelTable[vseEnemyLevel];
				vseWait1[player] = vseWait1[vseEnemyLevel];
				vseWait2[player] = vseWait2[vseEnemyLevel];
				vseWait3[player] = vseWait3[vseEnemyLevel];
				vseWaitt[player] = vseWaitt[vseEnemyLevel];
			}
			
			vseEnemyStat = 5;
			vseEnemyWait = 0;
		} else if(vseEnemyStat == 5) {
			// ���S���畜��
			for(j = 0; j < fldsizex; j++) {
				setFieldBlock(1, j, vseEnemyWait, 0);
			}
			
			if(vseEnemyWait >= fldsizey - 1) {
				resetField(1);
				vseEnemyStat = 0;
				vseEnemyWait = 0;
			}
		}
	}
}

// �G�̃u���b�N��u��
void vseSetEnemyBlock(int bx1, int by1, int kind, int rotate) {
	int i, bx2, by2, dead;
	dead = 0;
	
	for(i = 0; i < 4; i++) {
		bx2 = bx1 + blkDataX[kind * 16 + rotate * 4 + i];
		by2 = by1 + blkDataY[kind * 16 + rotate * 4 + i];
		if(by2 < 2) dead++;	// �g���͂ݏo����
		
		setFieldBlock(1, bx2, by2, blockcolor[kind] + 1);
	}
	
	if(dead) return 1;
	
	return 0;
}

// �X�R�A�\��
void vseViewScore(int player) {
	int color;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// �^�C��
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
	
	// �X�R�A
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "SCORE");
	sprintf(string[0], "%d", vseScore);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// �����������_
	if(vseScoreFrame > 0) {
		vseScoreFrame--;
		sprintf(string[0], "%d", vseScoreGet);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 58, string[0], (count % 4 / 2) * (1 + (b_to_b_count[player] != 0)));
	}
	
	// ������
	printTinyFont2(foffset[player] + 96, fyoffset[player] + 68, "WIN");
	sprintf(string[0], "%d", vseWin);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 76, string[0], color);
	
	// �G�̃��x��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 88, "LEVEL");
	sprintf(string[0], "%d", vseEnemyLevel + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 96, string[0], color);
	
	// T-SPIN
	if(vseTSpinFrame > 0) {
		vseTSpinFrame--;
		
		if((vseTSpinLine == 0) && (vseTSpinWall))
			printTinyFont(foffset[player] + 25, fyoffset[player] + 208, "EZ T-SPIN");
		else if((vseTSpinLine == 0) && (!vseTSpinWall))
			printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "T-SPIN");
		else if((vseTSpinLine == 1) && (vseTSpinWall))
			printTinyFont(foffset[player] + 20, fyoffset[player] + 208, "T-SPIN MINI");
		else if((vseTSpinLine == 1) && (!vseTSpinWall))
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN SINGLE");
		else if(vseTSpinLine == 2)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN DOUBLE");
		else if(vseTSpinLine == 3)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN TRIPLE");
		else if(vseTSpinLine == 4)
			printTinyFont(foffset[player] + 30, fyoffset[player] + 208, "HEBORIS");
	}
	
	// ����オ�萔
	if(upLines[player]) {
		sprintf(string[0], "%d LINE UP", upLines[player]);
		printTinyFontB(foffset[player] + 25, fyoffset[player] + 200, string[0]);
	}
	// BACK TO BACK
	else if(vseB2BFrame > 0) {
		vseB2BFrame--;
		printTinyFont(foffset[player] + 18, fyoffset[player] + 200, "BACK TO BACK");
	}
	// COMBO
	else if((vseComboFrame > 0) && (combo[player] >= 2)) {
		vseComboFrame--;
		sprintf(string[0], "COMBO %d", combo[player] - 1);
		printTinyFont(foffset[player] + 30, fyoffset[player] + 200, string[0]);
	}
	
	// �G�̂���オ�萔
	if(upLines[1]) {
		sprintf(string[0], "%d LINE UP", upLines[1]);
		printTinyFontB(foffset[player] + 105, fyoffset[player] + 113, string[0]);
	}
}

// ���C�������i�v���C���[���j
void vseCalcScorePlayer(int player, int lines) {
	int bo, points, b2b, combopts, temp;
	
	bo = 0;
	points = 0;
	b2b = 0;
	combopts = 0;
	
	// T-SPIN��
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		vseTSpinFrame = 60;
		vseTSpinLine = lines;
		vseTSpinWall = (last_command[player] == 4);
		
		if(lines == 1) {
			// T-SPIN Single
			bo = 2;
			if(vseTSpinWall) points = 2;
			else points = 8;
		}
		if(lines == 2) {
			// T-SPIN Double
			bo = 4;
			points = 12;
		}
		if(lines == 3) {
			// T-SPIN Triple
			bo = 6;
			points = 16;
		}
	}
	// ���ʂ̃��C������
	else {
		if(lines == 1) {
			bo = 0;
			points = 1;
		}
		if(lines == 2) {
			bo = 1;
			points = 3;
		}
		if(lines == 3) {
			bo = 2;
			points = 5;
		}
		if(lines == 4) {
			vseTSpinFrame = 60;
			vseTSpinLine = lines;
			bo = 4;
			points = 8;
		}
	}
	
	// B2B�{�[�i�X�i+1�j
	if(b_to_b_count[player] >= 2) {
		bo = bo + 1;
		b2b = 1;
		vseB2BFrame = 60;
	} else {
		b2b = 0;
		vseB2BFrame = 0;
	}
	
	// �R���{�{�[�i�X
	if(combo[player] >= 2) {
		combopts = (combo[player] - 1) * 50;
		
		if(combo[player] >= 12) bo = bo + 5;
		else if(combo[player] >= 9) bo = bo + 4;
		else if(combo[player] >= 7) bo = bo + 3;
		else if(combo[player] >= 5) bo = bo + 2;
		else if(combo[player] >= 3) bo = bo + 1;
		
		vseComboFrame = 60;
	}
	
	// �S�����{�[�i�X
	if(isBravo(player)) {
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		bo = bo * 2;
		vseScore = vseScore + 5000;
	}
	
	// �X�R�A���Z
	temp = (points * 100) * (vseEnemyLevel + 1);
	vseScore = vseScore + temp + ((temp / 2) * b2b) + combopts;
	vseScoreGet = temp + ((temp / 2) * b2b) + combopts;
	vseScoreFrame = 120;
	
	// ���C�������Z
	vseLines = vseLines + lines;
	
	// ���E
	upLines[player] = upLines[player] - bo;
	
	// ����ɂ�����܃u���b�N�𑗂�
	if(upLines[player] < 0) {
		upLines[1 - player] = upLines[1 - player] + abs(upLines[player]);
		upLines[player] = 0;
	}
	vseTotalAttack = vseTotalAttack + bo;
}

// ���C�������i�G���j
void vseCalcScoreEnemy(int player, int lines) {
	int bo;
	
	if(lines == 1) bo = 0;
	if(lines == 2) bo = 1;
	if(lines == 3) bo = 2;
	if(lines == 4) bo = 4;
	
	// B2B�{�[�i�X�i+1�j
	if((lines >= 4) && (vseEnableB2B)) {
		b_to_b_count[player]++;
	} else {
		b_to_b_count[player] = 0;
	}
	
	if(b_to_b_count[player] >= 2) {
		bo = bo + 1;
	}
	
	// �R���{�{�[�i�X
	if((combo[player] >= 2) && (vseEnableCombo)) {
		if(combo[player] >= 12) bo = bo + 5;
		else if(combo[player] >= 9) bo = bo + 4;
		else if(combo[player] >= 7) bo = bo + 3;
		else if(combo[player] >= 5) bo = bo + 2;
		else if(combo[player] >= 3) bo = bo + 1;
	}
	
	// �S�����{�[�i�X
	if(isBravo(player)) {
		bo = bo * 2;
	}
	
	// ���E
	upLines[player] = upLines[player] - bo;
	
	// ����ɂ�����܃u���b�N�𑗂�
	if(upLines[player] < 0) {
		upLines[1 - player] = upLines[1 - player] + abs(upLines[player]);
		upLines[player] = 0;
	}
}

// ����オ��i�v���C���[���j
void vseUpLineProcPlayer(int player) {
	int i, temp;
	
	// ���̈ʒu��ς���
	i = GiziRand(player, 10);
	if(i >= 7) {
		temp = vseGHole[player];
		
		do {
			vseGHole[player] = GiziRand(player, 10);
		} while(vseGHole[player] == temp);
	}
	
	// ����オ��u���b�N�쐬
	for(i = 0; i < 10; i++) fldu[i + player * 220] = (i != vseGHole[player]);
}

// ����オ��i�G���j
int vseUpLineProcEnemy(int player) {
	int i, j, temp, dead;
	
	dead = 0;
	
	while(upLines[player] > 0) {
		// ���̈ʒu��ς���
		i = GiziRand(player, 10);
		if(i >= 7) {
			temp = vseGHole[player];
			
			do {
				vseGHole[player] = GiziRand(player, 10);
			} while(vseGHole[player] == temp);
		}
		
		// �t�B�[���h����ɂ��炷
		for(i = 0; i < fldsizey - 1; i++) {
			for(j = 0; j < fldsizex; j++) {
				temp = getFieldBlock(player, j, i + 1);
				if((i < 2) && (temp != 0)) dead = 1;
				setFieldBlock(player, j, i, temp);
			}
		}
		
		// ����オ��u���b�N�쐬
		for(i = 0; i < fldsizex; i++) {
			if(i != vseGHole[player])
				setFieldBlock(player, i, fldsizey - 1, 1);
			else
				setFieldBlock(player, i, fldsizey - 1, 0);
		}
		
		upLines[player]--;
	}
	
	return dead;
}

// �\�t�g�h���b�v�i���j
void vseSoftDropOld(int player) {
	if((!down_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) && (engineVer <= 12)) {
		if((speedtype[player] == 1) || (sp[player] < (softspeed[player] + 1) * 30)) {
			vseScore++;
		}
	}
}

// �n�[�h�h���b�v
void vseHardDrop(int player, int bottom) {
	if((!up_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0)) {
		vseScore = vseScore + (bottom - by[player]) * 2;
	}
}

// �\�t�g�h���b�v�œ������_�������Z
void vseSoftDropScore(int player) {
	if(softd_score[player] > 0) {
		vseScore = vseScore + softd_score[player];
	}
}

// ���C�������Ȃ���T-SPIN
void vseTSpinZero(int player) {
	PlaySE(se_tspin);
	vseTSpinFrame = 60;
	vseTSpinLine = 0;
	
	// �ǏR�肠��
	if(last_command[player] == 4) {
		vseScore = vseScore + 100 * (vseEnemyLevel + 1);
		vseTSpinWall = 1;
		
		vseScoreGet = 100 * (vseEnemyLevel + 1);
		vseScoreFrame = 120;
	}
	// �ǏR��Ȃ�
	else {
		vseScore = vseScore + 400 * (vseEnemyLevel + 1);
		vseTSpinWall = 0;
		
		vseScoreGet = 400 * (vseEnemyLevel + 1);
		vseScoreFrame = 120;
	}
}

// BGM�ǂݍ���
void vseLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(10);
	}
}

// ���ʕ\��
void vseResult(int player) {
	// �����L���O�o�^
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = vseRegistRanking(player);
		if(statc[player * 10 + 1] != -1) vseSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 45, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 59, "SCORE");
	sprintf(string[0], "%13d", vseScore);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 67, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", vseLines);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "TOTAL ATTACK");
	sprintf(string[0], "%13d", vseTotalAttack);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[0], 0);
	
	printTinyFont2(foffset[player] + 8, fyoffset[player] + 119, "WIN");
	sprintf(string[0], "%13d", vseWin);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 139, "LEVEL");
	sprintf(string[0], "%13d", vseEnemyLevel + 1);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 147, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 159, "TIME");
	getTime(gameTimer[player]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[1], 0);
	
	if(statc[player * 10 + 1] != -1) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 179, "RANK");
		sprintf(string[0], "%13d", statc[player * 10 + 1] + 1);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 187, string[0], 0);
	}
}

// �ݒ���
void vseSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(vseLoadConfig() == 0) vseSaveConfig();
	
	// �����L���O��ǂݍ���
	if(vseLoadRanking(player) == 0) vseInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "VS-ENDLESS OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "T-SPIN",       7 * (cursor == 0));
		printFontGrid(2, 4, "COMBO",        7 * (cursor == 1));
		printFontGrid(2, 5, "BACK TO BACK", 7 * (cursor == 2));
		printFontGrid(2, 6, "GHOST BLOCK",  7 * (cursor == 3));
		printFontGrid(2, 7, "START LEVEL",  7 * (cursor == 4));
		
		// �ݒ�l�\��
		if(vseTSpin == 0) sprintf(string[0], "OFF");
		else if(vseTSpin == 1) sprintf(string[0], "LINE CLEAR");
		else if(vseTSpin == 2) sprintf(string[0], "IMMOBILE");
		else if(vseTSpin == 3) sprintf(string[0], "3-CORNER");
		else sprintf(string[0], "3-CORNER NO KICK");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!vseEnableCombo) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(vseEnableB2B == 0) sprintf(string[0], "OFF");
		else if(vseEnableB2B == 1) sprintf(string[0], "ON");
		else if(vseEnableB2B == 2) sprintf(string[0], "HEBORIS ONLY");
		else sprintf(string[0], "T-SPIN ONLY");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(!vseGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		sprintf(string[0], "%d", vseStartLevel + 1);
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		// �J�[�\���ړ�
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 4;
			if(cursor > 4) cursor = 0;
		}
		
		// �l��ύX
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) {
				vseTSpin = vseTSpin + move;
				if(vseTSpin < 0) vseTSpin = 4;
				if(vseTSpin > 4) vseTSpin = 0;
			}
			if(cursor == 1) vseEnableCombo = !vseEnableCombo;
			if(cursor == 2) {
				vseEnableB2B = vseEnableB2B + move;
				if(vseEnableB2B < 0) vseEnableB2B = 3;
				if(vseEnableB2B > 3) vseEnableB2B = 0;
			}
			if(cursor == 3) vseGhost = !vseGhost;
			if(cursor == 4) {
				vseStartLevel = vseStartLevel + move;
				if(vseStartLevel < 0) vseStartLevel = 19;
				if(vseStartLevel > 19) vseStartLevel = 0;
			}
		}
		
		// �L�����Z��
		if(getPushState(player, 5)) {
			PlaySE(se_move);
			param[0] = 0;
			return;
		}
		
		// ����
		if(getPushState(player, 4)) {
			PlayWave(se_kettei);
			vseSaveConfig();
			return;
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			vseViewRanking(player);
		}
	}
}

// �ݒ��ۑ�
void vseSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �ݒ���e
	saveBuf[1] = vseTSpin;
	saveBuf[2] = vseEnableCombo;
	saveBuf[3] = vseEnableB2B;
	saveBuf[4] = vseGhost;
	saveBuf[5] = vseStartLevel;
	
	SaveFile("config/VS_ENDLESS_CONFIG.SAV", &saveBuf, 50 * 4);
}

// �ݒ��ǂݍ���
int vseLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/VS_ENDLESS_CONFIG.SAV", &saveBuf, 50 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �ݒ���e
	vseTSpin = saveBuf[1];
	vseEnableCombo = saveBuf[2];
	vseEnableB2B = saveBuf[3];
	vseGhost = saveBuf[4];
	vseStartLevel = saveBuf[5];
	
	return 1;
}

// ���v���C�ۑ�
void vseSaveReplay(int player) {
	saveBuf[900] = vseTSpin;
	saveBuf[901] = vseEnableCombo;
	saveBuf[902] = vseEnableB2B;
	saveBuf[903] = vseGhost;
	saveBuf[904] = vseStartLevel;
	saveBuf[905] = vseScore;
	saveBuf[906] = vseLines;
	saveBuf[907] = vseTotalAttack;
	saveBuf[908] = vseWin;
	saveBuf[909] = vseEnemyLevel;
}

// ���v���C�ǂݍ���
void vseLoadReplay(int player) {
	vseTSpin = saveBuf[900];
	vseEnableCombo = saveBuf[901];
	vseEnableB2B = saveBuf[902];
	vseGhost = saveBuf[903];
	vseStartLevel = saveBuf[904];
	
	vsePlayerInitial(player);	// �ݒ�𔽉f�����邽�߂ɏ������������s
}

// ���v���C�ڍ�
void vseReplayDetail() {
	printFontGrid(1, 5, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[905]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "LINES", 0);
	sprintf(string[0], "%d", saveBuf[906]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "TOTAL ATTACK", 0);
	sprintf(string[0], "%d", saveBuf[907]);
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 8, "WIN", 0);
	sprintf(string[0], "%d", saveBuf[908]);
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[909] + 1);
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 11, "T-SPIN", 0);
	if(saveBuf[900] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[900] == 1) sprintf(string[0], "LINE CLEAR");
	else if(saveBuf[900] == 2) sprintf(string[0], "IMMOBILE");
	else if(saveBuf[900] == 3) sprintf(string[0], "3-CORNER");
	else sprintf(string[0], "3-CORNER NO KICK");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "COMBO", 0);
	if(!saveBuf[901]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 12, string[0], 0);
	
	printFontGrid(1, 13, "BACK TO BACK", 0);
	if(saveBuf[902] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[902] == 1) sprintf(string[0], "ON");
	else if(saveBuf[902] == 2) sprintf(string[0], "HEBORIS ONLY");
	else sprintf(string[0], "T-SPIN ONLY");
	printFontGrid(22, 13, string[0], 0);
	
	printFontGrid(1, 14, "GHOST BLOCK", 0);
	if(!saveBuf[903]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 14, string[0], 0);
	
	printFontGrid(1, 15, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[904] + 1);
	printFontGrid(22, 15, string[0], 0);
}

// �����L���O�ۑ�
void vseSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0]  = vseRankingScore[i];
		saveBuf[1 + (i * 20) + 1]  = vseRankingLines[i];
		saveBuf[1 + (i * 20) + 2]  = vseRankingAttack[i];
		saveBuf[1 + (i * 20) + 3]  = vseRankingWin[i];
		saveBuf[1 + (i * 20) + 4]  = vseRankingLevel[i];
		saveBuf[1 + (i * 20) + 5]  = vseRankingTime[i];
		saveBuf[1 + (i * 20) + 6]  = vseRankingYear[i];
		saveBuf[1 + (i * 20) + 7]  = vseRankingMonth[i];
		saveBuf[1 + (i * 20) + 8]  = vseRankingDay[i];
		saveBuf[1 + (i * 20) + 9]  = vseRankingHour[i];
		saveBuf[1 + (i * 20) + 10] = vseRankingMinute[i];
		saveBuf[1 + (i * 20) + 11] = vseRankingSecond[i];
	}
	
	sprintf(string[0], "config/VS_ENDLESS_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 221 * 4);
}

// �����L���O�ǂݍ���
int vseLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/VS_ENDLESS_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 221 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		vseRankingScore[i]  = saveBuf[1 + (i * 20) + 0];
		vseRankingLines[i]  = saveBuf[1 + (i * 20) + 1];
		vseRankingAttack[i] = saveBuf[1 + (i * 20) + 2];
		vseRankingWin[i]    = saveBuf[1 + (i * 20) + 3];
		vseRankingLevel[i]  = saveBuf[1 + (i * 20) + 4];
		vseRankingTime[i]   = saveBuf[1 + (i * 20) + 5];
		vseRankingYear[i]   = saveBuf[1 + (i * 20) + 6];
		vseRankingMonth[i]  = saveBuf[1 + (i * 20) + 7];
		vseRankingDay[i]    = saveBuf[1 + (i * 20) + 8];
		vseRankingHour[i]   = saveBuf[1 + (i * 20) + 9];
		vseRankingMinute[i] = saveBuf[1 + (i * 20) + 10];
		vseRankingSecond[i] = saveBuf[1 + (i * 20) + 11];
	}
	
	return 1;
}

// �����L���O������
void vseInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		vseRankingScore[i]  = 0;
		vseRankingLines[i]  = 0;
		vseRankingAttack[i] = 0;
		vseRankingWin[i]    = 0;
		vseRankingLevel[i]  = 0;
		vseRankingTime[i]   = 0;
		vseRankingYear[i]   = 0;
		vseRankingMonth[i]  = 0;
		vseRankingDay[i]    = 0;
		vseRankingHour[i]   = 0;
		vseRankingMinute[i] = 0;
		vseRankingSecond[i] = 0;
	}
}

// �����L���O�o�^
int vseRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if(playback) return -1;
	
	for(i = 0; i < 10; i++) {
		// �����N�C��
		if((vseScore > vseRankingScore[i]) || 
		   ((vseScore == vseRankingScore[i]) && (vseWin > vseRankingWin[i])))
		{
			// �����L���O�����炷
			for(j = 9; j > i; j--) {
				vseRankingScore[j]  = vseRankingScore[j - 1];
				vseRankingLines[j]  = vseRankingLines[j - 1];
				vseRankingAttack[j] = vseRankingAttack[j - 1];
				vseRankingWin[j]    = vseRankingWin[j - 1];
				vseRankingLevel[j]  = vseRankingLevel[j - 1];
				vseRankingTime[j]   = vseRankingTime[j - 1];
				vseRankingYear[j]   = vseRankingYear[j - 1];
				vseRankingMonth[j]  = vseRankingMonth[j - 1];
				vseRankingDay[j]    = vseRankingDay[j - 1];
				vseRankingHour[j]   = vseRankingHour[j - 1];
				vseRankingMinute[j] = vseRankingMinute[j - 1];
				vseRankingSecond[j] = vseRankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			vseRankingScore[i]  = vseScore;
			vseRankingLines[i]  = vseLines;
			vseRankingAttack[i] = vseTotalAttack;
			vseRankingWin[i]    = vseWin;
			vseRankingLevel[i]  = vseEnemyLevel;
			vseRankingTime[i]   = gameTimer[player];
			
			GetDateAndTime(&timebuf);
			vseRankingYear[i]   = timebuf[0];
			vseRankingMonth[i]  = timebuf[1];
			vseRankingDay[i]    = timebuf[2];
			vseRankingHour[i]   = timebuf[4];
			vseRankingMinute[i] = timebuf[5];
			vseRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �����L���O�\��
void vseViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "VS-ENDLESS MODE RANKING", 6);
		printFontGrid(1, 3, "RANK SCORE    WIN   LEVEL TIME", 4);
		
		for(i = 0; i < 10; i++) {
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", vseRankingScore[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", vseRankingWin[i]);
			printFontGrid(15, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", vseRankingLevel[i] + 1);
			printFontGrid(21, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(vseRankingTime[i]);
			printFontGrid(27, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// ���C�����ƍU����
			sprintf(string[0], "LINES:%d", vseRankingLines[cursor]);
			printFontGrid(1, 24, string[0], 0);
			sprintf(string[0], "TOTAL ATTACK:%d", vseRankingAttack[cursor]);
			printFontGrid(1, 25, string[0], 0);
			
			// ���t�Ǝ���
			sprintf(string[0],
			        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
			        vseRankingYear[cursor], vseRankingMonth[cursor], vseRankingDay[cursor],
			        vseRankingHour[cursor], vseRankingMinute[cursor], vseRankingSecond[cursor]);
			printFontGrid(1, 26, string[0], 0);
			
			printFontGrid(1, 28, "A/B:EXIT F:ERASE ALL", 6);
			
			// �J�[�\���ړ�
			padRepeat2(player);
			
			move = 0;
			if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
				move = getPressState(player, 1) - getPressState(player, 0);
			
			if(move) {
				PlaySE(se_move);
				cursor = cursor + move;
				if(cursor < 0) cursor = 9;
				if(cursor > 9) cursor = 0;
			}
			
			// �߂�
			if(getPushState(player, 4) || getPushState(player, 5)) {
				PlaySE(se_move);
				return;
			}
			
			// �����L���O�������[�h��
			if(getPushState(player, 9)) {
				PlaySE(se_shaki);
				erasemode = 1;
			}
		} else {
			printFontGrid(1, 24, "ERASE ALL RECORDS?", 2);
			printFontGrid(1, 26, "A:YES / B:NO", 2);
			
			// ����
			if(getPushState(player, 4)) {
				PlayWave(se_kettei);
				vseInitRanking();
				vseSaveRanking(player);
				erasemode = 0;
			}
			
			// �߂�
			if(getPushState(player, 5)) {
				PlaySE(se_move);
				erasemode = 0;
			}
		}
	}
}
