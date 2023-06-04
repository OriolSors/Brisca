#include "RoundManager.h"
#include "GameManager.h"
#include <cassert>

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
		}
		else
		{
			playerAI->SetPoints(std::abs(pointsObtained));
		}
	}
	else
	{
		int pointsObtained = ObtainPointsFromCards(playerAI->GetSelectedCard(), playerUser->GetSelectedCard());
		if (pointsObtained > 0)
		{
			playerAI->SetPoints(pointsObtained);
		}
		else
		{
			playerUser->SetPoints(std::abs(pointsObtained));
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
