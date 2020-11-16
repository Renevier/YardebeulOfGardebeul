#pragma once
#include "Object.h"
#include "Entity.h"

class Chest: public Entity
{
	//Variables
protected:
	string name;

	//'Object' is a pointeur because 'object' class is abstract
	map<string, Object*> chest; 

	//Functions
private:

public:
	Chest(string _name, Object* _myObject);
	~Chest();
};

