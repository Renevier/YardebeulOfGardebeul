#pragma once
#include "MovementComponent.h"
#include "AnimationComponent.h"

class Entity
{
protected:
	Sprite sprite;

	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;

protected:
	void VariableInit();
	void SetTexture(Texture& _texture);
	void CreateMovementComponent(const float _maxVelocity, float _acceleration, float _deceleretion);
	void CreateAnimationComponent(Texture& _texture_sheet);

public:
	Entity();
	virtual void SetPosition(const float _x, const float _y);
	virtual void Move(const float _x, const float _y, const float& _dt);
	virtual void Update(const float &_dt);
	virtual void Render(RenderTarget* _target);
	~Entity();

};

