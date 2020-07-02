//ACE-NORMAL+
//prefix:acep

// ���x���A�b�v�e�[�u��
int acepLevelTable[15] =
{
	1,10,20,30,60,100,130,160,190,220,240,300,1200,1200,1200
};

// BGM�֘A
int acepBgm = 0;								// ���݂�BGM�ԍ�
int acepBgmListTable[3] = {0, 1, 2};			// �g�p����BGM
int acepBgmFadeTable[3] = {45, 95, 145};		// �t�F�[�h�A�E�g���郉�C��
int acepBgmChangeTable[3] = {50, 100, 10000};	// BGM��؂�ւ��郉�C��

// �ϐ�
int acepModeNo = -1;		// ���[�h�ԍ�
int acepLines[2];			// ���C��
int acepLevel[2];			// ���x��
int acepTimer[2];			// ��������

// �ݒ�
int acepIsBig = 0;			// BIG���ǂ���
int acepBigMove = 1;		// BIG���̉��ړ��P��
int acepGhost = 1;			// �S�[�X�g�̗L��
int acepStartLevel = 0;		// �X�^�[�g���̃��x��

// �����L���O�p�ϐ�
int acepRankingTime[20];	// �^�C��
int acepRankingLines[20];	// ���C��
int acepRankingYear[20];	// �����N�C�������i�N�j
int acepRankingMonth[20];	// �����N�C�������i���j
int acepRankingDay[20];		// �����N�C�������i���j
int acepRankingHour[20];	// �����N�C�������i���j
int acepRankingMinute[20];	// �����N�C�������i���j
int acepRankingSecond[20];	// �����N�C�������i�b�j

// �C�x���g����
void acepPluginEvent(int player, int event, int *param) {
	int i;
	
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != acepModeNo)) return;
	
	if(event == 0) {
		// ���[�h��o�^����
		acepModeNo = addModePlugin("ACE-NORMAL+");
	} else if(event == 7) {
		timeOn[player] = 1;	// �u���b�N�o���Ɠ����Ƀ^�C�}�[�ĊJ
	} else if(event == 12) {
		acepLineErase(player, param[0]);	// ���C������
	} else if(event == 15) {
		acepViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		acepSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		acepPlayerInitial(player);	// ������
	} else if(event == 21) {
		acepResult(player);	// ���ʕ\��
	} else if(event == 24) {
		ending[player] = 3;	// �G���f�B���O�˓�
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		acepExcellent(player, param);	// EXCELLENT���
	} else if(event == 28) {
		acepIncrementTime(player);	// ���Ԃ�i�߂�
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		acepSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		acepLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		acepLoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		acepReplayDetail(param[0]);	// ���v���C�ڍ�
	}
}

// ������
void acepPlayerInitial(int player) {
	// �g�̐F���D�F�ɂ���
	framecolor[player] = 5;
	frame_decoration[player] = 1;
	
	// �ϐ���������
	acepLines[player] = acepStartLevel * 10;
	acepLevel[player] = acepStartLevel;
	backno = acepStartLevel;
	
	// ����BGM��ݒ�
	acepBgm = 0;
	while(acepLines[player] >= acepBgmChangeTable[acepBgm]) acepBgm++;
	bgmlv = acepBgmListTable[acepBgm];
	
	// �����X�s�[�h��ݒ�
	sp[player] = acepLevelTable[acepLevel[player]];
	acepTimer[player] = 5400;
	
	// �ݒ�𔽉f������
	IsBig[player] = acepIsBig;
	BigMove[player] = acepBigMove;
	if(acepGhost == 0) ghost[player] = 0;
}

// ���C������
void acepLineErase(int player, int lines) {
	// ���C�������Z
	acepLines[player] = acepLines[player] + lines;
	
	// �S����
	if(isBravo(player)) {
		PlaySE(se_levelup);
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
	}
	
	// BGM�t�F�[�h�A�E�g
	if((acepLines[player] >= acepBgmFadeTable[acepBgm]) && (acepLines[player] < acepBgmChangeTable[acepBgm]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// �G���f�B���O
	if(acepLines[player] >= 150) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		acepLines[player] = 150;
		ending[player] = 1;
	}
	// ���x���A�b�v
	else if(acepLines[player] >= (acepLevel[player] + 1) * 10) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		// �X�s�[�h�A�b�v
		acepLevel[player]++;
		sp[player] = acepLevelTable[acepLevel[player]];
		acepTimer[player] = 5400;
		
		// �w�i�؂�ւ�
		bgfadesw = 1;
		bgfadebg = acepLevel[player];
		
		// ���y�؂�ւ�
		if(acepLines[player] >= acepBgmChangeTable[acepBgm]) {
			acepBgm++;
			bgmlv = acepBgmListTable[acepBgm];
			PlayBGM();
		}
	}
}

// �X�R�A�\��
void acepViewScore(int player) {
	int color, color2;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// ���x��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "LEVEL");
	sprintf(string[0], "%d", acepLevel[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// �g�[�^���^�C��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "TOTAL TIME");
	getTime(gameTimer[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// �x�X�g�^�C��
	if((!playback) && (!IsBig[player]) && (!acepStartLevel)) {
		printTinyFont(foffset[player] + 96, fyoffset[player] + 76, "BEST TIME");
		if(acepRankingLines[0] >= 150) getTime(acepRankingTime[0]);
		else getTime(0);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 84, string[0], color);
	}
	
	// �m���}�i���q�j
	ExBltRect(sg_smallfont, foffset[player] + 107, fyoffset[player] + 161, 0, 14, 22, 7);
	sprintf(string[0], "%4d", acepLines[player]);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 169, string[0], color);
	
	// �m���}�i�����j
	ExBltRect(sg_spr, foffset[player] + 105, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 106, fyoffset[player] + 181, 22, 143, 22, 1);
	
	// �m���}�i����j
	if(ending[player]) sprintf(string[0], "%4d", acepLines[player]);
	else sprintf(string[0], "%4d", (acepLevel[player] + 1) * 10);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 185, string[0], color);
	
	// �c�莞��
	if((acepTimer[player] <= 60 * 10) && (timeOn[player])) color2 = 2;
	else color2 = color;
	getTime(acepTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
}

// EXCELLENT���
void acepExcellent(int player, int *param) {
	param[0] = 3;
	onRecord[player] = 0;
	
	// �ԉ�
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// ���Ԃ�i�߂�
void acepIncrementTime(int player) {
	int i;
	
	if(timeOn[player]) {
		// �������Ԍ���
		acepTimer[player]--;
		
		// ���Ԑ؂�
		if(acepTimer[player] <= 0) {
			PlaySE(se_timeover);
			acepTimer[player] = 0;
			
			timeOn[player] = 0;
			onRecord[player] = 0;
			
			stat[player] = 7;
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		}
		// �c��10�b
		else if(acepTimer[player] == 10 * 60) {
			PlaySE(se_hurryup);
		}
	}
}

// BGM�ǂݍ���
void acepLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 3; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/3)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(acepBgmListTable[i]);
		}
	}
}

// ���ʕ\��
void acepResult(int player) {
	// �����L���O�o�^
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = acepRegistRanking(player);
		if(statc[player * 10 + 1] != -1) acepSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", acepLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", acepLevel[player] + 1);
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
}

// �ݒ���
void acepSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(acepLoadConfig() == 0) acepSaveConfig();
	
	// �����L���O��ǂݍ���
	if(acepLoadRanking(player) == 0) acepInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE-NORMAL+ OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "BIG",         7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",    7 * (cursor == 1));
		printFontGrid(2, 5, "GHOST BLOCK", 7 * (cursor == 2));
		printFontGrid(2, 6, "START LEVEL", 7 * (cursor == 3));
		
		// �ݒ�l�\��
		if(!acepIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!acepBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!acepGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "LV%d", acepStartLevel + 1);
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
			if(cursor == 0) acepIsBig = !acepIsBig;
			if(cursor == 1) acepBigMove = !acepBigMove;
			if(cursor == 2) acepGhost = !acepGhost;
			if(cursor == 3) {
				acepStartLevel = acepStartLevel + move;
				if(acepStartLevel < 0) acepStartLevel = 14;
				if(acepStartLevel > 14) acepStartLevel = 0;
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
			acepSaveConfig();
			return;
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			acepViewRanking(player);
		}
	}
}

// ���v���C�ۑ�
void acepSaveReplay(int player) {
	saveBuf[900] = acepIsBig;
	saveBuf[901] = acepBigMove;
	saveBuf[902] = acepLines[player];
	saveBuf[903] = acepLevel[player];
	saveBuf[904] = acepGhost;
	saveBuf[905] = acepStartLevel;
}

// ���v���C�ǂݍ���
void acepLoadReplay(int player) {
	acepIsBig = saveBuf[900];
	acepBigMove = saveBuf[901];
	acepGhost = saveBuf[904];
	acepStartLevel = saveBuf[905];
	
	acepPlayerInitial(player);	// �ݒ�𔽉f������
}

// ���v���C�ڍ�
void acepReplayDetail(int number) {
	printFontGrid(1, 4, "LINES", 0);
	sprintf(string[0], "%d", saveBuf[902]);
	printFontGrid(22, 4, string[0], 0);
	
	printFontGrid(1, 5, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[903] + 1);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 7, "BIG", 0);
	if(!saveBuf[900]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 8, "BIG MOVE", 0);
	if(!saveBuf[901]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "GHOST BLOCK", 0);
	if(!saveBuf[904]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "START LEVEL", 0);
	sprintf(string[0], "LV%d", saveBuf[905] + 1);
	printFontGrid(22, 10, string[0], 0);
}

// �ݒ��ۑ�
void acepSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �ݒ���e
	saveBuf[1] = acepIsBig;
	saveBuf[2] = acepBigMove;
	saveBuf[3] = acepGhost;
	saveBuf[4] = acepStartLevel;
	
	SaveFile("config/ACE_NORMAL_PLUS_CONFIG.SAV", &saveBuf, 50 * 4);
}

// �ݒ��ǂݍ���
int acepLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/ACE_NORMAL_PLUS_CONFIG.SAV", &saveBuf, 50 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �ݒ���e
	acepIsBig = saveBuf[1];
	acepBigMove = saveBuf[2];
	acepGhost = saveBuf[3];
	acepStartLevel = saveBuf[4];
	
	return 1;
}

// �����L���O�ۑ�
void acepSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �����L���O���e
	for(i = 0; i < 20; i++) {
		saveBuf[1 + (i * 10) + 0] = acepRankingTime[i];
		saveBuf[1 + (i * 10) + 1] = acepRankingLines[i];
		saveBuf[1 + (i * 10) + 2] = acepRankingYear[i];
		saveBuf[1 + (i * 10) + 3] = acepRankingMonth[i];
		saveBuf[1 + (i * 10) + 4] = acepRankingDay[i];
		saveBuf[1 + (i * 10) + 5] = acepRankingHour[i];
		saveBuf[1 + (i * 10) + 6] = acepRankingMinute[i];
		saveBuf[1 + (i * 10) + 7] = acepRankingSecond[i];
	}
	
	sprintf(string[0], "config/ACE_NORMAL_PLUS_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 211 * 4);
}

// �����L���O�ǂݍ���
int acepLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/ACE_NORMAL_PLUS_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 211 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �����L���O���e
	for(i = 0; i < 20; i++) {
		acepRankingTime[i]   = saveBuf[1 + (i * 10) + 0];
		acepRankingLines[i]  = saveBuf[1 + (i * 10) + 1];
		acepRankingYear[i]   = saveBuf[1 + (i * 10) + 2];
		acepRankingMonth[i]  = saveBuf[1 + (i * 10) + 3];
		acepRankingDay[i]    = saveBuf[1 + (i * 10) + 4];
		acepRankingHour[i]   = saveBuf[1 + (i * 10) + 5];
		acepRankingMinute[i] = saveBuf[1 + (i * 10) + 6];
		acepRankingSecond[i] = saveBuf[1 + (i * 10) + 7];
	}
}

// �����L���O������
void acepInitRanking() {
	int i;
	
	for(i = 0; i < 20; i++) {
		acepRankingTime[i] = 0;
		acepRankingLines[i] = 0;
		acepRankingYear[i] = 0;
		acepRankingMonth[i] = 0;
		acepRankingDay[i] = 0;
		acepRankingHour[i] = 0;
		acepRankingMinute[i] = 0;
		acepRankingSecond[i] = 0;
	}
}

// �����L���O�o�^
int acepRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (acepStartLevel)) return -1;
	
	for(i = 0; i < 20; i++) {
		// �����N�C��
		if((acepLines[player] > acepRankingLines[i]) || 
		   ((acepLines[player] == acepRankingLines[i]) && (gameTimer[player] < acepRankingTime[i])))
		{
			// �����L���O�����炷
			for(j = 19; j > i; j--) {
				acepRankingTime[j]   = acepRankingTime[j - 1];
				acepRankingLines[j]  = acepRankingLines[j - 1];
				acepRankingYear[j]   = acepRankingYear[j - 1];
				acepRankingMonth[j]  = acepRankingMonth[j - 1];
				acepRankingDay[j]    = acepRankingDay[j - 1];
				acepRankingHour[j]   = acepRankingHour[j - 1];
				acepRankingMinute[j] = acepRankingMinute[j - 1];
				acepRankingSecond[j] = acepRankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			acepRankingTime[i]   = gameTimer[player];
			acepRankingLines[i]  = acepLines[player];
			
			GetDateAndTime(&timebuf);
			acepRankingYear[i]   = timebuf[0];
			acepRankingMonth[i]  = timebuf[1];
			acepRankingDay[i]    = timebuf[2];
			acepRankingHour[i]   = timebuf[4];
			acepRankingMinute[i] = timebuf[5];
			acepRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �����L���O�\��
void acepViewRanking(int player) {
	int i, erasemode;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE-NORMAL+ MODE RANKING", 6);
		printFontGrid(1, 3, "RANK LINE TIME     DATE", 4);
		
		for(i = 0; i < 20; i++) {
			if(acepRankingLines[i] >= 150) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, 2, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 0);
			
			sprintf(string[0], "%d", acepRankingLines[i]);
			printFontGrid(6, 4 + i, string[0], 0);
			
			getTime(acepRankingTime[i]);
			printFontGrid(11, 4 + i, string[0], 0);
			
			sprintf(string[0], "%04d/%02d/%02d", acepRankingYear[i], acepRankingMonth[i], acepRankingDay[i]);
			printFontGrid(20, 4 + i, string[0], 0);
			
			sprintf(string[0], "%02d:%02d:%02d", acepRankingHour[i], acepRankingMinute[i], acepRankingSecond[i]);
			printFontGrid(31, 4 + i, string[0], 0);
		}
		
		if(!erasemode) {
			printFontGrid(1, 27, "A/B:EXIT F:ERASE ALL", 6);
			
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
			printFontGrid(1, 25, "ERASE ALL RECORDS?", 2);
			printFontGrid(1, 27, "A:YES / B:NO", 2);
			
			// ����
			if(getPushState(player, 4)) {
				PlayWave(se_kettei);
				acepInitRanking();
				acepSaveRanking(player);
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
