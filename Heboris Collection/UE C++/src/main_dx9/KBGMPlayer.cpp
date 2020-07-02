//=============================================================================
//  KBGM32.DLL ���񂽂񃉃b�p�[�N���X��YO
//=============================================================================

#include <windows.h>
#include "KBGMPlayer.h"

// ============================================================================
//  CKBGMPlayer : KBGM32.DLL ������y�Ɏg����!!
// ============================================================================

// ----------------------------------------------------------------------------
//	CKBGMPlayer �N���X�̃R���X�g���N�^
// ----------------------------------------------------------------------------
CKBGMPlayer::CKBGMPlayer(bool initialize)
{
	if ( initialize )
		LibraryInitialize();
}

// ----------------------------------------------------------------------------
//	CKBGMPlayer �N���X�̃f�X�g���N�^
// ----------------------------------------------------------------------------
CKBGMPlayer::~CKBGMPlayer()
{
	if ( loaded )
	{
		// �ǂݍ���ł���n���h��������ꍇ�͊J������
		for ( int i = 0 ; i < KBGMPLAYER_HDATA_QTY ; i ++ )
		{
			if ( bgmloaded[i] ) Free(i);
		}

		(*funcs.lpStop)();
		(*funcs.lpClose)();
		FreeLibrary(funcs.hInst);
	}
}

// ----------------------------------------------------------------------------
//	KBGM32.DLL �̏�����
// ----------------------------------------------------------------------------
bool CKBGMPlayer::LibraryInitialize()
{
	if ( !loaded )
	{
		funcs.hInst = LoadLibrary("KBGM32.DLL");

		if ( funcs.hInst < (HINSTANCE)HINSTANCE_ERROR )
		{
			return false;
		}

		// �֐��̃G���g���|�C���g���擾
		funcs.lpOpen		= (KBGM_FUNC_KBGMOPEN)	GetProcAddress(funcs.hInst, "KBGMOpen");
		funcs.lpClose		= (KBGM_FUNC_CLOSE)		GetProcAddress(funcs.hInst, "KBGMClose");
		funcs.lpPlay		= (KBGM_FUNC_PLAY)		GetProcAddress(funcs.hInst, "KBGMPlay");
		funcs.lpResume		= (KBGM_FUNC_RESUME)	GetProcAddress(funcs.hInst, "KBGMResume");
		funcs.lpStop		= (KBGM_FUNC_STOP)		GetProcAddress(funcs.hInst, "KBGMStop");
		funcs.lpPause		= (KBGM_FUNC_PAUSE)		GetProcAddress(funcs.hInst, "KBGMPause");
		funcs.lpFree		= (KBGM_FUNC_FREE)		GetProcAddress(funcs.hInst, "KBGMFree");
		funcs.lpLoadRes		= (KBGM_FUNC_LOADRES)	GetProcAddress(funcs.hInst, "KBGMLoadRes");
		funcs.lpLoadFile	= (KBGM_FUNC_LOADFILE)	GetProcAddress(funcs.hInst, "KBGMLoadFile");
		funcs.lpInit		= (KBGM_FUNC_INIT)		GetProcAddress(funcs.hInst, "KBGMInit");
		funcs.lpGetInfo		= (KBGM_FUNC_GETINFO)	GetProcAddress(funcs.hInst, "KBGMGetInfo");
		funcs.lpSetVolume	= (KBGM_FUNC_SETVOLUME)	GetProcAddress(funcs.hInst, "KBGMSetVolume");
		funcs.lpSendSysx	= (KBGM_FUNC_SENDSYSX)	GetProcAddress(funcs.hInst, "KBGMSendSysx");
		funcs.lpFadeIn		= (KBGM_FUNC_FADEIN)	GetProcAddress(funcs.hInst, "KBGMFadeIn");
		funcs.lpFadeOut		= (KBGM_FUNC_FADEOUT)	GetProcAddress(funcs.hInst, "KBGMFadeOut");
		funcs.lpSetTempo	= (KBGM_FUNC_SETTEMPO)	GetProcAddress(funcs.hInst, "KBGMSetTempo");
		funcs.lpSeek		= (KBGM_FUNC_SEEK)		GetProcAddress(funcs.hInst, "KBGMSeek");
		funcs.lpSetRepeat	= (KBGM_FUNC_SETREPEAT)	GetProcAddress(funcs.hInst, "KBGMSetRepeat");
		funcs.lpNoteOn		= (KBGM_FUNC_NOTEON)	GetProcAddress(funcs.hInst, "KBGMNoteOn");
		funcs.lpSetCtrl		= (KBGM_FUNC_SETCTRL)	GetProcAddress(funcs.hInst, "KBGMSetCtrl");
		funcs.lpSetPrg		= (KBGM_FUNC_SETPRG)	GetProcAddress(funcs.hInst, "KBGMSetPrg");

		for ( int i = 0 ; i < KBGMPLAYER_HDATA_QTY ; i ++ )
		{
			bgmloaded[i] = false;
		}

		(*funcs.lpOpen)(10, MIDI_MAPPER);

		loaded = true;
	}

	return loaded;
}

// ----------------------------------------------------------------------------
//	SMF �t�@�C����ǂݍ���
// ----------------------------------------------------------------------------
UINT CKBGMPlayer::LoadFile(UINT num, LPSTR filename)
{
	UINT	result;

	// ���������ł��Ă��Ȃ��Ƃ��͂�߂�
	if ( !loaded ) return KBGM_NOTLOADEDDLL;

	// hData �Ƀt�@�C����ǂݍ���
	result = (*funcs.lpLoadFile)(&hData[num], filename);
	if ( result == KBGM_NOERROR ) bgmloaded[num] = true;

	return result;
}

// ----------------------------------------------------------------------------
//	���\�[�X���� SMF ��ǂݍ���
// ----------------------------------------------------------------------------
UINT CKBGMPlayer::LoadRes(UINT num, HINSTANCE hInstApp, LPCSTR resname, LPCSTR restype)
{
	UINT	result;

	// ���������ł��Ă��Ȃ��Ƃ��͂�߂�
	if ( !loaded ) return KBGM_NOTLOADEDDLL;

	// ���ɓǂݍ��ݍς݂̂Ƃ��͈�U�J������
	if ( bgmloaded[num] ) Free( num );

	// hData �Ƀ��\�[�X��ǂݍ���
	result = (*funcs.lpLoadRes)(&hData[num], hInstApp, resname, restype);
	if ( result == KBGM_NOERROR ) bgmloaded[num] = true;

	return result;
}

// ----------------------------------------------------------------------------
//	���������s��
// ----------------------------------------------------------------------------
UINT CKBGMPlayer::Init(UINT num)
{
	UINT	result;

	// ���������ł��Ă��Ȃ��Ƃ��͂�߂�
	if ( !loaded ) return KBGM_NOTLOADEDDLL;
	
	// ������
	result = (*funcs.lpInit)(hData[num]);

	return result;
}

// ----------------------------------------------------------------------------
//	�Đ�����
// ----------------------------------------------------------------------------
UINT CKBGMPlayer::Play(UINT num, UINT type)
{
	UINT	result;

	// ���������ł��Ă��Ȃ��Ƃ��͂�߂�
	if ( !loaded ) return KBGM_NOTLOADEDDLL;

	// BGM ���Đ�
	result = (*funcs.lpPlay)(hData[num], type);

	return result;
}

// ----------------------------------------------------------------------------
//	��~����
// ----------------------------------------------------------------------------
UINT CKBGMPlayer::Stop(void)
{
	UINT	result;

	// ���������ł��Ă��Ȃ��Ƃ��͂�߂�
	if ( !loaded ) return KBGM_NOTLOADEDDLL;

	// BGM ���~
	result = (*funcs.lpStop)();

	return result;
}

// ----------------------------------------------------------------------------
//	�ꎞ��~����
// ----------------------------------------------------------------------------
UINT CKBGMPlayer::Pause(void)
{
	UINT	result;

	// ���������ł��Ă��Ȃ��Ƃ��͂�߂�
	if ( !loaded ) return KBGM_NOTLOADEDDLL;

	// BGM ���ꎞ��~
	result = (*funcs.lpPause)();

	return result;
}

// ----------------------------------------------------------------------------
//	�ǂݍ��� MIDI ���J��
// ----------------------------------------------------------------------------
UINT CKBGMPlayer::Free(UINT num)
{
	UINT	result;

	// ���������ł��Ă��Ȃ��Ƃ��͂�߂�
	if ( !loaded ) return KBGM_NOTLOADEDDLL;

	// MIDI ���J��
	result = (*funcs.lpFree)(hData[num]);
	if ( result == KBGM_NOERROR ) bgmloaded[num] = false;

	return result;
}

// ----------------------------------------------------------------------------
//	�ꎞ��~���ĊJ����
// ----------------------------------------------------------------------------
UINT CKBGMPlayer::Resume(UINT num)
{
	UINT	result;

	// ���������ł��Ă��Ȃ��Ƃ��͂�߂�
	if ( !loaded ) return KBGM_NOTLOADEDDLL;

	// �ꎞ��~���� BGM ���ĊJ
	result = (*funcs.lpResume)(hData[num]);

	return result;
}

// ----------------------------------------------------------------------------
//	�{�����[����ύX����
// ----------------------------------------------------------------------------
UINT CKBGMPlayer::SetVolume(UINT num, UINT volume)
{
	UINT	result;

	// ���������ł��Ă��Ȃ��Ƃ��͂�߂�
	if ( !loaded ) return KBGM_NOTLOADEDDLL;

	// �{�����[����ݒ�
	result = (*funcs.lpSetVolume)(hData[num], volume);

	return result;
}

// ----------------------------------------------------------------------------
//	���s�[�g�̐ݒ��ύX����
// ----------------------------------------------------------------------------
UINT CKBGMPlayer::SetRepeat(UINT num, DWORD times, DWORD seek)
{
	UINT	result;

	// ���������ł��Ă��Ȃ��Ƃ��͂�߂�
	if ( !loaded ) return KBGM_NOTLOADEDDLL;

	// ���s�[�g��ݒ�
	result = (*funcs.lpSetRepeat)(hData[num], times, seek);

	return result;
}

// ----------------------------------------------------------------------------
//	�e���|��ݒ肷��
// ----------------------------------------------------------------------------
UINT CKBGMPlayer::SetTempo(UINT num, UINT beat)
{
	UINT	result;

	// ���������ł��Ă��Ȃ��Ƃ��͂�߂�
	if ( !loaded ) return KBGM_NOTLOADEDDLL;

	// �e���|��ݒ�
	result = (*funcs.lpSetTempo)(hData[num], beat);

	return result;
}

// ----------------------------------------------------------------------------
//	SMF �̏����擾
// ----------------------------------------------------------------------------
UINT CKBGMPlayer::GetInfo(UINT num, LPSMFINFO lpSmfInfo)
{
	UINT	result;

	// ���������ł��Ă��Ȃ��Ƃ��͂�߂�
	if ( !loaded ) return KBGM_NOTLOADEDDLL;

	// SMF�����擾
	result = (*funcs.lpGetInfo)(hData[num], lpSmfInfo);

	return result;
}

// ----------------------------------------------------------------------------
//	�V�X�e���G�N�X�N���[�W�u���b�Z�[�W�𑗐M
// ----------------------------------------------------------------------------
UINT CKBGMPlayer::SendSysx(UINT type)
{
	UINT	result;

	// ���������ł��Ă��Ȃ��Ƃ��͂�߂�
	if ( !loaded ) return KBGM_NOTLOADEDDLL;

	// �V�X�e���G�N�X�N���[�W�u���b�Z�[�W�𑗐M
	result = (*funcs.lpSendSysx)(type);

	return result;
}

// ----------------------------------------------------------------------------
//	�t�F�[�h�C��
// ----------------------------------------------------------------------------
UINT CKBGMPlayer::FadeIn(UINT num, UINT Sec)
{
	UINT	result;

	// ���������ł��Ă��Ȃ��Ƃ��͂�߂�
	if ( !loaded ) return KBGM_NOTLOADEDDLL;

	// �t�F�[�h�C��
	result = (*funcs.lpFadeIn)(hData[num], Sec);

	return result;
}

// ----------------------------------------------------------------------------
//	�t�F�[�h�A�E�g
// ----------------------------------------------------------------------------
UINT CKBGMPlayer::FadeOut(UINT num, UINT Sec)
{
	UINT	result;

	// ���������ł��Ă��Ȃ��Ƃ��͂�߂�
	if ( !loaded ) return KBGM_NOTLOADEDDLL;

	// �t�F�[�h�A�E�g
	result = (*funcs.lpFadeOut)(hData[num], Sec);

	return result;
}

// ----------------------------------------------------------------------------
//	�V�[�N����
// ----------------------------------------------------------------------------
UINT CKBGMPlayer::Seek(UINT num, LONG Tick)
{
	UINT	result;

	// ���������ł��Ă��Ȃ��Ƃ��͂�߂�
	if ( !loaded ) return KBGM_NOTLOADEDDLL;

	// �V�[�N
	result = (*funcs.lpSeek)(hData[num], Tick);

	return result;
}

// ----------------------------------------------------------------------------
//	�m�[�g�I��
// ----------------------------------------------------------------------------
UINT CKBGMPlayer::NoteOn(BYTE ChNum, BYTE Note, BYTE Vel)
{
	UINT	result;

	// ���������ł��Ă��Ȃ��Ƃ��͂�߂�
	if ( !loaded ) return KBGM_NOTLOADEDDLL;

	// ����炷
	result = (*funcs.lpNoteOn)(ChNum, Note, Vel);

	return result;
}

// ----------------------------------------------------------------------------
//	�R���g���[�����b�Z�[�W�𑗂�
// ----------------------------------------------------------------------------
UINT CKBGMPlayer::SetCtrl(BYTE ChNum, BYTE Data1, BYTE Data2)
{
	UINT	result;

	// ���������ł��Ă��Ȃ��Ƃ��͂�߂�
	if ( !loaded ) return KBGM_NOTLOADEDDLL;

	// �R���g���[�����b�Z�[�W�𑗂�
	result = (*funcs.lpSetCtrl)(ChNum, Data1, Data2);

	return result;
}

// ----------------------------------------------------------------------------
//	���F���w�肷��
// ----------------------------------------------------------------------------
UINT CKBGMPlayer::SetPrg(BYTE ChNum, BYTE Pnum)
{
	UINT	result;

	// ���������ł��Ă��Ȃ��Ƃ��͂�߂�
	if ( !loaded ) return KBGM_NOTLOADEDDLL;

	// ���F���w��
	result = (*funcs.lpSetPrg)(ChNum, Pnum);

	return result;
}

//=============================================================================
//	end of file
//=============================================================================
