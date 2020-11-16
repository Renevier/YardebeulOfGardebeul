#include "Database.h"

void Database::Fill()
{
	for(auto it : this->myArmorContainer.GetContainer())
		this->database.emplace(it);

	for (auto it : this->myChestContainer.GetContainer())
		this->database.emplace(it);

	for (auto it : this->myConsumableContainer.GetContainer())
		this->database.emplace(it);

	for (auto it : this->myDungeonContainer.GetContainer())
		this->database.emplace(it);

	for (auto it : this->myEffectContainer.GetContainer())
		this->database.emplace(it);

	for (auto it : this->myEventContainer.GetContainer())
		this->database.emplace(it);

	for (auto it : this->myNpcContainer.GetContainer())
		this->database.emplace(it);

	for (auto it : this->myWeaponContainer.GetContainer())
		this->database.emplace(it);
}

Database::Database()
{
	this->Fill();
}

Database::~Database()
{
}
