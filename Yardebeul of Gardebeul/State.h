#pragma once
#include "Hero.h"

class State;

//This class going to send all of our data to another state
class StateData
{
public:
	float gridSize;
	RenderWindow* window;
	map<string, int>* supportedKeys;
	stack<State*>* states;

public:
	StateData() {};
	~StateData() {};
};


//Mother of all our states
class State
{
	//Variables
protected:  
	StateData* stateData;
	float gridSize;
	stack<State*>* states;
	RenderWindow* window;
	map<string, int>* supportedKeys;
	map<string, int> keybinds;

	bool wantSave;
	bool quit;
	bool pause;

	float keytime;
	float keytimeMax;

	Vector2i mousePosScreen;
	Vector2i mousePosWindow;
	Vector2f mousePosView;
	Vector2i mousePosGrid;
	
	View view;
	float viewSpeed;

	map<string, Texture> textures;

	//Functions
private:
	virtual void InitKeybinds() = 0;
	virtual void InitView();

public:
	State(StateData* _state_data);
	~State();

	virtual void UpdateMousePosition(View* view = nullptr);
	virtual void UpdateInput(const float& _dt) = 0;
	virtual void UpdateKeytime(const float& _dt);
	virtual void Update(const float& _dt) = 0;
	virtual void Render(RenderTarget* _target) = 0;
	virtual void EndState();

	inline void PauseState() { this->pause = true; }
	inline void UnpauseState() { this->pause = false; }

	inline bool GetQuit() { return this->quit; }
	bool GetKeytime();
};