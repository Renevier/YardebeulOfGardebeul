#include "pch.h"
#include "Chest.h"

Chest::Chest(string _name, Object* _myObject)
{
	this->chest.emplace(_name, _myObject);
}

Chest::~Chest()
{
}
