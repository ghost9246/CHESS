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
	CUnit m_caBoard[8][8];		// ü����
	int m_iaMoveRange[8][8];		// ���� �̵����� (0:�̵��Ұ�, 1:�̵�����, 2:����)
	int m_iGameType;	// ���� Ÿ��
	int m_iTeam1;		// ���� �÷��̾� ���� (1:��, 2:��, 3:��, 4:û)
	int m_iTeam2;		// �Ʒ��� �÷��̾� ����;
	int m_iFrom_x;
	int m_iFrom_y;
	bool m_bTmp;
};