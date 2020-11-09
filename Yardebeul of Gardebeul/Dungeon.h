#pragma once
#include "Entity.h"
class Dungeon :
    public Entity
{
    // Variables
protected:
    string name;
    int level;
    STATE_EVENT type;
    int nbEvent;
    vector<STATE_EVENT> listOfEvent;

    //Functions
private:

public:

};

