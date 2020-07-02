//prefix:mase

//□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□
//
//    MASTER-EXTRA
//
//□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   グローバル変数の定義
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// システム
int maseModeNo = -1;				// モード番号
int maseVersion;					// バージョン番号（古いリプレイ再生用）
int maseCVersion = 0;				// 現在のバージョン

// レベル
int maseLevel;						// 現在の表示上のレベル
int maseSLevel;						// 内部のレベル（セクションCOOLで+100）
int maseSpeedIndex;					// 現在の落下速度番号

// 段位
int maseGrade;						// 現在の段位
int maseClass;						// 内部段位
int maseGPoint;						// 現在の内部ポイント
int maseGTimer;						// 内部ポイント減少タイマー
int maseGUpCount;					// このセクションで増加した内部段位の数
int maseFinalGrade;					// 最終的な暫定段位

// セクションタイム
int maseSTimer;						// セクションタイマー
int masePreSTimer;					// 前のセクションのセクションタイム
int maseSCoolCount;					// セクションタイムCOOL回数
int maseSCoolFlag;					// セクションタイムCOOLの判定をしたかどうかのフラグ
int maseSectionTime[10];			// このプレイのセクションタイム

// エンディング
int maseEndFlag;					// 完全クリアフラグ
int maseEndHeboris;					// ロール中のヘボリス回数
int maseEndLines;					// ロール中に消したライン数

// BGM
int maseBgmIndex;					// 現在のBGM番号

// メダル
int maseMedalStat[4];				// メダルの状態(0=なし 1=銅 2=銀 3=金)
int maseMedalAnim[4];				// メダル獲得アニメーション用カウンタ
int maseSkill;						// 合計ヘボリス回数

// 画面表示
int maseScore;						// スコア
int maseSHeboris;					// １セクション中に行ったヘボリス回数
int maseHeboCombo;					// 連続ヘボリス回数
int maseTSpinCombo;					// 連続T-SPIN回数
int maseTSpinFrame;					// T-SPIN表示の残り時間
int maseCoolFrame;					// COOL表示の残り時間
int maseRegretFrame;				// REGRET表示の残り時間

// 設定
int maseIsBig = 0;					// BIGかどうか
int maseBigMove = 1;				// BIG時の横移動単位
int maseGhost = 0;					// ゴーストの設定（0=LV0-99 1=常にON 2=常にOFF）
int maseLvUpBonus = 1;				// レベルアップボーナス
int maseTSpin = 1;					// T-SPINの種類
int maseTorikan = 25200;			// LV500とりカン基準タイム (7:00:00)
int mase20G = 0;					// 20Gモード

// ランキング変数
int maseRankingGrade[10];			// 段位
int maseRankingLevel[10];			// レベル
int maseRankingTime[10];			// タイム
int maseRankingEnd[10];				// クリアフラグ
int maseRankingMedal[4 * 10];		// メダル
int maseRankingYear[10];			// ランクイン日時（年）
int maseRankingMonth[10];			// ランクイン日時（月）
int maseRankingDay[10];				// ランクイン日時（日）
int maseRankingHour[10];			// ランクイン日時（時）
int maseRankingMinute[10];			// ランクイン日時（分）
int maseRankingSecond[10];			// ランクイン日時（秒）

// セクションタイムランキング変数
int maseRankingSectionTime[10];		// タイム
int maseRankingSectionLevel[10];	// レベル
int maseRankingSectionEnd[10];		// クリアフラグ
int maseRankingSectionYear[10];		// ランクイン日時（年）
int maseRankingSectionMonth[10];	// ランクイン日時（月）
int maseRankingSectionDay[10];		// ランクイン日時（日）
int maseRankingSectionHour[10];		// ランクイン日時（時）
int maseRankingSectionMinute[10];	// ランクイン日時（分）
int maseRankingSectionSecond[10];	// ランクイン日時（秒）

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   レベルアップテーブル
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// 速度
int maseLevelTable[30] =
{
	4, 6, 8, 10, 12, 16, 32, 48, 64, 80, 96, 112, 128, 144, 4, 32, 64, 96, 128, 160,
	192, 224, 256, 512, 768, 1024, 1280, 1024, 768, 5120
};

// 速度が変わるレベル
int maseLevelChange[30] = 
{
	30, 35, 40, 50, 60, 70, 80, 90, 100, 120, 140, 160, 170, 200, 220, 230, 233, 236, 239, 243,
	247, 251, 300, 330, 360, 400, 420, 450, 500, 10000
};

// wait値              0, 500, 600, 700, 800, 900,1000,1100,1200
int maseWait1[9] = {  25,  25,  25,  16,  12,  12,   6,   5,   4};
int maseWait2[9] = {  40,  25,  16,  12,   6,   6,   6,   6,   6};
int maseWait3[9] = {  30,  30,  30,  30,  30,  17,  17,  15,  15};
int maseWaitt[9] = {  14,   8,   8,   8,   8,   6,   6,   6,   6};
int maseWait5[9] = {  25,  25,  16,  12,   6,   6,   6,   5,   4};

// セクションCOOL規定タイム
int maseSectionCoolTable[9] = {52*60, 52*60, 49*60, 45*60, 45*60, 42*60, 42*60, 38*60, 38*60};

// セクションREGRET規定タイム
int maseSectionRegretTable[10] = {5400, 4500, 4500, 4080, 3600, 3600, 3000, 3000, 3000, 3000};

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   内部段位テーブル
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// 段位ポイント上昇テーブル
int maseGradePoint1[11] = {10,10,10,10,10, 5, 5, 5, 5, 5, 2};
int maseGradePoint2[11] = {20,20,20,15,15,15,10,10,10,10,12};
int maseGradePoint3[11] = {40,30,30,30,20,20,20,15,15,15,13};
int maseGradePoint4[11] = {50,40,40,40,40,30,30,30,30,30,30};

// コンボの倍率
int maseGradeCombo[11 * 4] = 
{
//    0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	100, 100, 120, 120, 120, 120, 120, 120, 120, 120, 150,
	100, 100, 140, 150, 160, 170, 180, 190, 200, 210, 250,
	100, 100, 150, 180, 200, 220, 230, 240, 250, 260, 300,
};

// 段位ポイントが1減るまでの時間
int maseGradeTimeLimit[32] = 
{
	125, 80, 80, 50, 45, 45, 45, 45, 40, 40, 40, 40, 30, 30, 30, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 10
};

// 暫定段位が増える内部段位
int maseGradeNorm[17] = 
{
	1, 2, 3, 4, 5, 7, 9, 12, 15, 18, 19, 20, 23, 25, 27, 29, 31
};

// 段位の表示名
str maseStrGradeName[33] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0～ 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9～17
	"M1", "M2", "M3", "M4", "M5", "M6", "M7", "M8", "M9",	// 18～26
	 "M", "MK", "MV", "MO", "MM", "GM"						// 27～32
};

// 裏段位の表示名
str maseStrSecretGradeName[19] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0～ 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9～17
	"GM"													// 18
};

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   BGMテーブル
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int maseBgmNo[4]     = {0,1,2,6};				// BGM番号（000-499、500-699、700-899、999）
int maseFadeLv[3]    = {485,685,10000};			// BGMをフェードアウトさせるレベル
int maseBgmChange[3] = {500,700,10000};			// BGMを切り替えるレベル

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベント発生時のメイン関数
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void masePluginEvent(int player, int event, int *param) {
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != maseModeNo)) return;
	
	if(event == 0) {
		maseModeNo = addModePlugin("MASTER-EXTRA");	// モードを登録する
	} else if(event == 7) {
		if(!ending[player]) maseMoveInit(player);	// ブロック出現
	} else if(event == 12) {
		if(!ending[player]) maseCalcScore(player, param[0]);	// スコア計算
		else maseCalcScore2(player, param[0]);
	} else if(event == 15) {
		maseViewScore(player);	// スコア表示
	} else if(event == 17) {
		maseSetting(player, param);	// 設定画面
	} else if(event == 18) {
		masePlayerInitial(player);	// 初期化処理
	} else if(event == 21) {
		maseResult(player, param);	// 結果表示
	} else if(event == 24) {
		maseEndingStart(player);	// エンディング突入
	} else if(event == 25) {
		maseExcellent(player, param);	// エンディング終了
	} else if(event == 28) {
		maseIncrementTime(player);	// 時間を進める
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		maseSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		maseLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		maseLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		maseReplayDetail();	// リプレイ詳細
	} else if(event == 60) {
		maseInitCombo(player);	// コンボ初期化
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   初期化処理
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void masePlayerInitial(int player) {
	int i;
	
	// バージョン
	if(!playback) maseVersion = maseCVersion;
	
	// プラグイン側の変数を初期化
	maseLevel = -1;
	maseSLevel = -1;
	maseSpeedIndex = 0;
	maseGrade = 0;
	maseClass = 0;
	maseGPoint = 0;
	maseGTimer = 0;
	maseGUpCount = 0;
	maseFinalGrade = 0;
	maseSTimer = 0;
	masePreSTimer = 0;
	maseSCoolCount = 0;
	maseSCoolFlag = 0;
	maseEndFlag = 0;
	maseEndHeboris = 0;
	maseEndLines = 0;
	maseBgmIndex = 0;
	maseScore = 0;
	maseSHeboris = 0;
	maseHeboCombo = 0;
	maseTSpinCombo = 0;
	maseTSpinFrame = 0;
	maseCoolFrame = 0;
	maseRegretFrame = 0;
	maseSkill = 0;
	
	for(i = 0; i < 10; i++) maseSectionTime[i] = 0;
	
	for(i = 0; i < 4; i++) {
		maseMedalStat[i] = 0;
		maseMedalAnim[i] = -1;
	}
	
	// システム側の変数を変える
	enable_combo[player] = 1;
	speedtype[player] = 2;
	bgmlv = maseBgmNo[0];
	backno = maseLevel / 100;
	
	// ゲーム設定を反映させる
	maseApplyGameSetting(player);
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ゲーム設定を反映させる
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseApplyGameSetting(int player) {
	IsBig[player] = maseIsBig;
	BigMove[player] = maseBigMove;
	if(maseGhost == 2) ghost[player] = 0;
	tspin_type[player] = maseTSpin;
	
	// 初期速度を設定
	maseSpeedUp(player);
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   スピードアップ
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseSpeedUp(int player) {
	int temp, secinlv;
	
	// スピードを変える
	if(mase20G) {
		sp[player] = 5120;
	} else {
		while(maseSLevel >= maseLevelChange[maseSpeedIndex]) maseSpeedIndex++;
		sp[player] = maseLevelTable[maseSpeedIndex];
	}
	
	// wait値
	if(maseSLevel < 500) {
		wait1[player] = maseWait1[0];
		wait2[player] = maseWait2[0];
		wait3[player] = maseWait3[0];
		waitt[player] = maseWaitt[0];
		wait5[player] = maseWait5[0];
	} else {
		wait1[player] = maseWait1[(maseSLevel / 100) - 4];
		wait2[player] = maseWait2[(maseSLevel / 100) - 4];
		wait3[player] = maseWait3[(maseSLevel / 100) - 4];
		waitt[player] = maseWaitt[(maseSLevel / 100) - 4];
		wait5[player] = maseWait5[(maseSLevel / 100) - 4];
	}
	
	// セクションCOOL判定
	secinlv = maseLevel - ((maseLevel / 100) * 100);	// レベルの下2桁
	
	if((secinlv >= 70) && (maseLevel < 900) && (maseSCoolFlag == 0)) {
		maseSCoolFlag = 1;
		
		if( (maseSTimer <= maseSectionCoolTable[maseLevel / 100]) && ((maseSTimer <= masePreSTimer + 120) || (maseLevel < 100)) ) {
			maseSCoolFlag = 2;
		}
		
		// このセクションのLV70通過タイムを記録
		masePreSTimer = maseSTimer;
	}
	
	// セクションCOOL表示
	if((secinlv >= 82) && (maseSCoolFlag == 2)) {
		maseSCoolFlag = 3;
		maseCoolFrame = 180;
		PlaySE(se_cool);
	}
	
	// BGMフェードアウト
	temp = maseSLevel;
	if((maseSCoolFlag >= 2) && (secinlv >= 85)) temp = temp + 100;
	if((temp >= maseFadeLv[maseBgmIndex]) && (fadelv == 0)) fadelv = 1;
	
	// BGM切り替え
	temp = 0;
	while(maseSLevel >= maseBgmChange[maseBgmIndex]) {
		maseBgmIndex++;
		bgmlv = maseBgmNo[maseBgmIndex];
		if(onRecord[player]) temp = 1;
	}
	if(temp) PlayBGM();
	
	// ゴーストを消す
	if((maseSLevel >= 100) && (maseGhost == 0)) ghost[player] = 0;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ブロック出現時の処理
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseMoveInit(int player) {
	int temp;
	
	// 最初のフレームなら
	if(statc[player * 10 + 3] == 0) {
		// レベルアップ処理
		if(maseLevel >= 900) temp = 98;	// LV998
		else temp = 99;
		
		if(maseLevel % 100 != temp) {
			// レベル+1
			maseLevel++;
			maseSLevel++;
			if(maseLevel > 999) maseLevel = 999;
			if(maseSLevel > 1200) maseSLevel = 1200;
			
			// レベルストップ音
			if(maseLevel % 100 == temp) PlaySE(se_lvstop);
			
			// スピードアップ
			maseSpeedUp(player);
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   スコア計算（通常時）
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseCalcScore(int player, int lines) {
	int temp, temp2, nextsec, secinlv, index, point, combobonus, lv, all;
	
	lv = maseLevel;	// 上がる前のレベル
	secinlv = maseLevel - ((maseLevel / 100) * 100);	// レベルの下2桁
	
	// ヘボリス回数増加
	if(lines >= 4) {
		maseSkill++;
		maseSHeboris++;
		maseHeboCombo++;
		
		// SKメダル獲得
		if((maseSkill == 15) || (maseSkill == 25) || (maseSkill == 40)) {
			PlaySE(se_medal);
			maseMedalStat[3]++;
			maseMedalAnim[3] = 0;
		}
		
		// １セクション中に規定回数のヘボリスで偽COOL
		if(secinlv < 94) {
			if(maseLevel <= 99) temp = 3;
			else if(maseLevel <= 199) temp = 6;
			else temp = 4;
			
			if(maseSHeboris >= temp) {
				maseSHeboris = 0;
				maseCoolFrame = 180;
				PlaySE(se_cool);
			}
		}
		
		// 3回連続ヘボリスで偽COOL
		if(maseHeboCombo == 3) {
			maseCoolFrame = 180;
			PlaySE(se_cool);
		}
	} else {
		maseHeboCombo = 0;
	}
	
	// 全消し
	if(isBravo(player)) {
		all = 1;
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		
		// ACメダル獲得
		if(maseMedalStat[1] < 3) {
			PlaySE(se_medal);
			maseMedalStat[1]++;
			maseMedalAnim[1] = 0;
		}
	} else {
		all = 0;
	}
	
	// COメダル獲得
	if(combo2[player] == 4) {
		if(maseMedalStat[2] < 1) {
			PlaySE(se_medal);
			maseMedalStat[2] = 1;
			maseMedalAnim[2] = 0;
		}
	} else if(combo2[player] == 5) {
		if(maseMedalStat[2] < 2) {
			PlaySE(se_medal);
			maseMedalStat[2] = 2;
			maseMedalAnim[2] = 0;
		}
	} else if(combo2[player] == 7) {
		if(maseMedalStat[2] < 3) {
			PlaySE(se_medal);
			maseMedalStat[2] = 3;
			maseMedalAnim[2] = 0;
		}
	}
	
	// T-SPIN
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		maseTSpinFrame = 120;
		
		// 2連続で偽COOL
		maseTSpinCombo++;
		if(maseTSpinCombo == 2) {
			maseCoolFrame = 180;
			PlaySE(se_cool);
		}
		
		// T-SPINトリプルで偽COOL
		if(lines >= 3) {
			maseCoolFrame = 180;
			PlaySE(se_cool);
		}
	} else {
		maseTSpinCombo = 0;
	}
	
	// 内部段位ポイント加算
	if(maseClass < 31) {
		index = maseClass;
		if(index > 10) index = 10;
		
		if(lines == 1) point = maseGradePoint1[index] * ((maseLevel / 250) + 1);
		if(lines == 2) point = maseGradePoint2[index] * ((maseLevel / 250) + 1);
		if(lines == 3) point = maseGradePoint3[index] * ((maseLevel / 250) + 1);
		if(lines >= 4) point = maseGradePoint4[index] * ((maseLevel / 250) + 1);
		
		combobonus = combo2[player];
		if(combobonus > 10) combobonus = 10;
		
		temp = (point * 10) * maseGradeCombo[combobonus + (lines - 1) * 11] / 1000;
		maseGPoint = maseGPoint + temp;
		
		// 内部段位上昇
		if(maseGPoint >= 100) {
			maseGPoint = 0;
			maseGTimer = 0;
			maseClass++;
			maseGUpCount++;
			if(maseClass >= maseGradeNorm[maseGrade]) maseGrade++;
		}
	}
	
	// レベルアップ
	nextsec = maseLevel / 100 * 100 + 100;	// 次のセクション
	
	if(maseLvUpBonus) {
		maseLevel = maseLevel + lines + ((lines >= 3) * (lines - 2));
		maseSLevel = maseSLevel + lines + ((lines >= 3) * (lines - 2));
	} else {
		maseLevel = maseLevel + lines;
		maseSLevel = maseSLevel + lines;
	}
	
	// レベルストップ音
	if(maseLevel >= 900) temp = 98;	// LV998
	else temp = 99;
	if(maseLevel % 100 == temp) PlaySE(se_lvstop);
	
	// 次のセクション
	if((maseLevel >= nextsec) || (maseLevel >= 999)) {
		// REGRET判定
		if(maseSTimer > maseSectionRegretTable[(nextsec / 100) - 1]) {
			PlaySE(se_regret);
			maseRegretFrame = 180;
			
			if(maseGUpCount >= 2) {
				maseGrade--;
				if(maseGrade < 0) maseGrade = 0;
				maseClass = maseGradeNorm[maseGrade] - 1;
				maseGPoint = 0;
				maseGTimer = 0;
			}
		}
		
		// セクションCOOL
		if(maseSCoolFlag >= 2) {
			maseSCoolCount++;
			maseSLevel = maseSLevel + 100;
			if(maseSLevel > 1200) maseSLevel = 1200;
		}
		
		// STメダル
		maseMedalST(player, (nextsec / 100) - 1);
		
		// いろいろ初期化
		maseSTimer = 0;
		maseGUpCount = 0;
		maseSCoolFlag = 0;
		maseSHeboris = 0;
		
		if(maseLevel >= 999) {
			// エンディング
			maseLevel = 999;
			ending[player] = 1;
			timeOn[player] = 0;
			maseEndFlag = 1;
		} else if((nextsec == 500) && (gameTimer[player] > maseTorikan) && (maseTorikan > 0)) {
			// LV500とりカン
			maseLevel = 500;
			ending[player] = 4;
			timeOn[player] = 0;
			resetStatc(player);
			stat[player] = 10;
			StopAllBGM();
		} else {
			// レベルアップ音
			PlaySE(se_levelup);
			
			// 背景切り替え
			bgfadesw = 1;
			bgfadebg = nextsec / 100;
		}
	}
	
	// スピードアップ
	maseSpeedUp(player);
	
	// スコア加算
	temp = wait3[player] - bactivetime[player];
	if(temp < 0) temp = 0;
	
	if(maseLvUpBonus) temp2 = lines + ((lines >= 3) * (lines - 2));
	else temp2 = lines;
	
	maseScore = maseScore + ((lv + lines) / 4 + qdrop[player] + (sdrop[player] / 2)) * temp2 * cmbpts[player] + temp + (maseLevel / 4) * (all + 1);
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   スコア計算（ロール時）
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseCalcScore2(int player, int lines) {
	// ライン数増加
	maseEndLines = maseEndLines + lines;
	
	// ヘボリス回数増加
	if(lines >= 4) {
		maseEndHeboris++;
		maseHeboCombo++;
		
		// 3回連続ヘボリスで偽COOL
		if(maseHeboCombo == 3) {
			maseCoolFrame = 180;
			PlaySE(se_cool);
		}
	} else {
		maseHeboCombo = 0;
	}
	
	// T-SPIN
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		maseTSpinFrame = 120;
		
		// 2連続で偽COOL
		maseTSpinCombo++;
		if(maseTSpinCombo == 2) {
			maseCoolFrame = 180;
			PlaySE(se_cool);
		}
		
		// T-SPINトリプルで偽COOL
		if(lines >= 3) {
			maseCoolFrame = 180;
			PlaySE(se_cool);
		}
	} else {
		maseTSpinCombo = 0;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   STメダル獲得
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseMedalST(int player, int section) {
	// セクションタイムを記録
	maseSectionTime[section] = maseSTimer;
	
	// STメダル獲得判定
	if((!playback) && (!maseIsBig) && (maseLvUpBonus) && (!mase20G)) {
		if((maseSTimer < maseRankingSectionTime[section]) && (maseMedalStat[0] < 3)) {
			PlaySE(se_medal);
			maseMedalStat[0] = 3;
			maseMedalAnim[0] = 0;
		} else if((maseSTimer < maseRankingSectionTime[section] + 300) && (maseMedalStat[0] < 2)) {
			PlaySE(se_medal);
			maseMedalStat[0] = 2;
			maseMedalAnim[0] = 0;
		} else if((maseSTimer < maseRankingSectionTime[section] + 600) && (maseMedalStat[0] < 1)) {
			PlaySE(se_medal);
			maseMedalStat[0] = 1;
			maseMedalAnim[0] = 0;
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   コンボ初期化
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseInitCombo(int player) {
	maseHeboCombo = 0;
	maseTSpinCombo = 0;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   時間を進める
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseIncrementTime(int player) {
	// セクションタイム増加
	if(timeOn[player]) maseSTimer++;
	
	// 段位ポイントを減少
	if((stat[player] == 4) && (maseGPoint > 0) && (!ending[player]) && (timeOn[player])) {
		if(combo2[player] == 0) maseGTimer++;
		
		if(maseGTimer >= maseGradeTimeLimit[maseClass]) {
			maseGTimer = 0;
			maseGPoint--;
		}
	}
	
	// ロール終了
	if((ending[player] == 2) && (edrec[player] >= 3238)) {
		onRecord[player] = 0;
		ending[player] = 3;
		stat[player] = 10;
		maseEndFlag = 2;
		resetStatc(player);
		maseFinalGrade = maseCalcFinalGrade(player);
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   エンディング突入
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseEndingStart(int player) {
	resetStatc(player);
	
	if(maseLevel >= 999) {
		// エンディング
		ending[player] = 2;
		stat[player] = 4;
		ending_timeOn[player] = 1;
		
		if((maseGrade >= 15) && (maseSCoolCount >= 9)) {
			// 消えロール
			hidden[player] = 9;
			shadowtime[player] = -60;
			objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
		} else {
			// 見えロール
			hidden[player] = 8;
			shadowtime[player] = 300;
		}
		
		bgmlv = maseBgmNo[3];
		PlayBGM();
	} else {
		ending[player] = 3;
		onRecord[player] = 0;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   エンディング終了
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseExcellent(int player, int *param) {
	statc[player * 10 + 1]++;
	
	// 完全クリア
	if(maseLevel >= 999) {
		if(statc[player * 10 + 1] == 1) {
			// ブロックを見えるようにする
			if(hidden[player] == 9) hidden[player] = 0;
			else disableShadowTimer(player);
		}
		
		// 花火
		if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 30)) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			statc[player * 10 + 2]++;
		}
		
		if(maseFinalGrade >= 32) {
			// YOU ARE GRAND MASTER!!
			param[0] = 1;
		} else {
			// EXCELLENT
			param[0] = 0;
			printTinyFont(foffset[player] + 20, fyoffset[player] + 116, "MASTER MODE");
			printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
		}
	}
	// とりカン
	else {
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

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   最終的な暫定段位を算出
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int maseCalcFinalGrade(int player) {
	int result, endingpoint, allclear;
	
	// ロール中の成績
	if(maseLevel >= 999) {
		if(hidden[player] == 9) {
			// 消えロール
			if(maseEndFlag == 2) allclear = 16;
			else allclear = 0;
			endingpoint = (allclear + (maseEndHeboris * 6) + maseEndLines) / 10;
		} else {
			// 見えロール
			if(maseEndFlag == 2) allclear = 50;
			else allclear = 0;
			endingpoint = (allclear + (maseEndHeboris * 10) + maseEndLines) / 100;
		}
	} else {
		endingpoint = 0;
	}
	
	result = maseGrade + maseSCoolCount + endingpoint;
	if(result > 32) result = 32;
	
	return result;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   結果表示
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseResult(int player, int *param) {
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
			
			// 段位を算出
			maseFinalGrade = maseCalcFinalGrade(player);
			
			// ランキング登録
			statc[player * 10 + 2] = maseRegistRanking(player);
			statc[player * 10 + 3] = maseUpdateSectionTimeRanking(player);
			if((statc[player * 10 + 2] != -1) || (statc[player * 10 + 3] != 0)) maseSaveRanking(player);
			
			// 裏段位判定
			statc[player * 10 + 4] = checkSecretGrade(player);
		}
		
		// 段位表示
		if(maseFinalGrade < 9)		// 9～1
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108,   0, ((count % 4 / 2) * 216) + (maseFinalGrade * 24), 90, 24);
		else if(maseFinalGrade < 18)	// S1～S9
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108,  90, ((count % 4 / 2) * 216) + ((maseFinalGrade -  9) * 24), 90, 24);
		else if(maseFinalGrade < 27)	// m1～m9
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108, 180, ((count % 4 / 2) * 216) + ((maseFinalGrade - 18) * 24), 90, 24);
		else if(maseFinalGrade < 32)	// M～MM
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108, 270, ((count % 4 / 2) * 216) + ((maseFinalGrade - 27) * 24), 90, 24);
		else							// Gm
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
		sprintf(string[0], "%13d", maseScore);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 67, string[0], 0);
		
		printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LEVEL");
		sprintf(string[0], "%13d", maseLevel);
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
			sprintf(string[0], "%13s", maseStrSecretGradeName[statc[player * 10 + 4]]);
			printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   スコア表示
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseViewScore(int player) {
	int i, x, y, color, kind, temp;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// メダル（通常）
	for(i = 0; i < 4; i++) {
		if((maseMedalAnim[i] < 0) || (maseMedalAnim[i] > 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 17;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			if(i == 0) kind = 1;
			if(i == 1) kind = 0;
			if(i == 2) kind = 5;
			if(i == 3) kind = 2;
			maseDrawMedal(x, y, kind, maseMedalStat[i], maseMedalAnim[i]);
		}
	}
	
	// メダル（アニメ中）
	for(i = 0; i < 4; i++) {
		if((maseMedalAnim[i] >= 0) && (maseMedalAnim[i] <= 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 17;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			if(i == 0) kind = 1;
			if(i == 1) kind = 0;
			if(i == 2) kind = 5;
			if(i == 3) kind = 2;
			maseDrawMedal(x, y, kind, maseMedalStat[i], maseMedalAnim[i]);
			maseMedalAnim[i]++;
		}
	}
	
	// レベル（分子）
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(maseLevel == -1) sprintf(string[0], "%4d", 0);	// -1なら0と表示する(内部的には最初は-1になっている)
	else sprintf(string[0], "%4d", maseLevel);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// レベル（横線）
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	temp = sp[player] / 128;
	if(temp > 22) temp = 22;
	ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22 - temp, 143, 22, 1);
	
	// レベル（分母）
	if(maseLevel >= 900) sprintf(string[0], "%4d", 999);
	else sprintf(string[0], "%4d", maseLevel / 100 * 100 + 100);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, string[0], color);
	
	// タイム
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
	
	// T-SPIN/COOL/REGRET表示
	if(maseTSpinFrame > 0) {
		maseTSpinFrame--;
		printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "T-SPIN");
	} else if(maseCoolFrame > 0) {
		maseCoolFrame--;
		printTinyFont(foffset[player] + 37, fyoffset[player] + 208, "COOL");
	} else if(maseRegretFrame > 0) {
		maseRegretFrame--;
		printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "REGRET");
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   メダルを表示
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseDrawMedal(int x, int y, int kind, int color, int anim) {
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

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   BGM読み込み
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 4; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/4)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(maseBgmNo[i]);
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   設定画面
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	maseLoadConfig();	// 設定を読み込み
	
	if(!maseLoadRanking(player)) maseInitRanking();	// ランキング読み込み
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "MASTER-EXTRA OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT E:RANKING", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "BIG",            7 * (cursor == 0));
		printFontGrid(2, 4, "BIG MOVE",       7 * (cursor == 1));
		printFontGrid(2, 5, "GHOST BLOCK",    7 * (cursor == 2));
		printFontGrid(2, 6, "LEVEL UP BONUS", 7 * (cursor == 3));
		printFontGrid(2, 7, "T-SPIN",         7 * (cursor == 4));
		printFontGrid(2, 8, "TIME LIMIT",     7 * (cursor == 5));
		printFontGrid(2, 9, "20G MODE",       7 * (cursor == 6));
		
		// 設定値表示
		if(!maseIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!maseBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(maseGhost == 0) sprintf(string[0], "LV100");
		else if(maseGhost == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(!maseLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(maseTSpin == 0) sprintf(string[0], "OFF");
		else if(maseTSpin == 1) sprintf(string[0], "LINE CLEAR");
		else if(maseTSpin == 2) sprintf(string[0], "IMMOBILE");
		else if(maseTSpin == 3) sprintf(string[0], "3-CORNER");
		else sprintf(string[0], "3-CORNER NO KICK");
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		if(!maseTorikan) sprintf(string[0], "OFF");
		else getTime(maseTorikan);
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		if(!mase20G) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
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
			
			if(cursor == 0) maseIsBig = !maseIsBig;
			if(cursor == 1) maseBigMove = !maseBigMove;
			if(cursor == 2) {
				maseGhost = maseGhost + move;
				if(maseGhost < 0) maseGhost = 2;
				if(maseGhost > 2) maseGhost = 0;
			}
			if(cursor == 3) maseLvUpBonus = !maseLvUpBonus;
			if(cursor == 4) {
				maseTSpin = maseTSpin + move;
				if(maseTSpin < 0) maseTSpin = 4;
				if(maseTSpin > 4) maseTSpin = 0;
			}
			if(cursor == 5) {
				maseTorikan = maseTorikan + (move * 60);
				if(maseTorikan < 0) maseTorikan = 72000;
				if(maseTorikan > 72000) maseTorikan = 0;
			}
			if(cursor == 6) mase20G = !mase20G;
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
			maseSaveConfig();	// 設定を保存
			return;
		}
		
		// ランキング表示
		if(getPushState(player, 8)) {
			maseViewRanking(player);
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   設定を保存
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// 設定内容
	saveBuf[1] = maseIsBig;
	saveBuf[2] = maseBigMove;
	saveBuf[3] = maseGhost;
	saveBuf[4] = maseLvUpBonus;
	saveBuf[5] = maseTSpin;
	saveBuf[6] = maseTorikan;
	saveBuf[7] = mase20G;
	
	SaveFile("config/MASTER_EXTRA_CONFIG.SAV", &saveBuf, 30 * 4);
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   設定を読み込み
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int maseLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/MASTER_EXTRA_CONFIG.SAV", &saveBuf, 30 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// 設定内容
	maseIsBig = saveBuf[1];
	maseBigMove = saveBuf[2];
	maseGhost = saveBuf[3];
	maseLvUpBonus = saveBuf[4];
	maseTSpin = saveBuf[5];
	maseTorikan = saveBuf[6];
	mase20G = saveBuf[7];
	
	return 1;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   リプレイ保存
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseSaveReplay(int player) {
	saveBuf[900] = maseIsBig;
	saveBuf[901] = maseBigMove;
	saveBuf[902] = maseGhost;
	saveBuf[903] = maseLvUpBonus;
	saveBuf[904] = maseTSpin;
	saveBuf[905] = maseTorikan;
	saveBuf[906] = maseLevel;
	saveBuf[907] = maseScore;
	saveBuf[908] = maseFinalGrade;
	saveBuf[909] = maseVersion;
	saveBuf[910] = mase20G;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   リプレイ読み込み
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseLoadReplay(int player) {
	maseIsBig = saveBuf[900];
	maseBigMove = saveBuf[901];
	maseGhost = saveBuf[902];
	maseLvUpBonus = saveBuf[903];
	maseTSpin = saveBuf[904];
	maseTorikan = saveBuf[905];
	maseVersion = saveBuf[909];
	mase20G = saveBuf[910];
	
	// ゲーム設定を反映させる
	maseApplyGameSetting(player);
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   リプレイ詳細
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseReplayDetail() {
	printFontGrid(1, 5, "GRADE", 0);
	if((saveBuf[908] >= 0) && (saveBuf[908] <= 32)) {
		printFontGrid(22, 5, maseStrGradeName[saveBuf[908]], 0);
	} else {
		printFontGrid(22, 5, "???", 0);
	}
	
	printFontGrid(1, 6, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[907]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[906]);
	printFontGrid(22, 7, string[0], 0);
	
	printFontGrid(1, 9, "BIG", 0);
	if(!saveBuf[900]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 9, string[0], 0);
	
	printFontGrid(1, 10, "BIG MOVE", 0);
	if(!saveBuf[901]) sprintf(string[0], "1 BLOCK");
	else sprintf(string[0], "2 BLOCKS");
	printFontGrid(22, 10, string[0], 0);
	
	printFontGrid(1, 11, "GHOST BLOCK", 0);
	if(saveBuf[902] == 0) sprintf(string[0], "LV100");
	else if(saveBuf[902] == 1) sprintf(string[0], "ON");
	else sprintf(string[0], "OFF");
	printFontGrid(22, 11, string[0], 0);
	
	printFontGrid(1, 12, "LEVEL UP BONUS", 0);
	if(!saveBuf[903]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 12, string[0], 0);
	
	printFontGrid(1, 13, "T-SPIN", 0);
	if(saveBuf[904] == 0) sprintf(string[0], "OFF");
	else if(saveBuf[904] == 1) sprintf(string[0], "LINE CLEAR");
	else if(saveBuf[904] == 2) sprintf(string[0], "IMMOBILE");
	else if(saveBuf[904] == 3) sprintf(string[0], "3-CORNER");
	else sprintf(string[0], "3-CORNER NO KICK");
	printFontGrid(22, 13, string[0], 0);
	
	printFontGrid(1, 14, "TIME LIMIT", 0);
	if(!saveBuf[905]) sprintf(string[0], "OFF");
	else getTime(saveBuf[905]);
	printFontGrid(22, 14, string[0], 0);
	
	printFontGrid(1, 15, "20G MODE", 0);
	if(!saveBuf[910]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 15, string[0], 0);
	
	printFontGrid(1, 17, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[909]);
	printFontGrid(22, 17, string[0], 0);
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ランキング保存
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0]  = maseRankingGrade[i];
		saveBuf[1 + (i * 20) + 1]  = maseRankingLevel[i];
		saveBuf[1 + (i * 20) + 2]  = maseRankingTime[i];
		saveBuf[1 + (i * 20) + 3]  = maseRankingEnd[i];
		saveBuf[1 + (i * 20) + 4]  = maseRankingMedal[i * 4 + 0];
		saveBuf[1 + (i * 20) + 5]  = maseRankingMedal[i * 4 + 1];
		saveBuf[1 + (i * 20) + 6]  = maseRankingMedal[i * 4 + 2];
		saveBuf[1 + (i * 20) + 7]  = maseRankingMedal[i * 4 + 3];
		saveBuf[1 + (i * 20) + 8]  = maseRankingYear[i];
		saveBuf[1 + (i * 20) + 9]  = maseRankingMonth[i];
		saveBuf[1 + (i * 20) + 10] = maseRankingDay[i];
		saveBuf[1 + (i * 20) + 11] = maseRankingHour[i];
		saveBuf[1 + (i * 20) + 12] = maseRankingMinute[i];
		saveBuf[1 + (i * 20) + 13] = maseRankingSecond[i];
	}
	
	// セクションタイムランキング
	for(i = 0; i < 10; i++) {
		saveBuf[221 + (i * 10) + 0] = maseRankingSectionTime[i];
		saveBuf[221 + (i * 10) + 1] = maseRankingSectionLevel[i];
		saveBuf[221 + (i * 10) + 2] = maseRankingSectionEnd[i];
		saveBuf[221 + (i * 10) + 3] = maseRankingSectionYear[i];
		saveBuf[221 + (i * 10) + 4] = maseRankingSectionMonth[i];
		saveBuf[221 + (i * 10) + 5] = maseRankingSectionDay[i];
		saveBuf[221 + (i * 10) + 6] = maseRankingSectionHour[i];
		saveBuf[221 + (i * 10) + 7] = maseRankingSectionMinute[i];
		saveBuf[221 + (i * 10) + 8] = maseRankingSectionSecond[i];
	}
	
	sprintf(string[0], "config/MASTER_EXTRA_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 331 * 4);
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ランキング読み込み
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int maseLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/MASTER_EXTRA_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 331 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		maseRankingGrade[i]         = saveBuf[1 + (i * 20) + 0];
		maseRankingLevel[i]         = saveBuf[1 + (i * 20) + 1];
		maseRankingTime[i]          = saveBuf[1 + (i * 20) + 2];
		maseRankingEnd[i]           = saveBuf[1 + (i * 20) + 3];
		maseRankingMedal[i * 4 + 0] = saveBuf[1 + (i * 20) + 4];
		maseRankingMedal[i * 4 + 1] = saveBuf[1 + (i * 20) + 5];
		maseRankingMedal[i * 4 + 2] = saveBuf[1 + (i * 20) + 6];
		maseRankingMedal[i * 4 + 3] = saveBuf[1 + (i * 20) + 7];
		maseRankingYear[i]          = saveBuf[1 + (i * 20) + 8];
		maseRankingMonth[i]         = saveBuf[1 + (i * 20) + 9];
		maseRankingDay[i]           = saveBuf[1 + (i * 20) + 10];
		maseRankingHour[i]          = saveBuf[1 + (i * 20) + 11];
		maseRankingMinute[i]        = saveBuf[1 + (i * 20) + 12];
		maseRankingSecond[i]        = saveBuf[1 + (i * 20) + 13];
	}
	
	// セクションタイムランキング
	for(i = 0; i < 10; i++) {
		maseRankingSectionTime[i]   = saveBuf[221 + (i * 10) + 0];
		maseRankingSectionLevel[i]  = saveBuf[221 + (i * 10) + 1];
		maseRankingSectionEnd[i]    = saveBuf[221 + (i * 10) + 2];
		maseRankingSectionYear[i]   = saveBuf[221 + (i * 10) + 3];
		maseRankingSectionMonth[i]  = saveBuf[221 + (i * 10) + 4];
		maseRankingSectionDay[i]    = saveBuf[221 + (i * 10) + 5];
		maseRankingSectionHour[i]   = saveBuf[221 + (i * 10) + 6];
		maseRankingSectionMinute[i] = saveBuf[221 + (i * 10) + 7];
		maseRankingSectionSecond[i] = saveBuf[221 + (i * 10) + 8];
	}
	
	return 1;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ランキング初期化
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseInitRanking() {
	int i;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		maseRankingGrade[i]         = 0;
		maseRankingLevel[i]         = 0;
		maseRankingTime[i]          = 0;
		maseRankingEnd[i]           = 0;
		maseRankingMedal[i * 4 + 0] = 0;
		maseRankingMedal[i * 4 + 1] = 0;
		maseRankingMedal[i * 4 + 2] = 0;
		maseRankingMedal[i * 4 + 3] = 0;
		maseRankingYear[i]          = 0;
		maseRankingMonth[i]         = 0;
		maseRankingDay[i]           = 0;
		maseRankingHour[i]          = 0;
		maseRankingMinute[i]        = 0;
		maseRankingSecond[i]        = 0;
	}
	
	// セクションタイムランキング
	for(i = 0; i < 10; i++) {
		maseRankingSectionTime[i]   = 5400;
		maseRankingSectionLevel[i]  = 0;
		maseRankingSectionEnd[i]    = 0;
		maseRankingSectionYear[i]   = 0;
		maseRankingSectionMonth[i]  = 0;
		maseRankingSectionDay[i]    = 0;
		maseRankingSectionHour[i]   = 0;
		maseRankingSectionMinute[i] = 0;
		maseRankingSectionSecond[i] = 0;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ランキング登録
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int maseRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (maseIsBig) || (!maseLvUpBonus) || (mase20G)) return -1;
	
	for(i = 0; i < 10; i++) {
		// ランクイン
		if(
		    (maseEndFlag > maseRankingEnd[i]) || 
		    ((maseEndFlag == maseRankingEnd[i]) && (maseFinalGrade > maseRankingGrade[i])) || 
		    ((maseEndFlag == maseRankingEnd[i]) && (maseFinalGrade == maseRankingGrade[i]) && (gameTimer < maseRankingTime[i]))
		  )
		{
			// ランキングをずらす
			for(j = 9; j > i; j--) {
				maseRankingGrade[j]         = maseRankingGrade[j - 1];
				maseRankingLevel[j]         = maseRankingLevel[j - 1];
				maseRankingTime[j]          = maseRankingTime[j - 1];
				maseRankingEnd[j]           = maseRankingEnd[j - 1];
				maseRankingMedal[j * 4 + 0] = maseRankingMedal[(j - 1) * 4 + 0];
				maseRankingMedal[j * 4 + 1] = maseRankingMedal[(j - 1) * 4 + 1];
				maseRankingMedal[j * 4 + 2] = maseRankingMedal[(j - 1) * 4 + 2];
				maseRankingMedal[j * 4 + 3] = maseRankingMedal[(j - 1) * 4 + 3];
				maseRankingYear[j]          = maseRankingYear[j - 1];
				maseRankingMonth[j]         = maseRankingMonth[j - 1];
				maseRankingDay[j]           = maseRankingDay[j - 1];
				maseRankingHour[j]          = maseRankingHour[j - 1];
				maseRankingMinute[j]        = maseRankingMinute[j - 1];
				maseRankingSecond[j]        = maseRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			maseRankingGrade[i]         = maseFinalGrade;
			maseRankingLevel[i]         = maseLevel;
			maseRankingTime[i]          = gameTimer[player];
			maseRankingEnd[i]           = maseEndFlag;
			maseRankingMedal[i * 4 + 0] = maseMedalStat[0];
			maseRankingMedal[i * 4 + 1] = maseMedalStat[1];
			maseRankingMedal[i * 4 + 2] = maseMedalStat[2];
			maseRankingMedal[i * 4 + 3] = maseMedalStat[3];
			
			GetDateAndTime(&timebuf);
			maseRankingYear[i]          = timebuf[0];
			maseRankingMonth[i]         = timebuf[1];
			maseRankingDay[i]           = timebuf[2];
			maseRankingHour[i]          = timebuf[4];
			maseRankingMinute[i]        = timebuf[5];
			maseRankingSecond[i]        = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   セクションタイムランキング更新
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int maseUpdateSectionTimeRanking(int player) {
	int i, timebuf[8], result;
	result = 0;
	
	if((playback) || (maseIsBig) || (!maseLvUpBonus) || (mase20G)) return 0;
	
	for(i = 0; i < 10; i++) {
		if((maseSectionTime[i] < maseRankingSectionTime[i]) && (maseSectionTime[i] != 0)) {
			result++;
			
			maseRankingSectionTime[i] = maseSectionTime[i];
			maseRankingSectionLevel[i] = maseLevel;
			maseRankingSectionEnd[i] = maseEndFlag;
			
			GetDateAndTime(&timebuf);
			maseRankingSectionYear[i] = timebuf[0];
			maseRankingSectionMonth[i] = timebuf[1];
			maseRankingSectionDay[i] = timebuf[2];
			maseRankingSectionHour[i] = timebuf[4];
			maseRankingSectionMinute[i] = timebuf[5];
			maseRankingSectionSecond[i] = timebuf[6];
		}
	}
	
	return result;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ランキング表示
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void maseViewRanking(int player) {
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
			printFontGrid(1, 1, "MASTER-EXTRA MODE RANKING >>", 6);
			printFontGrid(1, 3, "RANK GRADE LEVEL TIME", 4);
			
			for(i = 0; i < 10; i++) {
				if(maseRankingEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (maseRankingEnd[i] - 1) * 2, 320, 2);
				
				if(i == 0) sprintf(string[0], " 1ST");
				if(i == 1) sprintf(string[0], " 2ND");
				if(i == 2) sprintf(string[0], " 3RD");
				if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
				printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
				
				if((maseRankingGrade[i] >= 0) && (maseRankingGrade[i] < 33)) {
					printFontGrid(6, 4 + i, maseStrGradeName[maseRankingGrade[i]], 7 * (cursor == i));
				} else {
					printFontGrid(6, 4 + i, "???", 7 * (cursor == i));
				}
				
				sprintf(string[0], "%d", maseRankingLevel[i]);
				printFontGrid(12, 4 + i, string[0], 7 * (cursor == i));
				
				getTime(maseRankingTime[i]);
				printFontGrid(18, 4 + i, string[0], 7 * (cursor == i));
			}
			
			for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
			
			if(!erasemode) {
				// メダル
				maseDrawMedal(8 + 0 * 16, 192, 1, maseRankingMedal[cursor * 4 + 0], -1);
				maseDrawMedal(8 + 1 * 16, 192, 0, maseRankingMedal[cursor * 4 + 1], -1);
				maseDrawMedal(8 + 2 * 16, 192, 5, maseRankingMedal[cursor * 4 + 2], -1);
				maseDrawMedal(8 + 3 * 16, 192, 2, maseRankingMedal[cursor * 4 + 3], -1);
				
				// 日付と時刻
				sprintf(string[0],
				        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
				        maseRankingYear[cursor], maseRankingMonth[cursor], maseRankingDay[cursor],
				        maseRankingHour[cursor], maseRankingMinute[cursor], maseRankingSecond[cursor]);
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
					maseInitRanking();
					maseSaveRanking(player);
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
			printFontGrid(1, 1, "<< MASTER-EXTRA MODE SECTION TIME", 6);
			printFontGrid(1, 3, "SECTION TIME     LV  DATE", 4);
			printFontGrid(1, 28, "A/B:EXIT", 6);
			
			for(i = 0; i < 10; i++) {
				if(maseRankingSectionEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (maseRankingSectionEnd[i] - 1) * 2, 320, 2);
				
				sprintf(string[0], "%3d-%3d", i * 100, ((i + 1) * 100) - 1);
				printFontGrid(1, 4 + i, string[0], 0);
				
				getTime(maseRankingSectionTime[i]);
				printFontGrid(9, 4 + i, string[0], 0);
				
				sprintf(string[0], "%d", maseRankingSectionLevel[i]);
				printFontGrid(18, 4 + i, string[0], 0);
				
				temp = (maseRankingSectionYear[i] / 1000) * 1000;	// 年を下2桁だけ表示
				if(temp == 0) temp = 1;
				sprintf(string[0], "%02d/%02d/%02d", maseRankingSectionYear[i] % temp, maseRankingSectionMonth[i], maseRankingSectionDay[i]);
				printFontGrid(22, 4 + i, string[0], 0);
				
				sprintf(string[0], "%02d:%02d:%02d", maseRankingSectionHour[i], maseRankingSectionMinute[i], maseRankingSectionSecond[i]);
				printFontGrid(31, 4 + i, string[0], 0);
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
