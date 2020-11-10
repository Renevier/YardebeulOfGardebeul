#include "ChestContainer.h"

void ChestContainer::Fill()
{
	this->container.emplace("Chest of quest", Chest());
	this->container.emplace("Chest of boss", Chest());
	this->container.emplace("Chest of puzzle", Chest());
}

ChestContainer::ChestContainer()
{
	this->Fill();
}

ChestContainer::~ChestContainer()
{
}
