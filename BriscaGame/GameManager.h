#pragma once

class GameManager 
{
public:

	GameManager();
	~GameManager();

	bool Init();
	bool PlayerSelection();
	bool AISelection();
	bool GameRound();
	bool GameRoundFinish();
	bool GameFinish();
	bool CleanUp();

private:



};