#include "MovementComponent.h"

MovementComponent::MovementComponent(Sprite& _sprite, float _maxVelocity, float _acceleration, float _deceleretion)
	:sprite(_sprite), maxVelocity(_maxVelocity), acceleration(_acceleration), deceleration(_deceleretion)
{
	this->maxVelocity = _maxVelocity;
}

void MovementComponent::Move(const float _dir_x, const float _dir_y, const float& _dt)
{
	//Acceleration
	this->velocity.x += this->acceleration * _dir_x;
	this->velocity.y += this->acceleration * _dir_y;	
}

void MovementComponent::Update(const float& _dt)
{

	if (velocity.x > 0)
	{
		//Max velocity check positive
		if (this->velocity.x > this->maxVelocity)
			this->velocity.x = this->maxVelocity;
				
		//Deceleration x positive
		this->velocity.x -= this->deceleration;
		if (velocity.x < 0)
			this->velocity.x = 0;

	}
	else if (velocity.x < 0)
	{
		//Max velocity check x negative
		if (this->velocity.x < -this->maxVelocity)
			this->velocity.x = -this->maxVelocity;

		//Deceleration x negative
		this->velocity.x += this->deceleration;
		if (velocity.x > 0)
			this->velocity.x = 0;
	}

	if (velocity.y > 0)
	{
		//Max velocity positive check 
		if (this->velocity.y > this->maxVelocity)
			this->velocity.y = this->maxVelocity;

		//Deceleration positive x 
		this->velocity.y -= this->deceleration;
		if (velocity.y < 0)
			this->velocity.y = 0;

	}
	else if (velocity.y < 0)
	{
		//Max velocity check negative x 
		if (this->velocity.y < -this->maxVelocity)
			this->velocity.y = -this->maxVelocity;

		//Deceleration negative x 
		this->velocity.y += this->deceleration;
		if (velocity.y > 0)
			this->velocity.y = 0;
	}

	//Final move
	this->sprite.move(this->velocity * _dt);
}

MovementComponent::~MovementComponent()
{
}
