#include "printBoard.h"

std::vector<std::vector<std::string>> printBoardC::chessboard = {
	{ " "," A"," B"," C"," D"," E"," F"," G"," H" },
	{ "1"," r"," n"," b"," q"," k"," b"," n"," r" },
	{ "2"," p"," p"," p"," p"," p"," p"," p"," p" },
	{ "3","  ","  ","  ","  ","  ","  ","  ","  " },
	{ "4","  ","  ","  ","  ","  ","  ","  ","  " },
	{ "5","  ","  ","  ","  ","  ","  ","  ","  " },
	{ "6","  ","  ","  ","  ","  ","  ","  ","  " },
	{ "7"," p"," p"," p"," p"," p"," p"," p"," p" },
	{ "8"," r"," k"," b"," q"," k"," b"," k"," r" }
};

void printBoardC::printBoard() {

	for (int row = 0; row < SIZE; row++) {
		std::cout << '\n';
		for (int col = 0; col < SIZE; col++) {
			std::cout << chessboard[row][col];
		}
	}
}
