#pragma once
#include <vector>

class Tools
{
public:
	static int RandInt(int max);
	static int RandInt(int min, int max);
	static void PrintMenu();
	static void PrintSubMenu();
	static std::vector<int> ValueToArray(int val);
};

