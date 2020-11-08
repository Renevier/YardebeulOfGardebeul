#pragma once
#include "Weapon.h"

class WeaponContainer
{
	//Variable
protected:
	vector<Weapon> container;

	//Fonctions
private:
	void Fill();

public:
	WeaponContainer();
	~WeaponContainer();
};


