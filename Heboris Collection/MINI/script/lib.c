//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   フィールドをリセット
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void resetField(int player) {
	int i, j;
	
	for(i = 0; i < fldsizey; i++) {
		for(j = 0; j < fldsizex; j++) {
			setFieldBlock(player, j, i, 0);
			setFieldBlockT(player, j, i, 0);
			setFieldBlockO(player, j, i, 0);
			setFieldBlockL(player, j, i, 0);
			setFieldBlockI(player, j, i, 0);
		}
		erase[i + player * fldsizey] = 0;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   フィールドタイマー解除（全ブロックを見えるようにする）
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void disableShadowTimer(int player) {
	int i, j;
	
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++) {
			if(getFieldBlock(player, j, i) != 0)
				setFieldBlockT(player, j, i, -1);
		}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスカウンタリセット
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void resetStatc(int player) {
	int i;
	for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   NEXTブロックの色を設定
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void setNextBlockColor(int player, int first) {
	int i, j, block, color;
	
	if(!dispnext) return;
	
	if(first) {
		// 全てのブロックの色を設定
		for(i = 0; i < 6; i++) {
			block = getNextBlock(player, i);
			
			for(j = 0; j < 4; j++) next_color[player * 24 + i * 4 + j] = blockcolor[player * 7 + block];
			next_oblk[player * 6 + i] = oblk_spawn[player];
			next_item[player * 6 + i] = 0;
			
			// マルチカラーブロック
			if(multicolor_enable[player]) {
				for(j = 0; j < 4; j++) {
					if(GiziRand(player, 100) < multicolor_ratio[player]) {
						color = next_color[player * 24 + i * 4 + j];
						
						do {
							next_color[player * 24 + i * 4 + j] = GiziRand(player, 7) + 1;
						} while(color == next_color[player * 24 + i * 4 + j]);
					}
				}
			}
		}
	} else {
		// 色をずらす
		for(i = 0; i < dispnext - 1; i++) {
			for(j = 0; j < 4; j++) next_color[player * 24 + i * 4 + j] = next_color[player * 24 + (i + 1) * 4 + j];
			next_oblk[player * 6 + i] = next_oblk[player * 6 + i + 1];
			next_item[player * 6 + i] = next_item[player * 6 + i + 1];
		}
		
		// 一番最後のブロックの色を設定
		block = getNextBlock(player, dispnext - 1);
		for(j = 0; j < 4; j++) next_color[player * 24 + (dispnext - 1) * 4 + j] = blockcolor[player * 7 + block];
		next_oblk[player * 6 + dispnext - 1] = oblk_spawn[player];
		next_item[player * 6 + dispnext - 1] = item_coming[player];
		item_coming[player] = 0;
		
		// マルチカラーブロック
		if(multicolor_enable[player]) {
			for(j = 0; j < 4; j++) {
				if(GiziRand(player, 100) < multicolor_ratio[player]) {
					color = next_color[player * 24 + (dispnext - 1) * 4 + j];
					
					do {
						next_color[player * 24 + (dispnext - 1) * 4 + j] = GiziRand(player, 7) + 1;
					} while(color == next_color[player * 24 + (dispnext - 1) * 4 + j]);
				}
			}
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   NEXTブロックを取得
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int getNextBlock(int player, int offset) {
	int temp;
	
	temp = nextc[player] + offset;
	if(temp >= nextc_max[player]) temp = temp - nextc_max[player];
	
	return nextb[player * 1400 + temp];
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ピンチかどうかチェック
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void pinchCheck(int player) {
	int i, j, param, blocks;
	
	param = 0;
	executePlugin(player, 65, &param);
	if(param) return;
	
	pinch[player] = 0;
	
	if(engineVer >= 8) {
		blocks = checkHowManyBlocks(player);
		
		if((blocks >= ((fldsizex * fldsizey) - 70)) && (((fldsizex * fldsizey) - 70) > 0)) {
			pinch[player] = 1;
		}
	} else {
		for(i = 0; i <= 7; i++)
			for(j = 2; j <= 7; j++)
				if(fld[j + i * 7 + player * 220]) {
					pinch[player] = 1;
					return;
				}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   全消しチェック
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int isBravo(int player) {
	int i, j;
	
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++)
			if(getFieldBlock(player, j, i) != 0) return 0;
	
	return 1;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   現在のスピードが20Gかどうか判定
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int is20G(int player) {
	if((speedtype[player] == 0) && (sp[player] >= 1200)) return 1;
	if((speedtype[player] == 2) && (sp[player] >= 5120)) return 1;
	return 0;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   表示するアイテム名を決定
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void scanItem(int player) {
	int i, j;
	
	item_name[player] = 0;
	
	// フィールドを調べる
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++)
			if((getFieldBlockI(player, j, i) != 0) && (getFieldBlockI(player, j, i) < fldihardno)) {
				item_name[player] = getFieldBlockI(player, j, i);
			}
	
	// ホールドを調べる
	if((hold_item[player] != 0) && (hold_item[player] < fldihardno))
		item_name[player] = hold_item[player];
	
	// NEXTを調べる
	for(i = 0; i < 6; i++)
		if((next_item[i + player * 6] != 0) && (next_item[i + player * 6] < fldihardno)) {
			item_name[player] = next_item[i + player * 6];
		}
	
	// 現在のブロックを調べる
	if((current_item[player] != 0) && (current_item[player] < fldihardno))
		item_name[player] = current_item[player];
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   フィールド上からすべてのアイテムを除去
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void cleanupItem(int player) {
	int i, j;
	
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++)
			if((getFieldBlockI(player, j, i) != 0) && (getFieldBlockI(player, j, i) < fldihardno)) {
				setFieldBlockI(player, j, i, 0);
			}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ブロックの繋がりデータを自動生成
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void makeBlockLinkData(int player) {
	int i, j;
	int kind, rotate;
	int bx, by, bx2, by2;
	int linkdata;
	
	for(kind = 0; kind < 7; kind++)
		for(rotate = 0; rotate < 4; rotate++)
			for(i = 0; i < 4; i++) {
				// 相対X位置と相対Y位置
				bx = blkDataX[kind * 16 + rotate * 4 + player * 112 + i];
				by = blkDataY[kind * 16 + rotate * 4 + player * 112 + i];
				
				// 他の3つのブロックとの繋がりを調べる
				linkdata = 0;
				for(j = 0; j < 4; j++) {
					if(j != i) {
						bx2 = blkDataX[kind * 16 + rotate * 4 + player * 112 + j];
						by2 = blkDataY[kind * 16 + rotate * 4 + player * 112 + j];
						
						if((bx == bx2) && (by - 1 == by2)) linkdata = BitSet(linkdata, 0, 1);	// 上
						if((bx == bx2) && (by + 1 == by2)) linkdata = BitSet(linkdata, 1, 1);	// 下
						if((by == by2) && (bx - 1 == bx2)) linkdata = BitSet(linkdata, 2, 1);	// 左
						if((by == by2) && (bx + 1 == bx2)) linkdata = BitSet(linkdata, 3, 1);	// 右
					}
				}
				
				// 繋がりデータを代入
				blkDataL[kind * 16 + rotate * 4 + player * 112 + i] = linkdata;
			}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   パッドリピート入力処理
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void padRepeat(int player) {
	int param;
	param = 0;
	executePlugin(player, 61, &param);
	if(param) return;
	
	if(getPressState(player, 2) && getPressState(player, 3)) {
		mp[player] = 0;
		mpc[player] = 0;
	} else if(getPressState(player, 2)) {
		if(mp[player] != 2) {
			mp[player] = 2;
			mpc[player] = 0;
		}
		mpc[player]++;
	} else if(getPressState(player, 3)) {
		if(mp[player] != 3) {
			mp[player] = 3;
			mpc[player] = 0;
		}
		mpc[player]++;
	} else {
		mp[player] = 0;
		mpc[player] = 0;
	}
}

// hoge 上下入力バージョン
void padRepeat2(int player) {
	if(getPressState(player, 0) && getPressState(player, 1)) {
		mp2[player] = 0;
		mpc2[player] = 0;
	} else if(getPressState(player, 0)) {
		if(mp2[player] != 1) {
			mp2[player] = 1;
			mpc2[player] = 0;
		}
		mpc2[player]++;
	} else if(getPressState(player, 1)) {
		if(mp2[player] != 2) {
			mp2[player] = 2;
			mpc2[player] = 0;
		}
		mpc2[player]++;
	} else {
		mp2[player] = 0;
		mpc2[player] = 0;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   キー状態の取得
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// 押しつづけありのバージョン
int getPressState(int player, int key) {
	int param[2];
	param[0] = 0;
	param[1] = key;
	executePlugin(player, 62, &param);
	if(param[0]) return;
	
	if(!maxPlay && player) return 0;
	if(netplay && player) return 0;
	
	if(playback && replayauto) {
		// リプレイ
		if((onRecord[player]) && (recTimer[player] < 60 * 60 * 30) && (!pause[player]))
			return BitTest(replayData[player * 108000 + recTimer[player]], key);
		else
			return 0;
	} else if(cpu_flag[player] && onRecord[player] && !pause[player]) {
		// CPU
		return cpu_ctrl[player * 10 + key];
	} else {
		// 通常
		SelectJoyStick(player);
		
		if(!keyAssign[key + player * 10])
			return IsPressJoyKey(joykeyAssign[key + player * 10]);
		else
			return (IsPressJoyKey(joykeyAssign[key + player * 10]) | IsPressKey(keyAssign[key + player * 10]));
	}
}

// 押しつづけなしのバージョン
int getPushState(int player, int key) {
	int param[2];
	param[0] = 0;
	param[1] = key;
	executePlugin(player, 63, &param);
	if(param[0]) return;
	
	if(!maxPlay && player) return 0;
	if(netplay && player) return 0;
	
	if(playback && replayauto) {
		// リプレイ
		if((onRecord[player]) && (recTimer[player] < 60 * 60 * 30) && (!pause[player]))
			return BitTest(replayData[player * 108000 + recTimer[player]], key + 10);
		else
			return 0;
	} else if(cpu_flag[player] && onRecord[player] && !pause[player]) {
		// CPU
		return cpu_ctrl[player * 10 + key];
	} else {
		// 通常
		SelectJoyStick(player);
		
		if(!keyAssign[key + player * 10])
			return IsPushJoyKey(joykeyAssign[key + player * 10]);
		else
			return (IsPushJoyKey(joykeyAssign[key + player * 10]) | IsPushKey(keyAssign[key + player * 10]));
	}
}

// 特定のプレイヤーのジョイスティック入力を検出する関数…のつもり #LITE25
// ちゃんと動くかは不明
int getJoyPressState(int player, int key) {
	if(!maxPlay && player) return 0;
	if(netplay && player) return 0;
	SelectJoyStick(player);
	return IsPressJoyKey(key);
}

int getJoyPushState(int player, int key) {
	if(!maxPlay && player) return 0;
	if(netplay && player) return 0;
	SelectJoyStick(player);
	return IsPushJoyKey(key);
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ブロックのあたり判定
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int judgeBlock(int player, int bx1, int by1, int kind, int rotate) {
	int i, bx2, by2, temp;
	int param[5];
	param[0] = 0;
	param[1] = bx1;
	param[2] = by1;
	param[3] = kind;
	param[4] = rotate;
	executePlugin(player, 64, &param);
	if(param[0] == 1) return 0;
	if(param[0] == 2) return -1;
	
	// ビッグ時は専用処理
	if(IsBig[player]) {
		return judgeBigBlock(player, bx1, by1, kind, rotate);
	}
	
	for(i = 0; i < 4; i++) {
		bx2 = bx1 + blkDataX[kind * 16 + rotate * 4 + player * 112 + i];
		by2 = by1 + blkDataY[kind * 16 + rotate * 4 + player * 112 + i];
		
		temp = getFieldBlock(player, bx2, by2);
		if((temp != 0) && (temp != -2)) return -1;
	}
	
	return 0;
}

// ビッグ用
int judgeBigBlock(int player, int bx1, int by1, int kind, int rotate) {
	int i, bx2, by2, temp;
	int k, l;
	
	for(i = 0; i < 4; i++) {
		bx2 = (bx1 + blkDataX[kind * 16 + rotate * 4 + player * 112 + i] * 2);
		by2 = (by1 + blkDataY[kind * 16 + rotate * 4 + player * 112 + i] * 2);
		
		// 4ブロック分調べる
		for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
			temp = getFieldBlock(player, bx2 + k, by2 + l);
			if((temp != 0) && (temp != -2)) return -1;
		}
	}
	
	return 0;
}

// ARS系で壁蹴りできるかどうか判定
int judgeBlockRotate(int player, int bx1, int by1, int kind, int rotate) {
	int i, xx, bx2, by2, temp;
	
	// ビッグ時は専用処理
	if(IsBig[player]) {
		return judgeBigBlockRotate(player, bx1, by1, kind, rotate);
	}
	
	for(i = 0; i < 4; i++) {
		xx = blkDataX[kind * 16 + rotate * 4 + player * 112 + i];
		
		// 中央の列以外が重なっている場合は壁蹴り可能
		if(xx != 1) {
			bx2 = bx1 + xx;
			by2 = by1 + blkDataY[kind * 16 + rotate * 4 + i];
			temp = getFieldBlock(player, bx2, by2);
			if((temp != 0) && (temp != -2)) return 1;
		}
	}
	
	return 0;
}

// ARS系で壁蹴りできるかどうか判定（ビッグ用）
int judgeBigBlockRotate(int player, int bx1, int by1, int kind, int rotate) {
	int i, xx, bx2, by2, temp;
	int k, l;
	
	for(i = 0; i < 4; i++) {
		xx = blkDataX[kind * 16 + rotate * 4 + player * 112 + i];
		
		// 中央の列以外が重なっている場合は壁蹴り可能
		if(xx != 1) {
			bx2 = (bx1 + xx * 2);
			by2 = (by1 + blkDataY[kind * 16 + rotate * 4 + i] * 2);
			
			// 4ブロック分調べる
			for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
				temp = getFieldBlock(player, bx2 + k, by2 + l);
				if((temp != 0) && (temp != -2)) return 1;
			}
		}
	}
	
	return 0;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ブロックを設置する
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int setBlock(int player, int bx1, int by1, int kind, int rotate) {
	int i, bx2, by2, puted, linkdata;
	puted = 0;
	
	// ビッグ時は専用処理
	if(IsBig[player]) {
		return setBigBlock(player, bx1, by1, kind, rotate);
	}
	
	for(i = 0; i < 4; i++) {
		bx2 = bx1 + blkDataX[kind * 16 + rotate * 4 + player * 112 + i];
		by2 = by1 + blkDataY[kind * 16 + rotate * 4 + player * 112 + i];
		if(by2 >= 2) puted++;	// 枠内に置いた数＋１
		linkdata = blkDataL[kind * 16 + rotate * 4 + player * 112 + i];
		
		setFieldBlock(player, bx2, by2, current_color[i + player * 4] + 1);
		setFieldBlockT(player, bx2, by2, shadowtime[player]);
		setFieldBlockO(player, bx2, by2, current_oblk[player]);
		setFieldBlockL(player, bx2, by2, linkdata);
		setFieldBlockI(player, bx2, by2, current_item[player]);
	}
	
	if(!puted) return 1;
	
	return 0;
}

// ビッグ用
int setBigBlock(int player, int bx1, int by1, int kind, int rotate) {
	int i, bx2, by2, puted;
	int k, l, bx3, by3;
	puted = 0;
	
	for(i = 0; i < 4; i++) {
		bx2 = (bx1 + blkDataX[kind * 16 + rotate * 4 + player * 112 + i] * 2);
		by2 = (by1 + blkDataY[kind * 16 + rotate * 4 + player * 112 + i] * 2);
		if(by2 >= 2) puted++;	// 枠内に置いた数＋１
		
		// 4ブロック分設置する
		for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
			bx3 = bx2 + k;
			by3 = by2 + l;
			
			setFieldBlock(player, bx3, by3, current_color[i + player * 4] + 1);
			setFieldBlockT(player, bx3, by3, shadowtime[player]);
			setFieldBlockO(player, bx3, by3, current_oblk[player]);
			setFieldBlockL(player, bx3, by3, 0);
			setFieldBlockI(player, bx3, by3, current_item[player]);
		}
	}
	
	if(!puted) return 1;
	
	return 0;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   フィールドの状態を取得
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// フィールド外は-1
// フィールドより上は-2
int getFieldBlock(int player, int x, int y) {
	if((x < 0) || (x >= fldsizex) || (y >= fldsizey)) return -1;
	if(y < 0) return -2;
	return fld[x + y * fldsizex + player * (fldsizex * fldsizey)];
}

// フィールドタイマー用
int getFieldBlockT(int player, int x, int y) {
	if((x < 0) || (x >= fldsizex) || (y < 0) || (y >= fldsizey)) return 0;
	return fldt[x + y * fldsizex + player * (fldsizex * fldsizey)];
}

// ご先祖様フラグ用
int getFieldBlockO(int player, int x, int y) {
	if((x < 0) || (x >= fldsizex) || (y < 0) || (y >= fldsizey)) return 0;
	return fldo[x + y * fldsizex + player * (fldsizex * fldsizey)];
}

// ブロックの繋がり用
int getFieldBlockL(int player, int x, int y) {
	if((x < 0) || (x >= fldsizex) || (y < 0) || (y >= fldsizey)) return 0;
	return fldl[x + y * fldsizex + player * (fldsizex * fldsizey)];
}

// アイテム用
int getFieldBlockI(int player, int x, int y) {
	if((x < 0) || (x >= fldsizex) || (y < 0) || (y >= fldsizey)) return 0;
	return fldi[x + y * fldsizex + player * (fldsizex * fldsizey)];
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   フィールドの状態を書き換える
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void setFieldBlock(int player, int x, int y, int block) {
	if((x >= 0) && (x < fldsizex) && (y >= (spawntype[player] == 0)) && (y < fldsizey)) {
		fld[x + y * fldsizex + player * (fldsizex * fldsizey)] = block;
	}
}

// フィールドタイマー用
void setFieldBlockT(int player, int x, int y, int block) {
	if((x >= 0) && (x < fldsizex) && (y >= (spawntype[player] == 0)) && (y < fldsizey)) {
		fldt[x + y * fldsizex + player * (fldsizex * fldsizey)] = block;
	}
}

// ご先祖様フラグ用
void setFieldBlockO(int player, int x, int y, int block) {
	if((x >= 0) && (x < fldsizex) && (y >= (spawntype[player] == 0)) && (y < fldsizey)) {
		fldo[x + y * fldsizex + player * (fldsizex * fldsizey)] = block;
	}
}

// ブロックの繋がり用
void setFieldBlockL(int player, int x, int y, int block) {
	if((x >= 0) && (x < fldsizex) && (y >= (spawntype[player] == 0)) && (y < fldsizey)) {
		fldl[x + y * fldsizex + player * (fldsizex * fldsizey)] = block;
	}
}

// アイテム用
void setFieldBlockI(int player, int x, int y, int block) {
	if((x >= 0) && (x < fldsizex) && (y >= (spawntype[player] == 0)) && (y < fldsizey)) {
		fldi[x + y * fldsizex + player * (fldsizex * fldsizey)] = block;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   フィールドの最上段を返す
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int checkFieldTop(int player) {
	int i, j;
	
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++)
			if(getFieldBlock(player, j, i) != 0) return i;
	
	// 空っぽの場合
	return fldsizey;
}

// フィールドの最上段を返す（X座標を指定できるバージョン）
int checkFieldTopEx(int player, int j) {
	int i;
	
	for(i = 0; i < fldsizey; i++)
		if(getFieldBlock(player, j, i) != 0) return i;
	
	// 空っぽの場合
	return fldsizey;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   フィールドのブロックの数を返す
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int checkHowManyBlocks(int player) {
	int i, j, result;
	result = 0;
	
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++)
			if(getFieldBlock(player, j, i) != 0) result++;
	
	return result;
}

// プラチナブロックだけ数える
int checkHowManyPBlocks(int player) {
	int i, j, result;
	result = 0;
	
	for(i = 0; i < fldsizey; i++)
		for(j = 0; j < fldsizex; j++)
			if(getFieldBlock(player, j, i) >= 11) result++;
	
	return result;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   裏段位判定
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int checkSecretGrade(int player) {
	int i, j, uhole, umode, result;
	
	if(fldsizex != 10) return -1;
	if(fldsizey != 22) return -1;
	
	uhole = 0;		// 穴の位置を初期化（最初は左端）
	umode = 0;		// 1だと右から左へ穴が移動
	result = -1;	// 現在の裏段位を初期化
	
	// 9～S9までの判定
	for(i = 21; i > 3; i--) {
		for(j = 0; j < 10; j++) {
			// 埋まっているべき場所が埋まってないなら終了
			if((getFieldBlock(player, j, i) == 0) && (j != uhole)) return result;
		}
		
		// 次の穴の位置を決める
		if(!umode) {
			uhole++;
			
			if(uhole > 9) {
				uhole = 8;
				umode = 1;
			}
		} else {
			uhole--;
		}
		
		// 裏段位上昇
		result++;
	}
	
	// GM判定
	// 左上(X:0 Y:2)が埋まっていたらGM
	if(getFieldBlock(player, 0, 2) != 0) {
		result++;
	}
	
	return result;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  擬似乱数
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// シード生成
void GiziSRand(int player) {
	randseed[player] = Rand(65536);
	firstseed[player] = randseed[player];
}

// 乱数生成（リプレイ保存対応）
int GiziRand(int player, int max) {
	if(max == 0) return 0;
	randseed[player] = ((randseed[player] * 673 + 994) / 10) % 100000;
	return abs(randseed[player]) % max;
}

// 絶対値を求める
int abs(int i) {
	if(i < 0) return -i;
	return i;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ビット演算
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// 変数valueのbit目のビットの状態を調べる
int BitTest(int value, int bit) {
	int i;
	i = (value) & (1 << (bit));
	return (i != 0);
}

// 変数valueのbit目のビットの状態を変える
int BitSet(int value, int bit, int status) {
	if(status) {
		value = (value) | (1 << (bit));
	} else {
		value = (value) & (~(1 << (bit)));
	}
	return value;
}
