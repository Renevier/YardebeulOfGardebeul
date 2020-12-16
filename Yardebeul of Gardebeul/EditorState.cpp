#include "EditorState.h"

void EditorState::InitKeybinds()
{}

void EditorState::InitBackground()
{}

void EditorState::InitFont()
{
	if (!this->font.loadFromFile("../Ressources/Fonts/rpgFont.ttf"))
		exit(0);
}

void EditorState::InitButton()
{}

EditorState::EditorState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states)
	: State(_window, _supportedKeys, _states)
{
	this->InitBackground();
	this->InitFont();
	this->InitButton();

}

void EditorState::UpdateInput(const float& _dt)
{
	this->UpdateButton();

	if (Keyboard::isKeyPressed(Keyboard::Escape))
		this->EndState();
}

void EditorState::UpdateButton()
{
	/*for (auto it : this->buttons)
		it.second->Update(this->mousePosView);*/
}

void EditorState::Update(const float& _dt)
{
	this->UpdateMousePosition();
	this->UpdateInput(_dt);
}

void EditorState::RenderButton(RenderTarget& _target)
{
	/*for (auto it : this->buttons)
		it.second->Render(_target);*/
}

void EditorState::Render(RenderTarget* _target)
{
	if (!_target)
		_target = this->window;

	//this->RenderButton(*_target);
}

void EditorState::EndState()
{
	this->quit = true;
}

EditorState::~EditorState()
{
	/*for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
		delete it->second;*/
}
