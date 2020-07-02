//prefix:mase

//������������������������������������������������������������������������������
//
//    MASTER-EXTRA
//
//������������������������������������������������������������������������������

//������������������������������������������������������������������������������
//   �O���[�o���ϐ��̒�`
//������������������������������������������������������������������������������
// �V�X�e��
int maseModeNo = -1;				// ���[�h�ԍ�
int maseVersion;					// �o�[�W�����ԍ��i�Â����v���C�Đ��p�j
int maseCVersion = 0;				// ���݂̃o�[�W����

// ���x��
int maseLevel;						// ���݂̕\����̃��x��
int maseSLevel;						// �����̃��x���i�Z�N�V����COOL��+100�j
int maseSpeedIndex;					// ���݂̗������x�ԍ�

// �i��
int maseGrade;						// ���݂̒i��
int maseClass;						// �����i��
int maseGPoint;						// ���݂̓����|�C���g
int maseGTimer;						// �����|�C���g�����^�C�}�[
int maseGUpCount;					// ���̃Z�N�V�����ő������������i�ʂ̐�
int maseFinalGrade;					// �ŏI�I�Ȏb��i��

// �Z�N�V�����^�C��
int maseSTimer;						// �Z�N�V�����^�C�}�[
int masePreSTimer;					// �O�̃Z�N�V�����̃Z�N�V�����^�C��
int maseSCoolCount;					// �Z�N�V�����^�C��COOL��
int maseSCoolFlag;					// �Z�N�V�����^�C��COOL�̔�����������ǂ����̃t���O
int maseSectionTime[10];			// ���̃v���C�̃Z�N�V�����^�C��

// �G���f�B���O
int maseEndFlag;					// ���S�N���A�t���O
int maseEndHeboris;					// ���[�����̃w�{���X��
int maseEndLines;					// ���[�����ɏ��������C����

// BGM
int maseBgmIndex;					// ���݂�BGM�ԍ�

// ���_��
int maseMedalStat[4];				// ���_���̏��(0=�Ȃ� 1=�� 2=�� 3=��)
int maseMedalAnim[4];				// ���_���l���A�j���[�V�����p�J�E���^
int maseSkill;						// ���v�w�{���X��

// ��ʕ\��
int maseScore;						// �X�R�A
int maseSHeboris;					// �P�Z�N�V�������ɍs�����w�{���X��
int maseHeboCombo;					// �A���w�{���X��
int maseTSpinCombo;					// �A��T-SPIN��
int maseTSpinFrame;					// T-SPIN�\���̎c�莞��
int maseCoolFrame;					// COOL�\���̎c�莞��
int maseRegretFrame;				// REGRET�\���̎c�莞��

// �ݒ�
int maseIsBig = 0;					// BIG���ǂ���
int maseBigMove = 1;				// BIG���̉��ړ��P��
int maseGhost = 0;					// �S�[�X�g�̐ݒ�i0=LV0-99 1=���ON 2=���OFF�j
int maseLvUpBonus = 1;				// ���x���A�b�v�{�[�i�X
int maseTSpin = 1;					// T-SPIN�̎��
int maseTorikan = 25200;			// LV500�Ƃ�J����^�C�� (7:00:00)
int mase20G = 0;					// 20G���[�h

// �����L���O�ϐ�
int maseRankingGrade[10];			// �i��
int maseRankingLevel[10];			// ���x��
int maseRankingTime[10];			// �^�C��
int maseRankingEnd[10];				// �N���A�t���O
int maseRankingMedal[4 * 10];		// ���_��
int maseRankingYear[10];			// �����N�C�������i�N�j
int maseRankingMonth[10];			// �����N�C�������i���j
int maseRankingDay[10];				// �����N�C�������i���j
int maseRankingHour[10];			// �����N�C�������i���j
int maseRankingMinute[10];			// �����N�C�������i���j
int maseRankingSecond[10];			// �����N�C�������i�b�j

// �Z�N�V�����^�C�������L���O�ϐ�
int maseRankingSectionTime[10];		// �^�C��
int maseRankingSectionLevel[10];	// ���x��
int maseRankingSectionEnd[10];		// �N���A�t���O
int maseRankingSectionYear[10];		// �����N�C�������i�N�j
int maseRankingSectionMonth[10];	// �����N�C�������i���j
int maseRankingSectionDay[10];		// �����N�C�������i���j
int maseRankingSectionHour[10];		// �����N�C�������i���j
int maseRankingSectionMinute[10];	// �����N�C�������i���j
int maseRankingSectionSecond[10];	// �����N�C�������i�b�j

//������������������������������������������������������������������������������
//   ���x���A�b�v�e�[�u��
//������������������������������������������������������������������������������
// ���x
int maseLevelTable[30] =
{
	4, 6, 8, 10, 12, 16, 32, 48, 64, 80, 96, 112, 128, 144, 4, 32, 64, 96, 128, 160,
	192, 224, 256, 512, 768, 1024, 1280, 1024, 768, 5120
};

// ���x���ς�郌�x��
int maseLevelChange[30] = 
{
	30, 35, 40, 50, 60, 70, 80, 90, 100, 120, 140, 160, 170, 200, 220, 230, 233, 236, 239, 243,
	247, 251, 300, 330, 360, 400, 420, 450, 500, 10000
};

// wait�l              0, 500, 600, 700, 800, 900,1000,1100,1200
int maseWait1[9] = {  25,  25,  25,  16,  12,  12,   6,   5,   4};
int maseWait2[9] = {  40,  25,  16,  12,   6,   6,   6,   6,   6};
int maseWait3[9] = {  30,  30,  30,  30,  30,  17,  17,  15,  15};
int maseWaitt[9] = {  14,   8,   8,   8,   8,   6,   6,   6,   6};
int maseWait5[9] = {  25,  25,  16,  12,   6,   6,   6,   5,   4};

// �Z�N�V����COOL�K��^�C��
int maseSectionCoolTable[9] = {52*60, 52*60, 49*60, 45*60, 45*60, 42*60, 42*60, 38*60, 38*60};

// �Z�N�V����REGRET�K��^�C��
int maseSectionRegretTable[10] = {5400, 4500, 4500, 4080, 3600, 3600, 3000, 3000, 3000, 3000};

//������������������������������������������������������������������������������
//   �����i�ʃe�[�u��
//������������������������������������������������������������������������������
// �i�ʃ|�C���g�㏸�e�[�u��
int maseGradePoint1[11] = {10,10,10,10,10, 5, 5, 5, 5, 5, 2};
int maseGradePoint2[11] = {20,20,20,15,15,15,10,10,10,10,12};
int maseGradePoint3[11] = {40,30,30,30,20,20,20,15,15,15,13};
int maseGradePoint4[11] = {50,40,40,40,40,30,30,30,30,30,30};

// �R���{�̔{��
int maseGradeCombo[11 * 4] = 
{
//    0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 120, 120, 120, 120, 120, 120, 120, 120, 150,
	100, 100, 140, 150, 160, 170, 180, 190, 200, 210, 250,
	100, 100, 150, 180, 200, 220, 230, 240, 250, 260, 300,
};

// �i�ʃ|�C���g��1����܂ł̎���
int maseGradeTimeLimit[32] = 
{
	125, 80, 80, 50, 45, 45, 45, 45, 40, 40, 40, 40, 30, 30, 30, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 10
};

// �b��i�ʂ�����������i��
int maseGradeNorm[17] = 
{
	1, 2, 3, 4, 5, 7, 9, 12, 15, 18, 19, 20, 23, 25, 27, 29, 31
};

// �i�ʂ̕\����
str maseStrGradeName[33] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0�` 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9�`17
	"M1", "M2", "M3", "M4", "M5", "M6", "M7", "M8", "M9",	// 18�`26
	 "M", "MK", "MV", "MO", "MM", "GM"						// 27�`32
};

// ���i�ʂ̕\����
str maseStrSecretGradeName[19] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0�` 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9�`17
	"GM"													// 18
};

//������������������������������������������������������������������������������
//   BGM�e�[�u��
//������������������������������������������������������������������������������
int maseBgmNo[4]     = {0,1,2,6};				// BGM�ԍ��i000-499�A500-699�A700-899�A999�j
int maseFadeLv[3]    = {485,685,10000};			// BGM���t�F�[�h�A�E�g�����郌�x��
int maseBgmChange[3] = {500,700,10000};			// BGM��؂�ւ��郌�x��

//������������������������������������������������������������������������������
//   �C�x���g�������̃��C���֐�
//������������������������������������������������������������������������������
void masePluginEvent(int player, int event, int *param) {
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != maseModeNo)) return;
	
	if(event == 0) {
		maseModeNo = addModePlugin("MASTER-EXTRA");	// ���[�h��o�^����
	} else if(event == 7) {
		if(!ending[player]) maseMoveInit(player);	// �u���b�N�o��
	} else if(event == 12) {
		if(!ending[player]) maseCalcScore(player, param[0]);	// �X�R�A�v�Z
		else maseCalcScore2(player, param[0]);
	} else if(event == 15) {
		maseViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		maseSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		masePlayerInitial(player);	// ����������
	} else if(event == 21) {
		maseResult(player, param);	// ���ʕ\��
	} else if(event == 24) {
		maseEndingStart(player);	// �G���f�B���O�˓�
	} else if(event == 25) {
		maseExcellent(player, param);	// �G���f�B���O�I��
	} else if(event == 28) {
		maseIncrementTime(player);	// ���Ԃ�i�߂�
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		maseSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		maseLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		maseLoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		maseReplayDetail();	// ���v���C�ڍ�
	} else if(event == 60) {
		maseInitCombo(player);	// �R���{������
	}
}

//������������������������������������������������������������������������������
//   ����������
//������������������������������������������������������������������������������
void masePlayerInitial(int player) {
	int i;
	
	// �o�[�W����
	if(!playback) maseVersion = maseCVersion;
	
	// �v���O�C�����̕ϐ���������
	maseLevel = -1;
	maseSLevel = -1;
	maseSpeedIndex = 0;
	maseGrade = 0;
	maseClass = 0;
	maseGPoint = 0;
	maseGTimer = 0;
	maseGUpCount = 0;
	maseFinalGrade = 0;
	maseSTimer = 0;
	masePreSTimer = 0;
	maseSCoolCount = 0;
	maseSCoolFlag = 0;
	maseEndFlag = 0;
	maseEndHeboris = 0;
	maseEndLines = 0;
	maseBgmIndex = 0;
	maseScore = 0;
	maseSHeboris = 0;
	maseHeboCombo = 0;
	maseTSpinCombo = 0;
	maseTSpinFrame = 0;
	maseCoolFrame = 0;
	maseRegretFrame = 0;
	maseSkill = 0;
	
	for(i = 0; i < 10; i++) maseSectionTime[i] = 0;
	
	for(i = 0; i < 4; i++) {
		maseMedalStat[i] = 0;
		maseMedalAnim[i] = -1;
	}
	
	// �V�X�e�����̕ϐ���ς���
	enable_combo[player] = 1;
	speedtype[player] = 2;
	bgmlv = maseBgmNo[0];
	backno = maseLevel / 100;
	
	// �Q�[���ݒ�𔽉f������
	maseApplyGameSetting(player);
}

//������������������������������������������������������������������������������
//   �Q�[���ݒ�𔽉f������
//������������������������������������������������������������������������������
void maseApplyGameSetting(int player) {
	IsBig[player] = maseIsBig;
	BigMove[player] = maseBigMove;
	if(maseGhost == 2) ghost[player] = 0;
	tspin_type[player] = maseTSpin;
	
	// �������x��ݒ�
	maseSpeedUp(player);
}

//������������������������������������������������������������������������������
//   �X�s�[�h�A�b�v
//������������������������������������������������������������������������������
void maseSpeedUp(int player) {
	int temp, secinlv;
	
	// �X�s�[�h��ς���
	if(mase20G) {
		sp[player] = 5120;
	} else {
		while(maseSLevel >= maseLevelChange[maseSpeedIndex]) maseSpeedIndex++;
		sp[player] = maseLevelTable[maseSpeedIndex];
	}
	
	// wait�l
	if(maseSLevel < 500) {
		wait1[player] = maseWait1[0];
		wait2[player] = maseWait2[0];
		wait3[player] = maseWait3[0];
		waitt[player] = maseWaitt[0];
		wait5[player] = maseWait5[0];
	} else {
		wait1[player] = maseWait1[(maseSLevel / 100) - 4];
		wait2[player] = maseWait2[(maseSLevel / 100) - 4];
		wait3[player] = maseWait3[(maseSLevel / 100) - 4];
		waitt[player] = maseWaitt[(maseSLevel / 100) - 4];
		wait5[player] = maseWait5[(maseSLevel / 100) - 4];
	}
	
	// �Z�N�V����COOL����
	secinlv = maseLevel - ((maseLevel / 100) * 100);	// ���x���̉�2��
	
	if((secinlv >= 70) && (maseLevel < 900) && (maseSCoolFlag == 0)) {
		maseSCoolFlag = 1;
		
		if( (maseSTimer <= maseSectionCoolTable[maseLevel / 100]) && ((maseSTimer <= masePreSTimer + 120) || (maseLevel < 100)) ) {
			maseSCoolFlag = 2;
		}
		
		// ���̃Z�N�V������LV70�ʉ߃^�C�����L�^
		masePreSTimer = maseSTimer;
	}
	
	// �Z�N�V����COOL�\��
	if((secinlv >= 82) && (maseSCoolFlag == 2)) {
		maseSCoolFlag = 3;
		maseCoolFrame = 180;
		PlaySE(se_cool);
	}
	
	// BGM�t�F�[�h�A�E�g
	temp = maseSLevel;
	if((maseSCoolFlag >= 2) && (secinlv >= 85)) temp = temp + 100;
	if((temp >= maseFadeLv[maseBgmIndex]) && (fadelv == 0)) fadelv = 1;
	
	// BGM�؂�ւ�
	temp = 0;
	while(maseSLevel >= maseBgmChange[maseBgmIndex]) {
		maseBgmIndex++;
		bgmlv = maseBgmNo[maseBgmIndex];
		if(onRecord[player]) temp = 1;
	}
	if(temp) PlayBGM();
	
	// �S�[�X�g������
	if((maseSLevel >= 100) && (maseGhost == 0)) ghost[player] = 0;
}

//������������������������������������������������������������������������������
//   �u���b�N�o�����̏���
//������������������������������������������������������������������������������
void maseMoveInit(int player) {
	int temp;
	
	// �ŏ��̃t���[���Ȃ�
	if(statc[player * 10 + 3] == 0) {
		// ���x���A�b�v����
		if(maseLevel >= 900) temp = 98;	// LV998
		else temp = 99;
		
		if(maseLevel % 100 != temp) {
			// ���x��+1
			maseLevel++;
			maseSLevel++;
			if(maseLevel > 999) maseLevel = 999;
			if(maseSLevel > 1200) maseSLevel = 1200;
			
			// ���x���X�g�b�v��
			if(maseLevel % 100 == temp) PlaySE(se_lvstop);
			
			// �X�s�[�h�A�b�v
			maseSpeedUp(player);
		}
	}
}

//������������������������������������������������������������������������������
//   �X�R�A�v�Z�i�ʏ펞�j
//������������������������������������������������������������������������������
void maseCalcScore(int player, int lines) {
	int temp, temp2, nextsec, secinlv, index, point, combobonus, lv, all;
	
	lv = maseLevel;	// �オ��O�̃��x��
	secinlv = maseLevel - ((maseLevel / 100) * 100);	// ���x���̉�2��
	
	// �w�{���X�񐔑���
	if(lines >= 4) {
		maseSkill++;
		maseSHeboris++;
		maseHeboCombo++;
		
		// SK���_���l��
		if((maseSkill == 15) || (maseSkill == 25) || (maseSkill == 40)) {
			PlaySE(se_medal);
			maseMedalStat[3]++;
			maseMedalAnim[3] = 0;
		}
		
		// �P�Z�N�V�������ɋK��񐔂̃w�{���X�ŋUCOOL
		if(secinlv < 94) {
			if(maseLevel <= 99) temp = 3;
			else if(maseLevel <= 199) temp = 6;
			else temp = 4;
			
			if(maseSHeboris >= temp) {
				maseSHeboris = 0;
				maseCoolFrame = 180;
				PlaySE(se_cool);
			}
		}
		
		// 3��A���w�{���X�ŋUCOOL
		if(maseHeboCombo == 3) {
			maseCoolFrame = 180;
			PlaySE(se_cool);
		}
	} else {
		maseHeboCombo = 0;
	}
	
	// �S����
	if(isBravo(player)) {
		all = 1;
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		
		// AC���_���l��
		if(maseMedalStat[1] < 3) {
			PlaySE(se_medal);
			maseMedalStat[1]++;
			maseMedalAnim[1] = 0;
		}
	} else {
		all = 0;
	}
	
	// CO���_���l��
	if(combo2[player] == 4) {
		if(maseMedalStat[2] < 1) {
			PlaySE(se_medal);
			maseMedalStat[2] = 1;
			maseMedalAnim[2] = 0;
		}
	} else if(combo2[player] == 5) {
		if(maseMedalStat[2] < 2) {
			PlaySE(se_medal);
			maseMedalStat[2] = 2;
			maseMedalAnim[2] = 0;
		}
	} else if(combo2[player] == 7) {
		if(maseMedalStat[2] < 3) {
			PlaySE(se_medal);
			maseMedalStat[2] = 3;
			maseMedalAnim[2] = 0;
		}
	}
	
	// T-SPIN
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		maseTSpinFrame = 120;
		
		// 2�A���ŋUCOOL
		maseTSpinCombo++;
		if(maseTSpinCombo == 2) {
			maseCoolFrame = 180;
			PlaySE(se_cool);
		}
		
		// T-SPIN�g���v���ŋUCOOL
		if(lines >= 3) {
			maseCoolFrame = 180;
			PlaySE(se_cool);
		}
	} else {
		maseTSpinCombo = 0;
	}
	
	// �����i�ʃ|�C���g���Z
	if(maseClass < 31) {
		index = maseClass;
		if(index > 10) index = 10;
		
		if(lines == 1) point = maseGradePoint1[index] * ((maseLevel / 250) + 1);
		if(lines == 2) point = maseGradePoint2[index] * ((maseLevel / 250) + 1);
		if(lines == 3) point = maseGradePoint3[index] * ((maseLevel / 250) + 1);
		if(lines >= 4) point = maseGradePoint4[index] * ((maseLevel / 250) + 1);
		
		combobonus = combo2[player];
		if(combobonus > 10) combobonus = 10;
		
		temp = (point * 10) * maseGradeCombo[combobonus + (lines - 1) * 11] / 1000;
		maseGPoint = maseGPoint + temp;
		
		// �����i�ʏ㏸
		if(maseGPoint >= 100) {
			maseGPoint = 0;
			maseGTimer = 0;
			maseClass++;
			maseGUpCount++;
			if(maseClass >= maseGradeNorm[maseGrade]) maseGrade++;
		}
	}
	
	// ���x���A�b�v
	nextsec = maseLevel / 100 * 100 + 100;	// ���̃Z�N�V����
	
	if(maseLvUpBonus) {
		maseLevel = maseLevel + lines + ((lines >= 3) * (lines - 2));
		maseSLevel = maseSLevel + lines + ((lines >= 3) * (lines - 2));
	} else {
		maseLevel = maseLevel + lines;
		maseSLevel = maseSLevel + lines;
	}
	
	// ���x���X�g�b�v��
	if(maseLevel >= 900) temp = 98;	// LV998
	else temp = 99;
	if(maseLevel % 100 == temp) PlaySE(se_lvstop);
	
	// ���̃Z�N�V����
	if((maseLevel >= nextsec) || (maseLevel >= 999)) {
		// REGRET����
		if(maseSTimer > maseSectionRegretTable[(nextsec / 100) - 1]) {
			PlaySE(se_regret);
			maseRegretFrame = 180;
			
			if(maseGUpCount >= 2) {
				maseGrade--;
				if(maseGrade < 0) maseGrade = 0;
				maseClass = maseGradeNorm[maseGrade] - 1;
				maseGPoint = 0;
				maseGTimer = 0;
			}
		}
		
		// �Z�N�V����COOL
		if(maseSCoolFlag >= 2) {
			maseSCoolCount++;
			maseSLevel = maseSLevel + 100;
			if(maseSLevel > 1200) maseSLevel = 1200;
		}
		
		// ST���_��
		maseMedalST(player, (nextsec / 100) - 1);
		
		// ���낢�돉����
		maseSTimer = 0;
		maseGUpCount = 0;
		maseSCoolFlag = 0;
		maseSHeboris = 0;
		
		if(maseLevel >= 999) {
			// �G���f�B���O
			maseLevel = 999;
			ending[player] = 1;
			timeOn[player] = 0;
			maseEndFlag = 1;
		} else if((nextsec == 500) && (gameTimer[player] > maseTorikan) && (maseTorikan > 0)) {
			// LV500�Ƃ�J��
			maseLevel = 500;
			ending[player] = 4;
			timeOn[player] = 0;
			resetStatc(player);
			stat[player] = 10;
			StopAllBGM();
		} else {
			// ���x���A�b�v��
			PlaySE(se_levelup);
			
			// �w�i�؂�ւ�
			bgfadesw = 1;
			bgfadebg = nextsec / 100;
		}
	}
	
	// �X�s�[�h�A�b�v
	maseSpeedUp(player);
	
	// �X�R�A���Z
	temp = wait3[player] - bactivetime[player];
	if(temp < 0) temp = 0;
	
	if(maseLvUpBonus) temp2 = lines + ((lines >= 3) * (lines - 2));
	else temp2 = lines;
	
	maseScore = maseScore + ((lv + lines) / 4 + qdrop[player] + (sdrop[player] / 2)) * temp2 * cmbpts[player] + temp + (maseLevel / 4) * (all + 1);
}

//������������������������������������������������������������������������������
//   �X�R�A�v�Z�i���[�����j
//������������������������������������������������������������������������������
void maseCalcScore2(int player, int lines) {
	// ���C��������
	maseEndLines = maseEndLines + lines;
	
	// �w�{���X�񐔑���
	if(lines >= 4) {
		maseEndHeboris++;
		maseHeboCombo++;
		
		// 3��A���w�{���X�ŋUCOOL
		if(maseHeboCombo == 3) {
			maseCoolFrame = 180;
			PlaySE(se_cool);
		}
	} else {
		maseHeboCombo = 0;
	}
	
	// T-SPIN
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		maseTSpinFrame = 120;
		
		// 2�A���ŋUCOOL
		maseTSpinCombo++;
		if(maseTSpinCombo == 2) {
			maseCoolFrame = 180;
			PlaySE(se_cool);
		}
		
		// T-SPIN�g���v���ŋUCOOL
		if(lines >= 3) {
			maseCoolFrame = 180;
			PlaySE(se_cool);
		}
	} else {
		maseTSpinCombo = 0;
	}
}

//������������������������������������������������������������������������������
//   ST���_���l��
//������������������������������������������������������������������������������
void maseMedalST(int player, int section) {
	// �Z�N�V�����^�C�����L�^
	maseSectionTime[section] = maseSTimer;
	
	// ST���_���l������
	if((!playback) && (!maseIsBig) && (maseLvUpBonus) && (!mase20G)) {
		if((maseSTimer < maseRankingSectionTime[section]) && (maseMedalStat[0] < 3)) {
			PlaySE(se_medal);
			maseMedalStat[0] = 3;
			maseMedalAnim[0] = 0;
		} else if((maseSTimer < maseRankingSectionTime[section] + 300) && (maseMedalStat[0] < 2)) {
			PlaySE(se_medal);
			maseMedalStat[0] = 2;
			maseMedalAnim[0] = 0;
		} else if((maseSTimer < maseRankingSectionTime[section] + 600) && (maseMedalStat[0] < 1)) {
			PlaySE(se_medal);
			maseMedalStat[0] = 1;
			maseMedalAnim[0] = 0;
		}
	}
}

//������������������������������������������������������������������������������
//   �R���{������
//������������������������������������������������������������������������������
void maseInitCombo(int player) {
	maseHeboCombo = 0;
	maseTSpinCombo = 0;
}

//������������������������������������������������������������������������������
//   ���Ԃ�i�߂�
//������������������������������������������������������������������������������
void maseIncrementTime(int player) {
	// �Z�N�V�����^�C������
	if(timeOn[player]) maseSTimer++;
	
	// �i�ʃ|�C���g������
	if((stat[player] == 4) && (maseGPoint > 0) && (!ending[player]) && (timeOn[player])) {
		if(combo2[player] == 0) maseGTimer++;
		
		if(maseGTimer >= maseGradeTimeLimit[maseClass]) {
			maseGTimer = 0;
			maseGPoint--;
		}
	}
	
	// ���[���I��
	if((ending[player] == 2) && (edrec[player] >= 3238)) {
		onRecord[player] = 0;
		ending[player] = 3;
		stat[player] = 10;
		maseEndFlag = 2;
		resetStatc(player);
		maseFinalGrade = maseCalcFinalGrade(player);
	}
}

//������������������������������������������������������������������������������
//   �G���f�B���O�˓�
//������������������������������������������������������������������������������
void maseEndingStart(int player) {
	resetStatc(player);
	
	if(maseLevel >= 999) {
		// �G���f�B���O
		ending[player] = 2;
		stat[player] = 4;
		ending_timeOn[player] = 1;
		
		if((maseGrade >= 15) && (maseSCoolCount >= 9)) {
			// �������[��
			hidden[player] = 9;
			shadowtime[player] = -60;
			objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
		} else {
			// �������[��
			hidden[player] = 8;
			shadowtime[player] = 300;
		}
		
		bgmlv = maseBgmNo[3];
		PlayBGM();
	} else {
		ending[player] = 3;
		onRecord[player] = 0;
	}
}

//������������������������������������������������������������������������������
//   �G���f�B���O�I��
//������������������������������������������������������������������������������
void maseExcellent(int player, int *param) {
	statc[player * 10 + 1]++;
	
	// ���S�N���A
	if(maseLevel >= 999) {
		if(statc[player * 10 + 1] == 1) {
			// �u���b�N��������悤�ɂ���
			if(hidden[player] == 9) hidden[player] = 0;
			else disableShadowTimer(player);
		}
		
		// �ԉ�
		if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 30)) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			statc[player * 10 + 2]++;
		}
		
		if(maseFinalGrade >= 32) {
			// YOU ARE GRAND MASTER!!
			param[0] = 1;
		} else {
			// EXCELLENT
			param[0] = 0;
			printTinyFont(foffset[player] + 20, fyoffset[player] + 116, "MASTER MODE");
			printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
		}
	}
	// �Ƃ�J��
	else {
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

//������������������������������������������������������������������������������
//   �ŏI�I�Ȏb��i�ʂ��Z�o
//������������������������������������������������������������������������������
int maseCalcFinalGrade(int player) {
	int result, endingpoint, allclear;
	
	// ���[�����̐���
	if(maseLevel >= 999) {
		if(hidden[player] == 9) {
			// �������[��
			if(maseEndFlag == 2) allclear = 16;
			else allclear = 0;
			endingpoint = (allclear + (maseEndHeboris * 6) + maseEndLines) / 10;
		} else {
			// �������[��
			if(maseEndFlag == 2) allclear = 50;
			else allclear = 0;
			endingpoint = (allclear + (maseEndHeboris * 10) + maseEndLines) / 100;
		}
	} else {
		endingpoint = 0;
	}
	
	result = maseGrade + maseSCoolCount + endingpoint;
	if(result > 32) result = 32;
	
	return result;
}

//������������������������������������������������������������������������������
//   ���ʕ\��
//������������������������������������������������������������������������������
void maseResult(int player, int *param) {
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
			
			// �i�ʂ��Z�o
			maseFinalGrade = maseCalcFinalGrade(player);
			
			// �����L���O�o�^
			statc[player * 10 + 2] = maseRegistRanking(player);
			statc[player * 10 + 3] = maseUpdateSectionTimeRanking(player);
			if((statc[player * 10 + 2] != -1) || (statc[player * 10 + 3] != 0)) maseSaveRanking(player);
			
			// ���i�ʔ���
			statc[player * 10 + 4] = checkSecretGrade(player);
		}
		
		// �i�ʕ\��
		if(maseFinalGrade < 9)		// 9�`1
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108,   0, ((count % 4 / 2) * 216) + (maseFinalGrade * 24), 90, 24);
		else if(maseFinalGrade < 18)	// S1�`S9
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108,  90, ((count % 4 / 2) * 216) + ((maseFinalGrade -  9) * 24), 90, 24);
		else if(maseFinalGrade < 27)	// m1�`m9
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108, 180, ((count % 4 / 2) * 216) + ((maseFinalGrade - 18) * 24), 90, 24);
		else if(maseFinalGrade < 32)	// M�`MM
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108, 270, ((count % 4 / 2) * 216) + ((maseFinalGrade - 27) * 24), 90, 24);
		else							// Gm
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108, 270, ((count % 4 / 2) * 216) + 120, 90, 48);
		
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
		sprintf(string[0], "%13d", maseScore);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 67, string[0], 0);
		
		printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LEVEL");
		sprintf(string[0], "%13d", maseLevel);
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
			sprintf(string[0], "%13s", maseStrSecretGradeName[statc[player * 10 + 4]]);
			printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
		}
	}
}

//������������������������������������������������������������������������������
//   �X�R�A�\��
//������������������������������������������������������������������������������
void maseViewScore(int player) {
	int i, x, y, color, kind, temp;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// ���_���i�ʏ�j
	for(i = 0; i < 4; i++) {
		if((maseMedalAnim[i] < 0) || (maseMedalAnim[i] > 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 17;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			if(i == 0) kind = 1;
			if(i == 1) kind = 0;
			if(i == 2) kind = 5;
			if(i == 3) kind = 2;
			maseDrawMedal(x, y, kind, maseMedalStat[i], maseMedalAnim[i]);
		}
	}
	
	// ���_���i�A�j�����j
	for(i = 0; i < 4; i++) {
		if((maseMedalAnim[i] >= 0) && (maseMedalAnim[i] <= 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 17;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			if(i == 0) kind = 1;
			if(i == 1) kind = 0;
			if(i == 2) kind = 5;
			if(i == 3) kind = 2;
			maseDrawMedal(x, y, kind, maseMedalStat[i], maseMedalAnim[i]);
			maseMedalAnim[i]++;
		}
	}
	
	// ���x���i���q�j
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(maseLevel == -1) sprintf(string[0], "%4d", 0);	// -1�Ȃ�0�ƕ\������(�����I�ɂ͍ŏ���-1�ɂȂ��Ă���)
	else sprintf(string[0], "%4d", maseLevel);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// ���x���i�����j
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	temp = sp[player] / 128;
	if(temp > 22) temp = 22;
	ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22 - temp, 143, 22, 1);
	
	// ���x���i����j
	if(maseLevel >= 900) sprintf(string[0], "%4d", 999);
	else sprintf(string[0], "%4d", maseLevel / 100 * 100 + 100);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, string[0], color);
	
	// �^�C��
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
	
	// T-SPIN/COOL/REGRET�\��
	if(maseTSpinFrame > 0) {
		maseTSpinFrame--;
		printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "T-SPIN");
	} else if(maseCoolFrame > 0) {
		maseCoolFrame--;
		printTinyFont(foffset[player] + 37, fyoffset[player] + 208, "COOL");
	} else if(maseRegretFrame > 0) {
		maseRegretFrame--;
		printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "REGRET");
	}
}

//������������������������������������������������������������������������������
//   ���_����\��
//������������������������������������������������������������������������������
void maseDrawMedal(int x, int y, int kind, int color, int anim) {
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

//������������������������������������������������������������������������������
//   BGM�ǂݍ���
//������������������������������������������������������������������������������
void maseLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 4; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/4)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(maseBgmNo[i]);
		}
	}
}

//������������������������������������������������������������������������������
//   �ݒ���
//������������������������������������������������������������������������������
void maseSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	maseLoadConfig();	// �ݒ��ǂݍ���
	
	if(!maseLoadRanking(player)) maseInitRanking();	// �����L���O�ǂݍ���
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "MASTER-EXTRA OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "BIG",            7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",       7 * (cursor == 1));
		printFontGrid(2, 5, "GHOST BLOCK",    7 * (cursor == 2));
		printFontGrid(2, 6, "LEVEL UP BONUS", 7 * (cursor == 3));
		printFontGrid(2, 7, "T-SPIN",         7 * (cursor == 4));
		printFontGrid(2, 8, "TIME LIMIT",     7 * (cursor == 5));
		printFontGrid(2, 9, "20G MODE",       7 * (cursor == 6));
		
		// �ݒ�l�\��
		if(!maseIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!maseBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(maseGhost == 0) sprintf(string[0], "LV100");
		else if(maseGhost == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(!maseLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(maseTSpin == 0) sprintf(string[0], "OFF");
		else if(maseTSpin == 1) sprintf(string[0], "LINE CLEAR");
		else if(maseTSpin == 2) sprintf(string[0], "IMMOBILE");
		else if(maseTSpin == 3) sprintf(string[0], "3-CORNER");
		else sprintf(string[0], "3-CORNER NO KICK");
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		if(!maseTorikan) sprintf(string[0], "OFF");
		else getTime(maseTorikan);
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		if(!mase20G) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
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
			
			if(cursor == 0) maseIsBig = !maseIsBig;
			if(cursor == 1) maseBigMove = !maseBigMove;
			if(cursor == 2) {
				maseGhost = maseGhost + move;
				if(maseGhost < 0) maseGhost = 2;
				if(maseGhost > 2) maseGhost = 0;
			}
			if(cursor == 3) maseLvUpBonus = !maseLvUpBonus;
			if(cursor == 4) {
				maseTSpin = maseTSpin + move;
				if(maseTSpin < 0) maseTSpin = 4;
				if(maseTSpin > 4) maseTSpin = 0;
			}
			if(cursor == 5) {
				maseTorikan = maseTorikan + (move * 60);
				if(maseTorikan < 0) maseTorikan = 72000;
				if(maseTorikan > 72000) maseTorikan = 0;
			}
			if(cursor == 6) mase20G = !mase20G;
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
			maseSaveConfig();	// �ݒ��ۑ�
			return;
		}
		
		// �����L���O�\��
		if(getPushState(player, 8)) {
			maseViewRanking(player);
		}
	}
}

//������������������������������������������������������������������������������
//   �ݒ��ۑ�
//������������������������������������������������������������������������������
void maseSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �ݒ���e
	saveBuf[1] = maseIsBig;
	saveBuf[2] = maseBigMove;
	saveBuf[3] = maseGhost;
	saveBuf[4] = maseLvUpBonus;
	saveBuf[5] = maseTSpin;
	saveBuf[6] = maseTorikan;
	saveBuf[7] = mase20G;
	
	SaveFile("config/MASTER_EXTRA_CONFIG.SAV", &saveBuf, 30 * 4);
}

//������������������������������������������������������������������������������
//   �ݒ��ǂݍ���
//������������������������������������������������������������������������������
int maseLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/MASTER_EXTRA_CONFIG.SAV", &saveBuf, 30 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �ݒ���e
	maseIsBig = saveBuf[1];
	maseBigMove = saveBuf[2];
	maseGhost = saveBuf[3];
	maseLvUpBonus = saveBuf[4];
	maseTSpin = saveBuf[5];
	maseTorikan = saveBuf[6];
	mase20G = saveBuf[7];
	
	return 1;
}

//������������������������������������������������������������������������������
//   ���v���C�ۑ�
//������������������������������������������������������������������������������
void maseSaveReplay(int player) {
	saveBuf[900] = maseIsBig;
	saveBuf[901] = maseBigMove;
	saveBuf[902] = maseGhost;
	saveBuf[903] = maseLvUpBonus;
	saveBuf[904] = maseTSpin;
	saveBuf[905] = maseTorikan;
	saveBuf[906] = maseLevel;
	saveBuf[907] = maseScore;
	saveBuf[908] = maseFinalGrade;
	saveBuf[909] = maseVersion;
	saveBuf[910] = mase20G;
}

//������������������������������������������������������������������������������
//   ���v���C�ǂݍ���
//������������������������������������������������������������������������������
void maseLoadReplay(int player) {
	maseIsBig = saveBuf[900];
	maseBigMove = saveBuf[901];
	maseGhost = saveBuf[902];
	maseLvUpBonus = saveBuf[903];
	maseTSpin = saveBuf[904];
	maseTorikan = saveBuf[905];
	maseVersion = saveBuf[909];
	mase20G = saveBuf[910];
	
	// �Q�[���ݒ�𔽉f������
	maseApplyGameSetting(player);
}

//������������������������������������������������������������������������������
//   ���v���C�ڍ�
//������������������������������������������������������������������������������
void maseReplayDetail() {
	printFontGrid(1, 5, "GRADE", 0);
	if((saveBuf[908] >= 0) && (saveBuf[908] <= 32)) {
		printFontGrid(22, 5, maseStrGradeName[saveBuf[908]], 0);
	} else {
		printFontGrid(22, 5, "???", 0);
	}
	
	printFontGrid(1, 6, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[907]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[906]);
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
	
	printFontGrid(1, 13, "T-SPIN", 0);
	if(saveBuf[904] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[904] == 1) sprintf(string[0], "LINE CLEAR");
	else if(saveBuf[904] == 2) sprintf(string[0], "IMMOBILE");
	else if(saveBuf[904] == 3) sprintf(string[0], "3-CORNER");
	else sprintf(string[0], "3-CORNER NO KICK");
	printFontGrid(22, 13, string[0], 0);
	
	printFontGrid(1, 14, "TIME LIMIT", 0);
	if(!saveBuf[905]) sprintf(string[0], "OFF");
	else getTime(saveBuf[905]);
	printFontGrid(22, 14, string[0], 0);
	
	printFontGrid(1, 15, "20G MODE", 0);
	if(!saveBuf[910]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 15, string[0], 0);
	
	printFontGrid(1, 17, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[909]);
	printFontGrid(22, 17, string[0], 0);
}

//������������������������������������������������������������������������������
//   �����L���O�ۑ�
//������������������������������������������������������������������������������
void maseSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �m�[�}�������L���O
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0]  = maseRankingGrade[i];
		saveBuf[1 + (i * 20) + 1]  = maseRankingLevel[i];
		saveBuf[1 + (i * 20) + 2]  = maseRankingTime[i];
		saveBuf[1 + (i * 20) + 3]  = maseRankingEnd[i];
		saveBuf[1 + (i * 20) + 4]  = maseRankingMedal[i * 4 + 0];
		saveBuf[1 + (i * 20) + 5]  = maseRankingMedal[i * 4 + 1];
		saveBuf[1 + (i * 20) + 6]  = maseRankingMedal[i * 4 + 2];
		saveBuf[1 + (i * 20) + 7]  = maseRankingMedal[i * 4 + 3];
		saveBuf[1 + (i * 20) + 8]  = maseRankingYear[i];
		saveBuf[1 + (i * 20) + 9]  = maseRankingMonth[i];
		saveBuf[1 + (i * 20) + 10] = maseRankingDay[i];
		saveBuf[1 + (i * 20) + 11] = maseRankingHour[i];
		saveBuf[1 + (i * 20) + 12] = maseRankingMinute[i];
		saveBuf[1 + (i * 20) + 13] = maseRankingSecond[i];
	}
	
	// �Z�N�V�����^�C�������L���O
	for(i = 0; i < 10; i++) {
		saveBuf[221 + (i * 10) + 0] = maseRankingSectionTime[i];
		saveBuf[221 + (i * 10) + 1] = maseRankingSectionLevel[i];
		saveBuf[221 + (i * 10) + 2] = maseRankingSectionEnd[i];
		saveBuf[221 + (i * 10) + 3] = maseRankingSectionYear[i];
		saveBuf[221 + (i * 10) + 4] = maseRankingSectionMonth[i];
		saveBuf[221 + (i * 10) + 5] = maseRankingSectionDay[i];
		saveBuf[221 + (i * 10) + 6] = maseRankingSectionHour[i];
		saveBuf[221 + (i * 10) + 7] = maseRankingSectionMinute[i];
		saveBuf[221 + (i * 10) + 8] = maseRankingSectionSecond[i];
	}
	
	sprintf(string[0], "config/MASTER_EXTRA_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 331 * 4);
}

//������������������������������������������������������������������������������
//   �����L���O�ǂݍ���
//������������������������������������������������������������������������������
int maseLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/MASTER_EXTRA_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 331 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �m�[�}�������L���O
	for(i = 0; i < 10; i++) {
		maseRankingGrade[i]         = saveBuf[1 + (i * 20) + 0];
		maseRankingLevel[i]         = saveBuf[1 + (i * 20) + 1];
		maseRankingTime[i]          = saveBuf[1 + (i * 20) + 2];
		maseRankingEnd[i]           = saveBuf[1 + (i * 20) + 3];
		maseRankingMedal[i * 4 + 0] = saveBuf[1 + (i * 20) + 4];
		maseRankingMedal[i * 4 + 1] = saveBuf[1 + (i * 20) + 5];
		maseRankingMedal[i * 4 + 2] = saveBuf[1 + (i * 20) + 6];
		maseRankingMedal[i * 4 + 3] = saveBuf[1 + (i * 20) + 7];
		maseRankingYear[i]          = saveBuf[1 + (i * 20) + 8];
		maseRankingMonth[i]         = saveBuf[1 + (i * 20) + 9];
		maseRankingDay[i]           = saveBuf[1 + (i * 20) + 10];
		maseRankingHour[i]          = saveBuf[1 + (i * 20) + 11];
		maseRankingMinute[i]        = saveBuf[1 + (i * 20) + 12];
		maseRankingSecond[i]        = saveBuf[1 + (i * 20) + 13];
	}
	
	// �Z�N�V�����^�C�������L���O
	for(i = 0; i < 10; i++) {
		maseRankingSectionTime[i]   = saveBuf[221 + (i * 10) + 0];
		maseRankingSectionLevel[i]  = saveBuf[221 + (i * 10) + 1];
		maseRankingSectionEnd[i]    = saveBuf[221 + (i * 10) + 2];
		maseRankingSectionYear[i]   = saveBuf[221 + (i * 10) + 3];
		maseRankingSectionMonth[i]  = saveBuf[221 + (i * 10) + 4];
		maseRankingSectionDay[i]    = saveBuf[221 + (i * 10) + 5];
		maseRankingSectionHour[i]   = saveBuf[221 + (i * 10) + 6];
		maseRankingSectionMinute[i] = saveBuf[221 + (i * 10) + 7];
		maseRankingSectionSecond[i] = saveBuf[221 + (i * 10) + 8];
	}
	
	return 1;
}

//������������������������������������������������������������������������������
//   �����L���O������
//������������������������������������������������������������������������������
void maseInitRanking() {
	int i;
	
	// �m�[�}�������L���O
	for(i = 0; i < 10; i++) {
		maseRankingGrade[i]         = 0;
		maseRankingLevel[i]         = 0;
		maseRankingTime[i]          = 0;
		maseRankingEnd[i]           = 0;
		maseRankingMedal[i * 4 + 0] = 0;
		maseRankingMedal[i * 4 + 1] = 0;
		maseRankingMedal[i * 4 + 2] = 0;
		maseRankingMedal[i * 4 + 3] = 0;
		maseRankingYear[i]          = 0;
		maseRankingMonth[i]         = 0;
		maseRankingDay[i]           = 0;
		maseRankingHour[i]          = 0;
		maseRankingMinute[i]        = 0;
		maseRankingSecond[i]        = 0;
	}
	
	// �Z�N�V�����^�C�������L���O
	for(i = 0; i < 10; i++) {
		maseRankingSectionTime[i]   = 5400;
		maseRankingSectionLevel[i]  = 0;
		maseRankingSectionEnd[i]    = 0;
		maseRankingSectionYear[i]   = 0;
		maseRankingSectionMonth[i]  = 0;
		maseRankingSectionDay[i]    = 0;
		maseRankingSectionHour[i]   = 0;
		maseRankingSectionMinute[i] = 0;
		maseRankingSectionSecond[i] = 0;
	}
}

//������������������������������������������������������������������������������
//   �����L���O�o�^
//������������������������������������������������������������������������������
int maseRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (maseIsBig) || (!maseLvUpBonus) || (mase20G)) return -1;
	
	for(i = 0; i < 10; i++) {
		// �����N�C��
		if(
		    (maseEndFlag > maseRankingEnd[i]) || 
		    ((maseEndFlag == maseRankingEnd[i]) && (maseFinalGrade > maseRankingGrade[i])) || 
		    ((maseEndFlag == maseRankingEnd[i]) && (maseFinalGrade == maseRankingGrade[i]) && (gameTimer < maseRankingTime[i]))
		  )
		{
			// �����L���O�����炷
			for(j = 9; j > i; j--) {
				maseRankingGrade[j]         = maseRankingGrade[j - 1];
				maseRankingLevel[j]         = maseRankingLevel[j - 1];
				maseRankingTime[j]          = maseRankingTime[j - 1];
				maseRankingEnd[j]           = maseRankingEnd[j - 1];
				maseRankingMedal[j * 4 + 0] = maseRankingMedal[(j - 1) * 4 + 0];
				maseRankingMedal[j * 4 + 1] = maseRankingMedal[(j - 1) * 4 + 1];
				maseRankingMedal[j * 4 + 2] = maseRankingMedal[(j - 1) * 4 + 2];
				maseRankingMedal[j * 4 + 3] = maseRankingMedal[(j - 1) * 4 + 3];
				maseRankingYear[j]          = maseRankingYear[j - 1];
				maseRankingMonth[j]         = maseRankingMonth[j - 1];
				maseRankingDay[j]           = maseRankingDay[j - 1];
				maseRankingHour[j]          = maseRankingHour[j - 1];
				maseRankingMinute[j]        = maseRankingMinute[j - 1];
				maseRankingSecond[j]        = maseRankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			maseRankingGrade[i]         = maseFinalGrade;
			maseRankingLevel[i]         = maseLevel;
			maseRankingTime[i]          = gameTimer[player];
			maseRankingEnd[i]           = maseEndFlag;
			maseRankingMedal[i * 4 + 0] = maseMedalStat[0];
			maseRankingMedal[i * 4 + 1] = maseMedalStat[1];
			maseRankingMedal[i * 4 + 2] = maseMedalStat[2];
			maseRankingMedal[i * 4 + 3] = maseMedalStat[3];
			
			GetDateAndTime(&timebuf);
			maseRankingYear[i]          = timebuf[0];
			maseRankingMonth[i]         = timebuf[1];
			maseRankingDay[i]           = timebuf[2];
			maseRankingHour[i]          = timebuf[4];
			maseRankingMinute[i]        = timebuf[5];
			maseRankingSecond[i]        = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

//������������������������������������������������������������������������������
//   �Z�N�V�����^�C�������L���O�X�V
//������������������������������������������������������������������������������
int maseUpdateSectionTimeRanking(int player) {
	int i, timebuf[8], result;
	result = 0;
	
	if((playback) || (maseIsBig) || (!maseLvUpBonus) || (mase20G)) return 0;
	
	for(i = 0; i < 10; i++) {
		if((maseSectionTime[i] < maseRankingSectionTime[i]) && (maseSectionTime[i] != 0)) {
			result++;
			
			maseRankingSectionTime[i] = maseSectionTime[i];
			maseRankingSectionLevel[i] = maseLevel;
			maseRankingSectionEnd[i] = maseEndFlag;
			
			GetDateAndTime(&timebuf);
			maseRankingSectionYear[i] = timebuf[0];
			maseRankingSectionMonth[i] = timebuf[1];
			maseRankingSectionDay[i] = timebuf[2];
			maseRankingSectionHour[i] = timebuf[4];
			maseRankingSectionMinute[i] = timebuf[5];
			maseRankingSectionSecond[i] = timebuf[6];
		}
	}
	
	return result;
}

//������������������������������������������������������������������������������
//   �����L���O�\��
//������������������������������������������������������������������������������
void maseViewRanking(int player) {
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
			printFontGrid(1, 1, "MASTER-EXTRA MODE RANKING >>", 6);
			printFontGrid(1, 3, "RANK GRADE LEVEL TIME", 4);
			
			for(i = 0; i < 10; i++) {
				if(maseRankingEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (maseRankingEnd[i] - 1) * 2, 320, 2);
				
				if(i == 0) sprintf(string[0], " 1ST");
				if(i == 1) sprintf(string[0], " 2ND");
				if(i == 2) sprintf(string[0], " 3RD");
				if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
				printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
				
				if((maseRankingGrade[i] >= 0) && (maseRankingGrade[i] < 33)) {
					printFontGrid(6, 4 + i, maseStrGradeName[maseRankingGrade[i]], 7 * (cursor == i));
				} else {
					printFontGrid(6, 4 + i, "???", 7 * (cursor == i));
				}
				
				sprintf(string[0], "%d", maseRankingLevel[i]);
				printFontGrid(12, 4 + i, string[0], 7 * (cursor == i));
				
				getTime(maseRankingTime[i]);
				printFontGrid(18, 4 + i, string[0], 7 * (cursor == i));
			}
			
			for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
			
			if(!erasemode) {
				// ���_��
				maseDrawMedal(8 + 0 * 16, 192, 1, maseRankingMedal[cursor * 4 + 0], -1);
				maseDrawMedal(8 + 1 * 16, 192, 0, maseRankingMedal[cursor * 4 + 1], -1);
				maseDrawMedal(8 + 2 * 16, 192, 5, maseRankingMedal[cursor * 4 + 2], -1);
				maseDrawMedal(8 + 3 * 16, 192, 2, maseRankingMedal[cursor * 4 + 3], -1);
				
				// ���t�Ǝ���
				sprintf(string[0],
				        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
				        maseRankingYear[cursor], maseRankingMonth[cursor], maseRankingDay[cursor],
				        maseRankingHour[cursor], maseRankingMinute[cursor], maseRankingSecond[cursor]);
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
					maseInitRanking();
					maseSaveRanking(player);
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
			printFontGrid(1, 1, "<< MASTER-EXTRA MODE SECTION TIME", 6);
			printFontGrid(1, 3, "SECTION TIME     LV  DATE", 4);
			printFontGrid(1, 28, "A/B:EXIT", 6);
			
			for(i = 0; i < 10; i++) {
				if(maseRankingSectionEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (maseRankingSectionEnd[i] - 1) * 2, 320, 2);
				
				sprintf(string[0], "%3d-%3d", i * 100, ((i + 1) * 100) - 1);
				printFontGrid(1, 4 + i, string[0], 0);
				
				getTime(maseRankingSectionTime[i]);
				printFontGrid(9, 4 + i, string[0], 0);
				
				sprintf(string[0], "%d", maseRankingSectionLevel[i]);
				printFontGrid(18, 4 + i, string[0], 0);
				
				temp = (maseRankingSectionYear[i] / 1000) * 1000;	// �N����2�������\��
				if(temp == 0) temp = 1;
				sprintf(string[0], "%02d/%02d/%02d", maseRankingSectionYear[i] % temp, maseRankingSectionMonth[i], maseRankingSectionDay[i]);
				printFontGrid(22, 4 + i, string[0], 0);
				
				sprintf(string[0], "%02d:%02d:%02d", maseRankingSectionHour[i], maseRankingSectionMinute[i], maseRankingSectionSecond[i]);
				printFontGrid(31, 4 + i, string[0], 0);
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
