#pragma once


class HitBoxComponent
{
protected:
	Sprite& sprite;
	RectangleShape hitBox;

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

