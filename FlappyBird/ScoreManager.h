#pragma once
#include "GameObject.h"
#include <stdio.h>

using namespace std;

static class ScoreManager
{
public:
	static int getHighScore();
	static void saveHighScore(int score);
};

