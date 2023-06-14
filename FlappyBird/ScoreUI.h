#pragma once
#include "UIObject.h"
#include "Player.h"
#include <vector>

class ScoreUI : public UIObject
{
public:
	ScoreUI(Player* mainPlayer);
	void Tick() override;

protected:
	char GetConfiguredChar_override(Vector2 charPos) override;

private:
	Player* mainPlayer = nullptr;

	int scoreCount = 0;
	vector<int> scoreParams;
};

