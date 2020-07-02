//������������������������������������������������������������������������������
//   SCREEN.SAV�ۑ�
//������������������������������������������������������������������������������
void saveScreenConfig(int size, int mem, int color) {
	int tmpBuf[7];
	
	// �w�b�_
	tmpBuf[0] = 0x4F424548;
	tmpBuf[1] = 0x4554494C;
	tmpBuf[2] = 0x50534944;
	tmpBuf[3] = 0x3159414C;
	
	// �ݒ�
	tmpBuf[4] = size;
	tmpBuf[5] = mem;
	tmpBuf[6] = color;
	
	SaveFile("SCREEN.SAV", &tmpBuf, 7 * 4);
}

//������������������������������������������������������������������������������
//   SCREEN.SAV�ǂݍ���
//������������������������������������������������������������������������������
int loadScreenConfig() {
	int tmpBuf[7];
	
	// �w�b�_�����ǂݍ���
	LoadFile("SCREEN.SAV", &tmpBuf, 4 * 4);
	
	// �w�b�_���Ⴄ
	if(tmpBuf[0] != 0x4F424548) return -1;
	if(tmpBuf[1] != 0x4554494C) return -1;
	if(tmpBuf[2] != 0x50534944) return -1;
	if(tmpBuf[3] != 0x3159414C) return -1;
	
	// �S���ǂݍ���
	LoadFile("SCREEN.SAV", &tmpBuf, 7 * 4);
	screenMode = tmpBuf[4];
	systemmem = tmpBuf[5];
	screenColor = tmpBuf[6];
	
	return 0;
}
