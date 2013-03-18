#include "Direct.h"

CDirect* CDirect::m_pDirect=NULL;

CDirect::CDirect(HWND hWnd)
{
	if(NULL == (m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
		exit(0);

	D3DPRESENT_PARAMETERS d3dpp;		// ����̽� ������ ���� ����ü
	ZeroMemory(&d3dpp, sizeof(d3dpp));		// �ݵ�� ZeroMemory �Լ��� �̸� ����ü�� ������ ������ ��
	d3dpp.Windowed = TRUE;		// â ���
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;		// ���� ȿ������ swap ȿ��
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;		// ���� ����ȭ�� ��忡 ���缭 �ĸ���� ����

	// ����̽��� ������ ���� �������� �����Ѵ�:
	//		1. ����Ʈ ����ī�� ���
	//		2. HAL ����̽��� ���� (HW ������ġ ���)
	//		3. ���� ó���� ��� ī�忡�� �����ϴ� SWó���� ���� (HW�� �ϸ� �� ���� ����)
	m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &m_pd3dDevice);
	m_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );
	m_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
	D3DXCreateSprite(m_pd3dDevice, &m_pSprite);	
}

CDirect::~CDirect(void)
{
	if(m_pd3dDevice != NULL)
		m_pd3dDevice->Release();

	if(m_pD3D != NULL)
		m_pD3D->Release();
}

CDirect* CDirect::GetInstance(HWND hWnd)
{
	if (m_pDirect==NULL)
	{
		if(hWnd != NULL) m_pDirect = new CDirect(hWnd);
		else return NULL;
	}
	return m_pDirect;
}

LPD3DXSPRITE CDirect::GetSprite()
{
	return m_pSprite;
}

LPDIRECT3DTEXTURE9 CDirect::GetTexture(int iTEXTURE)
{
	return m_aTextureArray[iTEXTURE];
}

void CDirect::BeginDraw()
{
	m_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);		// D3DCOLOR_XRGB���� ������ �������� ȭ�� Clear
	m_pd3dDevice->BeginScene();
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void CDirect::EndDraw()
{
	m_pSprite->End();
	m_pd3dDevice->EndScene();
	m_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

void CDirect::Init()		// �ٸ� Ŭ������
{
	CreateTexture(&m_aTextureArray[MAIN_TITLE], _T("images\\title.png"), 800, 800, D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[CHESSBOARD], _T("images\\chessboard.png"), 800, 800,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[CLASSIC_BUTTON], _T("images\\classic.png"), 305, 75, D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[RANGED_BUTTON], _T("images\\ranged.png"), 305, 75, D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[ELIMINATION_BUTTON], _T("images\\elimination.png"), 305, 75,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[CLASSIC_SYMBOL], _T("images\\classic_symbol.png"), 40, 40,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[RANGED_SYMBOL], _T("images\\ranged_symbol.png"), 40, 40,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[ELIMINATION_SYMBOL], _T("images\\elimination_symbol.png"), 40, 40,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[START_BUTTON], _T("images\\start.png"), 305, 75,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[TURN_DISPLAY], _T("images\\turn.png"), 80, 80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[UNIT_MOVE], _T("images\\move.png"), 80, 80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[UNIT_ATTACK], _T("images\\attack.png"), 80, 80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[TOP_WIN], _T("images\\top_win.png"), 500, 100,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[BOTTOM_WIN], _T("images\\bottom_win.png"), 500, 100,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[INFORECT], _T("images\\infoRect.png"), 80, 80,D3DCOLOR_XRGB(255,255,255));

	CreateTexture(&m_aTextureArray[BLACK_PAWN]  ,_T("images\\blackPawn.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[BLACK_RUCK]  ,_T("images\\blackRuck.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[BLACK_KNIGHT]  ,_T("images\\blackKnight.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[BLACK_BISHOP]  ,_T("images\\blackBishop.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[BLACK_QUEEN]  ,_T("images\\blackQueen.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[BLACK_KING]  ,_T("images\\blackKing.png"),80,80,D3DCOLOR_XRGB(255,255,255));

	CreateTexture(&m_aTextureArray[WHITE_PAWN]  ,_T("images\\whitePawn.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[WHITE_RUCK]  ,_T("images\\whiteRuck.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[WHITE_KNIGHT]  ,_T("images\\whiteKnight.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[WHITE_BISHOP]  ,_T("images\\whiteBishop.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[WHITE_QUEEN]  ,_T("images\\whiteQueen.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[WHITE_KING]  ,_T("images\\whiteKing.png"),80,80,D3DCOLOR_XRGB(255,255,255));

	CreateTexture(&m_aTextureArray[RED_PAWN]  ,_T("images\\redPawn.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[RED_RUCK]  ,_T("images\\redRuck.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[RED_KNIGHT]  ,_T("images\\redKnight.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[RED_BISHOP]  ,_T("images\\redBishop.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[RED_QUEEN]  ,_T("images\\redQueen.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[RED_KING]  ,_T("images\\redKing.png"),80,80,D3DCOLOR_XRGB(255,255,255));

	CreateTexture(&m_aTextureArray[BLUE_PAWN]  ,_T("images\\bluePawn.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[BLUE_RUCK]  ,_T("images\\blueRuck.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[BLUE_KNIGHT]  ,_T("images\\blueKnight.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[BLUE_BISHOP]  ,_T("images\\blueBishop.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[BLUE_QUEEN]  ,_T("images\\blueQueen.png"),80,80,D3DCOLOR_XRGB(255,255,255));
	CreateTexture(&m_aTextureArray[BLUE_KING]  ,_T("images\\blueKing.png"),80,80,D3DCOLOR_XRGB(255,255,255));
}

LPDIRECT3DTEXTURE9 CDirect::CreateTexture(LPDIRECT3DTEXTURE9* ppTexture, TCHAR szFileName[], int nWidth, int nHeight, D3DCOLOR ColorKey)
{
	if(FAILED(D3DXCreateTextureFromFileEx(m_pd3dDevice, szFileName, nWidth, nHeight, 1, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED,
		D3DX_FILTER_NONE, D3DX_FILTER_NONE, ColorKey, NULL, NULL, ppTexture)))
	{
		//throw new CResourceError(szFileName);
		exit(0);
	}
	return *ppTexture;
}