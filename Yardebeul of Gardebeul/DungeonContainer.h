#pragma once
#include "Dungeon.h"
#include "pch.h"

class DungeonContainer
{
protected:
	map<string, Dungeon> container;

private:
	void Fill();

public:
	DungeonContainer();
	~DungeonContainer();

	//get
	inline  map<string, Dungeon> GetContainer() const { return this->container; }

	//set
};

