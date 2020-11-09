#include "GameState.h"


GameState::GameState(RenderWindow *_window): State(_window)
{
}

<<<<<<< HEAD
GameState::GameState(RenderWindow *_window, map<string, int>* _supportedKeys): State(_window, _supportedKeys)
{
	this->InitKeybins();
}

/*Seb ALED !!!*/
=======
>>>>>>> 689fd5903e5a522fde7025fe70562d1eb96b2850
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
