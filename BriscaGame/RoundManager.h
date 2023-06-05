#pragma once
#include "Card.h"
#include "Player.h"
class RoundManager
{
public:

	RoundManager();
	~RoundManager();

	void ObtainPointsFromRound();

private:

	bool IsFirstCardWinning(Card* firstCard, Card* secondCard);
};


