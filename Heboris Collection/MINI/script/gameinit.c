//������������������������������������������������������������������������������
//
//    HEBORIS [�w�{���X] 2001 Ver0.00 / 2000.11.05 (Sun) �` ????.??.?? (????)
//
//                         (c) 1998-2000 Kenji Hoshimoto
//
//������������������������������������������������������������������������������

// �ݒ�
int		windowPosX = 0;				// �E�B���h�E��X���W
int		windowPosY = 0;				// �E�B���h�E��Y���W
int		outputDebugLog = 0;			// �f�o�b�O���O��ErrorLog.txt�ւ̏o�̗͂L���i0=�Ȃ� 1=����j

// �O���[�o���ϐ�
int		screenMode = 1;
int		systemmem = 0;
int		screenColor = 16;
int		useHires = 0;

// �\�[�X�t�@�C�����C���|�[�g
	include "script/screencfg.c"	// SCREEN.SAV�̓ǂݏ���

//������������������������������������������������������������������������������
//   �����ݒ�
//������������������������������������������������������������������������������
void main() {
	int cfg[4];
	
	// SCREEN.SAV�ǂݍ���(screencfg.c)
	cfg[0] = screenMode;
	cfg[1] = systemmem;
	cfg[2] = screenColor;
	cfg[3] = useHires;
	if(loadScreenConfig(&cfg)) saveScreenConfig(&cfg);
	screenMode = cfg[0];
	systemmem = cfg[1];
	screenColor = cfg[2];
	useHires = cfg[3];
	
	// ��ʃ��[�h��ݒ�
	if(screenMode == 0)
		SetWindow(0, 320, 240, screenColor);	// �t���X�N���[�����[�h 320*240
	else if(screenMode == 1)
		SetWindow(1, 320, 240, screenColor);	// �E�C���h�E���[�h 320*240
	else if(screenMode == 2)
		SetWindow(1, 640, 480, screenColor);	// �E�C���h�E���[�h 640*480
	else
		SetWindow(0, 640, 480, screenColor);	// �t���X�N���[�����[�h 640*480
	
	// �E�B���h�E�|�W�V����
	SetConstParam("WindowPos", windowPosX, windowPosY);
	
	// 60fps
	SetFPS(60);
	
	// YGS2000�ŗL�̐ݒ�
	SetConstParam("Caption", "HEBORIS U.E. MINI - Please Wait...");
	SetConstParam("EnablePause", 0);	// �ǂݍ��݊����܂ł̓|�[�Y����
	SetConstParam("USE_XZ_FOR_BUTTON", 0);
	SetConstParam("StringMax", 16);
	SetConstParam("EnableMultiApp", 1);	// �����N���̋���
	
	// �f�o�b�O���O��ErrorLog.txt�ւ̏o�̗͂L���i0=�Ȃ� 1=����j
	SetDebugMode(outputDebugLog);
	
	// �V�X�e�����������g����?
	SetSystemMemoryUse(systemmem);
}
