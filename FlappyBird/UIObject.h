#pragma once
#include "Entity.h"
#include <string>
#include <vector>

class UIObject : public Entity
{
public:
	UIObject(std::string fileName, Vector2 offset);

	std::string GetUIChar(Vector2 currentPosition);

	const char space = 'x';

protected:
	std::vector<std::string> characters = std::vector<std::string>();
	Vector2 offset = Vector2(0, 0);
};

