//MASTER-EASY
//Special Thanks to www.tetrisconcept.com's wiki
//prefix:mas

int masVersion;				// バージョン（過去のリプレイとの互換性用）
int masCVersion = 8;		// 現在のバージョン（masVersionに代入される）

// BGM設定
int masBgmNo[3] = {0,1,7};	// BGM番号（000-499、500-998、999）
int masFadeLv = 490;		// BGMをフェードアウトさせるレベル
int masBgmChange = 500;		// BGMを変えるレベル

// レベルアップテーブル(420での減速追加後)
// 速度
int masLevelTable[30] =
{
	4, 6, 8, 10, 12, 16, 32, 48, 64, 80, 96, 112, 128, 144, 4, 32, 64, 96, 128, 160,
	192, 224, 256, 512, 768, 1024, 1280, 1024, 768, 5120
};

// レベル
int masLevelChange[30] = 
{
	30, 35, 40, 50, 60, 70, 80, 90, 100, 120, 140, 160, 170, 200, 220, 230, 233, 236, 239, 243,
	247, 251, 300, 330, 360, 400, 420, 450, 500, 10000
};

// レベルアップテーブル(420での減速追加前)
// 速度
int masLevelTable7[29] =
{
	4, 6, 8, 10, 12, 16, 32, 48, 64, 80, 96, 112, 128, 144, 4, 32, 64, 96, 128, 160,
	192, 224, 256, 512, 768, 1024, 1280, 768, 5120
};

// レベル
int masLevelChange7[29] = 
{
	30, 35, 40, 50, 60, 70, 80, 90, 100, 120, 140, 160, 170, 200, 220, 230, 233, 236, 239, 243,
	247, 251, 300, 330, 360, 400, 450, 500, 10000
};

// 旧レベルアップテーブル
int masLevelTableOld[51] =
{
//  *00, *10, *20, *30, *40, *50, *60, *70, *80, *90
	1  , 1  , 1  , 2  , 3  , 4  , 5  , 6  , 8  , 12 ,// 0**
	15 , 15 , 15 , 15 , 23 , 23 , 23 , 23 , 30 , 30 ,// 1**
	1  , 2  , 8  , 15 , 30 , 60 , 60 , 60 , 60 , 60 ,// 2**
	120, 120, 120, 180, 180, 180, 240, 240, 240, 240,// 3**
	300, 300, 300, 300, 240, 240, 240, 180, 180, 180,// 4**
	1200
};

// 基準スコア
int masScoreTable[18] = 
{
	   400,   800,  1400,  2000,  3500,  5500,  8000,  12000,			// 8～1
	 16000, 22000, 30000, 40000, 52000, 66000, 82000, 100000, 120000,	// S1～S9
	126000																// GM
};

// 段位の表示名
str masStrGradeName[19] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0～ 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9～17
	"GM"													// 18
};

int masModeNo = -1;		// モード番号

int masLevel[2];		// レベル
int masScore[2];		// スコア
int masGrade[2];		// 段位
int masBravo[2];		// 全消し回数
int masGMFlag[2 * 2];	// Gm条件フラグ
int masGFlash[2];		// 段位表示ズーム演出用
int masLevelIndex[2];	// 現在の速度番号
int masLastLine[2];		// 最後のライン消しのライン数

int masIsBig = 0;		// BIGかどうか
int masBigMove = 0;		// BIG時の横移動単位
int masGhost = 0;		// ゴーストの設定（0=LV0-99 1=常にON 2=常にOFF）
int masLvUpBonus = 0;	// レベルアップボーナス
int mas20G = 0;			// 20Gモード
int masStartLevel = 0;	// スタート時のレベル

// ランキング変数
int masRankingGrade[10];		// 段位
int masRankingLevel[10];		// レベル
int masRankingTime[10];			// タイム
int masRankingYear[10];			// ランクイン日時（年）
int masRankingMonth[10];		// ランクイン日時（月）
int masRankingDay[10];			// ランクイン日時（日）
int masRankingHour[10];			// ランクイン日時（時）
int masRankingMinute[10];		// ランクイン日時（分）
int masRankingSecond[10];		// ランクイン日時（秒）

// イベント発生
void masPluginEvent(int player, int event, int *param) {
	int i;
	
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != masModeNo)) return;
	
	if(event == 0) {
		masModeNo = addModePlugin("MASTER-EASY");	// モードを登録する
	} else if(event == 7) {
		if(!ending[player]) masMoveInit(player);	// ブロック出現
	} else if(event == 12) {
		if(!ending[player]) masCalcScore(player, param[0]);	// スコア計算
	} else if(event == 15) {
		masViewScore(player);	// スコア表示
	} else if(event == 17) {
		masSetting(player, param);	// 設定画面
	} else if(event == 18) {
		masPlayerInitial(player);	// 初期化処理
	} else if(event == 21) {
		masResult(player);	// 結果表示
	} else if(event == 24) {
		ending[player] = 3;	// 偽END
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	} else if(event == 25) {
		masExcellent(player, param);	// エンディング終了
	} else if(event == 28) {
		masIncrementTime(player);	// 時間を進める
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		masSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		masLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		masLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		masReplayDetail(param[0]);	// リプレイ詳細
	}
}

// 初期化処理
void masPlayerInitial(int player) {
	// バージョン設定
	if(!playback) masVersion = masCVersion;
	
	// コンボ有効
	enable_combo[player] = 1;
	
	// 変数を初期化
	if(masVersion >= 7) {
		if(masStartLevel > 0) masLevel[player] = masStartLevel;
		else masLevel[player] = -1;
		
		backno = masLevel[player] / 100;
	} else {
		masLevel[player] = -1;
	}
	masScore[player] = 0;
	masGrade[player] = 0;
	masBravo[player] = 0;
	masGMFlag[player * 2 + 0] = 0;
	masGMFlag[player * 2 + 1] = 0;
	masGFlash[player] = 0;
	masLevelIndex[player] = 0;
	masLastLine[player] = 0;
	bgmlv = masBgmNo[0];
	
	if(masVersion >= 5) {
		speedtype[player] = 2;
		wait1[player] = 30;
		wait2[player] = 40;
		wait3[player] = 30;
		waitt[player] = 16;
	} else if(masVersion >= 4) {
		speedtype[player] = 2;
		wait1[player] = 25;
		wait2[player] = 40;
		wait3[player] = 30;
		waitt[player] = 16;
	} else if(masVersion >= 1) {
		speedtype[player] = 2;
		wait1[player] = 30;
		wait2[player] = 40;
		wait3[player] = 30;
		waitt[player] = 15;
	}
	
	// 設定を反映させる
	IsBig[player] = masIsBig;
	BigMove[player] = masBigMove;
	if(masGhost == 2) ghost[player] = 0;
	
	// 初期スピードを設定
	masSpeedUp(player);
}

// ブロック出現
void masMoveInit(int player) {
	int temp;
	
	// 最初のフレームなら
	if(statc[player * 10 + 3] == 0) {
		// レベルアップ処理
		if(masLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		
		if(masLevel[player] % 100 != temp) {
			masLevel[player]++;
			if(masLevel[player] % 100 == temp) PlaySE(se_lvstop);
			masSpeedUp(player);
		}
	}
}

// スコア計算
void masCalcScore(int player, int lines) {
	int i, temp, bo, bai, nextsec, combopts;
	
	if(IsBig[player]) lines = lines * 2;	// BIGでは消去ライン数2倍
	
	bo = (masLevel[player] + lines) / 4 + sdrop[player] + qdrop[player] + qput[player];
	
	if(masVersion >= 6) {
		combopts = cmbpts[player];
	} else if(masVersion <= 2) {
		combopts = combo[player] - 1 + (2 * lines - 1);
	} else if(combo[player] == 1) {
		combopts = 1;
	} else {
		combopts = combo[player] - 2 + (2 * masLastLine[player] - 1);
	}
	bai = lines * combopts;
	
	if(isBravo(player)) {
		// 全消しするとスコア4倍
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		masBravo[player]++;
		bai = bai * 4;
	}
	
	// スコア加算
	masScore[player] = masScore[player] + (bo * bai);
	
	// 段位上昇
	while((masGrade[player] < 17) && (masScore[player] >= masScoreTable[masGrade[player]])) {
		PlaySE(se_rankup);
		masGrade[player]++;
		masGFlash[player] = 120;
	}
	
	masLastLine[player] = lines;
	
	// レベルアップ
	nextsec = masLevel[player] / 100 * 100 + 100;
	if(!masLvUpBonus) masLevel[player] = masLevel[player] + lines;
	else masLevel[player] = masLevel[player] + lines + ((lines >= 3) * (lines - 2));
	
	if(masLevel[player] >= 999) {
		// エンディング
		masLevel[player] = 999;
		timeOn[player] = 0;
		
		// Gm条件判定
		// 13:30:00以内、gmflag1とgmflag2点灯済み、スコア126000点以上
		if((gameTimer[player] <= 48600) && (masScore[player] >= masScoreTable[17]) && 
		   (masGMFlag[player * 2 + 0]) && (masGMFlag[player * 2 + 1]))
		{
			PlaySE(se_ttclear);
			masGrade[player] = 18;
			masGFlash[player] = 120;
			ending[player] = 2;
			ending_timeOn[player] = 1;
			fastroll[player] = 2;
			bgmlv = masBgmNo[2];
			PlayBGM();
		}
		else
		{
			ending[player] = 4;
		}
	} else {
		// レベルストップ音
		if(masLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		if(masLevel[player] % 100 == temp) PlaySE(se_lvstop);
		
		if(masLevel[player] >= nextsec) {
			// レベルアップ音
			PlaySE(se_levelup);
			
			// 背景切り替え
			bgfadesw = 1;
			bgfadebg = nextsec / 100;
			
			// Gmフラグ１成立判定（LV300になったときに段位が1以上）
			if((nextsec == 300) && (masGrade[player] >= 8)) {
				masGMFlag[player * 2 + 0] = 1;
				objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
			}
			
			// Gmフラグ２成立判定（LV500になったときに段位がS4以上）
			if((nextsec == 500) && (masGrade[player] >= 12)) {
				masGMFlag[player * 2 + 1] = 1;
				objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
			}
		}
		
		// スピードアップ
		masSpeedUp(player);
	}
}

// スピードアップ
void masSpeedUp(int player) {
	int index;
	
	// スピードを変える
	if(mas20G) {
		speedtype[player] = 2;
		sp[player] = 5120;
	} else if(masVersion >= 1) {
		if(masVersion >= 8) {
			while(masLevel[player] >= masLevelChange[masLevelIndex[player]]) masLevelIndex[player]++;
		} else if(masVersion >= 7) {
			while(masLevel[player] >= masLevelChange7[masLevelIndex[player]]) masLevelIndex[player]++;
		} else {
			if(masLevel[player] >= masLevelChange7[masLevelIndex[player]]) masLevelIndex[player]++;
		}
		
		if(masVersion >= 8) {
			sp[player] = masLevelTable[masLevelIndex[player]];
		} else {
			sp[player] = masLevelTable7[masLevelIndex[player]];
		}
	} else {
		index = masLevel[player] / 10;
		if(index < 0) index = 0;
		if(index > 50) index = 50;
		sp[player] = masLevelTableOld[index];
	}
	
	// BGMフェードアウト
	if((masLevel[player] >= masFadeLv) && (masLevel[player] < masBgmChange) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// 音楽切り替え
	if((masLevel[player] >= masBgmChange) && (bgmlv == masBgmNo[0])) {
		bgmlv = masBgmNo[1];
		PlayBGM();
	}
	
	// ゴーストを消す
	if((masLevel[player] >= 100) && (masGhost == 0)) {
		ghost[player] = 0;
	}
}

// スコア表示
void masViewScore(int player) {
	int color, color2, x, y, k, zoomx, zoomy, temp;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// 段位
	color2 = (count % 4 / 2) * (is20G(player));
	
	if(masGFlash[player] > 108) {
		// ズーム中
		k = masGFlash[player] - 96;
		zoomx = (90 * k / 12 - 90) / 2;
		zoomy = (24 * k / 12 - 24) / 2;
		k = 65536 * k / 12;
		
		x = foffset[player] + 63 - zoomx;
		y = fyoffset[player] + 40 - zoomy;
		
		if(masGrade[player] < 9) {
			// 9～1
			ExBltRectR(sg_grade, x, y, 0, (color2 * 216) + (masGrade[player] * 24), 90, 24, k, k);
		} else if(masGrade[player] < 18) {
			// S1～S9
			ExBltRectR(sg_grade, x, y, 90, (color2 * 216) + ((masGrade[player] - 9) * 24), 90, 24, k, k);
		} else {
			// Gm
			ExBltRectR(sg_grade, x + 9, y, 450, (color2 * 216) + 180, 90, 32, k, k);
		}
	} else {
		// 通常
		x = foffset[player] + 63;
		y = fyoffset[player] + 40;
		
		if(masGrade[player] < 9) {
			// 9～1
			ExBltRect(sg_grade, x, y, 0, (color2 * 216) + (masGrade[player] * 24), 90, 24);
		} else if(masGrade[player] < 18) {
			// S1～S9
			ExBltRect(sg_grade, x, y, 90, (color2 * 216) + ((masGrade[player] - 9) * 24), 90, 24);
		} else {
			// Gm
			ExBltRect(sg_grade, x + 9, y, 450, (color2 * 216) + 180, 90, 32);
		}
	}
	
	// 目標スコア
	printTinyFont(foffset[player] + 96, fyoffset[player] + 71, "NEXT GRADE");
	printTinyFont(foffset[player] + 96, fyoffset[player] + 78, "AT");
	if(masGrade[player] < 17) {
		sprintf(string[0], "%d", masScoreTable[masGrade[player]]);
	} else {
		sprintf(string[0], ";;;;;;");
	}
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 86, string[0], color);
	printTinyFont(foffset[player] + 96, fyoffset[player] + 96, "POINTS");
	
	// 全消し回数
	if(masBravo[player]) {
		printTinyFont(foffset[player] + 96, fyoffset[player] + 117, "BRAVO");
		sprintf(string[0], "%d", masBravo[player]);
		printSMALLFont(foffset[player] + 96, fyoffset[player] + 125, string[0], color);
	}
	
	// スコア
	printTinyFont(foffset[player] + 96, fyoffset[player] + 135, "POINTS");
	sprintf(string[0], "%d", masScore[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 143, string[0], color);
	
	// レベル（分子）
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(masLevel[player] == -1) sprintf(string[0], "%4d", 0);	// -1なら0と表示する(内部的には最初は-1になっている)
	else sprintf(string[0], "%4d", masLevel[player]);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// レベル（横線）
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	if(masVersion >= 1) {
		temp = sp[player] / 128;
		if(temp > 22) temp = 22;
		ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22 - temp, 143, 22, 1);
	} else {
		if(sp[player] <= 600) {
			ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22 - ((sp[player] * 24) / 660), 143, 22, 1);
		} else {
			ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 0, 143, 22, 1);
		}
	}
	
	// レベル（分母）
	if(masLevel[player] >= 900) sprintf(string[0], "%4d", 999);
	else sprintf(string[0], "%4d", masLevel[player] / 100 * 100 + 100);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, string[0], color);
	
	// タイム
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
}

// BGM読み込み
void masLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 3; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/3)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(masBgmNo[i]);
		}
	}
}

// エンディング終了
void masExcellent(int player, int *param) {
	onRecord[player] = 0;
	statc[player * 10 + 1]++;
	
	if(masGrade[player] >= 18) {
		// YOU ARE GRAND MASTER!!
		param[0] = 1;
		
		// 花火
		if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 30)) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			statc[player * 10 + 2]++;
		}
	} else {
		// EXCELLENT
		param[0] = 0;
		
		if(statc[player * 10] < 220) {
			// 花火
			if((statc[player * 10 + 1] % 40 == 0) && (statc[player * 10 + 2] < 4)) {
				objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
				statc[player * 10 + 2]++;
			}
			
			// ボタンでスキップ
			if(getPushState(player, 4)) {
				statc[player * 10] = 219;
			}
		} else {
			if(statc[player * 10] == 220) objectClearPl(player);	// 花火を消す
			
			printTinyFont(foffset[player] + 10, fyoffset[player] + 130, "TRY AGAIN TO BE");
			printTinyFont(foffset[player] + 12, fyoffset[player] + 137, "A GRAND MASTER");
			
			// ボタンでスキップ
			if(getPushState(player, 4)) {
				statc[player * 10] = 600;
			}
		}
	}
}

// 時間を進める
void masIncrementTime(int player) {
	int i;
	
	// ロール終了
	if((ending[player] == 2) && (edrec[player] >= 60 * 60)) {
		ending[player] = 3;
		stat[player] = 10;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
	
	// 段位が光る演出の時間を減らす
	if(masGFlash[player] > 0) masGFlash[player]--;
}

// 設定画面
void masSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(masLoadConfig() == 0) masSaveConfig();
	
	// ランキングを読み込み
	if(masLoadRanking(player) == 0) masInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "MASTER-EASY OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",            7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",       7 * (cursor == 1));
		printFontGrid(2, 5, "GHOST BLOCK",    7 * (cursor == 2));
		printFontGrid(2, 6, "LEVEL UP BONUS", 7 * (cursor == 3));
		printFontGrid(2, 7, "20G MODE",       7 * (cursor == 4));
		printFontGrid(2, 8, "START LEVEL",    7 * (cursor == 5));
		
		// 設定値表示
		if(!masIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!masBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(masGhost == 0) sprintf(string[0], "LV100");
		else if(masGhost == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(!masLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(!mas20G) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		sprintf(string[0], "%d", masStartLevel);
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		// カーソル移動
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 5;
			if(cursor > 5) cursor = 0;
		}
		
		// 値を変更
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) masIsBig = !masIsBig;
			if(cursor == 1) masBigMove = !masBigMove;
			if(cursor == 2) {
				masGhost = masGhost + move;
				if(masGhost < 0) masGhost = 2;
				if(masGhost > 2) masGhost = 0;
			}
			if(cursor == 3) masLvUpBonus = !masLvUpBonus;
			if(cursor == 4) mas20G = !mas20G;
			if(cursor == 5) {
				masStartLevel = masStartLevel + (move * 100);
				if(masStartLevel < 0) masStartLevel = 900;
				if(masStartLevel > 900) masStartLevel = 0;
			}
		}
		
		// キャンセル
		if(getPushState(player, 5)) {
			PlaySE(se_move);
			param[0] = 0;
			return;
		}
		
		// 決定
		if(getPushState(player, 4)) {
			PlayWave(se_kettei);
			masSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			masViewRanking(player);
		}
	}
}

// 結果表示
void masResult(int player) {
	if(statc[player * 10] == 0) {
		// ランキング登録
		statc[player * 10 + 1] = masRegistRanking(player);
		if(statc[player * 10 + 1] != -1) masSaveRanking(player);
		
		// 裏段位判定
		statc[player * 10 + 2] = checkSecretGrade(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "GRADE");
	sprintf(string[0], "%13s", masStrGradeName[masGrade[player]]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "SCORE");
	sprintf(string[0], "%13d", masScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "LEVEL");
	sprintf(string[0], "%13d", masLevel[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 139, "TIME");
	getTime(gameTimer[player]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 147, string[1], 0);
	
	if(statc[player * 10 + 1] != -1) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 159, "RANK");
		sprintf(string[0], "%13d", statc[player * 10 + 1] + 1);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
	}
	
	if(statc[player * 10 + 2] >= 4) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 179, "SECRET GRADE");
		sprintf(string[0], "%13s", masStrGradeName[statc[player * 10 + 2]]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 187, string[0], 0);
	}
}

// リプレイ保存
void masSaveReplay(int player) {
	saveBuf[900] = masIsBig;
	saveBuf[901] = masBigMove;
	saveBuf[902] = masGhost;
	saveBuf[903] = masLvUpBonus;
	saveBuf[904] = masVersion;
	saveBuf[905] = masLevel[player];
	saveBuf[906] = masScore[player];
	saveBuf[907] = masGrade[player];
	saveBuf[908] = masBravo[player];
	saveBuf[909] = mas20G;
	saveBuf[910] = masStartLevel;
}

// リプレイ読み込み
void masLoadReplay(int player) {
	masIsBig = saveBuf[900];
	masBigMove = saveBuf[901];
	masGhost = saveBuf[902];
	masLvUpBonus = saveBuf[903];
	masVersion = saveBuf[904];
	mas20G = saveBuf[909];
	masStartLevel = saveBuf[910];
	
	masPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void masReplayDetail(int number) {
	printFontGrid(1, 4, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[904]);
	printFontGrid(22, 4, string[0], 0);
	
	if(saveBuf[904] >= 2) {
		printFontGrid(1, 6, "GRADE", 0);
		if((saveBuf[907] >= 0) && (saveBuf[907] <= 18)) {
			printFontGrid(22, 6, masStrGradeName[saveBuf[907]], 0);
		} else {
			printFontGrid(22, 6, "???", 0);
		}
		
		printFontGrid(1, 7, "SCORE", 0);
		sprintf(string[0], "%d", saveBuf[906]);
		printFontGrid(22, 7, string[0], 0);
		
		printFontGrid(1, 8, "LEVEL", 0);
		sprintf(string[0], "%d", saveBuf[905]);
		printFontGrid(22, 8, string[0], 0);
		
		printFontGrid(1, 9, "BRAVO", 0);
		sprintf(string[0], "%d", saveBuf[908]);
		printFontGrid(22, 9, string[0], 0);
	}
	
	printFontGrid(1, 11, "BIG", 0);
	if(!saveBuf[900]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "BIG MOVE", 0);
	if(!saveBuf[901]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 12, string[0], 0);
	
	printFontGrid(1, 13, "GHOST BLOCK", 0);
	if(saveBuf[902] == 0) sprintf(string[0], "LV100");
	else if(saveBuf[902] == 1) sprintf(string[0], "ON");
	else sprintf(string[0], "OFF");
	printFontGrid(22, 13, string[0], 0);
	
	printFontGrid(1, 14, "LEVEL UP BONUS", 0);
	if(!saveBuf[903]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 14, string[0], 0);
	
	printFontGrid(1, 15, "20G MODE", 0);
	if(!saveBuf[909]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 15, string[0], 0);
	
	printFontGrid(1, 16, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[910]);
	printFontGrid(22, 16, string[0], 0);
}

// 設定を保存
void masSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x5453414D;
	saveBuf[3] = 0x31455245;
	
	// 設定内容
	saveBuf[4] = masIsBig;
	saveBuf[5] = masBigMove;
	saveBuf[6] = masGhost;
	saveBuf[7] = masLvUpBonus;
	saveBuf[8] = mas20G;
	saveBuf[9] = masStartLevel;
	
	SaveFile("config/MASTER_EASY_CONFIG.SAV", &saveBuf, 100 * 4);
}

// 設定を読み込み
int masLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/MASTER_EASY_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x5453414D) return 0;
	if(saveBuf[3] != 0x31455245) return 0;
	
	// 設定内容
	masIsBig = saveBuf[4];
	masBigMove = saveBuf[5];
	masGhost = saveBuf[6];
	masLvUpBonus = saveBuf[7];
	mas20G = saveBuf[8];
	masStartLevel = saveBuf[9];
	
	return 1;
}

// ランキング保存
void masSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ランキング内容
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 10) + 0] = masRankingGrade[i];
		saveBuf[1 + (i * 10) + 1] = masRankingLevel[i];
		saveBuf[1 + (i * 10) + 2] = masRankingTime[i];
		saveBuf[1 + (i * 10) + 3] = masRankingYear[i];
		saveBuf[1 + (i * 10) + 4] = masRankingMonth[i];
		saveBuf[1 + (i * 10) + 5] = masRankingDay[i];
		saveBuf[1 + (i * 10) + 6] = masRankingHour[i];
		saveBuf[1 + (i * 10) + 7] = masRankingMinute[i];
		saveBuf[1 + (i * 10) + 8] = masRankingSecond[i];
	}
	
	sprintf(string[0], "config/MASTER_EASY_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 111 * 4);
}

// ランキング読み込み
int masLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/MASTER_EASY_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 111 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ランキング内容
	for(i = 0; i < 10; i++) {
		masRankingGrade[i] = saveBuf[1 + (i * 10) + 0];
		masRankingLevel[i] = saveBuf[1 + (i * 10) + 1];
		masRankingTime[i] = saveBuf[1 + (i * 10) + 2];
		masRankingYear[i] = saveBuf[1 + (i * 10) + 3];
		masRankingMonth[i] = saveBuf[1 + (i * 10) + 4];
		masRankingDay[i] = saveBuf[1 + (i * 10) + 5];
		masRankingHour[i] = saveBuf[1 + (i * 10) + 6];
		masRankingMinute[i] = saveBuf[1 + (i * 10) + 7];
		masRankingSecond[i] = saveBuf[1 + (i * 10) + 8];
	}
}

// ランキング初期化
int masInitRanking() {
	int i;
	
	for(i = 0; i < 10; i++) {
		masRankingGrade[i] = 0;
		masRankingLevel[i] = 0;
		masRankingTime[i] = 0;
		masRankingYear[i] = 0;
		masRankingMonth[i] = 0;
		masRankingDay[i] = 0;
		masRankingHour[i] = 0;
		masRankingMinute[i] = 0;
		masRankingSecond[i] = 0;
	}
}

// ランキング登録
int masRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (masLvUpBonus) || (mas20G) || (masStartLevel)) return -1;
	
	for(i = 0; i < 10; i++) {
		// ランクイン
		if(
		    (masGrade[player] > masRankingGrade[i]) || 
		    ((masGrade[player] == masRankingGrade[i]) && (masLevel[player] > masRankingLevel[i])) || 
		    ((masGrade[player] == masRankingGrade[i]) && (masLevel[player] == masRankingLevel[i]) && (gameTimer[player] < masRankingTime[i]))
		  )
		{
			// ランキングをずらす
			for(j = 9; j > i; j--) {
				masRankingGrade[j] = masRankingGrade[j - 1];
				masRankingLevel[j] = masRankingLevel[j - 1];
				masRankingTime[j] = masRankingTime[j - 1];
				masRankingYear[j] = masRankingYear[j - 1];
				masRankingMonth[j] = masRankingMonth[j - 1];
				masRankingDay[j] = masRankingDay[j - 1];
				masRankingHour[j] = masRankingHour[j - 1];
				masRankingMinute[j] = masRankingMinute[j - 1];
				masRankingSecond[j] = masRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			masRankingGrade[i] = masGrade[player];
			masRankingLevel[i] = masLevel[player];
			masRankingTime[i] = gameTimer[player];
			
			GetDateAndTime(&timebuf);
			masRankingYear[i] = timebuf[0];
			masRankingMonth[i] = timebuf[1];
			masRankingDay[i] = timebuf[2];
			masRankingHour[i] = timebuf[4];
			masRankingMinute[i] = timebuf[5];
			masRankingSecond[i] = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// ランキング表示
void masViewRanking(int player) {
	int i, cursor, move, erasemode;
	cursor = 0;
	move = 0;
	erasemode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "MASTER-EASY MODE RANKING", 6);
		printFontGrid(1, 3, "RANK GRADE LEVEL TIME", 4);
		
		for(i = 0; i < 10; i++) {
			if(masRankingLevel[i] >= 999) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, 0, 320, 2);
			
			if(i == 0) sprintf(string[0], " 1ST");
			if(i == 1) sprintf(string[0], " 2ND");
			if(i == 2) sprintf(string[0], " 3RD");
			if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
			printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
			
			if((masRankingGrade[i] >= 0) && (masRankingGrade[i] < 19)) {
				printFontGrid(6, 4 + i, masStrGradeName[masRankingGrade[i]], 7 * (cursor == i));
			} else {
				printFontGrid(6, 4 + i, "???", 7 * (cursor == i));
			}
			
			sprintf(string[0], "%d", masRankingLevel[i]);
			printFontGrid(12, 4 + i, string[0], 7 * (cursor == i));
			
			getTime(masRankingTime[i]);
			printFontGrid(18, 4 + i, string[0], 7 * (cursor == i));
		}
		
		for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
		
		if(!erasemode) {
			// 日付と時刻
			sprintf(string[0],
			        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
			        masRankingYear[cursor], masRankingMonth[cursor], masRankingDay[cursor],
			        masRankingHour[cursor], masRankingMinute[cursor], masRankingSecond[cursor]);
			printFontGrid(1, 26, string[0], 0);
			
			printFontGrid(1, 28, "A/B:EXIT F:ERASE ALL", 6);
			
			// カーソル移動
			padRepeat2(player);
			
			move = 0;
			if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
				move = getPressState(player, 1) - getPressState(player, 0);
			
			if(move) {
				PlaySE(se_move);
				cursor = cursor + move;
				if(cursor < 0) cursor = 9;
				if(cursor > 9) cursor = 0;
			}
			
			// 戻る
			if(getPushState(player, 4) || getPushState(player, 5)) {
				PlaySE(se_move);
				return;
			}
			
			// ランキング消去モードへ
			if(getPushState(player, 9)) {
				PlaySE(se_shaki);
				erasemode = 1;
			}
		} else {
			printFontGrid(1, 24, "ERASE ALL RECORDS?", 2);
			printFontGrid(1, 26, "A:YES / B:NO", 2);
			
			// 消去
			if(getPushState(player, 4)) {
				PlayWave(se_kettei);
				masInitRanking();
				masSaveRanking(player);
				erasemode = 0;
			}
			
			// 戻る
			if(getPushState(player, 5)) {
				PlaySE(se_move);
				erasemode = 0;
			}
		}
	}
}
