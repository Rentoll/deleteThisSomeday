#ifndef WALL_H
#define WALL_H

#include "Entity.h"
class Wall : public Entity {
public:
	bool destructable = false;
	bool walkable = false;
	bool destroy = false;
	bool teleport = false;
	bool deck = false;
	int hp = 1;
	Wall();
	void update();
};

#endif
