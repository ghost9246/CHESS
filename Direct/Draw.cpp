#include "Draw.h"
#include "Win.h"

CDraw* CDraw::m_pDraw = NULL;

CDraw::CDraw(void)
{
	m_pDirect = CDirect::GetInstance(); 
}

CDraw::~CDraw(void)
{}

CDraw* CDraw::GetInstance()
{
	if(m_pDraw == NULL)
		m_pDraw = new CDraw();

	return m_pDraw;
}

void CDraw::Draw(LPDIRECT3DTEXTURE9 Texture, RECT* DrawRegion, D3DXVECTOR3* Position, D3DCOLOR Color)
{
	m_pDirect->GetSprite()->Draw(Texture,DrawRegion,NULL,Position,Color);
}