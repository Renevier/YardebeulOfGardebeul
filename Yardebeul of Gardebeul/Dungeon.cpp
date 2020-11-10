#include "Dungeon.h"

void Dungeon::InitVariable(string _name, int _level, STATE_EVENT _type, int _nbEvent, vector<STATE_EVENT> _listOfEvent)
{
	this->name = _name;
	this->level = _level;
	this->type = _type;
	this->nbEvent = _nbEvent;
	this->listOfEvent = _listOfEvent;
}

Dungeon::Dungeon(string _name, int _level, STATE_EVENT _type, int _nbEvent, vector<STATE_EVENT> _listOfEvent)
{
	this->InitVariable(_name, _level, _type, _nbEvent, _listOfEvent);
}

Dungeon::~Dungeon()
{
}
