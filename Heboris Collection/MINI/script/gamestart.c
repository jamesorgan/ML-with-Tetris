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
	更新履歴はdocs\changelog.txtに移動しました。
*/

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   外部ライブラリのインポート
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
	import	"string.dll"				// 文字列ライブラリのインポート
	import	"time.dll"					// 時間ライブラリのインポート
	import	"ygs2kTCP.dll"				// ネットワーク通信ライブラリのインポート

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   グローバル変数の定義
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int		saveBuf[150000];				// セーブ用バッファ
int		replayData[60 * 60 * 30 * 2];	// リプレイ保存用データ (最大30分まで) pl * 108000 + i

int		count;							// グローバルカウンタ (フレーム単位、65535まで)

int		disp_blkline[2];				// ブロックの枠線を表示するかどうかのフラグ

int		stat[2], statc[10*2];			// 現在のステータスとパラメータ no + pl * 10

int		mp[2], mpc[2], mps[2 * 2];		// 前回のパッドの入力内容と時間
int		mp2[2], mpc2[2];				//hoge 前回のパッドの入力内容と時間(上下キーバージョン)

int		tame1 = 25;						//hoge 左右の入れっぱなしで高速移動するまでの時間
int		tame2 = 3;						//hoge 高速移動の速さ(少ないほど速い)。
int		tame3 = 25;						//hoge ↑の上下版
int		tame4 = 3;						//hoge ↑の上下版

int		flag;							// 1以上でタイトルに戻る

int		pinch[2];						// ピンチかどうか

int		fast;							// 早送りフラグ

int		playback = 0;					// リプレイ中か?
int		demo = 0;						// デモモードか?
int		replayauto = 0;					// リプレイ自動操縦フラグ（0にすると手動操縦）

int		pause[2];						// ポーズしてるかーい!?

int		effectspeed[2];					// エフェクトのスピード

int		gameMode[2] = {-2, -2};			// 現在のモード
int		rots[2] = {-2, -2};				// 現在のルール

int		lastmode = 0;					// 最後に選んだモード
int		lastrots = 0;					// 最後に選んだルール

int		replayexist[40];				// リプレイデータが存在するかどうかのフラグ

int		blkshadow_direction[2];			// ブロックの影の方向

int		maxPlay = 0;					// 同時にプレイできる人数

// フィールドデータ
int		fld[20 * 42 * 2];				// フィールドの状態  x + y * fldsizex + player * (fldsizex * fldsizey)
int		fldt[20 * 42 * 2];				// フィールドタイマー
int		fldo[20 * 42 * 2];				// フィールドご先祖様
int		fldl[20 * 42 * 2];				// フィールドのブロックの繋がり
int		fldi[20 * 42 * 2];				// フィールドアイテム

// フィールドバッファ（ミラーの演出に使用）
int		fldbuf[20 * 42 * 2];			// フィールドの状態  x + y * fldsizex + player * (fldsizex * fldsizey)
int		fldtbuf[20 * 42 * 2];			// フィールドタイマー
int		fldobuf[20 * 42 * 2];			// フィールドご先祖様
int		fldlbuf[20 * 42 * 2];			// フィールドのブロックの繋がり
int		fldibuf[20 * 42 * 2];			// フィールドアイテム

// フィールドサイズ
int		fldsizex;						// フィールドの幅（0～20）
int		fldsizey;						// フィールドの高さ（0～42）

// フィールド枠
int		framecolor[2];					// フィールド枠の色
int		frame_decoration[2];			// フィールド枠に飾りを表示
int		field_spin[2];					// フィールド枠の回転状況（-1または20：回転してない）

// 現在のブロック
int		blk[2];							// 今落ちてくるブロック
int		bx[2], by[2], rt[2];			// ブロックの座標と向き
int		bs[2], bk[2];					// ブロックの自然落下とくっつきのタイム

int		current_color[4 * 2];			// 現在のブロックの色（固定後）
int		current_color_m[4 * 2];			// 現在のブロックの色（移動中）
int		current_oblk[2];				// 現在のブロックがご先祖様かどうか（oblkのoはover1000の意味）
int		current_item[2];				// 現在のアイテム

int		last_command[2];				// 最後の操作（0=移動/落下 1=空中で回転 2=空中で壁蹴り回転
										//             3=接地状態で回転 4=接地状態で壁蹴り回転）
int		rotcount[2];					// 接地状態で回転した回数
int		movecount[2];					// 接地状態で移動した回数
int		kickc[2];						// 壁蹴りカウンタ
int		kicktype[2];					// 壁蹴りタイプ

int		ghost[2];						// ゴーストON/OFF

int		bdowncnt[2];					// ブロックを置いた回数
int		brotcount[2];					// ブロックを回した回数

int		bactivetime[2];					// ブロックを操作している時間

int		bfallflag[2];					// ブロックが段差から落ちたフラグ
int		bfallcount[2];					// ブロックが段差から落ちた回数

int		spawntype[2];					// ブロックの出現位置（0=枠内 1=枠外）

// NEXTブロック
int		nextb[1400 * 2];				// 次のブロック
int		nextc[2];						// 次に降るブロックカウンタ
int		nextc_max[2];					// nextcの最大

int		next_color[6 * 4 * 2];			// 次のブロックの色
int		next_oblk[6 * 2];				// 次のブロックがご先祖様かどうか
int		next_item[6 * 2];				// 次のブロックがアイテムかどうか

int		next_offset[7 * 2];				// NEXTブロックのY座標位置のオフセット（NEXT1）
int		next_s_offset[7 * 2];			// NEXTブロックのY座標位置のオフセット（NEXT2～）
int		ndelay[2];						// NEXT遅延用

int		oblk_spawn[2];					// ご先祖様登場フラグ
int		oblk_bg[2];						// ご先祖様登場中の背景（0=なし 1=黒 2=白）

int		hnext[2];						// 今見えるNEXTブロックの数

str		userNextBlockList = "0123456";	// カスタムツモリスト (0=I 1=L 2=O 3=Z 4=T 5=J 6=S)

int		multicolor_enable[2];			// マルチカラーブロックが紛れ込むかどうか
int		multicolor_ratio[2];			// マルチカラーブロックが紛れ込む確率

// ホールド
int		hold[2];						// 現在ホールドに入っているブロック（-1=なし）
int		dhold[2];						// ホールド無効フラグ
int		hold_count[2];					// ホールド回数

int		hold_color[4 * 2];				// ホールドブロックの色
int		hold_oblk[2];					// ホールドブロックがご先祖様かどうか
int		hold_item[2];					// ホールドブロックがアイテムかどうか

// ハードドロップ／ソフトドロップ
int		harddrop[2];					// ハードドロップ使用フラグ
int		softdrop[2];					// ソフトドロップ使用フラグ
int		up_flag[2];						// 上入れ使いまわし防止フラグ
int		down_flag[2];					// 下入れ使いまわし防止フラグ
int		bk_D[2];						// DRS式ソフトドロップ用 下入れによる固定時間
int		softd_dropflag[2];				// ソフトドロップでブロックが落ちたら1になる
int		softd_score[2];					// ソフトドロップで入る点数

// アイテム
int		item_waiting[2];				// 発動待ち／発動中アイテム
int		enable_item_hold[2];			// アイテムをホールド可能かどうか
int		item_name[2];					// フィールド右上に表示するアイテム名
int		item_coming[2];					// NEXTの最後から出現するアイテム

int		fldisno = 44;					// fldiにおいてスクウェア用の画像がある場所(場所のカウントは→矢印が30番目)
int		fldigsno = 45;					// fldiにおいてGOLDENスクウェア用の画像がある場所
int		fldihardno = 43;				// fldiにおいてハードブロックの画像がある場所

// ライン消去
int		erase[42 * 2];					// 消されるブロック
int		line_count[4 * 2];				// ライン消し回数
int		are_skipflag[2];				// 消去時間中のAREスキップ使用フラグ
int		show_all_break_effect[2];		// 全てのブロックの消去エフェクトを表示するかどうか
int		perase_show_bonus[2];			// プラチナブロック消去時に+1を表示するかどうか

// 速度
int		wait1[2], wait2[2];				// 固定→次・消滅時の待ち時間
int		wait3[2], waitt[2];				// 設置から固定までのタイム・横溜め時間
int		wait4[2];						// 設置から固定までのタイム（段差落下後）-1でwait3を使用
int		wait5[2];						// 消滅時の待ち時間 -1でwait2を使用
int		sp[2];							// 現在の落下スピード
int		speedtype[2];					// 落下スピードの種類

// コンボ
int		enable_combo[2];				// コンボが有効かどうか
int		combo[2];						// コンボ
int		combo2[2];						// 1ライン消しで増えないコンボ
int		combo3[2];						// 1ライン消しで途切れるコンボ
int		hebocombo[2];					// ヘボリスからのコンボ

// スコア計算
int		sdrop[2];						// スコア計算用（ハードドロップ）
int		qdrop[2];						// スコア計算用（ソフトドロップ）
int		cmbpts[2];						// スコア計算用（コンボ）
int		qput[2];						// スコア計算用（自分でブロックを固定させたかどうか）

// BIGモード
int		IsBig[2];						// ビッグモードかどうか
int		BigMove[2];						// ビッグ時の横移動単位

// READY→GOの待ち時間
int		ready_start[2];					// ready開始
int		ready_end[2];					// ready終了
int		go_start[2];					// go開始
int		go_end[2];						// go終了

int		n_ready_start = 0;				// デフォルト ready開始
int		n_ready_end = 50;				// デフォルト ready終了
int		n_go_start = 55;				// デフォルト go開始
int		n_go_end = 100;					// デフォルト go終了

int		ready_count[2];					// READY→GOを表示した回数
int		nextskip[2];					// ツモスキップ

// せり上がり
int		upLines[2];						// 上昇してしまうライン数
int		fldu[20 * 42 * 2];				// せり上がりフィールド（せり上がるブロックの形状を記憶）

// T-SPIN
int		tspin_type[2];					// T-SPINの種類
int		tspin_flag[2];					// T-SPINしたかどうか

// BACK TO BACK
int		b_to_b_type[2];					// BACK TO BACKの種類（0=なし 1=通常 2=ヘボリスのみ 3=T-SPINのみ）
int		b_to_b_count[2];				// BACK TO BACKの連続回数

// タイム
int		gameTimer[2], timeOn[2];		// ゲーム開始からの経過時間 (1/60秒単位)、有効?
int		recTimer[2], onRecord[2];		// ゲーム開始からの本当の経過時間（リプレイ用）、有効?
int		replay_timer[40];				// リプレイデータのタイム

// エンディング
int		ending[2];						// エンディング中かどうか
int		edrec[2];						// エンディング経過時間
int		fastroll[2];					// 1の場合は高速ロール
int		ending_timeOn[2];				// エンディングタイマーが有効かどうか
int		staff_c[2];						// スタッフロールカウンタ
int		endtime[2];						// スタッフロール経過時間
int		staff_type[2];					// スタッフロールの画像の種類（0か1）

// 乱数
int		randseed[2];					// 擬似乱数シード
int		firstseed[2];					// 最初の乱数シード

// HIDDEN用変数
int		hidden[2], hiddentm[2], hiddeny[2], hiddenti[2], hiddenc[2];
int		shadowtime[2];					// ブロックが見える時間（HIDDEN LV8）

// キー設定
int		keyAssign[10 * 2];				// キーボードのボタン割り当て
int		joykeyAssign[10 * 2];			// ジョイスティックのボタン割り当て
int		joykeyButtonNum = 16;			// ジョイスティックのボタン数

int		pause_key[2];					// ポーズキー
int		joy_pause_key[2];				// ポーズキー（ジョイスティック）
int		giveup_key[2];					// 捨てゲーキー
int		joy_giveup_key[2];				// 捨てゲーキー（ジョイスティック）
int		ss_key[2];						// スクリーンショットキー
int		joy_ss_key[2];					// スクリーンショットキー（ジョイスティック）
int		extra_key[2];					// EXTRAキー
int		joy_extra_key[2];				// EXTRAキー（ジョイスティック）
int		fps_plus_key[2];				// FPS+1
int		joy_fps_plus_key[2];			// FPS+1（ジョイスティック）
int		fps_minus_key[2];				// FPS-1
int		joy_fps_minus_key[2];			// FPS-1（ジョイスティック）
int		retry_key[2];					// リトライキー
int		joy_retry_key[2];				// リトライキー（ジョイスティック）

int		key_enter = 0x1C;				// ENTERキーのキーコード
int		key_del = 0xD3;					// DELETEキーのキーコード
int		key_bs = 0x0E;					// BACKSPACEキーのキーコード

int		ssc = 0;						// スクリーンショットカウンタ
int		fps_plus_mpc[2];				// FPS+1の押しっぱなし時間
int		fps_minus_mpc[2];				// FPS-1の押しっぱなし時間

// 演出用変数
int		obj[100], objx[100], objy[100], objv[100], objw[100], objj[100], objc[100], obja[100], objp[100];

// 背景
int		backno = 0;						// 現在の背景
int		bgfadesw = 0;					// 背景フェードスイッチ
int		bgfadelv = 0;					// 背景フェードレベル
int		bgfadebg = 0;					// 背景フェード後に切り替える背景
int		firstbackno = 0;				// ゲームスタート時の背景

// 背景ムービー
int		back_acnt = 0;					// 現在のフレーム
int		back_mov_f[21];					// 最大コマ数（0にすると静止画）
int		back_mov_inter[21];				// 1コマを表示するフレーム数

// ゲームルール用
int		blockcolor[7 * 2];				// ブロックの色
int		blockgraphics[2];				// ブロックの絵柄
int		rot_reverse[2];					// 回転方向を逆にする

int		lockreset[2];					// 固定時間リセットの有無
int		rotlimit[2];					// 固定時間リセットONのとき、接地状態で回転できる回数
int		movelimit[2];					// 固定時間リセットONのとき、接地状態で移動できる回数

int		are[2];							// 出現待ち時間の有無（2=スキップあり）
int		lockflash[2];					// ブロックを固定させた瞬間、ブロックが光るフレーム数

int		lock_up[2];						// 上で即固定
int		lock_down[2];					// 下で即固定

int		softspeed[2];					// 下での落下速度（0から順に0.5倍、1.0倍、1.5倍、2.0倍、2.5倍…）

int		self_lock_sound[2];				// 自分で固定させたときにself_lock.wavを鳴らす

int		max_waitt[2];					// 横溜め最大
int		RepeatDelay[2];					// RepeatDelay
int		repeatcount[2];					// counter for RepeatDelay
int		fastlrmove[2];					// 先行横移動

int		initial_rotate[2];				// 先行回転
int		initial_hold[2];				// 先行ホールド
int		enable_wallkick[2];				// 壁蹴り有効?

int		block_init_x_pos[2];			// 出現時のX座標
int		block_init_y_pos[2];			// 出現時のY座標
int		block_init_rt[2];				// 出現時の向き

int		blkDataX[7 * 4 * 4 * 2];		// ユニットを構成するブロックの相対Ｘ位置(7種類/4角度/4ブロック/2プレイヤー)
int		blkDataY[7 * 4 * 4 * 2];		// ユニットを構成するブロックの相対Ｙ位置(7種類/4角度/4ブロック/2プレイヤー)
int		blkDataL[7 * 4 * 4 * 2];		// ブロックの繋がりのデータ

// 文字入力用
str		RankString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ.,- 0123456789<=>?!#$%&'()=pq";

// ミラー用
int		isfmirror[2];					// ミラー発動フラグ
int		fmirror_cnt[2];					// ミラー用カウンタ
int		stopmirror_flag[2];				// ミラー停止フラグ

// ロールロール用
int		current_rollroll[2];			// 今のツモがロールロールかどうか
int		rollroll_interval[2];			// 自動的に回転する間隔

// CPU
int		cpu_fld[20 * 42];				// 頭の中のフィールド
int		cpu_best_x[2];					// 最善手のX座標
int		cpu_best_y[2];					// 最善手のY座標
int		cpu_best_r[2];					// 最善手のブロックの方向
int		cpu_best_p[2];					// 最善手の評価点
int		cpu_hold[2];					// HOLDするかどうか
int		cpu_ctrl[10 * 2];				// コンピュータの操作内容
int		cpu_flag[2];					// コンピュータが操作するかどうか
int		cpu_speed[2];					// コンピュータの遅さ
int		cpu_frame[2];					// コンピュータが行動するまでのフレーム数

// ネットプレイ用
int		netplay = 0;					// ネットプレイ中は1
str		networkServerName[10];			// ネットプレイのサーバー名
int		networkServerPort[10];			// ネットプレイのポート番号
str		networkNickName = "";			// ニックネーム
int		networkUseNick = 0;				// ニックネームを使用するかどうか

// グラフィック・サウンド読み込み用
str		skin_folder = "default";		// スキンのフォルダ

int		graphics_count = 0;				// 読み込んだグラフィックの総数
int		sound_count = 0;				// 読み込んだ効果音の総数

int		graphics_plane_type[512];		// グラフィックプレーンの種類（0=なし 1=システム画像 2=背景 3=プラグイン画像）
int		sound_plane_type[512];			// サウンドプレーンの種類
										//（0=なし 1=システム効果音 2=システム音楽 3=プラグイン効果音 4=プラグイン音楽）

// システムで使うグラフィックプレーン番号
int		sg_blk_n;						// ブロックのグラフィック（通常）
int		sg_blk_b;						// ブロックのグラフィック（ビッグ）
int		sg_blk_s;						// ブロックのグラフィック（縮小）
int		sg_iblk_n;						// 特殊ブロックのグラフィック（通常）
int		sg_iblk_b;						// 特殊ブロックのグラフィック（ビッグ）
int		sg_iblk_s;						// 特殊ブロックのグラフィック（縮小）
int		sg_blkshadow;					// ブロックの影
int		sg_guide;						// ナビゲーションブロック
int		sg_font_n;						// フォント
int		sg_fld;							// フィールド画像
int		sg_3d_fld[10];					// 3Dフィールド画像
int		sg_spr;							// スプライト
int		sg_title;						// タイトル画像
int		sg_menu_back;					// メニューの背景
int		sg_black;						// 真っ黒画像
int		sg_white;						// 真っ白画像
int		sg_sssurface;					// スクリーンショット用サーフェイス
int		sg_2xwindow;					// 2倍拡大用サーフェイス
int		sg_background[21];				// 背景（20はback_vs.png）
int		sg_gametext;					// ゲームで使う大きい文字
int		sg_blkline;						// ブロックの枠線
int		sg_smallfont;					// 小さいフォント
int		sg_topframe;					// 画面上部の枠
int		sg_break[8];					// ライン消去エフェクト
int		sg_perase[7];					// プラチナブロック消去エフェクト
int		sg_itemerase;					// アイテム消去エフェクト
int		sg_medal[2];					// メダル
int		sg_shootingstar;				// 流れ星
int		sg_hanabi[7];					// 花火
int		sg_numberfont;					// 数字フォント（大・小）
int		sg_alphabetfont;				// アルファベットフォント（小文字使用可能）
int		sg_bgfade;						// 背景フェード
int		sg_staffroll[2];				// スタッフロール
int		sg_grade;						// 段位
int		sg_itemname;					// アイテムの名前
int		sg_line;						// ランキング画面の線

// システムで使うサウンドプレーン番号
int		se_shaki;
int		se_kon;
int		se_gon;
int		se_kachi;
int		se_rotate;
int		se_move;
int		se_gameover;
int		se_kettei;
int		se_erase[4];
int		se_ready;
int		se_go;
int		se_applause;
int		se_cheer;
int		se_levelup;
int		se_up;
int		se_blockse[7];
int		se_hold;
int		se_lvstop;
int		se_ttclear;
int		se_rankup;
int		se_hanabi;
int		se_pause;
int		se_pinch;
int		se_stgstar;
int		se_movefail;
int		se_rotfail;
int		se_cool;
int		se_regret;
int		se_tspin;
int		se_tserase;
int		se_platinaerase;
int		se_medal;
int		se_hurryup;
int		se_timeover;
int		se_self_lock;
int		se_warning;

// フィールド位置
int		foffset[2];						// フィールドの表示位置（横）
int		s_foffset = 112;				// SINGLE台用
int		d_foffset[2] = {16, 168};		// DUAL台用
int		v_foffset[2] = {16, 208};		// VERSUS用

int		fyoffset[2];					// フィールドの表示位置（縦）
int		s_fyoffset = 0;					// SINGLE台用
int		d_fyoffset[2] = {0, 0};			// DUAL台用
int		v_fyoffset[2] = {0, 0};			// VERSUS用

int		coffset;						// 操作状況の表示位置
int		s_coffset = 14;					// SINGLE台用
int		d_coffset = 176;				// DUAL台用

// サウンド関連
int		se_play[512];					// 効果音再生予約フラグ
int		sevolume = 0;					// 効果音の音量
int		bgmvolume = 0;					// BGMの音量
int		bgmtype = 0;					// BGMの種類（0=なし 1=WAV 2=MP3）
int		fadesetting = 100;				// BGMフェードの速さ

str		music_file_name[30];			// BGMのファイル名（heboris.iniで指定）
int		bgm_loop_start[30];				// BGMのループ開始地点（-1:なし）
int		bgm_loop_end[30];				// BGMのループ終了地点（ここに来たらstartの所に戻る）
int		bgm_auto_loop[30];				// BGMを通常ループさせるかどうか

int		bgm_plane[30];					// BGMのプレーン番号
int		bgmlv = 0;						// 現在のBGM
int		fadelv = 0;						// BGMフェードアウト用

// デバッグ関連
int		debug_enable = 0;				// デバッグモードフラグ
str*	debug_log_system[40];			// デバッグログ（システム）
str*	debug_log_rule[40];				// デバッグログ（ルール）
str*	debug_log_mode[40];				// デバッグログ（モード）

// プラグイン関連
str*	plugin_name_rule[200];			// ルール名
str*	plugin_name_mode[200];			// モード名
int		plugin_count_rule = 0;			// ルールプラグインの数
int		plugin_count_mode = 0;			// モードプラグインの数

str*	replay_plugin_name_rule[40];	// ルール名（リプレイ）
str*	replay_plugin_name_mode[40];	// モード名（リプレイ）

// 設定
int		screenMode = 1;					// 画面モード
int		systemmem = 0;					// システムメモリを使うか?
int		screenColor = 16;				// 画面の色数
int		useHires = 0;					// 2倍ウインドウモードの時に高解像度グラフィックを使用するかどうか

int		nextblock = 9;					// NEXTブロック生成方法
int		nanameallow = 1;				// 斜め入力無効化
int		fldtr = 32;						// フィールドの背景の半透明度
int		dispnext = 3;					// NEXTの数
int		top_frame = 2;					// 画面上部のNEXT枠の種類
int		breaktype = 1;					// ライン消去エフェクトの種類
int		downtype = 1;					// 連続上入れ下入れ制限の種類（0=なし 1=20Gのみあり 2=常にあり）
int		rotate_sound = 0;				// 回転音の有無
int		move_sound = 0;					// 移動音の有無
int		showctrl = 0;					// 操作状況表示の有無
int		spawn_y_type = 0;				// ブロックの出現位置（0=枠内 1=枠外）
int		fonttype = 0;					// 数字フォントの種類
int		show_fps = 1;					// FPS表示の有無（0=なし 1=あり 2=タイトルバー）
int		normalfps = 60;					// 標準FPS
int		hide_back = 0;					// 背景を表示しない
int		hold_sound = 0;					// ホールド音
int		english = 0;					// 英語モード
int		disable180 = 0;					// Eボタンを逆回転ボタンにする
int		enable_sysbgm = 1;				// タイトル画面とセレクト画面のBGMを有効にする
int		beffect_speed = 0;				// エフェクトスピード
int		blockshadow = 0;				// ブロックの影の有無＆方向（0=なし 1=左 2=右）
int		disable_hold = 0;				// HOLD無効化

int		dummy = 0;						// ダミー変数

// バージョン番号
str		versionStr = "HEBORIS U.E. MINI V20 BETA8 (08/04/28)";
int		versionNo = 24;		// バージョン番号
int		engineVer;			// ゲームエンジン番号
int		c_engineVer = 14;	// 現在のゲームエンジン番号

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ソースファイルのインポート
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
	include "script/screencfg.c"	// SCREEN.SAVの読み書き
	include "script/flexdraw.c"		// 高解像度対応描画関数
	include "script/loader.c"		// 各種読み込み関数
	include "script/lib.c"			// ゲームに関するいろいろな関数
	include "script/randomizer.c"	// NEXTブロック生成処理
	include "script/config.c"		// 設定画面
	include "script/move.c"			// 移動
	include "script/effect.c"		// 演出
	include "script/sound.c"		// 音声
	include "script/view.c"			// 表示
	include "script/cpu.c"			// CPU関連の処理
	include "script/replay.c"		// リプレイ
	include "script/debug.c"		// デバッグ用関数

	include "plugins.def"			// プラグイン

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   メイン
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void main() {
	int i, bak[2];
	
	// 設定を読み込み
	include "heboris.ini"
	include "network.ini"
	
	if(loadGeneralConfigData()) {
		saveGeneralConfigData();
	}
	
	// グラフィックや効果音を読み込み
	initialize();
	
	// キー設定を読み込み
	if(loadKeyConfigData()) {
		initKeyConfigData();
		keyconfig_keyboard_setting(0, 1);
	}
	
	if(!english) debugLogSystem("全初期化処理完了");
	else debugLogSystem("Completed all initialization.");
	
	loop {
		title();
		
		flag = 0;
		
		executePlugin(0, 41, &dummy);
		if(maxPlay) executePlugin(1, 41, &dummy);
		
		loop {
			spriteTime();
			KeyInput();
			
			// 背景
			if(!hide_back) viewBack();
			
			// リプレイ早送り
			if(playback && !demo && replayauto) {
				playback = 0;
				bak[0] = cpu_flag[0];
				bak[1] = cpu_flag[1];
				cpu_flag[0] = 0;
				cpu_flag[1] = 0;
				
				if(getPushState(0, 4) || getPushState(1, 4)) fast = 5;
				if(!(getPressState(0, 4) || getPressState(1, 4))) fast = 0;
				if(!fast && (getPressState(0, 0) || getPressState(1, 0))) fast = 3;
				if(!fast && (getPressState(0, 1) || getPressState(1, 1))) fast = 1;
				if(getPushState(0, 5) || getPushState(1, 5)) flag = 1;
				if(getPushState(0, 7) || getPushState(1, 7)) {
					PlaySE(se_shaki);
					fast = 0;
					replayauto = 0;
				}
				
				cpu_flag[0] = bak[0];
				cpu_flag[1] = bak[1];
				playback = 1;
			}
			
			// フィールド背景
			viewFieldBackground();
			
			// スタッフロール
			if(ending[0] || ending[1]) {
				for(i = 0; i < fast + 1; i++) {
					staffRoll(0);
					if(maxPlay) staffRoll(1);
				}
			}
			
			// フィールド表示
			viewField();
			
			// ゲーム処理
			for(i = 0; i < fast + 1; i++) {
				playerExecute();
				if(i > 0) objectExecute();
			}
			
			// NEXTとHOLDを表示
			for(i = 0; i <= maxPlay; i++) {
				if(stat[i] != 0) {
					viewNextBlock(i);
					viewHoldBlock(i);
				}
			}
			
			// フィールド枠を表示
			viewFieldFrame(0, 0);
			if(maxPlay) viewFieldFrame(1, 0);
			
			// 演出処理
			objectExecute();
			
			// スコア表示
			viewScore();
			
			// ポーズ・捨てゲーなど
			lastProc();
			
			// flag変数が1だったらタイトルに戻る
			if(flag > 0) {
				ReleaseAllBGM();
				StopAllWave();
				if(playback) loadGeneralConfigData();
				for(i = 0; i < 64; i++) TextLayerOff(i);
				executePlugin(0, 37, &dummy);
				if(maxPlay) executePlugin(1, 37, &dummy);
				break;
			}
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   タイトル
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void title() {
	int		player, mode, game, i, democ;
	
	// 初期設定
	count = 0;
	democ = 0;
	mode = 0;
	game = 0;
	
	demo = 0;
	playback = 0;
	replayauto = 0;
	
	backno = 0;
	bgfadesw = 0;
	bgfadelv = 0;
	bgfadebg = 0;
	firstbackno = 0;
	
	gameAllInit();
	
	maxPlay = 0;
	setFieldPosition(0, 0);
	setFieldPosition(1, 2);
	
	resetSoundVolume();
	
	engineVer = c_engineVer;
	
	// ネットプレイ中だったら切断
	if(netplay) {
		tcpCleanup();
		netplay = 0;
	}
	
	// FPSを元に戻す
	if((normalfps != 0) && (GetFPS() != normalfps)) SetFPS(normalfps);
	
	// BGM再生
	if(enable_sysbgm) {
		bgmlv = 11;
		PlayBGM();
	}
	
	SetConstParam("EnablePause", 1);	// ここからポーズ有効
	
	// ループ開始
	loop {
		democ++;
		
		// キー入力
		spriteTime();
		KeyInput();
		
		// 背景を描く
		ExBltFast(sg_title, 0, 0);
		
		// 著作権表示
		printFontGrid(6, 28, "a 1998-2002 KENJI HOSHIMOTO", 0 );
		
		// バージョン表示
		printFontGrid(27, 14, "VERSION 1.60", 4 );
		printFontGrid(27, 15, "(2002/03/31)", 6 );
		
		sprintf(string[0], "%39s", versionStr);
		printFontGrid(0, 1, string[0], 4);
		
		// モード0: ボタン入力待ち
		if(mode == 0) {
			// スタートボタンを押してください
			if(count % 80 < 40) ExBltRect(sg_gametext, 53, 154, 0, 204, 213, 19);
			
			// どちらかのスタートボタンが押されたらモード1へ
			for(player = 0; player <= maxPlay; player++) {
				if(getPushState(player, 4)) {
					democ = 0;
					PlaySE(se_kettei);
					mode = 1;
				}
			}
		}
		// モード1: モードセレクト
		else if(mode == 1) {
			// モード一覧表示
			printFontGrid(13, 18 + game * 2, "b", 2);
			
			printFontGrid(14, 18, "GAME START", 2 * (game == 0));
			printFontGrid(14, 20, "REPLAY",     2 * (game == 1));
			printFontGrid(14, 22, "CONFIG",     2 * (game == 2));
			
			// どちらかのジョイスティックでモードセレクト
			for(player = 0; player <= maxPlay; player++) {
				// 上へ
				if(getPushState(player, 0)) {
					PlaySE(se_move);
					game--;
					if(game < 0) game = 2;
				}
				
				// 下へ
				if(getPushState(player, 1)) {
					PlaySE(se_move);
					game++;
					if(game > 2) game = 0;
				}
				
				// キャンセル
				if(getPushState(player, 5)) {
					democ = 0;
					mode = 0;
				}
				
				// 決定
				if(getPushState(player, 4)) {
					StopAllBGM();
					PlaySE(se_kettei);
					mode = 0;
					
					// ゲームスタート
					if(game == 0) {
						if(selectRuleAndMode(0)) return;
					}
					// リプレイ
					if(game == 1) {
						if(selectReplay()) return;
					}
					// コンフィグ
					if(game == 2) {
						config_mainmenu();
					}
				}
			}
		}
		// モード2: ループから抜ける
		else {
			break;
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ルール・モード選択
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int selectRuleAndMode(int player) {
	int i, j, k, page, max, param;
	int crots, cmode;
	
	crots = lastrots;
	cmode = lastmode;
	if(crots >= plugin_count_rule) crots = 0;
	if(cmode >= plugin_count_mode) cmode = 0;
	page = 0;
	
	rots[0] = -2;
	rots[1] = -2;
	gameMode[0] = -2;
	gameMode[1] = -2;
	
	// BGM再生
	if(enable_sysbgm) {
		bgmlv = 12;
		PlayBGM();
	}
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		if(page == 0) {
			printFontGrid(1, 1, "SELECT 1P ROTATION RULE", 2);
			
			if(plugin_count_rule == 0) {
				printFontGrid(1, 3, "NO RULE PLUGIN FOUND", 2);
			} else {
				// メニュー表示
				max = plugin_count_rule;
				if(max > 20) max = 20;
				j = 0;
				k = (crots / 20) * 20;
				
				for(i = 0; i < max; i++) {
					sprintf(string[0], "%03d:", k + i + 1);
					printFontGrid(2, 3 + j, string[0], 7 * (crots == k + i));
					printFontGrid(6, 3 + j, plugin_name_rule[k + i], 7 * (crots == k + i));
					if(crots == k + i) printFontGrid(1, 3 + j, "b", 7);
					j++;
				}
			}
			
			// カーソル移動
			padRepeat2(player);
			
			// ↑
			if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
			if(getPressState(player, 0)) {
				PlaySE(se_move);
				crots--;
				if(crots < 0) crots = plugin_count_rule - 1;
			}
			
			// ↓
			if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
			if(getPressState(player, 1)) {
				PlaySE(se_move);
				crots++;
				if(crots > plugin_count_rule - 1) crots = 0;
			}
			
			// キャンセル
			if(getPushState(player, 5)) {
				StopAllBGM();
				return 0;
			}
			// 決定
			else if(getPushState(player, 4)) {
				if(plugin_count_rule > 0) {
					PlaySE(se_kettei);
					rots[player] = crots;
					
					param = 1;
					executePlugin(player, 16, &param);	// プラグイン呼び出し
					
					if(param) page++;
				}
			}
		} else if(page == 1) {
			printFontGrid(1, 1, "SELECT GAME MODE", 4);
			
			if(plugin_count_mode == 0) {
				printFontGrid(1, 3, "NO MODE PLUGIN FOUND", 2);
			} else {
				// メニュー表示
				max = plugin_count_mode;
				if(max > 20) max = 20;
				j = 0;
				k = (cmode / 20) * 20;
				
				for(i = 0; i < max; i++) {
					sprintf(string[0], "%03d:", k + i + 1);
					printFontGrid(2, 3 + j, string[0], 7 * (cmode == k + i));
					printFontGrid(6, 3 + j, plugin_name_mode[k + i], 7 * (cmode == k + i));
					if(cmode == k + i) printFontGrid(1, 3 + j, "b", 7);
					j++;
				}
			}
			
			// カーソル移動
			padRepeat2(player);
			
			// ↑
			if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
			if(getPressState(player, 0)) {
				PlaySE(se_move);
				cmode--;
				if(cmode < 0) cmode = plugin_count_mode - 1;
			}
			
			// ↓
			if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
			if(getPressState(player, 1)) {
				PlaySE(se_move);
				cmode++;
				if(cmode > plugin_count_mode - 1) cmode = 0;
			}
			
			// キャンセル
			if(getPushState(player, 5)) {
				PlaySE(se_move);
				
				param = 1;
				executePlugin(player, 16, &param);	// プラグイン呼び出し
				
				if(!param) page--;
			}
			// 決定
			else if(getPushState(player, 4)) {
				if(plugin_count_mode > 0) {
					PlaySE(se_kettei);
					gameMode[player] = cmode;
					
					maxPlay = 0;
					setFieldPosition(0, 0);
					setFieldPosition(1, 2);
					
					param = 1;
					executePlugin(player, 17, &param);	// プラグイン呼び出し
					
					if(param) {
						StopAllBGM();
						
						lastrots = crots;
						lastmode = cmode;
						saveGeneralConfigData();
						
						gameAllInit();
						
						playerInitial(0);
						versusInit(0);
						if(stat[0] == 0) stat[0] = 3;
						
						if(maxPlay) {
							gameMode[1] = gameMode[0];
							playerInitial(1);
							versusInit(1);
							if(stat[1] == 0) stat[1] = 3;
						}
						
						if(!english) sprintf(string[0], "ルール %s モード %s でゲーム開始", plugin_name_rule[crots], plugin_name_mode[cmode]);
						else sprintf(string[0], "Start new game (Rule:%s Mode:%s)", plugin_name_rule[crots], plugin_name_mode[cmode]);
						debugLogSystem(string[0]);
						
						return 1;
					}
				}
			}
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   最後にやる処理
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void lastProc() {
	int i, player;
	
	// 操作状況表示
	if(onRecord[0] && !pause[0] && !maxPlay) {
		if( (showctrl == 1) || ((showctrl == 2) && (playback) && (replayauto)) )
			showControl();
	}
	
	for(player = 0; player <= maxPlay; player++) {
		// ポーズ
		if(IsPushKey(pause_key[player]) | getJoyPushState(player, joy_pause_key[player])) {
			if(onRecord[player] && !netplay) {
				pause[player] = !pause[player];
				
				if(pause[player]) {
					PlaySE(se_pause);
					StopSE(se_hurryup);
				}
				
				if(bgmtype == 3) {
					if(IsPlayMIDI())
						PauseMIDI();
					else
						ReplayMIDI();
				} else if(bgmtype != 0) {
					if(IsPlayWave(bgm_plane[bgmlv]))
						PauseWave(bgm_plane[bgmlv]);
					else
						ReplayWave(bgm_plane[bgmlv]);
				}
				
				if(maxPlay) pause[1 - player] = pause[player];
			}
		}
		
		// リトライ
		if(!playback && !netplay) {
			if(IsPushKey(retry_key[player]) | getJoyPushState(player, joy_retry_key[player])) {
				retrygame(player);
			}
		}
		
		// 捨てゲー
		if(IsPushKey(giveup_key[player]) | getJoyPushState(player, joy_giveup_key[player])) {
			flag = 1;
		}
		
		// デバッグメニュー
		if(!playback && !netplay) {
			if(IsPushKey(extra_key[player]) | getJoyPushState(player, joy_extra_key[player])) {
				debugMenu(1);
			}
		}
		
		executePlugin(player, 35, &dummy);
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   初期化処理
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void gameAllInit() {
	back_acnt = 0;
	bgmlv = 0;
	fadelv = 0;
	fast = 0;
	count = 0;
	fldsizex = 10;
	fldsizey = 22;
	onRecord[0] = 0;
	onRecord[1] = 0;
	objectClear();
}

void playerInitial(int player) {
	int i, j;
	int param;
	
	param = 0;
	executePlugin(player, 2, &param);	// プラグイン呼び出し
	if(param) return;
	
	GiziSRand(player);		// 乱数のシード生成
	
	engineVer = c_engineVer;
	
	gameTimer[player] = 0;
	timeOn[player] = 0;
	recTimer[player] = 0;
	onRecord[player] = 0;
	
	nextc[player] = 0;
	pinch[player] = 0;
	pause[player] = 0;
	
	hidden[player] = 0;
	hiddenti[player] = 0;
	hiddentm[player] = 0;
	hiddeny[player] = fldsizey;
	hiddenti[player] = 0;
	hiddenc[player] = 0;
	
	if(engineVer >= 3) {
		wait1[player] = 25;
		wait2[player] = 40;
		wait3[player] = 30;
		waitt[player] = 16;
	} else {
		wait1[player] = 26;
		wait2[player] = 40;
		wait3[player] = 28;
		waitt[player] = 15;
	}
	wait4[player] = -1;
	wait5[player] = -1;
	
	sp[player] = 1;
	speedtype[player] = 0;
	
	enable_combo[player] = 0;
	combo[player] = 0;
	combo2[player] = 0;
	combo3[player] = 0;
	hebocombo[player] = 0;
	
	for(i = 0; i < 4; i++) line_count[player * 4 + i] = 0;
	
	stat[player] = 0;
	resetStatc(player);
	
	resetField(player);
	
	upLines[player] = 0;
	framecolor[player] = 1;
	frame_decoration[player] = 0;
	field_spin[player] = -1;
	
	for(i = 0; i < 7; i++) {
		blockcolor[player * 7 + i] = i + 1;
		next_offset[player * 7 + i] = 0;
		next_s_offset[player * 7 + i] = 0;
	}
	
	blockgraphics[player] = 0;
	
	for(i = 0; i < 4; i++) {
		current_color[i + player * 4] = 0;
		current_color_m[i + player * 4] = 0;
	}
	
	current_oblk[player] = 0;
	current_item[player] = 0;
	
	for(i = 0; i < 6; i++) {
		for(j = 0; j < 4; j++) next_color[player * 24 + i * 4 + j] = 0;
		next_oblk[player * 6 + i] = 0;
		next_item[player * 6 + i] = 0;
	}
	
	block_init_x_pos[player] = 3;
	spawntype[player] = spawn_y_type;
	if(!spawntype[player]) {
		block_init_y_pos[player] = 1;
	} else {
		block_init_y_pos[player] = -1;
	}
	
	block_init_rt[player] = 0;
	
	last_command[player] = 0;
	
	hold[player] = -1;
	if(!disable_hold) dhold[player] = 0;
	else dhold[player] = 2;
	hold_count[player] = 0;
	
	for(i = 0; i < 4; i++) hold_color[i + player * 4] = 0;
	hold_oblk[player] = 0;
	hold_item[player] = 0;
	
	harddrop[player] = 0;
	softdrop[player] = 0;
	bk_D[player] = 0;
	softd_dropflag[player] = 0;
	softd_score[player] = 0;
	
	up_flag[player] = 0;
	down_flag[player] = 0;
	
	rot_reverse[player] = 0;
	lockreset[player] = 0;
	rotcount[player] = 0;
	movecount[player] = 0;
	rotlimit[player] = 0;
	movelimit[player] = 0;
	are[player] = 1;
	lockflash[player] = 2;
	lock_up[player] = 0;
	lock_down[player] = 1;
	softspeed[player] = 1;
	self_lock_sound[player] = 0;
	max_waitt[player] = 99;
	RepeatDelay[player] = 0;
	repeatcount[player] = 0;
	fastlrmove[player] = 0;
	initial_rotate[player] = 1;
	initial_hold[player] = 1;
	enable_wallkick[player] = 1;
	
	disp_blkline[player] = 1;
	
	ready_start[player] = n_ready_start;
	ready_end[player] = n_ready_end;
	go_start[player] = n_go_start;
	go_end[player] = n_go_end;
	
	ready_count[player] = 0;
	
	kickc[player] = 0;
	kicktype[player] = 0;
	
	ghost[player] = 1;
	
	ndelay[player] = 1;
	
	sdrop[player] = 0;
	qdrop[player] = 0;
	if(engineVer <= 5) cmbpts[player] = 0;
	else cmbpts[player] = 1;
	qput[player] = 0;
	
	oblk_spawn[player] = 0;
	oblk_bg[player] = 0;
	hnext[player] = dispnext;
	
	IsBig[player] = 0;
	BigMove[player] = 0;
	
	if(beffect_speed != 0) effectspeed[player] = beffect_speed;
	else effectspeed[player] = 1;
	
	are_skipflag[player] = 0;
	show_all_break_effect[player] = (breaktype != 2);
	perase_show_bonus[player] = 0;
	
	ending[player] = 0;
	edrec[player] = 0;
	fastroll[player] = 0;
	ending_timeOn[player] = 0;
	staff_c[player] = 0;
	endtime[player] = 0;
	staff_type[player] = Rand(2);
	
	shadowtime[player] = -1;
	
	nextskip[player] = 0;
	
	item_waiting[player] = 0;
	enable_item_hold[player] = 0;
	item_name[player] = 0;
	item_coming[player] = 0;
	
	bdowncnt[player] = 0;
	brotcount[player] = 0;
	bactivetime[player] = 0;
	bfallflag[player] = 0;
	bfallcount[player] = 0;
	
	tspin_type[player] = 0;
	tspin_flag[player] = 0;
	b_to_b_type[player] = 0;
	b_to_b_count[player] = 0;
	
	fadelv = 0;
	
	isfmirror[player] = 0;
	fmirror_cnt[player] = -20;
	stopmirror_flag[player] = 0;
	
	current_rollroll[player] = 0;
	rollroll_interval[player] = 30;
	
	cpu_best_x[player] = -3;
	cpu_best_y[player] = 0;
	cpu_best_r[player] = 0;
	cpu_best_p[player] = 0;
	cpu_hold[player] = 0;
	for(i = 0; i < 10; i++) cpu_ctrl[player * 10 + i] = 0;
	cpu_flag[player] = 0;
	cpu_speed[player] = 0;
	cpu_frame[player] = 0;
	
	blkshadow_direction[player] = blockshadow - 1;
	nextc_max[player] = 1400;
	
	multicolor_enable[player] = 0;
	multicolor_ratio[player] = 50;
	
	executePlugin(player, 18, &dummy);	// プラグイン呼び出し
}

// NEXTブロックを生成
void versusInit(int player) {
	int param;
	
	param = 0;
	executePlugin(player, 3, &param);	// プラグイン呼び出し
	
	if(!param) {
		if(nextblock <= 7) heboNextInit(player);
		else if(nextblock == 8) tgmNextInit(player, 0);
		else if(nextblock == 9) tgmNextInit(player, 1);
		else if(nextblock == 10) guidelineNextInit(player);
		else if(nextblock == 11) userNextInit(player);
		else if(nextblock == 12) icheatNextInit(player);
		else eightBagNextInit(player);
	}
	
	setNextBlockColor(player, 1);	// NEXTブロックの色を設定
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   プレイヤーのステータスに応じて各処理を実行
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void playerExecute() {
	int i, j, player, temp;
	int param;
	
	// ピンチ音
	if((pinch[0] && onRecord[0]) || (pinch[1] && onRecord[1] && maxPlay)) {
		if(!IsPlayWave(se_pinch)) PlaySE(se_pinch);
	} else {
		StopSE(se_pinch);
	}
	
	for(i = 0; i <= maxPlay; i++) {
		player = i;
		
		for(j = 0; j < 10; j++) cpu_ctrl[player * 10 + j] = 0;
		
		param = 0;
		executePlugin(player, 4, &param);	// プラグイン呼び出し
		if(param) goto skip;
		
		if(pause[player]) {
			if(!getPressState(player, 6)) {
				if(count % 60 > 10) printTinyFont(foffset[player] + 35, fyoffset[player] + 120, "PAUSE");
				
				if(playback && replayauto) {
					if(count % 120 > 60)
						printTinyFont(foffset[player] + 10, fyoffset[player] + 201, "PRESS B TO EXIT");
					else
						printTinyFont(foffset[player] + 10, fyoffset[player] + 201, "PRESS D TO PLAY");
				} else {
					if((count % 120 > 60) && (!playback))
						printTinyFont(foffset[player], fyoffset[player] + 201, "PRESS E+F TO RETRY");
					else
						printTinyFont(foffset[player], fyoffset[player] + 201, "PRESS A+B TO GIVEUP");
				}
			}
			// E+F
			if(getPressState(player, 8) && getPressState(player, 9) && !playback) {
				retrygame(player);
			}
			// A+B
			if(getPressState(player, 4) && getPressState(player, 5)) {
				flag = 1;
			}
			goto skip;
		}
		
		padRepeat(player);	// 横溜め
		
		jump(stat[i],l00,l01,l02,l03,l04,l05,l06,l07,l08,l09,l10,l11);
		
		l00: 								// 00 -> タイトルに戻る
				goto next;
		l01: 								// 01 -> 何もしない
				goto next;
		l02: statCustom(player);			// 02 -> モードプラグイン用ステータス
				goto next;
		l03: statReady(player);				// 03 -> Ready!?
				goto next;
		l04: statMove(player);				// 04 -> ブロック移動中
				goto next;
		l05: statErase(player);				// 05 -> 待ち時間処理
				goto next;
		l06: statEraseBlock(player);		// 06 -> ブロック消去
				goto next;
		l07: statGameOver(player);			// 07 -> ゲームオーバー演出
				goto next;
		l08: statResult(player);			// 08 -> 結果表示
				goto next;
		l09: statGameOver2(player);			// 09 -> ゲームオーバー表示
				goto next;
		l10: statEnding(player);			// 10 -> エンディング
				goto next;
		l11: statReplaySave(player);		// 11 -> リプレイ保存画面
				goto next;
		
		next:
		increment_time(player);
		
		skip:
	}
	
	// BGMフェードアウト処理
	if(bgmtype != 0) bgmFadeout();
	
	// 両者ゲームオーバーならタイトルへ
	if( (stat[0] == 0) && ((stat[1] == 0) || (!maxPlay)) ) flag = 1;
}

// タイムを増加させる
void increment_time(int player) {
	int i, j, temp, param;
	
	param = 0;
	executePlugin(player, 27, &param);
	if(param) return;
	
	// リプレイ記録
	if(onRecord[player]) {
		if(recTimer[player] < 60 * 60 * 30) {
			temp = 0;
			
			for(j = 0; j < 10; j++) {
				temp = BitSet(temp, j, getPressState(player, j));
				temp = BitSet(temp, j + 10, getPushState(player, j));
			}
			
			replayData[player * 108000 + recTimer[player]] = temp;
		}
		
		recTimer[player]++;	// リプレイ用カウンタに1/60秒プラス
	}
	
	// タイマーが動作していれば時間に1/60秒プラス
	if(timeOn[player]) {
		gameTimer[player]++;
	}
	
	// エンディング中ならばエンディング経過時間に1/60秒プラス
	if((ending_timeOn[player]) && (ending[player] == 2) && (onRecord[player])) {
		if(fastroll[player] == 1)
			edrec[player] = edrec[player] + 2;
		else
			edrec[player]++;
	}
	
	// フィールドタイマーのカウントダウン
	if(hidden[player] == 8) {
		for(i = 0; i < fldsizey; i++)
			for(j = 0; j < fldsizex; j++)
				if(getFieldBlockT(player, j, i) > 0)
					setFieldBlockT(player, j, i, getFieldBlockT(player, j, i) - 1);
	} else if(hidden[player] == 9) {
		for(i = 0; i < fldsizey; i++)
			for(j = 0; j < fldsizex; j++)
				if(getFieldBlockT(player, j, i) < 0)
					setFieldBlockT(player, j, i, getFieldBlockT(player, j, i) + 10);
	}
	
	// エフェクトスピード自動調整
	if(!beffect_speed) {
		if((wait1[player] / 2) + wait2[player] <= 0)
			effectspeed[player] = 5;
		else if((wait1[player] / 2) + wait2[player] <= 3)
			effectspeed[player] = 4;
		else if((wait1[player] / 2) + wait2[player] <= 5)
			effectspeed[player] = 3;
		else if((wait1[player] / 2) + wait2[player] <= 10)
			effectspeed[player] = 2;
		else
			effectspeed[player] = 1;
	}
	
	executePlugin(player, 28, &dummy);
}

// スタッフロール描画
void staffRoll(int player) {
	int param;
	
	if((ending_timeOn[player]) && (ending[player] == 2) && (onRecord[player]) && (!pause[player])) {
		param = 0;
		executePlugin(player, 36, &param);
		
		if(!param) {
			// スタッフロール経過時間を増加させる
			if(fastroll[player] == 1)
				endtime[player] = endtime[player] + 2;
			else
				endtime[player]++;
			
			// 描画する
			ExBltRect(sg_staffroll[staff_type[player]], foffset[player] + 8, 40, 0, staff_c[player] / 2, 80, 160);
			
			// 移動
			if((endtime[player] % 2 == 0) && (endtime[player] < 3100)) staff_c[player]++;
		}
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.02 - モードプラグイン用ステータス
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statCustom(int player) {
	executePlugin(player, 68, &dummy);
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.03 - Ready!?
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statReady(int player) {
	int i, param;
	
	param = 0;
	executePlugin(player, 5, &param);	// プラグイン呼び出し
	if(param) return;
	
	// READY回数＋１
	if(!statc[player * 10]) ready_count[player]++;
	
	// 最初のフレームの横溜めを記録／再現
	if((ready_count[player] == 1) && (onRecord[player]) && (statc[player * 10] == 0)) {
		if(playback) {
			mp[player]  = mps[player * 2    ];
			mpc[player] = mps[player * 2 + 1];
		} else {
			mps[player * 2    ] =  mp[player];
			mps[player * 2 + 1] = mpc[player];
		}
	}
	
	// 最初の背景を覚えておく
	if((ready_count[player] == 1) && (statc[player * 10] == 0)) firstbackno = backno;
	
	// READY→GOを表示
	if((statc[player * 10] >= ready_start[player]) && (statc[player * 10] < ready_end[player])) {
		ExBltRect(sg_gametext, foffset[player] - 2, fyoffset[player] + 91, 200,  0, 100, 50);	// READY
	} else if((statc[player * 10] >= go_start[player]) && (statc[player * 10] < go_end[player])) {
		ExBltRect(sg_gametext, foffset[player] - 2, fyoffset[player] + 92, 200, 50, 100, 50);	// GO
	}
	if(statc[player * 10] == ready_start[player]) {
		if(!IsPlayWave(se_ready)) PlaySE(se_ready);
	}
	if(statc[player * 10] == go_start[player]) {
		if(!IsPlayWave(se_go)) PlaySE(se_go);
	}
	
	// ゲームスタート
	if(statc[player * 10] >= go_end[player]) {
		// スタート時の横溜めを記録／再現
		if((ready_count[player] == 1) && (!onRecord[player])) {
			if(playback) {
				mp[player]  = mps[player * 2    ];
				mpc[player] = mps[player * 2 + 1];
			} else {
				mps[player * 2    ] =  mp[player];
				mps[player * 2 + 1] = mpc[player];
			}
		}
		
		// タイマーON
		timeOn[player] = 1;
		onRecord[player] = 1;
		
		executePlugin(player, 38, &dummy);
		
		// ブロック移動処理へ
		stat[player] = 4;
		resetStatc(player);
		return;
	} else if(nextskip[player]) {
		// ツモスキップ
		onRecord[player] = 1;	// リプレイ記録開始
		
		if(getPushState(player, 7)) {
			PlaySE(se_hold);
			
			hold[player] = getNextBlock(player, 0);
			for(i = 0; i < 4; i++) hold_color[i + player * 4] = next_color[player * 24 + i];
			hold_oblk[player] = next_oblk[player * 6];
			
			nextc[player] = (nextc[player] + 1) % nextc_max[player];
			setNextBlockColor(player, 0);
			
			hold_count[player]++;
			dhold[player] = 0;
		}
	}
	
	// カウンタ増加
	statc[player * 10]++;
}

// ブロック消去判定
int blockEraseJudge(int player) {
	int		i, j, sr, lines;
	lines = 0;

	for(i = 0; i < fldsizey; i++) {
		sr = 1;
		
		for(j = 0; j < fldsizex; j++)
			if(getFieldBlock(player, j, i) == 0) {
				sr = 0;
				break;
			}
		
		erase[i + player * fldsizey] = sr;
		lines = lines + sr;
	}

	return lines;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.05 - 時間稼ぎ & レベルアップ判定
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statErase(int player) {
	int i;
	int param;
	
	param = 0;
	executePlugin(player, 10, &param);	// プラグイン呼び出し
	if(param) return;
	
	// 上入れ制限＆下入れ制限解除
	if(engineVer >= 3) {
		if( !getPressState(player, 0) || (!downtype) || ((downtype == 1) && (!is20G(player)) && (are[player] != 0)) )
			up_flag[player] = 0;
		if( !getPressState(player, 1) || (!downtype) || ((downtype == 1) && (!is20G(player)) && (are[player] != 0)) )
			down_flag[player] = 0;
	} else {
		if(!getPressState(player, 0) || (!downtype) || ((downtype == 1) && (sp[player] < 1200))) up_flag[player] = 0;
		if(!getPressState(player, 1) || (!downtype) || ((downtype == 1) && (sp[player] < 1200))) down_flag[player] = 0;
	}
	
	// せり上がり
	if(upLines[player]) {
		PlaySE(se_up);
		upLineProc(player);
		upLines[player]--;
		return;
	}
	
	statc[player * 10]--;
	
	// AREスキップ
	if((are[player] == 2) && (harddrop[player])) {
		if(getPushState(player, 0) || getPushState(player, 1) || getPushState(player, 2) || getPushState(player, 3) || 
		   getPushState(player, 4) || getPushState(player, 5) || getPushState(player, 6) || getPushState(player, 8))
		{
			statc[player * 10] = -1;
		}
	}
	if((are[player] == 2) && (are_skipflag[player])) {
		if(getPressState(player, 0) || getPressState(player, 1) || getPressState(player, 2) || getPressState(player, 3) || 
		   getPressState(player, 4) || getPressState(player, 5) || getPressState(player, 6) || getPressState(player, 8))
		{
			statc[player * 10] = -1;
			are_skipflag[player] = 0;
		}
	}
	
	if((ending[player] == 1) || (ending[player] == 4)) {
		// エンディング突入
		stat[player] = 10;
		resetStatc(player);
		statEnding(player);
	} else if((statc[player * 10] < 0) || (!are[player])) {
		// ミラー
		if(fldMirrorProc(player)) return;
		
		stat[player] = 4;	// ブロック移動処理へ
		resetStatc(player);
		statMove(player);
	} else {
		hiddenProc(player);
	}
}

// せり上がり処理
void upLineProc(int player) {
	int i, j;
	int param;
	
	param = 0;
	executePlugin(player, 69, &param);	// プラグイン呼び出し
	if(param) return;
	
	// フィールドを上にずらす
	for(i = 0; i < fldsizey - 1; i++) {
		for(j = 0; j < fldsizex; j++) {
			setFieldBlock(player, j, i, getFieldBlock(player, j, i + 1));
			setFieldBlockT(player, j, i, getFieldBlockT(player, j, i + 1));
			setFieldBlockO(player, j, i, getFieldBlockO(player, j, i + 1));
			setFieldBlockL(player, j, i, getFieldBlockL(player, j, i + 1));
			setFieldBlockI(player, j, i, getFieldBlockI(player, j, i + 1));
		}
	}
	
	// 枠内出現の場合は一番上を空白にする
	if(!spawntype[player]) {
		for(j = 0; j < fldsizex; j++) {
			setFieldBlock(player, j, 0, 0);
			setFieldBlockT(player, j, 0, 0);
			setFieldBlockO(player, j, 0, 0);
			setFieldBlockL(player, j, 0, 0);
			setFieldBlockI(player, j, 0, 0);
		}
	}
	
	// 一番下にせり上がりブロックを作る
	for(j = 0; j < fldsizex; j++) {
		setFieldBlock(player, j, fldsizey - 1, fldu[j + player * (fldsizex * fldsizey)]);
		setFieldBlockT(player, j, fldsizey - 1, shadowtime[player]);
		setFieldBlockO(player, j, fldsizey - 1, oblk_spawn[player]);
		setFieldBlockL(player, j, fldsizey - 1, 0);
		setFieldBlockI(player, j, fldsizey - 1, 0);
	}
	
	// せり上がりフィールドを上にずらす
	for(i = 0; i < fldsizey - 1; i++) {
		for(j = 0; j < fldsizex; j++) {
			fldu[j + i * fldsizex + player * (fldsizex * fldsizey)] = fldu[j + (i + 1) * fldsizex + player * (fldsizex * fldsizey)];
		}
	}
	
	// せり上がりフィールドの一番下を空白にする
	for(j = 0; j < fldsizex; j++) {
		fldu[j + (fldsizey - 1) * fldsizex + player * (fldsizex * fldsizey)] = 0;
	}
}

// ミラー処理
int fldMirrorProc(int player) {
	int i, j;
	
	// 強制停止
	if((stopmirror_flag[player]) && (fmirror_cnt[player] == -20)) {
		isfmirror[player] = 0;
		stopmirror_flag[player] = 0;
		field_spin[player] = -1;
		return 0;
	}
	
	if(isfmirror[player]) {
		if(fmirror_cnt[player] <= 20) {
			if(fmirror_cnt[player] == -20) {
				// フィールドをバッファに確保
				for(i = 0; i < fldsizey; i++) {
					for(j = 0; j < fldsizex; j++) {
						// バッファにコピー
						fldbuf[j + i * fldsizex + player * (fldsizex * fldsizey)] = getFieldBlock(player, j, i);
						fldtbuf[j + i * fldsizex + player * (fldsizex * fldsizey)] = getFieldBlockT(player, j, i);
						fldobuf[j + i * fldsizex + player * (fldsizex * fldsizey)] = getFieldBlockO(player, j, i);
						fldlbuf[j + i * fldsizex + player * (fldsizex * fldsizey)] = getFieldBlockL(player, j, i);
						fldibuf[j + i * fldsizex + player * (fldsizex * fldsizey)] = getFieldBlockI(player, j, i);
						
						// ブロックを消す
						setFieldBlock(player, j, i, 0);
						setFieldBlockT(player, j, i, 0);
						setFieldBlockO(player, j, i, 0);
						setFieldBlockL(player, j, i, 0);
						setFieldBlockI(player, j, i, 0);
					}
				}
			} else {
				// 反転
				if((fmirror_cnt[player] > 0) && (fmirror_cnt[player] % 2 == 0)) {
					j = fmirror_cnt[player] / 2 - 1;
					
					for(i = 0; i < fldsizey; i++) {
						setFieldBlock(player, fldsizex - j - 1, i, fldbuf[j + i * fldsizex + player * (fldsizex * fldsizey)]);
						setFieldBlockT(player, fldsizex - j - 1, i, fldtbuf[j + i * fldsizex + player * (fldsizex * fldsizey)]);
						setFieldBlockO(player, fldsizex - j - 1, i, fldobuf[j + i * fldsizex + player * (fldsizex * fldsizey)]);
						setFieldBlockL(player, fldsizex - j - 1, i, fldlbuf[j + i * fldsizex + player * (fldsizex * fldsizey)]);
						setFieldBlockI(player, fldsizex - j - 1, i, fldibuf[j + i * fldsizex + player * (fldsizex * fldsizey)]);
					}
					
					ExBltFastRect(sg_spr, foffset[player] + 8 + ((fldsizex - j - 1) * 8), fyoffset[player] + 40, 0, 165, 8, 160);
				}
			}
			fmirror_cnt[player]++;
			field_spin[player]++;
			return 1;
		} else if(fmirror_cnt[player] <= 24) {
			// 4フレームの待ち時間
			fmirror_cnt[player]++;
			field_spin[player]++;
			return 1;
		} else {
			// 終了
			fmirror_cnt[player] = -20;
			field_spin[player] = -1;
			isfmirror[player] = 0;
		}
	}
	
	return 0;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.06 - ブロック消去
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statEraseBlock(int player) {
	int i, j, k, l, x, y, lines, temp;
	int hardblock, itemerase;
	int param[2];
	
	param[0] = 0;
	executePlugin(player, 11, &param);	// プラグイン呼び出し
	if(param[0]) return;
	
	if(statc[player * 10] != 0) {
		hiddenProc(player);
	}
	
	// 上入れ制限＆下入れ制限解除
	if(engineVer >= 3) {
		if( !getPressState(player, 0) || (!downtype) || ((downtype == 1) && (!is20G(player)) && (are[player] != 0)) )
			up_flag[player] = 0;
		if( !getPressState(player, 1) || (!downtype) || ((downtype == 1) && (!is20G(player)) && (are[player] != 0)) )
			down_flag[player] = 0;
	} else {
		if(!getPressState(player, 0) || (!downtype) || ((downtype == 1) && (sp[player] < 1200))) up_flag[player] = 0;
		if(!getPressState(player, 1) || (!downtype) || ((downtype == 1) && (sp[player] < 1200))) down_flag[player] = 0;
	}
	
	if(statc[player * 10] == 0) {
		lines = 0;
		itemerase = 0;	// アイテム消去フラグ
		
		if(current_item[player]) {
			itemerase = 1;
			item_waiting[player] = current_item[player];
			objectCreate(player, 5, foffset[player] + 8 + (bx[player] * 8), fyoffset[player] + 24 + (by[player] * 8), 0, 0, 0, 0);
		}
		
		// ブロックを消す
		for(i = 0; i < fldsizey; i++) {
			if(erase[i + player * fldsizey]) {
				lines++;
				
				for(x = 0; x < fldsizex; x++) {
					hardblock = 0;	// ハードブロック消去フラグ
					
					// 消去エフェクトを表示
					temp = (show_all_break_effect[player] != 0);
					temp = (temp) || (getFieldBlock(player, x, i) >= 10);
					temp = (temp) || ((lines & 1 != 0) && (x & 1 == 1)) || ((lines & 1 == 0) && (x & 1 == 0));
					
					if((temp != 0) && (breaktype != 0) && (!getFieldBlockO(player, x, i))) {
						objectCreate(player, 1, foffset[player] + 8 + (x * 8), fyoffset[player] + (i + 3) * 8, (x - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + lines * 250, getFieldBlock(player, x, i) - 1, 100);
					}
					
					// プラグインを呼ぶ
					param[0] = x;
					param[1] = i;
					executePlugin(player, 53, &param);
					
					// 消えるブロックがアイテム
					if(getFieldBlockI(player, x, i) != 0) {
						if(getFieldBlockI(player, x, i) == fldihardno) {
							// ハードブロック
							hardblock = 1;
							erase[i + player * fldsizey] = 0;
							setFieldBlockO(player, x, i, 0);
						} else if((!itemerase) && (getFieldBlockI(player, x, i) < fldihardno)) {
							// アイテム
							itemerase = 1;
							item_waiting[player] = getFieldBlockI(player, x, i);
							objectCreate(player, 5, foffset[player] + 8 + (x * 8), fyoffset[player] + (i + 3) * 8, 0, 0, 0, 0);
						}
					}
					
					// ブロックを消す
					if(!hardblock) {
						setFieldBlock(player, x, i, 0);
						setFieldBlockT(player, x, i, 0);
						setFieldBlockO(player, x, i, 0);
						setFieldBlockL(player, x, i, 0);
						setFieldBlockI(player, x, i, 0);
					}
				}
			}
		}
		
		// ビッグ時はライン数半分
		if(IsBig[player]) lines = lines / 2;
		
		// ライン消去効果音を鳴らす
		if((lines >= 1) && (lines <= 4)) PlaySE(se_erase[lines - 1]);
		else PlaySE(se_erase[0]);
		
		// 歓声
		if(hebocombo[player]) PlaySE(se_cheer);
		else if(lines >= 4) PlaySE(se_applause);
		
		// ライン消し回数増加
		if((lines >= 1) && (lines <= 4)) line_count[player * 4 + (lines - 1)]++;
		
		// コンボ回数増加
		if(enable_combo[player]) {
			if(lines >= 4) hebocombo[player]++;
			combo[player]++;
			cmbpts[player] = cmbpts[player] + (lines * 2 - 2);
			
			if(lines >= 2) {
				combo2[player]++;
				combo3[player]++;
			} else {
				combo3[player] = 0;
			}
		}
		
		// BACK TO BACK
		if(b_to_b_type[player]) {
			if( ((b_to_b_type[player] != 3) && (lines >= 4)) || ((b_to_b_type[player] != 2) && (tspin_flag[player])) )
				b_to_b_count[player]++;
			else
				b_to_b_count[player] = 0;
		}
		
		statc[player * 10]++;
		
		param[0] = lines;
		param[1] = itemerase;
		executePlugin(player, 12, &param);	// プラグイン呼び出し
	}
	
	if(statc[player * 10] >= wait2[player]) {
		// 上にあったブロックを下まで下ろす
		lines = downFloatingBlocks(player);
		pinchCheck(player);
		
		// ビッグ時はライン数半分
		if(IsBig[player]) lines = lines / 2;
		
		PlaySE(se_gon);
		
		// HIDDENで見えなくなったラインを元に戻す
		hiddenti[player] = hiddenti[player] + lines;
		
		while(hiddenti[player] > 0) {
			hiddenti[player]--;
			hiddeny[player]++;
			
			if(hiddeny[player] > fldsizey) {
				hiddeny[player] = fldsizey;
				hiddentm[player] = 0;
			}
		}
		
		// アイテム存在のチェック
		scanItem(player);
		
		// 待ち時間処理へ
		stat[player] = 5;
		if(wait5[player] == -1) statc[player * 10] = wait1[player];
		else statc[player * 10] = wait5[player];
		
		executePlugin(player, 13, &lines);	// プラグイン呼び出し
	} else {
		// カウンタ増加
		statc[player * 10]++;
		
		// AREスキップ
		if((are[player] == 2) && (harddrop[player])) {
			if(getPushState(player, 0) || getPushState(player, 1) || getPushState(player, 2) || 
			   getPushState(player, 3) || getPushState(player, 4) || getPushState(player, 5) || 
			   getPushState(player, 6) || getPushState(player, 8))
			{
				statc[player * 10] = wait2[player];
				are_skipflag[player] = 1;
			}
		}
	}
}

// 上にあったブロックを下まで下ろす
int downFloatingBlocks(int player) {
	int i, k, l, y, lines;
	
	y = fldsizey - 1;
	lines = 0;
	
	for(i = 0; i < fldsizey; i++) {
		if(erase[y + player * fldsizey]) {
			// ブロックを1段上からコピー
			for(k = y; k > 0; k--) {
				for(l = 0; l < fldsizex; l++) {
					setFieldBlock(player, l, k, getFieldBlock(player, l, k - 1));
					setFieldBlockT(player, l, k, getFieldBlockT(player, l, k - 1));
					setFieldBlockO(player, l, k, getFieldBlockO(player, l, k - 1));
					setFieldBlockL(player, l, k, getFieldBlockL(player, l, k - 1));
					setFieldBlockI(player, l, k, getFieldBlockI(player, l, k - 1));
				}
				erase[k + player * fldsizey] = erase[(k - 1) + player * fldsizey];
			}
			
			// 一番上を空白にする
			for(l = 0; l < fldsizex; l++) {
				setFieldBlock(player, l, 0, 0);
				setFieldBlockT(player, l, 0, 0);
				setFieldBlockO(player, l, 0, 0);
				setFieldBlockL(player, l, 0, 0);
				setFieldBlockI(player, l, 0, 0);
			}
			erase[0 + player * fldsizey] = 0;
			
			lines++;
		} else {
			y--;
		}
	}
	
	return lines;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.07 - ゲームオーバー
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statGameOver(int player) {
	int i, j, block, c, tmp;
	int param;
	
	param = 0;
	executePlugin(player, 20, &param);
	if(param) return;
	
	// 最初のフレームの処理
	if(statc[player * 10 + 2] == 0) {
		timeOn[player] = 0;
		pinch[player] = 0;
		disp_blkline[player] = 0;
		StopSE(se_hurryup);
		hiddeny[player] = fldsizey;
		
		if(hidden[player]) {
			hidden[player] = 0;
			disableShadowTimer(player);
			statc[player * 10 + 3] = 1;	// HIDDEN時はブロックが消える演出開始まで間を置く
		}
		
		if(!fastroll[player]) {
			onRecord[player] = 0;
			StopAllBGM();
		}
		
		statc[player * 10] = fldsizey - 1;
		
		// フィールドに何もない場合はブロックが消える演出を省略
		if(isBravo(player)) statc[player * 10] = -2;
		
		statc[player * 10 + 2] = 1;
	}
	
	// 演出終了
	if(statc[player * 10] <= -2) {
		// 次のステータスへ
		if((ending[player] == 2) && (fastroll[player] != 0)) {
			stat[player] = 1;	// 高速ロールで死んだ場合はロール終了まで待つ
			
			// フィールドを消す
			resetField(player);
		} else {
			stat[player] = 8;	// 結果画面
		}
		resetStatc(player);
		return;
	}
	
	// カウンタ増加
	statc[player * 10 + 1]++;
	
	// スーッと消えていく演出
	if(statc[player * 10 + 1] > 4 + statc[player * 10 + 3] * 116) {
		block = statc[player * 10];
		
		statc[player * 10 + 1] = 0;
		
		for(j = 0; j < fldsizex; j++) {
			if(block >= 0) {
				c = getFieldBlockT(player, j, block);
				if(c == -1) c = 8;
				setFieldBlockT(player, j, block, c - 4);
			}
			
			if(block < fldsizey - 1) {
				setFieldBlockT(player, j, block + 1, getFieldBlockT(player, j, block + 1) - 4);
			}
		}
		
		statc[player * 10 + 3] = 0;
		statc[player * 10]--;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.08 - 結果表示
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statResult(int player) {
	int i, param;
	
	param = 0;
	executePlugin(player, 21, &param);
	if(param) return;
	
	statc[player * 10]++;
	
	// BGM再生
	if(statc[player * 10] == 1) {
		if((bgmtype != 0) && (!fast)) {
			if(!enable_sysbgm) loadBGM(13);
			bgmlv = 13;
			PlayBGM();
		}
	}
	
	// ボタンでスキップ
	if(getPushState(player, 4)) {
		statc[player * 10] = 500;
	}
	
	// 次の画面へ
	if(statc[player * 10] >= 500) {
		stat[player] = 9;
		resetStatc(player);
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.09 - ゲームオーバー表示
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statGameOver2(int player) {
	int i, param;
	
	param = 0;
	executePlugin(player, 22, &param);
	if(param) return;
	
	// カウンタ増加
	statc[player * 10]++;
	
	// ゲームオーバー音
	if(statc[player * 10] == 1) {
		PlaySE(se_gameover);
		StopAllBGM();
	}
	
	// GAME OVER
	ExBltRect(sg_gametext, foffset[player] - 2, 95, 0, 0, 100, 50);
	
	// ボタンでスキップ
	if(getPushState(player, 4)) {
		statc[player * 10] = 480;
	}
	
	// 終了
	if(statc[player * 10] >= 480) {
		if(playback && replayauto) stat[player] = 0;
		else stat[player] = 11;
		resetStatc(player);
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.10 - エンディング
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statEnding(int player) {
	int i, j, k, param;
	
	param = 0;
	executePlugin(player, 23, &param);
	if(param) return;
	
	jump(ending[player] - 1, lerase, lstart, lclear, lerase);
	
	// エンディング1＆4 ブロック消滅
	lerase:
		if(statc[player * 10] == 0) {
			PlaySE(se_ttclear);
			StopAllBGM();
			statc[player * 10 + 1] = 0;
			if(ending[player] == 4) statc[player * 10 + 1] = checkFieldTop(player) * 6;
		}
		
		// ブロックを消す
		if(statc[player * 10 + 1] % 6 == 0) {
			if(ending[player] == 4) {
				j = statc[player * 10 + 1] / 6;
			} else {
				j = fldsizey - statc[player * 10 + 1] / 6;
			}
			
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
			}
		}
		
		if(statc[player * 10] >= 129) {
			// アニメ終了、次の処理へ
			executePlugin(player, 24, &dummy);
		} else {
			// カウンタ増加
			statc[player * 10]++;
			statc[player * 10 + 1]++;
		}
		return;
	
	// エンディング2 スタッフロール
	lstart:
		stat[player] = 4;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		return;
	
	// エンディング3 EXCELLENT画面
	lclear:
		param = 0;
		executePlugin(player, 25, &param);
		if(param == -1) return;
		
		statc[player * 10]++;
		
		// 花火
		/*
		if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			statc[player * 10 + 1]++;
		}
		*/
		
		if(param == 0) {
			// EXCELLENT
			if(statc[player * 10] < 6) {
				k = 10 - statc[player * 10];
				i = (76 * k / 5 - 76) / 2;
				j = (10 * k / 5 - 10) / 2;
				k = 65536 * k / 5;
				ExBltRectR(sg_spr, foffset[player] + 10 - i, fyoffset[player] + 96 - j, 0, 31, 76, 10, k, k);
			} else {
				ExBltRect(sg_spr, foffset[player] + 10, fyoffset[player] + 96, 0, 31, 76, 10);
			}
		} else if(param == 1) {
			// YOU ARE GRAND MASTER!!
			if(statc[player * 10] < 64) {
				k = 128 - statc[player * 10];
				i = (80 * k / 64 - 80) / 2;
				j = (36 * k / 64 - 36) / 2;
				k = 65536 * k / 64;
				ExBltRectR(sg_spr, foffset[player] + 8 - i, fyoffset[player] + 102 - j, 0, 41, 80, 36, k, k);
			} else {
				ExBltRect(sg_spr, foffset[player] + 8, fyoffset[player] + 102, 0, 41, 80, 36);
			}
		} else if(param == 2) {
			// YOU ARE GOD
			if(statc[player * 10] < 64) {
				k = 128 - statc[player * 10];
				i = (105 * k / 64 - 105) / 2;
				j = (67 * k / 64 - 67) / 2;
				k = 65536 * k / 64;
				ExBltRectR(sg_spr, foffset[player] - 7 - i, fyoffset[player] + 70 - j, 88, 357, 105, 67, k, k);
			} else {
				ExBltRect(sg_spr, foffset[player] - 7, fyoffset[player] + 70, 88, 357, 105, 67);
			}
		} else if(param == 3) {
			// CLEAR!!
			ExBltRect(sg_spr, foffset[player] + 2, fyoffset[player] + 78, 0, 97, 92, 17);
		} else if(param == 4) {
			// CLEAR
			ExBltRect(sg_spr, foffset[player] + 3, fyoffset[player] + 78, 0, 116, 92, 17);
		} else if(param == 5) {
			// 何も表示せず終わり
			statc[player * 10] = 600;
		}
		
		// 終了
		if(statc[player * 10] >= 600) {
			fastroll[player] = 0;
			stat[player] = 7;
			resetStatc(player);
		}
		
		executePlugin(player, 26, &dummy);
		return;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   ステータスNo.11 - リプレイ保存画面
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void statReplaySave(int player) {
	int color, number;
	color = (count % 4 / 2) * 7;
	number = statc[player * 10 + 1];
	
	// 最初のフレームの処理
	if(!statc[player * 10 + 2]) {
		checkAllReplayExist();
		statc[player * 10 + 2] = 1;
	}
	
	// メニュー表示
	printFont(foffset[player] + 16, fyoffset[player] + 96 + statc[player * 10] * 16, "b", color);
	
	sprintf(string[0], "SAVE %d", number + 1);
	printFont(foffset[player] + 24, fyoffset[player] + 96, string[0], (statc[player * 10] == 0) * color);
	
	if(replayexist[number]) {
		printFont(foffset[player] + 32, fyoffset[player] + 104, "(USED)", (statc[player * 10] == 0) * color);
	}
	
	if(!playback) {
		printFont(foffset[player] + 24, fyoffset[player] + 112, "RETRY", (statc[player * 10] == 1) * color);
	}
	printFont(foffset[player] + 24, fyoffset[player] + 128, "END", (statc[player * 10] == 2) * color);
	
	// リプレイ内容表示
	if(replayexist[number]) {
		sprintf(string[0], "REPLAY %d", number + 1);
		printFont(foffset[player] + 8, fyoffset[player] + 160, string[0], 4);
		
		LeftStr(replay_plugin_name_mode[number], 10, string[0]);
		printFont(foffset[player] + 8, fyoffset[player] + 168, string[0], 0);
		
		LeftStr(replay_plugin_name_rule[number], 10, string[0]);
		printFont(foffset[player] + 8, fyoffset[player] + 176, string[0], 0);
		
		getTime(replay_timer[number]);
		printFont(foffset[player] + 8, fyoffset[player] + 184, string[0], 0);
	}
	
	// キー入力
	padRepeat2(player);
	
	// ↑
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if(getPressState(player, 0)) {
		PlaySE(se_move);
		statc[player * 10]--;
		if((playback) && (statc[player * 10] == 1)) statc[player * 10] = 0;
		if(statc[player * 10] < 0) statc[player * 10] = 2;
	}
	
	// ↓
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if(getPressState(player, 1)) {
		PlaySE(se_move);
		statc[player * 10]++;
		if((playback) && (statc[player * 10] == 1)) statc[player * 10] = 2;
		if(statc[player * 10] > 2) statc[player * 10] = 0;
	}
	
	// ←
	if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
	if(getPressState(player, 2)) {
		if(statc[player * 10] == 0) {
			PlaySE(se_kachi);
			statc[player * 10 + 1]--;
			if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = 39;
		}
	}
	
	// →
	if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
	if(getPressState(player, 3)) {
		if(statc[player * 10] == 0) {
			PlaySE(se_kachi);
			statc[player * 10 + 1]++;
			if(statc[player * 10 + 1] > 39) statc[player * 10 + 1] = 0;
		}
	}
	
	// Aボタン
	if(getPushState(player, 4)) {
		if(statc[player * 10] == 0) {
			// SAVE
			if(recTimer[player] <= 108000) {
				PlaySE(se_kettei);
				if(maxPlay) {
					saveReplayData(0, statc[player * 10 + 1]);
					saveReplayData(1, statc[player * 10 + 1]);
				} else {
					saveReplayData(player, statc[player * 10 + 1]);
				}
				checkAllReplayExist();
			}
		} else if(statc[player * 10] == 1) {
			// RETRY
			PlaySE(se_kettei);
			retrygame();
		} else if(statc[player * 10] == 2) {
			// END
			flag = 1;
		}
	}
}

// リトライ処理
void retrygame(int player) {
	int param;
	
	StopAllBGM();
	resetSoundVolume();
	
	param = 0;
	executePlugin(player, 70, &param);
	
	if(!param) {
		gameAllInit();
		playerInitial(player);
		versusInit(player);
		
		if(backno != firstbackno) {
			bgfadesw = 1;
			bgfadelv = 0;
			bgfadebg = firstbackno;
		}
		stat[player] = 3;
	}
	
	if(!english) debugLogSystem("再スタート");
	else debugLogSystem("Game restart");
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   起動時の読み込み処理
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void initialize() {
	int i, cfg[4];
	
	SetConstParam("Caption", "HEBORIS U.E. MINI - Now Loading...");
	
	// SCREEN.SAV読み込み(screencfg.c)
	cfg[0] = screenMode;
	cfg[1] = systemmem;
	cfg[2] = screenColor;
	cfg[3] = useHires;
	loadScreenConfig(&cfg);
	screenMode = cfg[0];
	systemmem = cfg[1];
	screenColor = cfg[2];
	useHires = cfg[3];
	
	// 画面解像度設定
	if((screenMode >= 2) && (useHires)) setDrawRate(2);
	else setDrawRate(1);
	
	// バージョン表示
	ExTextLayerOn(0, 8, 8);
	ExTextSize(0, 12);
	TextColor(0, 0, 255, 0);
	TextBackColorDisable(0);
	TextOut(0, versionStr);
	halt;
	
	// 初期化
	for(i = 0; i < 512; i++) {
		graphics_plane_type[i] = 0;
		sound_plane_type[i] = 0;
		se_play[i] = 0;
	}
	for(i = 0; i < 30; i++) {
		bgm_plane[i] = -1;
	}
	
	// 文字列変数のメモリを確保
	for(i = 0; i < 200; i++) {
		plugin_name_rule[i] = new(32);
		plugin_name_mode[i] = new(32);
		StrCpy(plugin_name_rule[i], "");
		StrCpy(plugin_name_mode[i], "");
	}
	
	for(i = 0; i < 40; i++) {
		replay_plugin_name_rule[i] = new(32);
		replay_plugin_name_mode[i] = new(32);
	}
	
	if(debug_enable) {
		for(i = 0; i < 40; i++) {
			debug_log_system[i] = new(256);
			debug_log_rule[i] = new(256);
			debug_log_mode[i] = new(256);
			StrCpy(debug_log_system[i], "");
			StrCpy(debug_log_rule[i], "");
			StrCpy(debug_log_mode[i], "");
		}
		
		if(!english) debugLogSystem("デバッグログ開始");
		else debugLogSystem("Debug log start.");
	}
	
	// システムグラフィックを読み込み
	TextColor(0, 255, 255, 255);
	ExTextMove(0, 8, 20);
	TextOut(0, "Graphics Loading");
	halt;
	loadAllSystemGraphics();
	
	// システム効果音を読み込み
	ExTextMove(0, 8, 32);
	TextOut(0, "Sound Effect Loading");
	halt;
	loadSystemSE();
	
	// システム音楽を読み込み
	if(enable_sysbgm) {
		ExTextMove(0, 8, 44);
		TextOut(0, "System BGM Loading");
		halt;
		loadSystemBGM();
	}
	
	TextLayerOff(0);
	
	fps_plus_mpc[0] = 0;
	fps_plus_mpc[1] = 0;
	fps_minus_mpc[0] = 0;
	fps_minus_mpc[1] = 0;
	
	SetConstParam("Caption", "HEBORIS U.E. MINI");
	
	executePlugin(0, 0, &dummy);	// プラグイン呼び出し
}

// フィールド表示位置設定
void setFieldPosition(int player, int max) {
	int i;
	
	if(max == 0) {
		// SINGLE
		foffset[player] = s_foffset;
		fyoffset[player] = s_fyoffset;
		coffset = s_coffset;
	} else if(max == 1) {
		// DUAL
		foffset[player] = d_foffset[player];
		fyoffset[player] = d_fyoffset[player];
		//coffset = d_coffset;
	} else {
		// VERSUS
		foffset[player] = v_foffset[player];
		fyoffset[player] = v_fyoffset[player];
		//coffset = d_coffset;
	}
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   プラグイン管理
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
// ルール追加
int addRulePlugin(str *name) {
	int len;
	
	// 既に200個登録されているならエラー
	if(plugin_count_rule >= 200) {
		if(!english) sprintf(string[0], "ルール %s の登録に失敗(数は200個が限界)", name);
		else sprintf(string[0], "Failed to add rule %s (There are 200 plugins)", name);
		debugLogSystem(string[0]);
		return -1;
	}
	
	// 名前が無い、または長すぎる場合はエラー
	len = StrLen(name);
	if((len < 1) || (len > 31)) {
		if(!english) sprintf(string[0], "ルール %s の登録に失敗(名前の長さが規定外)", name);
		else sprintf(string[0], "Failed to add rule %s (Name is too long or short)", name);
		debugLogSystem(string[0]);
		return -1;
	}
	
	// 同名のルールの登録を避ける
	if(findRulePlugin(name) != -1) {
		if(!english) sprintf(string[0], "ルール %s の登録に失敗(多重登録)", name);
		else sprintf(string[0], "Failed to add rule %s (Multiple registration)", name);
		debugLogSystem(string[0]);
		return -1;
	}
	
	StrCpy(plugin_name_rule[plugin_count_rule], name);
	plugin_count_rule++;
	
	if(!english) sprintf(string[0], "ルール %s を登録しました", name);
	else sprintf(string[0], "Rule %s added", name);
	debugLogSystem(string[0]);
	
	return plugin_count_rule - 1;
}

// モード追加
int addModePlugin(str *name) {
	int len;
	
	// 既に200個登録されているならエラー
	if(plugin_count_mode >= 200) {
		if(!english) sprintf(string[0], "モード %s の登録に失敗(数は200個が限界)", name);
		else sprintf(string[0], "Failed to add mode %s (There are 200 plugins)", name);
		debugLogSystem(string[0]);
		return -1;
	}
	
	// 名前が無い、または長すぎる場合はエラー
	len = StrLen(name);
	if((len < 1) || (len > 31)) {
		if(!english) sprintf(string[0], "モード %s の登録に失敗(名前の長さが規定外)", name);
		else sprintf(string[0], "Failed to add mode %s (Name is too long or short)", name);
		debugLogSystem(string[0]);
		return -1;
	}
	
	// 同名のモードの登録を避ける
	if(findModePlugin(name) != -1) {
		if(!english) sprintf(string[0], "モード %s の登録に失敗(多重登録)", name);
		else sprintf(string[0], "Failed to add mode %s (Multiple registration)", name);
		debugLogSystem(string[0]);
		return -1;
	}
	
	StrCpy(plugin_name_mode[plugin_count_mode], name);
	plugin_count_mode++;
	
	if(!english) sprintf(string[0], "モード %s を登録しました", name);
	else sprintf(string[0], "Mode %s added", name);
	debugLogSystem(string[0]);
	
	return plugin_count_mode - 1;
}

// ルールプラグインを検索
int findRulePlugin(str *name) {
	int i;
	
	for(i = 0; i < plugin_count_rule; i++) {
		if(StrCmp(plugin_name_rule[i], name) == 0) return i;
	}
	
	return -1;
}

// モードプラグインを検索
int findModePlugin(str *name) {
	int i;
	
	for(i = 0; i < plugin_count_mode; i++) {
		if(StrCmp(plugin_name_mode[i], name) == 0) return i;
	}
	
	return -1;
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   halt;
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void spriteTime() {
	int player;
	
	count = (count + 1) % 65536;	// グローバルカウンタ増加
	
	if(!netplay) {
		for(player = 0; player <= maxPlay; player++) {
			// FPS+1
			if(IsPressKey(fps_plus_key[player]) || getJoyPressState(player, joy_fps_plus_key[player])) {
				fps_plus_mpc[player]++;
				
				if((fps_plus_mpc[player] == 1) || (fps_plus_mpc[player] > tame1)) {
					if(GetFPS() < 180) SetFPS(GetFPS() + 1);
				}
			} else {
				fps_plus_mpc[player] = 0;
			}
			
			// FPS-1
			if(IsPressKey(fps_minus_key[player]) || getJoyPressState(player, joy_fps_minus_key[player])) {
				fps_minus_mpc[player]++;
				
				if((fps_minus_mpc[player] == 1) || (fps_minus_mpc[player] > tame1)) {
					if(GetFPS() > 1) SetFPS(GetFPS() - 1);
				}
			} else {
				fps_minus_mpc[player] = 0;
			}
		}
	}
	
	// FPS表示（画面）
	if(show_fps == 1) {
		sprintf(string[0], "%3d/%3dFPS", GetRealFPS(), GetFPS());
		printTinyFont(132, 233, string[0]);
	}
	
	// FPS表示（タイトルバー）
	if(show_fps == 2) {
		sprintf(string[0], "HEBORIS U.E. MINI - %d/%dFPS", GetRealFPS(), GetFPS());
		SetConstParam("Caption", string[0]);
	}
	
	// ネットプレイ中の表示
	if(netplay) {
		printTinyFont(0, 233, "NETPLAY");
	}
	// リプレイ中の表示
	else if(playback) {
		if(replayauto) printTinyFont(0, 233, "REPLAY");
		else printTinyFont(0, 233, "RERECORD");
	}
	
	executePlugin(0, 1, &dummy);	// プラグイン呼び出し
	
	// ESCキーが押されたら即刻終了
	if(IsPushEscKey()) {
		// ネットプレイ中だったら切断
		if(netplay) {
			tcpCleanup();
			netplay = 0;
		}
		
		Quit();
	}
	
	// 2倍ウインドウモードの時の処理
	if((screenMode >= 2) && (!useHires)) {
		SwapToSecondary(sg_2xwindow);		// セカンダリプレーンを、ダミーでプレーンsg_2xwindowと入れ替える
		BltFastRectR(sg_2xwindow, 0, 0, 0, 0, 320, 240, 65536 * 2, 65536 * 2);
		SwapToSecondary(sg_2xwindow);
		BltFast(sg_2xwindow, 0, 0);
	}
	
	// 描画
	halt;
	
	// 効果音再生
	PlayAllSE();
	
	// スクリーンショット
	if(IsPushKey(ss_key[0]) || IsPushKey(ss_key[1]) || 
	   getJoyPressState(0, joy_ss_key[0]) || getJoyPressState(1, joy_ss_key[1]))
	{
		sprintf(string[0], "ss/ss_%04d.bmp", ssc);
		
		SwapToSecondary(sg_sssurface);
		ExSaveBitmap(string[0], sg_sssurface, 0, 0, 320, 240);
		SwapToSecondary(sg_sssurface);
		
		ssc++;
	}
	
	ClearSecondary();
}
