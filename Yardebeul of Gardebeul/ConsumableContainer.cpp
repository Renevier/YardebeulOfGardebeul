#include "pch.h"
#include "ConsumableContainer.h"

void ConsumableContainer::Fill()
{
	EffectContainer containerOfEffect;

	Effect smallHealEffect = containerOfEffect.GetContainer().at("Small heal");
	Effect healEffect = containerOfEffect.GetContainer().at("Heal");
	Effect bigHealEffect = containerOfEffect.GetContainer().at("Big heal");

	this->container.emplace("Little potion of heal", Consumable("Little potion of heal", 10, smallHealEffect, 1));
	this->container.emplace("Potion of heal", Consumable("Potion of heal", 25, healEffect, 1));
	this->container.emplace("Big potion of heal", Consumable("Big potion of heal", 50, smallHealEffect, 1));
}

ConsumableContainer::ConsumableContainer()
{
	this->Fill();
}

ConsumableContainer::~ConsumableContainer()
{
}
