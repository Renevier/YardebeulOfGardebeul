#pragma once
#include "Chest.h"
#include "pch.h"

class ChestContainer
{
protected:
	map<string, Chest> container;

private:
	void Fill();

public:
	ChestContainer();
	~ChestContainer();

};