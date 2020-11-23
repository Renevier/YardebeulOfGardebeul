#include "MapEditorState.h"


void MapEditorState::InitTileSelector()
{
	this->tileSelector.setSize(Vector2f(this->tileSizeF, this->tileSizeF));
	this->tileSelector.setFillColor(Color::Transparent);
	this->tileSelector.setOutlineThickness(2.f);
	this->tileSelector.setOutlineColor(Color::Red);
}

void MapEditorState::InitTileSize()
{
	this->tileSizeF = 10.f;
	this->tileSizeU = (unsigned)this->tileSizeF;
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
	for (int x = 0; x < this->window->getSize().x / this->tileSizeF; x++)
	{
		for (int y = 0; y < this->window->getSize().y / tileSizeF; y++)
			this->tiles.push_back(new Tile(x * this->tileSizeF, y * this->tileSizeF, this->tileSizeF));
	}
}

void MapEditorState::InitVariables()
{
	this->viewSpeed = 100.f;
}

void MapEditorState::InitTilePicker()
{
	for (int i = 0; i <= this->window->getSize().x / this->tileSizeU - 1; i++)
		this->tilePicker.push_back(new Tile(i * this->tileSizeF, 0, this->tileSizeF));
}

MapEditorState::MapEditorState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states)
	: State(_window, _supportedKeys, _states)
{
	this->InitTileSize();
	this->InitTileSelector();
	this->InitTiles();
	this->InitVariables();
	this->InitKeybinds();
	this->InitTilePicker();
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

void MapEditorState::UpdateMousePosGrid()
{
	if (this->mousePosView.x >= 0)
		mousePosGrid.x = mousePosView.x / this->tileSizeU;
	
	if (this->mousePosView.y >= 0)
		mousePosGrid.y = mousePosView.y / this->tileSizeU;
	
	this->tileSelector.setPosition(this->mousePosGrid.x * this->tileSizeF, this->mousePosGrid.y * this->tileSizeF);
}

void MapEditorState::Update(const float& _dt)
{
	this->UpdateMousePosition();
	this->UpdateMousePosGrid();
	this->UpdateInput(_dt);
}

void MapEditorState::Render(RenderTarget* _target)
{
	if (!_target)
		_target = this->window;

	this->ViewRender(_target);
	this->TilesRender(_target);
	this->TileSelectorRender(_target);
	this->window->setView(_target->getDefaultView());
	this->RenderTilePicker(_target);

	cout << "Screen: X==>" << this->mousePosScreen.x << " Y==>" << this->mousePosScreen.y << endl <<
			"Window: X==>" << this->mousePosWindow.x << " Y==>" << this->mousePosWindow.y << endl <<
			"View: X==>" << this->mousePosView.x << " Y==>" << this->mousePosView.y << endl <<
			"Tile selector: X==>" << this->tileSelector.getPosition().x << " Y==>" << this->tileSelector.getPosition().y << endl <<
			"Grid: X==>" << this->mousePosGrid.x << " Y==>" << this->mousePosGrid.y;

	system("CLS");
}

void MapEditorState::ViewRender(RenderTarget* _target)
{
	_target->setView(this->view);
}

void MapEditorState::TilesRender(RenderTarget* _target)
{
	for (auto it : this->tiles)
		it->Render(_target);
}

void MapEditorState::TileSelectorRender(RenderTarget* _target)
{
	_target->draw(this->tileSelector);
}

void MapEditorState::RenderTilePicker(RenderTarget* _target)
{
	for (auto it : this->tilePicker)
		it->Render(_target);
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
