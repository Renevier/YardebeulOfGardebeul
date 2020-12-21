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
	Texture tileSheet;


public:
	TileMap(float _gridSize, unsigned _widht, unsigned _height);
	~TileMap();

	void Update();
	void Render(RenderTarget& _target);

	void AddTile(unsigned _x, unsigned _y, unsigned _z, IntRect& _texture_rect);
	void RemoveTile(unsigned _x, unsigned _y, unsigned _z);

	inline Texture* GetTileSheet() { return &this->tileSheet; }
};

