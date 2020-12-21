#pragma once
#include "State.h"
#include "PauseMenu.h"
#include "TileMap.h"

class GameState: public State
{
protected:
    Font font;
    PauseMenu* pauseMenu;

    Hero* player;

    TileMap* tileMap;
    Clock clock;
    float ingameTime;


private:
    virtual void InitKeybinds();
    void InitFont();
    void InitTexture();
    void InitPauseMenu();
    void InitButton();
    void InitPlayer(string _sLoad);
    void InitTileMap();

public:
    GameState(StateData* _state_data, string _sLoad);
    ~GameState();

    void LoadStat(string readFile);
    void LoadPos(string readFile);
    void Save(string writeFile);
    virtual void UpdatePlayerInput(const float& _dt);
    void UpdateState();
    void UpdatePauseMenuButtons();
    virtual void Update(const float& _dt);
    virtual void Render(RenderTarget* _target);
    void UpdateInput(const float& dt);
};