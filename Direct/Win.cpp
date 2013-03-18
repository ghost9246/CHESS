#include "Win.h"

CWin::CWin(void)
{
	m_pD3D=NULL;
	m_pd3dDevice=NULL;

	// ������ Ŭ���� ���
	wc.cbSize=sizeof(WNDCLASSEX);
	wc.style = CS_CLASSDC;
	wc.lpfnWndProc = CWin::MsgProc;
	wc.cbClsExtra = 0L;
	wc.cbWndExtra = 0L;
	wc.hInstance = GetModuleHandle(NULL);
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = TEXT("Chess");	
	wc.hIconSm = NULL;	
	RegisterClassEx(&wc);

	// ������ ����
	m_hWnd = CreateWindow(TEXT("Chess"), TEXT("Chess"), WS_OVERLAPPEDWINDOW, 100, 100, WndWidth, WndHeight, GetDesktopWindow(), NULL, wc.hInstance, NULL);
	ShowWindow(m_hWnd, SW_SHOWDEFAULT);
}

CWin::~CWin(void)
{
	UnregisterClass(TEXT("Chess"), wc.hInstance);
}

void CWin::Loop()
{
	MSG msg;
	while(GetMessage(&msg, NULL, 0, 0))
	{
		// �޽��� ť�� �޽����� ������ ó��
		if(PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Sleep(10);
			Process();
		}
	}
}

void CWin::Init()
{
	CDirect::GetInstance(m_hWnd)->Init();
	m_State = new CStateManager;
}

void CWin::Process()
{
	// ������ ��Draw
	m_State->SetXY(CMouseManager::GetInstance()->GetX(), CMouseManager::GetInstance()->GetY());

	CDirect::GetInstance()->BeginDraw();
	m_State->Run();
	CDirect::GetInstance()->EndDraw();
}

HWND CWin::GetHWnd()
{
	return m_hWnd;
}

// ������ ���ν���
LRESULT WINAPI CWin::MsgProc(HWND m_hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		break;

	case WM_MOUSEMOVE:
		CMouseManager::GetInstance()->GetMousePosition(LOWORD(lParam), HIWORD(lParam), false, m_hWnd);
		break;

	case WM_LBUTTONDOWN:
		CMouseManager::GetInstance()->GetMousePosition(LOWORD(lParam), HIWORD(lParam), true, m_hWnd);
		break;
	}
	return DefWindowProc(m_hWnd, msg, wParam, lParam);
}