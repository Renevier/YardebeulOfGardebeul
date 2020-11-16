#include "Room.h"

void Room::InitVariables(string _name, string _description, STATE_EVENT _state_event, bool _isBoss, cEvent _event)
{
	this->name = _name;
	this->description = _description;
	this->stateEvent = _state_event;
	this->isBoss = _isBoss;
	this->event = _event;
}

Room::Room(string _name, string _description, STATE_EVENT _state_event, bool _isBoss, cEvent _event)
{
	this->InitVariables(_name, _description, _state_event, _isBoss, _event);
}

Room::~Room()
{
}
