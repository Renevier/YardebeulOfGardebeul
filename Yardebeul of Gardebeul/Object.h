#pragma once
#include "Effect.h"
#include "Entity.h"

class Object
{
	//Variables
protected:
	string name;
	float price;
	float durability;

	Effect* effect;

	//Functions
public:
	Object();
	virtual void Choose() = 0;
	virtual void DisplayStat() = 0;
	~Object();
};
