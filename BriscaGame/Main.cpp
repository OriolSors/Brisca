#include <iostream>

enum class GameState
{
	GAME_INIT,
	PLAYER_SELECTION,
	AI_SELECTION,
	GAME_ROUND,
	GAME_ROUND_FINISH,
	GAME_FINISH
};

int main()
{
	GameState gameState = GameState::GAME_INIT;

	while (gameState != GameState::GAME_FINISH)
	{

	}
}