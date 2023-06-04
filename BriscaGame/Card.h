#pragma once

enum class CardSuit
{
	HEARTS,
	PIKES,
	TILES,
	CLOVERS
};
class Card
{
public:
	Card(char value, CardSuit cardSuit);
	~Card();

private:

	char value;
	CardSuit cardSuit;
};

