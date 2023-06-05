#include "Player.h"
#include "IOUser.h"
#include "GameManager.h"

#include <random>
#include <string>

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
			std::string message = std::to_string(count) + ')' + ' ' + card->GetValue() + card->GetCardSuitChar();
			Log(message);
		}
		int option = InputNumber(count);
		selectedCard = cardHand[option - 1];
		cardHand.erase(cardHand.begin() + option - 1);

		Log("You selected:");
		std::string message;
		message += selectedCard->GetValue();
		message += selectedCard->GetCardSuitChar();
		Log(message);
	}
	else
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(0, cardHand.size() - 1);
		int option = dist(gen);

		selectedCard = cardHand[option];
		cardHand.erase(cardHand.begin() + option);

		Log("Enemy selected:");
		std::string message;
		message += selectedCard->GetValue();
		message += selectedCard->GetCardSuitChar();
		Log(message);
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
