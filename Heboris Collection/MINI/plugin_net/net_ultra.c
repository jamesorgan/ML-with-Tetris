//NET-ULTRA
//prefix:netu

int netuModeNo = -1;				// モード番号
int netuModeVersion = 3;			// Mode Version

int netuScore[2];					// スコア
int netuLines[2];					// ライン数
int netuLimitTime;					// 残り時間

int netuRound;						// ラウンド
int netuWin[2];						// 勝った回数

int netuTSpinFrame[2];				// T-SPIN表示／ヘボリス表示の残り時間
int netuTSpinLine[2];				// 最後のT-SPINライン消し／ヘボリス消しの種類
int netuComboFrame[2];				// コンボ数表示の残り時間
int netuB2BFrame[2];				// Back To Back表示の残り時間
int netuTSpinWall[2];				// 壁蹴りありのT-SPINだったら1になる
int netuScoreGet[2];				// 今入ったスコア表示の点数
int netuScoreFrame[2];				// 今入ったスコア表示の残り時間

int netuServerNo = 0;				// サーバー番号

int netuGhost = 1;					// ゴーストの設定
int netuTSpin = 3;					// T-SPINの種類
int netuEnableCombo = 1;			// コンボボーナスの有無
int netuEnableB2B = 1;				// Back To Backの有無（0=なし 1=通常 2=ヘボリスのみ 3=T-SPINのみ）
int netuSpeed = 1;					// 落下速度
int netuSpeedType = 0;				// スピードタイプ
int netuWait1 = 25;					// ARE
int netuWait2 = 40;					// ライン消去
int netuWait3 = 30;					// 固定時間
int netuWaitt = 16;					// 横溜め
int netuWait4 = -1;					// 固定時間（接着後）
int netuWait5 = -1;					// ARE（消去後）
int netuGameType = 0;				// 0=2分間ラインアタック 1=3分間スコアアタック
int netuAreUse = -1;				// ARE Force
int netuFastlrmove = -1;			// INIT LR Force
int netuRepeatDelay = -1;			// Repeat Delay
int netuMaxDAS = -1;				// Disable Max DAS
int netuSpawnType = -1;				// SPAWN Y TYPE Force
int netuHoldEnable = -1;			// Enable Hold

int netuPreset[20 * 10];			// プリセット
int netuLastPresetNo = 0;			// 最後に選択したプリセット番号

int netuPlayerType;					// 0ならホスト側、1ならゲスト側
int netuGameStart;					// ゲーム中なら1
int netuTraining;					// トレーニング中なら1

int netuCustomStatNo[2];			// stat[player] = 2のときの処理の番号

int netuLastBlk[2];					// 前のフレームのブロックの種類
int netuLastBx[2];					// 前のフレームのブロックのX座標
int netuLastBy[2];					// 前のフレームのブロックのY座標
int netuLastRt[2];					// 前のフレームのブロックの向き
int netuLastNDelay[2];				// 前のフレームのNEXT遅延状態

int netuReceiveRuleNameOK;			// ルール名を受信したフラグ
int netuReceiveRuleConfigOK;		// ルール設定を受信したフラグ
int netuReceiveNextListOK;			// NEXTブロックを受信したフラグ
int netuReceiveModeConfigOK;		// モード設定を受信したフラグ

int netuEnemyID;					// 対戦相手ID
int netuEnemyNotFound;				// 対戦相手が見つからないとき、再度対戦相手を検索するまでのフレーム数
int netuEnemyDisconnect;			// 対戦相手が切断したら1になる
int netuEnemyRulePluginMissing;		// 対戦相手のルールプラグインがこちら側に無いときは1になる
int netuEnemyReady;					// 対戦相手の準備完了で1になる
int netuEnemyBlockVisible;			// 対戦相手のブロックが表示されているかどうか
int netuEnemyGameEndFlag;			// 対戦相手が時間切れになると1になる

int netuServerVersion;				// サーバーバージョン
int netuClientCount;				// 接続者数
int netuMaxClient;					// 最大接続者数
int netuSameModeClientCount[3];		// 同じモードとバージョンを使用しているプレイヤーの数
int netuCountUpdateFrame;			// 次にプレイヤー数を更新するまでのフレーム数

int netuRuleConfigPlayer[26];		// ルール設定（自分）
int netuRuleConfigEnemy[26];		// ルール設定（敵）

str* netuNickname[2];				// 自分と敵のニックネーム

int netuBufIn[16384];				// 受信用バッファ
int netuBufOut[16384];				// 送信用バッファ

// イベント発生
void netuPluginEvent(int player, int event, int *param) {
	// モードが違うなら戻る（モードを登録するタイミング以外の場合）
	if((event != 0) && (gameMode[player] != netuModeNo)) return;
	
	if(event == 0) {
		netuModeNo = addModePlugin("NET-ULTRA");	// モードを登録する
		netuNickname[0] = new(64);
		netuNickname[1] = new(64);
		LeftStr(networkNickName, 63, netuNickname[0]);
		StrCpy(netuNickname[1], "");
	} else if(event == 1) {
		netuRecvData();	// データ受信
	} else if(event == 5) {
		netuReady(player, param);	// Ready
	} else if(event == 6) {
		netuStatMove(player, param);	// ブロック移動処理
	} else if(event == 8) {
		netuSoftDropScore(player);	// ソフトドロップで入った点数を加算
	} else if(event == 10) {
		netuARE(player);	// ARE中の処理
	} else if(event == 11) {
		netuStatEraseBlock(player, param);	// ブロック消去時の処理
	} else if(event == 12) {
		netuCalcScore(player, param[0]);	// ライン消去
	} else if(event == 15) {
		netuViewScore(player);	// スコア表示
	} else if(event == 17) {
		netuSetting(player, param);	// 設定画面
	} else if(event == 18) {
		netuPlayerInitial(player);	// 初期化処理
	} else if(event == 20) {
		netuGameOver(player, param);	// ゲームオーバー処理
	} else if(event == 21) {
		netuResult(player, param);	// 結果表示
	} else if(event == 22) {
		netuGameOver2(player, param);	// ゲームオーバー表示
	} else if(event == 27) {
		netuIncrementTime(player);	// 各フレームの終わりの処理
	} else if(event == 38) {
		if(player == 0) PlayBGM();	// BGM再生
	} else if(event == 49) {
		netuHardDrop(player, param[1]);	// ハードドロップ
	} else if(event == 59) {
		netuTSpinZero(player);	// ライン消しなしのT-SPIN
	} else if(event == 68) {
		// stat[player] = 2のときの処理
		if(netuCustomStatNo[player] == 0) netuStatDisconnect(player);	// 切断
		if(netuCustomStatNo[player] == 1) netuStatWin(player);	// 勝利
		if(netuCustomStatNo[player] == 2) netuStatRetryScreen(player);	// リトライ
	}
}

// データ受信
void netuRecvData() {
	int size, result, id_from, command, temp;
	
	// 接続していないなら戻る
	if(!tcpIsConnect()) return;
	
	// 新しいデータが無いなら戻る
	if(!tcpIsReadReady()) return;
	
	// 最初の4バイトだけ調べる（キューから除去はしない）
	result = tcpRecvPeek(&netuBufIn, 4);
	if(result < 1) return;
	
	// 読み込むサイズを決める
	size = netuBufIn[0];
	if(size < 1) return;
	
	// データが全て来ているかどうか確認
	if(tcpReceiveLength() < size) return;
	
	// データを全て読み込み
	result = tcpRecv(&netuBufIn, size);
	if(result < 1) return;
	
	// 読み込んだデータに応じて処理をする
	id_from = netuBufIn[1];
	command = netuBufIn[2];
	
	// サーバーからのメッセージの場合
	if(id_from == 0) {
		// 情報取得
		if(command == 0) {
			netuServerVersion = netuBufIn[3];
			netuClientCount = netuBufIn[4];
			if(netuServerVersion >= 2) netuMaxClient = netuBufIn[7];
		}
		// 誰かが接続
		else if(command == 1) {
			netuClientCount = netuBufIn[4];
			netuCountUpdateFrame = 0;
		}
		// 誰かが切断
		else if(command == 2) {
			netuClientCount = netuBufIn[4];
			netuCountUpdateFrame = 0;
			
			// 相手が切断した
			if(netuBufIn[3] == netuEnemyID) {
				netuEnemyID = 0;
				netuEnemyDisconnect = 1;
			}
		}
		// 相手が見つかった
		else if(command == 3) {
			temp = netuBufIn[3];
			netuBufOut[0] = 3 * 4;		// サイズ
			netuBufOut[1] = temp;		// 送信先ID
			netuBufOut[2] = 0;			// コマンド（対戦要求）
			tcpSend(&netuBufOut, netuBufOut[0]);
		}
		// 相手が見つからない
		else if(command == 4) {
			netuEnemyNotFound = 180;
		}
		// プレイヤー数情報
		else if(command == 5) {
			netuSameModeClientCount[0] = netuBufIn[3];
			netuSameModeClientCount[1] = netuBufIn[4];
			netuSameModeClientCount[2] = netuBufIn[5];
		}
	}
	// 他のプレイヤーからのメッセージの場合
	else {
		// 対戦要求
		if(command == 0) {
			// 相手が決まっていないとき
			if(netuEnemyID == 0) {
				PlaySE(se_lvstop);
				netuEnemyID = id_from;			// 相手IDを決める
				netuBufOut[0] = 3 * 4;			// サイズ
				netuBufOut[1] = netuEnemyID;	// 送信先ID
				netuBufOut[2] = 1;				// コマンド（承諾）
				tcpSend(&netuBufOut, netuBufOut[0]);
			}
			// 相手がもう決まっているとき
			else {
				netuBufOut[0] = 3 * 4;			// サイズ
				netuBufOut[1] = id_from;		// 送信先ID
				netuBufOut[2] = 2;				// コマンド（拒否）
				tcpSend(&netuBufOut, netuBufOut[0]);
			}
		}
		// 対戦の承諾が来た
		else if(command == 1) {
			if(netuEnemyID == 0) {
				PlaySE(se_lvstop);
				netuEnemyID = id_from;			// 相手IDを決める
			}
		}
		// 対戦を拒否された
		else if(command == 2) {
			if(netuEnemyID == 0) {
				netuEnemyNotFound = 180;
			}
		}
		// ルール名を受信
		else if(command == 3) {
			if(id_from == netuEnemyID) {
				netuRecvEnemyRuleName();
			}
		}
		// ルール設定を受信
		else if(command == 4) {
			if(id_from == netuEnemyID) {
				netuRecvEnemyRuleConfig();
			}
		}
		// NEXTブロックを受信
		else if(command == 5) {
			if(id_from == netuEnemyID) {
				netuRecvEnemyNextList();
			}
		}
		// 相手の準備完了
		else if(command == 6) {
			if(id_from == netuEnemyID) {
				netuEnemyReady = 1;
			}
		}
		// 敵の移動
		else if(command == 7) {
			if(id_from == netuEnemyID) {
				netuRecvEnemyMove();
			}
		}
		// フィールド
		else if(command == 8) {
			if(id_from == netuEnemyID) {
				netuRecvField();
			}
		}
		// リトライ
		else if(command == 9) {
			if(id_from == netuEnemyID) {
				PlaySE(se_kettei);
				StopAllBGM();
				gameAllInit();
				playerInitial(0);
				playerInitial(1);
				if(netuPlayerType == 0) versusInit(0);
				stat[0] = 3;
				stat[1] = 3;
			}
		}
		// 相手のモード設定を受信
		else if(command == 10) {
			if(id_from == netuEnemyID) {
				netuRecvModeConfig();
			}
		}
		// 相手のプレイが終了
		else if(command == 11) {
			netuEnemyGameEndFlag = 1;
			netuScore[1] = netuBufIn[3];
			netuLines[1] = netuBufIn[4];
		}
		// 相手のプレイ結果
		else if(command == 12) {
			if(id_from == netuEnemyID) {
				netuScore[1] = netuBufIn[3];
				netuLines[1] = netuBufIn[4];
				gameTimer[1] = netuBufIn[5];
			}
		}
	}
}

// サーバーに自分のバージョン情報を送信
void netuSendVersionDataToServer() {
	int i, strbuf[8];
	
	// 基本情報
	netuBufOut[0] = 13 * 4;				// サイズ
	netuBufOut[1] = 0;					// 送信先ID
	netuBufOut[2] = 1;					// コマンド
	netuBufOut[3] = engineVer;			// ゲームエンジンのバージョン
	netuBufOut[4] = netuModeVersion;	// モードのバージョン
	
	// モード名
	for(i = 0; i < 8; i++) strbuf[i] = 0;
	StrCpy(&strbuf, plugin_name_mode[gameMode[0]]);
	for(i = 0; i < 8; i++) netuBufOut[5 + i] = strbuf[i];
	
	// 送信
	tcpSend(&netuBufOut, netuBufOut[0]);
}

// 自分のルール名を送信
void netuSendPlayerRuleName() {
	int i, strbuf[8];
	
	// 基本情報
	netuBufOut[0] = 11 * 4;			// サイズ
	netuBufOut[1] = netuEnemyID;	// 送信先ID
	netuBufOut[2] = 3;				// コマンド
	
	// ルール名
	for(i = 0; i < 8; i++) strbuf[i] = 0;
	StrCpy(&strbuf, plugin_name_rule[rots[0]]);
	for(i = 0; i < 8; i++) netuBufOut[3 + i] = strbuf[i];
	
	// 送信
	tcpSend(&netuBufOut, netuBufOut[0]);
}

// 相手のルール名を受信
void netuRecvEnemyRuleName() {
	int i, strbuf[8], temp;
	
	for(i = 0; i < 8; i++) strbuf[i] = netuBufIn[3 + i];
	StrCpy(string[1], &strbuf);
	temp = findRulePlugin(string[1]);
	if(temp != -1) {
		rots[1] = temp;
		netuEnemyRulePluginMissing = 0;
	} else {
		rots[1] = rots[0];
		netuEnemyRulePluginMissing = 1;
	}
	
	netuReceiveRuleNameOK = 1;
}

// 自分のルール設定をnetuRuleConfigPlayerにコピーする
void netuBackupPlayerRuleConfig() {
	int i;
	
	if(rotlimit[0] == 0) rotlimit[0] = 128;
	if(movelimit[0] == 0) movelimit[0] = 128;
	
	netuRuleConfigPlayer[0] = kicktype[0];
	netuRuleConfigPlayer[1] = lockreset[0];
	netuRuleConfigPlayer[2] = rotlimit[0];
	netuRuleConfigPlayer[3] = movelimit[0];
	netuRuleConfigPlayer[4] = blockgraphics[0];
	netuRuleConfigPlayer[5] = are[0];
	netuRuleConfigPlayer[6] = lock_up[0];
	netuRuleConfigPlayer[7] = lock_down[0];
	netuRuleConfigPlayer[8] = rot_reverse[0];
	netuRuleConfigPlayer[9] = softspeed[0];
	netuRuleConfigPlayer[10] = max_waitt[0];
	netuRuleConfigPlayer[11] = fastlrmove[0];
	netuRuleConfigPlayer[12] = oblk_bg[0];
	for(i = 0; i < 7; i++) netuRuleConfigPlayer[13 + i] = blockcolor[i];
	netuRuleConfigPlayer[20] = initial_rotate[0];
	netuRuleConfigPlayer[21] = initial_hold[0];
	netuRuleConfigPlayer[22] = enable_wallkick[0];
	netuRuleConfigPlayer[23] = self_lock_sound[0];
	netuRuleConfigPlayer[24] = lockflash[0];
	netuRuleConfigPlayer[25] = RepeatDelay[0];
}

// netuRuleConfigEnemyから相手のルール設定を反映させる
void netuApplyEnemyRuleConfig() {
	int i;
	
	kicktype[1] = netuRuleConfigEnemy[0];
	lockreset[1] = netuRuleConfigEnemy[1];
	rotlimit[1] = netuRuleConfigEnemy[2];
	movelimit[1] = netuRuleConfigEnemy[3];
	blockgraphics[1] = netuRuleConfigEnemy[4];
	are[1] = netuRuleConfigEnemy[5];
	lock_up[1] = netuRuleConfigEnemy[6];
	lock_down[1] = netuRuleConfigEnemy[7];
	rot_reverse[1] = netuRuleConfigEnemy[8];
	softspeed[1] = netuRuleConfigEnemy[9];
	max_waitt[1] = netuRuleConfigEnemy[10];
	fastlrmove[1] = netuRuleConfigEnemy[11];
	oblk_bg[1] = netuRuleConfigEnemy[12];
	for(i = 0; i < 7; i++) blockcolor[i + 7] = netuRuleConfigEnemy[13 + i];
	initial_rotate[1] = netuRuleConfigEnemy[20];
	initial_hold[1] = netuRuleConfigEnemy[21];
	enable_wallkick[1] = netuRuleConfigEnemy[22];
	self_lock_sound[1] = netuRuleConfigEnemy[23];
	lockflash[1] = netuRuleConfigEnemy[24];
	RepeatDelay[1] = netuRuleConfigEnemy[25];
}

// 自分のルール設定を送信
void netuSendPlayerRuleConfig() {
	int i, strbuf[16];
	
	// 基本情報
	netuBufOut[0] = 45 * 4;			// サイズ
	netuBufOut[1] = netuEnemyID;	// 送信先ID
	netuBufOut[2] = 4;				// コマンド
	
	// ルール設定
	netuBackupPlayerRuleConfig();
	for(i = 0; i < 26; i++) netuBufOut[3 + i] = netuRuleConfigPlayer[i];
	
	// ニックネーム
	for(i = 0; i < 16; i++) strbuf[i] = 0;
	if(networkUseNick) StrCpy(&strbuf, netuNickname[0]);
	for(i = 0; i < 16; i++) netuBufOut[29 + i] = strbuf[i];
	
	// 送信
	tcpSend(&netuBufOut, netuBufOut[0]);
}

// 相手のルール設定を受信
void netuRecvEnemyRuleConfig() {
	int i, strbuf[16];
	
	// ルール設定
	for(i = 0; i < 26; i++) netuRuleConfigEnemy[i] = netuBufIn[3 + i];
	
	// ニックネーム
	if(networkUseNick) {
		for(i = 0; i < 16; i++) strbuf[i] = netuBufIn[29 + i];
		StrCpy(netuNickname[1], &strbuf);
		
		netuViewNickname(0);
		netuViewNickname(1);
	}
	
	netuReceiveRuleConfigOK = 1;
}

// 自分のNEXTブロックを送信
void netuSendPlayerNextList() {
	int i, j, temp;
	
	// 基本情報
	netuBufOut[0] = 179 * 4;		// サイズ
	netuBufOut[1] = netuEnemyID;	// 送信先ID
	netuBufOut[2] = 5;				// コマンド
	netuBufOut[3] = nextc_max[0];	// NEXT最大数
	
	// NEXTブロック
	for(i = 0; i < 175; i++) {
		temp = 0;
		for(j = 0; j < 8; j++) {
			temp = temp | (nextb[(i << 3) + j] << (j * 4));
		}
		netuBufOut[i + 4] = temp;
	}
	
	// 送信
	tcpSend(&netuBufOut, netuBufOut[0]);
}

// 相手のNEXTブロックを受信
void netuRecvEnemyNextList() {
	int i, j, temp;
	
	nextc_max[0] = netuBufIn[3];	// NEXT最大数
	if(nextc_max[0] == 0) nextc_max[0] = 1400;
	
	for(i = 0; i < 175; i++) {
		for(j = 0; j < 8; j++) {
			nextb[(i << 3) + j] = ((netuBufIn[i + 4]) >> (j * 4)) & 15;
		}
	}
	netuCopyNextList();
	
	netuReceiveNextListOK = 1;
}

// 1PのNEXTを2Pにコピー
void netuCopyNextList() {
	int i;
	for(i = 0; i < 1400; i++) nextb[i + 1400] = nextb[i];
	nextc[1] = nextc[0];
	nextc_max[1] = nextc_max[0];
}

// 自分のモード設定を送信
void netuSendModeConfig() {
	netuBufOut[0] = 22 * 4;				// サイズ
	netuBufOut[1] = netuEnemyID;		// 送信先ID
	netuBufOut[2] = 10;					// コマンド
	netuBufOut[3] = netuGhost;			// ゴーストの有無
	netuBufOut[4] = netuTSpin;			// T-SPINの種類
	netuBufOut[5] = netuEnableCombo;	// コンボボーナスの有無
	netuBufOut[6] = netuEnableB2B;		// Back To Backの有無
	netuBufOut[7] = netuSpeed;			// 落下速度
	netuBufOut[8] = netuSpeedType;		// スピードタイプ
	netuBufOut[9] = netuWait1;			// ARE
	netuBufOut[10] = netuWait2;			// ライン消去
	netuBufOut[11] = netuWait3;			// 固定時間
	netuBufOut[12] = netuWaitt;			// 横溜め
	netuBufOut[13] = netuWait4;			// 固定時間（接着後）
	netuBufOut[14] = netuWait5;			// ARE（消去後）
	netuBufOut[15] = netuGameType;		// ゲームの種類
	netuBufOut[16] = netuAreUse;		// ARE Force
	netuBufOut[17] = netuFastlrmove;	// INIT LR Force
	netuBufOut[18] = netuRepeatDelay;	// Repeat Delay
	netuBufOut[19] = netuMaxDAS;		// Disable Max DAS
	netuBufOut[20] = netuSpawnType;		// SPAWN Y TYPE Force
	netuBufOut[21] = netuHoldEnable;	// Enable Hold
	
	tcpSend(&netuBufOut, netuBufOut[0]);
}

// 相手のモード設定を受信
void netuRecvModeConfig() {
	netuGhost = netuBufIn[3];
	netuTSpin = netuBufIn[4];
	netuEnableCombo = netuBufIn[5];
	netuEnableB2B = netuBufIn[6];
	netuSpeed = netuBufIn[7];
	netuSpeedType = netuBufIn[8];
	netuWait1 = netuBufIn[9];
	netuWait2 = netuBufIn[10];
	netuWait3 = netuBufIn[11];
	netuWaitt = netuBufIn[12];
	netuWait4 = netuBufIn[13];
	netuWait5 = netuBufIn[14];
	netuGameType = netuBufIn[15];
	netuAreUse = netuBufIn[16];
	netuFastlrmove = netuBufIn[17];
	netuRepeatDelay = netuBufIn[18];
	netuMaxDAS = netuBufIn[19];
	netuSpawnType = netuBufIn[20];
	netuHoldEnable = netuBufIn[21];
	
	netuReceiveModeConfigOK = 1;
}

// 各種設定を反映させる
void netuApplyModeConfig(int player) {
	ghost[player] = netuGhost;
	tspin_type[player] = netuTSpin;
	enable_combo[player] = netuEnableCombo;
	b_to_b_type[player] = netuEnableB2B;
	sp[player] = netuSpeed;
	speedtype[player] = netuSpeedType;
	wait1[player] = netuWait1;
	wait2[player] = netuWait2;
	wait3[player] = netuWait3;
	waitt[player] = netuWaitt;
	wait4[player] = netuWait4;
	wait5[player] = netuWait5;
	netuLimitTime = 7200 + netuGameType * 3600;
	
	if(netuAreUse > -1) are[player] = netuAreUse;
	if(netuFastlrmove > -1) fastlrmove[player] = netuFastlrmove;
	if(netuRepeatDelay > -1) RepeatDelay[player] = netuRepeatDelay;
	if(netuMaxDAS > -1) max_waitt[player] = 99;
	if(netuSpawnType > -1) spawntype[player] = netuSpawnType;
	if(netuHoldEnable > -1) {
		if(netuHoldEnable == 0) dhold[player] = 2;
		else dhold[player] = 0;
	}
}

// 設定画面
void netuSetting(int player, int *param) {
	int page;
	
	// BGMは最初に読み込んでおく
	netuLoadBGM();
	
	// 変数の初期化
	page = 0;
	
	// ゲーム側の変数を設定
	netplay = 1;
	maxPlay = 1;
	SetFPS(60);
	SetConstParam("EnablePause", 0);
	
	// 通信の初期化
	tcpStartup();
	
	// メインループ
	loop {
		if(page < 0) {
			tcpCleanup();
			netplay = 0;
			SetConstParam("EnablePause", 1);
			param[0] = 0;
			return;
		}
		else if(page == 0) page = netuMenuServerSelect();
		else if(page == 1) page = netuMenuServerConnect();
		else if(page == 2) page = netuMenuSelectPlayType();
		else if(page == 3) page = netuMenuGameOptions();
		else return;
	}
}

// サーバー選択画面
int netuMenuServerSelect() {
	int i, move;
	
	// 変数の初期化
	netuPlayerType = 0;
	netuGameStart = 0;
	netuTraining = 0;
	netuReceiveRuleNameOK = 0;
	netuEnemyID = 0;
	netuEnemyNotFound = 0;
	netuEnemyDisconnect = 0;
	netuEnemyRulePluginMissing = 0;
	netuServerVersion = -1;
	netuClientCount = -1;
	netuMaxClient = -1;
	netuSameModeClientCount[0] = -1;
	netuSameModeClientCount[1] = -1;
	netuSameModeClientCount[2] = -1;
	netuCountUpdateFrame = 0;
	netuRound = 0;
	netuWin[0] = 0;
	netuWin[1] = 0;
	
	// ソケット作成
	tcpSocket();
	
	// メインループ
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "SELECT A SERVER", 4);
		printFontGrid(1, 27, "A:OK B:BACK", 6);
		
		// 鯖一覧表示
		for(i = 0; i < 10; i++) {
			sprintf(string[0], "%s:%d", networkServerName[i], networkServerPort[i]);
			printSMALLFont(8, 24 + i * 9, string[0], 7 * (netuServerNo == i));
		}
		
		// カーソル移動
		padRepeat2(0);
		
		move = 0;
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
			move = getPressState(0, 1) - getPressState(0, 0);
		
		if(move) {
			PlaySE(se_move);
			netuServerNo = netuServerNo + move;
			if(netuServerNo < 0) netuServerNo = 9;
			if(netuServerNo > 9) netuServerNo = 0;
		}
		
		// キャンセル
		if(getPushState(0, 5)) {
			PlaySE(se_move);
			return -1;
		}
		
		// 決定
		if(getPushState(0, 4)) {
			PlayWave(se_kettei);
			return 1;
		}
	}
}

// サーバー接続画面
int netuMenuServerConnect() {
	int cursor;
	cursor = 0;
	
	// 接続
	tcpConnect(networkServerName[netuServerNo], networkServerPort[netuServerNo]);
	
	// メインループ
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		// 失敗
		if(tcpIsErrorEvent()) {
			printFontGrid(1, 1, "CONNECT FAILED", 2);
			sprintf(string[0], "ERROR CODE:%d", tcpWSAGetLastError());
			printFontGrid(1, 3, string[0], 0);
			
			printFontGrid(1, 27, "A:RETRY B:BACK", 6);
			
			// キャンセル
			if(getPushState(0, 5)) {
				PlaySE(se_move);
				tcpClosesocket();
				return 0;
			}
			
			// リトライ
			if(getPushState(0, 4)) {
				PlayWave(se_kettei);
				tcpConnect(networkServerName[netuServerNo], networkServerPort[netuServerNo]);
			}
		}
		// 成功
		else if(tcpIsConnect()) {
			// バージョン情報を送信
			netuSendVersionDataToServer();
			
			// 鯖情報を要求する
			netuBufOut[0] = 3 * 4;		// サイズ
			netuBufOut[1] = 0;			// 送信先ID
			netuBufOut[2] = 0;			// コマンド
			tcpSend(&netuBufOut, netuBufOut[0]);
			
			return 2;
		}
		// 接続中
		else {
			printFontGrid(1, 1, "CONNECTING TO SERVER...", 4);
			printFontGrid(1, 27, "B:BACK", 6);
			
			// キャンセル
			if(getPushState(0, 5)) {
				PlaySE(se_move);
				tcpClosesocket();
				return 0;
			}
		}
	}
}

// プレイ方法選択画面
int netuMenuSelectPlayType() {
	int i, move;
	
	// メインループ
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "SELECT PLAY TYPE", 4);
		printFontGrid(1, 27, "A:OK B:BACK", 6);
		
		// カーソル表示
		printFontGrid(1, 3 + netuPlayerType, "b", 7);
		
		// メニュー表示
		printFontGrid(2, 3, "PLAY AS HOST",  7 * (netuPlayerType == 0));
		printFontGrid(2, 4, "PLAY AS GUEST", 7 * (netuPlayerType == 1));
		
		// 鯖情報
		if(netuServerVersion != -1) {
			sprintf(string[0], "SERVER VERSION:%d", netuServerVersion);
			printFontGrid(1, 22, string[0], 6);
		}
		if((netuMaxClient > 0) && (netuServerVersion >= 2)) {
			sprintf(string[0], "MAX PLAYER:%d", netuMaxClient);
			printFontGrid(1, 23, string[0], 6);
		}
		if(netuClientCount != -1) {
			sprintf(string[0], "ALL OTHER PLAYERS IN SERVER:%d", netuClientCount - 1);
			printFontGrid(1, 24, string[0], 6);
		}
		if((netuSameModeClientCount[0] != -1) && (netuServerVersion >= 2)) {
			sprintf(string[0], "SAME MODE PLAYERS:%d/%d/%d", netuSameModeClientCount[0], netuSameModeClientCount[1], netuSameModeClientCount[2]);
			printFontGrid(1, 25, string[0], 6);
		}
		
		// カーソル移動
		padRepeat2(0);
		
		move = 0;
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
			move = getPressState(0, 1) - getPressState(0, 0);
		
		if(move) {
			PlaySE(se_move);
			netuPlayerType = netuPlayerType + move;
			if(netuPlayerType < 0) netuPlayerType = 1;
			if(netuPlayerType > 1) netuPlayerType = 0;
		}
		
		// キャンセル
		if(getPushState(0, 5)) {
			PlaySE(se_move);
			tcpClosesocket();
			return 0;
		}
		
		// 決定
		if(getPushState(0, 4)) {
			PlayWave(se_kettei);
			
			if(!netuPlayerType) {
				// ホスト
				return 3;
			} else {
				// ゲストなので相手を探す
				netuBufOut[0] = 3 * 4;		// サイズ
				netuBufOut[1] = 0;			// 送信先ID
				netuBufOut[2] = 3;			// コマンド
				tcpSend(&netuBufOut, netuBufOut[0]);
				return 4;
			}
		}
		
		// プレイヤー数取得
		if(netuServerVersion >= 2) {
			if(netuCountUpdateFrame <= 0) {
				netuCountUpdateFrame = 180;
				netuBufOut[0] = 3 * 4;		// サイズ
				netuBufOut[1] = 0;			// 送信先ID
				netuBufOut[2] = 4;			// コマンド
				tcpSend(&netuBufOut, netuBufOut[0]);
			} else {
				netuCountUpdateFrame--;
			}
		}
	}
}

// ゲーム設定
int netuMenuGameOptions() {
	int cursor, move;
	cursor = 0;
	
	if(netuLoadConfig() == 0) {
		netuMakeDefaultPreset();
	}
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		printFontGrid(1, 1, "GAME OPTIONS", 4);
		printFontGrid(1, 27, "A:OK B:BACK", 6);
		
		// カーソル
		printFontGrid(1, 3 + cursor, "b", 7);
		
		// 設定項目一覧
		printFontGrid(2, 3, "GHOST BLOCK",  (cursor == 0) * 7);
		printFontGrid(2, 4, "T-SPIN",       (cursor == 1) * 7);
		printFontGrid(2, 5, "COMBO",        (cursor == 2) * 7);
		printFontGrid(2, 6, "BACK TO BACK", (cursor == 3) * 7);
		printFontGrid(2, 7, "SPEED",        (cursor == 4) * 7);
		printFontGrid(2, 8, "SPEED TYPE",   (cursor == 5) * 7);
		if(!english) printFontGrid(2, 9, "SYUTUGEN", (cursor == 6) * 7);
		else printFontGrid(2, 9, "ARE", (cursor == 6) * 7);
		if(!english) printFontGrid(2, 10, "SYOUKYO", (cursor == 7) * 7);
		else printFontGrid(2, 10, "LINE DELAY", (cursor == 7) * 7);
		if(!english) printFontGrid(2, 11, "SETTYAKU", (cursor == 8) * 7);
		else printFontGrid(2, 11, "LOCK DELAY", (cursor == 8) * 7);
		if(!english) printFontGrid(2, 12, "YOKOTAME", (cursor == 9) * 7);
		else printFontGrid(2, 12, "DAS", (cursor == 9) * 7);
		if(!english) printFontGrid(2, 13, "SETTYAKU2", (cursor == 10) * 7);
		else printFontGrid(2, 13, "LOCK DELAY2", (cursor == 10) * 7);
		if(!english) printFontGrid(2, 14, "SYUTUGEN2", (cursor == 11) * 7);
		else printFontGrid(2, 14, "ARE2", (cursor == 11) * 7);
		printFontGrid(2, 15, "FORCE ARE", (cursor == 12) * 7);
		printFontGrid(2, 16, "FORCE INIT LR MOVE", (cursor == 13) * 7);
		printFontGrid(2, 17, "FORCE REPEAT DELAY", (cursor == 14) * 7);
		if(!english) printFontGrid(2, 18, "FORCE MAX YOKOTAME", (cursor == 15) * 7);
		else printFontGrid(2, 18, "FORCE MAX DAS", (cursor == 15) * 7);
		printFontGrid(2, 19, "FORCE SPAWN Y TYPE", (cursor == 16) * 7);
		printFontGrid(2, 20, "FORCE HOLD", (cursor == 17) * 7);
		printFontGrid(2, 21, "GAME TYPE", (cursor == 18) * 7);
		printFontGrid(2, 22, "[SAVE PRESET]", (cursor == 19) * 7);
		printFontGrid(2, 23, "[LOAD PRESET]", (cursor == 20) * 7);
		
		// 設定値表示
		if(!netuGhost) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 3, string[0], (cursor == 0) * 7);
		
		if(netuTSpin == 0) sprintf(string[0], "OFF");
		else if(netuTSpin == 1) sprintf(string[0], "LINE CLEAR");
		else if(netuTSpin == 2) sprintf(string[0], "IMMOBILE");
		else if(netuTSpin == 3) sprintf(string[0], "3-CORNER");
		else sprintf(string[0], "3-CORNER NO KICK");
		printFontGrid(22, 4, string[0], (cursor == 1) * 7);
		
		if(!netuEnableCombo) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 5, string[0], (cursor == 2) * 7);
		
		if(netuEnableB2B == 0) sprintf(string[0], "OFF");
		else if(netuEnableB2B == 1) sprintf(string[0], "ON");
		else if(netuEnableB2B == 2) sprintf(string[0], "HEBORIS ONLY");
		else sprintf(string[0], "T-SPIN ONLY");
		printFontGrid(22, 6, string[0], (cursor == 3) * 7);
		
		sprintf(string[0], "%d", netuSpeed);
		printFontGrid(22, 7, string[0], (cursor == 4) * 7);
		
		if(netuSpeedType == 0) sprintf(string[0], "1/60");
		else if(netuSpeedType == 1) sprintf(string[0], "FRAMES PER ROW");
		else sprintf(string[0], "1/256");
		printFontGrid(22, 8, string[0], (cursor == 5) * 7);
		
		sprintf(string[0], "%d", netuWait1);
		printFontGrid(22, 9, string[0], (cursor == 6) * 7);
		
		sprintf(string[0], "%d", netuWait2);
		printFontGrid(22, 10, string[0], (cursor == 7) * 7);
		
		sprintf(string[0], "%d", netuWait3);
		printFontGrid(22, 11, string[0], (cursor == 8) * 7);
		
		sprintf(string[0], "%d", netuWaitt);
		printFontGrid(22, 12, string[0], (cursor == 9) * 7);
		
		if(netuWait4 == -1) sprintf(string[0], "NO USE");
		else sprintf(string[0], "%d", netuWait4);
		printFontGrid(22, 13, string[0], (cursor == 10) * 7);
		
		if(netuWait5 == -1) sprintf(string[0], "NO USE");
		else sprintf(string[0], "%d", netuWait5);
		printFontGrid(22, 14, string[0], (cursor == 11) * 7);
		
		if(netuAreUse == -1) sprintf(string[0], "PLAYER CHOICE");
		else if(netuAreUse == 0) sprintf(string[0], "OFF");
		else if(netuAreUse == 1) sprintf(string[0], "ON");
		else sprintf(string[0], "ON (WITH SKIP)");
		printFontGrid(22, 15, string[0], (cursor == 12) * 7);
		
		if(netuFastlrmove == -1) sprintf(string[0], "PLAYER CHOICE");
		else if(netuFastlrmove == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 16, string[0], (cursor == 13) * 7);
		
		if(netuRepeatDelay == -1) sprintf(string[0], "PLAYER CHOICE");
		else if(netuRepeatDelay == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "%d", netuRepeatDelay);
		printFontGrid(22, 17, string[0], (cursor == 14) * 7);
		
		if(netuMaxDAS == -1) sprintf(string[0], "PLAYER CHOICE");
		else sprintf(string[0], "FORCE DISABLE");
		printFontGrid(22, 18, string[0], (cursor == 15) * 7);
		
		if(netuSpawnType == -1) sprintf(string[0], "PLAYER CHOICE");
		else if(netuSpawnType == 0) sprintf(string[0], "UNDER THE FRAME");
		else sprintf(string[0], "ABOVE THE FRAME");
		printFontGrid(22, 19, string[0], (cursor == 16) * 7);
		
		if(netuHoldEnable == -1) sprintf(string[0], "PLAYER CHOICE");
		else if(netuHoldEnable == 0) sprintf(string[0], "OFF");
		else sprintf(string[0], "ON");
		printFontGrid(22, 20, string[0], (cursor == 17) * 7);
		
		if(!netuGameType) sprintf(string[0], "2MIN LINE MATCH");
		else sprintf(string[0], "3MIN SCORE MATCH");
		printFontGrid(22, 21, string[0], (cursor == 18) * 7);
		
		sprintf(string[0], "PRESET NO.%d", netuLastPresetNo + 1);
		printFontGrid(22, 22, string[0], (cursor >= 19) * 7);
		
		// カーソル移動
		padRepeat2(0);
		
		move = 0;
		if( (mpc2[0] == 1) || ((mpc2[0] > tame3) && (mpc2[0] % tame4 == 0)) )
			move = getPressState(0, 1) - getPressState(0, 0);
		
		if(move) {
			PlaySE(se_move);
			cursor = cursor + move;
			if(cursor < 0) cursor = 20;
			if(cursor > 20) cursor = 0;
		}
		
		// 値を変更
		padRepeat(0);
		
		move = 0;
		if((mpc[0] == 1) || ((mpc[0] > tame1) && (mpc[0] % tame2 == 0)) || getPressState(0, 6))
			move = getPressState(0, 3) - getPressState(0, 2);
		
		if(move) {
			PlaySE(se_kachi);
			
			if(cursor == 0) netuGhost = !netuGhost;
			if(cursor == 1) {
				netuTSpin = netuTSpin + move;
				if(netuTSpin < 0) netuTSpin = 4;
				if(netuTSpin > 4) netuTSpin = 0;
			}
			if(cursor == 2) netuEnableCombo = !netuEnableCombo;
			if(cursor == 3) {
				netuEnableB2B = netuEnableB2B + move;
				if(netuEnableB2B < 0) netuEnableB2B = 3;
				if(netuEnableB2B > 3) netuEnableB2B = 0;
			}
			if(cursor == 4) {
				netuSpeed = netuSpeed + move;
				if(netuSpeed < 1) netuSpeed = 5120;
				if(netuSpeed > 5120) netuSpeed = 1;
			}
			if(cursor == 5) {
				netuSpeedType = netuSpeedType + move;
				if(netuSpeedType < 0) netuSpeedType = 2;
				if(netuSpeedType > 2) netuSpeedType = 0;
			}
			if(cursor == 6) {
				netuWait1 = netuWait1 + move;
				if(netuWait1 < 0) netuWait1 = 99;
				if(netuWait1 > 99) netuWait1 = 0;
			}
			if(cursor == 7) {
				netuWait2 = netuWait2 + move;
				if(netuWait2 < 0) netuWait2 = 99;
				if(netuWait2 > 99) netuWait2 = 0;
			}
			if(cursor == 8) {
				netuWait3 = netuWait3 + move;
				if(netuWait3 < 0) netuWait3 = 98;
				if(netuWait3 > 98) netuWait3 = 0;
			}
			if(cursor == 9) {
				netuWaitt = netuWaitt + move;
				if(netuWaitt < 0) netuWaitt = 99;
				if(netuWaitt > 99) netuWaitt = 0;
			}
			if(cursor == 10) {
				netuWait4 = netuWait4 + move;
				if(netuWait4 < -1) netuWait4 = 98;
				if(netuWait4 > 98) netuWait4 = -1;
			}
			if(cursor == 11) {
				netuWait5 = netuWait5 + move;
				if(netuWait5 < -1) netuWait5 = 99;
				if(netuWait5 > 99) netuWait5 = -1;
			}
			if(cursor == 12) {
				netuAreUse = netuAreUse + move;
				if(netuAreUse < -1) netuAreUse = 2;
				if(netuAreUse > 2) netuAreUse = -1;
			}
			if(cursor == 13) {
				netuFastlrmove = netuFastlrmove + move;
				if(netuFastlrmove < -1) netuFastlrmove = 1;
				if(netuFastlrmove > 1) netuFastlrmove = -1;
			}
			if(cursor == 14) {
				netuRepeatDelay = netuRepeatDelay + move;
				if(netuRepeatDelay < -1) netuRepeatDelay = 99;
				if(netuRepeatDelay > 99) netuRepeatDelay = -1;
			}
			if(cursor == 15) {
				netuMaxDAS = netuMaxDAS + move;
				if(netuMaxDAS < -1) netuMaxDAS = 0;
				if(netuMaxDAS > 0) netuMaxDAS = -1;
			}
			if(cursor == 16) {
				netuSpawnType = netuSpawnType + move;
				if(netuSpawnType < -1) netuSpawnType = 1;
				if(netuSpawnType > 1) netuSpawnType = -1;
			}
			if(cursor == 17) {
				netuHoldEnable = netuHoldEnable + move;
				if(netuHoldEnable < -1) netuHoldEnable = 1;
				if(netuHoldEnable > 1) netuHoldEnable = -1;
			}
			if(cursor == 18) netuGameType = !netuGameType;
			if(cursor >= 19) {
				netuLastPresetNo = netuLastPresetNo + move;
				if(netuLastPresetNo < 0) netuLastPresetNo = 9;
				if(netuLastPresetNo > 9) netuLastPresetNo = 0;
			}
		}
		
		// 決定
		if(getPushState(0, 4)) {
			PlaySE(se_kettei);
			
			if(cursor == 19) {
				netuSavePreset(netuLastPresetNo);
				netuSaveConfig();
			} else if(cursor == 20) {
				netuLoadPreset(netuLastPresetNo);
			} else {
				netuSaveConfig();
				
				// 相手待ち状態になる
				netuBufOut[0] = 4 * 4;		// サイズ
				netuBufOut[1] = 0;			// 送信先ID
				netuBufOut[2] = 2;			// コマンド
				netuBufOut[3] = 1;			// 状態
				tcpSend(&netuBufOut, netuBufOut[0]);
				
				return 4;
			}
		}
		
		// キャンセル
		if(getPushState(0, 5)) {
			PlaySE(se_move);
			return 2;
		}
	}
}

// 初期化処理
void netuPlayerInitial(int player) {
	backno = 20;								// 背景変更
	setFieldPosition(player, 2);				// フィールド位置設定
	blkshadow_direction[player] = 1 - player;	// ブロックの影
	hnext[player] = 0;							// NEXTは開始まで見せない
	bgmlv = 10;									// BGM番号設定
	
	netuScore[player] = 0;
	netuLines[player] = 0;
	
	netuTSpinFrame[player] = 0;
	netuTSpinLine[player] = 0;
	netuComboFrame[player] = 0;
	netuB2BFrame[player] = 0;
	netuTSpinWall[player] = 0;
	netuScoreGet[player] = 0;
	netuScoreFrame[player] = 0;
	
	netuLastBlk[player] = 0;
	netuLastBx[player] = 0;
	netuLastBy[player] = 0;
	netuLastRt[player] = 0;
	netuLastNDelay[player] = 0;
	
	netuCustomStatNo[player] = 0;
	
	netuGameStart = 0;
	netuTraining = 0;
	netuEnemyReady = 0;
	netuEnemyBlockVisible = 0;
	netuEnemyGameEndFlag = 0;
	netuReceiveRuleConfigOK = 0;
	netuReceiveNextListOK = 0;
	netuReceiveModeConfigOK = 0;
}

// Ready画面
void netuReady(int player, int *param) {
	// 相手待ち時のプレイヤー数表示
	if((netuEnemyID == 0) && (player == 1)) {
		param[0] = 1;
		
		sprintf(string[0], "ALL:%d", netuClientCount - 1);
		printFont(foffset[player] + 16, fyoffset[player] + 108, string[0], 6);
		sprintf(string[0], "SAME MODE\n%d/%d/%d", netuSameModeClientCount[0], netuSameModeClientCount[1], netuSameModeClientCount[2]);
		printFont(foffset[player] + 16, fyoffset[player] + 124, string[0], 6);
	}
	// 相手待ち時のメニュー
	else if((netuEnemyID == 0) && (player == 0) && (!netuTraining)) {
		param[0] = 1;
		
		printFont(foffset[player] + 8, fyoffset[player] + 108 + statc[player * 10 + 2] * 16, "b", (count % 4 / 2) * 7);
		
		printFont(foffset[player] + 16, fyoffset[player] + 108, "TRAINING", (statc[player * 10 + 2] == 0) * (count % 4 / 2) * 7);
		printFont(foffset[player] + 16, fyoffset[player] + 124, "EXIT", (statc[player * 10 + 2] == 1) * (count % 4 / 2) * 7);
		
		// 上下
		if(getPushState(player, 0) || getPushState(player, 1)) {
			PlaySE(se_move);
			statc[player * 10 + 2] = !statc[player * 10 + 2];
		}
		
		// 決定
		if(getPushState(player, 4)) {
			// TRAINING
			if(statc[player * 10 + 2] == 0) {
				PlaySE(se_kettei);
				netuTraining = 1;
				hnext[player] = dispnext;
				netuApplyModeConfig(0);
			}
			// EXIT
			else {
				tcpClosesocket();
				flag = 1;
			}
		}
	}
	// 相手決定後、ゲーム開始前
	else if((!netuGameStart) && (!netuTraining)) {
		param[0] = 1;
		
		if(player == 0) {
			// 自分のルール名送信
			if(statc[player * 10 + 1] == 0) {
				netuSendPlayerRuleName();
				
				// 自分の状態を変更
				netuBufOut[0] = 4 * 4;		// サイズ
				netuBufOut[1] = 0;			// 送信先ID
				netuBufOut[2] = 2;			// コマンド
				netuBufOut[3] = 2;			// 状態
				tcpSend(&netuBufOut, netuBufOut[0]);
				
				statc[player * 10 + 1] = 1;
			}
			// 相手のルール名受信
			else if(statc[player * 10 + 1] == 1) {
				if(netuReceiveRuleNameOK) {
					playerInitial(1);			// 相手を初期化
					stat[1] = 3;
					statc[player * 10 + 1] = 2;
				}
			}
			// 自分のルール設定送信
			else if(statc[player * 10 + 1] == 2) {
				netuSendPlayerRuleConfig();	// 自分のルール設定を送信する
				statc[player * 10 + 1] = 3;
			}
			// 自分がホストならNEXTブロックを送信する
			else if(statc[player * 10 + 1] == 3) {
				if(!netuPlayerType) {
					netuCopyNextList();			// 自分のNEXTを相手にコピー
					netuSendPlayerNextList();	// NEXTブロックを送信する
					netuReceiveNextListOK = 1;	// NEXTブロックは受け取った扱いにする
				}
				statc[player * 10 + 1] = 4;
			}
			// 自分がホストならモード設定を送信する
			else if(statc[player * 10 + 1] == 4) {
				if(!netuPlayerType) {
					netuSendModeConfig();			// モード設定を送信する
					netuReceiveModeConfigOK = 1;	// モード設定は受け取った扱いにする
				}
				statc[player * 10 + 1] = 5;
			}
			// ルール設定とNEXTブロックとモード設定を受け取ったら準備完了
			else if(statc[player * 10 + 1] == 5) {
				if((netuReceiveRuleConfigOK) && (netuReceiveNextListOK) && (netuReceiveModeConfigOK)) {
					netuApplyEnemyRuleConfig();		// 敵のルールを適用
					netuApplyModeConfig(0);			// モード設定を適用
					netuApplyModeConfig(1);
					
					netuBufOut[0] = 3 * 4;			// サイズ
					netuBufOut[1] = netuEnemyID;	// 送信先ID
					netuBufOut[2] = 6;				// コマンド
					tcpSend(&netuBufOut, netuBufOut[0]);
					
					statc[player * 10 + 1] = 6;
				}
			}
			// 相手の準備が完了したら始める
			else if(statc[player * 10 + 1] == 6) {
				if(netuEnemyReady) {
					netuGameStart = 1;
					resetStatc(0);
					resetStatc(1);
					setNextBlockColor(0, 1);
					setNextBlockColor(1, 1);
					hnext[0] = dispnext;
					hnext[1] = dispnext;
					netuRound++;
				}
			}
		}
	}
}

// ブロック移動処理
void netuStatMove(int player, int *param) {
	int bottom;
	
	if(player == 1) {
		// 敵
		param[0] = 1;
		
		if((!netuEnemyRulePluginMissing) && (netuEnemyBlockVisible)) {
			// ゴースト
			if(ghost[1]) {
				for(bottom = by[1]; judgeBlock(1, bx[1], bottom, blk[1], rt[1]) == 0; bottom++);
				bottom--;
				drawGBlock(1, bottom);
			}
			
			// ブロック
			drawCBlock(1, 0, 0);
		}
	}
}

// 各フレームの終わりの処理
void netuIncrementTime(int player) {
	int temp, temp2;
	
	if(player == 0) {
		// 自分の移動を報告
		if((stat[0] == 4) && (bactivetime[player] != 0)) {
			if((blk[0] != netuLastBlk[0]) || (bx[0] != netuLastBx[0]) || (by[0] != netuLastBy[0]) || (rt[0] != netuLastRt[0]) || 
			   (ndelay[0] != netuLastNDelay[0]))
			{
				netuLastBlk[0] = blk[0];
				netuLastBx[0] = bx[0];
				netuLastBy[0] = by[0];
				netuLastRt[0] = rt[0];
				netuLastNDelay[0] = ndelay[0];
				netuSendPlayerMove();
			}
		}
		
		if(onRecord[0]) {
			if(netuEnemyDisconnect) {
				// 切断
				stat[0] = 2;
				stat[1] = 2;
				netuCustomStatNo[0] = 0;
				netuCustomStatNo[1] = 0;
				resetStatc(0);
				resetStatc(1);
				onRecord[0] = 0;
				onRecord[1] = 0;
				timeOn[0] = 0;
				timeOn[1] = 0;
				pinch[0] = 0;
				pinch[1] = 0;
				StopAllBGM();
				tcpClosesocket();
			} else {
				// 制限時間減少
				if((netuLimitTime > 0) && (timeOn[0])) {
					netuLimitTime--;
					
					if(netuLimitTime == 10 * 60) {
						// 残り10秒
						PlaySE(se_hurryup);
					} else if(netuLimitTime <= 0) {
						// 時間切れ
						PlaySE(se_timeover);
						gameTimer[0]++;
						
						if(!netuTraining) {
							stat[0] = 1;
							timeOn[0] = 0;
							
							// 相手に報告
							netuBufOut[0] = 5 * 4;			// サイズ
							netuBufOut[1] = netuEnemyID;	// 送信先ID
							netuBufOut[2] = 11;				// コマンド
							netuBufOut[3] = netuScore[0];
							netuBufOut[4] = netuLines[0];
							tcpSend(&netuBufOut, netuBufOut[0]);
						} else {
							StopAllBGM();
							stat[0] = 7;
							resetStatc(0);
							timeOn[0] = 0;
							onRecord[0] = 0;
						}
					}
				}
				
				// 決着
				if((netuLimitTime <= 0) && (netuEnemyGameEndFlag)) {
					if(!netuGameType) {
						temp = netuLines[0];
						temp2 = netuLines[1];
					} else {
						temp = netuScore[0];
						temp2 = netuScore[1];
					}
					
					if(temp < temp2) {
						stat[0] = 7;
						resetStatc(0);
					} else if(temp == temp2) {
						stat[0] = 7;
						stat[1] = 7;
						resetStatc(0);
						resetStatc(1);
					}
					
					onRecord[0] = 0;
					onRecord[1] = 0;
				}
			}
		}
		
		// 相手がいないとき
		if((netuEnemyID == 0) && (!netuEnemyDisconnect)) {
			// 自分がゲストのときは相手を探す
			if((netuEnemyNotFound != 0) && (netuPlayerType == 1)) {
				netuEnemyNotFound--;
				
				if(netuEnemyNotFound <= 0) {
					netuBufOut[0] = 3 * 4;		// サイズ
					netuBufOut[1] = 0;			// 送信先ID
					netuBufOut[2] = 3;			// コマンド
					tcpSend(&netuBufOut, netuBufOut[0]);
				}
			}
			
			// プレイヤー数取得
			if(netuServerVersion >= 2) {
				if(netuCountUpdateFrame <= 0) {
					netuCountUpdateFrame = 180;
					netuBufOut[0] = 3 * 4;		// サイズ
					netuBufOut[1] = 0;			// 送信先ID
					netuBufOut[2] = 4;			// コマンド
					tcpSend(&netuBufOut, netuBufOut[0]);
				} else {
					netuCountUpdateFrame--;
				}
			}
		}
		
		// トレーニング中に相手出現
		if((netuTraining) && (netuEnemyID != 0)) {
			StopAllBGM();
			gameAllInit();
			playerInitial(0);
			playerInitial(1);
			if(netuPlayerType == 0) versusInit(0);
			stat[0] = 3;
			stat[1] = 3;
		}
		
		// ポーズボタンでトレーニング終了
		if((netuTraining) && (onRecord[0])) {
			if(IsPushKey(pause_key[0]) | getJoyPushState(0, joy_pause_key[0])) {
				StopAllBGM();
				stat[0] = 7;
				resetStatc(0);
			}
		}
	}
}

// 自分の移動を報告
void netuSendPlayerMove() {
	if(netuTraining) return;
	
	netuBufOut[0] = 12 * 4;			// サイズ
	netuBufOut[1] = netuEnemyID;	// 送信先ID
	netuBufOut[2] = 7;				// コマンド
	
	netuBufOut[3] = blk[0];
	netuBufOut[4] = bx[0];
	netuBufOut[5] = by[0];
	netuBufOut[6] = rt[0];
	netuBufOut[7] = nextc[0];
	netuBufOut[8] = ndelay[0];
	netuBufOut[9] = hold[0];
	netuBufOut[10] = dhold[0];
	netuBufOut[11] = hold_count[0];
	
	tcpSend(&netuBufOut, netuBufOut[0]);
}

// 敵の移動を反映させる
void netuRecvEnemyMove() {
	int i;
	
	blk[1] = netuBufIn[3];
	bx[1] = netuBufIn[4];
	by[1] = netuBufIn[5];
	rt[1] = netuBufIn[6];
	nextc[1] = netuBufIn[7];
	ndelay[1] = netuBufIn[8];
	hold[1] = netuBufIn[9];
	dhold[1] = netuBufIn[10];
	hold_count[1] = netuBufIn[11];
	
	// ブロックの色を設定
	for(i = 0; i < 4; i++) {
		current_color[i + 4] = blockcolor[blk[1] + 7];
		current_color_m[i + 4] = blockcolor[blk[1] + 7];
		hold_color[i + 4] = blockcolor[hold[1] + 7];
	}
	setNextBlockColor(1, 1);
	
	// 効果音再生
	if(blk[1] != netuLastBlk[1]) {
		// 新しいブロック出現時
		netuLastBlk[1] = blk[1];
		if(hnext[1]) PlaySE(se_blockse[getNextBlock(1, 0)]);
	} else {
		// 移動
		if(bx[1] != netuLastBx[1]) {
			netuLastBx[1] = bx[1];
			if(move_sound) PlaySE(se_move);
		}
		// 回転
		if(rt[1] != netuLastRt[1]) {
			netuLastRt[1] = rt[1];
			if(rotate_sound) PlaySE(se_rotate);
		}
	}
	
	if(onRecord[0] && timeOn[0]) {
		stat[1] = 4;
		resetStatc(1);
		netuEnemyBlockVisible = 1;
	}
}

// ARE中の処理
void netuARE(int player) {
	if(player == 0) {
		// 自分のARE時の処理
		if(!statc[player * 10 + 1]) {
			netuSendField(0);	// 自分のフィールドを送信
			statc[player * 10 + 1] = 1;
		}
	} else {
		// 相手のARE時の処理
		stat[1] = 4;
		resetStatc(1);
	}
}

// フィールドを送信
void netuSendField(int eraseflag) {
	int i;
	
	if(netuTraining) return;
	
	netuBufOut[0] = 67 * 4;				// サイズ
	netuBufOut[1] = netuEnemyID;		// 送信先ID
	netuBufOut[2] = 8;					// コマンド
	netuBufOut[3] = eraseflag;			// ライン消去／ゲームオーバーフラグ
	netuBufOut[4] = upLines[0];			// 自分のせり上がり数
	netuBufOut[5] = hebocombo[0];		// ヘボリスからのコンボかどうか
	netuBufOut[6] = combo[0];			// コンボ数
	netuBufOut[7] = b_to_b_count[0];	// B2Bフラグ
	netuBufOut[8] = tspin_flag[0];		// T-SPINフラグ
	netuBufOut[9] = last_command[0];	// 最後にした操作
	netuBufOut[10] = netuScore[0];		// スコア
	netuBufOut[11] = netuLines[0];		// ライン
	
	for(i = 0; i < 55; i++) {
		netuBufOut[i + 12] = (fld[(i * 4) + 0]);
		netuBufOut[i + 12] = netuBufOut[i + 12] | (fld[(i * 4) + 1] << 8);
		netuBufOut[i + 12] = netuBufOut[i + 12] | (fld[(i * 4) + 2] << 16);
		netuBufOut[i + 12] = netuBufOut[i + 12] | (fld[(i * 4) + 3] << 24);
	}
	
	tcpSend(&netuBufOut, netuBufOut[0]);
}

// フィールドを受信
void netuRecvField() {
	int i;
	
	// 操作中ブロックを非表示にする
	netuEnemyBlockVisible = 0;
	
	// フィールドをコピー
	for(i = 0; i < 55; i++) {
		fld[(i * 4) + 0 + 220] = (netuBufIn[i + 12] & 0x000000FF);
		fld[(i * 4) + 1 + 220] = (netuBufIn[i + 12] & 0x0000FF00) >> 8;
		fld[(i * 4) + 2 + 220] = (netuBufIn[i + 12] & 0x00FF0000) >> 16;
		fld[(i * 4) + 3 + 220] = (netuBufIn[i + 12] & 0xFF000000) >> 24;
	}
	
	// フィールドのブロックを見えるようにする
	disableShadowTimer(1);
	
	// NEXT遅延解除
	ndelay[1] = 1;
	
	// HOLD使用可能
	if(netuHoldEnable != 0) dhold[1] = 0;
	
	// せり上がり数など
	upLines[1] = netuBufIn[4];
	hebocombo[1] = netuBufIn[5];
	combo[1] = netuBufIn[6];
	b_to_b_count[1] = netuBufIn[7];
	tspin_flag[1] = netuBufIn[8];
	last_command[1] = netuBufIn[9];
	netuScore[1] = netuBufIn[10];
	netuLines[1] = netuBufIn[11];
	
	if(netuBufIn[3] == 1) {
		// ライン消去の時
		blockEraseJudge(1);
		stat[1] = 6;
		resetStatc(1);
	} else if(netuBufIn[3] == 2) {
		// ゲームオーバーの時
		stat[1] = 7;
		resetStatc(1);
	} else {
		// ブロックを置いたときの効果音
		if(stat[1] == 6) PlaySE(se_gon);
		else PlaySE(se_kachi);
	}
}

// ブロック消去時の処理
void netuStatEraseBlock(int player, int *param) {
	// 自分の消去時の最初のフレーム（まだブロックは消えていない）
	if((statc[player * 10] == 0) && (player == 0)) {
		netuSendField(1);	// 自分のフィールドを送信
	}
	
	// 敵の消去時
	if(player == 1) {
		if(statc[player * 10] != 0) param[0] = 1;	// 相手が消去し終わるまで待つ
	}
}

// 切断時
void netuStatDisconnect(int player) {
	printFont(foffset[player], fyoffset[player] + 96, "DISCONNECTED", 3);
	
	if(statc[player * 10 + 0] >= 180) {
		stat[0] = 8;
		stat[1] = 8;
		resetStatc(0);
		resetStatc(1);
		resetField(0);
		resetField(1);
	} else {
		statc[player * 10 + 0]++;
	}
}

// 勝利
void netuStatWin(int player) {
	// プレイ結果送信
	if((!netuEnemyDisconnect) && (player == 0) && (statc[player * 10] == 0)) {
		netuSendPlayResult();
	}
	if(statc[player * 10] == 0) {
		if(netuWin[player] < 99) netuWin[player]++;
	}
	
	// 花火
	if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 3] < 10)) {
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		statc[player * 10 + 3]++;
	}
	
	// WINロゴ
	statc[player * 10 + 1]++;
	statc[player * 10 + 2] = statc[player * 10 + 2] + statc[player * 10 + 1] / 4;
	
	if(statc[player * 10 + 2] > 140) {
		statc[player * 10 + 2] = 140;
		statc[player * 10 + 1] = -20;
	}
	
	ExBltRect(sg_spr, foffset[player] + 9, statc[player * 10 + 2], 184, 0, 79, 23);
	
	statc[player * 10]++;
	
	// ボタンでスキップ
	if(getPushState(player, 4) && (statc[player * 10] >= 60)) {
		statc[player * 10] = 300;
	}
	// 次の画面へ
	if(statc[player * 10] >= 300) {
		stat[0] = 8;
		stat[1] = 8;
		resetStatc(0);
		resetStatc(1);
		resetField(0);
		resetField(1);
	}
}

// リトライ
void netuStatRetryScreen(int player) {
	int color;
	
	if(player) return;
	
	color = (count % 4 / 2) * 7;
	
	if(netuEnemyDisconnect) statc[player * 10 + 0] = 1;
	
	printFont(foffset[player] + 16, fyoffset[player] + 112 + statc[player * 10 + 0] * 16, "b", color);
	
	if(!netuEnemyDisconnect) {
		printFont(foffset[player] + 24, fyoffset[player] + 112, "RETRY", (statc[player * 10 + 0] == 0) * color);
	}
	printFont(foffset[player] + 24, fyoffset[player] + 128, "END", (statc[player * 10 + 0] == 1) * color);
	
	// キー入力
	padRepeat2(player);
	
	// ↑↓
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if(getPressState(player, 0) || getPressState(player, 1)) {
		PlaySE(se_move);
		statc[player * 10 + 0] = !statc[player * 10 + 0];
	}
	
	// Aボタン
	if(getPushState(player, 4)) {
		// RETRY
		if(statc[player * 10 + 0] == 0) {
			PlaySE(se_kettei);
			gameAllInit();
			playerInitial(0);
			playerInitial(1);
			if(netuPlayerType == 0) versusInit(0);
			stat[0] = 3;
			stat[1] = 3;
			
			netuBufOut[0] = 3 * 4;			// サイズ
			netuBufOut[1] = netuEnemyID;	// 送信先ID
			netuBufOut[2] = 9;				// コマンド
			tcpSend(&netuBufOut, netuBufOut[0]);
		}
		// END
		else {
			tcpClosesocket();
			flag = 1;
		}
	}
}

// ゲームオーバー処理
void netuGameOver(int player, int *param) {
	int i, drawflag;
	
	param[0] = 1;
	
	// 引き分けフラグ
	if(stat[1 - player] == 7) drawflag = 1;
	else drawflag = 0;
	
	// 最初のフレームの処理
	if(statc[player * 10] == 0) {
		// 自分の状態を送信
		if(!player) {
			netuSendPlayerMove();
			netuSendField(2);
		}
		StopAllBGM();
		StopSE(se_hurryup);
		onRecord[0] = 0;
		onRecord[1] = 0;
		timeOn[0] = 0;
		timeOn[1] = 0;
		pinch[0] = 0;
		pinch[1] = 0;
		
		if((!drawflag) && (!netuTraining)) {
			stat[1 - player] = 2;
			resetStatc(1 - player);
			netuCustomStatNo[1 - player] = 1;
		}
		
		// プレイ結果送信
		if((!netuEnemyDisconnect) && (player == 0)) {
			netuSendPlayResult();
		}
	}
	
	if(!netuTraining) {
		// LOSEロゴ
		statc[player * 10 + 1]++;
		statc[player * 10 + 2] = statc[player * 10 + 2] + statc[player * 10 + 1] / 4;
		
		if(statc[player * 10 + 2] > 140) {
			statc[player * 10 + 2] = 140;
			statc[player * 10 + 1] = -20;
		}
		
		ExBltRect(sg_spr, foffset[player] + 8, statc[player * 10 + 2], 184, 24 * (drawflag + 1), 79, 23);
	}
	
	statc[player * 10]++;
	
	// ボタンでスキップ
	if(getPushState(player, 4) && (statc[player * 10] >= 60)) {
		statc[player * 10] = 300;
	}
	// 次の画面へ
	if(statc[player * 10] >= 300) {
		stat[0] = 8;
		resetStatc(0);
		resetField(0);
		
		if(!netuTraining) {
			stat[1] = 8;
			resetStatc(1);
			resetField(1);
		}
	}
}

// プレイ結果を相手に送信
void netuSendPlayResult() {
	if(netuTraining) return;
	
	netuBufOut[0] = 6 * 4;			// サイズ
	netuBufOut[1] = netuEnemyID;	// 送信先ID
	netuBufOut[2] = 12;				// コマンド
	netuBufOut[3] = netuScore[0];
	netuBufOut[4] = netuLines[0];
	netuBufOut[5] = gameTimer[0];
	tcpSend(&netuBufOut, netuBufOut[0]);
}

// 結果表示
void netuResult(int player, int *param) {
	param[0] = 1;
	
	// 結果
	printSMALLFont(foffset[player] + 21, fyoffset[player] + 50, "PLAY DATA", 4);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 79, "SCORE");
	sprintf(string[0], "%13d", netuScore[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 87, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 99, "LINES");
	sprintf(string[0], "%13d", netuLines[player]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 107, string[0], 0);
	
	printTinyFont(foffset[player] + 8, fyoffset[player] + 119, "TIME");
	getTime(gameTimer[0]);
	sprintf(string[1], "%13s", string[0]);
	printSMALLFont(foffset[player] + 10, fyoffset[player] + 127, string[1], 0);
	
	// カウンタ増加
	statc[player * 10]++;
	
	if(player == 0) {
		if(statc[player * 10] == 1) {
			// BGM再生
			if(bgmtype != 0) {
				bgmlv = 13;
				PlayBGM();
			}
		}
	}
	
	// ボタンでスキップ
	if(getPushState(player, 4)) {
		statc[player * 10] = 500;
	}
	
	// 次の画面へ
	if(statc[player * 10] >= 500) {
		if(netuTraining) {
			StopAllBGM();
			netuTraining = 0;
			gameAllInit();
			playerInitial(0);
			versusInit(0);
			stat[0] = 3;
			stat[1] = 3;
		} else {
			stat[0] = 9;
			stat[1] = 9;
		}
		resetStatc(0);
		resetStatc(1);
	}
}

// ゲームオーバー表示
void netuGameOver2(int player, int *param) {
	int i, param;
	
	param[0] = 1;
	
	// カウンタ増加
	statc[player * 10]++;
	
	// ゲームオーバー音
	if(player == 0) {
		if(statc[player * 10] == 1) {
			PlaySE(se_gameover);
			StopAllBGM();
		}
	}
	
	// GAME OVER
	ExBltRect(sg_gametext, foffset[player] - 2, 95, 0, 0, 100, 50);
	
	// ボタンでスキップ
	if(getPushState(player, 4)) {
		statc[player * 10] = 480;
	}
	
	// 終了
	if(statc[player * 10] >= 480) {
		stat[0] = 2;
		stat[1] = 2;
		netuCustomStatNo[0] = 2;
		netuCustomStatNo[1] = 2;
		resetStatc(0);
		resetStatc(1);
	}
}

// BGM読み込み
void netuLoadBGM() {
	if(bgmtype != 0) {
		ClearSecondary();
		printFontGrid(1, 1, "LOADING BGM...", 2);
		halt;
		loadBGM(10);
		if(!enable_sysbgm) loadBGM(13);
	}
}

// ライン消去
void netuCalcScore(int player, int lines) {
	int bo, b2b, combopts, combogoal, points;
	
	// T-SPIN時
	if(tspin_flag[player]) {
		PlaySE(se_tserase);
		netuTSpinFrame[player] = 60;
		netuTSpinLine[player] = lines;
		netuTSpinWall[player] = (last_command[player] == 4);
		
		if((lines == 1) && (netuTSpinWall[player])) bo = 2;	// 壁蹴りありT-SPIN Single
		if((lines == 1) && (!netuTSpinWall[player])) bo = 8;	// 壁蹴りなしT-SPIN Single
		if(lines == 2) bo = 12;	// T-SPIN Double
		if(lines == 3) bo = 16;	// T-SPIN Triple
	}
	// 普通のライン消し
	else {
		if(lines == 1) bo = 1;
		if(lines == 2) bo = 3;
		if(lines == 3) bo = 5;
		if(lines == 4) {
			netuTSpinFrame[player] = 60;
			netuTSpinLine[player] = lines;
			bo = 8;
		}
	}
	
	// B2Bボーナス（x 1.5）
	if((netuEnableB2B != 0) && (b_to_b_count[player] >= 2)) {
		b2b = 1;
		netuB2BFrame[player] = 60;
	} else {
		b2b = 0;
		netuB2BFrame[player] = 0;
	}
	
	// コンボボーナス
	if((netuEnableCombo != 0) && (combo[player] >= 2)) {
		combopts = (combo[player] - 1) * 50;
		
		if(combo[player] >= 12) combogoal = 5;
		else if(combo[player] >= 9) combogoal = 4;
		else if(combo[player] >= 7) combogoal = 3;
		else if(combo[player] >= 5) combogoal = 2;
		else if(combo[player] >= 3) combogoal = 1;
		else combogoal = 0;
		
		netuComboFrame[player] = 60;
	} else {
		combopts = 0;
		combogoal = 0;
	}
	
	// 全消しボーナス
	if(isBravo(player)) {
		objectCreate(player, 4, foffset[player] - 4, 232, 0, 0, 0, 0);
		objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
		netuScore[player] = netuScore[player] + 5000;
	}
	
	// スコア加算
	points = bo * 100;
	
	if(!player) {
		netuScore[player] = netuScore[player] + points;
		if(b2b) netuScore[player] = netuScore[player] + (points / 2);
		netuScore[player] = netuScore[player] + combopts;
	}
	
	netuScoreGet[player] = points + ((points / 2) * (b2b)) + combopts;
	netuScoreFrame[player] = 120;
	
	// ライン加算
	if(!player) netuLines[player] = netuLines[player] + lines;
	
	// 相手にプレイ状況を送信
	if(!player) netuSendPlayResult();
}

// ライン消しなしのT-SPIN
void netuTSpinZero(int player) {
	PlaySE(se_tspin);
	netuTSpinFrame[player] = 60;
	netuTSpinLine[player] = 0;
	
	// 壁蹴りあり
	if(last_command[player] == 4) {
		if(!player) netuScore[player] = netuScore[player] + 100;
		netuTSpinWall[player] = 1;
		
		netuScoreGet[player] = 100;
		netuScoreFrame[player] = 120;
	}
	// 壁蹴りなし
	else {
		if(!player) netuScore[player] = netuScore[player] + 400;
		netuTSpinWall[player] = 0;
		
		netuScoreGet[player] = 400;
		netuScoreFrame[player] = 120;
	}
	
	// 相手にプレイ状況を送信
	if(!player) netuSendPlayResult();
}

// ハードドロップ
void netuHardDrop(int player, int bottom) {
	if((!up_flag[player]) && (judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) == 0)) {
		netuScore[player] = netuScore[player] + (bottom - by[player]) * 2;
	}
}

// ソフトドロップで入った点数を加算
void netuSoftDropScore(int player) {
	if(softd_score[player] > 0) {
		netuScore[player] = netuScore[player] + softd_score[player];
	}
}

// スコア表示
void netuViewScore(int player) {
	int color, color2, temp;
	color = (count % 4 / 2) * (is20G(player)) * 7;
	
	if(netuGameType) {
		// スコア
		printTinyFont(112 + player * 70, fyoffset[player] + 40, "SCORE");
		if(!player) sprintf(string[0], "%d", netuScore[player]);
		else sprintf(string[0], "%8d", netuScore[player]);
		printSMALLFont(112 + player * 48, fyoffset[player] + 48, string[0], color);
		
		// 今入った得点
		if(netuScoreFrame[player] > 0) {
			netuScoreFrame[player]--;
			if(!player) sprintf(string[0], "%d", netuScoreGet[player]);
			else sprintf(string[0], "%8d", netuScoreGet[player]);
			printSMALLFont(112 + player * 48, fyoffset[player] + 58, string[0], (count % 4 / 2) * (1 + (b_to_b_count[player] != 0)));
		}
	} else {
		// ライン
		printTinyFont(112 + player * 70, fyoffset[player] + 40, "LINES");
		if(!player) sprintf(string[0], "%d", netuLines[player]);
		else sprintf(string[0], "%8d", netuLines[player]);
		printSMALLFont(112 + player * 48, fyoffset[player] + 48, string[0], color);
	}
	
	// 残りタイム
	if(player == 0) {
		if((netuLimitTime[player] <= 10 * 60) && (timeOn[player])) color2 = (count % 4 / 2) * 2;
		else color2 = color;
		getTime(netuLimitTime[player]);
		printBIGFont(112, 216, string[0], color2);
	}
	
	if(netuGameType) {
		// T-SPIN
		if(netuTSpinFrame[player] > 0) {
			netuTSpinFrame[player]--;
			
			if((netuTSpinLine[player] == 0) && (netuTSpinWall[player]))
				printTinyFont(foffset[player] + 25, fyoffset[player] + 208, "EZ T-SPIN");
			else if((netuTSpinLine[player] == 0) && (!netuTSpinWall[player]))
				printTinyFont(foffset[player] + 33, fyoffset[player] + 208, "T-SPIN");
			else if((netuTSpinLine[player] == 1) && (netuTSpinWall[player]))
				printTinyFont(foffset[player] + 20, fyoffset[player] + 208, "T-SPIN MINI");
			else if((netuTSpinLine[player] == 1) && (!netuTSpinWall[player]))
				printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN SINGLE");
			else if(netuTSpinLine[player] == 2)
				printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN DOUBLE");
			else if(netuTSpinLine[player] == 3)
				printTinyFont(foffset[player] + 16, fyoffset[player] + 208, "T-SPIN TRIPLE");
			else if(netuTSpinLine[player] == 4)
				printTinyFont(foffset[player] + 30, fyoffset[player] + 208, "HEBORIS");
		}
		
		// BACK TO BACK
		if(netuB2BFrame[player] > 0) {
			netuB2BFrame[player]--;
			printTinyFont(foffset[player] + 18, fyoffset[player] + 200, "BACK TO BACK");
		}
		// COMBO
		else if((netuComboFrame[player] > 0) && (combo[player] >= 2)) {
			netuComboFrame[player]--;
			sprintf(string[0], "COMBO %d", combo[player] - 1);
			printTinyFont(foffset[player] + 30, fyoffset[player] + 200, string[0]);
		}
	}
	
	// トレーニング中の表示
	if((netuTraining) && (player == 0) && (onRecord[0])) {
		printTinyFontB(foffset[player] + 15, fyoffset[player] + 216, "PUSH PAUSE TO");
		printTinyFontB(foffset[player] + 15, fyoffset[player] + 223, "EXIT TRAINING");
	}
	
	if(player == 0) {
		// スピード
		printTinyFont(142, 153, "SPEED");
		sprintf(string[0], "%d", sp[player]);
		printSMALLFont(142, 161, string[0], color);
		
		sprintf(string[0], "TYPE %d", speedtype[player] + 1);
		printSMALLFont(142, 171, string[0], color);
		
		// wait値
		ExBltRect(sg_smallfont, 142, 181, 68, 14, 24, 7);	// WAITS
		sprintf(string[0], "%2d %2d\n%2d %2d", wait1[player], wait2[player], wait3[player], waitt[player]);
		printSMALLFont(142, 189, string[0], color);
		
		if(wait4[player] != -1) {
			sprintf(string[0], "%2d", wait4[player]);
			printSMALLFont(142, 207, string[0], color);
		}
		
		if(wait5[player] != -1) {
			sprintf(string[0], "%2d", wait5[player]);
			printSMALLFont(160, 207, string[0], color);
		}
		
		// ARE Force
		if(netuAreUse > -1) {
			printTinyFont(112, 153, "ARE");
			
			if(netuAreUse == 0) sprintf(string[0], "OFF");
			else if(netuAreUse == 1) sprintf(string[0], "ON");
			else sprintf(string[0], "SKIP");
			printSMALLFont(112, 161, string[0], 2);
		}
		
		// ゲームタイプ
		printTinyFont(112, 171, "TYPE");
		if(!netuGameType) {
			sprintf(string[0], "LINE");
			temp = 4;
		} else {
			sprintf(string[0], "SCORE");
			temp = 1;
		}
		printSMALLFont(112, 179, string[0], temp);
		
		if(netuTraining) {
			// トレーニング
			printTinyFontB(139, 10, "TRAINING");
		} else if(netuEnemyID != 0) {
			// ラウンド
			sprintf(string[0], "ROUND %d", netuRound);
			printTinyFont(140, 10, string[0]);
		}
	}
	
	if((player == 1) && (netuEnemyDisconnect)) {
		printTinyFont(foffset[player] + 18, fyoffset[player] + 200, "DISCONNECTED");
	}
	
	// 勝利回数
	if(netuEnemyID != 0) {
		ExBltRect(sg_smallfont, 112 + player * 82, 135, 93, 14, 14, 7);	// WIN
		if(!player) sprintf(string[0], "%d", netuWin[player]);
		else sprintf(string[0], "%2d", netuWin[player]);
		printSMALLFont(112 + player * 84, 143, string[0], color);
	}
}

// 自分と相手のニックネームを表示
void netuViewNickname(int player) {
	ExTextLayerOn(player, foffset[player] + 8, fyoffset[player] + 222);
	ExTextSize(player, 10);
	TextColor(player, 255, 255, 255);
	TextBackColor(player, 64, 64, 64);
	TextOut(player, netuNickname[player]);
}

// 設定を保存
void netuSaveConfig() {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 2;
	
	// 設定内容
	saveBuf[1] = netuGhost;
	saveBuf[2] = netuTSpin;
	saveBuf[3] = netuEnableCombo;
	saveBuf[4] = netuEnableB2B;
	saveBuf[5] = netuSpeed;
	saveBuf[6] = netuSpeedType;
	saveBuf[7] = netuWait1;
	saveBuf[8] = netuWait2;
	saveBuf[9] = netuWait3;
	saveBuf[10] = netuWaitt;
	saveBuf[11] = netuWait4;
	saveBuf[12] = netuWait5;
	saveBuf[13] = netuGameType;
	saveBuf[14] = netuAreUse;
	saveBuf[15] = netuFastlrmove;
	saveBuf[16] = netuRepeatDelay;
	saveBuf[17] = netuMaxDAS;
	saveBuf[18] = netuSpawnType;
	saveBuf[19] = netuHoldEnable;
	
	// プリセット
	saveBuf[21] = netuLastPresetNo;
	for(i = 0; i < 20 * 10; i++) saveBuf[22 + i] = netuPreset[i];
	
	SaveFile("config/NET_ULTRA_CONFIG.SAV", &saveBuf, 222 * 4);
}

// 設定を読み込み
int netuLoadConfig() {
	int i;
	
	FillMemory(&saveBuf, 150000 * 4, 0);
	
	LoadFile("config/NET_ULTRA_CONFIG.SAV", &saveBuf, 222 * 4);
	
	// ヘッダがおかしいなら終了
	if(saveBuf[0] != 2) return 0;
	
	// 設定内容
	netuGhost = saveBuf[1];
	netuTSpin = saveBuf[2];
	netuEnableCombo = saveBuf[3];
	netuEnableB2B = saveBuf[4];
	netuSpeed = saveBuf[5];
	netuSpeedType = saveBuf[6];
	netuWait1 = saveBuf[7];
	netuWait2 = saveBuf[8];
	netuWait3 = saveBuf[9];
	netuWaitt = saveBuf[10];
	netuWait4 = saveBuf[11];
	netuWait5 = saveBuf[12];
	netuGameType = saveBuf[13];
	netuAreUse = saveBuf[14];
	netuFastlrmove = saveBuf[15];
	netuRepeatDelay = saveBuf[16];
	netuMaxDAS = saveBuf[17];
	netuSpawnType = saveBuf[18];
	netuHoldEnable = saveBuf[19];
	
	// プリセット
	netuLastPresetNo = saveBuf[21];
	for(i = 0; i < 20 * 10; i++) netuPreset[i] = saveBuf[22 + i];
	
	return 1;
}

// プリセットを初期化
void netuMakeDefaultPreset() {
	int i;
	
	netuLastPresetNo = 0;
	for(i = 0; i < 20 * 10; i++) netuPreset[i] = 0;
}

// プリセットを保存
void netuSavePreset(int number) {
	netuPreset[number * 20 + 0] = netuGhost;
	netuPreset[number * 20 + 1] = netuTSpin;
	netuPreset[number * 20 + 2] = netuEnableCombo;
	netuPreset[number * 20 + 3] = netuEnableB2B;
	netuPreset[number * 20 + 4] = netuSpeed;
	netuPreset[number * 20 + 5] = netuSpeedType;
	netuPreset[number * 20 + 6] = netuWait1;
	netuPreset[number * 20 + 7] = netuWait2;
	netuPreset[number * 20 + 8] = netuWait3;
	netuPreset[number * 20 + 9] = netuWaitt;
	netuPreset[number * 20 + 10] = netuWait4;
	netuPreset[number * 20 + 11] = netuWait5;
	netuPreset[number * 20 + 12] = netuGameType;
	netuPreset[number * 20 + 13] = netuAreUse;
	netuPreset[number * 20 + 14] = netuFastlrmove;
	netuPreset[number * 20 + 15] = netuRepeatDelay;
	netuPreset[number * 20 + 16] = netuMaxDAS;
	netuPreset[number * 20 + 17] = netuSpawnType;
	netuPreset[number * 20 + 18] = netuHoldEnable;
}

// プリセットを読み込み
void netuLoadPreset(int number) {
	netuGhost = netuPreset[number * 20 + 0];
	netuTSpin = netuPreset[number * 20 + 1];
	netuEnableCombo = netuPreset[number * 20 + 2];
	netuEnableB2B = netuPreset[number * 20 + 3];
	netuSpeed = netuPreset[number * 20 + 4];
	netuSpeedType = netuPreset[number * 20 + 5];
	netuWait1 = netuPreset[number * 20 + 6];
	netuWait2 = netuPreset[number * 20 + 7];
	netuWait3 = netuPreset[number * 20 + 8];
	netuWaitt = netuPreset[number * 20 + 9];
	netuWait4 = netuPreset[number * 20 + 10];
	netuWait5 = netuPreset[number * 20 + 11];
	netuGameType = netuPreset[number * 20 + 12];
	netuAreUse = netuPreset[number * 20 + 13];
	netuFastlrmove = netuPreset[number * 20 + 14];
	netuRepeatDelay = netuPreset[number * 20 + 15];
	netuMaxDAS = netuPreset[number * 20 + 16];
	netuSpawnType = netuPreset[number * 20 + 17];
	netuHoldEnable = netuPreset[number * 20 + 18];
}
