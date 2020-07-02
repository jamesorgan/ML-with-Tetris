//DEVIL-QUAKE
//prefix:dvlq

// バージョン
int dvlqVersion;			// バージョン番号（古いリプレイ再生用）
int dvlqCVersion = 1;		// 現在のバージョン

// レベルアップテーブル    000, 100, 200, 300, 400, 500, 600, 700, 800, 900,1000,1100,1200,1300
int dvlqWait1Table[14] = {  10,  10,  10,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4};	// 接着後（ARE）
int dvlqWait2Table[14] = {   6,   5,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   6};	// 消去
int dvlqWait3Table[14] = {  18,  18,  17,  15,  15,  13,  12,  12,  12,  12,  12,  10,   8,  15};	// 接着
int dvlqWait5Table[14] = {   6,   5,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   4};	// 消去後（ARE2）
int dvlqWaittTable[14] = {   8,   6,   6,   6,   6,   4,   4,   4,   4,   4,   4,   4,   4,   6};	// 横溜

// 旧レベルアップテーブル     000, 100, 200, 300, 400, 500, 600, 700, 800, 900,1000,1100,1200,1300
int dvlqWait1TableOld[14] = {   6,   5,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   4};	// 消去後（ARE）
int dvlqWait2TableOld[14] = {   6,   5,   4,   4,   4,   3,   3,   3,   3,   3,   3,   3,   3,   6};	// 消去
int dvlqWait3TableOld[14] = {  18,  18,  17,  15,  15,  13,  12,  12,  12,  12,  12,  10,   8,  15};	// 接着
int dvlqWait4TableOld[14] = {  24,  24,  23,  21,  21,  19,  18,  18,  18,  18,  18,  16,   8,  21};	// 接着後
int dvlqWaittTableOld[14] = {   8,   6,   6,   6,   6,   4,   4,   4,   4,   4,   4,   4,   4,   6};	// 横溜

// せり上がり間隔        000, 100, 200, 300, 400, 500, 600, 700, 800, 900,1000,1100,1200,1300
int dvlqRiseTable[14] = {  0,   0,   0,   0,   0,  20,  18,  10,   9,   8,   0,   0,   0,   0};

// REGRET基準タイム         000, 100, 200, 300, 400, 500, 600, 700, 800, 900,1000,1100,1200
int dvlqRegretTable[13] = {3600,3600,3000,3000,3000,3000,3000,3000,3000,3000,3000,3000,3000};

// BGM
int dvlqBgmListTable[5]   = {2, 3, 4, 5, 6};			// 使用するBGM
int dvlqBgmFadeTable[4]   = {485, 685, 985, 10000};		// フェードアウトするレベル
int dvlqBgmChangeTable[4] = {500, 700, 1000, 10000};	// 切り替えるレベル
int dvlqBgmIndex          = 0;							// 現在のBGM番号

// 段位の表示名
str dvlqStrGradeName[15] = 
{
	"1", "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13", "GOD"
};

// 裏段位の表示名
str dvlqStrSecretGradeName[19] = 
{
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  0～ 8
	"M1", "M2", "M3", "M4", "M5", "M6", "M7", "M8", "M9",	//  9～17
	"GM"													// 18
};

// 変数
int dvlqModeNo = -1;		// モード番号

int dvlqLevel[2];			// レベル
int dvlqScore[2];			// スコア
int dvlqGrade[2];			// 段位
int dvlqEndFlag[2];			// クリアフラグ

int dvlqRiseCount[2];		// せり上がり用カウンタ

int dvlqSTimer[2];			// セクションタイマー
int dvlqSkill[2];			// ヘボリス回数

int dvlqSectionTime[13 * 2];	// このプレイのセクションタイム

int dvlqMedalStat[4 * 2];	// メダルの状態(0=なし 1=銅 2=銀 3=金)
int dvlqMedalAnim[4 * 2];	// メダル獲得アニメーション用カウンタ

int dvlqTSpinFrame[2];		// T-SPIN表示の残り時間
int dvlqRegretFrame[2];		// REGRET表示の残り時間

int dvlqIsBig = 0;			// BIGかどうか
int dvlqBigMove = 1;		// BIG時の横移動単位
int dvlqLvUpBonus = 1;		// レベルアップボーナス
int dvlqTSpin = 1;			// T-SPINの種類
int dvlqTorikan = 10980;	// LV500とりカン基準タイム (3:03:00)
int dvlqRiseEnable = 1;		// せり上がりONOFF
int dvlqStartLevel = 0;		// スタート時のレベル

// ランキング変数
int dvlqRankingGrade[10];			// 段位
int dvlqRankingLevel[10];			// レベル
int dvlqRankingTime[10];			// タイム
int dvlqRankingEnd[10];				// クリアフラグ
int dvlqRankingMedal[4 * 10];		// メダル
int dvlqRankingYear[10];			// ランクイン日時（年）
int dvlqRankingMonth[10];			// ランクイン日時（月）
int dvlqRankingDay[10];				// ランクイン日時（日）
int dvlqRankingHour[10];			// ランクイン日時（時）
int dvlqRankingMinute[10];			// ランクイン日時（分）
int dvlqRankingSecond[10];			// ランクイン日時（秒）

// セクションタイムランキング変数
int dvlqRankingSectionTime[13];		// タイム
int dvlqRankingSectionEnd[13];		// クリアフラグ
int dvlqRankingSectionYear[13];		// ランクイン日時（年）
int dvlqRankingSectionMonth[13];	// ランクイン日時（月）
int dvlqRankingSectionDay[13];		// ランクイン日時（日）
int dvlqRankingSectionHour[13];		// ランクイン日時（時）
int dvlqRankingSectionMinute[13];	// ランクイン日時（分）
int dvlqRankingSectionSecond[13];	// ランクイン日時（秒）

// イベント発生
void dvlqPluginEvent(int player, int event, int *param) {
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != dvlqModeNo)) return;
	
	if(event == 0) {
		dvlqModeNo = addModePlugin("DEVIL-QUAKE");	// モードを登録する
	} else if(event == 7) {
		if(!ending[player]) dvlqMoveInit(player);	// ブロック出現
	} else if(event == 10) {
		dvlqRiseField(player);	// せり上がり
	} else if(event == 12) {
		if(!ending[player]) dvlqCalcScore(player, param[0]);	// スコア計算
	} else if(event == 15) {
		dvlqViewScore(player);	// スコア表示
	} else if(event == 17) {
		dvlqSetting(player, param);	// 設定画面
	} else if(event == 18) {
		dvlqPlayerInitial(player);	// 初期化処理
	} else if(event == 21) {
		dvlqResult(player, param);	// 結果表示
	} else if(event == 24) {
		dvlqEndingStart(player);	// エンディング突入
	} else if(event == 25) {
		dvlqExcellent(player, param);	// エンディング終了
	} else if(event == 28) {
		dvlqIncrementTime(player);	// 時間を進める
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		dvlqSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		dvlqLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		dvlqLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		dvlqReplayDetail(param[0]);	// リプレイ詳細
	}
}

// 初期化処理
void dvlqPlayerInitial(int player) {
	int i;
	
	// バージョン設定
	if(!playback) dvlqVersion = dvlqCVersion;
	
	// 変数を初期化
	if(dvlqStartLevel > 0) {
		dvlqLevel[player] = dvlqStartLevel;
		
		if(dvlqLevel[player] >= 1000) oblk_spawn[player] = 1;
		
		backno = dvlqLevel[player] / 100;
		if(backno > 9) backno = 9;
	} else {
		dvlqLevel[player] = -1;
	}
	
	dvlqScore[player] = 0;
	dvlqGrade[player] = 0;
	dvlqEndFlag[player] = 0;
	dvlqRiseCount[player] = 0;
	dvlqSTimer[player] = 0;
	dvlqSkill[player] = 0;
	dvlqTSpinFrame[player] = 0;
	dvlqRegretFrame[player] = 0;
	
	for(i = 0; i < 4; i++) {
		dvlqMedalStat[player * 4 + i] = 0;
		dvlqMedalAnim[player * 4 + i] = -1;
	}
	
	for(i = 0; i < 13; i++) dvlqSectionTime[i + player * 13] = 0;
	
	dvlqBgmIndex = 0;
	bgmlv = dvlqBgmListTable[0];
	framecolor[player] = 2;
	enable_combo[player] = 1;
	
	// 設定を反映させる
	IsBig[player] = dvlqIsBig;
	BigMove[player] = dvlqBigMove;
	tspin_type[player] = dvlqTSpin;
	
	// 初期スピードを設定
	dvlqSpeedUp(player);
}

// スピードアップ
void dvlqSpeedUp(int player) {
	int temp, index;
	
	// 20G
	sp[player] = 1200;
	
	// スピードを変える
	index = dvlqLevel[player] / 100;
	if(index < 0) index = 0;
	if(index > 13) index = 13;
	
	if(dvlqVersion >= 1) {
		wait1[player] = dvlqWait1Table[index];
		wait2[player] = dvlqWait2Table[index];
		wait3[player] = dvlqWait3Table[index];
		wait5[player] = dvlqWait5Table[index];
		waitt[player] = dvlqWaittTable[index];
	} else {
		wait1[player] = dvlqWait1TableOld[index];
		wait2[player] = dvlqWait2TableOld[index];
		wait3[player] = dvlqWait3TableOld[index];
		wait4[player] = dvlqWait4TableOld[index];
		waitt[player] = dvlqWaittTableOld[index];
	}
	
	// BGMフェードアウト
	if((dvlqLevel[player] >= dvlqBgmFadeTable[dvlqBgmIndex]) && (dvlqLevel[player] < dvlqBgmChangeTable[dvlqBgmIndex]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// BGM切り替え
	temp = 0;
	while(dvlqLevel[player] >= dvlqBgmChangeTable[dvlqBgmIndex]) {
		dvlqBgmIndex++;
		bgmlv = dvlqBgmListTable[dvlqBgmIndex];
		if(onRecord[player]) temp = 1;
	}
	if(temp) PlayBGM();
}

// ブロック出現
void dvlqMoveInit(int player) {
	// 最初のフレームなら
	if(statc[player * 10 + 3] == 0) {
		// レベルアップ処理
		if(dvlqLevel[player] % 100 != 99) {
			dvlqLevel[player]++;
			if(dvlqLevel[player] % 100 == 99) PlaySE(se_lvstop);
			dvlqSpeedUp(player);
		}
		
		// せり上がりカウンタ
		if(dvlqRiseTable[dvlqLevel[player] / 100] != 0) dvlqRiseCount[player]++;
	}
}

// スコア計算
void dvlqCalcScore(int player, int lines) {
	int i, temp, bo, bai, nextsec, lv;
	
	lv = dvlqLevel[player];	// 上がる前のレベル
	
	// せり上がりカウンタ減少
	if(dvlqRiseTable[dvlqLevel[player] / 100] != 0) dvlqRiseCount[player] = dvlqRiseCount[player] - lines;
	
	// ヘボリス回数増加
	if(lines >= 4) {
		dvlqSkill[player]++;
		
		// SKメダル獲得
		if((dvlqSkill[player] == 5) || (dvlqSkill[player] == 10) || (dvlqSkill[player] == 17)) {
			PlaySE(se_medal);
			dvlqMedalStat[player * 4 + 3]++;
			dvlqMedalAnim[player * 4 + 3] = 0;
		}
	}
	
	// COメダル獲得
	if(combo2[player] == 4) {
		if(dvlqMedalStat[player * 4 + 2] < 1) {
			PlaySE(se_medal);
			dvlqMedalStat[player * 4 + 2] = 1;
			dvlqMedalAnim[player * 4 + 2] = 0;
		}
	} else if(combo2[player] == 5) {
		if(dvlqMedalStat[player * 4 + 2] < 2) {
			PlaySE(se_medal);
			dvlqMedalStat[player * 4 + 2] = 2;
			dvlqMedalAnim[player * 4 + 2] = 0;
		}
	} else if(combo2[player] == 7) {
		if(dvlqMedalStat[player * 4 + 2] < 3) {
			PlaySE(se_medal);
			dvlqMedalStat[player * 4 + 2] = 3;
			dvlqMedalAnim[player * 4 + 2] = 0;
		}
	}
	
	// レベルアップ
	nextsec = dvlqLevel[player] / 100 * 100 + 100;
	if(!dvlqLvUpBonus) dvlqLevel[player] = dvlqLevel[player] + lines;
	else dvlqLevel[player] = dvlqLevel[player] + lines + ((lines >= 3) * (lines - 2));
	
	if(dvlqLevel[player] >= 1300) {
		// エンディング
		dvlqLevel[player] = 1300;
		ending[player] = 1;
		timeOn[player] = 0;
		dvlqSpeedUp(player);
		dvlqGradeUp(player, (nextsec / 100) - 1);
		dvlqEndFlag[player] = 1;
		
		// GOD条件を満たしている場合は流れ星出現
		if((dvlqGrade[player] == 13) && (gameTimer[player] <= 19200)) {
			objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
		}
	} else if((dvlqLevel[player] >= nextsec) && (nextsec == 500) && (gameTimer[player] > dvlqTorikan) && (dvlqTorikan > 0)) {
		// LV500とりカン
		dvlqLevel[player] = 500;
		ending[player] = 4;
		timeOn[player] = 0;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		stat[player] = 10;
		dvlqGradeUp(player, (nextsec / 100) - 1);
	} else if((dvlqLevel[player] >= nextsec) && (nextsec == 1000) && (gameTimer[player] > dvlqTorikan * 2) && (dvlqTorikan > 0)) {
		// LV1000とりカン
		dvlqLevel[player] = 1000;
		ending[player] = 4;
		timeOn[player] = 0;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		stat[player] = 10;
		dvlqGradeUp(player, (nextsec / 100) - 1);
	} else {
		// レベルストップ音
		if(dvlqLevel[player] % 100 == 99) PlaySE(se_lvstop);
		
		if(dvlqLevel[player] >= nextsec) {
			// レベルアップ音
			PlaySE(se_levelup);
			
			// 背景切り替え
			if(dvlqLevel[player] < 1000) {
				bgfadesw = 1;
				bgfadebg = nextsec / 100;
			}
			
			dvlqGradeUp(player, (nextsec / 100) - 1);
			
			// []出現
			if(dvlqLevel[player] >= 1000) oblk_spawn[player] = 1;
		}
		
		// スピードアップ
		dvlqSpeedUp(player);
	}
	
	// スコア計算
	temp = wait3[player] - bactivetime[player];
	if(temp < 0) temp = 0;
	
	bo = ((lv + lines) / 4 + (sdrop[player] / 2) + qdrop[player] + qput[player]) * lines * cmbpts[player] + (dvlqLevel[player] / 2) + temp;
	bai = 1;
	
	if(isBravo(player)) {
		// 全消し
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		
		// ACメダル獲得
		if(dvlqMedalStat[player * 4 + 1] < 3) {
			PlaySE(se_medal);
			dvlqMedalStat[player * 4 + 1]++;
			dvlqMedalAnim[player * 4 + 1] = 0;
		}
	}
	
	// T-SPIN
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		dvlqTSpinFrame[player] = 120;
	}
	
	// スコア加算
	dvlqScore[player] = dvlqScore[player] + (bo * bai);
}

// STメダル獲得／段位上昇
void dvlqGradeUp(int player, int section) {
	// セクションタイム記録
	dvlqSectionTime[section + player * 13] = dvlqSTimer[player];
	
	// STメダル獲得
	if((!playback) && (!dvlqIsBig) && (dvlqLvUpBonus) && (!dvlqStartLevel)) {
		if((dvlqSTimer[player] < dvlqRankingSectionTime[section]) && (dvlqMedalStat[player * 4 + 0] < 3)) {
			PlaySE(se_medal);
			dvlqMedalStat[player * 4 + 0] = 3;
			dvlqMedalAnim[player * 4 + 0] = 0;
		} else if((dvlqSTimer[player] < dvlqRankingSectionTime[section] + 300) && (dvlqMedalStat[player * 4 + 0] < 2)) {
			PlaySE(se_medal);
			dvlqMedalStat[player * 4 + 0] = 2;
			dvlqMedalAnim[player * 4 + 0] = 0;
		} else if((dvlqSTimer[player] < dvlqRankingSectionTime[section] + 600) && (dvlqMedalStat[player * 4 + 0] < 1)) {
			PlaySE(se_medal);
			dvlqMedalStat[player * 4 + 0] = 1;
			dvlqMedalAnim[player * 4 + 0] = 0;
		}
	}
	
	// 段位上昇
	if(dvlqSTimer[player] <= dvlqRegretTable[section]) {
		dvlqGrade[player]++;
	} else {
		PlaySE(se_regret);
		dvlqRegretFrame[player] = 180;
	}
	
	dvlqSTimer[player] = 0;
}

// 時間を進める
void dvlqIncrementTime(int player) {
	int i;
	
	// セクションタイム増加
	if(timeOn[player]) dvlqSTimer[player]++;
	
	// ロール終了
	if((ending[player] == 2) && (edrec[player] >= 3238)) {
		// GOD条件達成
		if((dvlqGrade[player] == 13) && (gameTimer[player] <= 19200)) {
			dvlqGrade[player] = 14;
		}
		ending[player] = 3;
		stat[player] = 10;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
	
	if(dvlqRegretFrame[player] > 0)
		dvlqRegretFrame[player]--;	// REGRET表示時間減少
	else if(dvlqTSpinFrame[player] > 0)
		dvlqTSpinFrame[player]--;	// T-SPIN表示時間減少
}

// せり上がり
void dvlqRiseField(int player) {
	int i;
	
	if(dvlqRiseEnable == 0) return;
	
	if((dvlqRiseCount[player] >= dvlqRiseTable[dvlqLevel[player] / 100]) && (dvlqRiseTable[dvlqLevel[player] / 100] != 0)) {
		// 最下段をコピーする
		for(i = 0; i < 10; i++) {
			fldu[i + player * 220] = (fld[i + 21 * 10 + player * 220] != 0);
		}
		upLines[player] = 1;
		
		// せり上がりカウントリセット
		dvlqRiseCount[player] = 0;
	}
}

// エンディング突入
void dvlqEndingStart(int player) {
	int i;
	
	for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	
	if(dvlqLevel[player] >= 1300) {
		ending[player] = 2;
		stat[player] = 4;
		ending_timeOn[player] = 1;
		
		IsBig[player] = 1;
		BigMove[player] = 1;
		
		bgmlv = dvlqBgmListTable[4];
		PlayBGM();
	} else {
		ending[player] = 3;
	}
}

// エンディング終了
void dvlqExcellent(int player, int *param) {
	onRecord[player] = 0;
	statc[player * 10 + 1]++;
	
	if(dvlqGrade[player] >= 14) {
		// GOD
		param[0] = 2;
		dvlqEndFlag[player] = 2;
		
		// 花火
		if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 30)) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			statc[player * 10 + 2]++;
		}
	} else if(dvlqLevel[player] >= 1300) {
		// 完全クリア
		printTinyFont(foffset[player] + 22, fyoffset[player] + 116, "DEVIL MODE");
		printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
		dvlqEndFlag[player] = 2;
		
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
void dvlqLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 5; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/5)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(dvlqBgmListTable[i]);
		}
	}
}

// スコアを表示
void dvlqViewScore(int player) {
	int i, x, y, color, kind;
	color = (count % 4 / 2) * 7;
	
	// メダル（通常）
	for(i = 0; i < 4; i++) {
		if((dvlqMedalAnim[player * 4 + i] < 0) || (dvlqMedalAnim[player * 4 + i] > 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 17;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			if(i == 0) kind = 1;
			if(i == 1) kind = 0;
			if(i == 2) kind = 5;
			if(i == 3) kind = 2;
			dvlqDrawMedal(x, y, kind, dvlqMedalStat[player * 4 + i], dvlqMedalAnim[player * 4 + i]);
		}
	}
	
	// メダル（アニメ中）
	for(i = 0; i < 4; i++) {
		if((dvlqMedalAnim[player * 4 + i] >= 0) && (dvlqMedalAnim[player * 4 + i] <= 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 17;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			if(i == 0) kind = 1;
			if(i == 1) kind = 0;
			if(i == 2) kind = 5;
			if(i == 3) kind = 2;
			dvlqDrawMedal(x, y, kind, dvlqMedalStat[player * 4 + i], dvlqMedalAnim[player * 4 + i]);
			dvlqMedalAnim[player * 4 + i]++;
		}
	}
	
	// レベル（分子）
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(dvlqLevel[player] == -1) sprintf(string[0], "%4d", 0);	// -1なら0と表示する(内部的には最初は-1になっている)
	else sprintf(string[0], "%4d", dvlqLevel[player]);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// レベル（横線）
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 0, 143, 22, 1);
	
	// レベル（分母）
	if(ending[player]) sprintf(string[0], "%4d", dvlqLevel[player]);
	else sprintf(string[0], "%4d", dvlqLevel[player] / 100 * 100 + 100);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, string[0], color);
	
	// タイム
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
	
	if(dvlqRegretFrame[player] > 0)
		printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "REGRET");	// REGRET表示
	else if(dvlqTSpinFrame[player] > 0)
		printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "T-SPIN");	// T-SPIN表示
}

// メダルを表示
void dvlqDrawMedal(int x, int y, int kind, int color, int anim) {
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
void dvlqResult(int player, int *param) {
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
			statc[player * 10 + 2] = dvlqRegistRanking(player);
			statc[player * 10 + 3] = dvlqUpdateSectionTimeRanking(player);
			if((statc[player * 10 + 2] != -1) || (statc[player * 10 + 3] != 0)) dvlqSaveRanking(player);
			
			// 裏段位判定
			statc[player * 10 + 4] = checkSecretGrade(player);
		}
		
		// 段位表示
		if(dvlqGrade[player] == 0)		// 1
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108,   0, ((count % 4 / 2) * 216) + 192, 90, 24);
		else if(dvlqGrade[player] < 10)	// S1～S9
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108,  90, ((count % 4 / 2) * 216) + ((dvlqGrade[player] -  1) * 24), 90, 24);
		else if(dvlqGrade[player] < 14)	// S10～S13
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108, 360, ((count % 4 / 2) * 216) + ((dvlqGrade[player] - 10) * 24), 90, 24);
		else							// GOD
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108, 360, ((count % 4 / 2) * 216) + 96, 90, 72);
		
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
		sprintf(string[0], "%13d", dvlqScore[player]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 67, string[0], 0);
		
		printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LEVEL");
		sprintf(string[0], "%13d", dvlqLevel[player]);
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
			sprintf(string[0], "%13s", dvlqStrSecretGradeName[statc[player * 10 + 4]]);
			printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
		}
	}
}

// 設定画面
void dvlqSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(dvlqLoadConfig() == 0) dvlqSaveConfig();
	
	// ランキングを読み込み
	if(dvlqLoadRanking(player) == 0) dvlqInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "DEVIL-QUAKE OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",            7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",       7 * (cursor == 1));
		printFontGrid(2, 5, "LEVEL UP BONUS", 7 * (cursor == 2));
		printFontGrid(2, 6, "T-SPIN",         7 * (cursor == 3));
		printFontGrid(2, 7, "TIME LIMIT",     7 * (cursor == 4));
		printFontGrid(2, 8, "RISE ON/OFF",    7 * (cursor == 5));
		printFontGrid(2, 9, "START LEVEL",    7 * (cursor == 6));
		
		// 設定値表示
		if(!dvlqIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!dvlqBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!dvlqLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(dvlqTSpin == 0) sprintf(string[0], "OFF");
		else if(dvlqTSpin == 1) sprintf(string[0], "LINE CLEAR");
		else if(dvlqTSpin == 2) sprintf(string[0], "IMMOBILE");
		else if(dvlqTSpin == 3) sprintf(string[0], "3-CORNER");
		else sprintf(string[0], "3-CORNER NO KICK");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(!dvlqTorikan) sprintf(string[0], "OFF");
		else getTime(dvlqTorikan);
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		if(!dvlqRiseEnable) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		sprintf(string[0], "%d", dvlqStartLevel);
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
			
			if(cursor == 0) dvlqIsBig = !dvlqIsBig;
			if(cursor == 1) dvlqBigMove = !dvlqBigMove;
			if(cursor == 2) dvlqLvUpBonus = !dvlqLvUpBonus;
			if(cursor == 3) {
				dvlqTSpin = dvlqTSpin + move;
				if(dvlqTSpin < 0) dvlqTSpin = 4;
				if(dvlqTSpin > 4) dvlqTSpin = 0;
			}
			if(cursor == 4) {
				dvlqTorikan = dvlqTorikan + (move * 60);
				if(dvlqTorikan < 0) dvlqTorikan = 72000;
				if(dvlqTorikan > 72000) dvlqTorikan = 0;
			}
			if(cursor == 5) {
				dvlqRiseEnable = !dvlqRiseEnable;
			}
			if(cursor == 6) {
				dvlqStartLevel = dvlqStartLevel + (move * 100);
				if(dvlqStartLevel < 0) dvlqStartLevel = 1200;
				if(dvlqStartLevel > 1200) dvlqStartLevel = 0;
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
			dvlqSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			dvlqViewRanking(player);
		}
	}
}

// 設定を保存
void dvlqSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x49564544;
	saveBuf[3] = 0x3176444C;
	
	// 設定内容
	saveBuf[4] = dvlqIsBig;
	saveBuf[5] = dvlqBigMove;
	saveBuf[6] = dvlqLvUpBonus;
	saveBuf[7] = dvlqTSpin;
	saveBuf[8] = dvlqTorikan;
	saveBuf[9] = dvlqRiseEnable;
	saveBuf[10] = dvlqStartLevel;
	
	SaveFile("config/DEVIL_QUAKE_CONFIG.SAV", &saveBuf, 100 * 4);
}

// 設定を読み込み
int dvlqLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/DEVIL_QUAKE_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x49564544) return 0;
	if(saveBuf[3] != 0x3176444C) return 0;
	
	// 設定内容
	dvlqIsBig = saveBuf[4];
	dvlqBigMove = saveBuf[5];
	dvlqLvUpBonus = saveBuf[6];
	dvlqTSpin = saveBuf[7];
	dvlqTorikan = saveBuf[8];
	dvlqRiseEnable = saveBuf[9];
	dvlqStartLevel = saveBuf[10];
	
	return 1;
}

// リプレイ保存
void dvlqSaveReplay(int player) {
	saveBuf[900] = dvlqIsBig;
	saveBuf[901] = dvlqBigMove;
	saveBuf[902] = dvlqLvUpBonus;
	saveBuf[903] = dvlqTSpin;
	saveBuf[904] = dvlqTorikan;
	saveBuf[905] = dvlqRiseEnable;
	saveBuf[906] = dvlqLevel[player];
	saveBuf[907] = dvlqScore[player];
	saveBuf[908] = dvlqGrade[player];
	saveBuf[909] = dvlqVersion;
	saveBuf[910] = dvlqStartLevel;
}

// リプレイ読み込み
void dvlqLoadReplay(int player) {
	dvlqIsBig = saveBuf[900];
	dvlqBigMove = saveBuf[901];
	dvlqLvUpBonus = saveBuf[902];
	dvlqTSpin = saveBuf[903];
	dvlqTorikan = saveBuf[904];
	dvlqRiseEnable = saveBuf[905];
	dvlqVersion = saveBuf[909];
	dvlqStartLevel = saveBuf[910];
}

// リプレイ詳細
void dvlqReplayDetail(int number) {
	printFontGrid(1, 5, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[907]);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[906]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "GRADE", 0);
	if((saveBuf[908] >= 0) && (saveBuf[908] <= 14)) {
		printFontGrid(22, 7, dvlqStrGradeName[saveBuf[908]], 0);
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
	
	printFontGrid(1, 14, "RISE ON/OFF", 0);
	if(!saveBuf[905]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 14, string[0], 0);
	
	printFontGrid(1, 15, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[910]);
	printFontGrid(22, 15, string[0], 0);
	
	printFontGrid(1, 16, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[909]);
	printFontGrid(22, 16, string[0], 0);
}

// ランキング保存
void dvlqSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0]  = dvlqRankingGrade[i];
		saveBuf[1 + (i * 20) + 1]  = dvlqRankingLevel[i];
		saveBuf[1 + (i * 20) + 2]  = dvlqRankingTime[i];
		saveBuf[1 + (i * 20) + 3]  = dvlqRankingEnd[i];
		saveBuf[1 + (i * 20) + 4]  = dvlqRankingMedal[i * 4 + 0];
		saveBuf[1 + (i * 20) + 5]  = dvlqRankingMedal[i * 4 + 1];
		saveBuf[1 + (i * 20) + 6]  = dvlqRankingMedal[i * 4 + 2];
		saveBuf[1 + (i * 20) + 7]  = dvlqRankingMedal[i * 4 + 3];
		saveBuf[1 + (i * 20) + 8]  = dvlqRankingYear[i];
		saveBuf[1 + (i * 20) + 9]  = dvlqRankingMonth[i];
		saveBuf[1 + (i * 20) + 10] = dvlqRankingDay[i];
		saveBuf[1 + (i * 20) + 11] = dvlqRankingHour[i];
		saveBuf[1 + (i * 20) + 12] = dvlqRankingMinute[i];
		saveBuf[1 + (i * 20) + 13] = dvlqRankingSecond[i];
	}
	
	// セクションタイムランキング
	for(i = 0; i < 13; i++) {
		saveBuf[221 + (i * 10) + 0] = dvlqRankingSectionTime[i];
		saveBuf[221 + (i * 10) + 1] = dvlqRankingSectionEnd[i];
		saveBuf[221 + (i * 10) + 2] = dvlqRankingSectionYear[i];
		saveBuf[221 + (i * 10) + 3] = dvlqRankingSectionMonth[i];
		saveBuf[221 + (i * 10) + 4] = dvlqRankingSectionDay[i];
		saveBuf[221 + (i * 10) + 5] = dvlqRankingSectionHour[i];
		saveBuf[221 + (i * 10) + 6] = dvlqRankingSectionMinute[i];
		saveBuf[221 + (i * 10) + 7] = dvlqRankingSectionSecond[i];
	}
	
	sprintf(string[0], "config/DEVIL_QUAKE_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 361 * 4);
}

// ランキング読み込み
int dvlqLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/DEVIL_QUAKE_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 361 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		dvlqRankingGrade[i]         = saveBuf[1 + (i * 20) + 0];
		dvlqRankingLevel[i]         = saveBuf[1 + (i * 20) + 1];
		dvlqRankingTime[i]          = saveBuf[1 + (i * 20) + 2];
		dvlqRankingEnd[i]           = saveBuf[1 + (i * 20) + 3];
		dvlqRankingMedal[i * 4 + 0] = saveBuf[1 + (i * 20) + 4];
		dvlqRankingMedal[i * 4 + 1] = saveBuf[1 + (i * 20) + 5];
		dvlqRankingMedal[i * 4 + 2] = saveBuf[1 + (i * 20) + 6];
		dvlqRankingMedal[i * 4 + 3] = saveBuf[1 + (i * 20) + 7];
		dvlqRankingYear[i]          = saveBuf[1 + (i * 20) + 8];
		dvlqRankingMonth[i]         = saveBuf[1 + (i * 20) + 9];
		dvlqRankingDay[i]           = saveBuf[1 + (i * 20) + 10];
		dvlqRankingHour[i]          = saveBuf[1 + (i * 20) + 11];
		dvlqRankingMinute[i]        = saveBuf[1 + (i * 20) + 12];
		dvlqRankingSecond[i]        = saveBuf[1 + (i * 20) + 13];
	}
	
	// セクションタイムランキング
	for(i = 0; i < 13; i++) {
		dvlqRankingSectionTime[i]   = saveBuf[221 + (i * 10) + 0];
		dvlqRankingSectionEnd[i]    = saveBuf[221 + (i * 10) + 1];
		dvlqRankingSectionYear[i]   = saveBuf[221 + (i * 10) + 2];
		dvlqRankingSectionMonth[i]  = saveBuf[221 + (i * 10) + 3];
		dvlqRankingSectionDay[i]    = saveBuf[221 + (i * 10) + 4];
		dvlqRankingSectionHour[i]   = saveBuf[221 + (i * 10) + 5];
		dvlqRankingSectionMinute[i] = saveBuf[221 + (i * 10) + 6];
		dvlqRankingSectionSecond[i] = saveBuf[221 + (i * 10) + 7];
	}
	
	return 1;
}

// ランキング初期化
void dvlqInitRanking() {
	int i;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		dvlqRankingGrade[i]         = 0;
		dvlqRankingLevel[i]         = 0;
		dvlqRankingTime[i]          = 0;
		dvlqRankingEnd[i]           = 0;
		dvlqRankingMedal[i * 4 + 0] = 0;
		dvlqRankingMedal[i * 4 + 1] = 0;
		dvlqRankingMedal[i * 4 + 2] = 0;
		dvlqRankingMedal[i * 4 + 3] = 0;
		dvlqRankingYear[i]          = 0;
		dvlqRankingMonth[i]         = 0;
		dvlqRankingDay[i]           = 0;
		dvlqRankingHour[i]          = 0;
		dvlqRankingMinute[i]        = 0;
		dvlqRankingSecond[i]        = 0;
	}
	
	// セクションタイムランキング
	for(i = 0; i < 13; i++) {
		dvlqRankingSectionTime[i]   = 3600;
		dvlqRankingSectionEnd[i]    = 0;
		dvlqRankingSectionYear[i]   = 0;
		dvlqRankingSectionMonth[i]  = 0;
		dvlqRankingSectionDay[i]    = 0;
		dvlqRankingSectionHour[i]   = 0;
		dvlqRankingSectionMinute[i] = 0;
		dvlqRankingSectionSecond[i] = 0;
	}
}

// ランキング登録
int dvlqRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (dvlqIsBig) || (!dvlqLvUpBonus) || (dvlqStartLevel)) return -1;
	
	for(i = 0; i < 10; i++) {
		// ランクイン
		if(
		    (dvlqEndFlag[player] > dvlqRankingEnd[i]) || 
		    ((dvlqEndFlag[player] == dvlqRankingEnd[i]) && (dvlqGrade[player] > dvlqRankingGrade[i])) || 
		    ((dvlqEndFlag[player] == dvlqRankingEnd[i]) && (dvlqGrade[player] == dvlqRankingGrade[i]) && (gameTimer[player] < dvlqRankingTime[i]))
		  )
		{
			// ランキングをずらす
			for(j = 9; j > i; j--) {
				dvlqRankingGrade[j]         = dvlqRankingGrade[j - 1];
				dvlqRankingLevel[j]         = dvlqRankingLevel[j - 1];
				dvlqRankingTime[j]          = dvlqRankingTime[j - 1];
				dvlqRankingEnd[j]           = dvlqRankingEnd[j - 1];
				dvlqRankingMedal[j * 4 + 0] = dvlqRankingMedal[(j - 1) * 4 + 0];
				dvlqRankingMedal[j * 4 + 1] = dvlqRankingMedal[(j - 1) * 4 + 1];
				dvlqRankingMedal[j * 4 + 2] = dvlqRankingMedal[(j - 1) * 4 + 2];
				dvlqRankingMedal[j * 4 + 3] = dvlqRankingMedal[(j - 1) * 4 + 3];
				dvlqRankingYear[j]          = dvlqRankingYear[j - 1];
				dvlqRankingMonth[j]         = dvlqRankingMonth[j - 1];
				dvlqRankingDay[j]           = dvlqRankingDay[j - 1];
				dvlqRankingHour[j]          = dvlqRankingHour[j - 1];
				dvlqRankingMinute[j]        = dvlqRankingMinute[j - 1];
				dvlqRankingSecond[j]        = dvlqRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			dvlqRankingGrade[i]         = dvlqGrade[player];
			dvlqRankingLevel[i]         = dvlqLevel[player];
			dvlqRankingTime[i]          = gameTimer[player];
			dvlqRankingEnd[i]           = dvlqEndFlag[player];
			dvlqRankingMedal[i * 4 + 0] = dvlqMedalStat[player * 4 + 0];
			dvlqRankingMedal[i * 4 + 1] = dvlqMedalStat[player * 4 + 1];
			dvlqRankingMedal[i * 4 + 2] = dvlqMedalStat[player * 4 + 2];
			dvlqRankingMedal[i * 4 + 3] = dvlqMedalStat[player * 4 + 3];
			
			GetDateAndTime(&timebuf);
			dvlqRankingYear[i]          = timebuf[0];
			dvlqRankingMonth[i]         = timebuf[1];
			dvlqRankingDay[i]           = timebuf[2];
			dvlqRankingHour[i]          = timebuf[4];
			dvlqRankingMinute[i]        = timebuf[5];
			dvlqRankingSecond[i]        = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// セクションタイムランキング更新
int dvlqUpdateSectionTimeRanking(int player) {
	int i, timebuf[8], result;
	result = 0;
	
	if((playback) || (dvlqIsBig) || (!dvlqLvUpBonus) || (dvlqStartLevel)) return 0;
	
	for(i = 0; i < 13; i++) {
		if((dvlqSectionTime[i + player * 13] < dvlqRankingSectionTime[i]) && (dvlqSectionTime[i + player * 13] != 0)) {
			result++;
			
			dvlqRankingSectionTime[i] = dvlqSectionTime[i + player * 13];
			dvlqRankingSectionEnd[i] = dvlqEndFlag[player];
			
			GetDateAndTime(&timebuf);
			dvlqRankingSectionYear[i] = timebuf[0];
			dvlqRankingSectionMonth[i] = timebuf[1];
			dvlqRankingSectionDay[i] = timebuf[2];
			dvlqRankingSectionHour[i] = timebuf[4];
			dvlqRankingSectionMinute[i] = timebuf[5];
			dvlqRankingSectionSecond[i] = timebuf[6];
		}
	}
	
	return result;
}

// ランキング表示
void dvlqViewRanking(int player) {
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
			printFontGrid(1, 1, "DEVIL-QUAKE MODE RANKING >>", 6);
			printFontGrid(1, 3, "RANK GRADE LEVEL TIME", 4);
			
			for(i = 0; i < 10; i++) {
				if(dvlqRankingEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (dvlqRankingEnd[i] - 1) * 2, 320, 2);
				
				if(i == 0) sprintf(string[0], " 1ST");
				if(i == 1) sprintf(string[0], " 2ND");
				if(i == 2) sprintf(string[0], " 3RD");
				if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
				printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
				
				if((dvlqRankingGrade[i] >= 0) && (dvlqRankingGrade[i] <= 14)) {
					printFontGrid(6, 4 + i, dvlqStrGradeName[dvlqRankingGrade[i]], 7 * (cursor == i));
				} else {
					printFontGrid(6, 4 + i, "???", 7 * (cursor == i));
				}
				
				sprintf(string[0], "%d", dvlqRankingLevel[i]);
				printFontGrid(12, 4 + i, string[0], 7 * (cursor == i));
				
				getTime(dvlqRankingTime[i]);
				printFontGrid(18, 4 + i, string[0], 7 * (cursor == i));
			}
			
			for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
			
			if(!erasemode) {
				// メダル
				dvlqDrawMedal(8 + 0 * 16, 192, 1, dvlqRankingMedal[cursor * 4 + 0], -1);
				dvlqDrawMedal(8 + 1 * 16, 192, 0, dvlqRankingMedal[cursor * 4 + 1], -1);
				dvlqDrawMedal(8 + 2 * 16, 192, 5, dvlqRankingMedal[cursor * 4 + 2], -1);
				dvlqDrawMedal(8 + 3 * 16, 192, 2, dvlqRankingMedal[cursor * 4 + 3], -1);
				
				// 日付と時刻
				sprintf(string[0],
				        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
				        dvlqRankingYear[cursor], dvlqRankingMonth[cursor], dvlqRankingDay[cursor],
				        dvlqRankingHour[cursor], dvlqRankingMinute[cursor], dvlqRankingSecond[cursor]);
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
					dvlqInitRanking();
					dvlqSaveRanking(player);
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
			printFontGrid(1, 1, "<< DEVIL-QUAKE MODE SECTION TIME", 6);
			printFontGrid(1, 3, "SECTION   TIME     DATE", 4);
			printFontGrid(1, 28, "A/B:EXIT", 6);
			
			for(i = 0; i < 13; i++) {
				if(dvlqRankingSectionEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (dvlqRankingSectionEnd[i] - 1) * 2, 320, 2);
				
				sprintf(string[0], "%4d-%4d", i * 100, ((i + 1) * 100) - 1);
				printFontGrid(1, 4 + i, string[0], 0);
				
				getTime(dvlqRankingSectionTime[i]);
				printFontGrid(11, 4 + i, string[0], 0);
				
				temp = (dvlqRankingSectionYear[i] / 1000) * 1000;	// 年を下2桁だけ表示
				if(temp == 0) temp = 1;
				sprintf(string[0], "%02d/%02d/%02d", dvlqRankingSectionYear[i] % temp, dvlqRankingSectionMonth[i], dvlqRankingSectionDay[i]);
				printFontGrid(20, 4 + i, string[0], 0);
				
				sprintf(string[0], "%02d:%02d:%02d", dvlqRankingSectionHour[i], dvlqRankingSectionMinute[i], dvlqRankingSectionSecond[i]);
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
