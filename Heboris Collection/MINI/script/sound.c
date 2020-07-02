//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  効果音再生（の予約）
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// 再生の予約
void PlaySE(int no) {
	if(no < sound_count) se_play[no] = 1;
}

// 停止の予約
void StopSE(int no) {
	if(no < sound_count) se_play[no] = 2;
}

// 予約された効果音を全て再生／停止
void PlayAllSE() {
	int i;
	
	for(i = 0; i < sound_count; i++) {
		if(se_play[i] == 1) {
			PlayWave(i);
			se_play[i] = 0;
		} else if(se_play[i] == 2) {
			StopWave(i);
			se_play[i] = 0;
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  音量をリセット
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void resetSoundVolume() {
	int i;
	
	for(i = 0; i < sound_count; i++) {
		if((sound_plane_type[i] == 1) || (sound_plane_type[i] == 3))
			SetVolumeWave(i, sevolume);
		else if((sound_plane_type[i] == 2) || (sound_plane_type[i] == 4))
			SetVolumeWave(i, bgmvolume);
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  サウンドを停止
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// 全て停止
void StopAllWave() {
	int i;
	if(bgmtype == 3) StopMIDI();
	for(i = 0; i < sound_count; i++) StopWave(i);
}

// 効果音だけ停止
void StopAllSE() {
	int i;
	
	for(i = 0; i < sound_count; i++) {
		if((sound_plane_type[i] == 1) || (sound_plane_type[i] == 3)) StopSE(i);
	}
}

// 音楽だけ停止
void StopAllBGM() {
	int i;
	
	if(bgmtype == 3) {
		StopMIDI();
	} else {
		for(i = 0; i < sound_count; i++) {
			if((sound_plane_type[i] == 2) || (sound_plane_type[i] == 4)) StopWave(i);
		}
	}
}

// 音楽を全て解放
void ReleaseAllBGM() {
	int i;
	
	if(bgmtype == 3) {
		StopMIDI();
		ReleaseMIDI();
	} else {
		for(i = 0; i < sound_count; i++) {
			if((sound_plane_type[i] == 2) || (sound_plane_type[i] == 4)) {
				StopWave(i);
				
				if( (!enable_sysbgm) || ((i != bgm_plane[11]) && (i != bgm_plane[12]) && (i != bgm_plane[13])) ) {
					ReleaseWave(i);
				}
			}
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  BGMループ／BGMフェードアウト処理
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void bgmFadeout() {
	// BGMループ処理
	if(IsPlayWave(bgm_plane[bgmlv]) && (bgm_loop_start[bgmlv] != -1) && (bgm_loop_end[bgmlv] != -1) && (GetPosWave(bgm_plane[bgmlv]) >= bgm_loop_end[bgmlv]) && (bgmtype != 3))
	{
		StopWave(bgm_plane[bgmlv]);
		PlayWave2(bgm_plane[bgmlv], bgm_loop_start[bgmlv]);
	}
	
	// BGMフェードアウト処理
	if((fadelv != 0) && IsPlayWave(bgm_plane[bgmlv]) && (bgmtype != 3)) {
		if(fadesetting == 0) {
			fadelv = 10000;
		} else {
			fadelv = fadelv + (fadelv < 10000) * fadesetting;
		}
		
		if(-fadelv <= bgmvolume) {
			SetVolumeWave(bgm_plane[bgmlv], -fadelv);
			if(fadelv >= 10000) StopWave(bgm_plane[bgmlv]);
		}
	}
	
	// BGMフェードアウト処理(MIDI)
	if((fadelv != 0) && (bgmtype == 3)) {
		fadelv = 10000;
		StopMIDI();
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  BGM再生
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void PlayBGM() {
	if(bgmtype == 3) {
		// MIDI
		if(!IsPlayMIDI()) {
			StopMIDI();
			fadelv = 0;
			sprintf(string[13], "%s.mid", music_file_name[bgmlv]);
			LoadMIDI(string[13]);
			SetLoopModeMIDI(bgmlv);
			PlayMIDI();
		}
	} else if(bgmtype != 0) {
		// WAV, MP3
		if(!IsPlayWave(bgm_plane[bgmlv])) {
			StopAllBGM();
			fadelv = 0;
			if(bgmtype != 0) PlayWave(bgm_plane[bgmlv]);
		}
	}
}
