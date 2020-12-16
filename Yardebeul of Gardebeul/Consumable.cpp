#include "pch.h"
#include "Consumable.h"

void Consumable::InitVariable(string _name, float _price,Effect _effect, float _durability)
{
	this->name = _name;
	this->price = _price;
	this->durability = _durability;
	this->effect = _effect;

	this->levelToAccess = 1;
}

Consumable::Consumable(string _name, float _price, Effect _effect, float _durability)
{
	this->InitVariable(_name, _price, _effect, _durability);
}

void Consumable::Choose()
{
}

void Consumable::DisplayStat()
{
}

Consumable::~Consumable()
{
}
