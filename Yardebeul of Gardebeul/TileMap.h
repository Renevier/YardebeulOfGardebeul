#pragma once
#include "Tile.h"
#include "Entity.h"

class TileMap
{
protected:
	float gridSizeF;
	unsigned gridSizeU;
	Vector2u maxSizeWorldGrid;
	Vector2f maxSizeWorldF;
	unsigned layers;
	vector<vector<vector<Tile*>>> map;
	Texture tileSheet;
	string textureFile;

	RectangleShape collideBox;

	//Culling
	int fromX;
	int toX;
	int fromY;
	int toY;
	int currentLayer;


private:
	void Clear();

public:
	TileMap(float _gridSize, unsigned _widht, unsigned _height, string texture_file);
	~TileMap();

	void Update();
	void Render(RenderTarget& _target, Entity* _entity = nullptr);

	void AddTile(unsigned _x, unsigned _y, unsigned _z, IntRect& _texture_rect, const bool& _collision, const short& _type);
	void RemoveTile(unsigned _x, unsigned _y, unsigned _z);
	void Save(string file_name);
	void Load(string file_name);

	void UpdateCollision(Entity* _entity);

	inline Texture* GetTileSheet() { return &this->tileSheet; }
};

