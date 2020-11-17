#include "Game.h"

void Game::InitWindow()
{
	this->window = new RenderWindow(VideoMode(1900, 1080), "Yardebeul of Gardebeul");
	this->window->setFramerateLimit(120);
	this->window->setVerticalSyncEnabled(false);
}


void Game::InitState()
{
	this->states.emplace(new MainMenuState(this->window, &this->supportedKeys, &this->states));
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
	this->InitWindow();
	this->InitKeys();
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