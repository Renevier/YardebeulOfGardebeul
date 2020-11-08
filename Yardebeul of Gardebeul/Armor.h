#pragma once
#include "Object.h"
class Armor :public Object
{
	//Variables
protected:
	float defense;

	//Functions
private:
	void InitVariables(string _name, float _price, float _durability, float _defense);

public:
	Armor(string _name, float _price, float _durability, float _defense);
	virtual void DisplayStat();
	~Armor();
};

