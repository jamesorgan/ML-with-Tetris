//TOMOYO-FLASH
//prefix:fla

// �ϐ�
int flaModeNo = -1;		// ���[�h�ԍ�

int flaScore[2];		// �X�R�A
int flaLines[2];		// ���C��

int flaStage[2];		// �X�e�[�W
int flaBonus[2];		// �{�[�i�X�_
int flaBTimer[2];		// �{�[�i�X�����J�E���^
int flaSTimer[2];		// �X�e�[�W�^�C��
int flaRest[2];			// �c��v���`�i�u���b�N��
int flaContinue[2];		// �R���e�B�j���[���̍ĊJ�X�e�[�W
int flaNextc[2];		// �X�e�[�W�J�n���̃u���b�N�J�E���^�i�R���e�B�j���[���ɖ߂��j
int flaClearStage[2];	// �N���A�����X�e�[�W��
int flaFirstStage[2];	// �J�n�X�e�[�W

int flaLevel[2];		// ���x��
int flaLvLine[2];		// 4�ȏ�ɂȂ�Ǝ��̃��x����
int flaLvTimer[2];		// �����I�Ɏ��̃��x���ɐi�ރJ�E���^
int flaLvFlash[2];		// ���x���A�b�v����Ƀ��x���\�������点��c�莞��

int flaScreen[2];		// ���݂̉��
int flaStart[2];		// �Q�[���X�^�[�g�t���O

int flaSectionTime[100 * 2];	// ���̃v���C�̃Z�N�V�����^�C��

// ���x���A�b�v�e�[�u��
int flaLevelTable[16] = {48,24,18,15,12,10, 8, 6, 4, 2,10, 8, 6, 4, 2, 1};	// ���x
int flaTimerTable[16] = {14, 9, 9, 9, 9, 9, 9, 9, 9,14,14, 9, 9, 9, 9,14};	// �������x���A�b�v�ɕK�v�Ȏ���
int flaBGTable[16]    = { 0, 0, 1, 1, 2, 2, 3, 3, 4, 5, 6, 7, 7, 8, 8, 9};	// �w�i

// �g�p����BGM
int flaBGMListTable[5] = {8, 14, 9, 19, 6};

// �c�����X�g (0=I 1=L 2=O 3=Z 4=T 5=J 6=S)
str flaNextBlockList = 
"6554550456120244500603524436302425326633362036436052202055321521645455643510264146640306114515244450"+
"4621006053256333034663614136164125646162203014235603434111014421443420136305543632604463351003005300"+
"3113034240614442346145603411201240043660365400542355605502540164151322136554135162536362611511544650"+
"0436003524541031324041121462562345432154451606022103263352550161231140341211033450330633020655146403"+
"4111312042106260052442623214250206561233065501645366322224531632336325105565036321260443364135060462"+
"6424413305662001514114115255244163505645360625360520123310461362403656351553004320234104442443443126"+
"2520622500465633022456043005425350040633021141556064304663022201515200124624202600431500352266062024"+
"0136151422012430242213242602553531464030104514303214051343025324445132610201464236045620365643346206"+
"2141403232202632664016405435063632253420601016604132246604110232541206463226626641062454431434333226"+
"3012131102643663452403012405552261460461540462345656555355534405144012655553302364654530404653013224";

// �ݒ�
int flaRandomMode = 0;	// �����_�����[�h
int flaStageType = 0;	// �X�e�[�W�̎�ށi0=NORMAL 1=EDIT�j
int flaGhost = 1;		// �S�[�X�g�̐ݒ�i0=OFF 1=ON�j
int flaGameType = 0;	// �Q�[���^�C�v�i0=NORMAL 1=TRAINING�j
int flaNextcReset = 1;	// 1�ʂ��Ƃ�NEXT���ŏ��ɖ߂�

// �����L���O�p�ϐ�
int flaRankingScore[10];		// �X�R�A
int flaRankingStage[10];		// ���B�X�e�[�W
int flaRankingTime[10];			// �^�C��
int flaRankingRand[10];			// �����_�����[�h
int flaRankingYear[10];			// �����N�C�������i�N�j
int flaRankingMonth[10];		// �����N�C�������i���j
int flaRankingDay[10];			// �����N�C�������i���j
int flaRankingHour[10];			// �����N�C�������i���j
int flaRankingMinute[10];		// �����N�C�������i���j
int flaRankingSecond[10];		// �����N�C�������i�b�j

// �Z�N�V�����^�C�������L���O�ϐ�
int flaRankingSectionTime[100];		// �^�C��
int flaRankingSectionRand[100];		// �����_�����[�h
int flaRankingSectionYear[100];		// �����N�C�������i�N�j
int flaRankingSectionMonth[100];	// �����N�C�������i���j
int flaRankingSectionDay[100];		// �����N�C�������i���j
int flaRankingSectionHour[100];		// �����N�C�������i���j
int flaRankingSectionMinute[100];	// �����N�C�������i���j
int flaRankingSectionSecond[100];	// �����N�C�������i�b�j

// �C�x���g����
void flaPluginEvent(int player, int event, int *param) {
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != flaModeNo)) return;
	
	if(event == 0) {
		flaModeNo = addModePlugin("TOMOYO-FLASH");	// ���[�h��o�^����
	} else if(event == 5) {
		flaReady(player, param);	// Ready
	} else if(event == 7) {
		if(!ending[player]) flaMoveInit(player);	// �u���b�N�o��
	} else if(event == 10) {
		if(!ending[player]) flaARE(player, param);	// ARE���i�X�e�[�W�N���A����j
	} else if(event == 13) {
		if(!ending[player]) flaEraseLine(player, param[0]);	// ���C������
	} else if(event == 15) {
		flaViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		flaSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		flaPlayerInitial(player);	// ����������
	} else if(event == 20) {
		if(!ending[player] && !flaGameType) flaGameOver(player, param);	// �Q�[���I�[�o�[���̏���
	} else if(event == 24) {
		flaEndingStart(player);	// �G���f�B���O�˓�
	} else if(event == 21) {
		flaResult(player);	// ���ʕ\��
	} else if(event == 25) {
		flaExcellent(player, param);	// �I�[���N���A
	} else if(event == 28) {
		flaIncrementTime(player);	// ���Ԃ�i�߂�
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		flaSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		flaLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		flaLoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		flaReplayDetail();	// ���v���C�ڍ�
	} else if(event == 68) {
		// stat[player] == 2�̂Ƃ�
		if(flaScreen[player] == 0) flaStatFirstStageSelect(player);	// �ŏ��̃X�e�[�W�Z���N�g
		if(flaScreen[player] == 1) flaStatNextStageSelect(player, 1);	// �N���A���̃X�e�[�W�Z���N�g
		if(flaScreen[player] == 2) flaStatNextStageSelect(player, 0);	// �R���e�B�j���[���̃X�e�[�W�Z���N�g
		if(flaScreen[player] == 3) flaStatStageClear(player);	// �X�e�[�W�N���A
	}
}

// ����������
void flaPlayerInitial(int player) {
	int i;
	
	// �ϐ���������
	flaScore[player] = 0;
	flaLines[player] = 0;
	flaStage[player] = 0;
	flaBonus[player] = 0;
	flaBTimer[player] = 0;
	flaSTimer[player] = 0;
	flaRest[player] = 0;
	flaContinue[player] = 0;
	flaNextc[player] = 0;
	flaClearStage[player] = 0;
	flaFirstStage[player] = 0;
	flaLevel[player] = 0;
	flaLvLine[player] = 0;
	flaLvTimer[player] = 0;
	flaLvFlash[player] = 0;
	flaScreen[player] = 0;
	flaStart[player] = 0;
	
	for(i = 0; i < 100; i++) flaSectionTime[i + player * 100] = 0;
	
	// �ݒ���e�ɉ����ăS�[�X�g������
	if(!flaGhost) ghost[player] = 0;
	
	// �g�̐F��ς���
	framecolor[player] = 4;
	
	// �������x
	speedtype[player] = 1;
	sp[player] = flaLevelTable[0];
}

// �c�����X�g��ǂݍ���
void flaLoadNextList(int player) {
	int i, j, temp, len;
	
	// �����𒲂ׂ�
	len = StrLen(flaNextBlockList);
	
	// �ǂݍ���
	if(len > 0) {
		nextc_max[player] = len;
		
		for(i = 0; i < len; i++) {
			j = i % len;
			
			MidStr(flaNextBlockList, j + 1, 1, string[0]);
			
			temp = ValLong(string[0]);
			if((temp >= 0) && (temp <= 6)) nextb[i + player * 1400] = temp;
		}
	}
	
	setNextBlockColor(player, 1);
}

// Ready
void flaReady(int player, int *param) {
	if(!flaStart[player] && !playback) {
		// �c�����X�g�ǂݍ���
		if(!flaRandomMode) flaLoadNextList(player);
		
		// �X�e�[�W�Z���N�g
		param[0] = 1;
		stat[player] = 2;
		flaScreen[player] = 0;
		return;
	}
	
	if(!flaStart[player] && playback) {
		// ���v���C�J�n
		flaStage[player] = flaFirstStage[player];
		flaSetBGMNo(flaStage[player]);
		flaLoadStage(player, flaStage[player], flaStageType);
		flaStart[player] = 1;
	}
	
	// �ŏ��̃t���[���̏���
	if(statc[player * 10] == 0) {
		// ���v���C�L�^�J�n
		onRecord[player] = 1;
		
		// Ready��Go�̎��Ԃ�ݒ�
		ready_start[player] = 45;
		ready_end[player] = 155;
		go_start[player] = 160;
		go_end[player] = 225;
		
		// �c���X�L�b�v�L��
		nextskip[player] = 1;
		
		// �u���b�N��u�����񐔂����Z�b�g
		bdowncnt[player] = 0;
		
		// HOLD����
		hold[player] = -1;
		dhold[player] = 0;
		
		// ���낢�냊�Z�b�g
		flaBTimer[player] = 0;
		flaSTimer[player] = 0;
		
		// �u���b�N�J�E���^���L��
		flaNextc[player] = nextc[player];
		
		// ���x���_�E��
		if(flaLevel[player] > 6) flaLevel[player] = 6;
		else if(flaLevel[player] > 0) flaLevel[player]--;
		sp[player] = flaLevelTable[flaLevel[player]];
		
		if(backno != flaBGTable[flaLevel[player]]) {
			bgfadesw = 1;
			bgfadebg = flaBGTable[flaLevel[player]];
		}
		
		flaLvFlash[player] = 0;
		
		// �{�[�i�X�_�ݒ�
		flaBonus[player] = 1000 * ((flaStage[player] / 4) + 1);
		
		// �v���`�i�u���b�N�̐��𐔂���
		flaRest[player] = checkHowManyPBlocks(player);
	}
	
	if(statc[player * 10] >= ready_start[player]) {
		// �X�e�[�W�ԍ�
		printFont(foffset[player] + 16, fyoffset[player] + 72, "STAGE", 4);
		sprintf(string[0], "%3d", flaStage[player] + 1);
		printFont(foffset[player] + 56, fyoffset[player] + 72, string[0], 0);
		
		// �x�X�g�^�C��
		if(!playback) {
			printFont(foffset[player] + 8, fyoffset[player] + 152, "BEST  TIME", 1);
			getTime(flaRankingSectionTime[flaStage[player]]);
			printFont(foffset[player] + 16, fyoffset[player] + 160, string[0], 0);
		}
	}
}

// �u���b�N�o��
void flaMoveInit(int player) {
	int lv;
	
	// �������x���A�b�v
	lv = flaLevel[player];
	if(lv > 15) lv = 15;
	
	if(flaLvTimer[player] >= 256 * flaTimerTable[lv]) {
		flaLevel[player]++;
		if(flaLevel[player] > 99) flaLevel[player] = 99;
		
		flaLvFlash[player] = 180;
		flaLvTimer[player] = 0;
		flaLvLine[player] = 0;
		
		lv = flaLevel[player];
		if(lv > 15) lv = 15;
		
		if(backno != flaBGTable[lv]) {
			PlaySE(se_levelup);
			bgfadesw = 1;
			bgfadebg = flaBGTable[lv];
		}
		sp[player] = flaLevelTable[lv];
	}
}

// ���C������
void flaEraseLine(int player, int lines) {
	int lv;
	
	// �v���`�i�u���b�N�̐��𐔂���
	flaRest[player] = checkHowManyPBlocks(player);
	
	// ���C��������
	flaLines[player] = flaLines[player] + lines;
	
	// ���x���A�b�v
	flaLvLine[player] = flaLvLine[player] + lines;
	
	if((flaLvLine[player] >= 4) && (flaRest[player] != 0)) {
		flaLevel[player]++;
		if(flaLevel[player] > 99) flaLevel[player] = 99;
		
		flaLvFlash[player] = 180;
		flaLvTimer[player] = 0;
		flaLvLine[player] = 0;
		
		lv = flaLevel[player];
		if(lv > 15) lv = 15;
		
		if(backno != flaBGTable[lv]) {
			PlaySE(se_levelup);
			bgfadesw = 1;
			bgfadebg = flaBGTable[lv];
		}
		sp[player] = flaLevelTable[lv];
	}
}

// ARE���i�X�e�[�W�N���A����j
void flaARE(int player, int *param) {
	if(flaRest[player] == 0) {
		param[0] = 1;
		timeOn[player] = 0;
		stat[player] = 2;
		resetStatc(player);
		flaScreen[player] = 3;
	}
}

// ���Ԃ�i�߂�
void flaIncrementTime(int player) {
	if(timeOn[player]) {
		flaSTimer[player]++;	// �X�e�[�W�^�C������
		flaLvTimer[player]++;	// ���x���^�C�}�[����
		
		// �{�[�i�X����
		if(stat[player] == 4) {
			flaBTimer[player]--;
			
			if(flaBTimer[player] < 0) {
				flaBTimer[player] = 3;
				flaBonus[player]--;
				if(flaBonus[player] < 0) flaBonus[player] = 0;
			}
		}
	}
	
	// ���[���I��
	if((ending[player] == 2) && (edrec[player] >= 60 * 60)) {
		flaScore[player] = flaScore[player] + 100000 + (flaClearStage[player] * 1000);
		ending[player] = 3;
		stat[player] = 10;
		resetStatc(player);
	}
}

// �Q�[���I�[�o�[���̏���
void flaGameOver(int player, int *param) {
	int i, j, block, c, tmp;
	
	// �ʏ�̏������X�L�b�v
	param[0] = 1;
	
	// �ŏ��̃t���[���̏���
	if(statc[player * 10 + 2] == 0) {
		timeOn[player] = 0;
		pinch[player] = 0;
		disp_blkline[player] = 0;
		StopSE(se_hurryup);
		hiddeny[player] = 22;
		
		if(hidden[player]) {
			hidden[player] = 0;
			disableShadowTimer(player);
			statc[player * 10 + 3] = 1;	// HIDDEN���̓u���b�N�������鉉�o�J�n�܂ŊԂ�u��
		}
		
		StopAllBGM();
		
		statc[player * 10] = 21;
		
		// �t�B�[���h�ɉ����Ȃ��ꍇ�̓u���b�N�������鉉�o���ȗ�
		if(isBravo(player)) statc[player * 10] = -2;
		
		statc[player * 10 + 2] = 1;
	}
	
	// ���o�I��
	if(statc[player * 10] <= -2) {
		// �R���e�B�j���[�I��
		printFont(foffset[player] + 12, fyoffset[player] + 96, "CONTINUE?", 3);
		
		printFont(foffset[player] + 36, fyoffset[player] + 112, "YES", (statc[player * 10 + 4] == 0) * 2);
		printFont(foffset[player] + 40, fyoffset[player] + 128, "NO", (statc[player * 10 + 4] == 1) * 2);
		
		if(statc[player * 10 + 5] < 600) {
			sprintf(string[0], "TIME %d", 9 - (statc[player * 10 + 5] / 60));
			printFont(foffset[player] + 24, fyoffset[player] + 144, string[0], 1);
		}
		
		// �J�E���^����
		statc[player * 10 + 5]++;
		
		// �I��
		if(getPushState(player, 0) || getPushState(player, 1)) {
			PlaySE(se_move);
			statc[player * 10 + 4] = !statc[player * 10 + 4];
		}
		
		// ����
		if(getPushState(player, 4) || (statc[player * 10 + 5] >= 600)) {
			if(!statc[player * 10 + 4] && getPushState(player, 4)) {
				// YES
				PlaySE(se_kettei);
				
				ready_count[player] = 0;
				disp_blkline[player] = 1;
				
				nextc[player] = flaNextc[player];
				setNextBlockColor(player, 1);
				
				flaLevel[player] = 0;
				sp[player] = flaLevelTable[0];
				if(backno != flaBGTable[0]) {
					bgfadesw = 1;
					bgfadebg = flaBGTable[0];
				}
				
				flaStage[player] = flaContinue[player];
				flaScore[player] = flaScore[player] / 2;
				
				stat[player] = 2;
				flaScreen[player] = 2;
			} else {
				// NO
				stat[player] = 8;
			}
			resetStatc(player);
		}
		
		return;
	}
	
	// �J�E���^����
	statc[player * 10 + 1]++;
	
	// �X�[�b�Ə����Ă������o
	if(statc[player * 10 + 1] > 4 + statc[player * 10 + 3] * 116) {
		block = statc[player * 10];
		
		statc[player * 10 + 1] = 0;
		
		for(j = 0; j < 10; j++) {
			if(block >= 0) {
				c = fldt[j + block * 10 + player * 220];
				if(c == -1) c = 8;
				fldt[j + block * 10 + player * 220] = c - 4;
			}
			
			if(block <= 20) {
				fldt[j + (block + 1) * 10 + player * 220] = fldt[j + (block + 1) * 10 + player * 220] - 4;
			}
		}
		
		statc[player * 10 + 3] = 0;
		statc[player * 10]--;
	}
}

// �X�R�A�\��
void flaViewScore(int player) {
	int color;
	
	// �X�e�[�W
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "STAGE");
	sprintf(string[0], "%d", flaStage[player] + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], 0);
	
	// �c��v���`�i�u���b�N
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "REST");
	sprintf(string[0], "%d", flaRest[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], 0);
	
	// �X�R�A
	printTinyFont(foffset[player] + 96, fyoffset[player] + 76, "SCORE");
	sprintf(string[0], "%d", flaScore[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 84, string[0], 0);
	
	// ���C��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 94, "LINES");
	sprintf(string[0], "%d", flaLines[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 102, string[0], 0);
	
	// ���x��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 112, "LEVEL");
	sprintf(string[0], "%d", flaLevel[player]);
	if(flaLvFlash[player]) {
		color = 2 * (count % 4 / 2);
		flaLvFlash[player]--;
	} else {
		color = 0;
	}
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 120, string[0], color);
	
	// �{�[�i�X
	if((!pause[player]) && (timeOn[player])) {
		printFont(foffset[player] + 8, fyoffset[player] + 200, "BONUS", 1);
		sprintf(string[0], "%5d", flaBonus[player]);
		printFont(foffset[player] + 48, fyoffset[player] + 200, string[0], 0);
	}
	
	// �^�C��
	if(gameTimer[player] > 359999) gameTimer[player] = 359999;
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], 0);
}

// �ŏ��̃X�e�[�W�Z���N�g
void flaStatFirstStageSelect(int player) {
	int i, move;
	
	padRepeat2(player);
	
	// �X�e�[�W�ǂݍ���
	if(statc[player * 10] == 0) {
		flaLoadStage(player, flaStage[player], flaStageType);
		statc[player * 10] = 1;
	}
	
	printFont(foffset[player], fyoffset[player] + 72, "STAGE SELECT", 3);
	
	sprintf(string[0], "kSTAGE%3dn", flaStage[player] + 1);
	printFont(foffset[player] + 8, fyoffset[player] + 96, string[0], (count % 4 / 2) * 7);
	
	printFont(foffset[player] + 24, fyoffset[player] + 128, "BONUS", 1);
	sprintf(string[0], "%d", 1000 * ((flaStage[player] / 4) + 1));
	printFont(foffset[player] + 24, fyoffset[player] + 136, string[0], 0);
	
	if(!playback && !flaStageType) {
		printFont(foffset[player] + 8, fyoffset[player] + 152, "BEST  TIME", 1);
		getTime(flaRankingSectionTime[flaStage[player]]);
		printFont(foffset[player] + 16, fyoffset[player] + 160, string[0], 0);
	}
	
	// A�{�^���ŊJ�n
	if(getPushState(player, 4)) {
		PlaySE(se_kettei);
		stat[player] = 3;
		resetStatc(player);
		flaSetBGMNo(flaStage[player]);
		flaContinue[player] = flaStage[player];
		flaFirstStage[player] = flaStage[player];
		flaStart[player] = 1;
		return;
	}
	
	// B�{�^���ŏI��
	if(getPushState(player, 5)) {
		stat[player] = 0;
		return;
	}
	
	// �X�e�[�W�ړ�
	move = 0;
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
		move = getPressState(player, 1) - getPressState(player, 0);
	
	if(move) {
		PlaySE(se_move);
		flaStage[player] = flaStage[player] + move;
		if(flaStage[player] < 0) flaStage[player] = 89 + (flaGameType * 10);
		if(flaStage[player] > 89 + (flaGameType * 10)) flaStage[player] = 0;
		statc[player * 10] = 0;
	}
}

// 2��ڈȍ~�̃X�e�[�W�Z���N�g
void flaStatNextStageSelect(int player, int clear) {
	int i, move, temp, max;
	
	padRepeat2(player);
	
	// �X�e�[�W�ǂݍ���
	if(statc[player * 10] == 0) {
		flaLoadStage(player, flaStage[player] + clear + (statc[player * 10 + 1] * 2), flaStageType);
		statc[player * 10] = 1;
	}
	
	printFont(foffset[player] + 8, fyoffset[player] + 56, "SELECT", 3);
	printFont(foffset[player] + 8, fyoffset[player] + 64, "NEXT STAGE", 3);
	
	// �X�e�[�W�ꗗ
	printFont(foffset[player] + 24, fyoffset[player] + 88 + (statc[player * 10 + 1] * 16), "b", (count % 4 / 2) * 7);
	
	for(i = 0; i < 4; i++) {
		temp = flaStage[player] + clear + (i * 2);
		if((flaStage[player] < 89) && (temp >= 90)) break;
		if(temp >= 100) break;
		
		max = i;
		sprintf(string[0], "%d", temp + 1);
		printFont(foffset[player] + 32, fyoffset[player] + 88 + (i * 16), string[0], (statc[player * 10 + 1] == i) * (count % 4 / 2) * 7);
	}
	
	// �{�[�i�X
	printFont(foffset[player] + 24, fyoffset[player] + 152, "BONUS", 1);
	temp = flaStage[player] + clear + (statc[player * 10 + 1] * 2);
	sprintf(string[0], "%d", 1000 * ((temp / 4) + 1));
	printFont(foffset[player] + 24, fyoffset[player] + 160, string[0], 0);
	
	// �x�X�g�^�C��
	if(!playback && !flaStageType) {
		printFont(foffset[player] + 8, fyoffset[player] + 176, "BEST  TIME", 1);
		getTime(flaRankingSectionTime[temp]);
		printFont(foffset[player] + 16, fyoffset[player] + 184, string[0], 0);
	}
	
	// �c�莞��
	if(statc[player * 10 + 2] < 600) {
		sprintf(string[0], "TIME %d", 9 - (statc[player * 10 + 2] / 60));
		printFont(foffset[player] + 24, fyoffset[player] + 200, string[0], 1);
	}
	
	// A�{�^���ŊJ�n
	if(getPushState(player, 4) || (statc[player * 10 + 2] >= 600)) {
		PlaySE(se_kettei);
		flaStage[player] = flaStage[player] + clear + (statc[player * 10 + 1] * 2);
		stat[player] = 3;
		resetStatc(player);
		if(flaSetBGMNo(flaStage[player])) StopAllBGM();
		if(clear) flaContinue[player] = flaStage[player];
		return;
	}
	
	// �X�e�[�W�ړ�
	move = 0;
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
		move = getPressState(player, 1) - getPressState(player, 0);
	
	if(move) {
		PlaySE(se_move);
		statc[player * 10 + 1] = statc[player * 10 + 1] + move;
		if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = max;
		if(statc[player * 10 + 1] > max) statc[player * 10 + 1] = 0;
		statc[player * 10] = 0;
	}
	
	statc[player * 10 + 2]++;
}

// �X�e�[�W�N���A
void flaStatStageClear(int player) {
	int i;
	
	// �ԉ�
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 10)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
	
	// STAGE XX
	printFont(foffset[player] + 16, fyoffset[player] + 48, "STAGE", 4);
	sprintf(string[0], "%3d", flaStage[player] + 1);
	printFont(foffset[player] + 56, fyoffset[player] + 48, string[0], 0);
	
	printFont(foffset[player] + 28, fyoffset[player] + 64, "CLEAR", 0);
	
	// TOTAL TIME
	printSMALLFont(foffset[player] + 18, fyoffset[player] + 80, "Total Time", 3);
	getTime(gameTimer[player]);
	printSMALLFont(foffset[player] + 24, fyoffset[player] + 90, string[0], 0);
	
	// BONUS POINT
	printSMALLFont(foffset[player] + 18, fyoffset[player] + 104, "Bonus Point", 3);
	sprintf(string[0], "%d pts", flaBonus[player]);
	printSMALLFont(foffset[player] + 28, fyoffset[player] + 114, string[0], 0);
	
	// CLEAR TIME
	printSMALLFont(foffset[player] + 18, fyoffset[player] + 128, "Clear Time", 3);
	getTime(flaSTimer[player]);
	printSMALLFont(foffset[player] + 25, fyoffset[player] + 138, string[0], 0);
	
	if(!playback && !flaStageType) {
		if((flaSTimer[player] < flaRankingSectionTime[flaStage[player]]) || (flaRankingSectionTime[flaStage[player]] == 0))
			printSMALLFont(foffset[player] + 18, fyoffset[player] + 150, "New Record", (count % 4 / 2) * 2);
	}
	
	if(getPushState(player, 4) || (statc[player * 10] >= 300)) {
		// �N���A�X�e�[�W��+1
		flaClearStage[player]++;
		
		// �{�[�i�X�|�C���g���Z
		flaScore[player] = flaScore[player] + flaBonus[player];
		
		// ���̖ʂ̃Z�N�V�����^�C�����L�^
		flaSectionTime[flaStage[player] + player * 100] = flaSTimer[player];
		
		// �u���b�N�J�E���^�����Z�b�g
		if(flaNextcReset) {
			nextc[player] = 0;
			setNextBlockColor(player, 1);
		}
		
		// HOLD����
		hold[player] = -1;
		dhold[player] = 0;
		
		// �X�e�[�^�X�J�E���^�����Z�b�g
		resetStatc(player);
		
		if(flaGameType) {
			// �g���[�j���O
			flaLoadStage(player, flaStage[player], flaStageType);
			stat[player] = 3;
		} else if(flaStage[player] >= 99) {
			// �G���f�B���O
			StopAllBGM();
			PlaySE(se_ttclear);
			
			ending[player] = 1;
			stat[player] = 10;
		} else {
			// ���̃X�e�[�W
			flaScreen[player] = 1;
			
			// �X�e�[�W90�N���A�ŗ���
			if(flaStage[player] == 89) {
				objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
			}
		}
	} else {
		// �J�E���^����
		statc[player * 10]++;
	}
}

// BGM�ǂݍ���
void flaLoadBGM() {
	int i;
	
	// BGM�ǂݍ���
	if(bgmtype != 0) {
		for(i = 0; i < 4 + ((flaGameType == 0) * 1); i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/%d)", i + 1, 4 + ((flaGameType == 0) * 1));
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(flaBGMListTable[i]);
		}
	}
}

// BGM�ԍ��ݒ�
int flaSetBGMNo(int number) {
	int backup;
	backup = bgmlv;
	
	if(number <= 29) bgmlv = flaBGMListTable[0];
	else if(number <= 59) bgmlv = flaBGMListTable[1];
	else if(number <= 89) bgmlv = flaBGMListTable[2];
	else bgmlv = flaBGMListTable[3];
	
	if(bgmlv != backup) return 1;
	return 0;
}

// �G���f�B���O�˓�
void flaEndingStart(int player) {
	resetStatc(player);
	
	ending[player] = 2;
	stat[player] = 4;
	ending_timeOn[player] = 1;
	
	fastroll[player] = 2;
	
	bgmlv = flaBGMListTable[4];
	PlayBGM();
	
	flaLoadStage(player, 100, flaStageType);
}

// �I�[���N���A
void flaExcellent(int player, int *param) {
	param[0] = 6;
	
	// �ԉ�
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 1]++;
	}
	
	printSMALLFont(foffset[player] + 2, fyoffset[player] + 80, "Congratulations", (count % 4 / 2) * 7);
	
	printFont(foffset[player] + 24, fyoffset[player] + 104, "GIVE UP", 2);
	printFont(foffset[player] + 24, fyoffset[player] + 128, "YOU ARE", 2);
	printFont(foffset[player] + 32, fyoffset[player] + 144, "CHAMP!", 2);
	
	printFont(foffset[player] +  8, fyoffset[player] + 160, "SPECIAL", 3);
	printFont(foffset[player] + 48, fyoffset[player] + 168, "BONUS", 3);
	
	sprintf(string[0], "%d PTS", 100000 + (flaClearStage[player] * 1000));
	printFont(foffset[player] +  8, fyoffset[player] + 184, string[0], 3);
}

// ���ʕ\��
void flaResult(int player) {
	if(statc[player * 10] == 0) {
		// ���v���C�L�^��~
		onRecord[player] = 0;
		
		// �����L���O�o�^
		statc[player * 10 + 1] = flaRegistRanking(player);
		statc[player * 10 + 2] = flaUpdateSectionTimeRanking(player);
		if((statc[player * 10 + 1] != -1) || (statc[player * 10 + 2] != 0)) flaSaveRanking(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "SCORE");
	sprintf(string[0], "%13d", flaScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "STAGE");
	sprintf(string[0], "%13d", flaStage[player] + 1);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "CLEAR");
	sprintf(string[0], "%13d", flaClearStage[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 139, "TIME");
	getTime(gameTimer[player]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 147, string[1], 0);
	
	if(statc[player * 10 + 1] != -1) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 159, "RANK");
		sprintf(string[0], "%13d", statc[player * 10 + 1] + 1);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
	}
	
	if(statc[player * 10 + 2] != 0) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 179, "ST RECORDS");
		sprintf(string[0], "%13d", statc[player * 10 + 2]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 187, string[0], 0);
	}
}

// ���v���C�ۑ�
void flaSaveReplay(int player) {
	saveBuf[900] = flaScore[player];
	saveBuf[901] = flaStage[player];
	saveBuf[902] = flaClearStage[player];
	saveBuf[903] = flaFirstStage[player];
	saveBuf[904] = flaRandomMode;
	saveBuf[905] = flaStageType;
	saveBuf[906] = flaGameType;
	saveBuf[907] = flaNextcReset;
}

// ���v���C��ǂݍ���
void flaLoadReplay(int player) {
	flaFirstStage[player] = saveBuf[903];
	flaRandomMode = saveBuf[904];
	flaStageType = saveBuf[905];
	flaGameType = saveBuf[906];
	flaNextcReset = saveBuf[907];
}

// ���v���C�ڍ�
void flaReplayDetail() {
	printFontGrid(1, 4, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[900]);
	printFontGrid(22, 4, string[0], 0);
	
	printFontGrid(1, 5, "STAGE", 0);
	sprintf(string[0], "%d", saveBuf[901] + 1);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "CLEAR", 0);
	sprintf(string[0], "%d", saveBuf[902]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "START STAGE", 0);
	sprintf(string[0], "%d", saveBuf[903] + 1);
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 9, "RANDOM MODE", 0);
	if(!saveBuf[904]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "STAGE TYPE", 0);
	if(!saveBuf[905]) sprintf(string[0], "NORMAL");
	else sprintf(string[0], "EDIT");
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "GAME TYPE", 0);
	if(!saveBuf[906]) sprintf(string[0], "NORMAL");
	else sprintf(string[0], "TRAINING");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "NEXT COUNT RESET", 0);
	if(!saveBuf[907]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 12, string[0], 0);
}

// �X�e�[�W�G�f�B�b�g
void flaStageEdit(int player) {
	int i, j, fi, temp, dx, dy;
	int cursor, move, edit, cx, cy, color, noset, stg;
	
	cursor = 0;		// ���j���[�̃J�[�\���ʒu
	edit = 0;		// 0=���j���[ 1=�t�B�[���h
	cx = 0;			// �t�B�[���h�G�f�B�b�g��X���W
	cy = 0;			// �t�B�[���h�G�f�B�b�g��Y���W
	color = 0;		// �t�B�[���h�G�f�B�b�g�̃u���b�N�̐F
	noset = 0;		// ��ʂ�؂�ւ����u�Ԃ����Ȃ�u���b�N��u���̂�h��
	stg = 0;		// �X�e�[�W
	
	flaLoadStage(player, stg, 1);
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		padRepeat(player);
		padRepeat2(player);
		
		sprintf(string[0], "STAGE EDIT %d", stg + 1);
		printFontGrid(1, 1, string[0], 4);
		
		// �t�B�[���h��`��
		ExBltFast(sg_black, 16, 40);
		ExBltRect(sg_fld, 8, 32, 4 * 96, 0, 96, 8 + 176);
		for(i = 0; i < 22; i++) {
			for(j = 0; j < 10; j++) {
				fi = getFieldBlock(player, j, i);
				
				if(fi > 0) {
					// �u���b�N
					dx = (j * 8) + 16;
					dy = (i + 3) * 8;
					drawSBlock(player, dx, dy, fi - 1, 5, 0, 0, 0);
					
					// �g��
					temp = getFieldBlock(player, j, i - 1);
					if((temp == 0) || (temp == -2)) ExBltFastRect(sg_blkline, dx    , dy    ,  8,  0, 8, 1);
					temp = getFieldBlock(player, j, i + 1);
					if((temp == 0) || (temp == -2)) ExBltFastRect(sg_blkline, dx    , dy + 7,  8, 15, 8, 1);
					temp = getFieldBlock(player, j - 1, i);
					if((temp == 0) || (temp == -2)) ExBltFastRect(sg_blkline, dx    , dy    ,  8, 16, 1, 8);
					temp = getFieldBlock(player, j + 1, i);
					if((temp == 0) || (temp == -2)) ExBltFastRect(sg_blkline, dx + 7, dy    , 15, 24, 1, 8);
				}
			}
		}
		
		// ���j���[��`��
		printFontGrid(15, 5, "[FIELD]", (cursor == 0) * 2);
		printFontGrid(15, 6, "[LOAD]",  (cursor == 1) * 2);
		printFontGrid(15, 7, "[SAVE]",  (cursor == 2) * 2);
		
		sprintf(string[0], "< STAGE:%3d >", stg + 1);
		printFontGrid(15, 9, string[0], 5);
		
		// �J�[�\���\��
		if(!edit) {
			printFontGrid(14, 5 + cursor, "b", 2);
			
			printFontGrid(1, 27, "A:OK B:EXIT", 6);
		} else {
			drawSBlock(player, (cx * 8) + 16, (cy + 3) * 8, color, 0, 0, 0, 0);
			ExBltFastRect(sg_blkline, (cx * 8) + 16    , (cy + 3) * 8    , 16,  0, 8, 1);
			ExBltFastRect(sg_blkline, (cx * 8) + 16    , (cy + 3) * 8 + 7, 16, 15, 8, 1);
			ExBltFastRect(sg_blkline, (cx * 8) + 16    , (cy + 3) * 8    , 16, 16, 1, 8);
			ExBltFastRect(sg_blkline, (cx * 8) + 16 + 7, (cy + 3) * 8    , 23, 24, 1, 8);
			
			sprintf(string[0], "X:%02d Y:%02d", cx, cy);
			printFontGrid(1, 2, string[0], 1);
			
			printFontGrid(1, 27, "A:PUT B:END C+L/C+R:SELECT-BLOCK", 6);
			printFontGrid(1, 28, "D:REMOVE", 6);
		}
		
		if(!edit) {
			// �J�[�\���ړ�
			move = 0;
			if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
				move = getPressState(player, 1) - getPressState(player, 0);
			
			if(move) {
				PlaySE(se_move);
				cursor = cursor + move;
				if(cursor < 0) cursor = 2;
				if(cursor > 2) cursor = 0;
			}
			
			// �X�e�[�W��ύX
			move = 0;
			if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
				move = getPressState(player, 3) - getPressState(player, 2);
			
			if(move) {
				PlaySE(se_kachi);
				stg = stg + move;
				if(stg < 0) stg = 100;
				if(stg > 100) stg = 0;
				flaLoadStage(player, stg, 1);
			}
			
			// ����
			if(getPushState(player, 4)) {
				if(cursor == 0) {
					PlayWave(se_kettei);
					edit = 1;
					noset = 1;
				}
				if(cursor == 1) {
					PlayWave(se_kettei);
					flaLoadStage(player, stg, 1);
				}
				if(cursor == 2) {
					PlayWave(se_kettei);
					flaSaveStage(player, stg, 1);
				}
			}
			
			// �L�����Z��
			if(getPushState(player, 5)) {
				PlaySE(se_move);
				return;
			}
		} else {
			// �J�[�\���ړ��i�㉺�j
			move = 0;
			if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
				move = getPressState(player, 1) - getPressState(player, 0);
			
			if(move) {
				PlaySE(se_move);
				cy = cy + move;
				if(cy < 0) cy = 21;
				if(cy > 21) cy = 0;
			}
			
			// �J�[�\���ړ��i���E�j�^�u���b�N�I��
			move = 0;
			if( (mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) )
				move = getPressState(player, 3) - getPressState(player, 2);
			
			if(move) {
				PlaySE(se_move);
				
				if(getPressState(player, 6)) {
					color = color + move;
					if(color < 0) color = 16;
					if(color > 16) color = 0;
				} else {
					cx = cx + move;
					if(cx < 0) cx = 9;
					if(cx > 9) cx = 0;
				}
			}
			
			// A�Ńu���b�N�z�u
			if(getPressState(player, 4) && !noset) {
				if(getFieldBlock(player, cx, cy) != color + 1) {
					PlaySE(se_kachi);
					setFieldBlock(player, cx, cy, color + 1);
				}
			}
			if(!getPressState(player, 4)) {
				noset = 0;
			}
			
			// D�Ńu���b�N����
			if(getPressState(player, 7)) {
				if(getFieldBlock(player, cx, cy) != 0) {
					PlaySE(se_kachi);
					setFieldBlock(player, cx, cy, 0);
				}
			}
			
			// �L�����Z��
			if(getPushState(player, 5)) {
				PlaySE(se_move);
				edit = 0;
			}
		}
	}
}

// �X�e�[�W�ۑ�
void flaSaveStage(int player, int number, int type) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �n�`�f�[�^
	for(i = 0; i < 55; i++) {
		saveBuf[i + 1] = (fld[(i * 4) + 0 + player * 220]);
		saveBuf[i + 1] = saveBuf[i + 1] | (fld[(i * 4) + 1 + player * 220] << 8);
		saveBuf[i + 1] = saveBuf[i + 1] | (fld[(i * 4) + 2 + player * 220] << 16);
		saveBuf[i + 1] = saveBuf[i + 1] | (fld[(i * 4) + 3 + player * 220] << 24);
	}
	
	// �ۑ�
	if(!type) sprintf(string[0], "stage/flash/flash%02d.sav", number);
	else sprintf(string[0], "stage/flash/edit%02d.sav", number);
	SaveFile(string[0], &saveBuf, 60 * 4);
}

// �X�e�[�W�ǂݍ���
int flaLoadStage(int player, int number, int type) {
	int i;
	
	// �ǂݍ��ݎ��s���Ă����v�Ȃ悤�Ƀ_�~�[�Ńf�t�H���g�l��ݒ�
	resetField(player);
	
	// �ǂݍ��݊J�n
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	if(!type) sprintf(string[0], "stage/flash/flash%02d.sav", number);
	else sprintf(string[0], "stage/flash/edit%02d.sav", number);
	LoadFile(string[0], &saveBuf, 60 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �n�`�f�[�^
	for(i = 0; i < 55; i++) {
		fld[(i * 4) + 0 + player * 220] = (saveBuf[1 + i] & 0x000000FF);
		fld[(i * 4) + 1 + player * 220] = (saveBuf[1 + i] & 0x0000FF00) >> 8;
		fld[(i * 4) + 2 + player * 220] = (saveBuf[1 + i] & 0x00FF0000) >> 16;
		fld[(i * 4) + 3 + player * 220] = (saveBuf[1 + i] & 0xFF000000) >> 24;
	}
	disableShadowTimer(player);	// �u���b�N��������悤�ɂ���
	
	return 1;
}

// �ݒ���
void flaSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(flaLoadConfig() == 0) flaSaveConfig();
	
	// �����L���O��ǂݍ���
	if(flaLoadRanking(player) == 0) flaInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "TOMOYO-FLASH OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT D:EDIT E:RANKING", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "GAME TYPE",        7 * (cursor == 0));
		printFontGrid(2, 4, "RANDOM MODE",      7 * (cursor == 1));
		printFontGrid(2, 5, "STAGE TYPE",       7 * (cursor == 2));
		printFontGrid(2, 6, "GHOST BLOCK",      7 * (cursor == 3));
		printFontGrid(2, 7, "NEXT COUNT RESET", 7 * (cursor == 4));
		
		// �ݒ�l�\��
		if(!flaGameType) sprintf(string[0], "NORMAL");
		else sprintf(string[0], "TRAINING");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!flaRandomMode) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!flaStageType) sprintf(string[0], "NORMAL");
		else sprintf(string[0], "EDIT");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(!flaGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(!flaNextcReset) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		// �J�[�\���ړ�
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 4;
			if(cursor > 4) cursor = 0;
		}
		
		// �l��ύX
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			if(cursor == 0) flaGameType = !flaGameType;
			if(cursor == 1) flaRandomMode = !flaRandomMode;
			if(cursor == 2) flaStageType = !flaStageType;
			if(cursor == 3) flaGhost = !flaGhost;
			if(cursor == 4) flaNextcReset = !flaNextcReset;
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
			flaSaveConfig();
			return;
		}
		
		// �X�e�[�W�G�f�B�b�g
		if(getPushState(player, 7)) {
			flaStageEdit(player);
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			flaViewRanking(player);
		}
	}
}

// �ݒ��ۑ�
void flaSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �ݒ���e
	saveBuf[1] = flaGameType;
	saveBuf[2] = flaRandomMode;
	saveBuf[3] = flaStageType;
	saveBuf[4] = flaGhost;
	saveBuf[5] = flaNextcReset;
	
	SaveFile("config/TOMOYO_FLASH_CONFIG.SAV", &saveBuf, 50 * 4);
}

// �ݒ��ǂݍ���
int flaLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/TOMOYO_FLASH_CONFIG.SAV", &saveBuf, 50 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �ݒ���e
	flaGameType = saveBuf[1];
	flaRandomMode = saveBuf[2];
	flaStageType = saveBuf[3];
	flaGhost = saveBuf[4];
	flaNextcReset = saveBuf[5];
	
	return 1;
}

// �����L���O�ۑ�
void flaSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 10) + 0] = flaRankingScore[i];
		saveBuf[1 + (i * 10) + 1] = flaRankingStage[i];
		saveBuf[1 + (i * 10) + 2] = flaRankingTime[i];
		saveBuf[1 + (i * 10) + 3] = flaRankingRand[i];
		saveBuf[1 + (i * 10) + 4] = flaRankingYear[i];
		saveBuf[1 + (i * 10) + 5] = flaRankingMonth[i];
		saveBuf[1 + (i * 10) + 6] = flaRankingDay[i];
		saveBuf[1 + (i * 10) + 7] = flaRankingHour[i];
		saveBuf[1 + (i * 10) + 8] = flaRankingMinute[i];
		saveBuf[1 + (i * 10) + 9] = flaRankingSecond[i];
	}
	
	// �Z�N�V�����^�C�������L���O���e
	for(i = 0; i < 100; i++) {
		saveBuf[111 + (i * 10) + 0] = flaRankingSectionTime[i];
		saveBuf[111 + (i * 10) + 1] = flaRankingSectionRand[i];
		saveBuf[111 + (i * 10) + 2] = flaRankingSectionYear[i];
		saveBuf[111 + (i * 10) + 3] = flaRankingSectionMonth[i];
		saveBuf[111 + (i * 10) + 4] = flaRankingSectionDay[i];
		saveBuf[111 + (i * 10) + 5] = flaRankingSectionHour[i];
		saveBuf[111 + (i * 10) + 6] = flaRankingSectionMinute[i];
		saveBuf[111 + (i * 10) + 7] = flaRankingSectionSecond[i];
	}
	
	sprintf(string[0], "config/TOMOYO_FLASH_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 1121 * 4);
}

// �����L���O�ǂݍ���
int flaLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/TOMOYO_FLASH_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 1121 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		flaRankingScore[i]  = saveBuf[1 + (i * 10) + 0];
		flaRankingStage[i]  = saveBuf[1 + (i * 10) + 1];
		flaRankingTime[i]   = saveBuf[1 + (i * 10) + 2];
		flaRankingRand[i]   = saveBuf[1 + (i * 10) + 3];
		flaRankingYear[i]   = saveBuf[1 + (i * 10) + 4];
		flaRankingMonth[i]  = saveBuf[1 + (i * 10) + 5];
		flaRankingDay[i]    = saveBuf[1 + (i * 10) + 6];
		flaRankingHour[i]   = saveBuf[1 + (i * 10) + 7];
		flaRankingMinute[i] = saveBuf[1 + (i * 10) + 8];
		flaRankingSecond[i] = saveBuf[1 + (i * 10) + 9];
	}
	
	// �Z�N�V�����^�C�������L���O���e
	for(i = 0; i < 100; i++) {
		flaRankingSectionTime[i]   = saveBuf[111 + (i * 10) + 0];
		flaRankingSectionRand[i]   = saveBuf[111 + (i * 10) + 1];
		flaRankingSectionYear[i]   = saveBuf[111 + (i * 10) + 2];
		flaRankingSectionMonth[i]  = saveBuf[111 + (i * 10) + 3];
		flaRankingSectionDay[i]    = saveBuf[111 + (i * 10) + 4];
		flaRankingSectionHour[i]   = saveBuf[111 + (i * 10) + 5];
		flaRankingSectionMinute[i] = saveBuf[111 + (i * 10) + 6];
		flaRankingSectionSecond[i] = saveBuf[111 + (i * 10) + 7];
	}
	
	return 1;
}

// �����L���O������
void flaInitRanking() {
	int i;
	
	// �����L���O���e
	for(i = 0; i < 10; i++) {
		flaRankingScore[i]  = 0;
		flaRankingStage[i]  = 0;
		flaRankingTime[i]   = 0;
		flaRankingRand[i]   = 0;
		flaRankingYear[i]   = 0;
		flaRankingMonth[i]  = 0;
		flaRankingDay[i]    = 0;
		flaRankingHour[i]   = 0;
		flaRankingMinute[i] = 0;
		flaRankingSecond[i] = 0;
	}
	
	// �Z�N�V�����^�C�������L���O���e
	for(i = 0; i < 100; i++) {
		flaRankingSectionTime[i]   = 0;
		flaRankingSectionRand[i]   = 0;
		flaRankingSectionYear[i]   = 0;
		flaRankingSectionMonth[i]  = 0;
		flaRankingSectionDay[i]    = 0;
		flaRankingSectionHour[i]   = 0;
		flaRankingSectionMinute[i] = 0;
		flaRankingSectionSecond[i] = 0;
	}
}

// �����L���O�o�^
int flaRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (flaStageType) || (flaGameType)) return -1;
	
	for(i = 0; i < 10; i++) {
		if( (flaScore[player] > flaRankingScore[i]) || ((flaScore[player] == flaRankingScore[i]) && (flaStage[player] > flaRankingStage[i])) ) {
			// �����L���O�����炷
			for(j = 9; j > i; j--) {
				flaRankingScore[j]  = flaRankingScore[j - 1];
				flaRankingStage[j]  = flaRankingStage[j - 1];
				flaRankingTime[j]   = flaRankingTime[j - 1];
				flaRankingRand[j]   = flaRankingRand[j - 1];
				flaRankingYear[j]   = flaRankingYear[j - 1];
				flaRankingMonth[j]  = flaRankingMonth[j - 1];
				flaRankingDay[j]    = flaRankingDay[j - 1];
				flaRankingHour[j]   = flaRankingHour[j - 1];
				flaRankingMinute[j] = flaRankingMinute[j - 1];
				flaRankingSecond[j] = flaRankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			flaRankingScore[i]  = flaScore[player];
			flaRankingStage[i]  = flaStage[player];
			flaRankingTime[i]   = gameTimer[player];
			flaRankingRand[i]   = flaRandomMode;
			
			GetDateAndTime(&timebuf);
			flaRankingYear[i]   = timebuf[0];
			flaRankingMonth[i]  = timebuf[1];
			flaRankingDay[i]    = timebuf[2];
			flaRankingHour[i]   = timebuf[4];
			flaRankingMinute[i] = timebuf[5];
			flaRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �Z�N�V�����^�C�������L���O�X�V
int flaUpdateSectionTimeRanking(int player) {
	int i, timebuf[8], result;
	result = 0;
	
	if((playback) || (flaStageType)) return 0;
	
	for(i = 0; i < 100; i++) {
		if( ((flaSectionTime[i + player * 100] < flaRankingSectionTime[i]) || (flaRankingSectionTime[i] == 0)) &&
		    (flaSectionTime[i + player * 100] != 0) )
		{
			result++;
			
			flaRankingSectionTime[i] = flaSectionTime[i + player * 100];
			flaRankingSectionRand[i] = flaRandomMode;
			
			GetDateAndTime(&timebuf);
			flaRankingSectionYear[i] = timebuf[0];
			flaRankingSectionMonth[i] = timebuf[1];
			flaRankingSectionDay[i] = timebuf[2];
			flaRankingSectionHour[i] = timebuf[4];
			flaRankingSectionMinute[i] = timebuf[5];
			flaRankingSectionSecond[i] = timebuf[6];
		}
	}
	
	return result;
}

// �����L���O�\��
void flaViewRanking(int player) {
	int i, cursor, move, erasemode, stmode, temp, temp2, page;
	cursor = 0;
	move = 0;
	erasemode = 0;
	stmode = 0;
	page = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		if(!stmode) {
			// �m�[�}�������L���O
			printFontGrid(1, 1, "OJAMA RANKING >>", 6);
			printFontGrid(1, 3, "RANK SCORE   STAGE RAND TIME", 4);
			
			for(i = 0; i < 10; i++) {
				if(i == 0) sprintf(string[0], " 1ST");
				if(i == 1) sprintf(string[0], " 2ND");
				if(i == 2) sprintf(string[0], " 3RD");
				if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
				printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
				
				sprintf(string[0], "%d", flaRankingScore[i]);
				printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
				
				sprintf(string[0], "%d", flaRankingStage[i] + 1);
				printFontGrid(14, 4 + i, string[0], 7 * (cursor == i));
				
				if(!flaRankingRand[i]) sprintf(string[0], "OFF");
				else sprintf(string[0], "ON");
				printFontGrid(20, 4 + i, string[0], 7 * (cursor == i));
				
				getTime(flaRankingTime[i]);
				printFontGrid(25, 4 + i, string[0], 7 * (cursor == i));
			}
			
			for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
			
			if(!erasemode) {
				// ���t�Ǝ���
				sprintf(string[0],
				        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
				        flaRankingYear[cursor], flaRankingMonth[cursor], flaRankingDay[cursor],
				        flaRankingHour[cursor], flaRankingMinute[cursor], flaRankingSecond[cursor]);
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
				
				// �����L���O�؂�ւ�
				if(getPushState(player, 2) || getPushState(player, 3)) {
					PlaySE(se_move);
					stmode = !stmode;
				}
			} else {
				printFontGrid(1, 24, "ERASE ALL RECORDS?", 2);
				printFontGrid(1, 26, "A:YES / B:NO", 2);
				
				// ����
				if(getPushState(player, 4)) {
					PlayWave(se_kettei);
					flaInitRanking();
					flaSaveRanking(player);
					erasemode = 0;
				}
				
				// �߂�
				if(getPushState(player, 5)) {
					PlaySE(se_move);
					erasemode = 0;
				}
			}
		} else {
			// �Z�N�V�����^�C�������L���O
			printFontGrid(1, 1, "<< SECTION TIME RANKING", 6);
			printFontGrid(1, 3, "NO. TIME     RAND DATE", 4);
			sprintf(string[0], "PAGE %d/5", page + 1);
			printFontGrid(1, 27, string[0], 6);
			printFontGrid(1, 28, "A/B:EXIT UP/DOWN:PAGE CHANGE", 6);
			
			for(i = 0; i < 20; i++) {
				temp = i + page * 20;
				
				sprintf(string[0], "%3d", temp + 1);
				printFontGrid(1, 4 + i, string[0], 0);
				
				getTime(flaRankingSectionTime[temp]);
				printFontGrid(5, 4 + i, string[0], 0);
				
				if(!flaRankingSectionRand[temp]) sprintf(string[0], "OFF");
				else sprintf(string[0], "ON");
				printFontGrid(14, 4 + i, string[0], 0);
				
				temp2 = (flaRankingSectionYear[temp] / 1000) * 1000;	// �N����2�������\��
				if(temp2 == 0) temp2 = 1;
				sprintf(string[0], "%02d/%02d/%02d", flaRankingSectionYear[temp] % temp2, flaRankingSectionMonth[temp], flaRankingSectionDay[temp]);
				printFontGrid(19, 4 + i, string[0], 0);
				
				sprintf(string[0], "%02d:%02d:%02d", flaRankingSectionHour[temp], flaRankingSectionMinute[temp], flaRankingSectionSecond[temp]);
				printFontGrid(28, 4 + i, string[0], 0);
			}
			
			// �y�[�W�ړ�
			padRepeat2(player);
			
			move = 0;
			if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
				move = getPressState(player, 1) - getPressState(player, 0);
			
			if(move) {
				PlaySE(se_kachi);
				page = page + move;
				if(page < 0) page = 4;
				if(page > 4) page = 0;
			}
			
			// �߂�
			if(getPushState(player, 4) || getPushState(player, 5)) {
				PlaySE(se_move);
				return;
			}
			
			// �����L���O�؂�ւ�
			if(getPushState(player, 2) || getPushState(player, 3)) {
				PlaySE(se_move);
				stmode = !stmode;
			}
		}
	}
}
