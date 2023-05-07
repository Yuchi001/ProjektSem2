#include "Entity.h"

std::vector<Vector2> Entity::getPosition()
{
	return position;
}

char Entity::getSprite()
{
	return entitySprite;
}

bool Entity::hasPosition(Vector2 pos)
{
	for (auto currentPos : position)
	{
		if (currentPos == pos)
			return true;
	}

	return false;
}

bool Entity::hasPosition(std::vector<Vector2> poses)
{
	for (auto currentPos : position)
	{
		for (auto pos : poses) {
			if (currentPos == pos)
				return true;
		}
	}
	return false;
}

Entity::Entity()
{
	type = eEntity;
}

