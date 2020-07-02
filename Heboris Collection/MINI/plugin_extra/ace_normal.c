//ACE-NORMAL
//prefix:ace

// ���x���A�b�v�e�[�u��
int aceLevelTable[15] =
{
	1, 3, 12, 18, 24, 30, 60, 120, 150, 180, 240, 300, 1200, 1200, 1200
};

// ���x�����Ƃ̐�������
int aceTimeLimit[15] =
{
	7200, 7200, 5400, 5400, 5400, 5400, 5400, 5400, 5400, 5400, 5400, 5400, 5400, 5400, 5400
};

// BGM�֘A
int aceBgm = 0;									// ���݂�BGM�ԍ�
int aceBgmListTable[3] = {15, 1, 2};			// �g�p����BGM
int aceBgmFadeTable[3] = {45, 95, 145};			// BGM���t�F�[�h�A�E�g���郉�C��
int aceBgmChangeTable[3] = {50, 100, 10000};	// BGM��؂�ւ��郉�C��

// �ϐ�
int aceModeNo = -1;			// ���[�h�ԍ�
int aceLines[2];			// ���C��
int aceLevel[2];			// ���x��
int aceTimer[2];			// ��������

// �ݒ�
int aceIsBig = 0;			// BIG���ǂ���
int aceBigMove = 1;			// BIG���̉��ړ��P��
int aceGhost = 1;			// �S�[�X�g�̗L��
int aceStartLevel = 0;		// �X�^�[�g���̃��x��

// �����L���O�p�ϐ�
int aceRankingTime[20];		// �^�C��
int aceRankingLines[20];	// ���C��
int aceRankingYear[20];		// �����N�C�������i�N�j
int aceRankingMonth[20];	// �����N�C�������i���j
int aceRankingDay[20];		// �����N�C�������i���j
int aceRankingHour[20];		// �����N�C�������i���j
int aceRankingMinute[20];	// �����N�C�������i���j
int aceRankingSecond[20];	// �����N�C�������i�b�j

// �C�x���g����
void acePluginEvent(int player, int event, int *param) {
	int i;
	
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != aceModeNo)) return;
	
	if(event == 0) {
		// ���[�h��o�^����
		aceModeNo = addModePlugin("ACE-NORMAL");
	} else if(event == 7) {
		timeOn[player] = 1;	// �u���b�N�o���Ɠ����Ƀ^�C�}�[�ĊJ
	} else if(event == 12) {
		aceLineErase(player, param[0]);	// ���C������
	} else if(event == 15) {
		aceViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		aceSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		acePlayerInitial(player);	// ������
	} else if(event == 21) {
		aceResult(player);	// ���ʕ\��
	} else if(event == 24) {
		ending[player] = 3;	// �G���f�B���O�˓�
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		aceExcellent(player, param);	// EXCELLENT���
	} else if(event == 28) {
		aceIncrementTime(player);	// ���Ԃ�i�߂�
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		aceSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		aceLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		aceLoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		aceReplayDetail(param[0]);	// ���v���C�ڍ�
	}
}

// ������
void acePlayerInitial(int player) {
	// �g�̐F���D�F�ɂ���
	framecolor[player] = 5;
	frame_decoration[player] = 1;
	
	// �ϐ���������
	aceLines[player] = aceStartLevel * 10;
	aceLevel[player] = aceStartLevel;
	backno = aceStartLevel;
	
	// ����BGM��ݒ�
	aceBgm = 0;
	while(aceLines[player] >= aceBgmChangeTable[aceBgm]) aceBgm++;
	bgmlv = aceBgmListTable[aceBgm];
	
	// �����X�s�[�h��ݒ�
	sp[player] = aceLevelTable[aceLevel[player]];
	aceTimer[player] = aceTimeLimit[aceLevel[player]];
	
	// �ݒ�𔽉f������
	IsBig[player] = aceIsBig;
	BigMove[player] = aceBigMove;
	if(aceGhost == 0) ghost[player] = 0;
}

// ���C������
void aceLineErase(int player, int lines) {
	// ���C�������Z
	aceLines[player] = aceLines[player] + lines;
	
	// �S����
	if(isBravo(player)) {
		PlaySE(se_levelup);
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
	}
	
	// BGM�t�F�[�h�A�E�g
	if((aceLines[player] >= aceBgmFadeTable[aceBgm]) && (aceLines[player] < aceBgmChangeTable[aceBgm]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// �G���f�B���O
	if(aceLines[player] >= 150) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		aceLines[player] = 150;
		ending[player] = 1;
	}
	// ���x���A�b�v
	else if(aceLines[player] >= (aceLevel[player] + 1) * 10) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		// �X�s�[�h�A�b�v
		aceLevel[player]++;
		sp[player] = aceLevelTable[aceLevel[player]];
		aceTimer[player] = aceTimeLimit[aceLevel[player]];
		
		// �w�i�؂�ւ�
		bgfadesw = 1;
		bgfadebg = aceLevel[player];
		
		// ���y�؂�ւ�
		if(aceLines[player] >= aceBgmChangeTable[aceBgm]) {
			aceBgm++;
			bgmlv = aceBgmListTable[aceBgm];
			PlayBGM();
		}
	}
}

// �X�R�A�\��
void aceViewScore(int player) {
	int color, color2;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// ���x��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "LEVEL");
	sprintf(string[0], "%d", aceLevel[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// �g�[�^���^�C��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "TOTAL TIME");
	getTime(gameTimer[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// �x�X�g�^�C��
	if((!playback) && (!IsBig[player]) && (!aceStartLevel)) {
		printTinyFont(foffset[player] + 96, fyoffset[player] + 76, "BEST TIME");
		if(aceRankingLines[0] >= 150) getTime(aceRankingTime[0]);
		else getTime(0);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 84, string[0], color);
	}
	
	// �m���}�i���q�j
	ExBltRect(sg_smallfont, foffset[player] + 107, fyoffset[player] + 161, 0, 14, 22, 7);
	sprintf(string[0], "%4d", aceLines[player]);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 169, string[0], color);
	
	// �m���}�i�����j
	ExBltRect(sg_spr, foffset[player] + 105, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 106, fyoffset[player] + 181, 22, 143, 22, 1);
	
	// �m���}�i����j
	if(ending[player]) sprintf(string[0], "%4d", aceLines[player]);
	else sprintf(string[0], "%4d", (aceLevel[player] + 1) * 10);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 185, string[0], color);
	
	// �c�莞��
	if((aceTimer[player] <= 60 * 10) && (timeOn[player])) color2 = 2;
	else color2 = color;
	getTime(aceTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
}

// EXCELLENT���
void aceExcellent(int player, int *param) {
	param[0] = 3;
	onRecord[player] = 0;
	
	// �ԉ�
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// ���Ԃ�i�߂�
void aceIncrementTime(int player) {
	int i;
	
	if(timeOn[player]) {
		// �������Ԍ���
		aceTimer[player]--;
		
		// ���Ԑ؂�
		if(aceTimer[player] <= 0) {
			PlaySE(se_timeover);
			aceTimer[player] = 0;
			
			timeOn[player] = 0;
			onRecord[player] = 0;
			
			stat[player] = 7;
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		}
		// �c��10�b
		else if(aceTimer[player] == 10 * 60) {
			PlaySE(se_hurryup);
		}
	}
}

// BGM�ǂݍ���
void aceLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 3; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/3)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(aceBgmListTable[i]);
		}
	}
}

// ���ʕ\��
void aceResult(int player) {
	// �����L���O�o�^
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = aceRegistRanking(player);
		if(statc[player * 10 + 1] != -1) aceSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", aceLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", aceLevel[player] + 1);
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
void aceSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(aceLoadConfig() == 0) aceSaveConfig();
	
	// �����L���O��ǂݍ���
	if(aceLoadRanking(player) == 0) aceInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE-NORMAL OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "BIG",         7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",    7 * (cursor == 1));
		printFontGrid(2, 5, "GHOST BLOCK", 7 * (cursor == 2));
		printFontGrid(2, 6, "START LEVEL", 7 * (cursor == 3));
		
		// �ݒ�l�\��
		if(!aceIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!aceBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!aceGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "LV%d", aceStartLevel + 1);
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
			if(cursor == 0) aceIsBig = !aceIsBig;
			if(cursor == 1) aceBigMove = !aceBigMove;
			if(cursor == 2) aceGhost = !aceGhost;
			if(cursor == 3) {
				aceStartLevel = aceStartLevel + move;
				if(aceStartLevel < 0) aceStartLevel = 14;
				if(aceStartLevel > 14) aceStartLevel = 0;
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
			aceSaveConfig();
			return;
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			aceViewRanking(player);
		}
	}
}

// ���v���C�ۑ�
void aceSaveReplay(int player) {
	saveBuf[900] = aceIsBig;
	saveBuf[901] = aceBigMove;
	saveBuf[902] = aceLines[player];
	saveBuf[903] = aceLevel[player];
	saveBuf[904] = aceGhost;
	saveBuf[905] = aceStartLevel;
}

// ���v���C�ǂݍ���
void aceLoadReplay(int player) {
	aceIsBig = saveBuf[900];
	aceBigMove = saveBuf[901];
	aceGhost = saveBuf[904];
	aceStartLevel = saveBuf[905];
	
	acePlayerInitial(player);	// �ݒ�𔽉f������
}

// ���v���C�ڍ�
void aceReplayDetail(int number) {
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
void aceSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x4E454341;
	saveBuf[3] = 0x31726576;
	
	// �ݒ���e
	saveBuf[4] = aceIsBig;
	saveBuf[5] = aceBigMove;
	saveBuf[6] = aceGhost;
	saveBuf[7] = aceStartLevel;
	
	SaveFile("config/ACE_NORMAL_CONFIG.SAV", &saveBuf, 100 * 4);
}

// �ݒ��ǂݍ���
int aceLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/ACE_NORMAL_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x4E454341) return 0;
	if(saveBuf[3] != 0x31726576) return 0;
	
	// �ݒ���e
	aceIsBig = saveBuf[4];
	aceBigMove = saveBuf[5];
	aceGhost = saveBuf[6];
	aceStartLevel = saveBuf[7];
	
	return 1;
}

// �����L���O�ۑ�
void aceSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �����L���O���e
	for(i = 0; i < 20; i++) {
		saveBuf[1 + (i * 10) + 0] = aceRankingTime[i];
		saveBuf[1 + (i * 10) + 1] = aceRankingLines[i];
		saveBuf[1 + (i * 10) + 2] = aceRankingYear[i];
		saveBuf[1 + (i * 10) + 3] = aceRankingMonth[i];
		saveBuf[1 + (i * 10) + 4] = aceRankingDay[i];
		saveBuf[1 + (i * 10) + 5] = aceRankingHour[i];
		saveBuf[1 + (i * 10) + 6] = aceRankingMinute[i];
		saveBuf[1 + (i * 10) + 7] = aceRankingSecond[i];
	}
	
	sprintf(string[0], "config/ACE_NORMAL_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 211 * 4);
}

// �����L���O�ǂݍ���
int aceLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/ACE_NORMAL_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 211 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �����L���O���e
	for(i = 0; i < 20; i++) {
		aceRankingTime[i]   = saveBuf[1 + (i * 10) + 0];
		aceRankingLines[i]  = saveBuf[1 + (i * 10) + 1];
		aceRankingYear[i]   = saveBuf[1 + (i * 10) + 2];
		aceRankingMonth[i]  = saveBuf[1 + (i * 10) + 3];
		aceRankingDay[i]    = saveBuf[1 + (i * 10) + 4];
		aceRankingHour[i]   = saveBuf[1 + (i * 10) + 5];
		aceRankingMinute[i] = saveBuf[1 + (i * 10) + 6];
		aceRankingSecond[i] = saveBuf[1 + (i * 10) + 7];
	}
}

// �����L���O������
void aceInitRanking() {
	int i;
	
	for(i = 0; i < 20; i++) {
		aceRankingTime[i] = 0;
		aceRankingLines[i] = 0;
		aceRankingYear[i] = 0;
		aceRankingMonth[i] = 0;
		aceRankingDay[i] = 0;
		aceRankingHour[i] = 0;
		aceRankingMinute[i] = 0;
		aceRankingSecond[i] = 0;
	}
}

// �����L���O�o�^
int aceRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (aceStartLevel)) return -1;
	
	for(i = 0; i < 20; i++) {
		// �����N�C��
		if((aceLines[player] > aceRankingLines[i]) || 
		   ((aceLines[player] == aceRankingLines[i]) && (gameTimer[player] < aceRankingTime[i])))
		{
			// �����L���O�����炷
			for(j = 19; j > i; j--) {
				aceRankingTime[j]   = aceRankingTime[j - 1];
				aceRankingLines[j]  = aceRankingLines[j - 1];
				aceRankingYear[j]   = aceRankingYear[j - 1];
				aceRankingMonth[j]  = aceRankingMonth[j - 1];
				aceRankingDay[j]    = aceRankingDay[j - 1];
				aceRankingHour[j]   = aceRankingHour[j - 1];
				aceRankingMinute[j] = aceRankingMinute[j - 1];
				aceRankingSecond[j] = aceRankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			aceRankingTime[i]   = gameTimer[player];
			aceRankingLines[i]  = aceLines[player];
			
			GetDateAndTime(&timebuf);
			aceRankingYear[i]   = timebuf[0];
			aceRankingMonth[i]  = timebuf[1];
			aceRankingDay[i]    = timebuf[2];
			aceRankingHour[i]   = timebuf[4];
			aceRankingMinute[i] = timebuf[5];
			aceRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �����L���O�\��
void aceViewRanking(int player) {
	int i, erasemode;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE-NORMAL MODE RANKING", 6);
		printFontGrid(1, 3, "RANK LINE TIME     DATE", 4);
		
		for(i = 0; i < 20; i++) {
			if(aceRankingLines[i] >= 150) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, 2, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 0);
			
			sprintf(string[0], "%d", aceRankingLines[i]);
			printFontGrid(6, 4 + i, string[0], 0);
			
			getTime(aceRankingTime[i]);
			printFontGrid(11, 4 + i, string[0], 0);
			
			sprintf(string[0], "%04d/%02d/%02d", aceRankingYear[i], aceRankingMonth[i], aceRankingDay[i]);
			printFontGrid(20, 4 + i, string[0], 0);
			
			sprintf(string[0], "%02d:%02d:%02d", aceRankingHour[i], aceRankingMinute[i], aceRankingSecond[i]);
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
				aceInitRanking();
				aceSaveRanking(player);
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
