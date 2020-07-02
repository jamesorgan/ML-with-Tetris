

//=============================================================================
// INCLUDE
//=============================================================================
#include "LunaBase.h"

#include "../LunaMain.h"
#include "../LunaFile.h"
#include "../Luna3D.h"

#include "LagLoader.h"
#include "Texture.h"

using namespace LibLuna;


//=============================================================================
/**
	@brief �R���X�g���N�^
*/
//=============================================================================
CTexture::CTexture( CBaseMgr *pMgr ) : CBaseSurface( pMgr )
{
	m_Pool					= D3DPOOL_DEFAULT;
	m_pTexture				= NULL;
	m_pBaseTexture			= NULL;
	m_IsMipmap				= false;
	m_IsAutoGenerateMipmap	= false;
}

//=============================================================================
/**
	@brief �f�X�g���N�^
*/
//=============================================================================
CTexture::~CTexture()
{
	SAFE_RELEASE( m_pBaseTexture );
	SAFE_RELEASE( m_pTexture );
}

//=============================================================================
/**
*/
//=============================================================================
Bool CTexture::CreateTextureFromImageInfo( void *pData, Uint32 Size, eSurfaceFormat Format, D3DCOLOR KeyColor, Bool IsMipmap )
{
	HRESULT hr;
	IDirect3DSurface9 *pSurface;
	D3DSURFACE_DESC Desc;
	Uint32 MipmapCount;

	//------------------------------------------------------------
	// �e�N�X�`���̕����擾
	//------------------------------------------------------------
	DEVICEINFORMATION Info;
	Luna3D::GetDeviceInformation( &Info );

	/* �ݏ攛��`�F�b�N */
	if ( Info.IsPow2 || ( !Info.IsPow2Conditional && ( Format == FORMAT_DXT1 || Format == FORMAT_DXT3 || Format == FORMAT_DXT5 || IsMipmap ) ) )
	{
		/* 2�̗ݏ攛�肠��A�܂��͏����t���ݏ攛�肠�� */
		for ( m_Width  = 1; m_Width  < m_ImageInfo.Width ; m_Width  <<= 1 );
		for ( m_Height = 1; m_Height < m_ImageInfo.Height; m_Height <<= 1 );
	}
	else
	{
		/* 2�̗ݏ攛��Ȃ� */
		m_Width  = m_ImageInfo.Width;
		m_Height = m_ImageInfo.Height;
	}

	/* �����`����`�F�b�N */
	if ( Info.IsSquareOnly )
	{
		if ( m_Width > m_Height )
		{
			m_Height = m_Width;
		}
		else
		{
			m_Width = m_Height;
		}
	}

	/* �傫������T�C�Y�̕␳ */
	if ( m_Width  > Info.MaxTextureWidth  ) m_Width  = Info.MaxTextureWidth;
	if ( m_Height > Info.MaxTextureHeight ) m_Height = Info.MaxTextureHeight;

	m_Format	= Luna3D::GetFormat( Format, m_ImageInfo.Format );
	m_IsMipmap	= IsMipmap;
	m_Pool		= D3DPOOL_MANAGED;

	//------------------------------------------------------------
	// �e�N�X�`���̐���
	//------------------------------------------------------------
	hr = GetDevice()->CreateTexture(
					m_Width,
					m_Height,
					IsMipmap ? 3 : 1,
					0,
					m_Format,
					D3DPOOL_MANAGED,
					&m_pTexture,
					NULL );
	if FAILED( hr )
	{
		Luna::LogoutError( "�e�N�X�`���̐����Ɏ��s���܂��� [ %d x %d ] [ %s ]", m_Width, m_Height, Luna3D::GetError(hr) );
		Luna::LogoutNextLine();
		SAFE_RELEASE( m_pTexture );
		return false;
	}

	//------------------------------------------------------------
	// �T�[�t�F�C�X�ɉ摜�ǂݍ���
	//------------------------------------------------------------
	MipmapCount = m_pTexture->GetLevelCount();
	for ( Uint32 i = 0; i < MipmapCount; i++ )
	{
		// �T�[�t�F�C�X�擾
		hr = m_pTexture->GetSurfaceLevel( i, &pSurface );
		if FAILED( hr )
		{
			Luna::LogoutError( "�T�[�t�F�C�X�̎擾�Ɏ��s���܂��� [ %s ]", Luna3D::GetError(hr) );
			Luna::LogoutNextLine();
			SAFE_RELEASE( m_pTexture );
			return false;
		}

		// �T�[�t�F�C�X���擾
		pSurface->GetDesc( &Desc );

		// �T�[�t�F�C�X�ɉ摜�f�[�^�ǂݍ���
		hr = LoadImageToBaseSurface( pSurface, pData, Size, m_ImageInfo.Width, m_ImageInfo.Height, KeyColor );
		if FAILED( hr )
		{
			Luna::LogoutError( "�摜�̓ǂݍ��݂Ɏ��s���܂��� [ %s ]", Luna3D::GetError(hr) );
			Luna::LogoutNextLine();
			SAFE_RELEASE( pSurface );
			SAFE_RELEASE( m_pTexture );
			return false;
		}

		SAFE_RELEASE( pSurface );
	}

	// ���O
	Luna::Logout( "SIZE [ %d x %d ] FORMAT [ %s ] MIPMAP [ %d ] : ", m_Width, m_Height, Luna3D::GetPixelFormat(m_Format), MipmapCount );

	// �e�N�X�`���X�V
	UpdateTexture();

	return true;
}

//=============================================================================
/**
*/
//=============================================================================
Bool CTexture::LoadImageFromMemory( void *pData, Uint32 Size, eSurfaceFormat Format, D3DCOLOR KeyColor, Bool IsMipmap )
{
	SAFE_RELEASE( m_pTexture );

	//--------------------------------------------------------
	// �摜�f�[�^���I�t�X�N���[���T�[�t�F�C�X�ɓǂݍ���
	//--------------------------------------------------------
	if ( !GetImageInfoFromMemory( pData, Size ) )
	{
		SAFE_RELEASE( m_pTexture );
		return false;
	}

	//--------------------------------------------------------
	// �e�N�X�`���𐶐�
	//--------------------------------------------------------
	if ( !CreateTextureFromImageInfo( pData, Size, Format, KeyColor, IsMipmap ) )
	{
		SAFE_RELEASE( m_pTexture );
		return false;
	}

	return true;
}

//=============================================================================
/**
*/
//=============================================================================
Bool CTexture::LoadImageFromFile( const char *pFileName, eSurfaceFormat Format, D3DCOLOR KeyColor, Bool IsMipmap )
{
	void *pData = NULL;
	Uint32 Size;

	SAFE_RELEASE( m_pTexture );

	//--------------------------------------------------------
	// �t�@�C������ǂݍ���
	//--------------------------------------------------------
	if ( !LunaFile::Load( pFileName, &pData, &Size ) )
	{
		SAFE_RELEASE( m_pTexture );
		MemGlobalFree( pData );
		Luna::LogoutError( "�t�@�C�����݂���܂���" );
		Luna::Logout( " : " );

		return false;
	}

	//--------------------------------------------------------
	// �摜�f�[�^���I�t�X�N���[���T�[�t�F�C�X�ɓǂݍ���
	//--------------------------------------------------------
	if ( !GetImageInfoFromMemory( pData, Size ) )
	{
		SAFE_RELEASE( m_pTexture );
		MemGlobalFree( pData );
		Luna::LogoutError( "�摜�f�[�^�̓W�J�Ɏ��s" );
		Luna::Logout( " : " );

		return false;
	}

	//--------------------------------------------------------
	// �e�N�X�`���𐶐�
	//--------------------------------------------------------
	if ( !CreateTextureFromImageInfo( pData, Size, Format, KeyColor, IsMipmap ) )
	{
		MemGlobalFree( pData );
		Luna::LogoutError( "�e�N�X�`���̐����Ɏ��s" );
		Luna::Logout( " : " );

		return false;
	}

	MemGlobalFree( pData );

	return true;
}

//=============================================================================
/**
*/
//=============================================================================
Bool CTexture::Create( Uint32 Width, Uint32 Height, eSurfaceFormat Format, Bool IsMipmap )
{
	HRESULT hr;
	DEVICEINFORMATION Info;

	Luna::LogoutKeyword( "CTexture::Create" );

	//------------------------------------------------------------
	// �C���[�W���
	//------------------------------------------------------------
	m_ImageInfo.Format		= Luna3D::GetFormat( Format, D3DFMT_UNKNOWN );
	m_ImageInfo.Width		= Width;
	m_ImageInfo.Height		= Height;
	m_Format				= Luna3D::GetFormat( Format, D3DFMT_UNKNOWN );
	m_IsAutoGenerateMipmap	= Luna3D::GetAutoGenerateMipmapEnable( m_Format, IsMipmap );
	m_IsMipmap				= m_IsAutoGenerateMipmap;
	m_Pool					= D3DPOOL_MANAGED;

	//------------------------------------------------------------
	// �e�N�X�`���̕����擾
	//------------------------------------------------------------
	for ( m_Width  = 1; m_Width  < m_ImageInfo.Width ; m_Width  <<= 1 );
	for ( m_Height = 1; m_Height < m_ImageInfo.Height; m_Height <<= 1 );

	Luna3D::GetDeviceInformation( &Info );
	while ( m_Width  > Info.MaxTextureWidth  ) m_Width  >>= 1;
	while ( m_Height > Info.MaxTextureHeight ) m_Height >>= 1;

	//------------------------------------------------------------
	// �e�N�X�`���̐���
	//------------------------------------------------------------
	hr = GetDevice()->CreateTexture(
					m_Width,
					m_Height,
					m_IsMipmap ? 0 : 1,
					m_IsAutoGenerateMipmap ? D3DUSAGE_AUTOGENMIPMAP : 0,
					m_Format,
					m_Pool,
					&m_pTexture,
					NULL );
	if FAILED( hr )
	{
		Luna::LogoutError( " �e�N�X�`���̐����Ɏ��s���܂��� [ %d x %d ] [ %s ]", m_Width, m_Height, Luna3D::GetError(hr) );
		Luna::LogoutNextLine();

		return false;
	}

	// ���O
	Luna::Logout( " : SIZE [ %d x %d ] FORMAT [ %s ] : ", m_Width, m_Height, Luna3D::GetPixelFormat(m_Format) );

	return true;
}

//=============================================================================
/**
*/
//=============================================================================
Bool CTexture::CreateEx( Uint32 Width, Uint32 Height, Uint32 Levels, Uint32 Usage, D3DFORMAT Format, D3DPOOL Pool )
{
	HRESULT hr;

	Luna::LogoutKeyword( "CTexture::CreateEx" );

	//------------------------------------------------------------
	// �C���[�W���
	//------------------------------------------------------------
	m_ImageInfo.Format		= Format;
	m_ImageInfo.Width		= Width;
	m_ImageInfo.Height		= Height;
	m_Width					= Width;
	m_Height				= Height;
	m_Format				= Format;
	m_SurfaceType			= ((Usage & D3DUSAGE_RENDERTARGET) != 0) ? SURFACE_TYPE_RENDERTARGET : SURFACE_TYPE_TEXTURE;
	m_IsAutoGenerateMipmap	= Luna3D::GetAutoGenerateMipmapEnable( m_Format, (Levels != 1) && ((Usage & D3DUSAGE_AUTOGENMIPMAP) != 0) );
	m_IsMipmap				= m_IsAutoGenerateMipmap;
	m_Pool					= Pool;

	//------------------------------------------------------------
	// �e�N�X�`���̐���
	//------------------------------------------------------------
	hr = GetDevice()->CreateTexture(
					Width,
					Height,
					Levels,
					Usage,
					m_Format,
					m_Pool,
					&m_pTexture,
					NULL );
	if FAILED( hr )
	{
		Luna::LogoutError( "�e�N�X�`���̐����Ɏ��s���܂��� [ %d x %d ] [ %s ]", m_Width, m_Height, Luna3D::GetError(hr) );
		Luna::LogoutNextLine();

		return false;
	}

	// ���O
	Luna::Logout( " : SIZE [ %d x %d ] FORMAT [ %s ] : ", m_Width, m_Height, Luna3D::GetPixelFormat(m_Format) );

	return true;
}

//=============================================================================
/**
*/
//=============================================================================
Bool CTexture::CreateRenderTarget( Uint32 Width, Uint32 Height, eSurfaceFormat Format, Bool IsMipmap )
{
	HRESULT hr;
	DEVICEINFORMATION Info;

	Luna::LogoutKeyword( "CTexture::CreateRenderTarget" );

	//------------------------------------------------------------
	// �C���[�W���
	//------------------------------------------------------------
	m_ImageInfo.Format		= Luna3D::GetFormat( Format, D3DFMT_UNKNOWN );
	m_ImageInfo.Width		= Width;
	m_ImageInfo.Height		= Height;
	m_Format				= Luna3D::GetFormat( Format, D3DFMT_UNKNOWN );
	m_SurfaceType			= SURFACE_TYPE_RENDERTARGET;
	m_IsAutoGenerateMipmap	= Luna3D::GetAutoGenerateMipmapEnable( m_Format, IsMipmap );
	m_IsMipmap				= m_IsAutoGenerateMipmap;
	m_Pool					= D3DPOOL_DEFAULT;

	//------------------------------------------------------------
	// �e�N�X�`���̕����擾
	//------------------------------------------------------------
	for ( m_Width  = 1; m_Width  < m_ImageInfo.Width ; m_Width  <<= 1 );
	for ( m_Height = 1; m_Height < m_ImageInfo.Height; m_Height <<= 1 );

	Luna3D::GetDeviceInformation( &Info );
	while ( m_Width  > Info.MaxTextureWidth  ) m_Width  >>= 1;
	while ( m_Height > Info.MaxTextureHeight ) m_Height >>= 1;

	//------------------------------------------------------------
	// �x�[�X�e�N�X�`������
	//------------------------------------------------------------
	hr = GetDevice()->CreateTexture(
					m_Width,
					m_Height,
					1,
					0,
					m_Format,
					D3DPOOL_SYSTEMMEM,
					&m_pBaseTexture,
					NULL );
	if FAILED( hr )
	{
		Luna::LogoutError( "�x�[�X�e�N�X�`���̐����Ɏ��s���܂��� [ %d x %d ] [ %s ]", m_Width, m_Height, Luna3D::GetError(hr) );
		Luna::LogoutNextLine();

		return false;
	}

	//------------------------------------------------------------
	// �e�N�X�`���̐���
	//------------------------------------------------------------
	hr = GetDevice()->CreateTexture(
					m_Width,
					m_Height,
					m_IsMipmap ? 0 : 1,
					m_IsAutoGenerateMipmap ? D3DUSAGE_RENDERTARGET|D3DUSAGE_AUTOGENMIPMAP : D3DUSAGE_RENDERTARGET,
					m_Format,
					D3DPOOL_DEFAULT,
					&m_pTexture,
					NULL );
	if FAILED( hr )
	{
		Luna::LogoutError( "�e�N�X�`���̐����Ɏ��s���܂��� [ %d x %d ] [ %s ]", m_Width, m_Height, Luna3D::GetError(hr) );
		Luna::LogoutNextLine();

		return false;
	}

	// ���O
	Luna::Logout( " : SIZE [ %d x %d ] FORMAT [ %s ] : ", m_Width, m_Height, Luna3D::GetPixelFormat(m_Format) );
	Luna::LogoutOK( "Success!" );
	Luna::LogoutNextLine();

	return true;
}

//=============================================================================
/**
*/
//=============================================================================
Bool CTexture::CreateFromFile( const char *pFileName, eSurfaceFormat Format, D3DCOLOR KeyColor, Bool IsMipmap )
{
	//--------------------------------------------------------------
	// �t�@�C������
	//--------------------------------------------------------------
	Luna::LogoutKeyword( "CTexture::CreateFromFile" );
	Luna::Logout( " : [ %s ] : ", pFileName );

	//--------------------------------------------------------------
	// �t�@�C����ǂݍ��݁A��������f�[�^���擾����
	//--------------------------------------------------------------
	if ( LoadImageFromFile( pFileName, Format, KeyColor, IsMipmap ) )
	{
		Luna::LogoutOK( "Success!" );
		Luna::LogoutNextLine();

		return true;
	}
	else
	{
		Luna::LogoutError( "Failed!" );
		Luna::LogoutNextLine();
	}

	return false;
}

//=============================================================================
/**
*/
//=============================================================================
Bool CTexture::CreateFromLAG( const char *pFileName, const char *pDataName, eSurfaceFormat Format, Bool IsMipmap )
{
	const char *pErr;
	CLagLoader LagLoad;

	Luna::LogoutKeyword( "CTexture::CreateFromLAG" );
	Luna::Logout( ": [ %s / %s ] : ", pFileName, pDataName );

	//--------------------------------------------------------------
	// �t�@�C�����擾
	//--------------------------------------------------------------
	pErr = LagLoad.Load( pFileName, pDataName );
	if ( pErr == NULL )
	{
		if ( LoadImageFromMemory( LagLoad.GetDataAddress(), LagLoad.GetDataSize(), Format, COLORKEY_DISABLE, IsMipmap ) )
		{
			LagLoad.Release();

			Luna::LogoutOK( "Success!" );
			Luna::LogoutNextLine();

			return true;
		}
		else
		{
			LagLoad.Release();

			Luna::LogoutError( "Failed!" );
			Luna::LogoutNextLine();
		}
	}
	else
	{
		Luna::LogoutError( "�t�@�C���̓ǂݍ��݂Ɏ��s���܂��� [ %s ]", pErr );
		Luna::LogoutNextLine();
		Luna::LogoutError( "Failed!" );
		Luna::LogoutNextLine();

		LagLoad.Release();
	}

	return false;
}

//=============================================================================
/**
*/
//=============================================================================
Bool CTexture::CreateFromMemory( void *pData, Uint32 Size, eSurfaceFormat Format, D3DCOLOR KeyColor, Bool IsMipmap )
{
	Luna::LogoutKeyword( "CTexture::CreateFromMemory" );

	//--------------------------------------------------------------
	// �e�N�X�`���ǂݍ���
	//--------------------------------------------------------------
	if ( LoadImageFromMemory( pData, Size, Format, KeyColor, IsMipmap ) )
	{
		Luna::LogoutOK( "Success!" );
		Luna::LogoutNextLine();

		return true;
	}
	else
	{
		Luna::LogoutError( "Failed!" );
		Luna::LogoutNextLine();
	}

	return false;
}


//=============================================================================
/**
*/
//=============================================================================
Bool CTexture::CreateFromRenderTarget( CTexture &Texture, Bool IsMipmap )
{
	IDirect3DSurface9 *pSurfDst, *pSurfSrc;
	HRESULT hr;

	//------------------------------------------------------------
	// �C���[�W���
	//------------------------------------------------------------
	m_ImageInfo				= Texture.m_ImageInfo;
	m_Width					= Texture.m_Width;
	m_Height				= Texture.m_Height;
	m_Format				= Texture.m_Format;
	m_IsAutoGenerateMipmap	= Luna3D::GetAutoGenerateMipmapEnable( m_Format, IsMipmap );
	m_IsMipmap				= m_IsAutoGenerateMipmap;
	m_Pool					= D3DPOOL_DEFAULT;

	//------------------------------------------------------------
	// �����_�����O�^�[�Q�b�g�i�[�p�e�N�X�`���̐���
	//------------------------------------------------------------
	hr = GetDevice()->CreateTexture(
					m_Width,
					m_Height,
					1,
					0,
					m_Format,
					D3DPOOL_SYSTEMMEM,
					&m_pBaseTexture,
					NULL );
	if FAILED( hr )
	{
		Luna::LogoutError( "�e�N�X�`���̐����Ɏ��s���܂��� [ %d x %d ] [ %s ]", m_Width, m_Height, Luna3D::GetError(hr) );
		Luna::LogoutNextLine();

		return false;
	}

	//------------------------------------------------------------
	// �e�N�X�`���̐���
	//------------------------------------------------------------
	hr = GetDevice()->CreateTexture(
					m_Width,
					m_Height,
					m_IsMipmap ? 0 : 1,
					m_IsAutoGenerateMipmap ? D3DUSAGE_AUTOGENMIPMAP : 0,
					m_Format,
					D3DPOOL_DEFAULT,
					&m_pTexture,
					NULL );
	if FAILED( hr )
	{
		Luna::LogoutError( "�e�N�X�`���̐����Ɏ��s���܂��� [ %d x %d ] [ %s ]", m_Width, m_Height, Luna3D::GetError(hr) );
		Luna::LogoutNextLine();

		return false;
	}

	//------------------------------------------------------------
	// �����_�����O�^�[�Q�b�g�̓��e���R�s�[
	//------------------------------------------------------------
	hr = Texture.m_pTexture->GetSurfaceLevel( 0, &pSurfSrc );
	if SUCCEEDED( hr )
	{
		hr = m_pBaseTexture->GetSurfaceLevel( 0, &pSurfDst );
		if SUCCEEDED( hr )
		{
			hr = GetDevice()->GetRenderTargetData( pSurfSrc, pSurfDst );
			SAFE_RELEASE( pSurfDst );
		}
		SAFE_RELEASE( pSurfSrc );
	}

	if FAILED( hr )
	{
		Luna::LogoutError( "�e�N�X�`���̃R�s�[�Ɏ��s���܂��� [ %s ]", Luna3D::GetError(hr) );
		Luna::LogoutNextLine();

		return false;
	}

	// �e�N�X�`���X�V
	UpdateTexture();

	// �~�b�v�}�b�v�X�V
	UpdateMipmap();

	// ���O
	Luna::Logout( " : SIZE [ %d x %d ] FORMAT [ %s ] : ", m_Width, m_Height, Luna3D::GetPixelFormat(m_Format) );

	return true;
}


//=============================================================================
/**
*/
//=============================================================================
void CTexture::Reset( void )
{
	if ( m_Pool == D3DPOOL_DEFAULT )
	{
		SAFE_RELEASE( m_pTexture );
	}
}

//=============================================================================
/**
*/
//=============================================================================
void CTexture::Restore( void )
{
	HRESULT hr = S_OK;

	switch ( m_SurfaceType )
	{
	case SURFACE_TYPE_RENDERTARGET:
		hr = GetDevice()->CreateTexture(
					m_Width,
					m_Height,
					m_IsMipmap ? 0 : 1,
					m_IsAutoGenerateMipmap ? D3DUSAGE_RENDERTARGET|D3DUSAGE_AUTOGENMIPMAP : D3DUSAGE_RENDERTARGET,
					m_Format,
					D3DPOOL_DEFAULT,
					&m_pTexture,
					NULL );
		break;

	case SURFACE_TYPE_TEXTURE:
		if ( m_Pool == D3DPOOL_DEFAULT )
		{
			hr = GetDevice()->CreateTexture(
						m_Width,
						m_Height,
						m_IsMipmap ? 0 : 1,
						m_IsAutoGenerateMipmap ? D3DUSAGE_AUTOGENMIPMAP : 0,
						m_Format,
						D3DPOOL_DEFAULT,
						&m_pTexture,
						NULL );

			UpdateTexture();
			UpdateMipmap();
		}
		break;
	}

	if FAILED( hr )
	{
		Luna::LogoutError( "�e�N�X�`���̐����Ɏ��s���܂��� [ %s ]", Luna3D::GetError(hr) );
		Luna::LogoutNextLine();
	}
}

//=============================================================================
/**
*/
//=============================================================================
Bool CTexture::LockRect( RECT *pRect, void **ppBites, Uint32 *pPitch, Uint32 *pWidth, Uint32 *pHeight, D3DFORMAT *pFormat )
{
	HRESULT hr;
	D3DLOCKED_RECT LockRect;

	if ( m_pTexture != NULL )
	{
		if ( m_IsLock )
		{
			Luna::LogoutError( "�e�N�X�`���͊��Ƀ��b�N����Ă��܂�" );
			Luna::LogoutNextLine();
		}
		else
		{
			// �����_�����O�^�[�Q�b�g�̏ꍇ�̓V�X�e���ɃR�s�|
			DownloadRenderTarget();

			if ( m_Pool == D3DPOOL_DEFAULT )
			{
				hr = m_pBaseTexture->LockRect( 0, &LockRect, pRect, 0 );
			}
			else
			{
				hr = m_pTexture->LockRect( 0, &LockRect, pRect, 0 );
			}

			if SUCCEEDED( hr )
			{
				m_IsLock = true;

				if ( pRect == NULL )
				{
					if ( pFormat != NULL ) *pFormat = m_Format;
					if ( pWidth  != NULL ) *pWidth  = m_Width;
					if ( pHeight != NULL ) *pHeight = m_Height;
					if ( ppBites != NULL ) *ppBites = LockRect.pBits;
					if ( pPitch  != NULL ) *pPitch  = LockRect.Pitch;
				}
				else
				{
					if ( pFormat != NULL ) *pFormat = m_Format;
					if ( pWidth  != NULL ) *pWidth  = pRect->right - pRect->left;
					if ( pHeight != NULL ) *pHeight = pRect->bottom - pRect->top;
					if ( ppBites != NULL ) *ppBites = LockRect.pBits;
					if ( pPitch  != NULL ) *pPitch  = LockRect.Pitch;
				}
			}
			else
			{
				Luna::LogoutError( "�e�N�X�`���̃��b�N�Ɏ��s���܂��� [ %s ]", Luna3D::GetError(hr) );
				Luna::LogoutNextLine();
			}
		}
	}

	return m_IsLock;
}


//=============================================================================
/**
*/
//=============================================================================
void CTexture::UnLockRect( void )
{
	if ( m_IsLock )
	{
		if ( m_Pool == D3DPOOL_DEFAULT )
		{
			m_pBaseTexture->UnlockRect( 0 );
		}
		else
		{
			m_pTexture->UnlockRect( 0 );
		}
		m_IsLock = false;
	}
}


//=============================================================================
/**
*/
//=============================================================================
Bool CTexture::StretchRect( RECT *pDstRect, CTexture *pSrcTex, RECT *pSrcRect, Bool IsUvToTexel )
{
	HRESULT hr;
	RECT Dst, Src;
	IDirect3DSurface9 *pSrcSurf = NULL;
	IDirect3DSurface9 *pDstSurf = NULL;

	GetSurface( &pDstSurf );
	pSrcTex->GetSurface( &pSrcSurf );

	if ( IsUvToTexel )
	{
		Dst.left   = pDstRect->left   * m_Width  / m_ImageInfo.Width;
		Dst.top    = pDstRect->top    * m_Height / m_ImageInfo.Height;
		Dst.right  = pDstRect->right  * m_Width  / m_ImageInfo.Width;
		Dst.bottom = pDstRect->bottom * m_Height / m_ImageInfo.Height;

		Src.left   = pSrcRect->left   * pSrcTex->m_Width  / pSrcTex->m_ImageInfo.Width;
		Src.top    = pSrcRect->top    * pSrcTex->m_Height / pSrcTex->m_ImageInfo.Height;
		Src.right  = pSrcRect->right  * pSrcTex->m_Width  / pSrcTex->m_ImageInfo.Width;
		Src.bottom = pSrcRect->bottom * pSrcTex->m_Height / pSrcTex->m_ImageInfo.Height;
	}
	else
	{
		Dst = *pDstRect;
		Src = *pSrcRect;
	}

	hr = GetDevice()->StretchRect( pSrcSurf, &Src, pDstSurf, &Dst, D3DTEXF_LINEAR );
	if FAILED( hr )
	{
		hr = GetDevice()->StretchRect( pSrcSurf, &Src, pDstSurf, &Dst, D3DTEXF_POINT );
		if FAILED( hr )
		{
			hr = GetDevice()->StretchRect( pSrcSurf, &Src, pDstSurf, &Dst, D3DTEXF_NONE );
		}
	}

	SAFE_RELEASE( pDstSurf );
	SAFE_RELEASE( pSrcSurf );

	return SUCCEEDED( hr );
}

//=============================================================================
/**
*/
//=============================================================================
void CTexture::UpdateTexture( void )
{
	if ( m_pTexture != NULL )
	{
		if ( m_pBaseTexture != NULL )
		{
			HRESULT hr;
			m_pTexture->AddDirtyRect( NULL );
			m_pBaseTexture->AddDirtyRect( NULL );
			hr = GetDevice()->UpdateTexture( m_pBaseTexture, m_pTexture );
			if FAILED( hr )
			{
				Luna::LogoutError( "UpdateTexture() �Ɏ��s���܂��� [ %s ]", Luna3D::GetError(hr) );
				Luna::LogoutNextLine();
			}
		}
	}
}

//=============================================================================
/**
*/
//=============================================================================
void CTexture::UpdateMipmap( void )
{
	if ( m_pTexture != NULL )
	{
		if ( m_IsAutoGenerateMipmap )
		{
			// �~�b�v�}�b�v�̍X�V
			m_pTexture->GenerateMipSubLevels();
		}
	}
}

//=============================================================================
/**
*/
//=============================================================================
void CTexture::GetInstance( IDirect3DTexture9 **ppTexture )
{
	if ( m_pTexture != NULL )
	{
		*ppTexture = m_pTexture;
		m_pTexture->AddRef();
	}
	else
	{
		*ppTexture = NULL;
	}
}

//=============================================================================
/**
*/
//=============================================================================
void CTexture::GetBaseInstance( IDirect3DTexture9 **ppTexture )
{
	if ( m_pBaseTexture != NULL )
	{
		*ppTexture = m_pBaseTexture;
		m_pBaseTexture->AddRef();
	}
	else
	{
		*ppTexture = NULL;
	}
}

//=============================================================================
/**
*/
//=============================================================================
void CTexture::GetSurface( IDirect3DSurface9 **ppSurface )
{
	if ( m_pTexture != NULL )
	{
		m_pTexture->GetSurfaceLevel( 0, ppSurface );
	}
	else
	{
		*ppSurface = NULL;
	}
}

//=============================================================================
/**
*/
//=============================================================================
void CTexture::GetBaseSurface( IDirect3DSurface9 **ppSurface )
{
	if ( m_pBaseTexture != NULL )
	{
		m_pBaseTexture->GetSurfaceLevel( 0, ppSurface );
	}
	else
	{
		*ppSurface = NULL;
	}
}

//=============================================================================
/**
*/
//=============================================================================
Float CTexture::PixelToTexelU( Float fParam )
{
	return fParam / toF(m_ImageInfo.Width);
}

//=============================================================================
/**
*/
//=============================================================================
Float CTexture::PixelToTexelV( Float fParam )
{
	return fParam / toF(m_ImageInfo.Height);
}

//=============================================================================
/**
*/
//=============================================================================
Bool CTexture::SaveToFile( const char *pFileName, D3DXIMAGE_FILEFORMAT Format )
{
	if ( m_pTexture != NULL )
	{
		// �����_�����O�^�[�Q�b�g�̏ꍇ�̓V�X�e���ɃR�s�|
		DownloadRenderTarget();

		// �ۑ�
		HRESULT hr;
		hr = ::D3DXSaveTextureToFile(
					pFileName,
					Format,
					m_pBaseTexture,
					NULL );
		return SUCCEEDED( hr );
	}

	return false;
}

//=============================================================================
/**
*/
//=============================================================================
Bool CTexture::DownloadRenderTarget( void )
{
	HRESULT hr;
	IDirect3DSurface9 *pSrcSurf;
	IDirect3DSurface9 *pDstSurf;

	if ( m_pTexture == NULL ) return false;
	if ( m_pBaseTexture == NULL ) return false;
	if ( m_SurfaceType != SURFACE_TYPE_RENDERTARGET ) return false;

	hr = m_pTexture->GetSurfaceLevel( 0, &pSrcSurf );
	if FAILED( hr )
	{
		Luna::LogoutError( "�T�[�t�F�C�X�̎擾�Ɏ��s [%s]", Luna3D::GetError(hr) );
		Luna::LogoutNextLine();
		return false;
	}
	else
	{
		hr = m_pBaseTexture->GetSurfaceLevel( 0, &pDstSurf );
		if FAILED( hr )
		{
			Luna::LogoutError( "�T�[�t�F�C�X�̎擾�Ɏ��s [%s]", Luna3D::GetError(hr) );
			Luna::LogoutNextLine();
			SAFE_RELEASE( pSrcSurf );
			return false;
		}
		else
		{
			hr = GetDevice()->GetRenderTargetData( pSrcSurf, pDstSurf );
			if FAILED( hr )
			{
				Luna::LogoutError( "�e�N�X�`���̃R�s�[�����Ɏ��s [%s]", Luna3D::GetError(hr) );
				Luna::LogoutNextLine();
				SAFE_RELEASE( pSrcSurf );
				SAFE_RELEASE( pDstSurf );
				return false;
			}

			SAFE_RELEASE( pDstSurf );
		}

		SAFE_RELEASE( pSrcSurf );
	}

	return true;
}

//=============================================================================
/**
*/
//=============================================================================
bool CTexture::GetDC( HDC *pDC )
{
	HRESULT hr;
	IDirect3DSurface9 *pSurface;
	GetBaseSurface( &pSurface );
	hr = pSurface->GetDC( pDC );
	pSurface->Release();
	return SUCCEEDED( hr );
}

//=============================================================================
/**
*/
//=============================================================================
void CTexture::ReleaseDC( HDC hDC )
{
	HRESULT hr;
	IDirect3DSurface9 *pSurface;
	GetBaseSurface( &pSurface );
	hr = pSurface->ReleaseDC( hDC );
	pSurface->Release();
}

//=============================================================================
/**
*/
//=============================================================================
void CTexture::ColorFill( D3DCOLOR Color )
{
	void *pBits			= NULL;
	Uint32 Pitch		= 0;
	Uint32 Width		= 0;
	Uint32 Height		= 0;
	D3DFORMAT Format	= D3DFMT_UNKNOWN;

	Uint32 c = 0;
	Sint32 a = ((Color>>24)&0xFF);
	Sint32 r = ((Color>>16)&0xFF);
	Sint32 g = ((Color>> 8)&0xFF);
	Sint32 b = ((Color>> 0)&0xFF);

	if ( LockRect( NULL, &pBits, &Pitch, &Width, &Height, &Format ) )
	{
		switch ( Format )
		{
		case D3DFMT_R5G6B5:
			r >>= 3;
			g >>= 2;
			b >>= 3;
			c = (r<<11) | (g<<5) | b;
			c |= c << 16;
			break;
		case D3DFMT_X1R5G5B5:
		case D3DFMT_A1R5G5B5:
			a = (a > 127) ? (1) : (0);
			r >>= 3;
			g >>= 3;
			b >>= 3;
			c = (a<<15) | (r<<10) | (g<<5) | b;
			c |= c << 16;
			break;
		case D3DFMT_X4R4G4B4:
		case D3DFMT_A4R4G4B4:
			a >>= 4;
			r >>= 4;
			g >>= 4;
			b >>= 4;
			c = (a<<12) | (r<<8) | (g<<4) | b;
			c |= c << 16;
			break;
		case D3DFMT_X8R8G8B8:
		case D3DFMT_A8R8G8B8:
			c = Color;
			break;
		}

		// �s�N�Z���h��Ԃ�
		Uint32 *p = (Uint32 *)pBits;
		Sint32 size = Height * (Pitch / 4);
		while ( size-- ) p[size] = c;

		UnLockRect();

		UpdateTexture();
		UpdateMipmap();
	}
}

//=============================================================================
/**
*/
//=============================================================================
Bool CTexture::SetRenderTarget( void )
{
	Bool bRet = false;

	// �f�o�C�X�擾
	IDirect3DDevice9 *pDevice;
	if SUCCEEDED( m_pTexture->GetDevice( &pDevice ) )
	{
		// �T�[�t�F�C�X�擾
		IDirect3DSurface9 *pSurface;
		GetSurface( &pSurface );

		// �����_�����O�^�[�Q�b�g�ݒ�
		if SUCCEEDED( pDevice->SetRenderTarget( 0, pSurface ) )
		{
			bRet = true;
		}

		pSurface->Release();
		pDevice->Release();
	}

	return bRet;
}

//=============================================================================
/**
*/
//=============================================================================
Bool CTexture::SetDepthStencil( void )
{
	return false;
}


