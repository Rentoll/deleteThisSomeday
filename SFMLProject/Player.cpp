#include "Player.h"



void Player::update() {
	sprite.setPosition(rect.getPosition());
}

void Player::control(sf::Time frameTime) {
	//1 - left, 2 - right, 3 - up, 4 - down
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (canMoveLeft) {
			direction = 1;
			rect.move(-movementSpeed, 0);
			sprite.setTextureRect(sf::IntRect(cntWalking * 32, 64, 32, 32));
			canMoveLeft = true;
			canMoveRight = true;
			canMoveUp = true;
			canMoveDown = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (canMoveRight) {
			direction = 2;
			rect.move(movementSpeed, 0);
			sprite.setTextureRect(sf::IntRect(cntWalking * 32, 32, 32, 32));
			canMoveLeft = true;
			canMoveRight = true;
			canMoveUp = true;
			canMoveDown = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (canMoveUp) {
			direction = 3;
			rect.move(0, -movementSpeed);
			sprite.setTextureRect(sf::IntRect(cntWalking * 32, 96, 32, 32));
			canMoveLeft = true;
			canMoveRight = true;
			canMoveUp = true;
			canMoveDown = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (canMoveDown) {
			direction = 4;
			rect.move(0, movementSpeed);
			sprite.setTextureRect(sf::IntRect(cntWalking * 32, 0, 32, 32));
			canMoveLeft = true;
			canMoveRight = true;
			canMoveUp = true;
			canMoveDown = true;
		}
	}
	else {

	}

	cntWalking++;
	if (cntWalking == 3) {
		cntWalking = 0;
	}
}

void Player::fireProjectile(std::vector <Projectile> *projectileArray, Projectile * projectile) {
	if (powerup == true) { //powerup attack
		projectile->rect.setPosition(rect.getPosition());
		projectile->direction = direction;
		projectileArray->push_back(*projectile);

		projectile->rect.setPosition(rect.getPosition().x + 50, rect.getPosition().y - 50);
		projectile->direction = direction;
		projectileArray->push_back(*projectile);

		projectile->rect.setPosition(rect.getPosition().x - 50, rect.getPosition().y + 50);
		projectile->direction = direction;
		projectileArray->push_back(*projectile);
	}
	else { //regular attack
		projectile->rect.setPosition(rect.getPosition());
		projectile->direction = direction;
		projectileArray->push_back(*projectile);
	}
}

Player::~Player()
{
}
