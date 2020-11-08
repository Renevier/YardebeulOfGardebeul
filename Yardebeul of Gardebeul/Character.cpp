#include "Character.h"

Character::Character()
{
}

void Character::DisplayStats()
{
	cout << this->name << endl;
	cout << this->level << endl;
	cout << this->healthPoints << endl;
	cout << this->manaPoints << endl;
	cout << this->endurePoints << endl;
	cout << this->mindPoints << endl;
}

Character::~Character()
{
}
