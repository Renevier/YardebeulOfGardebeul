#include "Character.h"

Character::Character()
{
}

Character::~Character()
{
}

string Character::GetName()
{
    return this->name;
}

int Character::GetLevel()
{
    return this->level;
}

float Character::GetHP()
{
    return this->healthPoints;
}

float Character::GetMP()
{
    return this->manaPoints;
}

float Character::GetEndurePoint()
{
    return this->endurePoints;
}

float Character::GetMindPoint()
{
    return this->mindPoints;
}
