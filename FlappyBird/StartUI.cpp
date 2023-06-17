#include "StartUI.h"
#include <Windows.h>

StartUI::StartUI(GameInstance* game): UIObject("StartUI.txt", '#') {
	gameInstance = game;
}

void StartUI::Tick() {
	if (gameInstance == nullptr || !active) return;

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		SetActive(false);
	}

	if (GetKeyState(VK_ESCAPE) & 0x8000)
	{
		this->SetActive(false);
		gameInstance->End();
	}
}

char StartUI::GetConfiguredChar_override(Vector2 charPos) {
	auto currentChar = board[charPos.getX()][charPos.getY()];
	if (currentChar == '?') return '\0';

	return '#';
}