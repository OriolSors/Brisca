#include "Player.h"
#include "IOUser.h"
#include "GameManager.h"

#include <random>

Player::Player(PlayerType playerType): playerType(playerType), points(0), selectedCard(nullptr)
{
}

Player::~Player()
{
	for (const Card* card : cardHand)
	{
		delete card;
	}

	cardHand.clear();
}

void Player::Play()
{
	if (playerType == PlayerType::USER) 
	{
		Log("Choose one card");
		int count = 0;
		for (auto card : cardHand)
		{
			count++;
			char message[5];
			message[0] = (char)(count);
			message[1] = ')';
			message[2] = ' ';
			message[3] = card->GetValue();
			message[4] = card->GetCardSuitChar();
			Log(message);
		}
		int option = InputNumber(count);
		selectedCard = cardHand[option - 1];
		cardHand.erase(cardHand.begin() + option - 1);
	}
	else
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(0, cardHand.size() - 1);
		int option = dist(gen);

		selectedCard = cardHand[option];
		cardHand.erase(cardHand.begin() + option);
	}
	
}

void Player::ChangeUnveiledCard()
{
	Card* unveiledCard = manager->GetUnveiledCard();
	bool changeUnveiled = false;
	for (auto card : cardHand)
	{
		
		if (card->GetCardSuit() == unveiledCard->GetCardSuit())
		{
			if (card->GetValueInt() == 7 && unveiledCard->GetValueInt() > 7)
			{
				Log("Change unveiled card?");
				changeUnveiled = InputBool();
				if (changeUnveiled)
				{
					Card* temp = card;
					card = unveiledCard;
					unveiledCard = card;
				}
				
			}
			else if (card->GetValueInt() == 2 && (unveiledCard->GetValueInt() <= 7 && unveiledCard->GetValueInt() > 2))
			{
				Log("Change unveiled card?");
				changeUnveiled = InputBool();
				if (changeUnveiled)
				{
					Card* temp = card;
					card = unveiledCard;
					unveiledCard = card;
				}
			}
		}
		
	}
}

void Player::TakeCard(Card* card)
{
	cardHand.push_back(card);
}
