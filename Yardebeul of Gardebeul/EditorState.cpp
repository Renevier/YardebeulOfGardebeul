#include "pch.h"
#include "EditorState.h"

void EditorState::InitKeybinds()
{}

void EditorState::InitPauseMenu()
{
	this->pauseMenu = new PauseMenu(*this->window, this->font);

	this->InitButton();
}

void EditorState::InitBackground()
{}

void EditorState::InitFont()
{
	if (!this->font.loadFromFile("../Ressources/Fonts/rpgFont.ttf"))
		exit(0);
}

void EditorState::InitButton()
{
	this->pauseMenu->AddButton("EXIT_GAME", 100.f, 800.f, "Quit");
}

EditorState::EditorState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states)
	: State(_window, _supportedKeys, _states)
{
	this->InitBackground();
	this->InitPauseMenu();
	this->InitFont();

}

void EditorState::UpdatePauseMenuButtons()
{
	if (this->pauseMenu->IsButtonPressed("EXIT_GAME"))
		this->EndState();
}

void EditorState::UpdateInput(const float& _dt)
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		if (!this->pause)
			this->PauseState();
	}
}

void EditorState::UpdateButton()
{
	for (auto& it : this->buttons)
		it.second->Update(this->mousePosView);
}

void EditorState::Update(const float& _dt)
{
	this->UpdateMousePosition();
	this->UpdateInput(_dt);

	if (!this->pause)
	{
		this->UpdateButton();
	}
	else
	{
		this->pauseMenu->Update(this->mousePosView);
		this->UpdatePauseMenuButtons();
	}

}

void EditorState::RenderButton(RenderTarget& _target)
{
	for (auto& it : this->buttons)
		it.second->Render(_target);
}

void EditorState::Render(RenderTarget* _target)
{
	if (!_target)
		_target = this->window;

	this->Map.Render(*_target);

	this->RenderButton(*_target);

	if (this->pause)
		this->pauseMenu->Render(*_target, this->wantSave);

}

void EditorState::EndState()
{
	this->quit = true;
}

EditorState::~EditorState()
{
	delete this->pauseMenu;

	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
		delete it->second;
}
