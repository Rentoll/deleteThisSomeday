#include "Loader.h"

Loader::Loader() : inFile("world.txt") {
	if (inFile.is_open()) {
		std::string line;
		for (int i = 0; i < HEIGH; i++) {
			std::getline(inFile, line);
			for (int j = 0; j < line.length(); j++) {
				world[i][j] = line[j];
			}
		}
		inFile.close();
		
		for (int i = 0; i < WIDTH; i++) {
			for (int j = 0; j < HEIGH; j++) {
				std::cout << world[i][j];
			}
			std::cout << std::endl;
		}
		
	}
	else {
		std::cout << "CANT OPEN WORLD FILE!1!" << std::endl;
	}
}

void Loader::loadTexture(sf::Texture * texture, std::string path) {
	if (!texture->loadFromFile(path)) {
		 std::cout << "Cant load file from path: " << path << std::endl;
	}
}

void Loader::loadSound(sf::SoundBuffer * sound, std::string path) {
	if (!sound->loadFromFile(path)) {
		std::cout << "Cant load file from path: " << path << std::endl;
	}
}

void Loader::worldBuilder(std::vector<Wall> *wallArray, Wall * wall) {
	for (int i = 0; i < HEIGH; i++) {
		for (int j = 0; j < WIDTH; j++) {
			switch (world[i][j]) {
			case WALL:
				wall->destructable = false;
				wall->walkable = false;
				wall->teleport = false;
				wall->deck = false;
				wall->sprite.setTextureRect(sf::IntRect(128, 0, 64, 64));
				wall->rect.setPosition(j * 64, i * 64);
				wallArray->push_back(*wall);
				break;
			case TELEPORT:
				wall->destructable = false;
				wall->walkable = true;
				wall->teleport = true;
				wall->deck = false;
				wall->sprite.setTextureRect(sf::IntRect(64, 0, 64, 64));
				wall->rect.setPosition(j * 64, i * 64);
				wallArray->push_back(*wall);
				break;
			case FLOOR:
				wall->destructable = false;
				wall->walkable = true;
				wall->teleport = false;
				wall->deck = false;
				wall->sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
				wall->rect.setPosition(j * 64, i * 64);
				wallArray->push_back(*wall);
				break;
			case DECK:
				wall->destructable = false;
				wall->walkable = false;
				wall->teleport = false;
				wall->deck = true;
				wall->sprite.setTextureRect(sf::IntRect(196, 0, 64, 64));
				wall->rect.setPosition(j * 64, i * 64);
				wallArray->push_back(*wall);
				break;
			default:
				break;
			}
		}
	}

}

void Loader::enemyBuilderFirstLevel(std::vector<Enemy> *enemyArray, Enemy * enemy, Stage *stage, sf::Texture * zero, sf::Texture * one, sf::Texture * two) {
	stage->rooms[1] = generateRandom(1);
	stage->rooms[2] = generateRandom(3);
	stage->rooms[3] = generateRandom(5);
	for (int i = 0; i < stage->rooms[1]; i++) {
		switch (generateRandom0(3)) {
		case 0:
			enemy->sprite.setTexture(*zero);
			enemy->maxFrames = 4;
			break;
		case 1:
			enemy->sprite.setTexture(*one);
			enemy->maxFrames = 3;
			break;
		case 2:
			enemy->sprite.setTexture(*two);
			enemy->maxFrames = 3;
			break;
		default:
			break;
		}
		enemy->room = 1;
		enemy->attackDamage = 1;
		enemy->hp = 3;
		enemy->maxHp = 3;
		enemy->movementSpeed = 3;
		enemy->rect.setPosition(64*2 + 64*generateRandom(5), 64 * 2 + 64 * generateRandom(5));
		enemyArray->push_back(*enemy);
	}
	for (int i = 0; i < stage->rooms[2]; i++) {
		switch (generateRandom0(3)) {
		case 0:
			enemy->sprite.setTexture(*zero);
			enemy->maxFrames = 4;
			break;
		case 1:
			enemy->sprite.setTexture(*one);
			enemy->maxFrames = 3;
			break;
		case 2:
			enemy->sprite.setTexture(*two);
			enemy->maxFrames = 3;
			break;
		default:
			break;
		}
		enemy->room = 2;
		enemy->attackDamage = 2;
		enemy->hp = 4;
		enemy->maxHp = 4;
		enemy->movementSpeed = 4;
		enemy->rect.setPosition(64 * 2 + 64 * generateRandom(5), 64 * 12 + 64 * generateRandom(5));
		enemyArray->push_back(*enemy);
	}
	for (int i = 0; i < stage->rooms[3]; i++) {
		switch (generateRandom0(3)) {
		case 0:
			enemy->sprite.setTexture(*zero);
			enemy->maxFrames = 4;
			break;
		case 1:
			enemy->sprite.setTexture(*one);
			enemy->maxFrames = 3;
			break;
		case 2:
			enemy->sprite.setTexture(*two);
			enemy->maxFrames = 3;
			break;
		default:
			break;
		}
		enemy->room = 3;
		enemy->attackDamage = 3;
		enemy->hp = 5;
		enemy->maxHp = 5;
		enemy->movementSpeed = 5;
		enemy->rect.setPosition(64 * 2 + 64 * generateRandom(5), 64 * 22 + 64 * generateRandom(5));
		enemyArray->push_back(*enemy);
	}
}