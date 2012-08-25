#include <SFML\Graphics.hpp>
#include <math.h>
#include "Camera.h"

Camera::Camera(int w, int h, float speed)
{
	size.x = w;
	size.y = h;

	if(speed < 0.0)
		speed = 0.0;
	if(speed > 1.0)
		speed = 1.0;

	this->speed = speed;
}

Camera::~Camera()
{

}

//Moves Camera to coords
void Camera::Move(int x, int y)
{
	position.x = (float)x;
	position.y = (float)y;
	target.x = (float)x;
	target.y = (float)y;
}

//Centers Camera at coords
void Camera::MoveCenter(int x, int y)
{
	x = x - (size.x / 2);
	y = y - (size.y / 2);

	position.x = (float)x;
	position.y = (float)y;
	target.x = (float)x;
	target.y = (float)y;
}

//Sets target to coords
void Camera::GoTo(int x, int y)
{
	target.x = (float)x;
	target.y = (float)y;
}

//Centers target at coords
void Camera::GoToCenter(int x, int y)
{
	x = x - (size.x	/ 2);
	y = y - (size.y / 2);

	target.x = (float)x;
	target.y = (float)y;
}

//Shits about to get REAL
//We're gonna make the camera move smooth
//to the target over time.
void Camera::Update()
{
	//X distance to target, Y distance to target, Euclidian distance
	float x, y, d;

	//Velocity magnatude
	float vx, vy, v;

	//Find x and y
	x = (float)(target.x - position.x);
	y = (float)(target.y - position.y);

	//If within 1 pixel, just snap
	//and stay there, otherwise continue
	if((x*x + y*y) <= 1)
	{
		position.x = target.x;
		position.y = target.y;
	}
	else
	{
		//SCARY MATH!
		d = sqrt((x*x + y*y));

		//Set velocity to 1/60th the distance to target
		//60 is arbitrary
		//this just means it runs every 6th of a second.
		//we also allow user to change with speed number
		v = (d * speed)/60;

		//Keep above 1 pixel per update, otherwise it may never get to
		//the target.  v is an absolute thats to the squaring of x
		//any earlier.
		if(v < 1.0f)
			v = 1.0f;

		//Similar triangles to get vx and vy
		vx = x * (v/d);
		vy = y * (v/d);

		//Now update camera position and we're done.
		position.x += vx;
		position.y += vy;
	}
}

sf::IntRect Camera::GetTileBounds(int tilesize)
{
	int x = (int)(position.x / tilesize);
	int y = (int)(position.y / tilesize);

	//+1 in case camera size isnt divisible by tilesize
	//And +1 again because those values start at 0, and 
	//we want them to start at one
	int w = (int)(size.x / tilesize + 2);
	int h = (int)(size.y / tilesize + 2);

	//+1 again if we're offset from the tile
	if(x % tilesize != 0)
		w++;
	if(h % tilesize != 0)
		h++;

	return sf::IntRect(x, y, w, h);
}
