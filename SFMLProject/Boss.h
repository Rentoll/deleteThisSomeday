#ifndef  BOSS_H
#define BOSS_H

#include "Enemy.h"
#include "Projectile.h"
class Boss : public Enemy {
public:
	Boss() {
		Enemy();
		this->maxHp = 15;
		this->hp = 15;
		this->maxFrames = 2;
	}
	void shoot(std::vector <Projectile> *projectileArray, Projectile * projectile);
};

#endif 