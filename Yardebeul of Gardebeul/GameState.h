#pragma once
#include "State.h"
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
    void Pause();
    virtual void UpdateInput(const float& _dt);
    void UpdateState();
    virtual void Update(const float &_dt);
    virtual void Render(RenderTarget *_target);
    virtual void EndState();
    ~GameState();
};