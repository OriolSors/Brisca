#include "RoundManager.h"
#include "GameManager.h"
#include <cassert>
#include "IOUser.h"

RoundManager::RoundManager()
{

}

RoundManager::~RoundManager()
{

}

void RoundManager::ObtainPointsFromRound()
{
	Player* playerUser = manager->GetPlayerUser();
	Player* playerAI = manager->GetPlayerAI();

	int pointsToSum = playerUser->GetSelectedCard()->GetPoints() + playerAI->GetSelectedCard()->GetPoints();

	if (manager->GetStartPlayer() == playerUser->GetPlayerType())
	{
		bool isFirstCardWinning = IsFirstCardWinning(playerUser->GetSelectedCard(), playerAI->GetSelectedCard());
		if (isFirstCardWinning)
		{
			playerUser->SetPoints(pointsToSum);
			manager->SetStartPlayer(playerUser->GetPlayerType());
			Log("You win!");
			Log("You receive: ");
			std::string points = std::to_string(pointsToSum);
			Log(points);
		}
		else
		{
			playerAI->SetPoints(pointsToSum);
			manager->SetStartPlayer(playerAI->GetPlayerType());
			Log("You lose :(");
			Log("Enemy receive: ");
			std::string points = std::to_string(pointsToSum);
			Log(points);
			
		}
	}
	else
	{
		bool isFirstCardWinning = IsFirstCardWinning(playerAI->GetSelectedCard(), playerUser->GetSelectedCard());
		if (isFirstCardWinning > 0)
		{
			playerAI->SetPoints(pointsToSum);
			manager->SetStartPlayer(playerAI->GetPlayerType());
			Log("You lose :(");
			Log("Enemy receive: ");
			std::string points = std::to_string(pointsToSum);
			Log(points);
		}
		else
		{
			playerUser->SetPoints(pointsToSum);
			manager->SetStartPlayer(playerUser->GetPlayerType());
			Log("You win!");
			Log("You receive: ");
			std::string points = std::to_string(pointsToSum);
			Log(points);
		}
	}
}

bool RoundManager::IsFirstCardWinning(Card* firstCard, Card* secondCard)
{
	bool isFirstCardMainSuit = firstCard->GetCardSuit() == manager->GetUnveiledCard()->GetCardSuit();
	bool isSecondCardMainSuit = secondCard->GetCardSuit() == manager->GetUnveiledCard()->GetCardSuit();
	int firstCardValue = firstCard->GetValueInt();
	int secondCardValue = secondCard->GetValueInt();

	if (isFirstCardMainSuit && isSecondCardMainSuit)
	{
		if (firstCardValue > secondCardValue)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (isFirstCardMainSuit)
	{
		return true;
	}
	else if (isSecondCardMainSuit)
	{
		return false;
	}
	else
	{
		if (firstCard->GetCardSuit() == secondCard->GetCardSuit())
		{
			if (firstCardValue > secondCardValue)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		}
		
	}
}
