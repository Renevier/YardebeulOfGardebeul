#pragma once
#include"Weapon.h"
#include"Entity.h"

class Character: public Entity
{
protected:
	//Variables
	string name;
	int level;
	float healthPoints;
	float manaPoints;
	float endurePoints;
	float mindPoints;
	int pointToDistribute;

	Weapon *weapon;

	//Function
protected:

public:
	Character();
	virtual void DisplayStats() = 0;
	~Character();
};