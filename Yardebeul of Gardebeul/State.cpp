#include "State.h"

State::State(RenderWindow *_window, map<string, int>* _supportedKeys)
{
	this->window = _window;
	this->Quit = false;
	this->supportedKeys = _supportedKeys;
}

void State::UpdateMousePosition()
{
	this->mousePosScreen = Mouse::getPosition();
	this->mousePosWindow = Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(Mouse::getPosition(*this->window));
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