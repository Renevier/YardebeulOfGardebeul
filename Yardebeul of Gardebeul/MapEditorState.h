#pragma once
#include "State.h"
#include "Tile.h"

class MapEditorState: public State
{
protected:
    Vector2f tileSizeF;
    Vector2u tileSizeU;

    Vector2u mousePosGrid;

    list<Tile*> tiles;

    RectangleShape tileSelectorGrid;

    Texture tilePickerTexture;
    RectangleShape tileSelectorTP;
    list<Tile*> tilePicker;

private:
    void InitTileSelector();
    void InitTileSize();
    virtual void InitKeybinds();
    void InitTiles();
    void InitVariables();
    void InitTilePicker();

public:
	MapEditorState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states);
    void UpdateState();
    void UpdateMousePosGrid();
    void SelectTile();
    virtual void UpdateInput(const float& _dt);
    virtual void Update(const float& _dt);
    virtual void Render(RenderTarget* _target);
    void ViewRender(RenderTarget* _target);
    void TilesRender(RenderTarget* _target);
    void TileSelectorRender(RenderTarget* _target);
    void RenderTilePicker(RenderTarget* _target);
    virtual void EndState();
	~MapEditorState();
};