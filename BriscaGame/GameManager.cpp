#include "GameManager.h"
#include "IOUser.h"
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
	CleanUp();
}

bool GameManager::Init()
{
	FillCardList();
	SplitCardsToPlayers();

	unveiledCard = TakeCardFromSet();

	Log("The unveiled card is:");
	std::string message;
	message += unveiledCard->GetValue();
	message += unveiledCard->GetCardSuitChar();
	Log(message);

	return true;
}

bool GameManager::PlayerSelection()
{

	if (startPlayer == PlayerType::USER)
	{
		Log("YOU go first!!");
	}
	else
	{
		Log("ENEMY go first!!");
	}

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
		if (startPlayer == PlayerType::USER)
		{
			playerUser->TakeCard(TakeCardFromSet());
			playerAI->TakeCard(TakeCardFromSet());
		}
		else
		{
			playerAI->TakeCard(TakeCardFromSet());
			playerUser->TakeCard(TakeCardFromSet());
		}

		playerUser->ChangeUnveiledCard();

		Log("The unveiled card is:");
		std::string message;
		message += unveiledCard->GetValue();
		message += unveiledCard->GetCardSuitChar();
		Log(message);

		return true;
	}
	
	
}

bool GameManager::GameFinish()
{
	int playerUserPoints = playerUser->GetPoints();
	int playerAIPoints = playerAI->GetPoints();

	if (playerUserPoints > playerAIPoints)
	{
		Log("You win with: ");
		std::string points = std::to_string(playerUserPoints);
		Log(points);
	}
	else
	{
		Log("Enemy win with: ");
		std::string points = std::to_string(playerAIPoints);
		Log(points);
	}

	Log("Repeat game?");
	bool isRepeatGame = InputBool();
	return isRepeatGame;
}

bool GameManager::CleanUp()
{
	for (const Card* card : cardDeck)
	{
		delete card;
	}

	cardDeck.clear();

	delete playerUser;
	delete playerAI;
	delete unveiledCard;
	return true;
}

//--- PRIVATE METHODS ---

void GameManager::FillCardList()
{
	for (int value = 0; value < 12; value++)
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
	case 7:
		points = 2;
		break;
	case 8:
		points = 3;
		break;
	case 9:
		points = 4;
		break;
	case 10:
		points = 10;
		break;
	case 11:
		points = 11;
		break;
	default:
		break;
	}


	char cardSuitChar;
	if (cardSuit == CardSuit::CLOVERS)
	{
		cardSuitChar = 'T';
	}
	else if (cardSuit == CardSuit::HEARTS)
	{
		cardSuitChar = 'C';
	}
	else if (cardSuit == CardSuit::PIKES)
	{
		cardSuitChar = 'P';
	}
	else
	{
		cardSuitChar = 'D';
	}

	Card* card = new Card(cardValue, cardSuit, value, points, cardSuitChar);
	cardDeck.push_back(card);
}

char GameManager::CastCardValue(int value)
{
	char cardValue = '0';
	switch (value)
	{
	case 0:
		cardValue = '2';
		break;
	case 1:
		cardValue = '4';
		break;
	case 2:
		cardValue = '5';
		break;
	case 3:
		cardValue = '6';
		break;
	case 4:
		cardValue = '7';
		break;
	case 5:
		cardValue = '8';
		break;
	case 6:
		cardValue = '9';
		break;
	case 7:
		cardValue = 'J';
		break;
	case 8:
		cardValue = 'Q';
		break;
	case 9:
		cardValue = 'K';
		break;
	case 10:
		cardValue = '3';
		break;
	case 11:
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
