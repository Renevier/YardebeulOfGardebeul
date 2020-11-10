#pragma once
#include "Object.h"
class Weapon :
    public Object
{
	//Variables
protected:
	float attack;

	//Functions
protected:
	void InitVariables(string _name, float _price, float _durability, float _attack, int _levelToAccess);

public:
	Weapon(string _name, float _price, float _durability, float _attack, int _levelToAccess);
	virtual void Choose();
	virtual void DisplayStat();
	~Weapon();
};