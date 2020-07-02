//VS-LINE
//prefix:vsl

// �o�[�W����
int vslVersion;					// �o�[�W�����ԍ��i�Â����v���C�Đ��p�j
int vslCVersion = 2;			// ���݂̃o�[�W����

// �ϐ�
int vslModeNo = -1;				// ���[�h�ԍ�

int vslLines[2];				// ���C����

int vslCPUFlag[2] = {0, 1};		// CPU�����삷�邩�ǂ���
int vslCPUSpeed[2] = {0, 5};	// CPU�̒x��
int vslGhost = 1;				// �S�[�X�g�̐ݒ�
int vslNormLine = 40;			// �m���}���C����

int vslSpeed = 1;				// �������x
int vslSpeedType = 0;			// �X�s�[�h�^�C�v
int vslWait1 = 25;				// ARE
int vslWait2 = 40;				// ���C������
int vslWait3 = 30;				// �Œ莞��
int vslWaitt = 16;				// ������
int vslWait4 = -1;				// �Œ莞�ԁi�ڒ���j
int vslWait5 = -1;				// ARE�i������j

// �C�x���g����
void vslPluginEvent(int player, int event, int *param) {
	int i;
	
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != vslModeNo)) return;
	
	if(event == 0) {
		vslModeNo = addModePlugin("VS-LINE");	// ���[�h��o�^����
	} else if(event == 3) {
		if((player == 1) && (!playback)) vslNextInit(param);	// 1P��NEXT��2P�ɃR�s�[
	} else if(event == 4) {
		vslPlayerExecute(player);	// �Q�[�������O
	} else if(event == 12) {
		vslCalcScore(player, param[0]);	// ���C������
	} else if(event == 15) {
		vslViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		vslSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		vslPlayerInitial(player);	// ������
	} else if(event == 19) {
		vslMoveInit(player);	// �u���b�N�o��
	} else if(event == 20) {
		vslGameOver(player, param);	// �Q�[���I�[�o�[����
	} else if(event == 21) {
		vslResult(player, param);	// ���ʕ\��
	} else if(event == 22) {
		vslGameOver2(player, param);	// �Q�[���I�[�o�[�\��
	} else if(event == 38) {
		if(player == 0) PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		vslSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		vslLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		if(player == 0) vslLoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		vslReplayDetail();	// ���v���C�ڍ�
	} else if(event == 68) {
		vslWin(player);	// ����
	} else if(event == 70) {
		vslRetry(param);	// ���g���C
	}
}

// ������
void vslPlayerInitial(int player) {
	int i;
	
	debugLogMode("vslPlayerInitial executed");
	
	// �o�[�W����
	if(!playback) vslVersion = vslCVersion;
	
	backno = 20;	// �w�i�ύX
	setFieldPosition(player, 2);	// �t�B�[���h�ʒu�ݒ�
	bgmlv = 10;	// BGM�ԍ��ݒ�
	
	if(!player) {
		// 1P
		blkshadow_direction[0] = 1;
	} else {
		// 2P
		blkshadow_direction[1] = 0;
		
		// ��������R�s�[
		randseed[1] = randseed[0];
		firstseed[1] = firstseed[0];
	}
	
	vslLines[player] = 0;
	
	cpu_flag[player] = vslCPUFlag[player];
	cpu_speed[player] = vslCPUSpeed[player];
	if(vslGhost == 0) ghost[player] = 0;
	else ghost[player] = 1;
	
	sp[player] = vslSpeed;
	speedtype[player] = vslSpeedType;
	wait1[player] = vslWait1;
	wait2[player] = vslWait2;
	wait3[player] = vslWait3;
	waitt[player] = vslWaitt;
	
	if(vslVersion >= 1) wait4[player] = vslWait4;
	else wait4[player] = -1;
	
	if(vslVersion >= 2) wait5[player] = vslWait5;
	else wait5[player] = -1;
	
	stat[player] = 3;
}

// 1P��NEXT��2P�ɃR�s�[
void vslNextInit(int *param) {
	int i;
	param[0] = 1;
	for(i = 0; i < 1400; i++) nextb[i + 1400] = nextb[i];
}

// �Q�[�������O
void vslPlayerExecute(int player) {
	// CPU�̑���
	if((onRecord[player]) && (timeOn[player]) && (stat[player] == 4) && (cpu_best_x[player] != -3) && (!playback) && (cpu_flag[player]))
		cpu_setCtrl(player);
}

// �u���b�N�o��
void vslMoveInit(int player) {
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
void vslLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(10);
	}
}

// ���C������
void vslCalcScore(int player, int lines) {
	vslLines[player] = vslLines[player] + lines;
	
	if(vslLines[player] >= vslNormLine) {
		stat[1 - player] = 7;
		resetStatc(1 - player);
	}
}

// �X�R�A�\��
void vslViewScore(int player) {
	int color;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// �c�胉�C��
	printTinyFont(112 + player * 70, 40, "LINES");
	if(player == 0) {
		if(vslLines[player] > vslNormLine) sprintf(string[0], "%d", 0);
		else sprintf(string[0], "%d", vslNormLine - vslLines[player]);
	} else {
		if(vslLines[player] > vslNormLine) sprintf(string[0], "%2d", 0);
		else sprintf(string[0], "%2d", vslNormLine - vslLines[player]);
	}
	printSMALLFont(112 + player * 84, 48, string[0], color);
	
	// �^�C��
	if(player == 0) {
		getTime(gameTimer[player]);
		printBIGFont(112, 216, string[0], color);
	}
}

// �Q�[���I�[�o�[����
void vslGameOver(int player, int *param) {
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
void vslWin(int player) {
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
void vslResult(int player, int *param) {
	param[0] = 1;
	
	// ����
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", vslLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "TIME");
	getTime(gameTimer[0]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[1], 0);
	
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
void vslGameOver2(int player, int *param) {
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
void vslRetry(int *param) {
	param[0] = 1;
	
	gameAllInit();
	
	playerInitial(0);
	versusInit(0);
	
	playerInitial(1);
	versusInit(1);
}

// �ݒ���
void vslSetting(int player, int *param) {
	int i, j, k, cursor, move, param2p, page, max, crots;
	cursor = 0;
	move = 0;
	page = 0;
	crots = rots[0];
	
	maxPlay = 1;	// 2P��L���ɂ���
	
	vslLoadConfig();	// �ݒ��ǂݍ���
	
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
			printFontGrid(1, 1, "VS-LINE", 4);
			
			// ���[����
			printFontGrid(2, 3, "1P RULE", 2);
			printFontGrid(22, 3, plugin_name_rule[rots[0]], 2);
			printFontGrid(2, 4, "2P RULE", 1);
			printFontGrid(22, 4, plugin_name_rule[rots[1]], 1);
			
			// �ݒ荀��
			printFontGrid(1, 6, "GAME OPTIONS", 4);
			
			if(cursor <= 5) printFontGrid(1, 8 + cursor, "b", 7);
			
			printFontGrid( 2,  8, "1P CPU FLAG",  (cursor == 0) * 7);
			if(!vslCPUFlag[0]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22,  8, string[0],      (cursor == 0) * 7);
			
			printFontGrid( 2,  9, "1P CPU SPEED", (cursor == 1) * 7);
			sprintf(string[0], "%d", vslCPUSpeed[0]);
			printFontGrid(22,  9, string[0],      (cursor == 1) * 7);
			
			printFontGrid( 2, 10, "2P CPU FLAG",  (cursor == 2) * 7);
			if(!vslCPUFlag[1]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 10, string[0],      (cursor == 2) * 7);
			
			printFontGrid( 2, 11, "2P CPU SPEED", (cursor == 3) * 7);
			sprintf(string[0], "%d", vslCPUSpeed[1]);
			printFontGrid(22, 11, string[0],      (cursor == 3) * 7);
			
			printFontGrid( 2, 12, "GHOST BLOCK",  (cursor == 4) * 7);
			if(!vslGhost) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 12, string[0],      (cursor == 4) * 7);
			
			printFontGrid( 2, 13, "NORM LINE",    (cursor == 5) * 7);
			sprintf(string[0], "%d", vslNormLine);
			printFontGrid(22, 13, string[0],      (cursor == 5) * 7);
			
			printFontGrid(1, 15, "GAME SPEED", 4);
			
			if(cursor >= 6) printFontGrid(1, 17 + cursor - 6, "b", 7);
			
			printFontGrid( 2, 17, "SPEED", (cursor == 6) * 7);
			sprintf(string[0], "%d", vslSpeed);
			printFontGrid(22, 17, string[0], (cursor == 6) * 7);
			
			printFontGrid( 2, 18, "SPEED TYPE", (cursor == 7) * 7);
			if(vslSpeedType == 0) sprintf(string[0], "1/60");
			else if(vslSpeedType == 1) sprintf(string[0], "FRAMES PER ROW");
			else sprintf(string[0], "1/256");
			printFontGrid(22, 18, string[0], (cursor == 7) * 7);
			
			if(!english) printFontGrid( 2, 19, "SYUTUGEN", (cursor == 8) * 7);
			else printFontGrid( 2, 19, "ARE", (cursor == 8) * 7);
			sprintf(string[0], "%d", vslWait1);
			printFontGrid(22, 19, string[0], (cursor == 8) * 7);
			
			if(!english) printFontGrid( 2, 20, "SYOUKYO", (cursor == 9) * 7);
			else printFontGrid( 2, 20, "LINE DELAY", (cursor == 9) * 7);
			sprintf(string[0], "%d", vslWait2);
			printFontGrid(22, 20, string[0], (cursor == 9) * 7);
			
			if(!english) printFontGrid( 2, 21, "SETTYAKU", (cursor == 10) * 7);
			else printFontGrid( 2, 21, "LOCK DELAY", (cursor == 10) * 7);
			sprintf(string[0], "%d", vslWait3);
			printFontGrid(22, 21, string[0], (cursor == 10) * 7);
			
			if(!english) printFontGrid( 2, 22, "YOKOTAME", (cursor == 11) * 7);
			else printFontGrid( 2, 22, "DAS", (cursor == 11) * 7);
			sprintf(string[0], "%d", vslWaitt);
			printFontGrid(22, 22, string[0], (cursor == 11) * 7);
			
			if(!english) printFontGrid( 2, 23, "SETTYAKU2", (cursor == 12) * 7);
			else printFontGrid( 2, 23, "LOCK DELAY2", (cursor == 12) * 7);
			if(vslWait4 == -1) {
				if(!english) sprintf(string[0], "USE SETTYAKU");
				else sprintf(string[0], "USE LOCK DELAY");
			} else {
				sprintf(string[0], "%d", vslWait4);
			}
			printFontGrid(22, 23, string[0], (cursor == 12) * 7);
			
			if(!english) printFontGrid( 2, 24, "SYUTUGEN2", (cursor == 13) * 7);
			else printFontGrid( 2, 24, "ARE2", (cursor == 13) * 7);
			if(vslWait5 == -1) {
				if(!english) sprintf(string[0], "USE SYUTUGEN");
				else sprintf(string[0], "USE ARE");
			} else {
				sprintf(string[0], "%d", vslWait5);
			}
			printFontGrid(22, 24, string[0], (cursor == 13) * 7);
			
			printFontGrid(1, 29, "A:START B:BACK", 6);
			
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
				
				if(cursor == 0) vslCPUFlag[0] = !vslCPUFlag[0];
				if(cursor == 1) {
					vslCPUSpeed[0] = vslCPUSpeed[0] + move;
					if(vslCPUSpeed[0] < 0) vslCPUSpeed[0] = 60;
					if(vslCPUSpeed[0] > 60) vslCPUSpeed[0] = 0;
				}
				if(cursor == 2) vslCPUFlag[1] = !vslCPUFlag[1];
				if(cursor == 3) {
					vslCPUSpeed[1] = vslCPUSpeed[1] + move;
					if(vslCPUSpeed[1] < 0) vslCPUSpeed[1] = 60;
					if(vslCPUSpeed[1] > 60) vslCPUSpeed[1] = 0;
				}
				if(cursor == 4) vslGhost = !vslGhost;
				if(cursor == 5) {
					vslNormLine = vslNormLine + move;
					if(vslNormLine < 0) vslNormLine = 99;
					if(vslNormLine > 99) vslNormLine = 0;
				}
				if(cursor == 6) {
					vslSpeed = vslSpeed + move;
					if(vslSpeed < 0) vslSpeed = 5120;
					if(vslSpeed > 5120) vslSpeed = 0;
				}
				if(cursor == 7) {
					vslSpeedType = vslSpeedType + move;
					if(vslSpeedType < 0) vslSpeedType = 2;
					if(vslSpeedType > 2) vslSpeedType = 0;
				}
				if(cursor == 8) {
					vslWait1 = vslWait1 + move;
					if(vslWait1 < 0) vslWait1 = 99;
					if(vslWait1 > 99) vslWait1 = 0;
				}
				if(cursor == 9) {
					vslWait2 = vslWait2 + move;
					if(vslWait2 < 0) vslWait2 = 99;
					if(vslWait2 > 99) vslWait2 = 0;
				}
				if(cursor == 10) {
					vslWait3 = vslWait3 + move;
					if(vslWait3 < 0) vslWait3 = 99;
					if(vslWait3 > 99) vslWait3 = 0;
				}
				if(cursor == 11) {
					vslWaitt = vslWaitt + move;
					if(vslWaitt < 0) vslWaitt = 99;
					if(vslWaitt > 99) vslWaitt = 0;
				}
				if(cursor == 12) {
					vslWait4 = vslWait4 + move;
					if(vslWait4 < -1) vslWait4 = 99;
					if(vslWait4 > 99) vslWait4 = -1;
				}
				if(cursor == 13) {
					vslWait5 = vslWait5 + move;
					if(vslWait5 < -1) vslWait5 = 99;
					if(vslWait5 > 99) vslWait5 = -1;
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
				vslSaveConfig();
				
				// �J�n
				return;
			}
		}
	}
}

// �ݒ��ۑ�
void vslSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �ݒ���e
	saveBuf[1] = vslCPUFlag[0];
	saveBuf[2] = vslCPUFlag[1];
	saveBuf[3] = vslCPUSpeed[0];
	saveBuf[4] = vslCPUSpeed[1];
	saveBuf[5] = vslGhost;
	saveBuf[6] = vslNormLine;
	saveBuf[7] = vslSpeed;
	saveBuf[8] = vslSpeedType;
	saveBuf[9] = vslWait1;
	saveBuf[10] = vslWait2;
	saveBuf[11] = vslWait3;
	saveBuf[12] = vslWaitt;
	saveBuf[13] = vslWait4;
	saveBuf[14] = vslWait5;
	
	SaveFile("config/VS_LINE_CONFIG.SAV", &saveBuf, 50 * 4);
}

// �ݒ��ǂݍ���
int vslLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/VS_LINE_CONFIG.SAV", &saveBuf, 50 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �ݒ���e
	vslCPUFlag[0] = saveBuf[1];
	vslCPUFlag[1] = saveBuf[2];
	vslCPUSpeed[0] = saveBuf[3];
	vslCPUSpeed[1] = saveBuf[4];
	vslGhost = saveBuf[5];
	vslNormLine = saveBuf[6];
	vslSpeed = saveBuf[7];
	vslSpeedType = saveBuf[8];
	vslWait1 = saveBuf[9];
	vslWait2 = saveBuf[10];
	vslWait3 = saveBuf[11];
	vslWaitt = saveBuf[12];
	vslWait4 = saveBuf[13];
	vslWait5 = saveBuf[14];
	
	return 1;
}

// ���v���C�ۑ�
void vslSaveReplay(int player) {
	saveBuf[900] = vslGhost;
	saveBuf[901] = vslNormLine;
	saveBuf[902] = vslVersion;
	saveBuf[903] = vslSpeed;
	saveBuf[904] = vslSpeedType;
	saveBuf[905] = vslWait1;
	saveBuf[906] = vslWait2;
	saveBuf[907] = vslWait3;
	saveBuf[908] = vslWaitt;
	saveBuf[909] = vslWait4;
	saveBuf[910] = vslWait5;
}

// ���v���C�ǂݍ���
void vslLoadReplay(int player) {
	maxPlay = 1;	// 2P��L���ɂ���
	
	vslGhost = saveBuf[900];
	vslNormLine = saveBuf[901];
	vslVersion = saveBuf[902];
	vslSpeed = saveBuf[903];
	vslSpeedType = saveBuf[904];
	vslWait1 = saveBuf[905];
	vslWait2 = saveBuf[906];
	vslWait3 = saveBuf[907];
	vslWaitt = saveBuf[908];
	vslWait4 = saveBuf[909];
	vslWait5 = saveBuf[910];
	
	vslPlayerInitial(player);	// �ݒ�𔽉f�����邽�߂ɏ������������s
}

// ���v���C�ڍ�
void vslReplayDetail() {
	printFontGrid(1, 5, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[902]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 7, "GHOST BLOCK", 0);
	if(!saveBuf[900]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 8, "NORM LINE", 0);
	sprintf(string[0], "%d", saveBuf[901]);
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 10, "SPEED", 0);
	sprintf(string[0], "%d", saveBuf[903]);
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "SPEED TYPE", 0);
	if(saveBuf[904] == 0) sprintf(string[0], "1/60");
	else if(saveBuf[904] == 1) sprintf(string[0], "FRAMES PER ROW");
	else sprintf(string[0], "1/256");
	printFontGrid(22, 11, string[0], 0);
	
	if(!english) printFontGrid(1, 12, "SYUTUGEN", 0);
	else printFontGrid(1, 12, "ARE", 0);
	sprintf(string[0], "%d", saveBuf[905]);
	printFontGrid(22, 12, string[0], 0);
	
	if(!english) printFontGrid(1, 13, "SYOUKYO", 0);
	else printFontGrid(1, 13, "LINE DELAY", 0);
	sprintf(string[0], "%d", saveBuf[906]);
	printFontGrid(22, 13, string[0], 0);
	
	if(!english) printFontGrid(1, 14, "SETTYAKU", 0);
	else printFontGrid(1, 14, "LOCK DELAY", 0);
	sprintf(string[0], "%d", saveBuf[907]);
	printFontGrid(22, 14, string[0], 0);
	
	if(!english) printFontGrid(1, 15, "YOKOTAME", 0);
	else printFontGrid(1, 15, "DAS", 0);
	sprintf(string[0], "%d", saveBuf[908]);
	printFontGrid(22, 15, string[0], 0);
	
	if(!english) printFontGrid(1, 16, "SETTYAKU2", 0);
	else printFontGrid(1, 16, "LOCK DELAY2", 0);
	if((saveBuf[909] == -1) || (saveBuf[902] <= 0)) {
		if(!english) sprintf(string[0], "USE SETTYAKU");
		else sprintf(string[0], "USE LOCK DELAY");
	} else {
		sprintf(string[0], "%d", saveBuf[909]);
	}
	printFontGrid(22, 16, string[0], 0);
	
	if(!english) printFontGrid(1, 17, "SYUTUGEN2", 0);
	else printFontGrid(1, 17, "ARE2", 0);
	if((saveBuf[910] == -1) || (saveBuf[902] <= 1)) {
		if(!english) sprintf(string[0], "USE SYUTUGEN");
		else sprintf(string[0], "USE ARE");
	} else {
		sprintf(string[0], "%d", saveBuf[910]);
	}
	printFontGrid(22, 17, string[0], 0);
}
