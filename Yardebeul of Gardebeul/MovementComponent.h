#pragma once
#include "pch.h"

class MovementComponent
{
protected:
	Sprite& sprite;

	float maxVelocity;

	Vector2f velocity;
	Vector2f acceleration;
	Vector2f deceleration;

private:

public:
	MovementComponent(Sprite& _sprite, float _maxVelocity);
	void Move(const float _dir_x, const float _dir_y, const float& _dt);
	void Update(const float& _dt);
	~MovementComponent();

	inline Vector2f& GetVelocity() { return this->velocity; }
};

