#pragma once
#include"Weapon.h"
#include"Entity.h"

class Character : public Entity
{
protected:
	//Variables
	string name;
	int level;
	float healthPoints;
	float manaPoints;
	float endurePoints;
	float mindPoints;

	Weapon* weapon;

	//Function
protected:

public:
	Character();
	virtual void DisplayStats() = 0;
	~Character();

	//getter
	inline string GetName() { return this->name; }
	inline int GetLevel() { return this->level; }
	inline float GetHP() { return this->healthPoints; }
	inline float GetMP() { return this->manaPoints; }
	inline float GetEndurePoint() { return this->endurePoints; }
	inline float GetMindPoint() { return this->mindPoints; }

	//Setter
	inline void SetLevel(int level) { this->level = level; }
	inline void SetHP(float Hp) { this->healthPoints = Hp; }
	inline void SetMP(float Mp) { this->manaPoints = Mp; }
	inline void SetEndurePoint(float endurePoint) { this->endurePoints = endurePoint; }
	inline void SetMindPoint(float mindPoint) { this->mindPoints = mindPoint; }
};