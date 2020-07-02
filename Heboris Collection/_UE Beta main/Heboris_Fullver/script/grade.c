/* TGM式段位上昇 */
void GradeUp(int player){
	// (S8までなら)段位上昇判定 #1.60c7g5
	if((grade[player] < 17) && (sc[player] >= gscore[grade[player]])) {
		PlayWave(30);	// rankup.wav #1.60c7i2
		grade[player]++;
		gflash[player]=120;
		gup_down[player] = 1;
	}
	// gmflag1成立判定#1.60c7g5
	if((tc[player] >= 300) && (!gmflag1_e[player])) {
		if((grade[player] >= 6) && (time[player] <= 255 * 60)){
				gmflag1[player] = 1;
				objectCreate2(player, 8, Rand(20) + 180 + 192 * player - 96 * maxPlay, 20 + Rand(10), 0, 0, 0, 0);
			}
		gmflag1_e[player] = 1;
	}
	// gmflag2成立判定#1.60c7g5
	if((tc[player] >= 500) && (!gmflag2_e[player])) {
		if((grade[player] >= 9) && (time[player] <= 450 * 60)){
				gmflag2[player] = 1;
				objectCreate2(player, 8, Rand(20) + 180 + 192 * player - 96 * maxPlay, 20 + Rand(10), 0, 0, 0, 0);
			}
		gmflag2_e[player] = 1;
	}
}
/* TAP式段位 #C7T5EX*/
void GradeUp2(int player, int lines){
	int i[2],gbai[2];
	//i[player]は素点
	if(enable_grade[player] == 1){
		if(grade[player]==0){//9
			if ( lines == 1 ) {
				i[player] = 10;
			} else if ( lines == 2 ) {
				i[player] = 15;
			} else if ( lines == 3 ) {
				i[player] = 30;
			} else {
				i[player] = 55;
			}
		}else if((grade[player]>=1)&&(grade[player]<=2)){//8,7
			if ( lines == 1 ) {
				i[player] = 10;
			} else if ( lines == 2 ) {
				i[player] = 20;
			} else if ( lines == 3 ) {
				i[player] = 30;
			} else {
				i[player] = 40;
			}
		}else if((grade[player]>=3)&&(grade[player]<=5)){//6,5,4
			if ( lines == 1 ) {
				i[player] = 10;
			} else if ( lines == 2 ) {
				i[player] = 15;
			} else if ( lines == 3 ) {
				i[player] = 25;
			} else {
				i[player] = 35;
			}
		}else if((grade[player]>=6)&&(grade[player]<=8)){//3,2,1
			if ( lines == 1 ) {
				i[player] = 5;
			} else if ( lines == 2 ) {
				i[player] = 15;
			} else if ( lines == 3 ) {
				i[player] = 23;
			} else {
				i[player] = 33;
			}
		}else if((grade[player]>=9)&&(grade[player]<=12)){//S1-S4
			if ( lines == 1 ) {
				i[player] = 3;
			} else if ( lines == 2 ) {
				i[player] = 12;
			} else if ( lines == 3 ) {
				i[player] = 15;
			} else {
				i[player] = 30;
			}
		}else if((grade[player]>=13)&&(grade[player]<=15)){//S5-S7
			if ( lines == 1 ) {
				i[player] = 3;
			} else if ( lines == 2 ) {
				i[player] = 15;
			} else if ( lines == 3 ) {
				i[player] = 20;
			} else {
				i[player] = 30;
			}
		}else if((grade[player]>=16)&&(grade[player]<=26)){//S8-m9
			if ( lines == 1 ) {
				i[player] = 4;
			} else if ( lines == 2 ) {
				i[player] = 18;
			} else if ( lines == 3 ) {
				i[player] = 23;
			} else {
				i[player] = 30;
			}
		}else if(grade[player]>=27){//M以上
			if ( lines == 1 ) {
				i[player] = 2;
			} else if ( lines == 2 ) {
				i[player] = 12;
			} else if ( lines == 3 ) {
				i[player] = 15;
			} else {
				i[player] = 20;
			}
		}
	}else if(enable_grade[player] == 2){
		if(grade2[player]==0){//9
			if ( lines == 1 ) {
				i[player] = 10;
			} else if ( lines == 2 ) {
				i[player] = 20;
			} else if ( lines == 3 ) {
				i[player] = 40;
			} else {
				i[player] = 50;
			}
		}else if((grade2[player]==1)&&(grade2[player]<=2)){//8,7
			if ( lines == 1 ) {
				i[player] = 10;
			} else if ( lines == 2 ) {
				i[player] = 20;
			} else if ( lines == 3 ) {
				i[player] = 30;
			} else {
				i[player] = 40;
			}
		}else if(grade2[player]==3){//6
			if ( lines == 1 ) {
				i[player] = 10;
			} else if ( lines == 2 ) {
				i[player] = 15;
			} else if ( lines == 3 ) {
				i[player] = 30;
			} else {
				i[player] = 45;
			}
		}else if(grade2[player]==4){
			if ( lines == 1 ) {
				i[player] = 10;
			} else if ( lines == 2 ) {
				i[player] = 15;
			} else if ( lines == 3 ) {
				i[player] = 20;
			} else {
				i[player] = 40;
			}
		}else if(grade2[player]==5){//S1-S4
			if ( lines == 1 ) {
				i[player] = 5;
			} else if ( lines == 2 ) {
				i[player] = 15;
			} else if ( lines == 3 ) {
				i[player] = 20;
			} else {
				i[player] = 30;
			}
		}else if(grade2[player]==6){//S5-S7
			if ( lines == 1 ) {
				i[player] = 5;
			} else if ( lines == 2 ) {
				i[player] = 10;
			} else if ( lines == 3 ) {
				i[player] = 20;
			} else {
				i[player] = 30;
			}
		}else if((grade2[player]>=7)&&(grade2[player]<=9)){//S8-m9
			if ( lines == 1 ) {
				i[player] = 5;
			} else if ( lines == 2 ) {
				i[player] = 10;
			} else if ( lines == 3 ) {
				i[player] = 15;
			} else {
				i[player] = 30;
			}
		}else if(grade2[player]>=10){//M以上
			if ( lines == 1 ) {
				i[player] = 2;
			} else if ( lines == 2 ) {
				i[player] = 12;
			} else if ( lines == 3 ) {
				i[player] = 13;
			} else {
				i[player] = 30;
			}
		}
	}
	
	if( ( (skillg[player] == 15) && (skillbai[player] == 0) )
		 || ( (skillg[player] == 30) && (skillbai[player] == 1) )
		 || ( (skillg[player] == 42) && (skillbai[player] == 2) )
		 || ( (skillg[player] == 50) && (skillbai[player] == 3) ) )
	{
		skillbai[player]++;
	}
	
	if(enable_grade[player] == 1){
		gbai[player] = ((tc[player] / 250) + 1) + (skillbai[player]+ 1);//倍率(レベルとSK数で決定)
	}else if(enable_grade[player] == 2){
		gbai[player] = ((tc[player] / 250) + 1)*2;//
	}
	
	if(gbai[player] < 2)gbai[player]= 2;//1以下にはならない
	 	
	i[player] = (i[player] * gbai[player]) / 2;
		
	//コンボ補正
	if(combo2[player] == 2){
		if(lines == 1){
	 		i[player] = (i[player] * 6 ) / 5;//1.2倍
		}if(lines == 2){
	 		i[player] = (i[player] * 7 ) / 5;//1.4倍
		}else if(lines == 3){
			i[player] = (i[player] * 3 ) / 2;//1.5倍
		}
	}else if(combo2[player] == 3){
		if(lines == 1){
	 		i[player] = (i[player] * 6 ) / 5;//1.2倍
		}if(lines == 2){
	 		i[player] = (i[player] * 3 ) / 2;//1.5倍
		}else if(lines == 3){
			i[player] = (i[player] * 9 ) / 5;//1.8倍
		}
	}else if(combo2[player] == 4){
		if(lines == 1){
	 		i[player] = (i[player] * 7 ) / 5;//1.4倍
		}if(lines == 2){
	 		i[player] = (i[player] * 8 ) / 5;//1.6倍
		}else if(lines == 3){
			i[player] = (i[player] * 2 );//2.0倍
		}
	}else if(combo2[player] == 5){
		if(lines == 1){
	 		i[player] = (i[player] * 7 ) / 5;//1.4倍
		}if(lines == 2){
	 		i[player] = (i[player] * 17 ) / 10;//1.7倍
		}else if(lines == 3){
			i[player] = (i[player] * 11 ) / 5;//2.2倍
		}
	}else if(combo2[player] == 6){
		if(lines == 1){
	 		i[player] = (i[player] * 7 ) / 5;//1.4倍
		}if(lines == 2){
	 		i[player] = (i[player] * 9 ) / 5;//1.8倍
		}else if(lines == 3){
			i[player] = (i[player] * 23 ) / 10;//2.3倍
		}
	}else if(combo2[player] == 7){
		if(lines == 1){
	 		i[player] = (i[player] * 7 ) / 5;//1.4倍
		}if(lines == 2){
	 		i[player] = (i[player] * 19 ) / 10;//1.9倍
		}else if(lines == 3){
			i[player] = (i[player] * 12 ) / 5;//2.4倍
		}
	}else if(combo2[player] == 8){
		if(lines == 1){
	 		i[player] = (i[player] * 3 ) / 2;//1.5倍
		}if(lines == 2){
	 		i[player] = (i[player] * 2 );//2.0倍
		}else if(lines == 3){
			i[player] = (i[player] * 5 ) / 2;//2.5倍
		}
	}else if(combo2[player] == 9){
		if(lines == 1){
	 		i[player] = (i[player] * 3 ) / 2;//1.5倍
		}if(lines == 2){
	 		i[player] = (i[player] * 21 ) /10;//2.1倍
		}else if(lines == 3){
			i[player] = (i[player] * 13 ) / 5;//2.6倍
		}
	}else if(combo2[player] == 9){
		if(lines == 1){
	 		i[player] = (i[player] * 2 );//2.0倍
		}if(lines == 2){
	 		i[player] = (i[player] * 5 ) /2;//2.5倍
		}else if(lines == 3){
			i[player] = (i[player] * 3 ) ;//3.0倍
		}
	}
	gpoint[player] = gpoint[player] + i[player];
	if(enable_grade[player] == 1){
		if(medal_sk[player] == 4)gbai[player] = 10;//SKメダルが4になると4倍
		if( (gpoint[player] >= 100) &&(grade[player] <= 30)) {//
			gup_down[player] = 1;
			gflash[player] = 120;
			PlaySE(30);//rankup.wav
			gtime[player] = 0;
			grade[player]++;
			gpoint[player] = ((gpoint[player] - 100)/ ((tc[player] / 350) + 1 + (combo2[player] / 2)));//持ち越し
		}
		
	}else if(enable_grade[player] == 2){
		if( (gpoint[player] >= 100) &&(grade2[player] <= 30)) {//MM
			gup_down[player] = 1;
			
			gtime[player] = 0;
			grade2[player]++;
			gpoint[player] = 0;
			if((grade2[player]==0)||(grade2[player]==1)||(grade2[player]==2)||(grade2[player]==3)||
			(grade2[player]==4)||(grade2[player]==5)||(grade2[player]==6)||(grade2[player]==8)||
			(grade2[player]==11)||(grade2[player]==14)||(grade2[player]==17)||(grade2[player]==18)||
			(grade2[player]==19)||(grade2[player]==22)||(grade2[player]==24)||(grade2[player]==26)||
			(grade2[player]==28)||(grade2[player]==30)){
				PlaySE(30);//rankup音
				gflash[player] = 120;
			}else {
				PlaySE(46);//cool音
			}
		}//19段位変換
		if(grade2[player]==0)
			grade[player]=0;//9
		if(grade2[player]==1)
			grade[player]=1;//8}
		if(grade2[player]==2)//7
			grade[player]=2;//7
		if(grade2[player]==3)//6
			grade[player]=3;//6
		if(grade2[player]==4)//
			grade[player]=4;//5
		if(grade2[player]==5)
			grade[player]=5;//4
		if((grade2[player]==6)||(grade2[player]==7))//21
			grade[player]=6;//3
		if((grade2[player]==8)||(grade2[player]==9)||(grade2[player]==10))//S1S2S3
			grade[player]=7;//2
		if((grade2[player]==11)||(grade2[player]==12)||(grade2[player]==13))//S4S5S6
			grade[player]=8;//1
			
		if((grade2[player]==14)||(grade2[player]==15)||(grade2[player]==16))//S7S8S9
			grade[player]=9;//S1
		if(grade2[player]==17)//m1
			grade[player]=10;//S2
		if(grade2[player]==18)//m2
			grade[player]=11;//S3
		if((grade2[player]==19)||(grade2[player]==20)||(grade2[player]==21))//m3m4
			grade[player]=12;//S4
		if((grade2[player]==22)||(grade2[player]==23))//m5m6
			grade[player]=13;//S5
		if((grade2[player]==24)||(grade2[player]==25))//m7m8
			grade[player]=14;//S6
		if((grade2[player]==26)||(grade2[player]==27))//m9M
			grade[player]=15;//S7
		if((grade2[player]==28)||(grade2[player]==29))//MKMV
			grade[player]=16;//S8
		if(grade2[player]>=30)//MM
			grade[player]=17;//S9
	//grade3つづき
	}
}
/*G#2,3のM条件*/
//一つでも条件を落とすと0
void Mconditions(int player){
	int ave_firsthalf_time[2];
	ave_firsthalf_time[player] = firsthalf_time[player] / 5;
	//G#2はTA式
	if(enable_grade[player]==1){
		//0-100：90秒以下
		//0-500：合計6分以下
		//600-900：0-500までの平均以下
		//900-999：45秒以下
		if(secCnt[player]==0){
			if(lap_time[tr[player]/10 -1 +player*30] > 90*60)gmflag3[player] = 0;
		}
		if(secCnt[player]==5){
			if(time[player] >360*60)gmflag3[player] = 0;
		}
		if((secCnt[player]>=6)&&(secCnt[player]<=8)){
			if(lap_time[tr[player]/10 -1 +player*30] > ave_firsthalf_time[player])gmflag3[player] = 0;
		}
		if(secCnt[player]==9){
			if(lap_time[tr[player]/10 -1 +player*30] > 45*60)gmflag3[player] = 0;
		}
		//0-900：4列消しを一回以上
		if((secCnt[player]>=0)&&(secCnt[player]<=8)){
			if(skillSec[player]<1 )gmflag3[player] = 0;
		}
	//G#3はTAP式
	}else if(enable_grade[player]==2){
		//0-500：65秒以下
		//500-900：前のセクションより2秒早い
		//900-999：45秒以下
		if((secCnt[player]>=0)&&(secCnt[player]<=4)){
			if(lap_time[tr[player]/10 -1 +player*30] > 65*60)gmflag3[player] = 0;
		}
		if((secCnt[player]>=5)&&(secCnt[player]<=8)){
			if(lap_time[tr[player]/10 -1 +player*30] > lap_time[tr[player]/10 -2 +player*30]-2*60)gmflag3[player] = 0;
		}
		if(secCnt[player]==9){
			if(lap_time[tr[player]/10 -1 +player*30] > 45*60)gmflag3[player] = 0;
		}
		//0-500：4列消しを二回以上
		//500-900：4列消しを一回以上
		if((secCnt[player]>=0)&&(secCnt[player]<=4)){
			if(skillSec[player]<2 )gmflag3[player] = 0;
		}
		if((secCnt[player]>=5)&&(secCnt[player]<=8)){
			if(skillSec[player]<1 )gmflag3[player] = 0;
		}
	}
	skillSec[player] = 0;
}
/* ??式段位　*/
void GradeUp3(int player) {//ブロックを置く度に
	int 	lap_timeT[2], isqcool;
	int	secinlv[2],rankGosa[2];
	
	secinlv[player] = tc[player] - ((tc[player]/100)*100);//セクション内でのレベルX88とか
	lap_timeT[player] = ( timeN[player] / (1 + ((rots[player] == 6) || (rots[player] == 8))) ) + (time99[player] * 2);//レベルストップ中は3倍加算
		// DS-WORLDで異様にCOOLが出にくいのでC7U1
	if((secinlv[player] > 80)&&(secinlv[player] < 99)&&(qualityflag[player] != 1)){//quality cool
		ave_laptime3[player] = lap_timeT[player] / secinlv[player];//セクションレベルで割る
		
		rankGosa[player] = tr2[player]/40;
		isqcool = (ave_laptime3[player] < border_time[border_rank[player]]);
		
		if(isqcool){//
			gup_down[player] = 1;//coolの文字を出す
			PlaySE(46);
			grade[player]++;	//段位を上げる
			qualityflag[player] = 1;
			gflash[player] = 240;
			gup3sp_adjust[player] = 2;	//速度スキップ
			if(gup3rank[player] <= 1){//0か1なら
				gup3rank[player]++;//ランクを上げる
			}
		}
	}
	if(secinlv[player]<94){//セクションまたぎは無効
		if((skillflag[player] != 1)){
			if(((skillg[player] >= 3)&&(tr2[player]<=10))||((skillg[player] >= 6)&&((tr2[player]>=10)&&(tr2[player]<20)))||((skillg[player] >= 4)&&(tr2[player]>=20))){//skill cool
				PlaySE(46);
				gup_down[player] = 1;
				skillg[player] = 0;
				gflash[player] = 240;
				grade[player]++;
				skillflag[player] = 1;
			}
		}
	}	
	// gmflag1成立判定（border_ranklが15以上	// gmflag2成立判定はisregret内（regretが一回もでない
	if((tc[player] >= 400) &&(!gmflag1_e[player])) {
		if(tr2[player] >= 80){
			gmflag1[player] = 1;
			objectCreate2(player, 8, Rand(20) + 180 + 192 * player - 96 * maxPlay, 20 + Rand(10), 0, 0, 0, 0);
		}
		gmflag1_e[player] = 1;
	}
}

void isregret(int player){	//100超えるごと呼び出し
	int	border_time2[2];

	border_time2[player]= border_time[border_rank[player]]+ 7;
	
	if(ave_laptime3[player]>border_time2[player]){//regret判定
		gup_down[player] = 0;//regretの文字を出す
		gflash[player] = 120;
		gmflag2[player] = 1;	// gmflag2成立剥奪
		if(grade[player]>0){
			grade[player]--;	//段位を下げる
		}
		if((gup3rank[player]==0)&&(gup3sp_adjust[player] == 0)){
			gup3sp_adjust[player] = 1;//速度
		}else{//1か2
			gup3rank[player]=0;//ランクダウン
			gup3sp_adjust[player] = 0;//速度やり直し
		}
	}else if(qualityflag[player] != 1){
		gup3sp_adjust[player] = 1;//速度そのまま
		if(gup3rank[player] == 2){	//2
			gup3rank[player]--;//ランクダウン
		}
	}
	ave_laptime3[player] = 0;
	border_rank[player] = border_rank[player] + gup3rank[player];//次の基準タイムを決める
	grade[player]++;
}

void reset_gradeup3(int player){//セクションが変わるごとにリセット
	skillg[player] = 0;
	time99[player] = 0;
	timeN[player] = 0;
	qualityflag[player] = 0;
	skillflag[player] = 0;
	gup3sp_adjust[player] = 0;	//BGMフェードのためにこれも。
	regretcancel[player] = 0;
}
