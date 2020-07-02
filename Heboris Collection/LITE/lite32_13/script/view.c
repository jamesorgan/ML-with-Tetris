//������������������������������������������������������������������������������
//   �f����ʂł̑����
//������������������������������������������������������������������������������
void showControl() {
	int		zx, zy, bai;

	// ���o�[�̃J�o�[����
	BltRect(3, coffset + 6, 126, 198, 38, 20, 20);

	// �{�^��
	BltRect(3, coffset + 30, 126, 224 + getPressState(0, 4) * 32, 0, 32, 32);
	BltRect(3, coffset + 50, 132, 224 + getPressState(0, 5) * 32, 0, 32, 32);
	BltRect(3, coffset + 70, 138, 224 + getPressState(0, 6) * 32, 0, 32, 32);
	BltRect(3, coffset + 30, 144, 224 + getPressState(0, 7) * 32, 0, 32, 32);

	// ���o�[
	zx = - getPressState(0, 2) + getPressState(0, 3);
	zy = - getPressState(0, 0) + getPressState(0, 1);
	bai = 10 + ((!zx) || (!zy)) * 4;

	BltRect(3, coffset + zx * bai, 120 + zy * bai, 192, 0, 32, 32);
}

//������������������������������������������������������������������������������
//  ��HIDDEN����
//������������������������������������������������������������������������������
void hiddenProc(int player) {
	if(hidden_old[player] == 0) {
		if(hiddeny[player] < 22)
			hiddeny[player]++;
	}

	if(hidden_old[player] == 1) {
		hiddentm[player]++;
		if(hiddentm[player] > (24 - hiddeny[player]) * 120) {
			hiddentm[player] = 0;
			hiddeny[player]--;
			if(hiddeny[player] < 7)
				hiddeny[player] = 7;
			else
				hiddenc[player] = 0;
		}
	}

	if(hidden_old[player] == 2) {
		hiddentm[player]++;
		if(hiddentm[player] > (23 - hiddeny[player]) * 100) {
			hiddentm[player] = 0;
			hiddeny[player]--;
			if(hiddeny[player] < 5)
				hiddeny[player] = 5;
			else
				hiddenc[player] = 0;
		}
	}

	if(hidden_old[player] == 3) {
		hiddentm[player]++;
		if(hiddentm[player] > (22 - hiddeny[player]) * 60 + 60) {
			hiddentm[player] = 0;
			hiddeny[player]--;
			if(hiddeny[player] < 3)
				hiddeny[player] = 3;
			else
				hiddenc[player] = 0;
		}
	}

	if(hidden_old[player] == 4) {
		hiddentm[player]++;
		if(hiddentm[player] > (22 - hiddeny[player]) * 30 + 45) {
			hiddentm[player] = 0;
			hiddeny[player]--;
			if(hiddeny[player] < 3)
				hiddeny[player] = 3;
			else
				hiddenc[player] = 0;
		}
	}

	if(hidden_old[player] == 5) {
		hiddentm[player]++;
		if(hiddentm[player] > (22 - hiddeny[player]) * 10 + 30) {
			hiddentm[player] = 0;
			hiddeny[player]--;
			if(hiddeny[player] < 3)
				hiddeny[player] = 3;
			else
				hiddenc[player] = 0;
		}
	}

	if(hidden_old[player] == 6) {
		hiddentm[player]++;
		if(hiddentm[player] > (((22 - hiddeny[player]) * 2) + 15)) {
			hiddentm[player] = 0;
			hiddeny[player]--;
			if(hiddeny[player] < 3)
				hiddeny[player] = 3;
			else
				hiddenc[player] = 0;
		}
	}

	if(hidden_old[player] == 7) {
		hiddentm[player]++;
		if(hiddentm[player] > ((22 - hiddeny[player]) + 15)) {
			hiddentm[player] = 0;
			hiddeny[player]--;
			if(hiddeny[player] < 0)
				hiddeny[player] = 0;
			else
				hiddenc[player] = 0;
		}
	}
}

//������������������������������������������������������������������������������
//   ��]�@�������擾 (string[0]�Ɋi�[���Ă���܂�)
//������������������������������������������������������������������������������
void getRuleName(int player) {
	if(rule_name == 0) StrCpy(string[0], rule_name_old[rots[player]]);
	if(rule_name == 1) StrCpy(string[0], rule_name_normal[rots[player]]);
	if(rule_name == 2) StrCpy(string[0], rule_name_new[rots[player]]);
}

void getRuleNameEx(int rule, int number) {
	if(rule_name == 0) StrCpy(string[number], rule_name_old[rule]);
	if(rule_name == 1) StrCpy(string[number], rule_name_normal[rule]);
	if(rule_name == 2) StrCpy(string[number], rule_name_new[rule]);
}

//������������������������������������������������������������������������������
//   ���[�h�����擾 (string[0]�Ɋi�[���Ă���܂�)
//������������������������������������������������������������������������������
void getModeName(int player) {
	StrCpy(string[0], mode_name[gameMode[player]]);
}

void getModeNameEx(int mode, int number) {
	StrCpy(string[number], mode_name[mode]);
}

//������������������������������������������������������������������������������
//   �^�C�������ԕ\�L�ɂ��� (string[0]�Ɋi�[���Ă���܂�)
//������������������������������������������������������������������������������
void getTime(int time) {
	if(time < 0) time = 0;
	sprintf(string[0], "%02d:%02d:%02d", time / 3600, (time / 60) % 60, (time % 60) * 5 / 3);
}

// getTime�̊g���o�[�W����
// time  �F���ԕ\�L�ɂ��������l
// number�F�ǂ�string�ϐ��Ɋi�[���邩
// small �F1�ɂ���Ə������o�[�W�����A2�ɂ���Ə����_�ȉ��̂�
void getTimeEx(int time, int number, int small) {
	if(time < 0) time = 0;
	
	if(small == 1) {
		sprintf(string[number], "%d:%02d", time / 3600, (time / 60) % 60);
	} else if(small == 2) {
		sprintf(string[number], ".%02d", (time % 60) * 5 / 3);
	} else {
		sprintf(string[number], "%02d:%02d:%02d", time / 3600, (time / 60) % 60, (time % 60) * 5 / 3);
	}
}

//������������������������������������������������������������������������������
//   �t�B�[���h�^�C�}�[����
//������������������������������������������������������������������������������
void disableShadowTimer(int player) {
	int i;
	
	for(i = 0; i < 220; i++) {
		if(fld[i + player * 220]) fldt[i + player * 220] = -1;
	}
}

//������������������������������������������������������������������������������
//   �i�ʂ��摜�ŕ\��
//������������������������������������������������������������������������������
void drawGradeImage(int x, int y, int number, int type) {
	if(type == 0) {
		// MASTER-NORMAL & MASTER-HARD
		if(number == 32)				// GM
			BltRect(21, x, y, 270, ((count % 4 / 2) * 216) + 120, 90, 48);
		else if(number >= 27)			// M�`MM
			BltRect(21, x, y, 270, ((count % 4 / 2) * 216) + ((number - 27) * 24), 90, 24);
		else if(number >= 18)			// m1�`m9
			BltRect(21, x, y, 180, ((count % 4 / 2) * 216) + ((number - 18) * 24), 90, 24);
		else if(number >= 9)			// S1�`S9
			BltRect(21, x, y,  90, ((count % 4 / 2) * 216) + ((number -  9) * 24), 90, 24);
		else							// 9�`1
			BltRect(21, x, y,   0, ((count % 4 / 2) * 216) + (number * 24), 90, 24);
	} else if(type == 3) {
		// MASTER-EASY
		if(number <= 8)					// 9�`1
			BltRect(21, x, y,   0, ((count % 4 / 2) * 216) + (number * 24), 90, 24);
		else if(number <= 17)			// S1�`S9
			BltRect(21, x, y,  90, ((count % 4 / 2) * 216) + ((number - 9) * 24), 90, 24);
		else							// GM
			BltRect(21, x, y, 270, ((count % 4 / 2) * 216) + 120, 90, 48);
	} else {
		// DEVIL-HARD & DEVIL-DOOM
		if(number == 0)					// 1
			BltRect(21, x, y,   0, ((count % 4 / 2) * 216) + 192, 90, 24);
		else if(number < 10)			// S1�`S9
			BltRect(21, x, y,  90, ((count % 4 / 2) * 216) + ((number -  1) * 24), 90, 24);
		else if(number < 14)			// S10�`S13
			BltRect(21, x, y, 360, ((count % 4 / 2) * 216) + ((number - 10) * 24), 90, 24);
		else if(type == 1)				// GM
			BltRect(21, x, y, 270, ((count % 4 / 2) * 216) + 120, 90, 48);
		else							// GOD(�l�\)
			BltRect(21, x, y, 360, ((count % 4 / 2) * 216) + 96, 90, 72);
	}
}

//������������������������������������������������������������������������������
//   �i�ʂ̕\�������擾
//������������������������������������������������������������������������������
void getGradeString(int number, int type, int strno) {
	if(type == 0) {
		// MASTER
		if((number >= 0) && (number <= 32))
			StrCpy(string[strno], gname[number]);
		else
			StrCpy(string[strno], "???");
	} else if(type == 1) {
		// DEVIL-HARD
		if((number >= 0) && (number <= 14))
			StrCpy(string[strno], dgname2[number]);
		else
			StrCpy(string[strno], "???");
	} else if(type == 2) {
		// DEVIL-DOOM
		if((number >= 0) && (number <= 14))
			StrCpy(string[strno], dgname[number]);
		else
			StrCpy(string[strno], "???");
	} else if(type == 3) {
		// MASTER-EASY
		if((number >= 0) && (number <= 18))
			StrCpy(string[strno], sgname[number]);
		else
			StrCpy(string[strno], "???");
	} else {
		// ����
		StrCpy(string[strno], "INVALID");
	}
}

//������������������������������������������������������������������������������
//   �Â��^�C�g���w�i��\��
//������������������������������������������������������������������������������
void viewDarkTitle() {
	if(!skip_viewbg) BltFast(51, 0, 0);
}

//������������������������������������������������������������������������������
//   �w�i�\��
//������������������������������������������������������������������������������
void viewBack() {
	int i, j, no;
	
	no = backno;
	if((no >= 12) && (no <= 14) && (background_compatibility)) no = 11;
	
	if(back_mov_f[no] == 0) {
		// �Î~��
		BltFastRect(60 + no, 0, 0, 0, 0, 320, 240);
	} else {
		// ����
		BltFastRect(60 + no, 0, 0, (back_acnt / 10) * 320, (back_acnt % 10) * 240, 320, 240);
		
		if(count % back_mov_inter[no] == 0)
			back_acnt++;
		
		if(back_acnt > back_mov_f[no] - 1)
			back_acnt = 0;
	}
	
	// �w�i�؂�ւ�
	if(bgfadesw && !demo) {
		if(enable_bgfade) {
			// �t�F�[�h�L��
			if(bgfadelv < 14) {
				bgfadelv++;
				
				// �t�F�[�h�摜��`��
				for(i = 0; i < 5; i++) {
					for(j = 0; j < 5; j++) {
						BltRect(50, i * 64, j * 48, 0, bgfadelv * 48, 64, 48);
					}
				}
				
				if(bgfadelv == 6) {
					if(gameMode[0] == 8) {
						// MISSION
						if(mission_bg[c_mission]) {
							backno = mission_bg[c_mission] - 1;
						} else if((mission_end[c_mission - 1] == 3) || (c_mission == 29)) {
							backno = 0;
						} else {
							backno++;
							if(backno > 14) backno = 0;
						}
					} else {
						// ���̔w�i��
						backno++;
						if(backno > 14) backno = 0;
					}
					back_acnt = 0;
				}
			} else {
				bgfadesw = 0;
				bgfadelv = 0;
			}
		} else {
			// �t�F�[�h����
			backno++;
			if(backno > 14) backno = 0;
			back_acnt = 0;
			bgfadesw = 0;
		}
	}
}

//������������������������������������������������������������������������������
//   �X�R�A�\��
//������������������������������������������������������������������������������

// �ʏ탂�[�h
void viewScoreNormal(int player) {
	int		i, ii, color, color2, so_far;
	
	color = (count % 4 / 2) * (sp[player] >= 1200) * digitc[rots[player]];
	
	/* �X�R�A */
	if( sc[player] > 9999999 ) sc[player] = 9999999;
	if(!hide_score) {
		printScoreFont(soffset[player], 4 + top_frame, "SCORE", fontc[rots[player]]);
		sprintf(string[0], "%d", sc[player]);
		printScoreFont(soffset[player], 5 + top_frame, string[0], color);
	}
	
	// �i��
	if( ((gameMode[player] == 1) || (gameMode[player] == 2)) && (gradetype[player] != 1) && (!hide_grade) ) {
		if(gflash[player]) color2 = (count % 4 / 2) * (gflash[player] != 0) * fontc[rots[player]];
		else color2 = color;
		
		printScoreFont(soffset[player], 7 + top_frame, "GRADE", fontc[rots[player]]);
		if(gradetype[player] == 2) getGradeString(grade[player], 3, 0);
		else getGradeString(grade[player], 0, 0);
		printScoreFont(soffset[player], 8 + top_frame, string[0], color2);
		
		if((show_gpoint) && (gradetype[player] == 0)) {
			sprintf(string[0], "%d", gpoint[player]);
			printScoreFont(soffset[player], 6 + top_frame, string[0], color);
		}
		
		if((gradetype[player] == 2) && (grade[player] < 17)) {
			sprintf(string[0], "%d", master_easy_score_table[grade[player]]);
			printScoreFont(soffset[player], 6 + top_frame, string[0], color);
		}
	}
	
	// �F��i�ʁ^�����i��
	if((gameMode[player] == 1) && (gradetype[player] == 1) && (user_enable[player])) {
		if(!examination[player]) {
			if(!maxPlay) printScoreFont(soffset[player], 7 + top_frame, "ADMIT GRADE", fontc[rots[player]]);
			else printScoreFont(soffset[player], 7 + top_frame, "ADMIT", fontc[rots[player]]);
			getGradeString(user_master_hard_admit[player], 0, 0);
			printScoreFont(soffset[player], 8 + top_frame, string[0], color);
		} else {
			printScoreFont(soffset[player], 7 + top_frame, "QUALIFY", fontc[rots[player]]);
			getGradeString(exam_grade[player], 0, 0);
			printScoreFont(soffset[player], 8 + top_frame, string[0], color);
		}
	}
	
	// DEVIL-DOOM�i��
	if((gameMode[player] == 3) && (!hide_grade)) {
		if(gflash[player]) color2 = (count % 4 / 2) * (gflash[player] != 0) * fontc[rots[player]];
		else color2 = color;
		
		printScoreFont(soffset[player], 7 + top_frame, "GRADE", fontc[rots[player]]);
		getGradeString(grade[player], 2, 0);
		printScoreFont(soffset[player], 8 + top_frame, string[0], color2);
	}
	
	// DEVIL-HARD�i��
	if((gameMode[player] == 16) && (!hide_grade)) {
		if(gflash[player]) color2 = (count % 4 / 2) * (gflash[player] != 0) * fontc[rots[player]];
		else color2 = color;
		
		printScoreFont(soffset[player], 7 + top_frame, "GRADE", fontc[rots[player]]);
		getGradeString(grade[player], 1, 0);
		printScoreFont(soffset[player], 8 + top_frame, string[0], color2);
	}
	
	/* ���x�� */
	printScoreFont(soffset[player], 20, "LEVEL", fontc[rots[player]]);
	
	// ���q
	if(tc[player] == -1)
		sprintf(string[0], "%3d", 0);	// -1�Ȃ�0�ƕ\��
	else
		sprintf(string[0], "%3d", tc[player]);
	
	printScoreFont(soffset[player], 21, string[0], color);
	
	// ����
	BltRect(3, (soffset[player] * 8) + 2, 178, 38, 34, 24, 3);
	if(sp[player] <= 600) {
		BltFastRect(3, (soffset[player] * 8) + 3, 179, 60 - ((sp[player] * 24) / 660), 37, 22, 1);
	} else {
		BltFastRect(3, (soffset[player] * 8) + 3, 179, 38, 37, 22, 1);
	}
	
	// ����
	if(ending[player]) {
		sprintf(string[0], "%3d", tc[player]);
	} else if((gameMode[player] == 0) || (gameMode[player] == 3) || (gameMode[player] == 16)) {
		// BEGINNER��DEVIL
		sprintf(string[0], "%3d", tc[player] / 100 * 100 + 100);
	} else {
		// BEGINNER��DEVIL�ȊO
		sprintf(string[0], "%3d", tc[player] / 100 * 100 + 100 - ((tc[player] >= 900) && (timeattack[player])));
	}
	printScoreFont(soffset[player], 23, string[0], color);
	
	/* ���x */
	if(disp_waits) {
		printScoreFont(soffset[player], 25, "WAITS", fontc[rots[player]]);
		sprintf(string[0], "%2d %2d", wait1[player], wait2[player]);
		printScoreFont(soffset[player], 26, string[0], color);
		sprintf(string[0], "%2d %2d", wait3[player], waitt[player]);
		printScoreFont(soffset[player], 27, string[0], color);
		sprintf(string[0], "%d", sp[player]);
		printScoreFont(soffset[player], 28, string[0], color);
	}
	
	/* �^�C�� */
	if((gameMode[player] == 5) && (p_timelimit > 0) && (timeOn[player])) {
		if(ltime[player] <= 10 * 60)
			color2 = (ltime[player] != 0) * 2;
		else
			color2 = color;
		
		getTime(ltime[player]);
		printBIGFont(foffset[player], 216, string[0], color2);
	} else {
		if(gameTimer[player] > 359999) gameTimer[player] = 359999;
		getTime(gameTimer[player]);
		printBIGFont(foffset[player], 216, string[0], color);
	}
	
	/* ���_�� */
	if((medal_st[player] != 0) && (medal_visible_st[player] != 0))
		BltRect(0, soffset[player] * 8 + 2     , 116, 16, medal_st[player] * 12, 16, 12);
	
	if((medal_ac[player] != 0) && (medal_visible_ac[player] != 0))
		BltRect(0, soffset[player] * 8 + 2 + 16, 116,  0, medal_ac[player] * 12, 16, 12);
	
	if((medal_co[player] != 0) && (medal_visible_co[player] != 0))
		BltRect(0, soffset[player] * 8 + 2     , 129, 48, medal_co[player] * 12, 16, 12);
	
	if((medal_sk[player] != 0) && (medal_visible_sk[player] != 0))
		BltRect(0, soffset[player] * 8 + 2 + 16, 129, 32, medal_sk[player] * 12, 16, 12);
	
	// �Z�N�V�����^�C���\��
	if((maxPlay == 0) && (show_section_time != 0)) {
		for(i = 0; i < 13; i++) {
			if(now_sttime[i + player * 30] > 0) {
				// ���x��
				if((i == 9) && (tc[player] == 999)) {
					sprintf(string[0], "%4d", 999);
				} else {
					sprintf(string[0], "%4d", (i + 1) * 100);
				}
				printScoreFont(section_time_offset, i * 2 + 5, string[0], fontc[rots[player]]);
				
				// ���B�^�C��
				if(show_section_time != 2) {
					so_far = 0;
					for(ii = 0; ii <= i; ii++) {
						so_far = so_far + now_sttime[ii + player * 30];
					}
					getTime(so_far);
					printScoreFont(section_time_offset + 5, i * 2 + 5, string[0], color);
				}
				
				// �Z�N�V�����^�C��
				if(show_section_time >= 2) {
					getTime(now_sttime[i + player * 30]);
					printScoreFont(section_time_offset + 5, i * 2 + 5 + (show_section_time == 3), string[0], color);
				}
			}
		}
	}
	
	if(tspin_frame[player]) {
		// T-SPIN
		if((bonus_tspin) && (tspin_frame[player] <= 60) && (gameMode[player] != 0)) {
			if(lasttspin[player] != 0)
				printScoreFont(toffset[player] + 4, 26, "e  4", (count % 4 / 2) * digitc[rots[player]]);
		} else {
			if(lasttspin[player] == 0)
				printScoreFont(toffset[player] + 3, 26, "T-SPIN", (count % 4 / 2) * digitc[rots[player]]);
			if(lasttspin[player] == 1)
				printScoreFont(toffset[player] - 1, 26, "T-SPIN SINGLE!", (count % 4 / 2) * digitc[rots[player]]);
			if(lasttspin[player] == 2)
				printScoreFont(toffset[player] - 1, 26, "T-SPIN DOUBLE!", (count % 4 / 2) * digitc[rots[player]]);
			if(lasttspin[player] == 3)
				printScoreFont(toffset[player] - 1, 26, "T-SPIN TRIPLE!", (count % 4 / 2) * digitc[rots[player]]);
		}
	} else if((gflash[player] > 0) && (gradetype[player] != 2)) {
		// COOL / REGRET
		if(gup_down[player]) {
			if((gameMode[player] != 3) && (gameMode[player] != 16))
				printScoreFont(toffset[player] + 3, 26, "COOL!!", (count % 4 / 2) * digitc[rots[player]]);
		} else {
			printScoreFont(toffset[player] + 3, 26, "REGRET", (count % 4 / 2) * digitc[rots[player]]);
		}
	} else if(playback) {
		// REPLAY
		if(count % 80 >= 20) printScoreFont(toffset[player] + 3, 26, "REPLAY", 2 + replayauto * 2);
	}
	
	if((show_rise_num) && (upLines[player] > 0)) {
		// ����オ�胉�C����
		sprintf(string[0], "%2d LINES UP", upLines[player]);
		printScoreFont(toffset[player], 25, string[0], fontc[rots[player]]);
	} else if(b_to_b_frame[player]) {
		// BACK TO BACK
		if(b_to_b_frame[player] <= 60) {
			if(enable_b_to_b >= 2) {
				sprintf(string[0], "%3d CHAINS", b_to_b_count[player]);
				printScoreFont(toffset[player], 25, string[0], (count % 4 / 2) * digitc[rots[player]]);
			} else if(bonus_btb) {
				printScoreFont(toffset[player] + 3, 25, "e  1.5", (count % 4 / 2) * digitc[rots[player]]);
			}
		} else {
			printScoreFont(toffset[player], 25, "BACK TO BACK", (count % 4 / 2) * digitc[rots[player]]);
		}
	} else if(lastline_frame[player]) {
		// ���C������
		if(lastline[player] == 1) printScoreFont(toffset[player] + 3, 25, "SINGLE", 0);
		if(lastline[player] == 2) printScoreFont(toffset[player] + 3, 25, "DOUBLE", 0);
		if(lastline[player] == 3) printScoreFont(toffset[player] + 3, 25, "TRIPLE", 0);
		if(lastline[player] == 4) printScoreFont(toffset[player] + 2, 25, "HEBORIS!", (count % 4 / 2) * digitc[rots[player]]);
	} else if((enable_combo) && (display_combo == 1) && (combo[player] >= 2)) {
		// �R���{
		sprintf(string[0], "%3d  COMBO", combo[player]);
		printScoreFont(toffset[player], 25, string[0], 0);
	} else if((enable_combo) && (display_combo == 2) && (combo2[player] >= 2)) {
		// 2���C���ȏ�R���{
		sprintf(string[0], "%3d  COMBO", combo2[player]);
		printScoreFont(toffset[player], 25, string[0], 0);
	}
}

// TOMOYO���[�h
void viewScoreTomoyo(int player) {
	int		color, color2;
	int		i, ii, so_far;
	
	color = (count % 4 / 2) * (sp[player] >= 1200) * digitc[rots[player]];
	
	/* �X�e�[�W */
	printScoreFont(soffset[player], 4 + top_frame, "STAGE", fontc[rots[player]]);
	getTomoyoStageNo(stage[player], 0, 0);
	printScoreFont(soffset[player], 5 + top_frame, string[0], color);
	
	/* �c��v���`�i�u���b�N�� */
	printScoreFont(soffset[player], 7 + top_frame, "REST", fontc[rots[player]]);
	sprintf(string[0], "%d", rest_pblock[player]);
	printScoreFont(soffset[player],  8 + top_frame, string[0], color);
	
	/* �N���A�� */
	if(start_stage[player] <= 26) {
		printScoreFont(soffset[player], 10 + top_frame, "CLEAR", fontc[rots[player]]);
		sprintf(string[0], "%d%%", clearp[player]);
		printScoreFont(soffset[player], 11 + top_frame, string[0], color);
	}
	
	/* �M�~�b�N�� */
	if(isfmirror[player])          printScoreFont(soffset[player], 13 + top_frame, "MIRROR",   fontc[rots[player]]);
	else if(rollroll_flag[player]) printScoreFont(soffset[player], 13 + top_frame, "ROLL",     fontc[rots[player]]);
	else if(IsBig[player])         printScoreFont(soffset[player], 13 + top_frame, "DEATH",    fontc[rots[player]]);
	else if(xray_flag[player])     printScoreFont(soffset[player], 13 + top_frame, "X-RAY",    fontc[rots[player]]);
	else if(color_flag[player])    printScoreFont(soffset[player], 13 + top_frame, "COLOR",    fontc[rots[player]]);
	else if(blind_flag[player])    printScoreFont(soffset[player], 13 + top_frame, "BLIND",    fontc[rots[player]]);
	else if(isthunder[player])     printScoreFont(soffset[player], 13 + top_frame, "THUNDER",  fontc[rots[player]]);
	else if(hnext_flag[player])    printScoreFont(soffset[player], 13 + top_frame, "HIDENEXT", fontc[rots[player]]);
	else if(tomoyo_waits[player])  printScoreFont(soffset[player], 13 + top_frame, "DEVIL500", fontc[rots[player]]);
	
	if(tomoyo_rise[player]) printScoreFont(soffset[player], 14 + top_frame, "RISE", fontc[rots[player]]);
	
	/* ���x�� */
	printScoreFont(soffset[player], 20, "LEVEL", fontc[rots[player]]);
	
	// ���q
	if(tc[player] == -1)
		sprintf(string[0], "%3d", 0);	// -1�Ȃ�0�ƕ\��
	else
		sprintf(string[0], "%3d", tc[player]);
	
	printScoreFont(soffset[player], 21, string[0], color);
	
	// ����
	BltRect(3, (soffset[player] * 8) + 2, 178, 38, 34, 24, 3);
	if(sp[player] <= 600) {
		BltFastRect(3, (soffset[player] * 8) + 3, 179, 60 - ((sp[player] * 24) / 660), 37, 22, 1);
	} else {
		BltFastRect(3, (soffset[player] * 8) + 3, 179, 38, 37, 22, 1);
	}
	
	// ����
	sprintf(string[0], "%3d", tc[player] / 100 * 100 + 100 - (tc[player] >= 900));
	printScoreFont(soffset[player], 23, string[0], color);
	
	/* ���x */
	if(disp_waits) {
		printScoreFont(soffset[player], 25, "WAITS", fontc[rots[player]]);
		sprintf(string[0], "%2d %2d", wait1[player], wait2[player]);
		printScoreFont(soffset[player], 26, string[0], color);
		sprintf(string[0], "%2d %2d", wait3[player], waitt[player]);
		printScoreFont(soffset[player], 27, string[0], color);
		sprintf(string[0], "%d", sp[player]);
		printScoreFont(soffset[player], 28, string[0], color);
	}
	
	/* �X�e�[�W�^�C�� */
	if(!tomoyo_no_stage_time[player]) {
		if(stime[player] <= 10 * 60)
			color2 = (count % 4 / 2) * (stime[player] != 0);
		else
			color2 = 1;
		
		getTime(stime[player]);
		printScoreFont(toffset[player] + 2, 27, string[0], color2);
	}
	
	/* ���~�b�g�^�C�� */
	if((ltime[player] > 0) && (ltime[player] <= 10 * 60)) {
		color2 = 2;
	} else if(sp[player] >= 1200) {
		color2 = (count % 4 / 2) * digitc[rots[player]];
	} else {
		color2 = 0;
	}
	getTime(ltime[player]);
	
	if(!tomoyo_no_stage_time[player]) {
		printScoreFont(toffset[player] + 2, 28, string[0], color2);
	} else {
		printBIGFont(foffset[player], 216, string[0], color2);
	}
	
	if(playback) {
		// REPLAY
		if(count % 80 >= 20) printScoreFont(toffset[player] + 3, 26, "REPLAY", 2 + replayauto * 2);
	}
	
	// �Z�N�V�����^�C���\��
	if( (maxPlay == 0) && (show_section_time != 0) && 
	    ((start_stage[player] == 0) || (start_stage[player] == 27) || (start_stage[player] == 45)) )
	{
		for(i = 0; i < 30; i++) {
			if(now_sttime[i + player * 30] != 0) {
				// �X�e�[�W
				getTomoyoStageNo(start_stage[player] + i, 0, 1);
				printScoreFont(section_time_offset, i + 1, string[0], fontc[rots[player]]);
				
				if(now_sttime[i + player * 30] == -1) {
					// ���s
					printScoreFont(section_time_offset + 4, i + 1, "FAILED", color);
				} else if(now_sttime[i + player * 30] == -2) {
					// �X�L�b�v
					printScoreFont(section_time_offset + 4, i + 1, "SKIPED", color);
				} else {
					// ���B�^�C��
					if(show_section_time == 1) {
						so_far = 0;
						for(ii = 0; ii <= i; ii++) {
							so_far = so_far + now_sttime[ii + player * 30];
						}
						getTime(so_far);
						printScoreFont(section_time_offset + 4, i + 1, string[0], color);
					}
					
					// �Z�N�V�����^�C��
					if(show_section_time >= 2) {
						getTime(now_sttime[i + player * 30]);
						printScoreFont(section_time_offset + 4, i + 1, string[0], color);
					}
				}
			}
		}
	}
	
	/* ����オ�胉�C���� */
	if((show_rise_num) && (upLines[player] > 0)) {
		sprintf(string[0], "%2d LINES UP", upLines[player]);
		printScoreFont(toffset[player], 25, string[0], fontc[rots[player]]);
	}
}

// TOMOYO���[�h�iDUAL�ʁj
void viewScoreTomoyoDual(int player) {
	int		i, color, color2;
	
	if(player != 0) return;
	
	color = (count % 4 / 2) * (sp[player] >= 1200) * digitc[rots[player]];
	
	printScoreFont(18, 4, "STAGE", fontc[rots[player]]);
	getTomoyoStageNo(stage[player], 0, 0);
	printScoreFont(18, 5, string[0], color);
	
	printScoreFont(18, 7, "REST", fontc[rots[player]]);
	sprintf(string[0], "%d", rest_pblock[player]);
	printScoreFont(18, 8, string[0], color);
	
	if(start_stage[player] <= 26) {
		printScoreFont(18, 10, "CLEAR", fontc[rots[player]]);
		sprintf(string[0], "%d%%", clearp[player]);
		printScoreFont(18, 11, string[0], color);
	}
	
	/* ���x�� */
	printScoreFont(18, 20, "LEVEL", fontc[rots[player]]);
	
	// ���q
	if(tc[player] == -1)
		sprintf(string[0], "%3d", 0);	// -1�Ȃ�0�ƕ\��
	else
		sprintf(string[0], "%3d", tc[player]);
	
	printScoreFont(18, 21, string[0], color);
	
	// ����
	BltRect(3,146,178,38,34,24,3);
	if(sp[player] <= 1149) {
		BltFastRect(3, 147, 179, 60 - ((sp[player] * 24) / 660), 37, 22, 1);
	} else {
		BltFastRect(3, 147, 179, 38, 37, 22, 1);
	}
	
	// ����
	if(ending[player]) {
		sprintf(string[0], "%3d", tc[player]);
	} else {
		sprintf(string[0], "%3d", tc[player] / 100 * 100 + 100);
	}
	printScoreFont(18, 23, string[0], color);
	
	/* �X�e�[�W�^�C�� */
	if(!tomoyo_no_stage_time[player]) {
		if(stime[player] <= 10 * 60)
			color2 = (count % 4 / 2) * (stime[player] != 0);
		else
			color2 = 1;
		
		getTime(stime[player]);
		printScoreFont(14, 27, string[0], color2);
	}
	
	/* ���~�b�g�^�C�� */
	if((ltime[player] > 0) && (ltime[player] <= 10 * 60)) {
		color2 = 2;
	} else if(sp[player] >= 1200) {
		color2 = (count % 4 / 2) * digitc[rots[player]];
	} else {
		color2 = 0;
	}
	getTime(ltime[player]);
	
	if(!tomoyo_no_stage_time[player]) {
		printScoreFont(14, 28, string[0], color2);
	} else {
		printBIGFont(112, 216, string[0], color2);
	}
	
	/* ����オ�胉�C���� */
	if((show_rise_num) && (upLines[player] > 0)) {
		sprintf(string[0], "%2d LINES UP", upLines[player]);
		printScoreFont(toffset[player], 25, string[0], fontc[rots[player]]);
	}
}

// ACE���[�h�^MISSION���[�h�^ACE200���[�h
void viewScoreAce(int player) {
	int		color, color2, tmp;
	int		i, ii, so_far;
	
	color = (count % 4 / 2) * (sp[player] >= 1200) * digitc[rots[player]];
	
	/* ���x���^�~�b�V���� */
	if(gameMode[player] == 8) {
		printScoreFont(soffset[player], 4 + top_frame, "MISSION", fontc[rots[player]]);
		sprintf(string[0], "%d", c_mission + 1);
		printScoreFont(soffset[player], 5 + top_frame, string[0], color);
	} else {
		printScoreFont(soffset[player], 4 + top_frame, "LEVEL", fontc[rots[player]]);
		sprintf(string[0], "%d", tc[player] + 1);
		printScoreFont(soffset[player], 5 + top_frame, string[0], color);
	}
	
	/* �g�[�^���^�C�� */
	if((!maxPlay) || (gameMode[player] == 8)) {
		// �t���o�[�W����
		printScoreFont(soffset[player], 7 + top_frame, "TOTAL TIME", fontc[rots[player]]);
		getTime(gameTimer[player]);
		printScoreFont(soffset[player], 8 + top_frame, string[0], color);
	} else {
		// �ȈՃo�[�W����
		printScoreFont(soffset[player], 7 + top_frame, "TIME", fontc[rots[player]]);
		getTimeEx(gameTimer[player], 0, 1);
		printScoreFont(soffset[player], 8 + top_frame, string[0], color);
		getTimeEx(gameTimer[player], 0, 2);
		printScoreFont(soffset[player], 9 + top_frame, string[0], color);
	}
	
	/* �x�X�g�^�C�� */
	if((gameMode[player] == 7) && (!playback)) {
		if(RankingSetCategory(player) != -1) {
			tmp = RankingGet(RankingSetCategory(player), rots[player]);
			
			if(!maxPlay) {
				// �t���o�[�W����
				printScoreFont(soffset[player], 10 + top_frame, "BEST TIME", fontc[rots[player]]);
				
				if(rkdata1[tmp] >= 150) getTime(rktime[tmp]);
				else getTime(0);
				
				printScoreFont(soffset[player], 11 + top_frame, string[0], color);
			} else {
				// �ȈՃo�[�W����
				if(rkdata1[tmp] >= 150) {
					printScoreFont(soffset[player], 11 + top_frame, "BEST", fontc[rots[player]]);
					getTimeEx(rktime[tmp], 0, 1);
					printScoreFont(soffset[player], 12 + top_frame, string[0], color);
					getTimeEx(rktime[tmp], 0, 2);
					printScoreFont(soffset[player], 13 + top_frame, string[0], color);
				}
			}
		}
	}
	
	/* �m���} */
	printScoreFont(soffset[player] + ace_frame, 20, "NORM", fontc[rots[player]]);
	
	// ���q
	sprintf(string[0], "%3d", c_norm[player]);
	printScoreFont(soffset[player] + ace_frame, 21, string[0], color);
	
	// ����
	BltRect(3, ((soffset[player] + ace_frame) * 8) + 2, 178, 38, 34, 24, 3);
	BltFastRect(3, ((soffset[player] + ace_frame) * 8) + 3, 179, 60, 37, 22, 1);
	
	// ����
	sprintf( string[0], "%3d", m_norm[player] );
	printScoreFont(soffset[player] + ace_frame, 23, string[0], color);
	
	/* ���x */
	if(disp_waits) {
		printScoreFont(soffset[player], 25, "WAITS", fontc[rots[player]]);
		sprintf(string[0], "%2d %2d", wait1[player], wait2[player]);
		printScoreFont(soffset[player], 26, string[0], color);
		sprintf(string[0], "%2d %2d", wait3[player], waitt[player]);
		printScoreFont(soffset[player], 27, string[0], color);
		sprintf(string[0], "%d", sp[player]);
		printScoreFont(soffset[player], 28, string[0], color);
	}
	
	/* �c��^�C�� */
	if( ((gameMode[player] == 8) && (!mission_time[c_mission])) || ((gameMode[player] == 5) && (!p_timelimit)) ) {
		BltFastRect(49, foffset[player] - 1, 216, 1, 229 + english * 18, 98, 16);
	} else {
		if(ltime[player] <= 10 * 60)
			color2 = (ltime[player] != 0) * 2;
		else
			color2 = color;
		
		getTime(ltime[player]);
		printBIGFont(foffset[player], 216, string[0], color2);
	}
	
	if(gflash[player] > 0) {
		// REGRET
		printScoreFont(toffset[player] + 3, 26, "REGRET", (count % 4 / 2) * digitc[rots[player]]);
	} else if(tspin_frame[player]) {
		// T-SPIN
		if(lasttspin[player] == 0)
			printScoreFont(toffset[player] + 3, 26, "T-SPIN", (count % 4 / 2) * digitc[rots[player]]);
		if(lasttspin[player] == 1)
			printScoreFont(toffset[player] - 1, 26, "T-SPIN SINGLE!", (count % 4 / 2) * digitc[rots[player]]);
		if(lasttspin[player] == 2)
			printScoreFont(toffset[player] - 1, 26, "T-SPIN DOUBLE!", (count % 4 / 2) * digitc[rots[player]]);
		if(lasttspin[player] == 3)
			printScoreFont(toffset[player] - 1, 26, "T-SPIN TRIPLE!", (count % 4 / 2) * digitc[rots[player]]);
	} else if(playback) {
		// REPLAY
		if(count % 80 >= 20) printScoreFont(toffset[player] + 3, 26, "REPLAY", 2 + replayauto * 2);
	}
	
	// �Z�N�V�����^�C���\��
	if((maxPlay == 0) && (show_section_time != 0) && (gameMode[player] != 8)) {
		for(i = 0; i < 15; i++) {
			if(now_sttime[i + player * 30] > 0) {
				// ���x��
				sprintf(string[0], "LV%d", i + 1);
				printScoreFont(section_time_offset, i + 5, string[0], fontc[rots[player]]);
				
				// ���B�^�C��
				if(show_section_time == 1) {
					so_far = 0;
					for(ii = 0; ii <= i; ii++) {
						so_far = so_far + now_sttime[ii + player * 30];
					}
					getTime(so_far);
					printScoreFont(section_time_offset + 5, i + 5, string[0], color);
				}
				
				// �Z�N�V�����^�C��
				if(show_section_time >= 2) {
					getTime(now_sttime[i + player * 30]);
					printScoreFont(section_time_offset + 5, i + 5, string[0], color);
				}
			}
		}
	}
	
	// �R�[�X���i�~�b�V�����j
	if((gameMode[player] == 8) && (!maxPlay) && (!mission_hide_info)) {
		printScoreFont(0, 1, mission_course_name, fontc[rots[player]]);
	}
	
	if((show_rise_num) && (upLines[player] > 0)) {
		// ����オ�胉�C����
		sprintf(string[0], "%2d LINES UP", upLines[player]);
		printScoreFont(toffset[player], 25, string[0], fontc[rots[player]]);
	} else if(lastline_frame[player]) {
		// ���C������
		if(lastline[player] == 1) printScoreFont(toffset[player] + 3, 25, "SINGLE", 0);
		if(lastline[player] == 2) printScoreFont(toffset[player] + 3, 25, "DOUBLE", 0);
		if(lastline[player] == 3) printScoreFont(toffset[player] + 3, 25, "TRIPLE", 0);
		if(lastline[player] == 4) printScoreFont(toffset[player] + 2, 25, "HEBORIS!", (count % 4 / 2) * digitc[rots[player]]);
	}
	
	// PUT THE BLOCK!�i�ϋv�~�b�V�����j
	if((gameMode[player] == 8) && (mission_type[c_mission] == 23)) {
		if(ltime[player] <= 0) {
			printScoreFont(boffset[player] - 2, 26, "PUT THE BLOCK!", (count % 4 / 2) * 3);
		} else if( ((mission_opt_3[c_mission] == 0) && ((kickc[player] > 10) || (kickc3[player] > 10))) || 
		           ((mission_opt_3[c_mission] > 0) && (mission_opt_3[c_mission] < 99) && 
		            ((kickc[player] > mission_opt_3[c_mission]) || (kickc3[player] > mission_opt_3[c_mission]))) )
		{
			printScoreFont(boffset[player] - 2, 26, "PUT THE BLOCK!", (count % 4 / 2) * 2);
		}
	}
}

// �ΐ탂�[�h
void viewScoreVersus(int player) {
	int		i, color, color2;
	
	color = (count % 4 / 2) * (sp[player] >= 1200) * digitc[rots[player]];
	
	if(item_mode[player]) {
		i = item_g[player];
		if(item_g[player] > item_interval) i = item_interval;
		
		// �A�C�e���Q�[�W
		BltRect(78, 114 + player * 80, 80, 0, 0, 12, 75);
		BltRect(78, 114 + player * 80,
		        153 - ((70 * i) / item_interval), 12 + ismiss[player] * 24,
		         72 - ((70 * i) / item_interval), 12, ((70 * i) / item_interval) );
		
		// �Q�[�W�̃t���b�V��
		if(itemappear_c[player]) {
			if(itemappear_c[player] % 2 == 0) BltRect(78, 114 + player * 80, 80, 24, 0, 12, 75);
			itemappear_c[player]--;
		}
		
		printFont(14 + player * 8, 4 + top_frame, "ITEM", fontc[rots[player]]);
		i = item_interval - item_g[player];
		if(i < 0) i = 0;
		
		if(player == 0) {
			sprintf(string[0], "%d", i);
			printFont(14, 5 + top_frame, string[0], color);
		} else {
			sprintf(string[0], "%2d", i);
			printFont(24, 5 + top_frame, string[0], color);
		}
	}
	
	/* ���x�� */
	if(!vs_goal_type) {
		printFont(14 + player * 7, 20, "LEVEL", fontc[rots[player]]);
		
		// ���q
		if(player == 0) {
			if(tc[player] == -1)
				sprintf(string[0], "%3d", 0);	// -1�Ȃ�0�ƕ\��
			else
				sprintf(string[0], "%3d", tc[player]);
			
			printFont(14, 21, string[0], color);
		} else {
			if(tc[player] == -1)
				sprintf(string[0], "%4d", 0);	// -1�Ȃ�0�ƕ\��
			else
				sprintf(string[0], "%4d", tc[player]);
			
			printFont(22, 21, string[0], color);
		}
		
		// ����
		BltRect(3,114 + 68 * player,178,38,34,24,3);
		if(sp[player] <= 1149) {
			BltFastRect(3, 115 + 68 * player, 179, 60 - ((sp[player] * 24) / 660), 37, 22, 1);
		} else {
			BltFastRect(3, 115 + 68 * player, 179, 38, 37, 22, 1);
		}
		
		// ����
		if(player == 0) {
			sprintf(string[0], "%3d", tc[player] / 100 * 100 + 100);
			printFont(14, 23, string[0], color);
		} else {
			sprintf(string[0], "%4d", tc[player] / 100 * 100 + 100);
			printFont(22, 23, string[0], color);
		}
	}
	/* ���C�� */
	else if(vs_goal_level != 0) {
		printFont(14 + player * 8, 20, "NORM", fontc[rots[player]]);
		
		// ���q
		if(player == 0) {
			sprintf(string[0], "%3d", c_norm[player]);
			printFont(14, 21, string[0], color);
		} else {
			sprintf(string[0], "%4d", c_norm[player]);
			printFont(22, 21, string[0], color);
		}
		
		// ����
		BltRect(3,114 + 68 * player,178,38,34,24,3);
		BltFastRect(3, 115 + 68 * player, 179, 60, 37, 22, 1);
		
		// ����
		if(vs_goal_type == 1) i = 10;
		else i = 5;
		
		if(player == 0) {
			sprintf(string[0], "%3d", vs_goal_level * i);
			printFont(14, 23, string[0], color);
		} else {
			sprintf(string[0], "%4d", vs_goal_level * i);
			printFont(22, 23, string[0], color);
		}
	}
	
	/* �^�C�� */
	if(player == 0) {
		if(vs_timelimit > 0) {
			if(ltime[player] <= 10 * 60)
				color2 = (ltime[player] != 0) * 2;
			else
				color2 = color;
			
			getTime(ltime[player]);
			printBIGFont(112, 216, string[0], color2);
		} else {
			if(gameTimer[player] > 359999) gameTimer[player] = 359999;
			getTime(gameTimer[player]);
			printBIGFont(112, 216, string[0], color);
		}
	}
	
	if(playback) {
		if(count % 80 >= 20) printFont(17, 26, "REPLAY", 2 + replayauto * 2);
	}
	
	if((show_rise_num) && (upLines[player] > 0)) {
		// ����オ�胉�C����
		sprintf(string[0], "%2d LINES UP", upLines[player]);
		printFont(2 + player * 24, 25, string[0], fontc[rots[player]]);
	} else if(lastline_frame[player]) {
		// ���C������
		if(lastline[player] == 1) printFont(5 + player * 24, 25, "SINGLE", 0);
		if(lastline[player] == 2) printFont(5 + player * 24, 25, "DOUBLE", 0);
		if(lastline[player] == 3) printFont(5 + player * 24, 25, "TRIPLE", 0);
		if(lastline[player] == 4) printFont(4 + player * 24, 25, "HEBORIS!", (count % 4 / 2) * digitc[rots[player]]);
	}
}

// OLD STYLE���[�h
void viewScoreGB(int player) {
	int		i, ii, so_far;
	
	/* �X�R�A */
	if(sc[player] > 999999) sc[player] = 999999;
	printScoreFont(soffset[player], 4 + top_frame, "SCORE", fontc[rots[player]]);
	sprintf(string[0], "%d", sc[player]);
	printScoreFont(soffset[player], 5 + top_frame, string[0], 0);
	
	/* ���x�� */
	if(tc[player] > 99) tc[player] = 99;
	printScoreFont(soffset[player], 7 + top_frame, "LEVEL", fontc[rots[player]]);
	if(tc[player] < 0) sprintf(string[0], "%d", 0);
	else sprintf(string[0], "%d", tc[player]);
	printScoreFont(soffset[player], 8 + top_frame, string[0], 0);
	
	/* ���C�� */
	if(li[player] > 999) li[player] = 999;
	printScoreFont(soffset[player], 10 + top_frame, "LINES", fontc[rots[player]]);
	sprintf(string[0], "%d", li[player]);
	printScoreFont(soffset[player], 11 + top_frame, string[0], 0);
	
	/* ���x */
	if(disp_waits) {
		printScoreFont(soffset[player], 25, "WAITS", fontc[rots[player]]);
		sprintf(string[0], "%2d %2d", wait1[player], wait2[player]);
		printScoreFont(soffset[player], 26, string[0], 0);
		sprintf(string[0], "%2d %2d", wait3[player], waitt[player]);
		printScoreFont(soffset[player], 27, string[0], 0);
		sprintf(string[0], "%d", sp[player]);
		printScoreFont(soffset[player], 28, string[0], 0);
	}
	
	/* �^�C�� */
	if(gameTimer[player] > 359999) gameTimer[player] = 359999;
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], 216, string[0], 0);
	
	if(playback) {
		// REPLAY
		if(count % 80 >= 20) printScoreFont(toffset[player] + 3, 26, "REPLAY", 2 + replayauto * 2);
	}
	
	// �Z�N�V�����^�C���\��
	if((maxPlay == 0) && (show_section_time != 0)) {
		for(i = 0; i < 15; i++) {
			if(now_sttime[i + player * 30] > 0) {
				// ���x��
				sprintf(string[0], "LV%d", i);
				printScoreFont(section_time_offset, i + 5, string[0], fontc[rots[player]]);
				
				// ���B�^�C��
				if(show_section_time == 1) {
					so_far = 0;
					for(ii = 0; ii <= i; ii++) {
						so_far = so_far + now_sttime[ii + player * 30];
					}
					getTime(so_far);
					printScoreFont(section_time_offset + 5, i + 5, string[0], 0);
				}
				
				// �Z�N�V�����^�C��
				if(show_section_time >= 2) {
					getTime(now_sttime[i + player * 30]);
					printScoreFont(section_time_offset + 5, i + 5, string[0], 0);
				}
			}
		}
	}
}

// FLASH���[�h
void viewScoreFlash(int player) {
	int		color, color2;
	
	color = (count % 4 / 2) * (sp[player] >= 1200) * digitc[rots[player]];
	
	/* �X�R�A */
	if(sc[player] > 9999999) sc[player] = 9999999;
	printScoreFont(soffset[player], 4 + top_frame, "SCORE", fontc[rots[player]]);
	sprintf(string[0], "%d", sc[player]);
	printScoreFont(soffset[player], 5 + top_frame, string[0], color);
	
	/* �X�e�[�W */
	printScoreFont(soffset[player], 7 + top_frame, "STAGE", fontc[rots[player]]);
	sprintf(string[0], "%d", stage[player] + 1);
	printScoreFont(soffset[player], 8 + top_frame, string[0], color);
	
	/* �c��v���`�i�u���b�N�� */
	printScoreFont(soffset[player], 10 + top_frame, "REST", fontc[rots[player]]);
	sprintf(string[0], "%d", rest_pblock[player]);
	printScoreFont(soffset[player], 11 + top_frame, string[0], color);
	
	/* ���x�� */
	printScoreFont(soffset[player], 20, "LEVEL", fontc[rots[player]]);
	
	// ���q
	if(tc[player] == -1)
		sprintf(string[0], "%3d", 0);	// -1�Ȃ�0�ƕ\��
	else
		sprintf(string[0], "%3d", tc[player]);
	
	printScoreFont(soffset[player], 21, string[0], color);
	
	// ����
	BltRect(3, (soffset[player] * 8) + 2, 178, 38, 34, 24, 3);
	if(sp[player] <= 600) {
		BltFastRect(3, (soffset[player] * 8) + 3, 179, 60 - ((sp[player] * 24) / 660), 37, 22, 1);
	} else {
		BltFastRect(3, (soffset[player] * 8) + 3, 179, 38, 37, 22, 1);
	}
	
	// ����
	sprintf(string[0], "%3d", tc[player] / 100 * 100 + 100 - (tc[player] >= 900));
	printScoreFont(soffset[player], 23, string[0], color);
	
	/* ���x */
	if(disp_waits) {
		printScoreFont(soffset[player], 25, "WAITS", fontc[rots[player]]);
		sprintf(string[0], "%2d %2d", wait1[player], wait2[player]);
		printScoreFont(soffset[player], 26, string[0], color);
		sprintf(string[0], "%2d %2d", wait3[player], waitt[player]);
		printScoreFont(soffset[player], 27, string[0], color);
		sprintf(string[0], "%d", sp[player]);
		printScoreFont(soffset[player], 28, string[0], color);
	}
	
	if(timeOn[player]) {
		// �{�[�i�X
		printScoreFont(toffset[player], 26, "BONUS", fontc[rots[player]]);
		sprintf(string[0], "%7d", flash_bonus_points[player]);
		printScoreFont(toffset[player] + 5, 26, string[0], 0);
	} else if(playback) {
		// REPLAY
		if(count % 80 >= 20) printScoreFont(toffset[player] + 3, 26, "REPLAY", 2 + replayauto * 2);
	}
	
	/* �^�C�� */
	if(!timeattack[player]) {
		if(gameTimer[player] > 359999) gameTimer[player] = 359999;
		getTime(gameTimer[player]);
		printBIGFont(foffset[player], 216, string[0], color);
	} else {
		if((ltime[player] > 0) && (ltime[player] <= 10 * 60)) {
			color2 = 2;
		} else if(sp[player] >= 1200) {
			color2 = (count % 4 / 2) * digitc[rots[player]];
		} else {
			color2 = 0;
		}
		getTime(ltime[player]);
		printBIGFont(foffset[player], 216, string[0], color2);
	}
}

// STANDARD���[�h
void viewScoreStandard(int player) {
	int		color, color2, tmp;
	
	color = (count % 4 / 2) * (sp[player] >= 1200) * digitc[rots[player]];
	
	if(sc[player] > 9999999) sc[player] = 9999999;
	if(!hide_score) {
		// �X�R�A
		printScoreFont(soffset[player], 4 + top_frame, "SCORE", fontc[rots[player]]);
		sprintf(string[0], "%d", sc[player]);
		printScoreFont(soffset[player], 5 + top_frame, string[0], color);
		
		// ���C��
		printScoreFont(soffset[player], 7 + top_frame, "LINES", fontc[rots[player]]);
		sprintf(string[0], "%d", c_norm[player]);
		printScoreFont(soffset[player], 8 + top_frame, string[0], color);
	}
	
	// 40LINES
	if((timeattack[player] == 0) || (timeattack[player] == 2)) {
		// �m���}
		printScoreFont(soffset[player], 20, "NORM", fontc[rots[player]]);
		
		// ���q
		sprintf(string[0], "%3d", c_norm[player]);
		printScoreFont(soffset[player], 21, string[0], color);
		
		// ����
		BltRect(3, (soffset[player] * 8) + 2, 178, 38, 34, 24, 3);
		BltFastRect(3, (soffset[player] * 8) + 3, 179, 60, 37, 22, 1);
		
		// ����
		sprintf(string[0], "%3d", m_norm[player]);
		printScoreFont(soffset[player], 23, string[0], color);
		
		// �^�C��
		if(gameTimer[player] > 359999) gameTimer[player] = 359999;
		getTime(gameTimer[player]);
		printBIGFont(foffset[player], 216, string[0], color);
		
		// �x�X�g�^�C��
		if(!playback) {
			if(stdRankingSetCategory(player) != -1) {
				tmp = stdRankingGet(stdRankingSetCategory(player), rots[player]);
				
				if(!maxPlay) {
					// �t���o�[�W����
					printScoreFont(soffset[player], 15 + top_frame, "BEST TIME", fontc[rots[player]]);
					
					if(std_rklines[tmp] >= 40) getTime(std_rktime[tmp]);
					else getTime(0);
					
					printScoreFont(soffset[player], 16 + top_frame, string[0], color);
				} else {
					// �ȈՃo�[�W����
					if(std_rklines[tmp] >= 40) {
						printScoreFont(soffset[player], 15 + top_frame, "BEST", fontc[rots[player]]);
						getTimeEx(std_rktime[tmp], 0, 1);
						printScoreFont(soffset[player], 16 + top_frame, string[0], color);
					}
				}
			}
		}
	}
	
	// ULTRA
	if((timeattack[player] == 1) || (timeattack[player] == 3)) {
		// �c��^�C��
		if((ltime[player] > 0) && (ltime[player] <= 10 * 60)) {
			color2 = 2;
		} else if(sp[player] >= 1200) {
			color2 = (count % 4 / 2) * digitc[rots[player]];
		} else {
			color2 = 0;
		}
		getTime(ltime[player]);
		printBIGFont(foffset[player], 216, string[0], color2);
		
		// �x�X�g�X�R�A
		if(!playback) {
			if(stdRankingSetCategory(player) != -1) {
				tmp = stdRankingGet(stdRankingSetCategory(player), rots[player]);
				
				if(!maxPlay) printScoreFont(soffset[player], 15 + top_frame, "BEST SCORE", fontc[rots[player]]);
				else printScoreFont(soffset[player], 15 + top_frame, "BEST", fontc[rots[player]]);
				
				sprintf(string[0], "%d", std_rkscore[tmp]);
				printScoreFont(soffset[player], 16 + top_frame, string[0], color);
			}
		}
	}
	
	// wait�l
	printScoreFont(soffset[player], 10 + top_frame, "WAITS", fontc[rots[player]]);
	sprintf(string[0], "%2d %2d", wait1[player], wait2[player]);
	printScoreFont(soffset[player], 11 + top_frame, string[0], color);
	sprintf(string[0], "%2d %2d", wait3[player], waitt[player]);
	printScoreFont(soffset[player], 12 + top_frame, string[0], color);
	sprintf(string[0], "%d", sp[player]);
	printScoreFont(soffset[player], 13 + top_frame, string[0], color);
	
	if(timeattack[player] >= 2) {
		printScoreFont(soffset[player], 15 + top_frame, "TRY", fontc[rots[player]]);
		sprintf(string[0], "%d/3", tc[player] + 1);
		printScoreFont(soffset[player], 16 + top_frame, string[0], color);
	}
	
	if(tspin_frame[player]) {
		// T-SPIN
		if(lasttspin[player] == 0)
			printScoreFont(toffset[player] + 3, 26, "T-SPIN", (count % 4 / 2) * digitc[rots[player]]);
		if(lasttspin[player] == 1)
			printScoreFont(toffset[player] - 1, 26, "T-SPIN SINGLE!", (count % 4 / 2) * digitc[rots[player]]);
		if(lasttspin[player] == 2)
			printScoreFont(toffset[player] - 1, 26, "T-SPIN DOUBLE!", (count % 4 / 2) * digitc[rots[player]]);
		if(lasttspin[player] == 3)
			printScoreFont(toffset[player] - 1, 26, "T-SPIN TRIPLE!", (count % 4 / 2) * digitc[rots[player]]);
	} else if(playback) {
		// REPLAY
		if(count % 80 >= 20) printScoreFont(toffset[player] + 3, 26, "REPLAY", 2 + replayauto * 2);
	}
	
	if(b_to_b_frame[player]) {
		// BACK TO BACK
		if((enable_b_to_b >= 2) && (b_to_b_frame[player] <= 60)) {
			sprintf(string[0], "%3d CHAINS", b_to_b_count[player]);
			printScoreFont(toffset[player], 25, string[0], (count % 4 / 2) * digitc[rots[player]]);
		} else {
			printScoreFont(toffset[player], 25, "BACK TO BACK", (count % 4 / 2) * digitc[rots[player]]);
		}
	} else if(lastline_frame[player]) {
		// ���C������
		if(lastline[player] == 1) printScoreFont(toffset[player] + 3, 25, "SINGLE", 0);
		if(lastline[player] == 2) printScoreFont(toffset[player] + 3, 25, "DOUBLE", 0);
		if(lastline[player] == 3) printScoreFont(toffset[player] + 3, 25, "TRIPLE", 0);
		if(lastline[player] == 4) printScoreFont(toffset[player] + 2, 25, "HEBORIS!", (count % 4 / 2) * digitc[rots[player]]);
	} else if((enable_combo) && (display_combo == 1) && (combo[player] >= 2)) {
		// �R���{
		sprintf(string[0], "%3d  COMBO", combo[player]);
		printScoreFont(toffset[player], 25, string[0], (count % 4 / 2) * digitc[rots[player]]);
	} else if((enable_combo) && (display_combo == 2) && (combo2[player] >= 2)) {
		// 2���C���ȏ�R���{
		sprintf(string[0], "%3d  COMBO", combo2[player]);
		printScoreFont(toffset[player], 25, string[0], (count % 4 / 2) * digitc[rots[player]]);
	}
}

// MARATHON���[�h
void viewScoreMarathon(int player) {
	int		color, color2, tmp;
	int		i, ii, so_far;
	
	color = (count % 4 / 2) * (sp[player] >= 1200) * digitc[rots[player]];
	
	// �X�R�A
	if(sc[player] > 9999999) sc[player] = 9999999;
	if(!hide_score) {
		printScoreFont(soffset[player], 4 + top_frame, "SCORE", fontc[rots[player]]);
		sprintf(string[0], "%d", sc[player]);
		printScoreFont(soffset[player], 5 + top_frame, string[0], color);
	}
	
	// ���x��
	printScoreFont(soffset[player], 7 + top_frame, "LEVEL", fontc[rots[player]]);
	sprintf(string[0], "%d", tc[player] + 1);
	printScoreFont(soffset[player], 8 + top_frame, string[0], color);
	
	if(timeattack[player] == 1) {
		// �X�N�E�F�A
		if(squarenum[player] > 999) squarenum[player] = 999;
		printScoreFont(soffset[player], 10 + top_frame, "SQUARE", fontc[rots[player]]);
		sprintf(string[0], "%d", squarenum[player]);
		printScoreFont(soffset[player], 11 + top_frame, string[0], color);
	} else {
		// ���C��
		if(li[player] > 999) li[player] = 999;
		printScoreFont(soffset[player], 10 + top_frame, "LINES", fontc[rots[player]]);
		sprintf(string[0], "%d", li[player]);
		printScoreFont(soffset[player], 11 + top_frame, string[0], color);
	}
	
	if((tc[player] < 14) || (timeattack[player] != 2)) {
		// �m���}
		printScoreFont(soffset[player] + ace_frame, 20, "NORM", fontc[rots[player]]);
		
		// ���q
		sprintf(string[0], "%3d", c_norm[player]);
		printScoreFont(soffset[player] + ace_frame, 21, string[0], color);
		
		// ����
		BltRect(3, ((soffset[player] + ace_frame) * 8) + 2, 178, 38, 34, 24, 3);
		BltFastRect(3, ((soffset[player] + ace_frame) * 8) + 3, 179, 60, 37, 22, 1);
		
		// ����
		sprintf(string[0], "%3d", m_norm[player]);
		printScoreFont(soffset[player] + ace_frame, 23, string[0], color);
	}
	
	/* ���x */
	if(disp_waits) {
		printScoreFont(soffset[player], 25, "WAITS", fontc[rots[player]]);
		sprintf(string[0], "%2d %2d", wait1[player], wait2[player]);
		printScoreFont(soffset[player], 26, string[0], color);
		sprintf(string[0], "%2d %2d", wait3[player], waitt[player]);
		printScoreFont(soffset[player], 27, string[0], color);
		sprintf(string[0], "%d", sp[player]);
		printScoreFont(soffset[player], 28, string[0], color);
	}
	
	// �^�C��
	if((gameMode[player] == 5) && (p_timelimit > 0) && (timeOn[player])) {
		if(ltime[player] <= 10 * 60)
			color2 = (ltime[player] != 0) * 2;
		else
			color2 = color;
		
		getTime(ltime[player]);
		printBIGFont(foffset[player], 216, string[0], color2);
	} else {
		if(gameTimer[player] > 359999) gameTimer[player] = 359999;
		getTime(gameTimer[player]);
		printBIGFont(foffset[player], 216, string[0], color);
	}
	
	if(tspin_frame[player]) {
		// T-SPIN
		if(lasttspin[player] == 0)
			printScoreFont(toffset[player] + 3, 26, "T-SPIN", (count % 4 / 2) * digitc[rots[player]]);
		if(lasttspin[player] == 1)
			printScoreFont(toffset[player] - 1, 26, "T-SPIN SINGLE!", (count % 4 / 2) * digitc[rots[player]]);
		if(lasttspin[player] == 2)
			printScoreFont(toffset[player] - 1, 26, "T-SPIN DOUBLE!", (count % 4 / 2) * digitc[rots[player]]);
		if(lasttspin[player] == 3)
			printScoreFont(toffset[player] - 1, 26, "T-SPIN TRIPLE!", (count % 4 / 2) * digitc[rots[player]]);
	} else if(playback) {
		// REPLAY
		if(count % 80 >= 20) printScoreFont(toffset[player] + 3, 26, "REPLAY", 2 + replayauto * 2);
	}
	
	if(b_to_b_frame[player]) {
		// BACK TO BACK
		if((enable_b_to_b >= 2) && (b_to_b_frame[player] <= 60)) {
			sprintf(string[0], "%3d CHAINS", b_to_b_count[player]);
			printScoreFont(toffset[player], 25, string[0], (count % 4 / 2) * digitc[rots[player]]);
		} else {
			printScoreFont(toffset[player], 25, "BACK TO BACK", (count % 4 / 2) * digitc[rots[player]]);
		}
	} else if(lastline_frame[player]) {
		// ���C������
		if(lastline[player] == 1) printScoreFont(toffset[player] + 3, 25, "SINGLE", 0);
		if(lastline[player] == 2) printScoreFont(toffset[player] + 3, 25, "DOUBLE", 0);
		if(lastline[player] == 3) printScoreFont(toffset[player] + 3, 25, "TRIPLE", 0);
		if(lastline[player] == 4) printScoreFont(toffset[player] + 2, 25, "HEBORIS!", (count % 4 / 2) * digitc[rots[player]]);
	} else if((enable_combo) && (display_combo == 1) && (combo[player] >= 2)) {
		// �R���{
		sprintf(string[0], "%3d  COMBO", combo[player]);
		printScoreFont(toffset[player], 25, string[0], (count % 4 / 2) * digitc[rots[player]]);
	} else if((enable_combo) && (display_combo == 2) && (combo2[player] >= 2)) {
		// 2���C���ȏ�R���{
		sprintf(string[0], "%3d  COMBO", combo2[player]);
		printScoreFont(toffset[player], 25, string[0], (count % 4 / 2) * digitc[rots[player]]);
	}
	
	// �Z�N�V�����^�C���\��
	if((maxPlay == 0) && (show_section_time != 0)) {
		for(i = 0; i < 15; i++) {
			if(now_sttime[i + player * 30] > 0) {
				// ���x��
				sprintf(string[0], "LV%d", i + 1);
				printScoreFont(section_time_offset, i + 5, string[0], fontc[rots[player]]);
				
				// ���B�^�C��
				if(show_section_time == 1) {
					so_far = 0;
					for(ii = 0; ii <= i; ii++) {
						so_far = so_far + now_sttime[ii + player * 30];
					}
					getTime(so_far);
					printScoreFont(section_time_offset + 5, i + 5, string[0], color);
				}
				
				// �Z�N�V�����^�C��
				if(show_section_time >= 2) {
					getTime(now_sttime[i + player * 30]);
					printScoreFont(section_time_offset + 5, i + 5, string[0], color);
				}
			}
		}
	}
}

void viewScore() {
	int player;
	
	for(player = 0; player <= maxPlay; player++) {
		if((stat[player] != 0) && (stat[player] != 2)) {
			if(isNormalOrBeginnerMode(player))
				viewScoreNormal(player);	// �ʏ탂�[�h
			else if(gameMode[player] == 4)
				viewScoreVersus(player);	// VERSUS���[�h
			else if(gameMode[player] == 6)
			{
				if(tomoyo_dual_enable[player])
					viewScoreTomoyoDual(player);	// TOMOYO���[�h DUAL��
				else
					viewScoreTomoyo(player);		// TOMOYO���[�h
			}
			else if(isAceModeOrMission(player))
				viewScoreAce(player);		// ACE���[�h�^MISSION���[�h
			else if(gameMode[player] == 9)
				viewScoreGB(player);		// OLD STYLE���[�h
			else if(gameMode[player] == 15)
				viewScoreFlash(player);		// FLASH���[�h
			else if(gameMode[player] == 17)
				viewScoreStandard(player);	// STANDARD���[�h
			else if(isMarathonMode(player))
				viewScoreMarathon(player);	// MARATHON���[�h
		}
	}
	
	if((disp_lineinfo) && (!maxPlay) && (gameMode[0] != 8) && (!show_section_time)) viewLineInfo(0);
}

//������������������������������������������������������������������������������
//   ���C�������񐔕\��
//������������������������������������������������������������������������������
void viewLineInfo(int player) {
	int temp;
	
	printFont(1, 1, "LINE ERASE", 0);
	sprintf(string[0], "SINGLE  %d", line_count[player * 4 + 0]);
	printFont(1, 2, string[0], 1);
	sprintf(string[0], "DOUBLE  %d", line_count[player * 4 + 1]);
	printFont(1, 3, string[0], 4);
	sprintf(string[0], "TRIPLE  %d", line_count[player * 4 + 2]);
	printFont(1, 4, string[0], 5);
	sprintf(string[0], "HEBORIS %d", line_count[player * 4 + 3]);
	printFont(1, 5, string[0], 2);
	
	temp = line_count[player * 4 + 0];
	temp = temp + line_count[player * 4 + 1] * 2;
	temp = temp + line_count[player * 4 + 2] * 3;
	temp = temp + line_count[player * 4 + 3] * 4;
	sprintf(string[0], "LINES   %d", temp);
	printFont(1, 6, string[0], 8);
	
	if((tspin_type != 0) && (isTSpinEnableMode(player))) {
		printFont(1, 8, "T-SPIN", 0);
		sprintf(string[0], "ZERO    %d", tspin_count[player * 4 + 0]);
		printFont(1, 9, string[0], 9);
		sprintf(string[0], "SINGLE  %d", tspin_count[player * 4 + 1]);
		printFont(1, 10, string[0], 6);
		sprintf(string[0], "DOUBLE  %d", tspin_count[player * 4 + 2]);
		printFont(1, 11, string[0], 7);
		
		if((tspin_type != 4) && (isWRule(player))) {
			sprintf(string[0], "TRIPLE  %d", tspin_count[player * 4 + 3]);
			printFont(1, 12, string[0], 3);
		}
		
		temp = tspin_count[player * 4 + 0];
		temp = temp + tspin_count[player * 4 + 1];
		temp = temp + tspin_count[player * 4 + 2];
		temp = temp + tspin_count[player * 4 + 3];
		sprintf(string[0], "TOTAL   %d", temp);
		printFont(1, 13, string[0], 8);
	}
}

//������������������������������������������������������������������������������
//   �`���[�g���A���̕��͂�\��
//������������������������������������������������������������������������������
void viewHowToPlay() {
	if(demotime ==       0) showHelpString(1, msg_howtoplay[english * 7 + 0]);
	if(demotime == 60 *  5) showHelpString(1, msg_howtoplay[english * 7 + 1]);
	if(demotime == 60 * 10) showHelpString(1, msg_howtoplay[english * 7 + 2]);
	if(demotime == 60 * 15) showHelpString(1, msg_howtoplay[english * 7 + 3]);
	if(demotime == 60 * 20) showHelpString(1, msg_howtoplay[english * 7 + 4]);
	if(demotime == 60 * 30) showHelpString(1, msg_howtoplay[english * 7 + 5]);
	if(demotime == 60 * 40) showHelpString(1, msg_howtoplay[english * 7 + 6]);
	
	printFont(1, 27, "HOW TO PLAY", 2);
}

//������������������������������������������������������������������������������
//   �t�B�[���h�̕`��
//������������������������������������������������������������������������������
void viewField(int player) {
	// �g�`��
	viewFieldFrame(player, 1);
	
	// �C���C�T�[�̐�
	if((player == 0) && (gameMode[0] == 8) && (onRecord[0]) && 
	   ((mission_type[c_mission] == 7) || (mission_type[c_mission] == 39) || (mission_type[c_mission] == 40)))
	{
		viewEraserLines();
	}
	
	// ����オ��G�f�B�^
	if(tomoyo_rise_edit[player]) viewFieldTomoyoRiseEditor(player);
	
	// �t�B�[���h�̃u���b�N��`��
	if(!tomoyo_rise_edit[player]) viewFieldBlock(player);
}

// NEXT��`��
void viewFieldNext(int player) {
	int		b, i, j, k, color, flash;
	int		ntmp, tmp_o;
	int		pl2;
	
	if(tomoyo_dual_enable[0]) pl2 = 0;
	else pl2 = player;
	
	// NEXT�`��
	if((hnext[pl2] > 0) && (!ishidenext[pl2])) {
		if(isfever[pl2]) {
			ntmp = 0;				// �t�B�[�o�[���͖_����
		} else if(isfakenext[pl2]) {
			ntmp = nextb_fake[nextc[pl2]];	// �U
		} else {
			ntmp = next[pl2];
		}
		
		flash = (count % 2) * (blockflash == 0) + (blockflash == 1);
		k = ((ntmp != 0) && isWRule(pl2)) + ((ntmp == 0) && (o_nblk[pl2 * 6] != 1) && (!isDRule(pl2)));
		
		// �F��ݒ�
		if(item_nblk[pl2 * 6]) {
			color = item_nblk[pl2 * 6] + 16;		// �A�C�e��
			tmp_o = 0;
		} else if(isfever[pl2]) {
			color = count % 7 + 1;					// �t�B�[�o�[
			tmp_o = o_nblk[pl2 * 6];
		} else {
			color = c_nblk[pl2 * 6];				// �ʏ�
			tmp_o = o_nblk[pl2 * 6];
		}
		
		if(ndelay[pl2]) {
			if(fastlrmove == 3) b = n_bx[pl2] + IsBig[pl2];
			else b = 3;
			drawBlockFast(boffset[player] + b, 1 + k, ntmp, rt_nblk[pl2 * 6], color, tmp_o * 17, -2, flash, pl2);
			
			if(!tmp_o) {
				drawBlockFastShadow(pl2, boffset[player] + b, 1 + k, ntmp, rt_nblk[pl2 * 6], color, tmp_o * 17, -2);
			}
		} else if((hnext[pl2] == 1) || (heboGB[pl2])) {
			// NEXT��������̏ꍇ�͏�����NEXT��\��
			drawhBlock(foffset[player] + 48, 18 + k, ntmp, rt_nblk[pl2 * 6], color, pl2, tmp_o);
		}
		
		// NEXT2��NEXT3
		if(!heboGB[pl2]) {
			for(j = 0; j < hnext[pl2] - 1; j++) {
				if(isfever[pl2]) {
					ntmp = 0;				// �t�B�[�o�[���͖_����
				} else if(isfakenext[pl2]) {
					// �U
					i = nextc[pl2] + ndelay[pl2] + j;
					if(i >= nextb_max[pl2]) i = i - nextb_max[pl2];
					ntmp = nextb_fake[i];
				} else {
					ntmp = getNextBlock(pl2, nextc[pl2] + ndelay[pl2] + j);
				}
				
				if(isWRule(pl2)) {
					k = (ntmp != 0) * 4 - (8 * top_frame);
				} else if(isDRule(pl2)) {
					k = (ntmp == 0) * -4 - (8 * top_frame);
				} else {
					k = -8 * top_frame;
				}
				
				// �F��ݒ�
				if(item_nblk[ndelay[pl2] + j + pl2 * 6]) {
					color = item_nblk[ndelay[pl2] + j + pl2 * 6] + 16;	// �A�C�e��
					tmp_o = 0;
				} else if(isfever[pl2]) {
					color = count % 7 + 1;										// �t�B�[�o�[
					tmp_o = o_nblk[ndelay[pl2] + j + pl2 * 6];
				} else {
					color = c_nblk[ndelay[pl2] + j + pl2 * 6];			// �ʏ�
					tmp_o = o_nblk[ndelay[pl2] + j + pl2 * 6];
				}
				
				drawhBlock(foffset[player] + 68 + j * 20, 18 + k, ntmp, rt_nblk[ndelay[pl2] + j + pl2 * 6], color, pl2, tmp_o);
			}
		}
	}
}

// HOLD��`��
void viewFieldHold(int player) {
	int		b, i, j, k, color, tmp_o;
	int		pl2;
	
	if(tomoyo_dual_enable[0]) pl2 = 0;
	else pl2 = player;
	
	// HOLD�u���b�N��`��
	if(hold[pl2] != -1) {
		if( (dhold[pl2]) && ((ishidenext[pl2]) || (!hnext[pl2])) ) {
			printFont(boffset[player], 2, "?", 0);
		} else {
			if(isWRule(pl2)) {
				k = (hold[pl2] != 0) * 4;
			} else if(isDRule(pl2)) {
				k = (hold[pl2] == 0) * -4;
			} else {
				k = 0;
			}
			
			// �F��ݒ�
			if((item_hblk[pl2] != 0) && (!dhold[pl2])) {
				color = item_hblk[pl2] + 16;
				tmp_o = 0;
			} else if(!dhold[pl2]) {
				color = c_hblk[pl2];
				tmp_o = o_hblk[pl2];
			} else {
				color = 0;
				tmp_o = o_hblk[pl2];
			}
			
			drawhBlock(foffset[player] + 4, 12 + k, hold[pl2], 0, color, pl2, tmp_o);
		}
	}
	
	// HOLD���g�p�ł��Ȃ��Ƃ��̏�
	if(heboGB[pl2] || disable_hold || isholdlock[pl2])
		BltRect(3, foffset[player] - 2, 5, 275, 275, 27, 27);
}

// �g��`��
void viewFieldFrame(int player, int allview) {
	int i, j, tmp, ace;
	
	// �㕔�̃O���t�B�b�N��`��
	if(top_frame) {
		BltRect(3, foffset[player] - 15, 0, 0, 268, 126, 35);
	} else {
		BltRect(3, foffset[player], 0, 0, 128, 100, 32);
	}
	BltRect(3, foffset[player] + 38, 0, 128, 112, 26, 7);
	BltRect(3, foffset[player]     , 4, 128, 119, 26, 7);
	
	ace = 0;
	if(heboGB[player]) {
		// �I�[���h�X�^�C��
		if(heboGB[player] == 1) {
			j = 7;
		} else {
			j = 8;
		}
	} else if((stat[player] == 0) || (stat[player] == 2)) {
		// �Q���҂��ł̓��m�N��
		j = 5;
	} else if(examination[player]) {
		// �����ł͋��F
		j = 3;
	} else {
		j = field_frame_color[gameMode[player]];
		if(j == 5) ace = 1;
		
		// �A�C�e���ł̐F�̕ω�
		if(item_mode[player]) {
			if(isfmirror[player] || isrollroll[player] || IsBig[player] || isxray[player] || iscolor[player] || 
			   isRotateLock[player] || ishidenext[player] || ismagnetblock[player] || istimestop[player] || 
			   isholdlock[player] || isLRreverse[player] || isboost[player] || isUDreverse[player] || isremote[player] || 
			   isdark[player] || istrance[player] || dolaser[player] || donega[player] || doshotgun[player] || 
			   isbanana[player] || do180field[player] || isdouble[player] || ismiss[player] || docopyfld[player] || 
			   isfakenext[player] || item_monochrome[player])
			{
				j = 2;	// �U���A�C�e��
			}
			else if((item_nblk[player * 6] == fldihardno) || (item[player] == fldihardno))
			{
				j = 2;	// HARD BLOCK
			}
			else if(isUPdelfield[player] || isDWdelfield[player] || isdeleven[player] || 
			        isLmovfield[player] || isRmovfield[player] || isreflect[player] || 
			        isallclear[player])
			{
				j = 6;	// �������P
			}
			else if(isfever[player] || doexchg[player] || isFreefall[player] || do16t[player])
			{
				j = 0;	// �������Q
			}
			else if(dorulet[player])
			{
				j = 3;	// RANDOM
			}
		}
	}
	
	// ACE���[�h�̘g�̏o�����聗�e����
	if(block_shadow && ace && ace_frame) {
		if(allview) {
			BltRect(2, foffset[player] - 8 + ofs_x[player] + 2 - (4 * IsVs2p(player)), 32 + ofs_y[player], 960, 184, 112, 184);
		} else {
			BltRect(2, foffset[player] - 8 + ofs_x[player] + 2 - (4 * IsVs2p(player)), 32 + ofs_y[player], 960, 184, 112, 8);
		}
	}
	
	if( (field_spin[player] < 0) || (field_spin[player] > 19) ) {
		// ��]���ĂȂ��ꍇ
		if(block_shadow && allview && !iscolor[player]) {
			BltRect(2, foffset[player] + ofs_x[player] + 2 - (4 * IsVs2p(player)), 32 + ofs_y[player], 96 * j, 184, 96, 184);
		}
		BltRect(2, foffset[player] + ofs_x[player], 32 + ofs_y[player], 96 * j, 0, 96, 8 + allview * 176);
	} else if(allview) {
		// ��]���Ă�ꍇ
		if(j == 5) tmp = 19;
		else if(j == 2) tmp = 77;
		else if(j == 3) tmp = 80;
		else tmp = 18;
		
		BltRect(tmp, foffset[player] + ofs_x[player], 17 + ofs_y[player], 96 * field_spin[player], 0, 96, 206);
	}
	
	// ACE���[�h�̘g�̏o������
	if(ace && ace_frame) {
		if(allview) {
			BltRect(2, foffset[player] - 8 + ofs_x[player], 32 + ofs_y[player], 960, 0, 112, 184);
		} else {
			BltRect(2, foffset[player] - 8 + ofs_x[player], 32 + ofs_y[player], 960, 0, 112, 8);
		}
	}
	
	// NEXT�`��
	if(allview) viewFieldNext(player);
	
	// HOLD�`��
	if(allview || !top_frame) viewFieldHold(player);
	
	// �A�C�e����
	if(item_name[player]) BltRect(79, foffset[player] + 65, 0, 0, (item_name[player] - 1) * 16, 48, 16);
}

// �t�B�[���h�w�i��\��
void viewFieldBackground(int player) {
	// COLOR�̎��ɍ��w�i��`��
	if( ((iscolor[player]) || (heboGB[player] == 2)) && (!skip_viewbg) )
		BltFastRect(24, foffset[player] + ofs_x[player] + 8, 40 + ofs_y[player], 0, 0, 80, 160);
	
	// �I�[���h�X�^�C��
	if(heboGB[player] == 1) {
		BltFastRect(84, foffset[player] + ofs_x[player] + 8, 32 + ofs_y[player], 0, 0, 80, 8);
		BltFastRect(84, foffset[player] + ofs_x[player] + 8, 40 + ofs_y[player], 0, 0, 80, 160);
	}
	
	// []�̎��̔w�i
	if( (use_over1000_block == 1) && ((tc[player] >= over1000_start) || (always_over1000[player])) ) {
		if(rule_oblk_bg[rots[player]] == 1)	// ��
			BltFastRect(84, foffset[player] + ofs_x[player] + 8, 40 + ofs_y[player], 0, 0, 80, 160);
		if(rule_oblk_bg[rots[player]] == 2)	// ��
			BltFastRect(24, foffset[player] + ofs_x[player] + 8, 40 + ofs_y[player], 0, 0, 80, 160);
	}
}

// TOMOYO����オ��G�f�B�b�g�p
void viewFieldTomoyoRiseEditor(int player) {
	int		b, i, j, k, fi, color;
	
	for(b = 0; b < 2; b++)
		for(j = 0; j < 20; j++)
			for(k = 0; k < 10; k++) {
				fi = tomoyo_rise_fld[k + j * 10 + player * 200] - 1;
				
				if(fi != -1) {
					if(!b) {
						drawSingleBlock(player, (k + boffset[player]) * 8, (j + 3 + 2) * 8, 0, fi, 5, 0, 0, 0, 0);
					} else {
						// ��
						if(getFieldBlockTomoyoRiseEditor(player, k - 1, j) == 0)
							BltRect(30, (k + boffset[player]) * 8 - 1, (j + 3 + 2) * 8 - 1, 54, 0, 10, 10);
						
						// �E
						if(getFieldBlockTomoyoRiseEditor(player, k + 1, j) == 0)
							BltRect(30, (k + boffset[player]) * 8 - 1, (j + 3 + 2) * 8 - 1, 64, 0, 10, 10);
						
						// ��
						if(getFieldBlockTomoyoRiseEditor(player, k, j - 1) == 0)
							BltRect(30, (k + boffset[player]) * 8 - 1, (j + 3 + 2) * 8 - 1, 74, 0, 10, 10);
						
						// ��
						if(getFieldBlockTomoyoRiseEditor(player, k, j + 1) == 0)
							BltRect(30, (k + boffset[player]) * 8 - 1, (j + 3 + 2) * 8 - 1, 84, 0, 10, 10);
					}
				}
			}
}

// �t�B�[���h�̃u���b�N��\��
void viewFieldBlock(int player) {
	int		b, i, j, k, fi, color, add;
	int		fldt3, fldt4, fldt5;	// �V���h�E�^�C�}�[�ł�������Ə����Ă������o�Ɏg�p
	int		tmp_fldo;
	int		tmp;
	
	if((pause[player]) && (!pause_visible)) return;
	if((hidden[player] == 2) && (!pause[player]) && (hidden_b_type)) return;
	
	for(b = isblind[player]; b < 2; b++)
		for(j = (!spawn_y_type) * 2; j < hiddeny[player]; j++)
			for(k = 0; k < 10; k++) {
				if(fldi[k + j * 10 + player * 220])
					fi = fldi[k + j * 10 + player * 220] + 16;
				else
					fi = fld[k + j * 10 + player * 220] - 1;
				
				fldt3 = fldt[k + j * 10 + player * 220];
				fldt4 = fldt[k + j * 10 + player * 220] * 32;
				fldt5 = 256 - (fldt[k + j * 10 + player * 220] * 32);
				
				if(fldi[k + j * 10 + player * 220])
					tmp_fldo = 0;
				else
					tmp_fldo = fldo[k + j * 10 + player * 220];
				
				if(fi != -1) {
					if(!b) {
						// �u���b�N
						if(iscolor[player]) {
							// COLOR�v�Z
							color = k;
							if(color >= 5) color = 9 - color;
							color = 40 - ( (((20 - j) + color) * 4 + color_counter[player]) % 40 );
							color = 7 + 10 - color_tbl[color];
						} else if((fldi[k + j * 10 + player * 220] == fldisno) || (fldi[k + j * 10 + player * 220] == fldigsno)) {
							// �����`
							if(flds[k + j * 10 + player * 220] >= -10) {
								color = 17 + flds[k + j * 10 + player * 220];
								flds[k + j * 10 + player * 220]--;
							} else if(flds[k + j * 10 + player * 220] >= -19) {
								color = abs(flds[k + j * 10 + player * 220]) - 10 + 7;
								flds[k + j * 10 + player * 220]--;
							} else {
								color = 5;
							}
						} else {
							// �ʏ�
							color = 5;
						}
						
						// �u���b�N��`��
						i = (color <= 16);
						i = i && ((!isxray[player]) || (xray_counter[player] % p_xray_frame == k));
						i = i && ((!isdark[player]) || ((isdark[player]) && (item_timer[player] > 420) && (item_timer[player] % 2 == 0)));
						
						if(i) {
							if( (fldt3 >= 1) && (fldt3 <= 8) && (!pause[player]) ) {
								drawSingleBlock(player, (k + boffset[player]) * 8 + ofs_x[player], (j + 3) * 8 + ofs_y[player], 0, fi, color + tmp_fldo * 17, 0, 1, fldt4, fldt5);
							} else if( ((fldt3 != 0) && (fldt3 > -10)) || (pause[player]) ) {
								drawSingleBlock(player, (k + boffset[player]) * 8 + ofs_x[player], (j + 3) * 8 + ofs_y[player], 0, fi, color + tmp_fldo * 17, 0, 0, 0, 0);
							}
						}
					} else {
						// �g��
						i = (!iscolor[player]);
						i = i && (!isdark[player]);
						i = i && ((!isxray[player]) || (xray_counter[player] % p_xray_frame == k));
						i = i && ((fi != 8) && (fi != 9));
						i = i && ((tmp_fldo != 1) || (isblind[player]));
						i = i && ((stat[player] != 7) || (gameMode[player] == 4));
						i = i && (!heboGB[player]);
						i = i && ((fldt3 <= -1) || (fldt3 >= 8) || (pause[player]));
						
						if(i) {
							// �e
							if((getFieldBlock(player, k + 1 - (IsVs2p(player) * 2), j) == 0) && (!isblind[player])) {
								drawSingleBlockShadow(player, (k + boffset[player]) * 8 + ofs_x[player], (j + 3) * 8 + ofs_y[player], 0, -1, -1, fi, 5, -1, 0);
							}
							
							// �g��
							if(fldt3 <= -10) add = 60 + fldt3 + 20;	// �������[����
							else if(isblind[player]) add = 10;
							else add = 0;
							
							// ��
							if(getFieldBlock(player, k - 1, j) == 0)
								BltRect(30, (k + boffset[player]) * 8 + ofs_x[player] - 1, (j + 3) * 8 + ofs_y[player] - 1, 54, add, 10, 10);
							
							// �E
							if(getFieldBlock(player, k + 1, j) == 0)
								BltRect(30, (k + boffset[player]) * 8 + ofs_x[player] - 1, (j + 3) * 8 + ofs_y[player] - 1, 64, add, 10, 10);
							
							// ��
							if(getFieldBlock(player, k, j - 1) == 0)
								BltRect(30, (k + boffset[player]) * 8 + ofs_x[player] - 1, (j + 3) * 8 + ofs_y[player] - 1, 74, add, 10, 10);
							
							// ��
							if(getFieldBlock(player, k, j + 1) == 0)
								BltRect(30, (k + boffset[player]) * 8 + ofs_x[player] - 1, (j + 3) * 8 + ofs_y[player] - 1, 84, add, 10, 10);
							
							// ����
							if(getFieldBlock(player, k - 1, j - 1) == 0)
								BltRect(30, (k + boffset[player]) * 8 + ofs_x[player], (j + 3) * 8 + ofs_y[player], 55, add + 1, 1, 1);
							
							// �E��
							if(getFieldBlock(player, k + 1, j - 1) == 0)
								BltRect(30, (k + boffset[player]) * 8 + ofs_x[player] + 7, (j + 3) * 8 + ofs_y[player], 55, add + 1, 1, 1);
							
							// ����
							if(getFieldBlock(player, k - 1, j + 1) == 0)
								BltRect(30, (k + boffset[player]) * 8 + ofs_x[player], (j + 3) * 8 + ofs_y[player] + 7, 55, add + 1, 1, 1);
							
							// �E��
							if(getFieldBlock(player, k + 1, j + 1) == 0)
								BltRect(30, (k + boffset[player]) * 8 + ofs_x[player] + 7, (j + 3) * 8 + ofs_y[player] + 7, 55, add + 1, 1, 1);
						}
					}
				}
			}
	
	// HIDDEN����
	if(hiddenc[player] < 15) {
		hiddenc[player]++;
		color = hiddenc[player] / 3;
	} else {
		color = 5;
	}
	
	for(j = hiddeny[player]; j < 22; j++) {
		for(k = 0; k < 10; k++) {
			drawSingleBlock(player, (k + boffset[player]) * 8 + ofs_x[player], (j + 3) * 8 + ofs_y[player], 0, 0, color, 0, 0, 0, 0);
		}
		color = 5;
	}
}

//������������������������������������������������������������������������������
//   �t�H���g��\������
//������������������������������������������������������������������������������
void printFont(int fontX, int fontY, str *fontStr, int fontColor) {
	int		i, sx, sy, stringLength, stringChar;

	stringLength = StrLen(fontStr);
	for(i = 0; i < stringLength; i++) {
		stringChar = CharAt(fontStr, i);
		sx = ( (stringChar - 32) % 32 ) * 8;
		sy = ( (stringChar - 32) / 32 ) * 8 + fontColor * 24;
		BltRect(1, (fontX + i) * 8, fontY * 8, sx, sy, 8, 8);
	}
}

// �X�R�A�\���p�i�u���b�N�̉e��ON�̏ꍇ�͉���+2�h�b�g�j
void printScoreFont(int fontX, int fontY, str *fontStr, int fontColor) {
	int		i, sx, sy, stringLength, stringChar;

	stringLength = StrLen(fontStr);
	for(i = 0; i < stringLength; i++) {
		stringChar = CharAt(fontStr, i);
		sx = ( (stringChar - 32) % 32 ) * 8;
		sy = ( (stringChar - 32) / 32 ) * 8 + fontColor * 24;
		BltRect(1, (fontX + i) * 8 + (block_shadow * 2), fontY * 8, sx, sy, 8, 8);
	}
}

// �傫���o�[�W�����i�����̂݁j
void printBIGFont(int fontX, int fontY, str *fontStr, int fontColor) {
	int		i, sx, sy, stringLength, stringChar;

	stringLength = StrLen(fontStr);
	for(i = 0; i < stringLength; i++) {
		stringChar = CharAt(fontStr, i);
		sx = (stringChar -48) * 12;
		sy = (fontColor * 16) + (timer_font_type * 160);
		if(sx >= 0) BltRect(22, fontX + 12 * i, fontY, sx, sy, 12, 16);
	}
}

//������������������������������������������������������������������������������
//   �u���b�N��`�悷��
//������������������������������������������������������������������������������

// ���ݑ��쒆�̃u���b�N�p
void drawBlock(int bx1, int by1, int kind, int rotate, int color, int bright, int offset, int flash, int player) {
	int		i, j, bx2, by2;
	int		data[2];
	
	for(j = (holdframetype != 0); j <= ((flash == 10) || (flash < 2)); j++) {
		for(i = 0; i < 4; i++) {
			getBlockData(player, bx1, by1, kind, rotate, i, &data);
			bx2 = data[0] * 8;
			by2 = data[1] * 8;
			
			if(j == 0) {
				if((dhold[player]) && (hold_used[player] >= 2) && (holdframetype == 0))
					BltFastRect(30, bx2 - 1, by2 - 1 + offset, 10 * ((count % 16 < 8) + 1), 0, 10, 10);
			} else {
				if(flash == 10) {			// �Œ莞�̓_��
					if(bright >= 17)
						drawSingleBlock(player, bx2, by2, offset, 0, 17, 0, 0, 0, 0);
					else if(color >= 8)							// []�u���b�N�^�A�C�e���u���b�N
						drawSingleBlock(player, bx2, by2, offset, color, 0, 0, 0, 0, 0);
					else										// �ʏ�u���b�N
						drawSingleBlock(player, bx2, by2, offset, 0, 0, 0, 0, 0, 0);
				} else if(flash < 2) {	// �ʏ�
					drawSingleBlock(player, bx2, by2, offset, color, bright, 0, 0, 0, 0);
					
					if((dhold[player]) && (hold_used[player] >= 2) && (holdframetype == 1))
						drawBlockLine(rots[player], bx2, by2, kind, rotate, i, 8 * (count % 16 < 8), offset, 0);
				}
			}
		}
	}
}

// NEXT��TLS�p�i�g�Ȃ��j
void drawBlockFast(int bx1, int by1, int kind, int rotate, int color, int bright, int offset, int flash, int player) {
	int		i, bx2, by2;
	int		data[2];
	
	for(i = 0; i < 4; i++) {
		getBlockData(player, bx1, by1, kind, rotate, i, &data);
		bx2 = data[0] * 8;
		by2 = data[1] * 8;
		
		if(flash == 999)
			drawSingleBlock(player, bx2, by2, offset, color, bright, 0, 1, 112, 154);
		else if(flash == 10)
			drawSingleBlock(player, bx2, by2, offset, 0, 0, 0, 0, 0, 0);
		else if(flash < 2)
			drawSingleBlock(player, bx2, by2, offset, color, bright, 0, 0, 0, 0);
	}
}

// hold�E3Next�p�k��drawBlock
// ����rotate��ǉ� #LITE20.22
void drawhBlock(int bx1, int by1, int kind, int rotate, int color, int player, int bright) {
	int		i, bx2, by2;
	int		data[2];
	
	for(i = 0; i < 4; i++) {
		getBlockData(player, 0, 0, kind, rotate, i, &data);
		bx2 = bx1 + (data[0] * 4);
		by2 = by1 + (data[1] * 4);
		
		drawSingleBlock(player, bx2, by2, 0, color, bright, 2, 0, 0, 0);
		
		if(bright == 0) drawSingleBlockShadow(player, bx2, by2, 0, kind, rotate, color, bright, i, 2);
	}
}

// BIG�̌��ݑ��쒆�̃u���b�N�p
void drawBigBlock(int bx1, int by1, int kind, int rotate, int color, int bright, int offset, int flash, int player) {
	int		i, j, bx2, by2;
	int		data[2];
	
	for(j = (holdframetype != 0); j <= ((flash == 10) || (flash < 2)); j++) {
		for(i = 0; i < 4; i++) {
			getBlockData(player, 0, 0, kind, rotate, i, &data);
			bx2 = (bx1 + (data[0] * 2)) * 8;
			by2 = (by1 + (data[1] * 2)) * 8;
			
			if(j == 0) {
				if((dhold[player]) && (hold_used[player] >= 2) && (holdframetype == 0))
					BltFastRect(30, bx2 - 1, by2 - 1 + offset, 18 * ((count % 16 < 8) * 2), 10, 18, 18);
			} else {
				if(flash == 10) {			// �Œ莞�̓_��
					if(bright >= 7)
						drawSingleBlock(player, bx2, by2, offset, 0, 7, 1, 0, 0, 0);
					else if(color >= 8)							// []�u���b�N�^�A�C�e���u���b�N
						drawSingleBlock(player, bx2, by2, offset, color, 0, 1, 0, 0, 0);
					else										// �ʏ�u���b�N
						drawSingleBlock(player, bx2, by2, offset, 0, 0, 1, 0, 0, 0);
				} else if(flash < 2) {	// �ʏ�
					drawSingleBlock(player, bx2, by2, offset, color, bright, 1, 0, 0, 0);
					
					if((dhold[player]) && (hold_used[player] >= 2) && (holdframetype == 1))
						drawBlockLine(rots[player], bx2, by2, kind, rotate, i, 8 * (count % 16 < 8), offset, 1);
				}
			}
		}
	}
}

// BIG��TLS�p�i�g�Ȃ��j
void drawBigBlockFast(int bx1, int by1, int kind, int rotate, int color, int bright, int offset, int flash, int player) {
	int		i, bx2, by2;
	int		data[2];
	
	for(i = 0; i < 4; i++) {
		getBlockData(player, 0, 0, kind, rotate, i, &data);
		bx2 = (bx1 + (data[0] * 2)) * 8;
		by2 = (by1 + (data[1] * 2)) * 8;
		
		if( flash == 999 )
			drawSingleBlock(player, bx2, by2, offset, color, bright, 1, 1, 112, 154);
		else if( flash == 10 )
			drawSingleBlock(player, bx2, by2, offset, 0, 0, 1, 0, 0, 0);
		else if( flash < 2 )
			drawSingleBlock(player, bx2, by2, offset, color, bright, 1, 0, 0, 0);
	}
}

// Draw Current Block
// ���쒆�̃u���b�N��\��
void drawCBlock(int player, int color, int bright, int offset, int flash, int use3D) {
	int tmp_color, tmp_oblk;
	
	// �F�����߂�
	if(item[player]) {
		tmp_color = 16 + item[player];	// �A�C�e��
		tmp_oblk = 0;
	} else if(istrance[player]) {
		// TRANCE FORM
		if(count % 2 == 0) tmp_color = 0;
		else tmp_color = ((count % 14) / 2) + 1;
		tmp_oblk = o_cblk[player];
	} else if(isrollroll[player] || isRotateLock[player]) {
		tmp_color = 0;					// ���[�����[���^��]�s��
		tmp_oblk = o_cblk[player];
	} else {
		tmp_color = color;				// �ʏ�
		tmp_oblk = o_cblk[player];
	}
	
	if(IsBig[player]) {
		// BIG
		drawBigBlock(bx[player] + boffset[player], by[player] + 3, blk[player], rt[player],
					tmp_color, bright + tmp_oblk * 7, offset, flash, player);
		
		if(tomoyo_dual_enable[0]) {
			drawBigBlock(bx[player] + boffset[1], by[player] + 3, blk[player], rt[player],
						tmp_color, bright + tmp_oblk * 7, offset, flash, player);
		}
	} else {
		// �ʏ�
		drawBlock(bx[player] + boffset[player], by[player] + 3, blk[player], rt[player],
					tmp_color, bright + tmp_oblk * 17, offset, flash, player);
		
		if(!tmp_oblk && use3D) {
			drawBlockShadow(player, bx[player], by[player], blk[player], rt[player],
						tmp_color, bright, offset, boffset[player]);
		}
		
		if(tomoyo_dual_enable[0]) {
			drawBlock(bx[player] + boffset[1], by[player] + 3, blk[player], rt[player],
						tmp_color, bright + tmp_oblk * 17, offset, flash, player);
			
			if(!tmp_oblk && use3D) {
				drawBlockShadow(player, bx[player], by[player], blk[player], rt[player],
							tmp_color, bright, offset, boffset[1]);
			}
		}
	}
}

// T.L.S. (Temporary Landing System)  (c)1998 AR��KA(^^;
void drawTLSBlock(int player, int bottom) {
	int tmp_color, tmp_oblk;
	
	// �F�����߂�
	if(item[player]) {
		tmp_color = 16 + item[player];	// �A�C�e��
		tmp_oblk = 0;
	} else if(istrance[player]) {
		// TRANCE FORM
		if(count % 2 == 0) tmp_color = 0;
		else tmp_color = ((count % 14) / 2) + 1;
		tmp_oblk = o_cblk[player];
	} else if(isrollroll[player] || isRotateLock[player]) {
		tmp_color = 0;					// ���[�����[���^��]�s��
		tmp_oblk = o_cblk[player];
	} else {
		tmp_color = c_cblk[player];		// �ʏ�
		tmp_oblk = o_cblk[player];
	}
	
	if( (!noredraw) && (tls_view != 2) && 
	    ((tls_view == 1) || (gameMode[player] == 0) || (gameMode[player] == 17) || (tc[player] < 100)) )
	{
		if(IsBig[player]) {
			// BIG
			drawBigBlockFast(bx[player] + boffset[player], bottom + 2, blk[player], rt[player],
							tmp_color, 6 + tmp_oblk * 7, 0, 0, player);
		} else {
			// �ʏ�
			drawBlockFast(bx[player] + boffset[player], bottom + 2, blk[player], rt[player],
							tmp_color, 6 + tmp_oblk * 17, 0, 0, player);
			
			if(!tmp_oblk) {
				drawBlockShadow(player, bx[player], bottom - 1, blk[player], rt[player],
								tmp_color, 6, 0, boffset[player]);
			}
		}
	}
}

// �i�r�Q�[�V�����p
void drawNaviBlock(int bx1, int by1, int kind, int rotate, int color, int bright, int player) {
	int		i, bx2, by2;
	int		data[2];
	
	if(bright < 8) {
		for(i = 0; i < 4; i++) {
			getBlockData(player, bx1, by1, kind, rotate, i, &data);
			bx2 = data[0] * 8;
			by2 = data[1] * 8;
			BltRect(76, bx2, by2, color * 8, bright * 8, 8, 8);
		}
	}
}

// 1�}�X���̃u���b�N��`��
void drawSingleBlock(int player, int bx2, int by2, int offset, int color, int bright, int size, int bl_on, int bl1, int bl2)
{
	int tmp, plane;
	
	// NORMAL
	if(size == 0) {
		if(color >= 10) {
			tmp = (color * 8) - 80;
			plane = 46;
		} else if(heboGB[player] == 1) {
			if(!rule_color[rots[player]]) {
				tmp = color * 8 + 80;
			} else {
				tmp = color * 8;
			}
			plane = 6;
			bright = 0;
		} else {
			tmp = (rule_graphics[rots[player]] * 80) + (color * 8);
			plane = 25;
		}
		
		if(!bl_on)
			BltFastRect(plane, bx2, by2 + offset, tmp, bright * 8, 8, 8);
		else
			BlendBltRect(plane, bx2, by2 + offset, tmp, bright * 8, 8, 8, bl1, bl1, bl1, bl2, bl2, bl2);
	}
	
	// BIG
	if(size == 1) {
		if(color >= 10) {
			tmp = (color * 16) - 160;
			plane = 47;
		} else if(heboGB[player] == 1) {
			if(!rule_color[rots[player]]) {
				tmp = color * 16 + 160;
			} else {
				tmp = color * 16;
			}
			plane = 52;
			bright = 0;
		} else {
			tmp = (rule_graphics[rots[player]] * 160) + (color * 16);
			plane = 26;
		}
		
		if(!bl_on)
			BltFastRect(plane, bx2, by2 + offset, tmp, bright * 16, 16, 16);
		else
			BlendBltRect(plane, bx2, by2 + offset, tmp, bright * 16, 16, 16, bl1, bl1, bl1, bl2, bl2, bl2);
	}
	
	// SMALL
	if(size == 2) {
		if(color < 10) {
			tmp = (rule_graphics[rots[player]] * 40) + (color * 4);
			plane = 27;
		} else {
			tmp = (color * 4) - 40;
			plane = 48;
		}
		
		if(!bl_on)
			BltFastRect(plane, bx2, by2 + offset, tmp, bright * 4, 4, 4);
		else
			BlendBltRect(plane, bx2, by2 + offset, tmp, bright * 4, 4, 4, bl1, bl1, bl1, bl2, bl2, bl2);
	}
}

// �g��k����
void drawSingleBlockR(int player, int bx2, int by2, int color, int zoom) {
	int tmp, plane;
	
	if(color < 10) {
		tmp = (rule_graphics[rots[player]] * 80) + (color * 8);
		plane = 25;
	} else {
		tmp = (color * 8) - 80;
		plane = 46;
	}
	
	BltFastRectR(plane, bx2, by2, tmp, 0, 8, 8, zoom, zoom);
}

// �u���b�N�̘g����`��
void drawBlockLine(int rule, int bx2, int by2, int kind, int rotate, int index, int bright, int offset, int size) {
	int linkdata;
	
	if(rule_rot[rule] == 0) linkdata = blkDataL[kind * 16 + rotate * 4 + index];
	if(rule_rot[rule] == 1) linkdata = blkWDataL[kind * 16 + rotate * 4 + index];
	if(rule_rot[rule] == 2) linkdata = blkDDataL[kind * 16 + rotate * 4 + index];
	
	if(!size) {
		// �ʏ�T�C�Y
		// ��
		if(BitTest(linkdata, 0) == 0)
			BltRect(30, bx2 - 1, by2 - 1 + offset, 74, bright * 10, 10, 10);
		
		// ��
		if(BitTest(linkdata, 1) == 0)
			BltRect(30, bx2 - 1, by2 - 1 + offset, 84, bright * 10, 10, 10);
		
		// ��
		if(BitTest(linkdata, 2) == 0)
			BltRect(30, bx2 - 1, by2 - 1 + offset, 54, bright * 10, 10, 10);
		
		// �E
		if(BitTest(linkdata, 3) == 0)
			BltRect(30, bx2 - 1, by2 - 1 + offset, 64, bright * 10, 10, 10);
		
		// ����
		if((BitTest(linkdata, 2) != 0) && (BitTest(linkdata, 0) != 0) && (kind != 2))
			BltRect(30, bx2, by2 + offset, 55, bright * 10 + 1, 1, 1);
		
		// �E��
		if((BitTest(linkdata, 3) != 0) && (BitTest(linkdata, 0) != 0) && (kind != 2))
			BltRect(30, bx2 + 7, by2 + offset, 55, bright * 10 + 1, 1, 1);
		
		// ����
		if((BitTest(linkdata, 2) != 0) && (BitTest(linkdata, 1) != 0) && (kind != 2))
			BltRect(30, bx2, by2 + offset + 7, 55, bright * 10 + 1, 1, 1);
		
		// �E��
		if((BitTest(linkdata, 3) != 0) && (BitTest(linkdata, 1) != 0) && (kind != 2))
			BltRect(30, bx2 + 7, by2 + offset + 7, 55, bright * 10 + 1, 1, 1);
	} else {
		// BIG�T�C�Y
		// ��
		if(BitTest(linkdata, 0) == 0)
			BltRect(30, bx2 - 2, by2 - 2 + offset, 133, bright * 20, 20, 20);
		
		// ��
		if(BitTest(linkdata, 1) == 0)
			BltRect(30, bx2 - 2, by2 - 2 + offset, 153, bright * 20, 20, 20);
		
		// ��
		if(BitTest(linkdata, 2) == 0)
			BltRect(30, bx2 - 2, by2 - 2 + offset, 94, bright * 20, 20, 20);
		
		// �E
		if(BitTest(linkdata, 3) == 0)
			BltRect(30, bx2 - 2, by2 - 2 + offset, 113, bright * 20, 20, 20);
		
		// ����
		if((BitTest(linkdata, 2) != 0) && (BitTest(linkdata, 0) != 0) && (kind != 2))
			BltRect(30, bx2 - 1, by2 + offset, 55, bright * 10 + 1, 1, 1);
		
		// �E��
		if((BitTest(linkdata, 3) != 0) && (BitTest(linkdata, 0) != 0) && (kind != 2))
			BltRect(30, bx2 + 15, by2 + offset, 55, bright * 10 + 1, 1, 1);
		
		// ����
		if((BitTest(linkdata, 2) != 0) && (BitTest(linkdata, 1) != 0) && (kind != 2))
			BltRect(30, bx2 - 1, by2 + offset + 15, 55, bright * 10 + 1, 1, 1);
		
		// �E��
		if((BitTest(linkdata, 3) != 0) && (BitTest(linkdata, 1) != 0) && (kind != 2))
			BltRect(30, bx2 + 15, by2 + offset + 15, 55, bright * 10 + 1, 1, 1);
	}
}

// ���쒆�̃u���b�N�̉e��`��
void drawBlockShadow(int player, int bx1, int by1, int kind, int rotate, int color, int bright, int offset, int xoffset) {
	int		i, bx2, by2;
	int		data[2];
	
	if(!block_shadow) return;
	
	for(i = 0; i < 4; i++) {
		getBlockData(player, bx1, by1, kind, rotate, i, &data);
		bx2 = data[0];
		by2 = data[1];
		
		if(getFieldBlock(player, bx2 + 1 - (IsVs2p(player) * 2), by2) == 0) {
			drawSingleBlockShadow(player, (bx2 + xoffset) * 8, (by2 + 3) * 8, offset, kind, rotate, color, bright, i, 0);
		}
	}
}

// NEXT�u���b�N�̉e��`��
void drawBlockFastShadow(int player, int bx1, int by1, int kind, int rotate, int color, int bright, int offset) {
	int		i, bx2, by2;
	int		data[2];
	
	if(!block_shadow) return;
	
	for(i = 0; i < 4; i++) {
		getBlockData(player, bx1, by1, kind, rotate, i, &data);
		bx2 = data[0] * 8;
		by2 = data[1] * 8;
		
		drawSingleBlockShadow(player, bx2, by2, offset, kind, rotate, color, bright, i, 0);
	}
}

// �u���b�N�̉e��`��
void drawSingleBlockShadow(int player, int bx2, int by2, int offset, int kind, int rotate, int color, int bright, int index, int size) {
	int tmp, tmp2, linkdata;
	
	if(!block_shadow) return;
	if(bright >= 17) return;
	if(heboGB[player]) return;
	
	if((kind >= 0) && (rotate >= 0) && (index >= 0)) {
		if(rule_rot[rots[player]] == 0) linkdata = blkDataL[kind * 16 + rotate * 4 + index];
		if(rule_rot[rots[player]] == 1) linkdata = blkWDataL[kind * 16 + rotate * 4 + index];
		if(rule_rot[rots[player]] == 2) linkdata = blkDDataL[kind * 16 + rotate * 4 + index];
		
		if(BitTest(linkdata, 3 - IsVs2p(player)) != 0) return;
	}
	
	// �ʏ�T�C�Y
	if(size == 0) {
		if(color >= 10) {
			tmp = (color - 10) * 2 + 160;
		} else {
			tmp = (rule_graphics[rots[player]] * 20) + (color * 2);
		}
		
		tmp2 = 8;
		if(IsVs2p(player)) tmp2 = -2;
		
		BltFastRect(83, bx2 + tmp2, by2 + offset, tmp, bright * 8, 2, 8);
	}
	
	// BIG�T�C�Y
	if(size == 1) {
		if(color >= 10) {
			tmp = (color - 10) * 4 + 320;
		} else {
			tmp = (rule_graphics[rots[player]] * 40) + (color * 4);
		}
		
		tmp2 = 16;
		if(IsVs2p(player)) tmp2 = -4;
		
		BltFastRect(83, bx2 + tmp2, by2 + offset, tmp, 136 + bright * 16, 4, 16);
	}
	
	// SMALL�T�C�Y
	if(size == 2) {
		if(color >= 10) {
			tmp = (color - 10) * 1 + 80;
		} else {
			tmp = (rule_graphics[rots[player]] * 10) + (color * 1);
		}
		
		tmp2 = 4;
		if(IsVs2p(player)) tmp2 = -1;
		
		BltFastRect(83, bx2 + tmp2, by2 + offset, tmp, 264, 1, 4);
	}
}

// VERSUS���[�h�^TOMOYO-EHEART���X�g�ʂ�2P�����ǂ�������
int IsVs2p(int player) {
	int vs2p;
	
	vs2p = 0;
	if((gameMode[player] == 4) && (player == 1)) vs2p = 1;
	
	return vs2p;
}
