#pragma once
#include "Entity.h"

class Object
{
	//Variables
protected:
	string name;
	float price;
	float durability;

	//Functions
private:
	virtual void InitVariables() = 0;

public:
	Object();
	virtual void Choose() = 0;
	~Object();
};
