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
	manager = new GameManager();
	
	while (gameState != GameState::EXIT)
	{
		switch (gameState)
		{
		case GameState::GAME_INIT:
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
			bool isGameFinished = manager->GameRoundFinish();
			if (isGameFinished)
			{
				gameState = GameState::GAME_FINISH;
			}
			else
			{
				gameState = GameState::PLAYER_SELECTION;
			}
			break;
		case GameState::GAME_FINISH:
			bool isGameReplayed = manager->GameFinish();
			if (isGameReplayed)
			{
				manager->CleanUp();
				gameState = GameState::GAME_INIT;
			}
			else
			{
				delete manager;
				gameState = GameState::EXIT;
			}
			break;
		default:
			break;
		}
	}
}