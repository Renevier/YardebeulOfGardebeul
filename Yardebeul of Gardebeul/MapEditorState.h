#pragma once
#include "State.h"
#include "Tile.h"

class MapEditorState: public State
{
protected:
    float tileSize;

    Font font;

    Vector2u mousePosGrid;

    map<int, Tile*> tiles;

private:
    virtual void InitKeybinds();
    void InitText();
    void InitTiles();
    void InitVariables();

public:
	MapEditorState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states);
    void UpdateState();
    virtual void UpdateInput(const float& _dt);
    virtual void Update(const float& _dt);
    virtual void Render(RenderTarget* _target);
    void ViewRender(RenderTarget* _target);
    void TilesRender(RenderTarget* _target);
    void TextRender(RenderTarget* _target);
    virtual void EndState();
	~MapEditorState();
};