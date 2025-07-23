#include "moves.h"

int conversionRM(char letRM, char numRM, std::string& pRM) {

	if (pRM.length() != 2) {
		std::cout << "Error: Invalid input";
		exit(1);
	}

	letRM = std::toupper(letRM);

	int rowM = (numRM - '0');

	if (rowM < 0 or rowM > 8) {

		std::cout << "Error: Invalid input";
		exit(1);
	};

	return rowM;
}

int conversionCM(char letCM, char numCM, std::string& pCM) {

	if (pCM.length() != 2) {
		std::cout << "Error: Invalid input";
		exit(1);
	}

	letCM = std::toupper(letCM);

	int colM = (letCM - 'A') + 1;

	if (colM < 1 or colM > 8) {

		std::cout << "Error: Invalid input";
		exit(1);
	};

	return colM;
}

int abilities(std::string pA, int rowA, int colA, int rowP, int colP) {

	if (pA == " k" or pA == " n") {
		if ((rowA == rowP + 2 and (colA == colP + 1 or colA == colP - 1)) or (rowA == rowP -2 and (colA == colP -1))) {
			return 0;
		}
		else {
			std::cout << "Error: Unable to move this piece there";
			exit(1);
		}
	}
	else if (pA == " r") {
		if (rowA == rowP + 2)
	}

	return 0;
}