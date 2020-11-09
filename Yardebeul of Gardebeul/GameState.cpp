#include "GameState.h"


GameState::GameState(RenderWindow *_window): State(_window)
{
}

void GameState::UpdateInput(const float& _dt)
{
	this->CheckForQuit();

	//Player input
	/*if (Keyboard::isKeyPressed(Keyboard::Up))
		this->player.Move(_dt, -1.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::Down))
		this->player.Move(_dt, 1.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::Left))
		this->player.Move(_dt, 0.f, -1.f);
	if (Keyboard::isKeyPressed(Keyboard::Right))
		this->player.Move(_dt, 0.f, 1.f);*/
}

void GameState::Update(const float &_dt)
{
	this->UpdateInput(_dt);
}

void GameState::Render(RenderTarget *_target)
{
}

void GameState::EndState()
{
}

GameState::~GameState()
{
}
