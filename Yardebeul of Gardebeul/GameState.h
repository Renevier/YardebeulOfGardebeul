#pragma once
#include "State.h"
#include "MainMenuState.h"
#include "PauseMenuState.h"

class GameState: public State
{
protected:
    Hero* player;

private:
    virtual void InitKeybinds();
    void InitTexture();
    void InitPlayer();

public:
    GameState(RenderWindow *_window, map<string, int>* _supportedKeys, stack<State*>* _states);
    virtual void UpdateInput(const float& _dt);
    virtual void Update(const float &_dt);
    virtual void Render(RenderTarget *_target);
    void UpdateState();
    virtual void EndState();
    ~GameState();
};