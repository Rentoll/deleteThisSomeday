#ifndef ENTITY_H
#define ENTITY_H
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Entity {
public:
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;


	Entity();
	~Entity();
};

#endif