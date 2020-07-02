//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.22 - �~�b�V�������[�h�Z���N�g���
//������������������������������������������������������������������������������
// statc[player * 10]    �F�J�E���^
void statMissionSelect(int player) {
	int i, color;
	
	statc[player * 10]++;
	
	color = (count % 4 / 2) * digitc[rots[player]];
	
	if(statc[player * 10] == 1) {
		loadMissionData(mission_file);
		viewMissionText();
	}
	
	printFont(boffset[0], 6, "SELECT", fontc[rots[player]]);
	printFont(boffset[0] + 4, 7, "COURSE", fontc[rots[player]]);
	
	printFont(boffset[0] + 4, 12, "k", color);
	printFont(boffset[0] + 4, 16, "n", color);
	
	if(StrLen(mission_course_name) > 0) {
		printFont(boffset[0], 14, mission_course_name, color);
	} else {
		sprintf(string[0], "EDIT %d", mission_file + 1);
		printFont(boffset[0], 14, string[0], color);
	}
	
	printFont(boffset[0], 19, "PRESS A TO", 0);
	printFont(boffset[0], 20, "START GAME", 0);
	printFont(boffset[0], 22, "PRESS D TO", 0);
	printFont(boffset[0], 23, " EDIT MODE", 0);
	
	padRepeat(player);
	padRepeat2(player);
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 0) ) {
		PlaySE(5);
		
		mission_file--;
		if(mission_file < 0) mission_file = 98;
		loadMissionData(mission_file);
		viewMissionText();
	}
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 1) ) {
		PlaySE(5);
		
		mission_file++;
		if(mission_file > 98) mission_file = 0;
		loadMissionData(mission_file);
		viewMissionText();
	}
	
	// ��
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 2) ) {
		PlaySE(5);
		c_mission--;
		if(c_mission < 0) c_mission = 29;
		viewMissionText();
	}
	
	// ��
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 3) ) {
		PlaySE(5);
		c_mission++;
		if(c_mission > 29) c_mission = 0;
		viewMissionText();
	}
	
	// A�{�^��
	if( getPushState(player, 4) ) {
		PlaySE(10);
		
		// BGM��~
		StopAllBGM();
		
		// �Q�[���J�n
		start_mission = c_mission;
		
		// ����󋵕\���ʒu�ύX
		if(!mission_hide_info) {
			if(!maxPlay) coffset = s_m_coffset;
			else coffset = d_m_coffset;
		} else {
			setFieldPosition(maxPlay);
		}
		
		stat[player] = 1;				// �u���b�N�V���b�^�[���s
		statc[player * 10] = 0;			// �X�e�[�^�X�J�E���^��0��
		statc[player * 10 + 1] = 3;		// �V���b�^�[��̓X�e�[�^�XNo.3
		return;
	}
	
	// B�{�^���Ŗ߂�
	if( getPushState(player, 5) ) {
		PlaySE(5);
		gameMode[player] = 0;
		stat[0] = 2;
		statc[0 * 10] = 0;
		stat[1] = 0;
		statc[1 * 10] = 0;
		
		for(i = 0; i < 10; i++) TextLayerOff(i);
		return;
	}
	
	// HOLD�{�^���ŃG�f�B�b�g���
	if( getPushState(player, 7) ) {
		stat[player] = 23;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		return;
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.23 - �~�b�V�������[�h�G�f�B�b�g���
//������������������������������������������������������������������������������
// statc[player * 10]    �F�J�[�\���ʒu
// statc[player * 10 + 1]�F�X�e�[�W�R�s�[�̃X�e�[�W�ԍ�
void statMissionEditor(int player) {
	int i, color;
	
	color = (count % 4 / 2) * digitc[rots[player]];
	
	printFont(toffset[0], 26, "D: EDIT NAME", 0);
	
	if(statc[player * 10] < 14) {
		printFont(boffset[0] - 1, 25, "kn  PAGE 1/2", 0);
		
		printFont(boffset[0], 5, "STAGE", fontc[rots[player]]);
		sprintf(string[0], "NO.%d", c_mission + 1);
		printFont(boffset[0], 6, string[0], (statc[player * 10] == 0) * color);
		
		printFont(boffset[0], 7, "TYPE", fontc[rots[player]]);
		if(mission_type[c_mission] < 0) {
			i = (mission_type[c_mission] + 1) * -1;
			printFont(boffset[0], 8, mission_ext_name_editor[i], (statc[player * 10] == 1) * color);
		} else {
			printFont(boffset[0], 8, mission_name_editor[mission_type[c_mission]], (statc[player * 10] == 1) * color);
		}
		
		printFont(boffset[0], 9, "NORM", fontc[rots[player]]);
		sprintf(string[0], "%2d", mission_norm[c_mission]);
		printFont(boffset[0] + 8, 9, string[0], (statc[player * 10] == 2) * color);
		
		printFont(boffset[0], 10, "TIME", fontc[rots[player]]);
		getTime(mission_time[c_mission]);
		printFont(boffset[0], 11, string[0], (statc[player * 10] == 3) * color);
		
		printFont(boffset[0], 12, "LEVEL", fontc[rots[player]]);
		if(mission_lv[c_mission] >= 15) {
			sprintf(string[0], "%2d+", mission_lv[c_mission] - 14);
			printFont(boffset[0] + 7, 12, string[0], (statc[player * 10] == 4) * color);
		} else {
			sprintf(string[0], "%2d", mission_lv[c_mission] + 1);
			printFont(boffset[0] + 8, 12, string[0], (statc[player * 10] == 4) * color);
		}
		
		if(mission_erase[c_mission] >= 0) {
			printFont(boffset[0], 13, "ERASE", fontc[rots[player]]);
			sprintf(string[0], "%3d", mission_erase[c_mission]);
		} else if(mission_erase[c_mission] < -20) {
			printFont(boffset[0], 13, "RISE-E", fontc[rots[player]]);
			sprintf(string[0], "%3d", abs(mission_erase[c_mission] + 20));
		} else {
			printFont(boffset[0], 13, "RISE-H", fontc[rots[player]]);
			sprintf(string[0], "%3d", abs(mission_erase[c_mission]));
		}
		printFont(boffset[0] + 7, 13, string[0], (statc[player * 10] == 5) * color);
		
		printFont(boffset[0], 14, "BGM", fontc[rots[player]]);
		if(mission_bgm[c_mission] == -1) {
			printFont(boffset[0] + 6, 14, "FADE", (statc[player * 10] == 6) * color);
		} else {
			sprintf(string[0], "%2d", mission_bgm[c_mission] + 1);
			printFont(boffset[0] + 8, 14, string[0], (statc[player * 10] == 6) * color);
		}
		
		printFont(boffset[0], 15, "ENDING", fontc[rots[player]]);
		if(mission_end[c_mission] ==  0) sprintf(string[0], "OFF");				// ���̖ʂ�
		if(mission_end[c_mission] ==  1) sprintf(string[0], "END");				// �G���f�B���O
		if(mission_end[c_mission] ==  2) sprintf(string[0], "EXTRA");			// �Ō���_�u���Ŏ���
		if(mission_end[c_mission] ==  3) sprintf(string[0], "EXTRA+");			// �Ō���_�u���Ŏ��ցi�������o���Ⴄ�j
		if(mission_end[c_mission] ==  4) sprintf(string[0], "STAFF ROLL");		// �m�[�}�����[��
		if(mission_end[c_mission] ==  5) sprintf(string[0], "M ROLL");			// �������[��
		if(mission_end[c_mission] ==  6) sprintf(string[0], "M BIG ROLL");		// �����r�b�O���[��
		if(mission_end[c_mission] ==  7) sprintf(string[0], "BIG ROLL");		// �r�b�O���[��
		if(mission_end[c_mission] ==  8) sprintf(string[0], "N ROLL");			// �������[��
		if(mission_end[c_mission] ==  9) sprintf(string[0], "N BIG ROLL");		// �����r�b�O���[��
		if(mission_end[c_mission] == 10) sprintf(string[0], "BONUS");			// �Ō���_�u���ő��؂薳�����l��
		
		printFont(boffset[0], 16, string[0], (statc[player * 10] == 7) * color);
		
		printFont(boffset[0], 18, "OPTIONS", fontc[rots[player]]);
		
		if((mission_type[c_mission] ==  2) || (mission_type[c_mission] ==  3) || 
		   (mission_type[c_mission] == 11) || (mission_type[c_mission] == 37)) {
			// �_�u�����g���v�����V���O����T-�X�s���_�u��
			sprintf(string[0], "TYPE  %4d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "N/A    %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 6) {
			// �^�[�Q�b�g
			sprintf(string[0], "MIN   %4d", mission_opt_1[c_mission] + 1);
			sprintf(string[1], "MAX   %4d", mission_opt_2[c_mission] + 1);
			sprintf(string[2], "FLASH  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "STGRAND%3d", mission_opt_4[c_mission]);
			sprintf(string[4], "RANDOPT%3d", mission_opt_5[c_mission]);
			sprintf(string[5], "ALL    %3d", mission_opt_6[c_mission]);
		} else if((mission_type[c_mission] == 7) || (mission_type[c_mission] == 40)) {
			// �C���C�T�[
			sprintf(string[0], "MIN    %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "MAX    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "LINES %4d", mission_opt_3[c_mission] + 1);
			sprintf(string[3], "LINES2%4d", mission_opt_4[c_mission] + 1);
			sprintf(string[4], "LINES3%4d", mission_opt_5[c_mission] + 1);
			sprintf(string[5], "LINES4%4d", mission_opt_6[c_mission] + 1);
		} else if(mission_type[c_mission] == 10) {
			// �A�i�U�[
			sprintf(string[0], "N/A    %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "BLIND  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 19) {
			// DEVIL 800
			sprintf(string[0], "NORISE %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "RANDOM %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "INTER  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 20) {
			// DEVIL 1200
			sprintf(string[0], "N/A    %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "FAST   %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 21) {
			// GARBAGE
			sprintf(string[0], "N/A    %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "LINES  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 22) {
			// �I�[���h�X�^�C��
			sprintf(string[0], "ARCADE %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "N/A    %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 23) {
			// �ϋv
			sprintf(string[0], "N/A    %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "LIMIT  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 26) {
			// �S����
			sprintf(string[0], "N/A    %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "NOBIG  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 27) {
			// �R���{
			sprintf(string[0], "N/A    %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "2LINE  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 30) {
			// �u���b�N�I�[�_�[�n
			sprintf(string[0], "HOLD   %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "BLOCK  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if( ((mission_type[c_mission] >= 31) && (mission_type[c_mission] <= 33)) || (mission_type[c_mission] == 38) ) {
			// �V���O���I�[�_�[�A�_�u���I�[�_�[�A�t�g���v���I�[�_�[�A�g���v���I�[�_�[
			sprintf(string[0], "HOLD   %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "TYPE   %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "BLOCK  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 39) {
			// �C���C�T�[�Q
			sprintf(string[0], "LINE1  %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "LINE2  %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "N/A    %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == -7) {
			// ���x�Œ�
			sprintf(string[0], "WAIT1  %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "WAIT2  %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "WAIT3  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "WAITT  %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "SPEED  %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else {
			// ���̑�
			sprintf(string[0], "N/A    %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "N/A    %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		}
		printFont(boffset[0], 19, string[0], (statc[player * 10] == 8) * color);
		printFont(boffset[0], 20, string[1], (statc[player * 10] == 9) * color);
		printFont(boffset[0], 21, string[2], (statc[player * 10] == 10) * color);
		printFont(boffset[0], 22, string[3], (statc[player * 10] == 11) * color);
		printFont(boffset[0], 23, string[4], (statc[player * 10] == 12) * color);
		printFont(boffset[0], 24, string[5], (statc[player * 10] == 13) * color);
	} else {
		printFont(boffset[0] - 1, 25, "kn  PAGE 2/2", 0);
		
		printFont(boffset[0], 5, "OPTIONS-2", fontc[rots[player]]);
		
		if(mission_type[c_mission] == 6) {
			// �^�[�Q�b�g
			sprintf(string[0], "USEn   %3d", mission_opt_7[c_mission]);
			sprintf(string[1], "MIN2  %4d", mission_opt_8[c_mission] + 1);
			sprintf(string[2], "MAX2  %4d", mission_opt_9[c_mission] + 1);
			sprintf(string[3], "FLASH2 %3d", mission_opt_10[c_mission]);
		} else {
			// ���̑�
			sprintf(string[0], "N/A    %3d", mission_opt_7[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_8[c_mission]);
			sprintf(string[2], "N/A    %3d", mission_opt_9[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_10[c_mission]);
		}
		printFont(boffset[0], 6, string[0], (statc[player * 10] == 14) * color);
		printFont(boffset[0], 7, string[1], (statc[player * 10] == 15) * color);
		printFont(boffset[0], 8, string[2], (statc[player * 10] == 16) * color);
		printFont(boffset[0], 9, string[3], (statc[player * 10] == 17) * color);
		
		// �w�i
		printFont(boffset[0], 11, "BACKGROUND", fontc[rots[player]]);
		if(!mission_bg[c_mission]) sprintf(string[0], "AUTO");
		else sprintf(string[0], "NO.%d", mission_bg[c_mission] - 1);
		printFont(boffset[0], 12, string[0], (statc[player * 10] == 18) * color);
		
		// �R�s�[
		printFont(boffset[0], 14, "COPY STAGE", fontc[rots[player]]);
		sprintf(string[0], "NO.%d", statc[player * 10 + 1] + 1);
		printFont(boffset[0], 15, string[0], (statc[player * 10] == 19) * color);
		
		// �w�߉B��
		printFont(boffset[0], 17, "HIDE INFO", digitc[rots[player]]);
		if(!mission_hide_info) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFont(boffset[0], 18, string[0], (statc[player * 10] == 20) * color);
		
		// �I�[���N���A���̉��o
		printFont(boffset[0], 20, "ALL CLEAR", digitc[rots[player]]);
		if(mission_clear_anim == 0) sprintf(string[0], "NORMAL");
		else if(mission_clear_anim == 1) sprintf(string[0], "GM");
		else if(mission_clear_anim == 2) sprintf(string[0], "GOD");
		else sprintf(string[0], "EXCELLENT");
		printFont(boffset[0], 21, string[0], (statc[player * 10] == 21) * color);
	}
	
	// �L�[����
	padRepeat(player);
	padRepeat2(player);
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 0) ) {
		PlaySE(5);
		statc[player * 10]--;
		if(statc[player * 10] < 0) statc[player * 10] = 21;
	}
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 1) ) {
		PlaySE(5);
		statc[player * 10]++;
		if(statc[player * 10] > 21) statc[player * 10] = 0;
	}
	
	// ��
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 2) ) {
		PlaySE(3);
		
		// STAGE
		if(statc[player * 10] == 0) {
			c_mission--;
			if(c_mission < 0) c_mission = 29;
		}
		// TYPE
		if(statc[player * 10] == 1) {
			mission_type[c_mission]--;
			if(mission_type[c_mission] < -7) mission_type[c_mission] = 42;
		}
		// NORM
		if(statc[player * 10] == 2) {
			mission_norm[c_mission]--;
			if(mission_norm[c_mission] < 0) mission_norm[c_mission] = 99;
		}
		// TIME
		if(statc[player * 10] == 3) {
			mission_time[c_mission] = mission_time[c_mission] - 60;
			if(mission_time[c_mission] < 0) mission_time[c_mission] = 72000;
		}
		// LEVEL
		if(statc[player * 10] == 4) {
			mission_lv[c_mission]--;
			if(mission_lv[c_mission] < 0) mission_lv[c_mission] = 29;
		}
		// ERASE
		if(statc[player * 10] == 5) {
			mission_erase[c_mission]--;
			if(mission_erase[c_mission] < -40) mission_erase[c_mission] = 22;
		}
		// BGM
		if(statc[player * 10] == 6) {
			mission_bgm[c_mission]--;
			if(mission_bgm[c_mission] < -1) mission_bgm[c_mission] = 20;
		}
		// ENDING
		if(statc[player * 10] == 7) {
			mission_end[c_mission]--;
			if(mission_end[c_mission] < 0) mission_end[c_mission] = 10;
		}
		// MIN
		if(statc[player * 10] == 8) {
			mission_opt_1[c_mission]--;
			if(mission_opt_1[c_mission] < 0) mission_opt_1[c_mission] = 999;
		}
		// MAX
		if(statc[player * 10] == 9) {
			mission_opt_2[c_mission]--;
			if(mission_opt_2[c_mission] < 0) mission_opt_2[c_mission] = 999;
		}
		// OPT
		if(statc[player * 10] == 10) {
			mission_opt_3[c_mission]--;
			if(mission_opt_3[c_mission] < 0) mission_opt_3[c_mission] = 999;
		}
		if(statc[player * 10] == 11) {
			mission_opt_4[c_mission]--;
			if(mission_opt_4[c_mission] < 0) mission_opt_4[c_mission] = 999;
		}
		if(statc[player * 10] == 12) {
			mission_opt_5[c_mission]--;
			if(mission_opt_5[c_mission] < 0) mission_opt_5[c_mission] = 999;
		}
		if(statc[player * 10] == 13) {
			mission_opt_6[c_mission]--;
			if(mission_opt_6[c_mission] < 0) mission_opt_6[c_mission] = 999;
		}
		if(statc[player * 10] == 14) {
			mission_opt_7[c_mission]--;
			if(mission_opt_7[c_mission] < 0) mission_opt_7[c_mission] = 999;
		}
		if(statc[player * 10] == 15) {
			mission_opt_8[c_mission]--;
			if(mission_opt_8[c_mission] < 0) mission_opt_8[c_mission] = 999;
		}
		if(statc[player * 10] == 16) {
			mission_opt_9[c_mission]--;
			if(mission_opt_9[c_mission] < 0) mission_opt_9[c_mission] = 999;
		}
		if(statc[player * 10] == 17) {
			mission_opt_10[c_mission]--;
			if(mission_opt_10[c_mission] < 0) mission_opt_10[c_mission] = 999;
		}
		// BACKGROUND
		if(statc[player * 10] == 18) {
			mission_bg[c_mission]--;
			if(mission_bg[c_mission] < 0) mission_bg[c_mission] = 15;
		}
		// COPY STAGE
		if(statc[player * 10] == 19) {
			statc[player * 10 + 1]--;
			if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = 29;
		}
		// HIDE INFO
		if(statc[player * 10] == 20) {
			mission_hide_info = !mission_hide_info;
		}
		// ALL CLEAR
		if(statc[player * 10] == 21) {
			mission_clear_anim--;
			if(mission_clear_anim < 0) mission_clear_anim = 3;
		}
		
		viewMissionText();
	}
	
	// ��
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 3) ) {
		PlaySE(3);
		
		// STAGE
		if(statc[player * 10] == 0) {
			c_mission++;
			if(c_mission > 29) c_mission = 0;
		}
		// TYPE
		if(statc[player * 10] == 1) {
			mission_type[c_mission]++;
			if(mission_type[c_mission] > 42) mission_type[c_mission] = -7;
		}
		// NORM
		if(statc[player * 10] == 2) {
			mission_norm[c_mission]++;
			if(mission_norm[c_mission] > 99) mission_norm[c_mission] = 0;
		}
		// TIME
		if(statc[player * 10] == 3) {
			mission_time[c_mission] = mission_time[c_mission] + 60;
			if(mission_time[c_mission] > 72000) mission_time[c_mission] = 0;
		}
		// LEVEL
		if(statc[player * 10] == 4) {
			mission_lv[c_mission]++;
			if(mission_lv[c_mission] > 29) mission_lv[c_mission] = 0;
		}
		// ERASE
		if(statc[player * 10] == 5) {
			mission_erase[c_mission]++;
			if(mission_erase[c_mission] > 22) mission_erase[c_mission] = -40;
		}
		// BGM
		if(statc[player * 10] == 6) {
			mission_bgm[c_mission]++;
			if(mission_bgm[c_mission] > 20) mission_bgm[c_mission] = -1;
		}
		// ENDING
		if(statc[player * 10] == 7) {
			mission_end[c_mission]++;
			if(mission_end[c_mission] > 10) mission_end[c_mission] = 0;
		}
		// OPT
		if(statc[player * 10] == 8) {
			mission_opt_1[c_mission]++;
			if(mission_opt_1[c_mission] > 999) mission_opt_1[c_mission] = 0;
		}
		if(statc[player * 10] == 9) {
			mission_opt_2[c_mission]++;
			if(mission_opt_2[c_mission] > 999) mission_opt_2[c_mission] = 0;
		}
		if(statc[player * 10] == 10) {
			mission_opt_3[c_mission]++;
			if(mission_opt_3[c_mission] > 999) mission_opt_3[c_mission] = 0;
		}
		if(statc[player * 10] == 11) {
			mission_opt_4[c_mission]++;
			if(mission_opt_4[c_mission] > 999) mission_opt_4[c_mission] = 0;
		}
		if(statc[player * 10] == 12) {
			mission_opt_5[c_mission]++;
			if(mission_opt_5[c_mission] > 999) mission_opt_5[c_mission] = 0;
		}
		if(statc[player * 10] == 13) {
			mission_opt_6[c_mission]++;
			if(mission_opt_6[c_mission] > 999) mission_opt_6[c_mission] = 0;
		}
		if(statc[player * 10] == 14) {
			mission_opt_7[c_mission]++;
			if(mission_opt_7[c_mission] > 999) mission_opt_7[c_mission] = 0;
		}
		if(statc[player * 10] == 15) {
			mission_opt_8[c_mission]++;
			if(mission_opt_8[c_mission] > 999) mission_opt_8[c_mission] = 0;
		}
		if(statc[player * 10] == 16) {
			mission_opt_9[c_mission]++;
			if(mission_opt_9[c_mission] > 999) mission_opt_9[c_mission] = 0;
		}
		if(statc[player * 10] == 17) {
			mission_opt_10[c_mission]++;
			if(mission_opt_10[c_mission] > 999) mission_opt_10[c_mission] = 0;
		}
		// BACKGROUND
		if(statc[player * 10] == 18) {
			mission_bg[c_mission]++;
			if(mission_bg[c_mission] > 15) mission_bg[c_mission] = 0;
		}
		// COPY STAGE
		if(statc[player * 10] == 19) {
			statc[player * 10 + 1]++;
			if(statc[player * 10 + 1] > 29) statc[player * 10 + 1] = 0;
		}
		// HIDE INFO
		if(statc[player * 10] == 20) {
			mission_hide_info = !mission_hide_info;
		}
		// ALL CLEAR
		if(statc[player * 10] == 21) {
			mission_clear_anim++;
			if(mission_clear_anim > 3) mission_clear_anim = 0;
		}
		
		viewMissionText();
	}
	
	// A�{�^��
	if( getPushState(player, 4) ) {
		// �R�s�[
		if(statc[player * 10] == 19) {
			PlaySE(3);
			mission_type[c_mission]   = mission_type[statc[player * 10 + 1]];
			mission_norm[c_mission]   = mission_norm[statc[player * 10 + 1]];
			mission_time[c_mission]   = mission_time[statc[player * 10 + 1]];
			mission_end[c_mission]    = mission_end[statc[player * 10 + 1]];
			mission_lv[c_mission]     = mission_lv[statc[player * 10 + 1]];
			mission_erase[c_mission]  = mission_erase[statc[player * 10 + 1]];
			mission_opt_1[c_mission]  = mission_opt_1[statc[player * 10 + 1]];
			mission_opt_2[c_mission]  = mission_opt_2[statc[player * 10 + 1]];
			mission_opt_3[c_mission]  = mission_opt_3[statc[player * 10 + 1]];
			mission_bgm[c_mission]    = mission_bgm[statc[player * 10 + 1]];
			mission_opt_4[c_mission]  = mission_opt_4[statc[player * 10 + 1]];
			mission_opt_5[c_mission]  = mission_opt_5[statc[player * 10 + 1]];
			mission_opt_6[c_mission]  = mission_opt_6[statc[player * 10 + 1]];
			mission_bg[c_mission]     = mission_bg[statc[player * 10 + 1]];
			mission_opt_7[c_mission]  = mission_opt_7[statc[player * 10 + 1]];
			mission_opt_8[c_mission]  = mission_opt_8[statc[player * 10 + 1]];
			mission_opt_9[c_mission]  = mission_opt_9[statc[player * 10 + 1]];
			mission_opt_10[c_mission] = mission_opt_10[statc[player * 10 + 1]];
			
			viewMissionText();
		}
		// �Z�[�u
		else {
			PlaySE(10);
			saveMissionData(mission_file);
			stat[player] = 22;
			statc[player * 10] = 0;
			statc[player * 10 + 1] = 0;
			return;
		}
	}
	
	// B�{�^���Ŗ߂�
	if( getPushState(player, 5) ) {
		PlaySE(5);
		loadMissionData(mission_file);
		stat[player] = 22;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		return;
	}
	
	// D�{�^���ŃR�[�X������
	if( getPushState(player, 7) ) {
		PlaySE(0);
		stat[player] = 39;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		return;
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.39 - �~�b�V�������[�h�R�[�X�����͉��
//������������������������������������������������������������������������������
// statc[player * 10]�@�@�F�������ς݃t���O
// statc[player * 10 + 1]�F�I���t���O
// statc[player * 10 + 2]�F���ݑI�����Ă��镶��
void statMissionCourseName(int player) {
	int		move, len;
	
	// ������
	if(!statc[player * 10]) {
		StrCpy(string[player + 2], mission_course_name);
		statc[player * 10] = 1;
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = 54;
	}
	
	padRepeat(player);
	
	printFont(boffset[player], 12, "ENTER NAME", 4);
	printFont(boffset[player], 16, "PRESS D", 1);
	printFont(boffset[player] + 1, 17, "TO CANCEL", 1);
	
	len = StrLen(string[player + 2]);	// ���͍ςݕ�����
	
	// ���ړ�
	move = getPressState(player, 3) - getPressState(player, 2);
	if(move)
		if((mpc[player] == 1) || (mpc[player] >= 15) || getPressState(player, 6)) {
			if(mpc[player] >= 15) mpc[player] = 12;
			statc[player * 10 + 2] = statc[player * 10 + 2] + move;
			PlaySE(5);
		}
	
	// �����̃��[�v
	if(statc[player * 10 + 2] > 54)
		statc[player * 10 + 2] = (len == 15) * 53;
	if(statc[player * 10 + 2] < (len == 15) * 53)
		statc[player * 10 + 2] = 54;
	
	// �I�����Ă��镶���Ɠ��͍ςݕ�����\��
	MidStr(RankString, statc[player * 10 + 2] + 1, 1, string[4]);
	printFont(boffset[player] + len, 14, string[4], 2 * (count % 20 > 10));
	printFont(boffset[player], 14, string[player + 2], 0);
	
	// D�ŃL�����Z��
	if(getPushState(player, 7)) {
		stat[player] = 23;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = 0;
		return;
	}
	
	// B�{�^����1�����폜
	if(getPushState(player, 5)) {
		if(len) {
			PlaySE(5);
			MidStr(string[player + 2], 1, len - 1, string[player + 2]);
		}
	}
	
	// A�{�^���œ���
	if(getPushState(player, 4)) {
		PlaySE(10);
		
		if(statc[player * 10 + 2] == 53) {
			// RB
			if(len) {
				MidStr(string[player + 2], 1, len - 1, string[player + 2]);
			}
		} else if(statc[player * 10 + 2] == 54) {
			// ED
			statc[player * 10 + 1] = 1;
		} else {
			// ��������
			StrCat(string[player + 2], string[4]);
		}
	}
	
	// �l�[���G���g���[�I��
	if(statc[player * 10 + 1]) {
		PlaySE(18);
		
		// ���O�̌��ɃX�y�[�X��}���i�]���������X�y�[�X�ɂ���j
		sprintf(string[player + 2], "%s                ", string[player + 2]);
		
		// ������16�����ڈȍ~���폜
		LeftStr(string[player + 2], 15, string[player + 2]);
		
		// �ۑ�
		StrCpy(mission_course_name, string[player + 2]);
		saveMissionData(mission_file);
		
		// �I���
		stat[player] = 23;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = 0;
	}
}

//������������������������������������������������������������������������������
//  ���̕\��
//������������������������������������������������������������������������������

// �g
void viewMissionFrame() {
	int i, j, tmp, tmp2;
	
	if(mission_hide_info) return;
	
	// �g
	ExBltFastRect(4, moffset, 112, 0, 64, 112, 112);
	
	// �u���b�N�I�[�_�[
	if( ((mission_type[c_mission] >= 30) && (mission_type[c_mission] <= 33)) || (mission_type[c_mission] == 38) ) {
		if(mission_opt_3[c_mission] <= 6) {
			// �ʏ�
			if(!rule_color[rots[0]]) {
				tmp = ccol[mission_opt_3[c_mission]];
			} else {
				tmp = wcol[mission_opt_3[c_mission]];
			}
			j = ( ((mission_opt_3[c_mission] != 0) || (isDRule(0))) && (!isWRule(0)) );
			
			if((mission_type[c_mission] == 33) && (english)) {
				// �t�g���v���I�[�_�[���p�ꃂ�[�h
				drawBlockFast(moffset + 1, 23 - j, mission_opt_3[c_mission], 0, tmp, 0, 0, 0, 0);
			} else {
				// ���̑�
				if(english)
					drawBlockFast(moffset + 1, 22 - j, mission_opt_3[c_mission], 0, tmp, 0, 0, 0, 0);
				else
					drawBlockFast(moffset + 1, 19 - j, mission_opt_3[c_mission], 0, tmp, 0, 0, 0, 0);
			}
		} else if(mission_opt_3[c_mission] == 7) {
			// LJ
			if(!rule_color[rots[0]]) {
				tmp = ccol[1];
				tmp2 = ccol[5];
			} else {
				tmp = wcol[1];
				tmp2 = wcol[5];
			}
			j = (!isWRule(0));
			
			if((mission_type[c_mission] == 33) && (english)) {
				// �t�g���v���I�[�_�[���p�ꃂ�[�h
				drawBlockFast(moffset + 1, 23 - j, 1, 0, tmp, 0, 0, 0, 0);
				drawBlockFast(moffset + 5, 23 - j, 5, 0, tmp2, 0, 0, 0, 0);
			} else {
				// ���̑�
				if(english) {
					drawBlockFast(moffset + 1, 22 - j, 1, 0, tmp, 0, 0, 0, 0);
					drawBlockFast(moffset + 5, 22 - j, 5, 0, tmp2, 0, 0, 0, 0);
				} else {
					drawBlockFast(moffset + 1, 19 - j, 1, 0, tmp, 0, 0, 0, 0);
					drawBlockFast(moffset + 5, 19 - j, 5, 0, tmp2, 0, 0, 0, 0);
				}
			}
		} else if(mission_opt_3[c_mission] == 8) {
			// SZ
			if(!rule_color[rots[0]]) {
				tmp = ccol[3];
				tmp2 = ccol[6];
			} else {
				tmp = wcol[3];
				tmp2 = wcol[6];
			}
			j = (!isWRule(0));
			
			if((mission_type[c_mission] == 33) && (english)) {
				// �t�g���v���I�[�_�[���p�ꃂ�[�h
				drawBlockFast(moffset + 1, 23 - j, 3, 0, tmp, 0, 0, 0, 0);
				drawBlockFast(moffset + 5, 23 - j, 6, 0, tmp2, 0, 0, 0, 0);
			} else {
				// ���̑�
				if(english) {
					drawBlockFast(moffset + 1, 22 - j, 3, 0, tmp, 0, 0, 0, 0);
					drawBlockFast(moffset + 5, 22 - j, 6, 0, tmp2, 0, 0, 0, 0);
				} else {
					drawBlockFast(moffset + 1, 19 - j, 3, 0, tmp, 0, 0, 0, 0);
					drawBlockFast(moffset + 5, 19 - j, 6, 0, tmp2, 0, 0, 0, 0);
				}
			}
		}
	}
	
	// �~�b�V�����ꗗ
	tmp = 0;
	
	while(c_mission - tmp > 4) {
		tmp = tmp + 5;
	}
	
	for(i = tmp; i < (tmp + 5); i++) {
		if((c_mission > i) || (ending[0] != 0)) {
			// �N���A�ς�
			ExBltFastRect(4, moffset, 32 + (i - tmp) * 16, 0, 48, 96, 16);
			ExBltRect(3, moffset + 98, 34 + (i - tmp) * 16, 12, 191, 12, 12);
		} else if(c_mission == i) {
			// �v���C��
			ExBltFastRect(4, moffset, 32 + (i - tmp) * 16, 0, 32, 96, 16);
			ExBltRect(3, moffset + 98, 34 + (i - tmp) * 16, 0, 191, 12, 12);
		} else {
			// �܂����v���C
			ExBltFastRect(4, moffset, 32 + (i - tmp) * 16, 0, 16, 96, 16);
			ExBltRect(3, moffset + 98, 34 + (i - tmp) * 16, 0, 191, 12, 12);
		}
		
		// �I���t���O������ꍇ�͂����Ń��[�v�𔲂���
		if((mission_end[i] != 0) && (mission_end[i] != 10)) break;
	}
}

// ����
void viewMissionText() {
	int i, tmp, count, draw_rate, tmp2;
	
	for(i = 0; i < 10; i++) TextLayerOff(i);
	
	if(mission_hide_info) return;
	
	if(screenMode >= 2) draw_rate = 2;
	else draw_rate = 1;
	
	// �薼
	TextSize(0, 10 * draw_rate);
	TextColor(0, 0, 0, 0);
	TextBackColorDisable(0);
	
	if(!english) {
		// ���{��
		if(mission_type[c_mission] < 0) {
			tmp2 = (mission_type[c_mission] + 1) * -1;
			StrCpy(string[0], mission_ext_name_jp[tmp2]);
		} else {
			StrCpy(string[0], mission_name_jp[mission_type[c_mission]]);
		}
	} else {
		// English
		if(mission_type[c_mission] < 0) {
			tmp2 = (mission_type[c_mission] + 1) * -1;
			StrCpy(string[0], mission_ext_name_en[tmp2]);
		} else {
			StrCpy(string[0], mission_name_en[mission_type[c_mission]]);
		}
	}
	
	// +
	if(mission_lv[c_mission] >= 15) StrCat(string[0], "+");
	
	// ���x��
	if(mission_lv[c_mission] >= 15) sprintf(string[1], " LV%02d", mission_lv[c_mission] - 14);
	else                            sprintf(string[1], " LV%02d", mission_lv[c_mission] + 1);
	StrCat(string[0], string[1]);
	
	TextOut(0, string[0]);
	TextLayerOn(0, (5 + moffset) * draw_rate, (8 + 112) * draw_rate);
	
	// ��������
	TextSize(1, 10 * draw_rate);
	TextColor(1, 0, 0, 0);
	TextBackColorDisable(1);
	
	StrCpy(string[1], mission_timelimit[english]);
	
	if(mission_time[c_mission] > 0) {
		getTime(mission_time[c_mission]);
	} else {
		StrCpy(string[0], mission_timelimit[2 + english]);
	}
	StrCat(string[1], string[0]);
	
	TextOut(1, string[1]);
	TextLayerOn(1, (5 + moffset) * draw_rate, (20 + 112) * draw_rate);
	
	// �w�ߕ�
	TextSize(2, 10 * draw_rate);
	TextColor(2, 0, 0, 0);
	TextBackColorDisable(2);
	
	if(mission_type[c_mission] < 0) {
		// �g��
		tmp2 = (mission_type[c_mission] + 1) * -1;
		
		if(!english)
			sprintf(string[0], mission_ext_info_jp[tmp2], mission_norm[c_mission]);
		else
			sprintf(string[0], mission_ext_info_en[tmp2], mission_norm[c_mission]);
	} else {
		// �W��
		if(!english)
			sprintf(string[0], mission_info_jp[mission_type[c_mission]], mission_norm[c_mission]);
		else
			sprintf(string[0], mission_info_en[mission_type[c_mission]], mission_norm[c_mission]);
	}
	
	// �_�u���̒ǉ�����
	if(mission_type[c_mission] == 2) {
		// �w��ȏ���J�E���g
		if(mission_opt_1[c_mission] == 1) {
			if(!english) StrCat(string[0], mission_info2_jp[1]);
			else StrCat(string[0], mission_info2_en[1]);
		}
		// ���s����ƃm���}���Z�b�g
		if(mission_opt_1[c_mission] >= 2) {
			if(!english) StrCat(string[0], mission_info2_jp[4]);
			else StrCat(string[0], mission_info2_en[4]);
		}
	}
	
	// �g���v���̒ǉ�����
	if(mission_type[c_mission] == 3) {
		// �w��ȏ���J�E���g
		if(mission_opt_1[c_mission] == 1) {
			if(!english) StrCat(string[0], mission_info2_jp[2]);
			else StrCat(string[0], mission_info2_en[2]);
		}
		// ���s����ƃm���}���Z�b�g
		if(mission_opt_1[c_mission] >= 2) {
			if(!english) StrCat(string[0], mission_info2_jp[5]);
			else StrCat(string[0], mission_info2_en[5]);
		}
	}
	
	// �w�{���X�̒ǉ�����
	if(mission_type[c_mission] == 4) {
		// ���s����ƃm���}���Z�b�g
		if(mission_opt_1[c_mission] >= 2) {
			if(!english) StrCat(string[0], mission_info2_jp[6]);
			else StrCat(string[0], mission_info2_en[6]);
		}
	}
	
	// �V���O���̒ǉ�����
	if(mission_type[c_mission] == 11) {
		// �w��ȏ���J�E���g
		if(mission_opt_1[c_mission] == 1) {
			if(!english) StrCat(string[0], mission_info2_jp[0]);
			else StrCat(string[0], mission_info2_en[0]);
		}
		// ���s����ƃm���}���Z�b�g
		if(mission_opt_1[c_mission] >= 2) {
			if(!english) StrCat(string[0], mission_info2_jp[3]);
			else StrCat(string[0], mission_info2_en[3]);
		}
	}
	
	// �R���{�̒ǉ�����
	if(mission_type[c_mission] == 27) {
		if(mission_opt_3[c_mission] >= 1) {
			if(!english) StrCat(string[0], mission_info2_jp[7]);
			else StrCat(string[0], mission_info2_en[7]);
		}
	}
	
	// �u���b�N�I�[�_�[�n�̒ǉ�����
	if( ((mission_type[c_mission] >= 30) && (mission_type[c_mission] <= 33)) || (mission_type[c_mission] == 38) ) {
		if(mission_opt_1[c_mission] >= 1) {
			if(!english) StrCat(string[0], mission_info2_jp[8]);
			else StrCat(string[0], mission_info2_en[8]);
		}
	}
	
	// �V���O���I�[�_�[�̒ǉ�����
	if(mission_type[c_mission] == 31) {
		// �w��ȏ���J�E���g
		if(mission_opt_2[c_mission] == 1) {
			if(!english) StrCat(string[0], mission_info2_jp[0]);
			else StrCat(string[0], mission_info2_en[0]);
		}
		// ���s����ƃm���}���Z�b�g
		if(mission_opt_2[c_mission] >= 2) {
			if(!english) StrCat(string[0], mission_info2_jp[3]);
			else StrCat(string[0], mission_info2_en[3]);
		}
	}
	
	// �_�u���I�[�_�[�̒ǉ�����
	if(mission_type[c_mission] == 32) {
		// �w��ȏ���J�E���g
		if(mission_opt_2[c_mission] == 1) {
			if(!english) StrCat(string[0], mission_info2_jp[1]);
			else StrCat(string[0], mission_info2_en[1]);
		}
		// ���s����ƃm���}���Z�b�g
		if(mission_opt_2[c_mission] >= 2) {
			if(!english) StrCat(string[0], mission_info2_jp[4]);
			else StrCat(string[0], mission_info2_en[4]);
		}
	}
	
	// T-�X�s���_�u���̒ǉ�����
	if(mission_type[c_mission] == 37) {
		// �w��ȏ���J�E���g
		if(mission_opt_1[c_mission] >= 1) {
			if(!english) StrCat(string[0], mission_info2_jp[1]);
			else StrCat(string[0], mission_info2_en[1]);
		}
	}
	
	// �g���v���I�[�_�[���t�g���v���I�[�_�[�̒ǉ�����
	if((mission_type[c_mission] == 33) || (mission_type[c_mission] == 38)) {
		// �w��ȏ���J�E���g
		if(mission_opt_2[c_mission] == 1) {
			if(!english) StrCat(string[0], mission_info2_jp[2]);
			else StrCat(string[0], mission_info2_en[2]);
		}
		// ���s����ƃm���}���Z�b�g
		if(mission_opt_2[c_mission] >= 2) {
			if(!english) StrCat(string[0], mission_info2_jp[5]);
			else StrCat(string[0], mission_info2_en[5]);
		}
	}
	
	// �Ō�̓_�u���ŏ���
	if((mission_end[c_mission] == 2) || (mission_end[c_mission] == 3) || (mission_end[c_mission] == 10))
		StrCat(string[0], mission_final_line[english]);
	
	TextOut(2, string[0]);
	TextLayerOn(2, (5 + moffset) * draw_rate, (40 + 112) * draw_rate);
	
	// �~�b�V�����ꗗ
	tmp = 0;
	count = 0;
	
	while(c_mission - tmp > 4) {
		tmp = tmp + 5;
	}
	
	for(i = tmp; i < (tmp + 5); i++) {
		if(!english) {
			// ���{��
			if(mission_type[i] < 0) {
				tmp2 = (mission_type[i] + 1) * -1;
				StrCpy(string[0], mission_ext_name_jp[tmp2]);
			} else {
				StrCpy(string[0], mission_name_jp[mission_type[i]]);
			}
		} else {
			// English
			if(mission_type[i] < 0) {
				tmp2 = (mission_type[i] + 1) * -1;
				StrCpy(string[0], mission_ext_name_en[tmp2]);
			} else {
				StrCpy(string[0], mission_name_en[mission_type[i]]);
			}
		}
		
		// +
		if(mission_lv[i] >= 15) StrCat(string[0], "+");
		
		TextSize(3 + count, 10 * draw_rate);
		TextColor(3 + count, 0, 0, 0);
		TextBackColorDisable(3 + count);
		TextOut(3 + count, string[0]);
		TextLayerOn(3 + count, (1 + moffset) * draw_rate, (1 + 32 + count * 16) * draw_rate);
		
		count++;
		
		// �I���t���O������ꍇ�͂����Ń��[�v�𔲂���
		if((mission_end[i] != 0) && (mission_end[i] != 10)) break;
	}
}

//������������������������������������������������������������������������������
//  �~�b�V�������[�h�̃m���}�㏸
//������������������������������������������������������������������������������
void missionNormUp(int lines) {
	int i, j;
	int by2, tmp;
	int data[2];
	int player;
	int gap;
	player = 0;
	
	// �_�u��
	if(mission_type[c_mission] == 2)
	{
		if(mission_opt_1[c_mission] == 0) {
			if(lines == 2) c_norm[0]++;
		} else if(mission_opt_1[c_mission] == 1) {
			if(lines >= 2) c_norm[0]++;	// �_�u���ȏ��OK
		} else {
			// ���s����Ƃ�蒼��
			if(lines == 2) {
				c_norm[0]++;
			} else if(c_norm[0]) {
				// REGRET
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
				
				// ��蒼��
				c_norm[0] = 0;
			}
		}
	}
	// �g���v��
	else if(mission_type[c_mission] == 3)
	{
		if(mission_opt_1[c_mission] == 0) {
			if(lines == 3) c_norm[0]++;
		} else if(mission_opt_1[c_mission] == 1) {
			if(lines >= 3) c_norm[0]++;	// �g���v���ȏ��OK
		} else {
			// ���s����Ƃ�蒼��
			if(lines == 3) {
				c_norm[0]++;
			} else if(c_norm[0]) {
				// REGRET
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
				
				// ��蒼��
				c_norm[0] = 0;
			}
		}
	}
	// �w�{���X
	else if(mission_type[c_mission] == 4)
	{
		if(mission_opt_1[c_mission] <= 1) {
			// �ʏ�
			if(lines == 4) c_norm[0]++;
		} else {
			// ���s����Ƃ�蒼��
			if(lines == 4) {
				c_norm[0]++;
			} else if(c_norm[0]) {
				// REGRET
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
				
				// ��蒼��
				c_norm[0] = 0;
			}
		}
	}
	// �T�C�N��
	else if(mission_type[c_mission] == 5)
	{
		if(!cycle[lines - 1]) {
			cycle[lines - 1] = 1;
			c_norm[0]++;
		}
	}
	// �^�[�Q�b�g
	else if(mission_type[c_mission] == 6)
	{
		// �قƂ�ǂ̕�����statErase�ŃN���A��������܂��B
		// �����ł͈ꕔ�̏��������ł��B
		if(getPlatinumBlock(0) == 0) {
			PlaySE(37);
			clear_mission = lines;
			timeOn[0] = 0;
			c_norm[0]++;
		}
	}
	// �C���C�T�[
	else if((mission_type[c_mission] == 7) || (mission_type[c_mission] == 39) || (mission_type[c_mission] == 40))
	{
		if((lines == 4) || (mission_type[c_mission] != 40)) {
			for(i = 0; i < 4; i++) {
				// ���ׂ�Y���W�����߂�
				getBlockData(0, bx[0], by[0], blk[0], rt[0], i, &data);
				by2 = data[1];
				
				// �����ׂ����C�������ׂ�
				for(j = 0; j < eraser_now_lines; j++) {
					if(j >= 4) break;
					
					if( (by2 == eraser_lines[j]) && (erase[by2]) && (!eraser_cleared[j]) ) {
						eraser_cleared[j] = 1;
						c_norm[0]++;
					}
				}
			}
			
			// �S�������Ă���̂Ƀm���}�B�����Ă��Ȃ��ꍇ�͐V���ȃp�^�[���o��
			if(c_norm[0] < m_norm[0]) {
				tmp = 1;
				
				for(i = 0; i < eraser_now_lines; i++) {
					if(!eraser_cleared[i]) {
						tmp = 0;
						break;
					}
				}
				
				if(tmp) {
					eraser_now_pattern++;
					setEraserLines();
				}
			}
		}
	}
	// �V���O��
	else if(mission_type[c_mission] == 11)
	{
		if(mission_opt_1[c_mission] == 0) {
			if(lines == 1) c_norm[0]++;
		} else if(mission_opt_1[c_mission] == 1) {
			if(lines >= 1) c_norm[0]++;	// �_�u���ȏ��OK
		} else {
			// ���s����Ƃ�蒼��
			if(lines == 1) {
				c_norm[0]++;
			} else if(c_norm[0]) {
				// REGRET
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
				
				// ��蒼��
				c_norm[0] = 0;
			}
		}
	}
	// T-�X�s��
	else if(mission_type[c_mission] == 16)
	{
		if(tspin_type) {
			if(IsTspin[0]) c_norm[0]++;
		} else {
			c_norm[0] = c_norm[0] + lines;
		}
	}
	// �ϋv
	else if(mission_type[c_mission] == 23)
	{
		if(ltime[0] <= 0) c_norm[0]++;
	}
	// �S����
	else if(mission_type[c_mission] == 26)
	{
		c_norm[0]++;
	}
	// �R���{
	else if(mission_type[c_mission] == 27)
	{
		if(enable_combo) {
			if(mission_opt_3[c_mission] == 1) c_norm[0] = combo2[0];
			else c_norm[0] = combo[0];
		} else {
			c_norm[0] = c_norm[0] + lines;
		}
	}
	// B to B �w�{���X
	else if(mission_type[c_mission] == 28)
	{
		if(lines == 4) {
			c_norm[0]++;
		} else if(c_norm[0]) {
			// REGRET
			PlaySE(44);
			gup_down[player] = 0;
			gflash[player] = 120;
			
			// ��蒼��
			c_norm[0] = 0;
		}
	}
	// OOBAKA
	else if(mission_type[c_mission] == 29)
	{
		if(lines == 0) c_norm[0]++;
	}
	// �u���b�N�I�[�_�[
	else if(mission_type[c_mission] == 30)
	{
		if( (mission_opt_1[c_mission] == 0) || 
		    ((mission_opt_1[c_mission] >= 1) && (dhold2[0]) && (hold_used[0] >= 2)) )
		{
			if(mission_opt_3[c_mission] <= 6) {
				if(blk[0] == mission_opt_3[c_mission]) c_norm[0] = c_norm[0] + lines;
			} else if(mission_opt_3[c_mission] == 7) {
				if((blk[0] == 1) || (blk[0] == 5)) c_norm[0] = c_norm[0] + lines;
			} else if(mission_opt_3[c_mission] == 8) {
				if((blk[0] == 3) || (blk[0] == 6)) c_norm[0] = c_norm[0] + lines;
			}
		}
	}
	// �V���O���I�[�_�[
	else if(mission_type[c_mission] == 31)
	{
		if( (mission_opt_1[c_mission] == 0) || 
		    ((mission_opt_1[c_mission] >= 1) && (dhold2[0]) && (hold_used[0] >= 2)) )
		{
			if( (lines == 1) || ((mission_opt_2[c_mission] == 1) && (lines >= 1)) ) {
				if(mission_opt_3[c_mission] <= 6) {
					if(blk[0] == mission_opt_3[c_mission]) c_norm[0]++;
				} else if(mission_opt_3[c_mission] == 7) {
					if((blk[0] == 1) || (blk[0] == 5)) c_norm[0]++;
				} else if(mission_opt_3[c_mission] == 8) {
					if((blk[0] == 3) || (blk[0] == 6)) c_norm[0]++;
				}
			} else if((mission_opt_2[c_mission] == 2) && (c_norm[0] > 0)) {
				// REGRET
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
				
				// ��蒼��
				c_norm[0] = 0;
			}
		}
	}
	// �_�u���I�[�_�[
	else if(mission_type[c_mission] == 32)
	{
		if( (mission_opt_1[c_mission] == 0) || 
		    ((mission_opt_1[c_mission] >= 1) && (dhold2[0]) && (hold_used[0] >= 2)) )
		{
			if( (lines == 2) || ((mission_opt_2[c_mission] == 1) && (lines >= 2)) ) {
				if(mission_opt_3[c_mission] <= 6) {
					if(blk[0] == mission_opt_3[c_mission]) c_norm[0]++;
				} else if(mission_opt_3[c_mission] == 7) {
					if((blk[0] == 1) || (blk[0] == 5)) c_norm[0]++;
				} else if(mission_opt_3[c_mission] == 8) {
					if((blk[0] == 3) || (blk[0] == 6)) c_norm[0]++;
				}
			} else if((mission_opt_2[c_mission] == 2) && (c_norm[0] > 0)) {
				// REGRET
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
				
				// ��蒼��
				c_norm[0] = 0;
			}
		}
	}
	// ���g���v���I�[�_�[
	else if(mission_type[c_mission] == 33)
	{
		if( (mission_opt_1[c_mission] == 0) || 
		    ((mission_opt_1[c_mission] >= 1) && (dhold2[0]) && (hold_used[0] >= 2)) )
		{
			if( (lines == 3) || ((mission_opt_2[c_mission] == 1) && (lines >= 3)) ) {
				if(mission_opt_3[c_mission] <= 6) {
					if(blk[0] != mission_opt_3[c_mission]) c_norm[0]++;
				} else if(mission_opt_3[c_mission] == 7) {
					if((blk[0] != 1) && (blk[0] != 5)) c_norm[0]++;
				} else if(mission_opt_3[c_mission] == 8) {
					if((blk[0] != 3) && (blk[0] != 6)) c_norm[0]++;
				}
			} else if((mission_opt_2[c_mission] == 2) && (c_norm[0] > 0)) {
				// REGRET
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
				
				// ��蒼��
				c_norm[0] = 0;
			}
		}
	}
	// �������_�u��
	else if(mission_type[c_mission] == 34)
	{
		if(lines == 2) {
			gap = 0;	// ����������
			j = 0;		// ����������t���O
			
			for(i = 0; i < 22; i++) {
				if(erase[i])
					j++;
				else if(j != 0)
					gap++;
				
				if(j >= lines) break;
			}
			
			if(gap != 0) c_norm[0]++;
		}
	}
	// �������g���v��
	else if(mission_type[c_mission] == 35)
	{
		if(lines == 3) {
			gap = 0;	// ����������
			j = 0;		// ����������t���O
			
			for(i = 0; i < 22; i++) {
				if(erase[i])
					j++;
				else if(j != 0)
					gap++;
				
				if(j >= lines) break;
			}
			
			if(gap != 0) c_norm[0]++;
		}
	}
	// 2�i�����_�u��
	else if(mission_type[c_mission] == 36)
	{
		if(lines == 2) {
			gap = 0;	// ����������
			j = 0;		// ����������t���O
			
			for(i = 0; i < 22; i++) {
				if(erase[i])
					j++;
				else if(j != 0)
					gap++;
				
				if(j >= lines) break;
			}
			
			if(gap == 2) c_norm[0]++;
		}
	}
	// T-�X�s���_�u��
	else if(mission_type[c_mission] == 37)
	{
		if(tspin_type) {
			if( (IsTspin[0]) && ((lines == 2) || ((mission_opt_1[c_mission] >= 1) && (lines >= 2))) )
				c_norm[0]++;
		} else {
			c_norm[0] = c_norm[0] + lines;
		}
	}
	// �g���v���I�[�_�[
	else if(mission_type[c_mission] == 38)
	{
		if( (mission_opt_1[c_mission] == 0) || 
		    ((mission_opt_1[c_mission] >= 1) && (dhold2[0]) && (hold_used[0] >= 2)) )
		{
			if( (lines == 3) || ((mission_opt_2[c_mission] == 1) && (lines >= 3)) ) {
				if(mission_opt_3[c_mission] <= 6) {
					if(blk[0] == mission_opt_3[c_mission]) c_norm[0]++;
				} else if(mission_opt_3[c_mission] == 7) {
					if((blk[0] == 1) || (blk[0] == 5)) c_norm[0]++;
				} else if(mission_opt_3[c_mission] == 8) {
					if((blk[0] == 3) || (blk[0] == 6)) c_norm[0]++;
				}
			} else if((mission_opt_2[c_mission] == 2) && (c_norm[0] > 0)) {
				// REGRET
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
				
				// ��蒼��
				c_norm[0] = 0;
			}
		}
	}
	// �X�N�E�F�A�^�S�[���h�X�N�E�F�A
	else if((mission_type[c_mission] == 41) || (mission_type[c_mission] == 42))
	{
		if(lines == 0) c_norm[0]++;
	}
	// �V���O��SP
	else if(mission_type[c_mission] == -1)
	{
		if(lines == 1) {
			c_norm[0]++;
		} else if(c_norm[0]) {
			// REGRET
			PlaySE(44);
			gup_down[player] = 0;
			gflash[player] = 120;
			
			// ��蒼��
			c_norm[0] = 0;
		}
	}
	// �_�u��SP
	else if(mission_type[c_mission] == -2)
	{
		if(lines == 2) {
			c_norm[0]++;
		} else if(c_norm[0]) {
			// REGRET
			PlaySE(44);
			gup_down[player] = 0;
			gflash[player] = 120;
			
			// ��蒼��
			c_norm[0] = 0;
		}
	}
	// �g���v��SP
	else if(mission_type[c_mission] == -3)
	{
		if(lines == 3) {
			c_norm[0]++;
		} else if(c_norm[0]) {
			// REGRET
			PlaySE(44);
			gup_down[player] = 0;
			gflash[player] = 120;
			
			// ��蒼��
			c_norm[0] = 0;
		}
	}
	// ���x���X�^�[�Ȃ�
	else
	{
		c_norm[0] = c_norm[0] + lines;
	}
	
	// �~�b�V�����N���A
	if(c_norm[0] >= m_norm[0]) {
		c_norm[0] = m_norm[0];
		timeOn[0] = 0;
		clear_mission = lines;
		mission_clear_flag = 1;
		
		// �^�C���x�������~�߂�
		StopWave(38);
		
		// �u�Ō�̃��C�����_�u���ŏ����I�v��B������ƃG�N�X�g���X�e�[�W�i�o���l��
		if( (clear_mission == 2) && 
		    ((mission_end[c_mission] == 2) || (mission_end[c_mission] == 3) || (mission_end[c_mission] == 10)) )
		{
			mission_extra = 1;
			objectCreate(0, 4, Rand(20) + foffset[0] + 68, 20 + Rand(10), 0, 0, 0, 0);
		}
	}
}

//������������������������������������������������������������������������������
//  �~�b�V�����J�n
//������������������������������������������������������������������������������
void missionSetStatus() {
	int i, tmp, player;
	player = 0;
	
	// �m���}�ݒ�
	c_norm[0] = 0;
	m_norm[0] = mission_norm[c_mission];
	mission_clear_flag = 0;
	
	// �^�C��
	ltime[0] = mission_time[c_mission];
	
	// ���x��
	tc[0] = mission_lv[c_mission];
	
	// BGM
	bgmlv = mission_bgm[c_mission];
	
	// �u���b�N��u������
	bdowncnt[0] = 0;
	
	// �r�b�O
	if(mission_type[c_mission] == 1) {
		IsBig[0] = 1;
		n_bx[0] = 2;
	} else {
		IsBig[0] = 0;
		n_bx[0] = 3;
	}
	
	// �T�C�N��
	if(mission_type[c_mission] == 5) {
		for(i = 0; i < 4; i++) cycle[i] = 0;
	}
	
	// �^�[�Q�b�g
	if(mission_type[c_mission] == 6) {
		// �o���t���O������
		for(i = 0; i < 1000; i++) target_cleared[i] = 0;
	}
	
	// �C���C�T�[
	if((mission_type[c_mission] == 7) || (mission_type[c_mission] == 39) || (mission_type[c_mission] == 40)) {
		eraser_now_pattern = 0;
		setEraserLines();
	}
	
	// �A�i�U�[
	if((mission_type[c_mission] == 10) && (mission_opt_3[c_mission])) {
		isblind[0] = 1;
		blind_flag[0] = 1;
	} else {
		isblind[0] = 0;
		blind_flag[0] = 0;
	}
	
	// X-RAY
	if(mission_type[c_mission] == 12) {
		isxray[0] = 1;
		xray_flag[0] = 1;
		xray_counter[0] = 0;
	} else {
		isxray[0] = 0;
		xray_flag[0] = 0;
	}
	
	// �J���[
	if(mission_type[c_mission] == 13) {
		iscolor[0] = 1;
		color_flag[0] = 1;
		color_counter[0] = 0;
	} else {
		iscolor[0] = 0;
		color_flag[0] = 0;
	}
	
	// ���[�����[��
	if(mission_type[c_mission] == 14) {
		rollroll_flag[0] = 1;
		isrollroll[0] = 1;
	} else {
		rollroll_flag[0] = 0;
		isrollroll[0] = 0;
	}
	
	// �~���[
	if(mission_type[c_mission] == 15) {
		isfmirror[0] = 1;
	} else {
		isfmirror[0] = 0;
	}
	
	// ��]�s��
	if(mission_type[c_mission] == 17) {
		isRotateLock[0] = 1;
		
		// �u���b�N�̌����������_���ɂ���
		for(i = 0; i < 6; i++) rt_nblk[i] = GiziRand(0, 4);
	} else {
		isRotateLock[0] = 0;
		
		for(i = 0; i < 6; i++) rt_nblk[i] = 0;
	}
	
	// NEXT�s��
	if(mission_type[c_mission] == 18) {
		ishidenext[0] = 1;
	} else {
		ishidenext[0] = 0;
	}
	
	// DEVIL 800
	if(mission_type[c_mission] == 19) {
		if(mission_opt_1[c_mission]) {
			r_enable[0] = 0;
		} else {
			r_enable[0] = 1;
			r_bdowncnt[0] = 0;
			r_start[0] = 0;
			r_end[0] = 999;
			upLines[0] = 0;
			uplinetype[0] = 0;
			
			if(mission_opt_2[c_mission]) {
				risecount[0] = 0;
				
				if((devil_rise_min[8] > 0) && (devil_rise_max[8] > 0)) {
					do {
						risecount[0] = GiziRand(0, devil_rise_max[8] + 1);
					} while(risecount[0] < devil_rise_min[8]);
				}
			} else {
				r_inter[0] = mission_opt_3[c_mission];
				if(r_inter[0] == 0) r_inter[0] = 20;
			}
		}
	} else {
		r_enable[0] = 0;
	}
	
	// GARBAGE
	if(mission_type[c_mission] == 21) {
		// ���̈ʒu��ݒ�
		ghole[0] = GiziRand(0, 10);
		uplinetype[0] = 4;
		
		// ����グ
		upLines[0] = mission_opt_3[c_mission];
		
		if(upLines[0] > 16 + spawn_y_type * 2) upLines[0] = 16 + spawn_y_type * 2;
	}
	
	// �I�[���h�X�^�C��
	if(mission_type[c_mission] == 22) {
		if(!mission_opt_1[c_mission]) {
			heboGB[0] = 1;
		} else {
			heboGB[0] = 2;
		}
		objectClear();
	} else {
		heboGB[0] = 0;
	}
	
	// �㉺���E�t�]
	if(mission_type[c_mission] == 24) {
		isUDLRreverse[0] = 1;
	} else {
		isUDLRreverse[0] = 0;
	}
	
	// �u���C���h
	if(mission_type[c_mission] == 25) {
		isblind[0] = 1;
		blind_flag[0] = 1;
	}
	
	// �S����
	if((mission_type[c_mission] == 26) && (mission_opt_3[c_mission] == 0)) {
		IsBig[0] = 1;
		n_bx[0] = 2;
	}
	
	// �X�N�E�F�A�^�S�[���h�X�N�E�F�A
	if((mission_type[c_mission] == 41) || (mission_type[c_mission] == 42)) {
		squaremode[0] = 1;
	} else {
		squaremode[0] = 0;
	}
	
	// []
	if((mission_type[c_mission] == 20) || (mission_type[c_mission] == -5) || (mission_type[c_mission] == -6)) {
		always_over1000[0] = 1;
	} else {
		always_over1000[0] = 0;
	}
	
	// ���x�ݒ�𔽉f������
	speedtype[0] = 0;
	
	// �n�C�X�s�[�h�P
	if(mission_type[c_mission] == 8)
	{
		sp[0] = lvTableHiSpeed1[tc[0]];
		wait1[0] = wait1_HiSpeed1;
		wait2[0] = wait2_HiSpeed1;
		wait3[0] = wait3_HiSpeed1;
		waitt[0] = waitt_HiSpeed1;
	}
	// �n�C�X�s�[�h�Q
	else if(mission_type[c_mission] == 9)
	{
		sp[0] = 1200;
		wait1[0] = wait1_HiSpeed2;
		wait2[0] = wait2_HiSpeed2;
		wait3[0] = wait3_HiSpeed2;
		waitt[0] = waitt_HiSpeed2;
	}
	// �A�i�U�[�^�ϋv
	else if((mission_type[c_mission] == 10) || (mission_type[c_mission] == 23))
	{
		sp[0] = 1200;
		
		if(repversw <= 6) {
			wait1[0] = wait1_Acea_tbl6[tc[0]];
			wait2[0] = wait2_Acea_tbl6[tc[0]];
			wait3[0] = wait3_Acea_tbl6[tc[0]];
			waitt[0] = waitt_Acea_tbl6[tc[0]];
		} else if(repversw <= 7) {
			wait1[0] = wait1_Acea_tbl7[tc[0]];
			wait2[0] = wait2_Acea_tbl7[tc[0]];
			wait3[0] = wait3_Acea_tbl7[tc[0]];
			waitt[0] = waitt_Acea_tbl7[tc[0]];
		} else {
			wait1[0] = wait1_Acea_tbl[tc[0]];
			wait2[0] = wait2_Acea_tbl[tc[0]];
			wait3[0] = wait3_Acea_tbl[tc[0]];
			waitt[0] = waitt_Acea_tbl[tc[0]];
		}
	}
	// DEVIL 800
	else if(mission_type[c_mission] == 19)
	{
		sp[0] = 1200;
		
		if(repversw <= 6) {
			wait1[0] = wait1_devil_tbl6[8];
			wait2[0] = wait2_devil_tbl6[8];
			wait3[0] = wait3_devil_tbl6[8];
			waitt[0] = waitt_devil_tbl6[8];
		} else if(repversw <= 7) {
			wait1[0] = wait1_devil_tbl7[8];
			wait2[0] = wait2_devil_tbl7[8];
			wait3[0] = wait3_devil_tbl7[8];
			waitt[0] = waitt_devil_tbl7[8];
		} else {
			wait1[0] = wait1_devil_tbl[8];
			wait2[0] = wait2_devil_tbl[8];
			wait3[0] = wait3_devil_tbl[8];
			waitt[0] = waitt_devil_tbl[8];
		}
	}
	// DEVIL 1200
	else if(mission_type[c_mission] == 20)
	{
		sp[0] = 1200;
		
		if(!mission_opt_3[c_mission]) {
			wait1[0] = wait1_devil_tbl32[12];
			wait2[0] = wait2_devil_tbl32[12];
			wait3[0] = wait3_devil_tbl32[12];
			waitt[0] = waitt_devil_tbl32[12];
		} else {
			if(repversw <= 6) {
				wait1[0] = wait1_devil_tbl6[12];
				wait2[0] = wait2_devil_tbl6[12];
				wait3[0] = wait3_devil_tbl6[12];
				waitt[0] = waitt_devil_tbl6[12];
			} else if(repversw <= 7) {
				wait1[0] = wait1_devil_tbl7[12];
				wait2[0] = wait2_devil_tbl7[12];
				wait3[0] = wait3_devil_tbl7[12];
				waitt[0] = waitt_devil_tbl7[12];
			} else {
				wait1[0] = wait1_devil_tbl[12];
				wait2[0] = wait2_devil_tbl[12];
				wait3[0] = wait3_devil_tbl[12];
				waitt[0] = waitt_devil_tbl[12];
			}
		}
	}
	// �I�[���h�X�^�C��
	else if(mission_type[c_mission] == 22)
	{
		if(!mission_opt_1[c_mission]) {
			tmp = tc[0];
			if(tmp > 14) tmp = 14;
			sp[0] = lvTableHeboGB[tmp];
			wait1[0] = wait1_HeboGB;
			wait2[0] = wait2_HeboGB;
			wait3[0] = wait3_HeboGB_tbl[tmp];
			waitt[0] = waitt_HeboGB_tbl[tmp];
		} else {
			if(tc[0] >= 15) sp[0] = lvTableHeboAC[15];
			else sp[0] = lvTableHeboAC[tc[0]];
			wait1[0] = wait1_HeboAC;
			wait2[0] = wait2_HeboAC;
			wait3[0] = wait3_HeboAC;
			waitt[0] = waitt_HeboAC;
			speedtype[0] = 1;
		}
	}
	// OOBAKA
	else if(mission_type[c_mission] == 29)
	{
		sp[0] = speed_oobaka;
		wait1[0] = wait1_oobaka;
		wait2[0] = wait2_oobaka;
		wait3[0] = wait3_oobaka;
		waitt[0] = waitt_oobaka;
	}
	// BASIC
	else if(mission_type[c_mission] == -4)
	{
		tmp = mission_lv[c_mission];
		if(tmp > 19) tmp = 19;
		
		sp[0] = lvTableAce200Basic[tmp];
		wait1[0] = wait1_Ace200Basic_tbl[tmp];
		wait2[0] = wait2_Ace200Basic_tbl[tmp];
		wait3[0] = wait3_Ace200Basic_tbl[tmp];
		waitt[0] = waitt_Ace200Basic_tbl[tmp];
	}
	// VOID
	else if(mission_type[c_mission] == -5)
	{
		tmp = mission_lv[c_mission];
		if(tmp > 19) tmp = 19;
		
		sp[0] = 1200;
		wait1[0] = wait1_Ace200Void_tbl[tmp];
		wait2[0] = wait2_Ace200Void_tbl[tmp];
		wait3[0] = wait3_Ace200Void_tbl[tmp];
		waitt[0] = waitt_Ace200Void_tbl[tmp];
	}
	// FINAL
	else if(mission_type[c_mission] == -6)
	{
		tmp = mission_lv[c_mission];
		if(tmp > 9) tmp = 9;
		
		sp[0] = 1200;
		if(repversw <= 4) {
			wait1[0] = wait1_final4[tmp];
			wait2[0] = wait2_final4[tmp];
			wait3[0] = wait3_final4[tmp];
			waitt[0] = waitt_final4[tmp];
		} else {
			if(rule_lock_reset[rots[0]]) {
				wait1[0] = wait1_final_srs[tmp];
				wait2[0] = wait2_final_srs[tmp];
				wait3[0] = wait3_final_srs[tmp];
				waitt[0] = waitt_final_srs[tmp];
			} else {
				wait1[0] = wait1_final_ars[tmp];
				wait2[0] = wait2_final_ars[tmp];
				wait3[0] = wait3_final_ars[tmp];
				waitt[0] = waitt_final_ars[tmp];
			}
		}
	}
	// ���x�Œ�
	else if(mission_type[c_mission] == -7)
	{
		wait1[0] = mission_opt_1[c_mission];
		wait2[0] = mission_opt_2[c_mission];
		wait3[0] = mission_opt_3[c_mission];
		waitt[0] = mission_opt_4[c_mission];
		
		if(mission_opt_5[c_mission] >= 999) {
			sp[0] = 1200;
		} else {
			sp[0] = mission_opt_5[c_mission];
		}
	}
	// ���̑�
	else
	{
		if(mission_lv[c_mission] >= 15) {
			sp[0] = 1200;
			
			if(repversw <= 6) {
				wait1[0] = wait1_Acea_tbl6[mission_lv[c_mission] - 15];
				wait2[0] = wait2_Acea_tbl6[mission_lv[c_mission] - 15];
				wait3[0] = wait3_Acea_tbl6[mission_lv[c_mission] - 15];
				waitt[0] = waitt_Acea_tbl6[mission_lv[c_mission] - 15];
			} else if(repversw <= 7) {
				wait1[0] = wait1_Acea_tbl7[mission_lv[c_mission] - 15];
				wait2[0] = wait2_Acea_tbl7[mission_lv[c_mission] - 15];
				wait3[0] = wait3_Acea_tbl7[mission_lv[c_mission] - 15];
				waitt[0] = waitt_Acea_tbl7[mission_lv[c_mission] - 15];
			} else {
				wait1[0] = wait1_Acea_tbl[mission_lv[c_mission] - 15];
				wait2[0] = wait2_Acea_tbl[mission_lv[c_mission] - 15];
				wait3[0] = wait3_Acea_tbl[mission_lv[c_mission] - 15];
				waitt[0] = waitt_Acea_tbl[mission_lv[c_mission] - 15];
			}
		} else {
			if(repversw >= 2) sp[0] = lvTableAce[mission_lv[c_mission]];
			else if(repversw == 1) sp[0] = lvTableAce1[mission_lv[c_mission]];
			else sp[0] = lvTableAceOld[mission_lv[c_mission]];
			wait1[0] = wait1_Ace;
			wait2[0] = wait2_Ace;
			wait3[0] = wait3_Ace;
			waitt[0] = waitt_Ace;
		}
	}
}

//������������������������������������������������������������������������������
//  �C���C�T�[�֘A
//������������������������������������������������������������������������������

// ����������
void setEraserLines() {
	int i, tmp, min, max, tmp2;
	int line[22];	// ���C���̏d���h�~�p
	
	eraser_now_lines = 0;
	
	// �o���͈͂����߂�
	min = mission_opt_1[c_mission];
	max = mission_opt_2[c_mission];
	
	if(min < 3) min = 3;
	if(max > 21) max = 21;
	
	if(min > max) {
		min = i;
		min = max;
		i = max;
	}
	
	if(mission_type[c_mission] == 39) {
		// �C���C�T�[�Q
		eraser_lines[0] = min;
		eraser_lines[1] = max;
		eraser_cleared[0] = 0;
		eraser_cleared[1] = 0;
		eraser_now_lines = 2;
	} else {
		for(i = 0; i < 22; i++) line[i] = 0;
		
		if(eraser_now_pattern == 0) tmp2 = mission_opt_3[c_mission];
		else if(eraser_now_pattern == 1) tmp2 = mission_opt_4[c_mission];
		else if(eraser_now_pattern == 2) tmp2 = mission_opt_5[c_mission];
		else tmp2 = mission_opt_6[c_mission];
		
		for(i = 0; i <= tmp2; i++) {
			// �ő�4�{�܂�
			if(i >= 4) break;
			
			// �]���ȃ��C�����o���Ȃ�
			if(i >= mission_norm[c_mission] - c_norm[0]) break;
			
			eraser_now_lines++;
			
			if(min == max) {
				// �ʒu�Œ�
				tmp = min;
			} else if((i >= mission_norm[c_mission] - c_norm[0] - 1) && (mission_norm[c_mission] > 1) && (!line[min + 1])) {
				// �Ō��1�{
				tmp = min + 1;
			} else {
				// �����_��
				do {
					tmp = GiziRand(0, 22);
				} while( (tmp < min) || (tmp > max) || (line[tmp] == 1) );
			}
			
			line[tmp] = 1;
			eraser_lines[i] = tmp;
			eraser_cleared[i] = 0;
		}
	}
}

// �C���C�T�[�̐���\��
void viewEraserLines() {
	int i;
	
	for(i = 0; i < eraser_now_lines; i++) {
		if(mission_type[c_mission] == 40)
			ExBltRect(4, (boffset[0] - 1) * 8, (eraser_lines[i] + 3) * 8, 0, 176 + eraser_cleared[i] * 8, 95, 8);
		else
			ExBltRect(4, (boffset[0] - 1) * 8, (eraser_lines[i] + 3) * 8, 0, eraser_cleared[i] * 8, 95, 8);
	}
}

// �^�[�Q�b�g�̃X�e�[�W�̓ǂݍ���
void loadTargetStage() {
	int tmp, min, max, isflash;
	
	if((!mission_opt_7[c_mission]) || (c_norm[0] < mission_opt_7[c_mission])) {
		// �p�^�[��1
		min = mission_opt_1[c_mission];
		max = mission_opt_2[c_mission];
		isflash = mission_opt_3[c_mission];
	} else {
		// �p�^�[��2
		min = mission_opt_8[c_mission];
		max = mission_opt_9[c_mission];
		isflash = mission_opt_10[c_mission];
	}
	
	if(min == max) {
		// �X�e�[�W��1�����̏ꍇ
		tmp = min;
	} else {
		do {
			tmp = GiziRand(0, max + 1);
		} while((tmp < min) || (target_cleared[tmp] != 0));
	}
	
	target_cleared[tmp] = 1;
	loadTomoyoStage(0, tmp, isflash);
	
	// �S�Ẵu���b�N���v���`�i�ɂ���
	if(mission_opt_6[c_mission]) {
		TransformAllBlockToPlatinumBlock();
	}
	// �v���`�i�u���b�N�̔z�u�������_���ɂ���
	else if(mission_opt_4[c_mission]) {
		RandmizePlatinumBlock(mission_opt_4[c_mission], mission_opt_5[c_mission]);
	}
	
	// ����オ��^�C�v�ݒ�
	uplinetype[0] = 2;
}

// �v���`�i�u���b�N�̔z�u�������_���ɂ���
void RandmizePlatinumBlock(int randmax, int opt) {
	int i, j, k, pblk;
	int line[22];
	pblk = 0;
	
	if(opt) {
		pblk = opt;
		i = 22 - checkFieldTop(0);	// �t���[�Y�΍�
		if(pblk > i) pblk = i;
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
	}
}

// �S�Ẵu���b�N���v���`�i�u���b�N�ɂ���
void TransformAllBlockToPlatinumBlock() {
	int i;
	
	for(i = 0; i < 220; i++) {
		if(fld[i] != 0) fld[i] = 11 + Rand(7);
	}
}

//������������������������������������������������������������������������������
//  ���f�[�^�̓ǂݍ��݁^�ۑ�
//������������������������������������������������������������������������������
/* ���[�h */
void loadMissionData(int number) {
	int i, temp[4];
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	sprintf(string[0], "stage/mission%02d.sav", number);
	
	LoadFile(string[0], &saveBuf, 624 * 4);
	
	mission_hide_info = saveBuf[1];
	mission_clear_anim = saveBuf[2];
	
	// ���f�[�^��ǂݍ���
	for(i = 0; i < 30; i++) {
		mission_type[i]   = saveBuf[(i + 1) * 20 +  0];	// ���
		mission_norm[i]   = saveBuf[(i + 1) * 20 +  1];	// �m���}
		mission_time[i]   = saveBuf[(i + 1) * 20 +  2];	// ��������
		mission_end[i]    = saveBuf[(i + 1) * 20 +  3];	// �I���t���O
		mission_lv[i]     = saveBuf[(i + 1) * 20 +  4];	// ���x��
		mission_erase[i]  = saveBuf[(i + 1) * 20 +  5];	// �N���A���ɏォ��������郉�C����
		mission_opt_1[i]  = saveBuf[(i + 1) * 20 +  6];	// �ǉ����P
		mission_opt_2[i]  = saveBuf[(i + 1) * 20 +  7];	// �ǉ����Q
		mission_opt_3[i]  = saveBuf[(i + 1) * 20 +  8];	// �ǉ����R
		mission_bgm[i]    = saveBuf[(i + 1) * 20 +  9];	// BGM
		mission_opt_4[i]  = saveBuf[(i + 1) * 20 + 10];	// �ǉ����S
		mission_opt_5[i]  = saveBuf[(i + 1) * 20 + 11];	// �ǉ����T
		mission_opt_6[i]  = saveBuf[(i + 1) * 20 + 12];	// �ǉ����U
		mission_bg[i]     = saveBuf[(i + 1) * 20 + 13];	// �w�i
		mission_opt_7[i]  = saveBuf[(i + 1) * 20 + 14];	// �ǉ����V
		mission_opt_8[i]  = saveBuf[(i + 1) * 20 + 15];	// �ǉ����W
		mission_opt_9[i]  = saveBuf[(i + 1) * 20 + 16];	// �ǉ����X
		mission_opt_10[i] = saveBuf[(i + 1) * 20 + 17];	// �ǉ����10
	}
	
	// �R�[�X����ǂݍ���
	if(saveBuf[0] == 2) {
		temp[0] = saveBuf[620];
		temp[1] = saveBuf[621];
		temp[2] = saveBuf[622];
		temp[3] = saveBuf[623];
		StrCpy(mission_course_name, &temp);
	} else {
		StrCpy(mission_course_name, "");
	}
}

/* �Z�[�u */
void saveMissionData(int number) {
	int i, temp[4];
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	// �w�b�_
	saveBuf[0] = 2;
	saveBuf[1] = mission_hide_info;
	saveBuf[2] = mission_clear_anim;
	
	// ���f�[�^
	for(i = 0; i < 30; i++) {
		saveBuf[(i + 1) * 20 +  0] = mission_type[i];	// ���
		saveBuf[(i + 1) * 20 +  1] = mission_norm[i];	// �m���}
		saveBuf[(i + 1) * 20 +  2] = mission_time[i];	// ��������
		saveBuf[(i + 1) * 20 +  3] = mission_end[i];	// �I���t���O
		saveBuf[(i + 1) * 20 +  4] = mission_lv[i];		// ���x��
		saveBuf[(i + 1) * 20 +  5] = mission_erase[i];	// �N���A���ɏォ��������郉�C����
		saveBuf[(i + 1) * 20 +  6] = mission_opt_1[i];	// �ǉ����P
		saveBuf[(i + 1) * 20 +  7] = mission_opt_2[i];	// �ǉ����Q
		saveBuf[(i + 1) * 20 +  8] = mission_opt_3[i];	// �ǉ����R
		saveBuf[(i + 1) * 20 +  9] = mission_bgm[i];	// BGM
		saveBuf[(i + 1) * 20 + 10] = mission_opt_4[i];	// �ǉ����S
		saveBuf[(i + 1) * 20 + 11] = mission_opt_5[i];	// �ǉ����T
		saveBuf[(i + 1) * 20 + 12] = mission_opt_6[i];	// �ǉ����U
		saveBuf[(i + 1) * 20 + 13] = mission_bg[i];		// �w�i
		saveBuf[(i + 1) * 20 + 14] = mission_opt_7[i];	// �ǉ����V
		saveBuf[(i + 1) * 20 + 15] = mission_opt_8[i];	// �ǉ����W
		saveBuf[(i + 1) * 20 + 16] = mission_opt_9[i];	// �ǉ����X
		saveBuf[(i + 1) * 20 + 17] = mission_opt_10[i];	// �ǉ����10
	}
	
	// �R�[�X����ۑ�
	if(StrLen(mission_course_name) > 0) {
		StrCpy(&temp, mission_course_name);
		saveBuf[620] = temp[0];
		saveBuf[621] = temp[1];
		saveBuf[622] = temp[2];
		saveBuf[623] = temp[3];
	}
	
	sprintf(string[0], "stage/mission%02d.sav", number);
	SaveFile(string[0], &saveBuf, 624 * 4);
}
