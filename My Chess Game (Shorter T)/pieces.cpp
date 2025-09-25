#include "pieces.h"
#include "printBoard.h"

int conversionR(char letR, char numR, std::string& pR) {

	if (pR.length() != 3) { 
		std::cout << "Error: Invalid input";
		exit(1);
	}
	
	letR = std::toupper(letR);
	
	int col = (letR - 'A') + 1;
	int row = (numR - '0');

	if (row < 0 or row > 8) { 
	
		std::cout << "Error: Invalid input";
		exit(1);
	};

	return row;
}

int conversionC(char letC, char numC, std::string& pC) {

	if (pC.length() != 2) {
		std::cout << "Error: Invalid input";
		exit(1);
	}

	letC = std::toupper(letC);

	int col = (letC - 'A') + 1;

	if (col < 1 or col > 8) {

		std::cout << "Error: Invalid input";
		exit(1);
	};

	return col;
}

