#pragma once

enum class TILE_STATE
{
	TILE_IDLE,
	TILE_HOVER,
	TILE_PRESSED
};

enum TILE_TYPE
{
	DEFAULT = 0,
	DAMAGING
};

class Tile
{
protected:
	RectangleShape shape;
	short type;
	bool collision;
private:


public:
	Tile();
	~Tile();

	Tile(unsigned _grid_x, unsigned _grid_y, float _gridSizeF, const Texture& _texture, const IntRect& _texture_rect, 
		bool _collision, short _type);
	void Update();
	void Render(RenderTarget& target);


	string GetAsString();

};