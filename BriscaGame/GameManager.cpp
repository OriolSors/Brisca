#include "GameManager.h"

GameManager::GameManager()
{
	FillCardList();

}

GameManager::~GameManager()
{

}

bool GameManager::Init()
{
	return false;
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
		cardList.insert(card);
	}

	for (int value = 0; value < 13; value++)
	{
		char cardValue = CastCardValue(value);
		Card* card = new Card(cardValue, CardSuit::HEARTS);
		cardList.insert(card);
	}

	for (int value = 0; value < 13; value++)
	{
		char cardValue = CastCardValue(value);
		Card* card = new Card(cardValue, CardSuit::PIKES);
		cardList.insert(card);
	}

	for (int value = 0; value < 13; value++)
	{
		char cardValue = CastCardValue(value);
		Card* card = new Card(cardValue, CardSuit::TILES);
		cardList.insert(card);
	}

	cardList.
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
