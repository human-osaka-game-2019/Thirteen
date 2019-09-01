#include"Texture.h"
#include"SceneSwitch.h"
#include"MapchipData.h"

#include <d3d9.h>
#include <d3dx9.h>
#include <D3dx9tex.h>

MapChipData mapChipData;
static LPDIRECT3DDEVICE9 pDevice;

// �e�N�X�`���ۑ��p�\����
struct TEXTUREDATA
{

	LPDIRECT3DTEXTURE9 pTexture;  // �e�N�X�`�����
	float Width;					// �e�N�X�`���̕�
	float Height;					// �e�N�X�`���̍���

};

void MapChipData::InputMapChipSize(float Height, float Width)
{
	MapChipHeight = Height;
	MapChipWidth = Width;
}

void MapChipData::InputTextureSize(float Height, float Width)
{
	Texture_Height = Height;
	Texture_Width = Width;
}

static TEXTUREDATA** TextureData[MAXSCENE] = { 0 };

// �摜�ǂݍ��݊֐�
void Texture::LoadTexture(const char* file_name, int SelectScene, int  SelectTexture)
{
	HRESULT result = D3DXCreateTextureFromFile(pDevice, file_name, &TextureData[SelectScene][SelectTexture]->pTexture);

	if ((_D3DXERR)result == D3DXERR_INVALIDDATA)
	{
		OutputDebugString(TEXT("\n�e�N�X�`���t�@�C����������܂���\n"));
	}

}

