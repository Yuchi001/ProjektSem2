#include "GameInstance.h"
#include <Windows.h>

using namespace std;

bool StartGame() {
	const auto gameInstance = new GameInstance();
	return gameInstance->Start();
}

int main()
{
	while (StartGame());
	exit(0);
}