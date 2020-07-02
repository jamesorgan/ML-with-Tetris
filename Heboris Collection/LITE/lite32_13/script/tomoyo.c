// TOMOYO���[�h�ł̕����I����������
void tomoyoInitial(int player) {
	int i, sbak[18], skipbak[20], stbak[30];
	
	// ����������Ă͍�����̂��o�b�N�A�b�v�ɃR�s�[
	sbak[0] = stage[player];			// �X�e�[�W
	sbak[1] = ltime[player];			// ���~�b�g�^�C��
	sbak[2] = nextc[player];			// NEXT�J�E���g
	sbak[3] = next[player];				// NEXT�u���b�N
	sbak[4] = gameTimer[player];				// �^�C��
	sbak[5] = clearnum[player];			// �N���A�X�e�[�W��
	sbak[6] = clearp[player];			// �N���A��
	sbak[7] = time2[player];			// ���v���C�p�^�C��
	sbak[8] = onRecord[player];			// ���v���C�L�^���t���O
	sbak[9] = laststage[player];		// �ŏI�X�e�[�W
	sbak[10] = timeattack[player];		// �����_�����[�h
	sbak[11] = start_stage[player];		// �J�n�X�e�[�W
	sbak[12] = repversw;				// ���v���C�o�[�W����
	sbak[13] = stage_skip_used[player];	// �X�e�[�W�X�L�b�v���g������
	sbak[14] = onRecord[player];		// ���v���C�L�^���t���O
	sbak[15] = nextb_max[player];		// NEXT�̃��[�v�Ԋu
	sbak[16] = ready_count[player];		// READY��GO�\����
	sbak[17] = start_nextc[player];		// �X�^�[�g����nextc
	
	// �X�e�[�W�X�L�b�v���g�����t���[�����o�b�N�A�b�v�ɃR�s�[
	for(i = 0; i < 20; i++) {
		skipbak[i] = stage_skip_frame[i + player * 20];
	}
	
	// �Z�N�V�����^�C�����o�b�N�A�b�v�ɃR�s�[
	for(i = 0; i < 30; i++) {
		stbak[i] = now_sttime[i + player * 30];
	}
	
	// ������
	playerInitial(player);
	
	// ����������Ă͍�����̂��o�b�N�A�b�v����߂�
	stage[player]     = sbak[0];		// �X�e�[�W
	ltime[player]     = sbak[1];		// ���~�b�g�^�C��
	nextc[player]     = sbak[2];		// NEXT�J�E���g
	next[player]      = sbak[3];		// NEXT�u���b�N
	gameTimer[player]      = sbak[4];		// �^�C��
	clearnum[player]  = sbak[5];		// �N���A�X�e�[�W��
	clearp[player]    = sbak[6];		// �N���A��
	time2[player]     = sbak[7];		// ���v���C�p�^�C��
	onRecord[player]  = sbak[8];		// ���v���C�L�^���t���O
	laststage[player] = sbak[9];		// �ŏI�X�e�[�W
	timeattack[player] = sbak[10];		// �����_�����[�h
	start_stage[player] = sbak[11];		// �J�n�X�e�[�W
	repversw          = sbak[12];		// ���v���C�o�[�W����
	stage_skip_used[player] = sbak[13];	// �X�e�[�W�X�L�b�v���g�����t���[��
	onRecord[player]  = sbak[14];		// ���v���C�L�^���t���O
	nextb_max[player] = sbak[15];		// NEXT�̃��[�v�Ԋu
	ready_count[player] = sbak[16];		// READY��GO�\����
	start_nextc[player] = sbak[17];		// �X�^�[�g����nextc
	
	// �X�e�[�W�X�L�b�v���g�����t���[�����o�b�N�A�b�v����߂�
	for(i = 0; i < 20; i++) {
		stage_skip_frame[i + player * 20] = skipbak[i];
	}
	
	// �Z�N�V�����^�C�����o�b�N�A�b�v����߂�
	for(i = 0; i < 30; i++) {
		now_sttime[i + player * 30] = stbak[i];
	}
	
	// �����X�s�[�h�l�Ə���wait�l�ǂݍ���
	setStartLevel(player);
	
	// NEXT�u���b�N�̐F��ݒ�
	setNextBlockColors(player, 1);
}

// �t�B�[���h���Ɏc���Ă���v���`�i�u���b�N�̐��𐔂���
int getPlatinumBlock(int player) {
	int i, j, result;
	result = 0;
	
	for(i = 0; i < 10; i++)
		for(j = 0; j < 22; j++) {
			if(fld[i + j * 10 + player * 220] >= 11) {
				result++;
			}
		}
	
	// ���肠���肪ON�Ȃ�A�܂�����オ���Ă��Ȃ��������J�E���g
	if(tomoyo_rise[player]) {
		for(i = 0; i < 10; i++)
			for(j = upLineNo[player]; j <= 20; j++) {
				if(tomoyo_rise_fld[i + j * 10 + player * 200] >= 11)
					result++;
			}
	}
	
	return result;
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.18 - TOMOYO���[�h �X�e�[�W�N���A�^�^�C���I�[�o�[
//������������������������������������������������������������������������������
void statTomoyoNextStage(int player) {
	int i;
	int ext;
	int ltime_s;		// ���~�b�g�^�C�������A�j���p
	
	// �J�E���^����
	statc[player * 10]++;
	
	// ���~�b�g�^�C�������ʂ����߂�
	ext = 0;
	
	if(tomoyo_timebonus[player]) {
		if( (sclear[player]) && (sectionTimer[player] < 10 * 60) ) {
			ext = 10;
		} else if( (sclear[player]) && (sectionTimer[player] < 20 * 60) ) {
			ext = 5;
		}
	}
	
	isxray[player] = 0;		// X-RAY���~�߂�
	iscolor[player] = 0;	// COLOR���~�߂�
	isblind[player] = 0;	// BLIND���~�߂�
	
	// STAGE XX
	printFont(boffset[player] + 1, 6, "STAGE", 4);
	
	if(gameMode[player] == 6) {
		getTomoyoStageNo(stage[player], 0, 1);
	} else {
		sprintf(string[0], "%2d", stage[player] + 1);
	}
	
	printFont(boffset[player] + 7, 6, string[0], 0);
	
	// CLEAR/TIME OVER
	if(sclear[player]) {
		printFont(boffset[player] + 2, 8, "CLEAR", 0);
	} else if(stime[player] <= 0) {
		printFont(boffset[player] + 1, 8, "TIME UP!", 0);
		printFont(boffset[player] + 1, 9, "TRY NEXT", 0);
	} else {
		printFont(boffset[player] + 2, 8, "SKIPED", 0);
	}
	
	if(gameMode[player] == 6) {
		// LIMIT TIME
		if(ext_s[player] < (ext * 60)) {
			ext_s[player] = ext_s[player] + 4;
		}
		if((timeextend_snd_cnt[player] < ext) && ((statc[player * 10] - 1) % 15 == 0)) {
			PlaySE(41);
			timeextend_snd_cnt[player]++;
		}
		ltime_s = ltime[player] + ext_s[player];
		
		printFont(boffset[player], 10, "LIMIT TIME", 3);
		getTime(ltime_s);
		printFont(boffset[player], 11, string[0], ((count % 4 / 2) * digitc[rots[player]])*(ext != 0));
	}
	
	if(gameMode[player] == 15) {
		if(!timeattack[player]) {
			// TOTAL TIME
			printFont(boffset[player], 10, "TOTAL TIME", 3);
			getTime(gameTimer[player]);
			printFont(boffset[player], 11, string[0], 0);
		} else {
			// LIMIT TIME
			printFont(boffset[player], 10, "LIMIT TIME", 3);
			getTime(ltime[player]);
			printFont(boffset[player], 11, string[0], 0);
		}
	}
	
	if(sclear[player]) {
		// �ԉ�
		if( (statc[player * 10] % 10 == 0) && (endingcnt[player] < 10) ) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], 16 + Rand(20), 0, 0, Rand(7), 0);
			endingcnt[player]++;
		}
		
		if(gameMode[player] == 6) {
			// TIME EXTEND
			if(tomoyo_timebonus[player]) {
				printFont(boffset[player], 13, "TIMEEXTEND", 3);
				
				sprintf(string[0], "%2d", ext);
				printFont(boffset[player], 14, string[0], 0);
				printFont(boffset[player] + 3, 14, "SEC", 0);
			}
			// ERASE LINE
			else {
				printFont(boffset[player], 13, "ERASE LINE", 3);
				sprintf(string[0], "%d LINES", li[player]);
				printFont(boffset[player], 14, string[0], 0);
			}
		}
		
		// BONUS
		if(gameMode[player] == 15) {
			printFont(boffset[player], 13, "BONUS", 3);
			sprintf(string[0], "%d PTS", flash_bonus_points[player]);
			printFont(boffset[player], 14, string[0], 0);
		}
		
		// CLEAR TIME
		printFont(boffset[player], 16, "CLEAR TIME", 3);
		getTime(sectionTimer[player]);
		printFont(boffset[player], 17, string[0], 0);
		
		if((gameMode[player] == 6) && (stage[player] == 19))
			printFont(boffset[player], 19, "+1 MINUTES", 2);
	} else {
		// �N���A��
		printFont(boffset[player], 13, "CLEAR PER.", 3);
		sprintf(string[0], "%d%%", (clearnum[player] * 100) / (stage[player] + 1));
		printFont(boffset[player] + 3, 14, string[0], 0);
	}
	
	StopWave(38);
	StopWave(39);
	
	// ���̃X�e�[�W
	if( getPushState(player, 4) || (statc[player * 10] >= 300) ) {
		if(gameMode[player] == 15) {
			// FLASH���[�h
			sc[player] = sc[player] + flash_bonus_points[player];
			endingcnt[player] = 0;
			sectionTimer[player] = 0;
			
			// ���x���_�E��
			if(tc[player] > 100) {
				tc[player] = 100;
				tr[player] = 10;
			} else {
				tc[player] = tc[player] - 20;
				if(tc[player] < -1) tc[player] = -1;
				
				tr[player] = tr[player] - 2;
				if(tr[player] < 0) tr[player] = 0;
			}
			sp[player] = lvTabletomoyo[tr[player]];
			if(stat[1 - player] == 0) backno = tr[player] / 10;
			
			// �R���e�B�j���[�g�p�t���O����
			flash_continue[player] = 0;
			
			// nextc��߂�
			nextc[player] = 0;
			next[player] = nextb[nextc[player] + player * 1400];
			setNextBlockColors(player, 1);
			
			if(stage[player] >= 99) {
				// �X�e�[�W100�N���A�ŃG���f�B���O
				StopAllBGM();
				if(!IsPlayWave(29)) PlaySE(29);
				
				end_f[player] = 2;
				
				ending[player] = 1;
				stat[player] = 1;					// �u���b�N�V���b�^�[
				statc[player * 10] = 0;				// �X�e�[�^�X�J�E���^��0��
				statc[player * 10 + 1] = 14;		// �V���b�^�[��̓X�e�[�^�XNo.14
			} else {
				// ���̃X�e�[�W
				stat[player] = 1;					// �u���b�N�V���b�^�[
				statc[player * 10] = 0;				// �X�e�[�^�X�J�E���^��0��
				statc[player * 10 + 1] = 37;		// �V���b�^�[��̓X�e�[�^�XNo.37
			}
		} else {
			// �N���A���v�Z
			if(stage[player] <= 19) {
				clearp[player] = (clearnum[player] * 100) / (stage[player] + 1);
			}
			
			// �ŏI�X�e�[�W�����肷��
			if(start_stage[player] <= 26) {
				// STAGE1�`EX7�܂�
				if(clearp[player] < 90) {
					laststage[player] = 19;			// �N���A����90%�ɖ����Ȃ��ꍇ�̓X�e�[�W20�ŏI��
				} else if(clearp[player] < 100) {
					laststage[player] = 22;			// �N���A����90�`99%��EX3�܂�
				} else if(stage[player] == 19) {
					// �N���A����100%�̏ꍇ�̓^�C���Ō��߂�
					if(gameTimer[player] < 18000) {
						laststage[player] = 26;		// 5���ȓ��Ȃ�Ō�܂�
						
						// ���ꐯ
						objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
					} else {
						laststage[player] = 24;		// 5�������Ă���ꍇ��EX5
					}
				}
			} else if(start_stage[player] <= 44) {
				// EH�X�e�[�W
				laststage[player] = 44;
			} else if(start_stage[player] <= 71) {
				// �^�[�Q�b�g
				laststage[player] = 71;
			} else {
				// �G�f�B�b�g
				laststage[player] = 999;
			}
			
			if(sclear[player]) {
				// ���~�b�g�^�C������
				ltime[player] = ltime[player] + (ext * 60);
				
				// 20�ʃN���A��1������
				if(stage[player] == 19) ltime[player] = ltime[player] + (60 * 60);
				
				// �Z�N�V�����^�C���L�^
				if(stage[player] <= 26) {
					now_sttime[stage[player] + player * 30] = sectionTimer[player];
				} else if(stage[player] <= 44) {
					now_sttime[(stage[player] - 27) + player * 30] = sectionTimer[player];
				} else if(stage[player] <= 71) {
					now_sttime[(stage[player] - 45) + player * 30] = sectionTimer[player];
				}
			} else {
				// ���s���̃Z�N�V�����^�C���L�^
				if(stage[player] <= 26) {
					now_sttime[stage[player] + player * 30] = -1 - (stime[player] > 0);
				} else if(stage[player] <= 44) {
					now_sttime[(stage[player] - 27) + player * 30] = -1 - (stime[player] > 0);
				} else if(stage[player] <= 71) {
					now_sttime[(stage[player] - 45) + player * 30] = -1 - (stime[player] > 0);
				}
			}
			
			// ���̃X�e�[�W��
			stage[player]++;
			
			// �w�i��߂�
			if(stat[1 - player] == 0) backno = 0;
			
			// DUAL�M�~�b�N����
			endTomoyoDualGimmick(player);
			
			// ������
			tomoyoInitial(player);
			
			if(stage[player] > laststage[player]) {
				// ���X�g�X�e�[�W�N���A�ŃG���f�B���O
				StopAllBGM();						// BGM��~
				
				stage[player] = laststage[player];
				
				// ���v���C�L�^�I��
				if(stage[player] != 44) onRecord[player] = 0;
				
				if(!IsPlayWave(29)) PlaySE(29);
				ending[player] = 1;
				stat[player] = 14;
				statc[player * 10] = 0;
				
				end_f[player] = 1 + (stage[player] >= 26);
			} else {
				stat[player] = 3;					// Ready
				statc[player * 10] = 0;				// �X�e�[�^�X�J�E���^��0��
				statc[player * 10 + 1] = 0;			// 
			}
		}
	}
}

// DUAL�M�~�b�N����
void endTomoyoDualGimmick(int player) {
	int i;
	
	if(tomoyo_dual_enable[player]) {
		backno = 0;
		maxPlay = b_maxPlay;
		
		for(i = 0; i < 2; i++) {
			tomoyo_dual_enable[i] = 0;
			foffset[i] = b_foffset[i];
			boffset[i] = b_boffset[i];
		}
		
		playerInitial(1);
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.19 - TOMOYO���[�h �R���e�B�j���[
//������������������������������������������������������������������������������
void statTomoyoContinue(int player) {
	int bak[6];
	
	// ���v���C�Z�[�u
	ReplaySaveCheck(player, 1);
	
	if(statc[player * 10 + 1]) {
		sprintf(string[0], "SAVED:  %02d", statc[player * 10 + 1]);
		printFont(boffset[player], 26, string[0], 5);
	}
	
	// �J�E���^����
	statc[player * 10]++;
	
	printFont(boffset[player] + 1, 9, "CONTINUE", 3);
	
	if(count % 60 > 10) {
		BltRect(49, foffset[player] - 2, 85, 100 * player, 50, 100, 65);
	}
	
	printFont(boffset[player] + 2, 23, "TIME", 6);
	sprintf(string[0], "%d", 10 - (statc[player * 10] / 60));
	printFont(boffset[player] + 7, 23, string[0], 0);
	
	// A�{�^���ŃR���e�B�j���[
	if( getPushState(player, 4) ) {
		PlaySE(10);
		StopAllBGM();	// BGM��~
		
		bak[0] = stage[player];			// �X�e�[�W�ԍ����o�b�N�A�b�v
		bak[1] = stage_nextc[player];		// �X�e�[�W�J�n����nextc���o�b�N�A�b�v
		bak[2] = timeattack[player];
		bak[3] = flash_continue[player];
		bak[4] = flash_cont_stage[player];
		bak[5] = flash_edit[player];
		
		playerInitial(player);			// ������
		
		stage[player] = bak[0];			// �X�e�[�W�ԍ��𕜋A
		start_stage[player] = bak[0];	// �X�^�[�g���̃X�e�[�W�ԍ���ݒ�
		
		nextc[player] = bak[1];			// nextc�𕜋A
		start_nextc[player] = bak[1];	// �X�^�[�g����nextc��ݒ�
		
		next[player] = nextb[bak[1] + player * 1400];
		setNextBlockColors(player, 1);
		
		timeattack[player] = bak[2];
		flash_continue[player] = bak[3];
		flash_cont_stage[player] = bak[4];
		flash_edit[player] = bak[5];
		
		setStartLevel(player);			// �J�n�X�s�[�h�ݒ�
		setstartBGM(player);			// �J�nBGM�ݒ�
		
		stat[player] = 1;				// �u���b�N�V���b�^�[
		statc[player * 10 + 0] = 0;		// �J�E���^������
		
		if(gameMode[player] == 15) {
			if(!flash_continue[player]) {
				stage[player]--;
				flash_cont_stage[player] = stage[player];
				flash_continue[player] = 1;
			} else {
				stage[player] = flash_cont_stage[player];
			}
			statc[player * 10 + 1] = 37;	// �X�e�[�W�Z���N�g
		} else {
			statc[player * 10 + 1] = 3;		// Ready
		}
		
		return;
	}
	
	// B�{�^���ő����^�C������
	if( getPushState(player, 5) ) {
		statc[player * 10] = statc[player * 10] + 60;
	}
	
	// �I��
	if(statc[player * 10] >= 10 * 60) {
		stat[player] = 13;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.20 - TOMOYO���[�h �X�e�[�W�G�f�B�^
//������������������������������������������������������������������������������
// statc[player * 10]    �F�J�[�\���ʒu
// statc[player * 10 + 1]�F���݂̉�ʁi0=���C�����j���[ 1=�ݒ��ʁj
void statTomoyoEditor(int player) {
	int i, j, color;
	
	color = (count % 4 / 2) * digitc[rots[player]];
	
	if(statc[player * 10 + 1] == 0) {
		// ���j���[�`��
		printFont(boffset[player], 6, "EDIT MENU", fontc[rots[player]]);
		
		printFont(boffset[player], 8, "STAGE", (statc[player * 10] == 0) * color);
		getTomoyoStageNo(stage[player], 0, 0);
		printFont(boffset[player] + 6, 8, string[0], (statc[player * 10] == 0) * color);
		
		printFont(boffset[player],  9, "MAIN FIELD", (statc[player * 10] == 1) * color);
		if(gameMode[player] == 6) {
			printFont(boffset[player], 10, "RISE FIELD", (statc[player * 10] == 2) * color);
			printFont(boffset[player], 11, "SETTING",    (statc[player * 10] == 3) * color);
		}
		printFont(boffset[player], 12, "LOAD",       (statc[player * 10] == 4) * color);
		printFont(boffset[player], 13, "SAVE",       (statc[player * 10] == 5) * color);
		
		// �L�[����
		padRepeat(player);
		padRepeat2(player);
		
		// ��
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
		if(getPressState(player, 0)) {
			PlaySE(5);
			statc[player * 10]--;
			if( (gameMode[player] == 15) && ((statc[player * 10] == 2) || (statc[player * 10] == 3)) )
				statc[player * 10] = 1;
			if(statc[player * 10] < 0) statc[player * 10] = 5;
		}
		
		// ��
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
		if(getPressState(player, 1)) {
			PlaySE(5);
			statc[player * 10]++;
			if( (gameMode[player] == 15) && ((statc[player * 10] == 2) || (statc[player * 10] == 3)) )
				statc[player * 10] = 4;
			if(statc[player * 10] > 5) statc[player * 10] = 0;
		}
		
		// ��
		if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
		if(getPressState(player, 2)) {
			PlaySE(3);
			
			if(statc[player * 10] == 0) {
				stage[player]--;
				if(stage[player] < 0) stage[player] = 999;
				start_stage[player] = stage[player];
				loadTomoyoStage(player, stage[player], (gameMode[player] == 15) * 2);
			}
		}
		
		// ��
		if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
		if(getPressState(player, 3)) {
			PlaySE(3);
			
			if(statc[player * 10] == 0) {
				stage[player]++;
				if(stage[player] > 999) stage[player] = 0;
				start_stage[player] = stage[player];
				loadTomoyoStage(player, stage[player], (gameMode[player] == 15) * 2);
			}
		}
		
		// A�{�^��
		if(getPushState(player, 4)) {
			PlaySE(10);
			
			// STAGE
			if(statc[player * 10] == 0) {
				if(gameMode[player] == 6) {
					statc[player * 10] = 0;
					statc[player * 10 + 1] = 1;
				}
			}
			// MAIN/RISE FIELD
			if((statc[player * 10] == 1) || (statc[player * 10] == 2)) {
				if(statc[player * 10] == 2) tomoyo_rise_edit[player] = 1;
				
				stat[player] = 17;
				statc[0 + player * 10] = 20;	// �߂��w��
				statc[1 + player * 10] = 0;
				statc[2 + player * 10] = 1;		// �z�u�s�t���O�ݒ�
				statc[3 + player * 10] = 0;
				statc[4 + player * 10] = 1 + tomoyo_rise_edit[player];		// Y���W
			}
			// SETTING
			if(statc[player * 10] == 3) {
				statc[player * 10] = 0;
				statc[player * 10 + 1] = 1;
			}
			// LOAD
			if(statc[player * 10] == 4) {
				loadTomoyoStage(player, stage[player], (gameMode[player] == 15) * 2);
			}
			// SAVE
			if(statc[player * 10] == 5) {
				saveTomoyoStage(player, stage[player], (gameMode[player] == 15) * 2);
			}
			
			return;
		}
		
		// B�{�^��
		if(getPushState(player, 5)) {
			stat[player] = 2;
			statc[player * 10] = 0;
			return;
		}
	} else {
		// �ݒ���
		if(statc[player * 10] < 16) {
			printFont(boffset[player] - 1, 25, "kn  PAGE 1/2", 0);
			
			printFont(boffset[player], 5, "STAGE TIME", fontc[rots[player]]);
			getTime(stime[player]);
			printFont(boffset[player], 6, string[0], (statc[player * 10] == 0) * color);
			
			printFont(boffset[player], 7, "LIMIT TIME", fontc[rots[player]]);
			getTime(ltime[player]);
			printFont(boffset[player], 8, string[0], (statc[player * 10] == 1) * color);
			
			printFont(boffset[player], 9, "TIMEBONUS", fontc[rots[player]]);
			if(!tomoyo_timebonus[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 9, string[0], (statc[player * 10] == 2) * color);
			
			printFont(boffset[player], 10, "MIRROR", fontc[rots[player]]);
			if(!isfmirror[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 10, string[0], (statc[player * 10] == 3) * color);
			
			printFont(boffset[player], 11, "ROLL", fontc[rots[player]]);
			if(!rollroll_flag[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 11, string[0], (statc[player * 10] == 4) * color);
			
			printFont(boffset[player], 12, "DEATH", fontc[rots[player]]);
			if(!IsBig[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 12, string[0], (statc[player * 10] == 5) * color);
			
			printFont(boffset[player], 13, "X-RAY", fontc[rots[player]]);
			if(!xray_flag[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 13, string[0], (statc[player * 10] == 6) * color);
			
			printFont(boffset[player], 14, "COLOR", fontc[rots[player]]);
			if(!color_flag[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 14, string[0], (statc[player * 10] == 7) * color);
			
			printFont(boffset[player], 15, "BLIND", fontc[rots[player]]);
			if(!blind_flag[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 15, string[0], (statc[player * 10] == 8) * color);
			
			printFont(boffset[player], 16, "THUNDER", fontc[rots[player]]);
			if(!isthunder[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 16, string[0], (statc[player * 10] == 9) * color);
			
			printFont(boffset[player], 17, "HIDENEXT", fontc[rots[player]]);
			if(!hnext_flag[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 17, string[0], (statc[player * 10] == 10) * color);
			
			printFont(boffset[player], 18, "DUAL", fontc[rots[player]]);
			if(!tomoyo_dual[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 18, string[0], (statc[player * 10] == 11) * color);
			
			printFont(boffset[player], 19, "DEVIL500", fontc[rots[player]]);
			if(!tomoyo_waits[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 19, string[0], (statc[player * 10] == 12) * color);
			
			printFont(boffset[player], 20, "SPEED", fontc[rots[player]]);
			sprintf(string[0], "%d", min_speed[player]);
			printFont(boffset[player], 21, string[0], (statc[player * 10] == 13) * color);
			
			printFont(boffset[player], 22, "RISE INTER", fontc[rots[player]]);
			sprintf(string[0], "%d", tomoyo_rise[player]);
			printFont(boffset[player], 23, string[0], (statc[player * 10] == 14) * color);
			
			printFont(boffset[player], 24, "BGM", fontc[rots[player]]);
			sprintf(string[0], "%2d", tomoyo_bgm[player] + 1);
			printFont(boffset[player] + 8, 24, string[0], (statc[player * 10] == 15) * color);
		} else {
			printFont(boffset[player] - 1, 25, "kn  PAGE 2/2", 0);
			
			printFont(boffset[player], 5, "LTIMEOVER", fontc[rots[player]]);
			if(!tomoyo_ltime_over[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 5, string[0], (statc[player * 10] == 16) * color);
		}
		
		// �L�[����
		padRepeat(player);
		padRepeat2(player);
		
		// ��
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
		if(getPressState(player, 0)) {
			PlaySE(5);
			statc[player * 10]--;
			if(statc[player * 10] < 0) statc[player * 10] = 16;
		}
		
		// ��
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
		if(getPressState(player, 1)) {
			PlaySE(5);
			statc[player * 10]++;
			if(statc[player * 10] > 16) statc[player * 10] = 0;
		}
		
		// ��
		if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
		if(getPressState(player, 2)) {
			PlaySE(3);
			
			if(statc[player * 10] == 0) {
				stime[player] = stime[player] - 60;
				if(stime[player] < 0) stime[player] = 72000;
				tomoyo_no_stage_time[player] = (stime[player] == 0);
			}
			if(statc[player * 10] == 1) {
				ltime[player] = ltime[player] - 60;
				if(ltime[player] < 0) ltime[player] = 72000;
			}
			if(statc[player * 10] == 2) tomoyo_timebonus[player] = !tomoyo_timebonus[player];
			if(statc[player * 10] == 3) isfmirror[player] = !isfmirror[player];
			if(statc[player * 10] == 4) rollroll_flag[player] = !rollroll_flag[player];
			if(statc[player * 10] == 5) IsBig[player] = !IsBig[player];
			if(statc[player * 10] == 6) xray_flag[player] = !xray_flag[player];
			if(statc[player * 10] == 7) color_flag[player] = !color_flag[player];
			if(statc[player * 10] == 8) blind_flag[player] = !blind_flag[player];
			if(statc[player * 10] == 9) isthunder[player] = !isthunder[player];
			if(statc[player * 10] == 10) hnext_flag[player] = !hnext_flag[player];
			if(statc[player * 10] == 11) tomoyo_dual[player] = !tomoyo_dual[player];
			if(statc[player * 10] == 12) tomoyo_waits[player] = !tomoyo_waits[player];
			if(statc[player * 10] == 13) {
				min_speed[player]--;
				if(min_speed[player] < 0) min_speed[player] = 1200;
			}
			if(statc[player * 10] == 14) {
				tomoyo_rise[player]--;
				if(tomoyo_rise[player] < 0) tomoyo_rise[player] = 99;
			}
			if(statc[player * 10] == 15) {
				tomoyo_bgm[player]--;
				if(tomoyo_bgm[player] < 0) tomoyo_bgm[player] = 20;
			}
			if(statc[player * 10] == 16) tomoyo_ltime_over[player] = !tomoyo_ltime_over[player];
		}
		
		// ��
		if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
		if(getPressState(player, 3)) {
			PlaySE(3);
			
			if(statc[player * 10] == 0) {
				stime[player] = stime[player] + 60;
				if(stime[player] > 72000) stime[player] = 0;
				tomoyo_no_stage_time[player] = (stime[player] == 0);
			}
			if(statc[player * 10] == 1) {
				ltime[player] = ltime[player] + 60;
				if(ltime[player] > 72000) ltime[player] = 0;
			}
			if(statc[player * 10] == 2) tomoyo_timebonus[player] = !tomoyo_timebonus[player];
			if(statc[player * 10] == 3) isfmirror[player] = !isfmirror[player];
			if(statc[player * 10] == 4) rollroll_flag[player] = !rollroll_flag[player];
			if(statc[player * 10] == 5) IsBig[player] = !IsBig[player];
			if(statc[player * 10] == 6) xray_flag[player] = !xray_flag[player];
			if(statc[player * 10] == 7) color_flag[player] = !color_flag[player];
			if(statc[player * 10] == 8) blind_flag[player] = !blind_flag[player];
			if(statc[player * 10] == 9) isthunder[player] = !isthunder[player];
			if(statc[player * 10] == 10) hnext_flag[player] = !hnext_flag[player];
			if(statc[player * 10] == 11) tomoyo_dual[player] = !tomoyo_dual[player];
			if(statc[player * 10] == 12) tomoyo_waits[player] = !tomoyo_waits[player];
			if(statc[player * 10] == 13) {
				min_speed[player]++;
				if(min_speed[player] > 1200) min_speed[player] = 0;
			}
			if(statc[player * 10] == 14) {
				tomoyo_rise[player]++;
				if(tomoyo_rise[player] > 99) tomoyo_rise[player] = 0;
			}
			if(statc[player * 10] == 15) {
				tomoyo_bgm[player]++;
				if(tomoyo_bgm[player] > 20) tomoyo_bgm[player] = 0;
			}
			if(statc[player * 10] == 16) tomoyo_ltime_over[player] = !tomoyo_ltime_over[player];
		}
		
		// A/B�{�^��
		if(getPushState(player, 4) || getPushState(player, 5)) {
			if(getPushState(player, 4)) PlaySE(10);
			statc[player * 10] = 0;
			statc[player * 10 + 1] = 0;
			return;
		}
		
		// D�{�^���Łu���~�b�g�^�C��3���v�u�^�C���{�[�i�X����v�ɐݒ�
		if(getPushState(player, 7)) {
			PlaySE(3);
			ltime[player] = 10800;
			tomoyo_timebonus[player] = 1;
		}
	}
}

// �X�e�[�W�ԍ��\���p
void getTomoyoStageNo(int stageno, int stringno, int type) {
	if((stageno >= 20) && (stageno <= 26)) {
		sprintf(string[stringno], "EX%d", stageno - 19);
	} else if((stageno >= 27) && (stageno <= 44)) {
		if(type == 0) {
			sprintf(string[stringno], "%d", stageno - 26);
		} else if(type == 1) {
			sprintf(string[stringno], "%2d", stageno - 26);
		} else if(type == 2) {
			sprintf(string[stringno], "%3d", stageno - 26);
		}
	} else if((stageno >= 45) && (stageno <= 71)) {
		if(type == 0) {
			sprintf(string[stringno], "%d", stageno - 44);
		} else if(type == 1) {
			sprintf(string[stringno], "%2d", stageno - 44);
		} else if(type == 2) {
			sprintf(string[stringno], "%3d", stageno - 44);
		}
	} else if(stageno >= 72) {
		if(type == 0) {
			sprintf(string[stringno], "%d", stageno - 71);
		} else if(type == 1) {
			sprintf(string[stringno], "%2d", stageno - 71);
		} else if(type == 2) {
			sprintf(string[stringno], "%3d", stageno - 71);
		}
	} else {
		if(type == 0) {
			sprintf(string[stringno], "%d", stageno + 1);
		} else if(type == 1) {
			sprintf(string[stringno], "%2d", stageno + 1);
		} else if(type == 2) {
			sprintf(string[stringno], "%3d", stageno + 1);
		}
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.36 - FLASH���[�h�X�e�[�W�Z���N�g�i����j
//������������������������������������������������������������������������������
void statFlashSelectFirstStage(int player) {
	int color;
	
	if(!statc[player * 10]) {
		loadTomoyoStage(player, stage[player], 1 + flash_edit[player]);
		statc[player * 10] = 1;
	}
	
	color = (count % 4 / 2) * digitc[rots[player]];
	
	printFont(boffset[player], 6, "SELECT", fontc[rots[player]]);
	printFont(boffset[player] + 5, 7, "STAGE", fontc[rots[player]]);
	
	printFont(boffset[player] + 4, 10, "k", color);
	printFont(boffset[player] + 4, 14, "n", color);
	
	sprintf(string[0], "%d", stage[player] + 1);
	printFont(boffset[player] + 4, 12, string[0], color);
	
	printFont(boffset[player] + 2, 16, "BONUS", fontc[rots[player]]);
	sprintf(string[0], "%d", 1000 * ((stage[player] / 4) + 1));
	printFont(boffset[player] + 3, 17, string[0], 0);
	
	printFont(boffset[player], 19, "TIME LIMIT", fontc[rots[player]]);
	if(!timeattack[player]) sprintf(string[0], "<   OFF  >");
	else sprintf(string[0], "<   ON   >");
	printFont(boffset[player], 20, string[0], color);
	
	// �L�[����
	padRepeat(player);
	padRepeat2(player);
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 0) ) {
		PlaySE(5);
		stage[player]--;
		if(stage[player] < 0) stage[player] = 89;
		statc[player * 10] = 0;
	}
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 1) ) {
		PlaySE(5);
		stage[player]++;
		if(stage[player] > 89) stage[player] = 0;
		statc[player * 10] = 0;
	}
	
	// ����
	if(getPushState(player, 2) || getPushState(player, 3)) {
		PlaySE(3);
		timeattack[player] = !timeattack[player];
	}
	
	// A�{�^��
	if( getPushState(player, 4) ) {
		PlaySE(10);
		
		start_stage[player] = stage[player];
		loadTomoyoStage(player, stage[player], 1 + flash_edit[player]);
		
		flash_bonus_points[player] = 1000 * ((stage[player] / 4) + 1);
		flash_bonus_count[player] = 0;
		
		stat[player] = 3;				// Ready
		statc[player * 10] = 0;
		return;
	}
	
	// B�{�^��
	if( getPushState(player, 5) ) {
		stat[player] = 1;				// �u���b�N�V���b�^�[���s
		statc[player * 10] = 0;			// �X�e�[�^�X�J�E���^��0��
		statc[player * 10 + 1] = 2;		// �V���b�^�[��̓X�e�[�^�XNo.2
		return;
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.37 - FLASH���[�h�X�e�[�W�Z���N�g�i2��ڈȍ~�j
//������������������������������������������������������������������������������
void statFlashSelectNextStage(int player) {
	int color, max;
	
	if(!statc[player * 10]) {
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = stage[player] + 1 + (statc[player * 10 + 1] * 2);
		loadTomoyoStage(player, statc[player * 10 + 2], 1 + flash_edit[player]);
	}
	
	color = (count % 4 / 2) * digitc[rots[player]];
	
	printFont(boffset[player], 6, "SELECT", fontc[rots[player]]);
	printFont(boffset[player], 7, "NEXT STAGE", fontc[rots[player]]);
	
	printFont(boffset[player] + 1, 10 + statc[player * 10 + 1] * 2, "b", fontc[rots[player]]);
	
	// ���̃X�e�[�W�ꗗ
	max = 0;
	
	sprintf(string[0], "%d", stage[player] + 1 + 1);
	printFont(boffset[player] + 3, 10, string[0], (statc[player * 10 + 1] == 0) * color);
	
	if( ((stage[player] < 89) && (stage[player] + 3 < 90)) || ((stage[player] >= 89) && (stage[player] + 3 < 100)) ) {
		sprintf(string[0], "%d", stage[player] + 1 + 3);
		printFont(boffset[player] + 3, 12, string[0], (statc[player * 10 + 1] == 1) * color);
		max = 1;
	}
	
	if( ((stage[player] < 89) && (stage[player] + 5 < 90)) || ((stage[player] >= 89) && (stage[player] + 5 < 100)) ) {
		sprintf(string[0], "%d", stage[player] + 1 + 5);
		printFont(boffset[player] + 3, 14, string[0], (statc[player * 10 + 1] == 2) * color);
		max = 2;
	}
	
	if( ((stage[player] < 89) && (stage[player] + 7 < 90)) || ((stage[player] >= 89) && (stage[player] + 7 < 100)) ) {
		sprintf(string[0], "%d", stage[player] + 1 + 7);
		printFont(boffset[player] + 3, 16, string[0], (statc[player * 10 + 1] == 3) * color);
		max = 3;
	}
	
	// �{�[�i�X
	printFont(boffset[player] + 2, 18, "BONUS", fontc[rots[player]]);
	sprintf(string[0], "%d", 1000 * ((stage[player] / 4) + 1));
	printFont(boffset[player] + 3, 19, string[0], 0);
	
	// �҂�����
	statc[player * 10]++;
	printFont(boffset[player] + 1, 23, "TIME", 6);
	sprintf(string[0], "%d", 9 - (statc[player * 10] / 60));
	printFont(boffset[player] + 8, 23, string[0], 0);
	
	// �L�[����
	padRepeat(player);
	padRepeat2(player);
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 0) ) {
		PlaySE(5);
		statc[player * 10 + 1]--;
		
		// �J�[�\���̃��[�v
		if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = max;
		
		statc[player * 10 + 2] = stage[player] + 1 + (statc[player * 10 + 1] * 2);
		
		loadTomoyoStage(player, statc[player * 10 + 2], 1 + flash_edit[player]);
	}
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 1) ) {
		PlaySE(5);
		statc[player * 10 + 1]++;
		
		// �J�[�\���̃��[�v
		if(statc[player * 10 + 1] > max) statc[player * 10 + 1] = 0;
		
		statc[player * 10 + 2] = stage[player] + 1 + (statc[player * 10 + 1] * 2);
		
		loadTomoyoStage(player, statc[player * 10 + 2], 1 + flash_edit[player]);
	}
	
	// A�{�^��
	if(getPushState(player, 4) || (statc[player * 10] >= 600)) {
		PlaySE(10);
		
		stage[player] = statc[player * 10 + 2];
		loadTomoyoStage(player, stage[player], 1 + flash_edit[player]);
		
		flash_bonus_points[player] = 1000 * ((stage[player] / 4) + 1);
		flash_bonus_count[player] = 0;
		
		if(flash_continue[player]) start_stage[player] = stage[player];
		
		stat[player] = 3;				// Ready
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = 0;
		return;
	}
}

//������������������������������������������������������������������������������
//  TOMOYO���[�h �X�e�[�W�ǂݍ��݁^�ۑ�
//������������������������������������������������������������������������������
// �t�@�C���t�H�[�}�b�g (4byte�P��)
//   0�`  209 �t�B�[���h�f�[�^�i��10 * �c21�}�X�j
// 210        MIRROR
// 211        ROLL ROLL
// 212        DEATH BLOCK
// 213        X-RAY
// 214        COLOR
// 215        BLIND
// 216        �������x����
// 217        THUNDER
// 218�`250   ���g�p�i���R�Ɏg�p�\�j

// �X�e�[�W�f�[�^�����[�h
void loadTomoyoStage(int player, int number, int kind) {
	int i;
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	if(kind == 0) sprintf(string[0], "stage/stage%02d.sav", number);
	else if(kind == 1) sprintf(string[0], "stage/flash%02d.sav", number);
	else sprintf(string[0], "stage/edit%02d.sav", number);
	LoadFile(string[0], &saveBuf, 250 * 4);
	
	for(i = 0; i < 10; i++) {
		fld[i + player * 220] = 0;
		fldt[i + player * 220] = 0;
		fldi[i + player * 220] = 0;
		fldo[i + player * 220] = 0;
		flds[i + player * 220] = 0;
	}
	
	// �t�B�[���h�ǂݍ���
	for(i = 0; i < 210; i++) {
		fld[(i + 10) + player * 220] = saveBuf[i];
		
		// �����z�u��������悤�ɂ���
		fldt[(i + 10) + player * 220] = (fld[(i + 10) + player * 220] != 0) * -1;
		
		fldi[(i + 10) + player * 220] = 0;
		fldo[(i + 10) + player * 220] = 0;
		flds[(i + 10) + player * 220] = 0;
	}
	
	// RISE
	tomoyo_rise[player] = saveBuf[218];
	
	if(gameMode[player] == 6) {
		// MIRROR
		isfmirror[player] = saveBuf[210];
		
		// ROLL ROLL
		rollroll_flag[player] = saveBuf[211];
		
		// DEATH BLOCK
		IsBig[player] = saveBuf[212];
		BigMove[player] = 0;
		
		// X-RAY
		xray_flag[player] = saveBuf[213];
		
		// COLOR
		color_flag[player] = saveBuf[214];
		
		// BLIND
		blind_flag[player] = saveBuf[215];
		
		// MIN SP
		min_speed[player] = saveBuf[216];
		
		// THUNDER
		isthunder[player] = saveBuf[217];
		
		// HIDE NEXT
		hnext_flag[player] = saveBuf[219];
		
		// DEVIL500
		tomoyo_waits[player] = saveBuf[220];
		
		// �X�e�[�W�^�C��
		stime[player] = saveBuf[221];
		tomoyo_no_stage_time[player] = (stime[player] == 0);
		
		// ���~�b�g�^�C��
		if(stage[player] == start_stage[player]) {
			ltime[player] = saveBuf[222];
		}
		
		// DUAL��
		tomoyo_dual[player] = saveBuf[223];
		
		// �^�C������
		tomoyo_timebonus[player] = saveBuf[224];
		
		// BGM
		tomoyo_bgm[player] = saveBuf[225];
		
		// ���~�b�g�^�C�����؂�Ă��u���b�N��u���܂ł̓v���C���s
		tomoyo_ltime_over[player] = saveBuf[226];
	}
	
	// ����オ��ꍇ�͂���オ��t�B�[���h��ǂݍ���
	if(tomoyo_rise[player]) {
		LoadFile(string[0], &saveBuf, 450 * 4);
		for(i = 0; i < 200; i++) tomoyo_rise_fld[i + 200 * player] = saveBuf[i + 250];
	} else {
		for(i = 0; i < 200; i++) tomoyo_rise_fld[i + 200 * player] = 0;
	}
}

// �X�e�[�W�f�[�^���Z�[�u
void saveTomoyoStage(int player, int number, int kind) {
	int i;
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	// �t�B�[���h���Z�[�u�o�b�t�@�ɃR�s�[
	for(i = 0; i < 210; i++) {
		saveBuf[i] = fld[(i + 10) + player * 220];
	}
	
	// MIRROR
	saveBuf[210] = isfmirror[player];
	
	// ROLL ROLL
	saveBuf[211] = rollroll_flag[player];
	
	// DEATH BLOCK
	saveBuf[212] = IsBig[player];
	
	// X-RAY
	saveBuf[213] = xray_flag[player];
	
	// COLOR
	saveBuf[214] = color_flag[player];
	
	// BLIND
	saveBuf[215] = blind_flag[player];
	
	// MIN SP
	saveBuf[216] = min_speed[player];
	
	// THUNDER
	saveBuf[217] = isthunder[player];
	
	// RISE
	saveBuf[218] = tomoyo_rise[player];
	
	// HIDE NEXT
	saveBuf[219] = hnext_flag[player];
	
	// DEVIL500(BOOST FIRE)
	saveBuf[220] = tomoyo_waits[player];
	
	// �X�e�[�W�^�C��
	saveBuf[221] = stime[player];
	
	// ���~�b�g�^�C��
	saveBuf[222] = ltime[player];
	
	// DUAL��
	saveBuf[223] = tomoyo_dual[player];
	
	// �^�C������
	saveBuf[224] = tomoyo_timebonus[player];
	
	// BGM
	saveBuf[225] = tomoyo_bgm[player];
	
	// ���~�b�g�^�C�����؂�Ă��u���b�N��u���܂ł̓v���C���s
	saveBuf[226] = tomoyo_ltime_over[player];
	
	// ����オ��t�B�[���h
	for(i = 0; i < 200; i++) saveBuf[i + 250] = tomoyo_rise_fld[i + 200 * player];
	
	// �ۑ�����
	if(kind == 0) sprintf(string[0], "stage/stage%02d.sav", number);
	else if(kind == 1) sprintf(string[0], "stage/flash%02d.sav", number);
	else sprintf(string[0], "stage/edit%02d.sav", number);
	SaveFile(string[0], &saveBuf, 450 * 4);
}
