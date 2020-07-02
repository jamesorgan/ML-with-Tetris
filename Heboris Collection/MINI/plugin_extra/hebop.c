//HEBO+
//prefix:hebop

// �o�[�W����
int hebopVersion;		// �o�[�W�����ԍ��i�Â����v���C�Đ��p�j
int hebopCVersion = 2;	// ���݂̃o�[�W����

// ���x���A�b�v�e�[�u��(420�ł̌����ǉ���)
// ���x
int hebopLevelTable[30] =
{
	4, 6, 8, 10, 12, 16, 32, 48, 64, 80, 96, 112, 128, 144, 4, 32, 64, 96, 128, 160,
	192, 224, 256, 512, 768, 1024, 1280, 1024, 768, 5120
};

// ���x��
int hebopLevelChange[30] = 
{
	30, 35, 40, 50, 60, 70, 80, 90, 100, 120, 140, 160, 170, 200, 220, 230, 233, 236, 239, 243,
	247, 251, 300, 330, 360, 400, 420, 450, 500, 10000
};

// ���x���A�b�v�e�[�u��(420�ł̌����ǉ��O)
// ���x
int hebopLevelTableOld[29] =
{
	4, 6, 8, 10, 12, 16, 32, 48, 64, 80, 96, 112, 128, 144, 4, 32, 64, 96, 128, 160,
	192, 224, 256, 512, 768, 1024, 1280, 768, 5120
};

// ���x��
int hebopLevelChangeOld[29] = 
{
	30, 35, 40, 50, 60, 70, 80, 90, 100, 120, 140, 160, 170, 200, 220, 230, 233, 236, 239, 243,
	247, 251, 300, 330, 360, 400, 450, 500, 10000
};

// ����オ��p�^�[��
int hebopGarbagePattern[10 * 24] = 
{
	0,1,1,1,1,1,1,1,1,1,
	0,1,1,1,1,1,1,1,1,1,
	0,1,1,1,1,1,1,1,1,1,
	0,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,0,
	1,1,1,1,1,1,1,1,1,0,
	1,1,1,1,1,1,1,1,1,0,
	1,1,1,1,1,1,1,1,1,0,
	0,0,1,1,1,1,1,1,1,1,
	0,1,1,1,1,1,1,1,1,1,
	0,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,0,0,
	1,1,1,1,1,1,1,1,1,0,
	1,1,1,1,1,1,1,1,1,0,
	1,1,0,1,1,1,1,1,1,1,
	1,0,0,1,1,1,1,1,1,1,
	1,0,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,0,1,1,
	1,1,1,1,1,1,1,0,0,1,
	1,1,1,1,1,1,1,1,0,1,
	1,1,1,1,0,0,1,1,1,1,
	1,1,1,1,0,0,1,1,1,1,
	1,1,1,1,0,1,1,1,1,1,
	1,1,1,0,0,0,1,1,1,1,
};

// ���i�ʂ̕\����
str hebopStrSecretGradeName[19] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0�` 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9�`17
	"GM"													// 18
};

// BGM�ݒ�
int hebopBgmNo[4]     = {0,1,2,3};				// BGM�ԍ��i000-499�A500-699�A700-899�A900-999�j
int hebopFadeLv[4]    = {495,695,880,10000};	// BGM���t�F�[�h�A�E�g�����郌�x��
int hebopBgmChange[4] = {500,700,900,10000};	// BGM��؂�ւ��郌�x��
int hebopBgmIndex     = 0;						// ���݂�BGM�ԍ�

// �ϐ�
int hebopModeNo = -1;		// ���[�h�ԍ�
int hebopLevel[2];			// ���x��
int hebopScore[2];			// �X�R�A
int hebopLevelIndex[2];		// ���݂̑��x�ԍ�
int hebopGarbagePos[2];		// ���݂̂���オ��p�^�[���̈ʒu�i0�`23�j
int hebopGarbageCount[2];	// ����オ��p�J�E���^�i���C���������Ȃ���+1�j

int hebopGhost = 0;			// �S�[�X�g�̐ݒ�i0=LV0-99 1=���ON 2=���OFF�j
int hebopLvUpBonus = 0;		// ���x���A�b�v�{�[�i�X
int hebop20G = 0;			// 20G���[�h
int hebopStartLevel = 0;	// �X�^�[�g���̃��x��

// �����L���O�p�ϐ�
int hebopRankingTime[20];	// �^�C��
int hebopRankingLevel[20];	// ���x��
int hebopRankingYear[20];	// �����N�C�������i�N�j
int hebopRankingMonth[20];	// �����N�C�������i���j
int hebopRankingDay[20];	// �����N�C�������i���j
int hebopRankingHour[20];	// �����N�C�������i���j
int hebopRankingMinute[20];	// �����N�C�������i���j
int hebopRankingSecond[20];	// �����N�C�������i�b�j

// �C�x���g����
void hebopPluginEvent(int player, int event, int *param) {
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != hebopModeNo)) return;
	
	if(event == 0) {
		hebopModeNo = addModePlugin("HEBO+");	// ���[�h��o�^����
	} else if(event == 7) {
		if(!ending[player]) hebopMoveInit(player);	// �u���b�N�o��
	} else if(event == 12) {
		if(!ending[player]) hebopCalcScore(player, param[0]);	// �X�R�A�v�Z
	} else if(event == 15) {
		hebopViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		hebopSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		hebopPlayerInitial(player);	// ����������
	} else if(event == 21) {
		hebopResult(player);	// ���ʕ\��
	} else if(event == 25) {
		hebopExcellent(player, param);	// �G���f�B���O�I��
	} else if(event == 28) {
		hebopIncrementTime(player);	// ���Ԃ�i�߂�
	} else if(event == 36) {
		hebopStaffRoll(player);	// �X�^�b�t���[���`��
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		hebopSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		hebopLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		hebopLoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		hebopReplayDetail();	// ���v���C�ڍ�
	} else if(event == 60) {
		hebopMoveLock(player);	// ���C�������Ȃ��Ńu���b�N��u�����Ƃ�
	}
}

// ����������
void hebopPlayerInitial(int player) {
	// �o�[�W����
	if(!playback) hebopVersion = hebopCVersion;
	
	// �R���{�L��
	enable_combo[player] = 1;
	
	// �g�̐F��ς���
	framecolor[player] = 6;
	
	// �ϐ���������
	if((hebopStartLevel > 0) && (hebopVersion >= 1)) hebopLevel[player] = hebopStartLevel;
	else hebopLevel[player] = -1;
	backno = hebopLevel[player] / 100;
	
	hebopScore[player] = 0;
	hebopLevelIndex[player] = 0;
	hebopGarbagePos[player] = 0;
	hebopGarbageCount[player] = 0;
	hebopBgmIndex = 0;
	bgmlv = hebopBgmNo[0];
	if(hebopGhost == 2) ghost[player] = 0;
	
	// �������x��ݒ�
	hebopSpeedUp(player);
}

// �X�s�[�h�A�b�v
void hebopSpeedUp(int player) {
	int temp;
	
	// �X�s�[�h��ς���
	speedtype[player] = 2;
	
	if(hebop20G) {
		sp[player] = 5120;
	} else {
		if(hebopVersion >= 2) {
			while(hebopLevel[player] >= hebopLevelChange[hebopLevelIndex[player]]) {
				hebopLevelIndex[player]++;
			}
		} else if(hebopVersion == 1) {
			while(hebopLevel[player] >= hebopLevelChangeOld[hebopLevelIndex[player]]) {
				hebopLevelIndex[player]++;
			}
		} else {
			if(hebopLevel[player] >= hebopLevelChangeOld[hebopLevelIndex[player]]) hebopLevelIndex[player]++;
		}
		
		if(hebopVersion >= 2) {
			sp[player] = hebopLevelTable[hebopLevelIndex[player]];
		} else {
			sp[player] = hebopLevelTableOld[hebopLevelIndex[player]];
		}
	}
	
	// �S�[�X�g������
	if((hebopLevel[player] >= 100) && (hebopGhost == 0)) {
		ghost[player] = 0;
	}
	
	// BGM�t�F�[�h�A�E�g
	if((hebopLevel[player] >= hebopFadeLv[hebopBgmIndex]) && (hebopLevel[player] < hebopBgmChange[hebopBgmIndex]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// BGM�؂�ւ�
	temp = 0;
	while(hebopLevel[player] >= hebopBgmChange[hebopBgmIndex]) {
		hebopBgmIndex++;
		bgmlv = hebopBgmNo[hebopBgmIndex];
		if(onRecord[player]) temp = 1;
	}
	if(temp) PlayBGM();
}

// �u���b�N�o��
void hebopMoveInit(int player) {
	int temp;
	
	// �ŏ��̃t���[���Ȃ�
	if(statc[player * 10 + 3] == 0) {
		// ���x���A�b�v����
		if(hebopLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		
		if(hebopLevel[player] % 100 != temp) {
			hebopLevel[player]++;
			if(hebopLevel[player] % 100 == temp) PlaySE(se_lvstop);
			hebopSpeedUp(player);
		}
	}
}

// �X�R�A�v�Z
void hebopCalcScore(int player, int lines) {
	int temp, temp2, bo, bai, nextsec;
	
	if(!hebopLvUpBonus) temp = hebopLevel[player] + lines;
	else temp = hebopLevel[player] + lines + ((lines >= 3) * (lines - 2));
	if(temp > 999) temp = 999;
	
	temp2 = wait3[player] - bactivetime[player];
	if(temp2 < 0) temp2 = 0;
	
	bo = ((hebopLevel[player] + lines) / 4 + sdrop[player] + qdrop[player] + qput[player]) * lines * cmbpts[player] + (temp / 2) + (temp2 * 7);
	bai = 1;
	
	if(isBravo(player)) {
		// �S��������ƃX�R�A4�{
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		bai = bai * 4;
	}
	
	// �X�R�A���Z
	hebopScore[player] = hebopScore[player] + bo * bai;
	
	// ���x���A�b�v
	nextsec = hebopLevel[player] / 100 * 100 + 100;
	if(!hebopLvUpBonus) hebopLevel[player] = hebopLevel[player] + lines;
	else hebopLevel[player] = hebopLevel[player] + lines + ((lines >= 3) * (lines - 2));
	
	if(hebopLevel[player] >= 999) {
		// �G���f�B���O
		PlaySE(se_ttclear);
		hebopLevel[player] = 999;
		timeOn[player] = 0;
		ending[player] = 2;
		ending_timeOn[player] = 1;
		fastroll[player] = 1;
	} else {
		// ���x���X�g�b�v��
		if(hebopLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		if(hebopLevel[player] % 100 == temp) PlaySE(se_lvstop);
		
		if(hebopLevel[player] >= nextsec) {
			// ���x���A�b�v��
			PlaySE(se_levelup);
			
			// �w�i�؂�ւ�
			bgfadesw = 1;
			bgfadebg = nextsec / 100;
		}
		
		// �X�s�[�h�A�b�v
		hebopSpeedUp(player);
	}
}

// ���Ԃ�i�߂�
void hebopIncrementTime(int player) {
	int i;
	
	// F�{�^���ō������[��������
	if((ending_timeOn[player]) && (onRecord[player]) && (fastroll[player] == 1) && (getPressState(player, 9)))
		edrec[player] = edrec[player] + 2;
	
	// ���[���I��
	if((ending[player] == 2) && (edrec[player] >= 60 * 60)) {
		ending[player] = 3;
		stat[player] = 10;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
}

// �X�^�b�t���[���`��
void hebopStaffRoll(int player) {
	// F�{�^���ō������[��������
	if((ending_timeOn[player]) && (onRecord[player]) && (fastroll[player] == 1) && (getPressState(player, 9))) {
		endtime[player] = endtime[player] + 2;
		if(endtime[player] < 3100) staff_c[player]++;
	}
}

// ���C�������Ȃ��Ńu���b�N��u�����Ƃ�
void hebopMoveLock(int player) {
	int i;
	
	hebopGarbageCount[player]++;
	
	if(hebopGarbageCount[player] >= 13 - (hebopLevel[player] / 100)) {
		// ����オ��
		for(i = 0; i < 10; i++) fldu[i + player * 220] = hebopGarbagePattern[i + hebopGarbagePos[player] * 10];
		hebopGarbagePos[player]++;
		if(hebopGarbagePos[player] > 23) hebopGarbagePos[player] = 0;
		upLines[player]++;
		hebopGarbageCount[player] = 0;
	}
}

// BGM�ǂݍ���
void hebopLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 4; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/4)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(hebopBgmNo[i]);
		}
	}
}

// �X�R�A�\��
void hebopViewScore(int player) {
	int color, temp;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// �X�R�A
	printTinyFont(foffset[player] + 96, fyoffset[player] + 135, "SCORE");
	sprintf(string[0], "%d", hebopScore[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 143, string[0], color);
	
	// ���x���i���q�j
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(hebopLevel[player] == -1) sprintf(string[0], "%4d", 0);	// -1�Ȃ�0�ƕ\������(�����I�ɂ͍ŏ���-1�ɂȂ��Ă���)
	else sprintf(string[0], "%4d", hebopLevel[player]);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// ���x���i�����j
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	temp = sp[player] / 128;
	if(temp > 22) temp = 22;
	ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22 - temp, 143, 22, 1);
	
	// ���x���i����j
	if(ending[player]) sprintf(string[0], "%4d", hebopLevel[player]);
	else if(hebopLevel[player] >= 900) sprintf(string[0], "%4d", 999);
	else sprintf(string[0], "%4d", hebopLevel[player] / 100 * 100 + 100);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, string[0], color);
	
	// �^�C��
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
}

// �G���f�B���O�I��
void hebopExcellent(int player, int *param) {
	onRecord[player] = 0;
	statc[player * 10 + 1]++;
	
	// �ԉ�
	if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 2]++;
	}
	
	// EXCELLENT
	param[0] = 0;
	printTinyFont(foffset[player] + 22, fyoffset[player] + 116, "HEBO+ MODE");
	printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
}

// ���ʕ\��
void hebopResult(int player) {
	if(statc[player * 10] == 0) {
		// �����L���O�o�^
		statc[player * 10 + 1] = hebopRegistRanking(player);
		if(statc[player * 10 + 1] != -1) hebopSaveRanking(player);
		
		// ���i�ʔ���
		statc[player * 10 + 2] = checkSecretGrade(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "SCORE");
	sprintf(string[0], "%13d", hebopScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", hebopLevel[player]);
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
	
	if(statc[player * 10 + 2] >= 4) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 159, "SECRET GRADE");
		sprintf(string[0], "%13s", hebopStrSecretGradeName[statc[player * 10 + 2]]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
	}
}

// �ݒ���
void hebopSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(hebopLoadConfig() == 0) hebopSaveConfig();
	
	// �����L���O��ǂݍ���
	if(hebopLoadRanking(player) == 0) hebopInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "HEBO+ OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "GHOST BLOCK",    7 * (cursor == 0));
		printFontGrid(2, 4, "LEVEL UP BONUS", 7 * (cursor == 1));
		printFontGrid(2, 5, "20G MODE",       7 * (cursor == 2));
		printFontGrid(2, 6, "START LEVEL",    7 * (cursor == 3));
		
		// �ݒ�l�\��
		if(hebopGhost == 0) sprintf(string[0], "LV100");
		else if(hebopGhost == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!hebopLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!hebop20G) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "%d", hebopStartLevel);
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
				hebopGhost = hebopGhost + move;
				if(hebopGhost < 0) hebopGhost = 2;
				if(hebopGhost > 2) hebopGhost = 0;
			}
			if(cursor == 1) hebopLvUpBonus = !hebopLvUpBonus;
			if(cursor == 2) hebop20G = !hebop20G;
			if(cursor == 3) {
				hebopStartLevel = hebopStartLevel + (move * 100);
				if(hebopStartLevel < 0) hebopStartLevel = 900;
				if(hebopStartLevel > 900) hebopStartLevel = 0;
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
			hebopSaveConfig();
			return;
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			hebopViewRanking(player);
		}
	}
}

// �ݒ��ۑ�
void hebopSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �ݒ���e
	saveBuf[1] = hebopGhost;
	saveBuf[2] = hebopLvUpBonus;
	saveBuf[3] = hebop20G;
	saveBuf[4] = hebopStartLevel;
	
	SaveFile("config/HEBOP_CONFIG.SAV", &saveBuf, 50 * 4);
}

// �ݒ��ǂݍ���
int hebopLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/HEBOP_CONFIG.SAV", &saveBuf, 50 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �ݒ���e
	hebopGhost = saveBuf[1];
	hebopLvUpBonus = saveBuf[2];
	hebop20G = saveBuf[3];
	hebopStartLevel = saveBuf[4];
	
	return 1;
}

// ���v���C�ۑ�
void hebopSaveReplay(int player) {
	saveBuf[900] = hebopLevel[player];
	saveBuf[901] = hebopScore[player];
	saveBuf[902] = hebopGhost;
	saveBuf[903] = hebopLvUpBonus;
	saveBuf[904] = hebop20G;
	saveBuf[905] = hebopStartLevel;
	saveBuf[906] = hebopVersion;
}

// ���v���C�ǂݍ���
void hebopLoadReplay(int player) {
	hebopGhost = saveBuf[902];
	hebopLvUpBonus = saveBuf[903];
	hebop20G = saveBuf[904];
	hebopStartLevel = saveBuf[905];
	hebopVersion = saveBuf[906];
	
	hebopPlayerInitial(player);	// �ݒ�𔽉f������
}

// ���v���C�ڍ�
void hebopReplayDetail() {
	printFontGrid(1, 4, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[901]);
	printFontGrid(22, 4, string[0], 0);
	
	printFontGrid(1, 5, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[900]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 7, "GHOST BLOCK", 0);
	if(saveBuf[902] == 0) sprintf(string[0], "LV100");
	else if(saveBuf[902] == 1) sprintf(string[0], "ON");
	else sprintf(string[0], "OFF");
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 8, "LEVEL UP BONUS", 0);
	if(!saveBuf[903]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "20G MODE", 0);
	if(!saveBuf[904]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[905]);
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[906]);
	printFontGrid(22, 11, string[0], 0);
}

// �����L���O�ۑ�
void hebopSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �����L���O���e
	for(i = 0; i < 20; i++) {
		saveBuf[1 + (i * 10) + 0] = hebopRankingTime[i];
		saveBuf[1 + (i * 10) + 1] = hebopRankingLevel[i];
		saveBuf[1 + (i * 10) + 2] = hebopRankingYear[i];
		saveBuf[1 + (i * 10) + 3] = hebopRankingMonth[i];
		saveBuf[1 + (i * 10) + 4] = hebopRankingDay[i];
		saveBuf[1 + (i * 10) + 5] = hebopRankingHour[i];
		saveBuf[1 + (i * 10) + 6] = hebopRankingMinute[i];
		saveBuf[1 + (i * 10) + 7] = hebopRankingSecond[i];
	}
	
	sprintf(string[0], "config/HEBOP_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 211 * 4);
}

// �����L���O�ǂݍ���
int hebopLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/HEBOP_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 211 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �����L���O���e
	for(i = 0; i < 20; i++) {
		hebopRankingTime[i]   = saveBuf[1 + (i * 10) + 0];
		hebopRankingLevel[i]  = saveBuf[1 + (i * 10) + 1];
		hebopRankingYear[i]   = saveBuf[1 + (i * 10) + 2];
		hebopRankingMonth[i]  = saveBuf[1 + (i * 10) + 3];
		hebopRankingDay[i]    = saveBuf[1 + (i * 10) + 4];
		hebopRankingHour[i]   = saveBuf[1 + (i * 10) + 5];
		hebopRankingMinute[i] = saveBuf[1 + (i * 10) + 6];
		hebopRankingSecond[i] = saveBuf[1 + (i * 10) + 7];
	}
}

// �����L���O������
void hebopInitRanking() {
	int i;
	
	for(i = 0; i < 20; i++) {
		hebopRankingTime[i] = 0;
		hebopRankingLevel[i] = 0;
		hebopRankingYear[i] = 0;
		hebopRankingMonth[i] = 0;
		hebopRankingDay[i] = 0;
		hebopRankingHour[i] = 0;
		hebopRankingMinute[i] = 0;
		hebopRankingSecond[i] = 0;
	}
}

// �����L���O�o�^
int hebopRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (hebopStartLevel)) return -1;
	
	for(i = 0; i < 20; i++) {
		// �����N�C��
		if((hebopLevel[player] > hebopRankingLevel[i]) || 
		   ((hebopLevel[player] == hebopRankingLevel[i]) && (gameTimer[player] < hebopRankingTime[i])))
		{
			// �����L���O�����炷
			for(j = 19; j > i; j--) {
				hebopRankingTime[j]   = hebopRankingTime[j - 1];
				hebopRankingLevel[j]  = hebopRankingLevel[j - 1];
				hebopRankingYear[j]   = hebopRankingYear[j - 1];
				hebopRankingMonth[j]  = hebopRankingMonth[j - 1];
				hebopRankingDay[j]    = hebopRankingDay[j - 1];
				hebopRankingHour[j]   = hebopRankingHour[j - 1];
				hebopRankingMinute[j] = hebopRankingMinute[j - 1];
				hebopRankingSecond[j] = hebopRankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			hebopRankingTime[i]   = gameTimer[player];
			hebopRankingLevel[i]  = hebopLevel[player];
			
			GetDateAndTime(&timebuf);
			hebopRankingYear[i]   = timebuf[0];
			hebopRankingMonth[i]  = timebuf[1];
			hebopRankingDay[i]    = timebuf[2];
			hebopRankingHour[i]   = timebuf[4];
			hebopRankingMinute[i] = timebuf[5];
			hebopRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �����L���O�\��
void hebopViewRanking(int player) {
	int i, erasemode;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "HEBO+ MODE RANKING", 6);
		printFontGrid(1, 3, "RANK LV.  TIME     DATE", 4);
		
		for(i = 0; i < 20; i++) {
			if(hebopRankingLevel[i] >= 999) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, 2, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 0);
			
			sprintf(string[0], "%d", hebopRankingLevel[i]);
			printFontGrid(6, 4 + i, string[0], 0);
			
			getTime(hebopRankingTime[i]);
			printFontGrid(11, 4 + i, string[0], 0);
			
			sprintf(string[0], "%04d/%02d/%02d", hebopRankingYear[i], hebopRankingMonth[i], hebopRankingDay[i]);
			printFontGrid(20, 4 + i, string[0], 0);
			
			sprintf(string[0], "%02d:%02d:%02d", hebopRankingHour[i], hebopRankingMinute[i], hebopRankingSecond[i]);
			printFontGrid(31, 4 + i, string[0], 0);
		}
		
		if(!erasemode) {
			printFontGrid(1, 27, "A/B:EXIT F:ERASE ALL", 6);
			
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
			printFontGrid(1, 25, "ERASE ALL RECORDS?", 2);
			printFontGrid(1, 27, "A:YES / B:NO", 2);
			
			// ����
			if(getPushState(player, 4)) {
				PlayWave(se_kettei);
				hebopInitRanking();
				hebopSaveRanking(player);
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
