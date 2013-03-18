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
	int m_iGameType;			// 0: ���۾���, 1:Ŭ����, 2:���Ÿ�, 3:������
	int x;		// MouseManager�κ��� �޾ƿ� Ŭ���� ��ġ
	int y;
	int m_iTeam1;
	int m_iTeam2;
	bool m_bStarted;
	bool m_bTurn;			// true: ���� ��
	bool m_bUnitSelected;
	bool m_bMouseType;
};

