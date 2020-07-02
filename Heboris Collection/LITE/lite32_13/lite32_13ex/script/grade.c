// 段位上昇判定（MASTER-EASY）
void GradeUpEasy(int player) {
	// 基準スコア達成
	while((grade[player] < 17) && (sc[player] >= master_easy_score_table[grade[player]])) {
		gup_down[player] = 1;
		gflash[player] = 120;
		PlaySE(31);
		grade[player]++;
		
		// S9になると流れ星
		if(grade[player] >= 17) objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
	}
}

// MASTER-NORMAL段位上昇判定 #LITE28
// C7T7.1EXを適当にコピペ改造しますた #LITE30.6
void GradeUp(int player, int lines) {
	int i, gbai;

	// 段位ポイントを上げるための倍率を計算
	if(lines >= 4) gskill[player]++;					// 4段消しボーナス
	
	if( (lines >= 2) && 
		(((tc[player] < 500) && (combo2[player] >= 4)) || ((tc[player] >= 500) && (combo2[player] >= 3))) )
	{
		gskill[player]++;								// コンボボーナス
	}
	
	if(bonus_tspin)
		gskill[player] = gskill[player] + IsTspin[player];	// T-SPINボーナス
	
	if( ((gskill[player] == 15) && (gskbai[player] == 0)) || 
		((gskill[player] == 30) && (gskbai[player] == 1)) || 
		((gskill[player] == 42) && (gskbai[player] == 2)) || 
		((gskill[player] == 50) && (gskbai[player] == 3)) )
	{
		gskbai[player]++;
	}
	
	// 上昇する段位ポイントの基本点を決める
	if(grade[player] == 0) {
		// 9
		if(lines == 1) i = 10;
		if(lines == 2) i = 15;
		if(lines == 3) i = 30;
		if(lines == 4) i = 55;
	} else if((grade[player] >= 1) && (grade[player] <= 2)) {
		// 8,7
		if(lines == 1) i = 10;
		if(lines == 2) i = 20;
		if(lines == 3) i = 30;
		if(lines == 4) i = 40;
	} else if((grade[player] >= 3) && (grade[player] <= 5)) {
		// 6,5,4
		if(lines == 1) i = 10;
		if(lines == 2) i = 15;
		if(lines == 3) i = 25;
		if(lines == 4) i = 35;
	} else if((grade[player] >= 6) && (grade[player] <= 8)) {
		// 3,2,1
		if(lines == 1) i = 5;
		if(lines == 2) i = 15;
		if(lines == 3) i = 23;
		if(lines == 4) i = 33;
	} else if((grade[player] >= 9) && (grade[player] <= 12)) {
		// S1-S4
		if(lines == 1) i = 3;
		if(lines == 2) i = 12;
		if(lines == 3) i = 15;
		if(lines == 4) i = 30;
	} else if((grade[player] >= 13) && (grade[player] <= 15)) {
		// S5-S7
		if(lines == 1) i = 3;
		if(lines == 2) i = 15;
		if(lines == 3) i = 20;
		if(lines == 4) i = 30;
	} else if((grade[player] >= 16) && (grade[player] <= 26)) {
		// S8-m9
		if(lines == 1) i = 4;
		if(lines == 2) i = 18;
		if(lines == 3) i = 23;
		if(lines == 4) i = 30;
	} else {
		// M以上
		if(lines == 1) i = 2;
		if(lines == 2) i = 12;
		if(lines == 3) i = 15;
		if(lines == 4) i = 20;
	}

	// レベルによる倍率
	gbai = ((tc[player] / 350) + 1);
	
	// gskbaiによる加点
	gbai = gbai + gskbai[player];
	
	// 最低でも2倍
	if(gbai < 2) gbai = 2;
	
	i = (i * gbai) / 2;

	// コンボによる段位ポイント上昇補正
	if((combo[player] - 1) > 0) {
		if(combo2[player] <= 2) {
			// 1コンボ～2コンボ
			if(lines == 2) i = (i *  6 * (combo2[player] - 1)) /  5;		// 1.2倍
			if(lines == 3) i = (i * 13 * (combo2[player] - 1)) / 10;		// 1.3倍
			if(lines == 4) i = (i *  3 * (combo2[player] - 1)) /  2;		// 1.5倍
		} else if(combo2[player] <= 4) {
			// 3コンボ～4コンボ
			if(lines == 1) i = (i * 21 * (combo[player]  - 1)) / 20;		// 1.05倍
			if(lines == 2) i = (i * 11 * (combo2[player] - 1)) / 10;		// 1.1 倍
			if(lines == 3) i = (i *  6 * (combo2[player] - 1)) /  5;		// 1.2 倍
			if(lines == 4) i = (i *  3 * (combo2[player] - 1)) /  2;		// 1.5 倍
		}
	}

	// 最低でも1ポイントは上昇させる
	if(i < 1) i = 1;

	// 段位ポイント上昇
	gpoint[player] = gpoint[player] + i;

	// 段位上昇
	if( (gpoint[player] >= 100) && (grade[player] <= 28) ) {	// MVまで
		gup_down[player] = 1;
		gflash[player] = 120;
		PlaySE(31);
		
		// ポイント持ち越し
		gpoint[player] = ((gpoint[player] - 100) / ((tc[player] / 350) + 1 + (combo2[player] / 2)));
		
		gtime[player] = 0;
		grade[player]++;
	}

	// gmflag1成立判定#C7T5EX
	if((tc[player] >= 500) && (!gmflag1_e[player])) {
		if((grade[player] >= 12) && (gameTimer[player] <= 300 * 60)) {
			gmflag1[player] = 1;
		}
		gmflag1_e[player] = 1;
		
		objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
	}

	// gmflag2成立判定#C7T5EX
	if((tc[player] >= 700) && (!gmflag2_e[player])) {
		if((grade[player] >= 18) && (gameTimer[player] <= 390 * 60)) {
			gmflag2[player] = 1;
		}
		gmflag2_e[player] = 1;
		
		objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
	}
}

// HARDのときの段位
// ブロックを置くたびに呼び出し
void GradeUp3(int player) {
	int lap_timeT, secinlv, tmp, border;
	
	secinlv = tc[player] - ((tc[player] / 100) * 100);		// レベルの下2桁
	lap_timeT = ( timeN[player] / (1 + (rule_are[rots[player]] != 1)) ) + (time99[player] * 2);
	
	// quality cool
	if((secinlv > 80) && (secinlv < 99) && (!qualityflag[player])) {
		// セクションレベルで割る
		ave_laptime3[player] = lap_timeT / secinlv;
		
		if(repversw <= 6) border = border_time6[border_rank[player]];
		else border = border_time[border_rank[player]];
		
		// COOL
		if(ave_laptime3[player] < border) {
			PlaySE(48);
			gup_down[player] = 1;		// COOLの文字を出す
			grade[player]++;			// 段位+1
			gflash[player] = 180;		// COOL表示時間設定
			
			qualityflag[player] = 1;	// 2回以上COOLを出さないようにする
			gup3sp_adjust[player] = 2;	// 速度スキップ
			
			if(gup3rank[player] <= 1)
				gup3rank[player]++;		// ランクを上げる
			
			if(tr2[player] < 51) {
				tc_20g[player] = tc_20g[player] - 100;	// フェードアウト予定レベル前倒し
				if(tc_20g[player] < 285) tc_20g[player] = 285;
			}
		}
	}
	
	// skill cool（セクションまたぎは無効）
	if((!skillflag[player]) && (secinlv < 94)) {
		if(repversw >= 3) {
			if(tc[player] < 100) tmp = 3;
			else if(tc[player] < 200) tmp = 6;
			else tmp = 4;
		} else {
			if(tr2[player] <= 10) tmp = 3;
			else tmp = 4;
		}
		
		if(gskill[player] >= tmp) {
			PlaySE(48);
			gup_down[player] = 1;		// COOLの文字を出す
			grade[player]++;			// 段位+1
			gflash[player] = 180;		// COOL表示時間設定
			skillflag[player] = 1;		// 2回以上COOLを出さないようにする
			gskill[player] = 0;			// スキルリセット
		}
	}
	
	// gmflag1成立判定（LV400になったときにtr2変数が80以上）
	if((tc[player] >= 400) && (!gmflag1_e[player])) {
		if(tr2[player] >= 80) {
			gmflag1[player] = 1;
			gmflag1_e[player] = 1;
			objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
		}
	}
	
	// gmflag2成立判定はisregret内（regretが一回もでない）
}

// REGRET判定
// 100超えるごとに呼び出し
void isregret(int player) {
	int border_time2, regretgosa, border;
	
	if(repversw <= 6) border = border_time6[border_rank[player]];
	else border = border_time[border_rank[player]];
	
	regretgosa = tr2[player] / 40;
	border_time2 = border + 6 + regretgosa;
	
	if(ave_laptime3[player] > border_time2) {
		// REGRET
		PlaySE(44);
		gup_down[player] = 0;
		gflash[player] = 120;
		
		// 降格
		if(grade[player] > 0) grade[player]--;
		
		// 速度を下げる
		if((gup3rank[player] == 0) && (gup3sp_adjust[player] == 0)) {
			gup3sp_adjust[player] = 1;
		} else {
			// まだBGMがフェードアウトしていない場合だけ速度やり直し
			if(!regretcancel[player]) {
				gup3rank[player] = 0;
				gup3sp_adjust[player] = 0;
				
				if(tr2[player] < 51) {
					tc_20g[player] = tc_20g[player] + 100;	// フェードアウト予定レベル延期
					if(tc_20g[player] > 485) tc_20g[player] = 485;
				}
			}
		}
		
		// GM条件剥奪
		gmflag2[player] = 1;
	} else if(!qualityflag[player]) {
		// 速度そのまま
		gup3sp_adjust[player] = 1;
		
		// ランクが2なら1にダウンさせる
		if(gup3rank[player] == 2) gup3rank[player]--;
	}
	
	// 次の基準タイムを決める
	border_rank[player] = border_rank[player] + gup3rank[player];
	
	ave_laptime3[player] = 0;
	grade[player]++;
}

// セクションが変わるごとに変数をリセットする
void reset_gradeup3(int player) {
	gskill[player] = 0;
	time99[player] = 0;
	timeN[player] = 0;
	qualityflag[player] = 0;
	skillflag[player] = 0;
	regretcancel[player] = 0;
	gup3sp_adjust[player] = 0;
	regretcancel[player] = 0;
}
