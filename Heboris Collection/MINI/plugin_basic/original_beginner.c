//ORIGINAL-BEGINNER
//prefix:obeg

// ���x���A�b�v�e�[�u��
int obegLevelTable[100] = 
{
	  1,   3,   4,   5,   6,   8,  10,  12,  15,  20,
	 20,   1,   2,   4,   6,  10,  12,  15,  20,  30,
	  2,   4,   6,  10,  15,  20,  30,  45,  60,  60,
	 60,  60,  60,  60,  10,  20,  30,  60,  60,  60,
	 60,  60,  60,  60,  60,  60,  60,  60,  60,  60,
	 60,  60,  60,  60,  60,  60,  60,  60,  60,  60,
	120, 120, 120, 120, 120, 120, 120, 120, 120, 120,
	120, 120, 120, 120, 120, 240, 240, 240, 240, 240,
	240, 240, 240, 240, 240, 240, 240, 240, 240, 240,
	300, 300, 300, 300, 300, 300, 300, 300, 300, 1200
};

// �ϐ�
int obegModeNo = -1;		// ���[�h�ԍ�
int obegScore[2];			// �X�R�A
int obegRate[2];			// �R���{�{�[�i�X�p�ϐ�
int obegLines[2];			// ���C��
int obegLevel[2];			// ���x��
int obegLc[2];				// ���x���A�b�v�܂ł̃J�E���^
int obegLvUpAnim[2];		// ���x���A�b�v����A������_�ł����鎞��

int obegIsBig = 0;			// BIG���ǂ���
int obegBigMove = 1;		// BIG���̉��ړ��P��
int obegStartLevel = 0;		// �J�n���x��
int obegBgm = 0;			// �g�p����BGM
int obegGhost = 1;			// �S�[�X�g�̐ݒ�

// �����L���O�p�ϐ�
int obegRankingScore[10];	// �X�R�A
int obegRankingLines[10];	// ���C��
int obegRankingLevel[10];	// ���x��
int obegRankingTime[10];	// �^�C��
int obegRankingYear[10];	// �����N�C�������i�N�j
int obegRankingMonth[10];	// �����N�C�������i���j
int obegRankingDay[10];		// �����N�C�������i���j
int obegRankingHour[10];	// �����N�C�������i���j
int obegRankingMinute[10];	// �����N�C�������i���j
int obegRankingSecond[10];	// �����N�C�������i�b�j

// �C�x���g����
void obegPluginEvent(int player, int event, int *param) {
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != obegModeNo)) return;
	
	if(event == 0) {
		obegModeNo = addModePlugin("ORIGINAL-BEGINNER");	// ���[�h��o�^����
	} else if(event == 8) {
		obegSoftDropScore(player);	// �\�t�g�h���b�v�œ������_�������Z
	} else if(event == 10) {
		obegARE(player);	// ARE��
	} else if(event == 13) {
		obegCalcScore(player, param[0]);	// �X�R�A�v�Z
	} else if(event == 15) {
		obegViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		obegSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		obegPlayerInitial(player);	// ������
	} else if(event == 21) {
		obegResult(player);	// ���ʕ\��
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		obegSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		obegLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		obegLoadBGM();	// BGM�ǂݍ���
	} else if(event == 48) {
		obegSoftDropOld(player);	// �\�t�g�h���b�v�i���j
	} else if(event == 49) {
		obegHardDrop(player, param[1]);	// �n�[�h�h���b�v
	} else if(event == 55) {
		obegReplayDetail();	// ���v���C�ڍ�
	}
}

// ������
void obegPlayerInitial(int player) {
	// �ϐ���������
	obegScore[player] = 0;
	obegRate[player] = 0;
	obegLines[player] = 0;
	obegLevel[player] = obegStartLevel;
	obegLc[player] = 0;
	obegLvUpAnim[player] = 0;
	
	// �R���{�L��
	enable_combo[player] = 1;
	
	// �g�̐F��ς���
	framecolor[player] = 9;
	
	// �������x
	// �t���[���֘A�̏�����啝�ɕς����̂ŁA�{�ƂƔ����Ƀ^�C�~���O���Ⴄ�����c
	sp[player] = obegLevelTable[obegStartLevel];
	wait1[player] = 26 + 3;
	wait2[player] = 40;
	wait3[player] = 28 + 2;
	waitt[player] = 15;
	backno = obegLevel[player] / 3;
	if(backno > 19) backno = 19;
	
	if( ((obegLevel[player] >= 12) && (!obegGhost)) || (obegGhost == 2) ) ghost[player] = 0;
	
	// �ݒ�𔽉f������
	IsBig[player] = obegIsBig;
	BigMove[player] = obegBigMove;
	bgmlv = obegBgm;
}

// ARE��
void obegARE(int player) {
	// ���x���J�E���^�{�P
	if(statc[player * 10] == wait1[player] - lockflash[player]) obegLc[player]++;
	
	// ���x���A�b�v����
	if(obegLc[player] > 100) {
		obegLc[player] = obegLc[player] - 100;
		
		obegLevel[player]++;
		obegLvUpAnim[player] = 180;
		
		if(obegLevel[player] < 100) sp[player] = obegLevelTable[obegLevel[player]];
		
		if(obegLevel[player] % 3 == 0) {
			PlaySE(se_levelup);
			
			if(obegLevel[player] / 3 < 20) {
				bgfadesw = 1;
				bgfadebg = obegLevel[player] / 3;
			}
		}
		
		if((obegLevel[player] >= 12) && (!obegGhost)) ghost[player] = 0;
	}
}

// �X�R�A�v�Z
void obegCalcScore(int player, int lines) {
	int bo, bai, all;
	
	// ��{�_
	if(combo[player] == 1) obegRate[player] = 100;
	
	if(lines == 1) {
		bo = 1 * obegRate[player];
		obegRate[player] = obegRate[player] + 5;
	}
	if(lines == 2) {
		bo = 4 * obegRate[player];
		obegRate[player] = obegRate[player] + 10;
	}
	if(lines == 3) {
		bo = 9 * obegRate[player];
		obegRate[player] = obegRate[player] + 30;
	}
	if(lines == 4) {
		bo = 20 * obegRate[player];
		obegRate[player] = obegRate[player] + 50;
	}
	
	// ���x�ɂ��{�[�i�X
	bai = 1 + (sp[player] >= 20) + (sp[player] >= 60) + (sp[player] >= 240) + (sp[player] >= 640);
	
	// �S��������ƃX�R�A10�{
	if(isBravo(player)) {
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		bo = bo * 10;
	}
	
	// �X�R�A���Z
	obegScore[player] = obegScore[player] + bo * bai;
	obegLines[player] = obegLines[player] + lines;
	obegLc[player] = obegLc[player] + lines * 20;
}

// �\�t�g�h���b�v�i���j
void obegSoftDropOld(int player) {
	if((!down_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) && (engineVer <= 12)) {
		if(sp[player] < (softspeed[player] + 1) * 30) {
			obegScore[player]++;
		}
	}
}

// �n�[�h�h���b�v
void obegHardDrop(int player, int bottom) {
	if((!up_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0)) {
		if(sp[player] <= 240) {
			obegScore[player] = obegScore[player] + (bottom - by[player]) * 23 / 20;	// �ʏ��15%���̓_���l��
		}
	}
}

// �\�t�g�h���b�v�œ������_�������Z
void obegSoftDropScore(int player) {
	if(softd_score[player] > 0) {
		obegScore[player] = obegScore[player] + softd_score[player];
	}
}

// �X�R�A�\��
void obegViewScore(int player) {
	int color, color2;
	color = (count % 4 / 2) * (sp[player] >= 1200) * 2;
	
	// �X�R�A
	printFont(foffset[player] + 96, fyoffset[player] + 40, "SCORE", 2);
	if(obegScore[player] > 9999999) obegScore[player] = 9999999;
	sprintf(string[0], "%d", obegScore[player]);
	printFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// ���C��
	printFont(foffset[player] + 96, fyoffset[player] + 64, "LINES", 2);
	if(obegLines[player] > 9999) obegLines[player] = 9999;
	sprintf(string[0], "%d", obegLines[player]);
	printFont(foffset[player] + 96, fyoffset[player] + 72, string[0], color);
	
	// ���x��
	printFont(foffset[player] + 96, fyoffset[player] + 88, "LEVEL", 2);
	if(obegLevel[player] > 999) obegLevel[player] = 999;
	sprintf(string[0], "%d", obegLevel[player]);
	if(!obegLvUpAnim[player]) {
		color2 = color;
	} else {
		color2 = 7 * (count % 4 / 2);
		obegLvUpAnim[player]--;
	}
	printFont(foffset[player] + 96, fyoffset[player] + 96, string[0], color2);
	
	// �^�C��
	if(gameTimer[player] > 359999) gameTimer[player] = 359999;
	getTime(gameTimer[player]);
	printFont(foffset[player] + 16, fyoffset[player] + 224, string[0], color);
}

// ���ʕ\��
void obegResult(int player) {
	// �����L���O�o�^
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = obegRegistRanking(player);
		if(statc[player * 10 + 1] != -1) obegSaveRanking(player);
	}
	
	printFont(foffset[player] + 8, fyoffset[player] + 48, "PLAY DATA", 4);
	
	// �X�R�A
	printFont(foffset[player] + 8, fyoffset[player] + 64, "SCORE", 2);
	sprintf(string[0], "%10d", obegScore[player]);
	printFont(foffset[player] + 8, fyoffset[player] + 72, string[0], 0);
	
	// ���C��
	printFont(foffset[player] + 8, fyoffset[player] + 88, "LINES", 2);
	sprintf(string[0], "%10d", obegLines[player]);
	printFont(foffset[player] + 8, fyoffset[player] + 96, string[0], 0);
	
	// ���x��
	printFont(foffset[player] + 8, fyoffset[player] + 112, "LEVEL", 2);
	sprintf(string[0], "%10d", obegLevel[player]);
	printFont(foffset[player] + 8, fyoffset[player] + 120, string[0], 0);
	
	// �^�C��
	printFont(foffset[player] + 8, fyoffset[player] + 136, "TIME", 2);
	getTime(gameTimer[player]);
	printFont(foffset[player] + 24, fyoffset[player] + 144, string[0], 0);
	
	// �����L���O����
	if(statc[player * 10 + 1] != -1) {
		printFont(foffset[player] + 8, fyoffset[player] + 160, "RANK", 2);
		sprintf(string[0], "%10d", statc[player * 10 + 1] + 1);
		printFont(foffset[player] + 8, fyoffset[player] + 168, string[0], 0);
	}
}

// BGM�ǂݍ���
void obegLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(obegBgm);
	}
}

// �ݒ���
void obegSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(obegLoadConfig() == 0) obegSaveConfig();
	
	// �����L���O��ǂݍ���
	if(obegLoadRanking(player) == 0) obegInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ORIGINAL-BEGINNER OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "BIG",         7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",    7 * (cursor == 1));
		printFontGrid(2, 5, "START LEVEL", 7 * (cursor == 2));
		printFontGrid(2, 6, "BGM",         7 * (cursor == 3));
		printFontGrid(2, 7, "GHOST BLOCK", 7 * (cursor == 4));
		
		// �ݒ�l�\��
		if(!obegIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!obegBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "%d", obegStartLevel);
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "%d", obegBgm);
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(obegGhost == 0) sprintf(string[0], "LV12");
		else if(obegGhost == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		// �J�[�\���ړ�
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 4;
			if(cursor > 4) cursor = 0;
		}
		
		// �l��ύX
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			if(cursor == 0) obegIsBig = !obegIsBig;
			if(cursor == 1) obegBigMove = !obegBigMove;
			if(cursor == 2) {
				obegStartLevel = obegStartLevel + move;
				if(obegStartLevel < 0) obegStartLevel = 99;
				if(obegStartLevel > 99) obegStartLevel = 0;
			}
			if(cursor == 3) {
				obegBgm = obegBgm + move;
				if(obegBgm < 0) obegBgm = 29;
				if(obegBgm > 29) obegBgm = 0;
			}
			if(cursor == 4) {
				obegGhost = obegGhost + move;
				if(obegGhost < 0) obegGhost = 2;
				if(obegGhost > 2) obegGhost = 0;
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
			obegSaveConfig();
			return;
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			obegViewRanking(player);
		}
	}
}

// �ݒ��ۑ�
void obegSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x4745424F;
	saveBuf[1] = 0x454E4E49;
	saveBuf[2] = 0x4E4F4352;
	saveBuf[3] = 0x31474946;
	
	// �ݒ���e
	saveBuf[4] = obegIsBig;
	saveBuf[5] = obegBigMove;
	saveBuf[6] = obegStartLevel;
	saveBuf[7] = obegBgm;
	saveBuf[8] = obegGhost;
	
	SaveFile("config/ORIGINAL_BEGINNER_CONFIG.SAV", &saveBuf, 100 * 4);
}

// �ݒ��ǂݍ���
int obegLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/ORIGINAL_BEGINNER_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x4745424F) return 0;
	if(saveBuf[1] != 0x454E4E49) return 0;
	if(saveBuf[2] != 0x4E4F4352) return 0;
	if(saveBuf[3] != 0x31474946) return 0;
	
	// �ݒ���e
	obegIsBig = saveBuf[4];
	obegBigMove = saveBuf[5];
	obegStartLevel = saveBuf[6];
	obegBgm = saveBuf[7];
	obegGhost = saveBuf[8];
	
	return 1;
}

// ���v���C�ۑ�
void obegSaveReplay(int player) {
	saveBuf[900] = obegScore[player];
	saveBuf[901] = obegLines[player];
	saveBuf[902] = obegLevel[player];
	saveBuf[903] = obegIsBig;
	saveBuf[904] = obegBigMove;
	saveBuf[905] = obegStartLevel;
	saveBuf[906] = obegBgm;
	saveBuf[907] = obegGhost;
}

// ���v���C�ǂݍ���
void obegLoadReplay(int player) {
	obegIsBig = saveBuf[903];
	obegBigMove = saveBuf[904];
	obegStartLevel = saveBuf[905];
	obegBgm = saveBuf[906];
	obegGhost = saveBuf[907];
	
	obegPlayerInitial(player);	// �ݒ�𔽉f������
}

// ���v���C�ڍ�
void obegReplayDetail() {
	printFontGrid(1, 4, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[900]);
	printFontGrid(22, 4, string[0], 0);
	
	printFontGrid(1, 5, "LINES", 0);
	sprintf(string[0], "%d", saveBuf[901]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[902]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "BIG", 0);
	if(!saveBuf[903]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 8, "BIG MOVE", 0);
	if(!saveBuf[904]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[905]);
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "BGM", 0);
	sprintf(string[0], "%d", saveBuf[906]);
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "GHOST BLOCK", 0);
	if(saveBuf[907] == 0) sprintf(string[0], "LV12");
	else if(saveBuf[907] == 1) sprintf(string[0], "ON");
	else sprintf(string[0], "OFF");
	printFontGrid(22, 11, string[0], 0);
}

// �����L���O�ۑ�
void obegSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 10) + 0] = obegRankingScore[i];
		saveBuf[1 + (i * 10) + 1] = obegRankingLines[i];
		saveBuf[1 + (i * 10) + 2] = obegRankingLevel[i];
		saveBuf[1 + (i * 10) + 3] = obegRankingTime[i];
		saveBuf[1 + (i * 10) + 4] = obegRankingYear[i];
		saveBuf[1 + (i * 10) + 5] = obegRankingMonth[i];
		saveBuf[1 + (i * 10) + 6] = obegRankingDay[i];
		saveBuf[1 + (i * 10) + 7] = obegRankingHour[i];
		saveBuf[1 + (i * 10) + 8] = obegRankingMinute[i];
		saveBuf[1 + (i * 10) + 9] = obegRankingSecond[i];
	}
	
	sprintf(string[0], "config/ORIGINAL_BEGINNER_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 111 * 4);
}

// �����L���O�ǂݍ���
int obegLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/ORIGINAL_BEGINNER_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 111 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		obegRankingScore[i]  = saveBuf[1 + (i * 10) + 0];
		obegRankingLines[i]  = saveBuf[1 + (i * 10) + 1];
		obegRankingLevel[i]  = saveBuf[1 + (i * 10) + 2];
		obegRankingTime[i]   = saveBuf[1 + (i * 10) + 3];
		obegRankingYear[i]   = saveBuf[1 + (i * 10) + 4];
		obegRankingMonth[i]  = saveBuf[1 + (i * 10) + 5];
		obegRankingDay[i]    = saveBuf[1 + (i * 10) + 6];
		obegRankingHour[i]   = saveBuf[1 + (i * 10) + 7];
		obegRankingMinute[i] = saveBuf[1 + (i * 10) + 8];
		obegRankingSecond[i] = saveBuf[1 + (i * 10) + 9];
	}
	
	return 1;
}

// �����L���O������
void obegInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		obegRankingScore[i]  = 0;
		obegRankingLines[i]  = 0;
		obegRankingLevel[i]  = 0;
		obegRankingTime[i]   = 0;
		obegRankingYear[i]   = 0;
		obegRankingMonth[i]  = 0;
		obegRankingDay[i]    = 0;
		obegRankingHour[i]   = 0;
		obegRankingMinute[i] = 0;
		obegRankingSecond[i] = 0;
	}
}

// �����L���O�o�^
int obegRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (obegIsBig)) return -1;
	
	for(i = 0; i < 10; i++) {
		// �����N�C��
		if(obegScore[player] > obegRankingScore[i]) {
			// �����L���O�����炷
			for(j = 9; j > i; j--) {
				obegRankingScore[j]  = obegRankingScore[j - 1];
				obegRankingLines[j]  = obegRankingLines[j - 1];
				obegRankingLevel[j]  = obegRankingLevel[j - 1];
				obegRankingTime[j]   = obegRankingTime[j - 1];
				obegRankingYear[j]   = obegRankingYear[j - 1];
				obegRankingMonth[j]  = obegRankingMonth[j - 1];
				obegRankingDay[j]    = obegRankingDay[j - 1];
				obegRankingHour[j]   = obegRankingHour[j - 1];
				obegRankingMinute[j] = obegRankingMinute[j - 1];
				obegRankingSecond[j] = obegRankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			obegRankingScore[i]  = obegScore[player];
			obegRankingLines[i]  = obegLines[player];
			obegRankingLevel[i]  = obegLevel[player];
			obegRankingTime[i]   = gameTimer[player];
			
			GetDateAndTime(&timebuf);
			obegRankingYear[i]   = timebuf[0];
			obegRankingMonth[i]  = timebuf[1];
			obegRankingDay[i]    = timebuf[2];
			obegRankingHour[i]   = timebuf[4];
			obegRankingMinute[i] = timebuf[5];
			obegRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �����L���O�\��
void obegViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ORIGINAL-BEGINNER MODE RANKING", 6);
		printFontGrid(1, 3, "RANK SCORE   LINES LEVEL TIME", 4);
		
		for(i = 0; i < 10; i++) {
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", obegRankingScore[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", obegRankingLines[i]);
			printFontGrid(14, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", obegRankingLevel[i]);
			printFontGrid(20, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(obegRankingTime[i]);
			printFontGrid(26, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// ���t�Ǝ���
			sprintf(string[0],
			        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
			        obegRankingYear[cursor], obegRankingMonth[cursor], obegRankingDay[cursor],
			        obegRankingHour[cursor], obegRankingMinute[cursor], obegRankingSecond[cursor]);
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
				obegInitRanking();
				obegSaveRanking(player);
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
