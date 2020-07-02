// DirectShow�ɂ��BGM�Đ�
// �ʓ|�����������̂ŃN���X�܂݂�̃Q�[���v���O���~���O���傩��
// �q�؂��܂����B���肪�Ƃ��������܂����B
// http://www.tnksoft.com/reading/classgame/

#pragma once
#include <strmif.h>
#include <control.h>
#include <uuids.h>
#pragma comment (lib,"strmiids.lib")
#define RELEASE(x) {if(x) { x->Release(); x = NULL; } }

class CMP3Player
{
private:
	IGraphBuilder *pBuilder;
	IMediaControl *pMediaCtrl;
	IMediaSeeking *pMediaSeeking;
	IBasicAudio *pBasicAudio;

	BOOL bFading;
	BOOL bLoop;
	BOOL bPlaying;
	float time_s, time_e, vol_s, delta;

public:
	CMP3Player();
	CMP3Player(LPCTSTR filename);
	~CMP3Player();

	void InitializeBGM();
	void Release();

	void SetVolume(LONG volume);
	void Fade(DWORD endtime, LONG volume);

	void Exec();

	void Load(LPCTSTR filename);
	void Play(bool loop);
	void Stop();
	bool IsPlay();
};
