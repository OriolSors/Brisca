#include <iostream>
#include "GameManager.h"

enum class GameState
{
	GAME_INIT,
	PLAYER_SELECTION,
	AI_SELECTION,
	GAME_ROUND,
	GAME_ROUND_FINISH,
	GAME_FINISH,
	EXIT
};

GameManager* manager;

int main()
{
	GameState gameState = GameState::GAME_INIT;
	
	while (gameState != GameState::EXIT)
	{
		switch (gameState)
		{
		case GameState::GAME_INIT:
			manager = new GameManager();
			manager->Init();
			gameState = GameState::PLAYER_SELECTION;
			break;
		case GameState::PLAYER_SELECTION:
			manager->PlayerSelection();
			gameState = GameState::AI_SELECTION;
			break;
		case GameState::AI_SELECTION:
			manager->AISelection();
			gameState = GameState::GAME_ROUND;
			break;
		case GameState::GAME_ROUND:
			manager->GameRound();
			gameState = GameState::GAME_ROUND_FINISH;
			break;
		case GameState::GAME_ROUND_FINISH:
			if (!manager->GameRoundFinish())
			{
				gameState = GameState::GAME_FINISH;
			}
			else
			{
				gameState = GameState::PLAYER_SELECTION;
			}
			break;
		case GameState::GAME_FINISH:
			if (manager->GameFinish())
			{
				gameState = GameState::GAME_INIT;
			}
			else
			{
				gameState = GameState::EXIT;
			}

			delete manager;
			break;
		default:
			break;
		}
	}
}