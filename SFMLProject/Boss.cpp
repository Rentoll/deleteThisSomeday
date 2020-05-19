#include "Boss.h"

void Boss::shoot(std::vector <Projectile> *projectileArray, Projectile * projectile) {
	projectile->enemyProjectile = true;
	projectile->rect.setPosition(rect.getPosition());
	projectile->direction = 1;
	projectileArray->push_back(*projectile);

	projectile->rect.setPosition(rect.getPosition());
	projectile->direction = 2;
	projectileArray->push_back(*projectile);

	projectile->rect.setPosition(rect.getPosition());
	projectile->direction = 3;
	projectileArray->push_back(*projectile);

	projectile->rect.setPosition(rect.getPosition());
	projectile->direction = 4;
	projectileArray->push_back(*projectile);
	projectile->enemyProjectile = false;
}
