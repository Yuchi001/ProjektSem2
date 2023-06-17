#pragma once
#include <string>

#include "Enums.h"

class GameObject
{
public:
	GameObject();

	virtual void Tick() = 0;

	void SetActive(bool active);
	bool IsActive();

	std::string GetName();
	EObjectType GetType();

protected:
	std::string name = "";
	EObjectType type = eNone;
	bool active = true;
};

