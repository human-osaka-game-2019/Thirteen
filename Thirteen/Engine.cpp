#include "Window.h"
#include <Windows.h>
#include "Engine.h"
#include "Sound.h"

//　エンジンの初期化
BOOL InitEngine(int width, int height, HINSTANCE hInst)
{
	HWND hWnd;
	InitWnd window;

	if (window.m_MakeWnd(hInst, width, height) == false)
	{
		return FALSE;
	}

	return TRUE;
}

//　メモリを開放する
VOID EndEngine()
{

}