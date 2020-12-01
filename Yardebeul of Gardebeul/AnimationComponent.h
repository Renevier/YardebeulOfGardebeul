#pragma once
#include "Animation.h"
#include "pch.h"
class AnimationComponent
{
protected:
	map<string, Animation> animations;

private:

public:
	AnimationComponent(Sprite& _sprite, Texture& _texture_sheet);
	~AnimationComponent();

};

