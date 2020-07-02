//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ステータスNo.22 - ミッションモードセレクト画面
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// statc[player * 10]    ：カウンタ
void statMissionSelect(int player) {
	int i, color;
	
	statc[player * 10]++;
	
	color = (count % 4 / 2) * digitc[rots[player]];
	
	if(statc[player * 10] == 1) {
		loadMissionData(mission_file);
		viewMissionText();
	}
	
	printFont(boffset[0], 6, "SELECT", fontc[rots[player]]);
	printFont(boffset[0] + 4, 7, "COURSE", fontc[rots[player]]);
	
	printFont(boffset[0] + 4, 12, "k", color);
	printFont(boffset[0] + 4, 16, "n", color);
	
	if(StrLen(mission_course_name) > 0) {
		printFont(boffset[0], 14, mission_course_name, color);
	} else {
		sprintf(string[0], "EDIT %d", mission_file + 1);
		printFont(boffset[0], 14, string[0], color);
	}
	
	printFont(boffset[0], 19, "PRESS A TO", 0);
	printFont(boffset[0], 20, "START GAME", 0);
	printFont(boffset[0], 22, "PRESS D TO", 0);
	printFont(boffset[0], 23, " EDIT MODE", 0);
	
	padRepeat(player);
	padRepeat2(player);
	
	// ↑
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 0) ) {
		PlaySE(5);
		
		mission_file--;
		if(mission_file < 0) mission_file = 98;
		loadMissionData(mission_file);
		viewMissionText();
	}
	
	// ↓
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 1) ) {
		PlaySE(5);
		
		mission_file++;
		if(mission_file > 98) mission_file = 0;
		loadMissionData(mission_file);
		viewMissionText();
	}
	
	// ←
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 2) ) {
		PlaySE(5);
		c_mission--;
		if(c_mission < 0) c_mission = 29;
		viewMissionText();
	}
	
	// →
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 3) ) {
		PlaySE(5);
		c_mission++;
		if(c_mission > 29) c_mission = 0;
		viewMissionText();
	}
	
	// Aボタン
	if( getPushState(player, 4) ) {
		PlaySE(10);
		
		// BGM停止
		StopAllBGM();
		
		// ゲーム開始
		start_mission = c_mission;
		
		// 操作状況表示位置変更
		if(!mission_hide_info) {
			if(!maxPlay) coffset = s_m_coffset;
			else coffset = d_m_coffset;
		} else {
			setFieldPosition(maxPlay);
		}
		
		stat[player] = 1;				// ブロックシャッター実行
		statc[player * 10] = 0;			// ステータスカウンタを0に
		statc[player * 10 + 1] = 3;		// シャッター後はステータスNo.3
		return;
	}
	
	// Bボタンで戻る
	if( getPushState(player, 5) ) {
		PlaySE(5);
		gameMode[player] = 0;
		stat[0] = 2;
		statc[0 * 10] = 0;
		stat[1] = 0;
		statc[1 * 10] = 0;
		
		for(i = 0; i < 10; i++) TextLayerOff(i);
		return;
	}
	
	// HOLDボタンでエディット画面
	if( getPushState(player, 7) ) {
		stat[player] = 23;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		return;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ステータスNo.23 - ミッションモードエディット画面
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// statc[player * 10]    ：カーソル位置
// statc[player * 10 + 1]：ステージコピーのステージ番号
void statMissionEditor(int player) {
	int i, color;
	
	color = (count % 4 / 2) * digitc[rots[player]];
	
	printFont(toffset[0], 26, "D: EDIT NAME", 0);
	
	if(statc[player * 10] < 14) {
		printFont(boffset[0] - 1, 25, "kn  PAGE 1/2", 0);
		
		printFont(boffset[0], 5, "STAGE", fontc[rots[player]]);
		sprintf(string[0], "NO.%d", c_mission + 1);
		printFont(boffset[0], 6, string[0], (statc[player * 10] == 0) * color);
		
		printFont(boffset[0], 7, "TYPE", fontc[rots[player]]);
		if(mission_type[c_mission] < 0) {
			i = (mission_type[c_mission] + 1) * -1;
			printFont(boffset[0], 8, mission_ext_name_editor[i], (statc[player * 10] == 1) * color);
		} else {
			printFont(boffset[0], 8, mission_name_editor[mission_type[c_mission]], (statc[player * 10] == 1) * color);
		}
		
		printFont(boffset[0], 9, "NORM", fontc[rots[player]]);
		sprintf(string[0], "%2d", mission_norm[c_mission]);
		printFont(boffset[0] + 8, 9, string[0], (statc[player * 10] == 2) * color);
		
		printFont(boffset[0], 10, "TIME", fontc[rots[player]]);
		getTime(mission_time[c_mission]);
		printFont(boffset[0], 11, string[0], (statc[player * 10] == 3) * color);
		
		printFont(boffset[0], 12, "LEVEL", fontc[rots[player]]);
		if(mission_lv[c_mission] >= 15) {
			sprintf(string[0], "%2d+", mission_lv[c_mission] - 14);
			printFont(boffset[0] + 7, 12, string[0], (statc[player * 10] == 4) * color);
		} else {
			sprintf(string[0], "%2d", mission_lv[c_mission] + 1);
			printFont(boffset[0] + 8, 12, string[0], (statc[player * 10] == 4) * color);
		}
		
		if(mission_erase[c_mission] >= 0) {
			printFont(boffset[0], 13, "ERASE", fontc[rots[player]]);
			sprintf(string[0], "%3d", mission_erase[c_mission]);
		} else if(mission_erase[c_mission] < -20) {
			printFont(boffset[0], 13, "RISE-E", fontc[rots[player]]);
			sprintf(string[0], "%3d", abs(mission_erase[c_mission] + 20));
		} else {
			printFont(boffset[0], 13, "RISE-H", fontc[rots[player]]);
			sprintf(string[0], "%3d", abs(mission_erase[c_mission]));
		}
		printFont(boffset[0] + 7, 13, string[0], (statc[player * 10] == 5) * color);
		
		printFont(boffset[0], 14, "BGM", fontc[rots[player]]);
		if(mission_bgm[c_mission] == -1) {
			printFont(boffset[0] + 6, 14, "FADE", (statc[player * 10] == 6) * color);
		} else {
			sprintf(string[0], "%2d", mission_bgm[c_mission] + 1);
			printFont(boffset[0] + 8, 14, string[0], (statc[player * 10] == 6) * color);
		}
		
		printFont(boffset[0], 15, "ENDING", fontc[rots[player]]);
		if(mission_end[c_mission] ==  0) sprintf(string[0], "OFF");				// 次の面へ
		if(mission_end[c_mission] ==  1) sprintf(string[0], "END");				// エンディング
		if(mission_end[c_mission] ==  2) sprintf(string[0], "EXTRA");			// 最後をダブルで次へ
		if(mission_end[c_mission] ==  3) sprintf(string[0], "EXTRA+");			// 最後をダブルで次へ（消去演出が違う）
		if(mission_end[c_mission] ==  4) sprintf(string[0], "STAFF ROLL");		// ノーマルロール
		if(mission_end[c_mission] ==  5) sprintf(string[0], "M ROLL");			// 消えロール
		if(mission_end[c_mission] ==  6) sprintf(string[0], "M BIG ROLL");		// 消えビッグロール
		if(mission_end[c_mission] ==  7) sprintf(string[0], "BIG ROLL");		// ビッグロール
		if(mission_end[c_mission] ==  8) sprintf(string[0], "N ROLL");			// 見えロール
		if(mission_end[c_mission] ==  9) sprintf(string[0], "N BIG ROLL");		// 見えビッグロール
		if(mission_end[c_mission] == 10) sprintf(string[0], "BONUS");			// 最後をダブルで足切り無効権獲得
		
		printFont(boffset[0], 16, string[0], (statc[player * 10] == 7) * color);
		
		printFont(boffset[0], 18, "OPTIONS", fontc[rots[player]]);
		
		if((mission_type[c_mission] ==  2) || (mission_type[c_mission] ==  3) || 
		   (mission_type[c_mission] == 11) || (mission_type[c_mission] == 37)) {
			// ダブル＆トリプル＆シングル＆T-スピンダブル
			sprintf(string[0], "TYPE  %4d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "N/A    %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 6) {
			// ターゲット
			sprintf(string[0], "MIN   %4d", mission_opt_1[c_mission] + 1);
			sprintf(string[1], "MAX   %4d", mission_opt_2[c_mission] + 1);
			sprintf(string[2], "FLASH  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "STGRAND%3d", mission_opt_4[c_mission]);
			sprintf(string[4], "RANDOPT%3d", mission_opt_5[c_mission]);
			sprintf(string[5], "ALL    %3d", mission_opt_6[c_mission]);
		} else if((mission_type[c_mission] == 7) || (mission_type[c_mission] == 40)) {
			// イレイサー
			sprintf(string[0], "MIN    %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "MAX    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "LINES %4d", mission_opt_3[c_mission] + 1);
			sprintf(string[3], "LINES2%4d", mission_opt_4[c_mission] + 1);
			sprintf(string[4], "LINES3%4d", mission_opt_5[c_mission] + 1);
			sprintf(string[5], "LINES4%4d", mission_opt_6[c_mission] + 1);
		} else if(mission_type[c_mission] == 10) {
			// アナザー
			sprintf(string[0], "N/A    %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "BLIND  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 19) {
			// DEVIL 800
			sprintf(string[0], "NORISE %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "RANDOM %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "INTER  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 20) {
			// DEVIL 1200
			sprintf(string[0], "N/A    %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "FAST   %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 21) {
			// GARBAGE
			sprintf(string[0], "N/A    %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "LINES  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 22) {
			// オールドスタイル
			sprintf(string[0], "ARCADE %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "N/A    %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 23) {
			// 耐久
			sprintf(string[0], "N/A    %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "LIMIT  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 26) {
			// 全消し
			sprintf(string[0], "N/A    %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "NOBIG  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 27) {
			// コンボ
			sprintf(string[0], "N/A    %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "2LINE  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 30) {
			// ブロックオーダー系
			sprintf(string[0], "HOLD   %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "BLOCK  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if( ((mission_type[c_mission] >= 31) && (mission_type[c_mission] <= 33)) || (mission_type[c_mission] == 38) ) {
			// シングルオーダー、ダブルオーダー、逆トリプルオーダー、トリプルオーダー
			sprintf(string[0], "HOLD   %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "TYPE   %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "BLOCK  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == 39) {
			// イレイサー２
			sprintf(string[0], "LINE1  %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "LINE2  %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "N/A    %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else if(mission_type[c_mission] == -7) {
			// 速度固定
			sprintf(string[0], "WAIT1  %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "WAIT2  %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "WAIT3  %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "WAITT  %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "SPEED  %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		} else {
			// その他
			sprintf(string[0], "N/A    %3d", mission_opt_1[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_2[c_mission]);
			sprintf(string[2], "N/A    %3d", mission_opt_3[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_4[c_mission]);
			sprintf(string[4], "N/A    %3d", mission_opt_5[c_mission]);
			sprintf(string[5], "N/A    %3d", mission_opt_6[c_mission]);
		}
		printFont(boffset[0], 19, string[0], (statc[player * 10] == 8) * color);
		printFont(boffset[0], 20, string[1], (statc[player * 10] == 9) * color);
		printFont(boffset[0], 21, string[2], (statc[player * 10] == 10) * color);
		printFont(boffset[0], 22, string[3], (statc[player * 10] == 11) * color);
		printFont(boffset[0], 23, string[4], (statc[player * 10] == 12) * color);
		printFont(boffset[0], 24, string[5], (statc[player * 10] == 13) * color);
	} else {
		printFont(boffset[0] - 1, 25, "kn  PAGE 2/2", 0);
		
		printFont(boffset[0], 5, "OPTIONS-2", fontc[rots[player]]);
		
		if(mission_type[c_mission] == 6) {
			// ターゲット
			sprintf(string[0], "USEn   %3d", mission_opt_7[c_mission]);
			sprintf(string[1], "MIN2  %4d", mission_opt_8[c_mission] + 1);
			sprintf(string[2], "MAX2  %4d", mission_opt_9[c_mission] + 1);
			sprintf(string[3], "FLASH2 %3d", mission_opt_10[c_mission]);
		} else {
			// その他
			sprintf(string[0], "N/A    %3d", mission_opt_7[c_mission]);
			sprintf(string[1], "N/A    %3d", mission_opt_8[c_mission]);
			sprintf(string[2], "N/A    %3d", mission_opt_9[c_mission]);
			sprintf(string[3], "N/A    %3d", mission_opt_10[c_mission]);
		}
		printFont(boffset[0], 6, string[0], (statc[player * 10] == 14) * color);
		printFont(boffset[0], 7, string[1], (statc[player * 10] == 15) * color);
		printFont(boffset[0], 8, string[2], (statc[player * 10] == 16) * color);
		printFont(boffset[0], 9, string[3], (statc[player * 10] == 17) * color);
		
		// 背景
		printFont(boffset[0], 11, "BACKGROUND", fontc[rots[player]]);
		if(!mission_bg[c_mission]) sprintf(string[0], "AUTO");
		else sprintf(string[0], "NO.%d", mission_bg[c_mission] - 1);
		printFont(boffset[0], 12, string[0], (statc[player * 10] == 18) * color);
		
		// コピー
		printFont(boffset[0], 14, "COPY STAGE", fontc[rots[player]]);
		sprintf(string[0], "NO.%d", statc[player * 10 + 1] + 1);
		printFont(boffset[0], 15, string[0], (statc[player * 10] == 19) * color);
		
		// 指令隠し
		printFont(boffset[0], 17, "HIDE INFO", digitc[rots[player]]);
		if(!mission_hide_info) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFont(boffset[0], 18, string[0], (statc[player * 10] == 20) * color);
		
		// オールクリア時の演出
		printFont(boffset[0], 20, "ALL CLEAR", digitc[rots[player]]);
		if(mission_clear_anim == 0) sprintf(string[0], "NORMAL");
		else if(mission_clear_anim == 1) sprintf(string[0], "GM");
		else if(mission_clear_anim == 2) sprintf(string[0], "GOD");
		else sprintf(string[0], "EXCELLENT");
		printFont(boffset[0], 21, string[0], (statc[player * 10] == 21) * color);
	}
	
	// キー操作
	padRepeat(player);
	padRepeat2(player);
	
	// ↑
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 0) ) {
		PlaySE(5);
		statc[player * 10]--;
		if(statc[player * 10] < 0) statc[player * 10] = 21;
	}
	
	// ↓
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 1) ) {
		PlaySE(5);
		statc[player * 10]++;
		if(statc[player * 10] > 21) statc[player * 10] = 0;
	}
	
	// ←
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 2) ) {
		PlaySE(3);
		
		// STAGE
		if(statc[player * 10] == 0) {
			c_mission--;
			if(c_mission < 0) c_mission = 29;
		}
		// TYPE
		if(statc[player * 10] == 1) {
			mission_type[c_mission]--;
			if(mission_type[c_mission] < -7) mission_type[c_mission] = 42;
		}
		// NORM
		if(statc[player * 10] == 2) {
			mission_norm[c_mission]--;
			if(mission_norm[c_mission] < 0) mission_norm[c_mission] = 99;
		}
		// TIME
		if(statc[player * 10] == 3) {
			mission_time[c_mission] = mission_time[c_mission] - 60;
			if(mission_time[c_mission] < 0) mission_time[c_mission] = 72000;
		}
		// LEVEL
		if(statc[player * 10] == 4) {
			mission_lv[c_mission]--;
			if(mission_lv[c_mission] < 0) mission_lv[c_mission] = 29;
		}
		// ERASE
		if(statc[player * 10] == 5) {
			mission_erase[c_mission]--;
			if(mission_erase[c_mission] < -40) mission_erase[c_mission] = 22;
		}
		// BGM
		if(statc[player * 10] == 6) {
			mission_bgm[c_mission]--;
			if(mission_bgm[c_mission] < -1) mission_bgm[c_mission] = 20;
		}
		// ENDING
		if(statc[player * 10] == 7) {
			mission_end[c_mission]--;
			if(mission_end[c_mission] < 0) mission_end[c_mission] = 10;
		}
		// MIN
		if(statc[player * 10] == 8) {
			mission_opt_1[c_mission]--;
			if(mission_opt_1[c_mission] < 0) mission_opt_1[c_mission] = 999;
		}
		// MAX
		if(statc[player * 10] == 9) {
			mission_opt_2[c_mission]--;
			if(mission_opt_2[c_mission] < 0) mission_opt_2[c_mission] = 999;
		}
		// OPT
		if(statc[player * 10] == 10) {
			mission_opt_3[c_mission]--;
			if(mission_opt_3[c_mission] < 0) mission_opt_3[c_mission] = 999;
		}
		if(statc[player * 10] == 11) {
			mission_opt_4[c_mission]--;
			if(mission_opt_4[c_mission] < 0) mission_opt_4[c_mission] = 999;
		}
		if(statc[player * 10] == 12) {
			mission_opt_5[c_mission]--;
			if(mission_opt_5[c_mission] < 0) mission_opt_5[c_mission] = 999;
		}
		if(statc[player * 10] == 13) {
			mission_opt_6[c_mission]--;
			if(mission_opt_6[c_mission] < 0) mission_opt_6[c_mission] = 999;
		}
		if(statc[player * 10] == 14) {
			mission_opt_7[c_mission]--;
			if(mission_opt_7[c_mission] < 0) mission_opt_7[c_mission] = 999;
		}
		if(statc[player * 10] == 15) {
			mission_opt_8[c_mission]--;
			if(mission_opt_8[c_mission] < 0) mission_opt_8[c_mission] = 999;
		}
		if(statc[player * 10] == 16) {
			mission_opt_9[c_mission]--;
			if(mission_opt_9[c_mission] < 0) mission_opt_9[c_mission] = 999;
		}
		if(statc[player * 10] == 17) {
			mission_opt_10[c_mission]--;
			if(mission_opt_10[c_mission] < 0) mission_opt_10[c_mission] = 999;
		}
		// BACKGROUND
		if(statc[player * 10] == 18) {
			mission_bg[c_mission]--;
			if(mission_bg[c_mission] < 0) mission_bg[c_mission] = 15;
		}
		// COPY STAGE
		if(statc[player * 10] == 19) {
			statc[player * 10 + 1]--;
			if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = 29;
		}
		// HIDE INFO
		if(statc[player * 10] == 20) {
			mission_hide_info = !mission_hide_info;
		}
		// ALL CLEAR
		if(statc[player * 10] == 21) {
			mission_clear_anim--;
			if(mission_clear_anim < 0) mission_clear_anim = 3;
		}
		
		viewMissionText();
	}
	
	// →
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 3) ) {
		PlaySE(3);
		
		// STAGE
		if(statc[player * 10] == 0) {
			c_mission++;
			if(c_mission > 29) c_mission = 0;
		}
		// TYPE
		if(statc[player * 10] == 1) {
			mission_type[c_mission]++;
			if(mission_type[c_mission] > 42) mission_type[c_mission] = -7;
		}
		// NORM
		if(statc[player * 10] == 2) {
			mission_norm[c_mission]++;
			if(mission_norm[c_mission] > 99) mission_norm[c_mission] = 0;
		}
		// TIME
		if(statc[player * 10] == 3) {
			mission_time[c_mission] = mission_time[c_mission] + 60;
			if(mission_time[c_mission] > 72000) mission_time[c_mission] = 0;
		}
		// LEVEL
		if(statc[player * 10] == 4) {
			mission_lv[c_mission]++;
			if(mission_lv[c_mission] > 29) mission_lv[c_mission] = 0;
		}
		// ERASE
		if(statc[player * 10] == 5) {
			mission_erase[c_mission]++;
			if(mission_erase[c_mission] > 22) mission_erase[c_mission] = -40;
		}
		// BGM
		if(statc[player * 10] == 6) {
			mission_bgm[c_mission]++;
			if(mission_bgm[c_mission] > 20) mission_bgm[c_mission] = -1;
		}
		// ENDING
		if(statc[player * 10] == 7) {
			mission_end[c_mission]++;
			if(mission_end[c_mission] > 10) mission_end[c_mission] = 0;
		}
		// OPT
		if(statc[player * 10] == 8) {
			mission_opt_1[c_mission]++;
			if(mission_opt_1[c_mission] > 999) mission_opt_1[c_mission] = 0;
		}
		if(statc[player * 10] == 9) {
			mission_opt_2[c_mission]++;
			if(mission_opt_2[c_mission] > 999) mission_opt_2[c_mission] = 0;
		}
		if(statc[player * 10] == 10) {
			mission_opt_3[c_mission]++;
			if(mission_opt_3[c_mission] > 999) mission_opt_3[c_mission] = 0;
		}
		if(statc[player * 10] == 11) {
			mission_opt_4[c_mission]++;
			if(mission_opt_4[c_mission] > 999) mission_opt_4[c_mission] = 0;
		}
		if(statc[player * 10] == 12) {
			mission_opt_5[c_mission]++;
			if(mission_opt_5[c_mission] > 999) mission_opt_5[c_mission] = 0;
		}
		if(statc[player * 10] == 13) {
			mission_opt_6[c_mission]++;
			if(mission_opt_6[c_mission] > 999) mission_opt_6[c_mission] = 0;
		}
		if(statc[player * 10] == 14) {
			mission_opt_7[c_mission]++;
			if(mission_opt_7[c_mission] > 999) mission_opt_7[c_mission] = 0;
		}
		if(statc[player * 10] == 15) {
			mission_opt_8[c_mission]++;
			if(mission_opt_8[c_mission] > 999) mission_opt_8[c_mission] = 0;
		}
		if(statc[player * 10] == 16) {
			mission_opt_9[c_mission]++;
			if(mission_opt_9[c_mission] > 999) mission_opt_9[c_mission] = 0;
		}
		if(statc[player * 10] == 17) {
			mission_opt_10[c_mission]++;
			if(mission_opt_10[c_mission] > 999) mission_opt_10[c_mission] = 0;
		}
		// BACKGROUND
		if(statc[player * 10] == 18) {
			mission_bg[c_mission]++;
			if(mission_bg[c_mission] > 15) mission_bg[c_mission] = 0;
		}
		// COPY STAGE
		if(statc[player * 10] == 19) {
			statc[player * 10 + 1]++;
			if(statc[player * 10 + 1] > 29) statc[player * 10 + 1] = 0;
		}
		// HIDE INFO
		if(statc[player * 10] == 20) {
			mission_hide_info = !mission_hide_info;
		}
		// ALL CLEAR
		if(statc[player * 10] == 21) {
			mission_clear_anim++;
			if(mission_clear_anim > 3) mission_clear_anim = 0;
		}
		
		viewMissionText();
	}
	
	// Aボタン
	if( getPushState(player, 4) ) {
		// コピー
		if(statc[player * 10] == 19) {
			PlaySE(3);
			mission_type[c_mission]   = mission_type[statc[player * 10 + 1]];
			mission_norm[c_mission]   = mission_norm[statc[player * 10 + 1]];
			mission_time[c_mission]   = mission_time[statc[player * 10 + 1]];
			mission_end[c_mission]    = mission_end[statc[player * 10 + 1]];
			mission_lv[c_mission]     = mission_lv[statc[player * 10 + 1]];
			mission_erase[c_mission]  = mission_erase[statc[player * 10 + 1]];
			mission_opt_1[c_mission]  = mission_opt_1[statc[player * 10 + 1]];
			mission_opt_2[c_mission]  = mission_opt_2[statc[player * 10 + 1]];
			mission_opt_3[c_mission]  = mission_opt_3[statc[player * 10 + 1]];
			mission_bgm[c_mission]    = mission_bgm[statc[player * 10 + 1]];
			mission_opt_4[c_mission]  = mission_opt_4[statc[player * 10 + 1]];
			mission_opt_5[c_mission]  = mission_opt_5[statc[player * 10 + 1]];
			mission_opt_6[c_mission]  = mission_opt_6[statc[player * 10 + 1]];
			mission_bg[c_mission]     = mission_bg[statc[player * 10 + 1]];
			mission_opt_7[c_mission]  = mission_opt_7[statc[player * 10 + 1]];
			mission_opt_8[c_mission]  = mission_opt_8[statc[player * 10 + 1]];
			mission_opt_9[c_mission]  = mission_opt_9[statc[player * 10 + 1]];
			mission_opt_10[c_mission] = mission_opt_10[statc[player * 10 + 1]];
			
			viewMissionText();
		}
		// セーブ
		else {
			PlaySE(10);
			saveMissionData(mission_file);
			stat[player] = 22;
			statc[player * 10] = 0;
			statc[player * 10 + 1] = 0;
			return;
		}
	}
	
	// Bボタンで戻る
	if( getPushState(player, 5) ) {
		PlaySE(5);
		loadMissionData(mission_file);
		stat[player] = 22;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		return;
	}
	
	// Dボタンでコース名入力
	if( getPushState(player, 7) ) {
		PlaySE(0);
		stat[player] = 39;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		return;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ステータスNo.39 - ミッションモードコース名入力画面
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// statc[player * 10]　　：初期化済みフラグ
// statc[player * 10 + 1]：終了フラグ
// statc[player * 10 + 2]：現在選択している文字
void statMissionCourseName(int player) {
	int		move, len;
	
	// 初期化
	if(!statc[player * 10]) {
		StrCpy(string[player + 2], mission_course_name);
		statc[player * 10] = 1;
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = 54;
	}
	
	padRepeat(player);
	
	printFont(boffset[player], 12, "ENTER NAME", 4);
	printFont(boffset[player], 16, "PRESS D", 1);
	printFont(boffset[player] + 1, 17, "TO CANCEL", 1);
	
	len = StrLen(string[player + 2]);	// 入力済み文字数
	
	// 横移動
	move = getPressState(player, 3) - getPressState(player, 2);
	if(move)
		if((mpc[player] == 1) || (mpc[player] >= 15) || getPressState(player, 6)) {
			if(mpc[player] >= 15) mpc[player] = 12;
			statc[player * 10 + 2] = statc[player * 10 + 2] + move;
			PlaySE(5);
		}
	
	// 文字のループ
	if(statc[player * 10 + 2] > 54)
		statc[player * 10 + 2] = (len == 15) * 53;
	if(statc[player * 10 + 2] < (len == 15) * 53)
		statc[player * 10 + 2] = 54;
	
	// 選択している文字と入力済み文字を表示
	MidStr(RankString, statc[player * 10 + 2] + 1, 1, string[4]);
	printFont(boffset[player] + len, 14, string[4], 2 * (count % 20 > 10));
	printFont(boffset[player], 14, string[player + 2], 0);
	
	// Dでキャンセル
	if(getPushState(player, 7)) {
		stat[player] = 23;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = 0;
		return;
	}
	
	// Bボタンで1文字削除
	if(getPushState(player, 5)) {
		if(len) {
			PlaySE(5);
			MidStr(string[player + 2], 1, len - 1, string[player + 2]);
		}
	}
	
	// Aボタンで入力
	if(getPushState(player, 4)) {
		PlaySE(10);
		
		if(statc[player * 10 + 2] == 53) {
			// RB
			if(len) {
				MidStr(string[player + 2], 1, len - 1, string[player + 2]);
			}
		} else if(statc[player * 10 + 2] == 54) {
			// ED
			statc[player * 10 + 1] = 1;
		} else {
			// 文字入力
			StrCat(string[player + 2], string[4]);
		}
	}
	
	// ネームエントリー終了
	if(statc[player * 10 + 1]) {
		PlaySE(18);
		
		// 名前の後ろにスペースを挿入（余った個所をスペースにする）
		sprintf(string[player + 2], "%s                ", string[player + 2]);
		
		// 左から16文字目以降を削除
		LeftStr(string[player + 2], 15, string[player + 2]);
		
		// 保存
		StrCpy(mission_course_name, string[player + 2]);
		saveMissionData(mission_file);
		
		// 終わり
		stat[player] = 23;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = 0;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  問題の表示
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲

// 枠
void viewMissionFrame() {
	int i, j, tmp, tmp2;
	
	if(mission_hide_info) return;
	
	// 枠
	ExBltFastRect(4, moffset, 112, 0, 64, 112, 112);
	
	// ブロックオーダー
	if( ((mission_type[c_mission] >= 30) && (mission_type[c_mission] <= 33)) || (mission_type[c_mission] == 38) ) {
		if(mission_opt_3[c_mission] <= 6) {
			// 通常
			if(!rule_color[rots[0]]) {
				tmp = ccol[mission_opt_3[c_mission]];
			} else {
				tmp = wcol[mission_opt_3[c_mission]];
			}
			j = ( ((mission_opt_3[c_mission] != 0) || (isDRule(0))) && (!isWRule(0)) );
			
			if((mission_type[c_mission] == 33) && (english)) {
				// 逆トリプルオーダー＠英語モード
				drawBlockFast(moffset + 1, 23 - j, mission_opt_3[c_mission], 0, tmp, 0, 0, 0, 0);
			} else {
				// その他
				if(english)
					drawBlockFast(moffset + 1, 22 - j, mission_opt_3[c_mission], 0, tmp, 0, 0, 0, 0);
				else
					drawBlockFast(moffset + 1, 19 - j, mission_opt_3[c_mission], 0, tmp, 0, 0, 0, 0);
			}
		} else if(mission_opt_3[c_mission] == 7) {
			// LJ
			if(!rule_color[rots[0]]) {
				tmp = ccol[1];
				tmp2 = ccol[5];
			} else {
				tmp = wcol[1];
				tmp2 = wcol[5];
			}
			j = (!isWRule(0));
			
			if((mission_type[c_mission] == 33) && (english)) {
				// 逆トリプルオーダー＠英語モード
				drawBlockFast(moffset + 1, 23 - j, 1, 0, tmp, 0, 0, 0, 0);
				drawBlockFast(moffset + 5, 23 - j, 5, 0, tmp2, 0, 0, 0, 0);
			} else {
				// その他
				if(english) {
					drawBlockFast(moffset + 1, 22 - j, 1, 0, tmp, 0, 0, 0, 0);
					drawBlockFast(moffset + 5, 22 - j, 5, 0, tmp2, 0, 0, 0, 0);
				} else {
					drawBlockFast(moffset + 1, 19 - j, 1, 0, tmp, 0, 0, 0, 0);
					drawBlockFast(moffset + 5, 19 - j, 5, 0, tmp2, 0, 0, 0, 0);
				}
			}
		} else if(mission_opt_3[c_mission] == 8) {
			// SZ
			if(!rule_color[rots[0]]) {
				tmp = ccol[3];
				tmp2 = ccol[6];
			} else {
				tmp = wcol[3];
				tmp2 = wcol[6];
			}
			j = (!isWRule(0));
			
			if((mission_type[c_mission] == 33) && (english)) {
				// 逆トリプルオーダー＠英語モード
				drawBlockFast(moffset + 1, 23 - j, 3, 0, tmp, 0, 0, 0, 0);
				drawBlockFast(moffset + 5, 23 - j, 6, 0, tmp2, 0, 0, 0, 0);
			} else {
				// その他
				if(english) {
					drawBlockFast(moffset + 1, 22 - j, 3, 0, tmp, 0, 0, 0, 0);
					drawBlockFast(moffset + 5, 22 - j, 6, 0, tmp2, 0, 0, 0, 0);
				} else {
					drawBlockFast(moffset + 1, 19 - j, 3, 0, tmp, 0, 0, 0, 0);
					drawBlockFast(moffset + 5, 19 - j, 6, 0, tmp2, 0, 0, 0, 0);
				}
			}
		}
	}
	
	// ミッション一覧
	tmp = 0;
	
	while(c_mission - tmp > 4) {
		tmp = tmp + 5;
	}
	
	for(i = tmp; i < (tmp + 5); i++) {
		if((c_mission > i) || (ending[0] != 0)) {
			// クリア済み
			ExBltFastRect(4, moffset, 32 + (i - tmp) * 16, 0, 48, 96, 16);
			ExBltRect(3, moffset + 98, 34 + (i - tmp) * 16, 12, 191, 12, 12);
		} else if(c_mission == i) {
			// プレイ中
			ExBltFastRect(4, moffset, 32 + (i - tmp) * 16, 0, 32, 96, 16);
			ExBltRect(3, moffset + 98, 34 + (i - tmp) * 16, 0, 191, 12, 12);
		} else {
			// まだ未プレイ
			ExBltFastRect(4, moffset, 32 + (i - tmp) * 16, 0, 16, 96, 16);
			ExBltRect(3, moffset + 98, 34 + (i - tmp) * 16, 0, 191, 12, 12);
		}
		
		// 終了フラグがある場合はここでループを抜ける
		if((mission_end[i] != 0) && (mission_end[i] != 10)) break;
	}
}

// 文字
void viewMissionText() {
	int i, tmp, count, draw_rate, tmp2;
	
	for(i = 0; i < 10; i++) TextLayerOff(i);
	
	if(mission_hide_info) return;
	
	if(screenMode >= 2) draw_rate = 2;
	else draw_rate = 1;
	
	// 題名
	TextSize(0, 10 * draw_rate);
	TextColor(0, 0, 0, 0);
	TextBackColorDisable(0);
	
	if(!english) {
		// 日本語
		if(mission_type[c_mission] < 0) {
			tmp2 = (mission_type[c_mission] + 1) * -1;
			StrCpy(string[0], mission_ext_name_jp[tmp2]);
		} else {
			StrCpy(string[0], mission_name_jp[mission_type[c_mission]]);
		}
	} else {
		// English
		if(mission_type[c_mission] < 0) {
			tmp2 = (mission_type[c_mission] + 1) * -1;
			StrCpy(string[0], mission_ext_name_en[tmp2]);
		} else {
			StrCpy(string[0], mission_name_en[mission_type[c_mission]]);
		}
	}
	
	// +
	if(mission_lv[c_mission] >= 15) StrCat(string[0], "+");
	
	// レベル
	if(mission_lv[c_mission] >= 15) sprintf(string[1], " LV%02d", mission_lv[c_mission] - 14);
	else                            sprintf(string[1], " LV%02d", mission_lv[c_mission] + 1);
	StrCat(string[0], string[1]);
	
	TextOut(0, string[0]);
	TextLayerOn(0, (5 + moffset) * draw_rate, (8 + 112) * draw_rate);
	
	// 制限時間
	TextSize(1, 10 * draw_rate);
	TextColor(1, 0, 0, 0);
	TextBackColorDisable(1);
	
	StrCpy(string[1], mission_timelimit[english]);
	
	if(mission_time[c_mission] > 0) {
		getTime(mission_time[c_mission]);
	} else {
		StrCpy(string[0], mission_timelimit[2 + english]);
	}
	StrCat(string[1], string[0]);
	
	TextOut(1, string[1]);
	TextLayerOn(1, (5 + moffset) * draw_rate, (20 + 112) * draw_rate);
	
	// 指令文
	TextSize(2, 10 * draw_rate);
	TextColor(2, 0, 0, 0);
	TextBackColorDisable(2);
	
	if(mission_type[c_mission] < 0) {
		// 拡張
		tmp2 = (mission_type[c_mission] + 1) * -1;
		
		if(!english)
			sprintf(string[0], mission_ext_info_jp[tmp2], mission_norm[c_mission]);
		else
			sprintf(string[0], mission_ext_info_en[tmp2], mission_norm[c_mission]);
	} else {
		// 標準
		if(!english)
			sprintf(string[0], mission_info_jp[mission_type[c_mission]], mission_norm[c_mission]);
		else
			sprintf(string[0], mission_info_en[mission_type[c_mission]], mission_norm[c_mission]);
	}
	
	// ダブルの追加条件
	if(mission_type[c_mission] == 2) {
		// 指定以上もカウント
		if(mission_opt_1[c_mission] == 1) {
			if(!english) StrCat(string[0], mission_info2_jp[1]);
			else StrCat(string[0], mission_info2_en[1]);
		}
		// 失敗するとノルマリセット
		if(mission_opt_1[c_mission] >= 2) {
			if(!english) StrCat(string[0], mission_info2_jp[4]);
			else StrCat(string[0], mission_info2_en[4]);
		}
	}
	
	// トリプルの追加条件
	if(mission_type[c_mission] == 3) {
		// 指定以上もカウント
		if(mission_opt_1[c_mission] == 1) {
			if(!english) StrCat(string[0], mission_info2_jp[2]);
			else StrCat(string[0], mission_info2_en[2]);
		}
		// 失敗するとノルマリセット
		if(mission_opt_1[c_mission] >= 2) {
			if(!english) StrCat(string[0], mission_info2_jp[5]);
			else StrCat(string[0], mission_info2_en[5]);
		}
	}
	
	// ヘボリスの追加条件
	if(mission_type[c_mission] == 4) {
		// 失敗するとノルマリセット
		if(mission_opt_1[c_mission] >= 2) {
			if(!english) StrCat(string[0], mission_info2_jp[6]);
			else StrCat(string[0], mission_info2_en[6]);
		}
	}
	
	// シングルの追加条件
	if(mission_type[c_mission] == 11) {
		// 指定以上もカウント
		if(mission_opt_1[c_mission] == 1) {
			if(!english) StrCat(string[0], mission_info2_jp[0]);
			else StrCat(string[0], mission_info2_en[0]);
		}
		// 失敗するとノルマリセット
		if(mission_opt_1[c_mission] >= 2) {
			if(!english) StrCat(string[0], mission_info2_jp[3]);
			else StrCat(string[0], mission_info2_en[3]);
		}
	}
	
	// コンボの追加条件
	if(mission_type[c_mission] == 27) {
		if(mission_opt_3[c_mission] >= 1) {
			if(!english) StrCat(string[0], mission_info2_jp[7]);
			else StrCat(string[0], mission_info2_en[7]);
		}
	}
	
	// ブロックオーダー系の追加条件
	if( ((mission_type[c_mission] >= 30) && (mission_type[c_mission] <= 33)) || (mission_type[c_mission] == 38) ) {
		if(mission_opt_1[c_mission] >= 1) {
			if(!english) StrCat(string[0], mission_info2_jp[8]);
			else StrCat(string[0], mission_info2_en[8]);
		}
	}
	
	// シングルオーダーの追加条件
	if(mission_type[c_mission] == 31) {
		// 指定以上もカウント
		if(mission_opt_2[c_mission] == 1) {
			if(!english) StrCat(string[0], mission_info2_jp[0]);
			else StrCat(string[0], mission_info2_en[0]);
		}
		// 失敗するとノルマリセット
		if(mission_opt_2[c_mission] >= 2) {
			if(!english) StrCat(string[0], mission_info2_jp[3]);
			else StrCat(string[0], mission_info2_en[3]);
		}
	}
	
	// ダブルオーダーの追加条件
	if(mission_type[c_mission] == 32) {
		// 指定以上もカウント
		if(mission_opt_2[c_mission] == 1) {
			if(!english) StrCat(string[0], mission_info2_jp[1]);
			else StrCat(string[0], mission_info2_en[1]);
		}
		// 失敗するとノルマリセット
		if(mission_opt_2[c_mission] >= 2) {
			if(!english) StrCat(string[0], mission_info2_jp[4]);
			else StrCat(string[0], mission_info2_en[4]);
		}
	}
	
	// T-スピンダブルの追加条件
	if(mission_type[c_mission] == 37) {
		// 指定以上もカウント
		if(mission_opt_1[c_mission] >= 1) {
			if(!english) StrCat(string[0], mission_info2_jp[1]);
			else StrCat(string[0], mission_info2_en[1]);
		}
	}
	
	// トリプルオーダー＆逆トリプルオーダーの追加条件
	if((mission_type[c_mission] == 33) || (mission_type[c_mission] == 38)) {
		// 指定以上もカウント
		if(mission_opt_2[c_mission] == 1) {
			if(!english) StrCat(string[0], mission_info2_jp[2]);
			else StrCat(string[0], mission_info2_en[2]);
		}
		// 失敗するとノルマリセット
		if(mission_opt_2[c_mission] >= 2) {
			if(!english) StrCat(string[0], mission_info2_jp[5]);
			else StrCat(string[0], mission_info2_en[5]);
		}
	}
	
	// 最後はダブルで消せ
	if((mission_end[c_mission] == 2) || (mission_end[c_mission] == 3) || (mission_end[c_mission] == 10))
		StrCat(string[0], mission_final_line[english]);
	
	TextOut(2, string[0]);
	TextLayerOn(2, (5 + moffset) * draw_rate, (40 + 112) * draw_rate);
	
	// ミッション一覧
	tmp = 0;
	count = 0;
	
	while(c_mission - tmp > 4) {
		tmp = tmp + 5;
	}
	
	for(i = tmp; i < (tmp + 5); i++) {
		if(!english) {
			// 日本語
			if(mission_type[i] < 0) {
				tmp2 = (mission_type[i] + 1) * -1;
				StrCpy(string[0], mission_ext_name_jp[tmp2]);
			} else {
				StrCpy(string[0], mission_name_jp[mission_type[i]]);
			}
		} else {
			// English
			if(mission_type[i] < 0) {
				tmp2 = (mission_type[i] + 1) * -1;
				StrCpy(string[0], mission_ext_name_en[tmp2]);
			} else {
				StrCpy(string[0], mission_name_en[mission_type[i]]);
			}
		}
		
		// +
		if(mission_lv[i] >= 15) StrCat(string[0], "+");
		
		TextSize(3 + count, 10 * draw_rate);
		TextColor(3 + count, 0, 0, 0);
		TextBackColorDisable(3 + count);
		TextOut(3 + count, string[0]);
		TextLayerOn(3 + count, (1 + moffset) * draw_rate, (1 + 32 + count * 16) * draw_rate);
		
		count++;
		
		// 終了フラグがある場合はここでループを抜ける
		if((mission_end[i] != 0) && (mission_end[i] != 10)) break;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ミッションモードのノルマ上昇
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void missionNormUp(int lines) {
	int i, j;
	int by2, tmp;
	int data[2];
	int player;
	int gap;
	player = 0;
	
	// ダブル
	if(mission_type[c_mission] == 2)
	{
		if(mission_opt_1[c_mission] == 0) {
			if(lines == 2) c_norm[0]++;
		} else if(mission_opt_1[c_mission] == 1) {
			if(lines >= 2) c_norm[0]++;	// ダブル以上もOK
		} else {
			// 失敗するとやり直し
			if(lines == 2) {
				c_norm[0]++;
			} else if(c_norm[0]) {
				// REGRET
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
				
				// やり直し
				c_norm[0] = 0;
			}
		}
	}
	// トリプル
	else if(mission_type[c_mission] == 3)
	{
		if(mission_opt_1[c_mission] == 0) {
			if(lines == 3) c_norm[0]++;
		} else if(mission_opt_1[c_mission] == 1) {
			if(lines >= 3) c_norm[0]++;	// トリプル以上もOK
		} else {
			// 失敗するとやり直し
			if(lines == 3) {
				c_norm[0]++;
			} else if(c_norm[0]) {
				// REGRET
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
				
				// やり直し
				c_norm[0] = 0;
			}
		}
	}
	// ヘボリス
	else if(mission_type[c_mission] == 4)
	{
		if(mission_opt_1[c_mission] <= 1) {
			// 通常
			if(lines == 4) c_norm[0]++;
		} else {
			// 失敗するとやり直し
			if(lines == 4) {
				c_norm[0]++;
			} else if(c_norm[0]) {
				// REGRET
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
				
				// やり直し
				c_norm[0] = 0;
			}
		}
	}
	// サイクル
	else if(mission_type[c_mission] == 5)
	{
		if(!cycle[lines - 1]) {
			cycle[lines - 1] = 1;
			c_norm[0]++;
		}
	}
	// ターゲット
	else if(mission_type[c_mission] == 6)
	{
		// ほとんどの部分はstatEraseでクリア判定をします。
		// ここでは一部の処理だけです。
		if(getPlatinumBlock(0) == 0) {
			PlaySE(37);
			clear_mission = lines;
			timeOn[0] = 0;
			c_norm[0]++;
		}
	}
	// イレイサー
	else if((mission_type[c_mission] == 7) || (mission_type[c_mission] == 39) || (mission_type[c_mission] == 40))
	{
		if((lines == 4) || (mission_type[c_mission] != 40)) {
			for(i = 0; i < 4; i++) {
				// 調べるY座標を決める
				getBlockData(0, bx[0], by[0], blk[0], rt[0], i, &data);
				by2 = data[1];
				
				// 消すべきラインか調べる
				for(j = 0; j < eraser_now_lines; j++) {
					if(j >= 4) break;
					
					if( (by2 == eraser_lines[j]) && (erase[by2]) && (!eraser_cleared[j]) ) {
						eraser_cleared[j] = 1;
						c_norm[0]++;
					}
				}
			}
			
			// 全部消えているのにノルマ達成していない場合は新たなパターン出現
			if(c_norm[0] < m_norm[0]) {
				tmp = 1;
				
				for(i = 0; i < eraser_now_lines; i++) {
					if(!eraser_cleared[i]) {
						tmp = 0;
						break;
					}
				}
				
				if(tmp) {
					eraser_now_pattern++;
					setEraserLines();
				}
			}
		}
	}
	// シングル
	else if(mission_type[c_mission] == 11)
	{
		if(mission_opt_1[c_mission] == 0) {
			if(lines == 1) c_norm[0]++;
		} else if(mission_opt_1[c_mission] == 1) {
			if(lines >= 1) c_norm[0]++;	// ダブル以上もOK
		} else {
			// 失敗するとやり直し
			if(lines == 1) {
				c_norm[0]++;
			} else if(c_norm[0]) {
				// REGRET
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
				
				// やり直し
				c_norm[0] = 0;
			}
		}
	}
	// T-スピン
	else if(mission_type[c_mission] == 16)
	{
		if(tspin_type) {
			if(IsTspin[0]) c_norm[0]++;
		} else {
			c_norm[0] = c_norm[0] + lines;
		}
	}
	// 耐久
	else if(mission_type[c_mission] == 23)
	{
		if(ltime[0] <= 0) c_norm[0]++;
	}
	// 全消し
	else if(mission_type[c_mission] == 26)
	{
		c_norm[0]++;
	}
	// コンボ
	else if(mission_type[c_mission] == 27)
	{
		if(enable_combo) {
			if(mission_opt_3[c_mission] == 1) c_norm[0] = combo2[0];
			else c_norm[0] = combo[0];
		} else {
			c_norm[0] = c_norm[0] + lines;
		}
	}
	// B to B ヘボリス
	else if(mission_type[c_mission] == 28)
	{
		if(lines == 4) {
			c_norm[0]++;
		} else if(c_norm[0]) {
			// REGRET
			PlaySE(44);
			gup_down[player] = 0;
			gflash[player] = 120;
			
			// やり直し
			c_norm[0] = 0;
		}
	}
	// OOBAKA
	else if(mission_type[c_mission] == 29)
	{
		if(lines == 0) c_norm[0]++;
	}
	// ブロックオーダー
	else if(mission_type[c_mission] == 30)
	{
		if( (mission_opt_1[c_mission] == 0) || 
		    ((mission_opt_1[c_mission] >= 1) && (dhold2[0]) && (hold_used[0] >= 2)) )
		{
			if(mission_opt_3[c_mission] <= 6) {
				if(blk[0] == mission_opt_3[c_mission]) c_norm[0] = c_norm[0] + lines;
			} else if(mission_opt_3[c_mission] == 7) {
				if((blk[0] == 1) || (blk[0] == 5)) c_norm[0] = c_norm[0] + lines;
			} else if(mission_opt_3[c_mission] == 8) {
				if((blk[0] == 3) || (blk[0] == 6)) c_norm[0] = c_norm[0] + lines;
			}
		}
	}
	// シングルオーダー
	else if(mission_type[c_mission] == 31)
	{
		if( (mission_opt_1[c_mission] == 0) || 
		    ((mission_opt_1[c_mission] >= 1) && (dhold2[0]) && (hold_used[0] >= 2)) )
		{
			if( (lines == 1) || ((mission_opt_2[c_mission] == 1) && (lines >= 1)) ) {
				if(mission_opt_3[c_mission] <= 6) {
					if(blk[0] == mission_opt_3[c_mission]) c_norm[0]++;
				} else if(mission_opt_3[c_mission] == 7) {
					if((blk[0] == 1) || (blk[0] == 5)) c_norm[0]++;
				} else if(mission_opt_3[c_mission] == 8) {
					if((blk[0] == 3) || (blk[0] == 6)) c_norm[0]++;
				}
			} else if((mission_opt_2[c_mission] == 2) && (c_norm[0] > 0)) {
				// REGRET
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
				
				// やり直し
				c_norm[0] = 0;
			}
		}
	}
	// ダブルオーダー
	else if(mission_type[c_mission] == 32)
	{
		if( (mission_opt_1[c_mission] == 0) || 
		    ((mission_opt_1[c_mission] >= 1) && (dhold2[0]) && (hold_used[0] >= 2)) )
		{
			if( (lines == 2) || ((mission_opt_2[c_mission] == 1) && (lines >= 2)) ) {
				if(mission_opt_3[c_mission] <= 6) {
					if(blk[0] == mission_opt_3[c_mission]) c_norm[0]++;
				} else if(mission_opt_3[c_mission] == 7) {
					if((blk[0] == 1) || (blk[0] == 5)) c_norm[0]++;
				} else if(mission_opt_3[c_mission] == 8) {
					if((blk[0] == 3) || (blk[0] == 6)) c_norm[0]++;
				}
			} else if((mission_opt_2[c_mission] == 2) && (c_norm[0] > 0)) {
				// REGRET
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
				
				// やり直し
				c_norm[0] = 0;
			}
		}
	}
	// 裏トリプルオーダー
	else if(mission_type[c_mission] == 33)
	{
		if( (mission_opt_1[c_mission] == 0) || 
		    ((mission_opt_1[c_mission] >= 1) && (dhold2[0]) && (hold_used[0] >= 2)) )
		{
			if( (lines == 3) || ((mission_opt_2[c_mission] == 1) && (lines >= 3)) ) {
				if(mission_opt_3[c_mission] <= 6) {
					if(blk[0] != mission_opt_3[c_mission]) c_norm[0]++;
				} else if(mission_opt_3[c_mission] == 7) {
					if((blk[0] != 1) && (blk[0] != 5)) c_norm[0]++;
				} else if(mission_opt_3[c_mission] == 8) {
					if((blk[0] != 3) && (blk[0] != 6)) c_norm[0]++;
				}
			} else if((mission_opt_2[c_mission] == 2) && (c_norm[0] > 0)) {
				// REGRET
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
				
				// やり直し
				c_norm[0] = 0;
			}
		}
	}
	// 中抜きダブル
	else if(mission_type[c_mission] == 34)
	{
		if(lines == 2) {
			gap = 0;	// 中抜き判定
			j = 0;		// 中抜き判定フラグ
			
			for(i = 0; i < 22; i++) {
				if(erase[i])
					j++;
				else if(j != 0)
					gap++;
				
				if(j >= lines) break;
			}
			
			if(gap != 0) c_norm[0]++;
		}
	}
	// 中抜きトリプル
	else if(mission_type[c_mission] == 35)
	{
		if(lines == 3) {
			gap = 0;	// 中抜き判定
			j = 0;		// 中抜き判定フラグ
			
			for(i = 0; i < 22; i++) {
				if(erase[i])
					j++;
				else if(j != 0)
					gap++;
				
				if(j >= lines) break;
			}
			
			if(gap != 0) c_norm[0]++;
		}
	}
	// 2段抜きダブル
	else if(mission_type[c_mission] == 36)
	{
		if(lines == 2) {
			gap = 0;	// 中抜き判定
			j = 0;		// 中抜き判定フラグ
			
			for(i = 0; i < 22; i++) {
				if(erase[i])
					j++;
				else if(j != 0)
					gap++;
				
				if(j >= lines) break;
			}
			
			if(gap == 2) c_norm[0]++;
		}
	}
	// T-スピンダブル
	else if(mission_type[c_mission] == 37)
	{
		if(tspin_type) {
			if( (IsTspin[0]) && ((lines == 2) || ((mission_opt_1[c_mission] >= 1) && (lines >= 2))) )
				c_norm[0]++;
		} else {
			c_norm[0] = c_norm[0] + lines;
		}
	}
	// トリプルオーダー
	else if(mission_type[c_mission] == 38)
	{
		if( (mission_opt_1[c_mission] == 0) || 
		    ((mission_opt_1[c_mission] >= 1) && (dhold2[0]) && (hold_used[0] >= 2)) )
		{
			if( (lines == 3) || ((mission_opt_2[c_mission] == 1) && (lines >= 3)) ) {
				if(mission_opt_3[c_mission] <= 6) {
					if(blk[0] == mission_opt_3[c_mission]) c_norm[0]++;
				} else if(mission_opt_3[c_mission] == 7) {
					if((blk[0] == 1) || (blk[0] == 5)) c_norm[0]++;
				} else if(mission_opt_3[c_mission] == 8) {
					if((blk[0] == 3) || (blk[0] == 6)) c_norm[0]++;
				}
			} else if((mission_opt_2[c_mission] == 2) && (c_norm[0] > 0)) {
				// REGRET
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
				
				// やり直し
				c_norm[0] = 0;
			}
		}
	}
	// スクウェア／ゴールドスクウェア
	else if((mission_type[c_mission] == 41) || (mission_type[c_mission] == 42))
	{
		if(lines == 0) c_norm[0]++;
	}
	// シングルSP
	else if(mission_type[c_mission] == -1)
	{
		if(lines == 1) {
			c_norm[0]++;
		} else if(c_norm[0]) {
			// REGRET
			PlaySE(44);
			gup_down[player] = 0;
			gflash[player] = 120;
			
			// やり直し
			c_norm[0] = 0;
		}
	}
	// ダブルSP
	else if(mission_type[c_mission] == -2)
	{
		if(lines == 2) {
			c_norm[0]++;
		} else if(c_norm[0]) {
			// REGRET
			PlaySE(44);
			gup_down[player] = 0;
			gflash[player] = 120;
			
			// やり直し
			c_norm[0] = 0;
		}
	}
	// トリプルSP
	else if(mission_type[c_mission] == -3)
	{
		if(lines == 3) {
			c_norm[0]++;
		} else if(c_norm[0]) {
			// REGRET
			PlaySE(44);
			gup_down[player] = 0;
			gflash[player] = 120;
			
			// やり直し
			c_norm[0] = 0;
		}
	}
	// レベルスターなど
	else
	{
		c_norm[0] = c_norm[0] + lines;
	}
	
	// ミッションクリア
	if(c_norm[0] >= m_norm[0]) {
		c_norm[0] = m_norm[0];
		timeOn[0] = 0;
		clear_mission = lines;
		mission_clear_flag = 1;
		
		// タイム警告音を止める
		StopWave(38);
		
		// 「最後のラインをダブルで消せ！」を達成するとエクストラステージ進出権獲得
		if( (clear_mission == 2) && 
		    ((mission_end[c_mission] == 2) || (mission_end[c_mission] == 3) || (mission_end[c_mission] == 10)) )
		{
			mission_extra = 1;
			objectCreate(0, 4, Rand(20) + foffset[0] + 68, 20 + Rand(10), 0, 0, 0, 0);
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ミッション開始
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void missionSetStatus() {
	int i, tmp, player;
	player = 0;
	
	// ノルマ設定
	c_norm[0] = 0;
	m_norm[0] = mission_norm[c_mission];
	mission_clear_flag = 0;
	
	// タイム
	ltime[0] = mission_time[c_mission];
	
	// レベル
	tc[0] = mission_lv[c_mission];
	
	// BGM
	bgmlv = mission_bgm[c_mission];
	
	// ブロックを置いた回数
	bdowncnt[0] = 0;
	
	// ビッグ
	if(mission_type[c_mission] == 1) {
		IsBig[0] = 1;
		n_bx[0] = 2;
	} else {
		IsBig[0] = 0;
		n_bx[0] = 3;
	}
	
	// サイクル
	if(mission_type[c_mission] == 5) {
		for(i = 0; i < 4; i++) cycle[i] = 0;
	}
	
	// ターゲット
	if(mission_type[c_mission] == 6) {
		// 出現フラグ初期化
		for(i = 0; i < 1000; i++) target_cleared[i] = 0;
	}
	
	// イレイサー
	if((mission_type[c_mission] == 7) || (mission_type[c_mission] == 39) || (mission_type[c_mission] == 40)) {
		eraser_now_pattern = 0;
		setEraserLines();
	}
	
	// アナザー
	if((mission_type[c_mission] == 10) && (mission_opt_3[c_mission])) {
		isblind[0] = 1;
		blind_flag[0] = 1;
	} else {
		isblind[0] = 0;
		blind_flag[0] = 0;
	}
	
	// X-RAY
	if(mission_type[c_mission] == 12) {
		isxray[0] = 1;
		xray_flag[0] = 1;
		xray_counter[0] = 0;
	} else {
		isxray[0] = 0;
		xray_flag[0] = 0;
	}
	
	// カラー
	if(mission_type[c_mission] == 13) {
		iscolor[0] = 1;
		color_flag[0] = 1;
		color_counter[0] = 0;
	} else {
		iscolor[0] = 0;
		color_flag[0] = 0;
	}
	
	// ロールロール
	if(mission_type[c_mission] == 14) {
		rollroll_flag[0] = 1;
		isrollroll[0] = 1;
	} else {
		rollroll_flag[0] = 0;
		isrollroll[0] = 0;
	}
	
	// ミラー
	if(mission_type[c_mission] == 15) {
		isfmirror[0] = 1;
	} else {
		isfmirror[0] = 0;
	}
	
	// 回転不可
	if(mission_type[c_mission] == 17) {
		isRotateLock[0] = 1;
		
		// ブロックの向きをランダムにする
		for(i = 0; i < 6; i++) rt_nblk[i] = GiziRand(0, 4);
	} else {
		isRotateLock[0] = 0;
		
		for(i = 0; i < 6; i++) rt_nblk[i] = 0;
	}
	
	// NEXT不可視
	if(mission_type[c_mission] == 18) {
		ishidenext[0] = 1;
	} else {
		ishidenext[0] = 0;
	}
	
	// DEVIL 800
	if(mission_type[c_mission] == 19) {
		if(mission_opt_1[c_mission]) {
			r_enable[0] = 0;
		} else {
			r_enable[0] = 1;
			r_bdowncnt[0] = 0;
			r_start[0] = 0;
			r_end[0] = 999;
			upLines[0] = 0;
			uplinetype[0] = 0;
			
			if(mission_opt_2[c_mission]) {
				risecount[0] = 0;
				
				if((devil_rise_min[8] > 0) && (devil_rise_max[8] > 0)) {
					do {
						risecount[0] = GiziRand(0, devil_rise_max[8] + 1);
					} while(risecount[0] < devil_rise_min[8]);
				}
			} else {
				r_inter[0] = mission_opt_3[c_mission];
				if(r_inter[0] == 0) r_inter[0] = 20;
			}
		}
	} else {
		r_enable[0] = 0;
	}
	
	// GARBAGE
	if(mission_type[c_mission] == 21) {
		// 穴の位置を設定
		ghole[0] = GiziRand(0, 10);
		uplinetype[0] = 4;
		
		// せり上げ
		upLines[0] = mission_opt_3[c_mission];
		
		if(upLines[0] > 16 + spawn_y_type * 2) upLines[0] = 16 + spawn_y_type * 2;
	}
	
	// オールドスタイル
	if(mission_type[c_mission] == 22) {
		if(!mission_opt_1[c_mission]) {
			heboGB[0] = 1;
		} else {
			heboGB[0] = 2;
		}
		objectClear();
	} else {
		heboGB[0] = 0;
	}
	
	// 上下左右逆転
	if(mission_type[c_mission] == 24) {
		isUDLRreverse[0] = 1;
	} else {
		isUDLRreverse[0] = 0;
	}
	
	// ブラインド
	if(mission_type[c_mission] == 25) {
		isblind[0] = 1;
		blind_flag[0] = 1;
	}
	
	// 全消し
	if((mission_type[c_mission] == 26) && (mission_opt_3[c_mission] == 0)) {
		IsBig[0] = 1;
		n_bx[0] = 2;
	}
	
	// スクウェア／ゴールドスクウェア
	if((mission_type[c_mission] == 41) || (mission_type[c_mission] == 42)) {
		squaremode[0] = 1;
	} else {
		squaremode[0] = 0;
	}
	
	// []
	if((mission_type[c_mission] == 20) || (mission_type[c_mission] == -5) || (mission_type[c_mission] == -6)) {
		always_over1000[0] = 1;
	} else {
		always_over1000[0] = 0;
	}
	
	// 速度設定を反映させる
	speedtype[0] = 0;
	
	// ハイスピード１
	if(mission_type[c_mission] == 8)
	{
		sp[0] = lvTableHiSpeed1[tc[0]];
		wait1[0] = wait1_HiSpeed1;
		wait2[0] = wait2_HiSpeed1;
		wait3[0] = wait3_HiSpeed1;
		waitt[0] = waitt_HiSpeed1;
	}
	// ハイスピード２
	else if(mission_type[c_mission] == 9)
	{
		sp[0] = 1200;
		wait1[0] = wait1_HiSpeed2;
		wait2[0] = wait2_HiSpeed2;
		wait3[0] = wait3_HiSpeed2;
		waitt[0] = waitt_HiSpeed2;
	}
	// アナザー／耐久
	else if((mission_type[c_mission] == 10) || (mission_type[c_mission] == 23))
	{
		sp[0] = 1200;
		
		if(repversw <= 6) {
			wait1[0] = wait1_Acea_tbl6[tc[0]];
			wait2[0] = wait2_Acea_tbl6[tc[0]];
			wait3[0] = wait3_Acea_tbl6[tc[0]];
			waitt[0] = waitt_Acea_tbl6[tc[0]];
		} else if(repversw <= 7) {
			wait1[0] = wait1_Acea_tbl7[tc[0]];
			wait2[0] = wait2_Acea_tbl7[tc[0]];
			wait3[0] = wait3_Acea_tbl7[tc[0]];
			waitt[0] = waitt_Acea_tbl7[tc[0]];
		} else {
			wait1[0] = wait1_Acea_tbl[tc[0]];
			wait2[0] = wait2_Acea_tbl[tc[0]];
			wait3[0] = wait3_Acea_tbl[tc[0]];
			waitt[0] = waitt_Acea_tbl[tc[0]];
		}
	}
	// DEVIL 800
	else if(mission_type[c_mission] == 19)
	{
		sp[0] = 1200;
		
		if(repversw <= 6) {
			wait1[0] = wait1_devil_tbl6[8];
			wait2[0] = wait2_devil_tbl6[8];
			wait3[0] = wait3_devil_tbl6[8];
			waitt[0] = waitt_devil_tbl6[8];
		} else if(repversw <= 7) {
			wait1[0] = wait1_devil_tbl7[8];
			wait2[0] = wait2_devil_tbl7[8];
			wait3[0] = wait3_devil_tbl7[8];
			waitt[0] = waitt_devil_tbl7[8];
		} else {
			wait1[0] = wait1_devil_tbl[8];
			wait2[0] = wait2_devil_tbl[8];
			wait3[0] = wait3_devil_tbl[8];
			waitt[0] = waitt_devil_tbl[8];
		}
	}
	// DEVIL 1200
	else if(mission_type[c_mission] == 20)
	{
		sp[0] = 1200;
		
		if(!mission_opt_3[c_mission]) {
			wait1[0] = wait1_devil_tbl32[12];
			wait2[0] = wait2_devil_tbl32[12];
			wait3[0] = wait3_devil_tbl32[12];
			waitt[0] = waitt_devil_tbl32[12];
		} else {
			if(repversw <= 6) {
				wait1[0] = wait1_devil_tbl6[12];
				wait2[0] = wait2_devil_tbl6[12];
				wait3[0] = wait3_devil_tbl6[12];
				waitt[0] = waitt_devil_tbl6[12];
			} else if(repversw <= 7) {
				wait1[0] = wait1_devil_tbl7[12];
				wait2[0] = wait2_devil_tbl7[12];
				wait3[0] = wait3_devil_tbl7[12];
				waitt[0] = waitt_devil_tbl7[12];
			} else {
				wait1[0] = wait1_devil_tbl[12];
				wait2[0] = wait2_devil_tbl[12];
				wait3[0] = wait3_devil_tbl[12];
				waitt[0] = waitt_devil_tbl[12];
			}
		}
	}
	// オールドスタイル
	else if(mission_type[c_mission] == 22)
	{
		if(!mission_opt_1[c_mission]) {
			tmp = tc[0];
			if(tmp > 14) tmp = 14;
			sp[0] = lvTableHeboGB[tmp];
			wait1[0] = wait1_HeboGB;
			wait2[0] = wait2_HeboGB;
			wait3[0] = wait3_HeboGB_tbl[tmp];
			waitt[0] = waitt_HeboGB_tbl[tmp];
		} else {
			if(tc[0] >= 15) sp[0] = lvTableHeboAC[15];
			else sp[0] = lvTableHeboAC[tc[0]];
			wait1[0] = wait1_HeboAC;
			wait2[0] = wait2_HeboAC;
			wait3[0] = wait3_HeboAC;
			waitt[0] = waitt_HeboAC;
			speedtype[0] = 1;
		}
	}
	// OOBAKA
	else if(mission_type[c_mission] == 29)
	{
		sp[0] = speed_oobaka;
		wait1[0] = wait1_oobaka;
		wait2[0] = wait2_oobaka;
		wait3[0] = wait3_oobaka;
		waitt[0] = waitt_oobaka;
	}
	// BASIC
	else if(mission_type[c_mission] == -4)
	{
		tmp = mission_lv[c_mission];
		if(tmp > 19) tmp = 19;
		
		sp[0] = lvTableAce200Basic[tmp];
		wait1[0] = wait1_Ace200Basic_tbl[tmp];
		wait2[0] = wait2_Ace200Basic_tbl[tmp];
		wait3[0] = wait3_Ace200Basic_tbl[tmp];
		waitt[0] = waitt_Ace200Basic_tbl[tmp];
	}
	// VOID
	else if(mission_type[c_mission] == -5)
	{
		tmp = mission_lv[c_mission];
		if(tmp > 19) tmp = 19;
		
		sp[0] = 1200;
		wait1[0] = wait1_Ace200Void_tbl[tmp];
		wait2[0] = wait2_Ace200Void_tbl[tmp];
		wait3[0] = wait3_Ace200Void_tbl[tmp];
		waitt[0] = waitt_Ace200Void_tbl[tmp];
	}
	// FINAL
	else if(mission_type[c_mission] == -6)
	{
		tmp = mission_lv[c_mission];
		if(tmp > 9) tmp = 9;
		
		sp[0] = 1200;
		if(repversw <= 4) {
			wait1[0] = wait1_final4[tmp];
			wait2[0] = wait2_final4[tmp];
			wait3[0] = wait3_final4[tmp];
			waitt[0] = waitt_final4[tmp];
		} else {
			if(rule_lock_reset[rots[0]]) {
				wait1[0] = wait1_final_srs[tmp];
				wait2[0] = wait2_final_srs[tmp];
				wait3[0] = wait3_final_srs[tmp];
				waitt[0] = waitt_final_srs[tmp];
			} else {
				wait1[0] = wait1_final_ars[tmp];
				wait2[0] = wait2_final_ars[tmp];
				wait3[0] = wait3_final_ars[tmp];
				waitt[0] = waitt_final_ars[tmp];
			}
		}
	}
	// 速度固定
	else if(mission_type[c_mission] == -7)
	{
		wait1[0] = mission_opt_1[c_mission];
		wait2[0] = mission_opt_2[c_mission];
		wait3[0] = mission_opt_3[c_mission];
		waitt[0] = mission_opt_4[c_mission];
		
		if(mission_opt_5[c_mission] >= 999) {
			sp[0] = 1200;
		} else {
			sp[0] = mission_opt_5[c_mission];
		}
	}
	// その他
	else
	{
		if(mission_lv[c_mission] >= 15) {
			sp[0] = 1200;
			
			if(repversw <= 6) {
				wait1[0] = wait1_Acea_tbl6[mission_lv[c_mission] - 15];
				wait2[0] = wait2_Acea_tbl6[mission_lv[c_mission] - 15];
				wait3[0] = wait3_Acea_tbl6[mission_lv[c_mission] - 15];
				waitt[0] = waitt_Acea_tbl6[mission_lv[c_mission] - 15];
			} else if(repversw <= 7) {
				wait1[0] = wait1_Acea_tbl7[mission_lv[c_mission] - 15];
				wait2[0] = wait2_Acea_tbl7[mission_lv[c_mission] - 15];
				wait3[0] = wait3_Acea_tbl7[mission_lv[c_mission] - 15];
				waitt[0] = waitt_Acea_tbl7[mission_lv[c_mission] - 15];
			} else {
				wait1[0] = wait1_Acea_tbl[mission_lv[c_mission] - 15];
				wait2[0] = wait2_Acea_tbl[mission_lv[c_mission] - 15];
				wait3[0] = wait3_Acea_tbl[mission_lv[c_mission] - 15];
				waitt[0] = waitt_Acea_tbl[mission_lv[c_mission] - 15];
			}
		} else {
			if(repversw >= 2) sp[0] = lvTableAce[mission_lv[c_mission]];
			else if(repversw == 1) sp[0] = lvTableAce1[mission_lv[c_mission]];
			else sp[0] = lvTableAceOld[mission_lv[c_mission]];
			wait1[0] = wait1_Ace;
			wait2[0] = wait2_Ace;
			wait3[0] = wait3_Ace;
			waitt[0] = waitt_Ace;
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  イレイサー関連
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲

// 初期化処理
void setEraserLines() {
	int i, tmp, min, max, tmp2;
	int line[22];	// ラインの重複防止用
	
	eraser_now_lines = 0;
	
	// 出現範囲を決める
	min = mission_opt_1[c_mission];
	max = mission_opt_2[c_mission];
	
	if(min < 3) min = 3;
	if(max > 21) max = 21;
	
	if(min > max) {
		min = i;
		min = max;
		i = max;
	}
	
	if(mission_type[c_mission] == 39) {
		// イレイサー２
		eraser_lines[0] = min;
		eraser_lines[1] = max;
		eraser_cleared[0] = 0;
		eraser_cleared[1] = 0;
		eraser_now_lines = 2;
	} else {
		for(i = 0; i < 22; i++) line[i] = 0;
		
		if(eraser_now_pattern == 0) tmp2 = mission_opt_3[c_mission];
		else if(eraser_now_pattern == 1) tmp2 = mission_opt_4[c_mission];
		else if(eraser_now_pattern == 2) tmp2 = mission_opt_5[c_mission];
		else tmp2 = mission_opt_6[c_mission];
		
		for(i = 0; i <= tmp2; i++) {
			// 最大4本まで
			if(i >= 4) break;
			
			// 余分なラインを出さない
			if(i >= mission_norm[c_mission] - c_norm[0]) break;
			
			eraser_now_lines++;
			
			if(min == max) {
				// 位置固定
				tmp = min;
			} else if((i >= mission_norm[c_mission] - c_norm[0] - 1) && (mission_norm[c_mission] > 1) && (!line[min + 1])) {
				// 最後の1本
				tmp = min + 1;
			} else {
				// ランダム
				do {
					tmp = GiziRand(0, 22);
				} while( (tmp < min) || (tmp > max) || (line[tmp] == 1) );
			}
			
			line[tmp] = 1;
			eraser_lines[i] = tmp;
			eraser_cleared[i] = 0;
		}
	}
}

// イレイサーの線を表示
void viewEraserLines() {
	int i;
	
	for(i = 0; i < eraser_now_lines; i++) {
		if(mission_type[c_mission] == 40)
			ExBltRect(4, (boffset[0] - 1) * 8, (eraser_lines[i] + 3) * 8, 0, 176 + eraser_cleared[i] * 8, 95, 8);
		else
			ExBltRect(4, (boffset[0] - 1) * 8, (eraser_lines[i] + 3) * 8, 0, eraser_cleared[i] * 8, 95, 8);
	}
}

// ターゲットのステージの読み込み
void loadTargetStage() {
	int tmp, min, max, isflash;
	
	if((!mission_opt_7[c_mission]) || (c_norm[0] < mission_opt_7[c_mission])) {
		// パターン1
		min = mission_opt_1[c_mission];
		max = mission_opt_2[c_mission];
		isflash = mission_opt_3[c_mission];
	} else {
		// パターン2
		min = mission_opt_8[c_mission];
		max = mission_opt_9[c_mission];
		isflash = mission_opt_10[c_mission];
	}
	
	if(min == max) {
		// ステージが1つだけの場合
		tmp = min;
	} else {
		do {
			tmp = GiziRand(0, max + 1);
		} while((tmp < min) || (target_cleared[tmp] != 0));
	}
	
	target_cleared[tmp] = 1;
	loadTomoyoStage(0, tmp, isflash);
	
	// 全てのブロックをプラチナにする
	if(mission_opt_6[c_mission]) {
		TransformAllBlockToPlatinumBlock();
	}
	// プラチナブロックの配置をランダムにする
	else if(mission_opt_4[c_mission]) {
		RandmizePlatinumBlock(mission_opt_4[c_mission], mission_opt_5[c_mission]);
	}
	
	// せり上がりタイプ設定
	uplinetype[0] = 2;
}

// プラチナブロックの配置をランダムにする
void RandmizePlatinumBlock(int randmax, int opt) {
	int i, j, k, pblk;
	int line[22];
	pblk = 0;
	
	if(opt) {
		pblk = opt;
		i = 22 - checkFieldTop(0);	// フリーズ対策
		if(pblk > i) pblk = i;
	}
	
	// プラチナブロックを普通のブロックにする＆プラチナブロックの数を数える
	for(i = 0; i < 22; i++) {
		line[i] = 0;
		
		for(k = 0; k < 10; k++) {
			if(fld[k + i * 10] >= 11) {
				if(!opt) pblk++;
				fld[k + i * 10] = fld[k + i * 10] - 9;
			}
		}
	}
	
	// プラチナブロックをランダムに配置
	j = 0;
	while(j < pblk) {
		for(i = 0; i < 22; i++) {
			for(k = 0; k < 10; k++) {
				if((fld[k + i * 10] >= 2) && (fld[k + i * 10] <= 8) && (!line[i])) {
					if(GiziRand(0, randmax) == 0) {
						fld[k + i * 10] = fld[k + i * 10] + 9;
						if(opt) line[i] = 1;
						j++;
						if(j >= pblk) return;
					}
				}
			}
		}
	}
}

// 全てのブロックをプラチナブロックにする
void TransformAllBlockToPlatinumBlock() {
	int i;
	
	for(i = 0; i < 220; i++) {
		if(fld[i] != 0) fld[i] = 11 + Rand(7);
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  問題データの読み込み／保存
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
/* ロード */
void loadMissionData(int number) {
	int i, temp[4];
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	sprintf(string[0], "stage/mission%02d.sav", number);
	
	LoadFile(string[0], &saveBuf, 624 * 4);
	
	mission_hide_info = saveBuf[1];
	mission_clear_anim = saveBuf[2];
	
	// 問題データを読み込み
	for(i = 0; i < 30; i++) {
		mission_type[i]   = saveBuf[(i + 1) * 20 +  0];	// 種類
		mission_norm[i]   = saveBuf[(i + 1) * 20 +  1];	// ノルマ
		mission_time[i]   = saveBuf[(i + 1) * 20 +  2];	// 制限時間
		mission_end[i]    = saveBuf[(i + 1) * 20 +  3];	// 終了フラグ
		mission_lv[i]     = saveBuf[(i + 1) * 20 +  4];	// レベル
		mission_erase[i]  = saveBuf[(i + 1) * 20 +  5];	// クリア時に上から消去するライン数
		mission_opt_1[i]  = saveBuf[(i + 1) * 20 +  6];	// 追加情報１
		mission_opt_2[i]  = saveBuf[(i + 1) * 20 +  7];	// 追加情報２
		mission_opt_3[i]  = saveBuf[(i + 1) * 20 +  8];	// 追加情報３
		mission_bgm[i]    = saveBuf[(i + 1) * 20 +  9];	// BGM
		mission_opt_4[i]  = saveBuf[(i + 1) * 20 + 10];	// 追加情報４
		mission_opt_5[i]  = saveBuf[(i + 1) * 20 + 11];	// 追加情報５
		mission_opt_6[i]  = saveBuf[(i + 1) * 20 + 12];	// 追加情報６
		mission_bg[i]     = saveBuf[(i + 1) * 20 + 13];	// 背景
		mission_opt_7[i]  = saveBuf[(i + 1) * 20 + 14];	// 追加情報７
		mission_opt_8[i]  = saveBuf[(i + 1) * 20 + 15];	// 追加情報８
		mission_opt_9[i]  = saveBuf[(i + 1) * 20 + 16];	// 追加情報９
		mission_opt_10[i] = saveBuf[(i + 1) * 20 + 17];	// 追加情報10
	}
	
	// コース名を読み込み
	if(saveBuf[0] == 2) {
		temp[0] = saveBuf[620];
		temp[1] = saveBuf[621];
		temp[2] = saveBuf[622];
		temp[3] = saveBuf[623];
		StrCpy(mission_course_name, &temp);
	} else {
		StrCpy(mission_course_name, "");
	}
}

/* セーブ */
void saveMissionData(int number) {
	int i, temp[4];
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 2;
	saveBuf[1] = mission_hide_info;
	saveBuf[2] = mission_clear_anim;
	
	// 問題データ
	for(i = 0; i < 30; i++) {
		saveBuf[(i + 1) * 20 +  0] = mission_type[i];	// 種類
		saveBuf[(i + 1) * 20 +  1] = mission_norm[i];	// ノルマ
		saveBuf[(i + 1) * 20 +  2] = mission_time[i];	// 制限時間
		saveBuf[(i + 1) * 20 +  3] = mission_end[i];	// 終了フラグ
		saveBuf[(i + 1) * 20 +  4] = mission_lv[i];		// レベル
		saveBuf[(i + 1) * 20 +  5] = mission_erase[i];	// クリア時に上から消去するライン数
		saveBuf[(i + 1) * 20 +  6] = mission_opt_1[i];	// 追加情報１
		saveBuf[(i + 1) * 20 +  7] = mission_opt_2[i];	// 追加情報２
		saveBuf[(i + 1) * 20 +  8] = mission_opt_3[i];	// 追加情報３
		saveBuf[(i + 1) * 20 +  9] = mission_bgm[i];	// BGM
		saveBuf[(i + 1) * 20 + 10] = mission_opt_4[i];	// 追加情報４
		saveBuf[(i + 1) * 20 + 11] = mission_opt_5[i];	// 追加情報５
		saveBuf[(i + 1) * 20 + 12] = mission_opt_6[i];	// 追加情報６
		saveBuf[(i + 1) * 20 + 13] = mission_bg[i];		// 背景
		saveBuf[(i + 1) * 20 + 14] = mission_opt_7[i];	// 追加情報７
		saveBuf[(i + 1) * 20 + 15] = mission_opt_8[i];	// 追加情報８
		saveBuf[(i + 1) * 20 + 16] = mission_opt_9[i];	// 追加情報９
		saveBuf[(i + 1) * 20 + 17] = mission_opt_10[i];	// 追加情報10
	}
	
	// コース名を保存
	if(StrLen(mission_course_name) > 0) {
		StrCpy(&temp, mission_course_name);
		saveBuf[620] = temp[0];
		saveBuf[621] = temp[1];
		saveBuf[622] = temp[2];
		saveBuf[623] = temp[3];
	}
	
	sprintf(string[0], "stage/mission%02d.sav", number);
	SaveFile(string[0], &saveBuf, 624 * 4);
}
