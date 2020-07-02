//SIMPLE-40LINES
//prefix:simpf

// �ϐ�
int simpfVersion;			// �o�[�W�����ԍ�
int simpfCVersion = 2;		// ���݂̃o�[�W����

int simpfModeNo = -1;		// ���[�h�ԍ�
int simpfLines[2];			// ���C��

int simpfSpeed = 1;			// �������x
int simpfSpType = 0;		// �X�s�[�h�^�C�v
int simpfWait1 = 25;		// ARE
int simpfWait2 = 25;		// ���C�������҂�����
int simpfWait3 = 30;		// �u���b�N���Œ肳���܂ł̗P�\����
int simpfWaitt = 16;		// DAS
int simpfIsBig = 0;			// BIG���ǂ���
int simpfBigMove = 1;		// BIG���̉��ړ��P��
int simpfBgm = 0;			// �g�p����BGM
int simpfGhost = 1;			// �S�[�X�g�̐ݒ�
int simpfWait4 = -1;		// �u���b�N���Œ肳���܂ł̗P�\���ԁi�i�����痎����j
int simpfWait5 = -1;		// ���C���������ARE

int simpfPreset[20 * 10];	// �v���Z�b�g
int simpfLastPresetNo = 0;	// �Ō�ɑI�������v���Z�b�g�ԍ�

// �����L���O�p�ϐ�
int simpfRankingTime[10];	// �N���A�^�C��
int simpfRankingSpeed[10];	// �������x
int simpfRankingSpType[10];	// �X�s�[�h�^�C�v
int simpfRankingWait1[10];	// ARE
int simpfRankingWait2[10];	// ���C�������҂�����
int simpfRankingWait3[10];	// �u���b�N���Œ肳���܂ł̗P�\����
int simpfRankingWaitt[10];	// DAS
int simpfRankingYear[10];	// �����N�C�������i�N�j
int simpfRankingMonth[10];	// �����N�C�������i���j
int simpfRankingDay[10];	// �����N�C�������i���j
int simpfRankingHour[10];	// �����N�C�������i���j
int simpfRankingMinute[10];	// �����N�C�������i���j
int simpfRankingSecond[10];	// �����N�C�������i�b�j
int simpfRankingWait4[10];	// �u���b�N���Œ肳���܂ł̗P�\���ԁi�i�����痎����j
int simpfRankingWait5[10];	// ���C���������ARE

// �C�x���g����
void simpfPluginEvent(int player, int event, int *param) {
	int i;
	
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != simpfModeNo)) return;
	
	if(event == 0) {
		simpfModeNo = addModePlugin("SIMPLE-40LINES");	// ���[�h��o�^����
	} else if(event == 12) {
		simpfCalcScore(player, param[0]);	// �X�R�A�v�Z
	} else if(event == 15) {
		simpfViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		simpfSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		simpfPlayerInitial(player);	// ������
	} else if(event == 21) {
		simpfResult(player);	// ���ʕ\��
	} else if(event == 24) {
		onRecord[player] = 0;	// �G���f�B���O�˓�
		ending[player] = 3;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		param[0] = 5;	// EXCELLENT��ʂ��ȗ�
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		simpfSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		simpfLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		simpfLoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		simpfReplayDetail();	// ���v���C�ڍ�
	}
}

// ������
void simpfPlayerInitial(int player) {
	// �o�[�W����
	if(!playback) simpfVersion = simpfCVersion;
	
	// ���C������������
	simpfLines[player] = 0;
	
	// �g�̐F��ς���
	framecolor[player] = 3;
	
	// �ݒ�𔽉f������
	sp[player] = simpfSpeed;
	speedtype[player] = simpfSpType;
	wait1[player] = simpfWait1;
	wait2[player] = simpfWait2;
	wait3[player] = simpfWait3;
	waitt[player] = simpfWaitt;
	IsBig[player] = simpfIsBig;
	BigMove[player] = simpfBigMove;
	bgmlv = simpfBgm;
	if(simpfGhost == 0) ghost[player] = 0;
	
	if(simpfVersion >= 1) wait4[player] = simpfWait4;
	else wait4[player] = -1;
	
	if(simpfVersion >= 2) wait5[player] = simpfWait5;
	else wait5[player] = -1;
}

// �X�R�A�v�Z
void simpfCalcScore(int player, int lines) {
	// ���C��������
	simpfLines[player] = simpfLines[player] + lines;
	
	// �N���A
	if(simpfLines[player] >= 40) {
		ending[player] = 1;
		timeOn[player] = 0;
	}
}

// �X�R�A�\��
void simpfViewScore(int player) {
	int temp, color;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// �c�胉�C��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "LINES");
	if(simpfLines[player] > 40) sprintf(string[0], "%d", 0);
	else sprintf(string[0], "%d", 40 - simpfLines[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// �x�X�g�^�C��
	if(!playback) {
		printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "BEST TIME");
		getTime(simpfRankingTime[0]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	}
	
	// �X�s�[�h
	printTinyFont(foffset[player] + 96, fyoffset[player] + 153, "SPEED");
	sprintf(string[0], "%d", simpfSpeed);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 161, string[0], color);
	
	sprintf(string[0], "TYPE %d", simpfSpType + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 171, string[0], color);
	
	// wait�l
	ExBltRect(sg_smallfont, foffset[player] + 96, fyoffset[player] + 181, 68, 14, 24, 7);	// WAITS
	sprintf(string[0], "%2d %2d\n%2d %2d", simpfWait1, simpfWait2, simpfWait3, simpfWaitt);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 189, string[0], color);
	
	if(wait4[player] != -1) {
		sprintf(string[0], "%2d", simpfWait4);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 207, string[0], color);
	}
	
	if(wait5[player] != -1) {
		sprintf(string[0], "%2d", simpfWait5);
		printSMALLFont(foffset[player] + 114, fyoffset[player] + 207, string[0], color);
	}
	
	// BLOCK/SEC
	printTinyFont(foffset[player] + 96, fyoffset[player] + 76, "BLOCK/SEC");
	if(gameTimer[player] > 0) {
		temp = (bdowncnt[player] * 10000 * 60) / gameTimer[player];
	} else {
		temp = 0;
	}
	sprintf(string[0], "%d.%04d", temp / 10000, temp % 10000);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 84, string[0], color);
	
	// LINES/MIN
	printTinyFont(foffset[player] + 96, fyoffset[player] + 94, "LINES/MIN");
	if(gameTimer[player] > 0) {
		temp = (simpfLines[player] * 100 * 3600) / gameTimer[player];
	} else {
		temp = 0;
	}
	sprintf(string[0], "%d.%02d", temp / 100, temp % 100);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 102, string[0], color);
	
	// ����
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
}

// ���ʕ\��
void simpfResult(int player) {
	// �����L���O�o�^
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = simpfRegistRanking(player);
		if(statc[player * 10 + 1] != -1) simpfSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", simpfLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "TIME");
	getTime(gameTimer[player]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[1], 0);
	
	if(statc[player * 10 + 1] != -1) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "RANK");
		sprintf(string[0], "%13d", statc[player * 10 + 1] + 1);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[0], 0);
	}
}

// BGM�ǂݍ���
void simpfLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(simpfBgm);
	}
}

// �ݒ���
void simpfSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(simpfLoadConfig() == 0) simpfMakeDefaultPreset();
	
	// �����L���O��ǂݍ���
	if(simpfLoadRanking(player) == 0) simpfInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "SIMPLE-40LINES OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2,  3, "SPEED",         7 * (cursor ==  0));
		printFontGrid(2,  4, "SPEED TYPE",    7 * (cursor ==  1));
		if(!english) {
			printFontGrid(2,  5, "SYUTUGEN",  7 * (cursor ==  2));
			printFontGrid(2,  6, "SYOUKYO",   7 * (cursor ==  3));
			printFontGrid(2,  7, "SETTYAKU",  7 * (cursor ==  4));
			printFontGrid(2,  8, "YOKOTAME",  7 * (cursor ==  5));
			printFontGrid(2,  9, "SETTYAKU2", 7 * (cursor ==  6));
			printFontGrid(2, 10, "SYUTUGEN2", 7 * (cursor ==  7));
		} else {
			printFontGrid(2,  5, "ARE",         7 * (cursor ==  2));
			printFontGrid(2,  6, "LINE DELAY",  7 * (cursor ==  3));
			printFontGrid(2,  7, "LOCK DELAY",  7 * (cursor ==  4));
			printFontGrid(2,  8, "DAS",         7 * (cursor ==  5));
			printFontGrid(2,  9, "LOCK DELAY2", 7 * (cursor ==  6));
			printFontGrid(2, 10, "ARE2",        7 * (cursor ==  7));
		}
		printFontGrid(2, 11, "BIG",           7 * (cursor ==  8));
		printFontGrid(2, 12, "BIG MOVE",      7 * (cursor ==  9));
		printFontGrid(2, 13, "BGM",           7 * (cursor == 10));
		printFontGrid(2, 14, "GHOST BLOCK",   7 * (cursor == 11));
		printFontGrid(2, 15, "[SAVE PRESET]", 7 * (cursor == 12));
		printFontGrid(2, 16, "[LOAD PRESET]", 7 * (cursor == 13));
		
		// �ݒ�l�\��
		sprintf(string[0], "%d", simpfSpeed);
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(simpfSpType == 0) sprintf(string[0], "1/60");
		else if(simpfSpType == 1) sprintf(string[0], "FRAMES PER ROW");
		else sprintf(string[0], "1/256");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "%d", simpfWait1);
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "%d", simpfWait2);
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		sprintf(string[0], "%d", simpfWait3);
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		sprintf(string[0], "%d", simpfWaitt);
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		if(simpfWait4 == -1) {
			if(!english) sprintf(string[0], "USE SETTYAKU");
			else sprintf(string[0], "USE LOCK DELAY");
		} else {
			sprintf(string[0], "%d", simpfWait4);
		}
		printFontGrid(22, 9, string[0], 7 * (cursor == 6));
		
		if(simpfWait5 == -1) {
			if(!english) sprintf(string[0], "USE SYUTUGEN");
			else sprintf(string[0], "USE ARE");
		} else {
			sprintf(string[0], "%d", simpfWait5);
		}
		printFontGrid(22, 10, string[0], 7 * (cursor == 7));
		
		if(!simpfIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 11, string[0], 7 * (cursor == 8));
		
		if(!simpfBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 12, string[0], 7 * (cursor == 9));
		
		sprintf(string[0], "%d", simpfBgm);
		printFontGrid(22, 13, string[0], 7 * (cursor == 10));
		
		if(!simpfGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 14, string[0], 7 * (cursor == 11));
		
		sprintf(string[0], "PRESET NO.%d", simpfLastPresetNo + 1);
		printFontGrid(22, 15, string[0], 7 * (cursor >= 12));
		
		// �J�[�\���ړ�
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 13;
			if(cursor > 13) cursor = 0;
		}
		
		// �l��ύX
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) {
				simpfSpeed = simpfSpeed + move;
				if(simpfSpeed < 0) simpfSpeed = 5120;
				if(simpfSpeed > 5120) simpfSpeed = 0;
			}
			if(cursor == 1) {
				simpfSpType = simpfSpType + move;
				if(simpfSpType < 0) simpfSpType = 2;
				if(simpfSpType > 2) simpfSpType = 0;
			}
			if(cursor == 2) {
				simpfWait1 = simpfWait1 + move;
				if(simpfWait1 < 0) simpfWait1 = 99;
				if(simpfWait1 > 99) simpfWait1 = 0;
			}
			if(cursor == 3) {
				simpfWait2 = simpfWait2 + move;
				if(simpfWait2 < 0) simpfWait2 = 99;
				if(simpfWait2 > 99) simpfWait2 = 0;
			}
			if(cursor == 4) {
				simpfWait3 = simpfWait3 + move;
				if(simpfWait3 < 0) simpfWait3 = 99;
				if(simpfWait3 > 99) simpfWait3 = 0;
			}
			if(cursor == 5) {
				simpfWaitt = simpfWaitt + move;
				if(simpfWaitt < 0) simpfWaitt = 99;
				if(simpfWaitt > 99) simpfWaitt = 0;
			}
			if(cursor == 6) {
				simpfWait4 = simpfWait4 + move;
				if(simpfWait4 < -1) simpfWait4 = 99;
				if(simpfWait4 > 99) simpfWait4 = -1;
			}
			if(cursor == 7) {
				simpfWait5 = simpfWait5 + move;
				if(simpfWait5 < -1) simpfWait5 = 99;
				if(simpfWait5 > 99) simpfWait5 = -1;
			}
			if(cursor == 8) simpfIsBig = !simpfIsBig;
			if(cursor == 9) simpfBigMove = !simpfBigMove;
			if(cursor == 10) {
				simpfBgm = simpfBgm + move;
				if(simpfBgm < 0) simpfBgm = 29;
				if(simpfBgm > 29) simpfBgm = 0;
			}
			if(cursor == 11) simpfGhost = !simpfGhost;
			if(cursor >= 12) {
				simpfLastPresetNo = simpfLastPresetNo + move;
				if(simpfLastPresetNo < 0) simpfLastPresetNo = 9;
				if(simpfLastPresetNo > 9) simpfLastPresetNo = 0;
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
			
			if(cursor == 12) {
				simpfSavePreset(simpfLastPresetNo);
				simpfSaveConfig();
			} else if(cursor == 13) {
				simpfLoadPreset(simpfLastPresetNo);
			} else {
				simpfSaveConfig();
				return;
			}
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			simpfViewRanking(player);
		}
	}
}

// �ݒ��ۑ�
void simpfSaveConfig() {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x504D4953;
	saveBuf[1] = 0x342D454C;
	saveBuf[2] = 0x4E494C30;
	saveBuf[3] = 0x32765345;
	
	// �ݒ���e
	saveBuf[4] = simpfSpeed;
	saveBuf[5] = simpfSpType;
	saveBuf[6] = simpfWait1;
	saveBuf[7] = simpfWait2;
	saveBuf[8] = simpfWait3;
	saveBuf[9] = simpfWaitt;
	saveBuf[10] = simpfIsBig;
	saveBuf[11] = simpfBigMove;
	saveBuf[12] = simpfBgm;
	saveBuf[13] = simpfGhost;
	saveBuf[14] = simpfWait4;
	saveBuf[15] = simpfWait5;
	
	saveBuf[99] = simpfLastPresetNo;
	for(i = 0; i < 20 * 10; i++) saveBuf[100 + i] = simpfPreset[i];
	
	SaveFile("config/SIMPLE_40LINES_CONFIG.SAV", &saveBuf, 300 * 4);
}

// �ݒ��ǂݍ���
int simpfLoadConfig() {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_�����ǂݍ���
	LoadFile("config/SIMPLE_40LINES_CONFIG.SAV", &saveBuf, 4 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x504D4953) return 0;
	if(saveBuf[1] != 0x342D454C) return 0;
	if(saveBuf[2] != 0x4E494C30) return 0;
	if(saveBuf[3] != 0x32765345) return 0;
	
	// �S���ǂݍ���
	LoadFile("config/SIMPLE_40LINES_CONFIG.SAV", &saveBuf, 300 * 4);
	
	// �ݒ���e
	simpfSpeed = saveBuf[4];
	simpfSpType = saveBuf[5];
	simpfWait1 = saveBuf[6];
	simpfWait2 = saveBuf[7];
	simpfWait3 = saveBuf[8];
	simpfWaitt = saveBuf[9];
	simpfIsBig = saveBuf[10];
	simpfBigMove = saveBuf[11];
	simpfBgm = saveBuf[12];
	simpfGhost = saveBuf[13];
	simpfWait4 = saveBuf[14];
	simpfWait5 = saveBuf[15];
	
	simpfLastPresetNo = saveBuf[99];
	for(i = 0; i < 20 * 10; i++) simpfPreset[i] = saveBuf[100 + i];
	
	return 1;
}

// �v���Z�b�g��������
void simpfMakeDefaultPreset() {
	int i;
	
	for(i = 0; i < 20 * 10; i++) simpfPreset[i] = 0;
}

// �v���Z�b�g��ۑ�
void simpfSavePreset(int number) {
	simpfPreset[number * 20 + 0]  = simpfSpeed;
	simpfPreset[number * 20 + 1]  = simpfSpType;
	simpfPreset[number * 20 + 2]  = simpfWait1;
	simpfPreset[number * 20 + 3]  = simpfWait2;
	simpfPreset[number * 20 + 4]  = simpfWait3;
	simpfPreset[number * 20 + 5]  = simpfWaitt;
	simpfPreset[number * 20 + 6]  = simpfIsBig;
	simpfPreset[number * 20 + 7]  = simpfBigMove;
	simpfPreset[number * 20 + 8]  = simpfBgm;
	simpfPreset[number * 20 + 9]  = simpfGhost;
	simpfPreset[number * 20 + 10] = simpfWait4;
	simpfPreset[number * 20 + 11] = simpfWait5;
}

// �v���Z�b�g��ǂݍ���
void simpfLoadPreset(int number) {
	simpfSpeed = simpfPreset[number * 20 + 0];
	simpfSpType = simpfPreset[number * 20 + 1];
	simpfWait1 = simpfPreset[number * 20 + 2];
	simpfWait2 = simpfPreset[number * 20 + 3];
	simpfWait3 = simpfPreset[number * 20 + 4];
	simpfWaitt = simpfPreset[number * 20 + 5];
	simpfIsBig = simpfPreset[number * 20 + 6];
	simpfBigMove = simpfPreset[number * 20 + 7];
	simpfBgm = simpfPreset[number * 20 + 8];
	simpfGhost = simpfPreset[number * 20 + 9];
	simpfWait4 = simpfPreset[number * 20 + 10];
	simpfWait5 = simpfPreset[number * 20 + 11];
}

// ���v���C�ۑ�
void simpfSaveReplay(int player) {
	saveBuf[900] = simpfLines[player];
	saveBuf[901] = simpfSpeed;
	saveBuf[902] = simpfSpType;
	saveBuf[903] = simpfWait1;
	saveBuf[904] = simpfWait2;
	saveBuf[905] = simpfWait3;
	saveBuf[906] = simpfWaitt;
	saveBuf[907] = simpfIsBig;
	saveBuf[908] = simpfBigMove;
	saveBuf[909] = simpfBgm;
	saveBuf[910] = simpfGhost;
	saveBuf[911] = simpfVersion;
	saveBuf[912] = simpfWait4;
	saveBuf[913] = simpfWait5;
}

// ���v���C�ǂݍ���
void simpfLoadReplay(int player) {
	simpfSpeed = saveBuf[901];
	simpfSpType = saveBuf[902];
	simpfWait1 = saveBuf[903];
	simpfWait2 = saveBuf[904];
	simpfWait3 = saveBuf[905];
	simpfWaitt = saveBuf[906];
	simpfIsBig = saveBuf[907];
	simpfBigMove = saveBuf[908];
	simpfBgm = saveBuf[909];
	simpfGhost = saveBuf[910];
	simpfVersion = saveBuf[911];
	simpfWait4 = saveBuf[912];
	simpfWait5 = saveBuf[913];
	
	// �ݒ�𔽉f������
	simpfPlayerInitial(player);
}

// ���v���C�ڍ�
void simpfReplayDetail() {
	printFontGrid(1, 4, "LINES", 0);
	sprintf(string[0], "%d", saveBuf[900]);
	printFontGrid(22, 4, string[0], 0);
	
	printFontGrid(1, 5, "SPEED", 0);
	sprintf(string[0], "%d", saveBuf[901]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "SPEED TYPE", 0);
	if(saveBuf[902] == 0) sprintf(string[0], "1/60");
	else if(saveBuf[902] == 1) sprintf(string[0], "FRAMES PER ROW");
	else sprintf(string[0], "1/256");
	printFontGrid(22, 6, string[0], 0);
	
	if(!english) printFontGrid(1, 7, "SYUTUGEN", 0);
	else printFontGrid(1, 7, "ARE", 0);
	sprintf(string[0], "%d", saveBuf[903]);
	printFontGrid(22, 7, string[0], 0);
	
	if(!english) printFontGrid(1, 8, "SYOUKYO", 0);
	else printFontGrid(1, 8, "LINE DELAY", 0);
	sprintf(string[0], "%d", saveBuf[904]);
	printFontGrid(22, 8, string[0], 0);
	
	if(!english) printFontGrid(1, 9, "SETTYAKU", 0);
	else printFontGrid(1, 9, "LOCK DELAY", 0);
	sprintf(string[0], "%d", saveBuf[905]);
	printFontGrid(22, 9, string[0], 0);
	
	if(!english) printFontGrid(1, 10, "YOKOTAME", 0);
	else printFontGrid(1, 10, "DAS", 0);
	sprintf(string[0], "%d", saveBuf[906]);
	printFontGrid(22, 10, string[0], 0);
	
	if(!english) printFontGrid(1, 11, "SETTYAKU2", 0);
	else printFontGrid(1, 11, "LOCK DELAY2", 0);
	if((saveBuf[912] == -1) || (saveBuf[911] <= 0)) {
		if(!english) sprintf(string[0], "USE SETTYAKU");
		else sprintf(string[0], "USE LOCK DELAY");
	} else {
		sprintf(string[0], "%d", saveBuf[912]);
	}
	printFontGrid(22, 11, string[0], 0);
	
	if(!english) printFontGrid(1, 12, "SYUTUGEN2", 0);
	else printFontGrid(1, 12, "ARE2", 0);
	if((saveBuf[913] == -1) || (saveBuf[911] <= 1)) {
		if(!english) sprintf(string[0], "USE SYUTUGEN");
		else sprintf(string[0], "USE ARE");
	} else {
		sprintf(string[0], "%d", saveBuf[913]);
	}
	printFontGrid(22, 12, string[0], 0);
	
	printFontGrid(1, 13, "BIG", 0);
	if(!saveBuf[907]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 13, string[0], 0);
	
	printFontGrid(1, 14, "BIG MOVE", 0);
	if(!saveBuf[908]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 14, string[0], 0);
	
	printFontGrid(1, 15, "BGM", 0);
	sprintf(string[0], "%d", saveBuf[909]);
	printFontGrid(22, 15, string[0], 0);
	
	printFontGrid(1, 16, "GHOST BLOCK", 0);
	if(!saveBuf[910]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 16, string[0], 0);
	
	printFontGrid(1, 17, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[911]);
	printFontGrid(22, 17, string[0], 0);
}

// �����L���O�ۑ�
void simpfSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0]  = simpfRankingTime[i];
		saveBuf[1 + (i * 20) + 1]  = simpfRankingSpeed[i];
		saveBuf[1 + (i * 20) + 2]  = simpfRankingSpType[i];
		saveBuf[1 + (i * 20) + 3]  = simpfRankingWait1[i];
		saveBuf[1 + (i * 20) + 4]  = simpfRankingWait2[i];
		saveBuf[1 + (i * 20) + 5]  = simpfRankingWait3[i];
		saveBuf[1 + (i * 20) + 6]  = simpfRankingWaitt[i];
		saveBuf[1 + (i * 20) + 7]  = simpfRankingYear[i];
		saveBuf[1 + (i * 20) + 8]  = simpfRankingMonth[i];
		saveBuf[1 + (i * 20) + 9]  = simpfRankingDay[i];
		saveBuf[1 + (i * 20) + 10] = simpfRankingHour[i];
		saveBuf[1 + (i * 20) + 11] = simpfRankingMinute[i];
		saveBuf[1 + (i * 20) + 12] = simpfRankingSecond[i];
		saveBuf[1 + (i * 20) + 13] = simpfRankingWait4[i];
		saveBuf[1 + (i * 20) + 14] = simpfRankingWait5[i];
	}
	
	sprintf(string[0], "config/SIMPLE_40LINES_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 221 * 4);
}

// �����L���O�ǂݍ���
int simpfLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/SIMPLE_40LINES_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 221 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		simpfRankingTime[i]   = saveBuf[1 + (i * 20) + 0];
		simpfRankingSpeed[i]  = saveBuf[1 + (i * 20) + 1];
		simpfRankingSpType[i] = saveBuf[1 + (i * 20) + 2];
		simpfRankingWait1[i]  = saveBuf[1 + (i * 20) + 3];
		simpfRankingWait2[i]  = saveBuf[1 + (i * 20) + 4];
		simpfRankingWait3[i]  = saveBuf[1 + (i * 20) + 5];
		simpfRankingWaitt[i]  = saveBuf[1 + (i * 20) + 6];
		simpfRankingYear[i]   = saveBuf[1 + (i * 20) + 7];
		simpfRankingMonth[i]  = saveBuf[1 + (i * 20) + 8];
		simpfRankingDay[i]    = saveBuf[1 + (i * 20) + 9];
		simpfRankingHour[i]   = saveBuf[1 + (i * 20) + 10];
		simpfRankingMinute[i] = saveBuf[1 + (i * 20) + 11];
		simpfRankingSecond[i] = saveBuf[1 + (i * 20) + 12];
		simpfRankingWait4[i]  = saveBuf[1 + (i * 20) + 13];
		simpfRankingWait5[i]  = saveBuf[1 + (i * 20) + 14];
	}
	
	return 1;
}

// �����L���O������
void simpfInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		simpfRankingTime[i]   = 0;
		simpfRankingSpeed[i]  = 0;
		simpfRankingSpType[i] = 0;
		simpfRankingWait1[i]  = 0;
		simpfRankingWait2[i]  = 0;
		simpfRankingWait3[i]  = 0;
		simpfRankingWaitt[i]  = 0;
		simpfRankingYear[i]   = 0;
		simpfRankingMonth[i]  = 0;
		simpfRankingDay[i]    = 0;
		simpfRankingHour[i]   = 0;
		simpfRankingMinute[i] = 0;
		simpfRankingSecond[i] = 0;
		simpfRankingWait4[i]  = 0;
		simpfRankingWait5[i]  = 0;
	}
}

// �����L���O�o�^
int simpfRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (!ending[player])) return -1;
	
	for(i = 0; i < 10; i++) {
		// �����N�C��
		if((gameTimer[player] < simpfRankingTime[i]) || (simpfRankingTime[i] == 0)) {
			// �����L���O�����炷
			for(j = 9; j > i; j--) {
				simpfRankingTime[j]   = simpfRankingTime[j - 1];
				simpfRankingSpeed[j]  = simpfRankingSpeed[j - 1];
				simpfRankingSpType[j] = simpfRankingSpType[j - 1];
				simpfRankingWait1[j]  = simpfRankingWait1[j - 1];
				simpfRankingWait2[j]  = simpfRankingWait2[j - 1];
				simpfRankingWait3[j]  = simpfRankingWait3[j - 1];
				simpfRankingWaitt[j]  = simpfRankingWaitt[j - 1];
				simpfRankingYear[j]   = simpfRankingYear[j - 1];
				simpfRankingMonth[j]  = simpfRankingMonth[j - 1];
				simpfRankingDay[j]    = simpfRankingDay[j - 1];
				simpfRankingHour[j]   = simpfRankingHour[j - 1];
				simpfRankingMinute[j] = simpfRankingMinute[j - 1];
				simpfRankingSecond[j] = simpfRankingSecond[j - 1];
				simpfRankingWait4[j]  = simpfRankingWait4[j - 1];
				simpfRankingWait5[j]  = simpfRankingWait5[j - 1];
			}
			
			// �V�����f�[�^��o�^
			simpfRankingTime[i]   = gameTimer[player];
			simpfRankingSpeed[i]  = simpfSpeed;
			simpfRankingSpType[i] = simpfSpType;
			simpfRankingWait1[i]  = simpfWait1;
			simpfRankingWait2[i]  = simpfWait2;
			simpfRankingWait3[i]  = simpfWait3;
			simpfRankingWaitt[i]  = simpfWaitt;
			
			GetDateAndTime(&timebuf);
			simpfRankingYear[i]   = timebuf[0];
			simpfRankingMonth[i]  = timebuf[1];
			simpfRankingDay[i]    = timebuf[2];
			simpfRankingHour[i]   = timebuf[4];
			simpfRankingMinute[i] = timebuf[5];
			simpfRankingSecond[i] = timebuf[6];
			
			simpfRankingWait4[i]  = simpfWait4;
			simpfRankingWait5[i]  = simpfWait5;
			
			return i;
		}
	}
	
	return -1;
}

// �����L���O�\��
void simpfViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "40LINES MODE RANKING", 6);
		printFontGrid(1, 3, "RANK TIME          DATE", 4);
		
		for(i = 0; i < 10; i++) {
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(simpfRankingTime[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%04d/%02d/%02d", simpfRankingYear[i], simpfRankingMonth[i], simpfRankingDay[i]);
			printFontGrid(20, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%02d:%02d:%02d", simpfRankingHour[i], simpfRankingMinute[i], simpfRankingSecond[i]);
			printFontGrid(31, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// �X�s�[�h�f�[�^
			sprintf(string[0], "SPEED:%d", simpfRankingSpeed[cursor]);
			printFontGrid(1, 24, string[0], 0);
			
			if(simpfRankingSpType[cursor] == 0) sprintf(string[0], "(1/60)");
			if(simpfRankingSpType[cursor] == 1) sprintf(string[0], "(FRAMES PER ROW)");
			if(simpfRankingSpType[cursor] == 2) sprintf(string[0], "(1/256)");
			printFontGrid(11, 24, string[0], 0);
			
			sprintf(string[0], "W1:%2d W2:%2d W3:%2d WT:%2d W4:%2d W5:%2d",
			        simpfRankingWait1[cursor], simpfRankingWait2[cursor], simpfRankingWait3[cursor], simpfRankingWaitt[cursor],
			        simpfRankingWait4[cursor], simpfRankingWait5[cursor]);
			printFontGrid(1, 25, string[0], 0);
			
			printFontGrid(1, 27, "A/B:EXIT F:ERASE ALL", 6);
			
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
				simpfInitRanking();
				simpfSaveRanking(player);
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
