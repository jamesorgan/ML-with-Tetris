//MARATHON-ONI
//prefix:maro

// ���x���A�b�v�e�[�u��
int maroWait1[15] = {15, 14, 10,  9,  5,  3,  3,  3,  3,  2,  2,  2,  1,  0,  0};
int maroWait2[15] = { 8,  8,  5,  5,  3,  3,  3,  3,  3,  3,  2,  1,  0,  0,  0};
int maroWait3[15] = {30, 26, 20, 19, 17, 14, 12, 11, 11, 11, 11, 11, 10, 10,  8};
int maroWaitt[15] = {12, 12, 10, 10,  9,  9,  6,  6,  6,  6,  6,  6,  6,  4,  2};

// �ϐ�
int maroModeNo = -1;		// ���[�h�ԍ�

int maroVersion;			// �o�[�W�����ԍ�
int maroCVersion = 1;		// ���݂̃o�[�W����

int maroScore[2];			// �X�R�A
int maroLines[2];			// ���C��
int maroLevel[2];			// ���x��
int maroGoal[2];			// ���x���A�b�v�܂ł̃|�C���g��

int maroHeborisCount[2];	// �w�{���X��
int maroTSpinCount[2];		// T-SPIN��

int maroTSpinFrame[2];		// T-SPIN�\���^�w�{���X�\���̎c�莞��
int maroTSpinLine[2];		// �Ō��T-SPIN���C�������^�w�{���X�����̎��
int maroComboFrame[2];		// �R���{���\���̎c�莞��
int maroB2BFrame[2];		// Back To Back�\���̎c�莞��
int maroTSpinWall[2];		// �ǏR�肠���T-SPIN��������1�ɂȂ�
int maroScoreGet[2];		// ���������X�R�A�\���̓_��
int maroScoreFrame[2];		// ���������X�R�A�\���̎c�莞��
int maroGoalGet[2];			// ���������|�C���g�\���̓_��
int maroGoalFrame[2];		// ���������|�C���g�\���̎c�莞��

int maroIsBig = 0;			// BIG���ǂ���
int maroBigMove = 1;		// BIG���̉��ړ��P��
int maroBgm = 17;			// �g�p����BGM
int maroTSpin = 3;			// T-SPIN�̎��
int maroEnableCombo = 1;	// �R���{�{�[�i�X�̗L��
int maroEnableB2B = 1;		// Back To Back�̗L���i0=�Ȃ� 1=�ʏ� 2=�w�{���X�̂� 3=T-SPIN�̂݁j
int maroStartLevel = 0;		// �X�^�[�g���̃��x��
int maroCarryOver = 0;		// �ڕW�|�C���g�̎����x���ւ̌J��z���̗L��

// �����L���O�p�ϐ�
int maroRankingScore[10];	// �X�R�A
int maroRankingLines[10];	// ���C��
int maroRankingLevel[10];	// ���x��
int maroRankingHeboris[10];	// �w�{���X��
int maroRankingTSpin[10];	// T-SPIN��
int maroRankingTime[10];	// �^�C��
int maroRankingYear[10];	// �����N�C�������i�N�j
int maroRankingMonth[10];	// �����N�C�������i���j
int maroRankingDay[10];		// �����N�C�������i���j
int maroRankingHour[10];	// �����N�C�������i���j
int maroRankingMinute[10];	// �����N�C�������i���j
int maroRankingSecond[10];	// �����N�C�������i�b�j

// �C�x���g����
void maroPluginEvent(int player, int event, int *param) {
	int i;
	
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != maroModeNo)) return;
	
	if(event == 0) {
		maroModeNo = addModePlugin("MARATHON-ONI");	// ���[�h��o�^����
	} else if(event == 12) {
		maroCalcScore(player, param[0]);	// �X�R�A�v�Z
	} else if(event == 15) {
		maroViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		maroSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		maroPlayerInitial(player);	// ������
	} else if(event == 21) {
		maroResult(player);	// ���ʕ\��
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		maroSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		maroLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		maroLoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		maroReplayDetail();	// ���v���C�ڍ�
	} else if(event == 59) {
		maroTSpinZero(player);	// ���C�������Ȃ���T-SPIN
	}
}

// ������
void maroPlayerInitial(int player) {
	// �o�[�W����
	if(!playback) maroVersion = maroCVersion;
	
	// �ϐ���������
	maroScore[player] = 0;
	maroLines[player] = 0;
	maroLevel[player] = maroStartLevel;
	maroGoal[player] = 5 * (maroLevel[player] + 1);
	
	maroHeborisCount[player] = 0;
	maroTSpinCount[player] = 0;
	
	maroTSpinFrame[player] = 0;
	maroTSpinLine[player] = 0;
	maroComboFrame[player] = 0;
	maroB2BFrame[player] = 0;
	maroTSpinWall[player] = 0;
	maroScoreGet[player] = 0;
	maroScoreFrame[player] = 0;
	maroGoalGet[player] = 0;
	maroGoalFrame[player] = 0;
	
	// �������x
	sp[player] = 1200;
	wait1[player] = maroWait1[maroLevel[player]];
	wait2[player] = maroWait2[maroLevel[player]];
	wait3[player] = maroWait3[maroLevel[player]];
	waitt[player] = maroWaitt[maroLevel[player]];
	if(maroLevel[player] >= 9) oblk_spawn[player] = 1;
	else oblk_spawn[player] = 0;
	
	// �g�̐F��ς���
	framecolor[player] = 2;
	frame_decoration[player] = 1;
	
	// �ݒ�𔽉f������
	IsBig[player] = maroIsBig;
	BigMove[player] = maroBigMove;
	bgmlv = maroBgm;
	tspin_type[player] = maroTSpin;
	enable_combo[player] = maroEnableCombo;
	b_to_b_type[player] = maroEnableB2B;
	backno = maroLevel[player];
}

// �X�R�A�v�Z
void maroCalcScore(int player, int lines) {
	int bo, b2b, combopts, combogoal, points;
	
	// T-SPIN��
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		maroTSpinFrame[player] = 60;
		maroTSpinLine[player] = lines;
		maroTSpinWall[player] = (last_command[player] == 4);
		maroTSpinCount[player]++;
		
		if((lines == 1) && (maroTSpinWall[player])) bo = 2;	// �ǏR�肠��T-SPIN Single
		if((lines == 1) && (!maroTSpinWall[player])) bo = 8;	// �ǏR��Ȃ�T-SPIN Single
		if(lines == 2) bo = 12;	// T-SPIN Double
		if(lines == 3) bo = 16;	// T-SPIN Triple
	}
	// ���ʂ̃��C������
	else {
		if(lines == 1) bo = 1;
		if(lines == 2) bo = 3;
		if(lines == 3) bo = 5;
		if(lines == 4) {
			maroTSpinFrame[player] = 60;
			maroTSpinLine[player] = lines;
			maroHeborisCount[player]++;
			bo = 8;
		}
	}
	
	// B2B�{�[�i�X�ix 1.5�j
	if((maroEnableB2B != 0) && (b_to_b_count[player] >= 2)) {
		b2b = 1;
		maroB2BFrame[player] = 60;
	} else {
		b2b = 0;
		maroB2BFrame[player] = 0;
	}
	
	// �R���{�{�[�i�X
	if((maroEnableCombo != 0) && (combo[player] >= 2)) {
		combopts = (combo[player] - 1) * 50;
		if(maroVersion >= 1) combopts = combopts * (maroLevel[player] + 1);
		
		if(combo[player] >= 12) combogoal = 5;
		else if(combo[player] >= 9) combogoal = 4;
		else if(combo[player] >= 7) combogoal = 3;
		else if(combo[player] >= 5) combogoal = 2;
		else if(combo[player] >= 3) combogoal = 1;
		else combogoal = 0;
		
		maroComboFrame[player] = 60;
	} else {
		combopts = 0;
		combogoal = 0;
	}
	
	// �S�����{�[�i�X
	if(isBravo(player)) {
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		bo = bo + 50;
	}
	
	// �X�R�A���Z
	points = (bo * 100) * (maroLevel[player] + 1);
	maroScore[player] = maroScore[player] + points;
	if(b2b) maroScore[player] = maroScore[player] + (points / 2);
	maroScore[player] = maroScore[player] + combopts;
	
	maroScoreGet[player] = points + ((points / 2) * (b2b)) + combopts;
	maroScoreFrame[player] = 120;
	
	// ���C�����Z
	maroLines[player] = maroLines[player] + lines;
	
	// �S�[������
	maroGoal[player] = maroGoal[player] - bo;
	if(b2b) maroGoal[player] = maroGoal[player] - (bo / 2);
	maroGoal[player] = maroGoal[player] - combogoal;
	
	if(maroLevel[player] < 14) {
		maroGoalGet[player] = bo + ((bo / 2) * (b2b)) + combogoal;
		maroGoalFrame[player] = 120;
	}
	
	// ���x���A�b�v
	maroLevelUp(player);
}

// ���C�������Ȃ���T-SPIN
void maroTSpinZero(int player) {
	PlaySE(se_tspin);
	maroTSpinFrame[player] = 60;
	maroTSpinLine[player] = 0;
	maroTSpinCount[player]++;
	
	// �ǏR�肠��
	if(last_command[player] == 4) {
		maroScore[player] = maroScore[player] + (100 * (maroLevel[player] + 1));
		maroGoal[player] = maroGoal[player] - 1;
		maroTSpinWall[player] = 1;
		
		maroScoreGet[player] = 100 * (maroLevel[player] + 1);
		maroScoreFrame[player] = 120;
		
		if(maroLevel[player] < 14) {
			maroGoalGet[player] = 1;
			maroGoalFrame[player] = 120;
		}
	}
	// �ǏR��Ȃ�
	else {
		maroScore[player] = maroScore[player] + (400 * (maroLevel[player] + 1));
		maroGoal[player] = maroGoal[player] - 4;
		maroTSpinWall[player] = 0;
		
		maroScoreGet[player] = 400 * (maroLevel[player] + 1);
		maroScoreFrame[player] = 120;
		
		if(maroLevel[player] < 14) {
			maroGoalGet[player] = 4;
			maroGoalFrame[player] = 120;
		}
	}
	
	// ���x���A�b�v
	maroLevelUp(player);
}

// ���x���A�b�v
void maroLevelUp(int player) {
	int carrypoints;
	
	while((maroGoal[player] <= 0) && (maroLevel[player] < 14)) {
		// �����x���ւ̌J��z���|�C���g
		if(maroCarryOver)
			carrypoints = abs(maroGoal[player]);
		else
			carrypoints = 0;
		
		// ���x���A�b�v
		maroLevel[player]++;
		maroGoal[player] = (5 * (maroLevel[player] + 1)) - carrypoints;
		
		wait1[player] = maroWait1[maroLevel[player]];
		wait2[player] = maroWait2[maroLevel[player]];
		wait3[player] = maroWait3[maroLevel[player]];
		waitt[player] = maroWaitt[maroLevel[player]];
		
		if(maroLevel[player] >= 9) oblk_spawn[player] = 1;
		
		if(maroLevel[player] == 14) PlaySE(se_ttclear);
		else PlaySE(se_rankup);
		bgfadesw = 1;
		bgfadebg = maroLevel[player];
	}
}

// �X�R�A�\��
void maroViewScore(int player) {
	int color;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// �X�R�A
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "SCORE");
	sprintf(string[0], "%d", maroScore[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// �����������_
	if(maroScoreFrame[player] > 0) {
		maroScoreFrame[player]--;
		sprintf(string[0], "%d", maroScoreGet[player]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 58, string[0], (count % 4 / 2) * (1 + (b_to_b_count[player] != 0)));
	}
	
	// ���x��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 68, "LEVEL");
	sprintf(string[0], "%d", maroLevel[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 76, string[0], color);
	
	if(maroLevel[player] < 14) {
		// �S�[��
		printTinyFont(foffset[player] + 96, fyoffset[player] + 86, "GOAL");
		sprintf(string[0], "%d", maroGoal[player]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 94, string[0], color);
	} else {
		// ���C��
		printTinyFont(foffset[player] + 96, fyoffset[player] + 86, "LINES");
		sprintf(string[0], "%d", maroLines[player]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 94, string[0], color);
	}
	
	// ���������|�C���g
	if(maroGoalFrame[player] > 0) {
		maroGoalFrame[player]--;
		sprintf(string[0], "%d", maroGoalGet[player]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 104, string[0], (count % 4 / 2) * (1 + (b_to_b_count[player] != 0)));
	}
	
	// �^�C��
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
	
	// T-SPIN
	if(maroTSpinFrame[player] > 0) {
		maroTSpinFrame[player]--;
		
		if((maroTSpinLine[player] == 0) && (maroTSpinWall[player]))
			printTinyFont(foffset[player] + 25, fyoffset[player] + 208, "EZ T-SPIN");
		else if((maroTSpinLine[player] == 0) && (!maroTSpinWall[player]))
			printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "T-SPIN");
		else if((maroTSpinLine[player] == 1) && (maroTSpinWall[player]))
			printTinyFont(foffset[player] + 20, fyoffset[player] + 208, "T-SPIN MINI");
		else if((maroTSpinLine[player] == 1) && (!maroTSpinWall[player]))
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN SINGLE");
		else if(maroTSpinLine[player] == 2)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN DOUBLE");
		else if(maroTSpinLine[player] == 3)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN TRIPLE");
		else if(maroTSpinLine[player] == 4)
			printTinyFont(foffset[player] + 30, fyoffset[player] + 208, "HEBORIS");
	}
	
	// BACK TO BACK
	if(maroB2BFrame[player] > 0) {
		maroB2BFrame[player]--;
		printTinyFont(foffset[player] + 18, fyoffset[player] + 200, "BACK TO BACK");
	}
	// COMBO
	else if((maroComboFrame[player] > 0) && (combo[player] >= 2)) {
		maroComboFrame[player]--;
		sprintf(string[0], "COMBO %d", combo[player] - 1);
		printTinyFont(foffset[player] + 30, fyoffset[player] + 200, string[0]);
	}
}

// ���ʕ\��
void maroResult(int player) {
	// �����L���O�o�^
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = maroRegistRanking(player);
		if(statc[player * 10 + 1] != -1) maroSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 45, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 59, "SCORE");
	sprintf(string[0], "%13d", maroScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 67, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", maroLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", maroLevel[player] + 1);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "HEBORIS");
	sprintf(string[0], "%13d", maroHeborisCount[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 139, "T-SPIN");
	sprintf(string[0], "%13d", maroTSpinCount[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 147, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 159, "TIME");
	getTime(gameTimer[player]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[1], 0);
	
	if(statc[player * 10 + 1] != -1) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 179, "RANK");
		sprintf(string[0], "%13d", statc[player * 10 + 1] + 1);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 187, string[0], 0);
	}
}

// BGM�ǂݍ���
void maroLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(maroBgm);
	}
}

// �ݒ���
void maroSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(maroLoadConfig() == 0) maroSaveConfig();
	
	// �����L���O��ǂݍ���
	if(maroLoadRanking(player) == 0) maroInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "MARATHON-ONI OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "BIG",          7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",     7 * (cursor == 1));
		printFontGrid(2, 5, "BGM",          7 * (cursor == 2));
		printFontGrid(2, 6, "T-SPIN",       7 * (cursor == 3));
		printFontGrid(2, 7, "COMBO",        7 * (cursor == 4));
		printFontGrid(2, 8, "BACK TO BACK", 7 * (cursor == 5));
		printFontGrid(2, 9, "START LEVEL",  7 * (cursor == 6));
		printFontGrid(2, 10, "CARRY OVER",  7 * (cursor == 7));
		
		// �ݒ�l�\��
		if(!maroIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!maroBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "%d", maroBgm);
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(maroTSpin == 0) sprintf(string[0], "OFF");
		else if(maroTSpin == 1) sprintf(string[0], "LINE CLEAR");
		else if(maroTSpin == 2) sprintf(string[0], "IMMOBILE");
		else if(maroTSpin == 3) sprintf(string[0], "3-CORNER");
		else sprintf(string[0], "3-CORNER NO KICK");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(!maroEnableCombo) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		if(maroEnableB2B == 0) sprintf(string[0], "OFF");
		else if(maroEnableB2B == 1) sprintf(string[0], "ON");
		else if(maroEnableB2B == 2) sprintf(string[0], "HEBORIS ONLY");
		else sprintf(string[0], "T-SPIN ONLY");
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		sprintf(string[0], "%d", maroStartLevel + 1);
		printFontGrid(22, 9, string[0], 7 * (cursor == 6));
		
		if(!maroCarryOver) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 10, string[0], 7 * (cursor == 7));
		
		// �J�[�\���ړ�
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 7;
			if(cursor > 7) cursor = 0;
		}
		
		// �l��ύX
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) maroIsBig = !maroIsBig;
			if(cursor == 1) maroBigMove = !maroBigMove;
			if(cursor == 2) {
				maroBgm = maroBgm + move;
				if(maroBgm < 0) maroBgm = 29;
				if(maroBgm > 29) maroBgm = 0;
			}
			if(cursor == 3) {
				maroTSpin = maroTSpin + move;
				if(maroTSpin < 0) maroTSpin = 4;
				if(maroTSpin > 4) maroTSpin = 0;
			}
			if(cursor == 4) maroEnableCombo = !maroEnableCombo;
			if(cursor == 5) {
				maroEnableB2B = maroEnableB2B + move;
				if(maroEnableB2B < 0) maroEnableB2B = 3;
				if(maroEnableB2B > 3) maroEnableB2B = 0;
			}
			if(cursor == 6) {
				maroStartLevel = maroStartLevel + move;
				if(maroStartLevel < 0) maroStartLevel = 14;
				if(maroStartLevel > 14) maroStartLevel = 0;
			}
			if(cursor == 7) maroCarryOver = !maroCarryOver;
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
			maroSaveConfig();
			return;
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			maroViewRanking(player);
		}
	}
}

// �ݒ��ۑ�
void maroSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x4152414D;
	saveBuf[1] = 0x4E4F4854;
	saveBuf[2] = 0x494E4F2D;
	saveBuf[3] = 0x31726576;
	
	// �ݒ���e
	saveBuf[4] = maroIsBig;
	saveBuf[5] = maroBigMove;
	saveBuf[6] = maroBgm;
	saveBuf[7] = maroTSpin;
	saveBuf[8] = maroEnableCombo;
	saveBuf[9] = maroEnableB2B;
	saveBuf[10] = maroStartLevel;
	saveBuf[11] = maroCarryOver;
	
	SaveFile("config/MARATHON_ONI_CONFIG.SAV", &saveBuf, 100 * 4);
}

// �ݒ��ǂݍ���
int maroLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/MARATHON_ONI_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x4152414D) return 0;
	if(saveBuf[1] != 0x4E4F4854) return 0;
	if(saveBuf[2] != 0x494E4F2D) return 0;
	if(saveBuf[3] != 0x31726576) return 0;
	
	// �ݒ���e
	maroIsBig = saveBuf[4];
	maroBigMove = saveBuf[5];
	maroBgm = saveBuf[6];
	maroTSpin = saveBuf[7];
	maroEnableCombo = saveBuf[8];
	maroEnableB2B = saveBuf[9];
	maroStartLevel = saveBuf[10];
	maroCarryOver = saveBuf[11];
	
	return 1;
}

// ���v���C�ۑ�
void maroSaveReplay(int player) {
	saveBuf[900] = maroScore[player];
	saveBuf[901] = maroLines[player];
	saveBuf[902] = maroLevel[player];
	saveBuf[903] = maroIsBig;
	saveBuf[904] = maroBigMove;
	saveBuf[905] = maroBgm;
	saveBuf[906] = maroTSpin;
	saveBuf[907] = maroEnableCombo;
	saveBuf[908] = maroEnableB2B;
	saveBuf[909] = maroHeborisCount[player];
	saveBuf[910] = maroTSpinCount[player];
	saveBuf[911] = maroStartLevel;
	saveBuf[912] = maroVersion;
	saveBuf[913] = maroCarryOver;
}

// ���v���C�ǂݍ���
void maroLoadReplay(int player) {
	maroIsBig = saveBuf[903];
	maroBigMove = saveBuf[904];
	maroBgm = saveBuf[905];
	maroTSpin = saveBuf[906];
	maroEnableCombo = saveBuf[907];
	maroEnableB2B = saveBuf[908];
	maroStartLevel = saveBuf[911];
	maroVersion = saveBuf[912];
	maroCarryOver = saveBuf[913];
	
	maroPlayerInitial(player);	// �ݒ�𔽉f������
}

// ���v���C�ڍ�
void maroReplayDetail() {
	printFontGrid(1, 5, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[900]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "LINES", 0);
	sprintf(string[0], "%d", saveBuf[901]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[902] + 1);
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 8, "TOTAL HEBORIS", 0);
	sprintf(string[0], "%d", saveBuf[909]);
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "TOTAL T-SPIN", 0);
	sprintf(string[0], "%d", saveBuf[910]);
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 11, "BIG", 0);
	if(!saveBuf[903]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "BIG MOVE", 0);
	if(!saveBuf[904]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 12, string[0], 0);
	
	printFontGrid(1, 13, "BGM", 0);
	sprintf(string[0], "%d", saveBuf[905]);
	printFontGrid(22, 13, string[0], 0);
	
	printFontGrid(1, 14, "T-SPIN", 0);
	if(saveBuf[906] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[906] == 1) sprintf(string[0], "LINE CLEAR");
	else if(saveBuf[906] == 2) sprintf(string[0], "IMMOBILE");
	else if(saveBuf[906] == 3) sprintf(string[0], "3-CORNER");
	else sprintf(string[0], "3-CORNER NO KICK");
	printFontGrid(22, 14, string[0], 0);
	
	printFontGrid(1, 15, "COMBO", 0);
	if(!saveBuf[907]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 15, string[0], 0);
	
	printFontGrid(1, 16, "BACK TO BACK", 0);
	if(saveBuf[908] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[908] == 1) sprintf(string[0], "ON");
	else if(saveBuf[908] == 2) sprintf(string[0], "HEBORIS ONLY");
	else sprintf(string[0], "T-SPIN ONLY");
	printFontGrid(22, 16, string[0], 0);
	
	printFontGrid(1, 17, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[911] + 1);
	printFontGrid(22, 17, string[0], 0);
	
	printFontGrid(1, 18, "CARRY OVER", 0);
	if(!saveBuf[913]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 18, string[0], 0);
	
	printFontGrid(1, 20, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[912]);
	printFontGrid(22, 20, string[0], 0);
}

// �����L���O�ۑ�
void maroSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0]  = maroRankingScore[i];
		saveBuf[1 + (i * 20) + 1]  = maroRankingLines[i];
		saveBuf[1 + (i * 20) + 2]  = maroRankingLevel[i];
		saveBuf[1 + (i * 20) + 3]  = maroRankingHeboris[i];
		saveBuf[1 + (i * 20) + 4]  = maroRankingTSpin[i];
		saveBuf[1 + (i * 20) + 5]  = maroRankingTime[i];
		saveBuf[1 + (i * 20) + 6]  = maroRankingYear[i];
		saveBuf[1 + (i * 20) + 7]  = maroRankingMonth[i];
		saveBuf[1 + (i * 20) + 8]  = maroRankingDay[i];
		saveBuf[1 + (i * 20) + 9]  = maroRankingHour[i];
		saveBuf[1 + (i * 20) + 10] = maroRankingMinute[i];
		saveBuf[1 + (i * 20) + 11] = maroRankingSecond[i];
	}
	
	sprintf(string[0], "config/MARATHON_ONI_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 221 * 4);
}

// �����L���O�ǂݍ���
int maroLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/MARATHON_ONI_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 221 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		maroRankingScore[i]   = saveBuf[1 + (i * 20) + 0];
		maroRankingLines[i]   = saveBuf[1 + (i * 20) + 1];
		maroRankingLevel[i]   = saveBuf[1 + (i * 20) + 2];
		maroRankingHeboris[i] = saveBuf[1 + (i * 20) + 3];
		maroRankingTSpin[i]   = saveBuf[1 + (i * 20) + 4];
		maroRankingTime[i]    = saveBuf[1 + (i * 20) + 5];
		maroRankingYear[i]    = saveBuf[1 + (i * 20) + 6];
		maroRankingMonth[i]   = saveBuf[1 + (i * 20) + 7];
		maroRankingDay[i]     = saveBuf[1 + (i * 20) + 8];
		maroRankingHour[i]    = saveBuf[1 + (i * 20) + 9];
		maroRankingMinute[i]  = saveBuf[1 + (i * 20) + 10];
		maroRankingSecond[i]  = saveBuf[1 + (i * 20) + 11];
	}
	
	return 1;
}

// �����L���O������
void maroInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		maroRankingScore[i]   = 0;
		maroRankingLines[i]   = 0;
		maroRankingLevel[i]   = 0;
		maroRankingHeboris[i] = 0;
		maroRankingTSpin[i]   = 0;
		maroRankingTime[i]    = 0;
		maroRankingYear[i]    = 0;
		maroRankingMonth[i]   = 0;
		maroRankingDay[i]     = 0;
		maroRankingHour[i]    = 0;
		maroRankingMinute[i]  = 0;
		maroRankingSecond[i]  = 0;
	}
}

// �����L���O�o�^
int maroRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (maroIsBig)) return -1;
	
	for(i = 0; i < 10; i++) {
		// �����N�C��
		if((maroScore[player] > maroRankingScore[i]) || 
		   ((maroScore[player] == maroRankingScore[i]) && (gameTimer[player] < maroRankingTime[i])))
		{
			// �����L���O�����炷
			for(j = 9; j > i; j--) {
				maroRankingScore[j]   = maroRankingScore[j - 1];
				maroRankingLines[j]   = maroRankingLines[j - 1];
				maroRankingLevel[j]   = maroRankingLevel[j - 1];
				maroRankingHeboris[j] = maroRankingHeboris[j - 1];
				maroRankingTSpin[j]   = maroRankingTSpin[j - 1];
				maroRankingTime[j]    = maroRankingTime[j - 1];
				maroRankingYear[j]    = maroRankingYear[j - 1];
				maroRankingMonth[j]   = maroRankingMonth[j - 1];
				maroRankingDay[j]     = maroRankingDay[j - 1];
				maroRankingHour[j]    = maroRankingHour[j - 1];
				maroRankingMinute[j]  = maroRankingMinute[j - 1];
				maroRankingSecond[j]  = maroRankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			maroRankingScore[i]   = maroScore[player];
			maroRankingLines[i]   = maroLines[player];
			maroRankingLevel[i]   = maroLevel[player];
			maroRankingHeboris[i] = maroHeborisCount[player];
			maroRankingTSpin[i]   = maroTSpinCount[player];
			maroRankingTime[i]    = gameTimer[player];
			
			GetDateAndTime(&timebuf);
			maroRankingYear[i]    = timebuf[0];
			maroRankingMonth[i]   = timebuf[1];
			maroRankingDay[i]     = timebuf[2];
			maroRankingHour[i]    = timebuf[4];
			maroRankingMinute[i]  = timebuf[5];
			maroRankingSecond[i]  = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �����L���O�\��
void maroViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "MARATHON-ONI MODE RANKING", 6);
		printFontGrid(1, 3, "RANK SCORE    LINES LEVEL TIME", 4);
		
		for(i = 0; i < 10; i++) {
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", maroRankingScore[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", maroRankingLines[i]);
			printFontGrid(15, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", maroRankingLevel[i] + 1);
			printFontGrid(21, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(maroRankingTime[i]);
			printFontGrid(27, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// �w�{���X�񐔂�T-SPIN��
			sprintf(string[0], "TOTAL HEBORIS:%d", maroRankingHeboris[cursor]);
			printFontGrid(1, 24, string[0], 0);
			sprintf(string[0], "TOTAL T-SPIN :%d", maroRankingTSpin[cursor]);
			printFontGrid(1, 25, string[0], 0);
			
			// ���t�Ǝ���
			sprintf(string[0],
			        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
			        maroRankingYear[cursor], maroRankingMonth[cursor], maroRankingDay[cursor],
			        maroRankingHour[cursor], maroRankingMinute[cursor], maroRankingSecond[cursor]);
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
				maroInitRanking();
				maroSaveRanking(player);
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
