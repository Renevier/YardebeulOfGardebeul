#pragma once
#include "State.h"
#include "gui.h"

class SettingState :
    public State
{
protected:
    Texture backgroundTexture;
    RectangleShape background;
    Font font;

    Text optionText;

    map<string, gui::Button*> buttons;
    map<string, gui::DropDownList*> dropDownLists;

protected:
    virtual void InitKeybinds();
    void InitText();
    void InitBackground();
    void InitFont();
    void InitGui();

public:
    SettingState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states);
    ~SettingState();

    virtual void UpdateInput(const float& _dt);
    virtual void UpdateGui(const float& _dt);
    virtual void Update(const float& _dt);
    virtual void RenderGui(RenderTarget& _target);
    virtual void Render(RenderTarget* _target);
};

