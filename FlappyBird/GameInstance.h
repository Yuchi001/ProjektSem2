#pragma once
#include "PipeManager.h"

class GameInstance
{
public:
	void Start();

private:
	Player* MainPlayer;
	PipeManager* PipeManagerObject;
	//ScoreManager* ScoreManagerObject;
	std::vector<GameObject*> GameObjects = std::vector<GameObject*>();
	bool IsPlaying = true;

	void Initialize();
	void GameLoop();
	void PrintScore(); // not finished
	void PrintBoard();
	
	bool PrintEntities(Vector2 currentPos);
	bool PrintUI(Vector2 currentPos);

	bool playerDied = false;
};

