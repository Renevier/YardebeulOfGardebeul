#include "Game.h"

void Game::InitWindow()
{
    this->window = new RenderWindow(VideoMode(800, 600), "Yardebeul of Gardebeul");
}


void Game::InitState()
{
    this->states.push(new GameState(this->window));
}

Game::Game()
{
    this->InitWindow();
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

    //Draw the items here
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