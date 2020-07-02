//������������������������������������������������������������������������������
//   ���v���C�f�[�^���Z�[�u
//������������������������������������������������������������������������������
void saveReplayData(int player, int number) {
	int i, j, temp, max, strbuf[8], timebuf[8];
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �t�@�C���t�H�[�}�b�g (4byte�P��)
	//    0�`      3 �w�b�_
	//    4          �t�@�C���T�C�Y
	//    5�`    179 �l�N�X�g�u���b�N
	//  180�`    187 �g�p�������[���̖��O
	//  188�`    195 �g�p�������[�h�̖��O
	//  196�`    199 �g�p�����o�[�W����
	//  200�`    399 �Q�[���̐ݒ�Ȃ�
	//  400�`    899 ���[���v���O�C�������R�Ɏg����G���A
	//  900�`   1399 ���[�h�v���O�C�������R�Ɏg����G���A
	// 1400�` 109400 ���v���C�f�[�^
	
	// �w�b�_
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x4C504552;
	saveBuf[3] = 0x31765941;
	
	// NEXT�u���b�N
	for(i = 0; i < 175; i++) {
		temp = 0;
		for(j = 0; j < 8; j++) {
			temp = temp | (nextb[(i << 3) + j + player * 1400] << (j * 4));
		}
		saveBuf[i + 5] = temp;
	}
	
	// �g�p�������[���̖��O
	for(i = 0; i < 8; i++) strbuf[i] = 0;
	StrCpy(&strbuf, plugin_name_rule[rots[player]]);
	for(i = 0; i < 8; i++) saveBuf[180 + i] = strbuf[i];
	
	// �g�p�������[�h�̖��O
	for(i = 0; i < 8; i++) strbuf[i] = 0;
	StrCpy(&strbuf, plugin_name_mode[gameMode[player]]);
	for(i = 0; i < 8; i++) saveBuf[188 + i] = strbuf[i];
	
	// �g�p�����o�[�W����
	saveBuf[196] = versionNo;
	saveBuf[197] = engineVer;
	
	// �Q�[���̐ݒ�Ȃ�
	saveBuf[200] = recTimer[player];		// ���v���C�̎���
	saveBuf[201] = gameTimer[player];		// �Q�[�����̎���
	saveBuf[202] = firstseed[player];		// �����V�[�h
	saveBuf[203] = nanameallow;				// �΂ߓ��͖�����
	saveBuf[204] = dispnext;				// NEXT�̐�
	saveBuf[205] = downtype;				// �A������ꉺ���ꐧ���̎��
	saveBuf[206] = spawn_y_type;			// �u���b�N�̏o���ʒu
	saveBuf[207] = kicktype[player];		// �ǏR��^�C�v
	saveBuf[208] = lockreset[player];		// �Œ莞�ԃ��Z�b�g
	saveBuf[209] = rotlimit[player];		// ��]������
	saveBuf[210] = movelimit[player];		// �ړ�������
	saveBuf[211] = blockgraphics[player];	// �u���b�N�̃O���t�B�b�N
	saveBuf[212] = are[player];				// ARE�̗L��
	saveBuf[213] = lock_up[player];			// ����ꑦ�Œ�
	saveBuf[214] = lock_down[player];		// �����ꑦ�Œ�
	saveBuf[215] = rot_reverse[player];		// ��]�����t�]
	saveBuf[216] = softspeed[player];		// ������X�s�[�h
	saveBuf[217] = max_waitt[player];		// �ō�������
	saveBuf[218] = fastlrmove[player];		// ��s���ړ�
	saveBuf[219] = oblk_bg[player];			// []�̎��̔w�i
	saveBuf[220] = mps[player * 2];			// �X�^�[�g���̓��͕���
	saveBuf[221] = mps[player * 2 + 1];		// �X�^�[�g���̉�����
	for(i = 0; i < 7; i++) saveBuf[222 + i] = blockcolor[player * 7 + i];	// �u���b�N�̐F
	saveBuf[229] = initial_rotate[player];	// ��s��]
	saveBuf[230] = initial_hold[player];	// ��s�z�[���h
	saveBuf[231] = enable_wallkick[player];	// �ǏR��
	saveBuf[232] = self_lock_sound[player];	// �����ŌŒ肳�����Ƃ��ɉ����o��
	saveBuf[233] = lockflash[player];		// �u���b�N���Œ肳�����u�ԁA�u���b�N������t���[����
	saveBuf[234] = disable180;				// E�{�^�����t��]�{�^���ɂ���
	
	// �쐬�������L�^
	GetDateAndTime(&timebuf);
	for(i = 0; i < 8; i++) saveBuf[235 + i] = timebuf[i];
	
	saveBuf[243] = disable_hold;			// HOLD������
	saveBuf[244] = RepeatDelay[player];		// RepeatDelay
	
	// �v���O�C�����Ăяo��
	executePlugin(player, 39, &dummy);
	
	// ����f�[�^��ۑ�
	max = recTimer[player];
	if(max > 60 * 60 * 30) max = 60 * 60 * 30;
	for(i = 0; i < max; i++) saveBuf[1400 + i] = replayData[player * 108000 + i];
	
	// �t�@�C���T�C�Y��ۑ�
	saveBuf[4] = (max + 1400) * 4;
	
	// �t�@�C���ɏ�������
	if(player == 0) sprintf(string[0], "replay/REPLAY%02d.SAV", number + 1);
	else sprintf(string[0], "replay/REPLAY%02d_2P.SAV", number + 1);
	SaveFile(string[0], &saveBuf, saveBuf[4]);
}

//������������������������������������������������������������������������������
//   ���v���C�f�[�^�����[�h
//������������������������������������������������������������������������������
int loadReplayData(int player, int number) {
	int i, j, temp, max, strbuf[8];
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_�����ǂݍ���
	if(player == 0) sprintf(string[0], "replay/REPLAY%02d.SAV", number + 1);
	else sprintf(string[0], "replay/REPLAY%02d_2P.SAV", number + 1);
	LoadFile(string[0], &saveBuf, 5 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x4C504552) return 0;
	if(saveBuf[3] != 0x31765941) return 0;
	
	// �S���ǂݍ���
	LoadFile(string[0], &saveBuf, saveBuf[4]);
	
	// �g�p�������[���̖��O
	for(i = 0; i < 8; i++) strbuf[i] = saveBuf[180 + i];
	StrCpy(string[1], &strbuf);
	temp = findRulePlugin(string[1]);
	rots[player] = temp;
	
	// �g�p�������[�h�̖��O
	for(i = 0; i < 8; i++) strbuf[i] = saveBuf[188 + i];
	StrCpy(string[2], &strbuf);
	temp = findModePlugin(string[2]);
	gameMode[player] = temp;
	
	sprintf(string[0], "player:%d rule:%s(%d) mode:%s(%d)", player, string[1], rots[player], string[2], gameMode[player]);
	debugLogSystem(string[0]);
	
	// ������
	playerInitial(player);
	
	// NEXT�u���b�N
	for(i = 0; i < 175; i++) {
		for(j = 0; j < 8; j++) {
			nextb[(i << 3) + j + player * 1400] = ((saveBuf[5 + i]) >> (j * 4)) & 15;
		}
	}
	setNextBlockColor(player, 1);
	
	// �g�p�����o�[�W����
	engineVer = saveBuf[197];
	
	// �Q�[���̐ݒ�Ȃ�
	firstseed[player] = saveBuf[202];		// �����V�[�h
	randseed[player] = firstseed[player];	// �����V�[�h
	nanameallow = saveBuf[203];				// �΂ߓ��͖�����
	dispnext = saveBuf[204];				// NEXT�̐�
	downtype = saveBuf[205];				// �A������ꉺ���ꐧ���̎��
	spawn_y_type = saveBuf[206];			// �u���b�N�̏o���ʒu
	kicktype[player] = saveBuf[207];		// �ǏR��^�C�v
	lockreset[player] = saveBuf[208];		// �Œ莞�ԃ��Z�b�g
	rotlimit[player] = saveBuf[209];		// ��]������
	movelimit[player] = saveBuf[210];		// �ړ�������
	blockgraphics[player] = saveBuf[211];	// �u���b�N�̃O���t�B�b�N
	are[player] = saveBuf[212];				// ARE�̗L��
	lock_up[player] = saveBuf[213];			// ����ꑦ�Œ�
	lock_down[player] = saveBuf[214];		// �����ꑦ�Œ�
	rot_reverse[player] = saveBuf[215];		// ��]�����t�]
	softspeed[player] = saveBuf[216];		// ������X�s�[�h
	max_waitt[player] = saveBuf[217];		// �ō�������
	fastlrmove[player] = saveBuf[218];		// ��s���ړ�
	oblk_bg[player] = saveBuf[219];			// []�̎��̔w�i
	mps[player * 2] = saveBuf[220];			// �X�^�[�g���̓��͕���
	mps[player * 2 + 1] = saveBuf[221];		// �X�^�[�g���̉�����
	if(engineVer >= 1) {
		// �u���b�N�̐F
		for(i = 0; i < 7; i++) blockcolor[player * 7 + i] = saveBuf[222 + i];
	}
	if(engineVer >= 3) {
		initial_rotate[player] = saveBuf[229];	// ��s��]
		initial_hold[player] = saveBuf[230];	// ��s�z�[���h
		enable_wallkick[player] = saveBuf[231];	// �ǏR��
	}
	self_lock_sound[player] = saveBuf[232];	// �����ŌŒ肳�����Ƃ��ɉ����o��
	
	if(engineVer >= 5) {
		lockflash[player] = saveBuf[233];	// �u���b�N���Œ肳�����u�ԁA�u���b�N������t���[����
	}
	disable180 = saveBuf[234];				// E�{�^�����t��]�{�^���ɂ���
	
	disable_hold = saveBuf[243];			// HOLD������
	if(disable_hold) dhold[player] = 2;
	else dhold[player] = 0;
	
	RepeatDelay[player] = saveBuf[244];		// RepeatDelay
	
	// ����f�[�^��ǂݍ���
	max = saveBuf[200];
	if(max > 60 * 60 * 30) max = 60 * 60 * 30;
	
	for(i = 0; i < max; i++) replayData[player * 108000 + i] = saveBuf[1400 + i];
	
	// �v���O�C�����Ăяo��
	executePlugin(player, 40, &dummy);
	
	return 1;
}

//������������������������������������������������������������������������������
//   ���v���C�����݂��邩�ǂ�������
//������������������������������������������������������������������������������
int isReplayExist(int number) {
	int i, strbuf[8];
	
	FillMemory(&saveBuf, 4 * 4, 0);
	
	// �w�b�_�����ǂݍ���
	sprintf(string[0], "replay/REPLAY%02d.SAV", number + 1);
	LoadFile(string[0], &saveBuf, 4 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x4C504552) return 0;
	if(saveBuf[3] != 0x31765941) return 0;
	
	// �ꕔ�ǂݍ���
	LoadFile(string[0], &saveBuf, 400 * 4);
	
	// �g�p�������[���̖��O
	for(i = 0; i < 8; i++) strbuf[i] = saveBuf[180 + i];
	StrCpy(replay_plugin_name_rule[number], &strbuf);
	
	// �g�p�������[�h�̖��O
	for(i = 0; i < 8; i++) strbuf[i] = saveBuf[188 + i];
	StrCpy(replay_plugin_name_mode[number], &strbuf);
	
	// �^�C��
	replay_timer[number] = saveBuf[201];
	
	// �Ή�����v���O�C�����Ȃ�
	if(findRulePlugin(replay_plugin_name_rule[number]) == -1) return -1;
	if(findModePlugin(replay_plugin_name_mode[number]) == -1) return -1;
	
	// ����
	return 1;
}

// �S�Ẵ��v���C�̑��݂��`�F�b�N
int checkAllReplayExist() {
	int i, temp, result;
	result = 0;
	
	for(i = 0; i < 40; i++) {
		temp = isReplayExist(i);
		replayexist[i] = temp;
		if(temp != 0) result++;
	}
	
	return result;
}

//������������������������������������������������������������������������������
//   ���v���C��ݒ肾���ǂݍ��݁i�ϐ��ɑ���͂��Ȃ��j
//������������������������������������������������������������������������������
int loadReplayHeader(int number) {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_�����ǂݍ���
	sprintf(string[0], "replay/REPLAY%02d.SAV", number + 1);
	LoadFile(string[0], &saveBuf, 5 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x4C504552) return 0;
	if(saveBuf[3] != 0x31765941) return 0;
	
	// �ݒ��S�ēǂݍ���
	LoadFile(string[0], &saveBuf, 1400 * 4);
	
	return 1;
}

//������������������������������������������������������������������������������
//   ���v���C�I�����
//������������������������������������������������������������������������������
int selectReplay() {
	int total, dcursor, temp;
	
	// ���v���C�����݂��邩�ǂ����`�F�b�N
	total = checkAllReplayExist();
	
	// �����J�[�\���ʒu�ݒ�
	dcursor = 0;
	if(total) {
		while(!replayexist[dcursor]) {
			dcursor++;
			if(dcursor >= 40) dcursor = 0;
		}
	}
	
	// �I����ʂ�
	temp = selectReplayScreen(total, dcursor);
	StopAllBGM();
	
	if(temp >= 0) {
		// �Đ�
		saveGeneralConfigData();
		
		playback = 1;
		replayauto = 1;
		demo = 0;
		
		gameAllInit();
		
		loadReplayData(0, temp);
		stat[0] = 3;
		setNextBlockColor(0, 1);
		
		if(maxPlay) {
			loadReplayData(1, temp);
			stat[1] = 3;
			setNextBlockColor(1, 1);
		}
		
		return 1;
	} else {
		// �L�����Z��
		return 0;
	}
}

// ���v���C�I����ʃ��C������
int selectReplayScreen(int total, int dcursor) {
	int i, j, start, end, color, cursor, temp1, temp2;
	cursor = dcursor;
	
	// BGM�Đ�
	if(enable_sysbgm) {
		bgmlv = 12;
		PlayBGM();
	}
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		if(!total) {
			// ���v���C�f�[�^���Ȃ�
			printFontGrid(13, 14, "NO REPLAY DATA", 2);
			
			if(getPushState(0, 5)) {
				return -1;
			}
			goto skip;
		}
		
		printFontGrid(9, 2, "- SELECT REPLAY DATA -", 4);
		printFontGrid(6, 3, "PRESS C BUTTON TO VIEW DETAIL", 5);
		
		// ���v���C�ꗗ�̕\��
		j = 0;
		if(cursor >= 20) {
			start = 20;
			end = 40;
			printFontGrid(8, 27, "PAGE 2 (NO.21 - NO.40)", 1);
		} else {
			start = 0;
			end = 20;
			printFontGrid(8, 27, "PAGE 1 (NO.01 - NO.20)", 1);
		}
		
		for(i = start; i < end; i++) {
			// �J�[�\���F�ݒ�
			if(replayexist[i] == 1)
				color = (i == cursor) * (count % 4 / 2) * 7;
			else
				color = (i == cursor) * 8;
			
			// �t�@�C���i���o�[
			sprintf(string[0], "%02d", i + 1);
			printFontGrid(1, 5 + j, string[0], color);
			
			if(replayexist[i]) {
				// ���[�h��
				printFontGrid(4, 5 + j, replay_plugin_name_mode[i], color);
				// ���[����
				printFontGrid(24, 5 + j, replay_plugin_name_rule[i], color);
				// �^�C��
				getTime(replay_timer[i]);
				printFontGrid(31, 5 + j, string[0], color);
			}
			
			j++;
		}
		
		// �J�[�\���ړ�
		padRepeat2(0);
		
		// ��
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if(getPressState(0, 0)) {
			PlaySE(se_move);
			
			do {
				cursor--;
				if(cursor < 0) cursor = 39;
			} while(!replayexist[cursor]);
		}
		
		// ��
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if(getPressState(0, 1)) {
			PlaySE(se_move);
			
			do {
				cursor++;
				if(cursor > 39) cursor = 0;
			} while(!replayexist[cursor]);
		}
		
		// �L�����Z��
		if(getPushState(0, 5)) {
			return -1;
		}
		
		// �ڍ׉��
		if(getPushState(0, 6)) {
			temp1 = findRulePlugin(replay_plugin_name_rule[cursor]);
			temp2 = findModePlugin(replay_plugin_name_mode[cursor]);
			
			if(temp1 == -1) rots[0] = -2;
			else rots[0] = temp1;
			if(temp2 == -1) gameMode[0] = -2;
			else gameMode[0] = temp2;
			
			replayDetail(cursor);
		}
		
		// ����
		if(getPushState(0, 4)) {
			temp1 = findRulePlugin(replay_plugin_name_rule[cursor]);
			temp2 = findModePlugin(replay_plugin_name_mode[cursor]);
			
			if((temp1 != -1) && (temp2 != -1)) {
				PlayWave(se_kettei);
				rots[0] = temp1;
				gameMode[0] = temp2;
				
				if(!english) sprintf(string[0], "���[�� %s ���[�h %s �Ń��v���C�Đ��J�n", plugin_name_rule[rots[0]], plugin_name_mode[gameMode[0]]);
				else sprintf(string[0], "Replay start (Rule:%s Mode:%s)", plugin_name_rule[rots[0]], plugin_name_mode[gameMode[0]]);
				debugLogSystem(string[0]);
				
				return cursor;
			}
		}
		
		skip:
	}
}

// ���v���C�ڍ�
void replayDetail(int number) {
	int page, color;
	page = 0;
	loadReplayHeader(number);
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		sprintf(string[0], "REPLAY DETAIL (PAGE %d/3)", page + 1);
		printFontGrid(1, 1, string[0], 4);
		
		printFontGrid(1, 28, "kn: PAGE CHANGE / A: PLAY / B: CANCEL", 7);
		
		if(page == 0) {
			printFontGrid(1, 3, "REPLAY NUMBER", 0);
			sprintf(string[0], "%02d", number + 1);
			printFontGrid(22, 3, string[0], 0);
			
			printFontGrid(1, 5, "HEBORIS VERSION", 0);
			sprintf(string[0], "%d", saveBuf[196]);
			printFontGrid(22, 5, string[0], 0);
			
			printFontGrid(1, 6, "ENGINE VERSION", 0);
			sprintf(string[0], "%d", saveBuf[197]);
			printFontGrid(22, 6, string[0], 0);
			
			printFontGrid(1, 8, "PLAY TIME", 0);
			getTime(saveBuf[201]);
			printFontGrid(22, 8, string[0], 0);
			
			printFontGrid(1, 10, "8WAY INPUT", 0);
			if(!saveBuf[203]) sprintf(string[0], "ON");
			else sprintf(string[0], "OFF");
			printFontGrid(22, 10, string[0], 0);
			
			printFontGrid(1, 11, "NEXT DISPLAY", 0);
			sprintf(string[0], "%d", saveBuf[204]);
			printFontGrid(22, 11, string[0], 0);
			
			printFontGrid(1, 12, "DROP LIMIT", 0);
			if(saveBuf[205] == 0) sprintf(string[0], "OFF");
			else if(saveBuf[205] == 1) sprintf(string[0], "20G ONLY");
			else sprintf(string[0], "ON");
			printFontGrid(22, 12, string[0], 0);
			
			printFontGrid(1, 13, "SPAWN Y TYPE", 0);
			if(!saveBuf[206]) sprintf(string[0], "UNDER THE FRAME");
			else sprintf(string[0], "ABOVE THE FRAME");
			printFontGrid(22, 13, string[0], 0);
			
			printFontGrid(1, 14, "E BUTTON", 0);
			if(!saveBuf[234]) sprintf(string[0], "180 ROTATE");
			else sprintf(string[0], "REVERSE ROTATE");
			printFontGrid(22, 14, string[0], 0);
			
			printFontGrid(1, 15, "HOLD", 0);
			if(!saveBuf[243]) sprintf(string[0], "ON");
			else sprintf(string[0], "OFF");
			printFontGrid(22, 15, string[0], 0);
			
			if(saveBuf[235] != 0) {
				printFontGrid(1, 17, "DATE", 0);
				sprintf(string[0], "%04d/%02d/%02d", saveBuf[235], saveBuf[236], saveBuf[237]);
				printFontGrid(22, 17, string[0], 0);
				
				printFontGrid(1, 18, "TIME", 0);
				sprintf(string[0], "%02d:%02d:%02d", saveBuf[239], saveBuf[240], saveBuf[241]);
				printFontGrid(22, 18, string[0], 0);
			}
		} else if(page == 1) {
			color = 0;
			if(rots[0] == -2) color = 8;
			printFontGrid(1, 3, "RULE", 0);
			printFontGrid(22, 3, replay_plugin_name_rule[number], color);
			executePlugin(0, 54, &number);
		} else {
			color = 0;
			if(gameMode[0] == -2) color = 8;
			printFontGrid(1, 3, "MODE", 0);
			printFontGrid(22, 3, replay_plugin_name_mode[number], color);
			executePlugin(0, 55, &number);
		}
		
		// ��
		if(getPushState(0, 0)) {
			PlaySE(se_move);
			page--;
			if(page < 0) page = 2;
		}
		
		// ��
		if(getPushState(0, 1)) {
			PlaySE(se_move);
			page++;
			if(page > 2) page = 0;
		}
		
		// A��B�Ŗ߂�
		if(getPushState(0, 4) || getPushState(0, 5)) {
			return;
		}
	}
}
