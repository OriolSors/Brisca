#include "Card.h"
#include <cassert>

Card::Card(char value, CardSuit cardSuit, int valueInt, int points, char cardSuitChar):
	value(value), cardSuit(cardSuit), valueInt(valueInt), points(points), cardSuitChar(cardSuitChar)
{
}

Card::~Card()
{
}
