#include "check.h"

int checkP(std::vector<std::string> pieces,std::string piece) {

	for (int i = 0; i < pieces.size(); i++) {
		if (piece == pieces[i]) {
			
			return 0;

		}
		else {
			if (i == pieces.size()) {
				return 1;
			}
			continue;
		}
		
	}
	
}

void checkM(std::string pieceID, std::string locationTo) {

	if (locationTo != "    ") {
		if (locationTo[locationTo.size() - 1] == pieceID[pieceID.size() - 1]) {
			std::cout << "Error: Unable to move the piece here" << '\n';
			exit(1);
		}
	}
}

void checkSurroundings(std::vector<std::vector<std::string>> chessboardV, std::string piece, int row, int col) {
		if (piece == " rW" or piece == " rB") {
			if ((row > 1 and row < 8) and (col > 1 and col < 8)) {
				if (((chessboardV[row + 1 and row - 1][col] != "    ") or (chessboardV[row][col + 1 and col - 1] != "   ")) and ((chessboardV[row + 1 and row - 1][col][chessboardV[row + 1 and row - 1][col].size() - 1] == chessboardV[row][col][chessboardV[row][col].size() - 1]) or (chessboardV[row][col + 1 and col - 1][chessboardV[row ][col + 1 and col - 1].size() - 1] == chessboardV[row][col][chessboardV[row][col].size() - 1]))) {
					std::cout << "Error: Unable to move this piece";
					exit(1);
				}
			}
			else {
				if (chessboardV[row + 1][col] != "   "  and chessboardV[row + 1][col][chessboardV[row + 1][col].size() - 1] == chessboardV[row][col][chessboardV[row][col].size() - 1]) {
					std::cout << "Error: Unable to move this piece";
					exit(1);
				}
			}
		}
		else if (piece == " pW" or piece == " pB") {
			if (piece == " pW") {
				if ((chessboardV[row + 1][col] != "   ") or (chessboardV[row - 1][col] != "   ")) {
					std::cout << "Error: Unable to move this piece";
					exit(1);
				}
			}
			else {
				if (chessboardV[row - 1][col] != "   ") {
					std::cout << "Error: Unable to move this piece";
					exit(1);
				}
			}
		}

}