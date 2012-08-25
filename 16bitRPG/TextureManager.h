#ifndef BITRPG_TEXTURE_MANAGER_H
#define BITRPG_TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class TextureManager{
private:
	vector<sf::Texture> textureList;

public:
	TextureManager();
	~TextureManager();

	void AddTexture(sf::Texture& texture);
	sf::Texture& GetTexture(int index);

};
#endif

