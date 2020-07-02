//BEGINNER-SCORE
//prefix:begs

// �o�[�W����
int begsVersion;		// �o�[�W�����ԍ��i�Â����v���C�Đ��p�j
int begsCVersion = 2;	// ���݂̃o�[�W����

// ���x���A�b�v�e�[�u��
// ���x
int begsLevelTable[32] = 
{
	4,5,6,8,10,12,16,32,48,64,4,5,6,8,12,32,48,80,112,128,144,16,48,80,112,144,176,192,208,224,240,5120
};

// ���x��
int begsLevelChange[32] = 
{
	8,19,35,40,50,60,70,80,90,100,108,119,125,131,139,149,156,164,174,180,200,212,221,232,244,256,267,277,287,295,300,10000
};

// BGM�ݒ�
int begsBgmNo[2] = {0,1};		// LV000�`299,LV300
int begsFadeLv = 280;			// BGM���t�F�[�h�A�E�g�����郌�x��

// ���i�ʂ̕\����
str begsStrSecretGradeName[19] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0�` 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9�`17
	"GM"													// 18
};

// �ϐ�
int begsModeNo = -1;			// ���[�h�ԍ�

int begsScore[2];				// �X�R�A

int begsLevel[2];				// ���x��
int begsLevelIndex[2];			// ���݂̑��x�ԍ�
int begsLevelSection[2];		// ���݂̃Z�N�V����

int begsItemFlag[2 * 2];		// �A�C�e���o���ς݃t���O
int begsItemCounter[2];			// �A�C�e�������p�J�E���^

int begsIsBig = 0;				// BIG���ǂ���
int begsBigMove = 1;			// BIG���̉��ړ��P��
int begsGhost = 0;				// �S�[�X�g�̐ݒ�i0=LV0-99 1=���ON 2=���OFF�j
int begsLvUpBonus = 0;			// ���x���A�b�v�{�[�i�X
int begsItemHold = 0;			// �A�C�e�����z�[���h�ł��邩�ǂ���
int begsStartLevel = 0;			// �X�^�[�g���̃��x��

// �����L���O�p�ϐ�
int begsRankingScore[10];		// �X�R�A
int begsRankingLevel[10];		// ���x��
int begsRankingTime[10];		// �^�C��
int begsRankingYear[10];		// �����N�C�������i�N�j
int begsRankingMonth[10];		// �����N�C�������i���j
int begsRankingDay[10];			// �����N�C�������i���j
int begsRankingHour[10];		// �����N�C�������i���j
int begsRankingMinute[10];		// �����N�C�������i���j
int begsRankingSecond[10];		// �����N�C�������i�b�j

// �C�x���g����
void begsPluginEvent(int player, int event, int *param) {
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != begsModeNo)) return;
	
	if(event == 0) {
		begsModeNo = addModePlugin("BEGINNER-SCORE");	// ���[�h��o�^����
	} else if(event == 7) {
		if(!ending[player]) begsMoveInit(player);	// �u���b�N�o��
	} else if(event == 10) {
		begsARE(player, param);	// ARE���i�A�C�e�������j
	} else if(event == 12) {
		if(!ending[player]) begsCalcScore(player, param[0], param[1]);	// �X�R�A�v�Z
	} else if(event == 15) {
		begsViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		begsSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		begsPlayerInitial(player);	// ����������
	} else if(event == 21) {
		begsResult(player);	// ���ʕ\��
	} else if(event == 25) {
		begsExcellent(player, param);	// �G���f�B���O�I��
	} else if(event == 28) {
		begsIncrementTime(player);	// ���Ԃ�i�߂�
	} else if(event == 36) {
		begsStaffRoll(player);	// �X�^�b�t���[���`��
	} else if(event == 38) {
		PlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		begsSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		begsLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		begsLoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		begsReplayDetail();	// ���v���C�ڍ�
	}
}

// ����������
void begsPlayerInitial(int player) {
	// �o�[�W����
	if(!playback) begsVersion = begsCVersion;
	
	// �ϐ���������
	begsScore[player] = 0;
	
	begsItemFlag[player * 2 + 0] = 0;
	begsItemFlag[player * 2 + 1] = 0;
	begsItemCounter[player] = 0;
	
	if((begsVersion >= 2) && (begsStartLevel > 0)) {
		begsLevel[player] = begsStartLevel * 100;
		begsLevelSection[player] = begsStartLevel;
		backno = begsStartLevel;
		
		if(begsStartLevel >= 1) begsItemFlag[player * 2 + 0] = 1;
		if(begsStartLevel >= 2) begsItemFlag[player * 2 + 1] = 1;
	} else {
		begsLevel[player] = -1;
		begsLevelSection[player] = 0;
	}
	
	begsLevelIndex[player] = 0;
	
	bgmlv = begsBgmNo[0];
	framecolor[player] = 0;
	enable_combo[player] = 1;
	
	// �ݒ�𔽉f������
	IsBig[player] = begsIsBig;
	BigMove[player] = begsBigMove;
	if(begsGhost == 2) ghost[player] = 0;
	enable_item_hold[player] = begsItemHold;
	
	// �����X�s�[�h��ݒ�
	begsSpeedUp(player);
}

// �X�s�[�h�A�b�v
void begsSpeedUp(int player) {
	// �X�s�[�h��ς���
	speedtype[player] = 2;
	if(begsVersion >= 2) {
		while(begsLevel[player] >= begsLevelChange[begsLevelIndex[player]]) begsLevelIndex[player]++;
	} else {
		if(begsLevel[player] >= begsLevelChange[begsLevelIndex[player]]) begsLevelIndex[player]++;
	}
	sp[player] = begsLevelTable[begsLevelIndex[player]];
	
	// BGM�t�F�[�h�A�E�g
	if((begsLevel[player] >= begsFadeLv) && (fadelv == 0) && (!ending[player])) {
		fadelv = 1;
	}
	
	// �S�[�X�g������
	if((begsLevel[player] >= 100) && (begsGhost == 0)) {
		ghost[player] = 0;
	}
}

// �u���b�N�o��
void begsMoveInit(int player) {
	// �ŏ��̃t���[���Ȃ�
	if(statc[player * 10 + 3] == 0) {
		// ���x���A�b�v����
		if(begsLevel[player] != 299) {
			begsLevel[player]++;
			if(begsLevel[player] == 299) PlaySE(se_lvstop);
			begsSpeedUp(player);
		}
		
		// FREE FALL�o��
		if((!begsItemFlag[player * 2 + 0]) && (begsLevel[player] >= 100)) {
			PlaySE(se_lvstop);
			item_coming[player] = 28;
			begsItemFlag[player * 2 + 0] = 1;
		}
		// DEL EVEN�o��
		else if((!begsItemFlag[player * 2 + 1]) && (begsLevel[player] >= 200)) {
			PlaySE(se_lvstop);
			item_coming[player] = 19;
			begsItemFlag[player * 2 + 1] = 1;
		}
	}
}

// ARE���i�A�C�e�������j
void begsARE(int player, int *param) {
	// FREE FALL������
	if(item_waiting[player] == 28) {
		begsFreeFall(player);
		param[0] = 1;
	}
	// DEL EVEN������
	else if(item_waiting[player] == 19) {
		begsDelEven(player);
		param[0] = 1;
	}
}

// �X�R�A�v�Z
void begsCalcScore(int player, int lines, int itemerase) {
	int temp, temp2, bo, bai;
	
	if(!itemerase) {
		if(begsVersion >= 1) {
			if(!begsLvUpBonus) temp = begsLevel[player] + lines;
			else temp = begsLevel[player] + lines + ((lines >= 3) * (lines - 2));
			if(temp > 300) temp = 300;
			
			temp2 = wait3[player] - bactivetime[player];
			if(temp2 < 0) temp2 = 0;
			
			bo = ((begsLevel[player] + lines) / 4 + sdrop[player] + qdrop[player] + qput[player]) * lines * cmbpts[player] + (temp / 2) + (temp2 * 7);
			bai = 6;
		} else {
			bo = (begsLevel[player] + lines) / 4 + sdrop[player] + qdrop[player] + qput[player];
			bai = (lines * 2 - 1 + cmbpts[player] - (lines * 2 - 2)) * lines * 6;
		}
		
		if(isBravo(player)) {
			// �S��������ƃX�R�A4�{
			objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			bai = bai * 4;
		}
		
		// �X�R�A���Z
		begsScore[player] = begsScore[player] + bo * bai;
	}
	
	// ���x���A�b�v
	if(!begsLvUpBonus) begsLevel[player] = begsLevel[player] + lines;
	else begsLevel[player] = begsLevel[player] + lines + ((lines >= 3) * (lines - 2));
	
	if(begsLevel[player] >= 300) {
		// �G���f�B���O
		PlaySE(se_ttclear);
		begsLevel[player] = 300;
		timeOn[player] = 0;
		ending[player] = 2;
		ending_timeOn[player] = 1;
		fastroll[player] = 1;
		
		// �^�C���{�[�i�X
		if(gameTimer[player] < 18000) {
			temp = 1253 * (300 - (gameTimer[player] / 60));
			if(temp > 0) begsScore[player] = begsScore[player] + temp;
		}
		
		// �w�i�؂�ւ�
		begsLevelSection[player]++;
		bgfadesw = 1;
		bgfadebg = begsLevelSection[player];
		
		// ���y�؂�ւ�
		bgmlv = begsBgmNo[1];
		PlayBGM();
	} else {
		// ���x���X�g�b�v��
		if(begsLevel[player] == 299) PlaySE(se_lvstop);
		
		if(begsLevel[player] >= (begsLevelSection[player] + 1) * 100) {
			// ���x���A�b�v��
			PlaySE(se_levelup);
			
			// �w�i�؂�ւ�
			begsLevelSection[player]++;
			bgfadesw = 1;
			bgfadebg = begsLevelSection[player];
		}
	}
	
	// �X�s�[�h�A�b�v
	begsSpeedUp(player);
}

// ���Ԃ�i�߂�
void begsIncrementTime(int player) {
	int i;
	
	// F�{�^���ō������[��������
	if((ending_timeOn[player]) && (onRecord[player]) && (fastroll[player] == 1) && (getPressState(player, 9)))
		edrec[player] = edrec[player] + 2;
	
	// ���[���I��
	if((ending[player] == 2) && (edrec[player] >= 60 * 60)) {
		ending[player] = 3;
		stat[player] = 10;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
}

// �X�^�b�t���[���`��
void begsStaffRoll(int player) {
	// F�{�^���ō������[��������
	if((ending_timeOn[player]) && (onRecord[player]) && (fastroll[player] == 1) && (getPressState(player, 9))) {
		endtime[player] = endtime[player] + 2;
		if(endtime[player] < 3100) staff_c[player]++;
	}
}

// FREE FALL
void begsFreeFall(int player) {
	int i, j, x, y, tmp, lines, anim;
	
	// �t�B�[���h��Ɏc���Ă���A�C�e�����ׂď���
	if(begsItemCounter[player] == 0) {
		cleanupItem(player);
		scanItem(player);
	}
	
	if(wait1[player] > 0) anim = wait1[player];
	else anim = 1;
	
	// �A�j���[�V����
	if(begsItemCounter[player] < anim + 25) {
		fyoffset[player] = fyoffset[player] - 2;
	} else if(begsItemCounter[player] < anim + 30) {
		fyoffset[player] = fyoffset[player] + 10;
	}
	
	// ���R��������
	if(begsItemCounter[player] == anim + 30) {
		PlaySE(se_gon);
		setFieldPosition(player, maxPlay);
		
		for(y = 20; y >= 0; y--) {
			for(i = 0; i < 10; i++) {
				// �u���b�N����1�i�����󔒂Ȃ�
				if((fld[i + y * 10 + player * 220] != 0) && (fld[i + (y + 1) * 10 + player * 220] == 0)) {
					tmp = y;
					
					do {
						if(tmp + 1 > 21) break;	// �ŉ��i�ɓ��B
						
						j = fld[i + tmp * 10 + player * 220];
						fld[i + tmp * 10 + player * 220] = 0;
						fld[i + (tmp + 1) * 10 + player * 220] = j;
						
						j = fldt[i + tmp * 10 + player * 220];
						fldt[i + tmp * 10 + player * 220] = 0;
						fldt[i + (tmp + 1) * 10 + player * 220] = j;
						
						j = fldo[i + tmp * 10 + player * 220];
						fldo[i + tmp * 10 + player * 220] = 0;
						fldo[i + (tmp + 1) * 10 + player * 220] = j;
						
						j = fldl[i + tmp * 10 + player * 220];
						fldl[i + tmp * 10 + player * 220] = 0;
						fldl[i + (tmp + 1) * 10 + player * 220] = j;
						
						j = fldi[i + tmp * 10 + player * 220];
						fldi[i + tmp * 10 + player * 220] = 0;
						fldi[i + (tmp + 1) * 10 + player * 220] = j;
						
						tmp++;
					} while(fld[i + (tmp + 1) * 10 + player * 220] == 0);
				}
			}
		}
	}
	
	// ��������i�Ȃ���Ύ��̃X�e�[�^�X�ցj
	if(begsItemCounter[player] == (anim * 2) + 30) {
		if(blockEraseJudge(player) == 0) {
			// �����Ȃ�
			begsItemCounter[player] = -1;
		} else {
			// ��������
			PlaySE(se_erase[0]);
			lines = 0;
			
			// ��������
			for(i = 0; i < 22; i++) {
				if(erase[i + player * 22]) {
					lines++;
					
					for(x = 0; x < 10; x++) {
						// �����G�t�F�N�g�\��
						j = (show_all_break_effect[player] != 0);
						j = (j) || (fld[x + i * 10 + player * 220] >= 10);
						j = (j) || ((lines & 1 != 0) && (x & 1 == 1)) || ((lines & 1 == 0) && (x & 1 == 0));
						
						if((j != 0) && (breaktype != 0) && (!fldo[x + i * 10 + player * 220])) {
							objectCreate(player, 1, foffset[player] + 8 + (x * 8), fyoffset[player] + (i + 3) * 8, (x - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + lines * 250, fld[x + i * 10 + player * 220] - 1, 100);
						}
						
						// �u���b�N������
						fld[x + i * 10 + player * 220] = 0;
						fldt[x + i * 10 + player * 220] = 0;
						fldo[x + i * 10 + player * 220] = 0;
						fldl[x + i * 10 + player * 220] = 0;
						fldi[x + i * 10 + player * 220] = 0;
					}
				}
			}
		}
	}
	
	// �������������ꍇ�̗�������
	if(begsItemCounter[player] == (anim * 2) + 30 + wait2[player]) {
		downFloatingBlocks(player);
		PlaySE(se_gon);
		begsItemCounter[player] = -1;
	}
	
	if(begsItemCounter[player] >= 0) {
		// �J�E���^����
		begsItemCounter[player]++;
	} else {
		// �I��
		pinchCheck(player);
		begsItemCounter[player] = 0;
		item_waiting[player] = 0;
	}
}

// DEL EVEN
void begsDelEven(int player) {
	int i, j, anim;
	
	if(wait1[player] > 0) {
		anim = wait1[player];
	} else {
		anim = 1;
	}
	
	begsItemCounter[player]++;
	
	if(begsItemCounter[player] == 1) {
		// �ǂ����������邩���߂�
		for(i = 22; i > checkFieldTop(player); i--) {
			erase[i + player * 22] = 1;
			i--;
		}
		
		// �t�B�[���h��Ɏc���Ă���A�C�e�����ׂď���
		cleanupItem(player);
		scanItem(player);
		
		// �g�̐F��ς���
		framecolor[player] = 6;
	}
	
	// ���C������
	if(begsItemCounter[player] < 15 + (anim * 2)) {
		for(i = 0; i < 22; i++) {
			if(erase[i + player * 22]) {
				if(begsItemCounter[player] < 16) {
					ExBltRect(sg_spr, foffset[player] + 8, fyoffset[player] + (i + 3) * 8, 8, 165 + (begsItemCounter[player] - 1) * 8, 80, 8);
				}
				
				if(begsItemCounter[player] == 1) {
					for(j = 0; j < 10; j++) {
						fld[j + i * 10 + player * 220] = 0;
						fldt[j + i * 10 + player * 220] = 0;
						fldo[j + i * 10 + player * 220] = 0;
						fldl[j + i * 10 + player * 220] = 0;
						fldi[j + i * 10 + player * 220] = 0;
					}
				}
			}
		}
	}
	
	// ��������
	if(begsItemCounter[player] == 15 + (anim * 2)) {
		downFloatingBlocks(player);
		PlaySE(se_gon);
	}
	
	// �I��
	if(begsItemCounter[player] > 15 + (anim * 2)) {
		for(i = 0; i < 22; i++) erase[i + player * 22] = 0;
		framecolor[player] = 0;
		pinchCheck(player);
		begsItemCounter[player] = 0;
		item_waiting[player] = 0;
	}
}

// BGM�ǂݍ���
void begsLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 2; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/2)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(begsBgmNo[i]);
		}
	}
}

// �X�R�A�\��
void begsViewScore(int player) {
	int color;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// �X�R�A
	printTinyFont(foffset[player] + 96, fyoffset[player] + 135, "SCORE");
	sprintf(string[0], "%d", begsScore[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 143, string[0], color);
	
	// ���x���i���q�j
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(begsLevel[player] == -1) sprintf(string[0], "%4d", 0);	// -1�Ȃ�0�ƕ\������(�����I�ɂ͍ŏ���-1�ɂȂ��Ă���)
	else sprintf(string[0], "%4d", begsLevel[player]);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// ���x���i�����j
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	if(sp[player] <= 600) {
		ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22 - ((sp[player] * 24) / 660), 143, 22, 1);
	} else {
		ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 0, 143, 22, 1);
	}
	
	// ���x���i����j
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, " 300", color);
	
	// �^�C��
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
}

// �G���f�B���O�I��
void begsExcellent(int player, int *param) {
	onRecord[player] = 0;
	statc[player * 10 + 1]++;
	
	printTinyFont(foffset[player] + 15, fyoffset[player] + 116, "BEGINNER MODE");
	printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
	
	// �ԉ�
	if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 2]++;
	}
}

// ���ʕ\��
void begsResult(int player) {
	if(statc[player * 10] == 0) {
		// �����L���O�o�^
		statc[player * 10 + 1] = begsRegistRanking(player);
		if(statc[player * 10 + 1] != -1) begsSaveRanking(player);
		
		// ���i�ʔ���
		statc[player * 10 + 2] = checkSecretGrade(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "SCORE");
	sprintf(string[0], "%13d", begsScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", begsLevel[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "TIME");
	getTime(gameTimer[player]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[1], 0);
	
	if(statc[player * 10 + 1] != -1) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 139, "RANK");
		sprintf(string[0], "%13d", statc[player * 10 + 1] + 1);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 147, string[0], 0);
	}
	
	if(statc[player * 10 + 2] >= 4) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 159, "SECRET GRADE");
		sprintf(string[0], "%13s", begsStrSecretGradeName[statc[player * 10 + 2]]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
	}
}

// �ݒ���
void begsSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// �ݒ��ǂݍ���
	if(begsLoadConfig() == 0) begsSaveConfig();
	
	// �����L���O��ǂݍ���
	if(begsLoadRanking(player) == 0) begsInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "BEGINNER-SCORE OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "BIG",            7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",       7 * (cursor == 1));
		printFontGrid(2, 5, "GHOST BLOCK",    7 * (cursor == 2));
		printFontGrid(2, 6, "LEVEL UP BONUS", 7 * (cursor == 3));
		printFontGrid(2, 7, "ITEM HOLD",      7 * (cursor == 4));
		printFontGrid(2, 8, "START LEVEL",    7 * (cursor == 5));
		
		// �ݒ�l�\��
		if(!begsIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!begsBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(begsGhost == 0) sprintf(string[0], "LV100");
		else if(begsGhost == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(!begsLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(!begsItemHold) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		sprintf(string[0], "%d", begsStartLevel * 100);
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		// �J�[�\���ړ�
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 5;
			if(cursor > 5) cursor = 0;
		}
		
		// �l��ύX
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) begsIsBig = !begsIsBig;
			if(cursor == 1) begsBigMove = !begsBigMove;
			if(cursor == 2) {
				begsGhost = begsGhost + move;
				if(begsGhost < 0) begsGhost = 2;
				if(begsGhost > 2) begsGhost = 0;
			}
			if(cursor == 3) begsLvUpBonus = !begsLvUpBonus;
			if(cursor == 4) begsItemHold = !begsItemHold;
			if(cursor == 5) {
				begsStartLevel = begsStartLevel + move;
				if(begsStartLevel < 0) begsStartLevel = 2;
				if(begsStartLevel > 2) begsStartLevel = 0;
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
			begsSaveConfig();
			return;
		}
		
		// �����L���O
		if(getPushState(player, 8)) {
			begsViewRanking(player);
		}
	}
}

// �ݒ��ۑ�
void begsSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x49474542;
	saveBuf[1] = 0x52454E4E;
	saveBuf[2] = 0x4F43532D;
	saveBuf[3] = 0x31764552;
	
	// �ݒ���e
	saveBuf[4] = begsIsBig;
	saveBuf[5] = begsBigMove;
	saveBuf[6] = begsGhost;
	saveBuf[7] = begsLvUpBonus;
	saveBuf[8] = begsItemHold;
	saveBuf[9] = begsStartLevel;
	
	SaveFile("config/BEGINNER_SCORE_CONFIG.SAV", &saveBuf, 100 * 4);
}

// �ݒ��ǂݍ���
int begsLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/BEGINNER_SCORE_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 0x49474542) return 0;
	if(saveBuf[1] != 0x52454E4E) return 0;
	if(saveBuf[2] != 0x4F43532D) return 0;
	if(saveBuf[3] != 0x31764552) return 0;
	
	// �ݒ���e
	begsIsBig = saveBuf[4];
	begsBigMove = saveBuf[5];
	begsGhost = saveBuf[6];
	begsLvUpBonus = saveBuf[7];
	begsItemHold = saveBuf[8];
	begsStartLevel = saveBuf[9];
	
	return 1;
}

// ���v���C�ۑ�
void begsSaveReplay(int player) {
	saveBuf[900] = begsIsBig;
	saveBuf[901] = begsBigMove;
	saveBuf[902] = begsGhost;
	saveBuf[903] = begsLvUpBonus;
	saveBuf[904] = begsItemHold;
	saveBuf[905] = begsLevel[player];
	saveBuf[906] = begsScore[player];
	saveBuf[907] = begsVersion;
	saveBuf[908] = begsStartLevel;
}

// ���v���C�ǂݍ���
void begsLoadReplay(int player) {
	begsIsBig = saveBuf[900];
	begsBigMove = saveBuf[901];
	begsGhost = saveBuf[902];
	begsLvUpBonus = saveBuf[903];
	begsItemHold = saveBuf[904];
	begsVersion = saveBuf[907];
	begsStartLevel = saveBuf[908];
	
	begsPlayerInitial(player);	// �ݒ�𔽉f������
}

// ���v���C�ڍ�
void begsReplayDetail() {
	printFontGrid(1, 5, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[906]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[905]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 8, "BIG", 0);
	if(!saveBuf[900]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "BIG MOVE", 0);
	if(!saveBuf[901]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "GHOST BLOCK", 0);
	if(saveBuf[902] == 0) sprintf(string[0], "LV100");
	else if(saveBuf[902] == 1) sprintf(string[0], "ON");
	else sprintf(string[0], "OFF");
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "LEVEL UP BONUS", 0);
	if(!saveBuf[903]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "ITEM HOLD", 0);
	if(!saveBuf[904]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 12, string[0], 0);
	
	printFontGrid(1, 13, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[908] * 100);
	printFontGrid(22, 13, string[0], 0);
	
	printFontGrid(1, 14, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[907]);
	printFontGrid(22, 14, string[0], 0);
}

// �����L���O�ۑ�
void begsSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 10) + 0] = begsRankingScore[i];
		saveBuf[1 + (i * 10) + 1] = begsRankingLevel[i];
		saveBuf[1 + (i * 10) + 2] = begsRankingTime[i];
		saveBuf[1 + (i * 10) + 3] = begsRankingYear[i];
		saveBuf[1 + (i * 10) + 4] = begsRankingMonth[i];
		saveBuf[1 + (i * 10) + 5] = begsRankingDay[i];
		saveBuf[1 + (i * 10) + 6] = begsRankingHour[i];
		saveBuf[1 + (i * 10) + 7] = begsRankingMinute[i];
		saveBuf[1 + (i * 10) + 8] = begsRankingSecond[i];
	}
	
	sprintf(string[0], "config/BEGINNER_SCORE_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 111 * 4);
}

// �����L���O�ǂݍ���
int begsLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/BEGINNER_SCORE_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 111 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	for(i = 0; i < 10; i++) {
		begsRankingScore[i]  = saveBuf[1 + (i * 10) + 0];
		begsRankingLevel[i]  = saveBuf[1 + (i * 10) + 1];
		begsRankingTime[i]   = saveBuf[1 + (i * 10) + 2];
		begsRankingYear[i]   = saveBuf[1 + (i * 10) + 3];
		begsRankingMonth[i]  = saveBuf[1 + (i * 10) + 4];
		begsRankingDay[i]    = saveBuf[1 + (i * 10) + 5];
		begsRankingHour[i]   = saveBuf[1 + (i * 10) + 6];
		begsRankingMinute[i] = saveBuf[1 + (i * 10) + 7];
		begsRankingSecond[i] = saveBuf[1 + (i * 10) + 8];
	}
	
	return 1;
}

// �����L���O������
void begsInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		begsRankingScore[i]  = 0;
		begsRankingLevel[i]  = 0;
		begsRankingTime[i]   = 0;
		begsRankingYear[i]   = 0;
		begsRankingMonth[i]  = 0;
		begsRankingDay[i]    = 0;
		begsRankingHour[i]   = 0;
		begsRankingMinute[i] = 0;
		begsRankingSecond[i] = 0;
	}
}

// �����L���O�o�^
int begsRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (begsIsBig) || (begsLvUpBonus) || (begsStartLevel)) return -1;
	
	for(i = 0; i < 10; i++) {
		// �����N�C��
		if( (begsScore[player] > begsRankingScore[i]) || 
		    ((begsScore[player] == begsRankingScore[i]) && (begsLevel[player] > begsRankingLevel[i])) || 
		    ((begsScore[player] == begsRankingScore[i]) && (begsLevel[player] == begsRankingLevel[i]) && (gameTimer[player] < begsRankingTime[i])) )
		{
			// �����L���O�����炷
			for(j = 9; j > i; j--) {
				begsRankingScore[j]  = begsRankingScore[j - 1];
				begsRankingLevel[j]  = begsRankingLevel[j - 1];
				begsRankingTime[j]   = begsRankingTime[j - 1];
				begsRankingYear[j]   = begsRankingYear[j - 1];
				begsRankingMonth[j]  = begsRankingMonth[j - 1];
				begsRankingDay[j]    = begsRankingDay[j - 1];
				begsRankingHour[j]   = begsRankingHour[j - 1];
				begsRankingMinute[j] = begsRankingMinute[j - 1];
				begsRankingSecond[j] = begsRankingSecond[j - 1];
			}
			
			// �V�����f�[�^��o�^
			begsRankingScore[i]  = begsScore[player];
			begsRankingLevel[i]  = begsLevel[player];
			begsRankingTime[i]   = gameTimer[player];
			
			GetDateAndTime(&timebuf);
			begsRankingYear[i]   = timebuf[0];
			begsRankingMonth[i]  = timebuf[1];
			begsRankingDay[i]    = timebuf[2];
			begsRankingHour[i]   = timebuf[4];
			begsRankingMinute[i] = timebuf[5];
			begsRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// �����L���O�\��
void begsViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "BEGINNER-SCORE MODE RANKING", 6);
		printFontGrid(1, 3, "RANK SCORE              LEVEL TIME", 4);
		
		for(i = 0; i < 10; i++) {
			if(begsRankingLevel[i] >= 300) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, 0, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", begsRankingScore[i]);
			printFontGrid(6, 4 + i, string[0], 7 * (cursor == i));
			
			sprintf(string[0], "%d", begsRankingLevel[i]);
			printFontGrid(25, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(begsRankingTime[i]);
			printFontGrid(31, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// ���t�Ǝ���
			sprintf(string[0],
			        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
			        begsRankingYear[cursor], begsRankingMonth[cursor], begsRankingDay[cursor],
			        begsRankingHour[cursor], begsRankingMinute[cursor], begsRankingSecond[cursor]);
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
		} else {
			printFontGrid(1, 24, "ERASE ALL RECORDS?", 2);
			printFontGrid(1, 26, "A:YES / B:NO", 2);
			
			// ����
			if(getPushState(player, 4)) {
				PlayWave(se_kettei);
				begsInitRanking();
				begsSaveRanking(player);
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
