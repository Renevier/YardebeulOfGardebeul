#pragma once
#include "pch.h"

class Animation
{
public:
	Texture& textureSheet;
	IntRect startRect;
	IntRect endRect;

	int width;
	int height;

	float animationTimer;
	float timer;

public:
	Animation(Texture& _textureSheet, float _speed, int _start_x, int _start_y, int _end_x, int _end_y, int _width, int _height);
	void Update(const float& _dt);
	void Play();
	void Reset();
	~Animation();
};