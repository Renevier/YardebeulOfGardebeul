#pragma once
#include "State.h"
#include "Button.h"
#include "GameState.h"
#include "MapEditorState.h"
#include "EditorState.h"

class EditorState :
    public State
{
protected:
    Texture backgroundTexture;
    RectangleShape background;
    Font font;

    map<string, Button*> buttons;

protected:
    virtual void InitKeybinds();
    void InitBackground();
    void InitFont();
    void InitButton();

public:
    EditorState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states);
    ~EditorState();
    virtual void UpdateInput(const float& _dt);
    virtual void UpdateButton();
    virtual void Update(const float& _dt);
    virtual void RenderButton(RenderTarget& _target);
    virtual void Render(RenderTarget* _target);
    virtual void EndState();
};