#pragma once
#include "Vector2.h"
#include <string>

class GameSettings
{
public:
	static const Vector2 boardSize;
	static const int refreshRate;
	static const int boardSize_x;
	static const int boardSize_y;
	static const int pipeSpawnTickRate;
	static const std::string filePath_UI;
	static const std::string filePath_data;
};

