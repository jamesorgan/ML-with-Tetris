//▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽▼▽
//  セクションタイムランキング関連
//▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲△▲
int		st_version = 6;	// バージョン
						// 0:無効 1:c7p6/
//30*3　(マス123+4) 20G, ドムデビ-,トモTI, EHが30づつ でCとWで×2
str    st_name[120*2];
int		st_time[120*2];	// タイム
int		st_end[120*2];		// 0:未カンスト 1:ロール途中窒息 2:完全クリア
int		st_lvstop[120*2];		//レベルストップした時間
int		st_others[120*2];		//落としたブロック数

//str*		st_rkname[135];			// 名前
// 初期化
void ST_RankingInit(void) {
	int	i, j;
	
	for(i=0; i<120*2; i++) {
		StrCpy(st_name[i], "NOP");
		st_time[i] = 5400;
		st_end[i] = 0;
		st_lvstop[i] = 0;
		st_others[i] = 0;
	}
	
}

// STメダルの色を判定
int ST_RankingCheck(int player, int rmode, int section,int other,int isrot) {
	int	tmp;
	
	tmp = ST_rankingGet(player,rmode,other,isrot);
	
	//-5秒更新
	if(lap_time[section + player * 30] <= st_time[section + tmp] - 300) {
		return 4;
	}
	// 記録更新
	if(lap_time[section + player * 30] <= st_time[section + tmp]) {
		return 3;
	}
	// 5秒以内
	if(lap_time[section + player * 30] <= st_time[section + tmp] + 300) {
		return 2;
	}
	// 10秒以内
	if(lap_time[section + player * 30] <= st_time[section + tmp] + 600) {
		return 1;
	}
	
	return 0;
}

// 記録更新したかチェック
int ST_RankingCheckAll(int player, int rmode, int other,int isrot) {
	int i,tmp2;
	
	tmp2 = ST_rankingGet(player,rmode,other,isrot);

	if((rmode >= modeNo_mas) && (rmode <= modeNo_dev)) {
		for(i=0; i< ((tc[player] / 100) + is999(player,rmode)); i++) {
			if((lap_time[i + player * 30] <= st_time[i + tmp2]) && (lap_time[i + player * 30] != 0)) {
				return 1;
			}
		}
	}else if(rmode == modeNo_tom){
		for(i=0; i<stage[player]+ (stage[player] == laststage[player])- (27 * tomoyo_opt[player]); i++) {

			if((stage_time[i + player * 30] <= st_time[i + tmp2]) && (stage_time[i + player * 30] != 0)) {
				return 1;
			}
		}
	}
	return 0;
}
// ステージごとの記録更新したかチェック
int Stage_RankingCheck(int player, int rmode,int other,int isrot) {
	int i,tmp3;
	if(tomoyo_opt[player] >= 2) return 0;
	
	tmp3 = ST_rankingGet(player,rmode,other,isrot);
	
	if((stage_time[stage[player] - (27 * tomoyo_opt[player]) + player * 30] <= st_time[stage[player] - (27 * tomoyo_opt[player])+ tmp3]) && (stage_time[stage[player] - (27 * tomoyo_opt[player])+ player * 30] != 0)) {
		return 1;
	}
	return 0;
}

// セクションタイムランキング更新
void ST_RankingUpdate(str *strname,int player, int rmode, int end,int other,int isrot) {
	int i, temp,tmp4;
	
	tmp4 = ST_rankingGet(player,rmode,other,isrot);
	
	if((rmode >=modeNo_mas)&&(rmode<=modeNo_dev)){
		if(tc[player] < 100) {
			return;
		}
		for(i=0; i<((tc[player] / 100) + is999(player,rmode)); i++) {
			if((lap_time[i + player * 30] <= st_time[i + tmp4]) && (lap_time[i + player * 30] != 0)) {
				StrCpy(st_name[i + tmp4], strname);
				st_time[i + tmp4] = lap_time[i + player * 30];	// タイム
				st_end[i + tmp4] = end;		// エンディング到達
				st_lvstop[i + tmp4] = lvstop_time[i + player * 30];
				st_others[i + tmp4] = st_other[i + player * 30];
					
			}
		}
	}
	else if(rmode == modeNo_tom){//TOMOYO
		for(i=0; i<stage[player] + (stage[player] == laststage[player]) - (27 * tomoyo_opt[player]); i++) {
			if((stage_time[i + player * 30] <= st_time[i + tmp4]) && (stage_time[i + player * 30] != 0)) {
				StrCpy(st_name[i + tmp4], strname);
				st_time[i + tmp4] = stage_time[i + player * 30];	// タイム
				st_end[i + tmp4] = end;
				st_others[i + tmp4] = st_other[i + player * 30];
				
			}
		}
	}
}

// ファイルフォーマット (4byte単位)	
//   0      バージョン			
//   1～  9 未使用（自由に使用可能	
//  10～ 61 タイム			10-90
//  62～113 エンディング到達		91-171
// 114～165 名前			172-252
//					253-333

// セーブ
void ST_RankingSave(void) {//12345 6789
	int i,j,nametemp[4];
	
	FillMemory(&saveBuf, 2000 * 4, 0);
	
	saveBuf[0] = st_version;
	
	for(i=0;i<120*2;i++) {
		StrCpy(&nametemp, st_name[i]);
		saveBuf[i + 10] = nametemp[0];
		saveBuf[i + 259] = st_time[i];
		saveBuf[i + 498] = st_end[i];
		saveBuf[i + 737] = st_lvstop[i];
		saveBuf[i + 976] = st_others[i];
	}
	
	SaveFile("STRANKING.SAV", &saveBuf, 1500 * 4);
}

// ロード
int ST_RankingLoad(void) {
	int i,j,nametemp[4];
	FillMemory(&saveBuf, 2000 * 4, 0);
		// バージョンを見る
	LoadFile("STRANKING.SAV", &saveBuf, 4);
	
	if(saveBuf[0] != st_version) {
		return 1;
	}
	
	// 全体を読み込む
	LoadFile("STRANKING.SAV", &saveBuf, 1500 * 4);
	
	for(i=0;i<120*2;i++) {
			// 名前
		nametemp[0] = saveBuf[i + 10];
		StrCpy(st_name[i], &nametemp);
		st_time[i] = saveBuf[i + 259];
		st_end[i] = saveBuf[i + 498];
		st_lvstop[i] = saveBuf[i + 737];
		st_others[i] = saveBuf[i + 976];
	}
	return 0;
}

// 名前を格納する変数(stname)のメモリを確保
void ST_RankingAlloc() {
	int i;
	
	for(i = 0; i < (120*2); i++) st_name[i] = new(4);
}

//ベストタイム(ACEのはranking2.c)
/*
void viewbestSTtime(int player){
	int	tempbest,color;
	
	if(Isbesttime==0)return;

	color = (count % 4 / 2) * (sp[player] >= 1200) * digitc[rots[player]];
	if((gameMode[player]>=0)&&(gameMode[player]<=3)){//セクションタイム
	}else if((gameMode[player] == modeNo_tom) && (stage[player] < 27)){//ベストタイム
	//	if( (gameMode[player] == modeNo_tom) && (!maxPlay) ) {
			printFont(26+2*((hnext[player] >= 4) && (!player)) + 7 * player - 12 * maxPlay, 11, "BEST TIME", fontc[rots[player]]);
		
			tempbest = ST_rankingGet(player,6,0);
			getTime(st_time[stage[player] + tempbest]);
			printFont(26+2*((hnext[player] >= 4) && (!player)) + 7 * player - 12 * maxPlay, 12, string[0], color);
	}
}
//ベストタイムスモールフォント
void viewbestSTtimes(int player){
	int	tempbest,color;
	
	if(Isbesttime==0)return;
	
	color = (count % 4 / 2) * (sp[player] >= 1200) * digitc[rots[player]];
	if((gameMode[player]>=0)&&(gameMode[player]<=3)){//セクションタイム

	}else if((gameMode[player] == modeNo_tom) && (stage[player] < 27)){//ベストタイム
		if( (gameMode[player] == modeNo_tom) && ((!maxPlay) || (stat[1 - player] == 0)) ) {
			//bestの文字
			ExBltRect(3, 208+20*((hnext[player] >= 4) && (!player)) + 70 * player - 96 * maxPlay, 95, 251, 91, 21, 7);
			//timeの文字
			ExBltRect(3, 230+20*((hnext[player] >= 4) && (!player)) + 70 * player - 96 * maxPlay, 95, 180, 119, 19, 7);
		
			tempbest = ST_rankingGet(player,6,0);
			getTime(st_time[stage[player] + tempbest]);
			printSMALLFont((26 + 8 * player - 12 * maxPlay)*8+20*((hnext[player] >= 4) && (!player)), 103, string[0], color);
		}
	}
}
*/
//STランキングのアドレス指定
int ST_rankingGet(int player,int rmode,int other,int isrot){
	int	tmp;

	if(rmode[player] == modeNo_mas){//マスター
		if(do20G[player]){
			tmp = 20;
		}else if(other[player]!=3){
			tmp = 0;
		}else {
			tmp = 10;
		}
	}else if(rmode[player] == modeNo_dev){//デビル
		if(!other[player]){//doom
			tmp = 30;
		}else {//devil-
			tmp = 50;
		}
	}else if(rmode[player] == modeNo_tom){//TOMOYO
		if(!other[player]){//ti
			tmp = 60;
		}else {//eh-
			tmp = 90;
		}
	}
	
	//ワールドか？
	if(isrot)
	tmp = tmp + 120;
	
	return tmp;
}

// セクションタイムランキング表示
void ST_RankingView() {
	int i, max, mode,mode2, stcolor, tmp5, bps, bps1,bps2,s,t,sumtime;
	
	mode = 0;
	
	while(1) {
		// 背景描画
		count++;
		//CとWを切り替えるための
		mode2 =mode % 7;
		if(background == 0) {
			for(i = 0; i <= 8; i++) {
				ExBltFastRect(4 + (mode2 >= 3) + (mode2 >= 5), 96 * i - (count % 96) / 3, 0, 0, 0, 96, 240);
			}
		} else if(background == 1) {
			for(i = 0; i <= 8; i++) {
				ExBltFastRect(4 + (mode2 >= 3) + (mode2 >= 5), 96 * i, 0, 0, 0, 96, 240);
			}
		} else {
			ExBltFast(30, 0, 0);
		}

		
		//アドレス指定
		//C
		if(mode == 0){
			tmp5 = 0;
		}else if(mode == 1){
			tmp5 = 10;
		}else if(mode == 2){
			tmp5 = 20;//G4
		}else if(mode == 3){
			tmp5 = 30;//20G
		}else if(mode == 4){
			tmp5 = 50;//doom
		}else if(mode == 5){
			tmp5 = 60;//devil-
		}else if(mode == 6){
			tmp5 = 90;//eh
		//W	
		}else if(mode == 7){
			tmp5 = 120;//G3
		}else if(mode == 8){
			tmp5 = 130;//G4
		}else if(mode == 9){
			tmp5 = 140;//20G
		}else if(mode == 10){
			tmp5 = 150;//doom
		}else if(mode == 11){
			tmp5 = 170;//devi-
		}else if(mode == 12){
			tmp5 = 180;//doom
		}else if(mode == 13){
			tmp5 = 210;//devil-
		}
		
		// モード名表示
		if(mode2== 0)
			printFont(11, 1, "-  MASTER MODE  -", 1);
		else if(mode2== 1)
			printFont(9, 1, "-  MASTER GRADE4 MODE  -", 1);
		else if(mode2== 2)
			printFont(11, 1, "-   20G MODE    -", 7);
		else if(mode2== 3)
			printFont(11, 1, "-   DOOM MODE   -", 2);
		else if(mode2== 4)
			printFont(11, 1, "-  DEVIL- MODE   -", 2);
		else if(mode2== 5)
			printFont(11, 1, "-  TOMOYO TI MODE   -", 3);
		else if(mode2== 6)
			printFont(11, 1, "-  TOMOYO EH MODE   -", 3);
				
		if(mode2 >= 5){
			printFont(1,  3, "STAGE",1);
			printFont(8,  3, "TIME", 1);
			printFont(15, 3, "USE", 1);
			if(mode2 != 6){
				printFont(21,  3, "STAGE",1);
				printFont(29,  3, "TIME", 1);
				printFont(37, 3, "USE", 1);
			}
		}else {
			printFont(1,  3, "LEVEL",1);
			printFont(10, 3, "NAME" ,1);
			printFont(15,  3, "TIME", 1);
			printFont(25, 3, "LVSTOP", 1);
			printFont(32, 3, "BLOCK/S ", 1);
		}
		if(mode >= 7){
			printFont(0, 29  , "TI-WORLD ACE-SRS DS-WORLD SRS-X", 0);//SRS	
		}else{
			printFont(0, 29  , "HEBORIS TI-ARS ACE-ARS ACE-ARS2 D.R.S", 0);//ARS
		}	
		
		// 表示数を決める
		if(mode2== 3)
			max = 13;
		else if(mode2== 5)
			max =27;
		else if(mode2== 6)
			max =18;	
		else {
			max = 10;
		}	
		// ランキング表示
		for(i=0; i<max; i++) {
			if(st_end[i + tmp5] == 1)
				stcolor = 4;
			else if(st_end[i + tmp5] == 2)
				stcolor = 7;
			else
				stcolor = 0;
				
			if(mode2 <= 4){//その他
				if(mode2 == 3){
					sprintf(string[0], "%4d-%3d", i*100, (i+1)*100);
				}else{
					if(i == 9){
						sprintf(string[0], " 900-999");
					}else{
						sprintf(string[0], "%4d-%3d", i*100, (i+1)*100);
					}
				}
				
				printFont(0, 4+i, string[0], stcolor);
				// Name
				printFont(10, 4 + i, st_name[i+tmp5],stcolor);
				//タイム
				getTime(st_time[i + tmp5]);
				printFont(15, 4+i, string[0], stcolor);

				//レベルストップ
				getSTime(st_lvstop[i + tmp5]);
				printFont(25, 4+i, string[0], stcolor);
				
				//BPS
				bps = (st_others[i + tmp5] * 1000) / (st_time[i + tmp5] / 60);
				bps1 = bps / 1000;//整数
				bps2 = bps % 1000;//下三桁
				sprintf(string[0],"%d.",bps1);
				printFont(32, 4+i, string[0], stcolor);
				if(bps2>=100){
				sprintf(string[0],"%3d",bps2);
				printFont(34, 4+i, string[0], stcolor);
				}else if(bps2>=10){
				sprintf(string[0],"0%2d",bps2);
				printFont(34, 4+i, string[0], stcolor);
				}else{				
				sprintf(string[0],"00%d",bps2);
				printFont(34, 4+i, string[0], stcolor);
				}
				/*
				if(mode==2){
					printFont(2, 25, "GRADE HISTORY", 2);
					for(t=0;t<2;t++){
						for(s=0;s<5;s++){
						sprintf(string[0],"%d",grade_his[5 * t+s]);
						printFont(3*s, 26+t, string[0], tmp);
						}
						sprintf(string[0],"%d",exam_point[t]);
						printFont(20, 26+t, string[0], 0);
					}
				}
				*/
			}else{ //TOMOYO
				if(i <= 19){
					sprintf(string[0], "%d",i+1);
					printFont(1, 4+i, string[0], stcolor);
				
					// Name
					printFont(4, 4 + i, st_name[i+tmp5],stcolor);
				
					//タイム
					getTime(st_time[i + tmp5]);
					printFont(8, 4+i, string[0], stcolor);
					
					//使用ブロック数
					sprintf(string[0],"%d",st_others[i + tmp5]);
					printFont(17, 4+i, string[0], stcolor);
				
				}else if(i > 19){
					sprintf(string[0], "EX%d",i - 19);
					printFont(21, i - 16, string[0], stcolor);
				
					// Name
					printFont(25, i-16, st_name[i+tmp5],stcolor);
					
					//タイム
					getTime(st_time[i + tmp5]);
					printFont(29, i - 16, string[0], stcolor);
					
					//使用ブロック数
					sprintf(string[0],"%d",st_others[i + tmp5]);
					printFont(38, i-16, string[0], stcolor);
				}
			}
		}
		
		// 合計数表示
		sumtime = 0;
		for(i=0; i<max; i++) {
			sumtime = sumtime + st_time[i + tmp5];
		}
		printFont(1, 25, "TOTAL TIME", 1);
		getTime(sumtime);
		printFont(12, 25, string[0], 2);
		
		KeyInput();
		
		if(getPushState(0, 4) || getPushState(0, 5)) {
			// AかBで戻る
			return;
		}
		
		if(getPushState(0, 2)) {
			// ←
			PlaySE(5);
			mode--;
			if(mode < 0) mode = 13;
		}
		if(getPushState(0, 3)) {
			// →
			PlaySE(5);
			mode++;
			if(mode > 13) mode = 0;
		}
		// ↑
		if( getPushState(0,0) ) {
			PlaySE( 5 );
			if(mode>=7)mode = mode - 7;//
			else mode = mode + 7;
		}
		
		// ↓
		if( getPushState(0,1) ) {
			PlaySE( 5 );
			
			if(mode>=7)mode = mode - 7;//
			else mode = mode + 7;
		}
		spriteTime();//halt
	}
}


// ファイルフォーマット (4byte単位)	
//   0      バージョン			
//   1-50   基本情報	
//  50-60		
//  12～ 13 

// プレイヤーデータセーブ
void PlayerdataSave(int player) {//12345 6789
	int i,j, nametemp[3];
	
	if(!usePlayerdata)return;
	
	FillMemory(&saveBuf, 500 * 4, 0);
	//バージョン
	saveBuf[0] = 1;

	StrCpy(&nametemp, user_name[player]);
	saveBuf[1] = nametemp[0];
	saveBuf[2] = numofplay[player];
	saveBuf[3] = user_tspin_cnt[player];
	saveBuf[4] = user_btb_cnt[player];
	saveBuf[5] = user_ren_cnt[player];
	saveBuf[6] = user_combo_cnt[player];
	saveBuf[7] = user_ren_max[player];
	saveBuf[8] = user_combo_max[player];
	for(i = 0; i < 4; i++) saveBuf[10 + i] = user_line_cnt[player * 4 + i];
	for(i = 0; i < 20; i++) saveBuf[20 + i] = rot_select[player * 20 + i];


	for( j = 0 ; j < 2 ; j++){
		saveBuf[100 + j * 100]=max_beginner[j + player * 2];
		saveBuf[101 + j * 100]=max_novice[j+ player * 2];
		saveBuf[102 + j * 100]=masterG1_maxgrade[j+ player * 2];
		saveBuf[103 + j * 100]=masterG2_maxgrade[j+ player * 2];
		saveBuf[104 + j * 100]=masterG3_maxgrade[j+ player * 2];
		saveBuf[105 + j * 100]=masterG4_maxgrade[j+ player * 2];
		saveBuf[106 + j * 100]=admit_grade[j+ player * 2];
		saveBuf[107 + j * 100]=exam_point[j+ player * 2];
		for(i=0;i<5;i++) {
			saveBuf[108 + i + j * 100] =grade_his[(i + j * 5) + player * 10];
		}
		saveBuf[130 + j * 100]=masterG1_time[j+ player * 2];
		saveBuf[131 + j * 100]=masterG2_time[j+ player * 2];
		saveBuf[132 + j * 100]=masterG3_time[j+ player * 2];
		saveBuf[133 + j * 100]=masterG4_time[j+ player * 2];
		
		saveBuf[134 + j * 100]=max20G_time[j+ player * 2];
		saveBuf[135 + j * 100]=max20G_maxgrade[j+ player * 2];
		
		saveBuf[136 + j * 100]=max_doom_grade[j+ player * 2];
		saveBuf[137 + j * 100]=max_devilm_grade[j+ player * 2];
		saveBuf[138 + j * 100]=doom_1sthalftime[j+ player * 2];
		saveBuf[139 + j * 100]=doom_2ndhalftime[j+ player * 2];
		saveBuf[140 + j * 100]=doom_3rdhalftime[j+ player * 2];
		saveBuf[141 + j * 100]=doom_4thhalftime[j+ player * 2];
		saveBuf[142 + j * 100]=doom_5thhalftime[j+ player * 2];
		saveBuf[143 + j * 100]=doom_cleartime[j+ player * 2];
		saveBuf[144 + j * 100]=devilm_1sthalftime[j+ player * 2];
		saveBuf[145 + j * 100]=devilm_2ndhalftime[j+ player * 2];
		saveBuf[146 + j * 100]=devilm_cleartime[j+ player * 2];
		
		saveBuf[150 + j * 100]=max_tomoyoTI_stage[j+ player * 2];
		saveBuf[151 + j * 100]=max_tomoyoEH_stage[j+ player * 2];
		saveBuf[152 + j * 100]=max_tomoyoTGT_stage[j+ player * 2];
		saveBuf[153 + j * 100]=max_tomoyoFP_stage[j+ player * 2];
		saveBuf[154 + j * 100]=tomoyoTI_time[j+ player * 2];
		saveBuf[155 + j * 100]=tomoyoEH_time[j+ player * 2];
		saveBuf[156 + j * 100]=tomoyoTGT_time[j+ player * 2];
		saveBuf[157 + j * 100]=max_tomoyoFP_score[j + player*2];
		
		saveBuf[160 + j * 100]=max_ace[j+ player * 2];
		saveBuf[161 + j * 100]=max_aceAno[j+ player * 2];
		saveBuf[162 + j * 100]=max_aceHell[j+ player * 2];
		saveBuf[163 + j * 100]=max_aceOld_lv[j+ player * 2];
		saveBuf[164 + j * 100]=max_aceOld_lines[j+ player * 2];
		saveBuf[165 + j * 100]=max_aceOld_score[j+ player * 2];
		saveBuf[166 + j * 100]=ace_time[j+ player * 2];
		saveBuf[167 + j * 100]=aceAno_time[j + player*2];
		saveBuf[168 + j * 100]=aceHell_time[j + player*2];
		
		saveBuf[170 + j * 100]=max_40L_time[j+ player * 2];
		saveBuf[171 + j * 100]=max_ultra2min_lines[j+ player * 2];
		saveBuf[172 + j * 100]=max_squarecnt[j+ player * 2];
		saveBuf[173 + j * 100]=max_square_score[j+ player * 2];
		saveBuf[174 + j * 100]=max_marathon_score[j+ player * 2];
	}
	SaveFile("PLAYERDATA.SAV", &saveBuf, 300 * 4);
}

// プレイヤーデータロード
int PlayerdataLoad(int player) {
	int i,j, nametemp[3];
	
	FillMemory(&saveBuf, 500 * 4, 0);
	
	// バージョンを見る
	LoadFile("PLAYERDATA.SAV", &saveBuf, 4);
	
	if(saveBuf[0] != 1) {
		return 1;
	}
	
	// 全体を読み込む
	LoadFile("PLAYERDATA.SAV", &saveBuf, 250 * 4);
	nametemp[0] = saveBuf[1];
	StrCpy(user_name[player], &nametemp);
	numofplay[player] = saveBuf[2];
	user_tspin_cnt[player] = saveBuf[3];
	user_btb_cnt[player] = saveBuf[4];
	user_ren_cnt[player] = saveBuf[5];
	user_combo_cnt[player] = saveBuf[6];
	user_ren_max[player] = saveBuf[7];
	user_combo_max[player] = saveBuf[8];
	for(i = 0; i < 4; i++) user_line_cnt[player * 4 + i] = saveBuf[10 + i];
	for(i = 0; i < 20; i++) rot_select[player * 20 + i] = saveBuf[20 + i];

	for( j = 0 ; j < 2 ; j++){
		max_beginner[j + player * 2] = saveBuf[100 + j * 100];
		max_novice[j+ player * 2]=saveBuf[101 + j * 100];
		masterG1_maxgrade[j+ player * 2] = saveBuf[102 + j * 100];
		masterG2_maxgrade[j+ player * 2] = saveBuf[103 + j * 100];
		masterG3_maxgrade[j+ player * 2] = saveBuf[104 + j * 100];
		masterG4_maxgrade[j+ player * 2] = saveBuf[105 + j * 100];
		admit_grade[j+ player * 2] = saveBuf[106 + j * 100];
		exam_point[j+ player * 2] = saveBuf[107 + j * 100];
		for(i=0;i<5;i++) {
			grade_his[(i + j * 5) + player * 10] = saveBuf[108 + i + j * 100];
		}
		masterG1_time[j+ player * 2] = saveBuf[130 + j * 100];
		masterG2_time[j+ player * 2] = saveBuf[131 + j * 100];
		masterG3_time[j+ player * 2] = saveBuf[132 + j * 100];
		masterG4_time[j+ player * 2] = saveBuf[133 + j * 100];
		
		max20G_maxgrade[j+ player * 2] = saveBuf[134 + j * 100];
		max20G_time[j+ player * 2] = saveBuf[135 + j * 100];
		
		max_doom_grade[j+ player * 2] = saveBuf[136 + j * 100];
		max_devilm_grade[j+ player * 2] = saveBuf[137 + j * 100];
		doom_1sthalftime[j+ player * 2] = saveBuf[138 + j * 100];
		doom_2ndhalftime[j+ player * 2] = saveBuf[139 + j * 100];
		doom_3rdhalftime[j+ player * 2] = saveBuf[140 + j * 100];
		doom_4thhalftime[j+ player * 2] = saveBuf[141 + j * 100];
		doom_5thhalftime[j+ player * 2] = saveBuf[142 + j * 100];
		doom_cleartime[j+ player * 2] = saveBuf[143 + j * 100];
		devilm_1sthalftime[j+ player * 2] = saveBuf[144 + j * 100];
		devilm_2ndhalftime[j+ player * 2] = saveBuf[145 + j * 100];
		devilm_cleartime[j+ player * 2] = saveBuf[146 + j * 100];
		
		max_tomoyoTI_stage[j+ player * 2] = saveBuf[150 + j * 100];
		max_tomoyoEH_stage[j+ player * 2] = saveBuf[151 + j * 100];
		max_tomoyoTGT_stage[j+ player * 2] = saveBuf[152 + j * 100];
		max_tomoyoFP_stage[j+ player * 2] = saveBuf[153 + j * 100];
		tomoyoTI_time[j+ player * 2] = saveBuf[154 + j * 100];
		tomoyoEH_time[j+ player * 2] = saveBuf[155 + j * 100];
		tomoyoTGT_time[j+ player * 2] = saveBuf[156 + j * 100];
		max_tomoyoFP_score[j + player*2] = saveBuf[157 + j * 100];
		
		max_ace[j+ player * 2] = saveBuf[160 + j * 100];
		max_aceAno[j+ player * 2] = saveBuf[161 + j * 100];
		max_aceHell[j+ player * 2] = saveBuf[162 + j * 100];
		max_aceOld_lv[j+ player * 2] = saveBuf[163 + j * 100];
		max_aceOld_lines[j+ player * 2] = saveBuf[164 + j * 100];
		max_aceOld_score[j+ player * 2] = saveBuf[165 + j * 100];
		ace_time[j+ player * 2] = saveBuf[166 + j * 100];
		aceAno_time[j + player*2] = saveBuf[167 + j * 100];
		aceHell_time[j + player*2] = saveBuf[168 + j * 100];
		
		max_40L_time[j+ player * 2] = saveBuf[161 + j * 100];
		max_ultra2min_lines[j+ player * 2] = saveBuf[162 + j * 100];
		max_squarecnt[j+ player * 2] = saveBuf[163 + j * 100];
		max_square_score[j+ player * 2] = saveBuf[164 + j * 100];
		max_marathon_score[j+ player * 2] = saveBuf[165 + j * 100];
		}
	return 0;
}
