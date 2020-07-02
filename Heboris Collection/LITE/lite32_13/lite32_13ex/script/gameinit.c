//□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□
//
//    HEBORIS [ヘボリス] 2001 Ver0.00 / 2000.11.05 (Sun) ～ ????.??.?? (????)
//
//                         (c) 1998-2000 Kenji Hoshimoto
//
//■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■

// グローバル変数
int		screenColor = 16;			// 現在の色数

// 設定ファイルをインポート
	include "option.def"			// Setting.exeの設定

// ソースファイルをインポート
	include "script/screencfg.c"	// SCREEN.SAV関連の関数

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   初期設定
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void main() {
	// SCREEN.SAV読み込み(screencfg.c)
	if(loadScreenConfig()) {
		saveScreenConfig(screenMode, systemmem, screenColor);
	}
	
	if(screenMode == 0)
		SetWindow(0, 320, 240, screenColor);	// フルスクリーンモード 320*240
	else if(screenMode == 1)
		SetWindow(1, 320, 240, screenColor);	// ウインドウモード 320*240
	else if(screenMode == 2)
		SetWindow(1, 640, 480, screenColor);	// ウインドウモード 640*480
	else
		SetWindow(0, 640, 480, screenColor);	// フルスクリーンモード 640*480
	
	// 60fps
	SetFPS(60);

	// YGS2000固有の設定
	SetConstParam("Caption", "HEBORIS LITE - Script Compiling...");
	SetConstParam("EnablePause", 0);	// 読み込み完了まではポーズ無効
	SetConstParam("USE_XZ_FOR_BUTTON", 0);
	SetConstParam("StringMax", 16);

	SetDebugMode(0);

	// システムメモリを使うか?
	SetSystemMemoryUse(systemmem);
}
