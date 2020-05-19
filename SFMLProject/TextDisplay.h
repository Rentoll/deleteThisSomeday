#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "Entity.h"
class TextDisplay: public Entity {
public:
	std::string myString = "Default";
	int movementSpeed = 2;
	int counter = 0;
	int lifeTime = 30;
	bool destroy = false;

	TextDisplay();
	void update();
	~TextDisplay();
};

#endif
