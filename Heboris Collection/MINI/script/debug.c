// �f�o�b�O���j���[
void debugMenu(int ingame) {
	int cursor;
	
	if(!debug_enable) return;
	
	cursor = 0;
	
	loop {
		spriteTime();
		KeyInput();
		
		printFontGrid(1, 1, "DEBUG MENU", 4);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "SYSTEM LOG",    7 * (cursor == 0));
		printFontGrid(2, 4, "RULE LOG",      7 * (cursor == 1));
		printFontGrid(2, 5, "MODE LOG",      7 * (cursor == 2));
		printFontGrid(2, 6, "RULE DEBUG",    7 * (cursor == 3));
		printFontGrid(2, 7, "MODE DEBUG",    7 * (cursor == 4));
		printFontGrid(2, 8, "GRAPHICS VIEW", 7 * (cursor == 5));
		
		// �J�[�\���ړ�
		padRepeat2(0);
		
		// ��
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if(getPressState(0, 0)) {
			PlaySE(se_move);
			cursor--;
			if(cursor < 0) cursor = 5;
		}
		
		// ��
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if(getPressState(0, 1)) {
			PlaySE(se_move);
			cursor++;
			if(cursor > 5) cursor = 0;
		}
		
		// �L�����Z��
		if(getPushState(0, 5)) {
			return;
		}
		
		// ����
		if(getPushState(0, 4)) {
			PlaySE(se_kettei);
			
			if(cursor == 0) debugLogView(0);
			if(cursor == 1) debugLogView(1);
			if(cursor == 2) debugLogView(2);
			if((cursor == 3) && (ingame)) executePlugin(0, 66, &dummy);
			if((cursor == 4) && (ingame)) executePlugin(0, 67, &dummy);
			if(cursor == 5) debugGraphicsView();
		}
	}
}

// �f�o�b�O���O��\��
void debugLogView(int type) {
	int i, cnt, page;
	page = 0;
	cnt = 0;
	
	loop {
		spriteTime();
		KeyInput();
		
		sprintf(string[0], "%d/2", page + 1);
		printTinyFont(304, 233, string[0]);
		
		if(cnt == 0) {
			for(i = 0; i < 20; i++) {
				ExTextLayerOn(44 + i, 0, i * 12);
				ExTextSize(44 + i, 12);
				TextColor(44 + i, 255, 255, 255);
				TextBackColorDisable(44 + i);
				if(type == 0) TextOut(44 + i, debug_log_system[i + page * 20]);
				if(type == 1) TextOut(44 + i, debug_log_rule[i + page * 20]);
				if(type == 2) TextOut(44 + i, debug_log_mode[i + page * 20]);
			}
		}
		
		// �y�[�W�؂�ւ�
		if(getPushState(0, 0) || getPushState(0, 1)) {
			PlaySE(se_move);
			page = !page;
			cnt = -1;
		}
		
		// ����
		if(getPushState(0, 7)) {
			PlaySE(se_kachi);
			debugLogClear(type);
			cnt = -1;
		}
		
		// �߂�
		if(getPushState(0, 4) || getPushState(0, 5)) {
			for(i = 0; i < 20; i++) TextLayerOff(44 + i);
			return;
		}
		
		cnt++;
	}
}

// �f�o�b�O���O������
void debugLogClear(int type) {
	int i;
	
	if(!debug_enable) return;
	
	for(i = 0; i < 40; i++) {
		if(type == 0) StrCpy(debug_log_system[i], "");
		if(type == 1) StrCpy(debug_log_rule[i], "");
		if(type == 2) StrCpy(debug_log_mode[i], "");
	}
}

// �f�o�b�O���O���o�́i�V�X�e���j
void debugLogSystem(str *msg) {
	int i;
	
	// ErrorLog.txt�ɏo�́iygs2k�̃f�o�b�O���[�h���L���̏ꍇ�j
	sprintf(string[15], "[SYST]{%s}", msg);
	InnerLogMes(string[15]);
	
	if(!debug_enable) return;
	
	// ���O�����炷
	for(i = 39; i > 0; i--) StrCpy(debug_log_system[i], debug_log_system[i - 1]);
	
	// ���O��ǉ�
	StrCpy(debug_log_system[0], msg);
}

// �f�o�b�O���O���o�́i���[���j
void debugLogRule(str *msg) {
	int i;
	
	// ErrorLog.txt�ɏo�́iygs2k�̃f�o�b�O���[�h���L���̏ꍇ�j
	sprintf(string[15], "[RULE]{%s}", msg);
	InnerLogMes(string[15]);
	
	if(!debug_enable) return;
	
	// ���O�����炷
	for(i = 39; i > 0; i--) StrCpy(debug_log_rule[i], debug_log_rule[i - 1]);
	
	// ���O��ǉ�
	StrCpy(debug_log_rule[0], msg);
}

// �f�o�b�O���O���o�́i���[�h�j
void debugLogMode(str *msg) {
	int i;
	
	// ErrorLog.txt�ɏo�́iygs2k�̃f�o�b�O���[�h���L���̏ꍇ�j
	sprintf(string[15], "[MODE]{%s}", msg);
	InnerLogMes(string[15]);
	
	if(!debug_enable) return;
	
	// ���O�����炷
	for(i = 39; i > 0; i--) StrCpy(debug_log_mode[i], debug_log_mode[i - 1]);
	
	// ���O��ǉ�
	StrCpy(debug_log_mode[0], msg);
}

// �O���t�B�b�N�\��
void debugGraphicsView() {
	int i, no, hide;
	no = 0;
	hide = 0;
	
	loop {
		spriteTime();
		KeyInput();
		
		BltFast(no, 0, 0);
		
		if(!hide) {
			printFontGrid(1, 1, "GRAPHICS VIEW", 4);
			sprintf(string[0], "kn %d/%d", no, graphics_count - 1);
			printFontGrid(1, 2, string[0], 1);
			printFontGrid(1, 3, "C: HIDE MESSAGE", 5);
		}
		
		padRepeat2(0);
		
		// ��
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if(getPressState(0, 0)) {
			PlaySE(se_move);
			no--;
			if(no < 0) no = graphics_count - 1;
		}
		
		// ��
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if(getPressState(0, 1)) {
			PlaySE(se_move);
			no++;
			if(no > graphics_count - 1) no = 0;
		}
		
		// ������\��
		if(getPushState(0, 6)) {
			PlaySE(se_kachi);
			hide = !hide;
		}
		
		// �߂�
		if(getPushState(0, 4) || getPushState(0, 5)) {
			return;
		}
	}
}
