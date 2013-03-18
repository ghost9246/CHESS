#include "Prepare.h"


CPrepare::CPrepare(void)
{}

CPrepare::~CPrepare(void)
{}

void CPrepare::GetMouseInfo()
{
	x=CMouseManager::GetInstance()->GetX();			// 마우스 클릭한 x,y위치 받아옴
	y=CMouseManager::GetInstance()->GetY();
	mouseType = CMouseManager::GetInstance()->GetType();
}

void CPrepare::ShowMenu()
{
	RECT main={0, 0, 800, 800};
	RECT button={0, 0, 305, 75};

	CDraw::GetInstance()->Draw(CDirect::GetInstance()->GetTexture(MAIN_TITLE), &main, NULL, D3DCOLOR_XRGB(255,255,255));
	CDraw::GetInstance()->Draw(CDirect::GetInstance()->GetTexture(CLASSIC_BUTTON), &button, &(D3DXVECTOR3(250,500,0)), D3DCOLOR_XRGB(255,255,255));
	CDraw::GetInstance()->Draw(CDirect::GetInstance()->GetTexture(RANGED_BUTTON), &button, &(D3DXVECTOR3(250,590,0)), D3DCOLOR_XRGB(255,255,255));
	CDraw::GetInstance()->Draw(CDirect::GetInstance()->GetTexture(ELIMINATION_BUTTON), &button, &(D3DXVECTOR3(250,680,0)), D3DCOLOR_XRGB(255,255,255));
}

int CPrepare::DecideGameType()
{
	GetMouseInfo();

	if(mouseType == true)
	{
		if(x >= 250 && x <=555 && y >= 500 && y <= 575)		// 클래식 버튼 누름
			gameType = 1;

		else if(x >= 250 && x <=555 && y >= 590 && y <= 665)	// 원거리 버튼 누름
			gameType = 2;

		else if(x >= 250 && x <=555 && y >= 680 && y <= 755)	// 전멸 버튼 누름
			gameType = 3;
	}
	else
		gameType = 0;

	return gameType;
}

int CPrepare::SelectTeam1()
{
	GetMouseInfo();

	if(mouseType == true)
	{
		if(x >= 80 && x <120 && y >= 20 && y < 60)		// 1p 흑색 선택
			return 1;

		else if(x >= 120 && x < 160 && y >= 20 && y < 60)		// 1p 백색 선택
			return 2;

		else if(x >= 160 && x < 200 && y >= 20 && y < 60)		// 1p 적색 선택
			return 3;

		else if(x >= 200 && x < 240 && y >= 20 && y < 60)		// 1p 청색 선택
			return 4;
	}
	return 0;
}

int CPrepare::SelectTeam2()
{
	GetMouseInfo();

	if(mouseType == true)
	{
		if(x >= 80 && x <120 && y >= 740 && y < 780)		// 2p 흑색 선택
			return 1;

		else if(x >= 120 && x < 160 && y >= 740 && y < 780)		// 2p 백색 선택
			return 2;

		else if(x >= 160 && x < 200 && y >= 740 && y < 780)		// 2p 적색 선택
			return 3;

		else if(x >= 200 && x < 240 && y >= 740 && y < 780)		// 2p 청색 선택
			return 4;
	}
	return 0;
}

bool CPrepare::ShowStart()
{
	RECT start={0,0,305,75};
	CDraw::GetInstance()->Draw(CDirect::GetInstance()->GetTexture(START_BUTTON), &start, &(D3DXVECTOR3(250,350,0)), D3DCOLOR_XRGB(255,255,255));

	GetMouseInfo();
	if(x >= 250 && x < 555 && y >= 350 && y < 425)
		return true;
	else
		return false;
}