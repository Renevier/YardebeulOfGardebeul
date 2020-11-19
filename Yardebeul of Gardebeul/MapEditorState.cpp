#include "MapEditorState.h"

void MapEditorState::InitBackground()
{
	
}

void MapEditorState::InitTiles()
{
	int sideOfTile = 50;

	for (int x = 0; x < this->window->getSize().x / sideOfTile; x++)
	{
		for (int y = 0; y < this->window->getSize().y / sideOfTile; y++)
			this->tiles.emplace((x, y), new Tile(x * sideOfTile, y * sideOfTile, sideOfTile, Color::Black));
	}
}

MapEditorState::MapEditorState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states)
	: State(_window, _supportedKeys, _states)
{
	this->InitTiles();
}

void MapEditorState::UpdateInput(const float& _dt)
{
}

void MapEditorState::Update(const float& _dt)
{
}

void MapEditorState::Render(RenderTarget* _target)
{
	if (!_target)
		_target = this->window;

	this->RenderTiles(_target);
}

void MapEditorState::RenderTiles(RenderTarget* _target)
{
	for (auto it : this->tiles)
		it.second->Render(_target);
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
