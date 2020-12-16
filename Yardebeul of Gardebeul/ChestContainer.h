#pragma once
#include "WeaponContainer.h"
#include "ArmorContainer.h"
#include "ConsumableContainer.h"
#include "Chest.h"


class ChestContainer
{
protected:
	map<string, Chest> container;

private:
	void Fill();

public:
	ChestContainer();
	~ChestContainer();

	//get
	inline  map<string, Chest> GetContainer() const { return this->container; }

	//set
};