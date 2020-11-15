#pragma once
#include "State.h"
class MapEditorState: public State
{
protected:

private:
    virtual void InitKeybins();

public:
	MapEditorState(RenderWindow* _window, map<string, int>* _supportedKeys, stack<State*>* _states);
    virtual void UpdateInput(const float& _dt);
    virtual void Update(const float& _dt);
    virtual void Render(RenderTarget* _target);
    void UpdateState();
    virtual void EndState();
    void CheckForPause();
    void PauseMenu();
	~MapEditorState();
};