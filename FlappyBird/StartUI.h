#pragma once
#include "UIObject.h"
#include "GameInstance.h"

class StartUI : public UIObject
{
public:
	StartUI(GameInstance* game);

	void Tick() override;

protected:
	char GetConfiguredChar_override(Vector2 charPos) override;

private:
	static const int SPACE_KEY = 32;
	static const int ESC_KEY = 27;

	GameInstance* gameInstance = nullptr;
};

