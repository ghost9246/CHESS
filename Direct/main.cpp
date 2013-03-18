#include <d3d9.h>
#include "Win.h"

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, INT)
{
	CWin win;
	win.Init();
	win.Loop();

	return 0;
}