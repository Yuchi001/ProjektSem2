#include "ScoreManager.h"
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string> 


int ScoreManager::getHighScore()
{
	file.open("HighScore.txt", ios::in);
	string buffor;

	if (!file.good())
	{
		cerr << "File not available! \n";
		exit(0);
	}
	else
	{
		getline(file, buffor);
	}

	highScore = stoi(buffor);
	file.close();

	return highScore;
}


void ScoreManager::saveHighScore(int score)
{
	file.open("HighScore.txt", ios::out);

	if (!file.good())
	{
		cerr << "File not available! \n";
		exit(0);
	}
	else
	{
		file << score;
	}

	file.close();
}