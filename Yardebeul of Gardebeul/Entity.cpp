#include "Entity.h"

void Entity::SetTexture(Texture& _texture)
{
	this->sprite.setTexture(_texture);
}

void Entity::CreateMovementComponent(const float _maxVelocity, float _acceleration, float _deceleretion)
{
	this->movementComponent = new MovementComponent(this->sprite, _maxVelocity, _acceleration, _deceleretion);
}

void Entity::VariableInit()
{	
	this->movementComponent = nullptr;
}

Entity::Entity()
{
	this->VariableInit();
}

void Entity::SetPosition(const float _x, const float _y)
{
	this->sprite.setPosition(_x, _y);
}

void Entity::Move(const float _dir_x, const float _dir_y, const float& _dt)
{
	if (this->movementComponent)
	{
		this->movementComponent->Move(_dir_x, _dir_y, _dt);
	}
}

void Entity::Update(const float& _dt)
{
	if (this->movementComponent)
		this->movementComponent->Update(_dt);
	
}

void Entity::Render(RenderTarget* _target)
{
	_target->draw(this->sprite);		
}


Entity::~Entity()
{
}
