#pragma once
#include <vector>
#include "Vector2.h"
#include "GameObject.h"

class Entity : public GameObject
{
protected:
	char entitySprite = 'e';

	std::vector<Vector2> position = std::vector<Vector2>();

	EEntityType entityType;

public:
	std::vector<Vector2> getPosition();
	char getSprite();
	bool hasPosition(Vector2 pos);
	bool hasPosition(std::vector<Vector2> posses);

	Entity();
};
