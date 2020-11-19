#include "MapEditorState.h"

void MapEditorState::InitBackground()
{
	
}

void MapEditorState::InitKeybinds()
{
	this->keybinds.emplace("ESCAPE", this->supportedKeys->at("Escape"));
	this->keybinds.emplace("MOVE_TOP", this->supportedKeys->at("Up"));
	this->keybinds.emplace("MOVE_LEFT", this->supportedKeys->at("Left"));
	this->keybinds.emplace("MOVE_RIGHT", this->supportedKeys->at("Right"));
	this->keybinds.emplace("MOVE_DOWN", this->supportedKeys->at("Down"));
}

void MapEditorState::InitGrid()
{
	this->gridSizeF = 100.f;
	this->shape.setSize(Vector2f(gridSizeF, gridSizeF));
}

void MapEditorState::InitVariables()
{
	this->viewSpeed = 100.f;
}


MapEditorState::MapEditorState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states)
	: State(_window, _supportedKeys, _states)
{
	this->InitGrid();
	this->InitVariables();
	this->InitKeybinds();
}

void MapEditorState::UpdateInput(const float& _dt)
{
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		view.move(-this->viewSpeed * _dt, 0.f); 
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		view.move(this->viewSpeed * _dt, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_TOP"))))
		view.move(0.f, -this->viewSpeed * _dt);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		view.move(0.f, this->viewSpeed * _dt);
}

void MapEditorState::Update(const float& _dt)
{
	this->UpdateInput(_dt);
}

void MapEditorState::Render(RenderTarget* _target)
{
	if (!_target)
		_target = this->window;

	this->ViewRender(_target);
}

void MapEditorState::ViewRender(RenderTarget* _target)
{
	_target->setView(this->view);
	this->GridRender(_target);
	this->window->setView(_target->getDefaultView());
}

void MapEditorState::GridRender(RenderTarget* _target)
{
	_target->draw(shape);
}

void MapEditorState::UpdateState()
{
}

void MapEditorState::EndState()
{
}

MapEditorState::~MapEditorState()
{
}
