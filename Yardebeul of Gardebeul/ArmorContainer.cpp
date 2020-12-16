#include "pch.h"
#include "ArmorContainer.h"

void ArmorContainer::Fill()
{
	container.emplace("Wooden armor", Armor("Wooden armor", 30, 100, 5, 1));
	container.emplace("Plasic armor", Armor("Plasic armor", 30, 100, 5, 1));
	container.emplace("Polystyrene armor", Armor("Polystyrene armor", 30, 100, 5, 1));
}

ArmorContainer::ArmorContainer()
{
	this->Fill();
}

ArmorContainer::~ArmorContainer()
{
}