#pragma once
#include "Weapon.h"

class WeaponContainer
{
	//Variable
protected:
	map<string, Weapon> container;

	//Fonctions
private:
	void Fill();

public:
	WeaponContainer();
	~WeaponContainer();
};


