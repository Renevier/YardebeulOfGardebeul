#pragma once
#include "Chest.h"
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
	bool isBoss;
	vector<Chest> chests;
	int sortOfDunjeon;

	//Functions
private:

public:
	Room(string _name, string _description, BIOME _biome, bool isBoss, );
	~Room();
};