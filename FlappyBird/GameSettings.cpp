#include "GameSettings.h"
#include <string>

const int GameSettings::refreshRate = 50; // 50 is the best 

const Vector2 GameSettings::boardSize = Vector2(30, 20);

const int GameSettings::boardSize_x = ((Vector2)boardSize).getX();

const int GameSettings::boardSize_y = ((Vector2)boardSize).getY();

const int GameSettings::pipeSpawnTickRate = 16;

const std::string GameSettings::filePath_UI = "./UI/";

const std::string GameSettings::filePath_data= "./Data/";