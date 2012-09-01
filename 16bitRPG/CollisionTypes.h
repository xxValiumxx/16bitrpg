enum CollisionType
{
	COLISION_NONE		=0x00,
	COLLISION_NORTH		= 0x01,
	COLLISION_EAST		= 0x02,
	COLLISION_SOUTH		= 0x04,
	COLLISION_WEST		= 0x08,
	COLLISION_PUSH_NORTH = 0x10,
	COLLISION_PUSH_EAST	= 0x20,
	COLLISION_PUSH_SOUTH = 0x40,
	COLLISION_PUSH_WEST	= 0x80
};