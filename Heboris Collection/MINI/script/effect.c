//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   オブジェクト関連
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// オブジェクトを作成
void objectCreate(int p, int s, int x, int y, int v, int w, int j, int c) {
	int i;
	int param[8];
	
	// プラグインを呼ぶ
	param[0] = 0;
	param[1] = s;
	param[2] = x;
	param[3] = y;
	param[4] = v;
	param[5] = w;
	param[6] = j;
	param[7] = c;
	executePlugin(p, 42, &param);
	if(param[0]) return;
	
	for(i = 0; i < 100; i++) {
		if(obj[i] == 0) {
			objp[i] = p;
			obj[i] = s;
			objx[i] = x;
			objy[i] = y;
			objv[i] = v;
			objw[i] = w;
			objj[i] = j;
			objc[i] = c;
			obja[i] = 0;
			return;
		}
	}
}

// 全てのオブジェクトを消去
void objectClear() {
	int i;
	
	for(i = 0; i < 100; i++) obj[i] = 0;
}

// 特定のプレイヤーのオブジェクトだけを消去
void objectClearPl(int player) {
	int i;
	
	for(i = 0; i < 100; i++) {
		if(objp[i] == player) obj[i] = 0;
	}
}

// オブジェクトを実行
void objectExecute() {
	int i;
	int param[3];
	
	for(i = 0; i < 100; i++) {
		if(obj[i]) {
			// プラグインを呼ぶ
			param[0] = 0;
			param[1] = i;
			param[2] = obj[i];
			executePlugin(objp[i], 43, &param);
			if(param[0]) goto next;
			
			jump(obj[i] - 1, o01, o02, o03, o04, o05, o06, o07, o08);
			
			o01: objectStatBlock(objp[i], i);			// 01 -> ブロック消去
					goto next;
			o02: objectPopBlock(objp[i], i);			// 02 -> 飛び散るブロック
					goto next;
			o03: objectHanabi(objp[i], i);				// 03 -> 花火
					goto next;
			o04: objectBravo(objp[i], i);				// 04 -> 全消し
					goto next;
			o05: objectItemErase(objp[i], i);			// 05 -> アイテム消去エフェクト
					goto next;
			o06: objectShootingStarP(objp[i], i);		// 06 -> 流れ星（座標計算）
					goto next;
			o07: objectShootingStarC(objp[i], i);		// 07 -> 流れ星（描画）
					goto next;
			o08: objectItemWarning(objp[i], i);			// 08 -> アイテム発動警告
					goto next;
			
			next:
		}
	}
}

// ブロック消去
void objectStatBlock(int player, int no) {
	int param[2];
	
	param[0] = 0;
	param[1] = no;
	executePlugin(player, 44, &param);
	if(param[0]) return;
	
	if((breaktype == 0) || (objj[no] == 8) || (objj[no] == 9)) {
		obj[no] = 0;
	} else if(objj[no] >= 10) {
		// プラチナブロック
		if(obja[no] >= 60) {
			obj[no] = 0;
		} else {
			ExBltRect(sg_perase[objj[no] - 10], objx[no] - 12, objy[no] - 12, (obja[no] % 10) * 32, (obja[no] / 10) * 32, 32, 32);
			
			// +1
			if((perase_show_bonus[player]) && (obja[no] < 32))
				ExBltRect(sg_spr, objx[no], objy[no] - obja[no], 12 * (objj[no] - 10), 133, 12, 7);
		}
		obja[no] = obja[no] + effectspeed[player];
	} else if(breaktype == 1) {
		// 飛び散るブロック
		objectPopBlock(player, no);
	} else if(breaktype == 2) {
		// 砕けるブロック
		if(obja[no] >= 36) {
			obj[no] = 0;
		} else {
			ExBltRect(sg_break[objj[no]], objx[no] - 44, objy[no] - 20, (obja[no] % 6) * 96, (obja[no] / 6) * 96, 96, 96);
		}
		obja[no] = obja[no] + effectspeed[player];
	} else if(breaktype == 3) {
		// シンプル1
		if(obja[no] % 30 < 15) drawSBlock(player, objx[no], objy[no], 0, 0, 0, 0, 0);
		else if(obja[no] < 40) drawSBlock(player, objx[no], objy[no], objj[no], 0, 0, 0, 0);
		obja[no] = obja[no] + effectspeed[player];
		if((obja[no] >= 40) || (obja[no] >= wait2[player])) obj[no] = 0;
	} else if(breaktype == 4) {
		// シンプル2
		drawSBlock(player, objx[no], objy[no], objj[no], 6 + (obja[no] / 2), 0, 0, 0);
		obja[no] = obja[no] + effectspeed[player];
		if((obja[no] >= 20) || (obja[no] >= wait2[player])) obj[no] = 0;
	}
}

// 飛び散るブロック
void objectPopBlock(int player, int no) {
	int zoom, offset;
	int param[2];
	
	param[0] = 0;
	param[1] = no;
	executePlugin(player, 45, &param);
	if(param[0]) return;
	
	// 最初の1フレームの処理
	if(obja[no] == 0) {
		objx[no] = objx[no] * 100;
		objy[no] = objy[no] * 100;
		obja[no]++;
	}
	
	objx[no] = objx[no] + objv[no] * effectspeed[player];
	objy[no] = objy[no] + objw[no] * effectspeed[player];
	
	objw[no] = objw[no] + 250 * effectspeed[player];
	objc[no] = objc[no] + 15 * effectspeed[player];
	
	zoom = objc[no] * 65536 / 100;
	offset = (objc[no] - 100) * 8 / 200;
	
	drawSBlockR(player, objx[no] / 100 - offset, objy[no] / 100 - offset, objj[no], zoom);
	
	if((objy[no] + offset * 100) > 24000) obj[no] = 0;
}

// 花火
void objectHanabi(int player, int no) {
	int param[2];
	
	param[0] = 0;
	param[1] = no;
	executePlugin(player, 46, &param);
	if(param[0]) return;
	
	if((objj[no] < 0) || (objj[no] > 6)) {
		obj[no] = 0;
		return;
	}
	
	if(!obja[no]) PlaySE(se_hanabi);
	
	// 96x96
	// 48frames
	ExBltRect(sg_hanabi[objj[no]], objx[no], objy[no], (obja[no] % 6) * 96, (obja[no] / 6) * 96, 96, 96);
	obja[no] = obja[no] + 1;
	if(obja[no] >= 48) obj[no] = 0;
}

// 全消し
void objectBravo(int player, int no) {
	int param[2];
	
	param[0] = 0;
	param[1] = no;
	executePlugin(player, 47, &param);
	if(param[0]) return;
	
	if(objy[no] > 104) objy[no] = objy[no] - 8 * effectspeed[player];
	
	ExBltRect(sg_gametext, objx[no], objy[no], 100, 150 + 25 * (count % 4 / 2), 100, 25);
	
	obja[no] = obja[no] + effectspeed[player];
	if(obja[no] > 80) obj[no] = 0;
}

// アイテム消去エフェクト
void objectItemErase(int player, int no) {
	int param[2];
	
	param[0] = 0;
	param[1] = no;
	executePlugin(player, 50, &param);
	if(param[0]) return;
	
	ExBltRect(sg_itemerase, objx[no] - 36, objy[no] - 36, (obja[no] % 6) * 80, (obja[no] / 6) * 80, 80, 80);
	obja[no]++;
	if(obja[no] >= 30) obj[no] = 0;
}

// 流れ星（座標計算）
void objectShootingStarP(int player, int no) {
	int param[2];
	
	param[0] = 0;
	param[1] = no;
	executePlugin(player, 51, &param);
	if(param[0]) return;
	
	if(!obja[no]) PlaySE(se_stgstar);
	
	objx[no] = objx[no] - 4;
	objy[no] = objy[no] + 6;
	objectCreate(player, 7, objx[no], objy[no], 0, 0, 0, 0);
	
	obja[no]++;
	if(obja[no] >= 30) obj[no] = 0;
}

// 流れ星（描画）
void objectShootingStarC(int player, int no) {
	int param[2];
	
	param[0] = 0;
	param[1] = no;
	executePlugin(player, 52, &param);
	if(param[0]) return;
	
	ExBltRect(sg_shootingstar, objx[no], objy[no], (obja[no] % 6) * 32, (obja[no] / 6) * 32, 32, 32);
	obja[no]++;
	if(obja[no] >= 35) obj[no] = 0;
}

// アイテム発動警告
void objectItemWarning(int player, int no) {
	if(!obja[no]) PlaySE(se_warning);	// warning.wav
	
	ExBltRect(sg_gametext, foffset[player] - 2, fyoffset[player] + 84, 0, 150 + 25 * (count % 4 / 2), 100, 25);
	
	if(objj[no] >= 0) {
		ExBltRect(sg_iblk_n, foffset[player] + 16, fyoffset[player] + 116, (8 * objj[no]) + 56, 0, 8, 8);
		ExBltRect(sg_itemname, foffset[player] + 24, fyoffset[player] + 112, 0, objj[no] * 16, 48, 16);
		ExBltRect(sg_iblk_n, foffset[player] + 72, fyoffset[player] + 116, (8 * objj[no]) + 56, 0, 8, 8);
	}
	
	obja[no]++;
	if(obja[no] > 40) obj[no] = 0;
}
