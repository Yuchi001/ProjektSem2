#include "DeathUI.h"
#include "Tools.h"

DeathUI::DeathUI(int score, int highscore) : UIObject("FlappyBirdEndGameUI.txt") {
	scoreParams = Tools::ValueToArray(score);
	highscoreParams = Tools::ValueToArray(highscore);
}

void DeathUI::Tick() {
	scoreCount = 0;
	highscoreCount = 0;
}

char DeathUI::GetConfiguredChar_override(Vector2 charPos) {
	auto currentChar = board[charPos.getX()][charPos.getY()];
	if (currentChar == '?' && scoreParams.size() != 0) {
		if (scoreCount >= scoreParams.size()) return ' ';
		currentChar = std::to_string(scoreParams[scoreCount])[0];
		scoreCount++;
		return currentChar;
	}
	if (currentChar == '!' && highscoreParams.size() != 0) {
		if (highscoreCount >= highscoreParams.size()) return ' ';
		currentChar = std::to_string(highscoreParams[highscoreCount])[0];
		highscoreCount++;
		return currentChar;
	}
	return '\0';
}