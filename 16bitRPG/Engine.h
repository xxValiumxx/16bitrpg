#ifndef BITRPG_ENGINE_H
#define BITRPG_ENGINE_H

#include <SFML\Graphics.hpp>

#include "TextureManager.h"
#include "Tile.h"
#include "Level.h"
#include "Editor.h"

class Engine
{
private:
	sf::Font font;
	//SFML Render Window
	sf::RenderWindow* window;
	sf::View view;
	Editor* editor;
	TextureManager texturemanager;
	Level* currentLevel;
	//Initializes the engine
	bool Init(int width, int height);				
	//Main Game Loop
	void MainLoop();			
	;
	//Updates all Engine internals
	void Update();
	void openEditor();
	void closeEditor();
	//Temporary
	Tile* tile;
	void Engine::LoadLevelFromImage(const char* filename);
	void LoadTextures();
	void LoadLevel();
	void saveMap();
	void RedrawTerrain();
	sf::RenderTexture levelmap;
	sf::Sprite terrain;
	sf::Text text;
	sf::Event evt;
	int selectedTile;
public:
	Engine(int width, int height);
	~Engine();
	bool edit;
	bool engineHasFocus;
	void Go();					//Starts the engine
	//Renders one frame
	void RenderFrame();
	//Processes user input
	void ProcessInput();
	float Engine::mathMap(int x, int in_min, int in_max, float out_min, float out_max);
};

#endif