#pragma once
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

	//Function
private:	
	virtual void InitVariable() = 0;

public:
	Character();
	virtual void DisplayStats() = 0;
	~Character();
};