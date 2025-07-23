#include <iostream>
#include <algorithm>
#include "printBoard.h"
#include "pieces.h"
#include "moves.h"

int main() {

	printBoardC print;
	printBoardC any;
	printBoardC chessP;
	printBoardC movesM;

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
	bool whiteT; // This variable is for white's turn.
	bool gameONS; // This variable is for the rest of the turns.

	while (gameONF == true) { // While on the first turns ...

		whiteT = true;

		if (whiteT == true) {
			std::string piece;
			std::cout << '\n';
			std::cout << "White goes first" << '\n' << '\n';
			std::cout << "Pick a piece: ";
			std::cin >> piece;

			char letter = piece[0];
			char number = piece[1];

			if (piece.length() != 2) { // Checking to see if the input is 2 characters long.
				std::cerr << "Error: Incorrect input";
				exit(1);
			}

			for (int pW = 0; pW < whiteP.size(); pW++) {

				if (chessP.chessboard[conversionR(letter, number, piece)][conversionC(letter, number, piece)] != whiteP[pW]) {
					if (pW > 8) {
						std::cerr << "Error: Invalid Input";
						exit(1);
					}
				}
				else {
					break;
				}
			}

			std::cout << "You've selected: " << chessP.chessboard[conversionR(letter, number, piece)][conversionC(letter, number, piece)] << '\n';

			std::string move;
			std::cout << "Choose where to move the piece to: ";
			std::cin >> move;

			char letterM = move[0];
			char numberM = move[1];

			movesM.chessboard[conversionRM(letterM, numberM, move)][conversionCM(letterM, numberM, move)] = chessP.chessboard[conversionR(letter, number, piece)][conversionC(letter, number, piece)];
			abilities(movesM.chessboard[conversionRM(letterM, numberM, move)][conversionCM(letterM, numberM, move)], conversionRM(letterM, numberM, move), conversionCM(letterM, numberM, move), conversionR(letter, number, piece), conversionC(letter, number, piece));
			chessP.chessboard[conversionR(letter, number, piece)][conversionC(letter, number, piece)] = "  ";

			print.printBoard();
		}

		whiteT = false;

		if (whiteT == false) {

			std::string piece;
			std::cout << '\n' << '\n';
			std::cout << "Blacks turn: " << '\n' << '\n';
			std::cout << "Pick a piece: ";
			std::cin >> piece;

			if (piece.length() != 2) {
				std::cerr << "Error: Incorrect input";
				exit(1);
			}

			char letter = piece[0];
			char number = piece[1];
			
			for (int p = 0; p < blackP.size(); p++) {
				
				if (chessP.chessboard[conversionR(letter, number, piece)][conversionC(letter, number, piece)] != blackP[p]) {
					if (p > 8) {
						std::cerr << "Error: Invalid Input";
						exit(1);
					}
				}
				else {
					break;
				}
			}

			std::cout << "You've selected: " << chessP.chessboard[conversionR(letter, number, piece)][conversionC(letter, number, piece)] << '\n';

			std::string move;
			std::cout << "Choose where to move the piece to: ";
			std::cin >> move;

			char letterM = move[0];
			char numberM = move[1];

			movesM.chessboard[conversionRM(letterM, numberM, move)][conversionCM(letterM, numberM, move)] = chessP.chessboard[conversionR(letter, number, piece)][conversionC(letter, number, piece)];
			abilities(movesM.chessboard[conversionRM(letterM, numberM, move)][conversionCM(letterM, numberM, move)], conversionRM(letterM, numberM, move), conversionCM(letterM, numberM, move), conversionR(letter, number, piece), conversionC(letter, number, piece));
			chessP.chessboard[conversionR(letter, number, piece)][conversionC(letter, number, piece)] = "  ";

			print.printBoard();
		
		}
		break;
	}

	gameONS = true;

	while (gameONS == true) {

		whiteT = true;

		if (whiteT == true) {
			std::string piece;
			std::cout << '\n' << '\n';
			std::cout << "White's turn: " << '\n' << '\n';
			std::cout << "Pick a piece: ";
			std::cin >> piece;

			char letter = piece[0];
			char number = piece[1];

			if (piece.length() != 2) {
				std::cerr << "Error: Incorrect input";
				exit(1);
			}
			
			for (int pW = 0; pW < whiteP.size(); pW++) {

				if (chessP.chessboard[conversionR(letter, number, piece)][conversionC(letter, number, piece)] != whiteP[pW]) {
					if (pW > 8) {
						std::cerr << "Error: Invalid Input";
						exit(1);
					}
				}
				else {
					break;
				}
			}

			std::cout << "You've selected: " << chessP.chessboard[conversionR(letter, number, piece)][conversionC(letter, number, piece)] << '\n';

			std::string move;
			std::cout << "Choose where to move the piece to: ";
			std::cin >> move;

			char letterM = move[0];
			char numberM = move[1];

			movesM.chessboard[conversionRM(letterM, numberM, move)][conversionCM(letterM, numberM, move)] = chessP.chessboard[conversionR(letter, number, piece)][conversionC(letter, number, piece)];
			abilities(movesM.chessboard[conversionRM(letterM, numberM, move)][conversionCM(letterM, numberM, move)], conversionRM(letterM, numberM, move), conversionCM(letterM, numberM, move), conversionR(letter, number, piece), conversionC(letter, number, piece));
			chessP.chessboard[conversionR(letter, number, piece)][conversionC(letter, number, piece)] = "  ";

			print.printBoard();
		}

		whiteT = false;

		if (whiteT == false) {

			std::string piece;
			std::cout << '\n' << '\n';
			std::cout << "Blacks turn: " << '\n' << '\n';
			std::cout << "Pick a piece: ";
			std::cin >> piece;

			char letter = piece[0];
			char number = piece[1];

			for (int p = 0; p < blackP.size(); p++) {

				if (chessP.chessboard[conversionR(letter, number, piece)][conversionC(letter, number, piece)] != blackP[p]) {
					if (p > 8) {
						std::cerr << "Error: Invalid Input";
						exit(1);
					}
				}
				else {
					break;
				}
			}

			std::cout << "You've selected: " << chessP.chessboard[conversionR(letter, number, piece)][conversionC(letter, number, piece)] << '\n';

			std::string move;
			std::cout << "Choose where to move the piece to: ";
			std::cin >> move;

			char letterM = move[0];
			char numberM = move[1];

			movesM.chessboard[conversionRM(letterM, numberM, move)][conversionCM(letterM, numberM, move)] = chessP.chessboard[conversionR(letter, number, piece)][conversionC(letter, number, piece)];
			abilities(movesM.chessboard[conversionRM(letterM, numberM, move)][conversionCM(letterM, numberM, move)], conversionRM(letterM, numberM, move), conversionCM(letterM, numberM, move), conversionR(letter, number, piece), conversionC(letter, number, piece));
			chessP.chessboard[conversionR(letter, number, piece)][conversionC(letter, number, piece)] = "  ";

			print.printBoard();

		}
	}

	return 0;
}
