#pragma once
#include "State.h"
class MainMenuState :
    public State
{
protected:

public:
    MainMenuState(RenderWindow* _window, map<string, int>* _supportedKeys);
    ~MainMenuState();
};

