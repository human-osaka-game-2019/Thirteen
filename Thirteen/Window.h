#ifndef WINDOW_H_ // => if not define
#define WINDOW_H_

#include <Windows.h>

#define WINDOW_CLASS_NAME "Thirteen"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

class InitWnd
{
public:
	HWND m_MakeWnd(HINSTANCE hInst, int width, int height);
	HWND m_OutputWindow(HWND* hWnd, HINSTANCE* hInstance, const TCHAR* API_NAME,
					  FLOAT* wnd_width, FLOAT* wnd_height);
};

#endif
