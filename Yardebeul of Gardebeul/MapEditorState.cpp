#include "MapEditorState.h"

void MapEditorState::InitTileSelector()
{
	this->tileSelectorGrid.setSize(this->tileSizeF);
	this->tileSelectorGrid.setFillColor(Color::Transparent);
	this->tileSelectorGrid.setOutlineThickness(1.5f);
	this->tileSelectorGrid.setOutlineColor(Color::Red);

	this->tileSelectorTP.setSize(this->tileSizeF);
	this->tileSelectorTP.setFillColor(Color::Transparent);
	this->tileSelectorTP.setOutlineThickness(1.5f);
	this->tileSelectorTP.setOutlineColor(Color::Blue);
}

void MapEditorState::InitTileSize()
{
	if (!this->tilePickerTexture.loadFromFile("../Ressources/Tilesmap/IceDungeonTiles.png"))
		exit(EXIT_FAILURE);

	this->tileSizeF = Vector2f(32, 32);
	this->tileSizeU.x = (unsigned)tileSizeF.x;
	this->tileSizeU.y = (unsigned)tileSizeF.y;
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
	for (int x = 0; x < this->window->getSize().x / this->tileSizeF.x; x++)
	{
		for (int y = 0; y < this->window->getSize().y / tileSizeF.y; y++)
			this->tiles.push_back(new Tile(x * this->tileSizeF.x, y * this->tileSizeF.y, this->tileSizeF));
	}
}

void MapEditorState::InitVariables()
{
	this->viewSpeed = 200.f;
}

void MapEditorState::InitTilePicker()
{
	int i = 0;
	int j = 0;
	Vector2f PosOnScreen(0, 0);
	Vector2f PosInTexture(0, 0);


	for (int y = 0; y < tilePickerTexture.getSize().y/ tileSizeF.y; y++)
	{
 		if (y * tileSizeF.y <= tilePickerTexture.getSize().y)
			PosInTexture.y = y * this->tileSizeF.y;
		else
			PosInTexture.y = 0;

		for (int x = 0; x < tilePickerTexture.getSize().x / tileSizeF.x; x++)
		{
			PosOnScreen.x = i * this->tileSizeF.x;
			PosOnScreen.y = j * this->tileSizeF.y;

			if (x * tileSizeF.x <= tilePickerTexture.getSize().x)
				PosInTexture.x = x * this->tileSizeF.x;
			else
				PosInTexture.x = 0;

			this->tilePicker.push_back(new Tile(&this->tilePickerTexture, PosOnScreen, PosInTexture));

			i++;

			if (i * this->tileSizeF.x >= this->view.getSize().x)
			{
				j++;
				i = 0;
			}

		}
	}
}

MapEditorState::MapEditorState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states)
	: State(_window, _supportedKeys, _states)
{
	this->InitTileSize();
	this->InitTilePicker();
	this->InitTileSelector();
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

void MapEditorState::UpdateMousePosGrid()
{
	//Update tileSelectorGrid
	if (this->mousePosView.x >= 0 && this->mousePosView.x <= this->window->getSize().x)
		mousePosGrid.x = mousePosView.x / this->tileSizeU.x;

	if (this->mousePosView.y >= 0 && this->mousePosView.y <= this->window->getSize().y)
		mousePosGrid.y = mousePosView.y / this->tileSizeU.y;

	this->tileSelectorGrid.setPosition(this->mousePosGrid.x * this->tileSizeF.x, this->mousePosGrid.y * this->tileSizeF.y);

	//Update tileSelector on tilePicker
	/*this->tileSelectorTP.setPosition();*/
}

void MapEditorState::SelectTile()
{

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
			"Tile Selector Grid: X==>" << this->tileSelectorGrid.getPosition().x << " Y==>" << this->tileSelectorGrid.getPosition().y << endl <<
			"Tile Selector TP: X==>" << this->tileSelectorTP.getPosition().x << " Y==>" << this->tileSelectorTP.getPosition().y << endl <<
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
	if (this->mousePosView.x >= 0 && this->mousePosView.x <= this->window->getSize().x
		&& this->mousePosView.y >= 0 && this->mousePosView.y <= this->window->getSize().y)
			_target->draw(this->tileSelectorGrid);
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