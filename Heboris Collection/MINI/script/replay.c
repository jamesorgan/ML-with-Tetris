//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   リプレイデータをセーブ
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void saveReplayData(int player, int number) {
	int i, j, temp, max, strbuf[8], timebuf[8];
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ファイルフォーマット (4byte単位)
	//    0～      3 ヘッダ
	//    4          ファイルサイズ
	//    5～    179 ネクストブロック
	//  180～    187 使用したルールの名前
	//  188～    195 使用したモードの名前
	//  196～    199 使用したバージョン
	//  200～    399 ゲームの設定など
	//  400～    899 ルールプラグインが自由に使えるエリア
	//  900～   1399 モードプラグインが自由に使えるエリア
	// 1400～ 109400 リプレイデータ
	
	// ヘッダ
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x4C504552;
	saveBuf[3] = 0x31765941;
	
	// NEXTブロック
	for(i = 0; i < 175; i++) {
		temp = 0;
		for(j = 0; j < 8; j++) {
			temp = temp | (nextb[(i << 3) + j + player * 1400] << (j * 4));
		}
		saveBuf[i + 5] = temp;
	}
	
	// 使用したルールの名前
	for(i = 0; i < 8; i++) strbuf[i] = 0;
	StrCpy(&strbuf, plugin_name_rule[rots[player]]);
	for(i = 0; i < 8; i++) saveBuf[180 + i] = strbuf[i];
	
	// 使用したモードの名前
	for(i = 0; i < 8; i++) strbuf[i] = 0;
	StrCpy(&strbuf, plugin_name_mode[gameMode[player]]);
	for(i = 0; i < 8; i++) saveBuf[188 + i] = strbuf[i];
	
	// 使用したバージョン
	saveBuf[196] = versionNo;
	saveBuf[197] = engineVer;
	
	// ゲームの設定など
	saveBuf[200] = recTimer[player];		// リプレイの時間
	saveBuf[201] = gameTimer[player];		// ゲーム内の時間
	saveBuf[202] = firstseed[player];		// 乱数シード
	saveBuf[203] = nanameallow;				// 斜め入力無効化
	saveBuf[204] = dispnext;				// NEXTの数
	saveBuf[205] = downtype;				// 連続上入れ下入れ制限の種類
	saveBuf[206] = spawn_y_type;			// ブロックの出現位置
	saveBuf[207] = kicktype[player];		// 壁蹴りタイプ
	saveBuf[208] = lockreset[player];		// 固定時間リセット
	saveBuf[209] = rotlimit[player];		// 回転数制限
	saveBuf[210] = movelimit[player];		// 移動数制限
	saveBuf[211] = blockgraphics[player];	// ブロックのグラフィック
	saveBuf[212] = are[player];				// AREの有無
	saveBuf[213] = lock_up[player];			// 上入れ即固定
	saveBuf[214] = lock_down[player];		// 下入れ即固定
	saveBuf[215] = rot_reverse[player];		// 回転方向逆転
	saveBuf[216] = softspeed[player];		// 下入れスピード
	saveBuf[217] = max_waitt[player];		// 最高横溜め
	saveBuf[218] = fastlrmove[player];		// 先行横移動
	saveBuf[219] = oblk_bg[player];			// []の時の背景
	saveBuf[220] = mps[player * 2];			// スタート時の入力方向
	saveBuf[221] = mps[player * 2 + 1];		// スタート時の横溜め
	for(i = 0; i < 7; i++) saveBuf[222 + i] = blockcolor[player * 7 + i];	// ブロックの色
	saveBuf[229] = initial_rotate[player];	// 先行回転
	saveBuf[230] = initial_hold[player];	// 先行ホールド
	saveBuf[231] = enable_wallkick[player];	// 壁蹴り
	saveBuf[232] = self_lock_sound[player];	// 自分で固定させたときに音を出す
	saveBuf[233] = lockflash[player];		// ブロックを固定させた瞬間、ブロックが光るフレーム数
	saveBuf[234] = disable180;				// Eボタンを逆回転ボタンにする
	
	// 作成日時を記録
	GetDateAndTime(&timebuf);
	for(i = 0; i < 8; i++) saveBuf[235 + i] = timebuf[i];
	
	saveBuf[243] = disable_hold;			// HOLD無効化
	saveBuf[244] = RepeatDelay[player];		// RepeatDelay
	
	// プラグインを呼び出す
	executePlugin(player, 39, &dummy);
	
	// 操作データを保存
	max = recTimer[player];
	if(max > 60 * 60 * 30) max = 60 * 60 * 30;
	for(i = 0; i < max; i++) saveBuf[1400 + i] = replayData[player * 108000 + i];
	
	// ファイルサイズを保存
	saveBuf[4] = (max + 1400) * 4;
	
	// ファイルに書き込み
	if(player == 0) sprintf(string[0], "replay/REPLAY%02d.SAV", number + 1);
	else sprintf(string[0], "replay/REPLAY%02d_2P.SAV", number + 1);
	SaveFile(string[0], &saveBuf, saveBuf[4]);
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   リプレイデータをロード
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int loadReplayData(int player, int number) {
	int i, j, temp, max, strbuf[8];
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダだけ読み込み
	if(player == 0) sprintf(string[0], "replay/REPLAY%02d.SAV", number + 1);
	else sprintf(string[0], "replay/REPLAY%02d_2P.SAV", number + 1);
	LoadFile(string[0], &saveBuf, 5 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x4C504552) return 0;
	if(saveBuf[3] != 0x31765941) return 0;
	
	// 全部読み込み
	LoadFile(string[0], &saveBuf, saveBuf[4]);
	
	// 使用したルールの名前
	for(i = 0; i < 8; i++) strbuf[i] = saveBuf[180 + i];
	StrCpy(string[1], &strbuf);
	temp = findRulePlugin(string[1]);
	rots[player] = temp;
	
	// 使用したモードの名前
	for(i = 0; i < 8; i++) strbuf[i] = saveBuf[188 + i];
	StrCpy(string[2], &strbuf);
	temp = findModePlugin(string[2]);
	gameMode[player] = temp;
	
	sprintf(string[0], "player:%d rule:%s(%d) mode:%s(%d)", player, string[1], rots[player], string[2], gameMode[player]);
	debugLogSystem(string[0]);
	
	// 初期化
	playerInitial(player);
	
	// NEXTブロック
	for(i = 0; i < 175; i++) {
		for(j = 0; j < 8; j++) {
			nextb[(i << 3) + j + player * 1400] = ((saveBuf[5 + i]) >> (j * 4)) & 15;
		}
	}
	setNextBlockColor(player, 1);
	
	// 使用したバージョン
	engineVer = saveBuf[197];
	
	// ゲームの設定など
	firstseed[player] = saveBuf[202];		// 乱数シード
	randseed[player] = firstseed[player];	// 乱数シード
	nanameallow = saveBuf[203];				// 斜め入力無効化
	dispnext = saveBuf[204];				// NEXTの数
	downtype = saveBuf[205];				// 連続上入れ下入れ制限の種類
	spawn_y_type = saveBuf[206];			// ブロックの出現位置
	kicktype[player] = saveBuf[207];		// 壁蹴りタイプ
	lockreset[player] = saveBuf[208];		// 固定時間リセット
	rotlimit[player] = saveBuf[209];		// 回転数制限
	movelimit[player] = saveBuf[210];		// 移動数制限
	blockgraphics[player] = saveBuf[211];	// ブロックのグラフィック
	are[player] = saveBuf[212];				// AREの有無
	lock_up[player] = saveBuf[213];			// 上入れ即固定
	lock_down[player] = saveBuf[214];		// 下入れ即固定
	rot_reverse[player] = saveBuf[215];		// 回転方向逆転
	softspeed[player] = saveBuf[216];		// 下入れスピード
	max_waitt[player] = saveBuf[217];		// 最高横溜め
	fastlrmove[player] = saveBuf[218];		// 先行横移動
	oblk_bg[player] = saveBuf[219];			// []の時の背景
	mps[player * 2] = saveBuf[220];			// スタート時の入力方向
	mps[player * 2 + 1] = saveBuf[221];		// スタート時の横溜め
	if(engineVer >= 1) {
		// ブロックの色
		for(i = 0; i < 7; i++) blockcolor[player * 7 + i] = saveBuf[222 + i];
	}
	if(engineVer >= 3) {
		initial_rotate[player] = saveBuf[229];	// 先行回転
		initial_hold[player] = saveBuf[230];	// 先行ホールド
		enable_wallkick[player] = saveBuf[231];	// 壁蹴り
	}
	self_lock_sound[player] = saveBuf[232];	// 自分で固定させたときに音を出す
	
	if(engineVer >= 5) {
		lockflash[player] = saveBuf[233];	// ブロックを固定させた瞬間、ブロックが光るフレーム数
	}
	disable180 = saveBuf[234];				// Eボタンを逆回転ボタンにする
	
	disable_hold = saveBuf[243];			// HOLD無効化
	if(disable_hold) dhold[player] = 2;
	else dhold[player] = 0;
	
	RepeatDelay[player] = saveBuf[244];		// RepeatDelay
	
	// 操作データを読み込み
	max = saveBuf[200];
	if(max > 60 * 60 * 30) max = 60 * 60 * 30;
	
	for(i = 0; i < max; i++) replayData[player * 108000 + i] = saveBuf[1400 + i];
	
	// プラグインを呼び出す
	executePlugin(player, 40, &dummy);
	
	return 1;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   リプレイが存在するかどうか判定
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int isReplayExist(int number) {
	int i, strbuf[8];
	
	FillMemory(&saveBuf, 4 * 4, 0);
	
	// ヘッダだけ読み込み
	sprintf(string[0], "replay/REPLAY%02d.SAV", number + 1);
	LoadFile(string[0], &saveBuf, 4 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x4C504552) return 0;
	if(saveBuf[3] != 0x31765941) return 0;
	
	// 一部読み込み
	LoadFile(string[0], &saveBuf, 400 * 4);
	
	// 使用したルールの名前
	for(i = 0; i < 8; i++) strbuf[i] = saveBuf[180 + i];
	StrCpy(replay_plugin_name_rule[number], &strbuf);
	
	// 使用したモードの名前
	for(i = 0; i < 8; i++) strbuf[i] = saveBuf[188 + i];
	StrCpy(replay_plugin_name_mode[number], &strbuf);
	
	// タイム
	replay_timer[number] = saveBuf[201];
	
	// 対応するプラグインがない
	if(findRulePlugin(replay_plugin_name_rule[number]) == -1) return -1;
	if(findModePlugin(replay_plugin_name_mode[number]) == -1) return -1;
	
	// 成功
	return 1;
}

// 全てのリプレイの存在をチェック
int checkAllReplayExist() {
	int i, temp, result;
	result = 0;
	
	for(i = 0; i < 40; i++) {
		temp = isReplayExist(i);
		replayexist[i] = temp;
		if(temp != 0) result++;
	}
	
	return result;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   リプレイを設定だけ読み込み（変数に代入はしない）
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int loadReplayHeader(int number) {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダだけ読み込み
	sprintf(string[0], "replay/REPLAY%02d.SAV", number + 1);
	LoadFile(string[0], &saveBuf, 5 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x4C504552) return 0;
	if(saveBuf[3] != 0x31765941) return 0;
	
	// 設定を全て読み込み
	LoadFile(string[0], &saveBuf, 1400 * 4);
	
	return 1;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   リプレイ選択画面
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int selectReplay() {
	int total, dcursor, temp;
	
	// リプレイが存在するかどうかチェック
	total = checkAllReplayExist();
	
	// 初期カーソル位置設定
	dcursor = 0;
	if(total) {
		while(!replayexist[dcursor]) {
			dcursor++;
			if(dcursor >= 40) dcursor = 0;
		}
	}
	
	// 選択画面へ
	temp = selectReplayScreen(total, dcursor);
	StopAllBGM();
	
	if(temp >= 0) {
		// 再生
		saveGeneralConfigData();
		
		playback = 1;
		replayauto = 1;
		demo = 0;
		
		gameAllInit();
		
		loadReplayData(0, temp);
		stat[0] = 3;
		setNextBlockColor(0, 1);
		
		if(maxPlay) {
			loadReplayData(1, temp);
			stat[1] = 3;
			setNextBlockColor(1, 1);
		}
		
		return 1;
	} else {
		// キャンセル
		return 0;
	}
}

// リプレイ選択画面メイン処理
int selectReplayScreen(int total, int dcursor) {
	int i, j, start, end, color, cursor, temp1, temp2;
	cursor = dcursor;
	
	// BGM再生
	if(enable_sysbgm) {
		bgmlv = 12;
		PlayBGM();
	}
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		if(!total) {
			// リプレイデータがない
			printFontGrid(13, 14, "NO REPLAY DATA", 2);
			
			if(getPushState(0, 5)) {
				return -1;
			}
			goto skip;
		}
		
		printFontGrid(9, 2, "- SELECT REPLAY DATA -", 4);
		printFontGrid(6, 3, "PRESS C BUTTON TO VIEW DETAIL", 5);
		
		// リプレイ一覧の表示
		j = 0;
		if(cursor >= 20) {
			start = 20;
			end = 40;
			printFontGrid(8, 27, "PAGE 2 (NO.21 - NO.40)", 1);
		} else {
			start = 0;
			end = 20;
			printFontGrid(8, 27, "PAGE 1 (NO.01 - NO.20)", 1);
		}
		
		for(i = start; i < end; i++) {
			// カーソル色設定
			if(replayexist[i] == 1)
				color = (i == cursor) * (count % 4 / 2) * 7;
			else
				color = (i == cursor) * 8;
			
			// ファイルナンバー
			sprintf(string[0], "%02d", i + 1);
			printFontGrid(1, 5 + j, string[0], color);
			
			if(replayexist[i]) {
				// モード名
				printFontGrid(4, 5 + j, replay_plugin_name_mode[i], color);
				// ルール名
				printFontGrid(24, 5 + j, replay_plugin_name_rule[i], color);
				// タイム
				getTime(replay_timer[i]);
				printFontGrid(31, 5 + j, string[0], color);
			}
			
			j++;
		}
		
		// カーソル移動
		padRepeat2(0);
		
		// ↑
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if(getPressState(0, 0)) {
			PlaySE(se_move);
			
			do {
				cursor--;
				if(cursor < 0) cursor = 39;
			} while(!replayexist[cursor]);
		}
		
		// ↓
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
		if(getPressState(0, 1)) {
			PlaySE(se_move);
			
			do {
				cursor++;
				if(cursor > 39) cursor = 0;
			} while(!replayexist[cursor]);
		}
		
		// キャンセル
		if(getPushState(0, 5)) {
			return -1;
		}
		
		// 詳細画面
		if(getPushState(0, 6)) {
			temp1 = findRulePlugin(replay_plugin_name_rule[cursor]);
			temp2 = findModePlugin(replay_plugin_name_mode[cursor]);
			
			if(temp1 == -1) rots[0] = -2;
			else rots[0] = temp1;
			if(temp2 == -1) gameMode[0] = -2;
			else gameMode[0] = temp2;
			
			replayDetail(cursor);
		}
		
		// 決定
		if(getPushState(0, 4)) {
			temp1 = findRulePlugin(replay_plugin_name_rule[cursor]);
			temp2 = findModePlugin(replay_plugin_name_mode[cursor]);
			
			if((temp1 != -1) && (temp2 != -1)) {
				PlayWave(se_kettei);
				rots[0] = temp1;
				gameMode[0] = temp2;
				
				if(!english) sprintf(string[0], "ルール %s モード %s でリプレイ再生開始", plugin_name_rule[rots[0]], plugin_name_mode[gameMode[0]]);
				else sprintf(string[0], "Replay start (Rule:%s Mode:%s)", plugin_name_rule[rots[0]], plugin_name_mode[gameMode[0]]);
				debugLogSystem(string[0]);
				
				return cursor;
			}
		}
		
		skip:
	}
}

// リプレイ詳細
void replayDetail(int number) {
	int page, color;
	page = 0;
	loadReplayHeader(number);
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		sprintf(string[0], "REPLAY DETAIL (PAGE %d/3)", page + 1);
		printFontGrid(1, 1, string[0], 4);
		
		printFontGrid(1, 28, "kn: PAGE CHANGE / A: PLAY / B: CANCEL", 7);
		
		if(page == 0) {
			printFontGrid(1, 3, "REPLAY NUMBER", 0);
			sprintf(string[0], "%02d", number + 1);
			printFontGrid(22, 3, string[0], 0);
			
			printFontGrid(1, 5, "HEBORIS VERSION", 0);
			sprintf(string[0], "%d", saveBuf[196]);
			printFontGrid(22, 5, string[0], 0);
			
			printFontGrid(1, 6, "ENGINE VERSION", 0);
			sprintf(string[0], "%d", saveBuf[197]);
			printFontGrid(22, 6, string[0], 0);
			
			printFontGrid(1, 8, "PLAY TIME", 0);
			getTime(saveBuf[201]);
			printFontGrid(22, 8, string[0], 0);
			
			printFontGrid(1, 10, "8WAY INPUT", 0);
			if(!saveBuf[203]) sprintf(string[0], "ON");
			else sprintf(string[0], "OFF");
			printFontGrid(22, 10, string[0], 0);
			
			printFontGrid(1, 11, "NEXT DISPLAY", 0);
			sprintf(string[0], "%d", saveBuf[204]);
			printFontGrid(22, 11, string[0], 0);
			
			printFontGrid(1, 12, "DROP LIMIT", 0);
			if(saveBuf[205] == 0) sprintf(string[0], "OFF");
			else if(saveBuf[205] == 1) sprintf(string[0], "20G ONLY");
			else sprintf(string[0], "ON");
			printFontGrid(22, 12, string[0], 0);
			
			printFontGrid(1, 13, "SPAWN Y TYPE", 0);
			if(!saveBuf[206]) sprintf(string[0], "UNDER THE FRAME");
			else sprintf(string[0], "ABOVE THE FRAME");
			printFontGrid(22, 13, string[0], 0);
			
			printFontGrid(1, 14, "E BUTTON", 0);
			if(!saveBuf[234]) sprintf(string[0], "180 ROTATE");
			else sprintf(string[0], "REVERSE ROTATE");
			printFontGrid(22, 14, string[0], 0);
			
			printFontGrid(1, 15, "HOLD", 0);
			if(!saveBuf[243]) sprintf(string[0], "ON");
			else sprintf(string[0], "OFF");
			printFontGrid(22, 15, string[0], 0);
			
			if(saveBuf[235] != 0) {
				printFontGrid(1, 17, "DATE", 0);
				sprintf(string[0], "%04d/%02d/%02d", saveBuf[235], saveBuf[236], saveBuf[237]);
				printFontGrid(22, 17, string[0], 0);
				
				printFontGrid(1, 18, "TIME", 0);
				sprintf(string[0], "%02d:%02d:%02d", saveBuf[239], saveBuf[240], saveBuf[241]);
				printFontGrid(22, 18, string[0], 0);
			}
		} else if(page == 1) {
			color = 0;
			if(rots[0] == -2) color = 8;
			printFontGrid(1, 3, "RULE", 0);
			printFontGrid(22, 3, replay_plugin_name_rule[number], color);
			executePlugin(0, 54, &number);
		} else {
			color = 0;
			if(gameMode[0] == -2) color = 8;
			printFontGrid(1, 3, "MODE", 0);
			printFontGrid(22, 3, replay_plugin_name_mode[number], color);
			executePlugin(0, 55, &number);
		}
		
		// ↑
		if(getPushState(0, 0)) {
			PlaySE(se_move);
			page--;
			if(page < 0) page = 2;
		}
		
		// ↓
		if(getPushState(0, 1)) {
			PlaySE(se_move);
			page++;
			if(page > 2) page = 0;
		}
		
		// AかBで戻る
		if(getPushState(0, 4) || getPushState(0, 5)) {
			return;
		}
	}
}
