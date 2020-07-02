//ダミーのモード
//prefix:dmy

void dmyPluginEvent(int player, int event, int *param) {
	if(event == 0) {
		addModePlugin("DUMMY");	// モードを登録する
	}
}
