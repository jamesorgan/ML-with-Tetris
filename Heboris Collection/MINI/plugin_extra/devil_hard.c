//DEVIL-HARD
//prefix:dvh

// バージョン
int dvhVersion;			// バージョン番号（古いリプレイ再生用）
int dvhCVersion = 3;	// 現在のバージョン

// レベルアップテーブル   000, 100, 200, 300, 400, 500, 600, 700, 800, 900,1000,1100,1200,1300
int dvhWait1Table[14] = {  11,   7,   6,   4,   4,   3,   3,   3,   3,   3,   4,   3,   3,   3};
int dvhWait2Table[14] = {   8,   5,   4,   4,   4,   3,   3,   3,   3,   3,   2,   2,   1,   1};
int dvhWait3Table[14] = {  20,  20,  18,  14,  14,  14,  12,  12,  12,  12,  12,  11,   9,   9};
int dvhWaittTable[14] = {  10,  10,   9,   7,   7,   7,   6,   6,   6,   6,   6,   6,   5,   5};

// 旧レベルアップテーブル
int dvhWait1TableOld[14] = {  10,   9,   8,   7,   6,   5,   5,   4,   4,   3,   5,   4,   3,   5};
int dvhWait2TableOld[14] = {   4,   4,   4,   4,   4,   3,   3,   3,   3,   3,   2,   2,   1,   3};
int dvhWait3TableOld[14] = {  20,  20,  19,  19,  18,  17,  16,  14,  13,  13,  13,  12,  12,  13};
int dvhWaittTableOld[14] = {  10,  10,  10,   9,   9,   9,   9,   8,   7,   7,   6,   6,   6,   7};

// BGM
int dvhBgmListTable[5]   = {2, 3, 4, 5, 6};			// 使用するBGM
int dvhBgmFadeTable[4]   = {485, 685, 985, 10000};	// フェードアウトするレベル
int dvhBgmChangeTable[4] = {500, 700, 1000, 10000};	// 切り替えるレベル
int dvhBgmIndex          = 0;						// 現在のBGM番号

// 段位の表示名
str dvhStrGradeName[15] = 
{
	"1", "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13", "GM"
};

// 裏段位の表示名
str dvhStrSecretGradeName[19] = 
{
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  0～ 8
	"M1", "M2", "M3", "M4", "M5", "M6", "M7", "M8", "M9",	//  9～17
	"GM"													// 18
};

// 変数
int dvhModeNo = -1;			// モード番号

int dvhLevel[2];			// レベル
int dvhScore[2];			// スコア
int dvhGrade[2];			// 段位
int dvhEndFlag[2];			// クリアフラグ

int dvhRiseCount[2];		// せり上がり用カウンタ

int dvhSTimer[2];			// セクションタイマー
int dvhSkill[2];			// ヘボリス回数

int dvhSectionTime[13 * 2];	// このプレイのセクションタイム

int dvhMedalStat[4 * 2];	// メダルの状態(0=なし 1=銅 2=銀 3=金)
int dvhMedalAnim[4 * 2];	// メダル獲得アニメーション用カウンタ

int dvhTSpinFrame[2];		// T-SPIN表示の残り時間
int dvhRegretFrame[2];		// REGRET表示の残り時間

int dvhIsBig = 0;			// BIGかどうか
int dvhBigMove = 1;			// BIG時の横移動単位
int dvhLvUpBonus = 1;		// レベルアップボーナス
int dvhTSpin = 1;			// T-SPINの種類
int dvhTorikan = 14400;		// LV500とりカン基準タイム (4:00:00)
int dvhRiseInterval = 20;	// せり上がり間隔（0で無し）
int dvhStartLevel = 0;		// スタート時のレベル

// ランキング変数
int dvhRankingGrade[10];			// 段位
int dvhRankingLevel[10];			// レベル
int dvhRankingTime[10];				// タイム
int dvhRankingEnd[10];				// クリアフラグ
int dvhRankingMedal[4 * 10];		// メダル
int dvhRankingYear[10];				// ランクイン日時（年）
int dvhRankingMonth[10];			// ランクイン日時（月）
int dvhRankingDay[10];				// ランクイン日時（日）
int dvhRankingHour[10];				// ランクイン日時（時）
int dvhRankingMinute[10];			// ランクイン日時（分）
int dvhRankingSecond[10];			// ランクイン日時（秒）

// セクションタイムランキング変数
int dvhRankingSectionTime[13];		// タイム
int dvhRankingSectionEnd[13];		// クリアフラグ
int dvhRankingSectionYear[13];		// ランクイン日時（年）
int dvhRankingSectionMonth[13];		// ランクイン日時（月）
int dvhRankingSectionDay[13];		// ランクイン日時（日）
int dvhRankingSectionHour[13];		// ランクイン日時（時）
int dvhRankingSectionMinute[13];	// ランクイン日時（分）
int dvhRankingSectionSecond[13];	// ランクイン日時（秒）

// イベント発生
void dvhPluginEvent(int player, int event, int *param) {
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != dvhModeNo)) return;
	
	if(event == 0) {
		dvhModeNo = addModePlugin("DEVIL-HARD");	// モードを登録する
	} else if(event == 7) {
		if(!ending[player]) dvhMoveInit(player);	// ブロック出現
	} else if(event == 10) {
		dvhRiseField(player);	// せり上がり
	} else if(event == 12) {
		if(!ending[player]) dvhCalcScore(player, param[0]);	// スコア計算
	} else if(event == 15) {
		dvhViewScore(player);	// スコア表示
	} else if(event == 17) {
		dvhSetting(player, param);	// 設定画面
	} else if(event == 18) {
		dvhPlayerInitial(player);	// 初期化処理
	} else if(event == 21) {
		dvhResult(player, param);	// 結果表示
	} else if(event == 24) {
		dvhEndingStart(player);	// エンディング突入
	} else if(event == 25) {
		dvhExcellent(player, param);	// エンディング終了
	} else if(event == 28) {
		dvhIncrementTime(player);	// 時間を進める
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		dvhSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		dvhLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		dvhLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		dvhReplayDetail(param[0]);	// リプレイ詳細
	}
}

// 初期化処理
void dvhPlayerInitial(int player) {
	int i;
	
	// バージョン設定
	if(!playback) dvhVersion = dvhCVersion;
	
	// 変数を初期化
	if(dvhVersion >= 3) {
		if(dvhStartLevel > 0) dvhLevel[player] = dvhStartLevel;
		else dvhLevel[player] = -1;
		
		if(dvhLevel[player] >= 1000) oblk_spawn[player] = 1;
		
		backno = dvhLevel[player] / 100;
		if(backno > 9) backno = 9;
	} else {
		dvhLevel[player] = -1;
	}
	dvhScore[player] = 0;
	dvhGrade[player] = 0;
	dvhEndFlag[player] = 0;
	dvhRiseCount[player] = 0;
	dvhSTimer[player] = 0;
	dvhSkill[player] = 0;
	dvhTSpinFrame[player] = 0;
	dvhRegretFrame[player] = 0;
	
	for(i = 0; i < 4; i++) {
		dvhMedalStat[player * 4 + i] = 0;
		dvhMedalAnim[player * 4 + i] = -1;
	}
	
	for(i = 0; i < 13; i++) dvhSectionTime[i + player * 13] = 0;
	
	dvhBgmIndex = 0;
	bgmlv = dvhBgmListTable[0];
	framecolor[player] = 2;
	enable_combo[player] = 1;
	
	// 設定を反映させる
	IsBig[player] = dvhIsBig;
	BigMove[player] = dvhBigMove;
	tspin_type[player] = dvhTSpin;
	
	// 初期スピードを設定
	dvhSpeedUp(player);
}

// スピードアップ
void dvhSpeedUp(int player) {
	int temp, index;
	
	// 20G
	sp[player] = 1200;
	
	// スピードを変える
	index = dvhLevel[player] / 100;
	if(index < 0) index = 0;
	if(index > 13) index = 13;
	
	if(dvhVersion >= 2) {
		wait1[player] = dvhWait1Table[index];
		wait2[player] = dvhWait2Table[index];
		wait3[player] = dvhWait3Table[index];
		waitt[player] = dvhWaittTable[index];
	} else {
		wait1[player] = dvhWait1TableOld[index];
		wait2[player] = dvhWait2TableOld[index];
		wait3[player] = dvhWait3TableOld[index];
		waitt[player] = dvhWaittTableOld[index];
	}
	
	// BGMフェードアウト
	if((dvhLevel[player] >= dvhBgmFadeTable[dvhBgmIndex]) && (dvhLevel[player] < dvhBgmChangeTable[dvhBgmIndex]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// BGM切り替え
	temp = 0;
	while(dvhLevel[player] >= dvhBgmChangeTable[dvhBgmIndex]) {
		dvhBgmIndex++;
		bgmlv = dvhBgmListTable[dvhBgmIndex];
		if(onRecord[player]) temp = 1;
	}
	if(temp) PlayBGM();
}

// ブロック出現
void dvhMoveInit(int player) {
	// 最初のフレームなら
	if(statc[player * 10 + 3] == 0) {
		// レベルアップ処理
		if(dvhLevel[player] % 100 != 99) {
			dvhLevel[player]++;
			if(dvhLevel[player] % 100 == 99) PlaySE(se_lvstop);
			dvhSpeedUp(player);
		}
		
		// せり上がりカウンタ+1
		if((dvhLevel[player] >= 500) && (dvhLevel[player] < 1000)) dvhRiseCount[player]++;
	}
}

// スコア計算
void dvhCalcScore(int player, int lines) {
	int i, temp, bo, bai, nextsec, lv;
	
	lv = dvhLevel[player];	// 上がる前のレベル
	
	// ヘボリス回数増加
	if(lines >= 4) {
		dvhSkill[player]++;
		
		// SKメダル獲得
		if((dvhSkill[player] == 5) || (dvhSkill[player] == 10) || (dvhSkill[player] == 17)) {
			PlaySE(se_medal);
			dvhMedalStat[player * 4 + 3]++;
			dvhMedalAnim[player * 4 + 3] = 0;
		}
	}
	
	// COメダル獲得
	if(combo2[player] == 4) {
		if(dvhMedalStat[player * 4 + 2] < 1) {
			PlaySE(se_medal);
			dvhMedalStat[player * 4 + 2] = 1;
			dvhMedalAnim[player * 4 + 2] = 0;
		}
	} else if(combo2[player] == 5) {
		if(dvhMedalStat[player * 4 + 2] < 2) {
			PlaySE(se_medal);
			dvhMedalStat[player * 4 + 2] = 2;
			dvhMedalAnim[player * 4 + 2] = 0;
		}
	} else if(combo2[player] == 7) {
		if(dvhMedalStat[player * 4 + 2] < 3) {
			PlaySE(se_medal);
			dvhMedalStat[player * 4 + 2] = 3;
			dvhMedalAnim[player * 4 + 2] = 0;
		}
	}
	
	// レベルアップ
	nextsec = dvhLevel[player] / 100 * 100 + 100;
	if(!dvhLvUpBonus) dvhLevel[player] = dvhLevel[player] + lines;
	else dvhLevel[player] = dvhLevel[player] + lines + ((lines >= 3) * (lines - 2));
	
	if(dvhLevel[player] >= 1300) {
		// エンディング
		dvhLevel[player] = 1300;
		ending[player] = 1;
		timeOn[player] = 0;
		dvhSpeedUp(player);
		dvhGradeUp(player, (nextsec / 100) - 1);
		dvhEndFlag[player] = 1;
		
		// GM条件を満たしている場合は流れ星出現
		if((dvhGrade[player] == 13) && (gameTimer[player] <= 21000)) {
			objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
		}
	} else if((dvhLevel[player] >= nextsec) && (nextsec == 500) && (gameTimer[player] > dvhTorikan) && (dvhTorikan > 0)) {
		// LV500とりカン
		dvhLevel[player] = 500;
		ending[player] = 4;
		timeOn[player] = 0;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		stat[player] = 10;
		dvhGradeUp(player, (nextsec / 100) - 1);
	} else if((dvhLevel[player] >= nextsec) && (nextsec == 1000) && (gameTimer[player] > dvhTorikan * 2) && (dvhTorikan > 0)) {
		// LV1000とりカン
		dvhLevel[player] = 1000;
		ending[player] = 4;
		timeOn[player] = 0;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		stat[player] = 10;
		dvhGradeUp(player, (nextsec / 100) - 1);
	} else {
		// レベルストップ音
		if(dvhLevel[player] % 100 == 99) PlaySE(se_lvstop);
		
		if(dvhLevel[player] >= nextsec) {
			// レベルアップ音
			PlaySE(se_levelup);
			
			// 背景切り替え
			if(dvhLevel[player] < 1000) {
				bgfadesw = 1;
				bgfadebg = nextsec / 100;
			}
			
			dvhGradeUp(player, (nextsec / 100) - 1);
			
			// []出現
			if(dvhLevel[player] >= 1000) oblk_spawn[player] = 1;
		}
		
		// スピードアップ
		dvhSpeedUp(player);
	}
	
	// スコア計算
	if(dvhVersion >= 1) {
		temp = wait3[player] - bactivetime[player];
		if(temp < 0) temp = 0;
		
		bo = ((lv + lines) / 4 + (sdrop[player] / 2) + qdrop[player] + qput[player]) * lines * cmbpts[player] + (dvhLevel[player] / 2) + temp;
		bai = 1;
	} else {
		bo = (lv + lines) / 4 + sdrop[player] + qdrop[player] + qput[player];
		bai = (lines * 2 - 1 + cmbpts[player] - (lines * 2 - 2)) * lines;
	}
	
	if(isBravo(player)) {
		// 全消しするとスコア4倍
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		if(dvhVersion <= 0) bai = bai * 4;
		
		// ACメダル獲得
		if(dvhMedalStat[player * 4 + 1] < 3) {
			PlaySE(se_medal);
			dvhMedalStat[player * 4 + 1]++;
			dvhMedalAnim[player * 4 + 1] = 0;
		}
	}
	
	// T-SPINで2倍
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		dvhTSpinFrame[player] = 120;
		if(dvhVersion <= 0) bai = bai * 2;
	}
	
	// スコア加算
	dvhScore[player] = dvhScore[player] + (bo * bai);
}

// STメダル獲得／段位上昇
void dvhGradeUp(int player, int section) {
	// セクションタイム記録
	dvhSectionTime[section + player * 13] = dvhSTimer[player];
	
	// STメダル獲得
	if((!playback) && (!dvhIsBig) && (dvhLvUpBonus) && (!dvhStartLevel)) {
		if((dvhSTimer[player] < dvhRankingSectionTime[section]) && (dvhMedalStat[player * 4 + 0] < 3)) {
			PlaySE(se_medal);
			dvhMedalStat[player * 4 + 0] = 3;
			dvhMedalAnim[player * 4 + 0] = 0;
		} else if((dvhSTimer[player] < dvhRankingSectionTime[section] + 300) && (dvhMedalStat[player * 4 + 0] < 2)) {
			PlaySE(se_medal);
			dvhMedalStat[player * 4 + 0] = 2;
			dvhMedalAnim[player * 4 + 0] = 0;
		} else if((dvhSTimer[player] < dvhRankingSectionTime[section] + 600) && (dvhMedalStat[player * 4 + 0] < 1)) {
			PlaySE(se_medal);
			dvhMedalStat[player * 4 + 0] = 1;
			dvhMedalAnim[player * 4 + 0] = 0;
		}
	}
	
	// 段位上昇
	if(dvhSTimer[player] <= 3690) {
		dvhGrade[player]++;
	} else {
		PlaySE(se_regret);
		dvhRegretFrame[player] = 180;
	}
	
	dvhSTimer[player] = 0;
}

// 時間を進める
void dvhIncrementTime(int player) {
	int i;
	
	// セクションタイム増加
	if(timeOn[player]) dvhSTimer[player]++;
	
	// ロール終了
	if((ending[player] == 2) && (edrec[player] >= 60 * 60)) {
		// GM条件達成
		if((dvhGrade[player] == 13) && (gameTimer[player] <= 21000)) {
			dvhGrade[player] = 14;
		}
		ending[player] = 3;
		stat[player] = 10;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
	
	if(dvhRegretFrame[player] > 0)
		dvhRegretFrame[player]--;	// REGRET表示時間減少
	else if(dvhTSpinFrame[player] > 0)
		dvhTSpinFrame[player]--;	// T-SPIN表示時間減少
}

// せり上がり
void dvhRiseField(int player) {
	int i;
	
	if(dvhRiseInterval == 0) return;
	
	if((dvhLevel[player] >= 500) && (dvhLevel[player] < 1000) && (dvhRiseCount[player] >= dvhRiseInterval)) {
		// 最下段をコピーする
		for(i = 0; i < 10; i++) {
			fldu[i + player * 220] = (fld[i + 21 * 10 + player * 220] != 0);
		}
		upLines[player] = 1;
		dvhRiseCount[player] = 0;
	}
}

// エンディング突入
void dvhEndingStart(int player) {
	int i;
	
	for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	
	if(dvhLevel[player] >= 1300) {
		ending[player] = 2;
		stat[player] = 4;
		ending_timeOn[player] = 1;
		
		IsBig[player] = 1;
		BigMove[player] = 1;
		
		bgmlv = dvhBgmListTable[4];
		PlayBGM();
	} else {
		ending[player] = 3;
	}
}

// エンディング終了
void dvhExcellent(int player, int *param) {
	onRecord[player] = 0;
	statc[player * 10 + 1]++;
	
	if(dvhGrade[player] >= 14) {
		// GM
		param[0] = 1;
		dvhEndFlag[player] = 2;
		
		// 花火
		if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 30)) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			statc[player * 10 + 2]++;
		}
	} else if(dvhLevel[player] >= 1300) {
		// 完全クリア
		printTinyFont(foffset[player] + 22, fyoffset[player] + 116, "DEVIL MODE");
		printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
		dvhEndFlag[player] = 2;
		
		// 花火
		if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 30)) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			statc[player * 10 + 2]++;
		}
	} else {
		// とりカン
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
			
			printFont(foffset[player] + 12, fyoffset[player] + 112, "BUT...", 0);
			printFont(foffset[player] + 12, fyoffset[player] + 120, "LET'S GO", 0);
			printFont(foffset[player] + 12, fyoffset[player] + 128, "BETTER", 0);
			printFont(foffset[player] + 12, fyoffset[player] + 136, "NEXT TIME", 0);
			
			// ボタンでスキップ
			if(getPushState(player, 4)) {
				statc[player * 10] = 600;
			}
		}
	}
}

// BGM読み込み
void dvhLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 5; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/5)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(dvhBgmListTable[i]);
		}
	}
}

// スコアを表示
void dvhViewScore(int player) {
	int i, x, y, color, kind;
	color = (count % 4 / 2) * 7;
	
	// メダル（通常）
	for(i = 0; i < 4; i++) {
		if((dvhMedalAnim[player * 4 + i] < 0) || (dvhMedalAnim[player * 4 + i] > 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 17;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			if(i == 0) kind = 1;
			if(i == 1) kind = 0;
			if(i == 2) kind = 5;
			if(i == 3) kind = 2;
			dvhDrawMedal(x, y, kind, dvhMedalStat[player * 4 + i], dvhMedalAnim[player * 4 + i]);
		}
	}
	
	// メダル（アニメ中）
	for(i = 0; i < 4; i++) {
		if((dvhMedalAnim[player * 4 + i] >= 0) && (dvhMedalAnim[player * 4 + i] <= 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 17;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			if(i == 0) kind = 1;
			if(i == 1) kind = 0;
			if(i == 2) kind = 5;
			if(i == 3) kind = 2;
			dvhDrawMedal(x, y, kind, dvhMedalStat[player * 4 + i], dvhMedalAnim[player * 4 + i]);
			dvhMedalAnim[player * 4 + i]++;
		}
	}
	
	// レベル（分子）
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(dvhLevel[player] == -1) sprintf(string[0], "%4d", 0);	// -1なら0と表示する(内部的には最初は-1になっている)
	else sprintf(string[0], "%4d", dvhLevel[player]);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// レベル（横線）
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 0, 143, 22, 1);
	
	// レベル（分母）
	if(ending[player]) sprintf(string[0], "%4d", dvhLevel[player]);
	else sprintf(string[0], "%4d", dvhLevel[player] / 100 * 100 + 100);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, string[0], color);
	
	// タイム
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
	
	if(dvhRegretFrame[player] > 0)
		printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "REGRET");	// REGRET表示
	else if(dvhTSpinFrame[player] > 0)
		printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "T-SPIN");	// T-SPIN表示
}

// メダルを表示
void dvhDrawMedal(int x, int y, int kind, int color, int anim) {
	int i, j, k;
	
	if(color == 0) return;
	
	if((anim >= 0) && (anim < 16)) {
		if(anim <= 8) {
			k = anim;
			i = (16 * k / 2 - 16) / 2;
			j = (12 * k / 2 - 12) / 2;
			k = 65536 * k / 2;
		} else {
			k = 16 - anim;
			i = (16 * k / 3 - 16) / 2;
			j = (12 * k / 3 - 12) / 2;
			k = 65536 * k / 3;
			
			if(k < 65536) {
				k = 65536;
				i = 0;
				j = 0;
			}
		}
		
		ExBltRectR(sg_medal[1], x - i, y - j, kind * 16, color * 12, 16, 12, k, k);
	} else {
		ExBltRect(sg_medal[1], x, y, kind * 16, color * 12, 16, 12);
	}
}

// 結果表示
void dvhResult(int player, int *param) {
	if(statc[player * 10 + 1] < 300) {
		// 通常の処理をスキップする
		param[0] = 1;
		
		if(statc[player * 10 + 1] == 0) {
			// 「あなたの段位は」の文字
			ExTextSize(0, 10);
			TextColor(0, 255, 255, 255);
			TextBackColorDisable(0);
			if(!english) {
				TextOut(0, "あなたの段位は");
			} else {
				TextOut(0, "Your Grade is");
			}
			ExTextLayerOn(0, foffset[player] + 13, fyoffset[player] + 92);
			
			// ランキング登録
			statc[player * 10 + 2] = dvhRegistRanking(player);
			statc[player * 10 + 3] = dvhUpdateSectionTimeRanking(player);
			if((statc[player * 10 + 2] != -1) || (statc[player * 10 + 3] != 0)) dvhSaveRanking(player);
			
			// 裏段位判定
			statc[player * 10 + 4] = checkSecretGrade(player);
		}
		
		// 段位表示
		if(dvhGrade[player] == 0)		// 1
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108,   0, ((count % 4 / 2) * 216) + 192, 90, 24);
		else if(dvhGrade[player] < 10)	// S1～S9
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108,  90, ((count % 4 / 2) * 216) + ((dvhGrade[player] -  1) * 24), 90, 24);
		else if(dvhGrade[player] < 14)	// S10～S13
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108, 360, ((count % 4 / 2) * 216) + ((dvhGrade[player] - 10) * 24), 90, 24);
		else							// GM
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108, 270, ((count % 4 / 2) * 216) + 120, 90, 48);
		
		// ボタンでスキップ
		if(getPushState(player, 4) && (statc[player * 10 + 1] >= 60)) {
			statc[player * 10 + 1] = 300;
		}
		
		// カウンタ増加
		statc[player * 10 + 1]++;
		
		// 文字を消す
		if(statc[player * 10 + 1] >= 300) TextLayerOff(0);
	} else {
		// 結果表示
		printSMALLFont(foffset[player] + 21, fyoffset[player] + 45, "PLAY DATA", 4);
		
		printTinyFont(foffset[player] + 8, fyoffset[player] + 59, "SCORE");
		sprintf(string[0], "%13d", dvhScore[player]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 67, string[0], 0);
		
		printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LEVEL");
		sprintf(string[0], "%13d", dvhLevel[player]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
		
		printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "TIME");
		getTime(gameTimer[player]);
		sprintf(string[1], "%13s", string[0]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[1], 0);
		
		if(statc[player * 10 + 2] != -1) {
			printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "RANK");
			sprintf(string[0], "%13d", statc[player * 10 + 2] + 1);
			printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[0], 0);
		}
		
		if(statc[player * 10 + 3] != 0) {
			printTinyFont(foffset[player] + 8, fyoffset[player] + 139, "ST RECORDS");
			sprintf(string[0], "%13d", statc[player * 10 + 3]);
			printSMALLFont(foffset[player] + 10, fyoffset[player] + 147, string[0], 0);
		}
		
		if(statc[player * 10 + 4] >= 4) {
			printTinyFont(foffset[player] + 8, fyoffset[player] + 159, "SECRET GRADE");
			sprintf(string[0], "%13s", dvhStrSecretGradeName[statc[player * 10 + 4]]);
			printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
		}
	}
}

// 設定画面
void dvhSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(dvhLoadConfig() == 0) dvhSaveConfig();
	
	// ランキングを読み込み
	if(dvhLoadRanking(player) == 0) dvhInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "DEVIL-HARD OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",            7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",       7 * (cursor == 1));
		printFontGrid(2, 5, "LEVEL UP BONUS", 7 * (cursor == 2));
		printFontGrid(2, 6, "T-SPIN",         7 * (cursor == 3));
		printFontGrid(2, 7, "TIME LIMIT",     7 * (cursor == 4));
		printFontGrid(2, 8, "RISE INTERVAL",  7 * (cursor == 5));
		printFontGrid(2, 9, "START LEVEL",    7 * (cursor == 6));
		
		// 設定値表示
		if(!dvhIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!dvhBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!dvhLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(dvhTSpin == 0) sprintf(string[0], "OFF");
		else if(dvhTSpin == 1) sprintf(string[0], "LINE CLEAR");
		else if(dvhTSpin == 2) sprintf(string[0], "IMMOBILE");
		else if(dvhTSpin == 3) sprintf(string[0], "3-CORNER");
		else sprintf(string[0], "3-CORNER NO KICK");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(!dvhTorikan) sprintf(string[0], "OFF");
		else getTime(dvhTorikan);
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		if(!dvhRiseInterval) sprintf(string[0], "OFF");
		else sprintf(string[0], "%d", dvhRiseInterval);
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		sprintf(string[0], "%d", dvhStartLevel);
		printFontGrid(22, 9, string[0], 7 * (cursor == 6));
		
		// カーソル移動
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 6;
			if(cursor > 6) cursor = 0;
		}
		
		// 値を変更
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) dvhIsBig = !dvhIsBig;
			if(cursor == 1) dvhBigMove = !dvhBigMove;
			if(cursor == 2) dvhLvUpBonus = !dvhLvUpBonus;
			if(cursor == 3) {
				dvhTSpin = dvhTSpin + move;
				if(dvhTSpin < 0) dvhTSpin = 4;
				if(dvhTSpin > 4) dvhTSpin = 0;
			}
			if(cursor == 4) {
				dvhTorikan = dvhTorikan + (move * 60);
				if(dvhTorikan < 0) dvhTorikan = 72000;
				if(dvhTorikan > 72000) dvhTorikan = 0;
			}
			if(cursor == 5) {
				dvhRiseInterval = dvhRiseInterval + move;
				if(dvhRiseInterval < 0) dvhRiseInterval = 100;
				if(dvhRiseInterval > 100) dvhRiseInterval = 0;
			}
			if(cursor == 6) {
				dvhStartLevel = dvhStartLevel + (move * 100);
				if(dvhStartLevel < 0) dvhStartLevel = 1200;
				if(dvhStartLevel > 1200) dvhStartLevel = 0;
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
			dvhSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			dvhViewRanking(player);
		}
	}
}

// 設定を保存
void dvhSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x49564544;
	saveBuf[3] = 0x3176484C;
	
	// 設定内容
	saveBuf[4] = dvhIsBig;
	saveBuf[5] = dvhBigMove;
	saveBuf[6] = dvhLvUpBonus;
	saveBuf[7] = dvhTSpin;
	saveBuf[8] = dvhTorikan;
	saveBuf[9] = dvhRiseInterval;
	saveBuf[10] = dvhStartLevel;
	
	SaveFile("config/DEVIL_HARD_CONFIG.SAV", &saveBuf, 100 * 4);
}

// 設定を読み込み
int dvhLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/DEVIL_HARD_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x49564544) return 0;
	if(saveBuf[3] != 0x3176484C) return 0;
	
	// 設定内容
	dvhIsBig = saveBuf[4];
	dvhBigMove = saveBuf[5];
	dvhLvUpBonus = saveBuf[6];
	dvhTSpin = saveBuf[7];
	dvhTorikan = saveBuf[8];
	dvhRiseInterval = saveBuf[9];
	dvhStartLevel = saveBuf[10];
	
	return 1;
}

// リプレイ保存
void dvhSaveReplay(int player) {
	saveBuf[900] = dvhIsBig;
	saveBuf[901] = dvhBigMove;
	saveBuf[902] = dvhLvUpBonus;
	saveBuf[903] = dvhTSpin;
	saveBuf[904] = dvhTorikan;
	saveBuf[905] = dvhRiseInterval;
	saveBuf[906] = dvhLevel[player];
	saveBuf[907] = dvhScore[player];
	saveBuf[908] = dvhGrade[player];
	saveBuf[909] = dvhVersion;
	saveBuf[910] = dvhStartLevel;
}

// リプレイ読み込み
void dvhLoadReplay(int player) {
	dvhIsBig = saveBuf[900];
	dvhBigMove = saveBuf[901];
	dvhLvUpBonus = saveBuf[902];
	dvhTSpin = saveBuf[903];
	dvhTorikan = saveBuf[904];
	dvhRiseInterval = saveBuf[905];
	dvhVersion = saveBuf[909];
	dvhStartLevel = saveBuf[910];
}

// リプレイ詳細
void dvhReplayDetail(int number) {
	printFontGrid(1, 5, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[907]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[906]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "GRADE", 0);
	if((saveBuf[908] >= 0) && (saveBuf[908] <= 14)) {
		printFontGrid(22, 7, dvhStrGradeName[saveBuf[908]], 0);
	} else {
		printFontGrid(22, 7, "???", 0);
	}
	
	printFontGrid(1, 9, "BIG", 0);
	if(!saveBuf[900]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "BIG MOVE", 0);
	if(!saveBuf[901]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "LEVEL UP BONUS", 0);
	if(!saveBuf[902]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "T-SPIN", 0);
	if(saveBuf[903] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[903] == 1) sprintf(string[0], "LINE CLEAR");
	else if(saveBuf[903] == 2) sprintf(string[0], "IMMOBILE");
	else if(saveBuf[903] == 3) sprintf(string[0], "3-CORNER");
	else sprintf(string[0], "3-CORNER NO KICK");
	printFontGrid(22, 12, string[0], 0);
	
	printFontGrid(1, 13, "TIME LIMIT", 0);
	if(!saveBuf[904]) sprintf(string[0], "OFF");
	else getTime(saveBuf[904]);
	printFontGrid(22, 13, string[0], 0);
	
	printFontGrid(1, 14, "RISE INTERVAL", 0);
	if(!saveBuf[905]) sprintf(string[0], "OFF");
	else sprintf(string[0], "%d", saveBuf[905]);
	printFontGrid(22, 14, string[0], 0);
	
	if(saveBuf[909] >= 3) {
		printFontGrid(1, 15, "START LEVEL", 0);
		sprintf(string[0], "%d", saveBuf[910]);
		printFontGrid(22, 15, string[0], 0);
	}
	
	printFontGrid(1, 16, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[909]);
	printFontGrid(22, 16, string[0], 0);
}

// ランキング保存
void dvhSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0]  = dvhRankingGrade[i];
		saveBuf[1 + (i * 20) + 1]  = dvhRankingLevel[i];
		saveBuf[1 + (i * 20) + 2]  = dvhRankingTime[i];
		saveBuf[1 + (i * 20) + 3]  = dvhRankingEnd[i];
		saveBuf[1 + (i * 20) + 4]  = dvhRankingMedal[i * 4 + 0];
		saveBuf[1 + (i * 20) + 5]  = dvhRankingMedal[i * 4 + 1];
		saveBuf[1 + (i * 20) + 6]  = dvhRankingMedal[i * 4 + 2];
		saveBuf[1 + (i * 20) + 7]  = dvhRankingMedal[i * 4 + 3];
		saveBuf[1 + (i * 20) + 8]  = dvhRankingYear[i];
		saveBuf[1 + (i * 20) + 9]  = dvhRankingMonth[i];
		saveBuf[1 + (i * 20) + 10] = dvhRankingDay[i];
		saveBuf[1 + (i * 20) + 11] = dvhRankingHour[i];
		saveBuf[1 + (i * 20) + 12] = dvhRankingMinute[i];
		saveBuf[1 + (i * 20) + 13] = dvhRankingSecond[i];
	}
	
	// セクションタイムランキング
	for(i = 0; i < 13; i++) {
		saveBuf[221 + (i * 10) + 0] = dvhRankingSectionTime[i];
		saveBuf[221 + (i * 10) + 1] = dvhRankingSectionEnd[i];
		saveBuf[221 + (i * 10) + 2] = dvhRankingSectionYear[i];
		saveBuf[221 + (i * 10) + 3] = dvhRankingSectionMonth[i];
		saveBuf[221 + (i * 10) + 4] = dvhRankingSectionDay[i];
		saveBuf[221 + (i * 10) + 5] = dvhRankingSectionHour[i];
		saveBuf[221 + (i * 10) + 6] = dvhRankingSectionMinute[i];
		saveBuf[221 + (i * 10) + 7] = dvhRankingSectionSecond[i];
	}
	
	sprintf(string[0], "config/DEVIL_HARD_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 361 * 4);
}

// ランキング読み込み
int dvhLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/DEVIL_HARD_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 361 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		dvhRankingGrade[i]         = saveBuf[1 + (i * 20) + 0];
		dvhRankingLevel[i]         = saveBuf[1 + (i * 20) + 1];
		dvhRankingTime[i]          = saveBuf[1 + (i * 20) + 2];
		dvhRankingEnd[i]           = saveBuf[1 + (i * 20) + 3];
		dvhRankingMedal[i * 4 + 0] = saveBuf[1 + (i * 20) + 4];
		dvhRankingMedal[i * 4 + 1] = saveBuf[1 + (i * 20) + 5];
		dvhRankingMedal[i * 4 + 2] = saveBuf[1 + (i * 20) + 6];
		dvhRankingMedal[i * 4 + 3] = saveBuf[1 + (i * 20) + 7];
		dvhRankingYear[i]          = saveBuf[1 + (i * 20) + 8];
		dvhRankingMonth[i]         = saveBuf[1 + (i * 20) + 9];
		dvhRankingDay[i]           = saveBuf[1 + (i * 20) + 10];
		dvhRankingHour[i]          = saveBuf[1 + (i * 20) + 11];
		dvhRankingMinute[i]        = saveBuf[1 + (i * 20) + 12];
		dvhRankingSecond[i]        = saveBuf[1 + (i * 20) + 13];
	}
	
	// セクションタイムランキング
	for(i = 0; i < 13; i++) {
		dvhRankingSectionTime[i]   = saveBuf[221 + (i * 10) + 0];
		dvhRankingSectionEnd[i]    = saveBuf[221 + (i * 10) + 1];
		dvhRankingSectionYear[i]   = saveBuf[221 + (i * 10) + 2];
		dvhRankingSectionMonth[i]  = saveBuf[221 + (i * 10) + 3];
		dvhRankingSectionDay[i]    = saveBuf[221 + (i * 10) + 4];
		dvhRankingSectionHour[i]   = saveBuf[221 + (i * 10) + 5];
		dvhRankingSectionMinute[i] = saveBuf[221 + (i * 10) + 6];
		dvhRankingSectionSecond[i] = saveBuf[221 + (i * 10) + 7];
	}
	
	return 1;
}

// ランキング初期化
void dvhInitRanking() {
	int i;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		dvhRankingGrade[i]         = 0;
		dvhRankingLevel[i]         = 0;
		dvhRankingTime[i]          = 0;
		dvhRankingEnd[i]           = 0;
		dvhRankingMedal[i * 4 + 0] = 0;
		dvhRankingMedal[i * 4 + 1] = 0;
		dvhRankingMedal[i * 4 + 2] = 0;
		dvhRankingMedal[i * 4 + 3] = 0;
		dvhRankingYear[i]          = 0;
		dvhRankingMonth[i]         = 0;
		dvhRankingDay[i]           = 0;
		dvhRankingHour[i]          = 0;
		dvhRankingMinute[i]        = 0;
		dvhRankingSecond[i]        = 0;
	}
	
	// セクションタイムランキング
	for(i = 0; i < 13; i++) {
		dvhRankingSectionTime[i]   = 5400;
		dvhRankingSectionEnd[i]    = 0;
		dvhRankingSectionYear[i]   = 0;
		dvhRankingSectionMonth[i]  = 0;
		dvhRankingSectionDay[i]    = 0;
		dvhRankingSectionHour[i]   = 0;
		dvhRankingSectionMinute[i] = 0;
		dvhRankingSectionSecond[i] = 0;
	}
}

// ランキング登録
int dvhRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (dvhIsBig) || (!dvhLvUpBonus) || (dvhStartLevel)) return -1;
	
	for(i = 0; i < 10; i++) {
		// ランクイン
		if(
		    (dvhEndFlag[player] > dvhRankingEnd[i]) || 
		    ((dvhEndFlag[player] == dvhRankingEnd[i]) && (dvhGrade[player] > dvhRankingGrade[i])) || 
		    ((dvhEndFlag[player] == dvhRankingEnd[i]) && (dvhGrade[player] == dvhRankingGrade[i]) && (gameTimer[player] < dvhRankingTime[i]))
		  )
		{
			// ランキングをずらす
			for(j = 9; j > i; j--) {
				dvhRankingGrade[j]         = dvhRankingGrade[j - 1];
				dvhRankingLevel[j]         = dvhRankingLevel[j - 1];
				dvhRankingTime[j]          = dvhRankingTime[j - 1];
				dvhRankingEnd[j]           = dvhRankingEnd[j - 1];
				dvhRankingMedal[j * 4 + 0] = dvhRankingMedal[(j - 1) * 4 + 0];
				dvhRankingMedal[j * 4 + 1] = dvhRankingMedal[(j - 1) * 4 + 1];
				dvhRankingMedal[j * 4 + 2] = dvhRankingMedal[(j - 1) * 4 + 2];
				dvhRankingMedal[j * 4 + 3] = dvhRankingMedal[(j - 1) * 4 + 3];
				dvhRankingYear[j]          = dvhRankingYear[j - 1];
				dvhRankingMonth[j]         = dvhRankingMonth[j - 1];
				dvhRankingDay[j]           = dvhRankingDay[j - 1];
				dvhRankingHour[j]          = dvhRankingHour[j - 1];
				dvhRankingMinute[j]        = dvhRankingMinute[j - 1];
				dvhRankingSecond[j]        = dvhRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			dvhRankingGrade[i]         = dvhGrade[player];
			dvhRankingLevel[i]         = dvhLevel[player];
			dvhRankingTime[i]          = gameTimer[player];
			dvhRankingEnd[i]           = dvhEndFlag[player];
			dvhRankingMedal[i * 4 + 0] = dvhMedalStat[player * 4 + 0];
			dvhRankingMedal[i * 4 + 1] = dvhMedalStat[player * 4 + 1];
			dvhRankingMedal[i * 4 + 2] = dvhMedalStat[player * 4 + 2];
			dvhRankingMedal[i * 4 + 3] = dvhMedalStat[player * 4 + 3];
			
			GetDateAndTime(&timebuf);
			dvhRankingYear[i]          = timebuf[0];
			dvhRankingMonth[i]         = timebuf[1];
			dvhRankingDay[i]           = timebuf[2];
			dvhRankingHour[i]          = timebuf[4];
			dvhRankingMinute[i]        = timebuf[5];
			dvhRankingSecond[i]        = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// セクションタイムランキング更新
int dvhUpdateSectionTimeRanking(int player) {
	int i, timebuf[8], result;
	result = 0;
	
	if((playback) || (dvhIsBig) || (!dvhLvUpBonus) || (dvhStartLevel)) return 0;
	
	for(i = 0; i < 13; i++) {
		if((dvhSectionTime[i + player * 13] < dvhRankingSectionTime[i]) && (dvhSectionTime[i + player * 13] != 0)) {
			result++;
			
			dvhRankingSectionTime[i] = dvhSectionTime[i + player * 13];
			dvhRankingSectionEnd[i] = dvhEndFlag[player];
			
			GetDateAndTime(&timebuf);
			dvhRankingSectionYear[i] = timebuf[0];
			dvhRankingSectionMonth[i] = timebuf[1];
			dvhRankingSectionDay[i] = timebuf[2];
			dvhRankingSectionHour[i] = timebuf[4];
			dvhRankingSectionMinute[i] = timebuf[5];
			dvhRankingSectionSecond[i] = timebuf[6];
		}
	}
	
	return result;
}

// ランキング表示
void dvhViewRanking(int player) {
	int i, cursor, move, erasemode, stmode, temp;
	cursor = 0;
	move = 0;
	erasemode = 0;
	stmode = 0;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		if(!stmode) {
			// ノーマルランキング
			printFontGrid(1, 1, "DEVIL-HARD MODE RANKING >>", 6);
			printFontGrid(1, 3, "RANK GRADE LEVEL TIME", 4);
			
			for(i = 0; i < 10; i++) {
				if(dvhRankingEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (dvhRankingEnd[i] - 1) * 2, 320, 2);
				
				if(i == 0) sprintf(string[0], " 1ST");
				if(i == 1) sprintf(string[0], " 2ND");
				if(i == 2) sprintf(string[0], " 3RD");
				if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
				printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
				
				if((dvhRankingGrade[i] >= 0) && (dvhRankingGrade[i] <= 14)) {
					printFontGrid(6, 4 + i, dvhStrGradeName[dvhRankingGrade[i]], 7 * (cursor == i));
				} else {
					printFontGrid(6, 4 + i, "???", 7 * (cursor == i));
				}
				
				sprintf(string[0], "%d", dvhRankingLevel[i]);
				printFontGrid(12, 4 + i, string[0], 7 * (cursor == i));
				
				getTime(dvhRankingTime[i]);
				printFontGrid(18, 4 + i, string[0], 7 * (cursor == i));
			}
			
			for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
			
			if(!erasemode) {
				// メダル
				dvhDrawMedal(8 + 0 * 16, 192, 1, dvhRankingMedal[cursor * 4 + 0], -1);
				dvhDrawMedal(8 + 1 * 16, 192, 0, dvhRankingMedal[cursor * 4 + 1], -1);
				dvhDrawMedal(8 + 2 * 16, 192, 5, dvhRankingMedal[cursor * 4 + 2], -1);
				dvhDrawMedal(8 + 3 * 16, 192, 2, dvhRankingMedal[cursor * 4 + 3], -1);
				
				// 日付と時刻
				sprintf(string[0],
				        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
				        dvhRankingYear[cursor], dvhRankingMonth[cursor], dvhRankingDay[cursor],
				        dvhRankingHour[cursor], dvhRankingMinute[cursor], dvhRankingSecond[cursor]);
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
				
				// ランキング切り替え
				if(getPushState(player, 2) || getPushState(player, 3)) {
					PlaySE(se_move);
					stmode = !stmode;
				}
			} else {
				printFontGrid(1, 24, "ERASE ALL RECORDS?", 2);
				printFontGrid(1, 26, "A:YES / B:NO", 2);
				
				// 消去
				if(getPushState(player, 4)) {
					PlayWave(se_kettei);
					dvhInitRanking();
					dvhSaveRanking(player);
					erasemode = 0;
				}
				
				// 戻る
				if(getPushState(player, 5)) {
					PlaySE(se_move);
					erasemode = 0;
				}
			}
		} else {
			// セクションタイムランキング
			printFontGrid(1, 1, "<< DEVIL-HARD MODE SECTION TIME", 6);
			printFontGrid(1, 3, "SECTION   TIME     DATE", 4);
			printFontGrid(1, 28, "A/B:EXIT", 6);
			
			for(i = 0; i < 13; i++) {
				if(dvhRankingSectionEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (dvhRankingSectionEnd[i] - 1) * 2, 320, 2);
				
				sprintf(string[0], "%4d-%4d", i * 100, ((i + 1) * 100) - 1);
				printFontGrid(1, 4 + i, string[0], 0);
				
				getTime(dvhRankingSectionTime[i]);
				printFontGrid(11, 4 + i, string[0], 0);
				
				temp = (dvhRankingSectionYear[i] / 1000) * 1000;	// 年を下2桁だけ表示
				if(temp == 0) temp = 1;
				sprintf(string[0], "%02d/%02d/%02d", dvhRankingSectionYear[i] % temp, dvhRankingSectionMonth[i], dvhRankingSectionDay[i]);
				printFontGrid(20, 4 + i, string[0], 0);
				
				sprintf(string[0], "%02d:%02d:%02d", dvhRankingSectionHour[i], dvhRankingSectionMinute[i], dvhRankingSectionSecond[i]);
				printFontGrid(29, 4 + i, string[0], 0);
			}
			
			// 戻る
			if(getPushState(player, 4) || getPushState(player, 5)) {
				PlaySE(se_move);
				return;
			}
			
			// ランキング切り替え
			if(getPushState(player, 2) || getPushState(player, 3)) {
				PlaySE(se_move);
				stmode = !stmode;
			}
		}
	}
}
