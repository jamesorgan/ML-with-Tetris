//NET-LINE
//prefix:netl

int netlModeNo = -1;				// ���[�h�ԍ�
int netlModeVersion = 3;			// Mode Version

int netlLines[2];					// ���C����

int netlRound;						// ���E���h
int netlWin[2];						// ��������

int netlServerNo = 0;				// �T�[�o�[�ԍ�

int netlGhost = 1;					// �S�[�X�g�̐ݒ�
int netlSpeed = 1;					// �������x
int netlSpeedType = 0;				// �X�s�[�h�^�C�v
int netlWait1 = 25;					// ARE
int netlWait2 = 40;					// ���C������
int netlWait3 = 30;					// �Œ莞��
int netlWaitt = 16;					// ������
int netlWait4 = -1;					// �Œ莞�ԁi�ڒ���j
int netlWait5 = -1;					// ARE�i������j
int netlNormLine = 40;				// �K�胉�C����
int netlAreUse = -1;				// ARE Force
int netlFastlrmove = -1;			// INIT LR Force
int netlRepeatDelay = -1;			// Repeat Delay
int netlMaxDAS = -1;				// Disable Max DAS
int netlSpawnType = -1;				// SPAWN Y TYPE Force
int netlHoldEnable = -1;			// Enable Hold

int netlPreset[20 * 10];			// �v���Z�b�g
int netlLastPresetNo = 0;			// �Ō�ɑI�������v���Z�b�g�ԍ�

int netlPlayerType;					// 0�Ȃ�z�X�g���A1�Ȃ�Q�X�g��
int netlGameStart;					// �Q�[�����Ȃ�1
int netlTraining;					// �g���[�j���O���Ȃ�1

int netlCustomStatNo[2];			// stat[player] = 2�̂Ƃ��̏����̔ԍ�

int netlLastBlk[2];					// �O�̃t���[���̃u���b�N�̎��
int netlLastBx[2];					// �O�̃t���[���̃u���b�N��X���W
int netlLastBy[2];					// �O�̃t���[���̃u���b�N��Y���W
int netlLastRt[2];					// �O�̃t���[���̃u���b�N�̌���
int netlLastNDelay[2];				// �O�̃t���[����NEXT�x�����

int netlReceiveRuleNameOK;			// ���[��������M�����t���O
int netlReceiveRuleConfigOK;		// ���[���ݒ����M�����t���O
int netlReceiveNextListOK;			// NEXT�u���b�N����M�����t���O
int netlReceiveModeConfigOK;		// ���[�h�ݒ����M�����t���O

int netlEnemyID;					// �ΐ푊��ID
int netlEnemyNotFound;				// �ΐ푊�肪������Ȃ��Ƃ��A�ēx�ΐ푊�����������܂ł̃t���[����
int netlEnemyDisconnect;			// �ΐ푊�肪�ؒf������1�ɂȂ�
int netlEnemyRulePluginMissing;		// �ΐ푊��̃��[���v���O�C���������瑤�ɖ����Ƃ���1�ɂȂ�
int netlEnemyReady;					// �ΐ푊��̏���������1�ɂȂ�
int netlEnemyBlockVisible;			// �ΐ푊��̃u���b�N���\������Ă��邩�ǂ���

int netlServerVersion;				// �T�[�o�[�o�[�W����
int netlClientCount;				// �ڑ��Ґ�
int netlMaxClient;					// �ő�ڑ��Ґ�
int netlSameModeClientCount[3];		// �������[�h�ƃo�[�W�������g�p���Ă���v���C���[�̐�
int netlCountUpdateFrame;			// ���Ƀv���C���[�����X�V����܂ł̃t���[����

int netlRuleConfigPlayer[26];		// ���[���ݒ�i�����j
int netlRuleConfigEnemy[26];		// ���[���ݒ�i�G�j

str* netlNickname[2];				// �����ƓG�̃j�b�N�l�[��

int netlBufIn[16384];				// ��M�p�o�b�t�@
int netlBufOut[16384];				// ���M�p�o�b�t�@

// �C�x���g����
void netlPluginEvent(int player, int event, int *param) {
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != netlModeNo)) return;
	
	if(event == 0) {
		netlModeNo = addModePlugin("NET-LINE");	// ���[�h��o�^����
		netlNickname[0] = new(64);
		netlNickname[1] = new(64);
		LeftStr(networkNickName, 63, netlNickname[0]);
		StrCpy(netlNickname[1], "");
	} else if(event == 1) {
		netlRecvData();	// �f�[�^��M
	} else if(event == 5) {
		netlReady(player, param);	// Ready
	} else if(event == 6) {
		netlStatMove(player, param);	// �u���b�N�ړ�����
	} else if(event == 10) {
		netlARE(player);	// ARE���̏���
	} else if(event == 11) {
		netlStatEraseBlock(player, param);	// �u���b�N�������̏���
	} else if(event == 12) {
		netlCalcScore(player, param[0]);	// ���C������
	} else if(event == 15) {
		netlViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		netlSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		netlPlayerInitial(player);	// ����������
	} else if(event == 20) {
		netlGameOver(player, param);	// �Q�[���I�[�o�[����
	} else if(event == 21) {
		netlResult(player, param);	// ���ʕ\��
	} else if(event == 22) {
		netlGameOver2(player, param);	// �Q�[���I�[�o�[�\��
	} else if(event == 27) {
		netlIncrementTime(player);	// �e�t���[���̏I���̏���
	} else if(event == 38) {
		if(player == 0) PlayBGM();	// BGM�Đ�
	} else if(event == 68) {
		// stat[player] = 2�̂Ƃ��̏���
		if(netlCustomStatNo[player] == 0) netlStatDisconnect(player);	// �ؒf
		if(netlCustomStatNo[player] == 1) netlStatWin(player);	// ����
		if(netlCustomStatNo[player] == 2) netlStatRetryScreen(player);	// ���g���C
	}
}

// �f�[�^��M
void netlRecvData() {
	int size, result, id_from, command, temp;
	
	// �ڑ����Ă��Ȃ��Ȃ�߂�
	if(!tcpIsConnect()) return;
	
	// �V�����f�[�^�������Ȃ�߂�
	if(!tcpIsReadReady()) return;
	
	// �ŏ���4�o�C�g�������ׂ�i�L���[���珜���͂��Ȃ��j
	result = tcpRecvPeek(&netlBufIn, 4);
	if(result < 1) return;
	
	// �ǂݍ��ރT�C�Y�����߂�
	size = netlBufIn[0];
	if(size < 1) return;
	
	// �f�[�^���S�ė��Ă��邩�ǂ����m�F
	if(tcpReceiveLength() < size) return;
	
	// �f�[�^��S�ēǂݍ���
	result = tcpRecv(&netlBufIn, size);
	if(result < 1) return;
	
	// �ǂݍ��񂾃f�[�^�ɉ����ď���������
	id_from = netlBufIn[1];
	command = netlBufIn[2];
	
	// �T�[�o�[����̃��b�Z�[�W�̏ꍇ
	if(id_from == 0) {
		// ���擾
		if(command == 0) {
			netlServerVersion = netlBufIn[3];
			netlClientCount = netlBufIn[4];
			if(netlServerVersion >= 2) netlMaxClient = netlBufIn[7];
		}
		// �N�����ڑ�
		else if(command == 1) {
			netlClientCount = netlBufIn[4];
			netlCountUpdateFrame = 0;
		}
		// �N�����ؒf
		else if(command == 2) {
			netlClientCount = netlBufIn[4];
			netlCountUpdateFrame = 0;
			
			// ���肪�ؒf����
			if(netlBufIn[3] == netlEnemyID) {
				netlEnemyID = 0;
				netlEnemyDisconnect = 1;
			}
		}
		// ���肪��������
		else if(command == 3) {
			temp = netlBufIn[3];
			netlBufOut[0] = 3 * 4;		// �T�C�Y
			netlBufOut[1] = temp;		// ���M��ID
			netlBufOut[2] = 0;			// �R�}���h�i�ΐ�v���j
			tcpSend(&netlBufOut, netlBufOut[0]);
		}
		// ���肪������Ȃ�
		else if(command == 4) {
			netlEnemyNotFound = 180;
		}
		// �v���C���[�����
		else if(command == 5) {
			netlSameModeClientCount[0] = netlBufIn[3];
			netlSameModeClientCount[1] = netlBufIn[4];
			netlSameModeClientCount[2] = netlBufIn[5];
		}
	}
	// ���̃v���C���[����̃��b�Z�[�W�̏ꍇ
	else {
		// �ΐ�v��
		if(command == 0) {
			// ���肪���܂��Ă��Ȃ��Ƃ�
			if(netlEnemyID == 0) {
				PlaySE(se_lvstop);
				netlEnemyID = id_from;			// ����ID�����߂�
				netlBufOut[0] = 3 * 4;			// �T�C�Y
				netlBufOut[1] = netlEnemyID;	// ���M��ID
				netlBufOut[2] = 1;				// �R�}���h�i�����j
				tcpSend(&netlBufOut, netlBufOut[0]);
			}
			// ���肪�������܂��Ă���Ƃ�
			else {
				netlBufOut[0] = 3 * 4;			// �T�C�Y
				netlBufOut[1] = id_from;		// ���M��ID
				netlBufOut[2] = 2;				// �R�}���h�i���ہj
				tcpSend(&netlBufOut, netlBufOut[0]);
			}
		}
		// �ΐ�̏���������
		else if(command == 1) {
			if(netlEnemyID == 0) {
				PlaySE(se_lvstop);
				netlEnemyID = id_from;			// ����ID�����߂�
			}
		}
		// �ΐ�����ۂ��ꂽ
		else if(command == 2) {
			if(netlEnemyID == 0) {
				netlEnemyNotFound = 180;
			}
		}
		// ���[��������M
		else if(command == 3) {
			if(id_from == netlEnemyID) {
				netlRecvEnemyRuleName();
			}
		}
		// ���[���ݒ����M
		else if(command == 4) {
			if(id_from == netlEnemyID) {
				netlRecvEnemyRuleConfig();
			}
		}
		// NEXT�u���b�N����M
		else if(command == 5) {
			if(id_from == netlEnemyID) {
				netlRecvEnemyNextList();
			}
		}
		// ����̏�������
		else if(command == 6) {
			if(id_from == netlEnemyID) {
				netlEnemyReady = 1;
			}
		}
		// �G�̈ړ�
		else if(command == 7) {
			if(id_from == netlEnemyID) {
				netlRecvEnemyMove();
			}
		}
		// �t�B�[���h
		else if(command == 8) {
			if(id_from == netlEnemyID) {
				netlRecvField();
			}
		}
		// ���g���C
		else if(command == 9) {
			if(id_from == netlEnemyID) {
				PlaySE(se_kettei);
				StopAllBGM();
				gameAllInit();
				playerInitial(0);
				playerInitial(1);
				if(netlPlayerType == 0) versusInit(0);
				stat[0] = 3;
				stat[1] = 3;
			}
		}
		// ����̃��[�h�ݒ����M
		else if(command == 10) {
			if(id_from == netlEnemyID) {
				netlRecvModeConfig();
			}
		}
		// ����̃��C����
		else if(command == 11) {
			if(id_from == netlEnemyID) {
				netlLines[1] = netlBufIn[3];
			}
		}
		// ����̃v���C����
		else if(command == 12) {
			if(id_from == netlEnemyID) {
				netlLines[1] = netlBufIn[3];
				gameTimer[1] = netlBufIn[4];
			}
		}
	}
}

// �T�[�o�[�Ɏ����̃o�[�W�������𑗐M
void netlSendVersionDataToServer() {
	int i, strbuf[8];
	
	// ��{���
	netlBufOut[0] = 13 * 4;				// �T�C�Y
	netlBufOut[1] = 0;					// ���M��ID
	netlBufOut[2] = 1;					// �R�}���h
	netlBufOut[3] = engineVer;			// �Q�[���G���W���̃o�[�W����
	netlBufOut[4] = netlModeVersion;	// ���[�h�̃o�[�W����
	
	// ���[�h��
	for(i = 0; i < 8; i++) strbuf[i] = 0;
	StrCpy(&strbuf, plugin_name_mode[gameMode[0]]);
	for(i = 0; i < 8; i++) netlBufOut[5 + i] = strbuf[i];
	
	// ���M
	tcpSend(&netlBufOut, netlBufOut[0]);
}

// �����̃��[�����𑗐M
void netlSendPlayerRuleName() {
	int i, strbuf[8];
	
	// ��{���
	netlBufOut[0] = 11 * 4;			// �T�C�Y
	netlBufOut[1] = netlEnemyID;	// ���M��ID
	netlBufOut[2] = 3;				// �R�}���h
	
	// ���[����
	for(i = 0; i < 8; i++) strbuf[i] = 0;
	StrCpy(&strbuf, plugin_name_rule[rots[0]]);
	for(i = 0; i < 8; i++) netlBufOut[3 + i] = strbuf[i];
	
	// ���M
	tcpSend(&netlBufOut, netlBufOut[0]);
}

// ����̃��[��������M
void netlRecvEnemyRuleName() {
	int i, strbuf[8], temp;
	
	for(i = 0; i < 8; i++) strbuf[i] = netlBufIn[3 + i];
	StrCpy(string[1], &strbuf);
	temp = findRulePlugin(string[1]);
	if(temp != -1) {
		rots[1] = temp;
		netlEnemyRulePluginMissing = 0;
	} else {
		rots[1] = rots[0];
		netlEnemyRulePluginMissing = 1;
	}
	
	netlReceiveRuleNameOK = 1;
}

// �����̃��[���ݒ��netlRuleConfigPlayer�ɃR�s�[����
void netlBackupPlayerRuleConfig() {
	int i;
	
	if(rotlimit[0] == 0) rotlimit[0] = 128;
	if(movelimit[0] == 0) movelimit[0] = 128;
	
	netlRuleConfigPlayer[0] = kicktype[0];
	netlRuleConfigPlayer[1] = lockreset[0];
	netlRuleConfigPlayer[2] = rotlimit[0];
	netlRuleConfigPlayer[3] = movelimit[0];
	netlRuleConfigPlayer[4] = blockgraphics[0];
	netlRuleConfigPlayer[5] = are[0];
	netlRuleConfigPlayer[6] = lock_up[0];
	netlRuleConfigPlayer[7] = lock_down[0];
	netlRuleConfigPlayer[8] = rot_reverse[0];
	netlRuleConfigPlayer[9] = softspeed[0];
	netlRuleConfigPlayer[10] = max_waitt[0];
	netlRuleConfigPlayer[11] = fastlrmove[0];
	netlRuleConfigPlayer[12] = oblk_bg[0];
	for(i = 0; i < 7; i++) netlRuleConfigPlayer[13 + i] = blockcolor[i];
	netlRuleConfigPlayer[20] = initial_rotate[0];
	netlRuleConfigPlayer[21] = initial_hold[0];
	netlRuleConfigPlayer[22] = enable_wallkick[0];
	netlRuleConfigPlayer[23] = self_lock_sound[0];
	netlRuleConfigPlayer[24] = lockflash[0];
	netlRuleConfigPlayer[25] = RepeatDelay[0];
}

// netlRuleConfigEnemy���瑊��̃��[���ݒ�𔽉f������
void netlApplyEnemyRuleConfig() {
	int i;
	
	kicktype[1] = netlRuleConfigEnemy[0];
	lockreset[1] = netlRuleConfigEnemy[1];
	rotlimit[1] = netlRuleConfigEnemy[2];
	movelimit[1] = netlRuleConfigEnemy[3];
	blockgraphics[1] = netlRuleConfigEnemy[4];
	are[1] = netlRuleConfigEnemy[5];
	lock_up[1] = netlRuleConfigEnemy[6];
	lock_down[1] = netlRuleConfigEnemy[7];
	rot_reverse[1] = netlRuleConfigEnemy[8];
	softspeed[1] = netlRuleConfigEnemy[9];
	max_waitt[1] = netlRuleConfigEnemy[10];
	fastlrmove[1] = netlRuleConfigEnemy[11];
	oblk_bg[1] = netlRuleConfigEnemy[12];
	for(i = 0; i < 7; i++) blockcolor[i + 7] = netlRuleConfigEnemy[13 + i];
	initial_rotate[1] = netlRuleConfigEnemy[20];
	initial_hold[1] = netlRuleConfigEnemy[21];
	enable_wallkick[1] = netlRuleConfigEnemy[22];
	self_lock_sound[1] = netlRuleConfigEnemy[23];
	lockflash[1] = netlRuleConfigEnemy[24];
	RepeatDelay[1] = netlRuleConfigEnemy[25];
}

// �����̃��[���ݒ�𑗐M
void netlSendPlayerRuleConfig() {
	int i, strbuf[16];
	
	// ��{���
	netlBufOut[0] = 45 * 4;			// �T�C�Y
	netlBufOut[1] = netlEnemyID;	// ���M��ID
	netlBufOut[2] = 4;				// �R�}���h
	
	// ���[���ݒ�
	netlBackupPlayerRuleConfig();
	for(i = 0; i < 26; i++) netlBufOut[3 + i] = netlRuleConfigPlayer[i];
	
	// �j�b�N�l�[��
	for(i = 0; i < 16; i++) strbuf[i] = 0;
	if(networkUseNick) StrCpy(&strbuf, netlNickname[0]);
	for(i = 0; i < 16; i++) netlBufOut[29 + i] = strbuf[i];
	
	// ���M
	tcpSend(&netlBufOut, netlBufOut[0]);
}

// ����̃��[���ݒ����M
void netlRecvEnemyRuleConfig() {
	int i, strbuf[16];
	
	// ���[���ݒ�
	for(i = 0; i < 26; i++) netlRuleConfigEnemy[i] = netlBufIn[3 + i];
	
	// �j�b�N�l�[��
	if(networkUseNick) {
		for(i = 0; i < 16; i++) strbuf[i] = netlBufIn[29 + i];
		StrCpy(netlNickname[1], &strbuf);
		
		netlViewNickname(0);
		netlViewNickname(1);
	}
	
	netlReceiveRuleConfigOK = 1;
}

// ������NEXT�u���b�N�𑗐M
void netlSendPlayerNextList() {
	int i, j, temp;
	
	// ��{���
	netlBufOut[0] = 179 * 4;		// �T�C�Y
	netlBufOut[1] = netlEnemyID;	// ���M��ID
	netlBufOut[2] = 5;				// �R�}���h
	netlBufOut[3] = nextc_max[0];	// NEXT�ő吔
	
	// NEXT�u���b�N
	for(i = 0; i < 175; i++) {
		temp = 0;
		for(j = 0; j < 8; j++) {
			temp = temp | (nextb[(i << 3) + j] << (j * 4));
		}
		netlBufOut[i + 4] = temp;
	}
	
	// ���M
	tcpSend(&netlBufOut, netlBufOut[0]);
}

// �����NEXT�u���b�N����M
void netlRecvEnemyNextList() {
	int i, j, temp;
	
	nextc_max[0] = netlBufIn[3];	// NEXT�ő吔
	if(nextc_max[0] == 0) nextc_max[0] = 1400;
	
	for(i = 0; i < 175; i++) {
		for(j = 0; j < 8; j++) {
			nextb[(i << 3) + j] = ((netlBufIn[i + 4]) >> (j * 4)) & 15;
		}
	}
	netlCopyNextList();
	
	netlReceiveNextListOK = 1;
}

// 1P��NEXT��2P�ɃR�s�[
void netlCopyNextList() {
	int i;
	for(i = 0; i < 1400; i++) nextb[i + 1400] = nextb[i];
	nextc[1] = nextc[0];
	nextc_max[1] = nextc_max[0];
}

// �����̃��[�h�ݒ�𑗐M
void netlSendModeConfig() {
	netlBufOut[0] = 19 * 4;				// �T�C�Y
	netlBufOut[1] = netlEnemyID;		// ���M��ID
	netlBufOut[2] = 10;					// �R�}���h
	netlBufOut[3] = netlGhost;			// �S�[�X�g�̗L��
	netlBufOut[4] = netlSpeed;			// �������x
	netlBufOut[5] = netlSpeedType;		// �X�s�[�h�^�C�v
	netlBufOut[6] = netlWait1;			// ARE
	netlBufOut[7] = netlWait2;			// ���C������
	netlBufOut[8] = netlWait3;			// �Œ莞��
	netlBufOut[9] = netlWaitt;			// ������
	netlBufOut[10] = netlWait4;			// �Œ莞�ԁi�ڒ���j
	netlBufOut[11] = netlWait5;			// ARE�i������j
	netlBufOut[12] = netlNormLine;		// �K�胉�C����
	netlBufOut[13] = netlAreUse;		// ARE Force
	netlBufOut[14] = netlFastlrmove;	// INIT LR Force
	netlBufOut[15] = netlRepeatDelay;	// Repeat Delay
	netlBufOut[16] = netlMaxDAS;		// Disable Max DAS
	netlBufOut[17] = netlSpawnType;		// SPAWN Y TYPE Force
	netlBufOut[18] = netlHoldEnable;	// Enable Hold
	
	tcpSend(&netlBufOut, netlBufOut[0]);
}

// ����̃��[�h�ݒ����M
void netlRecvModeConfig() {
	netlGhost = netlBufIn[3];
	netlSpeed = netlBufIn[4];
	netlSpeedType = netlBufIn[5];
	netlWait1 = netlBufIn[6];
	netlWait2 = netlBufIn[7];
	netlWait3 = netlBufIn[8];
	netlWaitt = netlBufIn[9];
	netlWait4 = netlBufIn[10];
	netlWait5 = netlBufIn[11];
	netlNormLine = netlBufIn[12];
	netlAreUse = netlBufIn[13];
	netlFastlrmove = netlBufIn[14];
	netlRepeatDelay = netlBufIn[15];
	netlMaxDAS = netlBufIn[16];
	netlSpawnType = netlBufIn[17];
	netlHoldEnable = netlBufIn[18];
	
	netlReceiveModeConfigOK = 1;
}

// �e��ݒ�𔽉f������
void netlApplyModeConfig(int player) {
	ghost[player] = netlGhost;
	sp[player] = netlSpeed;
	speedtype[player] = netlSpeedType;
	wait1[player] = netlWait1;
	wait2[player] = netlWait2;
	wait3[player] = netlWait3;
	waitt[player] = netlWaitt;
	wait4[player] = netlWait4;
	wait5[player] = netlWait5;
	
	if(netlAreUse > -1) are[player] = netlAreUse;
	if(netlFastlrmove > -1) fastlrmove[player] = netlFastlrmove;
	if(netlRepeatDelay > -1) RepeatDelay[player] = netlRepeatDelay;
	if(netlMaxDAS > -1) max_waitt[player] = 99;
	if(netlSpawnType > -1) spawntype[player] = netlSpawnType;
	if(netlHoldEnable > -1) {
		if(netlHoldEnable == 0) dhold[player] = 2;
		else dhold[player] = 0;
	}
}

// �ݒ���
void netlSetting(int player, int *param) {
	int page;
	
	// BGM�͍ŏ��ɓǂݍ���ł���
	netlLoadBGM();
	
	// �ϐ��̏�����
	page = 0;
	
	// �Q�[�����̕ϐ���ݒ�
	netplay = 1;
	maxPlay = 1;
	SetFPS(60);
	SetConstParam("EnablePause", 0);
	
	// �ʐM�̏�����
	tcpStartup();
	
	// ���C�����[�v
	loop {
		if(page < 0) {
			tcpCleanup();
			netplay = 0;
			SetConstParam("EnablePause", 1);
			param[0] = 0;
			return;
		}
		else if(page == 0) page = netlMenuServerSelect();
		else if(page == 1) page = netlMenuServerConnect();
		else if(page == 2) page = netlMenuSelectPlayType();
		else if(page == 3) page = netlMenuGameOptions();
		else return;
	}
}

// �T�[�o�[�I�����
int netlMenuServerSelect() {
	int i, move;
	
	// �ϐ��̏�����
	netlPlayerType = 0;
	netlGameStart = 0;
	netlTraining = 0;
	netlReceiveRuleNameOK = 0;
	netlEnemyID = 0;
	netlEnemyNotFound = 0;
	netlEnemyDisconnect = 0;
	netlEnemyRulePluginMissing = 0;
	netlServerVersion = -1;
	netlClientCount = -1;
	netlMaxClient = -1;
	netlSameModeClientCount[0] = -1;
	netlSameModeClientCount[1] = -1;
	netlSameModeClientCount[2] = -1;
	netlCountUpdateFrame = 0;
	netlRound = 0;
	netlWin[0] = 0;
	netlWin[1] = 0;
	
	// �\�P�b�g�쐬
	tcpSocket();
	
	// ���C�����[�v
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "SELECT A SERVER", 4);
		printFontGrid(1, 27, "A:OK B:BACK", 6);
		
		// �I�ꗗ�\��
		for(i = 0; i < 10; i++) {
			sprintf(string[0], "%s:%d", networkServerName[i], networkServerPort[i]);
			printSMALLFont(8, 24 + i * 9, string[0], 7 * (netlServerNo == i));
		}
		
		// �J�[�\���ړ�
		padRepeat2(0);
		
		move = 0;
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
			move = getPressState(0, 1) - getPressState(0, 0);
		
		if(move) {
			PlaySE(se_move);
			netlServerNo = netlServerNo + move;
			if(netlServerNo < 0) netlServerNo = 9;
			if(netlServerNo > 9) netlServerNo = 0;
		}
		
		// �L�����Z��
		if(getPushState(0, 5)) {
			PlaySE(se_move);
			return -1;
		}
		
		// ����
		if(getPushState(0, 4)) {
			PlayWave(se_kettei);
			return 1;
		}
	}
}

// �T�[�o�[�ڑ����
int netlMenuServerConnect() {
	int cursor;
	cursor = 0;
	
	// �ڑ�
	tcpConnect(networkServerName[netlServerNo], networkServerPort[netlServerNo]);
	
	// ���C�����[�v
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		// ���s
		if(tcpIsErrorEvent()) {
			printFontGrid(1, 1, "CONNECT FAILED", 2);
			sprintf(string[0], "ERROR CODE:%d", tcpWSAGetLastError());
			printFontGrid(1, 3, string[0], 0);
			
			printFontGrid(1, 27, "A:RETRY B:BACK", 6);
			
			// �L�����Z��
			if(getPushState(0, 5)) {
				PlaySE(se_move);
				tcpClosesocket();
				return 0;
			}
			
			// ���g���C
			if(getPushState(0, 4)) {
				PlayWave(se_kettei);
				tcpConnect(networkServerName[netlServerNo], networkServerPort[netlServerNo]);
			}
		}
		// ����
		else if(tcpIsConnect()) {
			// �o�[�W�������𑗐M
			netlSendVersionDataToServer();
			
			// �I����v������
			netlBufOut[0] = 3 * 4;		// �T�C�Y
			netlBufOut[1] = 0;			// ���M��ID
			netlBufOut[2] = 0;			// �R�}���h
			tcpSend(&netlBufOut, netlBufOut[0]);
			
			return 2;
		}
		// �ڑ���
		else {
			printFontGrid(1, 1, "CONNECTING TO SERVER...", 4);
			printFontGrid(1, 27, "B:BACK", 6);
			
			// �L�����Z��
			if(getPushState(0, 5)) {
				PlaySE(se_move);
				tcpClosesocket();
				return 0;
			}
		}
	}
}

// �v���C���@�I�����
int netlMenuSelectPlayType() {
	int i, move;
	
	// ���C�����[�v
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "SELECT PLAY TYPE", 4);
		printFontGrid(1, 27, "A:OK B:BACK", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + netlPlayerType, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "PLAY AS HOST",  7 * (netlPlayerType == 0));
		printFontGrid(2, 4, "PLAY AS GUEST", 7 * (netlPlayerType == 1));
		
		// �I���
		if(netlServerVersion != -1) {
			sprintf(string[0], "SERVER VERSION:%d", netlServerVersion);
			printFontGrid(1, 22, string[0], 6);
		}
		if((netlMaxClient > 0) && (netlServerVersion >= 2)) {
			sprintf(string[0], "MAX PLAYER:%d", netlMaxClient);
			printFontGrid(1, 23, string[0], 6);
		}
		if(netlClientCount != -1) {
			sprintf(string[0], "ALL OTHER PLAYERS IN SERVER:%d", netlClientCount - 1);
			printFontGrid(1, 24, string[0], 6);
		}
		if((netlSameModeClientCount[0] != -1) && (netlServerVersion >= 2)) {
			sprintf(string[0], "SAME MODE PLAYERS:%d/%d/%d", netlSameModeClientCount[0], netlSameModeClientCount[1], netlSameModeClientCount[2]);
			printFontGrid(1, 25, string[0], 6);
		}
		
		// �J�[�\���ړ�
		padRepeat2(0);
		
		move = 0;
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
			move = getPressState(0, 1) - getPressState(0, 0);
		
		if(move) {
			PlaySE(se_move);
			netlPlayerType = netlPlayerType + move;
			if(netlPlayerType < 0) netlPlayerType = 1;
			if(netlPlayerType > 1) netlPlayerType = 0;
		}
		
		// �L�����Z��
		if(getPushState(0, 5)) {
			PlaySE(se_move);
			tcpClosesocket();
			return 0;
		}
		
		// ����
		if(getPushState(0, 4)) {
			PlayWave(se_kettei);
			
			if(!netlPlayerType) {
				// �z�X�g
				return 3;
			} else {
				// �Q�X�g�Ȃ̂ő����T��
				netlBufOut[0] = 3 * 4;		// �T�C�Y
				netlBufOut[1] = 0;			// ���M��ID
				netlBufOut[2] = 3;			// �R�}���h
				tcpSend(&netlBufOut, netlBufOut[0]);
				return 4;
			}
		}
		
		// �v���C���[���擾
		if(netlServerVersion >= 2) {
			if(netlCountUpdateFrame <= 0) {
				netlCountUpdateFrame = 180;
				netlBufOut[0] = 3 * 4;		// �T�C�Y
				netlBufOut[1] = 0;			// ���M��ID
				netlBufOut[2] = 4;			// �R�}���h
				tcpSend(&netlBufOut, netlBufOut[0]);
			} else {
				netlCountUpdateFrame--;
			}
		}
	}
}

// �Q�[���ݒ�
int netlMenuGameOptions() {
	int cursor, move;
	cursor = 0;
	
	if(netlLoadConfig() == 0) {
		netlMakeDefaultPreset();
	}
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "GAME OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:BACK", 6);
		
		// �J�[�\��
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// �ݒ荀�ڈꗗ
		printFontGrid(2, 3, "GHOST BLOCK",  (cursor == 0) * 7);
		printFontGrid(2, 4, "SPEED",        (cursor == 1) * 7);
		printFontGrid(2, 5, "SPEED TYPE",   (cursor == 2) * 7);
		if(!english) printFontGrid(2, 6, "SYUTUGEN", (cursor == 3) * 7);
		else printFontGrid(2, 6, "ARE", (cursor == 3) * 7);
		if(!english) printFontGrid(2, 7, "SYOUKYO", (cursor == 4) * 7);
		else printFontGrid(2, 7, "LINE DELAY", (cursor == 4) * 7);
		if(!english) printFontGrid(2, 8, "SETTYAKU", (cursor == 5) * 7);
		else printFontGrid(2, 8, "LOCK DELAY", (cursor == 5) * 7);
		if(!english) printFontGrid(2, 9, "YOKOTAME", (cursor == 6) * 7);
		else printFontGrid(2, 9, "DAS", (cursor == 6) * 7);
		if(!english) printFontGrid(2, 10, "SETTYAKU2", (cursor == 7) * 7);
		else printFontGrid(2, 10, "LOCK DELAY2", (cursor == 7) * 7);
		if(!english) printFontGrid(2, 11, "SYUTUGEN2", (cursor == 8) * 7);
		else printFontGrid(2, 11, "ARE2", (cursor == 8) * 7);
		printFontGrid(2, 12, "FORCE ARE", (cursor == 9) * 7);
		printFontGrid(2, 13, "FORCE INIT LR MOVE", (cursor == 10) * 7);
		printFontGrid(2, 14, "FORCE REPEAT DELAY", (cursor == 11) * 7);
		if(!english) printFontGrid(2, 15, "FORCE MAX YOKOTAME", (cursor == 12) * 7);
		else printFontGrid(2, 15, "FORCE MAX DAS", (cursor == 12) * 7);
		printFontGrid(2, 16, "FORCE SPAWN Y TYPE", (cursor == 13) * 7);
		printFontGrid(2, 17, "FORCE HOLD", (cursor == 14) * 7);
		printFontGrid(2, 18, "GOAL LINES", (cursor == 15) * 7);
		printFontGrid(2, 19, "[SAVE PRESET]", (cursor == 16) * 7);
		printFontGrid(2, 20, "[LOAD PRESET]", (cursor == 17) * 7);
		
		// �ݒ�l�\��
		if(!netlGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], (cursor == 0) * 7);
		
		sprintf(string[0], "%d", netlSpeed);
		printFontGrid(22, 4, string[0], (cursor == 1) * 7);
		
		if(netlSpeedType == 0) sprintf(string[0], "1/60");
		else if(netlSpeedType == 1) sprintf(string[0], "FRAMES PER ROW");
		else sprintf(string[0], "1/256");
		printFontGrid(22, 5, string[0], (cursor == 2) * 7);
		
		sprintf(string[0], "%d", netlWait1);
		printFontGrid(22, 6, string[0], (cursor == 3) * 7);
		
		sprintf(string[0], "%d", netlWait2);
		printFontGrid(22, 7, string[0], (cursor == 4) * 7);
		
		sprintf(string[0], "%d", netlWait3);
		printFontGrid(22, 8, string[0], (cursor == 5) * 7);
		
		sprintf(string[0], "%d", netlWaitt);
		printFontGrid(22, 9, string[0], (cursor == 6) * 7);
		
		if(netlWait4 == -1) sprintf(string[0], "NO USE");
		else sprintf(string[0], "%d", netlWait4);
		printFontGrid(22, 10, string[0], (cursor == 7) * 7);
		
		if(netlWait5 == -1) sprintf(string[0], "NO USE");
		else sprintf(string[0], "%d", netlWait5);
		printFontGrid(22, 11, string[0], (cursor == 8) * 7);
		
		if(netlAreUse == -1) sprintf(string[0], "PLAYER CHOICE");
		else if(netlAreUse == 0) sprintf(string[0], "OFF");
		else if(netlAreUse == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "ON (WITH SKIP)");
		printFontGrid(22, 12, string[0], (cursor == 9) * 7);
		
		if(netlFastlrmove == -1) sprintf(string[0], "PLAYER CHOICE");
		else if(netlFastlrmove == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 13, string[0], (cursor == 10) * 7);
		
		if(netlRepeatDelay == -1) sprintf(string[0], "PLAYER CHOICE");
		else if(netlRepeatDelay == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "%d", netlRepeatDelay);
		printFontGrid(22, 14, string[0], (cursor == 11) * 7);
		
		if(netlMaxDAS == -1) sprintf(string[0], "PLAYER CHOICE");
		else sprintf(string[0], "FORCE DISABLE");
		printFontGrid(22, 15, string[0], (cursor == 12) * 7);
		
		if(netlSpawnType == -1) sprintf(string[0], "PLAYER CHOICE");
		else if(netlSpawnType == 0) sprintf(string[0], "UNDER THE FRAME");
		else sprintf(string[0], "ABOVE THE FRAME");
		printFontGrid(22, 16, string[0], (cursor == 13) * 7);
		
		if(netlHoldEnable == -1) sprintf(string[0], "PLAYER CHOICE");
		else if(netlHoldEnable == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 17, string[0], (cursor == 14) * 7);
		
		sprintf(string[0], "%d", netlNormLine);
		printFontGrid(22, 18, string[0], (cursor == 15) * 7);
		
		sprintf(string[0], "PRESET NO.%d", netlLastPresetNo + 1);
		printFontGrid(22, 19, string[0], (cursor >= 16) * 7);
		
		// �J�[�\���ړ�
		padRepeat2(0);
		
		move = 0;
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
			move = getPressState(0, 1) - getPressState(0, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 17;
			if(cursor > 17) cursor = 0;
		}
		
		// �l��ύX
		padRepeat(0);
		
		move = 0;
		if((mpc[0] == 1) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6))
			move = getPressState(0, 3) - getPressState(0, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) netlGhost = !netlGhost;
			if(cursor == 1) {
				netlSpeed = netlSpeed + move;
				if(netlSpeed < 1) netlSpeed = 5120;
				if(netlSpeed > 5120) netlSpeed = 1;
			}
			if(cursor == 2) {
				netlSpeedType = netlSpeedType + move;
				if(netlSpeedType < 0) netlSpeedType = 2;
				if(netlSpeedType > 2) netlSpeedType = 0;
			}
			if(cursor == 3) {
				netlWait1 = netlWait1 + move;
				if(netlWait1 < 0) netlWait1 = 99;
				if(netlWait1 > 99) netlWait1 = 0;
			}
			if(cursor == 4) {
				netlWait2 = netlWait2 + move;
				if(netlWait2 < 0) netlWait2 = 99;
				if(netlWait2 > 99) netlWait2 = 0;
			}
			if(cursor == 5) {
				netlWait3 = netlWait3 + move;
				if(netlWait3 < 0) netlWait3 = 98;
				if(netlWait3 > 98) netlWait3 = 0;
			}
			if(cursor == 6) {
				netlWaitt = netlWaitt + move;
				if(netlWaitt < 0) netlWaitt = 99;
				if(netlWaitt > 99) netlWaitt = 0;
			}
			if(cursor == 7) {
				netlWait4 = netlWait4 + move;
				if(netlWait4 < -1) netlWait4 = 98;
				if(netlWait4 > 98) netlWait4 = -1;
			}
			if(cursor == 8) {
				netlWait5 = netlWait5 + move;
				if(netlWait5 < -1) netlWait5 = 99;
				if(netlWait5 > 99) netlWait5 = -1;
			}
			if(cursor == 9) {
				netlAreUse = netlAreUse + move;
				if(netlAreUse < -1) netlAreUse = 2;
				if(netlAreUse > 2) netlAreUse = -1;
			}
			if(cursor == 10) {
				netlFastlrmove = netlFastlrmove + move;
				if(netlFastlrmove < -1) netlFastlrmove = 1;
				if(netlFastlrmove > 1) netlFastlrmove = -1;
			}
			if(cursor == 11) {
				netlRepeatDelay = netlRepeatDelay + move;
				if(netlRepeatDelay < -1) netlRepeatDelay = 99;
				if(netlRepeatDelay > 99) netlRepeatDelay = -1;
			}
			if(cursor == 12) {
				netlMaxDAS = netlMaxDAS + move;
				if(netlMaxDAS < -1) netlMaxDAS = 0;
				if(netlMaxDAS > 0) netlMaxDAS = -1;
			}
			if(cursor == 13) {
				netlSpawnType = netlSpawnType + move;
				if(netlSpawnType < -1) netlSpawnType = 1;
				if(netlSpawnType > 1) netlSpawnType = -1;
			}
			if(cursor == 14) {
				netlHoldEnable = netlHoldEnable + move;
				if(netlHoldEnable < -1) netlHoldEnable = 1;
				if(netlHoldEnable > 1) netlHoldEnable = -1;
			}
			if(cursor == 15) {
				netlNormLine = netlNormLine + move;
				if(netlNormLine < 1) netlNormLine = 99;
				if(netlNormLine > 99) netlNormLine = 1;
			}
			if(cursor >= 16) {
				netlLastPresetNo = netlLastPresetNo + move;
				if(netlLastPresetNo < 0) netlLastPresetNo = 9;
				if(netlLastPresetNo > 9) netlLastPresetNo = 0;
			}
		}
		
		// ����
		if(getPushState(0, 4)) {
			PlaySE(se_kettei);
			
			if(cursor == 16) {
				netlSavePreset(netlLastPresetNo);
				netlSaveConfig();
			} else if(cursor == 17) {
				netlLoadPreset(netlLastPresetNo);
			} else {
				netlSaveConfig();
				
				// ����҂���ԂɂȂ�
				netlBufOut[0] = 4 * 4;		// �T�C�Y
				netlBufOut[1] = 0;			// ���M��ID
				netlBufOut[2] = 2;			// �R�}���h
				netlBufOut[3] = 1;			// ���
				tcpSend(&netlBufOut, netlBufOut[0]);
				
				return 4;
			}
		}
		
		// �L�����Z��
		if(getPushState(0, 5)) {
			PlaySE(se_move);
			return 2;
		}
	}
}

// ����������
void netlPlayerInitial(int player) {
	backno = 20;								// �w�i�ύX
	setFieldPosition(player, 2);				// �t�B�[���h�ʒu�ݒ�
	blkshadow_direction[player] = 1 - player;	// �u���b�N�̉e
	hnext[player] = 0;							// NEXT�͊J�n�܂Ō����Ȃ�
	bgmlv = 10;									// BGM�ԍ��ݒ�
	
	netlLines[player] = 0;
	
	netlLastBlk[player] = 0;
	netlLastBx[player] = 0;
	netlLastBy[player] = 0;
	netlLastRt[player] = 0;
	netlLastNDelay[player] = 0;
	
	netlCustomStatNo[player] = 0;
	
	netlGameStart = 0;
	netlTraining = 0;
	netlEnemyReady = 0;
	netlEnemyBlockVisible = 0;
	netlReceiveRuleConfigOK = 0;
	netlReceiveNextListOK = 0;
	netlReceiveModeConfigOK = 0;
}

// Ready���
void netlReady(int player, int *param) {
	// ����҂����̃v���C���[���\��
	if((netlEnemyID == 0) && (player == 1)) {
		param[0] = 1;
		
		sprintf(string[0], "ALL:%d", netlClientCount - 1);
		printFont(foffset[player] + 16, fyoffset[player] + 108, string[0], 6);
		sprintf(string[0], "SAME MODE\n%d/%d/%d", netlSameModeClientCount[0], netlSameModeClientCount[1], netlSameModeClientCount[2]);
		printFont(foffset[player] + 16, fyoffset[player] + 124, string[0], 6);
	}
	// ����҂����̃��j���[
	else if((netlEnemyID == 0) && (player == 0) && (!netlTraining)) {
		param[0] = 1;
		
		printFont(foffset[player] + 8, fyoffset[player] + 108 + statc[player * 10 + 2] * 16, "b", (count % 4 / 2) * 7);
		
		printFont(foffset[player] + 16, fyoffset[player] + 108, "TRAINING", (statc[player * 10 + 2] == 0) * (count % 4 / 2) * 7);
		printFont(foffset[player] + 16, fyoffset[player] + 124, "EXIT", (statc[player * 10 + 2] == 1) * (count % 4 / 2) * 7);
		
		// �㉺
		if(getPushState(player, 0) || getPushState(player, 1)) {
			PlaySE(se_move);
			statc[player * 10 + 2] = !statc[player * 10 + 2];
		}
		
		// ����
		if(getPushState(player, 4)) {
			// TRAINING
			if(statc[player * 10 + 2] == 0) {
				PlaySE(se_kettei);
				netlTraining = 1;
				hnext[player] = dispnext;
				netlApplyModeConfig(0);
			}
			// EXIT
			else {
				tcpClosesocket();
				flag = 1;
			}
		}
	}
	// ���茈���A�Q�[���J�n�O
	else if((!netlGameStart) && (!netlTraining)) {
		param[0] = 1;
		
		if(player == 0) {
			// �����̃��[�������M
			if(statc[player * 10 + 1] == 0) {
				netlSendPlayerRuleName();
				
				// �����̏�Ԃ�ύX
				netlBufOut[0] = 4 * 4;		// �T�C�Y
				netlBufOut[1] = 0;			// ���M��ID
				netlBufOut[2] = 2;			// �R�}���h
				netlBufOut[3] = 2;			// ���
				tcpSend(&netlBufOut, netlBufOut[0]);
				
				statc[player * 10 + 1] = 1;
			}
			// ����̃��[������M
			else if(statc[player * 10 + 1] == 1) {
				if(netlReceiveRuleNameOK) {
					playerInitial(1);			// �����������
					stat[1] = 3;
					statc[player * 10 + 1] = 2;
				}
			}
			// �����̃��[���ݒ著�M
			else if(statc[player * 10 + 1] == 2) {
				netlSendPlayerRuleConfig();	// �����̃��[���ݒ�𑗐M����
				statc[player * 10 + 1] = 3;
			}
			// �������z�X�g�Ȃ�NEXT�u���b�N�𑗐M����
			else if(statc[player * 10 + 1] == 3) {
				if(!netlPlayerType) {
					netlCopyNextList();			// ������NEXT�𑊎�ɃR�s�[
					netlSendPlayerNextList();	// NEXT�u���b�N�𑗐M����
					netlReceiveNextListOK = 1;	// NEXT�u���b�N�͎󂯎���������ɂ���
				}
				statc[player * 10 + 1] = 4;
			}
			// �������z�X�g�Ȃ烂�[�h�ݒ�𑗐M����
			else if(statc[player * 10 + 1] == 4) {
				if(!netlPlayerType) {
					netlSendModeConfig();			// ���[�h�ݒ�𑗐M����
					netlReceiveModeConfigOK = 1;	// ���[�h�ݒ�͎󂯎���������ɂ���
				}
				statc[player * 10 + 1] = 5;
			}
			// ���[���ݒ��NEXT�u���b�N�ƃ��[�h�ݒ���󂯎�����珀������
			else if(statc[player * 10 + 1] == 5) {
				if((netlReceiveRuleConfigOK) && (netlReceiveNextListOK) && (netlReceiveModeConfigOK)) {
					netlApplyEnemyRuleConfig();		// �G�̃��[����K�p
					netlApplyModeConfig(0);			// ���[�h�ݒ��K�p
					netlApplyModeConfig(1);
					
					netlBufOut[0] = 3 * 4;			// �T�C�Y
					netlBufOut[1] = netlEnemyID;	// ���M��ID
					netlBufOut[2] = 6;				// �R�}���h
					tcpSend(&netlBufOut, netlBufOut[0]);
					
					statc[player * 10 + 1] = 6;
				}
			}
			// ����̏���������������n�߂�
			else if(statc[player * 10 + 1] == 6) {
				if(netlEnemyReady) {
					netlGameStart = 1;
					resetStatc(0);
					resetStatc(1);
					setNextBlockColor(0, 1);
					setNextBlockColor(1, 1);
					hnext[0] = dispnext;
					hnext[1] = dispnext;
					netlRound++;
				}
			}
		}
	}
}

// �u���b�N�ړ�����
void netlStatMove(int player, int *param) {
	int bottom;
	
	if(player == 1) {
		// �G
		param[0] = 1;
		
		if((!netlEnemyRulePluginMissing) && (netlEnemyBlockVisible)) {
			// �S�[�X�g
			if(ghost[1]) {
				for(bottom = by[1]; judgeBlock(1, bx[1], bottom, blk[1], rt[1]) == 0; bottom++);
				bottom--;
				drawGBlock(1, bottom);
			}
			
			// �u���b�N
			drawCBlock(1, 0, 0);
		}
	}
}

// �e�t���[���̏I���̏���
void netlIncrementTime(int player) {
	if(player == 0) {
		// �����̈ړ����
		if((stat[0] == 4) && (bactivetime[player] != 0)) {
			if((blk[0] != netlLastBlk[0]) || (bx[0] != netlLastBx[0]) || (by[0] != netlLastBy[0]) || (rt[0] != netlLastRt[0]) || 
			   (ndelay[0] != netlLastNDelay[0]))
			{
				netlLastBlk[0] = blk[0];
				netlLastBx[0] = bx[0];
				netlLastBy[0] = by[0];
				netlLastRt[0] = rt[0];
				netlLastNDelay[0] = ndelay[0];
				netlSendPlayerMove();
			}
		}
		
		if((onRecord[0]) && (!netlTraining)) {
			if(netlEnemyDisconnect) {
				// �ؒf
				stat[0] = 2;
				stat[1] = 2;
				netlCustomStatNo[0] = 0;
				netlCustomStatNo[1] = 0;
				resetStatc(0);
				resetStatc(1);
				onRecord[0] = 0;
				onRecord[1] = 0;
				timeOn[0] = 0;
				timeOn[1] = 0;
				pinch[0] = 0;
				pinch[1] = 0;
				StopAllBGM();
				tcpClosesocket();
			} else {
				// ����
				if(netlLines[0] >= netlNormLine) {
					stat[0] = 1;
				}
				if(netlLines[1] >= netlNormLine) {
					stat[0] = 7;
					resetStatc(0);
				}
			}
		}
		
		// ���肪���Ȃ��Ƃ�
		if((netlEnemyID == 0) && (!netlEnemyDisconnect)) {
			// �������Q�X�g�̂Ƃ��͑����T��
			if((netlEnemyNotFound != 0) && (netlPlayerType == 1)) {
				netlEnemyNotFound--;
				
				if(netlEnemyNotFound <= 0) {
					netlBufOut[0] = 3 * 4;		// �T�C�Y
					netlBufOut[1] = 0;			// ���M��ID
					netlBufOut[2] = 3;			// �R�}���h
					tcpSend(&netlBufOut, netlBufOut[0]);
				}
			}
			
			// �v���C���[���擾
			if(netlServerVersion >= 2) {
				if(netlCountUpdateFrame <= 0) {
					netlCountUpdateFrame = 180;
					netlBufOut[0] = 3 * 4;		// �T�C�Y
					netlBufOut[1] = 0;			// ���M��ID
					netlBufOut[2] = 4;			// �R�}���h
					tcpSend(&netlBufOut, netlBufOut[0]);
				} else {
					netlCountUpdateFrame--;
				}
			}
		}
		
		// �g���[�j���O�I��
		if((netlTraining) && (netlLines[player] >= netlNormLine) && (onRecord[0])) {
			StopAllBGM();
			stat[0] = 7;
			resetStatc(0);
		}
		
		// �g���[�j���O���ɑ���o��
		if((netlTraining) && (netlEnemyID != 0)) {
			StopAllBGM();
			gameAllInit();
			playerInitial(0);
			playerInitial(1);
			if(netlPlayerType == 0) versusInit(0);
			stat[0] = 3;
			stat[1] = 3;
		}
		
		// �|�[�Y�{�^���Ńg���[�j���O�I��
		if((netlTraining) && (onRecord[0])) {
			if(IsPushKey(pause_key[0]) | getJoyPushState(0, joy_pause_key[0])) {
				StopAllBGM();
				stat[0] = 7;
				resetStatc(0);
			}
		}
	}
}

// �����̈ړ����
void netlSendPlayerMove() {
	if(netlTraining) return;
	
	netlBufOut[0] = 12 * 4;			// �T�C�Y
	netlBufOut[1] = netlEnemyID;	// ���M��ID
	netlBufOut[2] = 7;				// �R�}���h
	
	netlBufOut[3] = blk[0];
	netlBufOut[4] = bx[0];
	netlBufOut[5] = by[0];
	netlBufOut[6] = rt[0];
	netlBufOut[7] = nextc[0];
	netlBufOut[8] = ndelay[0];
	netlBufOut[9] = hold[0];
	netlBufOut[10] = dhold[0];
	netlBufOut[11] = hold_count[0];
	
	tcpSend(&netlBufOut, netlBufOut[0]);
}

// �G�̈ړ��𔽉f������
void netlRecvEnemyMove() {
	int i;
	
	blk[1] = netlBufIn[3];
	bx[1] = netlBufIn[4];
	by[1] = netlBufIn[5];
	rt[1] = netlBufIn[6];
	nextc[1] = netlBufIn[7];
	ndelay[1] = netlBufIn[8];
	hold[1] = netlBufIn[9];
	dhold[1] = netlBufIn[10];
	hold_count[1] = netlBufIn[11];
	
	// �u���b�N�̐F��ݒ�
	for(i = 0; i < 4; i++) {
		current_color[i + 4] = blockcolor[blk[1] + 7];
		current_color_m[i + 4] = blockcolor[blk[1] + 7];
		hold_color[i + 4] = blockcolor[hold[1] + 7];
	}
	setNextBlockColor(1, 1);
	
	// ���ʉ��Đ�
	if(blk[1] != netlLastBlk[1]) {
		// �V�����u���b�N�o����
		netlLastBlk[1] = blk[1];
		if(hnext[1]) PlaySE(se_blockse[getNextBlock(1, 0)]);
	} else {
		// �ړ�
		if(bx[1] != netlLastBx[1]) {
			netlLastBx[1] = bx[1];
			if(move_sound) PlaySE(se_move);
		}
		// ��]
		if(rt[1] != netlLastRt[1]) {
			netlLastRt[1] = rt[1];
			if(rotate_sound) PlaySE(se_rotate);
		}
	}
	
	if(onRecord[0]) {
		stat[1] = 4;
		resetStatc(1);
		netlEnemyBlockVisible = 1;
	}
}

// ARE���̏���
void netlARE(int player) {
	if(player == 0) {
		// ������ARE���̏���
		if(!statc[player * 10 + 1]) {
			netlSendField(0);	// �����̃t�B�[���h�𑗐M
			statc[player * 10 + 1] = 1;
		}
	} else {
		// �����ARE���̏���
		stat[1] = 4;
		resetStatc(1);
	}
}

// �t�B�[���h�𑗐M
void netlSendField(int eraseflag) {
	int i;
	
	if(netlTraining) return;
	
	netlBufOut[0] = 60 * 4;				// �T�C�Y
	netlBufOut[1] = netlEnemyID;		// ���M��ID
	netlBufOut[2] = 8;					// �R�}���h
	netlBufOut[3] = eraseflag;			// ���C�������^�Q�[���I�[�o�[�t���O
	netlBufOut[4] = netlLines[0];		// ���C����
	
	for(i = 0; i < 55; i++) {
		netlBufOut[i + 5] = (fld[(i * 4) + 0]);
		netlBufOut[i + 5] = netlBufOut[i + 5] | (fld[(i * 4) + 1] << 8);
		netlBufOut[i + 5] = netlBufOut[i + 5] | (fld[(i * 4) + 2] << 16);
		netlBufOut[i + 5] = netlBufOut[i + 5] | (fld[(i * 4) + 3] << 24);
	}
	
	tcpSend(&netlBufOut, netlBufOut[0]);
}

// �t�B�[���h����M
void netlRecvField() {
	int i;
	
	// ���쒆�u���b�N���\���ɂ���
	netlEnemyBlockVisible = 0;
	
	// �t�B�[���h���R�s�[
	for(i = 0; i < 55; i++) {
		fld[(i * 4) + 0 + 220] = (netlBufIn[i + 5] & 0x000000FF);
		fld[(i * 4) + 1 + 220] = (netlBufIn[i + 5] & 0x0000FF00) >> 8;
		fld[(i * 4) + 2 + 220] = (netlBufIn[i + 5] & 0x00FF0000) >> 16;
		fld[(i * 4) + 3 + 220] = (netlBufIn[i + 5] & 0xFF000000) >> 24;
	}
	
	// �t�B�[���h�̃u���b�N��������悤�ɂ���
	disableShadowTimer(1);
	
	// NEXT�x������
	ndelay[1] = 1;
	
	// HOLD�g�p�\
	if(netlHoldEnable != 0) dhold[1] = 0;
	
	// ���C����
	netlLines[1] = netlBufIn[4];
	
	if(netlBufIn[3] == 1) {
		// ���C�������̎�
		blockEraseJudge(1);
		stat[1] = 6;
		resetStatc(1);
	} else if(netlBufIn[3] == 2) {
		// �Q�[���I�[�o�[�̎�
		stat[1] = 7;
		resetStatc(1);
	} else {
		// �u���b�N��u�����Ƃ��̌��ʉ�
		if(stat[1] == 6) PlaySE(se_gon);
		else PlaySE(se_kachi);
	}
}

// �u���b�N�������̏���
void netlStatEraseBlock(int player, int *param) {
	// �����̏������̍ŏ��̃t���[���i�܂��u���b�N�͏����Ă��Ȃ��j
	if((statc[player * 10] == 0) && (player == 0)) {
		netlSendField(1);	// �����̃t�B�[���h�𑗐M
	}
	
	// �G�̏�����
	if(player == 1) {
		if(statc[player * 10] != 0) param[0] = 1;	// ���肪�������I���܂ő҂�
	}
}

// �ؒf��
void netlStatDisconnect(int player) {
	printFont(foffset[player], fyoffset[player] + 96, "DISCONNECTED", 3);
	
	if(statc[player * 10 + 0] >= 180) {
		stat[0] = 8;
		stat[1] = 8;
		resetStatc(0);
		resetStatc(1);
		resetField(0);
		resetField(1);
	} else {
		statc[player * 10 + 0]++;
	}
}

// ����
void netlStatWin(int player) {
	// �v���C���ʑ��M
	if((!netlEnemyDisconnect) && (player == 0) && (statc[player * 10] == 0)) {
		netlSendPlayResult();
	}
	if(statc[player * 10] == 0) {
		if(netlWin[player] < 99) netlWin[player]++;
	}
	
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

// ���g���C
void netlStatRetryScreen(int player) {
	int color;
	
	if(player) return;
	
	color = (count % 4 / 2) * 7;
	
	if(netlEnemyDisconnect) statc[player * 10 + 0] = 1;
	
	printFont(foffset[player] + 16, fyoffset[player] + 112 + statc[player * 10 + 0] * 16, "b", color);
	
	if(!netlEnemyDisconnect) {
		printFont(foffset[player] + 24, fyoffset[player] + 112, "RETRY", (statc[player * 10 + 0] == 0) * color);
	}
	printFont(foffset[player] + 24, fyoffset[player] + 128, "END", (statc[player * 10 + 0] == 1) * color);
	
	// �L�[����
	padRepeat2(player);
	
	// ����
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if(getPressState(player, 0) || getPressState(player, 1)) {
		PlaySE(se_move);
		statc[player * 10 + 0] = !statc[player * 10 + 0];
	}
	
	// A�{�^��
	if(getPushState(player, 4)) {
		// RETRY
		if(statc[player * 10 + 0] == 0) {
			PlaySE(se_kettei);
			gameAllInit();
			playerInitial(0);
			playerInitial(1);
			if(netlPlayerType == 0) versusInit(0);
			stat[0] = 3;
			stat[1] = 3;
			
			netlBufOut[0] = 3 * 4;			// �T�C�Y
			netlBufOut[1] = netlEnemyID;	// ���M��ID
			netlBufOut[2] = 9;				// �R�}���h
			tcpSend(&netlBufOut, netlBufOut[0]);
		}
		// END
		else {
			tcpClosesocket();
			flag = 1;
		}
	}
}

// �Q�[���I�[�o�[����
void netlGameOver(int player, int *param) {
	int i, drawflag;
	
	param[0] = 1;
	
	// ���������t���O
	if(stat[1 - player] == 7) drawflag = 1;
	else drawflag = 0;
	
	// �ŏ��̃t���[���̏���
	if(statc[player * 10] == 0) {
		// �����̏�Ԃ𑗐M
		if(!player) {
			netlSendPlayerMove();
			netlSendField(2);
		}
		StopAllBGM();
		onRecord[0] = 0;
		onRecord[1] = 0;
		timeOn[0] = 0;
		timeOn[1] = 0;
		pinch[0] = 0;
		pinch[1] = 0;
		
		if((!drawflag) && (!netlTraining)) {
			stat[1 - player] = 2;
			resetStatc(1 - player);
			netlCustomStatNo[1 - player] = 1;
		}
		
		// �v���C���ʑ��M
		if((!netlEnemyDisconnect) && (player == 0)) {
			netlSendPlayResult();
		}
	}
	
	if(!netlTraining) {
		// LOSE���S
		statc[player * 10 + 1]++;
		statc[player * 10 + 2] = statc[player * 10 + 2] + statc[player * 10 + 1] / 4;
		
		if(statc[player * 10 + 2] > 140) {
			statc[player * 10 + 2] = 140;
			statc[player * 10 + 1] = -20;
		}
		
		ExBltRect(sg_spr, foffset[player] + 8, statc[player * 10 + 2], 184, 24 * (drawflag + 1), 79, 23);
	}
	
	statc[player * 10]++;
	
	// �{�^���ŃX�L�b�v
	if(getPushState(player, 4) && (statc[player * 10] >= 60)) {
		statc[player * 10] = 300;
	}
	// ���̉�ʂ�
	if(statc[player * 10] >= 300) {
		stat[0] = 8;
		resetStatc(0);
		resetField(0);
		
		if(!netlTraining) {
			stat[1] = 8;
			resetStatc(1);
			resetField(1);
		}
	}
}

// �v���C���ʂ𑊎�ɑ��M
void netlSendPlayResult() {
	if(netlTraining) return;
	
	netlBufOut[0] = 5 * 4;			// �T�C�Y
	netlBufOut[1] = netlEnemyID;	// ���M��ID
	netlBufOut[2] = 12;				// �R�}���h
	netlBufOut[3] = netlLines[0];
	netlBufOut[4] = gameTimer[0];
	tcpSend(&netlBufOut, netlBufOut[0]);
}

// ���ʕ\��
void netlResult(int player, int *param) {
	param[0] = 1;
	
	// ����
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", netlLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "TIME");
	getTime(gameTimer[player]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[1], 0);
	
	// �J�E���^����
	statc[player * 10]++;
	
	if(player == 0) {
		if(statc[player * 10] == 1) {
			// BGM�Đ�
			if(bgmtype != 0) {
				bgmlv = 13;
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
		if(netlTraining) {
			StopAllBGM();
			netlTraining = 0;
			gameAllInit();
			playerInitial(0);
			versusInit(0);
			stat[0] = 3;
			stat[1] = 3;
		} else {
			stat[0] = 9;
			stat[1] = 9;
		}
		resetStatc(0);
		resetStatc(1);
	}
}

// �Q�[���I�[�o�[�\��
void netlGameOver2(int player, int *param) {
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
		stat[0] = 2;
		stat[1] = 2;
		netlCustomStatNo[0] = 2;
		netlCustomStatNo[1] = 2;
		resetStatc(0);
		resetStatc(1);
	}
}

// BGM�ǂݍ���
void netlLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(10);
		if(!enable_sysbgm) loadBGM(13);
	}
}

// ���C������
void netlCalcScore(int player, int lines) {
	if(!player) {
		// ���C��������
		netlLines[player] = netlLines[player] + lines;
		
		// ����ɕ�
		if(!netlTraining) {
			netlBufOut[0] = 4 * 4;			// �T�C�Y
			netlBufOut[1] = netlEnemyID;	// ���M��ID
			netlBufOut[2] = 11;				// �R�}���h
			netlBufOut[3] = netlLines[0];	// ���C����
			tcpSend(&netlBufOut, netlBufOut[0]);
		}
	}
}

// �X�R�A�\��
void netlViewScore(int player) {
	int color;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// �c�胉�C��
	printTinyFont(112 + player * 70, 40, "LINES");
	if(player == 0) {
		if(netlLines[player] > netlNormLine) sprintf(string[0], "%d", 0);
		else sprintf(string[0], "%d", netlNormLine - netlLines[player]);
	} else {
		if(netlLines[player] > netlNormLine) sprintf(string[0], "%2d", 0);
		else sprintf(string[0], "%2d", netlNormLine - netlLines[player]);
	}
	printSMALLFont(112 + player * 84, 48, string[0], color);
	
	// �^�C��
	if(player == 0) {
		getTime(gameTimer[player]);
		printBIGFont(112, 216, string[0], color);
	}
	
	// �g���[�j���O���̕\��
	if((netlTraining) && (player == 0) && (onRecord[0])) {
		printTinyFontB(foffset[player] + 15, fyoffset[player] + 216, "PUSH PAUSE TO");
		printTinyFontB(foffset[player] + 15, fyoffset[player] + 223, "EXIT TRAINING");
	}
	
	if(player == 0) {
		// �X�s�[�h
		printTinyFont(142, 153, "SPEED");
		sprintf(string[0], "%d", sp[player]);
		printSMALLFont(142, 161, string[0], color);
		
		sprintf(string[0], "TYPE %d", speedtype[player] + 1);
		printSMALLFont(142, 171, string[0], color);
		
		// wait�l
		ExBltRect(sg_smallfont, 142, 181, 68, 14, 24, 7);	// WAITS
		sprintf(string[0], "%2d %2d\n%2d %2d", wait1[player], wait2[player], wait3[player], waitt[player]);
		printSMALLFont(142, 189, string[0], color);
		
		if(wait4[player] != -1) {
			sprintf(string[0], "%2d", wait4[player]);
			printSMALLFont(142, 207, string[0], color);
		}
		
		if(wait5[player] != -1) {
			sprintf(string[0], "%2d", wait5[player]);
			printSMALLFont(160, 207, string[0], color);
		}
		
		// ARE Force
		if(netlAreUse > -1) {
			printTinyFont(112, 153, "ARE");
			
			if(netlAreUse == 0) sprintf(string[0], "OFF");
			else if(netlAreUse == 1) sprintf(string[0], "ON");
			else sprintf(string[0], "SKIP");
			printSMALLFont(112, 161, string[0], 2);
		}
		
		if(netlTraining) {
			// �g���[�j���O
			printTinyFontB(139, 10, "TRAINING");
		} else if(netlEnemyID != 0) {
			// ���E���h
			sprintf(string[0], "ROUND %d", netlRound);
			printTinyFont(140, 10, string[0]);
		}
	}
	
	if((player == 1) && (netlEnemyDisconnect)) {
		printTinyFont(foffset[player] + 18, fyoffset[player] + 200, "DISCONNECTED");
	}
	
	// ������
	if(netlEnemyID != 0) {
		ExBltRect(sg_smallfont, 112 + player * 82, 135, 93, 14, 14, 7);	// WIN
		if(!player) sprintf(string[0], "%d", netlWin[player]);
		else sprintf(string[0], "%2d", netlWin[player]);
		printSMALLFont(112 + player * 84, 143, string[0], color);
	}
}

// �����Ƒ���̃j�b�N�l�[����\��
void netlViewNickname(int player) {
	ExTextLayerOn(player, foffset[player] + 8, fyoffset[player] + 222);
	ExTextSize(player, 10);
	TextColor(player, 255, 255, 255);
	TextBackColor(player, 64, 64, 64);
	TextOut(player, netlNickname[player]);
}

// �ݒ��ۑ�
void netlSaveConfig() {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 2;
	
	// �ݒ���e
	saveBuf[1] = netlGhost;
	saveBuf[2] = netlSpeed;
	saveBuf[3] = netlSpeedType;
	saveBuf[4] = netlWait1;
	saveBuf[5] = netlWait2;
	saveBuf[6] = netlWait3;
	saveBuf[7] = netlWaitt;
	saveBuf[8] = netlWait4;
	saveBuf[9] = netlWait5;
	saveBuf[10] = netlNormLine;
	saveBuf[11] = netlAreUse;
	saveBuf[12] = netlFastlrmove;
	saveBuf[13] = netlRepeatDelay;
	saveBuf[14] = netlMaxDAS;
	saveBuf[15] = netlSpawnType;
	saveBuf[16] = netlHoldEnable;
	
	// �v���Z�b�g
	saveBuf[21] = netlLastPresetNo;
	for(i = 0; i < 20 * 10; i++) saveBuf[22 + i] = netlPreset[i];
	
	SaveFile("config/NET_LINE_CONFIG.SAV", &saveBuf, 222 * 4);
}

// �ݒ��ǂݍ���
int netlLoadConfig() {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/NET_LINE_CONFIG.SAV", &saveBuf, 222 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 2) return 0;
	
	// �ݒ���e
	netlGhost = saveBuf[1];
	netlSpeed = saveBuf[2];
	netlSpeedType = saveBuf[3];
	netlWait1 = saveBuf[4];
	netlWait2 = saveBuf[5];
	netlWait3 = saveBuf[6];
	netlWaitt = saveBuf[7];
	netlWait4 = saveBuf[8];
	netlWait5 = saveBuf[9];
	netlNormLine = saveBuf[10];
	netlAreUse = saveBuf[11];
	netlFastlrmove = saveBuf[12];
	netlRepeatDelay = saveBuf[13];
	netlMaxDAS = saveBuf[14];
	netlSpawnType = saveBuf[15];
	netlHoldEnable = saveBuf[16];
	
	// �v���Z�b�g
	netlLastPresetNo = saveBuf[21];
	for(i = 0; i < 20 * 10; i++) netlPreset[i] = saveBuf[22 + i];
	
	return 1;
}

// �v���Z�b�g��������
void netlMakeDefaultPreset() {
	int i;
	
	netlLastPresetNo = 0;
	for(i = 0; i < 20 * 10; i++) netlPreset[i] = 0;
}

// �v���Z�b�g��ۑ�
void netlSavePreset(int number) {
	netlPreset[number * 20 + 0] = netlGhost;
	netlPreset[number * 20 + 1] = netlSpeed;
	netlPreset[number * 20 + 2] = netlSpeedType;
	netlPreset[number * 20 + 3] = netlWait1;
	netlPreset[number * 20 + 4] = netlWait2;
	netlPreset[number * 20 + 5] = netlWait3;
	netlPreset[number * 20 + 6] = netlWaitt;
	netlPreset[number * 20 + 7] = netlWait4;
	netlPreset[number * 20 + 8] = netlWait5;
	netlPreset[number * 20 + 9] = netlNormLine;
	netlPreset[number * 20 + 10] = netlAreUse;
	netlPreset[number * 20 + 11] = netlFastlrmove;
	netlPreset[number * 20 + 12] = netlRepeatDelay;
	netlPreset[number * 20 + 13] = netlMaxDAS;
	netlPreset[number * 20 + 14] = netlSpawnType;
	netlPreset[number * 20 + 15] = netlHoldEnable;
}

// �v���Z�b�g��ǂݍ���
void netlLoadPreset(int number) {
	netlGhost = netlPreset[number * 20 + 0];
	netlSpeed = netlPreset[number * 20 + 1];
	netlSpeedType = netlPreset[number * 20 + 2];
	netlWait1 = netlPreset[number * 20 + 3];
	netlWait2 = netlPreset[number * 20 + 4];
	netlWait3 = netlPreset[number * 20 + 5];
	netlWaitt = netlPreset[number * 20 + 6];
	netlWait4 = netlPreset[number * 20 + 7];
	netlWait5 = netlPreset[number * 20 + 8];
	netlNormLine = netlPreset[number * 20 + 9];
	netlAreUse = netlPreset[number * 20 + 10];
	netlFastlrmove = netlPreset[number * 20 + 11];
	netlRepeatDelay = netlPreset[number * 20 + 12];
	netlMaxDAS = netlPreset[number * 20 + 13];
	netlSpawnType = netlPreset[number * 20 + 14];
	netlHoldEnable = netlPreset[number * 20 + 15];
}
