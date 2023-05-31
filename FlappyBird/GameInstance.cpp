#include "GameInstance.h"
#include <iostream>
#include <Windows.h>
#include "GameSettings.h"
#include "Pipe.h"
#include "PipeManager.h"
#include "Player.h"
#include "Tools.h"
#include "UIObject.h"

using namespace std;

void GameInstance::Start()
{
	Initialize();

	while (IsPlaying)
	{
		GameLoop();
	}
}


void GameInstance::Initialize()
{
	MainPlayer = new Player(GameObjects);
	PipeManagerObject = new PipeManager(GameObjects, MainPlayer);

	GameObjects.push_back(MainPlayer);
	GameObjects.push_back(PipeManagerObject);
}

void GameInstance::PrintBoard()
{
	auto boardSize = GameSettings::boardSize;
	for (int i = 0; i < boardSize.getY(); i++)
	{
		for (int j = 0; j < boardSize.getX(); j++)
		{
			auto currentPos = Vector2(j, i);

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
		if (gameObject->GetType() != eEntity)
			continue;

		auto entity = (Entity*)gameObject;
		if (entity->GetEntityType() != eUI)
			continue;

		auto uiObject = (UIObject*)entity;
		auto uiChar = uiObject->GetUIChar(currentPos);
		if (uiChar != "")
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

void GameInstance::PrintScore()
{
	int xSize = GameSettings::boardSize_x;
	for (int i = 0; i < xSize; i++) cout << "=";
	cout << '\n';
	cout << "===";
	cout << " Score 53 ";
	cout << '\n';
	cout << "===";
	cout << " High score 69 ";
	cout << '\n';
	for (int i = 0; i < xSize; i++) cout << "=";
}

void GameInstance::GameLoop()
{
	system("cls"); // clears console

	Tools::PrintMenu();
	PrintBoard();
	PrintScore();
	cout << '\n';
	cout << MainPlayer->getPosition()[0] << '\n' << GameObjects.size();
	for (auto gameObject : GameObjects)
	{
		if (gameObject->GetType() == eManager)
			continue;

		gameObject->Tick();
	}

	PipeManagerObject->Tick();

	if (MainPlayer->IsDead())
	{
		for (auto gameObject : GameObjects)
		{
			gameObject->SetActive(false);
		}
	}

	Sleep(GameSettings::refreshRate); // freezing game for x time
}
