//DEVIL-QUAKE
//prefix:dvlq

// �o�[�W����
int dvlqVersion;			// �o�[�W�����ԍ��i�Â����v���C�Đ��p�j
int dvlqCVersion = 1;		// ���݂̃o�[�W����

// ���x���A�b�v�e�[�u��    000, 100, 200, 300, 400, 500, 600, 700, 800, 900,1000,1100,1200,1300
int dvlqWait1Table[14] = {  10,  10,  10,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4};	// �ڒ���iARE�j
int dvlqWait2Table[14] = {   6,   5,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   6};	// ����
int dvlqWait3Table[14] = {  18,  18,  17,  15,  15,  13,  12,  12,  12,  12,  12,  10,   8,  15};	// �ڒ�
int dvlqWait5Table[14] = {   6,   5,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   4};	// ������iARE2�j
int dvlqWaittTable[14] = {   8,   6,   6,   6,   6,   4,   4,   4,   4,   4,   4,   4,   4,   6};	// ����

// �����x���A�b�v�e�[�u��     000, 100, 200, 300, 400, 500, 600, 700, 800, 900,1000,1100,1200,1300
int dvlqWait1TableOld[14] = {   6,   5,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   4};	// ������iARE�j
int dvlqWait2TableOld[14] = {   6,   5,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   6};	// ����
int dvlqWait3TableOld[14] = {  18,  18,  17,  15,  15,  13,  12,  12,  12,  12,  12,  10,   8,  15};	// �ڒ�
int dvlqWait4TableOld[14] = {  24,  24,  23,  21,  21,  19,  18,  18,  18,  18,  18,  16,   8,  21};	// �ڒ���
int dvlqWaittTableOld[14] = {   8,   6,   6,   6,   6,   4,   4,   4,   4,   4,   4,   4,   4,   6};	// ����

// ����オ��Ԋu        000, 100, 200, 300, 400, 500, 600, 700, 800, 900,1000,1100,1200,1300
int dvlqRiseTable[14] = {  0,   0,   0,   0,   0,  20,  18,  10,   9,   8,   0,   0,   0,   0};

// REGRET��^�C��         000, 100, 200, 300, 400, 500, 600, 700, 800, 900,1000,1100,1200
int dvlqRegretTable[13] = {3600,3600,3000,3000,3000,3000,3000,3000,3000,3000,3000,3000,3000};

// BGM
int dvlqBgmListTable[5]   = {2, 3, 4, 5, 6};			// �g�p����BGM
int dvlqBgmFadeTable[4]   = {485, 685, 985, 10000};		// �t�F�[�h�A�E�g���郌�x��
int dvlqBgmChangeTable[4] = {500, 700, 1000, 10000};	// �؂�ւ��郌�x��
int dvlqBgmIndex          = 0;							// ���݂�BGM�ԍ�

// �i�ʂ̕\����
str dvlqStrGradeName[15] = 
{
	"1", "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13", "GOD"
};

// ���i�ʂ̕\����
str dvlqStrSecretGradeName[19] = 
{
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  0�` 8
	"M1", "M2", "M3", "M4", "M5", "M6", "M7", "M8", "M9",	//  9�`17
	"GM"													// 18
};

// �ϐ�
int dvlqModeNo = -1;		// ���[�h�ԍ�

int dvlqLevel[2];			// ���x��
int dvlqScore[2];			// �X�R�A
int dvlqGrade[2];			// �i��
int dvlqEndFlag[2];			// �N���A�t���O

int dvlqRiseCount[2];		// ����オ��p�J�E���^

int dvlqSTimer[2];			// �Z�N�V�����^�C�}�[
int dvlqSkill[2];			// �w�{���X��

int dvlqSectionTime[13 * 2];	// ���̃v���C�̃Z�N�V�����^�C��

int dvlqMedalStat[4 * 2];	// ���_���̏��(0=�Ȃ� 1=�� 2=�� 3=��)
int dvlqMedalAnim[4 * 2];	// ���_���l���A�j���[�V�����p�J�E���^

int dvlqTSpinFrame[2];		// T-SPIN�\���̎c�莞��
int dvlqRegretFrame[2];		// REGRET�\���̎c�莞��

int dvlqIsBig = 0;			// BIG���ǂ���
int dvlqBigMove = 1;		// BIG���̉��ړ��P��
int dvlqLvUpBonus = 1;		// ���x���A�b�v�{�[�i�X
int dvlqTSpin = 1;			// T-SPIN�̎��
int dvlqTorikan = 10980;	// LV500�Ƃ�J����^�C�� (3:03:00)
int dvlqRiseEnable = 1;		// ����オ��ONOFF
int dvlqStartLevel = 0;		// �X�^�[�g���̃��x��

// �����L���O�ϐ�
int dvlqRankingGrade[10];			// �i��
int dvlqRankingLevel[10];			// ���x��
int dvlqRankingTime[10];			// �^�C��
int dvlqRankingEnd[10];				// �N���A�t���O
int dvlqRankingMedal[4 * 10];		// ���_��
int dvlqRankingYear[10];			// �����N�C�������i�N�j
int dvlqRankingMonth[10];			// �����N�C�������i���j
int dvlqRankingDay[10];				// �����N�C�������i���j
int dvlqRankingHour[10];			// �����N�C�������i���j
int dvlqRankingMinute[10];			// �����N�C�������i���j
int dvlqRankingSecond[10];			// �����N�C�������i�b�j

// �Z�N�V�����^�C�������L���O�ϐ�
int dvlqRankingSectionTime[13];		// �^�C��
int dvlqRankingSectionEnd[13];		// �N���A�t���O
int dvlqRankingSectionYear[13];		// �����N�C�������i�N�j
int dvlqRankingSectionMonth[13];	// �����N�C�������i���j
int dvlqRankingSectionDay[13];		// �����N�C�������i���j
int dvlqRankingSectionHour[13];		// �����N�C�������i���j
int dvlqRankingSectionMinute[13];	// �����N�C�������i���j
int dvlqRankingSectionSecond[13];	// �����N�C�������i�b�j

// �C�x���g����
void dvlqPluginEvent(int player, int event, int *param) {
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != dvlqModeNo)) return;
	
	if(event == 0) {
		dvlqModeNo = addModePlugin("DEVIL-QUAKE");	// ���[�h��o�^����
	} else if(event == 7) {
		if(!ending[player]) dvlqMoveInit(player);	// �u���b�N�o��
	} else if(event == 10) {
		dvlqRiseField(player);	// ����オ��
	} else if(event == 12) {
		if(!ending[player]) dvlqCalcScore(player, param[0]);	// �X�R�A�v�Z
	} else if(event == 15) {
		dvlqViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		dvlqSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		dvlqPlayerInitial(player);	// ����������
	} else if(event == 21) {
		dvlqResult(player, param);	// ���ʕ\��
	} else if(event == 24) {
		dvlqEndingStart(player);	// �G���f�B���O�˓�
	} else if(event == 25) {
		dvlqExcellent(player, param);	// �G���f�B���O�I��
	} else if(event == 28) {
		dvlqIncrementTime(player);	// ���Ԃ�i�߂�
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		dvlqSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		dvlqLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		dvlqLoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		dvlqReplayDetail(param[0]);	// ���v���C�ڍ�
	}
}

// ����������
void dvlqPlayerInitial(int player) {
	int i;
	
	// �o�[�W�����ݒ�
	if(!playback) dvlqVersion = dvlqCVersion;
	
	// �ϐ���������
	if(dvlqStartLevel > 0) {
		dvlqLevel[player] = dvlqStartLevel;
		
		if(dvlqLevel[player] >= 1000) oblk_spawn[player] = 1;
		
		backno = dvlqLevel[player] / 100;
		if(backno > 9) backno = 9;
	} else {
		dvlqLevel[player] = -1;
	}
	
	dvlqScore[player] = 0;
	dvlqGrade[player] = 0;
	dvlqEndFlag[player] = 0;
	dvlqRiseCount[player] = 0;
	dvlqSTimer[player] = 0;
	dvlqSkill[player] = 0;
	dvlqTSpinFrame[player] = 0;
	dvlqRegretFrame[player] = 0;
	
	for(i = 0; i < 4; i++) {
		dvlqMedalStat[player * 4 + i] = 0;
		dvlqMedalAnim[player * 4 + i] = -1;
	}
	
	for(i = 0; i < 13; i++) dvlqSectionTime[i + player * 13] = 0;
	
	dvlqBgmIndex = 0;
	bgmlv = dvlqBgmListTable[0];
	framecolor[player] = 2;
	enable_combo[player] = 1;
	
	// �ݒ�𔽉f������
	IsBig[player] = dvlqIsBig;
	BigMove[player] = dvlqBigMove;
	tspin_type[player] = dvlqTSpin;
	
	// �����X�s�[�h��ݒ�
	dvlqSpeedUp(player);
}

// �X�s�[�h�A�b�v
void dvlqSpeedUp(int player) {
	int temp, index;
	
	// 20G
	sp[player] = 1200;
	
	// �X�s�[�h��ς���
	index = dvlqLevel[player] / 100;
	if(index < 0) index = 0;
	if(index > 13) index = 13;
	
	if(dvlqVersion >= 1) {
		wait1[player] = dvlqWait1Table[index];
		wait2[player] = dvlqWait2Table[index];
		wait3[player] = dvlqWait3Table[index];
		wait5[player] = dvlqWait5Table[index];
		waitt[player] = dvlqWaittTable[index];
	} else {
		wait1[player] = dvlqWait1TableOld[index];
		wait2[player] = dvlqWait2TableOld[index];
		wait3[player] = dvlqWait3TableOld[index];
		wait4[player] = dvlqWait4TableOld[index];
		waitt[player] = dvlqWaittTableOld[index];
	}
	
	// BGM�t�F�[�h�A�E�g
	if((dvlqLevel[player] >= dvlqBgmFadeTable[dvlqBgmIndex]) && (dvlqLevel[player] < dvlqBgmChangeTable[dvlqBgmIndex]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// BGM�؂�ւ�
	temp = 0;
	while(dvlqLevel[player] >= dvlqBgmChangeTable[dvlqBgmIndex]) {
		dvlqBgmIndex++;
		bgmlv = dvlqBgmListTable[dvlqBgmIndex];
		if(onRecord[player]) temp = 1;
	}
	if(temp) PlayBGM();
}

// �u���b�N�o��
void dvlqMoveInit(int player) {
	// �ŏ��̃t���[���Ȃ�
	if(statc[player * 10 + 3] == 0) {
		// ���x���A�b�v����
		if(dvlqLevel[player] % 100 != 99) {
			dvlqLevel[player]++;
			if(dvlqLevel[player] % 100 == 99) PlaySE(se_lvstop);
			dvlqSpeedUp(player);
		}
		
		// ����オ��J�E���^
		if(dvlqRiseTable[dvlqLevel[player] / 100] != 0) dvlqRiseCount[player]++;
	}
}

// �X�R�A�v�Z
void dvlqCalcScore(int player, int lines) {
	int i, temp, bo, bai, nextsec, lv;
	
	lv = dvlqLevel[player];	// �オ��O�̃��x��
	
	// ����オ��J�E���^����
	if(dvlqRiseTable[dvlqLevel[player] / 100] != 0) dvlqRiseCount[player] = dvlqRiseCount[player] - lines;
	
	// �w�{���X�񐔑���
	if(lines >= 4) {
		dvlqSkill[player]++;
		
		// SK���_���l��
		if((dvlqSkill[player] == 5) || (dvlqSkill[player] == 10) || (dvlqSkill[player] == 17)) {
			PlaySE(se_medal);
			dvlqMedalStat[player * 4 + 3]++;
			dvlqMedalAnim[player * 4 + 3] = 0;
		}
	}
	
	// CO���_���l��
	if(combo2[player] == 4) {
		if(dvlqMedalStat[player * 4 + 2] < 1) {
			PlaySE(se_medal);
			dvlqMedalStat[player * 4 + 2] = 1;
			dvlqMedalAnim[player * 4 + 2] = 0;
		}
	} else if(combo2[player] == 5) {
		if(dvlqMedalStat[player * 4 + 2] < 2) {
			PlaySE(se_medal);
			dvlqMedalStat[player * 4 + 2] = 2;
			dvlqMedalAnim[player * 4 + 2] = 0;
		}
	} else if(combo2[player] == 7) {
		if(dvlqMedalStat[player * 4 + 2] < 3) {
			PlaySE(se_medal);
			dvlqMedalStat[player * 4 + 2] = 3;
			dvlqMedalAnim[player * 4 + 2] = 0;
		}
	}
	
	// ���x���A�b�v
	nextsec = dvlqLevel[player] / 100 * 100 + 100;
	if(!dvlqLvUpBonus) dvlqLevel[player] = dvlqLevel[player] + lines;
	else dvlqLevel[player] = dvlqLevel[player] + lines + ((lines >= 3) * (lines - 2));
	
	if(dvlqLevel[player] >= 1300) {
		// �G���f�B���O
		dvlqLevel[player] = 1300;
		ending[player] = 1;
		timeOn[player] = 0;
		dvlqSpeedUp(player);
		dvlqGradeUp(player, (nextsec / 100) - 1);
		dvlqEndFlag[player] = 1;
		
		// GOD�����𖞂����Ă���ꍇ�͗��ꐯ�o��
		if((dvlqGrade[player] == 13) && (gameTimer[player] <= 19200)) {
			objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
		}
	} else if((dvlqLevel[player] >= nextsec) && (nextsec == 500) && (gameTimer[player] > dvlqTorikan) && (dvlqTorikan > 0)) {
		// LV500�Ƃ�J��
		dvlqLevel[player] = 500;
		ending[player] = 4;
		timeOn[player] = 0;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		stat[player] = 10;
		dvlqGradeUp(player, (nextsec / 100) - 1);
	} else if((dvlqLevel[player] >= nextsec) && (nextsec == 1000) && (gameTimer[player] > dvlqTorikan * 2) && (dvlqTorikan > 0)) {
		// LV1000�Ƃ�J��
		dvlqLevel[player] = 1000;
		ending[player] = 4;
		timeOn[player] = 0;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		stat[player] = 10;
		dvlqGradeUp(player, (nextsec / 100) - 1);
	} else {
		// ���x���X�g�b�v��
		if(dvlqLevel[player] % 100 == 99) PlaySE(se_lvstop);
		
		if(dvlqLevel[player] >= nextsec) {
			// ���x���A�b�v��
			PlaySE(se_levelup);
			
			// �w�i�؂�ւ�
			if(dvlqLevel[player] < 1000) {
				bgfadesw = 1;
				bgfadebg = nextsec / 100;
			}
			
			dvlqGradeUp(player, (nextsec / 100) - 1);
			
			// []�o��
			if(dvlqLevel[player] >= 1000) oblk_spawn[player] = 1;
		}
		
		// �X�s�[�h�A�b�v
		dvlqSpeedUp(player);
	}
	
	// �X�R�A�v�Z
	temp = wait3[player] - bactivetime[player];
	if(temp < 0) temp = 0;
	
	bo = ((lv + lines) / 4 + (sdrop[player] / 2) + qdrop[player] + qput[player]) * lines * cmbpts[player] + (dvlqLevel[player] / 2) + temp;
	bai = 1;
	
	if(isBravo(player)) {
		// �S����
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		
		// AC���_���l��
		if(dvlqMedalStat[player * 4 + 1] < 3) {
			PlaySE(se_medal);
			dvlqMedalStat[player * 4 + 1]++;
			dvlqMedalAnim[player * 4 + 1] = 0;
		}
	}
	
	// T-SPIN
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		dvlqTSpinFrame[player] = 120;
	}
	
	// �X�R�A���Z
	dvlqScore[player] = dvlqScore[player] + (bo * bai);
}

// ST���_���l���^�i�ʏ㏸
void dvlqGradeUp(int player, int section) {
	// �Z�N�V�����^�C���L�^
	dvlqSectionTime[section + player * 13] = dvlqSTimer[player];
	
	// ST���_���l��
	if((!playback) && (!dvlqIsBig) && (dvlqLvUpBonus) && (!dvlqStartLevel)) {
		if((dvlqSTimer[player] < dvlqRankingSectionTime[section]) && (dvlqMedalStat[player * 4 + 0] < 3)) {
			PlaySE(se_medal);
			dvlqMedalStat[player * 4 + 0] = 3;
			dvlqMedalAnim[player * 4 + 0] = 0;
		} else if((dvlqSTimer[player] < dvlqRankingSectionTime[section] + 300) && (dvlqMedalStat[player * 4 + 0] < 2)) {
			PlaySE(se_medal);
			dvlqMedalStat[player * 4 + 0] = 2;
			dvlqMedalAnim[player * 4 + 0] = 0;
		} else if((dvlqSTimer[player] < dvlqRankingSectionTime[section] + 600) && (dvlqMedalStat[player * 4 + 0] < 1)) {
			PlaySE(se_medal);
			dvlqMedalStat[player * 4 + 0] = 1;
			dvlqMedalAnim[player * 4 + 0] = 0;
		}
	}
	
	// �i�ʏ㏸
	if(dvlqSTimer[player] <= dvlqRegretTable[section]) {
		dvlqGrade[player]++;
	} else {
		PlaySE(se_regret);
		dvlqRegretFrame[player] = 180;
	}
	
	dvlqSTimer[player] = 0;
}

// ���Ԃ�i�߂�
void dvlqIncrementTime(int player) {
	int i;
	
	// �Z�N�V�����^�C������
	if(timeOn[player]) dvlqSTimer[player]++;
	
	// ���[���I��
	if((ending[player] == 2) && (edrec[player] >= 3238)) {
		// GOD�����B��
		if((dvlqGrade[player] == 13) && (gameTimer[player] <= 19200)) {
			dvlqGrade[player] = 14;
		}
		ending[player] = 3;
		stat[player] = 10;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
	
	if(dvlqRegretFrame[player] > 0)
		dvlqRegretFrame[player]--;	// REGRET�\�����Ԍ���
	else if(dvlqTSpinFrame[player] > 0)
		dvlqTSpinFrame[player]--;	// T-SPIN�\�����Ԍ���
}

// ����オ��
void dvlqRiseField(int player) {
	int i;
	
	if(dvlqRiseEnable == 0) return;
	
	if((dvlqRiseCount[player] >= dvlqRiseTable[dvlqLevel[player] / 100]) && (dvlqRiseTable[dvlqLevel[player] / 100] != 0)) {
		// �ŉ��i���R�s�[����
		for(i = 0; i < 10; i++) {
			fldu[i + player * 220] = (fld[i + 21 * 10 + player * 220] != 0);
		}
		upLines[player] = 1;
		
		// ����オ��J�E���g���Z�b�g
		dvlqRiseCount[player] = 0;
	}
}

// �G���f�B���O�˓�
void dvlqEndingStart(int player) {
	int i;
	
	for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	
	if(dvlqLevel[player] >= 1300) {
		ending[player] = 2;
		stat[player] = 4;
		ending_timeOn[player] = 1;
		
		IsBig[player] = 1;
		BigMove[player] = 1;
		
		bgmlv = dvlqBgmListTable[4];
		PlayBGM();
	} else {
		ending[player] = 3;
	}
}

// �G���f�B���O�I��
void dvlqExcellent(int player, int *param) {
	onRecord[player] = 0;
	statc[player * 10 + 1]++;
	
	if(dvlqGrade[player] >= 14) {
		// GOD
		param[0] = 2;
		dvlqEndFlag[player] = 2;
		
		// �ԉ�
		if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 30)) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			statc[player * 10 + 2]++;
		}
	} else if(dvlqLevel[player] >= 1300) {
		// ���S�N���A
		printTinyFont(foffset[player] + 22, fyoffset[player] + 116, "DEVIL MODE");
		printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
		dvlqEndFlag[player] = 2;
		
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
void dvlqLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 5; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/5)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(dvlqBgmListTable[i]);
		}
	}
}

// �X�R�A��\��
void dvlqViewScore(int player) {
	int i, x, y, color, kind;
	color = (count % 4 / 2) * 7;
	
	// ���_���i�ʏ�j
	for(i = 0; i < 4; i++) {
		if((dvlqMedalAnim[player * 4 + i] < 0) || (dvlqMedalAnim[player * 4 + i] > 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 17;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			if(i == 0) kind = 1;
			if(i == 1) kind = 0;
			if(i == 2) kind = 5;
			if(i == 3) kind = 2;
			dvlqDrawMedal(x, y, kind, dvlqMedalStat[player * 4 + i], dvlqMedalAnim[player * 4 + i]);
		}
	}
	
	// ���_���i�A�j�����j
	for(i = 0; i < 4; i++) {
		if((dvlqMedalAnim[player * 4 + i] >= 0) && (dvlqMedalAnim[player * 4 + i] <= 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 17;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			if(i == 0) kind = 1;
			if(i == 1) kind = 0;
			if(i == 2) kind = 5;
			if(i == 3) kind = 2;
			dvlqDrawMedal(x, y, kind, dvlqMedalStat[player * 4 + i], dvlqMedalAnim[player * 4 + i]);
			dvlqMedalAnim[player * 4 + i]++;
		}
	}
	
	// ���x���i���q�j
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(dvlqLevel[player] == -1) sprintf(string[0], "%4d", 0);	// -1�Ȃ�0�ƕ\������(�����I�ɂ͍ŏ���-1�ɂȂ��Ă���)
	else sprintf(string[0], "%4d", dvlqLevel[player]);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// ���x���i�����j
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 0, 143, 22, 1);
	
	// ���x���i����j
	if(ending[player]) sprintf(string[0], "%4d", dvlqLevel[player]);
	else sprintf(string[0], "%4d", dvlqLevel[player] / 100 * 100 + 100);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, string[0], color);
	
	// �^�C��
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
	
	if(dvlqRegretFrame[player] > 0)
		printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "REGRET");	// REGRET�\��
	else if(dvlqTSpinFrame[player] > 0)
		printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "T-SPIN");	// T-SPIN�\��
}

// ���_����\��
void dvlqDrawMedal(int x, int y, int kind, int color, int anim) {
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
void dvlqResult(int player, int *param) {
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
			statc[player * 10 + 2] = dvlqRegistRanking(player);
			statc[player * 10 + 3] = dvlqUpdateSectionTimeRanking(player);
			if((statc[player * 10 + 2] != -1) || (statc[player * 10 + 3] != 0)) dvlqSaveRanking(player);
			
			// ���i�ʔ���
			statc[player * 10 + 4] = checkSecretGrade(player);
		}
		
		// �i�ʕ\��
		if(dvlqGrade[player] == 0)		// 1
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108,   0, ((count % 4 / 2) * 216) + 192, 90, 24);
		else if(dvlqGrade[player] < 10)	// S1�`S9
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108,  90, ((count % 4 / 2) * 216) + ((dvlqGrade[player] -  1) * 24), 90, 24);
		else if(dvlqGrade[player] < 14)	// S10�`S13
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108, 360, ((count % 4 / 2) * 216) + ((dvlqGrade[player] - 10) * 24), 90, 24);
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
		sprintf(string[0], "%13d", dvlqScore[player]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 67, string[0], 0);
		
		printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LEVEL");
		sprintf(string[0], "%13d", dvlqLevel[player]);
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
			sprintf(string[0], "%13s", dvlqStrSecretGradeName[statc[player * 10 + 4]]);
			printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
		}
	}
}

// �ݒ���
void dvlqSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(dvlqLoadConfig() == 0) dvlqSaveConfig();
	
	// �����L���O��ǂݍ���
	if(dvlqLoadRanking(player) == 0) dvlqInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "DEVIL-QUAKE OPTIONS", 4);
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
		if(!dvlqIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!dvlqBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!dvlqLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(dvlqTSpin == 0) sprintf(string[0], "OFF");
		else if(dvlqTSpin == 1) sprintf(string[0], "LINE CLEAR");
		else if(dvlqTSpin == 2) sprintf(string[0], "IMMOBILE");
		else if(dvlqTSpin == 3) sprintf(string[0], "3-CORNER");
		else sprintf(string[0], "3-CORNER NO KICK");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(!dvlqTorikan) sprintf(string[0], "OFF");
		else getTime(dvlqTorikan);
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		if(!dvlqRiseEnable) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		sprintf(string[0], "%d", dvlqStartLevel);
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
			
			if(cursor == 0) dvlqIsBig = !dvlqIsBig;
			if(cursor == 1) dvlqBigMove = !dvlqBigMove;
			if(cursor == 2) dvlqLvUpBonus = !dvlqLvUpBonus;
			if(cursor == 3) {
				dvlqTSpin = dvlqTSpin + move;
				if(dvlqTSpin < 0) dvlqTSpin = 4;
				if(dvlqTSpin > 4) dvlqTSpin = 0;
			}
			if(cursor == 4) {
				dvlqTorikan = dvlqTorikan + (move * 60);
				if(dvlqTorikan < 0) dvlqTorikan = 72000;
				if(dvlqTorikan > 72000) dvlqTorikan = 0;
			}
			if(cursor == 5) {
				dvlqRiseEnable = !dvlqRiseEnable;
			}
			if(cursor == 6) {
				dvlqStartLevel = dvlqStartLevel + (move * 100);
				if(dvlqStartLevel < 0) dvlqStartLevel = 1200;
				if(dvlqStartLevel > 1200) dvlqStartLevel = 0;
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
			dvlqSaveConfig();
			return;
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			dvlqViewRanking(player);
		}
	}
}

// �ݒ��ۑ�
void dvlqSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x49564544;
	saveBuf[3] = 0x3176444C;
	
	// �ݒ���e
	saveBuf[4] = dvlqIsBig;
	saveBuf[5] = dvlqBigMove;
	saveBuf[6] = dvlqLvUpBonus;
	saveBuf[7] = dvlqTSpin;
	saveBuf[8] = dvlqTorikan;
	saveBuf[9] = dvlqRiseEnable;
	saveBuf[10] = dvlqStartLevel;
	
	SaveFile("config/DEVIL_QUAKE_CONFIG.SAV", &saveBuf, 100 * 4);
}

// �ݒ��ǂݍ���
int dvlqLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/DEVIL_QUAKE_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x49564544) return 0;
	if(saveBuf[3] != 0x3176444C) return 0;
	
	// �ݒ���e
	dvlqIsBig = saveBuf[4];
	dvlqBigMove = saveBuf[5];
	dvlqLvUpBonus = saveBuf[6];
	dvlqTSpin = saveBuf[7];
	dvlqTorikan = saveBuf[8];
	dvlqRiseEnable = saveBuf[9];
	dvlqStartLevel = saveBuf[10];
	
	return 1;
}

// ���v���C�ۑ�
void dvlqSaveReplay(int player) {
	saveBuf[900] = dvlqIsBig;
	saveBuf[901] = dvlqBigMove;
	saveBuf[902] = dvlqLvUpBonus;
	saveBuf[903] = dvlqTSpin;
	saveBuf[904] = dvlqTorikan;
	saveBuf[905] = dvlqRiseEnable;
	saveBuf[906] = dvlqLevel[player];
	saveBuf[907] = dvlqScore[player];
	saveBuf[908] = dvlqGrade[player];
	saveBuf[909] = dvlqVersion;
	saveBuf[910] = dvlqStartLevel;
}

// ���v���C�ǂݍ���
void dvlqLoadReplay(int player) {
	dvlqIsBig = saveBuf[900];
	dvlqBigMove = saveBuf[901];
	dvlqLvUpBonus = saveBuf[902];
	dvlqTSpin = saveBuf[903];
	dvlqTorikan = saveBuf[904];
	dvlqRiseEnable = saveBuf[905];
	dvlqVersion = saveBuf[909];
	dvlqStartLevel = saveBuf[910];
}

// ���v���C�ڍ�
void dvlqReplayDetail(int number) {
	printFontGrid(1, 5, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[907]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[906]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "GRADE", 0);
	if((saveBuf[908] >= 0) && (saveBuf[908] <= 14)) {
		printFontGrid(22, 7, dvlqStrGradeName[saveBuf[908]], 0);
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
	
	printFontGrid(1, 15, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[910]);
	printFontGrid(22, 15, string[0], 0);
	
	printFontGrid(1, 16, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[909]);
	printFontGrid(22, 16, string[0], 0);
}

// �����L���O�ۑ�
void dvlqSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �m�[�}�������L���O
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0]  = dvlqRankingGrade[i];
		saveBuf[1 + (i * 20) + 1]  = dvlqRankingLevel[i];
		saveBuf[1 + (i * 20) + 2]  = dvlqRankingTime[i];
		saveBuf[1 + (i * 20) + 3]  = dvlqRankingEnd[i];
		saveBuf[1 + (i * 20) + 4]  = dvlqRankingMedal[i * 4 + 0];
		saveBuf[1 + (i * 20) + 5]  = dvlqRankingMedal[i * 4 + 1];
		saveBuf[1 + (i * 20) + 6]  = dvlqRankingMedal[i * 4 + 2];
		saveBuf[1 + (i * 20) + 7]  = dvlqRankingMedal[i * 4 + 3];
		saveBuf[1 + (i * 20) + 8]  = dvlqRankingYear[i];
		saveBuf[1 + (i * 20) + 9]  = dvlqRankingMonth[i];
		saveBuf[1 + (i * 20) + 10] = dvlqRankingDay[i];
		saveBuf[1 + (i * 20) + 11] = dvlqRankingHour[i];
		saveBuf[1 + (i * 20) + 12] = dvlqRankingMinute[i];
		saveBuf[1 + (i * 20) + 13] = dvlqRankingSecond[i];
	}
	
	// �Z�N�V�����^�C�������L���O
	for(i = 0; i < 13; i++) {
		saveBuf[221 + (i * 10) + 0] = dvlqRankingSectionTime[i];
		saveBuf[221 + (i * 10) + 1] = dvlqRankingSectionEnd[i];
		saveBuf[221 + (i * 10) + 2] = dvlqRankingSectionYear[i];
		saveBuf[221 + (i * 10) + 3] = dvlqRankingSectionMonth[i];
		saveBuf[221 + (i * 10) + 4] = dvlqRankingSectionDay[i];
		saveBuf[221 + (i * 10) + 5] = dvlqRankingSectionHour[i];
		saveBuf[221 + (i * 10) + 6] = dvlqRankingSectionMinute[i];
		saveBuf[221 + (i * 10) + 7] = dvlqRankingSectionSecond[i];
	}
	
	sprintf(string[0], "config/DEVIL_QUAKE_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 361 * 4);
}

// �����L���O�ǂݍ���
int dvlqLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/DEVIL_QUAKE_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 361 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �m�[�}�������L���O
	for(i = 0; i < 10; i++) {
		dvlqRankingGrade[i]         = saveBuf[1 + (i * 20) + 0];
		dvlqRankingLevel[i]         = saveBuf[1 + (i * 20) + 1];
		dvlqRankingTime[i]          = saveBuf[1 + (i * 20) + 2];
		dvlqRankingEnd[i]           = saveBuf[1 + (i * 20) + 3];
		dvlqRankingMedal[i * 4 + 0] = saveBuf[1 + (i * 20) + 4];
		dvlqRankingMedal[i * 4 + 1] = saveBuf[1 + (i * 20) + 5];
		dvlqRankingMedal[i * 4 + 2] = saveBuf[1 + (i * 20) + 6];
		dvlqRankingMedal[i * 4 + 3] = saveBuf[1 + (i * 20) + 7];
		dvlqRankingYear[i]          = saveBuf[1 + (i * 20) + 8];
		dvlqRankingMonth[i]         = saveBuf[1 + (i * 20) + 9];
		dvlqRankingDay[i]           = saveBuf[1 + (i * 20) + 10];
		dvlqRankingHour[i]          = saveBuf[1 + (i * 20) + 11];
		dvlqRankingMinute[i]        = saveBuf[1 + (i * 20) + 12];
		dvlqRankingSecond[i]        = saveBuf[1 + (i * 20) + 13];
	}
	
	// �Z�N�V�����^�C�������L���O
	for(i = 0; i < 13; i++) {
		dvlqRankingSectionTime[i]   = saveBuf[221 + (i * 10) + 0];
		dvlqRankingSectionEnd[i]    = saveBuf[221 + (i * 10) + 1];
		dvlqRankingSectionYear[i]   = saveBuf[221 + (i * 10) + 2];
		dvlqRankingSectionMonth[i]  = saveBuf[221 + (i * 10) + 3];
		dvlqRankingSectionDay[i]    = saveBuf[221 + (i * 10) + 4];
		dvlqRankingSectionHour[i]   = saveBuf[221 + (i * 10) + 5];
		dvlqRankingSectionMinute[i] = saveBuf[221 + (i * 10) + 6];
		dvlqRankingSectionSecond[i] = saveBuf[221 + (i * 10) + 7];
	}
	
	return 1;
}

// �����L���O������
void dvlqInitRanking() {
	int i;
	
	// �m�[�}�������L���O
	for(i = 0; i < 10; i++) {
		dvlqRankingGrade[i]         = 0;
		dvlqRankingLevel[i]         = 0;
		dvlqRankingTime[i]          = 0;
		dvlqRankingEnd[i]           = 0;
		dvlqRankingMedal[i * 4 + 0] = 0;
		dvlqRankingMedal[i * 4 + 1] = 0;
		dvlqRankingMedal[i * 4 + 2] = 0;
		dvlqRankingMedal[i * 4 + 3] = 0;
		dvlqRankingYear[i]          = 0;
		dvlqRankingMonth[i]         = 0;
		dvlqRankingDay[i]           = 0;
		dvlqRankingHour[i]          = 0;
		dvlqRankingMinute[i]        = 0;
		dvlqRankingSecond[i]        = 0;
	}
	
	// �Z�N�V�����^�C�������L���O
	for(i = 0; i < 13; i++) {
		dvlqRankingSectionTime[i]   = 3600;
		dvlqRankingSectionEnd[i]    = 0;
		dvlqRankingSectionYear[i]   = 0;
		dvlqRankingSectionMonth[i]  = 0;
		dvlqRankingSectionDay[i]    = 0;
		dvlqRankingSectionHour[i]   = 0;
		dvlqRankingSectionMinute[i] = 0;
		dvlqRankingSectionSecond[i] = 0;
	}
}

// �����L���O�o�^
int dvlqRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (dvlqIsBig) || (!dvlqLvUpBonus) || (dvlqStartLevel)) return -1;
	
	for(i = 0; i < 10; i++) {
		// �����N�C��
		if(
		    (dvlqEndFlag[player] > dvlqRankingEnd[i]) || 
		    ((dvlqEndFlag[player] == dvlqRankingEnd[i]) && (dvlqGrade[player] > dvlqRankingGrade[i])) || 
		    ((dvlqEndFlag[player] == dvlqRankingEnd[i]) && (dvlqGrade[player] == dvlqRankingGrade[i]) && (gameTimer[player] < dvlqRankingTime[i]))
		  )
		{
			// �����L���O�����炷
			for(j = 9; j > i; j--) {
				dvlqRankingGrade[j]         = dvlqRankingGrade[j - 1];
				dvlqRankingLevel[j]         = dvlqRankingLevel[j - 1];
				dvlqRankingTime[j]          = dvlqRankingTime[j - 1];
				dvlqRankingEnd[j]           = dvlqRankingEnd[j - 1];
				dvlqRankingMedal[j * 4 + 0] = dvlqRankingMedal[(j - 1) * 4 + 0];
				dvlqRankingMedal[j * 4 + 1] = dvlqRankingMedal[(j - 1) * 4 + 1];
				dvlqRankingMedal[j * 4 + 2] = dvlqRankingMedal[(j - 1) * 4 + 2];
				dvlqRankingMedal[j * 4 + 3] = dvlqRankingMedal[(j - 1) * 4 + 3];
				dvlqRankingYear[j]          = dvlqRankingYear[j - 1];
				dvlqRankingMonth[j]         = dvlqRankingMonth[j - 1];
				dvlqRankingDay[j]           = dvlqRankingDay[j - 1];
				dvlqRankingHour[j]          = dvlqRankingHour[j - 1];
				dvlqRankingMinute[j]        = dvlqRankingMinute[j - 1];
				dvlqRankingSecond[j]        = dvlqRankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			dvlqRankingGrade[i]         = dvlqGrade[player];
			dvlqRankingLevel[i]         = dvlqLevel[player];
			dvlqRankingTime[i]          = gameTimer[player];
			dvlqRankingEnd[i]           = dvlqEndFlag[player];
			dvlqRankingMedal[i * 4 + 0] = dvlqMedalStat[player * 4 + 0];
			dvlqRankingMedal[i * 4 + 1] = dvlqMedalStat[player * 4 + 1];
			dvlqRankingMedal[i * 4 + 2] = dvlqMedalStat[player * 4 + 2];
			dvlqRankingMedal[i * 4 + 3] = dvlqMedalStat[player * 4 + 3];
			
			GetDateAndTime(&timebuf);
			dvlqRankingYear[i]          = timebuf[0];
			dvlqRankingMonth[i]         = timebuf[1];
			dvlqRankingDay[i]           = timebuf[2];
			dvlqRankingHour[i]          = timebuf[4];
			dvlqRankingMinute[i]        = timebuf[5];
			dvlqRankingSecond[i]        = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �Z�N�V�����^�C�������L���O�X�V
int dvlqUpdateSectionTimeRanking(int player) {
	int i, timebuf[8], result;
	result = 0;
	
	if((playback) || (dvlqIsBig) || (!dvlqLvUpBonus) || (dvlqStartLevel)) return 0;
	
	for(i = 0; i < 13; i++) {
		if((dvlqSectionTime[i + player * 13] < dvlqRankingSectionTime[i]) && (dvlqSectionTime[i + player * 13] != 0)) {
			result++;
			
			dvlqRankingSectionTime[i] = dvlqSectionTime[i + player * 13];
			dvlqRankingSectionEnd[i] = dvlqEndFlag[player];
			
			GetDateAndTime(&timebuf);
			dvlqRankingSectionYear[i] = timebuf[0];
			dvlqRankingSectionMonth[i] = timebuf[1];
			dvlqRankingSectionDay[i] = timebuf[2];
			dvlqRankingSectionHour[i] = timebuf[4];
			dvlqRankingSectionMinute[i] = timebuf[5];
			dvlqRankingSectionSecond[i] = timebuf[6];
		}
	}
	
	return result;
}

// �����L���O�\��
void dvlqViewRanking(int player) {
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
			printFontGrid(1, 1, "DEVIL-QUAKE MODE RANKING >>", 6);
			printFontGrid(1, 3, "RANK GRADE LEVEL TIME", 4);
			
			for(i = 0; i < 10; i++) {
				if(dvlqRankingEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (dvlqRankingEnd[i] - 1) * 2, 320, 2);
				
				if(i == 0) sprintf(string[0], " 1ST");
				if(i == 1) sprintf(string[0], " 2ND");
				if(i == 2) sprintf(string[0], " 3RD");
				if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
				printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
				
				if((dvlqRankingGrade[i] >= 0) && (dvlqRankingGrade[i] <= 14)) {
					printFontGrid(6, 4 + i, dvlqStrGradeName[dvlqRankingGrade[i]], 7 * (cursor == i));
				} else {
					printFontGrid(6, 4 + i, "???", 7 * (cursor == i));
				}
				
				sprintf(string[0], "%d", dvlqRankingLevel[i]);
				printFontGrid(12, 4 + i, string[0], 7 * (cursor == i));
				
				getTime(dvlqRankingTime[i]);
				printFontGrid(18, 4 + i, string[0], 7 * (cursor == i));
			}
			
			for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
			
			if(!erasemode) {
				// ���_��
				dvlqDrawMedal(8 + 0 * 16, 192, 1, dvlqRankingMedal[cursor * 4 + 0], -1);
				dvlqDrawMedal(8 + 1 * 16, 192, 0, dvlqRankingMedal[cursor * 4 + 1], -1);
				dvlqDrawMedal(8 + 2 * 16, 192, 5, dvlqRankingMedal[cursor * 4 + 2], -1);
				dvlqDrawMedal(8 + 3 * 16, 192, 2, dvlqRankingMedal[cursor * 4 + 3], -1);
				
				// ���t�Ǝ���
				sprintf(string[0],
				        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
				        dvlqRankingYear[cursor], dvlqRankingMonth[cursor], dvlqRankingDay[cursor],
				        dvlqRankingHour[cursor], dvlqRankingMinute[cursor], dvlqRankingSecond[cursor]);
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
					dvlqInitRanking();
					dvlqSaveRanking(player);
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
			printFontGrid(1, 1, "<< DEVIL-QUAKE MODE SECTION TIME", 6);
			printFontGrid(1, 3, "SECTION   TIME     DATE", 4);
			printFontGrid(1, 28, "A/B:EXIT", 6);
			
			for(i = 0; i < 13; i++) {
				if(dvlqRankingSectionEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (dvlqRankingSectionEnd[i] - 1) * 2, 320, 2);
				
				sprintf(string[0], "%4d-%4d", i * 100, ((i + 1) * 100) - 1);
				printFontGrid(1, 4 + i, string[0], 0);
				
				getTime(dvlqRankingSectionTime[i]);
				printFontGrid(11, 4 + i, string[0], 0);
				
				temp = (dvlqRankingSectionYear[i] / 1000) * 1000;	// �N����2�������\��
				if(temp == 0) temp = 1;
				sprintf(string[0], "%02d/%02d/%02d", dvlqRankingSectionYear[i] % temp, dvlqRankingSectionMonth[i], dvlqRankingSectionDay[i]);
				printFontGrid(20, 4 + i, string[0], 0);
				
				sprintf(string[0], "%02d:%02d:%02d", dvlqRankingSectionHour[i], dvlqRankingSectionMinute[i], dvlqRankingSectionSecond[i]);
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
