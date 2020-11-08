#include "NPC.h"

void NPC::InitVariable(string _name, float _level, Behaviour _behaviour, float _Hp, float _Mp, float _endure)
{
	this->name = _name;
	this->level = _level;
	this->behaviour = _behaviour;
	this->healthPoints = _Hp;
	this->manaPoints = _Mp;
	this->endurePoints = _endure;

	this->behaviour = Behaviour::PASSIFIC ;
}

NPC::NPC(string _name, float _level, Behaviour _behaviour, float _Hp, float _Mp, float _endure)
{
	InitVariable(_name, _level, _behaviour, _Hp, _Mp, _endure);
}

NPC::~NPC()
{
}
