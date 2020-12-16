#pragma once
#include "Tile.h"

class TileMap
{
protected:
	float gridSizeF;
	unsigned gridSizeU;
	Vector2u maxSize;
	unsigned layers;
	vector<vector<vector<Tile>>> map;


public:
	TileMap();
	~TileMap();

	void Update();
	void Render(RenderTarget& _target);
};

