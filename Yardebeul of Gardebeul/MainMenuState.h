#pragma once
#include "State.h"
#include "Gui.h"
#include "GameState.h"
#include "EditorState.h"
#include "SettingState.h"

class MainMenuState :
    public State
{
protected:
    Texture backgroundTexture;
    RectangleShape background;
    Font font;

    map<string, gui::Button*> buttons;
    bool bLoad;
    string sLoad;

    RectangleShape descriptionContainer;
    Text descriptionText;

protected:
    virtual void InitKeybinds();
    void InitBackground();
    void InitFont();
    void InitButton();

public:
    MainMenuState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states);
    virtual void UpdateInput(const float& _dt);
    virtual void UpdateButton();
    virtual void Update(const float& _dt);
    virtual void RenderButton(RenderTarget& _target);
    virtual void Render(RenderTarget* _target);
    virtual void EndState();
    ~MainMenuState();
};