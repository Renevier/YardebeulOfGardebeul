#include "MainMenuState.h"

void MainMenuState::InitKeybins()
{
	this->keybinds.emplace("ESCAPE", this->supportedKeys->at("Escape"));
}

void MainMenuState::InitFont()
{
	if (!this->font.loadFromFile("../Ressources/Font/rpgFont.ttf"))
	{
		throw("ERROR::MAINMENU::COULD NOT LOAD FONT");
	}
}

void MainMenuState::InitButton()
{
	this->buttons.emplace("GAME_STATE", new Button(100, 100, 150, 150,
		&this->font, "New Game", Color::White, Color::Green, Color::Red));

	this->buttons.emplace("EXIT_STATE", new Button(100, 300, 150, 150,
		&this->font, "Quit", Color::White, Color::Green, Color::Red));

}

MainMenuState::MainMenuState(RenderWindow* _window, map<string, int>* _supportedKeys) : State(_window, _supportedKeys)
{
	this->InitFont();
	this->InitKeybins();
	this->InitButton();
	
	this->background.setSize(Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(Color::Magenta);
}

void MainMenuState::UpdateInput(const float& _dt)
{
}

void MainMenuState::UpdateButton()
{
	for (auto it : this->buttons)
		it.second->Update(this->mousePosView);

	if (this->buttons.at("GAME_STATE")->IsPressed())
		//this->Quit = true;

	if (this->buttons.at("EXIT_STATE")->IsPressed())
		this->Quit = true;
}

void MainMenuState::Update(const float& _dt)
{
	this->UpdateMousePosition();
	this->CheckForQuit();
	this->UpdateButton();
}

void MainMenuState::RenderButton(RenderTarget* _target)
{
	for (auto it : this->buttons)
	{
		it.second->Render(_target);
	}
}

void MainMenuState::Render(RenderTarget* _target)
{
	if (!_target)
		_target = this->window;

	_target->draw(this->background);

	this->RenderButton(_target);
}

void MainMenuState::EndState()
{
}

MainMenuState::~MainMenuState()
{
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}
