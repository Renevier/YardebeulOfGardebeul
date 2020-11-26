#include "Hero.h"

void Hero::InitVariable()
{
	this->level = 1.f;
	this->manaPoints = 100.f;
	this->healthPoints = 100.f;
	this->endurePoints = 50.f;
	this->mindPoints = 25.f;

	this->currentExp = .0f;
	this->expNeed = .0f;
	this->totalExp = .0f;
}

void Hero::InitComponent(float _x, float _y, Texture* _texture)
{
	this->CreateSprite(_texture);
	this->SetPosition(_x, _y);
}

Hero::Hero(float _x, float _y, Texture* _texture)
{
	this->InitVariable();
	this->InitComponent(_x, _y, _texture);
}

void Hero::DisplayStats()
{
	cout << endl << "Stat of " << this->name << endl;
	cout << " Level: " << this->level << endl;
	cout << " HP: " << this->healthPoints << endl;
	cout << " Mp: " << this->manaPoints << endl;
	cout << " EndurePoint: " << this->endurePoints << endl;
	cout << " MindPoint: " << this->mindPoints << endl;
}

void Hero::LevelProgress()
{
	float percent = 0.0f;

	if ((this->currentExp + this->expNeed) == 0)
		percent = 100.0f;
	else if ((this->currentExp + this->expNeed) != 0)
		percent = this->currentExp / (this->currentExp + this->expNeed) * 100;
}

void Hero::GainExp(float _exp)
{
	this->currentExp += _exp;

	cout << "you gain " << _exp << " experience";

	this->TotalExpNeed(); 
}

void Hero::LvlUp(vector<int> _arrayOfExp)
{
	int i = _arrayOfExp[this->level];

	if (this->currentExp >= _arrayOfExp[this->level + 1] && this->currentExp > i)
	{
		this->level++;
		this->caracPoint++;
	}
}

void Hero::PickedUp()
{
	//put the object in the inventory
}

float Hero::TotalExpNeed()
{
	vector<int> arrayOfLvl;
	vector<int> arrayOfExp;
	int expNeeded;

	for (int i = 0; i <= 99; i++)
		arrayOfLvl.push_back(i);

	for (int i = 0; i <= 99; i++)
		arrayOfExp.push_back(i * 100);

	for (int j = 0; j <= 100; j++)
	{
		if (j == this->level)
		{
			LvlUp(arrayOfExp);
			return arrayOfExp.at(j);
		}
	}
}

Hero::~Hero()
{
}
