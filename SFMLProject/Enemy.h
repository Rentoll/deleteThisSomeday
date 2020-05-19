#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Random.h"

class Enemy : public Entity {
public:
	int movementSpeed = 1;
	int movementLenght = 100;
	int attackDamage = 5;
	int cntWalking = 0;
	int maxFrames = 4;
	int room;
	int direction = 0; //1 - left, 2 - right, 3 - up, 4 - down
	bool canMoveLeft = true,
		 canMoveRight = true,
		 canMoveUp = true,
		 canMoveDown = true;
	bool agro = false;
	int counter = 0;
	int maxHp = 3;
	int hp = 3;
	bool alive = true;

	Enemy();
	void update();
	void updateMovement();
	//void control();
};

#endif