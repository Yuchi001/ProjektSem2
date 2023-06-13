#pragma once
#include "GameObject.h"
#include <fstream>
#include <stdio.h>

using namespace std;

class ScoreManager : public GameObject
{
public:
	//ScoreManager();
	int getHighScore();
	void saveHighScore(int score);

private:
	int highScore;
	fstream file;
	
};

