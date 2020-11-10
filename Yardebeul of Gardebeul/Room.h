#pragma once
#include "Chest.h"
#include "Tool.h"
#include "pch.h"

class Event
{
	//Variables
protected:
	string name;
	string description;
	STATE_EVENT stateEvent;
	bool isBoss;
	vector<Chest> chests;
	int sortOfDungeon;

	//Functions
private:

public:
	Event();
	~Event();
};