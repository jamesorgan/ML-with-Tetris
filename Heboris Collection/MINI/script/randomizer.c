// �w�{���X����NEXT�u���b�N����
void heboNextInit(int player) {
	int i, j, temp, mae, shu;
	int nextwork[7];
	
	mae = -1;
	
	if(nextblock == 0) {
		// ���S�����_��
		do {
			temp = Rand(7);
		} while((temp == 2) || (temp == 3) || (temp == 6));
		
		nextb[player * 1400] = temp;
		
		for(i = 1; i < 1400; i++) {
			nextb[player * 1400 + i] = Rand(7);
		}
	} else {
		shu = nextblock;
		
		for(i = 0; i < 1400 / shu + 1; i++) {
			for(j = 0; j < 7; j++) nextwork[j] = 0;
			
			for(j = 0; j < shu; j++) {
				do {
					if(i * shu + j == 0) {
						do {
							temp = Rand(7);
						} while((temp == 2) || (temp == 3) || (temp == 6));
					} else {
						temp = Rand(7);
					}
				} while((nextwork[temp] != 0) || (mae == temp));
				
				if(i * shu + j < 1400) nextb[(player * 1400) + (i * shu + j)] = temp;
				nextwork[temp] = 1;
				mae = temp;
			}
		}
	}
}

// �^�Q�[����NEXT��������
void tgmNextInit(int player, int type) {
	int i, j;
	int history[4];
	int block;

	if(type) {
		// Z S Z S�Ŗ��߂�
		history[0] = 3;
		history[1] = 6;
		history[2] = 3;
		history[3] = 6;
	} else {
		// ������΂Ŗ��߂�
		for(i = 0; i < 4; i++) history[i] = 3;
	}

	// ���萶��
	do {
		nextb[0 + player * 1400] = Rand(7);
	} while((nextb[0 + player * 1400] == 2) || (nextb[0 + player * 1400] == 3) || (nextb[0 + player * 1400] == 6));

	// ���������炷
	for(j = 0; j < 3; j++) {
		history[3 - j] = history[3 - (j + 1)];
	}

	// �����ɐV�����u���b�N������
	history[0] = nextb[0 + player * 1400];

	// �c��̃c���𐶐�
	for(i = 1; i < 1400; i++) {
		// �c��������
		block = Rand(7);
		
		// �������c���������ɂ�������ő�4��(type = 1�ł�6��)��������
		if((block == history[0]) || (block == history[1]) || (block == history[2]) || (block == history[3])) {
			for(j = 0; j < 4 + (type * 2); j++) {
				block = Rand(7);
				
				// 4�̗����ɖ��������炻�̏�Ŕ�����
				if((block != history[0]) && (block != history[1]) && (block != history[2]) && (block != history[3]))
					break;
			}
		}

		// ���������炷
		for(j = 0; j < 3; j++) {
			history[3 - j] = history[3 - (j + 1)];
		}

		// �����ɐV�����u���b�N������
		history[0] = block;

		// nextb�ɓ����
		nextb[i + player * 1400] = block;
	}
}

// �K�C�h���C���Ή��Q�[������NEXT��������
void guidelineNextInit(int player) {
	int i, j;
	int tmp;
	int first;
	int block[7];	// �u���b�N���o�����ǂ����̃t���O
	
	first = 1;
	
	for(i = 0; i < 200; i++) {
		// ������
		for(j = 0; j < 7; j++) block[j] = 0;
		
		// �c���쐬
		for(j = 0; j < 7; j++) {
			do {
				tmp = Rand(7);	// �c��������
			} while( (block[tmp] == 1) || ( (first == 1) && ((tmp == 2)||(tmp == 3)||(tmp == 6)) ) );
			
			// �u���b�N���o���t���OON
			block[tmp] = 1;
			
			// nextb�ɓ����
			nextb[i * 7 + j + player * 1400] = tmp;
			
			first = 0;
		}
	}
}

// �J�X�^���c�����X�g��ǂݍ���
void userNextInit(int player) {
	int i, j, temp, len;
	
	// �����𒲂ׂ�
	len = StrLen(userNextBlockList);
	
	// �ǂݍ���
	if(len > 0) {
		nextc_max[player] = len;
		
		for(i = 0; i < len; i++) {
			j = i % len;
			
			MidStr(userNextBlockList, j + 1, 1, string[0]);
			
			temp = ValLong(string[0]);
			if((temp >= 0) && (temp <= 6)) nextb[i + player * 1400] = temp;
		}
	}
}

// �_�̂�
void icheatNextInit(int player) {
	int i;
	
	for(i = 0; i < 1400; i++) nextb[i + player * 1400] = 0;
}

// 7+1
void eightBagNextInit(int player) {
	int i, j;
	int tmp;
	int first;
	int block[7];	// �u���b�N���o�����ǂ����̃t���O
	
	first = 1;
	
	for(i = 0; i < 175; i++) {
		// ������
		for(j = 0; j < 7; j++) block[j] = 0;
		
		// �c���쐬
		for(j = 0; j < 8; j++) {
			if(j == 7) {
				// 8��
				nextb[i * 8 + j + player * 1400] = Rand(7);
			} else {
				// 1-7��
				do {
					tmp = Rand(7);	// �c��������
				} while( (block[tmp] == 1) || ( (first == 1) && ((tmp == 2)||(tmp == 3)||(tmp == 6)) ) );
				
				// �u���b�N���o���t���OON
				block[tmp] = 1;
				
				// nextb�ɓ����
				nextb[i * 8 + j + player * 1400] = tmp;
				
				first = 0;
			}
		}
	}
}
