#include "pch.h"
#include "SaveState.h"

void SaveState::InitKeybinds()
{
}

void SaveState::InitButton()
{
	this->buttons.emplace("SAVE_1", new Button(100, 420, 250, 50,
		&this->font, "Save 1", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

	this->buttons.emplace("SAVE_2", new Button(100, 520, 250, 50,
		&this->font, "Save 2", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

	this->buttons.emplace("SAVE_3", new Button(100, 600, 250, 50,
		&this->font, "Save 3", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

	this->buttons.emplace("EXIT", new Button(100, 700, 250, 50,
		&this->font, "Quit", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));
}

void SaveState::InitFont()
{
	if (!this->font.loadFromFile("../Ressources/Fonts/rpgFont.ttf"))
		exit(0);
}

void SaveState::InitBackground()
{
	this->background.setSize(Vector2f((float)this->window->getSize().x, (float)this->window->getSize().y));

	if (!this->backgroundTexture.loadFromFile("../Ressources/Background/backgound_menu.png"))
		exit(0);

	this->background.setTexture(&this->backgroundTexture);
}

SaveState::SaveState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states) :State(_window, _supportedKeys, _states)
{
	this->InitBackground();
	this->InitFont();
	this->InitButton();
}

void SaveState::UpdateButton()
{
	string nameFile;

	for (auto it : this->buttons)
		it.second->Update(this->mousePosView);	

	if (this->buttons.at("SAVE_1")->IsPressed())
	{
		nameFile = "Save1.txt";
	}

	if (this->buttons.at("SAVE_2")->IsPressed())
	{
		nameFile = "Save2.txt";
	}

	if (this->buttons.at("SAVE_3")->IsPressed())
	{
		nameFile = "Save3.txt";
	}

	if (this->buttons.at("EXIT")->IsPressed())
	{
		this->states->pop();
	}

}

void SaveState::Save(string _name_file)
{
	string path = "../Ressouces/Saves/" + _name_file;
}

void SaveState::UpdateInput(const float& _dt)
{
	this->UpdateButton();
}

void SaveState::Update(const float& _dt)
{
	this->UpdateMousePosition();
	this->UpdateInput(_dt);
}

void SaveState::RenderButton(RenderTarget& _target)
{
	for (auto it : this->buttons)
		it.second->Render(_target);
}

void SaveState::Render(RenderTarget* _target)
{
	if (!_target)
		_target = this->window;

	_target->draw(this->background);

	this->RenderButton(*_target);
}

void SaveState::EndState()
{
}

SaveState::~SaveState()
{
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
		delete it->second;
}
