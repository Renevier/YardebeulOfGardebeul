#pragma once
#include "pch.h"
#include "Effect.h"

class EffectContainer
{
	//Variable
protected:
	vector<Effect> container;

	//Functions
private:
	void Fill();

public:
	EffectContainer();
	~EffectContainer();

};

