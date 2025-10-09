#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "printBoard.h"
#include "pieces.h"
#include "moves.h"
#include "check.h"
#include "score.h"

int main() {

	struct convertions {
		int convertedR;
		int convertedC;
		int convertedMR;
		int convertedMC;
	};

	printBoardC print;
	printBoardC any;
	printBoardC chessP;
	printBoardC movesM;
	score Iftaken;
	convertions use;

	int scoreW = 0;
	int scoreB = 0;

	std::cout << "Black's score: " << scoreB;
	std::cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "White's score: " << scoreW << '\n' << '\n';


	print.printBoard(); // Print the chessboard. Example: 
	std::cout << '\n' << '\n'; /* " "," A"," B"," C"," D"," E"," F"," G"," H"
								  "1"," r"," n"," b"," q"," k"," b"," n"," r"
								  "2"," p"," p"," p"," p"," p"," p"," p"," p"
								  "3","  ","  ","  ","  ","  ","  ","  ","  "
								  "4","  ","  ","  ","  ","  ","  ","  ","  "
								  "5","  ","  ","  ","  ","  ","  ","  ","  "
								  "6","  ","  ","  ","  ","  ","  ","  ","  "
								  "7"," p"," p"," p"," p"," p"," p"," p"," p"
								  "8"," r"," k"," b"," q"," k"," b"," k"," r" */

	std::vector<std::string> blackP; // This is where we will store the black pieces.

	for (int iB = 7; iB <= 8; ++iB) { // Store the black pieces in a vector called blackP.
		for (int jB = 1; jB <= 8; ++jB) {
			blackP.push_back(chessP.chessboard[iB][jB]);
		}
	}

	std::vector<std::string> whiteP; // This is where we will store the white pieces.

	for (int iW = 1; iW <= 2; ++iW) { // Store the white pieces in a vector called whiteP.
		for (int jW = 1; jW <= 8; ++jW) {
			whiteP.push_back(chessP.chessboard[iW][jW]);
		}
	}

	bool gameONF = true; // This variable is for the first turns.
	int counter = 1;

	while (gameONF == true) { // While on the first turns ...

			std::string piece;
			std::cout << '\n';
			if (counter == 1) {
				std::cout << "White goes first" << '\n' << '\n';
				counter++;
			}
			else {
				std::cout << "White's turn" << '\n' << '\n';
			}
			std::cout << "Pick a piece: ";
			std::cin >> piece;

			if (piece.length() != 2) { // Checking to see if the input is 2 characters long.
				std::cerr << "Error: Incorrect input";
				exit(1);
			}

			char letter = piece[0];
			char number = piece[1];

			use.convertedR = conversionR(letter, number, piece);
			use.convertedC = conversionC(letter, number, piece);

			std::string *selectedP = &chessP.chessboard[use.convertedR][use.convertedC];

			checkSurroundings(any.chessboard, *selectedP, use.convertedR, use.convertedC);
			
			if (checkP(whiteP, *selectedP) != 0) {	// Checking if piece is in white pieces vector.
				std::cout << "Error: Wrong Piece" << '\n';
				exit(1);
			}

			std::cout << "You've selected: " << *selectedP << '\n';

			std::string move;
			std::cout << "Choose where to move the piece to: ";
			std::cin >> move;

			char letterM = move[0];
			char numberM = move[1];

			use.convertedMR = conversionRM(letterM, numberM, move);
			use.convertedMC = conversionCM(letterM, numberM, move);

			std::string * movingTo = &movesM.chessboard[use.convertedMR][use.convertedMC];

			checkM(*selectedP, *movingTo);

			if (Iftaken.scoreF(*movingTo) != 0) {
				scoreW += 1;
			}

			*movingTo = *selectedP;
			
			abilities(*movingTo, use.convertedMR, use.convertedMC, use.convertedR, use.convertedC);
			*selectedP = "   ";

			// Blacks's turn :

			system("cls");
			std::cout << "Black's score: " << scoreB;
			std::cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "White's score: " << scoreW << '\n' << '\n';
			print.printBoard();

			std::cout << '\n' << '\n';
			std::cout << "Blacks turn: " << '\n' << '\n';
			std::cout << "Pick a piece: ";
			std::cin >> piece;

			if (piece.length() != 2) {
				std::cerr << "Error: Incorrect input";
				exit(1);
			}

			letter = piece[0];
			number = piece[1];
			
			use.convertedR = conversionR(letter, number, piece);
			use.convertedC = conversionC(letter, number, piece);

			selectedP = &chessP.chessboard[use.convertedR][use.convertedC];

			checkSurroundings(any.chessboard, *selectedP, use.convertedR, use.convertedC);

			if (checkP(blackP, *selectedP) != 0) {
				std::cout << "Error: Wrong Piece" << '\n';
				exit(1);
			}

			std::cout << "You've selected: " << *selectedP << '\n';

			std::cout << "Choose where to move the piece to: ";
			std::cin >> move;

			letterM = move[0];
			numberM = move[1];

			use.convertedMR = conversionRM(letterM, numberM, move);
			use.convertedMC = conversionCM(letterM, numberM, move);

			movingTo = &movesM.chessboard[use.convertedMR][use.convertedMC];

			checkM(*selectedP, *movingTo);

			if (Iftaken.scoreF(*movingTo) != 0) {
				scoreB += 1;
			}

			*movingTo = *selectedP;

			abilities(*movingTo, use.convertedMR, use.convertedMC, use.convertedR, use.convertedC);
			*selectedP = "   ";
			
			system("cls");
			std::cout << "Black's score: " << scoreB;
			std::cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "White's score: " << scoreW << '\n' << '\n';
			print.printBoard();
	}

	return 0;
}

