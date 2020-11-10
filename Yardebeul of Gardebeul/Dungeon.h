#pragma once
#include "Entity.h"
#include "Room.h"

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

    map<string, Room> container;

    //Functions
private:
    void InitVariable(string _name, int _level, STATE_EVENT _type, int _nbEvent, vector<STATE_EVENT> _listOfEvent);
    void Fill();

public:
    Dungeon(string _name, int _level, STATE_EVENT _type, int _nbEvent, vector<STATE_EVENT> _listOfEvent);
    ~Dungeon();

};

