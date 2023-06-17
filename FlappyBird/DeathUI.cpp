#include "DeathUI.h"
#include "Tools.h"
#include "ScoreManager.h"
#include <conio.h>
#include <Windows.h>
#include "GameInstance.h"

DeathUI::DeathUI(int score, GameInstance* game) : UIObject("FlappyBirdEndGameUI.txt") {
	scoreParams = Tools::ValueToArray(score);

	auto highscore = ScoreManager::getHighScore();
	if (score > highscore) {
		highscore = score;
		ScoreManager::saveHighScore(highscore);
	}
	highscoreParams = Tools::ValueToArray(highscore);
	gameInstance = game;
}

void DeathUI::Tick() {
	scoreCount = 0;
	highscoreCount = 0;

	if (!active) return;

	if (GetKeyState(SPACE_KEY) & 0x8000)
	{
		this->SetActive(false);
		gameInstance->Restart();
	}
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