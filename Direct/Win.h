#include <d3d9.h>
#include "Direct.h"
#include "MouseManager.h"
#include "StateManager.h"

#define WndWidth		810	// 화면의 가로 사이즈
#define WndHeight		835	// 화면의 세로 사이즈
#pragma comment(lib,"d3d9.lib")
#pragma once

class CWin
{
public:
	CWin(void);
	~CWin(void);
	static LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void Loop();
	void Init();
	void Process();
	HWND GetHWnd();

private:
	LPDIRECT3D9				m_pD3D;		// D3D 디바이스를 생성할 D3D 객체 변수
	LPDIRECT3DDEVICE9		m_pd3dDevice;		// 렌더링에 사용될 D3D 디바이스
	WNDCLASSEX wc;
	HWND m_hWnd;
	CStateManager* m_State;
};