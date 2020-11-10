#pragma once
#include "Entity.h"

class Effect
{
	//Varibles
protected:
	string name;
	bool isAoe;
	float damage;
	float duration;

	//Function
private:
	void InitVariable(string _name, bool _isAoe, float _damage, float _duration);

public:
	Effect();
	Effect(string _name, bool _isAoe, float _damage, float _duration);
	void AffectPlayer();
	~Effect();

};


