#pragma once

#include <unordered_set>
#include "Card.h"

class GameManager 
{
public:

	GameManager();
	~GameManager();

	bool Init();
	bool PlayerSelection();
	bool AISelection();
	bool GameRound();
	bool GameRoundFinish();
	bool GameFinish();
	bool CleanUp();

private:

	void FillCardList();
	char CastCardValue(int value);
	std::unordered_set<Card*> cardList;

};