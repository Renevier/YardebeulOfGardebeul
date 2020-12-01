#pragma once
#include"Tile.h"

#include "pch.h"
class TilePicker
{
protected:
	Texture tilePickerTexture;
	list<Tile*> tilePicker;

private:
	void InitPicker(RenderWindow* _window);

public:
	TilePicker(RenderWindow* _window);
	~TilePicker();
};