#pragma once
#include "Tile.h"
#include "Entity.h"

class TileMap
{
protected:
	float gridSizeF;
	int gridSizeI;
	Vector2i maxSizeWorldGrid;
	Vector2f maxSizeWorldF;
	unsigned layers;
	vector<vector<vector<vector<Tile*>>>> map;
	stack<Tile*> deferredRenderStack;
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
	TileMap(float _gridSize, int _widht, int _height, string texture_file);
	~TileMap();

	void Update();
	void Render(RenderTarget& _target, const Vector2i& _gridPosition);
	void RenderDeferred(RenderTarget& _target);

	void AddTile(unsigned _x, unsigned _y, unsigned _z, IntRect& _texture_rect, const bool& _collision, const short& _type);
	void RemoveTile(unsigned _x, unsigned _y, unsigned _z);
	void Save(string file_name);
	void Load(string file_name);

	void UpdateCollision(Entity* _entity, float _dt);

	inline Texture* GetTileSheet() { return &this->tileSheet; }
	int GetLayerSize(int _x, int _y, int _layer);
};

