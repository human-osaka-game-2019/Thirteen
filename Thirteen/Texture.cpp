#include"Texture.h"
#include"SceneSwitch.h"
#include"MapchipData.h"

#include <d3d9.h>
#include <d3dx9.h>
#include <D3dx9tex.h>

MapChipData mapChipData;
static LPDIRECT3DDEVICE9 pDevice;

// テクスチャ保存用構造体
struct TEXTUREDATA
{

	LPDIRECT3DTEXTURE9 pTexture;  // テクスチャ情報
	float Width;					// テクスチャの幅
	float Height;					// テクスチャの高さ

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

// 画像読み込み関数
void Texture::LoadTexture(const char* file_name, int SelectScene, int  SelectTexture)
{
	HRESULT result = D3DXCreateTextureFromFile(pDevice, file_name, &TextureData[SelectScene][SelectTexture]->pTexture);

	if ((_D3DXERR)result == D3DXERR_INVALIDDATA)
	{
		OutputDebugString(TEXT("\nテクスチャファイルが見つかりません\n"));
	}

}

