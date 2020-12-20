#include "pch.h"
#include "MainMenuState.h"

void MainMenuState::InitKeybinds()
{
}

void MainMenuState::InitBackground()
{
	this->background.setSize(Vector2f((float)this->window->getSize().x, (float)this->window->getSize().y));

	if (!this->backgroundTexture.loadFromFile("../Ressources/Background/backgound_menu.png"))
		exit(0);

	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::InitFont()
{
	if (!this->font.loadFromFile("../Ressources/Fonts/rpgFont.ttf"))
		exit(0);
}

void MainMenuState::InitButton()
{
	this->buttons.emplace("NEW_GAME", new gui::Button(100, 500, 250, 50,
		&this->font, "New game", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

	this->buttons.emplace("LOAD_GAME", new gui::Button(100, 600, 250, 50,
		&this->font, "Load game", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

	this->buttons.emplace("MAP_EDITOR", new gui::Button(100, 700, 250, 50,
		&this->font, "Editor", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

	this->buttons.emplace("SETTING", new gui::Button(100, 800, 250, 50,
		&this->font, "Setting", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

	this->buttons.emplace("EXIT", new gui::Button(100, 1000, 250, 50,
		&this->font, "Quit", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

	this->buttons.emplace("SAVE_1", new gui::Button(100, 400, 250, 50,
		&this->font, "Save 1", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

	this->buttons.emplace("SAVE_2", new gui::Button(100, 500, 250, 50,
		&this->font, "Save 2", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

	this->buttons.emplace("SAVE_3", new gui::Button(100, 600, 250, 50,
		&this->font, "Save 3", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

	this->buttons.emplace("EXIT_SAVE", new gui::Button(100, 850, 250, 50,
		&this->font, "Quit", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));
}

MainMenuState::MainMenuState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states)
	: State(_window, _supportedKeys, _states)
{
	this->InitBackground();
	this->InitFont();
	this->InitButton();

	this->bLoad = false;
	this->sLoad = "NEW_GAME";
}

void MainMenuState::UpdateInput(const float& _dt)
{
	this->UpdateButton();
}

void MainMenuState::UpdateButton()
{
	if (this->bLoad)
	{
		this->buttons.at("SAVE_1")->Update(this->mousePosView);
		this->buttons.at("SAVE_2")->Update(this->mousePosView);
		this->buttons.at("SAVE_3")->Update(this->mousePosView);
		this->buttons.at("EXIT_SAVE")->Update(this->mousePosView);
	}
	else
	{
		this->buttons.at("NEW_GAME")->Update(this->mousePosView);
		this->buttons.at("LOAD_GAME")->Update(this->mousePosView);
		this->buttons.at("MAP_EDITOR")->Update(this->mousePosView);
		this->buttons.at("SETTING")->Update(this->mousePosView);
		this->buttons.at("EXIT")->Update(this->mousePosView);
	}

	if (this->GetKeytime())
	{
		if (this->buttons.at("NEW_GAME")->IsPressed())
			this->states->push(new GameState(this->window, this->supportedKeys, this->states, this->sLoad));

		if (this->buttons.at("LOAD_GAME")->IsPressed())
			this->bLoad = true;

		if (this->buttons.at("MAP_EDITOR")->IsPressed())
			this->states->push(new EditorState(this->window, this->supportedKeys, this->states));

		if (this->buttons.at("SETTING")->IsPressed())
			this->states->push(new SettingState(this->window, this->supportedKeys, this->states));

		if (this->buttons.at("EXIT")->IsPressed())
			this->EndState();

		//-------------------------Load-----------------------------------

		if (this->buttons.at("SAVE_1")->IsPressed())
		{
			this->bLoad = false;
			this->sLoad = "Save1";
			this->states->push(new GameState(this->window, this->supportedKeys, this->states, this->sLoad));
		}

		if (this->buttons.at("SAVE_2")->IsPressed())
		{
			this->bLoad = false;
			this->sLoad = "Save2";
			this->states->push(new GameState(this->window, this->supportedKeys, this->states, this->sLoad));
		}

		if (this->buttons.at("SAVE_3")->IsPressed())
		{
			this->bLoad = false;
			this->sLoad = "Save3";
			this->states->push(new GameState(this->window, this->supportedKeys, this->states, this->sLoad));
		}

		if (this->buttons.at("EXIT_SAVE")->IsPressed())
			this->bLoad = false;
	}
}

void MainMenuState::Update(const float& _dt)
{
	this->UpdateMousePosition();
	this->UpdateKeytime(_dt);
	this->UpdateInput(_dt);
}

void MainMenuState::RenderButton(RenderTarget& _target)
{
	if (this->bLoad)
	{
		this->buttons.at("SAVE_1")->Render(_target);
		this->buttons.at("SAVE_2")->Render(_target);
		this->buttons.at("SAVE_3")->Render(_target);
		this->buttons.at("EXIT_SAVE")->Render(_target);
	}
	else
	{
		this->buttons.at("NEW_GAME")->Render(_target);
		this->buttons.at("LOAD_GAME")->Render(_target);
		this->buttons.at("MAP_EDITOR")->Render(_target);
		this->buttons.at("SETTING")->Render(_target);
		this->buttons.at("EXIT")->Render(_target);
	}
}

void MainMenuState::Render(RenderTarget* _target)
{
	if (!_target)
		_target = this->window;

	_target->draw(this->background);

	this->RenderButton(*_target);
}

void MainMenuState::EndState()
{
	this->quit = true;
}

MainMenuState::~MainMenuState()
{
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
		delete it->second;
}
