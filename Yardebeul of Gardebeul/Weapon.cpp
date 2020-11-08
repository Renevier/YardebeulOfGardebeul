#include "Weapon.h"

void Weapon::InitVaribles(string _name, float _price, float _durability, float _attack)
{
	this->name = _name;
	this->price = _price;
	this->durability = _durability;
	this->attack = _attack;
}

Weapon::Weapon(string _name, float _price, float _durability, float _attack)
{
	this->InitVaribles(_name, _price, _durability, _attack);
}

Weapon::~Weapon()
{
}
