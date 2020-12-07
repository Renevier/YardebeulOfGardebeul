#pragma once
#include "State.h"
#include "Button.h"
class EditorState :
    public State
{
protected:
    Font font;

    map<string, Button*> buttons;

protected:
    virtual void InitKeybinds();
    void InitFont();
    void InitButton();

public:
    EditorState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states);
    ~EditorState();

    virtual void UpdateInput(const float& _dt);
    virtual void UpdateButton();
    virtual void Update(RenderTarget* _window, const float& _dt);
    virtual void RenderButton(RenderTarget& _target);
    virtual void Render(RenderTarget* _target);
    virtual void EndState();
};

