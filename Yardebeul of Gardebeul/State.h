#pragma once
#include "Entity.h"

//Mother of all our states
class State
{
	//Variables
protected:  
	RenderWindow* window;
	map<string, int>* supportedKeys;
	map<string, int> keybinds;
	bool Quit;

	Vector2i mousePosScreen;
	Vector2i mousePosWindow;
	Vector2f mousePosView;

	vector<Texture> states;

	//Functions
private:
	virtual void InitKeybins() = 0;

public:
	State(RenderWindow *_window, map<string, int>* _supportedKeys);
	virtual void UpdateMousePosition();
	virtual void UpdateInput(const float& _dt) = 0;
	virtual void Update(const float &_dt) = 0;
	virtual void Render(RenderTarget *_target) = 0;
	virtual void CheckForQuit();
	virtual void EndState() = 0;
	const bool& GetQuit() const;
	~State();

};