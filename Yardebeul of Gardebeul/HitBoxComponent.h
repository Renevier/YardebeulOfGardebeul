#pragma once
#include "pch.h"

class HitBoxComponent
{
protected:
	RectangleShape hitBox;
	Sprite& sprite;

	float offsetX;
	float offsetY;

private:

public:
	HitBoxComponent(Sprite& _sprite, float _offset_x, float _offset_y, float _width, float _height);
	~HitBoxComponent();

	bool CheckIntersect(const FloatRect& _frect);
	void Update();
	void Render(RenderTarget& _target);
};

