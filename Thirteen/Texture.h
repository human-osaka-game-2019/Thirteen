#ifndef DRAW_H
#define DRAW_H

#include <d3d9.h>
#include <d3dx9.h>
#include <D3dx9tex.h>


typedef struct
{
	float	// 頂点座標
		x,  // 幅
		y,  // 高さ
		z;  // 奥行

	float   // 除算数
		rhw;

	float   // テクスチャ座標
		tu,  // 幅
		tv;	// 高さ
} CUSTOMVERTEX, * P_CUSTOMVERTEX;

class MapChipData
{
public:
	const int Map_HeightNumber = 10;
	const int Map_WidhtNumber = 10;

	float MapChipHeight;
	float MapChipWidht;
	void InputChipSize(int Height, int Widht)
	{
		MapChipHeight = Height;
		MapChipWidht = Widht;
	}

	float Texture_Height;
	float Texture_Widht;
	void InputTextureSize(int Height, int Widht)
	{
		Texture_Height = Height;
		Texture_Widht = Widht;
	}

	float x;
	float y;
	float chip_x;
	float chip_y;
};

#endif // !DRAW_H

