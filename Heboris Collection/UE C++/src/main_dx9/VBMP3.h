//
// vbmp3.h
//   VBMP3.DLL �p�w�b�_�t�@�C��
//

#define INFO_NAME_SIZE		128

typedef void (__stdcall *INPUT_MSG_PROC)(int msg, int param);

struct InputInfo
{
	char	szTrackName[INFO_NAME_SIZE];	//�Ȗ�
	char	szArtistName[INFO_NAME_SIZE];	//�A�[�e�B�X�g��
	int		channels;						//�`�����l����
	int		bitRate;						//�r�b�g���[�g
	int		samplingRate;					//�T���v�����O���[�g
	int		totalSec;						//�������t����
};

struct TAG_INFO
{
	char	szTrackName[INFO_NAME_SIZE];	//�Ȗ�
	char	szArtistName[INFO_NAME_SIZE];	//�A�[�e�B�X�g��
	char    szAlbumName[INFO_NAME_SIZE];	//�A���o����
	char	szYear[5];						//�����[�X�N��
	char	szComment[INFO_NAME_SIZE];		//�R�����g������
	int		genre;							//�W������
	char    szGanreName[INFO_NAME_SIZE];	//�W����������
};

struct MPEG_INFO
{
	int		version;		//MPEG�̃o�[�W����
	int		layer;			//MPEG�̃��C��
	int		crcDisable;		//�G���[�ی�
	int		extension;		//�l���
	int		mode;			//�`�����l�����[�h
	int		copyright;		//���쌠
	int		original;		//�I���W�i��
	int		emphasis;		//�G���t�H�V�X		

	int		channels;		//�o�̓`�����l����
	int		bitRate;		//�r�b�g���[�g
	int		samplingRate;	//�T���v�����O���[�g
	int		fileSize;		//�t�@�C���T�C�Y
	int		flames;			//�t���[����
	int		totalSec;		//�������t����
};

struct LYRICS_INFO
{
	int		sec;
	char	LyricsNext2[INFO_NAME_SIZE];
	char	LyricsNext1[INFO_NAME_SIZE];
	char	LyricsCurrent[INFO_NAME_SIZE];
	char	LyricsPrev1[INFO_NAME_SIZE];
	char	LyricsPrev2[INFO_NAME_SIZE];
};

struct DEC_OPTION{
	int		reduction;		//�T���v�����O 0:1/1 1:1/2 2:1/4 (Default = 0)
	int		convert;		//�`�����l�� 0:�X�e���I 1:���m����(Default = 0)
	int		freqLimit;		//���g��
};

struct VBMP3_OPTION
{
	int inputBlock;			//���̓t���[����
	int outputBlock;		//WAVE�f�[�^�u���b�N��
	int inputSleep;			//���͒���̃X���[�v����(�~���b)
	int outputSleep;		//�o�͒���̃X���[�v����(�~���b)
};

struct LIST_INFO
{
	char	INAM[INFO_NAME_SIZE];	//�Ȗ�
	char	IART[INFO_NAME_SIZE];	//�A�[�e�B�X�g��
	char    IPRD[INFO_NAME_SIZE];	//���i��
	char	ICMT[INFO_NAME_SIZE];	//�R�����g������
	char	ICRD[INFO_NAME_SIZE];	//�����[�X�N��
	char	IGNR[INFO_NAME_SIZE];	//�W��������
	char    ICOP[INFO_NAME_SIZE];	//���쌠
	char    IENG[INFO_NAME_SIZE];	//�G���W�j�A
	char    ISRC[INFO_NAME_SIZE];	//�\�[�X
	char    ISFT[INFO_NAME_SIZE];	//�\�t�g�E�F�A
	char    IKEY[INFO_NAME_SIZE];	//�L�[���[�h
	char    ITCH[INFO_NAME_SIZE];	//�Z�p��
	char    ILYC[INFO_NAME_SIZE];	//�̎�
	char    ICMS[INFO_NAME_SIZE];	//�R�~�b�V����
};

struct WAVE_DATA
{
	int		channels;
	int		bitsPerSample;
	int		left;
	int		right;
};

struct WAVE_FORM
{
	int		channels;			//�`���l����
	int		bitsPerSample;		//�r�b�g��/1�T���v��
	int		samplingRate;
	int		dataSize;			//�t�@�C���T�C�Y
};

//�G���R�[�h�n
int APIENTRY  vbmp3_getEncodeState(int* readSize, int* encodeSize);
BOOL APIENTRY vbmp3_encodeOpen(const char* pszWaveName, WAVE_FORM* pWaveForm);
BOOL APIENTRY vbmp3_encodeStart(const char* pszMp3Name);
BOOL APIENTRY vbmp3_encodeStop();

//���g�p
void APIENTRY vbmp3_startAnalyze();
void APIENTRY vbmp3_stopAnalyze();
BOOL APIENTRY vbmp3_getWaveData(WAVE_DATA* pWaveData);

//���n
BOOL APIENTRY vbmp3_setLyricsFile(const char* pszLyricsName);
BOOL APIENTRY vbmp3_getLyrics(LYRICS_INFO* pLyricsInfo);
void APIENTRY vbmp3_getSpectrum(int* pSpecL, int* pSpecR);
void APIENTRY vbmp3_getWave(int* pWaveL, int* pWaveR);

//�R�[���o�b�N�֐�
BOOL APIENTRY vbmp3_callback(INPUT_MSG_PROC pProc);
BOOL APIENTRY vbmp3_startCallback();
BOOL APIENTRY vbmp3_stopCallback();

//�t�@�C���o�͌n
BOOL APIENTRY vbmp3_decodeWave(const char* pszWaveName);
BOOL APIENTRY vbmp3_changeWav(const char* pszName);
BOOL APIENTRY vbmp3_changeMp3(const char* pszName);
BOOL APIENTRY vbmp3_changeRmp(const char* pszName);
BOOL APIENTRY vbmp3_cutMacBinary(const char* pszName);
BOOL APIENTRY vbmp3_setTagInfo(const char* pszName, TAG_INFO* pTagInfo,int tagSet, int tagAdd);
BOOL APIENTRY vbmp3_setListInfo(const char* pszName, LIST_INFO* pListInfo);

//���擾�n
BOOL APIENTRY vbmp3_getFileInfo2(const char* pszName, TAG_INFO* pTagInfo, MPEG_INFO* pMpegInfo, LIST_INFO* pListInfo);
BOOL APIENTRY vbmp3_getFileInfo(const char* pszName, TAG_INFO* pTagInfo, MPEG_INFO* pMpegInfo);
BOOL APIENTRY vbmp3_getFileTagInfo(const char* pszName, TAG_INFO* pTagInfo);
BOOL APIENTRY vbmp3_getListInfo(LIST_INFO* pListInfo);
BOOL APIENTRY vbmp3_getMpegInfo(MPEG_INFO* pMpegInfo);
BOOL APIENTRY vbmp3_getTagInfo(TAG_INFO* pTagInfo);
int APIENTRY vbmp3_getFileType(const char* pszName);
BOOL APIENTRY vbmp3_getGenre(TAG_INFO* pTagInfo);
long APIENTRY vbmp3_getWinampPlayMs();
int APIENTRY vbmp3_getWinampTotalSec();
int APIENTRY vbmp3_getPlayBitRate();
int APIENTRY vbmp3_getLastErrorNo();

//VBMP3 �֘A
int APIENTRY vbmp3_getVersion();
BOOL APIENTRY vbmp3_setVbmp3Option(VBMP3_OPTION* pVbmp3Option);
void APIENTRY vbmp3_getVbmp3Option(VBMP3_OPTION* pVbmp3Option);
BOOL APIENTRY vbmp3_setDecodeOption(DEC_OPTION* pDecOption);
void APIENTRY vbmp3_getDecodeOption(DEC_OPTION* pDecOption);
int APIENTRY vbmp3_debug();
void APIENTRY vbmp3_setEqualizer(int* pTable);

//��{����n
BOOL APIENTRY vbmp3_setStepPitch(int pitch, int frames);
int APIENTRY vbmp3_getStepPitch();
BOOL APIENTRY vbmp3_reload();
BOOL APIENTRY vbmp3_setPitch(int pitch);
int APIENTRY vbmp3_getPitch();
BOOL APIENTRY vbmp3_init();
BOOL APIENTRY vbmp3_free();
BOOL APIENTRY vbmp3_open(const char* pszName, InputInfo* pInfo);
BOOL APIENTRY vbmp3_close();
int APIENTRY vbmp3_getState(int* sec);
BOOL APIENTRY vbmp3_play();
BOOL APIENTRY vbmp3_stop();
BOOL APIENTRY vbmp3_pause();
BOOL APIENTRY vbmp3_restart();
BOOL APIENTRY vbmp3_seek(int pos);
int APIENTRY vbmp3_getPlayFlames();
BOOL APIENTRY vbmp3_setPlayFlames(int flames);
int APIENTRY vbmp3_getPlaySamples();
int APIENTRY vbmp3_getTotalSamples();
BOOL APIENTRY vbmp3_setPlaySamples(int sample);
BOOL APIENTRY vbmp3_setVolume(int left, int right);
BOOL APIENTRY vbmp3_getVolume(int* left, int* right);
void APIENTRY vbmp3_setFadeIn(int on);
void APIENTRY vbmp3_setFadeOut(int on);
void APIENTRY vbmp3_fadeOut();
