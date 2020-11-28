#pragma once
#include "MovementComponent.h"

class Entity
{
	//Variables
protected:
	Sprite sprite;

	MovementComponent* movementComponent;
	//Function
protected:
	void VariableInit();
	void SetTexture(Texture& _texture);
	void CreateMovementComponent(const float _maxVelocity);

public:
	Entity();
	virtual void SetPosition(const float _x, const float _y);
	virtual void Move(const float& _dt, const float _x, const float _y);
	virtual void Update(const float &_dt);
	virtual void Render(RenderTarget* _target);
	~Entity();

};

