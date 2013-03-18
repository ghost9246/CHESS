#pragma once
#include <time.h>
#include <stdlib.h>
#include "Draw.h"
#include "MouseManager.h"
#include "Prepare.h"
#include "Play.h"
#include "SoundManager.h"
#include "UnitManager.h"
#include "BoardManager.h"

class CStateManager
{
public:
	CStateManager(void);
	~CStateManager(void);
	void Run();
	void SetXY(int x, int y);
	void TurnSetting();

private:
	CBoardManager m_cBoard;
	CPrepare m_cPrepare;
	CPlay m_cPlay;
	CUnitManager *m_pUnitManager;
	int m_iGameType;			// 0: 시작안함, 1:클래식, 2:원거리, 3:전멸전
	int x;		// MouseManager로부터 받아올 클릭한 위치
	int y;
	int m_iTeam1;
	int m_iTeam2;
	bool m_bStarted;
	bool m_bTurn;			// true: 위쪽 턴
	bool m_bUnitSelected;
	bool m_bMouseType;
};

