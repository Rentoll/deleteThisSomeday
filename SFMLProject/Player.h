#ifndef PLAYER_H
#define PLAYER_H

#include "Projectile.h"
class Player : public Entity {
public:
	int hp = 30;
	int maxHp = 30;
	int level = 1;
	int movementSpeed = 10;
	int attackDamage = 5;
	bool powerup = false;
	float currentFrame = 0;
	int cntWalking = 0;
	float speed = 80.0f;
	int direction = 0; //1 - left, 2 - right, 3 - up, 4 - down
	int numOfQuestions = 0;

	bool canMoveLeft = true, 
		 canMoveRight = true, 
		 canMoveUp = true, 
		 canMoveDown = true;

	Player() {
		rect.setSize(sf::Vector2f(32.0f, 32.0f));
		rect.setFillColor(sf::Color::White);
		rect.setPosition(400, 200);
		sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	};
	void update();
	void control(sf::Time frameTime);
	void fireProjectile(std::vector <Projectile> *projectileArray, Projectile * projectile);
	~Player();
};

#endif
