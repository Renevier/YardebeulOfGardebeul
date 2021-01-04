#pragma once
class AttributeComponent
{
public:
	unsigned level;
	unsigned exp;
	unsigned expNext;
	unsigned attributePoint;

	int strength;
	int vitality;
	int dexterity;
	int agility;
	int intelligence;

	int hp;
	int hpMax;
	int damageMin;
	int damageMax;
	int accuracy;
	int defence;
	int luck;


public:
	AttributeComponent(unsigned _level);
	~AttributeComponent();

	string Debug();

	void GainExp(unsigned _exp);

	void UpdateStats(bool _reset);
	void UpdateLevel();

	void Update();

	//Get

	//Set
};

