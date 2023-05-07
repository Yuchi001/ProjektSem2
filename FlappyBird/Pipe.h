#pragma once
#include "GameSettings.h"
#include "Entity.h"

using namespace std;

class Pipe : public Entity
{
private:
	vector<Vector2> GeneratePipe();

public:
	Pipe();

	void Tick() override;

private:
	bool move = true;

	int pipeGap = 5;
	int pipeMinLength = 3;
	int pipeMaxLength = GameSettings::boardSize_y - pipeGap - pipeMinLength;
};

