#include"Draw.h"
#include"Scene.h"

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


// 描画関数　前処理、後処理作成必要
void Draw(float x, float y, float Texturewidth, float Textureheight, float tu, float tv, float tu_width, float tv_height, TEXTUREDATA* TextureData)
{

	CUSTOMVERTEX customvertex[4] = {
	{x               ,y                ,0,1,tu      ,tv         },
	{x + Texturewidth,y                ,0,1,tu_width,tv         },
	{x + Texturewidth,y + Textureheight,0,1,tu_width,tv_height  },
	{x               ,y + Textureheight,0,1,tu      ,tv_height  },
	};  

	pDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_TEX1);
	pDevice->SetTexture(0,TextureData->pTexture);
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, customvertex, sizeof(CUSTOMVERTEX));

}

//	リリース(開放)関数
void TextureRelease(int SelectScene,int MaxTexture)
{
	for (int a = 0; a < MaxTexture; a++)
	{
	    TextureData[SelectScene][a]->pTexture->Release();
		TextureData[SelectScene][a]->pTexture = nullptr;
	}
}

//画像描画
////////////////////////////////////////////////////////////////////////////////////////////////////////
//マップチップ描画

void DrawMap(MapChipData MapData,TEXTUREDATA* TextureData)
{
	float cy = MapData.chip_y / MapData.Texture_Height;// 高さ
	float cx = MapData.chip_x / MapData.Texture_Widht; // 横
	float cx_size = MapData.MapChipWidht / MapData.Texture_Widht;
	float cy_size = MapData.MapChipHeight / MapData.Texture_Height;

	float cu_add = cx + cx_size;
	float cv_add = cy + cy_size;

	CUSTOMVERTEX sprite[] =
	{
		{ MapData.x                       , MapData.y                        , 0.0f, 1.0f,cx      ,cy      },
		{ MapData.x + MapData.MapChipWidht, MapData.y                        , 0.0f, 1.0f,cu_add  ,cy      },
		{ MapData.x + MapData.MapChipWidht, MapData.y + MapData.MapChipHeight, 0.0f, 1.0f,cu_add  ,cv_add  },
		{ MapData.x                       , MapData.y + MapData.MapChipHeight, 0.0f, 1.0f,cx      ,cv_add  },
	};

	pDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_TEX1);
	pDevice->SetTexture(0, TextureData->pTexture);
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, sprite, sizeof(CUSTOMVERTEX));
}

void DrawMapChip(MapChipData MapData, int MapChipList[10][10],TEXTUREDATA* TextureData)
{
	for (int i = 0; i < MapData.Map_HeightNumber; i++)
	{
		for (int j = 0; j < MapData.Map_WidhtNumber; j++)
		{
			int chip_id = MapChipList[i][j];
			if (chip_id == 0)
			{
				continue;
			}

			int width_num = MapData.Texture_Widht / MapData.MapChipWidht;
			int height_num = MapData.Texture_Height / MapData.MapChipHeight;

			float chip_pos_x = (float)((chip_id % width_num) * MapData.MapChipWidht);
			float chip_pos_y = (float)((chip_id / height_num) * MapData.MapChipHeight);

			// 描画する場所の指定 // 
			MapData.chip_x = chip_pos_x;
			MapData.chip_y = chip_pos_y;
			// チップ指定 //
			MapData.x = MapData.MapChipWidht * j;
			MapData.y = MapData.MapChipHeight * i;

			DrawMap(MapData,TextureData);

		}
	}
}