#include "pickUp.h"



pickUp::pickUp() {
	rect.setSize(sf::Vector2f(32.0f, 32.0f));
	rect.setFillColor(sf::Color::Yellow);
	rect.setPosition(0, 0);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void pickUp::update() {
	sprite.setPosition(rect.getPosition());
}
