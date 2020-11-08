#include "Effect.h"

void Effect::InitVariable(string _name, bool _isAoe, float _damage, float _duration)
{
	this->name = _name;
	this->name = _isAoe;
	this->damage = _damage;
	this->duration = _duration;
}

Effect::Effect(string _name, bool _isAoe, float _damage, float _duration)
{
	this->InitVariable(_name, _isAoe, _damage, _duration);
}

void Effect::AffectPlayer()
{
	cout << "the effect of " << this->name;

	if (this->damage > 0)
		cout << "inflige to your champ " << this->damage << " hp";
	else
		cout << "heal your hero with " << this->damage << " hp";

	cout << "with a duration of " << this->duration << " turn" << endl;
}

Effect::~Effect()
{
}