#include "MapEditorState.h"

void MapEditorState::InitKeybins()
{
}

MapEditorState::MapEditorState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states)
	: State(_window, _supportedKeys, _states)
{
}

void MapEditorState::UpdateInput(const float& _dt)
{
}

void MapEditorState::Update(const float& _dt)
{
}

void MapEditorState::Render(RenderTarget* _target)
{
}

void MapEditorState::UpdateState()
{
}

void MapEditorState::EndState()
{
}

void MapEditorState::CheckForPause()
{
}

void MapEditorState::PauseMenu()
{
}

MapEditorState::~MapEditorState()
{
}
