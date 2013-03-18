#include "MouseManager.h"

CMouseManager* CMouseManager::m_pMouseManager = NULL;
int CMouseManager::x = 0;
int CMouseManager::y = 0;

CMouseManager::CMouseManager(void)
{}

CMouseManager::~CMouseManager(void)
{}

CMouseManager* CMouseManager::GetInstance()
{
	if (m_pMouseManager == NULL)
		m_pMouseManager = new CMouseManager;

	return m_pMouseManager;
}

void CMouseManager::GetMousePosition(int x, int y, bool type, HWND hWnd)
{
	this->x = x;
	this->y = y;
	this->type = type;
}

int CMouseManager::GetX()
{
	return x;
}

int CMouseManager::GetY()
{
	return y;
}

bool CMouseManager::GetType()
{
	return type;
}