#include "pch.h"
#include "TileMap.h"

void TileMap::Clear()
{
	for (int x = 0; x < this->maxSizeWorldGrid.x; x++)
	{
		for (int y = 0; y < this->maxSizeWorldGrid.y; y++)
		{
			for (int z = 0; z < this->layers; z++)
			{
				for (int k = 0; k < this->map[x][y][z].size(); k++)
				{
					delete this->map[x][y][z][k];
					this->map[x][y][z][k] = nullptr;
				}
				this->map[x][y][z].clear();
			}
			this->map[x][y].clear();
		}
		this->map[x].clear();
	}
	this->map.clear();
}

TileMap::TileMap(float _gridSize, int _widht, int _height, string texture_file)
{
	this->gridSizeF = _gridSize;
	this->gridSizeI = static_cast<int>(this->gridSizeF);
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
	for (int x = 0; x < this->maxSizeWorldGrid.x; x++)
	{
		this->map.push_back(vector<vector<vector<Tile*>>>());

		for (int y = 0; y < this->maxSizeWorldGrid.y; y++)
		{
			this->map[x].resize(this->maxSizeWorldGrid.y);
			this->map[x].push_back(vector<vector<Tile*>>());

			for (int z = 0; z < this->layers; z++)
			{
				this->map[x][y].resize(this->layers);
				this->map[x][y].push_back(vector<Tile*>());
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
		this->map[_x][_y][_z].push_back(new Tile(_x, _y, this->gridSizeF, this->tileSheet, _texture_rect, _collision, _type));
	}
}

void TileMap::RemoveTile(unsigned _x, unsigned _y, unsigned _z)
{
	if (_x < this->maxSizeWorldGrid.x && _x >= 0 &&
		_y < this->maxSizeWorldGrid.x && _y >= 0 &&
		_z < this->layers && _z >= 0)
	{
		if (!this->map[_x][_y][_z].empty())
		{
			delete this->map[_x][_y][_z][this->map[_x][_y][_z].size() - 1];
			this->map[_x][_y][_z].pop_back();
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
			<< this->gridSizeI << endl
			<< this->layers << endl
			<< this->textureFile << endl;

		for (int x = 0; x < this->maxSizeWorldGrid.x; x++)
		{
			for (int y = 0; y < this->maxSizeWorldGrid.y; y++)
			{
				for (int z = 0; z < this->layers; z++)
				{
					if (!this->map[x][y][z].empty())
					{
						for (int k = 0; k < this->map[x][y][z].size(); k++)
						{
							ostream << x << " " << y << " " << z << " " << this->map[x][y][z][k]->GetAsString() << " ";
						}
					}
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
		Vector2i size;
		int gridSize = 0;
		int layers = 0;
		string texture_file = "";
		int x = 0;
		int y = 0;
		int z = 0;
		int textureRectX = 0;
		int textureRectY = 0;
		bool collision = false;
		short type = 0;

		istream >> size.x >> size.y >> gridSize >> layers >> texture_file;

		this->gridSizeI = gridSize;
		this->gridSizeF = static_cast<float>(gridSize);
		this->maxSizeWorldGrid.x = size.x;
		this->maxSizeWorldGrid.y = size.y;
		this->layers = layers;
		this->textureFile = texture_file;

		this->Clear();

		this->map.resize(this->maxSizeWorldGrid.x);

		for (int x = 0; x < this->maxSizeWorldGrid.x; x++)
		{
			this->map.push_back(vector<vector<vector<Tile*>>>());

			for (int y = 0; y < this->maxSizeWorldGrid.y; y++)
			{
				this->map[x].resize(this->maxSizeWorldGrid.y);
				this->map[x].push_back(vector<vector<Tile*>>());

				for (int z = 0; z < this->layers; z++)
				{
					this->map[x][y].resize(this->layers);
					this->map[x][y].push_back(vector<Tile*>());
				}
			}
		}

		if (!this->tileSheet.loadFromFile(texture_file))
			cerr << "Can't load texture";

		while (istream >> x >> y >> z >> textureRectX >> textureRectY >> collision >> type)
		{
			this->map[x][y][z].push_back(new Tile(
				x, y,
				this->gridSizeF,
				this->tileSheet,
				IntRect(textureRectX, textureRectY, this->gridSizeI, this->gridSizeI),
				collision,
				type));
		}
	}
	else
	{
		cerr << file_name << " couldn't be open";
	}

	istream.close();
}

void TileMap::UpdateCollision(Entity* _entity, float _dt)
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

	this->fromX = _entity->GetGridPosition(this->gridSizeI).x - 5;
	if (this->fromX < 0)
		this->fromX = 0;
	else if (this->fromX >= this->maxSizeWorldGrid.x)
		this->fromX = this->maxSizeWorldGrid.x - 1;

	this->toX = _entity->GetGridPosition(this->gridSizeI).x + 8;
	if (this->toX < 0)
		this->toX = 0;
	else if (this->toX >= this->maxSizeWorldGrid.x)
		this->toX = this->maxSizeWorldGrid.x - 1;

	this->fromY = _entity->GetGridPosition(this->gridSizeI).y - 5;
	if (this->fromY < 0)
		this->fromY = 0;
	else if (this->fromY >= this->maxSizeWorldGrid.x)
		this->fromY = this->maxSizeWorldGrid.x - 1;

	this->toY = _entity->GetGridPosition(this->gridSizeI).y + 8;
	if (this->toY < 0)
		this->toY = 0;
	else if (this->toY >= this->maxSizeWorldGrid.x)
		this->toY = this->maxSizeWorldGrid.x - 1;

	for (int x = this->fromX; x < this->toX; x++)
	{
		for (int y = this->fromY; y < this->toY; y++)
		{
			for (int k = 0; k < this->map[x][y][this->currentLayer].size(); k++)
			{
				FloatRect playerBounds = _entity->GetGlobalBounds();
				FloatRect wallBound = this->map[x][y][this->currentLayer][k]->GetGlobalBounds();
				FloatRect nextPosition = _entity->GetNextPositionBounds(_dt);

				if (this->map[x][y][this->currentLayer][k]->GetCollision() &&
					this->map[x][y][this->currentLayer][k]->Intersects(nextPosition))
				{
					//Bottom collision
					if (playerBounds.top < wallBound.top
						&& playerBounds.top + playerBounds.height < wallBound.top + wallBound.height
						&& playerBounds.left < wallBound.left + wallBound.width
						&& playerBounds.left + playerBounds.width > wallBound.left)
					{
						_entity->StopVelocityY();
						_entity->SetPosition(playerBounds.left, wallBound.top - playerBounds.height);
					}
					//Top collision
					else if (playerBounds.top > wallBound.top
						&& playerBounds.top + playerBounds.height > wallBound.top + wallBound.height
						&& playerBounds.left < wallBound.left + wallBound.width
						&& playerBounds.left + playerBounds.width > wallBound.left)
					{
						_entity->StopVelocityY();
						_entity->SetPosition(playerBounds.left, wallBound.top + wallBound.height);
					}
					//Right collision
					else if (playerBounds.left < wallBound.left
						&& playerBounds.left + playerBounds.width < wallBound.left + wallBound.width
						&& playerBounds.top < wallBound.top + wallBound.height
						&& playerBounds.top + playerBounds.height > wallBound.top)
					{
						_entity->StopVelocityX();
						_entity->SetPosition(wallBound.left - playerBounds.width, playerBounds.top);
					}
					//Left collision
					else if (playerBounds.left > wallBound.left
						&& playerBounds.left + playerBounds.width > wallBound.left + wallBound.width
						&& playerBounds.top < wallBound.top + wallBound.height
						&& playerBounds.top + playerBounds.height > wallBound.top)
					{
						_entity->StopVelocityX();
						_entity->SetPosition(wallBound.left + playerBounds.width, playerBounds.top);
					}
				}
			}
		}
	}
}

int TileMap::GetLayerSize(int _x, int _y, int _layer)
{
	if (_x >= 0 && _x < this->map.size())
	{
		if (_y >= 0 && _y < this->map[_x].size())
		{
			if (_layer >= 0 && _layer < this->map[_x][_y].size())
				return this->map[_x][_y][_layer].size();
		}
	}
	return -1;
}

void TileMap::Render(RenderTarget& _target, const Vector2i& _gridPosition)
{
	this->currentLayer = 0;

	this->fromX = _gridPosition.x - 20;
	if (this->fromX < 0)
		this->fromX = 0;
	else if (this->fromX > this->maxSizeWorldGrid.x)
		this->fromX = this->maxSizeWorldGrid.x;

	this->toX = _gridPosition.x + 20;
	if (this->toX < 0)
		this->toX = 0;
	else if (this->toX > this->maxSizeWorldGrid.x)
		this->toX = this->maxSizeWorldGrid.x;

	this->fromY = _gridPosition.y - 20;
	if (this->fromY < 0)
		this->fromY = 0;
	else if (this->fromY > this->maxSizeWorldGrid.x)
		this->fromY = this->maxSizeWorldGrid.x;

	this->toY = _gridPosition.y + 20;
	if (this->toY < 0)
		this->toY = 0;
	else if (this->toY > this->maxSizeWorldGrid.x)
		this->toY = this->maxSizeWorldGrid.x;

	for (int x = this->fromX; x < this->toX; x++)
	{
 		for (int y = this->fromY; y < this->toY; y++)
		{
			for (int k = 0; k < map[x][y][this->currentLayer].size(); k++)
			{
				if (this->map[x][y][this->currentLayer][k]->GetType() == TILE_TYPE::DOODAD)
				{
					this->deferredRenderStack.push(this->map[x][y][this->currentLayer][k]);
				}
				else
				{
					this->map[x][y][this->currentLayer][k]->Render(_target);
				}

				if (this->map[x][y][this->currentLayer][k]->GetCollision())
				{
					this->collideBox.setPosition(this->map[x][y][this->currentLayer][k]->GetPosition());
					_target.draw(this->collideBox);
				}
			}

		}
	}

}

void TileMap::RenderDeferred(RenderTarget& _target)
{
	while (!this->deferredRenderStack.empty())
	{
		this->deferredRenderStack.top()->Render(_target);
		this->deferredRenderStack.pop();
	}
}
