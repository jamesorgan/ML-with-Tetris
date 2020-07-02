// 設定を保存
void config_save() {
	int i;
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x4554494C;
	saveBuf[2] = 0x464E4F43;
	saveBuf[3] = 0x32764749;
	
	// キーコンフィグ系設定
	for(i = 0; i < 20; i++) {
		saveBuf[4 + i] = keyAssign[i];
		saveBuf[24 + i] = joykeyAssign[i];
	}
	saveBuf[44] = pause_key[0];
	saveBuf[45] = pause_key[1];
	saveBuf[46] = hnext_key[0];
	saveBuf[47] = hnext_key[1];
	saveBuf[48] = giveup_key;
	saveBuf[49] = ss_key;
	
	// その他設定
	saveBuf[50] = maxPlay;
	saveBuf[51] = w_reverse;
	saveBuf[52] = r_irs;
	saveBuf[53] = downtype;
	saveBuf[54] = beginner_effect;
	saveBuf[55] = nextblock;
	saveBuf[56] = nanameallow;
	saveBuf[57] = sonicdrop;
	saveBuf[58] = fastlrmove;
	saveBuf[59] = lvupbonus;
	saveBuf[60] = main_fps;
	saveBuf[61] = fldtr;
	saveBuf[62] = breakeffect;
	saveBuf[63] = breakgraphics;
	saveBuf[64] = dispnext;
	saveBuf[65] = rule_name;
	saveBuf[66] = show_fps;
	saveBuf[67] = showctrl;
	saveBuf[68] = skip_viewbg;
	saveBuf[69] = tls_view;
	saveBuf[70] = bgm;
	saveBuf[71] = se;
	saveBuf[72] = bgmvolume;
	saveBuf[73] = sevolume;
	saveBuf[74] = rotate_sound;
	saveBuf[75] = move_sound;
	saveBuf[76] = joy_pause_key[0];
	saveBuf[77] = joy_pause_key[1];
	saveBuf[78] = joy_hnext_key[0];
	saveBuf[79] = joy_hnext_key[1];
	saveBuf[80] = joy_giveup_key[0];
	saveBuf[81] = joy_giveup_key[1];
	saveBuf[82] = joy_ss_key[0];
	saveBuf[83] = joy_ss_key[1];
	saveBuf[84] = spawn_y_type;
	saveBuf[85] = top_frame;
	saveBuf[86] = rots[0];
	saveBuf[87] = rots[1];
	saveBuf[88] = empty_spin_field;
	saveBuf[89] = tspin_type;
	saveBuf[90] = world_move_sound;
	saveBuf[91] = breakmax;
	saveBuf[92] = show_gpoint;
	saveBuf[93] = w_lockdown;
	saveBuf[94] = blockflash;
	saveBuf[95] = fldbgtype;
	saveBuf[96] = wsoftlock;
	saveBuf[97] = rot180;
	saveBuf[98] = english;
	saveBuf[99] = skip_key[0];
	saveBuf[100] = skip_key[1];
	saveBuf[101] = joy_skip_key[0];
	saveBuf[102] = joy_skip_key[1];
	saveBuf[103] = enable_b_to_b;
	saveBuf[104] = enable_minspeed;
	saveBuf[105] = disable_hold;
	saveBuf[106] = bonus_tspin;
	saveBuf[107] = bonus_btb;
	saveBuf[108] = ace_irs;
	saveBuf[109] = hide_score;
	saveBuf[110] = hide_grade;
	saveBuf[111] = rule_rot[9];
	saveBuf[112] = rule_hard_lock[9];
	saveBuf[113] = rule_soft_lock[9];
	saveBuf[114] = rule_soft_speed[9];
	saveBuf[115] = rule_are[9];
	saveBuf[116] = rule_color[9];
	saveBuf[117] = rule_lock_reset[9];
	saveBuf[118] = rule_lock_sound[9];
	saveBuf[119] = rule_ars_extrot[9];
	saveBuf[120] = rule_lock_limit[9];
	saveBuf[121] = rule_graphics[9];
	
	// フォントカラー設定（122～141）
	for(i = 0; i < 10; i++) {
		saveBuf[122 + i] = fontc[i];
		saveBuf[132 + i] = digitc[i];
	}
	
	saveBuf[142] = enable_bgfade;
	saveBuf[143] = skip_blocklockflash;
	saveBuf[144] = drs_floorkick;
	saveBuf[145] = rule_rot_limit[9];
	saveBuf[146] = tomoyo_clear_erase;
	saveBuf[147] = rule_180rot[9];
	saveBuf[148] = show_endmenu;
	saveBuf[149] = sound_ending_loop;
	saveBuf[150] = sound_beginner_ending_loop;
	saveBuf[151] = enable_item_hold;
	
	// アイテムスイッチ
	for(i = 0; i < 32; i++) saveBuf[152] = BitSet(saveBuf[152], i, item_switch[i]);
	
	saveBuf[153] = enable_ff_rerise;
	saveBuf[154] = vs_goal_level;
	saveBuf[155] = vs_timelimit;
	saveBuf[156] = vs_item;
	saveBuf[157] = vs_rise;
	saveBuf[158] = item_gauge_uptype;
	saveBuf[159] = item_interval;
	saveBuf[160] = enable_navigation;
	saveBuf[161] = limit_navigation;
	saveBuf[162] = limit_time_navigation;
	saveBuf[163] = show_rise_num;
	saveBuf[164] = lackblock_grayout;
	saveBuf[165] = rule_max_waitt[9];
	saveBuf[166] = hold_sound;
	saveBuf[167] = pause_visible;
	saveBuf[168] = p_def_setting;
	saveBuf[169] = p_backno;
	saveBuf[170] = nextskip;
	saveBuf[171] = p_def_leveltype;
	saveBuf[172] = p_def_timelimit;
	saveBuf[173] = p_def_goal;
	saveBuf[174] = p_def_staffroll;
	saveBuf[175] = cpu_enable_setting[0];
	saveBuf[176] = cpu_enable_setting[1];
	saveBuf[177] = cpu_default_level[0];
	saveBuf[178] = cpu_default_level[1];
	saveBuf[179] = enable_disp_lastline;
	saveBuf[180] = lastmode[0];
	saveBuf[181] = lastmode[1];
	saveBuf[182] = lasttype[0];
	saveBuf[183] = lasttype[1];
	saveBuf[184] = holdframetype;
	saveBuf[185] = vs_goal_type;
	saveBuf[186] = rule_oblk_bg[9];
	saveBuf[187] = show_section_time;
	saveBuf[188] = joykeyButtonNum;
	
	// アイテムスイッチ２
	for(i = 32; i < 39; i++) saveBuf[189] = BitSet(saveBuf[189], i, item_switch[i]);
	
	// アイテム出現率（190～239）
	for(i = 0; i < 50; i++) saveBuf[190 + i] = item_pro[i];
	
	saveBuf[240] = timer_font_type;
	saveBuf[241] = block_shadow;
	saveBuf[242] = block_afterimage;
	saveBuf[243] = ace_frame;
	saveBuf[244] = enable_combo;
	saveBuf[245] = display_combo;
	saveBuf[246] = enable_irs;
	saveBuf[247] = background_compatibility;
	saveBuf[248] = fadesetting;
	saveBuf[249] = disp_waits;
	saveBuf[250] = fps_plus_key;
	saveBuf[251] = fps_minus_key;
	saveBuf[252] = joy_fps_plus_key[0];
	saveBuf[253] = joy_fps_plus_key[1];
	saveBuf[254] = joy_fps_minus_key[0];
	saveBuf[255] = joy_fps_minus_key[1];
	saveBuf[256] = replay_autosave;
	saveBuf[257] = d_disp_lineinfo;
	saveBuf[258] = refresh_timing;
	saveBuf[259] = beffect_speed;
	saveBuf[260] = hidden_b_type;
	
	// 保存
	SaveFile("CONFIG.SAV", &saveBuf, 500 * 4);
}

// 設定を読み込み
int config_load() {
	int i;
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	LoadFile("CONFIG.SAV", &saveBuf, 4 * 4);
	
	// ヘッダが違う
	if(saveBuf[0] != 0x4F424548) return -1;
	if(saveBuf[1] != 0x4554494C) return -1;
	if(saveBuf[2] != 0x464E4F43) return -1;
	if(saveBuf[3] != 0x32764749) return -1;
	
	// 読み込み
	LoadFile("CONFIG.SAV", &saveBuf, 500 * 4);
	
	// キーコンフィグ系設定
	for(i = 0; i < 20; i++) {
		keyAssign[i] = saveBuf[4 + i];
		joykeyAssign[i] = saveBuf[24 + i];
	}
	pause_key[0] = saveBuf[44];
	pause_key[1] = saveBuf[45];
	hnext_key[0] = saveBuf[46];
	hnext_key[1] = saveBuf[47];
	giveup_key = saveBuf[48];
	ss_key = saveBuf[49];
	
	// その他設定
	maxPlay = saveBuf[50];
	b_maxPlay = maxPlay;
	
	w_reverse = saveBuf[51];
	r_irs = saveBuf[52];
	downtype = saveBuf[53];
	beginner_effect = saveBuf[54];
	nextblock = saveBuf[55];
	nanameallow = saveBuf[56];
	sonicdrop = saveBuf[57];
	fastlrmove = saveBuf[58];
	lvupbonus = saveBuf[59];
	main_fps = saveBuf[60];
	fldtr = saveBuf[61];
	breakeffect = saveBuf[62];
	breakgraphics = saveBuf[63];
	dispnext = saveBuf[64];
	rule_name = saveBuf[65];
	show_fps = saveBuf[66];
	showctrl = saveBuf[67];
	skip_viewbg = saveBuf[68];
	tls_view = saveBuf[69];
	bgm = saveBuf[70];
	se = saveBuf[71];
	bgmvolume = saveBuf[72];
	sevolume = saveBuf[73];
	rotate_sound = saveBuf[74];
	move_sound = saveBuf[75];
	joy_pause_key[0] = saveBuf[76];
	joy_pause_key[1] = saveBuf[77];
	joy_hnext_key[0] = saveBuf[78];
	joy_hnext_key[1] = saveBuf[79];
	joy_giveup_key[0] = saveBuf[80];
	joy_giveup_key[1] = saveBuf[81];
	joy_ss_key[0] = saveBuf[82];
	joy_ss_key[1] = saveBuf[83];
	spawn_y_type = saveBuf[84];
	top_frame = saveBuf[85];
	rots[0] = saveBuf[86];
	rots[1] = saveBuf[87];
	empty_spin_field = saveBuf[88];
	tspin_type = saveBuf[89];
	world_move_sound = saveBuf[90];
	breakmax = saveBuf[91];
	show_gpoint = saveBuf[92];
	w_lockdown = saveBuf[93];
	blockflash = saveBuf[94];
	fldbgtype = saveBuf[95];
	wsoftlock = saveBuf[96];
	rot180 = saveBuf[97];
	english = saveBuf[98];
	skip_key[0] = saveBuf[99];
	skip_key[1] = saveBuf[100];
	joy_skip_key[0] = saveBuf[101];
	joy_skip_key[1] = saveBuf[102];
	enable_b_to_b = saveBuf[103];
	enable_minspeed = saveBuf[104];
	disable_hold = saveBuf[105];
	bonus_tspin = saveBuf[106];
	bonus_btb = saveBuf[107];
	ace_irs = saveBuf[108];
	hide_score = saveBuf[109];
	hide_grade = saveBuf[110];
	rule_rot[9] = saveBuf[111];
	rule_hard_lock[9] = saveBuf[112];
	rule_soft_lock[9] = saveBuf[113];
	rule_soft_speed[9] = saveBuf[114];
	rule_are[9] = saveBuf[115];
	rule_color[9] = saveBuf[116];
	rule_lock_reset[9] = saveBuf[117];
	rule_lock_sound[9] = saveBuf[118];
	rule_ars_extrot[9] = saveBuf[119];
	rule_lock_limit[9] = saveBuf[120];
	rule_graphics[9] = saveBuf[121];
	
	// フォントカラー設定（122～141）
	for(i = 0; i < 10; i++) {
		fontc[i] = saveBuf[122 + i];
		digitc[i] = saveBuf[132 + i];
	}
	
	enable_bgfade = saveBuf[142];
	skip_blocklockflash = saveBuf[143];
	drs_floorkick = saveBuf[144];
	rule_rot_limit[9] = saveBuf[145];
	tomoyo_clear_erase = saveBuf[146];
	rule_180rot[9] = saveBuf[147];
	show_endmenu = saveBuf[148];
	sound_ending_loop = saveBuf[149];
	sound_beginner_ending_loop = saveBuf[150];
	enable_item_hold = saveBuf[151];
	
	// アイテムスイッチ
	for(i = 0; i < 32; i++) item_switch[i] = BitTest(saveBuf[152], i);
	
	enable_ff_rerise = saveBuf[153];
	vs_goal_level = saveBuf[154];
	vs_timelimit = saveBuf[155];
	vs_item = saveBuf[156];
	vs_rise = saveBuf[157];
	item_gauge_uptype = saveBuf[158];
	item_interval = saveBuf[159];
	enable_navigation = saveBuf[160];
	limit_navigation = saveBuf[161];
	limit_time_navigation = saveBuf[162];
	show_rise_num = saveBuf[163];
	lackblock_grayout = saveBuf[164];
	rule_max_waitt[9] = saveBuf[165];
	hold_sound = saveBuf[166];
	pause_visible = saveBuf[167];
	p_def_setting = saveBuf[168];
	p_backno = saveBuf[169];
	nextskip = saveBuf[170];
	p_def_leveltype = saveBuf[171];
	p_def_timelimit = saveBuf[172];
	p_def_goal = saveBuf[173];
	p_def_staffroll = saveBuf[174];
	cpu_enable_setting[0] = saveBuf[175];
	cpu_enable_setting[1] = saveBuf[176];
	cpu_default_level[0] = saveBuf[177];
	cpu_default_level[1] = saveBuf[178];
	enable_disp_lastline = saveBuf[179];
	lastmode[0] = saveBuf[180];
	lastmode[1] = saveBuf[181];
	lasttype[0] = saveBuf[182];
	lasttype[1] = saveBuf[183];
	holdframetype = saveBuf[184];
	vs_goal_type = saveBuf[185];
	rule_oblk_bg[9] = saveBuf[186];
	show_section_time = saveBuf[187];
	joykeyButtonNum = saveBuf[188];
	
	// アイテムスイッチ２
	for(i = 32; i < 39; i++) item_switch[i] = BitTest(saveBuf[189], i);
	
	// アイテム出現率（190～239）
	for(i = 0; i < 50; i++) item_pro[i] = saveBuf[190 + i];
	
	timer_font_type = saveBuf[240];
	block_shadow = saveBuf[241];
	block_afterimage = saveBuf[242];
	ace_frame = saveBuf[243];
	enable_combo = saveBuf[244];
	display_combo = saveBuf[245];
	enable_irs = saveBuf[246];
	background_compatibility = saveBuf[247];
	fadesetting = saveBuf[248];
	disp_waits = saveBuf[249];
	fps_plus_key = saveBuf[250];
	fps_minus_key = saveBuf[251];
	joy_fps_plus_key[0] = saveBuf[252];
	joy_fps_plus_key[1] = saveBuf[253];
	joy_fps_minus_key[0] = saveBuf[254];
	joy_fps_minus_key[1] = saveBuf[255];
	replay_autosave = saveBuf[256];
	d_disp_lineinfo = saveBuf[257];
	refresh_timing = saveBuf[258];
	beffect_speed = saveBuf[259];
	hidden_b_type = saveBuf[260];
	
	return 0;
}

// 最後に使ったルールだけ保存
void config_save_rots() {
	int bak[6];
	
	bak[0] = rots[0];
	bak[1] = rots[1];
	bak[2] = lastmode[0];
	bak[3] = lastmode[1];
	bak[4] = lasttype[0];
	bak[5] = lasttype[1];
	
	config_load();
	
	rots[0] = bak[0];
	rots[1] = bak[1];
	lastmode[0] = bak[2];
	lastmode[1] = bak[3];
	lasttype[0] = bak[4];
	lasttype[1] = bak[5];
	
	saveBuf[86] = rots[0];
	saveBuf[87] = rots[1];
	saveBuf[180] = lastmode[0];
	saveBuf[181] = lastmode[1];
	saveBuf[182] = lasttype[0];
	saveBuf[183] = lasttype[1];
	
	SaveFile("CONFIG.SAV", &saveBuf, 500 * 4);
}

// デフォルト設定を作成
void config_make_default() {
	int i;
	
	// キーコンフィグ系設定
	for(i = 0; i < 20; i++) {
		keyAssign[i] = 0;
		joykeyAssign[i] = -1;
	}
	pause_key[0] = 0x3B;
	pause_key[1] = 0x3C;
	hnext_key[0] = 0x3D;
	hnext_key[1] = 0x3E;
	giveup_key = 0x58;
	ss_key = 0x57;
	
	// その他設定
	maxPlay = 0;
	b_maxPlay = maxPlay;
	
	w_reverse = 1;
	r_irs = 1;
	downtype = 2;
	beginner_effect = 1;
	nextblock = 10;
	nanameallow = 1;
	sonicdrop = 0;
	fastlrmove = 1;
	lvupbonus = 0;
	main_fps = 60;
	fldtr = 64;
	breakeffect = 2;
	breakgraphics = 1;
	dispnext = 3;
	rule_name = 2;
	show_fps = 1;
	showctrl = 0;
	skip_viewbg = 0;
	tls_view = 0;
	bgm = 0;
	se = 1;
	bgmvolume = 0;
	sevolume = 0;
	rotate_sound = 0;
	move_sound = 0;
	joy_pause_key[0] = -1;
	joy_pause_key[1] = -1;
	joy_hnext_key[0] = -1;
	joy_hnext_key[1] = -1;
	joy_giveup_key[0] = -1;
	joy_giveup_key[1] = -1;
	joy_ss_key[0] = -1;
	joy_ss_key[1] = -1;
	spawn_y_type = 0;
	top_frame = 0;
	rots[0] = 2;
	rots[1] = 1;
	empty_spin_field = 0;
	tspin_type = 4;
	world_move_sound = 1;
	breakmax = 100;
	show_gpoint = 0;
	w_lockdown = 1;
	blockflash = 2;
	fldbgtype = 0;
	wsoftlock = 0;
	rot180 = 0;
	english = 0;
	skip_key[0] = 0x3F;
	skip_key[1] = 0x40;
	joy_skip_key[0] = -1;
	joy_skip_key[1] = -1;
	enable_b_to_b = 0;
	enable_minspeed = 0;
	disable_hold = 0;
	bonus_tspin = 0;
	bonus_btb = 0;
	ace_irs = 0;
	hide_score = 0;
	hide_grade = 0;
	rule_rot[9] = 2;
	rule_hard_lock[9] = 1;
	rule_soft_lock[9] = 0;
	rule_soft_speed[9] = 1;
	rule_are[9] = 1;
	rule_color[9] = 1;
	rule_lock_reset[9] = 1;
	rule_lock_sound[9] = 1;
	rule_ars_extrot[9] = 1;
	rule_lock_limit[9] = 128;
	rule_graphics[9] = 7;
	enable_bgfade = 1;
	skip_blocklockflash = 3;
	drs_floorkick = 0;
	rule_rot_limit[9] = 128;
	tomoyo_clear_erase = 0;
	show_endmenu = 1;
	sound_ending_loop = 0;
	sound_beginner_ending_loop = 0;
	enable_item_hold = 2;
	
	// アイテムスイッチ
	for(i = 0; i < 32; i++) item_switch[i] = 1;
	
	enable_ff_rerise = 1;
	vs_goal_level = 2;
	vs_timelimit = 7200;
	vs_item = 1;
	vs_rise = 1;
	item_gauge_uptype = 0;
	item_interval = 20;
	enable_navigation = 1;
	limit_navigation = 100;
	limit_time_navigation = 60;
	show_rise_num = 0;
	lackblock_grayout = 0;
	rule_max_waitt[9] = 99;
	hold_sound = 3;
	pause_visible = 1;
	p_def_setting = 0;
	p_backno = 0;
	nextskip = 1;
	p_def_leveltype = 0;
	p_def_timelimit = 0;
	p_def_goal = 0;
	p_def_staffroll = 0;
	cpu_enable_setting[0] = 0;
	cpu_enable_setting[1] = 0;
	cpu_default_level[0] = 0;
	cpu_default_level[1] = 0;
	enable_disp_lastline = 0;
	lastmode[0] = 0;
	lastmode[1] = 0;
	lasttype[0] = 0;
	lasttype[1] = 0;
	holdframetype = 1;
	vs_goal_type = 0;
	rule_oblk_bg[9] = 0;
	show_section_time = 0;
	joykeyButtonNum = 16;
	
	// アイテムスイッチ２
	for(i = 32; i < 39; i++) item_switch[i] = 1;
	
	timer_font_type = 0;
	block_shadow = 0;
	block_afterimage = 0;
	ace_frame = 0;
	enable_combo = 1;
	display_combo = 0;
	enable_irs = 1;
	background_compatibility = 0;
	fadesetting = 100;
	disp_waits = 0;
	fps_plus_key = 0x42;
	fps_minus_key = 0x41;
	joy_fps_plus_key[0] = -1;
	joy_fps_plus_key[1] = -1;
	joy_fps_minus_key[0] = -1;
	joy_fps_minus_key[1] = -1;
	replay_autosave = 1;
	d_disp_lineinfo = 0;
	refresh_timing = 1;
	beffect_speed = 0;
	hidden_b_type = 0;
}

// C7系に似た設定にリセット
void set_c7_style_config() {
	rule_name = 1;
	tspin_type = 3;
	enable_b_to_b = 1;
	bonus_tspin = 1;
	bonus_btb = 1;
	enable_item_hold = 0;
	drs_floorkick = 1;
	rot180 = 2;
	show_gpoint = 1;
	show_rise_num = 1;
	pause_visible = 0;
	block_shadow = 1;
	block_afterimage = 2;
	ace_frame = 1;
	background_compatibility = 1;
}

// 設定画面
void config_menu() {
	int i;
	
	for(i = 0; i < 20; i++) statc[i] = 0;
	
	reload_graphics = 0;
	reload_background = 0;
	reload_se = 0;
	reload_bgm = 0;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		printFont(1, 1, "CONFIG", fontc[rots[0]]);
		
		printFont(1, 3 + statc[0], "b", fontc[rots[0]]);
		
		printFont(2,  3, "[SAVE & EXIT]",                fontc[rots[0]] * (statc[0] == 0));
		printFont(2,  4, "[GAME SETTING]",               fontc[rots[0]] * (statc[0] == 1));
		printFont(2,  5, "[DISPLAY SETTING]",            fontc[rots[0]] * (statc[0] == 2));
		printFont(2,  6, "[SOUND SETTING]",              fontc[rots[0]] * (statc[0] == 3));
		printFont(2,  7, "[INPUT SETTING]",              fontc[rots[0]] * (statc[0] == 4));
		printFont(2,  8, "[CUSTOM RULE]",                fontc[rots[0]] * (statc[0] == 5));
		printFont(2,  9, "[FONT COLOR]",                 fontc[rots[0]] * (statc[0] == 6));
		printFont(2, 10, "[ITEM SWITCH]",                fontc[rots[0]] * (statc[0] == 7));
		printFont(2, 11, "[EDIT FAVORITES]",             fontc[rots[0]] * (statc[0] == 8));
		printFont(2, 12, "[RESET SETTINGS TO C7 STYLE]", fontc[rots[0]] * (statc[0] == 9));
		printFont(2, 13, "[SCREEN SETTING]",             fontc[rots[0]] * (statc[0] == 10));
		
		// カーソル移動
		padRepeat2(0);
		
		// ↑
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 0) ) {
			PlaySE(5);
			
			statc[0]--;
			if(statc[0] < 0) statc[0] = 10;
		}
		
		// ↓
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 1) ) {
			PlaySE(5);
			
			statc[0]++;
			if(statc[0] > 10) statc[0] = 0;
		}
		
		// キャンセル
		if( getPushState(0, 5) ) {
			config_load();
			return;
		}
		
		// 決定
		if( getPushState(0, 4) ) {
			PlaySE(10);
			
			if(statc[0] == 0) {
				config_save();
				
				// フィールドの表示位置を設定
				setFieldPosition(maxPlay);
				
				// 再読み込み
				if(reload_graphics)   loadGraphics();
				if(reload_background) loadBackground();
				if(reload_se)         loadWaves();
				if(reload_bgm)        loadBGM();
				
				SetFPS(main_fps);
				
				resetVolume();
				
				// プレイ人数をバックアップ
				b_maxPlay = maxPlay;
				
				// 設定内容をバックアップ
				backupSetups();
				
				return;
			}
			if(statc[0] == 1) config_game();
			if(statc[0] == 2) config_display();
			if(statc[0] == 3) config_sound();
			if(statc[0] == 4) config_input();
			if(statc[0] == 5) config_custom();
			if(statc[0] == 6) config_fontc();
			if(statc[0] == 7) config_item();
			if(statc[0] == 8) config_favorites();
			if(statc[0] == 9) set_c7_style_config();
			if(statc[0] == 10) config_screen();
		}
		
		if(!refresh_timing) spriteTime();
	}
}

// GAME SETTING
void config_game() {
	int i;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		printFont(1, 1, "GAME SETTING", fontc[rots[0]]);
		
		// 設定項目名表示
		if(statc[1] < 20) {
			printFont(1, 3 + statc[1], "b", fontc[rots[0]]);
			
			printFont(2,  3, "MAX PLAYER    :", fontc[rots[0]] * (statc[1] ==  0));
			printFont(2,  4, "WORLD REVERSE :", fontc[rots[0]] * (statc[1] ==  1));
			printFont(2,  5, "IRS WALLKICK  :", fontc[rots[0]] * (statc[1] ==  2));
			printFont(2,  6, "DOWN TYPE     :", fontc[rots[0]] * (statc[1] ==  3));
			printFont(2,  7, "NEXT PATTERN  :", fontc[rots[0]] * (statc[1] ==  4));
			printFont(2,  8, "8WAY INPUT    :", fontc[rots[0]] * (statc[1] ==  5));
			printFont(2,  9, "SONIC DROP    :", fontc[rots[0]] * (statc[1] ==  6));
			printFont(2, 10, "INIT LR MOVE  :", fontc[rots[0]] * (statc[1] ==  7));
			printFont(2, 11, "LVUP BONUS    :", fontc[rots[0]] * (statc[1] ==  8));
			printFont(2, 12, "MAX FPS       :", fontc[rots[0]] * (statc[1] ==  9));
			printFont(2, 13, "SPAWN Y TYPE  :", fontc[rots[0]] * (statc[1] == 10));
			printFont(2, 14, "T-SPIN        :", fontc[rots[0]] * (statc[1] == 11));
			printFont(2, 15, "WORLD LOCKDOWN:", fontc[rots[0]] * (statc[1] == 12));
			printFont(2, 16, "WORLD SOFTLOCK:", fontc[rots[0]] * (statc[1] == 13));
			printFont(2, 17, "180 ROTATION  :", fontc[rots[0]] * (statc[1] == 14));
			printFont(2, 18, "ENABLE MIN SP :", fontc[rots[0]] * (statc[1] == 15));
			printFont(2, 19, "ENABLE HOLD   :", fontc[rots[0]] * (statc[1] == 16));
			printFont(2, 20, "T-SPIN BONUS  :", fontc[rots[0]] * (statc[1] == 17));
			printFont(2, 21, "B-T-B BONUS   :", fontc[rots[0]] * (statc[1] == 18));
			printFont(2, 22, "IRS TYPE      :", fontc[rots[0]] * (statc[1] == 19));
			
			printFont(1, 25, "PAGE 1/3", fontc[rots[0]]);
		} else if(statc[1] < 40) {
			printFont(1, 3 + statc[1] - 20, "b", fontc[rots[0]]);
			
			printFont(2,  3, "SKIP LOCKFLASH:", fontc[rots[0]] * (statc[1] == 20));
			printFont(2,  4, "DRS FLOOR KICK:", fontc[rots[0]] * (statc[1] == 21));
			printFont(2,  5, "SHOW END MENU :", fontc[rots[0]] * (statc[1] == 22));
			printFont(2,  6, "ITEM HOLD     :", fontc[rots[0]] * (statc[1] == 23));
			printFont(2,  7, "FREE FALL RISE:", fontc[rots[0]] * (statc[1] == 24));
			printFont(2,  8, "VS GOAL LEVEL :", fontc[rots[0]] * (statc[1] == 25));
			printFont(2,  9, "VS GOAL TYPE  :", fontc[rots[0]] * (statc[1] == 26));
			printFont(2, 10, "VS TIME LIMIT :", fontc[rots[0]] * (statc[1] == 27));
			printFont(2, 11, "VS ITEM       :", fontc[rots[0]] * (statc[1] == 28));
			printFont(2, 12, "VS RISE       :", fontc[rots[0]] * (statc[1] == 29));
			printFont(2, 13, "ITEM GAUGE UP :", fontc[rots[0]] * (statc[1] == 30));
			printFont(2, 14, "ITEM INTERVAL :", fontc[rots[0]] * (statc[1] == 31));
			printFont(2, 15, "SHOW RISE LINE:", fontc[rots[0]] * (statc[1] == 32));
			printFont(2, 16, "LACK BLOCK    :", fontc[rots[0]] * (statc[1] == 33));
			printFont(2, 17, "FAV DEFAULT   :", fontc[rots[0]] * (statc[1] == 34));
			printFont(2, 18, "NEXT SKIP     :", fontc[rots[0]] * (statc[1] == 35));
			printFont(2, 19, "P LEVEL TYPE  :", fontc[rots[0]] * (statc[1] == 36));
			printFont(2, 20, "P TIME LIMIT  :", fontc[rots[0]] * (statc[1] == 37));
			printFont(2, 21, "P GOAL        :", fontc[rots[0]] * (statc[1] == 38));
			printFont(2, 22, "P STAFF ROLL  :", fontc[rots[0]] * (statc[1] == 39));
			
			printFont(1, 25, "PAGE 2/3", fontc[rots[0]]);
		} else {
			printFont(1, 3 + statc[1] - 40, "b", fontc[rots[0]]);
			
			printFont(2,  3, "CPU PLAYER 1P :", fontc[rots[0]] * (statc[1] == 40));
			printFont(2,  4, "CPU PLAYER 2P :", fontc[rots[0]] * (statc[1] == 41));
			printFont(2,  5, "CPU LEVEL  1P :", fontc[rots[0]] * (statc[1] == 42));
			printFont(2,  6, "CPU LEVEL  2P :", fontc[rots[0]] * (statc[1] == 43));
			printFont(2,  7, "ENABLE COMBO  :", fontc[rots[0]] * (statc[1] == 44));
			printFont(2,  8, "ENABLE IRS    :", fontc[rots[0]] * (statc[1] == 45));
			printFont(2,  9, "AUTO SAVE     :", fontc[rots[0]] * (statc[1] == 46));
			
			printFont(1, 25, "PAGE 3/3", fontc[rots[0]]);
		}
		
		// 設定値表示
		if(statc[1] < 20) {
			if(maxPlay == 0) sprintf(string[0], "SINGLE");
			else sprintf(string[0], "DUAL");
			printFont(18, 3, string[0], fontc[rots[0]] * (statc[1] == 0));
			
			if(w_reverse == 0) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 4, string[0], fontc[rots[0]] * (statc[1] == 1));
			
			if(r_irs == 0) sprintf(string[0], "ON");
			else sprintf(string[0], "OFF");
			printFont(18, 5, string[0], fontc[rots[0]] * (statc[1] == 2));
			
			if(downtype == 0) sprintf(string[0], "NO LIMIT");
			if(downtype == 1) sprintf(string[0], "LIMIT");
			if(downtype == 2) sprintf(string[0], "AUTO");
			printFont(18, 6, string[0], fontc[rots[0]] * (statc[1] == 3));
			
			if(nextblock == 0) sprintf(string[0], "RANDOM");
			if((nextblock >= 1) && (nextblock <= 7)) sprintf(string[0], "HEBO%d", nextblock);
			if(nextblock == 8) sprintf(string[0], "MEMORY4 (4 TRY)");
			if(nextblock == 9) sprintf(string[0], "MEMORY4 (6 TRY)");
			if(nextblock == 10) sprintf(string[0], "7 PIECE BAG");
			if(nextblock == 11) sprintf(string[0], "TOMOYO");
			if(nextblock == 12) sprintf(string[0], "DENGEN");
			if(nextblock == 13) sprintf(string[0], "DENGEN2");
			
			printFont(18, 7, string[0], fontc[rots[0]] * (statc[1] == 4));
			
			if(nanameallow == 0) sprintf(string[0], "ON");
			else sprintf(string[0], "OFF");
			printFont(18, 8, string[0], fontc[rots[0]] * (statc[1] == 5));
			
			if(sonicdrop == 0) sprintf(string[0], "ON");
			else sprintf(string[0], "OFF");
			printFont(18, 9, string[0], fontc[rots[0]] * (statc[1] == 6));
			
			if(fastlrmove == 0) sprintf(string[0], "ON");
			if(fastlrmove == 1) sprintf(string[0], "OFF");
			if(fastlrmove == 2) sprintf(string[0], "SUPER");
			if(fastlrmove == 3) sprintf(string[0], "HYPER");
			printFont(18, 10, string[0], fontc[rots[0]] * (statc[1] == 7));
			
			if(lvupbonus == 0) sprintf(string[0], "ON");
			else sprintf(string[0], "OFF");
			printFont(18, 11, string[0], fontc[rots[0]] * (statc[1] == 8));
			
			sprintf(string[0], "%d", main_fps);
			printFont(18, 12, string[0], fontc[rots[0]] * (statc[1] == 9));
			
			if(spawn_y_type == 0) sprintf(string[0], "UNDER THE FRAME");
			else sprintf(string[0], "ABOVE THE FRAME");
			printFont(18, 13, string[0], fontc[rots[0]] * (statc[1] == 10));
			
			if(tspin_type == 0) sprintf(string[0], "OFF");
			if(tspin_type == 1) sprintf(string[0], "LINE CLEAR");
			if(tspin_type == 2) sprintf(string[0], "IMMOBILE");
			if(tspin_type == 3) sprintf(string[0], "3-CORNER");
			if(tspin_type == 4) sprintf(string[0], "3-CORNER NO KICK");
			printFont(18, 14, string[0], fontc[rots[0]] * (statc[1] == 11));
			
			if(w_lockdown == 0) sprintf(string[0], "OLD TYPE");
			else sprintf(string[0], "NEW TYPE");
			printFont(18, 15, string[0], fontc[rots[0]] * (statc[1] == 12));
			
			if(wsoftlock == 0) sprintf(string[0], "NORMAL");
			if(wsoftlock == 1) sprintf(string[0], "INSTANT LOCK");
			if(wsoftlock == 2) sprintf(string[0], "FASTER LOCK");
			if(wsoftlock == 3) sprintf(string[0], "NONE");
			printFont(18, 16, string[0], fontc[rots[0]] * (statc[1] == 13));
			
			if(rot180 == 0) sprintf(string[0], "OFF");
			if(rot180 == 1) sprintf(string[0], "ON");
			if(rot180 == 2) sprintf(string[0], "ONLY SP RULE");
			printFont(18, 17, string[0], fontc[rots[0]] * (statc[1] == 14));
			
			if(enable_minspeed == 0) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 18, string[0], fontc[rots[0]] * (statc[1] == 15));
			
			if(disable_hold == 0) sprintf(string[0], "ON");
			else sprintf(string[0], "OFF");
			printFont(18, 19, string[0], fontc[rots[0]] * (statc[1] == 16));
			
			if(bonus_tspin == 0) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 20, string[0], fontc[rots[0]] * (statc[1] == 17));
			
			if(bonus_btb == 0) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 21, string[0], fontc[rots[0]] * (statc[1] == 18));
			
			if(ace_irs == 0) sprintf(string[0], "NORMAL");
			if(ace_irs == 1) sprintf(string[0], "NEW (A TYPE)");
			if(ace_irs == 2) sprintf(string[0], "NEW (B TYPE)");
			if(ace_irs == 3) sprintf(string[0], "NEW (C TYPE)");
			printFont(18, 22, string[0], fontc[rots[0]] * (statc[1] == 19));
		} else if(statc[1] < 40) {
			if(skip_blocklockflash == 0) sprintf(string[0], "OFF");
			if(skip_blocklockflash == 1) sprintf(string[0], "ON");
			if(skip_blocklockflash == 2) sprintf(string[0], "SUPER");
			if(skip_blocklockflash == 3) sprintf(string[0], "ARCADE");
			printFont(18, 3, string[0], fontc[rots[0]] * (statc[1] == 20));
			
			if(drs_floorkick == 0) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 4, string[0], fontc[rots[0]] * (statc[1] == 21));
			
			if(show_endmenu == 0) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 5, string[0], fontc[rots[0]] * (statc[1] == 22));
			
			if(enable_item_hold == 0) sprintf(string[0], "INITAL OFF/NORMAL OFF");
			if(enable_item_hold == 1) sprintf(string[0], "INITAL  ON/NORMAL  ON");
			if(enable_item_hold == 2) sprintf(string[0], "INITAL OFF/NORMAL  ON");
			if(enable_item_hold == 3) sprintf(string[0], "INITAL  ON/NORMAL OFF");
			printFont(18, 6, string[0], fontc[rots[0]] * (statc[1] == 23));
			
			if(enable_ff_rerise == 0) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 7, string[0], fontc[rots[0]] * (statc[1] == 24));
			
			if(vs_goal_level == 0) sprintf(string[0], "NONE");
			else if(vs_goal_type == 0) sprintf(string[0], "LEVEL %d", vs_goal_level * 100);
			else if(vs_goal_type == 1) sprintf(string[0], "%d LINES", vs_goal_level * 10);
			else sprintf(string[0], "%d POINTS", vs_goal_level * 5);
			printFont(18, 8, string[0], fontc[rots[0]] * (statc[1] == 25));
			
			if(vs_goal_type == 0) sprintf(string[0], "LEVEL");
			else if(vs_goal_type == 1) sprintf(string[0], "LINE");
			else sprintf(string[0], "MARATHON");
			printFont(18, 9, string[0], fontc[rots[0]] * (statc[1] == 26));
			
			if(vs_timelimit == 0) sprintf(string[0], "NONE");
			else getTime(vs_timelimit);
			printFont(18, 10, string[0], fontc[rots[0]] * (statc[1] == 27));
			
			if(vs_item == 0) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 11, string[0], fontc[rots[0]] * (statc[1] == 28));
			
			if(vs_rise == 0) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 12, string[0], fontc[rots[0]] * (statc[1] == 29));
			
			if(item_gauge_uptype == 0) sprintf(string[0], "PUT BLOCK");
			if(item_gauge_uptype == 1) sprintf(string[0], "PUT BLOCK/ERASE LINE");
			if(item_gauge_uptype == 2) sprintf(string[0], "ERASE LINE");
			printFont(18, 13, string[0], fontc[rots[0]] * (statc[1] == 30));
			
			sprintf(string[0], "%d", item_interval);
			printFont(18, 14, string[0], fontc[rots[0]] * (statc[1] == 31));
			
			if(show_rise_num == 0) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 15, string[0], fontc[rots[0]] * (statc[1] == 32));
			
			if(lackblock_grayout == 0) sprintf(string[0], "NORMAL");
			else sprintf(string[0], "GRAYOUT");
			printFont(18, 16, string[0], fontc[rots[0]] * (statc[1] == 33));
			
			sprintf(string[0], "%d %s", p_def_setting + 1, waitname[p_def_setting]);
			printFont(18, 17, string[0], fontc[rots[0]] * (statc[1] == 34));
			
			if(nextskip == 0) sprintf(string[0], "TOMOYO ONLY");
			if(nextskip == 1) sprintf(string[0], "TOMOYO & FLASH");
			if(nextskip == 2) sprintf(string[0], "ON");
			if(nextskip == 3) sprintf(string[0], "OFF");
			printFont(18, 18, string[0], fontc[rots[0]] * (statc[1] == 35));
			
			if(p_def_leveltype == 0) sprintf(string[0], "NORMAL");
			if(p_def_leveltype == 1) sprintf(string[0], "10 LINES");
			if(p_def_leveltype == 2) sprintf(string[0], "MARATHON");
			printFont(18, 19, string[0], fontc[rots[0]] * (statc[1] == 36));
			
			if(!p_def_timelimit) sprintf(string[0], "NO LIMIT");
			else getTime(p_def_timelimit);
			printFont(18, 20, string[0], fontc[rots[0]] * (statc[1] == 37));
			
			if(!p_def_goal) {
				sprintf(string[0], "ENDLESS");
			} else {
				if(p_def_leveltype == 0) sprintf(string[0], "LEVEL %d", p_def_goal * 100);
				if(p_def_leveltype == 1) sprintf(string[0], "%d LINES", p_def_goal * 10);
				if(p_def_leveltype == 2) sprintf(string[0], "LEVEL %d", p_def_goal);
			}
			printFont(18, 21, string[0], fontc[rots[0]] * (statc[1] == 38));
			
			if(p_def_staffroll == 0) sprintf(string[0], "OFF");
			if(p_def_staffroll == 1) sprintf(string[0], "ON");
			if(p_def_staffroll == 2) sprintf(string[0], "FAST ROLL");
			printFont(18, 22, string[0], fontc[rots[0]] * (statc[1] == 39));
		} else {
			if(!cpu_enable_setting[0]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 3, string[0], fontc[rots[0]] * (statc[1] == 40));
			
			if(!cpu_enable_setting[1]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 4, string[0], fontc[rots[0]] * (statc[1] == 41));
			
			sprintf(string[0], "%d", cpu_default_level[0] + 1);
			printFont(18, 5, string[0], fontc[rots[0]] * (statc[1] == 42));
			
			sprintf(string[0], "%d", cpu_default_level[1] + 1);
			printFont(18, 6, string[0], fontc[rots[0]] * (statc[1] == 43));
			
			if(!enable_combo) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 7, string[0], fontc[rots[0]] * (statc[1] == 44));
			
			if(!enable_irs) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 8, string[0], fontc[rots[0]] * (statc[1] == 45));
			
			if(!replay_autosave) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 9, string[0], fontc[rots[0]] * (statc[1] == 46));
		}
		
		// 設定値変更
		padRepeat(0);
		
		// ←
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 2) ) {
			PlaySE(3);
			
			if(statc[1] == 0) {
				maxPlay = !maxPlay;
				reload_background = 1;
			}
			if(statc[1] == 1) w_reverse = !w_reverse;
			if(statc[1] == 2) r_irs = !r_irs;
			if(statc[1] == 3) {
				downtype--;
				if(downtype < 0) downtype = 2;
			}
			if(statc[1] == 4) {
				nextblock--;
				if(nextblock < 0) nextblock = 13;
			}
			if(statc[1] == 5) nanameallow = !nanameallow;
			if(statc[1] == 6) sonicdrop = !sonicdrop;
			if(statc[1] == 7) {
				fastlrmove--;
				if(fastlrmove < 0) fastlrmove = 3;
			}
			if(statc[1] == 8) lvupbonus = !lvupbonus;
			if(statc[1] == 9) {
				main_fps--;
				if(main_fps < 1) main_fps = 99;
			}
			if(statc[1] == 10) spawn_y_type = !spawn_y_type;
			if(statc[1] == 11) {
				tspin_type--;
				if(tspin_type < 0) tspin_type = 4;
			}
			if(statc[1] == 12) w_lockdown = !w_lockdown;
			if(statc[1] == 13) {
				wsoftlock--;
				if(wsoftlock < 0) wsoftlock = 3;
			}
			if(statc[1] == 14) {
				rot180--;
				if(rot180 < 0) rot180 = 2;
			}
			if(statc[1] == 15) enable_minspeed = !enable_minspeed;
			if(statc[1] == 16) disable_hold = !disable_hold;
			if(statc[1] == 17) bonus_tspin = !bonus_tspin;
			if(statc[1] == 18) bonus_btb = !bonus_btb;
			if(statc[1] == 19) {
				ace_irs--;
				if(ace_irs < 0) ace_irs = 3;
			}
			if(statc[1] == 20) {
				skip_blocklockflash--;
				if(skip_blocklockflash < 0) skip_blocklockflash = 3;
			}
			if(statc[1] == 21) drs_floorkick = !drs_floorkick;
			if(statc[1] == 22) show_endmenu = !show_endmenu;
			if(statc[1] == 23) {
				enable_item_hold--;
				if(enable_item_hold < 0) enable_item_hold = 3;
			}
			if(statc[1] == 24) enable_ff_rerise = !enable_ff_rerise;
			if(statc[1] == 25) {
				vs_goal_level--;
				if(vs_goal_level < 0) vs_goal_level = 20;
			}
			if(statc[1] == 26) {
				vs_goal_type--;
				if(vs_goal_type < 0) vs_goal_type = 2;
			}
			if(statc[1] == 27) {
				vs_timelimit = vs_timelimit - 60;
				if(vs_timelimit < 0) vs_timelimit = 72000;
			}
			if(statc[1] == 28) vs_item = !vs_item;
			if(statc[1] == 29) vs_rise = !vs_rise;
			if(statc[1] == 30) {
				item_gauge_uptype--;
				if(item_gauge_uptype < 0) item_gauge_uptype = 2;
			}
			if(statc[1] == 31) {
				item_interval--;
				if(item_interval < 0) item_interval = 99;
			}
			if(statc[1] == 32) show_rise_num = !show_rise_num;
			if(statc[1] == 33) lackblock_grayout = !lackblock_grayout;
			if(statc[1] == 34) {
				i = 0;
				
				do {
					p_def_setting--;
					
					if(p_def_setting < 0) {
						if(i == 0) {
							p_def_setting = 19;
							i = 1;
						} else {
							p_def_setting = 0;
							break;
						}
					}
				} while(favorites_isempty(p_def_setting));
			}
			if(statc[1] == 35) {
				nextskip--;
				if(nextskip < 0) nextskip = 3;
			}
			if(statc[1] == 36) {
				p_def_leveltype--;
				if(p_def_leveltype < 0) p_def_leveltype = 2;
			}
			if(statc[1] == 37) {
				p_def_timelimit = p_def_timelimit - 60;
				if(p_def_timelimit < 0) p_def_timelimit = 72000;
			}
			if(statc[1] == 38) {
				p_def_goal--;
				if(p_def_goal < 0) p_def_goal = 20;
			}
			if(statc[1] == 39) {
				p_def_staffroll--;
				if(p_def_staffroll < 0) p_def_staffroll = 2;
			}
			if(statc[1] == 40) cpu_enable_setting[0] = !cpu_enable_setting[0];
			if(statc[1] == 41) cpu_enable_setting[1] = !cpu_enable_setting[1];
			if(statc[1] == 42) {
				cpu_default_level[0]--;
				if(cpu_default_level[0] < 0) cpu_default_level[0] = 4;
			}
			if(statc[1] == 43) {
				cpu_default_level[1]--;
				if(cpu_default_level[1] < 0) cpu_default_level[1] = 4;
			}
			if(statc[1] == 44) enable_combo = !enable_combo;
			if(statc[1] == 45) enable_irs = !enable_irs;
			if(statc[1] == 46) replay_autosave = !replay_autosave;
		}
		
		// →
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 3) ) {
			PlaySE(3);
			
			if(statc[1] == 0) {
				maxPlay = !maxPlay;
				reload_background = 1;
			}
			if(statc[1] == 1) w_reverse = !w_reverse;
			if(statc[1] == 2) r_irs = !r_irs;
			if(statc[1] == 3) {
				downtype++;
				if(downtype > 2) downtype = 0;
			}
			if(statc[1] == 4) {
				nextblock++;
				if(nextblock > 13) nextblock = 0;
			}
			if(statc[1] == 5) nanameallow = !nanameallow;
			if(statc[1] == 6) sonicdrop = !sonicdrop;
			if(statc[1] == 7) {
				fastlrmove++;
				if(fastlrmove > 3) fastlrmove = 0;
			}
			if(statc[1] == 8) lvupbonus = !lvupbonus;
			if(statc[1] == 9) {
				main_fps++;
				if(main_fps > 99) main_fps = 1;
			}
			if(statc[1] == 10) spawn_y_type = !spawn_y_type;
			if(statc[1] == 11) {
				tspin_type++;
				if(tspin_type > 4) tspin_type = 0;
			}
			if(statc[1] == 12) w_lockdown = !w_lockdown;
			if(statc[1] == 13) {
				wsoftlock++;
				if(wsoftlock > 3) wsoftlock = 0;
			}
			if(statc[1] == 14) {
				rot180++;
				if(rot180 > 2) rot180 = 0;
			}
			if(statc[1] == 15) enable_minspeed = !enable_minspeed;
			if(statc[1] == 16) disable_hold = !disable_hold;
			if(statc[1] == 17) bonus_tspin = !bonus_tspin;
			if(statc[1] == 18) bonus_btb = !bonus_btb;
			if(statc[1] == 19) {
				ace_irs++;
				if(ace_irs > 3) ace_irs = 0;
			}
			if(statc[1] == 20) {
				skip_blocklockflash++;
				if(skip_blocklockflash > 3) skip_blocklockflash = 0;
			}
			if(statc[1] == 21) drs_floorkick = !drs_floorkick;
			if(statc[1] == 22) show_endmenu = !show_endmenu;
			if(statc[1] == 23) {
				enable_item_hold++;
				if(enable_item_hold > 3) enable_item_hold = 0;
			}
			if(statc[1] == 24) enable_ff_rerise = !enable_ff_rerise;
			if(statc[1] == 25) {
				vs_goal_level++;
				if(vs_goal_level > 20) vs_goal_level = 0;
			}
			if(statc[1] == 26) {
				vs_goal_type++;
				if(vs_goal_type > 2) vs_goal_type = 0;
			}
			if(statc[1] == 27) {
				vs_timelimit = vs_timelimit + 60;
				if(vs_timelimit > 72000) vs_timelimit = 0;
			}
			if(statc[1] == 28) vs_item = !vs_item;
			if(statc[1] == 29) vs_rise = !vs_rise;
			if(statc[1] == 30) {
				item_gauge_uptype++;
				if(item_gauge_uptype > 2) item_gauge_uptype = 0;
			}
			if(statc[1] == 31) {
				item_interval++;
				if(item_interval > 99) item_interval = 0;
			}
			if(statc[1] == 32) show_rise_num = !show_rise_num;
			if(statc[1] == 33) lackblock_grayout = !lackblock_grayout;
			if(statc[1] == 34) {
				i = 0;
				
				do {
					p_def_setting++;
					
					if(p_def_setting > 19) {
						if(i == 0) {
							p_def_setting = 0;
							i = 1;
						} else {
							p_def_setting = 0;
							break;
						}
					}
				} while(favorites_isempty(p_def_setting));
			}
			if(statc[1] == 35) {
				nextskip++;
				if(nextskip > 3) nextskip = 0;
			}
			if(statc[1] == 36) {
				p_def_leveltype++;
				if(p_def_leveltype > 2) p_def_leveltype = 0;
			}
			if(statc[1] == 37) {
				p_def_timelimit = p_def_timelimit + 60;
				if(p_def_timelimit > 72000) p_def_timelimit = 0;
			}
			if(statc[1] == 38) {
				p_def_goal++;
				if(p_def_goal > 20) p_def_goal = 0;
			}
			if(statc[1] == 39) {
				p_def_staffroll++;
				if(p_def_staffroll > 2) p_def_staffroll = 0;
			}
			if(statc[1] == 40) cpu_enable_setting[0] = !cpu_enable_setting[0];
			if(statc[1] == 41) cpu_enable_setting[1] = !cpu_enable_setting[1];
			if(statc[1] == 42) {
				cpu_default_level[0]++;
				if(cpu_default_level[0] > 4) cpu_default_level[0] = 0;
			}
			if(statc[1] == 43) {
				cpu_default_level[1]++;
				if(cpu_default_level[1] > 4) cpu_default_level[1] = 0;
			}
			if(statc[1] == 44) enable_combo = !enable_combo;
			if(statc[1] == 45) enable_irs = !enable_irs;
			if(statc[1] == 46) replay_autosave = !replay_autosave;
		}
		
		// カーソル移動
		padRepeat2(0);
		
		// ↑
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 0) ) {
			PlaySE(5);
			
			statc[1]--;
			if(statc[1] < 0) statc[1] = 46;
		}
		
		// ↓
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 1) ) {
			PlaySE(5);
			
			statc[1]++;
			if(statc[1] > 46) statc[1] = 0;
		}
		
		// キャンセル
		if( getPushState(0, 5) ) {
			return;
		}
		
		// 決定
		if( getPushState(0, 4) ) {
			PlaySE(10);
			return;
		}
		
		if(!refresh_timing) spriteTime();
	}
}

// DISPLAY SETTING
void config_display() {
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		printFont(1, 1, "DISPLAY SETTING", fontc[rots[0]]);
		
		// 設定項目名表示
		if(statc[2] < 20) {
			printFont(1, 3 + statc[2], "b", fontc[rots[0]]);
			
			printFont(2,  3, "FIELD TR      :", fontc[rots[0]] * (statc[2] ==  0));
			printFont(2,  4, "BREAK EFFECT  :", fontc[rots[0]] * (statc[2] ==  1));
			printFont(2,  5, "BREAK GRAPHICS:", fontc[rots[0]] * (statc[2] ==  2));
			printFont(2,  6, "NEXT DISPLAY  :", fontc[rots[0]] * (statc[2] ==  3));
			printFont(2,  7, "RULE NAME TYPE:", fontc[rots[0]] * (statc[2] ==  4));
			printFont(2,  8, "SHOW FPS      :", fontc[rots[0]] * (statc[2] ==  5));
			printFont(2,  9, "SHOW CONTROL  :", fontc[rots[0]] * (statc[2] ==  6));
			printFont(2, 10, "BACKGROUND    :", fontc[rots[0]] * (statc[2] ==  7));
			printFont(2, 11, "GHOST PIECE   :", fontc[rots[0]] * (statc[2] ==  8));
			printFont(2, 12, "TOP FRAME     :", fontc[rots[0]] * (statc[2] ==  9));
			printFont(2, 13, "SPIN FIELD    :", fontc[rots[0]] * (statc[2] == 10));
			printFont(2, 14, "MAX EFFECT    :", fontc[rots[0]] * (statc[2] == 11));
			printFont(2, 15, "SHOW GPOINT   :", fontc[rots[0]] * (statc[2] == 12));
			printFont(2, 16, "BLOCK FRAME   :", fontc[rots[0]] * (statc[2] == 13));
			printFont(2, 17, "SHOW GRID     :", fontc[rots[0]] * (statc[2] == 14));
			printFont(2, 18, "LANGUAGE      :", fontc[rots[0]] * (statc[2] == 15));
			printFont(2, 19, "BACK TO BACK  :", fontc[rots[0]] * (statc[2] == 16));
			printFont(2, 20, "SCORE DISPLAY :", fontc[rots[0]] * (statc[2] == 17));
			printFont(2, 21, "GRADE DISPLAY :", fontc[rots[0]] * (statc[2] == 18));
			printFont(2, 22, "BG FADE       :", fontc[rots[0]] * (statc[2] == 19));
			
			printFont(1, 25, "PAGE 1/2", fontc[rots[0]]);
		} else {
			printFont(1, 3 + statc[2] - 20, "b", fontc[rots[0]]);
			
			printFont(2,  3, "TOMOYO CLEAR  :", fontc[rots[0]] * (statc[2] == 20));
			printFont(2,  4, "BEGINNER BREAK:", fontc[rots[0]] * (statc[2] == 21));
			printFont(2,  5, "NAVIGATION    :", fontc[rots[0]] * (statc[2] == 22));
			printFont(2,  6, "NAVI END LEVEL:", fontc[rots[0]] * (statc[2] == 23));
			printFont(2,  7, "NAVI DISP TIME:", fontc[rots[0]] * (statc[2] == 24));
			printFont(2,  8, "PAUSE FIELD   :", fontc[rots[0]] * (statc[2] == 25));
			printFont(2,  9, "PRACTICE BG   :", fontc[rots[0]] * (statc[2] == 26));
			printFont(2, 10, "DISP LAST LINE:", fontc[rots[0]] * (statc[2] == 27));
			printFont(2, 11, "HOLD FRAME    :", fontc[rots[0]] * (statc[2] == 28));
			printFont(2, 12, "SHOW SEC-TIME :", fontc[rots[0]] * (statc[2] == 29));
			printFont(2, 13, "TIMER FONT    :", fontc[rots[0]] * (statc[2] == 30));
			printFont(2, 14, "BLOCK SHADOW  :", fontc[rots[0]] * (statc[2] == 31));
			printFont(2, 15, "AFTERIMAGE    :", fontc[rots[0]] * (statc[2] == 32));
			printFont(2, 16, "ACE FRAME     :", fontc[rots[0]] * (statc[2] == 33));
			printFont(2, 17, "DISPLAY COMBO :", fontc[rots[0]] * (statc[2] == 34));
			printFont(2, 18, "IGNORE BACK13-:", fontc[rots[0]] * (statc[2] == 35));
			printFont(2, 19, "DISP WAITS    :", fontc[rots[0]] * (statc[2] == 36));
			printFont(2, 20, "DISP LINE INFO:", fontc[rots[0]] * (statc[2] == 37));
			printFont(2, 21, "REFRESH TIMING:", fontc[rots[0]] * (statc[2] == 38));
			printFont(2, 22, "EFFECT SPEED  :", fontc[rots[0]] * (statc[2] == 39));
			printFont(2, 23, "HIDDEN-B TYPE :", fontc[rots[0]] * (statc[2] == 40));
			
			printFont(1, 25, "PAGE 2/2", fontc[rots[0]]);
		}
		
		// 設定値表示
		if(statc[2] < 20) {
			sprintf(string[0], "%d", fldtr);
			printFont(18, 3, string[0], fontc[rots[0]] * (statc[2] == 0));
			
			if(breakeffect == 0) sprintf(string[0], "NO EFFECT");
			if(breakeffect == 1) sprintf(string[0], "POP OUT");
			if(breakeffect == 2) sprintf(string[0], "SHATTER");
			if(breakeffect == 3) sprintf(string[0], "SHATTER (OLD)");
			if(breakeffect == 4) sprintf(string[0], "OLD STYLE-HANDHELD");
			if(breakeffect == 5) sprintf(string[0], "OLD STYLE-ARCADE");
			printFont(18, 4, string[0], fontc[rots[0]] * (statc[2] == 1));
			
			if(breakgraphics == 0) sprintf(string[0], "LOW BRIGHT");
			else sprintf(string[0], "HIGH BRIGHT");
			printFont(18, 5, string[0], fontc[rots[0]] * (statc[2] == 2));
			
			sprintf(string[0], "%d", dispnext);
			printFont(18, 6, string[0], fontc[rots[0]] * (statc[2] == 3));
			
			sprintf(string[0], "%d", rule_name);
			printFont(18, 7, string[0], fontc[rots[0]] * (statc[2] == 4));
			
			if(show_fps == 0) sprintf(string[0], "OFF");
			if(show_fps == 1) sprintf(string[0], "ON");
			if(show_fps == 2) sprintf(string[0], "CAPTION");
			printFont(18, 8, string[0], fontc[rots[0]] * (statc[2] == 5));
			
			if(showctrl == 0) sprintf(string[0], "REPLAY ONLY");
			if(showctrl == 1) sprintf(string[0], "ON");
			if(showctrl == 2) sprintf(string[0], "OFF");
			printFont(18, 9, string[0], fontc[rots[0]] * (statc[2] == 6));
			
			if(skip_viewbg == 0) sprintf(string[0], "ON");
			else sprintf(string[0], "OFF");
			printFont(18, 10, string[0], fontc[rots[0]] * (statc[2] == 7));
			
			if(tls_view == 0) sprintf(string[0], "LV100");
			if(tls_view == 1) sprintf(string[0], "ON");
			if(tls_view == 2) sprintf(string[0], "OFF");
			printFont(18, 11, string[0], fontc[rots[0]] * (statc[2] == 8));
			
			sprintf(string[0], "%d", top_frame);
			printFont(18, 12, string[0], fontc[rots[0]] * (statc[2] == 9));
			
			if(empty_spin_field == 0) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 13, string[0], fontc[rots[0]] * (statc[2] == 10));
			
			sprintf(string[0], "%d", breakmax);
			printFont(18, 14, string[0], fontc[rots[0]] * (statc[2] == 11));
			
			if(show_gpoint == 0) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 15, string[0], fontc[rots[0]] * (statc[2] == 12));
			
			if(blockflash == 0) sprintf(string[0], "BLINK");
			if(blockflash == 1) sprintf(string[0], "ON");
			if(blockflash == 2) sprintf(string[0], "OFF");
			printFont(18, 16, string[0], fontc[rots[0]] * (statc[2] == 13));
			
			if(fldbgtype == 0) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 17, string[0], fontc[rots[0]] * (statc[2] == 14));
			
			if(english == 0) sprintf(string[0], "JAPANESE");
			else sprintf(string[0], "ENGLISH");
			printFont(18, 18, string[0], fontc[rots[0]] * (statc[2] == 15));
			
			if(enable_b_to_b == 0) sprintf(string[0], "OFF");
			else if(enable_b_to_b == 1) sprintf(string[0], "ON");
			else sprintf(string[0], "ON (WITH CHAIN DISP)");
			printFont(18, 19, string[0], fontc[rots[0]] * (statc[2] == 16));
			
			if(hide_score == 0) sprintf(string[0], "SHOW");
			else sprintf(string[0], "HIDE");
			printFont(18, 20, string[0], fontc[rots[0]] * (statc[2] == 17));
			
			if(hide_grade == 0) sprintf(string[0], "SHOW");
			else sprintf(string[0], "HIDE");
			printFont(18, 21, string[0], fontc[rots[0]] * (statc[2] == 18));
			
			if(enable_bgfade == 0) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 22, string[0], fontc[rots[0]] * (statc[2] == 19));
		} else {
			if(tomoyo_clear_erase == 0) sprintf(string[0], "EFFECT OFF");
			else sprintf(string[0], "EFFECT ON");
			printFont(18, 3, string[0], fontc[rots[0]] * (statc[2] == 20));
			
			if(beginner_effect == 0) sprintf(string[0], "USE NORMAL SETTING");
			else sprintf(string[0], "POP OUT");
			printFont(18, 4, string[0], fontc[rots[0]] * (statc[2] == 21));
			
			if(enable_navigation == 0) sprintf(string[0], "OFF");
			if(enable_navigation == 1) sprintf(string[0], "BEGINNER ONLY");
			if(enable_navigation == 2) sprintf(string[0], "ON");
			printFont(18, 5, string[0], fontc[rots[0]] * (statc[2] == 22));
			
			sprintf(string[0], "%d", limit_navigation);
			printFont(18, 6, string[0], fontc[rots[0]] * (statc[2] == 23));
			
			getTime(limit_time_navigation);
			printFont(18, 7, string[0], fontc[rots[0]] * (statc[2] == 24));
			
			if(pause_visible == 0) sprintf(string[0], "HIDE");
			else sprintf(string[0], "SHOW");
			printFont(18, 8, string[0], fontc[rots[0]] * (statc[2] == 25));
			
			sprintf(string[0], "%d", p_backno + 1);
			printFont(18, 9, string[0], fontc[rots[0]] * (statc[2] == 26));
			
			if(!enable_disp_lastline) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 10, string[0], fontc[rots[0]] * (statc[2] == 27));
			
			if(holdframetype == 0) sprintf(string[0], "BOLD");
			else if(holdframetype == 1) sprintf(string[0], "THIN");
			else sprintf(string[0], "OFF");
			printFont(18, 11, string[0], fontc[rots[0]] * (statc[2] == 28));
			
			if(show_section_time == 0) sprintf(string[0], "OFF");
			if(show_section_time == 1) sprintf(string[0], "ACHIEVE TIME ONLY");
			if(show_section_time == 2) sprintf(string[0], "SECTION TIME ONLY");
			if(show_section_time == 3) sprintf(string[0], "ON");
			printFont(18, 12, string[0], fontc[rots[0]] * (statc[2] == 29));
			
			sprintf(string[0], "%d", timer_font_type);
			printFont(18, 13, string[0], fontc[rots[0]] * (statc[2] == 30));
			
			if(!block_shadow) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 14, string[0], fontc[rots[0]] * (statc[2] == 31));
			
			if(block_afterimage == 0) sprintf(string[0], "OFF");
			if(block_afterimage == 1) sprintf(string[0], "HARD DROP ONLY");
			if(block_afterimage == 2) sprintf(string[0], "ON");
			printFont(18, 15, string[0], fontc[rots[0]] * (statc[2] == 32));
			
			if(!ace_frame) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 16, string[0], fontc[rots[0]] * (statc[2] == 33));
			
			if(display_combo == 0) sprintf(string[0], "OFF");
			if(display_combo == 1) sprintf(string[0], "NORMAL");
			if(display_combo == 2) sprintf(string[0], "2LINES");
			printFont(18, 17, string[0], fontc[rots[0]] * (statc[2] == 34));
			
			if(!background_compatibility) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 18, string[0], fontc[rots[0]] * (statc[2] == 35));
			
			if(!disp_waits) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 19, string[0], fontc[rots[0]] * (statc[2] == 36));
			
			if(!d_disp_lineinfo) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFont(18, 20, string[0], fontc[rots[0]] * (statc[2] == 37));
			
			if(!refresh_timing) sprintf(string[0], "AFTER GAME CYCLE");
			else sprintf(string[0], "BEFORE GAME CYCLE");
			printFont(18, 21, string[0], fontc[rots[0]] * (statc[2] == 38));
			
			if(!beffect_speed) sprintf(string[0], "AUTO");
			else sprintf(string[0], "e %d", beffect_speed);
			printFont(18, 22, string[0], fontc[rots[0]] * (statc[2] == 39));
			
			if(!hidden_b_type) sprintf(string[0], "NORMAL");
			else sprintf(string[0], "SPECIAL");
			printFont(18, 23, string[0], fontc[rots[0]] * (statc[2] == 40));
		}
		
		// 設定値変更
		padRepeat(0);
		
		// ←
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 2) ) {
			PlaySE(3);
			
			if(statc[2] == 0) {
				fldtr--;
				if(fldtr < 0) fldtr = 256;
				reload_background = 1;
			}
			if(statc[2] == 1) {
				breakeffect--;
				if(breakeffect < 0) breakeffect = 5;
				reload_graphics = 1;
			}
			if(statc[2] == 2) {
				breakgraphics = !breakgraphics;
				reload_graphics = 1;
			}
			if(statc[2] == 3) {
				dispnext--;
				if(dispnext < 0) dispnext = 6;
			}
			if(statc[2] == 4) {
				rule_name--;
				if(rule_name < 0) rule_name = 2;
			}
			if(statc[2] == 5) {
				show_fps--;
				if(show_fps < 0) show_fps = 2;
				if(show_fps != 2) SetConstParam("Caption", "HEBORIS LITE");
			}
			if(statc[2] == 6) {
				showctrl--;
				if(showctrl < 0) showctrl = 2;
			}
			if(statc[2] == 7) {
				skip_viewbg = !skip_viewbg;
				reload_background = 1;
			}
			if(statc[2] == 8) {
				tls_view--;
				if(tls_view < 0) tls_view = 2;
			}
			if(statc[2] == 9) {
				top_frame = !top_frame;
				reload_background = 1;
			}
			if(statc[2] == 10) empty_spin_field = !empty_spin_field;
			if(statc[2] == 11) {
				breakmax--;
				if(breakmax < 0) breakmax = 100;
			}
			if(statc[2] == 12) show_gpoint = !show_gpoint;
			if(statc[2] == 13) {
				blockflash--;
				if(blockflash < 0) blockflash = 2;
			}
			if(statc[2] == 14) {
				fldbgtype = !fldbgtype;
				reload_background = 1;
			}
			if(statc[2] == 15) english = !english;
			if(statc[2] == 16) {
				enable_b_to_b--;
				if(enable_b_to_b < 0) enable_b_to_b = 2;
			}
			if(statc[2] == 17) hide_score = !hide_score;
			if(statc[2] == 18) hide_grade = !hide_grade;
			if(statc[2] == 19) enable_bgfade = !enable_bgfade;
			if(statc[2] == 20) tomoyo_clear_erase = !tomoyo_clear_erase;
			if(statc[2] == 21) beginner_effect = !beginner_effect;
			if(statc[2] == 22) {
				enable_navigation--;
				if(enable_navigation < 0) enable_navigation = 2;
			}
			if(statc[2] == 23) {
				limit_navigation = limit_navigation - 100;
				if(limit_navigation < 0) limit_navigation = 1300;
			}
			if(statc[2] == 24) {
				limit_time_navigation = limit_time_navigation - 10;
				if(limit_time_navigation < 0) limit_time_navigation = 600;
			}
			if(statc[2] == 25) pause_visible = !pause_visible;
			if(statc[2] == 26) {
				p_backno--;
				if(p_backno < 0) p_backno = 14;
			}
			if(statc[2] == 27) enable_disp_lastline = !enable_disp_lastline;
			if(statc[2] == 28) {
				holdframetype--;
				if(holdframetype < 0) holdframetype = 2;
			}
			if(statc[2] == 29) {
				show_section_time--;
				if(show_section_time < 0) show_section_time = 3;
			}
			if(statc[2] == 30) timer_font_type = !timer_font_type;
			if(statc[2] == 31) block_shadow = !block_shadow;
			if(statc[2] == 32) {
				block_afterimage--;
				if(block_afterimage < 0) block_afterimage = 2;
			}
			if(statc[2] == 33) ace_frame = !ace_frame;
			if(statc[2] == 34) {
				display_combo--;
				if(display_combo < 0) display_combo = 2;
			}
			if(statc[2] == 35) {
				background_compatibility = !background_compatibility;
				reload_background = 1;
			}
			if(statc[2] == 36) disp_waits = !disp_waits;
			if(statc[2] == 37) d_disp_lineinfo = !d_disp_lineinfo;
			if(statc[2] == 38) refresh_timing = !refresh_timing;
			if(statc[2] == 39) {
				beffect_speed--;
				if(beffect_speed < 0) beffect_speed = 5;
			}
			if(statc[2] == 40) hidden_b_type = !hidden_b_type;
		}
		
		// →
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 3) ) {
			PlaySE(3);
			
			if(statc[2] == 0) {
				fldtr++;
				if(fldtr > 256) fldtr = 0;
				reload_background = 1;
			}
			if(statc[2] == 1) {
				breakeffect++;
				if(breakeffect > 5) breakeffect = 0;
				reload_graphics = 1;
			}
			if(statc[2] == 2) {
				breakgraphics = !breakgraphics;
				reload_graphics = 1;
			}
			if(statc[2] == 3) {
				dispnext++;
				if(dispnext > 6) dispnext = 0;
			}
			if(statc[2] == 4) {
				rule_name++;
				if(rule_name > 2) rule_name = 0;
			}
			if(statc[2] == 5) {
				show_fps++;
				if(show_fps > 2) show_fps = 0;
				if(show_fps != 2) SetConstParam("Caption", "HEBORIS LITE");
			}
			if(statc[2] == 6) {
				showctrl++;
				if(showctrl > 2) showctrl = 0;
			}
			if(statc[2] == 7) {
				skip_viewbg = !skip_viewbg;
				reload_background = 1;
			}
			if(statc[2] == 8) {
				tls_view++;
				if(tls_view > 2) tls_view = 0;
			}
			if(statc[2] == 9) {
				top_frame = !top_frame;
				reload_background = 1;
			}
			if(statc[2] == 10) empty_spin_field = !empty_spin_field;
			if(statc[2] == 11) {
				breakmax++;
				if(breakmax > 100) breakmax = 0;
			}
			if(statc[2] == 12) show_gpoint = !show_gpoint;
			if(statc[2] == 13) {
				blockflash++;
				if(blockflash > 2) blockflash = 0;
			}
			if(statc[2] == 14) {
				fldbgtype = !fldbgtype;
				reload_graphics = 1;
				reload_background = 1;
			}
			if(statc[2] == 15) english = !english;
			if(statc[2] == 16) {
				enable_b_to_b++;
				if(enable_b_to_b > 2) enable_b_to_b = 0;
			}
			if(statc[2] == 17) hide_score = !hide_score;
			if(statc[2] == 18) hide_grade = !hide_grade;
			if(statc[2] == 19) enable_bgfade = !enable_bgfade;
			if(statc[2] == 20) tomoyo_clear_erase = !tomoyo_clear_erase;
			if(statc[2] == 21) beginner_effect = !beginner_effect;
			if(statc[2] == 22) {
				enable_navigation++;
				if(enable_navigation > 2) enable_navigation = 0;
			}
			if(statc[2] == 23) {
				limit_navigation = limit_navigation + 100;
				if(limit_navigation > 1300) limit_navigation = 0;
			}
			if(statc[2] == 24) {
				limit_time_navigation = limit_time_navigation + 10;
				if(limit_time_navigation > 600) limit_time_navigation = 0;
			}
			if(statc[2] == 25) pause_visible = !pause_visible;
			if(statc[2] == 26) {
				p_backno++;
				if(p_backno > 14) p_backno = 0;
			}
			if(statc[2] == 27) enable_disp_lastline = !enable_disp_lastline;
			if(statc[2] == 28) {
				holdframetype++;
				if(holdframetype > 2) holdframetype = 0;
			}
			if(statc[2] == 29) {
				show_section_time++;
				if(show_section_time > 3) show_section_time = 0;
			}
			if(statc[2] == 30) timer_font_type = !timer_font_type;
			if(statc[2] == 31) block_shadow = !block_shadow;
			if(statc[2] == 32) {
				block_afterimage++;
				if(block_afterimage > 2) block_afterimage = 0;
			}
			if(statc[2] == 33) ace_frame = !ace_frame;
			if(statc[2] == 34) {
				display_combo++;
				if(display_combo > 2) display_combo = 0;
			}
			if(statc[2] == 35) {
				background_compatibility = !background_compatibility;
				reload_background = 1;
			}
			if(statc[2] == 36) disp_waits = !disp_waits;
			if(statc[2] == 37) d_disp_lineinfo = !d_disp_lineinfo;
			if(statc[2] == 38) refresh_timing = !refresh_timing;
			if(statc[2] == 39) {
				beffect_speed++;
				if(beffect_speed > 5) beffect_speed = 0;
			}
			if(statc[2] == 40) hidden_b_type = !hidden_b_type;
		}
		
		// カーソル移動
		padRepeat2(0);
		
		// ↑
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 0) ) {
			PlaySE(5);
			
			statc[2]--;
			if(statc[2] < 0) statc[2] = 40;
		}
		
		// ↓
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 1) ) {
			PlaySE(5);
			
			statc[2]++;
			if(statc[2] > 40) statc[2] = 0;
		}
		
		// キャンセル
		if( getPushState(0, 5) ) {
			return;
		}
		
		// 決定
		if( getPushState(0, 4) ) {
			PlaySE(10);
			return;
		}
		
		if(!refresh_timing) spriteTime();
	}
}

// SOUND SETTING
void config_sound() {
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		printFont(1,  1, "SOUND SETTING", fontc[rots[0]]);
		
		printFont(1,  3 + statc[3], "b", fontc[rots[0]]);
		
		// 設定項目名表示
		printFont(2,  3, "[SOUND TEST]",    fontc[rots[0]] * (statc[3] ==  0));
		printFont(2,  4, "[MUSIC TEST]",    fontc[rots[0]] * (statc[3] ==  1));
		printFont(2,  5, "BGM           :", fontc[rots[0]] * (statc[3] ==  2));
		printFont(2,  6, "SE            :", fontc[rots[0]] * (statc[3] ==  3));
		printFont(2,  7, "BGM VOLUME    :", fontc[rots[0]] * (statc[3] ==  4));
		printFont(2,  8, "SE VOLUME     :", fontc[rots[0]] * (statc[3] ==  5));
		printFont(2,  9, "ROTATE SOUND  :", fontc[rots[0]] * (statc[3] ==  6));
		printFont(2, 10, "MOVE SOUND    :", fontc[rots[0]] * (statc[3] ==  7));
		printFont(2, 11, "SRS LANDING SE:", fontc[rots[0]] * (statc[3] ==  8));
		printFont(2, 12, "ENDING LOOP   :", fontc[rots[0]] * (statc[3] ==  9));
		printFont(2, 13, "B ENDING LOOP :", fontc[rots[0]] * (statc[3] == 10));
		printFont(2, 14, "HOLD SOUND    :", fontc[rots[0]] * (statc[3] == 11));
		printFont(2, 15, "BGM FADE TIME :", fontc[rots[0]] * (statc[3] == 12));
		
		// 設定値表示
		if(bgm == 0) sprintf(string[0], "OFF");
		if(bgm == 1) sprintf(string[0], "MIDI");
		if(bgm == 2) sprintf(string[0], "WAVE");
		if(bgm == 3) sprintf(string[0], "MP3");
		if(bgm == 4) sprintf(string[0], "MIDI (MULTI)");
		if(bgm == 5) sprintf(string[0], "WAVE (ONDEMAND)");
		if(bgm == 6) sprintf(string[0], "MP3 (ONDEMAND)");
		printFont(18, 5, string[0], fontc[rots[0]] * (statc[3] == 2));
		
		if(se == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFont(18, 6, string[0], fontc[rots[0]] * (statc[3] == 3));
		
		sprintf(string[0], "%d", bgmvolume);
		printFont(18, 7, string[0], fontc[rots[0]] * (statc[3] == 4));
		
		sprintf(string[0], "%d", sevolume);
		printFont(18, 8, string[0], fontc[rots[0]] * (statc[3] == 5));
		
		if(rotate_sound == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFont(18, 9, string[0], fontc[rots[0]] * (statc[3] == 6));
		
		if(move_sound == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFont(18, 10, string[0], fontc[rots[0]] * (statc[3] == 7));
		
		if(world_move_sound == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFont(18, 11, string[0], fontc[rots[0]] * (statc[3] == 8));
		
		if(sound_ending_loop == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFont(18, 12, string[0], fontc[rots[0]] * (statc[3] == 9));
		
		if(sound_beginner_ending_loop == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFont(18, 13, string[0], fontc[rots[0]] * (statc[3] == 10));
		
		if(hold_sound == 0) sprintf(string[0], "OFF");
		if(hold_sound == 1) sprintf(string[0], "IHS ONLY");
		if(hold_sound == 2) sprintf(string[0], "NO-IHS ONLY");
		if(hold_sound == 3) sprintf(string[0], "ON");
		printFont(18, 14, string[0], fontc[rots[0]] * (statc[3] == 11));
		
		sprintf(string[0], "%d", fadesetting);
		printFont(18, 15, string[0], fontc[rots[0]] * (statc[3] == 12));
		
		// 設定値変更
		padRepeat(0);
		
		// ←
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 2) ) {
			PlaySE(3);
			
			if(statc[3] == 2) {
				bgm--;
				if(bgm < 0) bgm = 6;
				reload_bgm = 1;
			}
			if(statc[3] == 3) {
				se = !se;
				reload_se = 1;
			}
			if(statc[3] == 4) {
				bgmvolume--;
				if(bgmvolume < -10000) bgmvolume = 0;
			}
			if(statc[3] == 5) {
				sevolume--;
				if(sevolume < -10000) sevolume = 0;
			}
			if(statc[3] == 6) rotate_sound = !rotate_sound;
			if(statc[3] == 7) move_sound = !move_sound;
			if(statc[3] == 8) world_move_sound = !world_move_sound;
			if(statc[3] == 9) sound_ending_loop = !sound_ending_loop;
			if(statc[3] == 10) sound_beginner_ending_loop = !sound_beginner_ending_loop;
			if(statc[3] == 11) {
				hold_sound--;
				if(hold_sound < 0) hold_sound = 3;
			}
			if(statc[3] == 12) {
				fadesetting--;
				if(fadesetting < 0) fadesetting = 10000;
			}
		}
		
		// →
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 3) ) {
			PlaySE(3);
			
			if(statc[3] == 2) {
				bgm++;
				if(bgm > 6) bgm = 0;
				reload_bgm = 1;
			}
			if(statc[3] == 3) {
				se = !se;
				reload_se = 1;
			}
			if(statc[3] == 4) {
				bgmvolume++;
				if(bgmvolume > 0) bgmvolume = -10000;
			}
			if(statc[3] == 5) {
				sevolume++;
				if(sevolume > 0) sevolume = -10000;
			}
			if(statc[3] == 6) rotate_sound = !rotate_sound;
			if(statc[3] == 7) move_sound = !move_sound;
			if(statc[3] == 8) world_move_sound = !world_move_sound;
			if(statc[3] == 9) sound_ending_loop = !sound_ending_loop;
			if(statc[3] == 10) sound_beginner_ending_loop = !sound_beginner_ending_loop;
			if(statc[3] == 11) {
				hold_sound++;
				if(hold_sound > 3) hold_sound = 0;
			}
			if(statc[3] == 12) {
				fadesetting++;
				if(fadesetting > 10000) fadesetting = 0;
			}
		}
		
		// カーソル移動
		padRepeat2(0);
		
		// ↑
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 0) ) {
			PlaySE(5);
			
			statc[3]--;
			if(statc[3] < 0) statc[3] = 12;
		}
		
		// ↓
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 1) ) {
			PlaySE(5);
			
			statc[3]++;
			if(statc[3] > 12) statc[3] = 0;
		}
		
		// キャンセル
		if( getPushState(0, 5) ) {
			return;
		}
		
		// 決定
		if( getPushState(0, 4) ) {
			PlaySE(10);
			
			if(statc[3] == 0)
				config_sound_test();
			else if(statc[3] == 1)
				config_sound_music();
			else
				return;
		}
		
		if(!refresh_timing) spriteTime();
	}
}

// SOUND TEST
void config_sound_test() {
	statc[10] = 0;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		printFont(1, 1, "SOUND TEST", fontc[rots[0]]);
		
		printFont(1, 3, "b", fontc[rots[0]]);
		
		// 設定項目名表示
		printFont(2, 3, "SOUND NO.     :", fontc[rots[0]]);
		
		// 現在地点
		sprintf(string[0], "POS:%d", GetPosWave(statc[10]));
		printFont(1, 5, string[0], 0);
		
		// 操作説明
		printFont(1,  7, "PRESS A BUTTON TO PLAY", 0);
		printFont(1,  8, "PRESS B BUTTON TO EXIT", 0);
		printFont(1,  9, "PRESS C BUTTON TO STOP", 0);
		printFont(1, 10, "PRESS D BUTTON TO PAUSE", 0);
		
		// 設定値表示
		sprintf(string[0], "%d", statc[10]);
		printFont(18, 3, string[0], fontc[rots[0]]);
		
		// 設定値変更
		padRepeat(0);
		
		// ←
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 2) ) {
			statc[10]--;
			if(statc[10] < 0) statc[10] = 80;
		}
		
		// →
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 3) ) {
			statc[10]++;
			if(statc[10] > 80) statc[10] = 0;
		}
		
		// キャンセル
		if( getPushState(0, 5) ) {
			StopAllWaves();
			StopAllBGM();
			statc[10] = 0;
			return;
		}
		
		// 決定
		if( getPushState(0, 4) ) {
			StopAllWaves();
			StopAllBGM();
			PlaySE(statc[10]);
		}
		
		// Cボタンで全音声停止
		if( getPushState(0, 6) ) {
			StopAllWaves();
			StopAllBGM();
		}
		
		// Dボタンで一時停止
		if( getPushState(0, 7) ) {
			if(IsPlayWave(statc[10])) PauseWave(statc[10]);
			else ReplayWave(statc[10]);
		}
		
		if(!refresh_timing) spriteTime();
	}
}

// MUSIC TEST
void config_sound_music() {
	StopAllBGM();
	bgmlv = 0;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		printFont(1,  1, "MUSIC TEST", fontc[rots[0]]);
		
		printFont(1,  3, "b", fontc[rots[0]]);
		
		// 設定項目名表示
		printFont(2,  3, "MUSIC NO.     :", fontc[rots[0]]);
		
		// 設定値表示
		sprintf(string[0], "%d", bgmlv + 1);
		printFont(18, 3, string[0], fontc[rots[0]]);
		
		// 曲名
		printFont(3, 4, music_name[bgmlv], fontc[rots[0]]);
		
		// 現在地点
		sprintf(string[0], "POS:%d", GetPosWave(60 + bgmlv));
		printFont(1, 5, string[0], 0);
		
		// 操作説明
		printFont(1,  7, "PRESS A BUTTON TO PLAY", 0);
		printFont(1,  8, "PRESS B BUTTON TO EXIT", 0);
		printFont(1,  9, "PRESS C BUTTON TO STOP", 0);
		printFont(1, 10, "PRESS D BUTTON TO PAUSE", 0);
		
		// 設定値変更
		padRepeat(0);
		
		// ←
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 2) ) {
			bgmlv--;
			if(bgmlv < 0) bgmlv = 20;
		}
		
		// →
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 3) ) {
			bgmlv++;
			if(bgmlv > 20) bgmlv = 0;
		}
		
		// キャンセル
		if( getPushState(0, 5) ) {
			StopAllBGM();
			return;
		}
		
		// 決定
		if( getPushState(0, 4) ) {
			changeBGM();
		}
		
		// Cボタンで全音声停止
		if( getPushState(0, 6) ) {
			StopAllBGM();
		}
		
		// Dボタンで一時停止
		if( getPushState(0, 7) ) {
			if(IsPlayWave(60 + bgmlv)) PauseWave(60 + bgmlv);
			else ReplayWave(60 + bgmlv);
		}
		
		if(bgm >= 2) bgmFadeout();
		if(!refresh_timing) spriteTime();
	}
}

// INPUT SETTING
void config_input() {
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		printFont(1, 1, "INPUT SETTING", fontc[rots[0]]);
		
		printFont(1, 3 + statc[4], "b", fontc[rots[0]]);
		
		// 設定項目名表示
		printFont(2,  3, "[KEYBOARD 1P]",              fontc[rots[0]] * (statc[4] == 0));
		printFont(2,  4, "[KEYBOARD 2P]",              fontc[rots[0]] * (statc[4] == 1));
		printFont(2,  5, "[FUNCTION KEY]",             fontc[rots[0]] * (statc[4] == 2));
		printFont(2,  6, "[JOYSTICK 1P]",              fontc[rots[0]] * (statc[4] == 3));
		printFont(2,  7, "[JOYSTICK 2P]",              fontc[rots[0]] * (statc[4] == 4));
		printFont(2,  8, "[JOYSTICK FUNCTION KEY 1P]", fontc[rots[0]] * (statc[4] == 5));
		printFont(2,  9, "[JOYSTICK FUNCTION KEY 2P]", fontc[rots[0]] * (statc[4] == 6));
		printFont(2, 10, "[INPUT TEST]",               fontc[rots[0]] * (statc[4] == 7));
		printFont(2, 11, "JOYSTICK BUTTONS:",          fontc[rots[0]] * (statc[4] == 8));
		
		sprintf(string[0], "%d", joykeyButtonNum);
		printFont(19, 11, string[0], fontc[rots[0]] * (statc[4] == 8));
		
		// カーソル移動
		padRepeat(0);
		padRepeat2(0);
		
		// ↑
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 0) ) {
			PlaySE(5);
			
			statc[4]--;
			if(statc[4] < 0) statc[4] = 8;
		}
		
		// ↓
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 1) ) {
			PlaySE(5);
			
			statc[4]++;
			if(statc[4] > 8) statc[4] = 0;
		}
		
		// ←
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 2) ) {
			if(statc[4] == 8) {
				PlaySE(3);
				joykeyButtonNum--;
				if(joykeyButtonNum < 0) joykeyButtonNum = 99;
			}
		}
		
		// →
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 3) ) {
			if(statc[4] == 8) {
				PlaySE(3);
				joykeyButtonNum++;
				if(joykeyButtonNum > 99) joykeyButtonNum = 0;
			}
		}
		
		// キャンセル
		if( getPushState(0, 5) ) {
			SetJoystickButtonSetting();
			return;
		}
		
		// 決定
		if( getPushState(0, 4) ) {
			PlaySE(19);
			SetJoystickButtonSetting();
			
			if(statc[4] == 0) config_input_keyboard(0, 0);
			else if(statc[4] == 1) config_input_keyboard(1, 0);
			else if(statc[4] == 2) config_input_function_key();
			else if(statc[4] == 3) config_input_joystick(0);
			else if(statc[4] == 4) config_input_joystick(1);
			else if(statc[4] == 5) config_input_function_joy(0);
			else if(statc[4] == 6) config_input_function_joy(1);
			else if(statc[4] == 7) config_input_test();
			else return;
		}
		
		if(!refresh_timing) spriteTime();
	}
}

// KEYBOARD
void config_input_keyboard(int player, int first) {
	int i;
	int nkey[8];
	
	statc[11] = 0;
	
	for(i = 0; i < 8; i++) nkey[i] = 0;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		sprintf(string[0], "%dP KEYBOARD SETTING", player + 1);
		printFont(1, 1, string[0], fontc[rots[player]]);
		
		printFont(2,  3, "UP            :", fontc[rots[player]] * (statc[11] == 0));
		printFont(2,  4, "DOWN          :", fontc[rots[player]] * (statc[11] == 1));
		printFont(2,  5, "LEFT          :", fontc[rots[player]] * (statc[11] == 2));
		printFont(2,  6, "RIGHT         :", fontc[rots[player]] * (statc[11] == 3));
		printFont(2,  7, "A (L/R-ROT)   :", fontc[rots[player]] * (statc[11] == 4));
		printFont(2,  8, "B (R/L-ROT)   :", fontc[rots[player]] * (statc[11] == 5));
		printFont(2,  9, "C (L/R-ROT)   :", fontc[rots[player]] * (statc[11] == 6));
		printFont(2, 10, "D (HOLD)      :", fontc[rots[player]] * (statc[11] == 7));
		
		// 設定状況表示
		for(i = 0; i < 8; i++) {
			if(nkey[i]) {
				sprintf(string[0], "%d", nkey[i]);
				printFont(18, 3 + i, string[0], digitc[rots[player]]);
			}
		}
		
		if(statc[11] < 8) {
			printFont(1, 3 + statc[11], "b", fontc[rots[player]]);
			
			for(i = 0; i < 256; i++) {
				// キーが押された
				if( IsPushKey(i) ) {
					PlaySE(5);
					if(i == key_del) nkey[statc[11]] = 0;
					else nkey[statc[11]] = i;
					statc[11]++;
					break;
				}
			}
			
			printFont(2, 12, "DELETE (KEYBOARD) : NO ASSIGN", digitc[rots[player]]);
		} else {
			if(!first)
				printFont(2, 12, "OK[ENTER] / RETRY[DEL] / CANCEL[BS]", digitc[rots[player]]);
			else
				printFont(2, 12, "OK[ENTER] / RETRY[DEL]", digitc[rots[player]]);
			
			// OK
			if( IsPushKey(key_enter) ) {
				PlaySE(10);
				for(i = 0; i < 8; i++) keyAssign[i + player * 10] = nkey[i];
				return;
			}
			
			// RETRY
			if( IsPushKey(key_del) ) {
				PlaySE(3);
				statc[11] = 0;
				for(i = 0; i < 8; i++) nkey[i] = 0;
			}
			
			// CANCEL
			if( (IsPushKey(key_bs) != 0) && (first == 0) ) {
				return;
			}
		}
		
		if(!refresh_timing) spriteTime();
	}
}

// FUNCTION KEY
void config_input_function_key() {
	int i;
	int nkey[10];
	
	statc[11] = 0;
	
	for(i = 0; i < 10; i++) nkey[i] = 0;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		printFont(1, 1, "FUNCTION KEY SETTING", fontc[rots[0]]);
		
		printFont(2,  3, "PAUSE (1P)    :", fontc[rots[0]] * (statc[11] == 0));
		printFont(2,  4, "PAUSE (2P)    :", fontc[rots[0]] * (statc[11] == 1));
		printFont(2,  5, "SHOW NEXT (1P):", fontc[rots[0]] * (statc[11] == 2));
		printFont(2,  6, "SHOW NEXT (2P):", fontc[rots[0]] * (statc[11] == 3));
		printFont(2,  7, "GIVEUP        :", fontc[rots[0]] * (statc[11] == 4));
		printFont(2,  8, "SCREEN SHOT   :", fontc[rots[0]] * (statc[11] == 5));
		printFont(2,  9, "STAGE SKIP(1P):", fontc[rots[0]] * (statc[11] == 6));
		printFont(2, 10, "STAGE SKIP(2P):", fontc[rots[0]] * (statc[11] == 7));
		printFont(2, 11, "FPS +1        :", fontc[rots[0]] * (statc[11] == 8));
		printFont(2, 12, "FPS -1        :", fontc[rots[0]] * (statc[11] == 9));
		
		// 設定状況表示
		for(i = 0; i < 10; i++) {
			if(nkey[i]) {
				sprintf(string[0], "%d", nkey[i]);
				printFont(18, 3 + i, string[0], digitc[rots[0]]);
			}
		}
		
		if(statc[11] < 10) {
			printFont(1, 3 + statc[11], "b", fontc[rots[0]]);
			
			for(i = 0; i < 256; i++) {
				// キーが押された
				if( IsPushKey(i) ) {
					PlaySE(5);
					if(i == key_del) nkey[statc[11]] = 0;
					else nkey[statc[11]] = i;
					statc[11]++;
					break;
				}
			}
			
			printFont(2, 14, "DELETE (KEYBOARD) : NO ASSIGN", digitc[rots[0]]);
		} else {
			printFont(2, 14, "OK[ENTER] / RETRY[DEL] / CANCEL[BS]", digitc[rots[0]]);
			
			// OK
			if( IsPushKey(key_enter) ) {
				PlaySE(10);
				
				pause_key[0]  = nkey[0];
				pause_key[1]  = nkey[1];
				hnext_key[0]  = nkey[2];
				hnext_key[1]  = nkey[3];
				giveup_key    = nkey[4];
				ss_key        = nkey[5];
				skip_key[0]   = nkey[6];
				skip_key[1]   = nkey[7];
				fps_plus_key  = nkey[8];
				fps_minus_key = nkey[9];
				
				return;
			}
			
			// RETRY
			if( IsPushKey(key_del) ) {
				PlaySE(3);
				statc[11] = 0;
				for(i = 0; i < 10; i++) nkey[i] = 0;
			}
			
			// CANCEL
			if( IsPushKey(key_bs) ) {
				return;
			}
		}
		
		if(!refresh_timing) spriteTime();
	}
}

// JOYSTICK
void config_input_joystick(int player) {
	int i;
	int nkey[8];
	
	statc[11] = 0;
	
	for(i = 0; i < 8; i++) nkey[i] = 0;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		sprintf(string[0], "%dP JOYSTICK SETTING", player + 1);
		printFont(1, 1, string[0], fontc[rots[player]]);
		
		printFont(2,  3, "UP            :", fontc[rots[player]] * (statc[11] == 0));
		printFont(2,  4, "DOWN          :", fontc[rots[player]] * (statc[11] == 1));
		printFont(2,  5, "LEFT          :", fontc[rots[player]] * (statc[11] == 2));
		printFont(2,  6, "RIGHT         :", fontc[rots[player]] * (statc[11] == 3));
		printFont(2,  7, "A (L/R-ROT)   :", fontc[rots[player]] * (statc[11] == 4));
		printFont(2,  8, "B (R/L-ROT)   :", fontc[rots[player]] * (statc[11] == 5));
		printFont(2,  9, "C (L/R-ROT)   :", fontc[rots[player]] * (statc[11] == 6));
		printFont(2, 10, "D (HOLD)      :", fontc[rots[player]] * (statc[11] == 7));
		
		// 設定状況表示
		for(i = 0; i < 8; i++) {
			if(nkey[i]) {
				sprintf(string[0], "%d", nkey[i]);
				printFont(18, 3 + i, string[0], digitc[rots[player]]);
			}
		}
		
		if(statc[11] < 8) {
			printFont(1, 3 + statc[11], "b", fontc[rots[player]]);
			
			for(i = 0; i < joykeyButtonNum; i++) {
				// ボタンが押された
				SelectJoyStick(player);
				
				if( IsPushJoyKey(i) ) {
					PlaySE(5);
					nkey[statc[11]] = i;
					statc[11]++;
					break;
				}
			}
			
			if( IsPushKey(key_del) ) {
				PlaySE(5);
				nkey[statc[11]] = -1;
				statc[11]++;
			}
			
			printFont(2, 12, "BACKSPACE (KEYBOARD) : CANCEL", digitc[rots[player]]);
			printFont(2, 13, "DELETE (KEYBOARD)    : NO ASSIGN", digitc[rots[player]]);
			
			if( IsPushKey(key_bs) ) {
				return;
			}
		} else {
			printFont(2, 12, "OK[ENTER] / RETRY[DEL] / CANCEL[BS]", digitc[rots[player]]);
			
			// OK
			if( IsPushKey(key_enter) ) {
				PlaySE(10);
				for(i = 0; i < 8; i++) joykeyAssign[i + player * 10] = nkey[i];
				return;
			}
			
			// RETRY
			if( IsPushKey(key_del) ) {
				PlaySE(3);
				statc[11] = 0;
				for(i = 0; i < 8; i++) nkey[i] = 0;
			}
			
			// CANCEL
			if( IsPushKey(key_bs) ) {
				return;
			}
		}
		
		if(!refresh_timing) spriteTime();
	}
}

// JOYSTICK FUNCTION KEY
void config_input_function_joy(int player) {
	int i;
	int nkey[7];
	
	statc[11] = 0;
	
	for(i = 0; i < 7; i++) nkey[i] = 0;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		sprintf(string[0], "%dP JOYSTICK FUNCTION KEY SETTING", player + 1);
		printFont(1, 1, string[0], fontc[rots[player]]);
		
		printFont(2, 3, "PAUSE          :", fontc[rots[player]] * (statc[11] == 0));
		printFont(2, 4, "SHOW NEXT      :", fontc[rots[player]] * (statc[11] == 1));
		printFont(2, 5, "GIVEUP         :", fontc[rots[player]] * (statc[11] == 2));
		printFont(2, 6, "SCREEN SHOT    :", fontc[rots[player]] * (statc[11] == 3));
		printFont(2, 7, "STAGE SKIP     :", fontc[rots[player]] * (statc[11] == 4));
		printFont(2, 8, "FPS +1         :", fontc[rots[player]] * (statc[11] == 5));
		printFont(2, 9, "FPS -1         :", fontc[rots[player]] * (statc[11] == 6));
		
		// 設定状況表示
		for(i = 0; i < 7; i++) {
			if(nkey[i]) {
				sprintf(string[0], "%d", nkey[i]);
				printFont(19, 3 + i, string[0], digitc[rots[player]]);
			}
		}
		
		if(statc[11] < 7) {
			printFont(1, 3 + statc[11], "b", fontc[rots[player]]);
			
			for(i = 0; i < joykeyButtonNum; i++) {
				// ボタンが押された
				SelectJoyStick(player);
				
				if( IsPushJoyKey(i) ) {
					PlaySE(5);
					nkey[statc[11]] = i;
					statc[11]++;
					break;
				}
			}
			
			if( IsPushKey(key_del) ) {
				PlaySE(5);
				nkey[statc[11]] = -1;
				statc[11]++;
			}
			
			printFont(2, 12, "BACKSPACE (KEYBOARD) : CANCEL", digitc[rots[player]]);
			printFont(2, 13, "DELETE (KEYBOARD)    : NO ASSIGN", digitc[rots[player]]);
			
			if( IsPushKey(key_bs) ) {
				return;
			}
		} else {
			printFont(2, 12, "OK[ENTER] / RETRY[DEL] / CANCEL[BS]", digitc[rots[player]]);
			
			// OK
			if( IsPushKey(key_enter) ) {
				PlaySE(10);
				
				joy_pause_key[player]     = nkey[0];
				joy_hnext_key[player]     = nkey[1];
				joy_giveup_key[player]    = nkey[2];
				joy_ss_key[player]        = nkey[3];
				joy_skip_key[player]      = nkey[4];
				joy_fps_plus_key[player]  = nkey[5];
				joy_fps_minus_key[player] = nkey[6];
				
				return;
			}
			
			// RETRY
			if( IsPushKey(key_del) ) {
				PlaySE(3);
				statc[11] = 0;
				for(i = 0; i < 7; i++) nkey[i] = 0;
			}
			
			// CANCEL
			if( IsPushKey(key_bs) ) {
				return;
			}
		}
		
		if(!refresh_timing) spriteTime();
	}
}

// INPUT TEST
void config_input_test() {
	int i, player, tmp;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		printFont(1, 1, "INPUT TEST", fontc[rots[0]]);
		
		printFont(2,  3, "KEY NAME      :", 4);
		printFont(18, 3, "1P", 2);
		if(maxPlay) printFont(21, 3, "2P", 1);
		
		printFont(2,  4, "UP            :", 0);
		printFont(2,  5, "DOWN          :", 0);
		printFont(2,  6, "LEFT          :", 0);
		printFont(2,  7, "RIGHT         :", 0);
		printFont(2,  8, "A (L/R-ROT)   :", 0);
		printFont(2,  9, "B (R/L-ROT)   :", 0);
		printFont(2, 10, "C (L/R-ROT)   :", 0);
		printFont(2, 11, "D (HOLD)      :", 0);
		
		printFont(2, 13, "PAUSE         :", 0);
		printFont(2, 14, "SHOW NEXT     :", 0);
		printFont(2, 15, "STAGE SKIP    :", 0);
		
		printFont(2, 17, "GIVEUP        :", 0);
		printFont(2, 18, "SCREEN SHOT   :", 0);
		printFont(2, 19, "FPS +1        :", 0);
		printFont(2, 20, "FPS -1        :", 0);
		
		printFont(2, 25, "BACKSPACE (KEYBOARD) : EXIT", digitc[rots[0]]);
		
		for(player = 0; player <= maxPlay; player++) {
			for(i = 0; i < 8; i++) {
				tmp = getPressState(player, i);
				sprintf(string[0], "%d", tmp);
				printFont(18 + player * 3, 4 + i, string[0], tmp * 2);
			}
			
			tmp = (IsPressKey(pause_key[player]) || getJoyPressState(player, joy_pause_key[player]));
			sprintf(string[0], "%d", tmp);
			printFont(18 + player * 3, 13, string[0], tmp * 1);
			
			tmp = (IsPressKey(hnext_key[player]) || getJoyPressState(player, joy_hnext_key[player]));
			sprintf(string[0], "%d", tmp);
			printFont(18 + player * 3, 14, string[0], tmp * 1);
			
			tmp = (IsPressKey(skip_key[player]) || getJoyPressState(player, joy_skip_key[player]));
			sprintf(string[0], "%d", tmp);
			printFont(18 + player * 3, 15, string[0], tmp * 1);
		}
		
		tmp = (IsPressKey(giveup_key) || getJoyPressState(0, joy_giveup_key[0]) || getJoyPressState(1, joy_giveup_key[1]));
		sprintf(string[0], "%d", tmp);
		printFont(18, 17, string[0], tmp * 4);
		
		tmp = (IsPressKey(ss_key) || getJoyPressState(0, joy_ss_key[0]) || getJoyPressState(1, joy_ss_key[1]));
		sprintf(string[0], "%d", tmp);
		printFont(18, 18, string[0], tmp * 4);
		
		tmp = (IsPressKey(fps_plus_key) || getJoyPressState(0, joy_fps_plus_key[0]) || getJoyPressState(1, joy_fps_plus_key[1]));
		sprintf(string[0], "%d", tmp);
		printFont(18, 19, string[0], tmp * 4);
		
		tmp = (IsPressKey(fps_minus_key) || getJoyPressState(0, joy_fps_minus_key[0]) || getJoyPressState(1, joy_fps_minus_key[1]));
		sprintf(string[0], "%d", tmp);
		printFont(18, 20, string[0], tmp * 4);
		
		// BACKSPACE
		if( IsPushKey(key_bs) ) {
			return;
		}
		
		if(!refresh_timing) spriteTime();
	}
}

// CUSTOM RULE
void config_custom() {
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		printFont(1,  1, "CUSTOM RULE", fontc[9]);
		
		printFont(1,  3 + statc[5], "b", fontc[9]);
		
		// 設定項目名表示
		printFont(2,  3, "ROTATION TYPE :", fontc[9] * (statc[5] ==  0));
		printFont(2,  4, "HARD DROP LOCK:", fontc[9] * (statc[5] ==  1));
		printFont(2,  5, "SOFT DROP LOCK:", fontc[9] * (statc[5] ==  2));
		printFont(2,  6, "SOFT DROP SPD :", fontc[9] * (statc[5] ==  3));
		printFont(2,  7, "ARE           :", fontc[9] * (statc[5] ==  4));
		printFont(2,  8, "BLOCK COLOR   :", fontc[9] * (statc[5] ==  5));
		printFont(2,  9, "LOCK RESET    :", fontc[9] * (statc[5] ==  6));
		printFont(2, 10, "LOCK SOUND    :", fontc[9] * (statc[5] ==  7));
		printFont(2, 11, "USE NEW ARS   :", fontc[9] * (statc[5] ==  8));
		printFont(2, 12, "MOVE LIMIT    :", fontc[9] * (statc[5] ==  9));
		printFont(2, 13, "ROTATE LIMIT  :", fontc[9] * (statc[5] == 10));
		printFont(2, 14, "BLOCK GRAPHICS:", fontc[9] * (statc[5] == 11));
		printFont(2, 15, "180 ROTATION  :", fontc[9] * (statc[5] == 12));
		if(!english) {
			printFont(2, 16, "MAX YOKOTAME  :", fontc[9] * (statc[5] == 13));
		} else {
			printFont(2, 16, "MAX DAS       :", fontc[9] * (statc[5] == 13));
		}
		printFont(2, 17, "[] BACKGROUND :", fontc[9] * (statc[5] == 14));
		
		// 設定値表示
		if(rule_rot[9] == 0) sprintf(string[0], "ARS");
		if(rule_rot[9] == 1) sprintf(string[0], "SRS");
		if(rule_rot[9] == 2) sprintf(string[0], "DRS");
		printFont(18, 3, string[0], fontc[9] * (statc[5] == 0) );
		
		if(rule_hard_lock[9] == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFont(18, 4, string[0], fontc[9] * (statc[5] == 1) );
		
		if(rule_soft_lock[9] == 0) sprintf(string[0], "OFF");
		if(rule_soft_lock[9] == 1) sprintf(string[0], "ON");
		if(rule_soft_lock[9] == 2) sprintf(string[0], "ONLY 1G OR FASTER");
		printFont(18, 5, string[0], fontc[9] * (statc[5] == 2) );
		
		if(rule_soft_speed[9] == 0) sprintf(string[0], "e 0.5");
		if(rule_soft_speed[9] == 1) sprintf(string[0], "e 1.0");
		if(rule_soft_speed[9] == 2) sprintf(string[0], "e 1.5");
		if(rule_soft_speed[9] == 3) sprintf(string[0], "e 2.0");
		printFont(18, 6, string[0], fontc[9] * (statc[5] == 3) );
		
		if(rule_are[9] == 0) sprintf(string[0], "OFF");
		if(rule_are[9] == 1) sprintf(string[0], "ON");
		if(rule_are[9] == 2) sprintf(string[0], "ON (WITH CANCEL)");
		printFont(18, 7, string[0], fontc[9] * (statc[5] == 4) );
		
		if(rule_color[9] == 0) sprintf(string[0], "CLASSIC");
		if(rule_color[9] == 1) sprintf(string[0], "WORLD");
		printFont(18, 8, string[0], fontc[9] * (statc[5] == 5) );
		
		if(rule_lock_reset[9] == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFont(18, 9, string[0], fontc[9] * (statc[5] == 6) );
		
		if(rule_lock_sound[9] == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFont(18, 10, string[0], fontc[9] * (statc[5] == 7) );
		
		if(rule_ars_extrot[9] == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFont(18, 11, string[0], fontc[9] * (statc[5] == 8) );
		
		if(rule_lock_limit[9] == 0) sprintf(string[0], "NO LIMIT");
		else sprintf(string[0], "%d", rule_lock_limit[9]);
		printFont(18, 12, string[0], fontc[9] * (statc[5] == 9) );
		
		if(rule_rot_limit[9] == 0) sprintf(string[0], "NO LIMIT");
		else sprintf(string[0], "%d", rule_rot_limit[9]);
		printFont(18, 13, string[0], fontc[9] * (statc[5] == 10) );
		
		sprintf(string[0], "%d", rule_graphics[9]);
		printFont(18, 14, string[0], fontc[9] * (statc[5] == 11));
		
		if(rule_180rot[9] == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFont(18, 15, string[0], fontc[9] * (statc[5] == 12));
		
		if(rule_max_waitt[9] >= 99) sprintf(string[0], "INFINITE");
		else sprintf(string[0], "%d", rule_max_waitt[9]);
		printFont(18, 16, string[0], fontc[9] * (statc[5] == 13));
		
		if(rule_oblk_bg[9] == 0) sprintf(string[0], "OFF");
		if(rule_oblk_bg[9] == 1) sprintf(string[0], "WHITE");
		if(rule_oblk_bg[9] == 2) sprintf(string[0], "BLACK");
		printFont(18, 17, string[0], fontc[9] * (statc[5] == 14));
		
		// 設定値変更
		padRepeat(0);
		
		// ←
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 2) ) {
			PlaySE(3);
			
			if(statc[5] == 0) {
				rule_rot[9]--;
				if(rule_rot[9] < 0) rule_rot[9] = 2;
			}
			if(statc[5] == 1) rule_hard_lock[9] = !rule_hard_lock[9];
			if(statc[5] == 2) {
				rule_soft_lock[9]--;
				if(rule_soft_lock[9] < 0) rule_soft_lock[9] = 2;
			}
			if(statc[5] == 3) {
				rule_soft_speed[9]--;
				if(rule_soft_speed[9] < 0) rule_soft_speed[9] = 3;
			}
			if(statc[5] == 4) {
				rule_are[9]--;
				if(rule_are[9] < 0) rule_are[9] = 2;
			}
			if(statc[5] == 5) rule_color[9] = !rule_color[9];
			if(statc[5] == 6) rule_lock_reset[9] = !rule_lock_reset[9];
			if(statc[5] == 7) rule_lock_sound[9] = !rule_lock_sound[9];
			if(statc[5] == 8) rule_ars_extrot[9] = !rule_ars_extrot[9];
			if(statc[5] == 9) {
				rule_lock_limit[9]--;
				if(rule_lock_limit[9] < 0) rule_lock_limit[9] = 128;
			}
			if(statc[5] == 10) {
				rule_rot_limit[9]--;
				if(rule_rot_limit[9] < 0) rule_rot_limit[9] = 128;
			}
			if(statc[5] == 11) {
				rule_graphics[9]--;
				if(rule_graphics[9] < 0) rule_graphics[9] = 7;
			}
			if(statc[5] == 12) rule_180rot[9] = !rule_180rot[9];
			if(statc[5] == 13) {
				rule_max_waitt[9]--;
				if(rule_max_waitt[9] < 0) rule_max_waitt[9] = 99;
			}
			if(statc[5] == 14) {
				rule_oblk_bg[9]--;
				if(rule_oblk_bg[9] < 0) rule_oblk_bg[9] = 2;
			}
		}
		
		// →
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 3) ) {
			PlaySE(3);
			
			if(statc[5] == 0) {
				rule_rot[9]++;
				if(rule_rot[9] > 2) rule_rot[9] = 0;
			}
			if(statc[5] == 1) rule_hard_lock[9] = !rule_hard_lock[9];
			if(statc[5] == 2) {
				rule_soft_lock[9]++;
				if(rule_soft_lock[9] > 2) rule_soft_lock[9] = 0;
			}
			if(statc[5] == 3) {
				rule_soft_speed[9]++;
				if(rule_soft_speed[9] > 3) rule_soft_speed[9] = 0;
			}
			if(statc[5] == 4) {
				rule_are[9]++;
				if(rule_are[9] > 2) rule_are[9] = 0;
			}
			if(statc[5] == 5) rule_color[9] = !rule_color[9];
			if(statc[5] == 6) rule_lock_reset[9] = !rule_lock_reset[9];
			if(statc[5] == 7) rule_lock_sound[9] = !rule_lock_sound[9];
			if(statc[5] == 8) rule_ars_extrot[9] = !rule_ars_extrot[9];
			if(statc[5] == 9) {
				rule_lock_limit[9]++;
				if(rule_lock_limit[9] > 128) rule_lock_limit[9] = 0;
			}
			if(statc[5] == 10) {
				rule_rot_limit[9]++;
				if(rule_rot_limit[9] > 128) rule_rot_limit[9] = 0;
			}
			if(statc[5] == 11) {
				rule_graphics[9]++;
				if(rule_graphics[9] > 7) rule_graphics[9] = 0;
			}
			if(statc[5] == 12) rule_180rot[9] = !rule_180rot[9];
			if(statc[5] == 13) {
				rule_max_waitt[9]++;
				if(rule_max_waitt[9] > 99) rule_max_waitt[9] = 0;
			}
			if(statc[5] == 14) {
				rule_oblk_bg[9]++;
				if(rule_oblk_bg[9] > 2) rule_oblk_bg[9] = 0;
			}
		}
		
		// カーソル移動
		padRepeat2(0);
		
		// ↑
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 0) ) {
			PlaySE(5);
			
			statc[5]--;
			if(statc[5] < 0) statc[5] = 14;
		}
		
		// ↓
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 1) ) {
			PlaySE(5);
			
			statc[5]++;
			if(statc[5] > 14) statc[5] = 0;
		}
		
		// キャンセル
		if( getPushState(0, 5) ) {
			return;
		}
		
		// 決定
		if( getPushState(0, 4) ) {
			PlaySE(10);
			return;
		}
		
		if(!refresh_timing) spriteTime();
	}
}

// FONT COLOR
void config_fontc() {
	int i;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		printFont(1, 1, "FONT COLOR", fontc[rots[0]]);
		
		printFont(1, 3 + statc[6], "b", fontc[rots[0]]);
		
		// 設定項目名表示
		for(i = 0; i < 10; i++) {
			getRuleNameEx(i, 0);
			printFont(2,  3 + i, string[0], fontc[rots[0]] * (statc[6] == i));
			printFont(2, 13 + i, string[0], fontc[rots[0]] * (statc[6] == 10 + i));
		}
		
		// 設定値表示
		for(i = 0; i < 10; i++) {
			// fontc
			sprintf(string[0], "FONT %d", fontc[i]);
			printFont(18, 3 + i, string[0], fontc[i]);
			
			// digitc
			sprintf(string[0], "DIGIT %d", digitc[i]);
			printFont(17, 13 + i, string[0], digitc[i]);
		}
		
		// 設定値変更
		padRepeat(0);
		
		// ←
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 2) ) {
			PlaySE(3);
			
			if(statc[6] < 10) {
				fontc[statc[6]]--;
				if(fontc[statc[6]] < 0) fontc[statc[6]] = 9;
			} else {
				digitc[statc[6] - 10]--;
				if(digitc[statc[6] - 10] < 0) digitc[statc[6] - 10] = 9;
			}
		}
		
		// →
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 3) ) {
			PlaySE(3);
			
			if(statc[6] < 10) {
				fontc[statc[6]]++;
				if(fontc[statc[6]] > 9) fontc[statc[6]] = 0;
			} else {
				digitc[statc[6] - 10]++;
				if(digitc[statc[6] - 10] > 9) digitc[statc[6] - 10] = 0;
			}
		}
		
		// カーソル移動
		padRepeat2(0);
		
		// ↑
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 0) ) {
			PlaySE(5);
			
			statc[6]--;
			if(statc[6] < 0) statc[6] = 19;
		}
		
		// ↓
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 1) ) {
			PlaySE(5);
			
			statc[6]++;
			if(statc[6] > 19) statc[6] = 0;
		}
		
		// キャンセル
		if( getPushState(0, 5) ) {
			return;
		}
		
		// 決定
		if( getPushState(0, 4) ) {
			PlaySE(10);
			return;
		}
		
		if(!refresh_timing) spriteTime();
	}
}

// ITEM SWITCH
void config_item() {
	int i, j, start, end, mode;
	mode = 0;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		printFont(1, 1, "ITEM SWITCH", fontc[rots[0]]);
		if(!mode) printFont(1, 2, "ITEM ON/OFF", digitc[rots[0]]);
		else printFont(1, 2, "ITEM PROBABILITY", digitc[rots[0]]);
		
		if(statc[7] <= 20) {
			start = 0;
			end = 20;
			printFont(1, 26, "PAGE 1/2", fontc[rots[0]]);
		} else {
			start = 21;
			end = 38;
			printFont(1, 26, "PAGE 2/2", fontc[rots[0]]);
		}
		
		if(!mode) printFont(1, 27, "PRESS D TO CHANGE ITEM PROBABILITY", fontc[rots[0]]);
		else printFont(1, 27, "PRESS D TO CHANGE ITEM ON/OFF", fontc[rots[0]]);
		
		// カーソル表示
		printFont(1, 4 + statc[7] - start, "b", fontc[rots[0]]);
		
		j = 0;
		
		for(i = start; i <= end; i++) {
			// 設定項目名表示
			printFont(2, 4 + j, config_item_name[i], fontc[rots[0]] * (statc[7] == i));
			
			// 設定値表示
			if(!mode) {
				if(item_switch[i] == 0) sprintf(string[0], ": OFF");
				if(item_switch[i] != 0) sprintf(string[0], ": ON");
			} else {
				sprintf(string[0], ": %d", item_pro[i]);
			}
			printFont(17, 4 + j, string[0], fontc[rots[0]] * (statc[7] == i));
			
			j++;
		}
		
		// 設定値変更
		padRepeat(0);
		
		// ←
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 2) ) {
			PlaySE(3);
			
			if(!mode) {
				item_switch[statc[7]] = !item_switch[statc[7]];
			} else {
				item_pro[statc[7]]--;
				if(item_pro[statc[7]] < 0) item_pro[statc[7]] = 9;
			}
		}
		
		// →
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 3) ) {
			PlaySE(3);
			
			if(!mode) {
				item_switch[statc[7]] = !item_switch[statc[7]];
			} else {
				item_pro[statc[7]]++;
				if(item_pro[statc[7]] > 9) item_pro[statc[7]] = 0;
			}
		}
		
		// カーソル移動
		padRepeat2(0);
		
		// ↑
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 0) ) {
			PlaySE(5);
			
			statc[7]--;
			if(statc[7] < 0) statc[7] = 38;
		}
		
		// ↓
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 1) ) {
			PlaySE(5);
			
			statc[7]++;
			if(statc[7] > 38) statc[7] = 0;
		}
		
		// 切り替え
		if( getPushState(0, 7) ) {
			PlaySE(0);
			mode = !mode;
		}
		
		// キャンセル
		if( getPushState(0, 5) ) {
			return;
		}
		
		// 決定
		if( getPushState(0, 4) ) {
			PlaySE(10);
			return;
		}
		
		if(!refresh_timing) spriteTime();
	}
}

// LANGUAGE
void config_lang() {
	int inputok;
	inputok = 0;	// 最初の1フレームは入力を無視（いきなり決定してしまうのを防ぐ）
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		printFont(1, 1, "SELECT LANGUAGE", fontc[rots[0]]);
		
		printFont(1, 3 + english, "b", fontc[rots[0]]);
		
		printFont(2, 3, "JAPANESE", fontc[rots[0]] * (english == 0));
		printFont(2, 4, "ENGLISH",  fontc[rots[0]] * (english == 1));
		
		if(inputok) {
			// ↑↓←→
			if( getPushState(0,0) || getPushState(0,1) || getPushState(0,2) || getPushState(0,3) ) {
				PlaySE(5);
				english = !english;
			}
			
			// 決定
			if( getPushState(0, 4) ) {
				PlaySE(10);
				return;
			}
		}
		
		inputok = 1;
		
		if(!refresh_timing) spriteTime();
	}
}

// SCREEN SETTING (SCREEN.SAV)
void config_screen() {
	int cfg[3];
	cfg[0] = screenMode;
	cfg[1] = systemmem;
	cfg[2] = screenColor;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		printFont(1, 1, "SCREEN SETTING", fontc[rots[0]]);
		
		printFont(1, 3 + statc[9], "b", fontc[rots[0]]);
		
		// 設定項目表示
		printFont(2, 3, "SIZE          :", fontc[rots[0]] * (statc[9] == 0));
		printFont(2, 4, "MEMORY        :", fontc[rots[0]] * (statc[9] == 1));
		printFont(2, 5, "COLOR         :", fontc[rots[0]] * (statc[9] == 2));
		
		printFont(1, 7, "PRESS A TO SAVE", fontc[rots[0]]);
		printFont(1, 8, "PRESS B TO DISCARD CHANGES", fontc[rots[0]]);
		
		printFont(1, 10, "SETTING WILL REFLECTED", digitc[rots[0]]);
		printFont(1, 11, "WHEN YOU RESTART HEBORIS.", digitc[rots[0]]);
		
		// 設定内容表示
		if(cfg[0] == 0) sprintf(string[0], "FULLSCREEN 320e240");
		if(cfg[0] == 1) sprintf(string[0], "WINDOW 320e240");
		if(cfg[0] == 2) sprintf(string[0], "WINDOW 640e480");
		if(cfg[0] == 3) sprintf(string[0], "FULLSCREEN 640e480");
		printFont(18, 3, string[0], fontc[rots[0]] * (statc[9] == 0));
		
		if(!cfg[1]) sprintf(string[0], "VIDEO MEMORY (FAST)");
		else sprintf(string[0], "SYSTEM MEMORY (SLOW)");
		printFont(18, 4, string[0], fontc[rots[0]] * (statc[9] == 1));
		
		sprintf(string[0], "%d BIT", cfg[2]);
		printFont(18, 5, string[0], fontc[rots[0]] * (statc[9] == 2));
		
		// 設定値変更
		padRepeat(0);
		
		// ←
		if((mpc[0] == 1) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6))
		if(getPressState(0, 2)) {
			PlaySE(3);
			
			if(statc[9] == 0) {
				cfg[0]--;
				if(cfg[0] < 0) cfg[0] = 3;
			}
			if(statc[9] == 1) cfg[1] = !cfg[1];
			if(statc[9] == 2) {
				cfg[2] = cfg[2] - 8;
				if(cfg[2] < 16) cfg[2] = 32;
			}
		}
		
		// →
		if((mpc[0] == 1) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6))
		if(getPressState(0, 3)) {
			PlaySE(3);
			
			if(statc[9] == 0) {
				cfg[0]++;
				if(cfg[0] > 3) cfg[0] = 0;
			}
			if(statc[9] == 1) cfg[1] = !cfg[1];
			if(statc[9] == 2) {
				cfg[2] = cfg[2] + 8;
				if(cfg[2] > 32) cfg[2] = 16;
			}
		}
		
		// カーソル移動
		padRepeat2(0);
		
		// ↑
		if((mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)))
		if(getPressState(0, 0)) {
			PlaySE(5);
			
			statc[9]--;
			if(statc[9] < 0) statc[9] = 2;
		}
		
		// ↓
		if((mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)))
		if(getPressState(0, 1)) {
			PlaySE(5);
			
			statc[9]++;
			if(statc[9] > 2) statc[9] = 0;
		}
		
		// キャンセル
		if(getPushState(0, 5)) {
			return;
		}
		
		// 決定
		if(getPushState(0, 4)) {
			PlaySE(10);
			saveScreenConfig(cfg[0], cfg[1], cfg[2]);	// screencfg.c
			return;
		}
		
		if(!refresh_timing) spriteTime();
	}
}
