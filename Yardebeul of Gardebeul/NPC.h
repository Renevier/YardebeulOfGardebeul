#pragma once
#include "Character.h"
class NPC : public Character
{
protected:
       Behaviour behaviour;

    //Function
private:
    virtual void InitVariable(string _name, int _level, Behaviour _behaviour, float _Hp, float _Mp, float _endure);
    virtual void InitComponent(float _x, float _y, Texture& _texture_sheet);

public:
    NPC(string _name, int _level, Behaviour _behaviour, float _Hp, float _Mp, float _endure);
    ~NPC();

    virtual void DisplayStats();
};

