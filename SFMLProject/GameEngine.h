#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Player.h"
#include "Enemy.h"
#include "TextDisplay.h"
#include "Projectile.h"
#include "pickUp.h"
#include "Wall.h"
#include "Loader.h"
#include "Boss.h"
class GameEngine {
public:
	GameEngine();
	void run();
	//drawing things
	void draw(sf::RenderWindow *window, std::vector<Wall> *wallArray);
	void draw(sf::RenderWindow *window, std::vector<Enemy> *enemyArray);
	void draw(sf::RenderWindow *window, std::vector<Projectile> *projectileArray);
	void draw(sf::RenderWindow *window, std::vector<pickUp> *pickUpArray);
	void draw(sf::RenderWindow *window, Boss *boss, sf::Font font, sf::Clock *clock4, sf::Time *elapsedBoss, Projectile *projectile1, std::vector<Projectile> * projectileArray, sf::SoundBuffer fireballSound);
	//deleting things
	void del(sf::RenderWindow *window, std::vector<Enemy> *enemyArray, std::vector<pickUp> *pickUpArray, pickUp *pickUp1, Stage *stage, sf::Texture *questionTexture, sf::Texture *healPotionTexture, sf::Texture *powerupTexture);
	//storytelling
	void drawStoryScreen(sf::RenderWindow *window, sf::Sprite * sprite, sf::View *view1);
};

#endif