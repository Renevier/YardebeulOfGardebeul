#include "MovementComponent.h"

MovementComponent::MovementComponent(Sprite& _sprite, float _maxVelocity)
	:sprite(_sprite), maxVelocity(_maxVelocity)
{
	this->maxVelocity = _maxVelocity;
}

void MovementComponent::Move(const float _dir_x, const float _dir_y, const float& _dt)
{
	this->velocity.x = this->maxVelocity * _dir_x;
	this->velocity.y = this->maxVelocity * _dir_y;

	this->sprite.move(this->velocity * _dt);
}

void MovementComponent::Update(const float& _dt)
{

}

MovementComponent::~MovementComponent()
{
}
