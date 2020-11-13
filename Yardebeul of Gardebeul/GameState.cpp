#include "GameState.h"


void GameState::InitKeybins()
{
	this->keybinds.emplace("MOVE_TOP", this->supportedKeys->at("Up"));
	this->keybinds.emplace("MOVE_LEFT", this->supportedKeys->at("Left"));
	this->keybinds.emplace("MOVE_RIGHT", this->supportedKeys->at("Right"));
	this->keybinds.emplace("MOVE_DOWN", this->supportedKeys->at("Down"));
}

GameState::GameState(RenderWindow *_window, map<string, int>* _supportedKeys, stack<State*>* _states)
	: State(_window, _supportedKeys, _states)
{
	this->InitKeybins();
}

void GameState::UpdateInput(const float& _dt)
{
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_TOP"))))
		this->player.Move(_dt, 0.f, -1.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player.Move(_dt, 0.f, 1.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player.Move(_dt, -1.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player.Move(_dt, 1.f, 0.f);	
}

void GameState::Update(const float &_dt)
{
	this->UpdateMousePosition();
	this->UpdateInput(_dt);
	this->CheckForQuit();
 
	
}

void GameState::Render(RenderTarget *_target)
{
	if (!_target)
		_target = this->window;

	this->player.Render(_target);
}

void GameState::EndState()
{
}

GameState::~GameState()
{
}
