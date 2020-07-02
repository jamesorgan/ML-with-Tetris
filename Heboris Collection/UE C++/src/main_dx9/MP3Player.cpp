// DirectShow�ɂ��BGM�Đ�
// �ʓ|�����������̂ŃN���X�܂݂�̃Q�[���v���O���~���O���傩��
// �q�؂��܂����B���肪�Ƃ��������܂����B
// http://www.tnksoft.com/reading/classgame/

#include "MP3Player.h"

void CMP3Player::InitializeBGM()
{
	pBuilder = NULL;
	pMediaCtrl = NULL;
	pMediaSeeking = NULL;
	pBasicAudio = NULL;

	bLoop = FALSE;
	bFading = FALSE;
	bPlaying = FALSE;
}

void CMP3Player::Release()
{
	Stop();

	RELEASE(pBasicAudio);
	RELEASE(pMediaSeeking);
	RELEASE(pMediaCtrl);
	RELEASE(pBuilder);
}

CMP3Player::CMP3Player()
{
	// InitializeBGM();
}

CMP3Player::~CMP3Player()
{
	Release();
}

void CMP3Player::Load(LPCTSTR filename)
{
	Release();

	HRESULT hr = CoCreateInstance(
		CLSID_FilterGraph,		// COM�̎��ʎq
		NULL,					// ���ʂɎ擾������͂Ȃ��̂�NULL
		CLSCTX_INPROC_SERVER,	// ���̃v���O�������ł̂ݎg�����Ƃ��w��
		IID_IGraphBuilder,		// �擾����C���^�[�t�F�[�X
		(LPVOID*)&pBuilder);	// �i�[��

	if(FAILED(hr)){
		// DXTRACE_MSG(_T("IGraphBuilder�̍쐬�Ɏ��s���܂���"));
		return;
	}

#ifdef _UNICODE
	pBuilder->RenderFile(filename, NULL);
#else
	wchar_t wfname[MAX_PATH];
	MultiByteToWideChar(CP_ACP, 0, filename, -1, wfname, MAX_PATH);
	pBuilder->RenderFile(wfname, NULL);
#endif

	pBuilder->QueryInterface(IID_IMediaControl, (LPVOID*)&pMediaCtrl);
	pBuilder->QueryInterface(IID_IMediaSeeking, (LPVOID*)&pMediaSeeking);
	pBuilder->QueryInterface(IID_IBasicAudio, (LPVOID*)&pBasicAudio);
}

void CMP3Player::Play(bool loop)
{
	if(pMediaCtrl){
		bLoop = loop;	// ���[�v�Đ����s�����̃t���O
		if(pMediaSeeking){
			// �Đ��ʒu��擪�Ɉړ�����
			LONGLONG s = 0;
			pMediaSeeking->SetPositions(
				// �Đ��ʒu�͐�Έʒu��(s * 100)�i�m�b
				&s, AM_SEEKING_AbsolutePositioning,
				// �I���ʒu�͕ύX���Ȃ��̂�NoPositioning���w��
				NULL, AM_SEEKING_NoPositioning);
		}
		pMediaCtrl->Run();
		bPlaying = TRUE;
	}
}

void CMP3Player::Stop()
{
	if(pMediaCtrl)
	{
		pMediaCtrl->Stop();
		bPlaying = FALSE;
	}
}

void CMP3Player::SetVolume(LONG volume)
{
	if ( pBasicAudio )
	{
		/* �Ȃ���-3000���炢�ł��������������ɂȂ�̂ŕ␳���� */
		if ( volume > -8500 )
		{
			/* 0 �` -8500 �� 0 �` -1500 */
			volume = volume * 1500 / 8500;
		}
		else
		{
			/* -8501 �` -10000 �� -1500 �` -10000 */
			volume += 8500;						/* 0 �` -1500�� */
			volume = volume * 8500 / 1500;		/* 0 �` -8500�� */
			volume -= 1500;						/* -1500 �` -10000 �� */
		}

		pBasicAudio->put_Volume(volume);
	}
}

void CMP3Player::Exec()
{
	if(bLoop == TRUE && pMediaSeeking){
		LONGLONG s, e;
		pMediaSeeking->GetPositions(&s, &e);	// s�͊J�n�ʒu�Ae�͏I���ʒu
		if(s >= e){
			s = 0;
			pMediaSeeking->SetPositions(
				&s, AM_SEEKING_AbsolutePositioning,
				NULL, AM_SEEKING_NoPositioning);
		}
	}

	if(bFading == TRUE){
		// �����Ōo�ߎ��Ԃ��擾
		float t = (float)timeGetTime() - time_s;
		pBasicAudio->put_Volume((long)(delta * t + vol_s));

		// �o�ߎ��Ԃ𒴂�����t�F�[�h�����I��
		if(t >= time_e)
		{
			bFading = FALSE;
			bPlaying = FALSE;
		}
	}
}

void CMP3Player::Fade(DWORD endtime, LONG volume)
{
	if(!pBasicAudio){
		// DXTRACE_MSG(_T("�{�����[���̐ݒ肪�ł��܂���B"));
		return;
	}

	bFading = TRUE;

	LONG v;
	pBasicAudio->get_Volume(&v);

	vol_s = (float)v;
	float vol_e = (float)volume;

	time_s = (float)timeGetTime();
	time_e = (float)endtime;

	delta = (vol_e - vol_s) / time_e;
}

bool CMP3Player::IsPlay()
{
	if ( pMediaSeeking && bPlaying )
	{
		LONGLONG s, e;
		pMediaSeeking->GetPositions(&s, &e);	// s�͊J�n�ʒu�Ae�͏I���ʒu
		if ( s < e )
		{
			return true;
		}
	}
	return false;
}
