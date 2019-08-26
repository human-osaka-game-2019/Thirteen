#include <Windows.h>
#include "Window.h"
#include "Engine.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	if (InitEngine((1280), (960), hInstance) == FALSE)
	{
		return 0;
	}

	while (TRUE)
	{
		MSG msg;
		//	ÉQÅ[ÉÄÉãÅ[Év
		ZeroMemory(&msg, sizeof(msg));

		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				
			}

		}

		return 0;
	}
	
}