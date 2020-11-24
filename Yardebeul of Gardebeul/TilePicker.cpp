#include "TilePicker.h"

void TilePicker::InitPicker()
{
	if (!this->tilePickerTexture.loadFromFile("../Ressources/Tilesmap/IceDungeonTiles.png"))
		exit(0);
}

TilePicker::TilePicker()
{
	this->InitPicker();
}

TilePicker::~TilePicker()
{
}
