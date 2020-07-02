//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   メインメニュー
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void config_mainmenu() {
	int cursor;
	cursor = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "CONFIG", 4);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "[GENERAL SETTING]", 7 * (cursor == 0));
		printFontGrid(2, 4, "[INPUT SETTING]",   7 * (cursor == 1));
		printFontGrid(2, 5, "[SCREEN SETTING]",  7 * (cursor == 2));
		printFontGrid(2, 6, "[MUSIC TEST]",      7 * (cursor == 3));
		printFontGrid(2, 7, "[SE TEST]",         7 * (cursor == 4));
		if(debug_enable) {
			printFontGrid(2, 8, "[DEBUG MENU]", 7 * (cursor == 5));
		}
		
		// キー入力
		padRepeat2(0);
		
		// ↑
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if(getPressState(0, 0)) {
			PlaySE(se_move);
			cursor--;
			if(cursor < 0) cursor = 4 + debug_enable;
		}
		
		// ↓
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if(getPressState(0, 1)) {
			PlaySE(se_move);
			cursor++;
			if(cursor > 4 + debug_enable) cursor = 0;
		}
		
		// キャンセル
		if(getPushState(0, 5)) {
			return;
		}
		
		// 決定
		if(getPushState(0, 4)) {
			PlaySE(se_kettei);
			if(cursor == 0) general_menu();
			if(cursor == 1) keyconfig_menu();
			if(cursor == 2) screen_config_menu();
			if(cursor == 3) music_test();
			if(cursor == 4) se_test();
			if(cursor == 5) debugMenu(0);
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   全般の設定
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// メニュー
void general_menu() {
	int cursor, reload_graphics, reload_sysbgm, move;
	cursor = 0;
	reload_graphics = 0;
	reload_sysbgm = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "GENERAL SETTING", 4);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2,  3, "NEXT PATTERN",      7 * (cursor ==  0));
		printFontGrid(2,  4, "8WAY INPUT",        7 * (cursor ==  1));
		printFontGrid(2,  5, "FIELD BRIGHT",      7 * (cursor ==  2));
		printFontGrid(2,  6, "NEXT DISPLAY",      7 * (cursor ==  3));
		printFontGrid(2,  7, "TOP FRAME",         7 * (cursor ==  4));
		printFontGrid(2,  8, "LINE ERASE EFFECT", 7 * (cursor ==  5));
		printFontGrid(2,  9, "DROP LIMIT",        7 * (cursor ==  6));
		printFontGrid(2, 10, "ROTATE SOUND",      7 * (cursor ==  7));
		printFontGrid(2, 11, "MOVE SOUND",        7 * (cursor ==  8));
		printFontGrid(2, 12, "SHOW CONTROL",      7 * (cursor ==  9));
		printFontGrid(2, 13, "SPAWN Y TYPE",      7 * (cursor == 10));
		printFontGrid(2, 14, "NUMBER FONT TYPE",  7 * (cursor == 11));
		printFontGrid(2, 15, "SE VOLUME",         7 * (cursor == 12));
		printFontGrid(2, 16, "BGM VOLUME",        7 * (cursor == 13));
		printFontGrid(2, 17, "BGM TYPE",          7 * (cursor == 14));
		printFontGrid(2, 18, "BGM FADE SPEED",    7 * (cursor == 15));
		printFontGrid(2, 19, "SHOW FPS",          7 * (cursor == 16));
		printFontGrid(2, 20, "FPS",               7 * (cursor == 17));
		printFontGrid(2, 21, "BACKGROUND",        7 * (cursor == 18));
		printFontGrid(2, 22, "HOLD SOUND",        7 * (cursor == 19));
		printFontGrid(2, 23, "LANGUAGE",          7 * (cursor == 20));
		printFontGrid(2, 24, "E BUTTON",          7 * (cursor == 21));
		printFontGrid(2, 25, "ENABLE SYSTEM BGM", 7 * (cursor == 22));
		printFontGrid(2, 26, "EFFECT SPEED",      7 * (cursor == 23));
		printFontGrid(2, 27, "BLOCK SHADOW",      7 * (cursor == 24));
		printFontGrid(2, 28, "HOLD",              7 * (cursor == 25));
		
		// 設定値表示
		if(nextblock == 0) sprintf(string[0], "RANDOM");
		else if(nextblock <= 7) sprintf(string[0], "HEBO%d", nextblock);
		else if(nextblock == 8) sprintf(string[0], "MEMORY4 (4 TRY)");
		else if(nextblock == 9) sprintf(string[0], "MEMORY4 (6 TRY)");
		else if(nextblock == 10) sprintf(string[0], "7 PIECE BAG");
		else if(nextblock == 11) sprintf(string[0], "CUSTOM");
		else if(nextblock == 12) sprintf(string[0], "I-CHEAT");
		else sprintf(string[0], "7+1 PIECE BAG");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(nanameallow == 0) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "%d", fldtr);
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		sprintf(string[0], "%d", dispnext);
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(top_frame == 0) sprintf(string[0], "TYPE A");
		else if(top_frame == 1) sprintf(string[0], "TYPE B");
		else if(top_frame == 2) sprintf(string[0], "TYPE C");
		else sprintf(string[0], "TYPE D");
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		if(breaktype == 0) sprintf(string[0], "NONE");
		else if(breaktype == 1) sprintf(string[0], "POP OUT");
		else if(breaktype == 2) sprintf(string[0], "SHATTER");
		else if(breaktype == 3) sprintf(string[0], "SIMPLE-1");
		else sprintf(string[0], "SIMPLE-2");
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		if(downtype == 0) sprintf(string[0], "OFF");
		else if(downtype == 1) sprintf(string[0], "20G ONLY");
		else sprintf(string[0], "ON");
		printFontGrid(22, 9, string[0], 7 * (cursor == 6));
		
		if(rotate_sound == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 10, string[0], 7 * (cursor == 7));
		
		if(move_sound == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 11, string[0], 7 * (cursor == 8));
		
		if(showctrl == 0) sprintf(string[0], "OFF");
		else if(showctrl == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "REPLAY ONLY");
		printFontGrid(22, 12, string[0], 7 * (cursor == 9));
		
		if(spawn_y_type == 0) sprintf(string[0], "UNDER THE FRAME");
		else sprintf(string[0], "ABOVE THE FRAME");
		printFontGrid(22, 13, string[0], 7 * (cursor == 10));
		
		if(fonttype == 0) sprintf(string[0], "TYPE A");
		else sprintf(string[0], "TYPE B");
		printFontGrid(22, 14, string[0], 7 * (cursor == 11));
		
		sprintf(string[0], "%d", sevolume);
		printFontGrid(22, 15, string[0], 7 * (cursor == 12));
		
		sprintf(string[0], "%d", bgmvolume);
		printFontGrid(22, 16, string[0], 7 * (cursor == 13));
		
		if(bgmtype == 0) sprintf(string[0], "OFF");
		else if(bgmtype == 1) sprintf(string[0], "WAV");
		else if(bgmtype == 2) sprintf(string[0], "MP3 (NO ID3 TAG)");
		else sprintf(string[0], "MIDI");
		printFontGrid(22, 17, string[0], 7 * (cursor == 14));
		
		sprintf(string[0], "%d", fadesetting);
		printFontGrid(22, 18, string[0], 7 * (cursor == 15));
		
		if(show_fps == 0) sprintf(string[0], "OFF");
		else if(show_fps == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "CAPTION");
		printFontGrid(22, 19, string[0], 7 * (cursor == 16));
		
		sprintf(string[0], "%d", normalfps);
		printFontGrid(22, 20, string[0], 7 * (cursor == 17));
		
		if(!hide_back) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 21, string[0], 7 * (cursor == 18));
		
		if(hold_sound == 0) sprintf(string[0], "INITIAL ONLY");
		else if(hold_sound == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 22, string[0], 7 * (cursor == 19));
		
		if(!english) sprintf(string[0], "JAPANESE");
		else sprintf(string[0], "ENGLISH");
		printFontGrid(22, 23, string[0], 7 * (cursor == 20));
		
		if(!disable180) sprintf(string[0], "180 ROTATE");
		else sprintf(string[0], "REVERSE ROTATE");
		printFontGrid(22, 24, string[0], 7 * (cursor == 21));
		
		if(!enable_sysbgm) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 25, string[0], 7 * (cursor == 22));
		
		if(!beffect_speed) sprintf(string[0], "AUTO");
		else sprintf(string[0], "e %d", beffect_speed);
		printFontGrid(22, 26, string[0], 7 * (cursor == 23));
		
		if(blockshadow == 0) sprintf(string[0], "OFF");
		else if(blockshadow == 1) sprintf(string[0], "LEFT");
		else sprintf(string[0], "RIGHT");
		printFontGrid(22, 27, string[0], 7 * (cursor == 24));
		
		if(!disable_hold) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 28, string[0], 7 * (cursor == 25));
		
		// カーソル移動
		padRepeat2(0);
		
		// ↑
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if(getPressState(0, 0)) {
			PlaySE(se_move);
			cursor--;
			if(cursor < 0) cursor = 25;
		}
		
		// ↓
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if(getPressState(0, 1)) {
			PlaySE(se_move);
			cursor++;
			if(cursor > 25) cursor = 0;
		}
		
		// 値を変更
		padRepeat(0);
		
		move = 0;
		if((mpc[0] == 1) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6))
			move = getPressState(0, 3) - getPressState(0, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) {
				nextblock = nextblock + move;
				if(nextblock < 0) nextblock = 13;
				if(nextblock > 13) nextblock = 0;
			}
			if(cursor == 1) nanameallow = !nanameallow;
			if(cursor == 2) {
				fldtr = fldtr + move;
				if(fldtr < 0) fldtr = 256;
				if(fldtr > 256) fldtr = 0;
				reload_graphics = 1;
			}
			if(cursor == 3) {
				dispnext = dispnext + move;
				if(dispnext < 0) dispnext = 6;
				if(dispnext > 6) dispnext = 0;
			}
			if(cursor == 4) {
				top_frame = top_frame + move;
				if(top_frame < 0) top_frame = 3;
				if(top_frame > 3) top_frame = 0;
				reload_graphics = 1;
			}
			if(cursor == 5) {
				breaktype = breaktype + move;
				if(breaktype < 0) breaktype = 4;
				if(breaktype > 4) breaktype = 0;
				reload_graphics = 1;
			}
			if(cursor == 6) {
				downtype = downtype + move;
				if(downtype > 2) downtype = 0;
				if(downtype < 0) downtype = 2;
			}
			if(cursor == 7) rotate_sound = !rotate_sound;
			if(cursor == 8) move_sound = !move_sound;
			if(cursor == 9) {
				showctrl = showctrl + move;
				if(showctrl < 0) showctrl = 2;
				if(showctrl > 2) showctrl = 0;
			}
			if(cursor == 10) spawn_y_type = !spawn_y_type;
			if(cursor == 11) fonttype = !fonttype;
			if(cursor == 12) {
				sevolume = sevolume + move;
				if(sevolume > 0) sevolume = -10000;
				if(sevolume < -10000) sevolume = 0;
			}
			if(cursor == 13) {
				bgmvolume = bgmvolume + move;
				if(bgmvolume > 0) bgmvolume = -10000;
				if(bgmvolume < -10000) bgmvolume = 0;
			}
			if(cursor == 14) {
				bgmtype = bgmtype + move;
				if(bgmtype < 0) bgmtype = 3;
				if(bgmtype > 3) bgmtype = 0;
			}
			if(cursor == 15) {
				fadesetting = fadesetting + move;
				if(fadesetting < 0) fadesetting = 10000;
				if(fadesetting > 10000) fadesetting = 0;
			}
			if(cursor == 16) {
				show_fps = show_fps + move;
				if(show_fps < 0) show_fps = 2;
				if(show_fps > 2) show_fps = 0;
				
				if(show_fps != 2) SetConstParam("Caption", "HEBORIS U.E. MINI");
			}
			if(cursor == 17) {
				normalfps = normalfps + move;
				if(normalfps < 1) normalfps = 120;
				if(normalfps > 120) normalfps = 1;
			}
			if(cursor == 18) {
				hide_back = !hide_back;
				reload_graphics = 1;
			}
			if(cursor == 19) {
				hold_sound = hold_sound + move;
				if(hold_sound < 0) hold_sound = 2;
				if(hold_sound > 2) hold_sound = 0;
			}
			if(cursor == 20) english = !english;
			if(cursor == 21) disable180 = !disable180;
			if(cursor == 22) {
				enable_sysbgm = !enable_sysbgm;
				reload_sysbgm = enable_sysbgm;
			}
			if(cursor == 23) {
				beffect_speed = beffect_speed + move;
				if(beffect_speed < 0) beffect_speed = 5;
				if(beffect_speed > 5) beffect_speed = 0;
			}
			if(cursor == 24) {
				blockshadow = blockshadow + move;
				if(blockshadow < 0) blockshadow = 2;
				if(blockshadow > 2) blockshadow = 0;
				reload_graphics = 1;
			}
			if(cursor == 25) disable_hold = !disable_hold;
		}
		
		// キャンセル
		if(getPushState(0, 5)) {
			loadGeneralConfigData();
			return;
		}
		
		// 決定
		if(getPushState(0, 4)) {
			PlaySE(se_kettei);
			saveGeneralConfigData();
			resetSoundVolume();
			
			// グラフィックの再読み込み
			if(reload_graphics) {
				ClearSecondary();
				printFontGrid(1, 1, "PLEASE WAIT...", 2);
				printFontGrid(1, 2, "LOADING GRAPHICS", 2);
				halt;
				loadAllSystemGraphics();
			}
			
			// システムBGMの再読み込み
			if(reload_sysbgm) {
				ClearSecondary();
				printFontGrid(1, 1, "PLEASE WAIT...", 2);
				printFontGrid(1, 2, "LOADING SYSTEM BGM", 2);
				halt;
				loadSystemBGM();
			}
			
			// FPS設定を反映させる
			if((normalfps != 0) && (GetFPS() != normalfps)) SetFPS(normalfps);
			
			return;
		}
	}
}

// 保存
void saveGeneralConfigData() {
	FillMemory(&saveBuf, 200 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x464E4F43;
	saveBuf[3] = 0x31764749;
	
	// 設定内容
	saveBuf[4] = nextblock;
	saveBuf[5] = nanameallow;
	//saveBuf[6] = maxPlay;
	saveBuf[7] = fldtr;
	saveBuf[8] = dispnext;
	saveBuf[9] = top_frame;
	saveBuf[10] = breaktype;
	saveBuf[11] = downtype;
	saveBuf[12] = rotate_sound;
	saveBuf[13] = move_sound;
	saveBuf[14] = showctrl;
	saveBuf[15] = spawn_y_type;
	saveBuf[16] = fonttype;
	saveBuf[17] = sevolume;
	saveBuf[18] = bgmvolume;
	saveBuf[19] = bgmtype;
	saveBuf[20] = fadesetting;
	saveBuf[21] = show_fps;
	saveBuf[22] = lastrots;
	saveBuf[23] = lastmode;
	saveBuf[24] = normalfps;
	saveBuf[25] = hide_back;
	saveBuf[26] = hold_sound;
	saveBuf[27] = english;
	saveBuf[28] = disable180;
	saveBuf[29] = enable_sysbgm;
	saveBuf[30] = beffect_speed;
	saveBuf[31] = blockshadow;
	saveBuf[32] = disable_hold;
	
	SaveFile("config/CONFIG.SAV", &saveBuf, 200 * 4);
}

// 読み込み
int loadGeneralConfigData() {
	FillMemory(&saveBuf, 200 * 4, 0);
	
	LoadFile("config/CONFIG.SAV", &saveBuf, 200 * 4);
	
	// ヘッダが違う
	if(saveBuf[0] != 0x4F424548) return -1;
	if(saveBuf[1] != 0x494E494D) return -1;
	if(saveBuf[2] != 0x464E4F43) return -1;
	if(saveBuf[3] != 0x31764749) return -1;
	
	// 設定を代入
	nextblock = saveBuf[4];
	nanameallow = saveBuf[5];
	//maxPlay = saveBuf[6];
	fldtr = saveBuf[7];
	dispnext = saveBuf[8];
	top_frame = saveBuf[9];
	breaktype = saveBuf[10];
	downtype = saveBuf[11];
	rotate_sound = saveBuf[12];
	move_sound = saveBuf[13];
	showctrl = saveBuf[14];
	spawn_y_type = saveBuf[15];
	fonttype = saveBuf[16];
	sevolume = saveBuf[17];
	bgmvolume = saveBuf[18];
	bgmtype = saveBuf[19];
	fadesetting = saveBuf[20];
	show_fps = saveBuf[21];
	lastrots = saveBuf[22];
	lastmode = saveBuf[23];
	normalfps = saveBuf[24];
	hide_back = saveBuf[25];
	hold_sound = saveBuf[26];
	english = saveBuf[27];
	disable180 = saveBuf[28];
	enable_sysbgm = saveBuf[29];
	beffect_speed = saveBuf[30];
	blockshadow = saveBuf[31];
	disable_hold = saveBuf[32];
	
	return 0;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   キーコンフィグ
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// メニュー
void keyconfig_menu() {
	int cursor;
	cursor = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "INPUT SETTING", 4);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "[1P KEYBOARD SETTING]",  7 * (cursor == 0));
		printFontGrid(2, 4, "[2P KEYBOARD SETTING]",  7 * (cursor == 1));
		printFontGrid(2, 5, "[1P JOYSTICK SETTING]",  7 * (cursor == 2));
		printFontGrid(2, 6, "[2P JOYSTICK SETTING]",  7 * (cursor == 3));
		printFontGrid(2, 7, "[JOYSTICK MAX BUTTONS]", 7 * (cursor == 4));
		printFontGrid(2, 8, "[INPUT TEST]",           7 * (cursor == 5));
		
		// キー入力
		padRepeat2(0);
		
		// ↑
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if(getPressState(0, 0)) {
			PlaySE(se_move);
			cursor--;
			if(cursor < 0) cursor = 5;
		}
		
		// ↓
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if(getPressState(0, 1)) {
			PlaySE(se_move);
			cursor++;
			if(cursor > 5) cursor = 0;
		}
		
		// キャンセル
		if(getPushState(0, 5)) {
			return;
		}
		
		// 決定
		if(getPushState(0, 4)) {
			PlaySE(se_kettei);
			if(cursor == 0) keyconfig_keyboard_setting(0, 0);
			if(cursor == 1) keyconfig_keyboard_setting(1, 0);
			if(cursor == 2) keyconfig_joystick_setting(0);
			if(cursor == 3) keyconfig_joystick_setting(1);
			if(cursor == 4) keyconfig_joybutton();
			if(cursor == 5) keyconfig_inputtest();
		}
	}
}

// キーボード設定
void keyconfig_keyboard_setting(int player, int first) {
	int i, cursor, key[17];
	
	for(i = 0; i < 17; i++) key[i] = 0;
	cursor = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		sprintf(string[0], "%dP KEYBOARD SETTING", player + 1);
		printFontGrid(1, 1, string[0], 2 - player);
		
		// カーソル表示
		if(cursor < 17) printFontGrid(1, 3 + cursor, "b", 7);
		
		// キー一覧表示
		sprintf(string[0], "UP             : %02X", key[0]);
		printFontGrid(2,  3, string[0], 7 * (cursor ==  0));
		sprintf(string[0], "DOWN           : %02X", key[1]);
		printFontGrid(2,  4, string[0], 7 * (cursor ==  1));
		sprintf(string[0], "LEFT           : %02X", key[2]);
		printFontGrid(2,  5, string[0], 7 * (cursor ==  2));
		sprintf(string[0], "RIGHT          : %02X", key[3]);
		printFontGrid(2,  6, string[0], 7 * (cursor ==  3));
		sprintf(string[0], "A (L/R-ROT)    : %02X", key[4]);
		printFontGrid(2,  7, string[0], 7 * (cursor ==  4));
		sprintf(string[0], "B (R/L-ROT)    : %02X", key[5]);
		printFontGrid(2,  8, string[0], 7 * (cursor ==  5));
		sprintf(string[0], "C (L/R-ROT)    : %02X", key[6]);
		printFontGrid(2,  9, string[0], 7 * (cursor ==  6));
		sprintf(string[0], "D (HOLD)       : %02X", key[7]);
		printFontGrid(2, 10, string[0], 7 * (cursor ==  7));
		sprintf(string[0], "E (180-ROT)    : %02X", key[8]);
		printFontGrid(2, 11, string[0], 7 * (cursor ==  8));
		sprintf(string[0], "F              : %02X", key[9]);
		printFontGrid(2, 12, string[0], 7 * (cursor ==  9));
		sprintf(string[0], "PAUSE          : %02X", key[10]);
		printFontGrid(2, 13, string[0], 7 * (cursor == 10));
		sprintf(string[0], "GIVEUP         : %02X", key[11]);
		printFontGrid(2, 14, string[0], 7 * (cursor == 11));
		sprintf(string[0], "SCREEN SHOT    : %02X", key[12]);
		printFontGrid(2, 15, string[0], 7 * (cursor == 12));
		sprintf(string[0], "EXTRA KEY      : %02X", key[13]);
		printFontGrid(2, 16, string[0], 7 * (cursor == 13));
		sprintf(string[0], "FPS +1         : %02X", key[14]);
		printFontGrid(2, 17, string[0], 7 * (cursor == 14));
		sprintf(string[0], "FPS -1         : %02X", key[15]);
		printFontGrid(2, 18, string[0], 7 * (cursor == 15));
		sprintf(string[0], "RETRY          : %02X", key[16]);
		printFontGrid(2, 19, string[0], 7 * (cursor == 16));
		
		// キー入力
		if(cursor < 17) {
			printFontGrid(1, 21, "DELETE:    NO SET", 6);
			if(!first) printFontGrid(1, 22, "BACKSPACE: CANCEL", 6);
			
			for(i = 0; i < 256; i++) {
				if(IsPushKey(i)) {
					// キーが押された
					if(i == key_del) {
						// DELETEキーで設定なし
						PlaySE(se_move);
						key[cursor] = 0;
						cursor++;
					} else if(i == key_bs) {
						// BACKSPACEキーでキャンセル
						if(!first) return;
					} else {
						// その他のキー
						PlaySE(se_move);
						key[cursor] = i;
						cursor++;
					}
				}
			}
		} else {
			printFontGrid(1, 21, "ENTER:     OK", 5);
			printFontGrid(1, 22, "DELETE:    AGAIN", 5);
			if(!first) printFontGrid(1, 23, "BACKSPACE: CANCEL", 5);
			
			if(IsPushKey(key_enter)) {
				// ENTERキーで決定
				keyAssign[player * 10 + 0] = key[0];	// ↑
				keyAssign[player * 10 + 1] = key[1];	// ↓
				keyAssign[player * 10 + 2] = key[2];	// ←
				keyAssign[player * 10 + 3] = key[3];	// →
				keyAssign[player * 10 + 4] = key[4];	// A
				keyAssign[player * 10 + 5] = key[5];	// B
				keyAssign[player * 10 + 6] = key[6];	// C
				keyAssign[player * 10 + 7] = key[7];	// D
				keyAssign[player * 10 + 8] = key[8];	// E
				keyAssign[player * 10 + 9] = key[9];	// E
				pause_key[player]          = key[10];	// ポーズ
				giveup_key[player]         = key[11];	// 捨てゲー
				ss_key[player]             = key[12];	// スクリーンショット
				extra_key[player]          = key[13];	// EXTRA
				fps_plus_key[player]       = key[14];	// FPS+1
				fps_minus_key[player]      = key[15];	// FPS-1
				retry_key[player]          = key[16];	// リトライ
				
				PlaySE(se_kettei);
				saveKeyConfigData();
				return;
			} else if(IsPushKey(key_del)) {
				// DELETEキーでやり直し
				PlaySE(se_move);
				for(i = 0; i < 17; i++) key[i] = 0;
				cursor = 0;
			} else if(IsPushKey(key_bs)) {
				// BACKSPACEキーでキャンセル
				if(!first) return;
			}
		}
	}
}

// ジョイスティック設定
void keyconfig_joystick_setting(int player) {
	int i, cursor, key[17];
	
	for(i = 0; i < 17; i++) key[i] = -1;
	cursor = 0;
	
	loop {
		spriteTime();
		KeyInput();
		SelectJoyStick(player);
		ExBltFast(sg_menu_back, 0, 0);
		
		sprintf(string[0], "%dP JOYSTICK SETTING", player + 1);
		printFontGrid(1, 1, string[0], 2 - player);
		
		// カーソル表示
		if(cursor < 17) printFontGrid(1, 3 + cursor, "b", 7);
		
		// キー一覧表示
		sprintf(string[0], "UP             : %02X", key[0]);
		printFontGrid(2,  3, string[0], 7 * (cursor ==  0));
		sprintf(string[0], "DOWN           : %02X", key[1]);
		printFontGrid(2,  4, string[0], 7 * (cursor ==  1));
		sprintf(string[0], "LEFT           : %02X", key[2]);
		printFontGrid(2,  5, string[0], 7 * (cursor ==  2));
		sprintf(string[0], "RIGHT          : %02X", key[3]);
		printFontGrid(2,  6, string[0], 7 * (cursor ==  3));
		sprintf(string[0], "A (L/R-ROT)    : %02X", key[4]);
		printFontGrid(2,  7, string[0], 7 * (cursor ==  4));
		sprintf(string[0], "B (R/L-ROT)    : %02X", key[5]);
		printFontGrid(2,  8, string[0], 7 * (cursor ==  5));
		sprintf(string[0], "C (L/R-ROT)    : %02X", key[6]);
		printFontGrid(2,  9, string[0], 7 * (cursor ==  6));
		sprintf(string[0], "D (HOLD)       : %02X", key[7]);
		printFontGrid(2, 10, string[0], 7 * (cursor ==  7));
		sprintf(string[0], "E (180-ROT)    : %02X", key[8]);
		printFontGrid(2, 11, string[0], 7 * (cursor ==  8));
		sprintf(string[0], "F              : %02X", key[9]);
		printFontGrid(2, 12, string[0], 7 * (cursor ==  9));
		sprintf(string[0], "PAUSE          : %02X", key[10]);
		printFontGrid(2, 13, string[0], 7 * (cursor ==  10));
		sprintf(string[0], "GIVEUP         : %02X", key[11]);
		printFontGrid(2, 14, string[0], 7 * (cursor == 11));
		sprintf(string[0], "SCREEN SHOT    : %02X", key[12]);
		printFontGrid(2, 15, string[0], 7 * (cursor == 12));
		sprintf(string[0], "EXTRA KEY      : %02X", key[13]);
		printFontGrid(2, 16, string[0], 7 * (cursor == 13));
		sprintf(string[0], "FPS +1         : %02X", key[14]);
		printFontGrid(2, 17, string[0], 7 * (cursor == 14));
		sprintf(string[0], "FPS -1         : %02X", key[15]);
		printFontGrid(2, 18, string[0], 7 * (cursor == 15));
		sprintf(string[0], "RETRY          : %02X", key[16]);
		printFontGrid(2, 19, string[0], 7 * (cursor == 16));
		
		// キー入力
		if(cursor < 17) {
			printFontGrid(1, 21, "DELETE:    NO SET", 6);
			printFontGrid(1, 22, "BACKSPACE: CANCEL", 6);
			
			for(i = 0; i < joykeyButtonNum; i++) {
				if(IsPushJoyKey(i)) {
					// ボタンが押された
					PlaySE(se_move);
					key[cursor] = i;
					cursor++;
				}
			}
			
			// DELETEキーで設定なし
			if(IsPushKey(key_del)) {
				PlaySE(se_move);
				key[cursor] = -1;
				cursor++;
			}
			
			// BACKSPACEキーでキャンセル
			if(IsPushKey(key_bs)) {
				return;
			}
		} else {
			printFontGrid(1, 21, "ENTER:     OK", 5);
			printFontGrid(1, 22, "DELETE:    AGAIN", 5);
			printFontGrid(1, 23, "BACKSPACE: CANCEL", 5);
			
			if(IsPushKey(key_enter)) {
				// ENTERキーで決定
				joykeyAssign[player * 10 + 0] = key[0];		// ↑
				joykeyAssign[player * 10 + 1] = key[1];		// ↓
				joykeyAssign[player * 10 + 2] = key[2];		// ←
				joykeyAssign[player * 10 + 3] = key[3];		// →
				joykeyAssign[player * 10 + 4] = key[4];		// A
				joykeyAssign[player * 10 + 5] = key[5];		// B
				joykeyAssign[player * 10 + 6] = key[6];		// C
				joykeyAssign[player * 10 + 7] = key[7];		// D
				joykeyAssign[player * 10 + 8] = key[8];		// E
				joykeyAssign[player * 10 + 9] = key[9];		// F
				joy_pause_key[player]         = key[10];	// ポーズ
				joy_giveup_key[player]        = key[11];	// 捨てゲー
				joy_ss_key[player]            = key[12];	// スクリーンショット
				joy_extra_key[player]         = key[13];	// EXTRA
				joy_fps_plus_key[player]      = key[14];	// FPS+1
				joy_fps_minus_key[player]     = key[15];	// FPS-1
				joy_retry_key[player]         = key[16];	// リトライ
				
				PlaySE(se_kettei);
				saveKeyConfigData();
				return;
			} else if(IsPushKey(key_del)) {
				// DELETEキーでやり直し
				PlaySE(se_move);
				for(i = 0; i < 17; i++) key[i] = -1;
				cursor = 0;
			} else if(IsPushKey(key_bs)) {
				// BACKSPACEキーでキャンセル
				return;
			}
		}
	}
}

// ジョイスティックのボタン数設定
void keyconfig_joybutton() {
	int buttons;
	buttons = joykeyButtonNum;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "JOYSTICK MAX BUTTONS", 4);
		
		sprintf(string[0], "BUTTONS: %d", buttons);
		printFontGrid(2, 3, string[0], 7);
		
		printFontGrid(1, 5, "A: OK", 6);
		printFontGrid(1, 6, "B: CANCEL", 6);
		
		// キー入力
		padRepeat(0);
		
		// ←
		if((mpc[0] == 1) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6))
		if(getPressState(0, 2)) {
			PlaySE(se_kachi);
			buttons--;
			if(buttons < 0) buttons = 99;
		}
		
		// →
		if((mpc[0] == 1) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6))
		if(getPressState(0, 3)) {
			PlaySE(se_kachi);
			buttons++;
			if(buttons > 99) buttons = 0;
		}
		
		// キャンセル
		if(getPushState(0, 5)) {
			return;
		}
		
		// 決定
		if(getPushState(0, 4)) {
			PlaySE(se_kettei);
			joykeyButtonNum = buttons;
			SetJoyButtonMax(joykeyButtonNum);
			saveKeyConfigData();
			return;
		}
	}
}

// キー入力テスト
void keyconfig_inputtest() {
	int player, i, temp;
	maxPlay = 1;	// 2Pを有効にする
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "INPUT TEST", 4);
		
		printFontGrid(1, 3, "BUTTON", 5);
		printFontGrid(8, 3, "1P", 2);
		printFontGrid(11, 3, "2P", 1);
		
		printFontGrid(1,  4, "UP", 0);
		printFontGrid(1,  5, "DOWN", 0);
		printFontGrid(1,  6, "LEFT", 0);
		printFontGrid(1,  7, "RIGHT", 0);
		printFontGrid(1,  8, "A", 0);
		printFontGrid(1,  9, "B", 0);
		printFontGrid(1, 10, "C", 0);
		printFontGrid(1, 11, "D", 0);
		printFontGrid(1, 12, "E", 0);
		printFontGrid(1, 13, "F", 0);
		printFontGrid(1, 14, "PAUSE", 0);
		printFontGrid(1, 15, "GIVEUP", 0);
		printFontGrid(1, 16, "SCSHOT", 0);
		printFontGrid(1, 17, "EXTRA", 0);
		printFontGrid(1, 18, "FPS+1", 0);
		printFontGrid(1, 19, "FPS-1", 0);
		printFontGrid(1, 20, "RETRY", 0);
		
		printFontGrid(1, 22, "PRESS A+B TO EXIT", 4);
		
		for(player = 0; player <= maxPlay; player++) {
			for(i = 0; i < 10; i++) {
				temp = getPressState(player, i);
				sprintf(string[0], "%d", temp);
				printFontGrid(8 + player * 3, 4 + i, string[0], temp * 2);
			}
			
			temp = IsPressKey(pause_key[player]) | getJoyPressState(player, joy_pause_key[player]);
			sprintf(string[0], "%d", temp);
			printFontGrid(8 + player * 3, 14, string[0], temp * 1);
			
			temp = IsPressKey(giveup_key[player]) | getJoyPressState(player, joy_giveup_key[player]);
			sprintf(string[0], "%d", temp);
			printFontGrid(8 + player * 3, 15, string[0], temp * 1);
			
			temp = IsPressKey(ss_key[player]) | getJoyPressState(player, joy_ss_key[player]);
			sprintf(string[0], "%d", temp);
			printFontGrid(8 + player * 3, 16, string[0], temp * 1);
			
			temp = IsPressKey(extra_key[player]) | getJoyPressState(player, joy_extra_key[player]);
			sprintf(string[0], "%d", temp);
			printFontGrid(8 + player * 3, 17, string[0], temp * 1);
			
			temp = IsPressKey(fps_plus_key[player]) | getJoyPressState(player, joy_fps_plus_key[player]);
			sprintf(string[0], "%d", temp);
			printFontGrid(8 + player * 3, 18, string[0], temp * 1);
			
			temp = IsPressKey(fps_minus_key[player]) | getJoyPressState(player, joy_fps_minus_key[player]);
			sprintf(string[0], "%d", temp);
			printFontGrid(8 + player * 3, 19, string[0], temp * 1);
			
			temp = IsPressKey(retry_key[player]) | getJoyPressState(player, joy_retry_key[player]);
			sprintf(string[0], "%d", temp);
			printFontGrid(8 + player * 3, 20, string[0], temp * 1);
			
			if(getPressState(player, 4) && getPressState(player, 5)) {
				maxPlay = 0;	// 戻す
				return;
			}
		}
	}
}

// キー設定を保存
void saveKeyConfigData() {
	int i;
	FillMemory(&saveBuf, 80 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x4359454B;
	saveBuf[3] = 0x31464E4F;
	
	// キーボード設定
	for(i = 0; i < 20; i++) saveBuf[i + 4] = keyAssign[i];
	
	// ジョイスティック設定
	for(i = 0; i < 20; i++) saveBuf[i + 4 + 20] = joykeyAssign[i];
	
	// その他のキー
	saveBuf[44] = pause_key[0];
	saveBuf[45] = pause_key[1];
	saveBuf[46] = joy_pause_key[0];
	saveBuf[47] = joy_pause_key[1];
	saveBuf[48] = giveup_key[0];
	saveBuf[49] = giveup_key[1];
	saveBuf[50] = joy_giveup_key[0];
	saveBuf[51] = joy_giveup_key[1];
	saveBuf[52] = ss_key[0];
	saveBuf[53] = ss_key[1];
	saveBuf[54] = joy_ss_key[0];
	saveBuf[55] = joy_ss_key[1];
	saveBuf[56] = extra_key[0];
	saveBuf[57] = extra_key[1];
	saveBuf[58] = joy_extra_key[0];
	saveBuf[59] = joy_extra_key[1];
	saveBuf[60] = fps_plus_key[0];
	saveBuf[61] = fps_plus_key[1];
	saveBuf[62] = joy_fps_plus_key[0];
	saveBuf[63] = joy_fps_plus_key[1];
	saveBuf[64] = fps_minus_key[0];
	saveBuf[65] = fps_minus_key[1];
	saveBuf[66] = joy_fps_minus_key[0];
	saveBuf[67] = joy_fps_minus_key[1];
	
	// ジョイスティックのボタンの数
	saveBuf[68] = joykeyButtonNum;
	
	saveBuf[69] = retry_key[0];
	saveBuf[70] = retry_key[1];
	saveBuf[71] = joy_retry_key[0];
	saveBuf[72] = joy_retry_key[1];
	
	SaveFile("config/KEYCONFIG.SAV", &saveBuf, 80 * 4);
}

// キー設定を読み込み
int loadKeyConfigData() {
	int i;
	FillMemory(&saveBuf, 80 * 4, 0);
	
	LoadFile("config/KEYCONFIG.SAV", &saveBuf, 80 * 4);
	
	// ヘッダが違う
	if(saveBuf[0] != 0x4F424548) return -1;
	if(saveBuf[1] != 0x494E494D) return -1;
	if(saveBuf[2] != 0x4359454B) return -1;
	if(saveBuf[3] != 0x31464E4F) return -1;
	
	// キーボード設定
	for(i = 0; i < 20; i++) keyAssign[i] = saveBuf[i + 4];
	
	// ジョイスティック設定
	for(i = 0; i < 20; i++) joykeyAssign[i] = saveBuf[i + 4 + 20];
	
	// その他のキー
	pause_key[0]         = saveBuf[44];
	pause_key[1]         = saveBuf[45];
	joy_pause_key[0]     = saveBuf[46];
	joy_pause_key[1]     = saveBuf[47];
	giveup_key[0]        = saveBuf[48];
	giveup_key[1]        = saveBuf[49];
	joy_giveup_key[0]    = saveBuf[50];
	joy_giveup_key[1]    = saveBuf[51];
	ss_key[0]            = saveBuf[52];
	ss_key[1]            = saveBuf[53];
	joy_ss_key[0]        = saveBuf[54];
	joy_ss_key[1]        = saveBuf[55];
	extra_key[0]         = saveBuf[56];
	extra_key[1]         = saveBuf[57];
	joy_extra_key[0]     = saveBuf[58];
	joy_extra_key[1]     = saveBuf[59];
	fps_plus_key[0]      = saveBuf[60];
	fps_plus_key[1]      = saveBuf[61];
	joy_fps_plus_key[0]  = saveBuf[62];
	joy_fps_plus_key[1]  = saveBuf[63];
	fps_minus_key[0]     = saveBuf[64];
	fps_minus_key[1]     = saveBuf[65];
	joy_fps_minus_key[0] = saveBuf[66];
	joy_fps_minus_key[1] = saveBuf[67];
	
	// ジョイスティックのボタンの数
	joykeyButtonNum = saveBuf[68];
	SetJoyButtonMax(joykeyButtonNum);
	
	retry_key[0]         = saveBuf[69];
	retry_key[1]         = saveBuf[70];
	joy_retry_key[0]     = saveBuf[71];
	joy_retry_key[1]     = saveBuf[72];
	
	return 0;
}

// 設定を初期化
void initKeyConfigData() {
	int i;
	
	// キーボード設定
	for(i = 0; i < 20; i++) keyAssign[i] = 0;
	
	// ジョイスティック設定
	for(i = 0; i < 20; i++) joykeyAssign[i] = -1;
	
	// その他のキー
	pause_key[0]         = 0;
	pause_key[1]         = 0;
	joy_pause_key[0]     = -1;
	joy_pause_key[1]     = -1;
	giveup_key[0]        = 0;
	giveup_key[1]        = 0;
	joy_giveup_key[0]    = -1;
	joy_giveup_key[1]    = -1;
	ss_key[0]            = 0;
	ss_key[1]            = 0;
	joy_ss_key[0]        = -1;
	joy_ss_key[1]        = -1;
	extra_key[0]         = 0;
	extra_key[1]         = 0;
	joy_extra_key[0]     = -1;
	joy_extra_key[1]     = -1;
	fps_plus_key[0]      = 0;
	fps_plus_key[1]      = 0;
	joy_fps_plus_key[0]  = -1;
	joy_fps_plus_key[1]  = -1;
	fps_minus_key[0]     = 0;
	fps_minus_key[1]     = 0;
	joy_fps_minus_key[0] = -1;
	joy_fps_minus_key[1] = -1;
	
	// ジョイスティックのボタンの数
	joykeyButtonNum = 16;
	SetJoyButtonMax(joykeyButtonNum);
	
	retry_key[0]         = 0;
	retry_key[1]         = 0;
	joy_retry_key[0]     = -1;
	joy_retry_key[1]     = -1;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   画面設定
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void screen_config_menu() {
	int cfg[4];
	int cursor, move;
	
	cfg[0] = screenMode;
	cfg[1] = systemmem;
	cfg[2] = screenColor;
	cfg[3] = useHires;
	loadScreenConfig(&cfg);
	cursor = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "SCREEN SETTING", 4);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "SIZE",      7 * (cursor == 0));
		printFontGrid(2, 4, "MEMORY",    7 * (cursor == 1));
		printFontGrid(2, 5, "COLOR",     7 * (cursor == 2));
		printFontGrid(2, 6, "USE HIRES", 7 * (cursor == 3));
		
		printFontGrid(1, 8, "SETTING WILL REFLECTED", 5);
		printFontGrid(1, 9, "WHEN YOU RESTART HEBORIS.", 5);
		
		// 設定値表示
		if(cfg[0] == 0) sprintf(string[0], "FULLSCREEN 320e240");
		else if(cfg[0] == 1) sprintf(string[0], "WINDOW 320e240");
		else if(cfg[0] == 2) sprintf(string[0], "WINDOW 640e480");
		else sprintf(string[0], "FULLSCREEN 640e480");
		printFontGrid(18, 3, string[0], 7 * (cursor == 0));
		
		if(!cfg[1]) sprintf(string[0], "VIDEO MEMORY (FAST)");
		else sprintf(string[0], "SYSTEM MEMORY (SLOW)");
		printFontGrid(18, 4, string[0], 7 * (cursor == 1));
		
		sprintf(string[0], "%d BIT", cfg[2]);
		printFontGrid(18, 5, string[0], 7 * (cursor == 2));
		
		if(!cfg[3]) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(18, 6, string[0], 7 * (cursor == 3));
		
		// カーソル移動
		padRepeat2(0);
		
		// ↑
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if(getPressState(0, 0)) {
			PlaySE(se_move);
			cursor--;
			if(cursor < 0) cursor = 3;
		}
		
		// ↓
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if(getPressState(0, 1)) {
			PlaySE(se_move);
			cursor++;
			if(cursor > 3) cursor = 0;
		}
		
		// 値を変更
		padRepeat(0);
		
		move = 0;
		if((mpc[0] == 1) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6))
			move = getPressState(0, 3) - getPressState(0, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) {
				cfg[0] = cfg[0] + move;
				if(cfg[0] < 0) cfg[0] = 3;
				if(cfg[0] > 3) cfg[0] = 0;
			}
			if(cursor == 1) cfg[1] = !cfg[1];
			if(cursor == 2) {
				cfg[2] = cfg[2] + move * 8;
				if(cfg[2] < 16) cfg[2] = 32;
				if(cfg[2] > 32) cfg[2] = 16;
			}
			if(cursor == 3) cfg[3] = !cfg[3];
		}
		
		// キャンセル
		if(getPushState(0, 5)) {
			return;
		}
		
		// 決定
		if(getPushState(0, 4)) {
			PlaySE(se_kettei);
			saveScreenConfig(&cfg);
			return;
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ミュージックテスト
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void music_test() {
	int number, move, pos;
	number = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "MUSIC TEST", 4);
		
		sprintf(string[0], "MUSIC NUMBER: %d/29", number);
		printFontGrid(1, 3, string[0], 7);
		
		pos = GetPosWave(bgm_plane[number]);
		if(pos != -1) {
			sprintf(string[0], "POSITION: %d", pos);
			printFontGrid(1, 5, string[0], 0);
			sprintf(string[0], "FADE LV : %d", fadelv);
			printFontGrid(1, 6, string[0], 0);
		}
		
		printFontGrid(1,  8, "A: PLAY", 6);
		printFontGrid(1,  9, "B: EXIT", 6);
		
		if((pos != -1) || (bgmtype == 3)) {
			printFontGrid(1, 10, "C: STOP", 6);
			printFontGrid(1, 11, "D: PAUSE", 6);
			if(bgmtype != 3) printFontGrid(1, 12, "E: FADE", 6);
		}
		
		// キー入力
		padRepeat(0);
		
		move = getPressState(0, 3) - getPressState(0, 2);
		
		if((mpc[0] == 1) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6))
		if(move) {
			number = number + move;
			if(number < 0) number = 29;
			if(number > 29) number = 0;
		}
		
		// 決定
		if(getPushState(0, 4)) {
			ReleaseAllBGM();
			fadelv = 0;
			bgmlv = number;
			loadBGM(number);
			PlayBGM();
		}
		
		// キャンセル
		if(getPushState(0, 5)) {
			ReleaseAllBGM();
			fadelv = 0;
			return;
		}
		
		// 停止
		if(getPushState(0, 6)) {
			ReleaseAllBGM();
			fadelv = 0;
		}
		
		// 一時停止
		if(getPushState(0, 7)) {
			if(IsPlayWave(bgm_plane[number])) PauseWave(bgm_plane[number]);
			else ReplayWave(bgm_plane[number]);
		}
		
		// フェード
		if(getPushState(0, 8)) {
			fadelv = 1;
		}
		
		if(bgmtype != 0) bgmFadeout();
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   SEテスト
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void se_test() {
	int number, move;
	number = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "SE TEST", 4);
		
		sprintf(string[0], "SE NUMBER: %d/%d", number, sound_count - 1);
		printFontGrid(1, 3, string[0], 7);
		
		if(sound_plane_type[number] == 0) printFontGrid(1, 4, "TYPE: NONE", 0);
		if(sound_plane_type[number] == 1) printFontGrid(1, 4, "TYPE: SYSTEM SE", 0);
		if(sound_plane_type[number] == 2) printFontGrid(1, 4, "TYPE: SYSTEM BGM", 0);
		if(sound_plane_type[number] == 3) printFontGrid(1, 4, "TYPE: PLUGIN SE", 0);
		if(sound_plane_type[number] == 4) printFontGrid(1, 4, "TYPE: PLUGIN BGM", 0);
		
		printFontGrid(1, 6, "A: PLAY", 6);
		printFontGrid(1, 7, "B: EXIT", 6);
		printFontGrid(1, 8, "C: STOP", 6);
		
		// キー入力
		padRepeat(0);
		
		move = getPressState(0, 3) - getPressState(0, 2);
		
		if((mpc[0] == 1) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6))
		if(move) {
			number = number + move;
			if(number < 0) number = sound_count - 1;
			if(number > sound_count - 1) number = 0;
		}
		
		// 決定
		if(getPushState(0, 4)) {
			StopAllSE();
			PlaySE(number);
		}
		
		// キャンセル
		if(getPushState(0, 5)) {
			StopAllWave();
			return;
		}
		
		// 停止
		if(getPushState(0, 6)) {
			StopAllSE();
		}
	}
}
