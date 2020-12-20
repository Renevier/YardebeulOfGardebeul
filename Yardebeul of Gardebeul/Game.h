#pragma once
#include "GameState.h"
#include "MainMenuState.h"

class Game
{
private:
	StateData stateData;
	RenderWindow* window;
	Event event;

	Clock clock;
	float deltaTime;

	stack<State*> states;

	map<string, int> supportedKeys;
	float gridSize;

private:

	void InitVariables();
	void InitStateData();
	void InitWindow();
	void InitKeys();
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