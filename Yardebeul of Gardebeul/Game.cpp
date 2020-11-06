#include "Game.h"


Game::Game()
{
    this->InitWindow();
}

void Game::InitWindow()
{
    this->window = new RenderWindow(VideoMode(800, 600), "Yardebeul of Gardebeul");
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
    this->UpdateEvent();
}

void Game::UpdateEvent()
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

    //Draw the items here

    this->window->display();
}

Game::~Game()
{
	delete this->window;
}