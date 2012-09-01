#include "Tile.h"
#include <SFML\Graphics.hpp>

Tile::Tile(sf::Texture& texture)
{
	baseSprite.setTexture(texture, true);
}

Tile::~Tile()
{

}

void Tile::Draw(int x, int y, sf::RenderTexture* rw)
{
	baseSprite.setPosition((float)x, (float)y);
	rw->draw(baseSprite);
}
void Tile::DrawWindow(int x, int y, sf::RenderWindow* rw)
{
	baseSprite.setPosition((float)x, (float)y);
	rw->draw(baseSprite);
}
