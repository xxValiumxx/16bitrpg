#ifndef BITRPG_TEXTURE_MANAGER_H
#define BITRPG_TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

class TextureManager{
private:
	std::vector<sf::Texture> textureList;
	std::map<int, int> textureIDs;

	int tileSize;
public:
	TextureManager();
	~TextureManager();
	int getTileSize(){ return this->tileSize; }
	void setTileSize(int tileSize){ this->tileSize = tileSize; }
	int numtiles;
	void AddTexture(sf::Texture& texture, int id);
	sf::Texture& GetTexture(int id);

	//Loads tileset from XML
	void LoadTileset(const char* filename);
	int tilesetWidth;
	int tilesetHeight;

};
#endif

