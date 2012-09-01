#include "Level.h"




Level::Level()
{
	
}
Level::~Level()
{

}

int Level::GetHeight()
{
	return h;
}

int Level::GetWidth()
{
	return w;
}

void Level::SetDimensions(int w, int h)
{
	//w rows
	map.resize(w);

	//each row has ha columns of null tile pointers
	for(int i = 0; i < w ; i++)
	{
		map.at(i).resize(h, 0);
	}
}

void Level::AddTile(int x, int y, Tile*	tile)
{
	map[x][y] = tile;
}

Tile* Level::GetTile(int x, int y)
{
	return map[x][y];
}

void Level::LoadLevel(const char* filename, TextureManager& texturemanager)
{
	//Pull from a png LOL
	sf::Image mapimage;
	mapimage.loadFromFile(filename);

	int width = mapimage.getSize().x;
	int height = mapimage.getSize().y;
	SetDimensions(width, height);
	this->w = width;
	this->h = height;
	sf::Color color;
	//RED is tile ID
	Tile* tile;
	

	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			color = mapimage.getPixel(x, y);
			tile = new Tile(texturemanager.GetTexture((int)color.r));
			AddTile(x, y, tile);
		}
	}


}
void Level::LoadLevelFromXML(const char* filename, TextureManager& texturemanager)
{
	

	


}

