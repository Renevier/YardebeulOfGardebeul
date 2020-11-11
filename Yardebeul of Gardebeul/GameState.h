#pragma once
#include "State.h"
class GameState :
    public State
{
protected:
    Entity player;
    map<string, Texture> textures;

    //Function
private:
    virtual void InitKeybins();
    void InitTexture();

public:
    GameState(RenderWindow *_window, map<string, int>* _supportedKeys);
    virtual void UpdateInput(const float& _dt);
    virtual void Update(const float &_dt);
    virtual void Render(RenderTarget *_target);
    virtual void EndState();
    ~GameState();

};

