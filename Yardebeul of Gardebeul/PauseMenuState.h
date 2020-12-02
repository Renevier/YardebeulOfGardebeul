#pragma once
#include "State.h"
#include "Button.h"

class PauseMenuState : public State
{
protected:
    Texture backgroundTexture;
    RectangleShape background;
    Font font;

    map<string, Button*> buttons;

private:
    virtual void InitKeybinds();
    virtual void InitButton();
    void InitBackground();

public:
    PauseMenuState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states);
    virtual void UpdateButton();
    virtual void UpdateInput(const float& _dt);
    virtual void Update(const float& _dt);
    virtual void Render(RenderTarget* _target);
    virtual void EndState();
    ~PauseMenuState();
};

