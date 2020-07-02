//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  全効果音停止
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void StopAllWaves() {
	int i;
	
	for(i = 0; i <= 59; i++) {
		StopWave(i);
		SetVolumeWave(i, sevolume);
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  全BGM停止
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void StopAllBGM() {
	int i;
	
	if(bgm == 4) {
		// MIDI
		StopMIDI();
		ReleaseMIDI();
	} else if(bgm >= 2) {
		// WAVE & MP3
		for(i = 60; i <= 80; i++) {
			StopWave(i);
			SetVolumeWave(i, bgmvolume);
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  音量設定
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void resetVolume() {
	int i;
	
	for(i = 0; i <= 59; i++) {
		SetVolumeWave(i, sevolume);
	}
	for(i = 60; i <= 80; i++) {
		SetVolumeWave(i, bgmvolume);
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  効果音再生（の予約）
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void PlaySE(int no) {
	if(no < 60) {
		se_play[no] = 1;
	}
}

// 予約された効果音を全て再生
void PlayAllSE() {
	int i;
	
	for(i = 0; i < 60; i++) {
		if(se_play[i]) {
			PlayWave(i);
			se_play[i] = 0;
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ゲーム開始時のBGMレベル設定
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void setstartBGM(int player) {
	bgmlv = 0;
	fadelv = 0;
	bgm_change = 0;
	
	if( ((gameMode[player] == 1) || (gameMode[player] == 2)) && (gradetype[player] == 2) ) {
		// MASTER-EASY & 20G-EASY
		while(1) {
			if(bgmfadestart[(7 + gameMode[player]) * 6 + bgmlv] < 0) {
				bgmlv++;
			} else {
				break;
			}
		}
	} else if(gameMode[player] == 4) {
		// VERSUS
		bgmlv = 10;
	} else if(gameMode[player] == 5) {
		// PRACTICE
		if(playback) bgmlv = start_bgmlv[player];
	} else if(gameMode[player] == 7) {
		// ACE
		bgmlv = ace_bgmlist[timeattack[player] * 3];
	} else if(gameMode[player] == 9) {
		// OLD STYLE
		bgmlv = 0;
	} else if((gameMode[player] == 10) || (gameMode[player] == 11)) {
		// HEBO+ / DEVIL-
		while(1) {
			if(bgmfadestart[(gameMode[player] - 6) * 6 + bgmlv] < 0) {
				bgmlv++;
			} else {
				break;
			}
		}
	} else if(gameMode[player] == 12) {
		// ACE200
		bgmlv = ace200_bgmlist[timeattack[player] * 3];
	} else if(gameMode[player] == 13) {
		// BEGINNER+
		while(1) {
			if(bgmfadestart[6 * 6 + bgmlv] < 0) {
				bgmlv++;
			} else {
				break;
			}
		}
	} else if(gameMode[player] == 14) {
		// FINAL
		bgmlv = final_bgm;
	} else if(gameMode[player] == 15) {
		// FLASH
		if(stage[player] < 30) bgmlv = flash_bgmlist[0];			//  0～ 30
		else if(stage[player] < 60) bgmlv = flash_bgmlist[1];		// 31～ 60
		else if(stage[player] < 90) bgmlv = flash_bgmlist[2];		// 61～ 90
		else bgmlv = flash_bgmlist[3];								// 91～100
	} else if(gameMode[player] == 16) {
		// EASYDEVIL
		while(1) {
			if(bgmfadestart[7 * 6 + bgmlv] < 0) {
				bgmlv++;
			} else {
				break;
			}
		}
	} else if(gameMode[player] == 17) {
		// STANDARD
		bgmlv = start_bgmlv[player];
	} else if(gameMode[player] == 18) {
		// MARATHON
		bgmlv = marathon_bgm[timeattack[player]];
	} else if(gameMode[player] <= 3) {
		// 通常
		while(1) {
			if(bgmfadestart[gameMode[player] * 6 + bgmlv] < 0) {
				bgmlv++;
			} else {
				break;
			}
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  BGMフェードアウトチェック
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void checkFadeout(int player) {
	int i;
	
	// 通常
	if(gameMode[player] <= 3) {
		if(gradetype[player] == 1) {
			// MASTER-HARD & 20G-HARD用
			checkMasterFadeout(player);
		} else if(gradetype[player] == 2) {
			// MASTER-EASY & 20G-EASY用
			if(tc[player] >= bgmfadestart[(7 + gameMode[player]) * 6 + bgmlv]) {
				fadelv = 1;
			}
		} else if(tc[player] >= bgmfadestart[gameMode[player] * 6 + bgmlv]) {
			fadelv = 1;
		}
	}
	
	// ACE #LITE25
	if(gameMode[player] == 7) {
		if(c_norm[player] >= ace_bgmfadestart[bgm_change + timeattack[player] * 4]) {
			fadelv = 1;
		}
	}
	
	// ACE200
	if(gameMode[player] == 12) {
		if(c_norm[player] >= ace200_bgmfadestart[bgm_change + timeattack[player] * 4]) {
			fadelv = 1;
		}
	}
	
	// HEBO+ / DEVIL-
	if((gameMode[player] == 10) || (gameMode[player] == 11)) {
		if(tc[player] >= bgmfadestart[(gameMode[player] - 6) * 6 + bgmlv]) {
			fadelv = 1;
		}
	}
	
	// BEGINNER+
	if(gameMode[player] == 13) {
		if(tc[player] >= bgmfadestart[6 * 6 + bgmlv]) {
			fadelv = 1;
		}
	}
	
	// EASYDEVIL
	if(gameMode[player] == 16) {
		if(tc[player] >= bgmfadestart[7 * 6 + bgmlv]) {
			fadelv = 1;
		}
	}
}

// MASTER-HARD用BGMフェードアウト判定
void checkMasterFadeout(int player) {
	int secinlv;
	secinlv = tc[player] - ((tc[player] / 100) * 100);		// レベルの下2桁
	
	if(fadelv == 0) {
		// 1曲目→2曲目の判定
		if((bgmlv == 0 + (gameMode[player] == 2)) && (tc[player] >= tc_20g[player])) {
			fadelv = 1;
		}
		
		// 2曲目→3曲目の判定
		if((bgmlv == 1 + (gameMode[player] == 2)) && (secinlv >= 85) && (tr[player] + 2 >= tr_20g[player] + 10)) {
			fadelv = 1;
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  BGMループ／BGMフェードアウト処理
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void bgmFadeout() {
	int i;
	
	// BGMループ処理
	if(bgm != 4) {
		for(i = 60; i <= 80; i++) {
			if(IsPlayWave(i) && (bgm_loop_start[i - 60] != -1) && (bgm_loop_end[i - 60] != -1) && (GetPosWave(i) >= bgm_loop_end[i - 60])) {
				StopWave(i);
				PlayWave2(i, bgm_loop_start[i - 60]);
			}
		}
	}
	
	// BGMフェードアウト処理
	if(fadelv != 0) {
		if(bgm == 4) {
			// MIDI
			if(fadelv != 10000) {
				StopMIDI();
				ReleaseMIDI();
				fadelv = 10000;
			}
		} else if(bgm >= 2) {
			// WAVE & MP3
			if(fadesetting == 0) {
				fadelv = 10000;
			} else {
				fadelv = fadelv + (fadelv < 10000) * fadesetting;
			}
			
			if(-fadelv <= bgmvolume) {
				for(i = 60; i <= 80; i++) {
					if(IsPlayWave(i)) {
						SetVolumeWave(i, -fadelv);
						
						if(fadelv >= 10000) {
							StopWave(i);
							if(bgm >= 5) ReleaseWave(i);
						}
					}
				}
			}
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  BGM切り替え
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void changeBGM() {
	if(demo) return;
	
	fadelv = 0;
	
	if(bgmlv >= 0) {
		if(bgm == 4) {
			// MIDI
			changeMIDIBGM();
		} else if(bgm >= 5) {
			// ONDEMAND
			ondemand_loadBGM();
		} else {
			// WAVE & MP3
			StopAllBGM();
			PlayWave(60 + bgmlv);
		}
	} else {
		StopAllBGM();
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  MIDI用BGM再生関数
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void changeMIDIBGM() {
	fadelv = 0;
	
	// 現在のBGMを停止
	StopMIDI();
	ReleaseMIDI();
	
	// ファイル名を決める
	StrCpy(string[0], music_file_name[bgmlv]);
	
	// 拡張子を決める
	StrCat(string[0], ".mid");
	
	// 読み込み
	LoadMIDI(string[0]);
	
	// ループON
	SetLoopModeMIDI(1);
	
	if(bgmlv == 6) SetLoopModeMIDI(sound_ending_loop);
	if(bgmlv == 7) SetLoopModeMIDI(sound_beginner_ending_loop);
	
	// 再生
	PlayMIDI();
}

// BGMを読み込み（ONDEMAND）
void ondemand_loadBGM() {
	int i;
	
	fadelv = 0;
	
	// 現在のBGMを停止
	for(i = 60; i <= 80; i++) {
		StopWave(i);
		ReleaseWave(i);
	}
	
	// ファイル名を決める
	StrCpy(string[0], music_file_name[bgmlv]);
	
	// 拡張子を決める
	if(bgm == 6) StrCat(string[0], ".mp3");
	else StrCat(string[0], ".wav");
	
	// 読み込み
	LoadWave(string[0], 60 + bgmlv);
	
	// ループON
	SetLoopModeWave(60 + bgmlv, 1);
	
	if(bgmlv == 6) SetLoopModeWave(60 + bgmlv, sound_ending_loop);
	if(bgmlv == 7) SetLoopModeWave(60 + bgmlv, sound_beginner_ending_loop);
	
	// ボリューム設定
	SetVolumeWave(60 + bgmlv, bgmvolume);
	
	// 再生
	PlayWave(60 + bgmlv);
}
