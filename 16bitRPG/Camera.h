#ifndef BITRPG_CAMERA_H
#define BITRPG_CAMERA_H

#include <SFML\Graphics.hpp>
#include "Tile.h"

class Camera
{
private:
	//Absolute position of camera in pixels from origin
	sf::Vector2f position;

	//Target position camera is moving towards
	sf::Vector2f target;

	//Size of camera
	sf::Vector2i size;
	
	//Speed of camera, 0 - 1
	float speed;

public:
	Camera(int w, int h, float speed);
	~Camera();

	//Move camera to coords
	void Move(int x, int y);
	void MoveCenter(int x, int y);

	//Sets Camera target
	void GoTo(int x, int y);
	void GoToCenter(int x, int y);

	//Update camera position
	void Update();

	sf::Vector2i GetPosition() { return sf::Vector2i((int)position.x, (int)position.y);}

	//Helper function for retrieving camera's offset from nearest tile
	sf::Vector2i GetTileOffset(int tilesize) { return sf::Vector2i((int)(position.x) % tilesize, (int)(position.y) % tilesize); }
	
	//Helper function for retrieving a rectangle defining what tiles are visible
	sf::IntRect GetTileBounds(int tilesize);
};


#endif