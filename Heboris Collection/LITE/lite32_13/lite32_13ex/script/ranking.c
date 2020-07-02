//������������������������������������������������������������������������������
//  �����L���O�֘A
//������������������������������������������������������������������������������

// �����L���O������
void RankingInit() {
	int i;
	
	for(i = 0; i < (3 * 10 * 40); i++) {
		StrCpy(rkname[i], "NOP");
		rkdata1[i] = 0;
		rkdata2[i] = 0;
		rktime[i] = 0;
		rkclear[i] = 0;
		rkac[i] = 0;
		rkst[i] = 0;
		rksk[i] = 0;
		rkco[i] = 0;
	}
}

// �J�e�S�������߂�i�����L���O�̂Ȃ����[�h��-1�A�Z�N�V�����^�C�������L���O������g����j
int RankingSetCategory(int player) {
	int data;
	
	data = -1;
	
	if(playback || demo || IsBigStart[player] || item_mode[player]) return -1;
	
	// BEGINNER-TAMAYA
	if(gameMode[player] == 0) {
		if(timeattack[player]) data = 0;
	}
	// BEGINNER-NOVICE
	else if(gameMode[player] == 13) {
		if(timeattack[player]) data = 1;
	}
	// MASTER
	else if(gameMode[player] == 1) {
		if(timeattack[player]) {
			if(gradetype[player] == 2) {
				data = 33;
			} else {
				data = 2 + gradetype[player];
			}
		}
	}
	// 20G
	else if(gameMode[player] == 2) {
		if(timeattack[player]) {
			if(gradetype[player] == 2) {
				data = 34;
			} else {
				data = 4 + gradetype[player];
			}
		}
	}
	// HEBO+
	else if(gameMode[player] == 10) {
		if(timeattack[player]) data = 6;
	}
	// DEVIL-NORMAL
	else if(gameMode[player] == 11) {
		if(timeattack[player]) data = 7;
	}
	// DEVIL-HARD
	else if(gameMode[player] == 16) {
		if(timeattack[player]) data = 8;
	}
	// DEVIL-DOOM
	else if(gameMode[player] == 3) {
		if(timeattack[player]) data = 9;
	}
	// TOMOYO
	else if(gameMode[player] == 6) {
		if(start_stage[player] ==  0) data = 10 + timeattack[player];	// NORMAL
		if(start_stage[player] == 27) data = 12 + timeattack[player];	// EHEART
		if(start_stage[player] == 45) data = 14 + timeattack[player];	// TARGET
	}
	// TOMOYO-FLASH
	else if(gameMode[player] == 15) {
		if(!flash_edit[player]) data = 16 + timeattack[player];
	}
	// ACE (NORMAL�`ANOTHER2)
	else if(gameMode[player] == 7) {
		data = 18 + timeattack[player];
	}
	// ACE (BASIC�`VOID�j
	else if(gameMode[player] == 12) {
		data = 23 + timeattack[player];
	}
	// OLD STYLE
	else if(gameMode[player] == 9) {
		data = 27 + timeattack[player];
	}
	// FINAL
	else if(gameMode[player] == 14) {
		if(timeattack[player]) data = 29;
	}
	// MARATHON
	else if(gameMode[player] == 18) {
		data = 30 + timeattack[player];
	}
	
	return data;
}

// ����v�f�P�����߂�
int RankingSetData1(int player) {
	int data;
	
	data = 0;
	
	// BEGINNER / OLD STYLE / BEGINNER+ / FLASH / MARATHON
	if((gameMode[player] == 0) || (gameMode[player] == 9) || (gameMode[player] == 13) || (gameMode[player] == 15) || 
	   (gameMode[player] == 18))
	{
		data = sc[player];
	}
	// MASTER / 20G / DEVIL / EASYDEVIL
	else if((gameMode[player] == 1) || (gameMode[player] == 2) || (gameMode[player] == 3) || (gameMode[player] == 16))
	{
		data = grade[player];
	}
	// TOMOYO
	else if(gameMode[player] == 6)
	{
		if((start_stage[player] == 0) || (start_stage[player] == 27) || (start_stage[player] == 45))
			data = stage[player];
	}
	// ACE / ACE200
	else if((gameMode[player] == 7) || (gameMode[player] == 12))
	{
		data = c_norm[player];
	}
	// HEBO+ & DEVIL- & FINAL
	else if((gameMode[player] == 10) || (gameMode[player] == 11) || (gameMode[player] == 14))
	{
		data = tc[player];
	}
	
	return data;
}

// ����v�f�Q�����߂�
int RankingSetData2(int player) {
	int data;
	
	data = 0;
	
	// TOMOYO
	if(gameMode[player] == 6)
	{
		if(start_stage[player] == 0) data = clearp[player];
	}
	// FLASH
	else if(gameMode[player] == 15)
	{
		data = stage[player];
	}
	// MARATHON
	else if(gameMode[player] == 18)
	{
		if(timeattack[player] == 1) data = squarenum[player];
		else data = li[player];
	}
	// ���̑�
	else
	{
		data = tc[player];
	}
	
	return data;
}

// �����L���O��ǂݏ������鎞�Ɏg�p
int RankingGet(int rcat, int rrots) {
	return (rrots * 3) + (rcat * 30);
}

// ���ʂɓ��邩�`�F�b�N�i�����N�O�Ȃ�-1�j
int RankingCheck(int player) {
	int i, j, data1, data2, rank;
	
	if(playback || demo) return -1;
	if(RankingSetCategory(player) == -1) return -1;
	
	data1 = RankingSetData1(player);
	data2 = RankingSetData2(player);
	rank = -1;
	
	for(i = 0; i < 3; i++) {
		j = RankingGet(RankingSetCategory(player), rots[player]);
		
		if(
		   (end_f[player] > rkclear[j + i]) || 
		   ((end_f[player] == rkclear[j + i]) && (data1 > rkdata1[j + i])) || 
		   ((end_f[player] == rkclear[j + i]) && (data1 == rkdata1[j + i]) && (data2 > rkdata2[j + i])) || 
		   ((end_f[player] == rkclear[j + i]) && (data1 == rkdata1[j + i]) && (data2 == rkdata2[j + i]) && 
		    (gameTimer[player] < rktime[j + i]))
		  )
		{
			rank = i;
			break;
		}
	}
	
	return rank;
}

// �����L���O�ɓo�^
void RankingRegist(int player, int rank, str *rname) {
	int i, j, data1, data2;
	
	if(playback || demo) return;
	if((rank < 0) || (rank > 2)) return;
	if(RankingSetCategory(player) == -1) return;
	
	data1 = RankingSetData1(player);
	data2 = RankingSetData2(player);
	j = RankingGet(RankingSetCategory(player), rots[player]);
	
	// �����L���O�����炷
	for(i = 2; i > rank; i--) {
		StrCpy(rkname[j + i], rkname[j + i - 1]);
		rkdata1[j + i] = rkdata1[j + i - 1];
		rkdata2[j + i] = rkdata2[j + i - 1];
		rktime[j + i]  = rktime[j + i - 1];
		rkclear[j + i] = rkclear[j + i - 1];
		rkac[j + i]    = rkac[j + i - 1];
		rkst[j + i]    = rkst[j + i - 1];
		rksk[j + i]    = rksk[j + i - 1];
		rkco[j + i]    = rkco[j + i - 1];
	}
	
	// �V�����f�[�^��o�^
	StrCpy(rkname[j + rank], rname);
	rkdata1[j + rank] = data1;
	rkdata2[j + rank] = data2;
	rktime[j + rank]  = gameTimer[player];
	rkclear[j + rank] = end_f[player];
	rkac[j + rank]    = medal_ac[player];
	rkst[j + rank]    = medal_st[player];
	rksk[j + rank]    = medal_sk[player];
	rkco[j + rank]    = medal_co[player];
}

// �����L���O�\��
// �iSTANDARD���[�h�̃����L���O���\���ł���悤�ɂ��邽�߂��낢�뉘���������Ă��܂�orz�j
void RankingProc() {
	int disptime;
	disptime = 0;
	rankingrule = rots[0];
	
	// �\������J�e�S�������߂�
	category = RankingSetCategory(0);
	
	// ��Ŗ����ȃ��[�h��������STANDARD���[�h�̃����L���O������
	if(category == -1) {
		category = stdRankingSetCategory(0);
		if(category != -1) category = category + 40;
	}
	
	// ����ł��_���Ȃ�^�C�g��
	if(category == -1) {
		flag = 1;
		return;
	}
	
	while(loopFlag) {
		disptime++;
		
		KeyInput();
		if(refresh_timing) spriteTime();
		
		if(category < 40) {
			RankingView();
		} else {
			stdRankingView();
		}
		
		// A��B�Ŗ߂�
		if( (disptime > 448) || getPushState(0,4) || getPushState(0,5) || getPushState(1,4) || getPushState(1,5) ) {
			flag = 1;
			return;
		}
		
		if(!refresh_timing) spriteTime();
	}
}

void RankingProc2() {
	rankingrule = rots[0];
	category = RankingSetCategory(0);
	if(category == -1) category = 0;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		padRepeat(0);
		padRepeat2(0);
		
		if(category < 40) {
			RankingView();
		} else {
			stdRankingView();
		}
		
		// ��
		if( (mpc[0] == 1) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if(getPressState(0, 2)) {
			PlaySE(5);
			category--;
			if(category < 0) category = 41;
			if((category >= 35) && (category <= 39)) category = 34;
		}
		
		// ��
		if( (mpc[0] == 1) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if(getPressState(0, 3)) {
			PlaySE(5);
			category++;
			if(category > 41) category = 0;
			if((category >= 35) && (category <= 39)) category = 40;
		}
		
		// ��
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) || getPressState(0, 6) )
		if(getPressState(0, 0)) {
			PlaySE(5);
			rankingrule--;
			if(rankingrule < 0) rankingrule = 9;
		}
		
		// ��
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) || getPressState(0, 6) )
		if(getPressState(0, 1)) {
			PlaySE(5);
			rankingrule++;
			if(rankingrule > 9) rankingrule = 0;
		}
		
		// A��B�Ŗ߂�
		if(getPushState(0, 4) || getPushState(0, 5)) {
			return;
		}
		
		if(!refresh_timing) spriteTime();
	}
}

void RankingView() {
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
	printFont(1, 4, ranking_table_top[category], fontc[rankingrule]);
	
	for(i = 0; i < 3; i++) {
		j = RankingGet(category, rankingrule);
		
		color = 0;
		if(rkclear[j + i] == 1) color = 4;
		if(rkclear[j + i] == 2) color = 7;
		
		// ����
		if(i == 0) StrCpy(string[0], "1ST");
		if(i == 1) StrCpy(string[0], "2ND");
		if(i == 2) StrCpy(string[0], "3RD");
		printFont(1, 5 + i * 4, string[0], color);
		
		// ���O
		printFont(7, 5 + i * 4, rkname[j + i], color);
		
		// ����v�f�P
		if((category >= 2) && (category <= 5)) {
			// MASTER & 20G
			getGradeString(rkdata1[j + i], 0, 0);
			printFont(13, 5 + i * 4, string[0], color);
		} else if(category == 8) {
			// DEVIL-HARD
			getGradeString(rkdata1[j + i], 1, 0);
			printFont(13, 5 + i * 4, string[0], color);
		} else if(category == 9) {
			// DEVIL-DOOM
			getGradeString(rkdata1[j + i], 2, 0);
			printFont(13, 5 + i * 4, string[0], color);
		} else if((category == 10) || (category == 11)) {
			// TOMOYO-NORMAL
			if(rkclear[j + i] == 2) {
				sprintf(string[0], "ALL");
			} else if(rkdata1[j + i] >= 20) {
				sprintf(string[0], "EX%d", rkdata1[j + i] - 19);
			} else {
				sprintf(string[0], "%d", rkdata1[j + i] + 1);
			}
			printFont(13, 5 + i * 4, string[0], color);
		} else if((category == 12) || (category == 13)) {
			// TOMOYO-EHEART
			if(rkclear[j + i] == 2) {
				sprintf(string[0], "ALL");
			} else if(rkdata1[j + i] - 26 <= 0) {
				sprintf(string[0], "%d", 1);
			} else {
				sprintf(string[0], "%d", rkdata1[j + i] - 26);
			}
			printFont(13, 5 + i * 4, string[0], color);
		} else if((category == 14) || (category == 15)) {
			// TOMOYO-TARGET
			if(rkclear[j + i] == 2) {
				sprintf(string[0], "ALL");
			} else if(rkdata1[j + i] - 44 <= 0) {
				sprintf(string[0], "%d", 1);
			} else {
				sprintf(string[0], "%d", rkdata1[j + i] - 44);
			}
			printFont(13, 5 + i * 4, string[0], color);
		} else if((category >= 33) && (category <= 34)) {
			// MASTER-EASY & 20G-EASY
			getGradeString(rkdata1[j + i], 3, 0);
			printFont(13, 5 + i * 4, string[0], color);
		} else {
			sprintf(string[0], "%d", rkdata1[j + i]);
			printFont(13, 5 + i * 4, string[0], color);
		}
		
		// ����v�f�Q
		if((category == 10) || (category == 11)) {
			// TOMOYO-NORMAL
			sprintf(string[0], "%d%%", rkdata2[j + i]);
			printFont(21, 5 + i * 4, string[0], color);
		} else if((category >= 18) && (category <= 26)) {
			// ACE�n
			sprintf(string[0], "%d", rkdata2[j + i] + 1);
			printFont(21, 5 + i * 4, string[0], color);
		} else if((category <= 11) || (category >= 16)) {
			// ���̑�
			sprintf(string[0], "%d", rkdata2[j + i]);
			printFont(21, 5 + i * 4, string[0], color);
		}
		
		// �^�C��
		getTime(rktime[j + i]);
		printFont(28, 5 + i * 4, string[0], color);
		
		// ���_��
		if(rkst[j + i]) ExBltRect(0, 10, 50 + i * 32, 16, rkst[j + i] * 12, 16, 12);
		if(rkac[j + i]) ExBltRect(0, 30, 50 + i * 32,  0, rkac[j + i] * 12, 16, 12);
		if(rkco[j + i]) ExBltRect(0, 50, 50 + i * 32, 48, rkco[j + i] * 12, 16, 12);
		if(rksk[j + i]) ExBltRect(0, 70, 50 + i * 32, 32, rksk[j + i] * 12, 16, 12);
	}
}

// �����L���O��ۑ�
void RankingSave() {
	int i, temp2[4];
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x4554494C;
	saveBuf[2] = 0x48474948;
	saveBuf[3] = 0x33764353;
	
	// �����L���O�f�[�^
	for(i = 0; i < (3 * 10 * 40); i++) {
		// ���O
		StrCpy(&temp2, rkname[i]);
		saveBuf[4 + i] = temp2[0];
		
		saveBuf[4 + i + (3 * 10 * 40) * 1] = rkdata1[i];	// ����v�f�P
		saveBuf[4 + i + (3 * 10 * 40) * 2] = rkdata2[i];	// ����v�f�Q
		saveBuf[4 + i + (3 * 10 * 40) * 3] = rktime[i];		// �^�C��
		saveBuf[4 + i + (3 * 10 * 40) * 4] = rkclear[i];	// �N���A�t���O
		saveBuf[4 + i + (3 * 10 * 40) * 5] = rkac[i];		// AC���_��
		saveBuf[4 + i + (3 * 10 * 40) * 6] = rkst[i];		// ST���_��
		saveBuf[4 + i + (3 * 10 * 40) * 7] = rksk[i];		// SK���_��
		saveBuf[4 + i + (3 * 10 * 40) * 8] = rkco[i];		// CO���_��
	}
	
	SaveFile("RANKING.SAV", &saveBuf, 10804 * 4);
}

// �����L���O��ǂݍ���
int RankingLoad() {
	int i, temp2[4];
	
	// �w�b�_�����ǂݍ���
	FillMemory(&saveBuf, 50000 * 4, 0);
	LoadFile("RANKING.SAV", &saveBuf, 16);
	
	// �o�[�W�����Ⴂ�Ȃ珉����
	if(saveBuf[0] != 0x4F424548) return -1;
	if(saveBuf[1] != 0x4554494C) return -1;
	if(saveBuf[2] != 0x48474948) return -1;
	if(saveBuf[3] != 0x33764353) return -1;
	
	// �S���ǂݍ���
	LoadFile("RANKING.SAV", &saveBuf, 10804 * 4);
	
	// �����L���O�f�[�^
	for(i = 0; i < (3 * 10 * 40); i++) {
		// ���O
		temp2[0] = saveBuf[4 + i];
		StrCpy(rkname[i], &temp2);
		
		rkdata1[i] = saveBuf[4 + i + (3 * 10 * 40) * 1];	// ����v�f�P
		rkdata2[i] = saveBuf[4 + i + (3 * 10 * 40) * 2];	// ����v�f�Q
		rktime[i]  = saveBuf[4 + i + (3 * 10 * 40) * 3];	// �^�C��
		rkclear[i] = saveBuf[4 + i + (3 * 10 * 40) * 4];	// �N���A�t���O
		rkac[i]    = saveBuf[4 + i + (3 * 10 * 40) * 5];	// AC���_��
		rkst[i]    = saveBuf[4 + i + (3 * 10 * 40) * 6];	// ST���_��
		rksk[i]    = saveBuf[4 + i + (3 * 10 * 40) * 7];	// SK���_��
		rkco[i]    = saveBuf[4 + i + (3 * 10 * 40) * 8];	// CO���_��
	}
	
	return 0;
}

// ���O���i�[����ϐ�(rkname)�̃��������m��
void RankingAlloc() {
	int i;
	
	for(i = 0; i < (3 * 10 * 40); i++) rkname[i] = new(4);
}
