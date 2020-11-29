#include "GameState.h"


void GameState::InitKeybinds()
{
	this->keybinds.emplace("ESCAPE", this->supportedKeys->at("Escape"));
	this->keybinds.emplace("MOVE_TOP", this->supportedKeys->at("Up"));
	this->keybinds.emplace("MOVE_LEFT", this->supportedKeys->at("Left"));
	this->keybinds.emplace("MOVE_RIGHT", this->supportedKeys->at("Right"));
	this->keybinds.emplace("MOVE_DOWN", this->supportedKeys->at("Down"));
}

void GameState::InitTexture()
{
	if(!this->textures["PLAYER_IDLE"].loadFromFile("../Ressources/Sprites/Player/lol.png"))
		throw "ERROR game state could not load idle texture";
}

void GameState::InitPlayer()
{
	this->player = new Hero(0, 0, this->textures["PLAYER_IDLE"]);
}

GameState::GameState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states)
	: State(_window, _supportedKeys, _states)
{
	this->InitKeybinds();
	this->InitTexture();
	this->InitPlayer();
}

void GameState::UpdateInput(const float& _dt)
{
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_TOP"))))
		this->player->Move(0.f, -1.f, _dt);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player->Move(0.f, 1.f, _dt);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->Move(-1.f, 0.f, _dt);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->Move(1.f, 0.f, _dt);
}

void GameState::Update(const float& _dt)
{
	this->UpdateMousePosition();
	this->UpdateInput(_dt);
	
	this->player->Update(_dt);
}

void GameState::Render(RenderTarget* _target)
{
	if (!_target)
		_target = this->window;

	this->player->Render(_target);

}

void GameState::UpdateState()
{
}

void GameState::EndState()
{
}

void GameState::CheckForPause()
{
	//if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("ESCAPE"))))
}

void GameState::PauseMenu()
{
	/*if(this->pause)
		this->states->push(new MainMenuState(this->window, this->supportedKeys, this->states));*/
}

GameState::~GameState()
{
	delete this->player;
}
