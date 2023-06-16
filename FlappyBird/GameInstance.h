#pragma once
#include "PipeManager.h"

class GameInstance
{
public:
	bool Start();

	void Restart();

	void End();

private:
	Player* MainPlayer;
	PipeManager* PipeManagerObject;
	std::vector<GameObject*> GameObjects = std::vector<GameObject*>();
	bool IsPlaying = true;
	bool shouldRestart = false;

	void Initialize();
	void GameLoop();
	void Deactivate();

	void PrintBoard();
	
	bool PrintEntities(Vector2 currentPos);
	bool PrintUI(Vector2 currentPos);

	bool playerDied = false;
};

