//MASTER-HARD
//prefix:mash

// �o�[�W����
int mashVersion;		// �o�[�W�����ԍ��i�Â����v���C�Đ��p�j
int mashCVersion = 1;	// ���݂̃o�[�W����

// ���x���A�b�v�e�[�u��
int mashLevelTable[51] =	// �������x
{
//  *00, *10, *20, *30, *40, *50, *60, *70, *80, *90
	1  , 1  , 1  , 2  , 3  , 4  , 5  , 6  , 8  , 12 ,// 0**
	15 , 15 , 15 , 15 , 23 , 23 , 23 , 23 , 30 , 30 ,// 1**
	1  , 2  , 8  , 15 , 30 , 60 , 60 , 60 , 60 , 60 ,// 2**
	120, 120, 120, 180, 180, 180, 240, 240, 240, 240,// 3**
	300, 300, 300, 300, 240, 240, 240, 180, 180, 180,// 4**
	1200
};

int mashWait1[17] =	// �Œ聨��
{
	  25,  25,  19,  14,  14,   8,   7,   7,   7,   7,   7,   6,   5,   3,   2,   0,  10
};
int mashWait2[17] =	// �u���b�N����
{
	  29,  19,   9,   6,   6,   6,   6,   6,   6,   6,   6,   6,   4,   3,   1,   0,   2
};
int mashWait3[17] =	// �ڒn���Œ�
{
	  28,  28,  28,  28,  18,  16,  15,  15,  15,  15,  15,  14,  12,  10,   9,   8,  15
};
int mashWaitt[17] =	// ������
{
	  10,  10,  10,  10,   9,   9,   8,   8,   8,   8,   8,   8,   7,   6,   6,   4,   7
};

// �����N���Ƃ̊�^�C��
int mashBorderTime[20] = 
{
	17, 15, 14, 13, 10, 10, 12, 13, 13,		//  0�` 8
	13, 13, 13, 13, 13, 13, 12, 12, 11,		//  9�`17
	11, 10									// 18�`20
};

// �i�ʂ̕\����
str mashStrGradeName[33] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0�` 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9�`17
	"M1", "M2", "M3", "M4", "M5", "M6", "M7", "M8", "M9",	// 18�`26
	 "M", "MK", "MV", "MO", "MM", "GM"						// 27�`32
};

// ���i�ʂ̕\����
str mashStrSecretGradeName[19] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0�` 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9�`17
	"GM"													// 18
};

// �g�p����BGM
int mashBgmListTable[4] = {0, 1, 2, 6};

// �ϐ�
int mashModeNo = -1;			// ���[�h�ԍ�

int mashLevel[2];				// ���x��
int mashScore[2];				// �X�R�A
int mashGrade[2];				// �i��
int mashEndFlag[2];				// �N���A�t���O

int mashTr[2];					// 10LV���Ƃ�1������i���x�㏸�p�j
int mashTr2[2];					// ���݂̑��x�ԍ��i��{�I��LV10���Ƃ�1�����A���x�����t���O�ɂ����10��������j
int mashTimeN[2];				// �u���b�N�𑀍삵�Ă��鎞��
int mashTime99[2];				// ���x���X�g�b�v����
int mashAveLapTime[2];			// �Z�N�V�����̕��ψړ�����
int mashRank[2];				// ���݂̃����N�i0�`2�j
int mashSpeedAdjust[2];			// ���x�����t���O�i0:��蒼�� 1:�ʏ� 2:�X�L�b�v�j
int mashQualityFlag[2];			// ���xCOOL�o���ς݃t���O
int mashSkillFlag[2];			// �w�{���XCOOL�o���ς݃t���O
int mashBorderRank[2];			// COOL����p�����N
int mashGSkill[2];				// �Z�N�V�������ł̃w�{���X��

int mashSectionTime[10 * 2];	// ���̃v���C�̃Z�N�V�����^�C��

int mashSTimer[2];				// �Z�N�V�����^�C�}�[
int mashSkill[2];				// ���v�w�{���X��

int mashHeboCombo[2];			// �A���w�{���X��
int mashTSpinCombo[2];			// �A��T-SPIN��

int mashGMFlag[2 * 2];			// m���[�������t���O
int mashEndingHeboris[2];		// �G���f�B���O��4���C��������������

int mashMedalStat[4 * 2];		// ���_���̏��(0=�Ȃ� 1=�� 2=�� 3=��)
int mashMedalAnim[4 * 2];		// ���_���l���A�j���[�V�����p�J�E���^

int mashTSpinFrame[2];			// T-SPIN�\���̎c�莞��
int mashCoolFrame[2];			// COOL�\���̎c�莞��
int mashRegretFrame[2];			// REGRET�\���̎c�莞��

int mashBgmFade[2];				// �t�F�[�h�A�E�g�\�背�x���iCOOL���o���-100�j
int mashBgmIndex[2];			// ���݂�BGM�ԍ�

int mashIsBig = 0;				// BIG���ǂ���
int mashBigMove = 1;			// BIG���̉��ړ��P��
int mashGhost = 0;				// �S�[�X�g�̐ݒ�i0=LV0-99 1=���ON 2=���OFF�j
int mashLvUpBonus = 1;			// ���x���A�b�v�{�[�i�X
int mashTSpin = 1;				// T-SPIN�̎��
int mashTorikan = 25200;		// LV500�Ƃ�J����^�C�� (7:00:00)
int mash20G = 0;				// 20G���[�h

// �����L���O�ϐ�
int mashRankingGrade[10];			// �i��
int mashRankingLevel[10];			// ���x��
int mashRankingTime[10];			// �^�C��
int mashRankingEnd[10];				// �N���A�t���O
int mashRankingMedal[4 * 10];		// ���_��
int mashRankingYear[10];			// �����N�C�������i�N�j
int mashRankingMonth[10];			// �����N�C�������i���j
int mashRankingDay[10];				// �����N�C�������i���j
int mashRankingHour[10];			// �����N�C�������i���j
int mashRankingMinute[10];			// �����N�C�������i���j
int mashRankingSecond[10];			// �����N�C�������i�b�j

// �Z�N�V�����^�C�������L���O�ϐ�
int mashRankingSectionTime[10];		// �^�C��
int mashRankingSectionEnd[10];		// �N���A�t���O
int mashRankingSectionYear[10];		// �����N�C�������i�N�j
int mashRankingSectionMonth[10];	// �����N�C�������i���j
int mashRankingSectionDay[10];		// �����N�C�������i���j
int mashRankingSectionHour[10];		// �����N�C�������i���j
int mashRankingSectionMinute[10];	// �����N�C�������i���j
int mashRankingSectionSecond[10];	// �����N�C�������i�b�j

// �C�x���g����
void mashPluginEvent(int player, int event, int *param) {
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != mashModeNo)) return;
	
	if(event == 0) {
		mashModeNo = addModePlugin("MASTER-HARD");	// ���[�h��o�^����
	} else if(event == 7) {
		if(!ending[player]) mashMoveInit(player);	// �u���b�N�o��
	} else if(event == 12) {
		if(!ending[player]) mashCalcScore(player, param[0]);	// �X�R�A�v�Z
		else mashCalcScore2(player, param[0]);
	} else if(event == 15) {
		mashViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		mashSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		mashPlayerInitial(player);	// ����������
	} else if(event == 21) {
		mashResult(player, param);	// ���ʕ\��
	} else if(event == 24) {
		mashEndingStart(player);	// �G���f�B���O�˓�
	} else if(event == 25) {
		mashExcellent(player, param);	// �G���f�B���O�I��
	} else if(event == 28) {
		mashIncrementTime(player);	// ���Ԃ�i�߂�
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		mashSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		mashLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		mashLoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		mashReplayDetail();	// ���v���C�ڍ�
	} else if(event == 60) {
		mashInitCombo(player);	// �R���{������
	}
}

// ����������
void mashPlayerInitial(int player) {
	int i;
	
	// �o�[�W�����ݒ�
	if(!playback) mashVersion = mashCVersion;
	
	// �R���{�L��
	enable_combo[player] = 1;
	
	// �ϐ���������
	mashLevel[player] = -1;
	mashScore[player] = 0;
	mashGrade[player] = 0;
	mashEndFlag[player] = 0;
	
	mashTr[player] = 0;
	mashTr2[player] = 0;
	mashTimeN[player] = 0;
	mashTime99[player] = 0;
	mashAveLapTime[player] = 0;
	mashRank[player] = 0;
	mashSpeedAdjust[player] = 0;
	mashQualityFlag[player] = 0;
	mashSkillFlag[player] = 0;
	mashBorderRank[player] = 0;
	mashGSkill[player] = 0;
	
	for(i = 0; i < 10; i++) mashSectionTime[i + player * 10] = 0;
	
	mashSTimer[player] = 0;
	mashSkill[player] = 0;
	
	mashHeboCombo[player] = 0;
	mashTSpinCombo[player] = 0;
	
	mashGMFlag[player * 2 + 0] = 0;
	mashGMFlag[player * 2 + 1] = 1;
	mashEndingHeboris[player] = 0;
	
	for(i = 0; i < 4; i++) {
		mashMedalStat[player * 4 + i] = 0;
		mashMedalAnim[player * 4 + i] = -1;
	}
	
	mashTSpinFrame[player] = 0;
	mashCoolFrame[player] = 0;
	mashRegretFrame[player] = 0;
	
	mashBgmFade[player] = 485;
	mashBgmIndex[player] = 0;
	bgmlv = mashBgmListTable[0];
	
	// �ݒ�𔽉f������
	IsBig[player] = mashIsBig;
	BigMove[player] = mashBigMove;
	if(mashGhost == 2) ghost[player] = 0;
	tspin_type[player] = mashTSpin;
	
	// �����X�s�[�h��ݒ�
	mashSpeedUp(player);
}

// �X�s�[�h��ݒ�
void mashSpeedUp(int player) {
	int index;
	
	// ���x�ԍ�����
	if(mashLevel[player] / 10 > mashTr[player]) {
		mashTr[player]++;
		mashTr2[player]++;
		
		if(mashTr[player] % 10 == 0) {
			// ���x����
			if(mashSpeedAdjust[player] == 2)		// skip
				mashTr2[player] = mashTr2[player] + 10;
			if(mashSpeedAdjust[player] == 0)		// ��蒼��
				mashTr2[player] = mashTr2[player] - 10;
		}
	}
	
	// �������x
	if(mash20G) {
		sp[player] = 1200;
	} else {
		index = mashTr2[player];
		if((index > 50) || (mashLevel[player] >= mashBgmFade[player] + 15)) index = 50;
		sp[player] = mashLevelTable[index];
	}
	
	// wait�l
	if(mashTr2[player] >= 50) {
		index = (mashTr2[player] - 50) / 10;
		if(index > 15) index = 15;
		wait1[player] = mashWait1[index];
		wait2[player] = mashWait2[index];
		wait3[player] = mashWait3[index];
		waitt[player] = mashWaitt[index];
	}
	
	// �S�[�X�g������
	if((mashGhost == 0) && (mashLevel[player] >= 100)) ghost[player] = 0;
	
	// BGM�t�F�[�h�A�E�g�P
	if((mashBgmIndex[player] == 0) && (mashLevel[player] >= mashBgmFade[player]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// BGM�t�F�[�h�A�E�g�Q
	if((mashBgmIndex[player] == 1) && (mashLevel[player] >= mashBgmFade[player] + 100) && (fadelv == 0)) {
		fadelv = 1;
	}
}

// �u���b�N�o��
void mashMoveInit(int player) {
	int temp;
	
	// �ŏ��̃t���[���Ȃ�
	if(statc[player * 10 + 3] == 0) {
		// ���x���A�b�v����
		if(mashLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		
		if(mashLevel[player] % 100 != temp) {
			mashLevel[player]++;
			if(mashLevel[player] % 100 == temp) PlaySE(se_lvstop);
			mashSpeedUp(player);
		}
		
		// COOL����
		mashGradeCool(player);
	}
}

// �X�R�A�v�Z
void mashCalcScore(int player, int lines) {
	int i, temp, bo, bai, nextsec, lv;
	
	lv = mashLevel[player];	// �オ��O�̃��x��
	
	// �w�{���X�񐔑���
	if(lines >= 4) {
		mashSkill[player]++;
		mashGSkill[player]++;
		mashHeboCombo[player]++;
		
		// SK���_���l��
		if((mashSkill[player] == 15) || (mashSkill[player] == 25) || (mashSkill[player] == 40)) {
			PlaySE(se_medal);
			mashMedalStat[player * 4 + 3]++;
			mashMedalAnim[player * 4 + 3] = 0;
		}
		
		// �w�{���X3�A���ŋUCOOL
		if(mashHeboCombo[player] == 3) {
			PlaySE(se_cool);
			mashCoolFrame[player] = 180;
		}
	} else {
		mashHeboCombo[player] = 0;
	}
	
	// CO���_���l��
	if(combo2[player] == 4) {
		if(mashMedalStat[player * 4 + 2] < 1) {
			PlaySE(se_medal);
			mashMedalStat[player * 4 + 2] = 1;
			mashMedalAnim[player * 4 + 2] = 0;
		}
	} else if(combo2[player] == 5) {
		if(mashMedalStat[player * 4 + 2] < 2) {
			PlaySE(se_medal);
			mashMedalStat[player * 4 + 2] = 2;
			mashMedalAnim[player * 4 + 2] = 0;
		}
	} else if(combo2[player] == 7) {
		if(mashMedalStat[player * 4 + 2] < 3) {
			PlaySE(se_medal);
			mashMedalStat[player * 4 + 2] = 3;
			mashMedalAnim[player * 4 + 2] = 0;
		}
	}
	
	// COOL����
	mashGradeCool(player);
	
	// ���x���A�b�v
	nextsec = mashLevel[player] / 100 * 100 + 100;
	if(!mashLvUpBonus) mashLevel[player] = mashLevel[player] + lines;
	else mashLevel[player] = mashLevel[player] + lines + ((lines >= 3) * (lines - 2));
	
	if(mashLevel[player] >= 999) {
		// �G���f�B���O
		mashLevel[player] = 999;
		ending[player] = 1;
		timeOn[player] = 0;
		mashEndFlag[player] = 1;
		
		// ST���_��
		mashMedalST(player, 9);
		
		// �Z�N�V�����^�C�}�[�����Z�b�g
		mashSTimer[player] = 0;
	} else if((mashLevel[player] >= nextsec) && (nextsec == 500) && (gameTimer[player] > mashTorikan) && (mashTorikan > 0)) {
		// LV500�Ƃ�J��
		mashLevel[player] = 500;
		ending[player] = 4;
		timeOn[player] = 0;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		stat[player] = 10;
		
		// ST���_��
		mashMedalST(player, 4);
		
		// �Z�N�V�����^�C�}�[�����Z�b�g
		mashSTimer[player] = 0;
	} else {
		// ���x���X�g�b�v��
		if(mashLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		if(mashLevel[player] % 100 == temp) PlaySE(se_lvstop);
		
		if(mashLevel[player] >= nextsec) {
			// ���x���A�b�v��
			PlaySE(se_levelup);
			
			// �w�i�؂�ւ�
			bgfadesw = 1;
			bgfadebg = nextsec / 100;
			
			// m���[���t���O��������iLV400�ɂȂ����Ƃ���tr2�ϐ���80�ȏ�j
			if((nextsec == 400) && (mashTr2[player] >= 80)) {
				mashGMFlag[player * 2 + 0] = 1;
				objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
			}
			
			// REGRET����
			mashGradeRegret(player);
			
			// ST���_��
			mashMedalST(player, (nextsec / 100) - 1);
			
			// �Z�N�V�����^�C�}�[�����Z�b�g
			mashSTimer[player] = 0;
			
			// BGM�؂�ւ�
			if(fadelv != 0) {
				mashBgmIndex[player]++;
				bgmlv = mashBgmListTable[mashBgmIndex[player]];
				PlayBGM();
			}
		}
		
		// �X�s�[�h�A�b�v
		mashSpeedUp(player);
	}
	
	// �X�R�A�v�Z
	if(mashVersion >= 1) {
		temp = wait3[player] - bactivetime[player];
		if(temp < 0) temp = 0;
		
		bo = ((lv + lines) / 4 + (sdrop[player] / 2) + qdrop[player] + qput[player]) * lines * cmbpts[player] + (mashLevel[player] / 2) + temp;
		bai = 1;
	} else {
		bo = (lv + lines) / 4 + sdrop[player] + qdrop[player] + qput[player];
		bai = (lines * 2 - 1 + cmbpts[player] - (lines * 2 - 2)) * lines;
	}
	
	if(isBravo(player)) {
		// �S��������ƃX�R�A4�{
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		if(mashVersion <= 0) bai = bai * 4;
		
		// AC���_���l��
		if(mashMedalStat[player * 4 + 1] < 3) {
			PlaySE(se_medal);
			mashMedalStat[player * 4 + 1]++;
			mashMedalAnim[player * 4 + 1] = 0;
		}
	}
	
	if(tspin_flag[player]) {
		// T-SPIN
		PlaySE(se_tserase);
		mashTSpinFrame[player] = 120;
		if(mashVersion <= 0) bai = bai * 2;
		
		mashTSpinCombo[player]++;
		
		// T-SPIN2�A���ŋUCOOL
		if(mashTSpinCombo[player] == 2) {
			PlaySE(se_cool);
			mashCoolFrame[player] = 180;
		}
		
		// T-SPIN�g���v���ŋUCOOL
		if(lines == 3) {
			PlaySE(se_cool);
			mashCoolFrame[player] = 180;
		}
	} else {
		mashTSpinCombo[player] = 0;
	}
	
	// �X�R�A���Z
	mashScore[player] = mashScore[player] + (bo * bai);
}

// �X�R�A�v�Z���G���f�B���O
void mashCalcScore2(int player, int lines) {
	// T-SPIN
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		mashTSpinFrame[player] = 120;
		mashTSpinCombo[player]++;
		
		// T-SPIN2�A���ŋUCOOL
		if(mashTSpinCombo[player] == 2) {
			PlaySE(se_cool);
			mashCoolFrame[player] = 180;
		}
		
		// T-SPIN�g���v���ŋUCOOL
		if(lines == 3) {
			PlaySE(se_cool);
			mashCoolFrame[player] = 180;
		}
	} else {
		mashTSpinCombo[player] = 0;
	}
	
	// �w�{���X
	if(lines >= 4) {
		// �G���f�B���O����4���C�������񐔑���
		mashEndingHeboris[player]++;
		
		// �w�{���X3�A���ŋUCOOL
		mashHeboCombo[player]++;
		
		if(mashHeboCombo[player] == 3) {
			PlaySE(se_cool);
			mashCoolFrame[player] = 180;
		}
	} else {
		mashHeboCombo[player] = 0;
	}
}

// ST���_���l��
void mashMedalST(int player, int section) {
	// �Z�N�V�����^�C�����L�^
	mashSectionTime[section + player * 10] = mashSTimer[player];
	
	// ST���_���l������
	if((!playback) && (!IsBig[player]) && (mashLvUpBonus) && (!mash20G)) {
		if((mashSTimer[player] < mashRankingSectionTime[section]) && (mashMedalStat[player * 4 + 0] < 3)) {
			PlaySE(se_medal);
			mashMedalStat[player * 4 + 0] = 3;
			mashMedalAnim[player * 4 + 0] = 0;
		} else if((mashSTimer[player] < mashRankingSectionTime[section] + 300) && (mashMedalStat[player * 4 + 0] < 2)) {
			PlaySE(se_medal);
			mashMedalStat[player * 4 + 0] = 2;
			mashMedalAnim[player * 4 + 0] = 0;
		} else if((mashSTimer[player] < mashRankingSectionTime[section] + 600) && (mashMedalStat[player * 4 + 0] < 1)) {
			PlaySE(se_medal);
			mashMedalStat[player * 4 + 0] = 1;
			mashMedalAnim[player * 4 + 0] = 0;
		}
	}
}

// �R���{������
void mashInitCombo(int player) {
	mashHeboCombo[player] = 0;
	mashTSpinCombo[player] = 0;
}

// ���Ԃ�i�߂�
void mashIncrementTime(int player) {
	int i, temp;
	
	if(timeOn[player]) {
		// �Z�N�V�����^�C������
		mashSTimer[player]++;
		
		// �u���b�N�𑀍삵�Ă��鎞�Ԃ𑝉�
		if(stat[player] == 4) mashTimeN[player]++;
		
		// ���x���X�g�b�v���ԑ���
		if(mashLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		if(mashLevel[player] % 100 == temp) mashTime99[player]++;
	}
	
	// ���[���I��
	if((ending[player] == 2) && (edrec[player] >= 60 * 60)) {
		ending[player] = 3;
		stat[player] = 10;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
	
	if(mashCoolFrame[player] > 0)
		mashCoolFrame[player]--;	// COOL�\�����Ԍ���
	else if(mashRegretFrame[player] > 0)
		mashRegretFrame[player]--;	// REGRET�\�����Ԍ���
	else if(mashTSpinFrame[player] > 0)
		mashTSpinFrame[player]--;	// T-SPIN�\�����Ԍ���
}

// COOL����i�u���b�N��u���A�܂��̓��C�������̂��тɌĂяo���j
void mashGradeCool(int player) {
	int lap_timeT, secinlv, tmp;
	
	secinlv = mashLevel[player] - ((mashLevel[player] / 100) * 100);		// ���x���̉�2��
	lap_timeT = ( mashTimeN[player] / (1 + (are[player] != 1)) ) + (mashTime99[player] * 2);
	
	// quality cool�i���xCOOL�j
	if((secinlv > 80) && (secinlv < 99) && (!mashQualityFlag[player])) {
		// �Z�N�V�������x���Ŋ���
		mashAveLapTime[player] = lap_timeT / secinlv;
		
		// COOL
		if(mashAveLapTime[player] < mashBorderTime[mashBorderRank[player]]) {
			PlaySE(se_cool);
			mashCoolFrame[player] = 180;	// COOL�̕������o��
			mashGrade[player]++;			// �i��+1
			if(mashGrade[player] > 32) mashGrade[player] = 32;
			
			mashQualityFlag[player] = 1;	// 2��ȏ�COOL���o�Ȃ��悤�ɂ���
			mashSpeedAdjust[player] = 2;	// ���x�X�L�b�v
			
			// �����N���グ��
			if(mashRank[player] < 2) mashRank[player]++;
			
			// �t�F�[�h�A�E�g�\�背�x���O�|��
			if(mashBgmIndex[player] == 0) {
				mashBgmFade[player] = mashBgmFade[player] - 100;
				if(mashBgmFade[player] < 285) mashBgmFade[player] = 285;
			}
		}
	}
	
	// skill cool�i�w�{���XCOOL �Z�N�V�����܂����͖����j
	if((!mashSkillFlag[player]) && (secinlv < 94)) {
		if(mashLevel[player] < 100) tmp = 3;
		else if(mashLevel[player] < 200) tmp = 6;
		else tmp = 4;
		
		if(mashGSkill[player] >= tmp) {
			PlaySE(se_cool);
			mashCoolFrame[player] = 180;	// COOL�̕������o��
			mashGSkill[player] = 0;			// �w�{���X�񐔃��Z�b�g
			mashGrade[player]++;			// �i��+1
			if(mashGrade[player] > 31) mashGrade[player] = 31;
			mashSkillFlag[player] = 1;		// 2��ȏ�COOL���o�Ȃ��悤�ɂ���
		}
	}
}

// REGRET����i100�����邲�ƂɌĂяo���j
void mashGradeRegret(int player) {
	int border_time2, regretgosa;
	
	regretgosa = mashTr2[player] / 40;
	border_time2 = mashBorderTime[mashBorderRank[player]] + 6 + regretgosa;
	
	if(mashAveLapTime[player] > border_time2) {
		// REGRET
		PlaySE(se_regret);
		mashRegretFrame[player] = 180;
		
		// �~�i
		if(mashGrade[player] > 0) mashGrade[player]--;
		
		// ���x��蒼���iBGM���t�F�[�h�A�E�g���Ă���ꍇ�������j
		if((mashBgmIndex[player] != 0) || (mashLevel[player] < mashBgmFade[player])) {
			mashRank[player] = 0;
			mashSpeedAdjust[player] = 0;
		}
		
		// �t�F�[�h�A�E�g�\�背�x������
		if(mashBgmIndex[player] == 0) {
			mashBgmFade[player] = mashBgmFade[player] + 100;
			if(mashBgmFade[player] > 485) mashBgmFade[player] = 485;
		}
		
		// m���[���t���O���D
		mashGMFlag[player * 2 + 1] = 0;
	} else {
		// �w�{���XCOOL���Ă��Ȃ��ꍇ
		if(!mashSkillFlag[player]) {
			// ���x�㏸��ʏ�̑�����
			mashSpeedAdjust[player] = 1;
			
			// �����N��2�Ȃ�1�Ƀ_�E��������
			if(mashRank[player] == 2) mashRank[player] = 1;
		}
		
		// �i��+1
		mashGrade[player]++;
		if(mashGrade[player] > 31) mashGrade[player] = 31;
	}
	
	// ���̊�^�C�������߂�
	mashBorderRank[player] = mashBorderRank[player] + mashRank[player];
	
	// �ϐ������Z�b�g����
	mashTimeN[player] = 0;
	mashTime99[player] = 0;
	mashAveLapTime[player] = 0;
	mashQualityFlag[player] = 0;
	mashSkillFlag[player] = 0;
	mashGSkill[player] = 0;
}

// BGM�ǂݍ���
void mashLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 4; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/4)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(mashBgmListTable[i]);
		}
	}
}

// �G���f�B���O�˓�
void mashEndingStart(int player) {
	int i;
	
	for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	
	if(mashLevel[player] >= 999) {
		ending[player] = 2;
		stat[player] = 4;
		ending_timeOn[player] = 1;
		
		wait1[player] = mashWait1[16];
		wait2[player] = mashWait2[16];
		wait3[player] = mashWait3[16];
		waitt[player] = mashWaitt[16];
		
		// �������[��
		if((mashGrade[player] >= 22) && (gameTimer[player] <= 390 * 60) && (mashGMFlag[player * 2 + 0]) && (mashGMFlag[player * 2 + 1]))
		{
			hidden[player] = 9;
			shadowtime[player] = -60;
			objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
		}
		// �������[��
		else
		{
			hidden[player] = 8;
			shadowtime[player] = 300;
			
			// m6�ȏ�͌����鎞�Ԕ���
			if(mashGrade[player] >= 23) shadowtime[player] = 150;
		}
		
		bgmlv = mashBgmListTable[3];
		PlayBGM();
	} else {
		ending[player] = 3;
	}
}

// �G���f�B���O�I��
void mashExcellent(int player, int *param) {
	onRecord[player] = 0;
	statc[player * 10 + 1]++;
	
	if(mashLevel[player] >= 999) {
		// ���S�N���A
		if(statc[player * 10 + 1] == 1) {
			mashEndFlag[player] = 2;
			
			if(hidden[player] == 10) {
				// m���[���N���A
				hidden[player] = 0;
				
				// �������ɒi�ʏ㏸
				mashGrade[player]++;
				
				// ���[������4���C�������񐔂ɉ����Ēi�ʏ㏸
				mashGrade[player] = mashGrade[player] + mashEndingHeboris[player];
				if(mashGrade[player] > 32) mashGrade[player] = 32;
			} else {
				// �u���b�N��������悤�ɂ���
				disableShadowTimer(player);
				
				// ���[������4���C��������3�񂲂Ƃɒi�ʏ㏸
				mashGrade[player] = mashGrade[player] + (mashEndingHeboris[player] / 3);
				if(mashGrade[player] > 31) mashGrade[player] = 31;
			}
		}
		
		// �ԉ�
		if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 30)) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			statc[player * 10 + 2]++;
		}
		
		if(mashGrade[player] >= 32) {
			// YOU ARE GRAND MASTER!!
			param[0] = 1;
		} else {
			// EXCELLENT
			param[0] = 0;
			printTinyFont(foffset[player] + 20, fyoffset[player] + 116, "MASTER MODE");
			printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
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

// �X�R�A��\��
void mashViewScore(int player) {
	int i, x, y, color, kind;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// ���_���i�ʏ�j
	for(i = 0; i < 4; i++) {
		if((mashMedalAnim[player * 4 + i] < 0) || (mashMedalAnim[player * 4 + i] > 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 17;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			if(i == 0) kind = 1;
			if(i == 1) kind = 0;
			if(i == 2) kind = 5;
			if(i == 3) kind = 2;
			mashDrawMedal(x, y, kind, mashMedalStat[player * 4 + i], mashMedalAnim[player * 4 + i]);
		}
	}
	
	// ���_���i�A�j�����j
	for(i = 0; i < 4; i++) {
		if((mashMedalAnim[player * 4 + i] >= 0) && (mashMedalAnim[player * 4 + i] <= 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 17;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			if(i == 0) kind = 1;
			if(i == 1) kind = 0;
			if(i == 2) kind = 5;
			if(i == 3) kind = 2;
			mashDrawMedal(x, y, kind, mashMedalStat[player * 4 + i], mashMedalAnim[player * 4 + i]);
			mashMedalAnim[player * 4 + i]++;
		}
	}
	
	// ���x���i���q�j
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(mashLevel[player] == -1) sprintf(string[0], "%4d", 0);	// -1�Ȃ�0�ƕ\������(�����I�ɂ͍ŏ���-1�ɂȂ��Ă���)
	else sprintf(string[0], "%4d", mashLevel[player]);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// ���x���i�����j
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	if(sp[player] <= 600) {
		ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22 - ((sp[player] * 24) / 660), 143, 22, 1);
	} else {
		ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 0, 143, 22, 1);
	}
	
	// ���x���i����j
	if(ending[player]) sprintf(string[0], "%4d", mashLevel[player]);
	else if(mashLevel[player] >= 900) sprintf(string[0], "%4d", 999);
	else sprintf(string[0], "%4d", mashLevel[player] / 100 * 100 + 100);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, string[0], color);
	
	// �^�C��
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
	
	if(mashCoolFrame[player] > 0)
		printTinyFont(foffset[player] + 37, fyoffset[player] + 208, "COOL");	// COOL�\��
	else if(mashRegretFrame[player] > 0)
		printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "REGRET");	// REGRET�\��
	else if(mashTSpinFrame[player] > 0)
		printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "T-SPIN");	// T-SPIN�\��
}

// ���_����\��
void mashDrawMedal(int x, int y, int kind, int color, int anim) {
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
void mashResult(int player, int *param) {
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
			statc[player * 10 + 2] = mashRegistRanking(player);
			statc[player * 10 + 3] = mashUpdateSectionTimeRanking(player);
			if((statc[player * 10 + 2] != -1) || (statc[player * 10 + 3] != 0)) mashSaveRanking(player);
			
			// ���i�ʔ���
			statc[player * 10 + 4] = checkSecretGrade(player);
		}
		
		// �i�ʕ\��
		if(mashGrade[player] < 9)		// 9�`1
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108,   0, ((count % 4 / 2) * 216) + (mashGrade[player] * 24), 90, 24);
		else if(mashGrade[player] < 18)	// S1�`S9
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108,  90, ((count % 4 / 2) * 216) + ((mashGrade[player] -  9) * 24), 90, 24);
		else if(mashGrade[player] < 27)	// m1�`m9
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108, 180, ((count % 4 / 2) * 216) + ((mashGrade[player] - 18) * 24), 90, 24);
		else if(mashGrade[player] < 32)	// M�`MM
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108, 270, ((count % 4 / 2) * 216) + ((mashGrade[player] - 27) * 24), 90, 24);
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
		sprintf(string[0], "%13d", mashScore[player]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 67, string[0], 0);
		
		printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LEVEL");
		sprintf(string[0], "%13d", mashLevel[player]);
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
			sprintf(string[0], "%13s", mashStrSecretGradeName[statc[player * 10 + 4]]);
			printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
		}
	}
}

// �ݒ���
void mashSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(!mashLoadConfig()) mashSaveConfig();
	
	// �����L���O��ǂݍ���
	if(mashLoadRanking(player) == 0) mashInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "MASTER-HARD OPTIONS", 4);
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
		if(!mashIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!mashBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(mashGhost == 0) sprintf(string[0], "LV100");
		else if(mashGhost == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(!mashLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(mashTSpin == 0) sprintf(string[0], "OFF");
		else if(mashTSpin == 1) sprintf(string[0], "LINE CLEAR");
		else if(mashTSpin == 2) sprintf(string[0], "IMMOBILE");
		else if(mashTSpin == 3) sprintf(string[0], "3-CORNER");
		else sprintf(string[0], "3-CORNER NO KICK");
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		if(!mashTorikan) sprintf(string[0], "OFF");
		else getTime(mashTorikan);
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		if(!mash20G) sprintf(string[0], "OFF");
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
			
			if(cursor == 0) mashIsBig = !mashIsBig;
			if(cursor == 1) mashBigMove = !mashBigMove;
			if(cursor == 2) {
				mashGhost = mashGhost + move;
				if(mashGhost < 0) mashGhost = 2;
				if(mashGhost > 2) mashGhost = 0;
			}
			if(cursor == 3) mashLvUpBonus = !mashLvUpBonus;
			if(cursor == 4) {
				mashTSpin = mashTSpin + move;
				if(mashTSpin < 0) mashTSpin = 4;
				if(mashTSpin > 4) mashTSpin = 0;
			}
			if(cursor == 5) {
				mashTorikan = mashTorikan + (move * 60);
				if(mashTorikan < 0) mashTorikan = 72000;
				if(mashTorikan > 72000) mashTorikan = 0;
			}
			if(cursor == 6) mash20G = !mash20G;
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
			mashSaveConfig();
			return;
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			mashViewRanking(player);
		}
	}
}

// �ݒ��ۑ�
void mashSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x5453414D;
	saveBuf[1] = 0x482D5245;
	saveBuf[2] = 0x43445241;
	saveBuf[3] = 0x31764746;
	
	// �ݒ���e
	saveBuf[4] = mashIsBig;
	saveBuf[5] = mashBigMove;
	saveBuf[6] = mashGhost;
	saveBuf[7] = mashLvUpBonus;
	saveBuf[8] = mashTSpin;
	saveBuf[9] = mashTorikan;
	saveBuf[10] = mash20G;
	
	SaveFile("config/MASTER_HARD_CONFIG.SAV", &saveBuf, 100 * 4);
}

// �ݒ��ǂݍ���
int mashLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/MASTER_HARD_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x5453414D) return 0;
	if(saveBuf[1] != 0x482D5245) return 0;
	if(saveBuf[2] != 0x43445241) return 0;
	if(saveBuf[3] != 0x31764746) return 0;
	
	// �ݒ���e
	mashIsBig = saveBuf[4];
	mashBigMove = saveBuf[5];
	mashGhost = saveBuf[6];
	mashLvUpBonus = saveBuf[7];
	mashTSpin = saveBuf[8];
	mashTorikan = saveBuf[9];
	mash20G = saveBuf[10];
	
	return 1;
}

// ���v���C�ڍ�
void mashReplayDetail() {
	printFontGrid(1, 5, "GRADE", 0);
	if((saveBuf[908] >= 0) && (saveBuf[908] <= 32)) {
		printFontGrid(22, 5, mashStrGradeName[saveBuf[908]], 0);
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

// ���v���C�ۑ�
void mashSaveReplay(int player) {
	saveBuf[900] = mashIsBig;
	saveBuf[901] = mashBigMove;
	saveBuf[902] = mashGhost;
	saveBuf[903] = mashLvUpBonus;
	saveBuf[904] = mashTSpin;
	saveBuf[905] = mashTorikan;
	saveBuf[906] = mashLevel[player];
	saveBuf[907] = mashScore[player];
	saveBuf[908] = mashGrade[player];
	saveBuf[909] = mashVersion;
	saveBuf[910] = mash20G;
}

// ���v���C�ǂݍ���
void mashLoadReplay(int player) {
	mashIsBig = saveBuf[900];
	mashBigMove = saveBuf[901];
	mashGhost = saveBuf[902];
	mashLvUpBonus = saveBuf[903];
	mashTSpin = saveBuf[904];
	mashTorikan = saveBuf[905];
	mashVersion = saveBuf[909];
	mash20G = saveBuf[910];
}

// �����L���O�ۑ�
void mashSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �m�[�}�������L���O
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0]  = mashRankingGrade[i];
		saveBuf[1 + (i * 20) + 1]  = mashRankingLevel[i];
		saveBuf[1 + (i * 20) + 2]  = mashRankingTime[i];
		saveBuf[1 + (i * 20) + 3]  = mashRankingEnd[i];
		saveBuf[1 + (i * 20) + 4]  = mashRankingMedal[i * 4 + 0];
		saveBuf[1 + (i * 20) + 5]  = mashRankingMedal[i * 4 + 1];
		saveBuf[1 + (i * 20) + 6]  = mashRankingMedal[i * 4 + 2];
		saveBuf[1 + (i * 20) + 7]  = mashRankingMedal[i * 4 + 3];
		saveBuf[1 + (i * 20) + 8]  = mashRankingYear[i];
		saveBuf[1 + (i * 20) + 9]  = mashRankingMonth[i];
		saveBuf[1 + (i * 20) + 10] = mashRankingDay[i];
		saveBuf[1 + (i * 20) + 11] = mashRankingHour[i];
		saveBuf[1 + (i * 20) + 12] = mashRankingMinute[i];
		saveBuf[1 + (i * 20) + 13] = mashRankingSecond[i];
	}
	
	// �Z�N�V�����^�C�������L���O
	for(i = 0; i < 10; i++) {
		saveBuf[221 + (i * 10) + 0] = mashRankingSectionTime[i];
		saveBuf[221 + (i * 10) + 1] = mashRankingSectionEnd[i];
		saveBuf[221 + (i * 10) + 2] = mashRankingSectionYear[i];
		saveBuf[221 + (i * 10) + 3] = mashRankingSectionMonth[i];
		saveBuf[221 + (i * 10) + 4] = mashRankingSectionDay[i];
		saveBuf[221 + (i * 10) + 5] = mashRankingSectionHour[i];
		saveBuf[221 + (i * 10) + 6] = mashRankingSectionMinute[i];
		saveBuf[221 + (i * 10) + 7] = mashRankingSectionSecond[i];
	}
	
	sprintf(string[0], "config/MASTER_HARD_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 331 * 4);
}

// �����L���O�ǂݍ���
int mashLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/MASTER_HARD_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 331 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �m�[�}�������L���O
	for(i = 0; i < 10; i++) {
		mashRankingGrade[i]         = saveBuf[1 + (i * 20) + 0];
		mashRankingLevel[i]         = saveBuf[1 + (i * 20) + 1];
		mashRankingTime[i]          = saveBuf[1 + (i * 20) + 2];
		mashRankingEnd[i]           = saveBuf[1 + (i * 20) + 3];
		mashRankingMedal[i * 4 + 0] = saveBuf[1 + (i * 20) + 4];
		mashRankingMedal[i * 4 + 1] = saveBuf[1 + (i * 20) + 5];
		mashRankingMedal[i * 4 + 2] = saveBuf[1 + (i * 20) + 6];
		mashRankingMedal[i * 4 + 3] = saveBuf[1 + (i * 20) + 7];
		mashRankingYear[i]          = saveBuf[1 + (i * 20) + 8];
		mashRankingMonth[i]         = saveBuf[1 + (i * 20) + 9];
		mashRankingDay[i]           = saveBuf[1 + (i * 20) + 10];
		mashRankingHour[i]          = saveBuf[1 + (i * 20) + 11];
		mashRankingMinute[i]        = saveBuf[1 + (i * 20) + 12];
		mashRankingSecond[i]        = saveBuf[1 + (i * 20) + 13];
	}
	
	// �Z�N�V�����^�C�������L���O
	for(i = 0; i < 10; i++) {
		mashRankingSectionTime[i]   = saveBuf[221 + (i * 10) + 0];
		mashRankingSectionEnd[i]    = saveBuf[221 + (i * 10) + 1];
		mashRankingSectionYear[i]   = saveBuf[221 + (i * 10) + 2];
		mashRankingSectionMonth[i]  = saveBuf[221 + (i * 10) + 3];
		mashRankingSectionDay[i]    = saveBuf[221 + (i * 10) + 4];
		mashRankingSectionHour[i]   = saveBuf[221 + (i * 10) + 5];
		mashRankingSectionMinute[i] = saveBuf[221 + (i * 10) + 6];
		mashRankingSectionSecond[i] = saveBuf[221 + (i * 10) + 7];
	}
	
	return 1;
}

// �����L���O������
void mashInitRanking() {
	int i;
	
	// �m�[�}�������L���O
	for(i = 0; i < 10; i++) {
		mashRankingGrade[i]         = 0;
		mashRankingLevel[i]         = 0;
		mashRankingTime[i]          = 0;
		mashRankingEnd[i]           = 0;
		mashRankingMedal[i * 4 + 0] = 0;
		mashRankingMedal[i * 4 + 1] = 0;
		mashRankingMedal[i * 4 + 2] = 0;
		mashRankingMedal[i * 4 + 3] = 0;
		mashRankingYear[i]          = 0;
		mashRankingMonth[i]         = 0;
		mashRankingDay[i]           = 0;
		mashRankingHour[i]          = 0;
		mashRankingMinute[i]        = 0;
		mashRankingSecond[i]        = 0;
	}
	
	// �Z�N�V�����^�C�������L���O
	for(i = 0; i < 10; i++) {
		mashRankingSectionTime[i]   = 5400;
		mashRankingSectionEnd[i]    = 0;
		mashRankingSectionYear[i]   = 0;
		mashRankingSectionMonth[i]  = 0;
		mashRankingSectionDay[i]    = 0;
		mashRankingSectionHour[i]   = 0;
		mashRankingSectionMinute[i] = 0;
		mashRankingSectionSecond[i] = 0;
	}
}

// �����L���O�o�^
int mashRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (!mashLvUpBonus) || (mash20G)) return -1;
	
	for(i = 0; i < 10; i++) {
		// �����N�C��
		if(
		    (mashEndFlag[player] > mashRankingEnd[i]) || 
		    ((mashEndFlag[player] == mashRankingEnd[i]) && (mashGrade[player] > mashRankingGrade[i])) || 
		    ((mashEndFlag[player] == mashRankingEnd[i]) && (mashGrade[player] == mashRankingGrade[i]) && (gameTimer[player] < mashRankingTime[i]))
		  )
		{
			// �����L���O�����炷
			for(j = 9; j > i; j--) {
				mashRankingGrade[j]         = mashRankingGrade[j - 1];
				mashRankingLevel[j]         = mashRankingLevel[j - 1];
				mashRankingTime[j]          = mashRankingTime[j - 1];
				mashRankingEnd[j]           = mashRankingEnd[j - 1];
				mashRankingMedal[j * 4 + 0] = mashRankingMedal[(j - 1) * 4 + 0];
				mashRankingMedal[j * 4 + 1] = mashRankingMedal[(j - 1) * 4 + 1];
				mashRankingMedal[j * 4 + 2] = mashRankingMedal[(j - 1) * 4 + 2];
				mashRankingMedal[j * 4 + 3] = mashRankingMedal[(j - 1) * 4 + 3];
				mashRankingYear[j]          = mashRankingYear[j - 1];
				mashRankingMonth[j]         = mashRankingMonth[j - 1];
				mashRankingDay[j]           = mashRankingDay[j - 1];
				mashRankingHour[j]          = mashRankingHour[j - 1];
				mashRankingMinute[j]        = mashRankingMinute[j - 1];
				mashRankingSecond[j]        = mashRankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			mashRankingGrade[i]         = mashGrade[player];
			mashRankingLevel[i]         = mashLevel[player];
			mashRankingTime[i]          = gameTimer[player];
			mashRankingEnd[i]           = mashEndFlag[player];
			mashRankingMedal[i * 4 + 0] = mashMedalStat[player * 4 + 0];
			mashRankingMedal[i * 4 + 1] = mashMedalStat[player * 4 + 1];
			mashRankingMedal[i * 4 + 2] = mashMedalStat[player * 4 + 2];
			mashRankingMedal[i * 4 + 3] = mashMedalStat[player * 4 + 3];
			
			GetDateAndTime(&timebuf);
			mashRankingYear[i]          = timebuf[0];
			mashRankingMonth[i]         = timebuf[1];
			mashRankingDay[i]           = timebuf[2];
			mashRankingHour[i]          = timebuf[4];
			mashRankingMinute[i]        = timebuf[5];
			mashRankingSecond[i]        = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �Z�N�V�����^�C�������L���O�X�V
int mashUpdateSectionTimeRanking(int player) {
	int i, timebuf[8], result;
	result = 0;
	
	if((playback) || (IsBig[player]) || (!mashLvUpBonus) || (mash20G)) return 0;
	
	for(i = 0; i < 10; i++) {
		if((mashSectionTime[i + player * 10] < mashRankingSectionTime[i]) && (mashSectionTime[i + player * 10] != 0)) {
			result++;
			
			mashRankingSectionTime[i] = mashSectionTime[i + player * 10];
			mashRankingSectionEnd[i] = mashEndFlag[player];
			
			GetDateAndTime(&timebuf);
			mashRankingSectionYear[i] = timebuf[0];
			mashRankingSectionMonth[i] = timebuf[1];
			mashRankingSectionDay[i] = timebuf[2];
			mashRankingSectionHour[i] = timebuf[4];
			mashRankingSectionMinute[i] = timebuf[5];
			mashRankingSectionSecond[i] = timebuf[6];
		}
	}
	
	return result;
}

// �����L���O�\��
void mashViewRanking(int player) {
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
			printFontGrid(1, 1, "MASTER-HARD MODE RANKING >>", 6);
			printFontGrid(1, 3, "RANK GRADE LEVEL TIME", 4);
			
			for(i = 0; i < 10; i++) {
				if(mashRankingEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (mashRankingEnd[i] - 1) * 2, 320, 2);
				
				if(i == 0) sprintf(string[0], " 1ST");
				if(i == 1) sprintf(string[0], " 2ND");
				if(i == 2) sprintf(string[0], " 3RD");
				if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
				printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
				
				if((mashRankingGrade[i] >= 0) && (mashRankingGrade[i] < 33)) {
					printFontGrid(6, 4 + i, mashStrGradeName[mashRankingGrade[i]], 7 * (cursor == i));
				} else {
					printFontGrid(6, 4 + i, "???", 7 * (cursor == i));
				}
				
				sprintf(string[0], "%d", mashRankingLevel[i]);
				printFontGrid(12, 4 + i, string[0], 7 * (cursor == i));
				
				getTime(mashRankingTime[i]);
				printFontGrid(18, 4 + i, string[0], 7 * (cursor == i));
			}
			
			for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
			
			if(!erasemode) {
				// ���_��
				mashDrawMedal(8 + 0 * 16, 192, 1, mashRankingMedal[cursor * 4 + 0], -1);
				mashDrawMedal(8 + 1 * 16, 192, 0, mashRankingMedal[cursor * 4 + 1], -1);
				mashDrawMedal(8 + 2 * 16, 192, 5, mashRankingMedal[cursor * 4 + 2], -1);
				mashDrawMedal(8 + 3 * 16, 192, 2, mashRankingMedal[cursor * 4 + 3], -1);
				
				// ���t�Ǝ���
				sprintf(string[0],
				        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
				        mashRankingYear[cursor], mashRankingMonth[cursor], mashRankingDay[cursor],
				        mashRankingHour[cursor], mashRankingMinute[cursor], mashRankingSecond[cursor]);
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
					mashInitRanking();
					mashSaveRanking(player);
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
			printFontGrid(1, 1, "<< MASTER-HARD MODE SECTION TIME", 6);
			printFontGrid(1, 3, "SECTION TIME     DATE", 4);
			printFontGrid(1, 28, "A/B:EXIT", 6);
			
			for(i = 0; i < 10; i++) {
				if(mashRankingSectionEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (mashRankingSectionEnd[i] - 1) * 2, 320, 2);
				
				sprintf(string[0], "%3d-%3d", i * 100, ((i + 1) * 100) - 1);
				printFontGrid(1, 4 + i, string[0], 0);
				
				getTime(mashRankingSectionTime[i]);
				printFontGrid(9, 4 + i, string[0], 0);
				
				temp = (mashRankingSectionYear[i] / 1000) * 1000;	// �N����2�������\��
				if(temp == 0) temp = 1;
				sprintf(string[0], "%02d/%02d/%02d", mashRankingSectionYear[i] % temp, mashRankingSectionMonth[i], mashRankingSectionDay[i]);
				printFontGrid(18, 4 + i, string[0], 0);
				
				sprintf(string[0], "%02d:%02d:%02d", mashRankingSectionHour[i], mashRankingSectionMinute[i], mashRankingSectionSecond[i]);
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
