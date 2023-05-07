#include "PipeManager.h"

#include <iostream>
#include <Windows.h>

#include "Pipe.h"
#include "Player.h"

PipeManager::PipeManager(std::vector<GameObject*>& gameObjects, Player* mainPlayer)
{
	this->gameObjects = &gameObjects;
	this->mainPlayer = mainPlayer;
	type = eManager;
	name = "PipeManager";
}

void PipeManager::Tick()
{
	if (active == false || mainPlayer->IsReady() == false)
		return;

	ticks++;
	if(ticks > spawnPipeTickCount)
	{
		ticks = 0;
		auto pipe = new Pipe();
		gameObjects->push_back(pipe);
	}

	for(int i = 0; i < gameObjects->size(); i++)
	{
		auto gameObject = gameObjects->at(i);

		if (gameObject->GetName() != "Pipe" || gameObject->GetType() != EObjectType::eEntity)
			continue;

		auto entity = (Entity*)gameObject;
		if (entity->getPosition()[0].getX() < 0)
		{
			gameObjects->erase(gameObjects->begin() + i);
		}
	}
}

