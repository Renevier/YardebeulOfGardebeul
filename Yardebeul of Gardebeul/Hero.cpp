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

void Hero::InitComponent(float _x, float _y, Texture& _texture_sheet)
{
	this->SetPosition(_x, _y);

	this->CreateMovementComponent(300.f, 15.f, 5.f);
	this->CreateAnimationComponent(_texture_sheet);
	this->CreateHitBoxComponent(this->sprite, -5.f, 0.f, 35.f, 35.f);

	this->animationComponent->AddAnimation("IDLE_FRONT", 150.f, 0, 0, 3, 0, 23, 33);
	this->animationComponent->AddAnimation("WALK_DOWN",  100.f, 0, 1, 4, 1, 23, 33);
	this->animationComponent->AddAnimation("WALK_RIGHT", 100.f, 0, 2, 5, 2, 25, 34);
	this->animationComponent->AddAnimation("WALK_LEFT",  100.f, 0, 4, 5, 4, 25, 36);
	this->animationComponent->AddAnimation("WALK_UP",    100.f, 0, 3, 5, 3, 27, 36);
}

Hero::Hero(float _x, float _y, Texture& _texture)
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

void Hero::Update(const float& _dt)
{
	this->movementComponent->Update(_dt);

	if(this->movementComponent->isIdle())
		this->animationComponent->Play("IDLE_FRONT", _dt);

	else if(this->movementComponent->isMovingBottom())
		this->animationComponent->Play("WALK_DOWN", _dt);

	else if (this->movementComponent->isMovingRight())
		this->animationComponent->Play("WALK_RIGHT", _dt);

	else if (this->movementComponent->isMovingTop())
		this->animationComponent->Play("WALK_UP", _dt);

	else if (this->movementComponent->isMovingLeft())
		this->animationComponent->Play("WALK_LEFT", _dt);
	

	this->hitBoxComponent->Update();
}

float Hero::GetCurrentExp()
{
	return this->currentExp;
}

float Hero::GetExpNeed()
{
	return this->expNeed;
}

float Hero::GetTotalExp()
{
	return this->totalExp;
}

int Hero::GetCaracPoint()
{
	return this->caracPoint;
}

Hero::~Hero()
{
	delete this->movementComponent;
}
