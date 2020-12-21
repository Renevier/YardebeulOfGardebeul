#include "pch.h"
#include "TileMap.h"

TileMap::TileMap(float _gridSize, unsigned _widht, unsigned _height)
{
	this->gridSizeF = _gridSize;
	this->gridSizeU = static_cast<unsigned>(this->gridSizeF);
	this->maxSize.x = _widht;
	this->maxSize.y = _height;
	this->layers = 1;

	this->map.resize(this->maxSize.x);

	for (size_t x = 0; x < this->maxSize.x; x++)
	{
		this->map.push_back(vector<vector<Tile*>>());

		for (size_t y = 0; y < this->maxSize.y; y++)
		{
			this->map[x].resize(this->maxSize.y);
			this->map[x].push_back(vector<Tile*>());

			for (size_t z = 0; z < this->layers; z++)
			{
				this->map[x][y].resize(this->layers);
				this->map[x][y].push_back(nullptr);
			}
		}
	}
}

TileMap::~TileMap()
{
	for (size_t x = 0; x < this->maxSize.x; x++)
	{
		for (size_t y = 0; y < this->maxSize.y; y++)
		{
			for (size_t z = 0; z < this->layers; z++)
			{
				delete this->map[x][y][z];
			}
		}
	}
}

void TileMap::Update()
{
}

void TileMap::Render(RenderTarget& _target)
{
	for(auto &x : this->map)
	{
		for (auto& y : x)
		{
			for (auto* z : y)
			{
				if(z != nullptr)
					z->Render(_target);
			}
		}
	}
}

void TileMap::AddTile(unsigned _x, unsigned _y, unsigned _z)
{
	if (_x < this->maxSize.x && _x >= 0 &&
		_y < this->maxSize.x && _y >= 0 &&
		_z < this->layers && _z >= 0)
	{
		if (this->map[_x][_y][_z] == nullptr)
		{
			this->map[_x][_y][_z] = new Tile(_x * this->gridSizeF, _y * this->gridSizeF, this->gridSizeF);
		}

	}
}
