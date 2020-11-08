#pragma once
#include "Character.h"
class NPC : public Character
{
protected:
       Behaviour behaviour;

    //Function
private:
    virtual void InitVariable(string _name, float _level, Behaviour _behaviour, float _Hp, float _Mp, float _endure);

public:
    NPC(string _name, float _level, Behaviour _behaviour, float _Hp, float _Mp, float _endure);
    ~NPC();
};

