//�N���V�b�N���[��
//prefix:ars

// �N���V�b�N���[�� �u���b�N�f�[�^
int arsBlkDataX[7 * 4 * 4] =	// ���j�b�g���\������u���b�N�̑��΂w�ʒu(7���/4�p�x/4�u���b�N)
{
	0, 1, 2, 3,			2, 2, 2, 2,			3, 2, 1, 0,			2, 2, 2, 2,	// I
	1, 0, 0, 2,			1, 0, 1, 1,			1, 2, 2, 0,			1, 2, 1, 1,	// L
	1, 2, 2, 1,			2, 2, 1, 1,			2, 1, 1, 2,			1, 1, 2, 2,	// O
	1, 0, 1, 2,			2, 2, 1, 1,			1, 2, 1, 0,			1, 1, 2, 2,	// Z
	1, 0, 1, 2,			1, 1, 0, 1,			1, 2, 1, 0,			1, 1, 2, 1,	// T
	1, 0, 2, 2,			1, 1, 1, 0,			1, 2, 0, 0,			1, 1, 1, 2,	// J
	1, 2, 1, 0,			1, 1, 0, 0,			1, 0, 1, 2,			0, 0, 1, 1,	// S
};

int arsBlkDataY[7 * 4 * 4] =	// ���j�b�g���\������u���b�N�̑��΂x�ʒu(7���/4�p�x/4�u���b�N)
{
	1, 1, 1, 1,			0, 1, 2, 3,			1, 1, 1, 1,			3, 2, 1, 0,	// I
	1, 2, 1, 1,			1, 0, 0, 2,			2, 1, 2, 2,			1, 2, 2, 0,	// L
	1, 1, 2, 2,			1, 2, 2, 1,			2, 2, 1, 1,			2, 1, 1, 2,	// O
	1, 1, 2, 2,			1, 0, 1, 2,			2, 2, 1, 1,			1, 2, 1, 0,	// Z
	1, 1, 2, 1,			1, 0, 1, 2,			2, 2, 1, 2,			1, 2, 1, 0,	// T
	1, 1, 1, 2,			1, 0, 2, 2,			2, 2, 2, 1,			1, 2, 0, 0,	// J
	1, 1, 2, 2,			1, 2, 1, 0,			2, 2, 1, 1,			1, 0, 1, 2,	// S
};

// �u���b�N�o���ʒu�i�ʏ�j
int arsSpawnX[7]   = { 3, 3, 3, 3, 3, 3, 3};	// X���W
int arsSpawnYU[7]  = { 1, 1, 1, 1, 1, 1, 1};	// Y���W�i�g���o���j
int arsSpawnYA[7]  = { 0,-1,-1,-1,-1,-1,-1};	// Y���W�i�g�O�o���j
int arsNDelay[7]   = { 0, 0, 0, 0, 0, 0, 0};	// �g�O�o����NEXT�x������������Y���W

// �u���b�N�o���ʒu�i�r�b�O�j
int arsBSpawnX[7]  = { 1, 2, 1, 2, 2, 2, 2};	// X���W�i1�}�X�ړ��j
int arsBSpawnX2[7] = { 2, 2, 2, 2, 2, 2, 2};	// X���W�i2�}�X�ړ��j
int arsBSpawnYU[7] = { 0, 0, 0, 0, 0, 0, 0};	// Y���W�i�g���o���j
int arsBSpawnYA[7] = {-1,-2,-2,-2,-2,-2,-2};	// Y���W�i�g�O�o���j
int arsBNDelay[7]  = {-1,-1,-1,-1,-1,-1,-1};	// �g�O�o����NEXT�x������������Y���W

// �u���b�N�̐F�ƕ\����
int arsColor[7 * 2];
str arsStrColor[8] = {"GRAY", "RED", "ORANGE", "YELLOW", "GREEN", "CYAN", "BLUE", "PURPLE"};

int arsRuleNumber = -1;		// ���[���ԍ�

int arsExtRotate[2];		// �Ԃ̕ǏR�菰�R��
int arsLockReset[2];		// �Œ莞�ԃ��Z�b�g
int arsRotLimit[2];			// ��]����
int arsMoveLimit[2];		// �ړ�����
int arsGraphics[2];			// �O���t�B�b�N�ԍ�
int arsAre[2];				// �o���҂����Ԃ̗L��
int arsLockUp[2];			// ��ő��Œ�
int arsLockDown[2];			// ���ő��Œ�
int arsRotReverse[2];		// ��]�������t�]������
int arsSoftSpeed[2];		// �\�t�g�h���b�v�̑��x
int arsMaxWaitt[2];			// �ő剡����
int arsFastlrmove[2];		// ��s���ړ�
int arsOBlkBG[2];			// ����c�l�o�ꒆ�̔w�i
int arsInitRotate[2];		// ��s��]
int arsInitHold[2];			// ��s�z�[���h
int arsEnableKick[2];		// �ǏR��L��
int arsSelfLockSound[2];	// �����ŌŒ肳�����Ƃ��ɉ����o��
int arsLockflash[2];		// �u���b�N���Œ肳�����u�ԁA�u���b�N������t���[����
int arsRepeatDelay[2];		// RepeatDelay

int arsPreset[30 * 5];		// �v���Z�b�g
int arsLastPresetNo[2];		// �Ō�ɑI�������v���Z�b�g�ԍ�

// �C�x���g�������ɌĂ΂��
void arsPluginEvent(int player, int event, int *param) {
	// ���[����ARS����Ȃ�������߂�i���[����o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (rots[player] != arsRuleNumber)) return;
	
	if(event == 0) {
		arsRuleNumber = addRulePlugin("ARS");	// ���[����o�^����
	} else if(event == 8) {
		arsBlockMove(player);	// �u���b�N�ړ���
	} else if(event == 9) {
		arsWallKick(player, param);	// �ǏR��
	} else if(event == 16) {
		arsSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		arsPlayerInitial(player);	// �Q�[���J�n�O�̏�����
	} else if(event == 19) {
		arsBlockSpawn(player);	// �u���b�N�o����
	} else if(event == 54) {
		arsReplayDetail(param[0]);	// ���v���C�ڍ�
	} else if(event == 58) {
		arsIsTSpin3Corner(player, param);	// 3-CORNER�^�C�v��T-SPIN����
	}
}

// �Q�[���J�n�O�̏�����
void arsPlayerInitial(int player) {
	int i;
	
	// �u���b�N�f�[�^���R�s�[
	for(i = 0; i < 112; i++) {
		blkDataX[player * 112 + i] = arsBlkDataX[i];
		blkDataY[player * 112 + i] = arsBlkDataY[i];
	}
	makeBlockLinkData(player); // �u���b�N�̌q����f�[�^����������
	
	// �_��NEXT�ł̈ʒu�����炷
	next_offset[player * 7 + 0] = 8;
	
	// �ݒ�𔽉f������
	kicktype[player] = arsExtRotate[player];
	lockreset[player] = arsLockReset[player];
	rotlimit[player] = arsRotLimit[player];
	movelimit[player] = arsMoveLimit[player];
	blockgraphics[player] = arsGraphics[player];
	are[player] = arsAre[player];
	lock_up[player] = arsLockUp[player];
	lock_down[player] = arsLockDown[player];
	rot_reverse[player] = arsRotReverse[player];
	softspeed[player] = arsSoftSpeed[player];
	max_waitt[player] = arsMaxWaitt[player];
	fastlrmove[player] = arsFastlrmove[player];
	oblk_bg[player] = arsOBlkBG[player];
	for(i = 0; i < 7; i++) blockcolor[player * 7 + i] = arsColor[player * 7 + i];
	initial_rotate[player] = arsInitRotate[player];
	initial_hold[player] = arsInitHold[player];
	enable_wallkick[player] = arsEnableKick[player];
	self_lock_sound[player] = arsSelfLockSound[player];
	lockflash[player] = arsLockflash[player];
	RepeatDelay[player] = arsRepeatDelay[player];
}

// �ǏR��
void arsWallKick(int player, int *param) {
	int i, temp, bak, move;
	bak = param[1];
	move = param[2];
	
	// �_�ȊO
	if(blk[player] != 0) {
		// �d�Ȃ��Ă��镔�����^���̗񂾂��ł͂Ȃ����
		if(judgeBlockRotate(player, bx[player], by[player], blk[player], bak)) {
			temp = 0;
			
			for(i = 0; i <= IsBig[player]; i++) {
				// ��
				if(judgeBlock(player, bx[player] - 1 - i, by[player], blk[player], bak) == 0) temp = -1 - i;
				// �E
				if(judgeBlock(player, bx[player] + 1 + i, by[player], blk[player], bak) == 0) temp = 1 + i;
				
				if(temp) {
					bx[player] = bx[player] + temp;
					param[0] = 1;
					return;
				}
			}
		}
	}
	
	// �s���̒E�o�i1�񂾂��j
	if((kicktype[player]) && (blk[player] == 4) && (!kickc[player]) && (bak == 2)) {
		for(i = 0; i <= IsBig[player]; i++) {
			if(judgeBlock(player, bx[player], by[player] - 1 - i, blk[player], bak) == 0) {
				by[player] = by[player] - 1 - i;
				kickc[player]++;
				bk[player] = 0;
				bfallflag[player] = 1;
				param[0] = 1;
				return;
			}
		}
	}
	
	// �w�{���X�_�̕ǏR��
	if((kicktype[player]) && (blk[player] == 0) && ((bak == 0) || (bak == 2))) {
		for(i = 0; i <= IsBig[player] * 2; i++) {
			temp = 0;
			
			if(judgeBlock(player, bx[player] - 1 - i, by[player], blk[player], bak) == 0) {
				temp = -1 - i;
			} else if(judgeBlock(player, bx[player] + 1 + i, by[player], blk[player], bak) == 0) {
				temp = 1 + i;
			} else if(judgeBlock(player, bx[player] + 2 + i, by[player], blk[player], bak) == 0) {
				temp = 2 + i;
			}
			
			// �ǏR����s
			if(temp) {
				bx[player] = bx[player] + temp;
				param[0] = 1;
				return;
			}
		}
	}
	
	// �w�{���X�_�̏��R��i1�񂾂��A�ڒn���Ă���ꍇ�̂݁j
	if( (kicktype[player]) && (blk[player] == 0) && ((bak == 1) || (bak == 3)) && (!kickc[player]) && 
	    (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0) )
	{
		for(i = 0; i <= IsBig[player] * 2; i++) {
			temp = 0;
			
			if(judgeBlock(player, bx[player], by[player] - 1 - i, blk[player], bak) == 0) {
				temp = -1 - i;
			} else if(judgeBlock(player, bx[player], by[player] - 2 - i, blk[player], bak) == 0) {
				temp = -2 - i;
			}
			
			// ���R����s
			if(temp) {
				by[player] = by[player] + temp;
				kickc[player]++;
				bk[player] = 0;
				bfallflag[player] = 1;
				param[0] = 1;
				return;
			}
		}
	}
}

// �u���b�N�ړ���
void arsBlockMove(int player) {
	int temp;
	
	// NEXT�x��������
	if(spawntype[player]) {
		if(!IsBig[player]) temp = arsNDelay[blk[player]];
		else temp = arsBNDelay[blk[player]];
		
		if(by[player] >= temp) ndelay[player] = 1;
	}
}

// �u���b�N�o����
void arsBlockSpawn(int player) {
	// �o���ʒu��ݒ�
	if(!IsBig[player]) {
		// ��r�b�O
		block_init_x_pos[player] = arsSpawnX[blk[player]];
		
		if(!spawntype[player])
			block_init_y_pos[player] = arsSpawnYU[blk[player]];
		else
			block_init_y_pos[player] = arsSpawnYA[blk[player]];
	} else {
		// �r�b�O
		if(!BigMove[player])
			block_init_x_pos[player] = arsBSpawnX[blk[player]];
		else
			block_init_x_pos[player] = arsBSpawnX2[blk[player]];
		
		if(!spawntype[player])
			block_init_y_pos[player] = arsBSpawnYU[blk[player]];
		else
			block_init_y_pos[player] = arsBSpawnYA[blk[player]];
	}
}

// 3-CORNER�^�C�v��T-SPIN����
void arsIsTSpin3Corner(int player, int *param) {
	int i, cnt, tx[4], ty[4];
	int tmp_x, tmp_y;
	
	// ����p���΍��W��ݒ�
	if(IsBig[player]) {
		tx[0] = 1;
		ty[0] = 1;
		tx[1] = 4;
		ty[1] = 1;
		tx[2] = 1;
		ty[2] = 4;
		tx[3] = 4;
		ty[3] = 4;
	} else {
		tx[0] = 0;
		ty[0] = 0;
		tx[1] = 2;
		ty[1] = 0;
		tx[2] = 0;
		ty[2] = 2;
		tx[3] = 2;
		ty[3] = 2;
	}
	
	// ���菈��
	cnt = 0;
	
	for(i = 0; i < 4; i++) {
		tmp_x = bx[player] + tx[i];
		tmp_y = by[player] + ty[i];
		
		// T��������̏ꍇ
		// ���@��
		// �@��
		// ������
		// ����Ȕ���ɂȂ�Ȃ��悤��Y���W���P���炷
		if(rt[player] == 2) tmp_y = tmp_y + 1 + IsBig[player];
		
		if(tmp_y >= 0) {
			if(getFieldBlock(player, tmp_x, tmp_y) != 0) {
				cnt++;
				
				if(cnt >= 3) {
					param[0] = 1;
					return;
				}
			}
		}
	}
}

// �ݒ���
void arsSetting(int player, int *param) {
	int i, temp, cursor, move;
	cursor = 0;
	
	// �ݒ��ǂݍ���
	if(arsLoadConfig(player) == 0) {
		arsMakeDefaultSetting(player);
		arsMakeDefaultPreset();
	}
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		sprintf(string[0], "%dP ARS OPTIONS", player + 1);
		printFontGrid(1, 1, string[0], 2 - player);
		
		if(cursor <= 25) {
			printFontGrid(31, 1, "PAGE 1/2", 6);
			
			// �J�[�\���\��
			printFontGrid(1, 3 + cursor, "b", 7);
			
			// ���j���[�\��
			printFontGrid(2,  3, "EXT-ROTATE",       7 * (cursor ==  0));
			printFontGrid(2,  4, "LOCK RESET",       7 * (cursor ==  1));
			printFontGrid(2,  5, "ROTATE LIMIT",     7 * (cursor ==  2));
			printFontGrid(2,  6, "MOVE LIMIT",       7 * (cursor ==  3));
			printFontGrid(2,  7, "BLOCK GRAPHICS",   7 * (cursor ==  4));
			printFontGrid(2,  8, "ARE",              7 * (cursor ==  5));
			printFontGrid(2,  9, "LOCK BY UP KEY",   7 * (cursor ==  6));
			printFontGrid(2, 10, "LOCK BY DOWN KEY", 7 * (cursor ==  7));
			printFontGrid(2, 11, "ROTATE REVERSE",   7 * (cursor ==  8));
			printFontGrid(2, 12, "SOFT DROP SPEED",  7 * (cursor ==  9));
			if(!english) printFontGrid(2, 13, "MAX YOKOTAME", 7 * (cursor == 10));
			else printFontGrid(2, 13, "MAX DAS", 7 * (cursor == 10));
			printFontGrid(2, 14, "INIT LR MOVE",     7 * (cursor == 11));
			printFontGrid(2, 15, "[] BACKGROUND",    7 * (cursor == 12));
			printFontGrid(2, 16, "I BLOCK COLOR",    7 * (cursor == 13));
			printFontGrid(2, 17, "L BLOCK COLOR",    7 * (cursor == 14));
			printFontGrid(2, 18, "O BLOCK COLOR",    7 * (cursor == 15));
			printFontGrid(2, 19, "Z BLOCK COLOR",    7 * (cursor == 16));
			printFontGrid(2, 20, "T BLOCK COLOR",    7 * (cursor == 17));
			printFontGrid(2, 21, "J BLOCK COLOR",    7 * (cursor == 18));
			printFontGrid(2, 22, "S BLOCK COLOR",    7 * (cursor == 19));
			printFontGrid(2, 23, "INITIAL ROTATE",   7 * (cursor == 20));
			printFontGrid(2, 24, "INITIAL HOLD",     7 * (cursor == 21));
			printFontGrid(2, 25, "ENABLE WALLKICK",  7 * (cursor == 22));
			printFontGrid(2, 26, "SELF LOCK SOUND",  7 * (cursor == 23));
			printFontGrid(2, 27, "LOCK FLASH",       7 * (cursor == 24));
			printFontGrid(2, 28, "REPEAT DELAY",     7 * (cursor == 25));
			
			// �ݒ�l�\��
			if(!arsExtRotate[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 3, string[0], 7 * (cursor == 0));
			
			if(!arsLockReset[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 4, string[0], 7 * (cursor == 1));
			
			if(!arsRotLimit[player]) sprintf(string[0], "INFINITE");
			else sprintf(string[0], "%d", arsRotLimit[player]);
			printFontGrid(22, 5, string[0], 7 * (cursor == 2));
			
			if(!arsMoveLimit[player]) sprintf(string[0], "INFINITE");
			else sprintf(string[0], "%d", arsMoveLimit[player]);
			printFontGrid(22, 6, string[0], 7 * (cursor == 3));
			
			sprintf(string[0], "%d", arsGraphics[player]);
			printFontGrid(22, 7, string[0], 7 * (cursor == 4));
			
			if(arsAre[player] == 0) sprintf(string[0], "OFF");
			else if(arsAre[player] == 1) sprintf(string[0], "ON");
			else sprintf(string[0], "ON (ENABLE SKIP)");
			printFontGrid(22, 8, string[0], 7 * (cursor == 5));
			
			if(arsLockUp[player] == 0) sprintf(string[0], "OFF");
			else if(arsLockUp[player] == 1) sprintf(string[0], "ON");
			else sprintf(string[0], "NO HARD DROP");
			printFontGrid(22, 9, string[0], 7 * (cursor == 6));
			
			if(arsLockDown[player] == 0) sprintf(string[0], "OFF");
			else if(arsLockDown[player] == 1) sprintf(string[0], "ON");
			else if(arsLockDown[player] == 2) sprintf(string[0], "SLOW LOCK");
			else if(arsLockDown[player] == 3) sprintf(string[0], "FAST LOCK");
			else if(arsLockDown[player] == 4) sprintf(string[0], "1G OR FASTER");
			else if(arsLockDown[player] == 5) sprintf(string[0], "PUSH AGAIN TO LOCK");
			else sprintf(string[0], "NO SOFT DROP");
			printFontGrid(22, 10, string[0], 7 * (cursor == 7));
			
			if(arsRotReverse[player] == 0) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 11, string[0], 7 * (cursor == 8));
			
			if(arsSoftSpeed[player] % 2 == 0) sprintf(string[0], "e %d.5", arsSoftSpeed[player] / 2);
			else sprintf(string[0], "e %d.0", (arsSoftSpeed[player] + 1) / 2);
			printFontGrid(22, 12, string[0], 7 * (cursor == 9));
			
			if(arsMaxWaitt[player] >= 99) sprintf(string[0], "INFINITE");
			else sprintf(string[0], "%d", arsMaxWaitt[player]);
			printFontGrid(22, 13, string[0], 7 * (cursor == 10));
			
			if(!arsFastlrmove[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 14, string[0], 7 * (cursor == 11));
			
			if(arsOBlkBG[player] == 0) sprintf(string[0], "OFF");
			else if(arsOBlkBG[player] == 1) sprintf(string[0], "BLACK");
			else sprintf(string[0], "WHITE");
			printFontGrid(22, 15, string[0], 7 * (cursor == 12));
			
			for(i = 0; i < 7; i++) printFontGrid(22, 16 + i, arsStrColor[arsColor[player * 7 + i]], 7 * (cursor == 13 + i));
			
			if(!arsInitRotate[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 23, string[0], 7 * (cursor == 20));
			
			if(!arsInitHold[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 24, string[0], 7 * (cursor == 21));
			
			if(!arsEnableKick[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 25, string[0], 7 * (cursor == 22));
			
			if(!arsSelfLockSound[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 26, string[0], 7 * (cursor == 23));
			
			sprintf(string[0], "%d FRAMES", arsLockflash[player]);
			printFontGrid(22, 27, string[0], 7 * (cursor == 24));
			
			if(!arsRepeatDelay[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "%d", arsRepeatDelay[player]);
			printFontGrid(22, 28, string[0], 7 * (cursor == 25));
		} else {
			printFontGrid(31, 1, "PAGE 2/2", 6);
			
			// �J�[�\���\��
			printFontGrid(1, 3 + cursor - 26, "b", 7);
			
			// ���j���[�\��
			printFontGrid(2,  3, "[SAVE PRESET]",    7 * (cursor == 26));
			printFontGrid(2,  4, "[LOAD PRESET]",    7 * (cursor == 27));
			
			// �ݒ�l�\��
			sprintf(string[0], "PRESET NO.%d", arsLastPresetNo[player] + 1);
			printFontGrid(22, 3, string[0], 7 * (cursor >= 26));
		}
		
		// �J�[�\���ړ�
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 27;
			if(cursor > 27) cursor = 0;
		}
		
		// �l��ύX
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) arsExtRotate[player] = !arsExtRotate[player];
			if(cursor == 1) arsLockReset[player] = !arsLockReset[player];
			if(cursor == 2) {
				arsRotLimit[player] = arsRotLimit[player] + move;
				if(arsRotLimit[player] < 0) arsRotLimit[player] = 128;
				if(arsRotLimit[player] > 128) arsRotLimit[player] = 0;
			}
			if(cursor == 3) {
				arsMoveLimit[player] = arsMoveLimit[player] + move;
				if(arsMoveLimit[player] < 0) arsMoveLimit[player] = 128;
				if(arsMoveLimit[player] > 128) arsMoveLimit[player] = 0;
			}
			if(cursor == 4) {
				arsGraphics[player] = arsGraphics[player] + move;
				if(arsGraphics[player] < 0) arsGraphics[player] = 7;
				if(arsGraphics[player] > 7) arsGraphics[player] = 0;
			}
			if(cursor == 5) {
				arsAre[player] = arsAre[player] + move;
				if(arsAre[player] < 0) arsAre[player] = 2;
				if(arsAre[player] > 2) arsAre[player] = 0;
			}
			if(cursor == 6) {
				arsLockUp[player] = arsLockUp[player] + move;
				if(arsLockUp[player] < 0) arsLockUp[player] = 2;
				if(arsLockUp[player] > 2) arsLockUp[player] = 0;
			}
			if(cursor == 7) {
				arsLockDown[player] = arsLockDown[player] + move;
				if(arsLockDown[player] < 0) arsLockDown[player] = 6;
				if(arsLockDown[player] > 6) arsLockDown[player] = 0;
			}
			if(cursor == 8) arsRotReverse[player] = !arsRotReverse[player];
			if(cursor == 9) {
				arsSoftSpeed[player] = arsSoftSpeed[player] + move;
				if(arsSoftSpeed[player] < 0) arsSoftSpeed[player] = 39;
				if(arsSoftSpeed[player] > 39) arsSoftSpeed[player] = 0;
			}
			if(cursor == 10) {
				arsMaxWaitt[player] = arsMaxWaitt[player] + move;
				if(arsMaxWaitt[player] < 0) arsMaxWaitt[player] = 99;
				if(arsMaxWaitt[player] > 99) arsMaxWaitt[player] = 0;
			}
			if(cursor == 11) arsFastlrmove[player] = !arsFastlrmove[player];
			if(cursor == 12) {
				arsOBlkBG[player] = arsOBlkBG[player] + move;
				if(arsOBlkBG[player] < 0) arsOBlkBG[player] = 2;
				if(arsOBlkBG[player] > 2) arsOBlkBG[player] = 0;
			}
			if((cursor >= 13) && (cursor <= 19)) {
				temp = cursor - 13;
				arsColor[player * 7 + temp] = arsColor[player * 7 + temp] + move;
				if(arsColor[player * 7 + temp] < 0) arsColor[player * 7 + temp] = 7;
				if(arsColor[player * 7 + temp] > 7) arsColor[player * 7 + temp] = 0;
			}
			if(cursor == 20) arsInitRotate[player] = !arsInitRotate[player];
			if(cursor == 21) arsInitHold[player] = !arsInitHold[player];
			if(cursor == 22) arsEnableKick[player] = !arsEnableKick[player];
			if(cursor == 23) arsSelfLockSound[player] = !arsSelfLockSound[player];
			if(cursor == 24) {
				arsLockflash[player] = arsLockflash[player] + move;
				if(arsLockflash[player] < 0) arsLockflash[player] = 99;
				if(arsLockflash[player] > 99) arsLockflash[player] = 0;
			}
			if(cursor == 25) {
				arsRepeatDelay[player] = arsRepeatDelay[player] + move;
				if(arsRepeatDelay[player] < 0) arsRepeatDelay[player] = 99;
				if(arsRepeatDelay[player] > 99) arsRepeatDelay[player] = 0;
			}
			if(cursor >= 26) {
				arsLastPresetNo[player] = arsLastPresetNo[player] + move;
				if(arsLastPresetNo[player] < 0) arsLastPresetNo[player] = 4;
				if(arsLastPresetNo[player] > 4) arsLastPresetNo[player] = 0;
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
			PlaySE(se_kettei);
			
			if(cursor == 26) {
				arsSavePreset(player, arsLastPresetNo[player]);
				arsSaveConfig(player);
			} else if(cursor == 27) {
				arsLoadPreset(player, arsLastPresetNo[player]);
			} else {
				arsSaveConfig(player);
				return;
			}
		}
	}
}

// ���v���C�ڍ�
void arsReplayDetail(int number) {
	int i;
	
	printFontGrid(1, 4, "EXT-ROTATE", 0);
	if(!saveBuf[207]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 4, string[0], 0);
	
	printFontGrid(1, 5, "LOCK RESET", 0);
	if(!saveBuf[208]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "ROTATE LIMIT", 0);
	if(!saveBuf[209]) sprintf(string[0], "INFINITE");
	else sprintf(string[0], "%d", saveBuf[209]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "MOVE LIMIT", 0);
	if(!saveBuf[210]) sprintf(string[0], "INFINITE");
	else sprintf(string[0], "%d", saveBuf[210]);
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 8, "BLOCK GRAPHICS", 0);
	sprintf(string[0], "%d", saveBuf[211]);
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "ARE", 0);
	if(saveBuf[212] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[212] == 1) sprintf(string[0], "ON");
	else sprintf(string[0], "ON (ENABLE SKIP)");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "LOCK BY UP KEY", 0);
	if(saveBuf[213] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[213] == 1) sprintf(string[0], "ON");
	else sprintf(string[0], "NO HARD DROP");
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "LOCK BY DOWN KEY", 0);
	if(saveBuf[214] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[214] == 1) sprintf(string[0], "ON");
	else if(saveBuf[214] == 2) sprintf(string[0], "SLOW LOCK");
	else if(saveBuf[214] == 3) sprintf(string[0], "FAST LOCK");
	else if(saveBuf[214] == 4) sprintf(string[0], "1G OR FASTER");
	else if(saveBuf[214] == 5) sprintf(string[0], "PUSH AGAIN TO LOCK");
	else sprintf(string[0], "NO SOFT DROP");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "ROTATE REVERSE", 0);
	if(!saveBuf[215]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 12, string[0], 0);
	
	printFontGrid(1, 13, "SOFT DROP SPEED", 0);
	if(saveBuf[216] % 2 == 0) sprintf(string[0], "e %d.5", saveBuf[216] / 2);
	else sprintf(string[0], "e %d.0", (saveBuf[216] + 1) / 2);
	printFontGrid(22, 13, string[0], 0);
	
	if(!english) printFontGrid(1, 14, "MAX YOKOTAME", 0);
	else printFontGrid(1, 14, "MAX DAS", 0);
	if(saveBuf[217] >= 99) sprintf(string[0], "INFINITE");
	else sprintf(string[0], "%d", saveBuf[217]);
	printFontGrid(22, 14, string[0], 0);
	
	printFontGrid(1, 15, "INIT LR MOVE", 0);
	if(!saveBuf[218]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 15, string[0], 0);
	
	printFontGrid(1, 16, "[] BACKGROUND", 0);
	if(saveBuf[219] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[219] == 1) sprintf(string[0], "BLACK");
	else sprintf(string[0], "WHITE");
	printFontGrid(22, 16, string[0], 0);
	
	printFontGrid(1, 17, "BLOCK COLORS", 0);
	for(i = 0; i < 7; i++) {
		sprintf(string[0], "%d", saveBuf[222 + i]);
		printFontGrid(22 + i, 17, string[0], 0);
	}
	
	printFontGrid(1, 18, "INITIAL ROTATE", 0);
	if(!saveBuf[229]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 18, string[0], 0);
	
	printFontGrid(1, 19, "INITIAL HOLD", 0);
	if(!saveBuf[230]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 19, string[0], 0);
	
	printFontGrid(1, 20, "ENABLE WALLKICK", 0);
	if(!saveBuf[231]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 20, string[0], 0);
	
	printFontGrid(1, 21, "SELF LOCK SOUND", 0);
	if(!saveBuf[232]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 21, string[0], 0);
	
	printFontGrid(1, 22, "LOCK FLASH", 0);
	sprintf(string[0], "%d FRAMES", saveBuf[233]);
	printFontGrid(22, 22, string[0], 0);
	
	printFontGrid(1, 22, "REPEAT DELAY", 0);
	if(!saveBuf[244]) sprintf(string[0], "OFF");
	else sprintf(string[0], "%d", saveBuf[244]);
	printFontGrid(22, 22, string[0], 0);
}

// �ݒ��ۑ�
void arsSaveConfig(int player) {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x43535241;
	saveBuf[3] = 0x32764746;
	
	// �ݒ���e
	saveBuf[4] = arsExtRotate[player];
	saveBuf[5] = arsLockReset[player];
	saveBuf[6] = arsRotLimit[player];
	saveBuf[7] = arsMoveLimit[player];
	saveBuf[8] = arsGraphics[player];
	saveBuf[9] = arsAre[player];
	saveBuf[10] = arsLockUp[player];
	saveBuf[11] = arsLockDown[player];
	saveBuf[12] = arsRotReverse[player];
	saveBuf[13] = arsSoftSpeed[player];
	saveBuf[14] = arsMaxWaitt[player];
	saveBuf[15] = arsFastlrmove[player];
	saveBuf[16] = arsOBlkBG[player];
	for(i = 0; i < 7; i++) saveBuf[17 + i] = arsColor[player * 7 + i];
	saveBuf[24] = arsInitRotate[player];
	saveBuf[25] = arsInitHold[player];
	saveBuf[26] = arsEnableKick[player];
	saveBuf[27] = arsSelfLockSound[player];
	saveBuf[28] = arsLockflash[player];
	saveBuf[29] = arsRepeatDelay[player];
	
	saveBuf[49] = arsLastPresetNo[player];
	for(i = 0; i < 30 * 5; i++) saveBuf[50 + i] = arsPreset[i];
	
	if(!player) SaveFile("config/ARS_CONFIG.SAV", &saveBuf, 200 * 4);
	else SaveFile("config/ARS_CONFIG_2P.SAV", &saveBuf, 200 * 4);
}

// �ݒ��ǂݍ���
int arsLoadConfig(int player) {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	if(!player) LoadFile("config/ARS_CONFIG.SAV", &saveBuf, 200 * 4);
	else LoadFile("config/ARS_CONFIG_2P.SAV", &saveBuf, 200 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x43535241) return 0;
	if(saveBuf[3] != 0x32764746) return 0;
	
	// �ݒ���e
	arsExtRotate[player] = saveBuf[4];
	arsLockReset[player] = saveBuf[5];
	arsRotLimit[player] = saveBuf[6];
	arsMoveLimit[player] = saveBuf[7];
	arsGraphics[player] = saveBuf[8];
	arsAre[player] = saveBuf[9];
	arsLockUp[player] = saveBuf[10];
	arsLockDown[player] = saveBuf[11];
	arsRotReverse[player] = saveBuf[12];
	arsSoftSpeed[player] = saveBuf[13];
	arsMaxWaitt[player] = saveBuf[14];
	arsFastlrmove[player] = saveBuf[15];
	arsOBlkBG[player] = saveBuf[16];
	for(i = 0; i < 7; i++) arsColor[player * 7 + i] = saveBuf[17 + i];
	arsInitRotate[player] = saveBuf[24];
	arsInitHold[player] = saveBuf[25];
	arsEnableKick[player] = saveBuf[26];
	arsSelfLockSound[player] = saveBuf[27];
	arsLockflash[player] = saveBuf[28];
	arsRepeatDelay[player] = saveBuf[29];
	
	arsLastPresetNo[player] = saveBuf[49];
	for(i = 0; i < 30 * 5; i++) arsPreset[i] = saveBuf[50 + i];
	
	return 1;
}

// �f�t�H���g�̐ݒ���쐬
void arsMakeDefaultSetting(int player) {
	arsExtRotate[player] = 1;		// �Ԃ̕ǏR�菰�R��
	arsLockReset[player] = 0;		// �Œ莞�ԃ��Z�b�g
	arsRotLimit[player] = 0;		// ��]����
	arsMoveLimit[player] = 0;		// �ړ�����
	arsGraphics[player] = 1;		// �O���t�B�b�N�ԍ�
	arsAre[player] = 1;				// �o���҂����Ԃ̗L��
	arsLockUp[player] = 0;			// ��ő��Œ�
	arsLockDown[player] = 1;		// ���ő��Œ�
	arsRotReverse[player] = 0;		// ��]�������t�]������
	arsSoftSpeed[player] = 1;		// �\�t�g�h���b�v�̑��x
	arsMaxWaitt[player] = 99;		// �ő剡����
	arsFastlrmove[player] = 0;		// ��s���ړ�
	arsOBlkBG[player] = 0;			// ����c�l�o�ꒆ�̔w�i
	arsInitRotate[player] = 1;		// ��s��]
	arsInitHold[player] = 1;		// ��s�z�[���h
	arsEnableKick[player] = 1;		// �ǏR��L��
	arsSelfLockSound[player] = 0;	// �����ŌŒ肳�����Ƃ��ɉ����o��
	arsLockflash[player] = 2;		// �u���b�N���Œ肳�����u�ԁA�u���b�N������t���[����
	arsRepeatDelay[player] = 0;		// RepeatDelay
	
	// �u���b�N�̐F
	arsColor[player * 7 + 0] = 1;
	arsColor[player * 7 + 1] = 2;
	arsColor[player * 7 + 2] = 3;
	arsColor[player * 7 + 3] = 4;
	arsColor[player * 7 + 4] = 5;
	arsColor[player * 7 + 5] = 6;
	arsColor[player * 7 + 6] = 7;
	
	// �v���Z�b�g�ԍ�
	arsLastPresetNo[player] = 0;
}

// �v���Z�b�g������
void arsMakeDefaultPreset() {
	int i;
	
	for(i = 0; i < 30 * 5; i++) arsPreset[i] = 0;
	
	// �v���Z�b�g1
	arsPreset[0 * 30 + 0] = 1;		// �Ԃ̕ǏR�菰�R��
	arsPreset[0 * 30 + 1] = 0;		// �Œ莞�ԃ��Z�b�g
	arsPreset[0 * 30 + 2] = 0;		// ��]����
	arsPreset[0 * 30 + 3] = 0;		// �ړ�����
	arsPreset[0 * 30 + 4] = 1;		// �O���t�B�b�N�ԍ�
	arsPreset[0 * 30 + 5] = 1;		// �o���҂����Ԃ̗L��
	arsPreset[0 * 30 + 6] = 0;		// ��ő��Œ�
	arsPreset[0 * 30 + 7] = 1;		// ���ő��Œ�
	arsPreset[0 * 30 + 8] = 0;		// ��]�������t�]������
	arsPreset[0 * 30 + 9] = 1;		// �\�t�g�h���b�v�̑��x
	arsPreset[0 * 30 + 10] = 99;	// �ő剡����
	arsPreset[0 * 30 + 11] = 0;		// ��s���ړ�
	arsPreset[0 * 30 + 12] = 0;		// ����c�l�o�ꒆ�̔w�i
	for(i = 0; i < 7; i++) arsPreset[0 * 30 + (13 + i)] = i + 1;
	arsPreset[0 * 30 + 20] = 1;		// ��s��]
	arsPreset[0 * 30 + 21] = 1;		// ��s�z�[���h
	arsPreset[0 * 30 + 22] = 1;		// �ǏR��L��
	arsPreset[0 * 30 + 23] = 0;		// �����ŌŒ肳�����Ƃ��ɉ����o��
	arsPreset[0 * 30 + 24] = 2;		// �u���b�N���Œ肳�����u�ԁA�u���b�N������t���[����
	arsPreset[0 * 30 + 25] = 0;		// RepeatDelay
	
	// �v���Z�b�g2
	arsPreset[1 * 30 + 0] = 0;
	arsPreset[1 * 30 + 1] = 0;
	arsPreset[1 * 30 + 2] = 0;
	arsPreset[1 * 30 + 3] = 0;
	arsPreset[1 * 30 + 4] = 0;
	arsPreset[1 * 30 + 5] = 1;
	arsPreset[1 * 30 + 6] = 0;
	arsPreset[1 * 30 + 7] = 1;
	arsPreset[1 * 30 + 8] = 0;
	arsPreset[1 * 30 + 9] = 1;
	arsPreset[1 * 30 + 10] = 99;
	arsPreset[1 * 30 + 11] = 0;
	arsPreset[1 * 30 + 12] = 0;
	for(i = 0; i < 7; i++) arsPreset[1 * 30 + (13 + i)] = i + 1;
	arsPreset[1 * 30 + 20] = 1;
	arsPreset[1 * 30 + 21] = 1;
	arsPreset[1 * 30 + 22] = 1;
	arsPreset[1 * 30 + 23] = 0;
	arsPreset[1 * 30 + 24] = 2;
	arsPreset[1 * 30 + 25] = 0;
	
	// �v���Z�b�g3
	arsPreset[2 * 30 + 0] = 1;
	arsPreset[2 * 30 + 1] = 1;
	arsPreset[2 * 30 + 2] = 128;
	arsPreset[2 * 30 + 3] = 128;
	arsPreset[2 * 30 + 4] = 1;
	arsPreset[2 * 30 + 5] = 1;
	arsPreset[2 * 30 + 6] = 1;
	arsPreset[2 * 30 + 7] = 0;
	arsPreset[2 * 30 + 8] = 0;
	arsPreset[2 * 30 + 9] = 0;
	arsPreset[2 * 30 + 10] = 99;
	arsPreset[2 * 30 + 11] = 0;
	arsPreset[2 * 30 + 12] = 0;
	arsPreset[2 * 30 + 13] = 5;
	arsPreset[2 * 30 + 14] = 2;
	arsPreset[2 * 30 + 15] = 3;
	arsPreset[2 * 30 + 16] = 1;
	arsPreset[2 * 30 + 17] = 7;
	arsPreset[2 * 30 + 18] = 6;
	arsPreset[2 * 30 + 19] = 4;
	arsPreset[2 * 30 + 20] = 1;
	arsPreset[2 * 30 + 21] = 1;
	arsPreset[2 * 30 + 22] = 1;
	arsPreset[2 * 30 + 23] = 1;
	arsPreset[2 * 30 + 24] = 2;
	arsPreset[2 * 30 + 25] = 0;
	
	// �v���Z�b�g4
	arsPreset[3 * 30 + 0] = 1;
	arsPreset[3 * 30 + 1] = 1;
	arsPreset[3 * 30 + 2] = 128;
	arsPreset[3 * 30 + 3] = 128;
	arsPreset[3 * 30 + 4] = 1;
	arsPreset[3 * 30 + 5] = 1;
	arsPreset[3 * 30 + 6] = 0;
	arsPreset[3 * 30 + 7] = 1;
	arsPreset[3 * 30 + 8] = 0;
	arsPreset[3 * 30 + 9] = 0;
	arsPreset[3 * 30 + 10] = 99;
	arsPreset[3 * 30 + 11] = 0;
	arsPreset[3 * 30 + 12] = 0;
	arsPreset[3 * 30 + 13] = 5;
	arsPreset[3 * 30 + 14] = 2;
	arsPreset[3 * 30 + 15] = 3;
	arsPreset[3 * 30 + 16] = 1;
	arsPreset[3 * 30 + 17] = 7;
	arsPreset[3 * 30 + 18] = 6;
	arsPreset[3 * 30 + 19] = 4;
	arsPreset[3 * 30 + 20] = 1;
	arsPreset[3 * 30 + 21] = 1;
	arsPreset[3 * 30 + 22] = 1;
	arsPreset[3 * 30 + 23] = 1;
	arsPreset[3 * 30 + 24] = 2;
	arsPreset[3 * 30 + 25] = 0;
}

// �v���Z�b�g��ۑ�
void arsSavePreset(int player, int number) {
	int i;
	
	arsPreset[number * 30 + 0] = arsExtRotate[player];
	arsPreset[number * 30 + 1] = arsLockReset[player];
	arsPreset[number * 30 + 2] = arsRotLimit[player];
	arsPreset[number * 30 + 3] = arsMoveLimit[player];
	arsPreset[number * 30 + 4] = arsGraphics[player];
	arsPreset[number * 30 + 5] = arsAre[player];
	arsPreset[number * 30 + 6] = arsLockUp[player];
	arsPreset[number * 30 + 7] = arsLockDown[player];
	arsPreset[number * 30 + 8] = arsRotReverse[player];
	arsPreset[number * 30 + 9] = arsSoftSpeed[player];
	arsPreset[number * 30 + 10] = arsMaxWaitt[player];
	arsPreset[number * 30 + 11] = arsFastlrmove[player];
	arsPreset[number * 30 + 12] = arsOBlkBG[player];
	for(i = 0; i < 7; i++) arsPreset[number * 30 + (13 + i)] = arsColor[player * 7 + i];
	arsPreset[number * 30 + 20] = arsInitRotate[player];
	arsPreset[number * 30 + 21] = arsInitHold[player];
	arsPreset[number * 30 + 22] = arsEnableKick[player];
	arsPreset[number * 30 + 23] = arsSelfLockSound[player];
	arsPreset[number * 30 + 24] = arsLockflash[player];
	arsPreset[number * 30 + 25] = arsRepeatDelay[player];
}

// �v���Z�b�g��ǂݍ���
void arsLoadPreset(int player, int number) {
	int i;
	
	arsExtRotate[player] = arsPreset[number * 30 + 0];
	arsLockReset[player] = arsPreset[number * 30 + 1];
	arsRotLimit[player] = arsPreset[number * 30 + 2];
	arsMoveLimit[player] = arsPreset[number * 30 + 3];
	arsGraphics[player] = arsPreset[number * 30 + 4];
	arsAre[player] = arsPreset[number * 30 + 5];
	arsLockUp[player] = arsPreset[number * 30 + 6];
	arsLockDown[player] = arsPreset[number * 30 + 7];
	arsRotReverse[player] = arsPreset[number * 30 + 8];
	arsSoftSpeed[player] = arsPreset[number * 30 + 9];
	arsMaxWaitt[player] = arsPreset[number * 30 + 10];
	arsFastlrmove[player] = arsPreset[number * 30 + 11];
	arsOBlkBG[player] = arsPreset[number * 30 + 12];
	for(i = 0; i < 7; i++) arsColor[player * 7 + i] = arsPreset[number * 30 + (13 + i)];
	arsInitRotate[player] = arsPreset[number * 30 + 20];
	arsInitHold[player] = arsPreset[number * 30 + 21];
	arsEnableKick[player] = arsPreset[number * 30 + 22];
	arsSelfLockSound[player] = arsPreset[number * 30 + 23];
	arsLockflash[player] = arsPreset[number * 30 + 24];
	arsRepeatDelay[player] = arsPreset[number * 30 + 25];
}
