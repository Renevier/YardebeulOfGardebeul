#include "Animation.h"

Animation::Animation(Sprite& _sprite, Texture& _texture_sheet, float _animation_timer,
	int _start_frames_x, int _start_frames_y, int _frames_x, int _frames_y, int _width, int _height)
	:sprite(_sprite), textureSheet(_texture_sheet), animationTimer(_animation_timer), width(_width), height(_height)
{
	this->timer = 0;
	this->startRect = IntRect(_start_frames_x, _start_frames_y, _width, _height);
	this->currentRect = this->startRect;
	this->endRect = IntRect(_frames_x * width, _frames_y * height, _width, _height);

	this->sprite.setTexture(this->textureSheet, true);
	this->sprite.setTextureRect(this->startRect);
}

void Animation::Play(const float& _dt)
{
	//Update timer
	this->timer += 10.f * _dt;

	if (this->timer >= animationTimer)
	{
		//reset timer
		this->timer = 0.f;

		//Animate
		if (this->currentRect != this->endRect)
		{
			this->currentRect.left += this->width;
		}
		//Reset
		else
		{
			this->currentRect.left = this->startRect.left;
		}

		this->sprite.setTextureRect(this->currentRect);
	}
}

void Animation::Reset()
{
	this->timer = 0.f;
	this->currentRect = this->startRect;

}

Animation::~Animation()
{
}
