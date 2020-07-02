//������������������������������������������������������������������������������
//   �f����ʂł̑����
//������������������������������������������������������������������������������
void showControl() {
	int		zx, zy, bai;

	// ���o�[�̃J�o�[����
	ExBltRect(sg_spr, coffset + 6, 126, 97, 135, 20, 21);

	// �{�^��
	ExBltRect(sg_spr, coffset + 30, 126, 123 + getPressState(0, 4) * 32, 97, 32, 32);	// A
	ExBltRect(sg_spr, coffset + 50, 132, 123 + getPressState(0, 5) * 32, 97, 32, 32);	// B
	ExBltRect(sg_spr, coffset + 70, 138, 123 + getPressState(0, 6) * 32, 97, 32, 32);	// C
	ExBltRect(sg_spr, coffset + 30, 144, 123 + getPressState(0, 7) * 32, 97, 32, 32);	// D
	ExBltRect(sg_spr, coffset + 50, 150, 123 + getPressState(0, 8) * 32, 97, 32, 32);	// E
	ExBltRect(sg_spr, coffset + 70, 156, 123 + getPressState(0, 9) * 32, 97, 32, 32);	// F

	// ���o�[
	zx = - getPressState(0, 2) + getPressState(0, 3);
	zy = - getPressState(0, 0) + getPressState(0, 1);
	bai = 10 + ((!zx) || (!zy)) * 4;

	ExBltRect(sg_spr, 1 + coffset + zx * bai, 1 + 120 + zy * bai, 92, 98, 30, 30);
}

//������������������������������������������������������������������������������
//   HIDDEN����
//������������������������������������������������������������������������������
void hiddenProc(int player) {
	if(hidden[player] == 1) {
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

	if(hidden[player] == 2) {
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

	if(hidden[player] == 3) {
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

	if(hidden[player] == 4) {
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

	if(hidden[player] == 5) {
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

	if(hidden[player] == 6) {
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

	if(hidden[player] == 7) {
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
//   �t�H���g��\������
//������������������������������������������������������������������������������
// �ʏ�
void printFont(int fontX, int fontY, str *fontStr, int fontColor) {
	int i, sx, sy, stringLength, stringChar, dx, dy;
	
	stringLength = StrLen(fontStr);
	dx = fontX;
	dy = fontY;
	
	for(i = 0; i < stringLength; i++) {
		stringChar = CharAt(fontStr, i);
		
		if(stringChar == 0x0A) {
			// ���s�i\n�j
			dy = dy + 8;
			dx = fontX;
		} else {
			// �����o��
			sx = ((stringChar - 32) % 32) * 8;
			sy = ((stringChar - 32) / 32) * 8 + fontColor * 24;
			ExBltRect(sg_font_n, dx, dy, sx, sy, 8, 8);
			dx = dx + 8;
		}
	}
}

// 8x8�̃O���b�h�P�ʃo�[�W����
void printFontGrid(int fontX, int fontY, str *fontStr, int fontColor) {
	int i, sx, sy, stringLength, stringChar, dx, dy;
	
	stringLength = StrLen(fontStr);
	dx = fontX;
	dy = fontY;
	
	for(i = 0; i < stringLength; i++) {
		stringChar = CharAt(fontStr, i);
		
		if(stringChar == 0x0A) {
			// ���s�i\n�j
			dy = dy + 1;
			dx = fontX;
		} else {
			// �����o��
			sx = ((stringChar - 32) % 32) * 8;
			sy = ((stringChar - 32) / 32) * 8 + fontColor * 24;
			ExBltRect(sg_font_n, dx * 8, dy * 8, sx, sy, 8, 8);
			dx = dx + 1;
		}
	}
}

// �������o�[�W�����i6x9�j
// ��֕��� ;��?  <��-  =��m  >��%  ?��.
void printSMALLFont(int fontX, int fontY, str *fontStr, int fontColor) {
	int i, sx, sy, stringLength, stringChar, dx, dy;
	
	stringLength = StrLen(fontStr);
	dx = fontX;
	dy = fontY;
	
	for(i = 0; i < stringLength; i++) {
		stringChar = CharAt(fontStr, i);
		
		if(stringChar == 0x3F)
			stringChar = 0x3B;	// ?
		else if(stringChar == 0x2D)
			stringChar = 0x3C;	// -
		else if(stringChar == 0x25)
			stringChar = 0x3E;	// %
		else if(stringChar == 0x2E)
			stringChar = 0x3F;	// .
		
		// ���s�i\n�j
		if(stringChar == 0x0A) {
			dy = dy + 9;
			dx = fontX;
		}
		// �X�y�[�X
		else if(stringChar == 0x20) {
			dx = dx + 6;
		}
		// ����
		else if(stringChar <= 64) {
			sx = (stringChar - 48) * 6 + 132;
			sy = fontColor * 9;
			ExBltRect(sg_numberfont, dx, dy, sx, sy + (90 * fonttype), 6, 9);
			dx = dx + 6;
		}
		// �啶��
		else if(stringChar <= 96) {
			sx = (stringChar - 65) * 6;
			sy = fontColor * 18;
			ExBltRect(sg_alphabetfont, dx, dy, sx, sy, 6, 9);
			dx = dx + 6;
		}
		// ������
		else {
			sx = (stringChar - 97) * 6;
			sy = (fontColor * 18) + 9;
			ExBltRect(sg_alphabetfont, dx, dy, sx, sy, 6, 9);
			dx = dx + 6;
		}
	}
}

// �傫���o�[�W�����i�����ƃR���}�L���̂� 12x16�j
void printBIGFont(int fontX, int fontY, str *fontStr, int fontColor) {
	int i, sx, sy, stringLength, stringChar, dx, dy;
	
	stringLength = StrLen(fontStr);
	dx = fontX;
	dy = fontY;
	
	for(i = 0; i < stringLength; i++) {
		stringChar = CharAt(fontStr, i);
		
		if(stringChar == 0x0A) {
			// ���s�i\n�j
			dy = dy + 16;
			dx = fontX;
		} else {
			// �����o��
			sx = (stringChar - 48) * 12;
			sy = fontColor * 16;
			if(sx >= 0) ExBltRect(sg_numberfont, dx, dy, sx, sy + (160 * fonttype), 12, 16);
			dx = dx + 12;
		}
	}
}

// �Ƃ��Ă��������o�[�W���� 6x7
// �����A+ - / : < > �A�A���t�@�x�b�g�啶�����g�p�\ �ꉞ�ȈՓI�Ȏ��l�߂���
void printTinyFont(int fontX, int fontY, str *fontStr) {
	printTinyFontEx(fontX, fontY, fontStr, 1, 0);
}

// �Ƃ��Ă��������o�[�W���� 6x7 ���l�߂Ȃ�
void printTinyFont2(int fontX, int fontY, str *fontStr) {
	printTinyFontEx(fontX, fontY, fontStr, 0, 0);
}

// �Ƃ��Ă��������o�[�W�����i�j 6x7 ���l�߂���
void printTinyFontB(int fontX, int fontY, str *fontStr) {
	printTinyFontEx(fontX, fontY, fontStr, 1, 1);
}

// �Ƃ��Ă��������o�[�W�����i�j 6x7 ���l�߂Ȃ�
void printTinyFontB2(int fontX, int fontY, str *fontStr) {
	printTinyFontEx(fontX, fontY, fontStr, 0, 1);
}

// �Ƃ��Ă��������o�[�W�����i���������j
void printTinyFontEx(int fontX, int fontY, str *fontStr, int xadjust, int color) {
	int i, sx, sy, stringLength, stringChar, dx, dy, cnt;
	
	stringLength = StrLen(fontStr);
	dx = fontX;
	dy = fontY;
	cnt = 0;
	
	for(i = 0; i < stringLength; i++) {
		stringChar = CharAt(fontStr, i) - 1;
		
		if(stringChar == 0x0A - 0x01) {
			// ���s�i\n�j
			dy = dy + 7;
			dx = fontX;
			cnt = 0;
		} else {
			// �����o��
			sx = ((stringChar - 32) % 32) * 6;
			sy = ((stringChar - 32) / 32) * 7 + (color * 21);
			ExBltRect(sg_smallfont, dx - cnt, dy, sx, sy, 6, 7);
			dx = dx + 6;
			if(xadjust) cnt = cnt + 1;
		}
	}
}

//������������������������������������������������������������������������������
//   �^�C�������ԕ\�L�ɂ��� (string[0]�Ɋi�[���Ă���܂�)
//������������������������������������������������������������������������������
void getTime(int i) {
	if(i < 0) i = 0;
	if(i > 359999) i = 359999;
	sprintf(string[0], "%02d:%02d:%02d", i / 3600, (i / 60) % 60, (i % 60) * 5 / 3);
}

// getTime�̊g����
// i: ���ԕ\�L�ɂ��鐔�l
// type: �\���^�C�v�i0=�ʏ� 1=���ƕb�̂� 2=�����_�ȉ��̂݁j
// no: �ǂ�string�ϐ��Ɋi�[���邩
void getTimeEx(int i, int type, int no) {
	if(i < 0) i = 0;
	if(i > 359999) i = 359999;
	
	if(type == 0) {
		sprintf(string[no], "%02d:%02d:%02d", i / 3600, (i / 60) % 60, (i % 60) * 5 / 3);
	} else if(type == 1) {
		sprintf(string[no], "%02d:%02d", i / 3600, (i / 60) % 60);
	} else {
		sprintf(string[no], "%02d", (i % 60) * 5 / 3);
	}
}

//������������������������������������������������������������������������������
//   �w�i�\��
//������������������������������������������������������������������������������
void viewBack() {
	int i, j, no;
	int param;
	
	param = 0;
	executePlugin(0, 14, &param);	// �v���O�C���Ăяo��
	if(param) return;
	
	if(backno < 21) {
		if(back_mov_f[backno] == 0) {
			// �Î~��
			ExBltFastRect(sg_background[backno], 0, 0, 0, 0, 320, 240);
		} else {
			// ����
			ExBltFastRect(sg_background[backno], 0, 0, (back_acnt / 10) * 320, (back_acnt % 10) * 240, 320, 240);
			
			i = back_mov_inter[backno];
			if(i == 0) i = 1;
			
			if(count % i == 0) back_acnt++;
			if(back_acnt >= back_mov_f[backno]) back_acnt = 0;
		}
	}
	
	// �w�i�؂�ւ�
	if(bgfadesw && !demo) {
		if(bgfadelv < 14) {
			bgfadelv++;
			
			// �t�F�[�h�摜��`��
			for(i = 0; i < 5; i++) {
				for(j = 0; j < 5; j++) {
					ExBltRect(sg_bgfade, i * 64, j * 48, 0, bgfadelv * 48, 64, 48);
				}
			}
			
			// ���̔w�i��
			if(bgfadelv == 6) {
				backno = bgfadebg;
				back_acnt = 0;
			}
		} else {
			bgfadesw = 0;
			bgfadelv = 0;
		}
	}
}

//������������������������������������������������������������������������������
//   �X�R�A�\��
//������������������������������������������������������������������������������
void viewScore() {
	int player;
	
	for(player = 0; player <= maxPlay; player++) {
		executePlugin(player, 15, &dummy);	// �v���O�C���Ăяo��
	}
}

//������������������������������������������������������������������������������
//   �t�B�[���h�̔w�i�̕`��
//������������������������������������������������������������������������������
void viewFieldBackground() {
	int player, param;
	
	for(player = 0; player <= maxPlay; player++) {
		param = 0;
		executePlugin(player, 29, &param);
		
		if((param == 0) && (oblk_spawn[player] != 0)) {
			if(oblk_bg[player] == 1) ExBltFast(sg_black, foffset[player] + 8, fyoffset[player] + 40);
			if(oblk_bg[player] == 2) ExBltFast(sg_white, foffset[player] + 8, fyoffset[player] + 40);
		}
	}
}

//������������������������������������������������������������������������������
//   �t�B�[���h�̕`��
//������������������������������������������������������������������������������
void viewField() {
	int player, param;
	
	for(player = 0; player <= maxPlay; player++) {
		param = 0;
		executePlugin(player, 30, &param);
		
		if(!param) {
			// �t�B�[���h�g��\��
			viewFieldFrame(player, 1);
			
			// �t�B�[���h�̃u���b�N��\��
			viewFieldBlock(player);
		}
	}
}

// �t�B�[���h�g��`��
void viewFieldFrame(int player, int all) {
	int temp;
	int param;
	
	param = 0;
	executePlugin(player, 31, &param);
	if(param) return;
	
	// ACE���[�h�̘g�̏o�����聗�e����
	if((blockshadow != 0) && (frame_decoration[player])) {
		if(blkshadow_direction[player]) temp = 2;
		else temp = -2;
		
		if(all) {
			ExBltRect(sg_fld, foffset[player] - 8 + temp, fyoffset[player] + 32, 960, 184, 112, 184);
		} else {
			ExBltRect(sg_fld, foffset[player] - 8 + temp, fyoffset[player] + 32, 960, 184, 112, 8);
		}
	}
	
	// �g
	if((field_spin[player] < 0) || (field_spin[player] > 19)) {
		// ��]�Ȃ�
		if((blockshadow != 0) && (all)) {
			if(blkshadow_direction[player]) temp = 2;
			else temp = -2;
			
			ExBltRect(sg_fld, foffset[player] + temp, fyoffset[player] + 32, framecolor[player] * 96, 184, 96, 184);
		}
		
		ExBltRect(sg_fld, foffset[player], fyoffset[player] + 32, framecolor[player] * 96, 0, 96, 8 + all * 176);
	} else {
		// ��]����
		ExBltRect(sg_3d_fld[framecolor[player]], foffset[player], fyoffset[player] + 17, field_spin[player] * 96, 0, 96, 206);
	}
	
	// ACE���[�h�̘g�̏o������
	if(frame_decoration[player]) {
		if(all) {
			ExBltRect(sg_fld, foffset[player] - 8, fyoffset[player] + 32, 960, 0, 112, 184);
		} else {
			ExBltRect(sg_fld, foffset[player] - 8, fyoffset[player] + 32, 960, 0, 112, 8);
		}
	}
	
	// NEXT��
	if(top_frame == 0) {
		if(all) ExBltRect(sg_topframe, foffset[player], fyoffset[player], 0, 0, 101, 33);
	} else if(top_frame == 1) {
		ExBltRect(sg_topframe, foffset[player] - 15, fyoffset[player], 0, 33, 126, 35);
	}
	
	// NEXT��HOLD�̕���
	if(hnext[player] != 0) printTinyFont(foffset[player] + 38, fyoffset[player], "NEXT");
	if(hold[player] != -2) printTinyFont(foffset[player], fyoffset[player] + 4, "HOLD");
	
	// �A�C�e����
	if(item_name[player]) ExBltRect(sg_itemname, foffset[player] + 65, fyoffset[player], 0, (item_name[player] - 1) * 16, 48, 16);
}

// NEXT��`��
void viewNextBlock(int player) {
	int i, temp, y, j, toffset;
	int tmp_color[4], tmp_oblk;
	int param;
	
	param = 0;
	executePlugin(player, 32, &param);
	if(param) return;
	
	if(hnext[player] == 0) return;
	
	// NEXT1
	temp = getNextBlock(player, 0);
	
	// �F�����߂�
	if(next_item[player * 6]) {
		// �A�C�e��
		tmp_color[0] = next_item[player * 6] + 16;
		tmp_color[1] = tmp_color[0];
		tmp_color[2] = tmp_color[0];
		tmp_color[3] = tmp_color[0];
		tmp_oblk = 0;
	} else {
		// �ʏ�
		tmp_color[0] = next_color[player * 24 + 0];
		tmp_color[1] = next_color[player * 24 + 1];
		tmp_color[2] = next_color[player * 24 + 2];
		tmp_color[3] = next_color[player * 24 + 3];
		tmp_oblk = next_oblk[player * 6];
	}
	
	if(ndelay[player]) {
		// ���ʂɕ\��
		drawBlock(player, foffset[player] + 32, fyoffset[player] + 6 + next_offset[player * 7 + temp],
		          temp, 0, &tmp_color, tmp_oblk * 17, 0);
		
		if((blockshadow != 0) && (!tmp_oblk)) {
			drawBlockShadow(player, foffset[player] + 32, fyoffset[player] + 6 + next_offset[player * 7 + temp],
			                temp, 0, &tmp_color, 0, blkshadow_direction[player], 0, 0, 1);
		}
	} else if(hnext[player] == 1) {
		// NEXT��������̏ꍇ�͏�����NEXT��\��
		if((top_frame == 0) || (top_frame == 2)) toffset = 8;
		else toffset = 0;
		y = fyoffset[player] + 10 + toffset + next_s_offset[player * 7 + temp];
		drawSmallBlock(player, foffset[player] + 48, y, temp, 0, &tmp_color, tmp_oblk);
		
		if((blockshadow != 0) && (!tmp_oblk)) {
			drawBlockShadowSmall(player, foffset[player] + 48, y, temp, 0, &tmp_color, blkshadow_direction[player]);
		}
	}
	
	// NEXT2�ȍ~
	for(i = 0; i < hnext[player] - 1; i++) {
		j = i + 1 - (!ndelay[player]);
		temp = getNextBlock(player, j);
		if((top_frame == 0) || (top_frame == 2)) toffset = 8;
		else toffset = 0;
		y = fyoffset[player] + 10 + toffset + next_s_offset[player * 7 + temp];
		
		// �F�����߂�
		if(next_item[player * 6 + j]) {
			// �A�C�e��
			tmp_color[0] = next_item[player * 6 + j] + 16;
			tmp_color[1] = tmp_color[0];
			tmp_color[2] = tmp_color[0];
			tmp_color[3] = tmp_color[0];
			tmp_oblk = 0;
		} else {
			// �ʏ�
			tmp_color[0] = next_color[player * 24 + j * 4 + 0];
			tmp_color[1] = next_color[player * 24 + j * 4 + 1];
			tmp_color[2] = next_color[player * 24 + j * 4 + 2];
			tmp_color[3] = next_color[player * 24 + j * 4 + 3];
			tmp_oblk = next_oblk[player * 6 + j];
		}
		
		drawSmallBlock(player, foffset[player] + 68 + i * 20, y, temp, 0, &tmp_color, tmp_oblk);
		
		if((blockshadow != 0) && (!tmp_oblk)) {
			drawBlockShadowSmall(player, foffset[player] + 68 + i * 20, y, temp, 0, &tmp_color, blkshadow_direction[player]);
		}
	}
}

// HOLD��`��
void viewHoldBlock(int player) {
	int param;
	int tmp_color[4], tmp_oblk;
	
	param = 0;
	executePlugin(player, 33, &param);
	if(param) return;
	
	if(hold[player] != -1) {
		// �F�����߂�
		if(hold_item[player]) {
			// �A�C�e��
			tmp_color[0] = hold_item[player] + 16;
			tmp_color[1] = tmp_color[0];
			tmp_color[2] = tmp_color[0];
			tmp_color[3] = tmp_color[0];
			tmp_oblk = 0;
		} else {
			// �ʏ�
			if(dhold[player]) {
				tmp_color[0] = 0;
				tmp_color[1] = 0;
				tmp_color[2] = 0;
				tmp_color[3] = 0;
			} else {
				tmp_color[0] = hold_color[player * 4 + 0];
				tmp_color[1] = hold_color[player * 4 + 1];
				tmp_color[2] = hold_color[player * 4 + 2];
				tmp_color[3] = hold_color[player * 4 + 3];
			}
			tmp_oblk = hold_oblk[player];
		}
		
		drawSmallBlock(player, foffset[player] + 4, fyoffset[player] + 12 + next_s_offset[player * 7 + hold[player]],
		           hold[player], 0, &tmp_color, tmp_oblk);
		
		if((blockshadow != 0) && (!tmp_oblk)) {
			drawBlockShadowSmall(player, foffset[player] + 4, fyoffset[player] + 12 + next_s_offset[player * 7 + hold[player]],
			                     hold[player], 0, &tmp_color, blkshadow_direction[player]);
		}
	}
	
	// HOLD���g�p�ł��Ȃ��Ƃ��̏�
	if(dhold[player] == 2) ExBltRect(sg_spr, foffset[player] - 2, fyoffset[player] + 5, 235, 71, 27, 27);
}

// �t�B�[���h��`��
void viewFieldBlock(int player) {
	int i, j, fi, ft, fo, it, temp, dx, dy, tmp_color, tmp_oblk;
	int param;
	
	param = 0;
	executePlugin(player, 34, &param);
	if(param) return;
	
	if(hidden[player] == 10) return;
	
	for(i = 0; i < hiddeny[player]; i++) {
		for(j = 0; j < fldsizex; j++) {
			fi = getFieldBlock(player, j, i);
			
			if(fi > 0) {
				// �u���b�N��`��
				dx = foffset[player] + 8 + (j * 8);
				dy = fyoffset[player] + (i + 3) * 8;
				
				ft = getFieldBlockT(player, j, i);
				fo = getFieldBlockO(player, j, i);
				it = getFieldBlockI(player, j, i);
				
				// �F�����߂�
				if(it) {
					// �A�C�e��
					tmp_color = it + 16;
					tmp_oblk = 0;
				} else {
					// �ʏ�
					tmp_color = fi - 1;
					tmp_oblk = fo;
				}
				
				if((ft >= 1) && (ft <= 8)) {
					drawSBlock(player, dx, dy, tmp_color, 5 + tmp_oblk * 17, 0, 1, ft * 32);
				} else if((ft != 0) && (ft > -10)) {
					drawSBlock(player, dx, dy, tmp_color, 5 + tmp_oblk * 17, 0, 0, 0);
				}
				
				if( (disp_blkline[player]) && ((ft <= -1) || (ft >= 8)) && (!tmp_oblk) ) {
					// �g����`��
					viewFieldBlockSub_DrawLine(player, j, i, dx, dy);
					
					// �e��`��
					if((blockshadow != 0) && (!IsBig[player])) viewFieldBlockSub_DrawShadow(player, j, i, dx, dy, it, tmp_color);
				}
			}
		}
	}
	
	// HIDDEN
	viewFieldBlockSub_Hidden(player);
}

// �g����`��
void viewFieldBlockSub_DrawLine(int player, int x, int y, int dx, int dy) {
	int temp;
	
	temp = getFieldBlock(player, x, y - 1);
	if((temp == 0) || (temp == -2)) ExBltFastRect(sg_blkline, dx    , dy    ,  8,  0, 8, 1);
	temp = getFieldBlock(player, x, y + 1);
	if((temp == 0) || (temp == -2)) ExBltFastRect(sg_blkline, dx    , dy + 7,  8, 15, 8, 1);
	temp = getFieldBlock(player, x - 1, y);
	if((temp == 0) || (temp == -2)) ExBltFastRect(sg_blkline, dx    , dy    ,  8, 16, 1, 8);
	temp = getFieldBlock(player, x + 1, y);
	if((temp == 0) || (temp == -2)) ExBltFastRect(sg_blkline, dx + 7, dy    , 15, 24, 1, 8);
}

// �e��`��
void viewFieldBlockSub_DrawShadow(int player, int x, int y, int dx, int dy, int it, int color) {
	int temp;
	
	if(blkshadow_direction[player]) temp = 1;
	else temp = -1;
	
	if(getFieldBlock(player, x + temp, y) == 0) {
		if(blkshadow_direction[player]) temp = 8;
		else temp = -2;
		
		if((it) || (color >= 10)) {
			ExBltFastRect(sg_blkshadow, dx + temp, dy, 160 + ((color - 10) * 2), 5 * 8, 2, 8);
		} else {
			ExBltFastRect(sg_blkshadow, dx + temp, dy, (blockgraphics[player] * 20) + (color * 2), 5 * 8, 2, 8);
		}
	}
}

// HIDDEN�֘A
void viewFieldBlockSub_Hidden(int player) {
	int i, j, dx, dy, temp;
	
	if(hiddenc[player] < 15) {
		hiddenc[player]++;
		temp = hiddenc[player] / 3;
	} else {
		temp = 5;
	}
	
	for(i = hiddeny[player]; i < fldsizey; i++) {
		for(j = 0; j < 10; j++) {
			dx = foffset[player] + 8 + (j * 8);
			dy = fyoffset[player] + (i + 3) * 8;
			drawSBlock(player, dx, dy, 0, temp, 0, 0, 0);
		}
		temp = 5;
	}
}

//������������������������������������������������������������������������������
//   �u���b�N��`�悷��
//������������������������������������������������������������������������������
void drawBlock(int player, int bx1, int by1, int kind, int rotate, int *color, int bright, int type) {
	int i, j, bx2, by2;
	
	for(i = 0; i < 4; i++) {
		bx2 = bx1 + (blkDataX[kind * 16 + rotate * 4 + player * 112 + i] * 8);
		by2 = by1 + (blkDataY[kind * 16 + rotate * 4 + player * 112 + i] * 8);
		drawSBlock(player, bx2, by2, color[i], bright, 0, 0, 0);
		
		// �z�[���h�u���b�N�̘g��
		if((type) && (hold_count[player] >= 2) && (dhold[player] == 1))
			drawBlockLine(player, bx2, by2, kind, rotate, i, 2 * (count % 16 < 8), 0);
	}
}

// �r�b�O�p
void drawBigBlock(int player, int bx1, int by1, int kind, int rotate, int *color, int bright, int type) {
	int i, j, bx2, by2;
	
	for(i = 0; i < 4; i++) {
		bx2 = bx1 + (blkDataX[kind * 16 + rotate * 4 + player * 112 + i] * 16);
		by2 = by1 + (blkDataY[kind * 16 + rotate * 4 + player * 112 + i] * 16);
		drawSBlock(player, bx2, by2, color[i], bright, 1, 0, 0);
		
		// �z�[���h�u���b�N�̘g��
		if((type) && (hold_count[player] >= 2) && (dhold[player] == 1))
			drawBlockLine(player, bx2, by2, kind, rotate, i, 2 * (count % 16 < 8), 1);
	}
}

// �������u���b�N��`��
void drawSmallBlock(int player, int bx1, int by1, int kind, int rotate, int *color, int bright) {
	int i, j, bx2, by2;
	
	for(i = 0; i < 4; i++) {
		bx2 = bx1 + (blkDataX[kind * 16 + rotate * 4 + player * 112 + i] * 4);
		by2 = by1 + (blkDataY[kind * 16 + rotate * 4 + player * 112 + i] * 4);
		drawSBlock(player, bx2, by2, color[i], bright, 2, 0, 0);
	}
}

// �i�r�Q�[�V�����u���b�N��`��
void drawNaviBlock(int player, int bx1, int by1, int kind, int rotate, int *color, int bright) {
	int i, bx2, by2;
	
	for(i = 0; i < 4; i++) {
		bx2 = bx1 + (blkDataX[kind * 16 + rotate * 4 + player * 112 + i] * 8);
		by2 = by1 + (blkDataY[kind * 16 + rotate * 4 + player * 112 + i] * 8);
		
		ExBltFastRect(sg_guide, bx2, by2, color[i] * 8, bright * 8, 8, 8);
	}
}

// ���ݑ��쒆�̃u���b�N��`��
void drawCBlock(int player, int kosa, int flash) {
	int i, bx1, by1, kosa;
	int tmp_color[4], tmp_oblk;
	
	bx1 = foffset[player] + 8 + (bx[player] * 8);
	by1 = fyoffset[player] + 24 + (by[player] * 8);
	
	// �F�����߂�
	if(current_item[player]) {
		tmp_color[0] = 16 + current_item[player];	// �A�C�e��
		tmp_color[1] = tmp_color[0];
		tmp_color[2] = tmp_color[0];
		tmp_color[3] = tmp_color[0];
		tmp_oblk = 0;
	} else if((current_rollroll[player]) || (flash)) {
		tmp_color[0] = 0;	// �D�F
		tmp_color[1] = 0;
		tmp_color[2] = 0;
		tmp_color[3] = 0;
		tmp_oblk = current_oblk[player];
	} else {
		tmp_color[0] = current_color_m[0 + player * 4];	// �ʏ�
		tmp_color[1] = current_color_m[1 + player * 4];
		tmp_color[2] = current_color_m[2 + player * 4];
		tmp_color[3] = current_color_m[3 + player * 4];
		tmp_oblk = current_oblk[player];
	}
	
	if(!IsBig[player]) {
		kosa = kosa + tmp_oblk * 17;
		drawBlock(player, bx1, by1, blk[player], rt[player], &tmp_color, kosa, 1);
		
		if((blockshadow != 0) && (!tmp_oblk))
			drawBlockShadow(player, bx1, by1, blk[player], rt[player], &tmp_color, kosa, blkshadow_direction[player], bx[player], by[player], 0);
	} else {
		kosa = kosa + tmp_oblk * 7;
		drawBigBlock(player, bx1, by1, blk[player], rt[player], &tmp_color, kosa, 1);
	}
}

// �S�[�X�g�u���b�N��`��
void drawGBlock(int player, int bottom) {
	int i, bx1, by1;
	int tmp_color[4], tmp_oblk;
	
	if(!ghost[player]) return;
	
	bx1 = foffset[player] + 8 + (bx[player] * 8);
	by1 = fyoffset[player] + 24 + (bottom * 8);
	
	// �F�����߂�
	if(current_item[player]) {
		tmp_color[0] = 16 + current_item[player];	// �A�C�e��
		tmp_color[1] = tmp_color[0];
		tmp_color[2] = tmp_color[0];
		tmp_color[3] = tmp_color[0];
		tmp_oblk = 0;
	} else if(current_rollroll[player]) {
		tmp_color[0] = 0;	// ���[�����[��
		tmp_color[1] = 0;
		tmp_color[2] = 0;
		tmp_color[3] = 0;
		tmp_oblk = current_oblk[player];
	} else {
		tmp_color[0] = current_color_m[0 + player * 4];	// �ʏ�
		tmp_color[1] = current_color_m[1 + player * 4];
		tmp_color[2] = current_color_m[2 + player * 4];
		tmp_color[3] = current_color_m[3 + player * 4];
		tmp_oblk = current_oblk[player];
	}
	
	if(!IsBig[player]) {
		drawBlock(player, bx1, by1, blk[player], rt[player], &tmp_color, 12 + tmp_oblk * 17, 0);
		
		if((blockshadow != 0) && (!tmp_oblk))
			drawBlockShadow(player, bx1, by1, blk[player], rt[player], &tmp_color, 12, blkshadow_direction[player], bx[player], bottom, 0);
	} else {
		drawBigBlock(player, bx1, by1, blk[player], rt[player], &tmp_color, 6 + tmp_oblk * 7, 0);
	}
}

// 1�}�X���̃u���b�N��`��
void drawSBlock(int player, int bx2, int by2, int color, int bright, int size, int bl_on, int bl_tr) {
	int rcol, bl_tr2, plane;
	bl_tr2 = 256 - bl_tr;
	
	// NORMAL
	if(size == 0) {
		if(color >= 10) {
			plane = sg_iblk_n;
			rcol = (color * 8) - 80;
		} else {
			plane = sg_blk_n;
			rcol = (blockgraphics[player] * 80) + (color * 8);
		}
		
		if(!bl_on) {
			ExBltFastRect(plane, bx2, by2, rcol, bright * 8, 8, 8);
		} else {
			BlendExBltRect(plane, bx2, by2, rcol, bright * 8, 8, 8, bl_tr, bl_tr, bl_tr, bl_tr2, bl_tr2, bl_tr2);
		}
	}
	// BIG
	else if(size == 1) {
		if(color >= 10) {
			plane = sg_iblk_b;
			rcol = (color * 16) - 160;
		} else {
			plane = sg_blk_b;
			rcol = (blockgraphics[player] * 160) + (color * 16);
		}
		
		if(!bl_on) {
			ExBltFastRect(plane, bx2, by2, rcol, bright * 16, 16, 16);
		} else {
			BlendExBltRect(plane, bx2, by2, rcol, bright * 16, 16, 16, bl_tr, bl_tr, bl_tr, bl_tr2, bl_tr2, bl_tr2);
		}
	}
	// SMALL
	else {
		if(color >= 10) {
			plane = sg_iblk_s;
			rcol = (color * 4) - 40;
		} else {
			plane = sg_blk_s;
			rcol = (blockgraphics[player] * 40) + (color * 4);
		}
		
		if(!bl_on) {
			ExBltFastRect(plane, bx2, by2, rcol, bright * 4, 4, 4);
		} else {
			BlendExBltRect(plane, bx2, by2, rcol, bright * 4, 4, 4, bl_tr, bl_tr, bl_tr, bl_tr2, bl_tr2, bl_tr2);
		}
	}
}

// 1�}�X���̃u���b�N��`��i�g��k���G�t�F�N�g�p�j
void drawSBlockR(int player, int bx2, int by2, int color, int zoom) {
	int plane, rcol;
	
	if(color >= 10) {
		plane = sg_iblk_n;
		rcol = (color * 8) - 80;
	} else {
		plane = sg_blk_n;
		rcol = (blockgraphics[player] * 80) + (color * 8);
	}
	
	ExBltFastRectR(sg_blk_n, bx2, by2, rcol, 0, 8, 8, zoom, zoom);
}

// �u���b�N�̘g����`��
void drawBlockLine(int player, int bx2, int by2, int kind, int rotate, int index, int bright, int size) {
	int linkdata;
	linkdata = blkDataL[kind * 16 + rotate * 4 + player * 112 + index];
	
	if(!size) {
		// �ʏ�T�C�Y
		if(BitTest(linkdata, 0) == 0) ExBltFastRect(sg_blkline, bx2    , by2    , bright * 8    ,  0, 8, 1);
		if(BitTest(linkdata, 1) == 0) ExBltFastRect(sg_blkline, bx2    , by2 + 7, bright * 8    , 15, 8, 1);
		if(BitTest(linkdata, 2) == 0) ExBltFastRect(sg_blkline, bx2    , by2    , bright * 8    , 16, 1, 8);
		if(BitTest(linkdata, 3) == 0) ExBltFastRect(sg_blkline, bx2 + 7, by2    , bright * 8 + 7, 24, 1, 8);
	} else {
		// BIG�T�C�Y
		if(BitTest(linkdata, 0) == 0) ExBltFastRect(sg_blkline, bx2     , by2     , 24 + bright * 16     ,  0, 16,  1);
		if(BitTest(linkdata, 1) == 0) ExBltFastRect(sg_blkline, bx2     , by2 + 15, 24 + bright * 16     , 31, 16,  1);
		if(BitTest(linkdata, 2) == 0) ExBltFastRect(sg_blkline, bx2     , by2     , 24 + bright * 16     , 32,  1, 16);
		if(BitTest(linkdata, 3) == 0) ExBltFastRect(sg_blkline, bx2 + 15, by2     , 24 + bright * 16 + 15, 48,  1, 16);
	}
}

// �u���b�N�̉e��`��
void drawBlockShadow(int player, int bx1, int by1, int kind, int rotate, int *color, int bright, int direction, int x, int y, int type) {
	int i, bx2, by2, blkx, blky, linkdata, offset, rcol, temp, temp2;
	
	for(i = 0; i < 4; i++) {
		linkdata = blkDataL[kind * 16 + rotate * 4 + player * 112 + i];
		blkx = blkDataX[kind * 16 + rotate * 4 + player * 112 + i];
		blky = blkDataY[kind * 16 + rotate * 4 + player * 112 + i];
		
		if(direction) temp = 1;
		else temp = -1;
		
		if(type) temp2 = 0;
		else temp2 = getFieldBlock(player, x + blkx + temp, y + blky);
		
		if((temp2 == 0) && (BitTest(linkdata, 2 + direction) == 0)) {
			bx2 = bx1 + (blkx * 8);
			by2 = by1 + (blky * 8);
			
			if(direction) offset = 8;
			else offset = -2;
			
			if(color[i] >= 10) rcol = 160 + ((color[i] - 10) * 2);
			else rcol = (blockgraphics[player] * 20) + (color[i] * 2);
			
			ExBltFastRect(sg_blkshadow, bx2 + offset, by2, rcol, bright * 8, 2, 8);
		}
	}
}

// �u���b�N�̉e��`��i�������o�[�W�����j
void drawBlockShadowSmall(int player, int bx1, int by1, int kind, int rotate, int *color, int direction) {
	int i, bx2, by2, blkx, blky, linkdata, offset, rcol, temp;
	
	for(i = 0; i < 4; i++) {
		linkdata = blkDataL[kind * 16 + rotate * 4 + player * 112 + i];
		blkx = blkDataX[kind * 16 + rotate * 4 + player * 112 + i];
		blky = blkDataY[kind * 16 + rotate * 4 + player * 112 + i];
		
		if(direction) temp = 1;
		else temp = -1;
		
		if(BitTest(linkdata, 2 + direction) == 0) {
			bx2 = bx1 + (blkx * 4);
			by2 = by1 + (blky * 4);
			
			if(direction) offset = 4;
			else offset = -1;
			
			if(color[i] >= 10) rcol = 80 + ((color[i] - 10) * 1);
			else rcol = (blockgraphics[player] * 10) + (color[i] * 1);
			
			ExBltFastRect(sg_blkshadow, bx2 + offset, by2, rcol, 264, 1, 4);
		}
	}
}
