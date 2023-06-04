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
	Card(char value, CardSuit cardSuit, int valueInt, int points, char cardSuitChar);
	~Card();

	char GetValue() const;
	int GetValueInt() const;
	int GetPoints() const;
	CardSuit GetCardSuit() const;
	char GetCardSuitChar() const;

private:

	char value;
	int valueInt;
	int points;
	CardSuit cardSuit;
	char cardSuitChar;
};

inline char Card::GetValue() const
{
	return value;
}

inline int Card::GetValueInt() const
{
	return valueInt;
}

inline int Card::GetPoints() const
{
	return points;
}

inline CardSuit Card::GetCardSuit() const
{
	return cardSuit;
}

inline char Card::GetCardSuitChar() const
{
	return cardSuitChar;
}

