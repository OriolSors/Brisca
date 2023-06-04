#include "GameManager.h"

#include <algorithm>
#include <random>

GameManager::GameManager()
{
	playerUser = new Player();
	playerAI = new Player();
	unveiledCard = nullptr;
}

GameManager::~GameManager()
{
	for (const Card* card: cardDeck)
	{
		delete card;
	}

	cardDeck.clear();

	delete playerUser;
	delete playerAI;
	delete unveiledCard;
}

bool GameManager::Init()
{
	FillCardList();
	SplitCardsToPlayers();

	
	unveiledCard = TakeCardFromSet();

	return true;
}

bool GameManager::PlayerSelection()
{
	return false;
}

bool GameManager::AISelection()
{
	return false;
}

bool GameManager::GameRound()
{
	return false;
}

bool GameManager::GameRoundFinish()
{
	return false;
}

bool GameManager::GameFinish()
{
	return false;
}

bool GameManager::CleanUp()
{
	return false;
}

//--- PRIVATE METHODS ---

void GameManager::FillCardList()
{
	for (int value = 0; value < 13; value++)
	{
		char cardValue = CastCardValue(value);
		Card* card = new Card(cardValue, CardSuit::CLOVERS);
		cardDeck.push_back(card);
	}

	for (int value = 0; value < 13; value++)
	{
		char cardValue = CastCardValue(value);
		Card* card = new Card(cardValue, CardSuit::HEARTS);
		cardDeck.push_back(card);
	}

	for (int value = 0; value < 13; value++)
	{
		char cardValue = CastCardValue(value);
		Card* card = new Card(cardValue, CardSuit::PIKES);
		cardDeck.push_back(card);
	}

	for (int value = 0; value < 13; value++)
	{
		char cardValue = CastCardValue(value);
		Card* card = new Card(cardValue, CardSuit::TILES);
		cardDeck.push_back(card);
	}

	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(cardDeck.begin(), cardDeck.end(), g);
}

char GameManager::CastCardValue(int value)
{
	char cardValue = '0';
	switch (value)
	{
	case 0:
		cardValue = 'A';
		break;
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		cardValue = static_cast<char>(value);
		break;
	case 11:
		cardValue = 'J';
		break;
	case 12:
		cardValue = 'Q';
		break;
	case 13:
		cardValue = 'K';
		break;
	default:
		break;
	}

	return cardValue;
}

void GameManager::SplitCardsToPlayers()
{
	playerUser->TakeCard(TakeCardFromSet());
	playerAI->TakeCard(TakeCardFromSet());
	playerUser->TakeCard(TakeCardFromSet());
	playerAI->TakeCard(TakeCardFromSet());
	playerUser->TakeCard(TakeCardFromSet());
	playerAI->TakeCard(TakeCardFromSet());
}

Card* GameManager::TakeCardFromSet()
{
	if (cardDeck.empty())
		return nullptr;

	Card* card = cardDeck.back();
	cardDeck.pop_back();
	return card;
}
