//VS-ULTRA
//prefix:vsu

// バージョン
int vsuVersion;					// バージョン番号（古いリプレイ再生用）
int vsuCVersion = 2;			// 現在のバージョン

// 変数
int vsuModeNo = -1;				// モード番号

int vsuScore[2];				// スコア
int vsuLines[2];				// ライン数
int vsuLimitTime[2];			// 残り時間

int vsuTSpinFrame[2];			// T-SPIN表示／ヘボリス表示の残り時間
int vsuTSpinLine[2];			// 最後のT-SPINライン消し／ヘボリス消しの種類
int vsuComboFrame[2];			// コンボ数表示の残り時間
int vsuB2BFrame[2];				// Back To Back表示の残り時間
int vsuTSpinWall[2];			// 壁蹴りありのT-SPINだったら1になる
int vsuScoreGet[2];				// 今入ったスコア表示の点数
int vsuScoreFrame[2];			// 今入ったスコア表示の残り時間

int vsuCPUFlag[2] = {0, 1};		// CPUが操作するかどうか
int vsuCPUSpeed[2] = {0, 5};	// CPUの遅さ
int vsuGhost = 1;				// ゴーストの設定
int vsuTSpin = 3;				// T-SPINの種類
int vsuEnableCombo = 1;			// コンボボーナスの有無
int vsuEnableB2B = 1;			// Back To Backの有無（0=なし 1=通常 2=ヘボリスのみ 3=T-SPINのみ）
int vsuGameType = 0;			// 0=2分間ラインアタック 1=3分間スコアアタック

int vsuSpeed = 1;				// 落下速度
int vsuSpeedType = 0;			// スピードタイプ
int vsuWait1 = 25;				// ARE
int vsuWait2 = 40;				// ライン消去
int vsuWait3 = 30;				// 固定時間
int vsuWaitt = 16;				// 横溜め
int vsuWait4 = -1;				// 固定時間（接着後）
int vsuWait5 = -1;				// ARE（消去後）

// イベント発生
void vsuPluginEvent(int player, int event, int *param) {
	int i;
	
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != vsuModeNo)) return;
	
	if(event == 0) {
		vsuModeNo = addModePlugin("VS-ULTRA");	// モードを登録する
	} else if(event == 3) {
		if((player == 1) && (!playback)) vsuNextInit(param);	// 1PのNEXTを2Pにコピー
	} else if(event == 4) {
		vsuPlayerExecute(player);	// ゲーム処理前
	} else if(event == 8) {
		vsuSoftDropScore(player);	// ソフトドロップで入った点数を加算
	} else if(event == 12) {
		vsuCalcScore(player, param[0]);	// ライン消去
	} else if(event == 15) {
		vsuViewScore(player);	// スコア表示
	} else if(event == 17) {
		vsuSetting(player, param);	// 設定画面
	} else if(event == 18) {
		vsuPlayerInitial(player);	// 初期化
	} else if(event == 19) {
		vsuMoveInit(player);	// ブロック出現
	} else if(event == 20) {
		vsuGameOver(player, param);	// ゲームオーバー処理
	} else if(event == 21) {
		vsuResult(player, param);	// 結果表示
	} else if(event == 22) {
		vsuGameOver2(player, param);	// ゲームオーバー表示
	} else if(event == 28) {
		vsuIncrementTime(player);	// 時間を進める
	} else if(event == 38) {
		if(player == 0) PlayBGM();	// BGM再生
	} else if(event == 39) {
		vsuSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		vsuLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		if(player == 0) vsuLoadBGM();	// BGM読み込み
	} else if(event == 48) {
		vsuSoftDropOld(player);	// ソフトドロップ（旧）
	} else if(event == 49) {
		vsuHardDrop(player, param[1]);	// ハードドロップ
	} else if(event == 55) {
		vsuReplayDetail();	// リプレイ詳細
	} else if(event == 59) {
		vsuTSpinZero(player);	// ライン消しなしのT-SPIN
	} else if(event == 68) {
		vsuWin(player);	// 勝利
	} else if(event == 70) {
		vsuRetry(param);	// リトライ
	}
}

// 初期化
void vsuPlayerInitial(int player) {
	int i;
	
	debugLogMode("vsuPlayerInitial executed");
	
	// バージョン
	if(!playback) vsuVersion = vsuCVersion;
	
	backno = 20;	// 背景変更
	setFieldPosition(player, 2);	// フィールド位置設定
	bgmlv = 10;	// BGM番号設定
	
	if(!player) {
		// 1P
		blkshadow_direction[0] = 1;
	} else {
		// 2P
		blkshadow_direction[1] = 0;
		
		// 乱数種をコピー
		randseed[1] = randseed[0];
		firstseed[1] = firstseed[0];
	}
	
	vsuScore[player] = 0;
	vsuLines[player] = 0;
	vsuLimitTime[player] = 7200 + (vsuGameType * 3600);
	
	vsuTSpinFrame[player] = 0;
	vsuTSpinLine[player] = 0;
	vsuComboFrame[player] = 0;
	vsuB2BFrame[player] = 0;
	vsuTSpinWall[player] = 0;
	vsuScoreGet[player] = 0;
	vsuScoreFrame[player] = 0;
	
	cpu_flag[player] = vsuCPUFlag[player];
	cpu_speed[player] = vsuCPUSpeed[player];
	if(vsuGhost == 0) ghost[player] = 0;
	else ghost[player] = 1;
	tspin_type[player] = vsuTSpin;
	enable_combo[player] = vsuEnableCombo;
	b_to_b_type[player] = vsuEnableB2B;
	
	sp[player] = vsuSpeed;
	speedtype[player] = vsuSpeedType;
	wait1[player] = vsuWait1;
	wait2[player] = vsuWait2;
	wait3[player] = vsuWait3;
	waitt[player] = vsuWaitt;
	
	if(vsuVersion >= 1) wait4[player] = vsuWait4;
	else wait4[player] = -1;
	
	if(vsuVersion >= 2) wait5[player] = vsuWait5;
	else wait5[player] = -1;
	
	stat[player] = 3;
}

// 1PのNEXTを2Pにコピー
void vsuNextInit(int *param) {
	int i;
	param[0] = 1;
	for(i = 0; i < 1400; i++) nextb[i + 1400] = nextb[i];
}

// ゲーム処理前
void vsuPlayerExecute(int player) {
	// CPUの操作
	if((onRecord[player]) && (timeOn[player]) && (stat[player] == 4) && (cpu_best_x[player] != -3) && (!playback) && (cpu_flag[player]))
		cpu_setCtrl(player);
}

// ブロック出現
void vsuMoveInit(int player) {
	// CPUの置き場所を決める
	if(cpu_flag[player] && !playback) {
		if(!dhold[player]) {
			if(hold[player] == -1)
				cpu_setBestSpotWithHold(player, blk[player], getNextBlock(player, 0));
			else
				cpu_setBestSpotWithHold(player, blk[player], hold[player]);
		} else {
			cpu_setBestSpot(player, blk[player]);
		}
	}
}

// BGM読み込み
void vsuLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(10);
	}
}

// ライン消去
void vsuCalcScore(int player, int lines) {
	int bo, b2b, combopts, combogoal, points;
	
	// T-SPIN時
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		vsuTSpinFrame[player] = 60;
		vsuTSpinLine[player] = lines;
		vsuTSpinWall[player] = (last_command[player] == 4);
		
		if((lines == 1) && (vsuTSpinWall[player])) bo = 2;	// 壁蹴りありT-SPIN Single
		if((lines == 1) && (!vsuTSpinWall[player])) bo = 8;	// 壁蹴りなしT-SPIN Single
		if(lines == 2) bo = 12;	// T-SPIN Double
		if(lines == 3) bo = 16;	// T-SPIN Triple
	}
	// 普通のライン消し
	else {
		if(lines == 1) bo = 1;
		if(lines == 2) bo = 3;
		if(lines == 3) bo = 5;
		if(lines == 4) {
			vsuTSpinFrame[player] = 60;
			vsuTSpinLine[player] = lines;
			bo = 8;
		}
	}
	
	// B2Bボーナス（x 1.5）
	if((vsuEnableB2B != 0) && (b_to_b_count[player] >= 2)) {
		b2b = 1;
		vsuB2BFrame[player] = 60;
	} else {
		b2b = 0;
		vsuB2BFrame[player] = 0;
	}
	
	// コンボボーナス
	if((vsuEnableCombo != 0) && (combo[player] >= 2)) {
		combopts = (combo[player] - 1) * 50;
		
		if(combo[player] >= 12) combogoal = 5;
		else if(combo[player] >= 9) combogoal = 4;
		else if(combo[player] >= 7) combogoal = 3;
		else if(combo[player] >= 5) combogoal = 2;
		else if(combo[player] >= 3) combogoal = 1;
		else combogoal = 0;
		
		vsuComboFrame[player] = 60;
	} else {
		combopts = 0;
		combogoal = 0;
	}
	
	// 全消しボーナス
	if(isBravo(player)) {
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		vsuScore[player] = vsuScore[player] + 5000;
	}
	
	// スコア加算
	points = bo * 100;
	vsuScore[player] = vsuScore[player] + points;
	if(b2b) vsuScore[player] = vsuScore[player] + (points / 2);
	vsuScore[player] = vsuScore[player] + combopts;
	
	vsuScoreGet[player] = points + ((points / 2) * (b2b)) + combopts;
	vsuScoreFrame[player] = 120;
	
	// ライン加算
	vsuLines[player] = vsuLines[player] + lines;
}

// ライン消しなしのT-SPIN
void vsuTSpinZero(int player) {
	PlaySE(se_tspin);
	vsuTSpinFrame[player] = 60;
	vsuTSpinLine[player] = 0;
	
	// 壁蹴りあり
	if(last_command[player] == 4) {
		vsuScore[player] = vsuScore[player] + 100;
		vsuTSpinWall[player] = 1;
		
		vsuScoreGet[player] = 100;
		vsuScoreFrame[player] = 120;
	}
	// 壁蹴りなし
	else {
		vsuScore[player] = vsuScore[player] + 400;
		vsuTSpinWall[player] = 0;
		
		vsuScoreGet[player] = 400;
		vsuScoreFrame[player] = 120;
	}
}

// ソフトドロップ（旧）
void vsuSoftDropOld(int player) {
	if((!down_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0) && (engineVer <= 12)) {
		if((speedtype[player] == 1) || (sp[player] < (softspeed[player] + 1) * 30)) {
			vsuScore[player]++;
		}
	}
}

// ハードドロップ
void vsuHardDrop(int player, int bottom) {
	if((!up_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0)) {
		vsuScore[player] = vsuScore[player] + (bottom - by[player]) * 2;
	}
}

// ソフトドロップで入った点数を加算
void vsuSoftDropScore(int player) {
	if(softd_score[player] > 0) {
		vsuScore[player] = vsuScore[player] + softd_score[player];
	}
}

// 時間を進める
void vsuIncrementTime(int player) {
	int temp[2];
	
	if(player == 0) {
		if(timeOn[player]) {
			// 制限時間減少
			vsuLimitTime[player]--;
			
			// 時間切れ
			if(vsuLimitTime[player] <= 0) {
				vsuLimitTime[player] = 0;
				timeOn[0] = 0;
				timeOn[1] = 0;
				onRecord[0] = 0;
				onRecord[1] = 0;
				
				if(!vsuGameType) {
					temp[0] = vsuLines[0];
					temp[1] = vsuLines[1];
				} else {
					temp[0] = vsuScore[0];
					temp[1] = vsuScore[1];
				}
				
				if(temp[0] == temp[1]) {
					stat[0] = 7;
					stat[1] = 7;
					resetStatc(0);
					resetStatc(1);
				} else if(temp[0] > temp[1]) {
					stat[1] = 7;
					resetStatc(1);
				} else if(temp[0] < temp[1]) {
					stat[0] = 7;
					resetStatc(0);
				}
			}
			// 残り10秒
			else if(vsuLimitTime[player] == 10 * 60) {
				PlaySE(se_hurryup);
			}
		}
	}
}

// スコア表示
void vsuViewScore(int player) {
	int color, color2, temp;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	if(vsuGameType) {
		// スコア
		printTinyFont(112 + player * 70, fyoffset[player] + 40, "SCORE");
		if(!player) sprintf(string[0], "%d", vsuScore[player]);
		else sprintf(string[0], "%8d", vsuScore[player]);
		printSMALLFont(112 + player * 48, fyoffset[player] + 48, string[0], color);
		
		// 今入った得点
		if(vsuScoreFrame[player] > 0) {
			vsuScoreFrame[player]--;
			if(!player) sprintf(string[0], "%d", vsuScoreGet[player]);
			else sprintf(string[0], "%8d", vsuScoreGet[player]);
			printSMALLFont(112 + player * 48, fyoffset[player] + 58, string[0], (count % 4 / 2) * (1 + (b_to_b_count[player] != 0)));
		}
	} else {
		// ライン
		printTinyFont(112 + player * 70, fyoffset[player] + 40, "LINES");
		if(!player) sprintf(string[0], "%d", vsuLines[player]);
		else sprintf(string[0], "%8d", vsuLines[player]);
		printSMALLFont(112 + player * 48, fyoffset[player] + 48, string[0], color);
	}
	
	// 残りタイム
	if(player == 0) {
		if((vsuLimitTime[player] <= 10 * 60) && (timeOn[player])) color2 = (count % 4 / 2) * 2;
		else color2 = color;
		getTime(vsuLimitTime[player]);
		printBIGFont(112, 216, string[0], color2);
	}
	
	if(vsuGameType) {
		// T-SPIN
		if(vsuTSpinFrame[player] > 0) {
			vsuTSpinFrame[player]--;
			
			if((vsuTSpinLine[player] == 0) && (vsuTSpinWall[player]))
				printTinyFont(foffset[player] + 25, fyoffset[player] + 208, "EZ T-SPIN");
			else if((vsuTSpinLine[player] == 0) && (!vsuTSpinWall[player]))
				printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "T-SPIN");
			else if((vsuTSpinLine[player] == 1) && (vsuTSpinWall[player]))
				printTinyFont(foffset[player] + 20, fyoffset[player] + 208, "T-SPIN MINI");
			else if((vsuTSpinLine[player] == 1) && (!vsuTSpinWall[player]))
				printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN SINGLE");
			else if(vsuTSpinLine[player] == 2)
				printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN DOUBLE");
			else if(vsuTSpinLine[player] == 3)
				printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN TRIPLE");
			else if(vsuTSpinLine[player] == 4)
				printTinyFont(foffset[player] + 30, fyoffset[player] + 208, "HEBORIS");
		}
		
		// BACK TO BACK
		if(vsuB2BFrame[player] > 0) {
			vsuB2BFrame[player]--;
			printTinyFont(foffset[player] + 18, fyoffset[player] + 200, "BACK TO BACK");
		}
		// COMBO
		else if((vsuComboFrame[player] > 0) && (combo[player] >= 2)) {
			vsuComboFrame[player]--;
			sprintf(string[0], "COMBO %d", combo[player] - 1);
			printTinyFont(foffset[player] + 30, fyoffset[player] + 200, string[0]);
		}
	}
}

// ゲームオーバー処理
void vsuGameOver(int player, int *param) {
	int i, drawflag;
	
	param[0] = 1;
	
	// 引き分けフラグ
	if(stat[1 - player] == 7) drawflag = 1;
	else drawflag = 0;
	
	// 最初のフレームの処理
	if(statc[player * 10] == 0) {
		StopAllBGM();
		StopSE(se_hurryup);
		disp_blkline[player] = 0;
		onRecord[0] = 0;
		onRecord[1] = 0;
		timeOn[0] = 0;
		timeOn[1] = 0;
		pinch[0] = 0;
		pinch[1] = 0;
		
		if(!drawflag) {
			stat[1 - player] = 2;
			resetStatc(1 - player);
		}
	}
	
	// LOSEロゴ
	statc[player * 10 + 1]++;
	statc[player * 10 + 2] = statc[player * 10 + 2] + statc[player * 10 + 1] / 4;
	
	if(statc[player * 10 + 2] > 140) {
		statc[player * 10 + 2] = 140;
		statc[player * 10 + 1] = -20;
	}
	
	ExBltRect(sg_spr, foffset[player] + 8, statc[player * 10 + 2], 184, 24 * (drawflag + 1), 79, 23);
	
	statc[player * 10]++;
	
	// ボタンでスキップ
	if(getPushState(player, 4) && (statc[player * 10] >= 60)) {
		statc[player * 10] = 300;
	}
	// 次の画面へ
	if(statc[player * 10] >= 300) {
		stat[0] = 8;
		stat[1] = 8;
		resetStatc(0);
		resetStatc(1);
		resetField(0);
		resetField(1);
	}
}

// 勝利
void vsuWin(int player) {
	int i;
	
	// 花火
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 3] < 10)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 3]++;
	}
	
	// WINロゴ
	statc[player * 10 + 1]++;
	statc[player * 10 + 2] = statc[player * 10 + 2] + statc[player * 10 + 1] / 4;
	
	if(statc[player * 10 + 2] > 140) {
		statc[player * 10 + 2] = 140;
		statc[player * 10 + 1] = -20;
	}
	
	ExBltRect(sg_spr, foffset[player] + 9, statc[player * 10 + 2], 184, 0, 79, 23);
	
	statc[player * 10]++;
	
	// ボタンでスキップ
	if(getPushState(player, 4) && (statc[player * 10] >= 60)) {
		statc[player * 10] = 300;
	}
	// 次の画面へ
	if(statc[player * 10] >= 300) {
		stat[0] = 8;
		stat[1] = 8;
		resetStatc(0);
		resetStatc(1);
		resetField(0);
		resetField(1);
	}
}

// 結果表示
void vsuResult(int player, int *param) {
	param[0] = 1;
	
	// 結果
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "SCORE");
	sprintf(string[0], "%13d", vsuScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LINES");
	sprintf(string[0], "%13d", vsuLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "TIME");
	getTime(gameTimer[0]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[1], 0);
	
	// カウンタ増加
	statc[player * 10]++;
	
	// BGM再生
	if(player == 0) {
		if(statc[player * 10] == 1) {
			if((bgmtype != 0) && (!fast)) {
				bgmlv = 13;
				if(!enable_sysbgm) loadBGM(13);
				PlayBGM();
			}
		}
	}
	
	// ボタンでスキップ
	if(getPushState(player, 4)) {
		statc[player * 10] = 500;
	}
	
	// 次の画面へ
	if(statc[player * 10] >= 500) {
		stat[0] = 9;
		stat[1] = 9;
		resetStatc(0);
		resetStatc(1);
	}
}

// ゲームオーバー表示
void vsuGameOver2(int player, int *param) {
	int i, param;
	
	param[0] = 1;
	
	// カウンタ増加
	statc[player * 10]++;
	
	// ゲームオーバー音
	if(player == 0) {
		if(statc[player * 10] == 1) {
			PlaySE(se_gameover);
			StopAllBGM();
		}
	}
	
	// GAME OVER
	ExBltRect(sg_gametext, foffset[player] - 2, 95, 0, 0, 100, 50);
	
	// ボタンでスキップ
	if(getPushState(player, 4)) {
		statc[player * 10] = 480;
	}
	
	// 終了
	if(statc[player * 10] >= 480) {
		if(playback && replayauto) {
			stat[0] = 0;
			stat[1] = 0;
		} else {
			stat[0] = 11;
			stat[1] = 11;
		}
		resetStatc(0);
		resetStatc(1);
	}
}

// リトライ
void vsuRetry(int *param) {
	param[0] = 1;
	
	gameAllInit();
	
	playerInitial(0);
	versusInit(0);
	
	playerInitial(1);
	versusInit(1);
}

// 設定画面
void vsuSetting(int player, int *param) {
	int i, j, k, cursor, move, param2p, page, max, crots;
	cursor = 0;
	move = 0;
	page = 0;
	crots = rots[0];
	
	maxPlay = 1;	// 2Pを有効にする
	
	vsuLoadConfig();	// 設定を読み込み
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		// 2Pルールセレクト
		if(page == 0) {
			printFontGrid(1, 1, "SELECT 2P ROTATION RULE", 1);
			
			// メニュー表示
			max = plugin_count_rule;
			if(max > 20) max = 20;
			j = 0;
			k = (crots / 20) * 20;
			
			for(i = 0; i < max; i++) {
				sprintf(string[0], "%03d:", k + i + 1);
				printFontGrid(2, 3 + j, string[0], 7 * (crots == k + i));
				printFontGrid(6, 3 + j, plugin_name_rule[k + i], 7 * (crots == k + i));
				if(crots == k + i) printFontGrid(1, 3 + j, "b", 7);
				j++;
			}
			
			// カーソル移動
			padRepeat2(1);
			
			// ↑
			if( (mpc2[1] == 1) || ((mpc2[1] > tame3) && (mpc2[1] % tame4 == 0)) || getPressState(1, 6) )
			if(getPressState(1, 0)) {
				PlaySE(se_move);
				crots--;
				if(crots < 0) crots = plugin_count_rule - 1;
			}
			
			// ↓
			if( (mpc2[1] == 1) || ((mpc2[1] > tame3) && (mpc2[1] % tame4 == 0)) || getPressState(1, 6) )
			if(getPressState(1, 1)) {
				PlaySE(se_move);
				crots++;
				if(crots > plugin_count_rule - 1) crots = 0;
			}
			
			// キャンセル
			if(getPushState(0, 5) || getPushState(1, 5)) {
				PlaySE(se_move);
				maxPlay = 0;
				param[0] = 0;
				return;
			}
			// 決定
			else if(getPushState(1, 4)) {
				if(plugin_count_rule > 0) {
					PlaySE(se_kettei);
					rots[1] = crots;
					
					param2p = 1;
					executePlugin(1, 16, &param2p);	// プラグイン呼び出し
					
					if(param2p) page++;
				}
			}
		}
		// モード設定
		else if(page == 1) {
			printFontGrid(1, 1, "VS-ULTRA", 4);
			
			// ルール名
			printFontGrid(2, 3, "1P RULE", 2);
			printFontGrid(22, 3, plugin_name_rule[rots[0]], 2);
			printFontGrid(2, 4, "2P RULE", 1);
			printFontGrid(22, 4, plugin_name_rule[rots[1]], 1);
			
			// 設定項目
			printFontGrid(1, 6, "GAME OPTIONS", 4);
			
			if(cursor <= 8) printFontGrid(1, 8 + cursor, "b", 7);
			
			printFontGrid( 2,  8, "1P CPU FLAG",  (cursor == 0) * 7);
			if(!vsuCPUFlag[0]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22,  8, string[0],      (cursor == 0) * 7);
			
			printFontGrid( 2,  9, "1P CPU SPEED", (cursor == 1) * 7);
			sprintf(string[0], "%d", vsuCPUSpeed[0]);
			printFontGrid(22,  9, string[0],      (cursor == 1) * 7);
			
			printFontGrid( 2, 10, "2P CPU FLAG",  (cursor == 2) * 7);
			if(!vsuCPUFlag[1]) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 10, string[0],      (cursor == 2) * 7);
			
			printFontGrid( 2, 11, "2P CPU SPEED", (cursor == 3) * 7);
			sprintf(string[0], "%d", vsuCPUSpeed[1]);
			printFontGrid(22, 11, string[0],      (cursor == 3) * 7);
			
			printFontGrid( 2, 12, "GHOST BLOCK",  (cursor == 4) * 7);
			if(!vsuGhost) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 12, string[0],      (cursor == 4) * 7);
			
			printFontGrid( 2, 13, "T-SPIN",       (cursor == 5) * 7);
			if(vsuTSpin == 0) sprintf(string[0], "OFF");
			else if(vsuTSpin == 1) sprintf(string[0], "LINE CLEAR");
			else if(vsuTSpin == 2) sprintf(string[0], "IMMOBILE");
			else if(vsuTSpin == 3) sprintf(string[0], "3-CORNER");
			else sprintf(string[0], "3-CORNER NO KICK");
			printFontGrid(22, 13, string[0],      (cursor == 5) * 7);
			
			printFontGrid( 2, 14, "COMBO",        (cursor == 6) * 7);
			if(!vsuEnableCombo) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 14, string[0],      (cursor == 6) * 7);
			
			printFontGrid( 2, 15, "BACK TO BACK", (cursor == 7) * 7);
			if(vsuEnableB2B == 0) sprintf(string[0], "OFF");
			else if(vsuEnableB2B == 1) sprintf(string[0], "ON");
			else if(vsuEnableB2B == 2) sprintf(string[0], "HEBORIS ONLY");
			else sprintf(string[0], "T-SPIN ONLY");
			printFontGrid(22, 15, string[0],      (cursor == 7) * 7);
			
			printFontGrid( 2, 16, "GAME TYPE",    (cursor == 8) * 7);
			if(!vsuGameType) sprintf(string[0], "2MIN LINE MATCH");
			else sprintf(string[0], "3MIN SCORE MATCH");
			printFontGrid(22, 16, string[0],      (cursor == 8) * 7);
			
			printFontGrid(1, 18, "GAME SPEED", 4);
			
			if(cursor >= 9) printFontGrid(1, 20 + cursor - 9, "b", 7);
			
			printFontGrid( 2, 20, "SPEED", (cursor == 9) * 7);
			sprintf(string[0], "%d", vsuSpeed);
			printFontGrid(22, 20, string[0], (cursor == 9) * 7);
			
			printFontGrid( 2, 21, "SPEED TYPE", (cursor == 10) * 7);
			if(vsuSpeedType == 0) sprintf(string[0], "1/60");
			else if(vsuSpeedType == 1) sprintf(string[0], "FRAMES PER ROW");
			else sprintf(string[0], "1/256");
			printFontGrid(22, 21, string[0], (cursor == 10) * 7);
			
			if(!english) printFontGrid( 2, 22, "SYUTUGEN", (cursor == 11) * 7);
			else printFontGrid( 2, 22, "ARE", (cursor == 11) * 7);
			sprintf(string[0], "%d", vsuWait1);
			printFontGrid(22, 22, string[0], (cursor == 11) * 7);
			
			if(!english) printFontGrid( 2, 23, "SYOUKYO", (cursor == 12) * 7);
			else printFontGrid( 2, 23, "LINE DELAY", (cursor == 12) * 7);
			sprintf(string[0], "%d", vsuWait2);
			printFontGrid(22, 23, string[0], (cursor == 12) * 7);
			
			if(!english) printFontGrid( 2, 24, "SETTYAKU", (cursor == 13) * 7);
			else printFontGrid( 2, 24, "LOCK DELAY", (cursor == 13) * 7);
			sprintf(string[0], "%d", vsuWait3);
			printFontGrid(22, 24, string[0], (cursor == 13) * 7);
			
			if(!english) printFontGrid( 2, 25, "YOKOTAME", (cursor == 14) * 7);
			else printFontGrid( 2, 25, "DAS", (cursor == 14) * 7);
			sprintf(string[0], "%d", vsuWaitt);
			printFontGrid(22, 25, string[0], (cursor == 14) * 7);
			
			if(!english) printFontGrid( 2, 26, "SETTYAKU2", (cursor == 15) * 7);
			else printFontGrid( 2, 26, "LOCK DELAY2", (cursor == 15) * 7);
			if(vsuWait4 == -1) {
				if(!english) sprintf(string[0], "USE SETTYAKU");
				else sprintf(string[0], "USE LOCK DELAY");
			} else {
				sprintf(string[0], "%d", vsuWait4);
			}
			printFontGrid(22, 26, string[0], (cursor == 15) * 7);
			
			if(!english) printFontGrid( 2, 27, "SYUTUGEN2", (cursor == 16) * 7);
			else printFontGrid( 2, 27, "ARE2", (cursor == 16) * 7);
			if(vsuWait5 == -1) {
				if(!english) sprintf(string[0], "USE SYUTUGEN");
				else sprintf(string[0], "USE ARE");
			} else {
				sprintf(string[0], "%d", vsuWait5);
			}
			printFontGrid(22, 27, string[0], (cursor == 16) * 7);
			
			printFontGrid(1, 29, "A:START B:BACK", 6);
			
			// カーソル移動
			padRepeat2(player);
			
			move = 0;
			if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
				move = getPressState(player, 1) - getPressState(player, 0);
			
			if(move) {
				PlaySE(se_move);
				cursor = cursor + move;
				if(cursor < 0) cursor = 16;
				if(cursor > 16) cursor = 0;
			}
			
			// 値を変更
			padRepeat(player);
			
			move = 0;
			if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
				move = getPressState(player, 3) - getPressState(player, 2);
			
			if(move) {
				PlaySE(se_kachi);
				
				if(cursor == 0) vsuCPUFlag[0] = !vsuCPUFlag[0];
				if(cursor == 1) {
					vsuCPUSpeed[0] = vsuCPUSpeed[0] + move;
					if(vsuCPUSpeed[0] < 0) vsuCPUSpeed[0] = 60;
					if(vsuCPUSpeed[0] > 60) vsuCPUSpeed[0] = 0;
				}
				if(cursor == 2) vsuCPUFlag[1] = !vsuCPUFlag[1];
				if(cursor == 3) {
					vsuCPUSpeed[1] = vsuCPUSpeed[1] + move;
					if(vsuCPUSpeed[1] < 0) vsuCPUSpeed[1] = 60;
					if(vsuCPUSpeed[1] > 60) vsuCPUSpeed[1] = 0;
				}
				if(cursor == 4) vsuGhost = !vsuGhost;
				if(cursor == 5) {
					vsuTSpin = vsuTSpin + move;
					if(vsuTSpin < 0) vsuTSpin = 4;
					if(vsuTSpin > 4) vsuTSpin = 0;
				}
				if(cursor == 6) vsuEnableCombo = !vsuEnableCombo;
				if(cursor == 7) {
					vsuEnableB2B = vsuEnableB2B + move;
					if(vsuEnableB2B < 0) vsuEnableB2B = 3;
					if(vsuEnableB2B > 3) vsuEnableB2B = 0;
				}
				if(cursor == 8) vsuGameType = !vsuGameType;
				if(cursor == 9) {
					vsuSpeed = vsuSpeed + move;
					if(vsuSpeed < 0) vsuSpeed = 5120;
					if(vsuSpeed > 5120) vsuSpeed = 0;
				}
				if(cursor == 10) {
					vsuSpeedType = vsuSpeedType + move;
					if(vsuSpeedType < 0) vsuSpeedType = 2;
					if(vsuSpeedType > 2) vsuSpeedType = 0;
				}
				if(cursor == 11) {
					vsuWait1 = vsuWait1 + move;
					if(vsuWait1 < 0) vsuWait1 = 99;
					if(vsuWait1 > 99) vsuWait1 = 0;
				}
				if(cursor == 12) {
					vsuWait2 = vsuWait2 + move;
					if(vsuWait2 < 0) vsuWait2 = 99;
					if(vsuWait2 > 99) vsuWait2 = 0;
				}
				if(cursor == 13) {
					vsuWait3 = vsuWait3 + move;
					if(vsuWait3 < 0) vsuWait3 = 99;
					if(vsuWait3 > 99) vsuWait3 = 0;
				}
				if(cursor == 14) {
					vsuWaitt = vsuWaitt + move;
					if(vsuWaitt < 0) vsuWaitt = 99;
					if(vsuWaitt > 99) vsuWaitt = 0;
				}
				if(cursor == 15) {
					vsuWait4 = vsuWait4 + move;
					if(vsuWait4 < -1) vsuWait4 = 99;
					if(vsuWait4 > 99) vsuWait4 = -1;
				}
				if(cursor == 16) {
					vsuWait5 = vsuWait5 + move;
					if(vsuWait5 < -1) vsuWait5 = 99;
					if(vsuWait5 > 99) vsuWait5 = -1;
				}
			}
			
			// キャンセル
			if(getPushState(0, 5) || getPushState(1, 5)) {
				PlaySE(se_move);
				
				param2p = 1;
				executePlugin(1, 16, &param2p);	// プラグイン呼び出し
				
				if(!param2p) page--;
			}
			// 決定
			else if(getPushState(0, 4) || getPushState(1, 4)) {
				// 2Pのモードを1Pと同じにする
				gameMode[1] = gameMode[0];
				
				// 設定を保存
				vsuSaveConfig();
				
				// 開始
				return;
			}
		}
	}
}

// 設定を保存
void vsuSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// 設定内容
	saveBuf[1] = vsuCPUFlag[0];
	saveBuf[2] = vsuCPUFlag[1];
	saveBuf[3] = vsuCPUSpeed[0];
	saveBuf[4] = vsuCPUSpeed[1];
	saveBuf[5] = vsuGhost;
	saveBuf[6] = vsuTSpin;
	saveBuf[7] = vsuEnableCombo;
	saveBuf[8] = vsuEnableB2B;
	saveBuf[9] = vsuSpeed;
	saveBuf[10] = vsuSpeedType;
	saveBuf[11] = vsuWait1;
	saveBuf[12] = vsuWait2;
	saveBuf[13] = vsuWait3;
	saveBuf[14] = vsuWaitt;
	saveBuf[15] = vsuGameType;
	saveBuf[16] = vsuWait4;
	saveBuf[17] = vsuWait5;
	
	SaveFile("config/VS_ULTRA_CONFIG.SAV", &saveBuf, 50 * 4);
}

// 設定を読み込み
int vsuLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/VS_ULTRA_CONFIG.SAV", &saveBuf, 50 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// 設定内容
	vsuCPUFlag[0] = saveBuf[1];
	vsuCPUFlag[1] = saveBuf[2];
	vsuCPUSpeed[0] = saveBuf[3];
	vsuCPUSpeed[1] = saveBuf[4];
	vsuGhost = saveBuf[5];
	vsuTSpin = saveBuf[6];
	vsuEnableCombo = saveBuf[7];
	vsuEnableB2B = saveBuf[8];
	vsuSpeed = saveBuf[9];
	vsuSpeedType = saveBuf[10];
	vsuWait1 = saveBuf[11];
	vsuWait2 = saveBuf[12];
	vsuWait3 = saveBuf[13];
	vsuWaitt = saveBuf[14];
	vsuGameType = saveBuf[15];
	vsuWait4 = saveBuf[16];
	vsuWait5 = saveBuf[17];
	
	return 1;
}

// リプレイ保存
void vsuSaveReplay(int player) {
	saveBuf[900] = vsuGhost;
	saveBuf[901] = vsuTSpin;
	saveBuf[902] = vsuEnableCombo;
	saveBuf[903] = vsuEnableB2B;
	saveBuf[904] = vsuVersion;
	saveBuf[905] = vsuSpeed;
	saveBuf[906] = vsuSpeedType;
	saveBuf[907] = vsuWait1;
	saveBuf[908] = vsuWait2;
	saveBuf[909] = vsuWait3;
	saveBuf[910] = vsuWaitt;
	saveBuf[911] = vsuGameType;
	saveBuf[912] = vsuWait4;
	saveBuf[913] = vsuWait5;
}

// リプレイ読み込み
void vsuLoadReplay(int player) {
	maxPlay = 1;	// 2Pを有効にする
	
	vsuGhost = saveBuf[900];
	vsuTSpin = saveBuf[901];
	vsuEnableCombo = saveBuf[902];
	vsuEnableB2B = saveBuf[903];
	vsuVersion = saveBuf[904];
	vsuSpeed = saveBuf[905];
	vsuSpeedType = saveBuf[906];
	vsuWait1 = saveBuf[907];
	vsuWait2 = saveBuf[908];
	vsuWait3 = saveBuf[909];
	vsuWaitt = saveBuf[910];
	vsuGameType = saveBuf[911];
	vsuWait4 = saveBuf[912];
	vsuWait5 = saveBuf[913];
	
	vsuPlayerInitial(player);	// 設定を反映させるために初期化処理実行
}

// リプレイ詳細
void vsuReplayDetail() {
	printFontGrid(1, 5, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[904]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 7, "GHOST BLOCK", 0);
	if(!saveBuf[900]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 8, "T-SPIN", 0);
	if(saveBuf[901] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[901] == 1) sprintf(string[0], "LINE CLEAR");
	else if(saveBuf[901] == 2) sprintf(string[0], "IMMOBILE");
	else if(saveBuf[901] == 3) sprintf(string[0], "3-CORNER");
	else sprintf(string[0], "3-CORNER NO KICK");
	printFontGrid(22, 8, string[0], 0);
	
	printFontGrid(1, 9, "COMBO", 0);
	if(!saveBuf[902]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "BACK TO BACK", 0);
	if(saveBuf[903] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[903] == 1) sprintf(string[0], "ON");
	else if(saveBuf[903] == 2) sprintf(string[0], "HEBORIS ONLY");
	else sprintf(string[0], "T-SPIN ONLY");
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "GAME TYPE", 0);
	if(!saveBuf[911]) sprintf(string[0], "2MIN LINE MATCH");
	else sprintf(string[0], "3MIN SCORE MATCH");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 13, "SPEED", 0);
	sprintf(string[0], "%d", saveBuf[905]);
	printFontGrid(22, 13, string[0], 0);
	
	printFontGrid(1, 14, "SPEED TYPE", 0);
	if(saveBuf[906] == 0) sprintf(string[0], "1/60");
	else if(saveBuf[906] == 1) sprintf(string[0], "FRAMES PER ROW");
	else sprintf(string[0], "1/256");
	printFontGrid(22, 14, string[0], 0);
	
	if(!english) printFontGrid(1, 15, "SYUTUGEN", 0);
	else printFontGrid(1, 15, "ARE", 0);
	sprintf(string[0], "%d", saveBuf[907]);
	printFontGrid(22, 15, string[0], 0);
	
	if(!english) printFontGrid(1, 16, "SYOUKYO", 0);
	else printFontGrid(1, 16, "LINE DELAY", 0);
	sprintf(string[0], "%d", saveBuf[908]);
	printFontGrid(22, 16, string[0], 0);
	
	if(!english) printFontGrid(1, 17, "SETTYAKU", 0);
	else printFontGrid(1, 17, "LOCK DELAY", 0);
	sprintf(string[0], "%d", saveBuf[909]);
	printFontGrid(22, 17, string[0], 0);
	
	if(!english) printFontGrid(1, 18, "YOKOTAME", 0);
	else printFontGrid(1, 18, "DAS", 0);
	sprintf(string[0], "%d", saveBuf[910]);
	printFontGrid(22, 18, string[0], 0);
	
	if(!english) printFontGrid(1, 19, "SETTYAKU2", 0);
	else printFontGrid(1, 19, "LOCK DELAY2", 0);
	if((saveBuf[912] == -1) || (saveBuf[904] <= 0)) {
		if(!english) sprintf(string[0], "USE SETTYAKU");
		else sprintf(string[0], "USE LOCK DELAY");
	} else {
		sprintf(string[0], "%d", saveBuf[912]);
	}
	printFontGrid(22, 19, string[0], 0);
	
	if(!english) printFontGrid(1, 20, "SYUTUGEN2", 0);
	else printFontGrid(1, 20, "ARE2", 0);
	if((saveBuf[913] == -1) || (saveBuf[904] <= 1)) {
		if(!english) sprintf(string[0], "USE SYUTUGEN");
		else sprintf(string[0], "USE ARE");
	} else {
		sprintf(string[0], "%d", saveBuf[913]);
	}
	printFontGrid(22, 20, string[0], 0);
}
