#include "pch.h"
#include "Game.h"

void Game::InitVariables()
{
	this->deltaTime = 0.f;
	this->window = nullptr;
	this->gridSize = 35.f;
}

void Game::InitStateData()
{
	this->stateData.window = this->window;
	this->stateData.supportedKeys = &this->supportedKeys;
	this->stateData.states = &this->states;
	this->stateData.gridSize = this->gridSize;

}

void Game::InitWindow()
{
	this->window = new RenderWindow(VideoMode(1920, 1080), "Yardebeul of Gardebeul");
}


void Game::InitState()
{
	this->states.emplace(new MainMenuState(&this->stateData));
}

void Game::InitKeys()
{
	this->supportedKeys.emplace("Escape", Keyboard::Key::Escape);
	this->supportedKeys.emplace("Up", Keyboard::Key::Up);
	this->supportedKeys.emplace("Left", Keyboard::Key::Left);
	this->supportedKeys.emplace("Right", Keyboard::Key::Right);
	this->supportedKeys.emplace("Down", Keyboard::Key::Down);
}

Game::Game()
{
	this->InitVariables();
	this->InitWindow();
	this->InitKeys();
	this->InitStateData();
	this->InitState();
}


void Game::Run()
{
	while (this->window->isOpen())
	{
		this->UpdateDt();
		this->Update();
		this->Render();
	}
}

void Game::UpdateDt()
{
	this->deltaTime = this->clock.restart().asSeconds();
}

void Game::Update()
{
	this->UpdateEventSFML();

	if (!this->states.empty())
	{
		this->states.top()->Update(this->deltaTime);

		if (this->states.top()->GetQuit())
		{
			delete this->states.top();
			this->states.pop();
		}
	}
	else
	{
		this->window->close();
	}

}

void Game::UpdateEventSFML()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == Event::Closed)
			this->window->close();
	}
}

void Game::Render()
{
	this->window->clear();

	//Display state
	if (!this->states.empty())
		this->states.top()->Render(this->window);

	this->window->display();
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}