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
    View view;
    float cameraSpeed;
    int layer;

    Texture backgroundTexture;
    RectangleShape background;
    Font font;
    Text cursorText;

    RectangleShape sideBar;

    gui::TextureSelector* textureSelector;

    bool collision;
    short type;

    TileMap* tileMap;
    PauseMenu* pauseMenu;
    map<string, gui::Button*> buttons;

    RectangleShape selector;
    IntRect textureRect;

protected:
    void InitView();
    virtual void InitKeybinds();
    void InitPauseMenu();
    void InitBackground();
    void InitFont();
    void InitText();
    void InitButton();
    void InitGui();
    void IniTileMap();

public:
    EditorState(StateData *_state_data);
    ~EditorState();
    
    void UpdatePauseMenuButtons();
    virtual void UpdateInput(const float& _dt);
    virtual void UpdateEditorInput(const float& _dt);
    virtual void UpdateButton();
    void UpdateGui(const float& _dt);
    virtual void Update(const float& _dt);
    virtual void RenderButton(RenderTarget& _target);
    void RenderGui(RenderTarget& _target);
    virtual void Render(RenderTarget* _target);
    virtual void EndState();
};