#include "pch.h"
#include "NPC.h"

void NPC::InitVariable(string _name, float _level, Behaviour _behaviour, float _Hp, float _Mp, float _endure)
	
{
	this->name = _name;
	this->level = _level;
	this->healthPoints = _Hp;
	this->manaPoints = _Mp;
	this->endurePoints = _endure;

	this->behaviour = Behaviour::PASSIFIC ;
	this->behaviour = _behaviour;
}

NPC::NPC(string _name, float _level, Behaviour _behaviour, float _Hp, float _Mp, float _endure)
{
	InitVariable(_name, _level, _behaviour, _Hp, _Mp, _endure);
	this->DisplayStats();
}

void NPC::DisplayStats()
{
	cout << endl << "Stat of " << this->name << endl;
	cout << " Level: " << this->level << endl;
	cout << " HP: " << this->healthPoints << endl;
	cout << " Mp: " << this->manaPoints << endl;
	cout << " EndurePoint: " << this->endurePoints << endl;
}

NPC::~NPC()
{
}
