#include"Texture.h"
#include"SceneSwitch.h"

MapChipData chipdata;
static LPDIRECT3DDEVICE9 pDevice;

// テクスチャ保存用構造体
struct TEXTUREDATA
{

	LPDIRECT3DTEXTURE9 pTexture;  // テクスチャ情報
	float Width;					// テクスチャの幅
	float Height;					// テクスチャの高さ

};

static TEXTUREDATA** TextureData[MAXSCENE] = { 0 };

// 画像読み込み関数
void LoadTexture(const char* file_name, int SelectScene, int  SelectTexture)
{
	HRESULT result = D3DXCreateTextureFromFile(pDevice, file_name, &TextureData[SelectScene][SelectTexture]->pTexture);

	if ((_D3DXERR)result == D3DXERR_INVALIDDATA)
	{
		OutputDebugString(TEXT("\nテクスチャファイルが見つかりません\n"));
	}

}

