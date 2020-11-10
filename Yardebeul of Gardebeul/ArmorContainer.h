#pragma once
#include "Armor.h"
#include "pch.h"

class ArmorContainer
{
protected:
	vector<Armor> container;

private:
	void Fill();

public:
	ArmorContainer();
	~ArmorContainer();
};
