//TOMOYO-NORMAL
//prefix:tmo

// �o�[�W����
int tmoVersion;			// �o�[�W�����ԍ��i�Â����v���C�Đ��p�j
int tmoCVersion = 2;	// ���݂̃o�[�W����

// �V���x���A�b�v�e�[�u��
int tmoLevelTable[14]  = {  4, 32, 64, 96,128,160,192,224,256,512,768,1024,768, 5120};	// ���x
int tmoLevelChange[14] = { 20, 30, 33, 36, 39, 43, 47, 51,100,130,160, 250,300,10000};	// ���x��

int tmoWait1[2] = {25, 25};		// �ڒ���
int tmoWait2[2] = {40, 25};		// ����
int tmoWait3[2] = {30, 30};		// �ڒ�
int tmoWaitt[2] = {14,  8};		// ����
int tmoWait5[2] = {25, 25};		// ������

// �����x���A�b�v�e�[�u��
int tmoLevelTableOld[31] =
{
	   1,   2,   4,  10,  15,  23,  23,  30,  30,  30, // 0**
	   1,   4,   8,  15,  30,  60,  60, 120, 120, 120, // 1**
	 180, 180, 240, 240, 300, 300, 240, 240, 180, 180, // 2**
	1200
};

// �c�����X�g (0=I 1=L 2=O 3=Z 4=T 5=J 6=S)
str tmoNextBlockList = 
"1052463015240653120563402534162340621456034251036420314526014362045136455062150461320365204631546310"+
"6451324023650143620435621456302513025430312603452013625026345012660132450346213462054360143260534215"+
"0621543621435624013542130562345123641230462134502613542";

// �J���[�p
int tmoColorTable[40] = {
	10, 10,  9,  9,  8,  8,  8,  7,  7,  7,
	 6,  6,  6,  5,  5,  5,  4,  4,  4,  4,
	 3,  3,  3,  3,  2,  2,  2,  2,  1,  1,
	 1,  1,  0,  0,  0,  0,  0,  0,  0,  0
};

// BGM�ԍ��i1�`20�AEX1�`7�j
int tmoBgmNo[2] = {8, 9};

// �ϐ�
int tmoModeNo = -1;		// ���[�h�ԍ�
int tmoLevel[2];		// ���x��
int tmoLevelIndex[2];	// ���݂̑��x�ԍ�

int tmoStage[2];		// �X�e�[�W
int tmoRest[2];			// �c��v���`�i�u���b�N��
int tmoLastStage[2];	// �ŏI�X�e�[�W
int tmoClearStage[2];	// �N���A�����X�e�[�W��
int tmoClearPer[2];		// �N���A��
int tmoClearFlag[2];	// �X�e�[�W�N���A�t���O
int tmoTryStage[2];		// �X�e�[�W�ɒ��킵����

int tmoLimitTime[2];	// ���~�b�g�^�C��
int tmoStageTime[2];	// �X�e�[�W�^�C��
int tmoClearTime[2];	// �N���A�^�C��

int tmoNoStageTime[2];	// �X�e�[�W�^�C���������t���O

int tmoSkipMpc[2];		// �X�e�[�W�X�L�b�v�L�[����������

int tmoTimeBonus[2];	// �^�C������
int tmoLTType[2];		// ���~�b�g�^�C�����؂�Ă��u���b�N��u���܂ł̓v���C���s

int tmoIsMirror[2];		// �~���[
int tmoIsRoll[2];		// ���[�����[��
int tmoIsBig[2];		// �f�X�u���b�N
int tmoIsXRay[2];		// X-RAY
int tmoIsColor[2];		// �J���[

int tmoXRayEnable[2];	// ��X-RAY���L�����ǂ���
int tmoXRayCounter[2];	// X-RAY�p�J�E���^

int tmoColorCounter[2];	// �J���[�p�J�E���^

int tmoNextc[2];		// �X�e�[�W�J�n���̃u���b�N�J�E���^

int tmoStatc[10 * 2];	// �X�e�[�^�X�J�E���^���ۂ�����

int tmoEndFlag[2];		// ���S�N���A�t���O

int tmoSectionTime[27 * 2];	// ���̃v���C�̃Z�N�V�����^�C��

int tmoFirstStage = 0;	// �J�n�X�e�[�W
int tmoStageType = 0;	// �X�e�[�W�̎�ށi0=NORMAL 1=EDIT�j
int tmoGhost = 0;		// �S�[�X�g�̐ݒ�i0=LV0-99 1=���ON 2=���OFF�j
int tmoLvUpBonus = 1;	// ���x���A�b�v�{�[�i�X
int tmoRandomMode = 0;	// �����_�����[�h
int tmoGameType = 0;	// �Q�[���^�C�v�i0=NORMAL 1=TRAINING�j

// �����L���O�p�ϐ�
int tmoRankingStage[5 * 2];		// �X�e�[�W
int tmoRankingClear[5 * 2];		// �N���A��
int tmoRankingTime[5 * 2];		// �^�C��
int tmoRankingEnd[5 * 2];		// ���S�N���A�t���O
int tmoRankingYear[5 * 2];		// �����N�C�������i�N�j
int tmoRankingMonth[5 * 2];		// �����N�C�������i���j
int tmoRankingDay[5 * 2];		// �����N�C�������i���j
int tmoRankingHour[5 * 2];		// �����N�C�������i���j
int tmoRankingMinute[5 * 2];	// �����N�C�������i���j
int tmoRankingSecond[5 * 2];	// �����N�C�������i�b�j

// �Z�N�V�����^�C�������L���O�ϐ�
int tmoRankingSectionTime[27];		// �^�C��
int tmoRankingSectionRand[27];		// �����_�����[�h
int tmoRankingSectionEnd[27];		// ���S�N���A�t���O
int tmoRankingSectionYear[27];		// �����N�C�������i�N�j
int tmoRankingSectionMonth[27];		// �����N�C�������i���j
int tmoRankingSectionDay[27];		// �����N�C�������i���j
int tmoRankingSectionHour[27];		// �����N�C�������i���j
int tmoRankingSectionMinute[27];	// �����N�C�������i���j
int tmoRankingSectionSecond[27];	// �����N�C�������i�b�j

// �C�x���g����
void tmoPluginEvent(int player, int event, int *param) {
	int i;
	
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != tmoModeNo)) return;
	
	if(event == 0) {
		tmoModeNo = addModePlugin("TOMOYO-NORMAL");	// ���[�h��o�^����
	} else if(event == 5) {
		tmoReady(player);	// Ready
	} else if(event == 7) {
		tmoMoveInit(player);	// �u���b�N�o��
	} else if(event == 10) {
		tmoARE(player, param);	// ARE���i�X�e�[�W�I������j
	} else if(event == 12) {
		tmoEraseLine(player, param[0]);	// �X�R�A�v�Z
	} else if(event == 15) {
		tmoViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		tmoSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		tmoPlayerInitial(player);	// ����������
	} else if(event == 20) {
		tmoGameOver(player, param);	// �Q�[���I�[�o�[���̏���
	} else if(event == 21) {
		tmoResult(player);	// ���ʕ\��
	} else if(event == 24) {
		ending[player] = 3;	// �G���f�B���O�˓�
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		tmoExcellent(player);	// EXCELLENT���
	} else if(event == 28) {
		tmoIncrementTime(player);	// ���Ԃ�i�߂�
	} else if(event == 29) {
		tmoViewFieldBackground(player);	// COLOR���̔w�i��`��
	} else if(event == 34) {
		tmoViewFieldBlock(player, param);	// �t�B�[���h��`��
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		tmoSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		tmoLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		tmoLoadBGM();	// BGM�ǂݍ���
	} else if(event == 53) {
		tmoEraseBlock(player, param[0], param[1]);	// �u���b�N����
	} else if(event == 55) {
		tmoReplayDetail();	// ���v���C�ڍ�
	}
}

// ����������
void tmoPlayerInitial(int player) {
	int i;
	
	// �o�[�W����
	if(!playback) tmoVersion = tmoCVersion;
	
	// �ϐ���������
	tmoLevel[player] = -1;
	tmoLevelIndex[player] = 0;
	
	tmoStage[player] = tmoFirstStage;
	tmoRest[player] = 0;
	tmoLastStage[player] = 26;
	tmoClearStage[player] = 0;
	tmoClearPer[player] = 0;
	tmoClearFlag[player] = 0;
	tmoTryStage[player] = 0;
	
	tmoLimitTime[player] = 0;
	tmoStageTime[player] = 0;
	tmoClearTime[player] = 0;
	
	tmoNoStageTime[player] = 0;
	
	tmoSkipMpc[player] = 0;
	
	tmoTimeBonus[player] = 1;
	tmoLTType[player] = 1;
	
	tmoIsMirror[player] = 0;
	tmoIsRoll[player] = 0;
	tmoIsBig[player] = 0;
	tmoIsXRay[player] = 0;
	tmoIsColor[player] = 0;
	
	tmoXRayEnable[player] = 0;
	tmoXRayCounter[player] = 0;
	
	tmoColorCounter[player] = 0;
	
	if(tmoGhost == 2) ghost[player] = 0;
	
	tmoNextc[player] = 0;
	
	for(i = 0; i < 10; i++) tmoStatc[player * 10 + i] = 0;
	
	tmoEndFlag[player] = 0;
	
	for(i = 0; i < 27; i++) tmoSectionTime[i + player * 27] = 0;
	
	framecolor[player] = 4;
	
	// �����X�s�[�h��ݒ�
	tmoSpeedUp(player);
}

// �u���b�N�o��
void tmoMoveInit(int player) {
	int temp;
	
	// �ŏ��̃t���[���Ȃ�
	if(statc[player * 10 + 3] == 0) {
		// ���x���A�b�v����
		if(tmoLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		
		if(tmoLevel[player] % 100 != temp) {
			tmoLevel[player]++;
			if(tmoLevel[player] % 100 == temp) PlaySE(se_lvstop);
			tmoSpeedUp(player);
		}
		
		// �~���[
		if(tmoIsMirror[player]) {
			if((bdowncnt[player] + 1) % tmoIsMirror[player] == 0)
				isfmirror[player] = 1;
			else
				isfmirror[player] = 0;
		} else {
			isfmirror[player] = 0;
		}
		
		// ���[�����[��
		if(tmoIsRoll[player]) {
			if((bdowncnt[player] + 1) % tmoIsRoll[player] == 0)
				current_rollroll[player] = 1;
			else
				current_rollroll[player] = 0;
		} else {
			current_rollroll[player] = 0;
		}
		
		// X-RAY
		if(tmoIsXRay[player]) tmoXRayEnable[player] = !tmoXRayEnable[player];
		else tmoXRayEnable[player] = 0;
		tmoXRayCounter[player] = 0;
	}
}

// �X�s�[�h�A�b�v
void tmoSpeedUp(int player) {
	int index;
	
	if(tmoVersion >= 2) {
		while(tmoLevel[player] >= tmoLevelChange[tmoLevelIndex[player]]) tmoLevelIndex[player]++;
		
		speedtype[player] = 2;
		sp[player] = tmoLevelTable[tmoLevelIndex[player]];
		
		index = is20G(player);
		wait1[player] = tmoWait1[index];
		wait2[player] = tmoWait2[index];
		wait3[player] = tmoWait3[index];
		waitt[player] = tmoWaitt[index];
		wait5[player] = tmoWait5[index];
	} else {
		index = tmoLevel[player] / 10;
		if(index < 0) index = 0;
		if(index > 30) index = 30;
		
		speedtype[player] = 0;
		sp[player] = tmoLevelTableOld[index];
	}
	
	// �S�[�X�g������
	if((tmoLevel[player] >= 100) && (tmoGhost == 0)) ghost[player] = 0;
}

// �v���`�i�u���b�N�̐��𐔂���
int tmoCountPlatinumBlocks(int player) {
	int i, cnt;
	cnt = 0;
	
	for(i = 0; i < 220; i++) {
		if(fld[i + player * 220] >= 11) cnt++;
	}
	
	return cnt;
}

// �c�����X�g��ǂݍ���
void tmoLoadNextList(int player) {
	int i, j, temp, len;
	
	// �����𒲂ׂ�
	len = StrLen(tmoNextBlockList);
	
	// �ǂݍ���
	if(len > 0) {
		nextc_max[player] = len;
		
		for(i = 0; i < len; i++) {
			j = i % len;
			
			MidStr(tmoNextBlockList, j + 1, 1, string[0]);
			
			temp = ValLong(string[0]);
			if((temp >= 0) && (temp <= 6)) nextb[i + player * 1400] = temp;
		}
	}
	
	setNextBlockColor(player, 1);
}

// Ready
void tmoReady(int player) {
	int bak;
	
	// �ŏ��̃t���[���̏���
	if(statc[player * 10] == 0) {
		// Ready��Go�̎��Ԃ�ݒ�
		ready_start[player] = 45;
		ready_end[player] = 155;
		go_start[player] = 160;
		go_end[player] = 225;
		
		// �c���X�L�b�v�L��
		nextskip[player] = 1;
		
		// �w�i��߂�
		if(backno != 0) {
			bgfadesw = 1;
			bgfadebg = 0;
		}
		
		// ���x�����Z�b�g
		tmoLevel[player] = -1;
		tmoLevelIndex[player] = 0;
		tmoSpeedUp(player);
		
		// �S�[�X�g����
		if(tmoGhost != 2) ghost[player] = 1;
		
		// �u���b�N��u�����񐔂����Z�b�g
		bdowncnt[player] = 0;
		
		// HOLD����
		hold[player] = -1;
		dhold[player] = 0;
		
		// �N���A�^�C���ƃt���O�����Z�b�g
		tmoClearTime[player] = 0;
		tmoClearFlag[player] = 0;
		
		// �u���b�N�J�E���^���o�b�N�A�b�v�i�R���e�B�j���[���ɖ߂��j
		tmoNextc[player] = nextc[player];
		
		// �c�����X�g�ǂݍ���
		if(!tmoRandomMode && !ready_count[player]) tmoLoadNextList(player);
		
		// BGM�ԍ��ύX
		if(tmoStage[player] < 20) bgmlv = tmoBgmNo[0];
		else bgmlv = tmoBgmNo[1];
		
		// ���~�b�g�^�C�����o�b�N�A�b�v
		if(ready_count[player]) bak = tmoLimitTime[player];
		
		// �X�e�[�W��ǂݍ���
		tmoLoadStage(player, tmoStage[player], tmoStageType);
		
		// ���~�b�g�^�C�����o�b�N�A�b�v����߂�
		if(ready_count[player]) tmoLimitTime[player] = bak;
		
		if(!tmoStageTime[player]) tmoNoStageTime[player] = 1;
		else tmoNoStageTime[player] = 0;
		
		perase_show_bonus[player] = tmoTimeBonus[player];
		tmoRest[player] = tmoCountPlatinumBlocks(player);
		
		// DEATH BLOCK
		if(tmoIsBig[player]) {
			IsBig[player] = 1;
			if(tmoIsBig[player] >= 2) BigMove[player] = 1;
			else BigMove[player] = 0;
		} else {
			IsBig[player] = 0;
		}
		
		// �M�~�b�N�x��
		if(tmoIsMirror[player]) {
			objectCreate(player, 8, 0, 0, 0, 0, 0, 0);
		} else if(tmoIsRoll[player]) {
			objectCreate(player, 8, 0, 0, 0, 0, 1, 0);
		} else if(tmoIsBig[player]) {
			objectCreate(player, 8, 0, 0, 0, 0, 2, 0);
		} else if(tmoIsXRay[player]) {
			objectCreate(player, 8, 0, 0, 0, 0, 3, 0);
		} else if(tmoIsColor[player]) {
			objectCreate(player, 8, 0, 0, 0, 0, 4, 0);
		}
	}
	
	if(statc[player * 10] >= ready_start[player]) {
		// �X�e�[�W�ԍ�
		printFont(foffset[player] + 16, fyoffset[player] + 72, "STAGE", 4);
		if(tmoStage[player] >= 20) sprintf(string[0], "EX%d", tmoStage[player] - 19);
		else sprintf(string[0], "%2d", tmoStage[player] + 1);
		printFont(foffset[player] + 64, fyoffset[player] + 72, string[0], 0);
		
		// �x�X�g�^�C��
		if(!playback) {
			printFont(foffset[player] + 8, fyoffset[player] + 152, "BEST  TIME", 1);
			getTime(tmoRankingSectionTime[tmoStage[player]]);
			printFont(foffset[player] + 16, fyoffset[player] + 160, string[0], 0);
		}
	}
}

// �u���b�N����
void tmoEraseBlock(int player, int x, int y) {
	if(fld[x + y * 10 + player * 220] >= 11) {
		PlaySE(se_platinaerase);
		if(tmoTimeBonus[player]) tmoLimitTime[player] = tmoLimitTime[player] + 60;
		tmoRest[player]--;
	}
}

// ���C������
void tmoEraseLine(int player, int lines) {
	int temp, nextsec;
	
	// �S����
	if(isBravo(player)) {
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
	}
	
	// ���x���A�b�v
	nextsec = tmoLevel[player] / 100 * 100 + 100;
	if(!tmoLvUpBonus) tmoLevel[player] = tmoLevel[player] + lines;
	else tmoLevel[player] = tmoLevel[player] + lines + ((lines >= 3) * (lines - 2));
	
	if(tmoLevel[player] >= 998) {
		// �J���X�g
		tmoLevel[player] = 998;
	} else {
		// ���x���X�g�b�v��
		if(tmoLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		if(tmoLevel[player] % 100 == temp) PlaySE(se_lvstop);
		
		if(tmoLevel[player] >= nextsec) {
			// ���x���A�b�v��
			PlaySE(se_levelup);
			
			// �w�i�؂�ւ�
			bgfadesw = 1;
			bgfadebg = nextsec / 100;
		}
		
		// �X�s�[�h�A�b�v
		tmoSpeedUp(player);
	}
}

// ���Ԃ�i�߂�
void tmoIncrementTime(int player) {
	int i;
	
	if(timeOn[player]) {
		// �X�e�[�W�^�C������
		if(tmoStageTime[player] > 0) {
			tmoStageTime[player]--;
			
			// ���Ԑ؂�
			if(tmoStageTime[player] <= 0) {
				PlaySE(se_timeover);
				tmoStageTime[player] = 0;
			}
			// �c��10�b
			else if(tmoStageTime[player] == 10 * 60) {
				PlaySE(se_hurryup);
			}
		}
		
		// ���~�b�g�^�C������
		if(tmoLimitTime[player] > 0) {
			tmoLimitTime[player]--;
			
			// ���Ԑ؂�
			if(tmoLimitTime[player] <= 0) {
				PlaySE(se_timeover);
				tmoLimitTime[player] = 0;
				
				// ����
				if(!tmoLTType[player]) {
					timeOn[player] = 0;
					stat[player] = 7;
					for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
				}
			}
			// �c��10�b
			else if(tmoLimitTime[player] == 10 * 60) {
				PlaySE(se_hurryup);
			}
		}
		
		// �N���A�^�C��+1
		tmoClearTime[player]++;
		
		// �X�e�[�W�X�L�b�v
		if((tmoStage[player] < 19) && (tmoLimitTime[player] > 30 * 60)) {
			// �X�e�[�W�X�L�b�v�L�[
			if(getPressState(player, 9)) tmoSkipMpc[player]++;
			else tmoSkipMpc[player] = 0;
			
			// �X�e�[�W�X�L�b�v�t���OON
			if(tmoSkipMpc[player] >= 60) {
				timeOn[player] = 0;
				tmoLimitTime[player] = tmoLimitTime[player] - 30 * 60;
				tmoClearFlag[player] = -1;
				stat[player] = 5;
				for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
			}
		} else {
			tmoSkipMpc[player] = 0;
		}
		
		// X-RAY
		if(tmoXRayEnable[player]) tmoXRayCounter[player]++;
		else tmoXRayCounter[player] = 0;
		
		// COLOR
		if(tmoIsColor[player]) tmoColorCounter[player]++;
		else tmoColorCounter[player] = 0;
	}
}

// ARE���i�X�e�[�W�I������j
void tmoARE(int player, int *param) {
	int i;
	
	// �X�e�[�W�X�L�b�v
	if(tmoClearFlag[player] == -1) {
		param[0] = 1;
		timeOn[player] = 0;
		tmoStageEnd(player);
		return;
	}
	// �N���A
	else if(tmoRest[player] <= 0) {
		param[0] = 1;
		timeOn[player] = 0;
		tmoClearFlag[player] = 1;
		tmoStageEnd(player);
		return;
	}
	// �X�e�[�W�^�C�����Ԑ؂�
	else if((tmoStageTime[player] <= 0) && (!tmoNoStageTime[player])) {
		param[0] = 1;
		timeOn[player] = 0;
		tmoClearFlag[player] = 0;
		tmoStageEnd(player);
		return;
	}
	
	// ���~�b�g�^�C�����Ԑ؂�
	if(tmoLimitTime[player] <= 0) {
		if(tmoVersion >= 1) param[0] = 1;
		timeOn[player] = 0;
		stat[player] = 7;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		return;
	}
}

// �X�e�[�W�I�����
void tmoStageEnd(int player) {
	int i, ext;
	
	// �ŏ��̃t���[���̏���
	if(tmoStatc[player * 10] == 0) {
		// �x�����X�g�b�v
		StopSE(se_hurryup);
		StopSE(se_timeover);
		pinch[player] = 0;
		
		// �N���A�����X�e�[�W+1
		if(tmoClearFlag[player] == 1) tmoClearStage[player]++;
		
		// �N���A���v�Z
		tmoTryStage[player]++;
		if(tmoStage[player] <= 19) tmoClearPer[player] = (tmoClearStage[player] * 100) / (tmoTryStage[player]);
		
		// �X�e�[�W20�N���A��BGM�t�F�[�h�A�E�g
		if(tmoStage[player] == 19) fadelv = 1;
		
		// X-RAY����
		tmoXRayEnable[player] = 0;
		tmoXRayCounter[player] = 0;
	}
	
	// STAGE XX
	printFont(foffset[player] + 16, fyoffset[player] + 48, "STAGE", 4);
	if(tmoStage[player] >= 20) sprintf(string[0], "EX%d", tmoStage[player] - 19);
	else sprintf(string[0], "%2d", tmoStage[player] + 1);
	printFont(foffset[player] + 64, fyoffset[player] + 48, string[0], 0);
	
	// CLEAR/TIME OVER
	if(tmoClearFlag[player] == 1) {
		printFont(foffset[player] + 28, fyoffset[player] + 64, "CLEAR", 0);
	} else if(tmoClearFlag[player] == 0) {
		printFont(foffset[player] + 16, fyoffset[player] + 64, "TIME UP!", 0);
		printFont(foffset[player] + 16, fyoffset[player] + 72, "TRY NEXT", 0);
	} else {
		printFont(foffset[player] + 24, fyoffset[player] + 60, "SKIPED", 0);
	}
	
	// ���~�b�g�^�C�������ʂ����߂�
	ext = 0;
	
	if((tmoTimeBonus[player]) && (tmoClearFlag[player] == 1)) {
		if(tmoClearTime[player] < 10 * 60) {
			ext = 10;
		} else if(tmoClearTime[player] < 20 * 60) {
			ext = 5;
		}
	}
	
	// �N���A���̏���
	if(tmoClearFlag[player] == 1) {
		// LIMIT TIME
		printSMALLFont(foffset[player] + 18, fyoffset[player] + 80, "Limit Time", 3);
		
		if(tmoStatc[player * 10 + 2] < (ext * 60)) {
			tmoStatc[player * 10 + 2] = tmoStatc[player * 10 + 2] + 4;	// ���~�b�g�^�C���������鉉�o
		}
		getTime(tmoLimitTime[player] + tmoStatc[player * 10 + 2]);
		printSMALLFont(foffset[player] + 24, fyoffset[player] + 90, string[0], ((count % 4 / 2) * 7) * (ext != 0));
		
		// TIME EXTEND
		if(tmoTimeBonus[player]) {
			printSMALLFont(foffset[player] + 15, fyoffset[player] + 104, "Time Extend", 3);
			sprintf(string[0], "%2d sec", ext);
			printSMALLFont(foffset[player] + 28, fyoffset[player] + 114, string[0], 0);
		}
		
		// CLEAR TIME
		printSMALLFont(foffset[player] + 18, fyoffset[player] + 128, "Clear Time", 3);
		getTime(tmoClearTime[player]);
		printSMALLFont(foffset[player] + 25, fyoffset[player] + 138, string[0], 0);
		
		if(!playback) {
			if((tmoClearTime[player] < tmoRankingSectionTime[tmoStage[player]]) || (tmoRankingSectionTime[tmoStage[player]] == 0))
				printSMALLFont(foffset[player] + 18, fyoffset[player] + 150, "New Record", (count % 4 / 2) * 2);
		}
		
		// 20�ʃN���A��1������
		if((tmoStage[player] == 19) && (!tmoGameType)) {
			printFont(foffset[player] + 8, 176, "+1 MINUTES", 2);
		}
		
		// �ԉ�
		if( ((ext == 0) && (tmoStatc[player * 10] % 40 == 0) && (tmoStatc[player * 10 + 1] <   3)) || 
		    ((ext != 0) && (tmoStatc[player * 10] % 10 == 0) && (tmoStatc[player * 10 + 1] < ext)) )
		{
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			tmoStatc[player * 10 + 1]++;
		}
	}
	// ���s���̏���
	else {
		// LIMIT TIME
		printSMALLFont(foffset[player] + 18, fyoffset[player] + 104, "Limit Time", 3);
		getTime(tmoLimitTime[player]);
		printSMALLFont(foffset[player] + 24, fyoffset[player] + 114, string[0], 0);
		
		// �N���A��
		printSMALLFont(foffset[player] + 18, fyoffset[player] + 128, "Clear Per.", 3);
		sprintf(string[0], "%d%%", tmoClearPer[player]);
		printSMALLFont(foffset[player] + 39, fyoffset[player] + 138, string[0], 0);
	}
	
	if(getPushState(player, 4) || (tmoStatc[player * 10] >= 300)) {
		// ���̃X�e�[�W
		
		if(tmoClearFlag[player] == 1) {
			// ���~�b�g�^�C������
			tmoLimitTime[player] = tmoLimitTime[player] + ext * 60;
			
			// �Z�N�V�����^�C���L�^
			tmoSectionTime[tmoStage[player] + player * 27] = tmoClearTime[player];
		}
		
		// �X�e�[�W20�N���A
		if((tmoStage[player] == 19) && (!tmoGameType)) {
			// +1��
			tmoLimitTime[player] = tmoLimitTime[player] + 3600;
			
			// �ŏI�X�e�[�W������
			if(tmoClearPer[player] < 90)
				tmoLastStage[player] = 19; // �N���A����90%�ɖ����Ȃ��ꍇ�̓X�e�[�W20�ŏI��
			else if(tmoClearPer[player] < 100)
				tmoLastStage[player] = 22; // �N���A����90�`99%��EX3�܂�
			else if(gameTimer[player] >= 18000)
				tmoLastStage[player] = 24; // �N���A����100%��5�������Ă���ꍇ��EX5
			else
				tmoLastStage[player] = 26; // �N���A����100%��5���ȓ��Ȃ�EX7
			
			// ����
			if(tmoLastStage[player] == 26) {
				objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
			}
		}
		
		if(tmoGameType) {
			// �g���[�j���O
			stat[player] = 3;
		} else if(tmoStage[player] >= tmoLastStage[player]) {
			// ���X�g�X�e�[�W�N���A�ŃG���f�B���O
			StopAllBGM();
			onRecord[player] = 0;
			ending[player] = 1;
			stat[player] = 10;
		} else {
			// �X�e�[�W��i�߂�
			tmoStage[player]++;
			stat[player] = 3;
		}
		
		// �X�e�[�^�X�J�E���^�����Z�b�g
		for(i = 0; i < 10; i++) {
			statc[player * 10 + i] = 0;
			tmoStatc[player * 10 + i] = 0;
		}
	} else {
		// �J�E���^����
		tmoStatc[player * 10]++;
	}
}

// BGM�ǂݍ���
void tmoLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 2; i++) {
			// EX�ʂ���n�߂�Ƃ���1�Ȗڂ̓ǂݍ��݂��ȗ�
			if((i == 1) || (tmoFirstStage < 20)) {
				ClearSecondary();
				sprintf(string[0], "LOADING BGM... (%d/2)", i + 1);
				printFontGrid(1, 1, string[0], 2);
				halt;
				loadBGM(tmoBgmNo[i]);
			}
		}
	}
}

// EXCELLENT���
void tmoExcellent(int player) {
	int max;
	
	statc[player * 10 + 1]++;
	
	printTinyFont(foffset[player] + 20, fyoffset[player] + 116, "TOMOYO MODE");
	
	if(tmoStage[player] >= 26) {
		printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
		max = 30;
		tmoEndFlag[player] = 2;
	} else {
		printTinyFont(foffset[player] + 35, fyoffset[player] + 123, "CLEAR");
		max = 15;
		tmoEndFlag[player] = 1;
	}
	
	// �ԉ�
	if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < max)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 2]++;
	}
}

// ���ʕ\��
void tmoResult(int player) {
	if(statc[player * 10] == 0) {
		// ���v���C�L�^��~
		onRecord[player] = 0;
		
		// �����L���O�o�^
		statc[player * 10 + 1] = tmoRegistRanking(player);
		statc[player * 10 + 2] = tmoUpdateSectionTimeRanking(player);
		if((statc[player * 10 + 1] != -1) || (statc[player * 10 + 2] != 0)) tmoSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "STAGE");
	if(tmoStage[player] >= 20) {
		sprintf(string[0], "EX%d", tmoStage[player] - 19);
		printSMALLFont(foffset[player] + 70, fyoffset[player] + 87, string[0], 0);
	} else {
		sprintf(string[0], "%2d", tmoStage[player] + 1);
		printSMALLFont(foffset[player] + 76, fyoffset[player] + 87, string[0], 0);
	}
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "CLEAR");
	sprintf(string[0], "%12d>", tmoClearPer[player]);
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
}

// �X�R�A�\��
void tmoViewScore(int player) {
	int temp, color, color2;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// �X�e�[�W
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "STAGE");
	if(tmoStage[player] >= 20) sprintf(string[0], "EX%d", tmoStage[player] - 19);
	else sprintf(string[0], "%d", tmoStage[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// �c��v���`�i�u���b�N
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "REST");
	sprintf(string[0], "%d", tmoRest[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// �N���A��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 76, "CLEAR");
	sprintf(string[0], "%d%%", tmoClearPer[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 84, string[0], color);
	
	// ���x���i���q�j
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(tmoLevel[player] == -1) sprintf(string[0], "%4d", 0);	// -1�Ȃ�0�ƕ\������(�����I�ɂ͍ŏ���-1�ɂȂ��Ă���)
	else sprintf(string[0], "%4d", tmoLevel[player]);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// ���x���i�����j
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	if(speedtype[player] == 2) {
		temp = sp[player] / 128;
		if(temp > 22) temp = 22;
		ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22 - temp, 143, 22, 1);
	} else if(sp[player] <= 600) {
		ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22 - ((sp[player] * 24) / 660), 143, 22, 1);
	} else {
		ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 0, 143, 22, 1);
	}
	
	// ���x���i����j
	if(tmoLevel[player] >= 900) sprintf(string[0], "%4d", 999);
	else sprintf(string[0], "%4d", tmoLevel[player] / 100 * 100 + 100);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, string[0], color);
	
	// �X�e�[�W�^�C��
	if(!tmoNoStageTime[player]) {
		getTime(tmoStageTime[player]);
		if(tmoStageTime[player] == 0) color2 = 0;
		else if(tmoStageTime[player] <= 10 * 60) color2 = (count % 4 / 2) * 1;
		else color2 = 1;
		printFont(foffset[player] + 16, fyoffset[player] + 216, string[0], color2);
	}
	
	// ���~�b�g�^�C��
	getTime(tmoLimitTime[player]);
	if(tmoLimitTime[player] == 0) color2 = 0;
	else if(tmoLimitTime[player] <= 10 * 60) color2 = (count % 4 / 2) * 2;
	else color2 = color;
	
	if(tmoNoStageTime[player]) {
		printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
	} else {
		printFont(foffset[player] + 16, fyoffset[player] + 224, string[0], color);
	}
	
	// �M�~�b�N
	if(tmoIsMirror[player]) {
		ExBltRect(sg_itemname, foffset[player] + 88, fyoffset[player] + 94, 0, 0, 48, 16);
	} else if(tmoIsRoll[player]) {
		ExBltRect(sg_itemname, foffset[player] + 88, fyoffset[player] + 94, 0, 16, 48, 16);
	} else if(tmoIsBig[player]) {
		ExBltRect(sg_itemname, foffset[player] + 88, fyoffset[player] + 94, 0, 32, 48, 16);
	} else if(tmoIsXRay[player]) {
		ExBltRect(sg_itemname, foffset[player] + 88, fyoffset[player] + 94, 0, 48, 48, 16);
	} else if(tmoIsColor[player]) {
		ExBltRect(sg_itemname, foffset[player] + 88, fyoffset[player] + 94, 0, 64, 48, 16);
	}
}

// COLOR���̔w�i��`��
void tmoViewFieldBackground(int player) {
	if((tmoIsColor[player]) && (timeOn[player])) {
		ExBltFast(sg_black, foffset[player] + 8, fyoffset[player] + 40);
	}
}

// �t�B�[���h��`��
void tmoViewFieldBlock(int player, int *param) {
	int i, j, fi, ft, temp, dx, dy, bright;
	
	param[0] = 1;
	
	for(i = 0; i < 22; i++) {
		for(j = 0; j < 10; j++) {
			if((!timeOn[player]) || (!tmoXRayEnable[player]) || (tmoXRayCounter[player] % 36 == j)) {
				fi = getFieldBlock(player, j, i);
				
				if(fi > 0) {
					// �u���b�N��`��
					dx = foffset[player] + 8 + (j * 8);
					dy = fyoffset[player] + (i + 3) * 8;
					ft = getFieldBlockT(player, j, i);
					
					// ���邳����
					if((tmoIsColor[player]) && (timeOn[player])) {
						// COLOR��
						bright = j;
						if(bright >= 5) bright = 9 - bright;
						bright = 40 - ( (((20 - i) + bright) * 4 + tmoColorCounter[player]) % 40 );
						bright = 7 + 10 - tmoColorTable[bright];
					} else {
						// �ʏ펞
						bright = 5;
					}
					
					if(bright <= 16) {
						if((ft >= 1) && (ft <= 8)) {
							drawSBlock(player, dx, dy, fi - 1, bright, 0, 1, ft * 32);
						} else if((ft != 0) && (ft > -10)) {
							drawSBlock(player, dx, dy, fi - 1, bright, 0, 0, 0);
						}
					}
					
					// �g����`��
					if( (disp_blkline[player]) && ((!tmoIsColor[player]) || (!timeOn[player])) ) {
						// �g����`��
						viewFieldBlockSub_DrawLine(player, j, i, dx, dy);
						
						// �e��`��
						if(blockshadow != 0) viewFieldBlockSub_DrawShadow(player, j, i, dx, dy, 0, fi - 1);
					}
				}
			}
		}
	}
}

// �Q�[���I�[�o�[���̏���
void tmoGameOver(int player, int *param) {
	int i, j, block, c, tmp;
	
	// �ʏ�̏������X�L�b�v
	param[0] = 1;
	
	// �ŏ��̃t���[���̏���
	if(statc[player * 10 + 2] == 0) {
		timeOn[player] = 0;
		pinch[player] = 0;
		disp_blkline[player] = 0;
		StopSE(se_hurryup);
		hiddeny[player] = 22;
		
		if(hidden[player]) {
			hidden[player] = 0;
			disableShadowTimer(player);
			statc[player * 10 + 3] = 1;	// HIDDEN���̓u���b�N�������鉉�o�J�n�܂ŊԂ�u��
		}
		
		if(ending[player]) {
			onRecord[player] = 0;
		}
		StopAllBGM();
		
		statc[player * 10] = 21;
		
		// �t�B�[���h�ɉ����Ȃ��ꍇ�̓u���b�N�������鉉�o���ȗ�
		if(isBravo(player)) statc[player * 10] = -2;
		
		statc[player * 10 + 2] = 1;
	}
	
	// ���o�I��
	if(statc[player * 10] <= -2) {
		if(!ending[player] && !tmoGameType) {
			// �R���e�B�j���[�I��
			printFont(foffset[player] + 12, fyoffset[player] + 96, "CONTINUE?", 3);
			
			printFont(foffset[player] + 36, fyoffset[player] + 112, "YES", (statc[player * 10 + 4] == 0) * 2);
			printFont(foffset[player] + 40, fyoffset[player] + 128, "NO", (statc[player * 10 + 4] == 1) * 2);
			
			if(statc[player * 10 + 5] < 600) {
				sprintf(string[0], "TIME %d", 9 - (statc[player * 10 + 5] / 60));
				printFont(foffset[player] + 24, fyoffset[player] + 144, string[0], 1);
			}
			
			// �J�E���^����
			statc[player * 10 + 5]++;
			
			// �I��
			if(getPushState(player, 0) || getPushState(player, 1)) {
				PlaySE(se_move);
				statc[player * 10 + 4] = !statc[player * 10 + 4];
			}
			
			// ����
			if(getPushState(player, 4) || (statc[player * 10 + 5] >= 600)) {
				if(!statc[player * 10 + 4] && getPushState(player, 4)) {
					// YES
					PlaySE(se_kettei);
					
					ready_count[player] = 0;
					disp_blkline[player] = 1;
					nextc[player] = tmoNextc[player];
					setNextBlockColor(player, 1);
					gameTimer[player] = gameTimer[player] * 2;
					
					stat[player] = 3;
					resetField(player);
				} else {
					// NO
					stat[player] = 8;
				}
				for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
			}
		} else {
			stat[player] = 8;
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		}
		
		return;
	}
	
	// �J�E���^����
	statc[player * 10 + 1]++;
	
	// �X�[�b�Ə����Ă������o
	if(statc[player * 10 + 1] > 4 + statc[player * 10 + 3] * 116) {
		block = statc[player * 10];
		
		statc[player * 10 + 1] = 0;
		
		for(j = 0; j < 10; j++) {
			if(block >= 0) {
				c = fldt[j + block * 10 + player * 220];
				if(c == -1) c = 8;
				fldt[j + block * 10 + player * 220] = c - 4;
			}
			
			if(block <= 20) {
				fldt[j + (block + 1) * 10 + player * 220] = fldt[j + (block + 1) * 10 + player * 220] - 4;
			}
		}
		
		statc[player * 10 + 3] = 0;
		statc[player * 10]--;
	}
}

// �ݒ���
void tmoSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(!tmoLoadConfig()) tmoSaveConfig();
	
	// �����L���O��ǂݍ���
	tmoInitRanking();
	tmoLoadRanking(player);
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "TOMOYO-NORMAL OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT D:EDIT E:RANKING", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "START STAGE",    7 * (cursor == 0));
		printFontGrid(2, 4, "STAGE TYPE",     7 * (cursor == 1));
		printFontGrid(2, 5, "GHOST BLOCK",    7 * (cursor == 2));
		printFontGrid(2, 6, "LEVEL UP BONUS", 7 * (cursor == 3));
		printFontGrid(2, 7, "RANDOM MODE",    7 * (cursor == 4));
		printFontGrid(2, 8, "GAME TYPE",      7 * (cursor == 5));
		
		// �ݒ�l�\��
		if(tmoFirstStage >= 20) sprintf(string[0], "EX%d", tmoFirstStage - 19);
		else sprintf(string[0], "%d", tmoFirstStage + 1);
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!tmoStageType) sprintf(string[0], "NORMAL");
		else sprintf(string[0], "EDIT");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(tmoGhost == 0) sprintf(string[0], "LV100");
		else if(tmoGhost == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(!tmoLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(!tmoRandomMode) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		if(!tmoGameType) sprintf(string[0], "NORMAL");
		else sprintf(string[0], "TRAINING");
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
			
			if(cursor == 0) {
				tmoFirstStage = tmoFirstStage + move;
				if(tmoFirstStage < 0) tmoFirstStage = 26;
				if(tmoFirstStage > 26) tmoFirstStage = 0;
			}
			if(cursor == 1) tmoStageType = !tmoStageType;
			if(cursor == 2) {
				tmoGhost = tmoGhost + move;
				if(tmoGhost < 0) tmoGhost = 2;
				if(tmoGhost > 2) tmoGhost = 0;
			}
			if(cursor == 3) tmoLvUpBonus = !tmoLvUpBonus;
			if(cursor == 4) tmoRandomMode = !tmoRandomMode;
			if(cursor == 5) tmoGameType = !tmoGameType;
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
			tmoSaveConfig();
			return;
		}
		
		// �X�e�[�W�G�f�B�b�g
		if(getPushState(player, 7)) {
			tmoStageEdit(player);
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			tmoViewRanking(player);
		}
	}
}

// �ݒ��ۑ�
void tmoSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x4F4D4F54;
	saveBuf[1] = 0x4F4E4F59;
	saveBuf[2] = 0x4C414D52;
	saveBuf[3] = 0x31474643;
	
	// �ݒ���e
	saveBuf[4] = tmoFirstStage;
	saveBuf[5] = tmoStageType;
	saveBuf[6] = tmoGhost;
	saveBuf[7] = tmoLvUpBonus;
	saveBuf[8] = tmoRandomMode;
	saveBuf[9] = tmoGameType;
	
	SaveFile("config/TOMOYO_NORMAL_CONFIG.SAV", &saveBuf, 100 * 4);
}

// �ݒ��ǂݍ���
int tmoLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/TOMOYO_NORMAL_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x4F4D4F54) return 0;
	if(saveBuf[1] != 0x4F4E4F59) return 0;
	if(saveBuf[2] != 0x4C414D52) return 0;
	if(saveBuf[3] != 0x31474643) return 0;
	
	// �ݒ���e
	tmoFirstStage = saveBuf[4];
	tmoStageType = saveBuf[5];
	tmoGhost = saveBuf[6];
	tmoLvUpBonus = saveBuf[7];
	tmoRandomMode = saveBuf[8];
	tmoGameType = saveBuf[9];
	
	return 1;
}

// �X�e�[�W�G�f�B�b�g
void tmoStageEdit(int player) {
	int i, j, fi, temp, dx, dy;
	int cursor, move, edit, cx, cy, color, noset;
	
	cursor = 0;		// ���j���[�̃J�[�\���ʒu
	edit = 0;		// 0=���j���[ 1=�t�B�[���h
	cx = 0;			// �t�B�[���h�G�f�B�b�g��X���W
	cy = 0;			// �t�B�[���h�G�f�B�b�g��Y���W
	color = 0;		// �t�B�[���h�G�f�B�b�g�̃u���b�N�̐F
	noset = 0;		// ��ʂ�؂�ւ����u�Ԃ����Ȃ�u���b�N��u���̂�h��
	
	tmoLoadStage(player, tmoFirstStage, 1);
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		padRepeat(player);
		padRepeat2(player);
		
		if(tmoFirstStage >= 20) sprintf(string[0], "STAGE EDIT EX%d", tmoFirstStage - 19);
		else sprintf(string[0], "STAGE EDIT %d", tmoFirstStage + 1);
		printFontGrid(1, 1, string[0], 4);
		
		// �t�B�[���h��`��
		ExBltFast(sg_black, 16, 40);
		ExBltRect(sg_fld, 8, 32, 4 * 96, 0, 96, 8 + 176);
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
		
		sprintf(string[0], "MIRROR    :%d", tmoIsMirror[player]);
		printFontGrid(15,  8, string[0], (cursor == 3) * 2);
		
		sprintf(string[0], "ROLL      :%d", tmoIsRoll[player]);
		printFontGrid(15,  9, string[0], (cursor == 4) * 2);
		
		sprintf(string[0], "DEATH     :%d", tmoIsBig[player]);
		printFontGrid(15, 10, string[0], (cursor == 5) * 2);
		
		sprintf(string[0], "X-RAY     :%d", tmoIsXRay[player]);
		printFontGrid(15, 11, string[0], (cursor == 6) * 2);
		
		sprintf(string[0], "COLOR     :%d", tmoIsColor[player]);
		printFontGrid(15, 12, string[0], (cursor == 7) * 2);
		
		printFontGrid(15, 13, "LIMIT TIME:", (cursor == 8) * 2);
		getTime(tmoLimitTime[player]);
		printFontGrid(26, 13, string[0], (cursor == 8) * 2);
		
		printFontGrid(15, 14, "STAGE TIME:", (cursor == 9) * 2);
		getTime(tmoStageTime[player]);
		printFontGrid(26, 14, string[0], (cursor == 9) * 2);
		
		sprintf(string[0], "TIME BONUS:%d", tmoTimeBonus[player]);
		printFontGrid(15, 15, string[0], (cursor == 10) * 2);
		
		sprintf(string[0], "LIMIT TYPE:%d", tmoLTType[player]);
		printFontGrid(15, 16, string[0], (cursor == 11) * 2);
		
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
				if(cursor < 0) cursor = 11;
				if(cursor > 11) cursor = 0;
			}
			
			// �l��ύX
			move = 0;
			if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
				move = getPressState(player, 3) - getPressState(player, 2);
			
			if(move) {
				PlaySE(se_kachi);
				
				if(cursor == 3) {
					tmoIsMirror[player] = tmoIsMirror[player] + move;
					if(tmoIsMirror[player] < 0) tmoIsMirror[player] = 99;
					if(tmoIsMirror[player] > 99) tmoIsMirror[player] = 0;
				}
				if(cursor == 4) {
					tmoIsRoll[player] = tmoIsRoll[player] + move;
					if(tmoIsRoll[player] < 0) tmoIsRoll[player] = 99;
					if(tmoIsRoll[player] > 99) tmoIsRoll[player] = 0;
				}
				if(cursor == 5) {
					tmoIsBig[player] = tmoIsBig[player] + move;
					if(tmoIsBig[player] < 0) tmoIsBig[player] = 2;
					if(tmoIsBig[player] > 2) tmoIsBig[player] = 0;
				}
				if(cursor == 6) tmoIsXRay[player] = !tmoIsXRay[player];
				if(cursor == 7) tmoIsColor[player] = !tmoIsColor[player];
				if(cursor == 8) {
					tmoLimitTime[player] = tmoLimitTime[player] + move * 60;
					if(tmoLimitTime[player] < 0) tmoLimitTime[player] = 72000;
					if(tmoLimitTime[player] > 72000) tmoLimitTime[player] = 0;
				}
				if(cursor == 9) {
					tmoStageTime[player] = tmoStageTime[player] + move * 60;
					if(tmoStageTime[player] < 0) tmoStageTime[player] = 72000;
					if(tmoStageTime[player] > 72000) tmoStageTime[player] = 0;
				}
				if(cursor == 10) tmoTimeBonus[player] = !tmoTimeBonus[player];
				if(cursor == 11) tmoLTType[player] = !tmoLTType[player];
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
					tmoLoadStage(player, tmoFirstStage, 1);
				}
				if(cursor == 2) {
					PlayWave(se_kettei);
					tmoSaveStage(player, tmoFirstStage, 1);
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
//  60�`114 ����オ��t�B�[���h�p�ɗ\��i�܂����g�p�j
// 115�`200 �X�e�[�W�̐ݒ�
void tmoSaveStage(int player, int number, int type) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x4F4D4F54;
	saveBuf[1] = 0x4F4D4F59;
	saveBuf[2] = 0x54534544;
	saveBuf[3] = 0x31454741;
	
	// �n�`�f�[�^
	for(i = 0; i < 55; i++) {
		saveBuf[i + 4] = (fld[(i * 4) + 0 + player * 220]);
		saveBuf[i + 4] = saveBuf[i + 4] | (fld[(i * 4) + 1 + player * 220] << 8);
		saveBuf[i + 4] = saveBuf[i + 4] | (fld[(i * 4) + 2 + player * 220] << 16);
		saveBuf[i + 4] = saveBuf[i + 4] | (fld[(i * 4) + 3 + player * 220] << 24);
	}
	
	// �ݒ�f�[�^
	saveBuf[115] = tmoLimitTime[player];
	saveBuf[116] = tmoStageTime[player];
	saveBuf[117] = tmoTimeBonus[player];
	saveBuf[118] = tmoLTType[player];
	saveBuf[119] = tmoIsMirror[player];
	saveBuf[120] = tmoIsRoll[player];
	saveBuf[121] = tmoIsBig[player];
	saveBuf[122] = tmoIsXRay[player];
	saveBuf[123] = tmoIsColor[player];
	
	if(!type) sprintf(string[0], "stage/tomoyo_normal/stage%02d.sav", number);
	else sprintf(string[0], "stage/tomoyo_normal/edit%02d.sav", number);
	SaveFile(string[0], &saveBuf, 200 * 4);
}

// �X�e�[�W��ǂݍ���
int tmoLoadStage(int player, int number, int type) {
	int i;
	
	// �ǂݍ��ݎ��s���Ă����v�Ȃ悤�Ƀ_�~�[�Ńf�t�H���g�l��ݒ�
	resetField(player);
	tmoLimitTime[player] = 10800;
	tmoStageTime[player] = 3600;
	tmoTimeBonus[player] = 1;
	tmoLTType[player] = 1;
	tmoIsMirror[player] = 0;
	tmoIsRoll[player] = 0;
	tmoIsBig[player] = 0;
	tmoIsXRay[player] = 0;
	tmoIsColor[player] = 0;
	
	// �ǂݍ��݊J�n
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	if(!type) sprintf(string[0], "stage/tomoyo_normal/stage%02d.sav", number);
	else sprintf(string[0], "stage/tomoyo_normal/edit%02d.sav", number);
	LoadFile(string[0], &saveBuf, 200 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x4F4D4F54) return 0;
	if(saveBuf[1] != 0x4F4D4F59) return 0;
	if(saveBuf[2] != 0x54534544) return 0;
	if(saveBuf[3] != 0x31454741) return 0;
	
	// �n�`�f�[�^
	for(i = 0; i < 55; i++) {
		fld[(i * 4) + 0 + player * 220] = (saveBuf[4 + i] & 0x000000FF);
		fld[(i * 4) + 1 + player * 220] = (saveBuf[4 + i] & 0x0000FF00) >> 8;
		fld[(i * 4) + 2 + player * 220] = (saveBuf[4 + i] & 0x00FF0000) >> 16;
		fld[(i * 4) + 3 + player * 220] = (saveBuf[4 + i] & 0xFF000000) >> 24;
	}
	disableShadowTimer(player);
	
	// �ݒ�f�[�^
	tmoLimitTime[player] = saveBuf[115];
	tmoStageTime[player] = saveBuf[116];
	tmoTimeBonus[player] = saveBuf[117];
	tmoLTType[player] = saveBuf[118];
	tmoIsMirror[player] = saveBuf[119];
	tmoIsRoll[player] = saveBuf[120];
	tmoIsBig[player] = saveBuf[121];
	tmoIsXRay[player] = saveBuf[122];
	tmoIsColor[player] = saveBuf[123];
	
	return 1;
}

// ���v���C�ڍ�
void tmoReplayDetail() {
	printFontGrid(1, 4, "STAGE", 0);
	if(saveBuf[905] >= 20) sprintf(string[0], "EX%d", saveBuf[905] - 19);
	else sprintf(string[0], "%d", saveBuf[905] + 1);
	printFontGrid(22, 4, string[0], 0);
	
	printFontGrid(1, 5, "CLEAR", 0);
	sprintf(string[0], "%d%%", saveBuf[906]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 7, "START STAGE", 0);
	if(saveBuf[900] >= 20) sprintf(string[0], "EX%d", saveBuf[900] - 19);
	else sprintf(string[0], "%d", saveBuf[900] + 1);
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 8, "STAGE TYPE", 0);
	if(!saveBuf[901]) sprintf(string[0], "NORMAL");
	else sprintf(string[0], "EDIT");
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "GHOST BLOCK", 0);
	if(saveBuf[902] == 0) sprintf(string[0], "LV100");
	else if(saveBuf[902] == 1) sprintf(string[0], "ON");
	else sprintf(string[0], "OFF");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "LEVEL UP BONUS", 0);
	if(!saveBuf[903]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "RANDOM MODE", 0);
	if(!saveBuf[904]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "GAME TYPE", 0);
	if(!saveBuf[908]) sprintf(string[0], "NORMAL");
	else sprintf(string[0], "TRAINING");
	printFontGrid(22, 12, string[0], 0);
	
	printFontGrid(1, 14, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[907]);
	printFontGrid(22, 14, string[0], 0);
}

// ���v���C��ۑ�
void tmoSaveReplay(int player) {
	saveBuf[900] = tmoFirstStage;
	saveBuf[901] = tmoStageType;
	saveBuf[902] = tmoGhost;
	saveBuf[903] = tmoLvUpBonus;
	saveBuf[904] = tmoRandomMode;
	saveBuf[905] = tmoStage[player];
	saveBuf[906] = tmoClearPer[player];
	saveBuf[907] = tmoVersion;
	saveBuf[908] = tmoGameType;
}

// ���v���C��ǂݍ���
void tmoLoadReplay(int player) {
	tmoFirstStage = saveBuf[900];
	tmoStageType = saveBuf[901];
	tmoGhost = saveBuf[902];
	tmoLvUpBonus = saveBuf[903];
	tmoRandomMode = saveBuf[904];
	tmoVersion = saveBuf[907];
	tmoGameType = saveBuf[908];
	
	tmoPlayerInitial(player);
}

// �����L���O�ۑ�
void tmoSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 2;
	
	// �����L���O���e
	for(i = 0; i < 5 * 2; i++) {
		saveBuf[1 + (i * 10) + 0] = tmoRankingStage[i];
		saveBuf[1 + (i * 10) + 1] = tmoRankingClear[i];
		saveBuf[1 + (i * 10) + 2] = tmoRankingTime[i];
		saveBuf[1 + (i * 10) + 3] = tmoRankingEnd[i];
		saveBuf[1 + (i * 10) + 4] = tmoRankingYear[i];
		saveBuf[1 + (i * 10) + 5] = tmoRankingMonth[i];
		saveBuf[1 + (i * 10) + 6] = tmoRankingDay[i];
		saveBuf[1 + (i * 10) + 7] = tmoRankingHour[i];
		saveBuf[1 + (i * 10) + 8] = tmoRankingMinute[i];
		saveBuf[1 + (i * 10) + 9] = tmoRankingSecond[i];
	}
	
	// �Z�N�V�����^�C�������L���O���e
	for(i = 0; i < 27; i++) {
		saveBuf[111 + (i * 10) + 0] = tmoRankingSectionTime[i];
		saveBuf[111 + (i * 10) + 1] = tmoRankingSectionRand[i];
		saveBuf[111 + (i * 10) + 2] = tmoRankingSectionEnd[i];
		saveBuf[111 + (i * 10) + 3] = tmoRankingSectionYear[i];
		saveBuf[111 + (i * 10) + 4] = tmoRankingSectionMonth[i];
		saveBuf[111 + (i * 10) + 5] = tmoRankingSectionDay[i];
		saveBuf[111 + (i * 10) + 6] = tmoRankingSectionHour[i];
		saveBuf[111 + (i * 10) + 7] = tmoRankingSectionMinute[i];
		saveBuf[111 + (i * 10) + 8] = tmoRankingSectionSecond[i];
	}
	
	sprintf(string[0], "config/TOMOYO_NORMAL_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 391 * 4);
}

// �����L���O�ǂݍ���
int tmoLoadRanking(int player) {
	int i, size;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/TOMOYO_NORMAL_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	
	// �w�b�_�����ǂݍ���
	LoadFile(string[0], &saveBuf, 1 * 4);
	
	// �w�b�_���e�ɉ����ēǂݍ��ރT�C�Y�����߂�
	if(saveBuf[0] == 1) size = 111 * 4;
	else if(saveBuf[0] == 2) size = 391 * 4;
	else return 0;
	LoadFile(string[0], &saveBuf, size);
	
	// �����L���O���e
	for(i = 0; i < 5 * 2; i++) {
		tmoRankingStage[i]  = saveBuf[1 + (i * 10) + 0];
		tmoRankingClear[i]  = saveBuf[1 + (i * 10) + 1];
		tmoRankingTime[i]   = saveBuf[1 + (i * 10) + 2];
		tmoRankingEnd[i]    = saveBuf[1 + (i * 10) + 3];
		tmoRankingYear[i]   = saveBuf[1 + (i * 10) + 4];
		tmoRankingMonth[i]  = saveBuf[1 + (i * 10) + 5];
		tmoRankingDay[i]    = saveBuf[1 + (i * 10) + 6];
		tmoRankingHour[i]   = saveBuf[1 + (i * 10) + 7];
		tmoRankingMinute[i] = saveBuf[1 + (i * 10) + 8];
		tmoRankingSecond[i] = saveBuf[1 + (i * 10) + 9];
	}
	
	// �Z�N�V�����^�C�������L���O���e
	if(saveBuf[0] == 2) {
		for(i = 0; i < 27; i++) {
			tmoRankingSectionTime[i]   = saveBuf[111 + (i * 10) + 0];
			tmoRankingSectionRand[i]   = saveBuf[111 + (i * 10) + 1];
			tmoRankingSectionEnd[i]    = saveBuf[111 + (i * 10) + 2];
			tmoRankingSectionYear[i]   = saveBuf[111 + (i * 10) + 3];
			tmoRankingSectionMonth[i]  = saveBuf[111 + (i * 10) + 4];
			tmoRankingSectionDay[i]    = saveBuf[111 + (i * 10) + 5];
			tmoRankingSectionHour[i]   = saveBuf[111 + (i * 10) + 6];
			tmoRankingSectionMinute[i] = saveBuf[111 + (i * 10) + 7];
			tmoRankingSectionSecond[i] = saveBuf[111 + (i * 10) + 8];
		}
	}
	
	return 1;
}

// �����L���O������
void tmoInitRanking() {
	int i;
	
	for(i = 0; i < 5 * 2; i++) {
		tmoRankingStage[i]  = 0;
		tmoRankingClear[i]  = 0;
		tmoRankingTime[i]   = 0;
		tmoRankingEnd[i]    = 0;
		tmoRankingYear[i]   = 0;
		tmoRankingMonth[i]  = 0;
		tmoRankingDay[i]    = 0;
		tmoRankingHour[i]   = 0;
		tmoRankingMinute[i] = 0;
		tmoRankingSecond[i] = 0;
	}
	
	for(i = 0; i < 27; i++) {
		tmoRankingSectionTime[i]   = 3600;
		tmoRankingSectionRand[i]   = 0;
		tmoRankingSectionEnd[i]    = 0;
		tmoRankingSectionYear[i]   = 0;
		tmoRankingSectionMonth[i]  = 0;
		tmoRankingSectionDay[i]    = 0;
		tmoRankingSectionHour[i]   = 0;
		tmoRankingSectionMinute[i] = 0;
		tmoRankingSectionSecond[i] = 0;
	}
}

// �����L���O�o�^
int tmoRegistRanking(int player) {
	int i, j, temp, temp2, timebuf[8];
	
	if((playback) || (tmoFirstStage != 0) || (tmoGameType) || (tmoStageType)) return -1;
	
	for(i = 0; i < 5; i++) {
		temp = i + tmoRandomMode * 5;
		
		if(
		   (tmoEndFlag[player] > tmoRankingEnd[temp]) || 
		   ((tmoEndFlag[player] == tmoRankingEnd[temp]) && (tmoStage[player] > tmoRankingStage[temp])) || 
		   ((tmoEndFlag[player] == tmoRankingEnd[temp]) && (tmoStage[player] == tmoRankingStage[temp]) && (gameTimer[player] < tmoRankingTime[temp]))
		  )
		{
			// �����L���O�����炷
			for(j = 4; j > i; j--) {
				temp = j + tmoRandomMode * 5;
				temp2 = (j - 1) + tmoRandomMode * 5;
				
				tmoRankingStage[temp]  = tmoRankingStage[temp2];
				tmoRankingClear[temp]  = tmoRankingClear[temp2];
				tmoRankingTime[temp]   = tmoRankingTime[temp2];
				tmoRankingEnd[temp]    = tmoRankingEnd[temp2];
				tmoRankingYear[temp]   = tmoRankingYear[temp2];
				tmoRankingMonth[temp]  = tmoRankingMonth[temp2];
				tmoRankingDay[temp]    = tmoRankingDay[temp2];
				tmoRankingHour[temp]   = tmoRankingHour[temp2];
				tmoRankingMinute[temp] = tmoRankingMinute[temp2];
				tmoRankingSecond[temp] = tmoRankingSecond[temp2];
			}
			
			// �V�����f�[�^��o�^
			temp = i + tmoRandomMode * 5;
			
			tmoRankingStage[temp]  = tmoStage[player];
			tmoRankingClear[temp]  = tmoClearPer[player];
			tmoRankingTime[temp]   = gameTimer[player];
			tmoRankingEnd[temp]    = tmoEndFlag[player];
			
			GetDateAndTime(&timebuf);
			tmoRankingYear[temp]   = timebuf[0];
			tmoRankingMonth[temp]  = timebuf[1];
			tmoRankingDay[temp]    = timebuf[2];
			tmoRankingHour[temp]   = timebuf[4];
			tmoRankingMinute[temp] = timebuf[5];
			tmoRankingSecond[temp] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �Z�N�V�����^�C�������L���O�X�V
int tmoUpdateSectionTimeRanking(int player) {
	int i, timebuf[8], result;
	result = 0;
	
	if((playback) || (tmoStageType)) return 0;
	
	for(i = 0; i < 27; i++) {
		if( ((tmoSectionTime[i + player * 27] < tmoRankingSectionTime[i]) || (tmoRankingSectionTime[i] == 0)) &&
		    (tmoSectionTime[i + player * 27] != 0) )
		{
			result++;
			
			tmoRankingSectionTime[i] = tmoSectionTime[i + player * 27];
			tmoRankingSectionRand[i] = tmoRandomMode;
			tmoRankingSectionEnd[i] = tmoEndFlag[player];
			
			GetDateAndTime(&timebuf);
			tmoRankingSectionYear[i] = timebuf[0];
			tmoRankingSectionMonth[i] = timebuf[1];
			tmoRankingSectionDay[i] = timebuf[2];
			tmoRankingSectionHour[i] = timebuf[4];
			tmoRankingSectionMinute[i] = timebuf[5];
			tmoRankingSectionSecond[i] = timebuf[6];
		}
	}
	
	return result;
}

// �����L���O�\��
void tmoViewRanking(int player) {
	int i, cursor, move, erasemode, stmode, temp, temp2, page;
	cursor = 0;
	move = 0;
	erasemode = 0;
	stmode = 0;
	page = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		if(!stmode) {
			// �m�[�}�������L���O
			printFontGrid(37, 1, ">>", 6);
			printFontGrid(1, 1, "NORMAL MODE RANKING", 6);
			printFontGrid(1, 3, "RANK STAGE CLEAR TIME", 4);
			printFontGrid(1, 11, "RANDOM MODE RANKING", 6);
			printFontGrid(1, 13, "RANK STAGE CLEAR TIME", 4);
			
			for(i = 0; i < 5 * 2; i++) {
				temp = i;
				if(i >= 5) temp = 10 + (i - 5);
				
				if(tmoRankingEnd[i]) ExBltFastRect(sg_line, 0, (4 + temp) * 8 + 6, 0, (tmoRankingEnd[i] - 1) * 2, 320, 2);
				
				if((i == 0) || (i == 5)) sprintf(string[0], "1ST");
				if((i == 1) || (i == 6)) sprintf(string[0], "2ND");
				if((i == 2) || (i == 7)) sprintf(string[0], "3RD");
				if((i == 3) || (i == 8)) sprintf(string[0], "4TH");
				if((i == 4) || (i == 9)) sprintf(string[0], "5TH");
				printFontGrid(1, 4 + temp, string[0], 7 * (cursor == i));
				
				if(tmoRankingStage[i] >= 20) sprintf(string[0], "EX%d", tmoRankingStage[i] - 19);
				else sprintf(string[0], "%d", tmoRankingStage[i] + 1);
				printFontGrid(6, 4 + temp, string[0], 7 * (cursor == i));
				
				sprintf(string[0], "%d%%", tmoRankingClear[i]);
				printFontGrid(12, 4 + temp, string[0], 7 * (cursor == i));
				
				getTime(tmoRankingTime[i]);
				printFontGrid(18, 4 + temp, string[0], 7 * (cursor == i));
			}
			
			for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
			
			if(!erasemode) {
				// ���t�Ǝ���
				sprintf(string[0],
				        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
				        tmoRankingYear[cursor], tmoRankingMonth[cursor], tmoRankingDay[cursor],
				        tmoRankingHour[cursor], tmoRankingMinute[cursor], tmoRankingSecond[cursor]);
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
					tmoInitRanking();
					tmoSaveRanking(player);
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
			printFontGrid(1, 1, "<< SECTION TIME RANKING", 6);
			printFontGrid(1, 3, "NO. TIME     RAND DATE", 4);
			sprintf(string[0], "PAGE %d/2", page + 1);
			printFontGrid(1, 27, string[0], 6);
			printFontGrid(1, 28, "A/B:EXIT UP/DOWN:PAGE CHANGE", 6);
			
			for(i = 0; i < 20; i++) {
				temp = i + page * 20;
				if(temp >= 27) break;
				
				if(tmoRankingSectionEnd[temp]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (tmoRankingSectionEnd[temp] - 1) * 2, 320, 2);
				
				if(temp >= 20) sprintf(string[0], "EX%d", temp - 19);
				else sprintf(string[0], "%3d", temp + 1);
				printFontGrid(1, 4 + i, string[0], 0);
				
				getTime(tmoRankingSectionTime[temp]);
				printFontGrid(5, 4 + i, string[0], 0);
				
				if(!tmoRankingSectionRand[temp]) sprintf(string[0], "OFF");
				else sprintf(string[0], "ON");
				printFontGrid(14, 4 + i, string[0], 0);
				
				temp2 = (tmoRankingSectionYear[temp] / 1000) * 1000;	// �N����2�������\��
				if(temp2 == 0) temp2 = 1;
				sprintf(string[0], "%02d/%02d/%02d", tmoRankingSectionYear[temp] % temp2, tmoRankingSectionMonth[temp], tmoRankingSectionDay[temp]);
				printFontGrid(19, 4 + i, string[0], 0);
				
				sprintf(string[0], "%02d:%02d:%02d", tmoRankingSectionHour[temp], tmoRankingSectionMinute[temp], tmoRankingSectionSecond[temp]);
				printFontGrid(28, 4 + i, string[0], 0);
			}
			
			// �y�[�W�ړ�
			padRepeat2(player);
			
			move = 0;
			if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
				move = getPressState(player, 1) - getPressState(player, 0);
			
			if(move) {
				PlaySE(se_kachi);
				page = page + move;
				if(page < 0) page = 1;
				if(page > 1) page = 0;
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
