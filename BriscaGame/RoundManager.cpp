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

	if (manager->GetStartPlayer() == playerUser->GetPlayerType())
	{
		int pointsObtained = ObtainPointsFromCards(playerUser->GetSelectedCard(), playerAI->GetSelectedCard());
		if (pointsObtained > 0)
		{
			playerUser->SetPoints(pointsObtained);
			manager->SetStartPlayer(playerUser->GetPlayerType());
			Log("You win!");
			LogSameLine("You receive: ");
			LogSameLine((char*) pointsObtained);
		}
		else
		{
			playerAI->SetPoints(std::abs(pointsObtained));
			manager->SetStartPlayer(playerAI->GetPlayerType());
			Log("You lose :(");
			
		}
	}
	else
	{
		int pointsObtained = ObtainPointsFromCards(playerAI->GetSelectedCard(), playerUser->GetSelectedCard());
		if (pointsObtained > 0)
		{
			playerAI->SetPoints(pointsObtained);
			manager->SetStartPlayer(playerAI->GetPlayerType());
			Log("You win!");
			LogSameLine("You receive: ");
			LogSameLine((char*)pointsObtained);
		}
		else
		{
			playerUser->SetPoints(std::abs(pointsObtained));
			manager->SetStartPlayer(playerUser->GetPlayerType());
			Log("You lose :(");
		}
	}
}

int RoundManager::ObtainPointsFromCards(Card* firstCard, Card* secondCard)
{
	bool isFirstCardMainSuit = firstCard->GetCardSuit() == manager->GetUnveiledCard()->GetCardSuit();
	bool isSecondCardMainSuit = secondCard->GetCardSuit() == manager->GetUnveiledCard()->GetCardSuit();
	int firstCardValue = firstCard->GetValueInt();
	int secondCardValue = secondCard->GetValueInt();
	int roundPoints = firstCard->GetPoints() + secondCard->GetPoints();

	if (isFirstCardMainSuit && isSecondCardMainSuit)
	{
		if (firstCardValue > secondCardValue)
		{
			return roundPoints;
		}
		else
		{
			return -roundPoints;
		}
	}
	else if (isFirstCardMainSuit)
	{
		return roundPoints;
	}
	else if (isSecondCardMainSuit)
	{
		return -roundPoints;
	}
	else
	{
		if (firstCardValue > secondCardValue)
		{
			return roundPoints;
		}
		else
		{
			return -roundPoints;
		}
	}
}
