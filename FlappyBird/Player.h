#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(std::vector<GameObject*>& gameObjects);

	void Tick() override;

	bool IsDead();
	bool IsReady();

private:
	bool CheckCollision(Vector2 currentPos);
	void ManageInput(Vector2 currentPos);
	void Jump(Vector2 currentPos);
	void Fall(Vector2 currentPos);

	int posToAdd = 0;
	int posAddSpeed = 2;

	int fallingTicks = 0;
	int maxFallingTickSpeed = 10;

	bool isDead = false;
	bool isReady = false;

	std::vector<GameObject*>* gameObjects;
};

