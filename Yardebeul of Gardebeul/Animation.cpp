#include "Animation.h"

Animation::Animation(Texture& _textureSheet, float _animation_timer, int _start_x, int _start_y, int _end_x, int _end_y, int _width, int _height)
	:textureSheet(_textureSheet), animationTimer(_animation_timer), width(_width), height(_height)
{
	this->startRect = IntRect(_start_x, _start_y, _width, _height);
	this->endRect = IntRect(_end_x, _end_y, _width, _height);
}

void Animation::Update(const float& _dt)
{
	//Update timer
	this->timer = 10.f * _dt;

	if (this->timer >= animationTimer)
	{
		//reset timer
		this->timer = 0.f;


	}
}

Animation::~Animation()
{
}
