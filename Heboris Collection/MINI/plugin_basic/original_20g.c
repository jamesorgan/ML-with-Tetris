//ORIGINAL-20G
//prefix:o20g

// ���x���A�b�v�e�[�u��
// �t���[���֘A�̏�����啝�ɕς����̂ŁA�{�ƂƔ����Ƀ^�C�~���O���Ⴄ�����c
int o20gWait1[12] =
{
	26, 27, 27, 27, 27, 18, 18, 16, 15, 14, 14, 13
};
int o20gWait2[12] =
{
	40, 25, 22, 18, 15, 12, 10,  8,  6,  5,  4,  3
};
int o20gWait3[12] =
{
	28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 22, 15
};
int o20gWaitt[12] =
{
	12,  9,  9,  9,  9,  8,  8,  8,  8,  7,  7,  7
};

// �ϐ�
int o20gModeNo = -1;		// ���[�h�ԍ�
int o20gScore[2];			// �X�R�A
int o20gRate[2];			// �R���{�{�[�i�X�p�ϐ�
int o20gLines[2];			// ���C��
int o20gLevel[2];			// ���x��
int o20gLc[2];				// ���x���A�b�v�܂ł̃J�E���^
int o20gLvUpAnim[2];		// ���x���A�b�v����A������_�ł����鎞��

int o20gIsBig = 0;			// BIG���ǂ���
int o20gBigMove = 1;		// BIG���̉��ړ��P��
int o20gStartLevel = 0;		// �J�n���x��
int o20gBgm = 1;			// �g�p����BGM

// �����L���O�p�ϐ�
int o20gRankingScore[10];	// �X�R�A
int o20gRankingLines[10];	// ���C��
int o20gRankingLevel[10];	// ���x��
int o20gRankingTime[10];	// �^�C��
int o20gRankingYear[10];	// �����N�C�������i�N�j
int o20gRankingMonth[10];	// �����N�C�������i���j
int o20gRankingDay[10];		// �����N�C�������i���j
int o20gRankingHour[10];	// �����N�C�������i���j
int o20gRankingMinute[10];	// �����N�C�������i���j
int o20gRankingSecond[10];	// �����N�C�������i�b�j

// �C�x���g����
void o20gPluginEvent(int player, int event, int *param) {
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != o20gModeNo)) return;
	
	if(event == 0) {
		o20gModeNo = addModePlugin("ORIGINAL-20G");	// ���[�h��o�^����
	} else if(event == 10) {
		o20gARE(player);	// ARE��
	} else if(event == 13) {
		o20gCalcScore(player, param[0]);	// �X�R�A�v�Z
	} else if(event == 15) {
		o20gViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		o20gSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		o20gPlayerInitial(player);	// ������
	} else if(event == 21) {
		o20gResult(player);	// ���ʕ\��
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		o20gSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		o20gLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		o20gLoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		o20gReplayDetail();	// ���v���C�ڍ�
	}
}

// ������
void o20gPlayerInitial(int player) {
	// �ϐ���������
	o20gScore[player] = 0;
	o20gRate[player] = 0;
	o20gLines[player] = 0;
	o20gLevel[player] = o20gStartLevel;
	o20gLc[player] = 0;
	o20gLvUpAnim[player] = 0;
	
	// �R���{�L��
	enable_combo[player] = 1;
	
	// �g�̐F��ς���
	framecolor[player] = 9;
	
	// �������x
	o20gChangeSpeed(player);
	backno = o20gLevel[player] / 3;
	if(backno > 19) backno = 19;
	
	// �ݒ�𔽉f������
	IsBig[player] = o20gIsBig;
	BigMove[player] = o20gBigMove;
	bgmlv = o20gBgm;
}

// ARE��
void o20gARE(int player) {
	// ���x���J�E���^�{�P
	if(statc[player * 10] == wait1[player] - lockflash[player]) o20gLc[player]++;
	
	// ���x���A�b�v����
	if(o20gLc[player] > 100) {
		o20gLc[player] = o20gLc[player] - 100;
		
		o20gLevel[player]++;
		o20gLvUpAnim[player] = 180;
		
		o20gChangeSpeed(player);
		
		if(o20gLevel[player] % 3 == 0) {
			PlaySE(se_levelup);
			
			if(o20gLevel[player] / 3 < 20) {
				bgfadesw = 1;
				bgfadebg = o20gLevel[player] / 3;
			}
		}
	}
}

// �X�s�[�h��ς���
void o20gChangeSpeed(int player) {
	int temp;
	
	sp[player] = 1200;
	
	if(o20gLevel[player] < 30) {
		wait1[player] = o20gWait1[0] + 3;
		wait2[player] = o20gWait2[0];
		wait3[player] = o20gWait3[0] + 2;
		waitt[player] = o20gWaitt[0];
	} else {
		temp = (o20gLevel[player] - 30) / 3;
		if(temp > 10) temp = 10;
		wait1[player] = o20gWait1[1 + temp] + 3;
		wait2[player] = o20gWait2[1 + temp];
		wait3[player] = o20gWait3[1 + temp] + 2;
		waitt[player] = o20gWaitt[1 + temp];
	}
}

// �X�R�A�v�Z
void o20gCalcScore(int player, int lines) {
	int bo, bai, all;
	
	// ��{�_
	if(combo[player] == 1) o20gRate[player] = 100;
	
	if(lines == 1) {
		bo = 1 * o20gRate[player];
		o20gRate[player] = o20gRate[player] + 5;
	}
	if(lines == 2) {
		bo = 4 * o20gRate[player];
		o20gRate[player] = o20gRate[player] + 10;
	}
	if(lines == 3) {
		bo = 9 * o20gRate[player];
		o20gRate[player] = o20gRate[player] + 30;
	}
	if(lines == 4) {
		bo = 20 * o20gRate[player];
		o20gRate[player] = o20gRate[player] + 50;
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
	o20gScore[player] = o20gScore[player] + bo * bai;
	o20gLines[player] = o20gLines[player] + lines;
	o20gLc[player] = o20gLc[player] + lines * 20;
}

// �X�R�A�\��
void o20gViewScore(int player) {
	int color, color2;
	color = (count % 4 / 2) * (sp[player] >= 1200) * 2;
	
	// �X�R�A
	printFont(foffset[player] + 96, fyoffset[player] + 40, "SCORE", 2);
	if(o20gScore[player] > 9999999) o20gScore[player] = 9999999;
	sprintf(string[0], "%d", o20gScore[player]);
	printFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// ���C��
	printFont(foffset[player] + 96, fyoffset[player] + 64, "LINES", 2);
	if(o20gLines[player] > 9999) o20gLines[player] = 9999;
	sprintf(string[0], "%d", o20gLines[player]);
	printFont(foffset[player] + 96, fyoffset[player] + 72, string[0], color);
	
	// ���x��
	printFont(foffset[player] + 96, fyoffset[player] + 88, "LEVEL", 2);
	if(o20gLevel[player] > 999) o20gLevel[player] = 999;
	sprintf(string[0], "%d", o20gLevel[player]);
	if(!o20gLvUpAnim[player]) {
		color2 = color;
	} else {
		color2 = 7 * (count % 4 / 2);
		o20gLvUpAnim[player]--;
	}
	printFont(foffset[player] + 96, fyoffset[player] + 96, string[0], color2);
	
	// �^�C��
	if(gameTimer[player] > 359999) gameTimer[player] = 359999;
	getTime(gameTimer[player]);
	printFont(foffset[player] + 16, fyoffset[player] + 224, string[0], color);
}

// ���ʕ\��
void o20gResult(int player) {
	// �����L���O�o�^
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = o20gRegistRanking(player);
		if(statc[player * 10 + 1] != -1) o20gSaveRanking(player);
	}
	
	printFont(foffset[player] + 8, fyoffset[player] + 48, "PLAY DATA", 4);
	
	// �X�R�A
	printFont(foffset[player] + 8, fyoffset[player] + 64, "SCORE", 2);
	sprintf(string[0], "%10d", o20gScore[player]);
	printFont(foffset[player] + 8, fyoffset[player] + 72, string[0], 0);
	
	// ���C��
	printFont(foffset[player] + 8, fyoffset[player] + 88, "LINES", 2);
	sprintf(string[0], "%10d", o20gLines[player]);
	printFont(foffset[player] + 8, fyoffset[player] + 96, string[0], 0);
	
	// ���x��
	printFont(foffset[player] + 8, fyoffset[player] + 112, "LEVEL", 2);
	sprintf(string[0], "%10d", o20gLevel[player]);
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
void o20gLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(o20gBgm);
	}
}

// �ݒ���
void o20gSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(o20gLoadConfig() == 0) o20gSaveConfig();
	
	// �����L���O��ǂݍ���
	if(o20gLoadRanking(player) == 0) o20gInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ORIGINAL-20G OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "BIG",         7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",    7 * (cursor == 1));
		printFontGrid(2, 5, "START LEVEL", 7 * (cursor == 2));
		printFontGrid(2, 6, "BGM",         7 * (cursor == 3));
		
		// �ݒ�l�\��
		if(!o20gIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!o20gBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "%d", o20gStartLevel);
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "%d", o20gBgm);
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
			if(cursor == 0) o20gIsBig = !o20gIsBig;
			if(cursor == 1) o20gBigMove = !o20gBigMove;
			if(cursor == 2) {
				o20gStartLevel = o20gStartLevel + move;
				if(o20gStartLevel < 0) o20gStartLevel = 60;
				if(o20gStartLevel > 60) o20gStartLevel = 0;
			}
			if(cursor == 3) {
				o20gBgm = o20gBgm + move;
				if(o20gBgm < 0) o20gBgm = 29;
				if(o20gBgm > 29) o20gBgm = 0;
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
			o20gSaveConfig();
			return;
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			o20gViewRanking(player);
		}
	}
}

// �ݒ��ۑ�
void o20gSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x4749524F;
	saveBuf[1] = 0x4C414E49;
	saveBuf[2] = 0x43473032;
	saveBuf[3] = 0x31464E4F;
	
	// �ݒ���e
	saveBuf[4] = o20gIsBig;
	saveBuf[5] = o20gBigMove;
	saveBuf[6] = o20gStartLevel;
	saveBuf[7] = o20gBgm;
	
	SaveFile("config/ORIGINAL_20G_CONFIG.SAV", &saveBuf, 100 * 4);
}

// �ݒ��ǂݍ���
int o20gLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/ORIGINAL_20G_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x4749524F) return 0;
	if(saveBuf[1] != 0x4C414E49) return 0;
	if(saveBuf[2] != 0x43473032) return 0;
	if(saveBuf[3] != 0x31464E4F) return 0;
	
	// �ݒ���e
	o20gIsBig = saveBuf[4];
	o20gBigMove = saveBuf[5];
	o20gStartLevel = saveBuf[6];
	o20gBgm = saveBuf[7];
	
	return 1;
}

// ���v���C�ۑ�
void o20gSaveReplay(int player) {
	saveBuf[900] = o20gScore[player];
	saveBuf[901] = o20gLines[player];
	saveBuf[902] = o20gLevel[player];
	saveBuf[903] = o20gIsBig;
	saveBuf[904] = o20gBigMove;
	saveBuf[905] = o20gStartLevel;
	saveBuf[906] = o20gBgm;
}

// ���v���C�ǂݍ���
void o20gLoadReplay(int player) {
	o20gIsBig = saveBuf[903];
	o20gBigMove = saveBuf[904];
	o20gStartLevel = saveBuf[905];
	o20gBgm = saveBuf[906];
	
	o20gPlayerInitial(player);	// �ݒ�𔽉f������
}

// ���v���C�ڍ�
void o20gReplayDetail() {
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
}

// �����L���O�ۑ�
void o20gSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 10) + 0] = o20gRankingScore[i];
		saveBuf[1 + (i * 10) + 1] = o20gRankingLines[i];
		saveBuf[1 + (i * 10) + 2] = o20gRankingLevel[i];
		saveBuf[1 + (i * 10) + 3] = o20gRankingTime[i];
		saveBuf[1 + (i * 10) + 4] = o20gRankingYear[i];
		saveBuf[1 + (i * 10) + 5] = o20gRankingMonth[i];
		saveBuf[1 + (i * 10) + 6] = o20gRankingDay[i];
		saveBuf[1 + (i * 10) + 7] = o20gRankingHour[i];
		saveBuf[1 + (i * 10) + 8] = o20gRankingMinute[i];
		saveBuf[1 + (i * 10) + 9] = o20gRankingSecond[i];
	}
	
	sprintf(string[0], "config/ORIGINAL_20G_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 111 * 4);
}

// �����L���O�ǂݍ���
int o20gLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/ORIGINAL_20G_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 111 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		o20gRankingScore[i]  = saveBuf[1 + (i * 10) + 0];
		o20gRankingLines[i]  = saveBuf[1 + (i * 10) + 1];
		o20gRankingLevel[i]  = saveBuf[1 + (i * 10) + 2];
		o20gRankingTime[i]   = saveBuf[1 + (i * 10) + 3];
		o20gRankingYear[i]   = saveBuf[1 + (i * 10) + 4];
		o20gRankingMonth[i]  = saveBuf[1 + (i * 10) + 5];
		o20gRankingDay[i]    = saveBuf[1 + (i * 10) + 6];
		o20gRankingHour[i]   = saveBuf[1 + (i * 10) + 7];
		o20gRankingMinute[i] = saveBuf[1 + (i * 10) + 8];
		o20gRankingSecond[i] = saveBuf[1 + (i * 10) + 9];
	}
	
	return 1;
}

// �����L���O������
void o20gInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		o20gRankingScore[i]  = 0;
		o20gRankingLines[i]  = 0;
		o20gRankingLevel[i]  = 0;
		o20gRankingTime[i]   = 0;
		o20gRankingYear[i]   = 0;
		o20gRankingMonth[i]  = 0;
		o20gRankingDay[i]    = 0;
		o20gRankingHour[i]   = 0;
		o20gRankingMinute[i] = 0;
		o20gRankingSecond[i] = 0;
	}
}

// �����L���O�o�^
int o20gRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (o20gIsBig)) return -1;
	
	for(i = 0; i < 10; i++) {
		// �����N�C��
		if(o20gScore[player] > o20gRankingScore[i]) {
			// �����L���O�����炷
			for(j = 9; j > i; j--) {
				o20gRankingScore[j]  = o20gRankingScore[j - 1];
				o20gRankingLines[j]  = o20gRankingLines[j - 1];
				o20gRankingLevel[j]  = o20gRankingLevel[j - 1];
				o20gRankingTime[j]   = o20gRankingTime[j - 1];
				o20gRankingYear[j]   = o20gRankingYear[j - 1];
				o20gRankingMonth[j]  = o20gRankingMonth[j - 1];
				o20gRankingDay[j]    = o20gRankingDay[j - 1];
				o20gRankingHour[j]   = o20gRankingHour[j - 1];
				o20gRankingMinute[j] = o20gRankingMinute[j - 1];
				o20gRankingSecond[j] = o20gRankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			o20gRankingScore[i]  = o20gScore[player];
			o20gRankingLines[i]  = o20gLines[player];
			o20gRankingLevel[i]  = o20gLevel[player];
			o20gRankingTime[i]   = gameTimer[player];
			
			GetDateAndTime(&timebuf);
			o20gRankingYear[i]   = timebuf[0];
			o20gRankingMonth[i]  = timebuf[1];
			o20gRankingDay[i]    = timebuf[2];
			o20gRankingHour[i]   = timebuf[4];
			o20gRankingMinute[i] = timebuf[5];
			o20gRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �����L���O�\��
void o20gViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ORIGINAL-20G MODE RANKING", 6);
		printFontGrid(1, 3, "RANK SCORE   LINES LEVEL TIME", 4);
		
		for(i = 0; i < 10; i++) {
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", o20gRankingScore[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", o20gRankingLines[i]);
			printFontGrid(14, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", o20gRankingLevel[i]);
			printFontGrid(20, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(o20gRankingTime[i]);
			printFontGrid(26, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// ���t�Ǝ���
			sprintf(string[0],
			        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
			        o20gRankingYear[cursor], o20gRankingMonth[cursor], o20gRankingDay[cursor],
			        o20gRankingHour[cursor], o20gRankingMinute[cursor], o20gRankingSecond[cursor]);
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
				o20gInitRanking();
				o20gSaveRanking(player);
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
