#include "TextureManager.h"



TextureManager::TextureManager(){
}

TextureManager::~TextureManager(){
}

void TextureManager::AddTexture(sf::Texture& texture, int id){
	textureList.push_back(texture);
	
	//map for pairing image id and image index in imageList
	textureIDs[id] = textureList.size() - 1;
}

void TextureManager::LoadTileset(const char* filename){
	
	sf::Image tileset;
	sf::Image tileImage;
	sf::Texture tileTexture;
	tileset.loadFromFile(filename);
	
	this->tilesetWidth = tileset.getSize().x;
	this->tilesetHeight = tileset.getSize().y;
	
	int tileX = tileset.getSize().x / tileSize;
	int tileY = tileset.getSize().y / tileSize;
	
	numtiles = 0;
	
	for(int y=0; y<tileY; y++)
	{
		for(int x=0; x<tileX; x++)
		{

			tileImage.create(tileSize, tileSize);
			tileImage.copy(tileset, 0, 0, sf::IntRect((x* tileSize), (y * tileSize), tileSize, tileSize), false);
			tileTexture.loadFromImage(tileImage, sf::IntRect());
			AddTexture(tileTexture, numtiles);
			numtiles++;
		}
	}
	

}

sf::Texture& TextureManager::GetTexture(int id){
	return textureList[textureIDs[id]];
}

