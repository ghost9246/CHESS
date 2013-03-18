#pragma once
#include "Unit.h"
#include "Draw.h"
#include "MouseManager.h"
#include "SoundManager.h"

class CUnitManager
{
public:
	CUnitManager(void);
	~CUnitManager(void);
	void SetTeam1(int new_Team);
	void SetTeam2(int new_Team);
	void SetGameType(int m_iGameType);
	int GetTeam1();
	int GetTeam2();
	void Team1Setting();
	void Team2Setting();
	void DrawMoveRange(int m_iTeam);
	bool UnitSelected(int m_iTeam, int x, int y);
	bool MoveUnit(int to_x, int to_y);
	bool CheckAlive(int m_iTeam);
	int GetUnitInfo(int x, int y);

private:
	CUnit m_caBoard[8][8];		// 체스판
	int m_iaMoveRange[8][8];		// 유닛 이동범위 (0:이동불가, 1:이동가능, 2:공격)
	int m_iGameType;	// 게임 타입
	int m_iTeam1;		// 위쪽 플레이어 색깔 (1:흑, 2:백, 3:적, 4:청)
	int m_iTeam2;		// 아래쪽 플레이어 색깔;
	int m_iFrom_x;
	int m_iFrom_y;
	bool m_bTmp;
};