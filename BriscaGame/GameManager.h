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


	Player* GetPlayerUser() const;
	Player* GetPlayerAI() const;
	Card* GetUnveiledCard() const;
	void SetUnveiledCard(Card* card);
	PlayerType GetStartPlayer() const;
	void SetStartPlayer(PlayerType playerType);

private:

	void FillCardList();
	void CreateNewCard(int value, CardSuit cardSuit);
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

extern GameManager* manager;

inline Player* GameManager::GetPlayerUser() const
{
	return playerUser;
}

inline Player* GameManager::GetPlayerAI() const
{
	return playerAI;
}

inline Card* GameManager::GetUnveiledCard() const
{
	return unveiledCard;
}

inline void GameManager::SetUnveiledCard(Card* card)
{
	unveiledCard = card;
}

inline PlayerType GameManager::GetStartPlayer() const
{
	return startPlayer;
}

inline void GameManager::SetStartPlayer(PlayerType playerType)
{
	startPlayer = playerType;
}
