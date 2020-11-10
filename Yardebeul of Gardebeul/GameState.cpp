#include "GameState.h"


void GameState::InitKeybins()
{
	this->keybinds.emplace("MOVE_TOP", this->supportedKeys->at("Up"));
	this->keybinds.emplace("MOVE_LEFT", this->supportedKeys->at("Left"));
	this->keybinds.emplace("MOVE_RIGHT", this->supportedKeys->at("Right"));
	this->keybinds.emplace("MOVE_DOWN", this->supportedKeys->at("Down"));
}

GameState::GameState(RenderWindow *_window, map<string, int>* _supportedKeys): State(_window, _supportedKeys)
{
	this->InitKeybins();
}

/*will see*/
void GameState::UpdateInput(float& _dt)
{

	
}

void GameState::Update(const float &_dt)
{
	//this->player.Update(_dt);
	this->CheckForQuit();

	//player input 
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_TOP"))))
		this->player.Move(_dt, 0.f, -1.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player.Move(_dt, 0.f, 1.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player.Move(_dt, -1.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player.Move(_dt, 1.f, 0.f);
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
