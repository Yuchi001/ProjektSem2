#pragma once
#include "UIObject.h"
#include <vector>
#include "GameInstance.h"
using namespace std;

class DeathUI : public UIObject
{

public:
	DeathUI(int score, GameInstance* game);

	void Tick() override;

protected:
	char GetConfiguredChar_override(Vector2 charPos) override;

private:
	int scoreCount = 0;
	int highscoreCount = 0;

	vector<int> scoreParams;
	vector<int> highscoreParams;

	GameInstance* gameInstance = nullptr;
};

