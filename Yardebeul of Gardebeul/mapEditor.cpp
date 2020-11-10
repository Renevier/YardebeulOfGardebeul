#include "mapEditor.h"

void MapEditor::InitMap(RenderWindow &_window)
{
	RectangleShape shape(Vector2f(50, 50));

	for (int i = 0; i <= _window.getSize().y / 50; i++)
	{
		for (int j = 0; j <= _window.getSize().x / 50; j++)
		{
			map.push_back(shape);
		}
	}
}

MapEditor::MapEditor(RenderWindow &_window)
{
	this->InitMap(_window);
}

void MapEditor::Display(RenderWindow& _window)
{
	for (int i = 0; i <= this->map.size(); i++)
	{
		for (int j = 0; j <= _window.getSize().x / 50; j++)
		{
			
		}
	}
	//_window.draw(this->map);
}

MapEditor::~MapEditor()
{
}
