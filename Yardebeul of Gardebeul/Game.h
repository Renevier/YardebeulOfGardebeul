#pragma once
#include "GameState.h"

class Game
{
private:
	RenderWindow *window;
	Event event;

	Clock clock;
	float deltaTime;

	stack<State*> states;

private:
	void InitWindow();
	void InitState();

public:
	Game();
	void Run();
	void Update();
	void UpdateEventSFML();
	void UpdateDt();
	void Render();
	~Game();


};



