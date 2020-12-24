#include "pch.h"
#include "TileMap.h"

void TileMap::Clear()
{
	for (size_t x = 0; x < this->maxSizeWorldGrid.x; x++)
	{
		for (size_t y = 0; y < this->maxSizeWorldGrid.y; y++)
		{
			for (size_t z = 0; z < this->layers; z++)
			{
				delete this->map[x][y][z];
				this->map[x][y][z] = nullptr;
			}
			this->map[x][y].clear();
		}
		this->map[x].clear();
	}
	this->map.clear();
}

TileMap::TileMap(float _gridSize, unsigned _widht, unsigned _height, string texture_file)
{
	this->gridSizeF = _gridSize;
	this->gridSizeU = static_cast<unsigned>(this->gridSizeF);
	this->maxSizeWorldGrid.x = _widht;
	this->maxSizeWorldGrid.y = _height;
	this->maxSizeWorldF.x = static_cast<float>(_widht) * _gridSize;
	this->maxSizeWorldF.y = static_cast<float>(_height) * _gridSize;
	this->layers = 1;
	this->textureFile = texture_file;

	this->map.resize(this->maxSizeWorldGrid.x);

	for (size_t x = 0; x < this->maxSizeWorldGrid.x; x++)
	{
		this->map.push_back(vector<vector<Tile*>>());

		for (size_t y = 0; y < this->maxSizeWorldGrid.y; y++)
		{
			this->map[x].resize(this->maxSizeWorldGrid.y);
			this->map[x].push_back(vector<Tile*>());

			for (size_t z = 0; z < this->layers; z++)
			{
				this->map[x][y].resize(this->layers);
				this->map[x][y].push_back(nullptr);
			}
		}
	}

	if (!this->tileSheet.loadFromFile(texture_file))
		cerr << "Can't load texture";

	this->collideBox.setSize(Vector2f(_gridSize, _gridSize));
	this->collideBox.setFillColor(Color::Red);
	this->collideBox.setOutlineThickness(1.f);
	this->collideBox.setOutlineColor(Color::Red);
}

TileMap::~TileMap()
{
	this->Clear();
}

void TileMap::Update()
{
}

void TileMap::Render(RenderTarget& _target, Entity* _entity)
{
	for (auto& x : this->map)
	{
		for (auto& y : x)
		{
			for (auto* z : y)
			{
				if (z != nullptr)
				{
					z->Render(_target);
					if (z->GetCollision())
					{
						this->collideBox.setPosition(z->GetPosition());
						_target.draw(this->collideBox);
					}
				}
			}
		}
	}
}

void TileMap::AddTile(unsigned _x, unsigned _y, unsigned _z, IntRect& _texture_rect, const bool& _collision, const short& _type)
{
	if (_x < this->maxSizeWorldGrid.x && _x >= 0 &&
		_y < this->maxSizeWorldGrid.x && _y >= 0 &&
		_z < this->layers && _z >= 0)
	{
		if (this->map[_x][_y][_z] == nullptr)
		{
			this->map[_x][_y][_z] = new Tile(_x, _y, this->gridSizeF, this->tileSheet, _texture_rect, _collision, _type);
		}

	}
}

void TileMap::RemoveTile(unsigned _x, unsigned _y, unsigned _z)
{
	if (_x < this->maxSizeWorldGrid.x && _x >= 0 &&
		_y < this->maxSizeWorldGrid.x && _y >= 0 &&
		_z < this->layers && _z >= 0)
	{
		if (this->map[_x][_y][_z] != nullptr)
		{
			delete this->map[_x][_y][_z];
			this->map[_x][_y][_z] = nullptr;
		}

	}
}

void TileMap::Save(string file_name)
{
	ofstream ostream;
	ostream.open("../Ressources/Saves/" + file_name + ".txt");

	if (ostream.is_open())
	{
		ostream << this->maxSizeWorldGrid.x << " " << this->maxSizeWorldGrid.y << endl
			<< this->gridSizeU << endl
			<< this->layers << endl
			<< this->textureFile << endl;

		for (size_t x = 0; x < this->maxSizeWorldGrid.x; x++)
		{
			for (size_t y = 0; y < this->maxSizeWorldGrid.y; y++)
			{
				for (size_t z = 0; z < this->layers; z++)
				{
					if (this->map[x][y][z])
						ostream << x << " " << " " << y << " " << z << " " << this->map[x][y][z]->GetAsString() << " ";
				}
			}
		}
	}
	else
	{
		cerr << file_name << " couldn't be open";
	}

	ostream.close();
}

void TileMap::Load(string file_name)
{
	ifstream istream;
	istream.open("../Ressources/Saves/" + file_name + ".txt");

	if (istream.is_open())
	{
		Vector2u size;
		unsigned gridSize = 0;
		unsigned layers = 0;
		string texture_file = "";
		unsigned x = 0;
		unsigned y = 0;
		unsigned z = 0;
		unsigned textureRectX = 0;
		unsigned textureRectY = 0;
		bool collision = false;
		short type = 0;

		istream >> size.x >> size.y >> gridSize >> layers >> texture_file;

		this->gridSizeU = gridSize;
		this->gridSizeF = static_cast<float>(gridSize);
		this->maxSizeWorldGrid.x = size.x;
		this->maxSizeWorldGrid.y = size.y;
		this->layers = layers;
		this->textureFile = texture_file;

		this->Clear();

		this->map.resize(this->maxSizeWorldGrid.x);

		for (size_t x = 0; x < this->maxSizeWorldGrid.x; x++)
		{
			this->map.push_back(vector<vector<Tile*>>());

			for (size_t y = 0; y < this->maxSizeWorldGrid.y; y++)
			{
				this->map[x].resize(this->maxSizeWorldGrid.y);
				this->map[x].push_back(vector<Tile*>());

				for (size_t z = 0; z < this->layers; z++)
				{
					this->map[x][y].resize(this->layers);
					this->map[x][y].push_back(nullptr);
				}
			}
		}

		if (!this->tileSheet.loadFromFile(texture_file))
			cerr << "Can't load texture";

		while (istream >> x >> y >> z >> textureRectX >> textureRectY >> collision >> type)
		{
			this->map[x][y][z] = new Tile(
				x, y,
				this->gridSizeF,
				this->tileSheet,
				IntRect(textureRectX, textureRectY, this->gridSizeU, this->gridSizeU),
				collision,
				type);
		}
	}
	else
	{
		cerr << file_name << " couldn't be open";
	}

	istream.close();
}

void TileMap::UpdateCollision(Entity* _entity)
{
	if (_entity->GetPos().x < 0.f)
		_entity->SetPosition(0.f, _entity->GetPos().y);
	else if (_entity->GetPos().x + _entity->GetGlobalBounds().width > this->maxSizeWorldF.x)
		_entity->SetPosition(this->maxSizeWorldF.x - _entity->GetGlobalBounds().width, _entity->GetPos().y);

	if (_entity->GetPos().y < 0.f)
		_entity->SetPosition(_entity->GetPos().x, 0.f);
	else if (_entity->GetPos().y + _entity->GetGlobalBounds().height > this->maxSizeWorldF.y)
		_entity->SetPosition(_entity->GetPos().x, this->maxSizeWorldF.y - _entity->GetGlobalBounds().height);
}
