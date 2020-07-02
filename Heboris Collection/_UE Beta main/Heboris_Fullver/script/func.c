//落下点を即入れる
int dropScCalc(int player){
	if((gameMode[player] == modeNo_std)||((gameMode[player] == modeNo_tom)&&(tomoyo_opt[player]==3))||((gameMode[player] == modeNo_ace)&&(ace_opt[player] == 3))){
		return 1;
	}else{
		return 0;
	}
}

//999までのモードかどうか
int is999(int player,int rmode){
	if(((rmode[player]==modeNo_mas)||((rmode[player]== modeNo_dev)&&(subMode_opt[player]<=1)))&&(tc[player] == 999)){
		return 1;
	}else return 0;
}

int isComboMode(int player){
	if((gameMode[player] <= modeNo_pra) || (gameMode[player] == modeNo_ori)) return 1;
	else if(gameMode[player] == modeNo_mis) return (mission_type[c_mission] == 27);
	else return 0;
}

// B to B で「x1.5」を出すかどうかの判定
void isScore(int player) {
	if((gameMode[player] < 4) && (ending[player] < 2)) return 1;
	else if(gameMode[player] == modeNo_pra) return 1;
	else if((gameMode[player] == modeNo_ace) && (ace_opt[player] == 3)) return 1;
	else if(gameMode[player] == modeNo_ori) return 1;
	else return 0;
}

