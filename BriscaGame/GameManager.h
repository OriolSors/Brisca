#pragma once

#include <deque>
#include "Card.h"
#include "Player.h"
#include "RoundManager.h"

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
	void SplitCardsToPlayers();
	Card* TakeCardFromSet();

	std::deque<Card*> cardDeck;
	Card* unveiledCard;

	Player* playerUser;
	Player* playerAI;
	PlayerType startPlayer;

	RoundManager* roundManager;

};