#ifndef BITRPG_ENGINE_H
#define BITRPG_ENGINE_H

#include <SFML\Graphics.hpp>

#include "TextureManager.h"
#include "Tile.h"

class Engine
{
private:
	//SFML Render Window
	sf::RenderWindow* window;
	TextureManager* texturemanager;

	//Initializes the engine
	bool Init();				
	//Main Game Loop
	void MainLoop();			
	//Renders one frame
	void RenderFrame();
	//Processes user input
	void ProcessInput();
	//Updates all Engine internals
	void Update();

	//Temporary
	Tile* testTile;
	void LoadTextures();
public:
	Engine();
	~Engine();

	void Go();					//Starts the engine
};

#endif