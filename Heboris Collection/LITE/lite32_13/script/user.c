// プレイヤーデータを保存
void user_save(int player) {
	int i;
	
	if(!user_enable[player]) return;
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x4554494C;
	saveBuf[2] = 0x52455355;
	saveBuf[3] = 0x31544144;
	
	// データ類
	for(i = 0; i < 4; i++) saveBuf[4 + i] = user_line_count[player * 4 + i];
	saveBuf[8] = user_playcount[player];
	saveBuf[9] = user_beginner_tamaya[player];
	saveBuf[10] = user_beginner_novice[player];
	saveBuf[11] = user_master_normal[player];
	saveBuf[12] = user_master_hard_admit[player];
	saveBuf[13] = user_master_hard_provisional[player];
	for(i = 0; i < 5; i++) saveBuf[14 + i] = user_master_hard_grade_his[player * 5 + i];
	saveBuf[19] = user_master_hard_grade_pasttime[player];
	saveBuf[20] = user_devil_normal[player];
	saveBuf[21] = user_devil_hard[player];
	saveBuf[22] = user_devil_doom[player];
	saveBuf[23] = user_tomoyo_normal[player];
	saveBuf[24] = user_tomoyo_eheart[player];
	saveBuf[25] = user_tomoyo_target[player];
	saveBuf[26] = user_tomoyo_flash[player];
	for(i = 0; i < 5; i++) saveBuf[27 + i] = user_ace[player * 5 + i];
	
	// 保存
	sprintf(string[0], "USER_%s.SAV", user_name[player]);
	SaveFile(string[0], &saveBuf, 200 * 4);
}

// プレイヤーデータを読み込み
int user_load(int player) {
	int i;
	
	// ヘッダだけ読み込み
	FillMemory(&saveBuf, 50000 * 4, 0);
	sprintf(string[0], "USER_%s.SAV", user_name[player]);
	LoadFile(string[0], &saveBuf, 16);
	
	// バージョン違いなら失敗
	if(saveBuf[0] != 0x4F424548) return -1;
	if(saveBuf[1] != 0x4554494C) return -1;
	if(saveBuf[2] != 0x52455355) return -1;
	if(saveBuf[3] != 0x31544144) return -1;
	
	// 全部読み込み
	LoadFile(string[0], &saveBuf, 200 * 4);
	
	user_enable[player] = 1;
	
	// データ類
	for(i = 0; i < 4; i++) user_line_count[player * 4 + i] = saveBuf[4 + i];
	user_playcount[player] = saveBuf[8];
	user_beginner_tamaya[player] = saveBuf[9];
	user_beginner_novice[player] = saveBuf[10];
	user_master_normal[player] = saveBuf[11];
	user_master_hard_admit[player] = saveBuf[12];
	user_master_hard_provisional[player] = saveBuf[13];
	for(i = 0; i < 5; i++) user_master_hard_grade_his[player * 5 + i] = saveBuf[14 + i];
	user_master_hard_grade_pasttime[player] = saveBuf[19];
	user_devil_normal[player] = saveBuf[20];
	user_devil_hard[player] = saveBuf[21];
	user_devil_doom[player] = saveBuf[22];
	user_tomoyo_normal[player] = saveBuf[23];
	user_tomoyo_eheart[player] = saveBuf[24];
	user_tomoyo_target[player] = saveBuf[25];
	user_tomoyo_flash[player] = saveBuf[26];
	for(i = 0; i < 5; i++) user_ace[player * 5 + i] = saveBuf[27 + i];
	
	return 0;
}

// 初期化処理
void user_init(int player) {
	int i;
	
	for(i = 0; i < 4; i++) user_line_count[player * 4 + i] = 0;
	user_playcount[player] = 0;
	user_beginner_tamaya[player] = 0;
	user_beginner_novice[player] = 0;
	user_master_normal[player] = 0;
	user_master_hard_admit[player] = 0;
	user_master_hard_provisional[player] = 0;
	for(i = 0; i < 5; i++) user_master_hard_grade_his[player * 5 + i] = 0;
	user_master_hard_grade_pasttime[player] = 0;
	user_devil_normal[player] = 0;
	user_devil_hard[player] = 0;
	user_devil_doom[player] = 0;
	user_tomoyo_normal[player] = 0;
	user_tomoyo_eheart[player] = 0;
	user_tomoyo_target[player] = 0;
	user_tomoyo_flash[player] = 0;
	for(i = 0; i < 5; i++) user_ace[player * 5 + i] = 0;
}

// 記録を表示
void user_view(int player) {
	int i, page;
	page = 0;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		viewDarkTitle();
		
		if(page == 0) {
			printFont(28, 1, "PAGE 1/2 kn", digitc[rots[player]]);
			
			sprintf(string[0], "PLAYER %s RECORDS", user_name[player]);
			printFont(1, 1, string[0], fontc[rots[player]]);
			
			printFont(1, 2, "PLAY COUNT      :", 0);
			sprintf(string[0], "%d", user_playcount[player]);
			printFont(20, 2, string[0], 0);
			
			printFont(1, 3, "SINGLE          :", 0);
			sprintf(string[0], "%d", user_line_count[player * 4 + 0]);
			printFont(20, 3, string[0], 0);
			
			printFont(1, 4, "DOUBLE          :", 0);
			sprintf(string[0], "%d", user_line_count[player * 4 + 1]);
			printFont(20, 4, string[0], 0);
			
			printFont(1, 5, "TRIPLE          :", 0);
			sprintf(string[0], "%d", user_line_count[player * 4 + 2]);
			printFont(20, 5, string[0], 0);
			
			printFont(1, 6, "HEBORIS         :", 0);
			sprintf(string[0], "%d", user_line_count[player * 4 + 3]);
			printFont(20, 6, string[0], 0);
			
			printFont(1, 8, "BEGINNER MODE RECORDS", fontc[rots[player]]);
			
			printFont(1, 9, "TAMAYA TOTAL    :", 0);
			sprintf(string[0], "%d", user_beginner_tamaya[player]);
			printFont(20, 9, string[0], 0);
			
			printFont(1, 10, "NOVICE TOTAL    :", 0);
			sprintf(string[0], "%d", user_beginner_novice[player]);
			printFont(20, 10, string[0], 0);
			
			printFont(1, 12, "MASTER MODE RECORDS", fontc[rots[player]]);
			
			printFont(1, 13, "NORMAL          :", 0);
			getGradeString(user_master_normal[player], 0, 0);
			printFont(20, 13, string[0], 0);
			
			printFont(1, 14, "HARD NON-ADMIT  :", 0);
			getGradeString(user_master_hard_provisional[player], 0, 0);
			printFont(20, 14, string[0], 0);
			
			printFont(1, 15, "HARD ADMIT      :", 0);
			getGradeString(user_master_hard_admit[player], 0, 0);
			printFont(20, 15, string[0], 0);
			
			printFont(1, 16, "LAST EXAM       :", 0);
			sprintf(string[0], "%d GAME(S) AGO", user_master_hard_grade_pasttime[player]);
			printFont(20, 16, string[0], 0);
			
			printFont(1, 18, "MASTER-HARD RECENT GRADES", fontc[rots[player]]);
			
			for(i = 0; i < 5; i++) {
				sprintf(string[0], "%d GAME(S) AGO   :", i + 1);
				printFont(1, 19 + i, string[0], 0);
				
				if((user_master_hard_grade_his[player * 5 + i] >= 0) && (user_master_hard_grade_his[player * 5 + i] <= 32)) {
					getGradeString(user_master_hard_grade_his[player * 5 + i], 0, 0);
					printFont(20, 19 + i, string[0], 0);
				} else {
					printFont(20, 19 + i, "N/A", 0);
				}
			}
			
			printFont(1, 25, "DEVIL MODE RECORDS", fontc[rots[player]]);
			
			printFont(1, 26, "NORMAL          :", 0);
			sprintf(string[0], "LV%d", user_devil_normal[player]);
			printFont(20, 26, string[0], 0);
			
			printFont(1, 27, "HARD            :", 0);
			getGradeString(user_devil_hard[player], 1, 0);
			printFont(20, 27, string[0], 0);
			
			printFont(1, 28, "DOOM            :", 0);
			getGradeString(user_devil_doom[player], 2, 0);
			printFont(20, 28, string[0], 0);
		} else {
			printFont(28, 1, "PAGE 2/2 kn", digitc[rots[player]]);
			
			printFont(1, 1, "TOMOYO MODE RECORDS", fontc[rots[player]]);
			
			printFont(1, 2, "NORMAL COURSE   :", 0);
			getTomoyoStageNo(user_tomoyo_normal[player], 0, 0);
			printFont(20, 2, string[0], 0);
			
			printFont(1, 3, "EHEART COURSE   :", 0);
			getTomoyoStageNo(user_tomoyo_eheart[player], 0, 0);
			printFont(20, 3, string[0], 0);
			
			printFont(1, 4, "TARGET COURSE   :", 0);
			getTomoyoStageNo(user_tomoyo_target[player], 0, 0);
			printFont(20, 4, string[0], 0);
			
			printFont(1, 5, "FLASH COURSE    :", 0);
			sprintf(string[0], "%d", user_tomoyo_flash[player] + 1);
			printFont(20, 5, string[0], 0);
			
			printFont(1, 7, "ACE MODE RECORDS", fontc[rots[player]]);
			printFont(1, 8, "NORMAL          :", 0);
			getTime(user_ace[player * 5 + 0]);
			printFont(20, 8, string[0], 0);
			
			printFont(1, 9, "HI-SPEED 1      :", 0);
			getTime(user_ace[player * 5 + 1]);
			printFont(20, 9, string[0], 0);
			
			printFont(1, 10, "HI-SPEED 2      :", 0);
			getTime(user_ace[player * 5 + 2]);
			printFont(20, 10, string[0], 0);
			
			printFont(1, 11, "ANOTHER         :", 0);
			getTime(user_ace[player * 5 + 3]);
			printFont(20, 11, string[0], 0);
			
			printFont(1, 12, "ANOTHER2        :", 0);
			getTime(user_ace[player * 5 + 4]);
			printFont(20, 12, string[0], 0);
		}
		
		// ページ切り替え
		if(getPushState(player, 0) || getPushState(player, 1)) {
			PlaySE(5);
			page = !page;
		}
		
		// 戻る
		if(getPushState(player, 4) || getPushState(player, 5)) {
			return;
		}
		
		if(!refresh_timing) spriteTime();
	}
}
