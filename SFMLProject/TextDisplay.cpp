#include "TextDisplay.h"




TextDisplay::TextDisplay() {
	text.setFillColor(sf::Color::Red);
	text.setCharacterSize(30);
	text.setPosition(0, 0);
	text.setString(myString);
}

void TextDisplay::update() {
	text.move(0, -movementSpeed);
	counter++;
	if (counter >= lifeTime) {
		destroy = true;
	}
}




TextDisplay::~TextDisplay() {

}
