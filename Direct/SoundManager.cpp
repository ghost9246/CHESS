// 사운드에 쿨타임 주는 방법?

#include "SoundManager.h"

CSoundManager* CSoundManager::m_sManager = NULL;

CSoundManager::CSoundManager(void)
{
	System_Create(&m_pSystem);
	m_pSystem->init(1, FMOD_INIT_NORMAL, 0);
	Load();
}

CSoundManager::~CSoundManager(void)
{
	m_pSystem->release();
	m_pSystem->close();
}

CSoundManager* CSoundManager::GetInstance()
{
	if (m_sManager == NULL)
		m_sManager = new CSoundManager();

	return m_sManager;
}

void CSoundManager::Load()
{
	FMOD_RESULT result;
	result = FMOD::System_Create(&m_pSystem);
    m_pSystem->init(1, FMOD_INIT_NORMAL, 0);

	m_pSystem->createSound("Sound/bgm.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_BGM]);
	m_pSystem->createSound("Sound/result.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_RESULTBGM]);

	m_pSystem->createSound("Sound/pawnSelect.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_PAWNSELECT]);
	m_pSystem->createSound("Sound/pawnMove.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_PAWNMOVE]);
	m_pSystem->createSound("Sound/pawnDie.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_PAWNDIE]);
	m_pSystem->createSound("Sound/ruckSelect.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_RUCKSELECT]);
	m_pSystem->createSound("Sound/ruckMove.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_RUCKMOVE]);
	m_pSystem->createSound("Sound/ruckDie.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_RUCKDIE]);
	m_pSystem->createSound("Sound/knightSelect.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_KNIGHTSELECT]);
	m_pSystem->createSound("Sound/knightMove.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_KNIGHTMOVE]);
	m_pSystem->createSound("Sound/knightDie.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_KNIGHTDIE]);
	m_pSystem->createSound("Sound/bishopSelect.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_BISHOPSELECT]);
	m_pSystem->createSound("Sound/bishopMove.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_BISHOPMOVE]);
	m_pSystem->createSound("Sound/bishopDie.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_BISHOPDIE]);
	m_pSystem->createSound("Sound/queenSelect.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_QUEENSELECT]);
	m_pSystem->createSound("Sound/queenMove.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_QUEENMOVE]);
	m_pSystem->createSound("Sound/queenDie.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_QUEENDIE]);
	m_pSystem->createSound("Sound/kingSelect.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_KINGSELECT]);
	m_pSystem->createSound("Sound/kingMove.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_KINGMOVE]);
	m_pSystem->createSound("Sound/kingDie.mp3", FMOD_HARDWARE, 0, &m_pSound[SD_KINGDIE]);
}

void CSoundManager::Play(int num, bool loop)
{
	FMOD_RESULT result;
    result = m_pSystem->playSound( FMOD_CHANNEL_FREE, m_pSound[num], loop, &m_pChannel[num]);
}

void CSoundManager::Stop(int num)
{
	m_pChannel[num]->stop();
}