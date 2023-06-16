#include "ScoreManager.h"
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string> 
#include <fstream>


int ScoreManager::getHighScore()
{
	fstream file;
	string buffor;
	file.open("HighScore.txt", ios::in);

	if (!file.good())
	{
		ofstream newFile;
		file.open("HighScore.txt");
		if (file.good()) {
			file << '0';
		}
		return 0;
	}
	
	getline(file, buffor);
	file.close();
	try {
		return stoi(buffor);
	}
	catch (exception e) {
		ofstream newFile;
		file.open("HighScore.txt");
		if (file.good()) {
			file << '0';
		}
		return 0;
	}
}

void ScoreManager::saveHighScore(int score)
{
	fstream file;
	file.open("HighScore.txt", ios::out);
	if (file.good())
	{
		file << score;
		file.close();
		return;
	}

	ofstream newFile;
	file.open("HighScore.txt");
	if (file.good()) {
		file << '0';
	}
}