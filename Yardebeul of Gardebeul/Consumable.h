#pragma once
#include "Object.h"
#include "pch.h"

class Consumable :
    public Object
{
    //Varibles
protected:
    Effect effect;

    //Function
private:
    void InitVariable(string _name, float _price, Effect _effect, float _durability);

public:
    Consumable(string _name, float _price, Effect _effect, float _durability);
    virtual void Choose();
    virtual void DisplayStat();
    ~Consumable();
};

