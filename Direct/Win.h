#include <d3d9.h>
#include "Direct.h"
#include "MouseManager.h"
#include "StateManager.h"

#define WndWidth		810	// ȭ���� ���� ������
#define WndHeight		835	// ȭ���� ���� ������
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
	LPDIRECT3D9				m_pD3D;		// D3D ����̽��� ������ D3D ��ü ����
	LPDIRECT3DDEVICE9		m_pd3dDevice;		// �������� ���� D3D ����̽�
	WNDCLASSEX wc;
	HWND m_hWnd;
	CStateManager* m_State;
};