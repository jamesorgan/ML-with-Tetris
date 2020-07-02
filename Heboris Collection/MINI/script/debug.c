// デバッグメニュー
void debugMenu(int ingame) {
	int cursor;
	
	if(!debug_enable) return;
	
	cursor = 0;
	
	loop {
		spriteTime();
		KeyInput();
		
		printFontGrid(1, 1, "DEBUG MENU", 4);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "SYSTEM LOG",    7 * (cursor == 0));
		printFontGrid(2, 4, "RULE LOG",      7 * (cursor == 1));
		printFontGrid(2, 5, "MODE LOG",      7 * (cursor == 2));
		printFontGrid(2, 6, "RULE DEBUG",    7 * (cursor == 3));
		printFontGrid(2, 7, "MODE DEBUG",    7 * (cursor == 4));
		printFontGrid(2, 8, "GRAPHICS VIEW", 7 * (cursor == 5));
		
		// カーソル移動
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
			
			if(cursor == 0) debugLogView(0);
			if(cursor == 1) debugLogView(1);
			if(cursor == 2) debugLogView(2);
			if((cursor == 3) && (ingame)) executePlugin(0, 66, &dummy);
			if((cursor == 4) && (ingame)) executePlugin(0, 67, &dummy);
			if(cursor == 5) debugGraphicsView();
		}
	}
}

// デバッグログを表示
void debugLogView(int type) {
	int i, cnt, page;
	page = 0;
	cnt = 0;
	
	loop {
		spriteTime();
		KeyInput();
		
		sprintf(string[0], "%d/2", page + 1);
		printTinyFont(304, 233, string[0]);
		
		if(cnt == 0) {
			for(i = 0; i < 20; i++) {
				ExTextLayerOn(44 + i, 0, i * 12);
				ExTextSize(44 + i, 12);
				TextColor(44 + i, 255, 255, 255);
				TextBackColorDisable(44 + i);
				if(type == 0) TextOut(44 + i, debug_log_system[i + page * 20]);
				if(type == 1) TextOut(44 + i, debug_log_rule[i + page * 20]);
				if(type == 2) TextOut(44 + i, debug_log_mode[i + page * 20]);
			}
		}
		
		// ページ切り替え
		if(getPushState(0, 0) || getPushState(0, 1)) {
			PlaySE(se_move);
			page = !page;
			cnt = -1;
		}
		
		// 消去
		if(getPushState(0, 7)) {
			PlaySE(se_kachi);
			debugLogClear(type);
			cnt = -1;
		}
		
		// 戻る
		if(getPushState(0, 4) || getPushState(0, 5)) {
			for(i = 0; i < 20; i++) TextLayerOff(44 + i);
			return;
		}
		
		cnt++;
	}
}

// デバッグログを消去
void debugLogClear(int type) {
	int i;
	
	if(!debug_enable) return;
	
	for(i = 0; i < 40; i++) {
		if(type == 0) StrCpy(debug_log_system[i], "");
		if(type == 1) StrCpy(debug_log_rule[i], "");
		if(type == 2) StrCpy(debug_log_mode[i], "");
	}
}

// デバッグログを出力（システム）
void debugLogSystem(str *msg) {
	int i;
	
	// ErrorLog.txtに出力（ygs2kのデバッグモードが有効の場合）
	sprintf(string[15], "[SYST]{%s}", msg);
	InnerLogMes(string[15]);
	
	if(!debug_enable) return;
	
	// ログをずらす
	for(i = 39; i > 0; i--) StrCpy(debug_log_system[i], debug_log_system[i - 1]);
	
	// ログを追加
	StrCpy(debug_log_system[0], msg);
}

// デバッグログを出力（ルール）
void debugLogRule(str *msg) {
	int i;
	
	// ErrorLog.txtに出力（ygs2kのデバッグモードが有効の場合）
	sprintf(string[15], "[RULE]{%s}", msg);
	InnerLogMes(string[15]);
	
	if(!debug_enable) return;
	
	// ログをずらす
	for(i = 39; i > 0; i--) StrCpy(debug_log_rule[i], debug_log_rule[i - 1]);
	
	// ログを追加
	StrCpy(debug_log_rule[0], msg);
}

// デバッグログを出力（モード）
void debugLogMode(str *msg) {
	int i;
	
	// ErrorLog.txtに出力（ygs2kのデバッグモードが有効の場合）
	sprintf(string[15], "[MODE]{%s}", msg);
	InnerLogMes(string[15]);
	
	if(!debug_enable) return;
	
	// ログをずらす
	for(i = 39; i > 0; i--) StrCpy(debug_log_mode[i], debug_log_mode[i - 1]);
	
	// ログを追加
	StrCpy(debug_log_mode[0], msg);
}

// グラフィック表示
void debugGraphicsView() {
	int i, no, hide;
	no = 0;
	hide = 0;
	
	loop {
		spriteTime();
		KeyInput();
		
		BltFast(no, 0, 0);
		
		if(!hide) {
			printFontGrid(1, 1, "GRAPHICS VIEW", 4);
			sprintf(string[0], "kn %d/%d", no, graphics_count - 1);
			printFontGrid(1, 2, string[0], 1);
			printFontGrid(1, 3, "C: HIDE MESSAGE", 5);
		}
		
		padRepeat2(0);
		
		// ↑
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if(getPressState(0, 0)) {
			PlaySE(se_move);
			no--;
			if(no < 0) no = graphics_count - 1;
		}
		
		// ↓
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if(getPressState(0, 1)) {
			PlaySE(se_move);
			no++;
			if(no > graphics_count - 1) no = 0;
		}
		
		// 文字非表示
		if(getPushState(0, 6)) {
			PlaySE(se_kachi);
			hide = !hide;
		}
		
		// 戻る
		if(getPushState(0, 4) || getPushState(0, 5)) {
			return;
		}
	}
}
