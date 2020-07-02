//MASTER-HARD
//prefix:mash

// バージョン
int mashVersion;		// バージョン番号（古いリプレイ再生用）
int mashCVersion = 1;	// 現在のバージョン

// レベルアップテーブル
int mashLevelTable[51] =	// 落下速度
{
//  *00, *10, *20, *30, *40, *50, *60, *70, *80, *90
	1  , 1  , 1  , 2  , 3  , 4  , 5  , 6  , 8  , 12 ,// 0**
	15 , 15 , 15 , 15 , 23 , 23 , 23 , 23 , 30 , 30 ,// 1**
	1  , 2  , 8  , 15 , 30 , 60 , 60 , 60 , 60 , 60 ,// 2**
	120, 120, 120, 180, 180, 180, 240, 240, 240, 240,// 3**
	300, 300, 300, 300, 240, 240, 240, 180, 180, 180,// 4**
	1200
};

int mashWait1[17] =	// 固定→次
{
	  25,  25,  19,  14,  14,   8,   7,   7,   7,   7,   7,   6,   5,   3,   2,   0,  10
};
int mashWait2[17] =	// ブロック消去
{
	  29,  19,   9,   6,   6,   6,   6,   6,   6,   6,   6,   6,   4,   3,   1,   0,   2
};
int mashWait3[17] =	// 接地→固定
{
	  28,  28,  28,  28,  18,  16,  15,  15,  15,  15,  15,  14,  12,  10,   9,   8,  15
};
int mashWaitt[17] =	// 横溜め
{
	  10,  10,  10,  10,   9,   9,   8,   8,   8,   8,   8,   8,   7,   6,   6,   4,   7
};

// ランクごとの基準タイム
int mashBorderTime[20] = 
{
	17, 15, 14, 13, 10, 10, 12, 13, 13,		//  0～ 8
	13, 13, 13, 13, 13, 13, 12, 12, 11,		//  9～17
	11, 10									// 18～20
};

// 段位の表示名
str mashStrGradeName[33] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0～ 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9～17
	"M1", "M2", "M3", "M4", "M5", "M6", "M7", "M8", "M9",	// 18～26
	 "M", "MK", "MV", "MO", "MM", "GM"						// 27～32
};

// 裏段位の表示名
str mashStrSecretGradeName[19] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0～ 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9～17
	"GM"													// 18
};

// 使用するBGM
int mashBgmListTable[4] = {0, 1, 2, 6};

// 変数
int mashModeNo = -1;			// モード番号

int mashLevel[2];				// レベル
int mashScore[2];				// スコア
int mashGrade[2];				// 段位
int mashEndFlag[2];				// クリアフラグ

int mashTr[2];					// 10LVごとに1つ増える（速度上昇用）
int mashTr2[2];					// 現在の速度番号（基本的にLV10ごとに1つ増え、速度調整フラグによって10増減する）
int mashTimeN[2];				// ブロックを操作している時間
int mashTime99[2];				// レベルストップ時間
int mashAveLapTime[2];			// セクションの平均移動時間
int mashRank[2];				// 現在のランク（0～2）
int mashSpeedAdjust[2];			// 速度調整フラグ（0:やり直し 1:通常 2:スキップ）
int mashQualityFlag[2];			// 速度COOL出現済みフラグ
int mashSkillFlag[2];			// ヘボリスCOOL出現済みフラグ
int mashBorderRank[2];			// COOL判定用ランク
int mashGSkill[2];				// セクション内でのヘボリス回数

int mashSectionTime[10 * 2];	// このプレイのセクションタイム

int mashSTimer[2];				// セクションタイマー
int mashSkill[2];				// 合計ヘボリス回数

int mashHeboCombo[2];			// 連続ヘボリス回数
int mashTSpinCombo[2];			// 連続T-SPIN回数

int mashGMFlag[2 * 2];			// mロール条件フラグ
int mashEndingHeboris[2];		// エンディングで4ライン消しをした回数

int mashMedalStat[4 * 2];		// メダルの状態(0=なし 1=銅 2=銀 3=金)
int mashMedalAnim[4 * 2];		// メダル獲得アニメーション用カウンタ

int mashTSpinFrame[2];			// T-SPIN表示の残り時間
int mashCoolFrame[2];			// COOL表示の残り時間
int mashRegretFrame[2];			// REGRET表示の残り時間

int mashBgmFade[2];				// フェードアウト予定レベル（COOLが出ると-100）
int mashBgmIndex[2];			// 現在のBGM番号

int mashIsBig = 0;				// BIGかどうか
int mashBigMove = 1;			// BIG時の横移動単位
int mashGhost = 0;				// ゴーストの設定（0=LV0-99 1=常にON 2=常にOFF）
int mashLvUpBonus = 1;			// レベルアップボーナス
int mashTSpin = 1;				// T-SPINの種類
int mashTorikan = 25200;		// LV500とりカン基準タイム (7:00:00)
int mash20G = 0;				// 20Gモード

// ランキング変数
int mashRankingGrade[10];			// 段位
int mashRankingLevel[10];			// レベル
int mashRankingTime[10];			// タイム
int mashRankingEnd[10];				// クリアフラグ
int mashRankingMedal[4 * 10];		// メダル
int mashRankingYear[10];			// ランクイン日時（年）
int mashRankingMonth[10];			// ランクイン日時（月）
int mashRankingDay[10];				// ランクイン日時（日）
int mashRankingHour[10];			// ランクイン日時（時）
int mashRankingMinute[10];			// ランクイン日時（分）
int mashRankingSecond[10];			// ランクイン日時（秒）

// セクションタイムランキング変数
int mashRankingSectionTime[10];		// タイム
int mashRankingSectionEnd[10];		// クリアフラグ
int mashRankingSectionYear[10];		// ランクイン日時（年）
int mashRankingSectionMonth[10];	// ランクイン日時（月）
int mashRankingSectionDay[10];		// ランクイン日時（日）
int mashRankingSectionHour[10];		// ランクイン日時（時）
int mashRankingSectionMinute[10];	// ランクイン日時（分）
int mashRankingSectionSecond[10];	// ランクイン日時（秒）

// イベント発生
void mashPluginEvent(int player, int event, int *param) {
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != mashModeNo)) return;
	
	if(event == 0) {
		mashModeNo = addModePlugin("MASTER-HARD");	// モードを登録する
	} else if(event == 7) {
		if(!ending[player]) mashMoveInit(player);	// ブロック出現
	} else if(event == 12) {
		if(!ending[player]) mashCalcScore(player, param[0]);	// スコア計算
		else mashCalcScore2(player, param[0]);
	} else if(event == 15) {
		mashViewScore(player);	// スコア表示
	} else if(event == 17) {
		mashSetting(player, param);	// 設定画面
	} else if(event == 18) {
		mashPlayerInitial(player);	// 初期化処理
	} else if(event == 21) {
		mashResult(player, param);	// 結果表示
	} else if(event == 24) {
		mashEndingStart(player);	// エンディング突入
	} else if(event == 25) {
		mashExcellent(player, param);	// エンディング終了
	} else if(event == 28) {
		mashIncrementTime(player);	// 時間を進める
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		mashSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		mashLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		mashLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		mashReplayDetail();	// リプレイ詳細
	} else if(event == 60) {
		mashInitCombo(player);	// コンボ初期化
	}
}

// 初期化処理
void mashPlayerInitial(int player) {
	int i;
	
	// バージョン設定
	if(!playback) mashVersion = mashCVersion;
	
	// コンボ有効
	enable_combo[player] = 1;
	
	// 変数を初期化
	mashLevel[player] = -1;
	mashScore[player] = 0;
	mashGrade[player] = 0;
	mashEndFlag[player] = 0;
	
	mashTr[player] = 0;
	mashTr2[player] = 0;
	mashTimeN[player] = 0;
	mashTime99[player] = 0;
	mashAveLapTime[player] = 0;
	mashRank[player] = 0;
	mashSpeedAdjust[player] = 0;
	mashQualityFlag[player] = 0;
	mashSkillFlag[player] = 0;
	mashBorderRank[player] = 0;
	mashGSkill[player] = 0;
	
	for(i = 0; i < 10; i++) mashSectionTime[i + player * 10] = 0;
	
	mashSTimer[player] = 0;
	mashSkill[player] = 0;
	
	mashHeboCombo[player] = 0;
	mashTSpinCombo[player] = 0;
	
	mashGMFlag[player * 2 + 0] = 0;
	mashGMFlag[player * 2 + 1] = 1;
	mashEndingHeboris[player] = 0;
	
	for(i = 0; i < 4; i++) {
		mashMedalStat[player * 4 + i] = 0;
		mashMedalAnim[player * 4 + i] = -1;
	}
	
	mashTSpinFrame[player] = 0;
	mashCoolFrame[player] = 0;
	mashRegretFrame[player] = 0;
	
	mashBgmFade[player] = 485;
	mashBgmIndex[player] = 0;
	bgmlv = mashBgmListTable[0];
	
	// 設定を反映させる
	IsBig[player] = mashIsBig;
	BigMove[player] = mashBigMove;
	if(mashGhost == 2) ghost[player] = 0;
	tspin_type[player] = mashTSpin;
	
	// 初期スピードを設定
	mashSpeedUp(player);
}

// スピードを設定
void mashSpeedUp(int player) {
	int index;
	
	// 速度番号増加
	if(mashLevel[player] / 10 > mashTr[player]) {
		mashTr[player]++;
		mashTr2[player]++;
		
		if(mashTr[player] % 10 == 0) {
			// 速度調整
			if(mashSpeedAdjust[player] == 2)		// skip
				mashTr2[player] = mashTr2[player] + 10;
			if(mashSpeedAdjust[player] == 0)		// やり直し
				mashTr2[player] = mashTr2[player] - 10;
		}
	}
	
	// 落下速度
	if(mash20G) {
		sp[player] = 1200;
	} else {
		index = mashTr2[player];
		if((index > 50) || (mashLevel[player] >= mashBgmFade[player] + 15)) index = 50;
		sp[player] = mashLevelTable[index];
	}
	
	// wait値
	if(mashTr2[player] >= 50) {
		index = (mashTr2[player] - 50) / 10;
		if(index > 15) index = 15;
		wait1[player] = mashWait1[index];
		wait2[player] = mashWait2[index];
		wait3[player] = mashWait3[index];
		waitt[player] = mashWaitt[index];
	}
	
	// ゴーストを消す
	if((mashGhost == 0) && (mashLevel[player] >= 100)) ghost[player] = 0;
	
	// BGMフェードアウト１
	if((mashBgmIndex[player] == 0) && (mashLevel[player] >= mashBgmFade[player]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// BGMフェードアウト２
	if((mashBgmIndex[player] == 1) && (mashLevel[player] >= mashBgmFade[player] + 100) && (fadelv == 0)) {
		fadelv = 1;
	}
}

// ブロック出現
void mashMoveInit(int player) {
	int temp;
	
	// 最初のフレームなら
	if(statc[player * 10 + 3] == 0) {
		// レベルアップ処理
		if(mashLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		
		if(mashLevel[player] % 100 != temp) {
			mashLevel[player]++;
			if(mashLevel[player] % 100 == temp) PlaySE(se_lvstop);
			mashSpeedUp(player);
		}
		
		// COOL判定
		mashGradeCool(player);
	}
}

// スコア計算
void mashCalcScore(int player, int lines) {
	int i, temp, bo, bai, nextsec, lv;
	
	lv = mashLevel[player];	// 上がる前のレベル
	
	// ヘボリス回数増加
	if(lines >= 4) {
		mashSkill[player]++;
		mashGSkill[player]++;
		mashHeboCombo[player]++;
		
		// SKメダル獲得
		if((mashSkill[player] == 15) || (mashSkill[player] == 25) || (mashSkill[player] == 40)) {
			PlaySE(se_medal);
			mashMedalStat[player * 4 + 3]++;
			mashMedalAnim[player * 4 + 3] = 0;
		}
		
		// ヘボリス3連続で偽COOL
		if(mashHeboCombo[player] == 3) {
			PlaySE(se_cool);
			mashCoolFrame[player] = 180;
		}
	} else {
		mashHeboCombo[player] = 0;
	}
	
	// COメダル獲得
	if(combo2[player] == 4) {
		if(mashMedalStat[player * 4 + 2] < 1) {
			PlaySE(se_medal);
			mashMedalStat[player * 4 + 2] = 1;
			mashMedalAnim[player * 4 + 2] = 0;
		}
	} else if(combo2[player] == 5) {
		if(mashMedalStat[player * 4 + 2] < 2) {
			PlaySE(se_medal);
			mashMedalStat[player * 4 + 2] = 2;
			mashMedalAnim[player * 4 + 2] = 0;
		}
	} else if(combo2[player] == 7) {
		if(mashMedalStat[player * 4 + 2] < 3) {
			PlaySE(se_medal);
			mashMedalStat[player * 4 + 2] = 3;
			mashMedalAnim[player * 4 + 2] = 0;
		}
	}
	
	// COOL判定
	mashGradeCool(player);
	
	// レベルアップ
	nextsec = mashLevel[player] / 100 * 100 + 100;
	if(!mashLvUpBonus) mashLevel[player] = mashLevel[player] + lines;
	else mashLevel[player] = mashLevel[player] + lines + ((lines >= 3) * (lines - 2));
	
	if(mashLevel[player] >= 999) {
		// エンディング
		mashLevel[player] = 999;
		ending[player] = 1;
		timeOn[player] = 0;
		mashEndFlag[player] = 1;
		
		// STメダル
		mashMedalST(player, 9);
		
		// セクションタイマーをリセット
		mashSTimer[player] = 0;
	} else if((mashLevel[player] >= nextsec) && (nextsec == 500) && (gameTimer[player] > mashTorikan) && (mashTorikan > 0)) {
		// LV500とりカン
		mashLevel[player] = 500;
		ending[player] = 4;
		timeOn[player] = 0;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		stat[player] = 10;
		
		// STメダル
		mashMedalST(player, 4);
		
		// セクションタイマーをリセット
		mashSTimer[player] = 0;
	} else {
		// レベルストップ音
		if(mashLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		if(mashLevel[player] % 100 == temp) PlaySE(se_lvstop);
		
		if(mashLevel[player] >= nextsec) {
			// レベルアップ音
			PlaySE(se_levelup);
			
			// 背景切り替え
			bgfadesw = 1;
			bgfadebg = nextsec / 100;
			
			// mロールフラグ成立判定（LV400になったときにtr2変数が80以上）
			if((nextsec == 400) && (mashTr2[player] >= 80)) {
				mashGMFlag[player * 2 + 0] = 1;
				objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
			}
			
			// REGRET判定
			mashGradeRegret(player);
			
			// STメダル
			mashMedalST(player, (nextsec / 100) - 1);
			
			// セクションタイマーをリセット
			mashSTimer[player] = 0;
			
			// BGM切り替え
			if(fadelv != 0) {
				mashBgmIndex[player]++;
				bgmlv = mashBgmListTable[mashBgmIndex[player]];
				PlayBGM();
			}
		}
		
		// スピードアップ
		mashSpeedUp(player);
	}
	
	// スコア計算
	if(mashVersion >= 1) {
		temp = wait3[player] - bactivetime[player];
		if(temp < 0) temp = 0;
		
		bo = ((lv + lines) / 4 + (sdrop[player] / 2) + qdrop[player] + qput[player]) * lines * cmbpts[player] + (mashLevel[player] / 2) + temp;
		bai = 1;
	} else {
		bo = (lv + lines) / 4 + sdrop[player] + qdrop[player] + qput[player];
		bai = (lines * 2 - 1 + cmbpts[player] - (lines * 2 - 2)) * lines;
	}
	
	if(isBravo(player)) {
		// 全消しするとスコア4倍
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		if(mashVersion <= 0) bai = bai * 4;
		
		// ACメダル獲得
		if(mashMedalStat[player * 4 + 1] < 3) {
			PlaySE(se_medal);
			mashMedalStat[player * 4 + 1]++;
			mashMedalAnim[player * 4 + 1] = 0;
		}
	}
	
	if(tspin_flag[player]) {
		// T-SPIN
		PlaySE(se_tserase);
		mashTSpinFrame[player] = 120;
		if(mashVersion <= 0) bai = bai * 2;
		
		mashTSpinCombo[player]++;
		
		// T-SPIN2連続で偽COOL
		if(mashTSpinCombo[player] == 2) {
			PlaySE(se_cool);
			mashCoolFrame[player] = 180;
		}
		
		// T-SPINトリプルで偽COOL
		if(lines == 3) {
			PlaySE(se_cool);
			mashCoolFrame[player] = 180;
		}
	} else {
		mashTSpinCombo[player] = 0;
	}
	
	// スコア加算
	mashScore[player] = mashScore[player] + (bo * bai);
}

// スコア計算＠エンディング
void mashCalcScore2(int player, int lines) {
	// T-SPIN
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		mashTSpinFrame[player] = 120;
		mashTSpinCombo[player]++;
		
		// T-SPIN2連続で偽COOL
		if(mashTSpinCombo[player] == 2) {
			PlaySE(se_cool);
			mashCoolFrame[player] = 180;
		}
		
		// T-SPINトリプルで偽COOL
		if(lines == 3) {
			PlaySE(se_cool);
			mashCoolFrame[player] = 180;
		}
	} else {
		mashTSpinCombo[player] = 0;
	}
	
	// ヘボリス
	if(lines >= 4) {
		// エンディング中の4ライン消し回数増加
		mashEndingHeboris[player]++;
		
		// ヘボリス3連続で偽COOL
		mashHeboCombo[player]++;
		
		if(mashHeboCombo[player] == 3) {
			PlaySE(se_cool);
			mashCoolFrame[player] = 180;
		}
	} else {
		mashHeboCombo[player] = 0;
	}
}

// STメダル獲得
void mashMedalST(int player, int section) {
	// セクションタイムを記録
	mashSectionTime[section + player * 10] = mashSTimer[player];
	
	// STメダル獲得判定
	if((!playback) && (!IsBig[player]) && (mashLvUpBonus) && (!mash20G)) {
		if((mashSTimer[player] < mashRankingSectionTime[section]) && (mashMedalStat[player * 4 + 0] < 3)) {
			PlaySE(se_medal);
			mashMedalStat[player * 4 + 0] = 3;
			mashMedalAnim[player * 4 + 0] = 0;
		} else if((mashSTimer[player] < mashRankingSectionTime[section] + 300) && (mashMedalStat[player * 4 + 0] < 2)) {
			PlaySE(se_medal);
			mashMedalStat[player * 4 + 0] = 2;
			mashMedalAnim[player * 4 + 0] = 0;
		} else if((mashSTimer[player] < mashRankingSectionTime[section] + 600) && (mashMedalStat[player * 4 + 0] < 1)) {
			PlaySE(se_medal);
			mashMedalStat[player * 4 + 0] = 1;
			mashMedalAnim[player * 4 + 0] = 0;
		}
	}
}

// コンボ初期化
void mashInitCombo(int player) {
	mashHeboCombo[player] = 0;
	mashTSpinCombo[player] = 0;
}

// 時間を進める
void mashIncrementTime(int player) {
	int i, temp;
	
	if(timeOn[player]) {
		// セクションタイム増加
		mashSTimer[player]++;
		
		// ブロックを操作している時間を増加
		if(stat[player] == 4) mashTimeN[player]++;
		
		// レベルストップ時間増加
		if(mashLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		if(mashLevel[player] % 100 == temp) mashTime99[player]++;
	}
	
	// ロール終了
	if((ending[player] == 2) && (edrec[player] >= 60 * 60)) {
		ending[player] = 3;
		stat[player] = 10;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
	
	if(mashCoolFrame[player] > 0)
		mashCoolFrame[player]--;	// COOL表示時間減少
	else if(mashRegretFrame[player] > 0)
		mashRegretFrame[player]--;	// REGRET表示時間減少
	else if(mashTSpinFrame[player] > 0)
		mashTSpinFrame[player]--;	// T-SPIN表示時間減少
}

// COOL判定（ブロックを置く、またはライン消去のたびに呼び出し）
void mashGradeCool(int player) {
	int lap_timeT, secinlv, tmp;
	
	secinlv = mashLevel[player] - ((mashLevel[player] / 100) * 100);		// レベルの下2桁
	lap_timeT = ( mashTimeN[player] / (1 + (are[player] != 1)) ) + (mashTime99[player] * 2);
	
	// quality cool（速度COOL）
	if((secinlv > 80) && (secinlv < 99) && (!mashQualityFlag[player])) {
		// セクションレベルで割る
		mashAveLapTime[player] = lap_timeT / secinlv;
		
		// COOL
		if(mashAveLapTime[player] < mashBorderTime[mashBorderRank[player]]) {
			PlaySE(se_cool);
			mashCoolFrame[player] = 180;	// COOLの文字を出す
			mashGrade[player]++;			// 段位+1
			if(mashGrade[player] > 32) mashGrade[player] = 32;
			
			mashQualityFlag[player] = 1;	// 2回以上COOLが出ないようにする
			mashSpeedAdjust[player] = 2;	// 速度スキップ
			
			// ランクを上げる
			if(mashRank[player] < 2) mashRank[player]++;
			
			// フェードアウト予定レベル前倒し
			if(mashBgmIndex[player] == 0) {
				mashBgmFade[player] = mashBgmFade[player] - 100;
				if(mashBgmFade[player] < 285) mashBgmFade[player] = 285;
			}
		}
	}
	
	// skill cool（ヘボリスCOOL セクションまたぎは無効）
	if((!mashSkillFlag[player]) && (secinlv < 94)) {
		if(mashLevel[player] < 100) tmp = 3;
		else if(mashLevel[player] < 200) tmp = 6;
		else tmp = 4;
		
		if(mashGSkill[player] >= tmp) {
			PlaySE(se_cool);
			mashCoolFrame[player] = 180;	// COOLの文字を出す
			mashGSkill[player] = 0;			// ヘボリス回数リセット
			mashGrade[player]++;			// 段位+1
			if(mashGrade[player] > 31) mashGrade[player] = 31;
			mashSkillFlag[player] = 1;		// 2回以上COOLが出ないようにする
		}
	}
}

// REGRET判定（100超えるごとに呼び出し）
void mashGradeRegret(int player) {
	int border_time2, regretgosa;
	
	regretgosa = mashTr2[player] / 40;
	border_time2 = mashBorderTime[mashBorderRank[player]] + 6 + regretgosa;
	
	if(mashAveLapTime[player] > border_time2) {
		// REGRET
		PlaySE(se_regret);
		mashRegretFrame[player] = 180;
		
		// 降格
		if(mashGrade[player] > 0) mashGrade[player]--;
		
		// 速度やり直し（BGMがフェードアウトしている場合を除く）
		if((mashBgmIndex[player] != 0) || (mashLevel[player] < mashBgmFade[player])) {
			mashRank[player] = 0;
			mashSpeedAdjust[player] = 0;
		}
		
		// フェードアウト予定レベル延期
		if(mashBgmIndex[player] == 0) {
			mashBgmFade[player] = mashBgmFade[player] + 100;
			if(mashBgmFade[player] > 485) mashBgmFade[player] = 485;
		}
		
		// mロールフラグ剥奪
		mashGMFlag[player * 2 + 1] = 0;
	} else {
		// ヘボリスCOOLしていない場合
		if(!mashSkillFlag[player]) {
			// 速度上昇を通常の速さに
			mashSpeedAdjust[player] = 1;
			
			// ランクが2なら1にダウンさせる
			if(mashRank[player] == 2) mashRank[player] = 1;
		}
		
		// 段位+1
		mashGrade[player]++;
		if(mashGrade[player] > 31) mashGrade[player] = 31;
	}
	
	// 次の基準タイムを決める
	mashBorderRank[player] = mashBorderRank[player] + mashRank[player];
	
	// 変数をリセットする
	mashTimeN[player] = 0;
	mashTime99[player] = 0;
	mashAveLapTime[player] = 0;
	mashQualityFlag[player] = 0;
	mashSkillFlag[player] = 0;
	mashGSkill[player] = 0;
}

// BGM読み込み
void mashLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 4; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/4)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(mashBgmListTable[i]);
		}
	}
}

// エンディング突入
void mashEndingStart(int player) {
	int i;
	
	for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	
	if(mashLevel[player] >= 999) {
		ending[player] = 2;
		stat[player] = 4;
		ending_timeOn[player] = 1;
		
		wait1[player] = mashWait1[16];
		wait2[player] = mashWait2[16];
		wait3[player] = mashWait3[16];
		waitt[player] = mashWaitt[16];
		
		// 消えロール
		if((mashGrade[player] >= 22) && (gameTimer[player] <= 390 * 60) && (mashGMFlag[player * 2 + 0]) && (mashGMFlag[player * 2 + 1]))
		{
			hidden[player] = 9;
			shadowtime[player] = -60;
			objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
		}
		// 見えロール
		else
		{
			hidden[player] = 8;
			shadowtime[player] = 300;
			
			// m6以上は見える時間半減
			if(mashGrade[player] >= 23) shadowtime[player] = 150;
		}
		
		bgmlv = mashBgmListTable[3];
		PlayBGM();
	} else {
		ending[player] = 3;
	}
}

// エンディング終了
void mashExcellent(int player, int *param) {
	onRecord[player] = 0;
	statc[player * 10 + 1]++;
	
	if(mashLevel[player] >= 999) {
		// 完全クリア
		if(statc[player * 10 + 1] == 1) {
			mashEndFlag[player] = 2;
			
			if(hidden[player] == 10) {
				// mロールクリア
				hidden[player] = 0;
				
				// 無条件に段位上昇
				mashGrade[player]++;
				
				// ロール中の4ライン消し回数に応じて段位上昇
				mashGrade[player] = mashGrade[player] + mashEndingHeboris[player];
				if(mashGrade[player] > 32) mashGrade[player] = 32;
			} else {
				// ブロックを見えるようにする
				disableShadowTimer(player);
				
				// ロール中の4ライン消し回数3回ごとに段位上昇
				mashGrade[player] = mashGrade[player] + (mashEndingHeboris[player] / 3);
				if(mashGrade[player] > 31) mashGrade[player] = 31;
			}
		}
		
		// 花火
		if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 30)) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			statc[player * 10 + 2]++;
		}
		
		if(mashGrade[player] >= 32) {
			// YOU ARE GRAND MASTER!!
			param[0] = 1;
		} else {
			// EXCELLENT
			param[0] = 0;
			printTinyFont(foffset[player] + 20, fyoffset[player] + 116, "MASTER MODE");
			printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
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

// スコアを表示
void mashViewScore(int player) {
	int i, x, y, color, kind;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// メダル（通常）
	for(i = 0; i < 4; i++) {
		if((mashMedalAnim[player * 4 + i] < 0) || (mashMedalAnim[player * 4 + i] > 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 17;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			if(i == 0) kind = 1;
			if(i == 1) kind = 0;
			if(i == 2) kind = 5;
			if(i == 3) kind = 2;
			mashDrawMedal(x, y, kind, mashMedalStat[player * 4 + i], mashMedalAnim[player * 4 + i]);
		}
	}
	
	// メダル（アニメ中）
	for(i = 0; i < 4; i++) {
		if((mashMedalAnim[player * 4 + i] >= 0) && (mashMedalAnim[player * 4 + i] <= 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 17;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			if(i == 0) kind = 1;
			if(i == 1) kind = 0;
			if(i == 2) kind = 5;
			if(i == 3) kind = 2;
			mashDrawMedal(x, y, kind, mashMedalStat[player * 4 + i], mashMedalAnim[player * 4 + i]);
			mashMedalAnim[player * 4 + i]++;
		}
	}
	
	// レベル（分子）
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(mashLevel[player] == -1) sprintf(string[0], "%4d", 0);	// -1なら0と表示する(内部的には最初は-1になっている)
	else sprintf(string[0], "%4d", mashLevel[player]);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// レベル（横線）
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	if(sp[player] <= 600) {
		ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22 - ((sp[player] * 24) / 660), 143, 22, 1);
	} else {
		ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 0, 143, 22, 1);
	}
	
	// レベル（分母）
	if(ending[player]) sprintf(string[0], "%4d", mashLevel[player]);
	else if(mashLevel[player] >= 900) sprintf(string[0], "%4d", 999);
	else sprintf(string[0], "%4d", mashLevel[player] / 100 * 100 + 100);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, string[0], color);
	
	// タイム
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
	
	if(mashCoolFrame[player] > 0)
		printTinyFont(foffset[player] + 37, fyoffset[player] + 208, "COOL");	// COOL表示
	else if(mashRegretFrame[player] > 0)
		printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "REGRET");	// REGRET表示
	else if(mashTSpinFrame[player] > 0)
		printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "T-SPIN");	// T-SPIN表示
}

// メダルを表示
void mashDrawMedal(int x, int y, int kind, int color, int anim) {
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
void mashResult(int player, int *param) {
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
			statc[player * 10 + 2] = mashRegistRanking(player);
			statc[player * 10 + 3] = mashUpdateSectionTimeRanking(player);
			if((statc[player * 10 + 2] != -1) || (statc[player * 10 + 3] != 0)) mashSaveRanking(player);
			
			// 裏段位判定
			statc[player * 10 + 4] = checkSecretGrade(player);
		}
		
		// 段位表示
		if(mashGrade[player] < 9)		// 9～1
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108,   0, ((count % 4 / 2) * 216) + (mashGrade[player] * 24), 90, 24);
		else if(mashGrade[player] < 18)	// S1～S9
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108,  90, ((count % 4 / 2) * 216) + ((mashGrade[player] -  9) * 24), 90, 24);
		else if(mashGrade[player] < 27)	// m1～m9
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108, 180, ((count % 4 / 2) * 216) + ((mashGrade[player] - 18) * 24), 90, 24);
		else if(mashGrade[player] < 32)	// M～MM
			ExBltRect(sg_grade, foffset[player] + 2, fyoffset[player] + 108, 270, ((count % 4 / 2) * 216) + ((mashGrade[player] - 27) * 24), 90, 24);
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
		sprintf(string[0], "%13d", mashScore[player]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 67, string[0], 0);
		
		printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "LEVEL");
		sprintf(string[0], "%13d", mashLevel[player]);
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
			sprintf(string[0], "%13s", mashStrSecretGradeName[statc[player * 10 + 4]]);
			printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
		}
	}
}

// 設定画面
void mashSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(!mashLoadConfig()) mashSaveConfig();
	
	// ランキングを読み込み
	if(mashLoadRanking(player) == 0) mashInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "MASTER-HARD OPTIONS", 4);
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
		if(!mashIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!mashBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(mashGhost == 0) sprintf(string[0], "LV100");
		else if(mashGhost == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(!mashLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(mashTSpin == 0) sprintf(string[0], "OFF");
		else if(mashTSpin == 1) sprintf(string[0], "LINE CLEAR");
		else if(mashTSpin == 2) sprintf(string[0], "IMMOBILE");
		else if(mashTSpin == 3) sprintf(string[0], "3-CORNER");
		else sprintf(string[0], "3-CORNER NO KICK");
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		if(!mashTorikan) sprintf(string[0], "OFF");
		else getTime(mashTorikan);
		printFontGrid(22, 8, string[0], 7 * (cursor == 5));
		
		if(!mash20G) sprintf(string[0], "OFF");
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
			
			if(cursor == 0) mashIsBig = !mashIsBig;
			if(cursor == 1) mashBigMove = !mashBigMove;
			if(cursor == 2) {
				mashGhost = mashGhost + move;
				if(mashGhost < 0) mashGhost = 2;
				if(mashGhost > 2) mashGhost = 0;
			}
			if(cursor == 3) mashLvUpBonus = !mashLvUpBonus;
			if(cursor == 4) {
				mashTSpin = mashTSpin + move;
				if(mashTSpin < 0) mashTSpin = 4;
				if(mashTSpin > 4) mashTSpin = 0;
			}
			if(cursor == 5) {
				mashTorikan = mashTorikan + (move * 60);
				if(mashTorikan < 0) mashTorikan = 72000;
				if(mashTorikan > 72000) mashTorikan = 0;
			}
			if(cursor == 6) mash20G = !mash20G;
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
			mashSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			mashViewRanking(player);
		}
	}
}

// 設定を保存
void mashSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x5453414D;
	saveBuf[1] = 0x482D5245;
	saveBuf[2] = 0x43445241;
	saveBuf[3] = 0x31764746;
	
	// 設定内容
	saveBuf[4] = mashIsBig;
	saveBuf[5] = mashBigMove;
	saveBuf[6] = mashGhost;
	saveBuf[7] = mashLvUpBonus;
	saveBuf[8] = mashTSpin;
	saveBuf[9] = mashTorikan;
	saveBuf[10] = mash20G;
	
	SaveFile("config/MASTER_HARD_CONFIG.SAV", &saveBuf, 100 * 4);
}

// 設定を読み込み
int mashLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/MASTER_HARD_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x5453414D) return 0;
	if(saveBuf[1] != 0x482D5245) return 0;
	if(saveBuf[2] != 0x43445241) return 0;
	if(saveBuf[3] != 0x31764746) return 0;
	
	// 設定内容
	mashIsBig = saveBuf[4];
	mashBigMove = saveBuf[5];
	mashGhost = saveBuf[6];
	mashLvUpBonus = saveBuf[7];
	mashTSpin = saveBuf[8];
	mashTorikan = saveBuf[9];
	mash20G = saveBuf[10];
	
	return 1;
}

// リプレイ詳細
void mashReplayDetail() {
	printFontGrid(1, 5, "GRADE", 0);
	if((saveBuf[908] >= 0) && (saveBuf[908] <= 32)) {
		printFontGrid(22, 5, mashStrGradeName[saveBuf[908]], 0);
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

// リプレイ保存
void mashSaveReplay(int player) {
	saveBuf[900] = mashIsBig;
	saveBuf[901] = mashBigMove;
	saveBuf[902] = mashGhost;
	saveBuf[903] = mashLvUpBonus;
	saveBuf[904] = mashTSpin;
	saveBuf[905] = mashTorikan;
	saveBuf[906] = mashLevel[player];
	saveBuf[907] = mashScore[player];
	saveBuf[908] = mashGrade[player];
	saveBuf[909] = mashVersion;
	saveBuf[910] = mash20G;
}

// リプレイ読み込み
void mashLoadReplay(int player) {
	mashIsBig = saveBuf[900];
	mashBigMove = saveBuf[901];
	mashGhost = saveBuf[902];
	mashLvUpBonus = saveBuf[903];
	mashTSpin = saveBuf[904];
	mashTorikan = saveBuf[905];
	mashVersion = saveBuf[909];
	mash20G = saveBuf[910];
}

// ランキング保存
void mashSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0]  = mashRankingGrade[i];
		saveBuf[1 + (i * 20) + 1]  = mashRankingLevel[i];
		saveBuf[1 + (i * 20) + 2]  = mashRankingTime[i];
		saveBuf[1 + (i * 20) + 3]  = mashRankingEnd[i];
		saveBuf[1 + (i * 20) + 4]  = mashRankingMedal[i * 4 + 0];
		saveBuf[1 + (i * 20) + 5]  = mashRankingMedal[i * 4 + 1];
		saveBuf[1 + (i * 20) + 6]  = mashRankingMedal[i * 4 + 2];
		saveBuf[1 + (i * 20) + 7]  = mashRankingMedal[i * 4 + 3];
		saveBuf[1 + (i * 20) + 8]  = mashRankingYear[i];
		saveBuf[1 + (i * 20) + 9]  = mashRankingMonth[i];
		saveBuf[1 + (i * 20) + 10] = mashRankingDay[i];
		saveBuf[1 + (i * 20) + 11] = mashRankingHour[i];
		saveBuf[1 + (i * 20) + 12] = mashRankingMinute[i];
		saveBuf[1 + (i * 20) + 13] = mashRankingSecond[i];
	}
	
	// セクションタイムランキング
	for(i = 0; i < 10; i++) {
		saveBuf[221 + (i * 10) + 0] = mashRankingSectionTime[i];
		saveBuf[221 + (i * 10) + 1] = mashRankingSectionEnd[i];
		saveBuf[221 + (i * 10) + 2] = mashRankingSectionYear[i];
		saveBuf[221 + (i * 10) + 3] = mashRankingSectionMonth[i];
		saveBuf[221 + (i * 10) + 4] = mashRankingSectionDay[i];
		saveBuf[221 + (i * 10) + 5] = mashRankingSectionHour[i];
		saveBuf[221 + (i * 10) + 6] = mashRankingSectionMinute[i];
		saveBuf[221 + (i * 10) + 7] = mashRankingSectionSecond[i];
	}
	
	sprintf(string[0], "config/MASTER_HARD_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 331 * 4);
}

// ランキング読み込み
int mashLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/MASTER_HARD_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 331 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		mashRankingGrade[i]         = saveBuf[1 + (i * 20) + 0];
		mashRankingLevel[i]         = saveBuf[1 + (i * 20) + 1];
		mashRankingTime[i]          = saveBuf[1 + (i * 20) + 2];
		mashRankingEnd[i]           = saveBuf[1 + (i * 20) + 3];
		mashRankingMedal[i * 4 + 0] = saveBuf[1 + (i * 20) + 4];
		mashRankingMedal[i * 4 + 1] = saveBuf[1 + (i * 20) + 5];
		mashRankingMedal[i * 4 + 2] = saveBuf[1 + (i * 20) + 6];
		mashRankingMedal[i * 4 + 3] = saveBuf[1 + (i * 20) + 7];
		mashRankingYear[i]          = saveBuf[1 + (i * 20) + 8];
		mashRankingMonth[i]         = saveBuf[1 + (i * 20) + 9];
		mashRankingDay[i]           = saveBuf[1 + (i * 20) + 10];
		mashRankingHour[i]          = saveBuf[1 + (i * 20) + 11];
		mashRankingMinute[i]        = saveBuf[1 + (i * 20) + 12];
		mashRankingSecond[i]        = saveBuf[1 + (i * 20) + 13];
	}
	
	// セクションタイムランキング
	for(i = 0; i < 10; i++) {
		mashRankingSectionTime[i]   = saveBuf[221 + (i * 10) + 0];
		mashRankingSectionEnd[i]    = saveBuf[221 + (i * 10) + 1];
		mashRankingSectionYear[i]   = saveBuf[221 + (i * 10) + 2];
		mashRankingSectionMonth[i]  = saveBuf[221 + (i * 10) + 3];
		mashRankingSectionDay[i]    = saveBuf[221 + (i * 10) + 4];
		mashRankingSectionHour[i]   = saveBuf[221 + (i * 10) + 5];
		mashRankingSectionMinute[i] = saveBuf[221 + (i * 10) + 6];
		mashRankingSectionSecond[i] = saveBuf[221 + (i * 10) + 7];
	}
	
	return 1;
}

// ランキング初期化
void mashInitRanking() {
	int i;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		mashRankingGrade[i]         = 0;
		mashRankingLevel[i]         = 0;
		mashRankingTime[i]          = 0;
		mashRankingEnd[i]           = 0;
		mashRankingMedal[i * 4 + 0] = 0;
		mashRankingMedal[i * 4 + 1] = 0;
		mashRankingMedal[i * 4 + 2] = 0;
		mashRankingMedal[i * 4 + 3] = 0;
		mashRankingYear[i]          = 0;
		mashRankingMonth[i]         = 0;
		mashRankingDay[i]           = 0;
		mashRankingHour[i]          = 0;
		mashRankingMinute[i]        = 0;
		mashRankingSecond[i]        = 0;
	}
	
	// セクションタイムランキング
	for(i = 0; i < 10; i++) {
		mashRankingSectionTime[i]   = 5400;
		mashRankingSectionEnd[i]    = 0;
		mashRankingSectionYear[i]   = 0;
		mashRankingSectionMonth[i]  = 0;
		mashRankingSectionDay[i]    = 0;
		mashRankingSectionHour[i]   = 0;
		mashRankingSectionMinute[i] = 0;
		mashRankingSectionSecond[i] = 0;
	}
}

// ランキング登録
int mashRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (!mashLvUpBonus) || (mash20G)) return -1;
	
	for(i = 0; i < 10; i++) {
		// ランクイン
		if(
		    (mashEndFlag[player] > mashRankingEnd[i]) || 
		    ((mashEndFlag[player] == mashRankingEnd[i]) && (mashGrade[player] > mashRankingGrade[i])) || 
		    ((mashEndFlag[player] == mashRankingEnd[i]) && (mashGrade[player] == mashRankingGrade[i]) && (gameTimer[player] < mashRankingTime[i]))
		  )
		{
			// ランキングをずらす
			for(j = 9; j > i; j--) {
				mashRankingGrade[j]         = mashRankingGrade[j - 1];
				mashRankingLevel[j]         = mashRankingLevel[j - 1];
				mashRankingTime[j]          = mashRankingTime[j - 1];
				mashRankingEnd[j]           = mashRankingEnd[j - 1];
				mashRankingMedal[j * 4 + 0] = mashRankingMedal[(j - 1) * 4 + 0];
				mashRankingMedal[j * 4 + 1] = mashRankingMedal[(j - 1) * 4 + 1];
				mashRankingMedal[j * 4 + 2] = mashRankingMedal[(j - 1) * 4 + 2];
				mashRankingMedal[j * 4 + 3] = mashRankingMedal[(j - 1) * 4 + 3];
				mashRankingYear[j]          = mashRankingYear[j - 1];
				mashRankingMonth[j]         = mashRankingMonth[j - 1];
				mashRankingDay[j]           = mashRankingDay[j - 1];
				mashRankingHour[j]          = mashRankingHour[j - 1];
				mashRankingMinute[j]        = mashRankingMinute[j - 1];
				mashRankingSecond[j]        = mashRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			mashRankingGrade[i]         = mashGrade[player];
			mashRankingLevel[i]         = mashLevel[player];
			mashRankingTime[i]          = gameTimer[player];
			mashRankingEnd[i]           = mashEndFlag[player];
			mashRankingMedal[i * 4 + 0] = mashMedalStat[player * 4 + 0];
			mashRankingMedal[i * 4 + 1] = mashMedalStat[player * 4 + 1];
			mashRankingMedal[i * 4 + 2] = mashMedalStat[player * 4 + 2];
			mashRankingMedal[i * 4 + 3] = mashMedalStat[player * 4 + 3];
			
			GetDateAndTime(&timebuf);
			mashRankingYear[i]          = timebuf[0];
			mashRankingMonth[i]         = timebuf[1];
			mashRankingDay[i]           = timebuf[2];
			mashRankingHour[i]          = timebuf[4];
			mashRankingMinute[i]        = timebuf[5];
			mashRankingSecond[i]        = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// セクションタイムランキング更新
int mashUpdateSectionTimeRanking(int player) {
	int i, timebuf[8], result;
	result = 0;
	
	if((playback) || (IsBig[player]) || (!mashLvUpBonus) || (mash20G)) return 0;
	
	for(i = 0; i < 10; i++) {
		if((mashSectionTime[i + player * 10] < mashRankingSectionTime[i]) && (mashSectionTime[i + player * 10] != 0)) {
			result++;
			
			mashRankingSectionTime[i] = mashSectionTime[i + player * 10];
			mashRankingSectionEnd[i] = mashEndFlag[player];
			
			GetDateAndTime(&timebuf);
			mashRankingSectionYear[i] = timebuf[0];
			mashRankingSectionMonth[i] = timebuf[1];
			mashRankingSectionDay[i] = timebuf[2];
			mashRankingSectionHour[i] = timebuf[4];
			mashRankingSectionMinute[i] = timebuf[5];
			mashRankingSectionSecond[i] = timebuf[6];
		}
	}
	
	return result;
}

// ランキング表示
void mashViewRanking(int player) {
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
			printFontGrid(1, 1, "MASTER-HARD MODE RANKING >>", 6);
			printFontGrid(1, 3, "RANK GRADE LEVEL TIME", 4);
			
			for(i = 0; i < 10; i++) {
				if(mashRankingEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (mashRankingEnd[i] - 1) * 2, 320, 2);
				
				if(i == 0) sprintf(string[0], " 1ST");
				if(i == 1) sprintf(string[0], " 2ND");
				if(i == 2) sprintf(string[0], " 3RD");
				if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
				printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
				
				if((mashRankingGrade[i] >= 0) && (mashRankingGrade[i] < 33)) {
					printFontGrid(6, 4 + i, mashStrGradeName[mashRankingGrade[i]], 7 * (cursor == i));
				} else {
					printFontGrid(6, 4 + i, "???", 7 * (cursor == i));
				}
				
				sprintf(string[0], "%d", mashRankingLevel[i]);
				printFontGrid(12, 4 + i, string[0], 7 * (cursor == i));
				
				getTime(mashRankingTime[i]);
				printFontGrid(18, 4 + i, string[0], 7 * (cursor == i));
			}
			
			for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
			
			if(!erasemode) {
				// メダル
				mashDrawMedal(8 + 0 * 16, 192, 1, mashRankingMedal[cursor * 4 + 0], -1);
				mashDrawMedal(8 + 1 * 16, 192, 0, mashRankingMedal[cursor * 4 + 1], -1);
				mashDrawMedal(8 + 2 * 16, 192, 5, mashRankingMedal[cursor * 4 + 2], -1);
				mashDrawMedal(8 + 3 * 16, 192, 2, mashRankingMedal[cursor * 4 + 3], -1);
				
				// 日付と時刻
				sprintf(string[0],
				        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
				        mashRankingYear[cursor], mashRankingMonth[cursor], mashRankingDay[cursor],
				        mashRankingHour[cursor], mashRankingMinute[cursor], mashRankingSecond[cursor]);
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
					mashInitRanking();
					mashSaveRanking(player);
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
			printFontGrid(1, 1, "<< MASTER-HARD MODE SECTION TIME", 6);
			printFontGrid(1, 3, "SECTION TIME     DATE", 4);
			printFontGrid(1, 28, "A/B:EXIT", 6);
			
			for(i = 0; i < 10; i++) {
				if(mashRankingSectionEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (mashRankingSectionEnd[i] - 1) * 2, 320, 2);
				
				sprintf(string[0], "%3d-%3d", i * 100, ((i + 1) * 100) - 1);
				printFontGrid(1, 4 + i, string[0], 0);
				
				getTime(mashRankingSectionTime[i]);
				printFontGrid(9, 4 + i, string[0], 0);
				
				temp = (mashRankingSectionYear[i] / 1000) * 1000;	// 年を下2桁だけ表示
				if(temp == 0) temp = 1;
				sprintf(string[0], "%02d/%02d/%02d", mashRankingSectionYear[i] % temp, mashRankingSectionMonth[i], mashRankingSectionDay[i]);
				printFontGrid(18, 4 + i, string[0], 0);
				
				sprintf(string[0], "%02d:%02d:%02d", mashRankingSectionHour[i], mashRankingSectionMinute[i], mashRankingSectionSecond[i]);
				printFontGrid(27, 4 + i, string[0], 0);
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
