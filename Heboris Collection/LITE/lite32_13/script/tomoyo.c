// TOMOYOモードでの部分的初期化処理
void tomoyoInitial(int player) {
	int i, sbak[18], skipbak[20], stbak[30];
	
	// 初期化されては困るものをバックアップにコピー
	sbak[0] = stage[player];			// ステージ
	sbak[1] = ltime[player];			// リミットタイム
	sbak[2] = nextc[player];			// NEXTカウント
	sbak[3] = next[player];				// NEXTブロック
	sbak[4] = gameTimer[player];				// タイム
	sbak[5] = clearnum[player];			// クリアステージ数
	sbak[6] = clearp[player];			// クリア率
	sbak[7] = time2[player];			// リプレイ用タイム
	sbak[8] = onRecord[player];			// リプレイ記録中フラグ
	sbak[9] = laststage[player];		// 最終ステージ
	sbak[10] = timeattack[player];		// ランダムモード
	sbak[11] = start_stage[player];		// 開始ステージ
	sbak[12] = repversw;				// リプレイバージョン
	sbak[13] = stage_skip_used[player];	// ステージスキップを使った回数
	sbak[14] = onRecord[player];		// リプレイ記録中フラグ
	sbak[15] = nextb_max[player];		// NEXTのループ間隔
	sbak[16] = ready_count[player];		// READY→GO表示回数
	sbak[17] = start_nextc[player];		// スタート時のnextc
	
	// ステージスキップを使ったフレームをバックアップにコピー
	for(i = 0; i < 20; i++) {
		skipbak[i] = stage_skip_frame[i + player * 20];
	}
	
	// セクションタイムをバックアップにコピー
	for(i = 0; i < 30; i++) {
		stbak[i] = now_sttime[i + player * 30];
	}
	
	// 初期化
	playerInitial(player);
	
	// 初期化されては困るものをバックアップから戻す
	stage[player]     = sbak[0];		// ステージ
	ltime[player]     = sbak[1];		// リミットタイム
	nextc[player]     = sbak[2];		// NEXTカウント
	next[player]      = sbak[3];		// NEXTブロック
	gameTimer[player]      = sbak[4];		// タイム
	clearnum[player]  = sbak[5];		// クリアステージ数
	clearp[player]    = sbak[6];		// クリア率
	time2[player]     = sbak[7];		// リプレイ用タイム
	onRecord[player]  = sbak[8];		// リプレイ記録中フラグ
	laststage[player] = sbak[9];		// 最終ステージ
	timeattack[player] = sbak[10];		// ランダムモード
	start_stage[player] = sbak[11];		// 開始ステージ
	repversw          = sbak[12];		// リプレイバージョン
	stage_skip_used[player] = sbak[13];	// ステージスキップを使ったフレーム
	onRecord[player]  = sbak[14];		// リプレイ記録中フラグ
	nextb_max[player] = sbak[15];		// NEXTのループ間隔
	ready_count[player] = sbak[16];		// READY→GO表示回数
	start_nextc[player] = sbak[17];		// スタート時のnextc
	
	// ステージスキップを使ったフレームをバックアップから戻す
	for(i = 0; i < 20; i++) {
		stage_skip_frame[i + player * 20] = skipbak[i];
	}
	
	// セクションタイムをバックアップから戻す
	for(i = 0; i < 30; i++) {
		now_sttime[i + player * 30] = stbak[i];
	}
	
	// 初期スピード値と初期wait値読み込み
	setStartLevel(player);
	
	// NEXTブロックの色を設定
	setNextBlockColors(player, 1);
}

// フィールド内に残っているプラチナブロックの数を数える
int getPlatinumBlock(int player) {
	int i, j, result;
	result = 0;
	
	for(i = 0; i < 10; i++)
		for(j = 0; j < 22; j++) {
			if(fld[i + j * 10 + player * 220] >= 11) {
				result++;
			}
		}
	
	// せりあがりがONなら、まだせり上がっていない部分もカウント
	if(tomoyo_rise[player]) {
		for(i = 0; i < 10; i++)
			for(j = upLineNo[player]; j <= 20; j++) {
				if(tomoyo_rise_fld[i + j * 10 + player * 200] >= 11)
					result++;
			}
	}
	
	return result;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ステータスNo.18 - TOMOYOモード ステージクリア／タイムオーバー
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statTomoyoNextStage(int player) {
	int i;
	int ext;
	int ltime_s;		// リミットタイム増加アニメ用
	
	// カウンタ増加
	statc[player * 10]++;
	
	// リミットタイム増加量を決める
	ext = 0;
	
	if(tomoyo_timebonus[player]) {
		if( (sclear[player]) && (sectionTimer[player] < 10 * 60) ) {
			ext = 10;
		} else if( (sclear[player]) && (sectionTimer[player] < 20 * 60) ) {
			ext = 5;
		}
	}
	
	isxray[player] = 0;		// X-RAYを止める
	iscolor[player] = 0;	// COLORを止める
	isblind[player] = 0;	// BLINDを止める
	
	// STAGE XX
	printFont(boffset[player] + 1, 6, "STAGE", 4);
	
	if(gameMode[player] == 6) {
		getTomoyoStageNo(stage[player], 0, 1);
	} else {
		sprintf(string[0], "%2d", stage[player] + 1);
	}
	
	printFont(boffset[player] + 7, 6, string[0], 0);
	
	// CLEAR/TIME OVER
	if(sclear[player]) {
		printFont(boffset[player] + 2, 8, "CLEAR", 0);
	} else if(stime[player] <= 0) {
		printFont(boffset[player] + 1, 8, "TIME UP!", 0);
		printFont(boffset[player] + 1, 9, "TRY NEXT", 0);
	} else {
		printFont(boffset[player] + 2, 8, "SKIPED", 0);
	}
	
	if(gameMode[player] == 6) {
		// LIMIT TIME
		if(ext_s[player] < (ext * 60)) {
			ext_s[player] = ext_s[player] + 4;
		}
		if((timeextend_snd_cnt[player] < ext) && ((statc[player * 10] - 1) % 15 == 0)) {
			PlaySE(41);
			timeextend_snd_cnt[player]++;
		}
		ltime_s = ltime[player] + ext_s[player];
		
		printFont(boffset[player], 10, "LIMIT TIME", 3);
		getTime(ltime_s);
		printFont(boffset[player], 11, string[0], ((count % 4 / 2) * digitc[rots[player]])*(ext != 0));
	}
	
	if(gameMode[player] == 15) {
		if(!timeattack[player]) {
			// TOTAL TIME
			printFont(boffset[player], 10, "TOTAL TIME", 3);
			getTime(gameTimer[player]);
			printFont(boffset[player], 11, string[0], 0);
		} else {
			// LIMIT TIME
			printFont(boffset[player], 10, "LIMIT TIME", 3);
			getTime(ltime[player]);
			printFont(boffset[player], 11, string[0], 0);
		}
	}
	
	if(sclear[player]) {
		// 花火
		if( (statc[player * 10] % 10 == 0) && (endingcnt[player] < 10) ) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], 16 + Rand(20), 0, 0, Rand(7), 0);
			endingcnt[player]++;
		}
		
		if(gameMode[player] == 6) {
			// TIME EXTEND
			if(tomoyo_timebonus[player]) {
				printFont(boffset[player], 13, "TIMEEXTEND", 3);
				
				sprintf(string[0], "%2d", ext);
				printFont(boffset[player], 14, string[0], 0);
				printFont(boffset[player] + 3, 14, "SEC", 0);
			}
			// ERASE LINE
			else {
				printFont(boffset[player], 13, "ERASE LINE", 3);
				sprintf(string[0], "%d LINES", li[player]);
				printFont(boffset[player], 14, string[0], 0);
			}
		}
		
		// BONUS
		if(gameMode[player] == 15) {
			printFont(boffset[player], 13, "BONUS", 3);
			sprintf(string[0], "%d PTS", flash_bonus_points[player]);
			printFont(boffset[player], 14, string[0], 0);
		}
		
		// CLEAR TIME
		printFont(boffset[player], 16, "CLEAR TIME", 3);
		getTime(sectionTimer[player]);
		printFont(boffset[player], 17, string[0], 0);
		
		if((gameMode[player] == 6) && (stage[player] == 19))
			printFont(boffset[player], 19, "+1 MINUTES", 2);
	} else {
		// クリア率
		printFont(boffset[player], 13, "CLEAR PER.", 3);
		sprintf(string[0], "%d%%", (clearnum[player] * 100) / (stage[player] + 1));
		printFont(boffset[player] + 3, 14, string[0], 0);
	}
	
	StopWave(38);
	StopWave(39);
	
	// 次のステージ
	if( getPushState(player, 4) || (statc[player * 10] >= 300) ) {
		if(gameMode[player] == 15) {
			// FLASHモード
			sc[player] = sc[player] + flash_bonus_points[player];
			endingcnt[player] = 0;
			sectionTimer[player] = 0;
			
			// レベルダウン
			if(tc[player] > 100) {
				tc[player] = 100;
				tr[player] = 10;
			} else {
				tc[player] = tc[player] - 20;
				if(tc[player] < -1) tc[player] = -1;
				
				tr[player] = tr[player] - 2;
				if(tr[player] < 0) tr[player] = 0;
			}
			sp[player] = lvTabletomoyo[tr[player]];
			if(stat[1 - player] == 0) backno = tr[player] / 10;
			
			// コンティニュー使用フラグ解除
			flash_continue[player] = 0;
			
			// nextcを戻す
			nextc[player] = 0;
			next[player] = nextb[nextc[player] + player * 1400];
			setNextBlockColors(player, 1);
			
			if(stage[player] >= 99) {
				// ステージ100クリアでエンディング
				StopAllBGM();
				if(!IsPlayWave(29)) PlaySE(29);
				
				end_f[player] = 2;
				
				ending[player] = 1;
				stat[player] = 1;					// ブロックシャッター
				statc[player * 10] = 0;				// ステータスカウンタを0に
				statc[player * 10 + 1] = 14;		// シャッター後はステータスNo.14
			} else {
				// 次のステージ
				stat[player] = 1;					// ブロックシャッター
				statc[player * 10] = 0;				// ステータスカウンタを0に
				statc[player * 10 + 1] = 37;		// シャッター後はステータスNo.37
			}
		} else {
			// クリア率計算
			if(stage[player] <= 19) {
				clearp[player] = (clearnum[player] * 100) / (stage[player] + 1);
			}
			
			// 最終ステージを決定する
			if(start_stage[player] <= 26) {
				// STAGE1～EX7まで
				if(clearp[player] < 90) {
					laststage[player] = 19;			// クリア率が90%に満たない場合はステージ20で終了
				} else if(clearp[player] < 100) {
					laststage[player] = 22;			// クリア率が90～99%はEX3まで
				} else if(stage[player] == 19) {
					// クリア率が100%の場合はタイムで決める
					if(gameTimer[player] < 18000) {
						laststage[player] = 26;		// 5分以内なら最後まで
						
						// 流れ星
						objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
					} else {
						laststage[player] = 24;		// 5分超えている場合はEX5
					}
				}
			} else if(start_stage[player] <= 44) {
				// EHステージ
				laststage[player] = 44;
			} else if(start_stage[player] <= 71) {
				// ターゲット
				laststage[player] = 71;
			} else {
				// エディット
				laststage[player] = 999;
			}
			
			if(sclear[player]) {
				// リミットタイム増加
				ltime[player] = ltime[player] + (ext * 60);
				
				// 20面クリアで1分増加
				if(stage[player] == 19) ltime[player] = ltime[player] + (60 * 60);
				
				// セクションタイム記録
				if(stage[player] <= 26) {
					now_sttime[stage[player] + player * 30] = sectionTimer[player];
				} else if(stage[player] <= 44) {
					now_sttime[(stage[player] - 27) + player * 30] = sectionTimer[player];
				} else if(stage[player] <= 71) {
					now_sttime[(stage[player] - 45) + player * 30] = sectionTimer[player];
				}
			} else {
				// 失敗時のセクションタイム記録
				if(stage[player] <= 26) {
					now_sttime[stage[player] + player * 30] = -1 - (stime[player] > 0);
				} else if(stage[player] <= 44) {
					now_sttime[(stage[player] - 27) + player * 30] = -1 - (stime[player] > 0);
				} else if(stage[player] <= 71) {
					now_sttime[(stage[player] - 45) + player * 30] = -1 - (stime[player] > 0);
				}
			}
			
			// 次のステージへ
			stage[player]++;
			
			// 背景を戻す
			if(stat[1 - player] == 0) backno = 0;
			
			// DUALギミック解除
			endTomoyoDualGimmick(player);
			
			// 初期化
			tomoyoInitial(player);
			
			if(stage[player] > laststage[player]) {
				// ラストステージクリアでエンディング
				StopAllBGM();						// BGM停止
				
				stage[player] = laststage[player];
				
				// リプレイ記録終了
				if(stage[player] != 44) onRecord[player] = 0;
				
				if(!IsPlayWave(29)) PlaySE(29);
				ending[player] = 1;
				stat[player] = 14;
				statc[player * 10] = 0;
				
				end_f[player] = 1 + (stage[player] >= 26);
			} else {
				stat[player] = 3;					// Ready
				statc[player * 10] = 0;				// ステータスカウンタを0に
				statc[player * 10 + 1] = 0;			// 
			}
		}
	}
}

// DUALギミック解除
void endTomoyoDualGimmick(int player) {
	int i;
	
	if(tomoyo_dual_enable[player]) {
		backno = 0;
		maxPlay = b_maxPlay;
		
		for(i = 0; i < 2; i++) {
			tomoyo_dual_enable[i] = 0;
			foffset[i] = b_foffset[i];
			boffset[i] = b_boffset[i];
		}
		
		playerInitial(1);
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ステータスNo.19 - TOMOYOモード コンティニュー
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statTomoyoContinue(int player) {
	int bak[6];
	
	// リプレイセーブ
	ReplaySaveCheck(player, 1);
	
	if(statc[player * 10 + 1]) {
		sprintf(string[0], "SAVED:  %02d", statc[player * 10 + 1]);
		printFont(boffset[player], 26, string[0], 5);
	}
	
	// カウンタ増加
	statc[player * 10]++;
	
	printFont(boffset[player] + 1, 9, "CONTINUE", 3);
	
	if(count % 60 > 10) {
		BltRect(49, foffset[player] - 2, 85, 100 * player, 50, 100, 65);
	}
	
	printFont(boffset[player] + 2, 23, "TIME", 6);
	sprintf(string[0], "%d", 10 - (statc[player * 10] / 60));
	printFont(boffset[player] + 7, 23, string[0], 0);
	
	// Aボタンでコンティニュー
	if( getPushState(player, 4) ) {
		PlaySE(10);
		StopAllBGM();	// BGM停止
		
		bak[0] = stage[player];			// ステージ番号をバックアップ
		bak[1] = stage_nextc[player];		// ステージ開始時のnextcをバックアップ
		bak[2] = timeattack[player];
		bak[3] = flash_continue[player];
		bak[4] = flash_cont_stage[player];
		bak[5] = flash_edit[player];
		
		playerInitial(player);			// 初期化
		
		stage[player] = bak[0];			// ステージ番号を復帰
		start_stage[player] = bak[0];	// スタート時のステージ番号を設定
		
		nextc[player] = bak[1];			// nextcを復帰
		start_nextc[player] = bak[1];	// スタート時のnextcを設定
		
		next[player] = nextb[bak[1] + player * 1400];
		setNextBlockColors(player, 1);
		
		timeattack[player] = bak[2];
		flash_continue[player] = bak[3];
		flash_cont_stage[player] = bak[4];
		flash_edit[player] = bak[5];
		
		setStartLevel(player);			// 開始スピード設定
		setstartBGM(player);			// 開始BGM設定
		
		stat[player] = 1;				// ブロックシャッター
		statc[player * 10 + 0] = 0;		// カウンタ初期化
		
		if(gameMode[player] == 15) {
			if(!flash_continue[player]) {
				stage[player]--;
				flash_cont_stage[player] = stage[player];
				flash_continue[player] = 1;
			} else {
				stage[player] = flash_cont_stage[player];
			}
			statc[player * 10 + 1] = 37;	// ステージセレクト
		} else {
			statc[player * 10 + 1] = 3;		// Ready
		}
		
		return;
	}
	
	// Bボタンで早くタイム減少
	if( getPushState(player, 5) ) {
		statc[player * 10] = statc[player * 10] + 60;
	}
	
	// 終了
	if(statc[player * 10] >= 10 * 60) {
		stat[player] = 13;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ステータスNo.20 - TOMOYOモード ステージエディタ
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// statc[player * 10]    ：カーソル位置
// statc[player * 10 + 1]：現在の画面（0=メインメニュー 1=設定画面）
void statTomoyoEditor(int player) {
	int i, j, color;
	
	color = (count % 4 / 2) * digitc[rots[player]];
	
	if(statc[player * 10 + 1] == 0) {
		// メニュー描画
		printFont(boffset[player], 6, "EDIT MENU", fontc[rots[player]]);
		
		printFont(boffset[player], 8, "STAGE", (statc[player * 10] == 0) * color);
		getTomoyoStageNo(stage[player], 0, 0);
		printFont(boffset[player] + 6, 8, string[0], (statc[player * 10] == 0) * color);
		
		printFont(boffset[player],  9, "MAIN FIELD", (statc[player * 10] == 1) * color);
		if(gameMode[player] == 6) {
			printFont(boffset[player], 10, "RISE FIELD", (statc[player * 10] == 2) * color);
			printFont(boffset[player], 11, "SETTING",    (statc[player * 10] == 3) * color);
		}
		printFont(boffset[player], 12, "LOAD",       (statc[player * 10] == 4) * color);
		printFont(boffset[player], 13, "SAVE",       (statc[player * 10] == 5) * color);
		
		// キー入力
		padRepeat(player);
		padRepeat2(player);
		
		// ↑
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
		if(getPressState(player, 0)) {
			PlaySE(5);
			statc[player * 10]--;
			if( (gameMode[player] == 15) && ((statc[player * 10] == 2) || (statc[player * 10] == 3)) )
				statc[player * 10] = 1;
			if(statc[player * 10] < 0) statc[player * 10] = 5;
		}
		
		// ↓
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
		if(getPressState(player, 1)) {
			PlaySE(5);
			statc[player * 10]++;
			if( (gameMode[player] == 15) && ((statc[player * 10] == 2) || (statc[player * 10] == 3)) )
				statc[player * 10] = 4;
			if(statc[player * 10] > 5) statc[player * 10] = 0;
		}
		
		// ←
		if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
		if(getPressState(player, 2)) {
			PlaySE(3);
			
			if(statc[player * 10] == 0) {
				stage[player]--;
				if(stage[player] < 0) stage[player] = 999;
				start_stage[player] = stage[player];
				loadTomoyoStage(player, stage[player], (gameMode[player] == 15) * 2);
			}
		}
		
		// →
		if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
		if(getPressState(player, 3)) {
			PlaySE(3);
			
			if(statc[player * 10] == 0) {
				stage[player]++;
				if(stage[player] > 999) stage[player] = 0;
				start_stage[player] = stage[player];
				loadTomoyoStage(player, stage[player], (gameMode[player] == 15) * 2);
			}
		}
		
		// Aボタン
		if(getPushState(player, 4)) {
			PlaySE(10);
			
			// STAGE
			if(statc[player * 10] == 0) {
				if(gameMode[player] == 6) {
					statc[player * 10] = 0;
					statc[player * 10 + 1] = 1;
				}
			}
			// MAIN/RISE FIELD
			if((statc[player * 10] == 1) || (statc[player * 10] == 2)) {
				if(statc[player * 10] == 2) tomoyo_rise_edit[player] = 1;
				
				stat[player] = 17;
				statc[0 + player * 10] = 20;	// 戻り先指定
				statc[1 + player * 10] = 0;
				statc[2 + player * 10] = 1;		// 配置不可フラグ設定
				statc[3 + player * 10] = 0;
				statc[4 + player * 10] = 1 + tomoyo_rise_edit[player];		// Y座標
			}
			// SETTING
			if(statc[player * 10] == 3) {
				statc[player * 10] = 0;
				statc[player * 10 + 1] = 1;
			}
			// LOAD
			if(statc[player * 10] == 4) {
				loadTomoyoStage(player, stage[player], (gameMode[player] == 15) * 2);
			}
			// SAVE
			if(statc[player * 10] == 5) {
				saveTomoyoStage(player, stage[player], (gameMode[player] == 15) * 2);
			}
			
			return;
		}
		
		// Bボタン
		if(getPushState(player, 5)) {
			stat[player] = 2;
			statc[player * 10] = 0;
			return;
		}
	} else {
		// 設定画面
		if(statc[player * 10] < 16) {
			printFont(boffset[player] - 1, 25, "kn  PAGE 1/2", 0);
			
			printFont(boffset[player], 5, "STAGE TIME", fontc[rots[player]]);
			getTime(stime[player]);
			printFont(boffset[player], 6, string[0], (statc[player * 10] == 0) * color);
			
			printFont(boffset[player], 7, "LIMIT TIME", fontc[rots[player]]);
			getTime(ltime[player]);
			printFont(boffset[player], 8, string[0], (statc[player * 10] == 1) * color);
			
			printFont(boffset[player], 9, "TIMEBONUS", fontc[rots[player]]);
			if(!tomoyo_timebonus[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 9, string[0], (statc[player * 10] == 2) * color);
			
			printFont(boffset[player], 10, "MIRROR", fontc[rots[player]]);
			if(!isfmirror[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 10, string[0], (statc[player * 10] == 3) * color);
			
			printFont(boffset[player], 11, "ROLL", fontc[rots[player]]);
			if(!rollroll_flag[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 11, string[0], (statc[player * 10] == 4) * color);
			
			printFont(boffset[player], 12, "DEATH", fontc[rots[player]]);
			if(!IsBig[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 12, string[0], (statc[player * 10] == 5) * color);
			
			printFont(boffset[player], 13, "X-RAY", fontc[rots[player]]);
			if(!xray_flag[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 13, string[0], (statc[player * 10] == 6) * color);
			
			printFont(boffset[player], 14, "COLOR", fontc[rots[player]]);
			if(!color_flag[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 14, string[0], (statc[player * 10] == 7) * color);
			
			printFont(boffset[player], 15, "BLIND", fontc[rots[player]]);
			if(!blind_flag[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 15, string[0], (statc[player * 10] == 8) * color);
			
			printFont(boffset[player], 16, "THUNDER", fontc[rots[player]]);
			if(!isthunder[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 16, string[0], (statc[player * 10] == 9) * color);
			
			printFont(boffset[player], 17, "HIDENEXT", fontc[rots[player]]);
			if(!hnext_flag[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 17, string[0], (statc[player * 10] == 10) * color);
			
			printFont(boffset[player], 18, "DUAL", fontc[rots[player]]);
			if(!tomoyo_dual[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 18, string[0], (statc[player * 10] == 11) * color);
			
			printFont(boffset[player], 19, "DEVIL500", fontc[rots[player]]);
			if(!tomoyo_waits[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 19, string[0], (statc[player * 10] == 12) * color);
			
			printFont(boffset[player], 20, "SPEED", fontc[rots[player]]);
			sprintf(string[0], "%d", min_speed[player]);
			printFont(boffset[player], 21, string[0], (statc[player * 10] == 13) * color);
			
			printFont(boffset[player], 22, "RISE INTER", fontc[rots[player]]);
			sprintf(string[0], "%d", tomoyo_rise[player]);
			printFont(boffset[player], 23, string[0], (statc[player * 10] == 14) * color);
			
			printFont(boffset[player], 24, "BGM", fontc[rots[player]]);
			sprintf(string[0], "%2d", tomoyo_bgm[player] + 1);
			printFont(boffset[player] + 8, 24, string[0], (statc[player * 10] == 15) * color);
		} else {
			printFont(boffset[player] - 1, 25, "kn  PAGE 2/2", 0);
			
			printFont(boffset[player], 5, "LTIMEOVER", fontc[rots[player]]);
			if(!tomoyo_ltime_over[player]) StrCpy(string[0], "e");
			else StrCpy(string[0], "c");
			printFont(boffset[player] + 9, 5, string[0], (statc[player * 10] == 16) * color);
		}
		
		// キー入力
		padRepeat(player);
		padRepeat2(player);
		
		// ↑
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
		if(getPressState(player, 0)) {
			PlaySE(5);
			statc[player * 10]--;
			if(statc[player * 10] < 0) statc[player * 10] = 16;
		}
		
		// ↓
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
		if(getPressState(player, 1)) {
			PlaySE(5);
			statc[player * 10]++;
			if(statc[player * 10] > 16) statc[player * 10] = 0;
		}
		
		// ←
		if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
		if(getPressState(player, 2)) {
			PlaySE(3);
			
			if(statc[player * 10] == 0) {
				stime[player] = stime[player] - 60;
				if(stime[player] < 0) stime[player] = 72000;
				tomoyo_no_stage_time[player] = (stime[player] == 0);
			}
			if(statc[player * 10] == 1) {
				ltime[player] = ltime[player] - 60;
				if(ltime[player] < 0) ltime[player] = 72000;
			}
			if(statc[player * 10] == 2) tomoyo_timebonus[player] = !tomoyo_timebonus[player];
			if(statc[player * 10] == 3) isfmirror[player] = !isfmirror[player];
			if(statc[player * 10] == 4) rollroll_flag[player] = !rollroll_flag[player];
			if(statc[player * 10] == 5) IsBig[player] = !IsBig[player];
			if(statc[player * 10] == 6) xray_flag[player] = !xray_flag[player];
			if(statc[player * 10] == 7) color_flag[player] = !color_flag[player];
			if(statc[player * 10] == 8) blind_flag[player] = !blind_flag[player];
			if(statc[player * 10] == 9) isthunder[player] = !isthunder[player];
			if(statc[player * 10] == 10) hnext_flag[player] = !hnext_flag[player];
			if(statc[player * 10] == 11) tomoyo_dual[player] = !tomoyo_dual[player];
			if(statc[player * 10] == 12) tomoyo_waits[player] = !tomoyo_waits[player];
			if(statc[player * 10] == 13) {
				min_speed[player]--;
				if(min_speed[player] < 0) min_speed[player] = 1200;
			}
			if(statc[player * 10] == 14) {
				tomoyo_rise[player]--;
				if(tomoyo_rise[player] < 0) tomoyo_rise[player] = 99;
			}
			if(statc[player * 10] == 15) {
				tomoyo_bgm[player]--;
				if(tomoyo_bgm[player] < 0) tomoyo_bgm[player] = 20;
			}
			if(statc[player * 10] == 16) tomoyo_ltime_over[player] = !tomoyo_ltime_over[player];
		}
		
		// →
		if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
		if(getPressState(player, 3)) {
			PlaySE(3);
			
			if(statc[player * 10] == 0) {
				stime[player] = stime[player] + 60;
				if(stime[player] > 72000) stime[player] = 0;
				tomoyo_no_stage_time[player] = (stime[player] == 0);
			}
			if(statc[player * 10] == 1) {
				ltime[player] = ltime[player] + 60;
				if(ltime[player] > 72000) ltime[player] = 0;
			}
			if(statc[player * 10] == 2) tomoyo_timebonus[player] = !tomoyo_timebonus[player];
			if(statc[player * 10] == 3) isfmirror[player] = !isfmirror[player];
			if(statc[player * 10] == 4) rollroll_flag[player] = !rollroll_flag[player];
			if(statc[player * 10] == 5) IsBig[player] = !IsBig[player];
			if(statc[player * 10] == 6) xray_flag[player] = !xray_flag[player];
			if(statc[player * 10] == 7) color_flag[player] = !color_flag[player];
			if(statc[player * 10] == 8) blind_flag[player] = !blind_flag[player];
			if(statc[player * 10] == 9) isthunder[player] = !isthunder[player];
			if(statc[player * 10] == 10) hnext_flag[player] = !hnext_flag[player];
			if(statc[player * 10] == 11) tomoyo_dual[player] = !tomoyo_dual[player];
			if(statc[player * 10] == 12) tomoyo_waits[player] = !tomoyo_waits[player];
			if(statc[player * 10] == 13) {
				min_speed[player]++;
				if(min_speed[player] > 1200) min_speed[player] = 0;
			}
			if(statc[player * 10] == 14) {
				tomoyo_rise[player]++;
				if(tomoyo_rise[player] > 99) tomoyo_rise[player] = 0;
			}
			if(statc[player * 10] == 15) {
				tomoyo_bgm[player]++;
				if(tomoyo_bgm[player] > 20) tomoyo_bgm[player] = 0;
			}
			if(statc[player * 10] == 16) tomoyo_ltime_over[player] = !tomoyo_ltime_over[player];
		}
		
		// A/Bボタン
		if(getPushState(player, 4) || getPushState(player, 5)) {
			if(getPushState(player, 4)) PlaySE(10);
			statc[player * 10] = 0;
			statc[player * 10 + 1] = 0;
			return;
		}
		
		// Dボタンで「リミットタイム3分」「タイムボーナスあり」に設定
		if(getPushState(player, 7)) {
			PlaySE(3);
			ltime[player] = 10800;
			tomoyo_timebonus[player] = 1;
		}
	}
}

// ステージ番号表示用
void getTomoyoStageNo(int stageno, int stringno, int type) {
	if((stageno >= 20) && (stageno <= 26)) {
		sprintf(string[stringno], "EX%d", stageno - 19);
	} else if((stageno >= 27) && (stageno <= 44)) {
		if(type == 0) {
			sprintf(string[stringno], "%d", stageno - 26);
		} else if(type == 1) {
			sprintf(string[stringno], "%2d", stageno - 26);
		} else if(type == 2) {
			sprintf(string[stringno], "%3d", stageno - 26);
		}
	} else if((stageno >= 45) && (stageno <= 71)) {
		if(type == 0) {
			sprintf(string[stringno], "%d", stageno - 44);
		} else if(type == 1) {
			sprintf(string[stringno], "%2d", stageno - 44);
		} else if(type == 2) {
			sprintf(string[stringno], "%3d", stageno - 44);
		}
	} else if(stageno >= 72) {
		if(type == 0) {
			sprintf(string[stringno], "%d", stageno - 71);
		} else if(type == 1) {
			sprintf(string[stringno], "%2d", stageno - 71);
		} else if(type == 2) {
			sprintf(string[stringno], "%3d", stageno - 71);
		}
	} else {
		if(type == 0) {
			sprintf(string[stringno], "%d", stageno + 1);
		} else if(type == 1) {
			sprintf(string[stringno], "%2d", stageno + 1);
		} else if(type == 2) {
			sprintf(string[stringno], "%3d", stageno + 1);
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ステータスNo.36 - FLASHモードステージセレクト（初回）
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statFlashSelectFirstStage(int player) {
	int color;
	
	if(!statc[player * 10]) {
		loadTomoyoStage(player, stage[player], 1 + flash_edit[player]);
		statc[player * 10] = 1;
	}
	
	color = (count % 4 / 2) * digitc[rots[player]];
	
	printFont(boffset[player], 6, "SELECT", fontc[rots[player]]);
	printFont(boffset[player] + 5, 7, "STAGE", fontc[rots[player]]);
	
	printFont(boffset[player] + 4, 10, "k", color);
	printFont(boffset[player] + 4, 14, "n", color);
	
	sprintf(string[0], "%d", stage[player] + 1);
	printFont(boffset[player] + 4, 12, string[0], color);
	
	printFont(boffset[player] + 2, 16, "BONUS", fontc[rots[player]]);
	sprintf(string[0], "%d", 1000 * ((stage[player] / 4) + 1));
	printFont(boffset[player] + 3, 17, string[0], 0);
	
	printFont(boffset[player], 19, "TIME LIMIT", fontc[rots[player]]);
	if(!timeattack[player]) sprintf(string[0], "<   OFF  >");
	else sprintf(string[0], "<   ON   >");
	printFont(boffset[player], 20, string[0], color);
	
	// キー入力
	padRepeat(player);
	padRepeat2(player);
	
	// ↑
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 0) ) {
		PlaySE(5);
		stage[player]--;
		if(stage[player] < 0) stage[player] = 89;
		statc[player * 10] = 0;
	}
	
	// ↓
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 1) ) {
		PlaySE(5);
		stage[player]++;
		if(stage[player] > 89) stage[player] = 0;
		statc[player * 10] = 0;
	}
	
	// ←→
	if(getPushState(player, 2) || getPushState(player, 3)) {
		PlaySE(3);
		timeattack[player] = !timeattack[player];
	}
	
	// Aボタン
	if( getPushState(player, 4) ) {
		PlaySE(10);
		
		start_stage[player] = stage[player];
		loadTomoyoStage(player, stage[player], 1 + flash_edit[player]);
		
		flash_bonus_points[player] = 1000 * ((stage[player] / 4) + 1);
		flash_bonus_count[player] = 0;
		
		stat[player] = 3;				// Ready
		statc[player * 10] = 0;
		return;
	}
	
	// Bボタン
	if( getPushState(player, 5) ) {
		stat[player] = 1;				// ブロックシャッター実行
		statc[player * 10] = 0;			// ステータスカウンタを0に
		statc[player * 10 + 1] = 2;		// シャッター後はステータスNo.2
		return;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ステータスNo.37 - FLASHモードステージセレクト（2回目以降）
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statFlashSelectNextStage(int player) {
	int color, max;
	
	if(!statc[player * 10]) {
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = stage[player] + 1 + (statc[player * 10 + 1] * 2);
		loadTomoyoStage(player, statc[player * 10 + 2], 1 + flash_edit[player]);
	}
	
	color = (count % 4 / 2) * digitc[rots[player]];
	
	printFont(boffset[player], 6, "SELECT", fontc[rots[player]]);
	printFont(boffset[player], 7, "NEXT STAGE", fontc[rots[player]]);
	
	printFont(boffset[player] + 1, 10 + statc[player * 10 + 1] * 2, "b", fontc[rots[player]]);
	
	// 次のステージ一覧
	max = 0;
	
	sprintf(string[0], "%d", stage[player] + 1 + 1);
	printFont(boffset[player] + 3, 10, string[0], (statc[player * 10 + 1] == 0) * color);
	
	if( ((stage[player] < 89) && (stage[player] + 3 < 90)) || ((stage[player] >= 89) && (stage[player] + 3 < 100)) ) {
		sprintf(string[0], "%d", stage[player] + 1 + 3);
		printFont(boffset[player] + 3, 12, string[0], (statc[player * 10 + 1] == 1) * color);
		max = 1;
	}
	
	if( ((stage[player] < 89) && (stage[player] + 5 < 90)) || ((stage[player] >= 89) && (stage[player] + 5 < 100)) ) {
		sprintf(string[0], "%d", stage[player] + 1 + 5);
		printFont(boffset[player] + 3, 14, string[0], (statc[player * 10 + 1] == 2) * color);
		max = 2;
	}
	
	if( ((stage[player] < 89) && (stage[player] + 7 < 90)) || ((stage[player] >= 89) && (stage[player] + 7 < 100)) ) {
		sprintf(string[0], "%d", stage[player] + 1 + 7);
		printFont(boffset[player] + 3, 16, string[0], (statc[player * 10 + 1] == 3) * color);
		max = 3;
	}
	
	// ボーナス
	printFont(boffset[player] + 2, 18, "BONUS", fontc[rots[player]]);
	sprintf(string[0], "%d", 1000 * ((stage[player] / 4) + 1));
	printFont(boffset[player] + 3, 19, string[0], 0);
	
	// 待ち時間
	statc[player * 10]++;
	printFont(boffset[player] + 1, 23, "TIME", 6);
	sprintf(string[0], "%d", 9 - (statc[player * 10] / 60));
	printFont(boffset[player] + 8, 23, string[0], 0);
	
	// キー入力
	padRepeat(player);
	padRepeat2(player);
	
	// ↑
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 0) ) {
		PlaySE(5);
		statc[player * 10 + 1]--;
		
		// カーソルのループ
		if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = max;
		
		statc[player * 10 + 2] = stage[player] + 1 + (statc[player * 10 + 1] * 2);
		
		loadTomoyoStage(player, statc[player * 10 + 2], 1 + flash_edit[player]);
	}
	
	// ↓
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 1) ) {
		PlaySE(5);
		statc[player * 10 + 1]++;
		
		// カーソルのループ
		if(statc[player * 10 + 1] > max) statc[player * 10 + 1] = 0;
		
		statc[player * 10 + 2] = stage[player] + 1 + (statc[player * 10 + 1] * 2);
		
		loadTomoyoStage(player, statc[player * 10 + 2], 1 + flash_edit[player]);
	}
	
	// Aボタン
	if(getPushState(player, 4) || (statc[player * 10] >= 600)) {
		PlaySE(10);
		
		stage[player] = statc[player * 10 + 2];
		loadTomoyoStage(player, stage[player], 1 + flash_edit[player]);
		
		flash_bonus_points[player] = 1000 * ((stage[player] / 4) + 1);
		flash_bonus_count[player] = 0;
		
		if(flash_continue[player]) start_stage[player] = stage[player];
		
		stat[player] = 3;				// Ready
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = 0;
		return;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  TOMOYOモード ステージ読み込み／保存
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// ファイルフォーマット (4byte単位)
//   0～  209 フィールドデータ（横10 * 縦21マス）
// 210        MIRROR
// 211        ROLL ROLL
// 212        DEATH BLOCK
// 213        X-RAY
// 214        COLOR
// 215        BLIND
// 216        落下速度下限
// 217        THUNDER
// 218～250   未使用（自由に使用可能）

// ステージデータをロード
void loadTomoyoStage(int player, int number, int kind) {
	int i;
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	if(kind == 0) sprintf(string[0], "stage/stage%02d.sav", number);
	else if(kind == 1) sprintf(string[0], "stage/flash%02d.sav", number);
	else sprintf(string[0], "stage/edit%02d.sav", number);
	LoadFile(string[0], &saveBuf, 250 * 4);
	
	for(i = 0; i < 10; i++) {
		fld[i + player * 220] = 0;
		fldt[i + player * 220] = 0;
		fldi[i + player * 220] = 0;
		fldo[i + player * 220] = 0;
		flds[i + player * 220] = 0;
	}
	
	// フィールド読み込み
	for(i = 0; i < 210; i++) {
		fld[(i + 10) + player * 220] = saveBuf[i];
		
		// 初期配置を見えるようにする
		fldt[(i + 10) + player * 220] = (fld[(i + 10) + player * 220] != 0) * -1;
		
		fldi[(i + 10) + player * 220] = 0;
		fldo[(i + 10) + player * 220] = 0;
		flds[(i + 10) + player * 220] = 0;
	}
	
	// RISE
	tomoyo_rise[player] = saveBuf[218];
	
	if(gameMode[player] == 6) {
		// MIRROR
		isfmirror[player] = saveBuf[210];
		
		// ROLL ROLL
		rollroll_flag[player] = saveBuf[211];
		
		// DEATH BLOCK
		IsBig[player] = saveBuf[212];
		BigMove[player] = 0;
		
		// X-RAY
		xray_flag[player] = saveBuf[213];
		
		// COLOR
		color_flag[player] = saveBuf[214];
		
		// BLIND
		blind_flag[player] = saveBuf[215];
		
		// MIN SP
		min_speed[player] = saveBuf[216];
		
		// THUNDER
		isthunder[player] = saveBuf[217];
		
		// HIDE NEXT
		hnext_flag[player] = saveBuf[219];
		
		// DEVIL500
		tomoyo_waits[player] = saveBuf[220];
		
		// ステージタイム
		stime[player] = saveBuf[221];
		tomoyo_no_stage_time[player] = (stime[player] == 0);
		
		// リミットタイム
		if(stage[player] == start_stage[player]) {
			ltime[player] = saveBuf[222];
		}
		
		// DUAL台
		tomoyo_dual[player] = saveBuf[223];
		
		// タイム延長
		tomoyo_timebonus[player] = saveBuf[224];
		
		// BGM
		tomoyo_bgm[player] = saveBuf[225];
		
		// リミットタイムが切れてもブロックを置くまではプレイ続行
		tomoyo_ltime_over[player] = saveBuf[226];
	}
	
	// せり上がる場合はせり上がりフィールドを読み込み
	if(tomoyo_rise[player]) {
		LoadFile(string[0], &saveBuf, 450 * 4);
		for(i = 0; i < 200; i++) tomoyo_rise_fld[i + 200 * player] = saveBuf[i + 250];
	} else {
		for(i = 0; i < 200; i++) tomoyo_rise_fld[i + 200 * player] = 0;
	}
}

// ステージデータをセーブ
void saveTomoyoStage(int player, int number, int kind) {
	int i;
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	// フィールドをセーブバッファにコピー
	for(i = 0; i < 210; i++) {
		saveBuf[i] = fld[(i + 10) + player * 220];
	}
	
	// MIRROR
	saveBuf[210] = isfmirror[player];
	
	// ROLL ROLL
	saveBuf[211] = rollroll_flag[player];
	
	// DEATH BLOCK
	saveBuf[212] = IsBig[player];
	
	// X-RAY
	saveBuf[213] = xray_flag[player];
	
	// COLOR
	saveBuf[214] = color_flag[player];
	
	// BLIND
	saveBuf[215] = blind_flag[player];
	
	// MIN SP
	saveBuf[216] = min_speed[player];
	
	// THUNDER
	saveBuf[217] = isthunder[player];
	
	// RISE
	saveBuf[218] = tomoyo_rise[player];
	
	// HIDE NEXT
	saveBuf[219] = hnext_flag[player];
	
	// DEVIL500(BOOST FIRE)
	saveBuf[220] = tomoyo_waits[player];
	
	// ステージタイム
	saveBuf[221] = stime[player];
	
	// リミットタイム
	saveBuf[222] = ltime[player];
	
	// DUAL台
	saveBuf[223] = tomoyo_dual[player];
	
	// タイム延長
	saveBuf[224] = tomoyo_timebonus[player];
	
	// BGM
	saveBuf[225] = tomoyo_bgm[player];
	
	// リミットタイムが切れてもブロックを置くまではプレイ続行
	saveBuf[226] = tomoyo_ltime_over[player];
	
	// せり上がりフィールド
	for(i = 0; i < 200; i++) saveBuf[i + 250] = tomoyo_rise_fld[i + 200 * player];
	
	// 保存する
	if(kind == 0) sprintf(string[0], "stage/stage%02d.sav", number);
	else if(kind == 1) sprintf(string[0], "stage/flash%02d.sav", number);
	else sprintf(string[0], "stage/edit%02d.sav", number);
	SaveFile(string[0], &saveBuf, 450 * 4);
}
