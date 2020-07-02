//STICKY
//prefix:sti

// ���x���A�b�v�e�[�u���iLV12�ŃX�s�[�h�^�C�v���ʏ탂�[�h�ɂȂ�j
int stiLevelTable[15] = 
{
//   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15
    60,  48,  36,  28,  22,  16,  12,   8,   6,   4,   2,  60, 180, 300,1200
};

// �ϐ�
int stiModeNo = -1;			// ���[�h�ԍ�

int stiMarkFld[10 * 22];	// ���������Ŏg�p����u���b�N���ʗp�t�B�[���h
int stiMarkCount;			// �u���b�N���q�����Ă��鐔

int stiLevel[2];			// ���݂̃��x��
int stiScore[2];			// �X�R�A
int stiBonus[2];			// �{�[�i�X���_

int stiRatio = 20;			// �}���`�J���[�u���b�N�o����
int stiBgm = 14;			// BGM
int stiGhost = 1;			// �S�[�X�g
int stiStartLevel = 0;		// �X�^�[�g���̃��x��

// �����L���O�ϐ�
int stiRankingScore[10];	// �X�R�A
int stiRankingLevel[10];	// ���x��
int stiRankingRatio[10];	// �}���`�J���[�u���b�N�o����
int stiRankingTime[10];		// �^�C��
int stiRankingYear[10];		// �����N�C�������i�N�j
int stiRankingMonth[10];	// �����N�C�������i���j
int stiRankingDay[10];		// �����N�C�������i���j
int stiRankingHour[10];		// �����N�C�������i���j
int stiRankingMinute[10];	// �����N�C�������i���j
int stiRankingSecond[10];	// �����N�C�������i�b�j

// �C�x���g����
void stiPluginEvent(int player, int event, int *param) {
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != stiModeNo)) return;
	
	if(event == 0) {
		stiModeNo = addModePlugin("STICKY");	// ���[�h��o�^����
	} else if(event == 5) {
		stiReady(player, param);	// Ready�\����
	} else if(event == 10) {
		stiARE(player, param);	// ARE���̏���
	} else if(event == 11) {
		stiAfterErase(player, param);	// ���C������
	} else if(event == 15) {
		stiViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		stiSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		stiPlayerInitial(player);	// ������
	} else if(event == 21) {
		stiResult(player);	// ���ʕ\��
	} else if(event == 24) {
		stiStartEnding(player);	// �G���f�B���O�˓�
	} else if(event == 25) {
		stiExcellent(player, param);	// EXCELLENT���
	} else if(event == 28) {
		stiIncrementTime(player);	// ���Ԃ�i�߂�
	} else if(event == 34) {
		stiViewFieldBlock(player, param);	// �t�B�[���h�̃u���b�N��\��
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		stiSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		stiLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		stiLoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		stiReplayDetail();	// ���v���C�ڍ�
	} else if(event == 60) {
		stiMoveLock(player, param);	// ���C�������Ȃ��Ńu���b�N��u�����Ƃ�
	} else if(event == 68) {
		stiLevelClear(player);	// ���x���N���A
	}
}

// �����F�̃u���b�N�̌q����𒲂ׂ�
void stiCheckBlockColorLink(int player, int x, int y) {
	int color;
	
	if((x >= 0) && (x < 10) && (y >= 0) && (y < 22)) {
		color = getFieldBlock(player, x, y);
		
		if((color > 1) && (color < 11) && (stiMarkFld[x + y * 10] == 0)) {
			stiMarkFld[x + y * 10] = 1;
			stiMarkCount++;
			
			if(getFieldBlock(player, x, y - 1) == color) stiCheckBlockColorLink(player, x, y - 1);
			if(getFieldBlock(player, x, y + 1) == color) stiCheckBlockColorLink(player, x, y + 1);
			if(getFieldBlock(player, x - 1, y) == color) stiCheckBlockColorLink(player, x - 1, y);
			if(getFieldBlock(player, x + 1, y) == color) stiCheckBlockColorLink(player, x + 1, y);
		}
	}
}

// �q�����Ă���u���b�N�𒲂ׂ�
void stiCheckBlockRealLink(int player, int x, int y) {
	int temp;
	
	if((x >= 0) && (x < 10) && (y >= 0) && (y < 22)) {
		if((getFieldBlock(player, x, y) > 1) && (getFieldBlock(player, x, y) < 11) && (stiMarkFld[x + y * 10] == 0)) {
			stiMarkFld[x + y * 10] = 1;
			
			temp = getFieldBlockL(player, x, y);
			if(BitTest(temp, 0)) stiCheckBlockRealLink(player, x, y - 1);
			if(BitTest(temp, 1)) stiCheckBlockRealLink(player, x, y + 1);
			if(BitTest(temp, 2)) stiCheckBlockRealLink(player, x - 1, y);
			if(BitTest(temp, 3)) stiCheckBlockRealLink(player, x + 1, y);
		}
	}
}

// �u���b�N�̌q����󋵂��X�V
void stiUpdateBlockLink(int player, int x, int y) {
	int color, temp;
	
	if((x >= 0) && (x < 10) && (y >= 0) && (y < 22)) {
		color = getFieldBlock(player, x, y);
		
		if((color > 1) && (color < 11) && (stiMarkFld[x + y * 10] == 0)) {
			stiMarkFld[x + y * 10] = 1;
			stiMarkCount++;
			
			temp = 0;
			
			if(getFieldBlock(player, x, y - 1) == color) {
				stiUpdateBlockLink(player, x, y - 1);
				temp = BitSet(temp, 0, 1);
			}
			if(getFieldBlock(player, x, y + 1) == color) {
				stiUpdateBlockLink(player, x, y + 1);
				temp = BitSet(temp, 1, 1);
			}
			if(getFieldBlock(player, x - 1, y) == color) {
				stiUpdateBlockLink(player, x - 1, y);
				temp = BitSet(temp, 2, 1);
			}
			if(getFieldBlock(player, x + 1, y) == color) {
				stiUpdateBlockLink(player, x + 1, y);
				temp = BitSet(temp, 3, 1);
			}
			
			setFieldBlockL(player, x, y, temp);
		}
	}
}

// �u���b�N�̌q����󋵂��X�V�i�t�B�[���h�S�́j
void stiUpdateBlockLinkAll(int player) {
	int i, j;
	
	for(i = 0; i < 220; i++) stiMarkFld[i] = 0;
	
	for(i = 0; i < 22; i++) {
		for(j = 0; j < 10; j++) {
			stiUpdateBlockLink(player, j, i);
		}
	}
}

// �������u���b�N�𗎂Ƃ��i�������ꍇ�͖߂�l��1�ɂȂ�j
int stiFallBlock(int player, int x, int y) {
	int i, j, fall, temp, color;
	
	fall = 0;
	color = getFieldBlock(player, x, y);
	
	if((color > 1) && (color < 11)) {
		fall = 1;
		
		for(i = 0; i < 220; i++) stiMarkFld[i] = 0;
		stiCheckBlockRealLink(player, x, y);
		
		// �u���b�N�̉��ɋ�Ԃ����邩�`�F�b�N�i���������璆�~�j
		for(i = 21; i >= 0; i--) {
			for(j = 0; j < 10; j++) {
				if(stiMarkFld[j + i * 10] == 1) {
					if( (i == 21) || ((getFieldBlock(player, j, i + 1) != 0) && (stiMarkFld[j + (i + 1) * 10] == 0)) ) {
						fall = 0;
					}
				}
			}
		}
		
		// 1�}�X���ɗ��Ƃ�
		if(fall) {
			for(i = 21; i >= 0; i--) {
				for(j = 0; j < 10; j++) {
					if(stiMarkFld[j + i * 10] == 1) {
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

// 25�ȏ�q�����Ă���u���b�N������
int stiErase25Block(int player, int x, int y) {
	int i, j, result, temp;
	
	result = 0;
	
	if((getFieldBlock(player, x, y) > 1) && (getFieldBlock(player, x, y) < 11)) {
		for(i = 0; i < 220; i++) stiMarkFld[i] = 0;
		stiMarkCount = 0;
		stiCheckBlockColorLink(player, x, y);
		
		if(stiMarkCount >= 25) {
			result = 1;
			
			for(i = 0; i < 22; i++) {
				for(j = 0; j < 10; j++) {
					if(stiMarkFld[j + i * 10] == 1) {
						temp = getFieldBlock(player, j, i);
						objectCreate(player, 1, foffset[player] + 8 + (j * 8), fyoffset[player] + (i + 3) * 8, (j - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + 1 * 250, temp - 1, 100);
						PlaySE(se_erase[0]);
						
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
	
	return result;
}

// ���C������
void stiAfterErase(int player, int *param) {
	int i, j, temp, fall;
	
	if(statc[player * 10] >= wait2[player]) {
		param[0] = 1;	// �ʏ�̃��C��������̏������X�L�b�v����
		
		if(statc[player * 10] == wait2[player]) {
			// �ʏ�ʂ�Ƀu���b�N�𗎂Ƃ�
			temp = downFloatingBlocks(player);
			if(temp) statc[player * 10 + 1] = 1;
			for(i = 0; i < 22; i++) erase[i + player * 22] = 0;
			
			// �u���b�N�̌q����󋵂��X�V
			stiUpdateBlockLinkAll(player);
		}
		
		// ����
		fall = 0;
		
		for(i = 21; i >= 0; i--) {
			for(j = 0; j < 10; j++) {
				if(stiFallBlock(player, j, i)) fall = 1;
				
				if(fall) statc[player * 10 + 1] = 1;
			}
		}
		
		// �����Ȃ��Ȃ�����
		if(!fall) {
			if(statc[player * 10 + 1]) PlaySE(se_gon);
			pinchCheck(player);
			
			// 25�ȏ�q�����Ă���u���b�N������
			temp = 0;
			
			for(i = 21; i >= 0; i--) {
				for(j = 0; j < 10; j++) {
					if(stiErase25Block(player, j, i)) temp = 1;
				}
			}
			
			// 25�ȏ�q�����Ă���u���b�N�������ꍇ
			if(!temp) {
				stiUpdateBlockLinkAll(player);
				
				if(blockEraseJudge(player)) {
					// �A��
					statc[player * 10] = 0;
				} else {
					// �I��
					stat[player] = 5;
					resetStatc(player);
					statc[player * 10] = wait1[player];
				}
			} else {
				statc[player * 10] = 0;
			}
			return;
		}
	}
	
	if(param[0]) statc[player * 10]++;
}

// �t�B�[���h�̃u���b�N��\��
void stiViewFieldBlock(int player, int *param) {
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

// ������
void stiPlayerInitial(int player) {
	// �ϐ���������
	stiLevel[player] = stiStartLevel;
	stiScore[player] = 0;
	stiBonus[player] = 0;
	
	// �g�̐F��ς���
	framecolor[player] = 5;
	frame_decoration[player] = 1;
	
	// �}���`�J���[�u���b�N�L��
	if(stiRatio) {
		multicolor_enable[player] = 1;
		multicolor_ratio[player] = stiRatio;
	} else {
		multicolor_enable[player] = 0;
	}
	
	// BGM
	bgmlv = stiBgm;
	
	// �S�[�X�g
	if(stiGhost == 0) ghost[player] = 0;
	
	// �������x
	sp[player] = stiLevelTable[stiLevel[player]];
	if(stiLevel[player] >= 11) speedtype[player] = 0;
	else speedtype[player] = 1;
	wait2[player] = 20;
	
	backno = stiLevel[player];
}

// ���C�������Ȃ��Ńu���b�N��u�����Ƃ�
void stiMoveLock(int player, int *param) {
	param[0] = 1;
	stat[player] = 6;
	resetStatc(player);
	statc[player * 10] = wait2[player];
}

// �t�B�[���h�����Z�b�g���ז��u���b�N�����
void stiMakeGarbage(int player) {
	int i, j, k, x, block;
	
	// �t�B�[���h���Z�b�g
	resetField(player);
	
	// �ז��u���b�N�쐬
	k = 21 - (stiLevel[player] + 1);
	
	for(i = 21; i >= k; i--) {
		for(j = 0; j < 5; j++) {
			retry:
			
			x = GiziRand(player, 10);
			
			if(getFieldBlock(player, x, i) == 0) {
				if(i == 21) block = Rand(7) + 11;
				else block = 1;
				setFieldBlock(player, x, i, block);
				setFieldBlockT(player, x, i, -1);
			} else {
				goto retry;
			}
		}
	}
	
	// �{�[�i�X���_���Z�b�g
	stiBonus[player] = (3600 * 2) * ((110 - stiRatio) / 10);
}

// ���x���N���A
void stiLevelClear(int player) {
	int i, j;
	
	// �u���b�N������
	i = 21 - statc[player * 10];
	
	if(i == 0) PlaySE(se_applause);
	
	for(j = 0; j < 10; j++) {
		if(getFieldBlock(player, j, i) > 0) {
			objectCreate(player, 1, foffset[player] + 8 + (j * 8), fyoffset[player] + (i + 3) * 8, (j - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + 1 * 250, getFieldBlock(player, j, i) - 1, 100);
			
			setFieldBlock(player, j, i, 0);
			setFieldBlockT(player, j, i, 0);
			setFieldBlockO(player, j, i, 0);
			setFieldBlockL(player, j, i, 0);
			setFieldBlockI(player, j, i, 0);
		}
	}
	
	if(statc[player * 10] >= 21) {
		// ���̃��x����
		PlaySE(se_rankup);
		
		stiLevel[player]++;
		stiMakeGarbage(player);
		
		sp[player] = stiLevelTable[stiLevel[player]];
		if(stiLevel[player] >= 11) speedtype[player] = 0;
		
		bgfadesw = 1;
		bgfadebg = stiLevel[player];
		
		timeOn[player] = 1;
		
		stat[player] = 4;
		resetStatc(player);
	} else {
		statc[player * 10]++;
	}
}

// ARE���̏���
void stiARE(int player, int *param) {
	// ���x���N���A����
	if(checkHowManyPBlocks(player) == 0) {
		timeOn[player] = 0;
		stiScore[player] = stiScore[player] + stiBonus[player];
		
		if(stiLevel[player] >= 14) {
			ending[player] = 1;
		} else {
			param[0] = 1;
			stat[player] = 2;
			resetStatc(player);
		}
	}
}

// Ready�\����
void stiReady(int player, int *param) {
	if(!statc[player * 10]) stiMakeGarbage(player);
}

// ���Ԃ�i�߂�
void stiIncrementTime(int player) {
	// �{�[�i�X����
	if(timeOn[player]) {
		if(stiBonus[player] > 0) stiBonus[player] = stiBonus[player] - (1 * ((110 - stiRatio) / 10));
	}
}

// �G���f�B���O�˓�
void stiStartEnding(int player) {
	onRecord[player] = 0;
	ending[player] = 3;
	resetStatc(player);
}

// EXCELLENT���
void stiExcellent(int player, int *param) {
	printTinyFont(foffset[player] + 19, fyoffset[player] + 116, "STICKY MODE");
	printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
	
	// �ԉ�
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// �X�R�A�\��
void stiViewScore(int player) {
	int color;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// �X�R�A
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "SCORE");
	sprintf(string[0], "%d", stiScore[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// �{�[�i�X
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "BONUS");
	sprintf(string[0], "%d", stiBonus[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// ���x��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 76, "LEVEL");
	sprintf(string[0], "%d", stiLevel[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 84, string[0], color);
	
	// �^�C��
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
}

// ���ʕ\��
void stiResult(int player) {
	// �����L���O�o�^
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = stiRegistRanking(player);
		if(statc[player * 10 + 1] != -1) stiSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "SCORE");
	sprintf(string[0], "%13d", stiScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", stiLevel[player] + 1);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "TIME");
	getTime(gameTimer[player]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[1], 0);
	
	if(statc[player * 10 + 1] != -1) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 139, "RANK");
		sprintf(string[0], "%13d", statc[player * 10 + 1] + 1);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 147, string[0], 0);
	}
}

// BGM�ǂݍ���
void stiLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(stiBgm);
	}
}

// ���v���C�ۑ�
void stiSaveReplay(int player) {
	saveBuf[900] = stiLevel[player];
	saveBuf[901] = stiScore[player];
	saveBuf[902] = stiRatio;
	saveBuf[903] = stiBgm;
	saveBuf[904] = stiGhost;
	saveBuf[905] = stiStartLevel;
}

// ���v���C�ǂݍ���
void stiLoadReplay(int player) {
	stiRatio = saveBuf[902];
	stiBgm = saveBuf[903];
	stiGhost = saveBuf[904];
	stiStartLevel = saveBuf[905];
	
	// �ݒ�𔽉f������
	stiPlayerInitial(player);
}

// ���v���C�ڍ�
void stiReplayDetail() {
	printFontGrid(1, 4, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[901]);
	printFontGrid(22, 4, string[0], 0);
	
	printFontGrid(1, 5, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[900]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 7, "MULTI-COLOR RATIO", 0);
	sprintf(string[0], "%d%%", saveBuf[902]);
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 8, "BGM", 0);
	sprintf(string[0], "%d", saveBuf[903]);
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "GHOST BLOCK", 0);
	sprintf(string[0], "%d", saveBuf[904]);
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[905] + 1);
	printFontGrid(22, 10, string[0], 0);
}

// �ݒ���
void stiSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	stiLoadConfig();
	
	// �����L���O��ǂݍ���
	if(!stiLoadRanking(player)) stiInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "STICKY OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2,  3, "MULTI-COLOR RATIO", 7 * (cursor == 0));
		printFontGrid(2,  4, "BGM",               7 * (cursor == 1));
		printFontGrid(2,  5, "GHOST BLOCK",       7 * (cursor == 2));
		printFontGrid(2,  6, "START LEVEL",       7 * (cursor == 3));
		
		// �ݒ�l�\��
		sprintf(string[0], "%d%%", stiRatio);
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		sprintf(string[0], "%d", stiBgm);
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!stiGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "%d", stiStartLevel + 1);
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		// �J�[�\���ړ�
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 3;
			if(cursor > 3) cursor = 0;
		}
		
		// �l��ύX
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) {
				stiRatio = stiRatio + move;
				if(stiRatio < 0) stiRatio = 100;
				if(stiRatio > 100) stiRatio = 0;
			}
			if(cursor == 1) {
				stiBgm = stiBgm + move;
				if(stiBgm < 0) stiBgm = 29;
				if(stiBgm > 29) stiBgm = 0;
			}
			if(cursor == 2) stiGhost = !stiGhost;
			if(cursor == 3) {
				stiStartLevel = stiStartLevel + move;
				if(stiStartLevel < 0) stiStartLevel = 14;
				if(stiStartLevel > 14) stiStartLevel = 0;
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
			stiSaveConfig();
			PlayWave(se_kettei);
			return;
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			stiViewRanking(player);
		}
	}
}

// �ݒ��ۑ�
void stiSaveConfig() {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �ݒ���e
	saveBuf[1] = stiRatio;
	saveBuf[2] = stiBgm;
	saveBuf[3] = stiGhost;
	saveBuf[4] = stiStartLevel;
	
	SaveFile("config/STICKY_CONFIG.SAV", &saveBuf, 50 * 4);
}

// �ݒ��ǂݍ���
int stiLoadConfig() {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/STICKY_CONFIG.SAV", &saveBuf, 50 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �ݒ���e
	stiRatio = saveBuf[1];
	stiBgm = saveBuf[2];
	stiGhost = saveBuf[3];
	stiStartLevel = saveBuf[4];
	
	return 1;
}

// �����L���O�ۑ�
void stiSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 10) + 0] = stiRankingScore[i];
		saveBuf[1 + (i * 10) + 1] = stiRankingLevel[i];
		saveBuf[1 + (i * 10) + 2] = stiRankingRatio[i];
		saveBuf[1 + (i * 10) + 3] = stiRankingTime[i];
		saveBuf[1 + (i * 10) + 4] = stiRankingYear[i];
		saveBuf[1 + (i * 10) + 5] = stiRankingMonth[i];
		saveBuf[1 + (i * 10) + 6] = stiRankingDay[i];
		saveBuf[1 + (i * 10) + 7] = stiRankingHour[i];
		saveBuf[1 + (i * 10) + 8] = stiRankingMinute[i];
		saveBuf[1 + (i * 10) + 9] = stiRankingSecond[i];
	}
	
	sprintf(string[0], "config/STICKY_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 111 * 4);
}

// �����L���O�ǂݍ���
int stiLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/STICKY_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 111 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		stiRankingScore[i]  = saveBuf[1 + (i * 10) + 0];
		stiRankingLevel[i]  = saveBuf[1 + (i * 10) + 1];
		stiRankingRatio[i]  = saveBuf[1 + (i * 10) + 2];
		stiRankingTime[i]   = saveBuf[1 + (i * 10) + 3];
		stiRankingYear[i]   = saveBuf[1 + (i * 10) + 4];
		stiRankingMonth[i]  = saveBuf[1 + (i * 10) + 5];
		stiRankingDay[i]    = saveBuf[1 + (i * 10) + 6];
		stiRankingHour[i]   = saveBuf[1 + (i * 10) + 7];
		stiRankingMinute[i] = saveBuf[1 + (i * 10) + 8];
		stiRankingSecond[i] = saveBuf[1 + (i * 10) + 9];
	}
	
	return 1;
}

// �����L���O������
void stiInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		stiRankingScore[i]  = 0;
		stiRankingLevel[i]  = 0;
		stiRankingRatio[i]  = 0;
		stiRankingTime[i]   = 0;
		stiRankingYear[i]   = 0;
		stiRankingMonth[i]  = 0;
		stiRankingDay[i]    = 0;
		stiRankingHour[i]   = 0;
		stiRankingMinute[i] = 0;
		stiRankingSecond[i] = 0;
	}
}

// �����L���O�o�^
int stiRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if(playback) return -1;
	
	for(i = 0; i < 10; i++) {
		// �����N�C��
		if((stiScore[player] > stiRankingScore[i]) || 
		   ((stiScore[player] == stiRankingScore[i]) && (gameTimer[player] < stiRankingTime[i])))
		{
			// �����L���O�����炷
			for(j = 9; j > i; j--) {
				stiRankingScore[j]  = stiRankingScore[j - 1];
				stiRankingLevel[j]  = stiRankingLevel[j - 1];
				stiRankingRatio[j]  = stiRankingRatio[j - 1];
				stiRankingTime[j]   = stiRankingTime[j - 1];
				stiRankingYear[j]   = stiRankingYear[j - 1];
				stiRankingMonth[j]  = stiRankingMonth[j - 1];
				stiRankingDay[j]    = stiRankingDay[j - 1];
				stiRankingHour[j]   = stiRankingHour[j - 1];
				stiRankingMinute[j] = stiRankingMinute[j - 1];
				stiRankingSecond[j] = stiRankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			stiRankingScore[i]   = stiScore[player];
			stiRankingLevel[i]   = stiLevel[player];
			stiRankingRatio[i]   = stiRatio;
			stiRankingTime[i]    = gameTimer[player];
			
			GetDateAndTime(&timebuf);
			stiRankingYear[i]    = timebuf[0];
			stiRankingMonth[i]   = timebuf[1];
			stiRankingDay[i]     = timebuf[2];
			stiRankingHour[i]    = timebuf[4];
			stiRankingMinute[i]  = timebuf[5];
			stiRankingSecond[i]  = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �����L���O�\��
void stiViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "STICKY MODE RANKING", 6);
		printFontGrid(1, 3, "RANK SCORE    LEVEL RATIO TIME", 4);
		
		for(i = 0; i < 10; i++) {
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", stiRankingScore[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", stiRankingLevel[i] + 1);
			printFontGrid(15, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d%%", stiRankingRatio[i]);
			printFontGrid(21, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(stiRankingTime[i]);
			printFontGrid(27, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// ���t�Ǝ���
			sprintf(string[0],
			        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
			        stiRankingYear[cursor], stiRankingMonth[cursor], stiRankingDay[cursor],
			        stiRankingHour[cursor], stiRankingMinute[cursor], stiRankingSecond[cursor]);
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
				stiInitRanking();
				stiSaveRanking(player);
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
