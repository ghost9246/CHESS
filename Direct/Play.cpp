#include "Play.h"


CPlay::CPlay(void)
{}

CPlay::~CPlay(void)
{}

void CPlay::GetMouseInfo()
{
	x=CMouseManager::GetInstance()->GetX();			// 마우스 클릭한 x,y위치 받아옴
	y=CMouseManager::GetInstance()->GetY();
	m_bMouseType = CMouseManager::GetInstance()->GetType();
}

void CPlay::SetTeam(int t1, int t2)
{
	m_pUnitManager->SetTeam1(t1);
	m_pUnitManager->SetTeam2(t2);
}

void CPlay::StartSetting(int team1, int team2, CUnitManager *unitManager, int gameType)
{
	m_pUnitManager=unitManager;
	m_pUnitManager->SetTeam1(team1);
	m_pUnitManager->SetTeam2(team2);
	m_pUnitManager->Team1Setting();
	m_pUnitManager->Team2Setting();
	m_pUnitManager->SetGameType(gameType);
	m_iGameType = gameType;

	int tmp=rand()%2;		// 첫 턴 누가 할지 설정
	if(tmp == 0)
		m_bTurn = true;
	else
		m_bTurn = false;
}

void CPlay::TurnSetting()
{
	RECT m_bTurnBar={0,0,80,80};
	int tmp;

	if(m_bTurn == true)		// 턴 설정
	{
		tmp = 80;
		m_iTeam = m_pUnitManager->GetTeam1();
	}
	else
	{
		tmp = 640;
		m_iTeam = m_pUnitManager->GetTeam2();
	}

	CDraw::GetInstance()->Draw(CDirect::GetInstance()->GetTexture(TURN_DISPLAY), &m_bTurnBar, &(D3DXVECTOR3(720,tmp,0)), D3DCOLOR_XRGB(255,255,255));
}

int CPlay::CheckAlive()
{
	if(m_pUnitManager->CheckAlive(m_pUnitManager->GetTeam1()) == false)		// 1p 패배
		return 1;

	else if(m_pUnitManager->CheckAlive(m_pUnitManager->GetTeam2()) == false)		// 2p 패배
		return 2;

	else return 0;
}

void CPlay::Run()
{
	if(CheckAlive() != 0)
	{
		if(CheckAlive() == false)
			End(true);
		else
			End(false);
	}
	else TurnSetting();

	GetMouseInfo();
	if(m_bMouseType == true)
	{
		if(m_pUnitManager->UnitSelected(m_iTeam, x, y) == true)
			m_bUnitSelected = true;

		if(m_bUnitSelected == true)
		{
			x=CMouseManager::GetInstance()->GetX();			// 마우스 클릭한 x,y위치 새로 받아옴
			y=CMouseManager::GetInstance()->GetY();
			m_bMouseType = CMouseManager::GetInstance()->GetType();

			if(m_pUnitManager->MoveUnit(x, y) == 1)
			{
				if(m_bTurn == true)
					m_bTurn=false;
				else
					m_bTurn=true;
			}
		}
		else m_bUnitSelected = false;
	}
	/*
	else		// 정보 사각형 그려주기. 일단 나중에 처리
	{
		if(x >= 80 && y >= 80 && x < 720 && y < 720)
		{
			RECT r_size={0, 0, 80, 80};
			D3DXVECTOR3* info_pos = new D3DXVECTOR3;
			info_pos->x = x;
			info_pos->y = y;
			info_pos->z = 0;

			CDraw::GetInstance()->Draw(CDirect::GetInstance()->GetTexture(INFORECT), &r_size, info_pos, D3DCOLOR_XRGB(255,255,255));
			delete info_pos;
		}
	}
	*/
}

void CPlay::End(bool m_iTeam)
{
	CSoundManager::GetInstance()->Play(SD_RESULTBGM,false);
	RECT r_size={0, 0, 500, 100};

	if(m_iTeam == false)		// 1p 패배
		CDraw::GetInstance()->Draw(CDirect::GetInstance()->GetTexture(BOTTOM_WIN), &r_size, &(D3DXVECTOR3(150,350,0)), D3DCOLOR_XRGB(255,255,255));

	else	// 2p 패배
		CDraw::GetInstance()->Draw(CDirect::GetInstance()->GetTexture(TOP_WIN), &r_size, &(D3DXVECTOR3(150,350,0)), D3DCOLOR_XRGB(255,255,255));
}