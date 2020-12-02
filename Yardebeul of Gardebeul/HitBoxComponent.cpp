#include "HitBoxComponent.h"

HitBoxComponent::HitBoxComponent(Sprite& _sprite, float _offset_x, float _offset_y, float _width, float _height)
	:sprite(_sprite), offsetX(_offset_x), offsetY(_offset_y)
{
	this->hitBox.setPosition(this->sprite.getPosition().x + _offset_x,
		this->sprite.getPosition().y + _offset_y);

	this->hitBox.setSize(Vector2f(_width, _height));
	this->hitBox.setFillColor(Color::Transparent);
	this->hitBox.setOutlineColor(Color::Green);
	this->hitBox.setOutlineThickness(1.f);

}

HitBoxComponent::~HitBoxComponent()
{
}


bool HitBoxComponent::CheckIntersect(const FloatRect& _frect)
{
	return this->hitBox.getGlobalBounds().intersects(_frect);
}

void HitBoxComponent::Update()
{
	this->hitBox.setPosition(this->sprite.getPosition().x + this->offsetX,
		this->sprite.getPosition().y + this->offsetY);
}

void HitBoxComponent::Render(RenderTarget& _target)
{
	_target.draw(this->hitBox);
}
