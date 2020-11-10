#pragma once
#include "pch.h"

class MapEditor
{
	//Variables
protected:
	vector<RectangleShape> map;

	//Functions
private:
	void InitMap(RenderWindow& _window);

public:
	MapEditor(RenderWindow& _window);
	void Display(RenderWindow& _window);
	~MapEditor();
};
