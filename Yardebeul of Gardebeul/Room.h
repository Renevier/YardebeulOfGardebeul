#pragma once
#include "Chest.h"
#include "cEvent.h"
#include "Tool.h"
#include "pch.h"

class Room
{
	//Variables
protected:
	string name;
	string description;
	STATE_EVENT stateEvent;
	bool isBoss;
	cEvent event;

	//Functions
private:
	void InitVariables(string _name, string _description, STATE_EVENT _state_event, bool _isBoss, cEvent _event);

public:
	Room(string _name, string _description, STATE_EVENT _state_event, bool _isBoss, cEvent _event);
	~Room();
};