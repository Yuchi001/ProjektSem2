#include "Player.h"
#include <conio.h>
#include <Windows.h>
#include <iostream>

#include "GameSettings.h"
#include "Pipe.h"

using namespace std;

Player::Player(std::vector<GameObject*>& gameObjects)
{
	this->gameObjects = &gameObjects;
	entitySprite = 'o';
	type = eEntity;
	name = "Player";
	position = std::vector<Vector2>();
	auto startPos = Vector2(GameSettings::boardSize_x / 3, GameSettings::boardSize_y / 2);
	position.emplace_back(startPos);
}

int Player::getScore()
{
	return score;
}

int Player::checkScore(Vector2 currentPos)
{
	for (int i = 0; i < gameObjects->size(); i++)
	{
		auto gameObject = gameObjects->at(i);
		if (gameObject->GetName() != "Pipe")
			continue;

		auto entity = (Entity*)gameObject;
		auto success = entity->getPosition()[0].getX() == currentPos.getX();
		
		if (success) Beep(1318, GameSettings::refreshRate);

		return success;
	}
	return 0;
}

void Player::Tick()
{
	auto currentPos = position[0];
	if(isDead && currentPos.getY() != GameSettings::boardSize_y - 1)
	{
		Fall(currentPos);
	}

	if (active == false)
		return;

	ManageInput(currentPos);

	if (isReady == false)
		return;

	if (CheckCollision(currentPos)) // no need to continue if player hit something
		return;

	score += checkScore(currentPos);

	if(posToAdd > 0)
	{
		Jump(currentPos);
		return;
	}

	Fall(currentPos);
}

void Player::Jump(Vector2 currentPos)
{
	fallingTicks = 0;
	auto y = currentPos.getY() - 1 > 0 ? currentPos.getY() - 1 : 1;
	position[0] = Vector2(currentPos.getX(), y);
	posToAdd = posToAdd > posAddSpeed ? posToAdd - posAddSpeed : 0;
}

void Player::Fall(Vector2 currentPos)
{
	auto boardSize = GameSettings::boardSize;
	if (position[0].getY() >= boardSize.getY() - 1)
	{
		position[0] = Vector2(currentPos.getX(), boardSize.getY() - 1);
		fallingTicks = 0;
		return;
	}

	fallingTicks += fallingTicks < maxFallingTickSpeed;
	position[0] = Vector2(currentPos.getX(), currentPos.getY() + fallingTicks / 2);
}

void Player::ManageInput(Vector2 currentPos)
{
	if (GetKeyState(SPACE_KEY) & 0x8000)
	{
		if (isReady == false)
		{
			isReady = true;
		}
		posToAdd = currentPos.getY() != 0 ? 4 : 0;
	}
}

bool Player::CheckCollision(Vector2 currentPos)
{
	for (int i = 0; i < gameObjects->size(); i++)
	{
		auto gameObject = gameObjects->at(i);
		if (gameObject->GetName() != "Pipe")
			continue;

		auto entity = (Entity*)gameObject;
		auto positions = vector<Vector2>({
			currentPos + Vector2(2, 0),
			currentPos + Vector2(1, 0),
			currentPos,
		});
		if (entity->hasPosition(positions))
		{
			isDead = true;
			return true;
		}
	}
	if (currentPos.getY() == GameSettings::boardSize_y - 1)
	{
		isDead = true;
		return true;
	}
	return false;
}

bool Player::IsReady()
{
	return isReady;
}

bool Player::IsDead()
{
	return isDead;
}
