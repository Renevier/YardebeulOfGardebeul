#pragma once

class MovementComponent
{
protected:
	Sprite& sprite;

	float maxVelocity;

	Vector2f velocity;
	float acceleration;
	float deceleration;

private:

public:
	MovementComponent(Sprite& _sprite, float _maxVelocity, float _acceleration, float _deceleretion);
	void Move(const float _dir_x, const float _dir_y, const float& _dt);
	void Update(const float& _dt);
	~MovementComponent();

	bool isIdle();
	bool isMovingLeft();
	bool isMovingRight();
	bool isMovingTop();
	bool isMovingBottom();

	inline Vector2f& GetVelocity() { return this->velocity; }
};

