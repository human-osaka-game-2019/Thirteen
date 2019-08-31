#ifndef DRAW_H
#define DRAW_H

#include <d3d9.h>
#include <d3dx9.h>
#include <D3dx9tex.h>


typedef struct
{
	float	// ���_���W
		x,  // ��
		y,  // ����
		z;  // ���s

	float   // ���Z��
		rhw;

	float   // �e�N�X�`�����W
		tu,  // ��
		tv;	// ����
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

