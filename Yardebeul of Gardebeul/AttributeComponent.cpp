#include "pch.h"
#include "AttributeComponent.h"

AttributeComponent::AttributeComponent(unsigned _level)
{
	this->level = _level;
	this->exp = 0;
	this->expNext = static_cast<unsigned>((50 / 3) * (pow(this->level, 3) - 6 * pow(this->level, 2) + (this->level * 17) - 12));
	this->attributePoint = 5;

	this->vitality = 1;
	this->strength = 1;
	this->dexterity = 1;
	this->agility = 1;
	this->intelligence = 1;

	this->UpdateStats(false);
}

AttributeComponent::~AttributeComponent()
{
}

string AttributeComponent::Debug()
{
	stringstream ss;

	ss << "Level: " << this->level << endl
		<< "Exp: " << this->exp << endl
		<< "Exp Next: " << this->expNext << endl
		<< "Attp: " << this->attributePoint << endl;
	return ss.str();
}

void AttributeComponent::GainExp(unsigned _exp)
{
	this->exp += _exp;
	this->UpdateLevel();
}

void AttributeComponent::UpdateStats(bool _reset)
{	
	this->hpMax = this->vitality * 9 + this->vitality + this->strength / 2 + this->intelligence / 5;
	this->damageMax = this->strength * 2 + this->strength / 2 + this->intelligence / 5;
	this->damageMin = this->strength * 2 + this->strength / 4 + this->intelligence / 5;
	this->accuracy = this->dexterity * 5 + this->dexterity / 2 + this->intelligence / 5;
	this->defence = this->agility * 2 + this->agility / 4 + this->intelligence / 5;
	this->luck = this->intelligence * 2 + this->intelligence / 5;

	if (_reset)
	{
		this->hp = this->hpMax;
	}
}

void AttributeComponent::UpdateLevel()
{
	while (this->exp > this->expNext)
	{
		this->level++;
		this->exp -= this->expNext;
		this->expNext = static_cast<unsigned>((50 / 3) * (pow(this->level, 3) - 6 * pow(this->level, 2) + (this->level * 17) - 12));
		this->attributePoint++;
	}
}

void AttributeComponent::Update()
{
	this->UpdateLevel();
}
