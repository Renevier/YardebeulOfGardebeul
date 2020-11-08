#include "WeaponContainer.h"

void WeaponContainer::Fill()
{
	this->container.push_back(Weapon("Wooden sword", 10.f, 100.f, 10.f));
	this->container.push_back(Weapon("Wooden shovel", 10.f, 100.f, 10.f));
	this->container.push_back(Weapon("Wooden staff", 10.f, 100.f, 10.f));
}

WeaponContainer::WeaponContainer()
{
}

WeaponContainer::~WeaponContainer()
{
}
