#include "Enemy.h"

Enemy::Enemy() {
	rect.setSize(sf::Vector2f(64.0f, 64.0f));
	rect.setFillColor(sf::Color::White);
	rect.setPosition(400, 200);
	sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	text.setFillColor(sf::Color::Red);
}


void Enemy::update() {
	sprite.setPosition(rect.getPosition());
	text.setPosition(rect.getPosition().x, rect.getPosition().y - 32);
}

void Enemy::updateMovement() {
	//1 - left, 2 - right, 3 - up, 4 - down
	if (direction == 1) {
		if (canMoveLeft == true) {
			rect.move(-movementSpeed, 0);
			sprite.setTextureRect(sf::IntRect(cntWalking * 64, 0, 64, 64));
			canMoveLeft = true;
			canMoveRight = true;
			canMoveUp = true;
			canMoveDown = true;
		}
	}
	else if (direction == 2) {
		if (canMoveRight == true) {
			rect.move(movementSpeed, 0);
			sprite.setTextureRect(sf::IntRect(cntWalking * 64, 0, 64, 64));
			canMoveLeft = true;
			canMoveRight = true;
			canMoveUp = true;
			canMoveDown = true;
		}
	}
	else if (direction == 3) {
		if (canMoveUp == true) {
			rect.move(0, -movementSpeed);
			sprite.setTextureRect(sf::IntRect(cntWalking * 64, 0, 64, 64));
			canMoveLeft = true;
			canMoveRight = true;
			canMoveUp = true;
			canMoveDown = true;
		}
	}
	else if (direction == 4) {
		if (canMoveDown == true) {
			rect.move(0, movementSpeed);
			sprite.setTextureRect(sf::IntRect(cntWalking * 64, 0, 64, 64));
			canMoveLeft = true;
			canMoveRight = true;
			canMoveUp = true;
			canMoveDown = true;
		}
	}
	else {
		sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	}
	cntWalking++;
	if (cntWalking >= maxFrames) {
		cntWalking = 0;
	}
	counter++;
	if (counter >= movementLenght) {
		counter = 0;
		direction = generateRandom(4);
	}
}

