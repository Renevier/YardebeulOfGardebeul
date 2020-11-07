#pragma once
#include "pch.h"

class Entity
{
protected:

public:
	Entity();
	virtual void Update(const float &_dt) = 0;
	virtual void Render(RenderTarget &_target) = 0;
	~Entity();

};

