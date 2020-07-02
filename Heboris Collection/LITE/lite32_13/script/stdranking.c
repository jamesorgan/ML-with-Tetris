//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  STANDARDモードのランキング
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲

// ランキング初期化
void stdRankingInit() {
	int i;
	
	for(i = 0; i < (5 * 10 * 4); i++) {
		StrCpy(std_rkname[i], "NOP");
		std_rkscore[i] = 0;
		std_rklines[i] = 0;
		std_rktime[i] = 0;
		std_wait1[i] = 0;
		std_wait2[i] = 0;
		std_wait3[i] = 0;
		std_waitt[i] = 0;
		std_speed[i] = 0;
	}
}

// カテゴリを決める（ランキングのないモードは-1）
int stdRankingSetCategory(int player) {
	int data;
	data = -1;
	
	if(gameMode[player] != 17) return -1;
	if(playback || demo || IsBigStart[player] || item_mode[player]) return -1;
	
	if((timeattack[player] != 2) && (timeattack[player] != 3)) data = timeattack[player];
	return data;
}

// ランキングを読み書きする時に使用
int stdRankingGet(int rcat, int rrots) {
	return (rrots * 5) + (rcat * 50);
}

// 何位に入るかチェック（ランク外なら-1）
int stdRankingCheck(int player) {
	int i, j, rank;
	
	if(playback || demo) return -1;
	if(stdRankingSetCategory(player) == -1) return -1;
	
	rank = -1;
	
	for(i = 0; i < 5; i++) {
		j = stdRankingGet(stdRankingSetCategory(player), rots[player]);
		
		if(timeattack[player] == 0) {
			if((c_norm[player] > std_rklines[j + i]) || 
			   ((c_norm[player] == std_rklines[j + i]) && (gameTimer[player] < std_rktime[j + i])))
			{
				rank = i;
				break;
			}
		} else if(timeattack[player] == 1) {
			if((sc[player] > std_rkscore[j + i]) || 
			   ((sc[player] == std_rkscore[j + i]) && (gameTimer[player] < std_rktime[j + i])))
			{
				rank = i;
				break;
			}
		}
	}
	
	return rank;
}

// ランキングに登録
void stdRankingRegist(int player, int rank, str *rname) {
	int i, j;
	
	if(playback || demo) return;
	if((rank < 0) || (rank > 4)) return;
	if(stdRankingSetCategory(player) == -1) return;
	
	j = stdRankingGet(stdRankingSetCategory(player), rots[player]);
	
	// ランキングをずらす
	for(i = 4; i > rank; i--) {
		StrCpy(std_rkname[j + i], std_rkname[j + i - 1]);
		std_rkscore[j + i] = std_rkscore[j + i - 1];
		std_rklines[j + i] = std_rklines[j + i - 1];
		std_rktime[j + i]  = std_rktime[j + i - 1];
		std_wait1[j + i] = std_wait1[j + i - 1];
		std_wait2[j + i] = std_wait2[j + i - 1];
		std_wait3[j + i] = std_wait3[j + i - 1];
		std_waitt[j + i] = std_waitt[j + i - 1];
		std_speed[j + i] = std_speed[j + i - 1];
	}
	
	// 新しいデータを登録
	StrCpy(std_rkname[j + rank], rname);
	std_rkscore[j + rank] = sc[player];
	std_rklines[j + rank] = c_norm[player];
	std_rktime[j + rank] = gameTimer[player];
	std_wait1[j + rank] = wait1[player];
	std_wait2[j + rank] = wait2[player];
	std_wait3[j + rank] = wait3[player];
	std_waitt[j + rank] = waitt[player];
	std_speed[j + rank] = sp[player];
}

// 名前を格納する変数(std_rkname)のメモリを確保
void stdRankingAlloc() {
	int i;
	
	for(i = 0; i < (5 * 10 * 4); i++) std_rkname[i] = new(4);
}

// ランキングを表示
void stdRankingView() {
	int i, j, k, color;
	
	viewDarkTitle();
	
	// ルール名表示
	printFont(1, 1, "RULE:", fontc[rankingrule]);
	getRuleNameEx(rankingrule, 0);
	printFont(6, 1, string[0], fontc[rankingrule]);
	
	// カテゴリ名表示
	printFont(1, 2, "MODE:", ranking_category_color[category]);
	printFont(6, 2, ranking_category_name[category], ranking_category_color[category]);
	
	// ランキング表示
	printFont(1, 4, "RANK  NAME  SCORE   LINES  TIME", fontc[rankingrule]);
	
	for(i = 0; i < 5; i++) {
		j = stdRankingGet(category - 40, rankingrule);
		
		// 順位
		if(i == 0) StrCpy(string[0], "1ST");
		if(i == 1) StrCpy(string[0], "2ND");
		if(i == 2) StrCpy(string[0], "3RD");
		if(i >= 3) sprintf(string[0], "%dTH", i + 1);
		printFont(1, 5 + i * 3, string[0], 0);
		
		// 名前
		printFont(7, 5 + i * 3, std_rkname[j + i], 0);
		
		// スコア
		sprintf(string[0], "%d", std_rkscore[j + i]);
		printFont(13, 5 + i * 3, string[0], 0);
		
		// ライン
		sprintf(string[0], "%d", std_rklines[j + i]);
		printFont(21, 5 + i * 3, string[0], 0);
		
		// タイム
		getTime(std_rktime[j + i]);
		printFont(28, 5 + i * 3, string[0], 0);
		
		// wait値
		sprintf(string[0], "W1:%2d W2:%2d W3:%2d WT:%2d SP:%d",
				std_wait1[j + i], std_wait2[j + i], std_wait3[j + i], std_waitt[j + i], std_speed[j + i]);
		printFont(5, 6 + i * 3, string[0], 0);
	}
}

// ランキングを保存
void stdRankingSave() {
	int i, temp2[4];
	
	FillMemory(&saveBuf, 50000 * 4, 0);
	
	// ヘッダ
	saveBuf[0] = 0x4F424548;
	saveBuf[1] = 0x4554494C;
	saveBuf[2] = 0x52445453;
	saveBuf[3] = 0x314B4E41;
	
	for(i = 0; i < (5 * 10 * 4); i++) {
		// 名前
		StrCpy(&temp2, std_rkname[i]);
		saveBuf[4 + i] = temp2[0];
		
		saveBuf[4 + i + (5 * 10 * 4) * 1] = std_rkscore[i];	// スコア
		saveBuf[4 + i + (5 * 10 * 4) * 2] = std_rklines[i];	// ライン
		saveBuf[4 + i + (5 * 10 * 4) * 3] = std_rktime[i];	// タイム
		saveBuf[4 + i + (5 * 10 * 4) * 4] = std_wait1[i];	// wait1
		saveBuf[4 + i + (5 * 10 * 4) * 5] = std_wait2[i];	// wait2
		saveBuf[4 + i + (5 * 10 * 4) * 6] = std_wait3[i];	// wait3
		saveBuf[4 + i + (5 * 10 * 4) * 7] = std_waitt[i];	// waitt
		saveBuf[4 + i + (5 * 10 * 4) * 8] = std_speed[i];	// sp
	}
	
	SaveFile("RANKING_STD.SAV", &saveBuf, 1804 * 4);
}

// ランキングを読み込み
int stdRankingLoad() {
	int i, temp2[4];
	
	// ヘッダだけ読み込み
	FillMemory(&saveBuf, 50000 * 4, 0);
	LoadFile("RANKING_STD.SAV", &saveBuf, 16);
	
	// バージョン違いなら初期化
	if(saveBuf[0] != 0x4F424548) return -1;
	if(saveBuf[1] != 0x4554494C) return -1;
	if(saveBuf[2] != 0x52445453) return -1;
	if(saveBuf[3] != 0x314B4E41) return -1;
	
	// 全部読み込み
	LoadFile("RANKING_STD.SAV", &saveBuf, 1804 * 4);
	
	// ランキングデータ
	for(i = 0; i < (5 * 10 * 4); i++) {
		// 名前
		temp2[0] = saveBuf[4 + i];
		StrCpy(std_rkname[i], &temp2);
		
		std_rkscore[i] = saveBuf[4 + i + (5 * 10 * 4) * 1];	// スコア
		std_rklines[i] = saveBuf[4 + i + (5 * 10 * 4) * 2];	// ライン
		std_rktime[i]  = saveBuf[4 + i + (5 * 10 * 4) * 3];	// タイム
		std_wait1[i]   = saveBuf[4 + i + (5 * 10 * 4) * 4];	// wait1
		std_wait2[i]   = saveBuf[4 + i + (5 * 10 * 4) * 5];	// wait2
		std_wait3[i]   = saveBuf[4 + i + (5 * 10 * 4) * 6];	// wait3
		std_waitt[i]   = saveBuf[4 + i + (5 * 10 * 4) * 7];	// waitt
		std_speed[i]   = saveBuf[4 + i + (5 * 10 * 4) * 8];	// sp
	}
	
	return 0;
}
