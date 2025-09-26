#include "score.h"

int score::scoreF(std::vector<std::vector<std::string>> board, std::string moveTo) {

	score emptySpaces;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[i][j] == "   ") {
				emptySpaces.empty.push_back(board[i][j]);

			}
		}
	}

	for (std::string space : emptySpaces.empty) {
		if (moveTo == space) {
			return 0;
		}
		else {
			if (space == emptySpaces.empty[emptySpaces.empty.size() - 1]) {
				return 1;
			}
			continue;
		}
	}
}