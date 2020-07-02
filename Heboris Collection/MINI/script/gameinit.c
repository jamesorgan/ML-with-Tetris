//□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□
//
//    HEBORIS [ヘボリス] 2001 Ver0.00 / 2000.11.05 (Sun) ～ ????.??.?? (????)
//
//                         (c) 1998-2000 Kenji Hoshimoto
//
//■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■

// 設定
int		windowPosX = 0;				// ウィンドウのX座標
int		windowPosY = 0;				// ウィンドウのY座標
int		outputDebugLog = 0;			// デバッグログのErrorLog.txtへの出力の有無（0=なし 1=あり）

// グローバル変数
int		screenMode = 1;
int		systemmem = 0;
int		screenColor = 16;
int		useHires = 0;

// ソースファイルをインポート
	include "script/screencfg.c"	// SCREEN.SAVの読み書き

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   初期設定
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void main() {
	int cfg[4];
	
	// SCREEN.SAV読み込み(screencfg.c)
	cfg[0] = screenMode;
	cfg[1] = systemmem;
	cfg[2] = screenColor;
	cfg[3] = useHires;
	if(loadScreenConfig(&cfg)) saveScreenConfig(&cfg);
	screenMode = cfg[0];
	systemmem = cfg[1];
	screenColor = cfg[2];
	useHires = cfg[3];
	
	// 画面モードを設定
	if(screenMode == 0)
		SetWindow(0, 320, 240, screenColor);	// フルスクリーンモード 320*240
	else if(screenMode == 1)
		SetWindow(1, 320, 240, screenColor);	// ウインドウモード 320*240
	else if(screenMode == 2)
		SetWindow(1, 640, 480, screenColor);	// ウインドウモード 640*480
	else
		SetWindow(0, 640, 480, screenColor);	// フルスクリーンモード 640*480
	
	// ウィンドウポジション
	SetConstParam("WindowPos", windowPosX, windowPosY);
	
	// 60fps
	SetFPS(60);
	
	// YGS2000固有の設定
	SetConstParam("Caption", "HEBORIS U.E. MINI - Please Wait...");
	SetConstParam("EnablePause", 0);	// 読み込み完了まではポーズ無効
	SetConstParam("USE_XZ_FOR_BUTTON", 0);
	SetConstParam("StringMax", 16);
	SetConstParam("EnableMultiApp", 1);	// 複数起動の許可
	
	// デバッグログのErrorLog.txtへの出力の有無（0=なし 1=あり）
	SetDebugMode(outputDebugLog);
	
	// システムメモリを使うか?
	SetSystemMemoryUse(systemmem);
}
