#pragma once
#include "State.h"
#include "Gui.h"
#include "GameState.h"
#include "TileMap.h"
#include "PauseMenu.h"

class EditorState :
    public State
{
protected:
    Texture backgroundTexture;
    RectangleShape background;
    Font font;

    TileMap Map;
    PauseMenu* pauseMenu;
    map<string, gui::Button*> buttons;

protected:
    virtual void InitKeybinds();
    void InitPauseMenu();
    void InitBackground();
    void InitFont();
    void InitButton();

public:
    EditorState(StateData *_state_data);
    ~EditorState();
    
    void UpdatePauseMenuButtons();
    virtual void UpdateInput(const float& _dt);
    virtual void UpdateButton();
    virtual void Update(const float& _dt);
    virtual void RenderButton(RenderTarget& _target);
    virtual void Render(RenderTarget* _target);
    virtual void EndState();
};