#pragma once
#include "Entity.h"

//Mother of all our states
class State
{
private:  
	RenderWindow* window;
	bool Quit;

public:
	State(RenderWindow *_window);
	virtual void UpdateInput(const float& _dt) = 0;
	virtual void Update(const float &_dt) = 0;
	virtual void Render(RenderTarget *_target = nullptr) = 0;
	virtual void CheckForQuit();
	virtual void EndState() = 0;
	const bool& GetQuit() const;
	~State();

};