#include "GameObject.h"

GameObject::GameObject()
{
	type = EObjectType::eNone;
	name = "New GameObject";
}


std::string GameObject::GetName()
{
	return name;
}

EObjectType GameObject::GetType()
{
	return type;
}

void GameObject::SetActive(bool active)
{
	this->active = active;
}

