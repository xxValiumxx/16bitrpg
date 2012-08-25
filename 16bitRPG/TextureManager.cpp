#include "TextureManager.h"

TextureManager::TextureManager(){
}

TextureManager::~TextureManager(){
}

void TextureManager::AddTexture(sf::Texture& texture){
	textureList.push_back(texture);
}

sf::Texture& TextureManager::GetTexture(int index){
	return textureList[index];
}

