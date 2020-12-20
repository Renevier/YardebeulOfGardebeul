#pragma once
#include "State.h"
#include "Gui.h"
class SaveState :
    public State
{
protected:
    Texture backgroundTexture;
    RectangleShape background;
    Font font;

    map<string, gui::Button*> buttons;

private:
    virtual void InitKeybinds();
    virtual void InitButton();
    void InitFont();
    void InitBackground();

public:
    SaveState(StateData* _state_data);
    virtual void UpdateButton();
    void Save(string _name_file);
    virtual void UpdateInput(const float& _dt);
    virtual void Update(const float& _dt);
    virtual void RenderButton(RenderTarget& _target);
    virtual void Render(RenderTarget* _target);
    virtual void EndState();
    ~SaveState();
};

