#include "printBoard.h"

std::vector<std::vector<std::string>> printBoardC::chessboard = {
	{ " ","  A","  B","  C","  D","  E","  F","  G","  H" },
	{ "1"," rW"," nW"," bW"," qW"," kW"," bW"," nW"," rW" },
	{ "2"," pW"," pW"," pW"," pW"," pW"," pW"," pW"," pW" },
	{ "3","   ","   ","   ","   ","   ","   ","   ","   " },
	{ "4","   ","   ","   ","   ","   ","   ","   ","   " },
	{ "5","   ","   ","   ","   ","   ","   ","   ","   " },
	{ "6","   ","   ","   ","   ","   ","   ","   ","   " },
	{ "7"," pB"," pB"," pB"," pB"," pB"," pB"," pB"," pB" },
	{ "8"," rB"," nB"," bB"," qB"," kB"," bB"," nB"," rB" }
};

void printBoardC::printBoard() {

	for (int row = 0; row < SIZE; row++) {
		std::cout << '\n';
		for (int col = 0; col < SIZE; col++) {
			std::cout << chessboard[row][col];
		}
	}
}
