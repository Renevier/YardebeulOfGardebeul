#pragma once
#include "pch.h"

class Entity
{
	//Variables
protected:
	Texture *texture;
	Sprite *sprite;

	float movementSpeed;

	//Function
protected:
	void CreateSprite(Texture *_texture);
	void VariableInit();

public:
	Entity();
	virtual void SetPosition(const float _x, const float _y);
	virtual void Move(const float& _dt, const float _x, const float _y);
	virtual void Update(const float &_dt);
	virtual void Render(RenderTarget* _target);
	~Entity();

};

