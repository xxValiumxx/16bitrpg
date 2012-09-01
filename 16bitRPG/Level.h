#ifndef BITRPG_LEVEL_H
#define BITRPG_LEVEL_H

#include<vector>
#include "Tile.h"
#include "TextureManager.h"

class Level
{
	private:
	//A 2d array of Tile Pointers
		std::vector<std::vector<Tile*> > map;

	//Width and height of level in tiles
		int w;
		int h;

	void SetDimensions(int w, int h);
	
public:
	Level();
	~Level();
	sf::RenderTexture leveltexture;

	
	void AddTile(int x, int y, Tile* tile);
	Tile* GetTile(int x, int y);
	
	void LoadLevel(const char* filename, TextureManager& texturemanager);
	void LoadLevelFromXML(const char* filename, TextureManager& texturemanager);

	int GetWidth();
	int GetHeight();
	
};

#endif