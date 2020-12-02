#include "PauseMenuState.h"

void PauseMenuState::InitKeybinds()
{
}

void PauseMenuState::InitButton()
{
	/*this->buttons.emplace("SAVE_GAME", new Button(100, 420, 250, 50,
		&this->font, "Save game", Color::White, Color::Green, Color::Red));*/
}

void PauseMenuState::InitBackground()
{
	this->background.setSize(Vector2f((float)this->window->getSize().x, (float)this->window->getSize().y));

	if (!this->backgroundTexture.loadFromFile("../Ressources/Background/backgound_menu.png"))
		exit(0);

	this->background.setTexture(&this->backgroundTexture);
}

PauseMenuState::PauseMenuState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states)
	:State(_window, _supportedKeys, _states)
{
	this->InitBackground();
	this->InitButton();
}

void PauseMenuState::UpdateButton()
{
	//Resume game button
	//Quit the pause menu state

	//save game
	//if (this->buttons.at("SAVE_GAME")->IsPressed())
	//this->Save();

	//return to the main menu button
	//Quit the pause menu sate and the game state
}

void PauseMenuState::UpdateInput(const float& _dt)
{
}

void PauseMenuState::Update(const float& _dt)
{
}

void PauseMenuState::Render(RenderTarget* _target)
{
	_target->draw(this->background);

	//print mouse potiton in the console
	system("CLS");
	cout << this->mousePosView.x << " " << this->mousePosView.y;
}

void PauseMenuState::EndState()
{
}

PauseMenuState::~PauseMenuState()
{
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
		delete it->second;
}
