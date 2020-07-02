//DEVIL-DOOM
//prefix:dvld

// �o�[�W����
int dvldVersion;			// �o�[�W�����ԍ��i�Â����v���C�Đ��p�j
int dvldCVersion = 3;		// ���݂̃o�[�W����

// ���x���A�b�v�e�[�u��    000, 100, 200, 300, 400, 500, 600, 700, 800, 900,1000,1100,1200,1300
int dvldWait1Table[14] = {  11,  10,   9,   6,   6,   5,   4,   4,   4,   4,   6,   4,   3,   3};
int dvldWait2Table[14] = {   8,   5,   5,   4,   4,   3,   3,   3,   3,   3,   2,   2,   2,   2};
int dvldWait3Table[14] = {  20,  18,  16,  13,  13,  12,  11,  11,  11,  11,  11,  10,   9,   9};
int dvldWaittTable[14] = {   9,   8,   7,   7,   7,   6,   5,   5,   5,   5,   5,   5,   5,   5};

// �����x���A�b�v�e�[�u��
int dvldWait1TableOld[14] = {  11,  10,   9,   6,   6,   5,   4,   4,   4,   4,   6,   4,   3,   2};
int dvldWait2TableOld[14] = {   8,   5,   5,   4,   4,   3,   3,   3,   3,   3,   2,   2,   2,   6};
int dvldWait3TableOld[14] = {  20,  18,  16,  13,  13,  12,  11,  11,  11,  11,  11,  10,   9,  14};
int dvldWaittTableOld[14] = {   9,   8,   7,   7,   7,   6,   5,   5,   5,   5,   5,   5,   5,   7};

// ����オ��Ԋu      000, 100, 200, 300, 400, 500, 600, 700, 800, 900,1000,1100,1200,1300
int dvldRiseMin[14] = {  0,   0,   0,   0,   0,  25,  20,  10,   8,   5,   0,   0,   0,   0};
int dvldRiseMax[14] = {  0,   0,   0,   0,   0,  35,  30,  20,  18,  15,   0,   0,   0,   0};

// BGM
int dvldBgmListTable[5]   = {2, 3, 4, 5, 6};			// �g�p����BGM
int dvldBgmFadeTable[4]   = {485, 685, 985, 10000};		// �t�F�[�h�A�E�g���郌�x��
int dvldBgmChangeTable[4] = {500, 700, 1000, 10000};	// �؂�ւ��郌�x��
int dvldBgmIndex          = 0;							// ���݂�BGM�ԍ�

// �i�ʂ̕\����
str dvldStrGradeName[15] = 
{
	"1", "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13", "GOD"
};

// ���i�ʂ̕\����
str dvldStrSecretGradeName[19] = 
{
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  0�` 8
	"M1", "M2", "M3", "M4", "M5", "M6", "M7", "M8", "M9",	//  9�`17
	"GM"													// 18
};

// �ϐ�
int dvldModeNo = -1;		// ���[�h�ԍ�

int dvldLevel[2];			// ���x��
int dvldScore[2];			// �X�R�A
int dvldGrade[2];			// �i��
int dvldEndFlag[2];			// �N���A�t���O

int dvldRiseCount[2];		// ����オ��p�J�E���^

int dvldSTimer[2];			// �Z�N�V�����^�C�}�[
int dvldSkill[2];			// �w�{���X��

int dvldSectionTime[13 * 2];	// ���̃v���C�̃Z�N�V�����^�C��

int dvldMedalStat[4 * 2];	// ���_���̏��(0=�Ȃ� 1=�� 2=�� 3=��)
int dvldMedalAnim[4 * 2];	// ���_���l���A�j���[�V�����p�J�E���^

int dvldTSpinFrame[2];		// T-SPIN�\���̎c�莞��
int dvldRegretFrame[2];		// REGRET�\���̎c�莞��

int dvldIsBig = 0;			// BIG���ǂ���
int dvldBigMove = 1;		// BIG���̉��ړ��P��
int dvldLvUpBonus = 1;		// ���x���A�b�v�{�[�i�X
int dvldTSpin = 1;			// T-SPIN�̎��
int dvldTorikan = 10980;	// LV500�Ƃ�J����^�C�� (3:03:00)
int dvldRiseEnable = 1;		// ����オ��ONOFF
int dvldStartLevel = 0;		// �X�^�[�g���̃��x��

// �����L���O�ϐ�
int dvldRankingGrade[10];			// �i��
int dvldRankingLevel[10];			// ���x��
int dvldRankingTime[10];			// �^�C��
int dvldRankingEnd[10];				// �N���A�t���O
int dvldRankingMedal[4 * 10];		// ���_��
int dvldRankingYear[10];			// �����N�C�������i�N�j
int dvldRankingMonth[10];			// �����N�C�������i���j
int dvldRankingDay[10];				// �����N�C�������i���j
int dvldRankingHour[10];			// �����N�C�������i���j
int dvldRankingMinute[10];			// �����N�C�������i���j
int dvldRankingSecond[10];			// �����N�C�������i�b�j

// �Z�N�V�����^�C�������L���O�ϐ�
int dvldRankingSectionTime[13];		// �^�C��
int dvldRankingSectionEnd[13];		// �N���A�t���O
int dvldRankingSectionYear[13];		// �����N�C�������i�N�j
int dvldRankingSectionMonth[13];	// �����N�C�������i���j
int dvldRankingSectionDay[13];		// �����N�C�������i���j
int dvldRankingSectionHour[13];		// �����N�C�������i���j
int dvldRankingSectionMinute[13];	// �����N�C�������i���j
int dvldRankingSectionSecond[13];	// �����N�C�������i�b�j

// �C�x���g����
void dvldPluginEvent(int player, int event, int *param) {
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != dvldModeNo)) return;
	
	if(event == 0) {
		dvldModeNo = addModePlugin("DEVIL-DOOM");	// ���[�h��o�^����
	} else if(event == 7) {
		if(!ending[player]) dvldMoveInit(player);	// �u���b�N�o��
	} else if(event == 10) {
		dvldRiseField(player);	// ����オ��
	} else if(event == 12) {
		if(!ending[player]) dvldCalcScore(player, param[0]);	// �X�R�A�v�Z
	} else if(event == 15) {
		dvldViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		dvldSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		dvldPlayerInitial(player);	// ����������
	} else if(event == 21) {
		dvldResult(player, param);	// ���ʕ\��
	} else if(event == 24) {
		dvldEndingStart(player);	// �G���f�B���O�˓�
	} else if(event == 25) {
		dvldExcellent(player, param);	// �G���f�B���O�I��
	} else if(event == 28) {
		dvldIncrementTime(player);	// ���Ԃ�i�߂�
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		dvldSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		dvldLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		dvldLoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		dvldReplayDetail(param[0]);	// ���v���C�ڍ�
	}
}

// ����������
void dvldPlayerInitial(int player) {
	int i;
	
	// �o�[�W�����ݒ�
	if(!playback) dvldVersion = dvldCVersion;
	
	// �ϐ���������
	if(dvldVersion >= 3) {
		if(dvldStartLevel > 0) dvldLevel[player] = dvldStartLevel;
		else dvldLevel[player] = -1;
		
		if(dvldLevel[player] >= 1000) oblk_spawn[player] = 1;
		
		backno = dvldLevel[player] / 100;
		if(backno > 9) backno = 9;
	} else {
		dvldLevel[player] = -1;
	}
	dvldScore[player] = 0;
	dvldGrade[player] = 0;
	dvldEndFlag[player] = 0;
	dvldRiseCount[player] = 0;
	dvldSTimer[player] = 0;
	dvldSkill[player] = 0;
	dvldTSpinFrame[player] = 0;
	dvldRegretFrame[player] = 0;
	
	for(i = 0; i < 4; i++) {
		dvldMedalStat[player * 4 + i] = 0;
		dvldMedalAnim[player * 4 + i] = -1;
	}
	
	for(i = 0; i < 13; i++) dvldSectionTime[i + player * 13] = 0;
	
	dvldBgmIndex = 0;
	bgmlv = dvldBgmListTable[0];
	framecolor[player] = 2;
	enable_combo[player] = 1;
	
	// �ݒ�𔽉f������
	IsBig[player] = dvldIsBig;
	BigMove[player] = dvldBigMove;
	tspin_type[player] = dvldTSpin;
	
	// �����X�s�[�h��ݒ�
	dvldSpeedUp(player);
}

// �X�s�[�h�A�b�v
void dvldSpeedUp(int player) {
	int temp, index;
	
	// 20G
	sp[player] = 1200;
	
	// �X�s�[�h��ς���
	index = dvldLevel[player] / 100;
	if(index < 0) index = 0;
	if(index > 13) index = 13;
	
	if(dvldVersion >= 2) {
		wait1[player] = dvldWait1Table[index];
		wait2[player] = dvldWait2Table[index];
		wait3[player] = dvldWait3Table[index];
		waitt[player] = dvldWaittTable[index];
	} else {
		wait1[player] = dvldWait1TableOld[index];
		wait2[player] = dvldWait2TableOld[index];
		wait3[player] = dvldWait3TableOld[index];
		waitt[player] = dvldWaittTableOld[index];
	}
	
	// BGM�t�F�[�h�A�E�g
	if((dvldLevel[player] >= dvldBgmFadeTable[dvldBgmIndex]) && (dvldLevel[player] < dvldBgmChangeTable[dvldBgmIndex]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// BGM�؂�ւ�
	temp = 0;
	while(dvldLevel[player] >= dvldBgmChangeTable[dvldBgmIndex]) {
		dvldBgmIndex++;
		bgmlv = dvldBgmListTable[dvldBgmIndex];
		if(onRecord[player]) temp = 1;
	}
	if(temp) PlayBGM();
}

// �u���b�N�o��
void dvldMoveInit(int player) {
	// �ŏ��̃t���[���Ȃ�
	if(statc[player * 10 + 3] == 0) {
		// ���x���A�b�v����
		if(dvldLevel[player] % 100 != 99) {
			dvldLevel[player]++;
			if(dvldLevel[player] % 100 == 99) PlaySE(se_lvstop);
			dvldSpeedUp(player);
		}
		
		// ����オ��J�E���^
		if(dvldRiseCount[player] > 0) dvldRiseCount[player]--;
	}
}

// �X�R�A�v�Z
void dvldCalcScore(int player, int lines) {
	int i, temp, bo, bai, nextsec, lv;
	
	lv = dvldLevel[player];	// �オ��O�̃��x��
	
	// �w�{���X�񐔑���
	if(lines >= 4) {
		dvldSkill[player]++;
		
		// SK���_���l��
		if((dvldSkill[player] == 5) || (dvldSkill[player] == 10) || (dvldSkill[player] == 17)) {
			PlaySE(se_medal);
			dvldMedalStat[player * 4 + 3]++;
			dvldMedalAnim[player * 4 + 3] = 0;
		}
	}
	
	// CO���_���l��
	if(combo2[player] == 4) {
		if(dvldMedalStat[player * 4 + 2] < 1) {
			PlaySE(se_medal);
			dvldMedalStat[player * 4 + 2] = 1;
			dvldMedalAnim[player * 4 + 2] = 0;
		}
	} else if(combo2[player] == 5) {
		if(dvldMedalStat[player * 4 + 2] < 2) {
			PlaySE(se_medal);
			dvldMedalStat[player * 4 + 2] = 2;
			dvldMedalAnim[player * 4 + 2] = 0;
		}
	} else if(combo2[player] == 7) {
		if(dvldMedalStat[player * 4 + 2] < 3) {
			PlaySE(se_medal);
			dvldMedalStat[player * 4 + 2] = 3;
			dvldMedalAnim[player * 4 + 2] = 0;
		}
	}
	
	// ���x���A�b�v
	nextsec = dvldLevel[player] / 100 * 100 + 100;
	if(!dvldLvUpBonus) dvldLevel[player] = dvldLevel[player] + lines;
	else dvldLevel[player] = dvldLevel[player] + lines + ((lines >= 3) * (lines - 2));
	
	if(dvldLevel[player] >= 1300) {
		// �G���f�B���O
		dvldLevel[player] = 1300;
		ending[player] = 1;
		timeOn[player] = 0;
		dvldSpeedUp(player);
		dvldGradeUp(player, (nextsec / 100) - 1);
		dvldEndFlag[player] = 1;
		
		// GOD�����𖞂����Ă���ꍇ�͗��ꐯ�o��
		if((dvldGrade[player] == 13) && (gameTimer[player] <= 19200)) {
			objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
		}
	} else if((dvldLevel[player] >= nextsec) && (nextsec == 500) && (gameTimer[player] > dvldTorikan) && (dvldTorikan > 0)) {
		// LV500�Ƃ�J��
		dvldLevel[player] = 500;
		ending[player] = 4;
		timeOn[player] = 0;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		stat[player] = 10;
		dvldGradeUp(player, (nextsec / 100) - 1);
	} else if((dvldLevel[player] >= nextsec) && (nextsec == 1000) && (gameTimer[player] > dvldTorikan * 2) && (dvldTorikan > 0)) {
		// LV1000�Ƃ�J��
		dvldLevel[player] = 1000;
		ending[player] = 4;
		timeOn[player] = 0;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		stat[player] = 10;
		dvldGradeUp(player, (nextsec / 100) - 1);
	} else {
		// ���x���X�g�b�v��
		if(dvldLevel[player] % 100 == 99) PlaySE(se_lvstop);
		
		if(dvldLevel[player] >= nextsec) {
			// ���x���A�b�v��
			PlaySE(se_levelup);
			
			// �w�i�؂�ւ�
			if(dvldLevel[player] < 1000) {
				bgfadesw = 1;
				bgfadebg = nextsec / 100;
			}
			
			dvldGradeUp(player, (nextsec / 100) - 1);
			
			// []�o��
			if(dvldLevel[player] >= 1000) oblk_spawn[player] = 1;
			
			// ����オ��J�E���g�ݒ�
			if((dvldRiseMax[dvldLevel[player] / 100] != 0) && (dvldRiseMin[dvldLevel[player] / 100] != 0)) {
				do {
					dvldRiseCount[player] = GiziRand(player, dvldRiseMax[dvldLevel[player] / 100] + 1);
				} while(dvldRiseCount[player] < dvldRiseMin[dvldLevel[player] / 100]);
			}
		}
		
		// �X�s�[�h�A�b�v
		dvldSpeedUp(player);
	}
	
	// �X�R�A�v�Z
	if(dvldVersion >= 1) {
		temp = wait3[player] - bactivetime[player];
		if(temp < 0) temp = 0;
		
		bo = ((lv + lines) / 4 + (sdrop[player] / 2) + qdrop[player] + qput[player]) * lines * cmbpts[player] + (dvldLevel[player] / 2) + temp;
		bai = 1;
	} else {
		bo = (lv + lines) / 4 + sdrop[player] + qdrop[player] + qput[player];
		bai = (lines * 2 - 1 + cmbpts[player] - (lines * 2 - 2)) * lines;
	}
	
	if(isBravo(player)) {
		// �S��������ƃX�R�A4�{
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		if(dvldVersion <= 0) bai = bai * 4;
		
		// AC���_���l��
		if(dvldMedalStat[player * 4 + 1] < 3) {
			PlaySE(se_medal);
			dvldMedalStat[player * 4 + 1]++;
			dvldMedalAnim[player * 4 + 1] = 0;
		}
	}
	
	// T-SPIN��2�{
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		dvldTSpinFrame[player] = 120;
		if(dvldVersion <= 0) bai = bai * 2;
	}
	
	// �X�R�A���Z
	dvldScore[player] = dvldScore[player] + (bo * bai);
}

// ST���_���l���^�i�ʏ㏸
void dvldGradeUp(int player, int section) {
	// �Z�N�V�����^�C���L�^
	dvldSectionTime[section + player * 13] = dvldSTimer[player];
	
	// ST���_���l��
	if((!playback) && (!dvldIsBig) && (dvldLvUpBonus) && (!dvldStartLevel)) {
		if((dvldSTimer[player] < dvldRankingSectionTime[section]) && (dvldMedalStat[player * 4 + 0] < 3)) {
			PlaySE(se_medal);
			dvldMedalStat[player * 4 + 0] = 3;
			dvldMedalAnim[player * 4 + 0] = 0;
		} else if((dvldSTimer[player] < dvldRankingSectionTime[section] + 300) && (dvldMedalStat[player * 4 + 0] < 2)) {
			PlaySE(se_medal);
			dvldMedalStat[player * 4 + 0] = 2;
			dvldMedalAnim[player * 4 + 0] = 0;
		} else if((dvldSTimer[player] < dvldRankingSectionTime[section] + 600) && (dvldMedalStat[player * 4 + 0] < 1)) {
			PlaySE(se_medal);
			dvldMedalStat[player * 4 + 0] = 1;
			dvldMedalAnim[player * 4 + 0] = 0;
		}
	}
	
	// �i�ʏ㏸
	if(dvldSTimer[player] <= 3690) {
		dvldGrade[player]++;
	} else {
		PlaySE(se_regret);
		dvldRegretFrame[player] = 180;
	}
	
	dvldSTimer[player] = 0;
}

// ���Ԃ�i�߂�
void dvldIncrementTime(int player) {
	int i;
	
	// �Z�N�V�����^�C������
	if(timeOn[player]) dvldSTimer[player]++;
	
	// ���[���I��
	if((ending[player] == 2) && (edrec[player] >= 60 * 60)) {
		// GOD�����B��
		if((dvldGrade[player] == 13) && (gameTimer[player] <= 19200)) {
			dvldGrade[player] = 14;
		}
		ending[player] = 3;
		stat[player] = 10;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
	
	if(dvldRegretFrame[player] > 0)
		dvldRegretFrame[player]--;	// REGRET�\�����Ԍ���
	else if(dvldTSpinFrame[player] > 0)
		dvldTSpinFrame[player]--;	// T-SPIN�\�����Ԍ���
}

// ����オ��
void dvldRiseField(int player) {
	int i;
	
	if(dvldRiseEnable == 0) return;
	
	if((dvldRiseCount[player] <= 0) && (dvldRiseMax[dvldLevel[player] / 100] != 0) && (dvldRiseMin[dvldLevel[player] / 100] != 0)) {
		// �ŉ��i���R�s�[����
		for(i = 0; i < 10; i++) {
			fldu[i + player * 220] = (fld[i + 21 * 10 + player * 220] != 0);
		}
		upLines[player] = 1;
		
		// ����オ��J�E���g�ݒ�
		do {
			dvldRiseCount[player] = GiziRand(player, dvldRiseMax[dvldLevel[player] / 100] + 1);
		} while(dvldRiseCount[player] < dvldRiseMin[dvldLevel[player] / 100]);
	}
}

// �G���f�B���O�˓�
void dvldEndingStart(int player) {
	int i;
	
	for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	
	if(dvldLevel[player] >= 1300) {
		ending[player] = 2;
		stat[player] = 4;
		ending_timeOn[player] = 1;
		
		IsBig[player] = 1;
		BigMove[player] = 1;
		
		bgmlv = dvldBgmListTable[4];
		PlayBGM();
	} else {
		ending[player] = 3;
	}
}

// �G���f�B���O�I��
void dvldExcellent(int player, int *param) {
	onRecord[player] = 0;
	statc[player * 10 + 1]++;
	
	if(dvldGrade[player] >= 14) {
		// GOD
		param[0] = 2;
		dvldEndFlag[player] = 2;
		
		// �ԉ�
		if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 30)) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			statc[player * 10 + 2]++;
		}
	} else if(dvldLevel[player] >= 1300) {
		// ���S�N���A
		printTinyFont(foffset[player] + 22, fyoffset[player] + 116, "DEVIL MODE");
		printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
		dvldEndFlag[player] = 2;
		
		// �ԉ�
		if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 30)) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			statc[player * 10 + 2]++;
		}
	} else {
		// �Ƃ�J��
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
			
			printFont(foffset[player] + 12, fyoffset[player] + 112, "BUT...", 0);
			printFont(foffset[player] + 12, fyoffset[player] + 120, "LET'S GO", 0);
			printFont(foffset[player] + 12, fyoffset[player] + 128, "BETTER", 0);
			printFont(foffset[player] + 12, fyoffset[player] + 136, "NEXT TIME", 0);
			
			// �{�^���ŃX�L�b�v
			if(getPushState(player, 4)) {
				statc[player * 10] = 600;
			}
		}
	}
}

// BGM�ǂݍ���
void dvldLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 5; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/5)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(dvldBgmListTable[i]);
		}
	}
}

// �X�R�A��\��
void dvldViewScore(int player) {
	int i, x, y, color, kind;
	color = (count % 4 / 2) * 7;
	
	// ���_���i�ʏ�j
	for(i = 0; i < 4; i++) {
		if((dvldMedalAnim[player * 4 + i] < 0) || (dvldMedalAnim[player * 4 + i] > 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 17;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			if(i == 0) kind = 1;
			if(i == 1) kind = 0;
			if(i == 2) kind = 5;
			if(i == 3) kind = 2;
			dvldDrawMedal(x, y, kind, dvldMedalStat[player * 4 + i], dvldMedalAnim[player * 4 + i]);
		}
	}
	
	// ���_���i�A�j�����j
	for(i = 0; i < 4; i++) {
		if((dvldMedalAnim[player * 4 + i] >= 0) && (dvldMedalAnim[player * 4 + i] <= 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 17;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			if(i == 0) kind = 1;
			if(i == 1) kind = 0;
			if(i == 2) kind = 5;
			if(i == 3) kind = 2;
			dvldDrawMedal(x, y, kind, dvldMedalStat[player * 4 + i], dvldMedalAnim[player * 4 + i]);
			dvldMedalAnim[player * 4 + i]++;
		}
	}
	
	// ���x���i���q�j
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(dvldLevel[player] == -1) sprintf(string[0], "%4d", 0);	// -1�Ȃ�0�ƕ\������(�����I�ɂ͍ŏ���-1�ɂȂ��Ă���)
	else sprintf(string[0], "%4d", dvldLevel[player]);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// ���x���i�����j
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 0, 143, 22, 1);
	
	// ���x���i����j
	if(ending[player]) sprintf(string[0], "%4d", dvldLevel[player]);
	else sprintf(string[0], "%4d", dvldLevel[player] / 100 * 100 + 100);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, string[0], color);
	
	// �^�C��
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
	
	if(dvldRegretFrame[player] > 0)
		printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "REGRET");	// REGRET�\��
	else if(dvldTSpinFrame[player] > 0)
		printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "T-SPIN");	// T-SPIN�\��
}

// ���_����\��
void dvldDrawMedal(int x, int y, int kind, int color, int anim) {
	int i, j, k;
	
	if(color == 0) return;
	
	if((anim >= 0) && (anim < 16)) {
		if(anim <= 8) {
			k = anim;
			i = (16 * k / 2 - 16) / 2;
			j = (12 * k / 2 - 12) / 2;
			k = 65536 * k / 2;
		} else {
			k = 16 - anim;
			i = (16 * k / 3 - 16) / 2;
			j = (12 * k / 3 - 12) / 2;
			k = 65536 * k / 3;
			
			if(k < 65536) {
				k = 65536;
				i = 0;
				j = 0;
			}
		}
		
		ExBltRectR(sg_medal[1], x - i, y - j, kind * 16, color * 12, 16, 12, k, k);
	} else {
		ExBltRect(sg_medal[1], x, y, kind * 16, color * 12, 16, 12);
	}
}

// ���ʕ\��
void dvldResult(int player, int *param) {
	if(statc[player * 10 + 1] < 300) {
		// �ʏ�̏������X�L�b�v����
		param[0] = 1;
		
		if(statc[player * 10 + 1] == 0) {
			// �u���Ȃ��̒i�ʂ́v�̕���
			ExTextSize(0, 10);
			TextColor(0, 255, 255, 255);
			TextBackColorDisable(0);
			if(!english) {
				TextOut(0, "���Ȃ��̒i�ʂ�");
			} else {
				TextOut(0, "Your Grade is");
			}
			ExTextLayerOn(0, foffset[player] + 13, fyoffset[player] + 92);
			
			// �����L���O�o�^
			statc[player * 10 + 2] = dvldRegistRanking(player);
			statc[player * 10 + 3] = dvldUpdateSectionTimeRanking(player);
			if((statc[player * 10 + 2] != -1) || (statc[player * 10 + 3] != 0)) dvldSaveRanking(player);
			
			// ���i�ʔ���
			statc[player * 10 + 4] = checkSecretGrade(player);
		}
		
		// �i�ʕ\��
		if(dvldGrade[player] == 0)		// 1
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108,   0, ((count % 4 / 2) * 216) + 192, 90, 24);
		else if(dvldGrade[player] < 10)	// S1�`S9
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108,  90, ((count % 4 / 2) * 216) + ((dvldGrade[player] -  1) * 24), 90, 24);
		else if(dvldGrade[player] < 14)	// S10�`S13
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108, 360, ((count % 4 / 2) * 216) + ((dvldGrade[player] - 10) * 24), 90, 24);
		else							// GOD
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108, 360, ((count % 4 / 2) * 216) + 96, 90, 72);
		
		// �{�^���ŃX�L�b�v
		if(getPushState(player, 4) && (statc[player * 10 + 1] >= 60)) {
			statc[player * 10 + 1] = 300;
		}
		
		// �J�E���^����
		statc[player * 10 + 1]++;
		
		// ����������
		if(statc[player * 10 + 1] >= 300) TextLayerOff(0);
	} else {
		// ���ʕ\��
		printSMALLFont(foffset[player] + 21, fyoffset[player] + 45, "PLAY DATA", 4);
		
		printTinyFont(foffset[player] + 8, fyoffset[player] + 59, "SCORE");
		sprintf(string[0], "%13d", dvldScore[player]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 67, string[0], 0);
		
		printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LEVEL");
		sprintf(string[0], "%13d", dvldLevel[player]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
		
		printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "TIME");
		getTime(gameTimer[player]);
		sprintf(string[1], "%13s", string[0]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[1], 0);
		
		if(statc[player * 10 + 2] != -1) {
			printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "RANK");
			sprintf(string[0], "%13d", statc[player * 10 + 2] + 1);
			printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[0], 0);
		}
		
		if(statc[player * 10 + 3] != 0) {
			printTinyFont(foffset[player] + 8, fyoffset[player] + 139, "ST RECORDS");
			sprintf(string[0], "%13d", statc[player * 10 + 3]);
			printSMALLFont(foffset[player] + 10, fyoffset[player] + 147, string[0], 0);
		}
		
		if(statc[player * 10 + 4] >= 4) {
			printTinyFont(foffset[player] + 8, fyoffset[player] + 159, "SECRET GRADE");
			sprintf(string[0], "%13s", dvldStrSecretGradeName[statc[player * 10 + 4]]);
			printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
		}
	}
}

// �ݒ���
void dvldSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(dvldLoadConfig() == 0) dvldSaveConfig();
	
	// �����L���O��ǂݍ���
	if(dvldLoadRanking(player) == 0) dvldInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "DEVIL-DOOM OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "BIG",            7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",       7 * (cursor == 1));
		printFontGrid(2, 5, "LEVEL UP BONUS", 7 * (cursor == 2));
		printFontGrid(2, 6, "T-SPIN",         7 * (cursor == 3));
		printFontGrid(2, 7, "TIME LIMIT",     7 * (cursor == 4));
		printFontGrid(2, 8, "RISE ON/OFF",    7 * (cursor == 5));
		printFontGrid(2, 9, "START LEVEL",    7 * (cursor == 6));
		
		// �ݒ�l�\��
		if(!dvldIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!dvldBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!dvldLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(dvldTSpin == 0) sprintf(string[0], "OFF");
		else if(dvldTSpin == 1) sprintf(string[0], "LINE CLEAR");
		else if(dvldTSpin == 2) sprintf(string[0], "IMMOBILE");
		else if(dvldTSpin == 3) sprintf(string[0], "3-CORNER");
		else sprintf(string[0], "3-CORNER NO KICK");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(!dvldTorikan) sprintf(string[0], "OFF");
		else getTime(dvldTorikan);
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		if(!dvldRiseEnable) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		sprintf(string[0], "%d", dvldStartLevel);
		printFontGrid(22, 9, string[0], 7 * (cursor == 6));
		
		// �J�[�\���ړ�
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 6;
			if(cursor > 6) cursor = 0;
		}
		
		// �l��ύX
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) dvldIsBig = !dvldIsBig;
			if(cursor == 1) dvldBigMove = !dvldBigMove;
			if(cursor == 2) dvldLvUpBonus = !dvldLvUpBonus;
			if(cursor == 3) {
				dvldTSpin = dvldTSpin + move;
				if(dvldTSpin < 0) dvldTSpin = 4;
				if(dvldTSpin > 4) dvldTSpin = 0;
			}
			if(cursor == 4) {
				dvldTorikan = dvldTorikan + (move * 60);
				if(dvldTorikan < 0) dvldTorikan = 72000;
				if(dvldTorikan > 72000) dvldTorikan = 0;
			}
			if(cursor == 5) {
				dvldRiseEnable = !dvldRiseEnable;
			}
			if(cursor == 6) {
				dvldStartLevel = dvldStartLevel + (move * 100);
				if(dvldStartLevel < 0) dvldStartLevel = 1200;
				if(dvldStartLevel > 1200) dvldStartLevel = 0;
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
			dvldSaveConfig();
			return;
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			dvldViewRanking(player);
		}
	}
}

// �ݒ��ۑ�
void dvldSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x49564544;
	saveBuf[3] = 0x3176444C;
	
	// �ݒ���e
	saveBuf[4] = dvldIsBig;
	saveBuf[5] = dvldBigMove;
	saveBuf[6] = dvldLvUpBonus;
	saveBuf[7] = dvldTSpin;
	saveBuf[8] = dvldTorikan;
	saveBuf[9] = dvldRiseEnable;
	saveBuf[10] = dvldStartLevel;
	
	SaveFile("config/DEVIL_DOOM_CONFIG.SAV", &saveBuf, 100 * 4);
}

// �ݒ��ǂݍ���
int dvldLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/DEVIL_DOOM_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x49564544) return 0;
	if(saveBuf[3] != 0x3176444C) return 0;
	
	// �ݒ���e
	dvldIsBig = saveBuf[4];
	dvldBigMove = saveBuf[5];
	dvldLvUpBonus = saveBuf[6];
	dvldTSpin = saveBuf[7];
	dvldTorikan = saveBuf[8];
	dvldRiseEnable = saveBuf[9];
	dvldStartLevel = saveBuf[10];
	
	return 1;
}

// ���v���C�ۑ�
void dvldSaveReplay(int player) {
	saveBuf[900] = dvldIsBig;
	saveBuf[901] = dvldBigMove;
	saveBuf[902] = dvldLvUpBonus;
	saveBuf[903] = dvldTSpin;
	saveBuf[904] = dvldTorikan;
	saveBuf[905] = dvldRiseEnable;
	saveBuf[906] = dvldLevel[player];
	saveBuf[907] = dvldScore[player];
	saveBuf[908] = dvldGrade[player];
	saveBuf[909] = dvldVersion;
	saveBuf[910] = dvldStartLevel;
}

// ���v���C�ǂݍ���
void dvldLoadReplay(int player) {
	dvldIsBig = saveBuf[900];
	dvldBigMove = saveBuf[901];
	dvldLvUpBonus = saveBuf[902];
	dvldTSpin = saveBuf[903];
	dvldTorikan = saveBuf[904];
	dvldRiseEnable = saveBuf[905];
	dvldVersion = saveBuf[909];
	dvldStartLevel = saveBuf[910];
}

// ���v���C�ڍ�
void dvldReplayDetail(int number) {
	printFontGrid(1, 5, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[907]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[906]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "GRADE", 0);
	if((saveBuf[908] >= 0) && (saveBuf[908] <= 14)) {
		printFontGrid(22, 7, dvldStrGradeName[saveBuf[908]], 0);
	} else {
		printFontGrid(22, 7, "???", 0);
	}
	
	printFontGrid(1, 9, "BIG", 0);
	if(!saveBuf[900]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "BIG MOVE", 0);
	if(!saveBuf[901]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "LEVEL UP BONUS", 0);
	if(!saveBuf[902]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "T-SPIN", 0);
	if(saveBuf[903] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[903] == 1) sprintf(string[0], "LINE CLEAR");
	else if(saveBuf[903] == 2) sprintf(string[0], "IMMOBILE");
	else if(saveBuf[903] == 3) sprintf(string[0], "3-CORNER");
	else sprintf(string[0], "3-CORNER NO KICK");
	printFontGrid(22, 12, string[0], 0);
	
	printFontGrid(1, 13, "TIME LIMIT", 0);
	if(!saveBuf[904]) sprintf(string[0], "OFF");
	else getTime(saveBuf[904]);
	printFontGrid(22, 13, string[0], 0);
	
	printFontGrid(1, 14, "RISE ON/OFF", 0);
	if(!saveBuf[905]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 14, string[0], 0);
	
	if(saveBuf[909] >= 3) {
		printFontGrid(1, 15, "START LEVEL", 0);
		sprintf(string[0], "%d", saveBuf[910]);
		printFontGrid(22, 15, string[0], 0);
	}
	
	printFontGrid(1, 16, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[909]);
	printFontGrid(22, 16, string[0], 0);
}

// �����L���O�ۑ�
void dvldSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �m�[�}�������L���O
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0]  = dvldRankingGrade[i];
		saveBuf[1 + (i * 20) + 1]  = dvldRankingLevel[i];
		saveBuf[1 + (i * 20) + 2]  = dvldRankingTime[i];
		saveBuf[1 + (i * 20) + 3]  = dvldRankingEnd[i];
		saveBuf[1 + (i * 20) + 4]  = dvldRankingMedal[i * 4 + 0];
		saveBuf[1 + (i * 20) + 5]  = dvldRankingMedal[i * 4 + 1];
		saveBuf[1 + (i * 20) + 6]  = dvldRankingMedal[i * 4 + 2];
		saveBuf[1 + (i * 20) + 7]  = dvldRankingMedal[i * 4 + 3];
		saveBuf[1 + (i * 20) + 8]  = dvldRankingYear[i];
		saveBuf[1 + (i * 20) + 9]  = dvldRankingMonth[i];
		saveBuf[1 + (i * 20) + 10] = dvldRankingDay[i];
		saveBuf[1 + (i * 20) + 11] = dvldRankingHour[i];
		saveBuf[1 + (i * 20) + 12] = dvldRankingMinute[i];
		saveBuf[1 + (i * 20) + 13] = dvldRankingSecond[i];
	}
	
	// �Z�N�V�����^�C�������L���O
	for(i = 0; i < 13; i++) {
		saveBuf[221 + (i * 10) + 0] = dvldRankingSectionTime[i];
		saveBuf[221 + (i * 10) + 1] = dvldRankingSectionEnd[i];
		saveBuf[221 + (i * 10) + 2] = dvldRankingSectionYear[i];
		saveBuf[221 + (i * 10) + 3] = dvldRankingSectionMonth[i];
		saveBuf[221 + (i * 10) + 4] = dvldRankingSectionDay[i];
		saveBuf[221 + (i * 10) + 5] = dvldRankingSectionHour[i];
		saveBuf[221 + (i * 10) + 6] = dvldRankingSectionMinute[i];
		saveBuf[221 + (i * 10) + 7] = dvldRankingSectionSecond[i];
	}
	
	sprintf(string[0], "config/DEVIL_DOOM_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 361 * 4);
}

// �����L���O�ǂݍ���
int dvldLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/DEVIL_DOOM_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 361 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �m�[�}�������L���O
	for(i = 0; i < 10; i++) {
		dvldRankingGrade[i]         = saveBuf[1 + (i * 20) + 0];
		dvldRankingLevel[i]         = saveBuf[1 + (i * 20) + 1];
		dvldRankingTime[i]          = saveBuf[1 + (i * 20) + 2];
		dvldRankingEnd[i]           = saveBuf[1 + (i * 20) + 3];
		dvldRankingMedal[i * 4 + 0] = saveBuf[1 + (i * 20) + 4];
		dvldRankingMedal[i * 4 + 1] = saveBuf[1 + (i * 20) + 5];
		dvldRankingMedal[i * 4 + 2] = saveBuf[1 + (i * 20) + 6];
		dvldRankingMedal[i * 4 + 3] = saveBuf[1 + (i * 20) + 7];
		dvldRankingYear[i]          = saveBuf[1 + (i * 20) + 8];
		dvldRankingMonth[i]         = saveBuf[1 + (i * 20) + 9];
		dvldRankingDay[i]           = saveBuf[1 + (i * 20) + 10];
		dvldRankingHour[i]          = saveBuf[1 + (i * 20) + 11];
		dvldRankingMinute[i]        = saveBuf[1 + (i * 20) + 12];
		dvldRankingSecond[i]        = saveBuf[1 + (i * 20) + 13];
	}
	
	// �Z�N�V�����^�C�������L���O
	for(i = 0; i < 13; i++) {
		dvldRankingSectionTime[i]   = saveBuf[221 + (i * 10) + 0];
		dvldRankingSectionEnd[i]    = saveBuf[221 + (i * 10) + 1];
		dvldRankingSectionYear[i]   = saveBuf[221 + (i * 10) + 2];
		dvldRankingSectionMonth[i]  = saveBuf[221 + (i * 10) + 3];
		dvldRankingSectionDay[i]    = saveBuf[221 + (i * 10) + 4];
		dvldRankingSectionHour[i]   = saveBuf[221 + (i * 10) + 5];
		dvldRankingSectionMinute[i] = saveBuf[221 + (i * 10) + 6];
		dvldRankingSectionSecond[i] = saveBuf[221 + (i * 10) + 7];
	}
	
	return 1;
}

// �����L���O������
void dvldInitRanking() {
	int i;
	
	// �m�[�}�������L���O
	for(i = 0; i < 10; i++) {
		dvldRankingGrade[i]         = 0;
		dvldRankingLevel[i]         = 0;
		dvldRankingTime[i]          = 0;
		dvldRankingEnd[i]           = 0;
		dvldRankingMedal[i * 4 + 0] = 0;
		dvldRankingMedal[i * 4 + 1] = 0;
		dvldRankingMedal[i * 4 + 2] = 0;
		dvldRankingMedal[i * 4 + 3] = 0;
		dvldRankingYear[i]          = 0;
		dvldRankingMonth[i]         = 0;
		dvldRankingDay[i]           = 0;
		dvldRankingHour[i]          = 0;
		dvldRankingMinute[i]        = 0;
		dvldRankingSecond[i]        = 0;
	}
	
	// �Z�N�V�����^�C�������L���O
	for(i = 0; i < 13; i++) {
		dvldRankingSectionTime[i]   = 5400;
		dvldRankingSectionEnd[i]    = 0;
		dvldRankingSectionYear[i]   = 0;
		dvldRankingSectionMonth[i]  = 0;
		dvldRankingSectionDay[i]    = 0;
		dvldRankingSectionHour[i]   = 0;
		dvldRankingSectionMinute[i] = 0;
		dvldRankingSectionSecond[i] = 0;
	}
}

// �����L���O�o�^
int dvldRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (dvldIsBig) || (!dvldLvUpBonus) || (dvldStartLevel)) return -1;
	
	for(i = 0; i < 10; i++) {
		// �����N�C��
		if(
		    (dvldEndFlag[player] > dvldRankingEnd[i]) || 
		    ((dvldEndFlag[player] == dvldRankingEnd[i]) && (dvldGrade[player] > dvldRankingGrade[i])) || 
		    ((dvldEndFlag[player] == dvldRankingEnd[i]) && (dvldGrade[player] == dvldRankingGrade[i]) && (gameTimer[player] < dvldRankingTime[i]))
		  )
		{
			// �����L���O�����炷
			for(j = 9; j > i; j--) {
				dvldRankingGrade[j]         = dvldRankingGrade[j - 1];
				dvldRankingLevel[j]         = dvldRankingLevel[j - 1];
				dvldRankingTime[j]          = dvldRankingTime[j - 1];
				dvldRankingEnd[j]           = dvldRankingEnd[j - 1];
				dvldRankingMedal[j * 4 + 0] = dvldRankingMedal[(j - 1) * 4 + 0];
				dvldRankingMedal[j * 4 + 1] = dvldRankingMedal[(j - 1) * 4 + 1];
				dvldRankingMedal[j * 4 + 2] = dvldRankingMedal[(j - 1) * 4 + 2];
				dvldRankingMedal[j * 4 + 3] = dvldRankingMedal[(j - 1) * 4 + 3];
				dvldRankingYear[j]          = dvldRankingYear[j - 1];
				dvldRankingMonth[j]         = dvldRankingMonth[j - 1];
				dvldRankingDay[j]           = dvldRankingDay[j - 1];
				dvldRankingHour[j]          = dvldRankingHour[j - 1];
				dvldRankingMinute[j]        = dvldRankingMinute[j - 1];
				dvldRankingSecond[j]        = dvldRankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			dvldRankingGrade[i]         = dvldGrade[player];
			dvldRankingLevel[i]         = dvldLevel[player];
			dvldRankingTime[i]          = gameTimer[player];
			dvldRankingEnd[i]           = dvldEndFlag[player];
			dvldRankingMedal[i * 4 + 0] = dvldMedalStat[player * 4 + 0];
			dvldRankingMedal[i * 4 + 1] = dvldMedalStat[player * 4 + 1];
			dvldRankingMedal[i * 4 + 2] = dvldMedalStat[player * 4 + 2];
			dvldRankingMedal[i * 4 + 3] = dvldMedalStat[player * 4 + 3];
			
			GetDateAndTime(&timebuf);
			dvldRankingYear[i]          = timebuf[0];
			dvldRankingMonth[i]         = timebuf[1];
			dvldRankingDay[i]           = timebuf[2];
			dvldRankingHour[i]          = timebuf[4];
			dvldRankingMinute[i]        = timebuf[5];
			dvldRankingSecond[i]        = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �Z�N�V�����^�C�������L���O�X�V
int dvldUpdateSectionTimeRanking(int player) {
	int i, timebuf[8], result;
	result = 0;
	
	if((playback) || (dvldIsBig) || (!dvldLvUpBonus) || (dvldStartLevel)) return 0;
	
	for(i = 0; i < 13; i++) {
		if((dvldSectionTime[i + player * 13] < dvldRankingSectionTime[i]) && (dvldSectionTime[i + player * 13] != 0)) {
			result++;
			
			dvldRankingSectionTime[i] = dvldSectionTime[i + player * 13];
			dvldRankingSectionEnd[i] = dvldEndFlag[player];
			
			GetDateAndTime(&timebuf);
			dvldRankingSectionYear[i] = timebuf[0];
			dvldRankingSectionMonth[i] = timebuf[1];
			dvldRankingSectionDay[i] = timebuf[2];
			dvldRankingSectionHour[i] = timebuf[4];
			dvldRankingSectionMinute[i] = timebuf[5];
			dvldRankingSectionSecond[i] = timebuf[6];
		}
	}
	
	return result;
}

// �����L���O�\��
void dvldViewRanking(int player) {
	int i, cursor, move, erasemode, stmode, temp;
	cursor = 0;
	move = 0;
	erasemode = 0;
	stmode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		if(!stmode) {
			// �m�[�}�������L���O
			printFontGrid(1, 1, "DEVIL-DOOM MODE RANKING >>", 6);
			printFontGrid(1, 3, "RANK GRADE LEVEL TIME", 4);
			
			for(i = 0; i < 10; i++) {
				if(dvldRankingEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (dvldRankingEnd[i] - 1) * 2, 320, 2);
				
				if(i == 0) sprintf(string[0], " 1ST");
				if(i == 1) sprintf(string[0], " 2ND");
				if(i == 2) sprintf(string[0], " 3RD");
				if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
				printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
				
				if((dvldRankingGrade[i] >= 0) && (dvldRankingGrade[i] <= 14)) {
					printFontGrid(6, 4 + i, dvldStrGradeName[dvldRankingGrade[i]], 7 * (cursor == i));
				} else {
					printFontGrid(6, 4 + i, "???", 7 * (cursor == i));
				}
				
				sprintf(string[0], "%d", dvldRankingLevel[i]);
				printFontGrid(12, 4 + i, string[0], 7 * (cursor == i));
				
				getTime(dvldRankingTime[i]);
				printFontGrid(18, 4 + i, string[0], 7 * (cursor == i));
			}
			
			for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
			
			if(!erasemode) {
				// ���_��
				dvldDrawMedal(8 + 0 * 16, 192, 1, dvldRankingMedal[cursor * 4 + 0], -1);
				dvldDrawMedal(8 + 1 * 16, 192, 0, dvldRankingMedal[cursor * 4 + 1], -1);
				dvldDrawMedal(8 + 2 * 16, 192, 5, dvldRankingMedal[cursor * 4 + 2], -1);
				dvldDrawMedal(8 + 3 * 16, 192, 2, dvldRankingMedal[cursor * 4 + 3], -1);
				
				// ���t�Ǝ���
				sprintf(string[0],
				        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
				        dvldRankingYear[cursor], dvldRankingMonth[cursor], dvldRankingDay[cursor],
				        dvldRankingHour[cursor], dvldRankingMinute[cursor], dvldRankingSecond[cursor]);
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
				
				// �����L���O�؂�ւ�
				if(getPushState(player, 2) || getPushState(player, 3)) {
					PlaySE(se_move);
					stmode = !stmode;
				}
			} else {
				printFontGrid(1, 24, "ERASE ALL RECORDS?", 2);
				printFontGrid(1, 26, "A:YES / B:NO", 2);
				
				// ����
				if(getPushState(player, 4)) {
					PlayWave(se_kettei);
					dvldInitRanking();
					dvldSaveRanking(player);
					erasemode = 0;
				}
				
				// �߂�
				if(getPushState(player, 5)) {
					PlaySE(se_move);
					erasemode = 0;
				}
			}
		} else {
			// �Z�N�V�����^�C�������L���O
			printFontGrid(1, 1, "<< DEVIL-DOOM MODE SECTION TIME", 6);
			printFontGrid(1, 3, "SECTION   TIME     DATE", 4);
			printFontGrid(1, 28, "A/B:EXIT", 6);
			
			for(i = 0; i < 13; i++) {
				if(dvldRankingSectionEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (dvldRankingSectionEnd[i] - 1) * 2, 320, 2);
				
				sprintf(string[0], "%4d-%4d", i * 100, ((i + 1) * 100) - 1);
				printFontGrid(1, 4 + i, string[0], 0);
				
				getTime(dvldRankingSectionTime[i]);
				printFontGrid(11, 4 + i, string[0], 0);
				
				temp = (dvldRankingSectionYear[i] / 1000) * 1000;	// �N����2�������\��
				if(temp == 0) temp = 1;
				sprintf(string[0], "%02d/%02d/%02d", dvldRankingSectionYear[i] % temp, dvldRankingSectionMonth[i], dvldRankingSectionDay[i]);
				printFontGrid(20, 4 + i, string[0], 0);
				
				sprintf(string[0], "%02d:%02d:%02d", dvldRankingSectionHour[i], dvldRankingSectionMinute[i], dvldRankingSectionSecond[i]);
				printFontGrid(29, 4 + i, string[0], 0);
			}
			
			// �߂�
			if(getPushState(player, 4) || getPushState(player, 5)) {
				PlaySE(se_move);
				return;
			}
			
			// �����L���O�؂�ւ�
			if(getPushState(player, 2) || getPushState(player, 3)) {
				PlaySE(se_move);
				stmode = !stmode;
			}
		}
	}
}
