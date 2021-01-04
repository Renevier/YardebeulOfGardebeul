#include "pch.h"
#include "Hero.h"

void Hero::InitVariable()
{

}

void Hero::InitComponent(float _x, float _y, Texture& _texture_sheet)
{
	Character::InitComponent(_x, _y, _texture_sheet);
	this->CreateAttributeComponent(1);

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

void Hero::PickedUp()
{
	//put the object in the inventory
}

void Hero::Update(const float& _dt)
{
	if(Keyboard::isKeyPressed(Keyboard::E))
		this->attributeComponent->GainExp(20);

	/*system("CLS");
	cout << this->attributeComponent->Debug();*/

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

Hero::~Hero()
{
	delete this->movementComponent;
}
