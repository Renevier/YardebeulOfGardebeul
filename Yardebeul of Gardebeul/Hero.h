#pragma once
#include "Character.h"
class Hero :
    public Character
{
	//Variables
	float currentExp;
	float expNeed;
	float totalExp;

	//Function

private:

	virtual void InitVariable(string _name);

public:
	Hero(string _name, float _x, float _y, Texture* texture);
	void LevelProgress();
	void LvlUp(vector<int> _arrayOfExp);
	void PickedUp();
	float TotalExpNeed();
	~Hero();

};

