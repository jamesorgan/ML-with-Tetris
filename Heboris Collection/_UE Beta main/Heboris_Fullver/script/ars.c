// �u���b�N�f�[�^��judgeBlockRotate��classic.c�̗��p
// ���classic.c��ǂݍ��ޕK�v������܂�
int	acol[7] = {5,2,3,1,7,6,4};

// player: �v���C���[�ԍ�
// kickm : �ڒn��Ԃňړ��ł����
// kickr : �ڒn��Ԃŉ�]�ł����
void statAMove(int player, int kickm, int kickr) {
	int		bak, bottom, move, don, flash, kosa, rolling,synchro,landing;
	int		i, k, l,lockT;

	don = 0;
	synchro = 0;
	landing = 0;
	if(kickm != -1)kickm++;
	hiddenProc (player);

	if(!statc[player * 10 + 2]) {
		padRepeat(player);
		
		// Hold
		if(!statc[player * 10 + 6]){
			doHold(player, 0);
			// HOLD���ăQ�[���I�[�o�[�ɂȂ����ꍇ�͂����Ŏ~�߂� #1.60c7m2
			if(stat[player] == 7) return;
		}

		bs[player] = bs[player] + sp[player];
		
		lockT = wait3[player];
		if(isboost[player]){
			bs[player] = 1200;
			if((sp[player] >= 1200) && (gameMode[player] != modeNo_tom))
				lockT = wait3[player] / 2;
		}

		// spawn_y_type��1�̏ꍇ��20G #1.60c7s2
		if( (spawn_y_type) && (sp[player] >= 1200) ) bs[player] = 1320;
		
		// ���[�����[������ #1.60c7j5
		rolling = 0;
		if(isrollroll[player]) {
			// ���^�C�~���O���u�X�e�[�W�^�C����30�t���[���Ŋ���؂��v���ɕύX #1.60c7m5
			if(ending[player] == 2){
				/* �G���f�B���O�E���[�� */
				if( edrec[player] % p_rollroll_timer == 0 )
					rolling = 1;
			} else if( gameMode[player] == modeNo_tom ) {
				/* TOMOYO */
				//�X�e�[�W20�ȍ~�i�X�e�[�W�^�C�������j
				if((stage[player] > 19) && (ltime[player] % p_rollroll_timer == 0))
					rolling = 1;
				//�X�e�[�W19�܂�
				else if( stime[player] % p_rollroll_timer == 0 )
					rolling = 1;
			} else if( (gameMode[player] <= modeNo_pra) ||(gameMode[player] == modeNo_mis)|| (item_mode[player]) ) {
				/* VERSUS / PRACTICE / MISSION */
				if( time[player] % p_rollroll_timer  == 0 )
					rolling = 1;
			}
		}

		// ��]
		if(statc[player * 10 + 6] != 0)
			move = 0;
		else
			move = (getPushState(player, 5) || rolling) - (getPushState(player, 4) || getPushState(player, 6));
		if((move) && (isrotatelock[player] == 0)) {
			bak = (rt[player] + move);
				if(istrance[player]){
					do{
						k = rand(7,player);
						setNextBlockColors(player, 1);
					}while(k == blk[player]);
				}else{
					k = blk[player];
				}
			if(bak < 0) bak = 3;
			if(bak > 3) bak = 0;
			if( (judgeBlock (player, bx[player], by[player] + 1, blk[player], rt[player]) != 0)) landing = 1;
			if(judgeBlock(player, bx[player], by[player], k, bak) == 0) {
				// �n�`�ɏd�Ȃ炸�ɉ�]�ł���ꍇ
				if(rotate_snd) PlaySE(4);	// ��]���ݒ�#1.60c7f7
				rt[player] = bak;
				blk[player] = k;
				synchro = 1;
				if(istrance[player])
					c_cblk_r[player] = acol[k];
				
				// ��]��������+1 #1.60c7s6
				statc[player * 10 + 5]++;
				
				// T-SPIN�����l�� #1.60c7n6
				if( judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0 ) {
					if((blk[player] == 4)&&(tspin_type>0))tspin_flag[player] = 1;
				}
			} else if( (blk[player] != 0) && (!disable_wallkick) && (heboGB[player]==0)) {	// �u���b�N���_�ȊO�̂Ƃ�
				// ��]�ł��Ȃ��Ƃ��́A���E�ɓ������Ă݂悤
				move = 0;
				
				// BIG�̏ꍇ��2�}�X�����ׂ� #1.60c7o9
				for(i = 0; i <= IsBig[player]; i++) {
					// �d�Ȃ��Ă��镔�����^���̗񂾂��ł͂Ȃ����
					if( judgeBlockRotate(player, bx[player], by[player], k, bak) )
					{
						if(judgeBlock(player, bx[player] - 1 - i, by[player], k, bak) == 0)
							move = -1 -i;
						if(judgeBlock(player, bx[player] + 1 + i, by[player], k, bak) == 0)
							move = 1 + i;
						
						if(move) {
							if(rotate_snd) PlaySE(4);	// ��]���ݒ�#1.60c7f7
							bx[player] = bx[player] + move;
							rt[player] = bak;
							blk[player] = k;
							synchro = 1;
							if(istrance[player])
								c_cblk_r[player] = acol[k];
							
							// ��]��������+1 #1.60c7s6
							statc[player * 10 + 5]++;
							
							// T-SPIN�����l�� #1.60c7n6
							if( judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0 ) {
								if((blk[player] == 4)&&(tspin_type>0))tspin_flag[player] = 1;
							}
							break;
						// Ti�����F���R�� ���R���1�񂾂��\ #1.60c3
						} else if((blk[player] == 4) && (kickc2[player] == 0)) {
							if((bak == 2) && (judgeBlock(player, bx[player], by[player] -1 -i, k, bak) == 0)) {
								if(rotate_snd) PlaySE(4);	// ��]���ݒ�#1.60c7f7
								by[player] = by[player] -1 -i;
								rt[player] = bak;
								blk[player] = k;
								synchro = 1;
								if(istrance[player])
									c_cblk_r[player] = acol[k];
								
								// ��]��������+1 #1.60c7s6
								statc[player * 10 + 5]++;
								
								kickc2[player]++;
								
								// T-SPIN�����l�� #1.60c7n6
								if( judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0 ) {
									if( blk[player] == 4 ) tspin_flag[player] = 1;
								}
								break;
							}
						}
					}
				}
			} else if((!disable_wallkick) && (heboGB[player]==0)) {
				// Ti���ԕǥ���R�� (�Ƃ肠�������R��͏c�A�ǏR��͉��ɂȂ鎞����) #1.60c3
				move = 0;
				// BIG�̏ꍇ��4�}�X�����ׂ� #1.60c7m6
				for(i = 0; i <= IsBig[player] * 3; i++) {
					if((bak == 0) || (bak == 2)) {	// ���ɂȂ鎞
						if(judgeBlock(player, bx[player] -1 -i, by[player], blk[player], bak) == 0)
							move = -1 -i;
						else if(judgeBlock(player, bx[player] + 1 +i, by[player], k, bak) == 0)
							move = 1 + i;
						else if(judgeBlock(player, bx[player] + 2 +i, by[player], k, bak) == 0)
							move = 2 + i;
						
						if(move) {
							if(rotate_snd) PlaySE(4);	// ��]���ݒ�#1.60c7f7
							bx[player] = bx[player] + move;
							rt[player] = bak;
							blk[player] = k;
							synchro = 1;
							if(istrance[player])
								c_cblk_r[player] = acol[k];
							
							// ��]��������+1 #1.60c7s6
							statc[player * 10 + 5]++;
							
							break;
						}
					} else if(kickc2[player] == 0) {	// �c�ɂȂ鎞
						if(judgeBlock(player, bx[player], by[player] -1 -i, k, bak) == 0)
							move = -1 -i;
						else if(judgeBlock(player, bx[player], by[player] -2 -i, k, bak) == 0)
							move = -2 -i;
						
						// �ڒn���Ă��Ȃ��ꍇ�͏R��Ȃ� #1.60c7k5
						if( (judgeBlock(player,bx[player],by[player]+1+i,k,rt[player]) == 0))
							move = 0;
						
						if(move) {
							if(rotate_snd) PlaySE(4);	// ��]���ݒ�#1.60c7f7
							by[player] = by[player] + move;
							rt[player] = bak;
							blk[player] = k;
							synchro = 1;
							if(istrance[player])
								c_cblk_r[player] = acol[k];
							
							// ��]��������+1 #1.60c7s6
							statc[player * 10 + 5]++;
							
							kickc2[player]++;
							
							break;
						}
					}
				}
			}
			l = judgeBlock (player, bx[player], by[player] + 1, blk[player], rt[player]);
			if((rt[player] == bak) && ((l != 0) || (landing)) && (heboGB[player]==0)) {

				kickc3[player]++;
				if((world_drop_snd != 0) && (world_drop_snd != 3) && (l != 0))
					PlaySE(1);
				if(kickc3[player] < kickr){
				 	bk[player] = 0;		// �Œ莞�ԃ��Z�b�g
				 }
			}
		}/* if(move) */

		//	���E�Ɉړ�
		move = getPressState(player , 3) - getPressState(player , 2);
		if(isLRreverse[player]) move = 0 - move;
		if(move && (statc[player * 10 + 4])) {
			if((block_spectrum) && (heboGB[player]==0)) drawCBlock (player, blk[player] + 1, 5, 0 , 0, 1);
			// BIG���A2�}�X�P�ʃ��[�h�̏ꍇ�͈ړ��ʂ�2�{���� #1.60c7m6
			if(IsBig[player] && BigMove[player]) move = move * 2;
			if( (judgeBlock (player, bx[player], by[player] + 1, blk[player], rt[player]) != 0)) landing = 1;
			if((mpc[player] == 1) || (mpc[player] >= waitt[player]) || ((isremote[player]) && (gameMode[player] != modeNo_ver)))
				if(judgeBlock (player, bx[player] + move, by[player], blk[player], rt[player]) == 0) {
					bx[player] = bx[player] + move;
					if(movesound) PlaySE(5);	// �ړ����ݒ肪���f����Ȃ��̂��C��#1.60c7f7
					l = judgeBlock (player, bx[player], by[player] + 1, blk[player], rt[player]);
					if(((l != 0) || (landing)) && (heboGB[player]==0)) {	// ���ړ��ł��Œ莞�ԃ��Z�b�g
						if(!synchro) kickc[player]++;
						if((world_drop_snd != 0) && (world_drop_snd != 3) && (l != 0))
							PlaySE(1);
						if(kickc[player] < kickm){
							 bk[player] = 0;
						 }
					}
					if(!synchro) tspin_flag[player] = 0;	// T-SPIN�������D #1.60c7n6
				}
		}
		synchro = 0;
//		statc[player * 10 + 4] = 1; 				 // �ŏ���1�t���[���͈ړ������Ȃ��]

		if(!nanameallow) move = 0;

		//	���𗣂��Ă���A�܂���downtype��0�̏ꍇ�A�����ꐧ������#1.60c7f9
		if((!getPressState(player, 1-(1*(isUDreverse[player])))) || (!downtype)) down_flag[player] = 0;
		if((!getPressState(player, 0+(1*(isUDreverse[player])))) || (!downtype)) up_flag[player] = 0;
		
		//	��������!! ���������#1.60c7f9
		if((!move) && getPressState(player , 1-(1*(isUDreverse[player]))) && (sp[player] < 60) && (!down_flag[player]) && ((statc[player * 10 + 4]) )) {
			if(heboGB[player]){
				bs[player] = 61;
			}else {						//���̃o�[�W��������
				bs[player] = bs[player] + 30;		//����������x��
			}
			if(dropScCalc(player)){
					sc[player]++;//������
				}else{
					qdrop[player]++;	//�x�����̃h���b�v�{�[�i�X�����́A�X�R�A�v�Z����
				}
		}
		
		if(ismagnetblock[player]) bs[player] = bs[player] + 30;

		for(bottom = by[player]; judgeBlock (player, bx[player], bottom, blk[player], rt[player]) == 0; bottom++);

		//	�n�ʂɂ�������
		if((judgeBlock (player, bx[player], by[player] + 1, blk[player], rt[player]) != 0)) {
		
			if((ismagnetblock[player] == 1) || ((kickc[player] > kickm) && (kickm != -1) ) ||
			((kickc3[player] >= kickr) && (kickr != -1)))
				bk[player] = 100;
		
			bs[player] = 0;
			if((bk[player] == 0) && (smooth)) don = 1;

			if(lockT != 99) // �ڒ�99�����@#1.60c7
				bk[player]++;
			else
				bk[player] = 98;

			// ���L�[�ŌŒ葬�x�A�b�v
			if((getPressState(player , 1-(1*(isUDreverse[player])))) && (!down_flag[player]) 
						&& (statc[player * 10 + 4]) && (!move || nanamedown)) {
				if((rots[player] == 5) || (heboGB[player])){	// ARS2�ł͉����ꑦ�ڒ�
					if(heboGB[player]==0) PlaySE(44);
					bk[player] = 100;
				}
				else
					bk[player]++;
			}

			// ��L�[�ő��Œ�(ARS1�̂�)
			if( (getPressState(player , 0+(1*(isUDreverse[player])))) 
				&& (rots[player] == 4) && (  !up_flag[player] ) && (heboGB[player]==0) 
						&& (((statc[player * 10 + 4]) && (!move || nanamedown)) )) {
				bk[player] = bk[player] + lockT;
					PlaySE(44);
			}

			// �Œ�
			if((bk[player] > lockT) || (kickc[player] > kickm) || (kickc3[player] > kickr)) {
				if(heboGB[player]==0)
					PlaySE(3);
				else if(heboGB[player] == 1)
					PlaySE(1);
				kickc[player] = 0;
				kickc2[player] = 0;
				kickc3[player] = 0;
				statc[player * 10 + 2] ++;
				drawCBlock (player, 0, 0, 0, 10 , 0);

				if((getPressState(player , 1)) && (downtype) && (!move || nanamedown)) down_flag[player] = 1;
				goto lockflash;	// SUPER��SKIP
				return;
			}
		} else {
			// T.L.S. (Temporary Landing System)  (c)1998 AR��KA(^^;
			drawTLSBlock(player, bottom);
			
			if(getPressState(player , 0+(1*(isUDreverse[player]))) && (!move) && (!sonicdrop) && (!up_flag[player]) && (heboGB[player]==0) && ((statc[player * 10 + 4]) )) {
				if(rots[player] == 4) {
					// ��L�[�ň�u�ŗ���&�Œ�
					if(gameMode[player]== modeNo_ori){
						sc[player] = sc[player] + ( bottom - by[player] - 1 ) * 23 / 20;
					}else if(dropScCalc(player)){
						sc[player] = sc[player]+(bottom -by[player] -1) *2;//������
					}else{
						sdrop[player] = (bottom -by[player] -1) *2;//��Usdrop�֓����
					}
					if(!block_spectrum){
						by[player] = bottom - 1;
					}else{	//�c����`��
						while(by[player] != bottom - 1){
							drawCBlock (player, blk[player] + 1, 4, 0 , 0, 1);
							by[player]++;
						}
					}
					if((world_drop_snd == 1) || (rots[player] == 4)) PlaySE(1);
					PlaySE(3);
					if(rots[player] == 4)	//ACE-ARS�͐�p��SE��炷
						PlaySE(44);
					kickc[player] = 0;
					kickc2[player] = 0;
					kickc3[player] = 0;
					statc[player * 10 + 2] ++;
					drawCBlock (player, 0, 0, 0, 10, 0);
					up_flag[player] = 1;
					statc[player * 10 + 5] = 0;	// ��]�����������Z�b�g #1.60c7s6
					goto lockflash;	// SUPER��SKIP
					return;
				} else {
					// ARS2�ł͌Œ肵�Ȃ�
					if((sp[player] <= 240) && (!ending[player])) {
						if(dropScCalc(player)){
							sc[player] = sc[player]+(bottom -by[player] -1) *2;//������
						}else{
							sdrop[player] = (bottom -by[player] -1) *2;//��Usdrop�֓����
						}
					}
					if(!block_spectrum){
						by[player] = bottom - 1;
					}else{	//�c����`��
						while(by[player] != bottom - 1){
							drawCBlock (player, blk[player] + 1, 4, 0 , 0, 1);
							by[player]++;
						}
					}
					bs[player] = 0;
					bk[player] = 0;
					if(!smooth) don = 1;
					statc[player * 10 + 5] = 0;	// ��]�����������Z�b�g #1.60c7s6
				}
			}
		}
		
		while(bs[player] > 60) {
			bk[player] = 0;
			tspin_flag[player] = 0;	// T-SPIN�������D #1.60c7o9

			bs[player] = bs[player] - 60;
			
			// BIG���A2�}�X�P�ʃ��[�h�̏ꍇ�͗�����ʂ�2�{���� #1.60c7m6
			// 3�}�X����Ă��Ă��ڒn���Ă��܂��̂��C�� #1.60c7o9
			if( (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0)
			 || (judgeBlock(player, bx[player], by[player] + 1 + (IsBig[player] && BigMove[player] && !ybigtype), blk[player], rt[player]) == 0) )
			{
				if((block_spectrum) && ((!smooth) || (bs[player] >= 60)) && (heboGB[player]==0))	//�c����`��
					drawCBlock (player, blk[player] + 1, 5, 0 , 0, 1);
				by[player] = by[player] + 1 + (IsBig[player] && BigMove[player] && !ybigtype);
			}
			
			// �n�ʂɂ�������
			if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player])) {
				by[player] = bottom - 1;
				bs[player] = 0;
				if(!smooth) don = 1;
				
				if((ismagnetblock[player] == 1) || (kickc[player] >= kickm) ||
				((kickc3[player] >= kickr)))
					bk[player] = 100;
				
				// ���L�[ #1.60c7r3
				if((getPressState(player, 1-(1*(isUDreverse[player])))) && (!down_flag[player]) 
							&& (statc[player * 10 + 4] ) && (!move || nanamedown)) {
					if((rots[player] == 5) || (heboGB[player])) {	// ARS2�ł͉����ꑦ�ڒ�
						PlaySE(1);
						if(heboGB[player]==0){
							PlaySE(3);
							PlaySE(44);
						}
						kickc[player] = 0;
						kickc2[player] = 0;
						kickc3[player] = 0;
						statc[player * 10 + 2]++;
						drawCBlock (player, 0, 0, 0, 10, 0);
						if(downtype) down_flag[player] = 1;
						goto lockflash;	// SUPER��SKIP
						return;
					} else {				// ARS1�ł͌Œ葬�x�A�b�v�̂�
						bk[player]++;
					}
				}
				
				// ��L�[�ő��Œ�(ARS1�̂�) #1.60c7r3
				if( (getPressState(player , 0+(1*(isUDreverse[player])))) 
					&& (rots[player] == 4) && (!up_flag[player]) && (heboGB[player]==0) 
					&& (((statc[player * 10 + 4]) && (!move || nanamedown)) )) {
					PlaySE(3);
					PlaySE(44);
					kickc[player] = 0;
					kickc2[player] = 0;
					kickc3[player] = 0;
					statc[player * 10 + 2]++;
					drawCBlock (player, 0, 0, 0, 10, 0);
					if( downtype ) up_flag[player] = 1;
					 goto lockflash;	// SUPER��SKIP
					return;
				}
			} else {
				// ��]�����������Z�b�g #1.60c7s6
				statc[player * 10 + 5] = 0;
			}
		}
		
		statc[player * 10 + 4] = 1; 				 // �ŏ���1�t���[���͈ړ������Ȃ��]
		
		// �ڒn����炷
		// world_drop_snd��1�̏ꍇ�̂� #1.60c7m9
		if( (don) && (world_drop_snd >= 1) && (heboGB[player]==0) ) PlaySE(1);

		// �u���b�N��`��
		flash = (count % 2) * (blockflash == 0) + (blockflash == 1);
		kosa = bk[player] * 7 / (lockT + (lockT == 0));
		if(kosa > 6) kosa = 6;
		// �e���[�h�̃u���b�N�̎�ނ�10�ɑ������̂�blk[player]+9��blk[player]+11�ɕύX #1.60c7d
		// �P�����ɔ���+11����+1�ɕύX#1.60c7k9
		if(smooth && (sp[player] < 60))
			drawCBlock (player, blk[player] + 1, kosa, bs[player] * 8 / 60 , flash, 0);
		else
			drawCBlock (player, blk[player] + 1, kosa, 0 , flash, 0);
		
		statc[player * 10 + 6] = 0;
		if(statc[player * 10 + 2] != 0) goto lockflash;	// SUPER��SKIP
	} else {
		lockflash:
		statc[player * 10 + 2] ++;
		if((c_nblk[0 + player * 6] != 8) && (c_nblk[0 + player * 6] >= 0))drawCBlock (player, 0, 0, 0, 10, 0);
		
		// ���𗣂��Ă���ꍇ�A�����ꐧ������#1.60c7n6
		if(!getPressState(player, 1-(1*(isUDreverse[player])))) down_flag[player] = 0;
		else if(downtype) down_flag[player] = 1;
		if(!getPressState(player, 0+(1*(isUDreverse[player])))) up_flag[player] = 0;
		else if(downtype) up_flag[player] = 1;
		
		if(statc[player * 10 + 2] > 1){	// �ڒ����̊D�F����1�t���Z�k #1.60c7k8
			setBlock (player, bx[player], by[player], blk[player], rt[player]);
			if(stat[player] == 7) return;
			
			ndelay[player] = 1;
			
			lc[player]++;
			
			// T-SPIN�l�� #1.60c7s6
			//3-�R�[�i�[�`�F�b�N(�X���C�h�̂�͂��łɃ`�F�b�N����Ă�)
			if((tspin_flag[player]) && (blk[player] == 4) && ((tspin_type>=2) || (gameMode[player] == modeNo_mis)) && (statc[player * 10 + 5] > 0) && (isTSpin(player) >= 3) ) {
				PlaySE(34);
				tspin_c[player] = 120;
				tspin_flag[player] = 2;
				last_tspin[player] = 0;
			} else if((tspin_type>=2) || (gameMode[player] == modeNo_mis)){
				tspin_flag[player] = 0;
			}
			
			lc[player]++;
			
			// TGMLV�㏸��statBlock�Ɉړ]���܂���#1.60c7i7
			if(ending[player] == 0) {
				// �u���b�N�𒅏��������� #1.60c7i2
				bdowncnt[player]++;
				st_bdowncnt[player]++;	
				if((gameMode[player] == modeNo_dev) && (devil_nextrise[player] >= 0) && (devil_randrise)) {
					devil_nextrise[player]--;
				}
			}

			// ACE�J�X�^����IRS
			if(ace_irs == 2) doIRS2plus(player);
			// �u���b�N�������f�ɂ��1�t���Z�k #1.60c7k8
			if (blockEraseJudge(player)) {
				stat[player] = 8;
				statc[player * 10] = 0;
				statc[player * 10 + 1] = 0;
				statc[player * 10 + 2] = 0;
				statc[player * 10 + 3] = 0;
				statc[player * 10 + 4] = 0;
				statc[player * 10 + 5] = 0;
				statc[player * 10 + 6] = 0;
				//�X�e�[�^�X�ύX�Ɠ����Ɏ��̃X�e�[�^�X�֐������s���鎖��1�t���Z�k�@C7V2.1
				statEraseBlock(player);
			} else {
				stat[player] = 6;
				statc[player * 10] = wait1[player];
				statc[player * 10 + 1] = 15;
				statc[player * 10 + 2] = 0;
				statc[player * 10 + 3] = 2;
				statc[player * 10 + 4] = 0;
				statc[player * 10 + 5] = 0;
				statc[player * 10 + 6] = 0;

				cmbpts[player] = 0;
				combo[player] = 0;
				combo2[player] = 0;
				hanabi_combo[player] = 0;
				hebocombo[player] = 0;
				scrate[player] = 100;//ori���[�h�p�̃X�R�A���[�g
				pinchCheck(player);
				//�X�e�[�^�X�ύX�Ɠ����Ɏ��̃X�e�[�^�X�֐������s���鎖��1�t���Z�k�@C7V2.1
				statErase(player);
			}

			return;
		}
	}
	effect (player);
}
