//������������������������������������������������������������������������������
//  �S���ʉ���~
//������������������������������������������������������������������������������
void StopAllWaves() {
	int i;
	
	for(i = 0; i <= 59; i++) {
		StopWave(i);
		SetVolumeWave(i, sevolume);
	}
}

//������������������������������������������������������������������������������
//  �SBGM��~
//������������������������������������������������������������������������������
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

//������������������������������������������������������������������������������
//  ���ʐݒ�
//������������������������������������������������������������������������������
void resetVolume() {
	int i;
	
	for(i = 0; i <= 59; i++) {
		SetVolumeWave(i, sevolume);
	}
	for(i = 60; i <= 80; i++) {
		SetVolumeWave(i, bgmvolume);
	}
}

//������������������������������������������������������������������������������
//  ���ʉ��Đ��i�̗\��j
//������������������������������������������������������������������������������
void PlaySE(int no) {
	if(no < 60) {
		se_play[no] = 1;
	}
}

// �\�񂳂ꂽ���ʉ���S�čĐ�
void PlayAllSE() {
	int i;
	
	for(i = 0; i < 60; i++) {
		if(se_play[i]) {
			PlayWave(i);
			se_play[i] = 0;
		}
	}
}

//������������������������������������������������������������������������������
//  �Q�[���J�n����BGM���x���ݒ�
//������������������������������������������������������������������������������
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
		if(stage[player] < 30) bgmlv = flash_bgmlist[0];			//  0�` 30
		else if(stage[player] < 60) bgmlv = flash_bgmlist[1];		// 31�` 60
		else if(stage[player] < 90) bgmlv = flash_bgmlist[2];		// 61�` 90
		else bgmlv = flash_bgmlist[3];								// 91�`100
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
		// �ʏ�
		while(1) {
			if(bgmfadestart[gameMode[player] * 6 + bgmlv] < 0) {
				bgmlv++;
			} else {
				break;
			}
		}
	}
}

//������������������������������������������������������������������������������
//  BGM�t�F�[�h�A�E�g�`�F�b�N
//������������������������������������������������������������������������������
void checkFadeout(int player) {
	int i;
	
	// �ʏ�
	if(gameMode[player] <= 3) {
		if(gradetype[player] == 1) {
			// MASTER-HARD & 20G-HARD�p
			checkMasterFadeout(player);
		} else if(gradetype[player] == 2) {
			// MASTER-EASY & 20G-EASY�p
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

// MASTER-HARD�pBGM�t�F�[�h�A�E�g����
void checkMasterFadeout(int player) {
	int secinlv;
	secinlv = tc[player] - ((tc[player] / 100) * 100);		// ���x���̉�2��
	
	if(fadelv == 0) {
		// 1�Ȗځ�2�Ȗڂ̔���
		if((bgmlv == 0 + (gameMode[player] == 2)) && (tc[player] >= tc_20g[player])) {
			fadelv = 1;
		}
		
		// 2�Ȗځ�3�Ȗڂ̔���
		if((bgmlv == 1 + (gameMode[player] == 2)) && (secinlv >= 85) && (tr[player] + 2 >= tr_20g[player] + 10)) {
			fadelv = 1;
		}
	}
}

//������������������������������������������������������������������������������
//  BGM���[�v�^BGM�t�F�[�h�A�E�g����
//������������������������������������������������������������������������������
void bgmFadeout() {
	int i;
	
	// BGM���[�v����
	if(bgm != 4) {
		for(i = 60; i <= 80; i++) {
			if(IsPlayWave(i) && (bgm_loop_start[i - 60] != -1) && (bgm_loop_end[i - 60] != -1) && (GetPosWave(i) >= bgm_loop_end[i - 60])) {
				StopWave(i);
				PlayWave2(i, bgm_loop_start[i - 60]);
			}
		}
	}
	
	// BGM�t�F�[�h�A�E�g����
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

//������������������������������������������������������������������������������
//  BGM�؂�ւ�
//������������������������������������������������������������������������������
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

//������������������������������������������������������������������������������
//  MIDI�pBGM�Đ��֐�
//������������������������������������������������������������������������������
void changeMIDIBGM() {
	fadelv = 0;
	
	// ���݂�BGM���~
	StopMIDI();
	ReleaseMIDI();
	
	// �t�@�C���������߂�
	StrCpy(string[0], music_file_name[bgmlv]);
	
	// �g���q�����߂�
	StrCat(string[0], ".mid");
	
	// �ǂݍ���
	LoadMIDI(string[0]);
	
	// ���[�vON
	SetLoopModeMIDI(1);
	
	if(bgmlv == 6) SetLoopModeMIDI(sound_ending_loop);
	if(bgmlv == 7) SetLoopModeMIDI(sound_beginner_ending_loop);
	
	// �Đ�
	PlayMIDI();
}

// BGM��ǂݍ��݁iONDEMAND�j
void ondemand_loadBGM() {
	int i;
	
	fadelv = 0;
	
	// ���݂�BGM���~
	for(i = 60; i <= 80; i++) {
		StopWave(i);
		ReleaseWave(i);
	}
	
	// �t�@�C���������߂�
	StrCpy(string[0], music_file_name[bgmlv]);
	
	// �g���q�����߂�
	if(bgm == 6) StrCat(string[0], ".mp3");
	else StrCat(string[0], ".wav");
	
	// �ǂݍ���
	LoadWave(string[0], 60 + bgmlv);
	
	// ���[�vON
	SetLoopModeWave(60 + bgmlv, 1);
	
	if(bgmlv == 6) SetLoopModeWave(60 + bgmlv, sound_ending_loop);
	if(bgmlv == 7) SetLoopModeWave(60 + bgmlv, sound_beginner_ending_loop);
	
	// �{�����[���ݒ�
	SetVolumeWave(60 + bgmlv, bgmvolume);
	
	// �Đ�
	PlayWave(60 + bgmlv);
}
