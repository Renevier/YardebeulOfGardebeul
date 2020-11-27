#include "Tile.h"

Tile::Tile(float _x, float _y, Vector2f _side)
{
	this->idleColor = Color::White;
	this->tileState = TILE_STATE::TILE_IDLE;

	this->shape.setFillColor(this->idleColor);

	this->shape.setSize(_side);
	this->shape.setOrigin(this->shape.getGlobalBounds().width / 2, this->shape.getGlobalBounds().height / 2);
	this->shape.setPosition(_x + this->shape.getGlobalBounds().width / 2,
		_y + this->shape.getGlobalBounds().height / 2);
	this->shape.setOutlineColor(Color::Black);
	this->shape.setOutlineThickness(2.f);
		
}

Tile::Tile(Texture* _texture, float _x, float _y)
{
	Vector2f tileSize = Vector2f(_texture->getSize().x / 5, _texture->getSize().y / 22);

	this->tileState = TILE_STATE::TILE_IDLE;
	this->shape.setTexture(_texture);
	this->shape.setSize(Vector2f(tileSize.x, tileSize.y));
	this->shape.setOrigin(this->shape.getGlobalBounds().width / 2, this->shape.getGlobalBounds().height / 2);

	this->shape.setTextureRect(IntRect(_x, _y, tileSize.x, tileSize.y));
	
	
	this->shape.setPosition(_x + this->shape.getGlobalBounds().width / 2,
		_y + this->shape.getGlobalBounds().height / 2);
}

void Tile::Update(const Vector2f _mousePos)
{
	this->tileState = TILE_STATE::TILE_IDLE;

	if (this->shape.getGlobalBounds().contains(_mousePos))
	{
		if (this->shape.getGlobalBounds().contains(_mousePos))
		{
			this->tileState = TILE_STATE::TILE_HOVER;

			if (Mouse::isButtonPressed(Mouse::Left))
				this->tileState = TILE_STATE::TILE_PRESSED;
		}
	}

	switch (this->tileState)
	{
	case TILE_STATE::TILE_IDLE:
		this->shape.setFillColor(this->idleColor);
		break;
	case TILE_STATE::TILE_HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;
	case TILE_STATE::TILE_PRESSED:
		this->shape.setFillColor(this->activeColor);
		break;
	default:
		this->shape.setFillColor(Color::Green);
		break;
	}
}

void Tile::Render(RenderTarget* target)
{
	target->draw(this->shape);
}

bool Tile::IsPressed() const
{
	if (this->tileState == TILE_STATE::TILE_PRESSED)
		return true;

	return false;
}

Tile::~Tile()
{
}
