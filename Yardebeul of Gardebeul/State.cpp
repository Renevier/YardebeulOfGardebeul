#include "State.h"

State::State(RenderWindow *_window)
{
	this->window = _window;
	this->Quit = false;
}

void State::CheckForQuit()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		this->Quit = true;
	}
}

const bool& State::GetQuit() const
{
	return this->Quit;
}

State::~State()
{
}