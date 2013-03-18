#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>
#include <tchar.h>
#include <iostream>

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"winmm.lib")

using namespace std;

inline RECT Rect(int iLeft, int iTop, int iRight, int iBottom)
{
	RECT rect;
	SetRect(&rect, iLeft, iTop, iRight, iBottom);
	return rect;
}

enum LeftRight
{
	LEFT = 0,
	RIGHT = 1
};