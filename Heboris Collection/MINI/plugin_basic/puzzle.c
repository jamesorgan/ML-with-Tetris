//PUZZLE
//prefix:pzl

int pzlModeNo = -1;			// ���[�h�ԍ�

int pzlStage[2];			// �X�e�[�W�ԍ�
int pzlClearFlag[2];		// �X�e�[�W�N���A�t���O
int pzlScreen[2];			// ���݂̉�ʁi0=�X�e�[�W�Z���N�g 1=�X�e�[�W�N���A 2=�G�f�B�b�g�j
int pzlStart[2];			// �Q�[���X�^�[�g�t���O
int pzlPBlock[2];			// �c��v���`�i�u���b�N��
int pzlRestLines[2];		// �c�胉�C����

int pzlFld[10 * 22 * 2];	// �t�B�[���h
int pzlNextb[256 * 2];		// �o������u���b�N�̃p�^�[��
int pzlNextc[2];			// �o������u���b�N�̐�
int pzlCondition[2];		// �N���A����
int pzlSpeed[2];			// �������x
int pzlWait1[2];			// �Œ聨��
int pzlWait2[2];			// �u���b�N����
int pzlWait3[2];			// �ڒn���Œ�
int pzlWaitt[2];			// ������
int pzlBigFlag[2];			// BIG���ǂ���
int pzlBigMove[2];			// BIG���̈ړ��P��
int pzlNoHold[2];			// HOLD�֎~
int pzlNorm[2];				// �m���}���C����

int pzlEditStage = 0;		// �G�f�B�b�g�ʂ��ǂ���
int pzlGhost = 1;			// �S�[�X�g���L�����ǂ���
int pzlBgm = 8;				// �g�p����BGM

// �C�x���g����
void pzlPluginEvent(int player, int event, int *param) {
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != pzlModeNo)) return;
	
	if(event == 0) {
		pzlModeNo = addModePlugin("PUZZLE");	// ���[�h��o�^����
	} else if(event == 5) {
		pzlReady(player, param);	// Ready
	} else if(event == 6) {
		pzlBeforeMove(player);	// �u���b�N�o���̒��O
	} else if(event == 7) {
		pzlMoveInit(player, param);	// �u���b�N�o��
	} else if(event == 12) {
		pzlCalcScore(player, param[0]);	// ���C��������
	} else if(event == 15) {
		pzlViewScore(player);	// �X�e�[�^�X�\��
	} else if(event == 18) {
		pzlPlayerInitial(player);	// ������
	} else if(event == 19) {
		pzlPlayNextBlockSE(player);	// NEXT�u���b�N���ʉ��Đ�
	} else if(event == 28) {
		pzlIncrementTime(player);	// ���Ԃ�i�߂�
	} else if(event == 21) {
		pzlTryAgain(player, param);	// ���g���C���
	} else if(event == 32) {
		pzlViewNextBlock(player, param);	// NEXT�u���b�N�\��
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 41) {
		pzlLoadBGM();	// BGM�ǂݍ���
	} else if(event == 65) {
		param[0] = 1;	// �s���`�`�F�b�N�Ȃ�
	} else if(event == 68) {
		// stat[player] == 2�̂Ƃ�
		if(pzlScreen[player] == 0) pzlStatStageSelect(player);	// �X�e�[�W�Z���N�g
		if(pzlScreen[player] == 1) pzlStatStageClear(player);	// �X�e�[�W�N���A
		if(pzlScreen[player] == 2) pzlStatStageEdit(player);	// �X�e�[�W�G�f�B�b�g
	}
}

// ������
void pzlPlayerInitial(int player) {
	pzlStage[player] = 0;
	pzlScreen[player] = 0;
	pzlStart[player] = 0;
	pzlPBlock[player] = 0;
	
	if(!pzlGhost) ghost[player] = 0;
	bgmlv = pzlBgm;
	
	framecolor[player] = 4;
	hnext[player] = 0;
}

// Ready
void pzlReady(int player, int *param) {
	if(!pzlStart[player]) {
		// �X�e�[�W�Z���N�g
		param[0] = 1;
		stat[player] = 2;
		pzlScreen[player] = 0;
		return;
	}
}

// NEXT�u���b�N�\��
void pzlViewNextBlock(int player, int *param) {
	int i, y, block, tmp_color[4];
	
	param[0] = 1;	// �ʏ�̏������X�L�b�v����
	
	printTinyFont(foffset[player] + 97, fyoffset[player] + 10, "NEXT");
	
	sprintf(string[0], "%3d/%3d", nextc[player], pzlNextc[player] + 1);
	printTinyFont(foffset[player] + 97, fyoffset[player] + 18, string[0]);
	
	// NEXT1
	if(nextc[player] <= pzlNextc[player]) {
		block = getNextBlock(player, 0);
		y = fyoffset[player] + 32 + next_offset[player * 7 + block];
		tmp_color[0] = blockcolor[player * 7 + block];
		tmp_color[1] = blockcolor[player * 7 + block];
		tmp_color[2] = blockcolor[player * 7 + block];
		tmp_color[3] = blockcolor[player * 7 + block];
		
		drawBlock(player, foffset[player] + 98, y, block, 0, &tmp_color, 0, 0);
		
		if(blockshadow != 0) {
			drawBlockShadow(player, foffset[player] + 98, y, block, 0, &tmp_color, 0, blockshadow - 1, 0, 0, 1);
		}
	}
	
	// NEXT2�`10
	for(i = 0; i < 9; i++) {
		if(nextc[player] + 1 + i <= pzlNextc[player]) {
			block = getNextBlock(player, i + 1);
			y = fyoffset[player] + 64 + (i * 16);
			tmp_color[0] = blockcolor[player * 7 + block];
			tmp_color[1] = blockcolor[player * 7 + block];
			tmp_color[2] = blockcolor[player * 7 + block];
			tmp_color[3] = blockcolor[player * 7 + block];
			
			drawSmallBlock(player, foffset[player] + 100, y, block, 0, &tmp_color, 0);
			
			if(blockshadow != 0) {
				drawBlockShadowSmall(player, foffset[player] + 100, y, block, 0, &tmp_color, blockshadow - 1);
			}
		}
	}
}

// �X�e�[�^�X�\��
void pzlViewScore(int player) {
	if(timeOn[player]) {
		// �X�e�[�W
		sprintf(string[0], "STAGE %2d", pzlStage[player] + 1);
		printFont(foffset[player] + 16, fyoffset[player] + 216, string[0], 4);
		
		// �c��v���`�i�u���b�N��
		if(pzlCondition[player] == 0) {
			sprintf(string[0], "REST %d", pzlPBlock[player]);
			printFont(foffset[player] + 24, fyoffset[player] + 224, string[0], 4);
		}
		
		// �c�胉�C����
		if(pzlCondition[player] == 2) {
			sprintf(string[0], "LINE  %2d", pzlRestLines[player]);
			printFont(foffset[player] + 16, fyoffset[player] + 224, string[0], 4);
		}
	}
}

// NEXT�u���b�N���ʉ��Đ�
void pzlPlayNextBlockSE(int player) {
	if(nextc[player] <= pzlNextc[player]) PlaySE(se_blockse[getNextBlock(player, 0)]);
}

// ���Ԃ�i�߂�
void pzlIncrementTime(int player) {
	// F�{�^���Ń��g���C
	if(timeOn[player] && getPushState(player, 9)) {
		stat[player] = 7;
		resetStatc(player);
	}
}

// �u���b�N�o���̒��O
void pzlBeforeMove(int player) {
	// �Ō�̃u���b�N�Ńz�[���h���g�p�̏ꍇ�̓z�[���h�g�p�s�\��
	if((nextc[player] >= pzlNextc[player]) && (hold[player] == -1) && (statc[player * 10 + 1])) {
		dhold[player] = 2;
	}
}

// �u���b�N�o��
void pzlMoveInit(int player, int *param) {
	int i;
	
	// �X�e�[�W�N���A
	if(pzlClearFlag[player]) {
		param[0] = 2;
		pzlScreen[player] = 1;
		stat[player] = 2;
		resetStatc(player);
		return;
	}
	
	// NEXT�u���b�N���g���ʂ����ƃQ�[���I�[�o�[
	if((nextc[player] > pzlNextc[player]) && (!param[1])) {
		param[0] = 2;
		stat[player] = 7;
		resetStatc(player);
		return;
	}
}

// ���C��������
void pzlCalcScore(int player, int lines) {
	// �v���`�i�u���b�N�����N���A
	if(pzlCondition[player] == 0) {
		pzlPBlock[player] = checkHowManyPBlocks(player);
		if(pzlPBlock[player] == 0) pzlClearFlag[player] = 1;
	}
	
	// �S�����N���A
	if((pzlCondition[player] == 1) && (isBravo(player))) {
		pzlClearFlag[player] = 1;
	}
	
	// ���C�������N���A
	if(pzlCondition[player] == 2) {
		pzlRestLines[player] = pzlRestLines[player] - lines;
		
		if(pzlRestLines[player] <= 0) {
			pzlRestLines[player] = 0;
			pzlClearFlag[player] = 1;
		}
	}
}

// ���g���C���
void pzlTryAgain(int player, int *param) {
	int i;
	
	param[0] = 1;	// �ʏ�̏������X�L�b�v����
	
	printFont(foffset[player] + 8, fyoffset[player] + 88, "TRY AGAIN?", 3);
	
	printFont(foffset[player] + 36, fyoffset[player] + 104, "YES", (statc[player * 10 + 1] == 0) * 2);
	printFont(foffset[player] + 36, fyoffset[player] + 120, "NO", (statc[player * 10 + 1] == 1) * 2);
	
	// �I��
	if(getPushState(player, 0) || getPushState(player, 1)) {
		PlaySE(se_move);
		statc[player * 10 + 1] = !statc[player * 10 + 1];
	}
	
	// ����
	if(getPushState(player, 4)) {
		PlaySE(se_kettei);
		
		if(statc[player * 10 + 1] == 0) {
			// YES
			pzlStageRead(player);
			stat[player] = 3;
		} else {
			// NO
			pzlScreen[player] = 0;
			stat[player] = 2;
		}
		
		resetStatc(player);
	}
}

// BGM�ǂݍ���
void pzlLoadBGM() {
	// BGM�ǂݍ���
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(pzlBgm);
	}
}

// �X�e�[�W�Z���N�g���
void pzlStatStageSelect(int player) {
	int i, move;
	
	padRepeat2(player);
	
	// �X�e�[�W�ǂݍ���
	if(statc[player * 10] == 0) {
		pzlLoadStage(player, pzlStage[player], pzlEditStage);
		pzlStageRead(player);
		statc[player * 10] = 1;
	}
	
	printFont(foffset[player], fyoffset[player] + 88, "STAGE SELECT", 3);
	
	sprintf(string[0], "kSTAGE %2dn", pzlStage[player] + 1);
	printFont(foffset[player] + 8, fyoffset[player] + 112, string[0], (count % 4 / 2) * 7);
	
	if(pzlCondition[player] == 0) sprintf(string[0], "TARGET");
	if(pzlCondition[player] == 1) sprintf(string[0], "BRAVO");
	if(pzlCondition[player] == 2) sprintf(string[0], "%dLINE", pzlNorm[player]);
	printFont(foffset[player] + 24, fyoffset[player] + 128, string[0], 1);
	
	printFont(foffset[player] + 16, fyoffset[player] + 144, "A:START!", 0);
	printFont(foffset[player] + 24, fyoffset[player] + 152, "B:EXIT", 0);
	printFont(foffset[player] + 24, fyoffset[player] + 160, "D:EDIT", 0);
	
	// A�{�^���ŊJ�n
	if(getPushState(player, 4)) {
		PlaySE(se_kettei);
		stat[player] = 3;
		resetStatc(player);
		pzlStart[player] = 1;
		return;
	}
	
	// B�{�^���ŏI��
	if(getPushState(player, 5)) {
		stat[player] = 0;
		return;
	}
	
	// D�{�^���ŃG�f�B�b�g��ʂ�
	if(getPushState(player, 7)) {
		PlaySE(se_shaki);
		pzlScreen[player] = 2;
		resetStatc(player);
		return;
	}
	
	// �X�e�[�W�ړ�
	move = 0;
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
		move = getPressState(player, 1) - getPressState(player, 0);
	
	if(move) {
		PlaySE(se_move);
		pzlStage[player] = pzlStage[player] + move;
		if(pzlStage[player] < 0) pzlStage[player] = 98;
		if(pzlStage[player] > 98) pzlStage[player] = 0;
		statc[player * 10] = 0;
	}
}

// �X�e�[�W�N���A���
void pzlStatStageClear(int player) {
	int i;
	
	statc[player * 10 + 1]++;
	
	timeOn[player] = 0;
	onRecord[player] = 0;
	
	// ���ʉ�
	if(statc[player * 10 + 1] == 1) PlaySE(se_cheer);
	
	// �ԉ�
	if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 10)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 2]++;
	}
	
	if(statc[player * 10 + 2] >= 10) {
		printFont(foffset[player] + 8, fyoffset[player] + 88, "GREAT JOB!", (count % 4 / 2) * 3);
		
		sprintf(string[0], "STAGE %2d", pzlStage[player] + 1);
		printFont(foffset[player] + 16, fyoffset[player] + 112, string[0], 0);
		
		printFont(foffset[player] + 24, fyoffset[player] + 128, "CLEAR!", 0);
		
		// A�{�^���ŃX�e�[�W�Z���N�g��
		if(getPushState(player, 4)) {
			pzlScreen[player] = 0;
			resetStatc(player);
		}
	}
}

// �X�e�[�W�G�f�B�b�g���
void pzlStatStageEdit(int player) {
	int i, move, cx, cy, color;
	
	padRepeat2(player);
	
	if(statc[player * 10] == 0) {
		// ���j���[���
		printFont(foffset[player] + 8, fyoffset[player] + 56, "STAGE EDIT", 4);
		sprintf(string[0], "STAGE %2d", pzlStage[player] + 1);
		printFont(foffset[player] + 16, fyoffset[player] + 64, string[0], 4);
		
		printFont(foffset[player] + 8, fyoffset[player] +  80, "FIELD EDIT", (statc[player * 10 + 1] == 0) * 2);
		printFont(foffset[player] + 8, fyoffset[player] +  88, "NEXT BLOCK", (statc[player * 10 + 1] == 1) * 2);
		printFont(foffset[player] + 8, fyoffset[player] +  96, "PARAMETER",  (statc[player * 10 + 1] == 2) * 2);
		printFont(foffset[player] + 8, fyoffset[player] + 104, "LOAD",       (statc[player * 10 + 1] == 3) * 2);
		printFont(foffset[player] + 8, fyoffset[player] + 112, "SAVE",       (statc[player * 10 + 1] == 4) * 2);
		
		// �J�[�\���ړ�
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			statc[player * 10 + 1] = statc[player * 10 + 1] + move;
			if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = 4;
			if(statc[player * 10 + 1] > 4) statc[player * 10 + 1] = 0;
		}
		
		// A�{�^��
		if(getPushState(player, 4)) {
			PlaySE(se_kettei);
			
			// FIELD EDIT
			if(statc[player * 10 + 1] == 0) {
				resetStatc(player);
				statc[player * 10] = 1;
				statc[player * 10 + 4] = 1;
			}
			// NEXT BLOCK
			if(statc[player * 10 + 1] == 1) {
				resetStatc(player);
				statc[player * 10] = 2;
			}
			// PARAMETER
			if(statc[player * 10 + 1] == 2) {
				resetStatc(player);
				statc[player * 10] = 3;
			}
			// LOAD
			if(statc[player * 10 + 1] == 3) {
				pzlLoadStage(player, pzlStage[player], pzlEditStage);
				pzlStageRead(player);
			}
			// SAVE
			if(statc[player * 10 + 1] == 4) {
				pzlStageWrite(player);
				pzlSaveStage(player, pzlStage[player], pzlEditStage);
			}
		}
		
		// B�{�^��
		if(getPushState(player, 5)) {
			pzlScreen[player] = 0;
			resetStatc(player);
		}
	} else if(statc[player * 10] == 1) {
		// FIELD EDIT
		// statc[player * 10 + 1] : X���W
		// statc[player * 10 + 2] : Y���W
		// statc[player * 10 + 3] : �u���b�N�̐F
		// statc[player * 10 + 4] : ��ʂ�؂�ւ����u�Ԃ����Ȃ�u���b�N��u���̂�h���t���O
		
		// �J�[�\���ړ��i���E�j�^�u���b�N�I��
		move = 0;
		if( (mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) )
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_move);
			
			if(getPressState(player, 6)) {
				statc[player * 10 + 3] = statc[player * 10 + 3] + move;
				if(statc[player * 10 + 3] < 0) statc[player * 10 + 3] = 16;
				if(statc[player * 10 + 3] > 16) statc[player * 10 + 3] = 0;
			} else {
				statc[player * 10 + 1] = statc[player * 10 + 1] + move;
				if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = 9;
				if(statc[player * 10 + 1] > 9) statc[player * 10 + 1] = 0;
			}
		}
		
		// �J�[�\���ړ��i�㉺�j
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			statc[player * 10 + 2] = statc[player * 10 + 2] + move;
			if(statc[player * 10 + 2] < 0) statc[player * 10 + 2] = 21;
			if(statc[player * 10 + 2] > 21) statc[player * 10 + 2] = 0;
		}
		
		cx = statc[player * 10 + 1];
		cy = statc[player * 10 + 2];
		color = statc[player * 10 + 3];
		
		// �J�[�\���\��
		drawSBlock(player, foffset[player] + 8 + (cx * 8), fyoffset[player] + (cy + 3) * 8, color, 0, 0, 0, 0);
		ExBltFastRect(sg_blkline, foffset[player] + 8 + (cx * 8)    , fyoffset[player] + (cy + 3) * 8    , 16,  0, 8, 1);
		ExBltFastRect(sg_blkline, foffset[player] + 8 + (cx * 8)    , fyoffset[player] + (cy + 3) * 8 + 7, 16, 15, 8, 1);
		ExBltFastRect(sg_blkline, foffset[player] + 8 + (cx * 8)    , fyoffset[player] + (cy + 3) * 8    , 16, 16, 1, 8);
		ExBltFastRect(sg_blkline, foffset[player] + 8 + (cx * 8) + 7, fyoffset[player] + (cy + 3) * 8    , 23, 24, 1, 8);
		
		// ���W
		sprintf(string[0], "X:%2d  Y:%2d", cx, cy);
		printFont(foffset[player] + 8, fyoffset[player] + 200, string[0], 0);
		
		// ������@
		printFont(foffset[player], fyoffset[player] + 216, "A:PUT D:ERASE", 4);
		printFont(foffset[player], fyoffset[player] + 224, "C+<>:COLOR", 4);
		
		// A�Ńu���b�N�z�u
		if(getPressState(player, 4) && !statc[player * 10 + 4]) {
			if(getFieldBlock(player, cx, cy) != color + 1) {
				PlaySE(se_kachi);
				setFieldBlock(player, cx, cy, color + 1);
				setFieldBlockT(player, cx, cy, -1);
			}
		}
		if(!getPressState(player, 4)) {
			statc[player * 10 + 4] = 0;
		}
		
		// D�Ńu���b�N����
		if(getPressState(player, 7)) {
			if(getFieldBlock(player, cx, cy) != 0) {
				PlaySE(se_kachi);
				setFieldBlock(player, cx, cy, 0);
				setFieldBlockT(player, cx, cy, 0);
			}
		}
		
		// B�{�^���ŏI���
		if(getPushState(player, 5)) {
			PlaySE(se_move);
			resetStatc(player);
		}
	} else if(statc[player * 10] == 2) {
		// NEXT BLOCK
		printFont(foffset[player] + 8, fyoffset[player] + 56, "kn SELECT", 7);
		printFont(foffset[player] + 8, fyoffset[player] + 64, "<> CHANGE", 7);
		printFont(foffset[player] + 8, fyoffset[player] + 72, "C+<> MAX", 7);
		
		// �㉺
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			nextc[player] = nextc[player] + move;
			if(nextc[player] < 0) nextc[player] = pzlNextc[player];
			if(nextc[player] > pzlNextc[player]) nextc[player] = 0;
		}
		
		// ���E
		move = 0;
		if( (mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) )
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(getPressState(player, 6)) {
				// NEXT�ő吔
				pzlNextc[player] = pzlNextc[player] + move;
				if(pzlNextc[player] < 0) pzlNextc[player] = 255;
				if(pzlNextc[player] > 255) pzlNextc[player] = 0;
				
				if(nextc[player] > pzlNextc[player]) nextc[player] = pzlNextc[player];
			} else {
				// �u���b�N���
				nextb[nextc[player] + player * 1400] = nextb[nextc[player] + player * 1400] + move;
				if(nextb[nextc[player] + player * 1400] < 0) nextb[nextc[player] + player * 1400] = 6;
				if(nextb[nextc[player] + player * 1400] > 6) nextb[nextc[player] + player * 1400] = 0;
			}
		}
		
		// A��B�{�^���ŏI���
		if(getPushState(player, 4) || getPushState(player, 5)) {
			PlaySE(se_move);
			nextc[player] = 0;
			resetStatc(player);
		}
	} else if(statc[player * 10] == 3) {
		// PARAMETER
		printFont(foffset[player] + 8, fyoffset[player] + 48, "CONDITION", 4);
		if(pzlCondition[player] == 0) sprintf(string[0], "TARGET");
		if(pzlCondition[player] == 1) sprintf(string[0], "BRAVO");
		if(pzlCondition[player] == 2) sprintf(string[0], "LINE");
		printFont(foffset[player] + 8, fyoffset[player] + 56, string[0], (statc[player * 10 + 1] == 0) * 2);
		
		printFont(foffset[player] + 8, fyoffset[player] + 72, "GAME SPEED", 4);
		sprintf(string[0], "SPEED %4d", pzlSpeed[player]);
		printFont(foffset[player] + 8, fyoffset[player] + 80, string[0], (statc[player * 10 + 1] == 1) * 2);
		if(!english) sprintf(string[0], "SYUTUGEN%2d", pzlWait1[player]);
		else sprintf(string[0], "ARE     %2d", pzlWait1[player]);
		printFont(foffset[player] + 8, fyoffset[player] + 88, string[0], (statc[player * 10 + 1] == 2) * 2);
		if(!english) sprintf(string[0], "SYOUKYO %2d", pzlWait2[player]);
		else sprintf(string[0], "LINE    %2d", pzlWait2[player]);
		printFont(foffset[player] + 8, fyoffset[player] + 96, string[0], (statc[player * 10 + 1] == 3) * 2);
		if(!english) sprintf(string[0], "SETTYAKU%2d", pzlWait3[player]);
		else sprintf(string[0], "LOCK    %2d", pzlWait3[player]);
		printFont(foffset[player] + 8, fyoffset[player] + 104, string[0], (statc[player * 10 + 1] == 4) * 2);
		if(!english) sprintf(string[0], "YOKOTAME%2d", pzlWaitt[player]);
		else sprintf(string[0], "DAS     %2d", pzlWaitt[player]);
		printFont(foffset[player] + 8, fyoffset[player] + 112, string[0], (statc[player * 10 + 1] == 5) * 2);
		
		printFont(foffset[player] + 8, fyoffset[player] + 128, "BIG MODE", 4);
		sprintf(string[0], "BIG FLAG %d", pzlBigFlag[player]);
		printFont(foffset[player] + 8, fyoffset[player] + 136, string[0], (statc[player * 10 + 1] == 6) * 2);
		sprintf(string[0], "BIG MOVE %d", pzlBigMove[player] + 1);
		printFont(foffset[player] + 8, fyoffset[player] + 144, string[0], (statc[player * 10 + 1] == 7) * 2);
		
		printFont(foffset[player] + 8, fyoffset[player] + 160, "OTHERS", 4);
		sprintf(string[0], "NOHOLD   %d", pzlNoHold[player]);
		printFont(foffset[player] + 8, fyoffset[player] + 168, string[0], (statc[player * 10 + 1] == 8) * 2);
		sprintf(string[0], "NORM    %2d", pzlNorm[player]);
		printFont(foffset[player] + 8, fyoffset[player] + 176, string[0], (statc[player * 10 + 1] == 9) * 2);
		
		// �J�[�\���ړ�
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			statc[player * 10 + 1] = statc[player * 10 + 1] + move;
			if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = 9;
			if(statc[player * 10 + 1] > 9) statc[player * 10 + 1] = 0;
		}
		
		// ���E
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(statc[player * 10 + 1] == 0) {
				pzlCondition[player] = pzlCondition[player] + move;
				if(pzlCondition[player] < 0) pzlCondition[player] = 2;
				if(pzlCondition[player] > 2) pzlCondition[player] = 0;
			}
			if(statc[player * 10 + 1] == 1) {
				pzlSpeed[player] = pzlSpeed[player] + move;
				if(pzlSpeed[player] < 0) pzlSpeed[player] = 1200;
				if(pzlSpeed[player] > 1200) pzlSpeed[player] = 0;
			}
			if(statc[player * 10 + 1] == 2) {
				pzlWait1[player] = pzlWait1[player] + move;
				if(pzlWait1[player] < 0) pzlWait1[player] = 99;
				if(pzlWait1[player] > 99) pzlWait1[player] = 0;
			}
			if(statc[player * 10 + 1] == 3) {
				pzlWait2[player] = pzlWait2[player] + move;
				if(pzlWait2[player] < 0) pzlWait2[player] = 99;
				if(pzlWait2[player] > 99) pzlWait2[player] = 0;
			}
			if(statc[player * 10 + 1] == 4) {
				pzlWait3[player] = pzlWait3[player] + move;
				if(pzlWait3[player] < 0) pzlWait3[player] = 99;
				if(pzlWait3[player] > 99) pzlWait3[player] = 0;
			}
			if(statc[player * 10 + 1] == 5) {
				pzlWaitt[player] = pzlWaitt[player] + move;
				if(pzlWaitt[player] < 0) pzlWaitt[player] = 99;
				if(pzlWaitt[player] > 99) pzlWaitt[player] = 0;
			}
			if(statc[player * 10 + 1] == 6) pzlBigFlag[player] = !pzlBigFlag[player];
			if(statc[player * 10 + 1] == 7) pzlBigMove[player] = !pzlBigMove[player];
			if(statc[player * 10 + 1] == 8) pzlNoHold[player] = !pzlNoHold[player];
			if(statc[player * 10 + 1] == 9) {
				pzlNorm[player] = pzlNorm[player] + move;
				if(pzlNorm[player] < 0) pzlNorm[player] = 99;
				if(pzlNorm[player] > 99) pzlNorm[player] = 0;
			}
		}
		
		// A��B�{�^���ŏI���
		if(getPushState(player, 4) || getPushState(player, 5)) {
			if(getPushState(player, 4)) PlaySE(se_kettei);
			nextc[player] = 0;
			resetStatc(player);
		}
	}
}

// �X�e�[�W�ۑ�
void pzlSaveStage(int player, int number, int type) {
	int i, j, temp;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �n�`�f�[�^
	for(i = 0; i < 55; i++) {
		saveBuf[i + 1] = (pzlFld[(i * 4) + 0 + player * 220]);
		saveBuf[i + 1] = saveBuf[i + 1] | (pzlFld[(i * 4) + 1 + player * 220] << 8);
		saveBuf[i + 1] = saveBuf[i + 1] | (pzlFld[(i * 4) + 2 + player * 220] << 16);
		saveBuf[i + 1] = saveBuf[i + 1] | (pzlFld[(i * 4) + 3 + player * 220] << 24);
	}
	
	// NEXT�u���b�N
	for(i = 0; i < 32; i++) {
		temp = 0;
		for(j = 0; j < 8; j++) {
			temp = temp | (pzlNextb[(i << 3) + j + player * 256] << (j * 4));
		}
		saveBuf[56 + i] = temp;
	}
	
	// �ݒ�f�[�^
	saveBuf[88] = pzlNextc[player];
	saveBuf[89] = pzlCondition[player];
	saveBuf[90] = pzlSpeed[player];
	saveBuf[91] = pzlWait1[player];
	saveBuf[92] = pzlWait2[player];
	saveBuf[93] = pzlWait3[player];
	saveBuf[94] = pzlWaitt[player];
	saveBuf[95] = pzlBigFlag[player];
	saveBuf[96] = pzlBigMove[player];
	saveBuf[97] = pzlNoHold[player];
	saveBuf[98] = pzlNorm[player];
	
	// �ۑ�
	if(!type) sprintf(string[0], "stage/puzzle/stage%02d.sav", number);
	else sprintf(string[0], "stage/puzzle/edit%02d.sav", number);
	SaveFile(string[0], &saveBuf, 150 * 4);
}

// �X�e�[�W�ǂݍ���
int pzlLoadStage(int player, int number, int type) {
	int i, j;
	
	// �ǂݍ��ݎ��s���Ă����v�Ȃ悤�Ƀ_�~�[�Ńf�t�H���g�l��ݒ�
	for(i = 0; i < 220; i++) pzlFld[i + player * 220] = 0;
	for(i = 0; i < 256; i++) pzlNextb[i + player * 256] = 0;
	pzlNextc[player] = 0;
	pzlCondition[player] = 0;
	pzlSpeed[player] = 1;
	pzlWait1[player] = 25;
	pzlWait2[player] = 40;
	pzlWait3[player] = 99;
	pzlWaitt[player] = 16;
	pzlBigFlag[player] = 0;
	pzlBigMove[player] = 1;
	pzlNoHold[player] = 0;
	pzlNorm[player] = 0;
	
	// �ǂݍ��݊J�n
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	if(!type) sprintf(string[0], "stage/puzzle/stage%02d.sav", number);
	else sprintf(string[0], "stage/puzzle/edit%02d.sav", number);
	LoadFile(string[0], &saveBuf, 150 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �n�`�f�[�^
	for(i = 0; i < 55; i++) {
		pzlFld[(i * 4) + 0 + player * 220] = (saveBuf[1 + i] & 0x000000FF);
		pzlFld[(i * 4) + 1 + player * 220] = (saveBuf[1 + i] & 0x0000FF00) >> 8;
		pzlFld[(i * 4) + 2 + player * 220] = (saveBuf[1 + i] & 0x00FF0000) >> 16;
		pzlFld[(i * 4) + 3 + player * 220] = (saveBuf[1 + i] & 0xFF000000) >> 24;
	}
	
	// NEXT�u���b�N�f�[�^
	for(i = 0; i < 32; i++) {
		for(j = 0; j < 8; j++) {
			pzlNextb[(i << 3) + j + player * 256] = ((saveBuf[56 + i]) >> (j * 4)) & 15;
		}
	}
	
	// �ݒ�f�[�^
	pzlNextc[player] = saveBuf[88];
	pzlCondition[player] = saveBuf[89];
	pzlSpeed[player] = saveBuf[90];
	pzlWait1[player] = saveBuf[91];
	pzlWait2[player] = saveBuf[92];
	pzlWait3[player] = saveBuf[93];
	pzlWaitt[player] = saveBuf[94];
	pzlBigFlag[player] = saveBuf[95];
	pzlBigMove[player] = saveBuf[96];
	pzlNoHold[player] = saveBuf[97];
	pzlNorm[player] = saveBuf[98];
	
	return 1;
}

// �X�e�[�W�̓��e������������
void pzlStageWrite(int player) {
	int i;
	
	// �t�B�[���h
	for(i = 0; i < 220; i++) pzlFld[i + player * 220] = fld[i + player * 220];
	
	// NEXT�u���b�N
	for(i = 0; i < 256; i++) pzlNextb[i + player * 256] = nextb[i + player * 1400];
}

// �X�e�[�W�̓��e���Q�[���ɔ��f������
void pzlStageRead(int player) {
	int i;
	
	// �t�B�[���h
	for(i = 0; i < 220; i++) fld[i + player * 220] = pzlFld[i + player * 220];
	disableShadowTimer(player);	// �u���b�N��������悤�ɂ���
	
	// NEXT�u���b�N
	for(i = 0; i < 256; i++) nextb[i + player * 1400] = pzlNextb[i + player * 256];
	
	// ���x
	sp[player] = pzlSpeed[player];
	wait1[player] = pzlWait1[player];
	wait2[player] = pzlWait2[player];
	wait3[player] = pzlWait3[player];
	waitt[player] = pzlWaitt[player];
	
	// BIG
	IsBig[player] = pzlBigFlag[player];
	BigMove[player] = pzlBigMove[player];
	
	// �z�[���h�֎~
	if(pzlNoHold[player]) dhold[player] = 2;
	else dhold[player] = 0;
	if(!pzlNextc[player]) dhold[player] = 2;
	
	// ���낢�돉����
	nextc[player] = 0;
	hold[player] = -1;
	disp_blkline[player] = 1;
	pzlClearFlag[player] = 0;
	pzlPBlock[player] = checkHowManyPBlocks(player);
	pzlRestLines[player] = pzlNorm[player];
	gameTimer[player] = 0;
	recTimer[player] = 0;
	setNextBlockColor(player, 1);
}
