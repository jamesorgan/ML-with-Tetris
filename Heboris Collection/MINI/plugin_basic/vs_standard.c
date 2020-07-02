//VS-STANDARD
//prefix:vss

// �o�[�W����
int vssVersion;					// �o�[�W�����ԍ��i�Â����v���C�Đ��p�j
int vssCVersion = 4;			// ���݂̃o�[�W����

// �ϐ�
int vssModeNo = -1;				// ���[�h�ԍ�

int vssLines[2];				// ���C����
int vssTotalAttack[2];			// �G�ɑ���������オ��u���b�N�̐�

int vssGHole[2];				// ����オ��u���b�N�̌��̈ʒu

int vssTSpinFrame[2];			// T-SPIN�\���^�w�{���X�\���̎c�莞��
int vssTSpinLine[2];			// �Ō��T-SPIN���C�������^�w�{���X�����̎��
int vssComboFrame[2];			// �R���{���\���̎c�莞��
int vssB2BFrame[2];				// Back To Back�\���̎c�莞��
int vssAttackGet[2];				// ���������ז��u���b�N��
int vssAttackFrame[2];				// ���������ז��u���b�N���\���̎c�莞��

int vssCPUFlag[2] = {0, 1};		// CPU�����삷�邩�ǂ���
int vssCPUSpeed[2] = {0, 5};	// CPU�̒x��
int vssGhost = 1;				// �S�[�X�g�̐ݒ�
int vssTSpin = 3;				// T-SPIN�̎��
int vssEnableCombo = 1;			// �R���{�{�[�i�X�̗L��
int vssEnableB2B = 1;			// Back To Back�̗L���i0=�Ȃ� 1=�ʏ� 2=�w�{���X�̂� 3=T-SPIN�̂݁j

int vssSpeed = 1;				// �������x
int vssSpeedType = 0;			// �X�s�[�h�^�C�v
int vssWait1 = 25;				// ARE
int vssWait2 = 40;				// ���C������
int vssWait3 = 30;				// �Œ莞��
int vssWaitt = 16;				// ������
int vssWait4 = -1;				// �Œ莞�ԁi�ڒ���j
int vssWait5 = -1;				// ARE�i������j
int vssHoleShiftRate = 30;		// Hole change rate(%)
int vssSousai = 1;				// �ז��u���b�N���E

// �C�x���g����
void vssPluginEvent(int player, int event, int *param) {
	int i;
	
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != vssModeNo)) return;
	
	if(event == 0) {
		vssModeNo = addModePlugin("VS-STANDARD");	// ���[�h��o�^����
	} else if(event == 3) {
		if((player == 1) && (!playback)) vssNextInit(param);	// 1P��NEXT��2P�ɃR�s�[
	} else if(event == 4) {
		vssPlayerExecute(player);	// �Q�[�������O
	} else if(event == 12) {
		vssCalcScore(player, param[0]);	// ���C������
	} else if(event == 15) {
		vssViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		vssSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		vssPlayerInitial(player);	// ������
	} else if(event == 19) {
		vssMoveInit(player);	// �u���b�N�o��
	} else if(event == 20) {
		vssGameOver(player, param);	// �Q�[���I�[�o�[����
	} else if(event == 21) {
		vssResult(player, param);	// ���ʕ\��
	} else if(event == 22) {
		vssGameOver2(player, param);	// �Q�[���I�[�o�[�\��
	} else if(event == 38) {
		if(player == 0) PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		vssSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		vssLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		if(player == 0) vssLoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		vssReplayDetail();	// ���v���C�ڍ�
	} else if(event == 68) {
		vssWin(player);	// ����
	} else if(event == 69) {
		vssUpLineProc(player);	// ����オ��
	} else if(event == 70) {
		vssRetry(param);	// ���g���C
	}
}

// ������
void vssPlayerInitial(int player) {
	int i;
	
	debugLogMode("vssPlayerInitial executed");
	
	// �o�[�W����
	if(!playback) vssVersion = vssCVersion;
	
	backno = 20;	// �w�i�ύX
	setFieldPosition(player, 2);	// �t�B�[���h�ʒu�ݒ�
	bgmlv = 10;	// BGM�ԍ��ݒ�
	
	if(!player) {
		// 1P
		if(vssVersion <= 3) vssGHole[0] = GiziRand(0, 10);
		blkshadow_direction[0] = 1;
	} else {
		// 2P
		if(vssVersion <= 3) vssGHole[1] = vssGHole[0];
		blkshadow_direction[1] = 0;
		
		// ��������R�s�[
		randseed[1] = randseed[0];
		firstseed[1] = firstseed[0];
	}
	
	vssLines[player] = 0;
	vssTotalAttack[player] = 0;
	
	vssTSpinFrame[player] = 0;
	vssTSpinLine[player] = 0;
	vssComboFrame[player] = 0;
	vssB2BFrame[player] = 0;
	vssAttackGet[player] = 0;
	vssAttackFrame[player] = 0;
	
	cpu_flag[player] = vssCPUFlag[player];
	cpu_speed[player] = vssCPUSpeed[player];
	if(vssGhost == 0) ghost[player] = 0;
	else ghost[player] = 1;
	tspin_type[player] = vssTSpin;
	enable_combo[player] = vssEnableCombo;
	b_to_b_type[player] = vssEnableB2B;
	
	if(vssVersion >= 1) {
		sp[player] = vssSpeed;
		speedtype[player] = vssSpeedType;
		wait1[player] = vssWait1;
		wait2[player] = vssWait2;
		wait3[player] = vssWait3;
		waitt[player] = vssWaitt;
	}
	
	if(vssVersion >= 2) wait4[player] = vssWait4;
	else wait4[player] = -1;
	
	if(vssVersion >= 3) wait5[player] = vssWait5;
	else wait5[player] = -1;
	
	stat[player] = 3;
}

// 1P��NEXT��2P�ɃR�s�[
void vssNextInit(int *param) {
	int i;
	param[0] = 1;
	for(i = 0; i < 1400; i++) nextb[i + 1400] = nextb[i];
}

// �Q�[�������O
void vssPlayerExecute(int player) {
	// CPU�̑���
	if((onRecord[player]) && (timeOn[player]) && (stat[player] == 4) && (cpu_best_x[player] != -3) && (!playback) && (cpu_flag[player]))
		cpu_setCtrl(player);
}

// �u���b�N�o��
void vssMoveInit(int player) {
	// CPU�̒u���ꏊ�����߂�
	if(cpu_flag[player] && !playback) {
		if(!dhold[player]) {
			if(hold[player] == -1)
				cpu_setBestSpotWithHold(player, blk[player], getNextBlock(player, 0));
			else
				cpu_setBestSpotWithHold(player, blk[player], hold[player]);
		} else {
			cpu_setBestSpot(player, blk[player]);
		}
	}
}

// BGM�ǂݍ���
void vssLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(10);
	}
}

// ���C������
void vssCalcScore(int player, int lines) {
	int bo;
	
	// T-SPIN��
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		vssTSpinFrame[player] = 60;
		vssTSpinLine[player] = lines;
		
		if(lines == 1) bo = 2;	// T-SPIN Single
		if(lines == 2) bo = 4;	// T-SPIN Double
		if(lines == 3) bo = 6;	// T-SPIN Triple
	}
	// ���ʂ̃��C������
	else {
		if(lines == 1) bo = 0;
		if(lines == 2) bo = 1;
		if(lines == 3) bo = 2;
		if(lines == 4) {
			vssTSpinFrame[player] = 60;
			vssTSpinLine[player] = lines;
			bo = 4;
		}
	}
	
	// B2B�{�[�i�X�i+1�j
	if(b_to_b_count[player] >= 2) {
		bo = bo + 1;
		vssB2BFrame[player] = 60;
	} else {
		vssB2BFrame[player] = 0;
	}
	
	// �R���{�{�[�i�X
	if(combo[player] >= 2) {
		if(combo[player] >= 12) bo = bo + 5;
		else if(combo[player] >= 9) bo = bo + 4;
		else if(combo[player] >= 7) bo = bo + 3;
		else if(combo[player] >= 5) bo = bo + 2;
		else if(combo[player] >= 3) bo = bo + 1;
		
		vssComboFrame[player] = 60;
	}
	
	// �S�����{�[�i�X
	if(isBravo(player)) {
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		bo = bo * 2;
	}
	
	if((vssVersion <= 3) || (vssSousai)) {
		// ���E
		upLines[player] = upLines[player] - bo;
		
		// ����ɂ�����܃u���b�N�𑗂�
		if(upLines[player] < 0) {
			upLines[1 - player] = upLines[1 - player] + abs(upLines[player]);
			upLines[player] = 0;
		}
	} else {
		upLines[1 - player] = upLines[1 - player] + bo;
	}
	
	vssTotalAttack[player] = vssTotalAttack[player] + bo;
	
	// ���C��������
	vssLines[player] = vssLines[player] + lines;
	
	// ���������ז��u���b�N��
	if(bo > 0) {
		vssAttackGet[player] = bo;
		vssAttackFrame[player] = 120;
	}
}

// ����オ��
void vssUpLineProc(int player) {
	int i, temp;
	
	// ���̈ʒu��ς���
	if(vssVersion >= 4) {
		i = GiziRand(player, 100);
		if(i < vssHoleShiftRate) {
			temp = vssGHole[player];
			
			do {
				vssGHole[player] = GiziRand(player, 10);
			} while(vssGHole[player] == temp);
		}
	} else {
		i = GiziRand(player, 10);
		if(i >= 7) {
			temp = vssGHole[player];
			
			do {
				vssGHole[player] = GiziRand(player, 10);
			} while(vssGHole[player] == temp);
		}
	}
	
	// ����オ��u���b�N�쐬
	for(i = 0; i < 10; i++) fldu[i + player * 220] = (i != vssGHole[player]);
}

// �X�R�A�\��
void vssViewScore(int player) {
	int color;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// ���C����
	printTinyFont(112 + player * 70, 40, "LINES");
	if(player == 0) {
		sprintf(string[0], "%d", vssLines[player]);
	} else {
		sprintf(string[0], "%4d", vssLines[player]);
	}
	printSMALLFont(112 + player * 72, 48, string[0], color);
	
	// �U����
	printTinyFont(112 + player * 65, 58, "ATTACK");
	if(player == 0) {
		sprintf(string[0], "%d", vssTotalAttack[player]);
	} else {
		sprintf(string[0], "%4d", vssTotalAttack[player]);
	}
	printSMALLFont(112 + player * 72, 66, string[0], color);
	
	// ���������ז��u���b�N��
	if(vssAttackFrame[player] > 0) {
		vssAttackFrame[player]--;
		if(player == 0) {
			sprintf(string[0], "%d", vssAttackGet[player]);
		} else {
			sprintf(string[0], "%4d", vssAttackGet[player]);
		}
		printSMALLFont(112 + player * 72, 75, string[0], (count % 4 / 2) * (1 + (b_to_b_count[player] != 0)));
	}
	
	// �^�C��
	if(player == 0) {
		getTime(gameTimer[player]);
		printBIGFont(112, 216, string[0], color);
	}
	
	// T-SPIN
	if(vssTSpinFrame[player] > 0) {
		vssTSpinFrame[player]--;
		
		if(vssTSpinLine[player] == 1)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN SINGLE");
		else if(vssTSpinLine[player] == 2)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN DOUBLE");
		else if(vssTSpinLine[player] == 3)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN TRIPLE");
		else if(vssTSpinLine[player] == 4)
			printTinyFont(foffset[player] + 30, fyoffset[player] + 208, "HEBORIS");
	}
	
	// BACK TO BACK
	if(vssB2BFrame[player] > 0) {
		vssB2BFrame[player]--;
		printTinyFont(foffset[player] + 18, fyoffset[player] + 200, "BACK TO BACK");
	}
	// COMBO
	else if((vssComboFrame[player] > 0) && (combo[player] >= 2)) {
		vssComboFrame[player]--;
		sprintf(string[0], "COMBO %d", combo[player] - 1);
		printTinyFont(foffset[player] + 30, fyoffset[player] + 200, string[0]);
	}
	
	// ����オ�萔
	if(upLines[player]) {
		sprintf(string[0], "%d LINE UP", upLines[player]);
		printTinyFontB(foffset[player] + 25, fyoffset[player] + 216, string[0]);
	}
}

// �Q�[���I�[�o�[����
void vssGameOver(int player, int *param) {
	int i, drawflag;
	
	param[0] = 1;
	
	// ���������t���O
	if(stat[1 - player] == 7) drawflag = 1;
	else drawflag = 0;
	
	// �ŏ��̃t���[���̏���
	if(statc[player * 10] == 0) {
		StopAllBGM();
		disp_blkline[player] = 0;
		onRecord[0] = 0;
		onRecord[1] = 0;
		timeOn[0] = 0;
		timeOn[1] = 0;
		pinch[0] = 0;
		pinch[1] = 0;
		
		if(!drawflag) {
			stat[1 - player] = 2;
			resetStatc(1 - player);
		}
	}
	
	// LOSE���S
	statc[player * 10 + 1]++;
	statc[player * 10 + 2] = statc[player * 10 + 2] + statc[player * 10 + 1] / 4;
	
	if(statc[player * 10 + 2] > 140) {
		statc[player * 10 + 2] = 140;
		statc[player * 10 + 1] = -20;
	}
	
	ExBltRect(sg_spr, foffset[player] + 8, statc[player * 10 + 2], 184, 24 * (drawflag + 1), 79, 23);
	
	statc[player * 10]++;
	
	// �{�^���ŃX�L�b�v
	if(getPushState(player, 4) && (statc[player * 10] >= 60)) {
		statc[player * 10] = 300;
	}
	// ���̉�ʂ�
	if(statc[player * 10] >= 300) {
		stat[0] = 8;
		stat[1] = 8;
		resetStatc(0);
		resetStatc(1);
		resetField(0);
		resetField(1);
	}
}

// ����
void vssWin(int player) {
	int i;
	
	// �ԉ�
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 3] < 10)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 3]++;
	}
	
	// WIN���S
	statc[player * 10 + 1]++;
	statc[player * 10 + 2] = statc[player * 10 + 2] + statc[player * 10 + 1] / 4;
	
	if(statc[player * 10 + 2] > 140) {
		statc[player * 10 + 2] = 140;
		statc[player * 10 + 1] = -20;
	}
	
	ExBltRect(sg_spr, foffset[player] + 9, statc[player * 10 + 2], 184, 0, 79, 23);
	
	statc[player * 10]++;
	
	// �{�^���ŃX�L�b�v
	if(getPushState(player, 4) && (statc[player * 10] >= 60)) {
		statc[player * 10] = 300;
	}
	// ���̉�ʂ�
	if(statc[player * 10] >= 300) {
		stat[0] = 8;
		stat[1] = 8;
		resetStatc(0);
		resetStatc(1);
		resetField(0);
		resetField(1);
	}
}

// ���ʕ\��
void vssResult(int player, int *param) {
	param[0] = 1;
	
	// ����
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", vssLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "TOTAL ATTACK");
	sprintf(string[0], "%13d", vssTotalAttack[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "TIME");
	getTime(gameTimer[0]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[1], 0);
	
	// �J�E���^����
	statc[player * 10]++;
	
	// BGM�Đ�
	if(player == 0) {
		if(statc[player * 10] == 1) {
			if((bgmtype != 0) && (!fast)) {
				bgmlv = 13;
				if(!enable_sysbgm) loadBGM(13);
				PlayBGM();
			}
		}
	}
	
	// �{�^���ŃX�L�b�v
	if(getPushState(player, 4)) {
		statc[player * 10] = 500;
	}
	
	// ���̉�ʂ�
	if(statc[player * 10] >= 500) {
		stat[0] = 9;
		stat[1] = 9;
		resetStatc(0);
		resetStatc(1);
	}
}

// �Q�[���I�[�o�[�\��
void vssGameOver2(int player, int *param) {
	int i, param;
	
	param[0] = 1;
	
	// �J�E���^����
	statc[player * 10]++;
	
	// �Q�[���I�[�o�[��
	if(player == 0) {
		if(statc[player * 10] == 1) {
			PlaySE(se_gameover);
			StopAllBGM();
		}
	}
	
	// GAME OVER
	ExBltRect(sg_gametext, foffset[player] - 2, 95, 0, 0, 100, 50);
	
	// �{�^���ŃX�L�b�v
	if(getPushState(player, 4)) {
		statc[player * 10] = 480;
	}
	
	// �I��
	if(statc[player * 10] >= 480) {
		if(playback && replayauto) {
			stat[0] = 0;
			stat[1] = 0;
		} else {
			stat[0] = 11;
			stat[1] = 11;
		}
		resetStatc(0);
		resetStatc(1);
	}
}

// ���g���C
void vssRetry(int *param) {
	param[0] = 1;
	
	gameAllInit();
	
	playerInitial(0);
	versusInit(0);
	
	playerInitial(1);
	versusInit(1);
}

// �ݒ���
void vssSetting(int player, int *param) {
	int i, j, k, cursor, move, param2p, page, max, crots;
	cursor = 0;
	move = 0;
	page = 0;
	crots = rots[0];
	
	maxPlay = 1;	// 2P��L���ɂ���
	
	vssLoadConfig();	// �ݒ��ǂݍ���
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		// 2P���[���Z���N�g
		if(page == 0) {
			printFontGrid(1, 1, "SELECT 2P ROTATION RULE", 1);
			
			// ���j���[�\��
			max = plugin_count_rule;
			if(max > 20) max = 20;
			j = 0;
			k = (crots / 20) * 20;
			
			for(i = 0; i < max; i++) {
				sprintf(string[0], "%03d:", k + i + 1);
				printFontGrid(2, 3 + j, string[0], 7 * (crots == k + i));
				printFontGrid(6, 3 + j, plugin_name_rule[k + i], 7 * (crots == k + i));
				if(crots == k + i) printFontGrid(1, 3 + j, "b", 7);
				j++;
			}
			
			// �J�[�\���ړ�
			padRepeat2(1);
			
			// ��
			if( (mpc2[1] == 1) || ((mpc2[1] > tame3) && (mpc2[1] % tame4 == 0)) || getPressState(1, 6) )
			if(getPressState(1, 0)) {
				PlaySE(se_move);
				crots--;
				if(crots < 0) crots = plugin_count_rule - 1;
			}
			
			// ��
			if( (mpc2[1] == 1) || ((mpc2[1] > tame3) && (mpc2[1] % tame4 == 0)) || getPressState(1, 6) )
			if(getPressState(1, 1)) {
				PlaySE(se_move);
				crots++;
				if(crots > plugin_count_rule - 1) crots = 0;
			}
			
			// �L�����Z��
			if(getPushState(0, 5) || getPushState(1, 5)) {
				PlaySE(se_move);
				maxPlay = 0;
				param[0] = 0;
				return;
			}
			// ����
			else if(getPushState(1, 4)) {
				if(plugin_count_rule > 0) {
					PlaySE(se_kettei);
					rots[1] = crots;
					
					param2p = 1;
					executePlugin(1, 16, &param2p);	// �v���O�C���Ăяo��
					
					if(param2p) page++;
				}
			}
		}
		// ���[�h�ݒ�
		else if(page == 1) {
			printFontGrid(1, 1, "VS-STANDARD", 4);
			
			// ���[����
			printFontGrid(2, 3, "1P RULE", 2);
			printFontGrid(22, 3, plugin_name_rule[rots[0]], 2);
			printFontGrid(2, 4, "2P RULE", 1);
			printFontGrid(22, 4, plugin_name_rule[rots[1]], 1);
			
			// �ݒ荀��
			printFontGrid(1, 6, "GAME OPTIONS", 4);
			
			printFontGrid(1, 8 + cursor, "b", 7);
			
			printFontGrid( 2,  8, "1P CPU FLAG",  (cursor == 0) * 7);
			if(!vssCPUFlag[0]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22,  8, string[0],      (cursor == 0) * 7);
			
			printFontGrid( 2,  9, "1P CPU SPEED", (cursor == 1) * 7);
			sprintf(string[0], "%d", vssCPUSpeed[0]);
			printFontGrid(22,  9, string[0],      (cursor == 1) * 7);
			
			printFontGrid( 2, 10, "2P CPU FLAG",  (cursor == 2) * 7);
			if(!vssCPUFlag[1]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 10, string[0],      (cursor == 2) * 7);
			
			printFontGrid( 2, 11, "2P CPU SPEED", (cursor == 3) * 7);
			sprintf(string[0], "%d", vssCPUSpeed[1]);
			printFontGrid(22, 11, string[0],      (cursor == 3) * 7);
			
			printFontGrid( 2, 12, "GHOST BLOCK",  (cursor == 4) * 7);
			if(!vssGhost) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 12, string[0],      (cursor == 4) * 7);
			
			printFontGrid( 2, 13, "T-SPIN",       (cursor == 5) * 7);
			if(vssTSpin == 0) sprintf(string[0], "OFF");
			else if(vssTSpin == 1) sprintf(string[0], "LINE CLEAR");
			else if(vssTSpin == 2) sprintf(string[0], "IMMOBILE");
			else if(vssTSpin == 3) sprintf(string[0], "3-CORNER");
			else sprintf(string[0], "3-CORNER NO KICK");
			printFontGrid(22, 13, string[0],      (cursor == 5) * 7);
			
			printFontGrid( 2, 14, "COMBO",        (cursor == 6) * 7);
			if(!vssEnableCombo) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 14, string[0],      (cursor == 6) * 7);
			
			printFontGrid( 2, 15, "BACK TO BACK", (cursor == 7) * 7);
			if(vssEnableB2B == 0) sprintf(string[0], "OFF");
			else if(vssEnableB2B == 1) sprintf(string[0], "ON");
			else if(vssEnableB2B == 2) sprintf(string[0], "HEBORIS ONLY");
			else sprintf(string[0], "T-SPIN ONLY");
			printFontGrid(22, 15, string[0],      (cursor == 7) * 7);
			
			printFontGrid( 2, 16, "HOLE CHANGE CHANCE", (cursor == 8) * 7);
			sprintf(string[0], "%d%%", vssHoleShiftRate);
			printFontGrid(22, 16, string[0], (cursor == 8) * 7);
			
			if(!english) printFontGrid( 2, 17, "SOUSAI", (cursor == 9) * 7);
			else printFontGrid( 2, 17, "GARBAGE COUNTERING", (cursor == 9) * 7);
			if(!vssSousai) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 17, string[0], (cursor == 9) * 7);
			
			printFontGrid( 2, 18, "SPEED", (cursor == 10) * 7);
			sprintf(string[0], "%d", vssSpeed);
			printFontGrid(22, 18, string[0], (cursor == 10) * 7);
			
			printFontGrid( 2, 19, "SPEED TYPE", (cursor == 11) * 7);
			if(vssSpeedType == 0) sprintf(string[0], "1/60");
			else if(vssSpeedType == 1) sprintf(string[0], "FRAMES PER ROW");
			else sprintf(string[0], "1/256");
			printFontGrid(22, 19, string[0], (cursor == 11) * 7);
			
			if(!english) printFontGrid( 2, 20, "SYUTUGEN", (cursor == 12) * 7);
			else printFontGrid( 2, 20, "ARE", (cursor == 12) * 7);
			sprintf(string[0], "%d", vssWait1);
			printFontGrid(22, 20, string[0], (cursor == 12) * 7);
			
			if(!english) printFontGrid( 2, 21, "SYOUKYO", (cursor == 13) * 7);
			else printFontGrid( 2, 21, "LINE DELAY", (cursor == 13) * 7);
			sprintf(string[0], "%d", vssWait2);
			printFontGrid(22, 21, string[0], (cursor == 13) * 7);
			
			if(!english) printFontGrid( 2, 22, "SETTYAKU", (cursor == 14) * 7);
			else printFontGrid( 2, 22, "LOCK DELAY", (cursor == 14) * 7);
			sprintf(string[0], "%d", vssWait3);
			printFontGrid(22, 22, string[0], (cursor == 14) * 7);
			
			if(!english) printFontGrid( 2, 23, "YOKOTAME", (cursor == 15) * 7);
			else printFontGrid( 2, 23, "DAS", (cursor == 15) * 7);
			sprintf(string[0], "%d", vssWaitt);
			printFontGrid(22, 23, string[0], (cursor == 15) * 7);
			
			if(!english) printFontGrid( 2, 24, "SETTYAKU2", (cursor == 16) * 7);
			else printFontGrid( 2, 24, "LOCK DELAY2", (cursor == 16) * 7);
			if(vssWait4 == -1) {
				if(!english) sprintf(string[0], "USE SETTYAKU");
				else sprintf(string[0], "USE LOCK DELAY");
			} else {
				sprintf(string[0], "%d", vssWait4);
			}
			printFontGrid(22, 24, string[0], (cursor == 16) * 7);
			
			if(!english) printFontGrid( 2, 25, "SYUTUGEN2", (cursor == 17) * 7);
			else printFontGrid( 2, 25, "ARE2", (cursor == 17) * 7);
			if(vssWait5 == -1) {
				if(!english) sprintf(string[0], "USE SYUTUGEN");
				else sprintf(string[0], "USE ARE");
			} else {
				sprintf(string[0], "%d", vssWait5);
			}
			printFontGrid(22, 25, string[0], (cursor == 17) * 7);
			
			printFontGrid(1, 29, "A:START B:BACK", 6);
			
			// �J�[�\���ړ�
			padRepeat2(player);
			
			move = 0;
			if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
				move = getPressState(player, 1) - getPressState(player, 0);
			
			if(move) {
				PlaySE(se_move);
				cursor = cursor + move;
				if(cursor < 0) cursor = 17;
				if(cursor > 17) cursor = 0;
			}
			
			// �l��ύX
			padRepeat(player);
			
			move = 0;
			if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
				move = getPressState(player, 3) - getPressState(player, 2);
			
			if(move) {
				PlaySE(se_kachi);
				
				if(cursor == 0) vssCPUFlag[0] = !vssCPUFlag[0];
				if(cursor == 1) {
					vssCPUSpeed[0] = vssCPUSpeed[0] + move;
					if(vssCPUSpeed[0] < 0) vssCPUSpeed[0] = 60;
					if(vssCPUSpeed[0] > 60) vssCPUSpeed[0] = 0;
				}
				if(cursor == 2) vssCPUFlag[1] = !vssCPUFlag[1];
				if(cursor == 3) {
					vssCPUSpeed[1] = vssCPUSpeed[1] + move;
					if(vssCPUSpeed[1] < 0) vssCPUSpeed[1] = 60;
					if(vssCPUSpeed[1] > 60) vssCPUSpeed[1] = 0;
				}
				if(cursor == 4) vssGhost = !vssGhost;
				if(cursor == 5) {
					vssTSpin = vssTSpin + move;
					if(vssTSpin < 0) vssTSpin = 4;
					if(vssTSpin > 4) vssTSpin = 0;
				}
				if(cursor == 6) vssEnableCombo = !vssEnableCombo;
				if(cursor == 7) {
					vssEnableB2B = vssEnableB2B + move;
					if(vssEnableB2B < 0) vssEnableB2B = 3;
					if(vssEnableB2B > 3) vssEnableB2B = 0;
				}
				if(cursor == 8) {
					vssHoleShiftRate = vssHoleShiftRate + move;
					if(vssHoleShiftRate < 0) vssHoleShiftRate = 100;
					if(vssHoleShiftRate > 100) vssHoleShiftRate = 0;
				}
				if(cursor == 9) vssSousai = !vssSousai;
				if(cursor == 10) {
					vssSpeed = vssSpeed + move;
					if(vssSpeed < 0) vssSpeed = 5120;
					if(vssSpeed > 5120) vssSpeed = 0;
				}
				if(cursor == 11) {
					vssSpeedType = vssSpeedType + move;
					if(vssSpeedType < 0) vssSpeedType = 2;
					if(vssSpeedType > 2) vssSpeedType = 0;
				}
				if(cursor == 12) {
					vssWait1 = vssWait1 + move;
					if(vssWait1 < 0) vssWait1 = 99;
					if(vssWait1 > 99) vssWait1 = 0;
				}
				if(cursor == 13) {
					vssWait2 = vssWait2 + move;
					if(vssWait2 < 0) vssWait2 = 99;
					if(vssWait2 > 99) vssWait2 = 0;
				}
				if(cursor == 14) {
					vssWait3 = vssWait3 + move;
					if(vssWait3 < 0) vssWait3 = 99;
					if(vssWait3 > 99) vssWait3 = 0;
				}
				if(cursor == 15) {
					vssWaitt = vssWaitt + move;
					if(vssWaitt < 0) vssWaitt = 99;
					if(vssWaitt > 99) vssWaitt = 0;
				}
				if(cursor == 16) {
					vssWait4 = vssWait4 + move;
					if(vssWait4 < -1) vssWait4 = 99;
					if(vssWait4 > 99) vssWait4 = -1;
				}
				if(cursor == 17) {
					vssWait5 = vssWait5 + move;
					if(vssWait5 < -1) vssWait5 = 99;
					if(vssWait5 > 99) vssWait5 = -1;
				}
			}
			
			// �L�����Z��
			if(getPushState(0, 5) || getPushState(1, 5)) {
				PlaySE(se_move);
				
				param2p = 1;
				executePlugin(1, 16, &param2p);	// �v���O�C���Ăяo��
				
				if(!param2p) page--;
			}
			// ����
			else if(getPushState(0, 4) || getPushState(1, 4)) {
				// 2P�̃��[�h��1P�Ɠ����ɂ���
				gameMode[1] = gameMode[0];
				
				// �ݒ��ۑ�
				vssSaveConfig();
				
				// �J�n
				return;
			}
		}
	}
}

// �ݒ��ۑ�
void vssSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �ݒ���e
	saveBuf[1] = vssCPUFlag[0];
	saveBuf[2] = vssCPUFlag[1];
	saveBuf[3] = vssCPUSpeed[0];
	saveBuf[4] = vssCPUSpeed[1];
	saveBuf[5] = vssGhost;
	saveBuf[6] = vssTSpin;
	saveBuf[7] = vssEnableCombo;
	saveBuf[8] = vssEnableB2B;
	saveBuf[9] = vssSpeed;
	saveBuf[10] = vssSpeedType;
	saveBuf[11] = vssWait1;
	saveBuf[12] = vssWait2;
	saveBuf[13] = vssWait3;
	saveBuf[14] = vssWaitt;
	saveBuf[15] = vssWait4;
	saveBuf[16] = vssWait5;
	saveBuf[17] = vssHoleShiftRate;
	saveBuf[18] = vssSousai;
	
	SaveFile("config/VS_STANDARD_CONFIG.SAV", &saveBuf, 50 * 4);
}

// �ݒ��ǂݍ���
int vssLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/VS_STANDARD_CONFIG.SAV", &saveBuf, 50 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �ݒ���e
	vssCPUFlag[0] = saveBuf[1];
	vssCPUFlag[1] = saveBuf[2];
	vssCPUSpeed[0] = saveBuf[3];
	vssCPUSpeed[1] = saveBuf[4];
	vssGhost = saveBuf[5];
	vssTSpin = saveBuf[6];
	vssEnableCombo = saveBuf[7];
	vssEnableB2B = saveBuf[8];
	vssSpeed = saveBuf[9];
	vssSpeedType = saveBuf[10];
	vssWait1 = saveBuf[11];
	vssWait2 = saveBuf[12];
	vssWait3 = saveBuf[13];
	vssWaitt = saveBuf[14];
	vssWait4 = saveBuf[15];
	vssWait5 = saveBuf[16];
	vssHoleShiftRate = saveBuf[17];
	vssSousai = saveBuf[18];
	
	return 1;
}

// ���v���C�ۑ�
void vssSaveReplay(int player) {
	saveBuf[900] = vssGhost;
	saveBuf[901] = vssTSpin;
	saveBuf[902] = vssEnableCombo;
	saveBuf[903] = vssEnableB2B;
	saveBuf[904] = vssVersion;
	saveBuf[905] = vssSpeed;
	saveBuf[906] = vssSpeedType;
	saveBuf[907] = vssWait1;
	saveBuf[908] = vssWait2;
	saveBuf[909] = vssWait3;
	saveBuf[910] = vssWaitt;
	saveBuf[911] = vssWait4;
	saveBuf[912] = vssWait5;
	saveBuf[913] = vssHoleShiftRate;
	saveBuf[914] = vssSousai;
}

// ���v���C�ǂݍ���
void vssLoadReplay(int player) {
	maxPlay = 1;	// 2P��L���ɂ���
	
	vssGhost = saveBuf[900];
	vssTSpin = saveBuf[901];
	vssEnableCombo = saveBuf[902];
	vssEnableB2B = saveBuf[903];
	vssVersion = saveBuf[904];
	
	if(vssVersion >= 1) {
		vssSpeed = saveBuf[905];
		vssSpeedType = saveBuf[906];
		vssWait1 = saveBuf[907];
		vssWait2 = saveBuf[908];
		vssWait3 = saveBuf[909];
		vssWaitt = saveBuf[910];
	}
	
	if(vssVersion >= 2) vssWait4 = saveBuf[911];
	else vssWait4 = -1;
	
	if(vssVersion >= 3) vssWait5 = saveBuf[912];
	else vssWait5 = -1;
	
	vssHoleShiftRate = saveBuf[913];
	vssSousai = saveBuf[914];
	
	vssPlayerInitial(player);	// �ݒ�𔽉f�����邽�߂ɏ������������s
}

// ���v���C�ڍ�
void vssReplayDetail() {
	printFontGrid(1, 5, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[904]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 7, "GHOST BLOCK", 0);
	if(!saveBuf[900]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 8, "T-SPIN", 0);
	if(saveBuf[901] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[901] == 1) sprintf(string[0], "LINE CLEAR");
	else if(saveBuf[901] == 2) sprintf(string[0], "IMMOBILE");
	else if(saveBuf[901] == 3) sprintf(string[0], "3-CORNER");
	else sprintf(string[0], "3-CORNER NO KICK");
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "COMBO", 0);
	if(!saveBuf[902]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "BACK TO BACK", 0);
	if(saveBuf[903] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[903] == 1) sprintf(string[0], "ON");
	else if(saveBuf[903] == 2) sprintf(string[0], "HEBORIS ONLY");
	else sprintf(string[0], "T-SPIN ONLY");
	printFontGrid(22, 10, string[0], 0);
	
	if(saveBuf[904] >= 1) {
		printFontGrid(1, 12, "SPEED", 0);
		sprintf(string[0], "%d", saveBuf[905]);
		printFontGrid(22, 12, string[0], 0);
		
		printFontGrid(1, 13, "SPEED TYPE", 0);
		if(saveBuf[906] == 0) sprintf(string[0], "1/60");
		else if(saveBuf[906] == 1) sprintf(string[0], "FRAMES PER ROW");
		else sprintf(string[0], "1/256");
		printFontGrid(22, 13, string[0], 0);
		
		if(!english) printFontGrid(1, 14, "SYUTUGEN", 0);
		else printFontGrid(1, 14, "ARE", 0);
		sprintf(string[0], "%d", saveBuf[907]);
		printFontGrid(22, 14, string[0], 0);
		
		if(!english) printFontGrid(1, 15, "SYOUKYO", 0);
		else printFontGrid(1, 15, "LINE DELAY", 0);
		sprintf(string[0], "%d", saveBuf[908]);
		printFontGrid(22, 15, string[0], 0);
		
		if(!english) printFontGrid(1, 16, "SETTYAKU", 0);
		else printFontGrid(1, 16, "LOCK DELAY", 0);
		sprintf(string[0], "%d", saveBuf[909]);
		printFontGrid(22, 16, string[0], 0);
		
		if(!english) printFontGrid(1, 17, "YOKOTAME", 0);
		else printFontGrid(1, 17, "DAS", 0);
		sprintf(string[0], "%d", saveBuf[910]);
		printFontGrid(22, 17, string[0], 0);
	}
	
	if(saveBuf[904] >= 2) {
		if(!english) printFontGrid(1, 18, "SETTYAKU2", 0);
		else printFontGrid(1, 18, "LOCK DELAY2", 0);
		if(saveBuf[911] == -1) {
			if(!english) sprintf(string[0], "USE SETTYAKU");
			else sprintf(string[0], "USE LOCK DELAY");
		} else {
			sprintf(string[0], "%d", saveBuf[911]);
		}
		printFontGrid(22, 18, string[0], 0);
	}
	
	if(saveBuf[904] >= 3) {
		if(!english) printFontGrid(1, 19, "SYUTUGEN2", 0);
		else printFontGrid(1, 19, "ARE2", 0);
		if(saveBuf[911] == -1) {
			if(!english) sprintf(string[0], "USE SYUTUGEN");
			else sprintf(string[0], "USE ARE");
		} else {
			sprintf(string[0], "%d", saveBuf[912]);
		}
		printFontGrid(22, 19, string[0], 0);
	}
	
	if(saveBuf[904] >= 4) {
		printFontGrid(1, 20, "HOLE CHANGE CHANCE", 0);
		sprintf(string[0], "%d%%", saveBuf[913]);
		printFontGrid(22, 20, string[0], 0);
		
		if(!english) printFontGrid(1, 21, "SOUSAI", 0);
		else printFontGrid(1, 21, "GARBAGE COUNTERING", 0);
		if(!saveBuf[914]) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 21, string[0], 0);
	}
}
