#pragma once
#include "Character.h"
class Hero :
    public Character
{
	//Variables
	float currentExp;
	float expNeed;
	float totalExp;

	int caracPoint;
	//Function

private:
	virtual void InitVariable();
	void InitComponent(float _x, float _y, Texture* _texture);

public:
	Hero(float _x, float _y, Texture* _texture);
	virtual void DisplayStats();
	void LevelProgress();
	void GainExp(float _exp);
	void LvlUp(vector<int> _arrayOfExp);
	void PickedUp();
	float TotalExpNeed();
	~Hero();

};

