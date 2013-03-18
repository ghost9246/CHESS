#include "StateManager.h"


CStateManager::CStateManager(void)
{
	m_iGameType=0;
	m_bTurn=m_bStarted=false;
	m_bUnitSelected=false;
	m_iTeam1=m_iTeam2=0;
	m_pUnitManager = new CUnitManager();
	m_cBoard.SetUnitManager(m_pUnitManager);
}

CStateManager::~CStateManager(void)
{}

void CStateManager::SetXY(int x, int y)
{
	this->x = x;
	this->y = y;
}

void CStateManager::Run()
{
	if(m_iGameType == 0)		// ����Ÿ�� ���� �ȵ�����
	{
		m_cPrepare.ShowMenu();
		m_iGameType = m_cPrepare.DecideGameType();
		m_cBoard.SetGameMode(m_iGameType);
	}

	else		// ���� ������
	{
		CSoundManager::GetInstance()->Play(SD_BGM,true);
		m_cBoard.DrawBoard();

		if(m_bStarted == false)
		{
			if(m_iTeam1 == 0 || m_iTeam2 == 0)		// ���� �ϳ��� ���� ��������
			{
				if(m_iTeam1 == 0)
				{
					m_iTeam1 = m_cPrepare.SelectTeam1();

					if(m_iTeam1 == m_iTeam2)		// �� �ߺ����� ����
						m_iTeam1 = 0;

					else
					{
						m_pUnitManager->SetTeam1(m_iTeam1);
						m_pUnitManager->Team1Setting();
					}
				}

				if(m_iTeam2 == 0)
				{
					m_iTeam2 = m_cPrepare.SelectTeam2();

					if(m_iTeam1 == m_iTeam2)		// �� �ߺ����� ����
						m_iTeam2 = 0;

					else
					{
						m_pUnitManager->SetTeam2(m_iTeam2);
						m_pUnitManager->Team2Setting();
					}
				}
			}
			else		// �Ѵ� ���� ������
			{
				if(m_cPrepare.ShowStart() == true)
				{
					m_cPlay.StartSetting(m_iTeam1, m_iTeam2, m_pUnitManager, m_iGameType);
					m_bStarted = true;
				}
			}
		}
		else
		{
			m_cBoard.DrawInfoRect();
			m_cPlay.Run();
		}

		m_cBoard.DrawUnit();
	}
}

void CStateManager::TurnSetting()
{
	if(x >= 250 && x < 555 && y >= 350 && y < 425)
	{
		m_bStarted = true;

		srand(time(NULL));		// �������� ù�� �������� ����
		int z=rand()%2;

		if(z == 0)
			m_bTurn = true;	// ���� ����
		else
			m_bTurn = false;	// �Ʒ��� ����
	}
}