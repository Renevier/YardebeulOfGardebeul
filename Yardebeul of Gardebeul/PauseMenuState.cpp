#include "PauseMenuState.h"

void PauseMenuState::InitButton()
{
	this->buttons.emplace("SAVE_GAME", new Button(100, 420, 250, 50,
		&this->font, "Save game", Color::White, Color::Green, Color::Red));
}

PauseMenuState::PauseMenuState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states)
	:MainMenuState(_window, _supportedKeys, _states)
{
	this->InitFont();
	this->InitButton();
}

void PauseMenuState::UpdateButton()
{
	//if (this->buttons.at("SAVE_GAME")->IsPressed())
}

PauseMenuState::~PauseMenuState()
{
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
		delete it->second;
}
