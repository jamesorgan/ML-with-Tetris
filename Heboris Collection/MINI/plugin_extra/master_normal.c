//MASTER-NORMAL
//Special Thanks to www.tetrisconcept.com's wiki
//prefix:masn

// �o�[�W����
int masnVersion;		// �o�[�W�����ԍ��i�Â����v���C�Đ��p�j
int masnCVersion = 4;	// ���݂̃o�[�W����

// ���x���A�b�v�e�[�u��(420�ł̌����ǉ���)
// ���x
int masnLevelTable[30] =
{
	4, 6, 8, 10, 12, 16, 32, 48, 64, 80, 96, 112, 128, 144, 4, 32, 64, 96, 128, 160,
	192, 224, 256, 512, 768, 1024, 1280, 1024, 768, 5120
};

// ���x��
int masnLevelChange[30] = 
{
	30, 35, 40, 50, 60, 70, 80, 90, 100, 120, 140, 160, 170, 200, 220, 230, 233, 236, 239, 243,
	247, 251, 300, 330, 360, 400, 420, 450, 500, 10000
};

// ���x���A�b�v�e�[�u��(420�ł̌����ǉ��O)
// ���x
int masnLevelTable3[29] =
{
	4, 6, 8, 10, 12, 16, 32, 48, 64, 80, 96, 112, 128, 144, 4, 32, 64, 96, 128, 160,
	192, 224, 256, 512, 768, 1024, 1280, 768, 5120
};

// ���x��
int masnLevelChange3[29] = 
{
	30, 35, 40, 50, 60, 70, 80, 90, 100, 120, 140, 160, 170, 200, 220, 230, 233, 236, 239, 243,
	247, 251, 300, 330, 360, 400, 450, 500, 10000
};

// wait�l           000,500,600,700,800,900
int masnWait1[6] = { 25, 25, 25, 16, 12, 12};
int masnWait2[6] = { 40, 25, 16, 12,  6,  6};
int masnWait3[6] = { 30, 30, 30, 30, 30, 17};
int masnWaitt[6] = { 16, 10, 10, 10, 10,  8};

// �i�ʂ̕\����
str masnStrGradeName[20] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0�` 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9�`17
	 "M", "GM"												// 18�`19
};

// �i�ʃ|�C���g�㏸�e�[�u��
int masnGradePoint1[11] = {10,10,10,10,10, 5, 5, 5, 5, 5, 2};
int masnGradePoint2[11] = {20,20,20,15,15,15,10,10,10,10,12};
int masnGradePoint3[11] = {40,30,30,30,20,20,20,15,15,15,13};
int masnGradePoint4[11] = {50,40,40,40,40,30,30,30,30,30,30};

// �R���{�̔{��
int masnGradeCombo[11 * 4] = 
{
//    0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,
	100, 100, 120, 120, 120, 120, 120, 120, 120, 120, 150,
	100, 100, 140, 150, 160, 170, 180, 190, 200, 210, 250,
	100, 100, 150, 180, 200, 220, 230, 240, 250, 260, 300,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100,   0,
};

// �i�ʕ\�����ς������N���X
int masnGradeNorm[17] = 
{
	1, 2, 3, 4, 5, 7, 9, 12, 15, 18, 19, 20, 23, 25, 27, 29, 31
};

// �i�ʃ|�C���g��1����܂ł̎���
int masnGradeTimeLimit[32] = 
{
	126, 81, 81, 51, 46, 46, 46, 46, 41, 41, 41, 41, 31, 31, 31, 21, 21, 21, 21, 21, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 11
};

// ���i�ʂ̕\����
str masnStrSecretGradeName[19] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0�` 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9�`17
	"GM"													// 18
};

// BGM�ݒ�
int masnBgmNo[5]     = {0,1,2,3,6};				// BGM�ԍ��i000-499�A500-699�A700-899�A900-998�A999�j
int masnFadeLv[4]    = {495,695,880,10000};		// BGM���t�F�[�h�A�E�g�����郌�x��
int masnBgmChange[4] = {500,700,900,10000};		// BGM��؂�ւ��郌�x��
int masnBgmIndex     = 0;						// ���݂�BGM�ԍ�

// �ϐ�
int masnModeNo = -1;	// ���[�h�ԍ�

int masnLevel[2];		// ���x��
int masnScore[2];		// �X�R�A
int masnLevelIndex[2];	// ���݂̑��x�ԍ�

int masnGrade[2];		// �i��
int masnGFlash[2];		// �i�ʕ\���Y�[�����o�p
int masnGPoint[2];		// ���݂̒i�ʃ|�C���g
int masnGTimer[2];		// �i�ʃ|�C���g�����^�C�}�[
int masnClass[2];		// �����N���X

int masnSTimer[2];				// �Z�N�V�����^�C�}�[
int masnSHebo[2];				// ���̃Z�N�V�����̃w�{���X��
int masnGMFlag[2 * 2];			// m���[�������t���O
int masnPreSTimer[2];			// �O�̃Z�N�V�����̃Z�N�V�����^�C��
int masnSectionTime[10 * 2];	// ���̃v���C�̃Z�N�V�����^�C��

int masnMedalStat[6 * 2];	// ���_���̏��(0=�Ȃ� 1=�� 2=�� 3=��)
int masnMedalAnim[6 * 2];	// ���_���l���A�j���[�V�����p�J�E���^

int masnSkill[2];		// �w�{���X��
int masnREFlag[2];		// RE���_���p�t���O�i0=�ʏ� 1=���J�o�����j
int masnTotalRotate[2];	// ��]������

int masnEndFlag[2];		// �N���A�t���O

int masnIsBig = 0;		// BIG���ǂ���
int masnBigMove = 1;	// BIG���̉��ړ��P��
int masnGhost = 0;		// �S�[�X�g�̐ݒ�i0=LV0-99 1=���ON 2=���OFF�j
int masnLvUpBonus = 0;	// ���x���A�b�v�{�[�i�X
int masn20G = 0;		// 20G���[�h
int masnStartLevel = 0;	// �X�^�[�g���̃��x��

// �����L���O�ϐ�
int masnRankingGrade[10];			// �i��
int masnRankingLevel[10];			// ���x��
int masnRankingTime[10];			// �^�C��
int masnRankingEnd[10];				// �N���A�t���O
int masnRankingMedal[6 * 10];		// ���_��
int masnRankingYear[10];			// �����N�C�������i�N�j
int masnRankingMonth[10];			// �����N�C�������i���j
int masnRankingDay[10];				// �����N�C�������i���j
int masnRankingHour[10];			// �����N�C�������i���j
int masnRankingMinute[10];			// �����N�C�������i���j
int masnRankingSecond[10];			// �����N�C�������i�b�j

// �Z�N�V�����^�C�������L���O�ϐ�
int masnRankingSectionTime[10];		// �^�C��
int masnRankingSectionEnd[10];		// �N���A�t���O
int masnRankingSectionYear[10];		// �����N�C�������i�N�j
int masnRankingSectionMonth[10];	// �����N�C�������i���j
int masnRankingSectionDay[10];		// �����N�C�������i���j
int masnRankingSectionHour[10];		// �����N�C�������i���j
int masnRankingSectionMinute[10];	// �����N�C�������i���j
int masnRankingSectionSecond[10];	// �����N�C�������i�b�j

// �C�x���g����
void masnPluginEvent(int player, int event, int *param) {
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != masnModeNo)) return;
	
	if(event == 0) {
		masnModeNo = addModePlugin("MASTER-NORMAL");	// ���[�h��o�^����
	} else if(event == 7) {
		if(!ending[player]) masnMoveInit(player);	// �u���b�N�o��
	} else if(event == 12) {
		if(!ending[player]) masnCalcScore(player, param[0]);	// �X�R�A�v�Z
	} else if(event == 15) {
		masnViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		masnSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		masnPlayerInitial(player);	// ����������
	} else if(event == 20) {
		masnGameOver(player);	// �Q�[���I�[�o�[�����̍ŏ�
	} else if(event == 21) {
		masnResult(player);	// ���ʕ\��
	} else if(event == 24) {
		masnEndingStart(player);	// �G���f�B���O�˓�
	} else if(event == 25) {
		masnExcellent(player, param);	// �G���f�B���O�I��
	} else if(event == 28) {
		masnIncrementTime(player);	// ���Ԃ�i�߂�
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		masnSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		masnLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		masnLoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		masnReplayDetail();	// ���v���C�ڍ�
	}
}

// ����������
void masnPlayerInitial(int player) {
	int i;
	
	// �o�[�W����
	if(!playback) masnVersion = masnCVersion;
	
	// �R���{�L��
	enable_combo[player] = 1;
	
	// �ϐ���������
	masnBgmIndex = 0;
	bgmlv = masnBgmNo[0];
	
	if(masnVersion >= 3) {
		if(masnStartLevel > 0) masnLevel[player] = masnStartLevel;
		else masnLevel[player] = -1;
		
		backno = masnLevel[player] / 100;
	} else {
		masnLevel[player] = -1;
	}
	masnScore[player] = 0;
	masnLevelIndex[player] = 0;
	
	masnGrade[player] = 0;
	masnGFlash[player] = 0;
	masnGPoint[player] = 0;
	masnGTimer[player] = 0;
	masnClass[player] = 0;
	
	masnSTimer[player] = 0;
	masnSHebo[player] = 0;
	
	masnGMFlag[player * 2 + 0] = 1;
	masnGMFlag[player * 2 + 1] = 1;
	
	masnPreSTimer[player] = 0;
	
	for(i = 0; i < 10; i++) masnSectionTime[i + player * 10] = 0;
	
	for(i = 0; i < 6; i++) {
		masnMedalStat[player * 6 + i] = 0;
		masnMedalAnim[player * 6 + i] = -1;
	}
	masnSkill[player] = 0;
	masnREFlag[player] = 0;
	masnTotalRotate[player] = 0;
	
	masnEndFlag[player] = 0;
	
	// �ݒ�𔽉f������
	IsBig[player] = masnIsBig;
	BigMove[player] = masnBigMove;
	if(masnGhost == 2) ghost[player] = 0;
	
	// �����X�s�[�h��ݒ�
	masnSpeedUp(player);
}

// �u���b�N�o��
void masnMoveInit(int player) {
	int temp;
	
	// �ŏ��̃t���[���Ȃ�
	if(statc[player * 10 + 3] == 0) {
		// ���x���A�b�v����
		if(masnLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		
		if(masnLevel[player] % 100 != temp) {
			masnLevel[player]++;
			if(masnLevel[player] % 100 == temp) PlaySE(se_lvstop);
			masnSpeedUp(player);
		}
		
		// RE���_��
		if(masnMedalStat[player * 6 + 3] < 3) {
			if(masnREFlag[player] == 0) {
				if(checkHowManyBlocks(player) >= 150) masnREFlag[player] = 1;
			} else {
				if(checkHowManyBlocks(player) <= 70) {
					masnREFlag[player] = 0;
					PlaySE(se_medal);
					masnMedalStat[player * 6 + 3]++;
					masnMedalAnim[player * 6 + 3] = 0;
				}
			}
		}
		
		// RO���_���֘A
		if(masnMedalStat[player * 6 + 4] < 3) {
			temp = brotcount[player];
			if(temp > 4) temp = 4;
			masnTotalRotate[player] = masnTotalRotate[player] + temp;
		}
	}
}

// �X�s�[�h�A�b�v
void masnSpeedUp(int player) {
	int temp;
	
	// �X�s�[�h��ς���
	speedtype[player] = 2;
	
	if(masn20G) {
		sp[player] = 5120;
	} else {
		if(masnVersion >= 4) {
			while(masnLevel[player] >= masnLevelChange[masnLevelIndex[player]]) masnLevelIndex[player]++;
		} else if(masnVersion >= 3) {
			while(masnLevel[player] >= masnLevelChange3[masnLevelIndex[player]]) masnLevelIndex[player]++;
		} else {
			if(masnLevel[player] >= masnLevelChange3[masnLevelIndex[player]]) masnLevelIndex[player]++;
		}
		
		if(masnVersion >= 4) {
			sp[player] = masnLevelTable[masnLevelIndex[player]];
		} else {
			sp[player] = masnLevelTable3[masnLevelIndex[player]];
		}
	}
	
	if(masnLevel[player] < 500) {
		wait1[player] = masnWait1[0];
		wait2[player] = masnWait2[0];
		wait3[player] = masnWait3[0];
		waitt[player] = masnWaitt[0];
	} else {
		wait1[player] = masnWait1[(masnLevel[player] / 100) - 4];
		wait2[player] = masnWait2[(masnLevel[player] / 100) - 4];
		wait3[player] = masnWait3[(masnLevel[player] / 100) - 4];
		waitt[player] = masnWaitt[(masnLevel[player] / 100) - 4];
	}
	
	// BGM�t�F�[�h�A�E�g
	if((masnLevel[player] >= masnFadeLv[masnBgmIndex]) && (masnLevel[player] < masnBgmChange[masnBgmIndex]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// BGM�؂�ւ�
	temp = 0;
	while(masnLevel[player] >= masnBgmChange[masnBgmIndex]) {
		masnBgmIndex++;
		bgmlv = masnBgmNo[masnBgmIndex];
		if(onRecord[player]) temp = 1;
	}
	if(temp) PlayBGM();
	
	// �S�[�X�g������
	if((masnLevel[player] >= 100) && (masnGhost == 0)) {
		ghost[player] = 0;
	}
}

// �X�R�A�v�Z
void masnCalcScore(int player, int lines) {
	int temp, temp2, temp3, index, bo, bai, nextsec;
	
	if(masnVersion >= 2) {
		if(!masnLvUpBonus) temp = masnLevel[player] + lines;
		else temp = masnLevel[player] + lines + ((lines >= 3) * (lines - 2));
		if(temp > 999) temp = 999;
		
		temp2 = wait3[player] - bactivetime[player];
		if(temp2 < 0) temp2 = 0;
		
		bo = ((masnLevel[player] + lines) / 4 + sdrop[player] + qdrop[player] + qput[player]) * lines * cmbpts[player] + (temp / 2) + (temp2 * 7);
		bai = 1;
	} else {
		bo = (masnLevel[player] + lines) / 4 + sdrop[player] + qdrop[player] + qput[player];
		bai = (lines * 2 - 1 + cmbpts[player] - (lines * 2 - 2)) * lines;
	}
	
	if(isBravo(player)) {
		// �S��������ƃX�R�A4�{
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		bai = bai * 4;
		
		// AC���_���l��
		if(masnMedalStat[player * 6 + 0] < 3) {
			PlaySE(se_medal);
			masnMedalStat[player * 6 + 0]++;
			masnMedalAnim[player * 6 + 0] = 0;
		}
	}
	
	// �X�R�A���Z
	masnScore[player] = masnScore[player] + bo * bai;
	
	// �w�{���X�񐔑���
	if(lines >= 4) {
		masnSkill[player]++;
		
		// SK���_���l��
		if((masnSkill[player] == 10) || (masnSkill[player] == 20) || (masnSkill[player] == 35)) {
			PlaySE(se_medal);
			masnMedalStat[player * 6 + 2]++;
			masnMedalAnim[player * 6 + 2] = 0;
		}
	}
	
	// CO���_���l��
	if(combo2[player] == 4) {
		if(masnMedalStat[player * 6 + 5] < 1) {
			PlaySE(se_medal);
			masnMedalStat[player * 6 + 5] = 1;
			masnMedalAnim[player * 6 + 5] = 0;
		}
	} else if(combo2[player] == 5) {
		if(masnMedalStat[player * 6 + 5] < 2) {
			PlaySE(se_medal);
			masnMedalStat[player * 6 + 5] = 2;
			masnMedalAnim[player * 6 + 5] = 0;
		}
	} else if(combo2[player] == 7) {
		if(masnMedalStat[player * 6 + 5] < 3) {
			PlaySE(se_medal);
			masnMedalStat[player * 6 + 5] = 3;
			masnMedalAnim[player * 6 + 5] = 0;
		}
	}
	
	// �i�ʃ|�C���g���Z
	if(masnClass[player] < 31) {
		index = masnClass[player];
		if(index > 10) index = 10;
		
		if(masnLevel[player] < 250) {
			temp2 = 1;
		} else if(masnLevel[player] < 500) {
			temp2 = 2;
		} else if(masnLevel[player] < 750) {
			temp2 = 3;
		} else {
			temp2 = 4;
		}
		
		if(lines == 1) temp = masnGradePoint1[index] * temp2;
		if(lines == 2) temp = masnGradePoint2[index] * temp2;
		if(lines == 3) temp = masnGradePoint3[index] * temp2;
		if(lines == 4) temp = masnGradePoint4[index] * temp2;
		
		if(masnVersion >= 1) temp3 = combo2[player];
		else temp3 = combo3[player];
		
		if(temp3 > 10) temp3 = 10;
		
		temp = (temp * 10) * masnGradeCombo[temp3 + (lines - 1) * 11] / 1000;
		masnGPoint[player] = masnGPoint[player] + temp;
		
		// �����N���X�㏸
		if(masnGPoint[player] >= 100) {
			masnGPoint[player] = 0;
			masnClass[player]++;
			
			if((masnClass[player] >= masnGradeNorm[masnGrade[player]]) && (masnGrade[player] < 17)) {
				PlaySE(se_rankup);
				masnGrade[player]++;
				masnGFlash[player] = 120;
			}
		}
	}
	
	// ���x���A�b�v
	nextsec = masnLevel[player] / 100 * 100 + 100;
	if(!masnLvUpBonus) masnLevel[player] = masnLevel[player] + lines;
	else masnLevel[player] = masnLevel[player] + lines + ((lines >= 3) * (lines - 2));
	
	if(masnLevel[player] >= 999) {
		// �G���f�B���O
		masnLevel[player] = 999;
		ending[player] = 1;
		timeOn[player] = 0;
		masnEndFlag[player] = 1;
		
		// ST���_���l��
		masnMedalST(player, 9);
		
		// RO���_���l��
		masnMedalRO(player);
		
		// m���[���������s����
		if((masnVersion == 0) && (masnSTimer[player] > 2700)) masnGMFlag[player * 2 + 0] = 0;
		
		if((masnVersion >= 1) && (masnSTimer[player] > masnPreSTimer[player] + 120))
			masnGMFlag[player * 2 + 0] = 0;
		
		if(gameTimer[player] > 31500) masnGMFlag[player * 2 + 0] = 0;
		
		// m���[���˓�����
		if((masnGMFlag[player * 2 + 0]) && (masnGMFlag[player * 2 + 1]) && (masnGrade[player] >= 17)) {
			objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
		}
	} else {
		// ���x���X�g�b�v��
		if(masnLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		if(masnLevel[player] % 100 == temp) PlaySE(se_lvstop);
		
		if(masnLevel[player] >= nextsec) {
			// ���x���A�b�v��
			PlaySE(se_levelup);
			
			// �w�i�؂�ւ�
			bgfadesw = 1;
			bgfadebg = nextsec / 100;
			
			// ST���_���l��
			masnMedalST(player, (nextsec / 100) - 1);
			
			// RO���_���l��
			if((nextsec == 300) || (nextsec == 700)) masnMedalRO(player);
			
			// m���[���������s����
			if(masnVersion >= 1) temp = nextsec;
			else temp = masnLevel[player];
			temp2 = 500 + ((masnVersion >= 1) * 100);
			
			if((masnVersion == 0) || (temp < temp2)) {
				if(masnSTimer[player] > 3900) masnGMFlag[player * 2 + 0] = 0;
			}
			
			if( ((temp <  temp2) && (masnSHebo[player] < 2)) || 
			    ((temp >= temp2) && (masnSHebo[player] < 1)) )
				masnGMFlag[player * 2 + 1] = 0;
			
			if(masnVersion >= 1) {
				if((temp >= temp2) && (masnSTimer[player] > masnPreSTimer[player] + 120))
					masnGMFlag[player * 2 + 0] = 0;
				
				masnPreSTimer[player] = masnSTimer[player];
			}
			
			// �Z�N�V�����^�C�}�[�ƃw�{���X�񐔂����Z�b�g
			masnSTimer[player] = 0;
			masnSHebo[player] = 0;
		}
		
		// �X�s�[�h�A�b�v
		masnSpeedUp(player);
	}
}

// ST���_���l��
void masnMedalST(int player, int section) {
	masnSectionTime[section + player * 10] = masnSTimer[player];
	
	if((!playback) && (!IsBig[player]) && (!masnLvUpBonus) && (!masn20G) && (!masnStartLevel)) {
		if((masnSTimer[player] < masnRankingSectionTime[section]) && (masnMedalStat[player * 6 + 1] < 3)) {
			PlaySE(se_medal);
			masnMedalStat[player * 6 + 1] = 3;
			masnMedalAnim[player * 6 + 1] = 0;
		} else if((masnSTimer[player] < masnRankingSectionTime[section] + 300) && (masnMedalStat[player * 6 + 1] < 2)) {
			PlaySE(se_medal);
			masnMedalStat[player * 6 + 1] = 2;
			masnMedalAnim[player * 6 + 1] = 0;
		} else if((masnSTimer[player] < masnRankingSectionTime[section] + 600) && (masnMedalStat[player * 6 + 1] < 1)) {
			PlaySE(se_medal);
			masnMedalStat[player * 6 + 1] = 1;
			masnMedalAnim[player * 6 + 1] = 0;
		}
	}
}

// RO���_���l��
void masnMedalRO(int player) {
	int temp, temp2;
	
	temp = bdowncnt[player];
	if(temp < 1) temp = 1;
	
	temp2 = masnTotalRotate[player] / temp;
	
	if( (temp2 >= 2) || ((temp2 == 1) && (masnTotalRotate[player] % temp >= 2)) ) {
		PlaySE(se_medal);
		masnMedalStat[player * 6 + 4]++;
		masnMedalAnim[player * 6 + 4] = 0;
	}
}

// BGM�ǂݍ���
void masnLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 5; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/5)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(masnBgmNo[i]);
		}
	}
}

// �X�R�A�\��
void masnViewScore(int player) {
	int i, color, color2, x, y, k, zoomx, zoomy, temp;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// �i��
	color2 = (count % 4 / 2) * (is20G(player));
	
	if(masnGFlash[player] > 108) {
		// �Y�[����
		k = masnGFlash[player] - 96;
		zoomx = (90 * k / 12 - 90) / 2;
		zoomy = (24 * k / 12 - 24) / 2;
		k = 65536 * k / 12;
		
		x = foffset[player] + 63 - zoomx;
		y = fyoffset[player] + 40 - zoomy;
		
		if(masnGrade[player] < 9) {
			// 9�`1
			ExBltRectR(sg_grade, x, y, 0, (color2 * 216) + (masnGrade[player] * 24), 90, 24, k, k);
		} else if(masnGrade[player] < 18) {
			// S1�`S9
			ExBltRectR(sg_grade, x, y, 90, (color2 * 216) + ((masnGrade[player] - 9) * 24), 90, 24, k, k);
		} else if(masnGrade[player] == 18) {
			// m
			ExBltRectR(sg_grade, x + 9, y, 450, (color2 * 216), 90, 24, k, k);
		} else {
			// Gm
			ExBltRectR(sg_grade, x + 9, y, 450, (color2 * 216) + 150, 90, 27, k, k);
		}
	} else {
		// �ʏ�
		x = foffset[player] + 63;
		y = fyoffset[player] + 40;
		
		if(masnGrade[player] < 9) {
			// 9�`1
			ExBltRect(sg_grade, x, y, 0, (color2 * 216) + (masnGrade[player] * 24), 90, 24);
		} else if(masnGrade[player] < 18) {
			// S1�`S9
			ExBltRect(sg_grade, x, y, 90, (color2 * 216) + ((masnGrade[player] - 9) * 24), 90, 24);
		} else if(masnGrade[player] == 18) {
			// m
			ExBltRect(sg_grade, x + 9, y, 450, (color2 * 216), 90, 24);
		} else {
			// Gm
			ExBltRect(sg_grade, x + 9, y, 450, (color2 * 216) + 150, 90, 27);
		}
	}
	
	// ���_���i�ʏ�j
	for(i = 0; i < 6; i++) {
		if((masnMedalAnim[player * 6 + i] < 0) || (masnMedalAnim[player * 6 + i] > 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 16;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			masnDrawMedal(x, y, i, masnMedalStat[player * 6 + i], masnMedalAnim[player * 6 + i]);
		}
	}
	
	// ���_���i�A�j�����j
	for(i = 0; i < 6; i++) {
		if((masnMedalAnim[player * 6 + i] >= 0) && (masnMedalAnim[player * 6 + i] <= 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 16;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			masnDrawMedal(x, y, i, masnMedalStat[player * 6 + i], masnMedalAnim[player * 6 + i]);
			masnMedalAnim[player * 6 + i]++;
		}
	}
	
	// �X�R�A
	printTinyFont(foffset[player] + 96, fyoffset[player] + 135, "SCORE");
	sprintf(string[0], "%d", masnScore[player]);
	//sprintf(string[0], "%d", masnGPoint[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 143, string[0], color);
	
	// ���x���i���q�j
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(masnLevel[player] == -1) sprintf(string[0], "%4d", 0);	// -1�Ȃ�0�ƕ\������(�����I�ɂ͍ŏ���-1�ɂȂ��Ă���)
	else sprintf(string[0], "%4d", masnLevel[player]);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// ���x���i�����j
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	temp = sp[player] / 128;
	if(temp > 22) temp = 22;
	ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22 - temp, 143, 22, 1);
	
	// ���x���i����j
	if(masnLevel[player] >= 900) sprintf(string[0], "%4d", 999);
	else sprintf(string[0], "%4d", masnLevel[player] / 100 * 100 + 100);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, string[0], color);
	
	// �^�C��
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
}

// ���_����\��
void masnDrawMedal(int x, int y, int kind, int color, int anim) {
	int i, j, k;
	
	if(color == 0) return;
	
	if((anim >= 0) && (anim < 16)) {
		k = 16 - anim;
		i = (15 * k / 3 - 15) / 2;
		j = (12 * k / 3 - 12) / 2;
		k = 65536 * k / 3;
		if(k < 65536) {
			k = 65536;
			i = 0;
			j = 0;
		}
		ExBltRectR(sg_medal[0], x - i, y - j, kind * 16, color * 13, 15, 12, k, k);
	} else {
		ExBltRect(sg_medal[0], x, y, kind * 16, color * 13, 15, 12);
	}
}

// ���Ԃ�i�߂�
void masnIncrementTime(int player) {
	int i;
	
	// �Z�N�V�����^�C������
	if(timeOn[player]) masnSTimer[player]++;
	
	// ���[���I��
	if((ending[player] == 2) && (edrec[player] >= 60 * 60)) {
		ending[player] = 3;
		stat[player] = 10;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
	
	// �i�ʂ����鉉�o�̎��Ԃ����炷
	if(masnGFlash[player] > 0) masnGFlash[player]--;
	
	// �i�ʃ|�C���g������
	if((stat[player] == 4) && (masnGPoint[player] > 0) && (!ending[player])) {
		if(masnVersion >= 1) i = combo2[player];
		else i = combo3[player];
		
		if(i < 2) masnGTimer[player]++;
		
		i = masnClass[player];
		if(i > 31) i = 31;
		
		if(masnGTimer[player] >= masnGradeTimeLimit[i]) {
			masnGTimer[player] = 0;
			masnGPoint[player]--;
		}
	}
}

// �G���f�B���O�˓�
void masnEndingStart(int player) {
	int i;
	
	for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	
	ending[player] = 2;
	stat[player] = 4;
	ending_timeOn[player] = 1;
	fastroll[player] = 0;
	
	if((masnGMFlag[player * 2 + 0]) && (masnGMFlag[player * 2 + 1]) && (masnGrade[player] >= 17)) {
		// m���[��
		hidden[player] = 10;
	} else {
		// �ʏ탍�[��
		hidden[player] = 8;
		shadowtime[player] = 300;
	}
	
	bgmlv = masnBgmNo[4];
	PlayBGM();
}

// �G���f�B���O�I��
void masnExcellent(int player, int *param) {
	onRecord[player] = 0;
	masnEndFlag[player] = 2;
	statc[player * 10 + 1]++;
	
	if(statc[player * 10 + 1] == 1) {
		if(hidden[player] == 10) {
			// m���[���N���A
			PlaySE(se_rankup);
			hidden[player] = 0;
			masnGrade[player] = 19;
			masnGFlash[player] = 120;
		} else {
			// �u���b�N��������悤�ɂ���
			disableShadowTimer(player);
		}
	}
	
	// �ԉ�
	if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 2]++;
	}
	
	if(masnGrade[player] >= 19) {
		// YOU ARE GRAND MASTER!!
		param[0] = 1;
	} else {
		// EXCELLENT
		param[0] = 0;
		printTinyFont(foffset[player] + 20, fyoffset[player] + 116, "MASTER MODE");
		printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
		
		printTinyFont(foffset[player] + 10, fyoffset[player] + 151, "TRY AGAIN TO BE");
		printTinyFont(foffset[player] + 12, fyoffset[player] + 158, "A GRAND MASTER");
	}
}

// �Q�[���I�[�o�[�����̍ŏ�
void masnGameOver(int player) {
	// m���[�����s
	if((hidden[player] == 10) && (statc[player * 10 + 2] == 0) && (masnGrade[player] < 18)) {
		PlaySE(se_rankup);
		masnGrade[player] = 18;
		masnGFlash[player] = 120;
	}
}

// ���ʕ\��
void masnResult(int player) {
	if(statc[player * 10] == 0) {
		// �����L���O�o�^
		statc[player * 10 + 1] = masnRegistRanking(player);
		statc[player * 10 + 2] = masnUpdateSectionTimeRanking(player);
		if((statc[player * 10 + 1] != -1) || (statc[player * 10 + 2] != 0)) masnSaveRanking(player);
		
		// ���i�ʔ���
		statc[player * 10 + 3] = checkSecretGrade(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 45, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 59, "GRADE");
	sprintf(string[0], "%13s", masnStrGradeName[masnGrade[player]]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 67, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "SCORE");
	sprintf(string[0], "%13d", masnScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", masnLevel[player]);
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
	
	if(statc[player * 10 + 2] != 0) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 159, "ST RECORDS");
		sprintf(string[0], "%13d", statc[player * 10 + 2]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
	}
	
	if(statc[player * 10 + 3] >= 4) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 179, "SECRET GRADE");
		sprintf(string[0], "%13s", masnStrSecretGradeName[statc[player * 10 + 3]]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 187, string[0], 0);
	}
}

// �ݒ���
void masnSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(masnLoadConfig() == 0) masnSaveConfig();
	
	// �����L���O��ǂݍ���
	if(masnLoadRanking(player) == 0) masnInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "MASTER-NORMAL OPTIONS", 4);
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
		if(!masnIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!masnBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(masnGhost == 0) sprintf(string[0], "LV100");
		else if(masnGhost == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(!masnLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(!masn20G) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		sprintf(string[0], "%d", masnStartLevel);
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
			
			if(cursor == 0) masnIsBig = !masnIsBig;
			if(cursor == 1) masnBigMove = !masnBigMove;
			if(cursor == 2) {
				masnGhost = masnGhost + move;
				if(masnGhost < 0) masnGhost = 2;
				if(masnGhost > 2) masnGhost = 0;
			}
			if(cursor == 3) masnLvUpBonus = !masnLvUpBonus;
			if(cursor == 4) masn20G = !masn20G;
			if(cursor == 5) {
				masnStartLevel = masnStartLevel + (move * 100);
				if(masnStartLevel < 0) masnStartLevel = 900;
				if(masnStartLevel > 900) masnStartLevel = 0;
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
			masnSaveConfig();
			return;
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			masnViewRanking(player);
		}
	}
}

// �ݒ��ۑ�
void masnSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x5453414D;
	saveBuf[3] = 0x314E5245;
	
	// �ݒ���e
	saveBuf[4] = masnIsBig;
	saveBuf[5] = masnBigMove;
	saveBuf[6] = masnGhost;
	saveBuf[7] = masnLvUpBonus;
	saveBuf[8] = masn20G;
	saveBuf[9] = masnStartLevel;
	
	SaveFile("config/MASTER_NORMAL_CONFIG.SAV", &saveBuf, 100 * 4);
}

// �ݒ��ǂݍ���
int masnLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/MASTER_NORMAL_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x5453414D) return 0;
	if(saveBuf[3] != 0x314E5245) return 0;
	
	// �ݒ���e
	masnIsBig = saveBuf[4];
	masnBigMove = saveBuf[5];
	masnGhost = saveBuf[6];
	masnLvUpBonus = saveBuf[7];
	masn20G = saveBuf[8];
	masnStartLevel = saveBuf[9];
	
	return 1;
}

// ���v���C�ۑ�
void masnSaveReplay(int player) {
	saveBuf[900] = masnIsBig;
	saveBuf[901] = masnBigMove;
	saveBuf[902] = masnGhost;
	saveBuf[903] = masnLvUpBonus;
	saveBuf[904] = masnLevel[player];
	saveBuf[905] = masnScore[player];
	saveBuf[906] = masnGrade[player];
	saveBuf[907] = masnVersion;
	saveBuf[908] = masn20G;
	saveBuf[909] = masnStartLevel;
}

// ���v���C�ǂݍ���
void masnLoadReplay(int player) {
	masnIsBig = saveBuf[900];
	masnBigMove = saveBuf[901];
	masnGhost = saveBuf[902];
	masnLvUpBonus = saveBuf[903];
	masnVersion = saveBuf[907];
	masn20G = saveBuf[908];
	masnStartLevel = saveBuf[909];
	
	masnPlayerInitial(player);	// �ݒ�𔽉f������
}

// ���v���C�ڍ�
void masnReplayDetail() {
	printFontGrid(1, 5, "GRADE", 0);
	if((saveBuf[906] >= 0) && (saveBuf[906] <= 19)) {
		printFontGrid(22, 5, masnStrGradeName[saveBuf[906]], 0);
	} else {
		printFontGrid(22, 5, "???", 0);
	}
	
	printFontGrid(1, 6, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[905]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[904]);
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 9, "BIG", 0);
	if(!saveBuf[900]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "BIG MOVE", 0);
	if(!saveBuf[901]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "GHOST BLOCK", 0);
	if(saveBuf[902] == 0) sprintf(string[0], "LV100");
	else if(saveBuf[902] == 1) sprintf(string[0], "ON");
	else sprintf(string[0], "OFF");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "LEVEL UP BONUS", 0);
	if(!saveBuf[903]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 12, string[0], 0);
	
	printFontGrid(1, 13, "20G MODE", 0);
	if(!saveBuf[908]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 13, string[0], 0);
	
	printFontGrid(1, 14, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[909]);
	printFontGrid(22, 14, string[0], 0);
	
	printFontGrid(1, 15, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[907]);
	printFontGrid(22, 15, string[0], 0);
}

// �����L���O�ۑ�
void masnSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �m�[�}�������L���O
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0]  = masnRankingGrade[i];
		saveBuf[1 + (i * 20) + 1]  = masnRankingLevel[i];
		saveBuf[1 + (i * 20) + 2]  = masnRankingTime[i];
		saveBuf[1 + (i * 20) + 3]  = masnRankingEnd[i];
		saveBuf[1 + (i * 20) + 4]  = masnRankingMedal[i * 6 + 0];
		saveBuf[1 + (i * 20) + 5]  = masnRankingMedal[i * 6 + 1];
		saveBuf[1 + (i * 20) + 6]  = masnRankingMedal[i * 6 + 2];
		saveBuf[1 + (i * 20) + 7]  = masnRankingMedal[i * 6 + 3];
		saveBuf[1 + (i * 20) + 8]  = masnRankingMedal[i * 6 + 4];
		saveBuf[1 + (i * 20) + 9]  = masnRankingMedal[i * 6 + 5];
		saveBuf[1 + (i * 20) + 10] = masnRankingYear[i];
		saveBuf[1 + (i * 20) + 11] = masnRankingMonth[i];
		saveBuf[1 + (i * 20) + 12] = masnRankingDay[i];
		saveBuf[1 + (i * 20) + 13] = masnRankingHour[i];
		saveBuf[1 + (i * 20) + 14] = masnRankingMinute[i];
		saveBuf[1 + (i * 20) + 15] = masnRankingSecond[i];
	}
	
	// �Z�N�V�����^�C�������L���O
	for(i = 0; i < 10; i++) {
		saveBuf[221 + (i * 10) + 0] = masnRankingSectionTime[i];
		saveBuf[221 + (i * 10) + 1] = masnRankingSectionEnd[i];
		saveBuf[221 + (i * 10) + 2] = masnRankingSectionYear[i];
		saveBuf[221 + (i * 10) + 3] = masnRankingSectionMonth[i];
		saveBuf[221 + (i * 10) + 4] = masnRankingSectionDay[i];
		saveBuf[221 + (i * 10) + 5] = masnRankingSectionHour[i];
		saveBuf[221 + (i * 10) + 6] = masnRankingSectionMinute[i];
		saveBuf[221 + (i * 10) + 7] = masnRankingSectionSecond[i];
	}
	
	sprintf(string[0], "config/MASTER_NORMAL_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 331 * 4);
}

// �����L���O�ǂݍ���
int masnLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/MASTER_NORMAL_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 331 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �m�[�}�������L���O
	for(i = 0; i < 10; i++) {
		masnRankingGrade[i]         = saveBuf[1 + (i * 20) + 0];
		masnRankingLevel[i]         = saveBuf[1 + (i * 20) + 1];
		masnRankingTime[i]          = saveBuf[1 + (i * 20) + 2];
		masnRankingEnd[i]           = saveBuf[1 + (i * 20) + 3];
		masnRankingMedal[i * 6 + 0] = saveBuf[1 + (i * 20) + 4];
		masnRankingMedal[i * 6 + 1] = saveBuf[1 + (i * 20) + 5];
		masnRankingMedal[i * 6 + 2] = saveBuf[1 + (i * 20) + 6];
		masnRankingMedal[i * 6 + 3] = saveBuf[1 + (i * 20) + 7];
		masnRankingMedal[i * 6 + 4] = saveBuf[1 + (i * 20) + 8];
		masnRankingMedal[i * 6 + 5] = saveBuf[1 + (i * 20) + 9];
		masnRankingYear[i]          = saveBuf[1 + (i * 20) + 10];
		masnRankingMonth[i]         = saveBuf[1 + (i * 20) + 11];
		masnRankingDay[i]           = saveBuf[1 + (i * 20) + 12];
		masnRankingHour[i]          = saveBuf[1 + (i * 20) + 13];
		masnRankingMinute[i]        = saveBuf[1 + (i * 20) + 14];
		masnRankingSecond[i]        = saveBuf[1 + (i * 20) + 15];
	}
	
	// �Z�N�V�����^�C�������L���O
	for(i = 0; i < 10; i++) {
		masnRankingSectionTime[i]   = saveBuf[221 + (i * 10) + 0];
		masnRankingSectionEnd[i]    = saveBuf[221 + (i * 10) + 1];
		masnRankingSectionYear[i]   = saveBuf[221 + (i * 10) + 2];
		masnRankingSectionMonth[i]  = saveBuf[221 + (i * 10) + 3];
		masnRankingSectionDay[i]    = saveBuf[221 + (i * 10) + 4];
		masnRankingSectionHour[i]   = saveBuf[221 + (i * 10) + 5];
		masnRankingSectionMinute[i] = saveBuf[221 + (i * 10) + 6];
		masnRankingSectionSecond[i] = saveBuf[221 + (i * 10) + 7];
	}
	
	return 1;
}

// �����L���O������
void masnInitRanking() {
	int i;
	
	// �m�[�}�������L���O
	for(i = 0; i < 10; i++) {
		masnRankingGrade[i]         = 0;
		masnRankingLevel[i]         = 0;
		masnRankingTime[i]          = 0;
		masnRankingEnd[i]           = 0;
		masnRankingMedal[i * 6 + 0] = 0;
		masnRankingMedal[i * 6 + 1] = 0;
		masnRankingMedal[i * 6 + 2] = 0;
		masnRankingMedal[i * 6 + 3] = 0;
		masnRankingMedal[i * 6 + 4] = 0;
		masnRankingMedal[i * 6 + 5] = 0;
		masnRankingYear[i]          = 0;
		masnRankingMonth[i]         = 0;
		masnRankingDay[i]           = 0;
		masnRankingHour[i]          = 0;
		masnRankingMinute[i]        = 0;
		masnRankingSecond[i]        = 0;
	}
	
	// �Z�N�V�����^�C�������L���O
	for(i = 0; i < 10; i++) {
		masnRankingSectionTime[i]   = 5400;
		masnRankingSectionEnd[i]    = 0;
		masnRankingSectionYear[i]   = 0;
		masnRankingSectionMonth[i]  = 0;
		masnRankingSectionDay[i]    = 0;
		masnRankingSectionHour[i]   = 0;
		masnRankingSectionMinute[i] = 0;
		masnRankingSectionSecond[i] = 0;
	}
}

// �����L���O�o�^
int masnRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (masnLvUpBonus) || (masn20G) || (masnStartLevel)) return -1;
	
	for(i = 0; i < 10; i++) {
		// �����N�C��
		if(
		    (masnEndFlag[player] > masnRankingEnd[i]) || 
		    ((masnEndFlag[player] == masnRankingEnd[i]) && (masnGrade[player] > masnRankingGrade[i])) || 
		    ((masnEndFlag[player] == masnRankingEnd[i]) && (masnGrade[player] == masnRankingGrade[i]) && (gameTimer[player] < masnRankingTime[i]))
		  )
		{
			// �����L���O�����炷
			for(j = 9; j > i; j--) {
				masnRankingGrade[j]         = masnRankingGrade[j - 1];
				masnRankingLevel[j]         = masnRankingLevel[j - 1];
				masnRankingTime[j]          = masnRankingTime[j - 1];
				masnRankingEnd[j]           = masnRankingEnd[j - 1];
				masnRankingMedal[j * 6 + 0] = masnRankingMedal[(j - 1) * 6 + 0];
				masnRankingMedal[j * 6 + 1] = masnRankingMedal[(j - 1) * 6 + 1];
				masnRankingMedal[j * 6 + 2] = masnRankingMedal[(j - 1) * 6 + 2];
				masnRankingMedal[j * 6 + 3] = masnRankingMedal[(j - 1) * 6 + 3];
				masnRankingMedal[j * 6 + 4] = masnRankingMedal[(j - 1) * 6 + 4];
				masnRankingMedal[j * 6 + 5] = masnRankingMedal[(j - 1) * 6 + 5];
				masnRankingYear[j]          = masnRankingYear[j - 1];
				masnRankingMonth[j]         = masnRankingMonth[j - 1];
				masnRankingDay[j]           = masnRankingDay[j - 1];
				masnRankingHour[j]          = masnRankingHour[j - 1];
				masnRankingMinute[j]        = masnRankingMinute[j - 1];
				masnRankingSecond[j]        = masnRankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			masnRankingGrade[i]         = masnGrade[player];
			masnRankingLevel[i]         = masnLevel[player];
			masnRankingTime[i]          = gameTimer[player];
			masnRankingEnd[i]           = masnEndFlag[player];
			masnRankingMedal[i * 6 + 0] = masnMedalStat[player * 6 + 0];
			masnRankingMedal[i * 6 + 1] = masnMedalStat[player * 6 + 1];
			masnRankingMedal[i * 6 + 2] = masnMedalStat[player * 6 + 2];
			masnRankingMedal[i * 6 + 3] = masnMedalStat[player * 6 + 3];
			masnRankingMedal[i * 6 + 4] = masnMedalStat[player * 6 + 4];
			masnRankingMedal[i * 6 + 5] = masnMedalStat[player * 6 + 5];
			
			GetDateAndTime(&timebuf);
			masnRankingYear[i]          = timebuf[0];
			masnRankingMonth[i]         = timebuf[1];
			masnRankingDay[i]           = timebuf[2];
			masnRankingHour[i]          = timebuf[4];
			masnRankingMinute[i]        = timebuf[5];
			masnRankingSecond[i]        = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �Z�N�V�����^�C�������L���O�X�V
int masnUpdateSectionTimeRanking(int player) {
	int i, timebuf[8], result;
	result = 0;
	
	if((playback) || (IsBig[player]) || (masnLvUpBonus) || (masn20G) || (masnStartLevel)) return 0;
	
	for(i = 0; i < 10; i++) {
		if((masnSectionTime[i + player * 10] < masnRankingSectionTime[i]) && (masnSectionTime[i + player * 10] != 0)) {
			result++;
			
			masnRankingSectionTime[i] = masnSectionTime[i + player * 10];
			masnRankingSectionEnd[i] = masnEndFlag[player];
			
			GetDateAndTime(&timebuf);
			masnRankingSectionYear[i] = timebuf[0];
			masnRankingSectionMonth[i] = timebuf[1];
			masnRankingSectionDay[i] = timebuf[2];
			masnRankingSectionHour[i] = timebuf[4];
			masnRankingSectionMinute[i] = timebuf[5];
			masnRankingSectionSecond[i] = timebuf[6];
		}
	}
	
	return result;
}

// �����L���O�\��
void masnViewRanking(int player) {
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
			printFontGrid(1, 1, "MASTER-NORMAL MODE RANKING >>", 6);
			printFontGrid(1, 3, "RANK GRADE LEVEL TIME", 4);
			
			for(i = 0; i < 10; i++) {
				if(masnRankingEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (masnRankingEnd[i] - 1) * 2, 320, 2);
				
				if(i == 0) sprintf(string[0], " 1ST");
				if(i == 1) sprintf(string[0], " 2ND");
				if(i == 2) sprintf(string[0], " 3RD");
				if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
				printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
				
				if((masnRankingGrade[i] >= 0) && (masnRankingGrade[i] < 20)) {
					printFontGrid(6, 4 + i, masnStrGradeName[masnRankingGrade[i]], 7 * (cursor == i));
				} else {
					printFontGrid(6, 4 + i, "???", 7 * (cursor == i));
				}
				
				sprintf(string[0], "%d", masnRankingLevel[i]);
				printFontGrid(12, 4 + i, string[0], 7 * (cursor == i));
				
				getTime(masnRankingTime[i]);
				printFontGrid(18, 4 + i, string[0], 7 * (cursor == i));
			}
			
			for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
			
			if(!erasemode) {
				// ���_��
				for(i = 0; i < 6; i++) masnDrawMedal(8 + i * 16, 192, i, masnRankingMedal[cursor * 6 + i], -1);
				
				// ���t�Ǝ���
				sprintf(string[0],
				        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
				        masnRankingYear[cursor], masnRankingMonth[cursor], masnRankingDay[cursor],
				        masnRankingHour[cursor], masnRankingMinute[cursor], masnRankingSecond[cursor]);
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
					masnInitRanking();
					masnSaveRanking(player);
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
			printFontGrid(1, 1, "<< MASTER-NORMAL MODE SECTION TIME", 6);
			printFontGrid(1, 3, "SECTION TIME     DATE", 4);
			printFontGrid(1, 28, "A/B:EXIT", 6);
			
			for(i = 0; i < 10; i++) {
				if(masnRankingSectionEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (masnRankingSectionEnd[i] - 1) * 2, 320, 2);
				
				sprintf(string[0], "%3d-%3d", i * 100, ((i + 1) * 100) - 1);
				printFontGrid(1, 4 + i, string[0], 0);
				
				getTime(masnRankingSectionTime[i]);
				printFontGrid(9, 4 + i, string[0], 0);
				
				temp = (masnRankingSectionYear[i] / 1000) * 1000;	// �N����2�������\��
				if(temp == 0) temp = 1;
				sprintf(string[0], "%02d/%02d/%02d", masnRankingSectionYear[i] % temp, masnRankingSectionMonth[i], masnRankingSectionDay[i]);
				printFontGrid(18, 4 + i, string[0], 0);
				
				sprintf(string[0], "%02d:%02d:%02d", masnRankingSectionHour[i], masnRankingSectionMinute[i], masnRankingSectionSecond[i]);
				printFontGrid(27, 4 + i, string[0], 0);
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
