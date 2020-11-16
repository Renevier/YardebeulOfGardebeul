#pragma once
#include "Armor.h"
#include "pch.h"

class ArmorContainer
{
protected:
	map<string, Armor> container;

private:
	void Fill();

public:
	ArmorContainer();
	~ArmorContainer();

	//get
	inline  map<string, Armor> GetContainer() const { return this->container; }

	//set
};