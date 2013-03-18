#pragma once
#include <stdlib.h>
#include "Draw.h"
#include "MouseManager.h"
#include "UnitManager.h"
#include "SoundManager.h"

class CPlay
{
public:
	CPlay(void);
	~CPlay(void);
	void GetMouseInfo();
	void SetTeam(int t1, int t2);
	void StartSetting(int team1, int team2, CUnitManager *unitManager, int gameType);
	void TurnSetting();
	int CheckAlive();
	void Run();
	void End(bool m_iTeam);

private:
	CUnitManager *m_pUnitManager;
	bool m_bTurn;
	int m_iGameType;
	int m_iTeam;
	int x;
	int y;
	bool m_bMouseType;
	bool m_bUnitSelected;
};