#include "Tools.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "GameSettings.h"

int Tools::RandInt(int max)
{
	srand((unsigned)time(NULL));
	return rand() % max;
}

int Tools::RandInt(int min, int max)
{
	srand((unsigned)time(NULL));
	return min + (rand() % (max - min + 1));
}

void Tools::PrintMenu()
{
	int xSize = GameSettings::boardSize_x;
	for (int i = 0; i < xSize; i++) std::cout << "=";
	std::cout << '\n';
	for (int i = 0; i < xSize / 7; i++) std::cout << "=";
	std::cout << " F L A P P Y  B I R D ";
	for (int i = 0; i < xSize / 7; i++) std::cout << "=";
	std::cout << '\n';
	for (int i = 0; i < xSize; i++) std::cout << "=";
}


std::vector<int> Tools::ValueToArray(int val) {
	if (val < 10)
		return std::vector<int>({ val });

	std::vector<int> res = std::vector<int>();
	while (val != 0) {
		res.push_back(val % 10);
		val /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}