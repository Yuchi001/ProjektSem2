#pragma once
#include "Entity.h"
#include "GameSettings.h"
#include "Player.h"

class PipeManager : public GameObject
{
public:
	PipeManager(std::vector<GameObject*>& gameObjects, Player* mainPlayer);
	~PipeManager();

	void Tick() override;

private:
	std::vector<GameObject*>* gameObjects;

	int spawnPipeTickCount = GameSettings::pipeSpawnTickRate;
	int ticks = GameSettings::pipeSpawnTickRate;

	bool playerReady = false;
	bool spawn = true;

	Player* mainPlayer;
};

