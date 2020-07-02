// ヘボリス式のNEXTブロック生成
void heboNextInit(int player) {
	int i, j, temp, mae, shu;
	int nextwork[7];
	
	mae = -1;
	
	if(nextblock == 0) {
		// 完全ランダム
		do {
			temp = Rand(7);
		} while((temp == 2) || (temp == 3) || (temp == 6));
		
		nextb[player * 1400] = temp;
		
		for(i = 1; i < 1400; i++) {
			nextb[player * 1400 + i] = Rand(7);
		}
	} else {
		shu = nextblock;
		
		for(i = 0; i < 1400 / shu + 1; i++) {
			for(j = 0; j < 7; j++) nextwork[j] = 0;
			
			for(j = 0; j < shu; j++) {
				do {
					if(i * shu + j == 0) {
						do {
							temp = Rand(7);
						} while((temp == 2) || (temp == 3) || (temp == 6));
					} else {
						temp = Rand(7);
					}
				} while((nextwork[temp] != 0) || (mae == temp));
				
				if(i * shu + j < 1400) nextb[(player * 1400) + (i * shu + j)] = temp;
				nextwork[temp] = 1;
				mae = temp;
			}
		}
	}
}

// 某ゲーム風NEXT生成処理
void tgmNextInit(int player, int type) {
	int i, j;
	int history[4];
	int block;

	if(type) {
		// Z S Z Sで埋める
		history[0] = 3;
		history[1] = 6;
		history[2] = 3;
		history[3] = 6;
	} else {
		// 履歴を緑で埋める
		for(i = 0; i < 4; i++) history[i] = 3;
	}

	// 初手生成
	do {
		nextb[0 + player * 1400] = Rand(7);
	} while((nextb[0 + player * 1400] == 2) || (nextb[0 + player * 1400] == 3) || (nextb[0 + player * 1400] == 6));

	// 履歴をずらす
	for(j = 0; j < 3; j++) {
		history[3 - j] = history[3 - (j + 1)];
	}

	// 履歴に新しいブロックを入れる
	history[0] = nextb[0 + player * 1400];

	// 残りのツモを生成
	for(i = 1; i < 1400; i++) {
		// ツモを引く
		block = Rand(7);
		
		// 引いたツモが履歴にあったら最大4回(type = 1では6回)引き直し
		if((block == history[0]) || (block == history[1]) || (block == history[2]) || (block == history[3])) {
			for(j = 0; j < 4 + (type * 2); j++) {
				block = Rand(7);
				
				// 4つの履歴に無かったらその場で抜ける
				if((block != history[0]) && (block != history[1]) && (block != history[2]) && (block != history[3]))
					break;
			}
		}

		// 履歴をずらす
		for(j = 0; j < 3; j++) {
			history[3 - j] = history[3 - (j + 1)];
		}

		// 履歴に新しいブロックを入れる
		history[0] = block;

		// nextbに入れる
		nextb[i + player * 1400] = block;
	}
}

// ガイドライン対応ゲーム風なNEXT生成処理
void guidelineNextInit(int player) {
	int i, j;
	int tmp;
	int first;
	int block[7];	// ブロックが出たかどうかのフラグ
	
	first = 1;
	
	for(i = 0; i < 200; i++) {
		// 初期化
		for(j = 0; j < 7; j++) block[j] = 0;
		
		// ツモ作成
		for(j = 0; j < 7; j++) {
			do {
				tmp = Rand(7);	// ツモを引く
			} while( (block[tmp] == 1) || ( (first == 1) && ((tmp == 2)||(tmp == 3)||(tmp == 6)) ) );
			
			// ブロックが出たフラグON
			block[tmp] = 1;
			
			// nextbに入れる
			nextb[i * 7 + j + player * 1400] = tmp;
			
			first = 0;
		}
	}
}

// カスタムツモリストを読み込み
void userNextInit(int player) {
	int i, j, temp, len;
	
	// 長さを調べる
	len = StrLen(userNextBlockList);
	
	// 読み込み
	if(len > 0) {
		nextc_max[player] = len;
		
		for(i = 0; i < len; i++) {
			j = i % len;
			
			MidStr(userNextBlockList, j + 1, 1, string[0]);
			
			temp = ValLong(string[0]);
			if((temp >= 0) && (temp <= 6)) nextb[i + player * 1400] = temp;
		}
	}
}

// 棒のみ
void icheatNextInit(int player) {
	int i;
	
	for(i = 0; i < 1400; i++) nextb[i + player * 1400] = 0;
}

// 7+1
void eightBagNextInit(int player) {
	int i, j;
	int tmp;
	int first;
	int block[7];	// ブロックが出たかどうかのフラグ
	
	first = 1;
	
	for(i = 0; i < 175; i++) {
		// 初期化
		for(j = 0; j < 7; j++) block[j] = 0;
		
		// ツモ作成
		for(j = 0; j < 8; j++) {
			if(j == 7) {
				// 8個目
				nextb[i * 8 + j + player * 1400] = Rand(7);
			} else {
				// 1-7個目
				do {
					tmp = Rand(7);	// ツモを引く
				} while( (block[tmp] == 1) || ( (first == 1) && ((tmp == 2)||(tmp == 3)||(tmp == 6)) ) );
				
				// ブロックが出たフラグON
				block[tmp] = 1;
				
				// nextbに入れる
				nextb[i * 8 + j + player * 1400] = tmp;
				
				first = 0;
			}
		}
	}
}
