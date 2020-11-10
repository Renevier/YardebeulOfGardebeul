#include "ArmorContainer.h"

void ArmorContainer::Fill()
{
	container.push_back(Armor("Wooden armor", 30, 100, 5, 1));
	container.push_back(Armor("Plasic armor", 30, 100, 5, 1));
	container.push_back(Armor("Polystyrene armor", 30, 100, 5, 1));
}

ArmorContainer::ArmorContainer()
{
}

ArmorContainer::~ArmorContainer()
{
}
