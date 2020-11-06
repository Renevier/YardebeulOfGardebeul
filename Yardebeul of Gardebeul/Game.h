#pragma once
#include "State.h"

class Game
{
private:
	RenderWindow *window;
	Event event;

	Clock clock;
	float deltaTime;

public:
	Game();
	void Run();
	void Update();
	void UpdateEvent();
	void UpdateDt();
	void Render();
	~Game();

private:
	void InitWindow();
};



