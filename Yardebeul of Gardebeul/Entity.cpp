#include "Entity.h"

void Entity::CreateSprite(Texture *_texture)
{
	this->texture = _texture;
	this->sprite->setTexture(*this->texture);
}

void Entity::VariableInit()
{
	this->texture = nullptr;
	this->sprite = nullptr;
	this->movementSpeed = 100.f;
}

Entity::Entity()
{
	VariableInit();

}

void Entity::SetPosition(const float _x, const float _y)
{
	if(this->sprite)
		this->sprite->setPosition(_x, _y);
}

void Entity::Move(const float& _dt, const float _dir_x, const float _dir_y)
{
	if(this->sprite)
		this->sprite->move(_dir_x * this->movementSpeed * _dt, _dir_y * this->movementSpeed * _dt);
}


Entity::~Entity()
{
	delete this->sprite;
}
