#include "Editor.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>

Editor::Editor(TextureManager& texturemanager)
{
	
	editorWindow = new sf::RenderWindow(sf::VideoMode(texturemanager.tilesetWidth, texturemanager.tilesetHeight, 32),"Tile Selector");
	
	tileX = texturemanager.tilesetWidth / texturemanager.getTileSize();
	tileY = texturemanager.tilesetHeight / texturemanager.getTileSize();

	int numtiles = 0;

	Redraw(texturemanager);
	editorWindow->draw(tileset);
	editorWindow->display();
}

Editor::~Editor()
{
	editorWindow->close();
	delete editorWindow;
}

void Editor::Redraw(TextureManager& texturemanager){

	int tileSize = texturemanager.getTileSize();
	tilemap.create((tileX * tileSize), (tileY * tileSize), false);
	tilemap.display();
	int tileCount = 0;
	for(int y = 0; y < tileY; y++)
	{
		for(int x = 0; x < tileX; x++)
		{
			tile = new Tile(texturemanager.GetTexture(tileCount));
			tile->Draw((x * tileSize), (y * tileSize), &tilemap);
			++tileCount;
		}
	}
	tileset.setTexture(tilemap.getTexture());
}