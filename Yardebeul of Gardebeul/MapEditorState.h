#pragma once
#include "State.h"
#include "Tile.h"

class MapEditorState: public State
{
protected:
    float tileSizeF;
    unsigned tileSizeU;

    Font font;

    Vector2u mousePosGrid;

    vector<Tile*> tiles;

    RectangleShape tileSelector;

private:
    void InitTileSelector();
    void InitTileSize();
    virtual void InitKeybinds();
    void InitTiles();
    void InitVariables();

public:
	MapEditorState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states);
    void UpdateState();
    void UpdateMousePosGrid();
    virtual void UpdateInput(const float& _dt);
    virtual void Update(const float& _dt);
    virtual void Render(RenderTarget* _target);
    void ViewRender(RenderTarget* _target);
    void TilesRender(RenderTarget* _target);
    void TileSelectorRender(RenderTarget* _target);
    virtual void EndState();
	~MapEditorState();
};