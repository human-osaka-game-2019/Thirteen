#include"Texture.h"
#include"SceneSwitch.h"

MapChipData chipdata;
static LPDIRECT3DDEVICE9 pDevice;

// �e�N�X�`���ۑ��p�\����
struct TEXTUREDATA
{

	LPDIRECT3DTEXTURE9 pTexture;  // �e�N�X�`�����
	float Width;					// �e�N�X�`���̕�
	float Height;					// �e�N�X�`���̍���

};

static TEXTUREDATA** TextureData[MAXSCENE] = { 0 };

// �摜�ǂݍ��݊֐�
void LoadTexture(const char* file_name, int SelectScene, int  SelectTexture)
{
	HRESULT result = D3DXCreateTextureFromFile(pDevice, file_name, &TextureData[SelectScene][SelectTexture]->pTexture);

	if ((_D3DXERR)result == D3DXERR_INVALIDDATA)
	{
		OutputDebugString(TEXT("\n�e�N�X�`���t�@�C����������܂���\n"));
	}

}

