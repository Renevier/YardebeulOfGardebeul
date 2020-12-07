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
	this->buttons.emplace("NEW_GAME", new Button(100, 420, 250, 50,
		&this->font, "New game", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

	this->buttons.emplace("LOAD_GAME", new Button(100, 520, 250, 50,
		&this->font, "Load game", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

	this->buttons.emplace("MAP_EDITOR", new Button(100, 600, 250, 50,
		&this->font, "Map editor", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

	this->buttons.emplace("EXIT", new Button(100, 700, 250, 50,
		&this->font, "Quit", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

	this->buttons.emplace("SAVE_1", new Button(100, 400, 250, 50,
		&this->font, "Save 1", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

	this->buttons.emplace("SAVE_2", new Button(100, 600, 250, 50,
		&this->font, "Save 2", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

	this->buttons.emplace("SAVE_3", new Button(100, 800, 250, 50,
		&this->font, "Save 3", 50,
		Color(70, 70, 70, 200), Color(250, 250, 250, 250), Color(20, 20, 20, 50),
		Color(70, 70, 70, 0), Color(250, 250, 250, 0), Color(20, 20, 20, 0)));

}

MainMenuState::MainMenuState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states)
	: State(_window, _supportedKeys, _states)
{
	this->InitBackground();
	this->InitFont();
	this->InitButton();

	this->load = false;
}

void MainMenuState::UpdateInput(const float& _dt)
{
	this->UpdateButton();
}

void MainMenuState::UpdateButton()
{
	if (this->load)
	{
		this->buttons.at("SAVE_1")->Update(this->mousePosView);
		this->buttons.at("SAVE_2")->Update(this->mousePosView);
		this->buttons.at("SAVE_3")->Update(this->mousePosView);
	}
	else
	{
		this->buttons.at("NEW_GAME")->Update(this->mousePosView);
		this->buttons.at("LOAD_GAME")->Update(this->mousePosView);
		this->buttons.at("MAP_EDITOR")->Update(this->mousePosView);
		this->buttons.at("EXIT")->Update(this->mousePosView);
	}

	if (this->buttons.at("NEW_GAME")->IsPressed())
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	
	if (this->buttons.at("LOAD_GAME")->IsPressed())
	{
		this->load = true;
	}

	/*if (this->buttons.at("MAP_EDITOR")->IsPressed())
		this->states->push(new MapEditorState(this->window, this->supportedKeys, this->states));*/

	if (this->buttons.at("EXIT")->IsPressed())
		this->EndState();
}

void MainMenuState::Update(const float& _dt)
{
	this->UpdateMousePosition();
	this->UpdateInput(_dt);
}

void MainMenuState::RenderButton(RenderTarget& _target)
{
	if (this->load)
	{
		this->buttons.at("SAVE_1")->Render(_target);
		this->buttons.at("SAVE_2")->Render(_target);
		this->buttons.at("SAVE_3")->Render(_target);
	}
	else
	{
		this->buttons.at("NEW_GAME")->Render(_target);
		this->buttons.at("LOAD_GAME")->Render(_target);
		this->buttons.at("MAP_EDITOR")->Render(_target);
		this->buttons.at("EXIT")->Render(_target);
	}

}

void MainMenuState::Render(RenderTarget* _target)
{
	if (!_target)
		_target = this->window;

	_target->draw(this->background);

	this->RenderButton(*_target);

	//print mouse potiton in the console
	system("CLS");
	cout << this->mousePosView.x << " " << this->mousePosView.y;
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
