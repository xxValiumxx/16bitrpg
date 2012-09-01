#ifndef BITRPG_EDITOR_H
#define BITRPG_EDITOR_H
#include "Tile.h"
#include "TextureManager.h"

class Editor {

private:

	
	Tile* tile;
	
	int tileX;
	int tileY;
	void Editor::Redraw(TextureManager& texturemanager);

	sf::RenderTexture tilemap;
	sf::Sprite tileset;
public:
	Editor(TextureManager& texturemanager);
	~Editor();
	int selectedTile;
	sf::RenderWindow* editorWindow;
	bool editorHasFocus;


};

#endif