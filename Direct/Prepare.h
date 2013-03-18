#pragma once
#include "MouseManager.h"
#include "Draw.h"
#include "SoundManager.h"
#include "UnitManager.h"

class CPrepare
{
public:
	CPrepare(void);
	~CPrepare(void);
	void GetMouseInfo();
	void ShowMenu();
	int DecideGameType();
	int SelectTeam1();
	int SelectTeam2();
	bool ShowStart();

private:
	int gameType;
	int x;
	int y;
	bool mouseType;
};

