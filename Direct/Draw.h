#pragma once
#include "StdAfx.h"
#include "Direct.h"

class CDraw
{
public:
	~CDraw(void);
	static CDraw* m_pDraw;
	static CDraw* GetInstance();
	void Draw(LPDIRECT3DTEXTURE9 Texture, RECT* DrawRegion, D3DXVECTOR3* Position, D3DCOLOR Color);

private:
	CDraw(void);
	CDirect* m_pDirect;
};

