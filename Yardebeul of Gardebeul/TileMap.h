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
	string textureFile;

private:
	void Clear();

public:
	TileMap(float _gridSize, unsigned _widht, unsigned _height, string texture_file);
	~TileMap();

	void Update();
	void Render(RenderTarget& _target);

	void AddTile(unsigned _x, unsigned _y, unsigned _z, IntRect& _texture_rect, const bool& _collision, const short& _type);
	void RemoveTile(unsigned _x, unsigned _y, unsigned _z);
	void Save(string file_name);
	void Load(string file_name);

	inline Texture* GetTileSheet() { return &this->tileSheet; }
};

