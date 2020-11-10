#include "DungeonContainer.h"

void DungeonContainer::Fill()
{
	this->container.emplace("Level 1 dungeon/type: nothing", Dungeon());
	this->container.emplace("Level 1 dungeon/type: Fight", Dungeon());
	this->container.emplace("Level 1 dungeon/type: Meet", Dungeon());
	this->container.emplace("Level 1 dungeon/type: puzzle", Dungeon());
}

DungeonContainer::DungeonContainer()
{
}

DungeonContainer::~DungeonContainer()
{
}
