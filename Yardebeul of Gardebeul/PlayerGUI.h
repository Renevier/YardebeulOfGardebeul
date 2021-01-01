#pragma once
#include "Hero.h"

class PlayerGUI
{
private:
	Hero* player;

public:
	PlayerGUI(Hero* _player);
	~PlayerGUI();

	void Update(const float& _dt);
	void Render(RenderTarget& _target);
};