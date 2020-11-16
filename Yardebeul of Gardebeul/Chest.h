#pragma once
#include "Object.h"
#include "Entity.h"

class Chest: public Entity
{
	//Variables
protected:
	string name;
	map<string, Object*> chest; //'Object' is a pointeur because 'object' class is abstract

	//Functions
private:

public:
	Chest(string _name, Object* _myObject);
	~Chest();
};

