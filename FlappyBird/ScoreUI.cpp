#include "ScoreUI.h"
#include "Tools.h"

ScoreUI::ScoreUI(Player* mainPlayer) : UIObject("ScoreUI.txt", '#') {
	this->mainPlayer = mainPlayer;
}

void ScoreUI::Tick() {
	if (mainPlayer == nullptr || mainPlayer->IsDead() || !mainPlayer->IsReady()) return;

	scoreCount = 0;
	scoreParams = Tools::ValueToArray(mainPlayer->getScore());
}

char ScoreUI::GetConfiguredChar_override(Vector2 charPos) {
	auto currentChar = board[charPos.getX()][charPos.getY()];
	if (currentChar == '?') {
		if (!mainPlayer->IsReady() || 
			scoreCount >= scoreParams.size()) 
			return '\0';

		currentChar = std::to_string(scoreParams[scoreCount])[0];
		scoreCount++;
		return currentChar;
	}
	return '#';
}