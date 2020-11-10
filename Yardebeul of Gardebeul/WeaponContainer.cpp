#include "WeaponContainer.h"

void WeaponContainer::Fill()
{
	this->container.emplace("sword", Weapon("Wooden sword", 10.f, 100.f, 10.f, 1));
	this->container.emplace("shovel", Weapon("Wooden shovel", 10.f, 100.f, 10.f, 1));
	this->container.emplace("staff", Weapon("Wooden staff", 10.f, 100.f, 10.f, 1));
}

WeaponContainer::WeaponContainer()
{
}

WeaponContainer::~WeaponContainer()
{
}
