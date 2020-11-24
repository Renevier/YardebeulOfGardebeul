#pragma once
#include "pch.h"

enum class TILE_STATE
{
	TILE_IDLE,
	TILE_HOVER,
	TILE_PRESSED
};

class Tile
{
protected:
	TILE_STATE tileState;

	RectangleShape shape;

	Color hoverColor;
	Color idleColor;
	Color activeColor;

private:


public:
	Tile(float _x, float _y, float _side);
	Tile(Texture* _texture, float _x, float _y);
	void Update(const Vector2f _mousePos);
	void Render(RenderTarget* target);
	bool IsPressed() const;
	~Tile();
};

