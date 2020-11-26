#pragma once
#include "MainMenuState.h"
#include "Button.h"

class PauseMenuState : public MainMenuState
{
protected:
    Texture backgroundTexture;
    RectangleShape background;
    Font font;

    map<string, Button*> buttons;

private:
    virtual void InitButton();

public:
    PauseMenuState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states);
    virtual void UpdateButton();
    ~PauseMenuState();
};

