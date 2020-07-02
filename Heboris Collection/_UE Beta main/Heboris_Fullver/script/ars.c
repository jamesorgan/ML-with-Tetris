// ブロックデータやjudgeBlockRotateはclassic.cの流用
// 先にclassic.cを読み込む必要があります
int	acol[7] = {5,2,3,1,7,6,4};

// player: プレイヤー番号
// kickm : 接地状態で移動できる回数
// kickr : 接地状態で回転できる回数
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
			// HOLDしてゲームオーバーになった場合はここで止める #1.60c7m2
			if(stat[player] == 7) return;
		}

		bs[player] = bs[player] + sp[player];
		
		lockT = wait3[player];
		if(isboost[player]){
			bs[player] = 1200;
			if((sp[player] >= 1200) && (gameMode[player] != modeNo_tom))
				lockT = wait3[player] / 2;
		}

		// spawn_y_typeが1の場合の20G #1.60c7s2
		if( (spawn_y_type) && (sp[player] >= 1200) ) bs[player] = 1320;
		
		// ロールロール処理 #1.60c7j5
		rolling = 0;
		if(isrollroll[player]) {
			// 回るタイミングを「ステージタイムが30フレームで割り切れる」時に変更 #1.60c7m5
			if(ending[player] == 2){
				/* エンディング・ロール */
				if( edrec[player] % p_rollroll_timer == 0 )
					rolling = 1;
			} else if( gameMode[player] == modeNo_tom ) {
				/* TOMOYO */
				//ステージ20以降（ステージタイム無し）
				if((stage[player] > 19) && (ltime[player] % p_rollroll_timer == 0))
					rolling = 1;
				//ステージ19まで
				else if( stime[player] % p_rollroll_timer == 0 )
					rolling = 1;
			} else if( (gameMode[player] <= modeNo_pra) ||(gameMode[player] == modeNo_mis)|| (item_mode[player]) ) {
				/* VERSUS / PRACTICE / MISSION */
				if( time[player] % p_rollroll_timer  == 0 )
					rolling = 1;
			}
		}

		// 回転
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
				// 地形に重ならずに回転できる場合
				if(rotate_snd) PlaySE(4);	// 回転音設定#1.60c7f7
				rt[player] = bak;
				blk[player] = k;
				synchro = 1;
				if(istrance[player])
					c_cblk_r[player] = acol[k];
				
				// 回転させた回数+1 #1.60c7s6
				statc[player * 10 + 5]++;
				
				// T-SPIN権利獲得 #1.60c7n6
				if( judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0 ) {
					if((blk[player] == 4)&&(tspin_type>0))tspin_flag[player] = 1;
				}
			} else if( (blk[player] != 0) && (!disable_wallkick) && (heboGB[player]==0)) {	// ブロックが棒以外のとき
				// 回転できないときは、左右に動かしてみよう
				move = 0;
				
				// BIGの場合は2マス分調べる #1.60c7o9
				for(i = 0; i <= IsBig[player]; i++) {
					// 重なっている部分が真中の列だけではなければ
					if( judgeBlockRotate(player, bx[player], by[player], k, bak) )
					{
						if(judgeBlock(player, bx[player] - 1 - i, by[player], k, bak) == 0)
							move = -1 -i;
						if(judgeBlock(player, bx[player] + 1 + i, by[player], k, bak) == 0)
							move = 1 + i;
						
						if(move) {
							if(rotate_snd) PlaySE(4);	// 回転音設定#1.60c7f7
							bx[player] = bx[player] + move;
							rt[player] = bak;
							blk[player] = k;
							synchro = 1;
							if(istrance[player])
								c_cblk_r[player] = acol[k];
							
							// 回転させた回数+1 #1.60c7s6
							statc[player * 10 + 5]++;
							
							// T-SPIN権利獲得 #1.60c7n6
							if( judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0 ) {
								if((blk[player] == 4)&&(tspin_type>0))tspin_flag[player] = 1;
							}
							break;
						// Ti風水色床蹴り 床蹴りは1回だけ可能 #1.60c3
						} else if((blk[player] == 4) && (kickc2[player] == 0)) {
							if((bak == 2) && (judgeBlock(player, bx[player], by[player] -1 -i, k, bak) == 0)) {
								if(rotate_snd) PlaySE(4);	// 回転音設定#1.60c7f7
								by[player] = by[player] -1 -i;
								rt[player] = bak;
								blk[player] = k;
								synchro = 1;
								if(istrance[player])
									c_cblk_r[player] = acol[k];
								
								// 回転させた回数+1 #1.60c7s6
								statc[player * 10 + 5]++;
								
								kickc2[player]++;
								
								// T-SPIN権利獲得 #1.60c7n6
								if( judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0 ) {
									if( blk[player] == 4 ) tspin_flag[player] = 1;
								}
								break;
							}
						}
					}
				}
			} else if((!disable_wallkick) && (heboGB[player]==0)) {
				// Ti風赤壁･床蹴り (とりあえず床蹴りは縦、壁蹴りは横になる時だけ) #1.60c3
				move = 0;
				// BIGの場合は4マス分調べる #1.60c7m6
				for(i = 0; i <= IsBig[player] * 3; i++) {
					if((bak == 0) || (bak == 2)) {	// 横になる時
						if(judgeBlock(player, bx[player] -1 -i, by[player], blk[player], bak) == 0)
							move = -1 -i;
						else if(judgeBlock(player, bx[player] + 1 +i, by[player], k, bak) == 0)
							move = 1 + i;
						else if(judgeBlock(player, bx[player] + 2 +i, by[player], k, bak) == 0)
							move = 2 + i;
						
						if(move) {
							if(rotate_snd) PlaySE(4);	// 回転音設定#1.60c7f7
							bx[player] = bx[player] + move;
							rt[player] = bak;
							blk[player] = k;
							synchro = 1;
							if(istrance[player])
								c_cblk_r[player] = acol[k];
							
							// 回転させた回数+1 #1.60c7s6
							statc[player * 10 + 5]++;
							
							break;
						}
					} else if(kickc2[player] == 0) {	// 縦になる時
						if(judgeBlock(player, bx[player], by[player] -1 -i, k, bak) == 0)
							move = -1 -i;
						else if(judgeBlock(player, bx[player], by[player] -2 -i, k, bak) == 0)
							move = -2 -i;
						
						// 接地していない場合は蹴らない #1.60c7k5
						if( (judgeBlock(player,bx[player],by[player]+1+i,k,rt[player]) == 0))
							move = 0;
						
						if(move) {
							if(rotate_snd) PlaySE(4);	// 回転音設定#1.60c7f7
							by[player] = by[player] + move;
							rt[player] = bak;
							blk[player] = k;
							synchro = 1;
							if(istrance[player])
								c_cblk_r[player] = acol[k];
							
							// 回転させた回数+1 #1.60c7s6
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
				 	bk[player] = 0;		// 固定時間リセット
				 }
			}
		}/* if(move) */

		//	左右に移動
		move = getPressState(player , 3) - getPressState(player , 2);
		if(isLRreverse[player]) move = 0 - move;
		if(move && (statc[player * 10 + 4])) {
			if((block_spectrum) && (heboGB[player]==0)) drawCBlock (player, blk[player] + 1, 5, 0 , 0, 1);
			// BIG時、2マス単位モードの場合は移動量を2倍する #1.60c7m6
			if(IsBig[player] && BigMove[player]) move = move * 2;
			if( (judgeBlock (player, bx[player], by[player] + 1, blk[player], rt[player]) != 0)) landing = 1;
			if((mpc[player] == 1) || (mpc[player] >= waitt[player]) || ((isremote[player]) && (gameMode[player] != modeNo_ver)))
				if(judgeBlock (player, bx[player] + move, by[player], blk[player], rt[player]) == 0) {
					bx[player] = bx[player] + move;
					if(movesound) PlaySE(5);	// 移動音設定が反映されないのを修正#1.60c7f7
					l = judgeBlock (player, bx[player], by[player] + 1, blk[player], rt[player]);
					if(((l != 0) || (landing)) && (heboGB[player]==0)) {	// 横移動でも固定時間リセット
						if(!synchro) kickc[player]++;
						if((world_drop_snd != 0) && (world_drop_snd != 3) && (l != 0))
							PlaySE(1);
						if(kickc[player] < kickm){
							 bk[player] = 0;
						 }
					}
					if(!synchro) tspin_flag[player] = 0;	// T-SPIN権利剥奪 #1.60c7n6
				}
		}
		synchro = 0;
//		statc[player * 10 + 4] = 1; 				 // 最初の1フレームは移動させないゾ

		if(!nanameallow) move = 0;

		//	↓を離している、またはdowntypeが0の場合、下入れ制限解除#1.60c7f9
		if((!getPressState(player, 1-(1*(isUDreverse[player])))) || (!downtype)) down_flag[player] = 0;
		if((!getPressState(player, 0+(1*(isUDreverse[player])))) || (!downtype)) up_flag[player] = 0;
		
		//	高速落下!! 下入れ改造#1.60c7f9
		if((!move) && getPressState(player , 1-(1*(isUDreverse[player]))) && (sp[player] < 60) && (!down_flag[player]) && ((statc[player * 10 + 4]) )) {
			if(heboGB[player]){
				bs[player] = 61;
			}else {						//このバージョンから
				bs[player] = bs[player] + 30;		//高速落下を遅く
			}
			if(dropScCalc(player)){
					sc[player]++;//直入れ
				}else{
					qdrop[player]++;	//遅い分のドロップボーナス半減は、スコア計算時に
				}
		}
		
		if(ismagnetblock[player]) bs[player] = bs[player] + 30;

		for(bottom = by[player]; judgeBlock (player, bx[player], bottom, blk[player], rt[player]) == 0; bottom++);

		//	地面にくっついた
		if((judgeBlock (player, bx[player], by[player] + 1, blk[player], rt[player]) != 0)) {
		
			if((ismagnetblock[player] == 1) || ((kickc[player] > kickm) && (kickm != -1) ) ||
			((kickc3[player] >= kickr) && (kickr != -1)))
				bk[player] = 100;
		
			bs[player] = 0;
			if((bk[player] == 0) && (smooth)) don = 1;

			if(lockT != 99) // 接着99処理　#1.60c7
				bk[player]++;
			else
				bk[player] = 98;

			// 下キーで固定速度アップ
			if((getPressState(player , 1-(1*(isUDreverse[player])))) && (!down_flag[player]) 
						&& (statc[player * 10 + 4]) && (!move || nanamedown)) {
				if((rots[player] == 5) || (heboGB[player])){	// ARS2では下入れ即接着
					if(heboGB[player]==0) PlaySE(44);
					bk[player] = 100;
				}
				else
					bk[player]++;
			}

			// 上キーで即固定(ARS1のみ)
			if( (getPressState(player , 0+(1*(isUDreverse[player])))) 
				&& (rots[player] == 4) && (  !up_flag[player] ) && (heboGB[player]==0) 
						&& (((statc[player * 10 + 4]) && (!move || nanamedown)) )) {
				bk[player] = bk[player] + lockT;
					PlaySE(44);
			}

			// 固定
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
				goto lockflash;	// SUPERなSKIP
				return;
			}
		} else {
			// T.L.S. (Temporary Landing System)  (c)1998 AR●KA(^^;
			drawTLSBlock(player, bottom);
			
			if(getPressState(player , 0+(1*(isUDreverse[player]))) && (!move) && (!sonicdrop) && (!up_flag[player]) && (heboGB[player]==0) && ((statc[player * 10 + 4]) )) {
				if(rots[player] == 4) {
					// 上キーで一瞬で落下&固定
					if(gameMode[player]== modeNo_ori){
						sc[player] = sc[player] + ( bottom - by[player] - 1 ) * 23 / 20;
					}else if(dropScCalc(player)){
						sc[player] = sc[player]+(bottom -by[player] -1) *2;//直入れ
					}else{
						sdrop[player] = (bottom -by[player] -1) *2;//一旦sdropへ入れる
					}
					if(!block_spectrum){
						by[player] = bottom - 1;
					}else{	//残像を描画
						while(by[player] != bottom - 1){
							drawCBlock (player, blk[player] + 1, 4, 0 , 0, 1);
							by[player]++;
						}
					}
					if((world_drop_snd == 1) || (rots[player] == 4)) PlaySE(1);
					PlaySE(3);
					if(rots[player] == 4)	//ACE-ARSは専用のSEを鳴らす
						PlaySE(44);
					kickc[player] = 0;
					kickc2[player] = 0;
					kickc3[player] = 0;
					statc[player * 10 + 2] ++;
					drawCBlock (player, 0, 0, 0, 10, 0);
					up_flag[player] = 1;
					statc[player * 10 + 5] = 0;	// 回転させた数リセット #1.60c7s6
					goto lockflash;	// SUPERなSKIP
					return;
				} else {
					// ARS2では固定しない
					if((sp[player] <= 240) && (!ending[player])) {
						if(dropScCalc(player)){
							sc[player] = sc[player]+(bottom -by[player] -1) *2;//直入れ
						}else{
							sdrop[player] = (bottom -by[player] -1) *2;//一旦sdropへ入れる
						}
					}
					if(!block_spectrum){
						by[player] = bottom - 1;
					}else{	//残像を描画
						while(by[player] != bottom - 1){
							drawCBlock (player, blk[player] + 1, 4, 0 , 0, 1);
							by[player]++;
						}
					}
					bs[player] = 0;
					bk[player] = 0;
					if(!smooth) don = 1;
					statc[player * 10 + 5] = 0;	// 回転させた数リセット #1.60c7s6
				}
			}
		}
		
		while(bs[player] > 60) {
			bk[player] = 0;
			tspin_flag[player] = 0;	// T-SPIN権利剥奪 #1.60c7o9

			bs[player] = bs[player] - 60;
			
			// BIG時、2マス単位モードの場合は落ちる量を2倍する #1.60c7m6
			// 3マス離れていても接地してしまうのを修正 #1.60c7o9
			if( (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0)
			 || (judgeBlock(player, bx[player], by[player] + 1 + (IsBig[player] && BigMove[player] && !ybigtype), blk[player], rt[player]) == 0) )
			{
				if((block_spectrum) && ((!smooth) || (bs[player] >= 60)) && (heboGB[player]==0))	//残像を描画
					drawCBlock (player, blk[player] + 1, 5, 0 , 0, 1);
				by[player] = by[player] + 1 + (IsBig[player] && BigMove[player] && !ybigtype);
			}
			
			// 地面にくっついた
			if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player])) {
				by[player] = bottom - 1;
				bs[player] = 0;
				if(!smooth) don = 1;
				
				if((ismagnetblock[player] == 1) || (kickc[player] >= kickm) ||
				((kickc3[player] >= kickr)))
					bk[player] = 100;
				
				// 下キー #1.60c7r3
				if((getPressState(player, 1-(1*(isUDreverse[player])))) && (!down_flag[player]) 
							&& (statc[player * 10 + 4] ) && (!move || nanamedown)) {
					if((rots[player] == 5) || (heboGB[player])) {	// ARS2では下入れ即接着
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
						goto lockflash;	// SUPERなSKIP
						return;
					} else {				// ARS1では固定速度アップのみ
						bk[player]++;
					}
				}
				
				// 上キーで即固定(ARS1のみ) #1.60c7r3
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
					 goto lockflash;	// SUPERなSKIP
					return;
				}
			} else {
				// 回転させた数リセット #1.60c7s6
				statc[player * 10 + 5] = 0;
			}
		}
		
		statc[player * 10 + 4] = 1; 				 // 最初の1フレームは移動させないゾ
		
		// 接地音を鳴らす
		// world_drop_sndが1の場合のみ #1.60c7m9
		if( (don) && (world_drop_snd >= 1) && (heboGB[player]==0) ) PlaySE(1);

		// ブロックを描く
		flash = (count % 2) * (blockflash == 0) + (blockflash == 1);
		kosa = bk[player] * 7 / (lockT + (lockT == 0));
		if(kosa > 6) kosa = 6;
		// 各モードのブロックの種類が10に増えたのでblk[player]+9をblk[player]+11に変更 #1.60c7d
		// 単純化に伴い+11から+1に変更#1.60c7k9
		if(smooth && (sp[player] < 60))
			drawCBlock (player, blk[player] + 1, kosa, bs[player] * 8 / 60 , flash, 0);
		else
			drawCBlock (player, blk[player] + 1, kosa, 0 , flash, 0);
		
		statc[player * 10 + 6] = 0;
		if(statc[player * 10 + 2] != 0) goto lockflash;	// SUPERなSKIP
	} else {
		lockflash:
		statc[player * 10 + 2] ++;
		if((c_nblk[0 + player * 6] != 8) && (c_nblk[0 + player * 6] >= 0))drawCBlock (player, 0, 0, 0, 10, 0);
		
		// ↓を離している場合、下入れ制限解除#1.60c7n6
		if(!getPressState(player, 1-(1*(isUDreverse[player])))) down_flag[player] = 0;
		else if(downtype) down_flag[player] = 1;
		if(!getPressState(player, 0+(1*(isUDreverse[player])))) up_flag[player] = 0;
		else if(downtype) up_flag[player] = 1;
		
		if(statc[player * 10 + 2] > 1){	// 接着時の灰色化を1フレ短縮 #1.60c7k8
			setBlock (player, bx[player], by[player], blk[player], rt[player]);
			if(stat[player] == 7) return;
			
			ndelay[player] = 1;
			
			lc[player]++;
			
			// T-SPIN獲得 #1.60c7s6
			//3-コーナーチェック(スライドのやつはすでにチェックされてる)
			if((tspin_flag[player]) && (blk[player] == 4) && ((tspin_type>=2) || (gameMode[player] == modeNo_mis)) && (statc[player * 10 + 5] > 0) && (isTSpin(player) >= 3) ) {
				PlaySE(34);
				tspin_c[player] = 120;
				tspin_flag[player] = 2;
				last_tspin[player] = 0;
			} else if((tspin_type>=2) || (gameMode[player] == modeNo_mis)){
				tspin_flag[player] = 0;
			}
			
			lc[player]++;
			
			// TGMLV上昇はstatBlockに移転しました#1.60c7i7
			if(ending[player] == 0) {
				// ブロックを着床させた回数 #1.60c7i2
				bdowncnt[player]++;
				st_bdowncnt[player]++;	
				if((gameMode[player] == modeNo_dev) && (devil_nextrise[player] >= 0) && (devil_randrise)) {
					devil_nextrise[player]--;
				}
			}

			// ACEカスタム式IRS
			if(ace_irs == 2) doIRS2plus(player);
			// ブロック消去判断により1フレ短縮 #1.60c7k8
			if (blockEraseJudge(player)) {
				stat[player] = 8;
				statc[player * 10] = 0;
				statc[player * 10 + 1] = 0;
				statc[player * 10 + 2] = 0;
				statc[player * 10 + 3] = 0;
				statc[player * 10 + 4] = 0;
				statc[player * 10 + 5] = 0;
				statc[player * 10 + 6] = 0;
				//ステータス変更と同時に次のステータス関数を実行する事で1フレ短縮　C7V2.1
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
				scrate[player] = 100;//oriモード用のスコアレート
				pinchCheck(player);
				//ステータス変更と同時に次のステータス関数を実行する事で1フレ短縮　C7V2.1
				statErase(player);
			}

			return;
		}
	}
	effect (player);
}
