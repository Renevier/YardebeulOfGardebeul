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
	map<string, Effect> const GetContainer() const;
	~EffectContainer();

};

