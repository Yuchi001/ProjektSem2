#pragma once
#include "PipeManager.h"

class GameInstance
{
public:
	void Start();

private:
	Player* MainPlayer;
	PipeManager* PipeManagerObject;
	std::vector<GameObject*> GameObjects = std::vector<GameObject*>();
	bool IsPlaying = true;

	void Initialize();
	void GameLoop();
	void PrintScore(); // not finished
	void PrintBoard();
};

