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

	bool Intersect(const FloatRect& _frect);
	void Update();
	void Render(RenderTarget& _target);

	//Get
	inline Vector2f GetPosition() { return this->hitBox.getPosition(); }
	inline FloatRect GetGlobalBounds() { return this->hitBox.getGlobalBounds(); }

	//Set
	void SetPosition(Vector2f _position);
	void SetPosition(const float _x, const float _y);
};

