#include "score.h"

int score::scoreF(std::string moveTo) {

	if (moveTo == "   ") {
		return 0;
	}
	else {
		std::cout << moveTo;
		return 1;
	}
}