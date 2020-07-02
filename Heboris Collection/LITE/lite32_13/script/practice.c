//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.16 - PRACTICEモード設定画面
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statPracticeSelect(int player) {
	int i;
	
	if(player == 1) return;		// 2P側だったら何もしない
	
	// メニューを表示
	if(vslevel[0] <= 11) {
		sprintf(string[0], "kn  PAGE 1/3");
		printFont(boffset[0] - 1, 25, string[0], 0);
		
		printFont(boffset[0],  5, "ROT. RULE", fontc[rots[0]]);
		getRuleName(player);
		printFont(boffset[0],  6, string[0], count % 9 * (vslevel[0] == 0));
		
		printFont(boffset[0],  8, "WAITS", fontc[rots[0]]);
		sprintf(string[0], "%s%2d", delayname[0 + english * 4], wait1[0]);
		printFont(boffset[0],  9, string[0], count % 9 * (vslevel[0] == 1));
		sprintf(string[0], "%s%2d", delayname[1 + english * 4], wait2[0]);
		printFont(boffset[0], 10, string[0], count % 9 * (vslevel[0] == 2));
		sprintf(string[0], "%s%2d", delayname[2 + english * 4], wait3[0]);
		printFont(boffset[0], 11, string[0], count % 9 * (vslevel[0] == 3));
		sprintf(string[0], "%s%2d", delayname[3 + english * 4], waitt[0]);
		printFont(boffset[0], 12, string[0], count % 9 * (vslevel[0] == 4));
		sprintf(string[0], "SPEED %4d", sp[0]);
		printFont(boffset[0], 13, string[0], count % 9 * (vslevel[0] == 5));
		
		printFont(boffset[0], 15, "OTHERS", fontc[rots[0]]);
		sprintf(string[0], "FPS     %2d", p_fps);
		printFont(boffset[0], 16, string[0], count % 9 * (vslevel[0] == 6));
		
		printFont(boffset[0], 17, "HIDDEN", count % 9 * (vslevel[0] == 7));
		if(hidden[0] == 0)      printFont(boffset[0] + 9, 17, "e", count % 9 * (vslevel[0] == 7));
		else if(hidden[0] == 1) printFont(boffset[0] + 9, 17, "A", count % 9 * (vslevel[0] == 7));
		else if(hidden[0] == 2) printFont(boffset[0] + 9, 17, "B", count % 9 * (vslevel[0] == 7));
		
		sprintf(string[0], "BGM     %2d", bgmlv + 1);
		printFont(boffset[0], 18, string[0], count % 9 * (vslevel[0] == 8));
		
		printFont(boffset[0], 19, "BIG", count % 9 * (vslevel[0] == 9));
		if(IsBigStart[0] == 0) printFont(boffset[0] + 9, 19, "e", count % 9 * (vslevel[0] == 9));
		else                   printFont(boffset[0] + 9, 19, "c", count % 9 * (vslevel[0] == 9));
		
		printFont(boffset[0], 20, "BIG MOVE", count % 9 * (vslevel[0] == 10));
		sprintf(string[0], "%d", BigMoveStart[0] + 1);
		printFont(boffset[0] + 9, 20, string[0], count % 9 * (vslevel[0] == 10));
		
		printFont(boffset[0], 22, "FAVORITES", fontc[rots[0]]);
		printFont(boffset[0], 23, waitname[p_setting], count % 9 * (vslevel[0] == 11));
	} else if(vslevel[0] <= 27) {
		sprintf(string[0], "kn  PAGE 2/3");
		printFont(boffset[0] - 1, 25, string[0], 0);
		
		printFont(boffset[0],  5, "GIMMICKS", fontc[rots[0]]);
		sprintf(string[0], "MIRROR   %d", isfmirror[0]);
		printFont(boffset[0],  6, string[0], count % 9 * (vslevel[0] == 12));
		sprintf(string[0], "ROLL ROLL%d", isrollroll[0]);
		printFont(boffset[0],  7, string[0], count % 9 * (vslevel[0] == 13));
		sprintf(string[0], "X-RAY    %d", isxray[0]);
		printFont(boffset[0],  8, string[0], count % 9 * (vslevel[0] == 14));
		sprintf(string[0], "COLOR    %d", iscolor[0]);
		printFont(boffset[0],  9, string[0], count % 9 * (vslevel[0] == 15));
		sprintf(string[0], "BLIND    %d", isblind[0]);
		printFont(boffset[0], 10, string[0], count % 9 * (vslevel[0] == 16));
		sprintf(string[0], "THUNDER  %d", isthunder[0]);
		printFont(boffset[0], 11, string[0], count % 9 * (vslevel[0] == 17));
		sprintf(string[0], "[] BLOCK %d", always_over1000[0]);
		printFont(boffset[0], 12, string[0], count % 9 * (vslevel[0] == 18));
		sprintf(string[0], "UDLR REV %d", isUDLRreverse[0]);
		printFont(boffset[0], 13, string[0], count % 9 * (vslevel[0] == 19));
		sprintf(string[0], "ROT LOCK %d", isRotateLock[0]);
		printFont(boffset[0], 14, string[0], count % 9 * (vslevel[0] == 20));
		sprintf(string[0], "HIDE NEXT%d", ishidenext[0]);
		printFont(boffset[0], 15, string[0], count % 9 * (vslevel[0] == 21));
		sprintf(string[0], "OLDHIDDEN%d", hidden_old[0]);
		printFont(boffset[0], 16, string[0], count % 9 * (vslevel[0] == 22));
		sprintf(string[0], "ITEM     %d", item_mode[0]);
		printFont(boffset[0], 17, string[0], count % 9 * (vslevel[0] == 23));
		
		printFont(boffset[0], 18, "BACKGROUND", fontc[rots[0]]);
		sprintf(string[0], "NO. %d", backno);
		printFont(boffset[0], 19, string[0], count % 9 * (vslevel[0] == 24));
		
		printFont(boffset[0], 20, "LOAD STAGE", fontc[rots[0]]);
		sprintf(string[0], "NO. %d", stage[0] + 1);
		printFont(boffset[0], 21, string[0], count % 9 * (vslevel[0] == 25));
		
		printFont(boffset[0], 22, "NEXT BLOCK", fontc[rots[0]]);
		sprintf(string[0], "NEXTC %4d", nextc[0]);
		printFont(boffset[0], 23, string[0], count % 9 * (vslevel[0] == 26));
		sprintf(string[0], "BLOCK    %d", next[0]);
		printFont(boffset[0], 24, string[0], count % 9 * (vslevel[0] == 27));
	} else {
		sprintf(string[0], "kn  PAGE 3/3");
		printFont(boffset[0] - 1, 25, string[0], 0);
		
		printFont(boffset[0],  5, "MODE", fontc[rots[0]]);
		sprintf(string[0], "OLD STYLE%d", heboGB[0]);
		printFont(boffset[0],  6, string[0], count % 9 * (vslevel[0] == 28));
		sprintf(string[0], "SQUARE   %d", squaremode[0]);
		printFont(boffset[0],  7, string[0], count % 9 * (vslevel[0] == 29));
		sprintf(string[0], "SPD TYPE %d", speedtype[0]);
		printFont(boffset[0],  8, string[0], count % 9 * (vslevel[0] == 30));
		
		printFont(boffset[0], 10, "LEVEL TYPE", fontc[rots[0]]);
		if(p_leveltype == 0) sprintf(string[0], "NORMAL");
		if(p_leveltype == 1) sprintf(string[0], "10 LINES");
		if(p_leveltype == 2) sprintf(string[0], "MARATHON");
		printFont(boffset[0], 11, string[0], count % 9 * (vslevel[0] == 31));
		
		printFont(boffset[0], 12, "TIME LIMIT", fontc[rots[0]]);
		if(!p_timelimit) sprintf(string[0], "NO LIMIT");
		else getTime(p_timelimit);
		printFont(boffset[0], 13, string[0], count % 9 * (vslevel[0] == 32));
		
		printFont(boffset[0], 14, "GOAL", fontc[rots[0]]);
		if(!p_goal) {
			sprintf(string[0], "ENDLESS");
		} else {
			if(p_leveltype == 0) sprintf(string[0], "LEVEL %d", p_goal * 100);
			if(p_leveltype == 1) sprintf(string[0], "%d LINES", p_goal * 10);
			if(p_leveltype == 2) sprintf(string[0], "LEVEL %d", p_goal);
		}
		printFont(boffset[0], 15, string[0], count % 9 * (vslevel[0] == 33));
		
		printFont(boffset[0], 16, "STAFF ROLL", fontc[rots[0]]);
		if(p_staffroll == 0) sprintf(string[0], "OFF");
		if(p_staffroll == 1) sprintf(string[0], "ON");
		if(p_staffroll == 2) sprintf(string[0], "FAST ROLL");
		printFont(boffset[0], 17, string[0], count % 9 * (vslevel[0] == 34));
		
		printFont(boffset[0], 19, "SHADOWTIME", fontc[rots[0]]);
		sprintf(string[0], "%d", shadowtime[0]);
		printFont(boffset[0], 20, string[0], count % 9 * (vslevel[0] == 35));
	}
	
	padRepeat( 0 );
	padRepeat2( 0 );
	
	// ↑
	if((mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)))
	if( getPressState(0, 0) ) {
		PlaySE(5);
		vslevel[0]--;
		if(vslevel[0] < 0) vslevel[0] = 35;
	}
	
	// ↓
	if((mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)))
	if( getPressState(0, 1) ) {
		PlaySE(5);
		vslevel[0]++;
		if(vslevel[0] > 35) vslevel[0] = 0;
	}
	
	// ←
	if((mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || (getPressState(0, 6)))
	if( getPressState(0, 2) ) {
		PlaySE(3);
		
		// ROT. STYLE
		if(vslevel[0] == 0) {
			changeRule(0, rots[0] - 1);
		}
		// SYUTUGEN
		if(vslevel[0] == 1) {
			wait1[0]--;
			if(wait1[0] < 0) wait1[0] = 99;
		}
		// SYOUKYO
		if(vslevel[0] == 2) {
			wait2[0]--;
			if(wait2[0] < 0) wait2[0] = 99;
		}
		// SETTYAKU
		if(vslevel[0] == 3) {
			wait3[0]--;
			if(wait3[0] < 0) wait3[0] = 99;
		}
		// YOKOTAME
		if(vslevel[0] == 4) {
			waitt[0]--;
			if(waitt[0] < 0) waitt[0] = 99;
		}
		// SPEED
		if(vslevel[0] == 5) {
			sp[0]--;
			if(sp[0] < 0) sp[0] = 1200;
		}
		// FPS
		if(vslevel[0] == 6) {
			p_fps--;
			if(p_fps < 1) p_fps = 99;
		}
		// HIDDEN
		if(vslevel[0] == 7) {
			hidden[0]--;
			if(hidden[0] < 0) hidden[0] = 2;
		}
		// BGMLV
		if(vslevel[0] == 8) {
			bgmlv--;
			if(bgmlv < 0) bgmlv = 20;
		}
		// BIG
		if(vslevel[0] == 9) {
			IsBigStart[0] = !IsBigStart[0];
		}
		// BIG MOVE
		if(vslevel[0] == 10) {
			BigMoveStart[0] = !BigMoveStart[0];
		}
		// FAVORITES
		if(vslevel[0] == 11) {
			i = 0;	// 無限ループ防止用
			
			do {
				p_setting--;
				
				if(p_setting < 0) {
					if(i == 0) {
						p_setting = 19;
						i = 1;
					} else {
						p_setting = 0;
						break;
					}
				}
			} while(favorites_isempty(p_setting));
		}
		// MIRROR
		if(vslevel[0] == 12) {
			isfmirror[0] = !isfmirror[0];
		}
		// ROLL ROLL
		if(vslevel[0] == 13) {
			isrollroll[0] = !isrollroll[0];
		}
		// X-RAY
		if(vslevel[0] == 14) {
			isxray[0] = !isxray[0];
		}
		// COLOR
		if(vslevel[0] == 15) {
			iscolor[0] = !iscolor[0];
		}
		// BLIND
		if(vslevel[0] == 16) {
			isblind[0] = !isblind[0];
		}
		// THUNDER
		if(vslevel[0] == 17) {
			isthunder[0] = !isthunder[0];
		}
		// [] BLOCK
		if(vslevel[0] == 18) {
			always_over1000[0] = !always_over1000[0];
			setNextBlockColors(0, 1);
		}
		// UDLR REV
		if(vslevel[0] == 19) {
			isUDLRreverse[0] = !isUDLRreverse[0];
		}
		// ROT LOCK
		if(vslevel[0] == 20) {
			isRotateLock[0] = !isRotateLock[0];
		}
		// HIDE NEXT
		if(vslevel[0] == 21) {
			ishidenext[0] = !ishidenext[0];
		}
		// OLDHIDDEN
		if(vslevel[0] == 22) {
			hidden_old[0]--;
			if(hidden_old[0] < 0) hidden_old[0] = 7;
		}
		// ITEM
		if(vslevel[0] == 23) {
			item_mode[0] = !item_mode[0];
		}
		// BACKGROUND
		if(vslevel[0] == 24) {
			backno--;
			if(backno < 0) backno = 14;
			p_backno = backno;
		}
		// LOAD STAGE
		if(vslevel[0] == 25) {
			stage[0]--;
			if(stage[0] < 0) stage[0] = 999;
		}
		// NEXTC
		if(vslevel[0] == 26) {
			nextc[0]--;
			if(nextc[0] < 0) nextc[0] = nextb_max[0] - 1;
			next[0] = nextb[nextc[0]];
			setNextBlockColors(0, 1);
		}
		// BLOCK
		if(vslevel[0] == 27) {
			next[0]--;
			if(next[0] < 0) next[0] = 6;
			nextb[nextc[0]] = next[0];
			setNextBlockColors(0, 1);
		}
		// OLD STYLE
		if(vslevel[0] == 28) {
			heboGB[0]--;
			if(heboGB[0] < 0) heboGB[0] = 2;
		}
		// SQUARE
		if(vslevel[0] == 29) {
			squaremode[0] = !squaremode[0];
		}
		// SPD TYPE
		if(vslevel[0] == 30) {
			speedtype[0] = !speedtype[0];
		}
		// LEVEL TYPE
		if(vslevel[0] == 31) {
			p_leveltype--;
			if(p_leveltype < 0) p_leveltype = 2;
		}
		// TIME LIMIT
		if(vslevel[0] == 32) {
			p_timelimit = p_timelimit - 60;
			if(p_timelimit < 0) p_timelimit = 72000;
		}
		// GOAL
		if(vslevel[0] == 33) {
			p_goal--;
			if(p_goal < 0) p_goal = 20;
		}
		// STAFF ROLL
		if(vslevel[0] == 34) {
			p_staffroll--;
			if(p_staffroll < 0) p_staffroll = 2;
		}
		// SHADOWTIME
		if(vslevel[0] == 35) {
			shadowtime[0]--;
			if(shadowtime[0] < 0) shadowtime[0] = 1000;
		}
	}
	
	// →
	if((mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || (getPressState(0, 6)))
	if( getPressState(0, 3) ) {
		PlaySE(3);
		
		// ROT. STYLE
		if(vslevel[0] == 0) {
			changeRule(0, rots[0] + 1);
		}
		// SYUTUGEN
		if(vslevel[0] == 1) {
			wait1[0]++;
			if(wait1[0] > 99) wait1[0] = 0;
		}
		// SYOUKYO
		if(vslevel[0] == 2) {
			wait2[0]++;
			if(wait2[0] > 99) wait2[0] = 0;
		}
		// SETTYAKU
		if(vslevel[0] == 3) {
			wait3[0]++;
			if(wait3[0] > 99) wait3[0] = 0;
		}
		// YOKOTAME
		if(vslevel[0] == 4) {
			waitt[0]++;
			if(waitt[0] > 99) waitt[0] = 0;
		}
		// SPEED
		if(vslevel[0] == 5) {
			sp[0]++;
			if(sp[0] > 1200) sp[0] = 0;
		}
		// FPS
		if(vslevel[0] == 6) {
			p_fps++;
			if(p_fps > 99) p_fps = 1;
		}
		// HIDDEN
		if(vslevel[0] == 7) {
			hidden[0]++;
			if(hidden[0] > 2) hidden[0] = 0;
		}
		// BGMLV
		if(vslevel[0] == 8) {
			bgmlv++;
			if(bgmlv > 20) bgmlv = 0;
		}
		// BIG
		if(vslevel[0] == 9) {
			IsBigStart[0] = !IsBigStart[0];
		}
		// BIG MOVE
		if(vslevel[0] == 10) {
			BigMoveStart[0] = !BigMoveStart[0];
		}
		// FAVORITES
		if(vslevel[0] == 11) {
			i = 0;	// 無限ループ防止用
			
			do {
				p_setting++;
				
				if(p_setting > 19) {
					if(i == 0) {
						p_setting = 0;
						i = 1;
					} else {
						p_setting = 0;
						break;
					}
				}
			} while(favorites_isempty(p_setting));
		}
		// MIRROR
		if(vslevel[0] == 12) {
			isfmirror[0] = !isfmirror[0];
		}
		// ROLL ROLL
		if(vslevel[0] == 13) {
			isrollroll[0] = !isrollroll[0];
		}
		// X-RAY
		if(vslevel[0] == 14) {
			isxray[0] = !isxray[0];
		}
		// COLOR
		if(vslevel[0] == 15) {
			iscolor[0] = !iscolor[0];
		}
		// BLIND
		if(vslevel[0] == 16) {
			isblind[0] = !isblind[0];
		}
		// THUNDER
		if(vslevel[0] == 17) {
			isthunder[0] = !isthunder[0];
		}
		// [] BLOCK
		if(vslevel[0] == 18) {
			always_over1000[0] = !always_over1000[0];
			setNextBlockColors(0, 1);
		}
		// UDLR REV
		if(vslevel[0] == 19) {
			isUDLRreverse[0] = !isUDLRreverse[0];
		}
		// ROT LOCK
		if(vslevel[0] == 20) {
			isRotateLock[0] = !isRotateLock[0];
		}
		// HIDE NEXT
		if(vslevel[0] == 21) {
			ishidenext[0] = !ishidenext[0];
		}
		// OLDHIDDEN
		if(vslevel[0] == 22) {
			hidden_old[0]++;
			if(hidden_old[0] > 7) hidden_old[0] = 0;
		}
		// ITEM
		if(vslevel[0] == 23) {
			item_mode[0] = !item_mode[0];
		}
		// BACKGROUND
		if(vslevel[0] == 24) {
			backno++;
			if(backno > 14) backno = 0;
			p_backno = backno;
		}
		// LOAD STAGE
		if(vslevel[0] == 25) {
			stage[0]++;
			if(stage[0] > 999) stage[0] = 0;
		}
		// NEXTC
		if(vslevel[0] == 26) {
			nextc[0]++;
			if(nextc[0] > nextb_max[0] - 1) nextc[0] = 0;
			next[0] = nextb[nextc[0]];
			setNextBlockColors(0, 1);
		}
		// BLOCK
		if(vslevel[0] == 27) {
			next[0]++;
			if(next[0] > 6) next[0] = 0;
			nextb[nextc[0]] = next[0];
			setNextBlockColors(0, 1);
		}
		// OLD STYLE
		if(vslevel[0] == 28) {
			heboGB[0]++;
			if(heboGB[0] > 2) heboGB[0] = 0;
		}
		// SQUARE
		if(vslevel[0] == 29) {
			squaremode[0] = !squaremode[0];
		}
		// SPD TYPE
		if(vslevel[0] == 30) {
			speedtype[0] = !speedtype[0];
		}
		// LEVEL TYPE
		if(vslevel[0] == 31) {
			p_leveltype++;
			if(p_leveltype > 2) p_leveltype = 0;
		}
		// TIME LIMIT
		if(vslevel[0] == 32) {
			p_timelimit = p_timelimit + 60;
			if(p_timelimit > 72000) p_timelimit = 0;
		}
		// GOAL
		if(vslevel[0] == 33) {
			p_goal++;
			if(p_goal > 20) p_goal = 0;
		}
		// STAFF ROLL
		if(vslevel[0] == 34) {
			p_staffroll++;
			if(p_staffroll > 2) p_staffroll = 0;
		}
		// SHADOWTIME
		if(vslevel[0] == 35) {
			shadowtime[0]++;
			if(shadowtime[0] > 1000) shadowtime[0] = 0;
		}
	}
	
	// ショートカットキーが押されたら対応する設定を読み込み
	for(i = 0; i < 20; i++) {
		if( IsPushKey(waitkey[i]) ) {
			PlaySE(3);
			loadWait(0, i);
		}
	}
	
	// Bボタン
	if( getPushState(0, 5) ) {
		PlaySE(5);
		gameMode[0] = 0;
		gameMode[1] = 0;
		playerInitial(0);
		playerInitial(1);
		stat[0] = 2;
		stat[1] = 0;
		backno = 0;
	}
	
	// Aボタン
	if( getPushState(0, 4) ) {
		if(vslevel[0] == 11) {
			// 設定読み込み
			PlaySE(3);
			loadWait(0, p_setting);
		} else if(vslevel[0] == 25) {
			// ステージ読み込み
			PlaySE(3);
			loadTomoyoStage(0, stage[0], 0);
		} else {
			// ゲーム開始
			PlaySE(10);
			PracticeStart();
		}
	}
	
	// HOLDボタンでフィールドエディットへ
	if( getPushState(0, 7) ) {
		stat[0] = 17;
		statc[0] = 16;	// 戻り先指定
		statc[1] = 0;
		statc[2] = 1;	// 配置不可フラグ設定
		statc[3] = 0;
		statc[4] = 1;	// Y座標
	}
}

// スタート処理
void PracticeStart() {
	int i;
	
	p_replay_save_enable = isBravo(0);
	
	playerInitial(1);	// 2P側の記録を消す
	stat[1] = 16;		// 何もしないようにする
	
	// 速度をバックアップ
	b_sp[0]    = sp[0];
	b_wait1[0] = wait1[0];
	b_wait2[0] = wait2[0];
	b_wait3[0] = wait3[0];
	b_waitt[0] = waitt[0];
	
	// BIG設定
	IsBig[0] = IsBigStart[0];
	BigMove[0] = BigMoveStart[0];
	
	// FPS設定
	if(p_fps != main_fps) SetFPS(p_fps);
	
	// ギミックON/OFFをバックアップ
	b_hidden[0]        = hidden[0];
	b_isfmirror[0]     = isfmirror[0];
	b_isrollroll[0]    = isrollroll[0];
	b_isxray[0]        = isxray[0];
	b_iscolor[0]       = iscolor[0];
	b_isblind[0]       = isblind[0];
	b_isthunder[0]     = isthunder[0];
	b_isUDLRreverse[0] = isUDLRreverse[0];
	b_isRotateLock[0]  = isRotateLock[0];
	b_ishidenext[0]    = ishidenext[0];
	b_hidden_old[0]    = hidden_old[0];
	b_item_mode[0]     = item_mode[0];
	b_heboGB[0]        = heboGB[0];
	b_squaremode[0]    = squaremode[0];
	b_speedtype[0]     = speedtype[0];
	b_shadowtime[0]    = shadowtime[0];
	
	// BGM
	b_bgmlv = bgmlv;
	start_bgmlv[0] = bgmlv;
	
	// 制限時間を設定
	ltime[0] = p_timelimit;
	
	// ノルマ設定
	if(p_leveltype == 1) {
		tc[0] = 0;
		c_norm[0] = 0;
		m_norm[0] = 10;
	}
	if(p_leveltype == 2) {
		tc[0] = 0;
		c_norm[0] = 0;
		m_norm[0] = 5;
	}
	
	// Ready
	stat[0] = 3;
	
	// ステータスカウンタ初期化
	for(i = 0; i < 10; i++) statc[i] = 0;
}

// 死んだとき
void PracticeDeath() {
	if(replayauto) statc[0]++;
	
	timeOn[0] = 0;
	timeOn[1] = 0;
	onRecord[0] = 0;
	onRecord[1] = 0;
	pinch[0] = 0;
	pinch[1] = 0;
	
	if(GetFPS() != main_fps) SetFPS(main_fps);	// FPSを戻す
	
	// 結果表示
	printFont(boffset[0], 6, "PLAY DATA", 4);
	
	printFont(boffset[0], 8, "LINE ERASE", fontc[rots[0]]);
	sprintf(string[0], "SINGLE %3d", line_count[0]);
	printFont(boffset[0], 9, string[0], 0);
	sprintf(string[0], "DOUBLE %3d", line_count[1]);
	printFont(boffset[0], 10, string[0], 0);
	sprintf(string[0], "TRIPLE %3d", line_count[2]);
	printFont(boffset[0], 11, string[0], 0);
	sprintf(string[0], "HEBORIS%3d", line_count[3]);
	printFont(boffset[0], 12, string[0], 0);
	
	if((tspin_type != 0) && (isTSpinEnableMode(0))) {
		printFont(boffset[0], 14, "T-SPIN", fontc[rots[0]]);
		sprintf(string[0], "ZERO   %3d", tspin_count[0]);
		printFont(boffset[0], 15, string[0], 0);
		sprintf(string[0], "SINGLE %3d", tspin_count[1]);
		printFont(boffset[0], 16, string[0], 0);
		sprintf(string[0], "DOUBLE %3d", tspin_count[2]);
		printFont(boffset[0], 17, string[0], 0);
		
		if( (tspin_type != 4) && (isWRule(0)) ) {
			sprintf(string[0], "TRIPLE %3d", tspin_count[3]);
			printFont(boffset[0], 18, string[0], 0);
		}
	}
	
	printFont(boffset[0], 20, "LINES", fontc[rots[0]]);
	sprintf(string[0], "%10d", c_norm[0]);
	printFont(boffset[0], 21, string[0], 0);
	
	if(p_leveltype != 1) {
		printFont(boffset[0], 22, "SCORE", fontc[rots[0]]);
		sprintf(string[0], "%10d", sc[0]);
		printFont(boffset[0], 23, string[0], 0);
	}
	
	// 裏段位
	if(!statc[0]) {
		statc[1] = checkSecretGrade(0);
	}
	if(statc[1] >= min_sgrade) {
		printFont(boffset[0], 26, "S-GRADE", fontc[rots[0]]);
		sprintf(string[0], "%2s", sgname[statc[1]]);
		printFont(boffset[0] + 8, 26, string[0], 0);
	}
	
	// ボタン
	if(getPushState(0, 4) || getPushState(0, 5) || (statc[0] >= 500)) {
		if((replayauto) && (replayno != 41)) {
			stat[0] = 0;
			stat[1] = 0;
			flag = 1;
		} else if(p_replay_save_enable) {
			stat[0] = 24;
			statc[0] = 0;
			statc[1] = 0;
			statc[2] = 0;
			flag = 0;
		} else {
			PracticeOver();
		}
	}
}

// PRACTICE終了処理
void PracticeOver() {
	int i, bak;
	
	if(GetFPS() != main_fps) SetFPS(main_fps);	// FPSを戻す
	backno = p_backno;
	
	versusInit(0);	// NEXTリセット
	versusInit(1);
	
	// 1Pの成績を2Pにコピーする
	for(i = 0; i < 220; i++) {
		fld[i + 220] = fld[i];
		fldt[i + 220] = (fld[i] != 0) * -1;
		fldi[i + 220] = fldi[i];
		fldo[i + 220] = fldo[i];
		flds[i + 220] = flds[i];
	}
	
	sc[1] = sc[0];
	tc[1] = tc[0];
	gameTimer[1] = gameTimer[0];
	bak = rots[1];
	rots[1] = rots[0];
	
	wait1[1] = wait1[0];
	wait2[1] = wait2[0];
	wait3[1] = wait3[0];
	waitt[1] = waitt[0];
	sp[1] = sp[0];
	
	// BIG設定 #LITE30.2
	IsBigStart[1] = IsBigStart[0];
	BigMoveStart[1] = BigMoveStart[0];
	
	// []
	always_over1000[1] = always_over1000[0];
	
	// ステージ
	stage[1] = stage[0];
	
	// 1Pを初期化する
	playerInitial(0);
	
	// wait値を2Pから戻す（↑のplayerInitialで初期化されるため）
	rots[0] = rots[1];
	wait1[0] = wait1[1];
	wait2[0] = wait2[1];
	wait3[0] = wait3[1];
	waitt[0] = waitt[1];
	sp[0] = sp[1];
	
	// BIG設定 #LITE30.2
	IsBigStart[0] = IsBigStart[1];
	BigMoveStart[0] = BigMoveStart[1];
	
	// 速度をバックアップから戻す
	sp[0]    = b_sp[0];
	wait1[0] = b_wait1[0];
	wait2[0] = b_wait2[0];
	wait3[0] = b_wait3[0];
	waitt[0] = b_waitt[0];
	
	// ギミックON/OFFをバックアップから戻す
	hidden[0]        = b_hidden[0];
	isfmirror[0]     = b_isfmirror[0];
	isrollroll[0]    = b_isrollroll[0];
	isxray[0]        = b_isxray[0];
	iscolor[0]       = b_iscolor[0];
	isblind[0]       = b_isblind[0];
	isthunder[0]     = b_isthunder[0];
	isUDLRreverse[0] = b_isUDLRreverse[0];
	isRotateLock[0]  = b_isRotateLock[0];
	ishidenext[0]    = b_ishidenext[0];
	hidden_old[0]    = b_hidden_old[0];
	item_mode[0]     = b_item_mode[0];
	heboGB[0]        = b_heboGB[0];
	squaremode[0]    = b_squaremode[0];
	speedtype[0]     = b_speedtype[0];
	shadowtime[0]    = b_shadowtime[0];
	
	// BGM
	bgmlv = b_bgmlv;
	
	// []
	always_over1000[0] = always_over1000[1];
	
	// ステージ
	stage[0] = stage[1];
	
	// 2Pの回転法則を戻す
	rots[1] = bak;
	
	// プレイヤーデータ保存
	if(user_enable[0]) user_save(0);
	
	// PRACTICEモード設定画面に戻る
	setNextBlockColors(0, 1);
	flag = 0;
	stat[0] = 16;
}
