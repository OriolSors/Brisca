#include "Card.h"
#include <cassert>

Card::Card(char value, CardSuit cardSuit, int valueInt, int points): 
	value(value), cardSuit(cardSuit), valueInt(valueInt), points(points)
{
}

Card::~Card()
{
}
