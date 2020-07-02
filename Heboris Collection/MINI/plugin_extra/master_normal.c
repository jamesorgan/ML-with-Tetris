//MASTER-NORMAL
//Special Thanks to www.tetrisconcept.com's wiki
//prefix:masn

// バージョン
int masnVersion;		// バージョン番号（古いリプレイ再生用）
int masnCVersion = 4;	// 現在のバージョン

// レベルアップテーブル(420での減速追加後)
// 速度
int masnLevelTable[30] =
{
	4, 6, 8, 10, 12, 16, 32, 48, 64, 80, 96, 112, 128, 144, 4, 32, 64, 96, 128, 160,
	192, 224, 256, 512, 768, 1024, 1280, 1024, 768, 5120
};

// レベル
int masnLevelChange[30] = 
{
	30, 35, 40, 50, 60, 70, 80, 90, 100, 120, 140, 160, 170, 200, 220, 230, 233, 236, 239, 243,
	247, 251, 300, 330, 360, 400, 420, 450, 500, 10000
};

// レベルアップテーブル(420での減速追加前)
// 速度
int masnLevelTable3[29] =
{
	4, 6, 8, 10, 12, 16, 32, 48, 64, 80, 96, 112, 128, 144, 4, 32, 64, 96, 128, 160,
	192, 224, 256, 512, 768, 1024, 1280, 768, 5120
};

// レベル
int masnLevelChange3[29] = 
{
	30, 35, 40, 50, 60, 70, 80, 90, 100, 120, 140, 160, 170, 200, 220, 230, 233, 236, 239, 243,
	247, 251, 300, 330, 360, 400, 450, 500, 10000
};

// wait値           000,500,600,700,800,900
int masnWait1[6] = { 25, 25, 25, 16, 12, 12};
int masnWait2[6] = { 40, 25, 16, 12,  6,  6};
int masnWait3[6] = { 30, 30, 30, 30, 30, 17};
int masnWaitt[6] = { 16, 10, 10, 10, 10,  8};

// 段位の表示名
str masnStrGradeName[20] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0～ 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9～17
	 "M", "GM"												// 18～19
};

// 段位ポイント上昇テーブル
int masnGradePoint1[11] = {10,10,10,10,10, 5, 5, 5, 5, 5, 2};
int masnGradePoint2[11] = {20,20,20,15,15,15,10,10,10,10,12};
int masnGradePoint3[11] = {40,30,30,30,20,20,20,15,15,15,13};
int masnGradePoint4[11] = {50,40,40,40,40,30,30,30,30,30,30};

// コンボの倍率
int masnGradeCombo[11 * 4] = 
{
//    0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,
	100, 100, 120, 120, 120, 120, 120, 120, 120, 120, 150,
	100, 100, 140, 150, 160, 170, 180, 190, 200, 210, 250,
	100, 100, 150, 180, 200, 220, 230, 240, 250, 260, 300,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100,   0,
};

// 段位表示が変わる内部クラス
int masnGradeNorm[17] = 
{
	1, 2, 3, 4, 5, 7, 9, 12, 15, 18, 19, 20, 23, 25, 27, 29, 31
};

// 段位ポイントが1減るまでの時間
int masnGradeTimeLimit[32] = 
{
	126, 81, 81, 51, 46, 46, 46, 46, 41, 41, 41, 41, 31, 31, 31, 21, 21, 21, 21, 21, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 11
};

// 裏段位の表示名
str masnStrSecretGradeName[19] = 
{
	 "9",  "8",  "7",  "6",  "5",  "4",  "3",  "2",  "1",	//  0～ 8
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9",	//  9～17
	"GM"													// 18
};

// BGM設定
int masnBgmNo[5]     = {0,1,2,3,6};				// BGM番号（000-499、500-699、700-899、900-998、999）
int masnFadeLv[4]    = {495,695,880,10000};		// BGMをフェードアウトさせるレベル
int masnBgmChange[4] = {500,700,900,10000};		// BGMを切り替えるレベル
int masnBgmIndex     = 0;						// 現在のBGM番号

// 変数
int masnModeNo = -1;	// モード番号

int masnLevel[2];		// レベル
int masnScore[2];		// スコア
int masnLevelIndex[2];	// 現在の速度番号

int masnGrade[2];		// 段位
int masnGFlash[2];		// 段位表示ズーム演出用
int masnGPoint[2];		// 現在の段位ポイント
int masnGTimer[2];		// 段位ポイント減少タイマー
int masnClass[2];		// 内部クラス

int masnSTimer[2];				// セクションタイマー
int masnSHebo[2];				// このセクションのヘボリス回数
int masnGMFlag[2 * 2];			// mロール条件フラグ
int masnPreSTimer[2];			// 前のセクションのセクションタイム
int masnSectionTime[10 * 2];	// このプレイのセクションタイム

int masnMedalStat[6 * 2];	// メダルの状態(0=なし 1=銅 2=銀 3=金)
int masnMedalAnim[6 * 2];	// メダル獲得アニメーション用カウンタ

int masnSkill[2];		// ヘボリス回数
int masnREFlag[2];		// REメダル用フラグ（0=通常 1=リカバリ中）
int masnTotalRotate[2];	// 回転した回数

int masnEndFlag[2];		// クリアフラグ

int masnIsBig = 0;		// BIGかどうか
int masnBigMove = 1;	// BIG時の横移動単位
int masnGhost = 0;		// ゴーストの設定（0=LV0-99 1=常にON 2=常にOFF）
int masnLvUpBonus = 0;	// レベルアップボーナス
int masn20G = 0;		// 20Gモード
int masnStartLevel = 0;	// スタート時のレベル

// ランキング変数
int masnRankingGrade[10];			// 段位
int masnRankingLevel[10];			// レベル
int masnRankingTime[10];			// タイム
int masnRankingEnd[10];				// クリアフラグ
int masnRankingMedal[6 * 10];		// メダル
int masnRankingYear[10];			// ランクイン日時（年）
int masnRankingMonth[10];			// ランクイン日時（月）
int masnRankingDay[10];				// ランクイン日時（日）
int masnRankingHour[10];			// ランクイン日時（時）
int masnRankingMinute[10];			// ランクイン日時（分）
int masnRankingSecond[10];			// ランクイン日時（秒）

// セクションタイムランキング変数
int masnRankingSectionTime[10];		// タイム
int masnRankingSectionEnd[10];		// クリアフラグ
int masnRankingSectionYear[10];		// ランクイン日時（年）
int masnRankingSectionMonth[10];	// ランクイン日時（月）
int masnRankingSectionDay[10];		// ランクイン日時（日）
int masnRankingSectionHour[10];		// ランクイン日時（時）
int masnRankingSectionMinute[10];	// ランクイン日時（分）
int masnRankingSectionSecond[10];	// ランクイン日時（秒）

// イベント発生
void masnPluginEvent(int player, int event, int *param) {
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != masnModeNo)) return;
	
	if(event == 0) {
		masnModeNo = addModePlugin("MASTER-NORMAL");	// モードを登録する
	} else if(event == 7) {
		if(!ending[player]) masnMoveInit(player);	// ブロック出現
	} else if(event == 12) {
		if(!ending[player]) masnCalcScore(player, param[0]);	// スコア計算
	} else if(event == 15) {
		masnViewScore(player);	// スコア表示
	} else if(event == 17) {
		masnSetting(player, param);	// 設定画面
	} else if(event == 18) {
		masnPlayerInitial(player);	// 初期化処理
	} else if(event == 20) {
		masnGameOver(player);	// ゲームオーバー処理の最初
	} else if(event == 21) {
		masnResult(player);	// 結果表示
	} else if(event == 24) {
		masnEndingStart(player);	// エンディング突入
	} else if(event == 25) {
		masnExcellent(player, param);	// エンディング終了
	} else if(event == 28) {
		masnIncrementTime(player);	// 時間を進める
	} else if(event == 38) {
		PlayBGM();	// BGM再生
	} else if(event == 39) {
		masnSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		masnLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		masnLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		masnReplayDetail();	// リプレイ詳細
	}
}

// 初期化処理
void masnPlayerInitial(int player) {
	int i;
	
	// バージョン
	if(!playback) masnVersion = masnCVersion;
	
	// コンボ有効
	enable_combo[player] = 1;
	
	// 変数を初期化
	masnBgmIndex = 0;
	bgmlv = masnBgmNo[0];
	
	if(masnVersion >= 3) {
		if(masnStartLevel > 0) masnLevel[player] = masnStartLevel;
		else masnLevel[player] = -1;
		
		backno = masnLevel[player] / 100;
	} else {
		masnLevel[player] = -1;
	}
	masnScore[player] = 0;
	masnLevelIndex[player] = 0;
	
	masnGrade[player] = 0;
	masnGFlash[player] = 0;
	masnGPoint[player] = 0;
	masnGTimer[player] = 0;
	masnClass[player] = 0;
	
	masnSTimer[player] = 0;
	masnSHebo[player] = 0;
	
	masnGMFlag[player * 2 + 0] = 1;
	masnGMFlag[player * 2 + 1] = 1;
	
	masnPreSTimer[player] = 0;
	
	for(i = 0; i < 10; i++) masnSectionTime[i + player * 10] = 0;
	
	for(i = 0; i < 6; i++) {
		masnMedalStat[player * 6 + i] = 0;
		masnMedalAnim[player * 6 + i] = -1;
	}
	masnSkill[player] = 0;
	masnREFlag[player] = 0;
	masnTotalRotate[player] = 0;
	
	masnEndFlag[player] = 0;
	
	// 設定を反映させる
	IsBig[player] = masnIsBig;
	BigMove[player] = masnBigMove;
	if(masnGhost == 2) ghost[player] = 0;
	
	// 初期スピードを設定
	masnSpeedUp(player);
}

// ブロック出現
void masnMoveInit(int player) {
	int temp;
	
	// 最初のフレームなら
	if(statc[player * 10 + 3] == 0) {
		// レベルアップ処理
		if(masnLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		
		if(masnLevel[player] % 100 != temp) {
			masnLevel[player]++;
			if(masnLevel[player] % 100 == temp) PlaySE(se_lvstop);
			masnSpeedUp(player);
		}
		
		// REメダル
		if(masnMedalStat[player * 6 + 3] < 3) {
			if(masnREFlag[player] == 0) {
				if(checkHowManyBlocks(player) >= 150) masnREFlag[player] = 1;
			} else {
				if(checkHowManyBlocks(player) <= 70) {
					masnREFlag[player] = 0;
					PlaySE(se_medal);
					masnMedalStat[player * 6 + 3]++;
					masnMedalAnim[player * 6 + 3] = 0;
				}
			}
		}
		
		// ROメダル関連
		if(masnMedalStat[player * 6 + 4] < 3) {
			temp = brotcount[player];
			if(temp > 4) temp = 4;
			masnTotalRotate[player] = masnTotalRotate[player] + temp;
		}
	}
}

// スピードアップ
void masnSpeedUp(int player) {
	int temp;
	
	// スピードを変える
	speedtype[player] = 2;
	
	if(masn20G) {
		sp[player] = 5120;
	} else {
		if(masnVersion >= 4) {
			while(masnLevel[player] >= masnLevelChange[masnLevelIndex[player]]) masnLevelIndex[player]++;
		} else if(masnVersion >= 3) {
			while(masnLevel[player] >= masnLevelChange3[masnLevelIndex[player]]) masnLevelIndex[player]++;
		} else {
			if(masnLevel[player] >= masnLevelChange3[masnLevelIndex[player]]) masnLevelIndex[player]++;
		}
		
		if(masnVersion >= 4) {
			sp[player] = masnLevelTable[masnLevelIndex[player]];
		} else {
			sp[player] = masnLevelTable3[masnLevelIndex[player]];
		}
	}
	
	if(masnLevel[player] < 500) {
		wait1[player] = masnWait1[0];
		wait2[player] = masnWait2[0];
		wait3[player] = masnWait3[0];
		waitt[player] = masnWaitt[0];
	} else {
		wait1[player] = masnWait1[(masnLevel[player] / 100) - 4];
		wait2[player] = masnWait2[(masnLevel[player] / 100) - 4];
		wait3[player] = masnWait3[(masnLevel[player] / 100) - 4];
		waitt[player] = masnWaitt[(masnLevel[player] / 100) - 4];
	}
	
	// BGMフェードアウト
	if((masnLevel[player] >= masnFadeLv[masnBgmIndex]) && (masnLevel[player] < masnBgmChange[masnBgmIndex]) && (fadelv == 0)) {
		fadelv = 1;
	}
	
	// BGM切り替え
	temp = 0;
	while(masnLevel[player] >= masnBgmChange[masnBgmIndex]) {
		masnBgmIndex++;
		bgmlv = masnBgmNo[masnBgmIndex];
		if(onRecord[player]) temp = 1;
	}
	if(temp) PlayBGM();
	
	// ゴーストを消す
	if((masnLevel[player] >= 100) && (masnGhost == 0)) {
		ghost[player] = 0;
	}
}

// スコア計算
void masnCalcScore(int player, int lines) {
	int temp, temp2, temp3, index, bo, bai, nextsec;
	
	if(masnVersion >= 2) {
		if(!masnLvUpBonus) temp = masnLevel[player] + lines;
		else temp = masnLevel[player] + lines + ((lines >= 3) * (lines - 2));
		if(temp > 999) temp = 999;
		
		temp2 = wait3[player] - bactivetime[player];
		if(temp2 < 0) temp2 = 0;
		
		bo = ((masnLevel[player] + lines) / 4 + sdrop[player] + qdrop[player] + qput[player]) * lines * cmbpts[player] + (temp / 2) + (temp2 * 7);
		bai = 1;
	} else {
		bo = (masnLevel[player] + lines) / 4 + sdrop[player] + qdrop[player] + qput[player];
		bai = (lines * 2 - 1 + cmbpts[player] - (lines * 2 - 2)) * lines;
	}
	
	if(isBravo(player)) {
		// 全消しするとスコア4倍
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		bai = bai * 4;
		
		// ACメダル獲得
		if(masnMedalStat[player * 6 + 0] < 3) {
			PlaySE(se_medal);
			masnMedalStat[player * 6 + 0]++;
			masnMedalAnim[player * 6 + 0] = 0;
		}
	}
	
	// スコア加算
	masnScore[player] = masnScore[player] + bo * bai;
	
	// ヘボリス回数増加
	if(lines >= 4) {
		masnSkill[player]++;
		
		// SKメダル獲得
		if((masnSkill[player] == 10) || (masnSkill[player] == 20) || (masnSkill[player] == 35)) {
			PlaySE(se_medal);
			masnMedalStat[player * 6 + 2]++;
			masnMedalAnim[player * 6 + 2] = 0;
		}
	}
	
	// COメダル獲得
	if(combo2[player] == 4) {
		if(masnMedalStat[player * 6 + 5] < 1) {
			PlaySE(se_medal);
			masnMedalStat[player * 6 + 5] = 1;
			masnMedalAnim[player * 6 + 5] = 0;
		}
	} else if(combo2[player] == 5) {
		if(masnMedalStat[player * 6 + 5] < 2) {
			PlaySE(se_medal);
			masnMedalStat[player * 6 + 5] = 2;
			masnMedalAnim[player * 6 + 5] = 0;
		}
	} else if(combo2[player] == 7) {
		if(masnMedalStat[player * 6 + 5] < 3) {
			PlaySE(se_medal);
			masnMedalStat[player * 6 + 5] = 3;
			masnMedalAnim[player * 6 + 5] = 0;
		}
	}
	
	// 段位ポイント加算
	if(masnClass[player] < 31) {
		index = masnClass[player];
		if(index > 10) index = 10;
		
		if(masnLevel[player] < 250) {
			temp2 = 1;
		} else if(masnLevel[player] < 500) {
			temp2 = 2;
		} else if(masnLevel[player] < 750) {
			temp2 = 3;
		} else {
			temp2 = 4;
		}
		
		if(lines == 1) temp = masnGradePoint1[index] * temp2;
		if(lines == 2) temp = masnGradePoint2[index] * temp2;
		if(lines == 3) temp = masnGradePoint3[index] * temp2;
		if(lines == 4) temp = masnGradePoint4[index] * temp2;
		
		if(masnVersion >= 1) temp3 = combo2[player];
		else temp3 = combo3[player];
		
		if(temp3 > 10) temp3 = 10;
		
		temp = (temp * 10) * masnGradeCombo[temp3 + (lines - 1) * 11] / 1000;
		masnGPoint[player] = masnGPoint[player] + temp;
		
		// 内部クラス上昇
		if(masnGPoint[player] >= 100) {
			masnGPoint[player] = 0;
			masnClass[player]++;
			
			if((masnClass[player] >= masnGradeNorm[masnGrade[player]]) && (masnGrade[player] < 17)) {
				PlaySE(se_rankup);
				masnGrade[player]++;
				masnGFlash[player] = 120;
			}
		}
	}
	
	// レベルアップ
	nextsec = masnLevel[player] / 100 * 100 + 100;
	if(!masnLvUpBonus) masnLevel[player] = masnLevel[player] + lines;
	else masnLevel[player] = masnLevel[player] + lines + ((lines >= 3) * (lines - 2));
	
	if(masnLevel[player] >= 999) {
		// エンディング
		masnLevel[player] = 999;
		ending[player] = 1;
		timeOn[player] = 0;
		masnEndFlag[player] = 1;
		
		// STメダル獲得
		masnMedalST(player, 9);
		
		// ROメダル獲得
		masnMedalRO(player);
		
		// mロール条件失敗判定
		if((masnVersion == 0) && (masnSTimer[player] > 2700)) masnGMFlag[player * 2 + 0] = 0;
		
		if((masnVersion >= 1) && (masnSTimer[player] > masnPreSTimer[player] + 120))
			masnGMFlag[player * 2 + 0] = 0;
		
		if(gameTimer[player] > 31500) masnGMFlag[player * 2 + 0] = 0;
		
		// mロール突入決定
		if((masnGMFlag[player * 2 + 0]) && (masnGMFlag[player * 2 + 1]) && (masnGrade[player] >= 17)) {
			objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
		}
	} else {
		// レベルストップ音
		if(masnLevel[player] >= 900) temp = 98;	// LV998
		else temp = 99;
		if(masnLevel[player] % 100 == temp) PlaySE(se_lvstop);
		
		if(masnLevel[player] >= nextsec) {
			// レベルアップ音
			PlaySE(se_levelup);
			
			// 背景切り替え
			bgfadesw = 1;
			bgfadebg = nextsec / 100;
			
			// STメダル獲得
			masnMedalST(player, (nextsec / 100) - 1);
			
			// ROメダル獲得
			if((nextsec == 300) || (nextsec == 700)) masnMedalRO(player);
			
			// mロール条件失敗判定
			if(masnVersion >= 1) temp = nextsec;
			else temp = masnLevel[player];
			temp2 = 500 + ((masnVersion >= 1) * 100);
			
			if((masnVersion == 0) || (temp < temp2)) {
				if(masnSTimer[player] > 3900) masnGMFlag[player * 2 + 0] = 0;
			}
			
			if( ((temp <  temp2) && (masnSHebo[player] < 2)) || 
			    ((temp >= temp2) && (masnSHebo[player] < 1)) )
				masnGMFlag[player * 2 + 1] = 0;
			
			if(masnVersion >= 1) {
				if((temp >= temp2) && (masnSTimer[player] > masnPreSTimer[player] + 120))
					masnGMFlag[player * 2 + 0] = 0;
				
				masnPreSTimer[player] = masnSTimer[player];
			}
			
			// セクションタイマーとヘボリス回数をリセット
			masnSTimer[player] = 0;
			masnSHebo[player] = 0;
		}
		
		// スピードアップ
		masnSpeedUp(player);
	}
}

// STメダル獲得
void masnMedalST(int player, int section) {
	masnSectionTime[section + player * 10] = masnSTimer[player];
	
	if((!playback) && (!IsBig[player]) && (!masnLvUpBonus) && (!masn20G) && (!masnStartLevel)) {
		if((masnSTimer[player] < masnRankingSectionTime[section]) && (masnMedalStat[player * 6 + 1] < 3)) {
			PlaySE(se_medal);
			masnMedalStat[player * 6 + 1] = 3;
			masnMedalAnim[player * 6 + 1] = 0;
		} else if((masnSTimer[player] < masnRankingSectionTime[section] + 300) && (masnMedalStat[player * 6 + 1] < 2)) {
			PlaySE(se_medal);
			masnMedalStat[player * 6 + 1] = 2;
			masnMedalAnim[player * 6 + 1] = 0;
		} else if((masnSTimer[player] < masnRankingSectionTime[section] + 600) && (masnMedalStat[player * 6 + 1] < 1)) {
			PlaySE(se_medal);
			masnMedalStat[player * 6 + 1] = 1;
			masnMedalAnim[player * 6 + 1] = 0;
		}
	}
}

// ROメダル獲得
void masnMedalRO(int player) {
	int temp, temp2;
	
	temp = bdowncnt[player];
	if(temp < 1) temp = 1;
	
	temp2 = masnTotalRotate[player] / temp;
	
	if( (temp2 >= 2) || ((temp2 == 1) && (masnTotalRotate[player] % temp >= 2)) ) {
		PlaySE(se_medal);
		masnMedalStat[player * 6 + 4]++;
		masnMedalAnim[player * 6 + 4] = 0;
	}
}

// BGM読み込み
void masnLoadBGM() {
	int i;
	
	if(bgmtype != 0) {
		for(i = 0; i < 5; i++) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/5)", i + 1);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(masnBgmNo[i]);
		}
	}
}

// スコア表示
void masnViewScore(int player) {
	int i, color, color2, x, y, k, zoomx, zoomy, temp;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// 段位
	color2 = (count % 4 / 2) * (is20G(player));
	
	if(masnGFlash[player] > 108) {
		// ズーム中
		k = masnGFlash[player] - 96;
		zoomx = (90 * k / 12 - 90) / 2;
		zoomy = (24 * k / 12 - 24) / 2;
		k = 65536 * k / 12;
		
		x = foffset[player] + 63 - zoomx;
		y = fyoffset[player] + 40 - zoomy;
		
		if(masnGrade[player] < 9) {
			// 9～1
			ExBltRectR(sg_grade, x, y, 0, (color2 * 216) + (masnGrade[player] * 24), 90, 24, k, k);
		} else if(masnGrade[player] < 18) {
			// S1～S9
			ExBltRectR(sg_grade, x, y, 90, (color2 * 216) + ((masnGrade[player] - 9) * 24), 90, 24, k, k);
		} else if(masnGrade[player] == 18) {
			// m
			ExBltRectR(sg_grade, x + 9, y, 450, (color2 * 216), 90, 24, k, k);
		} else {
			// Gm
			ExBltRectR(sg_grade, x + 9, y, 450, (color2 * 216) + 150, 90, 27, k, k);
		}
	} else {
		// 通常
		x = foffset[player] + 63;
		y = fyoffset[player] + 40;
		
		if(masnGrade[player] < 9) {
			// 9～1
			ExBltRect(sg_grade, x, y, 0, (color2 * 216) + (masnGrade[player] * 24), 90, 24);
		} else if(masnGrade[player] < 18) {
			// S1～S9
			ExBltRect(sg_grade, x, y, 90, (color2 * 216) + ((masnGrade[player] - 9) * 24), 90, 24);
		} else if(masnGrade[player] == 18) {
			// m
			ExBltRect(sg_grade, x + 9, y, 450, (color2 * 216), 90, 24);
		} else {
			// Gm
			ExBltRect(sg_grade, x + 9, y, 450, (color2 * 216) + 150, 90, 27);
		}
	}
	
	// メダル（通常）
	for(i = 0; i < 6; i++) {
		if((masnMedalAnim[player * 6 + i] < 0) || (masnMedalAnim[player * 6 + i] > 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 16;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			masnDrawMedal(x, y, i, masnMedalStat[player * 6 + i], masnMedalAnim[player * 6 + i]);
		}
	}
	
	// メダル（アニメ中）
	for(i = 0; i < 6; i++) {
		if((masnMedalAnim[player * 6 + i] >= 0) && (masnMedalAnim[player * 6 + i] <= 16)) {
			x = foffset[player] + 96 + (i % 2 != 0) * 16;
			y = fyoffset[player] + 80 + (i / 2) * 13;
			masnDrawMedal(x, y, i, masnMedalStat[player * 6 + i], masnMedalAnim[player * 6 + i]);
			masnMedalAnim[player * 6 + i]++;
		}
	}
	
	// スコア
	printTinyFont(foffset[player] + 96, fyoffset[player] + 135, "SCORE");
	sprintf(string[0], "%d", masnScore[player]);
	//sprintf(string[0], "%d", masnGPoint[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 143, string[0], color);
	
	// レベル（分子）
	printTinyFont(foffset[player] + 96, fyoffset[player] + 161, "LEVEL");
	if(masnLevel[player] == -1) sprintf(string[0], "%4d", 0);	// -1なら0と表示する(内部的には最初は-1になっている)
	else sprintf(string[0], "%4d", masnLevel[player]);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 169, string[0], color);
	
	// レベル（横線）
	ExBltRect(sg_spr, foffset[player] + 98, fyoffset[player] + 180, 0, 140, 24, 3);
	temp = sp[player] / 128;
	if(temp > 22) temp = 22;
	ExBltFastRect(sg_spr, foffset[player] + 99, fyoffset[player] + 181, 22 - temp, 143, 22, 1);
	
	// レベル（分母）
	if(masnLevel[player] >= 900) sprintf(string[0], "%4d", 999);
	else sprintf(string[0], "%4d", masnLevel[player] / 100 * 100 + 100);
	printSMALLFont(foffset[player] + 98, fyoffset[player] + 185, string[0], color);
	
	// タイム
	getTime(gameTimer[player]);
	printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color);
}

// メダルを表示
void masnDrawMedal(int x, int y, int kind, int color, int anim) {
	int i, j, k;
	
	if(color == 0) return;
	
	if((anim >= 0) && (anim < 16)) {
		k = 16 - anim;
		i = (15 * k / 3 - 15) / 2;
		j = (12 * k / 3 - 12) / 2;
		k = 65536 * k / 3;
		if(k < 65536) {
			k = 65536;
			i = 0;
			j = 0;
		}
		ExBltRectR(sg_medal[0], x - i, y - j, kind * 16, color * 13, 15, 12, k, k);
	} else {
		ExBltRect(sg_medal[0], x, y, kind * 16, color * 13, 15, 12);
	}
}

// 時間を進める
void masnIncrementTime(int player) {
	int i;
	
	// セクションタイム増加
	if(timeOn[player]) masnSTimer[player]++;
	
	// ロール終了
	if((ending[player] == 2) && (edrec[player] >= 60 * 60)) {
		ending[player] = 3;
		stat[player] = 10;
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
	
	// 段位が光る演出の時間を減らす
	if(masnGFlash[player] > 0) masnGFlash[player]--;
	
	// 段位ポイントを減少
	if((stat[player] == 4) && (masnGPoint[player] > 0) && (!ending[player])) {
		if(masnVersion >= 1) i = combo2[player];
		else i = combo3[player];
		
		if(i < 2) masnGTimer[player]++;
		
		i = masnClass[player];
		if(i > 31) i = 31;
		
		if(masnGTimer[player] >= masnGradeTimeLimit[i]) {
			masnGTimer[player] = 0;
			masnGPoint[player]--;
		}
	}
}

// エンディング突入
void masnEndingStart(int player) {
	int i;
	
	for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	
	ending[player] = 2;
	stat[player] = 4;
	ending_timeOn[player] = 1;
	fastroll[player] = 0;
	
	if((masnGMFlag[player * 2 + 0]) && (masnGMFlag[player * 2 + 1]) && (masnGrade[player] >= 17)) {
		// mロール
		hidden[player] = 10;
	} else {
		// 通常ロール
		hidden[player] = 8;
		shadowtime[player] = 300;
	}
	
	bgmlv = masnBgmNo[4];
	PlayBGM();
}

// エンディング終了
void masnExcellent(int player, int *param) {
	onRecord[player] = 0;
	masnEndFlag[player] = 2;
	statc[player * 10 + 1]++;
	
	if(statc[player * 10 + 1] == 1) {
		if(hidden[player] == 10) {
			// mロールクリア
			PlaySE(se_rankup);
			hidden[player] = 0;
			masnGrade[player] = 19;
			masnGFlash[player] = 120;
		} else {
			// ブロックを見えるようにする
			disableShadowTimer(player);
		}
	}
	
	// 花火
	if((statc[player * 10 + 1] % 10 == 0) && (statc[player * 10 + 2] < 30)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 2]++;
	}
	
	if(masnGrade[player] >= 19) {
		// YOU ARE GRAND MASTER!!
		param[0] = 1;
	} else {
		// EXCELLENT
		param[0] = 0;
		printTinyFont(foffset[player] + 20, fyoffset[player] + 116, "MASTER MODE");
		printTinyFont(foffset[player] + 25, fyoffset[player] + 123, "ALL CLEAR");
		
		printTinyFont(foffset[player] + 10, fyoffset[player] + 151, "TRY AGAIN TO BE");
		printTinyFont(foffset[player] + 12, fyoffset[player] + 158, "A GRAND MASTER");
	}
}

// ゲームオーバー処理の最初
void masnGameOver(int player) {
	// mロール失敗
	if((hidden[player] == 10) && (statc[player * 10 + 2] == 0) && (masnGrade[player] < 18)) {
		PlaySE(se_rankup);
		masnGrade[player] = 18;
		masnGFlash[player] = 120;
	}
}

// 結果表示
void masnResult(int player) {
	if(statc[player * 10] == 0) {
		// ランキング登録
		statc[player * 10 + 1] = masnRegistRanking(player);
		statc[player * 10 + 2] = masnUpdateSectionTimeRanking(player);
		if((statc[player * 10 + 1] != -1) || (statc[player * 10 + 2] != 0)) masnSaveRanking(player);
		
		// 裏段位判定
		statc[player * 10 + 3] = checkSecretGrade(player);
	}
	
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 45, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 59, "GRADE");
	sprintf(string[0], "%13s", masnStrGradeName[masnGrade[player]]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 67, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "SCORE");
	sprintf(string[0], "%13d", masnScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LEVEL");
	sprintf(string[0], "%13d", masnLevel[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "TIME");
	getTime(gameTimer[player]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[1], 0);
	
	if(statc[player * 10 + 1] != -1) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 139, "RANK");
		sprintf(string[0], "%13d", statc[player * 10 + 1] + 1);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 147, string[0], 0);
	}
	
	if(statc[player * 10 + 2] != 0) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 159, "ST RECORDS");
		sprintf(string[0], "%13d", statc[player * 10 + 2]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 167, string[0], 0);
	}
	
	if(statc[player * 10 + 3] >= 4) {
		printTinyFont(foffset[player] + 8, fyoffset[player] + 179, "SECRET GRADE");
		sprintf(string[0], "%13s", masnStrSecretGradeName[statc[player * 10 + 3]]);
		printSMALLFont(foffset[player] + 10, fyoffset[player] + 187, string[0], 0);
	}
}

// 設定画面
void masnSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	// 設定を読み込み
	if(masnLoadConfig() == 0) masnSaveConfig();
	
	// ランキングを読み込み
	if(masnLoadRanking(player) == 0) masnInitRanking();
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "MASTER-NORMAL OPTIONS", 4);
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
		if(!masnIsBig) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		if(!masnBigMove) sprintf(string[0], "1 BLOCK");
		else sprintf(string[0], "2 BLOCKS");
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(masnGhost == 0) sprintf(string[0], "LV100");
		else if(masnGhost == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "OFF");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		if(!masnLvUpBonus) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 6, string[0], 7 * (cursor == 3));
		
		if(!masn20G) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 7, string[0], 7 * (cursor == 4));
		
		sprintf(string[0], "%d", masnStartLevel);
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
			
			if(cursor == 0) masnIsBig = !masnIsBig;
			if(cursor == 1) masnBigMove = !masnBigMove;
			if(cursor == 2) {
				masnGhost = masnGhost + move;
				if(masnGhost < 0) masnGhost = 2;
				if(masnGhost > 2) masnGhost = 0;
			}
			if(cursor == 3) masnLvUpBonus = !masnLvUpBonus;
			if(cursor == 4) masn20G = !masn20G;
			if(cursor == 5) {
				masnStartLevel = masnStartLevel + (move * 100);
				if(masnStartLevel < 0) masnStartLevel = 900;
				if(masnStartLevel > 900) masnStartLevel = 0;
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
			masnSaveConfig();
			return;
		}
		
		// ランキング
		if(getPushState(player, 8)) {
			masnViewRanking(player);
		}
	}
}

// 設定を保存
void masnSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x494E494D;
	saveBuf[2] = 0x5453414D;
	saveBuf[3] = 0x314E5245;
	
	// 設定内容
	saveBuf[4] = masnIsBig;
	saveBuf[5] = masnBigMove;
	saveBuf[6] = masnGhost;
	saveBuf[7] = masnLvUpBonus;
	saveBuf[8] = masn20G;
	saveBuf[9] = masnStartLevel;
	
	SaveFile("config/MASTER_NORMAL_CONFIG.SAV", &saveBuf, 100 * 4);
}

// 設定を読み込み
int masnLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/MASTER_NORMAL_CONFIG.SAV", &saveBuf, 100 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 0x4F424548) return 0;
	if(saveBuf[1] != 0x494E494D) return 0;
	if(saveBuf[2] != 0x5453414D) return 0;
	if(saveBuf[3] != 0x314E5245) return 0;
	
	// 設定内容
	masnIsBig = saveBuf[4];
	masnBigMove = saveBuf[5];
	masnGhost = saveBuf[6];
	masnLvUpBonus = saveBuf[7];
	masn20G = saveBuf[8];
	masnStartLevel = saveBuf[9];
	
	return 1;
}

// リプレイ保存
void masnSaveReplay(int player) {
	saveBuf[900] = masnIsBig;
	saveBuf[901] = masnBigMove;
	saveBuf[902] = masnGhost;
	saveBuf[903] = masnLvUpBonus;
	saveBuf[904] = masnLevel[player];
	saveBuf[905] = masnScore[player];
	saveBuf[906] = masnGrade[player];
	saveBuf[907] = masnVersion;
	saveBuf[908] = masn20G;
	saveBuf[909] = masnStartLevel;
}

// リプレイ読み込み
void masnLoadReplay(int player) {
	masnIsBig = saveBuf[900];
	masnBigMove = saveBuf[901];
	masnGhost = saveBuf[902];
	masnLvUpBonus = saveBuf[903];
	masnVersion = saveBuf[907];
	masn20G = saveBuf[908];
	masnStartLevel = saveBuf[909];
	
	masnPlayerInitial(player);	// 設定を反映させる
}

// リプレイ詳細
void masnReplayDetail() {
	printFontGrid(1, 5, "GRADE", 0);
	if((saveBuf[906] >= 0) && (saveBuf[906] <= 19)) {
		printFontGrid(22, 5, masnStrGradeName[saveBuf[906]], 0);
	} else {
		printFontGrid(22, 5, "???", 0);
	}
	
	printFontGrid(1, 6, "SCORE", 0);
	sprintf(string[0], "%d", saveBuf[905]);
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 7, "LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[904]);
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
	
	printFontGrid(1, 13, "20G MODE", 0);
	if(!saveBuf[908]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 13, string[0], 0);
	
	printFontGrid(1, 14, "START LEVEL", 0);
	sprintf(string[0], "%d", saveBuf[909]);
	printFontGrid(22, 14, string[0], 0);
	
	printFontGrid(1, 15, "VERSION", 0);
	sprintf(string[0], "%d", saveBuf[907]);
	printFontGrid(22, 15, string[0], 0);
}

// ランキング保存
void masnSaveRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		saveBuf[1 + (i * 20) + 0]  = masnRankingGrade[i];
		saveBuf[1 + (i * 20) + 1]  = masnRankingLevel[i];
		saveBuf[1 + (i * 20) + 2]  = masnRankingTime[i];
		saveBuf[1 + (i * 20) + 3]  = masnRankingEnd[i];
		saveBuf[1 + (i * 20) + 4]  = masnRankingMedal[i * 6 + 0];
		saveBuf[1 + (i * 20) + 5]  = masnRankingMedal[i * 6 + 1];
		saveBuf[1 + (i * 20) + 6]  = masnRankingMedal[i * 6 + 2];
		saveBuf[1 + (i * 20) + 7]  = masnRankingMedal[i * 6 + 3];
		saveBuf[1 + (i * 20) + 8]  = masnRankingMedal[i * 6 + 4];
		saveBuf[1 + (i * 20) + 9]  = masnRankingMedal[i * 6 + 5];
		saveBuf[1 + (i * 20) + 10] = masnRankingYear[i];
		saveBuf[1 + (i * 20) + 11] = masnRankingMonth[i];
		saveBuf[1 + (i * 20) + 12] = masnRankingDay[i];
		saveBuf[1 + (i * 20) + 13] = masnRankingHour[i];
		saveBuf[1 + (i * 20) + 14] = masnRankingMinute[i];
		saveBuf[1 + (i * 20) + 15] = masnRankingSecond[i];
	}
	
	// セクションタイムランキング
	for(i = 0; i < 10; i++) {
		saveBuf[221 + (i * 10) + 0] = masnRankingSectionTime[i];
		saveBuf[221 + (i * 10) + 1] = masnRankingSectionEnd[i];
		saveBuf[221 + (i * 10) + 2] = masnRankingSectionYear[i];
		saveBuf[221 + (i * 10) + 3] = masnRankingSectionMonth[i];
		saveBuf[221 + (i * 10) + 4] = masnRankingSectionDay[i];
		saveBuf[221 + (i * 10) + 5] = masnRankingSectionHour[i];
		saveBuf[221 + (i * 10) + 6] = masnRankingSectionMinute[i];
		saveBuf[221 + (i * 10) + 7] = masnRankingSectionSecond[i];
	}
	
	sprintf(string[0], "config/MASTER_NORMAL_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	SaveFile(string[0], &saveBuf, 331 * 4);
}

// ランキング読み込み
int masnLoadRanking(int player) {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "config/MASTER_NORMAL_RANKING_%s.SAV", plugin_name_rule[rots[player]]);
	LoadFile(string[0], &saveBuf, 331 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		masnRankingGrade[i]         = saveBuf[1 + (i * 20) + 0];
		masnRankingLevel[i]         = saveBuf[1 + (i * 20) + 1];
		masnRankingTime[i]          = saveBuf[1 + (i * 20) + 2];
		masnRankingEnd[i]           = saveBuf[1 + (i * 20) + 3];
		masnRankingMedal[i * 6 + 0] = saveBuf[1 + (i * 20) + 4];
		masnRankingMedal[i * 6 + 1] = saveBuf[1 + (i * 20) + 5];
		masnRankingMedal[i * 6 + 2] = saveBuf[1 + (i * 20) + 6];
		masnRankingMedal[i * 6 + 3] = saveBuf[1 + (i * 20) + 7];
		masnRankingMedal[i * 6 + 4] = saveBuf[1 + (i * 20) + 8];
		masnRankingMedal[i * 6 + 5] = saveBuf[1 + (i * 20) + 9];
		masnRankingYear[i]          = saveBuf[1 + (i * 20) + 10];
		masnRankingMonth[i]         = saveBuf[1 + (i * 20) + 11];
		masnRankingDay[i]           = saveBuf[1 + (i * 20) + 12];
		masnRankingHour[i]          = saveBuf[1 + (i * 20) + 13];
		masnRankingMinute[i]        = saveBuf[1 + (i * 20) + 14];
		masnRankingSecond[i]        = saveBuf[1 + (i * 20) + 15];
	}
	
	// セクションタイムランキング
	for(i = 0; i < 10; i++) {
		masnRankingSectionTime[i]   = saveBuf[221 + (i * 10) + 0];
		masnRankingSectionEnd[i]    = saveBuf[221 + (i * 10) + 1];
		masnRankingSectionYear[i]   = saveBuf[221 + (i * 10) + 2];
		masnRankingSectionMonth[i]  = saveBuf[221 + (i * 10) + 3];
		masnRankingSectionDay[i]    = saveBuf[221 + (i * 10) + 4];
		masnRankingSectionHour[i]   = saveBuf[221 + (i * 10) + 5];
		masnRankingSectionMinute[i] = saveBuf[221 + (i * 10) + 6];
		masnRankingSectionSecond[i] = saveBuf[221 + (i * 10) + 7];
	}
	
	return 1;
}

// ランキング初期化
void masnInitRanking() {
	int i;
	
	// ノーマルランキング
	for(i = 0; i < 10; i++) {
		masnRankingGrade[i]         = 0;
		masnRankingLevel[i]         = 0;
		masnRankingTime[i]          = 0;
		masnRankingEnd[i]           = 0;
		masnRankingMedal[i * 6 + 0] = 0;
		masnRankingMedal[i * 6 + 1] = 0;
		masnRankingMedal[i * 6 + 2] = 0;
		masnRankingMedal[i * 6 + 3] = 0;
		masnRankingMedal[i * 6 + 4] = 0;
		masnRankingMedal[i * 6 + 5] = 0;
		masnRankingYear[i]          = 0;
		masnRankingMonth[i]         = 0;
		masnRankingDay[i]           = 0;
		masnRankingHour[i]          = 0;
		masnRankingMinute[i]        = 0;
		masnRankingSecond[i]        = 0;
	}
	
	// セクションタイムランキング
	for(i = 0; i < 10; i++) {
		masnRankingSectionTime[i]   = 5400;
		masnRankingSectionEnd[i]    = 0;
		masnRankingSectionYear[i]   = 0;
		masnRankingSectionMonth[i]  = 0;
		masnRankingSectionDay[i]    = 0;
		masnRankingSectionHour[i]   = 0;
		masnRankingSectionMinute[i] = 0;
		masnRankingSectionSecond[i] = 0;
	}
}

// ランキング登録
int masnRegistRanking(int player) {
	int i, j, timebuf[8];
	
	if((playback) || (IsBig[player]) || (masnLvUpBonus) || (masn20G) || (masnStartLevel)) return -1;
	
	for(i = 0; i < 10; i++) {
		// ランクイン
		if(
		    (masnEndFlag[player] > masnRankingEnd[i]) || 
		    ((masnEndFlag[player] == masnRankingEnd[i]) && (masnGrade[player] > masnRankingGrade[i])) || 
		    ((masnEndFlag[player] == masnRankingEnd[i]) && (masnGrade[player] == masnRankingGrade[i]) && (gameTimer[player] < masnRankingTime[i]))
		  )
		{
			// ランキングをずらす
			for(j = 9; j > i; j--) {
				masnRankingGrade[j]         = masnRankingGrade[j - 1];
				masnRankingLevel[j]         = masnRankingLevel[j - 1];
				masnRankingTime[j]          = masnRankingTime[j - 1];
				masnRankingEnd[j]           = masnRankingEnd[j - 1];
				masnRankingMedal[j * 6 + 0] = masnRankingMedal[(j - 1) * 6 + 0];
				masnRankingMedal[j * 6 + 1] = masnRankingMedal[(j - 1) * 6 + 1];
				masnRankingMedal[j * 6 + 2] = masnRankingMedal[(j - 1) * 6 + 2];
				masnRankingMedal[j * 6 + 3] = masnRankingMedal[(j - 1) * 6 + 3];
				masnRankingMedal[j * 6 + 4] = masnRankingMedal[(j - 1) * 6 + 4];
				masnRankingMedal[j * 6 + 5] = masnRankingMedal[(j - 1) * 6 + 5];
				masnRankingYear[j]          = masnRankingYear[j - 1];
				masnRankingMonth[j]         = masnRankingMonth[j - 1];
				masnRankingDay[j]           = masnRankingDay[j - 1];
				masnRankingHour[j]          = masnRankingHour[j - 1];
				masnRankingMinute[j]        = masnRankingMinute[j - 1];
				masnRankingSecond[j]        = masnRankingSecond[j - 1];
			}
			
			// 新しいデータを登録
			masnRankingGrade[i]         = masnGrade[player];
			masnRankingLevel[i]         = masnLevel[player];
			masnRankingTime[i]          = gameTimer[player];
			masnRankingEnd[i]           = masnEndFlag[player];
			masnRankingMedal[i * 6 + 0] = masnMedalStat[player * 6 + 0];
			masnRankingMedal[i * 6 + 1] = masnMedalStat[player * 6 + 1];
			masnRankingMedal[i * 6 + 2] = masnMedalStat[player * 6 + 2];
			masnRankingMedal[i * 6 + 3] = masnMedalStat[player * 6 + 3];
			masnRankingMedal[i * 6 + 4] = masnMedalStat[player * 6 + 4];
			masnRankingMedal[i * 6 + 5] = masnMedalStat[player * 6 + 5];
			
			GetDateAndTime(&timebuf);
			masnRankingYear[i]          = timebuf[0];
			masnRankingMonth[i]         = timebuf[1];
			masnRankingDay[i]           = timebuf[2];
			masnRankingHour[i]          = timebuf[4];
			masnRankingMinute[i]        = timebuf[5];
			masnRankingSecond[i]        = timebuf[6];
			
			return i;
		}
	}
	
	return -1;
}

// セクションタイムランキング更新
int masnUpdateSectionTimeRanking(int player) {
	int i, timebuf[8], result;
	result = 0;
	
	if((playback) || (IsBig[player]) || (masnLvUpBonus) || (masn20G) || (masnStartLevel)) return 0;
	
	for(i = 0; i < 10; i++) {
		if((masnSectionTime[i + player * 10] < masnRankingSectionTime[i]) && (masnSectionTime[i + player * 10] != 0)) {
			result++;
			
			masnRankingSectionTime[i] = masnSectionTime[i + player * 10];
			masnRankingSectionEnd[i] = masnEndFlag[player];
			
			GetDateAndTime(&timebuf);
			masnRankingSectionYear[i] = timebuf[0];
			masnRankingSectionMonth[i] = timebuf[1];
			masnRankingSectionDay[i] = timebuf[2];
			masnRankingSectionHour[i] = timebuf[4];
			masnRankingSectionMinute[i] = timebuf[5];
			masnRankingSectionSecond[i] = timebuf[6];
		}
	}
	
	return result;
}

// ランキング表示
void masnViewRanking(int player) {
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
			printFontGrid(1, 1, "MASTER-NORMAL MODE RANKING >>", 6);
			printFontGrid(1, 3, "RANK GRADE LEVEL TIME", 4);
			
			for(i = 0; i < 10; i++) {
				if(masnRankingEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (masnRankingEnd[i] - 1) * 2, 320, 2);
				
				if(i == 0) sprintf(string[0], " 1ST");
				if(i == 1) sprintf(string[0], " 2ND");
				if(i == 2) sprintf(string[0], " 3RD");
				if(i >= 3) sprintf(string[0], "%2dTH", i + 1);
				printFontGrid(1, 4 + i, string[0], 7 * (cursor == i));
				
				if((masnRankingGrade[i] >= 0) && (masnRankingGrade[i] < 20)) {
					printFontGrid(6, 4 + i, masnStrGradeName[masnRankingGrade[i]], 7 * (cursor == i));
				} else {
					printFontGrid(6, 4 + i, "???", 7 * (cursor == i));
				}
				
				sprintf(string[0], "%d", masnRankingLevel[i]);
				printFontGrid(12, 4 + i, string[0], 7 * (cursor == i));
				
				getTime(masnRankingTime[i]);
				printFontGrid(18, 4 + i, string[0], 7 * (cursor == i));
			}
			
			for(i = 0; i < 40; i++) printFontGrid(i, 22, "-", 1);
			
			if(!erasemode) {
				// メダル
				for(i = 0; i < 6; i++) masnDrawMedal(8 + i * 16, 192, i, masnRankingMedal[cursor * 6 + i], -1);
				
				// 日付と時刻
				sprintf(string[0],
				        "DATE: %04d/%02d/%02d %02d:%02d:%02d",
				        masnRankingYear[cursor], masnRankingMonth[cursor], masnRankingDay[cursor],
				        masnRankingHour[cursor], masnRankingMinute[cursor], masnRankingSecond[cursor]);
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
					masnInitRanking();
					masnSaveRanking(player);
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
			printFontGrid(1, 1, "<< MASTER-NORMAL MODE SECTION TIME", 6);
			printFontGrid(1, 3, "SECTION TIME     DATE", 4);
			printFontGrid(1, 28, "A/B:EXIT", 6);
			
			for(i = 0; i < 10; i++) {
				if(masnRankingSectionEnd[i]) ExBltFastRect(sg_line, 0, (4 + i) * 8 + 6, 0, (masnRankingSectionEnd[i] - 1) * 2, 320, 2);
				
				sprintf(string[0], "%3d-%3d", i * 100, ((i + 1) * 100) - 1);
				printFontGrid(1, 4 + i, string[0], 0);
				
				getTime(masnRankingSectionTime[i]);
				printFontGrid(9, 4 + i, string[0], 0);
				
				temp = (masnRankingSectionYear[i] / 1000) * 1000;	// 年を下2桁だけ表示
				if(temp == 0) temp = 1;
				sprintf(string[0], "%02d/%02d/%02d", masnRankingSectionYear[i] % temp, masnRankingSectionMonth[i], masnRankingSectionDay[i]);
				printFontGrid(18, 4 + i, string[0], 0);
				
				sprintf(string[0], "%02d:%02d:%02d", masnRankingSectionHour[i], masnRankingSectionMinute[i], masnRankingSectionSecond[i]);
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
