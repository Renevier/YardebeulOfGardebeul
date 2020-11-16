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

	//get
	inline  map<string, Weapon> GetContainer() const { return this->container; }

	//set
};


