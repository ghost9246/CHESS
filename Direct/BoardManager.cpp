#include "BoardManager.h"


CBoardManager::CBoardManager(void)
{}

CBoardManager::~CBoardManager(void)
{}

void CBoardManager::SetGameMode(int gameMode)
{
	m_iGameMode = gameMode;
}

void CBoardManager::SetUnitManager(CUnitManager *newManager)
{
	m_pUnitManager = newManager;
}

void CBoardManager::DrawBoard()
{
	RECT board={0,0,800,800};
	CDraw::GetInstance()->Draw(CDirect::GetInstance()->GetTexture(CHESSBOARD), &board, NULL, D3DCOLOR_XRGB(255,255,255));

	RECT symbol={0,0,40,40};
	switch(m_iGameMode)
	{
	case 1:
		CDraw::GetInstance()->Draw(CDirect::GetInstance()->GetTexture(CLASSIC_SYMBOL), &symbol, &(D3DXVECTOR3(480, 20, 0)), D3DCOLOR_XRGB(255,255,255));
		break;
	case 2:
		CDraw::GetInstance()->Draw(CDirect::GetInstance()->GetTexture(RANGED_SYMBOL), &symbol, &(D3DXVECTOR3(530, 20, 0)), D3DCOLOR_XRGB(255,255,255));
		break;
	case 3:
		CDraw::GetInstance()->Draw(CDirect::GetInstance()->GetTexture(ELIMINATION_SYMBOL), &symbol, &(D3DXVECTOR3(580, 20, 0)), D3DCOLOR_XRGB(255,255,255));
		break;
	}
}

void CBoardManager::DrawUnit()
{
	int t_x, t_y;
	RECT size = {0,0,80,80};

	for(int y=0; y<8; y++)
	{
		for(int x=0; x<8; x++)
		{
			int unitInfo = m_pUnitManager->GetUnitInfo(x, y);
			if(unitInfo != 0)
			{
				int team_code = unitInfo / 10;
				int unit_code = unitInfo % 10;
				t_x = (x*80)+80;		// 말 화면에 뿌려줄 좌표 설정
				t_y = (y*80)+80;

				CDraw::GetInstance()->Draw(CDirect::GetInstance()->GetTexture(((team_code-1)*6)+ 15+ (unit_code-1)), &size, &(D3DXVECTOR3(t_x, t_y, 0)), D3DCOLOR_XRGB(255,255,255));
			}
		}
	}
}

void CBoardManager::DrawInfoRect()
{
	int x=CMouseManager::GetInstance()->GetX();			// 마우스 클릭한 x,y위치 받아옴
	int y=CMouseManager::GetInstance()->GetY();

	if(x >= 80 && y >= 80 && x < 720 && y < 720)
	{
		RECT r_size={0, 0, 80, 80};
		//CDraw::GetInstance()->Draw(CDirect::GetInstance()->GetTexture(INFORECT), &r_size, &(D3DXVECTOR3(x, y, 0)), D3DCOLOR_XRGB(255,255,255));
	}
}