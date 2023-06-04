#pragma once
#include "Card.h"
#include "GameManager.h"
class RoundManager
{
public:

	RoundManager();
	~RoundManager();

	void SetStartPlayer(PlayerType startPlayer);
	void ObtainPointsFromRound(Player& playerUser, Player& playerAI);

private:
	PlayerType startPlayer;
};

inline void RoundManager::SetStartPlayer(PlayerType startPlayer)
{
	this->startPlayer = startPlayer;
}

