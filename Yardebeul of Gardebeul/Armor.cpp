#include "Armor.h"

void Armor::InitVariables(string _name, float _price, float _durability, float _defense)
{
	this->name = _name;
	this->price = _price;
	this->durability = _durability;
	this->defense = _defense;
}

Armor::Armor(string _name, float _price, float _durability, float _defense)
{
	this->InitVariables(_name, _price, _durability, _defense);
}

Armor::~Armor()
{
}
