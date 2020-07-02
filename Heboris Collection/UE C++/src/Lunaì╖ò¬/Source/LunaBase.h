//==============================================================================//
//				DirectX9�p�ėp���C�u���� Luna									//
//==============================================================================//
//																				//
//	�ŐV�ł̒u���Ă���URL														//
//																				//
//		TWINTAIL LOVERS.														//
//			http://www.twin-tail.jp/											//
//																				//
//	���ⓙ�����ꏊ																//
//																				//
//		BBS																		//
//			TWINTAIL LOVERS.���̌f����											//
//																				//
// DirectX Library "Luna for DirectX 9.0c"										//
// Copyright (C) 2003-2006 �t���`												//
// All rights reserved.															//
//																				//
//==============================================================================//

/**
    @brief		�����Ŏg�p���Ă���e��^��`���s���Ă��܂�
    @author		�t���`
*/

#ifndef ___LUNABASE_H___
#define ___LUNABASE_H___


//================================================================================
// WARNING
//================================================================================
#pragma warning ( disable: 4127 )		// �萔�̏�����
#pragma warning ( disable: 4100 )		// ���Q�Ƃ̕ϐ�
#pragma warning ( disable: 4514 )		// ���Q�Ƃ̃C�����C���֐�
#pragma warning ( disable: 4711 )		// �����C�����C���W�J
#pragma warning ( disable: 4201 )		// �\���̊g�����[�j���O

#pragma inline_depth ( 255 )
#pragma inline_recursion ( on )


//=============================================================================
// FOR MSVC6.0
//=============================================================================
#if (_MSC_VER == 1200)
	#define for				if ( false ) ; else for														///< for���X�R�[�v���������}�N��
	typedef long			LONG_PTR;
	typedef unsigned long	DWORD_PTR;
	typedef void (__stdcall *PAPCFUNC)( DWORD_PTR dwParam );
#endif


//================================================================================
// INCLUDE
//================================================================================
#undef DIRECTINPUT_VERSION
#define DIRECTINPUT_VERSION		(0x0800)			///< DirectInput�o�[�W������`

#undef _WIN32_WINNT
#define _WIN32_WINNT			(0x0400)			///< Fiber�p

#undef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN							///< �s�v�ȃw�b�_�̎Q�ƍ폜

#undef STRICT
#define STRICT										///< �\���̊g���錾

#define STRSAFE_NO_DEPRECATE
#define __MT__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <mbstring.h>
#include <tchar.h>
#include <wchar.h>
#include <windows.h>
#include <winsock2.h>
#include <shellapi.h>
#include <process.h>
#include <commdlg.h>
#include <strsafe.h>
#include <shlobj.h>
#include <imm.h>
#include <vfw.h>
#include <objbase.h>
#include <basetsd.h>

#include <d3dx9xof.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dsound.h>
#include <dinput.h>
#include <dmusicc.h>
#include <dmusici.h>
#include <dshow.h>
#include <mmstream.h>
#include <amstream.h>
#include <ddstream.h>
#include <vmr9.h>

#undef NULL
#define NULL		(0x00000000)


//================================================================================
// TYPEDEF
//================================================================================
typedef char					Sint8;								///< signed char �^�̕ʒ�`
typedef short					Sint16;								///< signed short �^�̕ʒ�`
typedef long					Sint32;								///< signed long �^�̕ʒ�`
typedef __int64					Sint64;								///< signed __int64 �^�̕ʒ�`
typedef unsigned char			Uint8;								///< unsigned char �^�̕ʒ�`
typedef unsigned short			Uint16;								///< unsigned short �^�̕ʒ�`
typedef unsigned long			Uint32;								///< unsigned long �^�̕ʒ�`
typedef unsigned __int64		Uint64;								///< unsigned __int64 �^�̕ʒ�`
typedef float					Float;								///< Float �^�̕ʒ�`
typedef float					Float32;							///< Float �^�̕ʒ�`
typedef double					Float64;							///< double �^�̕ʒ�`
typedef long double				Float80;							///< long double �^�̕ʒ�`
typedef bool					Bool;								///< Bool �^�̕ʒ�`


typedef Bool (*PCALLBACKSOCKETPROC)( HWND hWnd, long Id );			///< �\�P�b�g�����p�R�[���o�b�N�֐�
typedef void (WINAPI *PFIBERPROC)( void *pParameter );				///< �}�C�N���X���b�h�p�R�[���o�b�N�֐�
typedef Bool (*PMICROTHREADPROC)( void *pParameter );				///< �X���b�h�p�R�[���o�b�N�֐�
typedef IDirect3D9 * (WINAPI *PDIRECT3DCREATE9)( unsigned int );	///< Direct3D�I�u�W�F�N�g�����֐��p


//================================================================================
// DEFINE
//================================================================================
static const Sint32 OPTION_DIRECTINPUT			= (1 <<  0);						///< DirectInput���g�p���ăL�[���͂��s��
static const Sint32 OPTION_DIRECTSOUND			= (1 <<  1);						///< DirectSound�����g�p���ăT�E���h�Đ����s��
static const Sint32 OPTION_DIRECTMUSIC			= (1 <<  2);						///< DirectMusic���g�p���ăT�E���h�Đ����s��
static const Sint32 OPTION_DIRECTSHOW			= (1 <<  3);						///< DirectShow���g�p���ă��[�r�[�̍Đ�������
static const Sint32 OPTION_CDDA					= (1 <<  4);						///< MCI���g�p����CDDA���g�p����
static const Sint32 OPTION_FIBER				= (1 <<  5);						///< Fiber���g�p���ă^�X�N����������


static const Sint32 FX_SEND_TRANSFORM			= (1 <<  0);
static const Sint32 FX_SEND_WORLDMATRIX			= (1 <<  1);
static const Sint32 FX_SEND_WORLDVIEWMATRIX		= (1 <<  2);
static const Sint32 FX_SEND_BONEDATA			= (1 <<  3);
static const Sint32 FX_SEND_LIGHTDATA			= (1 <<  4);
static const Sint32 FX_SEND_MATERIALDATA		= (1 <<  5);
static const Sint32 FX_SEND_SLIDE_UV			= (1 <<  6);
static const Sint32 FX_SEND_VERTEXEXTRUCT		= (1 <<  7);
static const Sint32 FX_SEND_MORPFWEIGHT			= (1 <<  8);
static const Sint32 FX_SEND_CAMERAPOS			= (1 <<  9);
static const Sint32 FX_SEND_TEXTURE				= (1 << 10);
static const Sint32 FX_SEND_FOGDATA				= (1 << 11);


//================================================================================
// CLASS TYPEDEF
//================================================================================
typedef class CVector2D			LVECTOR2;
typedef class CVector3D			LVECTOR3;
typedef class CMatrix			LMATRIX;
typedef class CQuaternion		LQUATERNION;
typedef class CStyle			LSTYLE;


#include "Class/Vector2D.h"
#include "Class/Vector3D.h"
#include "Class/Matrix.h"
#include "Class/Quaternion.h"
#include "Class/Style.h"


//================================================================================
// DEFINE
//================================================================================
#define ef						else if																		///< else if �ȗ��p�}�N��

#define toF(V)					((Float)(V))																///< Float�^�ւ̃L���X�g�}�N��
#define toI(V)					((Sint32)(V))																///< Sint32�^�ւ̃L���X�g�}�N��
#define F(V)					toF(V)
#define L(V)					toI(V)

#define PI						(3.141592653589793238462643383279f)											///< ��
#define PI2						(6.283185307179586476925286766559f)											///< 2��
#define REV(V)					toF(1.0f/toF(V))																///< �t���Z�o�}�N��

#define SAFE_RELEASE(V)			if ( (V) != NULL ) { (V)->Release(); (V) = NULL; }							///< COM���S����}�N��
#define SAFE_DELETE(V)			if ( (V) != NULL ) { delete (V); (V) = NULL; }								///< new���������S���
#define SAFE_DELETES(V)			if ( (V) != NULL ) { delete [] (V); (V) = NULL; }							///< new[]���������S���

#define MIN(N1,N2)				((N1 < N2) ? (N1) : (N2))													///< �ŏ��l�擾�}�N��
#define MAX(N1,N2)				((N1 > N2) ? (N1) : (N2))													///< �ő�l�擾�}�N��
#define SWAP(N1,N2)				{ N1 = N2 - N1; N2 -= N1; N1 += N2; }										///< �l�����}�N��

#define SIN_TABLE_BIT			(16)																		///< �T�C���e�[�u���̃r�b�g��
#define SIN_TABLE_SIZE			(1 << SIN_TABLE_BIT)														///< �T�C���e�[�u���̃T�C�Y
#define SIN_TABLE_MASK			(SIN_TABLE_SIZE - 1)														///< �T�C���e�[�u���̃A�N�Z�X�p�}�X�N
#define ARCTAN_TABLE_SIZE		(SIN_TABLE_SIZE >> 3)														///< �A�[�N�^���W�F���g�e�[�u���̃T�C�Y
#define ARCTAN_POS_1			(ARCTAN_TABLE_SIZE << 1)													///< �A�[�N�^���W�F���g�̑�P�ی�
#define ARCTAN_POS_2			(ARCTAN_POS_1 + ARCTAN_POS_1)												///< �A�[�N�^���W�F���g�̑�Q�ی�
#define ARCTAN_POS_3			(ARCTAN_POS_1 + ARCTAN_POS_2)												///< �A�[�N�^���W�F���g�̑�R�ی�
#define ARCTAN_POS_4			(ARCTAN_POS_1 + ARCTAN_POS_3)												///< �A�[�N�^���W�F���g�̑�S�ی�
#define ARCTAN_POS_SHIFT		(SIN_TABLE_BIT - 3)															///< �A�[�N�^���W�F���g�̈ʒu�V�t�g��
#define ARCTAN_SCALE(V)			(toF(V) * toF(1 << ARCTAN_POS_SHIFT))										///< �A�[�N�^���W�F���g�̊g�嗦

#define TEXTURE_STAGE_MAX		(4)																			///< �e�N�X�`���X�e�[�W�ő吔
#define BONE_MAX				(32)																		///< �ЂƂ̃��b�V���Ŏg�p�\�ȍő�{�[����
#define LUNA_THREAD_MAX			(32)																		///< �X���b�h�̍ő吔

#define NORMALIZE_ANGLE(A)		((A) & SIN_TABLE_MASK)														///< �p�x�̐��K���i0�`65535�ցj
#define GET_ANGLE(A)			toI(toF(A) * toF(SIN_TABLE_SIZE) / toF(360))								///< ��p�p�x�̎Z�o
#define GET_ANGLE_PI(A)			toI(toF(A) * toF(SIN_TABLE_SIZE) / toF(PI2))								///< ���W�A�������p�p�x�̎Z�o

#define PRIMITIVE_Z_MAX			(0xFFFF)																	///< �v���~�e�B�u�p�y�ő�l
#define INV_PRIMITIVE_Z_MAX		REV(PRIMITIVE_Z_MAX)														///< �v���~�e�B�u�p�y�l�Z�o�p�f�[�^
#define PRIMITIVE_Z_CENTER		toF(PRIMITIVE_Z_MAX / 2)													///< �v���~�e�B�u�y���S�ʒu
#define Z_TO_SORT_VALUE(Z)		(toI(Z) >> 3)																///< �y�l����y�\�[�g�p��l�Z�o�p
#define SORT_Z_MAX				Z_TO_SORT_VALUE(PRIMITIVE_Z_MAX)											///< �y�\�[�g�p�y�ő�l

#define MemoryClear(PD,S)		::FillMemory((PD),(S),0x00)													///< �������N���A
#define MemoryFill(PD,PS,S)		::FillMemory((PD),(S),(PS))													///< �������h��Ԃ�
#define MemoryMove(PD,PS,S)		::MoveMemory((PD),(PS),(S))													///< �������ړ�
#define MemoryCopy(PD,PS,S)		::CopyMemory((PD),(PS),(S))													///< �������R�s�[

#define MemGlobalAlloc(size)	::VirtualAlloc( NULL, ((size)+4095)&~4095, MEM_COMMIT, PAGE_READWRITE )						///< VirtuakAlloc�������m�ۃ}�N��
#define MemGlobalFree(pointer)	if ( (pointer) != NULL ) { ::VirtualFree( pointer, 0, MEM_RELEASE ); (pointer) = NULL; }	///< VirtualAlloc����������}�N��

#define MemLocalAlloc(size)		::HeapAlloc( ::GetProcessHeap(), HEAP_ZERO_MEMORY, size )										///< HeapAlloc�������m�ۃ}�N��
#define MemLocalFree(pointer)	if ( (pointer) != NULL ) { ::HeapFree( ::GetProcessHeap(), 0, pointer ); (pointer) = NULL; }	///< HeapAlloc����������}�N��

#define CHECK_GUID(S,D)			(strcmp( (S).Data, (D) ) == 0)												///< �V�X�e���R�[���o�b�N��GUID�`�F�b�N

#define COLOR_BASE				(D3DCOLOR_XRGB(0xFF,0xFF,0xFF))												///< �J���[��`�F��{�F
#define COLOR_WHITE				(D3DCOLOR_XRGB(0xFF,0xFF,0xFF))												///< �J���[��`�F��
#define COLOR_BLACK				(D3DCOLOR_XRGB(0x00,0x00,0x00))												///< �J���[��`�F��
#define COLOR_RED				(D3DCOLOR_XRGB(0xFF,0x00,0x00))												///< �J���[��`�F��
#define COLOR_GREEN				(D3DCOLOR_XRGB(0x00,0xFF,0x00))												///< �J���[��`�F��
#define COLOR_BLUE				(D3DCOLOR_XRGB(0x00,0x00,0xFF))												///< �J���[��`�F��
#define COLOR_ALPHA(A)			(D3DCOLOR_ARGB(A,0xFF,0xFF,0xFF))											///< �J���[��`�F�A���t�@
#define COLOR_BRIGHT(B)			(D3DCOLOR_XRGB(B,B,B))														///< �J���[��`�F���x

#define LZSS_RING_LENGTH		4096																		///< ��o�b�t�@�̑傫��
#define LZSS_RING_MASK			(LZSS_RING_LENGTH-1)														///< ��o�b�t�@�̃}�X�N
#define LZSS_LONGEST_MATCH		16																			///< �Œ���v��
#define NIL						LZSS_RING_LENGTH															///< �؂̖��[

#define COLORKEY_DISABLE		(D3DCOLOR_ARGB(0x00,0x00,0x00,0x00))										///< �e�N�X�`���ǂݍ��ݎ��J���[�L�[�s�v
#define COLORKEY_BLACK			(D3DCOLOR_ARGB(0xFF,0x00,0x00,0x00))										///< �e�N�X�`���ǂݍ��ݎ��J���[�L�[���ݒ�
#define COLORKEY_WHITE			(D3DCOLOR_ARGB(0xFF,0xFF,0xFF,0xFF))										///< �e�N�X�`���ǂݍ��ݎ��J���[�L�[���ݒ�
#define COLORKEY_RED			(D3DCOLOR_ARGB(0xFF,0xFF,0x00,0x00))										///< �e�N�X�`���ǂݍ��ݎ��J���[�L�[�Ԑݒ�
#define COLORKEY_GREEN			(D3DCOLOR_ARGB(0xFF,0x00,0xFF,0x00))										///< �e�N�X�`���ǂݍ��ݎ��J���[�L�[�ΐݒ�
#define COLORKEY_BLUE			(D3DCOLOR_ARGB(0xFF,0x00,0x00,0xFF))										///< �e�N�X�`���ǂݍ��ݎ��J���[�L�[�ݒ�

#define LIGHT_MAX				(4)																			///< ���C�g�ő吔

#define PADLAYER_MAX			(256)																		///< �p�b�h�p���C���[�ő吔
#define JOYSTICK_MAX			(16)																		///< �W���C�X�e�B�b�N���ő吔
#define KEY_BUFFER_MAX			(32)																		///< �L�[�o�b�t�@�p�o�b�t�@�T�C�Y
#define ANIMATION_MAX			(256)																		///< �A�j���[�V�����ő吔

#define WM_SOCKET				(WM_USER + 1)																///< Socket�C�x���g��M�p���b�Z�[�W
#define WM_GRAPHNOTIFY			(WM_USER + 2)																///< ���[�r�[�C�x���g��M�p���b�Z�[�W

#define THREAD_SYSTEM			(0xFFFFFFFF)																///< �V�X�e���p�X���b�h��\���萔

#define RENDER_STATE_TBL_MAX	(210)
#define TEXTURE_STATE_TBL_MAX	(33)
#define SAMPLER_STATE_TBL_MAX	(14)

#define FILE_OPEN_READ(name)				::CreateFile( name, GENERIC_READ, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL )
#define FILE_OPEN_WRITE(name)				::CreateFile( name, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL )
#define FILE_OPEN_READ_WRITE(name)			::CreateFile( name, GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL )
#define FILE_CLOSE(handle)					::CloseHandle( handle )
#define FILE_GET_SIZE(handle)				::GetFileSize( handle, NULL )
#define FILE_READ(handle,ptr,size)			{Uint32 ReadBytes; ::ReadFile( handle, ptr, size, &ReadBytes, NULL);}
#define FILE_WRITE(handle,ptr,size)			{Uint32 WriteBytes; ::WriteFile( handle, ptr, size, &WriteBytes, NULL);}
#define FILE_SEEK_BEGIN(handle,pos)			::SetFilePointer( handle, pos, NULL, FILE_BEGIN )
#define FILE_SEEK_CURRENT(handle,pos)		::SetFilePointer( handle, pos, NULL, FILE_CURRENT )
#define FILE_SEEK_END(handle,pos)			::SetFilePointer( handle, pos, NULL, FILE_END )
#define FILE_SET_TIME(handle,ft0,ft1,ft2)	::SetFileTime( handle, ft0, ft1, ft2 )
#define FILE_GET_TIME(handle,ft0,ft1,ft2)	::GetFileTime( handle, ft0, ft1, ft2 )


//================================================================================
// OBJECT HANDLE
//================================================================================
typedef enum { INVALID_CAMERA		= -1 } LCAMERA;				///< �J�����n���h��
typedef enum { INVALID_MODEL		= -1 } LMODEL;				///< ���f���n���h��
typedef enum { INVALID_ANIMATION	= -1 } LANIMATION;			///< �A�j���[�V�����n���h��
typedef enum { INVALID_SOUND		= -1 } LSOUND;				///< �T�E���h�n���h��
typedef enum { INVALID_MUSIC		= -1 } LMUSIC;				///< �~���[�W�b�N�n���h��
typedef enum { INVALID_FIELD		= -1 } LFIELD;				///< �t�B�[���h�n���h��
typedef enum { INVALID_MEDIA		= -1 } LMEDIA;				///< ���f�B�A�n���h��
typedef enum { INVALID_LIST			= -1 } LLIST;				///< ���X�g�n���h��
typedef enum { INVALID_SHADERFX		= NULL } LSHADERFX;			///< �G�t�F�N�g�n���h��


typedef struct ___LSURFACE___      { void *pData; } *LSURFACE;
typedef struct ___LTEXTURE___      { void *pData; } *LTEXTURE;
typedef struct ___LSHEET___        { void *pData; } *LSHEET;
typedef struct ___LVMR9___         { void *pData; } *LVMR9;
typedef struct ___LSCENECONTROL___ { void *pData; } *LSCENECONTROL;
typedef struct ___LPOINT___        { void *pData; } *LPOINT;
typedef struct ___LPOINT3D___      { void *pData; } *LPOINT3D;
typedef struct ___LLINE___         { void *pData; } *LLINE;
typedef struct ___LLINE3D___       { void *pData; } *LLINE3D;
typedef struct ___LPRIMITIVE___    { void *pData; } *LPRIMITIVE;
typedef struct ___LPRIMITIVE3D___  { void *pData; } *LPRIMITIVE3D;
typedef struct ___LSPRITE___       { void *pData; } *LSPRITE;
typedef struct ___LSPRITE3D___     { void *pData; } *LSPRITE3D;
typedef struct ___LFONT___         { void *pData; } *LFONT;
typedef struct ___LFONTSPRITE___   { void *pData; } *LFONTSPRITE;
typedef struct ___LFONTSPRITE3D___ { void *pData; } *LFONTSPRITE3D;
typedef struct ___LMODELEX___      { void *pData; } *LMODELEX;


const LSURFACE			INVALID_SURFACE			= NULL;
const LTEXTURE			INVALID_TEXTURE			= NULL;
const LSHEET			INVALID_SHEET			= NULL;
const LVMR9				INVALID_VMR9			= NULL;
const LSCENECONTROL		INVALID_SCENECONTROL	= NULL;
const LPOINT			INVALID_POINT			= NULL;
const LPOINT3D			INVALID_POINT3D			= NULL;
const LLINE				INVALID_LINE			= NULL;
const LLINE3D			INVALID_LINE3D			= NULL;
const LPRIMITIVE		INVALID_PRIMITIVE		= NULL;
const LPRIMITIVE3D		INVALID_PRIMITIVE3D		= NULL;
const LSPRITE			INVALID_SPRITE			= NULL;
const LSPRITE3D			INVALID_SPRITE3D		= NULL;
const LFONT				INVALID_FONT			= NULL;
const LFONTSPRITE		INVALID_FONTSPRITE		= NULL;
const LFONTSPRITE3D		INVALID_FONTSPRITE3D	= NULL;
const LMODELEX			INVALID_MODELEX			= NULL;


//================================================================================
// ENUM
//================================================================================

/**
	@brief	�T�[�t�F�C�X�t�H�[�}�b�g��`

	�e��T�[�t�F�C�X�y�уe�N�X�`���t�H�[�}�b�g�̒�`�B
*/
enum eSurfaceFormat
{
	FORMAT_FROM_FILE,					///< �t�@�C������

	FORMAT_DEPTH16,						///< 16Bit�[�x�o�b�t�@
	FORMAT_DEPTH32,						///< 32Bit�[�x�o�b�t�@
	FORMAT_DEPTHSTENCIL,				///< �X�e���V���[�x�o�b�t�@

	FORMAT_DXT1,						///< DXT1���k�t�H�[�}�b�g�e�N�X�`��
	FORMAT_DXT3,						///< DXT3���k�t�H�[�}�b�g�e�N�X�`��
	FORMAT_DXT5,						///< DXT5���k�t�H�[�}�b�g�e�N�X�`��

	FORMAT_BACKBUFFER,					///< �o�b�N�o�b�t�@�[�ɏ���
	FORMAT_TARGET16,					///< 16Bit�����_�����O�^�[�Q�b�g
	FORMAT_TARGET32,					///< 32Bit�����_�����O�^�[�Q�b�g
	FORMAT_TARGETFloat,					///< ���������_�����_�����O�^�[�Q�b�g

	FORMAT_ALPHAONLY,					///< �A���t�@�p�e�N�X�`��

	FORMAT_TEXTURE32,					///< 32Bit�e�N�X�`���t�H�[�}�b�g�ɏ���
	FORMAT_TEXTURE16,					///< 16Bit�e�N�X�`���t�H�[�}�b�g�ɏ���

	FORMAT_TEXTURE_2D,					///< 2D�p�ėp�e�N�X�`���t�H�[�}�b�g
	FORMAT_TEXTURE_3D,					///< 3D�p�ėp�e�N�X�`���t�H�[�}�b�g
};

/**
	@brief	���_�t�H�[�}�b�g��`

	���LunaSprite�N���X�Ŏg�p����钸�_��`�B
*/
enum eVertexPrimitiveType
{
	PRIM_VERTEX_UV0,					///< �e�N�X�`���X�e�[�W���O�̒��_�f�[�^
	PRIM_VERTEX_UV1,					///< �e�N�X�`���X�e�[�W���P�̒��_�f�[�^
	PRIM_VERTEX_UV2,					///< �e�N�X�`���X�e�[�W���Q�̒��_�f�[�^
	PRIM_VERTEX_UV3,					///< �e�N�X�`���X�e�[�W���R�̒��_�f�[�^
	PRIM_VERTEX_UV4,					///< �e�N�X�`���X�e�[�W���S�̒��_�f�[�^
};


/**
	@brief	�A���t�@�u�����f�B���O���[�h��`

	�e��A���t�@�u�����f�B���O���[�h�̒�`�B
*/
enum eBlendType
{
	BLEND_NONE,							///< �A���t�@�u�����h����
	BLEND_NORMAL,						///< �ʏ�u�����f�B���O
	BLEND_ADD,							///< ���Z�u�����f�B���O
	BLEND_ADD_NOALPHA,					///< ���Z�u�����f�B���O�i�A���t�@�e���Ȃ�
	BLEND_MUL,							///< ��Z�u�����f�B���O
	BLEND_REVERSE,						///< ���]�u�����f�B���O
};


//================================================================================
// STRUCTURE
//================================================================================
/**
	@brief	�T�[�t�F�C�X�p�f�o�C�X�X�e�[�g
*/
struct MATERIALSTATE
{
	Uint32		SamplerState[TEXTURE_STAGE_MAX][SAMPLER_STATE_TBL_MAX];
	Uint32		TextureState[TEXTURE_STAGE_MAX][TEXTURE_STATE_TBL_MAX];
	eBlendType	BlendType;
	Bool		IsColorKey;
	Bool		IsBilinear;
	Bool		IsZBuffer;
	Bool		IsZWrite;
};


/**
	@brief	�_�f�[�^

	Luna�Ŏg�p�����_�\���p�̍\���́B
*/
typedef struct CLunaPoint
{
	Float Px;					///< �w���W
	Float Py;					///< �x���W

	/**
		@brief �l�ݒ�
		�l���ȗ��I�ɐݒ肷�邽�߂̊֐��B

		@param px		[in] �w���W
		@param py		[in] �x���W
	*/
	void Set( Float px, Float py )
	{
		Px = px;
		Py = py;
	}
}
LUNAPOINT;

/**
	@brief	��`�f�[�^

	Luna�Ŏg�p������`�\���p�̍\���́B
*/
typedef struct CLunaRect
{
	Float Px;					///< �w�n�_���W
	Float Py;					///< �x�n�_���W
	Float Sx;					///< �w�T�C�Y
	Float Sy;					///< �x�T�C�Y

	/**
		@brief �l�ݒ�
		�l���ȗ��I�ɐݒ肷�邽�߂̊֐��B

		@param px		[in] �w�n�_���W
		@param py		[in] �x�n�_���W
		@param sx		[in] �w�T�C�Y
		@param sy		[in] �x�T�C�Y
	*/
	void Set( Float px, Float py, Float sx, Float sy )
	{
		Px = px;
		Py = py;
		Sx = sx;
		Sy = sy;
	}
}
LUNARECT;

/**
	@brief	�N���b�s���O�̈�

	�N���b�s���O�p�̋�`�f�[�^
*/
struct CClipRect
{
	Sint32 x1;					///< �w�ʒu�n�_
	Sint32 y1;					///< �x�ʒu�n�_
	Sint32 x2;					///< �w�ʒu�I�_
	Sint32 y2;					///< �x�ʒu�I�_
};

/**
	@brief	�t�H���g�`���`

	�t�H���g�`��p�̃N���b�s���O���`��p��`�f�[�^
*/
struct CFontDrawRect
{
	Sint32 x1;					///< �w�n�_���W
	Sint32 y1;					///< �x�n�_���W
	Sint32 x2;					///< �w�I�_���W
	Sint32 y2;					///< �x�I�_���W
	Sint32 Pitch;					///< �t�H���g�摜�̃s�b�`
	void *pBits;				///< �t�H���g�̃s�N�Z���f�[�^�̐擪�|�C���^
};

/**
	@brief	�R�c�f�o�C�X���

	Luna3D�N���X�Ŏg�p����A�f�o�C�X�̏���S��
	�i�[���Ă������߂̍\���́B
*/
struct DEVICEINFORMATION
{
	Bool IsPureDevice;							///< �s���A�f�o�C�X���T�|�[�g���Ă邩�ǂ���
	Bool IsHardwareTnL;							///< �n�[�h�E�F�A�s���k���T�|�[�g���Ă邩�ǂ���
	Bool IsSoftwareTnL;							///< �\�t�g�E�F�A�s���k���T�|�[�g���Ă邩�ǂ���

	D3DDEVTYPE DeviceType;						///< �f�o�C�X�^�C�v

	Bool IsAnisotropy;							///< �ٕ����t�B���^�����O���T�|�[�g���Ă邩�ۂ�
	Bool IsDither;								///< �f�B�U���T�|�[�g���Ă邩�ۂ�
	Bool IsDepthBias;							///< �[�x�o�C�A�X���T�|�[�g���Ă邩�ۂ�
	Bool IsWBuffer;								///< �v�o�b�t�@���T�|�[�g���Ă邩�ۂ�
	Bool IsAutoMipMap;							///< �~�b�v�}�b�v�����������T�|�[�g���Ă��邩�ۂ�

	Bool IsZCmpAlways;							///< ALWAYS�[�x��r���T�|�[�g���Ă��邩�ۂ�
	Bool IsZCmpEqual;							///< EQUAL�[�x��r���T�|�[�g���Ă��邩�ۂ�
	Bool IsZCmpGreater;							///< GREATER�[�x��r���T�|�[�g���Ă��邩�ۂ�
	Bool IsZCmpGreaterEqual;					///< GREATEREQUAL�[�x��r���T�|�[�g���Ă��邩�ۂ�
	Bool IsZCmpLess;							///< LESS�[�x��r���T�|�[�g���Ă��邩�ۂ�
	Bool IsZCmpLessEqual;						///< LESSEQUAL�[�x��r���T�|�[�g���Ă��邩�ۂ�
	Bool IsZCmpNever;							///< NEVER�[�x��r���T�|�[�g���Ă��邩�ۂ�
	Bool IsZCmpNotEqual;						///< NOTEQUAL�[�x��r���T�|�[�g���Ă��邩�ۂ�

	Bool IsSrcBlendFactor;						///< �\�[�X�Ƀu�����h�t�@�N�^�[���T�|�[�g���Ă��邩�ۂ�
	Bool IsSrcBothInvSrc;						///< �\�[�X��BOTHINVSRC�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsSrcBothSrc;							///< �\�[�X��BOTHSRC�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsSrcDestAlpha;						///< �\�[�X��DESTALPHA�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsSrcDestColor;						///< �\�[�X��DESTCOLOR�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsSrcInvDestAlpha;						///< �\�[�X��INVDESTALPHA�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsSrcInvDestColor;						///< �\�[�X��INVDESTCOLOR�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsSrcInvSrcAlpha;						///< �\�[�X��INVSRCALPHA�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsSrcInvSrcColor;						///< �\�[�X��INVSRCCOLOR�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsSrcOne;								///< �\�[�X��ONE�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsSrcSrcAlpha;							///< �\�[�X��SRCALPHA�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsSrcSrcAphaSat;						///< �\�[�X��SRCALPHASAT�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsSrcSrcColor;							///< �\�[�X��SRCCOLOR�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsSrcZero;								///< �\�[�X��SERO�u�����h���T�|�[�g���Ă��邩�ۂ�

	Bool IsDstBlendFactor;						///< �f�X�e�B�l�[�V�����Ƀ\�[�X�Ƀu�����h�t�@�N�^�[���T�|�[�g���Ă��邩�ۂ�
	Bool IsDstBothInvSrc;						///< �f�X�e�B�l�[�V������BOTHINVSRC�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsDstBothSrc;							///< �f�X�e�B�l�[�V������BOTHSRC�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsDstDestAlpha;						///< �f�X�e�B�l�[�V������DESTALPHA�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsDstDestColor;						///< �f�X�e�B�l�[�V������DESTCOLOR�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsDstInvDestAlpha;						///< �f�X�e�B�l�[�V������INVDESTALPHA�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsDstInvDestColor;						///< �f�X�e�B�l�[�V������INVDESTCOLOR�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsDstInvSrcAlpha;						///< �f�X�e�B�l�[�V������INVSRCALPHA�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsDstInvSrcColor;						///< �f�X�e�B�l�[�V������INVSRCCOLOR�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsDstOne;								///< �f�X�e�B�l�[�V������ONE�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsDstSrcAlpha;							///< �f�X�e�B�l�[�V������SRCALPHA�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsDstSrcAphaSat;						///< �f�X�e�B�l�[�V������SRCALPHASAT�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsDstSrcColor;							///< �f�X�e�B�l�[�V������SRCCOLOR�u�����h���T�|�[�g���Ă��邩�ۂ�
	Bool IsDstZero;								///< �f�X�e�B�l�[�V������ZERO�u�����h���T�|�[�g���Ă��邩�ۂ�

	Bool IsCubeTexture;							///< �L���[�u�e�[�N�X�`�����T�|�[�g���Ă��邩�ۂ�
	Bool IsMipmapTexture;						///< �~�b�v�}�b�v�e�N�X�`�����T�|�[�g���Ă��邩�ۂ�
	Bool IsPerspective;							///< �p�[�X�y�N�e�B�u�R���N�g���T�|�[�g���Ă��邩�ۂ�
	Bool IsPow2;								///< �Q�ׂ̂���ȊO�̃T�C�Y�̃e�N�X�`�����T�|�[�g���Ă��邩�ۂ�
	Bool IsPow2Conditional;						///< �����t���łQ�ׂ̂���ȊO�̃T�C�Y�̃e�N�X�`�����T�|�[�g���Ă��邩�ۂ�
	Bool IsSquareOnly;							///< �����`�ȊO�̃e�N�X�`�����T�|�[�g���Ă��邩�ۂ�

	Bool IsTextureBorder;						///< BORDER�e�N�X�`�����[�h���T�|�[�g���Ă邩�ۂ�
	Bool IsTxtureClamp;							///< CLAMP�e�N�X�`�����[�h���T�|�[�g���Ă邩�ۂ�
	Bool IsTextureIndependent;					///< INDEPENDENT�e�N�X�`�����[�h���T�|�[�g���Ă邩�ۂ�
	Bool IsTextureMirror;						///< MIRROR�e�N�X�`�����[�h���T�|�[�g���Ă邩�ۂ�
	Bool IsTextureMirrorRonce;					///< MIRRORRONCE�e�N�X�`�����[�h���T�|�[�g���Ă邩�ۂ�
	Bool IsTextureWrap;							///< WRAP�e�N�X�`�����[�h���T�|�[�g���Ă邩�ۂ�

	Uint32 MaxAnisotropy;						///< �ٕ����t�B���^����
	Uint32 MaxTextureWidth;						///< �ő�e�N�X�`������
	Uint32 MaxTextureHeight;					///< �ő�e�N�X�`���c��
	Uint32 MaxTextureRepeat;					///< �ő�e�N�X�`�����s�[�g��
	Uint32 MaxTextureAspectRatio;				///< �ő�e�N�X�`���A�X�y�N�g�l

	Bool IsStencilKeep;							///< KEEP�X�e���V��������T�|�[�g���Ă邩�ۂ�
	Bool IsStencilZero;							///< ZERO�X�e���V��������T�|�[�g���Ă邩�ۂ�
	Bool IsStencilReplace;						///< REPLACE�X�e���V��������T�|�[�g���Ă邩�ۂ�
	Bool IsStencilIncRsat;						///< INCRSAT�X�e���V��������T�|�[�g���Ă邩�ۂ�
	Bool IsStencilDecRsat;						///< DECRSAT�X�e���V��������T�|�[�g���Ă邩�ۂ�
	Bool IsStencilInvert;						///< INVERT�X�e���V��������T�|�[�g���Ă邩�ۂ�
	Bool IsStencilIncR;							///< INCR�X�e���V��������T�|�[�g���Ă邩�ۂ�
	Bool IsStencilDecR;							///< DECR�X�e���V��������T�|�[�g���Ă邩�ۂ�
	Bool IsStencilTwoSided;						///< ���ʃX�e���V���������\���ǂ���

	Float MaxVertexW;							///< �ő咸�_�v�l
	Float GuardBandLeft;						///< �K�[�h�o���h�N���b�s���O���ʒu
	Float GuardBandTop;							///< �K�[�h�o���h�N���b�s���O��ʒu
	Float GuardBandRight;						///< �K�[�h�o���h�N���b�s���O�E�ʒu
	Float GuardBandBottom;						///< �K�[�h�o���h�N���b�s���O���ʒu

	Float MaxPointSize;							///< �ő�|�C���g�X�v���C�g�T�C�Y

	Uint32 MaxPrimitiveCount;					///< �ő�ꊇ�`��\�|���S����
	Uint32 MaxVertexIndex;						///< �ő�ꊇ�`��\���_�C���f�b�N�X��

	Uint32 MaxMaxAnisotropy;					///< �ٕ����t�B���^�����O�ő原��
	Uint32 MaxTextureBlendStages;				///< �ő�e�N�X�`���u�����f�B���O�X�e�[�W��
	Uint32 MaxSimultaneousTextures;				///< �ő�e�N�X�`���X�e�[�W��

	Uint32 MaxActiveLights;						///< �ő�n�[�h�E�F�A���C�g��

	Uint32 MaxVertexBlendMatrices;				///< ���_�u�����h�ő吔
	Uint32 MaxVertexBlendMatrixIndex;			///< ���_�E�F�C�g�ő吔

	Uint32 VertexShaderVersion;					///< ���_�V�F�[�_�[�o�[�W����
	Uint32 PixelShaderVersion;					///< �s�N�Z���V�F�[�_�[�o�[�W����
	Uint32 MaxVertexShaderConst;				///< �ő咸�_�V�F�[�_�[�萔���W�X�^��

	Uint32 DynamicFlowControlDepth;				///< ���_�V�F�[�_�[�ł̓��I�t���[����ő�l�X�g��
	Uint32 StaticFlowControlDepth;				///< ���_�V�F�[�_�[�ł̐ÓI�t���[����ő�l�X�g��
};

/**
	@brief	���k�f�[�^�w�b�_

	LunaCompres�N���X�Ŏg�p����A���k�f�[�^�̃w�b�_�B
*/
struct LZSSHEADER
{
	char Chunk[4];					///< ��p�̃t�@�C���ł��邱�Ƃ����߂����ʎq�B���'L''Z''S''S'
	Uint32 DecodeSize;				///< �W�J��̃f�[�^�T�C�Y
	Uint32 Reserved[2];				///< �\��̈�i��ɂO�j
};

/**
	@brief	16Bit�s�N�Z���f�[�^

	16Bit�s�N�Z���t�H�[�}�b�g�̍\���́B
*/
struct PIXELDATA16
{
	Uint16 a : 4;				///< �A���t�@����
	Uint16 r : 4;				///< �Ԑ���
	Uint16 g : 4;				///< �ΐ���
	Uint16 b : 4;				///< ����
};

/**
	@brief	32Bit�s�N�Z���f�[�^

	32Bit�s�N�Z���t�H�[�}�b�g�̍\���́B
*/
struct PIXELDATA32
{
	Uint8 b;				///< ����
	Uint8 g;				///< �ΐ���
	Uint8 r;				///< �Ԑ���
	Uint8 a;				///< �A���t�@����
};

/**
	@brief	64Bit�s�N�Z���f�[�^

	64Bit�s�N�Z���t�H�[�}�b�g�̍\���́B
*/
struct PIXELDATA64
{
	Uint16 b;				///< ����
	Uint16 g;				///< �ΐ���
	Uint16 r;				///< �Ԑ���
	Uint16 a;				///< �A���t�@����
};

/**
	@brief	Float�^�s�N�Z���f�[�^

	���������_�s�N�Z���t�H�[�}�b�g�̍\���́B
*/
struct PIXELDATAFloat
{
	Float b;						///< ����
	Float g;						///< �ΐ���
	Float r;						///< �Ԑ���
	Float a;						///< �A���t�@����
};

/**
	@brief	�v���~�e�B�u�p�_���

	�Q�c�v���~�e�B�u�̃����_�����O�L���[��
	�f�[�^��ǉ����鎞�Ɏg�p����ėp���_�f�[�^�B
*/
typedef struct CPrimitivePoint2D
{
	Float x;							///< �w�ʒu
	Float y;							///< �x�ʒu
	Float z;							///< �y�ʒu
	Float w;							///< �v�ʒu
	D3DCOLOR c;							///< ���_�F
	Float u1;							///< �t�u�X�e�[�W�P
	Float v1;							///< �t�u�X�e�[�W�P
	Float u2;							///< �t�u�X�e�[�W�Q
	Float v2;							///< �t�u�X�e�[�W�Q
	Float u3;							///< �t�u�X�e�[�W�R
	Float v3;							///< �t�u�X�e�[�W�R
	Float u4;							///< �t�u�X�e�[�W�S
	Float v4;							///< �t�u�X�e�[�W�S
}
PRIMITIVEPOINT, PRIMITIVEPOINT2D;

/**
	@brief	�R�c�v���~�e�B�u�p�_���

	�R�c�v���~�e�B�u�̃����_�����O�L���[��
	�f�[�^��ǉ����鎞�Ɏg�p����ėp���_�f�[�^�B
*/
typedef struct CPrimitivePoint3D
{
	Float x;							///< �w�ʒu
	Float y;							///< �x�ʒu
	Float z;							///< �y�ʒu
	D3DCOLOR c;							///< ���_�F
	Float u1;							///< �t�u�X�e�[�W�P
	Float v1;							///< �t�u�X�e�[�W�P
	Float u2;							///< �t�u�X�e�[�W�Q
	Float v2;							///< �t�u�X�e�[�W�Q
	Float u3;							///< �t�u�X�e�[�W�R
	Float v3;							///< �t�u�X�e�[�W�R
	Float u4;							///< �t�u�X�e�[�W�S
	Float v4;							///< �t�u�X�e�[�W�S
}
PRIMITIVEPOINT3D;

/**
	@brief	�Q�c�|���S��

	�ʏ�̃V���v���ȂQ�c�`����s�����Ɏg�p����钸�_�f�[�^�\���́B
*/
typedef struct CVertex2D
{
	Float x;							///< �w�ʒu
	Float y;							///< �x�ʒu
	Float z;							///< �y�ʒu
	Float w;							///< �v�ʒu
	D3DCOLOR c;							///< ���_�F
	Float u;							///< �t�u
	Float v;							///< �t�u

	/**
		CVertex2D���_�p�e�u�e��`
	*/
	enum {
		/// �e�u�e�t�H�[�}�b�g��`
		FVF = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
	};
}
VERTEX2D;

/**
	@brief	�v���~�e�B�u���_

	�e�N�X�`���t�u���S�X�e�[�W���܂񂾃v���~�e�B�u�p���_
*/
struct PRIMVERTEX0
{
	Float x;							///< �w�ʒu
	Float y;							///< �x�ʒu
	Float z;							///< �y�ʒu
	Float w;							///< �v�ʒu
	D3DCOLOR c;							///< ���_�F

	/**
		PRIMVERTEX0���_�p�e�u�e��`
	*/
	enum {
		/// �e�u�e�t�H�[�}�b�g��`
		FVF = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)
	};
};


/**
	@brief	�v���~�e�B�u���_

	�e�N�X�`���t�u���P�X�e�[�W���܂񂾃v���~�e�B�u�p���_
*/
struct PRIMVERTEX1
{
	Float x;							///< �w�ʒu
	Float y;							///< �x�ʒu
	Float z;							///< �y�ʒu
	Float w;							///< �v�ʒu
	D3DCOLOR c;							///< ���_�F
	Float u1;							///< �t�u�X�e�[�W�P
	Float v1;							///< �t�u�X�e�[�W�P

	/**
		PRIMVERTEX1���_�p�e�u�e��`
	*/
	enum {
		/// �e�u�e�t�H�[�}�b�g��`
		FVF = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
	};
};

/**
	@brief	�v���~�e�B�u���_

	�e�N�X�`���t�u���Q�X�e�[�W���܂񂾃v���~�e�B�u�p���_
*/
struct PRIMVERTEX2
{
	Float x;							///< �w�ʒu
	Float y;							///< �x�ʒu
	Float z;							///< �y�ʒu
	Float w;							///< �v�ʒu
	D3DCOLOR c;							///< ���_�F
	Float u1;							///< �t�u�X�e�[�W�P
	Float v1;							///< �t�u�X�e�[�W�P
	Float u2;							///< �t�u�X�e�[�W�Q
	Float v2;							///< �t�u�X�e�[�W�Q

	/**
		PRIMVERTEX2���_�p�e�u�e��`
	*/
	enum {
		/// �e�u�e�t�H�[�}�b�g��`
		FVF = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX2)
	};
};

/**
	@brief	�v���~�e�B�u���_

	�e�N�X�`���t�u���R�X�e�[�W���܂񂾃v���~�e�B�u�p���_
*/
struct PRIMVERTEX3
{
	Float x;							///< �w�ʒu
	Float y;							///< �x�ʒu
	Float z;							///< �y�ʒu
	Float w;							///< �v�ʒu
	D3DCOLOR c;							///< ���_�F
	Float u1;							///< �t�u�X�e�[�W�P
	Float v1;							///< �t�u�X�e�[�W�P
	Float u2;							///< �t�u�X�e�[�W�Q
	Float v2;							///< �t�u�X�e�[�W�Q
	Float u3;							///< �t�u�X�e�[�W�R
	Float v3;							///< �t�u�X�e�[�W�R

	/**
		PRIMVERTEX3���_�p�e�u�e��`
	*/
	enum {
		/// �e�u�e�t�H�[�}�b�g��`
		FVF = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX3)
	};
};

/**
	@brief	�v���~�e�B�u���_

	�e�N�X�`���t�u���S�X�e�[�W���܂񂾃v���~�e�B�u�p���_
*/
struct PRIMVERTEX4
{
	Float x;							///< �w�ʒu
	Float y;							///< �x�ʒu
	Float z;							///< �y�ʒu
	Float w;							///< �v�ʒu
	D3DCOLOR c;							///< ���_�F
	Float u1;							///< �t�u�X�e�[�W�P
	Float v1;							///< �t�u�X�e�[�W�P
	Float u2;							///< �t�u�X�e�[�W�Q
	Float v2;							///< �t�u�X�e�[�W�Q
	Float u3;							///< �t�u�X�e�[�W�R
	Float v3;							///< �t�u�X�e�[�W�R
	Float u4;							///< �t�u�X�e�[�W�S
	Float v4;							///< �t�u�X�e�[�W�S

	/**
		PRIMVERTEX4���_�p�e�u�e��`
	*/
	enum {
		/// �e�u�e�t�H�[�}�b�g��`
		FVF = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX4)
	};
};

/**
	@brief	�R�c�v���~�e�B�u���_

	�e�N�X�`���t�u���܂܂Ȃ��R�c�v���~�e�B�u�p���_
*/
struct PRIMVERTEX3D0
{
	Float x;							///< �w�ʒu
	Float y;							///< �x�ʒu
	Float z;							///< �y�ʒu
	D3DCOLOR c;							///< ���_�F

	/**
		PRIMVERTEX3D0���_�p�e�u�e��`
	*/
	enum {
		/// �e�u�e�t�H�[�}�b�g��`
		FVF = (D3DFVF_XYZ | D3DFVF_DIFFUSE)
	};
};

/**
	@brief	�R�c�v���~�e�B�u���_

	�e�N�X�`���t�u���P�X�e�[�W���܂񂾂R�c�v���~�e�B�u�p���_
*/
struct PRIMVERTEX3D1
{
	Float x;							///< �w�ʒu
	Float y;							///< �x�ʒu
	Float z;							///< �y�ʒu
	D3DCOLOR c;							///< ���_�F
	Float u1;							///< �t�u�X�e�[�W�P
	Float v1;							///< �t�u�X�e�[�W�P

	/**
		PRIMVERTEX3D1���_�p�e�u�e��`
	*/
	enum {
		/// �e�u�e�t�H�[�}�b�g��`
		FVF = (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)
	};
};

/**
	@brief	�R�c�v���~�e�B�u���_

	�e�N�X�`���t�u���Q�X�e�[�W���܂񂾂R�c�v���~�e�B�u�p���_
*/
struct PRIMVERTEX3D2
{
	Float x;							///< �w�ʒu
	Float y;							///< �x�ʒu
	Float z;							///< �y�ʒu
	D3DCOLOR c;							///< ���_�F
	Float u1;							///< �t�u�X�e�[�W�P
	Float v1;							///< �t�u�X�e�[�W�P
	Float u2;							///< �t�u�X�e�[�W�Q
	Float v2;							///< �t�u�X�e�[�W�Q

	/**
		PRIMVERTEX3D2���_�p�e�u�e��`
	*/
	enum {
		/// �e�u�e�t�H�[�}�b�g��`
		FVF = (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX2)
	};
};

/**
	@brief	�R�c�v���~�e�B�u���_

	�e�N�X�`���t�u���R�X�e�[�W���܂񂾂R�c�v���~�e�B�u�p���_
*/
struct PRIMVERTEX3D3
{
	Float x;							///< �w�ʒu
	Float y;							///< �x�ʒu
	Float z;							///< �y�ʒu
	D3DCOLOR c;							///< ���_�F
	Float u1;							///< �t�u�X�e�[�W�P
	Float v1;							///< �t�u�X�e�[�W�P
	Float u2;							///< �t�u�X�e�[�W�Q
	Float v2;							///< �t�u�X�e�[�W�Q
	Float u3;							///< �t�u�X�e�[�W�R
	Float v3;							///< �t�u�X�e�[�W�R

	/**
		PRIMVERTEX3D3���_�p�e�u�e��`
	*/
	enum {
		/// �e�u�e�t�H�[�}�b�g��`
		FVF = (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX3)
	};
};

/**
	@brief	�R�c�v���~�e�B�u���_

	�e�N�X�`���t�u���S�X�e�[�W���܂񂾂R�c�v���~�e�B�u�p���_
*/
struct PRIMVERTEX3D4
{
	Float x;							///< �w�ʒu
	Float y;							///< �x�ʒu
	Float z;							///< �y�ʒu
	D3DCOLOR c;							///< ���_�F
	Float u1;							///< �t�u�X�e�[�W�P
	Float v1;							///< �t�u�X�e�[�W�P
	Float u2;							///< �t�u�X�e�[�W�Q
	Float v2;							///< �t�u�X�e�[�W�Q
	Float u3;							///< �t�u�X�e�[�W�R
	Float v3;							///< �t�u�X�e�[�W�R
	Float u4;							///< �t�u�X�e�[�W�S
	Float v4;							///< �t�u�X�e�[�W�S

	/**
		PRIMVERTEX3D4���_�p�e�u�e��`
	*/
	enum {
		/// �e�u�e�t�H�[�}�b�g��`
		FVF = (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX4)
	};
};

/**
	@brief	�V�F�[�_�[���������p

	�V�F�[�_�[��I������Ƃ��Ɏg�p����f�[�^�\���́B
*/
struct SHADERCREATE
{
	Uint32 BoneWeightCount;		///< �{�[���E�F�C�g��
	Uint32 ShaderVersion;		///< �V�F�[�_�[�o�[�W����
	Bool IsSoftwareVP;					///< �\�t�g�E�F�A�������ۂ�
};

/**
	@brief	�Q������̓_

	LunaCollision�N���X�Ŏg����_�f�[�^�\���́B
*/
struct POINT2D
{
	Float Px;							///< �w�ʒu
	Float Py;							///< �x�ʒu
};

/**
	@brief	�Q������̉~

	LunaCollision�N���X�Ŏg����~�f�[�^�\���́B
*/
struct CIRCLE2D
{
	POINT2D Center;						///< �~�̒��S
	Float Radius;						///< �~�̔��a
};

/**
	@brief	�Q������̎l�p

	LunaCollision�N���X�Ŏg����l�p�`�f�[�^�\���́B
*/
struct RECT2D
{
	Float Sx;							///< ����w���W
	Float Sy;							///< ����x���W
	Float Ex;							///< �E���w���W
	Float Ey;							///< �E���x���W
};

/**
	@brief	�Q������̑��p�`

	LunaCollision�N���X�Ŏg���鑽�p�`�f�[�^�\���́B
*/
struct POLYGON2D
{
	Sint32 Count;							///< �|�C���g�z��̃|�C���g��
	POINT2D *pPts;						///< �|���S����\�����߂̃|�C���g�z��̃|�C���^
};

/**
	@brief	�Q������̐�

	LunaCollision�N���X�Ŏg������f�[�^�\���́B
*/
struct LINE2D
{
	POINT2D Pt0;						///< �����n�_�ʒu
	POINT2D Pt1;						///< �����I�_�ʒu
};

/**
	@brief	�R������̓_
*/
struct POINT3D
{
	Float Px;							///< �w�ʒu
	Float Py;							///< �x�ʒu
	Float Pz;							///< �y�ʒu

	POINT3D(){}														///< �R���g���N�^
	POINT3D( Float x, Float y, Float z ){ Px = x; Py = y; Pz = z; }	///< �R���g���N�^
	POINT3D( POINT3D &pt ) { Px = pt.Px; Py = pt.Py; Pz = pt.Pz; }	///< �R���g���N�^
};

/**
	@brief	�R������̉~�i��

	LunaCollision�N���X�Ŏg�p����鋅�f�[�^�\���́B
*/
struct SPHERE3D
{
	POINT3D Center;						///< ���̒��S
	Float Radius;						///< ���̔��a

	SPHERE3D(){}															///< �R���X�g���N�^
	SPHERE3D( POINT3D &pt, Float radius ){ Center = pt; Radius = radius; }	///< �R���X�g���N�^
};

/**
	@brief	�R������̐�

	LunaCollision�N���X�Ŏg������f�[�^�\���́B
*/
struct LINE3D
{
	POINT3D Pt0;						///< �����n�_�ʒu
	POINT3D Pt1;						///< �����I�_�ʒu

	LINE3D(){}																///< �R���X�g���N�^
	LINE3D( POINT3D &pt0, POINT3D &pt1 ) { Pt0 = pt0; Pt1 = pt1; }			///< �R���X�g���N�^
};

/**
	@brief	�R������̖�

	LunaCollision�N���X�Ŏg����ʃf�[�^�\���́B
*/
struct PLANE3D
{
	Float a;							///< ��ʕ��ʕ������ɂ�����N���b�v�ʂ� a �W�� 
	Float b;							///< ��ʕ��ʕ������ɂ�����N���b�v�ʂ� b �W�� 
	Float c;							///< ��ʕ��ʕ������ɂ�����N���b�v�ʂ� c �W�� 
	Float d;							///< ��ʕ��ʕ������ɂ�����N���b�v�ʂ� d �W�� 
};

/**
	@brief	�R������̔�

	LunaCollision�N���X�Ŏg���锠�f�[�^�\���́B
*/
struct BOX3D
{
	POINT3D Points[8];					///< ���̊e�p��\�����_�f�[�^
	PLANE3D Planes[6];					///< ���̊e�ʂ�\���ʃf�[�^
};

/**
	@brief	�V�F�[�_�[�p���C�g�f�[�^

    �V�F�[�_�[�p�̃��C�e�B���O�f�[�^��
	�i�[���邽�߂̍\���́B
*/
struct SHADERLIGHTDATA
{
	BOOL IsActive[LIGHT_MAX];			///< ���C�g���g�p���邩�ۂ�
	BOOL IsDirection[LIGHT_MAX];		///< �f�B���N�V���i�����C�g���ۂ�
	Float Attenuation[LIGHT_MAX];		///< ���C�g������
	D3DXVECTOR4 Position[LIGHT_MAX];	///< ���C�g�ʒu
	D3DXVECTOR4 Direction[LIGHT_MAX];	///< ���C�g����
	D3DCOLORVALUE Color[LIGHT_MAX];		///< ���C�g�F
	D3DCOLORVALUE Specular;				///< ���ˌ�
	D3DCOLORVALUE Ambient;				///< ����
};

/**
	@brief	���f���p���_

	�{�[���������_�x�[�X���_�\���́B<BR>
	�Œ�@�\�ŏ����\�ȃ{�[���������_�`���̍\���́B
*/
struct BASEVERTEX
{
	D3DXVECTOR3 Pos;					///< �ʒu
	D3DXVECTOR3 Norm;					///< �@��
	D3DCOLOR Color;						///< ���_�F
	D3DXVECTOR2 Tex;					///< �e�N�X�`���t�u

	/**
		BASEVERTEX���_�p�e�u�e��`
	*/
	enum {
		/// �e�u�e�t�H�[�}�b�g��`
		FVF = (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1)
	};
};

/**
	@brief	�{�[�����f���p���_

	�{�[���L�蒸�_�x�[�X���_�\���́B<BR>
	�Œ�@�\�ŏ����\�ȃ{�[���L�蒸�_�`���̍\���́B
*/
struct BASEBONEVERTEX
{
	D3DXVECTOR3 Pos;					///< �ʒu
	Float Weight[3];					///< �E�F�C�g
	Uint8 Index[4];				///< �{�[���C���f�b�N�X
	D3DXVECTOR3 Norm;					///< �@��
	D3DCOLOR Color;						///< ���_�F
	D3DXVECTOR2 Tex;					///< �e�N�X�`���t�u

	/**
		BASEBONEVERTEX���_�p�e�u�e��`
	*/
	enum {
		/// �e�u�e�t�H�[�}�b�g��`
		FVF = (D3DFVF_XYZB4 | D3DFVF_LASTBETA_UBYTE4 | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1)
	};
};

/**
	@brief	�S�f�[�^�ۗL���_

	�S���_�f�[�^�ۗL�p���_�f�[�^�\���́B
	�ǂݍ��܂ꂽ���f���[�f�[�^�͕K�����̌`����
	���_�f�[�^��ۗL���Ă��܂��B
*/
struct VERTEXALL
{
	D3DXVECTOR3 Pos;					///< �ʒu
	D3DXVECTOR3 Norm;					///< �@��
	D3DXVECTOR3 PosMorph;				///< �^�[�Q�b�g���_
	D3DXVECTOR3 NormMorph;				///< �^�[�Q�b�g�@��
	Float Weight[3];					///< �E�F�C�g
	Uint8 Index[4];				///< �{�[���C���f�b�N�X
	D3DCOLOR Color;						///< ���_�F
	D3DXVECTOR2 Tex;					///< �e�N�X�`���t�u
};

/**
	@brief	�ʏ풸�_

	�ʏ�̓����ϊ��p�̒��_�\���́B
*/
struct VERTEXNORMAL
{
	D3DXVECTOR3 Pos;					///< �ʒu
	D3DXVECTOR3 Norm;					///< �@��
	D3DCOLOR Color;						///< ���_�F
	D3DXVECTOR2 Tex;					///< �e�N�X�`���t�u
};

/**
	@brief	���[�t�B���O�p���_

	���[�t�B���O�������\�Ȓ��_�̍\���́B
*/
struct VERTEXMORPH
{
	D3DXVECTOR3 Pos;					///< �ʒu
	D3DXVECTOR3 Norm;					///< �@��
	D3DXVECTOR3 PosMorph;				///< �^�[�Q�b�g�ʒu
	D3DXVECTOR3 NormMorph;				///< �^�[�Q�b�g�@��
	D3DCOLOR Color;						///< ���_�F
	D3DXVECTOR2 Tex;					///< �e�N�X�`���t�u
};

/**
	@brief	�{�[���Q�E�F�C�g���_

	�ő�Q�{�̃{�[���̉e�����󂯂钸�_�̍\���́B
*/
struct VERTEXBONE2
{
	D3DXVECTOR3 Pos;					///< �ʒu
	D3DXVECTOR3 Norm;					///< �@��
	Float Weight[1];					///< �E�F�C�g
	Uint8 Index[4];				///< �{�[���C���f�b�N�X
	D3DCOLOR Color;						///< ���_�F
	D3DXVECTOR2 Tex;					///< �e�N�X�`���t�u
};

/**
	@brief	�{�[���R�E�F�C�g���_

	�ő�R�{�̃{�[���̉e�����󂯂钸�_�̍\���́B
*/
struct VERTEXBONE3
{
	D3DXVECTOR3 Pos;					///< �ʒu
	D3DXVECTOR3 Norm;					///< �@��
	Float Weight[2];					///< �E�F�C�g
	Uint8 Index[4];				///< �{�[���C���f�b�N�X
	D3DCOLOR Color;						///< ���_�F
	D3DXVECTOR2 Tex;					///< �e�N�X�`���t�u 
};

/**
	@brief	�{�[���S�E�F�C�g���_

	�ő�S�{�̃{�[���̉e�����󂯂钸�_�̍\���́B
*/
struct VERTEXBONE4
{
	D3DXVECTOR3 Pos;					///< �ʒu
	D3DXVECTOR3 Norm;					///< �@��
	Float Weight[3];					///< �E�F�C�g
	Uint8 Index[4];				///< �{�[���C���f�b�N�X
	D3DCOLOR Color;						///< ���_�F
	D3DXVECTOR2 Tex;					///< �e�N�X�`���t�u
};

/**
	@brief	�{�[���Q�E�F�C�g���[�t�B���O���_

	�ő�Q�{�̃{�[���̉e�����󂯂郂�[�t�B���O�L�蒸�_�̍\���́B
*/
struct VERTEXBONE2MORPH
{
	D3DXVECTOR3 Pos;					///< �ʒu
	D3DXVECTOR3 Norm;					///< �@��
	D3DXVECTOR3 PosMorph;				///< �^�[�Q�b�g���_
	D3DXVECTOR3 NormMorph;				///< �^�[�Q�b�g�@��
	Float Weight[1];					///< �E�F�C�g
	Uint8 Index[4];				///< �{�[���C���f�b�N�X
	D3DCOLOR Color;						///< ���_�F
	D3DXVECTOR2 Tex;					///< �e�N�X�`���t�u
};

/**
	@brief	�{�[���R�E�F�C�g���[�t�B���O���_

	�ő�R�{�̃{�[���̉e�����󂯂郂�[�t�B���O�L�蒸�_�̍\���́B
*/
struct VERTEXBONE3MORPH
{
	D3DXVECTOR3 Pos;					///< �ʒu
	D3DXVECTOR3 Norm;					///< �@��
	D3DXVECTOR3 PosMorph;				///< �^�[�Q�b�g���_
	D3DXVECTOR3 NormMorph;				///< �^�[�Q�b�g�@��
	Float Weight[2];					///< �E�F�C�g
	Uint8 Index[4];				///< �{�[���C���f�b�N�X
	D3DCOLOR Color;						///< ���_�F
	D3DXVECTOR2 Tex;					///< �e�N�X�`���t�u
};

/**
	@brief	�{�[���S�E�F�C�g���[�t�B���O���_

	�ő�S�{�̃{�[���̉e�����󂯂郂�[�t�B���O�L�蒸�_�̍\���́B
*/
struct VERTEXBONE4MORPH
{
	D3DXVECTOR3 Pos;					///< �ʒu
	D3DXVECTOR3 Norm;					///< �@��
	D3DXVECTOR3 PosMorph;				///< �^�[�Q�b�g���_
	D3DXVECTOR3 NormMorph;				///< �^�[�Q�b�g�@��
	Float Weight[3];					///< �E�F�C�g
	Uint8 Index[4];				///< �{�[���C���f�b�N�X
	D3DCOLOR Color;						///< ���_�F
	D3DXVECTOR2 Tex;					///< �e�N�X�`���t�u
};

/**
	@brief	�o���v�}�b�v�p���_

	�o���v�}�b�v����̓����ϊ��p�̒��_�\���́B
*/
struct VERTEXBUMPMAP
{
	D3DXVECTOR3 Pos;					///< �ʒu
	D3DXVECTOR3 Norm;					///< �@��
	D3DXVECTOR3 Tangent;				///< �ڐ�
	D3DXVECTOR3 BiNorm;					///< �]�@��
	D3DCOLOR Color;						///< ���_�F
	D3DXVECTOR2 Tex;					///< �e�N�X�`���t�u
};

/**
	@brief	�z�X�g���

	�\�P�b�g�g�p���Ƀz�X�g�����i�[���邽�߂Ɏg���\���́B
*/
struct HOSTINFO
{
	char Name[256];						///< �z�X�g��
	char Alias[16][256];				///< �z�X�g�ʖ��e�[�u��
	char Address[16][64];				///< IP�A�h���X�e�[�u��
	Sint32 Type;						///< �f�[�^�^�C�v
	Sint32 Length;						///< �f�[�^�T�C�Y
	Sint32 AliasCount;					///< �G�C���A�X��
	Sint32 AddressCount;				///< IP�A�h���X��
};

/**
	@brief	�\�P�b�g�p���M�f�[�^��`

	�\�P�b�g�g�p���Ƀf�[�^�𑗐M����ۂɎg�p�����f�[�^�\���́B
*/
struct SOCKETSENDDATA
{
	Uint32 Send;					///< ���M�ς݃f�[�^�T�C�Y
	Uint32 Size;					///< ���M���v�T�C�Y
	Uint8 *pData;					///< ���M�f�[�^
};

/**
	@brief	�\�P�b�g�ڑ����

	�\�P�b�g�ł̐ڑ����̐ڑ�����<BR>
	�i�[���Ă������߂̍\���̂ł�
*/
struct CONNECTCLIENTDATA
{
	SOCKET Socket;							///< �\�P�b�g�f�[�^
	SOCKADDR_IN SockAddr;					///< �\�P�b�g�A�h���X
	HOSTINFO HostInfo;						///< �z�X�g���
	char IPAddress[64];						///< �h�o�A�h���X
	char Buffer[1024];						///< �o�b�t�@
	Sint32 Length;							///< �o�b�t�@����

	Bool IsWriteEnable;						///< �������݂n�j�t���O
	Bool IsReadEnable;						///< �ǂݍ��݂n�j�t���O

	SOCKETSENDDATA SendData;				///< ���M�f�[�^

	CONNECTCLIENTDATA *pNext;				///< ���̐ڑ����ւ̃|�C���^
};

/**
	@brief	�񓯊�IO�p�I�[�o�[���b�v�\����

	�񓯊�IO��p�������������鎞��<BR>
	�g�������i�[���邽�߂̍\���̂ł��B
*/
struct OVERLAPEDDATA
{
	Bool			IsRequest;				///< ����M���N�G�X�g�����ۂ�
	Sint32			RequestCode;			///< ���N�G�X�g���ʃR�[�h
	WSAOVERLAPPED	Overlap;				///< ����M���N�G�X�g�p�f�[�^
	WSABUF			Buffer;					///< ���M�o�b�t�@
};

/**
	@brief	�t�@�C���Ǘ��p�f�[�^��`

	LunaFile�N���X�ŗp������t�@�C���Ǘ��֌W�̍\���́B
*/
struct FILEDATA
{
	HANDLE hFile;						///< �t�@�C���n���h��
	BOOL IsPack;						///< �p�b�N�t�@�C�����ۂ�
	Uint32 Start;						///< �t�@�C���J�n�ʒu
	Uint32 Size;						///< �t�@�C���I���ʒu
	FILETIME CreationTime;				///< �쐬����
	FILETIME LastAccessTime;			///< �ŏI�A�N�Z�X����
	FILETIME LastWriteTime;				///< �ŏI�X�V����
	char FileName[MAX_PATH];					///< �t�@�C����
};

//=============================================================================
// DEFINE
//=============================================================================
#define SOCKET_LOG_LINE_MAX				(256)


//=============================================================================
// WORK ENUM
//=============================================================================

/**
	@brief	�����R�[�h��`

	LunaFontSprite�N���X�Ŏg�p�����<BR>
	S-JIS�����R�[�h�\�̃C���f�b�N�X�Z�o�p��`�ł�
*/
enum
{
	CODE_ASCII_START		= 0x0000,
	CODE_ASCII_END			= 0x00FF,

	CODE_SJIS_A_START		= 0x8140,
	CODE_SJIS_A_END			= 0x9FFF,

	CODE_SJIS_B_START		= 0xE040,
	CODE_SJIS_B_END			= 0xEEFF,

	CODE_SJIS_C_START		= 0xF8A0,
	CODE_SJIS_C_END			= 0xFC4F,

	CODE_TABLE_SIZE			= (CODE_ASCII_END - CODE_ASCII_START) + (CODE_SJIS_A_END - CODE_SJIS_A_START) + (CODE_SJIS_B_END - CODE_SJIS_B_START) + (CODE_SJIS_C_END - CODE_SJIS_C_START),	///< �ŏI�I�ȃe�[�u���T�C�Y

	SHEET_MAX				= 32,		///< LunaFontSprite�N���X�Ŏg�p����V�[�g�ő吔
};

/**
	@brief	�V�[�g�T�C�Y��`

	CSheet�N���X�Ŏg�p�����V�[�g�̊e���`�ł�
*/
enum {
	SHEET_X_MAX		= 16,			///< �w�����̃V�[�g�ő吔
	SHEET_Y_MAX		= 16,			///< �x�����̃V�[�g�ő吔

	SHEET_SIZE_X	= 256,			///< �V�[�g�̂w�����ő�T�C�Y
	SHEET_SIZE_Y	= 256,			///< �V�[�g�̂x�����ő�T�C�Y
};

/**
	@brief	�G�t�F�N�g�p�����[�^�[�n���h����`

	LunaModelEx�N���X�Ŏg�p�����G�t�F�N�g�n���h���̊e���`�ł�
*/
enum {
	FX_HANDLE_mTransform,			///< �����ϊ��p�s��
	FX_HANDLE_mWorld,				///< ���[���h�ϊ��s��
	FX_HANDLE_mWorldView,			///< �J������Ԃւ̕ϊ��s��

	FX_HANDLE_mBoneMatrixArray,		///< �{�[���p�s��
	FX_HANDLE_BoneWeightCount,		///< �{�[���E�F�C�g��

	FX_HANDLE_LightIsUse,			///< ���C�g�F�g�p�L���t���O
	FX_HANDLE_LightIsDirectional,	///< ���C�g�F���s�����t���O�itrue:���s����/false:�_�����j
	FX_HANDLE_LightAttenuation,		///< ���C�g�F�X�|�b�g���C�g������
	FX_HANDLE_LightColor,			///< ���C�g�F�F
	FX_HANDLE_LightParameter,		///< ���C�g�F����or�ʒu�i�������ʒu����LightIsDirectional�Ɉˑ��j

	FX_HANDLE_MaterialDiffuse,		///< �}�e���A���F�f�B�t�[�Y
	FX_HANDLE_MaterialAmbient,		///< �}�e���A���F�A���r�G���g

	FX_HANDLE_vCameraPos,			///< �J�����ʒu
	FX_HANDLE_SlideTextureU,		///< �e�N�X�`���t�X���C�h�l
	FX_HANDLE_SlideTextureV,		///< �e�N�X�`���u�X���C�h�l
	FX_HANDLE_VertexExtrusion,		///< ���_�����o���l
	FX_HANDLE_MorphWeight,			///< ���[�t�B���O�E�F�C�g

	FX_HANDLE_FogParameter,			///< �t�H�O�F�v�Z�p
	FX_HANDLE_FogTransform,			///< �t�H�O�F�y�l�Z�o�p

	FX_HANDLE_TextureStage0,		///< �e�N�X�`���F�X�e�[�W�O
	FX_HANDLE_TextureStage1,		///< �e�N�X�`���F�X�e�[�W�P
	FX_HANDLE_TextureStage2,		///< �e�N�X�`���F�X�e�[�W�Q
	FX_HANDLE_TextureStage3,		///< �e�N�X�`���F�X�e�[�W�R

	FX_HANDLE_MAX,
};

/**
	@brief	���_�^�C�v��`

	LunaModelEx�Ŏg�p����钸�_�t�H�[�}�b�g��`�B
*/
enum eVertexType
{
	VX_NORMAL,						///< �ʏ�̓����ϊ��p
	VX_MORPH,						///< ���[�t�B���O�L�蓧���ϊ��p
	VX_BONE2,						///< �Q�{�[���e���{�[���ϊ�
	VX_BONE3,						///< �R�{�[���e���{�[���ϊ�
	VX_BONE4,						///< �S�{�[���e���{�[���ϊ�
	VX_BONE2MORPH,					///< �Q�{�[���e���{�[���ϊ��{���[�t�B���O
	VX_BONE3MORPH,					///< �R�{�[���e���{�[���ϊ��{���[�t�B���O
	VX_BONE4MORPH,					///< �S�{�[���e���{�[���ϊ��{���[�t�B���O

	VX_UNKNOW,
};


//=============================================================================
// WORK STRUCT
//=============================================================================

/**
	@brief	LFD�t�@�C���w�b�_

	LFD�t�@�C���p�̃t�@�C���w�b�_�\���́B
*/
struct LFDHEADER
{
	char Guid[4];						///< �t�@�C�����ʏ��i��� 'L' 'F' 'D' '\0'
	Uint8 FontSize;						///< �t�H���g�T�C�Y
	Uint8 SheetMax;						///< �V�[�g�ő吔
	Uint16 SheetWidth;					///< �V�[�g����
	Uint16 SheetHeight;					///< �V�[�g�c��
	Uint16 FontMax;						///< �t�H���g�ő吔
	Uint16 IndexTbl[CODE_TABLE_SIZE];	///< �C���f�b�N�X�e�[�u��
};

/**
	@brief	��{�I�u�W�F�N�g

	�e�I�u�W�F�N�g�̊�{�ƂȂ�\���̂ł�
*/
struct OBJECTBASE
{
	Bool IsUse;							///< �g�p�t���O
	Uint32 RefCount;					///< �Q�ƃJ�E���^
};

/**
	@brief	��{�I�u�W�F�N�g�t�@�C��

	�e�t�@�C���I�u�W�F�N�g�̊�{�ƂȂ�\���̂ł�
*/
struct OBJECTFILE : public OBJECTBASE
{
	char FileName[MAX_PATH];				///< �t�@�C����
};

/**
	@brief	�A�_�v�^�[���

	DirectXGraphics�Ŏg�p�����A�_�v�^�[��<BR>
	�����i�[���Ă������߂̍\���̂ł�
*/
struct ADAPTERDATA
{
	Sint32 ModeCount;						///< ��ʃ��[�h��
	D3DDISPLAYMODE Mode[128];				///< ��ʃ��[�h

	Sint32 DepthCount;						///< �[�x�t�H�[�}�b�g��
	D3DFORMAT DepthFormats[16];				///< �[�x�t�H�[�}�b�g

	Sint32 TextureCount;					///< �e�N�X�`���t�H�[�}�b�g��
	D3DFORMAT TextureFormats[128];			///< �e�N�X�`���t�H�[�}�b�g
	Bool TextureMipmap[128];				///< �����~�b�v�}�b�v����

	Sint32 TargetCount;						///< �����_�����O�^�[�Q�b�g�t�H�[�}�b�g��
	D3DFORMAT TargetFormats[32];			///< �����_�����O�^�[�Q�b�g�t�H�[�}�b�g
};

/**
	@brief	�T�E���h�f�[�^

	LunaSound�N���X�Ŏg�p�����A�T�E���h�f�[�^��<BR>
	�Ǘ����邽�߂̍\���̂ł�
*/
struct SOUNDDATA : public OBJECTFILE
{
	CRITICAL_SECTION CriticalSection;		///< �N���e�B�J���Z�N�V����
	FILEDATA *pFile;						///< �t�@�C���n���h��
	class CAyame *pAyame;					///< �h���C�o�[

	// ����p
	struct {
		Float fStart;
		Float fEnd;
		Sint32 Time;
		Sint32 TimeAll;
		Bool IsCtrl;
	} Volume, Pan;
};

/**
	@brief	���f�B�A�I�u�W�F�N�g

	LunaMedia�N���X�Ŏg�p�����A���f�B�A�֌W�̏���<BR>
	�Ǘ����邽�߂̍\���̂ł�
*/
struct MEDIADATA : public OBJECTFILE
{
	IGraphBuilder	*pGB;			///< DirectShow�C���^�[�t�F�[�X
	IMediaSeeking	*pMS;			///< DirectShow�C���^�[�t�F�[�X
	IMediaEventEx	*pME;			///< DirectShow�C���^�[�t�F�[�X
	IVideoWindow	*pVW;			///< DirectShow�C���^�[�t�F�[�X
	IMediaControl	*pMC;			///< DirectShow�C���^�[�t�F�[�X
	IBasicAudio		*pBA;			///< DirectShow�C���^�[�t�F�[�X
	Sint64			StartPos;		///< �J�n�ʒu
	Sint64			EndPos;			///< �I���ʒu
	Bool			IsPlay;			///< �Đ��t���O
	Bool			IsLoop;			///< ���[�v�t���O
	Bool			IsPause;		///< �ꎞ��~�t���O
	Bool			IsTemp;			///< �ꎞ�t�@�C������̓ǂݍ��݂��ۂ�
};

/**
	@brief	�~���[�W�b�N�f�[�^

	LunaMusic�N���X�Ŏg�p�����A�V�[�P���X�f�[�^��<BR>
	�Ǘ����邽�߂̍\���̂ł�
*/
struct MUSICDATA : public OBJECTFILE
{
	IDirectMusicPerformance8 *pPerformance;	///< �p�t�H�[�}���X�I�u�W�F�N�g
	IDirectMusicSegment8 *pSegment;			///< �Z�O�����g�I�u�W�F�N�g
	IDirectMusicSegmentState *pState;		///< �Z�O�����g�X�e�[�^�X�I�u�W�F�N�g

	void *pMusicData;						///< �p�b�N�t�@�C������̃f�[�^

	Bool IsPlay;							///< �Đ������ۂ�
	Bool IsPause;							///< �ꎞ��~�����ۂ�
};

/**
	@brief	�L�[�t���[���f�[�^

	LunaAnimation�N���X�Ŏg�p�����A�A�j���[�V������<BR>
	�L�[�t���[���̏����i�[���邽�߂̍\���̂ł�
*/
struct KEYFRAMEDATA
{
	Float fTime;							///< �L�[����
	Float fParam;							///< �L�[�l
	Bool IsIn;								///< �X�v���C������IN�W����萔�ɂ��邩�ǂ���
	Bool IsOut;								///< �X�v���C������OUT�W����萔�ɂ��邩�ǂ���
	Float fIn;								///< IN�W���̒萔
	Float fOut;								///< OUT�W���̒萔

	KEYFRAMEDATA *pPrev;					///< �O���L�[�t���[���f�[�^�|�C���^
	KEYFRAMEDATA *pNext;					///< ����L�[�t���[���f�[�^�|�C���^
};

/**
	@brief	�T�E���h�f�[�^

	LunaAnimation�N���X�Ŏg�p�����A�A�j���[�V������<BR>
	�f�[�^���Ǘ����邽�߂̍\���̂ł�
*/
struct ANIMATIONDATA : public OBJECTBASE
{
	Float *pNewtonWork0;					///< �j���[�g����ԗp���[�N
	Float *pNewtonWork1;					///< �j���[�g����ԗp���[�N
	KEYFRAMEDATA *pKeys;					///< �L�[�t���[���f�[�^�|�C���^
	Uint32 KeyMax;					///< �L�[�t���[����
	Float fTimeFirst;						///< �J�n����
	Float fTimeLast;						///< �I������
};

/**
	@brief	�V�F�[�_�[�]���p�f�[�^

	LunaModelEx�N���X�Ŏg�p�����A�����_�����O����<BR>
	�V�F�[�_�[�ւ̓]���f�[�^���Ǘ����邽�߂̍\���̂ł�
*/
struct SHADERDATA
{
	CMatrix mWorld;							///< ���[���h�s��
	CMatrix mCamera;						///< �J�����s��
	CMatrix mTransform;						///< �g�����X�I�[���s��
	CMatrix mWorldView;						///< ���[���h�r���[�s��
	CMatrix mInvRotateWorld;				///< ��]�t�s��
	CMatrix mInvWorld;						///< ���[���h�t�s��

	Float fVertexExtrusion;					///< ���_�����o����
	Float fMorphWeight;						///< ���[�t�B���O�E�F�C�g
	Float fSlideTextureU;					///< �t�}�b�v�X���C�h��
	Float fSlideTextureV;					///< �u�}�b�v�X���C�h��
};

/**
	@brief	�J�����f�[�^

	LunaCamera�N���X�Ŏg�p�����A�J�����f�[�^��<BR>
	�Ǘ����邽�߂̍\���̂ł�
*/
struct LUNACAMERADATA : public OBJECTBASE
{
	CMatrix mProjection;					///< �v���W�F�N�V�����s��
	CMatrix mView;							///< �r���[�s��
	CMatrix mCamera;						///< �J�����s��
	CVector3D vPosition;						///< �ʒu

	CStyle Style;							///< �p��������

	Float fFov;								///< �J�����e�n�u
	Float fAspect;							///< �J�����A�X�y�N�g
	Float fNearZ;							///< �ŋߕ���
	Float fFarZ;							///< �ŉ�����
};

/**
	@brief	�}�C�N���X���b�h�f�[�^

	LunaMicroThread�N���X�Ŏg�p�����A<BR>
	�X���b�h�f�[�^���Ǘ����邽�߂̍\���̂ł�
*/
struct MICROTHREADDATA
{
	PMICROTHREADPROC pProcMain;							///< �X���b�h���C���֐�
	PMICROTHREADPROC pProcTerminate;						///< �X���b�h�I���֐�

	Sint32 StackSize;									///< �X�^�b�N�T�C�Y

	unsigned int NextThreadNo;						///< ���̃X���b�h�̔ԍ�
	unsigned int PrevThreadNo;						///< �O�̃X���b�h�̔ԍ�
	unsigned int ThreadId;							///< �X���b�h�̂h�c
	HANDLE hThread;									///< �X���b�h�̃n���h��
	HANDLE hSemaphore;								///< �X���b�h�̊Ǘ��p�Z�}�t�H

	Sint64 StartTime;								///< �v���J�n����
	Sint64 EndTime;								///< �v���I������
	Float CPUTime;									///< �b�o�t����

	Bool IsActive;									///< �A�N�e�B�u���ۂ�
};

/**
	@brief	�t�@�C�o�[�f�[�^

	LunaFiber�N���X�Ŏg�p�����A<BR>
	�t�@�C�o�[�f�[�^���Ǘ����邽�߂̍\���̂ł�
*/
struct FIBERDATA
{
	PFIBERPROC pProcMain;					///< �X���b�h�p�R�[���o�b�N�֐��̃|�C���^
	unsigned long StackSize;				///< �X�^�b�N�T�C�Y
	Bool IsActive;							///< �A�N�e�B�u���ۂ�
	Bool IsBoot;							///< �N�������ۂ�
	Bool IsSuspend;							///< �T�X�y���h�����ۂ�

	__int64 StartTime;						///< �J�n����
	__int64 EndTime;						///< �I������
	Float CPUTime;							///< �b�o�t�g�p���ԁi���j

	void *pFiber;							///< �t�@�C�o�[�̃|�C���^
	void *pNextFiber;						///< ���̃t�@�C�o�[�̃|�C���^
};

/**
	@brief	�G�t�F�N�g�f�[�^

	LunaShaderFx�N���X�Ŏg�p�����A�G�t�F�N�g���f�[�^��<BR>
	�Ǘ����邽�߂̍\���̂ł�
*/
struct SHADERFXDATA : public OBJECTFILE
{
	ID3DXEffect *pEffect;
	Uint16 Major;
	Uint16 Minor;
};

/**
	@brief	���f���f�[�^

	LunaModel�N���X�Ŏg�p�����A���f�����f�[�^��<BR>
	�Ǘ����邽�߂̍\���̂ł�
*/
struct MODELDATA : public OBJECTFILE
{
	ID3DXAnimationController *pAnimController;	///< �A�j���[�V�����R���g���[���[
	D3DXFRAME *pFrameRoot;						///< �t���[���f�[�^�ւ̃|�C���^

	Sint32 MeshCount;								///< ���b�V����
	D3DXMESHCONTAINER **ppMeshTbl;				///< ���b�V���A�N�Z�X�e�[�u��

	Float fObjectRadius;						///< �o�E���f�B���O�X�t�B�A�̔��a
	CVector3D vObjectCenter;						///< �o�E���f�B���O�X�t�B�A�̒��S
	CVector3D vBBMin;							///< �o�E���f�B���O�{�b�N�X�ŏ��l
	CVector3D vBBMax;							///< �o�E���f�B���O�{�b�N�X�ő�l

	Float fSx;									///< �w�����g��k��
	Float fSy;									///< �x�����g��k��
	Float fSz;									///< �y�����g��k��

	CStyle Style;								///< �p��������
	CMatrix mWorld;								///< ���[���h�s��
};

/**
	@brief	�}�e���A���f�[�^

	LunaModelEx�N���X�Ŏg�p�����A�}�e���A���f�[�^��<BR>
	�Ǘ����邽�߂̍\���̂ł�
*/
struct LMATERIAL
{
	D3DMATERIAL9 Mat;						///< �}�e���A���f�[�^
	LTEXTURE lTex[4];						///< �e�N�X�`���n���h��
	Uint32 VertexStart;						///< ���_�J�n�ʒu
	Uint32 VertexCount;						///< ���_��
	Uint32 IndexStart;						///< �C���f�b�N�X�J�n�ʒu
	Uint32 FaceCount;						///< �C���f�b�N�X��
};


/**
	@brief	�t�B�[���h�}�e���A���f�[�^

	�N�I�[�h�c���[�\�z�p�}�e���A���f�[�^
*/
struct LFIELDMATERIAL
{
	Sint32 IndexStart;
	Sint32 IndexCount;
};

/**
	@brief	�t�B�[���h���b�V���f�[�^

	�N�I�[�h�c���[�\�z�p���b�V���f�[�^
*/
struct LFIELDMESH
{
	CVector3D BBMin;							///< �o�E���f�B���O�{�b�N�X�ŏ��_
	CVector3D BBMax;							///< �o�E���f�B���O�{�b�N�X�ő�_

	IDirect3DVertexDeclaration9 *pVD;		///< ���_��`
	IDirect3DVertexBuffer9 *pVB;			///< ���_�o�b�t�@
	IDirect3DIndexBuffer9 *pIB;				///< �C���f�b�N�X�o�b�t�@

	void *pVertexData;						///< ���_�f�[�^
	void *pIndexData;						///< �C���f�b�N�X�f�[�^
	Uint32 VertexCount;						///< ���_��
	Uint32 IndexCount;						///< �C���f�b�N�X��

	CVector3D *pNormals;						///< �e�ʂ̖@��

	LFIELDMATERIAL *pMaterial;				///< �}�e���A���f�[�^
};

/**
	@brief	�t�B�[���h�t���[���f�[�^

	�N�I�[�h�c���[�\�z�p�t���[���f�[�^
*/
struct LFIELDFRAME
{
	LFIELDFRAME *pChild[4];					///< �q���t���[���ւ̃|�C���^
	Sint32 MeshNo;							///< �֘A�t�����Ă��郁�b�V���ԍ�

	CVector3D BBMin;							///< �o�E���f�B���O�{�b�N�X�ŏ��_
	CVector3D BBMax;							///< �o�E���f�B���O�{�b�N�X�ő�_

	BOX3D Box;								///< �o�E���f�B���O�{�b�N�X
};

/**
	@brief	�t�B�[���h�f�[�^

	LunaField�N���X�Ŏg�p�����A�t�B�[���h�f�[�^��<BR>
	�Ǘ����邽�߂̍\���̂ł�
*/
struct LUNAFIELDDATA : public OBJECTFILE
{
	Sint32 AreaCount;							///< �G���A��
	LFIELDMESH *pMeshData;					///< ���b�V���f�[�^
	Bool *pIsDrawList;						///< �`��f�[�^���X�g

	Bool IsBumpMap;							///< �o���v�}�b�v�̗L��

	LFIELDFRAME *pFrameRoot;				///< �t���[���̗L��

	LMATERIAL *pMaterial;					///< �}�e���A���f�[�^�|�C���^
	Uint32 MaterialCount;			///< �}�e���A����

	Uint16 Major;					///< �V�F�[�_�[���W���[�o�[�W����
	Uint16 Minor;					///< �V�F�[�_�[�}�C�i�[�o�[�W����

	D3DXHANDLE FxHandle[FX_HANDLE_MAX];		///< �G�t�F�N�g�n���h��
	LSHADERFX lShaderFx;					///< �G�t�F�N�g�n���h��
	Uint32 EffectSendData;			///< �G�t�F�N�g���M�f�[�^
};

#endif // ___LUNABASE_H___

