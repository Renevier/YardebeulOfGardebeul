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
	BIOME biome;
	int difficulty;
	bool isBoss;
	vector<Chest> chests;
	int sortOfDungeon;
	list<cEvent> listOfEvent;

	//Functions
private:

public:
	Room();
	~Room();
};