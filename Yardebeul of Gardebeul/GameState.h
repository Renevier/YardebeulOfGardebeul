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
    void InitPlayer(string _sLoad);

public:
    GameState(RenderWindow *_window, map<string, int>* _supportedKeys, stack<State*>* _states, string _sLoad);
    ~GameState();

    void Load(string readFile);
    void Save(string writeFile);
    virtual void UpdatePlayerInput(const float& _dt);
    void UpdateState();
    void UpdatePauseMenuButtons();
    virtual void Update(const float& _dt);
    virtual void Render(RenderTarget* _target);
    virtual void EndState();
    void UpdateInput(const float& dt);
};