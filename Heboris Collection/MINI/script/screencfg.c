//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   SCREEN.SAV保存
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
void saveScreenConfig(int *cfg) {
	int tmpBuf[8];
	
	// ヘッダ
	tmpBuf[0] = 0x4F424548;
	tmpBuf[1] = 0x4554494C;
	tmpBuf[2] = 0x50534944;
	tmpBuf[3] = 0x3259414C;
	
	// 設定
	tmpBuf[4] = cfg[0];
	tmpBuf[5] = cfg[1];
	tmpBuf[6] = cfg[2];
	tmpBuf[7] = cfg[3];
	
	SaveFile("config/SCREEN.SAV", &tmpBuf, 8 * 4);
}

//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//   SCREEN.SAV読み込み
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int loadScreenConfig(int *cfg) {
	int tmpBuf[8], size;
	
	// ヘッダだけ読み込み
	LoadFile("config/SCREEN.SAV", &tmpBuf, 4 * 4);
	
	// ヘッダが違う
	if(tmpBuf[0] != 0x4F424548) return -1;
	if(tmpBuf[1] != 0x4554494C) return -1;
	if(tmpBuf[2] != 0x50534944) return -1;
	
	// 全て読み込み
	if(tmpBuf[3] == 0x3259414C) size = 8;	// バージョン2
	else size = 7;	// バージョン1
	
	LoadFile("config/SCREEN.SAV", &tmpBuf, size * 4);
	
	cfg[0] = tmpBuf[4];
	cfg[1] = tmpBuf[5];
	cfg[2] = tmpBuf[6];
	
	if(size >= 8) {
		cfg[3] = tmpBuf[7];
	} else {
		cfg[3] = 0;
	}
	
	return 0;
}
