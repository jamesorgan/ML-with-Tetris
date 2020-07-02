//DT��T ROTATION SYSTEM
//prefix:drs

// DRS �u���b�N�f�[�^
int drsBlkDataX[7 * 4 * 4] =	// ���j�b�g���\������u���b�N�̑��΂w�ʒu(7���/4�p�x/4�u���b�N)
{
	0, 1, 2, 3, 		2, 2, 2, 2, 		3, 2, 1, 0, 		1, 1, 1, 1,	// I
	1, 0, 0, 2, 		1, 0, 1, 1, 		1, 2, 2, 0, 		1, 2, 1, 1,	// L
	1, 2, 2, 1, 		2, 2, 1, 1, 		2, 1, 1, 2, 		1, 1, 2, 2,	// O
	1, 0, 1, 2, 		2, 2, 1, 1, 		1, 2, 1, 0, 		0, 0, 1, 1,	// Z
	1, 0, 1, 2, 		1, 1, 0, 1, 		1, 2, 1, 0, 		1, 1, 2, 1,	// T
	1, 0, 2, 2, 		1, 1, 1, 0, 		1, 2, 0, 0, 		1, 1, 1, 2,	// J
	1, 2, 1, 0, 		2, 2, 1, 1, 		1, 0, 1, 2, 		0, 0, 1, 1,	// S
};

int drsBlkDataY[7 * 4 * 4] =	// ���j�b�g���\������u���b�N�̑��΂x�ʒu(7���/4�p�x/4�u���b�N)
{
	2, 2, 2, 2, 		0, 1, 2, 3, 		2, 2, 2, 2, 		3, 2, 1, 0,	// I
	1, 2, 1, 1, 		1, 0, 0, 2, 		2, 1, 2, 2, 		1, 2, 2, 0,	// L
	1, 1, 2, 2, 		1, 2, 2, 1, 		2, 2, 1, 1, 		2, 1, 1, 2,	// O
	1, 1, 2, 2, 		1, 0, 1, 2, 		2, 2, 1, 1, 		1, 2, 1, 0,	// Z
	1, 1, 2, 1, 		1, 0, 1, 2, 		2, 2, 1, 2, 		1, 2, 1, 0,	// T
	1, 1, 1, 2, 		1, 0, 2, 2, 		2, 2, 2, 1, 		1, 2, 0, 0,	// J
	1, 1, 2, 2, 		1, 2, 1, 0, 		2, 2, 1, 1, 		1, 0, 1, 2,	// S
};

// �u���b�N�o���ʒu�i�ʏ�j
int drsSpawnX[7]   = { 3, 3, 3, 3, 3, 3, 3};	// X���W
int drsSpawnYU[7]  = { 0, 1, 1, 1, 1, 1, 1};	// Y���W�i�g���o���j
int drsSpawnYA[7]  = {-1,-1,-1,-1,-1,-1,-1};	// Y���W�i�g�O�o���j
int drsNDelay[7]   = {-1, 0, 0, 0, 0, 0, 0};	// �g�O�o����NEXT�x������������Y���W

// �u���b�N�o���ʒu�i�r�b�O�j
int drsBSpawnX[7]  = { 1, 2, 1, 2, 2, 2, 2};	// X���W�i1�}�X�ړ��j
int drsBSpawnX2[7] = { 2, 2, 2, 2, 2, 2, 2};	// X���W�i2�}�X�ړ��j
int drsBSpawnYU[7] = {-2, 0, 0, 0, 0, 0, 0};	// Y���W�i�g���o���j
int drsBSpawnYA[7] = {-3,-2,-2,-2,-2,-2,-2};	// Y���W�i�g�O�o���j
int drsBNDelay[7]  = {-3,-1,-1,-1,-1,-1,-1};	// �g�O�o����NEXT�x������������Y���W

// �u���b�N�̐F�ƕ\����
int drsColor[7 * 2];
str drsStrColor[8] = {"GRAY", "RED", "ORANGE", "YELLOW", "GREEN", "CYAN", "BLUE", "PURPLE"};

int drsRuleNumber = -1;		// ���[���ԍ�

int drsExtRotate[2];		// �Ԃ̕ǏR�菰�R��
int drsLockReset[2];		// �Œ莞�ԃ��Z�b�g
int drsRotLimit[2];			// ��]����
int drsMoveLimit[2];		// �ړ�����
int drsGraphics[2];			// �O���t�B�b�N�ԍ�
int drsAre[2];				// �o���҂����Ԃ̗L��
int drsLockUp[2];			// ��ő��Œ�
int drsLockDown[2];			// ���ő��Œ�
int drsRotReverse[2];		// ��]�������t�]������
int drsSoftSpeed[2];		// �\�t�g�h���b�v�̑��x
int drsMaxWaitt[2];			// �ő剡����
int drsFastlrmove[2];		// ��s���ړ�
int drsOBlkBG[2];			// ����c�l�o�ꒆ�̔w�i
int drsInitRotate[2];		// ��s��]
int drsInitHold[2];			// ��s�z�[���h
int drsEnableKick[2];		// �ǏR��L��
int drsSelfLockSound[2];	// �����ŌŒ肳�����Ƃ��ɉ����o��
int drsLockflash[2];		// �u���b�N���Œ肳�����u�ԁA�u���b�N������t���[����
int drsRepeatDelay[2];		// RepeatDelay

int drsPreset[30 * 5];		// �v���Z�b�g
int drsLastPresetNo[2];		// �Ō�ɑI�������v���Z�b�g�ԍ�

// �C�x���g�������ɌĂ΂��
void drsPluginEvent(int player, int event, int *param) {
	// ���[����DRS����Ȃ�������߂�i���[����o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (rots[player] != drsRuleNumber)) return;
	
	if(event == 0) {
		drsRuleNumber = addRulePlugin("DRS");	// ���[����o�^����
	} else if(event == 8) {
		drsBlockMove(player);	// �u���b�N�ړ���
	} else if(event == 9) {
		drsWallKick(player, param);	// �ǏR��
	} else if(event == 16) {
		drsSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		drsPlayerInitial(player);	// �Q�[���J�n�O�̏�����
	} else if(event == 19) {
		drsBlockSpawn(player);	// �u���b�N�o����
	} else if(event == 54) {
		drsReplayDetail(param[0]);	// ���v���C�ڍ�
	} else if(event == 58) {
		drsIsTSpin3Corner(player, param);	// 3-CORNER�^�C�v��T-SPIN����
	}
}

// �Q�[���J�n�O�̏�����
void drsPlayerInitial(int player) {
	int i;
	
	// �u���b�N�f�[�^���R�s�[
	for(i = 0; i < 112; i++) {
		blkDataX[player * 112 + i] = drsBlkDataX[i];
		blkDataY[player * 112 + i] = drsBlkDataY[i];
	}
	makeBlockLinkData(player); // �u���b�N�̌q����f�[�^����������
	
	// NEXT2�ȍ~�̕\���ł͖_�̈ʒu�����炷
	next_s_offset[player * 7 + 0] = -4;
	
	// �ݒ�𔽉f������
	kicktype[player] = drsExtRotate[player];
	lockreset[player] = drsLockReset[player];
	rotlimit[player] = drsRotLimit[player];
	movelimit[player] = drsMoveLimit[player];
	blockgraphics[player] = drsGraphics[player];
	are[player] = drsAre[player];
	lock_up[player] = drsLockUp[player];
	lock_down[player] = drsLockDown[player];
	rot_reverse[player] = drsRotReverse[player];
	softspeed[player] = drsSoftSpeed[player];
	max_waitt[player] = drsMaxWaitt[player];
	fastlrmove[player] = drsFastlrmove[player];
	oblk_bg[player] = drsOBlkBG[player];
	for(i = 0; i < 7; i++) blockcolor[player * 7 + i] = drsColor[player * 7 + i];
	initial_rotate[player] = drsInitRotate[player];
	initial_hold[player] = drsInitHold[player];
	enable_wallkick[player] = drsEnableKick[player];
	self_lock_sound[player] = drsSelfLockSound[player];
	lockflash[player] = drsLockflash[player];
	RepeatDelay[player] = drsRepeatDelay[player];
}

// �ǏR��
void drsWallKick(int player, int *param) {
	int i, temp, bak, move, hosei_type, y_hosei;
	bak = param[1];
	move = param[2];
	
	// �␳�^�C�v�����߂�i���΂̃{�^���������Ă���΃^�C�v�t�]�j
	if(move > 0)
		hosei_type = 1 - 0 * getPressState(player, 4);	// R
	else
		hosei_type = 0 + 1 * getPressState(player, 5);	// L
	
	temp = 0;
	y_hosei = 0;
	
	for(i = 0; i <= IsBig[player]; i++) {
		// ���D�� �D��x�̒Ⴂ�ړ����璲�ׂ�
		if(!hosei_type) {
			// �E��
			if(judgeBlock(player, bx[player] + 1 + i, by[player] + 1 + i, blk[player], bak) == 0) {
				temp = 1 + i;
				y_hosei = 1 + i;
			}
			// ����
			if(judgeBlock(player, bx[player] - 1 - i, by[player] + 1 + i, blk[player], bak) == 0) {
				temp = -1 - i;
				y_hosei = 1 + i;
			}
			// ��
			if(judgeBlock(player, bx[player]        , by[player] + 1 + i, blk[player], bak) == 0) {
				temp = 0;
				y_hosei = 1 + i;
			}
			// �E
			if(judgeBlock(player, bx[player] + 1 + i, by[player]        , blk[player], bak) == 0) {
				temp = 1 + i;
				y_hosei = 0;
			}
			// ��
			if(judgeBlock(player, bx[player] - 1 - i, by[player]        , blk[player], bak) == 0) {
				temp = -1 - i;
				y_hosei = 0;
			}
		}
		
		// �E�D��
		if(hosei_type) {
			// ����
			if(judgeBlock(player, bx[player] - 1 - i, by[player] + 1 + i, blk[player], bak) == 0) {
				temp = -1 - i;
				y_hosei = 1 + i;
			}
			// �E��
			if(judgeBlock(player, bx[player] + 1 + i, by[player] + 1 + i, blk[player], bak) == 0) {
				temp = 1 + i;
				y_hosei = 1 + i;
			}
			// ��
			if(judgeBlock(player, bx[player]        , by[player] + 1 + i, blk[player], bak) == 0) {
				temp = 0;
				y_hosei = 1 + i;
			}
			// ��
			if(judgeBlock(player, bx[player] - 1 - i, by[player]        , blk[player], bak) == 0) {
				temp = -1 - i;
				y_hosei = 0;
			}
			// �E
			if(judgeBlock(player, bx[player] + 1 + i, by[player]        , blk[player], bak) == 0) {
				temp = 1 + i;
				y_hosei = 0;
			}
		}
		
		// �ǏR����s
		if(temp || y_hosei) {
			bx[player] = bx[player] + temp;
			
			if(y_hosei) {
				PlaySE(se_kon);
				by[player] = by[player] + y_hosei;
				bk[player] = 0;		// �Œ莞�ԃ��Z�b�g
			}
			
			param[0] = 1;
			return;
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
void drsBlockMove(int player) {
	int temp;
	
	// NEXT�x��������
	if(spawntype[player]) {
		if(!IsBig[player]) temp = drsNDelay[blk[player]];
		else temp = drsBNDelay[blk[player]];
		
		if(by[player] >= temp) ndelay[player] = 1;
	}
}

// �u���b�N�o����
void drsBlockSpawn(int player) {
	// �o���ʒu��ݒ�
	if(!IsBig[player]) {
		// ��r�b�O
		block_init_x_pos[player] = drsSpawnX[blk[player]];
		
		if(!spawntype[player])
			block_init_y_pos[player] = drsSpawnYU[blk[player]];
		else
			block_init_y_pos[player] = drsSpawnYA[blk[player]];
	} else {
		// �r�b�O
		if(!BigMove[player])
			block_init_x_pos[player] = drsBSpawnX[blk[player]];
		else
			block_init_x_pos[player] = drsBSpawnX2[blk[player]];
		
		if(!spawntype[player])
			block_init_y_pos[player] = drsBSpawnYU[blk[player]];
		else
			block_init_y_pos[player] = drsBSpawnYA[blk[player]];
	}
}

// 3-CORNER�^�C�v��T-SPIN����
void drsIsTSpin3Corner(int player, int *param) {
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
void drsSetting(int player, int *param) {
	int i, temp, cursor, move;
	cursor = 0;
	
	// �ݒ��ǂݍ���
	if(drsLoadConfig(player) == 0) {
		drsMakeDefaultSetting(player);
		drsMakeDefaultPreset();
	}
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		sprintf(string[0], "%dP DRS OPTIONS", player + 1);
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
			if(!drsExtRotate[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 3, string[0], 7 * (cursor == 0));
			
			if(!drsLockReset[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 4, string[0], 7 * (cursor == 1));
			
			if(!drsRotLimit[player]) sprintf(string[0], "INFINITE");
			else sprintf(string[0], "%d", drsRotLimit[player]);
			printFontGrid(22, 5, string[0], 7 * (cursor == 2));
			
			if(!drsMoveLimit[player]) sprintf(string[0], "INFINITE");
			else sprintf(string[0], "%d", drsMoveLimit[player]);
			printFontGrid(22, 6, string[0], 7 * (cursor == 3));
			
			sprintf(string[0], "%d", drsGraphics[player]);
			printFontGrid(22, 7, string[0], 7 * (cursor == 4));
			
			if(drsAre[player] == 0) sprintf(string[0], "OFF");
			else if(drsAre[player] == 1) sprintf(string[0], "ON");
			else sprintf(string[0], "ON (ENABLE SKIP)");
			printFontGrid(22, 8, string[0], 7 * (cursor == 5));
			
			if(drsLockUp[player] == 0) sprintf(string[0], "OFF");
			else if(drsLockUp[player] == 1) sprintf(string[0], "ON");
			else sprintf(string[0], "NO HARD DROP");
			printFontGrid(22, 9, string[0], 7 * (cursor == 6));
			
			if(drsLockDown[player] == 0) sprintf(string[0], "OFF");
			else if(drsLockDown[player] == 1) sprintf(string[0], "ON");
			else if(drsLockDown[player] == 2) sprintf(string[0], "SLOW LOCK");
			else if(drsLockDown[player] == 3) sprintf(string[0], "FAST LOCK");
			else if(drsLockDown[player] == 4) sprintf(string[0], "1G OR FASTER");
			else if(drsLockDown[player] == 5) sprintf(string[0], "PUSH AGAIN TO LOCK");
			else sprintf(string[0], "NO SOFT DROP");
			printFontGrid(22, 10, string[0], 7 * (cursor == 7));
			
			if(drsRotReverse[player] == 0) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 11, string[0], 7 * (cursor == 8));
			
			if(drsSoftSpeed[player] % 2 == 0) sprintf(string[0], "e %d.5", drsSoftSpeed[player] / 2);
			else sprintf(string[0], "e %d.0", (drsSoftSpeed[player] + 1) / 2);
			printFontGrid(22, 12, string[0], 7 * (cursor == 9));
			
			if(drsMaxWaitt[player] >= 99) sprintf(string[0], "INFINITE");
			else sprintf(string[0], "%d", drsMaxWaitt[player]);
			printFontGrid(22, 13, string[0], 7 * (cursor == 10));
			
			if(!drsFastlrmove[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 14, string[0], 7 * (cursor == 11));
			
			if(drsOBlkBG[player] == 0) sprintf(string[0], "OFF");
			else if(drsOBlkBG[player] == 1) sprintf(string[0], "BLACK");
			else sprintf(string[0], "WHITE");
			printFontGrid(22, 15, string[0], 7 * (cursor == 12));
			
			for(i = 0; i < 7; i++) printFontGrid(22, 16 + i, drsStrColor[drsColor[player * 7 + i]], 7 * (cursor == 13 + i));
			
			if(!drsInitRotate[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 23, string[0], 7 * (cursor == 20));
			
			if(!drsInitHold[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 24, string[0], 7 * (cursor == 21));
			
			if(!drsEnableKick[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 25, string[0], 7 * (cursor == 22));
			
			if(!drsSelfLockSound[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 26, string[0], 7 * (cursor == 23));
			
			sprintf(string[0], "%d FRAMES", drsLockflash[player]);
			printFontGrid(22, 27, string[0], 7 * (cursor == 24));
			
			if(!drsRepeatDelay[player]) sprintf(string[0], "OFF");
			else sprintf(string[0], "%d", drsRepeatDelay[player]);
			printFontGrid(22, 28, string[0], 7 * (cursor == 25));
		} else {
			printFontGrid(31, 1, "PAGE 2/2", 6);
			
			// �J�[�\���\��
			printFontGrid(1, 3 + cursor - 26, "b", 7);
			
			// ���j���[�\��
			printFontGrid(2,  3, "[SAVE PRESET]",    7 * (cursor == 26));
			printFontGrid(2,  4, "[LOAD PRESET]",    7 * (cursor == 27));
			
			sprintf(string[0], "PRESET NO.%d", drsLastPresetNo[player] + 1);
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
			
			if(cursor == 0) drsExtRotate[player] = !drsExtRotate[player];
			if(cursor == 1) drsLockReset[player] = !drsLockReset[player];
			if(cursor == 2) {
				drsRotLimit[player] = drsRotLimit[player] + move;
				if(drsRotLimit[player] < 0) drsRotLimit[player] = 128;
				if(drsRotLimit[player] > 128) drsRotLimit[player] = 0;
			}
			if(cursor == 3) {
				drsMoveLimit[player] = drsMoveLimit[player] + move;
				if(drsMoveLimit[player] < 0) drsMoveLimit[player] = 128;
				if(drsMoveLimit[player] > 128) drsMoveLimit[player] = 0;
			}
			if(cursor == 4) {
				drsGraphics[player] = drsGraphics[player] + move;
				if(drsGraphics[player] < 0) drsGraphics[player] = 7;
				if(drsGraphics[player] > 7) drsGraphics[player] = 0;
			}
			if(cursor == 5) {
				drsAre[player] = drsAre[player] + move;
				if(drsAre[player] < 0) drsAre[player] = 2;
				if(drsAre[player] > 2) drsAre[player] = 0;
			}
			if(cursor == 6) {
				drsLockUp[player] = drsLockUp[player] + move;
				if(drsLockUp[player] < 0) drsLockUp[player] = 2;
				if(drsLockUp[player] > 2) drsLockUp[player] = 0;
			}
			if(cursor == 7) {
				drsLockDown[player] = drsLockDown[player] + move;
				if(drsLockDown[player] < 0) drsLockDown[player] = 6;
				if(drsLockDown[player] > 6) drsLockDown[player] = 0;
			}
			if(cursor == 8) drsRotReverse[player] = !drsRotReverse[player];
			if(cursor == 9) {
				drsSoftSpeed[player] = drsSoftSpeed[player] + move;
				if(drsSoftSpeed[player] < 0) drsSoftSpeed[player] = 39;
				if(drsSoftSpeed[player] > 39) drsSoftSpeed[player] = 0;
			}
			if(cursor == 10) {
				drsMaxWaitt[player] = drsMaxWaitt[player] + move;
				if(drsMaxWaitt[player] < 0) drsMaxWaitt[player] = 99;
				if(drsMaxWaitt[player] > 99) drsMaxWaitt[player] = 0;
			}
			if(cursor == 11) drsFastlrmove[player] = !drsFastlrmove[player];
			if(cursor == 12) {
				drsOBlkBG[player] = drsOBlkBG[player] + move;
				if(drsOBlkBG[player] < 0) drsOBlkBG[player] = 2;
				if(drsOBlkBG[player] > 2) drsOBlkBG[player] = 0;
			}
			if((cursor >= 13) && (cursor <= 19)) {
				temp = cursor - 13;
				drsColor[player * 7 + temp] = drsColor[player * 7 + temp] + move;
				if(drsColor[player * 7 + temp] < 0) drsColor[player * 7 + temp] = 7;
				if(drsColor[player * 7 + temp] > 7) drsColor[player * 7 + temp] = 0;
			}
			if(cursor == 20) drsInitRotate[player] = !drsInitRotate[player];
			if(cursor == 21) drsInitHold[player] = !drsInitHold[player];
			if(cursor == 22) drsEnableKick[player] = !drsEnableKick[player];
			if(cursor == 23) drsSelfLockSound[player] = !drsSelfLockSound[player];
			if(cursor == 24) {
				drsLockflash[player] = drsLockflash[player] + move;
				if(drsLockflash[player] < 0) drsLockflash[player] = 99;
				if(drsLockflash[player] > 99) drsLockflash[player] = 0;
			}
			if(cursor == 25) {
				drsRepeatDelay[player] = drsRepeatDelay[player] + move;
				if(drsRepeatDelay[player] < 0) drsRepeatDelay[player] = 99;
				if(drsRepeatDelay[player] > 99) drsRepeatDelay[player] = 0;
			}
			if(cursor >= 26) {
				drsLastPresetNo[player] = drsLastPresetNo[player] + move;
				if(drsLastPresetNo[player] < 0) drsLastPresetNo[player] = 4;
				if(drsLastPresetNo[player] > 4) drsLastPresetNo[player] = 0;
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
				drsSavePreset(player, drsLastPresetNo[player]);
				drsSaveConfig(player);
			} else if(cursor == 27) {
				drsLoadPreset(player, drsLastPresetNo[player]);
			} else {
				drsSaveConfig(player);
				return;
			}
		}
	}
}

// ���v���C�ڍ�
void drsReplayDetail(int number) {
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
void drsSaveConfig(int player) {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x43535244;
	saveBuf[3] = 0x32764746;
	
	// �ݒ���e
	saveBuf[4] = drsExtRotate[player];
	saveBuf[5] = drsLockReset[player];
	saveBuf[6] = drsRotLimit[player];
	saveBuf[7] = drsMoveLimit[player];
	saveBuf[8] = drsGraphics[player];
	saveBuf[9] = drsAre[player];
	saveBuf[10] = drsLockUp[player];
	saveBuf[11] = drsLockDown[player];
	saveBuf[12] = drsRotReverse[player];
	saveBuf[13] = drsSoftSpeed[player];
	saveBuf[14] = drsMaxWaitt[player];
	saveBuf[15] = drsFastlrmove[player];
	saveBuf[16] = drsOBlkBG[player];
	for(i = 0; i < 7; i++) saveBuf[17 + i] = drsColor[player * 7 + i];
	saveBuf[24] = drsInitRotate[player];
	saveBuf[25] = drsInitHold[player];
	saveBuf[26] = drsEnableKick[player];
	saveBuf[27] = drsSelfLockSound[player];
	saveBuf[28] = drsLockflash[player];
	saveBuf[29] = drsRepeatDelay[player];
	
	saveBuf[49] = drsLastPresetNo[player];
	for(i = 0; i < 30 * 5; i++) saveBuf[50 + i] = drsPreset[i];
	
	if(!player) SaveFile("config/DRS_CONFIG.SAV", &saveBuf, 200 * 4);
	else SaveFile("config/DRS_CONFIG_2P.SAV", &saveBuf, 200 * 4);
}

// �ݒ��ǂݍ���
int drsLoadConfig(int player) {
	int i;
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	if(!player) LoadFile("config/DRS_CONFIG.SAV", &saveBuf, 200 * 4);
	else LoadFile("config/DRS_CONFIG_2P.SAV", &saveBuf, 200 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x43535244) return 0;
	if(saveBuf[3] != 0x32764746) return 0;
	
	// �ݒ���e
	drsExtRotate[player] = saveBuf[4];
	drsLockReset[player] = saveBuf[5];
	drsRotLimit[player] = saveBuf[6];
	drsMoveLimit[player] = saveBuf[7];
	drsGraphics[player] = saveBuf[8];
	drsAre[player] = saveBuf[9];
	drsLockUp[player] = saveBuf[10];
	drsLockDown[player] = saveBuf[11];
	drsRotReverse[player] = saveBuf[12];
	drsSoftSpeed[player] = saveBuf[13];
	drsMaxWaitt[player] = saveBuf[14];
	drsFastlrmove[player] = saveBuf[15];
	drsOBlkBG[player] = saveBuf[16];
	for(i = 0; i < 7; i++) drsColor[player * 7 + i] = saveBuf[17 + i];
	drsInitRotate[player] = saveBuf[24];
	drsInitHold[player] = saveBuf[25];
	drsEnableKick[player] = saveBuf[26];
	drsSelfLockSound[player] = saveBuf[27];
	drsLockflash[player] = saveBuf[28];
	drsRepeatDelay[player] = saveBuf[29];
	
	drsLastPresetNo[player] = saveBuf[49];
	for(i = 0; i < 30 * 5; i++) drsPreset[i] = saveBuf[50 + i];
	
	return 1;
}

// �f�t�H���g�̐ݒ���쐬
void drsMakeDefaultSetting(int player) {
	drsExtRotate[player] = 1;		// �Ԃ̕ǏR�菰�R��
	drsLockReset[player] = 0;		// �Œ莞�ԃ��Z�b�g
	drsRotLimit[player] = 0;		// ��]����
	drsMoveLimit[player] = 0;		// �ړ�����
	drsGraphics[player] = 7;		// �O���t�B�b�N�ԍ�
	drsAre[player] = 2;				// �o���҂����Ԃ̗L��
	drsLockUp[player] = 1;			// ��ő��Œ�
	drsLockDown[player] = 4;		// ���ő��Œ�
	drsRotReverse[player] = 0;		// ��]�������t�]������
	drsSoftSpeed[player] = 2;		// �\�t�g�h���b�v�̑��x
	drsMaxWaitt[player] = 10;		// �ő剡����
	drsFastlrmove[player] = 1;		// ��s���ړ�
	drsOBlkBG[player] = 0;			// ����c�l�o�ꒆ�̔w�i
	drsInitRotate[player] = 1;		// ��s��]
	drsInitHold[player] = 1;		// ��s�z�[���h
	drsEnableKick[player] = 1;		// �ǏR��L��
	drsSelfLockSound[player] = 0;	// �����ŌŒ肳�����Ƃ��ɉ����o��
	drsLockflash[player] = 2;		// �u���b�N���Œ肳�����u�ԁA�u���b�N������t���[����
	drsRepeatDelay[player] = 0;		// RepeatDelay
	
	// �u���b�N�̐F
	drsColor[player * 7 + 0] = 1;
	drsColor[player * 7 + 1] = 2;
	drsColor[player * 7 + 2] = 3;
	drsColor[player * 7 + 3] = 4;
	drsColor[player * 7 + 4] = 5;
	drsColor[player * 7 + 5] = 6;
	drsColor[player * 7 + 6] = 7;
	
	// �v���Z�b�g�ԍ�
	drsLastPresetNo[player] = 0;
}

// �v���Z�b�g������
void drsMakeDefaultPreset() {
	int i;
	
	for(i = 0; i < 30 * 5; i++) drsPreset[i] = 0;
	
	// �v���Z�b�g1
	drsPreset[0 * 30 + 0] = 1;		// �ԂƐ��̏��R��
	drsPreset[0 * 30 + 1] = 0;		// �Œ莞�ԃ��Z�b�g
	drsPreset[0 * 30 + 2] = 0;		// ��]����
	drsPreset[0 * 30 + 3] = 0;		// �ړ�����
	drsPreset[0 * 30 + 4] = 7;		// �O���t�B�b�N�ԍ�
	drsPreset[0 * 30 + 5] = 2;		// �o���҂����Ԃ̗L��
	drsPreset[0 * 30 + 6] = 1;		// ��ő��Œ�
	drsPreset[0 * 30 + 7] = 4;		// ���ő��Œ�
	drsPreset[0 * 30 + 8] = 0;		// ��]�������t�]������
	drsPreset[0 * 30 + 9] = 2;		// �\�t�g�h���b�v�̑��x
	drsPreset[0 * 30 + 10] = 8;		// �ő剡����
	drsPreset[0 * 30 + 11] = 1;		// ��s���ړ�
	drsPreset[0 * 30 + 12] = 0;		// ����c�l�o�ꒆ�̔w�i
	for(i = 0; i < 7; i++) drsPreset[0 * 30 + (13 + i)] = i + 1;
	drsPreset[0 * 30 + 20] = 1;		// ��s��]
	drsPreset[0 * 30 + 21] = 1;		// ��s�z�[���h
	drsPreset[0 * 30 + 22] = 1;		// �ǏR��L��
	drsPreset[0 * 30 + 23] = 0;		// �����ŌŒ肳�����Ƃ��ɉ����o��
	drsPreset[0 * 30 + 24] = 0;		// �u���b�N���Œ肳�����u�ԁA�u���b�N������t���[����
	drsPreset[0 * 30 + 25] = 0;		// RepeatDelay
	
	// �v���Z�b�g2
	drsPreset[1 * 30 + 0] = 0;
	drsPreset[1 * 30 + 1] = 0;
	drsPreset[1 * 30 + 2] = 0;
	drsPreset[1 * 30 + 3] = 0;
	drsPreset[1 * 30 + 4] = 7;
	drsPreset[1 * 30 + 5] = 2;
	drsPreset[1 * 30 + 6] = 1;
	drsPreset[1 * 30 + 7] = 4;
	drsPreset[1 * 30 + 8] = 0;
	drsPreset[1 * 30 + 9] = 2;
	drsPreset[1 * 30 + 10] = 8;
	drsPreset[1 * 30 + 11] = 1;
	drsPreset[1 * 30 + 12] = 0;
	for(i = 0; i < 7; i++) drsPreset[1 * 30 + (13 + i)] = i + 1;
	drsPreset[1 * 30 + 20] = 1;
	drsPreset[1 * 30 + 21] = 1;
	drsPreset[1 * 30 + 22] = 1;
	drsPreset[1 * 30 + 23] = 0;
	drsPreset[1 * 30 + 24] = 0;
	drsPreset[1 * 30 + 25] = 0;
	
	// �v���Z�b�g3
	drsPreset[2 * 30 + 0] = 1;
	drsPreset[2 * 30 + 1] = 1;
	drsPreset[2 * 30 + 2] = 128;
	drsPreset[2 * 30 + 3] = 128;
	drsPreset[2 * 30 + 4] = 7;
	drsPreset[2 * 30 + 5] = 1;
	drsPreset[2 * 30 + 6] = 1;
	drsPreset[2 * 30 + 7] = 0;
	drsPreset[2 * 30 + 8] = 0;
	drsPreset[2 * 30 + 9] = 0;
	drsPreset[2 * 30 + 10] = 99;
	drsPreset[2 * 30 + 11] = 0;
	drsPreset[2 * 30 + 12] = 0;
	drsPreset[2 * 30 + 13] = 5;
	drsPreset[2 * 30 + 14] = 2;
	drsPreset[2 * 30 + 15] = 3;
	drsPreset[2 * 30 + 16] = 1;
	drsPreset[2 * 30 + 17] = 7;
	drsPreset[2 * 30 + 18] = 6;
	drsPreset[2 * 30 + 19] = 4;
	drsPreset[2 * 30 + 20] = 1;
	drsPreset[2 * 30 + 21] = 1;
	drsPreset[2 * 30 + 22] = 1;
	drsPreset[2 * 30 + 23] = 1;
	drsPreset[2 * 30 + 24] = 2;
	drsPreset[2 * 30 + 25] = 0;
	
	// �v���Z�b�g4
	drsPreset[3 * 30 + 0] = 1;
	drsPreset[3 * 30 + 1] = 1;
	drsPreset[3 * 30 + 2] = 0;
	drsPreset[3 * 30 + 3] = 0;
	drsPreset[3 * 30 + 4] = 7;
	drsPreset[3 * 30 + 5] = 0;
	drsPreset[3 * 30 + 6] = 1;
	drsPreset[3 * 30 + 7] = 0;
	drsPreset[3 * 30 + 8] = 0;
	drsPreset[3 * 30 + 9] = 0;
	drsPreset[3 * 30 + 10] = 10;
	drsPreset[3 * 30 + 11] = 1;
	drsPreset[3 * 30 + 12] = 0;
	drsPreset[3 * 30 + 13] = 5;
	drsPreset[3 * 30 + 14] = 2;
	drsPreset[3 * 30 + 15] = 3;
	drsPreset[3 * 30 + 16] = 1;
	drsPreset[3 * 30 + 17] = 7;
	drsPreset[3 * 30 + 18] = 6;
	drsPreset[3 * 30 + 19] = 4;
	drsPreset[3 * 30 + 20] = 0;
	drsPreset[3 * 30 + 21] = 1;
	drsPreset[3 * 30 + 22] = 1;
	drsPreset[3 * 30 + 23] = 1;
	drsPreset[3 * 30 + 24] = 0;
	drsPreset[3 * 30 + 25] = 0;
}

// �v���Z�b�g��ۑ�
void drsSavePreset(int player, int number) {
	int i;
	
	drsPreset[number * 30 + 0] = drsExtRotate[player];
	drsPreset[number * 30 + 1] = drsLockReset[player];
	drsPreset[number * 30 + 2] = drsRotLimit[player];
	drsPreset[number * 30 + 3] = drsMoveLimit[player];
	drsPreset[number * 30 + 4] = drsGraphics[player];
	drsPreset[number * 30 + 5] = drsAre[player];
	drsPreset[number * 30 + 6] = drsLockUp[player];
	drsPreset[number * 30 + 7] = drsLockDown[player];
	drsPreset[number * 30 + 8] = drsRotReverse[player];
	drsPreset[number * 30 + 9] = drsSoftSpeed[player];
	drsPreset[number * 30 + 10] = drsMaxWaitt[player];
	drsPreset[number * 30 + 11] = drsFastlrmove[player];
	drsPreset[number * 30 + 12] = drsOBlkBG[player];
	for(i = 0; i < 7; i++) drsPreset[number * 30 + (13 + i)] = drsColor[player * 7 + i];
	drsPreset[number * 30 + 20] = drsInitRotate[player];
	drsPreset[number * 30 + 21] = drsInitHold[player];
	drsPreset[number * 30 + 22] = drsEnableKick[player];
	drsPreset[number * 30 + 23] = drsSelfLockSound[player];
	drsPreset[number * 30 + 24] = drsLockflash[player];
	drsPreset[number * 30 + 25] = drsRepeatDelay[player];
}

// �v���Z�b�g��ǂݍ���
void drsLoadPreset(int player, int number) {
	int i;
	
	drsExtRotate[player] = drsPreset[number * 30 + 0];
	drsLockReset[player] = drsPreset[number * 30 + 1];
	drsRotLimit[player] = drsPreset[number * 30 + 2];
	drsMoveLimit[player] = drsPreset[number * 30 + 3];
	drsGraphics[player] = drsPreset[number * 30 + 4];
	drsAre[player] = drsPreset[number * 30 + 5];
	drsLockUp[player] = drsPreset[number * 30 + 6];
	drsLockDown[player] = drsPreset[number * 30 + 7];
	drsRotReverse[player] = drsPreset[number * 30 + 8];
	drsSoftSpeed[player] = drsPreset[number * 30 + 9];
	drsMaxWaitt[player] = drsPreset[number * 30 + 10];
	drsFastlrmove[player] = drsPreset[number * 30 + 11];
	drsOBlkBG[player] = drsPreset[number * 30 + 12];
	for(i = 0; i < 7; i++) drsColor[player * 7 + i] = drsPreset[number * 30 + (13 + i)];
	drsInitRotate[player] = drsPreset[number * 30 + 20];
	drsInitHold[player] = drsPreset[number * 30 + 21];
	drsEnableKick[player] = drsPreset[number * 30 + 22];
	drsSelfLockSound[player] = drsPreset[number * 30 + 23];
	drsLockflash[player] = drsPreset[number * 30 + 24];
	drsRepeatDelay[player] = drsPreset[number * 30 + 25];
}
