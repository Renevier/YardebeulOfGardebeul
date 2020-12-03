#include "PauseMenuState.h"

void PauseMenuState::InitKeybinds()
{
}

void PauseMenuState::InitButton()
{
	this->buttons.emplace("SAVE_GAME", new Button(100, 520, 250, 50,
		&this->font, "Save game", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));
}

void PauseMenuState::InitFont()
{
	if (!this->font.loadFromFile("../Ressources/Fonts/rpgFont.ttf"))
		exit(0);
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
	this->InitFont();
	this->InitButton();
}

void PauseMenuState::Save()
{
	system("CLS");
	cout << "Game saved";
}

void PauseMenuState::UpdateButton()
{
	for (auto it : this->buttons)
		it.second->Update(this->mousePosView);
	
	//Resume game button
	//Quit the pause menu state

	//save game
	if (this->buttons.at("SAVE_GAME")->IsPressed())
		this->Save();

	//return to the main menu button
	//Quit the pause menu sate and the game state
}

void PauseMenuState::UpdateInput(const float& _dt)
{
	this->UpdateButton();
}

void PauseMenuState::Update(const float& _dt)
{
	this->UpdateMousePosition();
	this->UpdateInput(_dt);
}

void PauseMenuState::RenderButton(RenderTarget& _target)
{
	for (auto it : this->buttons)
		it.second->Render(_target);
}

void PauseMenuState::Render(RenderTarget* _target)
{
	_target->draw(this->background);

	this->RenderButton(*_target);

	//print mouse potiton in the console
	/*system("CLS");
	cout << this->mousePosView.x << " " << this->mousePosView.y;*/
}

void PauseMenuState::EndState()
{
}

PauseMenuState::~PauseMenuState()
{
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
		delete it->second;
}
