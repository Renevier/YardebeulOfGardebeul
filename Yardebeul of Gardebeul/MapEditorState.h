#pragma once
#include "State.h"
#include "Tile.h"

class MapEditorState: public State
{
protected:
    float gridSizeF; 
    unsigned gridSizeU = (unsigned)gridSizeF;

    RectangleShape shape;

    map<int, Tile*> tiles;

private:
    virtual void InitKeybinds();
    void InitBackground();
    void InitGrid();
    void InitVariables();

public:
	MapEditorState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states);
    virtual void UpdateInput(const float& _dt);
    virtual void Update(const float& _dt);
    virtual void Render(RenderTarget* _target);
    void ViewRender(RenderTarget* _target);
    void GridRender(RenderTarget* _target);
    void UpdateState();
    virtual void EndState();
	~MapEditorState();
};