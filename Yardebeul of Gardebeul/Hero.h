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

private:
	virtual void InitVariable();
	void InitComponent(float _x, float _y, Texture& _texture_sheet);

public:
	Hero(float _x, float _y, Texture& _texture);
	~Hero();

	virtual void DisplayStats();
	void LevelProgress();
	void GainExp(float _exp);
	void LvlUp(vector<int> _arrayOfExp);
	void PickedUp();
	float TotalExpNeed();
	virtual void Update(const float& _dt);

	//Getter
	float GetCurrentExp();
	float GetExpNeed();
	float GetTotalExp();
	int GetCaracPoint();
};

