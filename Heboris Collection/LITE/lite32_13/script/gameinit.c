//������������������������������������������������������������������������������
//
//    HEBORIS [�w�{���X] 2001 Ver0.00 / 2000.11.05 (Sun) �` ????.??.?? (????)
//
//                         (c) 1998-2000 Kenji Hoshimoto
//
//������������������������������������������������������������������������������

// �O���[�o���ϐ�
int		screenColor = 16;			// ���݂̐F��

// �ݒ�t�@�C�����C���|�[�g
	include "option.def"			// Setting.exe�̐ݒ�

// �\�[�X�t�@�C�����C���|�[�g
	include "script/screencfg.c"	// SCREEN.SAV�֘A�̊֐�

//������������������������������������������������������������������������������
//   �����ݒ�
//������������������������������������������������������������������������������
void main() {
	// SCREEN.SAV�ǂݍ���(screencfg.c)
	if(loadScreenConfig()) {
		saveScreenConfig(screenMode, systemmem, screenColor);
	}
	
	if(screenMode == 0)
		SetWindow(0, 320, 240, screenColor);	// �t���X�N���[�����[�h 320*240
	else if(screenMode == 1)
		SetWindow(1, 320, 240, screenColor);	// �E�C���h�E���[�h 320*240
	else if(screenMode == 2)
		SetWindow(1, 640, 480, screenColor);	// �E�C���h�E���[�h 640*480
	else
		SetWindow(0, 640, 480, screenColor);	// �t���X�N���[�����[�h 640*480
	
	// 60fps
	SetFPS(60);

	// YGS2000�ŗL�̐ݒ�
	SetConstParam("Caption", "HEBORIS LITE - Script Compiling...");
	SetConstParam("EnablePause", 0);	// �ǂݍ��݊����܂ł̓|�[�Y����
	SetConstParam("USE_XZ_FOR_BUTTON", 0);
	SetConstParam("StringMax", 16);

	SetDebugMode(0);

	// �V�X�e�����������g����?
	SetSystemMemoryUse(systemmem);
}
