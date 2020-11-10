#include "Weapon.h"

void Weapon::InitVariables(string _name, float _price, float _durability, float _attack, int _levelToAccess)
{
	this->name = _name;
	this->price = _price;
	this->durability = _durability;
	this->attack = _attack;
	this->levelToAccess = _levelToAccess;
}

Weapon::Weapon(string _name, float _price, float _durability, float _attack, int _levelToAccess)
{
	this->InitVariables(_name, _price, _durability, _attack, _levelToAccess);
}

void Weapon::Choose()
{
	cout << this->name << endl;
	cout << this->price << endl;
	cout << this->durability << endl;
	cout << this->attack << endl;
}

void Weapon::DisplayStat()
{
}

Weapon::~Weapon()
{
}
