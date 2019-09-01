#ifndef Texture_H
#define Texture_H

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



class Texture
{
public:

	void LoadTexture(const char* file_name, int SelectScene, int  SelectTexture);
};


#endif // !TEXTURE_H

