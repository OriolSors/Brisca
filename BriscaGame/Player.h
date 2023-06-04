#pragma once

#include <list>
#include "Card.h"
class Player
{
public:
	Player();
	~Player();

	void Play();
	void TakeCard(Card* card);

private:
	std::list<Card*> cardHand;
};

