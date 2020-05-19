#ifndef PICKUP_H
#define PICKUP_H

#include "Entity.h"
class pickUp : public Entity {
public:
	bool isPartOfQuestion = false;
	bool isHealthPotion = false;
	bool isPowerup = false;
	bool destroy = false;
	int healthValue = 10;
	pickUp();
	void update();
	//void control();
};

#endif