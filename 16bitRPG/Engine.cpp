#include "Engine.h"
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <stdio.h>
#include <iostream>



Engine::Engine(int width, int height)
{
	Init(width, height);
	edit = false;
}

Engine::~Engine()
{
	delete window;
}

bool Engine::Init(int width, int height)
{	
	font.loadFromFile("5x5.ttf");
	
	window = new sf::RenderWindow(sf::VideoMode(width, height, 32), "16bitRPG");
	view.reset(sf::FloatRect(0, 0, (0.5f * window->getSize().x * 1.f), (0.5f * window->getSize().y * 1.f)));
	view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	
	window->setFramerateLimit(0);
	window->setKeyRepeatEnabled(false);
	window->setVerticalSyncEnabled(false);

	texturemanager.setTileSize(16);
	texturemanager.LoadTileset("forest.png");
	
	currentLevel = new Level();
	currentLevel->LoadLevel("simplemap.png", texturemanager);
	text.setString("16bitRPG -- SFML 2.0RC");
	text.setFont(font);
	text.setPosition(5, (window->getSize().y * 0.95f));
	RedrawTerrain();
	engineHasFocus = true;
	return true;
}
void Engine::openEditor()
{
	edit=true;
	editor = new Editor(texturemanager);
}
void Engine::closeEditor()
{
	edit = false;
	delete editor;
}
void Engine::RenderFrame()
{
	
	
		window->clear();
		window->setView(view);

		window->draw(terrain);
		
		
		
		//window->draw(text);
		if(edit == true)
		{
			float viewX = view.getCenter().x - (view.getSize().x / 2);
			float viewY = view.getCenter().y - (view.getSize().y / 2);
			float viewX2 = view.getCenter().x + (view.getSize().x / 2);
			float viewY2 = view.getCenter().y + (view.getSize().y / 2);

			tile = new Tile(texturemanager.GetTexture(selectedTile));

			int windowx = (sf::Mouse::getPosition(* window).x);
			int windowy = (sf::Mouse::getPosition(* window).y);

			int mapX = mathMap( windowx, 0, (view.getViewport().width * window->getSize().x), viewX, viewX2) / texturemanager.getTileSize();
			int mapY = mathMap( windowy, 0, (view.getViewport().height * window->getSize().y), viewY, viewY2) / texturemanager.getTileSize();

			if((mapX < currentLevel->GetWidth()) && (mapY < currentLevel->GetHeight()) && (mapX >= 0) && (mapY >= 0))
				tile->DrawWindow((mapX * texturemanager.getTileSize()), (mapY * texturemanager.getTileSize()), window);
		}
		window->setView(window->getDefaultView());
		window->display();
	
}
void Engine::RedrawTerrain()
{
	int tileSize = texturemanager.getTileSize();
	levelmap.create((currentLevel->GetWidth() * tileSize), (currentLevel->GetHeight() * tileSize), false);
	levelmap.display();
	for(int y = 0; y < currentLevel->GetHeight(); y++)
	{
		for(int x = 0; x < currentLevel->GetWidth(); x++)
		{
			tile = currentLevel->GetTile(x, y);
			tile->Draw((x * tileSize), (y * tileSize), &levelmap);
		}
	}
	terrain.setTexture(levelmap.getTexture());
}
void Engine::ProcessInput()
{
		//Loop through all window events
		while(window->pollEvent(evt, false))
		{
			switch(evt.type)
			{
			case sf::Event::Closed:
				{
					window->close();
					break;
				}
			case sf::Event::MouseWheelMoved:
				{
					view.zoom(evt.mouseWheel.delta > 0 ? 0.95f : 1.05f);
					break;
				}
			case sf::Event::GainedFocus:
				{
					engineHasFocus = true;
					break;
				}
			case sf::Event::LostFocus:
				{
					engineHasFocus = false;
					break;
				}
			default:
				{
					//nothing
					break;
				}
			}
		}
		if(edit)
		{
			while(editor->editorWindow->pollEvent(evt, false))
			{
				switch (evt.type)
				{
				case sf::Event::Closed:
					{
						closeEditor();
						break;
					}
				case sf::Event::GainedFocus:
					{
						editor->editorHasFocus = true;
						break;
					}
				case sf::Event::LostFocus:
					{
						editor->editorHasFocus = false;
						break;
					}
				default:
					{
						//nothing
						break;
					}
				}
				if(!edit) break;
			}
			if(editor->editorHasFocus)
			{
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Delete) && edit == true)
				{
					closeEditor();
				}
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					int windowx = (sf::Mouse::getPosition(* editor->editorWindow).x) / texturemanager.getTileSize();
					int windowy = (sf::Mouse::getPosition(* editor->editorWindow).y) / texturemanager.getTileSize();
					
					selectedTile = windowx +(windowy * texturemanager.tilesetWidth / texturemanager.getTileSize());
					
										
				}
			}
		}
		
		if(engineHasFocus)
		{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				view.move( 1.0f, 0.0f );
			
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				view.move( -1.0f, 0.0f );
			
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				view.move( 0.0f, -1.0f );
			
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				view.move( 0.0f, 1.0f );
			
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp))
				view.zoom( 1.01f );

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown))
				view.zoom( 0.99f );

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Home))
				view.rotate( 1.f );

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::End))
				view.rotate( -1.f );
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::F10))
			{
				while(sf::Keyboard::isKeyPressed(sf::Keyboard::F10))
				{
					//Nothing really, just lock up :P
				}
				sf::Texture savetex(levelmap.getTexture());
				sf::Image saveme(savetex.copyToImage());
				saveme.saveToFile("snapshot.png");
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Insert) && edit == false)
			{
				openEditor();
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Delete) && edit == true)
			{
				closeEditor();
			}
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if(edit == true)
				{
					float viewX = view.getCenter().x - (view.getSize().x / 2);
					float viewY = view.getCenter().y - (view.getSize().y / 2);
					float viewX2 = view.getCenter().x + (view.getSize().x / 2);
					float viewY2 = view.getCenter().y + (view.getSize().y / 2);

					tile = new Tile(texturemanager.GetTexture(selectedTile));

					int windowx = (sf::Mouse::getPosition(* window).x);
					int windowy = (sf::Mouse::getPosition(* window).y);
					
					int mapX = mathMap( windowx, 0, (view.getViewport().width * window->getSize().x), viewX, viewX2) / texturemanager.getTileSize();
					int mapY = mathMap( windowy, 0, (view.getViewport().height * window->getSize().y), viewY, viewY2) / texturemanager.getTileSize();
					
					if((mapX < currentLevel->GetWidth()) && (mapY < currentLevel->GetHeight()) && (mapX >= 0) && (mapY >= 0))
						currentLevel->AddTile(mapX, mapY, tile);
					RedrawTerrain();
				}
			}
		}
}
float Engine::mathMap(int x, int in_min, int in_max, float out_min, float out_max)
{
	return (float)((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}
void Engine::Update()
{
//nothing yet
	
}

void Engine::MainLoop()
{
	
	//Loop until our window is closed
	while(window->isOpen())
	{
		ProcessInput();
		
		//Update();
		RenderFrame();
		
		
	}
}

void Engine::Go()
{
	MainLoop();
}
