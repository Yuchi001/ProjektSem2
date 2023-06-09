#include "GameInstance.h"
#include <iostream>
#include <Windows.h>
#include "GameSettings.h"
#include "Pipe.h"
#include "PipeManager.h"
#include "Player.h"
#include "Tools.h"
#include "UIObject.h"
#include "ScoreManager.h"
#include "UIObject.h"
#include "DeathUI.h"
#include "StartUI.h"
#include "ScoreUI.h"

using namespace std;

bool GameInstance::Start()
{
	Initialize();
	while (IsPlaying)
	{
		GameLoop();
	}
	Deactivate();
	return shouldRestart;
}


void GameInstance::Initialize()
{
	MainPlayer = new Player(GameObjects);
	PipeManagerObject = new PipeManager(GameObjects, MainPlayer);
	auto scoreUI = new ScoreUI(MainPlayer);
	auto startUI = new StartUI(this);

	GameObjects.push_back(MainPlayer);
	GameObjects.push_back(PipeManagerObject);
	GameObjects.push_back(scoreUI);
	GameObjects.push_back(startUI);
}

void GameInstance::PrintBoard()
{
	auto boardSize = GameSettings::boardSize;
	for (int i = 0; i < boardSize.getY(); i++)
	{
		for (int j = 0; j < boardSize.getX(); j++)
		{
			auto currentPos = Vector2(j, i);
			if ((currentPos.getX() == 0 
				|| currentPos.getX() == boardSize.getX() - 1)
				&& i != 0) {
				cout << '|';
				continue;
			}

			if (PrintUI(currentPos)) continue;

			if (PrintEntities(currentPos)) continue;

			cout << " ";
		}
		cout << '\n';
	}
}

bool GameInstance::PrintUI(Vector2 currentPos) {
	for (auto gameObject : GameObjects)
	{
		if (!gameObject->IsActive()) continue;

		if (gameObject->GetType() != EObjectType::eEntity)
			continue;

		auto entity = (Entity*)gameObject;
		if (entity->GetEntityType() != EEntityType::eUI)
			continue;

		auto uiObject = (UIObject*)entity;
		auto uiChar = uiObject->GetUIChar(currentPos);
		if (uiChar != '\0')
		{
			cout << uiChar;
			return true;
		}
	}
	return false;
}

bool GameInstance::PrintEntities(Vector2 currentPos) {
	for (auto gameObject : GameObjects)
	{
		if (gameObject->GetType() != eEntity)
			continue;

		auto entity = (Entity*)gameObject;
		if (entity->hasPosition(currentPos))
		{
			cout << entity->getSprite();
			return true;
		}
	}
	return false;
}

void GameInstance::Restart() {
	IsPlaying = false;
	shouldRestart = true;
}

void GameInstance::End() {
	IsPlaying = false;
	shouldRestart = false;
}

void GameInstance::GameLoop()
{
	system("cls"); // clears console

	Tools::PrintMenu();
	PrintBoard();
	Tools::PrintSubMenu();
	//cout << MainPlayer->getPosition()[0] << '\n' << GameObjects.size(); // Debug print
	for (auto gameObject : GameObjects)
	{
		if (gameObject->GetType() == eManager)
			continue;

		gameObject->Tick();
	}

	PipeManagerObject->Tick();

	if (MainPlayer->IsDead() && !playerDied)
	{
		playerDied = true;
		for (auto gameObject : GameObjects)
		{
			gameObject->SetActive(false);
		}

		auto endUI = new DeathUI(MainPlayer->getScore(), this);
		GameObjects.push_back(endUI);
	}

	Sleep(GameSettings::refreshRate); // freezing game for x time
}

void GameInstance::Deactivate() {
	for (int i = 0; i < GameObjects.size(); i++)
	{
		GameObjects.erase(GameObjects.begin() + i);
	}
}
