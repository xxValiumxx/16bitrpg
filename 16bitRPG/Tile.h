#ifndef BITRPG_TILE_H
#define BITRPG_TILE_H

#include <SFML\Graphics.hpp>
#include "CollisionTypes.h"
#include "TileFlags.h"

class Tile
{
private:
	sf::Sprite baseSprite;
	sf::Sprite baseSprite2;
	CollisionType collision;


public:
	Tile(sf::Texture& image);
	~Tile();

	void Draw(int x, int y, sf::RenderTexture* rw);
	void DrawWindow(int x, int y, sf::RenderWindow* rw);
};

#endif