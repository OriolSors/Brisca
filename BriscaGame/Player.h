#pragma once

#include <list>
#include "Card.h"

enum class PlayerType
{
	USER,
	AI
};

class Player
{
public:
	Player(PlayerType playerType);
	~Player();

	PlayerType GetPlayerType() const;
	Card* GetSelectedCard() const;
	void SetPoints(int points);

	bool IsCardHandEmpty() const;

	void Play();
	void TakeCard(Card* card);

private:

	PlayerType playerType;
	std::list<Card*> cardHand;

	Card* selectedCard;
	int points;
};

inline PlayerType Player::GetPlayerType() const
{
	return playerType;
}

inline Card* Player::GetSelectedCard() const
{
	return selectedCard;
}

inline void Player::SetPoints(int points)
{
	this->points += points;
}

inline bool Player::IsCardHandEmpty() const
{
	return cardHand.empty();
}

