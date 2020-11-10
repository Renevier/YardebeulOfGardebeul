#include "EventContainer.h"

void EventContainer::Fill()
{
	//Fire
	this->container.emplace("Fire/nothing", cEvent("Fire path", "path surround by fire", STATE_EVENT::NOTHING, BIOME::FIRE, false));
	this->container.emplace("Fire/fight", cEvent("Fire/fight", "combat with a fire enemy", STATE_EVENT::FIGHT, BIOME::FIRE, true));
	this->container.emplace("Fire/meet", cEvent("Fire/meet", "meet an fire guys", STATE_EVENT::MEET, BIOME::FIRE, false));
	this->container.emplace("Fire/environement", cEvent("Fire/environement", "meet something ...", STATE_EVENT::ENVIRONEMENT, BIOME::FIRE, true));
	this->container.emplace("Fire/puzzle", cEvent("Fire/puzzle", "fire puzzle", STATE_EVENT::PUZZLE, BIOME::FIRE, true));

	//Water
	this->container.emplace("Water/nothing", cEvent("Water path", "path surround by Water", STATE_EVENT::NOTHING, BIOME::WATER, false));
	this->container.emplace("Water/fight", cEvent("Water/fight", "combat with a Water enemy", STATE_EVENT::FIGHT, BIOME::WATER, true));
	this->container.emplace("Water/meet", cEvent("Water/meet", "meet an Water guys", STATE_EVENT::MEET, BIOME::WATER, false));
	this->container.emplace("Water/environement", cEvent("Water/environement", "meet something ...", STATE_EVENT::ENVIRONEMENT, BIOME::WATER, true));
	this->container.emplace("Water/puzzle", cEvent("Water/puzzle", "water puzzle", STATE_EVENT::PUZZLE, BIOME::WATER, true));

	//Plant
	this->container.emplace("Plant/nothing", cEvent("Plant path", "path surround by plant", STATE_EVENT::NOTHING, BIOME::WATER, false));
	this->container.emplace("Plant/fight", cEvent("Plant/fight", "combat with a Plant enemy", STATE_EVENT::FIGHT, BIOME::WATER, true));
	this->container.emplace("Plant/meet", cEvent("Plant/meet", "meet an Plant guys", STATE_EVENT::MEET, BIOME::WATER, false));
	this->container.emplace("Plant/environement", cEvent("Plant/environement", "meet something ...", STATE_EVENT::ENVIRONEMENT, BIOME::WATER, true));
	this->container.emplace("Plant/puzzle", cEvent("Plant/puzzle", "Plant puzzle", STATE_EVENT::PUZZLE, BIOME::WATER, true));
}

EventContainer::EventContainer()
{
	this->Fill();
}

EventContainer::~EventContainer()
{
}
