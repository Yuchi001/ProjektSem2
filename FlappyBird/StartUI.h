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
	GameInstance* gameInstance = nullptr;
};

