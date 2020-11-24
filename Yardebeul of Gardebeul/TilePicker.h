#pragma once
#include"Tile.h"

#include "pch.h"
class TilePicker
{
protected:
	Texture tilePickerTexture;
	list<Tile*> tilePicker;

private:
	void InitPicker();

public:
	TilePicker();
	~TilePicker();
};