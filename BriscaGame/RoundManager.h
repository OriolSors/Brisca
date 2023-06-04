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

	int ObtainPointsFromCards(Card* firstCard, Card* secondCard);
};


