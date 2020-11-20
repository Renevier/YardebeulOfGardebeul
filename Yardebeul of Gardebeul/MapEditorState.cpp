#include "MapEditorState.h"

void MapEditorState::InitText()
{
	if (!this->font.loadFromFile("../Ressources/Font/rpgFont.ttf"))
		exit(0);

	this->text.setCharacterSize(12);
	this->text.setFillColor(Color::White);
	this->text.setFont(this->font);
}

void MapEditorState::InitKeybinds()
{
	this->keybinds.emplace("ESCAPE", this->supportedKeys->at("Escape"));
	this->keybinds.emplace("MOVE_TOP", this->supportedKeys->at("Up"));
	this->keybinds.emplace("MOVE_LEFT", this->supportedKeys->at("Left"));
	this->keybinds.emplace("MOVE_RIGHT", this->supportedKeys->at("Right"));
	this->keybinds.emplace("MOVE_DOWN", this->supportedKeys->at("Down"));
}

void MapEditorState::InitTiles()
{
	this->tileSize = 100.f;

	for (int x = 0; x < this->window->getSize().x; x++)
	{
		for (int y = 0; y < this->window->getSize().y; y++)
		{
			this->tiles.emplace((x + y), new Tile(x * this->tileSize, y * this->tileSize, this->tileSize));
		}
	}
}

void MapEditorState::InitVariables()
{
	this->viewSpeed = 100.f;
}


MapEditorState::MapEditorState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states)
	: State(_window, _supportedKeys, _states)
{
	this->InitText();
	this->InitTiles();
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
	this->UpdateMousePosition();

	if (this->mousePosView.x >= 0)
		mousePosGrid.x = mousePosView.x / this->tileSize;

	if (this->mousePosView.y >= 0)
		mousePosGrid.y = mousePosView.y / this->tileSize;

	this->UpdateInput(_dt);

		
}

void MapEditorState::Render(RenderTarget* _target)
{
	if (!_target)
		_target = this->window;

	this->ViewRender(_target);

	cout << "Screen: " << this->mousePosScreen.x << " " << this->mousePosScreen.y << endl <<
		"Window: " << this->mousePosWindow.x << " " << this->mousePosWindow.y << endl <<
		"View: " << this->mousePosView.x << " " << this->mousePosView.y << endl <<
		"Grid: " << this->mousePosGrid.x << " " << this->mousePosGrid.y;

	system("CLS");
}

void MapEditorState::ViewRender(RenderTarget* _target)
{
	_target->setView(this->view);
	this->TilesRender(_target);
	this->window->setView(_target->getDefaultView());
	this->TextRender(_target);
}

void MapEditorState::TilesRender(RenderTarget* _target)
{
	for (auto it : this->tiles)
		it.second->Render(_target);
}

void MapEditorState::TextRender(RenderTarget* _target)
{
	_target->draw(this->text);	
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
