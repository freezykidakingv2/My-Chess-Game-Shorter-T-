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

	if (pA == " nW" or pA == " nB") {
		if ((rowA == rowP + 2 and (colA == colP + 1 or colA == colP - 1)) or (rowA == rowP -2 and (colA == colP -1)) or (rowA == rowP + 1 and (colA == colP + 2 or colA == colP - 2)) or (rowA == rowP - 1 and (colA == colP - 2 or colA == colP + 2))) {
			return 0;
		}
		else {
			std::cout << "Error: Unable to move this piece there";
			exit(1);
		}
	}
	else if (pA == " rW" or pA == " rB") {

		for (int i = 0; i <= 8; i++) { // If the orginal row of the piece is == (1, 2, 3.. etc) then the row where you wan't to move to can't change or if the orginal column of the piece is == (1, 2, 3.. etc) then the column where you wan't to move to can't change
			// In simple terms, the row can either change and the column stays the same, or the column can either change and row stays the same.
			if (rowP == i or colP == i) {
				if (colA == colP or rowA == rowP) {
					return 0;
				}
				else {
					if (i > 8) {
						std::cout << "Error: Unable to move this piece there";
						exit(1);

					}
				}
			}
		}
	}
	else if (pA == " bW" or pA == " bB") {

		for (int i = 1; i <= 8; i++) {
			if ((rowA == rowP + i and (colA == colP + i or colA == colP - i)) or (rowA == rowP - i and (colA == colP - i or colA == colP + i))) {
				return 0;
			}
			else {
				if (i == 8) {
					std::cout << "New row: " << rowA << " Old row: " << rowP << " New column: " << colA << " Old Column: " << colP;
					std::cout << "Error: Unable to move this piece there";
					exit(1);

				}
			}
		 }
	}
	else if (pA == " pW" or pA == " pB") {
		if (pA == " pW") {
			if ((rowA == rowP + 2 and rowA == 4) and colA == colP) {
				return 0;
			}
			else if (rowA == rowP + 1 and colA == colP) {
				return 0;
			}
			else {
				std::cout << "Error: Unable to move this piece there";
				exit(1);
			}
		}
		else {
			if ((rowA == rowP - 2 and rowA == 5 and colA == colP) or (rowA == rowP - 1 and colA == colP)) {
				return 0;
			}
			else {
				std::cout << "Error: Unable to move this piece there";
				exit(1);
			}
		}
	}
	else if ()

return 0;
}