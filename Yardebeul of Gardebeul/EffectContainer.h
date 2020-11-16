#pragma once
#include "pch.h"
#include "Effect.h"

class EffectContainer
{
	//Variable
protected:
	map<string, Effect> container;

	//Functions
private:
	void Fill();

public:
	EffectContainer();
	~EffectContainer();

	//Get
	inline map<string, Effect> GetContainer() const { return this->container; }

	//Set

};

