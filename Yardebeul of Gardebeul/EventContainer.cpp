#include "pch.h"
#include "EventContainer.h"

void EventContainer::Fill()
{
	//Fire
	/*0*/this->container.emplace("Fire/nothing", cEvent("Fire path", "path surround by fire", STATE_EVENT::NOTHING, BIOME::FIRE, false));
	/*1*/this->container.emplace("Fire/fight", cEvent("Fire/fight", "combat with a fire enemy", STATE_EVENT::FIGHT, BIOME::FIRE, true));
	/*2*/this->container.emplace("Fire/meet", cEvent("Fire/meet", "meet an fire guys", STATE_EVENT::MEET, BIOME::FIRE, false));
	/*3*/this->container.emplace("Fire/environement", cEvent("Fire/environement", "meet something ...", STATE_EVENT::ENVIRONEMENT, BIOME::FIRE, true));
	/*4*/this->container.emplace("Fire/puzzle", cEvent("Fire/puzzle", "fire puzzle", STATE_EVENT::PUZZLE, BIOME::FIRE, true));

	//Water
	/*5*/this->container.emplace("Water/nothing", cEvent("Water path", "path surround by Water", STATE_EVENT::NOTHING, BIOME::WATER, false));
	/*6*/this->container.emplace("Water/fight", cEvent("Water/fight", "combat with a Water enemy", STATE_EVENT::FIGHT, BIOME::WATER, true));
	/*7*/this->container.emplace("Water/meet", cEvent("Water/meet", "meet an Water guys", STATE_EVENT::MEET, BIOME::WATER, false));
	/*8*/this->container.emplace("Water/environement", cEvent("Water/environement", "meet something ...", STATE_EVENT::ENVIRONEMENT, BIOME::WATER, true));
	/*9*/this->container.emplace("Water/puzzle", cEvent("Water/puzzle", "water puzzle", STATE_EVENT::PUZZLE, BIOME::WATER, true));

	//Plant
	/*10*/this->container.emplace("Plant/nothing", cEvent("Plant path", "path surround by plant", STATE_EVENT::NOTHING, BIOME::WATER, false));
	/*11*/this->container.emplace("Plant/fight", cEvent("Plant/fight", "combat with a Plant enemy", STATE_EVENT::FIGHT, BIOME::WATER, true));
	/*12*/this->container.emplace("Plant/meet", cEvent("Plant/meet", "meet a Plant guys", STATE_EVENT::MEET, BIOME::WATER, false));
	/*11*/this->container.emplace("Plant/environement", cEvent("Plant/environement", "meet something ...", STATE_EVENT::ENVIRONEMENT, BIOME::WATER, true));
	/*14*/this->container.emplace("Plant/puzzle", cEvent("Plant/puzzle", "Plant puzzle", STATE_EVENT::PUZZLE, BIOME::WATER, true));
}

EventContainer::EventContainer()
{
	this->Fill();
}

EventContainer::~EventContainer()
{
}
