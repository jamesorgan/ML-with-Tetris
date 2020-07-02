// �i�ʏ㏸����iMASTER-EASY�j
void GradeUpEasy(int player) {
	// ��X�R�A�B��
	while((grade[player] < 17) && (sc[player] >= master_easy_score_table[grade[player]])) {
		gup_down[player] = 1;
		gflash[player] = 120;
		PlaySE(31);
		grade[player]++;
		
		// S9�ɂȂ�Ɨ��ꐯ
		if(grade[player] >= 17) objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
	}
}

// MASTER-NORMAL�i�ʏ㏸���� #LITE28
// C7T7.1EX��K���ɃR�s�y�������܂��� #LITE30.6
void GradeUp(int player, int lines) {
	int i, gbai;

	// �i�ʃ|�C���g���グ�邽�߂̔{�����v�Z
	if(lines >= 4) gskill[player]++;					// 4�i�����{�[�i�X
	
	if( (lines >= 2) && 
		(((tc[player] < 500) && (combo2[player] >= 4)) || ((tc[player] >= 500) && (combo2[player] >= 3))) )
	{
		gskill[player]++;								// �R���{�{�[�i�X
	}
	
	if(bonus_tspin)
		gskill[player] = gskill[player] + IsTspin[player];	// T-SPIN�{�[�i�X
	
	if( ((gskill[player] == 15) && (gskbai[player] == 0)) || 
		((gskill[player] == 30) && (gskbai[player] == 1)) || 
		((gskill[player] == 42) && (gskbai[player] == 2)) || 
		((gskill[player] == 50) && (gskbai[player] == 3)) )
	{
		gskbai[player]++;
	}
	
	// �㏸����i�ʃ|�C���g�̊�{�_�����߂�
	if(grade[player] == 0) {
		// 9
		if(lines == 1) i = 10;
		if(lines == 2) i = 15;
		if(lines == 3) i = 30;
		if(lines == 4) i = 55;
	} else if((grade[player] >= 1) && (grade[player] <= 2)) {
		// 8,7
		if(lines == 1) i = 10;
		if(lines == 2) i = 20;
		if(lines == 3) i = 30;
		if(lines == 4) i = 40;
	} else if((grade[player] >= 3) && (grade[player] <= 5)) {
		// 6,5,4
		if(lines == 1) i = 10;
		if(lines == 2) i = 15;
		if(lines == 3) i = 25;
		if(lines == 4) i = 35;
	} else if((grade[player] >= 6) && (grade[player] <= 8)) {
		// 3,2,1
		if(lines == 1) i = 5;
		if(lines == 2) i = 15;
		if(lines == 3) i = 23;
		if(lines == 4) i = 33;
	} else if((grade[player] >= 9) && (grade[player] <= 12)) {
		// S1-S4
		if(lines == 1) i = 3;
		if(lines == 2) i = 12;
		if(lines == 3) i = 15;
		if(lines == 4) i = 30;
	} else if((grade[player] >= 13) && (grade[player] <= 15)) {
		// S5-S7
		if(lines == 1) i = 3;
		if(lines == 2) i = 15;
		if(lines == 3) i = 20;
		if(lines == 4) i = 30;
	} else if((grade[player] >= 16) && (grade[player] <= 26)) {
		// S8-m9
		if(lines == 1) i = 4;
		if(lines == 2) i = 18;
		if(lines == 3) i = 23;
		if(lines == 4) i = 30;
	} else {
		// M�ȏ�
		if(lines == 1) i = 2;
		if(lines == 2) i = 12;
		if(lines == 3) i = 15;
		if(lines == 4) i = 20;
	}

	// ���x���ɂ��{��
	gbai = ((tc[player] / 350) + 1);
	
	// gskbai�ɂ����_
	gbai = gbai + gskbai[player];
	
	// �Œ�ł�2�{
	if(gbai < 2) gbai = 2;
	
	i = (i * gbai) / 2;

	// �R���{�ɂ��i�ʃ|�C���g�㏸�␳
	if((combo[player] - 1) > 0) {
		if(combo2[player] <= 2) {
			// 1�R���{�`2�R���{
			if(lines == 2) i = (i *  6 * (combo2[player] - 1)) /  5;		// 1.2�{
			if(lines == 3) i = (i * 13 * (combo2[player] - 1)) / 10;		// 1.3�{
			if(lines == 4) i = (i *  3 * (combo2[player] - 1)) /  2;		// 1.5�{
		} else if(combo2[player] <= 4) {
			// 3�R���{�`4�R���{
			if(lines == 1) i = (i * 21 * (combo[player]  - 1)) / 20;		// 1.05�{
			if(lines == 2) i = (i * 11 * (combo2[player] - 1)) / 10;		// 1.1 �{
			if(lines == 3) i = (i *  6 * (combo2[player] - 1)) /  5;		// 1.2 �{
			if(lines == 4) i = (i *  3 * (combo2[player] - 1)) /  2;		// 1.5 �{
		}
	}

	// �Œ�ł�1�|�C���g�͏㏸������
	if(i < 1) i = 1;

	// �i�ʃ|�C���g�㏸
	gpoint[player] = gpoint[player] + i;

	// �i�ʏ㏸
	if( (gpoint[player] >= 100) && (grade[player] <= 28) ) {	// MV�܂�
		gup_down[player] = 1;
		gflash[player] = 120;
		PlaySE(31);
		
		// �|�C���g�����z��
		gpoint[player] = ((gpoint[player] - 100) / ((tc[player] / 350) + 1 + (combo2[player] / 2)));
		
		gtime[player] = 0;
		grade[player]++;
	}

	// gmflag1��������#C7T5EX
	if((tc[player] >= 500) && (!gmflag1_e[player])) {
		if((grade[player] >= 12) && (gameTimer[player] <= 300 * 60)) {
			gmflag1[player] = 1;
		}
		gmflag1_e[player] = 1;
		
		objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
	}

	// gmflag2��������#C7T5EX
	if((tc[player] >= 700) && (!gmflag2_e[player])) {
		if((grade[player] >= 18) && (gameTimer[player] <= 390 * 60)) {
			gmflag2[player] = 1;
		}
		gmflag2_e[player] = 1;
		
		objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
	}
}

// HARD�̂Ƃ��̒i��
// �u���b�N��u�����тɌĂяo��
void GradeUp3(int player) {
	int lap_timeT, secinlv, tmp, border;
	
	secinlv = tc[player] - ((tc[player] / 100) * 100);		// ���x���̉�2��
	lap_timeT = ( timeN[player] / (1 + (rule_are[rots[player]] != 1)) ) + (time99[player] * 2);
	
	// quality cool
	if((secinlv > 80) && (secinlv < 99) && (!qualityflag[player])) {
		// �Z�N�V�������x���Ŋ���
		ave_laptime3[player] = lap_timeT / secinlv;
		
		if(repversw <= 6) border = border_time6[border_rank[player]];
		else border = border_time[border_rank[player]];
		
		// COOL
		if(ave_laptime3[player] < border) {
			PlaySE(48);
			gup_down[player] = 1;		// COOL�̕������o��
			grade[player]++;			// �i��+1
			gflash[player] = 180;		// COOL�\�����Ԑݒ�
			
			qualityflag[player] = 1;	// 2��ȏ�COOL���o���Ȃ��悤�ɂ���
			gup3sp_adjust[player] = 2;	// ���x�X�L�b�v
			
			if(gup3rank[player] <= 1)
				gup3rank[player]++;		// �����N���グ��
			
			if(tr2[player] < 51) {
				tc_20g[player] = tc_20g[player] - 100;	// �t�F�[�h�A�E�g�\�背�x���O�|��
				if(tc_20g[player] < 285) tc_20g[player] = 285;
			}
		}
	}
	
	// skill cool�i�Z�N�V�����܂����͖����j
	if((!skillflag[player]) && (secinlv < 94)) {
		if(repversw >= 3) {
			if(tc[player] < 100) tmp = 3;
			else if(tc[player] < 200) tmp = 6;
			else tmp = 4;
		} else {
			if(tr2[player] <= 10) tmp = 3;
			else tmp = 4;
		}
		
		if(gskill[player] >= tmp) {
			PlaySE(48);
			gup_down[player] = 1;		// COOL�̕������o��
			grade[player]++;			// �i��+1
			gflash[player] = 180;		// COOL�\�����Ԑݒ�
			skillflag[player] = 1;		// 2��ȏ�COOL���o���Ȃ��悤�ɂ���
			gskill[player] = 0;			// �X�L�����Z�b�g
		}
	}
	
	// gmflag1��������iLV400�ɂȂ����Ƃ���tr2�ϐ���80�ȏ�j
	if((tc[player] >= 400) && (!gmflag1_e[player])) {
		if(tr2[player] >= 80) {
			gmflag1[player] = 1;
			gmflag1_e[player] = 1;
			objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
		}
	}
	
	// gmflag2���������isregret���iregret�������łȂ��j
}

// REGRET����
// 100�����邲�ƂɌĂяo��
void isregret(int player) {
	int border_time2, regretgosa, border;
	
	if(repversw <= 6) border = border_time6[border_rank[player]];
	else border = border_time[border_rank[player]];
	
	regretgosa = tr2[player] / 40;
	border_time2 = border + 6 + regretgosa;
	
	if(ave_laptime3[player] > border_time2) {
		// REGRET
		PlaySE(44);
		gup_down[player] = 0;
		gflash[player] = 120;
		
		// �~�i
		if(grade[player] > 0) grade[player]--;
		
		// ���x��������
		if((gup3rank[player] == 0) && (gup3sp_adjust[player] == 0)) {
			gup3sp_adjust[player] = 1;
		} else {
			// �܂�BGM���t�F�[�h�A�E�g���Ă��Ȃ��ꍇ�������x��蒼��
			if(!regretcancel[player]) {
				gup3rank[player] = 0;
				gup3sp_adjust[player] = 0;
				
				if(tr2[player] < 51) {
					tc_20g[player] = tc_20g[player] + 100;	// �t�F�[�h�A�E�g�\�背�x������
					if(tc_20g[player] > 485) tc_20g[player] = 485;
				}
			}
		}
		
		// GM�������D
		gmflag2[player] = 1;
	} else if(!qualityflag[player]) {
		// ���x���̂܂�
		gup3sp_adjust[player] = 1;
		
		// �����N��2�Ȃ�1�Ƀ_�E��������
		if(gup3rank[player] == 2) gup3rank[player]--;
	}
	
	// ���̊�^�C�������߂�
	border_rank[player] = border_rank[player] + gup3rank[player];
	
	ave_laptime3[player] = 0;
	grade[player]++;
}

// �Z�N�V�������ς�邲�Ƃɕϐ������Z�b�g����
void reset_gradeup3(int player) {
	gskill[player] = 0;
	time99[player] = 0;
	timeN[player] = 0;
	qualityflag[player] = 0;
	skillflag[player] = 0;
	regretcancel[player] = 0;
	gup3sp_adjust[player] = 0;
	regretcancel[player] = 0;
}
