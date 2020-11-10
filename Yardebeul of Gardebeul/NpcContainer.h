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

};

