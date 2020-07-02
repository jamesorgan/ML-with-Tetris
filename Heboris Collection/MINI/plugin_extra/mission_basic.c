//prefix:misb

//□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□
//
//    MISSION-BASIC
//    Version 0
//
//□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   グローバル変数の定義
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// システム
int		misbModeNo = -1;			// モード番号
int		misbVersion;				// バージョン番号（古いリプレイ再生用）
int		misbCVersion = 1;			// 現在のバージョン

// 現在のゲームの状況
int		misbCourseNo;				// 現在のコース
int		misbMissionNo;				// 現在のミッション番号
int		misbNormCurrent;			// 達成ノルマ
int		misbNormMax;				// 目標ノルマ
int		misbTimer;					// 残り時間
int		misbLastLine;				// 最後のライン消し
int		misbIgnoreTorikan;			// 足切り無視権
int		misbClearFlag;				// ミッションクリアフラグ
int		misbIsAllClear;				// 1=足切り 2=完全クリア
int		misbScreen;					// stat[0] == 2の時の動作（0=ライン強制消去１ 1=ライン強制消去２）

// ミッションの状況
int		misbCycle[4];				// サイクル用フラグ

int		misbEraserLinePos[4];		// イレイサーのラインの位置
int		misbEraserLineClear[4];		// イレイサーのライン消去済みフラグ
int		misbEraserNowLines;			// イレイサーのライン数
int		misbEraserPatternNo;		// イレイサーの出現パターン番号（全てのラインを消すと+1）

int		misbTargetStageFlag[10000];	// ターゲットのステージ出現済みフラグ
int		misbTargetPatternNo;		// ターゲットの出現パターン番号

// 各ミッションのデータ
int		misbMType[40];				// 種類
int		misbMNorm[40];				// ノルマ
int		misbMLevel[40];				// レベル
int		misbMTimeLimit[40];			// 制限時間
int		misbMBgm[40];				// BGM
int		misbMBackground[40];		// 背景
int		misbMErase[40];				// クリア時に上から消去するライン数
int		misbMEndFlag[40];			// 終了フラグ
int		misbMParam[20 * 40];		// パラメータ

// コース全般のオプション
int		misbExcellentType;			// オールクリア時の演出
int		misbHideInfo;				// 指令を非表示
str*	misbCourseName;				// コース名

// ゲームオプション
int		misbLastCourse = 0;			// 最後に選択したコース
int		misbStartMissionNo = 0;		// スタート時のミッション番号
int		misbGhost = 1;				// ゴースト有効フラグ

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   レベルアップテーブル
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// ノーマル
int		misbNormalLevelTable[15] = {1, 3, 12, 18, 24, 30, 60, 120, 150, 180, 240, 300, 1200, 1200, 1200};
int		misbNormalWait1 = 25;	// 固定→次
int		misbNormalWait2 = 40;	// ブロック消去
int		misbNormalWait3 = 30;	// 接地→固定
int		misbNormalWaitt = 16;	// 横溜め

// アナザー
int		misbAnotherWait1Table[15] = {18,14,14,14,12,12,10, 8, 7, 6, 6, 6, 6, 6, 6};	// 固定→次
int		misbAnotherWait2Table[15] = {14, 8, 8, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4};	// ブロック消去
int		misbAnotherWait3Table[15] = {28,24,22,20,18,14,14,13,13,13,13,13,13,13,13};	// 接地→固定
int		misbAnotherWaittTable[15] = {10,10, 9, 9, 9, 8, 8, 7, 7, 7, 7, 7, 7, 7, 7};	// 横溜め

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   文字列データ
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// ミッション名
str misbStringMissionNameJ[13] = 
{
	"レベルスター",								// 0
	"ハイスピード２",							// 1
	"アナザー",									// 2
	"速度固定",									// 3
	"ビッグ",									// 4
	"シングル",									// 5
	"ダブル",									// 6
	"トリプル",									// 7
	"ヘボリス",									// 8
	"サイクル",									// 9
	"イレイサー",								// 10
	"ターゲット",								// 11
	"イレイサー",								// 12
};
str misbStringMissionNameE[13] = 
{
	"Level star",								// 0
	"Hi-Speed 2",								// 1
	"Another",									// 2
	"Speed Lock",								// 3
	"Big",										// 4
	"Single",									// 5
	"Double",									// 6
	"Triple",									// 7
	"Heboris",									// 8
	"Cycle",									// 9
	"Eraser",									// 10
	"Target",									// 11
	"Eraser",									// 12
};
str misbStringMissionNameCourseEdit[13] = 
{
	"LEVEL STAR",								// 0
	"HI-SPEED 2",								// 1
	"ANOTHER",									// 2
	"SPEED LOCK",								// 3
	"BIG",										// 4
	"SINGLE",									// 5
	"DOUBLE",									// 6
	"TRIPLE",									// 7
	"HEBORIS",									// 8
	"CYCLE",									// 9
	"ERASER",									// 10
	"TARGET",									// 11
	"ERASER (NO RANDOM)",						// 12
};

// 指令
str misbStringMissionInfoJ[13] = 
{
	"%dライン消せ！",							// 0
	"%dライン消せ！",							// 1
	"%dライン消せ！",							// 2
	"%dライン消せ！",							// 3
	"%dライン消せ！",							// 4
	"%d回シングルを決めろ！",					// 5
	"%d回ダブルを決めろ！",						// 6
	"%d回トリプルを決めろ！",					// 7
	"%d回ヘボリスを決めろ！",					// 8
	"サイクルを決めろ！",						// 9
	"%dライン消せ！",							// 10
	"%dステージクリアしろ！",					// 11
	"%dライン消せ！",							// 12
};
str misbStringMissionInfoE[13] = 
{
	"Erase %d line(s)!",						// 0
	"Erase %d line(s)!",						// 1
	"Erase %d line(s)!",						// 2
	"Erase %d line(s)!",						// 3
	"Erase %d line(s)!",						// 4
	"Erase 1 line only\n%d time(s)!",			// 5
	"Erase 2 lines at once\n%d time(s)!",		// 6
	"Erase 3 lines at once\n%d time(s)!",		// 7
	"Erase 4 lines at once\n%d time(s)!",		// 8
	"Do all kinds of\nline erase!",				// 9
	"Erase %d line(s)!",						// 10
	"Clear %d stage(s)!",						// 11
	"Erase %d line(s)!",						// 12
};

int misbStringMax = 12;

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベント発生時のメイン関数
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbPluginEvent(int player, int event, int *param) {
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != misbModeNo)) return;
	
	if(event == 0) {
		misbAddMode();	// モード登録
	} else if(event == 5) {
		misbReady(player, param);	// Ready
	} else if(event == 10) {
		if(!ending[player]) misbOnARE(player, param);	// ARE中の処理
	} else if(event == 12) {
		if(!ending[player]) misbCalcScore(player, param[0]);	// ライン消去時の処理
	} else if(event == 15) {
		misbViewScore(player);	// スコア表示
	} else if(event == 17) {
		misbSetting(player, param);	// 設定画面
	} else if(event == 18) {
		misbPlayerInitial(player);	// ゲーム開始時の初期化
	} else if(event == 21) {
		misbResult(player);	// 結果表示
	} else if(event == 24) {
		misbEndingStart(player);	// エンディング突入
	} else if(event == 25) {
		misbExcellent(player, param);	// EXCELLENT画面
	} else if(event == 28) {
		misbIncrementTime(player);	// 時間を進める
	} else if(event == 34) {
		misbViewEraserLines(player);	// イレイサーの線を表示
	} else if(event == 38) {
		misbPlayBGM();	// BGM再生
	} else if(event == 39) {
		misbSaveReplay(player);	// リプレイ保存
	} else if(event == 40) {
		misbLoadReplay(player);	// リプレイ読み込み
	} else if(event == 41) {
		misbLoadBGM();	// BGM読み込み
	} else if(event == 55) {
		misbReplayDetail();	// リプレイ詳細
	} else if(event == 68) {
		if(misbScreen == 0) misbStatDelLineNormal(player);	// ライン強制消去１
		if(misbScreen == 1) misbStatDelLineExtra(player);	// ライン強制消去２
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベントNo.0 - モード登録
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbAddMode() {
	misbModeNo = addModePlugin("MISSION-BASIC");	// モードを登録する
	misbCourseName = new(16);	// コース名に使用するメモリを確保
	StrCpy(misbCourseName, "");	// コース名を空で初期化
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベントNo.18 - ゲーム開始時の初期化
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbPlayerInitial(int player) {
	// バージョン
	if(!playback) misbVersion = misbCVersion;
	
	// 枠の色を灰色にする
	framecolor[player] = 5;
	frame_decoration[player] = 1;
	
	// 操作状況の表示位置
	if(!misbHideInfo) coffset = 221;
	else coffset = s_coffset;
	
	// 変数を初期化
	misbNormCurrent = 0;
	misbNormMax = 0;
	misbTimer = 0;
	misbLastLine = 0;
	misbIgnoreTorikan = 0;
	misbClearFlag = 0;
	misbIsAllClear = 0;
	misbScreen = 0;
	
	// 設定を反映させる
	misbApplyGameSetting(player);
}

// 設定を反映させる
void misbApplyGameSetting(int player) {
	misbCourseNo = misbLastCourse;
	misbMissionNo = misbStartMissionNo;
	if(!misbGhost) ghost[player] = 0;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベントNo.12 - ライン消去時の処理
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbCalcScore(int player, int lines) {
	int i, temp;
	
	// 最後のライン消しの種類を記憶
	misbLastLine = lines;
	
	// 全消し
	if(isBravo(player)) {
		PlaySE(se_levelup);
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
	}
	
	// レベルスター～ビッグ
	if(misbMType[misbMissionNo] <= 4) {
		misbNormCurrent = misbNormCurrent + lines;
	}
	// シングル
	if(misbMType[misbMissionNo] == 5) {
		if(lines == 1) misbNormCurrent++;
	}
	// ダブル
	if(misbMType[misbMissionNo] == 6) {
		if(lines == 2) misbNormCurrent++;
	}
	// トリプル
	if(misbMType[misbMissionNo] == 7) {
		if(lines == 3) misbNormCurrent++;
	}
	// ヘボリス
	if(misbMType[misbMissionNo] == 8) {
		if(lines == 4) misbNormCurrent++;
	}
	// サイクル
	if(misbMType[misbMissionNo] == 9) {
		if(!misbCycle[lines - 1]) {
			misbCycle[lines - 1] = 1;
			misbNormCurrent++;
		}
	}
	// イレイサー
	if((misbMType[misbMissionNo] == 10) || (misbMType[misbMissionNo] == 12)) {
		// 消えるラインを調べる
		temp = misbEraserNowLines;
		for(i = 0; i < misbEraserNowLines; i++) {
			if(!misbEraserLineClear[i]) {
				if(erase[misbEraserLinePos[i]]) {
					misbEraserLineClear[i] = 1;
					misbNormCurrent++;
					temp--;
				}
			} else {
				temp--;
			}
		}
		
		// 全部消えてもまだノルマが残ってるなら次のパターンへ
		if((misbNormCurrent < misbNormMax) && (temp <= 0)) {
			misbEraserPatternNo++;
			if(misbMType[misbMissionNo] == 10) misbSetRandomEraserLines();
			if(misbMType[misbMissionNo] == 12) misbSetNormalEraserLines();
		}
	}
	// ターゲット
	if(misbMType[misbMissionNo] == 11) {
		if(!checkHowManyPBlocks(0)) {
			misbNormCurrent++;
			StopSE(se_hurryup);
			timeOn[player] = 0;
		}
	}
	
	// ミッションクリア
	if(misbNormCurrent >= misbNormMax) {
		// 流れ星
		if( ((misbMEndFlag[misbMissionNo] == 2) || (misbMEndFlag[misbMissionNo] == 3)) && (misbLastLine == 2) )
			objectCreate(player, 6, Rand(20) + foffset[player] + 68, fyoffset[player] + 20 + Rand(10), 0, 0, 0, 0);
		
		misbNormCurrent = misbNormMax;
		StopSE(se_hurryup);
		timeOn[player] = 0;
		misbClearFlag = 1;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベントNo.5 - Ready
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbReady(int player, int *param) {
	// 最初のフレームの処理
	if(!statc[player * 10]) {
		// ミッション開始時の処理
		if((misbClearFlag) || (ready_count[player] == 0)) {
			misbSetMissionStatus();
		}
		// ターゲットのステージ読み込み
		else if(misbMType[misbMissionNo] == 11) {
			misbTargetStartNewStage();
		}
	}
}

// ミッション開始時の処理
void misbSetMissionStatus() {
	int i, temp, use_custom_speed;
	use_custom_speed = 0;
	
	misbNormCurrent = 0;
	misbNormMax = misbMNorm[misbMissionNo];
	if(misbNormMax == 0) misbNormMax = 1;
	misbTimer = misbMTimeLimit[misbMissionNo];
	misbClearFlag = 0;
	
	if(ready_count[0] == 0) {
		if(misbMBackground[misbMissionNo] > 0) backno = misbMBackground[misbMissionNo] - 1;
	} else if(misbMBackground[misbMissionNo] == 0) {
		bgfadesw = 1;
		bgfadebg = backno + 1;
		if(bgfadebg > 19) bgfadebg = 0;
	} else if(backno != misbMBackground[misbMissionNo] - 1) {
		bgfadesw = 1;
		bgfadebg = misbMBackground[misbMissionNo] - 1;
	}
	
	if((bgmlv != misbMBgm[misbMissionNo]) && (fadelv == 0)) fadelv = 1;
	
	IsBig[0] = 0;
	
	// ハイスピード２
	if(misbMType[misbMissionNo] == 1) {
		sp[0] = 1200;
		speedtype[0] = 0;
		wait1[0] = misbNormalWait1;
		wait2[0] = misbNormalWait2;
		wait3[0] = misbNormalWait3;
		waitt[0] = misbNormalWaitt;
		use_custom_speed = 1;
	}
	// アナザー
	if(misbMType[misbMissionNo] == 2) {
		if(misbMLevel[misbMissionNo] < 15) {
			temp = misbMLevel[misbMissionNo];
		} else {
			temp = misbMLevel[misbMissionNo] - 15;
		}
		
		sp[0] = 1200;
		speedtype[0] = 0;
		wait1[0] = misbAnotherWait1Table[temp];
		wait2[0] = misbAnotherWait2Table[temp];
		wait3[0] = misbAnotherWait3Table[temp];
		waitt[0] = misbAnotherWaittTable[temp];
		use_custom_speed = 1;
	}
	// 速度固定
	if(misbMType[misbMissionNo] == 3) {
		sp[0] = misbMParam[misbMissionNo * 20 + 0];
		speedtype[0] = misbMParam[misbMissionNo * 20 + 1];
		wait1[0] = misbMParam[misbMissionNo * 20 + 2];
		wait2[0] = misbMParam[misbMissionNo * 20 + 3];
		wait3[0] = misbMParam[misbMissionNo * 20 + 4];
		waitt[0] = misbMParam[misbMissionNo * 20 + 5];
		IsBig[0] = misbMParam[misbMissionNo * 20 + 6];
		BigMove[0] = misbMParam[misbMissionNo * 20 + 7];
		use_custom_speed = 1;
	}
	// ビッグ
	if(misbMType[misbMissionNo] == 4) {
		IsBig[0] = 1;
		BigMove[0] = misbMParam[misbMissionNo * 20 + 0];
	}
	// サイクル
	if(misbMType[misbMissionNo] == 9) {
		for(i = 0; i < 4; i++) misbCycle[i] = 0;
		misbNormMax = 4;
	}
	// イレイサー
	if(misbMType[misbMissionNo] == 10) {
		for(i = 0; i < 4; i++) misbEraserLinePos[i] = 0;
		misbEraserPatternNo = 0;
		misbSetRandomEraserLines();
	}
	// ターゲット
	if(misbMType[misbMissionNo] == 11) {
		misbTargetPatternNo = 0;
		for(i = 0; i < 10000; i++) misbTargetStageFlag[i] = 0;
		misbTargetStartNewStage();
	}
	// 非ランダムイレイサー
	if(misbMType[misbMissionNo] == 12) {
		for(i = 0; i < 4; i++) misbEraserLinePos[i] = 0;
		misbEraserPatternNo = 0;
		misbSetNormalEraserLines();
	}
	
	// デフォルトの速度を設定
	if(!use_custom_speed) {
		if(misbMLevel[misbMissionNo] < 15) {
			sp[0] = misbNormalLevelTable[misbMLevel[misbMissionNo]];
			speedtype[0] = 0;
			wait1[0] = misbNormalWait1;
			wait2[0] = misbNormalWait2;
			wait3[0] = misbNormalWait3;
			waitt[0] = misbNormalWaitt;
		} else {
			sp[0] = 1200;
			speedtype[0] = 0;
			wait1[0] = misbAnotherWait1Table[misbMLevel[misbMissionNo] - 15];
			wait2[0] = misbAnotherWait2Table[misbMLevel[misbMissionNo] - 15];
			wait3[0] = misbAnotherWait3Table[misbMLevel[misbMissionNo] - 15];
			waitt[0] = misbAnotherWaittTable[misbMLevel[misbMissionNo] - 15];
		}
	}
	
	// 指令情報を更新
	misbViewMissionText();
}

// イレイサーの線の位置を設定
void misbSetRandomEraserLines() {
	int i, temp;
	int min, max;	// 出現範囲
	int lines;	// 出現数
	int lineflag[22];	// ラインの重複防止用
	
	misbEraserNowLines = 0;
	for(i = 0; i < 22; i++) lineflag[i] = 0;
	
	// 出現範囲を決める
	min = misbMParam[misbMissionNo * 20 + 0];
	max = misbMParam[misbMissionNo * 20 + 1];
	
	if(min > max) {
		min = i;
		min = max;
		i = max;
	}
	
	// 同時出現数を決める
	temp = misbEraserPatternNo;
	if(temp > 10) temp = 10;
	lines = misbMParam[misbMissionNo * 20 + 2 + temp];
	if(lines < 1) lines = 1;
	if(lines > 4) lines = 4;
	
	// 出現処理
	for(i = 0; i < lines; i++) {
		// 余分なラインを出さない
		if(i >= misbNormMax - misbNormCurrent) break;
		
		// 出現ライン数+1
		misbEraserNowLines++;
		
		// 位置を決める
		if(min == max) {
			// 位置固定
			temp = min;
		} else if((i >= misbNormMax - misbNormCurrent - 1) && (misbNormMax > 1) && (!lineflag[min + 1])) {
			// 最後の1本
			temp = min + 1;
		} else {
			// ランダム
			do {
				temp = GiziRand(0, 22);
			} while( (temp < min) || (temp > max) || (lineflag[temp] == 1) );
		}
		if(temp < 0) temp = 0;
		if(temp > 21) temp = 21;
		
		lineflag[temp] = 1;
		misbEraserLinePos[i] = temp;
		misbEraserLineClear[i] = 0;
	}
}

// 非ランダムイレイサーの線の位置を設定
void misbSetNormalEraserLines() {
	int i, lines, lineflag[22], pos, pat;
	
	misbEraserNowLines = 0;
	for(i = 0; i < 22; i++) lineflag[i] = 0;
	
	// パターン番号
	pat = misbEraserPatternNo;
	if(pat < 0) pat = 0;
	if(pat > 3) pat = 3;
	
	// 最大出現数を決める
	lines = misbMParam[misbMissionNo * 20 + pat * 5 + 0];
	if(lines < 1) lines = 1;
	if(lines > 4) lines = 4;
	
	// 出現処理
	for(i = 0; i < lines; i++) {
		// 余分なラインを出さない
		if(i >= misbNormMax - misbNormCurrent) break;
		
		// 位置を決める
		pos = misbMParam[misbMissionNo * 20 + pat * 5 + 1 + i];
		if(pos < 0) pos = 0;
		if(pos > 21) pos = 21;
		
		// 重複出現してないなら
		if(!lineflag[pos]) {
			// 出現
			misbEraserNowLines++;
			misbEraserLinePos[i] = pos;
			misbEraserLineClear[i] = 0;
			lineflag[pos] = 1;
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベントNo.34 - イレイサーの線を表示
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbViewEraserLines(int player) {
	int i;
	
	if(!onRecord[player]) return;
	
	if((misbMType[misbMissionNo] == 10) || (misbMType[misbMissionNo] == 12)) {
		for(i = 0; i < misbEraserNowLines; i++) {
			ExBltRect(sg_spr, foffset[player] + 1, fyoffset[player] + (misbEraserLinePos[i] + 3) * 8, 89, 165 + misbEraserLineClear[i] * 8, 95, 8);
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ターゲットのステージを読み込み
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲

// 出現させるステージ選択＆読み込み処理
void misbTargetStartNewStage() {
	int i, temp, type, min, max, stg, rcnt;
	
	// 次のパターンへ
	temp = misbMParam[misbMissionNo * 20 + 5 + misbTargetPatternNo * 4];
	
	if((misbTargetPatternNo < 3) && (temp != 0) && (misbNormCurrent >= temp)) {
		misbTargetPatternNo++;
		for(i = 0; i < 10000; i++) misbTargetStageFlag[i] = 0;
	}
	
	// ステージの出現範囲を決める
	type = misbMParam[misbMissionNo * 20 + 2 + misbTargetPatternNo * 4];
	min = misbMParam[misbMissionNo * 20 + 3 + misbTargetPatternNo * 4];
	max = misbMParam[misbMissionNo * 20 + 4 + misbTargetPatternNo * 4];
	
	// 出現させるステージを決める
	if(min == max) {
		// ステージが1つだけの場合
		stg = min;
	} else {
		// ランダム
		rcnt = 0;
		do {
			stg = GiziRand(0, max + 1);
			
			rcnt++;
			if(rcnt > 100000) {
				if(!english) debugLogMode("ステージ決定処理で無限ループが発生しました。");
				else debugLogMode("An infinite loop was generated by the stage decision processing.");
				break;
			}
		} while((stg < min) || (misbTargetStageFlag[stg] != 0));
	}
	
	// 出現済みフラグON
	misbTargetStageFlag[stg] = 1;
	
	// ステージ読み込み
	misbTargetLoadStage(0, stg, type);
	
	// 全てのブロックをプラチナにする
	if(misbMParam[misbMissionNo * 20 + 0] == 9999) {
		misbTargetTransformAllBlockToPlatinumBlock();
	}
	// プラチナブロックの配置をランダムにする
	else if(misbMParam[misbMissionNo * 20 + 0] > 0) {
		misbTargetRandmizePlatinumBlock(misbMParam[misbMissionNo * 20 + 0], misbMParam[misbMissionNo * 20 + 1]);
	}
}

// ステージ読み込み
int misbTargetLoadStage(int player, int number, int type) {
	int i, size, offset;
	
	// 読み込み失敗しても大丈夫なようにダミーでデフォルト値を設定
	resetField(player);
	
	// 読み込み開始
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	if(type == 0) {
		sprintf(string[0], "stage/tomoyo_normal/stage%02d.sav", number);
		size = 200 * 4;
	} else if(type == 1) {
		sprintf(string[0], "stage/flash/flash%02d.sav", number);
		size = 60 * 4;
	} else {
		sprintf(string[0], "stage/target/stage%02d.sav", number);
		size = 60 * 4;
	}
	LoadFile(string[0], &saveBuf, size);
	
	// ヘッダがおかしいなら終了
	if(type == 0) {
		if(saveBuf[0] != 0x4F4D4F54) return 0;
		if(saveBuf[1] != 0x4F4D4F59) return 0;
		if(saveBuf[2] != 0x54534544) return 0;
		if(saveBuf[3] != 0x31454741) return 0;
	} else {
		if(saveBuf[0] != 1) return 0;
	}
	
	// 地形データ
	if(type == 0) offset = 4;
	else offset = 1;
	
	for(i = 0; i < 55; i++) {
		fld[(i * 4) + 0 + player * 220] = (saveBuf[offset + i] & 0x000000FF);
		fld[(i * 4) + 1 + player * 220] = (saveBuf[offset + i] & 0x0000FF00) >> 8;
		fld[(i * 4) + 2 + player * 220] = (saveBuf[offset + i] & 0x00FF0000) >> 16;
		fld[(i * 4) + 3 + player * 220] = (saveBuf[offset + i] & 0xFF000000) >> 24;
	}
	disableShadowTimer(player);	// ブロックを見えるようにする
	
	return 1;
}

// プラチナブロックの配置をランダムにする
void misbTargetRandmizePlatinumBlock(int randmax, int opt) {
	int i, j, k, pblk, top;
	int line[22];
	int rcnt;
	pblk = 0;
	rcnt = 0;
	top = checkFieldTop(0);
	
	if(opt) {
		pblk = opt;
		i = 22 - top;	// フリーズ対策（無駄っぽい）
		if(pblk > i) pblk = i;
		if(pblk <= 0) return;
	}
	
	// プラチナブロックを普通のブロックにする＆プラチナブロックの数を数える
	for(i = 0; i < 22; i++) {
		line[i] = 0;
		
		for(k = 0; k < 10; k++) {
			if(fld[k + i * 10] >= 11) {
				if(!opt) pblk++;
				fld[k + i * 10] = fld[k + i * 10] - 9;
			}
		}
	}
	
	// プラチナブロックをランダムに配置
	j = 0;
	while(j < pblk) {
		for(i = 0; i < 22; i++) {
			for(k = 0; k < 10; k++) {
				if((fld[k + i * 10] >= 2) && (fld[k + i * 10] <= 8) && (!line[i])) {
					if(GiziRand(0, randmax) == 0) {
						fld[k + i * 10] = fld[k + i * 10] + 9;
						if(opt) line[i] = 1;
						j++;
						if(j >= pblk) return;
					}
				}
			}
		}
		
		// 全部のラインにプラチナブロックが配置されたら終了
		if((misbVersion >= 1) && (opt)) {
			for(i = top; i < 22; i++) {
				if(line[i]) return;
			}
		}
		
		// 無限ループ対策
		rcnt++;
		if(rcnt > 100000) {
			if(!english) debugLogMode("プラチナブロックランダム配置処理で無限ループが発生しました。");
			else debugLogMode("An infinite loop was generated by the orb block random arrangement processing.");
			break;
		}
	}
}

// 全てのブロックをプラチナブロックにする
void misbTargetTransformAllBlockToPlatinumBlock() {
	int i;
	
	for(i = 0; i < 220; i++) {
		if(fld[i] != 0) fld[i] = 11 + Rand(7);
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベントNo.10 - ARE中の処理
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbOnARE(int player, int *param) {
	// クリア時の処理
	if(misbClearFlag) {
		param[0] = 1;	// 通常のARE処理をスキップ
		
		statc[player * 10]--;
		
		if(statc[player * 10] < 0) {
			// 通常エンディング
			if((misbMEndFlag[misbMissionNo] == 1) || (misbMissionNo >= 39)) {
				ending[player] = 1;
				onRecord[player] = 0;
				misbIsAllClear = 2;
			}
			// 「最後のラインをダブルで消せ！」に失敗＆足切り無視権を持っていない
			else if((misbMEndFlag[misbMissionNo] == 2) && (misbLastLine != 2) && (!misbIgnoreTorikan)) {
				ending[player] = 4;
				onRecord[player] = 0;
				misbIsAllClear = 1;
			}
			// それ以外
			else {
				// 足切り無視権使用／獲得
				if(misbMEndFlag[misbMissionNo] == 2)
					misbIgnoreTorikan = 0;
				else if((misbMEndFlag[misbMissionNo] == 3) && (misbLastLine == 2))
					misbIgnoreTorikan = 1;
				
				if((misbMErase[misbMissionNo] >= 1) && (misbMErase[misbMissionNo] <= 22)) {
					// ライン強制消去１
					stat[0] = 2;
					resetStatc(0);
					misbScreen = 0;
				} else if((misbMErase[misbMissionNo] >= 23) && (misbMErase[misbMissionNo] <= 44)) {
					// ライン強制消去２
					stat[0] = 2;
					resetStatc(0);
					misbScreen = 1;
				} else {
					// 次の問題へ
					misbMissionNo++;
					stat[0] = 3;
					resetStatc(0);
				}
			}
		}
	}
	// ターゲットのステージクリア
	else if((misbMType[misbMissionNo] == 11) && (!checkHowManyPBlocks(0))) {
		param[0] = 1;	// 通常のARE処理をスキップ
		
		statc[player * 10]--;
		
		if(statc[player * 10] < 0) {
			stat[0] = 3;
			resetStatc(0);
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベントNo.68 - ライン強制消去１
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbStatDelLineNormal(int player) {
	int i, j, cnt;
	
	// ブロック消去
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = checkFieldTop(player);
		cnt = 0;
		
		for(i = statc[player * 10 + 1]; i < 22; i++) {
			for(j = 0; j < 10; j++) {
				setFieldBlock(player, j, i, 0);
			}
			
			cnt++;
			if(cnt >= misbMErase[misbMissionNo]) break;
		}
	}
	
	// 線を表示
	if(statc[player * 10] <= 15) {
		cnt = 0;
		
		for(i = statc[player * 10 + 1]; i < 22; i++) {
			ExBltRect(sg_spr, foffset[player] + 8, fyoffset[player] + (i + 3) * 8, 8, 165 + statc[player * 10] * 8, 80, 8);
			
			cnt++;
			if(cnt >= misbMErase[misbMissionNo]) break;
		}
	}
	
	// 終了／継続
	if(statc[player * 10] >= 15 + wait1[player]) {
		misbMissionNo++;
		stat[player] = 3;
		resetStatc(player);
	} else {
		statc[player * 10]++;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベントNo.68 - ライン強制消去２
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbStatDelLineExtra(int player) {
	int i, j, cnt;
	
	// 初期化
	if(statc[player * 10] == 0) {
		statc[player * 10 + 1] = checkFieldTop(player) * 6;
		statc[player * 10 + 2] = 0;
	}
	
	// ブロックを消す
	if((statc[player * 10 + 1] % 6 == 0) && (statc[player * 10] < 129)) {
		j = statc[player * 10 + 1] / 6;
		
		if((j >= 0) && (j < fldsizey)) {
			for(i = 0; i < fldsizex; i++) {
				if(getFieldBlock(player, i, j)) {
					if(getFieldBlockO(player, i, j) == 0) {
						objectCreate(player, 1, foffset[player] + 8 + (i * 8), fyoffset[player] + (j + 3) * 8, (i - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + 1 * 250, getFieldBlock(player, i, j) - 1, 100);
					}
					setFieldBlock(player, i, j, 0);
					setFieldBlockT(player, i, j, 0);
					setFieldBlockO(player, i, j, 0);
					setFieldBlockL(player, i, j, 0);
					setFieldBlockI(player, i, j, 0);
				}
			}
			
			statc[player * 10 + 2]++;
			if(statc[player * 10 + 2] >= misbMErase[misbMissionNo] - 23) {
				if(statc[player * 10] < 129) statc[player * 10] = 129;
			}
		} else {
			if(statc[player * 10] < 129) statc[player * 10] = 129;
		}
	}
	
	// 終了／継続
	if(statc[player * 10] >= 129 + wait1[player]) {
		misbMissionNo++;
		stat[player] = 3;
		resetStatc(player);
	} else {
		statc[player * 10]++;
		statc[player * 10 + 1]++;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベントNo.15 - スコア表示
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbViewScore(int player) {
	int i, temp, color, color2;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	// 枠
	if(!misbHideInfo) {
		// 指令情報
		ExBltFastRect(sg_spr, 0, 112, 88, 229, 112, 112);
		
		// ミッション一覧
		temp = 0;
		while(misbMissionNo - temp > 4) temp = temp + 5;
		
		for(i = temp; i < temp + 5; i++) {
			// クリア済み
			if((misbMissionNo > i) || (ending[player])) {
				ExBltFastRect(sg_spr, 0, 32 + (i - temp) * 16, 88, 213, 96, 16);
				ExBltRect(sg_spr, 98, 34 + (i - temp) * 16, 12, 144, 12, 12);
			}
			// プレイ中
			else if(misbMissionNo == i) {
				ExBltFastRect(sg_spr, 0, 32 + (i - temp) * 16, 88, 197, 96, 16);
				ExBltRect(sg_spr, 98, 34 + (i - temp) * 16, 0, 144, 12, 12);
			}
			// まだ未プレイ
			else {
				ExBltFastRect(sg_spr, 0, 32 + (i - temp) * 16, 88, 181, 96, 16);
				ExBltRect(sg_spr, 98, 34 + (i - temp) * 16, 0, 144, 12, 12);
			}
			
			// 終了フラグがある場合はここでループを抜ける
			if((misbMEndFlag[i] == 1) || (misbMEndFlag[i] == 2)) break;
		}
		
		// コース名
		printSMALLFont(2, 8, misbCourseName, 4);
	}
	
	// ミッション番号
	printTinyFont(foffset[player] + 96, fyoffset[player] + 40, "MISSION");
	sprintf(string[0], "%d", misbMissionNo + 1);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 48, string[0], color);
	
	// トータルタイム
	printTinyFont(foffset[player] + 96, fyoffset[player] + 58, "TOTAL TIME");
	getTime(gameTimer[player]);
	printSMALLFont(foffset[player] + 96, fyoffset[player] + 66, string[0], color);
	
	// ノルマ（分子）
	ExBltRect(sg_smallfont, foffset[player] + 107, fyoffset[player] + 161, 0, 14, 22, 7);
	sprintf(string[0], "%4d", misbNormCurrent);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 169, string[0], color);
	
	// ノルマ（横線）
	ExBltRect(sg_spr, foffset[player] + 105, fyoffset[player] + 180, 0, 140, 24, 3);
	ExBltFastRect(sg_spr, foffset[player] + 106, fyoffset[player] + 181, 22, 143, 22, 1);
	
	// ノルマ（分母）
	sprintf(string[0], "%4d", misbNormMax);
	printSMALLFont(foffset[player] + 105, fyoffset[player] + 185, string[0], color);
	
	// 残り時間
	if(misbMTimeLimit[misbMissionNo]) {
		if((misbTimer <= 60 * 10) && (timeOn[player])) color2 = 2;
		else color2 = color;
		getTime(misbTimer);
		printBIGFont(foffset[player], fyoffset[player] + 216, string[0], color2);
	} else {
		ExBltFastRect(sg_gametext, foffset[player] - 1, fyoffset[player] + 216, 1, 229 + english * 18, 98, 16);
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   指令情報表示
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbViewMissionText() {
	int i, temp, cnt;
	
	for(i = 0; i < 10; i++) TextLayerOff(i);
	
	if(misbHideInfo) return;
	
	// 題名
	ExTextSize(0, 10);
	TextColor(0, 0, 0, 0);
	TextBackColorDisable(0);
	
	if(misbMType[misbMissionNo] <= misbStringMax) {
		if(!english) StrCpy(string[0], misbStringMissionNameJ[misbMType[misbMissionNo]]);
		else StrCpy(string[0], misbStringMissionNameE[misbMType[misbMissionNo]]);
	} else {
		StrCpy(string[0], "-----");
	}
	
	// レベル
	if(misbMLevel[misbMissionNo] >= 15)
		sprintf(string[1], " LV%02d+", misbMLevel[misbMissionNo] - 14);
	else
		sprintf(string[1], " LV%02d", misbMLevel[misbMissionNo] + 1);
	
	StrCat(string[0], string[1]);
	
	TextOut(0, string[0]);
	ExTextLayerOn(0, 5, 120);
	
	// 制限時間
	ExTextSize(1, 10);
	TextColor(1, 0, 0, 0);
	TextBackColorDisable(1);
	
	if(!english) StrCpy(string[1], "制限時間 ");
	else StrCpy(string[1], "Time ");
	
	if(misbMTimeLimit[misbMissionNo]) {
		getTime(misbMTimeLimit[misbMissionNo]);
	} else {
		if(!english) StrCpy(string[0], "無制限");
		else StrCpy(string[0], "No Limit");
	}
	StrCat(string[1], string[0]);
	
	TextOut(1, string[1]);
	ExTextLayerOn(1, 5, 132);
	
	// 指令文
	ExTextSize(2, 10);
	TextColor(2, 0, 0, 0);
	TextBackColorDisable(2);
	
	if(misbMType[misbMissionNo] <= misbStringMax) {
		if(!english) sprintf(string[0], misbStringMissionInfoJ[misbMType[misbMissionNo]], misbNormMax);
		else sprintf(string[0], misbStringMissionInfoE[misbMType[misbMissionNo]], misbNormMax);
	} else {
		StrCpy(string[0], "-----");
	}
	
	if(!misbIgnoreTorikan) {
		if((misbMEndFlag[misbMissionNo] == 2) || (misbMEndFlag[misbMissionNo] == 3)) {
			if(!english) StrCat(string[0], "\n最後のラインを\nダブルで消せ！");
			else StrCat(string[0], "\nLast erase 2 lines!");
		}
	}
	
	TextOut(2, string[0]);
	ExTextLayerOn(2, 5, 152);
	
	// ミッション一覧
	temp = 0;
	cnt = 0;
	
	while(misbMissionNo - temp > 4) temp = temp + 5;
	
	for(i = temp; i < temp + 5; i++) {
		if(misbMType[i] <= misbStringMax) {
			if(!english) StrCpy(string[0], misbStringMissionNameJ[misbMType[i]]);
			else StrCpy(string[0], misbStringMissionNameE[misbMType[i]]);
		} else {
			StrCpy(string[0], "-----");
		}
		
		ExTextSize(3 + cnt, 10);
		TextColor(3 + cnt, 0, 0, 0);
		TextBackColorDisable(3 + cnt);
		TextOut(3 + cnt, string[0]);
		ExTextLayerOn(3 + cnt, 1, 33 + cnt * 16);
		
		cnt++;
		
		// 終了フラグがある場合はここでループを抜ける
		if((misbMEndFlag[i] == 1) || (misbMEndFlag[i] == 2)) break;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベントNo.21 - 結果表示
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbResult(int player) {
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "MISSION");
	sprintf(string[0], "%13d", misbMissionNo + 1);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "TIME");
	getTime(gameTimer[player]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[1], 0);
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベントNo.28 - 時間を進める
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbIncrementTime(int player) {
	if((timeOn[player]) && (misbMTimeLimit[misbMissionNo] != 0)) {
		// 制限時間減少
		misbTimer--;
		
		// 時間切れ
		if(misbTimer <= 0) {
			PlaySE(se_timeover);
			misbTimer = 0;
			
			timeOn[player] = 0;
			onRecord[player] = 0;
			
			stat[player] = 7;
			resetStatc(player);
		}
		// 残り10秒
		else if(misbTimer == 10 * 60) {
			PlaySE(se_hurryup);
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベントNo.24 - エンディング突入
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbEndingStart(int player) {
	int i;
	ending[player] = 3;
	for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベントNo.25 - EXCELLENT画面
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbExcellent(int player, int *param) {
	onRecord[player] = 0;
	
	if(misbIsAllClear == 1) {
		// 足切り
		param[0] = 4;
		statc[player * 10 + 1]++;
		
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
			
			printFont(foffset[player] + 8, fyoffset[player] + 112, "BUT...", 0);
			printFont(foffset[player] + 8, fyoffset[player] + 120, "LAST ERASE", 0);
			printFont(foffset[player] + 8, fyoffset[player] + 128, "2 LINES", 0);
			printFont(foffset[player] + 8, fyoffset[player] + 136, "NEXT TIME", 0);
			
			// ボタンでスキップ
			if(getPushState(player, 4)) {
				statc[player * 10] = 600;
			}
		}
	} else {
		// 完全クリア
		if(misbExcellentType == 0) param[0] = 3;	// CLEAR!!
		if(misbExcellentType == 1) param[0] = 0;	// EXCELLENT
		if(misbExcellentType == 2) param[0] = 1;	// GM
		if(misbExcellentType == 3) param[0] = 2;	// GOD
		
		// 花火
		if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			statc[player * 10 + 1]++;
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベントNo.38 - BGM再生
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbPlayBGM() {
	bgmlv = misbMBgm[misbMissionNo];
	
	if(!IsPlayWave(bgm_plane[bgmlv])) {
		StopAllBGM();
		fadelv = 0;
		PlayBGM();
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベントNo.41 - BGM読み込み
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbLoadBGM() {
	int i, cnt, cnt2;
	int loadflag[30];
	
	if(bgmtype == 0) return;
	
	for(i = 0; i < 30; i++) loadflag[i] = 0;
	cnt = 0;
	
	// 読み込むべきBGMを決める
	for(i = 0; i < 40; i++) {
		if(!loadflag[misbMBgm[i]]) {
			loadflag[misbMBgm[i]] = 1;
			cnt++;
		}
		
		if(misbMEndFlag[i] == 1) break;
	}
	
	// 読み込み
	cnt2 = 0;
	
	for(i = 0; i < 30; i++) {
		if(loadflag[i]) {
			ClearSecondary();
			sprintf(string[0], "LOADING BGM... (%d/%d)", cnt2 + 1, cnt);
			printFontGrid(1, 1, string[0], 2);
			halt;
			loadBGM(i);
			cnt2++;
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベントNo.39 - リプレイ保存
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbSaveReplay(int player) {
	saveBuf[900] = misbLastCourse;
	saveBuf[901] = misbStartMissionNo;
	saveBuf[902] = misbGhost;
	saveBuf[903] = misbMissionNo;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベントNo.40 - リプレイ読み込み
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbLoadReplay(int player) {
	// 設定を読み込み
	misbLastCourse = saveBuf[900];
	misbStartMissionNo = saveBuf[901];
	misbGhost = saveBuf[902];
	
	// 設定を反映させる
	misbApplyGameSetting(player);
	
	// コース読み込み
	misbLoadCourseData(misbLastCourse);
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベントNo.55 - リプレイ詳細
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbReplayDetail() {
	printFontGrid(1, 4, "COURSE", 0);
	sprintf(string[0], "%d", saveBuf[900] + 1);
	printFontGrid(22, 4, string[0], 0);
	
	printFontGrid(1, 5, "START MISSION NO.", 0);
	sprintf(string[0], "%d", saveBuf[901] + 1);
	printFontGrid(22, 5, string[0], 0);
	
	printFontGrid(1, 6, "GHOST BLOCK", 0);
	if(!saveBuf[902]) sprintf(string[0], "OFF");
	else sprintf(string[0], "ON");
	printFontGrid(22, 6, string[0], 0);
	
	printFontGrid(1, 8, "LAST MISSION NO.", 0);
	sprintf(string[0], "%d", saveBuf[903] + 1);
	printFontGrid(22, 8, string[0], 0);
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   イベントNo.17 - 設定画面
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbSetting(int player, int *param) {
	int cursor, move;
	cursor = 0;
	move = 0;
	
	misbLoadConfig();	// 設定を読み込み
	misbLoadCourseDataNameOnly(misbLastCourse);	// コース名読み込み
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "MISSION-BASIC OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:EXIT D:EDIT", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "COURSE",            7 * (cursor == 0));
		printFontGrid(2, 4, "START MISSION NO.", 7 * (cursor == 1));
		printFontGrid(2, 5, "GHOST BLOCK",       7 * (cursor == 2));
		
		// 設定値表示
		sprintf(string[0], "%d:%s", misbLastCourse + 1, misbCourseName);
		printFontGrid(22, 3, string[0], 7 * (cursor == 0));
		
		sprintf(string[0], "%d", misbStartMissionNo + 1);
		printFontGrid(22, 4, string[0], 7 * (cursor == 1));
		
		if(!misbGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 5, string[0], 7 * (cursor == 2));
		
		// カーソル移動
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 2;
			if(cursor > 2) cursor = 0;
		}
		
		// 値を変更
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) {
				misbLastCourse = misbLastCourse + move;
				if(misbLastCourse < 0) misbLastCourse = 98;
				if(misbLastCourse > 98) misbLastCourse = 0;
				misbLoadCourseDataNameOnly(misbLastCourse);
			}
			if(cursor == 1) {
				misbStartMissionNo = misbStartMissionNo + move;
				if(misbStartMissionNo < 0) misbStartMissionNo = 39;
				if(misbStartMissionNo > 39) misbStartMissionNo = 0;
			}
			if(cursor == 2) misbGhost = !misbGhost;
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
			
			// 設定を保存
			misbSaveConfig();
			
			// コース読み込み
			misbLoadCourseData(misbLastCourse);
			
			return;
		}
		
		// エディット
		if(getPushState(player, 7)) {
			misbLoadCourseData(misbLastCourse);
			misbCourseDataEditor(player);
		}
	}
}

// 設定を保存
void misbSaveConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// 設定内容
	saveBuf[1] = misbLastCourse;
	saveBuf[2] = misbStartMissionNo;
	saveBuf[3] = misbGhost;
	
	SaveFile("config/MISSION_BASIC_CONFIG.SAV", &saveBuf, 50 * 4);
}

// 設定を読み込み
int misbLoadConfig() {
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/MISSION_BASIC_CONFIG.SAV", &saveBuf, 50 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 1) return 0;
	
	// 設定内容
	misbLastCourse = saveBuf[1];
	misbStartMissionNo = saveBuf[2];
	misbGhost = saveBuf[3];
	
	return 1;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   コースデータ保存
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbSaveCourseData(int number) {
	int i, j, temp[4];
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 1;
	
	// コース全般の設定
	saveBuf[1] = misbExcellentType;
	saveBuf[2] = misbHideInfo;
	
	// コース名を保存
	if(StrLen(misbCourseName) > 0) {
		StrCpy(&temp, misbCourseName);
		saveBuf[4] = temp[0];
		saveBuf[5] = temp[1];
		saveBuf[6] = temp[2];
		saveBuf[7] = temp[3];
	}
	
	// 問題データ
	for(i = 0; i < 40; i++) {
		saveBuf[8 + (i * 30) + 0] = misbMType[i];
		saveBuf[8 + (i * 30) + 1] = misbMNorm[i];
		saveBuf[8 + (i * 30) + 2] = misbMLevel[i];
		saveBuf[8 + (i * 30) + 3] = misbMTimeLimit[i];
		saveBuf[8 + (i * 30) + 4] = misbMBgm[i];
		saveBuf[8 + (i * 30) + 5] = misbMBackground[i];
		saveBuf[8 + (i * 30) + 6] = misbMErase[i];
		saveBuf[8 + (i * 30) + 7] = misbMEndFlag[i];
		
		for(j = 0; j < 20; j++) saveBuf[8 + (i * 30) + 10 + j] = misbMParam[i * 20 + j];
	}
	
	sprintf(string[0], "stage/mission/mission%02d.sav", number);
	SaveFile(string[0], &saveBuf, 1238 * 4);
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   コースデータ読み込み
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int misbLoadCourseData(int number) {
	int i, j, temp[4];
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "stage/mission/mission%02d.sav", number);
	LoadFile(string[0], &saveBuf, 1238 * 4);
	
	// コース全般の設定
	misbExcellentType = saveBuf[1];
	misbHideInfo = saveBuf[2];
	
	// コース名を読み込み
	if(saveBuf[0] != 1) {
		StrCpy(misbCourseName, "");
	} else {
		temp[0] = saveBuf[4];
		temp[1] = saveBuf[5];
		temp[2] = saveBuf[6];
		temp[3] = saveBuf[7];
		StrCpy(misbCourseName, &temp);
	}
	
	// 問題データ
	for(i = 0; i < 40; i++) {
		misbMType[i] = saveBuf[8 + (i * 30) + 0];
		misbMNorm[i] = saveBuf[8 + (i * 30) + 1];
		misbMLevel[i] = saveBuf[8 + (i * 30) + 2];
		misbMTimeLimit[i] = saveBuf[8 + (i * 30) + 3];
		misbMBgm[i] = saveBuf[8 + (i * 30) + 4];
		misbMBackground[i] = saveBuf[8 + (i * 30) + 5];
		misbMErase[i] = saveBuf[8 + (i * 30) + 6];
		misbMEndFlag[i] = saveBuf[8 + (i * 30) + 7];
		
		for(j = 0; j < 20; j++) misbMParam[i * 20 + j] = saveBuf[8 + (i * 30) + 10 + j];
	}
	
	return 1;
}

// 名前だけ読み込み
int misbLoadCourseDataNameOnly(int number) {
	int temp[4];
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	sprintf(string[0], "stage/mission/mission%02d.sav", number);
	LoadFile(string[0], &saveBuf, 8 * 4);
	
	if(saveBuf[0] != 1) {
		StrCpy(misbCourseName, "");
		return 0;
	}
	
	temp[0] = saveBuf[4];
	temp[1] = saveBuf[5];
	temp[2] = saveBuf[6];
	temp[3] = saveBuf[7];
	StrCpy(misbCourseName, &temp);
	
	return 1;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   コースエディット
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbCourseDataEditor(int player) {
	int i, cursor, move, number, params, temp;
	cursor = 0;
	move = 0;
	number = misbStartMissionNo;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		if(cursor <= 11) {
			printFontGrid(1, 1, "COURSE EDIT (PAGE 1/2)", 4);
			printFontGrid(1, 26, "A:OK B:CANCEL\n<>:1 D+<>:10 E+<>:100 F+<>:1000", 6);
			
			// カーソル表示
			if(cursor <= 8) printFontGrid(1, 3 + cursor, "b", 7);
			else printFontGrid(1, 3 + cursor, "b", 6);
			
			// メニュー表示
			printFontGrid(2,  3, "STAGE",               7 * (cursor ==  0));
			printFontGrid(2,  4, "TYPE",                7 * (cursor ==  1));
			printFontGrid(2,  5, "NORM",                7 * (cursor ==  2));
			printFontGrid(2,  6, "LEVEL",               7 * (cursor ==  3));
			printFontGrid(2,  7, "TIME LIMIT",          7 * (cursor ==  4));
			printFontGrid(2,  8, "BGM",                 7 * (cursor ==  5));
			printFontGrid(2,  9, "BACKGROUND",          7 * (cursor ==  6));
			printFontGrid(2, 10, "ERASE",               7 * (cursor ==  7));
			printFontGrid(2, 11, "END",                 7 * (cursor ==  8));
			printFontGrid(2, 12, "ALL CLEAR ANIMATION", 6 * (cursor ==  9));
			printFontGrid(2, 13, "HIDE INFO",           6 * (cursor == 10));
			printFontGrid(2, 14, "[COURSE NAME]",       6 * (cursor == 11));
			
			// 設定値表示
			sprintf(string[0], "%d", number + 1);
			printFontGrid(22, 3, string[0], 7 * (cursor == 0));
			
			if(misbMType[number] <= misbStringMax) StrCpy(string[0], misbStringMissionNameCourseEdit[misbMType[number]]);
			else StrCpy(string[0], "-----");
			printFontGrid(22, 4, string[0], 7 * (cursor == 1));
			
			sprintf(string[0], "%d", misbMNorm[number]);
			printFontGrid(22, 5, string[0], 7 * (cursor == 2));
			
			if(misbMLevel[number] >= 15) sprintf(string[0], "%d+", misbMLevel[number] - 14);
			else sprintf(string[0], "%d", misbMLevel[number] + 1);
			printFontGrid(22, 6, string[0], 7 * (cursor == 3));
			
			getTime(misbMTimeLimit[number]);
			printFontGrid(22, 7, string[0], 7 * (cursor == 4));
			
			sprintf(string[0], "%d", misbMBgm[number]);
			printFontGrid(22, 8, string[0], 7 * (cursor == 5));
			
			if(!misbMBackground[number]) sprintf(string[0], "AUTO");
			else sprintf(string[0], "BACK%02d.PNG", misbMBackground[number]);
			printFontGrid(22, 9, string[0], 7 * (cursor == 6));
			
			if(misbMErase[number] >= 23) sprintf(string[0], "EX %d", misbMErase[number] - 22);
			else sprintf(string[0], "%d", misbMErase[number]);
			printFontGrid(22, 10, string[0], 7 * (cursor == 7));
			
			if(misbMEndFlag[number] == 0) sprintf(string[0], "OFF");
			else if(misbMEndFlag[number] == 1) sprintf(string[0], "ENDING");
			else if(misbMEndFlag[number] == 2) sprintf(string[0], "EXTRA");
			else sprintf(string[0], "BONUS");
			printFontGrid(22, 11, string[0], 7 * (cursor == 8));
			
			if(misbExcellentType == 0) sprintf(string[0], "CLEAR!!");
			else if(misbExcellentType == 1) sprintf(string[0], "EXCELLENT");
			else if(misbExcellentType == 2) sprintf(string[0], "GM");
			else sprintf(string[0], "GOD");
			printFontGrid(22, 12, string[0], 6 * (cursor == 9));
			
			if(!misbHideInfo) sprintf(string[0], "OFF");
			else sprintf(string[0], "ON");
			printFontGrid(22, 13, string[0], 6 * (cursor == 10));
			
			if(StrLen(misbCourseName) > 0) {
				printFontGrid(22, 14, misbCourseName, 6 * (cursor == 11));
			} else {
				printFontGrid(22, 14, "(NONE)", 6 * (cursor == 11));
			}
		} else {
			printFontGrid(1, 1, "COURSE EDIT (PAGE 2/2)", 4);
			printFontGrid(1, 26, "A:OK B:CANCEL\n<>:1 D+<>:10 E+<>:100 F+<>:1000", 6);
			
			// カーソル表示
			printFontGrid(1, 3 + (cursor - 12), "b", 7);
			params = 0;
			
			// 速度固定
			if(misbMType[number] == 3) {
				printFontGrid(2, 3, "SPEED", 7 * (cursor == 12));
				printFontGrid(2, 4, "SPEED TYPE", 7 * (cursor == 13));
				if(!english) {
					printFontGrid(2, 5, "SYUTUGEN", 7 * (cursor == 14));
					printFontGrid(2, 6, "SYOUKYO", 7 * (cursor == 15));
					printFontGrid(2, 7, "SETTYAKU", 7 * (cursor == 16));
					printFontGrid(2, 8, "YOKOTAME", 7 * (cursor == 17));
				} else {
					printFontGrid(2, 5, "ARE", 7 * (cursor == 14));
					printFontGrid(2, 6, "LINE DELAY", 7 * (cursor == 15));
					printFontGrid(2, 7, "LOCK DELAY", 7 * (cursor == 16));
					printFontGrid(2, 8, "DAS", 7 * (cursor == 17));
				}
				printFontGrid(2, 9, "BIG", 7 * (cursor == 18));
				printFontGrid(2, 10, "BIG MOVE", 7 * (cursor == 19));
				params = 8;
			}
			// ビッグ
			if(misbMType[number] == 4) {
				printFontGrid(2, 3, "BIG MOVE", 7 * (cursor == 12));
				params = 1;
			}
			// イレイサー
			if(misbMType[number] == 10) {
				printFontGrid(2, 3, "MIN (3-21)", 7 * (cursor == 12));
				printFontGrid(2, 4, "MAX (3-21)", 7 * (cursor == 13));
				
				for(i = 0; i < 10; i++) {
					sprintf(string[0], "LINES (PATTERN %d)", i + 1);
					printFontGrid(2, 5 + i, string[0], 7 * (cursor == 14 + i));
				}
				
				params = 12;
			}
			// ターゲット
			if(misbMType[number] == 11) {
				printFontGrid(2, 3, "RANDOM TYPE", 7 * (cursor == 12));
				printFontGrid(2, 4, "RANDOM OPTION", 7 * (cursor == 13));
				
				for(i = 0; i < 4; i++) {
					sprintf(string[0], "STAGE TYPE (PAT-%d)", i + 1);
					printFontGrid(2, 5 + i * 4, string[0], 7 * (cursor == 14 + i * 4));
					sprintf(string[0], "STAGE MIN (PAT-%d)", i + 1);
					printFontGrid(2, 6 + i * 4, string[0], 7 * (cursor == 15 + i * 4));
					sprintf(string[0], "STAGE MAX (PAT-%d)", i + 1);
					printFontGrid(2, 7 + i * 4, string[0], 7 * (cursor == 16 + i * 4));
					
					if(i < 3) printFontGrid(2, 8 + i * 4, "n NORM TO NEXT", 7 * (cursor == 17 + i * 4));
				}
				
				params = 17;
			}
			// 非ランダムイレイサー
			if(misbMType[number] == 12) {
				for(i = 0; i < 4; i++) {
					sprintf(string[0], "LINES (PATTERN %d)", i + 1);
					printFontGrid(2, 3 + i * 5, string[0], 7 * (cursor == 12 + i * 5));
					sprintf(string[0], "POS-1 (PATTERN %d)", i + 1);
					printFontGrid(2, 4 + i * 5, string[0], 7 * (cursor == 13 + i * 5));
					sprintf(string[0], "POS-2 (PATTERN %d)", i + 1);
					printFontGrid(2, 5 + i * 5, string[0], 7 * (cursor == 14 + i * 5));
					sprintf(string[0], "POS-3 (PATTERN %d)", i + 1);
					printFontGrid(2, 6 + i * 5, string[0], 7 * (cursor == 15 + i * 5));
					sprintf(string[0], "POS-4 (PATTERN %d)", i + 1);
					printFontGrid(2, 7 + i * 5, string[0], 7 * (cursor == 16 + i * 5));
				}
				params = 20;
			}
			
			// NO PARAM
			for(i = params; i < 20; i++) {
				printFontGrid(2, 3 + i, "NO PARAM", 7 * (cursor == 12 + i));
			}
			
			// 設定値表示
			for(i = 0; i < 20; i++) {
				sprintf(string[0], "%d", misbMParam[number * 20 + i]);
				printFontGrid(22, 3 + i, string[0], 7 * (cursor == 12 + i));
			}
		}
		
		// カーソル移動
		padRepeat2(player);
		
		move = 0;
		if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
			move = getPressState(player, 1) - getPressState(player, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 31;
			if(cursor > 31) cursor = 0;
		}
		
		// 値を変更
		padRepeat(player);
		
		move = 0;
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
			move = getPressState(player, 3) - getPressState(player, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			temp = 1;
			if(getPressState(player, 7)) temp = 10;		// D
			if(getPressState(player, 8)) temp = 100;	// E
			if(getPressState(player, 9)) temp = 1000;	// F
			
			if(cursor == 0) {
				number = number + move * temp;
				if(number < 0) number = 39;
				if(number > 39) number = 0;
			}
			if(cursor == 1) {
				misbMType[number] = misbMType[number] + move * temp;
				if(misbMType[number] < 0) misbMType[number] = misbStringMax;
				if(misbMType[number] > misbStringMax) misbMType[number] = 0;
			}
			if(cursor == 2) {
				misbMNorm[number] = misbMNorm[number] + move * temp;
				if(misbMNorm[number] < 0) misbMNorm[number] = 99;
				if(misbMNorm[number] > 99) misbMNorm[number] = 0;
			}
			if(cursor == 3) {
				misbMLevel[number] = misbMLevel[number] + move * temp;
				if(misbMLevel[number] < 0) misbMLevel[number] = 29;
				if(misbMLevel[number] > 29) misbMLevel[number] = 0;
			}
			if(cursor == 4) {
				misbMTimeLimit[number] = misbMTimeLimit[number] + (move * temp * 60);
				if(misbMTimeLimit[number] < 0) misbMTimeLimit[number] = 72000;
				if(misbMTimeLimit[number] > 72000) misbMTimeLimit[number] = 0;
			}
			if(cursor == 5) {
				misbMBgm[number] = misbMBgm[number] + move * temp;
				if(misbMBgm[number] < 0) misbMBgm[number] = 29;
				if(misbMBgm[number] > 29) misbMBgm[number] = 0;
			}
			if(cursor == 6) {
				misbMBackground[number] = misbMBackground[number] + move * temp;
				if(misbMBackground[number] > 20) misbMBackground[number] = 0;
				if(misbMBackground[number] < 0) misbMBackground[number] = 20;
			}
			if(cursor == 7) {
				misbMErase[number] = misbMErase[number] + move * temp;
				if(misbMErase[number] < 0) misbMErase[number] = 44;
				if(misbMErase[number] > 44) misbMErase[number] = 0;
			}
			if(cursor == 8) {
				misbMEndFlag[number] = misbMEndFlag[number] + move * temp;
				if(misbMEndFlag[number] < 0) misbMEndFlag[number] = 3;
				if(misbMEndFlag[number] > 3) misbMEndFlag[number] = 0;
			}
			if(cursor == 9) {
				misbExcellentType = misbExcellentType + move * temp;
				if(misbExcellentType < 0) misbExcellentType = 3;
				if(misbExcellentType > 3) misbExcellentType = 0;
			}
			if(cursor == 10) misbHideInfo = !misbHideInfo;
			if(cursor >= 12) {
				misbMParam[number * 20 + (cursor - 12)] = misbMParam[number * 20 + (cursor - 12)] + move * temp;
				if(misbMParam[number * 20 + (cursor - 12)] < 0) misbMParam[number * 20 + (cursor - 12)] = 9999;
				if(misbMParam[number * 20 + (cursor - 12)] > 9999) misbMParam[number * 20 + (cursor - 12)] = 0;
			}
		}
		
		// キャンセル
		if(getPushState(player, 5)) {
			PlaySE(se_move);
			return;
		}
		
		// 決定
		if(getPushState(player, 4)) {
			PlayWave(se_kettei);
			
			if(cursor == 11) {
				misbCourseNameEntry(player);
			} else {
				misbSaveCourseData(misbLastCourse);
				return;
			}
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   コース名入力
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void misbCourseNameEntry(int player) {
	int move, len, currentChar;
	
	// 初期化
	StrCpy(string[2], misbCourseName);
	currentChar = 54;
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "ENTER COURSE NAME", 4);
		printFontGrid(1, 26, "A:OK B:DELETE D:CANCEL\n<>:SELECT C+<>:FAST SELECT", 6);
		
		len = StrLen(string[2]);	// 入力済み文字数
		
		// 横移動
		padRepeat(player);
		move = getPressState(player, 3) - getPressState(player, 2);
		if(move)
			if((mpc[player] == 1) || (mpc[player] >= 15) || getPressState(player, 6)) {
				if(mpc[player] >= 15) mpc[player] = 12;
				currentChar = currentChar + move;
				PlaySE(se_move);
			}
		
		// 文字のループ
		if(currentChar > 54)
			currentChar = (len == 15) * 53;
		if(currentChar < (len == 15) * 53)
			currentChar = 54;
		
		// 選択している文字と入力済み文字を表示
		MidStr(RankString, currentChar + 1, 1, string[3]);
		printFontGrid(1 + len, 3, string[3], 2 * (count % 20 > 10));
		printFontGrid(1, 3, string[2], 0);
		
		sprintf(string[0], "LENGTH:%02d/15", len);
		printFontGrid(1, 5, string[0], 1);
		
		// Dでキャンセル
		if(getPushState(player, 7)) {
			PlaySE(se_move);
			return;
		}
		
		// Bボタンで1文字削除
		if(getPushState(player, 5)) {
			if(len) {
				PlaySE(se_move);
				MidStr(string[2], 1, len - 1, string[2]);
			}
		}
		
		// Aボタンで入力
		if(getPushState(player, 4)) {
			PlaySE(se_kettei);
			
			if(currentChar == 53) {
				// RB
				if(len) {
					MidStr(string[2], 1, len - 1, string[2]);
				}
			} else if(currentChar == 54) {
				// ED
				PlaySE(se_cheer);
				
				// 名前の後ろにスペースを挿入（余った個所をスペースにする）
				sprintf(string[2], "%s                ", string[2]);
				
				// 左から16文字目以降を削除
				LeftStr(string[2], 15, string[2]);
				
				// 保存
				StrCpy(misbCourseName, string[2]);
				
				// 終わり
				return;
			} else {
				// 文字入力
				StrCat(string[2], string[3]);
			}
		}
	}
}
