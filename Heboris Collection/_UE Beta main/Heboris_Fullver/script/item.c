//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.26 - ���[�U�[�i16t�j
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 1]�F�I����Ɉړ�����X�e�[�^�X
// statc[player * 10 + 2]�F16t���H
void statLaser(int player) {
	int i,j,move,waitA,waitB;
	
//	dolaser[player] = 0;
	
	waitA = 30 + (wait1[player] * 3);
	waitB = waitA + 34 + wait1[player];
	
	padRepeat(player);
	if((ace_irs) && (statc[player * 10 + 0] > 120)) doIRS2(player);	// ACE��IRS C7U1.5
	
	if(statc[player * 10 + 0] == 0){	//�ŏ�
		if(statc[player * 10 + 2] == 0){//���[�U�[
			lasernum[player] = 1;
			laserpos[0 + 4 * player] = bx[player] + rand(4,player) - 2;
			if(laserpos[0 + 4 * player] < 0) laserpos[0 + 4 * player] = 0;
			if(laserpos[0 + 4 * player] > fldsizew[player] - 1) laserpos[0 + 4 * player] = fldsizew[player] - 1;
			rapid_c[player] = 0;
			statc[player * 10 + 0]++;
		}else{//16t
			lasernum[player] = 1;
			laserpos[0 + 4 * player] = bx[player] + rand(4,player) - 2;//���[
			if(laserpos[0 + 4 * player] < 0) laserpos[0 + 4 * player] = 0;
			if(laserpos[0 + 4 * player] > fldsizew[player] - 3) laserpos[0 + 4 * player] = fldsizew[player] - 3;
			rapid_c[player] = 0;
			statc[player * 10 + 0]++;
		}
	} else {
		if(statc[player * 10 + 2] == 0){//���[�U�[
			if(statc[player * 10 + 0] < waitA){	//���[�U�[���ˑO
				if(statc[player * 10 + 0] % 5 == 0)
					PlaySE(3);
				if( ( getPushState(player, 4)) || ( getPushState(player, 5)) || ( getPushState(player, 6)) )
					rapid_c[player]++;
				if((rapid_c[player] > 4) && (lasernum[player] < 4)){	//���[�U�[�𑝂₷�i�ő�4�{�j
					lasernum[player]++;
					laserpos[lasernum[player] - 1 + 4 * player ] = rand(fldsizew[player] - 1,player);
					rapid_c[player] = 0;
				}
				//�Ə����ړ�
				// ��	�Ə��͓������ɂ�������
				if((getPushState(player, 3)) && (statc[player * 10 + 0] % 10 < 2)){
					for(i = 0; i < lasernum[player]; i++){
						if(laserpos[i + 4 * player] < fldsizew[player] - 1) laserpos[i + 4 * player]++;
					}
				}
				// ��	�ړ����͂̎�t�͈��Ԋu��
				if((getPushState(player, 2)) && (statc[player * 10 + 0] % 10 < 2)){
					for(i = 0; i < lasernum[player]; i++){
						if(laserpos[i + 4 * player] > 0) laserpos[i + 4 * player]--;
					}
				}
				// �Ə���`��
				for(i = 0; i < lasernum[player]; i++){
					ExBltRect(78, ((laserpos[i + 4 * player] + 15 + 24 * player - 12 * maxPlay) - 1) * 8, (4 - 1) * 8, 0, ((statc[player * 10 + 0] % 36) / 6) * 24, 24, 24);
				}
			} else if(statc[player * 10 + 0] == waitA){	// ���[�U�[����
				PlaySE(12);
				for(i = 0; i < lasernum[player]; i++){	// �Ə������̃u���b�N������
					ExBltRect(78, (laserpos[i + 4 * player] + 15 + 24 * player - 12 * maxPlay) * 8, 5 * 8, 24, 0, 8, 160);
					ExBltRect(78, ((laserpos[i + 4 * player] + 15 + 24 * player - 12 * maxPlay) - 1) * 8, (4 - 1) * 8, 0, 0, 24, 24);
					for(j = 0; j <= fldsizeh[player]; j++){
						if(fld[laserpos[i + 4 * player] + j * fldsizew[player] + player * 220] != 0){
							objectCreate(player, 1, (laserpos[i + 4 * player] + 15 + 24 * player - 12 * maxPlay) * 8, (j + 3) * 8, (laserpos[i + 4 * player] - 5) * 120 + 20 - Rand(40), - 1900 + Rand(150), fld[laserpos[i + 4 * player] + j * 10 + player * 220], 100);
							fld[laserpos[i + 4 * player] + j * fldsizew[player] + player * 220] = 0;
							fldt[laserpos[i + 4 * player] + j * fldsizew[player] + player * 220] = 0;
							fldi[laserpos[i + 4 * player] + j * fldsizew[player] + player * 220] = 0;
							grayoutLackedBlock(player, flds[laserpos[i + player * 4] + j * 10 + player * 220]);
							flds[laserpos[i + 4 * player] + j * fldsizew[player] + player * 220] = 0;
	
						}
					}
				}
				scanItem(player);
			} else {	// ���[�U�[���ˌ�
				for(i = 0; i < lasernum[player]; i++){
					if(statc[player * 10 + 0] - waitA < 34){
						j = (statc[player * 10 + 0] - waitA) / 2;
						ExBltRect(78, (laserpos[i + 4 * player] + 15 + 24 * player - 12 * maxPlay) * 8, 5 * 8, 24+(j*8), 0, 8, 160);
					}
					ExBltRect(78, ((laserpos[i + 4 * player] + 15 + 24 * player - 12 * maxPlay) - 1) * 8, (4 - 1) * 8, 0, 0, 24, 24);
				}
			}
		}else{//16t
			if(statc[player * 10 + 0] < waitA){	//���[�U�[���ˑO
				if(statc[player * 10 + 0] % 6 == 0)
					PlaySE(5);//�J�`�J�`
				laserpos[1 + 4 * player ] = laserpos[0 + 4 * player ] + 1;//�������Ԗ�
				laserpos[2 + 4 * player ] = laserpos[0 + 4 * player ] + 2;//������3�Ԗ�
				//�Ə����ړ�
				// ��	�Ə��͓������ɂ�������
				if(getPushState(player, 3)){
						if(laserpos[0 + 4 * player] < fldsizew[player] - 3) laserpos[0 + 4 * player]++;
				}
				// ��	�ړ����͂̎�t�͈��Ԋu��
				if(getPushState(player, 2)){
						if(laserpos[0 + 4 * player] > 0) laserpos[0 + 4 * player]--;
				}
				// ����`��
				ExBltRect(3, ((laserpos[0 + 4 * player] + 15 + 24 * player - 12 * maxPlay) - 1) * 8, 10, 260, 399, 40, 21);
				printFont(16+laserpos[0 + 4 * player]+24 * player - 12 * maxPlay, 5, "k", (count % 2));
				printFont(15+24 * player - 12 * maxPlay, 6, "<L R>:MOVE", (count % 2));
			} else if(statc[player * 10 + 0] >= waitA){	// ���[�U�[����
				for(i = 0; i < 3; i++){	// �Ə������̃u���b�N������
//					for(j = 0; j <= fldsizeh[player]; j++){
					j = (statc[player * 10 + 0] - waitA) * 2;
					if((j - 1 >= 0) && (j - 1 <= fldsizeh[player])){
						if(fld[laserpos[i + 4 * player] + (j-1) * fldsizew[player] + player * 220] != 0){
						//	objectCreate(player, 1, (laserpos[i + 4 * player] + 15 + 24 * player - 12 * maxPlay) * 8, (j + 2) * 8, (laserpos[i + 4 * player] - 5) * 120 + 20 - Rand(40), - 1900 + Rand(150), fld[laserpos[i + 4 * player] + j * 10 + player * 220], 100);
							fld[laserpos[i + 4 * player] + (j-1) * fldsizew[player] + player * 220] = 0;
							fldt[laserpos[i + 4 * player] + (j-1) * fldsizew[player] + player * 220] = 0;
							fldi[laserpos[i + 4 * player] + (j-1) * fldsizew[player] + player * 220] = 0;
							grayoutLackedBlock(player, flds[laserpos[i + player * 4] + (j-1) * 10 + player * 220]);
							flds[laserpos[i + 4 * player] + (j-1) * fldsizew[player] + player * 220] = 0;
							PlaySE(2);
						}
					}
					if((j >= 0) && (j <= fldsizeh[player])){
						if(fld[laserpos[i + 4 * player] + j * fldsizew[player] + player * 220] != 0){
						//	objectCreate(player, 1, (laserpos[i + 4 * player] + 15 + 24 * player - 12 * maxPlay) * 8, (j + 3) * 8, (laserpos[i + 4 * player] - 5) * 120 + 20 - Rand(40), - 1900 + Rand(150), fld[laserpos[i + 4 * player] + j * 10 + player * 220], 100);
							fld[laserpos[i + 4 * player] + j * fldsizew[player] + player * 220] = 0;
							fldt[laserpos[i + 4 * player] + j * fldsizew[player] + player * 220] = 0;
							fldi[laserpos[i + 4 * player] + j * fldsizew[player] + player * 220] = 0;
							grayoutLackedBlock(player, flds[laserpos[i + player * 4] + j * 10 + player * 220]);
							flds[laserpos[i + 4 * player] + j * fldsizew[player] + player * 220] = 0;
							PlaySE(2);
						}
					}
				}
				if(j <= fldsizeh[player]) scanItem(player);
			//	j = statc[player * 10 + 0] - waitA;
				ExBltRect(3, ((laserpos[0 + 4 * player] + 15 + 24 * player - 12 * maxPlay) - 1) * 8, ((j + 3)*8) - 20, 260, 399, 40, 21);
			}
		}
		
		statc[player * 10 + 0]++;
		
		if(statc[player * 10 + 0] >= waitB){
			stat[player] = statc[player * 10 + 1];
			statc[player * 10] = 0;
			statc[player * 10 + 1] = 0;
			statc[player * 10 + 2] = 0;
			
			statc[player * 10 + 1] = stat[player];
			stat[player] = 22;
		}
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.27 - �l�K�t�B�[���h
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 1]�F�I����Ɉړ�����X�e�[�^�X
void statNegafield(int player) {
	int i,j,y,waitA;
	
//	donega[player] = 0;
	
	waitA = 90 + wait1[player];
	
	padRepeat(player);
	if(ace_irs) doIRS2(player);	// ACE��IRS C7U1.5
	
	if(statc[player * 10 + 0] == 0){	//�ŏ�
		for(i = 0;i < 10; i++)
//			nega_pos[i + 10 * player] = checkFieldTop2(player,i);
			nega_pos[i + 10 * player] = checkFieldTop(player);
		statc[player * 10 + 0]++;
	} else {
		if(statc[player * 10 + 0] <= 88){
		if(statc[player * 10 + 0] % 4 == 0){
			y = 22 - (statc[player * 10 + 0] / 4);
			for(i = 0;i < 10; i++){
				if(fld[i + y * fldsizew[player] + player * 220] != 0){	// �u���b�N���󔒂�
					PlaySE(5);
					fld[i + y * fldsizew[player] + player * 220] = 0;
					fldt[i + y * fldsizew[player] + player * 220] = 0;
					fldi[i + y * fldsizew[player] + player * 220] = 0;
					grayoutLackedBlock(player, flds[i + y * 10 + player * 220]);
					flds[i + y * fldsizew[player] + player * 220] = 0;
				} else if(y >= nega_pos[i + 10 * player]){			// �󔒂��u���b�N��
					PlaySE(5);
					fld[i + y * fldsizew[player] + player * 220] = (y % 7) + 2;
					fldt[i + y * fldsizew[player] + player * 220] = -1;
					grayoutLackedBlock(player, flds[i + y * 10 + player * 220]);
					flds[i + y * fldsizew[player] + player * 220] = 0;
					if((hidden[player] == 8) && (m_roll_blockframe))
						fldt[i + y * fldsizew[player] + player * 220] = -60;
					else if(hidden[player] == 8)
						fldt[i + y * fldsizew[player] + player * 220] = 0;
				}
			}
			scanItem(player);
		}
		}
		statc[player * 10 + 0]++;
		if(statc[player * 10 + 0] >= waitA){
			stat[player] = statc[player * 10 + 1];
			statc[player * 10] = 0;
			statc[player * 10 + 1] = 0;
			statc[player * 10 + 1] = stat[player];
			stat[player] = 22;
			
		}
	}

}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.28 - �V���b�g�K��
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 1]�F�I����Ɉړ�����X�e�[�^�X
void statShotgun(int player) {
	int i,j,x,limit,waitA,waitB;
	
//	doshotgun[player] = 0;
	limit = 0;
	
	
	waitA = 6 + (wait1[player] * 2);
	waitB = waitA + 30 + wait1[player];
	
	padRepeat(player);
	if(ace_irs) doIRS2(player);	// ACE��IRS C7U1.5
	
	if(statc[player * 10 + 0] == 0){	//�ŏ�
		for(i = checkFieldTop(player); i < 22; i++){
			if(i == 0){
				do{
					x = rand(fldsizew[player],player);
				} while(fld[x + i * fldsizew[player] + player * 220] == 0);
			} else {
				do{
					x = rand(fldsizew[player],player);
					limit++;
					if(limit > 100000) break;
				} while( ((x == shotgunpos[(i - 1) + 22 * player]) && (limit < 50000)) || (fld[x + i * fldsizew[player] + player * 220] == 0) );
			}
			
			shotgunpos[i + 22 * player] = x;
		}
		statc[player * 10 + 0]++;
	} else {
		if(statc[player * 10 + 0] == waitA){
			PlaySE(14);
			thunder_timer = 10;
			for(i = checkFieldTop(player); i < 22; i++){
				if(fld[shotgunpos[i + 22 * player] + i * fldsizew[player] + player * 220] != 0){
					objectCreate(player, 1, (shotgunpos[i + 22 * player] + 15 + 24 * player - 12 * maxPlay) * 8, (i + 3) * 8, (shotgunpos[i + 22 * player] - 5) * 120 + 20 - Rand(40), - 1900 + Rand(150), fld[shotgunpos[i + 22 * player] + i * 10 + player * 220], 100);
					fld[shotgunpos[i + 22 * player] + i * fldsizew[player] + player * 220] = 0;
					fldt[shotgunpos[i + 22 * player] + i * fldsizew[player] + player * 220] = 0;
					fldi[shotgunpos[i + 22 * player] + i * fldsizew[player] + player * 220] = 0;
					grayoutLackedBlock(player, flds[j + i * 10 + player * 220]);	
					flds[shotgunpos[i + 22 * player] + i * fldsizew[player] + player * 220] = 0;
				}
			}
			scanItem(player);
		}
		statc[player * 10 + 0]++;
		if(statc[player * 10 + 0] >= waitB){
			stat[player] = statc[player * 10 + 1];
			statc[player * 10] = 0;
			statc[player * 10 + 1] = 0;
			statc[player * 10 + 1] = stat[player];
			stat[player] = 22;
		}
	}

}
//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.29 - �t�B�[���h����
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 1]�F�I����Ɉړ�����X�e�[�^�X
// statc[player * 10 + 2]�F����Ɠ�������邽�߂̃t���O
// statc[player * 10 + 3]�F�����͌������Ȃ��i�t�B�[���h�R�s�[�j
void statExchangefield(int player) {
	int i,j,enemy;
	
	doexchg[player] = 0;
	docopyfld[player] = 0;
	enemy = 1 - player;		//�Ώۂ����߂�
	if(gameMode[player] != modeNo_ver)
		enemy = player;
	
	padRepeat(player);
	if(ace_irs) doIRS2(player);	// ACE��IRS C7U1.5
	
	if(statc[player * 10 + 0] == 0){	//�ŏ�
		if( ((stat[enemy] == 29) && (statc[enemy * 10 + 2] == 1)) || (item_mode[player]) ){	//�����`�F�b�N
			statc[player * 10 + 0]++;
		}
		statc[player * 10 + 2] = 1;
	} else {
		// ����t�B�[���h�������̃o�b�t�@�Ɋm�ہi�����J�n���O�ɕύX�j
		if(statc[player * 10 + 0] == 58){
			for(i = 0; i < 220; i++) {
				fldbuf[i + player * 220] = fld[i + enemy * 220];
				fldtbuf[i + player * 220] = fldt[i + enemy * 220];
				fldibuf[i + player * 220] = fldi[i + enemy * 220];
				fldsbuf[i + player * 220] = flds[i + enemy * 220];
			}
		}
	
		if((statc[player * 10 + 0] >= 60) && (statc[player * 10 + 0] < 70) && (!statc[player * 10 + 3])){
			for(i = 0; i < 22; i++) {
				j = statc[player * 10 + 0] - 60;
				fld[j + i * 10 + player * 220] = fldbuf[j + i * 10 + player * 220];
				fldt[j + i * 10 + player * 220] = fldtbuf[j + i * 10 + player * 220];
				fldi[j + i * 10 + player * 220] = fldibuf[j + i * 10 + player * 220];
				flds[j + i * 10 + player * 220] = fldsbuf[j + i * 10 + player * 220];
				if((fld[j + i * 10 + player * 220] < 0) && (rots[player] != 6))
					fld[j + i * 10 + player * 220] = 8;
			}
		ExBltFast(27, 120+ ((statc[player * 10 + 0] - 60) * 8) + 192 * player - 96 * maxPlay, 40);
		scanItem(player);
		}
		if(gameMode[player] != modeNo_ver)		// 1�l�p�A�C�e�����[�h�ł͌��ʂȂ�
			printFont(15 + 24 * player - 12 * maxPlay, 15, "NO EFFECT", fontc[rots[player]]);
		statc[player * 10 + 0]++;
		if(statc[player * 10 + 0] >= 120){
			stat[player] = statc[player * 10 + 1];
			statc[player * 10] = 0;
			statc[player * 10 + 1] = 0;
			statc[player * 10 + 2] = 0;
			statc[player * 10 + 3] = 0;
				statc[player * 10 + 1] = stat[player];
				stat[player] = 22;
		}
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.31 - �A�C�e�����[���b�g
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 1]�F�I����Ɉړ�����X�e�[�^�X
// statc[player * 10 + 2]�F�����A�C�e��
void statItemRulet(int player) {
	int i,j,y,waitA;
		
	padRepeat(player);
	if(ace_irs) doIRS2(player);	// ACE��IRS C7U1.5
	

		waitA = 150 + wait1[player];
	
	
	if(statc[player * 10 + 0] == 0){	//�ŏ�
		
		statc[player * 10 + 0]++;
	} else {
		if(statc[player * 10 + 0] <= 119){//�V���b�t����
			if(statc[player * 10 + 0] % 3 == 0){
				PlaySE(5);
				statc[player * 10 + 2] = Rand(item_num) + 1;
			}
		}
		if(statc[player * 10 + 0] == 120){//����
			PlaySE(10);
			statc[player * 10 + 2] = rand(item_num,player) + 1;
			if((rand(10,player) < 1) || (statc[player * 10 + 2] == item_num + 1)){	//�X�J
				statc[player * 10 + 2] = 36;
				PlaySE(45);
					eraseItem(player, statc[player * 10 + 2]);
					item_t[player] = item_interval / 4;
			}else{//����������
				eraseItem(player, statc[player * 10 + 2]);
				if(statc[player * 10 + 2] == 36){
					PlaySE(45);
					misstimer[player] = item_interval / 4;
				}
			}
			
			if(stat[player] != 31){
				statc[player * 10 + 1] = stat[player];
				stat[player] = 31;
			}
			if(dorulet[player]){
				dorulet[player] = 0;
				eraseItem(player, rand(item_num,player) + 1);
			}
		}
		if((statc[player * 10 + 0] > 120) && (statc[player * 10 + 0] <= 150) && (statc[player * 10 + 2] == 36)){
			y = Rand(8);
			ofs_x[player] = y - (y / 2);
			ofs_x2[player] = ofs_x[player];
		}else{
			ofs_x[player] = 0;
			ofs_x2[player] = 0;
		}
		if(statc[player * 10 + 0] <= 150)ExBltFastRect(89, 120+192 * player -96 * maxPlay , 142 , 80 * ((statc[player * 10 + 2] - 1) / 10), 36 * ((statc[player * 10 + 2] - 1) % 10), 80, 36);
		ExBltFastRect(46,(4 + 24 * player + 12 * (!maxPlay))*8, 182,(8*(statc[player * 10 + 2] - 1))+56,0,8,8);
		ExBltFastRect(46,(11 + 24 * player + 12 * (!maxPlay))*8, 182,(8*(statc[player * 10 + 2] - 1))+56,0,8,8);
		ExBltRect(28,(5 + 24 * player + 12 * (!maxPlay))*8, 178, 0, (statc[player * 10 + 2] - 1) * 16, 48, 16);
		statc[player * 10 + 0]++;
		if(statc[player * 10 + 0] >= waitA){
				if(fmirror_cnt[player] == -20)
					if(UpLineShirase(player)) return;
				if(fldMirrorProc(player)) return;
			stat[player] = statc[player * 10 + 1];
			statc[player * 10] = 0;
			statc[player * 10 + 1] = 0;
			statc[player * 10 + 2] = 0;
			statc[player * 10 + 3] = 0;
			statc[player * 10 + 4] = 0;
	// �A�C�e�������̑Ώۂ������������ꍇ
	//��DEL FIELD
	if(isUPdelfield[player]){
		j = (22-checkFieldTop(player)) / 2;
		for(i = checkFieldTop(player); i <= 22; i++) {
			erase[i + player * 22] = 1;
			j--;
			if(j < 0) break;
		}
		stat[player] = 25;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 4;	// �����J�n
		if(ending[player])				//�G���f�B���O��
			statc[player * 10 + 1] = 13;
		return;
	}
	//��DEL FIELD
	if(isDWdelfield[player]){
		j = (22-checkFieldTop(player)) / 2;
		for(i = 22; i > checkFieldTop(player); i--) {
			erase[i + player * 22] = 1;
			j--;
			if(j < 0) break;
		}
		stat[player] = 25;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 4;	// �����J�n
		if(ending[player])				//�G���f�B���O��
			statc[player * 10 + 1] = 13;
		return;
	}
	//DEL EVEN
	if(isdeleven[player]){
		for(i = 22; i >= checkFieldTop(player); i--) {
			erase[i + player * 22] = 1;
			i--;
		}
		stat[player] = 25;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 4;	// �����J�n
		if(ending[player])				//�G���f�B���O��
			statc[player * 10 + 1] = 13;
		return;
	}
	//FREE FALL
	if(isFreefall[player]){
		stat[player] = 32;
		statc[player * 10 + 0] = 0;
		statc[player * 10 + 1] = 4;		// �X�e�[�^�X
		if(ending[player])				//�G���f�B���O��
			statc[player * 10 + 1] = 13;
		statc[player * 10 + 2] = 0;
		statc[player * 10 + 3] = 0;
		statc[player * 10 + 4] = 0;
		return;
	}
	//MOV FIELD
	if((isLmovfield[player]) || (isRmovfield[player])){
		stat[player] = 33;
		statc[player * 10 + 0] = 0;
		statc[player * 10 + 1] = 4;		// �X�e�[�^�X
		if(ending[player])				//�G���f�B���O��
			statc[player * 10 + 1] = 13;
		statc[player * 10 + 2] = 0;
		statc[player * 10 + 3] = 0;
		statc[player * 10 + 4] = 0;
		return;
	}
		//ALLCLEAR
	if(isallclear[player]){
//		for(i = 0; i < 22; i++) {
//			erase[i + player * 22] = 1;
//		}
		stat[player] = 35;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 4;	// �����J�n
		statc[player * 10] = -wait1[player];
		statc[player * 10 + 2] = 21;
		if(ending[player])				//�G���f�B���O��
			statc[player * 10 + 1] = 13;
		return;
	}
	if(doshotgun[player]){	//�V���b�g�K������
		stat[player] = 28;
		statc[player * 10 + 0] = 0;
		statc[player * 10 + 1] = 4;		// �X�e�[�^�X
		if(ending[player])				//�G���f�B���O��
			statc[player * 10 + 1] = 13;
		statc[player * 10 + 2] = 0;
		statc[player * 10 + 3] = 0;
		statc[player * 10 + 4] = 0;
		doshotgun[player] = 0;
		return;
	}
	if(dolaser[player]){	//���[�U�[����
		stat[player] = 26;
		statc[player * 10 + 0] = 0;
		statc[player * 10 + 1] = 4;		// �X�e�[�^�X
		if(ending[player])				//�G���f�B���O��
			statc[player * 10 + 1] = 13;
		statc[player * 10 + 2] = 0;
		statc[player * 10 + 3] = 0;
		statc[player * 10 + 4] = 0;
		dolaser[player] = 0;
		return;
	}
	if(donega[player]){	//�l�K�t�B�[���h����
		stat[player] = 27;
		statc[player * 10 + 0] = 0;
		statc[player * 10 + 1] = 4;		// �X�e�[�^�X
		if(ending[player])				//�G���f�B���O��
			statc[player * 10 + 1] = 13;
		statc[player * 10 + 2] = 0;
		statc[player * 10 + 3] = 0;
		statc[player * 10 + 4] = 0;
		donega[player] = 0;
		return;
	}
	if(dorulet[player]){	//�A�C�e�����[���b�g����
		stat[player] = 31;
		statc[player * 10 + 0] = 0;
		statc[player * 10 + 1] = 4;		// �X�e�[�^�X
		if(ending[player])				//�G���f�B���O��
			statc[player * 10 + 1] = 13;
		statc[player * 10 + 2] = 0;
		statc[player * 10 + 3] = 0;
		statc[player * 10 + 4] = 0;
		dorulet[player] = 0;
		return;
	}
	if(do180field[player]){	//180���t�B�[���h����
		stat[player] = 34;
		statc[player * 10 + 0] = 0;
		statc[player * 10 + 1] = 4;		// �X�e�[�^�X
		if(ending[player])				//�G���f�B���O��
			statc[player * 10 + 1] = 13;
		statc[player * 10 + 2] = 0;
		statc[player * 10 + 3] = 0;
		statc[player * 10 + 4] = 0;
		do180field[player] = 0;
		return;
	}
	if(doexchg[player]){	//�t�B�[���h��������
		stat[player] = 29;
		statc[player * 10 + 0] = 0;
		statc[player * 10 + 1] = 4;		// �X�e�[�^�X
		if(ending[player])				//�G���f�B���O��
			statc[player * 10 + 1] = 13;
		statc[player * 10 + 2] = 0;
		statc[player * 10 + 3] = 0;
		statc[player * 10 + 4] = 0;
		doexchg[player] = 0;
		return;
	}
	if(docopyfld[player]){	//�t�B�[���h�R�s�[����
		stat[player] = 29;
		statc[player * 10 + 0] = 0;
		statc[player * 10 + 1] = 4;		// �X�e�[�^�X
		if(ending[player])				//�G���f�B���O��
			statc[player * 10 + 1] = 13;
		statc[player * 10 + 2] = 0;
		statc[player * 10 + 3] = 1;
		statc[player * 10 + 4] = 0;
		docopyfld[player] = 0;
		return;
	}
		}
	}

}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.32 - �t���[�t�H�[��
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 1]�F�I����Ɉړ�����X�e�[�^�X
// statc[player * 10 + 2]�F�Ă���オ�莞�̌��̈ʒu
void statFreefall(int player) {
	int i,j,x,y,l,k,tmp;
	
	padRepeat(player);
	if(ace_irs) doIRS2(player);	// ACE��IRS C7U1.5

	if((statc[player * 10 + 0] >= wait1[player]) && (statc[player * 10 + 0] <= (wait1[player] * 2) + 40)){
		if(statc[player * 10 + 0] < wait1[player] + 25){
			ofs_y[player] = ofs_y[player] - 2;
			ofs_y2[player] = ofs_y2[player] - 2;
		}
		if((statc[player * 10 + 0] >= wait1[player] + 25) && (statc[player * 10 + 0] < wait1[player] + 30)){
			ofs_y[player] = ofs_y[player] + 10;
			ofs_y2[player] = ofs_y2[player] + 10;
		}
		if(statc[player * 10 + 0] == wait1[player] + 30){	//���R��������
			ofs_y[player] = 0;
			ofs_y2[player] = 0;
			PlaySE(2);
			for(y = fldsizeh[player] - 1;y >= 0;y--){	//�ŉ��i�͒��ׂȂ�
				for(i = 0;i < fldsizew[player];i++){
					if((fld[i + y * fldsizew[player] + player * 220] != 0) && (fld[i + (y + 1) * fldsizew[player] + player * 220] == 0)){	//�u���b�N����1�i�����󔒂Ȃ�
						tmp = y;
						do{
							if(tmp + 1 > fldsizeh[player]) break;	//�ŉ��i�ɓ��B
							j = fld[i + tmp * fldsizew[player] + player * 220];
							fld[i + tmp * fldsizew[player] + player * 220] = 0;
							fld[i + (tmp + 1) * fldsizew[player] + player * 220] = j;
							j = fldt[i + tmp * fldsizew[player] + player * 220];
							fldt[i + tmp * fldsizew[player] + player * 220] = 0;
							fldt[i + (tmp + 1) * fldsizew[player] + player * 220] = j;
							j = fldi[i + tmp * fldsizew[player] + player * 220];
							fldi[i + tmp * fldsizew[player] + player * 220] = 0;
							fldi[i + (tmp + 1) * fldsizew[player] + player * 220] = j;
							j = flds[i + tmp * fldsizew[player] + player * 220];
							flds[i + tmp * fldsizew[player] + player * 220] = 0;
							flds[i + (tmp + 1) * fldsizew[player] + player * 220] = j;
							tmp++;
						}while(fld[i + (tmp + 1) * fldsizew[player] + player * 220] == 0);
					}
				}
			}
		}
	}
	if(statc[player * 10 + 0] == (wait1[player] * 2) + 30){	//��������i�Ȃ���Ύ��̃X�e�[�^�X�ցj
		if(blockEraseJudgeFf(player,0) == 0){	// �����Ȃ�
			statc[player * 10 + 0] = -100;
		} else {							// ��������
			statc[player * 10 + 2] = rand(10,player);
			statc[player * 10 + 3] = statc[player * 10 + 2];
			if(IsBigStart[player]) {
				statc[player * 10 + 2] = (statc[player * 10 + 2] / 2) * 2;
				statc[player * 10 + 3] = statc[player * 10 + 2] + 1;
			}
			
			for(i = 0; i <= fldsizeh[player]; i++) {
				if(erase[i + player * 22]) {
					Ff_rerise[player]++;
					y--;			
					for(x = 0; x < fldsizew[player]; x++) { // #1.60c7b
						if(breakeffect) {
							// super_breakeffect��1�̏ꍇ�͑S�Ẵu���b�N�ɔj��G�t�F�N�g��K�p���� #1.60c7m9
							// �v���`�i�u���b�N��������ꍇ�͖�����
							if( (fld[x + i * fldsizew[player] + player * 220] >= 11) || (super_breakeffect == 1) ||
								( ((breaktype == 0)||((breaktype == 3)&&(gameMode[player] == modeNo_beg))) && (super_breakeffect == 2) ) ||
								((heboGB[player]) && (super_breakeffect == 2)) ) {
								objectCreate(player, 1, (x + 15 + 24 * player - 12 * maxPlay) * 8, (i + 3) * 8, (x - 5) * 120 + 20 - Rand(40), - 1900 + Rand(150) + Ff_rerise[player] * 250, fld[x + i * 10 + player * 220], 100);
							} else if(Ff_rerise[player] & 1) {
								if((x & 1) == 1) {
									objectCreate(player, 1 + (wait1[player] < 6) * 2, (x + 15 + 24 * player - 12 * maxPlay) * 8 + 4, (i + 3) * 8, (x - 5) * 120 + 20 - Rand(40), - 1900 + Rand(150) + Ff_rerise[player] * 250, fld[x + i * 10 + player * 220], 100);
								}
							} else {
								if((x & 1) == 0) {
									objectCreate(player, 1 + (wait1[player] < 6) * 2, (x + 15 + 24 * player - 12 * maxPlay) * 8 + 4, (i + 3) * 8, (x - 5) * 120 + 20 - Rand(40), - 1900 + Rand(150) + Ff_rerise[player] * 250, fld[x + i * 10 + player * 220], 100);
								}
							}
						}
						
						fld[x + i * fldsizew[player] + player * 220] = 0;
						fldt[x + i * fldsizew[player] + player * 220] = 0;	// #1.60c7j5
						fldi[x + i * fldsizew[player] + player * 220] = 0;	// #1.60c7n1
						grayoutLackedBlock(player, flds[x + i * 10 + player * 220]);
						flds[x + i * fldsizew[player] + player * 220] = 0;
					}
				}
			}
			if(gameMode[player] != modeNo_ver)
				PlaySE(11);
			else if( Ff_rerise[player] >= 5 )
				PlaySE(10 + 4);		// 5���C���ȏ�̏ꍇ��4���C���̉����o��
			else
				PlaySE(10 + Ff_rerise[player]);
			if(gameMode[player] == modeNo_ver){
				li[player] == li[player] + Ff_rerise[player];
				if(Ff_rerise[player] >= 2) blockEraseJudgeFf(player,1);
			}
		}
	}
	if(statc[player * 10 + 0] == (wait1[player] * 2) + 30 + wait2[player]) {	//�������肪�������ꍇ�̗�������
		y = fldsizeh[player];
		for(i = 0; i <= fldsizeh[player]; i++) {
			if(erase[y + player * 22]) {
				for(k = y; k > 0; k--) {
					for(l = 0; l < fldsizew[player]; l++) {
						fld[l + k * fldsizew[player] + player * 220] = fld[l + (k - 1) * fldsizew[player] + player * 220];
						// #1.60c7j5
						fldt[l + k * fldsizew[player] + player * 220] = fldt[l + (k - 1) * fldsizew[player] + player * 220];
						// #1.60c7n1
						if((gameMode[player] == modeNo_ver) || (item_mode[player]))
						fldi[l + k * fldsizew[player] + player * 220] = fldi[l + (k - 1) * fldsizew[player] + player * 220];
					}
					erase[k + player * 22] = erase[(k - 1) + player * 22];
				}
				for(l = 0; l < fldsizew[player]; l++) {
					fld[l + player * 220] = 0;
					fldt[l + player * 220] = 0;		// #1.60c7j5
					if((gameMode[player] == modeNo_ver) || (item_mode[player])) fldi[l + player * 220] = 0;		// #1.60c7n1
					erase[player * 22] = 0;
				}
			} else {
				y--;
			}
		}
		PlaySE(2);
		for(i = 0; i <= fldsizeh[player]; i++) erase[i + player * 22] = 0;
	}

	if(statc[player * 10 + 0] == (wait1[player] * 3) + 30 + wait2[player]) statc[player * 10 + 0] = -100;
	//novice���[�h��square���[�h���ƍĂ���オ��Ȃ��@�ΐ�ł͑��������グ��
	if(((gameMode[player] == modeNo_beg) && (novice_mode[player]))||(squaremode[player])||(gameMode[player] == modeNo_ver)) Ff_rerise[player] = 0;
	
//	if(statc[player * 10 + 0] >= 0) 
	statc[player * 10 + 0]++;
	if(statc[player * 10 + 0] < 0){
		if(Ff_rerise[player] != 0){	//�Ă���オ��
			PlaySE(20);
			for(i = 1; i <= fldsizeh[player]; i++) {
				for(j = 0; j < fldsizew[player]; j++) {
					fld[j + (i - 1) * fldsizew[player] + player * 220] = fld[j + i * fldsizew[player] + player * 220];
					fldt[j + (i - 1) * fldsizew[player] + player * 220] = fldt[j + i * fldsizew[player] + player * 220];
					flds[j + (i - 1) * fldsizew[player] + player * 220] = flds[j + i * fldsizew[player] + player * 220];
					if((gameMode[player] == modeNo_ver) || (item_mode[player]))
						fldi[j + (i - 1) * fldsizew[player] + player * 220] = fldi[j + i * fldsizew[player] + player * 220];
				}
				erase[(i - 1) + player * 22] = erase[i + player * 22];
			}
	
			for(j = 0; j < fldsizew[player]; j++) {
				fld[j + fldsizew[player] * fldsizeh[player] + player * 220] = ((j != statc[player * 10 + 2]) && (j != statc[player * 10 + 3])) * (rand(7,player) + 2);
				fldt[j + fldsizew[player] * fldsizeh[player] + player * 220] = (fld[j + fldsizew[player] * fldsizeh[player] + player * 220] != 0) * -1;
				// �A�C�e���𑝐B�����Ȃ� #1.60c7o6
				if((gameMode[player] == modeNo_ver) || (item_mode[player])) fldi[j + fldsizew[player] * fldsizeh[player] + player * 220] = 0;
			}
			erase[fldsizeh[player] + player * 22] = 0;
			Ff_rerise[player]--;
			return;
		}else{
			isFreefall[player] = 0;
			stat[player] = statc[player * 10 + 1];
			statc[player * 10 + 1] = 0;
			if(statc[player * 10 + 0] == -99){
				statc[player * 10 + 1] = stat[player];
				stat[player] = 22;
			}
			statc[player * 10] = 0;
			statc[player * 10 + 2] = 0;
			statc[player * 10 + 3] = 0;
		}
	}

}
//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.33 - �u���b�N��[�Ɋ񂹂�
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 1]�F�I����Ɉړ�����X�e�[�^�X
void statMovfield(int player) {
	int i,j,x,y,l,k,tmp;
	
	padRepeat(player);
	if(ace_irs) doIRS2(player);	// ACE��IRS C7U1.5

	if((statc[player * 10 + 0] >= wait1[player]) && (statc[player * 10 + 0] <= (wait1[player] * 2) + 40)){
		if(statc[player * 10 + 0] < wait1[player] + 25){
			ofs_x[player] = ofs_x[player] - 2 + (4 * isLmovfield[player]);
			ofs_x2[player] = ofs_x2[player] - 2 + (4 * isLmovfield[player]);
		}
		if((statc[player * 10 + 0] >= wait1[player] + 25) && (statc[player * 10 + 0] < wait1[player] + 30)){
			ofs_x[player] = ofs_x[player] + 10 - (10 * isLmovfield[player]);
			ofs_x2[player] = ofs_x2[player] + 10 - (10 * isLmovfield[player]);
		}
		if(statc[player * 10 + 0] == wait1[player] + 30){	//����
			ofs_x[player] = 0;
			ofs_x2[player] = 0;
			PlaySE(2);
			if(isLmovfield[player])	//��MOV FIELD
			for(i = 1;i < fldsizew[player];i++){
				for(y = 0;y <= fldsizeh[player];y++){
					if((fld[i + y * fldsizew[player] + player * 220] != 0) && (fld[(i - 1) + y * fldsizew[player] + player * 220] == 0)){
						tmp = i;
						do{
							if(tmp - 1 < 0) break;	//���[�ɓ��B
							j = fld[tmp + y * fldsizew[player] + player * 220];
							fld[tmp + y * fldsizew[player] + player * 220] = 0;
							fld[(tmp - 1) + y * fldsizew[player] + player * 220] = j;
							j = fldt[tmp + y * fldsizew[player] + player * 220];
							fldt[tmp + y * fldsizew[player] + player * 220] = 0;
							fldt[(tmp - 1) + y * fldsizew[player] + player * 220] = j;
							j = fldi[tmp + y * fldsizew[player] + player * 220];
							fldi[tmp + y * fldsizew[player] + player * 220] = 0;
							fldi[(tmp - 1) + y * fldsizew[player] + player * 220] = j;
							j = flds[tmp + y * fldsizew[player] + player * 220];
							flds[tmp + y * fldsizew[player] + player * 220] = 0;
							flds[(tmp - 1) + y * fldsizew[player] + player * 220] = j;
							tmp--;
						}while(fld[(tmp - 1) + y * fldsizew[player] + player * 220] == 0);
					}
				}
			}
			if(isRmovfield[player])	//��MOV FIELD
			for(i = fldsizew[player] - 2;i >= 0;i--){
				for(y = 0;y <= fldsizeh[player];y++){
					if((fld[i + y * fldsizew[player] + player * 220] != 0) && (fld[(i + 1) + y * fldsizew[player] + player * 220] == 0)){
						tmp = i;
						do{
							if(tmp + 1 >= fldsizew[player]) break;	//�E�[�ɓ��B
							j = fld[tmp + y * fldsizew[player] + player * 220];
							fld[tmp + y * fldsizew[player] + player * 220] = 0;
							fld[(tmp + 1) + y * fldsizew[player] + player * 220] = j;
							j = fldt[tmp + y * fldsizew[player] + player * 220];
							fldt[tmp + y * fldsizew[player] + player * 220] = 0;
							fldt[(tmp + 1) + y * fldsizew[player] + player * 220] = j;
							j = fldi[tmp + y * fldsizew[player] + player * 220];
							fldi[tmp + y * fldsizew[player] + player * 220] = 0;
							fldi[(tmp + 1) + y * fldsizew[player] + player * 220] = j;
							j = flds[tmp + y * fldsizew[player] + player * 220];
							flds[tmp + y * fldsizew[player] + player * 220] = 0;
							flds[(tmp + 1) + y * fldsizew[player] + player * 220] = j;
							tmp++;
						}while(fld[(tmp + 1) + y * fldsizew[player] + player * 220] == 0);
					}
				}
			}
			
		}
	}


	statc[player * 10 + 0]++;
	if(statc[player * 10 + 0] == (wait1[player] * 2) + 30){
		isLmovfield[player] = 0;
		isRmovfield[player] = 0;
		stat[player] = statc[player * 10 + 1];
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = 0;
		statc[player * 10 + 1] = stat[player];
		stat[player] = 22;
	}

}
//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.34 - �t�B�[���h��̃u���b�N���Ђ�����Ԃ�
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 1]�F�I����Ɉړ�����X�e�[�^�X
void stat180field(int player) {
	int i,j,x,y,l,k,tmp,waitA;
	
	padRepeat(player);
	if(ace_irs) doIRS2(player);	// ACE��IRS C7U1.5
	

	waitA = 20 + wait1[player] + (wait1[player] / 2);
	
//	do180field[player] = 0;

	if((statc[player * 10 + 0] >= waitA) && (statc[player * 10 + 0] <= waitA + 50 + 15)){
		if(statc[player * 10 + 0] < waitA + 25){
			ofs_y[player] = ofs_y[player] + 2;
			ofs_y2[player] = ofs_y2[player] + 2;
		}
		if((statc[player * 10 + 0] >= waitA + 25) && (statc[player * 10 + 0] <= waitA + 50)){
			if(ofs_y[player] > 0) ofs_y[player] = ofs_y[player] - 10;
			ofs_y2[player] = ofs_y2[player] - 10;
		}
		if(statc[player * 10 + 0] == waitA + 50){	//����
			ofs_y[player] = 0;
			statc[player * 10 + 2] = checkFieldTop(player);
			for(i = 0; i <= fldsizeh[player]; i++) {	// �o�b�t�@��
				for(j = 0; j < fldsizew[player]; j++) {
					fldbuf[j + i * fldsizew[player] + player * 220] = fld[j + i * fldsizew[player] + player * 220];
					fldtbuf[j + i * fldsizew[player] + player * 220] = fldt[j + i * fldsizew[player] + player * 220];
					fldibuf[j + i * fldsizew[player] + player * 220] = fldi[j + i * fldsizew[player] + player * 220];
					fldsbuf[j + i * fldsizew[player] + player * 220] = flds[j + i * fldsizew[player] + player * 220];
				}
			}
			for(i = 0; i <= fldsizeh[player]; i++) {	// �Ђ�����Ԃ�
				for(j = 0; j < fldsizew[player]; j++) {
					if(i + statc[player * 10 + 2] > fldsizeh[player]) break;
					fld[j + (i + statc[player * 10 + 2]) * fldsizew[player] + player * 220] = fldbuf[j + (fldsizeh[player] - i) * fldsizew[player] + player * 220];
					fldt[j + (i + statc[player * 10 + 2]) * fldsizew[player] + player * 220] = fldtbuf[j + (fldsizeh[player] - i) * fldsizew[player] + player * 220];
					fldi[j + (i + statc[player * 10 + 2]) * fldsizew[player] + player * 220] = fldibuf[j + (fldsizeh[player] - i) * fldsizew[player] + player * 220];
					flds[j + (i + statc[player * 10 + 2]) * fldsizew[player] + player * 220] = fldsbuf[j + (fldsizeh[player] - i) * fldsizew[player] + player * 220];
				
				}
			}
		}
		if((statc[player * 10 + 0] > waitA + 50) && (statc[player * 10 + 0] < waitA + 50 + 15)){
			ofs_y2[player] = ofs_y2[player] + 20;
			if(ofs_y2[player] > 0) ofs_y2[player] = 0;
		}
		if(statc[player * 10 + 0] == waitA + 50 + 15){
			ofs_y2[player] = 0;
			PlaySE(2);
		}
	}

	statc[player * 10 + 0]++;
	if(statc[player * 10 + 0] > wait1[player] + waitA + 50 + 15){
		stat[player] = statc[player * 10 + 1];
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = 0;
		statc[player * 10 + 1] = stat[player];
		stat[player] = 22;
	}

}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.35 - �ォ��u���b�N������
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 1]�F�I����Ɉړ�����X�e�[�^�X
// statc[player * 10 + 2]�F�������C����
// statc[player * 10 + 3]�F�J�E���^2
void statDelfromUpper(int player) {
	int i, j, k, waitA;
	
	padRepeat(player);
	if(ace_irs) doIRS2(player);	// ACE��IRS C7U1.5
	
	if(gameMode[player] == modeNo_mis){
		waitA = -160;
	}else{
		waitA = -100 - (wait1[player] * 2);
	}
	
	if((statc[player * 10] > -100 + wait1[player]) && (statc[player * 10] < 0)){
		statc[player * 10]++;
		return;
	}
	if(statc[player * 10] == 0) {
		// �ǂ�������������߂�
		statc[player * 10] = checkFieldTop(player) * 6;
		return;
	}
	
	// �u���b�N������
	if((statc[player * 10] % 6 == 0) && (statc[player * 10] >= 0)) {
		j = statc[player * 10] / 6;
		
		if((j >= 0) && (j < 22)) {
			for(i = 0; i < 10; i++) {
				if(fld[i + j * 10 + player * 220]) {
						objectCreate(player, 1, (i + 15 + 24 * player - 12 * maxPlay) * 8, (j + 3) * 8, (i - 5) * 120 + 20 - Rand(40), - 1900 + Rand(150), fld[i + j * 10 + player * 220], 100);
					
					fld[i + j * 10 + player * 220] = 0;
					fldt[i + j * 10 + player * 220] = 0;
					fldi[i + j * 10 + player * 220] = 0;
					flds[i + j * 10 + player * 220] = 0;
				}
			}
		}
		statc[player * 10 + 3]++;
	}
	if((statc[player * 10] >= 0) && ((statc[player * 10 + 3] >= statc[player * 10 + 2]) || ((statc[player * 10] / 6) >= 22)))
		statc[player * 10] = waitA;
	
	// �A�j���I��
	if(statc[player * 10] == -100) {
		pinchCheck(player);
		pinchCheck2(player);
		stat[player] = statc[player * 10 + 1];
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		for(i = 0; i < 22; i++) erase[i + player * 22] = 0;
		return;
	}
	
	statc[player * 10]++;
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.EX - �V���b�t���t�B�[���h
//������������������������������������������������������������������������������
void statBanana(int player){
	int i,j,y,flag[10],tmp,chg[10],chgt[10],chgi[10],chgs[10];
	
	if(banana_c[player] == 0){	// �ŏ�
		for(i = 0; i < 10; i++) flag[i] = 0;
		for(i = 0; i < 10; i++){
			do{
				tmp = rand(10,player);
			}while(flag[tmp] == 1);
			flag[tmp] = 1;
			banana_pos[i + 10 * player] = tmp;
		}
		banana_c[player]++;
	}else{
		y = banana_c[player] - 1;
		if(banana_c[player] <= 22){
			for(j = 0; j < fldsizew[player]; j++){
				chg[j] = fld[j + y * fldsizew[player] + player * 220];
				chgt[j] = fldt[j + y * fldsizew[player] + player * 220];
				chgi[j] = fldi[j + y * fldsizew[player] + player * 220];
				chgs[j] = flds[j + y * fldsizew[player] + player * 220];
			}
			for(j = 0; j < fldsizew[player]; j++){
				fld[j + y * fldsizew[player] + player * 220] = chg[banana_pos[j + 10 * player]];
				fldt[j + y * fldsizew[player] + player * 220] = chgt[banana_pos[j + 10 * player]];
				fldi[j + y * fldsizew[player] + player * 220] = chgi[banana_pos[j + 10 * player]];
				flds[j + y * fldsizew[player] + player * 220] = chgs[banana_pos[j + 10 * player]];
			}
		}
		if((y > 1) && (y <= 7))
			ExBltRect(79, 120 + 192 * player - 96 * maxPlay, 32, 0 , 50 * (count % 4) + (50 - ((y - 1) * 8)), 80, (y - 1) * 8);
		else if((y > 21) && (y <= 27))
			ExBltRect(79, 120 + 192 * player - 96 * maxPlay, 26 + (y * 8) - 50, 0 , 50 * (count % 4), 80, ((28 - y) * 8));
		else if((y > 7) && (y <= 21))
			ExBltRect(79, 120 + 192 * player - 96 * maxPlay, 24 + (y * 8) - 50, 0 , 50 * (count % 4), 80, 50);
		banana_c[player]++;
	}
	if(banana_c[player] > 32){
		isbanana[player] = 0;
		banana_c[player] = 0;
	}
}