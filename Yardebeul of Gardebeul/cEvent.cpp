#include "cEvent.h"

void cEvent::InitVariable(string _name, string _description, STATE_EVENT _type, BIOME _biome, bool hasReward)
{
	this->name = _name;
	this->description = _description;
	this->type = _type;
	this->biome = _biome;
	this->hasReward = hasReward;
	
}

cEvent::cEvent()
{
}

cEvent::cEvent(string _name, string _description, STATE_EVENT _type, BIOME _biome, bool hasReward)
{
	this->InitVariable(_name, _description, _type, _biome, hasReward);
}

cEvent::~cEvent()
{
}
