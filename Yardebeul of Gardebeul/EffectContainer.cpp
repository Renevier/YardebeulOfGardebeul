#include "EffectContainer.h"


void EffectContainer::Fill()
{
	this->container.emplace("Fire", Effect("Burn", false, 5, 2));
	this->container.emplace("Water", Effect("Freeze", false, 3, 3));
	this->container.emplace("Plant", Effect("Leech seed", false, 2, 3)); //Heal 2, 3
	this->container.emplace("Small heal", Effect("Little heal", false, -5, 1));
	this->container.emplace("Heal", Effect("Heal", false, -10, 1));
	this->container.emplace("Big heal", Effect("Big heal", false, -20, 1));
}

EffectContainer::EffectContainer()
{
	this->Fill();
}

map<string, Effect> const EffectContainer::GetContainer() const
{
	return container;
}

EffectContainer::~EffectContainer()
{
}
