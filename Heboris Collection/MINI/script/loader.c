//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   各種読み込み関数
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲

// グラフィックファイルを読み込み（プレーン番号自動選択）
int loadGraphics(int type, str *filename) {
	if(graphics_count < 512) {
		if(type == 3) {
			sprintf(string[14], "プラグイン画像 %s を読み込み", filename);
			debugLogSystem(string[14]);
		}
		
		if((getDrawRate() >= 2) && (useHires)) {
			sprintf(string[14], "skin/%s/graphicshi/%s", skin_folder, filename);
		} else {
			sprintf(string[14], "skin/%s/graphics/%s", skin_folder, filename);
		}
		LoadBitmap(string[14], graphics_count, 0);
		graphics_plane_type[graphics_count] = type;
		graphics_count++;
		return graphics_count - 1;
	} else {
		return -1;
	}
}

// 背景画像ファイルを読み込み（プレーン番号自動選択）
int loadBackground(int type, str *filename) {
	if(graphics_count < 512) {
		if((getDrawRate() >= 2) && (useHires)) {
			sprintf(string[14], "skin/%s/backhi/%s", skin_folder, filename);
		} else {
			sprintf(string[14], "skin/%s/back/%s", skin_folder, filename);
		}
		LoadBitmap(string[14], graphics_count, 0);
		graphics_plane_type[graphics_count] = type;
		graphics_count++;
		return graphics_count - 1;
	} else {
		return -1;
	}
}

// サーフェイス作成（プレーン番号自動選択）
int createNewSurface(int type, int x, int y) {
	if(graphics_count < 512) {
		ExCreateSurface(graphics_count, x, y);
		graphics_plane_type[graphics_count] = type;
		graphics_count++;
		return graphics_count - 1;
	} else {
		return -1;
	}
}

// 効果音ファイルを読み込み（プレーン番号自動選択）
int loadSE(int type, str *filename) {
	if(sound_count < 512) {
		LoadWave(filename, sound_count);
		sound_plane_type[sound_count] = type;
		sound_count++;
		return sound_count - 1;
	} else {
		return -1;
	}
}

// BGMファイルのプレーン番号を予約（読み込みはしない）
int reserveBGMPlane() {
	if(sound_count < 512) {
		sound_plane_type[sound_count] = 2;
		sound_count++;
		return sound_count - 1;
	} else {
		return -1;
	}
}

// BGMを読み込み
void loadBGM(int number) {
	if(bgmtype == 0) return;
	if(bgmtype == 3) return;
	
	if(bgmtype == 1) {
		sprintf(string[13], "%s.wav", music_file_name[number]);
	} else if(bgmtype == 2) {
		sprintf(string[13], "%s.mp3", music_file_name[number]);
	}
	
	if(GetPosWave(bgm_plane[number]) == -1) {
		if(!english) sprintf(string[14], "BGMファイル %s を読み込み", string[13]);
		else sprintf(string[14], "Loading BGM file: %s", string[13]);
		debugLogSystem(string[14]);
		LoadWave(string[13], bgm_plane[number]);
	}
	SetVolumeWave(bgm_plane[number], bgmvolume);
	SetLoopModeWave(bgm_plane[number], bgm_auto_loop[number]);
}

// システムで使うグラフィックを読み込み
void loadSystemGraphics() {
	int i;
	
	// ブロック絵
	sg_blk_n = loadGraphics(1, "heboblk_normal.png");
	sg_blk_b = loadGraphics(1, "heboblk_big.png");
	sg_blk_s = loadGraphics(1, "heboblk_small.bmp");
	sg_iblk_n = loadGraphics(1, "heboblk_sp.png");
	sg_iblk_b = loadGraphics(1, "heboblk_sp_big.png");
	sg_iblk_s = loadGraphics(1, "heboblk_sp_small.bmp");
	
	// ブロックの影
	if(blockshadow) sg_blkshadow = loadGraphics(1, "heboblk_shadow.png");
	
	// ナビゲーションブロック
	sg_guide = loadGraphics(1, "guide.png");
	
	// フォント
	sg_font_n = loadGraphics(1, "hebofont.png");
	
	// フィールド画像
	sg_fld = loadGraphics(1, "hebofld.png");
	
	// 3Dフィールド画像
	sg_3d_fld[2] = loadGraphics(1, "fldmirror_2.png");
	sg_3d_fld[3] = loadGraphics(1, "fldmirror_3.png");
	sg_3d_fld[4] = loadGraphics(1, "fldmirror_4.png");
	sg_3d_fld[5] = loadGraphics(1, "fldmirror_5.png");
	
	// スプライト
	sg_spr = loadGraphics(1, "hebospr.png");
	
	// タイトル画像
	sprintf(string[0], "title_%d.png", Rand(4));
	sg_title = loadGraphics(1, string[0]);
	
	// メニューの背景
	sg_menu_back = loadGraphics(1, "menu_back.png");
	
	// 真っ黒画像と真っ白画像
	sg_black = loadGraphics(1, "heboflb0.bmp");
	sg_white = loadGraphics(1, "heboflb1.bmp");
	
	// スクリーンショット用サーフェイス
	sg_sssurface = createNewSurface(1, 320, 240);
	
	// 2倍拡大用サーフェイス
	if((screenMode >= 2) && (!useHires)) sg_2xwindow = createNewSurface(1, 640, 480);
	
	// ゲームで使う大きい文字
	sg_gametext = loadGraphics(1, "gametext.png");
	
	// ブロックの枠線
	sg_blkline = loadGraphics(1, "blkline.bmp");
	SetColorKeyRGB(sg_blkline, 0, 0, 0);
	
	// 小さいフォント
	sg_smallfont = loadGraphics(1, "smallfont.bmp");
	
	// 画面上部の枠
	sg_topframe = loadGraphics(1, "topframe.png");
	EnableBlendColorKey(sg_topframe, 1);
	
	// ライン消去エフェクト
	if(breaktype == 2) {
		for(i = 0; i < 8; i++) {
			sprintf(string[0], "break%d.png", i);
			sg_break[i] = loadGraphics(1, string[0]);
		}
	}
	
	// プラチナブロック消去エフェクト
	for(i = 0; i < 7; i++) {
		sprintf(string[0], "perase%d.png", i);
		sg_perase[i] = loadGraphics(1, string[0]);
	}
	
	// アイテム消去エフェクト
	sg_itemerase = loadGraphics(1, "itemerase.png");
	
	// メダル
	sg_medal[0] = loadGraphics(1, "medal1.png");
	sg_medal[1] = loadGraphics(1, "medal2.png");
	
	// 流れ星
	sg_shootingstar = loadGraphics(1, "shootingstar.png");
	
	// 花火
	for(i = 0; i < 7; i++) {
		sprintf(string[0], "hanabi%d.png", i);
		sg_hanabi[i] = loadGraphics(1, string[0]);
	}
	
	// 数字フォント（大・小）
	sg_numberfont = loadGraphics(1, "hebofont3.png");
	
	// アルファベットフォント（小文字使用可能）
	sg_alphabetfont = loadGraphics(1, "hebofont4.png");
	
	// 背景フェード
	sg_bgfade = loadGraphics(1, "fade.bmp");
	SetColorKeyRGB(sg_bgfade, 255, 255, 255);
	
	// スタッフロール
	sg_staffroll[0] = loadGraphics(1, "staffroll.png");
	sg_staffroll[1] = loadGraphics(1, "staffroll2.png");
	
	// 段位
	sg_grade = loadGraphics(1, "grade.png");
	
	// アイテムの名前
	sg_itemname = loadGraphics(1, "itemname.bmp");
	SetColorKeyRGB(sg_itemname, 255, 0, 255);
	
	// ランキング画面の線
	sg_line = loadGraphics(1, "line.bmp");
}

// 背景画像を読み込み
void loadSystemBackground() {
	int i, k, player, tmptr, tr, tr2;
	int maxpl, dx, dy, movframe, maxframe, ax, ay;
	tmptr = 256 - fldtr;
	
	for(i = 0; i < 21; i++) {
		// 読み込み
		if(i == 20) sprintf(string[0], "back_vs.png");
		else sprintf(string[0], "back%02d.png", i + 1);
		sg_background[i] = loadBackground(2, string[0]);
		
		// 半透明化
		SwapToSecondary(sg_background[i]);
		
		// 人数を決める
		if(i == 20) maxpl = 1;
		else maxpl = maxPlay;
		
		maxframe = back_mov_f[i];
		if(maxframe < 1) maxframe = 1;
		
		for(movframe = 0; movframe < maxframe; movframe++) {
			for(player = 0; player <= maxpl; player++) {
				// 表示位置を決める
				if(i == 20) {
					dx = v_foffset[player];
					dy = v_fyoffset[player];
				} else {
					dx = foffset[player];
					dy = fyoffset[player];
				}
				ax = ((movframe / 10) * 320);
				ay = ((movframe % 10) * 240);
				
				// 背景
				BlendExBlt(sg_black,ax + dx + 8,ay + dy + 40,tmptr,tmptr,tmptr,fldtr,fldtr,fldtr);
				
				// NEXT枠
				if(top_frame == 0) {
					// TYPE A
					BlendExBltRect(sg_topframe,ax + dx + 8,ay + dy + 7,109,8,80,25,tmptr,tmptr,tmptr,fldtr,fldtr,fldtr);
					
					for(k = 0; k < 20; k++) {
						tr = tmptr * (19 - k) / 20;
						tr = 256 - tr;
						tr2 = 256 - tr;
						BlendExBltRect(sg_topframe,ax + dx + 8 + (80 + k),ay + dy + 7,181 + k,8,1,25,tr2,tr2,tr2,tr,tr,tr);
					}
				} else if(top_frame == 1) {
					// TYPE B
					BlendExBltRect(sg_topframe,ax + dx - 12,ay + dy + 6,129,40,121,26,tmptr,tmptr,tmptr,fldtr,fldtr,fldtr);
				}
			}
		}
		
		SwapToSecondary(sg_background[i]);
	}
}

// システムで使う効果音を読み込み
void loadSystemSE() {
	int i;
	
	se_shaki        = loadSE(1, "se/shaki.wav");
	se_kon          = loadSE(1, "se/kon.wav");
	se_gon          = loadSE(1, "se/gon.wav");
	se_kachi        = loadSE(1, "se/kachi.wav");
	se_rotate       = loadSE(1, "se/rotate.wav");
	se_move         = loadSE(1, "se/move.wav");
	se_gameover     = loadSE(1, "se/gameover.wav");
	se_kettei       = loadSE(1, "se/kettei.wav");
	se_erase[0]     = loadSE(1, "se/erase1.wav");
	se_erase[1]     = loadSE(1, "se/erase2.wav");
	se_erase[2]     = loadSE(1, "se/erase3.wav");
	se_erase[3]     = loadSE(1, "se/erase4.wav");
	se_ready        = loadSE(1, "voice/ready.wav");
	se_go           = loadSE(1, "voice/go.wav");
	se_applause     = loadSE(1, "se/applause.wav");
	se_cheer        = loadSE(1, "se/cheer.wav");
	se_levelup      = loadSE(1, "se/levelup.wav");
	se_up           = loadSE(1, "se/up.wav");
	se_blockse[0]   = loadSE(1, "blockse/block1.wav");
	se_blockse[1]   = loadSE(1, "blockse/block2.wav");
	se_blockse[2]   = loadSE(1, "blockse/block3.wav");
	se_blockse[3]   = loadSE(1, "blockse/block4.wav");
	se_blockse[4]   = loadSE(1, "blockse/block5.wav");
	se_blockse[5]   = loadSE(1, "blockse/block6.wav");
	se_blockse[6]   = loadSE(1, "blockse/block7.wav");
	se_hold         = loadSE(1, "se/hold.wav");
	se_lvstop       = loadSE(1, "se/lvstop.wav");
	se_ttclear      = loadSE(1, "se/ttclear.wav");
	se_rankup       = loadSE(1, "se/rankup.wav");
	se_hanabi       = loadSE(1, "se/hanabi.wav");
	se_pause        = loadSE(1, "se/pause.wav");
	se_pinch        = loadSE(1, "se/pinch.wav");
	SetLoopModeWave(se_pinch, 1);
	se_stgstar      = loadSE(1, "se/stgstar.wav");
	se_movefail     = loadSE(1, "se/movefail.wav");
	se_rotfail      = loadSE(1, "se/rotfail.wav");
	se_cool         = loadSE(1, "se/cool.wav");
	se_regret       = loadSE(1, "se/regret.wav");
	se_tspin        = loadSE(1, "se/tspin.wav");
	se_tserase      = loadSE(1, "se/tserase.wav");
	se_platinaerase = loadSE(1, "se/platinaerase.wav");
	se_medal        = loadSE(1, "se/medal.wav");
	se_hurryup      = loadSE(1, "se/hurryup.wav");
	se_timeover     = loadSE(1, "se/timeover.wav");
	se_self_lock    = loadSE(1, "se/self_lock.wav");
	se_warning      = loadSE(1, "se/warning.wav");
	
	for(i = 0; i < 30; i++) bgm_plane[i] = reserveBGMPlane();
	
	executePlugin(0, 57, &dummy);	// プラグイン呼び出し
}

// システムグラフィックの読み込み／再読み込み
void loadAllSystemGraphics() {
	int i;
	
	// 解放
	for(i = 0; i < graphics_count; i++) ReleaseBitmap(i);
	graphics_count = 0;
	
	// フィールドの表示位置を設定
	setFieldPosition(0, maxPlay);
	setFieldPosition(1, maxPlay);
	
	// 読み込み
	loadSystemGraphics();
	if(!hide_back) loadSystemBackground();
	
	executePlugin(0, 56, &dummy);	// プラグイン呼び出し
}

// システムBGMを読み込み
void loadSystemBGM() {
	loadBGM(11);
	loadBGM(12);
	loadBGM(13);
}
