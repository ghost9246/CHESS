#include "UnitManager.h"

CUnitManager::CUnitManager(void)
{
	m_iTeam1=m_iTeam2=0;
	m_bTmp=false;
}

CUnitManager::~CUnitManager(void)
{}

void CUnitManager::SetTeam1(int new_Team)
{
	m_iTeam1 = new_Team;
}

void CUnitManager::SetTeam2(int new_Team)
{
	m_iTeam2 = new_Team;
}

int CUnitManager::GetTeam1()
{
	return m_iTeam1;
}

int CUnitManager::GetTeam2()
{
	return m_iTeam2;
}

void CUnitManager::SetGameType(int m_iGameType)
{
	this->m_iGameType = m_iGameType;
}

void CUnitManager::Team1Setting()		// 유닛 체력 및 공격력 설정
{
	if(m_iGameType == 2)		// 원거리 모드일 경우 체력/공격력 설정
	{
		m_caBoard[0][0].SetDefault(2,3,3,m_iTeam1);		// 룩 체력 3, 공격력 3
		m_caBoard[7][0].SetDefault(2,3,3,m_iTeam1);
		m_caBoard[1][0].SetDefault(3,2,3,m_iTeam1);		// 나이트 체력 2, 공격력 3
		m_caBoard[6][0].SetDefault(3,2,3,m_iTeam1);
		m_caBoard[2][0].SetDefault(3,2,2,m_iTeam1);		// 비숍 체력 2, 공격력 2
		m_caBoard[5][0].SetDefault(3,2,2,m_iTeam1);
		m_caBoard[3][0].SetDefault(5,5,5,m_iTeam1);		// 킹 체력 5, 공격력 5
		m_caBoard[4][0].SetDefault(4,4,4,m_iTeam1);		// 퀸 체력 4, 공격력 4

		for(int x=0; x<8; x++)
			m_caBoard[x][1].SetDefault(1,1,5,m_iTeam1);	// 폰 체력 1, 공격력 5
	}
	else		// 원거리 모드 아니면 다 한방
	{
		int unitType = 2;
		for(int x=0; x<5;x++)
		{
			m_caBoard[x][0].SetDefault(unitType,1,1,m_iTeam1);

			if(x < 3)
				m_caBoard[7-x][0].SetDefault(unitType,1,1,m_iTeam1);

			unitType++;
		}

		for(int x=0; x<8; x++)
			m_caBoard[x][1].SetDefault(1,1,1,m_iTeam1);
	}
}

void CUnitManager::Team2Setting()
{
	if(m_iGameType == 2)		// 원거리 모드일 경우 체력/공격력 설정
	{
		m_caBoard[0][7].SetDefault(2,3,3,m_iTeam2);		// 룩 체력 3, 공격력 3
		m_caBoard[7][7].SetDefault(2,3,3,m_iTeam2);
		m_caBoard[1][7].SetDefault(3,2,3,m_iTeam2);		// 나이트 체력 2, 공격력 3
		m_caBoard[6][7].SetDefault(3,2,3,m_iTeam2);
		m_caBoard[2][7].SetDefault(3,2,2,m_iTeam2);		// 비숍 체력 2, 공격력 2
		m_caBoard[5][7].SetDefault(3,2,2,m_iTeam2);
		m_caBoard[3][7].SetDefault(5,5,5,m_iTeam2);		// 킹 체력 5, 공격력 5
		m_caBoard[4][7].SetDefault(4,4,4,m_iTeam2);		// 퀸 체력 4, 공격력 4

		for(int x=0; x<8; x++)
			m_caBoard[x][6].SetDefault(1,1,5,m_iTeam2);	// 폰 체력 1, 공격력 5
	}
	else
	{
		int unitType = 2;
		for(int x=0; x<5;x++)
		{
			m_caBoard[x][7].SetDefault(unitType,1,1,m_iTeam2);

			if(x < 3)
				m_caBoard[7-x][7].SetDefault(unitType,1,1,m_iTeam2);

			unitType++;
		}

		for(int x=0; x<8; x++)
			m_caBoard[x][6].SetDefault(1,1,1,m_iTeam2);
	}
}

bool CUnitManager::UnitSelected(int m_iTeam, int x, int y)
{
	x = (x-80)/80;
	y = (y-80)/80;
	int y2;

	if(m_caBoard[x][y].GetOwner() == m_iTeam)
	{
		m_iFrom_x = x;
		m_iFrom_y = y;
		for(int t=0; t<8; t++)
		{
			for(int t2=0; t2<8; t2++)
				m_iaMoveRange[t][t2] = 0;
		}

		switch(m_caBoard[x][y].GetType())
		{
		case 1:			// 폰
			CSoundManager::GetInstance()->Play(SD_PAWNSELECT,false);
			if(GetTeam1() == m_caBoard[x][y].GetOwner())		// 1팀
			{
				if(m_caBoard[x][y+1].GetOwner() == 0)
					m_iaMoveRange[x][y+1] = 1;

				if(y == 1 && m_caBoard[x][y+2].GetOwner() == 0)		// 폰 맨처음 두칸이동
					m_iaMoveRange[x][y+2] = 1;

				if(y+1 < 8)
				{
					if(x-1 >= 0)
					{
						if(m_caBoard[x-1][y+1].GetOwner() != 0 && m_caBoard[x-1][y+1].GetOwner() != m_iTeam)
							m_iaMoveRange[x-1][y+1] = 2;
					}
					if(x+1 < 8)
					{
						if(m_caBoard[x+1][y+1].GetOwner() != 0 && m_caBoard[x+1][y+1].GetOwner() != m_iTeam)
							m_iaMoveRange[x+1][y+1] = 2;
					}
				}

				DrawMoveRange(GetTeam1());
			}
			else		// 2팀
			{
				if(GetTeam2() == m_caBoard[x][y].GetOwner())
				{
					if(m_caBoard[x][y-1].GetOwner() == 0)
						m_iaMoveRange[x][y-1] = 1;

					if(y == 6 && m_caBoard[x][y-2].GetOwner() == 0)		// 폰 맨처음 두칸이동
						m_iaMoveRange[x][y-2] = 1;

					if(y-1 >= 0)
					{
						if(x-1 >= 0)
						{
							if(m_caBoard[x-1][y-1].GetOwner() != 0 && m_caBoard[x-1][y-1].GetOwner() != m_iTeam)
								m_iaMoveRange[x-1][y-1] = 2;
						}
						if(x+1 < 8)
						{
							if(m_caBoard[x+1][y-1].GetOwner() != 0 && m_caBoard[x+1][y-1].GetOwner() != m_iTeam)
								m_iaMoveRange[x+1][y-1] = 2;
						}
					}
				}
				DrawMoveRange(GetTeam2());
			}
			break;

		case 2:			// 룩
			CSoundManager::GetInstance()->Play(SD_RUCKSELECT,false);
			for(int t=y-1; t>=0; t--)		// ↑
			{
				if(m_caBoard[x][t].GetOwner() == 0)
					m_iaMoveRange[x][t] = 1;

				else
				{
					if(m_caBoard[x][t].GetOwner() != 0 && m_caBoard[x][t].GetOwner() != m_iTeam)
						m_iaMoveRange[x][t] = 2;
					break;
				}
			}
			for(int t=y+1; t<8; t++)		// ↓
			{
				if(m_caBoard[x][t].GetOwner() == 0)
					m_iaMoveRange[x][t] = 1;

				else
				{
					if(m_caBoard[x][t].GetOwner() != 0 && m_caBoard[x][t].GetOwner() != m_iTeam)
						m_iaMoveRange[x][t] = 2;
					break;
				}
			}
			for(int t=x-1; t>=0; t--)		// ←
			{
				if(m_caBoard[t][y].GetOwner() == 0)
					m_iaMoveRange[t][y] = 1;

				else
				{
					if(m_caBoard[t][y].GetOwner() != 0 && m_caBoard[t][y].GetOwner() != m_iTeam)
						m_iaMoveRange[t][y] = 2;
					break;
				}
			}
			for(int t=x+1; t<8; t++)		// →
			{
				if(m_caBoard[t][y].GetOwner() == 0)
					m_iaMoveRange[t][y] = 1;

				else
				{
					if(m_caBoard[t][y].GetOwner() != 0 && m_caBoard[t][y].GetOwner() != m_iTeam)
						m_iaMoveRange[t][y] = 2;
					break;
				}
			}
			
			DrawMoveRange(m_iTeam);
			break;

		case 3:			// 나이트
			CSoundManager::GetInstance()->Play(SD_KNIGHTSELECT,false);
			if(x-1 >= 0 && y-2 >= 0)
			{
				if(m_caBoard[x-1][y-2].GetOwner() != m_iTeam && m_caBoard[x-1][y-2].GetOwner() != 0)
					m_iaMoveRange[x-1][y-2] = 2;
				else if(m_caBoard[x-1][y-2].GetOwner() == 0)
					m_iaMoveRange[x-1][y-2] = 1;
			}
			if(x+1 < 8 && y-2 >= 0)
			{
				if(m_caBoard[x+1][y-2].GetOwner() != m_iTeam && m_caBoard[x+1][y-2].GetOwner() != 0)
					m_iaMoveRange[x+1][y-2] = 2;
				else if(m_caBoard[x+1][y-2].GetOwner() == 0)
					m_iaMoveRange[x+1][y-2] = 1;
			}
			if(x+2 < 8 && y-1 >= 0)
			{
				if(m_caBoard[x+2][y-1].GetOwner() != m_iTeam && m_caBoard[x+2][y-1].GetOwner() != 0)
					m_iaMoveRange[x+2][y-1] = 2;
				else if(m_caBoard[x+2][y-1].GetOwner() == 0)
					m_iaMoveRange[x+2][y-1] = 1;
			}
			if(x+2 < 8 && y+1 < 8)
			{
				if(m_caBoard[x+2][y+1].GetOwner() != m_iTeam && m_caBoard[x+2][y+1].GetOwner() != 0)
					m_iaMoveRange[x+2][y+1] = 2;
				else if(m_caBoard[x+2][y+1].GetOwner() == 0)
					m_iaMoveRange[x+2][y+1] = 1;
			}
			if(x+1 < 8 && y+2 < 8)
			{
				if(m_caBoard[x+1][y+2].GetOwner() != m_iTeam && m_caBoard[x+1][y+2].GetOwner() != 0)
					m_iaMoveRange[x+1][y+2] = 2;
				else if(m_caBoard[x+1][y+2].GetOwner() == 0)
					m_iaMoveRange[x+1][y+2] = 1;
			}
			if(x-1 >= 0 && y+2 < 8)
			{
				if(m_caBoard[x-1][y+2].GetOwner() != m_iTeam && m_caBoard[x-1][y+2].GetOwner() != 0)
					m_iaMoveRange[x-1][y+2] = 2;
				else if(m_caBoard[x-1][y+2].GetOwner() == 0)
					m_iaMoveRange[x-1][y+2] = 1;
			}
			if(x-2 >= 0 && y+1 < 8)
			{
				if(m_caBoard[x-2][y+1].GetOwner() != m_iTeam && m_caBoard[x-2][y+1].GetOwner() != 0)
					m_iaMoveRange[x-2][y+1] = 2;
				else if(m_caBoard[x-2][y+1].GetOwner() == 0)
					m_iaMoveRange[x-2][y+1] = 1;
			}
			if(x-2 >= 0 && y-1 >= 0)
			{
				if(m_caBoard[x-2][y-1].GetOwner() != m_iTeam && m_caBoard[x-2][y-1].GetOwner() != 0)
					m_iaMoveRange[x-2][y-1] = 2;
				else if(m_caBoard[x-2][y-1].GetOwner() == 0)
					m_iaMoveRange[x-2][y-1] = 1;
			}

			DrawMoveRange(m_iTeam);
			break;

		case 4:			// 비숍
			CSoundManager::GetInstance()->Play(SD_BISHOPSELECT,false);
			y2=y;
			for(int x2=x+1; x2<8; x2++)		// ↘
			{
				if(y2 == 7)
					break;
				else y2++;

				if(m_caBoard[x2][y2].GetOwner() == 0)
					m_iaMoveRange[x2][y2] = 1;

				else
				{
					if(m_caBoard[x2][y2].GetOwner() != 0 && m_caBoard[x2][y2].GetOwner() != m_iTeam)
						m_iaMoveRange[x2][y2] = 2;
					break;
				}
			}

			y2=y;
			for(int x2=x-1; x2>=0; x2--)		// ↙
			{
				if(y2 == 7)
					break;
				else y2++;

				if(m_caBoard[x2][y2].GetOwner() == 0)
					m_iaMoveRange[x2][y2] = 1;

				else
				{
					if(m_caBoard[x2][y2].GetOwner() != 0 && m_caBoard[x2][y2].GetOwner() != m_iTeam)
						m_iaMoveRange[x2][y2] = 2;
					break;
				}
			}

			y2=y;
			for(int x2=x-1; x2>=0; x2--)		// ↖
			{
				if(y2 == 0)
					break;
				else y2--;

				if(m_caBoard[x2][y2].GetOwner() == 0)
					m_iaMoveRange[x2][y2] = 1;

				else
				{
					if(m_caBoard[x2][y2].GetOwner() != 0 && m_caBoard[x2][y2].GetOwner() != m_iTeam)
						m_iaMoveRange[x2][y2] = 2;
					break;
				}
			}

			y2=y;
			for(int x2=x+1; x2<8; x2++)		// ↗
			{
				if(y2 == 0)
					break;
				else y2--;

				if(m_caBoard[x2][y2].GetOwner() == 0)
					m_iaMoveRange[x2][y2] = 1;

				else
				{
					if(m_caBoard[x2][y2].GetOwner() != 0 && m_caBoard[x2][y2].GetOwner() != m_iTeam)
						m_iaMoveRange[x2][y2] = 2;
					break;
				}
			}
			DrawMoveRange(m_iTeam);
			break;
			
		case 5:			// 퀸
			CSoundManager::GetInstance()->Play(SD_QUEENSELECT,false);
			for(int t=y-1; t>=0; t--)		// ↑
			{
				if(m_caBoard[x][t].GetOwner() == 0)
					m_iaMoveRange[x][t] = 1;

				else
				{
					if(m_caBoard[x][t].GetOwner() != 0 && m_caBoard[x][t].GetOwner() != m_iTeam)
						m_iaMoveRange[x][t] = 2;
					break;
				}
			}
			for(int t=y+1; t<8; t++)		// ↓
			{
				if(m_caBoard[x][t].GetOwner() == 0)
					m_iaMoveRange[x][t] = 1;

				else
				{
					if(m_caBoard[x][t].GetOwner() != 0 && m_caBoard[x][t].GetOwner() != m_iTeam)
						m_iaMoveRange[x][t] = 2;
					break;
				}
			}
			for(int t=x-1; t>=0; t--)		// ←
			{
				if(m_caBoard[t][y].GetOwner() == 0)
					m_iaMoveRange[t][y] = 1;

				else
				{
					if(m_caBoard[t][y].GetOwner() != 0 && m_caBoard[t][y].GetOwner() != m_iTeam)
						m_iaMoveRange[t][y] = 2;
					break;
				}
			}
			for(int t=x+1; t<8; t++)		// →
			{
				if(m_caBoard[t][y].GetOwner() == 0)
					m_iaMoveRange[t][y] = 1;

				else
				{
					if(m_caBoard[t][y].GetOwner() != 0 && m_caBoard[t][y].GetOwner() != m_iTeam)
						m_iaMoveRange[t][y] = 2;
					break;
				}
			}

			y2=y;
			for(int x2=x+1; x2<8; x2++)		// ↘
			{
				if(y2 == 7)
					break;
				else y2++;

				if(m_caBoard[x2][y2].GetOwner() == 0)
					m_iaMoveRange[x2][y2] = 1;

				else
				{
					if(m_caBoard[x2][y2].GetOwner() != 0 && m_caBoard[x2][y2].GetOwner() != m_iTeam)
						m_iaMoveRange[x2][y2] = 2;
					break;
				}
			}

			y2=y;
			for(int x2=x-1; x2>=0; x2--)		// ↙
			{
				if(y2 == 7)
					break;
				else y2++;

				if(m_caBoard[x2][y2].GetOwner() == 0)
					m_iaMoveRange[x2][y2] = 1;

				else
				{
					if(m_caBoard[x2][y2].GetOwner() != 0 && m_caBoard[x2][y2].GetOwner() != m_iTeam)
						m_iaMoveRange[x2][y2] = 2;
					break;
				}
			}

			y2=y;
			for(int x2=x-1; x2>=0; x2--)		// ↖
			{
				if(y2 == 0)
					break;
				else y2--;

				if(m_caBoard[x2][y2].GetOwner() == 0)
					m_iaMoveRange[x2][y2] = 1;

				else
				{
					if(m_caBoard[x2][y2].GetOwner() != 0 && m_caBoard[x2][y2].GetOwner() != m_iTeam)
						m_iaMoveRange[x2][y2] = 2;
					break;
				}
			}

			y2=y;
			for(int x2=x+1; x2<8; x2++)		// ↗
			{
				if(y2 == 0)
					break;
				else y2--;

				if(m_caBoard[x2][y2].GetOwner() == 0)
					m_iaMoveRange[x2][y2] = 1;

				else
				{
					if(m_caBoard[x2][y2].GetOwner() != 0 && m_caBoard[x2][y2].GetOwner() != m_iTeam)
						m_iaMoveRange[x2][y2] = 2;
					break;
				}
			}

			DrawMoveRange(m_iTeam);
			break;

		case 6:			// 킹
			CSoundManager::GetInstance()->Play(SD_KINGSELECT,false);
			for(int t1 = x-1; t1 <= x+1; t1++)
			{
				for(int t2 = y-1; t2 <= y+1; t2++)
				{
					if(t1 >= 0 && t1 < 8 && t2 >= 0 && t2 < 8)
					{
						if(m_caBoard[t1][t2].GetOwner() == 0)
							m_iaMoveRange[t1][t2] = 1;

						else
						{
							if(m_caBoard[t1][t2].GetOwner() != 0 && m_caBoard[t1][t2].GetOwner() != m_iTeam)
								m_iaMoveRange[t1][t2] = 2;
						}
					}
				}
			}
			DrawMoveRange(m_iTeam);
			break;
		}

		return true;
	}
	else return false;
}

void CUnitManager::DrawMoveRange(int m_iTeam)
{
	RECT move_size={0,0,80,80};
	D3DXVECTOR3* move_pos = new D3DXVECTOR3;
	move_pos->z = 0;

	for(int x=0; x<8; x++)
	{
		for(int y=0; y<8; y++)
		{
			if(m_iaMoveRange[x][y] != 0)
			{
				move_pos->x = (x+1)*80;
				move_pos->y = (y+1)*80;

				if(m_iaMoveRange[x][y] == 2)		// 공격
					CDraw::GetInstance()->Draw(CDirect::GetInstance()->GetTexture(UNIT_ATTACK), &move_size, move_pos, D3DCOLOR_XRGB(255,255,255));
				else
					CDraw::GetInstance()->Draw(CDirect::GetInstance()->GetTexture(UNIT_MOVE), &move_size, move_pos, D3DCOLOR_XRGB(255,255,255));

				m_bTmp=true;
			}
		}
	}
	delete move_pos;
}

bool CUnitManager::MoveUnit(int to_x, int to_y)
{
	to_x = (to_x-80)/80;
	to_y = (to_y-80)/80;
	bool result=false;

	if(m_iaMoveRange[to_x][to_y] == 1)		// 이동
	{
		switch(m_caBoard[m_iFrom_x][m_iFrom_y].GetType())
		{
		case 1:		// 폰
			CSoundManager::GetInstance()->Play(SD_PAWNMOVE,false);
			break;
		case 2:		// 룩
			CSoundManager::GetInstance()->Play(SD_RUCKMOVE,false);
			break;
		case 3:		// 나이트
			CSoundManager::GetInstance()->Play(SD_KNIGHTMOVE,false);
			break;
		case 4:		// 비숍
			CSoundManager::GetInstance()->Play(SD_BISHOPMOVE,false);
			break;
		case 5:		// 퀸
			CSoundManager::GetInstance()->Play(SD_QUEENMOVE,false);
			break;
		case 6:		// 킹
			CSoundManager::GetInstance()->Play(SD_KINGMOVE,false);
			break;
		}
		m_caBoard[to_x][to_y].SetAtk(m_caBoard[m_iFrom_x][m_iFrom_y].GetAtk());
		m_caBoard[to_x][to_y].SetHp(m_caBoard[m_iFrom_x][m_iFrom_y].GetHp());
		m_caBoard[to_x][to_y].SetOwner(m_caBoard[m_iFrom_x][m_iFrom_y].GetOwner());
		m_caBoard[to_x][to_y].SetType(m_caBoard[m_iFrom_x][m_iFrom_y].GetType());
		m_caBoard[m_iFrom_x][m_iFrom_y].SetAtk(0);
		m_caBoard[m_iFrom_x][m_iFrom_y].SetHp(0);
		m_caBoard[m_iFrom_x][m_iFrom_y].SetOwner(0);
		m_caBoard[m_iFrom_x][m_iFrom_y].SetType(0);
		result=true;

		for(int x=0; x<8; x++)
		{
			for(int y=0; y<8; y++)
				m_iaMoveRange[x][y] = 0;
		}
	}
	else if(m_iaMoveRange[to_x][to_y] == 2)		// 공격
	{
		m_caBoard[to_x][to_y].SetHp(m_caBoard[to_x][to_y].GetHp()-m_caBoard[m_iFrom_x][m_iFrom_y].GetAtk());		// 체력 감소

		if(m_caBoard[to_x][to_y].GetHp() <= 0)		// 피격자 체력 다 되면
		{
			switch(m_caBoard[to_x][to_y].GetType())
			{
			case 1:		// 폰
				CSoundManager::GetInstance()->Play(SD_PAWNDIE,false);
				break;
			case 2:		// 룩
				CSoundManager::GetInstance()->Play(SD_RUCKDIE,false);
				break;
			case 3:		// 나이트
				CSoundManager::GetInstance()->Play(SD_KNIGHTDIE,false);
				break;
			case 4:		// 비숍
				CSoundManager::GetInstance()->Play(SD_BISHOPDIE,false);
				break;
			case 5:		// 퀸
				CSoundManager::GetInstance()->Play(SD_QUEENDIE,false);
				break;
			case 6:		// 킹
				CSoundManager::GetInstance()->Play(SD_KINGDIE,false);
				break;
			}

			if(m_iGameType != 2)		// 원거리모드 아니면
			{
				m_caBoard[to_x][to_y].SetAtk(m_caBoard[m_iFrom_x][m_iFrom_y].GetAtk());
				m_caBoard[to_x][to_y].SetHp(m_caBoard[m_iFrom_x][m_iFrom_y].GetHp());
				m_caBoard[to_x][to_y].SetOwner(m_caBoard[m_iFrom_x][m_iFrom_y].GetOwner());
				m_caBoard[to_x][to_y].SetType(m_caBoard[m_iFrom_x][m_iFrom_y].GetType());
				m_caBoard[m_iFrom_x][m_iFrom_y].SetAtk(0);
				m_caBoard[m_iFrom_x][m_iFrom_y].SetHp(0);
				m_caBoard[m_iFrom_x][m_iFrom_y].SetOwner(0);
				m_caBoard[m_iFrom_x][m_iFrom_y].SetType(0);
			}
			else		// 원거리모드면
			{
				m_caBoard[to_x][to_y].SetAtk(0);
				m_caBoard[to_x][to_y].SetHp(0);
				m_caBoard[to_x][to_y].SetOwner(0);
				m_caBoard[to_x][to_y].SetType(0);
			}
		}
		result = true;

		for(int x=0; x<8; x++)
		{
			for(int y=0; y<8; y++)
				m_iaMoveRange[x][y] = 0;
		}
	}

	m_bTmp=false;
	return result;
}

bool CUnitManager::CheckAlive(int m_iTeam)
{
	for(int x=0; x<8; x++)
	{
		for(int y=0; y<8; y++)
		{
			if(m_caBoard[x][y].GetOwner() == m_iTeam && m_iGameType == 3)	// 전멸전 전용 처리
				return true;

			else if(m_caBoard[x][y].GetType() == 6 && m_caBoard[x][y].GetOwner() == m_iTeam && m_iGameType != 3)
				return true;
		}
	}
	return false;
}

int CUnitManager::GetUnitInfo(int x, int y)
{
	int result = 0;
	if(m_caBoard[x][y].GetOwner () != 0)
		result = m_caBoard[x][y].GetOwner()*10 + m_caBoard[x][y].GetType();

	return result;
}