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
	cEvent();
	~cEvent();

};
