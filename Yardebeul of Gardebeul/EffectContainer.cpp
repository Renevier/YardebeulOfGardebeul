#include "EffectContainer.h"


void EffectContainer::Fill()
{
	this->container.push_back(Effect("Burn", false, 5, 2));
	this->container.push_back(Effect("Freeze", false, 3, 3));
	this->container.push_back(Effect("Leech seed", false, 2, 3)); //Heal 2, 3
}

EffectContainer::EffectContainer()
{
	this->Fill();
}

EffectContainer::~EffectContainer()
{
}
