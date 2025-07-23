#include <iostream>
#include <vector>
#pragma once

class printBoardC {
public:
	const int SIZE = 9;
	static std::vector<std::vector<std::string>> chessboard;

	void printBoard();
};