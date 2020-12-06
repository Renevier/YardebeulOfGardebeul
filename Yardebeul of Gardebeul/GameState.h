#pragma once
#include "State.h"
#include "PauseMenu.h"

class GameState: public State
{
protected:
    Font font;
    PauseMenu* pauseMenu;

    Hero* player;

    bool wantSave;

    Clock clock;
    float ingameTime;

private:
    virtual void InitKeybinds();
    void InitFont();
    void InitTexture();
    void InitPauseMenu();
    void InitButton();
    void InitPlayer();

public:
    GameState(RenderWindow *_window, map<string, int>* _supportedKeys, stack<State*>* _states);
    ~GameState();

    void Save(string writeFile);
    virtual void UpdatePlayerInput(const float& _dt);
    void UpdateState();
    void UpdatePauseMenuButtons();
    virtual void Update(const float& _dt);
    virtual void Render(RenderTarget* _target);
    virtual void EndState();
    void UpdateInput(const float& dt);
};