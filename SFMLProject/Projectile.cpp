#include "Projectile.h"



Projectile::Projectile() {
	rect.setSize(sf::Vector2f(25.0f, 25.0f));
	rect.setFillColor(sf::Color::Green);
	rect.setPosition(0, 0);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void Projectile::update() {
	if (direction == 1) {
		rect.move(-movementSpeed, 0);
	}
	if (direction == 2) {
		rect.move(movementSpeed, 0);
	}
	if (direction == 3) {
		rect.move(0, -movementSpeed);
	}
	if (direction == 4) {
		rect.move(0, movementSpeed);
	}
	countLifetime++;
	if (countLifetime >= lifeTime) {
		destroy = true;
	}
	sprite.setTextureRect(sf::IntRect(animationCnt*32, 0, 32, 32));
	sprite.setPosition(rect.getPosition());
	animationCnt++;
	if (animationCnt >= 2) {
		animationCnt = 0;
	}
}

Projectile::~Projectile() {

}
