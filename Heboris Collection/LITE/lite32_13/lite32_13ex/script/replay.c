//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  キーが押されてたらリプレイを保存する
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void ReplaySaveCheck(int player, int statnumber) {
	int i;

	if((time2[player] <= 72000) && (!replayauto) && (!demo) && (gameMode[player] != 4) && (gameMode[player] != 5)) {
		for(i = 0; i < 10; i++) {
			if(IsPushKey(2 + i + player * 14)) {
				saveReplayData(player, i + player * 10 + 1);
				statc[player * 10 + statnumber] = i + player * 10 + 1;
			}
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   リプレイデータをセーブ
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void saveReplayData(int pl, int number) {
	int i, j, temp1, temp2, max, player;
	player = pl;
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	// ファイルフォーマット (4byte単位)
	//   0～    3 ヘッダ
	//   4        ファイルサイズ
	//   5～  179 ネクストブロック
	// 180～  199 ステージスキップを使ったフレーム
	// 200～  599 ゲームの設定
	// 600～36599 リプレイデータ
	
	saveBuf[0] = 0x4F424548;	// ヘッダ
	saveBuf[1] = 0x4554494C;
	saveBuf[2] = 0x4C504552;
	saveBuf[3] = 0x32765941;
	
	// NEXTブロック
	for(i = 0; i < 175; i++) {
		temp1 = 0;
		for(j = 0; j < 8; j++) {
			temp1 = temp1 | (nextb[(i << 3) + j + pl * 1400] << (j * 4));
		}
		saveBuf[i + 5] = temp1;
	}
	
	// ステージスキップを使ったフレーム
	for(i = 0; i < 20; i++) saveBuf[180 + i] = stage_skip_frame[i + pl * 20];
	
	// ゲーム設定
	saveBuf[200] = gameTimer[pl];
	saveBuf[201] = gameMode[pl];
	saveBuf[202] = sc[pl];
	
	if(gameMode[pl] == 6)
		saveBuf[203] = clearp[pl];		// TOMOYOモードのクリア率
	else if(gameMode[pl] == 15)
		saveBuf[203] = stage[pl];		// FLASHのステージ
	else
		saveBuf[203] = tc[pl];			// レベル
	
	saveBuf[204] = repversw;			// リプレイバージョン
	saveBuf[205] = firstseed[pl];		// 乱数シード
	saveBuf[206] = downtype;			// 下入れ
	saveBuf[207] = lvupbonus;			// レベルアップボーナス
	saveBuf[208] = enable_minspeed;		// TOMOYOモードのスピード下限有効無効
	saveBuf[209] = disable_hold;		// HOLD封印
	saveBuf[210] = mps[pl * 2    ];		// 横溜め
	saveBuf[211] = mps[pl * 2 + 1];		// 横溜め
	saveBuf[212] = r_enable[pl];		// せり上がり有効無効
	saveBuf[213] = r_start[pl];			// せり上がり開始
	saveBuf[214] = r_end[pl];			// せり上がり終了
	saveBuf[215] = r_inter[pl];			// せり上がり間隔
	saveBuf[216] = IsBigStart[pl];		// BIGモード
	saveBuf[217] = BigMoveStart[pl];	// BIG横移動
	saveBuf[218] = start_stage[pl];		// TOMOYO 開始ステージ
	saveBuf[219] = start_nextc[pl];		// 開始時のnextc
	saveBuf[220] = timelimit[0 + pl * 2];	// 足切りタイム #LITE20
	saveBuf[221] = timelimit[1 + pl * 2];
	saveBuf[222] = hnext[pl];			// NEXT表示数 #LITE23
	saveBuf[223] = r_irs;				// IRS基準
	saveBuf[224] = ready_start[pl];		// ready開始
	saveBuf[225] = ready_end[pl];		// ready終了
	saveBuf[226] = go_start[pl];		// go開始
	saveBuf[227] = go_end[pl];			// go終了
	saveBuf[228] = spawn_y_type;		// 出現位置
	saveBuf[229] = w_lockdown;
	saveBuf[230] = wsoftlock;
	saveBuf[231] = rot180;
	saveBuf[232] = tspin_type;
	saveBuf[233] = mission_file;		// ミッションのファイル
	saveBuf[234] = start_mission;		// どのミッションから始めたか
	saveBuf[235] = bonus_tspin;
	saveBuf[236] = bonus_btb;
	saveBuf[237] = ending_timelimit;
	saveBuf[238] = gradetype[pl];
	saveBuf[239] = rule_rot[rots[pl]];
	saveBuf[240] = rule_hard_lock[rots[pl]];
	saveBuf[241] = rule_soft_lock[rots[pl]];
	saveBuf[242] = rule_soft_speed[rots[pl]];
	saveBuf[243] = rule_are[rots[pl]];
	saveBuf[244] = rule_color[rots[pl]];
	saveBuf[245] = rule_lock_reset[rots[pl]];
	saveBuf[246] = rule_lock_sound[rots[pl]];
	saveBuf[247] = rule_ars_extrot[rots[pl]];
	saveBuf[248] = rule_lock_limit[rots[pl]];
	saveBuf[249] = rule_graphics[rots[pl]];
	saveBuf[250] = skip_blocklockflash;
	saveBuf[251] = drs_floorkick;
	saveBuf[252] = rule_rot_limit[rots[pl]];
	saveBuf[253] = tomoyo_clear_erase;
	saveBuf[254] = rule_180rot[rots[pl]];
	saveBuf[255] = item_mode[pl];
	saveBuf[256] = item_interval;
	saveBuf[257] = item_num;
	saveBuf[258] = enable_item_hold;
	
	for(i = 0; i < 32; i++) saveBuf[259] = BitSet(saveBuf[259], i, item_switch[i]);
	
	saveBuf[260] = enable_ff_rerise;
	saveBuf[261] = item_gauge_uptype;
	
	// VERSUS/PRACTICE/SIMPLEモード用
	if((gameMode[pl] == 4) || (gameMode[pl] == 5) || (gameMode[pl] == 17)) {
		saveBuf[262] = wait1[pl];
		saveBuf[263] = wait2[pl];
		saveBuf[264] = wait3[pl];
		saveBuf[265] = waitt[pl];
		saveBuf[266] = sp[pl];
		saveBuf[267] = start_bgmlv[pl];
	}
	
	saveBuf[268] = rule_max_waitt[rots[pl]];
	saveBuf[269] = nextskip;
	saveBuf[270] = rule_oblk_bg[rots[pl]];
	
	for(i = 32; i < 39; i++) saveBuf[271] = BitSet(saveBuf[271], i - 32, item_switch[i]);
	saveBuf[272] = cpu_flag[pl];
	saveBuf[273] = cpu_level[pl];
	saveBuf[274] = vs_goal_level;
	saveBuf[275] = vs_timelimit;
	saveBuf[276] = vs_goal_type;
	saveBuf[277] = flash_edit[pl];
	saveBuf[278] = enable_combo;
	saveBuf[279] = enable_irs;
	saveBuf[280] = devil_doom_n_rise;
	
	saveBuf[290] = smooth;
	saveBuf[291] = nanameallow;
	saveBuf[292] = sonicdrop;
	saveBuf[293] = fastlrmove;
	saveBuf[294] = rots[pl];			// 回転方式
	
	// リプレイ選択画面での表示用
	if((gameMode[pl] == 1) || (gameMode[pl] == 2) || (gameMode[pl] == 3) || (gameMode[pl] == 16))
		saveBuf[295] = grade[pl];	// MASTER, 20G, DEVIL-DOOM, DEVIL-HARD
	else if((gameMode[pl] ==  0) || (gameMode[pl] ==  9) || (gameMode[pl] == 10) || (gameMode[pl] == 11) || 
			(gameMode[pl] == 13) || (gameMode[pl] == 14) || (gameMode[pl] == 15) || 
			((gameMode[pl] == 5) && (p_leveltype != 1)) || 
			((timeattack[pl] != 0) && (timeattack[pl] != 2) && (gameMode[pl] == 17)) || 
			(gameMode[player] == 18))
		saveBuf[295] = sc[pl];		// BEGINNER,PRACTICE,OLD STYLE,HEBO+,DEVIL,NOVICE,FINAL,FLASH,SIMPLE-ULTRA,MARATHON
	else if(gameMode[pl] == 6)
		saveBuf[295] = stage[pl];	// TOMOYO
	else if(gameMode[pl] == 8)
		saveBuf[295] = c_mission;	// MISSION
	else
		saveBuf[295] = c_norm[pl];	// ACE, HI-SPEED1, HI-SPEED2, ANOTHER2, SIMPLE-40LINES
	
	saveBuf[296] = timeattack[pl];		// TIME TRIAL
	saveBuf[297] = nextb_max[pl];		// NEXTのループ間隔
	saveBuf[298] = ace_irs;				// IRSタイプ
	saveBuf[299] = w_reverse;			// ワールド時回転方向逆転
	
	for(i = 0; i < 50; i++) saveBuf[300 + i] = item_pro[i];	// アイテム出現率
	
	// PRACTICEの設定
	if(gameMode[pl] == 5) {
		saveBuf[350] = always_over1000[0];
		saveBuf[351] = hidden[0];
		saveBuf[352] = isfmirror[0];
		saveBuf[353] = isrollroll[0];
		saveBuf[354] = isxray[0];
		saveBuf[355] = iscolor[0];
		saveBuf[356] = isblind[0];
		saveBuf[357] = isthunder[0];
		saveBuf[358] = isUDLRreverse[0];
		saveBuf[359] = isRotateLock[0];
		saveBuf[360] = ishidenext[0];
		saveBuf[361] = hidden_old[0];
		//saveBuf[362] = item_mode[0];
		if(repversw >= 4) saveBuf[362] = shadowtime[0];
		saveBuf[363] = heboGB[0];
		saveBuf[364] = squaremode[0];
		saveBuf[365] = speedtype[0];
		saveBuf[366] = backno;
		saveBuf[367] = p_leveltype;
		saveBuf[368] = p_timelimit;
		saveBuf[369] = p_goal;
		saveBuf[370] = p_staffroll;
	}
	
	max = time2[pl] / 2;
	if(max > 60 * 60 * 20 / 2) max = 60 * 60 * 20 / 2;
	
	// 操作データ
	for(i = 0; i < max; i++) {
		if(!pl) {
			saveBuf[i + 600] = replayData[(i << 1)] | (replayData[(i << 1) + 1] << 16);
		} else {
			saveBuf[i + 600] = replayData2[(i << 1)] | (replayData2[(i << 1) + 1] << 16);
		}
	}
	
	saveBuf[4] = (max + 600) * 4;	// ファイルサイズを保存
	
	// ファイルに保存
	if(number == -1)
		sprintf(string[0], "DEMO.SAV");
	else if(number == 41)
		sprintf(string[0], "replay/LASTPLAY.SAV");
	else if((gameMode[0] == 4) && (pl == 1) && (number == 41))
		sprintf(string[0], "replay/LASTPLAY_2P.SAV");
	else if((gameMode[0] == 4) && (pl == 1))
		sprintf(string[0], "replay/REPLAY%02d_2P.SAV", number);
	else
		sprintf(string[0], "replay/REPLAY%02d.SAV", number);
	
	SaveFile(string[0], &saveBuf, saveBuf[4]);
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   リプレイデータをロード
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int loadReplayData(int pl, int number) {
	int i, j, temp1, temp2, max, player;
	player = pl;
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	if(number == -1)
		sprintf(string[0], "DEMO.SAV");
	else if(number == 41)
		sprintf(string[0], "replay/LASTPLAY.SAV");
	else if((gameMode[0] == 4) && (pl == 1) && (number == 41))
		sprintf(string[0], "replay/LASTPLAY_2P.SAV");
	else if((gameMode[0] == 4) && (pl == 1))
		sprintf(string[0], "replay/REPLAY%02d_2P.SAV", number);
	else
		sprintf(string[0], "replay/REPLAY%02d.SAV", number);
	
	// ヘッダだけ読み込み
	LoadFile(string[0], &saveBuf, 20);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x4F424548) return -1;
	if(saveBuf[1] != 0x4554494C) return -1;
	if(saveBuf[2] != 0x4C504552) return -1;
	if(saveBuf[3] != 0x32765941) return -1;
	
	// 全部読み込み
	LoadFile(string[0], &saveBuf, saveBuf[4]);
	
	// NEXTブロック
	for(i = 0; i < 175; i++) {
		for(j = 0; j < 8; j++) {
			nextb[(i << 3) + j + pl * 1400] = ((saveBuf[5 + i]) >> (j * 4)) & 15;
		}
	}
	
	// ステージスキップを使ったフレーム
	for(i = 0; i < 20; i++) stage_skip_frame[i + pl * 20] = saveBuf[180 + i];
	
	gameMode[pl] = saveBuf[201];		// モード
	rots[pl] = saveBuf[294];			// 回転方式
	
	repversw = saveBuf[204];			// リプレイバージョン
	firstseed[pl] = saveBuf[205];		// 乱数シード
	randseed[pl] = firstseed[pl];
	downtype = saveBuf[206];			// 下入れ
	lvupbonus = saveBuf[207];			// レベルアップボーナス
	enable_minspeed = saveBuf[208];		// TOMOYOモードのスピード下限有効無効
	disable_hold = saveBuf[209];		// HOLD封印
	mps[pl * 2    ] = saveBuf[210];		// 横溜め
	mps[pl * 2 + 1] = saveBuf[211];		// 横溜め
	r_enable[pl] = saveBuf[212];		// せり上がり有効無効
	r_start[pl]  = saveBuf[213];		// せり上がり開始
	r_end[pl]    = saveBuf[214];		// せり上がり終了
	r_inter[pl]  = saveBuf[215];		// せり上がり間隔
	IsBig[pl]    = saveBuf[216];		// BIGモード
	BigMove[pl]  = saveBuf[217];		// BIG横移動
	start_stage[pl] = saveBuf[218];		// TOMOYO 開始ステージ
	start_nextc[pl] = saveBuf[219];		// 開始時のnextc
	
	timelimit[0 + pl * 2] = saveBuf[220];	// 足切りタイム #LITE20
	timelimit[1 + pl * 2] = saveBuf[221];
	
	hnext[pl]        = saveBuf[222];		// NEXT表示数 #LITE23
	r_irs            = saveBuf[223];		// IRS基準
	ready_start[pl]  = saveBuf[224];		// ready開始
	ready_end[pl]    = saveBuf[225];		// ready終了
	go_start[pl]     = saveBuf[226];		// go開始
	go_end[pl]       = saveBuf[227];		// go終了
	spawn_y_type     = saveBuf[228];		// 出現位置
	w_lockdown       = saveBuf[229];
	wsoftlock        = saveBuf[230];
	rot180           = saveBuf[231];
	tspin_type       = saveBuf[232];
	mission_file     = saveBuf[233];		// ミッションのファイル
	start_mission    = saveBuf[234];		// どのミッションから始めたか
	c_mission        = start_mission;
	bonus_tspin      = saveBuf[235];
	bonus_btb        = saveBuf[236];
	ending_timelimit = saveBuf[237];
	gradetype[pl]    = saveBuf[238];
	rule_rot[rots[pl]]        = saveBuf[239];
	rule_hard_lock[rots[pl]]  = saveBuf[240];
	rule_soft_lock[rots[pl]]  = saveBuf[241];
	rule_soft_speed[rots[pl]] = saveBuf[242];
	rule_are[rots[pl]]        = saveBuf[243];
	rule_color[rots[pl]]      = saveBuf[244];
	rule_lock_reset[rots[pl]] = saveBuf[245];
	rule_lock_sound[rots[pl]] = saveBuf[246];
	rule_ars_extrot[rots[pl]] = saveBuf[247];
	rule_lock_limit[rots[pl]] = saveBuf[248];
	rule_graphics[rots[pl]]   = saveBuf[249];
	skip_blocklockflash = saveBuf[250];
	drs_floorkick = saveBuf[251];
	rule_rot_limit[rots[pl]] = saveBuf[252];
	tomoyo_clear_erase = saveBuf[253];
	rule_180rot[rots[pl]] = saveBuf[254];
	item_mode[pl] = saveBuf[255];
	item_interval = saveBuf[256];
	item_num = saveBuf[257];
	enable_item_hold = saveBuf[258];
	
	item_all[pl] = 0;
	for(i = 0; i < 32; i++) {
		item_switch[i] = BitTest(saveBuf[259], i);
		if(item_switch[i] != 0) item_all[pl]++;
	}
	
	enable_ff_rerise = saveBuf[260];
	item_gauge_uptype = saveBuf[261];
	
	// VERSUS/PRACITCE/SIMPLEモード用
	if((gameMode[pl] == 4) || (gameMode[pl] == 5) || (gameMode[pl] == 17)) {
		wait1[pl] = saveBuf[262];
		wait2[pl] = saveBuf[263];
		wait3[pl] = saveBuf[264];
		waitt[pl] = saveBuf[265];
		sp[pl] = saveBuf[266];
		start_bgmlv[pl] = saveBuf[267];
	}
	
	rule_max_waitt[rots[pl]] = saveBuf[268];
	nextskip = saveBuf[269];
	rule_oblk_bg[rots[pl]] = saveBuf[270];
	
	for(i = 32; i < 39; i++) {
		item_switch[i] = BitTest(saveBuf[271], i - 32);
		if(item_switch[i] != 0) item_all[pl]++;
	}
	cpu_flag[pl] = saveBuf[272];
	cpu_level[pl] = saveBuf[273];
	vs_goal_level = saveBuf[274];
	vs_timelimit = saveBuf[275];
	vs_goal_type = saveBuf[276];
	flash_edit[pl] = saveBuf[277];
	
	if(repversw >= 4) {
		enable_combo = saveBuf[278];
		enable_irs = saveBuf[279];
	} else {
		enable_combo = 1;
		enable_irs = 1;
	}
	
	devil_doom_n_rise = saveBuf[280];
	
	smooth = saveBuf[290];
	nanameallow = saveBuf[291];
	sonicdrop = saveBuf[292];
	fastlrmove = saveBuf[293];
	
	timeattack[pl] = saveBuf[296];		// TIME TRIAL
	
	nextb_max[pl] = saveBuf[297];		// NEXTのループ間隔
	if(!nextb_max[pl]) nextb_max[pl] = 1400;
	
	ace_irs = saveBuf[298];				// IRSタイプ
	w_reverse = saveBuf[299];			// ワールド時回転方向逆転
	
	// アイテム出現率
	item_pronum = 0;
	for(i = 0; i < item_num; i++) {
		saveBuf[300 + i] = item_pro[i];
		item_pronum = item_pronum + item_pro[i];
	}
	
	// PRACTICEの設定
	if(gameMode[pl] == 5) {
		always_over1000[0] = saveBuf[350];
		hidden[0] = saveBuf[351];
		isfmirror[0] = saveBuf[352];
		isrollroll[0] = saveBuf[353];
		isxray[0] = saveBuf[354];
		iscolor[0] = saveBuf[355];
		isblind[0] = saveBuf[356];
		isthunder[0] = saveBuf[357];
		isUDLRreverse[0] = saveBuf[358];
		isRotateLock[0] = saveBuf[359];
		ishidenext[0] = saveBuf[360];
		hidden_old[0] = saveBuf[361];
		//item_mode[0] = saveBuf[362];
		if(repversw >= 4) shadowtime[0] = saveBuf[362];
		heboGB[0] = saveBuf[363];
		squaremode[0] = saveBuf[364];
		speedtype[0] = saveBuf[365];
		backno = saveBuf[366];
		p_leveltype = saveBuf[367];
		p_timelimit = saveBuf[368];
		p_goal = saveBuf[369];
		p_staffroll = saveBuf[370];
	}
	
	stage[pl] = start_stage[pl];
	nextc[pl] = start_nextc[pl];
	
	max = saveBuf[4] / 2 + 1;
	if(max > 60 * 60 * 20 / 2) max = 60 * 60 * 20 / 2;
	
	// 操作データ
	for(i = 0; i < max; i++) {
		if(!pl) {
			replayData[(i << 1)    ] =   saveBuf[i + 600] & 0xFFFF;
			replayData[(i << 1) + 1] = ( saveBuf[i + 600] & 0xFFFF0000 ) >> 16;
		} else {
			replayData2[(i << 1)    ] =   saveBuf[i + 600] & 0xFFFF;
			replayData2[(i << 1) + 1] = ( saveBuf[i + 600] & 0xFFFF0000 ) >> 16;
		}
	}
	
	return 0;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   リプレイデータが存在するかどうか調べる
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int checkReplayExist() {
	int i, temp, result;
	result = 0;
	
	for(i = 0; i < 41; i++) {
		FillMemory(&saveBuf, 50000 * 4, 0);
		
		if(i == 40) sprintf(string[0], "replay/LASTPLAY.SAV");
		else sprintf(string[0], "replay/REPLAY%02d.SAV", i + 1);
		LoadFile(string[0], &saveBuf, 500 * 4);
		
		temp = 1;
		
		if(saveBuf[0] != 0x4F424548) temp = 0;
		if(saveBuf[1] != 0x4554494C) temp = 0;
		if(saveBuf[2] != 0x4C504552) temp = 0;
		if(saveBuf[3] != 0x32765941) temp = 0;
		
		if(temp) {
			result++;
			enable[i] = 1;
			
			replay_gamemode[i] = saveBuf[201];	// モード
			replay_score[i]    = saveBuf[295];	// 段位／スコア／ステージ／ライン
			replay_time[i]     = saveBuf[200];	// タイム
			replay_level[i]    = saveBuf[203];	// レベル／クリア率
			replay_rots[i]     = saveBuf[294];	// ルール
			replay_tt[i]       = saveBuf[296];	// ゲームタイプ
			
			// その他の情報
			if((saveBuf[201] == 1) || (saveBuf[201] == 2)) {
				replay_other[i] = saveBuf[238];	// gradetype
			} else if(saveBuf[201] == 5) {
				replay_other[i] = saveBuf[367];	// p_leveltype
			} else {
				replay_other[i] = 0;
			}
		} else {
			enable[i] = 0;
			replay_gamemode[i] = 0;
			replay_score[i]    = 0;
			replay_time[i]     = 0;
			replay_level[i]    = 0;
			replay_rots[i]     = 0;
			replay_tt[i]       = 0;
		}
	}
	
	return result;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   リプレイ関連
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int ReplaySelectProc() {
	int player;
	
	// リプレイ選択画面表示前の準備
	ReplaySelectInitial();
	flag = 0;
	
	// リプレイ選択画面
	while(!flag) {
		count++;
		if(refresh_timing) spriteTime();
		KeyInput();
		ReplaySelect();
		if(!refresh_timing) spriteTime();
	}
	
	if(flag > 0) {
		// 再生開始
		demo = 0;
		playback = 1;
		replayauto = 1;
		replayno = flag;
		
		gameAllInit();
		
		loadReplayData(0, flag);
		
		// VERSUS用処理
		if(gameMode[0] == 4) {
			loadReplayData(1, flag);
			setVersusField();
		}
		
		hnext[0] = 0;
		hnext[1] = 0;
		
		for(player = 0; player <= (gameMode[0] == 4); player++) {
			next[player] = nextb[nextc[player] + player * 1400];
			setNextBlockColors(player, 1);
			
			hnext[player] = dispnext;
			
			setStartLevel(player);		// スピード設定
			setstartBGM(player);		// 開始BGM設定
			
			stat[player] = 3;			// Ready
		}
		
		// PRACTICE用処理
		if(gameMode[0] == 5) {
			PracticeStart();
		}
		
		// MISSION用処理
		if(gameMode[0] == 8) {
			// コースデータ読み込み
			loadMissionData(mission_file);
			viewMissionText();
			
			// 操作状況表示位置変更
			if(!mission_hide_info) {
				if(!maxPlay) coffset = s_m_coffset;
				else coffset = d_m_coffset;
			} else {
				setFieldPosition(maxPlay);
			}
		}
		
		return 2;
	} else {
		// キャンセル
		return 0;
	}
}

// リプレイ選択画面表示前の準備
void ReplaySelectInitial() {
	// 再生可能なリプレイの総数
	cnt = checkReplayExist();
	
	// カーソル位置
	csr = 0;
	
	// 初期カーソル位置設定
	if(cnt) {
		while(!enable[csr]) {
			csr++;
			if(csr >= 41) csr = 0;
		}
	}
}

// リプレイ選択画面
void ReplaySelect() {
	int i, j, color, start, end;
	
	padRepeat2(0);
	
	viewDarkTitle();
	
	printFont(9, 2, "- SELECT REPLAY DATA -", 4);
	printFont(6, 3, "PRESS C BUTTON TO VIEW DETAIL", 5);
	
	if(!cnt) {
		// リプレイデータがない
		printFont(13, 14, "NO REPLAY DATA", 2);
	} else {
		// リプレイ一覧の表示
		j = 0;
		if(csr >= 20) {
			start = 20;
			end = 41;
			printFont(8, 27, "PAGE 2 (NO.21 - NO.40)", 1);
		} else {
			start = 0;
			end = 20;
			printFont(8, 27, "PAGE 1 (NO.01 - NO.20)", 1);
		}
		
		for(i = start; i < end; i++) {
			// カーソル色設定
			color = (i == csr) * (count % 4 / 2) * fontc[replay_rots[i]];
			
			// ファイルナンバー
			if(i == 40) {
				printFont(1, 5 + j, "LP", color);
			} else {
				sprintf(string[0], "%02d", i + 1);
				printFont(1, 5 + j, string[0], color);
			}
			
			if(enable[i]) {
				if((replay_gamemode[i] >= 1) && (replay_gamemode[i] <= 2)) {
					// MASTER, 20G
					if(replay_other[i] == 2) getGradeString(replay_score[i], 3, 1);
					else getGradeString(replay_score[i], 0, 1);
					sprintf(string[0], "G:%s", string[1]);
					printFont(4, 5 + j, string[0], color);
				} else if(replay_gamemode[i] == 3) {
					// DEVIL-DOOM
					getGradeString(replay_score[i], 2, 1);
					sprintf(string[0], "G:%s", string[1]);
					printFont(4, 5 + j, string[0], color);
				} else if(replay_gamemode[i] == 16) {
					// DEVIL-HARD
					getGradeString(replay_score[i], 1, 1);
					sprintf(string[0], "G:%s", string[1]);
					printFont(4, 5 + j, string[0], color);
				} else if((replay_gamemode[i] == 5) && (replay_other[i] == 1)) {
					// PRACTICE (10 LINES)
					sprintf(string[0], "L:%d", replay_score[i]);
					printFont(4, 5 + j, string[0], color);
				} else if((replay_gamemode[i] ==  0) || (replay_gamemode[i] ==  5) || (replay_gamemode[i] ==  9) || 
				          (replay_gamemode[i] == 10) || (replay_gamemode[i] == 11) || (replay_gamemode[i] == 13) || 
				          (replay_gamemode[i] == 14) || (replay_gamemode[i] == 15) || 
				          ((replay_tt[i] != 0) && (replay_tt[i] != 2) && (replay_gamemode[i] == 17)) || 
				          (replay_gamemode[i] == 18))
				{
					// BEGINNER, PRACITCE, OLD STYLE, HEBO+, DEVIL-NORMAL, NOVICE, FINAL, FLASH, SIMPLE-ULTRA, MARATHON
					sprintf(string[0], "P:%d", replay_score[i]);
					printFont(4, 5 + j, string[0], color);
				} else if(replay_gamemode[i] == 4) {
					// VERSUS
					printFont(4, 5 + j, "VS MODE", color);
				} else if(replay_gamemode[i] == 6) {
					// TOMOYO
					printFont(4, 5 + j, "S:", color);
					getTomoyoStageNo(replay_score[i], 0, 0);
					printFont(6, 5 + j, string[0], color);
				} else if(replay_gamemode[i] == 8) {
					// MISSION
					sprintf(string[0], "M:%d", replay_score[i] + 1);
					printFont(4, 5 + j, string[0], color);
				} else {
					// ACEなど
					sprintf(string[0], "L:%d", replay_score[i]);
					printFont(4, 5 + j, string[0], color);
				}
				
				if(replay_gamemode[i] == 6) {
					// TOMOYOクリア率
					if(replay_score[i] <= 26) {
						sprintf(string[0], "%d%%", replay_level[i]);
						printFont(14, 5 + j, string[0], color);
					}
				} else if(replay_gamemode[i] == 15) {
					// FLASHのステージ
					sprintf(string[0], "S:%d", replay_level[i] + 1);
					printFont(14, 5 + j, string[0], color);
				} else {
					// レベル
					if((replay_gamemode[i] <=  3) || (replay_gamemode[i] ==  9) || (replay_gamemode[i] == 10) || 
					   (replay_gamemode[i] == 11) || (replay_gamemode[i] == 13) || (replay_gamemode[i] == 14) || 
					   (replay_gamemode[i] == 16) || 
					   ((replay_gamemode[i] == 5) && (replay_other[i] == 0)))
					{
						sprintf(string[0], "LV%d", replay_level[i]);
					}
					else if((replay_gamemode[i] == 4) || (replay_gamemode[i] == 8))
					{
						sprintf(string[0], "");
					}
					else if(replay_gamemode[i] == 17)
					{
						if((replay_tt[i] == 0) || (replay_tt[i] == 2)) sprintf(string[0], "40LINE");
						if((replay_tt[i] == 1) || (replay_tt[i] == 3)) sprintf(string[0], "ULTRA");
					}
					else
					{
						sprintf(string[0], "LV%d", replay_level[i] + 1);
					}
					
					printFont(14, 5 + j, string[0], color);
				}
				
				// タイム
				getTime(replay_time[i]);
				printFont(21, 5 + j, string[0], color);
				
				// モード
				getModeNameEx(replay_gamemode[i], 0);
				printFont(30, 5 + j, string[0], color);
			}
			
			j++;
		}
	}
	
	if(cnt != 0) {
		// ↑
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 0) ) {
			PlaySE(5);
			
			do {
				csr--;
				if(csr < 0) csr = 40;
			} while(!enable[csr]);
		}
		
		// ↓
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 1) ) {
			PlaySE(5);
			
			do {
				csr++;
				if(csr > 40) csr = 0;
			} while(!enable[csr]);
		}
	}
	
	// Bで戻る
	if(getPushState(0, 5)) {
		flag = -1;
		return;
	}
	
	// Cでリプレイ詳細
	if((getPushState(0, 6) != 0) && (cnt != 0)) {
		PlaySE(5);
		loadReplayData(0, csr + 1);
		
		// VERSUSの場合は2Pをリプレイを読み込み
		if(gameMode[0] == 4) {
			loadReplayData(1, csr + 1);
		}
		
		// ミッションモードの場合はコースデータを読み込み（コース名表示のため）
		if(gameMode[0] == 8) {
			loadMissionData(mission_file);
		}
		
		ReplayDetail();
	}
	
	// Aで決定
	if((getPushState(0, 4) != 0) && (cnt != 0)) {
		PlaySE(10);
		flag = csr + 1;
		return;
	}
}

// リプレイ詳細画面
void ReplayDetail() {
	int page;
	page = 0;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		sprintf(string[0], "REPLAY DETAIL (PAGE %d)", page + 1);
		printFont(1, 1, string[0], 4);
		
		printFont(1, 27, "kn: PAGE CHANGE / A: PLAY / B: CANCEL", 7);
		
		if(!page) {
			printFont(1, 3, "REPLAY NUMBER  : ", 0);
			if(csr == 40) {
				printFont(18, 3, "LAST PLAY", 0);
			} else {
				sprintf(string[0], "%02d", csr + 1);
				printFont(18, 3, string[0], 0);
			}
			
			sprintf(string[0], "VERSION        : %d", repversw);
			printFont(1, 4, string[0], 0);
			
			printFont(1, 5, "MODE           :", 0);
			getModeName(0);
			printFont(18, 5, string[0], modecolor[gameMode[0]]);
			
			// MASTER / 20G
			if((gameMode[0] == 1) || (gameMode[0] == 2)) {
				// ルール
				printFont(1, 6, "RULE           :", 0);
				getRuleName(0);
				printFont(18, 6, string[0], fontc[rots[0]]);
				
				// 難易度
				printFont(1, 8, "DIFFICULTY     :", 0);
				if(gradetype[0] == 0) printFont(18, 8, "NORMAL", 1);
				if(gradetype[0] == 1) printFont(18, 8, "HARD", 2);
				if(gradetype[0] == 2) printFont(18, 8, "EASY", 4);
				
				// スコア類
				printFont(1, 9, "GRADE          :", 0);
				if(gradetype[0] == 2) getGradeString(saveBuf[295], 3, 0);
				else getGradeString(saveBuf[295], 0, 0);
				printFont(18, 9, string[0], 0);
				
				sprintf(string[0], "LEVEL          : %d", saveBuf[203]);
				printFont(1, 10, string[0], 0);
				
				printFont(1, 11, "TIME           :", 0);
				getTime(saveBuf[200]);
				printFont(18, 11, string[0], 0);
				
				// 設定
				printFont(1, 13, "ENDLESS MODE   :", 0);
				if(!timeattack[0]) printFont(18, 13, "ON", 0);
				else printFont(18, 13, "OFF", 0);
				
				printFont(1, 14, "BIG MODE       :", 0);
				if(!IsBigStart[0]) printFont(18, 14, "OFF", 0);
				else printFont(18, 14, "ON", 0);
				
				printFont(1, 15, "ITEM MODE      :", 0);
				if(!item_mode[0]) printFont(18, 15, "OFF", 0);
				else printFont(18, 15, "ON", 0);
			}
			// DEVIL-DOOM / DEVIL-HARD
			else if((gameMode[0] == 3) || (gameMode[0] == 16)) {
				// ルール
				printFont(1, 6, "RULE           :", 0);
				getRuleName(0);
				printFont(18, 6, string[0], fontc[rots[0]]);
				
				// スコア類
				printFont(1, 8, "GRADE          :", 0);
				if(gameMode[0] == 16) getGradeString(saveBuf[295], 1, 0);
				else getGradeString(saveBuf[295], 2, 0);
				printFont(18, 8, string[0], 0);
				
				sprintf(string[0], "LEVEL          : %d", saveBuf[203]);
				printFont(1, 9, string[0], 0);
				
				printFont(1, 10, "TIME           :", 0);
				getTime(saveBuf[200]);
				printFont(18, 10, string[0], 0);
				
				// 設定
				printFont(1, 12, "ENDLESS MODE   :", 0);
				if(!timeattack[0]) printFont(18, 12, "ON", 0);
				else printFont(18, 12, "OFF", 0);
				
				printFont(1, 13, "BIG MODE       :", 0);
				if(!IsBigStart[0]) printFont(18, 13, "OFF", 0);
				else printFont(18, 13, "ON", 0);
				
				printFont(1, 14, "ITEM MODE      :", 0);
				if(!item_mode[0]) printFont(18, 14, "OFF", 0);
				else printFont(18, 14, "ON", 0);
			}
			// VERSUS
			else if(gameMode[0] == 4) {
				printFont(1, 6, "TIME           :", 0);
				getTime(saveBuf[200]);
				printFont(18, 6, string[0], 0);
				
				printFont(1, 7, "1P RULE        :", 0);
				getRuleName(0);
				printFont(18, 7, string[0], fontc[rots[0]]);
				
				printFont(1, 8, "2P RULE        :", 0);
				getRuleName(1);
				printFont(18, 8, string[0], fontc[rots[1]]);
				
				printFont(1, 9, "1P CPU PLAYER  :", 0);
				if(!cpu_flag[0]) sprintf(string[0], "OFF");
				else sprintf(string[0], "LEVEL %d", cpu_level[0] + 1);
				printFont(18, 9, string[0], 0);
				
				printFont(1, 10, "2P CPU PLAYER  :", 0);
				if(!cpu_flag[1]) sprintf(string[0], "OFF");
				else sprintf(string[0], "LEVEL %d", cpu_level[1] + 1);
				printFont(18, 10, string[0], 0);
				
				printFont(1, 12, "GOAL TYPE      :", 0);
				if(vs_goal_type == 0) sprintf(string[0], "LEVEL");
				else if(vs_goal_type == 1) sprintf(string[0], "LINE");
				else sprintf(string[0], "MARATHON");
				printFont(18, 12, string[0], 0);
				
				printFont(1, 13, "GOAL LEVEL     :", 0);
				if(vs_goal_level == 0) sprintf(string[0], "NONE");
				else if(vs_goal_type == 0) sprintf(string[0], "LEVEL %d", vs_goal_level * 100);
				else if(vs_goal_type == 1) sprintf(string[0], "%d LINES", vs_goal_level * 10);
				else sprintf(string[0], "%d POINTS", vs_goal_level * 5);
				printFont(18, 13, string[0], 0);
				
				printFont(1, 14, "TIME LIMIT     :", 0);
				if(!vs_timelimit) sprintf(string[0], "NONE");
				else getTimeEx(vs_timelimit, 0, 0);
				printFont(18, 14, string[0], 0);
				
				printFont(1, 15, "ITEM MODE      :", 0);
				if(!item_mode[0]) printFont(18, 15, "OFF", 0);
				else printFont(18, 15, "ON", 0);
				
				printFont(1, 16, "RISE MODE      :", 0);
				if(!r_enable[0]) printFont(18, 16, "OFF", 0);
				else printFont(18, 16, "ON", 0);
				
				// 速度設定
				sprintf(string[0], "%s       : 1P:%4d 2P:%4d", delayname[0 + english * 4], wait1[0], wait1[1]);
				printFont(1, 18, string[0], 0);
				sprintf(string[0], "%s       : 1P:%4d 2P:%4d", delayname[1 + english * 4], wait2[0], wait2[1]);
				printFont(1, 19, string[0], 0);
				sprintf(string[0], "%s       : 1P:%4d 2P:%4d", delayname[2 + english * 4], wait3[0], wait3[1]);
				printFont(1, 20, string[0], 0);
				sprintf(string[0], "%s       : 1P:%4d 2P:%4d", delayname[3 + english * 4], waitt[0], waitt[1]);
				printFont(1, 21, string[0], 0);
				sprintf(string[0], "SPEED          : 1P:%4d 2P:%4d", sp[0], sp[1]);
				printFont(1, 22, string[0], 0);
			}
			// PRACTICE
			else if(gameMode[0] == 5) {
				// ルール
				printFont(1, 6, "RULE           :", 0);
				getRuleName(0);
				printFont(18, 6, string[0], fontc[rots[0]]);
				
				// レベルタイプ
				printFont(1, 7, "LEVEL TYPE     :", 0);
				if(p_leveltype == 0) sprintf(string[0], "NORMAL");
				else if(p_leveltype == 1) sprintf(string[0], "10 LINES");
				else sprintf(string[0], "MARATHON");
				printFont(18, 7, string[0], 0);
				
				// ゴール
				printFont(1, 8, "GOAL LEVEL     :", 0);
				if(!p_goal) {
					sprintf(string[0], "ENDLESS");
				} else {
					if(p_leveltype == 0) sprintf(string[0], "LEVEL %d", p_goal * 100);
					if(p_leveltype == 1) sprintf(string[0], "%d LINES", p_goal * 10);
					if(p_leveltype == 2) sprintf(string[0], "LEVEL %d", p_goal);
				}
				printFont(18, 8, string[0], 0);
				
				// スタッフロールの有無
				printFont(1, 9, "STAFF ROLL     :", 0);
				if(p_staffroll == 0) sprintf(string[0], "OFF");
				if(p_staffroll == 1) sprintf(string[0], "ON");
				if(p_staffroll == 2) sprintf(string[0], "FAST ROLL");
				printFont(18, 9, string[0], 0);
				
				// 制限時間
				printFont(1, 10, "TIME LIMIT     :", 0);
				if(!p_timelimit) sprintf(string[0], "NONE");
				else getTimeEx(p_timelimit, 0, 0);
				printFont(18, 10, string[0], 0);
				
				// ビッグ
				printFont(1, 11, "BIG MODE       :", 0);
				if(!IsBigStart[0]) printFont(18, 11, "OFF", 0);
				else printFont(18, 11, "ON", 0);
				
				// アイテム
				printFont(1, 12, "ITEM MODE      :", 0);
				if(!item_mode[0]) printFont(18, 12, "OFF", 0);
				else printFont(18, 12, "ON", 0);
				
				// スコア類
				if(p_leveltype != 1) {
					sprintf(string[0], "SCORE          : %d", saveBuf[295]);
				} else {
					sprintf(string[0], "LINES          : %d", saveBuf[295]);
				}
				printFont(1, 14, string[0], 0);
				
				if(p_leveltype == 0) {
					sprintf(string[0], "LEVEL          : %d", saveBuf[203]);
				} else {
					sprintf(string[0], "LEVEL          : %d", saveBuf[203] + 1);
				}
				printFont(1, 15, string[0], 0);
				
				printFont(1, 16, "TIME           :", 0);
				getTime(saveBuf[200]);
				printFont(18, 16, string[0], 0);
				
				// 速度設定
				sprintf(string[0], "%s       : %d", delayname[0 + english * 4], wait1[0]);
				printFont(1, 18, string[0], 0);
				sprintf(string[0], "%s       : %d", delayname[1 + english * 4], wait2[0]);
				printFont(1, 19, string[0], 0);
				sprintf(string[0], "%s       : %d", delayname[2 + english * 4], wait3[0]);
				printFont(1, 20, string[0], 0);
				sprintf(string[0], "%s       : %d", delayname[3 + english * 4], waitt[0]);
				printFont(1, 21, string[0], 0);
				sprintf(string[0], "SPEED          : %d", sp[0]);
				printFont(1, 22, string[0], 0);
				sprintf(string[0], "BGM            : %d", start_bgmlv[0] + 1);
				printFont(1, 23, string[0], 0);
			}
			// TOMOYO
			else if(gameMode[0] == 6) {
				// ルール
				printFont(1, 6, "RULE           :", 0);
				getRuleName(0);
				printFont(18, 6, string[0], fontc[rots[0]]);
				
				// コース
				printFont(1, 8, "COURSE         :", 0);
				if(start_stage[0] == 0) {
					printFont(18, 8, "NORMAL", 1);
				} else if(start_stage[0] == 27) {
					printFont(18, 8, "EHEART", 3);
				} else if(start_stage[0] == 45) {
					printFont(18, 8, "TARGET", 0);
				} else if(start_stage[0] == 72) {
					printFont(18, 8, "EDIT", 4);
				} else {
					sprintf(string[0], "SELECT %d", start_stage[0] + 1);
					printFont(18, 8, string[0], 5);
				}
				
				// ステージ
				printFont(1, 9, "STAGE          :", 0);
				getTomoyoStageNo(saveBuf[295], 0, 0);
				printFont(18, 9, string[0], 0);
				
				// クリア率
				if(start_stage[0] <= 26) {
					sprintf(string[0], "CLEAR          : %d%%", saveBuf[203]);
					printFont(1, 10, string[0], 0);
				}
				
				// ランダムモード
				printFont(1, 11, "RANDOM MODE    :", 0);
				if(!timeattack[0]) printFont(18, 11, "OFF", 0);
				else printFont(18, 11, "ON", 0);
				
				// タイム
				printFont(1, 12, "TIME           :", 0);
				getTime(saveBuf[200]);
				printFont(18, 12, string[0], 0);
			}
			// ACE
			else if((gameMode[0] == 7) || (gameMode[0] == 12)) {
				// ルール
				printFont(1, 6, "RULE           :", 0);
				getRuleName(0);
				printFont(18, 6, string[0], fontc[rots[0]]);
				
				// 難易度
				printFont(1, 8, "DIFFICULTY     :", 0);
				if(gameMode[0] == 7) {
					if(timeattack[0] == 0) printFont(18, 8, "NORMAL", 1);
					if(timeattack[0] == 1) printFont(18, 8, "HI-SPEED 1", 5);
					if(timeattack[0] == 2) printFont(18, 8, "HI-SPEED 2", 7);
					if(timeattack[0] == 3) printFont(18, 8, "ANOTHER", 2);
					if(timeattack[0] == 4) printFont(18, 8, "ANOTHER2", 3);
				} else {
					if(timeattack[0] == 0) printFont(18, 8, "BASIC", 6);
					if(timeattack[0] == 1) printFont(18, 8, "HELL", 2);
					if(timeattack[0] == 2) printFont(18, 8, "HELL-X", 3);
					if(timeattack[0] == 3) printFont(18, 8, "VOID", 0);
				}
				
				// ライン
				sprintf(string[0], "LINES          : %d", saveBuf[295]);
				printFont(1, 9, string[0], 0);
				
				// レベル
				sprintf(string[0], "LEVEL          : %d", saveBuf[203] + 1);
				printFont(1, 10, string[0], 0);
				
				// タイム
				printFont(1, 11, "TIME           :", 0);
				getTime(saveBuf[200]);
				printFont(18, 11, string[0], 0);
				
				// 設定
				printFont(1, 13, "BIG MODE       :", 0);
				if(!IsBigStart[0]) printFont(18, 13, "OFF", 0);
				else printFont(18, 13, "ON", 0);
				
				printFont(1, 14, "ITEM MODE      :", 0);
				if(!item_mode[0]) printFont(18, 14, "OFF", 0);
				else printFont(18, 14, "ON", 0);
			}
			// MISSION
			else if(gameMode[0] == 8) {
				// ルール
				printFont(1, 6, "RULE           :", 0);
				getRuleName(0);
				printFont(18, 6, string[0], fontc[rots[0]]);
				
				// コース
				printFont(1, 8, "COURSE         :", 0);
				if(StrLen(mission_course_name) > 0) {
					printFont(18, 8, mission_course_name, 0);
				} else {
					sprintf(string[0], "EDIT %d", mission_file + 1);
					printFont(18, 8, string[0], 0);
				}
				
				// スタート地点
				sprintf(string[0], "START MISSION  : %d", start_mission + 1);
				printFont(1, 9, string[0], 0);
				
				// 終了地点
				sprintf(string[0], "LAST MISSION   : %d", replay_score[csr] + 1);
				printFont(1, 10, string[0], 0);
			}
			// OLD STYLE
			else if(gameMode[0] == 9) {
				// ルール
				printFont(1, 6, "RULE           :", 0);
				getRuleName(0);
				printFont(18, 6, string[0], fontc[rots[0]]);
				
				// ゲームタイプ
				printFont(1, 8, "GAME TYPE      :", 0);
				if(!timeattack[0]) printFont(18, 8, "HANDHELD", 0);
				else printFont(18, 8, "ARCADE", 0);
				
				// スコア類
				sprintf(string[0], "SCORE          : %d", saveBuf[295]);
				printFont(1, 9, string[0], 0);
				
				sprintf(string[0], "LEVEL          : %d", saveBuf[203]);
				printFont(1, 10, string[0], 0);
				
				printFont(1, 11, "TIME           :", 0);
				getTime(saveBuf[200]);
				printFont(18, 11, string[0], 0);
			}
			// FLASH
			else if(gameMode[0] == 15) {
				// ルール
				printFont(1, 6, "RULE           :", 0);
				getRuleName(0);
				printFont(18, 6, string[0], fontc[rots[0]]);
				
				// タイムリミット
				printFont(1, 8, "TIME LIMIT     :", 0);
				if(!timeattack[0]) printFont(18, 8, "OFF", 0);
				else printFont(18, 8, "ON", 0);
				
				// エディット面
				printFont(1, 9, "EDIT STAGE     :", 0);
				if(!flash_edit[0]) printFont(18, 9, "OFF", 0);
				else printFont(18, 9, "ON", 0);
				
				// スコア
				sprintf(string[0], "SCORE          : %d", saveBuf[295]);
				printFont(1, 11, string[0], 0);
				
				// ステージ
				sprintf(string[0], "STAGE          : %d", saveBuf[203] + 1);
				printFont(1, 12, string[0], 0);
			}
			// SIMPLE
			else if(gameMode[0] == 17) {
				// ルール
				printFont(1, 6, "RULE           :", 0);
				getRuleName(0);
				printFont(18, 6, string[0], fontc[rots[0]]);
				
				// ゲームタイプ
				printFont(1, 8, "GAME TYPE      :", 0);
				if(timeattack[0] == 0) printFont(18, 8, "40LINES", 2);
				if(timeattack[0] == 1) printFont(18, 8, "ULTRA", 1);
				if(timeattack[0] == 2) printFont(18, 8, "40LINES ROT. RELAY", 3);
				if(timeattack[0] == 3) printFont(18, 8, "ULTRA ROT. RELAY", 6);
				
				// スコア／ライン
				if((timeattack[0] == 0) || (timeattack[0] == 2)) {
					sprintf(string[0], "LINES          : %d", saveBuf[295]);
				} else {
					sprintf(string[0], "SCORE          : %d", saveBuf[295]);
				}
				printFont(1, 9, string[0], 0);
				
				// タイム
				printFont(1, 10, "TIME           :", 0);
				getTime(saveBuf[200]);
				printFont(18, 10, string[0], 0);
				
				// ビッグ
				printFont(1, 12, "BIG MODE       :", 0);
				if(!IsBigStart[0]) printFont(18, 12, "OFF", 0);
				else printFont(18, 12, "ON", 0);
				
				// アイテム
				printFont(1, 13, "ITEM MODE      :", 0);
				if(!item_mode[0]) printFont(18, 13, "OFF", 0);
				else printFont(18, 13, "ON", 0);
				
				// 速度設定
				sprintf(string[0], "%s       : %d", delayname[0 + english * 4], wait1[0]);
				printFont(1, 15, string[0], 0);
				sprintf(string[0], "%s       : %d", delayname[1 + english * 4], wait2[0]);
				printFont(1, 16, string[0], 0);
				sprintf(string[0], "%s       : %d", delayname[2 + english * 4], wait3[0]);
				printFont(1, 17, string[0], 0);
				sprintf(string[0], "%s       : %d", delayname[3 + english * 4], waitt[0]);
				printFont(1, 18, string[0], 0);
				sprintf(string[0], "SPEED          : %d", sp[0]);
				printFont(1, 19, string[0], 0);
				sprintf(string[0], "BGM            : %d", start_bgmlv[0] + 1);
				printFont(1, 20, string[0], 0);
			}
			// MARATHON
			else if(gameMode[0] == 18) {
				// ルール
				printFont(1, 6, "RULE           :", 0);
				getRuleName(0);
				printFont(18, 6, string[0], fontc[rots[0]]);
				
				// ゲームタイプ
				printFont(1, 8, "GAME TYPE      :", 0);
				if(timeattack[0] == 0) printFont(18, 8, "NORMAL", 1);
				if(timeattack[0] == 1) printFont(18, 8, "SQUARE", 5);
				if(timeattack[0] == 2) printFont(18, 8, "ONI", 2);
				
				// スコア
				sprintf(string[0], "SCORE          : %d", saveBuf[295]);
				printFont(1, 9, string[0], 0);
				
				// レベル
				sprintf(string[0], "LEVEL          : %d", saveBuf[203]);
				printFont(1, 10, string[0], 0);
				
				// タイム
				printFont(1, 11, "TIME           :", 0);
				getTime(saveBuf[200]);
				printFont(18, 11, string[0], 0);
				
				// 設定
				printFont(1, 13, "BIG MODE       :", 0);
				if(!IsBigStart[0]) printFont(18, 13, "OFF", 0);
				else printFont(18, 13, "ON", 0);
				
				printFont(1, 14, "ITEM MODE      :", 0);
				if(!item_mode[0]) printFont(18, 14, "OFF", 0);
				else printFont(18, 14, "ON", 0);
			}
			// その他
			else {
				// ルール
				printFont(1, 6, "RULE           :", 0);
				getRuleName(0);
				printFont(18, 6, string[0], fontc[rots[0]]);
				
				// スコア類
				sprintf(string[0], "SCORE          : %d", saveBuf[295]);
				printFont(1, 8, string[0], 0);
				
				sprintf(string[0], "LEVEL          : %d", saveBuf[203]);
				printFont(1, 9, string[0], 0);
				
				printFont(1, 10, "TIME           :", 0);
				getTime(saveBuf[200]);
				printFont(18, 10, string[0], 0);
				
				printFont(1, 12, "ENDLESS MODE   :", 0);
				if(!timeattack[0]) printFont(18, 12, "ON", 0);
				else printFont(18, 12, "OFF", 0);
				
				printFont(1, 13, "BIG MODE       :", 0);
				if(!IsBigStart[0]) printFont(18, 13, "OFF", 0);
				else printFont(18, 13, "ON", 0);
				
				printFont(1, 14, "ITEM MODE      :", 0);
				if(!item_mode[0]) printFont(18, 14, "OFF", 0);
				else printFont(18, 14, "ON", 0);
			}
		} else {
			printFont(1, 3, "8WAY INPUT     :", 0);
			if(nanameallow == 0) sprintf(string[0], "ON");
			else sprintf(string[0], "OFF");
			printFont(18, 3, string[0], 0);
			
			printFont(1, 4, "SONIC DROP     :", 0);
			if(sonicdrop == 0) sprintf(string[0], "ON");
			else sprintf(string[0], "OFF");
			printFont(18, 4, string[0], 0);
			
			printFont(1, 5, "INIT LR MOVE   :", 0);
			if(fastlrmove == 0) sprintf(string[0], "ON");
			if(fastlrmove == 1) sprintf(string[0], "OFF");
			if(fastlrmove == 2) sprintf(string[0], "SUPER");
			if(fastlrmove == 3) sprintf(string[0], "HYPER");
			printFont(18, 5, string[0], 0);
			
			printFont(1, 6, "LVUP BONUS     :", 0);
			if(lvupbonus == 0) sprintf(string[0], "ON");
			else sprintf(string[0], "OFF");
			printFont(18, 6, string[0], 0);
			
			printFont(1, 7, "SPAWN Y TYPE   :", 0);
			if(spawn_y_type == 0) sprintf(string[0], "UNDER THE FRAME");
			else sprintf(string[0], "ABOVE THE FRAME");
			printFont(18, 7, string[0], 0);
			
			printFont(1, 8, "T-SPIN         :", 0);
			if(tspin_type == 0) sprintf(string[0], "OFF");
			if(tspin_type == 1) sprintf(string[0], "LINE CLEAR");
			if(tspin_type == 2) sprintf(string[0], "IMMOBILE");
			if(tspin_type == 3) sprintf(string[0], "3-CORNER");
			if(tspin_type == 4) sprintf(string[0], "3-CORNER NO KICK");
			printFont(18, 8, string[0], 0);
			
			printFont(1, 9, "180 ROTATION   :", 0);
			if(rot180 == 0) sprintf(string[0], "OFF");
			if(rot180 == 1) sprintf(string[0], "ON");
			if(rot180 == 2) sprintf(string[0], "ONLY SP RULE");
			printFont(18, 9, string[0], 0);
			
			printFont(1, 10, "B-T-B BONUS    :", 0);
			if(bonus_btb == 0) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 10, string[0], 0);
			
			printFont(1, 11, "SKIP LOCKFLASH :", 0);
			if(skip_blocklockflash == 0) sprintf(string[0], "OFF");
			if(skip_blocklockflash == 1) sprintf(string[0], "ON");
			if(skip_blocklockflash == 2) sprintf(string[0], "SUPER");
			if(skip_blocklockflash == 3) sprintf(string[0], "ARCADE");
			printFont(18, 11, string[0], 0);
			
			printFont(1, 12, "DRS FLOOR KICK :", 0);
			if(drs_floorkick == 0) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 12, string[0], 0);
		}
		
		// ページ切り替え
		if(getPushState(0, 0) || getPushState(0, 1)) {
			PlaySE(5);
			page = !page;
		}
		
		// AかBで戻る
		if(getPushState(0, 4) || getPushState(0, 5)) {
			return;
		}
		
		if(!refresh_timing) spriteTime();
	}
}
