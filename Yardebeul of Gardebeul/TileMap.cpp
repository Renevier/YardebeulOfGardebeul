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

	this->fromX = 0;
	this->toX = 0;
	this->fromY = 0;
	this->toY = 0;
	this->currentLayer = 0;

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

}

TileMap::~TileMap()
{
	this->Clear();
}

void TileMap::Update()
{
}


void TileMap::AddTile(unsigned _x, unsigned _y, unsigned _z, IntRect& _texture_rect, const bool& _collision, const short& _type)
{
	if (_x < this->maxSizeWorldGrid.x && _x >= 0 &&
		_y < this->maxSizeWorldGrid.y && _y >= 0 &&
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
						ostream << x << " " << y << " " << z << " " << this->map[x][y][z]->GetAsString() << " ";
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
	//World collision
	if (_entity->GetPos().x < 0.f)
	{
		_entity->SetPosition(0.f, _entity->GetPos().y);
		_entity->StopVelocityX();
	}
	else if (_entity->GetPos().x + _entity->GetGlobalBounds().width > this->maxSizeWorldF.x)
	{
		_entity->SetPosition(this->maxSizeWorldF.x - _entity->GetGlobalBounds().width, _entity->GetPos().y);
		_entity->StopVelocityX();
	}

	if (_entity->GetPos().y < 0.f)
	{
		_entity->SetPosition(_entity->GetPos().x, 0.f);
		_entity->StopVelocityY();
	}
	else if (_entity->GetPos().y + _entity->GetGlobalBounds().height > this->maxSizeWorldF.y)
	{
		_entity->SetPosition(_entity->GetPos().x, this->maxSizeWorldF.y - _entity->GetGlobalBounds().height);
		_entity->StopVelocityX();
	}

	//Tiles collision
	this->currentLayer = 0;

	this->fromX = _entity->GetGridPosition(this->gridSizeU).x - 5;
	if (this->fromX < 0)
		this->fromX = 0;
	else if (this->fromX >= this->maxSizeWorldGrid.x)
		this->fromX = this->maxSizeWorldGrid.x - 1;

	this->toX = _entity->GetGridPosition(this->gridSizeU).x + 8;
	if (this->toX < 0)
		this->toX = 0;
	else if (this->toX >= this->maxSizeWorldGrid.x)
		this->toX = this->maxSizeWorldGrid.x - 1;

	this->fromY = _entity->GetGridPosition(this->gridSizeU).y - 5;
	if (this->fromY < 0)
		this->fromY = 0;
	else if (this->fromY >= this->maxSizeWorldGrid.x)
		this->fromY = this->maxSizeWorldGrid.x - 1;

	this->toY = _entity->GetGridPosition(this->gridSizeU).y + 8;
	if (this->toY < 0)
		this->toY = 0;
	else if (this->toY >= this->maxSizeWorldGrid.x)
		this->toY = this->maxSizeWorldGrid.x - 1;

	for (size_t x = this->fromX; x < this->toX; x++)
	{
		for (size_t y = this->fromY; y < this->toY; y++)
		{
			if(this->map[x][y][this->currentLayer]->GetCollision() &&
				this->map[x][y][this->currentLayer]->Intersects(_entity->GetGlobalBounds()))
			{
				cout << "COLLISION" << endl;
			}
		}
	}
}

void TileMap::Render(RenderTarget& _target, Entity* _entity)
{
	if (_entity)
	{

		this->currentLayer = 0;

		this->fromX = _entity->GetGridPosition(this->gridSizeU).x - 5;
		if (this->fromX < 0)
			this->fromX = 0;
		else if (this->fromX > this->maxSizeWorldGrid.x)
			this->fromX = this->maxSizeWorldGrid.x;

		this->toX = _entity->GetGridPosition(this->gridSizeU).x + 8;
		if (this->toX < 0)
			this->toX = 0;
		else if (this->toX > this->maxSizeWorldGrid.x)
			this->toX = this->maxSizeWorldGrid.x;

		this->fromY = _entity->GetGridPosition(this->gridSizeU).y - 5;
		if (this->fromY < 0)
			this->fromY = 0;
		else if (this->fromY > this->maxSizeWorldGrid.x)
			this->fromY = this->maxSizeWorldGrid.x;

		this->toY = _entity->GetGridPosition(this->gridSizeU).y + 8;
		if (this->toY < 0)
			this->toY = 0;
		else if (this->toY > this->maxSizeWorldGrid.x)
			this->toY = this->maxSizeWorldGrid.x;

		for (size_t x = this->fromX; x < this->toX; x++)
		{
			for (size_t y = this->fromY; y < this->toY; y++)
			{
				this->map[x][y][this->currentLayer]->Render(_target);
				if (this->map[x][y][this->currentLayer]->GetCollision())
				{
					this->collideBox.setPosition(this->map[x][y][this->currentLayer]->GetPosition());
					_target.draw(this->collideBox);
				}
			}
		}
	}
	else
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
}
