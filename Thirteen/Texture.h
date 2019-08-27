#ifndef Texture_H
#define Texture_H

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



class Texture
{
public:

	void LoadTexture(const char* file_name, int SelectScene, int  SelectTexture);
};


#endif // !TEXTURE_H

