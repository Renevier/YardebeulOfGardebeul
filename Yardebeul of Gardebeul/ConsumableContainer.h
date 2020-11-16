#pragma once
#include "Consumable.h"
#include "EffectContainer.h"
#include "pch.h"

class ConsumableContainer
{
protected:
	map<string, Consumable> container;

private:
	void Fill();

public:
	ConsumableContainer();
	~ConsumableContainer();

	//get
	inline  map<string, Consumable> GetContainer() const { return this->container; }

	//set
};
