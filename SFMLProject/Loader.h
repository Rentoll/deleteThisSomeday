#ifndef LOADER_H
#define LOADER_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include "Wall.h"
#include "Random.h"
#include "Enemy.h"
#include "Player.h"
#include "Stage.h"


#define FLOOR    '.'
#define WALL     '1'
#define TELEPORT '2'
#define DECK     '3'
#define WIDTH    100
#define HEIGH    30

class Loader {
	char world[WIDTH][HEIGH];
	std::ifstream inFile;
public:
	Loader();
	void loadTexture(sf::Texture * texture, std::string path);
	void loadSound(sf::SoundBuffer * sound, std::string path);
	void worldBuilder(std::vector<Wall> *wallArray, Wall * wall);
	void enemyBuilderFirstLevel(std::vector<Enemy> *enemyArray, Enemy * enemy, Stage *stage, sf::Texture * zero, sf::Texture * one, sf::Texture * two);
};

#endif