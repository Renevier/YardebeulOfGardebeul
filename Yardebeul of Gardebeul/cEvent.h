#pragma once
#include "pch.h"

class cEvent
{
protected:
	string name;
	string description;
	STATE_EVENT type;
	BIOME biome;
	bool hasReward;

public:
	cEvent(string _name, string _description, STATE_EVENT _type, BIOME _biome, bool hasReward);
	~cEvent();

};