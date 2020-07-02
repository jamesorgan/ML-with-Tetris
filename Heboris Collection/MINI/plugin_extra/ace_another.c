//ACE-ANOTHER
//prefix:acea

// LITE�Ńx�[�X

// ���x���A�b�v�e�[�u�� LV01,02,03,04,05,06,07,08,09,10,11,12,13,14,15
int aceaWait1Table[15] = {18,14,14,14,12,12,10, 8, 7, 6, 6, 6, 6, 6, 6};	// �Œ聨��
int aceaWait2Table[15] = {14, 8, 8, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4};	// �u���b�N����
int aceaWait3Table[15] = {28,24,22,20,18,14,14,13,13,13,13,13,13,13,13};	// �ڒn���Œ�
int aceaWaittTable[15] = {10,10, 9, 9, 9, 8, 8, 7, 7, 7, 7, 7, 7, 7, 7};	// ������

// BGM�֘A
int aceaBgm = 0;								// ���݂�BGM�ԍ�
int aceaBgmListTable[3]   = {5, 3, 4};			// �g�p����BGM
int aceaBgmFadeTable[3]   = {35, 95, 145};		// BGM���t�F�[�h�A�E�g���郉�C��
int aceaBgmChangeTable[3] = {40, 100, 10000};	// BGM��؂�ւ��郉�C��

// �ϐ�
int aceaModeNo = -1;		// ���[�h�ԍ�
int aceaLines[2];			// ���C��
int aceaLevel[2];			// ���x��
int aceaTimer[2];			// ��������

// �ݒ�
int aceaIsBig = 0;			// BIG���ǂ���
int aceaBigMove = 1;		// BIG���̉��ړ��P��
int aceaStartLevel = 0;		// �X�^�[�g���̃��x��

// �����L���O�p�ϐ�
int aceaRankingTime[20];	// �^�C��
int aceaRankingLines[20];	// ���C��
int aceaRankingYear[20];	// �����N�C�������i�N�j
int aceaRankingMonth[20];	// �����N�C�������i���j
int aceaRankingDay[20];		// �����N�C�������i���j
int aceaRankingHour[20];	// �����N�C�������i���j
int aceaRankingMinute[20];	// �����N�C�������i���j
int aceaRankingSecond[20];	// �����N�C�������i�b�j

// �C�x���g����
void aceaPluginEvent(int player, int event, int *param) {
	int i;
	
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != aceaModeNo)) return;
	
	if(event == 0) {
		// ���[�h��o�^����
		aceaModeNo = addModePlugin("ACE-ANOTHER");
	} else if(event == 7) {
		timeOn[player] = 1;	// �u���b�N�o���Ɠ����Ƀ^�C�}�[�ĊJ
	} else if(event == 12) {
		aceaLineErase(player, param[0]);	// ���C������
	} else if(event == 15) {
		aceaViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		aceaSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		aceaPlayerInitial(player);	// ������
	} else if(event == 21) {
		aceaResult(player);	// ���ʕ\��
	} else if(event == 24) {
		ending[player] = 3;	// �G���f�B���O�˓�
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		aceaExcellent(player, param);	// EXCELLENT���
	} else if(event == 28) {
		aceaIncrementTime(player);	// ���Ԃ�i�߂�
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		aceaSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		aceaLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		aceaLoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		aceaReplayDetail(param[0]);	// ���v���C�ڍ�
	}
}

// ������
void aceaPlayerInitial(int player) {
	// �g�̐F���D�F�ɂ���
	framecolor[player] = 5;
	frame_decoration[player] = 1;
	
	// �ϐ���������
	aceaLines[player] = aceaStartLevel * 10;
	aceaLevel[player] = aceaStartLevel;
	backno = aceaStartLevel;
	
	// ����BGM��ݒ�
	aceaBgm = 0;
	while(aceaLines[player] >= aceaBgmChangeTable[aceaBgm]) aceaBgm++;
	bgmlv = aceaBgmListTable[aceaBgm];
	
	// �����X�s�[�h��ݒ�
	sp[player] = 1200;
	wait1[player] = aceaWait1Table[aceaLevel[player]];
	wait2[player] = aceaWait2Table[aceaLevel[player]];
	wait3[player] = aceaWait3Table[aceaLevel[player]];
	waitt[player] = aceaWaittTable[aceaLevel[player]];
	aceaTimer[player] = 3600;
	
	// �ݒ�𔽉f������
	IsBig[player] = aceaIsBig;
	BigMove[player] = aceaBigMove;
}

// ���C������
void aceaLineErase(int player, int lines) {
	// ���C�������Z
	aceaLines[player] = aceaLines[player] + lines;
	
	// �S����
	if(isBravo(player)) {
		PlaySE(se_levelup);
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
	}
	
	// BGM�t�F�[�h�A�E�g
	if((aceaLines[player] >= aceaBgmFadeTable[aceaBgm]) && (aceaLines[player] < aceaBgmChangeTable[aceaBgm]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// �G���f�B���O
	if(aceaLines[player] >= 150) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		aceaLines[player] = 150;
		ending[player] = 1;
	}
	// ���x���A�b�v
	else if(aceaLines[player] >= (aceaLevel[player] + 1) * 10) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		// �X�s�[�h�A�b�v
		aceaLevel[player]++;
		wait1[player] = aceaWait1Table[aceaLevel[player]];
		wait2[player] = aceaWait2Table[aceaLevel[player]];
		wait3[player] = aceaWait3Table[aceaLevel[player]];
		waitt[player] = aceaWaittTable[aceaLevel[player]];
		aceaTimer[player] = 3600;
		
		// �w�i�؂�ւ�
		bgfadesw = 1;
		bgfadebg = aceaLevel[player];
		
		// ���y�؂�ւ�
		if(aceaLines[player] >= aceaBgmChangeTable[aceaBgm]) {
			aceaBgm++;
			bgmlv = aceaBgmListTable[aceaBgm];
			PlayBGM();
		}
	}
}

// �X�R�A�\��
void aceaViewScore(int player) {
	int color, color2;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// ���x��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "LEVEL");
	sprintf(string[0], "%d", aceaLevel[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// �g�[�^���^�C��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "TOTAL TIME");
	getTime(gameTimer[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// �x�X�g�^�C��
	if((!playback) && (!IsBig[player]) && (!aceaStartLevel)) {
		printTinyFont(foffset[player] + 96, fyoffset[player] + 76, "BEST TIME");
		if(aceaRankingLines[0] >= 150) getTime(aceaRankingTime[0]);
		else getTime(0);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 84, string[0], color);
	}
	
	// �m���}�i���q�j
	ExBltRect(sg_smallfont, foffset[player] + 107, fyoffset[player] + 161, 0, 14, 22, 7);
	sprintf(string[0], "%4d", aceaLines[player]);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 169, string[0], color);
	
	// �m���}�i�����j
	ExBltRect(sg_spr, foffset[player] + 105, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 106, fyoffset[player] + 181, 22, 143, 22, 1);
	
	// �m���}�i����j
	if(ending[player]) sprintf(string[0], "%4d", aceaLines[player]);
	else sprintf(string[0], "%4d", (aceaLevel[player] + 1) * 10);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 185, string[0], color);
	
	// �c�莞��
	if((aceaTimer[player] <= 60 * 10) && (timeOn[player])) color2 = 2;
	else color2 = color;
	getTime(aceaTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
}

// EXCELLENT���
void aceaExcellent(int player, int *param) {
	param[0] = 3;
	onRecord[player] = 0;
	
	// �ԉ�
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// ���Ԃ�i�߂�
void aceaIncrementTime(int player) {
	int i;
	
	if(timeOn[player]) {
		// �������Ԍ���
		aceaTimer[player]--;
		
		// ���Ԑ؂�
		if(aceaTimer[player] <= 0) {
			PlaySE(se_timeover);
			aceaTimer[player] = 0;
			
			timeOn[player] = 0;
			onRecord[player] = 0;
			
			stat[player] = 7;
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		}
		// �c��10�b
		else if(aceaTimer[player] == 10 * 60) {
			PlaySE(se_hurryup);
		}
	}
}

// BGM�ǂݍ���
void aceaLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 3; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/3)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(aceaBgmListTable[i]);
		}
	}
}

// ���ʕ\��
void aceaResult(int player) {
	// �����L���O�o�^
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = aceaRegistRanking(player);
		if(statc[player * 10 + 1] != -1) aceaSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", aceaLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", aceaLevel[player] + 1);
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
void aceaSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(aceaLoadConfig() == 0) aceaSaveConfig();
	
	// �����L���O��ǂݍ���
	if(aceaLoadRanking(player) == 0) aceaInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE-ANOTHER OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "BIG",         7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",    7 * (cursor == 1));
		printFontGrid(2, 5, "START LEVEL", 7 * (cursor == 2));
		
		// �ݒ�l�\��
		if(!aceaIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!aceaBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "LV%d", aceaStartLevel + 1);
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		// �J�[�\���ړ�
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 2;
			if(cursor > 2) cursor = 0;
		}
		
		// �l��ύX
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			if(cursor == 0) aceaIsBig = !aceaIsBig;
			if(cursor == 1) aceaBigMove = !aceaBigMove;
			if(cursor == 2) {
				aceaStartLevel = aceaStartLevel + move;
				if(aceaStartLevel < 0) aceaStartLevel = 14;
				if(aceaStartLevel > 14) aceaStartLevel = 0;
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
			aceaSaveConfig();
			return;
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			aceaViewRanking(player);
		}
	}
}

// ���v���C�ۑ�
void aceaSaveReplay(int player) {
	saveBuf[900] = aceaIsBig;
	saveBuf[901] = aceaBigMove;
	saveBuf[902] = aceaLines[player];
	saveBuf[903] = aceaLevel[player];
	saveBuf[904] = aceaStartLevel;
}

// ���v���C�ǂݍ���
void aceaLoadReplay(int player) {
	aceaIsBig = saveBuf[900];
	aceaBigMove = saveBuf[901];
	aceaStartLevel = saveBuf[904];
	
	aceaPlayerInitial(player);	// �ݒ�𔽉f������
}

// ���v���C�ڍ�
void aceaReplayDetail(int number) {
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
	
	printFontGrid(1, 9, "START LEVEL", 0);
	sprintf(string[0], "LV%d", saveBuf[904] + 1);
	printFontGrid(22, 9, string[0], 0);
}

// �ݒ��ۑ�
void aceaSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x41454341;
	saveBuf[3] = 0x31726576;
	
	// �ݒ���e
	saveBuf[4] = aceaIsBig;
	saveBuf[5] = aceaBigMove;
	saveBuf[6] = aceaStartLevel;
	
	SaveFile("config/ACE_ANOTHER_CONFIG.SAV", &saveBuf, 100 * 4);
}

// �ݒ��ǂݍ���
int aceaLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/ACE_ANOTHER_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x41454341) return 0;
	if(saveBuf[3] != 0x31726576) return 0;
	
	// �ݒ���e
	aceaIsBig = saveBuf[4];
	aceaBigMove = saveBuf[5];
	aceaStartLevel = saveBuf[6];
	
	return 1;
}

// �����L���O�ۑ�
void aceaSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �����L���O���e
	for(i = 0; i < 20; i++) {
		saveBuf[1 + (i * 10) + 0] = aceaRankingTime[i];
		saveBuf[1 + (i * 10) + 1] = aceaRankingLines[i];
		saveBuf[1 + (i * 10) + 2] = aceaRankingYear[i];
		saveBuf[1 + (i * 10) + 3] = aceaRankingMonth[i];
		saveBuf[1 + (i * 10) + 4] = aceaRankingDay[i];
		saveBuf[1 + (i * 10) + 5] = aceaRankingHour[i];
		saveBuf[1 + (i * 10) + 6] = aceaRankingMinute[i];
		saveBuf[1 + (i * 10) + 7] = aceaRankingSecond[i];
	}
	
	sprintf(string[0], "config/ACE_ANOTHER_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 211 * 4);
}

// �����L���O�ǂݍ���
int aceaLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/ACE_ANOTHER_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 211 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �����L���O���e
	for(i = 0; i < 20; i++) {
		aceaRankingTime[i]   = saveBuf[1 + (i * 10) + 0];
		aceaRankingLines[i]  = saveBuf[1 + (i * 10) + 1];
		aceaRankingYear[i]   = saveBuf[1 + (i * 10) + 2];
		aceaRankingMonth[i]  = saveBuf[1 + (i * 10) + 3];
		aceaRankingDay[i]    = saveBuf[1 + (i * 10) + 4];
		aceaRankingHour[i]   = saveBuf[1 + (i * 10) + 5];
		aceaRankingMinute[i] = saveBuf[1 + (i * 10) + 6];
		aceaRankingSecond[i] = saveBuf[1 + (i * 10) + 7];
	}
}

// �����L���O������
void aceaInitRanking() {
	int i;
	
	for(i = 0; i < 20; i++) {
		aceaRankingTime[i] = 0;
		aceaRankingLines[i] = 0;
		aceaRankingYear[i] = 0;
		aceaRankingMonth[i] = 0;
		aceaRankingDay[i] = 0;
		aceaRankingHour[i] = 0;
		aceaRankingMinute[i] = 0;
		aceaRankingSecond[i] = 0;
	}
}

// �����L���O�o�^
int aceaRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (aceaStartLevel)) return -1;
	
	for(i = 0; i < 20; i++) {
		// �����N�C��
		if((aceaLines[player] > aceaRankingLines[i]) || 
		   ((aceaLines[player] == aceaRankingLines[i]) && (gameTimer[player] < aceaRankingTime[i])))
		{
			// �����L���O�����炷
			for(j = 19; j > i; j--) {
				aceaRankingTime[j]   = aceaRankingTime[j - 1];
				aceaRankingLines[j]  = aceaRankingLines[j - 1];
				aceaRankingYear[j]   = aceaRankingYear[j - 1];
				aceaRankingMonth[j]  = aceaRankingMonth[j - 1];
				aceaRankingDay[j]    = aceaRankingDay[j - 1];
				aceaRankingHour[j]   = aceaRankingHour[j - 1];
				aceaRankingMinute[j] = aceaRankingMinute[j - 1];
				aceaRankingSecond[j] = aceaRankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			aceaRankingTime[i]   = gameTimer[player];
			aceaRankingLines[i]  = aceaLines[player];
			
			GetDateAndTime(&timebuf);
			aceaRankingYear[i]   = timebuf[0];
			aceaRankingMonth[i]  = timebuf[1];
			aceaRankingDay[i]    = timebuf[2];
			aceaRankingHour[i]   = timebuf[4];
			aceaRankingMinute[i] = timebuf[5];
			aceaRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �����L���O�\��
void aceaViewRanking(int player) {
	int i, erasemode;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE-ANOTHER MODE RANKING", 6);
		printFontGrid(1, 3, "RANK LINE TIME     DATE", 4);
		
		for(i = 0; i < 20; i++) {
			if(aceaRankingLines[i] >= 150) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, 2, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 0);
			
			sprintf(string[0], "%d", aceaRankingLines[i]);
			printFontGrid(6, 4 + i, string[0], 0);
			
			getTime(aceaRankingTime[i]);
			printFontGrid(11, 4 + i, string[0], 0);
			
			sprintf(string[0], "%04d/%02d/%02d", aceaRankingYear[i], aceaRankingMonth[i], aceaRankingDay[i]);
			printFontGrid(20, 4 + i, string[0], 0);
			
			sprintf(string[0], "%02d:%02d:%02d", aceaRankingHour[i], aceaRankingMinute[i], aceaRankingSecond[i]);
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
				aceaInitRanking();
				aceaSaveRanking(player);
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
