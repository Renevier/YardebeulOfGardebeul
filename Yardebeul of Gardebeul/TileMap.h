#pragma once
#include "Tile.h"

class TileMap
{
protected:
	float gridSizeF;
	unsigned gridSizeU;
	Vector2u maxSize;
	unsigned layers;
	vector<vector<vector<Tile*>>> map;


public:
	TileMap(float _gridSize, unsigned _widht, unsigned _height);
	~TileMap();

	void Update();
	void Render(RenderTarget& _target);

	void AddTile(unsigned _x, unsigned _y, unsigned _z);
	void RemoveTile();
};

