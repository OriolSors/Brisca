#include "Player.h"

Player::Player(PlayerType playerType): playerType(playerType), points(0), selectedCard(nullptr)
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
	//TODO: Set the selected card
}

void Player::TakeCard(Card* card)
{
	cardHand.push_back(card);
}
