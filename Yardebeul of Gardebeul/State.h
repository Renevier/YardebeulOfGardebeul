#pragma once
#include "Hero.h"

//Mother of all our states
class State
{
	//Variables
protected:  
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
	
	View view;
	float viewSpeed;

	map<string, Texture> textures;

	//Functions
private:
	virtual void InitKeybinds() = 0;
	virtual void InitView();

public:
	State(RenderWindow *_window, map<string, int>* _supportedKeys, stack<State*>* _states);
	~State();

	virtual void UpdateMousePosition();
	virtual void UpdateInput(const float& _dt) = 0;
	virtual void UpdateKeytime(const float& _dt);
	virtual void Update(const float& _dt) = 0;
	virtual void Render(RenderTarget* _target) = 0;
	virtual void EndState() = 0;

	inline void PauseState() { this->pause = true; }
	inline void UnpauseState() { this->pause = false; }

	inline bool GetQuit() { return this->quit; }
	bool GetKeytime();
};