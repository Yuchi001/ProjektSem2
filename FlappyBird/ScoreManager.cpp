#include "ScoreManager.h"
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string> 
#include <fstream>
#include "GameSettings.h"
#include <Windows.h>

int ScoreManager::getHighScore()
{
	//conversion from string to wstring -> to LPCWSTR
	auto dataPath = GameSettings::filePath_data;
	auto dataPath_wstring = wstring(dataPath.begin(), dataPath.end());
	CreateDirectory(dataPath_wstring.c_str(), NULL);
	//dir safety

	fstream file;
	string buffor;
	file.open(dataPath + "HighScore.txt", ios::in);

	if (!file.good())
	{
		ofstream newFile;
		file.open(dataPath + "HighScore.txt");
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
		file.open(dataPath + "HighScore.txt");
		if (file.good()) {
			file << '0';
		}
		return 0;
	}
}

void ScoreManager::saveHighScore(int score)
{
	//conversion from string to wstring -> to LPCWSTR
	auto dataPath = GameSettings::filePath_data;
	auto dataPath_wstring = wstring(dataPath.begin(), dataPath.end());
	CreateDirectory(dataPath_wstring.c_str(), NULL);
	//dir safety

	fstream file;
	file.open(dataPath + "HighScore.txt", ios::out);
	if (file.good())
	{
		file << score;
		file.close();
		return;
	}

	ofstream newFile;
	file.open(dataPath + "HighScore.txt");
	if (file.good()) {
		file << '0';
	}
}