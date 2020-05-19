#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Entity.h"
class Projectile : public Entity {
public:
	int movementSpeed = 10;
	int attackDamage = 1;
	int direction = 0; //1 - left, 2 - right, 3 - up, 4 - down
	bool destroy = false;
	bool enemyProjectile = false;
	int countLifetime = 0;
	int animationCnt = 0;
	int lifeTime = 100;

	Projectile();
	void update();
	//void control();
	~Projectile();
};

#endif