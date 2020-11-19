#pragma once
#include "State.h"
#include "Tile.h"

class MapEditorState: public State
{
protected:
    Texture backgroundTexture;
    RectangleShape background;

    map<int, Tile*> tiles;

private:
    void InitBackground();
    void InitTiles();

public:
	MapEditorState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states);
    virtual void UpdateInput(const float& _dt);
    virtual void Update(const float& _dt);
    virtual void Render(RenderTarget* _target);
    void RenderTiles(RenderTarget* _target);
    void UpdateState();
    virtual void EndState();
	~MapEditorState();
};