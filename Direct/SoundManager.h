#include <stdlib.h>
#include "inc/fmod.hpp"
using namespace FMOD;
#pragma comment (lib, "fmodex_vc.lib")
#pragma once

enum SOUNDKIND
{
	SD_BGM,				// 브금
	SD_RESULTBGM,		// 결과 브금
	SD_PAWNSELECT,	// 폰 선택
	SD_PAWNMOVE,		// 폰 이동
	SD_PAWNDIE,
	SD_RUCKSELECT,
	SD_RUCKMOVE,
	SD_RUCKDIE,
	SD_KNIGHTSELECT,
	SD_KNIGHTMOVE,
	SD_KNIGHTDIE,
	SD_BISHOPSELECT,
	SD_BISHOPMOVE,
	SD_BISHOPDIE,
	SD_QUEENSELECT,
	SD_QUEENMOVE,
	SD_QUEENDIE,
	SD_KINGSELECT,
	SD_KINGMOVE,
	SD_KINGDIE,
	SD_END
};

class CSoundManager
{
public:
	~CSoundManager(void);
	static CSoundManager* GetInstance();
	static CSoundManager* m_sManager;

	void Load();
	void Play(int num,bool loop);
	void Stop(int num);

private:
	CSoundManager(void);
	System* m_pSystem;
	Sound* m_pSound[SD_END];
	Channel* m_pChannel[SD_END];
};