#pragma once
#include "MovementComponent.h"

class Entity
{
protected:
	Sprite sprite;

	MovementComponent* movementComponent;

protected:
	void VariableInit();
	void SetTexture(Texture& _texture);
	void CreateMovementComponent(const float _maxVelocity, float _acceleration, float _deceleretion);

public:
	Entity();
	virtual void SetPosition(const float _x, const float _y);
	virtual void Move(const float _x, const float _y, const float& _dt);
	virtual void Update(const float &_dt);
	virtual void Render(RenderTarget* _target);
	~Entity();

};

