#include "pch.h"
#include "ChestContainer.h"

void ChestContainer::Fill()
{
	WeaponContainer myWeaponContainer;
	ArmorContainer myArmorContainer;
	ConsumableContainer myConsumableContainer;

	Chest questChest("QUEST_CHEST", &myArmorContainer.GetContainer().at(0));
	Chest bossChest("CHEST_BOSS", &myArmorContainer.GetContainer().at(0));
	Chest puzzleChest("PUZZLE_CHEST", &myArmorContainer.GetContainer().at(0));

	this->container.emplace("Chest of quest", questChest);
	this->container.emplace("Chest of boss", bossChest);
	this->container.emplace("Chest of puzzle", puzzleChest);
}

ChestContainer::ChestContainer()
{
	this->Fill();
}

ChestContainer::~ChestContainer()
{

}
