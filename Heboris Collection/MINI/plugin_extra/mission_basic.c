//prefix:misb

//������������������������������������������������������������������������������
//
//    MISSION-BASIC
//    Version 0
//
//������������������������������������������������������������������������������

//������������������������������������������������������������������������������
//   �O���[�o���ϐ��̒�`
//������������������������������������������������������������������������������
// �V�X�e��
int		misbModeNo = -1;			// ���[�h�ԍ�
int		misbVersion;				// �o�[�W�����ԍ��i�Â����v���C�Đ��p�j
int		misbCVersion = 1;			// ���݂̃o�[�W����

// ���݂̃Q�[���̏�
int		misbCourseNo;				// ���݂̃R�[�X
int		misbMissionNo;				// ���݂̃~�b�V�����ԍ�
int		misbNormCurrent;			// �B���m���}
int		misbNormMax;				// �ڕW�m���}
int		misbTimer;					// �c�莞��
int		misbLastLine;				// �Ō�̃��C������
int		misbIgnoreTorikan;			// ���؂薳����
int		misbClearFlag;				// �~�b�V�����N���A�t���O
int		misbIsAllClear;				// 1=���؂� 2=���S�N���A
int		misbScreen;					// stat[0] == 2�̎��̓���i0=���C�����������P 1=���C�����������Q�j

// �~�b�V�����̏�
int		misbCycle[4];				// �T�C�N���p�t���O

int		misbEraserLinePos[4];		// �C���C�T�[�̃��C���̈ʒu
int		misbEraserLineClear[4];		// �C���C�T�[�̃��C�������ς݃t���O
int		misbEraserNowLines;			// �C���C�T�[�̃��C����
int		misbEraserPatternNo;		// �C���C�T�[�̏o���p�^�[���ԍ��i�S�Ẵ��C����������+1�j

int		misbTargetStageFlag[10000];	// �^�[�Q�b�g�̃X�e�[�W�o���ς݃t���O
int		misbTargetPatternNo;		// �^�[�Q�b�g�̏o���p�^�[���ԍ�

// �e�~�b�V�����̃f�[�^
int		misbMType[40];				// ���
int		misbMNorm[40];				// �m���}
int		misbMLevel[40];				// ���x��
int		misbMTimeLimit[40];			// ��������
int		misbMBgm[40];				// BGM
int		misbMBackground[40];		// �w�i
int		misbMErase[40];				// �N���A���ɏォ��������郉�C����
int		misbMEndFlag[40];			// �I���t���O
int		misbMParam[20 * 40];		// �p�����[�^

// �R�[�X�S�ʂ̃I�v�V����
int		misbExcellentType;			// �I�[���N���A���̉��o
int		misbHideInfo;				// �w�߂��\��
str*	misbCourseName;				// �R�[�X��

// �Q�[���I�v�V����
int		misbLastCourse = 0;			// �Ō�ɑI�������R�[�X
int		misbStartMissionNo = 0;		// �X�^�[�g���̃~�b�V�����ԍ�
int		misbGhost = 1;				// �S�[�X�g�L���t���O

//������������������������������������������������������������������������������
//   ���x���A�b�v�e�[�u��
//������������������������������������������������������������������������������
// �m�[�}��
int		misbNormalLevelTable[15] = {1, 3, 12, 18, 24, 30, 60, 120, 150, 180, 240, 300, 1200, 1200, 1200};
int		misbNormalWait1 = 25;	// �Œ聨��
int		misbNormalWait2 = 40;	// �u���b�N����
int		misbNormalWait3 = 30;	// �ڒn���Œ�
int		misbNormalWaitt = 16;	// ������

// �A�i�U�[
int		misbAnotherWait1Table[15] = {18,14,14,14,12,12,10, 8, 7, 6, 6, 6, 6, 6, 6};	// �Œ聨��
int		misbAnotherWait2Table[15] = {14, 8, 8, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4};	// �u���b�N����
int		misbAnotherWait3Table[15] = {28,24,22,20,18,14,14,13,13,13,13,13,13,13,13};	// �ڒn���Œ�
int		misbAnotherWaittTable[15] = {10,10, 9, 9, 9, 8, 8, 7, 7, 7, 7, 7, 7, 7, 7};	// ������

//������������������������������������������������������������������������������
//   ������f�[�^
//������������������������������������������������������������������������������
// �~�b�V������
str misbStringMissionNameJ[13] = 
{
	"���x���X�^�[",								// 0
	"�n�C�X�s�[�h�Q",							// 1
	"�A�i�U�[",									// 2
	"���x�Œ�",									// 3
	"�r�b�O",									// 4
	"�V���O��",									// 5
	"�_�u��",									// 6
	"�g���v��",									// 7
	"�w�{���X",									// 8
	"�T�C�N��",									// 9
	"�C���C�T�[",								// 10
	"�^�[�Q�b�g",								// 11
	"�C���C�T�[",								// 12
};
str misbStringMissionNameE[13] = 
{
	"Level star",								// 0
	"Hi-Speed 2",								// 1
	"Another",									// 2
	"Speed Lock",								// 3
	"Big",										// 4
	"Single",									// 5
	"Double",									// 6
	"Triple",									// 7
	"Heboris",									// 8
	"Cycle",									// 9
	"Eraser",									// 10
	"Target",									// 11
	"Eraser",									// 12
};
str misbStringMissionNameCourseEdit[13] = 
{
	"LEVEL STAR",								// 0
	"HI-SPEED 2",								// 1
	"ANOTHER",									// 2
	"SPEED LOCK",								// 3
	"BIG",										// 4
	"SINGLE",									// 5
	"DOUBLE",									// 6
	"TRIPLE",									// 7
	"HEBORIS",									// 8
	"CYCLE",									// 9
	"ERASER",									// 10
	"TARGET",									// 11
	"ERASER (NO RANDOM)",						// 12
};

// �w��
str misbStringMissionInfoJ[13] = 
{
	"%d���C�������I",							// 0
	"%d���C�������I",							// 1
	"%d���C�������I",							// 2
	"%d���C�������I",							// 3
	"%d���C�������I",							// 4
	"%d��V���O�������߂�I",					// 5
	"%d��_�u�������߂�I",						// 6
	"%d��g���v�������߂�I",					// 7
	"%d��w�{���X�����߂�I",					// 8
	"�T�C�N�������߂�I",						// 9
	"%d���C�������I",							// 10
	"%d�X�e�[�W�N���A����I",					// 11
	"%d���C�������I",							// 12
};
str misbStringMissionInfoE[13] = 
{
	"Erase %d line(s)!",						// 0
	"Erase %d line(s)!",						// 1
	"Erase %d line(s)!",						// 2
	"Erase %d line(s)!",						// 3
	"Erase %d line(s)!",						// 4
	"Erase 1 line only\n%d time(s)!",			// 5
	"Erase 2 lines at once\n%d time(s)!",		// 6
	"Erase 3 lines at once\n%d time(s)!",		// 7
	"Erase 4 lines at once\n%d time(s)!",		// 8
	"Do all kinds of\nline erase!",				// 9
	"Erase %d line(s)!",						// 10
	"Clear %d stage(s)!",						// 11
	"Erase %d line(s)!",						// 12
};

int misbStringMax = 12;

//������������������������������������������������������������������������������
//   �C�x���g�������̃��C���֐�
//������������������������������������������������������������������������������
void misbPluginEvent(int player, int event, int *param) {
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != misbModeNo)) return;
	
	if(event == 0) {
		misbAddMode();	// ���[�h�o�^
	} else if(event == 5) {
		misbReady(player, param);	// Ready
	} else if(event == 10) {
		if(!ending[player]) misbOnARE(player, param);	// ARE���̏���
	} else if(event == 12) {
		if(!ending[player]) misbCalcScore(player, param[0]);	// ���C���������̏���
	} else if(event == 15) {
		misbViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		misbSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		misbPlayerInitial(player);	// �Q�[���J�n���̏�����
	} else if(event == 21) {
		misbResult(player);	// ���ʕ\��
	} else if(event == 24) {
		misbEndingStart(player);	// �G���f�B���O�˓�
	} else if(event == 25) {
		misbExcellent(player, param);	// EXCELLENT���
	} else if(event == 28) {
		misbIncrementTime(player);	// ���Ԃ�i�߂�
	} else if(event == 34) {
		misbViewEraserLines(player);	// �C���C�T�[�̐���\��
	} else if(event == 38) {
		misbPlayBGM();	// BGM�Đ�
	} else if(event == 39) {
		misbSaveReplay(player);	// ���v���C�ۑ�
	} else if(event == 40) {
		misbLoadReplay(player);	// ���v���C�ǂݍ���
	} else if(event == 41) {
		misbLoadBGM();	// BGM�ǂݍ���
	} else if(event == 55) {
		misbReplayDetail();	// ���v���C�ڍ�
	} else if(event == 68) {
		if(misbScreen == 0) misbStatDelLineNormal(player);	// ���C�����������P
		if(misbScreen == 1) misbStatDelLineExtra(player);	// ���C�����������Q
	}
}

//������������������������������������������������������������������������������
//   �C�x���gNo.0 - ���[�h�o�^
//������������������������������������������������������������������������������
void misbAddMode() {
	misbModeNo = addModePlugin("MISSION-BASIC");	// ���[�h��o�^����
	misbCourseName = new(16);	// �R�[�X���Ɏg�p���郁�������m��
	StrCpy(misbCourseName, "");	// �R�[�X������ŏ�����
}

//������������������������������������������������������������������������������
//   �C�x���gNo.18 - �Q�[���J�n���̏�����
//������������������������������������������������������������������������������
void misbPlayerInitial(int player) {
	// �o�[�W����
	if(!playback) misbVersion = misbCVersion;
	
	// �g�̐F���D�F�ɂ���
	framecolor[player] = 5;
	frame_decoration[player] = 1;
	
	// ����󋵂̕\���ʒu
	if(!misbHideInfo) coffset = 221;
	else coffset = s_coffset;
	
	// �ϐ���������
	misbNormCurrent = 0;
	misbNormMax = 0;
	misbTimer = 0;
	misbLastLine = 0;
	misbIgnoreTorikan = 0;
	misbClearFlag = 0;
	misbIsAllClear = 0;
	misbScreen = 0;
	
	// �ݒ�𔽉f������
	misbApplyGameSetting(player);
}

// �ݒ�𔽉f������
void misbApplyGameSetting(int player) {
	misbCourseNo = misbLastCourse;
	misbMissionNo = misbStartMissionNo;
	if(!misbGhost) ghost[player] = 0;
}

//������������������������������������������������������������������������������
//   �C�x���gNo.12 - ���C���������̏���
//������������������������������������������������������������������������������
void misbCalcScore(int player, int lines) {
	int i, temp;
	
	// �Ō�̃��C�������̎�ނ��L��
	misbLastLine = lines;
	
	// �S����
	if(isBravo(player)) {
		PlaySE(se_levelup);
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
	}
	
	// ���x���X�^�[�`�r�b�O
	if(misbMType[misbMissionNo] <= 4) {
		misbNormCurrent = misbNormCurrent + lines;
	}
	// �V���O��
	if(misbMType[misbMissionNo] == 5) {
		if(lines == 1) misbNormCurrent++;
	}
	// �_�u��
	if(misbMType[misbMissionNo] == 6) {
		if(lines == 2) misbNormCurrent++;
	}
	// �g���v��
	if(misbMType[misbMissionNo] == 7) {
		if(lines == 3) misbNormCurrent++;
	}
	// �w�{���X
	if(misbMType[misbMissionNo] == 8) {
		if(lines == 4) misbNormCurrent++;
	}
	// �T�C�N��
	if(misbMType[misbMissionNo] == 9) {
		if(!misbCycle[lines - 1]) {
			misbCycle[lines - 1] = 1;
			misbNormCurrent++;
		}
	}
	// �C���C�T�[
	if((misbMType[misbMissionNo] == 10) || (misbMType[misbMissionNo] == 12)) {
		// �����郉�C���𒲂ׂ�
		temp = misbEraserNowLines;
		for(i = 0; i < misbEraserNowLines; i++) {
			if(!misbEraserLineClear[i]) {
				if(erase[misbEraserLinePos[i]]) {
					misbEraserLineClear[i] = 1;
					misbNormCurrent++;
					temp--;
				}
			} else {
				temp--;
			}
		}
		
		// �S�������Ă��܂��m���}���c���Ă�Ȃ玟�̃p�^�[����
		if((misbNormCurrent < misbNormMax) && (temp <= 0)) {
			misbEraserPatternNo++;
			if(misbMType[misbMissionNo] == 10) misbSetRandomEraserLines();
			if(misbMType[misbMissionNo] == 12) misbSetNormalEraserLines();
		}
	}
	// �^�[�Q�b�g
	if(misbMType[misbMissionNo] == 11) {
		if(!checkHowManyPBlocks(0)) {
			misbNormCurrent++;
			StopSE(se_hurryup);
			timeOn[player] = 0;
		}
	}
	
	// �~�b�V�����N���A
	if(misbNormCurrent >= misbNormMax) {
		// ���ꐯ
		if( ((misbMEndFlag[misbMissionNo] == 2) || (misbMEndFlag[misbMissionNo] == 3)) && (misbLastLine == 2) )
			objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
		
		misbNormCurrent = misbNormMax;
		StopSE(se_hurryup);
		timeOn[player] = 0;
		misbClearFlag = 1;
	}
}

//������������������������������������������������������������������������������
//   �C�x���gNo.5 - Ready
//������������������������������������������������������������������������������
void misbReady(int player, int *param) {
	// �ŏ��̃t���[���̏���
	if(!statc[player * 10]) {
		// �~�b�V�����J�n���̏���
		if((misbClearFlag) || (ready_count[player] == 0)) {
			misbSetMissionStatus();
		}
		// �^�[�Q�b�g�̃X�e�[�W�ǂݍ���
		else if(misbMType[misbMissionNo] == 11) {
			misbTargetStartNewStage();
		}
	}
}

// �~�b�V�����J�n���̏���
void misbSetMissionStatus() {
	int i, temp, use_custom_speed;
	use_custom_speed = 0;
	
	misbNormCurrent = 0;
	misbNormMax = misbMNorm[misbMissionNo];
	if(misbNormMax == 0) misbNormMax = 1;
	misbTimer = misbMTimeLimit[misbMissionNo];
	misbClearFlag = 0;
	
	if(ready_count[0] == 0) {
		if(misbMBackground[misbMissionNo] > 0) backno = misbMBackground[misbMissionNo] - 1;
	} else if(misbMBackground[misbMissionNo] == 0) {
		bgfadesw = 1;
		bgfadebg = backno + 1;
		if(bgfadebg > 19) bgfadebg = 0;
	} else if(backno != misbMBackground[misbMissionNo] - 1) {
		bgfadesw = 1;
		bgfadebg = misbMBackground[misbMissionNo] - 1;
	}
	
	if((bgmlv != misbMBgm[misbMissionNo]) && (fadelv == 0)) fadelv = 1;
	
	IsBig[0] = 0;
	
	// �n�C�X�s�[�h�Q
	if(misbMType[misbMissionNo] == 1) {
		sp[0] = 1200;
		speedtype[0] = 0;
		wait1[0] = misbNormalWait1;
		wait2[0] = misbNormalWait2;
		wait3[0] = misbNormalWait3;
		waitt[0] = misbNormalWaitt;
		use_custom_speed = 1;
	}
	// �A�i�U�[
	if(misbMType[misbMissionNo] == 2) {
		if(misbMLevel[misbMissionNo] < 15) {
			temp = misbMLevel[misbMissionNo];
		} else {
			temp = misbMLevel[misbMissionNo] - 15;
		}
		
		sp[0] = 1200;
		speedtype[0] = 0;
		wait1[0] = misbAnotherWait1Table[temp];
		wait2[0] = misbAnotherWait2Table[temp];
		wait3[0] = misbAnotherWait3Table[temp];
		waitt[0] = misbAnotherWaittTable[temp];
		use_custom_speed = 1;
	}
	// ���x�Œ�
	if(misbMType[misbMissionNo] == 3) {
		sp[0] = misbMParam[misbMissionNo * 20 + 0];
		speedtype[0] = misbMParam[misbMissionNo * 20 + 1];
		wait1[0] = misbMParam[misbMissionNo * 20 + 2];
		wait2[0] = misbMParam[misbMissionNo * 20 + 3];
		wait3[0] = misbMParam[misbMissionNo * 20 + 4];
		waitt[0] = misbMParam[misbMissionNo * 20 + 5];
		IsBig[0] = misbMParam[misbMissionNo * 20 + 6];
		BigMove[0] = misbMParam[misbMissionNo * 20 + 7];
		use_custom_speed = 1;
	}
	// �r�b�O
	if(misbMType[misbMissionNo] == 4) {
		IsBig[0] = 1;
		BigMove[0] = misbMParam[misbMissionNo * 20 + 0];
	}
	// �T�C�N��
	if(misbMType[misbMissionNo] == 9) {
		for(i = 0; i < 4; i++) misbCycle[i] = 0;
		misbNormMax = 4;
	}
	// �C���C�T�[
	if(misbMType[misbMissionNo] == 10) {
		for(i = 0; i < 4; i++) misbEraserLinePos[i] = 0;
		misbEraserPatternNo = 0;
		misbSetRandomEraserLines();
	}
	// �^�[�Q�b�g
	if(misbMType[misbMissionNo] == 11) {
		misbTargetPatternNo = 0;
		for(i = 0; i < 10000; i++) misbTargetStageFlag[i] = 0;
		misbTargetStartNewStage();
	}
	// �񃉃��_���C���C�T�[
	if(misbMType[misbMissionNo] == 12) {
		for(i = 0; i < 4; i++) misbEraserLinePos[i] = 0;
		misbEraserPatternNo = 0;
		misbSetNormalEraserLines();
	}
	
	// �f�t�H���g�̑��x��ݒ�
	if(!use_custom_speed) {
		if(misbMLevel[misbMissionNo] < 15) {
			sp[0] = misbNormalLevelTable[misbMLevel[misbMissionNo]];
			speedtype[0] = 0;
			wait1[0] = misbNormalWait1;
			wait2[0] = misbNormalWait2;
			wait3[0] = misbNormalWait3;
			waitt[0] = misbNormalWaitt;
		} else {
			sp[0] = 1200;
			speedtype[0] = 0;
			wait1[0] = misbAnotherWait1Table[misbMLevel[misbMissionNo] - 15];
			wait2[0] = misbAnotherWait2Table[misbMLevel[misbMissionNo] - 15];
			wait3[0] = misbAnotherWait3Table[misbMLevel[misbMissionNo] - 15];
			waitt[0] = misbAnotherWaittTable[misbMLevel[misbMissionNo] - 15];
		}
	}
	
	// �w�ߏ����X�V
	misbViewMissionText();
}

// �C���C�T�[�̐��̈ʒu��ݒ�
void misbSetRandomEraserLines() {
	int i, temp;
	int min, max;	// �o���͈�
	int lines;	// �o����
	int lineflag[22];	// ���C���̏d���h�~�p
	
	misbEraserNowLines = 0;
	for(i = 0; i < 22; i++) lineflag[i] = 0;
	
	// �o���͈͂����߂�
	min = misbMParam[misbMissionNo * 20 + 0];
	max = misbMParam[misbMissionNo * 20 + 1];
	
	if(min > max) {
		min = i;
		min = max;
		i = max;
	}
	
	// �����o���������߂�
	temp = misbEraserPatternNo;
	if(temp > 10) temp = 10;
	lines = misbMParam[misbMissionNo * 20 + 2 + temp];
	if(lines < 1) lines = 1;
	if(lines > 4) lines = 4;
	
	// �o������
	for(i = 0; i < lines; i++) {
		// �]���ȃ��C�����o���Ȃ�
		if(i >= misbNormMax - misbNormCurrent) break;
		
		// �o�����C����+1
		misbEraserNowLines++;
		
		// �ʒu�����߂�
		if(min == max) {
			// �ʒu�Œ�
			temp = min;
		} else if((i >= misbNormMax - misbNormCurrent - 1) && (misbNormMax > 1) && (!lineflag[min + 1])) {
			// �Ō��1�{
			temp = min + 1;
		} else {
			// �����_��
			do {
				temp = GiziRand(0, 22);
			} while( (temp < min) || (temp > max) || (lineflag[temp] == 1) );
		}
		if(temp < 0) temp = 0;
		if(temp > 21) temp = 21;
		
		lineflag[temp] = 1;
		misbEraserLinePos[i] = temp;
		misbEraserLineClear[i] = 0;
	}
}

// �񃉃��_���C���C�T�[�̐��̈ʒu��ݒ�
void misbSetNormalEraserLines() {
	int i, lines, lineflag[22], pos, pat;
	
	misbEraserNowLines = 0;
	for(i = 0; i < 22; i++) lineflag[i] = 0;
	
	// �p�^�[���ԍ�
	pat = misbEraserPatternNo;
	if(pat < 0) pat = 0;
	if(pat > 3) pat = 3;
	
	// �ő�o���������߂�
	lines = misbMParam[misbMissionNo * 20 + pat * 5 + 0];
	if(lines < 1) lines = 1;
	if(lines > 4) lines = 4;
	
	// �o������
	for(i = 0; i < lines; i++) {
		// �]���ȃ��C�����o���Ȃ�
		if(i >= misbNormMax - misbNormCurrent) break;
		
		// �ʒu�����߂�
		pos = misbMParam[misbMissionNo * 20 + pat * 5 + 1 + i];
		if(pos < 0) pos = 0;
		if(pos > 21) pos = 21;
		
		// �d���o�����ĂȂ��Ȃ�
		if(!lineflag[pos]) {
			// �o��
			misbEraserNowLines++;
			misbEraserLinePos[i] = pos;
			misbEraserLineClear[i] = 0;
			lineflag[pos] = 1;
		}
	}
}

//������������������������������������������������������������������������������
//   �C�x���gNo.34 - �C���C�T�[�̐���\��
//������������������������������������������������������������������������������
void misbViewEraserLines(int player) {
	int i;
	
	if(!onRecord[player]) return;
	
	if((misbMType[misbMissionNo] == 10) || (misbMType[misbMissionNo] == 12)) {
		for(i = 0; i < misbEraserNowLines; i++) {
			ExBltRect(sg_spr, foffset[player] + 1, fyoffset[player] + (misbEraserLinePos[i] + 3) * 8, 89, 165 + misbEraserLineClear[i] * 8, 95, 8);
		}
	}
}

//������������������������������������������������������������������������������
//   �^�[�Q�b�g�̃X�e�[�W��ǂݍ���
//������������������������������������������������������������������������������

// �o��������X�e�[�W�I�����ǂݍ��ݏ���
void misbTargetStartNewStage() {
	int i, temp, type, min, max, stg, rcnt;
	
	// ���̃p�^�[����
	temp = misbMParam[misbMissionNo * 20 + 5 + misbTargetPatternNo * 4];
	
	if((misbTargetPatternNo < 3) && (temp != 0) && (misbNormCurrent >= temp)) {
		misbTargetPatternNo++;
		for(i = 0; i < 10000; i++) misbTargetStageFlag[i] = 0;
	}
	
	// �X�e�[�W�̏o���͈͂����߂�
	type = misbMParam[misbMissionNo * 20 + 2 + misbTargetPatternNo * 4];
	min = misbMParam[misbMissionNo * 20 + 3 + misbTargetPatternNo * 4];
	max = misbMParam[misbMissionNo * 20 + 4 + misbTargetPatternNo * 4];
	
	// �o��������X�e�[�W�����߂�
	if(min == max) {
		// �X�e�[�W��1�����̏ꍇ
		stg = min;
	} else {
		// �����_��
		rcnt = 0;
		do {
			stg = GiziRand(0, max + 1);
			
			rcnt++;
			if(rcnt > 100000) {
				if(!english) debugLogMode("�X�e�[�W���菈���Ŗ������[�v���������܂����B");
				else debugLogMode("An infinite loop was generated by the stage decision processing.");
				break;
			}
		} while((stg < min) || (misbTargetStageFlag[stg] != 0));
	}
	
	// �o���ς݃t���OON
	misbTargetStageFlag[stg] = 1;
	
	// �X�e�[�W�ǂݍ���
	misbTargetLoadStage(0, stg, type);
	
	// �S�Ẵu���b�N���v���`�i�ɂ���
	if(misbMParam[misbMissionNo * 20 + 0] == 9999) {
		misbTargetTransformAllBlockToPlatinumBlock();
	}
	// �v���`�i�u���b�N�̔z�u�������_���ɂ���
	else if(misbMParam[misbMissionNo * 20 + 0] > 0) {
		misbTargetRandmizePlatinumBlock(misbMParam[misbMissionNo * 20 + 0], misbMParam[misbMissionNo * 20 + 1]);
	}
}

// �X�e�[�W�ǂݍ���
int misbTargetLoadStage(int player, int number, int type) {
	int i, size, offset;
	
	// �ǂݍ��ݎ��s���Ă����v�Ȃ悤�Ƀ_�~�[�Ńf�t�H���g�l��ݒ�
	resetField(player);
	
	// �ǂݍ��݊J�n
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	if(type == 0) {
		sprintf(string[0], "stage/tomoyo_normal/stage%02d.sav", number);
		size = 200 * 4;
	} else if(type == 1) {
		sprintf(string[0], "stage/flash/flash%02d.sav", number);
		size = 60 * 4;
	} else {
		sprintf(string[0], "stage/target/stage%02d.sav", number);
		size = 60 * 4;
	}
	LoadFile(string[0], &saveBuf, size);
	
	// �w�b�_�����������Ȃ�I��
	if(type == 0) {
		if(saveBuf[0] != 0x4F4D4F54) return 0;
		if(saveBuf[1] != 0x4F4D4F59) return 0;
		if(saveBuf[2] != 0x54534544) return 0;
		if(saveBuf[3] != 0x31454741) return 0;
	} else {
		if(saveBuf[0] != 1) return 0;
	}
	
	// �n�`�f�[�^
	if(type == 0) offset = 4;
	else offset = 1;
	
	for(i = 0; i < 55; i++) {
		fld[(i * 4) + 0 + player * 220] = (saveBuf[offset + i] & 0x000000FF);
		fld[(i * 4) + 1 + player * 220] = (saveBuf[offset + i] & 0x0000FF00) >> 8;
		fld[(i * 4) + 2 + player * 220] = (saveBuf[offset + i] & 0x00FF0000) >> 16;
		fld[(i * 4) + 3 + player * 220] = (saveBuf[offset + i] & 0xFF000000) >> 24;
	}
	disableShadowTimer(player);	// �u���b�N��������悤�ɂ���
	
	return 1;
}

// �v���`�i�u���b�N�̔z�u�������_���ɂ���
void misbTargetRandmizePlatinumBlock(int randmax, int opt) {
	int i, j, k, pblk, top;
	int line[22];
	int rcnt;
	pblk = 0;
	rcnt = 0;
	top = checkFieldTop(0);
	
	if(opt) {
		pblk = opt;
		i = 22 - top;	// �t���[�Y�΍�i���ʂ��ۂ��j
		if(pblk > i) pblk = i;
		if(pblk <= 0) return;
	}
	
	// �v���`�i�u���b�N�𕁒ʂ̃u���b�N�ɂ��違�v���`�i�u���b�N�̐��𐔂���
	for(i = 0; i < 22; i++) {
		line[i] = 0;
		
		for(k = 0; k < 10; k++) {
			if(fld[k + i * 10] >= 11) {
				if(!opt) pblk++;
				fld[k + i * 10] = fld[k + i * 10] - 9;
			}
		}
	}
	
	// �v���`�i�u���b�N�������_���ɔz�u
	j = 0;
	while(j < pblk) {
		for(i = 0; i < 22; i++) {
			for(k = 0; k < 10; k++) {
				if((fld[k + i * 10] >= 2) && (fld[k + i * 10] <= 8) && (!line[i])) {
					if(GiziRand(0, randmax) == 0) {
						fld[k + i * 10] = fld[k + i * 10] + 9;
						if(opt) line[i] = 1;
						j++;
						if(j >= pblk) return;
					}
				}
			}
		}
		
		// �S���̃��C���Ƀv���`�i�u���b�N���z�u���ꂽ��I��
		if((misbVersion >= 1) && (opt)) {
			for(i = top; i < 22; i++) {
				if(line[i]) return;
			}
		}
		
		// �������[�v�΍�
		rcnt++;
		if(rcnt > 100000) {
			if(!english) debugLogMode("�v���`�i�u���b�N�����_���z�u�����Ŗ������[�v���������܂����B");
			else debugLogMode("An infinite loop was generated by the orb block random arrangement processing.");
			break;
		}
	}
}

// �S�Ẵu���b�N���v���`�i�u���b�N�ɂ���
void misbTargetTransformAllBlockToPlatinumBlock() {
	int i;
	
	for(i = 0; i < 220; i++) {
		if(fld[i] != 0) fld[i] = 11 + Rand(7);
	}
}

//������������������������������������������������������������������������������
//   �C�x���gNo.10 - ARE���̏���
//������������������������������������������������������������������������������
void misbOnARE(int player, int *param) {
	// �N���A���̏���
	if(misbClearFlag) {
		param[0] = 1;	// �ʏ��ARE�������X�L�b�v
		
		statc[player * 10]--;
		
		if(statc[player * 10] < 0) {
			// �ʏ�G���f�B���O
			if((misbMEndFlag[misbMissionNo] == 1) || (misbMissionNo >= 39)) {
				ending[player] = 1;
				onRecord[player] = 0;
				misbIsAllClear = 2;
			}
			// �u�Ō�̃��C�����_�u���ŏ����I�v�Ɏ��s�����؂薳�����������Ă��Ȃ�
			else if((misbMEndFlag[misbMissionNo] == 2) && (misbLastLine != 2) && (!misbIgnoreTorikan)) {
				ending[player] = 4;
				onRecord[player] = 0;
				misbIsAllClear = 1;
			}
			// ����ȊO
			else {
				// ���؂薳�����g�p�^�l��
				if(misbMEndFlag[misbMissionNo] == 2)
					misbIgnoreTorikan = 0;
				else if((misbMEndFlag[misbMissionNo] == 3) && (misbLastLine == 2))
					misbIgnoreTorikan = 1;
				
				if((misbMErase[misbMissionNo] >= 1) && (misbMErase[misbMissionNo] <= 22)) {
					// ���C�����������P
					stat[0] = 2;
					resetStatc(0);
					misbScreen = 0;
				} else if((misbMErase[misbMissionNo] >= 23) && (misbMErase[misbMissionNo] <= 44)) {
					// ���C�����������Q
					stat[0] = 2;
					resetStatc(0);
					misbScreen = 1;
				} else {
					// ���̖���
					misbMissionNo++;
					stat[0] = 3;
					resetStatc(0);
				}
			}
		}
	}
	// �^�[�Q�b�g�̃X�e�[�W�N���A
	else if((misbMType[misbMissionNo] == 11) && (!checkHowManyPBlocks(0))) {
		param[0] = 1;	// �ʏ��ARE�������X�L�b�v
		
		statc[player * 10]--;
		
		if(statc[player * 10] < 0) {
			stat[0] = 3;
			resetStatc(0);
		}
	}
}

//������������������������������������������������������������������������������
//   �C�x���gNo.68 - ���C�����������P
//������������������������������������������������������������������������������
void misbStatDelLineNormal(int player) {
	int i, j, cnt;
	
	// �u���b�N����
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = checkFieldTop(player);
		cnt = 0;
		
		for(i = statc[player * 10 + 1]; i < 22; i++) {
			for(j = 0; j < 10; j++) {
				setFieldBlock(player, j, i, 0);
			}
			
			cnt++;
			if(cnt >= misbMErase[misbMissionNo]) break;
		}
	}
	
	// ����\��
	if(statc[player * 10] <= 15) {
		cnt = 0;
		
		for(i = statc[player * 10 + 1]; i < 22; i++) {
			ExBltRect(sg_spr, foffset[player] + 8, fyoffset[player] + (i + 3) * 8, 8, 165 + statc[player * 10] * 8, 80, 8);
			
			cnt++;
			if(cnt >= misbMErase[misbMissionNo]) break;
		}
	}
	
	// �I���^�p��
	if(statc[player * 10] >= 15 + wait1[player]) {
		misbMissionNo++;
		stat[player] = 3;
		resetStatc(player);
	} else {
		statc[player * 10]++;
	}
}

//������������������������������������������������������������������������������
//   �C�x���gNo.68 - ���C�����������Q
//������������������������������������������������������������������������������
void misbStatDelLineExtra(int player) {
	int i, j, cnt;
	
	// ������
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = checkFieldTop(player) * 6;
		statc[player * 10 + 2] = 0;
	}
	
	// �u���b�N������
	if((statc[player * 10 + 1] % 6 == 0) && (statc[player * 10] < 129)) {
		j = statc[player * 10 + 1] / 6;
		
		if((j >= 0) && (j < fldsizey)) {
			for(i = 0; i < fldsizex; i++) {
				if(getFieldBlock(player, i, j)) {
					if(getFieldBlockO(player, i, j) == 0) {
						objectCreate(player, 1, foffset[player] + 8 + (i * 8), fyoffset[player] + (j + 3) * 8, (i - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + 1 * 250, getFieldBlock(player, i, j) - 1, 100);
					}
					setFieldBlock(player, i, j, 0);
					setFieldBlockT(player, i, j, 0);
					setFieldBlockO(player, i, j, 0);
					setFieldBlockL(player, i, j, 0);
					setFieldBlockI(player, i, j, 0);
				}
			}
			
			statc[player * 10 + 2]++;
			if(statc[player * 10 + 2] >= misbMErase[misbMissionNo] - 23) {
				if(statc[player * 10] < 129) statc[player * 10] = 129;
			}
		} else {
			if(statc[player * 10] < 129) statc[player * 10] = 129;
		}
	}
	
	// �I���^�p��
	if(statc[player * 10] >= 129 + wait1[player]) {
		misbMissionNo++;
		stat[player] = 3;
		resetStatc(player);
	} else {
		statc[player * 10]++;
		statc[player * 10 + 1]++;
	}
}

//������������������������������������������������������������������������������
//   �C�x���gNo.15 - �X�R�A�\��
//������������������������������������������������������������������������������
void misbViewScore(int player) {
	int i, temp, color, color2;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// �g
	if(!misbHideInfo) {
		// �w�ߏ��
		ExBltFastRect(sg_spr, 0, 112, 88, 229, 112, 112);
		
		// �~�b�V�����ꗗ
		temp = 0;
		while(misbMissionNo - temp > 4) temp = temp + 5;
		
		for(i = temp; i < temp + 5; i++) {
			// �N���A�ς�
			if((misbMissionNo > i) || (ending[player])) {
				ExBltFastRect(sg_spr, 0, 32 + (i - temp) * 16, 88, 213, 96, 16);
				ExBltRect(sg_spr, 98, 34 + (i - temp) * 16, 12, 144, 12, 12);
			}
			// �v���C��
			else if(misbMissionNo == i) {
				ExBltFastRect(sg_spr, 0, 32 + (i - temp) * 16, 88, 197, 96, 16);
				ExBltRect(sg_spr, 98, 34 + (i - temp) * 16, 0, 144, 12, 12);
			}
			// �܂����v���C
			else {
				ExBltFastRect(sg_spr, 0, 32 + (i - temp) * 16, 88, 181, 96, 16);
				ExBltRect(sg_spr, 98, 34 + (i - temp) * 16, 0, 144, 12, 12);
			}
			
			// �I���t���O������ꍇ�͂����Ń��[�v�𔲂���
			if((misbMEndFlag[i] == 1) || (misbMEndFlag[i] == 2)) break;
		}
		
		// �R�[�X��
		printSMALLFont(2, 8, misbCourseName, 4);
	}
	
	// �~�b�V�����ԍ�
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "MISSION");
	sprintf(string[0], "%d", misbMissionNo + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// �g�[�^���^�C��
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "TOTAL TIME");
	getTime(gameTimer[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// �m���}�i���q�j
	ExBltRect(sg_smallfont, foffset[player] + 107, fyoffset[player] + 161, 0, 14, 22, 7);
	sprintf(string[0], "%4d", misbNormCurrent);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 169, string[0], color);
	
	// �m���}�i�����j
	ExBltRect(sg_spr, foffset[player] + 105, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 106, fyoffset[player] + 181, 22, 143, 22, 1);
	
	// �m���}�i����j
	sprintf(string[0], "%4d", misbNormMax);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 185, string[0], color);
	
	// �c�莞��
	if(misbMTimeLimit[misbMissionNo]) {
		if((misbTimer <= 60 * 10) && (timeOn[player])) color2 = 2;
		else color2 = color;
		getTime(misbTimer);
		printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
	} else {
		ExBltFastRect(sg_gametext, foffset[player] - 1, fyoffset[player] + 216, 1, 229 + english * 18, 98, 16);
	}
}

//������������������������������������������������������������������������������
//   �w�ߏ��\��
//������������������������������������������������������������������������������
void misbViewMissionText() {
	int i, temp, cnt;
	
	for(i = 0; i < 10; i++) TextLayerOff(i);
	
	if(misbHideInfo) return;
	
	// �薼
	ExTextSize(0, 10);
	TextColor(0, 0, 0, 0);
	TextBackColorDisable(0);
	
	if(misbMType[misbMissionNo] <= misbStringMax) {
		if(!english) StrCpy(string[0], misbStringMissionNameJ[misbMType[misbMissionNo]]);
		else StrCpy(string[0], misbStringMissionNameE[misbMType[misbMissionNo]]);
	} else {
		StrCpy(string[0], "-----");
	}
	
	// ���x��
	if(misbMLevel[misbMissionNo] >= 15)
		sprintf(string[1], " LV%02d+", misbMLevel[misbMissionNo] - 14);
	else
		sprintf(string[1], " LV%02d", misbMLevel[misbMissionNo] + 1);
	
	StrCat(string[0], string[1]);
	
	TextOut(0, string[0]);
	ExTextLayerOn(0, 5, 120);
	
	// ��������
	ExTextSize(1, 10);
	TextColor(1, 0, 0, 0);
	TextBackColorDisable(1);
	
	if(!english) StrCpy(string[1], "�������� ");
	else StrCpy(string[1], "Time ");
	
	if(misbMTimeLimit[misbMissionNo]) {
		getTime(misbMTimeLimit[misbMissionNo]);
	} else {
		if(!english) StrCpy(string[0], "������");
		else StrCpy(string[0], "No Limit");
	}
	StrCat(string[1], string[0]);
	
	TextOut(1, string[1]);
	ExTextLayerOn(1, 5, 132);
	
	// �w�ߕ�
	ExTextSize(2, 10);
	TextColor(2, 0, 0, 0);
	TextBackColorDisable(2);
	
	if(misbMType[misbMissionNo] <= misbStringMax) {
		if(!english) sprintf(string[0], misbStringMissionInfoJ[misbMType[misbMissionNo]], misbNormMax);
		else sprintf(string[0], misbStringMissionInfoE[misbMType[misbMissionNo]], misbNormMax);
	} else {
		StrCpy(string[0], "-----");
	}
	
	if(!misbIgnoreTorikan) {
		if((misbMEndFlag[misbMissionNo] == 2) || (misbMEndFlag[misbMissionNo] == 3)) {
			if(!english) StrCat(string[0], "\n�Ō�̃��C����\n�_�u���ŏ����I");
			else StrCat(string[0], "\nLast erase 2 lines!");
		}
	}
	
	TextOut(2, string[0]);
	ExTextLayerOn(2, 5, 152);
	
	// �~�b�V�����ꗗ
	temp = 0;
	cnt = 0;
	
	while(misbMissionNo - temp > 4) temp = temp + 5;
	
	for(i = temp; i < temp + 5; i++) {
		if(misbMType[i] <= misbStringMax) {
			if(!english) StrCpy(string[0], misbStringMissionNameJ[misbMType[i]]);
			else StrCpy(string[0], misbStringMissionNameE[misbMType[i]]);
		} else {
			StrCpy(string[0], "-----");
		}
		
		ExTextSize(3 + cnt, 10);
		TextColor(3 + cnt, 0, 0, 0);
		TextBackColorDisable(3 + cnt);
		TextOut(3 + cnt, string[0]);
		ExTextLayerOn(3 + cnt, 1, 33 + cnt * 16);
		
		cnt++;
		
		// �I���t���O������ꍇ�͂����Ń��[�v�𔲂���
		if((misbMEndFlag[i] == 1) || (misbMEndFlag[i] == 2)) break;
	}
}

//������������������������������������������������������������������������������
//   �C�x���gNo.21 - ���ʕ\��
//������������������������������������������������������������������������������
void misbResult(int player) {
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "MISSION");
	sprintf(string[0], "%13d", misbMissionNo + 1);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "TIME");
	getTime(gameTimer[player]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[1], 0);
}

//������������������������������������������������������������������������������
//   �C�x���gNo.28 - ���Ԃ�i�߂�
//������������������������������������������������������������������������������
void misbIncrementTime(int player) {
	if((timeOn[player]) && (misbMTimeLimit[misbMissionNo] != 0)) {
		// �������Ԍ���
		misbTimer--;
		
		// ���Ԑ؂�
		if(misbTimer <= 0) {
			PlaySE(se_timeover);
			misbTimer = 0;
			
			timeOn[player] = 0;
			onRecord[player] = 0;
			
			stat[player] = 7;
			resetStatc(player);
		}
		// �c��10�b
		else if(misbTimer == 10 * 60) {
			PlaySE(se_hurryup);
		}
	}
}

//������������������������������������������������������������������������������
//   �C�x���gNo.24 - �G���f�B���O�˓�
//������������������������������������������������������������������������������
void misbEndingStart(int player) {
	int i;
	ending[player] = 3;
	for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
}

//������������������������������������������������������������������������������
//   �C�x���gNo.25 - EXCELLENT���
//������������������������������������������������������������������������������
void misbExcellent(int player, int *param) {
	onRecord[player] = 0;
	
	if(misbIsAllClear == 1) {
		// ���؂�
		param[0] = 4;
		statc[player * 10 + 1]++;
		
		if(statc[player * 10] < 220) {
			// �ԉ�
			if((statc[player * 10 + 1] % 40 == 0) && (statc[player * 10 + 2] < 4)) {
				objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
				statc[player * 10 + 2]++;
			}
			
			// �{�^���ŃX�L�b�v
			if(getPushState(player, 4)) {
				statc[player * 10] = 219;
			}
		} else {
			if(statc[player * 10] == 220) objectClearPl(player);	// �ԉ΂�����
			
			printFont(foffset[player] + 8, fyoffset[player] + 112, "BUT...", 0);
			printFont(foffset[player] + 8, fyoffset[player] + 120, "LAST ERASE", 0);
			printFont(foffset[player] + 8, fyoffset[player] + 128, "2 LINES", 0);
			printFont(foffset[player] + 8, fyoffset[player] + 136, "NEXT TIME", 0);
			
			// �{�^���ŃX�L�b�v
			if(getPushState(player, 4)) {
				statc[player * 10] = 600;
			}
		}
	} else {
		// ���S�N���A
		if(misbExcellentType == 0) param[0] = 3;	// CLEAR!!
		if(misbExcellentType == 1) param[0] = 0;	// EXCELLENT
		if(misbExcellentType == 2) param[0] = 1;	// GM
		if(misbExcellentType == 3) param[0] = 2;	// GOD
		
		// �ԉ�
		if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			statc[player * 10 + 1]++;
		}
	}
}

//������������������������������������������������������������������������������
//   �C�x���gNo.38 - BGM�Đ�
//������������������������������������������������������������������������������
void misbPlayBGM() {
	bgmlv = misbMBgm[misbMissionNo];
	
	if(!IsPlayWave(bgm_plane[bgmlv])) {
		StopAllBGM();
		fadelv = 0;
		PlayBGM();
	}
}

//������������������������������������������������������������������������������
//   �C�x���gNo.41 - BGM�ǂݍ���
//������������������������������������������������������������������������������
void misbLoadBGM() {
	int i, cnt, cnt2;
	int loadflag[30];
	
	if(bgmtype == 0) return;
	
	for(i = 0; i < 30; i++) loadflag[i] = 0;
	cnt = 0;
	
	// �ǂݍ��ނׂ�BGM�����߂�
	for(i = 0; i < 40; i++) {
		if(!loadflag[misbMBgm[i]]) {
			loadflag[misbMBgm[i]] = 1;
			cnt++;
		}
		
		if(misbMEndFlag[i] == 1) break;
	}
	
	// �ǂݍ���
	cnt2 = 0;
	
	for(i = 0; i < 30; i++) {
		if(loadflag[i]) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/%d)", cnt2 + 1, cnt);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(i);
			cnt2++;
		}
	}
}

//������������������������������������������������������������������������������
//   �C�x���gNo.39 - ���v���C�ۑ�
//������������������������������������������������������������������������������
void misbSaveReplay(int player) {
	saveBuf[900] = misbLastCourse;
	saveBuf[901] = misbStartMissionNo;
	saveBuf[902] = misbGhost;
	saveBuf[903] = misbMissionNo;
}

//������������������������������������������������������������������������������
//   �C�x���gNo.40 - ���v���C�ǂݍ���
//������������������������������������������������������������������������������
void misbLoadReplay(int player) {
	// �ݒ��ǂݍ���
	misbLastCourse = saveBuf[900];
	misbStartMissionNo = saveBuf[901];
	misbGhost = saveBuf[902];
	
	// �ݒ�𔽉f������
	misbApplyGameSetting(player);
	
	// �R�[�X�ǂݍ���
	misbLoadCourseData(misbLastCourse);
}

//������������������������������������������������������������������������������
//   �C�x���gNo.55 - ���v���C�ڍ�
//������������������������������������������������������������������������������
void misbReplayDetail() {
	printFontGrid(1, 4, "COURSE", 0);
	sprintf(string[0], "%d", saveBuf[900] + 1);
	printFontGrid(22, 4, string[0], 0);
	
	printFontGrid(1, 5, "START MISSION NO.", 0);
	sprintf(string[0], "%d", saveBuf[901] + 1);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "GHOST BLOCK", 0);
	if(!saveBuf[902]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 8, "LAST MISSION NO.", 0);
	sprintf(string[0], "%d", saveBuf[903] + 1);
	printFontGrid(22, 8, string[0], 0);
}

//������������������������������������������������������������������������������
//   �C�x���gNo.17 - �ݒ���
//������������������������������������������������������������������������������
void misbSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	misbLoadConfig();	// �ݒ��ǂݍ���
	misbLoadCourseDataNameOnly(misbLastCourse);	// �R�[�X���ǂݍ���
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "MISSION-BASIC OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT D:EDIT", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "COURSE",            7 * (cursor == 0));
		printFontGrid(2, 4, "START MISSION NO.", 7 * (cursor == 1));
		printFontGrid(2, 5, "GHOST BLOCK",       7 * (cursor == 2));
		
		// �ݒ�l�\��
		sprintf(string[0], "%d:%s", misbLastCourse + 1, misbCourseName);
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		sprintf(string[0], "%d", misbStartMissionNo + 1);
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!misbGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		// �J�[�\���ړ�
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 2;
			if(cursor > 2) cursor = 0;
		}
		
		// �l��ύX
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) {
				misbLastCourse = misbLastCourse + move;
				if(misbLastCourse < 0) misbLastCourse = 98;
				if(misbLastCourse > 98) misbLastCourse = 0;
				misbLoadCourseDataNameOnly(misbLastCourse);
			}
			if(cursor == 1) {
				misbStartMissionNo = misbStartMissionNo + move;
				if(misbStartMissionNo < 0) misbStartMissionNo = 39;
				if(misbStartMissionNo > 39) misbStartMissionNo = 0;
			}
			if(cursor == 2) misbGhost = !misbGhost;
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
			
			// �ݒ��ۑ�
			misbSaveConfig();
			
			// �R�[�X�ǂݍ���
			misbLoadCourseData(misbLastCourse);
			
			return;
		}
		
		// �G�f�B�b�g
		if(getPushState(player, 7)) {
			misbLoadCourseData(misbLastCourse);
			misbCourseDataEditor(player);
		}
	}
}

// �ݒ��ۑ�
void misbSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �ݒ���e
	saveBuf[1] = misbLastCourse;
	saveBuf[2] = misbStartMissionNo;
	saveBuf[3] = misbGhost;
	
	SaveFile("config/MISSION_BASIC_CONFIG.SAV", &saveBuf, 50 * 4);
}

// �ݒ��ǂݍ���
int misbLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/MISSION_BASIC_CONFIG.SAV", &saveBuf, 50 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 1) return 0;
	
	// �ݒ���e
	misbLastCourse = saveBuf[1];
	misbStartMissionNo = saveBuf[2];
	misbGhost = saveBuf[3];
	
	return 1;
}

//������������������������������������������������������������������������������
//   �R�[�X�f�[�^�ۑ�
//������������������������������������������������������������������������������
void misbSaveCourseData(int number) {
	int i, j, temp[4];
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 1;
	
	// �R�[�X�S�ʂ̐ݒ�
	saveBuf[1] = misbExcellentType;
	saveBuf[2] = misbHideInfo;
	
	// �R�[�X����ۑ�
	if(StrLen(misbCourseName) > 0) {
		StrCpy(&temp, misbCourseName);
		saveBuf[4] = temp[0];
		saveBuf[5] = temp[1];
		saveBuf[6] = temp[2];
		saveBuf[7] = temp[3];
	}
	
	// ���f�[�^
	for(i = 0; i < 40; i++) {
		saveBuf[8 + (i * 30) + 0] = misbMType[i];
		saveBuf[8 + (i * 30) + 1] = misbMNorm[i];
		saveBuf[8 + (i * 30) + 2] = misbMLevel[i];
		saveBuf[8 + (i * 30) + 3] = misbMTimeLimit[i];
		saveBuf[8 + (i * 30) + 4] = misbMBgm[i];
		saveBuf[8 + (i * 30) + 5] = misbMBackground[i];
		saveBuf[8 + (i * 30) + 6] = misbMErase[i];
		saveBuf[8 + (i * 30) + 7] = misbMEndFlag[i];
		
		for(j = 0; j < 20; j++) saveBuf[8 + (i * 30) + 10 + j] = misbMParam[i * 20 + j];
	}
	
	sprintf(string[0], "stage/mission/mission%02d.sav", number);
	SaveFile(string[0], &saveBuf, 1238 * 4);
}

//������������������������������������������������������������������������������
//   �R�[�X�f�[�^�ǂݍ���
//������������������������������������������������������������������������������
int misbLoadCourseData(int number) {
	int i, j, temp[4];
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "stage/mission/mission%02d.sav", number);
	LoadFile(string[0], &saveBuf, 1238 * 4);
	
	// �R�[�X�S�ʂ̐ݒ�
	misbExcellentType = saveBuf[1];
	misbHideInfo = saveBuf[2];
	
	// �R�[�X����ǂݍ���
	if(saveBuf[0] != 1) {
		StrCpy(misbCourseName, "");
	} else {
		temp[0] = saveBuf[4];
		temp[1] = saveBuf[5];
		temp[2] = saveBuf[6];
		temp[3] = saveBuf[7];
		StrCpy(misbCourseName, &temp);
	}
	
	// ���f�[�^
	for(i = 0; i < 40; i++) {
		misbMType[i] = saveBuf[8 + (i * 30) + 0];
		misbMNorm[i] = saveBuf[8 + (i * 30) + 1];
		misbMLevel[i] = saveBuf[8 + (i * 30) + 2];
		misbMTimeLimit[i] = saveBuf[8 + (i * 30) + 3];
		misbMBgm[i] = saveBuf[8 + (i * 30) + 4];
		misbMBackground[i] = saveBuf[8 + (i * 30) + 5];
		misbMErase[i] = saveBuf[8 + (i * 30) + 6];
		misbMEndFlag[i] = saveBuf[8 + (i * 30) + 7];
		
		for(j = 0; j < 20; j++) misbMParam[i * 20 + j] = saveBuf[8 + (i * 30) + 10 + j];
	}
	
	return 1;
}

// ���O�����ǂݍ���
int misbLoadCourseDataNameOnly(int number) {
	int temp[4];
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "stage/mission/mission%02d.sav", number);
	LoadFile(string[0], &saveBuf, 8 * 4);
	
	if(saveBuf[0] != 1) {
		StrCpy(misbCourseName, "");
		return 0;
	}
	
	temp[0] = saveBuf[4];
	temp[1] = saveBuf[5];
	temp[2] = saveBuf[6];
	temp[3] = saveBuf[7];
	StrCpy(misbCourseName, &temp);
	
	return 1;
}

//������������������������������������������������������������������������������
//   �R�[�X�G�f�B�b�g
//������������������������������������������������������������������������������
void misbCourseDataEditor(int player) {
	int i, cursor, move, number, params, temp;
	cursor = 0;
	move = 0;
	number = misbStartMissionNo;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		if(cursor <= 11) {
			printFontGrid(1, 1, "COURSE EDIT (PAGE 1/2)", 4);
			printFontGrid(1, 26, "A:OK B:CANCEL\n<>:1 D+<>:10 E+<>:100 F+<>:1000", 6);
			
			// �J�[�\���\��
			if(cursor <= 8) printFontGrid(1, 3 + cursor, "b", 7);
			else printFontGrid(1, 3 + cursor, "b", 6);
			
			// ���j���[�\��
			printFontGrid(2,  3, "STAGE",               7 * (cursor ==  0));
			printFontGrid(2,  4, "TYPE",                7 * (cursor ==  1));
			printFontGrid(2,  5, "NORM",                7 * (cursor ==  2));
			printFontGrid(2,  6, "LEVEL",               7 * (cursor ==  3));
			printFontGrid(2,  7, "TIME LIMIT",          7 * (cursor ==  4));
			printFontGrid(2,  8, "BGM",                 7 * (cursor ==  5));
			printFontGrid(2,  9, "BACKGROUND",          7 * (cursor ==  6));
			printFontGrid(2, 10, "ERASE",               7 * (cursor ==  7));
			printFontGrid(2, 11, "END",                 7 * (cursor ==  8));
			printFontGrid(2, 12, "ALL CLEAR ANIMATION", 6 * (cursor ==  9));
			printFontGrid(2, 13, "HIDE INFO",           6 * (cursor == 10));
			printFontGrid(2, 14, "[COURSE NAME]",       6 * (cursor == 11));
			
			// �ݒ�l�\��
			sprintf(string[0], "%d", number + 1);
			printFontGrid(22, 3, string[0], 7 * (cursor == 0));
			
			if(misbMType[number] <= misbStringMax) StrCpy(string[0], misbStringMissionNameCourseEdit[misbMType[number]]);
			else StrCpy(string[0], "-----");
			printFontGrid(22, 4, string[0], 7 * (cursor == 1));
			
			sprintf(string[0], "%d", misbMNorm[number]);
			printFontGrid(22, 5, string[0], 7 * (cursor == 2));
			
			if(misbMLevel[number] >= 15) sprintf(string[0], "%d+", misbMLevel[number] - 14);
			else sprintf(string[0], "%d", misbMLevel[number] + 1);
			printFontGrid(22, 6, string[0], 7 * (cursor == 3));
			
			getTime(misbMTimeLimit[number]);
			printFontGrid(22, 7, string[0], 7 * (cursor == 4));
			
			sprintf(string[0], "%d", misbMBgm[number]);
			printFontGrid(22, 8, string[0], 7 * (cursor == 5));
			
			if(!misbMBackground[number]) sprintf(string[0], "AUTO");
			else sprintf(string[0], "BACK%02d.PNG", misbMBackground[number]);
			printFontGrid(22, 9, string[0], 7 * (cursor == 6));
			
			if(misbMErase[number] >= 23) sprintf(string[0], "EX %d", misbMErase[number] - 22);
			else sprintf(string[0], "%d", misbMErase[number]);
			printFontGrid(22, 10, string[0], 7 * (cursor == 7));
			
			if(misbMEndFlag[number] == 0) sprintf(string[0], "OFF");
			else if(misbMEndFlag[number] == 1) sprintf(string[0], "ENDING");
			else if(misbMEndFlag[number] == 2) sprintf(string[0], "EXTRA");
			else sprintf(string[0], "BONUS");
			printFontGrid(22, 11, string[0], 7 * (cursor == 8));
			
			if(misbExcellentType == 0) sprintf(string[0], "CLEAR!!");
			else if(misbExcellentType == 1) sprintf(string[0], "EXCELLENT");
			else if(misbExcellentType == 2) sprintf(string[0], "GM");
			else sprintf(string[0], "GOD");
			printFontGrid(22, 12, string[0], 6 * (cursor == 9));
			
			if(!misbHideInfo) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 13, string[0], 6 * (cursor == 10));
			
			if(StrLen(misbCourseName) > 0) {
				printFontGrid(22, 14, misbCourseName, 6 * (cursor == 11));
			} else {
				printFontGrid(22, 14, "(NONE)", 6 * (cursor == 11));
			}
		} else {
			printFontGrid(1, 1, "COURSE EDIT (PAGE 2/2)", 4);
			printFontGrid(1, 26, "A:OK B:CANCEL\n<>:1 D+<>:10 E+<>:100 F+<>:1000", 6);
			
			// �J�[�\���\��
			printFontGrid(1, 3 + (cursor - 12), "b", 7);
			params = 0;
			
			// ���x�Œ�
			if(misbMType[number] == 3) {
				printFontGrid(2, 3, "SPEED", 7 * (cursor == 12));
				printFontGrid(2, 4, "SPEED TYPE", 7 * (cursor == 13));
				if(!english) {
					printFontGrid(2, 5, "SYUTUGEN", 7 * (cursor == 14));
					printFontGrid(2, 6, "SYOUKYO", 7 * (cursor == 15));
					printFontGrid(2, 7, "SETTYAKU", 7 * (cursor == 16));
					printFontGrid(2, 8, "YOKOTAME", 7 * (cursor == 17));
				} else {
					printFontGrid(2, 5, "ARE", 7 * (cursor == 14));
					printFontGrid(2, 6, "LINE DELAY", 7 * (cursor == 15));
					printFontGrid(2, 7, "LOCK DELAY", 7 * (cursor == 16));
					printFontGrid(2, 8, "DAS", 7 * (cursor == 17));
				}
				printFontGrid(2, 9, "BIG", 7 * (cursor == 18));
				printFontGrid(2, 10, "BIG MOVE", 7 * (cursor == 19));
				params = 8;
			}
			// �r�b�O
			if(misbMType[number] == 4) {
				printFontGrid(2, 3, "BIG MOVE", 7 * (cursor == 12));
				params = 1;
			}
			// �C���C�T�[
			if(misbMType[number] == 10) {
				printFontGrid(2, 3, "MIN (3-21)", 7 * (cursor == 12));
				printFontGrid(2, 4, "MAX (3-21)", 7 * (cursor == 13));
				
				for(i = 0; i < 10; i++) {
					sprintf(string[0], "LINES (PATTERN %d)", i + 1);
					printFontGrid(2, 5 + i, string[0], 7 * (cursor == 14 + i));
				}
				
				params = 12;
			}
			// �^�[�Q�b�g
			if(misbMType[number] == 11) {
				printFontGrid(2, 3, "RANDOM TYPE", 7 * (cursor == 12));
				printFontGrid(2, 4, "RANDOM OPTION", 7 * (cursor == 13));
				
				for(i = 0; i < 4; i++) {
					sprintf(string[0], "STAGE TYPE (PAT-%d)", i + 1);
					printFontGrid(2, 5 + i * 4, string[0], 7 * (cursor == 14 + i * 4));
					sprintf(string[0], "STAGE MIN (PAT-%d)", i + 1);
					printFontGrid(2, 6 + i * 4, string[0], 7 * (cursor == 15 + i * 4));
					sprintf(string[0], "STAGE MAX (PAT-%d)", i + 1);
					printFontGrid(2, 7 + i * 4, string[0], 7 * (cursor == 16 + i * 4));
					
					if(i < 3) printFontGrid(2, 8 + i * 4, "n NORM TO NEXT", 7 * (cursor == 17 + i * 4));
				}
				
				params = 17;
			}
			// �񃉃��_���C���C�T�[
			if(misbMType[number] == 12) {
				for(i = 0; i < 4; i++) {
					sprintf(string[0], "LINES (PATTERN %d)", i + 1);
					printFontGrid(2, 3 + i * 5, string[0], 7 * (cursor == 12 + i * 5));
					sprintf(string[0], "POS-1 (PATTERN %d)", i + 1);
					printFontGrid(2, 4 + i * 5, string[0], 7 * (cursor == 13 + i * 5));
					sprintf(string[0], "POS-2 (PATTERN %d)", i + 1);
					printFontGrid(2, 5 + i * 5, string[0], 7 * (cursor == 14 + i * 5));
					sprintf(string[0], "POS-3 (PATTERN %d)", i + 1);
					printFontGrid(2, 6 + i * 5, string[0], 7 * (cursor == 15 + i * 5));
					sprintf(string[0], "POS-4 (PATTERN %d)", i + 1);
					printFontGrid(2, 7 + i * 5, string[0], 7 * (cursor == 16 + i * 5));
				}
				params = 20;
			}
			
			// NO PARAM
			for(i = params; i < 20; i++) {
				printFontGrid(2, 3 + i, "NO PARAM", 7 * (cursor == 12 + i));
			}
			
			// �ݒ�l�\��
			for(i = 0; i < 20; i++) {
				sprintf(string[0], "%d", misbMParam[number * 20 + i]);
				printFontGrid(22, 3 + i, string[0], 7 * (cursor == 12 + i));
			}
		}
		
		// �J�[�\���ړ�
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 31;
			if(cursor > 31) cursor = 0;
		}
		
		// �l��ύX
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			temp = 1;
			if(getPressState(player, 7)) temp = 10;		// D
			if(getPressState(player, 8)) temp = 100;	// E
			if(getPressState(player, 9)) temp = 1000;	// F
			
			if(cursor == 0) {
				number = number + move * temp;
				if(number < 0) number = 39;
				if(number > 39) number = 0;
			}
			if(cursor == 1) {
				misbMType[number] = misbMType[number] + move * temp;
				if(misbMType[number] < 0) misbMType[number] = misbStringMax;
				if(misbMType[number] > misbStringMax) misbMType[number] = 0;
			}
			if(cursor == 2) {
				misbMNorm[number] = misbMNorm[number] + move * temp;
				if(misbMNorm[number] < 0) misbMNorm[number] = 99;
				if(misbMNorm[number] > 99) misbMNorm[number] = 0;
			}
			if(cursor == 3) {
				misbMLevel[number] = misbMLevel[number] + move * temp;
				if(misbMLevel[number] < 0) misbMLevel[number] = 29;
				if(misbMLevel[number] > 29) misbMLevel[number] = 0;
			}
			if(cursor == 4) {
				misbMTimeLimit[number] = misbMTimeLimit[number] + (move * temp * 60);
				if(misbMTimeLimit[number] < 0) misbMTimeLimit[number] = 72000;
				if(misbMTimeLimit[number] > 72000) misbMTimeLimit[number] = 0;
			}
			if(cursor == 5) {
				misbMBgm[number] = misbMBgm[number] + move * temp;
				if(misbMBgm[number] < 0) misbMBgm[number] = 29;
				if(misbMBgm[number] > 29) misbMBgm[number] = 0;
			}
			if(cursor == 6) {
				misbMBackground[number] = misbMBackground[number] + move * temp;
				if(misbMBackground[number] > 20) misbMBackground[number] = 0;
				if(misbMBackground[number] < 0) misbMBackground[number] = 20;
			}
			if(cursor == 7) {
				misbMErase[number] = misbMErase[number] + move * temp;
				if(misbMErase[number] < 0) misbMErase[number] = 44;
				if(misbMErase[number] > 44) misbMErase[number] = 0;
			}
			if(cursor == 8) {
				misbMEndFlag[number] = misbMEndFlag[number] + move * temp;
				if(misbMEndFlag[number] < 0) misbMEndFlag[number] = 3;
				if(misbMEndFlag[number] > 3) misbMEndFlag[number] = 0;
			}
			if(cursor == 9) {
				misbExcellentType = misbExcellentType + move * temp;
				if(misbExcellentType < 0) misbExcellentType = 3;
				if(misbExcellentType > 3) misbExcellentType = 0;
			}
			if(cursor == 10) misbHideInfo = !misbHideInfo;
			if(cursor >= 12) {
				misbMParam[number * 20 + (cursor - 12)] = misbMParam[number * 20 + (cursor - 12)] + move * temp;
				if(misbMParam[number * 20 + (cursor - 12)] < 0) misbMParam[number * 20 + (cursor - 12)] = 9999;
				if(misbMParam[number * 20 + (cursor - 12)] > 9999) misbMParam[number * 20 + (cursor - 12)] = 0;
			}
		}
		
		// �L�����Z��
		if(getPushState(player, 5)) {
			PlaySE(se_move);
			return;
		}
		
		// ����
		if(getPushState(player, 4)) {
			PlayWave(se_kettei);
			
			if(cursor == 11) {
				misbCourseNameEntry(player);
			} else {
				misbSaveCourseData(misbLastCourse);
				return;
			}
		}
	}
}

//������������������������������������������������������������������������������
//   �R�[�X������
//������������������������������������������������������������������������������
void misbCourseNameEntry(int player) {
	int move, len, currentChar;
	
	// ������
	StrCpy(string[2], misbCourseName);
	currentChar = 54;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ENTER COURSE NAME", 4);
		printFontGrid(1, 26, "A:OK B:DELETE D:CANCEL\n<>:SELECT C+<>:FAST SELECT", 6);
		
		len = StrLen(string[2]);	// ���͍ςݕ�����
		
		// ���ړ�
		padRepeat(player);
		move = getPressState(player, 3) - getPressState(player, 2);
		if(move)
			if((mpc[player] == 1) || (mpc[player] >= 15) || getPressState(player, 6)) {
				if(mpc[player] >= 15) mpc[player] = 12;
				currentChar = currentChar + move;
				PlaySE(se_move);
			}
		
		// �����̃��[�v
		if(currentChar > 54)
			currentChar = (len == 15) * 53;
		if(currentChar < (len == 15) * 53)
			currentChar = 54;
		
		// �I�����Ă��镶���Ɠ��͍ςݕ�����\��
		MidStr(RankString, currentChar + 1, 1, string[3]);
		printFontGrid(1 + len, 3, string[3], 2 * (count % 20 > 10));
		printFontGrid(1, 3, string[2], 0);
		
		sprintf(string[0], "LENGTH:%02d/15", len);
		printFontGrid(1, 5, string[0], 1);
		
		// D�ŃL�����Z��
		if(getPushState(player, 7)) {
			PlaySE(se_move);
			return;
		}
		
		// B�{�^����1�����폜
		if(getPushState(player, 5)) {
			if(len) {
				PlaySE(se_move);
				MidStr(string[2], 1, len - 1, string[2]);
			}
		}
		
		// A�{�^���œ���
		if(getPushState(player, 4)) {
			PlaySE(se_kettei);
			
			if(currentChar == 53) {
				// RB
				if(len) {
					MidStr(string[2], 1, len - 1, string[2]);
				}
			} else if(currentChar == 54) {
				// ED
				PlaySE(se_cheer);
				
				// ���O�̌��ɃX�y�[�X��}���i�]���������X�y�[�X�ɂ���j
				sprintf(string[2], "%s                ", string[2]);
				
				// ������16�����ڈȍ~���폜
				LeftStr(string[2], 15, string[2]);
				
				// �ۑ�
				StrCpy(misbCourseName, string[2]);
				
				// �I���
				return;
			} else {
				// ��������
				StrCat(string[2], string[3]);
			}
		}
	}
}
