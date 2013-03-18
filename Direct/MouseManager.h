#pragma once
#include <d3d9.h>

class CMouseManager
{
public:
	~CMouseManager(void);
	static CMouseManager* GetInstance();
	static CMouseManager* m_pMouseManager;
	void GetMousePosition(int x, int y, bool type, HWND hWnd);
	int GetX();
	int GetY();
	bool GetType();

private:
	CMouseManager(void);
	static int x;
	static int y;
	bool type;
};