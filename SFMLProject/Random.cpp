#include "Random.h"


int generateRandom(int max) {
	int randomNumber = rand();
	float random = (randomNumber % max) + 1;
	return int(random);
}

int generateRandom0(int max) {
	int randomNumber = rand();
	float random = (randomNumber % max);
	return int(random);
}

bool generateRandomBool() {
	int randomNumber = rand();
	float random = (randomNumber % 2) + 1;
	int myRandom = random;
	if (myRandom == 1)
		return true;
	return false;
}
