//hoge heboris.iniで設定されたwaitを実際のwaitに代入するための関数。
// 現在はFAVORITES.SAVから読み込み
void loadWait(int player, int no) {
	if(syutugen[no] != -1) wait1[player] = syutugen[no];
	if(syoukyo[no]  != -1) wait2[player] = syoukyo[no];
	if(settyaku[no] != -1) wait3[player] = settyaku[no];
	if(yokotame[no] != -1) waitt[player] = yokotame[no];
	if(speed[no]    != -1) sp[player]    = speed[no];
	if(fps[no]      != -1) p_fps         = fps[no];
	if(pbgm[no]     != -1) bgmlv         = pbgm[no];
}

// 設定が空かどうか判定
int favorites_isempty(int no) {
	if(syutugen[no] != -1) return 0;
	if(syoukyo[no]  != -1) return 0;
	if(settyaku[no] != -1) return 0;
	if(yokotame[no] != -1) return 0;
	if(speed[no]    != -1) return 0;
	if(fps[no]      != -1) return 0;
	if(pbgm[no]     != -1) return 0;
	
	return 1;
}

// デフォルト設定を作成
void favorites_set_default() {
	StrCpy(waitname[0],  "BEGINNER       ");
	syutugen[0] = 26;
	syoukyo[0] = 40;
	settyaku[0] = 28;
	yokotame[0] = 15;
	speed[0] = 1;
	fps[0] = 60;
	pbgm[0] = 0;
	waitkey[0] = 0x02;
	
	StrCpy(waitname[1],  "INFINITY       ");
	syutugen[1] = -1;
	syoukyo[1] = -1;
	settyaku[1] = 99;
	yokotame[1] = -1;
	speed[1] = -1;
	fps[1] = -1;
	pbgm[1] = -1;
	waitkey[1] = 0x03;
	
	StrCpy(waitname[2],  "20G            ");
	syutugen[2] = 26;
	syoukyo[2] = 40;
	settyaku[2] = 28;
	yokotame[2] = 12;
	speed[2] = 1200;
	fps[2] = -1;
	pbgm[2] = 1;
	waitkey[2] = 0x04;
	
	StrCpy(waitname[3],  "MASTER 5XX     ");
	syutugen[3] = 25;
	syoukyo[3] = 29;
	settyaku[3] = 28;
	yokotame[3] = 10;
	speed[3] = 1200;
	fps[3] = -1;
	pbgm[3] = 1;
	waitkey[3] = 0x05;
	
	StrCpy(waitname[4],  "DOOM 0XX       ");
	syutugen[4] = 11;
	syoukyo[4] = 8;
	settyaku[4] = 20;
	yokotame[4] = 9;
	speed[4] = 1200;
	fps[4] = -1;
	pbgm[4] = 2;
	waitkey[4] = 0x06;
	
	StrCpy(waitname[5],  "HARD 0XX       ");
	syutugen[5] = 10;
	syoukyo[5] = 4;
	settyaku[5] = 20;
	yokotame[5] = 10;
	speed[5] = 1200;
	fps[5] = -1;
	pbgm[5] = 2;
	waitkey[5] = 0x07;
	
	StrCpy(waitname[6],  "DEVIL 0XX      ");
	syutugen[6] = 18;
	syoukyo[6] = 8;
	settyaku[6] = 30;
	yokotame[6] = 12;
	speed[6] = 1200;
	fps[6] = -1;
	pbgm[6] = 1;
	waitkey[6] = 0x08;
	
	StrCpy(waitname[7],  "ANOTHER 01     ");
	syutugen[7] = 18;
	syoukyo[7] = 14;
	settyaku[7] = 28;
	yokotame[7] = 10;
	speed[7] = 1200;
	fps[7] = -1;
	pbgm[7] = 5;
	waitkey[7] = 0x09;
	
	StrCpy(waitname[8],  "ANOTHER 15     ");
	syutugen[8] = 6;
	syoukyo[8] = 4;
	settyaku[8] = 13;
	yokotame[8] = 7;
	speed[8] = 1200;
	fps[8] = -1;
	pbgm[8] = 4;
	waitkey[8] = 0x0A;
	
	StrCpy(waitname[9],  "DOOM 1200      ");
	syutugen[9] = 3;
	syoukyo[9] = 2;
	settyaku[9] = 9;
	yokotame[9] = 5;
	speed[9] = 1200;
	fps[9] = -1;
	pbgm[9] = 5;
	waitkey[9] = 0x0B;
	
	StrCpy(waitname[10], "HARD 1200      ");
	syutugen[10] = 2;
	syoukyo[10] = 0;
	settyaku[10] = 10;
	yokotame[10] = 6;
	speed[10] = 1200;
	fps[10] = -1;
	pbgm[10] = 5;
	waitkey[10] = 0x00;
	
	StrCpy(waitname[11], "VOID 05        ");
	syutugen[11] = 1;
	syoukyo[11] = 0;
	settyaku[11] = 9;
	yokotame[11] = 4;
	speed[11] = 1200;
	fps[11] = -1;
	pbgm[11] = 5;
	waitkey[11] = 0x00;
	
	StrCpy(waitname[12], "VOID 10        ");
	syutugen[12] = 0;
	syoukyo[12] = 0;
	settyaku[12] = 9;
	yokotame[12] = 3;
	speed[12] = 1200;
	fps[12] = -1;
	pbgm[12] = 5;
	waitkey[12] = 0x00;
	
	StrCpy(waitname[13], "VOID 20        ");
	syutugen[13] = 0;
	syoukyo[13] = 0;
	settyaku[13] = 8;
	yokotame[13] = 2;
	speed[13] = 1200;
	fps[13] = -1;
	pbgm[13] = 5;
	waitkey[13] = 0x00;
	
	StrCpy(waitname[14], "FINAL          ");
	syutugen[14] = 0;
	syoukyo[14] = 0;
	settyaku[14] = 3;
	yokotame[14] = 0;
	speed[14] = 1200;
	fps[14] = -1;
	pbgm[14] = 5;
	waitkey[14] = 0x00;
}

// 初期化
void favorites_init() {
	int i;
	
	for(i = 0; i < 20; i++) {
		waitname[i] = new(17);	// 15 + NULL
		StrCpy(waitname[i], "EMPTY          ");
		syutugen[i] = -1;
		syoukyo[i] = -1;
		settyaku[i] = -1;
		yokotame[i] = -1;
		speed[i] = -1;
		fps[i] = -1;
		pbgm[i] = -1;
		waitkey[i] = 0x00;
	}
}

// FAVORITE編集画面（CONFIG画面から呼ばれる）
void config_favorites() {
	p_setting = p_def_setting;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		printFont(1, 1, "EDIT FAVORITES", fontc[rots[0]]);
		
		printFont(1, 3 + statc[8], "b", fontc[rots[0]]);
		
		// 設定項目名表示
		printFont(2,  3, "SETTING NUMBER:", fontc[rots[0]] * (statc[8] == 0));
		printFont(2,  4, "[NAME]        :", fontc[rots[0]] * (statc[8] == 1));
		sprintf(string[0], "%s      :", delayname[0 + english * 4]);
		printFont(2,  5, string[0], fontc[rots[0]] * (statc[8] == 2));
		sprintf(string[0], "%s      :", delayname[1 + english * 4]);
		printFont(2,  6, string[0], fontc[rots[0]] * (statc[8] == 3));
		sprintf(string[0], "%s      :", delayname[2 + english * 4]);
		printFont(2,  7, string[0], fontc[rots[0]] * (statc[8] == 4));
		sprintf(string[0], "%s      :", delayname[3 + english * 4]);
		printFont(2,  8, string[0], fontc[rots[0]] * (statc[8] == 5));
		printFont(2,  9, "SPEED         :", fontc[rots[0]] * (statc[8] == 6));
		printFont(2, 10, "FPS           :", fontc[rots[0]] * (statc[8] == 7));
		printFont(2, 11, "BGM           :", fontc[rots[0]] * (statc[8] == 8));
		printFont(2, 12, "[SHORTCUT KEY]:", fontc[rots[0]] * (statc[8] == 9));
		
		if(statc[8] == 1) {
			printFont(1, 15, "PRESS A TO ENTER NAME", fontc[rots[0]]);
		} else if(statc[8] == 9) {
			printFont(1, 15, "PRESS A TO SET SHORTCUT KEY", fontc[rots[0]]);
		} else {
			printFont(1, 15, "PRESS A TO SAVE", fontc[rots[0]]);
		}
		printFont(1, 16, "PRESS B TO DISCARD CHANGES", fontc[rots[0]]);
		
		// 設定値表示
		sprintf(string[0], "%d", p_setting + 1);
		printFont(18, 3, string[0], fontc[rots[0]] * (statc[8] == 0));
		
		printFont(18, 4, waitname[p_setting], fontc[rots[0]] * (statc[8] == 1));
		
		if(syutugen[p_setting] == -1)
			sprintf(string[0], "NO CHANGE");
		else
			sprintf(string[0], "%d", syutugen[p_setting]);
		printFont(18, 5, string[0], fontc[rots[0]] * (statc[8] == 2));
		
		if(syoukyo[p_setting] == -1)
			sprintf(string[0], "NO CHANGE");
		else
			sprintf(string[0], "%d", syoukyo[p_setting]);
		printFont(18, 6, string[0], fontc[rots[0]] * (statc[8] == 3));
		
		if(settyaku[p_setting] == -1)
			sprintf(string[0], "NO CHANGE");
		else
			sprintf(string[0], "%d", settyaku[p_setting]);
		printFont(18, 7, string[0], fontc[rots[0]] * (statc[8] == 4));
		
		if(yokotame[p_setting] == -1)
			sprintf(string[0], "NO CHANGE");
		else
			sprintf(string[0], "%d", yokotame[p_setting]);
		printFont(18, 8, string[0], fontc[rots[0]] * (statc[8] == 5));
		
		if(speed[p_setting] == -1)
			sprintf(string[0], "NO CHANGE");
		else
			sprintf(string[0], "%d", speed[p_setting]);
		printFont(18, 9, string[0], fontc[rots[0]] * (statc[8] == 6));
		
		if(fps[p_setting] == -1)
			sprintf(string[0], "NO CHANGE");
		else
			sprintf(string[0], "%d", fps[p_setting]);
		printFont(18, 10, string[0], fontc[rots[0]] * (statc[8] == 7));
		
		if(pbgm[p_setting] == -1)
			sprintf(string[0], "NO CHANGE");
		else
			sprintf(string[0], "%d", pbgm[p_setting] + 1);
		printFont(18, 11, string[0], fontc[rots[0]] * (statc[8] == 8));
		
		if(waitkey[p_setting] == 0)
			sprintf(string[0], "NO SHORTCUT KEY");
		else
			sprintf(string[0], "%02X", waitkey[p_setting]);
		printFont(18, 12, string[0], fontc[rots[0]] * (statc[8] == 9));
		
		// 設定値変更
		padRepeat(0);
		
		// ←
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 2) ) {
			PlaySE(3);
			
			if(statc[8] == 0) {
				p_setting--;
				if(p_setting < 0) p_setting = 19;
			}
			if(statc[8] == 2) {
				syutugen[p_setting]--;
				if(syutugen[p_setting] < -1) syutugen[p_setting] = 99;
			}
			if(statc[8] == 3) {
				syoukyo[p_setting]--;
				if(syoukyo[p_setting] < -1) syoukyo[p_setting] = 99;
			}
			if(statc[8] == 4) {
				settyaku[p_setting]--;
				if(settyaku[p_setting] < -1) settyaku[p_setting] = 99;
			}
			if(statc[8] == 5) {
				yokotame[p_setting]--;
				if(yokotame[p_setting] < -1) yokotame[p_setting] = 99;
			}
			if(statc[8] == 6) {
				speed[p_setting]--;
				if(speed[p_setting] < -1) speed[p_setting] = 1200;
			}
			if(statc[8] == 7) {
				fps[p_setting]--;
				if(fps[p_setting] < -1) fps[p_setting] = 99;
			}
			if(statc[8] == 8) {
				pbgm[p_setting]--;
				if(pbgm[p_setting] < -1) pbgm[p_setting] = 20;
			}
		}
		
		// →
		if( (mpc[0] == 1 ) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6) )
		if( getPressState(0, 3) ) {
			PlaySE(3);
			
			if(statc[8] == 0) {
				p_setting++;
				if(p_setting > 19) p_setting = 0;
			}
			if(statc[8] == 2) {
				syutugen[p_setting]++;
				if(syutugen[p_setting] > 99) syutugen[p_setting] = -1;
			}
			if(statc[8] == 3) {
				syoukyo[p_setting]++;
				if(syoukyo[p_setting] > 99) syoukyo[p_setting] = -1;
			}
			if(statc[8] == 4) {
				settyaku[p_setting]++;
				if(settyaku[p_setting] > 99) settyaku[p_setting] = -1;
			}
			if(statc[8] == 5) {
				yokotame[p_setting]++;
				if(yokotame[p_setting] > 99) yokotame[p_setting] = -1;
			}
			if(statc[8] == 6) {
				speed[p_setting]++;
				if(speed[p_setting] > 99) speed[p_setting] = -1;
			}
			if(statc[8] == 7) {
				fps[p_setting]++;
				if(fps[p_setting] > 99) fps[p_setting] = -1;
			}
			if(statc[8] == 8) {
				pbgm[p_setting]++;
				if(pbgm[p_setting] > 20) pbgm[p_setting] = -1;
			}
		}
		
		// カーソル移動
		padRepeat2(0);
		
		// ↑
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 0) ) {
			PlaySE(5);
			
			statc[8]--;
			if(statc[8] < 0) statc[8] = 9;
		}
		
		// ↓
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if( getPressState(0, 1) ) {
			PlaySE(5);
			
			statc[8]++;
			if(statc[8] > 9) statc[8] = 0;
		}
		
		// キャンセル
		if( getPushState(0, 5) ) {
			favorites_load();
			return;
		}
		
		// 決定
		if( getPushState(0, 4) ) {
			PlaySE(10);
			
			if(statc[8] == 1) {
				config_favorites_name();
			} else if(statc[8] == 9) {
				config_favorites_key();
			} else {
				favorites_save();
				return;
			}
		}
		
		if(!refresh_timing) spriteTime();
	}
}

// 名前入力
void config_favorites_name() {
	int move, cursor, len;
	
	// 初期化
	StrCpy(string[2], waitname[p_setting]);
	cursor = 54;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		printFont(1, 1, "ENTER NAME", fontc[rots[0]]);
		printFont(1, 2, "PRESS D TO CANCEL", fontc[rots[0]]);
		
		len = StrLen(string[2]);	// 入力済み文字数
		
		// 横移動
		padRepeat(0);
		move = getPressState(0, 3) - getPressState(0, 2);
		if(move)
			if((mpc[0] == 1) || (mpc[0] >= 15) || getPressState(0, 6)) {
				if(mpc[0] >= 15) mpc[0] = 12;
				cursor = cursor + move;
				PlaySE(5);
			}
		
		// 文字のループ
		if(cursor > 54)
			cursor = (len == 15) * 53;
		if(cursor < (len == 15) * 53)
			cursor = 54;
		
		// 選択している文字と入力済み文字を表示
		MidStr(RankString, cursor + 1, 1, string[4]);
		printFont(1 + len, 4, string[4], 2 * (count % 20 > 10));
		printFont(1, 4, string[2], 0);
		
		// Dでキャンセル
		if(getPushState(0, 7)) {
			return;
		}
		
		// Bボタンで1文字削除
		if(getPushState(0, 5)) {
			if(len) {
				PlaySE(5);
				MidStr(string[2], 1, len - 1, string[2]);
			}
		}
		
		// Aボタンで入力
		if(getPushState(0, 4)) {
			PlaySE(10);
			
			if(cursor == 53) {
				// RB
				if(len) {
					MidStr(string[2], 1, len - 1, string[2]);
				}
			} else if(cursor == 54) {
				// ED
				PlaySE(18);
				
				// 名前の後ろにスペースを挿入（余った個所をスペースにする）
				sprintf(string[2], "%s                ", string[2]);
				
				// 左から16文字目以降を削除
				LeftStr(string[2], 15, string[2]);
				
				// 保存
				StrCpy(waitname[p_setting], string[2]);
				
				// 終わり
				return;
			} else {
				// 文字入力
				StrCat(string[2], string[4]);
			}
		}
		
		count++;
		if(!refresh_timing) spriteTime();
	}
}

// ショートカットキー設定
void config_favorites_key() {
	int i, mode, key, cursor;
	mode = 0;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		printFont(1, 1, "SHORTCUT KEY SETTING", fontc[rots[0]]);
		
		if(mode == 0) {
			printFont(1, 3, "PUSH ANY KEY", fontc[rots[0]]);
			
			for(i = 0; i < 256; i++) {
				// キーが押された
				if( IsPushKey(i) ) {
					PlaySE(5);
					if(i == key_del) key = 0;
					else key = i;
					cursor = 0;
					mode++;
					break;
				}
			}
			
			printFont(2, 5, "DELETE (KEYBOARD) : NO ASSIGN", digitc[rots[0]]);
		} else {
			sprintf(string[0], "KEY: %02X", key);
			printFont(1, 3, string[0], fontc[rots[0]]);
			
			printFont(1, 5 + cursor, "b", fontc[rots[0]]);
			
			printFont(2, 5, "OK",                  fontc[rots[0]] * (cursor == 0));
			printFont(2, 6, "RETRY",               fontc[rots[0]] * (cursor == 1));
			printFont(2, 7, "DELETE SHORTCUT KEY", fontc[rots[0]] * (cursor == 2));
			printFont(2, 8, "CANCEL",              fontc[rots[0]] * (cursor == 3));
			
			// カーソル移動
			padRepeat2(0);
			
			// ↑
			if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
			if( getPressState(0, 0) ) {
				PlaySE(5);
				cursor--;
				if(cursor < 0) cursor = 3;
			}
			
			// ↓
			if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
			if( getPressState(0, 1) ) {
				PlaySE(5);
				cursor++;
				if(cursor > 3) cursor = 0;
			}
			
			// キャンセル
			if( getPushState(0, 5) ) {
				return;
			}
			
			// 決定
			if( getPushState(0, 4) ) {
				PlaySE(10);
				
				if(cursor == 0) {
					// OK
					waitkey[p_setting] = key;
					return;
				}
				if(cursor == 1) {
					// RETRY
					mode = 0;
				}
				if(cursor == 2) {
					// DELETE SHORTCUT KEY
					waitkey[p_setting] = 0;
					return;
				}
				if(cursor == 3) {
					// CANCEL
					return;
				}
			}
		}
		
		if(!refresh_timing) spriteTime();
	}
}

// セーブ
void favorites_save() {
	int i, temp[4];
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x4554494C;
	saveBuf[2] = 0x4F564146;
	saveBuf[3] = 0x31544952;
	
	for(i = 0; i < 20; i++) {
		// 名前
		StrCpy(&temp, waitname[i]);
		saveBuf[4 + i * 20 +  0] = temp[0];
		saveBuf[4 + i * 20 +  1] = temp[1];
		saveBuf[4 + i * 20 +  2] = temp[2];
		saveBuf[4 + i * 20 +  3] = temp[3];
		
		// 設定値
		saveBuf[4 + i * 20 +  4] = syutugen[i];
		saveBuf[4 + i * 20 +  5] = syoukyo[i];
		saveBuf[4 + i * 20 +  6] = settyaku[i];
		saveBuf[4 + i * 20 +  7] = yokotame[i];
		saveBuf[4 + i * 20 +  8] = speed[i];
		saveBuf[4 + i * 20 +  9] = fps[i];
		saveBuf[4 + i * 20 + 10] = pbgm[i];
		saveBuf[4 + i * 20 + 11] = waitkey[i];
	}
	
	// 保存
	SaveFile("FAVORITES.SAV", &saveBuf, 404 * 4);
}

// ロード
int favorites_load() {
	int i, temp[4];
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	// ヘッダだけ読み込み
	LoadFile("FAVORITES.SAV", &saveBuf, 4 * 4);
	
	// ヘッダが違う
	if(saveBuf[0] != 0x4F424548) return -1;
	if(saveBuf[1] != 0x4554494C) return -1;
	if(saveBuf[2] != 0x4F564146) return -1;
	if(saveBuf[3] != 0x31544952) return -1;
	
	// 読み込み
	LoadFile("FAVORITES.SAV", &saveBuf, 404 * 4);
	
	for(i = 0; i < 20; i++) {
		// 名前
		temp[0] = saveBuf[4 + i * 20 +  0];
		temp[1] = saveBuf[4 + i * 20 +  1];
		temp[2] = saveBuf[4 + i * 20 +  2];
		temp[3] = saveBuf[4 + i * 20 +  3];
		StrCpy(waitname[i], &temp);
		
		// 設定値
		syutugen[i] = saveBuf[4 + i * 20 +  4];
		syoukyo[i]  = saveBuf[4 + i * 20 +  5];
		settyaku[i] = saveBuf[4 + i * 20 +  6];
		yokotame[i] = saveBuf[4 + i * 20 +  7];
		speed[i]    = saveBuf[4 + i * 20 +  8];
		fps[i]      = saveBuf[4 + i * 20 +  9];
		pbgm[i]     = saveBuf[4 + i * 20 + 10];
		waitkey[i]  = saveBuf[4 + i * 20 + 11];
	}
	
	return 0;
}
