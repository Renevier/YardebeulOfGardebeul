#include "NpcContainer.h"

void NpcContainer::Fill()
{
	this->container.emplace("NPC lvl 1/Helpfull", NPC("Georges", 1, Behaviour::HELPFULL, 100, 0, 100));
	this->container.emplace("NPC lvl 2/ Passific", NPC("Georges", 2, Behaviour::PASSIFIC, 100, 0, 100));
	this->container.emplace("NPC lvl 3/ Agressif", NPC("Georges", 3, Behaviour::AGRESSIF, 150, 0, 100));
}

NpcContainer::NpcContainer()
{
	this->Fill();
}

NpcContainer::~NpcContainer()
{
}
