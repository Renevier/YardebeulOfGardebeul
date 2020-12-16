#include "pch.h"
#include "Dungeon.h"

void Dungeon::InitVariable(string _name, int _level, STATE_EVENT _type, int _nbEvent, vector<STATE_EVENT> _listOfEvent)
{
	this->name = _name;
	this->level = _level;
	this->type = _type;
	this->nbEvent = _nbEvent;
	this->listOfEvent = _listOfEvent;
}

void Dungeon::Fill()
{
	EventContainer myEventContainer;

	this->containerOfRoom.emplace("Fire/nothing", Room("Fire path", "path surround by fire", STATE_EVENT::NOTHING, false, myEventContainer.GetContainer().at("Fire/nothing")));
	this->containerOfRoom.emplace("Water/fight", Room("Water/fight", "combat with a Water enemy", STATE_EVENT::FIGHT, true, myEventContainer.GetContainer().at("Water/fight")));
	this->containerOfRoom.emplace("Fire/nothing", Room("Plant/meet", "meet a Plant guys", STATE_EVENT::MEET, false, myEventContainer.GetContainer().at("Plant/meet")));
}

Dungeon::Dungeon(string _name, int _level, STATE_EVENT _type, int _nbEvent, vector<STATE_EVENT> _listOfEvent)
{
	this->InitVariable(_name, _level, _type, _nbEvent, _listOfEvent);
	this->Fill();
}

Dungeon::~Dungeon()
{
}
