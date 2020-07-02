void playerDateRegister(int player){
		if(gameMode[player] == modeNo_beg){
			if(!novice_mode[player]){
				if(hanabi_total[player]>max_beginner[cw[player]]){
					max_beginner[cw[player]] =hanabi_total[player];
				}
			}else {
				if(sc[player]>max_novice[cw[player]]){
					max_novice[cw[player]] =sc[player];
				}
			}
		}
		
		if(gameMode[player] == modeNo_mas){
			if(enable_grade[player] == 0){
				if(grade[player] > masterG1_maxgrade[cw[player]]){
					masterG1_maxgrade[cw[player]] = grade[player];
				}
			}else if(enable_grade[player] ==1){
				if(grade[player] > masterG2_maxgrade[cw[player]]){
					masterG2_maxgrade[cw[player]] = grade[player];
				}
			}else if(enable_grade[player] == 2){
				if(grade[player] > masterG3_maxgrade[cw[player]]){
					masterG3_maxgrade[cw[player]] = grade[player];
				}
			}else{
				if(grade[player] > masterG4_maxgrade[cw[player]]){
					masterG4_maxgrade[cw[player]] = grade[player];
				}
			}
			
			//認定関係
			if((statc[player*10+1]==1)&&(enable_randexam==2)&&(enable_grade[player]==3)){
				grade_his[4+cw[player]*5]=grade_his[3+cw[player]*5];//ここで暫定段位履歴をずらす
				grade_his[3+cw[player]*5]=grade_his[2+cw[player]*5];
				grade_his[2+cw[player]*5]=grade_his[1+cw[player]*5];
				grade_his[1+cw[player]*5]=grade_his[0+cw[player]*5];
				grade_his[0+cw[player]*5]=grade[player];
				
				if(admit_grade[cw[player]] > 24){
					if(grade[player] >= admit_grade[cw[player]]){
						exam_point[cw[player]] = exam_point[cw[player]]+1;
					}
					
					if(grade[player] < (admit_grade[cw[player]])-3){
						exam_point[cw[player]] = exam_point[cw[player]]-1;
					}
					
					if(grade[player] < (admit_grade[cw[player]]-9)){
						exam_point[cw[player]] = exam_point[cw[player]]-1;
					}
					
					if(grade[player] < (admit_grade[cw[player]]-18)){
						exam_point[cw[player]] = exam_point[cw[player]]-1;
					}
				}else if(admit_grade[cw[player]] > 14){
					if(grade[player] > admit_grade[cw[player]]+6){
						exam_point[cw[player]] = exam_point[cw[player]]+1;
					}
					
					if(grade[player] > (admit_grade[cw[player]])){
						exam_point[cw[player]] = exam_point[cw[player]]+1;
					}
					
					if(grade[player] < (admit_grade[cw[player]])){
						exam_point[cw[player]] = exam_point[cw[player]]-1;
					}
					
					if(grade[player] < (admit_grade[cw[player]]-9)){
						exam_point[cw[player]] = exam_point[cw[player]]-1;
					}
				}else{
					if(grade[player] > admit_grade[cw[player]]+18){
						exam_point[cw[player]] = exam_point[cw[player]]+1;
					}
					
					if(grade[player] > (admit_grade[cw[player]]+9)){
						exam_point[cw[player]] = exam_point[cw[player]]+1;
					}
					
					if(grade[player] > (admit_grade[cw[player]])){
						exam_point[cw[player]] = exam_point[cw[player]]+1;
					}
					
					if(grade[player] < (admit_grade[cw[player]]-6)){
						exam_point[cw[player]] = exam_point[cw[player]]-1;
					}
				}
			}
		}
		
		
		if(gameMode[player] == modeNo_dev){
			if(devil_opt[player]){
				if(grade[player]>max_devilm_grade[cw[player]]){
					max_devilm_grade[cw[player]] =grade[player];
				}
			}else{
				if(grade[player]>max_doom_grade[cw[player]]){
					max_doom_grade[cw[player]] =grade[player];
				}
			}
		}
		
		if(gameMode[player] == modeNo_tom){
			if(tomoyo_opt[player] == 0){
				if(max_tomoyoTI_stage[cw[player]]<stage[player]){
					max_tomoyoTI_stage[cw[player]] =stage[player];
				}
			}else if(tomoyo_opt[player] == 1){
				if(max_tomoyoEH_stage[cw[player]]<stage[player]){
					max_tomoyoEH_stage[cw[player]] =stage[player];
				}
			}else if(tomoyo_opt[player] == 2){
				if(max_tomoyoTGT_stage[cw[player]]<stage[player]){
					max_tomoyoTGT_stage[cw[player]] =stage[player];
				}
			}else if(tomoyo_opt[player] == 3){
				if(max_tomoyoFP_stage[cw[player]]<stage[player]){
					max_tomoyoFP_stage[cw[player]] =stage[player];
				}
			}
		}
		
		PlayerdataSave(player);//プレイヤーデータセーブ
}
