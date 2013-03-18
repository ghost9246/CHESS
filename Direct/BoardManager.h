#pragma once
#include "Draw.h"
#include "Direct.h"
#include "UnitManager.h"

class CBoardManager
{
public:
	CBoardManager(void);
	~CBoardManager(void);
	void SetUnitManager(CUnitManager *newManager);
	void DrawBoard();
	void DrawUnit();
	void DrawInfoRect();
	void SetGameMode(int gameMode);

private:
	CUnitManager *m_pUnitManager;
	int m_iGameMode;
};