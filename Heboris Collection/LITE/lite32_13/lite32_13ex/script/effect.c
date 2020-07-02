//������������������������������������������������������������������������������
//   �I�u�W�F�N�g�֘A
//������������������������������������������������������������������������������

// �I�u�W�F�N�g���쐬
void objectCreate(int p, int s, int x, int y, int v, int w, int j, int c) {
	int		i;
	
	for(i = 0; i < breakmax; i++)
		if(obj[i] == 0) {
			obj[i] = s;
			objx[i] = x;
			objy[i] = y;
			objv[i] = v;
			objw[i] = w;
			objj[i] = j;
			objc[i] = c;
			obja[i] = 0;	// #LITE07
			objp[i] = p;	// #LITE07
			
			break;
		}
}

// ��ʏ�̃I�u�W�F�N�g��S�ď���
void objectClear() {
	int i;
	for(i = 0; i < breakmax; i++) obj[i] = 0;
}

// �w�肵���v���C���[�̃I�u�W�F�N�g�����S�ď���
void objectClearPl(int player) {
	int i;
	for(i = 0; i < breakmax; i++) {
		if(objp[i] == player) obj[i] = 0;
	}
}

// �I�u�W�F�N�g��`��
void objectExecute() {
	int		i, num;
	
	num = 0;
	
	for(i = 0; i < breakmax; i++) {
		if( obj[i] ) {
			num++;
			
			jump(obj[i] - 1, o01, o02, o03, o04, o05, o06, o07, o08, o09);
			
			/*
			switch(obj[i]) {
				case 1: goto o01;
				case 2: goto o02;
				case 3: goto o03;
				case 4: goto o04;
				case 5: goto o05;
				case 6: goto o06;
				case 7: goto o07;
				case 8: goto o08;
				case 9: goto o09;
			}
			*/
			
			o01: objectStatBlock(i);				// 01 -> ��юU��u���b�N
					goto next;
			o02: objectAllCrear(i);					// 02 -> �S����
					goto next;
			o03: objectHanabi(i);					// 03 -> �ԉ�
					goto next;
			o04: objectNagareboshiP(i);				// 04 -> ���ꐯ�i�{�́j
					goto next;
			o05: objectNagareboshiC(i);				// 05 -> ���ꐯ�i�q�j
					goto next;
			o06: objectPopBlock(i);					// 06 -> �e����ԃu���b�N
					goto next;
			o07: objectGetmedal(i);					// 07 -> ���_���l��
					goto next;
			o08: objectItemWarning(i);				// 08 -> �A�C�e�������x��
					goto next;
			o09: objectItemErase(i);				// 09 -> �A�C�e�������G�t�F�N�g
					goto next;
			
			next:
		}
	}
}

// ��юU��u���b�N
void objectStatBlock(int no) {
	int		zoom, offset, player;
	
	if( (breakeffect == 0) || (objj[no] == 8) || (objj[no] == 9) ) {
		obj[no] = 0;
		return;
	}
	
	player = objp[no];
	
	if(objj[no] >= 10) {
		// �v���`�i�u���b�N
		objectplatina_erase(no);
		
		// +1
		if((obja[no] < 32) && (gameMode[player] == 6) && (tomoyo_timebonus[player]))
			ExBltRect(3, objx[no], objy[no] - obja[no], 212 + (objj[no] - 10) * 12, 64, 12, 7);
	} else if((heboGB[player] == 1) || (breakeffect == 4)) {
		// �I�[���h�X�^�C��GB
		if(obja[no] % 30 < 15)
			drawSingleBlock(player, objx[no], objy[no], 0, 0, 0, 0, 0, 0, 0);
		else if(obja[no] < 40)
			drawSingleBlock(player, objx[no], objy[no], 0, objj[no], 0, 0, 0, 0, 0);
		
		if((obja[no] >= 59) || (obja[no] >= wait2[player])) obj[no] = 0;
	} else if((heboGB[player] == 2) || (breakeffect == 5)) {
		// �I�[���h�X�^�C��AC
		drawSingleBlock(player, objx[no], objy[no], 0, objj[no], 6 + (obja[no] / 2), 0, 0, 0, 0);
		if((obja[no] >= 20) || (obja[no] >= wait2[player])) obj[no] = 0;
	} else if( (breakeffect == 1) || ((gameMode[player] == 0) && (beginner_effect)) ) {
		// �e����ԃG�t�F�N�g
		objectPopBlock(no);
		return;
	} else if(breakeffect == 2) {
		// �VTAP/TI
		ExBltRect(31 + objj[no], objx[no] - 44, objy[no] - 20 - (!breakgraphics) * 24, 
					(obja[no] % (8 - (2 * breakgraphics))) * 96, (obja[no] / (8 - (2 * breakgraphics))) * 96, 96, 96);
		if(obja[no] >= 36) obj[no] = 0;
	} else {
		// ��TAP/TI
		ExBltRect(31, objx[no] - 12, objy[no] - 12, (obja[no] / 3) * 32, objj[no] * 32, 32, 32);
		if(obja[no] >= 18) obj[no] = 0;
	}
	
	if(!beffect_speed) {
		if((wait1[player] / 2) + wait2[player] <= 5)
			obja[no] = obja[no] + 3;
		else if((wait1[player] / 2) + wait2[player] <= 10)
			obja[no] = obja[no] + 2;
		else
			obja[no]++;
	} else {
		obja[no] = obja[no] + beffect_speed;
	}
}

// �S����
void objectAllCrear(int no) {
	int player;
	player = objp[no];

	obja[no]++;
	if(objy[no] > 13) objy[no]--;

	// BRAVO!
	ExBltRect(49, foffset[player] - 2, (objy[no] - 1) * 8, 100, 150 + 25 * (count % 4 / 2), 100, 25);

	if(isNormalMode(player)) printFont(boffset[player] + 3, objy[no] + 4, "e 4", 5);

	if(obja[no] > 80) obj[no] = 0;
}

// �ԉ�
void objectHanabi(int no) {
	if( (objj[no] < 0) || (objj[no] > 6) ) {
		obj[no] = 0;
		return;
	}
	
	if(!obja[no]) PlaySE(33);
	
	// 96x96
	// 48frames
	ExBltRect(39 + objj[no], objx[no], objy[no], (obja[no] % 6) * 96, (obja[no] / 6) * 96, 96, 96);
	obja[no]++;
	if(obja[no] >= 48) obj[no] = 0;
}

//�v���`�i�u���b�N�����G�t�F�N�gC7T2.8
void objectplatina_erase(int no) {
	// 32x32
	// 60frames
	ExBltRect(10 + objj[no] - 10, objx[no] - 12, objy[no] - 12, (obja[no] % 10) * 32, (obja[no] / 10) * 32, 32, 32);
	if(obja[no] >= 59) obj[no] = 0;
}

// ���ꐯ�i���W�v�Z�j
void objectNagareboshiP(int no) {
	if(!obja[no]) PlaySE(46);
	
	objx[no] = objx[no] - 4;
	objy[no] = objy[no] + 6;
	objectCreate(objp[no], 5, objx[no], objy[no], 0, 0, 0, 0);
	
	obja[no]++;
	if(obja[no] >= 30) obj[no] = 0;
}

// ���ꐯ�i�`��j
void objectNagareboshiC(int no) {
	ExBltRect(20, objx[no], objy[no], (obja[no] % 6) * 32, (obja[no] / 6) * 32, 32, 32);
	obja[no]++;
	if(obja[no] >= 35) obj[no] = 0;
}

// �e����ԃu���b�N
void objectPopBlock(int no) {
	int		zoom, offset, player;

	if( (breakeffect == 0) || (objj[no] == 8) || (objj[no] == 9) ) {
		obj[no] = 0;
		return;
	}

	player = objp[no];

	if(obja[no] == 0) {
		objx[no] = objx[no] * 100;
		objy[no] = objy[no] * 100;
	}

	objx[no] = objx[no] + objv[no];
	objy[no] = objy[no] + objw[no];

	objw[no] = objw[no] + 250;
	objc[no] = objc[no] + 15;

	zoom = objc[no] * 65536 / 100;
	offset = (objc[no] - 100) * 8 / 200;

	drawSingleBlockR(player, objx[no] / 100 - offset, objy[no] / 100 - offset, objj[no], zoom);

	if((objy[no] + offset * 100) > 24000) obj[no] = 0;

	if(!beffect_speed) {
		if((wait1[player] / 2) + wait2[player] <= 5)
			obja[no] = obja[no] + 3;
		else if((wait1[player] / 2) + wait2[player] <= 10)
			obja[no] = obja[no] + 2;
		else
			obja[no]++;
	} else {
		obja[no] = obja[no] + beffect_speed;
	}
}

// ���_���l��
// objv ���_���̎�� 0:AC 1:ST 2:SK 3:CO
// objc ���_���̒i�K 0:�� 1:�� 2:��
void objectGetmedal(int no) {
	int i, j, k;
	
	if(obja[no] <= 8) {
		k = obja[no];
		i = (16 * k / 2 - 16) / 2;
		j = (12 * k / 2 - 12) / 2;
		k = 65536 * k / 2;
	} else {
		k = 16 - obja[no];
		i = (16 * k / 3 - 16) / 2;
		j = (12 * k / 3 - 12) / 2;
		k = 65536 * k / 3;
		
		if(k < 65536) {
			k = 65536;
			i = 0;
			j = 0;
		}
	}
	
	ExBltRectR(0, objx[no] - i, objy[no] - j, objv[no] * 16, objc[no] * 12, 16, 12, k, k);
	
	obja[no]++;
	
	if(obja[no] >= 16) {
		obj[no] = 0;
		
		// ���_���\���t���OON
		if(objv[no] == 0) medal_visible_ac[objp[no]] = 1;
		if(objv[no] == 1) medal_visible_st[objp[no]] = 1;
		if(objv[no] == 2) medal_visible_sk[objp[no]] = 1;
		if(objv[no] == 3) medal_visible_co[objp[no]] = 1;
	}
}

// �A�C�e�������x��
void objectItemWarning(int no) {
	int player;
	player = objp[no];
	
	if(!obja[no]) PlaySE(49);	// warning.wav
	if((objj[no] == 8) && (!obja[no])) PlaySE(51);	// timestop.wav
	
	ExBltRect(49, foffset[player], 84, 0, 150 + 25 * (count % 4 / 2), 100, 25);
	
	if(objj[no] >= 0){
		ExBltRect(46, (boffset[player] + 1) * 8, 116, (8 * objj[no]) + 56, 0, 8, 8);
		ExBltRect(79, (boffset[player] + 2) * 8, 112, 0, objj[no] * 16, 48, 16);
		ExBltRect(46, (boffset[player] + 8) * 8, 116, (8 * objj[no]) + 56, 0, 8, 8);
	}
	
	obja[no]++;
	if(obja[no] > 40) obj[no] = 0;
}

// �A�C�e�������G�t�F�N�g
void objectItemErase(int no) {
	ExBltRect(29, objx[no] - 36, objy[no] - 36, (obja[no] % 6) * 80, (obja[no] / 6) * 80, 80, 80);
	
	obja[no]++;
	if(obja[no] >= 30) obj[no] = 0;
}
