//ORIGINAL-MASTER
//prefix:omas

// ���x���A�b�v�e�[�u��
// �t���[���֘A�̏�����啝�ɕς����̂ŁA�{�ƂƔ����Ƀ^�C�~���O���Ⴄ�����c
int omasLevelTable[30] = 
{
	  1,   3,   5,   6,   8,  10,  12,  15,  20,  30,
	 30,   1,   5,  12,  30,  60,  60,  60,  60,  60,
	120, 120, 180, 180, 240, 300, 300, 240, 180,1200
};
int omasWait1[12] =
{
	26, 27, 27, 27, 27, 18, 18, 16, 15, 14, 14, 13
};
int omasWait2[12] =
{
	40, 25, 22, 18, 15, 12, 10,  8,  6,  5,  4,  3
};
int omasWait3[12] =
{
	28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 22, 15
};
int omasWaitt[12] =
{
	15,  9,  9,  9,  9,  8,  8,  8,  8,  7,  7,  7
};

// �ϐ�
int omasModeNo = -1;		// ���[�h�ԍ�
int omasScore[2];			// �X�R�A
int omasRate[2];			// �R���{�{�[�i�X�p�ϐ�
int omasLines[2];			// ���C��
int omasLevel[2];			// ���x��
int omasLc[2];				// ���x���A�b�v�܂ł̃J�E���^
int omasLvUpAnim[2];		// ���x���A�b�v����A������_�ł����鎞��

int omasIsBig = 0;			// BIG���ǂ���
int omasBigMove = 1;		// BIG���̉��ړ��P��
int omasStartLevel = 0;		// �J�n���x��
int omasBgm = 0;			// �g�p����BGM
int omasGhost = 0;			// �S�[�X�g�̐ݒ�

// �����L���O�p�ϐ�
int omasRankingScore[10];	// �X�R�A
int omasRankingLines[10];	// ���C��
int omasRankingLevel[10];	// ���x��
int omasRankingTime[10];	// �^�C��
int omasRankingYear[10];	// �����N�C�������i�N�j
int omasRankingMonth[10];	// �����N�C�������i���j
int omasRankingDay[10];		// �����N�C�������i���j
int omasRankingHour[10];	// �����N�C�������i���j
int omasRankingMinute[10];	// �����N�C�������i���j
int omasRankingSecond[10];	// �����N�C�������i�b�j

// �C�x���g����
void omasPluginEvent(int player, int event, int *param) {
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != omasModeNo)) return;
	
	if(event == 0) {
		omasModeNo = addModePlugin("ORIGINAL-MASTER");	// ���[�h��o�^����
	} else if(event == 8) {
		omasSoftDropScore(player);	// �\�t�g�h���b�v�œ������_�������Z
	} else if(event == 10) {
		omasARE(player);	// ARE��
	} else if(event == 13) {
		omasCalcScore(player, param[0]);	// �X�R�A�v�Z
	} else if(event == 15) {
		omasViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		omasSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		omasPlayerInitial(player);	// ������
	} else if(event == 21) {
		omasResult(player);	// ���ʕ\��
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		omasSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		omasLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		omasLoadBGM();	// BGM�ǂݍ���
	} else if(event == 48) {
		omasSoftDropOld(player);	// �\�t�g�h���b�v
	} else if(event == 49) {
		omasHardDrop(player, param[1]);	// �n�[�h�h���b�v
	} else if(event == 55) {
		omasReplayDetail();	// ���v���C�ڍ�
	}
}

// ������
void omasPlayerInitial(int player) {
	// �ϐ���������
	omasScore[player] = 0;
	omasRate[player] = 0;
	omasLines[player] = 0;
	omasLevel[player] = omasStartLevel;
	omasLc[player] = 0;
	omasLvUpAnim[player] = 0;
	
	// �R���{�L��
	enable_combo[player] = 1;
	
	// �g�̐F��ς���
	framecolor[player] = 9;
	
	// �������x
	omasChangeSpeed(player);
	backno = omasLevel[player] / 3;
	if(backno > 19) backno = 19;
	
	if( ((omasLevel[player] >= 12) && (!omasGhost)) || (omasGhost == 2) ) ghost[player] = 0;
	
	// �ݒ�𔽉f������
	IsBig[player] = omasIsBig;
	BigMove[player] = omasBigMove;
	bgmlv = omasBgm;
}

// ARE��
void omasARE(int player) {
	// ���x���J�E���^�{�P
	if(statc[player * 10] == wait1[player] - lockflash[player]) omasLc[player]++;
	
	// ���x���A�b�v����
	if(omasLc[player] > 100) {
		omasLc[player] = omasLc[player] - 100;
		
		omasLevel[player]++;
		omasLvUpAnim[player] = 180;
		
		omasChangeSpeed(player);
		
		if(omasLevel[player] % 3 == 0) {
			PlaySE(se_levelup);
			
			if(omasLevel[player] / 3 < 20) {
				bgfadesw = 1;
				bgfadebg = omasLevel[player] / 3;
			}
		}
		
		if((omasLevel[player] >= 12) && (!omasGhost)) ghost[player] = 0;
	}
}

// �X�s�[�h��ς���
void omasChangeSpeed(int player) {
	int temp;
	
	temp = omasLevel[player];
	if(temp > 29) temp = 29;
	sp[player] = omasLevelTable[temp];
	
	if(omasLevel[player] < 30) {
		wait1[player] = omasWait1[0] + 3;
		wait2[player] = omasWait2[0];
		wait3[player] = omasWait3[0] + 2;
		waitt[player] = omasWaitt[0];
	} else {
		temp = (omasLevel[player] - 30) / 3;
		if(temp > 10) temp = 10;
		wait1[player] = omasWait1[1 + temp] + 3;
		wait2[player] = omasWait2[1 + temp];
		wait3[player] = omasWait3[1 + temp] + 2;
		waitt[player] = omasWaitt[1 + temp];
	}
}

// �X�R�A�v�Z
void omasCalcScore(int player, int lines) {
	int bo, bai, all;
	
	// ��{�_
	if(combo[player] == 1) omasRate[player] = 100;
	
	if(lines == 1) {
		bo = 1 * omasRate[player];
		omasRate[player] = omasRate[player] + 5;
	}
	if(lines == 2) {
		bo = 4 * omasRate[player];
		omasRate[player] = omasRate[player] + 10;
	}
	if(lines == 3) {
		bo = 9 * omasRate[player];
		omasRate[player] = omasRate[player] + 30;
	}
	if(lines == 4) {
		bo = 20 * omasRate[player];
		omasRate[player] = omasRate[player] + 50;
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
	omasScore[player] = omasScore[player] + bo * bai;
	omasLines[player] = omasLines[player] + lines;
	omasLc[player] = omasLc[player] + lines * 20;
}

// �\�t�g�h���b�v�i���j
void omasSoftDropOld(int player) {
	if((!down_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) && (engineVer <= 12)) {
		if(sp[player] < (softspeed[player] + 1) * 30) {
			omasScore[player]++;
		}
	}
}

// �n�[�h�h���b�v
void omasHardDrop(int player, int bottom) {
	if((!up_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0)) {
		if(sp[player] <= 240) {
			omasScore[player] = omasScore[player] + (bottom - by[player]) * 23 / 20;	// �ʏ��15%���̓_���l��
		}
	}
}

// �\�t�g�h���b�v�œ������_�������Z
void omasSoftDropScore(int player) {
	if(softd_score[player] > 0) {
		omasScore[player] = omasScore[player] + softd_score[player];
	}
}

// �X�R�A�\��
void omasViewScore(int player) {
	int color, color2;
	color = (count % 4 / 2) * (sp[player] >= 1200) * 2;
	
	// �X�R�A
	printFont(foffset[player] + 96, fyoffset[player] + 40, "SCORE", 2);
	if(omasScore[player] > 9999999) omasScore[player] = 9999999;
	sprintf(string[0], "%d", omasScore[player]);
	printFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// ���C��
	printFont(foffset[player] + 96, fyoffset[player] + 64, "LINES", 2);
	if(omasLines[player] > 9999) omasLines[player] = 9999;
	sprintf(string[0], "%d", omasLines[player]);
	printFont(foffset[player] + 96, fyoffset[player] + 72, string[0], color);
	
	// ���x��
	printFont(foffset[player] + 96, fyoffset[player] + 88, "LEVEL", 2);
	if(omasLevel[player] > 999) omasLevel[player] = 999;
	sprintf(string[0], "%d", omasLevel[player]);
	if(!omasLvUpAnim[player]) {
		color2 = color;
	} else {
		color2 = 7 * (count % 4 / 2);
		omasLvUpAnim[player]--;
	}
	printFont(foffset[player] + 96, fyoffset[player] + 96, string[0], color2);
	
	// �^�C��
	if(gameTimer[player] > 359999) gameTimer[player] = 359999;
	getTime(gameTimer[player]);
	printFont(foffset[player] + 16, fyoffset[player] + 224, string[0], color);
}

// ���ʕ\��
void omasResult(int player) {
	// �����L���O�o�^
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = omasRegistRanking(player);
		if(statc[player * 10 + 1] != -1) omasSaveRanking(player);
	}
	
	printFont(foffset[player] + 8, fyoffset[player] + 48, "PLAY DATA", 4);
	
	// �X�R�A
	printFont(foffset[player] + 8, fyoffset[player] + 64, "SCORE", 2);
	sprintf(string[0], "%10d", omasScore[player]);
	printFont(foffset[player] + 8, fyoffset[player] + 72, string[0], 0);
	
	// ���C��
	printFont(foffset[player] + 8, fyoffset[player] + 88, "LINES", 2);
	sprintf(string[0], "%10d", omasLines[player]);
	printFont(foffset[player] + 8, fyoffset[player] + 96, string[0], 0);
	
	// ���x��
	printFont(foffset[player] + 8, fyoffset[player] + 112, "LEVEL", 2);
	sprintf(string[0], "%10d", omasLevel[player]);
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
void omasLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(omasBgm);
	}
}

// �ݒ���
void omasSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(omasLoadConfig() == 0) omasSaveConfig();
	
	// �����L���O��ǂݍ���
	if(omasLoadRanking(player) == 0) omasInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ORIGINAL-MASTER OPTIONS", 4);
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
		if(!omasIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!omasBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "%d", omasStartLevel);
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "%d", omasBgm);
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(omasGhost == 0) sprintf(string[0], "LV12");
		else if(omasGhost == 1) sprintf(string[0], "ON");
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
			if(cursor == 0) omasIsBig = !omasIsBig;
			if(cursor == 1) omasBigMove = !omasBigMove;
			if(cursor == 2) {
				omasStartLevel = omasStartLevel + move;
				if(omasStartLevel < 0) omasStartLevel = 60;
				if(omasStartLevel > 60) omasStartLevel = 0;
			}
			if(cursor == 3) {
				omasBgm = omasBgm + move;
				if(omasBgm < 0) omasBgm = 29;
				if(omasBgm > 29) omasBgm = 0;
			}
			if(cursor == 4) {
				omasGhost = omasGhost + move;
				if(omasGhost < 0) omasGhost = 2;
				if(omasGhost > 2) omasGhost = 0;
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
			omasSaveConfig();
			return;
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			omasViewRanking(player);
		}
	}
}

// �ݒ��ۑ�
void omasSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x53414D4F;
	saveBuf[1] = 0x43524554;
	saveBuf[2] = 0x49464E4F;
	saveBuf[3] = 0x31307647;
	
	// �ݒ���e
	saveBuf[4] = omasIsBig;
	saveBuf[5] = omasBigMove;
	saveBuf[6] = omasStartLevel;
	saveBuf[7] = omasBgm;
	saveBuf[8] = omasGhost;
	
	SaveFile("config/ORIGINAL_MASTER_CONFIG.SAV", &saveBuf, 100 * 4);
}

// �ݒ��ǂݍ���
int omasLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/ORIGINAL_MASTER_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x53414D4F) return 0;
	if(saveBuf[1] != 0x43524554) return 0;
	if(saveBuf[2] != 0x49464E4F) return 0;
	if(saveBuf[3] != 0x31307647) return 0;
	
	// �ݒ���e
	omasIsBig = saveBuf[4];
	omasBigMove = saveBuf[5];
	omasStartLevel = saveBuf[6];
	omasBgm = saveBuf[7];
	omasGhost = saveBuf[8];
	
	return 1;
}

// ���v���C�ۑ�
void omasSaveReplay(int player) {
	saveBuf[900] = omasScore[player];
	saveBuf[901] = omasLines[player];
	saveBuf[902] = omasLevel[player];
	saveBuf[903] = omasIsBig;
	saveBuf[904] = omasBigMove;
	saveBuf[905] = omasStartLevel;
	saveBuf[906] = omasBgm;
	saveBuf[907] = omasGhost;
}

// ���v���C�ǂݍ���
void omasLoadReplay(int player) {
	omasIsBig = saveBuf[903];
	omasBigMove = saveBuf[904];
	omasStartLevel = saveBuf[905];
	omasBgm = saveBuf[906];
	omasGhost = saveBuf[907];
	
	omasPlayerInitial(player);	// �ݒ�𔽉f������
}

// ���v���C�ڍ�
void omasReplayDetail() {
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
void omasSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 10) + 0] = omasRankingScore[i];
		saveBuf[1 + (i * 10) + 1] = omasRankingLines[i];
		saveBuf[1 + (i * 10) + 2] = omasRankingLevel[i];
		saveBuf[1 + (i * 10) + 3] = omasRankingTime[i];
		saveBuf[1 + (i * 10) + 4] = omasRankingYear[i];
		saveBuf[1 + (i * 10) + 5] = omasRankingMonth[i];
		saveBuf[1 + (i * 10) + 6] = omasRankingDay[i];
		saveBuf[1 + (i * 10) + 7] = omasRankingHour[i];
		saveBuf[1 + (i * 10) + 8] = omasRankingMinute[i];
		saveBuf[1 + (i * 10) + 9] = omasRankingSecond[i];
	}
	
	sprintf(string[0], "config/ORIGINAL_MASTER_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 111 * 4);
}

// �����L���O�ǂݍ���
int omasLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/ORIGINAL_MASTER_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 111 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		omasRankingScore[i]  = saveBuf[1 + (i * 10) + 0];
		omasRankingLines[i]  = saveBuf[1 + (i * 10) + 1];
		omasRankingLevel[i]  = saveBuf[1 + (i * 10) + 2];
		omasRankingTime[i]   = saveBuf[1 + (i * 10) + 3];
		omasRankingYear[i]   = saveBuf[1 + (i * 10) + 4];
		omasRankingMonth[i]  = saveBuf[1 + (i * 10) + 5];
		omasRankingDay[i]    = saveBuf[1 + (i * 10) + 6];
		omasRankingHour[i]   = saveBuf[1 + (i * 10) + 7];
		omasRankingMinute[i] = saveBuf[1 + (i * 10) + 8];
		omasRankingSecond[i] = saveBuf[1 + (i * 10) + 9];
	}
	
	return 1;
}

// �����L���O������
void omasInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		omasRankingScore[i]  = 0;
		omasRankingLines[i]  = 0;
		omasRankingLevel[i]  = 0;
		omasRankingTime[i]   = 0;
		omasRankingYear[i]   = 0;
		omasRankingMonth[i]  = 0;
		omasRankingDay[i]    = 0;
		omasRankingHour[i]   = 0;
		omasRankingMinute[i] = 0;
		omasRankingSecond[i] = 0;
	}
}

// �����L���O�o�^
int omasRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (omasIsBig)) return -1;
	
	for(i = 0; i < 10; i++) {
		// �����N�C��
		if(omasScore[player] > omasRankingScore[i]) {
			// �����L���O�����炷
			for(j = 9; j > i; j--) {
				omasRankingScore[j]  = omasRankingScore[j - 1];
				omasRankingLines[j]  = omasRankingLines[j - 1];
				omasRankingLevel[j]  = omasRankingLevel[j - 1];
				omasRankingTime[j]   = omasRankingTime[j - 1];
				omasRankingYear[j]   = omasRankingYear[j - 1];
				omasRankingMonth[j]  = omasRankingMonth[j - 1];
				omasRankingDay[j]    = omasRankingDay[j - 1];
				omasRankingHour[j]   = omasRankingHour[j - 1];
				omasRankingMinute[j] = omasRankingMinute[j - 1];
				omasRankingSecond[j] = omasRankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			omasRankingScore[i]  = omasScore[player];
			omasRankingLines[i]  = omasLines[player];
			omasRankingLevel[i]  = omasLevel[player];
			omasRankingTime[i]   = gameTimer[player];
			
			GetDateAndTime(&timebuf);
			omasRankingYear[i]   = timebuf[0];
			omasRankingMonth[i]  = timebuf[1];
			omasRankingDay[i]    = timebuf[2];
			omasRankingHour[i]   = timebuf[4];
			omasRankingMinute[i] = timebuf[5];
			omasRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �����L���O�\��
void omasViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ORIGINAL-MASTER MODE RANKING", 6);
		printFontGrid(1, 3, "RANK SCORE   LINES LEVEL TIME", 4);
		
		for(i = 0; i < 10; i++) {
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", omasRankingScore[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", omasRankingLines[i]);
			printFontGrid(14, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", omasRankingLevel[i]);
			printFontGrid(20, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(omasRankingTime[i]);
			printFontGrid(26, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// ���t�Ǝ���
			sprintf(string[0],
			        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
			        omasRankingYear[cursor], omasRankingMonth[cursor], omasRankingDay[cursor],
			        omasRankingHour[cursor], omasRankingMinute[cursor], omasRankingSecond[cursor]);
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
				omasInitRanking();
				omasSaveRanking(player);
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
