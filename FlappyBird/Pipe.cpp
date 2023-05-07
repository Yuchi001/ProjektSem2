#include "Pipe.h"

#include "Tools.h"

Pipe::Pipe()
{
	entitySprite = 'U';
	name = "Pipe";
	type = eEntity;
	position = GeneratePipe();
}

vector<Vector2> Pipe::GeneratePipe()
{
	auto pos = vector<Vector2>({});
	int top = Tools::RandInt(pipeMinLength, pipeMaxLength);
	for(int i = 1, gap = 0; i < GameSettings::boardSize_y; i++)
	{
		if(i < top)
		{
			pos.push_back(Vector2(GameSettings::boardSize_x, i));
			continue;
		}

		if(gap < pipeGap)
		{
			gap++;
			continue;
		}

		pos.push_back(Vector2(GameSettings::boardSize_x, i));
	}

	return pos;
}

void Pipe::Tick()
{
	if (active == false)
		return;

	for(int i = 0; i < position.size(); i++)
	{
		position[i].setX(position[i].getX() - 1);
	}
}

