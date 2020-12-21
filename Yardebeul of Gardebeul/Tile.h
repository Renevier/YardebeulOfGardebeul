#pragma once

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
	Tile();
	~Tile();

	Tile(float _x, float _y, float _grisSizeF, Texture& _texture, IntRect& _texture_rect);
	Tile(float _x, float _y, Vector2f _side);
	Tile(Texture* _texture, Vector2f _posOnScreen, Vector2f _posInTexture);
	void Update(const Vector2f _mousePos);
	void Render(RenderTarget& target);
	bool IsPressed() const;

};