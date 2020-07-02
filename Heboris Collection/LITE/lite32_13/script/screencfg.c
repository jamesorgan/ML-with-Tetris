//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   SCREEN.SAV保存
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void saveScreenConfig(int size, int mem, int color) {
	int tmpBuf[7];
	
	// ヘッダ
	tmpBuf[0] = 0x4F424548;
	tmpBuf[1] = 0x4554494C;
	tmpBuf[2] = 0x50534944;
	tmpBuf[3] = 0x3159414C;
	
	// 設定
	tmpBuf[4] = size;
	tmpBuf[5] = mem;
	tmpBuf[6] = color;
	
	SaveFile("SCREEN.SAV", &tmpBuf, 7 * 4);
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   SCREEN.SAV読み込み
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int loadScreenConfig() {
	int tmpBuf[7];
	
	// ヘッダだけ読み込み
	LoadFile("SCREEN.SAV", &tmpBuf, 4 * 4);
	
	// ヘッダが違う
	if(tmpBuf[0] != 0x4F424548) return -1;
	if(tmpBuf[1] != 0x4554494C) return -1;
	if(tmpBuf[2] != 0x50534944) return -1;
	if(tmpBuf[3] != 0x3159414C) return -1;
	
	// 全部読み込み
	LoadFile("SCREEN.SAV", &tmpBuf, 7 * 4);
	screenMode = tmpBuf[4];
	systemmem = tmpBuf[5];
	screenColor = tmpBuf[6];
	
	return 0;
}
