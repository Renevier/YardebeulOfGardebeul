#include "GameState.h"

GameState::GameState(RenderWindow *_window): State(_window)
{
}

void GameState::UpdateKeyBind(const float& _dt)
{
	this->CheckForQuit();
}

void GameState::Update(const float &_dt)
{
	this->UpdateKeyBind(_dt);
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
