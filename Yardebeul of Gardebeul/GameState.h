#pragma once
#include "State.h"
class GameState :
    public State
{
protected:

public:
    GameState(RenderWindow *_window);
    virtual void UpdateKeyBind(const float& _dt);
    virtual void Update(const float &_dt);
    virtual void Render(RenderTarget *_target);
    virtual void EndState();
    ~GameState();

};

