// シングル台対応 & エンディング時に↓か↑を押しても点を増加させない#1.60c6.1a
// 接着99, Big対応　#1.60c7
/*
world回転法則メモ

→:右回転  ←左回転
L:  ０      １      ２      ３        J:  ０      １      ２      ３
□□◆→□■□→□□□→◆■□→      ◆□□→□■◆→□□□→□■□→
■■■  □■□  ■■■  □■□        ■■■  □■□  ■■■  □■□
□□□←□■◆←◆□□←□■□←      □□□←□■□←□□◆←◆■□←

S:  ０      １      ２      ３        Z:  ０      １      ２      ３
□■◆→□■□→□□□→◆□□→      ◆■□→□□◆→□□□→□■□→
■■□  □■■  □■■  ■■□        □■■  □■■  ■■□  ■■□
□□□←□□◆←◆■□←□■□←      □□□←□■□←□■◆←◆□□←

T:  ０      １      ２      ３        □:TTC推奨はこんなんだったっけ?
□◆□→□■□→□□□→□■□→      ◆■□→□■◆→□□□→□□□→
■■■  □■◆  ■■■  ◆■□        ■■□  □■■  □■■  ■■□
□□□←□■□←□◆□←□■□←      □□□←□□□←□■◆←◆■□←

I:    ０        １        ２        ３
□□□□  □□◆□  □□□□  □■□□
◆■■■→□□■□→□□□□→□■□□→
□□□□←□□■□←■■■◆←□■□□←
□□□□  □□■□  □□□□  □◆□□

回転補正(I以外共通)
0>>1:(-1, 0)>(-1, -1)>(0, +2)>(-1, +2)  0>>3:(+1, 0)>(+1, -1)>(0, +2)>(+1, +2)
1>>2:(+1, 0)>(+1, +1)>(0, -2)>(+1, -2)  3>>2:(-1, 0)>(-1, +1)>(0, -2)>(-1, -2)
2>>3:(+1, 0)>(+1, -1)>(0, +2)>(+1, +2)  2>>1:(-1, 0)>(-1, -1)>(0, +2)>(-1, +2)
3>>0:(-1, 0)>(-1, +1)>(0, -2)>(-1, -2)  1>>0:(+1, 0)>(+1, +1)>(0, -2)>(+1, -2)
a>>bとすると
a==1: (+1, 0)>(+1, +1)>(0, -2)>(+1, -2)
a==3: (-1, 0)>(-1, +1)>(0, -2)>(-1, -2)
b==1: (-1, 0)>(-1, -1)>(0, +2)>(-1, +2)
b==3: (+1, 0)>(+1, -1)>(0, +2)>(+1, +2)

Iのみ
0>>1:(-2, 0)>(+1, 0)>(+1, -2)            0>>3:(+2, 0)>(-1, 0)>(-1, -2)		5/14修正
1>>2:(-1, 0)>(+2, 0)>(-1, -2)>(+2, +1)   3>>2:(+1, 0)>(-2, 0)>(+1, -2)>(-2, +1)
2>>3:(-1, 0)>(+2, 0)>(+2, -1)            2>>1:(+1, 0)>(-2, 0)>(-2, -1)
3>>0:(+1, 0)>(-2, 0)>(-2, -1)>(+1, +2)   1>>0:(-1, 0)>(+2, 0)>(+2, -1)>(-1, +2)

0>>1:(+1, 0)>(-2, 0)>(+1, -2)
0>>3:(-1, 0)>(+2, 0)>(-1, -2)
の方が分かりやすいしプレイしやすいが…
*/

int	blkWDataX[7 * 4 * 4] =	// worldタイプミノ 相対X位置
{
	0, 1, 2, 3, 		2, 2, 2, 2, 		3, 2, 1, 0, 		1, 1, 1, 1, // I
	2, 2, 1, 0, 		2, 1, 1, 1, 		0, 0, 1, 2, 		0, 1, 1, 1, // L
	1, 2, 2, 1, 		2, 2, 1, 1, 		2, 1, 1, 2, 		1, 1, 2, 2, // □
	0, 1, 1, 2, 		2, 2, 1, 1, 		2, 1, 1, 0, 		0, 0, 1, 1, // Z
	1, 0, 1, 2, 		2, 1, 1, 1, 		1, 2, 1, 0, 		0, 1, 1, 1, // T
	0, 0, 1, 2, 		2, 1, 1, 1, 		2, 2, 1, 0, 		0, 1, 1, 1, // J
	2, 1, 1, 0, 		2, 2, 1, 1, 		0, 1, 1, 2, 		0, 0, 1, 1, // S
};

int	blkWDataY[7 * 4 * 4] =	// worldタイプミノ 相対Y位置
{
	1, 1, 1, 1, 		0, 1, 2, 3, 		2, 2, 2, 2, 		3, 2, 1, 0, // I
	0, 1, 1, 1, 		2, 2, 1, 0, 		2, 1, 1, 1, 		0, 0, 1, 2, // L
	0, 0, 1, 1, 		0, 1, 1, 0, 		1, 1, 0, 0, 		1, 0, 0, 1, // □
	0, 0, 1, 1, 		0, 1, 1, 2, 		2, 2, 1, 1, 		2, 1, 1, 0, // Z
	0, 1, 1, 1, 		1, 0, 1, 2, 		2, 1, 1, 1, 		1, 2, 1, 0, // T
	0, 1, 1, 1, 		0, 0, 1, 2, 		2, 1, 1, 1, 		2, 2, 1, 0, // J
	0, 0, 1, 1, 		2, 1, 1, 0, 		2, 2, 1, 1, 		0, 1, 1, 2, // S
};

// 9色だと、wcol[9]が不正な値になっているので10色に修正#1.60c7k6
// これが[]が赤に化ける原因だったわけだが
//int	wcol[20] = {0, 5, 2, 3, 1, 7, 6, 4, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int	wcol[7] = {5,2,3,1,7,6,4};

/*
0>>3:(-1, 0)>(+2, 0)>(-1, -2)>(+2, +1)  0>>1:(-2, 0)>(+1, 0)>(+1, -2)>(-2, +1)
3>>2:(-2, 0)>(+1, 0)>(+1, -2)>(-2, +1)  1>>2:(+2, 0)>(-1, 0)>(-1, -2)>(+2, +1)
2>>1:(-2, 0)>(+1, 0)>(-2, -1)>(+1, +1)  2>>3:(+2, 0)>(-1, 0)>(+2, -1)>(-1, +1)
1>>0:(+2, 0)>(-1, 0)>(+2, -1)>(-1, +2)  3>>0:(-2, 0)>(+1, 0)>(-2, -1)>(+1, +2)
*/

// I型ブロック壁蹴りテーブル（4候補×4方向×2回転×2補正座標）
/*
int iBlockKickTable[4 * 4 * 2 * 2] = {
	// 左回転
	-1, 0,		 2, 0,		-1, -2,		 2, 1,		// 0>>3
	 2, 0,		-1, 0,		 2, -1,		-1, 2,		// 1>>0
	-2, 0,		 1, 0,		-2, -1,		 1, 1,		// 2>>1
	-2, 0,		 1, 0,		 1, -2,		-2, 1,		// 3>>2

	// 右回転
	-2, 0,		 1, 0,		 1, -2,		-2, 1,		// 0>>1
	 2, 0,		-1, 0,		-1, -2,		 2, 1,		// 1>>2
	 2, 0,		-1, 0,		 2, -1,		-1, 1,		// 2>>3
	-2, 0,		 1, 0,		-2, -1,		 1, 2		// 3>>0
};
*/

// 左回転の場合は、棒が上へすっぽ抜けるほうが優先
// 右回転の場合は、棒が下に収まるほうが優先
int iBlockKickTable[4 * 4 * 2 * 2] = {
	// 左回転
	-1, 0,		 2, 0,		-1, -2,		 2, 1,		// 0>>3
	 2, 0,		-1, 0,		 2, -1,		-1, 2,		// 1>>0
	-2, 0,		 1, 0,		-2, -1,		 1, 1,		// 2>>1
	-2, 0,		 1, 0,		 1, -2,		-2, 1,		// 3>>2

	// 右回転
	-2, 0,		 1, 0,		-2, 1,		 1, -2,		// 0>>1
	 2, 0,		-1, 0,		 2, 1,		-1, -2,		// 1>>2
	 2, 0,		-1, 0,		-1, 1,		 2, -1,		// 2>>3
	-2, 0,		 1, 0,		 1, 2,		-2, -1		// 3>>0
};
// SRS-X専用　180度回転壁蹴りテーブル（I以外）
// 偶数番号は2回180°回転すれば元の位置に戻る（かもしれない）が、
// 奇数番号は下への補正が優先される（かもしれない）
int otherBlock180KickTable[11 * 2 * 4] ={
	 1, 0,   2, 0,   1, 1,   2, 1,  -1, 0,  -2, 0,  -1, 1,  -2, 1,   0,-1,   3, 0,  -3, 0,		// 0>>2─┐
	 0, 1,   0, 2,  -1, 1,  -1, 2,   0,-1,   0,-2,  -1,-1,  -1,-2,   1, 0,   0, 3,   0,-3,		// 1>>3─┼┐
	-1, 0,  -2, 0,  -1,-1,  -2,-1,   1, 0,   2, 0,   1,-1,   2,-1,   0, 1,  -3, 0,   3, 0,		// 2>>0─┘│
	 0, 1,   0, 2,   1, 1,   1, 2,   0,-1,   0,-2,   1,-1,   1,-2,  -1, 0,   0, 3,   0,-3		// 3>>1──┘
};

// SRS-X専用　180度回転壁蹴りテーブル（I）
// やり方次第では驚異の壁飛ばし、壁抜けが可能ww
int iBlock180KickTable[11 * 2 * 4] ={
	 -1, 0,  -2, 0,   1, 0,   2, 0,   0, 1,    0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
	  0, 1,   0, 2,   0,-1,   0,-2,  -1, 0,    0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
	  1, 0,   2, 0,  -1, 0,  -2, 0,   0,-1,    0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
	  0, 1,   0, 2,   0,-1,   0,-2,   1, 0,    0,0, 0,0, 0,0, 0,0, 0,0, 0,0
};
// player: プレイヤー番号
// kickm : 接地状態で移動できる回数
// kickr : 接地状態で回転できる回数
void statWMove(int player, int kickm, int kickr) {
	int		bak, bottom, move, don, flash, kosa, rolling ,synchro,landing;
	int		mx, my, sx[11], sy[11], i, k, l;
	int		j,lockT;

	don = 0;
	synchro = 0;
	landing = 0;
	if(kickm != -1) kickm++;
	hiddenProc (player);

	if(!statc[player * 10 + 2]) {
		padRepeat (player);
		
		// Hold
		if( !statc[player * 10 + 6]){
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
			} else if( (gameMode[player] <= modeNo_pra)||(gameMode[player] == modeNo_mis) || (item_mode[player]) ) {
				/* VERSUS / PRACTICE / MISSION */
				if( time[player] % p_rollroll_timer  == 0 )
					rolling = 1;
			}
		}

		// 回転
		// 回転方向逆転設定対応#1.60c7f8
		if(statc[player * 10 + 6] != 0)
			move = 0;
		else if(w_reverse)
			move = (getPushState(player , 4) || getPushState(player , 6) || rolling) - (getPushState(player , 5));
		else
			move = (getPushState(player , 5) || rolling) - (getPushState(player , 4) || getPushState(player , 6));
		if((rots[player] == 7) && (getPushState(player , 6) != 0) && (statc[player * 10 + 6] == 0)) move = 2;
		if((move != 0 ) && (isrotatelock[player] == 0)) {
				bak = (rt[player] + move);
				if(istrance[player]){
					do{
						k = rand(7,player);
						setNextBlockColors(player, 1);
					}while(k == blk[player]);
				}else{
					k = blk[player];
				}
				mx = 0; my = 0;
			if(move < 2){
				if(bak < 0) bak = 3;
				if(bak > 3) bak = 0;
			}else{
				if(bak > 3) bak = bak - 4;
				if(bak < 0) bak = bak + 4;
			}
			if((judgeBlock (player, bx[player], by[player] + 1, blk[player], rt[player]) != 0)) landing = 1;
			if(judgeBlock (player, bx[player], by[player], k, bak) == 0) {
				if(rotate_snd) PlaySE(4);	// 回転音設定#1.60c7f7
				rt[player] = bak;
				blk[player] = k;
				synchro = 1;
				if(istrance[player])
					c_cblk_r[player] = wcol[k];
				
				// 回転させた回数+1 #1.60c7s6
				statc[player * 10 + 5]++;
			} else if((!disable_wallkick) && (heboGB[player]==0)) {	// 回らなかったら
				if(move == 2){	// SRS-X 180°回転の時
//					j = (move > 0) * 88;
					if(blk[player] != 0){
						for(i = 0; i < 11; i++) {
							sx[i] = otherBlock180KickTable[ (i * 2) + (rt[player] * 22) ];
							sy[i] = otherBlock180KickTable[ (i * 2) + (rt[player] * 22) + 1 ];
						}
					}else {
						for(i = 0; i < 11; i++) {
							sx[i] = iBlock180KickTable[ (i * 2) + (rt[player] * 22) ];
							sy[i] = iBlock180KickTable[ (i * 2) + (rt[player] * 22) + 1 ];
						}
					}
				}else if(blk[player] != 0) {	//	I以外の時
					/*
					1>>0, 2: (+1, 0)>(+1, +1)>(0, -2)>(+1, -2)
					3>>0, 2: (-1, 0)>(-1, +1)>(0, -2)>(-1, -2)
					0, 2>>1: (-1, 0)>(-1, -1)>(0, +2)>(-1, +2)
					0, 2>>3: (+1, 0)>(+1, -1)>(0, +2)>(+1, +2)
					*/
					sx[0] = co(((rt[player]==1)||(bak==3)), 1, -1);
					sy[0] = 0;
					sx[1] = sx[0];
					sy[1] = co(rt[player]%2, 1, -1);
					sx[2] = 0;
					sy[2] = sy[1]*(-2);
					sx[3] = sx[0];
					sy[3] = sy[2];
				} else {		//	Iの時
					if(world_i_rot) {
						/*
						非左右対称バージョン #1.60c7r7
						
						左回転                                  右回転
						0>>3:(-1, 0)>(+2, 0)>(-1, -2)>(+2, +1)  0>>1:(-2, 0)>(+1, 0)>(+1, -2)>(-2, +1)
						3>>2:(-2, 0)>(+1, 0)>(+1, -2)>(-2, +1)  1>>2:(+2, 0)>(-1, 0)>(-1, -2)>(+2, +1)
						2>>1:(-2, 0)>(+1, 0)>(-2, -1)>(+1, +1)  2>>3:(+2, 0)>(-1, 0)>(+2, -1)>(-1, +1)
						1>>0:(+2, 0)>(-1, 0)>(+2, -1)>(-1, +2)  3>>0:(-2, 0)>(+1, 0)>(-2, -1)>(+1, +2)
						*/
						
						j = (move > 0) * 32;
						
						for(i = 0; i < 4; i++) {
							sx[i] = iBlockKickTable[ (i * 2) + (rt[player] * 8) + j ];
							sy[i] = iBlockKickTable[ (i * 2) + (rt[player] * 8) + j + 1 ];
							
							//sprintf(string[0], "move:%d no:%d rt:%d sx:%d sy:%d", move, i, rt[player], sx[i], sy[i]);
							//InnerLogMes(string[0]);
						}
					} else {
						/*
						0>>1:(-2, 0)>(+1, 0)>(+1, -2)>(,)         2>>3:(-1, 0)>(+2, 0)>(+2, -1)>(,)
						2>>1:(+1, 0)>(-2, 0)>(-2, -1)>(,)         0>>3:(+2, 0)>(-1, 0)>(-1, -2)>(,)
						1>>2:(-1, 0)>(+2, 0)>(-1, -2)>(+2, +1)    3>>2:(+1, 0)>(-2, 0)>(+1, -2)>(-2, +1)
						1>>0:(-1, 0)>(+2, 0)>(+2, -1)>(-1, +2)    3>>0:(+1, 0)>(-2, 0)>(-2, -1)>(+1, +2)
						*/
						sx[0] = co(((rt[player]==3)||(bak == 1)), 1, -1);
						sy[0] = 0;
						sx[1] = sx[0]*(-2);
						sy[1] = 0;
						sx[2] = co((rt[player]+bak==3), co(sx[0]==1, -2, -1), co(sx[0]==1, 1, 2));
						sy[2] = co(sx[2]%2, -2, -1);
						sx[3] = (rt[player]%2)*co(bak, sx[0], sx[1]);
						sy[3] = (rt[player]%2)*co(bak, 1, 2);
						if(rt[player] == 0) {		// 状態0からの回転時だけ修正
							i = sx[0]; sx[0] = sx[1]; sx[1] = i;
						}
					}
				}
				
				// BIGでは補正量を2倍する #1.60c7m6
				if(IsBig[player]) {
					for(i = 0; i < 4+(7*(move == 2)); i++) {
						sx[i] = sx[i] * 2;
						sy[i] = sy[i] * 2;
					}
				}
				
				for(i = 0; i < 4+(7*(move == 2)); i++) {
					if(judgeBlock (player, bx[player]+sx[i], by[player]+sy[i], k, bak) == 0) {
						mx = sx[i];
						my = sy[i];
						break;
					}
				}
			}

			if(mx || my) {
				if(rotate_snd) {
					PlaySE(4);	// 回転音設定#1.60c7f7
				}
				if(move == 2) PlaySE(0);
				bx[player] = bx[player] + mx;
				by[player] = by[player] + my;
				rt[player] = bak;
				blk[player] = k;
				synchro = 1;
				if(istrance[player])
					c_cblk_r[player] = wcol[k];
				
				// 回転させた回数+1 #1.60c7s6
				statc[player * 10 + 5]++;
			}
			l = judgeBlock (player, bx[player], by[player] + 1, blk[player], rt[player]);
			if((rt[player] == bak) && ((l != 0) || (landing)) && (heboGB[player]==0)) {
				kickc3[player]++;
				if((world_drop_snd != 0) && (world_drop_snd != 3) && (l != 0))
					PlaySE(1);
				if( (kickc3[player] < kickr) || (kickr == -1)) {
					bk[player] = 0;		// 固定時間リセット
				}
				// T-SPIN権利獲得 #1.60c7n6
				if((blk[player] == 4 )&&(tspin_type >0)) tspin_flag[player] = 1;
			}
		}

		//	左右に移動
				move = getPressState(player , 3) - getPressState(player , 2);
		if(isLRreverse[player]) move = 0 - move;
		if( move && (statc[player * 10 + 4] != 0) ) {
			if((block_spectrum) && (heboGB[player]==0)) drawCBlock (player, blk[player] + 1, 5, 0 , 0, 1);
			// BIG時、2マス単位モードの場合は移動量を2倍する #1.60c7m6
			if(IsBig[player] && BigMove[player]) move = move * 2;
			if( judgeBlock (player, bx[player], by[player] + 1, blk[player], rt[player]) != 0) landing = 1;
			if((mpc[player] == 1) || (mpc[player] >= waitt[player]) || ( (rots[player] == 6) && (mpc[player] >= 9) )
			 || ((isremote[player])&&(gameMode[player] != modeNo_ver)))
				if(judgeBlock (player, bx[player] + move, by[player], blk[player], rt[player]) == 0) {
					bx[player] = bx[player] + move;
					if(movesound) PlaySE(5);	// 移動音設定が反映されないのを修正#1.60c7f7
					l = judgeBlock (player, bx[player], by[player] + 1, blk[player], rt[player]);
					if(((l != 0) || (landing)) && (heboGB[player]==0)) {	// 横移動でも固定時間リセット
						if(!synchro) kickc[player]++;
						if((world_drop_snd != 0) && (world_drop_snd != 3) && (l != 0))
							PlaySE(1);
						if((kickc[player] < kickm) || (kickm == -1)) {
							bk[player] = 0;
						}
					}
					if(!synchro) tspin_flag[player] = 0;	// シンクロでないならT-SPIN権利剥奪 #1.60c7n6
				}
		}
		synchro = 0;

//		statc[player * 10 + 4] = 1; 				 // 最初の1フレームは移動させないゾ

		if(!nanameallow) move = 0;

		//	↓を離している、またはdowntypeが0の場合、下入れ制限解除#1.60c7f9
		if((!getPressState(player, 1-(1*(isUDreverse[player])))) || (!downtype)) down_flag[player] = 0;
		if((!getPressState(player, 0+(1*(isUDreverse[player])))) || (!downtype)) up_flag[player] = 0;
		
		//	高速落下!! 下入れ改造#1.60c7f9
		if((!move) && getPressState(player , 1-(1*(isUDreverse[player]))) && ((sp[player] < 60) || ((rots[player] == 7))) 
		&& (!down_flag[player]) && (statc[player * 10 + 4])) {
			if(heboGB[player]){
				bs[player] = bs[player] + 20;//1/3G
			}else if((rots[player] == 3) || (rots[player] == 6)){
				bs[player] = bs[player] + 30;		//ACE-SRSとDS-WORLDの高速落下を遅く
			}else{
				if(rots[player] == 7) bs[player] = bs[player] + 90;
				else bs[player] = 61;
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

			if((ismagnetblock[player] == 1) || ((kickc[player] >= kickm) && (kickm != -1) && (rots[player] != 6)) ||
			((kickc3[player] >= kickr) && (kickr != -1) && (rots[player] != 6)))
				bk[player] = 100;
				
			bs[player] = 0;
			if((bk[player] == 0) && (smooth)) don = 1;

			if(lockT != 99) // 接着99処理　#1.60c7
				bk[player]++;
			else
				bk[player] = 98;

			// 下入れ改造#1.60c7f9
			if(getPressState(player , 1-(1*(isUDreverse[player]))) && (!down_flag[player]) 
						&& (statc[player * 10 + 4]  && (!move || nanamedown)))
				if((rots[player] == 7) || (heboGB[player]!=0))	// SRS-X即接着
					bk[player] = 100;
				else
					bk[player] = bk[player] + 1 + ((rots[player] == 2) && (!nanamedown));
			
			// 上入れ即接着
			if( ( (getPressState(player , 0+(1*(isUDreverse[player]))) )
				 && (rots[player] != 7) && (!up_flag[player] ) && (heboGB[player]==0) 
				 && (statc[player * 10 + 4]) && (!move || nanamedown))) {
				bk[player] = bk[player] + lockT;
				if((rots[player] == 3) || (rots[player] == 6))	//ACE-SRSは専用のSEを鳴らす
					PlaySE(44);
			}
			
			if((bk[player] > lockT) || ((kickc[player] > kickm) && (kickm != -1)) || ((kickc3[player] > kickr) && (kickr != -1))) {
				if(heboGB[player]==0)
					PlaySE(3);
				else if(heboGB[player] == 1)
					PlaySE(1);
				kickc[player] = 0;
				kickc3[player] = 0;
				statc[player * 10 + 2] ++;
				drawCBlock (player, 0, 0, 0, 10, 0);
				// 下入れ制限#1.60c7f9
				if((getPressState(player , 1-(1*(isUDreverse[player])))) && (downtype) && (!move || nanamedown)) down_flag[player] = 1;
				if(rots[player] != 6) goto lockflash;	// SUPERなSKIP
				return;
			}
		} else {
			// T.L.S. (Temporary Landing System)  (c)1998 AR●KA(^^;
			// 別関数に独立 #1.60c7k4
			drawTLSBlock(player, bottom);
			
			// 上キーで一瞬で落下&固定
			// 上入れ制限追加 #1.60c7p1
			if(getPressState(player , 0+(1*(isUDreverse[player]))) && (!move) && (!sonicdrop) && (!up_flag[player]) && (heboGB[player]==0) && ((statc[player * 10 + 4]))) {
				if(rots[player] != 7){
					if(gameMode[player] == modeNo_ori){//15%
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
					if((world_drop_snd == 1) || ((world_drop_snd == 3) && (rots[player] != 2)) || (rots[player] == 3) || (rots[player] == 6)) PlaySE(1);
					PlaySE(3);
					if((rots[player] == 3) || (rots[player] == 6))	//ACE-SRSは専用のSEを鳴らす
						PlaySE(44);
					kickc[player] = 0;
					kickc3[player] = 0;
					statc[player * 10 + 2] ++;
					drawCBlock (player, 0, 0, 0, 10, 0);
					statc[player * 10 + 5] = 0;	// 回転させた数リセット #1.60c7s6
					if(rots[player] != 6) goto lockflash;	// SUPERなSKIP
					return;
				}
				else {	//SRS-X
					if((sp[player] <= 240) && (!ending[player])) {
						if(dropScCalc(player)){
							sc[player] = sc[player]+(bottom -by[player] -1) *2;//直入れ
						}else{
							sdrop[player] = (bottom -by[player] -1) *2;//一旦sdropへ入れる
						}
					}
//					PlaySE(44);
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
					
					if((ismagnetblock[player] == 1) || ((kickc[player] >= kickm) && (kickm != -1) && (rots[player] != 6)) ||
					((kickc3[player] >= kickr) && (kickr != -1) && (rots[player] != 6)))
						bk[player] = 100;
					
					// 下キーで固定速度アップ #1.60c7r3
					if( getPressState(player, 1-(1*(isUDreverse[player]))) && (!down_flag[player]) 
							&& (statc[player * 10 + 4] ) && (!move || nanamedown)) {
						if((rots[player] != 7) && (heboGB[player]==0)) bk[player] = bk[player] + 1 + ((rots[player] == 2) && (!nanamedown));
						else {	// SRS-X即固定
							PlaySE(1);
							if(heboGB[player]==0)
								PlaySE(3);
							kickc[player] = 0;
							kickc3[player] = 0;
							statc[player * 10 + 2]++;
							drawCBlock (player, 0, 0, 0, 10, 0);
							if(downtype) down_flag[player] = 1;
							if(rots[player] != 6) goto lockflash;	// SUPERなSKIP
							return;
						}
					}
					
					// 上入れ即接着 #1.60c7r3
					if( (getPressState(player , 0+(1*(isUDreverse[player]))) ) 
						&& (rots[player] != 7) &&(!up_flag[player]) && (heboGB[player]==0) 
						&& (statc[player * 10 + 4]) && (!move || nanamedown)) {
						PlaySE(3);
						if((rots[player] == 3) || (rots[player] == 6))	//ACE-SRSは専用のSEを鳴らす
							PlaySE(44);
						kickc[player] = 0;
						kickc3[player] = 0;
						statc[player * 10 + 2]++;
						drawCBlock (player, 0, 0, 0, 10, 0);
						if(downtype) up_flag[player] = 1;
						if(rots[player] != 6) goto lockflash;	// SUPERなSKIP
						return;
					}
				} else {
					// 回転させた数リセット #1.60c7s6
					statc[player * 10 + 5] = 0;
				}
			}
		}

		statc[player * 10 + 4] = 1; 				 // 最初の1フレームは移動させないゾ
				
		// 接地音を鳴らす
		// world_drop_sndが1の場合のみ #1.60c7m9
		if( (don) && (world_drop_snd >= 1) && (heboGB[player]!=1) ) PlaySE(1);
			
		// ブロックを描く
		flash = (count % 2) * (blockflash == 0) + (blockflash == 1);
		kosa = bk[player] * 7 / (lockT + (lockT == 0));
		if(kosa > 6) kosa = 6;
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
		else if(downtype)up_flag[player] = 1;
		
		if(statc[player * 10 + 2] > 1) {	// 接着時の灰色化を1フレ短縮 #1.60c7k8
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
			} else if((tspin_type==2) || (gameMode[player] == modeNo_mis)){
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
			
			// エンディング中の花火発生 #1.60c7s8
			if( (ending[player] == 2) && (gameMode[player] == modeNo_beg)) {
				hanabi_total[player]++;
				hanabi_waiting[player]++;
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
				statc[player * 10 + 3] = 2 * (rots[player] != 6);
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


int	co(int a, int b, int c) {	// conditional op
	if(a) return b;
	else return c;
}
