#include "GameEngine.h"

GameEngine::GameEngine() {}

void GameEngine::run() {
	//variables
	srand(time(NULL));
	float playerSpeed = 2;
	int cntWalking = 0;
	int counter1 = 0;
	int counter2 = 0;
	int counter3 = 0;
	sf::Clock clock1;
	sf::Clock clock2;
	sf::Clock clock3;
	sf::Clock clock4;
	float speed = 80.0f;

	//window init
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Calculus of Death(CoD)", sf::Style::Close);
	window.setFramerateLimit(60);

	//View
	sf::View view1(sf::FloatRect(200, 200, 300, 200));
	view1.setSize(sf::Vector2f(window.getSize().x/2, window.getSize().y/2));
	view1.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
	window.setView(view1);

	//font init
	sf::Font font;
	font.loadFromFile("Fonts/CyrilicOld.TTF");
	//player init
	Player player1;
	sf::Texture playerTexture;
	sf::Texture angryZero;
	sf::Texture angryOne;
	sf::Texture angryTwo;
	sf::Texture healPotionTexture;
	sf::Texture questionTexture;
	sf::Texture powerupTexture;
	sf::Texture fireballTexture;
	sf::Texture worldTilesetTexture;
	sf::Texture firstQuestion;
	sf::Texture bossTexture;
	sf::Texture welcomeScreen;
	sf::Texture winningScreen;
	sf::Texture loosingScreen;

	Loader loader;
	loader.loadTexture(&playerTexture, "Images/Player.png");
	loader.loadTexture(&angryZero, "Images/angryZero.png");
	loader.loadTexture(&angryOne, "Images/angryOne.png");
	loader.loadTexture(&angryTwo, "Images/angryTwo.png");
	loader.loadTexture(&healPotionTexture, "Images/healPotion.png");
	loader.loadTexture(&powerupTexture, "Images/PiPowerUp.png");
	loader.loadTexture(&questionTexture, "Images/question.png");
	loader.loadTexture(&fireballTexture, "Images/fireball.png");
	loader.loadTexture(&worldTilesetTexture, "Images/WorldTileset2.png");
	loader.loadTexture(&firstQuestion, "Images/firstQuestion.png");
	loader.loadTexture(&welcomeScreen, "Images/welcomeScreen.png");
	loader.loadTexture(&winningScreen, "Images/winningScreen.png");
	loader.loadTexture(&loosingScreen, "Images/loosingScreen.png");
	loader.loadTexture(&bossTexture, "Images/firstBoss.png");

	//wall vector array
	std::vector<Wall>::const_iterator iterWall;
	std::vector<Wall> wallArray;
	Wall wall1;
	wall1.sprite.setTexture(worldTilesetTexture);
	loader.worldBuilder(&wallArray, &wall1);

	player1.sprite.setTexture(playerTexture);

	//////
	sf::Sprite questionSprite;
	questionSprite.setTexture(firstQuestion);
	questionSprite.setPosition(0,0);

	sf::Sprite welcomeScreenSprite;
	welcomeScreenSprite.setTexture(welcomeScreen);
	welcomeScreenSprite.setPosition(0, 0);

	sf::Sprite winningScreenSprite;
	winningScreenSprite.setTexture(winningScreen);
	winningScreenSprite.setPosition(0, 0);

	sf::Sprite loosingScreenSprite;
	loosingScreenSprite.setTexture(loosingScreen);
	loosingScreenSprite.setPosition(0, 0);
	//////
	drawStoryScreen(&window, &welcomeScreenSprite, &view1);
	Boss boss;

	//enemy vector array
	std::vector<Enemy>::const_iterator iter4;
	std::vector<Enemy> enemyArray;
	Enemy enemy1;

	enemy1.text.setFont(font);
	enemy1.text.setCharacterSize(17);

	Stage stage;

	switch (player1.level) {
	case 1:
		enemy1.sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
		//enemy1.sprite.setTexture(angryZero);
		loader.enemyBuilderFirstLevel(&enemyArray, &enemy1, &stage, &angryZero, &angryOne, &angryTwo);
		boss.sprite.setTexture(bossTexture);
		boss.rect.setPosition(1000, 1000);
		break;
	default:
		break;
	}

	//
	bool question = true;
	sf::Event event2;
	sf::String playerInput;
	sf::Text playerText("", font, 25);
	//

	//projectile vector array
	std::vector<Projectile>::const_iterator iter;
	std::vector<Projectile> projectileArray;
	Projectile projectile1;
	projectile1.sprite.setTexture(fireballTexture);

	//heal potion vector array
	std::vector<pickUp>::const_iterator iterPickUp;
	std::vector<pickUp> pickUpArray;
	pickUp pickUp1;
	pickUp1.isHealthPotion = true;
	pickUp1.isPowerup = false;
	pickUp1.sprite.setTexture(healPotionTexture);
	pickUp1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

	//text vector array
	std::vector<TextDisplay>::const_iterator iterText;
	std::vector<TextDisplay> textArray;
	TextDisplay textDisplay1;
	textDisplay1.text.setFont(font);
	textDisplay1.text.setPosition(300, 300);
	//health
	sf::Text text("Health:", font, 25);
	text.setFillColor(sf::Color::Black);
	text.setPosition(0, 0);

	sf::Text numOfQuestions("Number of collected lists:", font, 25);
	numOfQuestions.setFillColor(sf::Color::Black);
	numOfQuestions.setPosition(0, 50);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
		}
		window.clear(sf::Color::White);

		sf::Time elapsed1 = clock1.getElapsedTime();
		sf::Time elapsed2 = clock2.getElapsedTime();
		sf::Time elapsed3 = clock3.getElapsedTime();
		sf::Time elapsedBoss = clock4.getElapsedTime();

		//player collides with wall
		counter1 = 0;
		for (iterWall = wallArray.begin(); iterWall != wallArray.end(); iterWall++) {
			if (wallArray[counter1].walkable == false && player1.rect.getGlobalBounds().intersects(wallArray[counter1].rect.getGlobalBounds())) {
				//hit wall
				//1 - left, 2 - right, 3 - up, 4 - down
				if (player1.direction == 1) {
					player1.canMoveLeft = false;
					player1.rect.move(1, 0);
				}
				else if (player1.direction == 2) {
					player1.canMoveRight = false;
					player1.rect.move(-1, 0);
				}
				else if (player1.direction == 3) {
					player1.canMoveUp = false;
					player1.rect.move(0, 1);
				}
				else if (player1.direction == 4) {
					player1.canMoveDown = false;
					player1.rect.move(0, -1);
				}
				else {

				}
				if (wallArray[counter1].deck == true && player1.numOfQuestions >= 3) {
					questionSprite.setPosition(window.getPosition().x, window.getPosition().y);
					playerText.setPosition(view1.getCenter().x + 100, view1.getCenter().y - 20);
					question = true;
					playerInput = "";
					playerText.setString(playerInput);
					playerText.setFillColor(sf::Color::Black);
					questionSprite.setPosition(view1.getCenter().x-250, view1.getCenter().y-200);
					while (question == true) {
						while (window.pollEvent(event2)) {
							if (event2.key.code == sf::Keyboard::Q) {
								question = false;
								player1.rect.move(-5,0);
								break;
							}
							if (event2.type == sf::Event::TextEntered) {
								if (event2.text.unicode == '\b') {
									playerInput = playerInput.substring(0, playerInput.getSize());
								}
								else {
									playerInput += event2.text.unicode;
									playerText.setString(playerInput);
								}
							}
						}					
						if (playerInput == "0.25") {
							question = false;
							//boss.agro = true;
							boss.rect.setPosition(1000, 1000);
							wallArray[counter1].deck = false;
							wallArray[counter1].walkable = true;
							break;
						}
						window.clear();
						window.draw(questionSprite);
						window.draw(playerText);
						window.display();
					}
				}
			}
			counter1++;
		}
		//Enemy collides with wall
		counter1 = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
			counter2 = 0;
			for (iterWall = wallArray.begin(); iterWall != wallArray.end(); iterWall++) {
				if (enemyArray[counter1].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds())) {
					if (wallArray[counter2].walkable == false || wallArray[counter2].teleport == true) {
						if (enemyArray[counter1].direction == 1) {
							enemyArray[counter1].canMoveLeft = false;
							enemyArray[counter1].rect.move(1, 0);
						}
						else if (enemyArray[counter1].direction == 2) {
							enemyArray[counter1].canMoveRight = false;
							enemyArray[counter1].rect.move(-1, 0);
						}
						else if (enemyArray[counter1].direction == 3) {
							enemyArray[counter1].canMoveUp = false;
							enemyArray[counter1].rect.move(0, 1);
						}
						else if (enemyArray[counter1].direction == 4) {
							enemyArray[counter1].canMoveDown = false;
							enemyArray[counter1].rect.move(0, -1);
						}
						else {

						}
					}
				}
				counter2++;
			}
			counter1++;
		}

		
		counter2 = 0;
		for (iterWall = wallArray.begin(); iterWall != wallArray.end(); iterWall++) {
			if (boss.rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds())) {
				if (wallArray[counter2].walkable == false || wallArray[counter2].teleport == true) {
					if (boss.direction == 1) {
						boss.canMoveLeft = false;
						boss.rect.move(1, 0);
					}
					else if (boss.direction == 2) {
						boss.canMoveRight = false;
						boss.rect.move(-1, 0);
					}
					else if (boss.direction == 3) {
						boss.canMoveUp = false;
						boss.rect.move(0, 1);
					}
					else if (boss.direction == 4) {
						boss.canMoveDown = false;
						boss.rect.move(0, -1);
					}
					else {

					}
				}
			}
			counter2++;
		}

		//player collides with pick up item
		counter1 = 0;
		for (iterPickUp = pickUpArray.begin(); iterPickUp != pickUpArray.end(); iterPickUp++) {
			if (player1.rect.getGlobalBounds().intersects(pickUpArray[counter1].rect.getGlobalBounds())) {
				if (pickUpArray[counter1].isHealthPotion) {
					if (player1.hp + pickUpArray[counter1].healthValue <= player1.maxHp) {
						player1.hp += pickUpArray[counter1].healthValue;
					}
					else {
						player1.hp = player1.maxHp;
					}
				}
				if (pickUpArray[counter1].isPowerup) {
					player1.powerup = true;
				}
				if (pickUpArray[counter1].isPartOfQuestion) {
					player1.numOfQuestions++;
				}
				pickUpArray[counter1].destroy = true;
			}
			counter1++;
		}

		// Enemy collides with player(Player damage)
		if (elapsed2.asSeconds() >= 0.5f) {
			clock2.restart();
			counter1 = 0;
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
				if (player1.rect.getGlobalBounds().intersects(enemyArray[counter1].rect.getGlobalBounds())) {
					textDisplay1.text.setString(std::to_string(enemyArray[counter1].attackDamage));
					textDisplay1.text.setPosition(player1.rect.getPosition().x, player1.rect.getPosition().y);
					textArray.push_back(textDisplay1);
					player1.hp -= enemyArray[counter1].attackDamage;
					player1.powerup = false;
				}
				if (player1.rect.getGlobalBounds().intersects(boss.rect.getGlobalBounds())) {
					textDisplay1.text.setString(std::to_string(boss.attackDamage));
					textDisplay1.text.setPosition(player1.rect.getPosition().x, player1.rect.getPosition().y);
					textArray.push_back(textDisplay1);
					player1.hp -= boss.attackDamage;
					player1.powerup = false;
				}
				if (player1.hp <= 0) {
					drawStoryScreen(&window, &loosingScreenSprite, &view1);
					exit(0);
				}
				counter1++;
			}
		}

		//projectile collision with wall
		counter1 = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++) {
			counter2 = 0;
			for (iterWall = wallArray.begin(); iterWall != wallArray.end(); iterWall++) {
				if (projectileArray[counter1].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds())) {
					if (wallArray[counter2].walkable == false) {
						projectileArray[counter1].destroy = true;
						if (wallArray[counter2].destructable) {
							wallArray[counter2].hp -= projectileArray[counter1].attackDamage;
							if (wallArray[counter2].hp <= 0) {
								wallArray[counter2].destroy = true;
							}
						}
					}
				}
				counter2++;
			}
			counter1++;
		}

		//agro enemy

		counter1 = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
			if (enemyArray[counter1].agro == true) {
					int tmp = generateRandom(2);
					if ( player1.rect.getPosition().y + 1 < enemyArray[counter1].rect.getPosition().y) {
						enemyArray[counter1].counter = 0;
						enemyArray[counter1].direction = 3;
					}
					else if (player1.rect.getPosition().y - 1 > enemyArray[counter1].rect.getPosition().y) {
						enemyArray[counter1].counter = 0;
						enemyArray[counter1].direction = 4;
					}
					else if (player1.rect.getPosition().x <= enemyArray[counter1].rect.getPosition().x) {
						enemyArray[counter1].counter = 0;
						enemyArray[counter1].direction = 1;
					}
					else if (player1.rect.getPosition().x >= enemyArray[counter1].rect.getPosition().x) {
						enemyArray[counter1].counter = 0;
						enemyArray[counter1].direction = 2;
					}
				}
			counter1++;
		}

		if (boss.agro == true) {
			int tmp = generateRandom(2);
			if (player1.rect.getPosition().y + 1 < boss.rect.getPosition().y) {
				boss.counter = 0;
				boss.direction = 3;
			}
			else if (player1.rect.getPosition().y - 1 > boss.rect.getPosition().y) {
				boss.counter = 0;
				boss.direction = 4;
			}
			else if (player1.rect.getPosition().x <= boss.rect.getPosition().x) {
				boss.counter = 0;
				boss.direction = 1;
			}
			else if (player1.rect.getPosition().x >= boss.rect.getPosition().x) {
				boss.counter = 0;
				boss.direction = 2;
			}
		}

		//projectile collision
		counter1 = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++) {
			counter2 = 0;
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
				if (projectileArray[counter1].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()) && projectileArray[counter1].enemyProjectile == false) {
					projectileArray[counter1].destroy = true;

					//text display
					textDisplay1.text.setString(std::to_string(projectileArray[counter1].attackDamage));
					textDisplay1.text.setPosition(enemyArray[counter2].rect.getPosition().x, enemyArray[counter2].rect.getPosition().y);
					textArray.push_back(textDisplay1);

					//std::cout << "collision\n";
					enemyArray[counter2].hp -= projectileArray[counter1].attackDamage;
					enemyArray[counter2].agro = true;
				}
				if (enemyArray[counter2].hp <= 0) {
					enemyArray[counter2].alive = false;
				}

				if (projectileArray[counter1].rect.getGlobalBounds().intersects(boss.rect.getGlobalBounds()) && projectileArray[counter1].enemyProjectile == false) {
					projectileArray[counter1].destroy = true;

					//text display
					textDisplay1.text.setString(std::to_string(projectileArray[counter1].attackDamage));
					textDisplay1.text.setPosition(boss.rect.getPosition().x, boss.rect.getPosition().y);
					textArray.push_back(textDisplay1);

					//std::cout << "collision\n";
					boss.hp -= projectileArray[counter1].attackDamage;
					boss.agro = true;
				}
				if (boss.hp <= 0) {
					boss.alive = false;
					drawStoryScreen(&window, &winningScreenSprite, &view1);
					exit(0);
				}
				counter2++;
			}
			
			if (projectileArray[counter1].rect.getGlobalBounds().intersects(player1.rect.getGlobalBounds()) && projectileArray[counter1].enemyProjectile == true) {
				projectileArray[counter1].destroy = true;

				//text display
				textDisplay1.text.setString(std::to_string(projectileArray[counter1].attackDamage));
				textDisplay1.text.setPosition(player1.rect.getPosition().x, player1.rect.getPosition().y);
				textArray.push_back(textDisplay1);

				//std::cout << "collision\n";
				player1.hp -= projectileArray[counter1].attackDamage;
			}
			counter1++;
		}
		//delete dead enemy
		del(&window, &enemyArray, &pickUpArray, &pickUp1, &stage, &questionTexture, &healPotionTexture, &powerupTexture);

		//delete dead projectiles
		counter1 = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++) {
			if (projectileArray[counter1].destroy) {
				projectileArray.erase(iter);
				break;
			}
			counter1++;
		}
		//delete text
		counter1 = 0;
		for (iterText = textArray.begin(); iterText != textArray.end(); iterText++) {
			if (textArray[counter1].destroy) {
				textArray.erase(iterText);
				break;
			}
			counter1++;
		}
		//delete puckups
		counter1 = 0;
		for (iterPickUp = pickUpArray.begin(); iterPickUp != pickUpArray.end(); iterPickUp++) {
			if (pickUpArray[counter1].destroy) {
				pickUpArray.erase(iterPickUp);
				break;
			}
			counter1++;
		}

		//delete wall
		counter1 = 0;
		for (iterWall = wallArray.begin(); iterWall != wallArray.end(); iterWall++) {
			if (wallArray[counter1].destroy == true) {
				if (generateRandom(4) == 1) {
					pickUp1.isHealthPotion = true;
					pickUp1.isPowerup = false;
					pickUp1.sprite.setTexture(healPotionTexture);
					pickUp1.rect.setPosition(wallArray[counter1].rect.getPosition());
					pickUpArray.push_back(pickUp1);
				}
				if (generateRandom(4) == 1) {
					pickUp1.isPowerup = true;
					pickUp1.isHealthPotion = false;
					pickUp1.sprite.setTexture(powerupTexture);
					pickUp1.rect.setPosition(wallArray[counter1].rect.getPosition());
					pickUpArray.push_back(pickUp1);
				}
				wallArray.erase(iterWall);
				break;
			}
			counter1++;
		}

		//fire projectiles

		if (elapsed1.asSeconds() >= 0.5f) {
			clock1.restart();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				player1.fireProjectile(&projectileArray, &projectile1);
			}
		}
		//draw walls
		draw(&window, &wallArray);

		//draw boss
		draw(&window, &boss, font, &clock4, &elapsedBoss, &projectile1, &projectileArray);

		//draw pick up items
		draw(&window, &pickUpArray);

		//draw projectiles
		draw(&window, &projectileArray);

		//draw enemies
		draw(&window, &enemyArray);

		//health display
		text.setString("Health:" + std::to_string(player1.hp));
		window.draw(text);
		text.setPosition(player1.rect.getPosition().x - window.getSize().x / 4, player1.rect.getPosition().y - window.getSize().y / 4);

		numOfQuestions.setString("Number of collected lists:" + std::to_string(player1.numOfQuestions));
		window.draw(numOfQuestions);
		numOfQuestions.setPosition(player1.rect.getPosition().x - window.getSize().x / 4, player1.rect.getPosition().y - window.getSize().y / 4 + 50);

		player1.update();
		sf::Time frameTime = clock3.restart(); 
		player1.control(frameTime);

		//player view
		window.setView(view1);
		view1.setCenter(player1.rect.getPosition());

		//draw player
		window.draw(player1.sprite);
		//draw text
		counter1 = 0;
		for (iterText = textArray.begin(); iterText != textArray.end(); iterText++) {
			textArray[counter1].update();
			window.draw(textArray[counter1].text);
			counter1++;
		}

		//window.draw(questionSprite);

		window.display();
	}
}

void GameEngine::drawStoryScreen(sf::RenderWindow *window, sf::Sprite * sprite, sf::View *view1) {
	sf::Event evnt;
	bool flag = true;
	sprite->setPosition(view1->getCenter().x - 250, view1->getCenter().y - 200);
	while (flag == true) {
		while (window->pollEvent(evnt)) {
			if (evnt.key.code == sf::Keyboard::Space) {
				flag = false;
				break;
			}
		}
		window->clear();
		window->draw(*sprite);
		window->display();
	}
}

void GameEngine::draw(sf::RenderWindow *window, std::vector<Enemy> *enemyArray) {
	int counter1 = 0;
	std::vector<Enemy>::const_iterator iterEnemy;
	for (iterEnemy = enemyArray->begin(); iterEnemy != enemyArray->end(); iterEnemy++) {
		enemyArray->at(counter1).text.setString("HP " + std::to_string(enemyArray->at(counter1).hp) + "/" + std::to_string(enemyArray->at(counter1).maxHp));
		window->draw(enemyArray->at(counter1).text);
		enemyArray->at(counter1).update();
		enemyArray->at(counter1).updateMovement();
		//window.draw(enemyArray[counter1].rect);
		window->draw(enemyArray->at(counter1).sprite);
		counter1++;
	}
}

void GameEngine::draw(sf::RenderWindow *window, std::vector<Projectile> *projectileArray) {
	std::vector<Projectile>::const_iterator iterProjectile;
	int counter1 = 0;
	for (iterProjectile = projectileArray->begin(); iterProjectile != projectileArray->end(); iterProjectile++) {
		projectileArray->at(counter1).update();
		//window.draw(projectileArray[counter1].rect);
		window->draw(projectileArray->at(counter1).sprite);
		counter1++;
	}
}

void GameEngine::draw(sf::RenderWindow *window, std::vector<Wall> *wallArray) {
	std::vector<Wall>::const_iterator iterWall;
	int counter = 0;
	for (iterWall = wallArray->begin(); iterWall != wallArray->end(); iterWall++) {
		wallArray->at(counter).update();
		//window.draw(wallArray[counter1].rect);
		window->draw(wallArray->at(counter).sprite);
		counter++;
	}
}

void GameEngine::draw(sf::RenderWindow *window, std::vector<pickUp> *pickUpArray) {
	std::vector<pickUp>::const_iterator iterPickUp;
	int counter = 0;
	for (iterPickUp = pickUpArray->begin(); iterPickUp != pickUpArray->end(); iterPickUp++) {
		pickUpArray->at(counter).update();
		//window.draw(wallArray[counter1].rect);
		window->draw(pickUpArray->at(counter).sprite);
		counter++;
	}
}

void GameEngine::draw(sf::RenderWindow *window, Boss *boss, sf::Font font, sf::Clock *clock4, sf::Time *elapsedBoss, Projectile *projectile1, std::vector<Projectile> * projectileArray) {
	sf::Text bossHP;
	bossHP.setFont(font);
	std::string buf = "[";
	//std::cout << "Enemy:" << boss->hp << std::endl;
	buf = "[";
	bossHP.setFillColor(sf::Color::Magenta);
	int i;
	for (i = 0; i < boss->hp; i++) {
		buf += "#";
	}
	for (; i < boss->maxHp; i++) {
		buf += "_";
	}
	buf += "]";
	bossHP.setString(buf);
	bossHP.setPosition(boss->rect.getPosition().x, boss->rect.getPosition().y - 75);
	window->draw(bossHP);
	//boss drawing
	boss->update();
	boss->updateMovement();
	window->draw(boss->sprite);
	if (elapsedBoss->asSeconds() >= 5.0f) {
		clock4->restart();
		boss->shoot(projectileArray, projectile1);
	}
}

void GameEngine::del(sf::RenderWindow *window, std::vector<Enemy> *enemyArray, std::vector<pickUp> *pickUpArray, pickUp *pickUp1, Stage *stage, sf::Texture *questionTexture, sf::Texture *healPotionTexture, sf::Texture *powerupTexture) {
	std::vector<Enemy>::const_iterator iterEnemy;
	int counter1 = 0;
	for (iterEnemy = enemyArray->begin(); iterEnemy != enemyArray->end(); iterEnemy++) {
		if (enemyArray->at(counter1).alive == false) {
			std::cout << "ENEMY IS DEAD!!1!\n";
			stage->rooms[enemyArray->at(counter1).room]--;
			if (stage->rooms[enemyArray->at(counter1).room] <= 0) {
				pickUp1->isPowerup = false;
				pickUp1->isHealthPotion = false;
				pickUp1->isPartOfQuestion = true;
				pickUp1->sprite.setTexture(*questionTexture);
				pickUp1->rect.setPosition(enemyArray->at(counter1).rect.getPosition());
				pickUpArray->push_back(*pickUp1);
			}
			//drop health
			if (generateRandom(2) == 1) {
				pickUp1->isPowerup = false;
				pickUp1->isHealthPotion = true;
				pickUp1->isPartOfQuestion = false;
				pickUp1->sprite.setTexture(*healPotionTexture);
				pickUp1->rect.setPosition(enemyArray->at(counter1).rect.getPosition());
				pickUpArray->push_back(*pickUp1);
			}
			else if (generateRandom(2) == 1) {
				pickUp1->isPowerup = true;
				pickUp1->isHealthPotion = false;
				pickUp1->isPartOfQuestion = false;
				pickUp1->sprite.setTexture(*powerupTexture);
				pickUp1->rect.setPosition(enemyArray->at(counter1).rect.getPosition());
				pickUpArray->push_back(*pickUp1);
			}
			enemyArray->erase(iterEnemy);
			break;
		}
		counter1++;
	}
}

