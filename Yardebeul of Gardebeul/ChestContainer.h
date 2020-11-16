#pragma once
#include "WeaponContainer.h"
#include "ArmorContainer.h"
#include "ConsumableContainer.h"
#include "Chest.h"
#include "pch.h"

class ChestContainer
{
protected:
	map<string, Chest> container;

private:
	void Fill();

public:
	ChestContainer();
	~ChestContainer();

};