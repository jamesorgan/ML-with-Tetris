//MASTER-EASY
//Special Thanks to www.tetrisconcept.com's wiki
//prefix:mas

int masVersion;				// �o�[�W�����i�ߋ��̃��v���C�Ƃ̌݊����p�j
int masCVersion = 8;		// ���݂̃o�[�W�����imasVersion�ɑ�������j

// BGM�ݒ�
int masBgmNo[3] = {0,1,7};	// BGM�ԍ��i000-499�A500-998�A999�j
int masFadeLv = 490;		// BGM���t�F�[�h�A�E�g�����郌�x��
int masBgmChange = 500;		// BGM��ς��郌�x��

// ���x���A�b�v�e�[�u��(420�ł̌����ǉ���)
// ���x
int masLevelTable[30] =
{
	4, 6, 8, 10, 12, 16, 32, 48, 64, 80, 96, 112, 128, 144, 4, 32, 64, 96, 128, 160,
	192, 224, 256, 512, 768, 1024, 1280, 1024, 768, 5120
};

// ���x��
int masLevelChange[30] = 
{
	30, 35, 40, 50, 60, 70, 80, 90, 100, 120, 140, 160, 170, 200, 220, 230, 233, 236, 239, 243,
	247, 251, 300, 330, 360, 400, 420, 450, 500, 10000
};

// ���x���A�b�v�e�[�u��(420�ł̌����ǉ��O)
// ���x
int masLevelTable7[29] =
{
	4, 6, 8, 10, 12, 16, 32, 48, 64, 80, 96, 112, 128, 144, 4, 32, 64, 96, 128, 160,
	192, 224, 256, 512, 768, 1024, 1280, 768, 5120
};

// ���x��
int masLevelChange7[29] = 
{
	30, 35, 40, 50, 60, 70, 80, 90, 100, 120, 140, 160, 170, 200, 220, 230, 233, 236, 239, 243,
	247, 251, 300, 330, 360, 400, 450, 500, 10000
};

// �����x���A�b�v�e�[�u��
int masLevelTableOld[51] =
{
//  *00, *10, *20, *30, *40, *50, *60, *70, *80, *90
	1  , 1  , 1  , 2  , 3  , 4  , 5  , 6  , 8  , 12 ,// 0**
	15 , 15 , 15 , 15 , 23 , 23 , 23 , 23 , 30 , 30 ,// 1**
	1  , 2  , 8  , 15 , 30 , 60 , 60 , 60 , 60 , 60 ,// 2**
	120, 120, 120, 180, 180, 180, 240, 240, 240, 240,// 3**
	300, 300, 300, 300, 240, 240, 240, 180, 180, 180,// 4**
	1200
};

// ��X�R�A
int masScoreTable[18] = 
{
	   400,   800,  1400,  2000,  3500,  5500,  8000,  12000,			// 8�`1
	 16000, 22000, 30000, 40000, 52000, 66000, 82000, 100000, 120000,	// S1�`S9
	126000																// GM
};

// �i�ʂ̕\����
str masStrGradeName[19] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0�` 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9�`17
	"GM"													// 18
};

int masModeNo = -1;		// ���[�h�ԍ�

int masLevel[2];		// ���x��
int masScore[2];		// �X�R�A
int masGrade[2];		// �i��
int masBravo[2];		// �S������
int masGMFlag[2 * 2];	// Gm�����t���O
int masGFlash[2];		// �i�ʕ\���Y�[�����o�p
int masLevelIndex[2];	// ���݂̑��x�ԍ�
int masLastLine[2];		// �Ō�̃��C�������̃��C����

int masIsBig = 0;		// BIG���ǂ���
int masBigMove = 0;		// BIG���̉��ړ��P��
int masGhost = 0;		// �S�[�X�g�̐ݒ�i0=LV0-99 1=���ON 2=���OFF�j
int masLvUpBonus = 0;	// ���x���A�b�v�{�[�i�X
int mas20G = 0;			// 20G���[�h
int masStartLevel = 0;	// �X�^�[�g���̃��x��

// �����L���O�ϐ�
int masRankingGrade[10];		// �i��
int masRankingLevel[10];		// ���x��
int masRankingTime[10];			// �^�C��
int masRankingYear[10];			// �����N�C�������i�N�j
int masRankingMonth[10];		// �����N�C�������i���j
int masRankingDay[10];			// �����N�C�������i���j
int masRankingHour[10];			// �����N�C�������i���j
int masRankingMinute[10];		// �����N�C�������i���j
int masRankingSecond[10];		// �����N�C�������i�b�j

// �C�x���g����
void masPluginEvent(int player, int event, int *param) {
	int i;
	
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != masModeNo)) return;
	
	if(event == 0) {
		masModeNo = addModePlugin("MASTER-EASY");	// ���[�h��o�^����
	} else if(event == 7) {
		if(!ending[player]) masMoveInit(player);	// �u���b�N�o��
	} else if(event == 12) {
		if(!ending[player]) masCalcScore(player, param[0]);	// �X�R�A�v�Z
	} else if(event == 15) {
		masViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		masSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		masPlayerInitial(player);	// ����������
	} else if(event == 21) {
		masResult(player);	// ���ʕ\��
	} else if(event == 24) {
		ending[player] = 3;	// �UEND
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		masExcellent(player, param);	// �G���f�B���O�I��
	} else if(event == 28) {
		masIncrementTime(player);	// ���Ԃ�i�߂�
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		masSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		masLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		masLoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		masReplayDetail(param[0]);	// ���v���C�ڍ�
	}
}

// ����������
void masPlayerInitial(int player) {
	// �o�[�W�����ݒ�
	if(!playback) masVersion = masCVersion;
	
	// �R���{�L��
	enable_combo[player] = 1;
	
	// �ϐ���������
	if(masVersion >= 7) {
		if(masStartLevel > 0) masLevel[player] = masStartLevel;
		else masLevel[player] = -1;
		
		backno = masLevel[player] / 100;
	} else {
		masLevel[player] = -1;
	}
	masScore[player] = 0;
	masGrade[player] = 0;
	masBravo[player] = 0;
	masGMFlag[player * 2 + 0] = 0;
	masGMFlag[player * 2 + 1] = 0;
	masGFlash[player] = 0;
	masLevelIndex[player] = 0;
	masLastLine[player] = 0;
	bgmlv = masBgmNo[0];
	
	if(masVersion >= 5) {
		speedtype[player] = 2;
		wait1[player] = 30;
		wait2[player] = 40;
		wait3[player] = 30;
		waitt[player] = 16;
	} else if(masVersion >= 4) {
		speedtype[player] = 2;
		wait1[player] = 25;
		wait2[player] = 40;
		wait3[player] = 30;
		waitt[player] = 16;
	} else if(masVersion >= 1) {
		speedtype[player] = 2;
		wait1[player] = 30;
		wait2[player] = 40;
		wait3[player] = 30;
		waitt[player] = 15;
	}
	
	// �ݒ�𔽉f������
	IsBig[player] = masIsBig;
	BigMove[player] = masBigMove;
	if(masGhost == 2) ghost[player] = 0;
	
	// �����X�s�[�h��ݒ�
	masSpeedUp(player);
}

// �u���b�N�o��
void masMoveInit(int player) {
	int temp;
	
	// �ŏ��̃t���[���Ȃ�
	if(statc[player * 10 + 3] == 0) {
		// ���x���A�b�v����
		if(masLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		
		if(masLevel[player] % 100 != temp) {
			masLevel[player]++;
			if(masLevel[player] % 100 == temp) PlaySE(se_lvstop);
			masSpeedUp(player);
		}
	}
}

// �X�R�A�v�Z
void masCalcScore(int player, int lines) {
	int i, temp, bo, bai, nextsec, combopts;
	
	if(IsBig[player]) lines = lines * 2;	// BIG�ł͏������C����2�{
	
	bo = (masLevel[player] + lines) / 4 + sdrop[player] + qdrop[player] + qput[player];
	
	if(masVersion >= 6) {
		combopts = cmbpts[player];
	} else if(masVersion <= 2) {
		combopts = combo[player] - 1 + (2 * lines - 1);
	} else if(combo[player] == 1) {
		combopts = 1;
	} else {
		combopts = combo[player] - 2 + (2 * masLastLine[player] - 1);
	}
	bai = lines * combopts;
	
	if(isBravo(player)) {
		// �S��������ƃX�R�A4�{
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		masBravo[player]++;
		bai = bai * 4;
	}
	
	// �X�R�A���Z
	masScore[player] = masScore[player] + (bo * bai);
	
	// �i�ʏ㏸
	while((masGrade[player] < 17) && (masScore[player] >= masScoreTable[masGrade[player]])) {
		PlaySE(se_rankup);
		masGrade[player]++;
		masGFlash[player] = 120;
	}
	
	masLastLine[player] = lines;
	
	// ���x���A�b�v
	nextsec = masLevel[player] / 100 * 100 + 100;
	if(!masLvUpBonus) masLevel[player] = masLevel[player] + lines;
	else masLevel[player] = masLevel[player] + lines + ((lines >= 3) * (lines - 2));
	
	if(masLevel[player] >= 999) {
		// �G���f�B���O
		masLevel[player] = 999;
		timeOn[player] = 0;
		
		// Gm��������
		// 13:30:00�ȓ��Agmflag1��gmflag2�_���ς݁A�X�R�A126000�_�ȏ�
		if((gameTimer[player] <= 48600) && (masScore[player] >= masScoreTable[17]) && 
		   (masGMFlag[player * 2 + 0]) && (masGMFlag[player * 2 + 1]))
		{
			PlaySE(se_ttclear);
			masGrade[player] = 18;
			masGFlash[player] = 120;
			ending[player] = 2;
			ending_timeOn[player] = 1;
			fastroll[player] = 2;
			bgmlv = masBgmNo[2];
			PlayBGM();
		}
		else
		{
			ending[player] = 4;
		}
	} else {
		// ���x���X�g�b�v��
		if(masLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		if(masLevel[player] % 100 == temp) PlaySE(se_lvstop);
		
		if(masLevel[player] >= nextsec) {
			// ���x���A�b�v��
			PlaySE(se_levelup);
			
			// �w�i�؂�ւ�
			bgfadesw = 1;
			bgfadebg = nextsec / 100;
			
			// Gm�t���O�P��������iLV300�ɂȂ����Ƃ��ɒi�ʂ�1�ȏ�j
			if((nextsec == 300) && (masGrade[player] >= 8)) {
				masGMFlag[player * 2 + 0] = 1;
				objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
			}
			
			// Gm�t���O�Q��������iLV500�ɂȂ����Ƃ��ɒi�ʂ�S4�ȏ�j
			if((nextsec == 500) && (masGrade[player] >= 12)) {
				masGMFlag[player * 2 + 1] = 1;
				objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
			}
		}
		
		// �X�s�[�h�A�b�v
		masSpeedUp(player);
	}
}

// �X�s�[�h�A�b�v
void masSpeedUp(int player) {
	int index;
	
	// �X�s�[�h��ς���
	if(mas20G) {
		speedtype[player] = 2;
		sp[player] = 5120;
	} else if(masVersion >= 1) {
		if(masVersion >= 8) {
			while(masLevel[player] >= masLevelChange[masLevelIndex[player]]) masLevelIndex[player]++;
		} else if(masVersion >= 7) {
			while(masLevel[player] >= masLevelChange7[masLevelIndex[player]]) masLevelIndex[player]++;
		} else {
			if(masLevel[player] >= masLevelChange7[masLevelIndex[player]]) masLevelIndex[player]++;
		}
		
		if(masVersion >= 8) {
			sp[player] = masLevelTable[masLevelIndex[player]];
		} else {
			sp[player] = masLevelTable7[masLevelIndex[player]];
		}
	} else {
		index = masLevel[player] / 10;
		if(index < 0) index = 0;
		if(index > 50) index = 50;
		sp[player] = masLevelTableOld[index];
	}
	
	// BGM�t�F�[�h�A�E�g
	if((masLevel[player] >= masFadeLv) && (masLevel[player] < masBgmChange) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// ���y�؂�ւ�
	if((masLevel[player] >= masBgmChange) && (bgmlv == masBgmNo[0])) {
		bgmlv = masBgmNo[1];
		PlayBGM();
	}
	
	// �S�[�X�g������
	if((masLevel[player] >= 100) && (masGhost == 0)) {
		ghost[player] = 0;
	}
}

// �X�R�A�\��
void masViewScore(int player) {
	int color, color2, x, y, k, zoomx, zoomy, temp;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// �i��
	color2 = (count % 4 / 2) * (is20G(player));
	
	if(masGFlash[player] > 108) {
		// �Y�[����
		k = masGFlash[player] - 96;
		zoomx = (90 * k / 12 - 90) / 2;
		zoomy = (24 * k / 12 - 24) / 2;
		k = 65536 * k / 12;
		
		x = foffset[player] + 63 - zoomx;
		y = fyoffset[player] + 40 - zoomy;
		
		if(masGrade[player] < 9) {
			// 9�`1
			ExBltRectR(sg_grade, x, y, 0, (color2 * 216) + (masGrade[player] * 24), 90, 24, k, k);
		} else if(masGrade[player] < 18) {
			// S1�`S9
			ExBltRectR(sg_grade, x, y, 90, (color2 * 216) + ((masGrade[player] - 9) * 24), 90, 24, k, k);
		} else {
			// Gm
			ExBltRectR(sg_grade, x + 9, y, 450, (color2 * 216) + 180, 90, 32, k, k);
		}
	} else {
		// �ʏ�
		x = foffset[player] + 63;
		y = fyoffset[player] + 40;
		
		if(masGrade[player] < 9) {
			// 9�`1
			ExBltRect(sg_grade, x, y, 0, (color2 * 216) + (masGrade[player] * 24), 90, 24);
		} else if(masGrade[player] < 18) {
			// S1�`S9
			ExBltRect(sg_grade, x, y, 90, (color2 * 216) + ((masGrade[player] - 9) * 24), 90, 24);
		} else {
			// Gm
			ExBltRect(sg_grade, x + 9, y, 450, (color2 * 216) + 180, 90, 32);
		}
	}
	
	// �ڕW�X�R�A
	printTinyFont(foffset[player] + 96, fyoffset[player] + 71, "NEXT GRADE");
	printTinyFont(foffset[player] + 96, fyoffset[player] + 78, "AT");
	if(masGrade[player] < 17) {
		sprintf(string[0], "%d", masScoreTable[masGrade[player]]);
	} else {
		sprintf(string[0], ";;;;;;");
	}
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 86, string[0], color);
	printTinyFont(foffset[player] + 96, fyoffset[player] + 96, "POINTS");
	
	// �S������
	if(masBravo[player]) {
		printTinyFont(foffset[player] + 96, fyoffset[player] + 117, "BRAVO");
		sprintf(string[0], "%d", masBravo[player]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 125, string[0], color);
	}
	
	// �X�R�A
	printTinyFont(foffset[player] + 96, fyoffset[player] + 135, "POINTS");
	sprintf(string[0], "%d", masScore[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 143, string[0], color);
	
	// ���x���i���q�j
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(masLevel[player] == -1) sprintf(string[0], "%4d", 0);	// -1�Ȃ�0�ƕ\������(�����I�ɂ͍ŏ���-1�ɂȂ��Ă���)
	else sprintf(string[0], "%4d", masLevel[player]);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// ���x���i�����j
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	if(masVersion >= 1) {
		temp = sp[player] / 128;
		if(temp > 22) temp = 22;
		ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22 - temp, 143, 22, 1);
	} else {
		if(sp[player] <= 600) {
			ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22 - ((sp[player] * 24) / 660), 143, 22, 1);
		} else {
			ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 0, 143, 22, 1);
		}
	}
	
	// ���x���i����j
	if(masLevel[player] >= 900) sprintf(string[0], "%4d", 999);
	else sprintf(string[0], "%4d", masLevel[player] / 100 * 100 + 100);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, string[0], color);
	
	// �^�C��
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
}

// BGM�ǂݍ���
void masLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 3; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/3)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(masBgmNo[i]);
		}
	}
}

// �G���f�B���O�I��
void masExcellent(int player, int *param) {
	onRecord[player] = 0;
	statc[player * 10 + 1]++;
	
	if(masGrade[player] >= 18) {
		// YOU ARE GRAND MASTER!!
		param[0] = 1;
		
		// �ԉ�
		if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 30)) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			statc[player * 10 + 2]++;
		}
	} else {
		// EXCELLENT
		param[0] = 0;
		
		if(statc[player * 10] < 220) {
			// �ԉ�
			if((statc[player * 10 + 1] % 40 == 0) && (statc[player * 10 + 2] < 4)) {
				objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
				statc[player * 10 + 2]++;
			}
			
			// �{�^���ŃX�L�b�v
			if(getPushState(player, 4)) {
				statc[player * 10] = 219;
			}
		} else {
			if(statc[player * 10] == 220) objectClearPl(player);	// �ԉ΂�����
			
			printTinyFont(foffset[player] + 10, fyoffset[player] + 130, "TRY AGAIN TO BE");
			printTinyFont(foffset[player] + 12, fyoffset[player] + 137, "A GRAND MASTER");
			
			// �{�^���ŃX�L�b�v
			if(getPushState(player, 4)) {
				statc[player * 10] = 600;
			}
		}
	}
}

// ���Ԃ�i�߂�
void masIncrementTime(int player) {
	int i;
	
	// ���[���I��
	if((ending[player] == 2) && (edrec[player] >= 60 * 60)) {
		ending[player] = 3;
		stat[player] = 10;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
	
	// �i�ʂ����鉉�o�̎��Ԃ����炷
	if(masGFlash[player] > 0) masGFlash[player]--;
}

// �ݒ���
void masSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(masLoadConfig() == 0) masSaveConfig();
	
	// �����L���O��ǂݍ���
	if(masLoadRanking(player) == 0) masInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "MASTER-EASY OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "BIG",            7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",       7 * (cursor == 1));
		printFontGrid(2, 5, "GHOST BLOCK",    7 * (cursor == 2));
		printFontGrid(2, 6, "LEVEL UP BONUS", 7 * (cursor == 3));
		printFontGrid(2, 7, "20G MODE",       7 * (cursor == 4));
		printFontGrid(2, 8, "START LEVEL",    7 * (cursor == 5));
		
		// �ݒ�l�\��
		if(!masIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!masBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(masGhost == 0) sprintf(string[0], "LV100");
		else if(masGhost == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(!masLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(!mas20G) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		sprintf(string[0], "%d", masStartLevel);
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		// �J�[�\���ړ�
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 5;
			if(cursor > 5) cursor = 0;
		}
		
		// �l��ύX
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) masIsBig = !masIsBig;
			if(cursor == 1) masBigMove = !masBigMove;
			if(cursor == 2) {
				masGhost = masGhost + move;
				if(masGhost < 0) masGhost = 2;
				if(masGhost > 2) masGhost = 0;
			}
			if(cursor == 3) masLvUpBonus = !masLvUpBonus;
			if(cursor == 4) mas20G = !mas20G;
			if(cursor == 5) {
				masStartLevel = masStartLevel + (move * 100);
				if(masStartLevel < 0) masStartLevel = 900;
				if(masStartLevel > 900) masStartLevel = 0;
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
			masSaveConfig();
			return;
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			masViewRanking(player);
		}
	}
}

// ���ʕ\��
void masResult(int player) {
	if(statc[player * 10] == 0) {
		// �����L���O�o�^
		statc[player * 10 + 1] = masRegistRanking(player);
		if(statc[player * 10 + 1] != -1) masSaveRanking(player);
		
		// ���i�ʔ���
		statc[player * 10 + 2] = checkSecretGrade(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "GRADE");
	sprintf(string[0], "%13s", masStrGradeName[masGrade[player]]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "SCORE");
	sprintf(string[0], "%13d", masScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "LEVEL");
	sprintf(string[0], "%13d", masLevel[player]);
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
	
	if(statc[player * 10 + 2] >= 4) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 179, "SECRET GRADE");
		sprintf(string[0], "%13s", masStrGradeName[statc[player * 10 + 2]]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 187, string[0], 0);
	}
}

// ���v���C�ۑ�
void masSaveReplay(int player) {
	saveBuf[900] = masIsBig;
	saveBuf[901] = masBigMove;
	saveBuf[902] = masGhost;
	saveBuf[903] = masLvUpBonus;
	saveBuf[904] = masVersion;
	saveBuf[905] = masLevel[player];
	saveBuf[906] = masScore[player];
	saveBuf[907] = masGrade[player];
	saveBuf[908] = masBravo[player];
	saveBuf[909] = mas20G;
	saveBuf[910] = masStartLevel;
}

// ���v���C�ǂݍ���
void masLoadReplay(int player) {
	masIsBig = saveBuf[900];
	masBigMove = saveBuf[901];
	masGhost = saveBuf[902];
	masLvUpBonus = saveBuf[903];
	masVersion = saveBuf[904];
	mas20G = saveBuf[909];
	masStartLevel = saveBuf[910];
	
	masPlayerInitial(player);	// �ݒ�𔽉f������
}

// ���v���C�ڍ�
void masReplayDetail(int number) {
	printFontGrid(1, 4, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[904]);
	printFontGrid(22, 4, string[0], 0);
	
	if(saveBuf[904] >= 2) {
		printFontGrid(1, 6, "GRADE", 0);
		if((saveBuf[907] >= 0) && (saveBuf[907] <= 18)) {
			printFontGrid(22, 6, masStrGradeName[saveBuf[907]], 0);
		} else {
			printFontGrid(22, 6, "???", 0);
		}
		
		printFontGrid(1, 7, "SCORE", 0);
		sprintf(string[0], "%d", saveBuf[906]);
		printFontGrid(22, 7, string[0], 0);
		
		printFontGrid(1, 8, "LEVEL", 0);
		sprintf(string[0], "%d", saveBuf[905]);
		printFontGrid(22, 8, string[0], 0);
		
		printFontGrid(1, 9, "BRAVO", 0);
		sprintf(string[0], "%d", saveBuf[908]);
		printFontGrid(22, 9, string[0], 0);
	}
	
	printFontGrid(1, 11, "BIG", 0);
	if(!saveBuf[900]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "BIG MOVE", 0);
	if(!saveBuf[901]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 12, string[0], 0);
	
	printFontGrid(1, 13, "GHOST BLOCK", 0);
	if(saveBuf[902] == 0) sprintf(string[0], "LV100");
	else if(saveBuf[902] == 1) sprintf(string[0], "ON");
	else sprintf(string[0], "OFF");
	printFontGrid(22, 13, string[0], 0);
	
	printFontGrid(1, 14, "LEVEL UP BONUS", 0);
	if(!saveBuf[903]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 14, string[0], 0);
	
	printFontGrid(1, 15, "20G MODE", 0);
	if(!saveBuf[909]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 15, string[0], 0);
	
	printFontGrid(1, 16, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[910]);
	printFontGrid(22, 16, string[0], 0);
}

// �ݒ��ۑ�
void masSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x5453414D;
	saveBuf[3] = 0x31455245;
	
	// �ݒ���e
	saveBuf[4] = masIsBig;
	saveBuf[5] = masBigMove;
	saveBuf[6] = masGhost;
	saveBuf[7] = masLvUpBonus;
	saveBuf[8] = mas20G;
	saveBuf[9] = masStartLevel;
	
	SaveFile("config/MASTER_EASY_CONFIG.SAV", &saveBuf, 100 * 4);
}

// �ݒ��ǂݍ���
int masLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/MASTER_EASY_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x5453414D) return 0;
	if(saveBuf[3] != 0x31455245) return 0;
	
	// �ݒ���e
	masIsBig = saveBuf[4];
	masBigMove = saveBuf[5];
	masGhost = saveBuf[6];
	masLvUpBonus = saveBuf[7];
	mas20G = saveBuf[8];
	masStartLevel = saveBuf[9];
	
	return 1;
}

// �����L���O�ۑ�
void masSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 10) + 0] = masRankingGrade[i];
		saveBuf[1 + (i * 10) + 1] = masRankingLevel[i];
		saveBuf[1 + (i * 10) + 2] = masRankingTime[i];
		saveBuf[1 + (i * 10) + 3] = masRankingYear[i];
		saveBuf[1 + (i * 10) + 4] = masRankingMonth[i];
		saveBuf[1 + (i * 10) + 5] = masRankingDay[i];
		saveBuf[1 + (i * 10) + 6] = masRankingHour[i];
		saveBuf[1 + (i * 10) + 7] = masRankingMinute[i];
		saveBuf[1 + (i * 10) + 8] = masRankingSecond[i];
	}
	
	sprintf(string[0], "config/MASTER_EASY_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 111 * 4);
}

// �����L���O�ǂݍ���
int masLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/MASTER_EASY_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 111 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		masRankingGrade[i] = saveBuf[1 + (i * 10) + 0];
		masRankingLevel[i] = saveBuf[1 + (i * 10) + 1];
		masRankingTime[i] = saveBuf[1 + (i * 10) + 2];
		masRankingYear[i] = saveBuf[1 + (i * 10) + 3];
		masRankingMonth[i] = saveBuf[1 + (i * 10) + 4];
		masRankingDay[i] = saveBuf[1 + (i * 10) + 5];
		masRankingHour[i] = saveBuf[1 + (i * 10) + 6];
		masRankingMinute[i] = saveBuf[1 + (i * 10) + 7];
		masRankingSecond[i] = saveBuf[1 + (i * 10) + 8];
	}
}

// �����L���O������
int masInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		masRankingGrade[i] = 0;
		masRankingLevel[i] = 0;
		masRankingTime[i] = 0;
		masRankingYear[i] = 0;
		masRankingMonth[i] = 0;
		masRankingDay[i] = 0;
		masRankingHour[i] = 0;
		masRankingMinute[i] = 0;
		masRankingSecond[i] = 0;
	}
}

// �����L���O�o�^
int masRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (masLvUpBonus) || (mas20G) || (masStartLevel)) return -1;
	
	for(i = 0; i < 10; i++) {
		// �����N�C��
		if(
		    (masGrade[player] > masRankingGrade[i]) || 
		    ((masGrade[player] == masRankingGrade[i]) && (masLevel[player] > masRankingLevel[i])) || 
		    ((masGrade[player] == masRankingGrade[i]) && (masLevel[player] == masRankingLevel[i]) && (gameTimer[player] < masRankingTime[i]))
		  )
		{
			// �����L���O�����炷
			for(j = 9; j > i; j--) {
				masRankingGrade[j] = masRankingGrade[j - 1];
				masRankingLevel[j] = masRankingLevel[j - 1];
				masRankingTime[j] = masRankingTime[j - 1];
				masRankingYear[j] = masRankingYear[j - 1];
				masRankingMonth[j] = masRankingMonth[j - 1];
				masRankingDay[j] = masRankingDay[j - 1];
				masRankingHour[j] = masRankingHour[j - 1];
				masRankingMinute[j] = masRankingMinute[j - 1];
				masRankingSecond[j] = masRankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			masRankingGrade[i] = masGrade[player];
			masRankingLevel[i] = masLevel[player];
			masRankingTime[i] = gameTimer[player];
			
			GetDateAndTime(&timebuf);
			masRankingYear[i] = timebuf[0];
			masRankingMonth[i] = timebuf[1];
			masRankingDay[i] = timebuf[2];
			masRankingHour[i] = timebuf[4];
			masRankingMinute[i] = timebuf[5];
			masRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �����L���O�\��
void masViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "MASTER-EASY MODE RANKING", 6);
		printFontGrid(1, 3, "RANK GRADE LEVEL TIME", 4);
		
		for(i = 0; i < 10; i++) {
			if(masRankingLevel[i] >= 999) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, 0, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			if((masRankingGrade[i] >= 0) && (masRankingGrade[i] < 19)) {
				printFontGrid(6, 4 + i, masStrGradeName[masRankingGrade[i]], 7 * (cursor == i));
			} else {
				printFontGrid(6, 4 + i, "???", 7 * (cursor == i));
			}
			
			sprintf(string[0], "%d", masRankingLevel[i]);
			printFontGrid(12, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(masRankingTime[i]);
			printFontGrid(18, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// ���t�Ǝ���
			sprintf(string[0],
			        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
			        masRankingYear[cursor], masRankingMonth[cursor], masRankingDay[cursor],
			        masRankingHour[cursor], masRankingMinute[cursor], masRankingSecond[cursor]);
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
				masInitRanking();
				masSaveRanking(player);
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
