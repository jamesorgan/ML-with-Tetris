//ACE-HI SPEED 2
//prefix:ahsp2

// BGM�֘A
int ahsp2Bgm = 0;								// ���݂�BGM�ԍ�
int ahsp2BgmListTable[3] = {2, 5, 3};			// �g�p����BGM
int ahsp2BgmFadeTable[3] = {45, 95, 145};		// �t�F�[�h�A�E�g���郉�C��
int ahsp2BgmChangeTable[3] = {50, 100, 10000};	// BGM��؂�ւ��郉�C��

// �ϐ�
int ahsp2ModeNo = -1;		// ���[�h�ԍ�
int ahsp2Lines[2];			// ���C��
int ahsp2Level[2];			// ���x��
int ahsp2Timer[2];			// ��������

// �ݒ�
int ahsp2IsBig = 0;			// BIG���ǂ���
int ahsp2BigMove = 1;		// BIG���̉��ړ��P��
int ahsp2StartLevel = 0;	// �X�^�[�g���̃��x��

// �����L���O�p�ϐ�
int ahsp2RankingTime[20];	// �^�C��
int ahsp2RankingLines[20];	// ���C��
int ahsp2RankingYear[20];	// �����N�C�������i�N�j
int ahsp2RankingMonth[20];	// �����N�C�������i���j
int ahsp2RankingDay[20];	// �����N�C�������i���j
int ahsp2RankingHour[20];	// �����N�C�������i���j
int ahsp2RankingMinute[20];	// �����N�C�������i���j
int ahsp2RankingSecond[20];	// �����N�C�������i�b�j

// �C�x���g����
void ahsp2PluginEvent(int player, int event, int *param) {
	int i;
	
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != ahsp2ModeNo)) return;
	
	if(event == 0) {
		// ���[�h��o�^����
		ahsp2ModeNo = addModePlugin("ACE-HI SPEED 2");
	} else if(event == 7) {
		timeOn[player] = 1;	// �u���b�N�o���Ɠ����Ƀ^�C�}�[�ĊJ
	} else if(event == 12) {
		ahsp2LineErase(player, param[0]);	// ���C������
	} else if(event == 15) {
		ahsp2ViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		ahsp2Setting(player, param);	// �ݒ���
	} else if(event == 18) {
		ahsp2PlayerInitial(player);	// ������
	} else if(event == 21) {
		ahsp2Result(player);	// ���ʕ\��
	} else if(event == 24) {
		ending[player] = 3;	// �G���f�B���O�˓�
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		ahsp2Excellent(player, param);	// EXCELLENT���
	} else if(event == 28) {
		ahsp2IncrementTime(player);	// ���Ԃ�i�߂�
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		ahsp2SaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		ahsp2LoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		ahsp2LoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		ahsp2ReplayDetail(param[0]);	// ���v���C�ڍ�
	}
}

// ������
void ahsp2PlayerInitial(int player) {
	// �g�̐F���D�F�ɂ���
	framecolor[player] = 5;
	frame_decoration[player] = 1;
	
	// �ϐ���������
	ahsp2Lines[player] = ahsp2StartLevel * 10;
	ahsp2Level[player] = ahsp2StartLevel;
	backno = ahsp2StartLevel;
	
	// ����BGM��ݒ�
	ahsp2Bgm = 0;
	while(ahsp2Lines[player] >= ahsp2BgmChangeTable[ahsp2Bgm]) ahsp2Bgm++;
	bgmlv = ahsp2BgmListTable[ahsp2Bgm];
	
	// �����X�s�[�h��ݒ�
	sp[player] = 1200;
	ahsp2Timer[player] = 3600;
	
	// �ݒ�𔽉f������
	IsBig[player] = ahsp2IsBig;
	BigMove[player] = ahsp2BigMove;
}

// ���C������
void ahsp2LineErase(int player, int lines) {
	// ���C�������Z
	ahsp2Lines[player] = ahsp2Lines[player] + lines;
	
	// �S����
	if(isBravo(player)) {
		PlaySE(se_levelup);
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
	}
	
	// BGM�t�F�[�h�A�E�g
	if((ahsp2Lines[player] >= ahsp2BgmFadeTable[ahsp2Bgm]) && (ahsp2Lines[player] < ahsp2BgmChangeTable[ahsp2Bgm]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// �G���f�B���O
	if(ahsp2Lines[player] >= 150) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		ahsp2Lines[player] = 150;
		ending[player] = 1;
	}
	// ���x���A�b�v
	else if(ahsp2Lines[player] >= (ahsp2Level[player] + 1) * 10) {
		PlaySE(se_rankup);
		timeOn[player] = 0;
		StopSE(se_hurryup);
		
		// �X�s�[�h�A�b�v
		ahsp2Level[player]++;
		ahsp2Timer[player] = 3600;
		
		// �w�i�؂�ւ�
		bgfadesw = 1;
		bgfadebg = ahsp2Level[player];
		
		// ���y�؂�ւ�
		if(ahsp2Lines[player] >= ahsp2BgmChangeTable[ahsp2Bgm]) {
			ahsp2Bgm++;
			bgmlv = ahsp2BgmListTable[ahsp2Bgm];
			PlayBGM();
		}
	}
}

// �X�R�A�\��
void ahsp2ViewScore(int player) {
	int color, color2;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// ���x��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "LEVEL");
	sprintf(string[0], "%d", ahsp2Level[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// �g�[�^���^�C��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "TOTAL TIME");
	getTime(gameTimer[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// �x�X�g�^�C��
	if((!playback) && (!IsBig[player]) && (!ahsp2StartLevel)) {
		printTinyFont(foffset[player] + 96, fyoffset[player] + 76, "BEST TIME");
		if(ahsp2RankingLines[0] >= 150) getTime(ahsp2RankingTime[0]);
		else getTime(0);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 84, string[0], color);
	}
	
	// �m���}�i���q�j
	ExBltRect(sg_smallfont, foffset[player] + 107, fyoffset[player] + 161, 0, 14, 22, 7);
	sprintf(string[0], "%4d", ahsp2Lines[player]);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 169, string[0], color);
	
	// �m���}�i�����j
	ExBltRect(sg_spr, foffset[player] + 105, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 106, fyoffset[player] + 181, 22, 143, 22, 1);
	
	// �m���}�i����j
	if(ending[player]) sprintf(string[0], "%4d", ahsp2Lines[player]);
	else sprintf(string[0], "%4d", (ahsp2Level[player] + 1) * 10);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 185, string[0], color);
	
	// �c�莞��
	if((ahsp2Timer[player] <= 60 * 10) && (timeOn[player])) color2 = 2;
	else color2 = color;
	getTime(ahsp2Timer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
}

// EXCELLENT���
void ahsp2Excellent(int player, int *param) {
	param[0] = 3;
	onRecord[player] = 0;
	
	// �ԉ�
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
}

// ���Ԃ�i�߂�
void ahsp2IncrementTime(int player) {
	int i;
	
	if(timeOn[player]) {
		// �������Ԍ���
		ahsp2Timer[player]--;
		
		// ���Ԑ؂�
		if(ahsp2Timer[player] <= 0) {
			PlaySE(se_timeover);
			ahsp2Timer[player] = 0;
			
			timeOn[player] = 0;
			onRecord[player] = 0;
			
			stat[player] = 7;
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		}
		// �c��10�b
		else if(ahsp2Timer[player] == 10 * 60) {
			PlaySE(se_hurryup);
		}
	}
}

// BGM�ǂݍ���
void ahsp2LoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 3; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/3)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(ahsp2BgmListTable[i]);
		}
	}
}

// ���ʕ\��
void ahsp2Result(int player) {
	// �����L���O�o�^
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = ahsp2RegistRanking(player);
		if(statc[player * 10 + 1] != -1) ahsp2SaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", ahsp2Lines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", ahsp2Level[player] + 1);
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
void ahsp2Setting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(ahsp2LoadConfig() == 0) ahsp2SaveConfig();
	
	// �����L���O��ǂݍ���
	if(ahsp2LoadRanking(player) == 0) ahsp2InitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE-HI SPEED 2 OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "BIG",         7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",    7 * (cursor == 1));
		printFontGrid(2, 5, "START LEVEL", 7 * (cursor == 2));
		
		// �ݒ�l�\��
		if(!ahsp2IsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!ahsp2BigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "LV%d", ahsp2StartLevel + 1);
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
			if(cursor == 0) ahsp2IsBig = !ahsp2IsBig;
			if(cursor == 1) ahsp2BigMove = !ahsp2BigMove;
			if(cursor == 2) {
				ahsp2StartLevel = ahsp2StartLevel + move;
				if(ahsp2StartLevel < 0) ahsp2StartLevel = 14;
				if(ahsp2StartLevel > 14) ahsp2StartLevel = 0;
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
			ahsp2SaveConfig();
			return;
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			ahsp2ViewRanking(player);
		}
	}
}

// ���v���C�ۑ�
void ahsp2SaveReplay(int player) {
	saveBuf[900] = ahsp2IsBig;
	saveBuf[901] = ahsp2BigMove;
	saveBuf[902] = ahsp2Lines[player];
	saveBuf[903] = ahsp2Level[player];
	//saveBuf[904] = ahsp2Ghost;
	saveBuf[905] = ahsp2StartLevel;
}

// ���v���C�ǂݍ���
void ahsp2LoadReplay(int player) {
	ahsp2IsBig = saveBuf[900];
	ahsp2BigMove = saveBuf[901];
	//ahsp2Ghost = saveBuf[904];
	ahsp2StartLevel = saveBuf[905];
	
	ahsp2PlayerInitial(player);	// �ݒ�𔽉f������
}

// ���v���C�ڍ�
void ahsp2ReplayDetail(int number) {
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
	sprintf(string[0], "LV%d", saveBuf[905] + 1);
	printFontGrid(22, 9, string[0], 0);
}

// �ݒ��ۑ�
void ahsp2SaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x48454341;
	saveBuf[3] = 0x31763253;
	
	// �ݒ���e
	saveBuf[4] = ahsp2IsBig;
	saveBuf[5] = ahsp2BigMove;
	//saveBuf[6] = ahsp2Ghost;
	saveBuf[7] = ahsp2StartLevel;
	
	SaveFile("config/ACE_HI_SPEED_2_CONFIG.SAV", &saveBuf, 100 * 4);
}

// �ݒ��ǂݍ���
int ahsp2LoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/ACE_HI_SPEED_2_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x48454341) return 0;
	if(saveBuf[3] != 0x31763253) return 0;
	
	// �ݒ���e
	ahsp2IsBig = saveBuf[4];
	ahsp2BigMove = saveBuf[5];
	//ahsp2Ghost = saveBuf[6];
	ahsp2StartLevel = saveBuf[7];
	
	return 1;
}

// �����L���O�ۑ�
void ahsp2SaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �����L���O���e
	for(i = 0; i < 20; i++) {
		saveBuf[1 + (i * 10) + 0] = ahsp2RankingTime[i];
		saveBuf[1 + (i * 10) + 1] = ahsp2RankingLines[i];
		saveBuf[1 + (i * 10) + 2] = ahsp2RankingYear[i];
		saveBuf[1 + (i * 10) + 3] = ahsp2RankingMonth[i];
		saveBuf[1 + (i * 10) + 4] = ahsp2RankingDay[i];
		saveBuf[1 + (i * 10) + 5] = ahsp2RankingHour[i];
		saveBuf[1 + (i * 10) + 6] = ahsp2RankingMinute[i];
		saveBuf[1 + (i * 10) + 7] = ahsp2RankingSecond[i];
	}
	
	sprintf(string[0], "config/ACE_HI_SPEED_2_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 211 * 4);
}

// �����L���O�ǂݍ���
int ahsp2LoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/ACE_HI_SPEED_2_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 211 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �����L���O���e
	for(i = 0; i < 20; i++) {
		ahsp2RankingTime[i]   = saveBuf[1 + (i * 10) + 0];
		ahsp2RankingLines[i]  = saveBuf[1 + (i * 10) + 1];
		ahsp2RankingYear[i]   = saveBuf[1 + (i * 10) + 2];
		ahsp2RankingMonth[i]  = saveBuf[1 + (i * 10) + 3];
		ahsp2RankingDay[i]    = saveBuf[1 + (i * 10) + 4];
		ahsp2RankingHour[i]   = saveBuf[1 + (i * 10) + 5];
		ahsp2RankingMinute[i] = saveBuf[1 + (i * 10) + 6];
		ahsp2RankingSecond[i] = saveBuf[1 + (i * 10) + 7];
	}
}

// �����L���O������
void ahsp2InitRanking() {
	int i;
	
	for(i = 0; i < 20; i++) {
		ahsp2RankingTime[i] = 0;
		ahsp2RankingLines[i] = 0;
		ahsp2RankingYear[i] = 0;
		ahsp2RankingMonth[i] = 0;
		ahsp2RankingDay[i] = 0;
		ahsp2RankingHour[i] = 0;
		ahsp2RankingMinute[i] = 0;
		ahsp2RankingSecond[i] = 0;
	}
}

// �����L���O�o�^
int ahsp2RegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (ahsp2StartLevel)) return -1;
	
	for(i = 0; i < 20; i++) {
		// �����N�C��
		if((ahsp2Lines[player] > ahsp2RankingLines[i]) || 
		   ((ahsp2Lines[player] == ahsp2RankingLines[i]) && (gameTimer[player] < ahsp2RankingTime[i])))
		{
			// �����L���O�����炷
			for(j = 19; j > i; j--) {
				ahsp2RankingTime[j]   = ahsp2RankingTime[j - 1];
				ahsp2RankingLines[j]  = ahsp2RankingLines[j - 1];
				ahsp2RankingYear[j]   = ahsp2RankingYear[j - 1];
				ahsp2RankingMonth[j]  = ahsp2RankingMonth[j - 1];
				ahsp2RankingDay[j]    = ahsp2RankingDay[j - 1];
				ahsp2RankingHour[j]   = ahsp2RankingHour[j - 1];
				ahsp2RankingMinute[j] = ahsp2RankingMinute[j - 1];
				ahsp2RankingSecond[j] = ahsp2RankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			ahsp2RankingTime[i]   = gameTimer[player];
			ahsp2RankingLines[i]  = ahsp2Lines[player];
			
			GetDateAndTime(&timebuf);
			ahsp2RankingYear[i]   = timebuf[0];
			ahsp2RankingMonth[i]  = timebuf[1];
			ahsp2RankingDay[i]    = timebuf[2];
			ahsp2RankingHour[i]   = timebuf[4];
			ahsp2RankingMinute[i] = timebuf[5];
			ahsp2RankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �����L���O�\��
void ahsp2ViewRanking(int player) {
	int i, erasemode;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ACE-HI SPEED 2 MODE RANKING", 6);
		printFontGrid(1, 3, "RANK LINE TIME     DATE", 4);
		
		for(i = 0; i < 20; i++) {
			if(ahsp2RankingLines[i] >= 150) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, 2, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 0);
			
			sprintf(string[0], "%d", ahsp2RankingLines[i]);
			printFontGrid(6, 4 + i, string[0], 0);
			
			getTime(ahsp2RankingTime[i]);
			printFontGrid(11, 4 + i, string[0], 0);
			
			sprintf(string[0], "%04d/%02d/%02d", ahsp2RankingYear[i], ahsp2RankingMonth[i], ahsp2RankingDay[i]);
			printFontGrid(20, 4 + i, string[0], 0);
			
			sprintf(string[0], "%02d:%02d:%02d", ahsp2RankingHour[i], ahsp2RankingMinute[i], ahsp2RankingSecond[i]);
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
				ahsp2InitRanking();
				ahsp2SaveRanking(player);
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
