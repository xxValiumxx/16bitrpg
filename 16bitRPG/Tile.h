#ifndef BITRPG_TILE_H
#define BITRPG_TILE_H

#include <SFML\Graphics.hpp>

class Tile
{
private:
	sf::Sprite baseSprite;

public:
	Tile(sf::Texture& image);
	~Tile();

	void Draw(int x, int y, sf::RenderWindow* rw);
};

#endif