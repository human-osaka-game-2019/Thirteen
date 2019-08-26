#include <windows.h>
#include "Window.h"


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, iMsg, wParam, lParam);
		break;
	}

	return 0;
}

HWND InitWnd::m_MakeWnd(HINSTANCE hInst, int width, int height)
{
	static char title_name[] = "Thirteen";
	WNDCLASSEX  wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInst;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = title_name;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (RegisterClassEx(&wndclass) == 0)
	{
		return 0;
	}

	HWND hInsT = CreateWindow(title_name, title_name,
		WS_OVERLAPPEDWINDOW, 0, 0, width, height, NULL, NULL,
		hInst, NULL);

	RECT rx; // ウィンドウ領域
	RECT cx; // クライアント領域
	GetWindowRect(hInsT, &rx);
	GetClientRect(hInsT, &cx);
	const int new_width = width + (rx.right - rx.left) - (cx.right - cx.left);
	const int new_height = height + (rx.bottom - rx.top) - (cx.bottom - cx.top);
	const int disp_width = GetSystemMetrics(SM_CXSCREEN);
	const int disp_height = GetSystemMetrics(SM_CYSCREEN);
	SetWindowPos(hInsT, NULL, (disp_width - new_width) / 2,
		(disp_height - new_height) / 2,
		new_width, new_height, SWP_SHOWWINDOW);


	ShowWindow(hInsT, SW_SHOW);
	UpdateWindow(hInsT);

	return hInsT;
}

