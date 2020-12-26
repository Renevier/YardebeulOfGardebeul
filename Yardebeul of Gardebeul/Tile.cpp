#include "pch.h"
#include "Tile.h"

Tile::Tile()
{
	this->collision = false;
	this->type = 0;
}

Tile::Tile(unsigned _grid_x, unsigned _grid_y, float _gridSizeF, const Texture& _texture, const IntRect& _texture_rect, bool _collision, short _type)
{
	this->shape.setSize(Vector2f(_gridSizeF, _gridSizeF));
	this->shape.setPosition(static_cast<float>(_grid_x) * _gridSizeF, static_cast<float>(_grid_y) * _gridSizeF);
	this->shape.setTexture(&_texture);
	this->shape.setTextureRect(_texture_rect);

	this->collision = _collision;
	this->type = _type;
}

void Tile::Update()
{
}

void Tile::Render(RenderTarget& target)
{
	target.draw(this->shape);
}


string Tile::GetAsString()
{
	stringstream ss;

	ss << this->shape.getTextureRect().left << " " << this->shape.getTextureRect().top << " " << this->collision << " " << 
		this->type << " ";

	return ss.str();
}

Tile::~Tile()
{
}
