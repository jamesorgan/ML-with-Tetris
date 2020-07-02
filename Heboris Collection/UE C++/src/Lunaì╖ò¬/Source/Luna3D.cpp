
/**
    @brief		�R�c�����N���X
    @author		�t���`
*/

//=============================================================================
// INCLUDE
//=============================================================================
#include "LunaBase.h"

#include "Luna3D.h"
#include "LunaMain.h"
#include "LunaCamera.h"
#include "LunaLight.h"
#include "LunaField.h"
#include "LunaDebug.h"
#include "LunaLine.h"
#include "LunaLine3D.h"
#include "LunaPoint.h"
#include "LunaPoint3D.h"
#include "LunaPrimitive.h"
#include "LunaPrimitive3D.h"
#include "LunaSprite.h"
#include "LunaSprite3D.h"
#include "LunaSurface.h"
#include "LunaTexture.h"
#include "LunaVMR9.h"
#include "LunaModel.h"
#include "LunaModelEx.h"
#include "LunaShaderEffect.h"
#include "LunaSimple.h"


using namespace LibLuna;

//=============================================================================
// CONSTANT
//=============================================================================

//---------------------------------------------------------------
// �o�b�N�o�b�t�@�t�H�[�}�b�g
//---------------------------------------------------------------
static const D3DFORMAT BackBufferFormats[] = {
	D3DFMT_X8R8G8B8,
	D3DFMT_X1R5G5B5,
	D3DFMT_R5G6B5,
	D3DFMT_UNKNOWN,
};


//---------------------------------------------------------------
// �e�N�X�`���t�H�[�}�b�g
//---------------------------------------------------------------
static D3DFORMAT TextureFormats[] = {
	D3DFMT_R5G6B5,			D3DFMT_X1R5G5B5,		D3DFMT_A1R5G5B5,
	D3DFMT_A4R4G4B4,		D3DFMT_R8G8B8,			D3DFMT_A8R8G8B8,
	D3DFMT_X8R8G8B8,		D3DFMT_R3G3B2,			D3DFMT_A8,
	D3DFMT_A8R3G3B2,		D3DFMT_X4R4G4B4,		D3DFMT_A2B10G10R10,
	D3DFMT_A2R10G10B10,		D3DFMT_A16B16G16R16,	D3DFMT_A8P8,
	D3DFMT_P8,				D3DFMT_L8,				D3DFMT_L16,
	D3DFMT_A8L8,			D3DFMT_A4L4,			D3DFMT_V8U8,
	D3DFMT_Q8W8V8U8,		D3DFMT_V16U16,			D3DFMT_Q16W16V16U16,
	D3DFMT_CxV8U8,			D3DFMT_L6V5U5,			D3DFMT_X8L8V8U8,
	D3DFMT_A2W10V10U10,		D3DFMT_G8R8_G8B8,		D3DFMT_R8G8_B8G8,
	D3DFMT_DXT5,			D3DFMT_DXT4,			D3DFMT_DXT3,
	D3DFMT_DXT2,			D3DFMT_DXT1,			D3DFMT_UYVY,
	D3DFMT_YUY2,			D3DFMT_D16_LOCKABLE,	D3DFMT_D32,
	D3DFMT_D15S1,			D3DFMT_D24S8,			D3DFMT_D24X8,
	D3DFMT_D24X4S4,			D3DFMT_D32F_LOCKABLE,	D3DFMT_D24FS8,
	D3DFMT_D16,				D3DFMT_VERTEXDATA,		D3DFMT_INDEX16,
	D3DFMT_INDEX32,			D3DFMT_R16F,			D3DFMT_G16R16F,
	D3DFMT_A16B16G16R16F,	D3DFMT_R32F,			D3DFMT_G32R32F,
	D3DFMT_A32B32G32R32F,	D3DFMT_G16R16,			D3DFMT_UNKNOWN,
};


//---------------------------------------------------------------
// �[�x�o�b�t�@�t�H�[�}�b�g
//---------------------------------------------------------------
static D3DFORMAT DepthFormats[] = {
	D3DFMT_D16,				D3DFMT_D32,				D3DFMT_D24S8,
	D3DFMT_D24X8,			D3DFMT_D24X4S4,			D3DFMT_D24FS8,
	D3DFMT_D15S1,			D3DFMT_UNKNOWN,
};


//---------------------------------------------------------------
// �f�o�C�X�^�C�v
//---------------------------------------------------------------
static D3DDEVTYPE DeviceType[3] = {
	D3DDEVTYPE_HAL,													// 0
	D3DDEVTYPE_HAL,													// 1
	D3DDEVTYPE_REF,													// 2
};


//---------------------------------------------------------------
// ���_����
//---------------------------------------------------------------
static Uint32 CreateFlag[3] = {
	D3DCREATE_MIXED_VERTEXPROCESSING,								// 0
	D3DCREATE_SOFTWARE_VERTEXPROCESSING,							// 1
	D3DCREATE_SOFTWARE_VERTEXPROCESSING,							// 2
};

//---------------------------------------------------------------
// �����_�[�X�e�[�g�ꗗ
//---------------------------------------------------------------
static D3DRENDERSTATETYPE RenderStateTbl[] =
{
    D3DRS_ZENABLE,
    D3DRS_FILLMODE,
    D3DRS_SHADEMODE,
    D3DRS_ZWRITEENABLE,
    D3DRS_ALPHATESTENABLE,
    D3DRS_LASTPIXEL,
    D3DRS_SRCBLEND,
    D3DRS_DESTBLEND,
    D3DRS_CULLMODE,
    D3DRS_ZFUNC,
    D3DRS_ALPHAREF,
    D3DRS_ALPHAFUNC,
    D3DRS_DITHERENABLE,
    D3DRS_ALPHABLENDENABLE,
    D3DRS_FOGENABLE,
    D3DRS_SPECULARENABLE,
    D3DRS_FOGCOLOR,
    D3DRS_FOGTABLEMODE,
    D3DRS_FOGSTART,
    D3DRS_FOGEND,
    D3DRS_FOGDENSITY,
    D3DRS_RANGEFOGENABLE,
    D3DRS_STENCILENABLE,
    D3DRS_STENCILFAIL,
    D3DRS_STENCILZFAIL,
    D3DRS_STENCILPASS,
    D3DRS_STENCILFUNC,
    D3DRS_STENCILREF,
    D3DRS_STENCILMASK,
    D3DRS_STENCILWRITEMASK,
    D3DRS_TEXTUREFACTOR,
    D3DRS_WRAP0,
    D3DRS_WRAP1,
    D3DRS_WRAP2,
    D3DRS_WRAP3,
    D3DRS_WRAP4,
    D3DRS_WRAP5,
    D3DRS_WRAP6,
    D3DRS_WRAP7,
    D3DRS_CLIPPING,
    D3DRS_LIGHTING,
    D3DRS_AMBIENT,
    D3DRS_FOGVERTEXMODE,
    D3DRS_COLORVERTEX,
    D3DRS_LOCALVIEWER,
    D3DRS_NORMALIZENORMALS,
    D3DRS_DIFFUSEMATERIALSOURCE,
    D3DRS_SPECULARMATERIALSOURCE,
    D3DRS_AMBIENTMATERIALSOURCE,
    D3DRS_EMISSIVEMATERIALSOURCE,
    D3DRS_VERTEXBLEND,
    D3DRS_CLIPPLANEENABLE,
    D3DRS_POINTSIZE,
    D3DRS_POINTSIZE_MIN,
    D3DRS_POINTSPRITEENABLE,
    D3DRS_POINTSCALEENABLE,
    D3DRS_POINTSCALE_A,
    D3DRS_POINTSCALE_B,
    D3DRS_POINTSCALE_C,
    D3DRS_MULTISAMPLEANTIALIAS,
    D3DRS_MULTISAMPLEMASK,
    D3DRS_PATCHEDGESTYLE,
    D3DRS_DEBUGMONITORTOKEN,
    D3DRS_POINTSIZE_MAX,
    D3DRS_INDEXEDVERTEXBLENDENABLE,
    D3DRS_COLORWRITEENABLE,
    D3DRS_TWEENFACTOR,
    D3DRS_BLENDOP,
    D3DRS_POSITIONDEGREE,
    D3DRS_NORMALDEGREE,
    D3DRS_SCISSORTESTENABLE,
    D3DRS_SLOPESCALEDEPTHBIAS,
    D3DRS_ANTIALIASEDLINEENABLE,
    D3DRS_MINTESSELLATIONLEVEL,
    D3DRS_MAXTESSELLATIONLEVEL,
    D3DRS_ADAPTIVETESS_X,
    D3DRS_ADAPTIVETESS_Y,
    D3DRS_ADAPTIVETESS_Z,
    D3DRS_ADAPTIVETESS_W,
    D3DRS_ENABLEADAPTIVETESSELLATION,
    D3DRS_TWOSIDEDSTENCILMODE,
    D3DRS_CCW_STENCILFAIL,
    D3DRS_CCW_STENCILZFAIL,
    D3DRS_CCW_STENCILPASS,
    D3DRS_CCW_STENCILFUNC,
    D3DRS_COLORWRITEENABLE1,
    D3DRS_COLORWRITEENABLE2,
    D3DRS_COLORWRITEENABLE3,
    D3DRS_BLENDFACTOR,
    D3DRS_SRGBWRITEENABLE,
    D3DRS_DEPTHBIAS,
    D3DRS_WRAP8,
    D3DRS_WRAP9,
    D3DRS_WRAP10,
    D3DRS_WRAP11,
    D3DRS_WRAP12,
    D3DRS_WRAP13,
    D3DRS_WRAP14,
    D3DRS_WRAP15,
    D3DRS_SEPARATEALPHABLENDENABLE,
    D3DRS_SRCBLENDALPHA,
    D3DRS_DESTBLENDALPHA,
    D3DRS_BLENDOPALPHA,
};

static Uint32 RenderStateTblCount = sizeof(RenderStateTbl) / sizeof(D3DRENDERSTATETYPE);


//---------------------------------------------------------------
// �e�N�X�`���X�e�[�g�ꗗ
//---------------------------------------------------------------
static D3DTEXTURESTAGESTATETYPE TextureStateTbl[] =
{
    D3DTSS_COLOROP,
    D3DTSS_COLORARG1,
    D3DTSS_COLORARG2,
    D3DTSS_ALPHAOP,
    D3DTSS_ALPHAARG1,
    D3DTSS_ALPHAARG2,
    D3DTSS_BUMPENVMAT00,
    D3DTSS_BUMPENVMAT01,
    D3DTSS_BUMPENVMAT10,
    D3DTSS_BUMPENVMAT11,
    D3DTSS_TEXCOORDINDEX,
    D3DTSS_BUMPENVLSCALE,
    D3DTSS_BUMPENVLOFFSET,
    D3DTSS_TEXTURETRANSFORMFLAGS,
    D3DTSS_COLORARG0,
    D3DTSS_ALPHAARG0,
    D3DTSS_RESULTARG,
    D3DTSS_CONSTANT,
};

static Uint32 TextureStateTblCount = sizeof(TextureStateTbl) / sizeof(D3DTEXTURESTAGESTATETYPE);


//---------------------------------------------------------------
// �T���v���[�X�e�[�g�ꗗ
//---------------------------------------------------------------
static D3DSAMPLERSTATETYPE SamplerStateTbl[] =
{
    D3DSAMP_ADDRESSU,
    D3DSAMP_ADDRESSV,
    D3DSAMP_ADDRESSW,
    D3DSAMP_BORDERCOLOR,
    D3DSAMP_MAGFILTER,
    D3DSAMP_MINFILTER,
    D3DSAMP_MIPFILTER,
    D3DSAMP_MIPMAPLODBIAS,
    D3DSAMP_MAXMIPLEVEL,
    D3DSAMP_MAXANISOTROPY,
    D3DSAMP_SRGBTEXTURE,
    D3DSAMP_ELEMENTINDEX,
    D3DSAMP_DMAPOFFSET,
};

static Uint32 SamplerStateTblCount = sizeof(SamplerStateTbl) / sizeof(D3DSAMPLERSTATETYPE);


//=============================================================================
// VARIABLE
//=============================================================================
Sint32					Luna3D::m_SceneCount;
HINSTANCE				Luna3D::m_hDllD3D9;
IDirect3D9				*Luna3D::m_pDirect3D;
IDirect3DDevice9		*Luna3D::m_pDevice;
IDirect3DSurface9		*Luna3D::m_pRenderTarget;
IDirect3DQuery9			*Luna3D::m_pQuery[2];
D3DVIEWPORT9			Luna3D::m_Viewport;
char					Luna3D::m_AdapterName[128];
char					Luna3D::m_AdapterDriver[128];
char					Luna3D::m_AdapterVersion[128];
D3DMULTISAMPLE_TYPE		Luna3D::m_MultiSampleType;
Uint32					Luna3D::m_MultiSampleQuality;
DEVICEINFORMATION		Luna3D::m_DeviceInfo;
D3DDISPLAYMODE			Luna3D::m_WindowMode;
D3DDISPLAYMODE			Luna3D::m_FullScreenMode[2];
ADAPTERDATA				Luna3D::m_AdapterData;
D3DPRESENT_PARAMETERS	Luna3D::m_PresentParams[2];
LCAMERA					Luna3D::m_lCamera;
LTEXTURE				Luna3D::m_lTexTarget;
LSURFACE				Luna3D::m_lSurfTarget;
LSURFACE				Luna3D::m_lSurfDepthStencil;
LTEXTURE				Luna3D::m_lTexActive[TEXTURE_STAGE_MAX];
Uint32					Luna3D::m_RenderState[RENDER_STATE_TBL_MAX];
Uint32					Luna3D::m_SamplerState[TEXTURE_STAGE_MAX][SAMPLER_STATE_TBL_MAX];
Uint32					Luna3D::m_TextureState[TEXTURE_STAGE_MAX][TEXTURE_STATE_TBL_MAX];
Uint32					Luna3D::m_MaxVertexShaderVersion;
HFONT					Luna3D::m_hFont;
HFONT					Luna3D::m_hOldFont;
HDC						Luna3D::m_hDC;
Float					Luna3D::m_FogNear;
Float					Luna3D::m_FogFar;
D3DCOLOR				Luna3D::m_FogColor;
Bool					Luna3D::m_IsWaitBlank;
Bool					Luna3D::m_IsFullColor;
Bool					Luna3D::m_IsEmulationMode;
Bool					Luna3D::m_IsLocked;
Bool					Luna3D::m_IsCheckingFillRate;
Bool					Luna3D::m_IsNVPerfHUD;
void					(*Luna3D::m_pCallbackReset)( void );
void					(*Luna3D::m_pCallbackRestore)( void );
MATERIALSTATE			Luna3D::m_DefaultState;

eSurfaceFormat Luna3D::m_SurfaceFormatTbl[2][16] = {
	{ FORMAT_TEXTURE32,	FORMAT_TEXTURE16,	FORMAT_DXT5,		FORMAT_DXT3 },
	{ FORMAT_DXT5,		FORMAT_DXT3,		FORMAT_TEXTURE32,	FORMAT_TEXTURE16 },
};
Uint32 Luna3D::m_SurfaceFormatCount[2] = { 4, 4 };


//=============================================================================
/**
	�R�c�N���X�̏����������܂��B

	@retval true		����
	@retval false		���s
*/
//=============================================================================
Bool Luna3D::Initialize( void )
{
	Luna::LogoutMainCategory( "Luna3D�N���X�̏�����" );
	Luna::LogoutNextLine();

	//----------------------------------------------------------
	// �f�t�H���g�l
	//----------------------------------------------------------
	m_MaxVertexShaderVersion = D3DVS_VERSION(2,0);

	//----------------------------------------------------------
	// �A�_�v�^�[�̏�����
	//----------------------------------------------------------
	if ( !Luna3D::InitAdapter() )
	{
		Luna::MsgBox( MB_ICONERROR, "Luna3D", "�A�_�v�^�[�̏������Ɏ��s" );
		return false;
	}

	return true;
}

//=============================================================================
/**
	�R�c�N���X�̉�������܂��B

*/
//=============================================================================
void Luna3D::Finalize( void )
{
	Luna::LogoutMainCategory( "Luna3D�N���X�̉��" );
	Luna::LogoutNextLine();

	for ( Sint32 i = 0; i < 2; i++ )
	{
		if ( m_pQuery[i] != NULL )
		{
			m_pQuery[i]->Release();
			m_pQuery[i] = NULL;
			Luna::Logout( "IDirect3DQuery9�C���^�[�t�F�[�X�����" );
			Luna::LogoutNextLine();
		}
	}

	SAFE_RELEASE( m_pRenderTarget );

	if ( m_pDevice != NULL )
	{
		m_pDevice->Release();
		m_pDevice = NULL;
		Luna::Logout( "Direct3D�f�o�C�X�����" );
		Luna::LogoutNextLine();
	}

	if ( m_pDirect3D != NULL )
	{
		m_pDirect3D->Release();
		m_pDirect3D = NULL;
		Luna::Logout( "Direct3D�I�u�W�F�N�g�����" );
		Luna::LogoutNextLine();
	}

	if ( m_hDllD3D9 != NULL )
	{
		::FreeLibrary( m_hDllD3D9 );
		m_hDllD3D9 = NULL;
		Luna::Logout( "DLL�����" );
		Luna::LogoutNextLine();
	}

	Luna::LogoutNextLine();
}

//=============================================================================
/**
	�A�_�v�^�[�̏����������܂��B

	@retval true		����
	@retval false		���s
*/
//=============================================================================
Bool Luna3D::InitAdapter( void )
{
	//---------------------------------------------------------------
	// Direct3D�I�u�W�F�N�g�̐���
	//---------------------------------------------------------------
	if ( !Luna3D::CreateDirect3DObject() )
	{
		return false;
	}

	//---------------------------------------------------------------
	// �A�_�v�^�[���̃`�F�b�N
	//---------------------------------------------------------------
	if ( !Luna3D::CheckAdapterInformation() )
	{
		return false;
	}

	//---------------------------------------------------------------
	// �f�o�C�X���̃`�F�b�N
	//---------------------------------------------------------------
	if ( !Luna3D::CheckDeviceInformation() )
	{
		return false;
	}

	return true;
}

//=============================================================================
/**
	Direct3D�I�u�W�F�N�g�̐��������܂��B

	@retval true		����
	@retval false		���s
*/
//=============================================================================
Bool Luna3D::CreateDirect3DObject( void )
{
	PDIRECT3DCREATE9 pProcDirect3DCreate9 = NULL;

	//---------------------------------------------------------------
	// Load DLL
	//---------------------------------------------------------------
	m_hDllD3D9 = ::LoadLibrary( "d3d9.dll" );
	if ( m_hDllD3D9 == NULL )
	{
		Luna::LogoutError( "�@�@�@�G���[ : DLL�̓ǂݍ��݂Ɏ��s" );
		Luna::LogoutNextLine();
		Luna::LogoutError( "�@�@�@DirectX9c���������C���X�g�[������Ă��邩�m�F���ĉ�����" );
		Luna::LogoutNextLine();
		Luna::MsgBox( MB_ICONERROR, "Luna3D", "DLL�̓ǂݍ��݂Ɏ��s\nDirectX9c���������C���X�g�[������Ă��邩\n�m�F���ĉ�����" );
		return false;
	}

	//---------------------------------------------------------------
	// Load Direct3DCreate from DLL
	//---------------------------------------------------------------
	pProcDirect3DCreate9 = (PDIRECT3DCREATE9)::GetProcAddress( m_hDllD3D9, "Direct3DCreate9" );
	if ( pProcDirect3DCreate9 == NULL )
	{
		Luna::LogoutError( "�@�@�@�G���[ : DLL����̊֐��Ăяo���Ɏ��s" );
		Luna::LogoutNextLine();
		Luna::LogoutError( "�@�@�@DirectX9c���������C���X�g�[������Ă��邩�m�F���ĉ�����" );
		Luna::LogoutNextLine();
		Luna::MsgBox( MB_ICONERROR, "Luna3D", "DLL����̊֐��Ăяo���Ɏ��s\nDirectX9c���������C���X�g�[������Ă��邩\n�m�F���ĉ�����" );
		return false;
	}

	//---------------------------------------------------------------
	// Create Direct3D Object
	//---------------------------------------------------------------
	m_pDirect3D = pProcDirect3DCreate9( D3D_SDK_VERSION );
	if ( m_pDirect3D == NULL )
	{
		Luna::LogoutError( "�@�@�@�G���[ : Direct3D�I�u�W�F�N�g�̐����Ɏ��s" );
		Luna::LogoutNextLine();
		Luna::LogoutError( "�@�@�@DirectX9c���������C���X�g�[������Ă��邩�m�F���ĉ�����" );
		Luna::LogoutNextLine();
		Luna::MsgBox( MB_ICONERROR, "Luna3D", "Direct3D�I�u�W�F�N�g�̐����Ɏ��s\nDirectX9c���������C���X�g�[������Ă��邩\n�m�F���ĉ�����" );
		return false;
	}

	return true;
}

//=============================================================================
/**
	�A�_�v�^�[���̎擾�����܂��B

	@retval true		����
	@retval false		���s
*/
//=============================================================================
Bool Luna3D::CheckAdapterInformation( void )
{
	D3DADAPTER_IDENTIFIER9 Identifier;
	HRESULT hr;

	//---------------------------------------------------------------
	// �A�_�v�^�[���
	//---------------------------------------------------------------
	Luna::LogoutKeyword( "�A�_�v�^�[���" );
	Luna::LogoutNextLine();

	hr = m_pDirect3D->GetAdapterIdentifier( D3DADAPTER_DEFAULT, 0, &Identifier );
	if SUCCEEDED( hr )
	{
		strcpy( m_AdapterName, Identifier.Description );
		strcpy( m_AdapterDriver, Identifier.Driver );
		sprintf(
			m_AdapterVersion,
			"%u.%u.%u.%u",
			HIWORD(Identifier.DriverVersion.HighPart),
			LOWORD(Identifier.DriverVersion.HighPart),
			HIWORD(Identifier.DriverVersion.LowPart),
			LOWORD(Identifier.DriverVersion.LowPart) );

		Luna::Logout( "�@�@�@Name [ %s ]", Identifier.Description );
		Luna::LogoutNextLine();
		Luna::Logout( "�@�@�@Driver [ %s ]", Identifier.Driver );
		Luna::LogoutNextLine();
		Luna::Logout( "�@�@�@Product [ %u ]", HIWORD(Identifier.DriverVersion.HighPart) );
		Luna::LogoutNextLine();
		Luna::Logout( "�@�@�@Version [ %u.%u.%u ]",
			LOWORD(Identifier.DriverVersion.HighPart),
			HIWORD(Identifier.DriverVersion.LowPart),
			LOWORD(Identifier.DriverVersion.LowPart) );
		Luna::LogoutNextLine();

		Luna::Logout( "�@Windows Hardware Quality Lab (WHQL) �F�؃��x��" );
		Luna::LogoutNextLine();

		if ( Identifier.WHQLLevel == 0 )
		{
			Luna::Logout( "�@�@�@�F�؂���Ă��Ȃ��B" );
			Luna::LogoutNextLine();
		}
		ef ( Identifier.WHQLLevel == 1 )
		{
			Luna::Logout( "�@�@�@WHQL �̔F�؂͎󂯂Ă��邪�A���p�ł�����t���͂Ȃ��B" );
			Luna::LogoutNextLine();
		}
		else
		{
			Luna::Logout( "�@�@�@%u.%u.%u",
				((Identifier.WHQLLevel>>16)&0xFF), ((Identifier.WHQLLevel>>8)&0x0F), ((Identifier.WHQLLevel>>0)&0x0F) );
			Luna::LogoutNextLine();
		}
	}

	Luna::LogoutNextLine();

	//---------------------------------------------------------------
	// ���݂̉�ʃ��[�h�擾
	//---------------------------------------------------------------
	Luna::LogoutKeyword( "���݂̉�ʏ��" );
	Luna::LogoutNextLine();

	hr = m_pDirect3D->GetAdapterDisplayMode( D3DADAPTER_DEFAULT, &m_WindowMode );
	if SUCCEEDED( hr )
	{
		Luna::Logout( "�@�@�@Width [ %u ]", m_WindowMode.Width );
		Luna::LogoutNextLine();

		Luna::Logout( "�@�@�@Height [ %u ]", m_WindowMode.Height );
		Luna::LogoutNextLine();

		Luna::Logout( "�@�@�@RefreshRate [ %u ]", m_WindowMode.RefreshRate );
		Luna::LogoutNextLine();

		Luna::Logout( "�@�@�@Format [ %s ]", Luna3D::GetPixelFormat(m_WindowMode.Format) );
		Luna::LogoutNextLine();
	}

	Luna::LogoutNextLine();

	//---------------------------------------------------------------
	// �t���X�N���[�����Ɏg�p�\�ȉ�ʃ��[�h��񋓂���
	//---------------------------------------------------------------
	Luna::LogoutKeyword( "�g�p�\�ȉ�ʃ��[�h���" );
	Luna::LogoutNextLine();

	for ( Sint32 i = 0; BackBufferFormats[i] != D3DFMT_UNKNOWN; i++ )
	{
		// �f�B�X�v���C���[�h���̎擾
		D3DDISPLAYMODE DisplayMode;
		Uint32 ModeCount = m_pDirect3D->GetAdapterModeCount( D3DADAPTER_DEFAULT, BackBufferFormats[i] );

		if ( ModeCount > 0 )
		{
			Luna::LogoutStrong( "�@BackBuffer Format [ %s ]", GetPixelFormat(BackBufferFormats[i]) );
			Luna::LogoutNextLine();

			// ���[�h���
			for ( Uint32 j = 0; j < ModeCount; j++ )
			{
				hr = m_pDirect3D->EnumAdapterModes( D3DADAPTER_DEFAULT, BackBufferFormats[i], j, &DisplayMode );
				if SUCCEEDED( hr )
				{
					Bool IsNew = true;

					// �����ʃT�C�Y�̌���
					for ( Sint32 k = 0; k < m_AdapterData.ModeCount; k++ )
					{
						if ( m_AdapterData.Mode[k].Width == DisplayMode.Width )
						{
							if ( m_AdapterData.Mode[k].Height == DisplayMode.Height )
							{
								if ( m_AdapterData.Mode[k].Format == DisplayMode.Format )
								{
									IsNew = false;
								}
							}
						}
					}

					// �����ʃT�C�Y��������Ȃ������ꍇ�͐V��������Ă���
					if ( IsNew )
					{
						m_AdapterData.Mode[m_AdapterData.ModeCount++] = DisplayMode;
						Luna::Logout( "�@�@�@[ %u x %u ] [ %uHz ]", DisplayMode.Width, DisplayMode.Height, DisplayMode.RefreshRate );
						Luna::LogoutNextLine();
					}

				}
			}

			Luna::LogoutNextLine();
		}
	}

	Luna::LogoutNextLine();

	//---------------------------------------------------------------
	// �t���X�N���[�����[�h�p�̃f�B�X�v���C���[�h�ݒ�
	//---------------------------------------------------------------
	Luna::LogoutKeyword( "�t���X�N���[���p�f�B�X�v���C���[�h�̌���" );
	Luna::LogoutNextLine();

	Sint32 Width, Height;
	Luna::GetScreenData( &Width, &Height, NULL );

	// �N���A
	m_FullScreenMode[0].Format = D3DFMT_UNKNOWN;
	m_FullScreenMode[1].Format = D3DFMT_UNKNOWN;

	// ����
	for ( Sint32 j = 0; j < m_AdapterData.ModeCount; j++ )
	{
		if ( m_AdapterData.Mode[j].Width == (Uint32)Width )
		{
			if ( m_AdapterData.Mode[j].Height == (Uint32)Height )
			{
				switch ( m_AdapterData.Mode[j].Format )
				{
				// 16Bit
				case D3DFMT_X1R5G5B5:
				case D3DFMT_R5G6B5:
					m_FullScreenMode[0] = m_AdapterData.Mode[j];
					break;
				// 32Bit
				case D3DFMT_X8R8G8B8:
					m_FullScreenMode[1] = m_AdapterData.Mode[j];
					break;
				}
			}
		}
	}

	// ���O
	Luna::Logout( "�@�@�@16BitColor [ %s ]", Luna3D::GetPixelFormat(m_FullScreenMode[0].Format) );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@32BitColor [ %s ]", Luna3D::GetPixelFormat(m_FullScreenMode[1].Format) );
	Luna::LogoutNextLine();

	Luna::LogoutNextLine();

	//---------------------------------------------------------------
	// �e�N�X�`���t�H�[�}�b�g����g�p�\�Ȃ��̂�����
	//---------------------------------------------------------------
	Luna::LogoutKeyword( "�g�p�\�ȃe�N�X�`���t�H�[�}�b�g���" );
	Luna::LogoutNextLine();

	D3DFORMAT BaseFormat = m_FullScreenMode[1].Format == D3DFMT_UNKNOWN ? m_WindowMode.Format : m_FullScreenMode[1].Format;

	for ( Sint32 i = 0; TextureFormats[i] != D3DFMT_UNKNOWN; i++ )
	{
		hr = m_pDirect3D->CheckDeviceFormat(
						D3DADAPTER_DEFAULT,
						D3DDEVTYPE_HAL,
						BaseFormat,
						D3DUSAGE_AUTOGENMIPMAP,
						D3DRTYPE_TEXTURE,
						TextureFormats[i] );
		if ( SUCCEEDED(hr) && (hr != D3DOK_NOAUTOGEN) )
		{
			m_AdapterData.TextureFormats[ m_AdapterData.TextureCount ] = TextureFormats[i];
			m_AdapterData.TextureMipmap[ m_AdapterData.TextureCount ] = true;
			m_AdapterData.TextureCount++;

			Luna::Logout( "�@�@�@�� [ %s ]", Luna3D::GetPixelFormat(TextureFormats[i]) );
			Luna::LogoutNextLine();
		}
		else
		{
			hr = m_pDirect3D->CheckDeviceFormat(
							D3DADAPTER_DEFAULT,
							D3DDEVTYPE_HAL,
							BaseFormat,
							0,
							D3DRTYPE_TEXTURE,
							TextureFormats[i] );
			if SUCCEEDED( hr )
			{
				m_AdapterData.TextureFormats[ m_AdapterData.TextureCount ] = TextureFormats[i];
				m_AdapterData.TextureMipmap[ m_AdapterData.TextureCount ] = false;
				m_AdapterData.TextureCount++;

				Luna::Logout( "�@�@�@�~ [ %s ]", Luna3D::GetPixelFormat(TextureFormats[i]) );
				Luna::LogoutNextLine();
			}
		}
	}

	Luna::LogoutNextLine();

	//---------------------------------------------------------------
	// �����_�����O�^�[�Q�b�g�e�N�X�`���t�H�[�}�b�g����g�p�\�Ȃ��̂�����
	//---------------------------------------------------------------
	Luna::LogoutKeyword( "�g�p�\�ȃ����_�����O�^�[�Q�b�g�e�N�X�`���t�H�[�}�b�g���" );
	Luna::LogoutNextLine();

	for ( Sint32 i = 0; TextureFormats[i] != D3DFMT_UNKNOWN; i++ )
	{
		hr = m_pDirect3D->CheckDeviceFormat(
						D3DADAPTER_DEFAULT,
						D3DDEVTYPE_HAL,
						BaseFormat,
						D3DUSAGE_RENDERTARGET,
						D3DRTYPE_TEXTURE,
						TextureFormats[i] );
		if SUCCEEDED( hr )
		{
			m_AdapterData.TargetFormats[ m_AdapterData.TargetCount++ ] = TextureFormats[i];

			Luna::Logout( "�@�@�@[ %s ]", Luna3D::GetPixelFormat(TextureFormats[i]) );
			Luna::LogoutNextLine();
		}
	}

	Luna::LogoutNextLine();

	//---------------------------------------------------------------
	// �[�x�o�b�t�@�t�H�[�}�b�g����g�p�\�Ȃ��̂�����
	//---------------------------------------------------------------
	Luna::LogoutKeyword( "�g�p�\�Ȑ[�x�o�b�t�@�t�H�[�}�b�g���" );
	Luna::LogoutNextLine();

	for ( Sint32 i = 0; DepthFormats[i] != D3DFMT_UNKNOWN; i++ )
	{
		hr = m_pDirect3D->CheckDeviceFormat(
								D3DADAPTER_DEFAULT,
								D3DDEVTYPE_HAL,
								BaseFormat,
								D3DUSAGE_DEPTHSTENCIL,
								D3DRTYPE_SURFACE,
								DepthFormats[i] );
		if SUCCEEDED( hr )
		{
			m_AdapterData.DepthFormats[ m_AdapterData.DepthCount++ ] = DepthFormats[i];

			Luna::Logout( "�@�@�@[ %s ]", Luna3D::GetPixelFormat(DepthFormats[i]) );
			Luna::LogoutNextLine();
		}
	}

	Luna::LogoutNextLine();

	return true;
}

//=============================================================================
/**
	�R�c�f�o�C�X�̐��\�`�F�b�N�����܂��B

	@retval true		����
	@retval false		���s
*/
//=============================================================================
Bool Luna3D::CheckDeviceInformation( void )
{
	Luna::LogoutKeyword( "�f�o�C�X�\�͂̎擾" );
	Luna::LogoutNextLine();

	D3DCAPS9 Caps;

	//-----------------------------------------------------------
	// �n�[�h�E�F�A�f�o�C�X�̐��\���擾
	//-----------------------------------------------------------
	m_pDirect3D->GetDeviceCaps( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &Caps );
	GetDeviceCaps( &Caps, &m_DeviceInfo );

	//-----------------------------------------------------------
	// �n�[�h�E�F�A�f�o�C�X�̐��\���
	//-----------------------------------------------------------
	Luna::LogoutStrong( "�@�f�o�C�X�\��" );
	Luna::LogoutNextLine();

	Luna::Logout( "�@�@�@[ %s ] �s���A�f�o�C�X", m_DeviceInfo.IsPureDevice ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �n�[�h�E�F�A�s���k", m_DeviceInfo.IsHardwareTnL ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �n�[�h�E�F�A���X�^���C�Y", m_DeviceInfo.IsSoftwareTnL ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �ٕ����t�B���^�����O", m_DeviceInfo.IsAnisotropy ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �f�B�U�����O", m_DeviceInfo.IsDither ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �[�x�o�C�A�X", m_DeviceInfo.IsDepthBias ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �v�o�b�t�@", m_DeviceInfo.IsWBuffer ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �~�b�v�}�b�v��������", m_DeviceInfo.IsAutoMipMap ? "��" : "�~" );
	Luna::LogoutNextLine();

	Luna::LogoutStrong( "�@�[�x�e�X�g�\��" );
	Luna::LogoutNextLine();

	Luna::Logout( "�@�@�@[ %s ] �[�x�e�X�g ALWAYS", m_DeviceInfo.IsZCmpAlways ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �[�x�e�X�g EQUAL", m_DeviceInfo.IsZCmpEqual ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �[�x�e�X�g GREATER", m_DeviceInfo.IsZCmpGreater ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �[�x�e�X�g GREATER EQUA", m_DeviceInfo.IsZCmpGreaterEqual ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �[�x�e�X�g LESS", m_DeviceInfo.IsZCmpLess ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �[�x�e�X�g LESS EQUAL", m_DeviceInfo.IsZCmpLessEqual ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �[�x�e�X�g NEVER", m_DeviceInfo.IsZCmpNever ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �[�x�e�X�g NOT EQUAL", m_DeviceInfo.IsZCmpNotEqual ? "��" : "�~" );
	Luna::LogoutNextLine();

	Luna::LogoutStrong( "�@�\�[�X�u�����h�\��" );
	Luna::LogoutNextLine();

	Luna::Logout( "�@�@�@[ %s ] �\�[�X�u�����h BLEND FACTOR", m_DeviceInfo.IsSrcBlendFactor ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �\�[�X�u�����h BOTH INVSRC", m_DeviceInfo.IsSrcBothInvSrc ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �\�[�X�u�����h BOTH SRC", m_DeviceInfo.IsSrcBothSrc ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �\�[�X�u�����h DEST ALPHA", m_DeviceInfo.IsSrcDestAlpha ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �\�[�X�u�����h DEST COLOR", m_DeviceInfo.IsSrcDestColor ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �\�[�X�u�����h INV DEST ALPHA", m_DeviceInfo.IsSrcInvDestAlpha ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �\�[�X�u�����h INV DEST COLOR", m_DeviceInfo.IsSrcInvDestColor ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �\�[�X�u�����h INV SRC ALPHA", m_DeviceInfo.IsSrcInvSrcAlpha ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �\�[�X�u�����h INV SRC COLOR", m_DeviceInfo.IsSrcInvSrcColor ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �\�[�X�u�����h ONE", m_DeviceInfo.IsSrcOne ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �\�[�X�u�����h SRC ALPHA", m_DeviceInfo.IsSrcSrcAlpha ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �\�[�X�u�����h SRC ALPHA SAT", m_DeviceInfo.IsSrcSrcAphaSat ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �\�[�X�u�����h SRC COLOR", m_DeviceInfo.IsSrcSrcColor ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �\�[�X�u�����h ZERO", m_DeviceInfo.IsSrcZero ? "��" : "�~" );
	Luna::LogoutNextLine();

	Luna::LogoutStrong( "�@�f�X�g�u�����h�\��" );
	Luna::LogoutNextLine();

	Luna::Logout( "�@�@�@[ %s ] �f�X�g�u�����h BLEND FACTOR", m_DeviceInfo.IsDstBlendFactor ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �f�X�g�u�����h BOTH INVSRC", m_DeviceInfo.IsDstBothInvSrc ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �f�X�g�u�����h BOTH SRC", m_DeviceInfo.IsDstBothSrc ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �f�X�g�u�����h DEST ALPHA", m_DeviceInfo.IsDstDestAlpha ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �f�X�g�u�����h DEST COLOR", m_DeviceInfo.IsDstDestColor ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �f�X�g�u�����h INV DEST ALPHA", m_DeviceInfo.IsDstInvDestAlpha ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �f�X�g�u�����h INV DEST COLOR", m_DeviceInfo.IsDstInvDestColor ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �f�X�g�u�����h INV SRC ALPHA", m_DeviceInfo.IsDstInvSrcAlpha ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �f�X�g�u�����h INV SRC COLOR", m_DeviceInfo.IsDstInvSrcColor ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �f�X�g�u�����h ONE", m_DeviceInfo.IsDstOne ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �f�X�g�u�����h SRC ALPHA", m_DeviceInfo.IsDstSrcAlpha ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �f�X�g�u�����h SRC ALPHA SAT", m_DeviceInfo.IsDstSrcAphaSat ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �f�X�g�u�����h SRC COLOR", m_DeviceInfo.IsDstSrcColor ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �f�X�g�u�����h ZERO", m_DeviceInfo.IsDstZero ? "��" : "�~" );
	Luna::LogoutNextLine();

	Luna::LogoutStrong( "�@�e�N�X�`���\��" );
	Luna::LogoutNextLine();

	Luna::Logout( "�@�@�@[ %s ] �L���[�u�}�b�v", m_DeviceInfo.IsCubeTexture ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �~�b�v�}�b�v", m_DeviceInfo.IsMipmapTexture ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �p�[�X�y�N�e�B�u�R���N�g", m_DeviceInfo.IsPerspective ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �Q�ׂ̂���ȊO�̃e�N�X�`��", m_DeviceInfo.IsPow2 ? "�~" : "��" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �����`�ȊO�̃e�N�X�`��", m_DeviceInfo.IsSquareOnly ? "�~" : "��" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �e�N�X�`�� BORDER", m_DeviceInfo.IsTextureBorder ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �e�N�X�`�� CLAMP", m_DeviceInfo.IsTxtureClamp ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �e�N�X�`�� INDEPENDENT", m_DeviceInfo.IsTextureIndependent ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �e�N�X�`�� MIRROR", m_DeviceInfo.IsTextureMirror ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �e�N�X�`�� MIRROR RONCE", m_DeviceInfo.IsTextureMirrorRonce ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �e�N�X�`�� WRAP", m_DeviceInfo.IsTextureWrap ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�e�N�X�`���ő剡�� [ %u ]", m_DeviceInfo.MaxTextureWidth );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�e�N�X�`���ő�c�� [ %u ]", m_DeviceInfo.MaxTextureHeight );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�e�N�X�`���ő僊�s�[�g�� [ %u ]", m_DeviceInfo.MaxTextureRepeat );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�e�N�X�`���ő�A�X�y�N�g [ %u ]", m_DeviceInfo.MaxTextureAspectRatio );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�e�N�X�`���ٕ����̎��� [ %u ]", m_DeviceInfo.MaxAnisotropy );
	Luna::LogoutNextLine();

	Luna::LogoutStrong( "�@�X�e���V���\��" );
	Luna::LogoutNextLine();

	Luna::Logout( "�@�@�@[ %s ] �X�e���V�� KEEP", m_DeviceInfo.IsStencilKeep ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �X�e���V�� ZERO", m_DeviceInfo.IsStencilZero ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �X�e���V�� REPLACE", m_DeviceInfo.IsStencilReplace ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �X�e���V�� INCRSAT", m_DeviceInfo.IsStencilIncRsat ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �X�e���V�� DECRSAT", m_DeviceInfo.IsStencilDecRsat ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �X�e���V�� INVERT", m_DeviceInfo.IsStencilInvert ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �X�e���V�� INCR", m_DeviceInfo.IsStencilIncR ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �X�e���V�� DECR", m_DeviceInfo.IsStencilDecR ? "��" : "�~" );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@[ %s ] �X�e���V�� TWO SIDED", m_DeviceInfo.IsStencilTwoSided ? "��" : "�~" );
	Luna::LogoutNextLine();

	Luna::LogoutStrong( "�@���̑�" );
	Luna::LogoutNextLine();

	Luna::Logout( "�@�@�@�ő傗�l [ %lf ]", m_DeviceInfo.MaxVertexW );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�K�[�h�o���h�@�� [ %.3lf ]", m_DeviceInfo.GuardBandLeft );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�K�[�h�o���h�@�� [ %.3lf ]", m_DeviceInfo.GuardBandTop );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�K�[�h�o���h�@�E [ %.3lf ]", m_DeviceInfo.GuardBandRight );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�K�[�h�o���h�@�� [ %.3lf ]", m_DeviceInfo.GuardBandBottom );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�|�C���g�T�C�Y [ %.3lf ]", m_DeviceInfo.MaxPointSize );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�ő�v���~�e�B�u�� [ %u ]", m_DeviceInfo.MaxPrimitiveCount );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�ő�C���f�b�N�X�� [ %u ]", m_DeviceInfo.MaxVertexIndex );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�ő�e�N�X�`���X�e�[�W�� [ %u ]", m_DeviceInfo.MaxTextureBlendStages );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�ő�}���`�e�N�X�`���� [ %u ]", m_DeviceInfo.MaxSimultaneousTextures );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�ő�n�[�h�E�F�A���C�g�� [ %u ]", m_DeviceInfo.MaxActiveLights );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�ő�u�����h�}�g���b�N�X�� [ %u ]", m_DeviceInfo.MaxVertexBlendMatrices );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�ő�u�����h�C���f�b�N�X�� [ %u ]", m_DeviceInfo.MaxVertexBlendMatrixIndex );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�ő咸�_�V�F�[�_�[�萔�� [ %u ]", m_DeviceInfo.MaxVertexShaderConst );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@���_�V�F�[�_�[�o�[�W���� [ %u.%u ]", D3DSHADER_VERSION_MAJOR(m_DeviceInfo.VertexShaderVersion), D3DSHADER_VERSION_MINOR(m_DeviceInfo.VertexShaderVersion) );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�s�N�Z���V�F�[�_�[�o�[�W����[ %u.%u ]", D3DSHADER_VERSION_MAJOR(m_DeviceInfo.PixelShaderVersion), D3DSHADER_VERSION_MINOR(m_DeviceInfo.PixelShaderVersion) );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@���I�t���[���䖽�߂̃l�X�e�B���O [ %u ]", m_DeviceInfo.DynamicFlowControlDepth );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�ÓI�t���[���䖽�߂̃l�X�e�B���O [ %u ]", m_DeviceInfo.StaticFlowControlDepth );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�ٕ����t�B���^�����O�ő原�� [ %u ]", m_DeviceInfo.MaxMaxAnisotropy );
	Luna::LogoutNextLine();

	Luna::LogoutNextLine();

	return true;
}

//=============================================================================
/**
	�R�c�f�o�C�X�̐��\���擾���܂��B

	@param pCaps		[in] �f�o�C�X�̐��\���i�[���ꂽ�L���p�V�e�B�\����
	@param pDevInfo		[out] �f�o�C�X���i�[�p�\���̃A�h���X

*/
//=============================================================================
void Luna3D::GetDeviceCaps( D3DCAPS9 *pCaps, DEVICEINFORMATION *pDevInfo )
{
	//-----------------------------------------------------------
	// �f�o�C�X���
	//-----------------------------------------------------------

	// �f�o�C�X�^�C�v
	pDevInfo->DeviceType				= pCaps->DeviceType;
	// �s���A�f�o�C�X
	pDevInfo->IsPureDevice				= ((pCaps->DevCaps & D3DDEVCAPS_PUREDEVICE) != 0);
	// �n�[�h�E�F�ATnL
	pDevInfo->IsHardwareTnL				= ((pCaps->DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) != 0);
	// �n�[�h�E�F�ARaster
	pDevInfo->IsSoftwareTnL				= ((pCaps->DevCaps & D3DDEVCAPS_HWRASTERIZATION) != 0);
	// �f�B�U�����O
	pDevInfo->IsDither					= ((pCaps->RasterCaps & D3DPRASTERCAPS_DITHER) != 0);
	// �[�x�o�C�A�X
	pDevInfo->IsDepthBias				= ((pCaps->RasterCaps & D3DPRASTERCAPS_DEPTHBIAS) != 0);
	// �v�o�b�t�@
	pDevInfo->IsWBuffer					= ((pCaps->RasterCaps & D3DPRASTERCAPS_WBUFFER) != 0);
	// �~�b�v�}�b�v
	pDevInfo->IsAutoMipMap				= ((pCaps->Caps2 & D3DCAPS2_CANAUTOGENMIPMAP) != 0);
	// �y��r
	pDevInfo->IsZCmpAlways				= ((pCaps->ZCmpCaps & D3DPCMPCAPS_ALWAYS) != 0);
	pDevInfo->IsZCmpEqual				= ((pCaps->ZCmpCaps & D3DPCMPCAPS_EQUAL) != 0);
	pDevInfo->IsZCmpGreater				= ((pCaps->ZCmpCaps & D3DPCMPCAPS_GREATER) != 0);
	pDevInfo->IsZCmpGreaterEqual		= ((pCaps->ZCmpCaps & D3DPCMPCAPS_GREATEREQUAL) != 0);
	pDevInfo->IsZCmpLess				= ((pCaps->ZCmpCaps & D3DPCMPCAPS_LESS) != 0);
	pDevInfo->IsZCmpLessEqual			= ((pCaps->ZCmpCaps & D3DPCMPCAPS_LESSEQUAL) != 0);
	pDevInfo->IsZCmpNever				= ((pCaps->ZCmpCaps & D3DPCMPCAPS_NEVER) != 0);
	pDevInfo->IsZCmpNotEqual			= ((pCaps->ZCmpCaps & D3DPCMPCAPS_NOTEQUAL) != 0);
	// �A���t�@�u�����h�^�C�v
	pDevInfo->IsSrcBlendFactor			= ((pCaps->SrcBlendCaps & D3DPBLENDCAPS_BLENDFACTOR) != 0);
	pDevInfo->IsSrcBothInvSrc			= ((pCaps->SrcBlendCaps & D3DPBLENDCAPS_BOTHINVSRCALPHA) != 0);
	pDevInfo->IsSrcBothSrc				= ((pCaps->SrcBlendCaps & D3DPBLENDCAPS_BOTHSRCALPHA) != 0);
	pDevInfo->IsSrcDestAlpha			= ((pCaps->SrcBlendCaps & D3DPBLENDCAPS_DESTALPHA) != 0);
	pDevInfo->IsSrcDestColor			= ((pCaps->SrcBlendCaps & D3DPBLENDCAPS_DESTCOLOR) != 0);
	pDevInfo->IsSrcInvDestAlpha			= ((pCaps->SrcBlendCaps & D3DPBLENDCAPS_INVDESTALPHA) != 0);
	pDevInfo->IsSrcInvDestColor			= ((pCaps->SrcBlendCaps & D3DPBLENDCAPS_INVDESTCOLOR) != 0);
	pDevInfo->IsSrcInvSrcAlpha			= ((pCaps->SrcBlendCaps & D3DPBLENDCAPS_INVSRCALPHA) != 0);
	pDevInfo->IsSrcInvSrcColor			= ((pCaps->SrcBlendCaps & D3DPBLENDCAPS_INVSRCCOLOR) != 0);
	pDevInfo->IsSrcOne					= ((pCaps->SrcBlendCaps & D3DPBLENDCAPS_ONE) != 0);
	pDevInfo->IsSrcSrcAlpha				= ((pCaps->SrcBlendCaps & D3DPBLENDCAPS_SRCALPHA) != 0);
	pDevInfo->IsSrcSrcAphaSat			= ((pCaps->SrcBlendCaps & D3DPBLENDCAPS_SRCALPHASAT) != 0);
	pDevInfo->IsSrcSrcColor				= ((pCaps->SrcBlendCaps & D3DPBLENDCAPS_SRCCOLOR) != 0);
	pDevInfo->IsSrcZero					= ((pCaps->SrcBlendCaps & D3DPBLENDCAPS_ZERO) != 0);
	// �A���t�@�u�����h�^�C	�v
	pDevInfo->IsDstBlendFactor			= ((pCaps->DestBlendCaps & D3DPBLENDCAPS_BLENDFACTOR) != 0);
	pDevInfo->IsDstBothInvSrc			= ((pCaps->DestBlendCaps & D3DPBLENDCAPS_BOTHINVSRCALPHA) != 0);
	pDevInfo->IsDstBothSrc				= ((pCaps->DestBlendCaps & D3DPBLENDCAPS_BOTHSRCALPHA) != 0);
	pDevInfo->IsDstDestAlpha			= ((pCaps->DestBlendCaps & D3DPBLENDCAPS_DESTALPHA) != 0);
	pDevInfo->IsDstDestColor			= ((pCaps->DestBlendCaps & D3DPBLENDCAPS_DESTCOLOR) != 0);
	pDevInfo->IsDstInvDestAlpha			= ((pCaps->DestBlendCaps & D3DPBLENDCAPS_INVDESTALPHA) != 0);
	pDevInfo->IsDstInvDestColor			= ((pCaps->DestBlendCaps & D3DPBLENDCAPS_INVDESTCOLOR) != 0);
	pDevInfo->IsDstInvSrcAlpha			= ((pCaps->DestBlendCaps & D3DPBLENDCAPS_INVSRCALPHA) != 0);
	pDevInfo->IsDstInvSrcColor			= ((pCaps->DestBlendCaps & D3DPBLENDCAPS_INVSRCCOLOR) != 0);
	pDevInfo->IsDstOne					= ((pCaps->DestBlendCaps & D3DPBLENDCAPS_ONE) != 0);
	pDevInfo->IsDstSrcAlpha				= ((pCaps->DestBlendCaps & D3DPBLENDCAPS_SRCALPHA) != 0);
	pDevInfo->IsDstSrcAphaSat			= ((pCaps->DestBlendCaps & D3DPBLENDCAPS_SRCALPHASAT) != 0);
	pDevInfo->IsDstSrcColor				= ((pCaps->DestBlendCaps & D3DPBLENDCAPS_SRCCOLOR) != 0);
	pDevInfo->IsDstZero					= ((pCaps->DestBlendCaps & D3DPBLENDCAPS_ZERO) != 0);
	// �e�N�X�`��
	pDevInfo->IsCubeTexture				= ((pCaps->TextureCaps & D3DPTEXTURECAPS_CUBEMAP) != 0);
	pDevInfo->IsMipmapTexture			= ((pCaps->TextureCaps & D3DPTEXTURECAPS_MIPMAP) != 0);
	pDevInfo->IsPerspective				= ((pCaps->TextureCaps & D3DPTEXTURECAPS_PERSPECTIVE) != 0);
	pDevInfo->IsPow2					= ((pCaps->TextureCaps & D3DPTEXTURECAPS_POW2) != 0);
	pDevInfo->IsPow2Conditional			= ((pCaps->TextureCaps & D3DPTEXTURECAPS_NONPOW2CONDITIONAL) != 0);
	pDevInfo->IsSquareOnly				= ((pCaps->TextureCaps & D3DPTEXTURECAPS_SQUAREONLY) != 0);
	// �e�N�X�`���A�h���V���O
	pDevInfo->IsTextureBorder			= ((pCaps->TextureAddressCaps & D3DPTADDRESSCAPS_BORDER) != 0);
	pDevInfo->IsTxtureClamp				= ((pCaps->TextureAddressCaps & D3DPTADDRESSCAPS_CLAMP) != 0);
	pDevInfo->IsTextureIndependent		= ((pCaps->TextureAddressCaps & D3DPTADDRESSCAPS_INDEPENDENTUV) != 0);
	pDevInfo->IsTextureMirror			= ((pCaps->TextureAddressCaps & D3DPTADDRESSCAPS_MIRROR) != 0);
	pDevInfo->IsTextureMirrorRonce		= ((pCaps->TextureAddressCaps & D3DPTADDRESSCAPS_MIRRORONCE) != 0);
	pDevInfo->IsTextureWrap				= ((pCaps->TextureAddressCaps & D3DPTADDRESSCAPS_WRAP) != 0);
	// �e�N�X�`�����
	pDevInfo->MaxTextureWidth			= pCaps->MaxTextureWidth;
	pDevInfo->MaxTextureHeight			= pCaps->MaxTextureHeight;
	pDevInfo->MaxTextureRepeat			= pCaps->MaxTextureRepeat;
	pDevInfo->MaxTextureAspectRatio		= pCaps->MaxTextureAspectRatio;
	pDevInfo->MaxAnisotropy				= pCaps->MaxAnisotropy;
	// �X�e���V��
	pDevInfo->IsStencilKeep				= ((pCaps->StencilCaps & D3DSTENCILCAPS_KEEP) != 0);
	pDevInfo->IsStencilZero				= ((pCaps->StencilCaps & D3DSTENCILCAPS_ZERO) != 0);
	pDevInfo->IsStencilReplace			= ((pCaps->StencilCaps & D3DSTENCILCAPS_REPLACE) != 0);
	pDevInfo->IsStencilIncRsat			= ((pCaps->StencilCaps & D3DSTENCILCAPS_INCRSAT) != 0); 
	pDevInfo->IsStencilDecRsat			= ((pCaps->StencilCaps & D3DSTENCILCAPS_DECRSAT) != 0); 
	pDevInfo->IsStencilInvert			= ((pCaps->StencilCaps & D3DSTENCILCAPS_INVERT) != 0);
	pDevInfo->IsStencilIncR				= ((pCaps->StencilCaps & D3DSTENCILCAPS_INCR) != 0);
	pDevInfo->IsStencilDecR				= ((pCaps->StencilCaps & D3DSTENCILCAPS_DECR) != 0);
	pDevInfo->IsStencilTwoSided			= ((pCaps->StencilCaps & D3DSTENCILCAPS_TWOSIDED) != 0);
	// ��
	pDevInfo->MaxVertexW				= pCaps->MaxVertexW;
	pDevInfo->GuardBandLeft				= pCaps->GuardBandLeft;
	pDevInfo->GuardBandTop				= pCaps->GuardBandTop;
	pDevInfo->GuardBandRight			= pCaps->GuardBandRight;
	pDevInfo->GuardBandBottom			= pCaps->GuardBandBottom;
	pDevInfo->MaxPointSize				= pCaps->MaxPointSize;
	pDevInfo->MaxPrimitiveCount			= pCaps->MaxPrimitiveCount;
	pDevInfo->MaxVertexIndex			= pCaps->MaxVertexIndex;
	pDevInfo->MaxMaxAnisotropy			= pCaps->MaxAnisotropy;
	// �e�N�X�`��
	pDevInfo->MaxTextureBlendStages		= pCaps->MaxTextureBlendStages;
	pDevInfo->MaxSimultaneousTextures	= pCaps->MaxSimultaneousTextures;
	// ���C�g
	pDevInfo->MaxActiveLights			= pCaps->MaxActiveLights;
	// �{�[������
	pDevInfo->MaxVertexBlendMatrices	= pCaps->MaxVertexBlendMatrices;
	pDevInfo->MaxVertexBlendMatrixIndex	= pCaps->MaxVertexBlendMatrixIndex;
	// �V�F�[�_�[
	pDevInfo->VertexShaderVersion		= pCaps->VertexShaderVersion;
	pDevInfo->PixelShaderVersion		= pCaps->PixelShaderVersion;
	pDevInfo->MaxVertexShaderConst		= pCaps->MaxVertexShaderConst;
	pDevInfo->DynamicFlowControlDepth	= pCaps->VS20Caps.DynamicFlowControlDepth;
	pDevInfo->StaticFlowControlDepth	= pCaps->VS20Caps.StaticFlowControlDepth;
}

//=============================================================================
/**
	�R�c�֌W�̃f�o�C�X���N�����܂��B

	@param hWindow		[in] �E�B���h�E�n���h��
	@param IsWindow		[in] �E�B���h�E���[�h�̎��� true ���w��

	@retval true		����
	@retval false		���s
*/
//=============================================================================
Bool Luna3D::Start( HWND hWindow, Bool IsWindow )
{
	HRESULT hr = E_FAIL;

	Luna::LogoutMainCategory( "Luna3D�N���X�̋N��" );
	Luna::LogoutNextLine();

	//-----------------------------------------------------------
	// ��������f�o�C�X�^�C�v�̐ݒ�
	//-----------------------------------------------------------
	Sint32 DeviceNo = Luna3D::GetDeviceTypeNo();

	//-----------------------------------------------------------
	// �f�o�C�X�����p�p�����[�^�[�̐ݒ�
	//-----------------------------------------------------------
	m_PresentParams[0] = MakePresentParameters( hWindow, true, false );
	m_PresentParams[1] = MakePresentParameters( hWindow, false, m_IsFullColor );

	D3DPRESENT_PARAMETERS PresentParam = m_PresentParams[IsWindow ? 0 : 1];

	//-----------------------------------------------------------
	// �R�c�f�o�C�X�̐���
	//-----------------------------------------------------------
	Luna::LogoutStrong( "�@Direct3D�f�o�C�X�̐���" );
	Luna::LogoutNextLine();

	if ( !CreateDeviceByNVPerfHUD( hWindow, &PresentParam ) )
	{
		do
		{
			// �f�o�C�X����
			hr = m_pDirect3D->CreateDevice(
								D3DADAPTER_DEFAULT,
								DeviceType[DeviceNo],
								hWindow,
								CreateFlag[DeviceNo] | D3DCREATE_MULTITHREADED,
								&PresentParam,
								&m_pDevice );
			if SUCCEEDED( hr ) break;
		}
		while ( ++DeviceNo < 5 );

		// �f�o�C�X�����I��
		switch ( DeviceNo )
		{
		case 0:
			Luna::Logout( "�@�@�@Direct3D�f�o�C�X�� [ D3DDEVTYPE_HAL ] [ D3DCREATE_MIXED_VERTEXPROCESSING ] �Ő���" );
			Luna::LogoutNextLine();
			break;
		case 1:
			Luna::Logout( "�@�@�@Direct3D�f�o�C�X�� [ D3DDEVTYPE_HAL ] [ D3DCREATE_SOFTWARE_VERTEXPROCESSING ] �Ő���" );
			Luna::LogoutNextLine();
			break;
		case 2:
			Luna::Logout( "�@�@�@Direct3D�f�o�C�X�� [ D3DDEVTYPE_REF ] [ D3DCREATE_SOFTWARE_VERTEXPROCESSING ] �Ő���" );
			Luna::LogoutNextLine();
			break;
		default:
			Luna::LogoutError( "�@�@�@�G���[�F�f�o�C�X�̍쐬�Ɏ��s [ %s ]", Luna3D::GetError(hr) );
			Luna::LogoutNextLine();
			Luna::LogoutError( "�@�@�@�@�@�@�FDirectX���̃G���[�Ŗ����ꍇ�͑��̃\�t�g���r�f�I�J�[�h���L���Ă�\��������܂��B" );
			Luna::LogoutNextLine();
			return false;
		}
	}

	//-----------------------------------------------------------
	// VRAM
	//-----------------------------------------------------------
	Luna::LogoutStrong( "�@����c�e�N�X�`���������e�� <%4dMB>", Luna3D::GetRestVRAM() );
	Luna::LogoutNextLine();

	//-----------------------------------------------------------
	// IDirect3DQuery9�C���^�[�t�F�[�X���擾
	//-----------------------------------------------------------
	// �C�x���g�擾�p
	hr = m_pDevice->CreateQuery( D3DQUERYTYPE_EVENT, &m_pQuery[0] );
	if FAILED( hr )
	{
		Luna::LogoutError( "�@�@�@�G���[�FIDirect3DQuery9�C���^�[�t�F�[�X�̎擾�Ɏ��s [ %s ]", Luna3D::GetError(hr) );
		Luna::LogoutNextLine();
	}

	// �s�N�Z���t�B�����[�g�擾�p
	hr = m_pDevice->CreateQuery( D3DQUERYTYPE_OCCLUSION, &m_pQuery[1] );
	if FAILED( hr )
	{
		Luna::LogoutError( "�@�@�@�G���[�FIDirect3DQuery9�C���^�[�t�F�[�X�̎擾�Ɏ��s [ %s ]", Luna3D::GetError(hr) );
		Luna::LogoutNextLine();
	}

	//-----------------------------------------------------------
	// �����_�����O�^�[�Q�b�g�擾
	//-----------------------------------------------------------
	m_pDevice->GetRenderTarget( 0, &m_pRenderTarget );

	//-----------------------------------------------------------
	// �f�o�C�X�ݒ�
	//-----------------------------------------------------------
	InitializeDeviceSetteing();
	ResetDeviceSetteing();

	//-----------------------------------------------------------
	// ���݂̃f�o�C�X�̐��\���擾
	//-----------------------------------------------------------
	D3DCAPS9 Caps;
	m_pDevice->GetDeviceCaps( &Caps );
	GetDeviceCaps( &Caps, &m_DeviceInfo );

	Luna::LogoutStrong( "�@���݂̃f�o�C�X�����擾" );
	Luna::LogoutNextLine();

	Luna::Logout( "�@�@�@�|�C���g�T�C�Y [ %.3lf ]", m_DeviceInfo.MaxPointSize );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�ő�v���~�e�B�u�� [ %u ]", m_DeviceInfo.MaxPrimitiveCount );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�ő�C���f�b�N�X�� [ %u ]", m_DeviceInfo.MaxVertexIndex );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�ő�e�N�X�`���X�e�[�W�� [ %u ]", m_DeviceInfo.MaxTextureBlendStages );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�ő�}���`�e�N�X�`���� [ %u ]", m_DeviceInfo.MaxSimultaneousTextures );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�ő�n�[�h�E�F�A���C�g�� [ %u ]", m_DeviceInfo.MaxActiveLights );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�ő�u�����h�}�g���b�N�X�� [ %u ]", m_DeviceInfo.MaxVertexBlendMatrices );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�ő�u�����h�C���f�b�N�X�� [ %u ]", m_DeviceInfo.MaxVertexBlendMatrixIndex );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�ő咸�_�V�F�[�_�[�萔�� [ %u ]", m_DeviceInfo.MaxVertexShaderConst );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@���_�V�F�[�_�[�o�[�W���� [ %u.%u ]", D3DSHADER_VERSION_MAJOR(m_DeviceInfo.VertexShaderVersion), D3DSHADER_VERSION_MINOR(m_DeviceInfo.VertexShaderVersion) );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�s�N�Z���V�F�[�_�[�o�[�W����[ %u.%u ]", D3DSHADER_VERSION_MAJOR(m_DeviceInfo.PixelShaderVersion), D3DSHADER_VERSION_MINOR(m_DeviceInfo.PixelShaderVersion) );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@���I�t���[���䖽�߂̃l�X�e�B���O [ %u ]", m_DeviceInfo.DynamicFlowControlDepth );
	Luna::LogoutNextLine();
	Luna::Logout( "�@�@�@�ÓI�t���[���䖽�߂̃l�X�e�B���O [ %u ]", m_DeviceInfo.StaticFlowControlDepth );
	Luna::LogoutNextLine();

	Luna::LogoutNextLine();

	return true;
}

//=============================================================================
/**
	�f�o�C�X�ݒ�̏����������܂�

*/
//=============================================================================
Bool Luna3D::CreateDeviceByNVPerfHUD( HWND hWindow, D3DPRESENT_PARAMETERS *pPresentParam )
{
	if ( m_IsNVPerfHUD )
	{
		for ( Uint32 Adapter = 0; Adapter < m_pDirect3D->GetAdapterCount(); Adapter++ )
		{
			D3DADAPTER_IDENTIFIER9 Identifier;
			
			m_pDirect3D->GetAdapterIdentifier( Adapter, 0, &Identifier );
			if ( !strcmp( Identifier.Description, "NVIDIA NVPerfHUD" ) )
			{
				HRESULT hr = m_pDirect3D->CreateDevice(
									Adapter,
									D3DDEVTYPE_REF,
									hWindow,
									D3DCREATE_MIXED_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
									pPresentParam,
									&m_pDevice );
				if SUCCEEDED( hr )
				{
					Luna::Logout( "�@�@�@Direct3D�f�o�C�X�� [ NVPerfHUD�p ] �Ő���" );
					Luna::LogoutNextLine();

					return true;
				}
			}
		}
	}

	return false;
}

//=============================================================================
/**
	�f�o�C�X�ݒ�̏����������܂�

*/
//=============================================================================
void Luna3D::InitializeDeviceSetteing( void )
{
	Sint32 Width, Height;
	Luna::GetScreenData( &Width, &Height, NULL );
	// �r���[�|�[�g�����l
	m_Viewport.X			= 0;
	m_Viewport.Y			= 0;
	m_Viewport.Width		= Width;
	m_Viewport.Height		= Height;
    m_Viewport.MinZ			= 0.0000000000000000000000001f;
	m_Viewport.MaxZ			= 1.0000000000000000000000000f;

	// �e�T�[�t�F�C�X
	m_lTexTarget			= INVALID_TEXTURE;
	m_lSurfTarget			= INVALID_SURFACE;
	m_lSurfDepthStencil		= INVALID_SURFACE;
	m_lCamera				= INVALID_CAMERA;

	// �����_�[�X�e�[�g
	MemoryFill( m_RenderState, 0xFF, sizeof(m_RenderState) );
	for ( Uint32 i = 0; i < RenderStateTblCount; i++ )
	{
		m_pDevice->GetRenderState( RenderStateTbl[i], &m_RenderState[RenderStateTbl[i]] );
	}

	// �e�N�X�`���X�e�[�g
	MemoryFill( m_TextureState, 0xFF, sizeof(m_TextureState) );
	for ( Uint32 i = 0; i < TEXTURE_STAGE_MAX; i++ )
	{
		for ( Uint32 j = 0; j < TextureStateTblCount; j++ )
		{
			m_pDevice->GetTextureStageState( i, TextureStateTbl[j], &m_TextureState[i][TextureStateTbl[j]] );
		}
	}

	// �T���v���[�X�e�[�g
	MemoryFill( m_SamplerState, 0xFF, sizeof(m_SamplerState) );
	for ( Uint32 i = 0; i < TEXTURE_STAGE_MAX; i++ )
	{
		for ( Uint32 j = 0; j < SamplerStateTblCount; j++ )
		{
			m_pDevice->GetSamplerState( i, SamplerStateTbl[j], &m_SamplerState[i][SamplerStateTbl[j]] );
		}
	}

	//�@�����_�����O�X�e�[�g
	Luna3D::SetRenderState( D3DRS_LIGHTING, false );
	Luna3D::SetRenderState( D3DRS_ZENABLE, false );
	Luna3D::SetRenderState( D3DRS_ZWRITEENABLE, false );
	Luna3D::SetRenderState( D3DRS_ALPHABLENDENABLE, true );
	Luna3D::SetRenderState( D3DRS_ALPHATESTENABLE, false );
	Luna3D::SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );

	for ( Sint32 i = 0; i < TEXTURE_STAGE_MAX; i++ )
	{
		// �T���v���[�X�e�[�g
		Luna3D::SetSamplerState( i, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP );
		Luna3D::SetSamplerState( i, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP );
		Luna3D::SetSamplerState( i, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR );
		Luna3D::SetSamplerState( i, D3DSAMP_MINFILTER, D3DTEXF_LINEAR );
		Luna3D::SetSamplerState( i, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR );
		Luna3D::SetSamplerState( i, D3DSAMP_MAXANISOTROPY, m_DeviceInfo.MaxAnisotropy );

		// �e�N�X�`���X�e�[�g
		Luna3D::SetTextureState( i, D3DTSS_COLOROP, (i==0)?(D3DTOP_MODULATE):(D3DTOP_DISABLE) );
		Luna3D::SetTextureState( i, D3DTSS_COLORARG1, D3DTA_TEXTURE );
		Luna3D::SetTextureState( i, D3DTSS_COLORARG2, D3DTA_CURRENT );

		Luna3D::SetTextureState( i, D3DTSS_ALPHAOP, (i==0)?(D3DTOP_MODULATE):(D3DTOP_DISABLE) );
		Luna3D::SetTextureState( i, D3DTSS_ALPHAARG1, D3DTA_TEXTURE );
		Luna3D::SetTextureState( i, D3DTSS_ALPHAARG2, D3DTA_CURRENT );
	}

	// �}�e���A���p�f�t�H���g����
	for ( Uint32 i = 0; i < TEXTURE_STAGE_MAX; i++ )
	{
		for ( Uint32 j = 0; j < TextureStateTblCount; j++ )
		{
			m_DefaultState.TextureState[i][TextureStateTbl[j]] = m_TextureState[i][TextureStateTbl[j]];
		}

		for ( Uint32 j = 0; j < SamplerStateTblCount; j++ )
		{
			m_DefaultState.SamplerState[i][SamplerStateTbl[j]] = m_SamplerState[i][SamplerStateTbl[j]];
		}
	}

	m_DefaultState.BlendType	= BLEND_NONE;
	m_DefaultState.IsColorKey	= true;
	m_DefaultState.IsBilinear	= true;
	m_DefaultState.IsZBuffer	= true;
	m_DefaultState.IsZWrite		= true;
}

//=============================================================================
/**
	�f�o�C�X�ݒ�̏����������܂�

*/
//=============================================================================
void Luna3D::ResetDeviceSetteing( void )
{
	//------------------------------------------------------------------
	// �r���[�|�[�g��ݒ�
	//------------------------------------------------------------------
	m_pDevice->SetViewport( &m_Viewport );

	//------------------------------------------------------------------
	// �����_�����O�^�[�Q�b�g�e�N�X�`��
	//------------------------------------------------------------------
	if ( m_lTexTarget != NULL )
	{
		((CTexture*)m_lTexTarget)->SetRenderTarget();
	}

	//------------------------------------------------------------------
	// �����_�����O�^�[�Q�b�g�T�[�t�F�C�X
	//------------------------------------------------------------------
	if ( m_lSurfTarget != NULL )
	{
		((CSurface*)m_lSurfTarget)->SetRenderTarget();
	}

	//------------------------------------------------------------------
	// �[�x�X�e���V���T�[�t�F�C�X
	//------------------------------------------------------------------
	if ( m_lSurfDepthStencil != NULL )
	{
		((CSurface*)m_lSurfDepthStencil)->SetDepthStencil();
	}

	//------------------------------------------------------------------
	// �J����
	//------------------------------------------------------------------
	if ( m_lCamera != INVALID_CAMERA )
	{
		LunaCamera::SetDevice( m_lCamera );
	}

	//------------------------------------------------------------------
	// �����_�����O�X�e�[�g
	//------------------------------------------------------------------
	for ( Uint32 i = 0; i < RenderStateTblCount; i++ )
	{
		m_pDevice->SetRenderState( RenderStateTbl[i], m_RenderState[RenderStateTbl[i]] );
	}

	//------------------------------------------------------------------
	// �e�N�X�`���[�X�e�[�g
	//------------------------------------------------------------------
	for ( Uint32 i = 0; i < TEXTURE_STAGE_MAX; i++ )
	{
		for ( Uint32 j = 0; j < TextureStateTblCount; j++ )
		{
			m_pDevice->SetTextureStageState( i, TextureStateTbl[j], m_TextureState[i][TextureStateTbl[j]] );
		}
	}

	//------------------------------------------------------------------
	// �T���v���[�X�e�[�g
	//------------------------------------------------------------------
	for ( Uint32 i = 0; i < TEXTURE_STAGE_MAX; i++ )
	{
		for ( Uint32 j = 0; j < SamplerStateTblCount; j++ )
		{
			m_pDevice->SetSamplerState( i, SamplerStateTbl[j], m_SamplerState[i][SamplerStateTbl[j]] );
		}
	}

	//------------------------------------------------------------------
	// �o�b�N�o�b�t�@�N���A
	//------------------------------------------------------------------
	Luna3D::Clear( D3DCLEAR_TARGET );
}

//=============================================================================
/**
	�G�~�����[�V�������[�h�ŋN������悤�ɂ��܂��B

*/
//=============================================================================
void Luna3D::EnableEmulationMode( void )
{
	m_IsEmulationMode = true;
}

//=============================================================================
/**
	�G�~�����[�V�������[�h���g�p����悤�ɂ��܂��B

*/
//=============================================================================
void Luna3D::EnableFullColorMode( void )
{
	m_IsFullColor = true;
}

//=============================================================================
/**
	��ʂ̍X�V���ɐ��������X������悤�ɂȂ�܂��B

*/
//=============================================================================
void Luna3D::EnableWaitVBlank( void )
{
	m_IsWaitBlank = true;
}

//=============================================================================
/**
	��ʂ̍X�V���ɐ��������X������悤�ɂȂ�܂��B

*/
//=============================================================================
void Luna3D::EnableNVPerfHUD( void )
{
	m_IsNVPerfHUD = true;
}

//=============================================================================
/**
	��������f�o�C�X�̃^�C�v�ԍ����擾���܂��B

	@retval 0		PureDevice
	@retval 1		Hardware & Spftware TnL
	@retval 2		Hardware & Spftware TnL
	@retval 3		Software TnL
	@retval 4		Reference Rasterizer
*/
//=============================================================================
Sint32 Luna3D::GetDeviceTypeNo( void )
{
	Sint32 No = 2;		// REF

	// �����G�~�����[�V�������[�h�H
	if ( m_IsEmulationMode ) return No;

	// �n�[�h�E�F�A���X�^���C�Y�T�|�[�g�H
	if ( !m_DeviceInfo.IsSoftwareTnL ) return No;

	No--;

	// �n�[�h�E�F�A�s���k�T�|�[�g�H
	if ( !m_DeviceInfo.IsHardwareTnL ) return No;

	No--;

	return No;
}


//=============================================================================
/**
	�g�p����v���[���e�[�V�����p�����[�^�[���擾���܂��B

	@param hWnd				[in] �E�B���h�E�n���h��
	@param IsWindow			[in] true �̎� �E�B���h�E���[�h / false �̎� �t���X�N���[�����[�h
	@param IsFullColor		[in] true �̎� 32Bit���[�h / false �̎� 16Bit���[�h

	@return			�������ꂽ�v���[���e�[�V�����p�����[�^�[�\����
*/
//=============================================================================
D3DPRESENT_PARAMETERS Luna3D::MakePresentParameters( HWND hWnd, Bool IsWindow, Bool IsFullColor )
{
	Sint32 Width, Height;
	D3DPRESENT_PARAMETERS PresentParam;
	D3DFORMAT DepthFormat = D3DFMT_UNKNOWN;
	D3DFORMAT ScreenFormat = IsWindow ? m_WindowMode.Format : m_FullScreenMode[IsFullColor ? 1 : 0].Format;

	//-----------------------------------------------------------
	// ��ʃT�C�Y�擾
	//-----------------------------------------------------------
	Luna::GetScreenData( &Width, &Height, NULL );

	//-----------------------------------------------------------
	// �L���ȃt�H�[�}�b�g�擾
	//-----------------------------------------------------------
	for ( Sint32 i = 0; i < 8; i++ )
	{
		if ( BackBufferFormats[i] == ScreenFormat )
		{
			DepthFormat = m_AdapterData.DepthFormats[0];
		}
	}

	//-----------------------------------------------------------
	// �p�����[�^�[����
	//-----------------------------------------------------------
	PresentParam.BackBufferWidth			= Width;
	PresentParam.BackBufferHeight			= Height;
	PresentParam.BackBufferFormat			= ScreenFormat;
	PresentParam.BackBufferCount			= 1;
	PresentParam.MultiSampleType			= m_MultiSampleType;
	PresentParam.MultiSampleQuality			= m_MultiSampleQuality;
	PresentParam.SwapEffect					= D3DSWAPEFFECT_DISCARD;
	PresentParam.hDeviceWindow				= hWnd;
	PresentParam.Windowed					= IsWindow;
	PresentParam.EnableAutoDepthStencil		= false;
	PresentParam.AutoDepthStencilFormat		= DepthFormat;
	PresentParam.Flags						= D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;
	PresentParam.FullScreen_RefreshRateInHz	= D3DPRESENT_RATE_DEFAULT;
	PresentParam.PresentationInterval		= m_IsWaitBlank ? D3DPRESENT_INTERVAL_ONE : D3DPRESENT_INTERVAL_IMMEDIATE;

	return PresentParam;
}

//=============================================================================
/**
	�R�c�f�o�C�X�̃��Z�b�g�����܂��B

	@param IsChange		[in] true �̎��A��ʃ��[�h��؂�ւ��܂�
*/
//=============================================================================
void Luna3D::ResetDevice( Bool IsChange )
{
	HRESULT hr;

	//-------------------------------------------------------
	// �f�o�C�X���܂���������Ă��Ȃ��ꍇ�͏I��
	//-------------------------------------------------------
	if ( m_pDevice == NULL ) return;

	//-------------------------------------------------------
	// �X�N���[�����[�h�̕ύX�łȂ����A�f�o�C�X�����Ȃ��Ȃ�I��
	//-------------------------------------------------------
	if ( !IsChange && (m_pDevice->TestCooperativeLevel() == D3D_OK) ) return;

	//-------------------------------------------------------
	// �v���[���e�[�V�����p�����[�^�擾
	//-------------------------------------------------------
	Sint32 Width, Height;
	Bool IsWindow;
	Luna::GetScreenData( &Width, &Height, &IsWindow );
	m_PresentParams[0].BackBufferWidth		= Width;
	m_PresentParams[0].BackBufferHeight	= Height;
	m_PresentParams[1].BackBufferWidth		= Width;
	m_PresentParams[1].BackBufferHeight	= Height;

	D3DPRESENT_PARAMETERS PresentParam = m_PresentParams[IsWindow ? 0 : 1];

	//-------------------------------------------------------
	// �r�f�I���������̃��\�[�X�S���
	//-------------------------------------------------------
	LunaTexture::Reset();
	LunaVMR9::Reset();
	LunaSurface::Reset();
	LunaSprite::Reset();
	LunaSprite3D::Reset();
	LunaPrimitive::Reset();
	LunaPrimitive3D::Reset();
	LunaLine::Reset();
	LunaLine3D::Reset();
	LunaPoint::Reset();
	LunaPoint3D::Reset();
	LunaModel::Reset();
	LunaModelEx::Reset();
	LunaField::Reset();
	LunaSimple::Reset();
	LunaShaderFx::Reset();

	SAFE_RELEASE( m_pQuery[0] );
	SAFE_RELEASE( m_pQuery[1] );
	SAFE_RELEASE( m_pRenderTarget );

	if ( m_pCallbackReset != NULL )
	{
		m_pCallbackReset();
	}

	//-------------------------------------------------------
	// �f�o�C�X�̃��Z�b�g
	//-------------------------------------------------------
	if FAILED( m_pDevice->Reset( &PresentParam ) )
	{
		Luna::MsgBox( MB_ICONERROR, "ERROR", "�f�o�C�X�̕��A�Ɏ��s" );
	}

	m_pDevice->GetRenderTarget( 0, &m_pRenderTarget );

	//-------------------------------------------------------
	// IDirect3DQuery9�C���^�[�t�F�[�X���擾
	//-------------------------------------------------------
	// �C�x���g�擾�p
	hr = m_pDevice->CreateQuery( D3DQUERYTYPE_EVENT, &m_pQuery[0] );
	if FAILED( hr )
	{
		Luna::LogoutError( "�@�@�@�G���[�FIDirect3DQuery9�C���^�[�t�F�[�X�̎擾�Ɏ��s [ %s ]", Luna3D::GetError(hr) );
		Luna::LogoutNextLine();
	}

	// �s�N�Z���t�B�����[�g�擾�p
	hr = m_pDevice->CreateQuery( D3DQUERYTYPE_OCCLUSION, &m_pQuery[1] );
	if FAILED( hr )
	{
		Luna::LogoutError( "�@�@�@�G���[�FIDirect3DQuery9�C���^�[�t�F�[�X�̎擾�Ɏ��s [ %s ]", Luna3D::GetError(hr) );
		Luna::LogoutNextLine();
	}

	m_IsCheckingFillRate = false;

	//-------------------------------------------------------
	// �r�f�I���������̃��\�[�X�S����
	//-------------------------------------------------------
	LunaTexture::Restore();
	LunaVMR9::Restore();
	LunaSurface::Restore();
	LunaSprite::Restore();
	LunaSprite3D::Restore();
	LunaPrimitive::Restore();
	LunaPrimitive3D::Restore();
	LunaLine::Restore();
	LunaLine3D::Restore();
	LunaPoint::Restore();
	LunaPoint3D::Restore();
	LunaModel::Restore();
	LunaModelEx::Restore();
	LunaField::Restore();
	LunaSimple::Restore();
	LunaShaderFx::Restore();

	if ( m_pCallbackRestore != NULL )
	{
		m_pCallbackRestore();
	}

	//-------------------------------------------------------
	// �f�o�C�X�̐ݒ�𕜋A
	//-------------------------------------------------------
	Luna3D::ResetDeviceSetteing();
}

//=============================================================================
/*
	�f�o�C�X���X�g���̃f�[�^���Z�b�g�p�R�[���o�b�N�֐��ݒ�

	@param pCallback		[in] �R�[���o�b�N�֐�

*/
//=============================================================================
void Luna3D::SetCallbackDeviceReset( void (*pCallback)( void ) )
{
	m_pCallbackReset = pCallback;
}

//=============================================================================
/*
	�f�o�C�X���X�g���̃f�[�^���X�g�A�p�R�[���o�b�N�֐��ݒ�

	@param pCallback		[in] �R�[���o�b�N�֐�

*/
//=============================================================================
void Luna3D::SetCallbackDeviceRestore( void (*pCallback)( void ) )
{
	m_pCallbackRestore = pCallback;
}

//=============================================================================
/*
	�g�p����R�c�f�o�C�X�̃f�o�C�X�����擾���܂��B

	@param pInfo		[in] �f�o�C�X���i�[��A�h���X

*/
//=============================================================================
void Luna3D::GetDeviceInformation( DEVICEINFORMATION *pInfo )
{
	MemoryCopy( pInfo, &m_DeviceInfo, sizeof(DEVICEINFORMATION) );
}

//=============================================================================
/**
	�g�p���Ă���R�c�f�o�C�X���擾���܂��B

	@return		�R�c�f�o�C�X�I�u�W�F�N�g
*/
//=============================================================================
HMONITOR Luna3D::GetAdapterMonitor( void )
{
	return m_pDirect3D->GetAdapterMonitor( D3DADAPTER_DEFAULT );
}

//=============================================================================
/**
	�g�p���Ă���R�c�f�o�C�X���擾���܂��B

	@return		�R�c�f�o�C�X�I�u�W�F�N�g
*/
//=============================================================================
IDirect3DDevice9 *Luna3D::GetDevice( void )
{
	return m_pDevice;
}

//=============================================================================
/**
	�s�N�Z���V�F�[�_�[�̃T�|�[�g�`�F�b�N�����܂�

	@param Major		[in] ���W���[�o�[�W����
	@param Minor		[in] �}�C�i�[�o�[�W����

	@retval true		�T�|�[�g���Ă���
	@retval false		�T�|�[�g���Ă��Ȃ�
*/
//=============================================================================
Bool Luna3D::CheckPixelShaderSupport( Uint16 Major, Uint16 Minor )
{
	return (D3DPS_VERSION(Major,Minor) <= m_DeviceInfo.PixelShaderVersion);
}

//=============================================================================
/**
	�g�p���钸�_�V�F�[�_�[�̍ō��o�[�W������ݒ�

	@param Major		[in] ���W���[�o�[�W����
	@param Minor		[in] �}�C�i�[�o�[�W����

*/
//=============================================================================
void Luna3D::SetMaxVertexShaderViersion( Uint16 Major, Uint16 Minor )
{
	m_MaxVertexShaderVersion = D3DVS_VERSION(Major,Minor);
}

//=============================================================================
/**
	���_�V�F�[�_�[�̃T�|�[�g�`�F�b�N�����܂�

	@param Major		[in] ���W���[�o�[�W����
	@param Minor		[in] �}�C�i�[�o�[�W����

	@retval true		�T�|�[�g���Ă���
	@retval false		�T�|�[�g���Ă��Ȃ�
*/
//=============================================================================
void Luna3D::SetVertexProccessing( Uint16 Major, Uint16 Minor )
{
	if ( m_IsEmulationMode )
	{
		m_pDevice->SetSoftwareVertexProcessing( true );
	}
	else
	{
		if ( GetVertexProccessing( Major, Minor ) )
		{
			m_pDevice->SetSoftwareVertexProcessing( true );
		}
		else
		{
			m_pDevice->SetSoftwareVertexProcessing( false );
		}
	}
}

//=============================================================================
/**
	���_�����^�C�v���擾���܂�

	@param Major		[in] ���_�V�F�[�_�[�̃��W���[�o�[�W����
	@param Minor		[in] ���_�V�F�[�_�[�̃}�C�i�[�o�[�W����

	@retval true		�n�[�h�E�F�A�s���k�ŏ��������
	@retval false		�\�t�g�E�F�A�s���k�ŏ��������
*/
//=============================================================================
Bool Luna3D::GetVertexProccessing( Uint16 Major, Uint16 Minor )
{
	if ( m_DeviceInfo.IsHardwareTnL )
	{
		if ( D3DVS_VERSION(Major,Minor) <= m_DeviceInfo.VertexShaderVersion )
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return true;
	}
}


//=============================================================================
/**
	�����~�b�v�}�b�v�������T�|�[�g���Ă��邩�𒲂ׂ܂��B

	@param Format	[in] ���ׂ�T�[�t�F�C�X�t�H�[�}�b�g
	@param IsMipmap	[in] �~�b�v�}�b�v���g�p���邩�ۂ�

	@return �T�|�[�g����true
*/
//=============================================================================
Bool Luna3D::GetAutoGenerateMipmapEnable( D3DFORMAT Format, Bool IsMipmap )
{
	if ( IsMipmap )
	{
		for ( Sint32 i = 0; i < m_AdapterData.TextureCount; i++ )
		{
			if ( m_AdapterData.TextureFormats[i] == Format )
			{
				if ( m_AdapterData.TextureMipmap[i] )
				{
					return true;
				}
			}
		}
	}

	return false;
}


//=============================================================================
/**
	�����_�����O�Ɏg�p����r���[�|�[�g��ݒ肵�܂�

	@param pRect	[in] �r���[�|�[�g��`�\���̂ւ̃|�C���^
*/
//=============================================================================
void Luna3D::SetViewport( RECT *pRect )
{
	RECT Rect = { 0, 0, 0, 0 };
	if ( pRect == NULL )
	{
		pRect = &Rect;
		Luna::GetScreenData( &Rect.right, &Rect.bottom, NULL );
	}

	m_Viewport.X		= pRect->left;
	m_Viewport.Y		= pRect->top;
	m_Viewport.Width	= pRect->right - pRect->left;
	m_Viewport.Height	= pRect->bottom - pRect->top;
	m_Viewport.MinZ		= 0.0f;
	m_Viewport.MaxZ		= 1.0f;

	m_pDevice->SetViewport( &m_Viewport );
}

//=============================================================================
/**
	�����_�����O�Ɏg�p���Ă���r���[�|�[�g���擾���܂�

	@param pRect	[in] �r���[�|�[�g��`�\���̂ւ̃|�C���^
*/
//=============================================================================
void Luna3D::GetViewport( RECT *pRect )
{
	pRect->left   = m_Viewport.X;
	pRect->top    = m_Viewport.Y;
	pRect->right  = m_Viewport.X + m_Viewport.Width;
	pRect->bottom = m_Viewport.Y + m_Viewport.Height;
}

//=============================================================================
/**
	�����_�����O�X�e�[�g���f�o�C�X�ɐݒ肵�܂��B<BR>
	�p�����[�^�[�֌W��DirectX9�̃w���v���Q�Ƃ��Ă��������B

	@param State	[in] �ݒ肷��X�e�[�g�^�C�v
	@param Param	[in] �p�����[�^
*/
//=============================================================================
void Luna3D::SetRenderState( D3DRENDERSTATETYPE State, Uint32 Param )
{
	if ( m_RenderState[State] != Param )
	{
		m_RenderState[State] = Param;
		m_pDevice->SetRenderState( State, Param );
	}
}

//=============================================================================
/**
	�e�N�X�`���X�e�[�g���f�o�C�X�ɐݒ肵�܂�<BR>
	�p�����[�^�[�֌W��DirectX9�̃w���v���Q�Ƃ��Ă��������B

	@param Stage	[in] �ݒ肷��X�e�[�W
	@param State	[in] �ݒ肷��X�e�[�g�^�C�v
	@param Param	[in] �p�����[�^
*/
//=============================================================================
void Luna3D::SetTextureState( Uint32 Stage, D3DTEXTURESTAGESTATETYPE State, Uint32 Param )
{
	if ( (0 <= Stage) && (Stage < TEXTURE_STAGE_MAX) )
	{
		if ( m_TextureState[Stage][State] != Param )
		{
			m_TextureState[Stage][State] = Param;
			m_pDevice->SetTextureStageState( Stage, State, Param );
		}
	}
}

//=============================================================================
/**
	�T���v���[�X�e�[�g���f�o�C�X�ɐݒ肵�܂�<BR>
	�p�����[�^�[�֌W��DirectX9�̃w���v���Q�Ƃ��Ă�������

	@param Stage	[in] �ݒ肷��X�e�[�W
	@param State	[in] �ݒ肷��X�e�[�g�^�C�v
	@param Param	[in] �p�����[�^
*/
//=============================================================================
void Luna3D::SetSamplerState( Uint32 Stage, D3DSAMPLERSTATETYPE State, Uint32 Param )
{
	if ( (0 <= Stage) && (Stage < TEXTURE_STAGE_MAX) )
	{
		if ( m_SamplerState[Stage][State] != Param )
		{
			m_SamplerState[Stage][State] = Param;
			m_pDevice->SetSamplerState( Stage, State, Param );
		}
	}
}

//=============================================================================
/**
	�A���t�@�u�����f�B���O�̃^�C�v��ݒ肵�܂�

	@param BlendType		[in] �ݒ肷��u�����h�^�C�v

*/
//=============================================================================
void Luna3D::SetBlendingType( eBlendType BlendType )
{
	switch ( BlendType )
	{
	case BLEND_NONE:
		Luna3D::SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_ONE );
		Luna3D::SetRenderState( D3DRS_DESTBLEND, D3DBLEND_ZERO );
		break;

	case BLEND_NORMAL:
		Luna3D::SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA );
		Luna3D::SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
		break;

	case BLEND_ADD:
		Luna3D::SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA );
		Luna3D::SetRenderState( D3DRS_DESTBLEND, D3DBLEND_ONE );
		break;

	case BLEND_ADD_NOALPHA:
		Luna3D::SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_ONE );
		Luna3D::SetRenderState( D3DRS_DESTBLEND, D3DBLEND_ONE );
		break;

	case BLEND_MUL:
		Luna3D::SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_ZERO );
		Luna3D::SetRenderState( D3DRS_DESTBLEND, D3DBLEND_SRCCOLOR );
		break;

	case BLEND_REVERSE:
		Luna3D::SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_INVDESTCOLOR );
		Luna3D::SetRenderState( D3DRS_DESTBLEND, D3DBLEND_ZERO );
		break;
	}
}

//=============================================================================
/**
	�o�C���j�A�t�B���^�̂n�m�^�n�e�e�����܂�

	@param Flag		[in] �o�C���j�A�t�B���^���n�m�ɂ���Ȃ� true / �n�e�e�ɂ���Ȃ� false

*/
//=============================================================================
void Luna3D::SetBilinearEnable( Bool Flag )
{
	if ( Flag )
	{
		LunaTexture::SetOffsetUV( 0.5f );
		for ( Sint32 i = 0; i < TEXTURE_STAGE_MAX; i++ )
		{
			if ( m_DeviceInfo.MaxMaxAnisotropy > 0 )
			{
				Luna3D::SetSamplerState( i, D3DSAMP_MAGFILTER, D3DTEXF_ANISOTROPIC );
				Luna3D::SetSamplerState( i, D3DSAMP_MINFILTER, D3DTEXF_ANISOTROPIC );
				Luna3D::SetSamplerState( i, D3DSAMP_MIPFILTER, D3DTEXF_ANISOTROPIC );
				Luna3D::SetSamplerState( i, D3DSAMP_MAXANISOTROPY, m_DeviceInfo.MaxMaxAnisotropy );
			}
			else
			{
				Luna3D::SetSamplerState( i, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR );
				Luna3D::SetSamplerState( i, D3DSAMP_MINFILTER, D3DTEXF_LINEAR );
				Luna3D::SetSamplerState( i, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR );
			}
		}
	}
	else
	{
		LunaTexture::SetOffsetUV( 0.0f );
		for ( Sint32 i = 0; i < TEXTURE_STAGE_MAX; i++ )
		{
			Luna3D::SetSamplerState( i, D3DSAMP_MAGFILTER, D3DTEXF_POINT );
			Luna3D::SetSamplerState( i, D3DSAMP_MINFILTER, D3DTEXF_POINT );
			Luna3D::SetSamplerState( i, D3DSAMP_MIPFILTER, D3DTEXF_POINT );
		}
	}
}

//=============================================================================
/**
	�J���[�L�[�����̂n�m�^�n�e�e�����܂�

	@param Flag		[in] �J���[�L�[���n�m�ɂ���Ȃ� true / �n�e�e�ɂ���Ȃ� false

*/
//=============================================================================
void Luna3D::SetColorkeyEnable( Bool Flag )
{
	if ( Flag )
	{
		Luna3D::SetRenderState( D3DRS_ALPHABLENDENABLE, true );
		Luna3D::SetRenderState( D3DRS_ALPHATESTENABLE, true );
		Luna3D::SetRenderState( D3DRS_ALPHAFUNC, D3DCMP_GREATER );
		Luna3D::SetRenderState( D3DRS_ALPHAREF, 8 );
	}
	else
	{
		Luna3D::SetRenderState( D3DRS_ALPHABLENDENABLE, true );
		Luna3D::SetRenderState( D3DRS_ALPHATESTENABLE, false );
	}
}

//=============================================================================
/**
	�J���[�L�[�����̂n�m�^�n�e�e�����܂�

	@param Flag		[in] �J���[�L�[���n�m�ɂ���Ȃ� true / �n�e�e�ɂ���Ȃ� false

*/
//=============================================================================
void Luna3D::SetZBufferEnable( Bool Flag )
{
	if ( Flag )
	{
		Luna3D::SetRenderState( D3DRS_ZENABLE, D3DZB_TRUE );
	}
	else
	{
		Luna3D::SetRenderState( D3DRS_ZENABLE, D3DZB_FALSE );
	}
}

//=============================================================================
/**
	�J���[�L�[�����̂n�m�^�n�e�e�����܂�

	@param Flag		[in] �J���[�L�[���n�m�ɂ���Ȃ� true / �n�e�e�ɂ���Ȃ� false

*/
//=============================================================================
void Luna3D::SetZWriteEnable( Bool Flag )
{
	if ( Flag )
	{
		Luna3D::SetRenderState( D3DRS_ZWRITEENABLE, true );
	}
	else
	{
		Luna3D::SetRenderState( D3DRS_ZWRITEENABLE, false );
	}
}

//=============================================================================
/**
	�J���[�L�[�����̂n�m�^�n�e�e�����܂�

	@param Flag		[in] �J���[�L�[���n�m�ɂ���Ȃ� true / �n�e�e�ɂ���Ȃ� false

*/
//=============================================================================
void Luna3D::SetWireFrameEnable( Bool Flag )
{
	if ( Flag )
	{
		Luna3D::SetRenderState( D3DRS_FILLMODE, D3DFILL_WIREFRAME );
		Luna3D::SetRenderState( D3DRS_SHADEMODE, D3DSHADE_GOURAUD );
	}
	else
	{
		Luna3D::SetRenderState( D3DRS_FILLMODE, D3DFILL_SOLID );
		Luna3D::SetRenderState( D3DRS_SHADEMODE, D3DSHADE_GOURAUD );
	}
}

//=============================================================================
/**
	�t�H�O�p�f�[�^�ݒ�

	@param fNear	[in] �t�H�O�J�n�_
	@param fFar		[in] �t�H�O�I���_
	@param Color	[in] �t�H�O�F

*/
//=============================================================================
void Luna3D::SetFogParameter( Float fNear, Float fFar, D3DCOLOR Color )
{
	Float start_z = 0.0f;
	Float end_z   = 1.0f;

	Luna3D::SetRenderState( D3DRS_FOGVERTEXMODE, D3DFOG_LINEAR );
	Luna3D::SetRenderState( D3DRS_FOGCOLOR, Color & 0x00FFFFFF );
	Luna3D::SetRenderState( D3DRS_FOGSTART, *((Uint32 *)(&start_z)) );
	Luna3D::SetRenderState( D3DRS_FOGEND,   *((Uint32 *)(&end_z)) );

	m_FogNear  = fNear;
	m_FogFar   = fFar;
	m_FogColor = Color;
}

//=============================================================================
/**
	�t�H�O�p�f�[�^�擾

	@param pfNear	[in] �t�H�O�J�n�_�i�[��
	@param pfFar	[in] �t�H�O�I���_�i�[��
	@param pColor	[in] �t�H�O�F�i�[��

*/
//=============================================================================
void Luna3D::GetFogParameter( Float *pfNear, Float *pfFar, D3DCOLOR *pColor )
{
	if ( pfNear != NULL ) *pfNear = m_FogNear;
	if ( pfFar  != NULL ) *pfFar  = m_FogFar;
	if ( pColor != NULL ) *pColor = m_FogColor;
}

//=============================================================================
/**
	�e�o�b�t�@���e���N���A���܂��B

	@param ClearFlags	[in] �N���A�t���O<BR>
								D3DCLEAR_TARGET		�����_�����O �^�[�Q�b�g���N���A���āAColor �p�����[�^�̐F�ɂ���<BR>
								D3DCLEAR_ZBUFFER	�[�x�o�b�t�@���N���A���āADepth �p�����[�^�̒l�ɂ���<BR>
								D3DCLEAR_STENCIL	�X�e���V�� �o�b�t�@���N���A���āAStencil �p�����[�^�̒l�ɂ���<BR>
	@param Color		[in] D3DCLEAR_TARGET �w�莞�̓h��Ԃ��F
	@param Depth		[in] D3DCLEAR_ZBUFFER �w�莞�̐[�x�l
	@param Stencil		[in] D3DCLEAR_STENCIL �w�莞�̃X�e���V���l
	@param pDst			[in] �K�p���`�A�h���X

	@retval true		����
	@retval false		���s
*/
//=============================================================================
Bool Luna3D::Clear( Uint32 ClearFlags, D3DCOLOR Color, Float Depth, Uint32 Stencil, RECT *pDst )
{
	return SUCCEEDED( m_pDevice->Clear( (pDst==NULL)?(0):(1), (D3DRECT*)pDst, ClearFlags, Color, Depth, Stencil ) );
}

//=============================================================================
/**
	��ʂ̓h��Ԃ������܂�

	@param pDst		[in] �h��Ԃ��]�����`�̃|�C���^
	@param Color	[in] �h��Ԃ��F
*/
//=============================================================================
void Luna3D::ColorFill( RECT *pDst, D3DCOLOR Color )
{
	m_pDevice->Clear( (pDst==NULL)?(0):(1), (D3DRECT*)pDst, D3DCLEAR_TARGET, Color, 1, 0 );
}

//=============================================================================
/**
	�R�c�V�[���̊J�n���f�o�C�X�ɒʒm���܂��B

	@retval true		����
	@retval false		���s
*/
//=============================================================================
Bool Luna3D::BeginScene( void )
{
	HRESULT hr = D3D_OK;

	if ( m_SceneCount == 0 )
	{
		hr = m_pDevice->BeginScene();
	}

	m_SceneCount++;

	return SUCCEEDED( hr );
}

//=============================================================================
/**
	�R�c�V�[���̏I�����f�o�C�X�ɒʒm���܂��B

*/
//=============================================================================
void Luna3D::EndScene( void )
{
	m_SceneCount--;

	if ( m_SceneCount == 0 )
	{
		m_pDevice->EndScene();
	}
}

//=============================================================================
/**
	�|���S�����V�U�����O���邽�߂̗̈��ݒ肵�܂�

	@param IsUse		[in] �g�p����Ȃ� true / �g�p���Ȃ��Ȃ� false
	@param pRect		[in] �V�U�����O��`�̃|�C���^
*/
//=============================================================================
void Luna3D::SetScissoring( Bool IsUse, RECT *pRect )
{
	//------------------------------------------------
	// ���z��ʂ������ʂ�
	//------------------------------------------------
	if ( IsUse )
	{
		pRect->left   = toI(Luna::Virtual2RealX( toF(pRect->left)   ) - 0.5f);
		pRect->right  = toI(Luna::Virtual2RealX( toF(pRect->right)  ) - 0.5f);
		pRect->top    = toI(Luna::Virtual2RealY( toF(pRect->top)    ) - 0.5f);
		pRect->bottom = toI(Luna::Virtual2RealY( toF(pRect->bottom) ) - 0.5f);
	}

	//------------------------------------------------
	// �e�N���X�ɓ`�B
	//------------------------------------------------
	LunaPrimitive::SetScissoring( IsUse, pRect );
	LunaSprite::SetScissoring( IsUse, pRect );
	LunaLine::SetScissoring( IsUse, pRect );
	LunaPoint::SetScissoring( IsUse, pRect );
}

//=============================================================================
/**
	�Q�c�v���~�e�B�u�֘A�̓����ϊ��`�揈���̐ݒ�����܂�

	@param IsUse		[in] �g�p����Ȃ� true / �g�p���Ȃ��Ȃ� false
	@param LookX		[in] �����_�w���W
	@param LookY		[in] �����_�w���W
	@param Scale		[in] �p�[�X�̂���
*/
//=============================================================================
void Luna3D::SetPerspective( Bool IsUse, Float LookX, Float LookY, Float Scale )
{
	LunaPrimitive::SetPerspective( IsUse, LookX, LookY, Scale );
	LunaSprite::SetPerspective( IsUse, LookX, LookY, Scale );
	LunaLine::SetPerspective( IsUse, LookX, LookY, Scale );
	LunaPoint::SetPerspective( IsUse, LookX, LookY, Scale );
}

//=============================================================================
/*
	�Q�c�v���~�e�B�u�֘A�̊g��k���`�揈���̐ݒ�����܂�

	@param IsUse		[in] �g�p����Ȃ� true / �g�p���Ȃ��Ȃ� false
	@param CenterX		[in] ���S�w���W
	@param CenterY		[in] ���S�x���W
	@param Zoom			[in] �g��k����
*/
//=============================================================================
void Luna3D::SetZoom( Bool IsUse, Float CenterX, Float CenterY, Float Zoom )
{
	LunaPrimitive::SetZoom( IsUse, CenterX, CenterY, Zoom );
	LunaSprite::SetZoom( IsUse, CenterX, CenterY, Zoom );
	LunaLine::SetZoom( IsUse, CenterX, CenterY, Zoom );
	LunaPoint::SetZoom( IsUse, CenterX, CenterY, Zoom );
}

//=============================================================================
/**
	�o�b�N�o�b�t�@�̓��e���t�����g�o�b�t�@�ɓ]�����܂��B

	@param hWnd		[in] �]����E�C���h�E�n���h��
*/
//=============================================================================
void Luna3D::Refresh( HWND hWnd )
{
	HRESULT hr;
	//------------------------------------------------------------------
	// ��ʍX�V
	//------------------------------------------------------------------
#ifdef __TOOL_MODE__
	if ( hWnd == NULL )
	{
		hr = m_pDevice->Present( NULL, NULL, NULL, NULL );
	}
	else
	{
		RECT Rect;
		::GetClientRect( hWnd, &Rect );
		hr = m_pDevice->Present( &Rect, &Rect, hWnd, NULL );
	}
#else
	hr = m_pDevice->Present( NULL, NULL, hWnd, NULL );
#endif
	switch ( hr )
	{
	case D3DERR_DRIVERINTERNALERROR:
#ifndef __TOOL_MODE__
		Luna::Exit();
#else
		::SendMessage( ::GetActiveWindow(), WM_CLOSE, 0, 0 );
#endif
		break;
	case D3DERR_DEVICELOST:
		switch ( m_pDevice->TestCooperativeLevel() )
		{
		case D3DERR_DEVICELOST:
			::SleepEx( 10, true );
			break;
		case D3DERR_DEVICENOTRESET:
			Luna3D::ResetDevice( false );
			break;
		}
		break;
	}
}

//=============================================================================
/**
	�e�N�X�`�����f�o�C�X�ɐݒ肵�܂�

	@param Stage	[in] �e�N�X�`���X�e�[�W
	@param lTex		[in] �e�N�X�`���n���h��

*/
//=============================================================================
void Luna3D::SetTexture( Uint32 Stage, LTEXTURE lTex )
{
	if ( (0 <= Stage) && (Stage < TEXTURE_STAGE_MAX) )
	{
		if ( lTex == NULL )
		{
			m_pDevice->SetTexture( Stage, NULL );
		}
		else
		{
			IDirect3DTexture9 *pTex;
			((CTexture*)lTex)->GetInstance( &pTex );
			m_pDevice->SetTexture( Stage, pTex );
			SAFE_RELEASE( pTex );
		}
	}
}

//=============================================================================
/**
	�T�[�t�F�C�X�p�̃t�H�[�}�b�g�̎擾���s���܂��B

	@param Format	[in] �T�[�t�F�C�X�t�H�[�}�b�g
	@param OrgFmt	[in] �I���W�i���̃t�@�C���t�H�[�}�b�g

	@return		���ۂ̃T�[�t�F�C�X�ɓK�p�����t�H�[�}�b�g
*/
//=============================================================================
D3DFORMAT Luna3D::GetFormat( eSurfaceFormat Format, D3DFORMAT OrgFmt )
{
	Bool IsWindow;
	D3DFORMAT ScreenFormat;

	//------------------------------------------------------------
	// �E�B���h�E���擾
	//------------------------------------------------------------
	Luna::GetScreenData( NULL, NULL, &IsWindow );
	ScreenFormat = IsWindow ? m_WindowMode.Format : m_FullScreenMode[m_IsFullColor ? 1 : 0].Format;

	//------------------------------------------------------------
	// �t�H�[�}�b�g��񌟍�
	//------------------------------------------------------------
	switch ( Format )
	{
		// �t�@�C������
	case FORMAT_FROM_FILE:
		return OrgFmt;

		// 16Bit�[�x�o�b�t�@
	case FORMAT_DEPTH16:
		{
			D3DFORMAT FmtTbl[] = {
				D3DFMT_D16_LOCKABLE, D3DFMT_D16, D3DFMT_D15S1, D3DFMT_UNKNOWN,
			};

			for ( Sint32 i = 0; FmtTbl[i] != D3DFMT_UNKNOWN; i++ )
			{
				for ( Sint32 j = 0; j < m_AdapterData.DepthCount; j++ )
				{
					if ( FmtTbl[i] == m_AdapterData.DepthFormats[j] )
					{
						return FmtTbl[i];
					}
				}
			}
		}
		break;

		// 32Bit�[�x�o�b�t�@
	case FORMAT_DEPTH32:
		{
			D3DFORMAT FmtTbl[] = {
				D3DFMT_D32, D3DFMT_D24S8, D3DFMT_D24X8, D3DFMT_D24X4S4, D3DFMT_D24FS8, D3DFMT_UNKNOWN,
			};

			for ( Sint32 i = 0; FmtTbl[i] != D3DFMT_UNKNOWN; i++ )
			{
				for ( Sint32 j = 0; j < m_AdapterData.DepthCount; j++ )
				{
					if ( FmtTbl[i] == m_AdapterData.DepthFormats[j] )
					{
						return FmtTbl[i];
					}
				}
			}
		}
		break;

		// �X�e���V���[�x�o�b�t�@
	case FORMAT_DEPTHSTENCIL:
		{
			D3DFORMAT FmtTbl[] = {
				D3DFMT_D24S8, D3DFMT_D24X4S4, D3DFMT_D24FS8, D3DFMT_D15S1, D3DFMT_UNKNOWN,
			};

			for ( Sint32 i = 0; FmtTbl[i] != D3DFMT_UNKNOWN; i++ )
			{
				for ( Sint32 j = 0; j < m_AdapterData.DepthCount; j++ )
				{
					if ( FmtTbl[i] == m_AdapterData.DepthFormats[j] )
					{
						return FmtTbl[i];
					}
				}
			}
		}
		break;

		// �o�b�N�o�b�t�@�[�ɏ���
	case FORMAT_BACKBUFFER:
		{
			return ScreenFormat;
		}
		break;

		// 16Bit�����_�����O�^�[�Q�b�g
	case FORMAT_TARGET16:
		{
			D3DFORMAT FmtTbl[] = {
				D3DFMT_A4R4G4B4, D3DFMT_A1R5G5B5, D3DFMT_X1R5G5B5, D3DFMT_UNKNOWN,
			};

			for ( Sint32 i = 0; FmtTbl[i] != D3DFMT_UNKNOWN; i++ )
			{
				for ( Sint32 j = 0; j < m_AdapterData.TargetCount; j++ )
				{
					if ( FmtTbl[i] == m_AdapterData.TargetFormats[j] )
					{
						return FmtTbl[i];
					}
				}
			}
		}
		break;

		// 32Bit�����_�����O�^�[�Q�b�g
	case FORMAT_TARGET32:
		{
			D3DFORMAT FmtTbl[] = {
				D3DFMT_A8R8G8B8, D3DFMT_X8R8G8B8, D3DFMT_UNKNOWN,
			};

			for ( Sint32 i = 0; FmtTbl[i] != D3DFMT_UNKNOWN; i++ )
			{
				for ( Sint32 j = 0; j < m_AdapterData.TargetCount; j++ )
				{
					if ( FmtTbl[i] == m_AdapterData.TargetFormats[j] )
					{
						return FmtTbl[i];
					}
				}
			}
		}
		break;

		// ���������_�����_�����O�^�[�Q�b�g
	case FORMAT_TARGETFloat:
		{
			D3DFORMAT FmtTbl[] = {
				D3DFMT_A32B32G32R32F, D3DFMT_A16B16G16R16F, D3DFMT_UNKNOWN,
			};

			for ( Sint32 i = 0; FmtTbl[i] != D3DFMT_UNKNOWN; i++ )
			{
				for ( Sint32 j = 0; j < m_AdapterData.TargetCount; j++ )
				{
					if ( FmtTbl[i] == m_AdapterData.TargetFormats[j] )
					{
						return FmtTbl[i];
					}
				}
			}
		}
		break;

		// �A���t�@�p�e�N�X�`��
	case FORMAT_ALPHAONLY:
		{
			D3DFORMAT FmtTbl[] = {
				D3DFMT_A8, D3DFMT_A8R3G3B2, D3DFMT_A8R8G8B8, D3DFMT_A4R4G4B4, D3DFMT_UNKNOWN,
			};

			for ( Sint32 i = 0; FmtTbl[i] != D3DFMT_UNKNOWN; i++ )
			{
				for ( Sint32 j = 0; j < m_AdapterData.TextureCount; j++ )
				{
					if ( FmtTbl[i] == m_AdapterData.TextureFormats[j] )
					{
						return FmtTbl[i];
					}
				}
			}
		}
		break;

		// 32Bit�e�N�X�`���t�H�[�}�b�g�ɏ���
	case FORMAT_TEXTURE32:
		{
			D3DFORMAT FmtTbl[] = {
				D3DFMT_A8R8G8B8, D3DFMT_UNKNOWN,
			};

			for ( Sint32 i = 0; FmtTbl[i] != D3DFMT_UNKNOWN; i++ )
			{
				for ( Sint32 j = 0; j < m_AdapterData.TextureCount; j++ )
				{
					if ( FmtTbl[i] == m_AdapterData.TextureFormats[j] )
					{
						return FmtTbl[i];
					}
				}
			}
		}
		break;

		// 16Bit�e�N�X�`���t�H�[�}�b�g�ɏ���
	case FORMAT_TEXTURE16:
		{
			D3DFORMAT FmtTbl[] = {
				D3DFMT_A4R4G4B4, D3DFMT_A1R5G5B5, D3DFMT_A8R3G3B2, D3DFMT_UNKNOWN,
			};

			for ( Sint32 i = 0; FmtTbl[i] != D3DFMT_UNKNOWN; i++ )
			{
				for ( Sint32 j = 0; j < m_AdapterData.TextureCount; j++ )
				{
					if ( FmtTbl[i] == m_AdapterData.TextureFormats[j] )
					{
						return FmtTbl[i];
					}
				}
			}
		}
		break;

		// DXT1���k�t�H�[�}�b�g�e�N�X�`��
	case FORMAT_DXT1:
		{
			D3DFORMAT FmtTbl[] = {
				D3DFMT_DXT1, D3DFMT_UNKNOWN,
			};

			for ( Sint32 i = 0; FmtTbl[i] != D3DFMT_UNKNOWN; i++ )
			{
				for ( Sint32 j = 0; j < m_AdapterData.TextureCount; j++ )
				{
					if ( FmtTbl[i] == m_AdapterData.TextureFormats[j] )
					{
						return FmtTbl[i];
					}
				}
			}
		}
		break;

		// DXT3���k�t�H�[�}�b�g�e�N�X�`��
	case FORMAT_DXT3:
		{
			D3DFORMAT FmtTbl[] = {
				D3DFMT_DXT3, D3DFMT_UNKNOWN,
			};

			for ( Sint32 i = 0; FmtTbl[i] != D3DFMT_UNKNOWN; i++ )
			{
				for ( Sint32 j = 0; j < m_AdapterData.TextureCount; j++ )
				{
					if ( FmtTbl[i] == m_AdapterData.TextureFormats[j] )
					{
						return FmtTbl[i];
					}
				}
			}
		}
		break;

		// DXT5���k�t�H�[�}�b�g�e�N�X�`��
	case FORMAT_DXT5:
		{
			D3DFORMAT FmtTbl[] = {
				D3DFMT_DXT5, D3DFMT_UNKNOWN,
			};

			for ( Sint32 i = 0; FmtTbl[i] != D3DFMT_UNKNOWN; i++ )
			{
				for ( Sint32 j = 0; j < m_AdapterData.TextureCount; j++ )
				{
					if ( FmtTbl[i] == m_AdapterData.TextureFormats[j] )
					{
						return FmtTbl[i];
					}
				}
			}
		}
		break;

		// ���[�U�[��`2D�e�N�X�`��
	case FORMAT_TEXTURE_2D:
		{
			for ( Uint32 i = 0; i < m_SurfaceFormatCount[0]; i++ )
			{
				D3DFORMAT Fmt = GetFormat( m_SurfaceFormatTbl[0][i], D3DFMT_UNKNOWN );
				if ( Fmt != D3DFMT_UNKNOWN )
				{
					return Fmt;
				}
			}
		}
		break;

		// ���[�U�[��`3D�e�N�X�`��
	case FORMAT_TEXTURE_3D:
		{
			for ( Uint32 i = 0; i < m_SurfaceFormatCount[1]; i++ )
			{
				D3DFORMAT Fmt = GetFormat( m_SurfaceFormatTbl[1][i], D3DFMT_UNKNOWN );
				if ( Fmt != D3DFMT_UNKNOWN )
				{
					return Fmt;
				}
			}
		}
		break;
	}

	return D3DFMT_UNKNOWN;
}

//=============================================================================
/**
	2D�p�T�[�t�F�C�X�t�H�[�}�b�g�����e�[�u����ݒ肵�܂�

	@param FmtTbl	[in] �T�[�t�F�C�X�t�H�[�}�b�g�e�[�u��
	@param Count	[in] �T�[�t�F�C�X�t�H�[�}�b�g�e�[�u����
*/
//=============================================================================
void Luna3D::SetSurfaceFormatTblFor2D( eSurfaceFormat FmtTbl[], Uint32 Count )
{
	MemoryCopy( m_SurfaceFormatTbl[0], FmtTbl, sizeof(eSurfaceFormat) * Count );
	m_SurfaceFormatCount[0] = Count;
}

//=============================================================================
/**
	3D�p�T�[�t�F�C�X�t�H�[�}�b�g�����e�[�u����ݒ肵�܂�

	@param FmtTbl	[in] �T�[�t�F�C�X�t�H�[�}�b�g�e�[�u��
	@param Count	[in] �T�[�t�F�C�X�t�H�[�}�b�g�e�[�u����
*/
//=============================================================================
void Luna3D::SetSurfaceFormatTblFor3D( eSurfaceFormat FmtTbl[], Uint32 Count )
{
	MemoryCopy( m_SurfaceFormatTbl[1], FmtTbl, sizeof(eSurfaceFormat) * Count );
	m_SurfaceFormatCount[1] = Count;
}

//=============================================================================
/**
	�[�x�o�b�t�@�Ɏg�p����T�[�t�F�C�X��ݒ肵�܂�

	@param lSurf	[in] �T�[�t�F�C�X�n���h��

	@retval true		����
	@retval false		���s
*/
//=============================================================================
Bool Luna3D::SetDepthStencilSurface( LSURFACE lSurf )
{
	if ( lSurf == NULL )
	{
		m_lSurfDepthStencil = NULL;
		Luna3D::GetDevice()->SetDepthStencilSurface( NULL );

		return true;
	}
	else
	{
		m_lSurfDepthStencil = lSurf;
		((CSurface*)lSurf)->SetDepthStencil();

		return true;
	}
}

//=============================================================================
/**
	�����_�����O�Ɏg�p����J������ݒ肵�܂�

	@param lCam		[in] �J�����n���h��

*/
//=============================================================================
void Luna3D::SetCamera( LCAMERA lCam )
{
	if ( lCam == INVALID_CAMERA ) return;

	m_lCamera = lCam;
	LunaCamera::SetDevice( m_lCamera );
}

//=============================================================================
/**
	�����_�����O�^�[�Q�b�g�Ɏg���T�[�t�F�C�X��ݒ肵�܂�

	@param lSurf		[in] �T�[�t�F�C�X�n���h��

	@retval true		����
	@retval false		���s
*/
//=============================================================================
Bool Luna3D::SetRenderTargetSurface( LSURFACE lSurf )
{
	if ( lSurf != NULL )
	{
		m_lTexTarget = NULL;
		m_lSurfTarget = lSurf;

		if ( ((CSurface*)m_lSurfTarget)->SetRenderTarget() )
		{
			ResetDepthStencil();
		
			return true;
		}
	}
	else
	{
		m_lTexTarget = NULL;
		m_lSurfTarget = NULL;

		RECT View = { 0, 0, 0, 0 };
		Luna::GetScreenData( &View.right, &View.bottom, NULL );

		if ( ResetRenderTarget() )
		{
			SetViewport( &View );
	
			ResetDepthStencil();

			return true;
		}
	}

	return false;
}

//=============================================================================
/**
	�����_�����O�^�[�Q�b�g�Ɏg���e�N�X�`����ݒ肵�܂�

	@retval true		����
	@retval false		���s
*/
//=============================================================================
Bool Luna3D::ResetRenderTarget( void )
{
	if SUCCEEDED( m_pDevice->SetRenderTarget( 0, m_pRenderTarget ) )
	{
		ResetDepthStencil();

		return true;
	}

	return false;
}

//=============================================================================
/**
	�����_�����O�^�[�Q�b�g�Ɏg���e�N�X�`����ݒ肵�܂�

	@param pDstRect		[in] �]�����`(NULL�őS��
	@param lSurf		[in] �]�����T�[�t�F�C�X
	@param pSrcRect		[in] �]������`(NULL�őS��

	@retval true		����
	@retval false		���s
*/
//=============================================================================
Bool Luna3D::CopyToRenderTarget( RECT *pDstRect, LSURFACE lSurf, RECT *pSrcRect )
{
	CSurface *pSrc = (CSurface*)lSurf;
	IDirect3DSurface9 *pSrcSurf;
	HRESULT hr;

	pSrc->GetInstance( &pSrcSurf );

	hr = GetDevice()->StretchRect(
						pSrcSurf,
						pSrcRect,
						m_pRenderTarget,
						pDstRect,
						D3DTEXF_NONE );

	pSrcSurf->Release();

	return SUCCEEDED( hr );
}


//=============================================================================
/**
	�����_�����O�^�[�Q�b�g�Ɏg���e�N�X�`����ݒ肵�܂�

	@retval true		����
	@retval false		���s
*/
//=============================================================================
Bool Luna3D::ResetDepthStencil( void )
{
	if ( m_lSurfDepthStencil != NULL )
	{
		if ( ((CSurface*)m_lSurfDepthStencil)->SetDepthStencil() )
		{
			SetRenderState( D3DRS_ZENABLE, true );
			SetRenderState( D3DRS_ZWRITEENABLE, true );

			return true;
		}

		SetRenderState( D3DRS_ZENABLE, false );
		SetRenderState( D3DRS_ZWRITEENABLE, false );

		return false;
	}

	SetRenderState( D3DRS_ZENABLE, false );
	SetRenderState( D3DRS_ZWRITEENABLE, false );

	return true;
}

//=============================================================================
/**
	�����_�����O�^�[�Q�b�g�Ɏg���e�N�X�`����ݒ肵�܂�

	@param lTex		[in] �e�N�X�`���n���h��

	@retval true		����
	@retval false		���s
*/
//=============================================================================
Bool Luna3D::SetRenderTargetTexture( LTEXTURE lTex )
{
	if ( lTex != NULL )
	{
		m_lTexTarget = lTex;
		m_lSurfTarget = NULL;

		if ( ((CTexture*)m_lTexTarget)->SetRenderTarget() )
		{
			RECT View = { 0, 0, ((CTexture*)m_lTexTarget)->GetWidth(), ((CTexture*)m_lTexTarget)->GetHeight() };
			SetViewport( &View );

			ResetDepthStencil();

			return true;
		}
	}
	else
	{
		m_lTexTarget = NULL;
		m_lSurfTarget = NULL;

		RECT View = { 0, 0, 0, 0 };
		Luna::GetScreenData( &View.right, &View.bottom, NULL );

		if ( ResetRenderTarget() )
		{
			SetViewport( &View );
			ResetDepthStencil();

			return true;
		}
	}

	return false;
}

//=============================================================================
/**
	���C�g�̂n�m�^�n�e�e��ݒ肵�܂�

	@param No			[in] ���C�g�ԍ�
	@param IsActive		[in] true �g�p / false ���g�p
*/
//=============================================================================
void Luna3D::SetLight( Sint32 No, Bool IsActive )
{
	LunaLight::SetDevice( No, IsActive );
}

//=============================================================================
/**
	�c�b�o�R�̃t�H���g�`����J�n���܂�

	@param pFontFace	[in] �t�H���g��
	@param FontSize		[in] �t�H���g�T�C�Y

	@retval true		����
	@retval false		���s
*/
//=============================================================================
Bool Luna3D::FontBegin( const char *pFontFace, Sint32 FontSize )
{
	HRESULT hr;

	//----------------------------------------------
	// �c�b�擾
	//----------------------------------------------
	hr = m_pRenderTarget->GetDC( &m_hDC );
	if FAILED( hr )
	{
		return false;
	}

	//----------------------------------------------
	// �t�H���g����
	//----------------------------------------------
	m_hFont = ::CreateFont(
						FontSize,					// �t�H���g����
						0,							// ������
						0,							// �e�L�X�g�̊p�x	
						0,							// �x�[�X���C���Ƃ����Ƃ̊p�x
						0,							// �t�H���g�̏d���i�����j
						false,						// �C�^���b�N��
						false,						// �A���_�[���C��
						false,						// �ł�������
						SHIFTJIS_CHARSET,			// �����Z�b�g
						OUT_TT_PRECIS,				// �o�͐��x
						CLIP_DEFAULT_PRECIS,		// �N���b�s���O���x
						PROOF_QUALITY,				// �o�͕i��
						FIXED_PITCH | FF_MODERN,	// �s�b�`�ƃt�@�~���[
						pFontFace );				// ���̖�

	// �t�H���g�ݒ�
	m_hOldFont = (HFONT)::SelectObject( m_hDC, m_hFont );

	return true;
}

//=============================================================================
/**
	�c�b�o�R�̃t�H���g�`������܂�

	@param Px			[] �`��w�ʒu
	@param Py			[] �`��x�ʒu
	@param FontColor	[] �t�H���g�J���[
	@param BackColor	[] �w�i�J���[
	@param pStr,...		[] �`�敶����iprintf()�Ɠ��l�̏����j
*/
//=============================================================================
void Luna3D::FontDraw( Sint32 Px, Sint32 Py, COLORREF FontColor, COLORREF BackColor, const char *pStr,... )
{
	char Temp[1024] = "";
	vsprintf( Temp, pStr, (char*)(&pStr + 1) );

	// �q�[�F
	::SetBkColor( m_hDC, BackColor );
	::SetBkMode( m_hDC, OPAQUE );

	// �t�H���g�F
	::SetTextColor( m_hDC, FontColor );

	// �t�H���g�`��
	::TextOut( m_hDC, Px, Py, Temp, (Sint32)strlen(Temp) );
}

//=============================================================================
/**
	�c�b�o�R�̃t�H���g�`����I�����܂�

*/
//=============================================================================
void Luna3D::FontEnd( void )
{
	::SelectObject( m_hDC, m_hOldFont );
	::DeleteObject( m_hFont );

	m_pRenderTarget->ReleaseDC( m_hDC );
}

//=============================================================================
/**
	�t�B�����[�g�̃`�F�b�N���J�n����

*/
//=============================================================================
void Luna3D::FillRateCheckStart( void )
{
	if ( m_pQuery[1] != NULL )
	{
		if ( !m_IsCheckingFillRate )
		{
			m_IsCheckingFillRate = true;
			m_pQuery[1]->Issue( D3DISSUE_BEGIN );
		}
	}
}

//=============================================================================
/**
	�t�B�����[�g�̃`�F�b�N���I������

	@return �t�B���s�N�Z����
*/
//=============================================================================
Uint32 Luna3D::FillRateCheckEnd( void )
{
	if ( m_pQuery[1] != NULL )
	{
		if ( m_IsCheckingFillRate )
		{
			m_IsCheckingFillRate = false;
			m_pQuery[1]->Issue( D3DISSUE_END );

			Uint32 Data = 0;
			HRESULT hr = m_pQuery[1]->GetData( &Data, sizeof(Uint32), D3DGETDATA_FLUSH );
			if FAILED( hr )
			{
				LunaDebug::OutputString( Luna3D::GetError( hr ) );
				return 0xFFFFFFFF;
			}
			return Data;
		}
	}

	return 0;
}

//=============================================================================
/**
	�����_�����O�̏I����҂�

*/
//=============================================================================
Bool Luna3D::BlockForEndRendering( void )
{
	if ( m_pQuery[0] != NULL )
	{
		m_pQuery[0]->Issue( D3DISSUE_END );

		BOOL Data = false;
		return (S_OK == m_pQuery[0]->GetData( &Data, sizeof(BOOL), D3DGETDATA_FLUSH ));
	}
	return false;
}

//=============================================================================
/**
	�o�b�N�o�b�t�@�̃��b�N�����܂�

	@param ppBits		[out] �o�b�t�@�̃s�N�Z���f�[�^�̐擪�A�h���X�i�[��
	@param pPitch		[out] �T�[�t�F�C�X�̃s�b�`�i�[��A�h���X
	@param pFormat		[out] �T�[�t�F�C�X�̃t�H�[�}�b�g�i�[��A�h���X
	@param pWidth		[out] �T�[�t�F�C�X�̉����i�[��A�h���X
	@param pHeight		[out] �T�[�t�F�C�X�̏c���i�[��A�h���X

	@retval true		����
	@retval false		���s
*/
//=============================================================================
Bool Luna3D::LockBackBuffer( void **ppBits, Sint32 *pPitch, D3DFORMAT *pFormat, Sint32 *pWidth, Sint32 *pHeight )
{
	if ( !m_IsLocked )
	{
		HRESULT hr;
		IDirect3DSurface9 *pBackBuffer = NULL;

		// �o�b�N�o�b�t�@�擾
		hr = m_pDevice->GetBackBuffer( 0, 0, D3DBACKBUFFER_TYPE_MONO, &pBackBuffer );
		if SUCCEEDED( hr )
		{
			D3DSURFACE_DESC Desc;
			pBackBuffer->GetDesc( &Desc );
			*pFormat = Desc.Format;
			*pWidth = Desc.Width;
			*pHeight = Desc.Height;

			D3DLOCKED_RECT rect;
			HRESULT hr = pBackBuffer->LockRect( &rect, NULL, 0 );
			*pPitch = rect.Pitch;
			*ppBits = rect.pBits;

			m_IsLocked = SUCCEEDED( hr );

			SAFE_RELEASE( pBackBuffer );
		}
	}

	return m_IsLocked;
}

//=============================================================================
/**
	�o�b�N�o�b�t�@�̃��b�N���������܂�

*/
//=============================================================================
void Luna3D::UnlockBackBuffer( void )
{
	if ( m_IsLocked )
	{
		HRESULT hr;
		IDirect3DSurface9 *pBackBuffer = NULL;

		// �o�b�N�o�b�t�@�擾
		hr = m_pDevice->GetBackBuffer( 0, 0, D3DBACKBUFFER_TYPE_MONO, &pBackBuffer );
		if SUCCEEDED( hr )
		{
			pBackBuffer->UnlockRect();
			SAFE_RELEASE( pBackBuffer );
			m_IsLocked = false;
		}
	}
}

//=============================================================================
/**
	���[���h���W����X�N���[����Ԃւ̕ϊ������܂�

	@param pWorldPos	[in] ���[���h��Ԃ̍��W
	@param pScreenPos	[out] �X�N���[����̍��W
*/
//=============================================================================
void Luna3D::WorldToScreen( CVector3D *pWorldPos, CVector3D *pScreenPos )
{
	CMatrix mCamera;
	CVector3D vWorld;

	//----------------------------------------------
	// �J�����s��擾
	//----------------------------------------------
	LunaCamera::GetMatrixDirect( NULL, NULL, &mCamera );

	//----------------------------------------------
	// �J������Ԃɕϊ�
	//----------------------------------------------
	vWorld.TransformProjection( pWorldPos, &mCamera );

	//----------------------------------------------
	// �v���W�F�N�V������Ԃɕϊ�
	//----------------------------------------------
	Float w = toF(m_Viewport.Width  / 2);
	Float h = toF(m_Viewport.Height / 2);
	Float x = toF(m_Viewport.X + w);
	Float y = toF(m_Viewport.Y + h);

	pScreenPos->x = x + (+vWorld.x * w);
	pScreenPos->y = y + (-vWorld.y * h);
}

//=============================================================================
/**
	�X�N���[�����W���烏�[���h��Ԃւ̕ϊ������܂�

	@param pWorldPos	[out] ���[���h��Ԃ̍��W
	@param pScreenPos	[in] �X�N���[����̍��W
*/
//=============================================================================
void Luna3D::ScreenToWorld( CVector3D *pWorldPos, CVector3D *pScreenPos )
{
	CMatrix mCameraInv;

	//----------------------------------------------
	// �J�����s��擾
	//----------------------------------------------
	LunaCamera::GetMatrixDirect( NULL, NULL, NULL, &mCameraInv );

	//----------------------------------------------
	// �v���W�F�N�V������Ԃɕϊ�
	//----------------------------------------------
	Float w = toF(m_Viewport.Width  / 2);
	Float h = toF(m_Viewport.Height / 2);
	Float x = toF(m_Viewport.X + w);
	Float y = toF(m_Viewport.Y + h);
	pWorldPos->x = +toF(pScreenPos->x - x) / w;
	pWorldPos->y = -toF(pScreenPos->y - y) / h;
	pWorldPos->z = pScreenPos->z;

	//----------------------------------------------
	// �J������Ԃɕϊ�
	//----------------------------------------------
	pWorldPos->TransformProjection( &mCameraInv );
}

//=============================================================================
/**
	�X�N���[�����W����r���[��Ԃւ̕ϊ������܂�

	@param pViewPos		[out] �r���[��Ԃ̍��W
	@param pScreenPos	[in] �X�N���[����̍��W
*/
//=============================================================================
void Luna3D::ScreenToView( CVector3D *pViewPos, CVector3D *pScreenPos )
{
	CMatrix mCamera;

	//----------------------------------------------
	// �J�����s��擾
	//----------------------------------------------
	LunaCamera::GetMatrixDirect( &mCamera, NULL, NULL );

	//----------------------------------------------
	// �v���W�F�N�V������Ԃɕϊ�
	//----------------------------------------------
	Float w = toF(m_Viewport.Width  / 2);
	Float h = toF(m_Viewport.Height / 2);
	Float x = toF(m_Viewport.X + w);
	Float y = toF(m_Viewport.Y + h);
	pViewPos->x = +toF(pScreenPos->x - x) / w;
	pViewPos->y = -toF(pScreenPos->y - y) / h;
	pViewPos->z = pScreenPos->z;

	//----------------------------------------------
	// �J������Ԃɕϊ�
	//----------------------------------------------
	mCamera.Inverse();
	pViewPos->TransformProjection( &mCamera );
}

//=============================================================================
/**
	�w���`���N���b�s���O���܂�

	@param pDst		[in/out] �]�����`
	@param pSrc		[in/out] �]������`

	@retval true	�`��\
	@retval false	�`��s�v
*/
//=============================================================================
Bool Luna3D::Clip( RECT *pDst, RECT *pSrc )
{
	// �r���[�|�[�g
	Sint32 x1 = m_Viewport.X;
	Sint32 y1 = m_Viewport.Y;
	Sint32 x2 = x1 + m_Viewport.Width;
	Sint32 y2 = y1 + m_Viewport.Height;

	// �]�����`
	Sint32 dx1 = pDst->left;
	Sint32 dy1 = pDst->top;
	Sint32 dx2 = pDst->right;
	Sint32 dy2 = pDst->bottom;

	// �]������`
	Sint32 sx1 = pSrc->left;
	Sint32 sy1 = pSrc->top;
	Sint32 sx2 = pSrc->right;
	Sint32 sy2 = pSrc->bottom;

	// �T�C�Y�䗦
	Float fx = toF(sx2 - sx1) / toF(dx2 - dx1);
	Float fy = toF(sy2 - sy1) / toF(dy2 - dy1);

	// ���`�F�b�N
	if ( dx1 < x1 )
	{
		sx1 = sx1 + toI(toF(x1 - dx1) * fx);
		dx1 = x1;
	}
	// ��`�F�b�N
	if ( dy1 < y1 )
	{
		sy1 = sy1 + toI(toF(y1 - dy1) * fy);
		dy1 = y1;
	}
	// �E�`�F�b�N
	if ( dx2 > x2 )
	{
		sx2 = sx2 - toI(toF(dx2 - x2) * fx);
		dx2 = x2;
	}
	// ���`�F�b�N
	if ( dy2 > y2 )
	{
		sy2 = sy2 - toI(toF(dy2 - y2) * fy);
		dy2 = y2;
	}

	// �]�����`
	pDst->left		= dx1;
	pDst->top		= dy1;
	pDst->right		= dx2;
	pDst->bottom	= dy2;

	// �]������`
	pSrc->left		= sx1;
	pSrc->top		= sy1;
	pSrc->right		= sx2;
	pSrc->bottom	= sy2;

	return ((dx1 < dx2) && (dy1 < dy2));
}

//=============================================================================
/**
	�g�p�\�Ȑ���e�N�X�`���������e�ʂ��擾���܂��B

	@return		�������e��(MByte)
*/
//=============================================================================
Uint32 Luna3D::GetRestVRAM( void )
{
	return m_pDevice->GetAvailableTextureMem() / 1024 / 1024;
}

//=============================================================================
/**
	D3DFORMAT�^�̎����s�N�Z���t�H�[�}�b�g�𕶎���Ƃ��Ď擾���܂�

	@param Format	[in] �s�N�Z���t�H�[�}�b�g���ʗp�萔
	@param pStr		[out] ������i�[��

	@return		�s�N�Z���t�H�[�}�b�g������̃|�C���^
*/
//=============================================================================
char *Luna3D::GetPixelFormat( D3DFORMAT Format, char *pStr )
{
	static char String[MAX_PATH];

	switch ( Format )
	{
	case D3DFMT_UNKNOWN:			strcpy( String, "UNKNOWN" );		break;
	case D3DFMT_R8G8B8:				strcpy( String, "R8G8B8" );		break;
	case D3DFMT_A8R8G8B8:			strcpy( String, "A8R8G8B8" );		break;
	case D3DFMT_X8R8G8B8:			strcpy( String, "X8R8G8B8" );		break;
	case D3DFMT_R5G6B5:				strcpy( String, "R5G6B5" );		break;
	case D3DFMT_X1R5G5B5:			strcpy( String, "X1R5G5B5" );		break;
	case D3DFMT_A1R5G5B5:			strcpy( String, "A1R5G5B5" );		break;
	case D3DFMT_A4R4G4B4:			strcpy( String, "A4R4G4B4" );		break;
	case D3DFMT_R3G3B2:				strcpy( String, "R3G3B2" );		break;
	case D3DFMT_A8:					strcpy( String, "A8" );			break;
	case D3DFMT_A8R3G3B2:			strcpy( String, "A8R3G3B2" );		break;
	case D3DFMT_X4R4G4B4:			strcpy( String, "X4R4G4B4" );		break;
	case D3DFMT_A2B10G10R10:		strcpy( String, "A2B10G10R10" );	break;
	case D3DFMT_A8B8G8R8:			strcpy( String, "A8B8G8R8" );		break;
	case D3DFMT_X8B8G8R8:			strcpy( String, "X8B8G8R8" );		break;
	case D3DFMT_G16R16:				strcpy( String, "G16R16" );		break;
	case D3DFMT_A2R10G10B10:		strcpy( String, "A2R10G10B10" );	break;
	case D3DFMT_A16B16G16R16:		strcpy( String, "A16B16G16R16" );	break;
	case D3DFMT_A8P8:				strcpy( String, "A8P8" );			break;
	case D3DFMT_P8:					strcpy( String, "P8" );			break;
	case D3DFMT_L8:					strcpy( String, "L8" );			break;
	case D3DFMT_L16:				strcpy( String, "L16" );			break;
	case D3DFMT_A8L8:				strcpy( String, "A8L8" );			break;
	case D3DFMT_A4L4:				strcpy( String, "A4L4" );			break;
	case D3DFMT_V8U8:				strcpy( String, "V8U8" );			break;
	case D3DFMT_Q8W8V8U8:			strcpy( String, "Q8W8V8U8" );		break;
	case D3DFMT_V16U16:				strcpy( String, "V16U16" );		break;
	case D3DFMT_Q16W16V16U16:		strcpy( String, "Q16W16V16U16" );	break;
	case D3DFMT_CxV8U8:				strcpy( String, "CxV8U8" );		break;
	case D3DFMT_L6V5U5:				strcpy( String, "L6V5U5" );		break;
	case D3DFMT_X8L8V8U8:			strcpy( String, "X8L8V8U8" );		break;
	case D3DFMT_A2W10V10U10:		strcpy( String, "A2W10V10U10" );	break;
	case D3DFMT_G8R8_G8B8:			strcpy( String, "G8R8_G8B8" );		break;
	case D3DFMT_R8G8_B8G8:			strcpy( String, "R8G8_B8G8" );		break;
	case D3DFMT_DXT1:				strcpy( String, "DXT1" );			break;
	case D3DFMT_DXT2:				strcpy( String, "DXT2" );			break;
	case D3DFMT_DXT3:				strcpy( String, "DXT3" );			break;
	case D3DFMT_DXT4:				strcpy( String, "DXT4" );			break;
	case D3DFMT_DXT5:				strcpy( String, "DXT5" );			break;
	case D3DFMT_UYVY:				strcpy( String, "UYVY" );			break;
	case D3DFMT_YUY2:				strcpy( String, "YUY2" );			break;
	case D3DFMT_D16_LOCKABLE:		strcpy( String, "D16_LOCKABLE" );	break;
	case D3DFMT_D32:				strcpy( String, "D32" );			break;
	case D3DFMT_D15S1:				strcpy( String, "D15S1" );			break;
	case D3DFMT_D24S8:				strcpy( String, "D24S8" );			break;
	case D3DFMT_D24X8:				strcpy( String, "D24X8" );			break;
	case D3DFMT_D24X4S4:			strcpy( String, "D24X4S4" );		break;
	case D3DFMT_D32F_LOCKABLE:		strcpy( String, "D32F_LOCKABLE" );	break;
	case D3DFMT_D24FS8:				strcpy( String, "D24FS8" );		break;
	case D3DFMT_D16:				strcpy( String, "D16" );			break;
	case D3DFMT_VERTEXDATA:			strcpy( String, "VERTEXDATA" );	break;
	case D3DFMT_INDEX16:			strcpy( String, "INDEX16" );		break;
	case D3DFMT_INDEX32:			strcpy( String, "INDEX32" );		break;
	case D3DFMT_R16F:				strcpy( String, "R16F" );			break;
	case D3DFMT_G16R16F:			strcpy( String, "G16R16F" );		break;
	case D3DFMT_A16B16G16R16F:		strcpy( String, "A16B16G16R16F" );	break;
	case D3DFMT_R32F:				strcpy( String, "R32F" );			break;
	case D3DFMT_G32R32F:			strcpy( String, "G32R32F" );		break;
	case D3DFMT_A32B32G32R32F:		strcpy( String, "A32B32G32R32F" );	break;
	}

	if ( pStr != NULL ) strcpy( pStr, String );

	return String;
}

//=============================================================================
/**
	HRESULT�^�̎���Direct3D�֘A�̃G���[�𕶎���Ƃ��Ď擾���܂�

	@param hr	[in] �G���[���ʗp�萔

	@return		�G���[������̃|�C���^
*/
//=============================================================================
char *Luna3D::GetError( HRESULT hr )
{
	static char String[MAX_PATH] = "";

	switch ( hr )
	{
	case D3D_OK:
		strcpy( String, "�G���[�͔������Ă��Ȃ��B" );
		break;
	case D3DERR_CONFLICTINGRENDERSTATE:
		strcpy( String, "���ݐݒ肳��Ă��郌���_�����O �X�e�[�g�͈ꏏ�Ɏg�p�ł��Ȃ��B" );
		break;
	case D3DERR_CONFLICTINGTEXTUREFILTER:
		strcpy( String, "���݂̃e�N�X�`�� �t�B���^�͈ꏏ�Ɏg�p�ł��Ȃ��B" );
		break;
	case D3DERR_CONFLICTINGTEXTUREPALETTE:
		strcpy( String, "���݂̃e�N�X�`���͓����Ɏg�p�ł��Ȃ��B��ʂɃ}���`�e�N�X�`�� �f�o�C�X�ɂ����āA�����ɗL���ɂ��ꂽ�p���b�g���e�N�X�`���œ����p���b�g�����L����K�v������ꍇ�ɔ�������B" );
		break;
	case D3DERR_DEVICELOST:
		strcpy( String, "�f�o�C�X�������Ă��āA�����_�ł͕����ł��Ȃ����߁A�����_�����O�͕s�\�ł���B" );
		break;
	case D3DERR_DEVICENOTRESET:
		strcpy( String, "�f�o�C�X�̓��Z�b�g�ł��Ȃ��B" );
		break;
	case D3DERR_DRIVERINTERNALERROR:
		strcpy( String, "�����h���C�o �G���[�B" );
		break;
	case D3DERR_INVALIDCALL:
		strcpy( String, "���\�b�h�̌Ăяo���������ł���B���Ƃ��΁A���\�b�h�̃p�����[�^�ɖ����Ȓl���ݒ肳��Ă���ꍇ�ȂǁB" );
		break;
	case D3DERR_INVALIDDEVICE:
		strcpy( String, "�v�����ꂽ�f�o�C�X�̎�ނ��L���łȂ��B" );
		break;
	case D3DERR_MOREDATA:
		strcpy( String, "�w�肳�ꂽ�o�b�t�@ �T�C�Y�ɕێ��ł���ȏ�̃f�[�^�����݂���B" );
		break;
	case D3DERR_NOTAVAILABLE:
		strcpy( String, "���̃f�o�C�X�́A�Ɖ�ꂽ�e�N�j�b�N���T�|�[�g���Ă��Ȃ��B" );
		break;
	case D3DERR_NOTFOUND:
		strcpy( String, "�v�����ꂽ���ڂ�������Ȃ������B" );
		break;
	case D3DERR_OUTOFVIDEOMEMORY:
		strcpy( String, "Direct3D ���������s���̂ɏ\���ȃf�B�X�v���C ���������Ȃ��B" );
		break;
	case D3DERR_TOOMANYOPERATIONS:
		strcpy( String, "�f�o�C�X���T�|�[�g���Ă���ȏ�̃e�N�X�`�� �t�B���^�����O�������A�A�v���P�[�V�������v�����Ă���B" );
		break;
	case D3DERR_UNSUPPORTEDALPHAARG:
		strcpy( String, "�A���t�@ �`���l���ɑ΂��Ďw�肳��Ă���e�N�X�`�� �u�����f�B���O�������A�f�o�C�X���T�|�[�g���Ă��Ȃ��B" );
		break;
	case D3DERR_UNSUPPORTEDALPHAOPERATION:
		strcpy( String, "�A���t�@ �`���l���ɑ΂��Ďw�肳��Ă���e�N�X�`�� �u�����f�B���O�������A�f�o�C�X���T�|�[�g���Ă��Ȃ��B" );
		break;
	case D3DERR_UNSUPPORTEDCOLORARG:
		strcpy( String, "�J���[�l�ɑ΂��Ďw�肳��Ă���e�N�X�`�� �u�����f�B���O�������A�f�o�C�X���T�|�[�g���Ă��Ȃ��B" );
		break;
	case D3DERR_UNSUPPORTEDCOLOROPERATION:
		strcpy( String, "�J���[�l�ɑ΂��Ďw�肳��Ă���e�N�X�`�� �u�����f�B���O�������A�f�o�C�X���T�|�[�g���Ă��Ȃ��B" );
		break;
	case D3DERR_UNSUPPORTEDFACTORVALUE:
		strcpy( String, "�f�o�C�X���w�肳�ꂽ�e�N�X�`���W���l���T�|�[�g���Ă��Ȃ��B" );
		break;
	case D3DERR_UNSUPPORTEDTEXTUREFILTER:
		strcpy( String, "�f�o�C�X���w�肳�ꂽ�e�N�X�`�� �t�B���^���T�|�[�g���Ă��Ȃ��B" );
		break;
	case D3DERR_WRONGTEXTUREFORMAT:
		strcpy( String, "�e�N�X�`�� �T�[�t�F�X�̃s�N�Z�� �t�H�[�}�b�g���L���łȂ��B" );
		break;
	case E_FAIL:
		strcpy( String, "Direct3D �T�u�V�X�e�����Ō����s���̃G���[�����������B" );
		break;
	case E_INVALIDARG:
		strcpy( String, "�����ȃp�����[�^���߂��Ă���֐��ɓn���ꂽ�B" );
		break;
	case E_OUTOFMEMORY:
		strcpy( String, "Direct3D ���Ăяo�����������邽�߂̏\���ȃ����������蓖�Ă邱�Ƃ��ł��Ȃ������B" );
		break;
	case D3DXERR_CANNOTATTRSORT:
		strcpy( String, "�œK���e�N�j�b�N�Ƃ��đ����̃\�[�g (D3DXMESHOPT_ATTRSORT) �̓T�|�[�g����Ă��Ȃ��B " );
		break;
	case D3DXERR_CANNOTMODIFYINDEXBUFFER:
		strcpy( String, "�C���f�b�N�X �o�b�t�@��ύX�ł��Ȃ��B " );
		break;
	case D3DXERR_INVALIDMESH:
		strcpy( String, "���b�V���������ł���B " );
		break;
	case D3DXERR_SKINNINGNOTSUPPORTED:
		strcpy( String, "�X�L�j���O�̓T�|�[�g����Ă��Ȃ��B " );
		break;
	case D3DXERR_TOOMANYINFLUENCES:
		strcpy( String, "�w�肳�ꂽ�e������������B " );
		break;
	case D3DXERR_INVALIDDATA:
		strcpy( String, "�f�[�^�������ł���B" );
		break;
	default:
		strcpy( String, "���m�̃G���[�B" );
		break;
	}

	return String;
}

//=============================================================================
/**
	��ʃ��[�h���̎擾�����܂�

	@param IsFullColor	[in] �t���J���[��ʂ��ǂ���

	@return		���[�h��
*/
//=============================================================================
Sint32 Luna3D::GetScreenModeCount( Bool IsFullColor )
{
	Sint32 Count = 0;

	if ( IsFullColor )
	{
		for ( Sint32 i = 0; i < m_AdapterData.ModeCount; i++ )
		{
			if ( m_AdapterData.Mode[i].Format == m_FullScreenMode[1].Format )
			{
				Count++;
			}
		}
	}
	else
	{
		for ( Sint32 i = 0; i < m_AdapterData.ModeCount; i++ )
		{
			if ( m_AdapterData.Mode[i].Format == m_FullScreenMode[0].Format )
			{
				Count++;
			}
		}
	}

	return Count;
}

//=============================================================================
/**
	��ʃ��[�h�̎擾�����܂�

	@param IsFullColor	[in] �t���J���[��ʂ��ǂ���
	@param No			[in] ��ʃT�C�Y�ԍ�
	@param pWidth		[out] ��ʉ���
	@param pHeight		[out] ��ʏc��

*/
//=============================================================================
void Luna3D::GetScreenMode( Bool IsFullColor, Sint32 No, Sint32 *pWidth, Sint32 *pHeight )
{
	if ( IsFullColor )
	{
		for ( Sint32 i = 0; i < m_AdapterData.ModeCount; i++ )
		{
			if ( m_AdapterData.Mode[i].Format == m_FullScreenMode[1].Format )
			{
				if ( No-- == 0 )
				{
					*pWidth = m_AdapterData.Mode[i].Width;
					*pHeight = m_AdapterData.Mode[i].Height;
					return;
				}
			}
		}
	}
	else
	{
		for ( Sint32 i = 0; i < m_AdapterData.ModeCount; i++ )
		{
			if ( m_AdapterData.Mode[i].Format == m_FullScreenMode[0].Format )
			{
				if ( No-- == 0 )
				{
					*pWidth = m_AdapterData.Mode[i].Width;
					*pHeight = m_AdapterData.Mode[i].Height;
					return;
				}
			}
		}
	}

	*pWidth = 0;
	*pHeight = 0;
}

//=============================================================================
/**
	�����_�����O�^�[�Q�b�g�e�N�X�`���T�C�Y���̎擾�����܂�

    @return		�e�N�X�`���T�C�Y��
*/
//=============================================================================
Sint32 Luna3D::GetRenderTargetTextureSizeCount( void )
{
	Sint32 Count = 0;

	if ( m_DeviceInfo.MaxTextureWidth <  m_DeviceInfo.MaxTextureHeight )
	{
		for ( Uint32 i = 32; i <= m_DeviceInfo.MaxTextureWidth; i <<= 1 ) Count++;
	}
	else
	{
		for ( Uint32 i = 32; i <= m_DeviceInfo.MaxTextureHeight; i <<= 1 ) Count++;
	}

	return Count;
}

//=============================================================================
/**
	�����_�����O�^�[�Q�b�g�e�N�X�`���T�C�Y�̎擾�����܂�

	@param No			[in] ��ʃT�C�Y�ԍ�
	@param pWidth		[out] ��ʉ���
	@param pHeight		[out] ��ʏc��

*/
//=============================================================================
void Luna3D::GetRenderTargetTextureSize( Sint32 No, Sint32 *pWidth, Sint32 *pHeight )
{
	Sint32 Count = 0;

	if ( m_DeviceInfo.MaxTextureWidth <  m_DeviceInfo.MaxTextureHeight )
	{
		for ( Uint32 i = 32; i <= m_DeviceInfo.MaxTextureWidth; i <<= 1 )
		{
			if ( Count++ == No )
			{
				*pWidth = *pHeight = i;
				return;
			}
		}
	}
	else
	{
		for ( Uint32 i = 32; i <= m_DeviceInfo.MaxTextureHeight; i <<= 1 )
		{
			if ( Count++ == No )
			{
				*pWidth = *pHeight = i;
				return;
			}
		}
	}

	*pWidth = *pHeight = 0;
}

//=============================================================================
/**
	�A�_�v�^�[���̎擾�����܂�

	@param pName	[out] �擾����������̊i�[��

*/
//=============================================================================
void Luna3D::GetAdapterName( char *pName )
{
	strcpy( pName, m_AdapterName );
}

//=============================================================================
/**
	�A�_�v�^�[�h���C�o�[�̎擾�����܂�

	@param pName	[out] �擾����������̊i�[��

*/
//=============================================================================
void Luna3D::GetAdapterDriver( char *pName )
{
	strcpy( pName, m_AdapterDriver );
}

//=============================================================================
/**
	�A�_�v�^�[�h���C�o�[�o�[�W�����̎擾�����܂�

	@param pName	[out] �擾����������̊i�[��

*/
//=============================================================================
void Luna3D::GetAdapterVersion( char *pName )
{
	strcpy( pName, m_AdapterVersion );
}

//=============================================================================
/**
	�_�C�A���O�{�b�N�X���[�h���g�p���邩�ǂ���

	@param IsMode	[in] �g�p���邩�ۂ�

*/
//=============================================================================
void Luna3D::SetDialogMode( Bool IsMode )
{
	if ( m_pDevice != NULL )
	{
		m_pDevice->SetDialogBoxMode( IsMode );
	}
}

//=============================================================================
/**
	�f�t�H���g�̃��f���}�e���A���X�e�[�g���擾

	@param pState	[in] �X�e�[�g

*/
//=============================================================================
void Luna3D::GetDefaultMateriaState( MATERIALSTATE *pState )
{
	*pState = m_DefaultState;
}

//=============================================================================
/**
	�f�t�H���g�̃��f���}�e���A���X�e�[�g���擾

	@param pState	[in] �X�e�[�g

*/
//=============================================================================
void Luna3D::SetMateriaRenderState( MATERIALSTATE *pState )
{
	Luna3D::SetBlendingType( pState->BlendType );
	Luna3D::SetBilinearEnable( pState->IsBilinear );
	Luna3D::SetColorkeyEnable( pState->IsColorKey );
	Luna3D::SetZBufferEnable( pState->IsZBuffer );
	Luna3D::SetZWriteEnable( pState->IsZWrite );

	for ( Uint32 i = 0; i < TEXTURE_STAGE_MAX; i++ )
	{
		for ( Uint32 j = 0; j < TextureStateTblCount; j++ )
		{
			Luna3D::SetTextureState( i, TextureStateTbl[j], pState->TextureState[i][TextureStateTbl[j]] );
		}

		for ( Uint32 j = 0; j < SamplerStateTblCount; j++ )
		{
			Luna3D::SetSamplerState( i, SamplerStateTbl[j], pState->SamplerState[i][SamplerStateTbl[j]] );
		}
	}
}

