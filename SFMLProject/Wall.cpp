#include "Wall.h"


Wall::Wall() {
	rect.setSize(sf::Vector2f(64.0f, 64.0f));
	rect.setFillColor(sf::Color::White);
	rect.setPosition(0, 0);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void Wall::update() {
	sprite.setPosition(rect.getPosition());
}
