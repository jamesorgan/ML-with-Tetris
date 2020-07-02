//□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□
//
//    HEBORIS [ヘボリス] 2001 Ver1.60β1 / 2000.11.05 (Sun) ～ 2001.07.29 (Sun)
//
//                         (c) 1998-2001 Kenji Hoshimoto
//
//   Version 1.60 (02/03/31) 横移動を修正、フィールドの背景を消せるように
//                           ブロックが突然消えるバグを修正
//   Version 1.51 (01/12/04) 落ちてしまうバグを修正
//   Version 1.50 (01/11/26) ランキング機能追加 (インターネットランキング対応)
//                           リプレイ・ポース・NEXT隠し機能追加 デモ画面追加
//                           全消しボーナス追加 デビルモードをもう少し簡単に
//                           その他いっぱい
//
//■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■
// TODO: さあどうしようかな～

/*
LITE32.13 (07/07/04)
【追加】
・heboris_user.iniを復活させてみました。
・heboris.iniに「devil_doom_n_rise」を追加しました。1にするとDEVIL-DOOMでせり上がり間隔が一定になります。
【変更】
・DEVIL-DOOMモードのLV300-400の速度とACE-ANOTHERモードとACE-ANOTHER2モードの速度を変更しました。
・MASTER-HARDの認定試験で現在の認定段位と試験段位の差が5以内になるようにしました。（MOとかやたら高い段位が出ないように）
・MASTER-HARDの降格試験が2回以上連続で起こらないようにしました。
・数字キーでリプレイを保存すると、保存完了メッセージが他の文字と被ることがあったのでメッセージを小さくしました。
【バグ修正】
・DEVIL-HARDとDEVIL-DOOMで、段位がS10～S13のときに結果画面の段位表示がフィールド枠に被るバグを修正しました。
・SOUND SETTINGの「BGM FADE TIME」が0だとBGMが切り替わらないバグを修正しました。
・20G-EASYでGm条件の判定が行われないバグを修正しました。

LITE32.12 (07/06/27)
【追加】
・DISPLAY SETTINGに「HIDDEN-B TYPE」を追加しました。SPECIALにするとHIDDEN-B状態でブロックを置いても枠線が出なくなります。
・MISSIONモードに新しいミッション「速度固定」を追加しました。ミッションの設定で速度を自由に指定できるレベルスターです。
・リプレイ選択画面でPRACTICEのリプレイの到達レベルが見えるようにしました。
・DISPLAY SETTINGのREFRESH TIMINGがメニューでも反映されるようにしました。
【バグ修正】
・リプレイ選択画面でMASTER-EASYと20G-EASYのリプレイで段位表示がGMではなくM1と表示されるバグを修正しました。
・リプレイ中にBボタンを押すと設定画面で設定値の変更ができなくなる事があるバグを修正したつもり

LITE32.11 (07/06/18)
【追加】
・MASTER-EASYモードを追加しました。（いわゆるMASTER-G1）
・DISPLAY SETTINGに「EFFECT SPEED」を追加しました。ライン消去エフェクトの速さを5段階で変更できます。
　AUTOにすると通常は1倍速、高速になると2倍速、超高速になると3倍速になります。
　2倍速以上にすると多分描画も軽くなるはず…
・OLD STYLE-ARCADEの消去エフェクトを変更しました。
　また、DISPLAY SETTINGのBREAK EFFECTに「OLD STYLE-ARCADE」を追加しました。
　全てのモードでOLD STYLE-ARCADEと同じエフェクトを使えます。
【変更】
・DEVIL-DOOMの速度とせり上がりペースを変更しました。
・ACE-ANOTHERモードとACE-ANOTHER2モードの速度を変更しました。（速度変化はLV13で打ち止め、DEVIL-DOOM LV300-400台と同じ）
【バグ修正】
・1フレームに2回以上横溜め処理が行われるバグをたぶん完全に修正しました。
・VERSUSモードやデモ画面などのCPUがまともに動作していないバグを修正しました。
・エンディング突入時、ブロックが消えていく場面で横溜めができないバグを修正しました。
・MISSIONモードのリプレイで操作状況表示が左に出てしまうバグを修正しました。

LITE32.10 (07/06/10)
【追加】
・SKIP LOCKFLASHに「ARCADE」を追加しました。
　「OFF」よりも短くて「ON」よりも長いです。固定した瞬間の灰色ブロックの表示時間が2フレームあります。
・DISPLAY SETTINGに「REFRESH TIMING」を追加しました。
　画面表示を更新するタイミングを「内部処理の後」と「内部処理の前」のどちらにするかを選択できます。
・WORLD SOFTLOCKに「NONE」を追加しました。ワールドルールで下を押しつづけても（本当に）何も起こらなくなります。
　これまでの「OFF」（微妙に早く固定時間が進む）は「NORMAL」に改名しました。
【バグ修正】
・INPUT SETTINGのFUNCTION KEYを選択するとフリーズするバグを修正しました。
・SKIP LOCKFLASHがOFF以外の場合、ブロックが固定した瞬間に横溜め処理が1フレームに2回行われるバグを修正しました。
・SETTYAKUを99にするとブロックが一瞬で固定されてしまうバグを修正しました。
・AFTERIMAGEをONにしていても残像が表示されないバグを修正しました。

LITE32.9以前の変更履歴はchangelog.txtにあります。
*/

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   外部ライブラリのインポート
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
	import	"string.dll"		// 文字列ライブラリのインポート

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   グローバル変数の定義
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int		count;						// グローバルカウンタ (フレーム単位、65535まで)
int		backno;						// 現在の背景
int		background_compatibility;	// back13.png back14.png back15.pngを無視する

int		stat[2], statc[10*2];		// 現在のステータスとパラメータ no + pl * 5
int		gameTimer[2], timeOn[2];	// ゲーム開始からの経過時間 (1/60秒単位)、有効?

int		flag;						// 1にするとタイトルに戻る
int		overcount;					// 1Pと2Pがゲームオーバーになったとき、タイトルに戻るときに使うカウンタ

int		pinch[2];					// ピンチかどうか

int		winr, winc, winu, wink;

int		noredraw, fast;
int		csr, cnt, category;

int		saveBuf[50000];				// セーブ用バッファ
int		setupBak[24];				// セッティング内容のバックアップ用
int		pause[2];					// ポーズしてるかーい!?
int		hnext[2];					// NEXT隠してるかーい!?
int		gameMode[2];				// 現在のゲームモード

int		rankingrule;

int		ssc = 0;					// スクリーンショットカウンタ

int		timeattack[2];				// ゲームタイプ

int		bdowncnt[2];				// ブロックを置いた回数
int		s_bdowncnt[2];				// ブロックを置いた回数（破片判定／スクウェア用）

int		IsBig[2];					// 現在BIGかどうか
int		BigMove[2];					// BIG時の横移動単位
int		IsBigStart[2];				// BIGで始めたかどうか
int		BigMoveStart[2];			// スタート時の横移動単位

int		first_setting;				// 設定ファイルの読み込みに失敗したら-1になる
int		reload_graphics;			// 再読み込みフラグ
int		reload_background;
int		reload_se;
int		reload_bgm;

int		repversw;					// 旧バージョンのリプレイを再生するためのスイッチ

int		randseed[2];				// 擬似乱数シード
int		firstseed[2];				// 最初の乱数シード

int		dummy;						// heboris_user.ini用

int		maxPlay = 0;				// プレイ人数 0=1人 1=2人
int		b_maxPlay = 0;				// プレイ人数のバックアップ

int		w_reverse = 1;				// 1にするとワールドルールで回転方向を逆転させる
int		r_irs = 1;					// 1にすると赤のIRS時の床蹴り無効

int		fldtr = 64;					// 背景の半透明度
int		skip_viewbg = 0;			// 背景なし

int		tls_view = 0;				// TLS 0=LV100まで表示 1=常に表示 2=常に非表示

int		world_move_sound = 1;		// WORLDで接地時に横移動／回転したときに接地音を鳴らすか

int		def_IsBig = 0;				// BIGモード
int		def_BigMove = 1;			// BIG横移動

int		show_fps = 0;				// FPSを表示する
int		lvupbonus = 0;				// 3ライン以上消したときのレベルアップボーナス 0=あり(TI) 1=なし(TGM/TAP)
int		showctrl = 0;				// 操作状況表示 0=リプレイのみ 1=常に表示 2=常に非表示
int		use_over1000_block = 1;		// []の有無
int		over1000_start = 1000;		// []の開始レベル

int		keyAssign[10 * 2];			// キーボード割り当て
int		pause_key[2];				// ポーズ
int		hnext_key[2];				// NEXT隠し
int		giveup_key;					// 捨てゲー
int		ss_key;						// スクリーンショット
int		skip_key[2];				// ステージスキップ
int		fps_plus_key;				// FPS+1
int		fps_minus_key;				// FPS-1

int		joykeyAssign[10 * 2];		// ジョイスティックボタン割り当て
int		joy_pause_key[2];			// ジョイスティック ポーズ
int		joy_hnext_key[2];			// ジョイスティック NEXT隠し
int		joy_giveup_key[2];			// ジョイスティック 捨てゲー
int		joy_ss_key[2];				// ジョイスティック スクリーンショット
int		joy_skip_key[2];			// ジョイスティック ステージスキップ
int		joy_fps_plus_key[2];		// ジョイスティック FPS+1
int		joy_fps_minus_key[2];		// ジョイスティック FPS-1
int		joykeyButtonNum;			// ジョイスティックのボタン数

int		fps_plus_mpc;				// FPS+1の押しっぱなし時間
int		fps_minus_mpc;				// FPS-1の押しっぱなし時間

int		rule_name = 1;				// ルール名の種類（0、1、2の3種類）
int		main_fps = 60;				// ゲーム全体のFPS
int		dispnext = 6;				// NEXT表示数
int		spawn_y_type = 1;			// ブロックの出現位置 0=枠内 1=枠外
int		top_frame = 0;				// NEXT欄のグラフィックの種類

int		empty_spin_field = 0;		// 1にすると参加待ちプレイヤーのフィールドがグルグル回る

int		w_lockdown = 1;				// ワールドルールの回転制限の設定
									// 0=制限回数以上回せることがある 1=制限回数ピッタリで固定

int		pause_visible;				// ポーズ中にブロックが見えるかどうかの設定

int		screenColor = 16;			// 現在の色数

int		ready_count[2];				// READY→GOの表示回数

int		nextskip;					// ツモスキップ（0=TOMOYOのみ 1=TOMOYO&FLASH 2=全モード 3=なし）

int		fldbgtype;					// フィールドに網目を表示

int		lastmode[2];				// 最後に選んだモード
int		lasttype[2];				// 最後に選んだゲームタイプ

int		timer_font_type;			// タイム表示のフォントの種類

int		enable_irs;					// IRS有効？

int		block_shadow;				// ブロックの影を表示
int		block_afterimage;			// ブロックの残像を表示
int		ace_frame;					// ACEモードで枠に飾りを表示
int		disp_waits;					// 現在のスピードを表示

// タイトルムービー
int		title_acnt = 0;				// 現在のフレーム
int		title_mov_f = 30;			// 最大コマ数（0にすると静止画）
int		mov_inter = 2;				// 1コマを表示するフレーム数

// 背景ムービー
int		back_acnt = 0;				// 現在のフレーム
int		back_mov_f[16];				// 最大コマ数（0にすると静止画）
int		back_mov_inter[16];			// 1コマを表示するフレーム数

int		wsoftlock = 0;				// 1にするとワールドルールで下入れしても即固定可能
int		rot180 = 2;					// 1にするとCボタンで180度回転 2にすると一部のルールのみ
int		english = 0;				// 0=Japanese 1=English

int		ace_irs;					// 新IRSを使用するかどうか

int		always_over1000[2];			// 常に[]が登場するフラグ

int		bgfadesw = 0;				// 背景フェードスイッチ
int		bgfadelv = 0;				// 背景フェードレベル
int		enable_bgfade = 1;			// 背景フェードを 0=使わない 1=使う

int		skip_blocklockflash;		// ブロックを置いたときの光る演出の時間を短縮
int		refresh_timing;				// 画面更新タイミング

int		lackblock_grayout;			// 1の場合はブロックの破片を灰色にする
int		squaremode[2];				// 正方形の有無
int		squarenum[2];				// 作った正方形の数

/* フィールドデータ */
int		fld[10 * 22 * 2];			// フィールドの状態  x + y * 10 + pl * 220
int		fldt[10 * 22 * 2];			// フィールドタイマー
int		fldi[10 * 22 * 2];			// フィールドアイテム
int		fldo[10 * 22 * 2];			// フィールドブロック[]フラグ（fldoの「o」はover1000の意味）
int		flds[10 * 22 * 2];			// フィールドブロック番号（破片を灰色化するときに使用）

int		fldbuf[10 * 22 * 2];		// フィールドバッファ(ミラーの演出に使用)
int		fldtbuf[10 * 22 * 2];		// フィールドタイマーバッファ(ミラーの演出に使用)
int		fldibuf[10 * 22 * 2];		// フィールドアイテムバッファ(ミラーの演出に使用)
int		fldobuf[10 * 22 * 2];		// フィールドブロック[]フラグバッファ(ミラーの演出に使用)
int		fldsbuf[10 * 22 * 2];		// フィールドブロック番号バッファ(ミラーの演出に使用)

/* NEXTブロック */
int		next[2];					// 次のブロック
int		nextb[1400 * 2];			// 次のブロックのリスト
int		nextb_fake[1400 * 2];		// 次のブロックのリスト（FAKE NEXT用）
int		nextc[2];					// 次に降るブロックカウンタ
int		nextb_max[2];				// NEXTブロックのループ間隔
int		nextwork[7 * 2];			// 次に降ってくるブロックのダブリ防止用

int		c_nblk[6 * 2];				// NEXTミノの色
int		item_nblk[6 * 2];			// NEXTミノのアイテムフラグ
int		o_nblk[6 * 2];				// NEXTミノの[]フラグ
int		rt_nblk[6 * 2];				// NEXTブロックの向き

int		n_bx[2];					// 次のブロックのX座標

int		ndelay[2];					// NEXTブロックの表示の遅延用

str		nextb_list;					// TOMOYOモードツモリスト
str		nextdengen_list;			// 電源パターンのツモリスト
str		nextdengen2_list;			// 電源パターンのツモリスト2

/* 操作中のブロック */
int		blk[2];						// 今落ちてくるブロック
int		bx[2], by[2], rt[2];		// ブロックの座標
int		c_cblk[2];					// 操作中テトラミノの色（操作中）
int		c_cblk_r[2];				// 操作中テトラミノの色（置いた後）
int		item[2];					// 現在のアイテム
int		o_cblk[2];					// 操作中テトラミノの[]フラグ
int		kickc[2];					// 床蹴りカウンタ
int		kickc2[2];					// ARS用床蹴りカウンタ
int		kickc3[2];					// 回転カウンタ

/* HOLDブロック */
int		hold[2];					// HOLD中のミノ
int		dhold[2];					// HOLD可不可
int		dhold2[2];					// HOLD可不可（ブロックオーダー用）
int		hold_used[2];				// HOLDした回数
int		c_hblk[2];					// HOLDミノの色
int		item_hblk[2];				// HOLDミノのアイテムフラグ
int		o_hblk[2];					// HOLDミノの[]フラグ

int		disable_hold;				// HOLD封印
int		enable_item_hold;			// アイテムをホールドできるか
int		hold_sound;					// HOLD音が鳴るタイミング(0:なし 1:IHS 2:非IHS 3:両方)
int		holdframetype;				// HOLDから出したブロックの枠の種類 0:太い 1:細い 2:なし

/* 落下速度とレベル */
int		sp[2];						// 落下スピード
int		wait1[2], wait2[2];			// 固定→次・消滅時の待ち時間
int		wait3[2], waitt[2];			// 設置から固定までのタイム・横溜め時間
int		bs[2], bk[2];				// ブロックの自然落下とくっつきのタイム
int		tc[2];						// 現在のレベル
int		tr[2];						// 10LVごとに1つ増える（主に速度上昇用）
int		speedtype[2];				// 落下スピードの種類

int		b_wait1[2], b_wait2[2];		// [バックアップ] 固定→次・消滅時の待ち時間
int		b_wait3[2], b_waitt[2];		// [バックアップ] 設置から固定までのタイム・横溜め時間
int		b_sp[2];					// [バックアップ] 落下速度
int		b_speedtype[2];				// [バックアップ] 落下スピードの種類

/* スコア */
int		hide_score;					// スコア非表示
int		sc[2];						// スコア
int		sdrop[2];					// スコア計算用（ハードドロップ）
int		qdrop[2];					// スコア計算用（ソフトドロップ）
int		cmbpts[2];					// スコア計算用（コンボ）

/* ライン */
int		erase[22 * 2];				// 消されるブロック
int		li[2];						// ライン数
int		endlines[2];				// ロール中に消した列数
int		c_norm[2];					// 達成ノルマ
int		m_norm[2];					// 目標ノルマ
int		line_count[4 * 2];			// ライン消し回数（シングル、ダブル、トリプル、ヘボリスの順）
int		skill[2];					// 4段消しした回数
int		lastblkline[2];				// 最後にブロックを置いたとき消えたライン数

int		enable_disp_lastline;		// ライン消し数を表示するかどうか
int		lastline[2];				// 最後のライン消し時のライン数
int		lastline_frame[2];			// 表示する残りフレーム

int		disp_lineinfo;				// ライン消し回数を表示するかどうか
int		d_disp_lineinfo;		// disp_lineinfoがデフォルトでONかどうか

/* コンボ */
int		combo[2], hebocombo[2];		// コンボ
int		combo2[2];					// 1ライン消しをカウントしないコンボ
int		tcombo[2];					// T-Spinコンボ
int		enable_combo;				// コンボボーナスの有無
int		display_combo;				// コンボ表示の有無

/* BACK TO BACK */
int		b_to_b[2];					// BACK TO BACKフラグ
int		b_to_b_count[2];			// BACK TO BACK回数
int		b_to_b_frame[2];			// BACK TO BACK表示フレーム
int		enable_b_to_b = 0;			// BACK TO BACKが有効かどうか
int		bonus_btb = 0;				// BACK TO BACKボーナスの有無

/* T-SPIN */
int		IsTspin[2];					// T-SPINしたかどうか
int		last_command[2];			// 最後にした操作（0=左右移動 1=空中で回転 2=接地状態で回転 3=落下）
int		tspin_frame[2];				// T-SPIN表示フレーム数
int		tspin_count[4 * 2];			// T-SPIN回数（ラインなし、シングル、ダブル、トリプルの順）
int		tspin_kick[2];				// 3-CORNER NO KICKのT-SPIN判定用（T-SPIN無効フラグ）
int		lasttspin[2];				// 最後にしたT-SPINの種類
int		tspin_type = 1;				// T-SPINの判定方法
int		bonus_tspin = 0;			// T-SPINボーナスの有無

/* キー入力 */
int		mp[2], mpc[2], mps[2 * 2];	// 前回のパッドの入力内容と時間
int		mp2[2], mpc2[2];			//hoge 前回のパッドの入力内容と時間(上下キーバージョン)
int		down_flag[2];				// 0:前回↓を使ってないor↓を離した 1:前回↓を使った
int		up_flag[2];					// 0:前回↑を使ってないor↑を離した 1:前回↑を使った
int		harddrop[2];				// ハードドロップ使用フラグ
int		softdrop[2];				// ソフトドロップ使用フラグ
int		downtype = 1;				// 下入れ＆上入れに制限を設けるかどうか（2=20G時のみ制限）
int		last_mp_check[2];			// 最後に横溜めをチェックしたフレーム
									//（1フレームに2回以上横溜め処理が行われるのを防ぐ）

/* DRS */
int		bk_D[2];					// DRS用下入れ時間
int		drs_floorkick = 0;			// DRSでARS系と同じ床蹴りをする
int		are_skipflag[2];			// 消去時間中のAREスキップ使用フラグ

/* 段位 */
int		grade[2];					// 現在の段位
int		gpoint[2];					// 現在の段位ポイント
int		gtime[2];					// 段位ポイント減少タイマー
int		gflash[2];					// 段位が上がった時に表示を光らせる時に使用

int		gradetype[2];				// 段位タイプ 0=NORMAL 1=HARD 2=EASY
int		hide_grade = 0;				// 段位非表示

int		min_sgrade = 4;				// この段から裏段位を表示

int		gskill[2];					// 段位で使う4段消し回数
int		gskbai[2];					// gskillで決まる段位上昇倍率

int		tc_20g[2];					// MASTER-HARDでのBGMフェードアウト予定レベル（COOLを出すと前倒し）
int		regretcancel[2];			// REGRETが出ても速度が遅くならないフラグ（1曲目→2曲目のときに1になる）

int		show_gpoint = 0;			// 1にすると段位ポイントが見える

int		time99[2];					// レベルストップ時間
int		timeN[2];					// ブロックを操作している時間(0-98)
int		ave_laptime3[2];			// セクションの平均移動時間
int		gup3rank[2];				// ランク0-2
int		gup3sp_adjust[2];			// ランクにあわせてスピード調整(0:やり直し 1:通常 2:スキップ)
int		qualityflag[2];				// 2回以上出ないように
int		skillflag[2];
int		tr2[2];						// 可変速レベル
int		tr_20g[2];					// 20Gになったときのtrの値
int		border_rank[2];

int		gup_down[2];				// COOLとREGRETの表示に使用 0=降格 1=昇格
int		gmflag1[2];					// Gm条件フラグ1
int		gmflag2[2];					// Gm条件フラグ2
int		gmflag1_e[2];				// gmflag1の判定をしたかどうかのフラグ
int		gmflag2_e[2];				// gmflag2の判定をしたかどうかのフラグ
int		gmflag_r[2];				// ロールクリアでGMになる権利のようなもの

/* メダル */
int		medal_ac[2];				// ACメダル
int		medal_st[2];				// STメダル
int		medal_sk[2];				// SKメダル
int		medal_co[2];				// COメダル
int		medal_visible_ac[2];		// メダル表示フラグ
int		medal_visible_st[2];
int		medal_visible_sk[2];
int		medal_visible_co[2];

/* 足切り */
int		timelimit[2 * 2];			// 足切りタイム
									// [0 + player * 2] = LV500の足切りタイム
									// [1 + player * 2] = LV1000の足切りタイム

int		timelimit_master[10];		// MASTERモード
int		timelimit_20G[10];			// 20Gモード
int		timelimit_deviln[10];		// DEVIL-NORMALモード
int		timelimit_devilh[10];		// DEVIL-HARDモード
int		timelimit_devild[10];		// DEVIL-DOOMモード

/* エンディング */
int		ending[2];					// エンディング中かどうか
int		edrec[2];					// エンディング経過時間
int		fastroll[2];				// 1の場合は高速ロール
int		end_f[2];					// 完全クリアフラグ
int		endingcnt[2];				// エンディング中の花火発生回数
int		ending_timeOn[2];			// エンディングタイマーが有効かどうか
int		ending_timelimit = 60 * 60;	// エンディングの時間
int		sound_ending_loop;			// エンディング曲をループさせるかどうか
int		sound_beginner_ending_loop;	// BEGINNERのエンディング曲をループさせるかどうか
int		staff_c[2];					// スタッフロールカウンタ
int		endtime[2];					// スタッフロール経過時間
int		staff_type[2];				// スタッフロールの画像の種類（0か1）

/* せり上がり */
int		upLines[2];					// 上昇してしまうライン数
int		hole;						// 対戦のときの穴の位置
int		uplinetype[2];				// せり上がりタイプ
int		r_bdowncnt[2];				// ブロックを置いた回数（せり上がり用）

int		r_enable[2];				// せり上がり有効／無効
int		r_start[2];					// せり上がり開始レベル
int		r_end[2];					// せり上がり終了レベル
int		r_inter[2];					// せり上がり間隔
int		def_rise_enable = 0;		// せり上がりデフォルト値
int		def_rise_start  = 500;
int		def_rise_end    = 999;
int		def_rise_inter  = 20;

int		b_r_enable[2];				// せり上がり有効／無効のバックアップ

int		ghole[2];					// GARBAGEミッションのときの穴の位置
int		upLineNo[2];				// せり上がりラインNo
int		upLineNoMax = 32;			// せり上がりフィールドのライン総数
int		upFld[256];					// せり上がりフィールド配列(上限は今のところ128ライン)

int		risecount[2];				// せり上がりが発生するまでのカウント

int		fldu[10 * 22 * 2];			// せり上がりフィールド（せり上がるブロックの形状を記憶）

int		show_rise_num;				// 1にするとせり上がり時にせり上がるライン数を表示

int		devil_doom_n_rise = 0;		// 1にするとDEVIL-DOOMでせり上がり間隔を一定にする

/* セクションタイム */
int		sectionTimer[2];			// 現在のセクションタイム（セクションが切り替わるたびにリセット）
int		now_sttime[30 * 2];			// セクションタイム記録
int		show_section_time = 0;		// セクションタイムを表示するかどうか
int		section_time_offset = 0;	// セクションタイム表示位置

/* HIDDEN */
int		hidden[2];
int		hidden_old[2], hiddentm[2], hiddeny[2], hiddenti[2], hiddenc[2];
int		b_hidden_old[2];
int		shadowtime[2];		// ブロックが見える時間
int		b_shadowtime[2];	// ↑のバックアップ
int		hidden_b_type;		// 1だとHIDDEN-Bでブロックを置いた瞬間の枠線を表示しない

/* CPUとナビゲーションシステム */
int		cpu_best_x[2];				// 最善手のX座標
int		cpu_best_y[2];				// 最善手のY座標
int		cpu_best_r[2];				// 最善手のブロックの方向
int		cpu_best_p[2];				// 最善手の評価点
int		cpu_ctrl[10 * 2];			// コンピュータの操作内容
int		cpu_flag[2];				// コンピュータが操作するかどうか
int		cpu_level[2];				// コンピュータのレベル
int		b_cpu_flag[2];				// [バックアップ] コンピュータが操作するかどうか
int		b_cpu_level[2];				// [バックアップ] コンピュータのレベル
int		cpu_hold[2];				// HOLDするかどうか
int		cpu_frame[2];				// CPUが最後に操作したフレーム

int		enable_navigation = 1;		// ナビゲーションシステムの有効／無効
									// 0=無効 1=BEGINNERのみ有効 2=全てのモードで有効
int		limit_navigation = 100;		// このレベルを過ぎるとナビゲーション終了

int		navigation_time[2];			// ナビゲーションタイマー
int		limit_time_navigation = 60;	// ナビゲーションブロックの表示時間

int		cpu_enable_setting[2];		// VSモード以外でのコンピュータのON/OFF
int		cpu_default_level[2];		// VSモード以外でのコンピュータのレベル

/* READY→GOの待ち時間 */
int		ready_start[2];				// ready開始
int		ready_end[2];				// ready終了
int		go_start[2];				// go開始
int		go_end[2];					// go終了

int		n_ready_start = 0;			// 通常 ready開始
int		n_ready_end = 50;			// 通常 ready終了
int		n_go_start = 55;			// 通常 go開始
int		n_go_end = 100;				// 通常 go終了

int		s_ready_start = 15;			// TOMOYO ready開始
int		s_ready_end = 30;			// TOMOYO ready終了
int		s_go_start = 135;			// TOMOYO go開始
int		s_go_end = 150;				// TOMOYO go終了

/* ルール */
int		rots[2];					// 現在のルール

int		def_rule_rot[9]        = {0, 0, 1, 1, 0, 0, 1, 1, 2};			// 回転法則 (0:ARS 1:SRS 2:DRS)
int		def_rule_hard_lock[9]  = {0, 0, 1, 1, 1, 0, 1, 0, 1};			// ハードドロップで固定
int		def_rule_soft_lock[9]  = {1, 1, 0, 0, 0, 1, 0, 1, 2};			// ソフトドロップで固定 (2は1G以上)
int		def_rule_soft_speed[9] = {1, 1, 1, 0, 0, 0, 0, 2, 2};			// ソフトドロップの速度
int		def_rule_are[9]        = {1, 1, 1, 1, 1, 1, 0, 1, 2};			// AREの有無（2はキャンセル機能付き）
int		def_rule_color[9]      = {0, 0, 1, 1, 1, 1, 1, 1, 0};			// ブロックの色
int		def_rule_lock_reset[9] = {0, 0, 1, 1, 1, 1, 1, 1, 0};			// 接地中に移動または回転で固定時間リセット
int		def_rule_lock_sound[9] = {0, 0, 0, 1, 1, 1, 1, 0, 0};			// 自分で固定したときに音を鳴らす
int		def_rule_ars_extrot[9] = {0, 1, 1, 1, 1, 1, 1, 1, 1};			// 凸と棒が床蹴りするかどうか(ARSの場合)
int		def_rule_lock_limit[9] = {0, 0, 10, 128, 128, 128, 0, 24, 0};	// 接地状態で移動できる回数 (0で無限)
int		def_rule_graphics[9]   = {0, 1, 2, 2, 1, 1, 3, 4, 7};			// ブロックの模様
int		def_rule_rot_limit[9]  = {0, 0, 8, 128, 128, 128, 0, 12, 0};	// 接地状態で回転できる回数 (0で無限)
int		def_rule_180rot[9]     = {0, 0, 0, 0, 0, 0, 0, 1, 1};			// 180度回転
int		def_rule_max_waitt[9]  = {99, 99, 99, 99, 99, 99, 10, 99, 10};	// 横溜め最大（99で無制限）
int		def_rule_oblk_bg[9]    = {0, 0, 0, 0, 0, 0, 1, 0, 0};			// []の時の背景（0:なし 1:白 2:黒）

int		rule_rot[10];				// 今のルール内容（CUSTOM以外は↑からコピーされる）
int		rule_hard_lock[10];
int		rule_soft_lock[10];
int		rule_soft_speed[10];
int		rule_are[10];
int		rule_color[10];
int		rule_lock_reset[10];
int		rule_lock_sound[10];
int		rule_ars_extrot[10];
int		rule_lock_limit[10];
int		rule_graphics[10];
int		rule_rot_limit[10];
int		rule_180rot[10];
int		rule_max_waitt[10];
int		rule_oblk_bg[10];

/* フィールド位置 */
int		foffset[2];					// フィールドの表示位置
int		boffset[2];					// ブロックやメニューの表示位置
int		soffset[2];					// スコアの表示位置
int		toffset[2];					// 「T-SPIN」「BACK TO BACK」などの表示位置
int		moffset;					// MISSIONモードの指令表示の位置

int		s_foffset = 112;			// SINGLE台用
int		s_boffset = 15;
int		s_soffset = 26;
int		s_toffset = 14;
int		s_moffset = 0;

int		d_foffset[2] = {16, 168};	// DUAL台用
int		d_boffset[2] = { 3,  22};
int		d_soffset[2] = {14,  33};
int		d_toffset[2] = { 2,  21};
int		d_moffset = 208;

int		v_foffset[2] = {16, 208};	// VERSUSモード用
int		v_boffset[2] = { 3,  27};

int		b_foffset[2];				// VERSUSから出たとき、元のフィールド位置に戻す時用のバックアップ
int		b_boffset[2];

int		ofs_x[2];					// フィールドを横に揺らす用
int		ofs_y[2];					// フィールドを縦に揺らす用

int		coffset;					// 操作状況表示の表示位置
int		s_coffset = 14;				// SINGLE用
int		d_coffset = 176;			// DUAL用
int		s_m_coffset = 221;			// SINGLE(MISSION)用
int		d_m_coffset = 115;			// DUAL(MISSION)用

/* 演出 */
int		obj[100], objx[100], objy[100], objv[100], objw[100], objj[100], objc[100];
int		obja[100], objp[100];

int		breakeffect = 2;			// 破壊エフェクト 0=なし 1=HEBORIS/TGM 2=TAP/TI(新) 3=TAP/TI(旧)
int		breakmax = 100;				// 画面内に表示可能なエフェクトの数（0～100）

int		breakgraphics = 1;			// breakeffect = 2のときの絵の種類
int		beginner_effect;			// BEGINNERモードの消去エフェクトを「POP OUT」で固定

int		beffect_speed;				// 破壊エフェクトの速度 0=自動 1以上=常時n倍速

/* 花火 */
int		hanabi_waiting[2];			// 発生待ち花火数
int		hanabi_frame[2];			// 発生するまでのフレーム数
int		hanabi_combo[2];			// HANABIコンボ補正用記憶域
int		hanabi_int[2];				// BEGINNERロール中の花火打ち上げ間隔

/* サウンド */
int		bgmlv = 0;					// 現在のBGM
int		fadelv = 0;					// フェードアウト用
int		bgm_change = 0;				// BGMを切り替えた回数
int		bgm = 0;					// BGM (0=なし 1=MIDI 2=WAV 3=MP3 4=MIDI(MULTI))
int		se = 1;						// 効果音の有無
int		rotate_sound = 0;			// 回転音の有無
int		move_sound = 0;				// 移動音の有無
int		sevolume = -100;			// 効果音の音量
int		bgmvolume = 0;				// BGMの音量
int		fadesetting;				// BGMフェードにかかる時間

int		bgm_loop_start[21];			// BGMのループ開始地点（-1:なし）
int		bgm_loop_end[21];			// BGMのループ終了地点（ここに来たらstartの所に戻る）

int		start_bgmlv[2];				// STANDARDで使ったBGMを記録
int		b_bgmlv;					// bgmlvのバックアップ

str		music_file_name[21];		// BGMのファイル名（heboris.iniで指定）

int		se_play[60];				// 効果音再生予約フラグ

/* リプレイ */
int		replayData[60 * 60 * 20];		// リプレイ保存用データ (最大20分まで)
int		replayData2[60 * 60 * 20];		// 2P用リプレイ保存用データ
int		playback = 0;					// リプレイ中か?
int		onRecord[2];					// リプレイ記録中フラグ
int		time2[2];						// リプレイ記録用カウンタ
int		replayauto;						// リプレイ自動操縦フラグ（0にすると手動操縦）
int		show_endmenu;					// ゲームオーバー後にリプレイセーブ画面を出す
int		replay_autosave;				// リプレイを自動セーブ
int		replayno;						// 現在見ているリプレイの番号（41=自動セーブされた最後のプレイ）

int		enable[41];						// リプレイが存在するかどうか
int		replay_gamemode[41];			// リプレイ選択画面用
int		replay_score[41];
int		replay_time[41];
int		replay_level[41];
int		replay_rots[41];
int		replay_tt[41];
int		replay_other[41];

/* デモ画面 */
int		demo = 0;						// デモモードか?
int		demotime;						// デモ画面経過時間
int		demokind = -1;					// デモの種類

/* PRACTICEモード関連の変数 */
str*	waitname[20];				// 設定名

int		syutugen[20],				// ブロックが固定されてから、次のブロックが出現するまでの時間
		syoukyo[20],				// ブロックが一列揃ったときの消滅の待ち時間
		settyaku[20],				// ブロックが地面に到達してから、接着されるまでの時間。99にすると無限
		yokotame[20],				// 横溜めに必要な時間
		speed[20],					// 落下速度
		fps[20],					// FPS
		pbgm[20],					// BGM
		waitkey[20];				// ショートカットキー

int		p_setting = 0;				// 現在の設定
int		p_def_setting = 0;			// デフォルトの設定

int		b_hidden[2];				// 各種ギミックON/OFFフラグのバックアップ
int		b_isfmirror[2];
int		b_isrollroll[2];
int		b_isxray[2];
int		b_iscolor[2];
int		b_isblind[2];
int		b_isthunder[2];
int		b_isUDLRreverse[2];
int		b_isRotateLock[2];
int		b_ishidenext[2];
int		b_heboGB[2];
int		b_squaremode[2];

int		p_backno = 0;				// PRACTICEモードの背景
int		p_fps = 60;					// PRACTICEモード用のFPS

int		vslevel[2];					// カーソル位置

int		p_leveltype;				// レベルアップの種類
int		p_timelimit;				// 制限時間
int		p_goal;						// ゴール
int		p_staffroll;				// スタッフロールの有無

int		p_def_leveltype;			// レベルアップの種類のデフォルト
int		p_def_timelimit;			// 制限時間のデフォルト
int		p_def_goal;					// ゴールのデフォルト
int		p_def_staffroll;			// スタッフロールの有無のデフォルト

int		p_replay_save_enable;		// リプレイセーブ可能フラグ

/* TOMOYOモード／FLASHモード関連の変数 */
int		stage[2];					// ステージ番号
int		sclear[2];					// ステージクリアしたか
int		rest_pblock[2];				// 残りプラチナブロック数

int		stime[2];					// ステージタイム
int		ltime[2];					// リミットタイム（ACEモードなどでも使用）

int		clearnum[2];				// タイムオーバー／スキップせずにクリアしたステージ数
int		clearp[2];					// クリア率

int		pass_flg[2];				// ツモ送りフラグ(連続入力防止用)

int		start_stage[2];				// どのステージから始めたか
int		start_nextc[2];				// スタート時のnextc

int		laststage[2];				// TOMOYOモードの最終ステージ

int		stage_nextc[2];				// ステージ開始時のnextc

int		stage_skip_frame[20 * 2];	// ステージスキップを使ったフレーム
int		stage_skip_used[2];			// ステージスキップを使った回数

int		stage_skip_mpc[2];			// ステージスキップキーを押している時間
int		stage_skip_tame = 60;		// このフレーム以上ステージスキップキーを押しつづけるとスキップ発動

int		flash_bonus_points[2];		// FLASHモードのボーナス点
int		flash_bonus_count[2];		// ボーナス点減少カウンタ
int		flash_continue[2];			// コンティニュー使用フラグ
int		flash_cont_stage[2];		// コンティニューしたときの復活地点（2回以上連続で失敗したときに先に進ませない）
int		flash_edit[2];				// FLASH-EDITかどうか

int		tomoyo_waits[2];			// DEVIL500ギミックON/OFF
int		min_speed[2];				// TOMOYOモードの最低スピード
int		enable_minspeed = 0;		// TOMOYOモードでスピード下限を有効にするかどうか

int		tomoyo_rise_fld[10 * 20 * 2];	// TOMOYO用せり上がりフィールド 最大20段
int		tomoyo_rise[2];					// せり上がりON/OFF兼せり上がり間隔
int		tomoyo_rise_t[2];				// せり上がりカウント
int		tomoyo_rise_edit[2];			// TOMOYOせり上がりエディタフラグ

int		tomoyo_timebonus[2];		// TOMOYO タイム延長の有無
int		tomoyo_no_stage_time[2];	// 1の場合はステージタイム無限
int		tomoyo_bgm[2];				// TOMOYOのBGM

int		tomoyo_dual[2];				// TOMOYO EHEARTラストステージギミック
int		tomoyo_dual_enable[2];		// 今ラストステージギミックが有効かどうか
int		tomoyo_ehfinal_c[2];		// TOMOYO EHEARTラストステージギミック用のカウンタ

int		tomoyo_ltime_over[2];		// 1の場合はリミットタイムが切れてもブロックを置くまではプレイ続行

int		tomoyo_clear_erase;			// 1の場合はTOMOYOモードでステージクリア時にブロックを消す演出を出す

int		platinaerase_cnt[2];		// プラチナブロック消去サウンドを鳴らす回数
int		ext_s[2];					// 時間増加の演出（表示）用
int		timeextend_snd_cnt[2];		// 時間増加の演出（SE）用

/* MISSIONモードの変数 */
int		c_mission = 0;				// 現在のミッション番号
int		mission_file = 0;			// ファイル番号
int		clear_mission = 0;			// ミッションをクリアしたときの消したライン数

int		mission_type[30];			// 問題の種類
int		mission_norm[30];			// 問題のノルマ
int		mission_time[30];			// 問題の制限時間
int		mission_end[30];			// エンディングフラグ
int		mission_lv[30];				// 落下速度レベル
int		mission_erase[30];			// 上から消去するライン数
int		mission_opt_1[30];			// ミッションによって異なる追加情報１
int		mission_opt_2[30];			// ミッションによって異なる追加情報２
int		mission_opt_3[30];			// ミッションによって異なる追加情報３
int		mission_bgm[30];			// BGM
int		mission_opt_4[30];			// ミッションによって異なる追加情報４
int		mission_opt_5[30];			// ミッションによって異なる追加情報５
int		mission_opt_6[30];			// ミッションによって異なる追加情報６
int		mission_bg[30];				// 背景
int		mission_opt_7[30];			// ミッションによって異なる追加情報７
int		mission_opt_8[30];			// ミッションによって異なる追加情報８
int		mission_opt_9[30];			// ミッションによって異なる追加情報９
int		mission_opt_10[30];			// ミッションによって異なる追加情報10
int		mission_hide_info;			// 画面左の指令を表示しないフラグ
int		mission_clear_anim;			// オールクリア時に出る演出の種類

int		cycle[4];					// サイクル用
int		target_cleared[1000];		// ターゲットのステージ出現済みフラグ（同じ面がまた出るのを防ぐ）

int		eraser_lines[4];			// イレイサーのライン位置
int		eraser_cleared[4];			// 既に消したかどうかのフラグ
int		eraser_now_lines;			// 現在画面内に存在しているイレイサーのラインの数
int		eraser_now_pattern = 0;		// イレイサーの現在のパターン

int		start_mission = 0;			// どのミッションから始めたか
int		mission_extra = 0;			// ミッションでEXステージへ行く権利
int		mission_clear_flag = 0;		// ミッションクリア後の処理で使用

str		mission_course_name;		// ミッションモードのコース名

/* アイテムやギミックの変数 */
int		item_name[2];				// フィールド右上に表示するアイテム名
int		item_g[2];					// アイテムゲージ
int		item_t[2];					// アイテムの効果時間
int		item_coming[2];				// 出現待ちアイテム
int		item_waiting[2];			// 発動待ちアイテム
int		itemappear_c[2];			// アイテムゲージが光る演出用
int		item_mode[2];				// アイテムON/OFF
int		b_item_mode[2];				// アイテムON/OFFのバックアップ
int		item_interval = 20;			// アイテムが出現する間隔
int		item_all[2];				// 出現する可能性のあるアイテムの種類の数
int		item_timer[2];				// 時限性アイテムのタイマー

int		isfmirror[2];				// 現在の面がミラーか
int		fmirror_cnt[2];				// ミラー用カウンタ
int		p_fmirror_interval = 3;		// フィールドミラー間隔
int		p_fmirror_timer = 10;		// フィールドミラータイマー(ミラー化にかかる時間) 
int		stopmirror_flag[2];			// ミラー停止フラグ
int		field_spin[2];				// フィールド枠の回転状況（-1または20：回転してない）

int		rollroll_flag[2];			// 現在の面がロールロールか
int		isrollroll[2];				// 現在のツモがロールロールか
int		p_rollroll_interval = 4;	// ロールロール間隔
int		p_rollroll_timer = 30;		// ロールロールタイマー(回転するまでの時間) 

// X-RAY用
int		xray_flag[2];				// 現在の面がX-RAYか
int		isxray[2];					// 現在X-RAY状態か
int		xray_counter[2];			// X-RAY用カウンタ
int		p_xray_interval = 2;		// X-RAY間隔
int		p_xray_frame = 36;			// X-RAY周期フレーム数

// COLOR用
int		color_tbl[40] = {
	10, 10, 9, 9, 8, 8, 8, 7, 7, 7,
	6, 6, 6, 5, 5, 5, 4, 4, 4, 4,
	3, 3, 3, 3, 2, 2, 2, 2, 1, 1,
	1, 1, 0, 0, 0, 0, 0, 0, 0, 0
};

int		color_flag[2];				// 現在の面がCOLORか
int		iscolor[2];					// 現在COLOR状態か
int		color_counter[2];			// COLOR用カウンタ

int		isblind[2];					// 今BLIND状態かどうか
int		blind_flag[2];				// この面でのBLINDの有無

int		isRotateLock[2];			// 回転不可

int		ishidenext[2];				// NEXT不可視
int		hnext_flag[2];				// HIDE NEXTギミックON/OFF
int		hnext_timer[2];				// HIDE NEXT用タイマー

int		ismagnetblock[2];			// MAGNET BLOCK
int		istimestop[2];				// TIME STOP
int		isholdlock[2];				// HOLD LOCK

int		isUDLRreverse[2];			// 上下左右逆転
int		isUDreverse[2];				// ↑↓ REVERSE
int		isLRreverse[2];				// →← REVERSE

int		isboost[2];					// BOOST FIRE
int		boostbak_sp[2];				// 速度のバックアップ(BOOST FIRE用)
int		boostbak_settyaku[2];		// 接着時間のバックアップ(BOOST FIRE用)

int		isfever[2];					// FEVER!!
int		isremote[2];				// REMOTE CONTROL
int		isdark[2];					// DARK BLOCK
int		isUPdelfield[2];			// ↑ DEL FIELD
int		isDWdelfield[2];			// ↓ DEL FIELD
int		isdeleven[2];				// DEL EVEN
int		istrance[2];				// TRANCE FORM

int		dolaser[2];					// LASER
int		lasernum[2];				// レーザーの本数
int		laserpos[4 * 2];			// レーザー位置
int		rapid_c[2];					// ボタン連打数（レーザーの増加に使用）

int		donega[2];					// NEGA FIELD

int		doshotgun[2];				// SHOT GUN!
int		shotgunpos[22 * 2];

int		doexchg[2];					// EXCHG FIELD

int		isbanana[2];				// SHUFFLE FIELD
int		banana_pos[10 * 2];
int		banana_c[2];

int		dorulet[2];					// RANDOM

int		isFreefall[2];				// FREE FALL
int		Ff_rerise[2];				// FREE FALL再せり上がりライン数
int		enable_ff_rerise;			// 1の場合はFREE FALL後に再せり上がり

int		isLmovfield[2];				// ← MOV FIELD
int		isRmovfield[2];				// → MOV FIELD
int		do180field[2];				// 180゜FIELD

int		do16t[2];					// 16t
int		isreflect[2];				// REFLECT
int		isdouble[2];				// DOUBLE
int		isallclear[2];				// ALL CLEAR
int		ismiss[2];					// MISS
int		docopyfld[2];				// COPY FIELD
int		isfakenext[2];				// FAKE NEXT
int		item_monochrome[2];			// [] BLOCK

int		isthunder[2];				// THUNDERギミックのON/OFF
int		thunder_timer;

int		heboGB[2];					// オールドスタイル

int		item_num;					// アイテムの総数
int		item_switch[39];			// 特定のアイテムが出現するかどうか

int		item_gauge_uptype;			// 1の場合はラインを消すとアイテムゲージ上昇

int		itemhistory[2 * 5];			// アイテムの履歴

int		item_pro[50] = 				// アイテム出現率
{
	5,8,5,9,6,3,5,4,6,8,
	4,7,5,6,5,3,6,6,5,4,
	9,1,5,1,7,7,8,3,3,5,
	7,4,3,3,1,5,3,2,7,5,
	5,5,5,5,5,5,5,5,5,5
};

int		item_pronum;				// item_proの合計（自動計算）

/* VERSUSモードの変数 */
int		vs_goal_level;				// VSモードのゴールレベル（0:なし）
int		vs_goal_type;				// VSモードのゴール種類（0:レベル 1:ライン 2:マラソン）
int		vs_timelimit;				// VSモードの制限時間（0:なし）
int		vs_item;					// VSモードのアイテムON/OFF
int		vs_rise;					// VSモードのせり上がりON/OFF

/* ランキング変数 */

// 通常のランキング
// 3名 × 10ルール × 40カテゴリ（カテゴリ≠モードということに注意）
str*	rkname[3 * 10 * 40];			// 名前
int		rkdata1[3 * 10 * 40];			// 判定要素１
int		rkdata2[3 * 10 * 40];			// 判定要素２
int		rktime[3 * 10 * 40];			// タイム
int		rkclear[3 * 10 * 40];			// 0=途中で窒息 1=ロール失敗 2=ロールクリア
int		rkac[3 * 10 * 40];				// ACメダル
int		rkst[3 * 10 * 40];				// STメダル
int		rksk[3 * 10 * 40];				// SKメダル
int		rkco[3 * 10 * 40];				// COメダル

// STANDARDランキング
// 5名 × 10ルール × 4カテゴリ（カテゴリ≠モードということに注意）
str*	std_rkname[5 * 10 * 4];			// 名前
int		std_rkscore[5 * 10 * 4];		// スコア
int		std_rklines[5 * 10 * 4];		// ライン
int		std_rktime[5 * 10 * 4];			// タイム
int		std_wait1[5 * 10 * 4];			// wait1
int		std_wait2[5 * 10 * 4];			// wait2
int		std_wait3[5 * 10 * 4];			// wait3
int		std_waitt[5 * 10 * 4];			// waitt
int		std_speed[5 * 10 * 4];			// sp

// セクションタイムランキング
// 30セクション × 10ルール × 40カテゴリ
str*	stname[30 * 10 * 40];			// 名前
int		sttime[30 * 10 * 40];			// タイム
int		stend[30 * 10 * 40];			// 0=途中で窒息 1=ロール失敗 2=ロールクリア

/* プレイヤーデータ関連の変数 */
int		user_enable[2];						// プレイヤーデータを使用しているかどうか
str		user_name[2];						// 現在のプレイヤー名

int		user_line_count[4 * 2];				// ライン消し回数
int		user_playcount[2];					// プレイ回数

int		user_beginner_tamaya[2];			// BEGINNER-TAMAYAの花火総数
int		user_beginner_novice[2];			// BEGINNER-NOVICEのスコア総数

int		user_master_normal[2];				// MASTER-NORMALの最高段位

int		user_master_hard_admit[2];			// MASTER-HARDの認定段位
int		user_master_hard_provisional[2];	// MASTER-HARDの最高暫定段位
int		user_master_hard_grade_his[2 * 5];	// 段位履歴
int		user_master_hard_grade_pasttime[2];	// 最後の試験からどれだけ経ったか？

int		user_devil_normal[2];				// DEVIL-NORMALの最高レベル
int		user_devil_hard[2];					// DEVIL-HARDの最高段位
int		user_devil_doom[2];					// DEVIL-DOOMの最高段位

int		user_tomoyo_normal[2];				// TOMOYO-NORMALの最高ステージ
int		user_tomoyo_eheart[2];				// TOMOYO-EHEARTの最高ステージ
int		user_tomoyo_target[2];				// TOMOYO-TARGETの最高ステージ
int		user_tomoyo_flash[2];				// TOMOYO-FLASHの最高ステージ

int		user_ace[5 * 2];					// ACEモードのベストタイム

/* 段位試験 */
int		examination[2];						// 試験中？ 0:なし 1:昇格試験 2:降格試験
int		exam_grade[2];						// 試験段位
int		purupuru[2];						// フィールドのプルプル

/* ROT. RELAY用変数 */
int		start_rots[2];						// スタート時のルール
int		rot_used_flag[10 * 2];				// ルール使用済みフラグ
int		rot_relay_record[3 * 2];			// 各ルールのスコア

/* 定数類 */

// BGMフェードアウトテーブル（heboris.iniで設定させるのでこの値はほぼ無意味）
int		bgmfadestart[10 * 6] = {
	 185, 10000, 10000, 10000, 10000, 10000,	// BEGINNER-TAMAYA
	 485,   685, 10000, 10000, 10000, 10000,	// MASTER-NORMAL
	  -1,   485, 10000, 10000, 10000, 10000,	// 20G-NORMAL
	  -1,    -1,   485,   685,   985, 10000,	// DEVIL-DOOM
	 490, 10000, 10000, 10000, 10000, 10000,	// HEBO+
	  -1,   280,   480, 10000, 10000, 10000,	// DEVIL-NORMAL
	 280, 10000, 10000, 10000, 10000, 10000,	// BEGINNER-NOVICE
	  -1,    -1,   485,   685,   985, 10000,	// DEVIL-HARD
	 490, 10000, 10000, 10000, 10000, 10000,	// MASTER-EASY
	  -1, 10000, 10000, 10000, 10000, 10000,	// 20G-EASY
};

// ACEモードBGMフェードアウトテーブル（heboris.iniで設定させるのでこの値はほぼ無意味）
int		ace_bgmfadestart[4 * 5] = {
	   45,    95,   145, 10000,		// NORMAL
	   45,    95,   145, 10000,		// HI-SPEED1
	   45,    95,   145, 10000,		// HI-SPEED2
	   35,    95,   145, 10000,		// ANOTHER
	  145, 10000, 10000, 10000,		// ANOTHER2
};

// ACEモードBGM切り替え用（heboris.iniで設定させるのでこの値はほぼ無意味）
int		ace_bgmlist[3 * 5] = {
	15, 1, 2,	// NORMAL曲
	0, 2, 5,	// HI-SPEED1曲
	2, 5, 3,	// HI-SPEED2曲
	5, 3, 4,	// ANOTHER曲
	4, 4, 4		// ANOTHER2曲
};

// ACE200モードBGMフェードアウトテーブル（heboris.iniで設定させるのでこの値はほぼ無意味）
int		ace200_bgmfadestart[4 * 4] = {
	  45,   145,   195, 10000,		// BASIC
	  45,   145,   195, 10000,		// HELL
	  45,   145,   195, 10000,		// HELL-X
	 195, 10000, 10000, 10000,		// VOID
};

// ACE200モードBGM切り替え用（heboris.iniで設定させるのでこの値はほぼ無意味）
int		ace200_bgmlist[3 * 4] = {
	 0,  1,  2,		// BASIC
	19, 18, 16,		// HELL
	 3,  4, 17,		// HELL-X
	 5,  5,  5,		// VOID
};

int		flash_bgmlist[4];	// FLASHモードのBGMリスト
int		final_bgm;			// FINALモードのBGM
int		marathon_bgm[3];	// MARATHONモードのBGM

// NORMAL段位で段位ポイントが1つ減るまでの時間
int		glimit[31] = 
{
	100, 80, 80, 60, 50, 50, 40, 40, 40,	//  0～ 8
	 30, 30, 25, 25, 20, 20, 20, 15, 15,	//  9～17
	 10,  8,  5,  5,  5,  5,  5,  5,  4,	// 18～26
	  5,  5,  4,  3							// 27
};

// HARD段位でランクごとの基準タイム
int		border_time[20] = 
{
	17, 15, 14, 13, 10, 10, 12, 13, 13,		//  0～ 8
	13, 13, 13, 13, 13, 13, 12, 12, 11,		//  9～17
	11, 10									// 18～20
};

// HARD段位でランクごとの基準タイム (repversw <= 6)
int		border_time6[20] = 
{
	17, 15, 14, 13, 10, 10, 11, 12, 12,		//  0～ 8
	12, 12, 12, 12, 12, 11, 11, 10, 10,		//  9～17
	 9,  9									// 18～20
};

// MASTER-EASYの基準スコア
int		master_easy_score_table[18] = 
{
	   400,   800,  1400,  2000,  3500,  5500,  8000,  12000,			// 8～1
	 16000, 22000, 30000, 40000, 52000, 66000, 82000, 100000, 120000,	// S1～S9
	126000																// GM
};

// DEVIL-HARDモードのREGRET基準タイム
int		devil_hard_regret_border[13] = 
{
//	 0**,  1**,  2**,  3**,  4**,  5**,  6**,  7**,  8**,  9**, 10**, 11**, 12**
	5400, 5400, 5400, 5400, 5400, 3600, 3600, 3600, 3600, 3600, 3300, 3300, 3300
};

// DEVIL-DOOMモードのREGRET基準タイム
int		devil_doom_regret_border[13] = 
{
//	 0**,  1**,  2**,  3**,  4**,  5**,  6**,  7**,  8**,  9**, 10**, 11**, 12**
	3600, 3600, 3600, 3600, 3600, 3300, 3300, 3300, 3300, 3300, 3000, 3000, 3000
};

int		fontc[10]  = {9,1,2,3,8,4,2,6,7,5};	// 題字の色 0:白 1:青 2:赤 3:桃 4:緑 5:黄 6:空 7:橙 8:紫 9:藍
int		digitc[10] = {5,5,7,7,5,5,7,7,5,7};	// 数字の色

int		modecolor[19] = {4,1,5,2,1,5,3,0,0,0,6,2,0,4,2,3,2,1,0};			// モード名表示用
int		field_frame_color[19] = {0,1,1,2,1,3,4,5,5,7,6,2,5,0,2,4,2,3,5};	// フィールド枠の色

int		modecolor2[12] = {4,1,2,3,0,0,2,0,1,1,0,5};

int		tame1 = 25,	//hoge 左右の入れっぱなしで高速移動するまでの時間
		tame2 = 3,	//hoge 高速移動の速さ(少ないほど速い)。
		tame3 = 25,	//hoge ↑の上下版
		tame4 = 3;	//hoge ↑の上下版

int		fldisno = 44;		// fldiにおいてスクウェア用の画像がある場所(場所のカウントは→矢印が30番目)
int		fldigsno = 45;		// fldiにおいてGOLDENスクウェア用の画像がある場所
int		fldihardno = 43;	// fldiにおいてハードブロックの画像がある場所

str		RankString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ.,- 0123456789<=>?!#$%&'()=pq";

int		key_enter = 0x1C;	// ENTERキーのキーコード
int		key_del = 0xD3;		// DELETEキーのキーコード
int		key_bs = 0x0E;		// BACKSPACEキーのキーコード

int		loopFlag = 1;		// 0になると全てのループを無条件で抜ける

int		c_repver = 8;		// リプレイバージョン
str		version = "LITE32.13EX (07/07/04)";

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   設定ファイルのインポート
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
	include "option.def"				// Setting.exeの設定
	include "script/speed.def"			// 速度設定
	include "script/block.def"			// ブロックデータ
	include "script/message.def"		// メッセージデータ
	include "script/mission_info.def"	// MISSIONモードのメッセージデータ

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ソースファイルのインポート
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
	include "script/flexdraw.c"		// 高解像度対応描画関数
	include "script/screencfg.c"	// SCREEN.SAV関連の関数
	include "script/move.c"			// ブロックの操作
	include "script/ranking.c"		// ランキング
	include "script/stdranking.c"	// SIMPLEモードのランキング
	include "script/view.c"			// 表示
	include "script/effect.c"		// 演出
	include "script/sound.c"		// 音楽
	include "script/favorites.c"	// FAVORITES
	include "script/practice.c"		// PRACTICEモード
	include "script/tomoyo.c"		// TOMOYOモード
	include "script/replay.c"		// リプレイ
	include "script/config.c"		// 設定画面
	include "script/sectime.c"		// セクションタイムランキング
	include "script/mission.c"		// MISSIONモード
	include "script/cpu.c"			// コンピュータの思考ルーチン
	include "script/grade.c"		// 段位上昇判定
	include "script/item.c"			// アイテム
	include "script/user.c"			// プレイヤーデータ

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   メイン
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void main() {
	int i;
	
	// 設定ファイル読み込み
	include "heboris.ini"
	include "heboris_user.ini"
	
	// グラフィック・サウンド読み込み
	initialize();
	
	// FPS設定 #LITE23
	SetFPS(main_fps);
	
	// 設定ファイルが存在しない場合はキーボードの初期設定画面へ #LITE24
	if(first_setting) {
		config_make_default();
		config_input_keyboard(0, 1);
		config_lang();
		config_save();
	}
	
	// メインループ
	while(loopFlag) {
		// 効果音・BGM停止
		StopAllWaves();
		StopAllBGM();
		
		// タイトル画面
		title();
		
		// ゲームメイン処理
		flag = 0;
		
		while(loopFlag) {
			if(refresh_timing) spriteTime();
			KeyInput();
			
			// グローバルカウンタ増加
			count = ( count + 1 ) % 65536;
			
			// 背景処理
			if((demo) && (!demokind)) viewDarkTitle();
			else if(!skip_viewbg) viewBack();
			
			noredraw = 0;
			
			// リプレイ
			if(playback && !demo && replayauto) {
				playback = 0;
				
				// 早送り
				if((getPushState(0, 4) && !cpu_flag[0]) || (getPushState(1, 4) && !cpu_flag[1]))
					fast = 5;
				
				if( !((getPressState(0, 4) && !cpu_flag[0]) || (getPressState(1, 4) && !cpu_flag[1])) )
					fast = 0;
				
				if( (!fast) && ((getPressState(0, 0) && !cpu_flag[0]) || (getPressState(1, 0) && !cpu_flag[1])) )
					fast = 3;
				
				if( (!fast) && ((getPressState(0, 1) && !cpu_flag[0]) || (getPressState(1, 1) && !cpu_flag[1])) )
					fast = 1;
				
				// Bボタンでタイトルに戻る
				if((getPushState(0, 5) && !cpu_flag[0]) || (getPushState(1, 5) && !cpu_flag[1]))
					flag = 1;
				
				// HOLDボタンで手動操作
				if((getPushState(0, 7) && !cpu_flag[0]) || (getPushState(1, 7) && !cpu_flag[1])) {
					PlaySE(0);
					fast = 0;
					replayauto = 0;
				}
				
				playback = 1;
			}
			
			// フィールド背景を表示
			viewFieldBackground(0);
			if(maxPlay) viewFieldBackground(1);
			
			// スタッフロール #LITE10
			if(ending[0] || ending[1]) {
				for(i = 0; i < fast + 1; i++) {
					staffRoll(0);
					if(maxPlay) staffRoll(1);
				}
			}
			
			// フィールド表示
			viewField(0);
			if(maxPlay) viewField(1);
			
			// ゲーム処理
			for(i = 0; i < fast + 1; i++) {
				playerExecute();
				
				if(spawn_y_type) {
					viewFieldFrame(0, 0);
					if(maxPlay) viewFieldFrame(1, 0);
				}
				
				if( i > 0 ) objectExecute();
				noredraw = 1;
			}
			
			// ミッションモードの枠
			if(gameMode[0] == 8) viewMissionFrame();
			
			// スコア表示
			if((!demo) || (demokind)) viewScore();
			
			// チュートリアル表示
			if((demo) && (!demokind)) viewHowToPlay();
			
			// 演出処理
			objectExecute();
			
			// ポーズ・NEXT隠しなど
			lastProc();
			
			// flag変数が1だったらタイトルに戻る
			if(flag > 0) {
				if(gameMode[0] == 4) leaveVersusMode();
				for(i = 0; i < 10; i++) TextLayerOff(i);
				if(playback || demo) restoreSetups();
				isUDLRreverse[0] = 0;
				isUDLRreverse[1] = 0;
				playback = 0;
				demo = 0;
				bgfadesw = 0;
				onRecord[0] = 0;
				onRecord[1] = 0;
				break;
			}
			
			if(!refresh_timing) spriteTime();
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   タイトル
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void title() {
	int		player, pl, mode, game, i, democ;
	
	// 初期設定
	count = 0;
	democ = 0;
	mode = 0;
	game = 0;
	
	demo = 0;
	playback = 0;
	replayauto = 0;
	replayno = 0;
	
	cpu_flag[0] = 0;
	cpu_flag[1] = 0;
	
	user_enable[0] = 0;
	user_enable[1] = 0;
	
	// タイトルBGM再生
	if(bgm == 1) {
		if( !IsPlayMIDI() ) ReplayMIDI();
	} else if(bgm >= 2) {
		bgmlv = 11;
		changeBGM();
	}
	
	// プレイ人数をバックアップ
	b_maxPlay = maxPlay;
	setFieldPosition(maxPlay);
	
	// 設定内容をバックアップ
	backupSetups();
	
	// ループ開始
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();

		count++;

		// タイトル画像を描く
		if(!title_mov_f) {	// 静止画
			ExBltFast(8,0,0);
		} else {
			ExBltFastRect(8, 0, 0, (title_acnt / 10) * 320, (title_acnt % 10) * 240, 320, 240);
			
			if(count % mov_inter == 0)
				title_acnt++;
			if(title_acnt > title_mov_f -1)
				title_acnt = 0;
			
			ExBlt(7, 0, 0);
		}
		
		// 著作権表示
		printFont( 6, 28, "a 1998-2002 KENJI HOSHIMOTO", 0 );

		// バージョン表示
		printFont( 27, 14, "VERSION 1.60", 4 );
		printFont( 27, 15, "(2002/03/31)", 6 );
		
		sprintf(string[0], "%39s", version);
		printFont(0, 16, string[0], 1);
		
		// モード0: ボタン入力待ち
		if(mode == 0) {
			// スタートボタンを押してください
			if(count % 80 < 40) {
				ExBltRect(49,53,154,0,204,213,19);
			}
			
			// デモ画面
			democ++;
			if(democ > 900) {
				doDemoMode();
				mode = 2;
			}
			
			// どちらかのスタートボタンが押されたらモード1へ
			for(player = 0; player <= maxPlay; player++) {
				if(getPushState(player, 4)) {
					democ = 0;
					PlaySE(10);
					mode = 1;
				}
				
				if(getPushState(player, 7)) {
					democ = 901;
				}
			}
		}
		// モード1: モードセレクト
		else if(mode == 1)
		{
			// モード一覧表示
			printFont(13, 18 + game * 2, "b", fontc[rots[0]]);
			
			printFont(14, 18, "GAME START",           (fontc[rots[0]]) * (game == 0));
			printFont(14, 20, "REPLAY",               (fontc[rots[0]]) * (game == 1));
			printFont(14, 22, "NORMAL RANKING",       (fontc[rots[0]]) * (game == 2));
			printFont(14, 24, "SECTION TIME RANKING", (fontc[rots[0]]) * (game == 3));
			printFont(14, 26, "CONFIG",               (fontc[rots[0]]) * (game == 4));
			
			// どちらかのジョイスティックでモードセレクト
			for(player = 0; player <= maxPlay; player++) {
				padRepeat2(player);
				
				// 上へ
				if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
				if(getPressState(player, 0)) {
					PlaySE(5);
					game--;
					if(game < 0) game = 4;
				}

				// 下へ
				if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
				if(getPressState(player, 1)) {
					PlaySE(5);
					game++;
					if(game > 4) game = 0;
				}

				// キャンセル
				if(getPushState(player, 5)) {
					democ = 0;
					mode = 0;
				}

				// 決定
				if(getPushState(player, 4)) {
					PlaySE(10);
					mode = 2;

					// スタート
					if( game == 0 )
					{
						enterSoloMode(player);
						break;
					}
					// リプレイ
					else if( game == 1 )
					{
						mode = ReplaySelectProc();
						if(!mode) restoreSetups();
					}
					// ランキング
					else if( game == 2 )
					{
						RankingProc2();
						mode = 0;
					}
					// セクションタイムランキング
					else if( game == 3 )
					{
						ST_RankingView();
						mode = 0;
					}
					// 設定
					else if( game == 4 )
					{
						StopAllBGM();
						config_menu();	// config.c
						mode = 0;
					}
				}
			}
		}
		else
		// モード2: ループを抜けてゲーム画面へ
		{
			break;
		}
		
		if(!refresh_timing) spriteTime();
	}
	
	// BGM停止
	StopAllBGM();
}

// モードセレクトに入る
void enterSoloMode(int player) {
	int i;
	
	gameMode[0] = 0;
	gameMode[1] = 0;
	
	versusInit(0);
	if(maxPlay) versusInit(1);
	gameAllInit();
	
	stat[player] = 2;					// モードセレクト
	for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	
	hnext[0] = dispnext;
	hnext[1] = dispnext;
}

// VERSUS MODEに入る
void enterVersusMode() {
	int player;
	
	StopAllBGM();
	
	gameAllInit();			// 初期化処理
	
	gameMode[0] = 4;		// VSモード
	gameMode[1] = 4;
	
	versusInit(0);
	versusInit(1);
	setNextBlockColors(0, 1);
	setNextBlockColors(1, 1);
	
	item_mode[0] = vs_item;
	item_mode[1] = vs_item;
	r_enable[0] = vs_rise;
	r_enable[1] = vs_rise;
	
	setVersusField();
	
	for(player = 0; player < 2; player++) {
		stat[player] = 1;				// ブロックシャッター実行
		statc[player * 10] = 0;			// ステータスカウンタを0に
		statc[player * 10 + 1] = 9;		// シャッター後はステータスNo.9
		hnext[player] = dispnext;
	}
}

// VERSUSモード用のフィールド位置を設定
void setVersusField() {
	int player;
	
	b_maxPlay = maxPlay;	// プレイ人数をバックアップ
	maxPlay = 1;			// 一時的にDUAL台にする
	
	backno = 15;			// back_vs.png
	
	for(player = 0; player < 2; player++) {
		// フィールドの表示位置をバックアップ
		b_foffset[player] = foffset[player];
		b_boffset[player] = boffset[player];
		
		// フィールドの表示位置を変更
		foffset[player] = v_foffset[player];
		boffset[player] = v_boffset[player];
	}
}

// VERSUSモードから出る
void leaveVersusMode() {
	int i;
	
	maxPlay = b_maxPlay;				// プレイ人数をバックアップから戻す
	
	for(i = 0; i < 2; i++) {
		gameMode[i] = 0;				// モード番号初期化
		playerInitial(i);				// いろいろ初期化
		foffset[i] = b_foffset[i];		// フィールド位置をバックアップから戻す
		boffset[i] = b_boffset[i];
	}
	
	backno = 0;
}

// PRACTICE MODEに入る
void enterPracticeMode() {
	StopAllBGM();
	
	gameMode[0] = 5;
	gameMode[1] = 5;
	
	stat[0] = 1;					// ブロックシャッター実行
	statc[0 * 10] = 0;				// ステータスカウンタを0に
	statc[0 * 10 + 1] = 16;			// シャッター後はステータスNo.16
	
	p_setting = p_def_setting;
	p_leveltype = p_def_leveltype;
	p_timelimit = p_def_timelimit;
	p_goal = p_def_goal;
	p_staffroll = p_def_staffroll;
	
	loadWait(0, p_setting);			// wait設定を読み込む
	
	backno = p_backno;
}

// MISSION MODEに入る
void enterMissionMode() {
	StopAllBGM();
	
	gameMode[0] = 8;
	gameMode[1] = 8;
	
	stat[0] = 1;					// ブロックシャッター実行
	statc[0 * 10] = 0;				// ステータスカウンタを0に
	statc[0 * 10 + 1] = 22;			// シャッター後はステータスNo.22
	
	c_mission = 0;
	start_mission = 0;
	mission_file = 0;
}

// デモ画面準備
void doDemoMode() {
	int tmp, player;
	
	gameAllInit();
	demo = 1;
	demotime = 0;
	bgmlv = -1;
	
	demokind++;
	if(demokind > 1) demokind = 0;
	
	if(demokind == 0) {
		// チュートリアル
		b_maxPlay = maxPlay;
		maxPlay = 1;				// 一時的にDUAL台にする
		setFieldPosition(maxPlay);
		foffset[0] = v_foffset[0];
		boffset[0] = v_boffset[0];
		foffset[1] = v_foffset[1];
		boffset[1] = v_boffset[1];
		coffset = 110;
		
		playback = 1;
		replayauto = 1;
		loadReplayData(0, -1);
		
		nextc[0] = 0;
		next[0] = nextb[0];
		setNextBlockColors(0, 1);
		
		setStartLevel(0);
		
		hnext[0] = dispnext;
		hnext[1] = 0;
		
		stat[0] = 4;
		stat[1] = 35;
		
		timeOn[0] = 1;
		onRecord[0] = 1;
		gameMode[1] = 1;
	} else {
		// デモプレイ
		backno = Rand(15);
		
		for(player = 0; player <= maxPlay; player++) {
			rots[player] = Rand(10);
			
			versusInit(player);
			setNextBlockColors(player, 1);
			
			tmp = Rand(7);
			
			// BEGINNER-TAMAYA
			if(tmp == 0) {
				gameMode[player] = 0;
				timeattack[player] = 1;
			}
			// MASTER
			if(tmp == 1) {
				gameMode[player] = 1;
				timeattack[player] = 1;
				gradetype[player] = Rand(3);
			}
			// ACE-NORMAL
			if(tmp == 2) {
				gameMode[player] = 7;
				timeattack[player] = 0;
			}
			// HEBO+
			if(tmp == 3) {
				gameMode[player] = 10;
				timeattack[player] = 1;
			}
			// BEGINNER-NOVICE
			if(tmp == 4) {
				gameMode[player] = 13;
				timeattack[player] = 1;
			}
			// SIMPLE-40LINES
			if(tmp == 5) {
				gameMode[player] = 17;
				timeattack[player] = 0;
				
				wait1[player] = wait1_Beginner;
				wait2[player] = wait2_Beginner;
				wait3[player] = wait3_Beginner;
				waitt[player] = waitt_Beginner;
				sp[player] = 1;
			}
			// SIMPLE-ULTRA
			if(tmp == 6) {
				gameMode[player] = 17;
				timeattack[player] = 1;
				
				wait1[player] = wait1_Beginner;
				wait2[player] = wait2_Beginner;
				wait3[player] = wait3_Beginner;
				waitt[player] = waitt_Beginner;
				sp[player] = 1;
			}
			
			cpu_flag[player] = 1;
			
			if(maxPlay) cpu_level[player] = Rand(5);
			else cpu_level[player] = 4;
			
			hnext[player] = dispnext;
			setStartLevel(player);
			stat[player] = 3;
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   最後にやる処理
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void lastProc() {
	int		i, j, player;
	
	if(!demo) {
		for(player = 0; player <= maxPlay; player++) {
			// ポーズ
			if(IsPushKey(pause_key[player]) || getJoyPushState(player, joy_pause_key[player])) {
				if(onRecord[player]) {
					pause[player] = !pause[player];
					if(gameMode[player] == 4) pause[1 - player] = !pause[1 - player];
					
					if(pause[player]) PlaySE(36);
					
					StopWave(38);
					
					// BGMポーズ
					if(bgm == 4) {
						// MIDI
						if(pause[player]) {
							PauseMIDI();
						} else {
							ReplayMIDI();
						}
					} else if(bgm >= 2) {
						// WAVE & MP3
						if(pause[player]) {
							PauseWave(60 + bgmlv);
						} else {
							ReplayWave(60 + bgmlv);
						}
					}
				}
			}
			
			// NEXT切り替え
			if(IsPushKey(hnext_key[player]) || getJoyPushState(player, joy_hnext_key[player])) {
				hnext[player]++;
				if(hnext[player] > 6) hnext[player] = 0;
			}
			
			// ライン消し回数表示切り替え
			if((pause[player]) && (player == 0)) {
				if(IsPushKey(skip_key[0]) || getJoyPushState(0, joy_skip_key[0]))
					disp_lineinfo = !disp_lineinfo;
			}
		}
		
		// 操作状況表示
		if( (showctrl != 2) && ((!showctrl && playback) || (showctrl == 1)) ) {
			if((gameMode[0] != 4) && (!tomoyo_dual_enable[0]) && (onRecord[0]) && (!pause[0]))
				showControl();
		}
	}
	
	// デモ画面
	if(demo) {
		demotime++;
		
		if(demokind) {
			if(count % 80 < 40) ExBltRect(49,53,154,0,204,213,19);
			if(maxPlay) ExBltRect(3, 98, 100 + (count % 40 > 20), 0, 160, 123, 31);
		} else {
			showControl();
		}
		
		if(demokind) {
			cpu_flag[0] = 0;
			cpu_flag[1] = 0;
		} else {
			replayauto = 0;
		}
		
		if(getPushState(0,4) || getPushState(0,5) || getPushState(1,4) || getPushState(1,5) || (stat[0] == 11) || (stat[1] == 11))
			flag = 1;
		
		if((demokind) && (demotime >= 3600 * 3))
			flag = 1;
		
		if(flag && !demokind) {
			maxPlay = b_maxPlay;
			setFieldPosition(maxPlay);
		}
		
		if(demokind) {
			cpu_flag[0] = 1;
			cpu_flag[1] = 1;
		} else {
			replayauto = 1;
		}
	}
	
	// THUNDERギミック
	if(thunder_timer) {
		SetSecondaryOffset(-10 + Rand(30), -10 + Rand(30));
		thunder_timer--;
	} else {
		SetSecondaryOffset(0, 0);
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   NEXT生成処理
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void versusInit(int player) {
	int		i, j, temp, mae, shu;
	
	mae = -1;
	nextc[player] = 0;
	nextb_max[player] = 1400;
	
	if((gameMode[0] == 4) && (player == 1)) {
		// 対戦では、1Pのブロックを2Pにコピー
		nextb_max[1] = nextb_max[0];
		for(i = 0; i < nextb_max[1]; i++) nextb[i + 1400] = nextb[i];
		next[1] = next[0];
	} else if(nextblock == 8) {
		// TGM
		tgmNextInit(player, 0);
	} else if(nextblock == 9) {
		// TAP
		tgmNextInit(player, 1);
	} else if(nextblock == 10) {
		// ガイドラインゲーム
		guidelineNextInit(player);
	} else if(nextblock == 11) {
		// TOMOYO
		tomoyoNextInit(player, 0);
	} else if(nextblock == 12) {
		// 電源パターン
		tomoyoNextInit(player, 1);
	} else if(nextblock == 13) {
		// 電源パターン2
		tomoyoNextInit(player, 2);
	} else if(nextblock == 0) {
		// 完全ランダム
		do {
			nextb[0 + player * 1400] = Rand(7);
		} while((nextb[0 + player * 1400] == 2) || (nextb[0 + player * 1400] == 3) || (nextb[0 + player * 1400] == 6));
		
		for(i = 1; i < 1400; i++) nextb[i + player * 1400] = Rand(7);
	} else {
		// HEBORISパターン
		for(i = 0; i < 1400 / nextblock + 1; i++) {
			for(j = 0; j < 7; j++) nextwork[j] = 0;
			
			for(j = 0; j < nextblock; j++) {
				do {
					if(i * nextblock + j == 0) {
						do {
							temp = Rand(7);
						} while((temp == 2) || (temp == 3) || (temp == 6));
					} else {
						temp = Rand(7);
					}
				} while((nextwork[temp] != 0) || (mae == temp));
				
				if(i * nextblock + j < 1400) nextb[i * nextblock + j + player * 1400] = temp;
				
				nextwork[temp] = 1;
				mae = temp;
			}
		}
	}
	
	next[player] = nextb[nextc[player] + player * 1400];
	
	for(i = 0; i < 1400; i++) nextb_fake[i + player * 1400] = Rand(7);
}

// TGM風なNEXT生成処理
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
		
		// 引いたツモが履歴にあったら最大4回(TAP/TIでは6回)引き直し
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

// ツモリストからNEXTを読み込む
// type：0だとTOMOYO、1だと電源パターン1、2だと電源パターン2
void tomoyoNextInit(int player, int type) {
	int		i, j, temp, len;
	
	// 長さを調べる
	if(type == 1) len = StrLen(nextdengen_list);
	else if(type == 2) len = StrLen(nextdengen2_list);
	else len = StrLen(nextb_list);
	
	// 読み込み
	if(len > 0) {
		nextb_max[player] = len;
		
		for(i = 0; i < len; i++) {
			j = i % len;
			
			if(type == 1) MidStr(nextdengen_list, j + 1, 1, string[0]);
			else if(type == 2) MidStr(nextdengen2_list, j + 1, 1, string[0]);
			else MidStr(nextb_list, j + 1, 1, string[0]);
			
			temp = ValLong(string[0]);
			if((temp >= 0) && (temp <= 6)) nextb[i + player * 1400] = temp;
		}
	}
	
	next[player] = nextb[nextc[player] + player * 1400];
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   初期化処理
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void gameAllInit() {
	backno = 0;
	fast = 0;
	count = 0;
	overcount = 0;
	disp_lineinfo = d_disp_lineinfo;

	playerInitial(0);
	playerInitial(1);

	objectClear();
}

void playerInitial(int player) {
	int		i, j;

	repversw = c_repver;
	item_num = 39;

	item_pronum = 0;
	for(i = 0; i < item_num; i++) item_pronum = item_pronum + item_pro[i];

	GiziSRand(player);		// 乱数のシード生成

	sc[player] = 0;
	sp[player] = 1;
	gameTimer[player] = 0;
	timeOn[player] = 0;
	next[player] = nextb[0 + player * 1400];
	hidden[player] = 0;

	wait1[player] = 26;
	wait2[player] = 40;
	wait3[player] = 28;
	waitt[player] = 15;

	combo[player] = 0;
	pinch[player] = 0;

	stat[player] = 0;

	for(i = 0; i < 10; i++) statc[i + player * 10] = 0;

	for(i = 0; i < 10; i++)
		for(j = 0; j < 22; j++) {
			fld[i + j * 10 + player * 220] = 0;
			fldt[i + j * 10 + player * 220] = 0;
			fldu[i + j * 10 + player * 220] = 0;
			fldi[i + j * 10 + player * 220] = 0;
			fldo[i + j * 10 + player * 220] = 0;
			flds[i + j * 10 + player * 220] = 0;
		}

	for(i = 0; i < 22; i++) erase[i + player * 22] = 0;

	// #LITE07
	hold[player] = -1;
	dhold[player] = 0;
	dhold2[player] = 0;
	hold_used[player] = 0;
	tc[player] = -1;
	tr[player] = 0;
	kickc[player] = 0;
	kickc2[player] = 0;
	onRecord[player] = 0;
	time2[player] = 0;
	timeattack[player] = 0;
	ending[player] = 0;
	edrec[player] = 0;
	end_f[player] = 0;
	uplinetype[player] = 0;
	
	c_cblk[player] = 0;
	c_cblk_r[player] = 0;
	c_nblk[0 + player * 6] = 0;
	c_nblk[1 + player * 6] = 0;
	c_nblk[2 + player * 6] = 0;
	c_nblk[3 + player * 6] = 0;
	c_nblk[4 + player * 6] = 0;
	c_nblk[5 + player * 6] = 0;
	c_hblk[player] = 0;
	
	// #LITE08
	endingcnt[player] = 0;
	
	// #LITE10
	bdowncnt[player] = 0;
	r_bdowncnt[player] = 0;
	r_enable[player] = def_rise_enable;
	r_start[player]  = def_rise_start;
	r_end[player]    = def_rise_end;
	r_inter[player]  = def_rise_inter;
	
	staff_c[player] = 0;
	endtime[player] = 0;
	
	sdrop[player] = 0;
	qdrop[player] = 0;
	cmbpts[player] = 0;
	
	// #LITE11
	IsBig[player] = def_IsBig;
	BigMove[player] = def_BigMove;
	IsBigStart[player] = def_IsBig;
	BigMoveStart[player] = def_BigMove;
	
	// #LITE12
	hebocombo[player] = 0;
	nextc[player] = 0;
	
	// #LITE13
	vslevel[player] = 0;
	
	stage[player] = 0;			// ステージ番号
	rest_pblock[player] = 0;	// 残りプラチナブロック数
	sclear[player] = 0;			// ステージクリアフラグ
	stime[player] = 0;			// ステージタイム
	ltime[player] = 0;			// リミットタイム
	sectionTimer[player] = 0;			// クリアタイム
	clearnum[player] = 0;		// クリアステージ数
	clearp[player] = 0;			// クリア率
	pass_flg[player] = 0;		// ツモ送りフラグ
	
	// #LITE14
	start_stage[player] = 0;
	start_nextc[player] = 0;
	
	// #LITE15
	laststage[player] = 26;
	
	isfmirror[player] = 0;
	fmirror_cnt[player] = -20;
	
	rollroll_flag[player] = 0;
	isrollroll[player] = 0;
	
	// #LITE16
	stage_nextc[player] = 0;
	
	xray_flag[player] = 0;
	isxray[player] = 0;
	xray_counter[player] = 0;
	
	color_flag[player] = 0;
	iscolor[player] = 0;
	color_counter[player] = 0;
	
	// #LITE17
	c_norm[player] = 0;
	m_norm[player] = 0;
	
	// #LITE18
	grade[player] = 0;
	gpoint[player] = 0;
	gtime[player] = 0;
	gflash[player] = 0;
	
	// #LITE19
	hanabi_waiting[player] = 0;
	hanabi_frame[player] = 0;
	hanabi_combo[player] = 0;
	combo2[player] = 0;
	
	// #LITE20
	timelimit[0 + player * 2] = 0;
	timelimit[1 + player * 2] = 0;
	
	// #LITE22
	platinaerase_cnt[player] = 0;
	ext_s[player] = 0;
	timeextend_snd_cnt[player] = 0;
	
	// #LITE23
	last_command[player] = 0;
	tspin_frame[player] = 0;
	
	// #LITE27
	field_spin[player] = -1;
	
	// #LITE28
	gup_down[player] = 0;
	gmflag1[player] = 0;
	gmflag2[player] = 0;
	gmflag1_e[player] = 0;
	gmflag2_e[player] = 0;
	gmflag_r[player] = 0;
	
	// #LITE29
	for(i = 0; i < 30; i++) now_sttime[i + player * 30] = 0;
	medal_st[player] = 0;
	medal_ac[player] = 0;
	medal_co[player] = 0;
	medal_sk[player] = 0;
	skill[player] = 0;
	
	// #LITE30.6
	IsTspin[player] = 0;
	gskill[player] = 0;
	gskbai[player] = 0;
	endlines[player] = 0;
	isblind[player] = 0;
	blind_flag[player] = 0;
	
	// #LITE30.8
	isUDLRreverse[player] = 0;
	isRotateLock[player] = 0;
	ishidenext[player] = 0;
	heboGB[player] = 0;
	c_mission = 0;
	clear_mission = 0;
	
	// #LITE30.9
	min_speed[player] = 0;
	mission_extra = 0;
	
	// #LITE30.12
	for(i = 0; i < 20; i++) stage_skip_frame[i + player * 20] = 0;
	stage_skip_used[player] = 0;
	stage_skip_mpc[player] = 0;
	
	// #LITE30.13
	isthunder[player] = 0;
	thunder_timer = 0;
	
	// #LITE30.14
	cpu_best_x[player] = 0;
	cpu_best_y[player] = 0;
	cpu_best_r[player] = 0;
	for(i = 0; i < 10; i++) cpu_ctrl[i + player * 10] = 0;
	cpu_flag[player] = cpu_enable_setting[player];
	cpu_level[player] = cpu_default_level[player];
	//cpu_climb[player] = 0;
	
	// #LITE30.15
	b_to_b[player] = 0;
	b_to_b_count[player] = 0;
	b_to_b_frame[player] = 0;
	ndelay[player] = 1;
	
	// #LITE30.16
	ghole[player] = 0;
	
	// #LITE30.18
	tomoyo_rise[player] = 0;
	tomoyo_rise_t[player] = 0;
	tomoyo_waits[player] = 0;
	upLineNo[player] = 0;
	tomoyo_rise_edit[player] = 0;
	hnext_flag[player] = 0;
	hnext_timer[player] = 0;
	navigation_time[player] = 0;
	
	// #LITE30.20
	item[player] = 0;
	item_name[player] = 0;
	item_g[player] = 0;
	item_t[player] = 0;
	item_hblk[player] = 0;
	item_coming[player] = 0;
	item_waiting[player] = 0;
	itemappear_c[player] = 0;
	item_mode[player] = 0;
	for(i = 0; i < 6; i++) item_nblk[i + player * 6] = 0;
	
	// #LITE30.22
	for(i = 0; i < 6; i++) rt_nblk[i + player * 6] = 0;
	
	// #LITE30.24
	ending_timeOn[player] = 0;
	always_over1000[player] = 0;
	
	// #LITE30.25
	time99[player] = 0;
	timeN[player] = 0;
	ave_laptime3[player] = 0;
	gup3rank[player] = 0;
	gup3sp_adjust[player] = 0;
	qualityflag[player] = 0;
	skillflag[player] = 0;
	tr2[player] = 0;
	border_rank[player] = 0;
	gradetype[player] = 0;
	
	// #LITE30.26
	harddrop[player] = 0;
	
	// #LITE30.27
	for(i = 0; i < 4; i++) {
		line_count[i + player * 4] = 0;
		tspin_count[i + player * 4] = 0;
	}
	tspin_kick[player] = 0;
	
	// #LITE30.29
	softdrop[player] = 0;
	
	// #LITE30.30
	tc_20g[player] = 485;
	regretcancel[player] = 0;
	
	// #LITE30.31
	medal_visible_ac[player] = 0;
	medal_visible_st[player] = 0;
	medal_visible_sk[player] = 0;
	medal_visible_co[player] = 0;
	are_skipflag[player] = 0;
	hanabi_int[player] = 20;
	
	// #LITE30.33
	kickc3[player] = 0;
	
	// #LITE30.34
	pause[player] = 0;
	
	// #LITE31
	risecount[player] = 0;
	
	// #LITE31.1
	o_cblk[player] = 0;
	o_nblk[0 + player * 6] = 0;
	o_nblk[1 + player * 6] = 0;
	o_nblk[2 + player * 6] = 0;
	o_nblk[3 + player * 6] = 0;
	o_nblk[4 + player * 6] = 0;
	o_nblk[5 + player * 6] = 0;
	o_hblk[player] = 0;
	
	// #LITE31.4
	hidden_old[player] = 0;
	hiddentm[player] = 0;
	hiddeny[player] = 22;
	hiddenti[player] = 0;
	hiddenc[player] = 0;
	
	// #LITE31.5
	item_timer[player] = 0;
	ismagnetblock[player] = 0;
	istimestop[player] = 0;
	isholdlock[player] = 0;
	isLRreverse[player] = 0;
	isboost[player] = 0;
	boostbak_sp[player] = 0;
	boostbak_settyaku[player] = 0;
	isfever[player] = 0;
	isUDreverse[player] = 0;
	isremote[player] = 0;
	isdark[player] = 0;
	isUPdelfield[player] = 0;
	isDWdelfield[player] = 0;
	isdeleven[player] = 0;
	istrance[player] = 0;
	dolaser[player] = 0;
	lasernum[player] = 0;
	for(i = 0; i < 4; i++) laserpos[i + player * 4] = -1;
	rapid_c[player] = 0;
	donega[player] = 0;
	doshotgun[player] = 0;
	for(i = 0; i < 22; i++) shotgunpos[i + player * 22] = 0;
	doexchg[player] = 0;
	isbanana[player] = 0;
	for(i = 0; i < 10; i++) banana_pos[i + player * 10] = 0;
	banana_c[player] = 0;
	dorulet[player] = 0;
	isFreefall[player] = 0;
	isLmovfield[player] = 0;
	isRmovfield[player] = 0;
	do180field[player] = 0;
	
	ofs_x[player] = 0;
	ofs_y[player] = 0;
	
	stopmirror_flag[player] = 0;
	
	// #LITE31.8
	Ff_rerise[player] = 0;
	tomoyo_dual[player] = 0;
	tomoyo_timebonus[player] = 0;
	tomoyo_no_stage_time[player] = 0;
	tomoyo_bgm[player] = 0;
	
	// #LITE31.10
	tomoyo_ehfinal_c[player] = 0;
	tomoyo_dual_enable[player] = 0;
	
	// #LITE31.11
	flash_bonus_points[player] = 0;
	flash_bonus_count[player] = 0;
	flash_continue[player] = 0;
	flash_cont_stage[player] = 0;
	li[player] = 0;
	
	// #LITE31.13
	item_all[player] = 0;
	
	for(i = 0; i < 39; i++) {
		if(item_switch[i] != 0) item_all[player]++;
	}
	
	tr_20g[player] = 0;
	
	// #LITE31.14
	cpu_best_p[player] = 0;
	cpu_hold[player] = 0;
	
	// #LITE31.16
	fastroll[player] = 0;
	
	// #LITE31.17
	shadowtime[player] = 300;
	squaremode[player] = 0;
	
	// #LITE31.19
	start_bgmlv[player] = 0;
	
	// #LITE31.22
	s_bdowncnt[player] = 0;
	
	// #LITE31.23
	n_bx[player] = 3;
	
	// #LITE31.27
	ready_count[player] = 0;
	lastblkline[player] = 0;
	speedtype[player] = 0;
	
	// #LITE31.30
	lastline[player] = 0;
	lastline_frame[player] = 0;
	
	// #LITE31.31
	examination[player] = 0;
	exam_grade[player] = 0;
	purupuru[player] = 0;
	
	// #LITE31.32
	tomoyo_ltime_over[player] = 0;
	
	// #LITE31.36
	staff_type[player] = Rand(2);
	
	// #LITE32
	do16t[player] = 0;
	isreflect[player] = 0;
	isdouble[player] = 0;
	isallclear[player] = 0;
	ismiss[player] = 0;
	docopyfld[player] = 0;
	isfakenext[player] = 0;
	item_monochrome[player] = 0;
	for(i = 0; i < 5; i++) itemhistory[i + player * 5] = 0;
	
	// #LITE32.1
	squarenum[player] = 0;
	
	// #LITE32.3
	tcombo[player] = 0;
	start_rots[player] = 0;
	for(i = 0; i < 10; i++) rot_used_flag[i + player * 10] = 0;
	for(i = 0; i < 3; i++) rot_relay_record[i + player * 3] = 0;
	
	// #LITE32.6
	flash_edit[player] = 0;
	lasttspin[player] = 0;
	
	// #LITE32.7
	cpu_frame[player] = -1;
	
	// #LITE32.11
	last_mp_check[player] = -1;
	
	// ブロックの色を設定
	setNextBlockColors(player, 1);
}

// NEXT領域内のブロックの色を設定
// 回転法則を変更したりNEXT関係の変数を弄ったりする度に呼び出す必要あり
void setNextBlockColors(int player, int first) {
	int i, tmp;
	
	if( first ) {
		// 初期設定
		for(i = 0; i < 6; i++) {
			c_nblk[i + player * 6] = getNextBlock(player, nextc[player] + i);
			item_nblk[i + player * 6] = 0;
		}
		
		// 色を変換する
		if(!rule_color[rots[player]]) {
			// クラシック
			for(i = 0; i < 6; i++) c_nblk[i + player * 6] = ccol[c_nblk[i + player * 6]];
		} else {
			// ワールド
			for(i = 0; i < 6; i++) c_nblk[i + player * 6] = wcol[c_nblk[i + player * 6]];
		}
		
		// 強制[]
		if(always_over1000[player] || item_monochrome[player]) {
			for(i = 0; i < 6; i++) o_nblk[i + player * 6] = 1;
		} else {
			for(i = 0; i < 6; i++) o_nblk[i + player * 6] = 0;
		}
	} else {
		// NEXT領域内のブロックの色をずらす
		for(i = 0; i < 5; i++) {
			c_nblk[i + player * 6] = c_nblk[(i + 1) + player * 6];
			item_nblk[i + player * 6] = item_nblk[(i + 1) + player * 6];
			rt_nblk[i + player * 6] = rt_nblk[(i + 1) + player * 6];
			o_nblk[i + player * 6] = o_nblk[(i + 1) + player * 6];
		}
		
		// NEXT領域の最後のブロックの色を設定
		if( (use_over1000_block == 1) && 
		    ((tc[player] >= over1000_start) || (always_over1000[player]) || (item_monochrome[player])) ) {
			// []
			tmp = hnext[player] - 1;
			if(tmp < 0) tmp = 0;
			
			o_nblk[tmp + player * 6] = 1;
		}
		
		// ブロックの種類を取得
		c_nblk[5 + player * 6] = getNextBlock(player, nextc[player] + 5);
		
		// 色を変換する
		if(!rule_color[rots[player]])
			c_nblk[5 + player * 6] = ccol[c_nblk[5 + player * 6]];
		else
			c_nblk[5 + player * 6] = wcol[c_nblk[5 + player * 6]];
		
		// NEXT領域の最後のアイテムを設定
		item_nblk[2 + player * 6] = item_coming[player];
		
		// NEXT領域の最後のブロックの向きを設定
		if(isRotateLock[player])
			rt_nblk[i + player * 6] = GiziRand(player, 4);
		else
			rt_nblk[i + player * 6] = 0;
	}
}

// NEXTブロックを取得
int getNextBlock(int player, int count) {
	// 通常時
	if(count >= nextb_max[player]) {
		count = count - nextb_max[player];
	}
	
	if(player == 0) {
		return nextb[count];
	} else {
		return nextb[count + 1400];
	}
}

// スタッフロール描画
void staffRoll(int player) {
	if((ending[player] == 2) && (onRecord[player]) && (!pause[player])) {
		// スタッフロール経過時間を増加させる
		endtime[player] = endtime[player] + 1 + fastroll[player];
		
		// 描画する
		ExBltRect(81 + staff_type[player], foffset[player] + 8, 40, 0, staff_c[player] / 2, 80, 160);
		
		// 移動
		if((endtime[player] % 2 == 0) && (endtime[player] < 3100)) staff_c[player]++;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   プレイヤーのステータスに応じて各処理を実行
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void playerExecute() {
	int		i, player, j, temp;
	
	// 捨てゲー処理
	if(doGiveup()) {
		return;
	}
	
	// ピンチ音
	if( (pinch[0] && onRecord[0]) || (pinch[1] && onRecord[1]) ) {
		if( !IsPlayWave(32) ) PlaySE(32);
	} else {
		StopWave(32);
	}
	
	for(i = 0; i <= maxPlay; i++) {
		player = i;
		
		if(pause[player]) {
			if(!getPressState(player, 6)) {
				if(count % 60 > 10) printFont(boffset[player] + 2, 15, "PAUSE!", fontc[rots[player]]);
				
				// A+Bで強制終了 #LITE30.6
				if(playback && replayauto) {
					printFont(boffset[player],     19, "PRESS D", digitc[rots[player]]);
					printFont(boffset[player] + 3, 20, "TO PLAY", digitc[rots[player]]);
					
					printFont(boffset[player],     22, "PRESS B", digitc[rots[player]]);
					printFont(boffset[player] + 3, 23, "TO EXIT", digitc[rots[player]]);
				} else {
					printFont(boffset[player],     22, "PRESS A+B", digitc[rots[player]]);
					printFont(boffset[player] + 1, 23, "TO GIVEUP", digitc[rots[player]]);
				}
			}
			
			// PRACTICEではCを押しながら左右でアイテム選択
			if((gameMode[player] == 5) && (item_mode[player])) {
				printFont(boffset[player] - 1, 25, "C+<L R>:ITEM", count % 9);
				
				if(getPressState(player, 6)) {
					// ←
					if(getPushState(player, 2)) {
						PlaySE(5);
						item_nblk[0 + player * 6]--;
						if(item_nblk[0 + player * 6] < 0) item_nblk[0 + player * 6] = item_num;
						item_name[player] = item_nblk[0 + player * 6];
						p_replay_save_enable = 0;
					}
					// →
					if(getPushState(player, 3)) {
						PlaySE(5);
						item_nblk[0 + player * 6]++;
						if(item_nblk[0 + player * 6] > item_num) item_nblk[0 + player * 6] = 0;
						item_name[player] = item_nblk[0 + player * 6];
						p_replay_save_enable = 0;
					}
				}
			}
			
			goto skip;
		}

		// TIME STOP
		if(istimestop[player]) {
			getTime(item_timer[player]);
			printFont(boffset[player] + 1, 18, string[0], (count % 4 / 2) * fontc[rots[player]]);
			
			if(item_timer[player] <= 0) istimestop[player] = 0;
			
			goto next;
		}

		// TOMOYOモードのステージスキップ機能
		if((gameMode[player] == 6) && (stage[player] < 19) && (ltime[player] > 1800) && (timeOn[player])) {
			tomoyoStageSkip(player);
		}

		// 15分以上プレイすると超高速（TOMOYO、MISSION以外）
		if((gameTimer[player] >= 54000) && (timeOn[player]) && 
		   (gameMode[player] != 5) && (gameMode[player] != 6) && (gameMode[player] != 8) && (gameMode[player] != 15))
		{
			sp[player] = speed_limit15;
			wait1[player] = wait1_limit15;
			wait2[player] = wait2_limit15;
			wait3[player] = wait3_limit15;
			speedtype[player] = 0;
		}

		// VERSUS勝敗画面
		if(flag == -1) {
			if(!player) winner();
			goto next;
		}

		jump(stat[i],l00,l01,l02,l03,l04,l05,l06,l07,l08,l09,l10,l11,l12,l13,l14,l15,l16,l17,l18,l19,l20,l21,l22,l23,l24,l25,l26,l27,l28,l29,l30,l31,l32,l33,l34,l35,l36,l37,l38,l39,l40,l41,l42);
		
		/*
		switch(stat[i]) {
			case  0: goto l00;
			case  1: goto l01;
			case  2: goto l02;
			case  3: goto l03;
			case  4: goto l04;
			case  5: goto l05;
			case  6: goto l06;
			case  7: goto l07;
			case  8: goto l08;
			case  9: goto l09;
			case 10: goto l10;
			case 11: goto l11;
			case 12: goto l12;
			case 13: goto l13;
			case 14: goto l14;
			case 15: goto l15;
			case 16: goto l16;
			case 17: goto l17;
			case 18: goto l18;
			case 19: goto l19;
			case 20: goto l20;
			case 21: goto l21;
			case 22: goto l22;
			case 23: goto l23;
			case 24: goto l24;
			case 25: goto l25;
			case 26: goto l26;
			case 27: goto l27;
			case 28: goto l28;
			case 29: goto l29;
			case 30: goto l30;
			case 31: goto l31;
			case 32: goto l32;
			case 33: goto l33;
			case 34: goto l34;
			case 35: goto l35;
			case 36: goto l36;
			case 37: goto l37;
			case 38: goto l38;
			case 39: goto l39;
			case 40: goto l40;
			case 41: goto l41;
			case 42: goto l42;
		}
		*/
		
		l00: statJoinwait(player);				// 00 -> 途中参加待ち状態
				goto next;
		l01: statBlockSutter(player);			// 01 -> ブロックシャッター
				goto next;
		l02: statSelectMode(player);			// 02 -> モードセレクト画面
				goto next;
		l03: statReady(player);					// 03 -> Ready!?
				goto next;
		l04: statBlock(player);					// 04 -> ブロック落下準備
				goto next;
		l05: statMove(player);					// 05 -> ブロック移動中 (move.c)
				goto next;
		l06: statErase(player);					// 06 -> 時間稼ぎ
				goto next;
		l07: statGameOver(player);				// 07 -> ゲームオーバー演出
				goto next;
		l08: statEraseBlock(player);			// 08 -> ブロック消去
				goto next;
		l09: statSelectLevel(player);			// 09 -> VSモードレベルセレクト画面
				goto next;
		l10: statVersusWait(player);			// 10 -> おまちください画面
				goto next;
		l11: statNameEntry(player);				// 11 -> ネームエントリー
				goto next;
		l12: statResult(player);				// 12 -> 結果表示
				goto next;
		l13: statGameOver2(player);				// 13 -> ゲームオーバー表示
				goto next;
		l14: statEnding(player);				// 14 -> エンディング
				goto next;
		l15: statRiseLine(player);				// 15 -> せり上がり
				goto next;
		l16: statPracticeSelect(player);		// 16 -> PRACTICEモード設定画面 (practice.c)
				goto next;
		l17: statFieldEditor(player);			// 17 -> フィールドエディタ
				goto next;
		l18: statTomoyoNextStage(player);		// 18 -> TOMOYOモード ステージクリア／タイムオーバー (tomoyo.c)
				goto next;
		l19: statTomoyoContinue(player);		// 19 -> TOMOYOモード コンティニュー (tomoyo.c)
				goto next;
		l20: statTomoyoEditor(player);			// 20 -> TOMOYOモード ステージエディタ (tomoyo.c)
				goto next;
		l21: statDelField(player);				// 21 -> ライン強制消去 (item.c)
				goto next;
		l22: statMissionSelect(player);			// 22 -> ミッションモードセレクト画面
				goto next;
		l23: statMissionEditor(player);			// 23 -> ミッションモードエディット画面
				goto next;
		l24: statReplaySave(player);			// 24 -> リプレイ保存画面
				goto next;
		l25: statNothing(player);				// 25 -> 一定時間何もしない
				goto next;
		l26: statExtraErase(player);			// 26 -> ブロックを上から指定したライン数だけ消去
				goto next;
		l27: statLaser(player);					// 27 -> レーザー (item.c)
				goto next;
		l28: statNegafield(player);				// 28 -> ネガフィールド (item.c)
				goto next;
		l29: statShotgun(player);				// 29 -> ショットガン (item.c)
				goto next;
		l30: statExchangeField(player);			// 30 -> フィールド交換 (item.c)
				goto next;
		l31: statItemRulet(player);				// 31 -> アイテムルーレット (item.c)
				goto next;
		l32: statFreefall(player);				// 32 -> フリーフォール (item.c)
				goto next;
		l33: statMovfield(player);				// 33 -> ブロックを端に寄せる (item.c)
				goto next;
		l34: stat180field(player);				// 34 -> フィールド上のブロックをひっくり返す (item.c)
				goto next;
		l35:									// 35 -> 何もしない
				goto next;
		l36: statFlashSelectFirstStage(player);	// 36 -> FLASHモードステージセレクト（初回）
				goto next;
		l37: statFlashSelectNextStage(player);	// 37 -> FLASHモードステージセレクト（2回目以降）
				goto next;
		l38: statStandardSelect(player);		// 38 -> STANDARDモードセレクト画面
				goto next;
		l39: statMissionCourseName(player);		// 39 -> ミッションモードコース名入力画面
				goto next;
		l40: statExamination(player);			// 40 -> 段位認定試験
				goto next;
		l41: statCopyField(player);				// 41 -> フィールドコピー
				goto next;
		l42: statRotRelaySelectRule(player);	// 42 -> ROT. RELAYの次のルール選択
				goto next;
		
		next:
		increment_time(player);
		
		skip:
	}

	// BGMフェードアウト処理
	if(bgm >= 2) bgmFadeout();

	// 両者ゲームオーバーなら一定時間経過後タイトルへ
	if((stat[0] == 0) && (stat[1] == 0)) {
		if(!overcount) {
			hold[0] = -1;
			hold[1] = -1;
			versusInit(0);
			versusInit(1);
			setNextBlockColors(0, 1);
			setNextBlockColors(1, 1);
			backno = 0;
			back_acnt = 0;
		}
		
		if(playback) {
			// リプレイでは即タイトル
			flag = 1;
		}
		
		overcount++;
		
		if(overcount > 120) {
			RankingProc(gameMode[0]);
			flag = 1;
		}
	} else {
		overcount = 0;
	}
}

// 捨てゲーする処理
// 捨てゲーした場合の戻り値は1
int doGiveup() {
	int player, bak, tmp, i;
	
	tmp = (IsPushKey(giveup_key) || getJoyPushState(0, joy_giveup_key[0]) || getJoyPushState(1, joy_giveup_key[1]));
	tmp = ((tmp) || (getPressState(0, 4) && getPressState(0, 5) && pause[0]));	// ポーズ中にA+B (1P)
	tmp = ((tmp) || (getPressState(1, 4) && getPressState(1, 5) && pause[1]));	// ポーズ中にA+B (2P)
	
	if(tmp) {
		versusInit(0);				// NEXT初期化
		versusInit(1);
		
		objectClear();				// 全オブジェクト消去
		
		// 効果音＆BGM全停止
		StopAllWaves();
		StopAllBGM();
		
		// 背景を戻す
		backno = 0;
		back_acnt = 0;
		
		for(i = 0; i < 10; i++) TextLayerOff(i);
		
		// DUALギミック解除
		endTomoyoDualGimmick(0);
		
		if(playback || demo) {
			// リプレイ
			flag = 1;
		} else if(gameMode[0] == 5) {
			// PRACTICEモード用
			flag = 0;
			pause[0] = 0;
			PracticeOver();
		} else if(gameMode[0] == 8) {
			// MISSIONモード用
			flag = 0;
			pause[0] = 0;
			playerInitial(0);
			stat[0] = 1;
			statc[0 * 10] = 0;
			statc[0 * 10 + 1] = 22;
		} else {
			flag = 0;
			
			for(player = 0; player <= maxPlay; player++) {
				pause[player] = 0;				// ポーズ解除
				bak = stat[player];				// ステータスをバックアップ
				
				playerInitial(player);			// 初期化
				stat[player] = 1;				// ブロックシャッター実行
				statc[player * 10] = 0;			// ステータスカウンタを0に
				
				if(gameMode[player] == 4) {
					resetVersusMode();
					backno = 15;	// back_vs.png
				}
				
				// シャッター後は
				if(bak == 0) {
					statc[player * 10 + 1] = 0;		// 参加待ち
				} else if(gameMode[player] == 4) {
					statc[player * 10 + 1] = 9;		// VSモードレベルセレクト
				} else {
					statc[player * 10 + 1] = 2;		// モードセレクト
				}
			}
		}
		
		return 1;
	}
	
	return 0;
}

// タイムを増加させる
void increment_time(int player) {
	int temp, i, j, k, tmp;
	
	// SHUFFLE FIELD
	if(isbanana[player]) bananaProc(player);
	
	// リプレイ記録
	if(onRecord[player]) {
		if((!replayauto) && (time2[player] < 60 * 60 * 20)) {
			temp = 0;
			for(j = 0; j < 8; j++) {
				temp = temp | (getPressState(player, j) << j) | (getPushState(player, j) << (j + 8));
			}
			
			if(!player) {
				replayData[time2[player]] = temp;
			} else {
				replayData2[time2[player]] = temp;
			}
		}
		
		time2[player]++;	// リプレイ用カウンタに1/60秒プラス
	}
	
	// タイマーが動作していれば時間に1/60秒プラス
	if( timeOn[player] ) {
		gameTimer[player]++;
		sectionTimer[player]++;	// セクションタイム増加
	}
	
	// エンディング中ならばエンディング経過時間に1/60秒プラス
	if((ending_timeOn[player]) && (onRecord[player])) {
		edrec[player] = edrec[player] + 1 + fastroll[player];
	}
	
	// ロールクリア
	if((ending[player] == 2) && (edrec[player] > ending_timelimit) && (onRecord[player])) {
		ending_timeOn[player] = 0;
		stat[player] = 14;
		for(i=0; i<10; i++) statc[player * 10 + i] = 0;
		
		if(hidden[player]) {
			hidden[player] = 0;			// フィールドタイマーを解除
			disableShadowTimer(player);
		}
		
		// ロールクリアで段位上昇
		if( (gameMode[player] == 1) || (gameMode[player] == 2) ) {
			// 現在の段位をバックアップ（COOL/REGRET演出用）
			temp = grade[player];
			
			// NORMAL
			if(gradetype[player] == 0) {
				// 消えロール中に消した列数で昇格or降格
				if(gmflag_r[player]) {
					if(endlines[player] >= 20) grade[player]++;		// 合計+3
					if(endlines[player] >= 13) grade[player]++;		// 合計+2
					if(endlines[player] >=  7) grade[player]++;		// 合計+1
					if(endlines[player] <=  2) grade[player]--;		// 2ライン以下で降格
				} else {
					grade[player]++;								// 見えロールでは+1
				}
			}
			
			// HARD
			if(gradetype[player] == 1) {
				if(gmflag_r[player]) {
					if(endlines[player] >= 3) {
						// 消えロールで3列以上消すと段位上昇
						grade[player] = grade[player] + endlines[player] / 4;
						
						if(grade[player] >= 30) {
							if(tr[player] > 185)
								grade[player] = 30;		// MO
							else
								grade[player] = 29;		// MV
						}
					} else {
						// 2ライン以下だったら降格
						grade[player]--;
					}
				} else {
					// 見えロールでは10ラインごとに段位上昇
					grade[player] = grade[player] + endlines[player] / 10;
					if(grade[player] > 28) grade[player] = 28;
				}
			}
			
			// GMより上には上がらない
			if(grade[player] > 32) grade[player] = 32;
			if(grade[player] <  0) grade[player] = 0;
			
			// 演出
			if(grade[player] > temp) {
				// COOL!!
				if(gradetype[player] == 1)
					PlaySE(48);
				else
					PlaySE(31);
				
				gup_down[player] = 1;
				gflash[player] = 120;
			} else if(grade[player] < temp) {
				// REGRET
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
			}
		}
		
		// DEVIL-DOOM段位
		if((gameMode[player] == 3) && (grade[player] == 13)) {
			// CLASSIC系列は5:00以内、WORLD系列は5:20以内でGOD昇格
			if( ((!isWRule(player)) && (gameTimer[player] <= 18000)) || ((isWRule(player)) && (gameTimer[player] <= 19200)) ) {
				grade[player] = 14;
				gflash[player] = 120;
			}
		}
		// DEVIL-HARD段位
		if((gameMode[player] == 16) && (grade[player] == 13)) {
			// CLASSIC系列は5:20以内、WORLD系列は5:50以内でGM昇格
			if( ((!isWRule(player)) && (gameTimer[player] <= 19200)) || ((isWRule(player)) && (gameTimer[player] <= 21000)) ) {
				grade[player] = 14;
				gflash[player] = 120;
			}
		}
		
		if(gameMode[player] == 0) sc[player] = sc[player] + 30;
		
		if(gameMode[player] == 15) sc[player] = sc[player] + 100000 + ltime[player];
		
		ending[player] = 3;
		if((gameMode[player] != 0) && (gameMode[player] != 13)) end_f[player] = 2;
		
		onRecord[player] = 0;	// エンディングロール終了と同時にリプレイ記録終了
		PlaySE(30);
		
		// DEVIL-の足切り
		if((gameMode[player] == 11) && (tc[player] < 999)) {
			end_f[player] = 0;
			ending[player] = 5;
		}
	}
	
	// TOMOYOモードの制限時間をカウントダウン #LITE13
	if( (timeOn[player]) && (gameMode[player] == 6) ) {
		ltime[player]--;	// リミットタイム減少
		
		if((ltime[player] <= 0) && (!tomoyo_ltime_over[player])) {
			// リミットタイムが0になったらゲームオーバー
			PlaySE(39);
			ltime[player] = 0;
			setGameOver(player);
		} else {
			// まだリミットタイムが0になっていない
			if((!tomoyo_no_stage_time[player]) && (stime[player] > 0)) {
				stime[player]--;	// ステージタイム減少
				
				// 警告音
				if(stime[player] == 10 * 60) PlaySE(38);
				if(stime[player] == 0) PlaySE(39);
			}
			
			// リミットタイム警告音
			if(ltime[player] == 10 * 60) PlaySE(38);
		}
	}
	
	// ACEモードの制限時間をカウントダウン #LITE17
	if((timeOn[player]) && (isAceModeOrMission(player)) && (gameMode[player] != 4) && (gameMode[player] != 5)) {
		ltime[player]--;	// リミットタイム減少
		
		// 耐久ミッション用
		if((gameMode[player] == 8) && (mission_type[c_mission] == 23)) {
			if( ((mission_opt_3[c_mission] == 0) && ((kickc[player] > 10) || (kickc3[player] > 10))) || 
			    ((mission_opt_3[c_mission] > 0) && (mission_opt_3[c_mission] < 99) && 
			     ((kickc[player] > mission_opt_3[c_mission]) || (kickc3[player] > mission_opt_3[c_mission]))) )
			{
				ltime[player]++;
				StopWave(38);
			}
		}
		
		if((gameMode[player] != 8) || (mission_time[c_mission] > 0)) {
			if(ltime[player] <= 0) {
				// リミットタイムが0になったらゲームオーバー
				ltime[player] = 0;
				
				if((isAceMode(player)) || (mission_type[c_mission] != 23)) {
					PlaySE(39);
					setGameOver(player);
				}
			} else {
				// 警告音
				if(ltime[player] == 10 * 60) PlaySE(38);
			}
		}
	}
	
	// VERSUSモードの制限時間をカウントダウン
	if((timeOn[player]) && (gameMode[player] == 4) && (vs_timelimit > 0) && (player == 0)) {
		ltime[player]--;	// リミットタイム減少
		
		if(ltime[player] <= 0) {
			// リミットタイムが0になったらレベルが大きい方の勝ち
			ltime[player] = 0;
			PlaySE(39);
			
			if(!vs_goal_type) {
				i = tc[0];
				j = tc[1];
			} else {
				i = c_norm[0];
				j = c_norm[1];
			}
			
			if(i > j) {
				// 1P WIN
				setGameOver(1);
			} else if(i < j) {
				// 2P WIN
				setGameOver(0);
			} else {
				// DRAW
				setGameOver(0);
				setGameOver(1);
			}
		} else {
			// 警告音
			if(ltime[player] == 10 * 60) PlaySE(38);
		}
	}
	
	// フィールドタイマーのカウントダウン
	if(hidden[player] == 1) {
		for(j = 0; j < 22; j++)
			for(k = 0; k < 10; k++) 
				if(fldt[k + j * 10 + player * 220] > 0)
					fldt[k + j * 10 + player * 220]--;
	} else if(hidden[player] == 2) {
		for(j = 0; j < 22; j++)
			for(k = 0; k < 10; k++) 
				if(fldt[k + j * 10 + player * 220] < 0)
					fldt[k + j * 10 + player * 220] = fldt[k + j * 10 + player * 220] + 10;
	}
	
	// X-RAY用カウント
	if(isxray[player]) xray_counter[player]++;
	
	// COLOR用カウント
	if(iscolor[player]) color_counter[player]++;
	
	// 段位ポイント減少 #LITE18
	if( (gameMode[player] == 1) || (gameMode[player] == 2) ) {
		if( ((stat[player] == 3)||(stat[player] == 5)) && (combo[player] <= 1) && (!ending[player]) && (gradetype[player] == 0) ) {
			gtime[player]++;
			
			if( (grade[player] <= 29) && (gtime[player] >= glimit[grade[player]]) ) {
				gpoint[player]--;
				gtime[player] = 0;
				
				// 段位9のときは段位ポイントが0より小さくならない
				if( (grade[player] == 0) && (gpoint[player] < 0) ) {
					gpoint[player] = 0;
				}
				
				// 降格
				if(gpoint[player] < -50) {
					PlaySE(44);
					grade[player]--;
					gpoint[player] = 0;
					gup_down[player] = 0;
					gflash[player] = 120;
				}
			}
		}
	}
	
	// 段位上昇アニメ時間減少
	if( (gflash[player] > 0) && (!tspin_frame[player]) ) gflash[player]--;
	
	// BEGINNERロール花火
	if((gameMode[player] == 0) && (ending[player] == 2)) {
		if(edrec[player] % hanabi_int[player] == 0) {
			sc[player]++;
			hanabi_waiting[player]++;
		}
	}
	
	// 花火発生 #LITE19
	if( (hanabi_waiting[player] > 0) && (onRecord[player] == 1) ) {
		hanabi_frame[player] = hanabi_frame[player] + 1 + (hanabi_waiting[player] > 60);
		
		if(hanabi_frame[player] >= 10) {
			hanabi_waiting[player]--;
			objectCreate(player, 3, -40 + Rand(80) + foffset[player],
			             16 + Rand(20) + 116 * ((checkFieldTop(player) < 12) && (by[player] < 12)), 0, 0, Rand(7), 0);
			hanabi_frame[player] = 0;
		}
	}
	
	if(hanabi_waiting[player] == 0) hanabi_frame[player] = 10;
	
	// プラチナブロック消去音 #LITE22
	if( (platinaerase_cnt[player] > 0) && (count % 10 == 0) ) {
		PlaySE(40);
		platinaerase_cnt[player]--;
	}
	
	// T-SPIN表示フレーム数減少
	if(tspin_frame[player]) tspin_frame[player]--;
	
	// BACK TO BACK表示フレーム数減少
	if(b_to_b_frame[player]) b_to_b_frame[player]--;
	
	// HIDE NEXTギミック
	if(hnext_flag[player] && timeOn[player]) {
		hnext_timer[player]++;
		if(hnext_timer[player] > 720) hnext_timer[player] = 0;
		
		if(((hnext_timer[player] > 540) && (hnext_timer[player] <= 660)) || (( ((hnext_timer[player] > 480) && (hnext_timer[player] <= 540)) || (hnext_timer[player] > 660) ) && (hnext_timer[player] % 2 == 0)))
			ishidenext[player] = 1;
		else
			ishidenext[player] = 0;
	}
	
	// レベルストップ時間をカウント
	if( (timeOn[player]) && ((tc[player] % 100 == 99) || (tc[player] == 998)) ) {
		time99[player]++;
	}
	
	// 時限式アイテムの効果時間減少
	if(item_timer[player] > 0) {
		item_timer[player]--;
		if(item_timer[player] <= 0) endTimerItem(player);
	}
	
	// TOMOYO DUAL面
	if(tomoyo_dual_enable[player]) {
		if(timeOn[player]) {
			// カウンタ増加
			tomoyo_ehfinal_c[player]++;
			if(tomoyo_ehfinal_c[player] > 480) tomoyo_ehfinal_c[player] = 0;
			
			// フィールド位置を交換
			if((tomoyo_ehfinal_c[player] >= 220) && (tomoyo_ehfinal_c[player] <= 240)) {
				temp = foffset[0];
				foffset[0] = foffset[1];
				foffset[1] = temp;
				
				temp = boffset[0];
				boffset[0] = boffset[1];
				boffset[1] = temp;
			}
		}
		
		// 使っていないほうのフィールドを塗りつぶす
		if((tomoyo_ehfinal_c[player] < 220) || (tomoyo_ehfinal_c[player] > 240)) {
			if(foffset[0] == v_foffset[0])
				ExBltFastRect(84, foffset[1] + ofs_x[0] + 8, 40 + ofs_y[0], 0, 0, 80, 160);
			else
				ExBltFastRect(24, foffset[1] + ofs_x[0] + 8, 40 + ofs_y[0], 0, 0, 80, 160);
		}
	}
	
	// FLASHモード ボーナス減少
	if((gameMode[player] == 15) && (flash_bonus_points[player] > 0) && (timeOn[player]) && 
	   (stat[player] != 6) && (stat[player] != 8))
	{
		flash_bonus_count[player]--;
		
		if(flash_bonus_count[player] <= 0) {
			flash_bonus_count[player] = 4;
			flash_bonus_points[player]--;
		}
	}
	
	// FLASH-18MINモード リミットタイム減少
	if((gameMode[player] == 15) && (timeattack[player])) {
		CountDownLimitTime(player);
	}
	
	// SIMPLE-ULTRAモード リミットタイム減少
	if((gameMode[player] == 17) && ((timeattack[player] == 1) || (timeattack[player] == 3)) && (timeOn[player])) {
		ltime[player]--;
		
		if(ltime[player] <= 0) {
			// リミットタイムが0になったらクリア
			ltime[player] = 0;
			timeOn[player] = 0;
			
			// 警告音停止
			pinch[player] = 0;
			StopWave(38);
			
			// リプレイ記録終了
			if((timeattack[player] == 1) && (repversw <= 4)) onRecord[player] = 0;
			
			if(!IsPlayWave(29)) PlaySE(29);
			ending[player] = 1;
			stat[player] = 14;
			for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		} else {
			// 警告音
			if(ltime[player] == 10 * 60) PlaySE(38);
		}
	}
	
	// PRACTICEモードリミットタイム減少
	if((gameMode[player] == 5) && (p_timelimit > 0)) {
		CountDownLimitTime(player);
	}
	
	// ライン消し表示フレーム減少
	if(lastline_frame[player] > 0) lastline_frame[player]--;
	
	// プルプル
	if(purupuru[player]) {
		if(purupuru[player] == 1) {
			purupuru[player] = 2;
			tmp = Rand(2) + 1;
		} else {
			purupuru[player] = 1;
			tmp = Rand(2) + 1 * -1;
		}
		ofs_x[player] = tmp;
	}
}

// リミットタイムを減らす
// リミットタイムが0になったらゲームオーバー
void CountDownLimitTime(int player) {
	if((ltime[player] > 0) && (timeOn[player])) {
		ltime[player]--;
		
		if(ltime[player] <= 0) {
			// リミットタイムが0になったらゲームオーバー
			ltime[player] = 0;
			PlaySE(39);
			setGameOver(player);
		} else {
			// 警告音
			if(ltime[player] == 10 * 60) PlaySE(38);
		}
	}
}

// 現在のルールがワールド系かどうか判定
int isWRule(int player) {
	return (rule_rot[rots[player]] == 1);
}

// 現在のルールがDRSかどうか判定
int isDRule(int player) {
	return (rule_rot[rots[player]] == 2);
}

// 回転法則を変更
int changeRule(int player, int rule) {
	rots[player] = rule;
	if(rots[player] < 0) rots[player] = 9;
	if(rots[player] > 9) rots[player] = 0;
	setNextBlockColors(player, 1);
}

// 通常のモードかどうか判定（BEGINNER含まない）
int isNormalMode(int player) {
	int mode;
	mode = gameMode[player];
	return (((mode >= 1) && (mode <= 3)) || ((mode == 5) && (!p_leveltype)) || (mode == 10) || (mode == 11) || (mode == 13) || (mode == 14) || (mode == 16));
}

// 通常のモードかどうか判定（BEGINNER含む）
int isNormalOrBeginnerMode(int player) {
	int mode;
	mode = gameMode[player];
	return ((mode <= 3) || ((mode == 5) && (!p_leveltype)) || (mode == 10) || (mode == 11) || (mode == 13) || (mode == 14) || (mode == 16));
}

// ACE系のモードかどうか判定（MISSION含まない）
int isAceMode(int player) {
	int mode;
	mode = gameMode[player];
	return ((mode == 7) || (mode == 12) || ((mode == 4) && (vs_goal_type == 1)) || ((mode == 5) && (p_leveltype == 1)));
}

// ACE系のモードかどうか判定（MISSION含む）
int isAceModeOrMission(int player) {
	int mode;
	mode = gameMode[player];
	return ((mode == 7) || (mode == 8) || (mode == 12) || ((mode == 4) && (vs_goal_type == 1)) || ((mode == 5) && (p_leveltype == 1)));
}

// MARATHONモードかどうか判定
int isMarathonMode(int player) {
	int mode;
	mode = gameMode[player];
	return ((mode == 18) || ((mode == 4) && (vs_goal_type == 2)) || ((mode == 5) && (p_leveltype == 2)));
}

// TOMOYOモードのステージスキップ機能
void tomoyoStageSkip(int player) {
	if(!playback) {
		if(IsPressKey(skip_key[player]) || getJoyPressState(player, joy_skip_key[player]))
			stage_skip_mpc[player]++;
		else
			stage_skip_mpc[player] = 0;
	}
	
	if( ((!playback) && (stage_skip_mpc[player] >= stage_skip_tame)) || 
	    ((playback) && (time2[player] == stage_skip_frame[stage_skip_used[player] + player * 20])) )
	{
		timeOn[player] = 0;						// タイマー停止
		ltime[player] = ltime[player] - 1800;	// -30秒
		sclear[player] = 0;						// スキップ
		
		// ステージスキップを使ったフレームを記録
		if(!playback) {
			stage_skip_frame[stage_skip_used[player] + player * 20] = time2[player];
		}
		
		stage_skip_used[player]++;				// 使用回数+1
		
		stat[player] = 18;						// ステージ終了
		statc[player * 10] = 0;					// カウンタ初期化
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.00 - 途中参加待ち状態
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statJoinwait(int player) {
	if((count % 5 == 0) && (empty_spin_field)) {
		field_spin[player]++;
		if(field_spin[player] > 19) field_spin[player] = 0;
	}
	
	if(playback) return;
	
	if((player == 1) && (gameMode[0] == 5)) return;
	if((player == 1) && (gameMode[0] == 8)) return;
	
	padRepeat(player);
	
	// PUSH nP START BUTTON
	if(count % 60 > 10) {
		ExBltRect(49, foffset[player] - 2, 85, 100 * player, 50, 100, 65);
	}
	
	if(getPushState(player, 4)) {
		PlaySE(10);
		
		if(bgm == 1) {
			if( !IsPlayMIDI() ) {
				ReplayMIDI();
				StopWave(8);
			}
		}
		
		playerInitial(player);
		
		stat[player] = 1;					// ブロックシャッター実行
		statc[player * 10] = 0;				// ステータスカウンタを0に
		statc[player * 10 + 1] = 2;			// シャッター後はステータスNo.2
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.01 - ブロックシャッター
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statBlockSutter(int player) {
	int		i;
	
	stat[player] = statc[player * 10 + 1];	// 次のステータスへジャンプ
	
	// カウンタはあとかたづけ
	for(i = 0; i < 10; i++) {
		statc[player * 10 + i] = 0;
	}
	
	// フィールド初期化
	for(i = 0; i < 220; i++) {
		fld[i + player * 220] = 0;
		fldt[i + player * 220] = 0;
		fldu[i + player * 220] = 0;
		fldi[i + player * 220] = 0;
		fldo[i + player * 220] = 0;
		flds[i + player * 220] = 0;
	}
	
	upLines[player] = 0;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.02 - モードセレクト画面
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// statc[player * 10 + 0] : 初期化済みフラグ
// statc[player * 10 + 1] : 選択しているモード
// statc[player * 10 + 2] : ゲームタイプ
// statc[player * 10 + 3] : 現在の画面
// statc[player * 10 + 4] : オプション画面のカーソル位置
// statc[player * 10 + 5] : プレイヤーデータ選択画面で選択している文字

void statSelectMode(int player) {
	int i, j, color, color2, move, len;
	
	color = (count % 4 / 2) * digitc[rots[player]];
	color2 = (count % 4 / 2) * fontc[rots[player]];
	padRepeat(player);
	padRepeat2(player);
	
	// モードセレクトBGM再生
	if((!onRecord[1 - player]) && (statc[player * 10 + 0] == 0)) {
		bgmlv = 12;
		changeBGM();
		
		statc[player * 10 + 1] = lastmode[player];
		statc[player * 10 + 2] = lasttype[player];
		statc[player * 10 + 3] = 0;
		statc[player * 10 + 4] = 0;
		statc[player * 10 + 5] = 0;
		setFieldPosition(maxPlay);
		
		statc[player * 10 + 0] = 1;
	}
	
	printScoreFont(soffset[player], 4 + top_frame, "A: OK", fontc[rots[player]]);
	printScoreFont(soffset[player], 5 + top_frame, "B: BACK", fontc[rots[player]]);
	
	// プレイヤーデータセレクト
	if(statc[player * 10 + 3] == 0) {
		printFont(boffset[player], 12, "ENTER NAME", 4);
		
		len = StrLen(user_name[player]);	// 入力済み文字数
		
		// 横移動
		move = getPressState(player, 3) - getPressState(player, 2);
		if(move)
			if((mpc[player] == 1) || (mpc[player] >= 15) || getPressState(player, 6)) {
				if(mpc[player] >= 15) mpc[player] = 12;
				statc[player * 10 + 5] = statc[player * 10 + 5] + move;
				PlaySE(5);
			}
		
		// 文字のループ
		if(statc[player * 10 + 5] > 54)
			statc[player * 10 + 5] = (len == 3) * 53;
		if(statc[player * 10 + 5] < (len == 3) * 53)
			statc[player * 10 + 5] = 54;
		
		// 選択している文字と入力済み文字を表示
		MidStr(RankString, statc[player * 10 + 5] + 1, 1, string[4]);
		printFont(boffset[player] + 3 + len, 14, string[4], 2 * (count % 20 > 10));
		printFont(boffset[player] + 3, 14, user_name[player], 0);
		
		printFont(boffset[player], 16, "PRESS D TO", 1);
		printFont(boffset[player], 17, "GUEST MODE", 1);
		
		if((statc[player * 10 + 5] == 54) && (len != 0) && (!onRecord[1 - player])) {
			printScoreFont(soffset[player], 7 + top_frame, "C+A:", fontc[rots[player]]);
			printScoreFont(soffset[player], 8 + top_frame, "RECORDS", fontc[rots[player]]);
		}
		
		// Bボタンで戻る
		if(getPushState(player, 5)) {
			stat[player] = 0;
			if(stat[1 - player] == 0) flag = 1;
			return;
		}
		
		// Aボタンで入力
		if(getPushState(player, 4)) {
			PlaySE(10);
			
			if(statc[player * 10 + 5] == 53) {
				// RB
				if(len) {
					MidStr(user_name[player], 1, len - 1, user_name[player]);
				}
			} else if(statc[player * 10 + 5] == 54) {
				// ED
				PlaySE(18);
				
				if(!len) {
					// 名前が入力されていない場合はプレイヤーデータ未使用
					user_enable[player] = 0;
				} else {
					user_enable[player] = 1;
					
					// 名前の後ろにスペースを挿入（名前が1～2文字しかない場合、余った個所をスペースにする）
					sprintf(user_name[player], "%s   ", user_name[player]);
					
					// 左から4文字目以降を削除
					LeftStr(user_name[player], 3, user_name[player]);
					
					// 読み込み
					if(user_load(player) != 0) {
						user_init(player);
					}
					
					// Cを押している場合は記録を表示
					if(getPressState(player, 6) && !onRecord[1 - player]) {
						user_view(player);
					}
				}
				
				statc[player * 10 + 3]++;
				return;
			} else {
				// 文字入力
				StrCat(user_name[player], string[4]);
			}
		}
		
		// Dボタンでプレイヤーデータ未使用
		if(getPushState(player, 7)) {
			user_enable[player] = 0;
			statc[player * 10 + 3]++;
			return;
		}
	}
	// ルールセレクト
	else if(statc[player * 10 + 3] == 1) {
		printScoreFont(soffset[player], 20, "PAUSE:", fontc[rots[player]]);
		printScoreFont(soffset[player], 21, "HELP", fontc[rots[player]]);
		
		// ルール一覧表示
		printFont(boffset[player], 6, "SELECT", fontc[rots[player]]);
		printFont(boffset[player] + 1, 7, "ROT. RULE", fontc[rots[player]]);
		
		printFont(boffset[player], 9 + rots[player], "b", color2);
		
		for(i = 0; i < 10; i++) {
			getRuleNameEx(i, 0);
			printFont(boffset[player] + 1, 9 + i, string[0], (rots[player] == i) * color2);
		}
		
		// キー入力
		// ↑
		if((mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6))
		if(getPressState(player, 0)) {
			PlaySE(5);
			changeRule(player, rots[player] - 1);
		}
		
		// ↓
		if((mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6))
		if(getPressState(player, 1)) {
			PlaySE(5);
			changeRule(player, rots[player] + 1);
		}
		
		// Bボタン
		if(getPushState(player, 5)) {
			statc[player * 10 + 3]--;
			return;
		}
		
		// Aボタン
		if(getPushState(player, 4)) {
			PlaySE(10);
			statc[player * 10 + 3]++;
			return;
		}
		
		// ポーズボタンでヘルプ
		if(IsPushKey(pause_key[player]) || getJoyPushState(0, joy_pause_key[player])) {
			PlaySE(0);
			showHelpString(player, help_rule[rots[player] + english * 10]);
			statc[player * 10 + 3] = 4;
			return;
		}
	}
	// モードセレクト
	else if(statc[player * 10 + 3] == 2) {
		printScoreFont(soffset[player], 20, "PAUSE:", fontc[rots[player]]);
		printScoreFont(soffset[player], 21, "HELP", fontc[rots[player]]);
		
		if(statc[player * 10 + 1] <= 7) {
			printScoreFont(soffset[player], 7 + top_frame, "C+A:", fontc[rots[player]]);
			printScoreFont(soffset[player], 8 + top_frame, "OPTIONS", fontc[rots[player]]);
		}
		
		// モード一覧表示
		printFont(boffset[player], 6, "SELECT", fontc[rots[player]]);
		printFont(boffset[player] + 1, 7, "GAME MODE", fontc[rots[player]]);
		
		printFont(boffset[player], 9 + statc[player * 10 + 1], "b", color2);
		
		for(i = 0; i < 9; i++) {
			printFont(boffset[player] + 1, 9 + i, mode_select_name[i], modecolor2[i]);
		}
		
		if(stat[1] == 0) {
			for(i = 9; i < 12; i++) {
				printFont(boffset[player] + 1, 9 + i, mode_select_name[i], modecolor2[i]);
			}
		}
		
		// ゲームタイプ表示
		// BEGINNER
		if(statc[player * 10 + 1] == 0) {
			if(statc[player * 10 + 2] == 0) sprintf(string[0], "<  TAMAYA  >");
			if(statc[player * 10 + 2] == 1) sprintf(string[0], "<  NOVICE  >");
			printFont(boffset[player] - 1, 23, string[0], color);
			
			if(timeattack[player]) printFont(boffset[player] + 1, 24, "ENDLESS", 0);
			
			printScoreFont(soffset[player], 10 + top_frame, "D:", fontc[rots[player]]);
			printScoreFont(soffset[player], 11 + top_frame, "ENDLESS", fontc[rots[player]]);
		}
		// MASTER
		else if(statc[player * 10 + 1] == 1) {
			if(statc[player * 10 + 2] == 0) sprintf(string[0], "<   EASY   >");
			if(statc[player * 10 + 2] == 1) sprintf(string[0], "<  NORMAL  >");
			if(statc[player * 10 + 2] == 2) sprintf(string[0], "<   HARD   >");
			if(statc[player * 10 + 2] == 3) sprintf(string[0], "< 20G-EASY >");
			if(statc[player * 10 + 2] == 4) sprintf(string[0], "<20G-NORMAL>");
			if(statc[player * 10 + 2] == 5) sprintf(string[0], "< 20G-HARD >");
			if(statc[player * 10 + 2] == 6) sprintf(string[0], "<   HEBO+  >");
			printFont(boffset[player] - 1, 23, string[0], color);
			
			if(timeattack[player]) printFont(boffset[player] + 1, 24, "ENDLESS", 0);
			
			printScoreFont(soffset[player], 10 + top_frame, "D:", fontc[rots[player]]);
			printScoreFont(soffset[player], 11 + top_frame, "ENDLESS", fontc[rots[player]]);
		}
		// DEVIL
		else if(statc[player * 10 + 1] == 2) {
			if(statc[player * 10 + 2] == 0) sprintf(string[0], "<  NORMAL  >");
			if(statc[player * 10 + 2] == 1) sprintf(string[0], "<   HARD   >");
			if(statc[player * 10 + 2] == 2) sprintf(string[0], "<   DOOM   >");
			printFont(boffset[player] - 1, 23, string[0], color);
			
			if(timeattack[player]) printFont(boffset[player] + 1, 24, "ENDLESS", 0);
			
			printScoreFont(soffset[player], 10 + top_frame, "D:", fontc[rots[player]]);
			printScoreFont(soffset[player], 11 + top_frame, "ENDLESS", fontc[rots[player]]);
		}
		// TOMOYO
		else if(statc[player * 10 + 1] == 3) {
			if(statc[player * 10 + 2] == 0) sprintf(string[0], "<  NORMAL  >");
			if(statc[player * 10 + 2] == 1) sprintf(string[0], "<  EHEART  >");
			if(statc[player * 10 + 2] == 2) sprintf(string[0], "<  TARGET  >");
			if(statc[player * 10 + 2] == 3) sprintf(string[0], "<  FLASH   >");
			if(statc[player * 10 + 2] == 4) sprintf(string[0], "<   EDIT   >");
			if(statc[player * 10 + 2] == 5) sprintf(string[0], "<FLASH-EDIT>");
			printFont(boffset[player] - 1, 23, string[0], color);
			
			if((timeattack[player]) && (statc[player * 10 + 2] != 3) && (statc[player * 10 + 2] != 5))
				printFont(boffset[player] + 1, 24, "RANDOM", 0);
			
			if((statc[player * 10 + 2] != 3) && (statc[player * 10 + 2] != 5)) {
				printScoreFont(soffset[player], 10 + top_frame, "D:", fontc[rots[player]]);
				printScoreFont(soffset[player], 11 + top_frame, "RANDOM", fontc[rots[player]]);
			}
		}
		// ACE
		else if(statc[player * 10 + 1] == 4) {
			if(statc[player * 10 + 2] == 0) sprintf(string[0], "<  NORMAL  >");
			if(statc[player * 10 + 2] == 1) sprintf(string[0], "<HI-SPEED 1>");
			if(statc[player * 10 + 2] == 2) sprintf(string[0], "<HI-SPEED 2>");
			if(statc[player * 10 + 2] == 3) sprintf(string[0], "< ANOTHER  >");
			if(statc[player * 10 + 2] == 4) sprintf(string[0], "< ANOTHER2 >");
			if(statc[player * 10 + 2] == 5) sprintf(string[0], "<  BASIC   >");
			if(statc[player * 10 + 2] == 6) sprintf(string[0], "<   HELL   >");
			if(statc[player * 10 + 2] == 7) sprintf(string[0], "<  HELL-X  >");
			if(statc[player * 10 + 2] == 8) sprintf(string[0], "<   VOID   >");
			printFont(boffset[player] - 1, 23, string[0], color);
		}
		// OLD STYLE
		else if(statc[player * 10 + 1] == 5) {
			if(statc[player * 10 + 2] == 0) sprintf(string[0], "< HANDHELD >");
			if(statc[player * 10 + 2] == 1) sprintf(string[0], "<  ARCADE  >");
			printFont(boffset[player] - 1, 23, string[0], color);
		}
		// FINAL
		else if(statc[player * 10 + 1] == 6) {
			if(timeattack[player]) printFont(boffset[player] + 1, 24, "ENDLESS", 0);
			printScoreFont(soffset[player], 10 + top_frame, "D:", fontc[rots[player]]);
			printScoreFont(soffset[player], 11 + top_frame, "ENDLESS", fontc[rots[player]]);
		}
		// MARATHON
		else if(statc[player * 10 + 1] == 7) {
			if(statc[player * 10 + 2] == 0) sprintf(string[0], "<  NORMAL  >");
			if(statc[player * 10 + 2] == 1) sprintf(string[0], "<  SQUARE  >");
			if(statc[player * 10 + 2] == 2) sprintf(string[0], "<   ONI    >");
			printFont(boffset[player] - 1, 23, string[0], color);
		}
		// SIMPLE
		else if(statc[player * 10 + 1] == 8) {
			if((statc[player * 10 + 2] == 0) || (statc[player * 10 + 2] == 2)) sprintf(string[0], "< 40LINES  >");
			if((statc[player * 10 + 2] == 1) || (statc[player * 10 + 2] == 3)) sprintf(string[0], "<  ULTRA   >");
			printFont(boffset[player] - 1, 23, string[0], color);
			
			if(statc[player * 10 + 2] >= 2) {
				printFont(boffset[player], 24, "ROT. RELAY", 0);
			}
		}
		
		// キー入力
		// ↑
		if((mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6))
		if(getPressState(player, 0)) {
			PlaySE(5);
			statc[player * 10 + 1]--;
			if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = 8 + (stat[1] == 0) * 3;
			
			statc[player * 10 + 2] = 0;
			timeattack[player] = 0;
		}
		
		// ↓
		if((mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6))
		if(getPressState(player, 1)) {
			PlaySE(5);
			statc[player * 10 + 1]++;
			if(statc[player * 10 + 1] > 8 + (stat[1] == 0) * 3) statc[player * 10 + 1] = 0;
			
			statc[player * 10 + 2] = 0;
			timeattack[player] = 0;
		}
		
		if((stat[1] != 0) && (statc[player * 10 + 1] > 8)) {
			statc[player * 10 + 1] = 0;
			statc[player * 10 + 2] = 0;
			timeattack[player] = 0;
		}
		
		// ←
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
		if(getPressState(player, 2)) {
			PlaySE(3);
			statc[player * 10 + 2]--;
			
			if((statc[player * 10 + 1] == 0) && (statc[player * 10 + 2] < 0)) statc[player * 10 + 2] = 1;
			if((statc[player * 10 + 1] == 1) && (statc[player * 10 + 2] < 0)) statc[player * 10 + 2] = 6;
			if((statc[player * 10 + 1] == 2) && (statc[player * 10 + 2] < 0)) statc[player * 10 + 2] = 2;
			if((statc[player * 10 + 1] == 3) && (statc[player * 10 + 2] < 0)) statc[player * 10 + 2] = 5;
			if((statc[player * 10 + 1] == 4) && (statc[player * 10 + 2] < 0)) statc[player * 10 + 2] = 8;
			if((statc[player * 10 + 1] == 5) && (statc[player * 10 + 2] < 0)) statc[player * 10 + 2] = 1;
			if((statc[player * 10 + 1] == 6) && (statc[player * 10 + 2] < 0)) statc[player * 10 + 2] = 0;
			if((statc[player * 10 + 1] == 7) && (statc[player * 10 + 2] < 0)) statc[player * 10 + 2] = 2;
			if((statc[player * 10 + 1] == 8) && (statc[player * 10 + 2] < 0)) statc[player * 10 + 2] = 3;
		}
		
		// →
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
		if(getPressState(player, 3)) {
			PlaySE(3);
			statc[player * 10 + 2]++;
			
			if((statc[player * 10 + 1] == 0) && (statc[player * 10 + 2] > 1)) statc[player * 10 + 2] = 0;
			if((statc[player * 10 + 1] == 1) && (statc[player * 10 + 2] > 6)) statc[player * 10 + 2] = 0;
			if((statc[player * 10 + 1] == 2) && (statc[player * 10 + 2] > 2)) statc[player * 10 + 2] = 0;
			if((statc[player * 10 + 1] == 3) && (statc[player * 10 + 2] > 5)) statc[player * 10 + 2] = 0;
			if((statc[player * 10 + 1] == 4) && (statc[player * 10 + 2] > 8)) statc[player * 10 + 2] = 0;
			if((statc[player * 10 + 1] == 5) && (statc[player * 10 + 2] > 1)) statc[player * 10 + 2] = 0;
			if((statc[player * 10 + 1] == 6) && (statc[player * 10 + 2] > 0)) statc[player * 10 + 2] = 0;
			if((statc[player * 10 + 1] == 7) && (statc[player * 10 + 2] > 2)) statc[player * 10 + 2] = 0;
			if((statc[player * 10 + 1] == 8) && (statc[player * 10 + 2] > 3)) statc[player * 10 + 2] = 0;
		}
		
		// Dボタン
		if(getPushState(player, 7)) {
			PlaySE(5);
			timeattack[player] = !timeattack[player];
		}
		
		// Bボタン
		if(getPushState(player, 5)) {
			PlaySE(5);
			statc[player * 10 + 3]--;
			return;
		}
		
		// C+Aボタン
		if(getPressState(player, 6) && getPressState(player, 4) && (statc[player * 10 + 1] <= 7)) {
			PlaySE(10);
			statc[player * 10 + 3] = 3;
			return;
		}
		
		// Aボタン
		if(getPushState(player, 4)) {
			PlaySE(10);
			startGame(player, statc[player * 10 + 1], statc[player * 10 + 2], 0);
			return;
		}
		
		// ポーズボタンでヘルプ
		if(IsPushKey(pause_key[player]) || getJoyPushState(0, joy_pause_key[player])) {
			PlaySE(0);
			showHelpString(player, help_mode[statc[player * 10 + 1] + english * 12]);
			statc[player * 10 + 3] = 5;
			return;
		}
	}
	// オプション画面
	else if(statc[player * 10 + 3] == 3) {
		// オプション一覧表示
		printFont(boffset[player], 6, "SELECT", fontc[rots[player]]);
		printFont(boffset[player] + 3, 7, "OPTIONS", fontc[rots[player]]);
		
		printFont(boffset[player], 10 + statc[player * 10 + 4] * 2, "b", color);
		
		if(statc[player * 10 + 1] == 3) {
			printFont(boffset[player], 9, "STAGE", fontc[rots[player]]);
			sprintf(string[0], "%d", start_stage[player] + 1);
			printFont(boffset[player] + 1, 10, string[0], (statc[player * 10 + 4] == 0) * color);
			
			printFont(boffset[player], 11, "EDIT MODE", fontc[rots[player]]);
			printFont(boffset[player] + 1, 12, "PRESS A", (statc[player * 10 + 4] == 1) * color);
			
			printFont(boffset[player], 13, "FLASH EDIT", fontc[rots[player]]);
			printFont(boffset[player] + 1, 14, "PRESS A", (statc[player * 10 + 4] == 2) * color);
		} else {
			printFont(boffset[player], 9, "BIG ON/OFF", fontc[rots[player]]);
			if(!IsBigStart[player]) sprintf(string[0], "e");
			else sprintf(string[0], "c");
			printFont(boffset[player] + 1, 10, string[0], (statc[player * 10 + 4] == 0) * color);
			
			printFont(boffset[player], 11, "BIG MOVE", fontc[rots[player]]);
			sprintf(string[0], "%d", BigMoveStart[player] + 1);
			printFont(boffset[player] + 1, 12, string[0], (statc[player * 10 + 4] == 1) * color);
			
			printFont(boffset[player], 13, "ITEM", fontc[rots[player]]);
			if(!item_mode[player]) sprintf(string[0], "e");
			else sprintf(string[0], "c");
			printFont(boffset[player] + 1, 14, string[0], (statc[player * 10 + 4] == 2) * color);
		}
		
		// キー入力
		// ↑
		if((mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6))
		if(getPressState(player, 0)) {
			PlaySE(5);
			statc[player * 10 + 4]--;
			
			if((statc[player * 10 + 1] == 3) && (statc[player * 10 + 4] < 0)) statc[player * 10 + 4] = 2;
			if((statc[player * 10 + 1] != 3) && (statc[player * 10 + 4] < 0)) statc[player * 10 + 4] = 2;
		}
		
		// ↓
		if((mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6))
		if(getPressState(player, 1)) {
			PlaySE(5);
			statc[player * 10 + 4]++;
			
			if((statc[player * 10 + 1] == 3) && (statc[player * 10 + 4] > 2)) statc[player * 10 + 4] = 0;
			if((statc[player * 10 + 1] != 3) && (statc[player * 10 + 4] > 2)) statc[player * 10 + 4] = 0;
		}
		
		// ←
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
		if(getPressState(player, 2)) {
			PlaySE(3);
			
			if(statc[player * 10 + 1] == 3) {
				if(statc[player * 10 + 4] == 0) {
					start_stage[player]--;
					if(start_stage[player] < 0) start_stage[player] = 999;
					stage[player] = start_stage[player];
				}
			} else {
				if(statc[player * 10 + 4] == 0) IsBigStart[player] = !IsBigStart[player];
				if(statc[player * 10 + 4] == 1) BigMoveStart[player] = !BigMoveStart[player];
				if(statc[player * 10 + 4] == 2) item_mode[player] = !item_mode[player];
			}
		}
		
		// →
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
		if(getPressState(player, 3)) {
			PlaySE(3);
			
			if(statc[player * 10 + 1] == 3) {
				if(statc[player * 10 + 4] == 0) {
					start_stage[player]++;
					if(start_stage[player] > 999) start_stage[player] = 0;
					stage[player] = start_stage[player];
				}
			} else {
				if(statc[player * 10 + 4] == 0) IsBigStart[player] = !IsBigStart[player];
				if(statc[player * 10 + 4] == 1) BigMoveStart[player] = !BigMoveStart[player];
				if(statc[player * 10 + 4] == 2) item_mode[player] = !item_mode[player];
			}
		}
		
		// Bボタン
		if(getPushState(player, 5)) {
			PlaySE(5);
			statc[player * 10 + 3]--;
			return;
		}
		
		// Aボタン
		if(getPushState(player, 4)) {
			PlaySE(10);
			
			if((statc[player * 10 + 1] == 3) && (statc[player * 10 + 4] == 1)) {
				// TOMOYOエディット
				if(!onRecord[1 - player]) StopAllBGM();
				
				gameMode[player] = 6;
				stat[player] = 20;
				for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
				
				stage[player] = start_stage[player];
				loadTomoyoStage(player, stage[player], 0);
			} else if((statc[player * 10 + 1] == 3) && (statc[player * 10 + 4] == 2)) {
				// FLASHエディット
				if(!onRecord[1 - player]) StopAllBGM();
				
				gameMode[player] = 15;
				stat[player] = 20;
				for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
				
				stage[player] = start_stage[player];
				loadTomoyoStage(player, stage[player], 2);
			} else {
				startGame(player, statc[player * 10 + 1], statc[player * 10 + 2], 1);
			}
			
			return;
		}
	}
	// ヘルプ（ルール）
	else if(statc[player * 10 + 3] == 4) {
		getRuleNameEx(rots[player], 0);
		printFont(boffset[player], 6, string[0], fontc[rots[player]]);
		
		if(getPushState(player, 4) || getPushState(player, 5)) {
			TextLayerOff(player);
			statc[player * 10 + 3] = 1;
			return;
		}
	}
	// ヘルプ（モード）
	else if(statc[player * 10 + 3] == 5) {
		printFont(boffset[player], 6, mode_select_name[statc[player * 10 + 1]], modecolor2[statc[player * 10 + 1]]);
		
		if(getPushState(player, 4) || getPushState(player, 5)) {
			TextLayerOff(player);
			statc[player * 10 + 3] = 2;
			return;
		}
	}
}

// 説明文を表示
void showHelpString(int player, str *helpStr) {
	int i, j, draw_rate;
	
	// 自動改行
	sprintf(string[0], "");
	j = 0;
	for(i = 0; i < StrLen(helpStr); i++) {
		MidStr(helpStr, i + 1, 1, string[1]);
		StrCat(string[0], string[1]);
		
		// 16バイトごとに改行
		if(j >= 15) {
			StrCat(string[0], "\n");
			j = 0;
		} else {
			j++;
		}
	}
	
	// 表示
	TextLayerOff(player);
	
	if(screenMode >= 2) draw_rate = 2;
	else draw_rate = 1;
	
	TextSize(player, 10 * draw_rate);
	TextColor(player, 255, 255, 255);
	TextBackColorDisable(player);
	TextOut(player, string[0]);
	TextLayerOn(player, (foffset[player] + 8) * draw_rate, 56 * draw_rate);
}

// 段位試験に入るかどうか判定
void admitGradeCheck(int player) {
	int i, j, temp1, temp2, grade_his_buf[5];
	int grade_his[5], admit_grade, grade_pasttime;
	
	// 準備
	examination[player] = 0;
	
	admit_grade = user_master_hard_admit[player];
	grade_pasttime = user_master_hard_grade_pasttime[player];
	for(i = 0; i < 5; i++) {
		grade_his[i] = user_master_hard_grade_his[player * 5 + i];
		if((grade_his[i] < 0) || (grade_his[i] > 32)) return;
	}
	
	if(admit_grade >= 32) return;	// 認定段位がGMだったら何もしない
	
	// 昇格チェック
	if(admit_grade < 32) {
		temp2 = 5 - grade_pasttime; // 試験から経過時間
		if(temp2 < 1) temp2 = 1; // 0にはしない
		if((grade_his[0] == grade_his[1]) && (abs(admit_grade - grade_his[0]) > temp2)) {
			exam_grade[player] = grade_his[0];
			
			// 現在の認定段位と試験段位の差が大きくなりすぎないようにする
			if(exam_grade[player] - admit_grade > 5) exam_grade[player] = admit_grade + 5;
			
			if((exam_grade[player] >= 1) && (exam_grade[player] <= 32) && (exam_grade[player] > admit_grade)) {
				examination[player] = 1;
				return;
			}
		}
		
		temp1 = grade_his[0] + grade_his[1] + grade_his[2] / 3;
		temp2 = 4 - grade_pasttime;
		if(temp2 < 1) temp2 = 1;
		if((temp1 % 3 == 0) && (abs(admit_grade - grade_his[0]) > temp2)) {
			exam_grade[player] = temp1;
			
			// 現在の認定段位と試験段位の差が大きくなりすぎないようにする
			if(exam_grade[player] - admit_grade > 5) exam_grade[player] = admit_grade + 5;
			
			if((exam_grade[player] >= 1) && (exam_grade[player] <= 32) && (exam_grade[player] > admit_grade)) {
				examination[player] = 1;
				return;
			}
		}
		
		temp1 = grade_his[0] + grade_his[1] + grade_his[2] + grade_his[3] / 3;
		temp2 = 3 - grade_pasttime;
		if(temp2 < 1) temp2 = 1;
		if((grade_pasttime >= 2) && (temp1 == 0) && (abs(admit_grade - temp1) > temp2)) {
			exam_grade[player] = temp1;
			
			// 現在の認定段位と試験段位の差が大きくなりすぎないようにする
			if(exam_grade[player] - admit_grade > 5) exam_grade[player] = admit_grade + 5;
			
			if((exam_grade[player] >= 1) && (exam_grade[player] <= 32) && (exam_grade[player] > admit_grade)) {
				examination[player] = 1;
				return;
			}
		}
	}
	
	// 降格チェック
	// 認定段位が高くなると落ちやすくなる
	// 認定段位がS3以上で最後の試験から2ゲーム以上経過していると発生する可能性あり
	
	// m8以上
	if((admit_grade > 24) && (grade_pasttime >= 2)) {
		if((grade_his[0] + grade_his[1]) / 2 < admit_grade - 3) {
			exam_grade[player] = grade_his[0];
			
			if((exam_grade[player] >= 1) && (exam_grade[player] <= 32) && (exam_grade[player] < admit_grade)) {
				examination[player] = 2;
				return;
			}
		}
	}
	
	// m2以上
	if((admit_grade > 18) && (grade_pasttime >= 2)) {
		if((grade_his[0] + grade_his[1] + grade_his[2]) / 3 < admit_grade - 4) {
			exam_grade[player] = grade_his[0];
			
			if((exam_grade[player] >= 1) && (exam_grade[player] <= 32) && (exam_grade[player] < admit_grade)) {
				examination[player] = 2;
				return;
			}
		}
	}
	
	// S3以上
	if((admit_grade > 10) && (grade_pasttime >= 2)) {
		// 履歴並べ替え作業
		// バッファに入れる
		for(i = 0; i < 5; i++) grade_his_buf[i] = grade_his[i];
		
		// バブルソート
		for(i = 0; i < 4; i++) {
			for(j = 4; j > i; j--) {
				// 前の要素の方が大きかったら交換する
				if(grade_his_buf[j - 1] > grade_his_buf[j]) {
					temp1 = grade_his_buf[j];
					grade_his_buf[j] = grade_his_buf[j - 1];
					grade_his_buf[j - 1] = temp1;
				}
			}
		}
		
		// 大きいほうから3つの平均が現在より5つ下
		if((grade_his[0] + grade_his[1] + grade_his[2] + grade_his[3] + grade_his[4]) / 3 < admit_grade - 5) {
			exam_grade[player] = grade_his_buf[0];
			
			if((exam_grade[player] >= 1) && (exam_grade[player] <= 32) && (exam_grade[player] < admit_grade)) {
				examination[player] = 2;
				return;
			}
		}
	}
}

// ゲーム開始処理
void startGame(int player, int mode, int type, int opt) {
	int i;
	
	// 最後に選んだゲームモードを記憶
	lastmode[player] = mode;
	lasttype[player] = type;
	
	// ゲームモードを設定
	// BEGINNER
	if(mode == 0) {
		// TAMAYA
		if(type == 0) gameMode[player] = 0;
		// NOVICE
		if(type == 1) gameMode[player] = 13;
		
		timeattack[player] = !timeattack[player];
	}
	// MASTER
	else if(mode == 1) {
		// EASY
		if(type == 0) {
			gameMode[player] = 1;
			gradetype[player] = 2;
		}
		// NORMAL
		if(type == 1) {
			gameMode[player] = 1;
			gradetype[player] = 0;
		}
		// HARD
		if(type == 2) {
			gameMode[player] = 1;
			gradetype[player] = 1;
		}
		// 20G-EASY
		if(type == 3) {
			gameMode[player] = 2;
			gradetype[player] = 2;
		}
		// 20G-NORMAL
		if(type == 4) {
			gameMode[player] = 2;
			gradetype[player] = 0;
		}
		// 20G-HARD
		if(type == 5) {
			gameMode[player] = 2;
			gradetype[player] = 1;
		}
		// HEBO+
		if(type == 6) {
			gameMode[player] = 10;
		}
		
		timeattack[player] = !timeattack[player];
	}
	// DEVIL
	else if(mode == 2) {
		// NORMAL
		if(type == 0) {
			gameMode[player] = 11;
		}
		// HARD
		if(type == 1) {
			gameMode[player] = 16;
			r_enable[player] = 1;
		}
		// DOOM
		if(type == 2) {
			gameMode[player] = 3;
			r_enable[player] = 1;
		}
		
		timeattack[player] = !timeattack[player];
	}
	// TOMOYO
	else if(mode == 3) {
		// NORMAL
		if(type == 0) {
			gameMode[player] = 6;
			if(!opt) start_stage[player] = 0;
		}
		// EHEART
		if(type == 1) {
			gameMode[player] = 6;
			if(!opt) start_stage[player] = 27;
		}
		// TARGET
		if(type == 2) {
			gameMode[player] = 6;
			if(!opt) start_stage[player] = 45;
		}
		// FLASH
		if(type == 3) {
			gameMode[player] = 15;
			start_stage[player] = 0;
			timeattack[player] = 0;
		}
		// EDIT
		if(type == 4) {
			gameMode[player] = 6;
			if(!opt) start_stage[player] = 72;
		}
		// FLASH-EDIT
		if(type == 5) {
			gameMode[player] = 15;
			start_stage[player] = 0;
			timeattack[player] = 0;
			flash_edit[player] = 1;
		}
		
		stage[player] = start_stage[player];
		
		// NEXT初期化
		if((!timeattack[player]) && (type != 3) && (type != 5)) {
			tomoyoNextInit(player, 0);
			setNextBlockColors(player, 1);
		}
	}
	// ACE
	else if(mode == 4) {
		if(type <= 4) {
			// NORMAL～ANOTHER2
			gameMode[player] = 7;
			timeattack[player] = type;
		} else {
			// BASIC～VOID
			gameMode[player] = 12;
			timeattack[player] = type - 5;
		}
	}
	// OLD STYLE
	else if(mode == 5) {
		gameMode[player] = 9;
		timeattack[player] = type;
	}
	// FINAL
	else if(mode == 6) {
		gameMode[player] = 14;
		timeattack[player] = !timeattack[player];
	}
	// MARATHON
	else if(mode == 7) {
		gameMode[player] = 18;
		timeattack[player] = type;
	}
	// SIMPLE
	else if(mode == 8) {
		gameMode[player] = 17;
		timeattack[player] = type;
	}
	// VERSUS
	else if(mode == 9) {
		enterVersusMode();
		return;
	}
	// MISSION
	else if(mode == 10) {
		enterMissionMode();
		return;
	}
	// PRACTICE
	else if(mode == 11) {
		enterPracticeMode();
		return;
	}
	
	// BIG設定
	IsBig[player] = IsBigStart[player];
	BigMove[player] = BigMoveStart[player];
	
	// BGM停止
	if(stat[1 - player] == 0) StopAllBGM();
	
	// 開始スピード設定
	setStartLevel(player);
	
	// 開始BGM設定
	setstartBGM(player);
	
	for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
	stat[player] = 1;				// ブロックシャッター実行
	statc[player * 10] = 0;			// ステータスカウンタを0に
	statc[player * 10 + 1] = 3;		// シャッター後はステータスNo.3
	
	if(gameMode[player] == 15) statc[player * 10 + 1] = 36;	// FLASH用セレクト画面
	if(gameMode[player] == 17) statc[player * 10 + 1] = 38;	// SIMPLE用セレクト画面
	
	// MASTER-HARD段位試験
	if((gameMode[player] == 1) && (gradetype[player] == 1) && (user_enable[player])) {
		admitGradeCheck(player);
		if(examination[player]) statc[player * 10 + 1] = 40;
	}
}

// 開始スピードなどを設定
void setStartLevel(int player) {
	jump(gameMode[player],lbeg,lmas,l20g,ldvl,lvs,lpra,ltmo,lace,lmis,lold,lhep,ldvm,lace200,lbeg,lfinal,ltmo,ledvl,lstd,lmar);
	
	/*
	switch(gameMode[player]) {
		case  0: goto lbeg;
		case  1: goto lmas;
		case  2: goto l20g;
		case  3: goto ldvl;
		case  4: goto lvs;
		case  5: goto lpra;
		case  6: goto ltmo;
		case  7: goto lace;
		case  8: goto lmis;
		case  9: goto lold;
		case 10: goto lhep;
		case 11: goto ldvm;
		case 12: goto lace200;
		case 13: goto lbeg;
		case 14: goto lfinal;
		case 15: goto ltmo;
		case 16: goto ledvl;
		case 17: goto lstd;
		case 18: goto lmar;
	}
	*/
	
	lbeg:	// BEGINNER-TAMAYA
		sp[player] = lvTableBeg[0];
		wait1[player] = wait1_Beginner;
		wait2[player] = wait2_Beginner;
		wait3[player] = wait3_Beginner;
		waitt[player] = waitt_Beginner;
		return;
	
	lmas:	// MASTER
		sp[player]    = lvTableTgm[0];
		wait1[player] = wait1_master_half;
		wait2[player] = wait2_master_half;
		wait3[player] = wait3_master_half;
		waitt[player] = waitt_master_half;
		
		// 足切りタイム設定 #LITE20
		if(!playback) {
			timelimit[0 + player * 2] = timelimit_master[rots[player]];
		}
		return;
	
	l20g:	// 20G
		sp[player]    = 1200;
		wait1[player] = wait1_20G_half;
		wait2[player] = wait2_20G_half;
		wait3[player] = wait3_20G_half;
		waitt[player] = waitt_20G_half;
		
		// 足切りタイム設定 #LITE20
		if(!playback) {
			timelimit[0 + player * 2] = timelimit_20G[rots[player]];
		}
		return;
	
	ldvl:	// DEVIL-DOOM
		sp[player]    = 1200;
		
		if(repversw <= 6) {
			wait1[player] = wait1_devil_tbl6[0];
			wait2[player] = wait2_devil_tbl6[0];
			wait3[player] = wait3_devil_tbl6[0];
			waitt[player] = waitt_devil_tbl6[0];
		} else if(repversw <= 7) {
			wait1[player] = wait1_devil_tbl7[0];
			wait2[player] = wait2_devil_tbl7[0];
			wait3[player] = wait3_devil_tbl7[0];
			waitt[player] = waitt_devil_tbl7[0];
		} else {
			wait1[player] = wait1_devil_tbl[0];
			wait2[player] = wait2_devil_tbl[0];
			wait3[player] = wait3_devil_tbl[0];
			waitt[player] = waitt_devil_tbl[0];
		}
		
		// 足切りタイム設定 #LITE20
		if(!playback) {
			timelimit[0 + player * 2] = timelimit_devild[rots[player]];
			timelimit[1 + player * 2] = timelimit[0 + player * 2] * 2;
		}
		return;
	
	lvs:	// VERSUS
		return;
	
	lpra:	// PRACTICE
		return;
	
	ltmo:	// TOMOYO
		sp[player]    = lvTabletomoyo[0];
		wait1[player] = wait1_tomoyo;
		wait2[player] = wait2_tomoyo;
		wait3[player] = wait3_tomoyo;
		waitt[player] = waitt_tomoyo;
		return;
	
	lace:	// ACE (NORMAL～ANOTHER2）
		if(timeattack[player] == 0) {
			// NORMAL
			if(repversw >= 2) sp[player] = lvTableAce[0];
			else if(repversw == 1) sp[player] = lvTableAce1[0];
			else sp[player] = lvTableAceOld[0];
			wait1[player] = wait1_Ace;
			wait2[player] = wait2_Ace;
			wait3[player] = wait3_Ace;
			waitt[player] = waitt_Ace;
			ltime[player] = timeLimitAceNormal[0];
		} else if(timeattack[player] == 1) {
			// HI-SPEED1
			sp[player] = lvTableHiSpeed1[0];
			wait1[player] = wait1_HiSpeed1;
			wait2[player] = wait2_HiSpeed1;
			wait3[player] = wait3_HiSpeed1;
			waitt[player] = waitt_HiSpeed1;
			ltime[player] = timeLimitAcea[0];
		} else if(timeattack[player] == 2) {
			// HI-SPEED2
			sp[player] = 1200;
			wait1[player] = wait1_HiSpeed2;
			wait2[player] = wait2_HiSpeed2;
			wait3[player] = wait3_HiSpeed2;
			waitt[player] = waitt_HiSpeed2;
			ltime[player] = timeLimitAcea[0];
		} else if(timeattack[player] == 3) {
			// ANOTHER
			sp[player] = 1200;
			
			if(repversw <= 6) {
				wait1[player] = wait1_Acea_tbl6[0];
				wait2[player] = wait2_Acea_tbl6[0];
				wait3[player] = wait3_Acea_tbl6[0];
				waitt[player] = waitt_Acea_tbl6[0];
			} else if(repversw <= 7) {
				wait1[player] = wait1_Acea_tbl7[0];
				wait2[player] = wait2_Acea_tbl7[0];
				wait3[player] = wait3_Acea_tbl7[0];
				waitt[player] = waitt_Acea_tbl7[0];
			} else {
				wait1[player] = wait1_Acea_tbl[0];
				wait2[player] = wait2_Acea_tbl[0];
				wait3[player] = wait3_Acea_tbl[0];
				waitt[player] = waitt_Acea_tbl[0];
			}
			
			ltime[player] = timeLimitAcea[0];
		} else if(timeattack[player] == 4) {
			// ANOTHER2
			sp[player] = 1200;
			
			if(repversw <= 6) {
				wait1[player] = wait1_Acea_tbl6[14];
				wait2[player] = wait2_Acea_tbl6[14];
				wait3[player] = wait3_Acea_tbl6[14];
				waitt[player] = waitt_Acea_tbl6[14];
			} else if(repversw <= 7) {
				wait1[player] = wait1_Acea_tbl7[14];
				wait2[player] = wait2_Acea_tbl7[14];
				wait3[player] = wait3_Acea_tbl7[14];
				waitt[player] = waitt_Acea_tbl7[14];
			} else {
				wait1[player] = wait1_Acea_tbl[14];
				wait2[player] = wait2_Acea_tbl[14];
				wait3[player] = wait3_Acea_tbl[14];
				waitt[player] = waitt_Acea_tbl[14];
			}
			
			ltime[player] = timeLimitAcea[0];
		}
		
		m_norm[player] = 10;
		tc[player] = 0;
		return;
	
	lmis:	// MISSION
		return;
	
	lold:	// OLD STYLE
		if(timeattack[player] == 0) {
			sp[player] = lvTableHeboGB[0];
			wait1[player] = wait1_HeboGB;
			wait2[player] = wait2_HeboGB;
			wait3[player] = wait3_HeboGB_tbl[0];
			waitt[player] = waitt_HeboGB_tbl[0];
			heboGB[player] = 1;
			m_norm[player] = 10;
		} else {
			sp[player] = lvTableHeboAC[0];
			wait1[player] = wait1_HeboAC;
			wait2[player] = wait2_HeboAC;
			wait3[player] = wait3_HeboAC;
			waitt[player] = waitt_HeboAC;
			speedtype[player] = 1;
			heboGB[player] = 2;
		}
		
		tc[player] = 0;
		return;
	
	lhep:	// HEBO+
		sp[player]    = lvTableTgm[0];
		wait1[player] = wait1_master_half;
		wait2[player] = wait2_master_half;
		wait3[player] = wait3_master_half;
		waitt[player] = waitt_master_half;
		
		// せり上がり用
		uplinetype[player] = 1;
		r_inter[player] = 13;
		return;
	
	ldvm:	// DEVIL-NORMAL
		sp[player] = 1200;
		
		if(repversw <= 6) {
			wait1[player] = wait1_devil_m_tbl6[0];
			wait2[player] = wait2_devil_m_tbl6[0];
			wait3[player] = wait3_devil_m_tbl6[0];
			waitt[player] = waitt_devil_m_tbl6[0];
		} else {
			wait1[player] = wait1_devil_m_tbl[0];
			wait2[player] = wait2_devil_m_tbl[0];
			wait3[player] = wait3_devil_m_tbl[0];
			waitt[player] = waitt_devil_m_tbl[0];
		}
		
		// 足切りタイム設定
		if(!playback) {
			timelimit[0 + player * 2] = timelimit_deviln[rots[player]];
		}
		return;
	
	lace200:	// ACE (BASIC～VOID）
		if(timeattack[player] == 0) {
			// BASIC
			sp[player] = lvTableAce200Basic[0];
			wait1[player] = wait1_Ace200Basic_tbl[0];
			wait2[player] = wait2_Ace200Basic_tbl[0];
			wait3[player] = wait3_Ace200Basic_tbl[0];
			waitt[player] = waitt_Ace200Basic_tbl[0];
			ltime[player] = timeLimitAce200Basic[0];
		} else if(timeattack[player] == 1) {
			// HELL
			sp[player] = lvTableAce200Basic[19];
			wait1[player] = wait1_Ace200Basic_tbl[19];
			wait2[player] = wait2_Ace200Basic_tbl[19];
			wait3[player] = wait3_Ace200Basic_tbl[19];
			waitt[player] = waitt_Ace200Basic_tbl[19];
			ltime[player] = timeLimitAce200Hell[0];
			
			isblind[player] = 1;
		} else if(timeattack[player] == 2) {
			// HELL-X
			sp[player] = lvTableAce200Basic[19];
			wait1[player] = wait1_Ace200Basic_tbl[19];
			wait2[player] = wait2_Ace200Basic_tbl[19];
			wait3[player] = wait3_Ace200Basic_tbl[19];
			waitt[player] = waitt_Ace200Basic_tbl[19];
			ltime[player] = timeLimitAce200Hell[0];
			
			always_over1000[player] = 1;
			o_nblk[0 + player * 6] = 1;
			o_nblk[1 + player * 6] = 1;
			o_nblk[2 + player * 6] = 1;
			o_nblk[3 + player * 6] = 1;
			o_nblk[4 + player * 6] = 1;
			o_nblk[5 + player * 6] = 1;
		} else if(timeattack[player] == 3) {
			// VOID
			sp[player] = lvTableAce200Basic[19];
			wait1[player] = wait1_Ace200Void_tbl[0];
			wait2[player] = wait2_Ace200Void_tbl[0];
			wait3[player] = wait3_Ace200Void_tbl[0];
			waitt[player] = waitt_Ace200Void_tbl[0];
			ltime[player] = timeLimitAce200Void[0];
			
			always_over1000[player] = 1;
			o_nblk[0 + player * 6] = 1;
			o_nblk[1 + player * 6] = 1;
			o_nblk[2 + player * 6] = 1;
			o_nblk[3 + player * 6] = 1;
			o_nblk[4 + player * 6] = 1;
			o_nblk[5 + player * 6] = 1;
		}
		
		m_norm[player] = 10;
		tc[player] = 0;
		return;
	
	lfinal:		// FINAL
		sp[player]    = 1200;
		
		if(repversw <= 4) {
			wait1[player] = wait1_final4[0];
			wait2[player] = wait2_final4[0];
			wait3[player] = wait3_final4[0];
			waitt[player] = waitt_final4[0];
		} else {
			if(rule_lock_reset[rots[player]]) {
				wait1[player] = wait1_final_srs[0];
				wait2[player] = wait2_final_srs[0];
				wait3[player] = wait3_final_srs[0];
				waitt[player] = waitt_final_srs[0];
			} else {
				wait1[player] = wait1_final_ars[0];
				wait2[player] = wait2_final_ars[0];
				wait3[player] = wait3_final_ars[0];
				waitt[player] = waitt_final_ars[0];
			}
		}
		
		always_over1000[player] = 1;
		o_nblk[0 + player * 6] = 1;
		o_nblk[1 + player * 6] = 1;
		o_nblk[2 + player * 6] = 1;
		o_nblk[3 + player * 6] = 1;
		o_nblk[4 + player * 6] = 1;
		o_nblk[5 + player * 6] = 1;
		
		return;
	
	ledvl:		// DEVIL-HARD
		sp[player]    = 1200;
		wait1[player] = wait1_devil_tbl32[0];
		wait2[player] = wait2_devil_tbl32[0];
		wait3[player] = wait3_devil_tbl32[0];
		waitt[player] = waitt_devil_tbl32[0];
		
		// 足切りタイム設定
		if(!playback) {
			timelimit[0 + player * 2] = timelimit_devilh[rots[player]];
			timelimit[1 + player * 2] = timelimit[0 + player * 2] * 2;
		}
		return;
	
	lstd:		// SIMPLE
		tc[player] = 0;
		if((timeattack[player] == 0) || (timeattack[player] == 2)) m_norm[player] = 40;
		if((timeattack[player] == 1) || (timeattack[player] == 3)) ltime[player] = 7200;
		return;
	
	lmar:		// MARATHON
		tc[player] = 0;
		m_norm[player] = 5;
		
		if(timeattack[player] == 2) {
			// 鬼
			sp[player] = 1200;
			wait1[player] = wait1_Marathon_Oni[0];
			wait2[player] = wait2_Marathon_Oni[0];
			wait3[player] = wait3_Marathon_Oni[0];
			waitt[player] = waitt_Marathon_Oni[0];
		} else {
			// 通常
			sp[player] = lvTableMarathon[0];
			wait1[player] = wait1_Ace;
			wait2[player] = wait2_Ace;
			wait3[player] = wait3_Ace;
			waitt[player] = waitt_Ace;
			speedtype[player] = 1;
		}
		
		// スクウェア
		if(timeattack[player] == 1) {
			squaremode[player] = 1;
		}
		return;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.03 - Ready !?
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statReady(int player) {
	int i, tmp;
	
	// CPUの操作
	if( (cpu_flag[player]) && ((!replayauto) || (repversw <= 3)) ) {
		if(!statc[player * 10]) cpu_setBestSpot(player, next[player], 0, getNextBlock(player, nextc[player] + 1), 0);
		
		cpu_setCtrl(player);
	}
	
	padRepeat(player);
	
	if(statc[player * 10] == 0) {
		ready_count[player]++;
	}
	
	// プレイ回数+1 (プレイヤーデータ使用時)
	if((statc[player * 10] == 0) && (ready_count[player] == 1) && (user_enable[player])) {
		user_playcount[player]++;
	}
	
	// READY→GOの時間を設定
	if( (!playback) && (statc[player * 10] == 0) ) {
		if( ((nextskip == 0) && (gameMode[player] == 6)) || 
		    ((nextskip == 1) && ((gameMode[player] == 6) || (gameMode[player] == 15))) || 
		    (nextskip == 2) )
		{
			// TOMOYO
			ready_start[player] = s_ready_start;
			ready_end[player]   = s_ready_end;
			go_start[player]    = s_go_start;
			go_end[player]      = s_go_end;
		} else {
			// 通常
			ready_start[player] = n_ready_start;
			ready_end[player]   = n_ready_end;
			go_start[player]    = n_go_start;
			go_end[player]      = n_go_end;
		}
	}
	
	if( (gameMode[player] == 6) && (statc[player * 10] == 0) ) {
		// TOMOYOモードのステージ読み込み
		loadTomoyoStage(player, stage[player], 0);
		
		// プラチナブロック数を数える
		rest_pblock[player] = getPlatinumBlock(player);
		
		// プラチナブロックが1つもない場合はエンディング
		if(!rest_pblock[player]) {
			StopAllBGM();						// BGM停止
			onRecord[player] = 0;				// リプレイ記録終了
			stage[player]--;
			ending[player] = 3;
			stat[player] = 14;
			statc[player * 10] = 0;
			return;
		}
		
		// ステージ開始時のnextcを記憶
		stage_nextc[player] = nextc[player];
		
		// BGM設定
		if((bgmlv != tomoyo_bgm[player]) && (!onRecord[1 - player])) {
			fadelv = 1;
			bgmlv = tomoyo_bgm[player];
		}
		
		// スピード設定
		if((enable_minspeed) && (sp[player] < min_speed[player]))
			sp[player] = min_speed[player];
		
		// DEVIL500ギミック
		if(tomoyo_waits[player] && enable_minspeed) {
			if(repversw <= 6) {
				wait1[player] = wait1_devil_tbl6[5];
				wait2[player] = wait2_devil_tbl6[5];
				wait3[player] = wait3_devil_tbl6[5];
				waitt[player] = waitt_devil_tbl6[5];
			} else if(repversw <= 7) {
				wait1[player] = wait1_devil_tbl7[5];
				wait2[player] = wait2_devil_tbl7[5];
				wait3[player] = wait3_devil_tbl7[5];
				waitt[player] = waitt_devil_tbl7[5];
			} else {
				wait1[player] = wait1_devil_tbl[5];
				wait2[player] = wait2_devil_tbl[5];
				wait3[player] = wait3_devil_tbl[5];
				waitt[player] = waitt_devil_tbl[5];
			}
		}
		
		// DUALギミック
		if(tomoyo_dual[player]) {
			tomoyo_dual_enable[player] = !maxPlay;
		} else {
			tomoyo_dual_enable[player] = 0;
		}
		
		if(tomoyo_dual_enable[player]) {
			b_maxPlay = maxPlay;	// プレイ人数をバックアップ
			maxPlay = 1;			// 一時的にDUAL台にする
			
			backno = 15;			// back_vs.png
			
			for(i = 0; i < 2; i++) {
				// フィールドの表示位置をバックアップ
				b_foffset[i] = foffset[i];
				b_boffset[i] = boffset[i];
				
				// フィールドの表示位置を変更
				foffset[i] = v_foffset[i];
				boffset[i] = v_boffset[i];
			}
			
			// 2P側を初期化
			gameMode[1] = 6;
			playerInitial(1);
			tomoyo_dual[1] = 1;
			tomoyo_dual_enable[1] = 1;
			stat[1] = 35;
		}
		
		// ギミック警告
		if(isfmirror[player]) {
			objectCreate(player, 8, 0, 0, 0, 0, 0, 0);
		} else if(rollroll_flag[player]) {
			objectCreate(player, 8, 0, 0, 0, 0, 1, 0);
		} else if(IsBig[player]) {
			objectCreate(player, 8, 0, 0, 0, 0, 2, 0);
		} else if(xray_flag[player]) {
			objectCreate(player, 8, 0, 0, 0, 0, 3, 0);
		} else if(color_flag[player]) {
			objectCreate(player, 8, 0, 0, 0, 0, 4, 0);
		} else if(hnext_flag[player]) {
			objectCreate(player, 8, 0, 0, 0, 0, 6, 0);
		} else if(tomoyo_waits[player]) {
			if(enable_minspeed) objectCreate(player, 8, 0, 0, 0, 0, 11, 0);
		} else if(blind_flag[player] || isthunder[player] || tomoyo_rise[player]) {
			objectCreate(player, 8, 0, 0, 0, 0, -1, 0);
		}
		
		// せり上がりタイプ設定
		uplinetype[player] = 2;
	}
	
	// FLASHモード
	if((gameMode[player] == 15) && (statc[player * 10] == 0)) {
		// リプレイ用初期設定
		if((playback) && (start_stage[player] == stage[player])) {
			loadTomoyoStage(player, stage[player], 1 + flash_edit[player]);
			flash_bonus_points[player] = 1000 * ((stage[player] / 4) + 1);
			flash_bonus_count[player] = 0;
		}
		
		// プラチナブロックの数を数える
		rest_pblock[player] = getPlatinumBlock(player);
		
		// 制限時間をセット
		if((start_stage[player] == stage[player]) && (timeattack[player])) ltime[player] = 64800;
		
		// BGM切り替え
		tmp = bgmlv;
		setstartBGM(player);
		if(bgmlv != tmp) fadelv = 1;
		
		scanItem(player);
	}
	
	// STAGEの表示(TOMOYO)
	if((gameMode[player] == 6) && (statc[player * 10] >= ready_start[player])) {
		printFont(boffset[player] + 1, 9, "STAGE", fontc[rots[player]]);
		getTomoyoStageNo(stage[player], 0, 1);
		printFont(boffset[player] + 7, 9, string[0], fontc[rots[player]]);
	}
	
	// STAGEの表示(FLASH)
	if((gameMode[player] == 15) && (statc[player * 10] >= ready_start[player])) {
		printFont(boffset[player] + 1, 9, "STAGE", fontc[rots[player]]);
		sprintf(string[0], "%2d", stage[player] + 1);
		printFont(boffset[player] + 7, 9, string[0], fontc[rots[player]]);
	}
	
	// ミッションモード用
	if((gameMode[player] == 8) && (statc[player * 10] == 0) && (c_mission == start_mission) && (!c_norm[0])) {
		// 初期設定
		missionSetStatus();
		
		// 背景を設定
		if(mission_bg[c_mission]) backno = mission_bg[c_mission] - 1;
		
		// ターゲットのステージ読み込み
		if(mission_type[c_mission] == 6) loadTargetStage();
		
		// ピンチかどうかチェック
		pinchCheck(player);
	}
	
	// VERSUSモードの制限時間を設定
	if((gameMode[player] == 4) && (vs_timelimit > 0) && (statc[player * 10] == 0)) {
		ltime[player] = vs_timelimit;
	}
	// VERSUSのせり上がりタイプ設定
	if((gameMode[player] == 4) && (statc[player * 10] == 0)) {
		uplinetype[player] = 3;
	}
	
	// 新IRS
	if(ace_irs) {
		if(statc[player * 10]) {
			doNewIRS(player, 0);
		} else {
			onRecord[player] = 1;
			doNewIRS(player, 0);
		}
	}
	
	// ブロックの出現位置を設定
	if(statc[player * 10] == 0) {
		setBlockSpawnPosition(player);
	}
	
	// スタート時のnextcを記録
	if((statc[player * 10] == 0) && (ready_count[player] == 1)) {
		start_nextc[player] = nextc[player];
	}
	
	// HYPER横先行移動
	if(fastlrmove == 3) {
		if(statc[player * 10]) {
			HyperLRMove(player);
		} else {
			onRecord[player] = 1;
			HyperLRMove(player);
		}
	}
	
	// 最初のフレームの横溜めを記録／再現
	if((ready_count[player] == 1) && (onRecord[player]) && (statc[player * 10] == 0)) {
		if(playback) {
			mp [player] = mps[player * 2    ];
			mpc[player] = mps[player * 2 + 1];
		} else {
			mps[player * 2    ] = mp [player];
			mps[player * 2 + 1] = mpc[player];
		}
	}
	
	if( (statc[player * 10] >= ready_start[player]) && (statc[player * 10] < ready_end[player]) ) {
		// READY
		ExBltRect(49, foffset[player] - 2, 91, 200,  0, 100, 50);
	} else if( (statc[player * 10] >= go_start[player]) && (statc[player * 10] < go_end[player]) ) {
		// GO
		ExBltRect(49, foffset[player] - 2, 92, 200, 50, 100, 50);
	}
	
	if(statc[player * 10] == ready_start[player]) {
		if(!IsPlayWave(15)) PlaySE(15);
	}
	if(statc[player * 10] == go_start[player]) {
		if(!IsPlayWave(16)) PlaySE(16);
	}
	
	// ゲームスタート
	if( statc[player * 10] >= go_end[player] ) {
		stat[player] = 4;					// ブロック落下開始へ
		statc[player * 10 + 1] = 1;			// 
		statc[player * 10] = 0;				// あとかたづけ
		
		// スタート時の横溜めを記録／再現
		if((ready_count[player] == 1) && (!onRecord[player])) {
			if(playback) {
				mp [player] = mps[player * 2    ];
				mpc[player] = mps[player * 2 + 1];
			} else {
				mps[player * 2    ] = mp [player];
				mps[player * 2 + 1] = mpc[player];
			}
		}
		
		// スタート時のルールを設定
		if(ready_count[player] == 1) {
			start_rots[player] = rots[player];
		}
		
		timeOn[player] = 1;					// タイマー開始
		onRecord[player] = 1;				// リプレイ記録開始
		
		// COLOR #LITE16
		if(color_flag[player]) iscolor[player] = 1;
		
		// BGM再生
		if(!onRecord[1 - player]) {
			if( ((bgm == 4) && !IsPlayMIDI()) || ((bgm >= 2) && (bgm != 4) && !IsPlayWave(60 + bgmlv)) )
				changeBGM();
		}
	} else if( ((nextskip == 0) && (gameMode[player] == 6)) || 
	           ((nextskip == 1) && ((gameMode[player] == 6) || (gameMode[player] == 15))) || 
	           (nextskip == 2) )
	{
		// リプレイ記録開始
		onRecord[player] = 1;
		
		// ツモ送り機能 #LITE13
		if( !pass_flg[player] && getPressState(player, 7) ) {
			hold_used[player]++;
			
			if((hold_sound == 1) || (hold_sound == 3)) PlaySE(9);	// hold.wav
			
			hold[player] = next[player];
			dhold[player] = 0;
			dhold2[player] = 0;
			
			// HOLDブロックの色を設定
			if(!rule_color[rots[player]])
				c_hblk[player] = ccol[next[player]];
			else
				c_hblk[player] = wcol[next[player]];
			
			// NEXTを進める
			nextc[player] = (nextc[player] + 1) % nextb_max[player];
			next[player] = getNextBlock(player, nextc[player]);
			
			// 回転状態や出現位置をリセット
			rt_nblk[player * 6] = 0;
			setBlockSpawnPosition(player);
			
			// NEXTブロックの色を設定
			setNextBlockColors(player, 0);
		}
		
		pass_flg[player] = getPressState(player, 7);
	}
	
	// 下入れ制限初期化
	down_flag[player] = 0;
	up_flag[player] = 0;
	
	// カウンタ増加
	statc[player * 10]++;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.04 - ブロック落下開始
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statBlock(int player) {
	int i;
	
	// アイテム発動
	if(goItemStat(player, stat[player])) return;
	
	// TGMLV上昇
	if( (!ending[player]) && (!isAceModeOrMission(player)) && (!isMarathonMode(player)) && 
	    (gameMode[player] != 9) && (gameMode[player] != 17) )
	{
		if((gameMode[player] == 0) || (gameMode[player] == 3) || (gameMode[player] == 16))
			i = 99;
		else if(gameMode[player] == 13)
			i = 99 * (tc[player] >= 200);
		else
			i = 99 - ((tc[player] > 900) && (timeattack[player]));
		
		if((tc[player] % 100 != i) || (i == 0)) {
			tc[player]++;
			if((tc[player] % 100 == i) && (i != 0)) PlaySE(28);
		}
		
		// TOMOYOモードでは998でストップ
		if((gameMode[player] == 6) && (tc[player] > 998)) tc[player] = 998;
		
		if( (bgm >= 2) && (fadelv == 0) ) checkFadeout(player);	// BGMフェードアウトチェック
	}

	// TOMOYOせり上がり
	if( ((gameMode[player] == 6) || ((gameMode[player] == 8) && (mission_type[c_mission] == 6))) && 
	    (tomoyo_rise[player] != 0) )
	{
		tomoyo_rise_t[player]++;
		
		if(tomoyo_rise_t[player] % tomoyo_rise[player] == 0) {
			upLines[player] = 1;
		}
	}

	// ACEモードのタイマー再開
	if(isAceMode(player) && !ending[player])
		timeOn[player] = 1;

	// アイテムを設定
	item[player] = item_nblk[0 + player * 6];

	// アイテム関連
	if(item_mode[player]) setItemStatus(player);

	// フィーバー中は棒だけ出現
	if(isfever[player]) {
		next[player] = 0;
		
		if(rule_color[rots[player]])
			c_nblk[0 + player * 6] = wcol[0];
		else
			c_nblk[0 + player * 6] = ccol[0];
	}

	// CPUの操作
	if( (cpu_flag[player]) && ((!replayauto) || (repversw <= 3)) ) {
		cpu_setCtrl(player);
	}

	// ナビゲーションシステムもどき
	if( (tc[player] < limit_navigation) && 
	    ( (enable_navigation == 2) || ((enable_navigation == 1) && (gameMode[player] == 0)) ) && 
	    (!IsBig[player]) && (!cpu_flag[player]) )
	{
		cpu_setBestSpot(player, next[player], 0, getNextBlock(player, nextc[player] + 1), 1);
		navigation_time[player] = 0;
	}

	padRepeat(player);

	blk[player] = next[player];

	nextc[player] = (nextc[player] + 1) % nextb_max[player];
	next[player] = getNextBlock(player, nextc[player]);
	
	// blockseを鳴らす
	if( (hnext[player] > 0) && (!ishidenext[player]) && (!heboGB[player]) ) {
		if(isfakenext[player]) PlaySE(21 + Rand(7));
		else PlaySE(21 + next[player]);
	}
	
	// ブロックの色を設定
	c_cblk[player] = c_nblk[0 + player * 6];
	c_cblk_r[player] = c_nblk[0 + player * 6];
	
	o_cblk[player] = o_nblk[0 + player * 6];
	
	// 向きを設定
	rt[player] = rt_nblk[player * 6];
	
	// 横位置を設定
	bx[player] = n_bx[player];
	
	// NEXTブロックの色を設定
	setNextBlockColors(player, 0);
	
	// 出現位置設定
	setBlockSpawnPosition(player);
	
	bs[player] = 0;
	bk[player] = 0;
	bk_D[player] = 0;
	
	dhold[player] = 0;
	dhold2[player] = 0;
	kickc[player] = 0;
	kickc2[player] = 0;
	kickc3[player] = 0;
	
	// スコア変数初期化
	sdrop[player] = 0;
	qdrop[player] = 0;
	
	// 旧HIDDEN処理
	hiddenProc(player);
	
	// 最後の操作を初期化 #LITE23
	last_command[player] = 0;
	
	// T-SPINフラグ初期化
	IsTspin[player] = 0;
	
	// ハードドロップ使用フラグ初期化
	harddrop[player] = 0;
	softdrop[player] = 0;
	
	// T-SPIN無効フラグ初期化
	tspin_kick[player] = 0;
	
	// フィールド位置初期化
	ofs_x[player] = 0;
	ofs_y[player] = 0;
	
	// MASTER-HARDで1曲目のBGMがフェードアウトした場合はREGRETしても速度を落とさない
	if((gradetype[player] == 1) && (tc[player] >= tc_20g[player]) && (tr2[player] < 51)) {
		regretcancel[player] = 1;
	}
	
	// ↓を離している場合、下入れ制限解除
	if( !getPressState(player, 1) ) down_flag[player] = 0;
	if( !getPressState(player, 0) ) up_flag[player] = 0;
	
	if((spawn_y_type) && (!heboGB[player]) && (rule_are[rots[player]] != 0)) {
		if( ((sp[player] < 60) && (!speedtype[player])) || ((sp[player] > 1) && (speedtype[player])) )
			ndelay[player] = 0;
	}
	
	stat[player] = 5;
	statc[player * 10 + 2] = 0;
	statc[player * 10 + 3] = 0;
	
	// 横方向の先行移動
	statc[player * 10 + 4] = (fastlrmove != 1);
	
	// IHS
	doHold(player, 1);
	
	// IRS
	if(!ace_irs) doClassicIRS(player);
	
	// ゲームオーバーチェック
	if(checkGameOver(player)) return;
	
	// ブロック移動処理
	if(repversw >= 5) statMove(player);
}

// (I.R.S.) Initial Rotation System  (c)1998 AR●KA(^^;
void doClassicIRS(int player) {
	int bak;
	
	if(isRotateLock[player] || heboGB[player] || !enable_irs) return;
	
	if( getPressState(player, 4) || getPressState(player, 5) || getPressState(player, 6) ) {
		PlaySE(0);
		
		// 回転する方向を決める
		if( !getPressState(player, 5) ) {
			// AまたはC
			if(isWRule(player) && w_reverse)
				bak = 1;	// WORLD 右回転
			else
				bak = 3;	// CLASSIC 左回転
		} else {
			// B
			if(isWRule(player) && w_reverse)
				bak = 3;	// WORLD 左回転
			else
				bak = 1;	// CLASSIC 右回転
		}
		
		// 180度回転
		if( ((rot180 == 1) || ((rot180 == 2) && (rule_180rot[rots[player]] != 0))) && getPressState(player, 6) ) {
			bak = 2;
		}
		
		// 回転できるかチェック
		if( judgeBlock(player, bx[player], by[player], blk[player], bak) == 0 ) {
			// 回転可能
			if(rotate_sound) PlaySE(4);
			rt[player] = bak;
		} else if(!blk[player] && !r_irs) {
			// 赤色ブロックで回転しなかったときは1マス上にずらせるか判定
			if( judgeBlock(player, bx[player], by[player] - 1, blk[player], bak) == 0 ) {
				if(rotate_sound) PlaySE(4);
				rt[player] = bak;
				by[player]--;
			}
		} else {
			// 回らなかった
			if( !IsPlayWave(35) ) PlaySE(35);
		}
	}
}

// 新IRS
// typeを1にすると押しっぱなしでも回転
void doNewIRS(int player, int type) {
	int bak, bak2, result;
	
	if(isRotateLock[player] || heboGB[player] || !enable_irs) return;
	
	if( ((!type) && (getPushState(player, 4) || getPushState(player, 5) || getPushState(player, 6))) || 
	    ((type) && (getPressState(player, 4) || getPressState(player, 5) || getPressState(player, 6))) )
	{
		// 回転する方向を決める
		if( (!type && !getPushState(player, 5)) || (type && !getPressState(player, 5)) ) {
			// AまたはC
			if(isWRule(player) && w_reverse)
				bak = 1;	// WORLD 右回転
			else
				bak = -1;	// CLASSIC 左回転
		} else {
			// B
			if(isWRule(player) && w_reverse)
				bak = -1;	// WORLD 左回転
			else
				bak = 1;	// CLASSIC 右回転
		}
		
		// 180度回転
		if( ((rot180 == 1) || ((rot180 == 2) && (rule_180rot[rots[player]] != 0))) && 
		    ((!type && getPushState(player, 6)) || (type && getPressState(player, 6))) )
		{
			bak = 2;
		}
		
		bak2 = rt_nblk[player * 6] + bak;
		if(bak2 < 0) bak2 = bak2 + 4;
		if(bak2 > 3) bak2 = bak2 - 4;
		
		if(judgeBlock(player, n_bx[player], -2, next[player], bak2) == 0) {
			// 壁に当たらない場合
			result = 1;
		} else if(judgeBlock(player, n_bx[player] + 1, -2, next[player], bak2) == 0) {
			// 右1マス壁蹴り
			n_bx[player] = n_bx[player] + 1;
			result = 1;
		} else if(judgeBlock(player, n_bx[player] + 2, -2, next[player], bak2) == 0) {
			// 右2マス壁蹴り
			n_bx[player] = n_bx[player] + 2;
			result = 1;
		} else if(judgeBlock(player, n_bx[player] - 1, -2, next[player], bak2) == 0) {
			// 左1マス壁蹴り
			n_bx[player] = n_bx[player] - 1;
			result = 1;
		} else if(judgeBlock(player, n_bx[player] - 2, -2, next[player], bak2) == 0) {
			// 左2マス壁蹴り
			n_bx[player] = n_bx[player] - 2;
			result = 1;
		} else {
			// 失敗
			result = 0;
		}
		
		// 回転させる
		if(result) {
			PlaySE(0);
			rt_nblk[player * 6] = bak2;
		} else {
			PlaySE(35);
		}
	}
}

// HYPER横先行移動
void HyperLRMove(int player) {
	int move, tmp;
	
	// キー入力を取得して移動方向を設定
	move = getPressState(player, 3) - getPressState(player, 2);
	
	// 2マス単位のBIGでは移動量を2倍にする
	if(IsBig[player] && BigMove[player]) move = move * 2;
	
	// 横溜め設定
	if(rule_max_waitt[rots[player]] < waitt[player]) tmp = rule_max_waitt[rots[player]];
	else tmp = waitt[player];
	
	if( (move != 0) && ((mpc[player] == 1) || (mpc[player] >= tmp)) )
		if(judgeBlock(player, n_bx[player] + move, -2, next[player], rt_nblk[player * 6]) == 0) {
			// ブロックを移動させる
			n_bx[player] = n_bx[player] + move;
			if(move_sound) PlaySE(5);
		} else {
			// 移動できなかった
			if(!IsPlayWave(34)) PlaySE(34);
		}
}

// ゲームオーバーになるかチェック
int checkGameOver(int player) {
	if(judgeBlock(player, bx[player], by[player], blk[player], rt[player]) != 0) {
		// ブロックがめり込んでいたらゲームオーバー
		setBlock(player, bx[player], by[player], blk[player], rt[player]);
		setGameOver(player);
		return 1;
	} else if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0) {
		// 1マス下にブロックがある場合は接地音を鳴らす
		PlaySE(1);
	}
	
	return 0;
}

// ゲームオーバーにさせる
void setGameOver(int player) {
	int i;
	
	// 高速ロールでは行わない処理
	if(!fastroll[player]) {
		if(!onRecord[1 - player]) StopAllBGM();	// 音楽停止
		onRecord[player] = 0;		// リプレイ記録停止
		ending_timeOn[player] = 0;	// エンディングタイマー停止
	}
	
	isxray[player] = 0;		// X-RAYを止める
	iscolor[player] = 0;	// COLORを止める
	isblind[player] = 0;	// BLINDを止める
	isdark[player] = 0;		// DARKを止める
	
	ofs_x[player] = 0;
	ofs_y[player] = 0;
	
	timeOn[player] = 0;			// タイマー停止
	stat[player] = 7;			// ゲームオーバー処理へ
	
	// 警告音を止める
	pinch[player] = 0;
	StopWave(38);
	
	// カウンタ初期化
	for(i=0; i<10; i++) statc[player * 10 + i] = 0;
	
	// 消えロール中に死んだら段位+1
	if((gmflag_r[player]) && (gradetype[player] == 0)) {
		if(grade[player] < 31) {
			grade[player]++;
			gflash[player] = 120;
			gup_down[player] = 1;
			PlaySE(31);
		}
	}
	
	// HARDのときの死亡段位上昇
	if((gradetype[player] == 1) && (tc[player] - ((tc[player] / 100) * 100) > 50)) {
		grade[player] = grade[player] + gup3rank[player];
		if(grade[player] > 31) grade[player] = 31;
	}
	
	// DUALギミック解除
	endTomoyoDualGimmick(0);
	
	// ROT. RELAY用
	if((gameMode[player] == 17) && (timeattack[player] >= 2)) {
		rots[player] = start_rots[player];
		setNextBlockColors(player, 1);
	}
}

// 裏段位判定
int checkSecretGrade(int player) {
	int i, j, uhole, umode, count;
	
	uhole = 0;		// 穴の位置を初期化（最初は左端）
	umode = 0;		// 1だと右から左へ穴が移動
	count = -1;		// 現在の裏段位を初期化
	
	// 9～S9までの判定
	for(i = 21; i > 3; i--) {
		for(j = 0; j < 10; j++) {
			// 埋まっているべき場所が埋まってないなら終了
			if((fld[j + i * 10 + player * 220] == 0) && (j != uhole)) return count;
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
		count++;
	}
	
	// GM判定
	// 左上(X:0 Y:1)が埋まっていたらGM
	if(fld[0 + 1 * 10 + player * 220] != 0) {
		count++;
	}
	
	return count;
}

// ブロック出現位置を設定
void setBlockSpawnPosition(int player) {
	int move;
	
	if((spawn_y_type) && (!heboGB[player])) {
		// 枠外
		if(IsBig[player]) {
			// BIG
			n_bx[player] = 2;
			
			if(isWRule(player)) {
				by[player] = (blk[player] == 0) * -1;
			} else if(isDRule(player)) {
				by[player] = -1 - (blk[player] != 0) - (2 * (blk[player] == 0));
			} else {
				by[player] = -1 - (blk[player] != 0);
			}
		} else {
			// 通常
			n_bx[player] = 3;
			
			if(isWRule(player)) {
				by[player] = 0;
			} else if(isDRule(player)) {
				by[player] = -1;
			} else {
				by[player] = (blk[player] != 0) * -1;
			}
		}
	} else {
		// 枠内
		if(IsBig[player]) {
			// BIG
			n_bx[player] = 2;
			
			if(isWRule(player)) {
				by[player] = (blk[player] != 0) * 2;
			} else if(isDRule(player)) {
				by[player] = (blk[player] == 0) * -2;
			} else {
				by[player] = 0;
			}
		} else {
			// 通常
			n_bx[player] = 3;
			
			if(isWRule(player)) {
				by[player] = 1 + (blk[player] != 0);
			} else if(isDRule(player)) {
				by[player] = 1 * (blk[player] != 0);
			} else {
				by[player] = 1;
			}
		}
	}
	
	// SUPER横先行移動
	if(fastlrmove == 2) {
		// キー入力を取得して移動方向を設定
		move = getPressState(player, 3) - getPressState(player, 2);
		
		// 2マス単位のBIGでは移動量を2倍にする
		if(IsBig[player] && BigMove[player]) move = move * 2;
		
		// 移動
		if(judgeBlock(player, n_bx[player] + move, by[player], blk[player], rt[player]) == 0) {
			n_bx[player] = n_bx[player] + move;
		}
	}
}

// HOLDする処理 #LITE07
void doHold(int player, int ihs) {
	int tmp, first;
	
	if(dhold[player] || heboGB[player] || disable_hold || isholdlock[player]) return;
	
	if(getPressState(player, 7)) {
		// hold.wav
		if( ((hold_sound == 1) && (ihs)) || ((hold_sound == 2) && (!ihs)) || (hold_sound == 3) )
			PlaySE(9);
		
		first = (hold[player] == -1);
		
		if(first) {
			// 初回
			hold[player] = blk[player];
			blk[player] = next[player];
			nextc[player] = (nextc[player] + 1) % nextb_max[player];
			next[player] = getNextBlock(player, nextc[player]);
			
			// ブロックの色を設定
			c_hblk[player] = c_cblk_r[player];
			
			c_cblk[player] = c_nblk[0 + player * 6];
			c_cblk_r[player] = c_nblk[0 + player * 6];
			
			o_hblk[player] = o_cblk[player];
			o_cblk[player] = o_nblk[0 + player * 6];
			
			// アイテムを設定
			
			// すべてOFF
			if(enable_item_hold == 0) {
				item_hblk[player] = 0;
				item[player] = 0;
			}
			// すべてON
			if(enable_item_hold == 1) {
				item_hblk[player] = item[player];
				item[player] = item_nblk[0 + player * 6];
			}
			// IHS時OFF、それ以外ON
			if(enable_item_hold == 2) {
				if(ihs) {
					item_hblk[player] = 0;
					item[player] = 0;
				} else {
					item_hblk[player] = item[player];
					item[player] = item_nblk[0 + player * 6];
				}
			}
			// IHS時ON、それ以外OFF
			if(enable_item_hold == 3) {
				if(ihs) {
					item_hblk[player] = item[player];
					item[player] = item_nblk[0 + player * 6];
				} else {
					item_hblk[player] = 0;
					item[player] = 0;
				}
			}
			
			item_coming[player] = 0;
			
			if(ace_irs >= 2) tmp = rt[player];
			
			// NEXTブロックの色を設定
			setNextBlockColors(player, 0);
			
			if(ace_irs >= 2) rt[player] = tmp;
			scanItem(player);
		} else {
			// 2回目以降
			tmp = blk[player];
			blk[player] = hold[player];
			hold[player] = tmp;
			
			// ブロックの色を設定
			tmp = c_cblk_r[player];
			
			c_cblk[player] = c_hblk[player];
			c_cblk_r[player] = c_hblk[player];
			c_hblk[player] = tmp;
			
			tmp = o_hblk[player];
			o_hblk[player] = o_cblk[player];
			o_cblk[player] = tmp;
			
			// アイテムを設定
			
			// すべてOFF
			if(enable_item_hold == 0) {
				item[player] = 0;
				item_hblk[player] = 0;
			}
			// すべてON
			if(enable_item_hold == 1) {
				tmp = item_hblk[player];
				item_hblk[player] = item[player];
				item[player] = tmp;
			}
			// IHS時OFF、それ以外ON
			if(enable_item_hold == 2) {
				if(ihs) {
					item[player] = 0;
					item_hblk[player] = 0;
				} else {
					tmp = item_hblk[player];
					item_hblk[player] = item[player];
					item[player] = tmp;
				}
			}
			// IHS時ON、それ以外OFF
			if(enable_item_hold == 3) {
				if(ihs) {
					tmp = item_hblk[player];
					item_hblk[player] = item[player];
					item[player] = tmp;
				} else {
					item[player] = 0;
					item_hblk[player] = 0;
				}
			}
			
			scanItem(player);
		}
		
		dhold[player] = 1;
		dhold2[player] = 1;
		hold_used[player]++;
		
		kickc[player] = 0;
		kickc2[player] = 0;
		kickc3[player] = 0;
		
		// 出現位置設定
		setBlockSpawnPosition(player);
		bx[player] = n_bx[player];
		
		// ブロックの向きをリセット
		if(ace_irs < 2) rt[player] = 0;
		
		bs[player] = 0;
		bk[player] = 0;
		bk_D[player] = 0;
		
		// CPUの操作
		if( (cpu_flag[player]) && ((!replayauto) || (repversw <= 3)) ) {
			cpu_setBestSpot(player, blk[player], 0, next[player], 0);
			cpu_setCtrl(player);
		}
		
		// ナビゲーションシステムもどき
		if( (tc[player] < limit_navigation) && 
		    ( (enable_navigation == 2) || ((enable_navigation == 1) && (gameMode[player] == 0)) ) && 
		    (!IsBig[player]) && (!cpu_flag[player]) )
		{
			cpu_setBestSpot(player, blk[player], 0, next[player], 1);
			navigation_time[player] = 0;
		}
		
		// IHSでない場合
		if(!ihs) {
			// IRS
			if(ace_irs != 1) doClassicIRS(player);
			
			// blockseを鳴らす
			if( (hnext[player] > 0) && (!ishidenext[player]) && (!heboGB[player]) ) {
				if(isfakenext[player]) PlaySE(21 + Rand(7));
				else PlaySE(21 + next[player]);
			}
			
			// 横方向の先行移動を無効にする
			statc[player * 10 + 4] = (fastlrmove != 1);
		}
		
		// ブロックがめり込んでいたらゲームオーバー
		checkGameOver(player);
	}
}

// T-SPINがあるモードかどうか判定
int isTSpinEnableMode(int player) {
	int result;
	result = isNormalOrBeginnerMode(player);
	result = result || isMarathonMode(player);
	result = result || (gameMode[player] == 17);
	result = result || ((gameMode[player] == 8) && ((mission_type[c_mission] == 16) || (mission_type[c_mission] == 37)));
	return result;
}

// 3-CORNERタイプのT-SPIN判定
int isTSpin3Corner(int player) {
	int i, count, tx[4], ty[4];
	int tmp_x, tmp_y;
	
	if((tspin_type != 3) && (tspin_type != 4)) return 0;
	if((tspin_type == 4) && (tspin_kick[player] > 0)) return 0;
	
	// 判定用相対座標を設定
	if(IsBig[player]) {
		tx[0] = 1;
		ty[0] = 1;
		tx[1] = 4;
		ty[1] = 1;
		tx[2] = 1;
		ty[2] = 4;
		tx[3] = 4;
		ty[3] = 4;
	} else {
		tx[0] = 0;
		ty[0] = 0;
		tx[1] = 2;
		ty[1] = 0;
		tx[2] = 0;
		ty[2] = 2;
		tx[3] = 2;
		ty[3] = 2;
	}
	
	// 判定処理
	count = 0;
	
	for(i = 0; i < 4; i++) {
		tmp_x = bx[player] + tx[i];
		tmp_y = by[player] + ty[i];
		
		// ARSでTが上向きの場合
		// ◇　◇
		// 　■
		// ◆■◆
		// こんな判定だったのを修正
		if((isWRule(player) == 0) && (rt[player] == 2))
			tmp_y = tmp_y + 1 + (IsBig[player]);
		
		if(tmp_y >= 0) {
			if( (tmp_x < 0) || (tmp_x > 9) || (tmp_y > 21) || (fld[tmp_x + tmp_y * 10 + player * 220]) ) {
				count++;
				
				if(count >= 3) return 1;
			}
		}
	}
	
	return 0;
}

// IMMOBILEタイプのT-SPIN判定
int isTSpinImmobile(int player) {
	if(tspin_type != 2) return 0;
	
	if( (judgeBlock(player, bx[player] - 1, by[player], blk[player], rt[player]) != 0) &&
		(judgeBlock(player, bx[player] + 1, by[player], blk[player], rt[player]) != 0) &&
		(judgeBlock(player, bx[player], by[player] - 1, blk[player], rt[player]) != 0) )
	{
		return 1;
	}
	
	return 0;
}

// ブロック消去判定
// 戻り値は消去されるライン数 #LITE07
int blockEraseJudge(int player) {
	int		i, j, sr;
	int		result;
	int		by2, k;
	int		data[2];
	
	if(gameMode[player] == 4) {
		// 対戦ではブロックが揃った状態のまま残るバグがあるので、全部調べる
		result = blockAllEraseJudge(player);
	} else {
		// 対戦以外では置いた所だけ調べる
		result = 0;
		
		for(i = 0; i < 4; i++) {
			// 置いたブロックのY座標を取得
			getBlockData(player, 0, 0, blk[player], rt[player], i, &data);
			by2 = by[player] + (data[1] * (IsBig[player] + 1));
			
			// 消去判定（BIGでは2ライン調べる）
			for(k = 0; k < 1 + IsBig[player]; k++) {
				if((by2 + k >= 0) && (!erase[(by2 + k) + player * 22])) {
					sr = 1;
					
					for(j = 0 ; j < 10; j++) {
						if(!fld[j + (by2 + k) * 10 + player * 220]) {
							sr = 0;
							break;
						}
					}
					
					if(sr) {
						erase[(by2 + k) + player * 22] = 1;
						result++;
					}
				}
			}
		}
	}
	
	// 対戦モードのせり上がり処理
	if((result >= 2) && (uplinetype[player] == 3) && (upLines[1 - player] <= 21) && (r_enable[player]) && (!ismiss[player])) {
		// 一時的に今置いたブロックを消す（こうしないと揃った状態でせり上がる）
		removeBlock(player, bx[player], by[player], blk[player], rt[player]);
		
		// 消したラインの形状をコピー
		for(k = 0; k <= isdouble[1 - player]; k++) {
			for(i = 0; i < 22; i++) {
				if(erase[(21 - i) + player * 22]) {
					for(j = 0; j < 10; j++) {
						fldu[j + upLines[1 - player] * 10 + (1 - player) * 220] = fld[j + (21 - i) * 10 + player * 220];
					}
					
					upLines[1 - player]++;
					if(upLines[1 - player] > 21) break;
				}
			}
		}
		
		// ブロックをもう一度設置する
		setBlock(player, bx[player], by[player], blk[player], rt[player]);
	}
	
	return result;
}

// FREE FALL用ブロック消去判定（全ての列を調べる）
int blockAllEraseJudge(int player) {
	int		i, j, sr;
	int		result;
	
	result = 0;
	
	for(i = 0; i < 22; i++) {
		sr = 1;
		
		for(j = 0; j < 10; j++)
			if(!fld[j + i * 10 + player * 220]) {
				sr = 0;
				break;
			}
		
		erase[i + player * 22] = sr;
		result = result + sr;
	}
	
	return result;
}

// ブロック上昇する?
void UpLineBlockJudge(int player) {
	// せり上がりラインが残っているときはせり上げる
	if(upLines[player] > 0) {
		PlaySE(20);
		UpLineBlock(player);
	}
}

// フィールドを上にずらす
void UpLinePush(int player) {
	int		i, j;
	
	for(i = 1 + (!spawn_y_type); i < 22; i++) {
		for(j = 0; j < 10; j++) {
			fld[j + (i - 1) * 10 + player * 220] = fld[j + i * 10 + player * 220];
			fldt[j + (i - 1) * 10 + player * 220] = fldt[j + i * 10 + player * 220];
			fldi[j + (i - 1) * 10 + player * 220] = fldi[j + i * 10 + player * 220];
			fldo[j + (i - 1) * 10 + player * 220] = fldo[j + i * 10 + player * 220];
			flds[j + (i - 1) * 10 + player * 220] = flds[j + i * 10 + player * 220];
		}
		
		erase[(i - 1) + player * 22] = erase[i + player * 22];
	}
}

// ブロック上昇
void UpLineBlock(int player) {
	int		i, j, newhole;
	
	// フィールドを上にずらす
	UpLinePush(player);
	
	if(uplinetype[player] == 0) {
		// SHIRASE式
		// ラインをコピーする
		for(j = 0; j < 10; j++) {
			fld[j + 21 * 10 + player * 220] = (fld[j + 20 * 10 + player * 220] != 0);
			fldt[j + 21 * 10 + player * 220] = (fld[j + 21 * 10 + player * 220] != 0) * -1;
		}
	} else if(uplinetype[player] == 1) {
		// TGM+式
		
		// せり上がりフィールドの読み込み
		fld[0 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2] / 10000 % 10;
		fld[1 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2] / 1000 % 10;
		fld[2 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2] / 100 % 10;
		fld[3 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2] / 10 % 10;
		fld[4 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2] % 10;
		fld[5 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2 + 1] / 10000 % 10;
		fld[6 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2 + 1] / 1000 % 10;
		fld[7 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2 + 1] / 100 % 10;
		fld[8 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2 + 1] / 10 % 10;
		fld[9 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2 + 1] % 10;
		
		// ブロックを見えるようにする
		for(i = 0; i < 10; i++) {
			fldt[i + 10 * 21 + player * 220] = (fld[i + 10 * 21 + player * 220] != 0) * -1;
		}
		
		// 次のパターンへ
		if(upLineNo[player] + 1 < upLineNoMax)
			upLineNo[player]++;
		else
			upLineNo[player] = 0;
	} else if(uplinetype[player] == 2) {
		// TOMOYOせり上がり
		// せり上がりフィールドの読み込み
		for(i = 0; i < 10; i++) {
			fld[i + 10 * 21 + player * 220] = tomoyo_rise_fld[i + (upLineNo[player] * 10) + player * 200];
			fldt[i + 10 * 21 + player * 220] = (fld[i + 10 * 21 + player * 220] != 0) * -1;
		}
		
		upLineNo[player]++;
		
		// せり上がり終了判定
		if(upLineNo[player] > 20) {
			tomoyo_rise[player] = 0;
		} else {
			j = 0;
			
			for(i = 0; i < 10; i++) {
				if(tomoyo_rise_fld[i + (upLineNo[player] * 10) + player * 200] != 0) break;
				j++;
			}
			
			if(j == 10) tomoyo_rise[player] = 0;
		}
	} else if(uplinetype[player] == 3) {
		// 対戦用（新式）
		// せり上がりフィールドの一番上のラインをコピー
		for(j = 0; j < 10; j++) {
			fld[j + 21 * 10 + player * 220] = fldu[j + 0 * 10 + player * 220];
			fldt[j + 21 * 10 + player * 220] = (fld[j + 21 * 10 + player * 220] != 0) * -1;
		}
		
		// せり上がりフィールドをずらす
		for(i = 1; i < 22; i++) {
			for(j = 0; j < 10; j++) {
				fldu[j + ( i - 1 ) * 10 + player * 220] = fldu[j + i * 10 + player * 220];
			}
		}
	} else if(uplinetype[player] == 4) {
		// ミッションせり上がり
		for(j = 0; j < 10; j++) {
			fld[j + 21 * 10 + player * 220] = (j != ghole[player]);
			fldt[j + 21 * 10 + player * 220] = (fld[j + 21 * 10 + player * 220] != 0) * -1;
		}
		
		// 8割の確率で穴の位置を変える
		if(GiziRand(player, 10) > 2) {
			do {
				newhole = GiziRand(player, 10);
			} while(newhole == ghole[player]);
			ghole[player] = newhole;
		}
	} else if(uplinetype[player] == 5) {
		// ミッション穴固定せり上がり
		for(j = 0; j < 10; j++) {
			fld[j + 21 * 10 + player * 220] = (j != ghole[player]);
			fldt[j + 21 * 10 + player * 220] = (fld[j + 21 * 10 + player * 220] != 0) * -1;
		}
	}
	
	// 最下段のアイテムを消す
	for(j = 0; j < 10; j++) {
		fldi[j + 21 * 10 + player * 220] = 0;
		fldo[j + 21 * 10 + player * 220] = 0;
	}
	
	erase[21 + player * 22] = 0;
	
	upLines[player]--;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.06 - 時間稼ぎ & レベルアップ判定
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statErase(int player) {
	int i, j, allowskip;
	
	if(repversw <= 6) {
		if(statc[player * 10] == wait1[player]) statc[player * 10 + 1] = 0;
		else statc[player * 10 + 1] = 1;
	}
	
	// HOLD使用可能に
	dhold[player] = 0;
	
	// CPUの操作
	if( (cpu_flag[player]) && ((!replayauto) || (repversw <= 3)) ) {
		if(!statc[player * 10 + 1]) cpu_setBestSpot(player, next[player], 0, getNextBlock(player, nextc[player] + 1), 0);
		
		cpu_setCtrl(player);
	}
	
	padRepeat(player);
	
	// 旧HIDDEN処理
	hiddenProc(player);
	
	// HARDのときの段位上昇
	if(gradetype[player] == 1) GradeUp3(player);
	
	// 新IRS
	if(ace_irs) doNewIRS(player, 0);
	
	// HYPER横先行移動
	if(fastlrmove == 3) HyperLRMove(player);
	
	// ↓を離している場合、下入れ制限解除
	if( !getPressState(player, 1) ) down_flag[player] = 0;
	if( !getPressState(player, 0) ) up_flag[player] = 0;
	
	if(!statc[player * 10 + 1]) {
		// 耐久ミッションクリア
		if((gameMode[0] == 8) && (timeOn[player]) && (mission_type[c_mission] == 23) && (ltime[0] <= 0))
			missionNormUp(0);
		
		// OOBAKAミッション用
		if((gameMode[0] == 8) && (timeOn[player]) && (mission_type[c_mission] == 29))
			missionNormUp(0);
		
		// ミッションクリア時のライン消去／せり上がり発生
		if((gameMode[0] == 8) && (c_norm[0] >= m_norm[0]) && (mission_clear_flag == 1) && (!ending[0])) {
			mission_clear_flag = 2;
			j = mission_erase[c_mission];
			
			// エンディングになる場合はラインを消去させない
			if(
			   (mission_end[c_mission] == 1) || 
			   ((mission_end[c_mission] >= 4) && (mission_end[c_mission] <= 9)) || 
			   (((mission_end[c_mission] == 2) || (mission_end[c_mission] == 3)) && (!mission_extra))
			  )
			{
				j = 0;
			}
			
			if(j > 0) {
				if(mission_end[c_mission] == 3) {
					// EXTRA+
					stat[0] = 26;
					statc[0] = -wait1[0];
					statc[1] = 6;
					statc[2] = j;
					statc[3] = 0;
				} else {
					// 普通に消す
					for(i = checkFieldTop(0); i < 22; i++) {
						erase[i] = 1;
						j--;
						if(j <= 0) break;
					}
					
					stat[0] = 21;
					statc[0] = 0;
					statc[1] = 6;
					statc[2] = 0;
				}
				return;
			} else if(j < -20) {
				// 穴揃いせり上がり発生
				ghole[0] = GiziRand(0, 10);
				uplinetype[0] = 5;
				upLines[0] = abs(j + 20);
				statc[0] = 6;
				statc[1] = 1;
				statRiseLine(0);
				return;
			} else if(j < 0) {
				// 穴バラバラせり上がり発生
				ghole[0] = GiziRand(0, 10);
				uplinetype[0] = 4;
				upLines[0] = abs(j);
				statc[0] = 6;
				statc[1] = 1;
				statRiseLine(0);
				return;
			}
		}
	}
	
	if( ((gameMode[player] == 6) || (gameMode[player] == 15)) && (!ending[player]) ) {
		// TOMOYOモードまたはFLASHモードでプラチナブロックが0個ならステージクリア
		if(rest_pblock[player] <= 0) {
			// 警告音を止める
			pinch[player] = 0;
			StopWave(38);
			StopWave(39);
			
			thunder_timer = 0;
			
			PlaySE(37);			// stageclear.wav
			clearnum[player]++;		// クリア数+1
			timeOn[player] = 0;		// タイマー停止
			sclear[player] = 1;
			
			if(tomoyo_clear_erase) {
				stat[player] = 26;
				statc[player * 10] = 0;
				statc[player * 10 + 1] = 18;
				statc[player * 10 + 2] = 21;
				statc[player * 10 + 3] = 0;
			} else {
				stat[player] = 18;
				statc[player * 10] = 0;
			}
			return;
		}
		// リミットタイムが0になっていたらゲームオーバー
		else if((ltime[player] <= 0) && (tomoyo_ltime_over[player])) {
			PlaySE(39);
			ltime[player] = 0;
			setGameOver(player);
			return;
		}
		// ステージタイムが0になっていたらタイムオーバー
		else if((!tomoyo_no_stage_time[player]) && (stime[player] == 0) && (gameMode[player] == 6)) {
			timeOn[player] = 0;		// タイマー停止
			sclear[player] = 0;
			stat[player] = 18;
			statc[player * 10] = 0;
			return;
		}
	}
	
	// TOMOYOせり上がり
	if( ((gameMode[player] == 6) || ((gameMode[player] == 8) && (mission_type[c_mission] == 6))) && 
	    (!statc[player * 10 + 1]) && (upLines[player]) )
		UpLineBlockJudge(player);
	
	// THUNDER発動
	if((isthunder[player]) && (!statc[player * 10 + 1])) {
		PlaySE(47);	// thunder.wav
		thunder_timer = 30;
	}
	
	// AREスキップが可能か決める（SKIP LOCKFLASHがSUPERかつAREに入って最初の1フレームの場合はスキップ不可）
	if((skip_blocklockflash == 3) && (repversw >= 7)) {
		allowskip = statc[player * 10 + 1];
	} else if(skip_blocklockflash != 2) {
		allowskip = 1;
	} else {
		allowskip = statc[player * 10 + 1];
	}
	
	statc[player * 10]--;
	statc[player * 10 + 1] = 1;
	
	// AREスキップ
	if((rule_are[rots[player]] == 2) && (harddrop[player]) && (allowskip)) {
		if( getPushState(player, 0) || getPushState(player, 1) || getPushState(player, 2) || getPushState(player, 3) || 
		    getPushState(player, 4) || getPushState(player, 5) || getPushState(player, 6) )
		{
			statc[player * 10] = -1;
		}
	}
	if((rule_are[rots[player]] == 2) && (are_skipflag[player]) && (allowskip)) {
		if( getPushState(player, 0) || getPushState(player, 1) || getPushState(player, 2) || getPushState(player, 3) || 
		    getPushState(player, 4) || getPushState(player, 5) || getPushState(player, 6) )
		{
			statc[player * 10] = -1;
			are_skipflag[player] = 0;
		}
	}
	
	if((statc[player * 10] < 0) || (!rule_are[rots[player]])) {
		// ステータスカウンタ初期化
		for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		
		// ターゲットミッションで1ステージクリアしたときの処理
		if( (gameMode[0] == 8) && (player == 0) && 
		    (mission_type[c_mission] == 6) && (getPlatinumBlock(0) == 0) && (!ending[0]) )
		{
			StopWave(38);			// タイム警告音を止める
			stat[player] = 3;		// Ready
			
			if(c_norm[0] < m_norm[0]) {
				// 次のステージ読み込み
				loadTargetStage();
				
				// ピンチかどうかチェック
				pinchCheck(player);
				
				return;
			}
		}
		
		// ミッションクリア
		if( (gameMode[0] == 8) && (player == 0) && (c_norm[0] >= m_norm[0]) && (!ending[0]) ) {
			if( (mission_end[c_mission] == 0) || (mission_end[c_mission] == 10) || 
			    ((mission_extra) && ((mission_end[c_mission] == 2) || (mission_end[c_mission] == 3))) )
			{
				// 使用したEXステージ権利を消す
				if((mission_end[c_mission] == 2) || (mission_end[c_mission] == 3)) mission_extra = 0;
				
				c_mission++;			// 次のミッションへ
				if(c_mission > 29) c_mission = 0;
				viewMissionText();		// 文字表示を更新
				
				// 背景切り替え
				bgfadesw = 1;
				
				// ノルマ初期化
				c_norm[0] = 0;
				
				// BGM切り替え
				if((bgmlv != mission_bgm[c_mission]) && (fadelv == 0)) fadelv = 1;
				
				// 次のミッションの初期設定
				missionSetStatus();
				
				// ターゲットのステージ読み込み
				if(mission_type[c_mission] == 6) {
					loadTargetStage();
				}
				
				// ピンチかどうかチェック
				pinchCheck(player);
				
				stat[player] = 25;		// 少し待つ
				statc[player * 10 + 0] = wait1[player];
				statc[player * 10 + 1] = 3;
			} else {
				StopAllBGM();			// BGM停止
				if(!IsPlayWave(29)) PlaySE(29);
				
				if(mission_end[c_mission] == 1) {
					onRecord[player] = 0;	// リプレイ記録終了
					ending[player] = 1;		// エンディング
				} else if((mission_end[c_mission] == 2) || (mission_end[c_mission] == 3)) {
					onRecord[player] = 0;	// リプレイ記録終了
					ending[player] = 4;		// 足切り
				} else if(mission_end[c_mission] == 4) {
					ending[player] = 1;		// ノーマルロール
				} else if(mission_end[c_mission] == 5) {
					hidden[player] = 2;
					ending[player] = 1;		// 消えロール
				} else if(mission_end[c_mission] == 6) {
					hidden[player] = 2;
					IsBig[player] = 1;
					ending[player] = 1;		// 消えビッグロール
					n_bx[player] = 2;
				} else if(mission_end[c_mission] == 7) {
					IsBig[player] = 1;
					ending[player] = 1;		// ビッグロール
					n_bx[player] = 2;
				} else if(mission_end[c_mission] == 8) {
					hidden[player] = 1;
					ending[player] = 1;		// 見えロール
				} else if(mission_end[c_mission] == 9) {
					hidden[player] = 1;
					IsBig[player] = 1;
					ending[player] = 1;		// 見えビッグロール
					n_bx[player] = 2;
				}
				
				stat[player] = 14;		// エンディング突入
			}
			
			return;
		}
		
		if( (ending[player] == 1) || (ending[player] == 4) ) {
			stat[player] = 14;	// エンディング突入
		} else {
			// アイテム発動
			if(goItemStat(player, stat[player])) return;
			
			// レベルアップ判定
			if(!lastblkline[player]) LevelUp(player);
			
			if(gameMode[player] == 6) {
				// ロールロール化判断
				if( (rollroll_flag[player]) && ((bdowncnt[player] + 1) % p_rollroll_interval == 0) )
					isrollroll[player] = 1;
				else
					isrollroll[player] = 0;
				
				// X-RAY化判断
				isxray[player] = 0;
				if( (xray_flag[player]) && ((bdowncnt[player] + 1) % p_xray_interval == 0) ) {
					isxray[player] = 1;
					xray_counter[player] = 0;
				}
			}
			
			// フィールドミラー処理
			if(fldMirrorProc(player)) return;
			
			// せり上がり判定 #LITE10
			upLines[player] = upLines[player] + checkRiseUp(player);
			
			// せり上がり
			if(upLines[player] > 0) {
				statc[0 + player * 10] = 4;
				statc[1 + player * 10] = 1;
				statRiseLine(player);
				return;
			}
			
			// 落下開始
			statBlock(player);
		}
	}
}

/* フィールドミラー */
int fldMirrorProc(int player) {
	int		i, j;
	
	// 強制停止
	if((stopmirror_flag[player]) && (fmirror_cnt[player] == -20)) {
		isfmirror[player] = 0;
		stopmirror_flag[player] = 0;
		return 0;
	}
	
	p_fmirror_timer = 20;
	
	if( (isfmirror[player]) && ((bdowncnt[player] % p_fmirror_interval == 0) || (gameMode[player] == 8) || (item_mode[player])) ) {
		if(fmirror_cnt[player] <= p_fmirror_timer) {
			if(fmirror_cnt[player] == -20) {
				// フィールドをバッファに確保
				for(i = 0; i < 22; i++) {
					for(j = 0; j < 10; j++) {
						fldbuf[j + i * 10 + player * 220] = fld[j + i * 10 + player * 220];
						fldtbuf[j + i * 10 + player * 220] = fldt[j + i * 10 + player * 220];
						fldibuf[j + i * 10 + player * 220] = fldi[j + i * 10 + player * 220];
						fldobuf[j + i * 10 + player * 220] = fldo[j + i * 10 + player * 220];
						fldsbuf[j + i * 10 + player * 220] = flds[j + i * 10 + player * 220];
						
						// ブロックを消す
						fld[j + i * 10 + player * 220] = 0;
						fldt[j + i * 10 + player * 220] = 0;
						fldi[j + i * 10 + player * 220] = 0;
						fldo[j + i * 10 + player * 220] = 0;
						flds[j + i * 10 + player * 220] = 0;
					}
				}
			} else {
				// 反転
				if( (fmirror_cnt[player] > 0) && (fmirror_cnt[player] % (p_fmirror_timer / 10) == 0) ) {
					for(i = 0; i < 22; i++) {
						j = fmirror_cnt[player] / (p_fmirror_timer / 10) - 1;
						fld[(10 - j - 1) + i * 10 + player * 220] = fldbuf[j + i * 10 + player * 220];
						fldt[(10 - j - 1) + i * 10 + player * 220] = fldtbuf[j + i * 10 + player * 220];
						fldi[(10 - j - 1) + i * 10 + player * 220] = fldibuf[j + i * 10 + player * 220];
						fldo[(10 - j - 1) + i * 10 + player * 220] = fldobuf[j + i * 10 + player * 220];
						flds[(10 - j - 1) + i * 10 + player * 220] = fldsbuf[j + i * 10 + player * 220];
					}
					
					ExBltFast(17, 8 + ((10 - j - 1) * 8) + foffset[player], 40);
				}
			}
			fmirror_cnt[player]++;
			field_spin[player]++;
			return 1;
		} else if(fmirror_cnt[player] <= p_fmirror_timer + 4) {
			// 4フレームの待ち時間
			fmirror_cnt[player]++;
			field_spin[player]++;
			return 1;
		}
		fmirror_cnt[player] = -20;
		field_spin[player] = -1;
		
		// CPUの操作
		if( (cpu_flag[player]) && ((!replayauto) || (repversw <= 3)) ) {
			cpu_setBestSpot(player, next[player], 0, getNextBlock(player, nextc[player] + 1), 0);
			cpu_setCtrl(player);
		}
	}
	return 0;
}

/* レベルアップ判定 */
void LevelUp(int player) {
	int tmp, tmp2;
	
	if(ending[player]) return;
	
	if((!isAceModeOrMission(player)) && (gameMode[player] != 9) && (!isMarathonMode(player))) {
		if(tc[player] / 10 <= tr[player]) return;
		tr[player]++;
		tr2[player]++;
	}
	
	jump(gameMode[player],lbeg,lmas,l20g,ldvl,lvs,lpra,ltmo,lace,lmis,lold,lhep,ldvm,lace200,lbegp,lfinal,ltmo,ledvl,lstd,lmar);
	
	/*
	switch(gameMode[player]) {
		case  0: goto lbeg;
		case  1: goto lmas;
		case  2: goto l20g;
		case  3: goto ldvl;
		case  4: goto lvs;
		case  5: goto lpra;
		case  6: goto ltmo;
		case  7: goto lace;
		case  8: goto lmis;
		case  9: goto lold;
		case 10: goto lhep;
		case 11: goto ldvm;
		case 12: goto lace200;
		case 13: goto lbegp;
		case 14: goto lfinal;
		case 15: goto ltmo;
		case 16: goto ledvl;
		case 17: goto lstd;
		case 18: goto lmar;
	}
	*/
	
	// ビギナーモードのレベルアップ判定
	lbeg:
		if(tr[player] < 101) {
			sp[player] = lvTableBeg[tr[player]];
		}
		
		if(tr[player] % 10 == 0) {
			PlaySE(19);
			
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
			
			// BGM切り替え
			if( (bgm >= 2) && (fadelv != 0) ) {
				bgmlv++;
				changeBGM();
			}
			
			// セクションタイム記録
			if(tr[player] / 10 <= 2) {
				now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// STメダル獲得
				getSTMedal(player, ((tr[player] / 10) - 1));
			}
		}
		return;
	
	// マスターモードのレベルアップ判定
	lmas:
		if((gradetype[player] == 1) && (tr[player] % 10 == 0)) {
			isregret(player);	// REGRET判定
			
			if(gup3sp_adjust[player] == 2)		// skip
				tr2[player] = tr2[player] + 10;
			
			if(gup3sp_adjust[player] == 0)		// やり直し
				tr2[player] = tr2[player] - 10;
		}
		
		if(tr2[player] < 51) {
			sp[player] = lvTableTgm[tr2[player]];
		}
		
		if(tr[player] % 10 == 0) {
			if((tr2[player] >= 50) && (tr2[player] <= 200) && (gradetype[player] != 2)) {
				sp[player] = 1200;
				wait1[player] = wait1_master_tbl[(tr2[player] - 50) / 10 * 2];
				wait2[player] = wait2_master_tbl[(tr2[player] - 50) / 10 * 2];
				wait3[player] = wait3_master_tbl[(tr2[player] - 50) / 10 * 2];
				waitt[player] = waitt_master_tbl[(tr2[player] - 50) / 10 * 2];
			}
			PlaySE(19);
			
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
			
			// BGM切り替え
			if( (bgm >= 2) && (fadelv != 0) ) {
				if(bgmlv == 0) tr_20g[player] = tr[player];
				bgmlv++;
				changeBGM();
			}
			
			// セクションタイム記録
			if(tr[player] / 10 <= 10) {
				now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// STメダル獲得
				getSTMedal(player, ((tr[player] / 10) - 1));
			}
			
			if(gradetype[player] == 1) reset_gradeup3(player);	// gradeup3に使う変数を一気にリセット
			
			// MASTER-EASY Gm条件成立判定
			if(gradetype[player] == 2) {
				// gmflag1成立判定（LV300になったときに段位が1以上）
				if((tc[player] >= 300) && (!gmflag1_e[player])) {
					if(grade[player] >= 8) {
						gmflag1[player] = 1;
						objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
					}
					gmflag1_e[player] = 1;
				}
				
				// gmflag2成立判定（LV500になったときに段位がS4以上）
				if((tc[player] >= 500) && (!gmflag2_e[player])) {
					if(grade[player] >= 12) {
						gmflag2[player] = 1;
						objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
					}
					gmflag2_e[player] = 1;
				}
			}
		}
		
		return;
	
	// 20Gモードのレベルアップ判定
	l20g:
		if((gradetype[player] == 1) && (tr[player] % 10 == 0)) {
			isregret(player);	// REGRET判定
			
			if(gup3sp_adjust[player] == 2)		// skip
				tr2[player] = tr2[player] + 10;
			
			if(gup3sp_adjust[player] == 0)		// やり直し
				tr2[player] = tr2[player] - 10;
		}
		
		if(tr[player] % 10 == 0) {
			if((tr2[player] >= 50) && (tr2[player] <= 100) && (gradetype[player] != 2)) {
				wait1[player] = wait1_master_tbl[(tr2[player] - 50) / 10 * 2];
				wait2[player] = wait2_master_tbl[(tr2[player] - 50) / 10 * 2];
				wait3[player] = wait3_master_tbl[(tr2[player] - 50) / 10 * 2];
				waitt[player] = waitt_master_tbl[(tr2[player] - 50) / 10 * 2];
			}
			PlaySE(19);
			
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
			
			// BGM切り替え
			if( (bgm >= 2) && (fadelv != 0) ) {
				bgmlv++;
				changeBGM();
			}
			
			// セクションタイム記録
			if(tr[player] / 10 <= 10) {
				now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// STメダル獲得
				getSTMedal(player, ((tr[player] / 10) - 1));
			}
			
			if(gradetype[player] == 1) reset_gradeup3(player);	// gradeup3に使う変数を一気にリセット
			
			// 20G-EASY Gm条件成立判定
			if((gradetype[player] == 2) && (repversw >= 8)) {
				// gmflag1成立判定（LV300になったときに段位が1以上）
				if((tc[player] >= 300) && (!gmflag1_e[player])) {
					if(grade[player] >= 8) {
						gmflag1[player] = 1;
						objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
					}
					gmflag1_e[player] = 1;
				}
				
				// gmflag2成立判定（LV500になったときに段位がS4以上）
				if((tc[player] >= 500) && (!gmflag2_e[player])) {
					if(grade[player] >= 12) {
						gmflag2[player] = 1;
						objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
					}
					gmflag2_e[player] = 1;
				}
			}
		}
		return;
	
	// デビル(DOOM)モードのレベルアップ判定
	ldvl:
		if(tr[player] % 10 == 0) {
			if(tr[player] <= 120) {
				if(repversw <= 6) {
					wait1[player] = wait1_devil_tbl6[tr[player] / 10];
					wait2[player] = wait2_devil_tbl6[tr[player] / 10];
					wait3[player] = wait3_devil_tbl6[tr[player] / 10];
					waitt[player] = waitt_devil_tbl6[tr[player] / 10];
				} else if(repversw <= 7) {
					wait1[player] = wait1_devil_tbl7[tr[player] / 10];
					wait2[player] = wait2_devil_tbl7[tr[player] / 10];
					wait3[player] = wait3_devil_tbl7[tr[player] / 10];
					waitt[player] = waitt_devil_tbl7[tr[player] / 10];
				} else {
					wait1[player] = wait1_devil_tbl[tr[player] / 10];
					wait2[player] = wait2_devil_tbl[tr[player] / 10];
					wait3[player] = wait3_devil_tbl[tr[player] / 10];
					waitt[player] = waitt_devil_tbl[tr[player] / 10];
				}
			}
			PlaySE(19);
			
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
			
			// BGM切り替え
			if( (bgm >= 2) && (fadelv != 0) ) {
				bgmlv++;
				changeBGM();
			}
			
			// セクションタイムがREGRET基準を超えてなければ段位上昇
			if((repversw <= 2) || (sectionTimer[player] < devil_doom_regret_border[(tr[player] / 10) - 1])) {
				grade[player]++;
				gup_down[player] = 1;
				gflash[player] = 120;
				if(grade[player] > 13) grade[player] = 13;
			} else {
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
			}
			
			// セクションタイム記録
			if(tr[player] / 10 <= 13) {
				now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// STメダル獲得
				getSTMedal(player, ((tr[player] / 10) - 1));
			}
			
			// せり上がりカウント設定
			if(repversw <= 6) {
				tmp = devil_rise_min6[tr[player] / 10];
				tmp2 = devil_rise_max6[tr[player] / 10];
			} else {
				tmp = devil_rise_min[tr[player] / 10];
				tmp2 = devil_rise_max[tr[player] / 10];
			}
			
			if((risecount[player] <= 0) && (tmp > 0) && (tmp2 > 0) && (r_enable[player])) {
				do {
					risecount[player] = GiziRand(player, tmp2 + 1);
				} while(risecount[player] < tmp);
			}
		}
		return;
	
	// VERSUS
	lvs:
		if((tr[player] % 10 == 0) && (!vs_goal_type)) {
			PlaySE(19);
		}
		return;
	
	// PRACTICE
	lpra:
		if(!p_leveltype) {
			if(tr[player] % 10 == 0) {
				PlaySE(19);
				
				// セクションタイム記録
				if(tr[player] / 10 <= 13) {
					now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
					sectionTimer[player] = 0;
				}
			}
		} else {
			if(c_norm[player] >= m_norm[player]) {
				PlaySE(31);
				
				tc[player]++;
				ltime[player] = p_timelimit;
				
				if(p_leveltype == 1) {
					m_norm[player] = m_norm[player] + 10;
					timeOn[player] = 0;
				} else {
					c_norm[player] = 0;
					m_norm[player] = (tc[player] + 1) * 5;
				}
				
				// セクションタイム記録
				now_sttime[(tc[player] - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// 警告音停止
				StopWave(38);
			}
		}
		return;
	
	// TOMOYO
	ltmo:
		if(tr[player] < 31) {
			if((!enable_minspeed) || (lvTabletomoyo[tr[player]] > min_speed[player]))
				sp[player] = lvTabletomoyo[tr[player]];
		}
		
		if(tr[player] % 10 == 0) {
			PlaySE(19);
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
		}
		return;
	
	// ACE
	lace:
		if(c_norm[player] >= m_norm[player]) {
			PlaySE(31);
			
			timeOn[player] = 0;
			
			tc[player]++;
			
			if(timeattack[player] == 0) {
				// NORMAL
				if(repversw >= 2) sp[player] = lvTableAce[tc[player]];
				else if(repversw == 1) sp[player] = lvTableAce1[tc[player]];
				else sp[player] = lvTableAceOld[tc[player]];
				ltime[player] = timeLimitAceNormal[tc[player]];
			} else if(timeattack[player] == 1) {
				// HI-SPEED1
				sp[player] = lvTableHiSpeed1[tc[player]];
				ltime[player] = timeLimitAcea[tc[player]];
			} else if(timeattack[player] == 2) {
				// HI-SPEED2
				ltime[player] = timeLimitAcea[tc[player]];
			} else if(timeattack[player] == 3) {
				// ANOTHER
				if(repversw <= 6) {
					wait1[player] = wait1_Acea_tbl6[tc[player]];
					wait2[player] = wait2_Acea_tbl6[tc[player]];
					wait3[player] = wait3_Acea_tbl6[tc[player]];
					waitt[player] = waitt_Acea_tbl6[tc[player]];
				} else if(repversw <= 7) {
					wait1[player] = wait1_Acea_tbl7[tc[player]];
					wait2[player] = wait2_Acea_tbl7[tc[player]];
					wait3[player] = wait3_Acea_tbl7[tc[player]];
					waitt[player] = waitt_Acea_tbl7[tc[player]];
				} else {
					wait1[player] = wait1_Acea_tbl[tc[player]];
					wait2[player] = wait2_Acea_tbl[tc[player]];
					wait3[player] = wait3_Acea_tbl[tc[player]];
					waitt[player] = waitt_Acea_tbl[tc[player]];
				}
				ltime[player] = timeLimitAcea[tc[player]];
			} else if(timeattack[player] == 4) {
				// ANOTHER2
				ltime[player] = timeLimitAcea[tc[player]];
			}
			
			m_norm[player] = m_norm[player] + 10;
			
			// セクションタイム記録
			now_sttime[(tc[player] - 1) + player * 30] = sectionTimer[player];
			sectionTimer[player] = 0;
			
			if(backno < tc[player]) bgfadesw = 1;
			
			// BGM切り替え
			if(fadelv != 0) {
				bgm_change++;
				bgmlv = ace_bgmlist[bgm_change + timeattack[player] * 3];
				changeBGM();
			}
			
			// 警告音停止
			StopWave(38);
		}
		
		return;
	
	// MISSION
	lmis:
		return;
	
	// OLD STYLE
	lold:
		if(timeattack[player] == 0) {
			// HANDHELD
			if(c_norm[player] >= m_norm[player]) {
				PlaySE(19);
				tc[player]++;
				
				if(tc[player] < 15) {
					sp[player] = lvTableHeboGB[tc[player]];
					wait3[player] = wait3_HeboGB_tbl[tc[player]];
					waitt[player] = waitt_HeboGB_tbl[tc[player]];
				}
				
				m_norm[player] = m_norm[player] + 10;
				
				// セクションタイム記録
				if(tc[player] <= 15) {
					now_sttime[(tc[player] - 1) + player * 30] = sectionTimer[player];
					sectionTimer[player] = 0;
				}
				
				if(backno < tc[player]) bgfadesw = 1;
			}
		} else {
			// ARCADE
			tmp = tc[player];
			if(tmp > 15) tmp = 15;
			
			if((c_norm[player] >= 4) || ((sectionTimer[player] >= lvTimerHeboAC[tmp] * 256) && (!lastblkline[player]))) {
				PlaySE(19);
				tc[player]++;
				
				if(tc[player] < 16) {
					sp[player] = lvTableHeboAC[tc[player]];
				}
				
				c_norm[player] = 0;
				
				// セクションタイム記録
				if(tc[player] <= 16) {
					now_sttime[(tc[player] - 1) + player * 30] = sectionTimer[player];
				}
				sectionTimer[player] = 0;
				
				if((backno < tc[player]) && (backno < 14)) bgfadesw = 1;
			}
		}
		
		return;
	
	// HEBO+
	lhep:
		if(tr[player] < 51) {
			sp[player] = lvTableTgm[tr[player]];
		}
		
		if(tr[player] % 10 == 0) {
			PlaySE(19);
			
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
			
			if(r_inter[player] > 1) r_inter[player]--;	// せり上がり間隔-1
			
			// BGM切り替え
			if( (bgm >= 2) && (fadelv != 0) ) {
				bgmlv++;
				changeBGM();
			}
			
			// セクションタイム記録
			if(tr[player] / 10 <= 10) {
				now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// STメダル獲得
				getSTMedal(player, ((tr[player] / 10) - 1));
			}
		}
		return;
	
	// DEVIL-NORMAL
	ldvm:
		if(tr[player] % 10 == 0) {
			if(tr[player] <= 50) {
				if(repversw <= 6) {
					wait1[player] = wait1_devil_m_tbl6[tr[player] / 10];
					wait2[player] = wait2_devil_m_tbl6[tr[player] / 10];
					wait3[player] = wait3_devil_m_tbl6[tr[player] / 10];
					waitt[player] = waitt_devil_m_tbl6[tr[player] / 10];
				} else {
					wait1[player] = wait1_devil_m_tbl[tr[player] / 10];
					wait2[player] = wait2_devil_m_tbl[tr[player] / 10];
					wait3[player] = wait3_devil_m_tbl[tr[player] / 10];
					waitt[player] = waitt_devil_m_tbl[tr[player] / 10];
				}
			}
			PlaySE(19);
			
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
			
			// BGM切り替え
			if( (bgm >= 2) && (fadelv != 0) ) {
				bgmlv++;
				changeBGM();
			}
			
			// セクションタイム記録
			if(tr[player] / 10 <= 10) {
				now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// STメダル獲得
				getSTMedal(player, ((tr[player] / 10) - 1));
			}
		}
		return;
	
	// ACE (BASIC～VOID）
	lace200:
		if(c_norm[player] >= m_norm[player]) {
			PlaySE(31);
			
			timeOn[player] = 0;
			
			tc[player]++;
			
			if(timeattack[player] == 0) {
				// BASIC
				sp[player] = lvTableAce200Basic[tc[player]];
				wait1[player] = wait1_Ace200Basic_tbl[tc[player]];
				wait2[player] = wait2_Ace200Basic_tbl[tc[player]];
				wait3[player] = wait3_Ace200Basic_tbl[tc[player]];
				waitt[player] = waitt_Ace200Basic_tbl[tc[player]];
				ltime[player] = timeLimitAce200Basic[tc[player]];
			} else if(timeattack[player] == 1) {
				// HELL
				ltime[player] = timeLimitAce200Hell[tc[player]];
				
				if((tc[player] >= 5) && (tc[player] <= 6)) {
					hidden_old[player] = 4;			// レベル6～7
				} else if((tc[player] >= 7) && (tc[player] <= 14)) {
					hidden_old[player] = 5;			// レベル8～15
				} else if(tc[player] >= 15) {
					hidden_old[player] = 0;
					always_over1000[player] = 1;	// レベル16以降は[]
				}
			} else if(timeattack[player] == 2) {
				// HELL-X
				ltime[player] = timeLimitAce200Hell[tc[player]];
				
				if((tc[player] >= 5) && (tc[player] <= 14)) {
					hidden[player] = 1;
					shadowtime[player] = 150;
				} else if((tc[player] >= 15) && (tc[player] <= 18)) {
					shadowtime[player] = 120;
				} else if(tc[player] >= 19) {
					shadowtime[player] = 60;
				}
			} else if(timeattack[player] == 3) {
				// VOID
				wait1[player] = wait1_Ace200Void_tbl[tc[player]];
				wait2[player] = wait2_Ace200Void_tbl[tc[player]];
				wait3[player] = wait3_Ace200Void_tbl[tc[player]];
				waitt[player] = waitt_Ace200Void_tbl[tc[player]];
				ltime[player] = timeLimitAce200Void[tc[player]];
			}
			
			m_norm[player] = m_norm[player] + 10;
			
			// セクションタイム記録
			now_sttime[(tc[player] - 1) + player * 30] = sectionTimer[player];
			sectionTimer[player] = 0;
			
			if((tc[player] >= 10) || (tc[player] % 2 == 0)) {
				if(backno < tc[player]) bgfadesw = 1;
			}
			
			// BGM切り替え
			if(fadelv != 0) {
				bgm_change++;
				bgmlv = ace200_bgmlist[bgm_change + timeattack[player] * 3];
				changeBGM();
			}
			
			// 警告音停止
			StopWave(38);
		}
		return;
	
	// BEGINNER-NOVICE
	lbegp:
		if(tr[player] < 101) {
			sp[player] = lvTableBeg[tr[player]];
		}
		
		if(tr[player] % 10 == 0) {
			PlaySE(19);
			
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
			
			// アイテム出現
			if((tc[player] >= 100) && (tc[player] < 200)) {
				PlaySE(28);
				item_nblk[2 + player * 6] = 28;	// FREE FALL
				item_name[player] = item_nblk[2 + player * 6];
			} else if((tc[player] >= 200) && (tc[player] < 300)) {
				PlaySE(28);
				item_nblk[2 + player * 6] = 19;	// DEL EVEN
				item_name[player] = item_nblk[2 + player * 6];
			}
			
			// BGM切り替え
			if( (bgm >= 2) && (fadelv != 0) ) {
				bgmlv++;
				changeBGM();
			}
			
			// セクションタイム記録
			if(tr[player] / 10 <= 3) {
				now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// STメダル獲得
				getSTMedal(player, ((tr[player] / 10) - 1));
			}
		}
		return;
	
	// FINAL
	lfinal:
		if(tr[player] % 10 == 0) {
			if(tr[player] <= 90) {
				if(repversw <= 4) {
					wait1[player] = wait1_final4[tr[player] / 10];
					wait2[player] = wait2_final4[tr[player] / 10];
					wait3[player] = wait3_final4[tr[player] / 10];
					waitt[player] = waitt_final4[tr[player] / 10];
				} else {
					if(rule_lock_reset[rots[player]]) {
						wait1[player] = wait1_final_srs[tr[player] / 10];
						wait2[player] = wait2_final_srs[tr[player] / 10];
						wait3[player] = wait3_final_srs[tr[player] / 10];
						waitt[player] = waitt_final_srs[tr[player] / 10];
					} else {
						wait1[player] = wait1_final_ars[tr[player] / 10];
						wait2[player] = wait2_final_ars[tr[player] / 10];
						wait3[player] = wait3_final_ars[tr[player] / 10];
						waitt[player] = waitt_final_ars[tr[player] / 10];
					}
				}
			}
			
			PlaySE(19);
			
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
			
			// セクションタイム記録
			if(tr[player] / 10 <= 10) {
				now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// STメダル獲得
				getSTMedal(player, ((tr[player] / 10) - 1));
			}
		}
		return;
	
	// DEVIL-HARD
	ledvl:
		if(tr[player] % 10 == 0) {
			if(tr[player] <= 120) {
				wait1[player] = wait1_devil_tbl32[tr[player] / 10];
				wait2[player] = wait2_devil_tbl32[tr[player] / 10];
				wait3[player] = wait3_devil_tbl32[tr[player] / 10];
				waitt[player] = waitt_devil_tbl32[tr[player] / 10];
			}
			PlaySE(19);
			
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
			
			// BGM切り替え
			if( (bgm >= 2) && (fadelv != 0) ) {
				bgmlv++;
				changeBGM();
			}
			
			// セクションタイムがREGRET基準を超えてなければ段位上昇
			if((repversw <= 2) || (sectionTimer[player] < devil_hard_regret_border[(tr[player] / 10) - 1])) {
				grade[player]++;
				gup_down[player] = 1;
				gflash[player] = 120;
				if(grade[player] > 13) grade[player] = 13;
			} else {
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
			}
			
			// セクションタイム記録
			if(tr[player] / 10 <= 13) {
				now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// STメダル獲得
				getSTMedal(player, ((tr[player] / 10) - 1));
			}
		}
		return;
	
	// STANDARD
	lstd:
		return;
	
	// MARATHON
	lmar:
		if((c_norm[player] >= m_norm[player]) && (tc[player] < 14)) {
			PlaySE(31);
			
			// レベルアップ
			tc[player]++;
			
			if(timeattack[player] == 2) {
				wait1[player] = wait1_Marathon_Oni[tc[player]];
				wait2[player] = wait2_Marathon_Oni[tc[player]];
				wait3[player] = wait3_Marathon_Oni[tc[player]];
				waitt[player] = waitt_Marathon_Oni[tc[player]];
				if(tc[player] >= 9) always_over1000[player] = 1;
			} else {
				sp[player] = lvTableMarathon[tc[player]];
				if(tc[player] >= 11) speedtype[player] = 0;
			}
			
			// セクションタイム記録
			now_sttime[(tc[player] - 1) + player * 30] = sectionTimer[player];
			sectionTimer[player] = 0;
			
			// 背景変更
			if(backno < tc[player]) bgfadesw = 1;
			
			c_norm[player] = 0;
			m_norm[player] = (tc[player] + 1) * 5;
		}
		return;
}

// せり上がり判定
int checkRiseUp(int player) {
	int tmp, tmp2;
	
	if((gameMode[player] == 3) && (!devil_doom_n_rise)) {
		// DEVIL
		if(repversw <= 6) {
			tmp = devil_rise_min6[tr[player] / 10];
			tmp2 = devil_rise_max6[tr[player] / 10];
		} else {
			tmp = devil_rise_min[tr[player] / 10];
			tmp2 = devil_rise_max[tr[player] / 10];
		}
		
		if((risecount[player] <= 0) && (tmp > 0) && (tmp2 > 0) && (r_enable[player])) {
			do {
				risecount[player] = GiziRand(player, tmp2 + 1);
			} while(risecount[player] < tmp);
			
			return 1;
		}
	} else if(gameMode[player] == 8) {
		// MISSION
		if(r_enable[player]) {
			// DEVIL 800
			if(mission_type[c_mission] == 19) {
				if(mission_opt_2[c_mission]) {
					// RANDOMあり
					if(repversw <= 6) {
						tmp = devil_rise_min6[8];
						tmp2 = devil_rise_max6[8];
					} else {
						tmp = devil_rise_min[8];
						tmp2 = devil_rise_max[8];
					}
					
					if((risecount[player] <= 0) && (tmp > 0) && (tmp2 > 0)) {
						do {
							risecount[player] = GiziRand(player, tmp2 + 1);
						} while(risecount[player] < tmp);
						return 1;
					}
				} else {
					// RANDOMなし
					if((r_bdowncnt[player] > 0) && (r_bdowncnt[player] % r_inter[player] == 0)) {
						return 1;
					}
				}
			}
		}
	} else if(gameMode[player] == 10) {
		// HEBO+
		if(r_bdowncnt[player] >= r_inter[player]) {
			r_bdowncnt[player] = 0;
			return 1;
		}
	} else {
		// 通常
		if((r_enable[player]) && (tc[player] >= r_start[player]) && (tc[player] <= r_end[player])) {
			if((r_bdowncnt[player] > 0) && (r_bdowncnt[player] % r_inter[player] == 0)) {
				return 1;
			}
		}
	}
	
	return 0;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.07 - ゲームオーバー
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statGameOver(int player) {
	int		i, j, block, c, tmp, draw_rate;

	// VERSUS専用死亡処理
	if(gameMode[player] == 4) {
		if(flag == 0) {
			StopAllBGM();
			winr = 0;
			winc = 0;
			winu = -24;
			wink = 0;
			flag = -1;
		}
		return;
	}

	if(hidden[player]) {
		hidden[player] = 0;			// フィールドタイマーを解除
		disableShadowTimer(player);
		statc[player * 10 + 5] = 1;
	}

	hidden_old[player] = 0;
	hiddeny[player] = 22;

	// リプレイセーブ
	ReplaySaveCheck(player, 3);

	if(statc[player * 10 + 3]) {
		sprintf(string[0], "SAVED:  %02d", statc[player * 10 + 3]);
		printFont(boffset[player], 26, string[0], 5);
	}

	statc[player * 10 + 1]++;
	
	// プレイヤーデータ更新
	if(!statc[player * 10 + 4] && !IsBigStart[player] && !item_mode[player] && user_enable[player]) {
		if(gameMode[player] == 0) {
			// BEGINNER-TAMAYA
			user_beginner_tamaya[player] = user_beginner_tamaya[player] + sc[player];
		} else if(gameMode[player] == 1) {
			if(gradetype[player] == 0) {
				// MASTER-NORMAL
				if(grade[player] > user_master_normal[player])
					user_master_normal[player] = grade[player];
			} else if(gradetype[player] == 1) {
				// MASTER-HARD
				if(grade[player] > user_master_hard_provisional[player])
					user_master_hard_provisional[player] = grade[player];
				
				// 履歴をずらす
				user_master_hard_grade_his[player * 5 + 4] = user_master_hard_grade_his[player * 5 + 3];
				user_master_hard_grade_his[player * 5 + 3] = user_master_hard_grade_his[player * 5 + 2];
				user_master_hard_grade_his[player * 5 + 2] = user_master_hard_grade_his[player * 5 + 1];
				user_master_hard_grade_his[player * 5 + 1] = user_master_hard_grade_his[player * 5 + 0];
				
				// 履歴に今回の暫定段位を入れる
				user_master_hard_grade_his[player * 5 + 0] = grade[player];
				
				// 最後の試験からの経過時間+1
				if(!examination[player]) user_master_hard_grade_pasttime[player]++;
			}
		} else if(gameMode[player] == 3) {
			// DEVIL-DOOM
			if(grade[player] > user_devil_doom[player])
				user_devil_doom[player] = grade[player];
		} else if(gameMode[player] == 6) {
			// TOMOYO
			if(start_stage[player] == 0) {
				if(stage[player] > user_tomoyo_normal[player]) user_tomoyo_normal[player] = stage[player];
			} else if(start_stage[player] == 27) {
				if(stage[player] > user_tomoyo_eheart[player]) user_tomoyo_eheart[player] = stage[player];
			} else if(start_stage[player] == 45) {
				if(stage[player] > user_tomoyo_target[player]) user_tomoyo_target[player] = stage[player];
			}
		} else if(gameMode[player] == 7) {
			// ACE-NORMAL～ACE-ANOTHER2
			if(end_f[player]) {
				if((!user_ace[player * 5 + timeattack[player]]) || (gameTimer[player] < user_ace[player * 5 + timeattack[player]]))
					user_ace[player * 5 + timeattack[player]] = gameTimer[player];
			}
		} else if(gameMode[player] == 11) {
			// DEVIL-NORMAL
			if(tc[player] > user_devil_normal[player])
				user_devil_normal[player] = tc[player];
		} else if(gameMode[player] == 13) {
			// BEGINNER-NOVICE
			user_beginner_novice[player] = user_beginner_novice[player] + sc[player];
		} else if(gameMode[player] == 15) {
			// TOMOYO-FLASH
			if(stage[player] > user_tomoyo_flash[player]) user_tomoyo_flash[player] = stage[player];
		} else if(gameMode[player] == 16) {
			// DEVIL-HARD
			if(grade[player] > user_devil_hard[player])
				user_devil_hard[player] = grade[player];
		}
		
		statc[player * 10 + 4] = 1;
	}
	
	if(statc[player * 10 + 2] == 0) {
		statc[player * 10] = 21;
		statc[player * 10 + 2] = 1;
	}
	
	// フィールドにブロックが無い場合はブロックが消える演出を省略
	if(isBravo(player)) {
		statc[player * 10] = -2;
	}
	
	if(statc[player * 10] == -2) {
		tmp = 60;
		
		// 段位表示
		if(((gameMode[player] == 1) || (gameMode[player] == 2) || (gameMode[player] == 3) || (gameMode[player] == 16)) && 
		   (!examination[player]) && (!demo || demokind) && (gradetype[player] != 2))
		{
			tmp = 300;
			
			// 「あなたの段位は」の文字
			if(statc[player * 10 + 1] == 1) {
				if(screenMode >= 2) draw_rate = 2;
				else draw_rate = 1;
				
				TextSize(player, 10 * draw_rate);
				TextColor(player, 255, 255, 255);
				TextBackColorDisable(player);
				
				if((gameMode[player] == 1) && (gradetype[player] == 1)) {
					TextOut(player, yourgrade[english + 2]);
					TextLayerOn(player, (foffset[player] + 3) * draw_rate, 92 * draw_rate);
				} else {
					TextOut(player, yourgrade[english]);
					TextLayerOn(player, (foffset[player] + 13) * draw_rate, 92 * draw_rate);
				}
			}
			
			if((gameMode[player] == 1) || (gameMode[player] == 2)) {
				drawGradeImage(foffset[player] + 2, 108, grade[player], 0);
			} else if(gameMode[player] == 16) {
				drawGradeImage(foffset[player] + 2, 108, grade[player], 1);
			} else {
				drawGradeImage(foffset[player] + 2, 108, grade[player], 2);
			}
			
			// ボタンでスキップ
			if(getPushState(player, 4)) {
				tmp = 60;
			}
		}
		
		if(statc[player * 10 + 1] >= tmp) {
			// 「あなたの段位は」表示を消去
			if((gameMode[player] == 1) || (gameMode[player] == 2) || (gameMode[player] == 3) || (gameMode[player] == 16))
				TextLayerOff(player);
			
			if((fastroll[player]) && (ending[player] == 2)) {
				// 高速ロールで窒息した場合はエンディング終了まで待つ
				stat[player] = 1;
				statc[player * 10 + 1] = 35;
			} else if(examination[player]) {
				// 試験結果へ
				stat[player] = 40;
				statc[player * 10] = 0;
				statc[player * 10 + 1] = 1;
				statc[player * 10 + 2] = 0;
				statc[player * 10 + 3] = 0;
				statc[player * 10 + 4] = 0;
				statc[player * 10 + 5] = 0;
			} else {
				// ネームエントリーへ
				stat[player] = 11;
				statc[player * 10] = 0;
				statc[player * 10 + 1] = 0;
				statc[player * 10 + 2] = 0;
				statc[player * 10 + 3] = 0;
				statc[player * 10 + 4] = 0;
				statc[player * 10 + 5] = 0;
			}
		}
		return;
	}

	if(statc[player * 10 + 1] > 4 + statc[player * 10 + 5] * 116) {
		block = statc[player * 10];
		
		statc[player * 10 + 1] = 0;
		
		for(j = 0; j < 10; j++) {
			// スーッと消えていく演出
			if(block >= 0) {
				c = fldt[j + block * 10 + player * 220];
				if(c == -1) c = 8;
				fldt[j + block * 10 + player * 220] = c - 4;
			}
			
			if(block <= 20) {
				c = fldt[j + (block + 1) * 10 + player * 220];
				fldt[j + (block + 1) * 10 + player * 220] = c - 4;
			}
		}
		
		statc[player * 10 + 5] = 0;
		statc[player * 10]--;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.08 - ブロック消去
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statEraseBlock(int player) {
	int		i, j, k, l, x, y, lines, all, hardblock, itemerase, allowskip, squares, squarecount;
	
	padRepeat(player);
	
	// 新IRS
	if(ace_irs) doNewIRS(player, 0);
	
	// HYPER横先行移動
	if(fastlrmove == 3) HyperLRMove(player);
	
	// ↓を離している場合、下入れ制限解除
	if( !getPressState(player, 1) ) down_flag[player] = 0;
	if( !getPressState(player, 0) ) up_flag[player] = 0;
	
	// 旧HIDDEN処理
	hiddenProc(player);
	
	// AREスキップが可能か決める（SKIP LOCKFLASHがSUPERかつ消去エフェクトに入って最初の1フレームの場合はスキップ不可）
	if((skip_blocklockflash == 3) && (repversw >= 7)) {
		allowskip = (statc[player * 10] != 0);
	} else if(skip_blocklockflash != 2) {
		allowskip = 1;
	} else {
		allowskip = (statc[player * 10] != 0);
	}
	
	if(statc[player * 10] < 1) {
		lines = 0;
		itemerase = 0;		// アイテム消去フラグ
		squares = 0;		// 正方形消去フラグ（金の正方形は銀の２個分）
		
		if((item[player]) && (repversw >= 3)) {
			itemerase = 1;
			item_waiting[player] = item[player];
		}
		
		for(i = 0; i < 22; i++) {
			if(erase[i + player * 22]) {
				lines++;
				squarecount = 0;	// 正方形判定カウンタ（正方形が見つかったあと4ブロック分判定停止）
				
				for(x = 0; x < 10; x++) {
					hardblock = 0;	// ハードブロック消去フラグ
					
					if((breakeffect > 0) && (fldo[x + i * 10 + player * 220] == 0)) {
						if( (breakeffect == 1) || ((gameMode[player] == 0) && (beginner_effect)) || 
						    (heboGB[player]) || (breakeffect >= 4) || 
						    (fld[x + i * 10 + player * 220] >= 11) || 
						    ((lines & 1 != 0) && (x & 1 == 1)) || ((lines & 1 == 0) && (x & 1 == 0)) )
						{
							objectCreate(player, 1, (x + boffset[player]) * 8, (i + 3) * 8, (x - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + lines * 250, fld[x + i * 10 + player * 220] - 1, 100);
						}
					}
					
					// 消えるブロックがプラチナブロックなら
					if(fld[x + i * 10 + player * 220] >= 11) {
						// リミットタイム延長
						if((tomoyo_timebonus[player]) && (gameMode[player] == 6)) {
							ltime[player] = ltime[player] + 60;
							StopWave(38);
						}
						
						// プラチナブロック数-1
						rest_pblock[player]--;
						
						// 音を再生
						platinaerase_cnt[player]++;
					}
					
					// 消えるブロックがアイテム
					if(fldi[x + i * 10 + player * 220]) {
						if(fldi[x + i * 10 + player * 220] == fldisno) {
							// 銀スクウェア
							if(!squarecount) {
								squares++;
								squarecount = 4;
							} else {
								squarecount--;
							}
						} else if(fldi[x + i * 10 + player * 220] == fldigsno) {
							// 金スクウェア
							if(!squarecount) {
								squares = squares + 2;
								squarecount = 4;
							} else {
								squarecount--;
							}
						} else if(fldi[x + i * 10 + player * 220] == fldihardno) {
							// ハードブロック
							hardblock = 1;
							erase[i + player * 22] = 0;
							fldi[x + i * 10 + player * 220] = 0;
							squarecount = 0;
						} else if(fldi[x + i * 10 + player * 220] < fldihardno) {
							// アイテム
							itemerase = 1;
							if(breakeffect) objectCreate(player, 9, (x + boffset[player]) * 8, (i + 3) * 8, 0, 0, 0, 0);
							if(!item_waiting[player]) item_waiting[player] = fldi[x + i * 10 + player * 220];
							squarecount = 0;
						}
					} else {
						squarecount = 0;
					}
					
					if(!hardblock) {
						fld[x + i * 10 + player * 220] = 0;
						fldt[x + i * 10 + player * 220] = 0;
						fldi[x + i * 10 + player * 220] = 0;
						fldo[x + i * 10 + player * 220] = 0;
						grayoutLackedBlock(player, flds[x + i * 10 + player * 220]);
						flds[x + i * 10 + player * 220] = 0;
					}
				}
			}
		}
		
		statc[player * 10]++;
		
		// 全消しチェック
		all = isBravo(player);
		
		// BIGでの0.5ライン消しは0ライン消しにする
		if((IsBig[player]) && (lines == 1)) lines = 0;
		
		// BIGの場合はライン数を2で割る
		if((IsBig[player]) && (lines >= 2)) lines = lines / 2;
		
		lastblkline[player] = lines;
		
		lastline[player] = lines;
		if(enable_disp_lastline) lastline_frame[player] = 60;
		
		if(IsTspin[player]) lasttspin[player] = lines;
		
		if(lines) {
			i = lines;
			if(i > 4) i = 4;
			
			PlaySE(10 + i);
			
			if(i >= 4) PlaySE(17);
			if(hebocombo[player]) PlaySE(18);
		} else {
			PlaySE(11);
		}
		
		if(enable_combo) {
			combo[player]++;
			if(lines >= 2) combo2[player]++;
			cmbpts[player] = cmbpts[player] + (lines * 2 - 2);
			
			if(IsTspin[player]) tcombo[player]++;
			else tcombo[player] = 0;
		} else {
			combo[player] = 0;
			cmbpts[player] = 0;
			combo2[player] = 0;
			tcombo[player] = 0;
		}
		
		// 花火計算 #LITE19
		if((gameMode[player] == 0) && (!itemerase)) {
			if(!enable_combo) hanabi_combo[player] = 0;
			
			if( (lines >= 2) || ((IsTspin[player]) && (lines >= 1)) ) {
				// T-SPINボーナス
				if((IsTspin[player]) && (bonus_tspin))
					hanabi_combo[player] = ((hanabi_combo[player] + lines) * 5) / 2;
				
				i = lines + hanabi_combo[player] + combo2[player];
				hanabi_combo[player] = i;		// 前に打ち上げた数を覚えておく（ただしLV150以降の倍率は除く）
				
				if(ending[player] == 2)    i = i * 2;			// ロール中は2倍
				else if(tc[player] >= 150) i = i + (i / 2);		// LV150以降は1.5倍
			} else {
				// T-SPINなしの一列消しはコンボ中でも一発
				i = 1;
			}
			
			// 全消しで4倍
			if(all) i = i * 4;
			
			sc[player] = sc[player] + i;
			hanabi_waiting[player] = hanabi_waiting[player] + i;
			hanabi_frame[player] = 0;
		}
		
		// ロール中に消した列数増加
		if(ending[player] == 2) {
			endlines[player] = endlines[player] + lines;
		}
		
		// BACK TO BACK
		if( (enable_b_to_b != 0) && ((lines >= 4) || (IsTspin[player])) && (isTSpinEnableMode(player)) ) {
			b_to_b[player] = 1;
			b_to_b_count[player]++;
			if(b_to_b_count[player] >= 2) b_to_b_frame[player] = 120;
		} else {
			b_to_b[player] = 0;
			b_to_b_count[player] = 0;
		}
		
		// ライン消し回数増加
		line_count[(lines - 1) + player * 4]++;
		if(user_enable[player]) user_line_count[(lines - 1) + player * 4]++;
		
		// T-SPIN回数増加
		if(IsTspin[player]) tspin_count[lines + player * 4]++;
		
		// スコア計算
		if(!ending[player] && !ismiss[player]) {
			calcScore(player, lines, all, itemerase, squares);
		}
	}
	
	if(statc[player * 10] >= wait2[player]) {
		// 上にあったブロックを下まで下ろす
		lines = downFloatingBlocks(player);
		
		// BIGでの0.5ライン消しは0ライン消しにする
		if((IsBig[player]) && (lines == 1)) lines = 0;
		
		// BIGの場合はライン数を2で割る
		if((IsBig[player]) && (lines >= 2)) lines = lines / 2;
		
		PlaySE(2);
		
		if((lines >= 4) && (enable_combo)) hebocombo[player]++;
		
		// ヘボリス3連続で偽COOL
		if((gameMode[player] == 1) && (gradetype[player] == 1) && (hebocombo[player] == 3)) {
			PlaySE(48);
			gup_down[player] = 1;
			gflash[player] = 180;
		}
		
		// T-SPIN2連続で偽COOL
		if((gameMode[player] == 1) && (gradetype[player] == 1) && (tcombo[player] == 2)) {
			PlaySE(48);
			gup_down[player] = 1;
			gflash[player] = 180;
		}
		
		// 時間稼ぎへ
		stat[player] = 6;
		statc[player * 10] = wait1[player];
		statc[player * 10 + 1] = 0;
		
		// エンディング突入音
		if( ((ending[player] == 1) || (ending[player] == 4)) && (!IsPlayWave(29)) ) PlaySE(29);
		
		pinchCheck(player);
		
		// アイテム発動
		if(item_waiting[player]) {
			eraseItem(player, item_waiting[player]);
		}
	} else {
		// AREスキップ
		if((rule_are[rots[player]] == 2) && (harddrop[player]) && (allowskip)) {
			if(getPushState(player, 0) || getPushState(player, 1) || getPushState(player, 2) || getPushState(player, 3) ||
			   getPushState(player, 4) || getPushState(player, 5) || getPushState(player, 6) )
			{
				statc[player * 10] = wait2[player];
				are_skipflag[player] = 1;
			}
		}
		
		statc[player * 10]++;
	}
}

// 上にあったブロックを下まで下ろす
int downFloatingBlocks(int player) {
	int		i, k, l, y, lines;
	
	y = 21;
	lines = 0;
	
	for(i = 0; i < 22; i++) {
		if(erase[y + player * 22]) {
			for(k = y; k > 0; k--) {
				for(l = 0; l < 10; l++) {
					fld[l + k * 10 + player * 220] = fld[l + (k - 1) * 10 + player * 220];
					fldt[l + k * 10 + player * 220] = fldt[l + (k - 1) * 10 + player * 220];
					fldi[l + k * 10 + player * 220] = fldi[l + (k - 1) * 10 + player * 220];
					fldo[l + k * 10 + player * 220] = fldo[l + (k - 1) * 10 + player * 220];
					flds[l + k * 10 + player * 220] = flds[l + (k - 1) * 10 + player * 220];
				}
				erase[k + player * 22] = erase[(k - 1) + player * 22];
			}
			
			// 一番上を空白にする
			for(l = 0; l < 10; l++) {
				fld[l + player * 220] = 0;
				fldt[l + player * 220] = 0;
				fldi[l + player * 220] = 0;
				fldo[l + player * 220] = 0;
				flds[l + player * 220] = 0;
			}
			erase[player * 22] = 0;
			
			lines++;
		} else {
			y--;
		}
	}
	
	return lines;
}

// 破片ブロック判定
void grayoutLackedBlock(int player, int no) {
	int i, j;
	
	if(no <= 0) return;
	
	for(j = 0; j < 22; j++) {
		for(i = 0; i < 10; i++) {
			if((fld[i + j * 10 + player * 220] >= 1) && (flds[i + j * 10 + player * 220] == no)) {
				flds[i + j * 10 + player * 220] = 0;	// 破片にする
				if(lackblock_grayout) fld[i + j * 10 + player * 220] = 1;	// 灰色ブロックにする
			}
		}
	}
}

// 正方形ができるかチェック
// player：プレイヤー番号 x:始点のX座標 y:始点のY座標 gold:1の場合は一種類のブロックのみで正方形ができる
int checkSquare(int player, int x, int y, int gold) {
	int i, j, color;
	
	// 始点の色を取得
	color = getFieldBlock(player, x, y);
	
	// 空白だったら失敗
	if(color <= 0) return 0;
	
	// おじゃまブロックや初期配置だったり、破片だったり、既に正方形だったら失敗
	if(getFieldBlockS(player, x, y) <= 0) return 0;
	
	// 色が2種類以上なら失敗（gold != 0のときのみ）
	if(gold) {
		for(i = 0; i < 4; i++) {
			for(j = 0; j < 4; j++) {
				if(getFieldBlock(player, x + i, y + j) != color) return 0;
			}
		}
	}
	
	// 破片があれば失敗
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 4; j++) {
			if(getFieldBlockS(player, x + i, y + j) <= 0) return 0;
		}
	}
	
	// 始点より上にブロックが繋がってたら失敗
	for(i = 0; i < 4; i++) {
		if(getFieldBlockS(player, x + i, y    ) == getFieldBlockS(player, x + i, y - 1)) return 0;
	}
	
	// 正方形の底より下にブロックが繋がってたら失敗
	for(i = 0; i < 4; i++) {
		if(getFieldBlockS(player, x + i, y + 3) == getFieldBlockS(player, x + i, y + 4)) return 0;
	}
	
	// 始点より左にブロックが繋がってたら失敗
	for(j = 0; j < 4; j++) {
		if(getFieldBlockS(player, x    , y + j) == getFieldBlockS(player, x - 1, y + j)) return 0;
	}
	
	// 正方形の端より右にブロックが繋がってたら失敗
	for(j = 0; j < 4; j++) {
		if(getFieldBlockS(player, x + 3, y + j) == getFieldBlockS(player, x + 4, y + j)) return 0;
	}
	
	// 成功
	return 1;
}

// 正方形を作る
int makeSquare(int player) {
	int i, j, k, l, result;
	result = 0;
	
	for(i = 0; i < 22 - 3; i++) {
		for(j = 0; j < 10 - 3; j++) {
			if(checkSquare(player, j, i, 1)) {
				// 金色
				if(result < 2) result = 2;
				PlaySE(18);
				squarenum[player] = squarenum[player] + 2;
				
				// マークを付ける
				for(k = 0; k < 4; k++) {
					for(l = 0; l < 4; l++) {
						fldi[(k + j) + (l + i) * 10 + player * 220] = fldigsno;
						flds[(k + j) + (l + i) * 10 + player * 220] = -1;
					}
				}
			} else if(checkSquare(player, j, i, 0)) {
				// 銀色
				if(result < 1) result = 1;
				PlaySE(17);
				squarenum[player]++;
				
				// マークを付ける
				for(k = 0; k < 4; k++) {
					for(l = 0; l < 4; l++) {
						fldi[(k + j) + (l + i) * 10 + player * 220] = fldisno;
						flds[(k + j) + (l + i) * 10 + player * 220] = -1;
					}
				}
			}
		} /* for(j = 0; j < 6; j++) */
	} /* for(i = 0; i < 18; i++) */
	
	return result;
}

// 全消しチェック
int isBravo(int player) {
	int all, i, j;
	
	all = 1;
	
	for(j = 0; j < 22; j++) {
		for(i = 0; i < 10; i++) {
			if(fld[i + j * 10 + player * 220] != 0) {
				all = 0;
				break;
			}
		}
	}
	
	return all;
}

// スコア計算
void calcScore(int player, int lines, int all, int itemerase, int squares) {
	int bo, bai, i, j, tcbuf;
	
	if(all) {
		// 全消し演出
		objectCreate(player, 2, player, 30, 0, 0, 0, 0);
		
		if(isAceModeOrMission(player)) PlaySE(19);
	}
	
	if(gameMode[player] == 8) {
		// MISSIONモード
		if((mission_type[c_mission] != 26) || (all)) missionNormUp(lines);
	} else if(gameMode[player] == 9) {
		// OLD STYLEモード
		c_norm[player] = c_norm[player] + lines;
		
		if(timeattack[player] == 0) {
			if(lines == 1) bo = 40;
			if(lines == 2) bo = 100;
			if(lines == 3) bo = 300;
			if(lines == 4) bo = 1200;
			bai = tc[player] + 1;
		} else {
			if(lines == 1) bo = 100;
			if(lines == 2) bo = 400;
			if(lines == 3) bo = 900;
			if(lines == 4) bo = 2000;
			
			if(tc[player] >= 8) {
				bai = 5;
			} else {
				bai = (tc[player] / 2) + 1;
			}
			
			if(all) bai = bai * 10;
		}
		
		sc[player] = sc[player] + bo * bai;
	} else if((gameMode[player] == 17) || (isMarathonMode(player))) {
		// SIMPLE/MARATHON/PRACTICE(10 LINES/MARATHON)モード
		if(bonus_tspin && IsTspin[player]) {
			// T-SPIN
			if(lines == 1) {
				if(!tspin_kick[player]) bo = 8;
				else bo = 2;
			}
			if(lines >= 2) bo = 12;
		} else {
			// 普通のライン消し
			if(lines == 1) bo = 1;
			if(lines == 2) bo = 3;
			if(lines == 3) bo = 5;
			if(lines == 4) bo = 8;
		}
		
		// スクウェアボーナス
		if(squares) bo = bo + squares * 5;
		
		bai = 1;
		
		// Back to Back
		if((bonus_btb) && (b_to_b_count[player] >= 2)) bai = (b_to_b_count[player] / 2);
		
		// スコア加算
		sc[player] = sc[player] + (bo * bai * 100 * (tc[player] + 1));
		if(gameMode[player] != 17) c_norm[player] = c_norm[player] + (bo * bai);
		
		// コンボボーナス
		if(combo[player] >= 2) {
			sc[player] = sc[player] + (combo[player] - 1) * 50 * (tc[player] + 1);
			if(gameMode[player] != 17) c_norm[player] = c_norm[player] + ((combo[player] - 1) / 2);
		}
		
		// SIMPLEモードのライン数
		if(gameMode[player] == 17) {
			c_norm[player] = c_norm[player] + lines;
		}
		
		// VSモードでは規定ポイントに到達すると勝利
		if((gameMode[player] == 4) && (vs_goal_level > 0) && (c_norm[player] >= vs_goal_level * 5)) {
			c_norm[player] = vs_goal_level * 5;
			setGameOver(1 - player);
		}
	} else if(isAceMode(player)) {
		// ACEモード
		c_norm[player] = c_norm[player] + lines;
		if(fadelv == 0) checkFadeout(player);
		
		// VSモードでは規定ラインに到達すると勝利
		if((gameMode[player] == 4) && (vs_goal_level > 0) && (c_norm[player] >= vs_goal_level * 10)) {
			c_norm[player] = vs_goal_level * 10;
			setGameOver(1 - player);
		}
	} else {
		// 通常モードならスコア計算
		if(isNormalMode(player)) {
			// 落下速度の遅いルールではドロップボーナス半減
			if(rule_soft_speed[rots[player]] == 0) qdrop[player] = qdrop[player] / 2;
			
			// 落下速度の速いルールではドロップボーナス1.5倍
			if(rule_soft_speed[rots[player]] == 2) qdrop[player] = qdrop[player] + (qdrop[player] / 2);
			
			// 落下速度が2倍のルールではドロップボーナス2倍
			if(rule_soft_speed[rots[player]] == 3) qdrop[player] = qdrop[player] * 2;
			
			bo = (tc[player] + lines) / 4 + sdrop[player] + qdrop[player];
			
			if((gameMode[player] >= 1) && (gameMode[player] <= 2) && (gradetype[player] == 2)) {
				// MASTER-EASY
				if(combo[player] >= 2) j = combo[player] - 1 + (2 * lines - 1);
				else j = 1;
				bai = lines * j;
			} else {
				// その他
				bai = (lines * 2 - 1 + cmbpts[player] - (lines * 2 - 2)) * lines;
			}
			
			// 全消しするとスコア4倍
			if(all) bai = bai * 4;
			
			// T-SPINで4倍
			if(bonus_tspin && IsTspin[player]) bai = bai * 4;
			
			// BACK TO BACKで1.5倍
			if((bonus_btb) && (b_to_b_count[player] >= 2)) bai = bai + (bai / 2);
			
			// BEGINNER+では常時6倍
			if(gameMode[player] == 13) bai = bai * 6;
			
			// スコア加算
			if(!itemerase) sc[player] = sc[player] + bo * bai;
		}
		
		// HARD用
		if(gradetype[player] == 1) {
			if(lines == 4) gskill[player]++;					// 4段消しボーナス
			
			if(bonus_tspin)
				gskill[player] = gskill[player] + IsTspin[player];	// T-SPINボーナス
		}
		
		// 段位 #LITE18
		if( (gameMode[player] == 1) || (gameMode[player] == 2) ) {
			if(gradetype[player] == 0)
				GradeUp(player, lines);
			else if(gradetype[player] == 1)
				GradeUp3(player);
			else if(gradetype[player] == 2)
				GradeUpEasy(player);
		}
		
		// PRACTICEの合計ライン数増加
		if(gameMode[player] == 5) c_norm[player] = c_norm[player] + lines;
		
		// 4段消し回数増加
		if( (lines == 4) && (isNormalOrBeginnerMode(player)) ) {
			skill[player]++;
			
			// SKメダル獲得
			if( (skill[player] == 15) || (skill[player] == 25) || (skill[player] == 40) ) {
				PlaySE(45);
				medal_sk[player]++;
				medal_visible_sk[player] = 0;
				objectCreate(player, 7, soffset[player] * 8 + 2 + 16, 129, 2, 0, 0, medal_sk[player]);
			}
		}
		
		// 全消しするとACメダル獲得
		if( (all) && (isNormalOrBeginnerMode(player)) ) {
			if(medal_ac[player] < 3) {
				PlaySE(45);
				medal_ac[player]++;
				medal_visible_ac[player] = 0;
				objectCreate(player, 7, soffset[player] * 8 + 2 + 16, 116, 0, 0, 0, medal_ac[player]);
			}
		}
		
		// COメダル獲得
		if(isNormalOrBeginnerMode(player)) {
			if( ((medal_co[player] == 0) && (combo2[player] == 4)) ||
				((medal_co[player] == 1) && (combo2[player] == 5)) ||
				((medal_co[player] == 2) && (combo2[player] == 7)) )
			{
				PlaySE(45);
				medal_co[player]++;
				medal_visible_co[player] = 0;
				objectCreate(player, 7, soffset[player] * 8 + 2, 129, 3, 0, 0, medal_co[player]);
			}
		}
		
		// BLIND
		if( (gameMode[player] == 6) && (blind_flag[player]) )
			isblind[player] = !isblind[player];
		
		// TGMLV上昇
		if(gameMode[player] != 17) {
			tcbuf = tc[player];
			if(!lvupbonus)
				tc[player] = tc[player] + lines + ((lines >= 3) * (lines - 2));
			else
				tc[player] = tc[player] + lines;
			
			// lvstop.wavを鳴らす
			if((gameMode[player] == 0) || (gameMode[player] == 3) || (gameMode[player] == 16))
				i = 99;
			else if(gameMode[player] == 13)
				i = 99 * (tc[player] >= 200);
			else
				i = 99 - ((tc[player] >= 900) && (timeattack[player]));
			
			if((tc[player] % 100 == i) && (i != 0)) PlaySE(28);
			
			// TOMOYOモードでは998でストップ
			if((gameMode[player] == 6) && (tc[player] > 998)) tc[player] = 998;
			
			// VSモードでは規定レベルに到達すると勝利
			if((gameMode[player] == 4) && (vs_goal_level > 0) && (tc[player] >= vs_goal_level * 100)) {
				tc[player] = vs_goal_level * 100;
				setGameOver(1 - player);
			}
		}
	}
	
	// ライン消去でアイテムゲージ上昇
	if((item_gauge_uptype >= 1) && (item_mode[player]) && (!ismiss[player])) {
		item_g[player] = item_g[player] + lines;
		
		if(item_gauge_uptype == 1) {
			if(item_g[player] > item_interval) item_g[player] = item_interval;
		} else {
			if(item_g[player] > item_interval + 1) item_g[player] = item_interval + 1;
		}
	}
	
	li[player] = li[player] + lines;						// ライン数増加
	
	if( (bgm >= 2) && (fadelv == 0) ) checkFadeout(player);	// BGMフェードアウトチェック
	
	// HIDDENで隠された段を見えるようにする
	hiddenti[player] = hiddenti[player] + lines;
	
	while(hiddenti[player] > 0) {
		hiddenti[player]--;
		hiddeny[player]++;
		if(hiddeny[player] > 22) {
			hiddeny[player] = 22;
			hiddentm[player] = 0;
		}
	}
	
	// スクウェアモードでのT-SPINフリーフォール
	// 本当はT-SPINシングルの場合はラインが消えたところから下だけフリーフォールするんだけど
	// ブロックの引っかかり判定が複雑なんで今の所は全部落とす
	if((squaremode[player]) && (IsTspin[player]) && (repversw >= 1)) {
		isFreefall[player] = 1;
	}
	
	// エンディング突入チェック
	checkEnding(player, tcbuf);
	
	// レベルアップ判定
	LevelUp(player);
}

// エンディングに突入するかチェック
void checkEnding(int player, int tcbuf) {
	int i, tmp;
	
	jump(gameMode[player],lbeg,lmas,lmas,ldvl,ldummy,lpra,ldummy,lace,ldummy,ldummy,lhep,ldvm,lace200,lbegp,lfinal,ldummy,ldvl,lstd,lmar);
	
	/*
	switch(gameMode[player]) {
		case  0: goto lbeg;
		case  1: goto lmas;
		case  2: goto lmas;
		case  3: goto ldvl;
		case  4: goto ldummy;
		case  5: goto lpra;
		case  6: goto ldummy;
		case  7: goto lace;
		case  8: goto ldummy;
		case  9: goto ldummy;
		case 10: goto lhep;
		case 11: goto ldvm;
		case 12: goto lace200;
		case 13: goto lbegp;
		case 14: goto lfinal;
		case 15: goto ldummy;
		case 16: goto ldvl;
		case 17: goto lstd;
		case 18: goto lmar;
	}
	*/
	
	lbeg:
		// BEGINNERなら200で終了
		if((tc[player] >= 200) && (timeattack[player])) {
			tc[player] = 200;
			timeOn[player] = 0;
			ending[player] = 1;
			end_f[player] = 1;
			
			// ロール中の花火間隔を決定
			if(sc[player] >= 400) {
				hanabi_int[player] = 12;	// 400発以上で秒間5発
			} else if(sc[player] >= 200) {
				hanabi_int[player] = 15;	// 200～399発で秒間4発
			} else {
				hanabi_int[player] = 20;	// 199以下で秒間3発
			}
			
			// スタッフロール用wait値セット
			sp[player] = speed_beginner_roll;
			wait1[player] = wait1_beginner_roll;
			wait2[player] = wait2_beginner_roll;
			wait3[player] = wait3_beginner_roll;
			waitt[player] = waitt_beginner_roll;
			
			PlaySE(19);
			//backno++;
			if(backno < 2) bgfadesw = 1;
			
			// セクションタイム記録
			now_sttime[1 + player * 30] = sectionTimer[player];
			
			// STメダル獲得
			getSTMedal(player, 1);
		}
		return;
	
	lmas:
		// MASTERと20Gでは999で終了
		if((tc[player] >= 999) && (timeattack[player])) {
			tc[player] = 999;
			timeOn[player] = 0;
			ending[player] = 1;
			end_f[player] = 1;
			
			// スタッフロール用wait値セット
			sp[player] = speed_master_roll;
			
			if(gradetype[player] == 1) {
				// HARD
				wait1[player] = wait1_master_rollG4;
				wait2[player] = wait2_master_rollG4;
				wait3[player] = wait3_master_rollG4;
				waitt[player] = waitt_master_rollG4;
			} else if(gradetype[player] == 0) {
				// NORMAL
				wait1[player] = wait1_master_roll;
				wait2[player] = wait2_master_roll;
				wait3[player] = wait3_master_roll;
				waitt[player] = waitt_master_roll;
			}
			
			// Gm条件を全て満たしているかチェック
			tmp = 0;
			
			if(gradetype[player] == 0) {
				// NORMAL
				// M以上で8分45秒以内
				if((grade[player] >= 27) && (gameTimer[player] <= 525 * 60) && (gmflag1[player]) && (gmflag2[player]))
				{
					tmp = 1;
				}
			} else if(gradetype[player] == 1) {
				// HARD
				// m5以上で6分30秒以内
				// LV400になったときにtr2変数が80以上、REGRETが一回も出ない
				if( (grade[player] >= 22) && (gameTimer[player] <= 390 * 60) && 
				    (gup3rank[player] == 2) && (gmflag1[player]) && (!gmflag2[player]) )
				{
					tmp = 1;
				}
			} else if(gradetype[player] == 2) {
				// EASY
				// S9で13:30:00以内、gmflag1とgmflag2点灯済み、スコア126000点以上
				if((grade[player] >= 17) && (gameTimer[player] <= 48600) && 
				   (sc[player] >= master_easy_score_table[17]) && (gmflag1[player]) && (gmflag2[player]))
				{
					tmp = 1;
				}
			}
			
			if(tmp) {
				gmflag_r[player] = 1;	// GMになる権利が与えられ、消えロール突入
				objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
			}
			
			// MASTER-EASY
			if(gradetype[player] == 2) {
				// Gm条件を満たしている場合
				if(gmflag_r[player]) {
					if(!IsPlayWave(29)) PlaySE(29);
					ending[player] = 2;
					ending_timeOn[player] = 1;
					end_f[player] = 2;
					
					grade[player] = 18;
					gup_down[player] = 1;
					gflash[player] = 120;
					
					// BGM切り替え
					if(bgm >= 2) {
						bgmlv = 7;
						changeBGM();
					}
				}
				// 満たしていない場合
				else {
					ending[player] = 4;
				}
			}
			
			// セクションタイム記録
			now_sttime[9 + player * 30] = sectionTimer[player];
			
			// STメダル獲得
			getSTMedal(player, 9);
		}
		
		// LV500の足切り #LITE20
		if( (tc[player] >= 500) && (tcbuf < 500) && (gradetype[player] != 2) && 
			(gameTimer[player] >= timelimit[0 + player * 2]) && (timelimit[0 + player * 2] > 0) )
		{
			tc[player] = 500;
			timeOn[player] = 0;
			if(repversw <= 4) onRecord[player] = 0;
			ending[player] = 4;
			
			// セクションタイム記録
			now_sttime[4 + player * 30] = sectionTimer[player];
			
			// 即エンディング
			stat[player] = 14;
			for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		}
		return;
	
	ldvl:
		// DEVIL(HARD/DOOM)では1300で終了
		if((tc[player] >= 1300) && (timeattack[player])) {
			tc[player] = 1300;
			timeOn[player] = 0;
			ending[player] = 1;
			end_f[player] = 1;
			
			// スタッフロール用wait値セット
			sp[player] = speed_devil_roll;
			if((repversw >= 4) && (gameMode[player] == 3)) {
				wait1[player] = wait1_devil_roll;
				wait2[player] = wait2_devil_roll;
				wait3[player] = wait3_devil_roll;
				waitt[player] = waitt_devil_roll;
			} else {
				wait1[player] = wait1_devil_roll3;
				wait2[player] = wait2_devil_roll3;
				wait3[player] = wait3_devil_roll3;
				waitt[player] = waitt_devil_roll3;
			}
			
			// セクションタイムが基準を超えていない場合は段位上昇
			if(gameMode[player] == 16) tmp = devil_hard_regret_border[12];
			else tmp = devil_doom_regret_border[12];
			
			if((repversw <= 2) || (sectionTimer[player] < tmp)) {
				grade[player]++;
				gflash[player] = 120;
				if(grade[player] > 13) grade[player] = 13;
			} else {
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
			}
			
			// セクションタイム記録
			now_sttime[12 + player * 30] = sectionTimer[player];
			
			// STメダル獲得
			getSTMedal(player, 12);
			
			// GOD条件を満たしている場合は流れ星出現
			if(grade[player] == 13) {
				if(isWRule(player)) {
					if(gameMode[player] == 16) tmp = 21000;
					else tmp = 19200;
				} else {
					if(gameMode[player] == 16) tmp = 19200;
					else tmp = 18000;
				}
				
				if(gameTimer[player] <= tmp) {
					objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
				}
			}
		}
		
		// LV500の足切り #LITE20
		if( (tc[player] >= 500) && (tcbuf < 500) && 
			(gameTimer[player] >= timelimit[0 + player * 2]) && (timelimit[0 + player * 2] > 0) )
		{
			tc[player] = 500;
			timeOn[player] = 0;
			if(repversw <= 4) onRecord[player] = 0;
			ending[player] = 4;
			
			// セクションタイム記録
			now_sttime[4 + player * 30] = sectionTimer[player];
			
			// 即エンディング
			stat[player] = 14;
			for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		}
		
		// LV1000の足切り #LITE20
		if( (tc[player] >= 1000) && (tcbuf < 1000) && 
			(gameTimer[player] >= timelimit[1 + player * 2]) && (timelimit[1 + player * 2] > 0) )
		{
			tc[player] = 1000;
			timeOn[player] = 0;
			if(repversw <= 4) onRecord[player] = 0;
			ending[player] = 4;
			
			// セクションタイム記録
			now_sttime[9 + player * 30] = sectionTimer[player];
			
			// 即エンディング
			stat[player] = 14;
			for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		}
		
		return;
	
	ldummy:
		// エンディングなし
		return;
	
	lpra:
		// PRACTICE
		if(p_goal > 0) {
			tmp = 0;
			
			if((p_leveltype == 0) && (tc[player] >= p_goal * 100))
				tmp = 1;
			if((p_leveltype == 1) && (c_norm[player] >= p_goal * 10))
				tmp = 1;
			if((p_leveltype == 2) && (c_norm[player] >= p_goal * 5))
				tmp = 1;
			
			if(tmp) {
				if(p_leveltype == 0) tc[player] = p_goal * 100;
				if(p_leveltype == 1) c_norm[player] = p_goal * 10;
				if(p_leveltype == 2) c_norm[player] = p_goal * 5;
				
				timeOn[player] = 0;
				ending[player] = 1;
				end_f[player] = 1;
				
				// セクションタイム記録
				now_sttime[(tr[player] / 10) + player * 30] = sectionTimer[player];
				
				// 高速ロール
				if(p_staffroll == 2) {
					if(!IsPlayWave(29)) PlaySE(29);
					ending[player] = 2;
					fastroll[player] = 1;
					ending_timeOn[player] = 1;
				}
			}
		}
		return;
	
	lace:
		// ACEでは150ラインで終了
		if(c_norm[player] >= 150) {
			PlaySE(31);
			c_norm[player] = 150;
			timeOn[player] = 0;
			ending[player] = 1;
			end_f[player] = 2;
			
			// 警告音停止
			pinch[player] = 0;
			StopWave(38);
			
			// リプレイ記録終了
			if(repversw <= 4) onRecord[player] = 0;
			
			// セクションタイム記録
			now_sttime[14 + player * 30] = sectionTimer[player];
		}
		return;
	
	lhep:
		// HEBO+
		if((tc[player] >= 999) && (timeattack[player])) {
			tc[player] = 999;
			timeOn[player] = 0;
			ending[player] = 1;
			end_f[player] = 1;
			
			// セクションタイム記録
			now_sttime[9 + player * 30] = sectionTimer[player];
		}
		return;
	
	ldvm:
		// DEVIL-
		if((tc[player] >= 999) && (timeattack[player])) {
			if(!IsPlayWave(29)) PlaySE(29);
			tc[player] = 999;
			timeOn[player] = 0;
			ending[player] = 2;
			end_f[player] = 1;
			ending_timeOn[player] = 1;
			
			// セクションタイム記録
			now_sttime[9 + player * 30] = sectionTimer[player];
			
			fastroll[player] = 1;	// 高速ロール
		}
		
		// LV500の足切り
		if( (tc[player] >= 500) && (tcbuf < 500) && 
			(gameTimer[player] >= timelimit[0 + player * 2]) && (timelimit[0 + player * 2] > 0) )
		{
			if(!IsPlayWave(29)) PlaySE(29);
			tc[player] = 500;
			timeOn[player] = 0;
			ending[player] = 2;
			
			// BGM切り替え
			if( (bgm >= 2) && (fadelv != 0) ) {
				bgmlv++;
				changeBGM();
			}
			
			ending_timeOn[player] = 1;
			
			// セクションタイム記録
			now_sttime[4 + player * 30] = sectionTimer[player];
			
			fastroll[player] = 1;	// 高速ロール
		}
		return;
	
	// ACE200
	lace200:
		// ACE200では200ラインで終了
		if(c_norm[player] >= 200) {
			c_norm[player] = 200;
			timeOn[player] = 0;
			ending[player] = 1;
			hidden_old[player] = 0;
			
			if(timeattack[player] >= 2) {
				end_f[player] = 1;
			} else {
				end_f[player] = 2;
				
				// リプレイ記録終了
				if(repversw <= 4) onRecord[player] = 0;
			}
			
			// 警告音停止
			pinch[player] = 0;
			StopWave(38);
			
			// セクションタイム記録
			now_sttime[19 + player * 30] = sectionTimer[player];
		}
		return;
	
	// BEGINNER+
	lbegp:
		if((tc[player] >= 300) && (timeattack[player])) {
			if(!IsPlayWave(29)) PlaySE(29);
			tc[player] = 300;
			timeOn[player] = 0;
			ending[player] = 2;
			end_f[player] = 1;
			ending_timeOn[player] = 1;
			
			// スタッフロール用wait値セット
			sp[player] = speed_beginner_roll;
			wait1[player] = wait1_beginner_roll;
			wait2[player] = wait2_beginner_roll;
			wait3[player] = wait3_beginner_roll;
			waitt[player] = waitt_beginner_roll;
			
			if(backno < 3) bgfadesw = 1;
			
			// セクションタイム記録
			now_sttime[2 + player * 30] = sectionTimer[player];
			
			// STメダル獲得
			getSTMedal(player, 2);
			
			// タイムボーナス
			if(gameTimer[player] < 18000) {
				tmp = 1253 * (300 - (gameTimer[player] / 60));
				if(tmp > 0) sc[player] = sc[player] + tmp;
			}
			
			// BGM再生
			if(!onRecord[1 - player]) {
				bgmlv = 1;
				changeBGM();
			}
			
			fastroll[player] = 1;	// 高速ロール
		}
		return;
	
	// FINAL
	lfinal:
		if((tc[player] >= 999) && (timeattack[player])) {
			tc[player] = 999;
			timeOn[player] = 0;
			ending[player] = 1;
			end_f[player] = 1;
			
			// セクションタイム記録
			now_sttime[9 + player * 30] = sectionTimer[player];
		}
		return;
	
	// SIMPLE
	lstd:
		// 40LINES
		if((timeattack[player] == 0) || (timeattack[player] == 2)) {
			if(c_norm[player] >= m_norm[player]) {
				c_norm[player] = m_norm[player];
				timeOn[player] = 0;
				ending[player] = 1;
				
				// 警告音停止
				pinch[player] = 0;
				StopWave(38);
				
				// リプレイ記録終了
				if((timeattack[player] == 0) && (repversw <= 4)) onRecord[player] = 0;
			}
		}
		return;
	
	// MARATHON
	lmar:
		if((c_norm[player] >= m_norm[player]) && (tc[player] >= 14) && (timeattack[player] != 2)) {
			PlaySE(31);
			c_norm[player] = m_norm[player];
			timeOn[player] = 0;
			ending[player] = 1;
			end_f[player] = 2;
			
			// セクションタイム記録
			now_sttime[14 + player * 30] = sectionTimer[player];
			
			// 警告音停止
			pinch[player] = 0;
			StopWave(38);
			
			// リプレイ記録終了
			if(repversw <= 4) onRecord[player] = 0;
		}
		return;
}

// STメダル獲得処理
void getSTMedal(int player, int section) {
	int tmp;
	
	tmp = ST_RankingCheck(player, section);
	
	if(tmp > medal_st[player]) {
		PlaySE(45);
		medal_st[player] = tmp;
		medal_visible_st[player] = 0;
		objectCreate(player, 7, soffset[player] * 8 + 2, 116, 1, 0, 0, medal_st[player]);
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.09 - 対戦モードレベルセレクト
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statSelectLevel(int player) {
	int color, i;
	
	// デフォルト設定を読み込み
	if(!statc[player * 10 + 2]) {
		loadWait(player, p_def_setting);
		statc[player * 10 + 1] = p_def_setting;
		statc[player * 10 + 2] = 1;
	}
	
	color = (count % 4 / 2) * digitc[rots[player]];
	
	// メニュー表示
	printFont(boffset[player],  5, "ROT. RULE", fontc[rots[player]]);
	getRuleName(player);
	printFont(boffset[player],  6, string[0], (statc[player * 10] == 0) * color);
	
	printFont(boffset[player],  8, "GAME SPEED", fontc[rots[player]]);
	sprintf(string[0], "%s%2d", delayname[0 + english * 4], wait1[player]);
	printFont(boffset[player],  9, string[0], (statc[player * 10] == 1) * color);
	sprintf(string[0], "%s%2d", delayname[1 + english * 4], wait2[player]);
	printFont(boffset[player], 10, string[0], (statc[player * 10] == 2) * color);
	sprintf(string[0], "%s%2d", delayname[2 + english * 4], wait3[player]);
	printFont(boffset[player], 11, string[0], (statc[player * 10] == 3) * color);
	sprintf(string[0], "%s%2d", delayname[3 + english * 4], waitt[player]);
	printFont(boffset[player], 12, string[0], (statc[player * 10] == 4) * color);
	sprintf(string[0], "SPEED %4d", sp[player]);
	printFont(boffset[player], 13, string[0], (statc[player * 10] == 5) * color);
	
	printFont(boffset[player], 15, "FAVORITES", fontc[rots[player]]);
	printFont(boffset[player], 16, waitname[statc[player * 10 + 1]], (statc[player * 10] == 6) * color);
	
	printFont(boffset[player], 18, "CPU PLAYER", fontc[rots[player]]);
	
	if(cpu_flag[player] == 0) sprintf(string[0], "CPU    OFF");
	else sprintf(string[0], "CPU     ON");
	printFont(boffset[player], 19, string[0], (statc[player * 10] == 7) * color);
	
	sprintf(string[0], "LEVEL   %2d", cpu_level[player] + 1);
	printFont(boffset[player], 20, string[0], (statc[player * 10] == 8) * color);
	
	printFont(boffset[player], 22, "ATTACK", fontc[rots[player]]);
	
	if(!item_mode[player]) sprintf(string[0], "ITEM   OFF");
	else sprintf(string[0], "ITEM    ON");
	printFont(boffset[player], 23, string[0], (statc[player * 10] == 9) * color);
	
	if(!r_enable[player]) sprintf(string[0], "RISE   OFF");
	else sprintf(string[0], "RISE    ON");
	printFont(boffset[player], 24, string[0], (statc[player * 10] == 10) * color);
	
	padRepeat(player);
	padRepeat2(player);
	
	// ↑
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 0) ) {
		PlaySE(5);
		statc[player * 10]--;
		if(statc[player * 10] < 0) statc[player * 10] = 10;
	}
	
	// ↓
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 1) ) {
		PlaySE(5);
		statc[player * 10]++;
		if(statc[player * 10] > 10) statc[player * 10] = 0;
	}
	
	// ←
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 2) ) {
		PlaySE(3);
		
		// ROT. RULE
		if(statc[player * 10] == 0) {
			changeRule(player, rots[player] - 1);
		}
		// SYUTUGEN
		if(statc[player * 10] == 1) {
			wait1[player]--;
			if(wait1[player] < 0) wait1[player] = 99;
		}
		// SYOUKYO
		if(statc[player * 10] == 2) {
			wait2[player]--;
			if(wait2[player] < 0) wait2[player] = 99;
		}
		// SETTYAKU
		if(statc[player * 10] == 3) {
			wait3[player]--;
			if(wait3[player] < 0) wait3[player] = 99;
		}
		// YOKOTAME
		if(statc[player * 10] == 4) {
			waitt[player]--;
			if(waitt[player] < 0) waitt[player] = 99;
		}
		// SPEED
		if(statc[player * 10] == 5) {
			sp[player]--;
			if(sp[player] < 0) sp[player] = 1200;
		}
		// FAVORITES
		if(statc[player * 10] == 6) {
			i = 0;
			
			do {
				statc[player * 10 + 1]--;
				if(statc[player * 10 + 1] < 0) {
					if(i == 0) {
						statc[player * 10 + 1] = 19;
						i = 1;
					} else {
						statc[player * 10 + 1] = 0;
						break;
					}
				}
			} while(favorites_isempty(statc[player * 10 + 1]));
		}
		// CPU
		if(statc[player * 10] == 7) {
			cpu_flag[player] = !cpu_flag[player];
		}
		// CPU LEVEL
		if(statc[player * 10] == 8) {
			cpu_level[player]--;
			if(cpu_level[player] < 0) cpu_level[player] = 4;
		}
		// ITEM
		if(statc[player * 10] == 9) {
			item_mode[player] = !item_mode[player];
			item_mode[1 - player] = item_mode[player];
		}
		// RISE
		if(statc[player * 10] == 10) {
			r_enable[player] = !r_enable[player];
			r_enable[1 - player] = r_enable[player];
		}
	}
	
	// →
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 3) ) {
		PlaySE(3);
		
		// ROT. RULE
		if(statc[player * 10] == 0) {
			changeRule(player, rots[player] + 1);
		}
		// SYUTUGEN
		if(statc[player * 10] == 1) {
			wait1[player]++;
			if(wait1[player] > 99) wait1[player] = 0;
		}
		// SYOUKYO
		if(statc[player * 10] == 2) {
			wait2[player]++;
			if(wait2[player] > 99) wait2[player] = 0;
		}
		// SETTYAKU
		if(statc[player * 10] == 3) {
			wait3[player]++;
			if(wait3[player] > 99) wait3[player] = 0;
		}
		// YOKOTAME
		if(statc[player * 10] == 4) {
			waitt[player]++;
			if(waitt[player] > 99) waitt[player] = 0;
		}
		// SPEED
		if(statc[player * 10] == 5) {
			sp[player]++;
			if(sp[player] > 1200) sp[player] = 0;
		}
		// FAVORITES
		if(statc[player * 10] == 6) {
			i = 0;
			
			do {
				statc[player * 10 + 1]++;
				if(statc[player * 10 + 1] > 19) {
					if(i == 0) {
						statc[player * 10 + 1] = 0;
						i = 1;
					} else {
						statc[player * 10 + 1] = 0;
						break;
					}
				}
			} while(favorites_isempty(statc[player * 10 + 1]));
		}
		// CPU
		if(statc[player * 10] == 7) {
			cpu_flag[player] = !cpu_flag[player];
		}
		// CPU LEVEL
		if(statc[player * 10] == 8) {
			cpu_level[player]++;
			if(cpu_level[player] > 4) cpu_level[player] = 0;
		}
		// ITEM
		if(statc[player * 10] == 9) {
			item_mode[player] = !item_mode[player];
			item_mode[1 - player] = item_mode[player];
		}
		// RISE
		if(statc[player * 10] == 10) {
			r_enable[player] = !r_enable[player];
			r_enable[1 - player] = r_enable[player];
		}
	}
	
	// ショートカットキーが押されたら対応する設定を読み込み
	for(i = 0; i < 20; i++) {
		if( IsPushKey(waitkey[i]) ) {
			PlaySE(3);
			loadWait(player, i);
		}
	}
	
	// Aボタン
	if( getPushState(player, 4) ) {
		if(statc[player * 10] == 6) {
			// 速度読み込み
			PlaySE(3);
			loadWait(player, statc[player * 10 + 1]);
		} else {
			// ゲームスタート
			PlaySE(10);
			
			// 速度をバックアップ
			b_sp[player]    = sp[player];
			b_wait1[player] = wait1[player];
			b_wait2[player] = wait2[player];
			b_wait3[player] = wait3[player];
			b_waitt[player] = waitt[player];
			
			// CPU設定をバックアップ
			b_cpu_flag[player] = cpu_flag[player];
			b_cpu_level[player] = cpu_level[player];
			
			// アイテム設定をバックアップ
			b_item_mode[player] = item_mode[player];
			b_r_enable[player] = r_enable[player];
			
			stat[player] = 1;					// ブロックシャッター実行
			statc[player * 10] = 0;				// ステータスカウンタを0に
			statc[player * 10 + 1] = 10;		// シャッター後はステータスNo.10
			return;
		}
	}
	
	// Bボタン
	if( getPushState(player, 5) ) {
		PlaySE(5);
		
		leaveVersusMode();
		
		// セレクト画面に戻る
		if(!maxPlay) {
			stat[0] = 2;
			stat[1] = 0;
		} else {
			stat[player] = 2;
			stat[1 - player] = 0;
		}
		return;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.10 - 対戦モード相手決定待ち
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statVersusWait(int player) {
	if(count % 60 > 30) {
		// WAIT
		ExBltRect(49, foffset[player] - 2, 91, 100, 0, 100, 50);
	}

	if((stat[1] == 10) && (player == 0)) {
		bgmlv = 10;
		stat[0] = 3;
		stat[1] = 3;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.11 - ネームエントリー
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statNameEntry(int player) {
	int		move, len;
	
	// PRACTICE専用死亡処理
	if(gameMode[player] == 5) {
		PracticeDeath();
		return;
	}
	
	// リプレイセーブ
	ReplaySaveCheck(player, 4);
	
	if(statc[player * 10 + 4]) {
		sprintf(string[0], "SAVED:  %02d", statc[player * 10 + 4]);
		printFont(boffset[player], 26, string[0], 5);
	}
	
	// 初期化
	if(statc[player * 10 + 1] == 0) {
		// 名前を設定
		if(!user_enable[player]) StrCpy(string[player + 2], "");
		else StrCpy(string[player + 2], user_name[player]);
		
		// 順位を取得
		if(gameMode[player] == 17) {
			statc[player * 10 + 3] = stdRankingCheck(player);
		} else {
			statc[player * 10 + 3] = RankingCheck(player);
		}
		
		// セクションタイム更新をチェック
		statc[player * 10 + 5] = ST_RankingCheckAll(player);
		
		// ランク外
		if((statc[player * 10 + 3] == -1) && (statc[player * 10 + 5] == 0)) {
			// プレイヤーデータ保存
			if(user_enable[player]) user_save(player);
			
			// GAME OVER
			statc[player * 10 + 1] = 0;
			statc[player * 10 + 2] = 0;
			statc[player * 10 + 3] = 0;
			statc[player * 10 + 4] = 0;
			statc[player * 10 + 5] = 0;
			stat[player] = 12;
			return;
		}
		
		// BGM再生
		if((!onRecord[1 - player]) && (bgmlv != 13)) {
			bgmlv = 13;
			changeBGM();
		}
		
		// プレイヤーデータ使用時は表示時間短縮
		if(user_enable[player]) statc[player * 10 + 1] = 35 * 60;
	}
	
	len = StrLen(string[player + 2]);	// 入力済み文字数
	
	// 何位に入ったか表示
	if(statc[player * 10 + 3] != -1) {
		sprintf(string[0], "RANK %d", statc[player * 10 + 3] + 1);
		printFont(boffset[player] + 2, 7, string[0], 5);
	}
	
	// セクションタイム更新
	if(statc[player * 10 + 5]) {
		printFont(boffset[player]    ,  9, "NEW ST", 3);
		printFont(boffset[player] + 1, 10, "RECORD(S)", 3);
	}
	
	if(!user_enable[player]) {
		printFont(boffset[player], 12, "ENTER NAME", 4);

		padRepeat(player);

		// 横移動
		move = getPressState(player, 3) - getPressState(player, 2);
		if(move)
			if((mpc[player] == 1) || (mpc[player] >= 15) || getPressState(player, 6)) {
				if(mpc[player] >= 15) mpc[player] = 12;
				statc[player * 10 + 2] = statc[player * 10 + 2] + move;
				PlaySE(5);
			}

		// 文字のループ
		if(statc[player * 10 + 2] > 54)
			statc[player * 10 + 2] = (len == 3) * 53;
		if(statc[player * 10 + 2] < (len == 3) * 53)
			statc[player * 10 + 2] = 54;

		// 選択している文字と入力済み文字を表示
		MidStr(RankString, statc[player * 10 + 2] + 1, 1, string[4]);
		printFont(boffset[player] + 3 + len, 14, string[4], 2 * (count % 20 > 10));
		printFont(boffset[player] + 3, 14, string[player + 2], 0);

		// 残り時間を表示
		statc[player * 10 + 1]++;
		printFont(boffset[player] + 3, 16, "TIME", 6);
		sprintf(string[0], "%2d", 45 - (statc[player * 10 + 1] / 60));
		printFont(boffset[player] + 4, 17, string[0], 0);

		// Bボタンで1文字削除
		if(getPushState(player, 5)) {
			if(len) {
				PlaySE(5);
				MidStr(string[player + 2], 1, len - 1, string[player + 2]);
			}
		}

		// Aボタンで入力
		if(getPushState(player, 4)) {
			PlaySE(10);
			
			if(statc[player * 10 + 2] == 53) {
				// RB
				if(len) {
					MidStr(string[player + 2], 1, len - 1, string[player + 2]);
				}
			} else if(statc[player * 10 + 2] == 54) {
				// ED
				PlaySE(18);
				statc[player * 10 + 1] = 45 * 60;
			} else {
				// 文字入力
				StrCat(string[player + 2], string[4]);
			}
		}
	} else {
		printFont(boffset[player] + 2, 12, "PLAYER", 4);
		printFont(boffset[player] + 3, 14, string[player + 2], 0);
		
		statc[player * 10 + 1]++;
		
		if(getPushState(player, 4)) {
			statc[player * 10 + 1] = 45 * 60;
		}
	}
	
	// ネームエントリー終了
	if(statc[player * 10 + 1] >= 45 * 60) {
		// 名前が入力されていない場合はNOPとして登録
		if(!len) StrCpy(string[player + 2], "NOP");
		
		// 名前の後ろにスペースを挿入（名前が1～2文字しかない場合、余った個所をスペースにする）
		sprintf(string[player + 2], "%s   ", string[player + 2]);
		
		// 左から4文字目以降を削除
		LeftStr(string[player + 2], 3, string[player + 2]);
		
		// ランキングに登録＆保存
		if(statc[player * 10 + 3] != -1) {
			if(gameMode[player] == 17) {
				stdRankingRegist(player, statc[player * 10 + 3], string[player + 2]);
				stdRankingSave();
			} else {
				RankingRegist(player, statc[player * 10 + 3], string[player + 2]);
				RankingSave();
			}
		}
		
		// セクションタイムランキングに登録＆保存
		if(statc[player * 10 + 5]) {
			ST_RankingUpdate(player, string[player + 2]);
			ST_RankingSave();
		}
		
		// プレイヤーデータ保存
		if(user_enable[player]) user_save(player);
		
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = 0;
		statc[player * 10 + 3] = 0;
		statc[player * 10 + 4] = 0;
		stat[player] = 12;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.12 - 結果表示
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statResult(int player) {
	int i, tmp;
	
	// BGM再生
	if((!onRecord[1 - player]) && (bgmlv != 13) && (statc[player * 10 + 1] == 0)) {
		bgmlv = 13;
		changeBGM();
	}
	
	// リプレイセーブ
	ReplaySaveCheck(player, 3);
	
	if(statc[player * 10 + 3]) {
		sprintf(string[0], "SAVED:  %02d", statc[player * 10 + 3]);
		printFont(boffset[player], 26, string[0], 5);
	}
	
	statc[player * 10 + 1]++;
	
	printFont(boffset[player], 6, "PLAY DATA", 4);
	
	if(gameMode[player] == 4) {
		// VERSUSモード
		if(!vs_goal_type) {
			// LEVEL
			printFont(boffset[player], 8, "LEVEL", fontc[rots[player]]);
			sprintf(string[0], "%4d", tc[player]);
			printFont(boffset[player] + 6, 9, string[0], 0);
		} else {
			// NORM
			printFont(boffset[player], 8, "NORM", fontc[rots[player]]);
			sprintf(string[0], "%4d", c_norm[player]);
			printFont(boffset[player] + 6, 9, string[0], 0);
		}
		
		// TIME
		printFont(boffset[player], 11, "TIME", fontc[rots[player]]);
		getTime(gameTimer[player]);
		printFont(boffset[player] + 2, 12, string[0], 0);
	} else if(gameMode[player] == 6) {
		// TOMOYOモード
		// STAGE
		printFont(boffset[player], 8, "STAGE", fontc[rots[player]]);
		getTomoyoStageNo(stage[player], 0, 2);
		printFont(boffset[player] + 7, 9, string[0], 0);
		
		// CLEAR
		if(stage[player] <= 26) {
			printFont(boffset[player], 11, "CLEAR", fontc[rots[player]]);
			sprintf(string[0], "%3d%%", clearp[player]);
			printFont(boffset[player] + 6, 12, string[0], 0);
		}
		
		// TIME
		printFont(boffset[player], 14, "TIME", fontc[rots[player]]);
		getTime(gameTimer[player]);
		printFont(boffset[player] + 2, 15, string[0], 0);
	} else if(isAceMode(player)) {
		// ACEモード
		// LINES
		printFont(boffset[player], 8, "LINES", fontc[rots[player]]);
		sprintf(string[0], "%3d", c_norm[player]);
		printFont(boffset[player] + 7, 9, string[0], 0);
		
		// LEVEL
		printFont(boffset[player], 11, "LEVEL", fontc[rots[player]]);
		sprintf(string[0], "%4d", tc[player] + 1);
		printFont(boffset[player] + 6, 12, string[0], 0);
		
		// TIME
		printFont(boffset[player], 14, "TIME", fontc[rots[player]]);
		getTime(gameTimer[player]);
		printFont(boffset[player] + 2, 15, string[0], 0);
	} else if(gameMode[player] == 8) {
		// MISSIONモード
		// MISSION
		printFont(boffset[player], 8, "MISSION", fontc[rots[player]]);
		sprintf(string[0], "%3d", c_mission + 1);
		printFont(boffset[player] + 7, 9, string[0], 0);
		
		// TIME
		printFont(boffset[player], 11, "TIME", fontc[rots[player]]);
		getTime(gameTimer[player]);
		printFont(boffset[player] + 2, 12, string[0], 0);
	} else if(gameMode[player] == 15) {
		// TOMOYO-FLASHモード
		// SCORE
		printFont(boffset[player], 8, "SCORE", fontc[rots[player]]);
		sprintf(string[0], "%7d", sc[player]);
		printFont(boffset[player] + 3, 9, string[0], 0);
		
		// STAGE
		printFont(boffset[player], 11, "STAGE", fontc[rots[player]]);
		sprintf(string[0], "%3d", stage[player] + 1);
		printFont(boffset[player] + 7, 12, string[0], 0);
		
		// TIME
		printFont(boffset[player], 14, "TIME", fontc[rots[player]]);
		getTime(gameTimer[player]);
		printFont(boffset[player] + 2, 15, string[0], 0);
	} else if(gameMode[player] == 17) {
		// SIMPLEモード
		if(timeattack[player] >= 2) {
			tmp = 0;
			
			for(i = 0; i < 3; i++) {
				sprintf(string[0], "TRY %d:", i + 1);
				printFont(boffset[player], 8 + i * 3, string[0], fontc[rots[player]]);
				
				if(timeattack[player] == 2) {
					getTime(rot_relay_record[i + player * 3]);
				} else {
					sprintf(string[0], "%d", rot_relay_record[i + player * 3]);
				}
				tmp = tmp + rot_relay_record[i + player * 3];
				printFont(boffset[player] + 2, 9 + i * 3, string[0], 0);
			}
			
			printFont(boffset[player], 17, "TOTAL:", fontc[rots[player]]);
			if(timeattack[player] == 2) {
				getTime(tmp);
			} else {
				sprintf(string[0], "%d", tmp);
			}
			printFont(boffset[player] + 2, 18, string[0], 0);
		} else {
			printFont(boffset[player], 8 + timeattack[player] * 3, "LINES", fontc[rots[player]]);
			sprintf(string[0], "%3d", c_norm[player]);
			printFont(boffset[player] + 7, 9 + timeattack[player] * 3, string[0], 0);
			
			printFont(boffset[player], 11 - timeattack[player] * 3, "SCORE", fontc[rots[player]]);
			sprintf(string[0], "%7d", sc[player]);
			printFont(boffset[player] + 3, 12 - timeattack[player] * 3, string[0], 0);
			
			// TIME
			printFont(boffset[player], 14, "TIME", fontc[rots[player]]);
			getTime(gameTimer[player]);
			printFont(boffset[player] + 2, 15, string[0], 0);
		}
	} else if(gameMode[player] == 18) {
		// MARATHONモード
		// SCORE
		printFont(boffset[player], 8, "SCORE", fontc[rots[player]]);
		sprintf(string[0], "%7d", sc[player]);
		printFont(boffset[player] + 3, 9, string[0], 0);
		
		if(timeattack[player] == 1) {
			// SQUARE
			printFont(boffset[player], 11, "SQUARE", fontc[rots[player]]);
			sprintf(string[0], "%3d", squarenum[player]);
			printFont(boffset[player] + 7, 12, string[0], 0);
		} else {
			// LINES
			printFont(boffset[player], 11, "LINES", fontc[rots[player]]);
			sprintf(string[0], "%3d", li[player]);
			printFont(boffset[player] + 7, 12, string[0], 0);
		}
		
		// TIME
		printFont(boffset[player], 14, "TIME", fontc[rots[player]]);
		getTime(gameTimer[player]);
		printFont(boffset[player] + 2, 15, string[0], 0);
	} else if((gameMode[player] == 1) || (gameMode[player] == 2) || (gameMode[player] == 3) || (gameMode[player] == 16)) {
		// MASTER & 20G & DEVIL-DOOM & DEVIL-HARD
		// SCORE
		printFont(boffset[player], 8, "SCORE", fontc[rots[player]]);
		sprintf(string[0], "%7d", sc[player]);
		printFont(boffset[player] + 3, 9, string[0], 0);
		
		// LEVEL
		printFont(boffset[player], 11, "LEVEL", fontc[rots[player]]);
		sprintf(string[0], "%4d", tc[player]);
		printFont(boffset[player] + 6, 12, string[0], 0);
		
		// GRADE
		printFont(boffset[player], 14, "GRADE", fontc[rots[player]]);
		
		if(gameMode[player] == 3)
			getGradeString(grade[player], 2, 1);
		else if(gameMode[player] == 16)
			getGradeString(grade[player], 1, 1);
		else if(gradetype[player] == 2)
			getGradeString(grade[player], 3, 1);
		else
			getGradeString(grade[player], 0, 1);
		
		sprintf(string[0], "%3s", string[1]);
		printFont(boffset[player] + 7, 15, string[0], 0);
		
		// TIME
		printFont(boffset[player], 17, "TIME", fontc[rots[player]]);
		getTime(gameTimer[player]);
		printFont(boffset[player] + 2, 18, string[0], 0);
	} else {
		// それ以外のモード
		// SCORE
		printFont(boffset[player], 8, "SCORE", fontc[rots[player]]);
		sprintf(string[0], "%7d", sc[player]);
		printFont(boffset[player] + 3, 9, string[0], 0);
		
		// LEVEL
		printFont(boffset[player], 11, "LEVEL", fontc[rots[player]]);
		sprintf(string[0], "%4d", tc[player]);
		printFont(boffset[player] + 6, 12, string[0], 0);
		
		// TIME
		printFont(boffset[player], 14, "TIME", fontc[rots[player]]);
		getTime(gameTimer[player]);
		printFont(boffset[player] + 2, 15, string[0], 0);
	}
	
	// S-GRADE
	if(statc[player * 10 + 1] == 1) {
		statc[player * 10 + 2] = checkSecretGrade(player);
	}
	if(statc[player * 10 + 2] >= min_sgrade) {
		printFont(boffset[player], 23, "S-GRADE", fontc[rots[player]]);
		getGradeString(statc[player * 10 + 2], 3, 1);
		sprintf(string[0], "%2s", string[1]);
		printFont(boffset[player] + 8, 24, string[0], 0);
	}

	// ボタンでスキップ
	if(getPushState(player, 4)) {
		statc[player * 10 + 1] = 500;
	}

	// 終了
	if(statc[player * 10 + 1] >= 500) {
		if(gameMode[player] == 4) {
			// VERSUSモードではリプレイセーブ画面へ
			StopAllBGM();
			
			if((replayauto) && (replayno != 41)) {
				flag = 1;
			} else {
				for(i = 0; i < 2; i++) stat[i] = 24;
				for(i = 0; i < 20; i++) statc[i] = 0;
			}
		} else {
			if( ((gameMode[player] == 6) || (gameMode[player] == 15)) && (!ending[player]) && (!playback) )
				stat[player] = 19;	// TOMOYOモードではコンティニュー画面へ
			else
				stat[player] = 13;
			
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ステータスNo.13 - ゲームオーバー表示
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statGameOver2(int player) {
	int i;
	
	// リプレイセーブ
	ReplaySaveCheck(player, 3);
	
	if(statc[player * 10 + 3]) {
		sprintf(string[0], "SAVED:  %02d", statc[player * 10 + 3]);
		printFont(boffset[player], 26, string[0], 5);
	}
	
	// カウンタ増加
	statc[player * 10]++;
	
	if(statc[player * 10] == 1) {
		// ゲームオーバー音
		PlaySE(8);
		
		// 全BGM停止
		if(!onRecord[1 - player]) StopAllBGM();
	}
	
	// GAME OVER
	ExBltRect(49, foffset[player] - 2, 95, 0, 0, 100, 50);
	
	// ボタンでスキップ
	if(getPushState(player, 4)) {
		statc[player * 10] = 480;
	}
	
	// 終了
	if(statc[player * 10] >= 480) {
		// 次の画面
		if( ((!replayauto) || (replayno == 41)) && (!demo) && (show_endmenu) ) stat[player] = 24;
		else stat[player] = 0;
		
		for(i=0; i<10; i++) statc[player * 10 + i] = 0;
		
		if(!show_endmenu) {
			if(!onRecord[1 - player]) {
				backno = 0;
				back_acnt = 0;
			}
			
			// MISSIONモード用
			if( (gameMode[0] == 8) && (player == 0) && (!playback) ) {
				playerInitial(0);
				stat[0] = 1;
				statc[0 * 10] = 0;
				statc[0 * 10 + 1] = 22;
			}
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ステータスNo.14 - エンディング・ロール
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statEnding(int player) {
	int i, j, k;
	
	if(onRecord[player]) {
		// 横溜め
		if(repversw >= 7) padRepeat(player);
		
		// 新IRS
		if(ace_irs) doNewIRS(player, 0);
		
		// HYPER横先行移動
		if(fastlrmove == 3) HyperLRMove(player);
	}
	
	jump(ending[player] - 1, lerase, lstart, lclear, lerase, lretry);
	
	/*
	switch(ending[player]) {
		case 1: goto lerase;
		case 2: goto lstart;
		case 3: goto lclear;
		case 4: goto lerase;
		case 5: goto lretry;
	}
	*/
	
	// エンディング1＆4 ブロック消滅
	lerase:
		if(statc[player * 10] == 0) {
			// BGM停止
			if(!onRecord[1 - player]) StopAllBGM();
			
			// 警告音停止
			pinch[player] = 0;
			StopWave(38);
			
			statc[player * 10 + 1] = 0;
			if(ending[player] == 4) statc[player * 10 + 1] = checkFieldTop(player) * 6;
		}
		
		// ブロックを消す
		if(statc[player * 10 + 1] % 6 == 0) {
			if(ending[player] == 4) {
				j = statc[player * 10 + 1] / 6;
			} else {
				j = 22 - statc[player * 10 + 1] / 6;
			}
			
			if((j >= 0) && (j < 22)) {
				for(i = 0; i < 10; i++) {
					if(fld[i + j * 10 + player * 220]) {
						if(fldo[i + j * 10 + player * 220] == 0) {
							objectCreate(player, 1, (i + boffset[player]) * 8, (j + 3) * 8, (i - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + 1 * 250, fld[i + j * 10 + player * 220] - 1, 100);
						}
						fld[i + j * 10 + player * 220] = 0;
						fldt[i + j * 10 + player * 220] = 0;
						fldi[i + j * 10 + player * 220] = 0;
						fldo[i + j * 10 + player * 220] = 0;
						flds[i + j * 10 + player * 220] = 0;
					}
				}
			}
		}
		
		// アニメ終了
		if(statc[player * 10] == 129) {
			if(gameMode[player] == 5) {
				// PRACTICE
				if(!p_staffroll) {
					// 即EXCELLENT
					ending[player] = 3;
				} else {
					// スタッフロール
					ending[player] = 2;
					
					// BGM再生
					if(!onRecord[1 - player]) {
						bgmlv = 6;
						changeBGM();
					}
				}
			} else if(gameMode[player] == 6) {
				// TOMOYO
				if(stage[player] == 44) {
					// EHeartではスタッフロール
					ending[player] = 2;
					
					// BGM再生
					if(!onRecord[1 - player]) {
						bgmlv = 6;
						changeBGM();
					}
				} else {
					// 即EXCELLENT画面
					ending[player] = 3;
				}
			} else if(gameMode[player] == 7) {
				// ACE
				ending[player] = 3;
			} else if(gameMode[player] == 8) {
				// MISSIONモード
				if((mission_end[c_mission] >= 4) && (mission_end[c_mission] <= 9)) {
					// スタッフロール開始
					ending[player] = 2;
					
					// BGM再生
					bgmlv = 6;
					changeBGM();
				} else if((mission_end[c_mission] == 2) || (mission_end[c_mission] == 3)) {
					// 足切り
					ending[player] = 5;
				} else {
					// 通常
					ending[player] = 3;
				}
			} else if(gameMode[player] == 12) {
				// ACE200
				if(timeattack[player] >= 2) {
					ending[player] = 2;
					hidden[player] = 2;
					
					// BGM再生
					if(!onRecord[1 - player]) {
						bgmlv = 6;
						changeBGM();
					}
				} else {
					ending[player] = 3;
				}
			} else if(gameMode[player] == 17) {
				// SIMPLE
				if(timeattack[player] >= 2) {
					// ROT. RELAY
					if(timeattack[player] == 2) {
						rot_relay_record[tc[player] + player * 3] = gameTimer[player];
						gameTimer[player] = 0;
					} else {
						rot_relay_record[tc[player] + player * 3] = sc[player];
						sc[player] = 0;
					}
					
					if(tc[player] >= 2) {
						ending[player] = 3;
						onRecord[player] = 0;
						
						for(i = 0; i < 3; i++) {
							if(timeattack[player] == 2) {
								gameTimer[player] = gameTimer[player] + rot_relay_record[i + player * 3];
							} else {
								sc[player] = sc[player] + rot_relay_record[i + player * 3];
							}
						}
					} else {
						ending[player] = 0;
						tc[player]++;
						bgfadesw = 1;
						hold[player] = -1;
						dhold[player] = 0;
						
						if(timeattack[player] == 2) {
							c_norm[player] = 0;
						} else {
							ltime[player] = 7200;
						}
						
						stat[player] = 42;
					}
				} else {
					// 通常
					ending[player] = 3;
				}
			} else if(gameMode[player] == 18) {
				// MARATHON
				ending[player] = 3;
			} else if(ending[player] == 1) {
				// スタッフロール開始
				ending[player] = 2;
				
				// MASTERと20Gではフィールドタイマー発動
				if( (gameMode[player] == 1) || (gameMode[player] == 2) ) {
					if(gmflag_r[player]) {
						// 消えロール
						hidden[player] = 2;
					} else {
						// 見えロール
						hidden[player] = 1;
						
						// HARDで好成績の場合は見える時間半減
						if((gradetype[player] == 1) && (grade[player] >= 23))
							shadowtime[player] = 150;
					}
				}
				
				// DEVILでは強制BIG #LITE11
				if((gameMode[player] == 3) || (gameMode[player] == 16)) {
					IsBig[player] = 1;
					BigMove[player] = 1;
					n_bx[player] = 2;
				}
				
				// FINALでは消えロール
				if(gameMode[player] == 14) {
					hidden[player] = 2;
				}
				
				// FLASHではエンディング用ステージ読み込み
				if(gameMode[player] == 15) {
					loadTomoyoStage(player, 100, 1 + flash_edit[player]);
				}
				
				// BGM再生
				if(!onRecord[1 - player]) {
					bgmlv = 6 + (gameMode[player] == 0);
					changeBGM();
				}
			} else {
				// 足切り
				ending[player] = 5;
			}
			statc[player * 10] = 0;
			statc[player * 10 + 1] = 0;
		} else {
			statc[player * 10]++;
			statc[player * 10 + 1]++;
		}
		return;
	
	// エンディング2 スタッフロール開始
	lstart:
		ending_timeOn[player] = 1;
		stat[player] = 6;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		return;
	
	// エンディング3 EXCELLENT画面
	lclear:
		statc[player * 10]++;
		onRecord[player] = 0;
		
		// リプレイセーブ
		ReplaySaveCheck(player, 1);
		
		if(statc[player * 10 + 1]) {
			sprintf(string[0], "SAVED:  %02d", statc[player * 10 + 1]);
			printFont(boffset[player], 26, string[0], 5);
		}
		
		// 花火
		if( (statc[player * 10] % 10 == 0) && (endingcnt[player] < 30) ) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], 16 + Rand(20), 0, 0, Rand(7), 0);
			endingcnt[player]++;
		}
		
		// フィールド位置を戻す
		fmirror_cnt[player] = -20;
		ofs_x[player] = 0;
		ofs_y[player] = 0;
		
		if((gameMode[player] == 8) && (mission_clear_anim == 0)) {
			// CLEAR!!
			ExBltRect(3, foffset[player] - 7, 96, 195, 230, 109, 20);
			
			if((gameMode[player] == 8) && (!statc[player * 10 + 2])) {
				PlaySE(7);	// missionclr.wav
				statc[player * 10 + 2] = 1;
			}
		} else if( (((gameMode[player] == 1) || (gameMode[player] == 2)) && (grade[player] >= 32)) || 
		           (((gameMode[player] == 1) || (gameMode[player] == 2)) && (gradetype[player] == 2)) || 
		           ((gameMode[player] == 8) && (mission_clear_anim == 1)) || 
		           ((gameMode[player] == 12) && (timeattack[player] == 2)) || 
		           ((gameMode[player] == 16) && (grade[player] >= 14)) )
		{
			// YOU ARE GRAND MASTER!!
			if(statc[player * 10] < 64) {
				k = 128 - statc[player * 10];
				i = (80 * k / 64 - 80) / 2;
				j = (36 * k / 64 - 36) / 2;
				k = 65536 * k / 64;
				ExBltRectR(3, foffset[player] + 8 - i, 102 - j, 208, 126, 80, 36, k, k);
			} else {
				ExBltRect(3, foffset[player] + 8, 102, 208, 126, 80, 36);
			}
		} else if( ((gameMode[player] == 3) && (grade[player] >= 14)) || 
		           ((gameMode[player] == 8) && (mission_clear_anim == 2)) || 
		           ((gameMode[player] == 12) && (timeattack[player] == 3)) || 
		           (gameMode[player] == 14) )
		{
			// YOU ARE GOD
			if(statc[player * 10] < 64) {
				k = 128 - statc[player * 10];
				i = (112 * k / 64 - 112) / 2;
				j = (66 * k / 64 - 66) / 2;
				k = 65536 * k / 64;
				ExBltRectR(3, foffset[player] - 7 - i, 70 - j, 191, 163, 112, 66, k, k);
			} else {
				ExBltRect(3, foffset[player] - 7, 70, 191, 163, 112, 66);
			}
		} else if(gameMode[player] == 15) {
			// FLASHモード
			printFont(boffset[player] - 3, 10, "CONGRATULATIONS!", 7);
			
			printFont(boffset[player] + 2, 13, "GIVE UP", 2);
			printFont(boffset[player] + 2, 16, "YOU ARE", 2);
			printFont(boffset[player] + 3, 18, "CHAMP!", 2);
			
			printFont(boffset[player], 20, "SPECIAL", 3);
			printFont(boffset[player] + 5, 21, "BONUS", 3);
			
			sprintf(string[0], "%d PTS", 100000 + ltime[player]);
			printFont(boffset[player], 23, string[0], 3);
		} else if(gameMode[player] == 17) {
			// SIMPLEモード
			if(timeattack[player] >= 2) {
				rots[player] = start_rots[player];
				setNextBlockColors(player, 1);
			}
			statc[player * 10] = 600;
		} else {
			// EXCELLENT
			if(statc[player * 10] <= 5){
				k = 10 - statc[player * 10];
				i = (75 * k / 5 - 75) / 2;
				j = (9 * k / 5 - 9) / 2;
				k = 65536 * k / 5;
				ExBltRectR(3, foffset[player] + 10 - i, 96 - j, 212, 73, 75, 9, k, k);
			} else {
				ExBltRect(3, foffset[player] + 10, 96, 212, 73, 75, 9);
			}
			
			if(gameMode[player] != 8) {
				getModeName(player);
				printFont(boffset[player], 14, string[0], 0);
				printFont(boffset[player] + 6, 15, "MODE", 0);
				printFont(boffset[player], 16, "ALL CLEAR", 0);
			}
		}
		
		if(statc[player * 10] >= 600) {
			if(!onRecord[1 - player]) StopAllBGM();
			stat[player] = 7;
			statc[player * 10] = 0;
			statc[player * 10 + 1] = 0;
			statc[player * 10 + 2] = 0;
		}
		return;
	
	// エンディング5 足切り
	lretry:
		statc[player * 10]++;
		onRecord[player] = 0;
		
		// リプレイセーブ
		ReplaySaveCheck(player, 1);
		
		if(statc[player * 10 + 1]) {
			sprintf(string[0], "SAVED:  %02d", statc[player * 10 + 1]);
			printFont(boffset[player], 26, string[0], 5);
		}
		
		// フィールド位置を戻す
		fmirror_cnt[player] = -20;
		ofs_x[player] = 0;
		ofs_y[player] = 0;
		
		if(gameMode[player] == 8) {
			// CLEAR
			ExBltRect(3, foffset[player] - 7, 96, 195, 250, 109, 20);
		} else {
			// EXCELLENT
			if(statc[player * 10] <= 5){
				k = 10 - statc[player * 10];
				i = (75 * k / 5 - 75) / 2;
				j = (9 * k / 5 - 9) / 2;
				k = 65536 * k / 5;
				ExBltRectR(3, foffset[player] + 10 - i, 96 - j, 212, 73, 75, 9, k, k);
			} else {
				ExBltRect(3, foffset[player] + 10, 96, 212, 73, 75, 9);
			}
		}
		
		if(statc[player * 10] < 220) {
			// 花火
			if((statc[player * 10] % 40 == 0) && (endingcnt[player] < 4)) {
				objectCreate(player, 3, -40 + Rand(80) + foffset[player], 16 + Rand(20), 0, 0, Rand(7), 0);
				endingcnt[player]++;
			}
			
			// ボタンでスキップ
			if(getPushState(player, 4)) {
				statc[player * 10] = 220;
			}
		} else {
			if((statc[player * 10] == 220) || (statc[player * 10] == 221))
				objectClearPl(player);	// 花火を消す
			
			if(gameMode[player] == 8) {
				printFont(boffset[player] + 1, 15, "BUT...", 0);
				printFont(boffset[player] + 1, 16, "LAST", 0);
				printFont(boffset[player] + 1, 17, "ERASE", 0);
				printFont(boffset[player] + 1, 18, "2 LINES", 0);
			} else if( ((gameMode[player] == 1) || (gameMode[player] == 2)) && (gradetype[player] == 2) ) {
				printFont(boffset[player] + 1, 15, "TRY AGAIN", 0);
				printFont(boffset[player] + 2, 16, "TO BE A", 0);
				printFont(boffset[player] - 1, 17, "GRAND MASTER", 0);
			} else {
				printFont(boffset[player] + 1, 14, "BUT...", 0);
				printFont(boffset[player] + 1, 15, "LET'S GO", 0);
				printFont(boffset[player] + 1, 16, "BETTER", 0);
				printFont(boffset[player] + 1, 17, "NEXT TIME", 0);
			}
			
			// ボタンでスキップ
			if(getPushState(player, 4)) {
				statc[player * 10] = 600;
			}
			
			if(statc[player * 10] >= 600) {
				if(!onRecord[1 - player]) StopAllBGM();
				stat[player] = 7;
				statc[player * 10] = 0;
				statc[player * 10 + 1] = 0;
			}
		}
		return;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ステータスNo.15 - せりあがり
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// statc[0 + player * 10]：終了後に移動するステータス
// statc[1 + player * 10]：最初のフレームかどうか
void statRiseLine(int player) {
	if((repversw >= 7) && (!statc[1 + player * 10])) {
		// 横溜め
		padRepeat(player);
		
		// 新IRS
		if(ace_irs) doNewIRS(player, 0);
		
		// HYPER横先行移動
		if(fastlrmove == 3) HyperLRMove(player);
	}
	
	statc[1 + player * 10] = 0;
	
	if(upLines[player] <= 0) {
		stat[player] = statc[0 + player * 10];
		statc[0 + player * 10] = 0;
	} else {
		UpLineBlockJudge(player);
		pinchCheck(player);
		
		if(upLines[player] <= 0) {
			stat[player] = statc[0 + player * 10];
			statc[0 + player * 10] = 0;
		} else {
			stat[player] = 15;
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ステータスNo.17 - フィールドエディタ
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// statc[0 + player * 10]：Bボタンを押したときに戻るステータス
// statc[1 + player * 10]：選択しているブロック
// statc[2 + player * 10]：配置不可フラグ（画面が切り替わった瞬間いきなりブロックを置いてしまうのを防ぐ）
// statc[3 + player * 10]：カーソルX座標
// statc[4 + player * 10]：カーソルY座標
void statFieldEditor(int player) {
	int i;
	int bx1, by1;
	
	padRepeat(player);
	padRepeat2(player);
	
	// カーソル枠描画
	if(count % 16 < 8)
		ExBltFastRect(30, (statc[3 + player * 10] + boffset[player]) * 8 - 1, (statc[4 + player * 10] + 3) * 8 - 1, 20, 0, 10, 10);
	else
		ExBltFastRect(30, (statc[3 + player * 10] + boffset[player]) * 8 - 1, (statc[4 + player * 10] + 3) * 8 - 1, 10, 0, 10, 10);
	
	// カーソルブロック描画
	drawSingleBlock(player, (statc[3 + player * 10] + boffset[player]) * 8, (statc[4 + player * 10] + 3) * 8,
					0, statc[1 + player * 10], 0, 0, 0, 0, 0);
	
	// ↑
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 0) ) {
		PlaySE(5);
		statc[4 + player * 10]--;
		if(statc[4 + player * 10] < 1 + tomoyo_rise_edit[player]) statc[4 + player * 10] = 21;
	}
	
	// ↓
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 1) ) {
		PlaySE(5);
		statc[4 + player * 10]++;
		if(statc[4 + player * 10] > 21) statc[4 + player * 10] = 1 + tomoyo_rise_edit[player];
	}
	
	// ←
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) )
	if( getPressState(player, 2) ) {
		PlaySE(5);
		
		if( getPressState(player, 6) ) {
			// 選択ブロック変更
			statc[1 + player * 10]--;
			if(statc[1 + player * 10] < 0) statc[1 + player * 10] = 16;
		} else {
			// 移動
			statc[3 + player * 10]--;
			if(statc[3 + player * 10] < 0) statc[3 + player * 10] = 9;
		}
	}
	
	// →
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) )
	if( getPressState(player, 3) ) {
		PlaySE(5);
		
		if( getPressState(player, 6) ) {
			// 選択ブロック変更
			statc[1 + player * 10]++;
			if(statc[1 + player * 10] > 16) statc[1 + player * 10] = 0;
		} else {
			// 移動
			statc[3 + player * 10]++;
			if(statc[3 + player * 10] > 9) statc[3 + player * 10] = 0;
		}
	}
	
	bx1 = statc[3 + player * 10];
	by1 = statc[4 + player * 10];
	
	// フィールドエディット
	if(!tomoyo_rise_edit[player]) {
		// Aボタン
		if( getPressState(player, 4) && !statc[2 + player * 10] ) {
			if( fld[bx1 + by1 * 10 + player * 220] != statc[1 + player * 10] + 1) {
				PlaySE(3);
				fld[bx1 + by1 * 10 + player * 220] = statc[1 + player * 10] + 1;
				fldt[bx1 + by1 * 10 + player * 220] = -1;
				fldi[bx1 + by1 * 10 + player * 220] = 0;
				fldo[bx1 + by1 * 10 + player * 220] = 0;
				flds[bx1 + by1 * 10 + player * 220] = 0;
			}
		}
		
		// HOLDボタン
		if( getPressState(player, 7) && !statc[2 + player * 10] ) {
			if( fld[bx1 + by1 * 10 + player * 220] != 0 ) {
				PlaySE(3);
				fld[bx1 + by1 * 10 + player * 220] = 0;
				fldt[bx1 + by1 * 10 + player * 220] = 0;
				fldi[bx1 + by1 * 10 + player * 220] = 0;
				fldo[bx1 + by1 * 10 + player * 220] = 0;
				flds[bx1 + by1 * 10 + player * 220] = 0;
			}
		}
	}
	
	// せり上がりエディット
	if(tomoyo_rise_edit[player]) {
		// Aボタン
		if( getPressState(player, 4) && !statc[2 + player * 10] ) {
			if( tomoyo_rise_fld[bx1 + (by1 - 2) * 10 + player * 200] != statc[1 + player * 10] + 1) {
				PlaySE(3);
				tomoyo_rise_fld[bx1 + (by1 - 2) * 10 + player * 200] = statc[1 + player * 10] + 1;
			}
		}
		
		// HOLDボタン
		if( getPressState(player, 7) && !statc[2 + player * 10] ) {
			if( tomoyo_rise_fld[bx1 + (by1 - 2) * 10 + player * 200] != 0 ) {
				PlaySE(3);
				tomoyo_rise_fld[bx1 + (by1 - 2) * 10 + player * 200] = 0;
			}
		}
	}
	
	// 配置不可フラグ解除
	if( !getPressState(player, 4) && !getPressState(player, 7) ) {
		statc[2 + player * 10] = 0;
	}
	
	// Bボタン
	if( getPushState(player, 5) ) {
		stat[player] = statc[0 + player * 10];
		for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		tomoyo_rise_edit[player] = 0;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ステータスNo.24 - リプレイ保存画面
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statReplaySave(int player) {
	int i, color;
	
	color = (count % 4 / 2) * digitc[rots[player]];
	
	if(!statc[player * 10 + 2]) {
		// 自動セーブ
		if((replay_autosave) && (time2[player] <= 72000) && (!replayauto) && (replayno != 41)) {
			if(gameMode[player] == 4) {
				if(player == 0) {
					saveReplayData(0, 41);
					saveReplayData(1, 41);
				}
			} else {
				saveReplayData(player, 41);
			}
		}
		
		if((replayno == 41) && (playback)) {
			fast = 0;
			replayauto = 0;
		}
		
		// リプレイの存在を調べる
		checkReplayExist();
		
		statc[player * 10 + 2] = 1;
	}
	
	// カーソル
	printFont(boffset[player] + 1, 12 + statc[player * 10] * 2, "b", color);
	
	// メニュー
	sprintf(string[0], "SAVE %d", statc[player * 10 + 1] + 1);
	printFont(boffset[player] + 2, 12, string[0], (statc[player * 10] == 0) * (time2[player] <= 72000) * color);
	
	if(enable[statc[player * 10 + 1]] != 0) {
		printFont(boffset[player] + 4, 13, "(USED)", (statc[player * 10] == 0) * (time2[player] <= 72000) * color);
	}
	
	if(!playback) printFont(boffset[player] + 2, 14, "RETRY", (statc[player * 10] == 1) * color);
	
	printFont(boffset[player] + 2, 16, "END", (statc[player * 10] == 2) * color);
	
	if(enable[statc[player * 10 + 1]] != 0) {
		sprintf(string[0], "REPLAY %d", statc[player * 10 + 1] + 1);
		printFont(boffset[player], 20, string[0], fontc[rots[player]]);
		
		getModeNameEx(replay_gamemode[statc[player * 10 + 1]], 0);
		printFont(boffset[player] + 1, 21, string[0], modecolor[replay_gamemode[statc[player * 10 + 1]]]);
		
		getRuleNameEx(replay_rots[statc[player * 10 + 1]], 0);
		printFont(boffset[player] + 1, 22, string[0], fontc[replay_rots[statc[player * 10 + 1]]]);
		
		getTimeEx(replay_time[statc[player * 10 + 1]], 0, 0);
		printFont(boffset[player] + 1, 23, string[0], 0);
	}
	
	// キー入力
	padRepeat(player);
	padRepeat2(player);
	
	// ↑
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 0) ) {
		PlaySE(5);
		statc[player * 10]--;
		if((statc[player * 10] == 1) && (playback)) statc[player * 10] = 0;
		if(statc[player * 10] < 0) statc[player * 10] = 2;
	}
	
	// ↓
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 1) ) {
		PlaySE(5);
		statc[player * 10]++;
		if((statc[player * 10] == 1) && (playback)) statc[player * 10] = 2;
		if(statc[player * 10] > 2) statc[player * 10] = 0;
	}
	
	// ←
	if( (mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 2) ) {
		if(statc[player * 10] == 0) {
			PlaySE(3);
			statc[player * 10 + 1]--;
			if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = 39;
		}
	}
	
	// →
	if( (mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 3) ) {
		if(statc[player * 10] == 0) {
			PlaySE(3);
			statc[player * 10 + 1]++;
			if(statc[player * 10 + 1] > 39) statc[player * 10 + 1] = 0;
		}
	}
	
	// Aボタン
	if( getPushState(player, 4) ) {
		if(statc[player * 10] == 0) {
			// SAVE
			if(time2[player] <= 72000) {
				PlaySE(10);
				
				if(gameMode[player] == 4) {
					saveReplayData(0, statc[player * 10 + 1] + 1);
					saveReplayData(1, statc[player * 10 + 1] + 1);
				} else {
					saveReplayData(player, statc[player * 10 + 1] + 1);
				}
				
				checkReplayExist();
			}
		} else if(statc[player * 10] == 1) {
			// RETRY
			PlaySE(10);
			
			if(gameMode[player] == 5) {
				// PRACITCE
				PracticeOver();
			} else {
				// それ以外
				if(!onRecord[1 - player]) {
					backno = 0;
					back_acnt = 0;
				}
				
				versusInit(player);
				playerInitial(player);
				
				if(gameMode[player] == 4) {
					// VERSUS
					versusInit(1 - player);
					playerInitial(1 - player);
					
					for(i = 0; i < 2; i++) {
						stat[i] = 9;
						statc[i * 10] = 0;
						statc[i * 10 + 1] = 0;
						statc[i * 10 + 2] = 0;
					}
					
					backno = 15;
					resetVersusMode();
				} else if(gameMode[player] == 8) {
					// MISSION
					stat[player] = 22;
					statc[player * 10] = 0;
					statc[player * 10 + 1] = 0;
					statc[player * 10 + 2] = 0;
				} else {
					// それ以外
					stat[player] = 2;
					statc[player * 10] = 0;
					statc[player * 10 + 1] = 0;
					statc[player * 10 + 2] = 0;
					
					// BIGとかが維持されないのでまだコメントアウト状態
					//startGame(player, lastmode[player], lasttype[player], 0);
				}
			}
		} else if(statc[player * 10] == 2) {
			// END
			if(!onRecord[1 - player]) {
				RankingProc(gameMode[player]);
				flag = 1;
			} else {
				PlaySE(10);
				stat[player] = 0;
				statc[player * 10] = 0;
				statc[player * 10 + 1] = 0;
				statc[player * 10 + 2] = 0;
			}
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ステータスNo.25 - 一定時間何もしない
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// statc[player * 10 + 0]：待ち時間
// statc[player * 10 + 1]：待ち時間終了後に移動するステータス
void statNothing(int player) {
	int i;
	
	padRepeat(player);
	if(ace_irs) doNewIRS(player, 0);
	if(fastlrmove == 3) HyperLRMove(player);
	
	statc[player * 10 + 2]++;
	
	if(statc[player * 10 + 2] >= statc[player * 10 + 0]) {
		stat[player] = statc[player * 10 + 1];
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ステータスNo.26 - ブロックを上から指定したライン数だけ消去
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// statc[player * 10 + 0]：カウンタ
// statc[player * 10 + 1]：終了後に移動するステータス
// statc[player * 10 + 2]：消すライン数
// statc[player * 10 + 3]：既に消去したライン数
void statExtraErase(int player) {
	int i, j, k;
	
	padRepeat(player);
	if(ace_irs) doNewIRS(player, 0);
	if(fastlrmove == 3) HyperLRMove(player);
	
	if((statc[player * 10] > -100 + wait1[player]) && (statc[player * 10] < 0) && (gameMode[player] != 6)) {
		statc[player * 10]++;
		return;
	}
	
	if(statc[player * 10] == 0) {
		// どこから消すか決める
		statc[player * 10] = checkFieldTop(player) * 6;
		return;
	}
	
	// ブロックを消す
	if(statc[player * 10] % 6 == 0) {
		j = statc[player * 10] / 6;
		
		if((j >= 0) && (j < 22)) {
			for(i = 0; i < 10; i++) {
				if(fld[i + j * 10 + player * 220]) {
					if(fldo[i + j * 10 + player * 220] == 0) {
						objectCreate(player, 1, (i + boffset[player]) * 8, (j + 3) * 8, (i - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + 1 * 250, fld[i + j * 10 + player * 220] - 1, 100);
					}
					fld[i + j * 10 + player * 220] = 0;
					fldt[i + j * 10 + player * 220] = 0;
					fldi[i + j * 10 + player * 220] = 0;
					fldo[i + j * 10 + player * 220] = 0;
					flds[i + j * 10 + player * 220] = 0;
				}
			}
		}
		
		statc[player * 10 + 3]++;	// 消したライン数+1
	}
	
	// アニメ終了判定
	if((statc[player * 10] >= 0) && ((statc[player * 10 + 3] >= statc[player * 10 + 2]) || (statc[player * 10] / 6 >= 22)))
		statc[player * 10] = -160;
	
	if((gameMode[player] == 6) && (statc[player * 10] >= 129)) statc[player * 10] = -100;
	
	// アニメ終了処理
	if(statc[player * 10] == -100) {
		pinchCheck(player);
		stat[player] = statc[player * 10 + 1];
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		return;
	}
	
	statc[player * 10]++;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ステータスNo.38 - STANDARDモードセレクト画面
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statStandardSelect(int player) {
	int i;
	
	// デフォルト設定を読み込み
	if(!statc[player * 10 + 2]) {
		loadWait(player, p_def_setting);
		statc[player * 10 + 1] = p_def_setting;
		statc[player * 10 + 2] = 1;
	}
	
	// 画面表示
	printFont(boffset[player], 5, "SETUP", fontc[rots[player]]);
	
	sprintf(string[0], "%s%2d", delayname[0 + english * 4], wait1[player]);
	printFont(boffset[player],  6, string[0], count % 9 * (statc[player * 10] == 0));
	sprintf(string[0], "%s%2d", delayname[1 + english * 4], wait2[player]);
	printFont(boffset[player],  7, string[0], count % 9 * (statc[player * 10] == 1));
	sprintf(string[0], "%s%2d", delayname[2 + english * 4], wait3[player]);
	printFont(boffset[player],  8, string[0], count % 9 * (statc[player * 10] == 2));
	sprintf(string[0], "%s%2d", delayname[3 + english * 4], waitt[player]);
	printFont(boffset[player],  9, string[0], count % 9 * (statc[player * 10] == 3));
	sprintf(string[0], "SPEED %4d", sp[player]);
	printFont(boffset[player], 10, string[0], count % 9 * (statc[player * 10] == 4));
	sprintf(string[0], "BGM     %2d", bgmlv + 1);
	printFont(boffset[player], 11, string[0], count % 9 * (statc[player * 10] == 5));
	
	printFont(boffset[player], 13, "FAVORITES", fontc[rots[player]]);
	printFont(boffset[player], 14, waitname[statc[player * 10 + 1]], count % 9 * (statc[player * 10] == 6));
	
	if(statc[player * 10] == 6) {
		printFont(boffset[player], 22, "PRESS A TO", fontc[rots[player]]);
		printFont(boffset[player], 23, "LOAD SETUP", fontc[rots[player]]);
	} else {
		printFont(boffset[player], 22, "PRESS A TO", fontc[rots[player]]);
		printFont(boffset[player], 23, "START GAME", fontc[rots[player]]);
	}
	
	// キー入力
	padRepeat(player);
	padRepeat2(player);
	
	// ↑
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 0) ) {
		PlaySE(5);
		statc[player * 10]--;
		if(statc[player * 10] < 0) statc[player * 10] = 6;
	}
	
	// ↓
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 1) ) {
		PlaySE(5);
		statc[player * 10]++;
		if(statc[player * 10] > 6) statc[player * 10] = 0;
	}
	
	// ←
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 2) ) {
		PlaySE(3);
		
		// SYUTUGEN
		if(statc[player * 10] == 0) {
			wait1[player]--;
			if(wait1[player] < 0) wait1[player] = 99;
		}
		// SYOUKYO
		if(statc[player * 10] == 1) {
			wait2[player]--;
			if(wait2[player] < 0) wait2[player] = 99;
		}
		// SETTYAKU
		if(statc[player * 10] == 2) {
			wait3[player]--;
			if(wait3[player] < 0) wait3[player] = 99;
		}
		// YOKOTAME
		if(statc[player * 10] == 3) {
			waitt[player]--;
			if(waitt[player] < 0) waitt[player] = 99;
		}
		// SPEED
		if(statc[player * 10] == 4) {
			sp[player]--;
			if(sp[player] < 0) sp[player] = 1200;
		}
		// BGM
		if(statc[player * 10] == 5) {
			bgmlv--;
			if(bgmlv < 0) bgmlv = 20;
		}
		// FAVORITES
		if(statc[player * 10] == 6) {
			i = 0;	// 無限ループ防止用
			
			do {
				statc[player * 10 + 1]--;
				
				if(statc[player * 10 + 1] < 0) {
					if(i == 0) {
						statc[player * 10 + 1] = 19;
						i = 1;
					} else {
						statc[player * 10 + 1] = 0;
						break;
					}
				}
			} while(favorites_isempty(statc[player * 10 + 1]));
		}
	}
	
	// →
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 3) ) {
		PlaySE(3);
		
		// SYUTUGEN
		if(statc[player * 10] == 0) {
			wait1[player]++;
			if(wait1[player] > 99) wait1[player] = 0;
		}
		// SYOUKYO
		if(statc[player * 10] == 1) {
			wait2[player]++;
			if(wait2[player] > 99) wait2[player] = 0;
		}
		// SETTYAKU
		if(statc[player * 10] == 2) {
			wait3[player]++;
			if(wait3[player] > 99) wait3[player] = 0;
		}
		// YOKOTAME
		if(statc[player * 10] == 3) {
			waitt[player]++;
			if(waitt[player] > 99) waitt[player] = 0;
		}
		// SPEED
		if(statc[player * 10] == 4) {
			sp[player]++;
			if(sp[player] > 1200) sp[player] = 0;
		}
		// BGM
		if(statc[player * 10] == 5) {
			bgmlv++;
			if(bgmlv > 20) bgmlv = 0;
		}
		// FAVORITES
		if(statc[player * 10] == 6) {
			i = 0;	// 無限ループ防止用
			
			do {
				statc[player * 10 + 1]++;
				
				if(statc[player * 10 + 1] > 19) {
					if(i == 0) {
						statc[player * 10 + 1] = 0;
						i = 1;
					} else {
						statc[player * 10 + 1] = 0;
						break;
					}
				}
			} while(favorites_isempty(statc[player * 10 + 1]));
		}
	}
	
	// ショートカットキーが押されたら対応する設定を読み込み
	for(i = 0; i < 20; i++) {
		if( IsPushKey(waitkey[i]) ) {
			PlaySE(3);
			loadWait(player, i);
		}
	}
	
	// Bボタン
	if( getPushState(player, 5) ) {
		tc[player] = -1;
		stat[player] = 1;				// ブロックシャッター実行
		statc[player * 10] = 0;			// ステータスカウンタを0に
		statc[player * 10 + 1] = 2;		// シャッター後はステータスNo.2
		return;
	}
	
	// Aボタン
	if( getPushState(player, 4) ) {
		if(statc[player * 10] == 6) {
			PlaySE(3);
			loadWait(player, statc[player * 10 + 1]);
		} else {
			PlaySE(10);
			start_bgmlv[player] = bgmlv;
			stat[player] = 1;				// ブロックシャッター実行
			statc[player * 10] = 0;			// ステータスカウンタを0に
			statc[player * 10 + 1] = 3;		// シャッター後はステータスNo.3
			return;
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ステータスNo.40 - 段位認定試験
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// statc[player * 10 + 0]：カウンタ
// statc[player * 10 + 1]：0なら開始宣言、1なら結果発表、それ以外なら暫定段位表示
// statc[player * 10 + 2]：花火が上がった回数
void statExamination(int player) {
	int i, k, tmp, draw_rate;
	
	// 開始宣言
	if(statc[player * 10 + 1] == 0) {
		// プルプル開始
		if(statc[player * 10 + 0] == 0) {
			if(examination[player] == 1) PlaySE(14);
			else PlaySE(49);
			purupuru[player] = 1;
		}
		// プルプルおわり
		else if(statc[player * 10 + 0] == 110) {
			PlaySE(45);
			ofs_x[player] = 0;
			purupuru[player] = 0;
		}
		// 試験指令
		else if(statc[player * 10 + 0] > 110) {
			// A PROMOTIONAL EXAM
			if(statc[player * 10 + 0] < 170) {
				ExBltRectR(49, foffset[player] - 2 - ((100 * 22 / 12 - 100) / 2), 80, 200, 100 + 25 * (count % 4 / 2), 100, 25, 65536 * 22 / 12, 65536 * 22 / 12);
			} else if(statc[player * 10 + 0] < 192) {
				k = 192 - statc[player * 10 + 0];
				i = (100 * k / 12 - 100) / 2;
				k = 65536 * k / 12;
				if(k < 65536) {
					k = 65536;
					i = 0;
				}
				
				ExBltRectR(49, foffset[player] - 2 - i, 48 + 192 - statc[player * 10 + 0] , 200, 100 + 25 * (count % 4 / 2), 100, 25, k, k);
			} else {
				ExBltRect(49, foffset[player] - 2, 48, 200, 100 + 25 * (count % 4 / 2), 100, 25);
			}
			
			// 目標段位の表示
			if(statc[player * 10 + 0] > 210) {
				if(!english) ExBltRect(49, foffset[player] - 2, 74, 200, 180, 100, 20);
				else printFont(boffset[player], 10, "EXAM GRADE", 0);
				
				drawGradeImage(foffset[player] + 2, 100, exam_grade[player], 0);
			}
		}
		
		// ゲーム開始
		if(statc[player * 10 + 0] > 360) {
			timelimit[0 + player * 2] = 0;	// 足切り無効
			stat[player] = 3;
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
			return;
		}
	}
	// 結果発表
	else if(statc[player * 10 + 1] == 1) {
		// プルプル開始
		if(statc[player * 10 + 0] == 0) {
			purupuru[player] = 1;
		}
		// プルプルおわり
		else if(statc[player * 10 + 0] == 60) {
			PlaySE(45);
			ofs_x[player] = 0;
			purupuru[player] = 0;
		}
		// 結果発表
		else if(statc[player * 10 + 0] > 60) {
			if(!english) ExBltRect(49, foffset[player] - 2, 48, 200, 150, 100, 30);
			else printFont(boffset[player] + 2, 6, "RESULT", 0);
			
			// 目標段位の表示
			if(statc[player * 10 + 0] > 90) {
				if(!english) ExBltRect(49, foffset[player] - 2, 74, 200, 180, 100, 20);
				else printFont(boffset[player], 10, "EXAM GRADE", 0);
				
				drawGradeImage(foffset[player] + 2, 100, exam_grade[player], 0);
			}
			
			// 差が大きければルーレット演出をとばす
			if(statc[player * 10 + 0] == 150) {
				if((abs(exam_grade[player] - grade[player]) > 3) || (grade[player] == 32))
					statc[player * 10 + 0] = 350;
			}
			
			// ルーレット
			if((statc[player * 10 + 0] > 150) && (statc[player * 10 + 0] < 350)) {
				if((statc[player * 10 + 0] % 5 == 0) && (statc[player * 10 + 0] < 320))
					PlaySE(5);
				
				if((statc[player * 10 + 0] % 10 < 5) || (statc[player * 10 + 0] >= 320)) {
					// 不合格
					if(!english) ExBltRect(49, foffset[player] + 13, 162, 215, 250, 70, 25);
					else printFont(boffset[player] + 2, 20, "FAILED", 0);
				} else {
					// 合格
					if(!english) ExBltRect(49, foffset[player] + 13, 162, 215, 200, 70, 25);
					else printFont(boffset[player] + 1, 20, "SUCCESS!", 0);
				}
			}
			
			// 確定した瞬間
			if(statc[player * 10 + 0] == 350) {
				// 合格
				if(grade[player] >= exam_grade[player]) {
					PlaySE(18);
					
					if(examination[player] == 1) {
						PlaySE(31);
						user_master_hard_admit[player] = exam_grade[player];
					}
				}
				// 不合格
				else {
					PlaySE(44);
					
					if(examination[player] == 2) {
						user_master_hard_admit[player] = exam_grade[player];
					}
				}
			}
			
			// 確定後
			if(statc[player * 10 + 0] >= 350) {
				// 合格
				if(grade[player] >= exam_grade[player]) {
					if(!english) ExBltRect(49, foffset[player] + 13, 162, 215, 200 + 25 * (count % 4 / 2), 70, 25);
					else printFont(boffset[player] + 1, 20, "SUCCESS!", 7 * (count % 4 / 2));
					
					// 花火発生
					if((statc[player * 10 + 0] % 10 == 0) && (statc[player * 10 + 2] < 20)) {
						objectCreate(player, 3, -40 + Rand(80) + foffset[player], 16 + Rand(20), 0, 0, Rand(7), 0);
						statc[player * 10 + 2]++;
					}
				}
				// 不合格
				else {
					if(!english) ExBltRect(49, foffset[player] + 13, 162, 215, 250 + 25 * (count % 4 / 2), 70, 25);
					else printFont(boffset[player] + 2, 20, "FAILED", 2 * (count % 4 / 2));
				}
			}
			
			// 暫定段位の画面へ
			if(statc[player * 10 + 0] >= 720) {
				statc[player * 10 + 0] = 0;
				statc[player * 10 + 1] = 2;
				statc[player * 10 + 2] = 0;
				return;
			}
		}
	}
	// 暫定段位表示
	else {
		tmp = 300;
		
		// あなたの暫定段位は
		if(statc[player * 10 + 0] == 0) {
			if(screenMode >= 2) draw_rate = 2;
			else draw_rate = 1;
			
			TextSize(player, 10 * draw_rate);
			TextColor(player, 255, 255, 255);
			TextBackColorDisable(player);
			TextOut(player, yourgrade[english + 2]);
			TextLayerOn(player, (foffset[player] + 3) * draw_rate, 92 * draw_rate);
		}
		
		drawGradeImage(foffset[player] + 2, 108, grade[player], 0);
		
		// ボタンでスキップ
		if(getPushState(player, 4)) {
			tmp = 60;
		}
		
		// 終了
		if(statc[player * 10 + 0] >= tmp) {
			TextLayerOff(player);
			user_master_hard_grade_pasttime[player] = 0;	// 前の試験からの経過時間をリセット
			stat[player] = 11;
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
			return;
		}
	}
	
	statc[player * 10 + 0]++;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  ステータスNo.42 - ROT. RELAYの次のルール選択
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// statc[player * 10 + 0]：初期化済みフラグ
// statc[player * 10 + 1]：カーソル位置
// statc[player * 10 + 2]：タイム
void statRotRelaySelectRule(int player) {
	int i, color2;
	
	// 横溜め
	if(repversw >= 7) padRepeat(player);
	
	// 初期化
	if(statc[player * 10 + 0] == 0) {
		statc[player * 10 + 0] = 1;
		
		// ルール使用済みフラグON
		rot_used_flag[rots[player] + player * 10] = 1;
		
		// カーソル位置設定
		statc[player * 10 + 1] = rots[player];
		while(rot_used_flag[statc[player * 10 + 1] + player * 10]) {
			statc[player * 10 + 1]++;
			if(statc[player * 10 + 1] > 9) statc[player * 10 + 1] = 0;
		}
		
		statc[player * 10 + 2] = 600;
	}
	
	color2 = (count % 4 / 2) * fontc[statc[player * 10 + 1]];
	padRepeat2(player);
	
	// ルール一覧表示
	printFont(boffset[player], 6, "SELECT", fontc[statc[player * 10 + 1]]);
	printFont(boffset[player] + 1, 7, "ROT. RULE", fontc[statc[player * 10 + 1]]);
	
	printFont(boffset[player], 9 + statc[player * 10 + 1], "b", color2);
	
	for(i = 0; i < 10; i++) {
		if(!rot_used_flag[i + player * 10]) {
			getRuleNameEx(i, 0);
			printFont(boffset[player] + 1, 9 + i, string[0], (statc[player * 10 + 1] == i) * color2);
		}
	}
	
	printFont(boffset[player] + 1, 22, "TIME", fontc[statc[player * 10 + 1]]);
	statc[player * 10 + 2]--;
	sprintf(string[0], "%d", (statc[player * 10 + 2] / 60));
	printFont(boffset[player] + 8, 22, string[0], 0);
	
	// キー入力
	// ↑
	if((mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6))
	if(getPressState(player, 0)) {
		PlaySE(5);
		
		do {
			statc[player * 10 + 1]--;
			if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = 9;
		} while(rot_used_flag[statc[player * 10 + 1] + player * 10]);
	}
	
	// ↓
	if((mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6))
	if(getPressState(player, 1)) {
		PlaySE(5);
		
		do {
			statc[player * 10 + 1]++;
			if(statc[player * 10 + 1] > 9) statc[player * 10 + 1] = 0;
		} while(rot_used_flag[statc[player * 10 + 1] + player * 10]);
	}
	
	// 決定
	if(getPushState(player, 4) || (statc[player * 10 + 2] <= 0)) {
		PlaySE(10);
		rots[player] = statc[player * 10 + 1];
		setNextBlockColors(player, 1);
		stat[player] = 1;				// ブロックシャッター実行
		statc[player * 10] = 0;			// ステータスカウンタを0に
		statc[player * 10 + 1] = 3;		// シャッター後はステータスNo.3
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   勝敗決定
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void winner() {
	int		player, i, j, block, win, obj, c;

	timeOn[0] = 0;
	timeOn[1] = 0;
	onRecord[0] = 0;
	onRecord[1] = 0;
	
	gameTimer[1] = gameTimer[0];
	
	ofs_x[0] = 0;
	ofs_y[0] = 0;
	ofs_x[1] = 0;
	ofs_y[1] = 0;
	
	winc++;
	wink++;
	winu = winu + wink / 4;
	
	StopWave(32);	// ピンチ音停止
	
	if(winu > 140) {
		winu = 140;
		wink = -20;
	}

	win = (stat[1] == 7) + ((stat[0] == 7) && (stat[1] == 7));

	for(player = 0; player < 2; player++) {
		if(win == player)
			obj = 1;
		else if(win != 2)
			obj = 0;
		else
			obj = 2;
		
		ExBltRect(3, foffset[player] + 6, winu, 96, obj * 25, 86, 24);
		
		// 花火
		if((winc % 10 == 0) && (endingcnt[player] < 10) && (win != player) && (obj != 2)) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], 16 + Rand(20), 0, 0, Rand(7), 0);
			endingcnt[player]++;
		}
		
		if( (getPushState(player, 4) && (winr > 20)) || (winc > 60 * 5) ) {
			for(i = 0; i < 2; i++) {
				stat[i] = 1;					// ブロックシャッター実行
				statc[i * 10] = 0;				// ステータスカウンタを0に
				statc[i * 10 + 1] = 12;			// シャッター後はステータスNo.12
			}
			flag = 0;
			return;
		}
	}
	
	if(winr <= 20) winr++;
}

// VERSUSモードで各種設定をバックアップから戻す
void resetVersusMode() {
	int player;
	
	for(player = 0; player < 2; player++) {
		// 速度をバックアップから戻す
		sp[player]    = b_sp[player];
		wait1[player] = b_wait1[player];
		wait2[player] = b_wait2[player];
		wait3[player] = b_wait3[player];
		waitt[player] = b_waitt[player];
		
		// CPU設定をバックアップから戻す
		cpu_flag[player] = b_cpu_flag[player];
		cpu_level[player] = b_cpu_level[player];
		
		// アイテム設定をバックアップから戻す
		item_mode[player] = b_item_mode[player];
		r_enable[player] = b_r_enable[player];
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ピンチかどうかチェック
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void pinchCheck(int player) {
	int		i, j;

	pinch[player] = 0;
	
	for(i = 0; i <= 7; i++)
		for(j = 2; j <= 7; j++)
			if(fld[j + i * 7 + player * 220]) {
				pinch[player] = 1;
				break;
			}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   パッドリピート入力処理
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void padRepeat(int player) {
	// ゲーム中は1フレームに2回以上実行しない
	if(onRecord[player]) {
		if((last_mp_check[player] == time2[player]) && (repversw >= 7)) {
			return;
		} else {
			last_mp_check[player] = time2[player];
		}
	}
	
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
int getPressState(int pl, int key) {
	int player;
	
	if(!maxPlay && pl) return 0;
	
	// 誰が操作するか決める
	if(isremote[pl]) {
		player = !pl;	// リモコン
	} else {
		player = pl;	// 通常
	}
	
	if(!replayauto && onRecord[player]) {
		if(isUDLRreverse[player]) {
			if(key == 0)
				key = 1;
			else if(key == 1)
				key = 0;
			else if(key == 2)
				key = 3;
			else if(key == 3)
				key = 2;
		} else if(isLRreverse[player]) {
			if(key == 2)
				key = 3;
			else if(key == 3)
				key = 2;
		} else if(isUDreverse[player]) {
			if(key == 0)
				key = 1;
			else if(key == 1)
				key = 0;
		}
	}
	
	if(playback && replayauto) {
		// リプレイ
		if(onRecord[player]) {
			if(!player)
				return (replayData[time2[player]] & (1 << key)) / (1 << key);
			else
				return (replayData2[time2[player]] & (1 << key)) / (1 << key);
		}
		
		return 0;
	} else if( (cpu_flag[player]) && (!pause[player]) && ((onRecord[player]) || (stat[player] == 3)) ) {
		// コンピュータ
		return cpu_ctrl[key + player * 10];
	} else {
		// 通常
		SelectJoyStick(player);
		
		if(!keyAssign[key + player * 10])
			return IsPressJoyKey(joykeyAssign[key + player * 10]);
		else
			return IsPressJoyKey(joykeyAssign[key + player * 10]) | IsPressKey(keyAssign[key + player * 10]);
	}
}

int getPushState(int pl, int key) {
	int player;
	
	if(!maxPlay && pl) return 0;
	
	// 誰が操作するか決める
	if(isremote[pl]) {
		player = !pl;	// リモコン
	} else {
		player = pl;	// 通常
	}
	
	if(!replayauto && onRecord[player]) {
		if(isUDLRreverse[player]) {
			if(key == 0)
				key = 1;
			else if(key == 1)
				key = 0;
			else if(key == 2)
				key = 3;
			else if(key == 3)
				key = 2;
		} else if(isLRreverse[player]) {
			if(key == 2)
				key = 3;
			else if(key == 3)
				key = 2;
		} else if(isUDreverse[player]) {
			if(key == 0)
				key = 1;
			else if(key == 1)
				key = 0;
		}
	}
	
	if(playback && replayauto) {
		// リプレイ
		if(onRecord[player]) {
			if(!player)
				return (replayData[time2[player]] & (1 << (key + 8))) / (1 << (key + 8));
			else
				return (replayData2[time2[player]] & (1 << (key + 8))) / (1 << (key + 8));
		}
		
		return 0;
	} else if( (cpu_flag[player]) && (!pause[player]) && ((onRecord[player]) || (stat[player] == 3)) ) {
		// コンピュータ
		return cpu_ctrl[key + player * 10];
	} else {
		// 通常
		SelectJoyStick(player);
		
		return IsPushJoyKey(joykeyAssign[key + player * 10]) | IsPushKey(keyAssign[key + player * 10]);
	}
}

// 特定のプレイヤーのジョイスティック入力を検出する関数…のつもり #LITE25
// ちゃんと動くかは不明
int getJoyPressState(int pl, int key) {
	if(!maxPlay && pl) return 0;
	SelectJoyStick(pl);
	return IsPressJoyKey(key);
}

int getJoyPushState(int pl, int key) {
	if(!maxPlay && pl) return 0;
	SelectJoyStick(pl);
	return IsPushJoyKey(key);
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   初期設定
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void initialize() {
	int i;
	
	SetConstParam("Caption", "HEBORIS LITE - Loading...");
	
	loadScreenConfig();	// SCREEN.SAV読み込み(screencfg.c)
	
	// 描画する解像度を設定
	if(screenMode <= 1)
		setDrawRate(1);
	else
		setDrawRate(2);
	
	// バージョン表示
	TextLayerOn(1, 10, 220);
	TextSize(1, 12);
	TextColor(1, 255, 255, 255);
	TextBackColorDisable(1);
	TextOut(1, version);
	halt;
	
	// CUSTOM以外のルール設定
	setRuleSettingToDefault();
	
	// CONFIG.SAVを読み込み
	first_setting = config_load();
	
	// グラフィックを読み込み
	TextMove(1, 10, 10);
	TextOut(1, "Graphics Loading");
	halt;
	
	loadGraphics();
	
	// フィールドの表示位置を設定
	setFieldPosition(maxPlay);
	
	// 背景を読み込み
	if(!skip_viewbg) loadBackground();
	
	// 効果音を読み込み
	if(se) {
		TextMove(1, 10, 22);
		TextOut(1, "Sound Effect Loading");
		halt;
		
		loadWaves();
	}
	
	for(i = 0; i < 60; i++) se_play[i] = 0;
	
	// BGMを読み込み
	if((bgm >= 1) && (bgm <= 3)) {
		TextMove(1, 10, 34);
		TextOut(1, "BGM Loading");
		halt;
		
		if(bgm == 1) {
			LoadMIDI("bgm/bgm.mid");
			PlayMIDI();
		} else {
			loadBGM();
		}
	}
	
	// 音量設定
	resetVolume();
	
	TextLayerOff(1);
	
	// ランキング読み込み
	RankingAlloc();
	if( RankingLoad() ) {
		RankingInit();
	}
	
	// セクションタイムランキング読み込み
	ST_RankingAlloc();
	if( ST_RankingLoad() ) {
		ST_RankingInit();
	}
	
	// STANDARDモード用ランキング読み込み
	stdRankingAlloc();
	if( stdRankingLoad() ) {
		stdRankingInit();
	}
	
	mission_course_name = new(17);	// 15 + NULL
	StrCpy(mission_course_name, "");
	
	user_name[0] = new(4);
	user_name[1] = new(4);
	StrCpy(user_name[0], "");
	StrCpy(user_name[1], "");
	
	// FAVORITES読み込み
	favorites_init();
	if( favorites_load() ) {
		favorites_set_default();
	}
	
	// ジョイスティックのボタンは3つ以上使いますよー
	SetJoystickButtonSetting();
	
	SetConstParam("Caption", "HEBORIS LITE");
	SetConstParam("EnablePause", 1);	// ここからポーズ有効
}

// ジョイスティックのボタン数設定を反映させる
void SetJoystickButtonSetting() {
	int i;
	
	for(i = 0; i < 2; i++) {
		SelectJoyStick(i);
		SetJoyButtonMax(joykeyButtonNum);
	}
}

// ビットマップを読み込み
void ExLoadBitmap(str *nameStr, int plane, int unknown) {
	/*
	sprintf(string[0], "graphics/%s", nameStr);
	LoadBitmap(string[0], plane, unknown);
	*/
	
	if(getDrawRate() == 1)
		sprintf(string[0], "graphics/%s", nameStr);
	else
		sprintf(string[0], "graphicshi/%s", nameStr);
	
	LoadBitmap(string[0], plane, unknown);
}

// 背景ビットマップを読み込み
void ExLoadBackground(str *nameStr, int plane, int unknown) {
	/*
	sprintf(string[0], "back/%s", nameStr);
	LoadBitmap(string[0], plane, unknown);
	*/
	
	if(getDrawRate() == 1)
		sprintf(string[0], "back/%s", nameStr);
	else
		sprintf(string[0], "backhi/%s", nameStr);
	
	LoadBitmap(string[0], plane, unknown);
}

// アニメーションするタイトル画像を読み込み
void ExLoadTitleAnim() {
	/*
	LoadBitmap("title_mov/logo_low.png", 7, 0);
	LoadBitmap("title_mov/tmov_low.png", 8, 0);
	SetColorKeyRGB(7,0,0,0);
	*/
	
	if(getDrawRate() == 1) {
		LoadBitmap("title_mov/logo_low.png", 7, 0);
		LoadBitmap("title_mov/tmov_low.png", 8, 0);
	} else {
		LoadBitmap("title_mov/logo_hi.png", 7, 0);
		LoadBitmap("title_mov/tmov_hi.png", 8, 0);
	}
	
	SetColorKeyRGB(7,0,0,0);
}

// グラフィック読み込み
void loadGraphics() {
	int i, j, k, tr;
	
	/* プレーン0にメダル絵を読み込み */
	ExLoadBitmap("medal.png", 0, 0);
	
	/* プレーン1にフォントを読み込み */
	ExLoadBitmap("hebofont.png", 1, 0);
	SetColorKeyPos(1, 0, 0);
	
	/* プレーン2にフィールドを読み込み */
	ExLoadBitmap("hebofld.png", 2, 0);
	SetColorKeyPos(2, 20, 20);
	
	/* プレーン3に各種スプライトを読み込み */
	ExLoadBitmap("hebospr.png", 3, 0);
	SetColorKeyPos(3, 0, 0);
	EnableBlendColorKey(3, 1);
	
	/* プレーン4～5にミッションモード用画像を読み込み */
	ExLoadBitmap("heboris_road.png", 4, 0);
	ExLoadBitmap("del_field.bmp", 5, 0);
	SetColorKeyRGB(5, 255, 0, 255);
	
	/* プレーン6にオールドスタイル用画像を読み込み */
	ExLoadBitmap("heboblk_old.bmp", 6, 0);
	
	/* プレーン7～8にタイトル画像を読み込み */
	if(!title_mov_f) {	// 静止画
		ExLoadBitmap("title.png", 8, 0);
	} else {
		ExLoadTitleAnim();
	}
	
	/* プレーン9に2倍拡大用サーフェス */
	//if(screenMode >= 2) CreateSurface(9, 640, 480);
	
	/* プレーン10～16にプラチナブロック消去エフェクトを読み込み */
	ExLoadBitmap("perase1.png", 10, 0);
	ExLoadBitmap("perase2.png", 11, 0);
	ExLoadBitmap("perase3.png", 12, 0);
	ExLoadBitmap("perase4.png", 13, 0);
	ExLoadBitmap("perase5.png", 14, 0);
	ExLoadBitmap("perase6.png", 15, 0);
	ExLoadBitmap("perase7.png", 16, 0);
	
	/* プレーン17～19にミラー演出用画像を読み込み */
	ExLoadBitmap("mirror_effect.bmp", 17, 0);
	ExLoadBitmap("fldmirror.png", 18, 0);
	ExLoadBitmap("fldmirror2.png", 19, 0);
	
	/* プレーン20に流れ星を読み込み */
	ExLoadBitmap("shootingstar.png", 20, 0);
	
	/* プレーン21に段位表示用の画像を読み込み */
	ExLoadBitmap("grade.png", 21, 0);
	
	/* プレーン22に大きいフォントを読み込み */
	ExLoadBitmap("hebofont3.png", 22, 0);
	
	/* プレーン23にスナップショット用プレーンを作成 */
	//if(screenMode <= 1) CreateSurface(23, 320, 240);
	ExCreateSurface(23, 320, 240);
	
	/* プレーン24に真っ黒フィールド背景を読み込み */
	if(!fldbgtype)
		ExLoadBitmap("heboflb0.bmp", 24, 0);
	else
		ExLoadBitmap("heboflb1.bmp", 24, 0);
	
	/* プレーン25～27にブロック絵を読み込み */
	ExLoadBitmap("heboblk_normal.png", 25, 0);	// 普通
	ExLoadBitmap("heboblk_big.png", 26, 0);		// ビッグ
	ExLoadBitmap("heboblk_small.bmp", 27, 0);	// 縮小
	
	/* プレーン28にレーザー用の画像を読み込み */
	ExLoadBitmap("laser.bmp", 28, 0);
	
	/* プレーン29にアイテム消去エフェクトを読み込み */
	ExLoadBitmap("itemerase.png", 29, 0);
	
	/* プレーン30にブロックの枠線を読み込み */
	ExLoadBitmap("heboblkframe.bmp", 30, 0);
	SetColorKeyRGB(30, 0, 0, 0);
	
	/* プレーン31～38にブロック消去エフェクトを読み込み */
	if(breakeffect == 3) {
		ExLoadBitmap("old_break_effect.png", 31, 0);
	} else if((breakgraphics) && (breakeffect == 2)) {
		ExLoadBitmap("break0.png", 31, 0);
		ExLoadBitmap("break1.png", 32, 0);
		ExLoadBitmap("break2.png", 33, 0);
		ExLoadBitmap("break3.png", 34, 0);
		ExLoadBitmap("break4.png", 35, 0);
		ExLoadBitmap("break5.png", 36, 0);
		ExLoadBitmap("break6.png", 37, 0);
		ExLoadBitmap("break7.png", 38, 0);
		SetColorKeyRGB(31, 0, 0, 0);
		SetColorKeyRGB(32, 0, 0, 0);
		SetColorKeyRGB(33, 0, 0, 0);
		SetColorKeyRGB(34, 0, 0, 0);
		SetColorKeyRGB(35, 0, 0, 0);
		SetColorKeyRGB(36, 0, 0, 0);
		SetColorKeyRGB(37, 0, 0, 0);
		SetColorKeyRGB(38, 0, 0, 0);
	} else if((!breakgraphics) && (breakeffect == 2)) {
		ExLoadBitmap("break0_tap.png", 31, 0);
		ExLoadBitmap("break1_tap.png", 32, 0);
		ExLoadBitmap("break2_tap.png", 33, 0);
		ExLoadBitmap("break3_tap.png", 34, 0);
		ExLoadBitmap("break4_tap.png", 35, 0);
		ExLoadBitmap("break5_tap.png", 36, 0);
		ExLoadBitmap("break6_tap.png", 37, 0);
		ExLoadBitmap("break7_tap.png", 38, 0);
		SetColorKeyRGB(31, 255, 0, 255);
		SetColorKeyRGB(32, 255, 0, 255);
		SetColorKeyRGB(33, 255, 0, 255);
		SetColorKeyRGB(34, 255, 0, 255);
		SetColorKeyRGB(35, 255, 0, 255);
		SetColorKeyRGB(36, 255, 0, 255);
		SetColorKeyRGB(37, 255, 0, 255);
		SetColorKeyRGB(38, 255, 0, 255);
	}
	
	/* プレーン39～45に花火を読み込み */
	ExLoadBitmap("hanabi_red.png",       39, 0);
	ExLoadBitmap("hanabi_orange.png",    40, 0);
	ExLoadBitmap("hanabi_yellow.png",    41, 0);
	ExLoadBitmap("hanabi_green.png",     42, 0);
	ExLoadBitmap("hanabi_waterblue.png", 43, 0);
	ExLoadBitmap("hanabi_blue.png",      44, 0);
	ExLoadBitmap("hanabi_purple.png",    45, 0);
	
	/* プレーン46～48に特殊ブロックの絵を読み込み */
	ExLoadBitmap("heboblk_sp.png", 46, 0);			// 普通
	ExLoadBitmap("heboblk_sp_big.png", 47, 0);		// ビッグ
	ExLoadBitmap("heboblk_sp_small.bmp", 48, 0);		// 縮小
	
	/* プレーン49に文字画像を読み込み */
	ExLoadBitmap("text2.png", 49, 0);
	
	/* プレーン50に背景フェード用画像を読み込み */
	ExLoadBitmap("fade.bmp", 50, 0);
	SetColorKeyRGB(50, 255, 255, 255);
	
	/* プレーン51に暗いタイトル画像を読み込み #LITE30.2 */
	ExLoadBitmap("title_dark.png", 51, 0);
	
	/* プレーン52にオールドスタイルビッグ画像を読み込み */
	ExLoadBitmap("heboblk_old_big.bmp", 52, 0);
	
	/* プレーン53にSHUFFLE FIELD用画像を読み込み */
	ExLoadBitmap("shuffle_field_effect.bmp", 53, 0);
	
	/* プレーン60～75は背景 */
	
	/* プレーン76にナビゲーションブロック絵を読み込み */
	ExLoadBitmap("guide.bmp", 76, 0);
	SetColorKeyRGB(76, 0, 0, 0);
	
	/* プレーン77～79に対戦モード用画像を読み込み */
	ExLoadBitmap("fldmirror3.png", 77, 0);
	ExLoadBitmap("item_guage.bmp", 78, 0);
	SetColorKeyRGB(78, 255, 0, 255);
	ExLoadBitmap("item_name.png", 79, 0);
	SetColorKeyRGB(79, 255, 0, 255);
	
	/* プレーン80にミラー演出用画像を読み込み */
	ExLoadBitmap("fldmirror4.png", 80, 0);
	
	/* プレーン81～82にスタッフロール画像を読み込み */
	ExLoadBitmap("staffroll.png", 81, 0);
	ExLoadBitmap("staffroll2.png", 82, 0);
	
	/* プレーン83にブロックの影を読み込み */
	ExLoadBitmap("heboblk_shadow.png", 83, 0);
	
	/* プレーン84に真っ白画像を読み込み */
	ExLoadBitmap("heboflb2.bmp", 84, 0);
}

// 背景読み込み
void loadBackground() {
	int i, j, k, tr;
	int movframe, max, tmp1, tmp2, tmptr;
	int players, tmp_offset;
	
	/* プレーン60～75にバックを読み込み */
	ExLoadBackground("back01.png",  60, 0);
	ExLoadBackground("back02.png",  61, 0);
	ExLoadBackground("back03.png",  62, 0);
	ExLoadBackground("back04.png",  63, 0);
	ExLoadBackground("back05.png",  64, 0);
	ExLoadBackground("back06.png",  65, 0);
	ExLoadBackground("back07.png",  66, 0);
	ExLoadBackground("back08.png",  67, 0);
	ExLoadBackground("back09.png",  68, 0);
	ExLoadBackground("back10.png",  69, 0);
	ExLoadBackground("back11.png",  70, 0);
	ExLoadBackground("back12.png",  71, 0);
	if(!background_compatibility) {
		ExLoadBackground("back13.png",  72, 0);
		ExLoadBackground("back14.png",  73, 0);
		ExLoadBackground("back15.png",  74, 0);
	}
	ExLoadBackground("back_vs.png", 75, 0);
	
	/* 背景半透明処理 */
	tmptr = 256 - fldtr;
	for(i = 60; i <= 75; i++) {
		if((i < 72) || (i > 74) || (!background_compatibility)) {
			SwapToSecondary(i);
			
			if(back_mov_f[i - 60] == 0)
				max = 1;
			else
				max = back_mov_f[i - 60];
			
			for(movframe = 0; movframe < max; movframe++) {
				tmp1 = ((movframe / 10) * 320);
				tmp2 = ((movframe % 10) * 240);
				
				// プレイヤー数を決める
				if(i == 75) players = 1;
				else players = maxPlay;
				
				for(j = 0; j <= players; j++) {
					// 表示位置を決める
					if(i == 75) {
						// VERSUS
						tmp_offset = v_foffset[j];
					} else {
						// 通常
						tmp_offset = foffset[j];
					}
					
					
					BlendExBltRect(24, (tmp_offset + 8) + tmp1, 40 + tmp2, 0, 0, 80, 160, tmptr, tmptr, tmptr, fldtr, fldtr, fldtr);
					
					if(top_frame) {
						BlendExBltRect(3, (tmp_offset - 15) + tmp1, tmp2, 127, 268, 126, 35, tmptr, tmptr, tmptr, fldtr, fldtr, fldtr);
					} else {
						// グラデーション部分をなめらかに#1.60c7p9ex
						BlendExBltRect(3, tmp_offset + tmp1, tmp2, 101, 128, 100 - 20, 32, tmptr, tmptr, tmptr, fldtr, fldtr, fldtr);
						for(k = 0; k < 20; k++) {
							tr = tmptr * (19 - k) / 20;
							tr = 256 - tr;
							BlendExBltRect(3, tmp_offset + (80 + k) + tmp1, tmp2, 101 + (80 + k), 128, 1, 32, 256 - tr, 256 - tr, 256 - tr, tr, tr, tr);
						}
					}
				}
			}
			SwapToSecondary(i);
		}
	}
}

// 効果音読み込み
void loadWaves() {
	int i;
	
	ReleaseWaveAll();
	
	LoadWave("se/shaki.wav", 0);
	LoadWave("se/kon.wav", 1);
	LoadWave("se/gon.wav", 2);
	LoadWave("se/kachi.wav", 3);
	LoadWave("se/rotate.wav", 4);
	LoadWave("se/move.wav", 5);
	LoadWave("se/missionclr.wav", 7);
	LoadWave("se/gameover.wav", 8);
	LoadWave("se/hold.wav", 9);
	LoadWave("se/kettei.wav", 10);
	LoadWave("se/erase1.wav", 11);
	LoadWave("se/erase2.wav", 12);
	LoadWave("se/erase3.wav", 13);
	LoadWave("se/erase4.wav", 14);
	LoadWave("voice/ready.wav", 15);
	LoadWave("voice/go.wav", 16);
	LoadWave("se/applause.wav", 17);
	LoadWave("se/cheer.wav", 18);
	LoadWave("se/levelup.wav", 19);
	LoadWave("se/up.wav", 20);
	LoadWave("blockse/block1.wav", 21);
	LoadWave("blockse/block2.wav", 22);
	LoadWave("blockse/block3.wav", 23);
	LoadWave("blockse/block4.wav", 24);
	LoadWave("blockse/block5.wav", 25);
	LoadWave("blockse/block6.wav", 26);
	LoadWave("blockse/block7.wav", 27);
	LoadWave("se/lvstop.wav", 28);
	LoadWave("se/ttclear.wav", 29);
	LoadWave("se/gm.wav", 30);
	LoadWave("se/rankup.wav", 31);
	
	LoadWave("se/pinch.wav", 32);
	SetLoopModeWave(32,1);
	
	LoadWave("se/hanabi.wav", 33);
	LoadWave("se/movefail.wav", 34);
	LoadWave("se/rotfail.wav", 35);
	LoadWave("se/pause.wav", 36);
	LoadWave("se/stageclear.wav", 37);
	LoadWave("se/hurryup.wav", 38);
	LoadWave("se/timeover.wav", 39);
	LoadWave("se/platinaerase.wav", 40);
	LoadWave("se/timeextend.wav", 41);
	LoadWave("se/tspin.wav", 42);
	LoadWave("se/ace_sonic_lock.wav",43);
	LoadWave("se/regret.wav", 44);
	LoadWave("se/medal.wav", 45);
	LoadWave("se/stgstar.wav", 46);
	LoadWave("se/thunder.wav", 47);
	LoadWave("se/cool.wav", 48);
	LoadWave("se/warning.wav", 49);
	LoadWave("se/tserase.wav", 50);
	LoadWave("se/timestop.wav", 51);
}

// BGMを読み込み
void loadBGM() {
	int i;
	
	for(i = 0; i <= 20; i++) {
		// ファイル名を決める
		StrCpy(string[0], music_file_name[i]);
		
		// 拡張子を決める
		if(bgm == 3) StrCat(string[0], ".mp3");
		else StrCat(string[0], ".wav");
		
		// 読み込み
		LoadWave(string[0], 60 + i);
		
		// ループON
		SetLoopModeWave(60 + i, 1);
	}
	
	// エンディング曲をループさせるかは設定で決める
	SetLoopModeWave(66, sound_ending_loop);
	SetLoopModeWave(67, sound_beginner_ending_loop);
}

// 設定内容をバックアップ
void backupSetups() {
	setupBak[ 0] = smooth;
	setupBak[ 1] = nanameallow;
	setupBak[ 2] = sonicdrop;
	setupBak[ 3] = fastlrmove;
	setupBak[ 4] = w_reverse;
	setupBak[ 5] = r_irs;
	setupBak[ 6] = rots[0];
	setupBak[ 7] = rots[1];
	setupBak[ 8] = lvupbonus;
	setupBak[ 9] = spawn_y_type;
	setupBak[10] = w_lockdown;
	setupBak[11] = wsoftlock;
	setupBak[12] = rot180;
	setupBak[13] = tspin_type;
	setupBak[14] = enable_minspeed;
	setupBak[15] = disable_hold;
	setupBak[16] = bonus_tspin;
	setupBak[17] = bonus_btb;
	setupBak[18] = ace_irs;
	setupBak[19] = ending_timelimit;
	setupBak[20] = skip_blocklockflash;
	setupBak[21] = drs_floorkick;
	setupBak[22] = item_interval;
	setupBak[23] = devil_doom_n_rise;
}

// 設定内容を戻す
void restoreSetups() {
	smooth              = setupBak[ 0];
	nanameallow         = setupBak[ 1];
	sonicdrop           = setupBak[ 2];
	fastlrmove          = setupBak[ 3];
	w_reverse           = setupBak[ 4];
	r_irs               = setupBak[ 5];
	rots[0]             = setupBak[ 6];
	rots[1]             = setupBak[ 7];
	lvupbonus           = setupBak[ 8];
	spawn_y_type        = setupBak[ 9];
	w_lockdown          = setupBak[10];
	wsoftlock           = setupBak[11];
	rot180              = setupBak[12];
	tspin_type          = setupBak[13];
	enable_minspeed     = setupBak[14];
	disable_hold        = setupBak[15];
	bonus_tspin         = setupBak[16];
	bonus_btb           = setupBak[17];
	ace_irs             = setupBak[18];
	ending_timelimit    = setupBak[19];
	skip_blocklockflash = setupBak[20];
	drs_floorkick       = setupBak[21];
	item_interval       = setupBak[22];
	devil_doom_n_rise   = setupBak[23];
	
	config_load();				// 設定を再読み込み
	setRuleSettingToDefault();	// CUSTOM以外の各ルールの設定をデフォルトに戻す
}

// フィールドの表示位置を設定
void setFieldPosition(int players) {
	int i;
	
	// フィールドの表示位置を設定
	if(players) {
		// DUAL
		for(i = 0; i <= maxPlay; i++) {
			foffset[i] = d_foffset[i];
			boffset[i] = d_boffset[i];
			soffset[i] = d_soffset[i];
			toffset[i] = d_toffset[i];
		}
		moffset = d_moffset;
		coffset = d_coffset;
	} else {
		// SINGLE
		foffset[0] = s_foffset;
		boffset[0] = s_boffset;
		soffset[0] = s_soffset;
		toffset[0] = s_toffset;
		moffset = s_moffset;
		coffset = s_coffset;
	}
}

// CUSTOM以外の各ルールの設定をデフォルトに戻す
void setRuleSettingToDefault() {
	int i;
	
	for(i = 0; i < 9; i++) {
		rule_rot[i]        = def_rule_rot[i];
		rule_hard_lock[i]  = def_rule_hard_lock[i];
		rule_soft_lock[i]  = def_rule_soft_lock[i];
		rule_soft_speed[i] = def_rule_soft_speed[i];
		rule_are[i]        = def_rule_are[i];
		rule_color[i]      = def_rule_color[i];
		rule_lock_reset[i] = def_rule_lock_reset[i];
		rule_lock_sound[i] = def_rule_lock_sound[i];
		rule_ars_extrot[i] = def_rule_ars_extrot[i];
		rule_lock_limit[i] = def_rule_lock_limit[i];
		rule_rot_limit[i]  = def_rule_rot_limit[i];
		rule_graphics[i]   = def_rule_graphics[i];
		rule_180rot[i]     = def_rule_180rot[i];
		rule_max_waitt[i]  = def_rule_max_waitt[i];
		rule_oblk_bg[i]    = def_rule_oblk_bg[i];
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ブロックのあたり判定
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int judgeBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	int		data[2];
	
	// BIGの場合は専用処理
	if(IsBig[player]) {
		return judgeBigBlock(player, bx1, by1, kind, rotate);
	}
	
	for(i = 0 ; i < 4 ; i++) {
		getBlockData(player, bx1, by1, kind, rotate, i, &data);
		bx2 = data[0];
		by2 = data[1];
		
		if((by2 < 2) && (heboGB[player] == 2)) {
			return -1;
		}
		
		if( (bx2 < 0) || (bx2 > 9) || (by2 > 21) ) {
			return -1;
		} else if( (fld[bx2 + by2 * 10 + player * 220] != 0) && (by2 >= 0) ) {
			return -1;
		}
	}

	return 0;
}

// BIG用
int judgeBigBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	int		k, l, bx3, by3;
	int		data[2];
	
	for(i = 0 ; i < 4 ; i++) {
		getBlockData(player, 0, 0, kind, rotate, i, &data);
		bx2 = bx1 + (data[0] * 2);
		by2 = by1 + (data[1] * 2);
		
		/* 4ブロック分調べる */
		for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
			bx3 = bx2 + k;
			by3 = by2 + l;
			
			if((by3 < 2) && (heboGB[player] == 2)) {
				return -1;
			}
			
			if( (bx3 < 0) || (bx3 > 9) || (by3 > 21) ) {
				return -1;
			} else if( (fld[bx3 + by3 * 10 + player * 220] != 0) && (by3 >= 0) ) {
				return -1;
			}
		}
	}

	return 0;
}

// ARS系で壁蹴りできるか判定
int judgeBlockRotate(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	
	// BIGの場合は専用処理
	if(IsBig[player]) {
		return judgeBigBlockRotate(player, bx1, by1, kind, rotate);
	}
	
	for(i = 0 ; i < 4 ; i++) {
		// 中央の列以外が重なっている場合は壁蹴り可能
		if( blkDataX[ kind * 16 + rotate * 4 + i ] != 1 ) {
			bx2 = ( bx1 + blkDataX[ kind * 16 + rotate * 4 + i ] );
			by2 = ( by1 + blkDataY[ kind * 16 + rotate * 4 + i ] );
			
			if( (bx2 < 0) || (bx2 > 9) || (by2 > 21) ) {
				return -1;
			} else if( (fld[bx2 + by2 * 10 + player * 220] != 0) && (by2 >= 0) ) {
				return -1;
			}
		}
	}
	
	return 0;
}

// ARS系で壁蹴りできるか判定
// BIG用
int judgeBigBlockRotate(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	int		k, l, bx3, by3;
	
	for(i = 0 ; i < 4 ; i++) {
		// 中央の列以外が重なっている場合は壁蹴り可能
		if( blkDataX[ kind * 16 + rotate * 4 + i ] != 1 ) {
			bx2 = (bx1 + blkDataX[ kind * 16 + rotate * 4 + i ] * 2);
			by2 = (by1 + blkDataY[ kind * 16 + rotate * 4 + i ] * 2);
			
			/* 4ブロック分調べる */
			for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
				bx3 = bx2 + k;
				by3 = by2 + l;
				
				if( (bx3 < 0) || (bx3 > 9) || (by3 > 21) ) {
					return -1;
				} else if( (fld[bx3 + by3 * 10 + player * 220] != 0) && (by3 >= 0) ) {
					return -1;
				}
			}
		}
	}
	
	return 0;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ブロックを設置する
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void setBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2, puted;
	int		data[2];
	
	// BIGの場合は専用処理
	if(IsBig[player]) {
		setBigBlock(player, bx1, by1, kind, rotate);
		return;
	}
	
	puted = 0;
	
	for(i = 0 ; i < 4 ; i++) {
		getBlockData(player, bx1, by1, kind, rotate, i, &data);
		bx2 = data[0];
		by2 = data[1];
		
		if((bx2 >= 0) && (bx2 <= 9) && (by2 >= (!spawn_y_type)) && (by2 < 22)) {
			if(by2 >= 2) puted++;
			
			fld[bx2 + by2 * 10 + player * 220] = c_cblk_r[player] + 1;
			
			if(hidden[player] == 1)
				fldt[bx2 + by2 * 10 + player * 220] = shadowtime[player];
			else if(hidden[player] == 2)
				fldt[bx2 + by2 * 10 + player * 220] = -60;
			else
				fldt[bx2 + by2 * 10 + player * 220] = -1;
			
			fldi[bx2 + by2 * 10 + player * 220] = item[player];
			fldo[bx2 + by2 * 10 + player * 220] = o_cblk[player];
			flds[bx2 + by2 * 10 + player * 220] = s_bdowncnt[player] + 1;
		}
	}
	
	// ブロックを1つも置けなかったらゲームオーバー
	if((!puted) && (spawn_y_type)) setGameOver(player);
}

// BIG用
void setBigBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2, puted;
	int		k, l, bx3, by3;
	int		data[2];
	
	puted = 0;
	
	for(i = 0 ; i < 4 ; i++) {
		getBlockData(player, 0, 0, kind, rotate, i, &data);
		bx2 = bx1 + (data[0] * 2);
		by2 = by1 + (data[1] * 2);
		
		/* 4ブロック分設置する */
		for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
			bx3 = bx2 + k;
			by3 = by2 + l;
			
			if((bx3 >= 0) && (bx3 <= 9) && (by3 >= (!spawn_y_type)) && (by3 < 22)) {
				if(by2 >= 2) puted++;
				
				fld[bx3 + by3 * 10 + player * 220] = c_cblk_r[player] + 1;
				
				if(hidden[player] == 1)
					fldt[bx3 + by3 * 10 + player * 220] = shadowtime[player];
				else if(hidden[player] == 2)
					fldt[bx3 + by3 * 10 + player * 220] = -60;
				else
					fldt[bx3 + by3 * 10 + player * 220] = -1;
				
				fldi[bx3 + by3 * 10 + player * 220] = item[player];
				fldo[bx3 + by3 * 10 + player * 220] = o_cblk[player];
				flds[bx3 + by3 * 10 + player * 220] = s_bdowncnt[player] + 1;
			}
		}
	}
	
	// ブロックを1つも置けなかったらゲームオーバー
	if((!puted) && (spawn_y_type)) setGameOver(player);
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ブロックを消去する
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void removeBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	int		data[2];
	
	// BIGの場合は専用処理
	if(IsBig[player]) {
		removeBigBlock(player, bx1, by1, kind, rotate);
		return;
	}
	
	for(i = 0 ; i < 4 ; i++) {
		getBlockData(player, bx1, by1, kind, rotate, i, &data);
		bx2 = data[0];
		by2 = data[1];
		
		if( ( bx2 >= 0 ) && ( bx2 <= 9 ) && ( by2 >= 0 ) && ( by2 < 22 ) ) {
			fld[bx2 + by2 * 10 + player * 220] = 0;
			fldt[bx2 + by2 * 10 + player * 220] = 0;
		}
	}
}

// BIG用
void removeBigBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	int		k, l, bx3, by3;
	int		data[2];
	
	for(i = 0 ; i < 4 ; i++) {
		getBlockData(player, 0, 0, kind, rotate, i, &data);
		bx2 = bx1 + (data[0] * 2);
		by2 = by1 + (data[1] * 2);
		
		/* 4ブロック分消す */
		for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
			bx3 = bx2 + k;
			by3 = by2 + l;
			
			if( ( bx3 >= 0 ) && ( bx3 <= 9 ) && ( by3 >= 0 ) && ( by3 < 22 ) ) {
				fld[bx3 + by3 * 10 + player * 220] = 0;
				fldt[bx3 + by3 * 10 + player * 220] = 0;
			}
		}
	}
}

// ブロックの相対Ｘ座標＆Ｙ座標を取得
void getBlockData(int player, int bx1, int by1, int kind, int rotate, int index, int *data) {
	// ARS
	if(rule_rot[rots[player]] == 0) {
		data[0] = bx1 +  blkDataX[kind * 16 + rotate * 4 + index];
		data[1] = by1 +  blkDataY[kind * 16 + rotate * 4 + index];
	}
	// SRS
	if(rule_rot[rots[player]] == 1) {
		data[0] = bx1 + blkWDataX[kind * 16 + rotate * 4 + index];
		data[1] = by1 + blkWDataY[kind * 16 + rotate * 4 + index];
	}
	// DRS
	if(rule_rot[rots[player]] == 2) {
		data[0] = bx1 + blkDDataX[kind * 16 + rotate * 4 + index];
		data[1] = by1 + blkDDataY[kind * 16 + rotate * 4 + index];
	}
}

// 特定の座標にどんなブロックが存在するか調べる
// フィールド外は-1
// フィールドより上は-2
int getFieldBlock(int player, int bx1, int by1) {
	if((bx1 < 0) || (bx1 > 9) || (by1 > 21)) return -1;
	if(by1 < 0) return -2;
	
	return fld[bx1 + by1 * 10 + player * 220];
}

// TOMOYOせり上がりエディタ用
int getFieldBlockTomoyoRiseEditor(int player, int bx1, int by1) {
	if((bx1 < 0) || (bx1 > 9) || (by1 > 21)) return -1;
	if(by1 < 0) return -2;
	
	return tomoyo_rise_fld[bx1 + by1 * 10 + player * 200];
}

// 正方形用
int getFieldBlockS(int player, int bx1, int by1) {
	if((bx1 < 0) || (bx1 > 9) || (by1 < 0) || (by1 > 21)) return 0;
	
	return flds[bx1 + by1 * 10 + player * 220];
}

// フィールドの最上段を返す
int checkFieldTop(int player) {
	int i, j;
	
	for(i = 0; i < 22; i++)
		for(j = 0; j < 10; j++) 
			if(fld[j + i * 10 + player * 220])
				return i;
	
	// 空っぽの場合
	return 22;
}

// フィールドの最上段を返す（X座標を指定できるバージョン）
int checkFieldTopEx(int player, int j) {
	int i;
	
	for(i = 0; i < 22; i++)
		if(fld[j + i * 10 + player * 220])
			return i;
	
	// 空っぽの場合
	return 22;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  擬似乱数
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// シード生成
void GiziSRand(int player) {
	randseed[player] = Rand(65536);
	firstseed[player] = randseed[player];
}

// 乱数生成
int GiziRand(int player, int max) {
	if(max == 0) return 0;
	randseed[player] = ((randseed[player] * 673 + 994) / 10) % 100000;
	return abs(randseed[player]) % max;
}

// 絶対値を求める（C++版では削除推奨）
int abs(int i) {
	if(i < 0) return -i;
	return i;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ビット演算
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// 変数valueのbit目のビットの状態を調べる
int BitTest(int value, int bit) {
	return (value) & (1 << (bit));
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

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   valueが0なら動作停止
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void debug_assert(int value, str *errMsg) {
	int frame;
	
	if(value) return;
	
	frame = 0;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		printFont(1, 1, "ASSERTION FAILED", 2);
		printFont(1, 3, errMsg, 0);
		
		sprintf(string[0], "STAT 1P: %d", stat[0]);
		printFont(1, 5, string[0], 0);
		sprintf(string[0], "STAT 2P: %d", stat[1]);
		printFont(1, 6, string[0], 0);
		
		frame++;
		
		if(frame > 60) {
			printFont(1, 27, "A: CONTINUE", 3);
			printFont(1, 28, "B: QUIT", 3);
			
			if(getPushState(0, 4)) {
				return;
			}
			if(getPushState(0, 5)) {
				Quit();
			}
		}
		
		if(!refresh_timing) spriteTime();
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   halt;
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void spriteTime() {
	// FPS増加キー
	if(IsPressKey(fps_plus_key) || getJoyPressState(0, joy_fps_plus_key[0]) || getJoyPressState(1, joy_fps_plus_key[1])) {
		fps_plus_mpc++;
		
		if((fps_plus_mpc == 1) || (fps_plus_mpc > tame1)) {
			if(GetFPS() < 99) SetFPS(GetFPS() + 1);
		}
	} else {
		fps_plus_mpc = 0;
	}
	
	// FPS減少キー
	if(IsPressKey(fps_minus_key) || getJoyPressState(0, joy_fps_minus_key[0]) || getJoyPressState(1, joy_fps_minus_key[1])) {
		fps_minus_mpc++;
		
		if((fps_minus_mpc == 1) || (fps_minus_mpc > tame1)) {
			if(GetFPS() > 1) SetFPS(GetFPS() - 1);
		}
	} else {
		fps_minus_mpc = 0;
	}
	
	// FPSの表示
	if(show_fps == 1) {
		sprintf(string[0], "%3d/%2dFPS", GetRealFPS(), GetFPS());
		printFont(15, 29, string[0], digitc[rots[0]]);
	}
	if(show_fps == 2) {
		sprintf(string[0], "HEBORIS LITE - %02d/%02dFPS", GetRealFPS(), GetFPS());
		SetConstParam("Caption", string[0]);
	}
	
	// 2倍ウインドウモードの時の処理
	/*
	if(screenMode >= 2) {
		SwapToSecondary(9);		// セカンダリプレーンを、ダミーでプレーン9と入れ替える
		ExBltFastRectR(9, 0, 0, 0, 0, 320, 240, 65536 * 2, 65536 * 2);
		SwapToSecondary(9);
		ExBltFast(9, 0, 0);
	}
	*/
	
	// ESCキーが押されたら即刻終了
	if( IsPushEscKey() ) {
		if(!playback) {
			maxPlay = b_maxPlay;	// プレイ人数をバックアップから戻す
			config_save_rots();		// 最後に使っていたルールをセーブする
		}
		Quit();
	}
	
	// 描画
	halt;
	
	// 効果音再生
	PlayAllSE();
	
	// スクリーンショット
	if( IsPushKey(ss_key) || getJoyPushState(0, joy_ss_key[0]) || getJoyPushState(1, joy_ss_key[1]) ) {
		sprintf(string[0], "ss\\ss_%04d.bmp", ssc);
		
		SwapToSecondary(23);
		ExSaveBitmap(string[0], 23, 0, 0, 320, 240);
		SwapToSecondary(23);
		
		/*
		if(screenMode <= 1) {
			SwapToSecondary(23);
			SaveBitmap(string[0], 23, 0, 0, 320, 240);
			SwapToSecondary(23);
		} else {
			SaveBitmap(string[0], 9, 0, 0, 640, 480);
		}
		*/
		
		ssc++;
	}
	
	ClearSecondary();
}
