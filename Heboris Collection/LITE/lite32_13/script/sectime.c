//������������������������������������������������������������������������������
//  �Z�N�V�����^�C�������L���O�֘A
//������������������������������������������������������������������������������

// �����L���O������
void ST_RankingInit() {
	int i;
	
	for(i = 0; i < (30 * 10 * 40); i++) {
		StrCpy(stname[i], "NOP");
		sttime[i] = 5400;
		stend[i] = 0;
	}
}

// ST���_���̐F�𔻒�
int ST_RankingCheck(int player, int section) {
	int j;
	
	if(playback || demo) return 0;
	if(RankingSetCategory(player) == -1) return 0;
	
	j = ST_RankingGet(RankingSetCategory(player), rots[player]);
	
	if(now_sttime[section + player * 30] <= 0) {
		return 0;
	}
	
	// �L�^�X�V
	if(now_sttime[section + player * 30] < sttime[j + section]) {
		return 3;
	}
	// 5�b�ȓ�
	if(now_sttime[section + player * 30] < sttime[j + section] + 300) {
		return 2;
	}
	// 10�b�ȓ�
	if(now_sttime[section + player * 30] < sttime[j + section] + 600) {
		return 1;
	}
	
	return 0;
}

// �L�^�X�V�������`�F�b�N
int ST_RankingCheckAll(int player) {
	int i, j;
	
	if(playback || demo) return 0;
	if(RankingSetCategory(player) == -1) return 0;
	
	j = ST_RankingGet(RankingSetCategory(player), rots[player]);
	
	for(i = 0; i < 30; i++) {
		if(now_sttime[i + player * 30] > 0) {
			if(now_sttime[i + player * 30] < sttime[j + i]) {
				return 1;
			}
		}
	}
	
	return 0;
}

// �Z�N�V�����^�C�������L���O�X�V
void ST_RankingUpdate(int player, str *rname) {
	int i, j;
	
	if(playback || demo) return;
	if(RankingSetCategory(player) == -1) return;
	
	j = ST_RankingGet(RankingSetCategory(player), rots[player]);
	
	for(i = 0; i < 30; i++) {
		if(now_sttime[i + player * 30] > 0) {
			if(now_sttime[i + player * 30] < sttime[j + i]) {
				sttime[j + i] = now_sttime[i + player * 30];
				stend[j + i] = end_f[player];
				StrCpy(stname[j + i], rname);
			}
		}
	}
}

// �����L���O��ۑ�
void ST_RankingSave() {
	int i, temp2[4];
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x4554494C;
	saveBuf[2] = 0x54434553;
	saveBuf[3] = 0x344E4F49;
	
	// �����L���O�f�[�^
	for(i = 0; i < (30 * 10 * 40); i++) {
		// ���O
		StrCpy(&temp2, stname[i]);
		saveBuf[4 + i] = temp2[0];
		
		// �^�C��
		saveBuf[4 + i + (30 * 10 * 40) * 1] = sttime[i];
		
		// ���[���N���A
		saveBuf[4 + i + (30 * 10 * 40) * 2] = stend[i];
	}
	
	SaveFile("STRANKING.SAV", &saveBuf, 36004 * 4);
}

// �����L���O��ǂݍ���
int ST_RankingLoad() {
	int i, temp2[4];
	
	// �w�b�_�����ǂݍ���
	FillMemory(&saveBuf, 50000 * 4, 0);
	LoadFile("STRANKING.SAV", &saveBuf, 16);
	
	// �o�[�W�����Ⴂ�Ȃ珉����
	if(saveBuf[0] != 0x4F424548) return -1;
	if(saveBuf[1] != 0x4554494C) return -1;
	if(saveBuf[2] != 0x54434553) return -1;
	if(saveBuf[3] != 0x344E4F49) return -1;
	
	// �S���ǂݍ���
	LoadFile("STRANKING.SAV", &saveBuf, 36004 * 4);
	
	for(i = 0; i < (30 * 10 * 40); i++) {
		// ���O
		temp2[0] = saveBuf[4 + i];
		StrCpy(stname[i], &temp2);
		
		// �^�C��
		sttime[i] = saveBuf[4 + i + (30 * 10 * 40) * 1];
		
		// ���[���N���A
		stend[i] = saveBuf[4 + i + (30 * 10 * 40) * 2];
	}
	
	return 0;
}

// �����L���O��ǂݏ������鎞�Ɏg�p
int ST_RankingGet(int rcat, int rrots) {
	return (rrots * 30) + (rcat * 300);
}

// ���O���i�[����ϐ�(stname)�̃��������m��
void ST_RankingAlloc() {
	int i;
	
	for(i = 0; i < (30 * 10 * 40); i++) stname[i] = new(4);
}

// �Z�N�V�����^�C�������L���O�\��
void ST_RankingView() {
	int i, j, k, color;
	int extra, start, end;
	int total;
	
	rankingrule = rots[0];
	category = RankingSetCategory(0);
	if(category < 0) category = 0;
	if(category > 39) category = 0;
	if((category == 16) || (category == 17)) category = 0;
	if((category >= 35) && (category <= 39)) category = 0;
	
	k = 0;
	extra = 0;		// TOMOYO-EXTRA�\���t���O
	start = 0;
	end = 0;
	total = 0;		// ���v�^�C��
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		padRepeat(0);
		padRepeat2(0);
		
		viewDarkTitle();
		
		// ���[�����\��
		printFont(1, 1, "RULE:", fontc[rankingrule]);
		getRuleNameEx(rankingrule, 0);
		printFont(6, 1, string[0], fontc[rankingrule]);
		
		// �J�e�S�����\��
		printFont(1, 2, "MODE:", ranking_category_color[category]);
		printFont(6, 2, ranking_category_name[category], ranking_category_color[category]);
		
		// �����L���O�\��
		printFont(1, 4, "SECTION  TIME      NAME", fontc[rankingrule]);
		
		// �\���J�n�n�_�����߂�
		if(!extra) {
			start = 0;
			end = ST_RankingSetMaxSection(category);
		} else {
			start = 20;
			end = 27;
		}
		
		k = 0;	// �Z�N�V�����^�C����\������Y���W
		total = 0;
		
		for(i = start; i < end; i++) {
			j = ST_RankingGet(category, rankingrule);
			
			color = 0;
			if(stend[j + i] == 1) color = 4;
			if(stend[j + i] == 2) color = 7;
			
			ST_RankingGetSectionName(category, i);
			printFont(0, 5 + k, string[0], color);
			
			getTime(sttime[j + i]);
			printFont(10, 5 + k, string[0], color);
			
			printFont(20, 5 + k, stname[j + i], color);
			
			k++;
			total = total + sttime[j + i];
		}
		
		// TOMOYO��EXTRA�؂�ւ�
		if((category == 10) || (category == 11) || (category == 14) || (category == 15)) {
			printFont(1, 27, "PRESS HOLD TO CHANGE PAGE", 3);
			
			if(getPushState(0,7) || getPushState(1,7)) {
				PlaySE(0);
				extra = !extra;
			}
		}
		
		printFont(1, 28, "TOTAL TIME:", 1);
		getTime(total);
		printFont(13, 28, string[0], 2);
		
		// ��
		if( (mpc[0] == 1) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if(getPressState(0, 2)) {
			PlaySE(5);
			category--;
			if(category < 0) category = 39;
			if((category == 16) || (category == 17)) category = 15;	// FLASH���[�h���΂�
			if((category >= 35) && (category <= 39)) category = 34;
			extra = 0;
		}
		
		// ��
		if( (mpc[0] == 1) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if(getPressState(0, 3)) {
			PlaySE(5);
			category++;
			if(category > 39) category = 0;
			if((category == 16) || (category == 17)) category = 18;	// FLASH���[�h���΂�
			if((category >= 35) && (category <= 39)) category = 0;
			extra = 0;
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
		if(getPushState(0,4) || getPushState(0,5) || getPushState(1,4) || getPushState(1,5)) {
			return;
		}
		
		if(!refresh_timing) spriteTime();
	}
}

// �Z�N�V�����̍ő�\���������߂�
int ST_RankingSetMaxSection(int cat) {
	int max;
	
	// BEGINNER-TAMAYA
	if(cat == 0) {
		max = 2;
	}
	// BEGINNER-NOVICE
	else if(cat == 1) {
		max = 3;
	}
	// DEVIL-HARD/DEVIL-DOOM
	else if((cat == 8) || (cat == 9)) {
		max = 13;
	}
	// TOMOYO-NORMAL
	else if((cat == 10) || (cat == 11)) {
		max = 20;
	}
	// TOMOYO-EHEART
	else if((cat == 12) || (cat == 13)) {
		max = 18;
	}
	// TOMOYO-TARGET
	else if((cat == 14) || (cat == 15)) {
		max = 20;
	}
	// TOMOYO-FLASH
	else if((cat == 16) || (cat == 17)) {
		max = 0;
	}
	// ACE (NORMAL�`ANOTHER2�j
	else if((cat >= 18) && (cat <= 22)) {
		max = 15;
	}
	// ACE (BASIC�`VOID�j
	else if((cat >= 23) && (cat <= 26)) {
		max = 20;
	}
	// OLD STYLE
	else if((cat == 27) || (cat == 28)) {
		max = 15;
	}
	// MARATHON
	else if((cat == 30) || (cat == 31)) {
		max = 15;
	}
	else if(cat == 32) {
		max = 14;
	}
	// ����ȊO
	else {
		max = 10;
	}
	
	return max;
}

void ST_RankingGetSectionName(int cat, int section) {
	// MASTER & 20G & HEBO+ & DEVIL-NORMAL & FINAL
	if( ((cat >= 2) && (cat <= 7)) || (cat == 29) || (cat == 33) || (cat == 34) ) {
		if(section == 9)
			sprintf(string[0], " 900-999");
		else
			sprintf(string[0], "%4d-%3d", section * 100, (section + 1) * 100);
	}
	// TOMOYO-NORMAL
	else if((cat == 10) || (cat == 11)) {
		if(section >= 20)
			sprintf(string[0], " EX%d", section - 19);
		else
			sprintf(string[0], " %d", section + 1);
	}
	// TOMOYO-EHEART & TOMOYO-TARGET
	else if((cat >= 12) && (cat <= 17)) {
		sprintf(string[0], " %d", section + 1);
	}
	// ACE
	else if((cat >= 18) && (cat <= 26)) {
		sprintf(string[0], " LV%d", section + 1);
	}
	// OLD STYLE
	else if((cat == 27) || (cat == 28)) {
		sprintf(string[0], " LV%d", section);
	}
	// MARATHON
	else if((cat == 30) || (cat == 31) || (cat == 32)) {
		sprintf(string[0], " LV%d", section + 1);
	}
	// ���̑�
	else {
		sprintf(string[0], "%4d-%3d", section * 100, (section + 1) * 100);
	}
}
