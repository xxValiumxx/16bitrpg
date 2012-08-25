#include "Engine.h"
#include <SFML\Graphics.hpp>

Engine::Engine()
{

}

Engine::~Engine()
{
delete texturemanager;
delete window;
}

bool Engine::Init()
{
	texturemanager = new TextureManager();
	window = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "16bitRPG");

	if(!window)
		return false;

	LoadTextures();

	return true;
}

void Engine::LoadTextures()
{
	sf::Texture sprite;
	sprite.loadFromFile("grass.png");

	texturemanager->AddTexture(sprite);

	testTile = new Tile(texturemanager->GetTexture(0));
}

void Engine::RenderFrame()
{
	window->clear();
	testTile->Draw(0,0, window);
	window->display();
}

void Engine::ProcessInput()
{
	sf::Event evt;
	//Loop through all window events
	while(window->pollEvent(evt))
	{
		if(evt.type == sf::Event::Closed)
			window->close();
	}
}

void Engine::Update()
{

}

void Engine::MainLoop()
{
	//Loop until our window is closed
	while(window->isOpen())
	{
		ProcessInput();
		Update();
		RenderFrame();
	}
}

void Engine::Go()
{
	if(!Init())
		throw "Could not initialize Engine";

	MainLoop();
}