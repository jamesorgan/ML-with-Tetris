//NET-STANDARD
//prefix:nets

int netsModeNo = -1;				// ���[�h�ԍ�
int netsModeVersion = 5;			// Mode Version

int netsLines[2];					// ���C����
int netsTotalAttack[2];				// �G�ɑ���������オ��u���b�N�̐�
int netsGHole[2];					// ����オ��u���b�N�̌��̈ʒu

int netsTSpinFrame[2];				// T-SPIN�\���^�w�{���X�\���̎c�莞��
int netsTSpinLine[2];				// �Ō��T-SPIN���C�������^�w�{���X�����̎��
int netsComboFrame[2];				// �R���{���\���̎c�莞��
int netsB2BFrame[2];				// Back To Back�\���̎c�莞��
int netsAttackGet[2];				// ���������ז��u���b�N��
int netsAttackFrame[2];				// ���������ז��u���b�N���\���̎c�莞��

int netsRound;						// ���E���h
int netsWin[2];						// ��������

int netsServerNo = 0;				// �T�[�o�[�ԍ�

int netsGhost = 1;					// �S�[�X�g�̐ݒ�
int netsTSpin = 3;					// T-SPIN�̎��
int netsEnableCombo = 1;			// �R���{�{�[�i�X�̗L��
int netsEnableB2B = 1;				// Back To Back�̗L���i0=�Ȃ� 1=�ʏ� 2=�w�{���X�̂� 3=T-SPIN�̂݁j
int netsSpeed = 1;					// �������x
int netsSpeedType = 0;				// �X�s�[�h�^�C�v
int netsWait1 = 25;					// ARE
int netsWait2 = 40;					// ���C������
int netsWait3 = 30;					// �Œ莞��
int netsWaitt = 16;					// ������
int netsWait4 = -1;					// �Œ莞�ԁi�ڒ���j
int netsWait5 = -1;					// ARE�i������j
int netsAreUse = -1;				// ARE Force
int netsFastlrmove = -1;			// INIT LR Force
int netsRepeatDelay = -1;			// Repeat Delay
int netsMaxDAS = -1;				// Disable Max DAS
int netsSpawnType = -1;				// SPAWN Y TYPE Force
int netsHoldEnable = -1;			// Enable Hold
int netsHoleShiftRate = 30;			// Hole change rate(%)
int netsSousai = 1;					// �ז��u���b�N���E

int netsPreset[20 * 10];			// �v���Z�b�g
int netsLastPresetNo = 0;			// �Ō�ɑI�������v���Z�b�g�ԍ�

int netsPlayerType;					// 0�Ȃ�z�X�g���A1�Ȃ�Q�X�g��
int netsGameStart;					// �Q�[�����Ȃ�1
int netsTraining;					// �g���[�j���O���Ȃ�1

int netsCustomStatNo[2];			// stat[player] = 2�̂Ƃ��̏����̔ԍ�

int netsLastBlk[2];					// �O�̃t���[���̃u���b�N�̎��
int netsLastBx[2];					// �O�̃t���[���̃u���b�N��X���W
int netsLastBy[2];					// �O�̃t���[���̃u���b�N��Y���W
int netsLastRt[2];					// �O�̃t���[���̃u���b�N�̌���
int netsLastNDelay[2];				// �O�̃t���[����NEXT�x�����
int netsLastUpLines[2];				// �O�̃t���[���̂���オ�萔

int netsReceiveRuleNameOK;			// ���[��������M�����t���O
int netsReceiveRuleConfigOK;		// ���[���ݒ����M�����t���O
int netsReceiveNextListOK;			// NEXT�u���b�N����M�����t���O
int netsReceiveModeConfigOK;		// ���[�h�ݒ����M�����t���O

int netsEnemyID;					// �ΐ푊��ID
int netsEnemyNotFound;				// �ΐ푊�肪������Ȃ��Ƃ��A�ēx�ΐ푊�����������܂ł̃t���[����
int netsEnemyDisconnect;			// �ΐ푊�肪�ؒf������1�ɂȂ�
int netsEnemyRulePluginMissing;		// �ΐ푊��̃��[���v���O�C���������瑤�ɖ����Ƃ���1�ɂȂ�
int netsEnemyReady;					// �ΐ푊��̏���������1�ɂȂ�
int netsEnemyBlockVisible;			// �ΐ푊��̃u���b�N���\������Ă��邩�ǂ���
int netsEnemyRealUpLines;			// �ΐ푊��̂���オ��u���b�N��

int netsServerVersion;				// �T�[�o�[�o�[�W����
int netsClientCount;				// �ڑ��Ґ�
int netsMaxClient;					// �ő�ڑ��Ґ�
int netsSameModeClientCount[3];		// �������[�h�ƃo�[�W�������g�p���Ă���v���C���[�̐�
int netsCountUpdateFrame;			// ���Ƀv���C���[�����X�V����܂ł̃t���[����

int netsRuleConfigPlayer[26];		// ���[���ݒ�i�����j
int netsRuleConfigEnemy[26];		// ���[���ݒ�i�G�j

str* netsNickname[2];				// �����ƓG�̃j�b�N�l�[��

int netsBufIn[16384];				// ��M�p�o�b�t�@
int netsBufOut[16384];				// ���M�p�o�b�t�@

// �C�x���g����
void netsPluginEvent(int player, int event, int *param) {
	// ���[�h���Ⴄ�Ȃ�߂�i���[�h��o�^����^�C�~���O�ȊO�̏ꍇ�j
	if((event != 0) && (gameMode[player] != netsModeNo)) return;
	
	if(event == 0) {
		netsModeNo = addModePlugin("NET-STANDARD");	// ���[�h��o�^����
		netsNickname[0] = new(64);
		netsNickname[1] = new(64);
		LeftStr(networkNickName, 63, netsNickname[0]);
		StrCpy(netsNickname[1], "");
	} else if(event == 1) {
		netsRecvData();	// �f�[�^��M
	} else if(event == 5) {
		netsReady(player, param);	// Ready
	} else if(event == 6) {
		netsStatMove(player, param);	// �u���b�N�ړ�����
	} else if(event == 10) {
		netsARE(player);	// ARE���̏���
	} else if(event == 11) {
		netsStatEraseBlock(player, param);	// �u���b�N�������̏���
	} else if(event == 12) {
		netsCalcScore(player, param[0]);	// ���C������
	} else if(event == 15) {
		netsViewScore(player);	// �X�R�A�\��
	} else if(event == 17) {
		netsSetting(player, param);	// �ݒ���
	} else if(event == 18) {
		netsPlayerInitial(player);	// ����������
	} else if(event == 20) {
		netsGameOver(player, param);	// �Q�[���I�[�o�[����
	} else if(event == 21) {
		netsResult(player, param);	// ���ʕ\��
	} else if(event == 22) {
		netsGameOver2(player, param);	// �Q�[���I�[�o�[�\��
	} else if(event == 27) {
		netsIncrementTime(player);	// �e�t���[���̏I���̏���
	} else if(event == 38) {
		if(player == 0) PlayBGM();	// BGM�Đ�
	} else if(event == 68) {
		// stat[player] = 2�̂Ƃ��̏���
		if(netsCustomStatNo[player] == 0) netsStatDisconnect(player);	// �ؒf
		if(netsCustomStatNo[player] == 1) netsStatWin(player);	// ����
		if(netsCustomStatNo[player] == 2) netsStatRetryScreen(player);	// ���g���C
	} else if(event == 69) {
		netsUpLineProc(player, param);	// ����オ��
	}
}

// �f�[�^��M
void netsRecvData() {
	int size, result, id_from, command, temp;
	
	// �ڑ����Ă��Ȃ��Ȃ�߂�
	if(!tcpIsConnect()) return;
	
	// �V�����f�[�^�������Ȃ�߂�
	if(!tcpIsReadReady()) return;
	
	// �ŏ���4�o�C�g�������ׂ�i�L���[���珜���͂��Ȃ��j
	result = tcpRecvPeek(&netsBufIn, 4);
	if(result < 1) return;
	
	// �ǂݍ��ރT�C�Y�����߂�
	size = netsBufIn[0];
	if(size < 1) return;
	
	// �f�[�^���S�ė��Ă��邩�ǂ����m�F
	if(tcpReceiveLength() < size) return;
	
	// �f�[�^��S�ēǂݍ���
	result = tcpRecv(&netsBufIn, size);
	if(result < 1) return;
	
	// �ǂݍ��񂾃f�[�^�ɉ����ď���������
	id_from = netsBufIn[1];
	command = netsBufIn[2];
	
	// �T�[�o�[����̃��b�Z�[�W�̏ꍇ
	if(id_from == 0) {
		// ���擾
		if(command == 0) {
			netsServerVersion = netsBufIn[3];
			netsClientCount = netsBufIn[4];
			if(netsServerVersion >= 2) netsMaxClient = netsBufIn[7];
		}
		// �N�����ڑ�
		else if(command == 1) {
			netsClientCount = netsBufIn[4];
			netsCountUpdateFrame = 0;
		}
		// �N�����ؒf
		else if(command == 2) {
			netsClientCount = netsBufIn[4];
			netsCountUpdateFrame = 0;
			
			// ���肪�ؒf����
			if(netsBufIn[3] == netsEnemyID) {
				netsEnemyID = 0;
				netsEnemyDisconnect = 1;
			}
		}
		// ���肪��������
		else if(command == 3) {
			temp = netsBufIn[3];
			netsBufOut[0] = 3 * 4;		// �T�C�Y
			netsBufOut[1] = temp;		// ���M��ID
			netsBufOut[2] = 0;			// �R�}���h�i�ΐ�v���j
			tcpSend(&netsBufOut, netsBufOut[0]);
		}
		// ���肪������Ȃ�
		else if(command == 4) {
			netsEnemyNotFound = 180;
		}
		// �v���C���[�����
		else if(command == 5) {
			netsSameModeClientCount[0] = netsBufIn[3];
			netsSameModeClientCount[1] = netsBufIn[4];
			netsSameModeClientCount[2] = netsBufIn[5];
		}
	}
	// ���̃v���C���[����̃��b�Z�[�W�̏ꍇ
	else {
		// �ΐ�v��
		if(command == 0) {
			// ���肪���܂��Ă��Ȃ��Ƃ�
			if(netsEnemyID == 0) {
				PlaySE(se_lvstop);
				netsEnemyID = id_from;			// ����ID�����߂�
				netsBufOut[0] = 3 * 4;			// �T�C�Y
				netsBufOut[1] = netsEnemyID;	// ���M��ID
				netsBufOut[2] = 1;				// �R�}���h�i�����j
				tcpSend(&netsBufOut, netsBufOut[0]);
			}
			// ���肪�������܂��Ă���Ƃ�
			else {
				netsBufOut[0] = 3 * 4;			// �T�C�Y
				netsBufOut[1] = id_from;		// ���M��ID
				netsBufOut[2] = 2;				// �R�}���h�i���ہj
				tcpSend(&netsBufOut, netsBufOut[0]);
			}
		}
		// �ΐ�̏���������
		else if(command == 1) {
			if(netsEnemyID == 0) {
				PlaySE(se_lvstop);
				netsEnemyID = id_from;			// ����ID�����߂�
			}
		}
		// �ΐ�����ۂ��ꂽ
		else if(command == 2) {
			if(netsEnemyID == 0) {
				netsEnemyNotFound = 180;
			}
		}
		// ���[��������M
		else if(command == 3) {
			if(id_from == netsEnemyID) {
				netsRecvEnemyRuleName();
			}
		}
		// ���[���ݒ����M
		else if(command == 4) {
			if(id_from == netsEnemyID) {
				netsRecvEnemyRuleConfig();
			}
		}
		// NEXT�u���b�N����M
		else if(command == 5) {
			if(id_from == netsEnemyID) {
				netsRecvEnemyNextList();
			}
		}
		// ����̏�������
		else if(command == 6) {
			if(id_from == netsEnemyID) {
				netsEnemyReady = 1;
			}
		}
		// �G�̈ړ�
		else if(command == 7) {
			if(id_from == netsEnemyID) {
				netsRecvEnemyMove();
			}
		}
		// �t�B�[���h
		else if(command == 8) {
			if(id_from == netsEnemyID) {
				netsRecvField();
			}
		}
		// ���g���C
		else if(command == 9) {
			if(id_from == netsEnemyID) {
				PlaySE(se_kettei);
				StopAllBGM();
				gameAllInit();
				playerInitial(0);
				playerInitial(1);
				if(netsPlayerType == 0) versusInit(0);
				stat[0] = 3;
				stat[1] = 3;
			}
		}
		// ����̃��[�h�ݒ����M
		else if(command == 10) {
			if(id_from == netsEnemyID) {
				netsRecvModeConfig();
			}
		}
		// ������܂�H�����
		else if(command == 11) {
			if(id_from == netsEnemyID) {
				upLines[0] = netsBufIn[3];
			}
		}
		// ����̃v���C����
		else if(command == 12) {
			if(id_from == netsEnemyID) {
				netsLines[1] = netsBufIn[3];
				netsTotalAttack[1] = netsBufIn[4];
				gameTimer[1] = netsBufIn[5];
			}
		}
	}
}

// �T�[�o�[�Ɏ����̃o�[�W�������𑗐M
void netsSendVersionDataToServer() {
	int i, strbuf[8];
	
	// ��{���
	netsBufOut[0] = 13 * 4;				// �T�C�Y
	netsBufOut[1] = 0;					// ���M��ID
	netsBufOut[2] = 1;					// �R�}���h
	netsBufOut[3] = engineVer;			// �Q�[���G���W���̃o�[�W����
	netsBufOut[4] = netsModeVersion;	// ���[�h�̃o�[�W����
	
	// ���[�h��
	for(i = 0; i < 8; i++) strbuf[i] = 0;
	StrCpy(&strbuf, plugin_name_mode[gameMode[0]]);
	for(i = 0; i < 8; i++) netsBufOut[5 + i] = strbuf[i];
	
	// ���M
	tcpSend(&netsBufOut, netsBufOut[0]);
}

// �����̃��[�����𑗐M
void netsSendPlayerRuleName() {
	int i, strbuf[8];
	
	// ��{���
	netsBufOut[0] = 11 * 4;			// �T�C�Y
	netsBufOut[1] = netsEnemyID;	// ���M��ID
	netsBufOut[2] = 3;				// �R�}���h
	
	// ���[����
	for(i = 0; i < 8; i++) strbuf[i] = 0;
	StrCpy(&strbuf, plugin_name_rule[rots[0]]);
	for(i = 0; i < 8; i++) netsBufOut[3 + i] = strbuf[i];
	
	// ���M
	tcpSend(&netsBufOut, netsBufOut[0]);
}

// ����̃��[��������M
void netsRecvEnemyRuleName() {
	int i, strbuf[8], temp;
	
	for(i = 0; i < 8; i++) strbuf[i] = netsBufIn[3 + i];
	StrCpy(string[1], &strbuf);
	temp = findRulePlugin(string[1]);
	if(temp != -1) {
		rots[1] = temp;
		netsEnemyRulePluginMissing = 0;
	} else {
		rots[1] = rots[0];
		netsEnemyRulePluginMissing = 1;
	}
	
	netsReceiveRuleNameOK = 1;
}

// �����̃��[���ݒ��netsRuleConfigPlayer�ɃR�s�[����
void netsBackupPlayerRuleConfig() {
	int i;
	
	if(rotlimit[0] == 0) rotlimit[0] = 128;
	if(movelimit[0] == 0) movelimit[0] = 128;
	
	netsRuleConfigPlayer[0] = kicktype[0];
	netsRuleConfigPlayer[1] = lockreset[0];
	netsRuleConfigPlayer[2] = rotlimit[0];
	netsRuleConfigPlayer[3] = movelimit[0];
	netsRuleConfigPlayer[4] = blockgraphics[0];
	netsRuleConfigPlayer[5] = are[0];
	netsRuleConfigPlayer[6] = lock_up[0];
	netsRuleConfigPlayer[7] = lock_down[0];
	netsRuleConfigPlayer[8] = rot_reverse[0];
	netsRuleConfigPlayer[9] = softspeed[0];
	netsRuleConfigPlayer[10] = max_waitt[0];
	netsRuleConfigPlayer[11] = fastlrmove[0];
	netsRuleConfigPlayer[12] = oblk_bg[0];
	for(i = 0; i < 7; i++) netsRuleConfigPlayer[13 + i] = blockcolor[i];
	netsRuleConfigPlayer[20] = initial_rotate[0];
	netsRuleConfigPlayer[21] = initial_hold[0];
	netsRuleConfigPlayer[22] = enable_wallkick[0];
	netsRuleConfigPlayer[23] = self_lock_sound[0];
	netsRuleConfigPlayer[24] = lockflash[0];
	netsRuleConfigPlayer[25] = RepeatDelay[0];
}

// netsRuleConfigEnemy���瑊��̃��[���ݒ�𔽉f������
void netsApplyEnemyRuleConfig() {
	int i;
	
	kicktype[1] = netsRuleConfigEnemy[0];
	lockreset[1] = netsRuleConfigEnemy[1];
	rotlimit[1] = netsRuleConfigEnemy[2];
	movelimit[1] = netsRuleConfigEnemy[3];
	blockgraphics[1] = netsRuleConfigEnemy[4];
	are[1] = netsRuleConfigEnemy[5];
	lock_up[1] = netsRuleConfigEnemy[6];
	lock_down[1] = netsRuleConfigEnemy[7];
	rot_reverse[1] = netsRuleConfigEnemy[8];
	softspeed[1] = netsRuleConfigEnemy[9];
	max_waitt[1] = netsRuleConfigEnemy[10];
	fastlrmove[1] = netsRuleConfigEnemy[11];
	oblk_bg[1] = netsRuleConfigEnemy[12];
	for(i = 0; i < 7; i++) blockcolor[i + 7] = netsRuleConfigEnemy[13 + i];
	initial_rotate[1] = netsRuleConfigEnemy[20];
	initial_hold[1] = netsRuleConfigEnemy[21];
	enable_wallkick[1] = netsRuleConfigEnemy[22];
	self_lock_sound[1] = netsRuleConfigEnemy[23];
	lockflash[1] = netsRuleConfigEnemy[24];
	RepeatDelay[1] = netsRuleConfigEnemy[25];
}

// �����̃��[���ݒ�𑗐M
void netsSendPlayerRuleConfig() {
	int i, strbuf[16];
	
	// ��{���
	netsBufOut[0] = 45 * 4;			// �T�C�Y
	netsBufOut[1] = netsEnemyID;	// ���M��ID
	netsBufOut[2] = 4;				// �R�}���h
	
	// ���[���ݒ�
	netsBackupPlayerRuleConfig();
	for(i = 0; i < 26; i++) netsBufOut[3 + i] = netsRuleConfigPlayer[i];
	
	// �j�b�N�l�[��
	for(i = 0; i < 16; i++) strbuf[i] = 0;
	if(networkUseNick) StrCpy(&strbuf, netsNickname[0]);
	for(i = 0; i < 16; i++) netsBufOut[29 + i] = strbuf[i];
	
	// ���M
	tcpSend(&netsBufOut, netsBufOut[0]);
}

// ����̃��[���ݒ����M
void netsRecvEnemyRuleConfig() {
	int i, strbuf[16];
	
	// ���[���ݒ�
	for(i = 0; i < 26; i++) netsRuleConfigEnemy[i] = netsBufIn[3 + i];
	
	// �j�b�N�l�[��
	if(networkUseNick) {
		for(i = 0; i < 16; i++) strbuf[i] = netsBufIn[29 + i];
		StrCpy(netsNickname[1], &strbuf);
		netsViewNickname(0);
		netsViewNickname(1);
	}
	
	netsReceiveRuleConfigOK = 1;
}

// ������NEXT�u���b�N�𑗐M
void netsSendPlayerNextList() {
	int i, j, temp;
	
	// ��{���
	netsBufOut[0] = 179 * 4;		// �T�C�Y
	netsBufOut[1] = netsEnemyID;	// ���M��ID
	netsBufOut[2] = 5;				// �R�}���h
	netsBufOut[3] = nextc_max[0];	// NEXT�ő吔
	
	// NEXT�u���b�N
	for(i = 0; i < 175; i++) {
		temp = 0;
		for(j = 0; j < 8; j++) {
			temp = temp | (nextb[(i << 3) + j] << (j * 4));
		}
		netsBufOut[i + 4] = temp;
	}
	
	// ���M
	tcpSend(&netsBufOut, netsBufOut[0]);
}

// �����NEXT�u���b�N����M
void netsRecvEnemyNextList() {
	int i, j, temp;
	
	nextc_max[0] = netsBufIn[3];	// NEXT�ő吔
	if(nextc_max[0] == 0) nextc_max[0] = 1400;
	
	for(i = 0; i < 175; i++) {
		for(j = 0; j < 8; j++) {
			nextb[(i << 3) + j] = ((netsBufIn[i + 4]) >> (j * 4)) & 15;
		}
	}
	netsCopyNextList();
	
	netsReceiveNextListOK = 1;
}

// 1P��NEXT��2P�ɃR�s�[
void netsCopyNextList() {
	int i;
	for(i = 0; i < 1400; i++) nextb[i + 1400] = nextb[i];
	nextc[1] = nextc[0];
	nextc_max[1] = nextc_max[0];
}

// �����̃��[�h�ݒ�𑗐M
void netsSendModeConfig() {
	netsBufOut[0] = 25 * 4;				// �T�C�Y
	netsBufOut[1] = netsEnemyID;		// ���M��ID
	netsBufOut[2] = 10;					// �R�}���h
	netsBufOut[3] = netsGhost;			// �S�[�X�g�̗L��
	netsBufOut[4] = netsTSpin;			// T-SPIN�̎��
	netsBufOut[5] = netsEnableCombo;	// �R���{�{�[�i�X�̗L��
	netsBufOut[6] = netsEnableB2B;		// Back To Back�̗L��
	netsBufOut[7] = netsSpeed;			// �������x
	netsBufOut[8] = netsSpeedType;		// �X�s�[�h�^�C�v
	netsBufOut[9] = netsWait1;			// ARE
	netsBufOut[10] = netsWait2;			// ���C������
	netsBufOut[11] = netsWait3;			// �Œ莞��
	netsBufOut[12] = netsWaitt;			// ������
	netsBufOut[13] = netsWait4;			// �Œ莞�ԁi�ڒ���j
	netsBufOut[14] = netsWait5;			// ARE�i������j
	netsBufOut[15] = randseed[0];		// ������
	netsBufOut[16] = firstseed[0];		// ������
	netsBufOut[17] = netsAreUse;		// ARE Force
	netsBufOut[18] = netsFastlrmove;	// INIT LR Force
	netsBufOut[19] = netsRepeatDelay;	// Repeat Delay
	netsBufOut[20] = netsMaxDAS;		// Disable Max DAS
	netsBufOut[21] = netsSpawnType;		// SPAWN Y TYPE Force
	netsBufOut[22] = netsHoldEnable;	// Enable Hold
	netsBufOut[23] = netsHoleShiftRate;	// Hole change rate(%)
	netsBufOut[24] = netsSousai;		// �ז��u���b�N���E
	
	tcpSend(&netsBufOut, netsBufOut[0]);
}

// ����̃��[�h�ݒ����M
void netsRecvModeConfig() {
	netsGhost = netsBufIn[3];
	netsTSpin = netsBufIn[4];
	netsEnableCombo = netsBufIn[5];
	netsEnableB2B = netsBufIn[6];
	netsSpeed = netsBufIn[7];
	netsSpeedType = netsBufIn[8];
	netsWait1 = netsBufIn[9];
	netsWait2 = netsBufIn[10];
	netsWait3 = netsBufIn[11];
	netsWaitt = netsBufIn[12];
	netsWait4 = netsBufIn[13];
	netsWait5 = netsBufIn[14];
	randseed[0] = netsBufIn[15];
	firstseed[0] = netsBufIn[16];
	netsAreUse = netsBufIn[17];
	netsFastlrmove = netsBufIn[18];
	netsRepeatDelay = netsBufIn[19];
	netsMaxDAS = netsBufIn[20];
	netsSpawnType = netsBufIn[21];
	netsHoldEnable = netsBufIn[22];
	netsHoleShiftRate = netsBufIn[23];
	netsSousai = netsBufIn[24];
	
	randseed[1] = randseed[0];
	firstseed[1] = firstseed[0];
	
	netsReceiveModeConfigOK = 1;
}

// �e��ݒ�𔽉f������
void netsApplyModeConfig(int player) {
	ghost[player] = netsGhost;
	tspin_type[player] = netsTSpin;
	enable_combo[player] = netsEnableCombo;
	b_to_b_type[player] = netsEnableB2B;
	sp[player] = netsSpeed;
	speedtype[player] = netsSpeedType;
	wait1[player] = netsWait1;
	wait2[player] = netsWait2;
	wait3[player] = netsWait3;
	waitt[player] = netsWaitt;
	wait4[player] = netsWait4;
	wait5[player] = netsWait5;
	
	if(netsAreUse > -1) are[player] = netsAreUse;
	if(netsFastlrmove > -1) fastlrmove[player] = netsFastlrmove;
	if(netsRepeatDelay > -1) RepeatDelay[player] = netsRepeatDelay;
	if(netsMaxDAS > -1) max_waitt[player] = 99;
	if(netsSpawnType > -1) spawntype[player] = netsSpawnType;
	if(netsHoldEnable > -1) {
		if(netsHoldEnable == 0) dhold[player] = 2;
		else dhold[player] = 0;
	}
}

// �ݒ���
void netsSetting(int player, int *param) {
	int page;
	
	// BGM�͍ŏ��ɓǂݍ���ł���
	netsLoadBGM();
	
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
		else if(page == 0) page = netsMenuServerSelect();
		else if(page == 1) page = netsMenuServerConnect();
		else if(page == 2) page = netsMenuSelectPlayType();
		else if(page == 3) page = netsMenuGameOptions();
		else return;
	}
}

// �T�[�o�[�I�����
int netsMenuServerSelect() {
	int i, move;
	
	// �ϐ��̏�����
	netsPlayerType = 0;
	netsGameStart = 0;
	netsTraining = 0;
	netsReceiveRuleNameOK = 0;
	netsEnemyID = 0;
	netsEnemyNotFound = 0;
	netsEnemyDisconnect = 0;
	netsEnemyRulePluginMissing = 0;
	netsServerVersion = -1;
	netsClientCount = -1;
	netsMaxClient = -1;
	netsSameModeClientCount[0] = -1;
	netsSameModeClientCount[1] = -1;
	netsSameModeClientCount[2] = -1;
	netsCountUpdateFrame = 0;
	netsRound = 0;
	netsWin[0] = 0;
	netsWin[1] = 0;
	
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
			printSMALLFont(8, 24 + i * 9, string[0], 7 * (netsServerNo == i));
		}
		
		// �J�[�\���ړ�
		padRepeat2(0);
		
		move = 0;
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
			move = getPressState(0, 1) - getPressState(0, 0);
		
		if(move) {
			PlaySE(se_move);
			netsServerNo = netsServerNo + move;
			if(netsServerNo < 0) netsServerNo = 9;
			if(netsServerNo > 9) netsServerNo = 0;
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
int netsMenuServerConnect() {
	int cursor;
	cursor = 0;
	
	// �ڑ�
	tcpConnect(networkServerName[netsServerNo], networkServerPort[netsServerNo]);
	
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
				tcpConnect(networkServerName[netsServerNo], networkServerPort[netsServerNo]);
			}
		}
		// ����
		else if(tcpIsConnect()) {
			// �o�[�W�������𑗐M
			netsSendVersionDataToServer();
			
			// �I����v������
			netsBufOut[0] = 3 * 4;		// �T�C�Y
			netsBufOut[1] = 0;			// ���M��ID
			netsBufOut[2] = 0;			// �R�}���h
			tcpSend(&netsBufOut, netsBufOut[0]);
			
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
int netsMenuSelectPlayType() {
	int i, move;
	
	// ���C�����[�v
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "SELECT PLAY TYPE", 4);
		printFontGrid(1, 27, "A:OK B:BACK", 6);
		
		// �J�[�\���\��
		printFontGrid(1, 3 + netsPlayerType, "b", 7);
		
		// ���j���[�\��
		printFontGrid(2, 3, "PLAY AS HOST",  7 * (netsPlayerType == 0));
		printFontGrid(2, 4, "PLAY AS GUEST", 7 * (netsPlayerType == 1));
		
		// �I���
		if(netsServerVersion != -1) {
			sprintf(string[0], "SERVER VERSION:%d", netsServerVersion);
			printFontGrid(1, 22, string[0], 6);
		}
		if((netsMaxClient > 0) && (netsServerVersion >= 2)) {
			sprintf(string[0], "MAX PLAYER:%d", netsMaxClient);
			printFontGrid(1, 23, string[0], 6);
		}
		if(netsClientCount != -1) {
			sprintf(string[0], "ALL OTHER PLAYERS IN SERVER:%d", netsClientCount - 1);
			printFontGrid(1, 24, string[0], 6);
		}
		if((netsSameModeClientCount[0] != -1) && (netsServerVersion >= 2)) {
			sprintf(string[0], "SAME MODE PLAYERS:%d/%d/%d", netsSameModeClientCount[0], netsSameModeClientCount[1], netsSameModeClientCount[2]);
			printFontGrid(1, 25, string[0], 6);
		}
		
		// �J�[�\���ړ�
		padRepeat2(0);
		
		move = 0;
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
			move = getPressState(0, 1) - getPressState(0, 0);
		
		if(move) {
			PlaySE(se_move);
			netsPlayerType = netsPlayerType + move;
			if(netsPlayerType < 0) netsPlayerType = 1;
			if(netsPlayerType > 1) netsPlayerType = 0;
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
			
			if(!netsPlayerType) {
				// �z�X�g
				return 3;
			} else {
				// �Q�X�g�Ȃ̂ő����T��
				netsBufOut[0] = 3 * 4;		// �T�C�Y
				netsBufOut[1] = 0;			// ���M��ID
				netsBufOut[2] = 3;			// �R�}���h
				tcpSend(&netsBufOut, netsBufOut[0]);
				return 4;
			}
		}
		
		// �v���C���[���擾
		if(netsServerVersion >= 2) {
			if(netsCountUpdateFrame <= 0) {
				netsCountUpdateFrame = 180;
				netsBufOut[0] = 3 * 4;		// �T�C�Y
				netsBufOut[1] = 0;			// ���M��ID
				netsBufOut[2] = 4;			// �R�}���h
				tcpSend(&netsBufOut, netsBufOut[0]);
			} else {
				netsCountUpdateFrame--;
			}
		}
	}
}

// �Q�[���ݒ�
int netsMenuGameOptions() {
	int cursor, move;
	cursor = 0;
	
	// �ݒ�ǂݍ���
	if(netsLoadConfig() == 0) {
		netsMakeDefaultPreset();
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
		printFontGrid(2, 4, "T-SPIN",       (cursor == 1) * 7);
		printFontGrid(2, 5, "COMBO",        (cursor == 2) * 7);
		printFontGrid(2, 6, "BACK TO BACK", (cursor == 3) * 7);
		printFontGrid(2, 7, "SPEED",        (cursor == 4) * 7);
		printFontGrid(2, 8, "SPEED TYPE",   (cursor == 5) * 7);
		if(!english) printFontGrid(2, 9, "SYUTUGEN", (cursor == 6) * 7);
		else printFontGrid(2, 9, "ARE", (cursor == 6) * 7);
		if(!english) printFontGrid(2, 10, "SYOUKYO", (cursor == 7) * 7);
		else printFontGrid(2, 10, "LINE DELAY", (cursor == 7) * 7);
		if(!english) printFontGrid(2, 11, "SETTYAKU", (cursor == 8) * 7);
		else printFontGrid(2, 11, "LOCK DELAY", (cursor == 8) * 7);
		if(!english) printFontGrid(2, 12, "YOKOTAME", (cursor == 9) * 7);
		else printFontGrid(2, 12, "DAS", (cursor == 9) * 7);
		if(!english) printFontGrid(2, 13, "SETTYAKU2", (cursor == 10) * 7);
		else printFontGrid(2, 13, "LOCK DELAY2", (cursor == 10) * 7);
		if(!english) printFontGrid(2, 14, "SYUTUGEN2", (cursor == 11) * 7);
		else printFontGrid(2, 14, "ARE2", (cursor == 11) * 7);
		printFontGrid(2, 15, "FORCE ARE", (cursor == 12) * 7);
		printFontGrid(2, 16, "FORCE INIT LR MOVE", (cursor == 13) * 7);
		printFontGrid(2, 17, "FORCE REPEAT DELAY", (cursor == 14) * 7);
		if(!english) printFontGrid(2, 18, "FORCE MAX YOKOTAME", (cursor == 15) * 7);
		else printFontGrid(2, 18, "FORCE MAX DAS", (cursor == 15) * 7);
		printFontGrid(2, 19, "FORCE SPAWN Y TYPE", (cursor == 16) * 7);
		printFontGrid(2, 20, "FORCE HOLD", (cursor == 17) * 7);
		printFontGrid(2, 21, "HOLE CHANGE CHANCE", (cursor == 18) * 7);
		if(!english) printFontGrid(2, 22, "SOUSAI", (cursor == 19) * 7);
		else printFontGrid(2, 22, "GARBAGE COUNTERING", (cursor == 19) * 7);
		printFontGrid(2, 23, "[SAVE PRESET]", (cursor == 20) * 7);
		printFontGrid(2, 24, "[LOAD PRESET]", (cursor == 21) * 7);
		
		// �ݒ�l�\��
		if(!netsGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], (cursor == 0) * 7);
		
		if(netsTSpin == 0) sprintf(string[0], "OFF");
		else if(netsTSpin == 1) sprintf(string[0], "LINE CLEAR");
		else if(netsTSpin == 2) sprintf(string[0], "IMMOBILE");
		else if(netsTSpin == 3) sprintf(string[0], "3-CORNER");
		else sprintf(string[0], "3-CORNER NO KICK");
		printFontGrid(22, 4, string[0], (cursor == 1) * 7);
		
		if(!netsEnableCombo) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 5, string[0], (cursor == 2) * 7);
		
		if(netsEnableB2B == 0) sprintf(string[0], "OFF");
		else if(netsEnableB2B == 1) sprintf(string[0], "ON");
		else if(netsEnableB2B == 2) sprintf(string[0], "HEBORIS ONLY");
		else sprintf(string[0], "T-SPIN ONLY");
		printFontGrid(22, 6, string[0], (cursor == 3) * 7);
		
		sprintf(string[0], "%d", netsSpeed);
		printFontGrid(22, 7, string[0], (cursor == 4) * 7);
		
		if(netsSpeedType == 0) sprintf(string[0], "1/60");
		else if(netsSpeedType == 1) sprintf(string[0], "FRAMES PER ROW");
		else sprintf(string[0], "1/256");
		printFontGrid(22, 8, string[0], (cursor == 5) * 7);
		
		sprintf(string[0], "%d", netsWait1);
		printFontGrid(22, 9, string[0], (cursor == 6) * 7);
		
		sprintf(string[0], "%d", netsWait2);
		printFontGrid(22, 10, string[0], (cursor == 7) * 7);
		
		sprintf(string[0], "%d", netsWait3);
		printFontGrid(22, 11, string[0], (cursor == 8) * 7);
		
		sprintf(string[0], "%d", netsWaitt);
		printFontGrid(22, 12, string[0], (cursor == 9) * 7);
		
		if(netsWait4 == -1) sprintf(string[0], "NO USE");
		else sprintf(string[0], "%d", netsWait4);
		printFontGrid(22, 13, string[0], (cursor == 10) * 7);
		
		if(netsWait5 == -1) sprintf(string[0], "NO USE");
		else sprintf(string[0], "%d", netsWait5);
		printFontGrid(22, 14, string[0], (cursor == 11) * 7);
		
		if(netsAreUse == -1) sprintf(string[0], "PLAYER CHOICE");
		else if(netsAreUse == 0) sprintf(string[0], "OFF");
		else if(netsAreUse == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "ON (WITH SKIP)");
		printFontGrid(22, 15, string[0], (cursor == 12) * 7);
		
		if(netsFastlrmove == -1) sprintf(string[0], "PLAYER CHOICE");
		else if(netsFastlrmove == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 16, string[0], (cursor == 13) * 7);
		
		if(netsRepeatDelay == -1) sprintf(string[0], "PLAYER CHOICE");
		else if(netsRepeatDelay == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "%d", netsRepeatDelay);
		printFontGrid(22, 17, string[0], (cursor == 14) * 7);
		
		if(netsMaxDAS == -1) sprintf(string[0], "PLAYER CHOICE");
		else sprintf(string[0], "FORCE DISABLE");
		printFontGrid(22, 18, string[0], (cursor == 15) * 7);
		
		if(netsSpawnType == -1) sprintf(string[0], "PLAYER CHOICE");
		else if(netsSpawnType == 0) sprintf(string[0], "UNDER THE FRAME");
		else sprintf(string[0], "ABOVE THE FRAME");
		printFontGrid(22, 19, string[0], (cursor == 16) * 7);
		
		if(netsHoldEnable == -1) sprintf(string[0], "PLAYER CHOICE");
		else if(netsHoldEnable == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 20, string[0], (cursor == 17) * 7);
		
		sprintf(string[0], "%d%%", netsHoleShiftRate);
		printFontGrid(22, 21, string[0], (cursor == 18) * 7);
		
		if(!netsSousai) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 22, string[0], (cursor == 19) * 7);
		
		sprintf(string[0], "PRESET NO.%d", netsLastPresetNo + 1);
		printFontGrid(22, 23, string[0], (cursor >= 20) * 7);
		
		// �J�[�\���ړ�
		padRepeat2(0);
		
		move = 0;
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
			move = getPressState(0, 1) - getPressState(0, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 21;
			if(cursor > 21) cursor = 0;
		}
		
		// �l��ύX
		padRepeat(0);
		
		move = 0;
		if((mpc[0] == 1) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6))
			move = getPressState(0, 3) - getPressState(0, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) netsGhost = !netsGhost;
			if(cursor == 1) {
				netsTSpin = netsTSpin + move;
				if(netsTSpin < 0) netsTSpin = 4;
				if(netsTSpin > 4) netsTSpin = 0;
			}
			if(cursor == 2) netsEnableCombo = !netsEnableCombo;
			if(cursor == 3) {
				netsEnableB2B = netsEnableB2B + move;
				if(netsEnableB2B < 0) netsEnableB2B = 3;
				if(netsEnableB2B > 3) netsEnableB2B = 0;
			}
			if(cursor == 4) {
				netsSpeed = netsSpeed + move;
				if(netsSpeed < 1) netsSpeed = 5120;
				if(netsSpeed > 5120) netsSpeed = 1;
			}
			if(cursor == 5) {
				netsSpeedType = netsSpeedType + move;
				if(netsSpeedType < 0) netsSpeedType = 2;
				if(netsSpeedType > 2) netsSpeedType = 0;
			}
			if(cursor == 6) {
				netsWait1 = netsWait1 + move;
				if(netsWait1 < 0) netsWait1 = 99;
				if(netsWait1 > 99) netsWait1 = 0;
			}
			if(cursor == 7) {
				netsWait2 = netsWait2 + move;
				if(netsWait2 < 0) netsWait2 = 99;
				if(netsWait2 > 99) netsWait2 = 0;
			}
			if(cursor == 8) {
				netsWait3 = netsWait3 + move;
				if(netsWait3 < 0) netsWait3 = 98;
				if(netsWait3 > 98) netsWait3 = 0;
			}
			if(cursor == 9) {
				netsWaitt = netsWaitt + move;
				if(netsWaitt < 0) netsWaitt = 99;
				if(netsWaitt > 99) netsWaitt = 0;
			}
			if(cursor == 10) {
				netsWait4 = netsWait4 + move;
				if(netsWait4 < -1) netsWait4 = 98;
				if(netsWait4 > 98) netsWait4 = -1;
			}
			if(cursor == 11) {
				netsWait5 = netsWait5 + move;
				if(netsWait5 < -1) netsWait5 = 99;
				if(netsWait5 > 99) netsWait5 = -1;
			}
			if(cursor == 12) {
				netsAreUse = netsAreUse + move;
				if(netsAreUse < -1) netsAreUse = 2;
				if(netsAreUse > 2) netsAreUse = -1;
			}
			if(cursor == 13) {
				netsFastlrmove = netsFastlrmove + move;
				if(netsFastlrmove < -1) netsFastlrmove = 1;
				if(netsFastlrmove > 1) netsFastlrmove = -1;
			}
			if(cursor == 14) {
				netsRepeatDelay = netsRepeatDelay + move;
				if(netsRepeatDelay < -1) netsRepeatDelay = 99;
				if(netsRepeatDelay > 99) netsRepeatDelay = -1;
			}
			if(cursor == 15) {
				netsMaxDAS = netsMaxDAS + move;
				if(netsMaxDAS < -1) netsMaxDAS = 0;
				if(netsMaxDAS > 0) netsMaxDAS = -1;
			}
			if(cursor == 16) {
				netsSpawnType = netsSpawnType + move;
				if(netsSpawnType < -1) netsSpawnType = 1;
				if(netsSpawnType > 1) netsSpawnType = -1;
			}
			if(cursor == 17) {
				netsHoldEnable = netsHoldEnable + move;
				if(netsHoldEnable < -1) netsHoldEnable = 1;
				if(netsHoldEnable > 1) netsHoldEnable = -1;
			}
			if(cursor == 18) {
				netsHoleShiftRate = netsHoleShiftRate + move;
				if(netsHoleShiftRate < 0) netsHoleShiftRate = 100;
				if(netsHoleShiftRate > 100) netsHoleShiftRate = 0;
			}
			if(cursor == 19) netsSousai = !netsSousai;
			if(cursor >= 20) {
				netsLastPresetNo = netsLastPresetNo + move;
				if(netsLastPresetNo < 0) netsLastPresetNo = 9;
				if(netsLastPresetNo > 9) netsLastPresetNo = 0;
			}
		}
		
		// ����
		if(getPushState(0, 4)) {
			PlaySE(se_kettei);
			
			if(cursor == 20) {
				netsSavePreset(netsLastPresetNo);
				netsSaveConfig();
			} else if(cursor == 21) {
				netsLoadPreset(netsLastPresetNo);
			} else {
				netsSaveConfig();
				
				// ����҂���ԂɂȂ�
				netsBufOut[0] = 4 * 4;		// �T�C�Y
				netsBufOut[1] = 0;			// ���M��ID
				netsBufOut[2] = 2;			// �R�}���h
				netsBufOut[3] = 1;			// ���
				tcpSend(&netsBufOut, netsBufOut[0]);
				
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
void netsPlayerInitial(int player) {
	backno = 20;								// �w�i�ύX
	setFieldPosition(player, 2);				// �t�B�[���h�ʒu�ݒ�
	blkshadow_direction[player] = 1 - player;	// �u���b�N�̉e
	hnext[player] = 0;							// NEXT�͊J�n�܂Ō����Ȃ�
	bgmlv = 10;									// BGM�ԍ��ݒ�
	
	netsLines[player] = 0;
	netsTotalAttack[player] = 0;
	netsGHole[player] = 0;
	
	netsTSpinFrame[player] = 0;
	netsTSpinLine[player] = 0;
	netsComboFrame[player] = 0;
	netsB2BFrame[player] = 0;
	netsAttackGet[player] = 0;
	netsAttackFrame[player] = 0;
	
	netsLastBlk[player] = 0;
	netsLastBx[player] = 0;
	netsLastBy[player] = 0;
	netsLastRt[player] = 0;
	netsLastNDelay[player] = 0;
	netsLastUpLines[player] = 0;
	
	netsCustomStatNo[player] = 0;
	
	netsGameStart = 0;
	netsTraining = 0;
	netsEnemyReady = 0;
	netsEnemyBlockVisible = 0;
	netsReceiveRuleConfigOK = 0;
	netsReceiveNextListOK = 0;
	netsReceiveModeConfigOK = 0;
	netsEnemyRealUpLines = 0;
}

// Ready���
void netsReady(int player, int *param) {
	// ����҂����̃v���C���[���\��
	if((netsEnemyID == 0) && (player == 1)) {
		param[0] = 1;
		
		sprintf(string[0], "ALL:%d", netsClientCount - 1);
		printFont(foffset[player] + 16, fyoffset[player] + 108, string[0], 6);
		sprintf(string[0], "SAME MODE\n%d/%d/%d", netsSameModeClientCount[0], netsSameModeClientCount[1], netsSameModeClientCount[2]);
		printFont(foffset[player] + 16, fyoffset[player] + 124, string[0], 6);
	}
	// ����҂����̃��j���[
	else if((netsEnemyID == 0) && (player == 0) && (!netsTraining)) {
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
				netsTraining = 1;
				hnext[player] = dispnext;
				netsApplyModeConfig(0);
			}
			// EXIT
			else {
				tcpClosesocket();
				flag = 1;
			}
		}
	}
	// ���茈���A�Q�[���J�n�O
	else if((!netsGameStart) && (!netsTraining)) {
		param[0] = 1;
		
		if(player == 0) {
			// �����̃��[�������M
			if(statc[player * 10 + 1] == 0) {
				netsSendPlayerRuleName();
				
				// �����̏�Ԃ�ύX
				netsBufOut[0] = 4 * 4;		// �T�C�Y
				netsBufOut[1] = 0;			// ���M��ID
				netsBufOut[2] = 2;			// �R�}���h
				netsBufOut[3] = 2;			// ���
				tcpSend(&netsBufOut, netsBufOut[0]);
				
				statc[player * 10 + 1] = 1;
			}
			// ����̃��[������M
			else if(statc[player * 10 + 1] == 1) {
				if(netsReceiveRuleNameOK) {
					playerInitial(1);			// �����������
					stat[1] = 3;
					statc[player * 10 + 1] = 2;
				}
			}
			// �����̃��[���ݒ著�M
			else if(statc[player * 10 + 1] == 2) {
				netsSendPlayerRuleConfig();	// �����̃��[���ݒ�𑗐M����
				statc[player * 10 + 1] = 3;
			}
			// �������z�X�g�Ȃ�NEXT�u���b�N�𑗐M����
			else if(statc[player * 10 + 1] == 3) {
				if(!netsPlayerType) {
					netsCopyNextList();			// ������NEXT�𑊎�ɃR�s�[
					netsSendPlayerNextList();	// NEXT�u���b�N�𑗐M����
					netsReceiveNextListOK = 1;	// NEXT�u���b�N�͎󂯎���������ɂ���
				}
				statc[player * 10 + 1] = 4;
			}
			// �������z�X�g�Ȃ烂�[�h�ݒ�𑗐M����
			else if(statc[player * 10 + 1] == 4) {
				if(!netsPlayerType) {
					netsSendModeConfig();			// ���[�h�ݒ�𑗐M����
					netsReceiveModeConfigOK = 1;	// ���[�h�ݒ�͎󂯎���������ɂ���
				}
				statc[player * 10 + 1] = 5;
			}
			// ���[���ݒ��NEXT�u���b�N�ƃ��[�h�ݒ���󂯎�����珀������
			else if(statc[player * 10 + 1] == 5) {
				if((netsReceiveRuleConfigOK) && (netsReceiveNextListOK) && (netsReceiveModeConfigOK)) {
					netsApplyEnemyRuleConfig();		// �G�̃��[����K�p
					netsApplyModeConfig(0);			// ���[�h�ݒ��K�p
					netsApplyModeConfig(1);
					
					netsBufOut[0] = 3 * 4;			// �T�C�Y
					netsBufOut[1] = netsEnemyID;	// ���M��ID
					netsBufOut[2] = 6;				// �R�}���h
					tcpSend(&netsBufOut, netsBufOut[0]);
					
					statc[player * 10 + 1] = 6;
				}
			}
			// ����̏���������������n�߂�
			else if(statc[player * 10 + 1] == 6) {
				if(netsEnemyReady) {
					netsGameStart = 1;
					resetStatc(0);
					resetStatc(1);
					setNextBlockColor(0, 1);
					setNextBlockColor(1, 1);
					hnext[0] = dispnext;
					hnext[1] = dispnext;
					netsGHole[0] = GiziRand(0, 10);
					netsRound++;
				}
			}
		}
	}
}

// �u���b�N�ړ�����
void netsStatMove(int player, int *param) {
	int bottom;
	
	if(player == 1) {
		// �G
		param[0] = 1;
		
		if((!netsEnemyRulePluginMissing) && (netsEnemyBlockVisible)) {
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
void netsIncrementTime(int player) {
	if(player == 0) {
		// �����̈ړ����
		if((stat[0] == 4) && (bactivetime[player] != 0)) {
			if((blk[0] != netsLastBlk[0]) || (bx[0] != netsLastBx[0]) || (by[0] != netsLastBy[0]) || (rt[0] != netsLastRt[0]) || 
			   (ndelay[0] != netsLastNDelay[0]) || (upLines[0] != netsLastUpLines[0]))
			{
				netsLastBlk[0] = blk[0];
				netsLastBx[0] = bx[0];
				netsLastBy[0] = by[0];
				netsLastRt[0] = rt[0];
				netsLastNDelay[0] = ndelay[0];
				netsLastUpLines[0] = upLines[0];
				netsSendPlayerMove();
			}
		}
		
		if(onRecord[0]) {
			if(netsEnemyDisconnect) {
				// �ؒf
				stat[0] = 2;
				stat[1] = 2;
				netsCustomStatNo[0] = 0;
				netsCustomStatNo[1] = 0;
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
			}
		}
		
		// ���肪���Ȃ��Ƃ�
		if((netsEnemyID == 0) && (!netsEnemyDisconnect)) {
			// �������Q�X�g�̂Ƃ��͑����T��
			if((netsEnemyNotFound != 0) && (netsPlayerType == 1)) {
				netsEnemyNotFound--;
				
				if(netsEnemyNotFound <= 0) {
					netsBufOut[0] = 3 * 4;		// �T�C�Y
					netsBufOut[1] = 0;			// ���M��ID
					netsBufOut[2] = 3;			// �R�}���h
					tcpSend(&netsBufOut, netsBufOut[0]);
				}
			}
			
			// �v���C���[���擾
			if(netsServerVersion >= 2) {
				if(netsCountUpdateFrame <= 0) {
					netsCountUpdateFrame = 180;
					netsBufOut[0] = 3 * 4;		// �T�C�Y
					netsBufOut[1] = 0;			// ���M��ID
					netsBufOut[2] = 4;			// �R�}���h
					tcpSend(&netsBufOut, netsBufOut[0]);
				} else {
					netsCountUpdateFrame--;
				}
			}
		}
		
		// �g���[�j���O���ɑ���o��
		if((netsTraining) && (netsEnemyID != 0)) {
			StopAllBGM();
			gameAllInit();
			playerInitial(0);
			playerInitial(1);
			if(netsPlayerType == 0) versusInit(0);
			stat[0] = 3;
			stat[1] = 3;
		}
		
		// �|�[�Y�{�^���Ńg���[�j���O�I��
		if((netsTraining) && (onRecord[0])) {
			if(IsPushKey(pause_key[0]) | getJoyPushState(0, joy_pause_key[0])) {
				StopAllBGM();
				stat[0] = 7;
				resetStatc(0);
			}
		}
	}
}

// �����̈ړ����
void netsSendPlayerMove() {
	if(netsTraining) return;
	
	netsBufOut[0] = 13 * 4;			// �T�C�Y
	netsBufOut[1] = netsEnemyID;	// ���M��ID
	netsBufOut[2] = 7;				// �R�}���h
	
	netsBufOut[3] = blk[0];
	netsBufOut[4] = bx[0];
	netsBufOut[5] = by[0];
	netsBufOut[6] = rt[0];
	netsBufOut[7] = nextc[0];
	netsBufOut[8] = ndelay[0];
	netsBufOut[9] = hold[0];
	netsBufOut[10] = dhold[0];
	netsBufOut[11] = hold_count[0];
	netsBufOut[12] = upLines[0];
	
	tcpSend(&netsBufOut, netsBufOut[0]);
}

// �G�̈ړ��𔽉f������
void netsRecvEnemyMove() {
	int i;
	
	blk[1] = netsBufIn[3];
	bx[1] = netsBufIn[4];
	by[1] = netsBufIn[5];
	rt[1] = netsBufIn[6];
	nextc[1] = netsBufIn[7];
	ndelay[1] = netsBufIn[8];
	hold[1] = netsBufIn[9];
	dhold[1] = netsBufIn[10];
	hold_count[1] = netsBufIn[11];
	upLines[1] = netsBufIn[12];
	netsEnemyRealUpLines = upLines[1];
	
	// �u���b�N�̐F��ݒ�
	for(i = 0; i < 4; i++) {
		current_color[i + 4] = blockcolor[blk[1] + 7];
		current_color_m[i + 4] = blockcolor[blk[1] + 7];
		hold_color[i + 4] = blockcolor[hold[1] + 7];
	}
	setNextBlockColor(1, 1);
	
	// ���ʉ��Đ�
	if(blk[1] != netsLastBlk[1]) {
		// �V�����u���b�N�o����
		netsLastBlk[1] = blk[1];
		if(hnext[1]) PlaySE(se_blockse[getNextBlock(1, 0)]);
	} else {
		// �ړ�
		if(bx[1] != netsLastBx[1]) {
			netsLastBx[1] = bx[1];
			if(move_sound) PlaySE(se_move);
		}
		// ��]
		if(rt[1] != netsLastRt[1]) {
			netsLastRt[1] = rt[1];
			if(rotate_sound) PlaySE(se_rotate);
		}
	}
	
	if(onRecord[0]) {
		stat[1] = 4;
		resetStatc(1);
		netsEnemyBlockVisible = 1;
	}
}

// ARE���̏���
void netsARE(int player) {
	if(player == 0) {
		// ������ARE���̏���
		if((!statc[player * 10 + 1]) || (upLines[player] != 0)) {
			if(upLines[player] == 0) {
				if(!statc[player * 10 + 2]) {
					netsSendField(0);	// �����̃t�B�[���h�𑗐M�i�u���b�N�ݒu���t���j
				} else {
					netsSendField(4);	// �����̃t�B�[���h�𑗐M�i�u���b�N�ݒu���Ȃ��j
				}
				statc[player * 10 + 1] = 1;
			} else {
				netsSendField(3);
				statc[player * 10 + 2] = 1;
			}
		}
	} else {
		// �����ARE���̏���
		stat[1] = 4;
		resetStatc(1);
	}
}

// �t�B�[���h�𑗐M
void netsSendField(int eraseflag) {
	int i;
	
	if(netsTraining) return;
	
	netsBufOut[0] = 68 * 4;					// �T�C�Y
	netsBufOut[1] = netsEnemyID;			// ���M��ID
	netsBufOut[2] = 8;						// �R�}���h
	netsBufOut[3] = eraseflag;				// ���C�������^�Q�[���I�[�o�[�^����オ��t���O
	netsBufOut[4] = upLines[0];				// �����̂���オ�萔
	netsBufOut[5] = hebocombo[0];			// �w�{���X����̃R���{���ǂ���
	netsBufOut[6] = combo[0];				// �R���{��
	netsBufOut[7] = b_to_b_count[0];		// B2B�t���O
	netsBufOut[8] = tspin_flag[0];			// T-SPIN�t���O
	netsBufOut[9] = netsLines[0];			// ���C����
	netsBufOut[10] = netsTotalAttack[0];	// �U����
	netsBufOut[11] = netsAttackGet[0];		// ���������ז��u���b�N��
	netsBufOut[12] = netsAttackFrame[0];	// ���������ז��u���b�N���\���̎c�莞��
	
	// �t�B�[���h
	for(i = 0; i < 55; i++) {
		netsBufOut[i + 13] = (fld[(i * 4) + 0]);
		netsBufOut[i + 13] = netsBufOut[i + 13] | (fld[(i * 4) + 1] << 8);
		netsBufOut[i + 13] = netsBufOut[i + 13] | (fld[(i * 4) + 2] << 16);
		netsBufOut[i + 13] = netsBufOut[i + 13] | (fld[(i * 4) + 3] << 24);
	}
	
	tcpSend(&netsBufOut, netsBufOut[0]);
}

// �t�B�[���h����M
void netsRecvField() {
	int i;
	
	// ���쒆�u���b�N���\���ɂ���
	netsEnemyBlockVisible = 0;
	
	// �t�B�[���h���R�s�[
	for(i = 0; i < 55; i++) {
		fld[(i * 4) + 0 + 220] = (netsBufIn[i + 13] & 0x000000FF);
		fld[(i * 4) + 1 + 220] = (netsBufIn[i + 13] & 0x0000FF00) >> 8;
		fld[(i * 4) + 2 + 220] = (netsBufIn[i + 13] & 0x00FF0000) >> 16;
		fld[(i * 4) + 3 + 220] = (netsBufIn[i + 13] & 0xFF000000) >> 24;
	}
	
	// �t�B�[���h�̃u���b�N��������悤�ɂ���
	disableShadowTimer(1);
	
	// NEXT�x������
	ndelay[1] = 1;
	
	// HOLD�g�p�\
	if(netsHoldEnable != 0) dhold[1] = 0;
	
	// ����オ�萔�Ȃ�
	upLines[1] = netsBufIn[4];
	netsEnemyRealUpLines = upLines[1];
	hebocombo[1] = netsBufIn[5];
	combo[1] = netsBufIn[6];
	b_to_b_count[1] = netsBufIn[7];
	tspin_flag[1] = netsBufIn[8];
	netsLines[1] = netsBufIn[9];
	netsTotalAttack[1] = netsBufIn[10];
	netsAttackGet[1] = netsBufIn[11];
	netsAttackFrame[1] = netsBufIn[12];
	
	if(netsBufIn[3] == 1) {
		// ���C�������̎�
		blockEraseJudge(1);
		stat[1] = 6;
		resetStatc(1);
	} else if(netsBufIn[3] == 2) {
		// �Q�[���I�[�o�[�̎�
		stat[1] = 7;
		resetStatc(1);
	} else if(netsBufIn[3] == 3) {
		// ����オ�艹
		PlaySE(se_up);
	} else if(netsBufIn[3] == 0) {
		// �u���b�N��u�����Ƃ��̌��ʉ�
		if(stat[1] == 6) PlaySE(se_gon);
		else PlaySE(se_kachi);
	}
}

// �u���b�N�������̏���
void netsStatEraseBlock(int player, int *param) {
	// �����̏������̍ŏ��̃t���[���i�܂��u���b�N�͏����Ă��Ȃ��j
	if((statc[player * 10] == 0) && (player == 0)) {
		netsSendField(1);	// �����̃t�B�[���h�𑗐M
	}
	
	// �G�̏�����
	if(player == 1) {
		if(statc[player * 10] != 0) param[0] = 1;	// ���肪�������I���܂ő҂�
	}
}

// �ؒf��
void netsStatDisconnect(int player) {
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
void netsStatWin(int player) {
	// �v���C���ʑ��M
	if((!netsEnemyDisconnect) && (player == 0) && (statc[player * 10] == 0)) {
		netsSendPlayResult();
	}
	if(statc[player * 10] == 0) {
		if(netsWin[player] < 99) netsWin[player]++;
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
void netsStatRetryScreen(int player) {
	int color;
	
	if(player) return;
	
	color = (count % 4 / 2) * 7;
	
	if(netsEnemyDisconnect) statc[player * 10 + 0] = 1;
	
	printFont(foffset[player] + 16, fyoffset[player] + 112 + statc[player * 10 + 0] * 16, "b", color);
	
	if(!netsEnemyDisconnect) {
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
			if(netsPlayerType == 0) versusInit(0);
			stat[0] = 3;
			stat[1] = 3;
			
			netsBufOut[0] = 3 * 4;			// �T�C�Y
			netsBufOut[1] = netsEnemyID;	// ���M��ID
			netsBufOut[2] = 9;				// �R�}���h
			tcpSend(&netsBufOut, netsBufOut[0]);
		}
		// END
		else {
			tcpClosesocket();
			flag = 1;
		}
	}
}

// �Q�[���I�[�o�[����
void netsGameOver(int player, int *param) {
	int i, drawflag;
	
	param[0] = 1;
	
	// ���������t���O
	if(stat[1 - player] == 7) drawflag = 1;
	else drawflag = 0;
	
	// �ŏ��̃t���[���̏���
	if(statc[player * 10] == 0) {
		// �����̏�Ԃ𑗐M
		if(player == 0) {
			netsSendPlayerMove();
			netsSendField(2);
		}
		StopAllBGM();
		onRecord[0] = 0;
		onRecord[1] = 0;
		timeOn[0] = 0;
		timeOn[1] = 0;
		pinch[0] = 0;
		pinch[1] = 0;
		
		if((!drawflag) && (!netsTraining)) {
			stat[1 - player] = 2;
			resetStatc(1 - player);
			netsCustomStatNo[1 - player] = 1;
		}
		
		// �v���C���ʑ��M
		if((!netsEnemyDisconnect) && (player == 0)) {
			netsSendPlayResult();
		}
	}
	
	if(!netsTraining) {
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
		
		if(!netsTraining) {
			stat[1] = 8;
			resetStatc(1);
			resetField(1);
		}
	}
}

// �v���C���ʂ𑊎�ɑ��M
void netsSendPlayResult() {
	if(netsTraining) return;
	
	netsBufOut[0] = 6 * 4;			// �T�C�Y
	netsBufOut[1] = netsEnemyID;	// ���M��ID
	netsBufOut[2] = 12;				// �R�}���h
	netsBufOut[3] = netsLines[0];
	netsBufOut[4] = netsTotalAttack[0];
	netsBufOut[5] = gameTimer[0];
	tcpSend(&netsBufOut, netsBufOut[0]);
}

// ���ʕ\��
void netsResult(int player, int *param) {
	param[0] = 1;
	
	// ����
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LINES");
	sprintf(string[0], "%13d", netsLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "TOTAL ATTACK");
	sprintf(string[0], "%13d", netsTotalAttack[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "TIME");
	getTime(gameTimer[player]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[1], 0);
	
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
		if(netsTraining) {
			StopAllBGM();
			netsTraining = 0;
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
void netsGameOver2(int player, int *param) {
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
		netsCustomStatNo[0] = 2;
		netsCustomStatNo[1] = 2;
		resetStatc(0);
		resetStatc(1);
	}
}

// BGM�ǂݍ���
void netsLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(10);
		if(!enable_sysbgm) loadBGM(13);
	}
}

// ���C������
void netsCalcScore(int player, int lines) {
	int bo;
	
	// T-SPIN��
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		netsTSpinFrame[player] = 60;
		netsTSpinLine[player] = lines;
		
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
			netsTSpinFrame[player] = 60;
			netsTSpinLine[player] = lines;
			bo = 4;
		}
	}
	
	// B2B�{�[�i�X�i+1�j
	if(b_to_b_count[player] >= 2) {
		bo = bo + 1;
		netsB2BFrame[player] = 60;
	} else {
		netsB2BFrame[player] = 0;
	}
	
	// �R���{�{�[�i�X
	if(combo[player] >= 2) {
		if(combo[player] >= 12) bo = bo + 5;
		else if(combo[player] >= 9) bo = bo + 4;
		else if(combo[player] >= 7) bo = bo + 3;
		else if(combo[player] >= 5) bo = bo + 2;
		else if(combo[player] >= 3) bo = bo + 1;
		
		netsComboFrame[player] = 60;
	}
	
	// �S�����{�[�i�X
	if(isBravo(player)) {
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		bo = bo * 2;
	}
	
	if(player == 0) {
		if(netsSousai) {
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
		
		// ������܃u���b�N���𑊎�ɕ�
		if(!netsTraining) {
			netsBufOut[0] = 4 * 4;					// �T�C�Y
			netsBufOut[1] = netsEnemyID;			// ���M��ID
			netsBufOut[2] = 11;						// �R�}���h
			netsBufOut[3] = upLines[1 - player];	// ������܃u���b�N��
			tcpSend(&netsBufOut, netsBufOut[0]);
		}
	}
	
	// �U��������
	netsTotalAttack[player] = netsTotalAttack[player] + bo;
	
	// ���C��������
	netsLines[player] = netsLines[player] + lines;
	
	// ���������ז��u���b�N��
	if(bo > 0) {
		netsAttackGet[player] = bo;
		netsAttackFrame[player] = 120;
	}
}

// ����オ��
void netsUpLineProc(int player, int *param) {
	int i, temp;
	
	if(!player) {
		// ���̈ʒu��ς���
		i = GiziRand(player, 100);
		if(i < netsHoleShiftRate) {
			temp = netsGHole[player];
			
			do {
				netsGHole[player] = GiziRand(player, 10);
			} while(netsGHole[player] == temp);
		}
		
		// ����オ��u���b�N�쐬
		for(i = 0; i < 10; i++) fldu[i + player * 220] = (i != netsGHole[player]);
	} else {
		param[0] = 1;
	}
}

// �X�R�A�\��
void netsViewScore(int player) {
	int color, temp;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// ���C����
	printTinyFont(112 + player * 70, 40, "LINES");
	if(player == 0) {
		sprintf(string[0], "%d", netsLines[player]);
	} else {
		sprintf(string[0], "%4d", netsLines[player]);
	}
	printSMALLFont(112 + player * 72, 48, string[0], color);
	
	// �U����
	printTinyFont(112 + player * 65, 58, "ATTACK");
	if(player == 0) {
		sprintf(string[0], "%d", netsTotalAttack[player]);
	} else {
		sprintf(string[0], "%4d", netsTotalAttack[player]);
	}
	printSMALLFont(112 + player * 72, 66, string[0], color);
	
	// ���������ז��u���b�N��
	if(netsAttackFrame[player] > 0) {
		netsAttackFrame[player]--;
		if(player == 0) {
			sprintf(string[0], "%d", netsAttackGet[player]);
		} else {
			sprintf(string[0], "%4d", netsAttackGet[player]);
		}
		printSMALLFont(112 + player * 72, 75, string[0], (count % 4 / 2) * (1 + (b_to_b_count[player] != 0)));
	}
	
	// �^�C��
	if(player == 0) {
		getTime(gameTimer[player]);
		printBIGFont(112, 216, string[0], color);
	}
	
	// T-SPIN
	if(netsTSpinFrame[player] > 0) {
		netsTSpinFrame[player]--;
		
		if(netsTSpinLine[player] == 1)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN SINGLE");
		else if(netsTSpinLine[player] == 2)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN DOUBLE");
		else if(netsTSpinLine[player] == 3)
			printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN TRIPLE");
		else if(netsTSpinLine[player] == 4)
			printTinyFont(foffset[player] + 30, fyoffset[player] + 208, "HEBORIS");
	}
	
	// BACK TO BACK
	if(netsB2BFrame[player] > 0) {
		netsB2BFrame[player]--;
		printTinyFont(foffset[player] + 18, fyoffset[player] + 200, "BACK TO BACK");
	}
	// COMBO
	else if((netsComboFrame[player] > 0) && (combo[player] >= 2)) {
		netsComboFrame[player]--;
		sprintf(string[0], "COMBO %d", combo[player] - 1);
		printTinyFont(foffset[player] + 30, fyoffset[player] + 200, string[0]);
	}
	
	// ����オ�萔
	if(player == 0) temp = upLines[0];
	else temp = netsEnemyRealUpLines;
	
	if(temp) {
		sprintf(string[0], "%d LINE UP", temp);
		printTinyFontB(foffset[player] + 25, fyoffset[player] + 216, string[0]);
	}
	
	// �g���[�j���O���̕\��
	if((netsTraining) && (temp == 0) && (player == 0) && (onRecord[0])) {
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
		if(netsAreUse > -1) {
			printTinyFont(112, 153, "ARE");
			
			if(netsAreUse == 0) sprintf(string[0], "OFF");
			else if(netsAreUse == 1) sprintf(string[0], "ON");
			else sprintf(string[0], "SKIP");
			printSMALLFont(112, 161, string[0], 2);
		}
		
		if(netsTraining) {
			// �g���[�j���O
			printTinyFontB(139, 10, "TRAINING");
		} else if(netsEnemyID != 0) {
			// ���E���h
			sprintf(string[0], "ROUND %d", netsRound);
			printTinyFont(140, 10, string[0]);
		}
	}
	
	if((player == 1) && (netsEnemyDisconnect)) {
		printTinyFont(foffset[player] + 18, fyoffset[player] + 200, "DISCONNECTED");
	}
	
	// ������
	if(netsEnemyID != 0) {
		ExBltRect(sg_smallfont, 112 + player * 82, 135, 93, 14, 14, 7);	// WIN
		if(!player) sprintf(string[0], "%d", netsWin[player]);
		else sprintf(string[0], "%2d", netsWin[player]);
		printSMALLFont(112 + player * 84, 143, string[0], color);
	}
}

// �����Ƒ���̃j�b�N�l�[����\��
void netsViewNickname(int player) {
	ExTextLayerOn(player, foffset[player] + 8, fyoffset[player] + 222);
	ExTextSize(player, 10);
	TextColor(player, 255, 255, 255);
	TextBackColor(player, 64, 64, 64);
	TextOut(player, netsNickname[player]);
}

// �ݒ��ۑ�
void netsSaveConfig() {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 2;
	
	// �ݒ���e
	saveBuf[1] = netsGhost;
	saveBuf[2] = netsTSpin;
	saveBuf[3] = netsEnableCombo;
	saveBuf[4] = netsEnableB2B;
	saveBuf[5] = netsSpeed;
	saveBuf[6] = netsSpeedType;
	saveBuf[7] = netsWait1;
	saveBuf[8] = netsWait2;
	saveBuf[9] = netsWait3;
	saveBuf[10] = netsWaitt;
	saveBuf[11] = netsWait4;
	saveBuf[12] = netsWait5;
	saveBuf[13] = netsAreUse;
	saveBuf[14] = netsFastlrmove;
	saveBuf[15] = netsRepeatDelay;
	saveBuf[16] = netsMaxDAS;
	saveBuf[17] = netsSpawnType;
	saveBuf[18] = netsHoldEnable;
	saveBuf[19] = netsHoleShiftRate;
	saveBuf[20] = netsSousai;
	
	// �v���Z�b�g
	saveBuf[21] = netsLastPresetNo;
	for(i = 0; i < 20 * 10; i++) saveBuf[22 + i] = netsPreset[i];
	
	SaveFile("config/NET_STANDARD_CONFIG.SAV", &saveBuf, 222 * 4);
}

// �ݒ��ǂݍ���
int netsLoadConfig() {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/NET_STANDARD_CONFIG.SAV", &saveBuf, 222 * 4);
	
	// �w�b�_�����������Ȃ�I��
	if(saveBuf[0] != 2) return 0;
	
	// �ݒ���e
	netsGhost = saveBuf[1];
	netsTSpin = saveBuf[2];
	netsEnableCombo = saveBuf[3];
	netsEnableB2B = saveBuf[4];
	netsSpeed = saveBuf[5];
	netsSpeedType = saveBuf[6];
	netsWait1 = saveBuf[7];
	netsWait2 = saveBuf[8];
	netsWait3 = saveBuf[9];
	netsWaitt = saveBuf[10];
	netsWait4 = saveBuf[11];
	netsWait5 = saveBuf[12];
	netsAreUse = saveBuf[13];
	netsFastlrmove = saveBuf[14];
	netsRepeatDelay = saveBuf[15];
	netsMaxDAS = saveBuf[16];
	netsSpawnType = saveBuf[17];
	netsHoldEnable = saveBuf[18];
	netsHoleShiftRate = saveBuf[19];
	netsSousai = saveBuf[20];
	
	// �v���Z�b�g
	netsLastPresetNo = saveBuf[21];
	for(i = 0; i < 20 * 10; i++) netsPreset[i] = saveBuf[22 + i];
	
	return 1;
}

// �v���Z�b�g��������
void netsMakeDefaultPreset() {
	int i;
	
	netsLastPresetNo = 0;
	for(i = 0; i < 20 * 10; i++) netsPreset[i] = 0;
}

// �v���Z�b�g��ۑ�
void netsSavePreset(int number) {
	netsPreset[number * 20 + 0] = netsGhost;
	netsPreset[number * 20 + 1] = netsTSpin;
	netsPreset[number * 20 + 2] = netsEnableCombo;
	netsPreset[number * 20 + 3] = netsEnableB2B;
	netsPreset[number * 20 + 4] = netsSpeed;
	netsPreset[number * 20 + 5] = netsSpeedType;
	netsPreset[number * 20 + 6] = netsWait1;
	netsPreset[number * 20 + 7] = netsWait2;
	netsPreset[number * 20 + 8] = netsWait3;
	netsPreset[number * 20 + 9] = netsWaitt;
	netsPreset[number * 20 + 10] = netsWait4;
	netsPreset[number * 20 + 11] = netsWait5;
	netsPreset[number * 20 + 12] = netsAreUse;
	netsPreset[number * 20 + 13] = netsFastlrmove;
	netsPreset[number * 20 + 14] = netsRepeatDelay;
	netsPreset[number * 20 + 15] = netsMaxDAS;
	netsPreset[number * 20 + 16] = netsSpawnType;
	netsPreset[number * 20 + 17] = netsHoldEnable;
	netsPreset[number * 20 + 18] = netsHoleShiftRate;
	netsPreset[number * 20 + 19] = netsSousai;
}

// �v���Z�b�g��ǂݍ���
void netsLoadPreset(int number) {
	netsGhost = netsPreset[number * 20 + 0];
	netsTSpin = netsPreset[number * 20 + 1];
	netsEnableCombo = netsPreset[number * 20 + 2];
	netsEnableB2B = netsPreset[number * 20 + 3];
	netsSpeed = netsPreset[number * 20 + 4];
	netsSpeedType = netsPreset[number * 20 + 5];
	netsWait1 = netsPreset[number * 20 + 6];
	netsWait2 = netsPreset[number * 20 + 7];
	netsWait3 = netsPreset[number * 20 + 8];
	netsWaitt = netsPreset[number * 20 + 9];
	netsWait4 = netsPreset[number * 20 + 10];
	netsWait5 = netsPreset[number * 20 + 11];
	netsAreUse = netsPreset[number * 20 + 12];
	netsFastlrmove = netsPreset[number * 20 + 13];
	netsRepeatDelay = netsPreset[number * 20 + 14];
	netsMaxDAS = netsPreset[number * 20 + 15];
	netsSpawnType = netsPreset[number * 20 + 16];
	netsHoldEnable = netsPreset[number * 20 + 17];
	netsHoleShiftRate = netsPreset[number * 20 + 18];
	netsSousai = netsPreset[number * 20 + 19];
}
