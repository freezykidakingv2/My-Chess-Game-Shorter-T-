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

int checkSurroundings(std::vector<std::vector<std::string>> chessboardV, std::string piece, int row, int col) {
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
				if (chessboardV[row + 1][col] != "   ") {
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
		else if (piece == " qW" or piece == " qB") {
			int startingR = row - 1;
			int startingC = col - 1;
			int notEmpty = 0;
			if ((row > 1 and row < 8) and (col > 1 and col < 8)) {
				for (int i = startingR; i <= startingR + 2; i++) {
					for (int j = startingC; j <= col + 2; j++) {
						if (chessboardV[i][j] == chessboardV[row][col]) {
							continue;
						}

						if (chessboardV[i][j] != "   ") {
							notEmpty++;
						}

						if (notEmpty == 8) {
							std::cout << "Error: Unable to move this piece";
							exit(1);
						}
					}
				}
			}
			else if ((row == 1 or row == 8) and (col == 1 or col == 8)) {
				startingR = row + 1;
				startingC = col;
				if (row == 1) {
					if (col != 8) {
						for (int i = startingR; i >= row; i--) {

							if (chessboardV[i][col + 1] != "   ") {
								notEmpty++;
							}

							if (notEmpty == 3) {
								std::cout << "Error: Unable to move this piece";
								exit(1);
							}

							if (i == row) {
								return 0;
							}

							if (chessboardV[i][col] != "   ") {
								notEmpty++;
							}

						}
					}
					else {
						for (int i = startingR; i > row; i--) {
							for (int j = startingC; j >= col; j--) {
								if (chessboardV[i][col - 1] != "   ") {
									notEmpty++;
								}

								if (notEmpty == 3) {
									std::cout << "Error: Unable to move this piece";
									exit(1);
								}

								if (i == row) {
									return 0;
								}

								if (chessboardV[i][col] != "   ") {
									notEmpty++;
								}
							}
						}
					}
				}
				else if (row == 8) {
					startingR = row - 1;
					if (col == 1) {
						for (int i = startingR; i <= row; i++) {

							if (chessboardV[i][col + 1] != "   ") {
								notEmpty++;
							}

							if (notEmpty == 3) {
								std::cout << "Error: Unable to move this piece";
								exit(1);
							}

							if (i == row) {
								return 0;
							}

							if (chessboardV[i][col] != "   ") {
								notEmpty++;
							}
						}
					}
					else {
						for (int i = startingR; i <= row; i++) {

							if (chessboardV[i][col - 1] != "   ") {
								notEmpty++;
							}

							if (notEmpty == 3) {
								std::cout << "Error: Unable to move this piece";
								exit(1);
							}

							if (i == row) {
								return 0;
							}

							if (chessboardV[i][col] != "   ") {
								notEmpty++;
							}
						}
					}
				}
			}
			else if ((row > 1 and row < 8) and (col == 1 or col == 8)) {
				startingR = row - 1;
				startingC = col;
				if (col == 1) {
					for (int i = startingR; i <= row + 1; i++) {
						for (int j = startingC; j <= col + 1; j++) {

							if (chessboardV[i][j] == chessboardV[row][col]) {
								continue;
							}

							if (chessboardV[i][j] != "   ") {
								notEmpty++;
							}
							if (notEmpty == 5) {
								std::cout << "Error: Unable to move this piece";
								exit(1);
							}
						}
						if (i == row + 1) {
							return 0;
						}
					}
				}
				else {
					for (int i = startingR; i <= row + 1; i++) {
						for (int j = startingC; j >= col - 1; j--) {

							if (chessboardV[i][j] == chessboardV[row][col]) {
								continue;
							}

							if (chessboardV[i][j] != "   ") {
								notEmpty++;
							}
							if (notEmpty == 5) {
								std::cout << "Error: Unable to move this piece";
								exit(1);
							}
						}
						if (i == row + 1) {
							return 0;
						}
					}
				}
			}
			else if ((row == 1 or row == 8) and (col > 1 and col < 8)) {
				startingR = row;
				startingC = col - 1;
				if (row == 1) {
					for (int j = startingC; j <= col + 1; j++) {
						for (int i = startingR; i <= row + 1; i++) {

							if (chessboardV[i][j] == chessboardV[row][col]) {
								continue;
							}

							if (chessboardV[i][j] != "   ") {
								notEmpty++;
							}

							if (notEmpty == 5) {
								std::cout << "Error: Unable to move this piece";
								exit(1);
							}
						}
						if (j == col + 1) {
							return 0;
						}
					}
				}
				else {
					for (int j = startingC; j <= col + 1; j++) {
						for (int i = startingR; i >= row - 1; i--) {

							if (chessboardV[i][j] == chessboardV[row][col]) {
								continue;
							}

							if (chessboardV[i][j] != "   ") {
								notEmpty++;
							}

							if (notEmpty == 5) {
								std::cout << "Error: Unable to move this piece";
								exit(1);
							}
						}
						if (j == col + 1) {
							return 0;
						}
					}
				}
			}

		}
		else if (piece == " kW" or piece == " kB") {
			int startingR = row - 1;
			int startingC = col - 1;
			int notEmpty = 0;
			if ((row > 1 and row < 8) and (col > 1 and col < 8)) {
				for (int i = startingR; i <= startingR + 2; i++) {
					for (int j = startingC; j <= col + 2; j++) {
						if (chessboardV[i][j] == chessboardV[row][col]) {
							continue;
						}

						if (chessboardV[i][j] != "   ") {
							notEmpty++;
						}

						if (notEmpty == 8) {
							std::cout << "Error: Unable to move this piece";
							exit(1);
						}
					}
				}
			}
			else if ((row == 1 or row == 8) and (col == 1 or col == 8)) {
				startingR = row + 1;
				startingC = col;
				if (row == 1) {
					if (col != 8) {
						for (int i = startingR; i >= row; i--) {

							if (chessboardV[i][col + 1] != "   ") {
								notEmpty++;
							}

							if (notEmpty == 3) {
								std::cout << "Error: Unable to move this piece";
								exit(1);
							}

							if (i == row) {
								return 0;
							}

							if (chessboardV[i][col] != "   ") {
								notEmpty++;
							}

						}
					}
					else {
						for (int i = startingR; i > row; i--) {
							for (int j = startingC; j >= col; j--) {
								if (chessboardV[i][col - 1] != "   ") {
									notEmpty++;
								}

								if (notEmpty == 3) {
									std::cout << "Error: Unable to move this piece";
									exit(1);
								}

								if (i == row) {
									return 0;
								}

								if (chessboardV[i][col] != "   ") {
									notEmpty++;
								}
							}
						}
					}
				}
				else if (row == 8) {
					startingR = row - 1;
					if (col == 1) {
						for (int i = startingR; i <= row; i++) {

							if (chessboardV[i][col + 1] != "   ") {
								notEmpty++;
							}

							if (notEmpty == 3) {
								std::cout << "Error: Unable to move this piece";
								exit(1);
							}

							if (i == row) {
								return 0;
							}

							if (chessboardV[i][col] != "   ") {
								notEmpty++;
							}
						}
					}
					else {
						for (int i = startingR; i <= row; i++) {

							if (chessboardV[i][col - 1] != "   ") {
								notEmpty++;
							}

							if (notEmpty == 3) {
								std::cout << "Error: Unable to move this piece";
								exit(1);
							}

							if (i == row) {
								return 0;
							}

							if (chessboardV[i][col] != "   ") {
								notEmpty++;
							}
						}
					}
				}
			}
			else if ((row > 1 and row < 8) and (col == 1 or col == 8)) {
				startingR = row - 1;
				startingC = col;
				if (col == 1) {
					for (int i = startingR; i <= row + 1; i++) {
						for (int j = startingC; j <= col + 1; j++) {

							if (chessboardV[i][j] == chessboardV[row][col]) {
								continue;
							}

							if (chessboardV[i][j] != "   ") {
								notEmpty++;
							}
							if (notEmpty == 5) {
								std::cout << "Error: Unable to move this piece";
								exit(1);
							}
						}
						if (i == row + 1) {
							return 0;
						}
					}
				}
				else {
					for (int i = startingR; i <= row + 1; i++) {
						for (int j = startingC; j >= col - 1; j--) {

							if (chessboardV[i][j] == chessboardV[row][col]) {
								continue;
							}

							if (chessboardV[i][j] != "   ") {
								notEmpty++;
							}
							if (notEmpty == 5) {
								std::cout << "Error: Unable to move this piece";
								exit(1);
							}
						}
						if (i == row + 1) {
							return 0;
						}
					}
				}
			}
			else if ((row == 1 or row == 8) and (col > 1 and col < 8)) {
				startingR = row;
				startingC = col - 1;
				if (row == 1) {
					for (int j = startingC; j <= col + 1; j++) {
						for (int i = startingR; i <= row + 1; i++) {

							if (chessboardV[i][j] == chessboardV[row][col]) {
								continue;
							}

							if (chessboardV[i][j] != "   ") {
								notEmpty++;
							}

							if (notEmpty == 5) {
								std::cout << "Error: Unable to move this piece";
								exit(1);
							}
						}
						if (j == col + 1) {
							return 0;
						}
					}
				}
				else {
					for (int j = startingC; j <= col + 1; j++) {
						for (int i = startingR; i >= row - 1; i--) {

							if (chessboardV[i][j] == chessboardV[row][col]) {
								continue;
							}

							if (chessboardV[i][j] != "   ") {
								notEmpty++;
							}

							if (notEmpty == 5) {
								std::cout << "Error: Unable to move this piece";
								exit(1);
							}
						}
						if (j == col + 1) {
							return 0;
						}
					}
				}
			}

		}
}