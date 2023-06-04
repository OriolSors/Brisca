#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
	for (const Card* card : cardHand)
	{
		delete card;
	}

	cardHand.clear();
}

void Player::Play()
{
}

void Player::TakeCard(Card* card)
{
	cardHand.push_back(card);
}
