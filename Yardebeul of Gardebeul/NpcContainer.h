#pragma once
#include "NPC.h"

class NpcContainer
{
protected:
	map<string, NPC> container;

private:
	void Fill();

public:
	NpcContainer();
	~NpcContainer();

	//get
	inline  map<string, NPC> GetContainer() const { return this->container; }

	//set
};

