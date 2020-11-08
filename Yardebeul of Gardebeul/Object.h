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
	virtual void InitVariables();

public:
	Object();
	virtual void Choose() = 0;
	virtual void DisplayStat() = 0;
	~Object();
};
