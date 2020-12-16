#pragma once
#include "Tile.h"

class TileMap
{
protected:
	unsigned gridSizeU;
	Vector2u maxSize;
	unsigned layers;
	vector<vector<vector<Tile>>> map;


public:
	TileMap();
	~TileMap();
};

