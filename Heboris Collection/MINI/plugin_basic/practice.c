//PRACTICE
//prefix:pra

int praVersion;				// �o�[�W�����ԍ�
int praCVersion = 9;		// ���݂̃o�[�W����

int praRuleNumber = -1;		// ���[�h�ԍ�

int praScore[2];			// �X�R�A
int praLines[2];			// ���C��
int praLevel[2];			// ���x��
int praTimer[2];			// ��������
int praGoalPoint[2];		// ���x���A�b�v�܂ł̃|�C���g��

int praTSpinFrame[2];		// T-SPIN�\���^�w�{���X�\���̎c�莞��
int praTSpinLine[2];		// �Ō��T-SPIN���C�������^�w�{���X�����̎��
int praComboFrame[2];		// �R���{���\���̎c�莞��
int praB2BFrame[2];			// Back To Back�\���̎c�莞��
int praTSpinWall[2];		// �ǏR�肠���T-SPIN��������1�ɂȂ�
int praScoreGet[2];			// ���������X�R�A�\���̓_��
int praScoreFrame[2];		// ���������X�R�A�\���̎c�莞��
int praGoalGet[2];			// ���������|�C���g�\���̓_��
int praGoalFrame[2];		// ���������|�C���g�\���̎c�莞��

int praSpeed = 1;			// �������x
int praWait1 = 25;			// ARE
int praWait2 = 40;			// ���C������
int praWait3 = 30;			// �Œ莞��
int praWaitt = 16;			// ������
int praBig = 0;				// BIG���[�h
int praBMove = 1;			// BIG���̉��ړ��P��
int praOBlk = 0;			// ����c�l
int praGoal = 0;			// �S�[�����x��
int praRoll = 0;			// �X�^�b�t���[���̗L��
int praEnd = 0;				// �N���A��ʂ̎��
int praBGM = 0;				// BGM
int praEBGM = 6;			// �G���f�B���O��BGM
int praBack = 0;			// �w�i
int praLvUpBonus = 1;		// ���x���A�b�v�{�[�i�X
int praGhost = 0;			// �S�[�X�g�i0=LV100 1=��ɂ��� 2=��ɂȂ��j
int praFieldColor = 3;		// �t�B�[���h�̘g�̐F
int praDecoration = 0;		// �t�B�[���h�̏���
int praSpeedType = 0;		// �X�s�[�h�^�C�v
int praLvType = 0;			// ���x���^�C�v�i0=NORMAL 1=10LINES 2=POINTS�j
int praTimeLimit = 0;		// �������ԁi0=�Ȃ��j
int praEnableCombo = 1;		// �R���{�{�[�i�X�̗L��
int praTSpin = 3;			// T-SPIN�̎��
int praEnableB2B = 1;		// Back To Back�̗L���i0=�Ȃ� 1=�ʏ� 2=�w�{���X�̂� 3=T-SPIN�̂݁j
int praWait4 = -1;			// �Œ莞�ԁi�i�����痎����j
int praWait5 = -1;			// ���C���������ARE

int praStage = 0;			// �g�p����X�e�[�W�i0=�Ȃ��j
int praInitFld[10 * 22];	// �X�^�[�g���̒n�`

int praPreset[30 * 5];		// �v���Z�b�g
int praLastPresetNo = 0;	// �Ō�ɑI�������v���Z�b�g�ԍ�

int praReplayDetailPage = 0;	// ���v���C�ڍ׉�ʂ̃y�[�W�ԍ�

// ���i�ʂ̕\����
str praStrSecretGradeName[19] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0�` 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9�`17
	"GM"													// 18
};

// �C�x���g�������ɌĂ΂��
void praPluginEvent(int player, int event, int *param) {
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != praRuleNumber)) return;
	
	if(event == 0) {
		praRuleNumber = addModePlugin("PRACTICE");	// ���[�h��o�^����
	} else if(event == 7) {
		if(!ending[player]) praMoveInit(player, param);	// �u���b�N�o���̏u�Ԃ̏���
	} else if(event == 8) {
		praSoftDropScore(player);	// �\�t�g�h���b�v�œ������_�������Z
	} else if(event == 12) {
		// �X�R�A�v�Z
		if(!ending[player]) {
			if(praLvType == 0) praCalcScore(player, param[0]);
			if(praLvType == 1) praCalcScore2(player, param[0]);
			if(praLvType == 2) praCalcScore3(player, param[0]);
		}
	} else if(event == 15) {
		// �X�R�A�\��
		if(praLvType == 0) praViewScore(player);
		if(praLvType == 1) praViewScore2(player);
		if(praLvType == 2) praViewScore3(player);
	} else if(event == 17) {
		praSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		praPlayerInitial(player);	// �Q�[���J�n�O�̏�����
	} else if(event == 21) {
		praResult(player, param);	// ���ʕ\��
	} else if(event == 24) {
		praEndingStart(player);	// �G���f�B���O�˓�
	} else if(event == 25) {
		praExcellent(player, param);	// EXCELLENT���
	} else if(event == 28) {
		praIncrementTime(player);	// ���Ԃ�i�߂�
	} else if(event == 36) {
		praStaffRoll(player, param);	// �X�^�b�t���[���`��
	} else if(event == 38) {
		praPlayBGM(player);	// BGM�Đ�
	} else if(event == 39) {
		praSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		praLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		praLoadBGM();	// BGM�ǂݍ���
	} else if(event == 48) {
		praSoftDropOld(player);	// �\�t�g�h���b�v�i���j
	} else if(event == 49) {
		praHardDrop(player, param[1]);	// �n�[�h�h���b�v
	} else if(event == 55) {
		praReplayDetail();	// ���v���C�ڍ�
	} else if(event == 59) {
		praTSpinZero(player);	// ���C�������Ȃ���T-SPIN
	} else if(event == 70) {
		praRetry(player, param);	// ���g���C
	}
}

// �Q�[���J�n�O�̏�����
void praPlayerInitial(int player) {
	int i;
	
	// �o�[�W����
	if(!playback) praVersion = praCVersion;
	
	// �ݒ�𔽉f������
	sp[player] = praSpeed;
	wait1[player] = praWait1;
	wait2[player] = praWait2;
	wait3[player] = praWait3;
	waitt[player] = praWaitt;
	wait4[player] = praWait4;
	wait5[player] = praWait5;
	IsBig[player] = praBig;
	BigMove[player] = praBMove;
	oblk_spawn[player] = praOBlk;
	backno = praBack;
	if(praGhost == 2) ghost[player] = 0;
	framecolor[player] = praFieldColor;
	frame_decoration[player] = praDecoration;
	speedtype[player] = praSpeedType;
	praTimer[player] = praTimeLimit;
	
	if(praLvType == 1) enable_combo[player] = 0;
	else enable_combo[player] = praEnableCombo;
	
	if(praLvType == 2) {
		tspin_type[player] = praTSpin;
		b_to_b_type[player] = praEnableB2B;
	} else {
		tspin_type[player] = 0;
		b_to_b_type[player] = 0;
	}
	
	// �ϐ���������
	praScore[player] = 0;
	praLines[player] = 0;
	if(praLvType == 0) praLevel[player] = -1;
	else praLevel[player] = 0;
	praGoalPoint[player] = 5;
	
	praTSpinFrame[player] = 0;
	praTSpinLine[player] = 0;
	praComboFrame[player] = 0;
	praB2BFrame[player] = 0;
	praTSpinWall[player] = 0;
	praScoreGet[player] = 0;
	praScoreFrame[player] = 0;
	praGoalGet[player] = 0;
	praGoalFrame[player] = 0;
	
	// �X�e�[�W��ǂݍ���
	if(!playback) {
		if(praStage > 0) praLoadStage(player, praStage);
		for(i = 0; i < 220; i++) praInitFld[i] = fld[i + player * 220];
	} else {
		for(i = 0; i < 220; i++) fld[i + player * 220] = praInitFld[i];
		disableShadowTimer(player);
	}
}

// �u���b�N�o���̏u�Ԃ̏���
void praMoveInit(int player, int *param) {
	if(statc[player * 10 + 3] == 0) {
		// ���x���A�b�v
		if((praLevel[player] % 100 != 99) && (praLvType == 0)) {
			praLevel[player]++;
			if(praLevel[player] % 100 == 99) PlaySE(se_lvstop);
		}
		
		// �^�C�}�[�ĊJ
		if(praLvType == 1) timeOn[player] = 1;
	}
}

// �X�R�A�v�Z�ipraLvType == 0�j
void praCalcScore(int player, int lines) {
	int temp, temp2, bo, bai, all, nextsec;
	
	if(praVersion >= 5) {
		if(!praLvUpBonus) temp = praLevel[player] + lines;
		else temp = praLevel[player] + lines + ((lines >= 3) * (lines - 2));
		if(temp > praGoal * 100) temp = praGoal * 100;
		
		temp2 = wait3[player] - bactivetime[player];
		if(temp2 < 0) temp2 = 0;
		
		bo = ((praLevel[player] + lines) / 4 + sdrop[player] + qdrop[player] + qput[player]) * lines * cmbpts[player] + (temp / 2) + (temp2 * 7);
		bai = 1;
	} else {
		bo = (praLevel[player] + lines) / 4 + sdrop[player] + qdrop[player] + qput[player];
		bai = (lines * 2 - 1 + cmbpts[player] - (lines * 2 - 2)) * lines;
	}
	
	all = isBravo(player);	// �S�����`�F�b�N
	if(all) {
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		bai = bai * 4;
	}
	
	// �X�R�A���Z
	praScore[player] = praScore[player] + bo * bai;
	praLines[player] = praLines[player] + lines;
	
	// ���x���A�b�v
	nextsec = praLevel[player] / 100 * 100 + 100;
	if(!praLvUpBonus) praLevel[player] = praLevel[player] + lines;
	else praLevel[player] = praLevel[player] + lines + ((lines >= 3) * (lines - 2));
	
	// �S�[�X�g������
	if((praLevel[player] >= 100) && (praGhost == 0)) {
		ghost[player] = 0;
	}
	
	if((praGoal != 0) && (praLevel[player] >= praGoal * 100)) {
		// �G���f�B���O
		StopSE(se_hurryup);
		praLevel[player] = praGoal * 100;
		timeOn[player] = 0;
		
		if(praRoll == 2) {
			PlaySE(se_ttclear);
			ending[player] = 2;
			ending_timeOn[player] = 1;
			fastroll[player] = 1;
		} else {
			ending[player] = 1;
		}
	} else {
		// ���x���X�g�b�v��
		if(praLevel[player] % 100 == 99) PlaySE(se_lvstop);
		// ���x���A�b�v��
		if(praLevel[player] >= nextsec) PlaySE(se_levelup);
	}
}

// �X�R�A�v�Z�ipraLvType == 1�j
void praCalcScore2(int player, int lines) {
	// ���C�������Z
	praLines[player] = praLines[player] + lines;
	
	// �S����
	if(isBravo(player)) {
		PlaySE(se_levelup);
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
	}
	
	if((praGoal != 0) && (praLines[player] >= praGoal * 10)) {
		// �G���f�B���O
		StopSE(se_hurryup);
		praLines[player] = praGoal * 10;
		timeOn[player] = 0;
		
		if(praRoll == 2) {
			PlaySE(se_ttclear);
			ending[player] = 2;
			ending_timeOn[player] = 1;
			fastroll[player] = 1;
		} else {
			ending[player] = 1;
		}
	} else if(praLines[player] >= (praLevel[player] + 1) * 10) {
		// ���x���A�b�v
		PlaySE(se_rankup);
		StopSE(se_hurryup);
		timeOn[player] = 0;
		praTimer[player] = praTimeLimit;
		praLevel[player]++;
	}
}

// �X�R�A�v�Z�ipraLvType == 2�j
void praCalcScore3(int player, int lines) {
	int bo, b2b, combopts, combogoal, points;
	
	// T-SPIN��
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		praTSpinFrame[player] = 60;
		praTSpinLine[player] = lines;
		praTSpinWall[player] = (last_command[player] == 4);
		
		if((lines == 1) && (praTSpinWall[player])) bo = 2;	// �ǏR�肠��T-SPIN Single
		if((lines == 1) && (!praTSpinWall[player])) bo = 8;	// �ǏR��Ȃ�T-SPIN Single
		if(lines == 2) bo = 12;	// T-SPIN Double
		if(lines == 3) bo = 16;	// T-SPIN Triple
	}
	// ���ʂ̃��C������
	else {
		if(lines == 1) bo = 1;
		if(lines == 2) bo = 3;
		if(lines == 3) bo = 5;
		if(lines == 4) {
			praTSpinFrame[player] = 60;
			praTSpinLine[player] = lines;
			bo = 8;
		}
	}
	
	// B2B�{�[�i�X�ix 1.5�j
	if((praEnableB2B != 0) && (b_to_b_count[player] >= 2)) {
		b2b = 1;
		praB2BFrame[player] = 60;
	} else {
		b2b = 0;
		praB2BFrame[player] = 0;
	}
	
	// �R���{�{�[�i�X
	if((praEnableCombo != 0) && (combo[player] >= 2)) {
		combopts = (combo[player] - 1) * 50;
		
		if(combo[player] >= 12) combogoal = 5;
		else if(combo[player] >= 9) combogoal = 4;
		else if(combo[player] >= 7) combogoal = 3;
		else if(combo[player] >= 5) combogoal = 2;
		else if(combo[player] >= 3) combogoal = 1;
		else combogoal = 0;
		
		praComboFrame[player] = 60;
	} else {
		combopts = 0;
		combogoal = 0;
	}
	
	// �S�����{�[�i�X
	if(isBravo(player)) {
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		bo = bo + 50;
	}
	
	// �X�R�A���Z
	points = (bo * 100) * (praLevel[player] + 1);
	praScore[player] = praScore[player] + points;
	if(b2b) praScore[player] = praScore[player] + (points / 2);
	praScore[player] = praScore[player] + combopts;
	
	praScoreGet[player] = points + ((points / 2) * (b2b)) + combopts;
	praScoreFrame[player] = 120;
	
	// ���C�����Z
	praLines[player] = praLines[player] + lines;
	
	// �S�[������
	praGoalPoint[player] = praGoalPoint[player] - bo;
	if(b2b) praGoalPoint[player] = praGoalPoint[player] - (bo / 2);
	praGoalPoint[player] = praGoalPoint[player] - combogoal;
	
	praGoalGet[player] = bo + ((bo / 2) * (b2b)) + combogoal;
	praGoalFrame[player] = 120;
	
	// ���x���A�b�v
	praLevelUpMarathon(player);
}

// ���C�������Ȃ���T-SPIN
void praTSpinZero(int player) {
	// �G���f�B���O���͎��s���Ȃ�
	if((praVersion >= 7) && (ending[player] != 0)) return;
	
	PlaySE(se_tspin);
	praTSpinFrame[player] = 60;
	praTSpinLine[player] = 0;
	
	// �ǏR�肠��
	if(last_command[player] == 4) {
		praScore[player] = praScore[player] + (100 * (praLevel[player] + 1));
		praGoalPoint[player] = praGoalPoint[player] - 1;
		praTSpinWall[player] = 1;
		
		praScoreGet[player] = 100 * (praLevel[player] + 1);
		praScoreFrame[player] = 120;
		
		praGoalGet[player] = 1;
		praGoalFrame[player] = 120;
	}
	// �ǏR��Ȃ�
	else {
		praScore[player] = praScore[player] + (400 * (praLevel[player] + 1));
		praGoalPoint[player] = praGoalPoint[player] - 4;
		praTSpinWall[player] = 0;
		
		praScoreGet[player] = 400 * (praLevel[player] + 1);
		praScoreFrame[player] = 120;
		
		praGoalGet[player] = 4;
		praGoalFrame[player] = 120;
	}
	
	// ���x���A�b�v
	praLevelUpMarathon(player);
}

// ���x���A�b�v�ipraLvType == 2�j
void praLevelUpMarathon(int player) {
	if(praGoalPoint[player] <= 0) {
		if((praGoal != 0) && (praLevel[player] >= praGoal - 1)) {
			// �G���f�B���O
			StopSE(se_hurryup);
			praGoalPoint[player] = 0;
			timeOn[player] = 0;
			
			if(praRoll == 2) {
				PlaySE(se_ttclear);
				ending[player] = 2;
				ending_timeOn[player] = 1;
				fastroll[player] = 1;
			} else {
				ending[player] = 1;
			}
		} else {
			// ���x���A�b�v
			PlaySE(se_rankup);
			StopSE(se_hurryup);
			praTimer[player] = praTimeLimit;
			praLevel[player]++;
			praGoalPoint[player] = (praLevel[player] + 1) * 5;
		}
	}
}

// �\�t�g�h���b�v�i���j�ipraLvType == 2�j
void praSoftDropOld(int player) {
	// �G���f�B���O���͎��s���Ȃ�
	if((praVersion >= 7) && (ending[player] != 0)) return;
	
	if((praLvType == 2) && (!down_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) && (engineVer <= 12)) {
		if((speedtype[player] == 1) || (sp[player] < (softspeed[player] + 1) * 30)) {
			praScore[player]++;
		}
	}
}

// �n�[�h�h���b�v�ipraLvType == 2�j
void praHardDrop(int player, int bottom) {
	// �G���f�B���O���͎��s���Ȃ�
	if((praVersion >= 7) && (ending[player] != 0)) return;
	
	if((praLvType == 2) && (!up_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0)) {
		praScore[player] = praScore[player] + (bottom - by[player]) * 2;
	}
}

// �\�t�g�h���b�v�œ������_�������Z
void praSoftDropScore(int player) {
	// �G���f�B���O���͎��s���Ȃ�
	if((praVersion >= 7) && (ending[player] != 0)) return;
	
	if((praLvType == 2) && (softd_score[player] > 0)) {
		praScore[player] = praScore[player] + softd_score[player];
	}
}

// �X�R�A�\���ipraLvType == 0)
void praViewScore(int player) {
	int color, color2, temp;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// �X�R�A
	printTinyFont(foffset[player] + 96, fyoffset[player] + 117, "SCORE");
	sprintf(string[0], "%d", praScore[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 125, string[0], color);
	
	// ���C��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 135, "LINES");
	sprintf(string[0], "%d", praLines[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 143, string[0], color);
	
	// ���x���i���q�j
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(praLevel[player] == -1) sprintf(string[0], "%4d", 0);	// -1�Ȃ�0�ƕ\������(�����I�ɂ͍ŏ���-1�ɂȂ��Ă���)
	else sprintf(string[0], "%4d", praLevel[player]);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// ���x���i�����j
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	
	if(speedtype[player] == 2) {
		temp = sp[player] / 128;
		if(temp > 22) temp = 22;
		ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22 - temp, 143, 22, 1);
	} else if(speedtype[player] == 1) {
		ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22, 143, 22, 1);
	} else if(sp[player] <= 600) {
		ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22 - ((sp[player] * 24) / 660), 143, 22, 1);
	} else {
		ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 0, 143, 22, 1);
	}
	
	// ���x���i����j
	if(ending[player]) sprintf(string[0], "%4d", praLevel[player]);
	else sprintf(string[0], "%4d", praLevel[player] / 100 * 100 + 100);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, string[0], color);
	
	// �^�C��
	if(praTimeLimit) {
		if((praTimer[player] <= 60 * 10) && (timeOn[player])) color2 = (count % 4 / 2) * 2;
		else color2 = color;
		getTime(praTimer[player]);
	} else {
		color2 = color;
		getTime(gameTimer[player]);
	}
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
}

// �X�R�A�\���ipraLvType == 1)
void praViewScore2(int player) {
	int color, color2;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// ���x��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "LEVEL");
	sprintf(string[0], "%d", praLevel[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// �g�[�^���^�C��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "TOTAL TIME");
	getTime(gameTimer[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// �m���}�i���q�j
	ExBltRect(sg_smallfont, foffset[player] + 107, fyoffset[player] + 161, 0, 14, 22, 7);
	sprintf(string[0], "%4d", praLines[player]);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 169, string[0], color);
	
	// �m���}�i�����j
	ExBltRect(sg_spr, foffset[player] + 105, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 106, fyoffset[player] + 181, 22, 143, 22, 1);
	
	// �m���}�i����j
	if(ending[player]) sprintf(string[0], "%4d", praLines[player]);
	else sprintf(string[0], "%4d", (praLevel[player] + 1) * 10);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 185, string[0], color);
	
	// �c�莞��
	if(praTimeLimit) {
		if((praTimer[player] <= 60 * 10) && (timeOn[player])) color2 = 2;
		else color2 = color;
		getTime(praTimer[player]);
		printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
	} else {
		ExBltFastRect(sg_gametext, foffset[player] - 1, fyoffset[player] + 216, 1, 229 + english * 18, 98, 16);
	}
}

// �X�R�A�\���ipraLvType == 2)
void praViewScore3(int player) {
	int color, color2;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// �X�R�A
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "SCORE");
	sprintf(string[0], "%d", praScore[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// �����������_
	if(praScoreFrame[player] > 0) {
		praScoreFrame[player]--;
		sprintf(string[0], "%d", praScoreGet[player]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 58, string[0], (count % 4 / 2) * (1 + (b_to_b_count[player] != 0)));
	}
	
	// ���x��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 68, "LEVEL");
	sprintf(string[0], "%d", praLevel[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 76, string[0], color);
	
	// �S�[��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 86, "GOAL");
	sprintf(string[0], "%d", praGoalPoint[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 94, string[0], color);
	
	// ���������|�C���g
	if(praGoalFrame[player] > 0) {
		praGoalFrame[player]--;
		sprintf(string[0], "%d", praGoalGet[player]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 104, string[0], (count % 4 / 2) * (1 + (b_to_b_count[player] != 0)));
	}
	
	// �^�C��
	if(praTimeLimit) {
		if((praTimer[player] <= 60 * 10) && (timeOn[player])) color2 = (count % 4 / 2) * 2;
		else color2 = color;
		getTime(praTimer[player]);
	} else {
		color2 = color;
		getTime(gameTimer[player]);
	}
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
	
	// T-SPIN
	if(praTSpinFrame[player] > 0) {
		praTSpinFrame[player]--;
		
		if((praTSpinLine[player] == 0) && (praTSpinWall[player]))
			printTinyFont(foffset[player] + 25, fyoffset[player] + 208, "EZ T-SPIN");
		else if((praTSpinLine[player] == 0) && (!praTSpinWall[player]))
			printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "T-SPIN");
		else if((praTSpinLine[player] == 1) && (praTSpinWall[player]))
			printTinyFont(foffset[player] + 20, fyoffset[player] + 208, "T-SPIN MINI");
		else if((praTSpinLine[player] == 1) && (!praTSpinWall[player]))
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN SINGLE");
		else if(praTSpinLine[player] == 2)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN DOUBLE");
		else if(praTSpinLine[player] == 3)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN TRIPLE");
		else if(praTSpinLine[player] == 4)
			printTinyFont(foffset[player] + 30, fyoffset[player] + 208, "HEBORIS");
	}
	
	// BACK TO BACK
	if(praB2BFrame[player] > 0) {
		praB2BFrame[player]--;
		printTinyFont(foffset[player] + 18, fyoffset[player] + 200, "BACK TO BACK");
	}
	// COMBO
	else if((praComboFrame[player] > 0) && (combo[player] >= 2)) {
		praComboFrame[player]--;
		sprintf(string[0], "COMBO %d", combo[player] - 1);
		printTinyFont(foffset[player] + 30, fyoffset[player] + 200, string[0]);
	}
	else {
		praComboFrame[player] = 0;
	}
}

// �G���f�B���O�˓�
void praEndingStart(int player) {
	int i;
	
	resetStatc(player);
	
	// �X�^�b�t���[���Ȃ�
	if(praRoll == 0) {
		ending[player] = 3;
		onRecord[player] = 0;
	}
	// �ʏ�̃X�^�b�t���[��
	else if(praRoll == 1) {
		ending[player] = 2;
		stat[player] = 4;
		ending_timeOn[player] = 1;
		fastroll[player] = 0;
		
		bgmlv = praEBGM;
		PlayBGM();
	}
	// �����X�^�b�t���[��
	else if(praRoll == 2) {
		ending[player] = 2;
		stat[player] = 4;
		ending_timeOn[player] = 1;
		fastroll[player] = 1;
	}
	// ����ł��p������X�^�b�t���[��
	else {
		ending[player] = 2;
		stat[player] = 4;
		ending_timeOn[player] = 1;
		fastroll[player] = 2;
		
		bgmlv = praEBGM;
		PlayBGM();
	}
}

// EXCELLENT���
void praExcellent(int player, int *param) {
	param[0] = praEnd;
	
	// �ԉ�
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30) && (praEnd != 5)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// ���Ԃ�i�߂�
void praIncrementTime(int player) {
	int i;
	
	// ��������
	if((timeOn[player]) && (praTimeLimit != 0)) {
		// �������Ԍ���
		praTimer[player]--;
		
		// ���Ԑ؂�
		if(praTimer[player] <= 0) {
			PlaySE(se_timeover);
			praTimer[player] = 0;
			
			timeOn[player] = 0;
			onRecord[player] = 0;
			
			stat[player] = 7;
			resetStatc(player);
		}
		// �c��10�b
		else if(praTimer[player] == 10 * 60) {
			PlaySE(se_hurryup);
		}
	}
	
	// F�{�^���ō������[��������
	if((ending_timeOn[player]) && (onRecord[player]) && (fastroll[player] == 1) && (getPressState(player, 9)))
		edrec[player] = edrec[player] + 2;
	
	// ���[���I��
	if((ending[player] == 2) && (edrec[player] >= 60 * 60)) {
		ending[player] = 3;
		stat[player] = 10;
		resetStatc(player);
		onRecord[player] = 0;
	}
}

// �X�^�b�t���[���`��
void praStaffRoll(int player, int *param) {
	// F�{�^���ō������[��������
	if((ending_timeOn[player]) && (onRecord[player]) && (fastroll[player] == 1) && (getPressState(player, 9))) {
		endtime[player] = endtime[player] + 2;
		if(endtime[player] < 3100) staff_c[player]++;
	}
}

// ���ʕ\��
void praResult(int player, int *param) {
	if(statc[player * 10] == 0) {
		// ���i�ʔ���
		statc[player * 10 + 2] = checkSecretGrade(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	if(praLvType != 1) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "SCORE");
		sprintf(string[0], "%13d", praScore[player]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	}
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LINES");
	sprintf(string[0], "%13d", praLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "LEVEL");
	if(praLvType == 0) sprintf(string[0], "%13d", praLevel[player]);
	else sprintf(string[0], "%13d", praLevel[player] + 1);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 139, "TIME");
	getTime(gameTimer[player]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 147, string[1], 0);
	
	if(statc[player * 10 + 2] >= 4) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 159, "SECRET GRADE");
		sprintf(string[0], "%13s", praStrSecretGradeName[statc[player * 10 + 2]]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
	}
}

// ���g���C
void praRetry(int player, int *param) {
	param[0] = 1;	// �ʏ�̏������X�L�b�v����
	
	// ������
	gameAllInit();
	playerInitial(player);
	versusInit(player);
	stat[player] = 3;
	
	// �w�i�͂��̂܂܂ɂ���
}

// �ݒ���
void praSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(praLoadConfig() == 0) {
		praMakeDefaultPreset();
		praSaveConfig();
	}
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 26, "A:OK B:EXIT D:NEXT PAGE\n<>:1 E+<>:100 C+<>:FAST CHANGE", 6);
		
		// �y�[�W1 (�Q�[���X�s�[�h)
		if(cursor < 8) {
			printFontGrid(1, 1, "PRACTICE OPTIONS (PAGE 1/3:GAME SPEED)", 4);
			
			// �J�[�\���\��
			printFontGrid(1, 3 + cursor, "b", 7);
			
			// ���j���[�\��
			printFontGrid(2, 3, "SPEED",      7 * (cursor == 0));
			printFontGrid(2, 4, "SPEED TYPE", 7 * (cursor == 1));
			if(!english) {
				printFontGrid(2,  5, "SYUTUGEN",    7 * (cursor == 2));
				printFontGrid(2,  6, "SYOUKYO",     7 * (cursor == 3));
				printFontGrid(2,  7, "SETTYAKU",    7 * (cursor == 4));
				printFontGrid(2,  8, "YOKOTAME",    7 * (cursor == 5));
				printFontGrid(2,  9, "SETTYAKU2",   7 * (cursor == 6));
				printFontGrid(2, 10, "SYUTUGEN2",   7 * (cursor == 7));
			} else {
				printFontGrid(2,  5, "ARE",         7 * (cursor == 2));
				printFontGrid(2,  6, "LINE DELAY",  7 * (cursor == 3));
				printFontGrid(2,  7, "LOCK DELAY",  7 * (cursor == 4));
				printFontGrid(2,  8, "DAS",         7 * (cursor == 5));
				printFontGrid(2,  9, "LOCK DELAY2", 7 * (cursor == 6));
				printFontGrid(2, 10, "ARE2",        7 * (cursor == 7));
			}
			
			// �ݒ�l�\��
			sprintf(string[0], "%d", praSpeed);
			printFontGrid(22, 3, string[0], 7 * (cursor == 0));
			
			if(praSpeedType == 0) sprintf(string[0], "1/60");
			else if(praSpeedType == 1) sprintf(string[0], "FRAMES PER ROW");
			else sprintf(string[0], "1/256");
			printFontGrid(22, 4, string[0], 7 * (cursor == 1));
			
			sprintf(string[0], "%d", praWait1);
			printFontGrid(22, 5, string[0], 7 * (cursor == 2));
			
			sprintf(string[0], "%d", praWait2);
			printFontGrid(22, 6, string[0], 7 * (cursor == 3));
			
			sprintf(string[0], "%d", praWait3);
			printFontGrid(22, 7, string[0], 7 * (cursor == 4));
			
			sprintf(string[0], "%d", praWaitt);
			printFontGrid(22, 8, string[0], 7 * (cursor == 5));
			
			if(praWait4 == -1) sprintf(string[0], "NO USE");
			else sprintf(string[0], "%d", praWait4);
			printFontGrid(22, 9, string[0], 7 * (cursor == 6));
			
			if(praWait5 == -1) sprintf(string[0], "NO USE");
			else sprintf(string[0], "%d", praWait5);
			printFontGrid(22, 10, string[0], 7 * (cursor == 7));
		}
		// �y�[�W2 (�V�X�e��)
		else if(cursor < 18) {
			printFontGrid(1, 1, "PRACTICE OPTIONS (PAGE 2/3:SYSTEM)", 4);
			
			// �J�[�\���\��
			printFontGrid(1, 3 + cursor - 8, "b", 7);
			
			// ���j���[�\��
			printFontGrid(2,  3, "LEVEL TYPE",     7 * (cursor ==  8));
			printFontGrid(2,  4, "GOAL",           7 * (cursor ==  9));
			printFontGrid(2,  5, "STAFF ROLL",     7 * (cursor == 10));
			printFontGrid(2,  6, "END SCREEN",     7 * (cursor == 11));
			printFontGrid(2,  7, "LEVEL UP BONUS", 7 * (cursor == 12));
			printFontGrid(2,  8, "COMBO",          7 * (cursor == 13));
			printFontGrid(2,  9, "T-SPIN",         7 * (cursor == 14));
			printFontGrid(2, 10, "BACK TO BACK",   7 * (cursor == 15));
			printFontGrid(2, 11, "GHOST BLOCK",    7 * (cursor == 16));
			printFontGrid(2, 12, "TIME LIMIT",     7 * (cursor == 17));
			
			// �ݒ�l�\��
			if(praLvType == 0) sprintf(string[0], "NORMAL");
			else if(praLvType == 1) sprintf(string[0], "10LINES");
			else if(praLvType == 2) sprintf(string[0], "POINTS");
			printFontGrid(22, 3, string[0], 7 * (cursor == 8));
			
			if(!praGoal) sprintf(string[0], "ENDLESS");
			else if(praLvType == 0) sprintf(string[0], "LV%d", praGoal * 100);
			else if(praLvType == 1) sprintf(string[0], "%d LINES", praGoal * 10);
			else sprintf(string[0], "LV%d", praGoal);
			printFontGrid(22, 4, string[0], 7 * (cursor == 9));
			
			if(praRoll == 0) sprintf(string[0], "OFF");
			else if(praRoll == 1) sprintf(string[0], "NORMAL ROLL");
			else if(praRoll == 2) sprintf(string[0], "FAST ROLL");
			else sprintf(string[0], "NO-DEATH ROLL");
			printFontGrid(22, 5, string[0], 7 * (cursor == 10));
			
			if(praEnd == 0) sprintf(string[0], "EXCELLENT");
			else if(praEnd == 1) sprintf(string[0], "GM");
			else if(praEnd == 2) sprintf(string[0], "GOD");
			else if(praEnd == 3) sprintf(string[0], "CLEAR!!");
			else if(praEnd == 4) sprintf(string[0], "CLEAR");
			else sprintf(string[0], "NONE");
			printFontGrid(22, 6, string[0], 7 * (cursor == 11));
			
			if(!praLvUpBonus) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 7, string[0], 7 * (cursor == 12));
			
			if(!praEnableCombo) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 8, string[0], 7 * (cursor == 13));
			
			if(praTSpin == 0) sprintf(string[0], "OFF");
			else if(praTSpin == 1) sprintf(string[0], "LINE CLEAR");
			else if(praTSpin == 2) sprintf(string[0], "IMMOBILE");
			else if(praTSpin == 3) sprintf(string[0], "3-CORNER");
			else sprintf(string[0], "3-CORNER NO KICK");
			printFontGrid(22, 9, string[0], 7 * (cursor == 14));
			
			if(praEnableB2B == 0) sprintf(string[0], "OFF");
			else if(praEnableB2B == 1) sprintf(string[0], "ON");
			else if(praEnableB2B == 2) sprintf(string[0], "HEBORIS ONLY");
			else sprintf(string[0], "T-SPIN ONLY");
			printFontGrid(22, 10, string[0], 7 * (cursor == 15));
			
			if(praGhost == 0) sprintf(string[0], "LV100");
			else if(praGhost == 1) sprintf(string[0], "ON");
			else sprintf(string[0], "OFF");
			printFontGrid(22, 11, string[0], 7 * (cursor == 16));
			
			if(!praTimeLimit) sprintf(string[0], "NONE");
			else getTime(praTimeLimit);
			printFontGrid(22, 12, string[0], 7 * (cursor == 17));
		}
		// �y�[�W3 (���̑�)
		else {
			printFontGrid(1, 1, "PRACTICE OPTIONS (PAGE 3/3:OTHERS)", 4);
			
			// �J�[�\���\��
			printFontGrid(1, 3 + cursor - 18, "b", 7);
			
			// ���j���[�\��
			printFontGrid(2,  3, "BGM",              7 * (cursor == 18));
			printFontGrid(2,  4, "ENDING BGM",       7 * (cursor == 19));
			printFontGrid(2,  5, "BACKGROUND",       7 * (cursor == 20));
			printFontGrid(2,  6, "FIELD COLOR",      7 * (cursor == 21));
			printFontGrid(2,  7, "FIELD DECORATION", 7 * (cursor == 22));
			printFontGrid(2,  8, "BIG",              7 * (cursor == 23));
			printFontGrid(2,  9, "BIG MOVE",         7 * (cursor == 24));
			printFontGrid(2, 10, "[] BLOCK",         7 * (cursor == 25));
			printFontGrid(2, 11, "[STAGE]",          7 * (cursor == 26));
			printFontGrid(2, 12, "[SAVE PRESET]",    7 * (cursor == 27));
			printFontGrid(2, 13, "[LOAD PRESET]",    7 * (cursor == 28));
			
			// �ݒ�l�\��
			sprintf(string[0], "%d", praBGM);
			printFontGrid(22, 3, string[0], 7 * (cursor == 18));
			
			sprintf(string[0], "%d", praEBGM);
			printFontGrid(22, 4, string[0], 7 * (cursor == 19));
			
			sprintf(string[0], "BACK%02d.PNG", praBack + 1);
			printFontGrid(22, 5, string[0], 7 * (cursor == 20));
			
			sprintf(string[0], "%d", praFieldColor);
			printFontGrid(22, 6, string[0], 7 * (cursor == 21));
			
			if(!praDecoration) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 7, string[0], 7 * (cursor == 22));
			
			if(!praBig) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 8, string[0], 7 * (cursor == 23));
			
			if(!praBMove) sprintf(string[0], "1 BLOCK");
			else sprintf(string[0], "2 BLOCKS");
			printFontGrid(22, 9, string[0], 7 * (cursor == 24));
			
			if(!praOBlk) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 10, string[0], 7 * (cursor == 25));
			
			if(!praStage) sprintf(string[0], "EMPTY");
			else sprintf(string[0], "%d", praStage);
			printFontGrid(22, 11, string[0], 7 * (cursor == 26));
			
			sprintf(string[0], "PRESET NO.%d", praLastPresetNo + 1);
			printFontGrid(22, 12, string[0], 7 * (cursor >= 27));
		}
		
		// �J�[�\���ړ�
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 28;
			if(cursor > 28) cursor = 0;
		}
		
		// �l��ύX
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(getPressState(player, 8)) move = move * 100;	// E�{�^����100�{
			
			if(cursor == 0) {
				praSpeed = praSpeed + move;
				if(praSpeed < 0) praSpeed = 5120;
				if(praSpeed > 5120) praSpeed = 0;
			}
			if(cursor == 1) {
				praSpeedType = praSpeedType + move;
				if(praSpeedType < 0) praSpeedType = 2;
				if(praSpeedType > 2) praSpeedType = 0;
			}
			if(cursor == 2) {
				praWait1 = praWait1 + move;
				if(praWait1 < 0) praWait1 = 99;
				if(praWait1 > 99) praWait1 = 0;
			}
			if(cursor == 3) {
				praWait2 = praWait2 + move;
				if(praWait2 < 0) praWait2 = 99;
				if(praWait2 > 99) praWait2 = 0;
			}
			if(cursor == 4) {
				praWait3 = praWait3 + move;
				if(praWait3 < 0) praWait3 = 99;
				if(praWait3 > 99) praWait3 = 0;
			}
			if(cursor == 5) {
				praWaitt = praWaitt + move;
				if(praWaitt < 0) praWaitt = 99;
				if(praWaitt > 99) praWaitt = 0;
			}
			if(cursor == 6) {
				praWait4 = praWait4 + move;
				if(praWait4 < -1) praWait4 = 99;
				if(praWait4 > 99) praWait4 = -1;
			}
			if(cursor == 7) {
				praWait5 = praWait5 + move;
				if(praWait5 < -1) praWait5 = 99;
				if(praWait5 > 99) praWait5 = -1;
			}
			if(cursor == 8) {
				praLvType = praLvType + move;
				if(praLvType < 0) praLvType = 2;
				if(praLvType > 2) praLvType = 0;
			}
			if(cursor == 9) {
				praGoal = praGoal + move;
				if(praGoal < 0) praGoal = 20;
				if(praGoal > 20) praGoal = 0;
			}
			if(cursor == 10) {
				praRoll = praRoll + move;
				if(praRoll < 0) praRoll = 3;
				if(praRoll > 3) praRoll = 0;
			}
			if(cursor == 11) {
				praEnd = praEnd + move;
				if(praEnd < 0) praEnd = 5;
				if(praEnd > 5) praEnd = 0;
			}
			if(cursor == 12) praLvUpBonus = !praLvUpBonus;
			if(cursor == 13) praEnableCombo = !praEnableCombo;
			if(cursor == 14) {
				praTSpin = praTSpin + move;
				if(praTSpin < 0) praTSpin = 4;
				if(praTSpin > 4) praTSpin = 0;
			}
			if(cursor == 15) {
				praEnableB2B = praEnableB2B + move;
				if(praEnableB2B < 0) praEnableB2B = 3;
				if(praEnableB2B > 3) praEnableB2B = 0;
			}
			if(cursor == 16) {
				praGhost = praGhost + move;
				if(praGhost < 0) praGhost = 2;
				if(praGhost > 2) praGhost = 0;
			}
			if(cursor == 17) {
				praTimeLimit = praTimeLimit + move * 60;
				if(praTimeLimit < 0) praTimeLimit = 72000;
				if(praTimeLimit > 72000) praTimeLimit = 0;
			}
			if(cursor == 18) {
				praBGM = praBGM + move;
				if(praBGM < 0) praBGM = 29;
				if(praBGM > 29) praBGM = 0;
			}
			if(cursor == 19) {
				praEBGM = praEBGM + move;
				if(praEBGM < 0) praEBGM = 29;
				if(praEBGM > 29) praEBGM = 0;
			}
			if(cursor == 20) {
				praBack = praBack + move;
				if(praBack < 0) praBack = 19;
				if(praBack > 19) praBack = 0;
			}
			if(cursor == 21) {
				praFieldColor = praFieldColor + move;
				if(praFieldColor < 0) praFieldColor = 9;
				if(praFieldColor > 9) praFieldColor = 0;
			}
			if(cursor == 22) praDecoration = !praDecoration;
			if(cursor == 23) praBig = !praBig;
			if(cursor == 24) praBMove = !praBMove;
			if(cursor == 25) praOBlk = !praOBlk;
			if(cursor == 26) {
				praStage = praStage + move;
				if(praStage < 0) praStage = 99;
				if(praStage > 99) praStage = 0;
			}
			if((cursor == 27) || (cursor == 28)) {
				praLastPresetNo = praLastPresetNo + move;
				if(praLastPresetNo < 0) praLastPresetNo = 4;
				if(praLastPresetNo > 4) praLastPresetNo = 0;
			}
		}
		
		// �y�[�W�؂�ւ�
		if(getPushState(player, 7)) {
			PlaySE(se_kachi);
			
			if(cursor < 8) cursor = 8;
			else if(cursor < 18) cursor = 18;
			else cursor = 0;
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
			
			if(cursor == 26) {
				if(praStage > 0) praStageEdit(player);
			} else if(cursor == 27) {
				praSavePreset(praLastPresetNo);
				praSaveConfig();
			} else if(cursor == 28) {
				praLoadPreset(praLastPresetNo);
			} else {
				praSaveConfig();
				return;
			}
		}
	}
}

// BGM�Đ�
void praPlayBGM(int player) {
	// BGM�Đ�
	bgmlv = praBGM;
	PlayBGM();
}

// BGM�ǂݍ���
void praLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(praBGM);
		if((praGoal != 0) && (praRoll != 0)) loadBGM(praEBGM);
	}
}

// ���v���C�ۑ�
void praSaveReplay(int player) {
	int i;
	
	saveBuf[900] = praSpeed;
	saveBuf[901] = praWait1;
	saveBuf[902] = praWait2;
	saveBuf[903] = praWait3;
	saveBuf[904] = praWaitt;
	saveBuf[905] = praBig;
	saveBuf[906] = praBMove;
	saveBuf[907] = praOBlk;
	saveBuf[908] = praGoal;
	saveBuf[909] = praRoll;
	saveBuf[910] = praEnd;
	saveBuf[911] = praBGM;
	saveBuf[912] = praEBGM;
	saveBuf[913] = praBack;
	saveBuf[914] = praVersion;
	saveBuf[915] = praLvUpBonus;
	saveBuf[916] = praGhost;
	saveBuf[917] = praFieldColor;
	saveBuf[918] = praDecoration;
	saveBuf[919] = praSpeedType;
	saveBuf[920] = praScore[player];
	saveBuf[921] = praLines[player];
	saveBuf[922] = praLevel[player];
	saveBuf[923] = praStage;
	
	for(i = 0; i < 55; i++) {
		saveBuf[i + 924] = (praInitFld[(i * 4) + 0]);
		saveBuf[i + 924] = saveBuf[i + 924] | (praInitFld[(i * 4) + 1] << 8);
		saveBuf[i + 924] = saveBuf[i + 924] | (praInitFld[(i * 4) + 2] << 16);
		saveBuf[i + 924] = saveBuf[i + 924] | (praInitFld[(i * 4) + 3] << 24);
	}
	
	saveBuf[979] = praLvType;
	saveBuf[980] = praTimeLimit;
	saveBuf[981] = praEnableCombo;
	saveBuf[982] = praTSpin;
	saveBuf[983] = praEnableB2B;
	saveBuf[984] = praWait4;
	saveBuf[985] = praWait5;
}

// ���v���C�ǂݍ���
void praLoadReplay(int player) {
	int i;
	
	praSpeed = saveBuf[900];
	praWait1 = saveBuf[901];
	praWait2 = saveBuf[902];
	praWait3 = saveBuf[903];
	praWaitt = saveBuf[904];
	praBig = saveBuf[905];
	praBMove = saveBuf[906];
	praOBlk = saveBuf[907];
	praGoal = saveBuf[908];
	praRoll = saveBuf[909];
	praEnd = saveBuf[910];
	praBGM = saveBuf[911];
	praEBGM = saveBuf[912];
	praBack = saveBuf[913];
	praVersion = saveBuf[914];
	
	if(praVersion >= 1) {
		praLvUpBonus = saveBuf[915];
		praGhost = saveBuf[916];
		praFieldColor = saveBuf[917];
		praDecoration = saveBuf[918];
	} else {
		praLvUpBonus = 1;
		praGhost = 1;
		praFieldColor = 1;
		praDecoration = 0;
	}
	if(praVersion >= 2) {
		praSpeedType = saveBuf[919];
	} else {
		praSpeedType = 0;
	}
	
	praStage = saveBuf[923];
	
	for(i = 0; i < 55; i++) {
		praInitFld[(i * 4) + 0] = (saveBuf[924 + i] & 0x000000FF);
		praInitFld[(i * 4) + 1] = (saveBuf[924 + i] & 0x0000FF00) >> 8;
		praInitFld[(i * 4) + 2] = (saveBuf[924 + i] & 0x00FF0000) >> 16;
		praInitFld[(i * 4) + 3] = (saveBuf[924 + i] & 0xFF000000) >> 24;
	}
	
	if(praVersion >= 6) {
		praLvType = saveBuf[979];
		praTimeLimit = saveBuf[980];
		praEnableCombo = saveBuf[981];
		praTSpin = saveBuf[982];
		praEnableB2B = saveBuf[983];
	} else {
		praLvType = 0;
		praTimeLimit = 0;
		praEnableCombo = 1;
		praTSpin = 0;
		praEnableB2B = 0;
	}
	
	if(praVersion >= 8) praWait4 = saveBuf[984];
	else praWait4 = -1;
	
	if(praVersion >= 9) praWait5 = saveBuf[985];
	else praWait5 = -1;
	
	praPlayerInitial(player);	// �ݒ�𔽉f������
}

// ���v���C�ڍ�
void praReplayDetail() {
	sprintf(string[0], "< PAGE %d/4 >", praReplayDetailPage + 1);
	printFontGrid(27, 1, string[0], (count % 4 / 2) * 7);
	
	// �y�[�W1
	if(praReplayDetailPage == 0) {
		printFontGrid(1, 4, "GAME PLAY INFO", 6);
		
		if(saveBuf[914] >= 3) {
			printFontGrid(1, 6, "SCORE", 0);
			if(saveBuf[979] == 1) sprintf(string[0], "N/A");
			else sprintf(string[0], "%d", saveBuf[920]);
			printFontGrid(22, 6, string[0], 0);
			
			printFontGrid(1, 7, "LINES", 0);
			sprintf(string[0], "%d", saveBuf[921]);
			printFontGrid(22, 7, string[0], 0);
			
			printFontGrid(1, 8, "LEVEL", 0);
			if(saveBuf[979] == 0) sprintf(string[0], "%d", saveBuf[922]);
			else sprintf(string[0], "%d", saveBuf[922] + 1);
			printFontGrid(22, 8, string[0], 0);
		}
		
		printFontGrid(1, 10, "VERSION", 0);
		sprintf(string[0], "%d", saveBuf[914]);
		printFontGrid(22, 10, string[0], 0);
	}
	// �y�[�W2
	else if(praReplayDetailPage == 1) {
		printFontGrid(1, 4, "GAME SPEED", 6);
		
		printFontGrid(1, 6, "SPEED", 0);
		sprintf(string[0], "%d", saveBuf[900]);
		printFontGrid(22, 6, string[0], 0);
		
		printFontGrid(1, 7, "SPEED TYPE", 0);
		if(saveBuf[919] == 0) sprintf(string[0], "1/60");
		else if(saveBuf[919] == 1) sprintf(string[0], "FRAMES PER ROW");
		else sprintf(string[0], "1/256");
		printFontGrid(22, 7, string[0], 0);
		
		if(!english) printFontGrid(1, 8, "SYUTUGEN", 0);
		else printFontGrid(1, 8, "ARE", 0);
		sprintf(string[0], "%d", saveBuf[901]);
		printFontGrid(22, 8, string[0], 0);
		
		if(!english) printFontGrid(1, 9, "SYOUKYO", 0);
		else printFontGrid(1, 9, "LINE DELAY", 0);
		sprintf(string[0], "%d", saveBuf[902]);
		printFontGrid(22, 9, string[0], 0);
		
		if(!english) printFontGrid(1, 10, "SETTYAKU", 0);
		else printFontGrid(1, 10, "LOCK DELAY", 0);
		sprintf(string[0], "%d", saveBuf[903]);
		printFontGrid(22, 10, string[0], 0);
		
		if(!english) printFontGrid(1, 11, "YOKOTAME", 0);
		else printFontGrid(1, 11, "DAS", 0);
		sprintf(string[0], "%d", saveBuf[904]);
		printFontGrid(22, 11, string[0], 0);
		
		if(!english) printFontGrid(1, 12, "SETTYAKU2", 0);
		else printFontGrid(1, 12, "LOCK DELAY2", 0);
		if((saveBuf[984] == -1) || (saveBuf[914] <= 7)) {
			sprintf(string[0], "NO USE");
		} else {
			sprintf(string[0], "%d", saveBuf[984]);
		}
		printFontGrid(22, 12, string[0], 0);
		
		if(!english) printFontGrid(1, 13, "SYUTUGEN2", 0);
		else printFontGrid(1, 13, "ARE2", 0);
		if((saveBuf[985] == -1) || (saveBuf[914] <= 8)) {
			sprintf(string[0], "NO USE");
		} else {
			sprintf(string[0], "%d", saveBuf[985]);
		}
		printFontGrid(22, 13, string[0], 0);
	}
	// �y�[�W3
	else if(praReplayDetailPage == 2) {
		printFontGrid(1, 4, "SYSTEM", 6);
		
		printFontGrid(1, 6, "LEVEL TYPE", 0);
		if(saveBuf[979] == 0) sprintf(string[0], "NORMAL");
		else if(saveBuf[979] == 1) sprintf(string[0], "10LINES");
		else sprintf(string[0], "POINTS");
		printFontGrid(22, 6, string[0], 0);
		
		printFontGrid(1, 7, "GOAL", 0);
		if(!saveBuf[908]) sprintf(string[0], "ENDLESS");
		else if(saveBuf[979] == 0) sprintf(string[0], "LV%d", saveBuf[908] * 100);
		else if(saveBuf[979] == 1) sprintf(string[0], "%d LINES", saveBuf[908] * 10);
		else sprintf(string[0], "LV%d", saveBuf[908]);
		printFontGrid(22, 7, string[0], 0);
		
		printFontGrid(1, 8, "STAFF ROLL", 0);
		if(saveBuf[909] == 0) sprintf(string[0], "OFF");
		else if(saveBuf[909] == 1) sprintf(string[0], "NORMAL ROLL");
		else if(saveBuf[909] == 2) sprintf(string[0], "FAST ROLL");
		else sprintf(string[0], "NO-DEATH ROLL");
		printFontGrid(22, 8, string[0], 0);
		
		printFontGrid(1, 9, "END SCREEN", 0);
		if(saveBuf[910] == 0) sprintf(string[0], "EXCELLENT");
		else if(saveBuf[910] == 1) sprintf(string[0], "GM");
		else if(saveBuf[910] == 2) sprintf(string[0], "GOD");
		else if(saveBuf[910] == 3) sprintf(string[0], "CLEAR!!");
		else if(saveBuf[910] == 4) sprintf(string[0], "CLEAR");
		else sprintf(string[0], "NONE");
		printFontGrid(22, 9, string[0], 0);
		
		printFontGrid(1, 10, "LEVEL UP BONUS", 0);
		if(!saveBuf[915]) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 10, string[0], 0);
		
		printFontGrid(1, 11, "COMBO", 0);
		if(!saveBuf[981]) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 11, string[0], 0);
		
		printFontGrid(1, 12, "T-SPIN", 0);
		if(saveBuf[982] == 0) sprintf(string[0], "OFF");
		else if(saveBuf[982] == 1) sprintf(string[0], "LINE CLEAR");
		else if(saveBuf[982] == 2) sprintf(string[0], "IMMOBILE");
		else if(saveBuf[982] == 3) sprintf(string[0], "3-CORNER");
		else sprintf(string[0], "3-CORNER NO KICK");
		printFontGrid(22, 12, string[0], 0);
		
		printFontGrid(1, 13, "BACK TO BACK", 0);
		if(saveBuf[983] == 0) sprintf(string[0], "OFF");
		else if(saveBuf[983] == 1) sprintf(string[0], "ON");
		else if(saveBuf[983] == 2) sprintf(string[0], "HEBORIS ONLY");
		else sprintf(string[0], "T-SPIN ONLY");
		printFontGrid(22, 13, string[0], 0);
		
		printFontGrid(1, 14, "GHOST BLOCK", 0);
		if(saveBuf[916] == 0) sprintf(string[0], "LV100");
		else if(saveBuf[916] == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 14, string[0], 0);
		
		printFontGrid(1, 15, "TIME LIMIT", 0);
		if(!saveBuf[980]) sprintf(string[0], "NONE");
		else getTime(saveBuf[980]);
		printFontGrid(22, 15, string[0], 0);
	}
	// �y�[�W4
	else if(praReplayDetailPage == 3) {
		printFontGrid(1, 4, "OTHERS", 6);
		
		printFontGrid(1, 6, "BGM", 0);
		sprintf(string[0], "%d", saveBuf[911]);
		printFontGrid(22, 6, string[0], 0);
		
		printFontGrid(1, 7, "ENDING BGM", 0);
		sprintf(string[0], "%d", saveBuf[912]);
		printFontGrid(22, 7, string[0], 0);
		
		printFontGrid(1, 8, "BACKGROUND", 0);
		sprintf(string[0], "BACK%02d.PNG", saveBuf[913] + 1);
		printFontGrid(22, 8, string[0], 0);
		
		printFontGrid(1, 9, "FIELD COLOR", 0);
		sprintf(string[0], "%d", saveBuf[917]);
		printFontGrid(22, 9, string[0], 0);
		
		printFontGrid(1, 10, "FIELD DECORATION", 0);
		if(!saveBuf[918]) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 10, string[0], 0);
		
		printFontGrid(1, 11, "BIG", 0);
		if(!saveBuf[905]) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 11, string[0], 0);
		
		printFontGrid(1, 12, "BIG MOVE", 0);
		if(!saveBuf[906]) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 12, string[0], 0);
		
		printFontGrid(1, 13, "[] BLOCK", 0);
		if(!saveBuf[907]) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 13, string[0], 0);
		
		printFontGrid(1, 14, "STAGE", 0);
		if(saveBuf[923] == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 14, string[0], 0);
	}
	
	// �y�[�W�؂�ւ�
	if(getPushState(0, 2)) {
		PlaySE(se_kachi);
		praReplayDetailPage--;
		if(praReplayDetailPage < 0) praReplayDetailPage = 3;
	}
	if(getPushState(0, 3)) {
		PlaySE(se_kachi);
		praReplayDetailPage++;
		if(praReplayDetailPage > 3) praReplayDetailPage = 0;
	}
}

// �ݒ��ۑ�
void praSaveConfig() {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x43415250;
	saveBuf[1] = 0x45434954;
	saveBuf[2] = 0x464E4F43;
	saveBuf[3] = 0x32764749;
	
	// �ݒ���e
	saveBuf[4] = praSpeed;
	saveBuf[5] = praWait1;
	saveBuf[6] = praWait2;
	saveBuf[7] = praWait3;
	saveBuf[8] = praWaitt;
	saveBuf[9] = praBig;
	saveBuf[10] = praBMove;
	saveBuf[11] = praOBlk;
	saveBuf[12] = praGoal;
	saveBuf[13] = praRoll;
	saveBuf[14] = praEnd;
	saveBuf[15] = praBGM;
	saveBuf[16] = praEBGM;
	saveBuf[17] = praBack;
	saveBuf[18] = praLvUpBonus;
	saveBuf[19] = praGhost;
	saveBuf[20] = praFieldColor;
	saveBuf[21] = praDecoration;
	saveBuf[22] = praSpeedType;
	saveBuf[23] = praStage;
	saveBuf[24] = praLvType;
	saveBuf[25] = praTimeLimit;
	saveBuf[26] = praEnableCombo;
	saveBuf[27] = praTSpin;
	saveBuf[28] = praEnableB2B;
	saveBuf[29] = praWait4;
	saveBuf[30] = praWait5;
	
	saveBuf[49] = praLastPresetNo;
	for(i = 0; i < 30 * 5; i++) saveBuf[50 + i] = praPreset[i];
	
	SaveFile("config/PRACITCE_CONFIG.SAV", &saveBuf, 200 * 4);
}

// �ݒ��ǂݍ���
int praLoadConfig() {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/PRACITCE_CONFIG.SAV", &saveBuf, 200 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x43415250) return 0;
	if(saveBuf[1] != 0x45434954) return 0;
	if(saveBuf[2] != 0x464E4F43) return 0;
	if(saveBuf[3] != 0x32764749) return 0;
	
	// �ݒ���e
	praSpeed = saveBuf[4];
	praWait1 = saveBuf[5];
	praWait2 = saveBuf[6];
	praWait3 = saveBuf[7];
	praWaitt = saveBuf[8];
	praBig = saveBuf[9];
	praBMove = saveBuf[10];
	praOBlk = saveBuf[11];
	praGoal = saveBuf[12];
	praRoll = saveBuf[13];
	praEnd = saveBuf[14];
	praBGM = saveBuf[15];
	praEBGM = saveBuf[16];
	praBack = saveBuf[17];
	praLvUpBonus = saveBuf[18];
	praGhost = saveBuf[19];
	praFieldColor = saveBuf[20];
	praDecoration = saveBuf[21];
	praSpeedType = saveBuf[22];
	praStage = saveBuf[23];
	praLvType = saveBuf[24];
	praTimeLimit = saveBuf[25];
	praEnableCombo = saveBuf[26];
	praTSpin = saveBuf[27];
	praEnableB2B = saveBuf[28];
	praWait4 = saveBuf[29];
	praWait5 = saveBuf[30];
	
	praLastPresetNo = saveBuf[49];
	for(i = 0; i < 30 * 5; i++) praPreset[i] = saveBuf[50 + i];
	
	return 1;
}

// �v���Z�b�g������
void praMakeDefaultPreset() {
	int i;
	
	for(i = 0; i < 30 * 5; i++) praPreset[i] = 0;
}

// �v���Z�b�g��ۑ�
void praSavePreset(int number) {
	praPreset[number * 30 + 0] = praSpeed;
	praPreset[number * 30 + 1] = praWait1;
	praPreset[number * 30 + 2] = praWait2;
	praPreset[number * 30 + 3] = praWait3;
	praPreset[number * 30 + 4] = praWaitt;
	praPreset[number * 30 + 5] = praBig;
	praPreset[number * 30 + 6] = praBMove;
	praPreset[number * 30 + 7] = praOBlk;
	praPreset[number * 30 + 8] = praGoal;
	praPreset[number * 30 + 9] = praRoll;
	praPreset[number * 30 + 10] = praEnd;
	praPreset[number * 30 + 11] = praBGM;
	praPreset[number * 30 + 12] = praEBGM;
	praPreset[number * 30 + 13] = praBack;
	praPreset[number * 30 + 14] = praLvUpBonus;
	praPreset[number * 30 + 15] = praGhost;
	praPreset[number * 30 + 16] = praFieldColor;
	praPreset[number * 30 + 17] = praDecoration;
	praPreset[number * 30 + 18] = praSpeedType;
	praPreset[number * 30 + 19] = praStage;
	praPreset[number * 30 + 20] = praLvType;
	praPreset[number * 30 + 21] = praTimeLimit;
	praPreset[number * 30 + 22] = praEnableCombo;
	praPreset[number * 30 + 23] = praTSpin;
	praPreset[number * 30 + 24] = praEnableB2B;
	praPreset[number * 30 + 25] = praWait4;
	praPreset[number * 30 + 26] = praWait5;
}

// �v���Z�b�g��ǂݍ���
void praLoadPreset(int number) {
	praSpeed = praPreset[number * 30 + 0];
	praWait1 = praPreset[number * 30 + 1];
	praWait2 = praPreset[number * 30 + 2];
	praWait3 = praPreset[number * 30 + 3];
	praWaitt = praPreset[number * 30 + 4];
	praBig = praPreset[number * 30 + 5];
	praBMove = praPreset[number * 30 + 6];
	praOBlk = praPreset[number * 30 + 7];
	praGoal = praPreset[number * 30 + 8];
	praRoll = praPreset[number * 30 + 9];
	praEnd = praPreset[number * 30 + 10];
	praBGM = praPreset[number * 30 + 11];
	praEBGM = praPreset[number * 30 + 12];
	praBack = praPreset[number * 30 + 13];
	praLvUpBonus = praPreset[number * 30 + 14];
	praGhost = praPreset[number * 30 + 15];
	praFieldColor = praPreset[number * 30 + 16];
	praDecoration = praPreset[number * 30 + 17];
	praSpeedType = praPreset[number * 30 + 18];
	praStage = praPreset[number * 30 + 19];
	praLvType = praPreset[number * 30 + 20];
	praTimeLimit = praPreset[number * 30 + 21];
	praEnableCombo = praPreset[number * 30 + 22];
	praTSpin = praPreset[number * 30 + 23];
	praEnableB2B = praPreset[number * 30 + 24];
	praWait4 = praPreset[number * 30 + 25];
	praWait5 = praPreset[number * 30 + 26];
}

// �X�e�[�W�G�f�B�b�g
void praStageEdit(int player) {
	int i, j, fi, temp, dx, dy;
	int cursor, move, edit, cx, cy, color, noset;
	
	cursor = 0;		// ���j���[�̃J�[�\���ʒu
	edit = 0;		// 0=���j���[ 1=�t�B�[���h
	cx = 0;			// �t�B�[���h�G�f�B�b�g��X���W
	cy = 0;			// �t�B�[���h�G�f�B�b�g��Y���W
	color = 0;		// �t�B�[���h�G�f�B�b�g�̃u���b�N�̐F
	noset = 0;		// ��ʂ�؂�ւ����u�Ԃ����Ȃ�u���b�N��u���̂�h��
	
	praLoadStage(player, praStage);
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		padRepeat(player);
		padRepeat2(player);
		
		sprintf(string[0], "STAGE EDIT %d", praStage);
		printFontGrid(1, 1, string[0], 4);
		
		// �t�B�[���h��`��
		ExBltFast(sg_black, 16, 40);
		ExBltRect(sg_fld, 8, 32, praFieldColor * 96, 0, 96, 8 + 176);
		for(i = 0; i < 22; i++) {
			for(j = 0; j < 10; j++) {
				fi = getFieldBlock(player, j, i);
				
				if(fi > 0) {
					// �u���b�N
					dx = (j * 8) + 16;
					dy = (i + 3) * 8;
					drawSBlock(player, dx, dy, fi - 1, 5, 0, 0, 0);
					
					// �g��
					temp = getFieldBlock(player, j, i - 1);
					if((temp == 0) || (temp == -2)) ExBltFastRect(sg_blkline, dx    , dy    ,  8,  0, 8, 1);
					temp = getFieldBlock(player, j, i + 1);
					if((temp == 0) || (temp == -2)) ExBltFastRect(sg_blkline, dx    , dy + 7,  8, 15, 8, 1);
					temp = getFieldBlock(player, j - 1, i);
					if((temp == 0) || (temp == -2)) ExBltFastRect(sg_blkline, dx    , dy    ,  8, 16, 1, 8);
					temp = getFieldBlock(player, j + 1, i);
					if((temp == 0) || (temp == -2)) ExBltFastRect(sg_blkline, dx + 7, dy    , 15, 24, 1, 8);
				}
			}
		}
		
		// ���j���[��`��
		printFontGrid(15,  5, "[FIELD]", (cursor == 0) * 2);
		printFontGrid(15,  6, "[LOAD]",  (cursor == 1) * 2);
		printFontGrid(15,  7, "[SAVE]",  (cursor == 2) * 2);
		
		// �J�[�\���\��
		if(!edit) {
			printFontGrid(14, 5 + cursor, "b", 2);
			
			printFontGrid(1, 27, "A:OK B:EXIT", 6);
		} else {
			drawSBlock(player, (cx * 8) + 16, (cy + 3) * 8, color, 0, 0, 0, 0);
			ExBltFastRect(sg_blkline, (cx * 8) + 16    , (cy + 3) * 8    , 16,  0, 8, 1);
			ExBltFastRect(sg_blkline, (cx * 8) + 16    , (cy + 3) * 8 + 7, 16, 15, 8, 1);
			ExBltFastRect(sg_blkline, (cx * 8) + 16    , (cy + 3) * 8    , 16, 16, 1, 8);
			ExBltFastRect(sg_blkline, (cx * 8) + 16 + 7, (cy + 3) * 8    , 23, 24, 1, 8);
			
			sprintf(string[0], "X:%02d Y:%02d", cx, cy);
			printFontGrid(1, 2, string[0], 1);
			
			printFontGrid(1, 27, "A:PUT B:END C+L/C+R:SELECT-BLOCK", 6);
			printFontGrid(1, 28, "D:REMOVE", 6);
		}
		
		if(!edit) {
			// �J�[�\���ړ�
			move = 0;
			if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
				move = getPressState(player, 1) - getPressState(player, 0);
			
			if(move) {
				PlaySE(se_move);
				cursor = cursor + move;
				if(cursor < 0) cursor = 2;
				if(cursor > 2) cursor = 0;
			}
			
			// ����
			if(getPushState(player, 4)) {
				if(cursor == 0) {
					PlayWave(se_kettei);
					edit = 1;
					noset = 1;
				}
				if(cursor == 1) {
					PlayWave(se_kettei);
					praLoadStage(player, praStage);
				}
				if(cursor == 2) {
					PlayWave(se_kettei);
					praSaveStage(player, praStage);
				}
			}
			
			// �L�����Z��
			if(getPushState(player, 5)) {
				PlaySE(se_move);
				return;
			}
		} else {
			// �J�[�\���ړ��i�㉺�j
			move = 0;
			if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
				move = getPressState(player, 1) - getPressState(player, 0);
			
			if(move) {
				PlaySE(se_move);
				cy = cy + move;
				if(cy < 0) cy = 21;
				if(cy > 21) cy = 0;
			}
			
			// �J�[�\���ړ��i���E�j�^�u���b�N�I��
			move = 0;
			if( (mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) )
				move = getPressState(player, 3) - getPressState(player, 2);
			
			if(move) {
				PlaySE(se_move);
				
				if(getPressState(player, 6)) {
					color = color + move;
					if(color < 0) color = 16;
					if(color > 16) color = 0;
				} else {
					cx = cx + move;
					if(cx < 0) cx = 9;
					if(cx > 9) cx = 0;
				}
			}
			
			// A�Ńu���b�N�z�u
			if(getPressState(player, 4) && !noset) {
				if(getFieldBlock(player, cx, cy) != color + 1) {
					PlaySE(se_kachi);
					setFieldBlock(player, cx, cy, color + 1);
				}
			}
			if(!getPressState(player, 4)) {
				noset = 0;
			}
			
			// D�Ńu���b�N����
			if(getPressState(player, 7)) {
				if(getFieldBlock(player, cx, cy) != 0) {
					PlaySE(se_kachi);
					setFieldBlock(player, cx, cy, 0);
				}
			}
			
			// �L�����Z��
			if(getPushState(player, 5)) {
				PlaySE(se_move);
				edit = 0;
			}
		}
	}
}

// �X�e�[�W��ۑ�
//   0�`  4 �w�b�_
//   5�` 59 �n�`�f�[�^
void praSaveStage(int player, int number) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x43415250;
	saveBuf[1] = 0x45434954;
	saveBuf[2] = 0x4154532D;
	saveBuf[3] = 0x31764547;
	
	// �n�`�f�[�^
	for(i = 0; i < 55; i++) {
		saveBuf[i + 4] = (fld[(i * 4) + 0 + player * 220]);
		saveBuf[i + 4] = saveBuf[i + 4] | (fld[(i * 4) + 1 + player * 220] << 8);
		saveBuf[i + 4] = saveBuf[i + 4] | (fld[(i * 4) + 2 + player * 220] << 16);
		saveBuf[i + 4] = saveBuf[i + 4] | (fld[(i * 4) + 3 + player * 220] << 24);
	}
	
	sprintf(string[0], "stage/practice/field%02d.sav", number);
	SaveFile(string[0], &saveBuf, 60 * 4);
}

// �X�e�[�W��ǂݍ���
int praLoadStage(int player, int number) {
	int i;
	
	// �ǂݍ��ݎ��s���Ă����v�Ȃ悤�Ƀ_�~�[�Ńf�t�H���g�l��ݒ�
	resetField(player);
	
	// �ǂݍ��݊J�n
	FillMemory(&saveBuf, 150000 * 4, 0);
	sprintf(string[0], "stage/practice/field%02d.sav", number);
	LoadFile(string[0], &saveBuf, 60 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x43415250) return 0;
	if(saveBuf[1] != 0x45434954) return 0;
	if(saveBuf[2] != 0x4154532D) return 0;
	if(saveBuf[3] != 0x31764547) return 0;
	
	// �n�`�f�[�^
	for(i = 0; i < 55; i++) {
		fld[(i * 4) + 0 + player * 220] = (saveBuf[4 + i] & 0x000000FF);
		fld[(i * 4) + 1 + player * 220] = (saveBuf[4 + i] & 0x0000FF00) >> 8;
		fld[(i * 4) + 2 + player * 220] = (saveBuf[4 + i] & 0x00FF0000) >> 16;
		fld[(i * 4) + 3 + player * 220] = (saveBuf[4 + i] & 0xFF000000) >> 24;
	}
	disableShadowTimer(player);
	
	return 1;
}
