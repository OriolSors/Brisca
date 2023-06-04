#include "GameManager.h"

#include <algorithm>
#include <random>

GameManager::GameManager()
{
	playerUser = new Player(PlayerType::USER);
	playerAI = new Player(PlayerType::AI);
	unveiledCard = nullptr;
	startPlayer = PlayerType::USER;
	roundManager = new RoundManager();
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
	playerUser->Play();
	return true;
}

bool GameManager::AISelection()
{
	playerAI->Play();
	return true;
}

bool GameManager::GameRound()
{
	roundManager->ObtainPointsFromRound();
	return true;
}

bool GameManager::GameRoundFinish()
{
	if (playerUser->IsCardHandEmpty() && playerAI->IsCardHandEmpty()) 
	{
		return false;
	}
	else if (cardDeck.empty()) 
	{
		return true;
	}
	else if (cardDeck.size() == 1)
	{
		if (startPlayer == PlayerType::USER)
		{
			playerUser->TakeCard(TakeCardFromSet());
			playerAI->TakeCard(unveiledCard);
		}
		else
		{
			playerAI->TakeCard(TakeCardFromSet());
			playerUser->TakeCard(unveiledCard);
		}
		return true;
	}
	else
	{
		return true;
	}
	
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
	for (int value = 2; value < 15; value++)
	{
		CreateNewCard(value, CardSuit::CLOVERS);
		CreateNewCard(value, CardSuit::HEARTS);
		CreateNewCard(value, CardSuit::PIKES);
		CreateNewCard(value, CardSuit::TILES);
	}

	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(cardDeck.begin(), cardDeck.end(), g);
}

void GameManager::CreateNewCard(int value, CardSuit cardSuit)
{
	char cardValue = CastCardValue(value);
	int points = 0;
	switch (value)
	{
	case 3:
		points = 10;
		break;
	case 11:
		points = 2;
		break;
	case 12:
		points = 3;
		break;
	case 13:
		points = 4;
		break;
	case 14:
		points = 11;
		break;
	default:
		break;
	}
	Card* card = new Card(cardValue, cardSuit, value, points);
	cardDeck.push_back(card);
}

char GameManager::CastCardValue(int value)
{
	char cardValue = '0';
	switch (value)
	{
	case 2:
		cardValue = '2';
		break;
	case 3:
		cardValue = '3';
		break;
	case 4:
		cardValue = '4';
		break;
	case 5:
		cardValue = '5';
		break;
	case 6:
		cardValue = '6';
		break;
	case 7:
		cardValue = '7';
		break;
	case 8:
		cardValue = '8';
		break;
	case 9:
		cardValue = '9';
		break;
	case 10:
		cardValue = '10';
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
	case 14:
		cardValue = 'A';
		break;
	default:
		break;
	}

	return cardValue;
}

void GameManager::SplitCardsToPlayers()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 2);
	int randomNum = dis(gen);

	startPlayer = static_cast<PlayerType>(randomNum);

	if (startPlayer == PlayerType::USER)
	{
		playerUser->TakeCard(TakeCardFromSet());
		playerAI->TakeCard(TakeCardFromSet());
		playerUser->TakeCard(TakeCardFromSet());
		playerAI->TakeCard(TakeCardFromSet());
		playerUser->TakeCard(TakeCardFromSet());
		playerAI->TakeCard(TakeCardFromSet());

	}
	else
	{
		playerAI->TakeCard(TakeCardFromSet());
		playerUser->TakeCard(TakeCardFromSet());
		playerAI->TakeCard(TakeCardFromSet());
		playerUser->TakeCard(TakeCardFromSet());
		playerAI->TakeCard(TakeCardFromSet());
		playerUser->TakeCard(TakeCardFromSet());
	}
}

Card* GameManager::TakeCardFromSet()
{
	if (cardDeck.empty())
		return nullptr;

	Card* card = cardDeck.back();
	cardDeck.pop_back();
	return card;
}
