//������������������������������������������������������������������������������
//  �A�C�e����������
//������������������������������������������������������������������������������
void eraseItem(int player, int type) {
	int i, enemy;
	int bx2, by2;
	int data[2];
	int attack, instant, destroy;
	int move;
	
	// �g�����A�C�e�����U���A�C�e�����ǂ������f
	attack = 0;
	
	if((type != 13) && (type != 17) && (type != 18) && (type != 19) && (type != 27) && 
	   (type != 28) && (type != 29) && (type != 30) && (type != 32) && (type != 33) && 
	   (type != 35) && (type != 36))
	{
		attack = 1;
	}
	
	// �����Ώۂ����߂�
	if(gameMode[player] == 4) {
		if(isreflect[1 - player]) {
			enemy = player;
		} else {
			enemy = 1 - player;
		}
	} else {
		enemy = player;
	}
	
	// �G���u���b�N�𑀍삵�Ă��邩����
	move = ((stat[enemy] == 5) && (!statc[enemy * 10 + 2]));
	
	// �����Ώێ҂̃A�C�e�����ʂ������i�U���A�C�e���̏ꍇ�j
	if(attack) {
		item_t[enemy] = 0;
		item_timer[enemy] = 0;
		
		stopmirror_flag[enemy] = 1;
		isrollroll[enemy] = 0;
		IsBig[enemy] = IsBigStart[enemy];
		BigMove[enemy] = BigMoveStart[enemy];
		isxray[enemy] = 0;
		iscolor[enemy] = 0;
		isRotateLock[enemy] = 0;
		ishidenext[enemy] = 0;
		ismagnetblock[enemy] = 0;
		istimestop[enemy] = 0;
		isholdlock[enemy] = 0;
		isLRreverse[enemy] = 0;
		isboost[enemy] = 0;
		isfever[enemy] = 0;
		isUDreverse[enemy] = 0;
		isremote[enemy] = 0;
		isdark[enemy] = 0;
		istrance[enemy] = 0;
		dolaser[enemy] = 0;
		donega[enemy] = 0;
		doshotgun[enemy] = 0;
		doexchg[enemy] = 0;
		isbanana[enemy] = 0;
		do16t[enemy] = 0;
		isdouble[enemy] = 0;
		ismiss[enemy] = 0;
		purupuru[enemy] = 0;
		docopyfld[enemy] = 0;
		isfakenext[enemy] = 0;
		item_monochrome[enemy] = 0;
	}
	
	instant = 0;	// �����ɔ������邩�ǂ����̃t���O
	
	// MIRROR BLOCK
	if(type == 1)
	{
		isfmirror[enemy] = 1;
		stopmirror_flag[enemy] = 0;
	}
	// ROLL ROLL
	if(type == 2)
	{
		isrollroll[enemy] = 1;
	}
	// DEATH BLOCK
	if(type == 3)
	{
		IsBig[enemy] = 1;
		BigMove[enemy] = 0;
		n_bx[enemy] = 2;
	}
	// X-RAY
	if(type == 4)
	{
		isxray[enemy] = 1;
	}
	// COLOR BLOCK
	if(type == 5)
	{
		iscolor[enemy] = 1;
	}
	// ROTATE LOCK
	if(type == 6)
	{
		isRotateLock[enemy] = 1;
		
		// NEXT�̌����������_����
		for(i = 0; i < 6; i++) rt_nblk[i + enemy * 6] = GiziRand(enemy, 4);
		
		item_timer[enemy] = 600;
	}
	// HIDE NEXT
	if(type == 7)
	{
		ishidenext[enemy] = 1;
		item_timer[enemy] = 900;
	}
	// MAGNET BLOCK
	if(type == 8)
	{
		ismagnetblock[enemy] = 1;
	}
	// TIME STOP
	if(type == 9)
	{
		istimestop[enemy] = 1;
		item_timer[enemy] = 300;
	}
	// HOLD LOCK
	if(type == 10)
	{
		isholdlock[enemy] = 1;
	}
	// ���� REVERSE
	if(type == 11)
	{
		isLRreverse[enemy] = 1;
		item_timer[enemy] = 600;
	}
	// BOOST FIRE
	if(type == 12)
	{
		if(!heboGB[enemy]) {
			isboost[enemy] = 1;
			item_timer[enemy] = 600;
		}
	}
	// FEVER!!
	if(type == 13)
	{
		isfever[player] = 1;
		item_timer[player] = 600;
	}
	// ���� REVERSE
	if(type == 14)
	{
		isUDreverse[enemy] = 1;
		item_timer[enemy] = 600;
	}
	// REMOTE CONTROL
	if(type == 15)
	{
		if(gameMode[0] == 4) isremote[enemy] = 1;
	}
	// DARK BLOCK
	if(type == 16)
	{
		isdark[enemy] = 1;
		item_timer[enemy] = 480;
	}
	// ��DEL FIELD
	if(type == 17)
	{
		isUPdelfield[player] = 1;
	}
	// ��DEL FIELD
	if(type == 18)
	{
		isDWdelfield[player] = 1;
	}
	// DEL EVEN
	if(type == 19)
	{
		isdeleven[player] = 1;
	}
	// TRANCE FORM
	if(type == 20)
	{
		istrance[enemy] = 1;
	}
	// LASER
	if(type == 21)
	{
		dolaser[enemy] = 1;
		instant = 1;
		
		if((stat[enemy] == 5) && (!statc[enemy * 10 + 2])) {
			stat[enemy] = 27;
			statc[enemy * 10] = 0;
			statc[enemy * 10 + 1] = 4;
		}
	}
	// NEGA FIELD
	if(type == 22)
	{
		donega[enemy] = 1;
		instant = 1;
		
		if((stat[enemy] == 5) && (!statc[enemy * 10 + 2])) {
			stat[enemy] = 28;
			statc[enemy * 10] = 0;
			statc[enemy * 10 + 1] = 4;
		}
	}
	// SHOT GUN!
	if(type == 23)
	{
		doshotgun[enemy] = 1;
		instant = 1;
		
		if((stat[enemy] == 5) && (!statc[enemy * 10 + 2])) {
			stat[enemy] = 29;
			statc[enemy * 10] = 0;
			statc[enemy * 10 + 1] = 4;
		}
	}
	// EXCHG FIELD
	if(type == 24)
	{
		doexchg[player] = 1;
		doexchg[enemy] = 1;
		objectCreate(player, 8, 0, 0, 0, 0, type - 1, 0);
	}
	// HARD BLOCK
	if(type == 25)
	{
		item_nblk[0 + enemy * 6] = fldihardno;
	}
	// SHUFFLE FIELD
	if(type == 26)
	{
		isbanana[enemy] = 1;
	}
	// RANDOM
	if(type == 27)
	{
		dorulet[player] = 1;
	}
	// FREE FALL
	if(type == 28)
	{
		isFreefall[player] = 1;
	}
	// ��MOV FIELD
	if(type == 29)
	{
		isLmovfield[player] = 1;
	}
	// ��MOV FIELD
	if(type == 30)
	{
		isRmovfield[player] = 1;
	}
	// 180��FIELD
	if(type == 31)
	{
		do180field[enemy] = 1;
	}
	// 16t
	if(type == 32)
	{
		do16t[player] = 1;
	}
	// REFLECT
	if(type == 33)
	{
		isreflect[player] = 1;
		item_timer[player] = 300;
	}
	// DOUBLE
	if(type == 34)
	{
		isdouble[enemy] = 1;
		item_timer[enemy] = 600;
	}
	// ALL CLEAR
	if(type == 35)
	{
		isallclear[player] = 1;
	}
	// MISS
	if(type == 36)
	{
		ismiss[player] = 1;
		purupuru[player] = 1;
		objectCreate(player, 8, 0, 0, 0, 0, type - 1, 0);
	}
	// COPY FIELD
	if(type == 37)
	{
		docopyfld[enemy] = 1;
	}
	// FAKE NEXT
	if(type == 38)
	{
		isfakenext[enemy] = 1;
		item_timer[enemy] = 480;
	}
	// [] BLOCK
	if(type == 39)
	{
		item_monochrome[enemy] = 1;
	}
	
	// ����̃u���b�N��e����΂����ǂ������߂�
	if(attack) {
		if((type == 6) || (type == 7) || (type == 11) || (type == 12) || (type == 14) || (type == 26) || 
		   (type == 34) || (type == 38) || (type == 39))
			destroy = 0;
		else
			destroy = 1;
	}
	
	if(move && attack && destroy) {
		// �g�����A�C�e�����U���A�C�e���Ȃ瑊��v���C���[�̑��쒆�u���b�N��e����΂�
		for(i = 0; i < 4; i++) {
			getBlockData(enemy, bx[enemy], by[enemy], blk[enemy], rt[enemy], i, &data);
			bx2 = data[0];
			by2 = data[1];
			
			objectCreate(enemy, 6, (bx2 + boffset[enemy]) * 8, (by2 + 3) * 8, (bx2 - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + 250, c_cblk[enemy], 100);
		}
		
		// �A�C�e�������ł�����
		if(item[enemy]) {
			item[enemy] = 0;
			scanItem(enemy);
		}
		
		// �����I�Ɏ��̃u���b�N���o��������
		if(!instant) {
			stat[enemy] = 25;
			statc[enemy * 10] = wait1[enemy] * 2;
			statc[enemy * 10 + 1] = 4;
		}
	}
	
	if(attack) {
		// �����x��
		objectCreate(enemy, 8, 0, 0, 0, 0, type - 1, 0);
	}
	
	item_waiting[player] = 0;
	
	// �t�B�[���h�Ɏc���Ă���A�C�e����S�ď���
	for(i = 0; i < 220; i++) {
		if(fldi[i + player * 220] < fldihardno) fldi[i + player * 220] = 0;
	}
	item[player] = 0;
	
	scanItem(player);
}

//������������������������������������������������������������������������������
//  �������A�C�e���̌��ʏI��
//������������������������������������������������������������������������������
void endTimerItem(int player) {
	int i;
	
	// ROTATE LOCK
	if(isRotateLock[player]) {
		isRotateLock[player] = 0;
		
		// NEXT�̌�����߂�
		for(i = 0; i < 6; i++) rt_nblk[i + player * 6] = 0;
	}
	// HIDE NEXT
	if(ishidenext[player]) {
		ishidenext[player] = 0;
	}
	// TIME STOP
	if(istimestop[player]) {
		istimestop[player] = 0;
	}
	// ���� REVERSE
	if(isLRreverse[player]) {
		isLRreverse[player] = 0;
	}
	// BOOST FIRE
	if(isboost[player]) {
		isboost[player] = 0;
	}
	// FEVER!!
	if(isfever[player]) {
		isfever[player] = 0;
	}
	// ���� REVERSE
	if(isUDreverse[player]) {
		isUDreverse[player] = 0;
	}
	// DARK BLOCK
	if(isdark[player]) {
		isdark[player] = 0;
	}
	// REFLECT
	if(isreflect[player]) {
		isreflect[player] = 0;
	}
	// DOUBLE
	if(isdouble[player]) {
		isdouble[player] = 0;
	}
	// FAKE NEXT
	if(isfakenext[player]) {
		isfakenext[player] = 0;
	}
}

//������������������������������������������������������������������������������
//  �A�C�e���o�������^�񐔐��A�C�e���̌��ʏI��
//������������������������������������������������������������������������������
void setItemStatus(int player) {
	int i, limit, tmp, tmp2;
	
	// �A�C�e���Q�[�W�㏸
	if((item_gauge_uptype <= 1) && (!ismiss[player])) item_g[player]++;
	
	// �A�C�e���o��
	if(item_g[player] > item_interval) {
		PlaySE(28);
		
		if(item_all[player] >= 2) {
			// �o������\��������A�C�e����2�ȏ�̂Ƃ�
			limit = 0;	// �������[�v�h�~�p
			
			do {
				tmp = 1;
				tmp2 = GiziRand(player, item_pronum) + 1;
				
				while(1) {
					tmp2 = tmp2 - item_pro[tmp - 1];
					if(tmp2 < 0) break;
					
					tmp++;
					if(tmp > item_num + 1) break;
				}
				
				limit++;
				if(limit > 100000) break;
			} while((item_switch[tmp - 1] == 0) || 
			        (itemhistory[0 + player * 5] == tmp) || (itemhistory[1 + player * 5] == tmp) || 
			        (itemhistory[2 + player * 5] == tmp) || (itemhistory[3 + player * 5] == tmp) || 
			        (itemhistory[4 + player * 5] == tmp));
			
			item_coming[player] = tmp;	// �A�C�e���m��
			
			// ���������炷
			itemhistory[0 + player * 5] = itemhistory[1 + player * 5];
			itemhistory[1 + player * 5] = itemhistory[2 + player * 5];
			itemhistory[2 + player * 5] = itemhistory[3 + player * 5];
			itemhistory[3 + player * 5] = itemhistory[4 + player * 5];
			itemhistory[4 + player * 5] = tmp;
		} else if(item_all[player] == 1) {
			// �o������\��������A�C�e����1�̂Ƃ�
			for(i = 0; i < 39; i++) {
				if(item_switch[i] != 0) {
					item_coming[player] = i + 1;
					break;
				}
			}
		} else {
			// �o������\��������A�C�e����0�̂Ƃ�
			item_coming[player] = GiziRand(player, item_num) + 1;
		}
		
		item_name[player] = item_coming[player];
		item_g[player] = 0;
		itemappear_c[player] = 30;
	} else {
		item_coming[player] = 0;
	}
	
	if(isfmirror[player] || isrollroll[player] || IsBig[player] || isxray[player] || iscolor[player] || 
	   ismagnetblock[player] || isholdlock[player] || isremote[player] || istrance[player] || ismiss[player] || 
	   item_monochrome[player])
	{
		// �A�C�e�����ʎ��ԑ���
		item_t[player]++;
		
		// �A�C�e�����ʏI��
		// MIRROR BLOCK
		if((isfmirror[player]) && (item_t[player] > 3)) {
			isfmirror[player] = 0;
			stopmirror_flag[player] = 0;
		}
		// ROLL ROLL
		if((isrollroll[player]) && (item_t[player] > 3)) {
			isrollroll[player] = 0;
		}
		// DEATH BLOCK
		if((IsBig[player]) && (item_t[player] > 1)) {
			IsBig[player] = IsBigStart[player];
			BigMove[player] = BigMoveStart[player];
			n_bx[player] = 3;
		}
		// X-RAY
		if((isxray[player]) && (item_t[player] > 4)) {
			isxray[player] = 0;
		}
		// COLOR BLOCK
		if((iscolor[player]) && (item_t[player] > 3)) {
			iscolor[player] = 0;
		}
		// MAGNET BLOCK
		if((ismagnetblock[player]) && (item_t[player] > 2)) {
			ismagnetblock[player] = 0;
		}
		// HOLD LOCK
		if((isholdlock[player]) && (item_t[player] > 6)) {
			isholdlock[player] = 0;
		}
		// REMOTE CONTROL
		if((isremote[player]) && (item_t[player] > 2)) {
			isremote[player] = 0;
		}
		// TRANCE FORM
		if((istrance[player]) && (item_t[player] > 3)) {
			istrance[player] = 0;
		}
		// MISS
		if((ismiss[player]) && (item_t[player] > item_interval)) {
			ismiss[player] = 0;
			purupuru[player] = 0;
		}
		// [] BLOCK
		if((item_monochrome[player]) && (item_t[player] > 20)) {
			item_monochrome[player] = 0;
		}
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.21 - ���C����������
//������������������������������������������������������������������������������
// statc[player * 10]    �F�J�E���^
// statc[player * 10 + 1]�F�I����Ɉړ�����X�e�[�^�X
// statc[player * 10 + 2]�F1�̏ꍇ�̓��C��������ɏ�ɂ������u���b�N�𗎂Ƃ�
void statDelField(int player) {
	int i, j, anim, anim2, anim3;
	
	// ������
	padRepeat(player);
	
	// �VIRS
	if(ace_irs) doNewIRS(player, 0);
	
	// HYPER����s�ړ�
	if(fastlrmove == 3) HyperLRMove(player);
	
	if(wait1[player] > 0) {
		anim = wait1[player];
		anim2 = wait1[player] + 1;
		anim3 = wait1[player];
	} else {
		anim = 1;
		anim2 = 2;
		anim3 = 1;
	}
	
	statc[player * 10]++;
	
	// ���C������
	if(statc[player * 10] < 15 + (anim * 2)) {
		for(i = 0; i < 22; i++) {
			if(erase[i + player * 22]) {
				BltRect(5, (boffset[player]) * 8, (i + 3) * 8, 0, (statc[player * 10] - anim2) * 8, 80, 8);
				
				if(statc[player * 10] == anim3) {
					for(j = 0; j < 10; j++) {
						fld[j + i * 10 + player * 220] = 0;
						fldt[j + i * 10 + player * 220] = 0;
						fldi[j + i * 10 + player * 220] = 0;
						fldo[j + i * 10 + player * 220] = 0;
						grayoutLackedBlock(player, flds[j + i * 10 + player * 220]);
						flds[j + i * 10 + player * 220] = 0;
					}
				}
			}
		}
	}
	
	// ��������
	if((statc[player * 10] == 15 + (anim * 2)) && (statc[player * 10 + 2])) {
		downFloatingBlocks(player);
		PlaySE(2);
	}
	
	// �I��
	if(statc[player * 10] > 15 + (anim * 2) + (anim * statc[player * 10 + 2])) {
		isUPdelfield[player] = 0;
		isDWdelfield[player] = 0;
		isdeleven[player] = 0;
		isallclear[player] = 0;
		stat[player] = statc[player * 10 + 1];
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = 0;
		for(i = 0; i < 22; i++) erase[i + player * 22] = 0;
		pinchCheck(player);
		scanItem(player);
		rest_pblock[player] = getPlatinumBlock(player);
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.27 - ���[�U�[�i16t�j
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 1]�F�I����Ɉړ�����X�e�[�^�X
// statc[player * 10 + 2]�F16t���H
void statLaser(int player) {
	int i, j, k;
	
	padRepeat(player);
	if((ace_irs) && (statc[player * 10] > 120)) doNewIRS(player, 0);
	if((fastlrmove == 3) && (statc[player * 10] > 120)) HyperLRMove(player);
	
	// �����ݒ�
	if(statc[player * 10] == 0) {
		lasernum[player] = 0;
		
		laserpos[0 + player * 4] = bx[player] + GiziRand(player, 4) - 2;
		if(laserpos[0 + player * 4] < 0) laserpos[0 + player * 4] = 0;
		
		// �Ə��̈ʒu��ݒ�
		if(!statc[player * 10 + 2]) {
			// ���[�U�[
			if(laserpos[0 + player * 4] > 9) laserpos[0 + player * 4] = 9;
		} else {
			// 16t
			if(laserpos[0 + player * 4] > 7) laserpos[0 + player * 4] = 7;
		}
		
		rapid_c[player] = 0;
	}
	// ���[�U�[���ˑO
	else if(statc[player * 10] < 120) {
		// ����炷
		if(statc[player * 10] % 7 == 0) PlaySE(3);
		
		// ���[�U�[�p
		if(!statc[player * 10 + 2]) {
			// �{�^���A�ł�F��
			if(getPushState(player, 4) || getPushState(player, 5) || getPushState(player, 6) || getPushState(player, 7)) {
				rapid_c[player]++;
			}
			// ���[�U�[�����i�ő��4�{�j
			if((rapid_c[player] > 4) && (lasernum[player] < 3)) {
				lasernum[player]++;
				laserpos[lasernum[player] + player * 4] = GiziRand(player, 10);
				rapid_c[player] = 0;
			}
			
			// �Ə����ړ�
			// ��
			if(getPushState(player, 2) && (statc[player * 10] % 10 < 2)) {
				for(i = 0; i <= lasernum[player]; i++) {
					if(laserpos[i + player * 4] > 0) laserpos[i + player * 4]--;
				}
			}
			// ��
			if(getPushState(player, 3) && (statc[player * 10] % 10 < 2)) {
				for(i = 0; i <= lasernum[player]; i++) {
					if(laserpos[i + player * 4] < 9) laserpos[i + player * 4]++;
				}
			}
			
			// �Ə���\��
			for(i = 0; i <= lasernum[player]; i++) {
				BltRect(28, (boffset[player] + laserpos[i + player * 4] - 1) * 8, 24, 0, 0, 24, 24);
			}
		}
		// 16t�p
		else {
			// �Ə����ړ�
			// ��
			if(getPushState(player, 2)) {
				if(laserpos[0 + player * 4] > 0) laserpos[0 + player * 4]--;
			}
			// ��
			if(getPushState(player, 3)) {
				if(laserpos[0 + player * 4] < 7) laserpos[0 + player * 4]++;
			}
			
			// �Ə���\��
			BltRect(3, (boffset[player] + laserpos[0 + player * 4] - 1) * 8, 18, 0, 203, 32, 23);
		}
	}
	// ���[�U�[���˂̏u��
	else if(statc[player * 10] == 120) {
		PlaySE(11 + lasernum[player]);
		
		// �Ə������̃u���b�N������
		if(!statc[player * 10 + 2]) {
			// ���[�U�[
			for(i = 0; i <= lasernum[player]; i++) {
				k = laserpos[i + player * 4];
				
				BltRect(28, (boffset[player] + k) * 8, 40, 24, 0, 8, 160);
				BltRect(28, (boffset[player] + k - 1) * 8, 24, 0, 0, 24, 24);
				
				for(j = 0; j < 22; j++) {
					if(fld[k + j * 10 + player * 220]) {
						if(fldo[k + j * 10 + player * 220] == 0) {
							objectCreate(player, 1, (k + boffset[player]) * 8, (j + 3) * 8, (k - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + 1 * 250, fld[k + j * 10 + player * 220] - 1, 100);
						}
						fld[k + j * 10 + player * 220] = 0;
						fldt[k + j * 10 + player * 220] = 0;
						fldi[k + j * 10 + player * 220] = 0;
						fldo[k + j * 10 + player * 220] = 0;
						grayoutLackedBlock(player, flds[k + j * 10 + player * 220]);
						flds[k + j * 10 + player * 220] = 0;
					}
				}
			}
		} else {
			// 16t
			for(i = 0; i < 3; i++) {
				k = laserpos[0 + player * 4] + i;
				
				for(j = 0; j < 22; j++) {
					if(fld[k + j * 10 + player * 220]) {
						if(fldo[k + j * 10 + player * 220] == 0) {
							objectCreate(player, 1, (k + boffset[player]) * 8, (j + 3) * 8, (k - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + 1 * 250, fld[k + j * 10 + player * 220] - 1, 100);
						}
						fld[k + j * 10 + player * 220] = 0;
						fldt[k + j * 10 + player * 220] = 0;
						fldi[k + j * 10 + player * 220] = 0;
						fldo[k + j * 10 + player * 220] = 0;
						grayoutLackedBlock(player, flds[k + j * 10 + player * 220]);
						flds[k + j * 10 + player * 220] = 0;
					}
				}
			}
		}
	}
	// ���[�U�[���ˌ�
	else {
		if(!statc[player * 10 + 2]) {
			// ���[�U�[
			for(i = 0; i <= lasernum[player]; i++) {
				if(statc[player * 10] - 120 < 34) {
					j = (statc[player * 10] - 120) / 2;
					BltRect(28, (boffset[player] + laserpos[i + player * 4]) * 8, 40, 24 + (j * 8), 0, 8, 160);
				}
				BltRect(28, (boffset[player] + laserpos[i + player * 4] - 1) * 8, 24, 0, 0, 24, 24);
			}
		} else {
			// 16t
			j = (statc[player * 10] - 120) * 3;
			
			if(j < 20) {
				BltRect(3, (boffset[player] + laserpos[0 + player * 4] - 1) * 8, ((j + 3) * 8) + 18, 0, 203, 32, 23);
			}
		}
	}
	
	// �J�E���^����
	statc[player * 10]++;
	
	// ���̃X�e�[�^�X��
	if(statc[player * 10] >= 180) {
		stat[player] = statc[player * 10 + 1];
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		dolaser[player] = 0;
		do16t[player] = 0;
		scanItem(player);
		rest_pblock[player] = getPlatinumBlock(player);
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.28 - �l�K�t�B�[���h
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 1]�F�I����Ɉړ�����X�e�[�^�X
// statc[player * 10 + 2]�F�t�B�[���h�̒��_��Y���W
void statNegafield(int player) {
	int i, y;
	
	padRepeat(player);
	if(ace_irs) doNewIRS(player, 0);
	if(fastlrmove == 3) HyperLRMove(player);
	
	// �����ݒ�
	if(statc[player * 10] == 0) {
		statc[player * 10 + 2] = checkFieldTop(player);
	}
	// �l�K�t�B�[���h���s
	else if((statc[player * 10] <= 88) && (statc[player * 10] % 4 == 0)) {
		y = 22 - (statc[player * 10] / 4);
		
		for(i = 0; i < 10; i++) {
			// �u���b�N���󔒂�
			if((fld[i + y * 10 + player * 220] != 0) && (fldi[i + y * 10 + player * 220] == 0)) {
				if(!IsPlayWave(0)) PlaySE(0);
				fld[i + y * 10 + player * 220] = 0;
				fldt[i + y * 10 + player * 220] = 0;
				fldi[i + y * 10 + player * 220] = 0;
				fldo[i + y * 10 + player * 220] = 0;
				grayoutLackedBlock(player, flds[i + y * 10 + player * 220]);
				flds[i + y * 10 + player * 220] = 0;
			}
			// �󔒂��u���b�N��
			else if((y >= statc[player * 10 + 2]) && (fldi[i + y * 10 + player * 220] == 0)) {
				if(!IsPlayWave(0)) PlaySE(0);
				fld[i + y * 10 + player * 220] = (y % 7) + 2;
				fldt[i + y * 10 + player * 220] = -1;
				fldi[i + y * 10 + player * 220] = 0;
				fldo[i + y * 10 + player * 220] = 0;
				grayoutLackedBlock(player, flds[i + y * 10 + player * 220]);
				flds[i + y * 10 + player * 220] = 0;
			}
		}
	}
	
	// �J�E���^����
	statc[player * 10]++;
	
	// ���̃X�e�[�^�X��
	if(statc[player * 10] >= 120) {
		stat[player] = statc[player * 10 + 1];
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = 0;
		donega[player] = 0;
		scanItem(player);
		rest_pblock[player] = getPlatinumBlock(player);
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.29 - �V���b�g�K��
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 1]�F�I����Ɉړ�����X�e�[�^�X
// statc[player * 10 + 2]�F�t�B�[���h�̒��_��Y���W
void statShotgun(int player) {
	int i, j, x, limit;
	
	padRepeat(player);
	if(ace_irs) doNewIRS(player, 0);
	if(fastlrmove == 3) HyperLRMove(player);
	
	limit = 0;	// �������[�v�h�~�p
	
	// �����ݒ�
	if(statc[player * 10] == 0) {
		statc[player * 10 + 2] = checkFieldTop(player);
		
		for(i = statc[player * 10 + 2]; i < 22; i++) {
			if(i == 0) {
				do {
					x = GiziRand(player, 10);
				} while(fld[x + i * 10 + player * 220] == 0);
			} else {
				do {
					x = GiziRand(player, 10);
					limit++;
					if(limit > 100000) break;
				} while( ((x == shotgunpos[(i - 1) + player * 22]) && (limit < 50000)) || (fld[x + i * 10 + player * 220] == 0) );
			}
			
			shotgunpos[i + player * 22] = x;
		}
	}
	// ���ŗ\��̃u���b�N��_��
	else if(statc[player * 10] < 60) {
		for(i = statc[player * 10 + 2]; i < 22; i++) {
			j = shotgunpos[i + player * 22];
			
			if(fld[j + i * 10 + player * 220]) {
				fld[j + i * 10 + player * 220] = count % 7 + 1;
			}
		}
	}
	// �V���b�g�K�����s
	else if(statc[player * 10] == 60) {
		PlaySE(14);
		thunder_timer = 10;
		
		for(i = statc[player * 10 + 2]; i < 22; i++) {
			j = shotgunpos[i + player * 22];
			
			if(fld[j + i * 10 + player * 220]) {
				if(fldo[j + i * 10 + player * 220] == 0) {
					objectCreate(player, 1, (j + boffset[player]) * 8, (i + 3) * 8, (j - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + 1 * 250, fld[j + i * 10 + player * 220] - 1, 100);
				}
				fld[j + i * 10 + player * 220] = 0;
				fldt[j + i * 10 + player * 220] = 0;
				fldi[j + i * 10 + player * 220] = 0;
				fldo[j + i * 10 + player * 220] = 0;
				grayoutLackedBlock(player, flds[j + i * 10 + player * 220]);
				flds[j + i * 10 + player * 220] = 0;
			}
		}
	}
	
	// �J�E���^����
	statc[player * 10]++;
	
	// ���̃X�e�[�^�X��
	if(statc[player * 10] >= 120) {
		stat[player] = statc[player * 10 + 1];
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = 0;
		doshotgun[player] = 0;
		scanItem(player);
		rest_pblock[player] = getPlatinumBlock(player);
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.30 - �t�B�[���h����
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 1]�F�I����Ɉړ�����X�e�[�^�X
// statc[player * 10 + 2]�F����Ɠ�������邽�߂̃t���O
void statExchangeField(int player) {
	int i, j, enemy;
	
	padRepeat(player);
	if(ace_irs) doNewIRS(player, 0);
	if(fastlrmove == 3) HyperLRMove(player);
	
	// ������������߂�
	if(gameMode[0] == 4)
		enemy = 1 - player;
	else
		enemy = player;
	
	if(statc[player * 10] == 0) {
		// ������҂�
		if((stat[enemy] == stat[player]) && (statc[enemy * 10 + 2] != 0)) {
			// �t�B�[���h���o�b�t�@�Ɋm��
			for(i = 0; i < 22; i++) {
				for(j = 0; j < 10; j++) {
					fldbuf[j + i * 10 + player * 220] = fld[j + i * 10 + player * 220];
					fldtbuf[j + i * 10 + player * 220] = fldt[j + i * 10 + player * 220];
					fldibuf[j + i * 10 + player * 220] = fldi[j + i * 10 + player * 220];
					fldobuf[j + i * 10 + player * 220] = fldo[j + i * 10 + player * 220];
					fldsbuf[j + i * 10 + player * 220] = flds[j + i * 10 + player * 220];
				}
			}
			
			// �J�E���^����
			statc[player * 10]++;
		}
		
		statc[player * 10 + 2] = 1;
	} else {
		// ����ƃt�B�[���h������
		if((statc[player * 10] >= 60 - player) && (statc[player * 10] < 70 - player)) {
			j = statc[player * 10] - 60 - player;
			
			for(i = 0; i < 22; i++) {
				fld[j + i * 10 + player * 220] = fldbuf[j + i * 10 + enemy * 220];
				fldt[j + i * 10 + player * 220] = fldtbuf[j + i * 10 + enemy * 220];
				fldi[j + i * 10 + player * 220] = fldibuf[j + i * 10 + enemy * 220];
				fldo[j + i * 10 + player * 220] = fldobuf[j + i * 10 + enemy * 220];
				flds[j + i * 10 + player * 220] = fldsbuf[j + i * 10 + enemy * 220];
			}
			
			BltFast(17, foffset[player] + 8 + (j * 8), 40);
		}
		
		// �J�E���^����
		statc[player * 10]++;
	}
	
	// ���̃X�e�[�^�X��
	if(statc[player * 10] >= 120) {
		stat[player] = statc[player * 10 + 1];
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = 0;
		doexchg[player] = 0;
		scanItem(player);
		rest_pblock[player] = getPlatinumBlock(player);
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.31 - �A�C�e�����[���b�g
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 2]�F�����A�C�e��
void statItemRulet(int player) {
	int i, j, limit;
	
	padRepeat(player);
	if(ace_irs) doNewIRS(player, 0);
	if(fastlrmove == 3) HyperLRMove(player);
	
	if(statc[player * 10] <= 119) {
		// ���[���b�g
		if(statc[player * 10] % 3 == 0) {
			PlaySE(5);
			
			if(item_all[player] >= 2) {
				// �o������\���̂���A�C�e����2��ވȏ�̏ꍇ
				limit = 0;	// �������[�v�h�~�p
				
				do {
					statc[player * 10 + 2] = Rand(item_num);
					
					limit++;
					if(limit > 100000) break;
				} while((item_switch[statc[player * 10 + 2]] == 0) || (statc[player * 10 + 2] == 26));
			} else if(item_all[player] == 1) {
				// �o������\���̂���A�C�e����1��ނ̏ꍇ
				for(i = 0; i < 39; i++) {
					if(item_switch[i] != 0) {
						statc[player * 10 + 2] = i;
					}
				}
			} else {
				// �o������\���̂���A�C�e����0��ނ̏ꍇ
				statc[player * 10 + 2] = Rand(item_num);
			}
		}
	} else if(statc[player * 10] == 120) {
		// �m��
		PlaySE(10);
		
		if(item_all[player] >= 2) {
			// �o������\���̂���A�C�e����2��ވȏ�̏ꍇ
			limit = 0;	// �������[�v�h�~�p
			
			do {
				statc[player * 10 + 2] = GiziRand(player, item_num);
				
				limit++;
				if(limit > 100000) break;
			} while((item_switch[statc[player * 10 + 2]] == 0) || (statc[player * 10 + 2] == 26));
		} else if(item_all[player] == 1) {
			// �o������\���̂���A�C�e����1��ނ̏ꍇ
			for(i = 0; i < 39; i++) {
				if(item_switch[i] != 0) {
					statc[player * 10 + 2] = i;
				}
			}
		} else {
			// �o������\���̂���A�C�e����0��ނ̏ꍇ
			statc[player * 10 + 2] = GiziRand(player, item_num);
		}
	}
	
	BltRect(46, (boffset[player] + 1) * 8, 116, (8 * statc[player * 10 + 2]) + 56, 0, 8, 8);
	BltRect(79, (boffset[player] + 2) * 8, 112, 0, statc[player * 10 + 2] * 16, 48, 16);
	BltRect(46, (boffset[player] + 8) * 8, 116, (8 * statc[player * 10 + 2]) + 56, 0, 8, 8);
	
	statc[player * 10]++;	// �J�E���^����
	
	// ���̃X�e�[�^�X��
	if(statc[player * 10] >= 180) {
		j = statc[player * 10 + 2];
		
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		dorulet[player] = 0;
		stat[player] = 6;
		
		eraseItem(player, j + 1);
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.32 - �t���[�t�H�[��
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 1]�F�I����Ɉړ�����X�e�[�^�X
// statc[player * 10 + 2]�F�Ă���オ�莞�̌��̈ʒu
// statc[player * 10 + 3]�F�Ă���オ�莞�̌��̈ʒu�Q�iBIG�p�j
void statFreefall(int player) {
	int i, j, x, y, tmp, anim;
	
	padRepeat(player);
	if(ace_irs) doNewIRS(player, 0);
	if(fastlrmove == 3) HyperLRMove(player);
	
	if(wait1[player] > 0) anim = wait1[player];
	else anim = 1;
	
	// �A�j���[�V����
	if(statc[player * 10] < anim + 25) {
		ofs_y[player] = ofs_y[player] - 2;
	} else if(statc[player * 10] < anim + 30) {
		ofs_y[player] = ofs_y[player] + 10;
	}
	
	// ���R��������
	if(statc[player * 10] == anim + 30) {
		PlaySE(2);
		ofs_y[player] = 0;
		
		for(y = 20; y >= 0; y--) {
			for(i = 0; i < 10; i++) {
				// �u���b�N����1�i�����󔒂Ȃ�
				if((fld[i + y * 10 + player * 220] != 0) && (fld[i + (y + 1) * 10 + player * 220] == 0)) {
					tmp = y;
					
					do {
						if(tmp + 1 > 21) break;	// �ŉ��i�ɓ��B
						
						j = fld[i + tmp * 10 + player * 220];
						fld[i + tmp * 10 + player * 220] = 0;
						fld[i + (tmp + 1) * 10 + player * 220] = j;
						
						j = fldt[i + tmp * 10 + player * 220];
						fldt[i + tmp * 10 + player * 220] = 0;
						fldt[i + (tmp + 1) * 10 + player * 220] = j;
						
						j = fldi[i + tmp * 10 + player * 220];
						fldi[i + tmp * 10 + player * 220] = 0;
						fldi[i + (tmp + 1) * 10 + player * 220] = j;
						
						j = fldo[i + tmp * 10 + player * 220];
						fldo[i + tmp * 10 + player * 220] = 0;
						fldo[i + (tmp + 1) * 10 + player * 220] = j;
						
						j = flds[i + tmp * 10 + player * 220];
						flds[i + tmp * 10 + player * 220] = 0;
						flds[i + (tmp + 1) * 10 + player * 220] = j;
						
						tmp++;
					} while(fld[i + (tmp + 1) * 10 + player * 220] == 0);
				}
			}
		}
	}
	
	// ��������i�Ȃ���Ύ��̃X�e�[�^�X�ցj
	if(statc[player * 10] == (anim * 2) + 30) {
		if(blockAllEraseJudge(player) == 0) {
			// �����Ȃ�
			statc[player * 10] = -1;
		} else {
			// ��������
			PlaySE(11);
			tmp = 0;
			
			// �Ă���オ�莞�̌��̈ʒu��ݒ�
			if(enable_ff_rerise) {
				statc[player * 10 + 2] = GiziRand(player, 10);
				statc[player * 10 + 3] = statc[player * 10 + 2];
				
				if(IsBigStart[player]) {
					statc[player * 10 + 2] = (statc[player * 10 + 2] / 2) * 2;
					statc[player * 10 + 3] = statc[player * 10 + 2] + 1;
				}
			}
			
			// ��������
			for(i = 0; i < 22; i++) {
				if(erase[i + player * 22]) {
					tmp++;
					if(enable_ff_rerise) Ff_rerise[player]++;
					
					for(x = 0; x < 10; x++) {
						// �����G�t�F�N�g�\��
						if((breakeffect > 0) && (fldo[x + i * 10 + player * 220] == 0)) {
							if( (breakeffect == 1) || ((gameMode[player] == 0) && (beginner_effect)) || 
							    (heboGB[player]) || (breakeffect == 4) || 
							    (fld[x + i * 10 + player * 220] >= 11) || 
							    ((tmp & 1 != 0) && (x & 1 == 1)) || ((tmp & 1 == 0) && (x & 1 == 0)) )
							{
								objectCreate(player, 1, (x + boffset[player]) * 8, (i + 3) * 8, (x - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + tmp * 250, fld[x + i * 10 + player * 220] - 1, 100);
							}
						}
						
						// �u���b�N������
						fld[x + i * 10 + player * 220] = 0;
						fldt[x + i * 10 + player * 220] = 0;
						fldi[x + i * 10 + player * 220] = 0;
						fldo[x + i * 10 + player * 220] = 0;
						grayoutLackedBlock(player, flds[x + i * 10 + player * 220]);
						flds[x + i * 10 + player * 220] = 0;
					}
				}
			}
		}
	}
	
	// �������������ꍇ�̗�������
	if(statc[player * 10] == (anim * 2) + 30 + wait2[player]) {
		downFloatingBlocks(player);
		PlaySE(2);
	}
	
	// �I��
	if(statc[player * 10] == (anim * 3) + 30 + wait2[player]) statc[player * 10] = -1;
	
	if(statc[player * 10] >= 0) {
		// �J�E���^����
		statc[player * 10]++;
	} else {
		ofs_y[player] = 0;
		
		if(Ff_rerise[player] > 0) {
			// �Ă���オ��
			PlaySE(20);
			
			// �t�B�[���h����ɂ��炷
			UpLinePush(player);
			
			// ����グ
			for(j = 0; j < 10; j++) {
				fld[j + 21 * 10 + player * 220] = ((j != statc[player * 10 + 2]) && (j != statc[player * 10 + 3])) * (Rand(7) + 2);
				fldt[j + 21 * 10 + player * 220] = (fld[j + 21 * 10 + player * 220] != 0) * -1;
				fldi[j + 21 * 10 + player * 220] = 0;
				fldo[j + 21 * 10 + player * 220] = 0;
				flds[j + 21 * 10 + player * 220] = 0;
			}
			erase[21 + player * 22] = 0;
			
			Ff_rerise[player]--;
		} else {
			// ���̃X�e�[�^�X��
			isFreefall[player] = 0;
			pinchCheck(player);
			stat[player] = statc[player * 10 + 1];
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
			scanItem(player);
			rest_pblock[player] = getPlatinumBlock(player);
		}
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.33 - �u���b�N��[�Ɋ񂹂�
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 1]�F�I����Ɉړ�����X�e�[�^�X
void statMovfield(int player) {
	int i, j, x, y, tmp, anim;
	
	padRepeat(player);
	if(ace_irs) doNewIRS(player, 0);
	if(fastlrmove == 3) HyperLRMove(player);
	
	if(wait1[player] > 0) anim = wait1[player];
	else anim = 1;
	
	// �A�j���[�V����
	if(statc[player * 10] < anim + 25) {
		ofs_x[player] = ofs_x[player] - 2 + (4 * isLmovfield[player]);
	} else if(statc[player * 10] < anim + 30) {
		ofs_x[player] = ofs_x[player] + 10 - (10 * isLmovfield[player]);
	}
	
	// �[�Ɋ񂹂�
	if(statc[player * 10] == anim + 30) {
		PlaySE(2);
		ofs_x[player] = 0;
		
		// �� MOV FIELD
		if(isLmovfield[player]) {
			for(i = 1; i < 10; i++) {
				for(y = 0; y < 22; y++) {
					// �u���b�N����1�}�X�����󔒂Ȃ�
					if((fld[i + y * 10 + player * 220] != 0) && (fld[(i - 1) + y * 10 + player * 220] == 0)) {
						tmp = i;
						
						do {
							if(tmp - 1 < 0) break;	// ���[�ɓ��B
							
							j = fld[tmp + y * 10 + player * 220];
							fld[tmp + y * 10 + player * 220] = 0;
							fld[(tmp - 1) + y * 10 + player * 220] = j;
							
							j = fldt[tmp + y * 10 + player * 220];
							fldt[tmp + y * 10 + player * 220] = 0;
							fldt[(tmp - 1) + y * 10 + player * 220] = j;
							
							j = fldi[tmp + y * 10 + player * 220];
							fldi[tmp + y * 10 + player * 220] = 0;
							fldi[(tmp - 1) + y * 10 + player * 220] = j;
							
							j = fldo[tmp + y * 10 + player * 220];
							fldo[tmp + y * 10 + player * 220] = 0;
							fldo[(tmp - 1) + y * 10 + player * 220] = j;
							
							j = flds[tmp + y * 10 + player * 220];
							flds[tmp + y * 10 + player * 220] = 0;
							flds[(tmp - 1) + y * 10 + player * 220] = j;
							
							tmp--;
						} while(fld[(tmp - 1) + y * 10 + player * 220] == 0);
					}
				}
			}
		}
		
		// �� MOV FIELD
		if(isRmovfield[player]) {
			for(i = 8; i >= 0; i--) {
				for(y = 0; y < 22; y++) {
					// �u���b�N����1�}�X�E���󔒂Ȃ�
					if((fld[i + y * 10 + player * 220] != 0) && (fld[(i + 1) + y * 10 + player * 220] == 0)) {
						tmp = i;
						
						do {
							if(tmp + 1 > 9) break;	// �E�[�ɓ��B
							
							j = fld[tmp + y * 10 + player * 220];
							fld[tmp + y * 10 + player * 220] = 0;
							fld[(tmp + 1) + y * 10 + player * 220] = j;
							
							j = fldt[tmp + y * 10 + player * 220];
							fldt[tmp + y * 10 + player * 220] = 0;
							fldt[(tmp + 1) + y * 10 + player * 220] = j;
							
							j = fldi[tmp + y * 10 + player * 220];
							fldi[tmp + y * 10 + player * 220] = 0;
							fldi[(tmp + 1) + y * 10 + player * 220] = j;
							
							j = fldo[tmp + y * 10 + player * 220];
							fldo[tmp + y * 10 + player * 220] = 0;
							fldo[(tmp + 1) + y * 10 + player * 220] = j;
							
							j = flds[tmp + y * 10 + player * 220];
							flds[tmp + y * 10 + player * 220] = 0;
							flds[(tmp + 1) + y * 10 + player * 220] = j;
							
							tmp++;
						} while(fld[(tmp + 1) + y * 10 + player * 220] == 0);
					}
				}
			}
		}
	}
	
	// �J�E���^����
	statc[player * 10]++;
	
	// ���̃X�e�[�^�X��
	if(statc[player * 10] == (anim * 2) + 30) {
		isLmovfield[player] = 0;
		isRmovfield[player] = 0;
		stat[player] = statc[player * 10 + 1];
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.34 - �t�B�[���h��̃u���b�N���Ђ�����Ԃ�
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 1]�F�I����Ɉړ�����X�e�[�^�X
void stat180field(int player) {
	int i, j, tmp, anim;
	
	padRepeat(player);
	if(ace_irs) doNewIRS(player, 0);
	if(fastlrmove == 3) HyperLRMove(player);
	
	if(wait1[player] > 0) anim = wait1[player];
	else anim = 1;
	
	// �A�j���[�V����
	if(statc[player * 10] < anim + 65) {
		ofs_y[player] = ofs_y[player] + 2;
	} else if(statc[player * 10] < anim + 90) {
		ofs_y[player] = ofs_y[player] - 10;
	} else if(statc[player * 10] < anim + 105) {
		ofs_y[player] = ofs_y[player] + 20;
		if(ofs_y[player] > 0) ofs_y[player] = 0;
	} else if(statc[player * 10] == anim + 105) {
		ofs_y[player] = 0;
		PlaySE(2);
	}
	
	// �Ђ�����Ԃ�
	if(statc[player * 10] == anim + 90) {
		tmp = checkFieldTop(player);
		
		// �o�b�t�@��
		for(i = 0; i < 22; i++) {
			for(j = 0; j < 10; j++) {
				fldbuf[j + i * 10 + player * 220] = fld[j + i * 10 + player * 220];
				fldtbuf[j + i * 10 + player * 220] = fldt[j + i * 10 + player * 220];
				fldibuf[j + i * 10 + player * 220] = fldi[j + i * 10 + player * 220];
				fldobuf[j + i * 10 + player * 220] = fldo[j + i * 10 + player * 220];
				fldsbuf[j + i * 10 + player * 220] = flds[j + i * 10 + player * 220];
			}
		}
		
		// �Ђ�����Ԃ�
		for(i = 0; i < 22; i++) {
			for(j = 0; j < 10; j++) {
				if(i + tmp > 21) break;
				fld[j + (i + tmp) * 10 + player * 220] = fldbuf[j + (21 - i) * 10 + player * 220];
				fldt[j + (i + tmp) * 10 + player * 220] = fldtbuf[j + (21 - i) * 10 + player * 220];
				fldi[j + (i + tmp) * 10 + player * 220] = fldibuf[j + (21 - i) * 10 + player * 220];
				fldo[j + (i + tmp) * 10 + player * 220] = fldobuf[j + (21 - i) * 10 + player * 220];
				flds[j + (i + tmp) * 10 + player * 220] = fldsbuf[j + (21 - i) * 10 + player * 220];
			}
		}
	}
	
	// �J�E���^����
	statc[player * 10]++;
	
	// ���̃X�e�[�^�X��
	if(statc[player * 10] == (anim * 2) + 105) {
		do180field[player] = 0;
		stat[player] = statc[player * 10 + 1];
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.41 - �t�B�[���h�R�s�[
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 1]�F�I����Ɉړ�����X�e�[�^�X
void statCopyField(int player) {
	int i, j, enemy;
	
	padRepeat(player);
	if(ace_irs) doNewIRS(player, 0);
	if(fastlrmove == 3) HyperLRMove(player);
	
	// ������������߂�
	if(gameMode[0] == 4)
		enemy = 1 - player;
	else
		enemy = player;
	
	// �t�B�[���h�𑊎肩��R�s�[
	if((statc[player * 10] >= 60 - player) && (statc[player * 10] < 70 - player)) {
		j = statc[player * 10] - 60 - player;
		
		for(i = 0; i < 22; i++) {
			fld[j + i * 10 + player * 220] = fld[j + i * 10 + enemy * 220];
			fldt[j + i * 10 + player * 220] = fldt[j + i * 10 + enemy * 220];
			fldi[j + i * 10 + player * 220] = fldi[j + i * 10 + enemy * 220];
			fldo[j + i * 10 + player * 220] = fldo[j + i * 10 + enemy * 220];
			flds[j + i * 10 + player * 220] = flds[j + i * 10 + enemy * 220];
		}
		
		BltFast(17, foffset[player] + 8 + (j * 8), 40);
	}
	
	// �J�E���^����
	statc[player * 10]++;
	
	// ���̃X�e�[�^�X��
	if(statc[player * 10] >= 120) {
		stat[player] = statc[player * 10 + 1];
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		docopyfld[player] = 0;
		scanItem(player);
		rest_pblock[player] = getPlatinumBlock(player);
	}
}

//������������������������������������������������������������������������������
//   SHUFFLE FIELD
//������������������������������������������������������������������������������
void bananaProc(int player) {
	int i, j, y, fl[10], tmp;
	int chg[10], chgt[10], chgi[10], chgo[10], chgs[10];
	
	if(banana_c[player] == 0) {
		// �����ݒ�
		for(i = 0; i < 10; i++) fl[i] = 0;
		
		for(i = 0; i < 10; i++) {
			do {
				tmp = GiziRand(player, 10);
			} while(fl[tmp] == 1);
			
			fl[tmp] = 1;
			banana_pos[i + player * 10] = tmp;
		}
		
		banana_c[player]++;
	} else if(banana_c[player] <= 32) {
		// �t�B�[���h���V���b�t������
		y = banana_c[player] - 1;
		
		if(banana_c[player] <= 22) {
			// �t�B�[���h���o�b�t�@�Ɋi�[
			for(j = 0; j < 10; j++) {
				chg[j] = fld[j + y * 10 + player * 220];
				chgt[j] = fldt[j + y * 10 + player * 220];
				chgi[j] = fldi[j + y * 10 + player * 220];
				chgo[j] = fldo[j + y * 10 + player * 220];
				chgs[j] = flds[j + y * 10 + player * 220];
			}
			// ����ւ�
			for(j = 0; j < 10; j++) {
				fld[j + y * 10 + player * 220] = chg[banana_pos[j + player * 10]];
				fldt[j + y * 10 + player * 220] = chgt[banana_pos[j + player * 10]];
				fldi[j + y * 10 + player * 220] = chgi[banana_pos[j + player * 10]];
				fldo[j + y * 10 + player * 220] = chgo[banana_pos[j + player * 10]];
				flds[j + y * 10 + player * 220] = chgs[banana_pos[j + player * 10]];
			}
		}
		
		if((y > 1) && (y <= 7))
			BltRect(53, foffset[player] + 8, 32, 0, 50 * (count % 4) + (50 - ((y - 1) * 8)), 80, (y - 1) * 8);
		else if((y > 21) && (y <= 27))
			BltRect(53, foffset[player] + 8, 26 + (y * 8) - 50, 0, 50 * (count % 4), 80, ((28 - y) * 8));
		else if((y > 7) && (y <= 21))
			BltRect(53, foffset[player] + 8, 24 + (y * 8) - 50, 0, 50 * (count % 4), 80, 50);
		
		banana_c[player]++;
	} else {
		// �I��
		isbanana[player] = 0;
		banana_c[player] = 0;
	}
}

//������������������������������������������������������������������������������
//   �\������A�C�e����������
//������������������������������������������������������������������������������
void scanItem(int player) {
	int i, j;
	
	item_name[player] = 0;
	
	// �t�B�[���h�𒲂ׂ�
	for(i = 0; i < 22; i++)
		for(j = 0; j < 10; j++)
			if((fldi[j + i * 10 + player * 220] != 0) && (fldi[j + i * 10 + player * 220] < fldihardno)) {
				item_name[player] = fldi[j + i * 10 + player * 220];
			}
	
	// �z�[���h�𒲂ׂ�
	if((item_hblk[player] != 0) && (item_hblk[player] < fldihardno))
		item_name[player] = item_hblk[player];
	
	// NEXT�𒲂ׂ�
	for(i = 0; i < 6; i++)
		if((item_nblk[i + player * 6] != 0) && (item_nblk[i + player * 6] < fldihardno)) {
			item_name[player] = item_nblk[i + player * 6];
		}
	
	// ���݂̃u���b�N�𒲂ׂ�
	if((item[player] != 0) && (item[player] < fldihardno))
		item_name[player] = item[player];
}

//������������������������������������������������������������������������������
//  �A�C�e������
//������������������������������������������������������������������������������
int goItemStat(int player, int current_stat) {
	int i, j;
	
	// �� DEL FIELD
	if(isUPdelfield[player]) {
		j = (22 - checkFieldTop(player)) / 2;
		
		for(i = checkFieldTop(player); i < 22; i++) {
			erase[i + player * 22] = 1;
			j--;
			if(j <= 0) break;
		}
		
		for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		stat[player] = 21;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = current_stat;
		statc[player * 10 + 2] = 0;
		return 1;
	}
	
	// �� DEL FIELD
	if(isDWdelfield[player]) {
		j = (22 - checkFieldTop(player)) / 2;
		
		for(i = 22; i > checkFieldTop(player); i--) {
			erase[i + player * 22] = 1;
			j--;
			if(j <= 0) break;
		}
		
		for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		stat[player] = 21;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = current_stat;
		statc[player * 10 + 2] = 1;		// ��ɂ������u���b�N�𗎉�������
		return 1;
	}
	
	// DEL EVEN
	if(isdeleven[player]) {
		for(i = 22; i > checkFieldTop(player); i--) {
			erase[i + player * 22] = 1;
			i--;
		}
		
		for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		stat[player] = 21;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = current_stat;
		statc[player * 10 + 2] = 1;		// ��ɂ������u���b�N�𗎉�������
		return 1;
	}
	
	// LASER
	if(dolaser[player]) {
		for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		stat[player] = 27;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = current_stat;
		return 1;
	}
	
	// NEGA FIELD
	if(donega[player]) {
		for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		stat[player] = 28;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = current_stat;
		return 1;
	}
	
	// SHOT GUN!
	if(doshotgun[player]) {
		for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		stat[player] = 29;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = current_stat;
		return 1;
	}
	
	// EXCHG FIELD
	if(doexchg[player]) {
		for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		stat[player] = 30;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = current_stat;
		statc[player * 10 + 2] = 0;
		return 1;
	}
	
	// RANDOM
	if(dorulet[player]) {
		for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		stat[player] = 31;
		statc[player * 10] = 0;
		return 1;
	}
	
	// FREE FALL
	if(isFreefall[player]) {
		for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		stat[player] = 32;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = current_stat;
		return 1;
	}
	
	// �� MOV FIELD �^ �� MOV FIELD
	if(isLmovfield[player] || isRmovfield[player]) {
		for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		stat[player] = 33;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = current_stat;
		return 1;
	}
	
	// 180�KFIELD
	if(do180field[player]) {
		for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		stat[player] = 34;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = current_stat;
		return 1;
	}
	
	// 16t
	if(do16t[player]) {
		for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		stat[player] = 27;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = current_stat;
		statc[player * 10 + 2] = 1;
		return 1;
	}
	
	// ALL CLEAR
	if(isallclear[player]) {
		for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		for(i = checkFieldTop(player); i < 22; i++) erase[i + player * 22] = 1;
		stat[player] = 21;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = current_stat;
		statc[player * 10 + 2] = 0;
		return 1;
	}
	
	// COPY FIELD
	if(docopyfld[player]) {
		for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		stat[player] = 41;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = current_stat;
		return 1;
	}
	
	return 0;
}
