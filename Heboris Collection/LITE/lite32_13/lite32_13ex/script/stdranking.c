//������������������������������������������������������������������������������
//  STANDARD���[�h�̃����L���O
//������������������������������������������������������������������������������

// �����L���O������
void stdRankingInit() {
	int i;
	
	for(i = 0; i < (5 * 10 * 4); i++) {
		StrCpy(std_rkname[i], "NOP");
		std_rkscore[i] = 0;
		std_rklines[i] = 0;
		std_rktime[i] = 0;
		std_wait1[i] = 0;
		std_wait2[i] = 0;
		std_wait3[i] = 0;
		std_waitt[i] = 0;
		std_speed[i] = 0;
	}
}

// �J�e�S�������߂�i�����L���O�̂Ȃ����[�h��-1�j
int stdRankingSetCategory(int player) {
	int data;
	data = -1;
	
	if(gameMode[player] != 17) return -1;
	if(playback || demo || IsBigStart[player] || item_mode[player]) return -1;
	
	if((timeattack[player] != 2) && (timeattack[player] != 3)) data = timeattack[player];
	return data;
}

// �����L���O��ǂݏ������鎞�Ɏg�p
int stdRankingGet(int rcat, int rrots) {
	return (rrots * 5) + (rcat * 50);
}

// ���ʂɓ��邩�`�F�b�N�i�����N�O�Ȃ�-1�j
int stdRankingCheck(int player) {
	int i, j, rank;
	
	if(playback || demo) return -1;
	if(stdRankingSetCategory(player) == -1) return -1;
	
	rank = -1;
	
	for(i = 0; i < 5; i++) {
		j = stdRankingGet(stdRankingSetCategory(player), rots[player]);
		
		if(timeattack[player] == 0) {
			if((c_norm[player] > std_rklines[j + i]) || 
			   ((c_norm[player] == std_rklines[j + i]) && (gameTimer[player] < std_rktime[j + i])))
			{
				rank = i;
				break;
			}
		} else if(timeattack[player] == 1) {
			if((sc[player] > std_rkscore[j + i]) || 
			   ((sc[player] == std_rkscore[j + i]) && (gameTimer[player] < std_rktime[j + i])))
			{
				rank = i;
				break;
			}
		}
	}
	
	return rank;
}

// �����L���O�ɓo�^
void stdRankingRegist(int player, int rank, str *rname) {
	int i, j;
	
	if(playback || demo) return;
	if((rank < 0) || (rank > 4)) return;
	if(stdRankingSetCategory(player) == -1) return;
	
	j = stdRankingGet(stdRankingSetCategory(player), rots[player]);
	
	// �����L���O�����炷
	for(i = 4; i > rank; i--) {
		StrCpy(std_rkname[j + i], std_rkname[j + i - 1]);
		std_rkscore[j + i] = std_rkscore[j + i - 1];
		std_rklines[j + i] = std_rklines[j + i - 1];
		std_rktime[j + i]  = std_rktime[j + i - 1];
		std_wait1[j + i] = std_wait1[j + i - 1];
		std_wait2[j + i] = std_wait2[j + i - 1];
		std_wait3[j + i] = std_wait3[j + i - 1];
		std_waitt[j + i] = std_waitt[j + i - 1];
		std_speed[j + i] = std_speed[j + i - 1];
	}
	
	// �V�����f�[�^��o�^
	StrCpy(std_rkname[j + rank], rname);
	std_rkscore[j + rank] = sc[player];
	std_rklines[j + rank] = c_norm[player];
	std_rktime[j + rank] = gameTimer[player];
	std_wait1[j + rank] = wait1[player];
	std_wait2[j + rank] = wait2[player];
	std_wait3[j + rank] = wait3[player];
	std_waitt[j + rank] = waitt[player];
	std_speed[j + rank] = sp[player];
}

// ���O���i�[����ϐ�(std_rkname)�̃��������m��
void stdRankingAlloc() {
	int i;
	
	for(i = 0; i < (5 * 10 * 4); i++) std_rkname[i] = new(4);
}

// �����L���O��\��
void stdRankingView() {
	int i, j, k, color;
	
	viewDarkTitle();
	
	// ���[�����\��
	printFont(1, 1, "RULE:", fontc[rankingrule]);
	getRuleNameEx(rankingrule, 0);
	printFont(6, 1, string[0], fontc[rankingrule]);
	
	// �J�e�S�����\��
	printFont(1, 2, "MODE:", ranking_category_color[category]);
	printFont(6, 2, ranking_category_name[category], ranking_category_color[category]);
	
	// �����L���O�\��
	printFont(1, 4, "RANK  NAME  SCORE   LINES  TIME", fontc[rankingrule]);
	
	for(i = 0; i < 5; i++) {
		j = stdRankingGet(category - 40, rankingrule);
		
		// ����
		if(i == 0) StrCpy(string[0], "1ST");
		if(i == 1) StrCpy(string[0], "2ND");
		if(i == 2) StrCpy(string[0], "3RD");
		if(i >= 3) sprintf(string[0], "%dTH", i + 1);
		printFont(1, 5 + i * 3, string[0], 0);
		
		// ���O
		printFont(7, 5 + i * 3, std_rkname[j + i], 0);
		
		// �X�R�A
		sprintf(string[0], "%d", std_rkscore[j + i]);
		printFont(13, 5 + i * 3, string[0], 0);
		
		// ���C��
		sprintf(string[0], "%d", std_rklines[j + i]);
		printFont(21, 5 + i * 3, string[0], 0);
		
		// �^�C��
		getTime(std_rktime[j + i]);
		printFont(28, 5 + i * 3, string[0], 0);
		
		// wait�l
		sprintf(string[0], "W1:%2d W2:%2d W3:%2d WT:%2d SP:%d",
				std_wait1[j + i], std_wait2[j + i], std_wait3[j + i], std_waitt[j + i], std_speed[j + i]);
		printFont(5, 6 + i * 3, string[0], 0);
	}
}

// �����L���O��ۑ�
void stdRankingSave() {
	int i, temp2[4];
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x4554494C;
	saveBuf[2] = 0x52445453;
	saveBuf[3] = 0x314B4E41;
	
	for(i = 0; i < (5 * 10 * 4); i++) {
		// ���O
		StrCpy(&temp2, std_rkname[i]);
		saveBuf[4 + i] = temp2[0];
		
		saveBuf[4 + i + (5 * 10 * 4) * 1] = std_rkscore[i];	// �X�R�A
		saveBuf[4 + i + (5 * 10 * 4) * 2] = std_rklines[i];	// ���C��
		saveBuf[4 + i + (5 * 10 * 4) * 3] = std_rktime[i];	// �^�C��
		saveBuf[4 + i + (5 * 10 * 4) * 4] = std_wait1[i];	// wait1
		saveBuf[4 + i + (5 * 10 * 4) * 5] = std_wait2[i];	// wait2
		saveBuf[4 + i + (5 * 10 * 4) * 6] = std_wait3[i];	// wait3
		saveBuf[4 + i + (5 * 10 * 4) * 7] = std_waitt[i];	// waitt
		saveBuf[4 + i + (5 * 10 * 4) * 8] = std_speed[i];	// sp
	}
	
	SaveFile("RANKING_STD.SAV", &saveBuf, 1804 * 4);
}

// �����L���O��ǂݍ���
int stdRankingLoad() {
	int i, temp2[4];
	
	// �w�b�_�����ǂݍ���
	FillMemory(&saveBuf, 50000 * 4, 0);
	LoadFile("RANKING_STD.SAV", &saveBuf, 16);
	
	// �o�[�W�����Ⴂ�Ȃ珉����
	if(saveBuf[0] != 0x4F424548) return -1;
	if(saveBuf[1] != 0x4554494C) return -1;
	if(saveBuf[2] != 0x52445453) return -1;
	if(saveBuf[3] != 0x314B4E41) return -1;
	
	// �S���ǂݍ���
	LoadFile("RANKING_STD.SAV", &saveBuf, 1804 * 4);
	
	// �����L���O�f�[�^
	for(i = 0; i < (5 * 10 * 4); i++) {
		// ���O
		temp2[0] = saveBuf[4 + i];
		StrCpy(std_rkname[i], &temp2);
		
		std_rkscore[i] = saveBuf[4 + i + (5 * 10 * 4) * 1];	// �X�R�A
		std_rklines[i] = saveBuf[4 + i + (5 * 10 * 4) * 2];	// ���C��
		std_rktime[i]  = saveBuf[4 + i + (5 * 10 * 4) * 3];	// �^�C��
		std_wait1[i]   = saveBuf[4 + i + (5 * 10 * 4) * 4];	// wait1
		std_wait2[i]   = saveBuf[4 + i + (5 * 10 * 4) * 5];	// wait2
		std_wait3[i]   = saveBuf[4 + i + (5 * 10 * 4) * 6];	// wait3
		std_waitt[i]   = saveBuf[4 + i + (5 * 10 * 4) * 7];	// waitt
		std_speed[i]   = saveBuf[4 + i + (5 * 10 * 4) * 8];	// sp
	}
	
	return 0;
}
