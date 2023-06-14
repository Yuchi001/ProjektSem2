#pragma once
#include "UIObject.h"
#include <vector>
using namespace std;

class DeathUI : public UIObject
{

public:
	DeathUI(int score, int highscore);

	void Tick() override;

protected:
	char GetConfiguredChar_override(Vector2 charPos) override;

private:
	int scoreCount = 0;
	int highscoreCount = 0;

	vector<int> scoreParams;
	vector<int> highscoreParams;
};

