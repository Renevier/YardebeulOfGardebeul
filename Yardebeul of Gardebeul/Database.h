#pragma once
#pragma once
#include "ArmorContainer.h"
#include "ChestContainer.h"
#include "ConsumableContainer.h"
#include "DungeonContainer.h"
#include "EffectContainer.h"
#include "EventContainer.h"
#include "NpcContainer.h"
#include "WeaponContainer.h"

class Database
{
protected:
	map<string, Entity*> database;
	ArmorContainer myArmorContainer;
	ChestContainer myChestContainer;
	ConsumableContainer myConsumableContainer;
	DungeonContainer myDungeonContainer;
	EffectContainer myEffectContainer;
	EventContainer myEventContainer;
	NpcContainer myNpcContainer;
	WeaponContainer myWeaponContainer;

private:
	void Fill();

public:
	Database();
	~Database();
};

