//SQUARE
//prefix:squ

// ���x���A�b�v�e�[�u���iLV12�ŃX�s�[�h�^�C�v���ʏ탂�[�h�ɂȂ�j
int squLevelTable[15] = 
{
//   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15
    60,  48,  36,  28,  22,  16,  12,   8,   6,   4,   2,  60, 180, 300,1200
};

// �ϐ�
int squModeNo = -1;			// ���[�h�ԍ�

int squScore[2];			// �X�R�A
int squSquares[2];			// ����������`�̐�
int squLevel[2];			// ���݂̃��x��
int squGoal[2];				// ���x���A�b�v�܂ł̃|�C���g��

int squTSpinFrame[2];		// T-SPIN�\���̎c�莞��
int squTSpinLine[2];		// �Ō��T-SPIN���C�������̎��
int squScoreGet[2];			// ���������X�R�A�\���̓_��
int squScoreFrame[2];		// ���������X�R�A�\���̎c�莞��
int squGoalGet[2];			// ���������|�C���g�\���̓_��
int squGoalFrame[2];		// ���������|�C���g�\���̎c�莞��

int squMarkFld[10 * 22];	// T-SPIN�ł̗��������Ŏg�p����u���b�N���ʗp�t�B�[���h
int squTFallFlag[2];		// T-SPIN�ł̗����t���O
int squMarkCount;			// �q�����Ă���u���b�N�̐�

int squSilverCount[2];		// ���C���̒��Ɋ܂܂���̐����`�̐��i�����`�{�[�i�X�J�E���^�j
int squGoldCount[2];		// ���C���̒��Ɋ܂܂����̐����`�̐��i�����`�{�[�i�X�J�E���^�j

int squBgm = 20;			// �g�p����BGM
int squGhost = 1;			// �S�[�X�g�̐ݒ�
int squFieldView = 0;		// �t�B�[���h�̕\���^�C�v
int squTSpin = 3;			// T-SPIN�̎��
int squStartLevel = 0;		// �X�^�[�g���̃��x��

// �����L���O�p�ϐ�
int squRankingScore[10];	// �X�R�A
int squRankingSquares[10];	// ����������`�̐�
int squRankingLevel[10];	// ���x��
int squRankingTime[10];		// �^�C��
int squRankingYear[10];		// �����N�C�������i�N�j
int squRankingMonth[10];	// �����N�C�������i���j
int squRankingDay[10];		// �����N�C�������i���j
int squRankingHour[10];		// �����N�C�������i���j
int squRankingMinute[10];	// �����N�C�������i���j
int squRankingSecond[10];	// �����N�C�������i�b�j

// �C�x���g����
void squPluginEvent(int player, int event, int *param) {
	int i;
	
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != squModeNo)) return;
	
	if(event == 0) {
		squModeNo = addModePlugin("SQUARE");	// ���[�h��o�^����
	} else if(event == 8) {
		squSoftDropScore(player);	// �\�t�g�h���b�v�œ������_�������Z
	} else if(event == 11) {
		squAfterErase(player, param);	// ���C������
	} else if(event == 12) {
		squCalcScore(player, param[0]);	// �X�R�A�v�Z
	} else if(event == 15) {
		squViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		squSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		squPlayerInitial(player);	// ������
	} else if(event == 21) {
		squResult(player);	// ���ʕ\��
	} else if(event == 24) {
		onRecord[player] = 0;	// �G���f�B���O�˓�
		ending[player] = 3;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		squExcellent(player, param);	// EXCELLENT���
	} else if(event == 34) {
		if(squFieldView) squViewFieldBlock(player, param);	// �t�B�[���h�̃u���b�N��\��
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		squSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		squLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		squLoadBGM();	// BGM�ǂݍ���
	} else if(event == 48) {
		squSoftDropOld(player);	// �\�t�g�h���b�v�i���j
	} else if(event == 49) {
		squHardDrop(player, param[1]);	// �n�[�h�h���b�v
	} else if(event == 53) {
		squOnBlockErase(player, param[0], param[1]);	// �u���b�N��������Ƃ�
	} else if(event == 55) {
		squReplayDetail();	// ���v���C�ڍ�
	} else if(event == 59) {
		squTSpinZero(player);	// ���C�������Ȃ���T-SPIN
	} else if(event == 60) {
		squMakeSquare(player);	// �u���b�N��u�����u�Ԃɐ����`���������
	}
}

// �����`���ł��邩����
int squCheckSquare(int player, int x, int y, int gold) {
	int i, j, color, temp;
	
	// �n�_�̐F���擾
	color = getFieldBlock(player, x, y);
	
	// 4x4�̃G���A���`�F�b�N
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 4; j++) {
			// �u���b�N���擾
			temp = getFieldBlock(player, x + i, y + j);
			
			// �j�Ђ���������I��
			if(temp <= 1) return 0;
			
			// �S�������F�łȂ�������I���igold == 1�̏ꍇ�j
			if((gold) && (temp != color)) return 0;
			
			// �A�C�e���t���O���擾
			temp = getFieldBlockI(player, x + i, y + j);
			
			// ���łɐ����`�ɂȂ��Ă���I��
			if((temp == fldisno) || (temp == fldigsno)) return 0;
		}
	}
	
	// �O���Ɍq�����Ă�����I��
	// �㉺
	for(i = 0; i < 4; i++) {
		if(BitTest(getFieldBlockL(player, x + i, y    ), 0)) return 0;
		if(BitTest(getFieldBlockL(player, x + i, y + 3), 1)) return 0;
	}
	
	// ���E
	for(j = 0; j < 4; j++) {
		if(BitTest(getFieldBlockL(player, x    , y + j), 2)) return 0;
		if(BitTest(getFieldBlockL(player, x + 3, y + j), 3)) return 0;
	}
	
	// ����
	return 1;
}

// �����`�����
int squMakeSquare(int player) {
	int i, j, k, l, result;
	result = 0;
	
	for(i = 0; i < 22 - 3; i++) {
		for(j = 0; j < 10 - 3; j++) {
			if(squCheckSquare(player, j, i, 1)) {
				// ���F
				if(result < 2) result = 2;
				PlaySE(se_cheer);
				squSquares[player] = squSquares[player] + 2;
				
				// �}�[�N��t����
				for(k = 0; k < 4; k++) {
					for(l = 0; l < 4; l++) {
						setFieldBlockI(player, l + j, i + k, fldigsno);
					}
				}
				
				// �q�����ς���
				setFieldBlockL(player, j    , i    , 10);
				setFieldBlockL(player, j + 1, i    , 14);
				setFieldBlockL(player, j + 2, i    , 14);
				setFieldBlockL(player, j + 3, i    ,  6);
				setFieldBlockL(player, j    , i + 1, 11);
				setFieldBlockL(player, j + 1, i + 1, 15);
				setFieldBlockL(player, j + 2, i + 1, 15);
				setFieldBlockL(player, j + 3, i + 1,  7);
				setFieldBlockL(player, j    , i + 2, 11);
				setFieldBlockL(player, j + 1, i + 2, 15);
				setFieldBlockL(player, j + 2, i + 2, 15);
				setFieldBlockL(player, j + 3, i + 2,  7);
				setFieldBlockL(player, j    , i + 3,  9);
				setFieldBlockL(player, j + 1, i + 3, 13);
				setFieldBlockL(player, j + 2, i + 3, 13);
				setFieldBlockL(player, j + 3, i + 3,  5);
			} else if(squCheckSquare(player, j, i, 0)) {
				// ��F
				if(result < 1) result = 1;
				PlaySE(se_applause);
				squSquares[player]++;
				
				// �}�[�N��t����
				for(k = 0; k < 4; k++) {
					for(l = 0; l < 4; l++) {
						setFieldBlockI(player, l + j, i + k, fldisno);
					}
				}
				
				// �q�����ς���
				setFieldBlockL(player, j    , i    , 10);
				setFieldBlockL(player, j + 1, i    , 14);
				setFieldBlockL(player, j + 2, i    , 14);
				setFieldBlockL(player, j + 3, i    ,  6);
				setFieldBlockL(player, j    , i + 1, 11);
				setFieldBlockL(player, j + 1, i + 1, 15);
				setFieldBlockL(player, j + 2, i + 1, 15);
				setFieldBlockL(player, j + 3, i + 1,  7);
				setFieldBlockL(player, j    , i + 2, 11);
				setFieldBlockL(player, j + 1, i + 2, 15);
				setFieldBlockL(player, j + 2, i + 2, 15);
				setFieldBlockL(player, j + 3, i + 2,  7);
				setFieldBlockL(player, j    , i + 3,  9);
				setFieldBlockL(player, j + 1, i + 3, 13);
				setFieldBlockL(player, j + 2, i + 3, 13);
				setFieldBlockL(player, j + 3, i + 3,  5);
			}
		} /* for(j = 0; j < 6; j++) */
	} /* for(i = 0; i < 18; i++) */
	
	return result;
}

// ���C������
void squAfterErase(int player, int *param) {
	int i, j, temp, fall;
	
	if(statc[player * 10] == wait2[player]) {
		param[0] = 1;	// �ʏ�̃��C��������̏������X�L�b�v����
		
		for(i = 21; i >= 0; i--) {
			if(erase[i + player * 22]) {
				// ���������C����1�}�X�㉺�̃u���b�N�̌q������O���A�j�Ёi�q�����Ă��鐔��3�ȉ��j���D�F�ɂ���
				for(j = 0; j < 10; j++) {
					// ��
					temp = getFieldBlockL(player, j, i - 1);
					temp = BitSet(temp, 1, 0);
					setFieldBlockL(player, j, i - 1, temp);
					
					if(squHowManyBlockLink(player, j, i - 1) <= 3) {
						squGrayoutBlockLink(player, j, i - 1);
					}
					
					// ��
					temp = getFieldBlockL(player, j, i + 1);
					temp = BitSet(temp, 0, 0);
					setFieldBlockL(player, j, i + 1, temp);
					
					if(squHowManyBlockLink(player, j, i + 1) <= 3) {
						squGrayoutBlockLink(player, j, i + 1);
					}
				}
			}
		}
	}
	
	if((statc[player * 10] >= wait2[player]) && (squTFallFlag[player])) {
		param[0] = 1;	// �ʏ�̃��C��������̏������X�L�b�v����
		
		// T-SPIN�ŗ���
		fall = 0;
		
		for(i = 21; i >= 0; i--) {
			for(j = 0; j < 10; j++) {
				if(squFallBlock(player, j, i)) fall = 1;
			}
		}
		
		// �����Ȃ��Ȃ�����I���
		if(!fall) {
			PlaySE(se_gon);
			pinchCheck(player);
			
			if(blockEraseJudge(player)) {
				// �A��
				statc[player * 10] = 0;
			} else {
				// �I��
				squTFallFlag[player] = 0;
				stat[player] = 5;
				statc[player * 10] = wait1[player];
			}
			return;
		}
	}
	
	if(param[0]) statc[player * 10]++;
}

// T-SPIN���̕����^�S�̃t���[�t�H�[���J�n����
void squTSpinFall(int player, int lines) {
	int i, j, start;
	
	if(lines == 1) {
		// �n�_�𒲂ׂ�
		for(i = 0; i < 22; i++) {
			if(erase[i + player * 22]) {
				start = i;
				break;
			}
		}
	} else {
		start = 0;
	}
	
	// �n�_���牺�̃u���b�N�̌���������
	for(i = start; i < 22; i++) {
		for(j = 0; j < 10; j++) {
			if(getFieldBlock(player, j, i) >= 1) {
				setFieldBlock(player, j, i, 1);
				setFieldBlockL(player, j, i, 0);
				setFieldBlockI(player, j, i, 0);
			}
		}
	}
	
	// �����t���OON
	squTFallFlag[player] = 1;
}

// T-SPIN�ŕ������u���b�N�𗎂Ƃ��i�������ꍇ�͖߂�l��1�ɂȂ�j
int squFallBlock(int player, int x, int y) {
	int i, j, fall, temp;
	
	fall = 0;
	
	if((!squMarkFld[x + y * 10]) && (getFieldBlock(player, x, y) > 0)) {
		fall = 1;
		
		for(i = 0; i < 220; i++) squMarkFld[i] = 0;
		squMarkCount = 0;
		squCheckBlockLink(player, x, y);
		
		// �u���b�N�̉��ɋ�Ԃ����邩�`�F�b�N�i���������璆�~�j
		for(i = 21; i >= 0; i--) {
			for(j = 0; j < 10; j++) {
				if(squMarkFld[j + i * 10] == 1) {
					if( (i == 21) || ((getFieldBlock(player, j, i + 1) != 0) && (squMarkFld[j + (i + 1) * 10] != 1)) ) {
						fall = 0;
					}
				}
			}
		}
		
		// 1�}�X���ɗ��Ƃ�
		if(fall) {
			for(i = 21; i >= 0; i--) {
				for(j = 0; j < 10; j++) {
					if(squMarkFld[j + i * 10] == 1) {
						temp = getFieldBlock(player, j, i);
						setFieldBlock(player, j, i + 1, temp);
						temp = getFieldBlockT(player, j, i);
						setFieldBlockT(player, j, i + 1, temp);
						temp = getFieldBlockO(player, j, i);
						setFieldBlockO(player, j, i + 1, temp);
						temp = getFieldBlockL(player, j, i);
						setFieldBlockL(player, j, i + 1, temp);
						temp = getFieldBlockI(player, j, i);
						setFieldBlockI(player, j, i + 1, temp);
						
						setFieldBlock(player, j, i, 0);
						setFieldBlockT(player, j, i, 0);
						setFieldBlockO(player, j, i, 0);
						setFieldBlockL(player, j, i, 0);
						setFieldBlockI(player, j, i, 0);
					}
				}
			}
		}
	}
	
	return fall;
}

// �q�����Ă���u���b�N�𒲂ׂ�
void squCheckBlockLink(int player, int x, int y) {
	int temp;
	
	if((x >= 0) && (x < 10) && (y >= 0) && (y < 22)) {
		if((getFieldBlock(player, x, y) > 0) && (squMarkFld[x + y * 10] == 0)) {
			squMarkFld[x + y * 10] = 1;
			squMarkCount++;
			
			temp = getFieldBlockL(player, x, y);
			if(BitTest(temp, 0)) squCheckBlockLink(player, x, y - 1);
			if(BitTest(temp, 1)) squCheckBlockLink(player, x, y + 1);
			if(BitTest(temp, 2)) squCheckBlockLink(player, x - 1, y);
			if(BitTest(temp, 3)) squCheckBlockLink(player, x + 1, y);
		}
	}
}

// �q�����Ă���u���b�N���D�F�ɂ���
void squGrayoutBlockLink(int player, int x, int y) {
	int temp;
	
	if((x >= 0) && (x < 10) && (y >= 0) && (y < 22)) {
		if(getFieldBlock(player, x, y) >= 2) {
			setFieldBlock(player, x, y, 1);
			
			temp = getFieldBlockL(player, x, y);
			if(BitTest(temp, 0)) squGrayoutBlockLink(player, x, y - 1);
			if(BitTest(temp, 1)) squGrayoutBlockLink(player, x, y + 1);
			if(BitTest(temp, 2)) squGrayoutBlockLink(player, x - 1, y);
			if(BitTest(temp, 3)) squGrayoutBlockLink(player, x + 1, y);
		}
	}
}

// �q�����Ă���u���b�N�̐��𐔂���
int squHowManyBlockLink(int player, int x, int y) {
	int i;
	for(i = 0; i < 220; i++) squMarkFld[i] = 0;
	squMarkCount = 0;
	squCheckBlockLink(player, x, y);
	return squMarkCount;
}

// ������
void squPlayerInitial(int player) {
	// �ϐ���������
	squScore[player] = 0;
	squSquares[player] = 0;
	squLevel[player] = squStartLevel;
	squGoal[player] = 5 * (squLevel[player] + 1);
	
	squTSpinFrame[player] = 0;
	squTSpinLine[player] = 0;
	squScoreGet[player] = 0;
	squScoreFrame[player] = 0;
	squGoalGet[player] = 0;
	squGoalFrame[player] = 0;
	
	squTFallFlag[player] = 0;
	
	squSilverCount[player] = 0;
	squGoldCount[player] = 0;
	
	// �������x
	sp[player] = squLevelTable[squLevel[player]];
	if(squLevel[player] >= 11) speedtype[player] = 0;
	else speedtype[player] = 1;
	
	// �g�̐F��ς���
	framecolor[player] = 5;
	frame_decoration[player] = 1;
	
	// �ݒ�𔽉f������
	bgmlv = squBgm;
	if(squGhost == 0) ghost[player] = 0;
	tspin_type[player] = squTSpin;
	backno = squLevel[player];
}

// �u���b�N��������Ƃ�
void squOnBlockErase(int player, int x, int y) {
	int temp;
	temp = getFieldBlockI(player, x, y);
	
	// �����鐳���`�̐����J�E���g
	if(temp == fldisno) squSilverCount[player]++;
	if(temp == fldigsno) squGoldCount[player]++;
}

// �X�R�A�v�Z
void squCalcScore(int player, int lines) {
	int bo, points;
	
	// T-SPIN�������̓J�E���g���Ȃ�
	if(squTFallFlag[player]) return;
	
	// T-SPIN
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		squTSpinFall(player, lines);
		
		squTSpinFrame[player] = 60;
		squTSpinLine[player] = lines;
		
		if(lines == 1) bo = 3;	// T-SPIN Single
		if(lines == 2) bo = 7;	// T-SPIN Double
		if(lines == 3) bo = 6;	// T-SPIN Triple
	}
	// ���ʂ̃��C������
	else {
		if(lines == 1) bo = 1;
		if(lines == 2) bo = 3;
		if(lines == 3) bo = 5;
		if(lines == 4) {
			bo = 8;
			squTSpinFrame[player] = 60;
			squTSpinLine[player] = lines;
		}
	}
	
	// �����`�{�[�i�X
	bo = bo + ((squSilverCount[player] / 4) * 5);
	bo = bo + ((squGoldCount[player] / 4) * 10);
	
	// �S�����{�[�i�X
	if(isBravo(player)) {
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		bo = bo + 50;
	}
	
	// �X�R�A���Z
	points = (bo * 100) * (squLevel[player] + 1);
	squScore[player] = squScore[player] + points;
	squScoreGet[player] = points;
	squScoreFrame[player] = 120;
	
	// �S�[������
	squGoal[player] = squGoal[player] - bo;
	squGoalGet[player] = bo;
	squGoalFrame[player] = 120;
	
	// �����`�{�[�i�X�J�E���^�����Z�b�g
	squSilverCount[player] = 0;
	squGoldCount[player] = 0;
	
	// ���x���A�b�v
	squLevelUp(player);
}

// ���C�������Ȃ���T-SPIN
void squTSpinZero(int player) {
	PlaySE(se_tspin);
	squTSpinFrame[player] = 60;
	squTSpinLine[player] = 0;
	
	squScore[player] = squScore[player] + (100 * (squLevel[player] + 1));
	squScoreGet[player] = 100 * (squLevel[player] + 1);
	squScoreFrame[player] = 120;
	
	squGoal[player] = squGoal[player] - 1;
	squGoalGet[player] = 1;
	squGoalFrame[player] = 120;
	
	// ���x���A�b�v
	squLevelUp(player);
}

// ���x���A�b�v
void squLevelUp(int player) {
	if(squGoal[player] <= 0) {
		if(squLevel[player] >= 14) {
			// �G���f�B���O
			squGoal[player] = 0;
			ending[player] = 1;
			timeOn[player] = 0;
		} else {
			// ���x���A�b�v
			squLevel[player]++;
			squGoal[player] = 5 * (squLevel[player] + 1);
			sp[player] = squLevelTable[squLevel[player]];
			if(squLevel[player] >= 11) speedtype[player] = 0;
			
			PlaySE(se_rankup);
			bgfadesw = 1;
			bgfadebg = squLevel[player];
		}
	}
}

// �\�t�g�h���b�v�i���j
void squSoftDropOld(int player) {
	if((!down_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) && (engineVer <= 12)) {
		if((speedtype[player] == 1) || (sp[player] < (softspeed[player] + 1) * 30)) {
			squScore[player]++;
		}
	}
}

// �n�[�h�h���b�v
void squHardDrop(int player, int bottom) {
	if((!up_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0)) {
		squScore[player] = squScore[player] + (bottom - by[player]) * 2;
	}
}

// �\�t�g�h���b�v�œ������_�������Z
void squSoftDropScore(int player) {
	if(softd_score[player] > 0) {
		squScore[player] = squScore[player] + softd_score[player];
	}
}

// �X�R�A�\��
void squViewScore(int player) {
	int color;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// �X�R�A
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "SCORE");
	sprintf(string[0], "%d", squScore[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// �����������_
	if(squScoreFrame[player] > 0) {
		squScoreFrame[player]--;
		sprintf(string[0], "%d", squScoreGet[player]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 58, string[0], (count % 4 / 2) * (1 + (b_to_b_count[player] != 0)));
	}
	
	// ���x��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 68, "LEVEL");
	sprintf(string[0], "%d", squLevel[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 76, string[0], color);
	
	// �S�[��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 86, "GOAL");
	sprintf(string[0], "%d", squGoal[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 94, string[0], color);
	
	// ���������|�C���g
	if(squGoalFrame[player] > 0) {
		squGoalFrame[player]--;
		sprintf(string[0], "%d", squGoalGet[player]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 104, string[0], (count % 4 / 2) * (1 + (b_to_b_count[player] != 0)));
	}
	
	// �^�C��
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
	
	// T-SPIN
	if(squTSpinFrame[player] > 0) {
		squTSpinFrame[player]--;
		
		if(squTSpinLine[player] == 0)
			printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "T-SPIN");
		else if(squTSpinLine[player] == 1)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN SINGLE");
		else if(squTSpinLine[player] == 2)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN DOUBLE");
		else if(squTSpinLine[player] == 3)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN TRIPLE");
		else if(squTSpinLine[player] == 4)
			printTinyFont(foffset[player] + 30, fyoffset[player] + 208, "HEBORIS");
	}
}

// ���ʕ\��
void squResult(int player) {
	// �����L���O�o�^
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = squRegistRanking(player);
		if(statc[player * 10 + 1] != -1) squSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "SCORE");
	sprintf(string[0], "%13d", squScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "SQUARES");
	sprintf(string[0], "%13d", squSquares[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "LEVEL");
	sprintf(string[0], "%13d", squLevel[player] + 1);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 139, "TIME");
	getTime(gameTimer[player]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 147, string[1], 0);
	
	if(statc[player * 10 + 1] != -1) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 159, "RANK");
		sprintf(string[0], "%13d", statc[player * 10 + 1] + 1);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
	}
}

// EXCELLENT���
void squExcellent(int player, int *param) {
	printTinyFont(foffset[player] + 20, fyoffset[player] + 116, "SQUARE MODE");
	printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
	
	// �ԉ�
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// BGM�ǂݍ���
void squLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(squBgm);
	}
}

// �t�B�[���h�̃u���b�N��\��
void squViewFieldBlock(int player, int *param) {
	int i, j, fi, ft, fo, it, temp, dx, dy, tmp_color, tmp_oblk;
	
	param[0] = 1;
	
	for(i = 0; i < hiddeny[player]; i++) {
		for(j = 0; j < 10; j++) {
			fi = getFieldBlock(player, j, i);
			
			if(fi > 0) {
				// �u���b�N��`��
				dx = foffset[player] + 8 + (j * 8);
				dy = fyoffset[player] + (i + 3) * 8;
				
				ft = getFieldBlockT(player, j, i);
				fo = getFieldBlockO(player, j, i);
				it = getFieldBlockI(player, j, i);
				
				// �F�����߂�
				if(it) {
					// �A�C�e��
					tmp_color = it + 16;
					tmp_oblk = 0;
				} else {
					// �ʏ�
					tmp_color = fi - 1;
					tmp_oblk = fo;
				}
				
				if((ft >= 1) && (ft <= 8)) {
					drawSBlock(player, dx, dy, tmp_color, 5 + tmp_oblk * 17, 0, 1, ft * 32);
				} else if((ft != 0) && (ft > -10)) {
					drawSBlock(player, dx, dy, tmp_color, 5 + tmp_oblk * 17, 0, 0, 0);
				}
				
				if( (disp_blkline[player]) && ((ft <= -1) || (ft >= 8)) && (!tmp_oblk) ) {
					// �g����`��
					temp = getFieldBlockL(player, j, i);
					
					if(!BitTest(temp, 0)) ExBltFastRect(sg_blkline, dx    , dy    ,  8,  0, 8, 1);
					if(!BitTest(temp, 1)) ExBltFastRect(sg_blkline, dx    , dy + 7,  8, 15, 8, 1);
					if(!BitTest(temp, 2)) ExBltFastRect(sg_blkline, dx    , dy    ,  8, 16, 1, 8);
					if(!BitTest(temp, 3)) ExBltFastRect(sg_blkline, dx + 7, dy    , 15, 24, 1, 8);
					
					// �e��`��
					if(blockshadow != 0) viewFieldBlockSub_DrawShadow(player, j, i, dx, dy, it, tmp_color);
				}
			}
		}
	}
}

// �ݒ���
void squSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(squLoadConfig() == 0) squSaveConfig();
	
	// �����L���O��ǂݍ���
	if(squLoadRanking(player) == 0) squInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "SQUARE OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "BGM",          7 * (cursor == 0));
		printFontGrid(2, 4, "GHOST BLOCK",  7 * (cursor == 1));
		printFontGrid(2, 5, "FIELD VIEW",   7 * (cursor == 2));
		printFontGrid(2, 6, "T-SPIN",       7 * (cursor == 3));
		printFontGrid(2, 7, "START LEVEL",  7 * (cursor == 4));
		
		// �ݒ�l�\��
		sprintf(string[0], "%d", squBgm);
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!squGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!squFieldView) sprintf(string[0], "NORMAL");
		else sprintf(string[0], "SPECIAL");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(squTSpin == 0) sprintf(string[0], "OFF");
		else if(squTSpin == 1) sprintf(string[0], "LINE CLEAR");
		else if(squTSpin == 2) sprintf(string[0], "IMMOBILE");
		else if(squTSpin == 3) sprintf(string[0], "3-CORNER");
		else sprintf(string[0], "3-CORNER NO KICK");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		sprintf(string[0], "%d", squStartLevel + 1);
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
				squBgm = squBgm + move;
				if(squBgm < 0) squBgm = 29;
				if(squBgm > 29) squBgm = 0;
			}
			if(cursor == 1) squGhost = !squGhost;
			if(cursor == 2) squFieldView = !squFieldView;
			if(cursor == 3) {
				squTSpin = squTSpin + move;
				if(squTSpin < 0) squTSpin = 4;
				if(squTSpin > 4) squTSpin = 0;
			}
			if(cursor == 4) {
				squStartLevel = squStartLevel + move;
				if(squStartLevel < 0) squStartLevel = 14;
				if(squStartLevel > 14) squStartLevel = 0;
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
			squSaveConfig();
			return;
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			squViewRanking(player);
		}
	}
}

// �ݒ��ۑ�
void squSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �ݒ���e
	saveBuf[1] = squBgm;
	saveBuf[2] = squGhost;
	saveBuf[3] = squFieldView;
	saveBuf[4] = squTSpin;
	saveBuf[5] = squStartLevel;
	
	SaveFile("config/SQUARE_CONFIG.SAV", &saveBuf, 100 * 4);
}

// �ݒ��ǂݍ���
int squLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/SQUARE_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �ݒ���e
	squBgm = saveBuf[1];
	squGhost = saveBuf[2];
	squFieldView = saveBuf[3];
	squTSpin = saveBuf[4];
	squStartLevel = saveBuf[5];
	
	return 1;
}

// ���v���C�ۑ�
void squSaveReplay(int player) {
	saveBuf[900] = squScore[player];
	saveBuf[901] = squSquares[player];
	saveBuf[902] = squLevel[player];
	saveBuf[903] = squBgm;
	saveBuf[904] = squGhost;
	saveBuf[905] = squFieldView;
	saveBuf[906] = squTSpin;
	saveBuf[907] = squStartLevel;
}

// ���v���C�ǂݍ���
void squLoadReplay(int player) {
	squBgm = saveBuf[903];
	squGhost = saveBuf[904];
	squFieldView = saveBuf[905];
	squTSpin = saveBuf[906];
	squStartLevel = saveBuf[907];
	
	squPlayerInitial(player);	// �ݒ�𔽉f������
}

// ���v���C�ڍ�
void squReplayDetail() {
	printFontGrid(1, 5, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[900]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "SQUARES", 0);
	sprintf(string[0], "%d", saveBuf[901]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[902] + 1);
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 9, "BGM", 0);
	sprintf(string[0], "%d", saveBuf[903]);
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "GHOST BLOCK", 0);
	if(!saveBuf[904]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "FIELD VIEW", 0);
	if(!saveBuf[905]) sprintf(string[0], "NORMAL");
	else sprintf(string[0], "SPECIAL");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "T-SPIN", 0);
	if(saveBuf[906] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[906] == 1) sprintf(string[0], "LINE CLEAR");
	else if(saveBuf[906] == 2) sprintf(string[0], "IMMOBILE");
	else if(saveBuf[906] == 3) sprintf(string[0], "3-CORNER");
	else sprintf(string[0], "3-CORNER NO KICK");
	printFontGrid(22, 12, string[0], 0);
	
	printFontGrid(1, 13, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[907] + 1);
	printFontGrid(22, 13, string[0], 0);
}

// �����L���O�ۑ�
void squSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0] = squRankingScore[i];
		saveBuf[1 + (i * 20) + 1] = squRankingSquares[i];
		saveBuf[1 + (i * 20) + 2] = squRankingLevel[i];
		saveBuf[1 + (i * 20) + 3] = squRankingTime[i];
		saveBuf[1 + (i * 20) + 4] = squRankingYear[i];
		saveBuf[1 + (i * 20) + 5] = squRankingMonth[i];
		saveBuf[1 + (i * 20) + 6] = squRankingDay[i];
		saveBuf[1 + (i * 20) + 7] = squRankingHour[i];
		saveBuf[1 + (i * 20) + 8] = squRankingMinute[i];
		saveBuf[1 + (i * 20) + 9] = squRankingSecond[i];
	}
	
	sprintf(string[0], "config/SQUARE_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 221 * 4);
}

// �����L���O�ǂݍ���
int squLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/SQUARE_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 221 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		squRankingScore[i]   = saveBuf[1 + (i * 20) + 0];
		squRankingSquares[i] = saveBuf[1 + (i * 20) + 1];
		squRankingLevel[i]   = saveBuf[1 + (i * 20) + 2];
		squRankingTime[i]    = saveBuf[1 + (i * 20) + 3];
		squRankingYear[i]    = saveBuf[1 + (i * 20) + 4];
		squRankingMonth[i]   = saveBuf[1 + (i * 20) + 5];
		squRankingDay[i]     = saveBuf[1 + (i * 20) + 6];
		squRankingHour[i]    = saveBuf[1 + (i * 20) + 7];
		squRankingMinute[i]  = saveBuf[1 + (i * 20) + 8];
		squRankingSecond[i]  = saveBuf[1 + (i * 20) + 9];
	}
	
	return 1;
}

// �����L���O������
void squInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		squRankingScore[i]   = 0;
		squRankingSquares[i] = 0;
		squRankingLevel[i]   = 0;
		squRankingTime[i]    = 0;
		squRankingYear[i]    = 0;
		squRankingMonth[i]   = 0;
		squRankingDay[i]     = 0;
		squRankingHour[i]    = 0;
		squRankingMinute[i]  = 0;
		squRankingSecond[i]  = 0;
	}
}

// �����L���O�o�^
int squRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if(playback) return -1;
	
	for(i = 0; i < 10; i++) {
		// �����N�C��
		if((squScore[player] > squRankingScore[i]) || 
		   ((squScore[player] == squRankingScore[i]) && (gameTimer[player] < squRankingTime[i])))
		{
			// �����L���O�����炷
			for(j = 9; j > i; j--) {
				squRankingScore[j]   = squRankingScore[j - 1];
				squRankingSquares[j] = squRankingSquares[j - 1];
				squRankingLevel[j]   = squRankingLevel[j - 1];
				squRankingTime[j]    = squRankingTime[j - 1];
				squRankingYear[j]    = squRankingYear[j - 1];
				squRankingMonth[j]   = squRankingMonth[j - 1];
				squRankingDay[j]     = squRankingDay[j - 1];
				squRankingHour[j]    = squRankingHour[j - 1];
				squRankingMinute[j]  = squRankingMinute[j - 1];
				squRankingSecond[j]  = squRankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			squRankingScore[i]   = squScore[player];
			squRankingSquares[i] = squSquares[player];
			squRankingLevel[i]   = squLevel[player];
			squRankingTime[i]    = gameTimer[player];
			
			GetDateAndTime(&timebuf);
			squRankingYear[i]    = timebuf[0];
			squRankingMonth[i]   = timebuf[1];
			squRankingDay[i]     = timebuf[2];
			squRankingHour[i]    = timebuf[4];
			squRankingMinute[i]  = timebuf[5];
			squRankingSecond[i]  = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �����L���O�\��
void squViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "SQUARE MODE RANKING", 6);
		printFontGrid(1, 3, "RANK SCORE    SQUARES LEVEL TIME", 4);
		
		for(i = 0; i < 10; i++) {
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", squRankingScore[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", squRankingSquares[i]);
			printFontGrid(15, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", squRankingLevel[i] + 1);
			printFontGrid(23, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(squRankingTime[i]);
			printFontGrid(29, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// ���t�Ǝ���
			sprintf(string[0],
			        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
			        squRankingYear[cursor], squRankingMonth[cursor], squRankingDay[cursor],
			        squRankingHour[cursor], squRankingMinute[cursor], squRankingSecond[cursor]);
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
				squInitRanking();
				squSaveRanking(player);
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
