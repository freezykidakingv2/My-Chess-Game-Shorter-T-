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
		
	int startingR;
	int startingC;
	int notEmpty;

		if (piece == " rW" or piece == " rB") {
			startingR = row - 1;
			startingC = col - 1;
			if ((row > 1 and row < 8) and (col > 1 and col < 8)) {
				for (int i = startingR; i <= row + 1; i++) {
					for (int j = startingC; j <= col + 1; j++) {
						if (row - i == 1 or row - i == -1) {
							if (j == col) {
								if (chessboardV[i][j] == "   ") {
									return 0;
								}
								else {
									continue;
								}
							}
						}
					}
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
			startingR = row - 1;
			startingC = col - 1;
			notEmpty = 0;
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
		else if (piece == " nW" or piece == " nB") {
			int startingR = row - 2;
			int startingC = col - 1;
			int notEmpty = 0;
			if ((row >= 2 and row <= 7) and (col >= 2 and col <= 7)) {
				if ((row > 2 and row < 7) and (col > 2 and col < 7)) {
					for (int i = startingR; i <= startingR + 4; i + 2) {
						for (int j = startingC; j <= col + 1; j + 2) {
							if (chessboardV[i][j] == "   ") {
								return 0;
							}
						}
					}
					
					startingR = row - 1;
					startingC = col - 2;

					for (int i = startingR; i <= row + 1; i + 2) {
						for (int j = startingC; j <= col + 2; j + 4) {
							if (chessboardV[i][j] == "   ") {
								return 0;
							}
						}
					}
					std::cout << "Error: Unable to move this piece";
					exit(1);
				}
				else if ((row == 2 or row == 7) and (col == 2 or col == 7)) {

					if (row == 2) {
						if (col == 2) {
							if (chessboardV[4][1] == "   " or chessboardV[4][3] == "   ") {
								return 0;
							}
							else if (chessboardV[3][4] == "   " or chessboardV[1][4] == "   ") {
								return 0;
							}
							else {
								std::cout << "Error: Unable to move this piece";
								exit(1);
							}
						}
						else {
							if (chessboardV[4][6] == "   " or chessboardV[4][8] == "   ") {
								return 0;
							}
							else if (chessboardV[3][5] == "   " or chessboardV[1][5] == "   ") {
								return 0;
							}
							else {
								std::cout << "Error: Unable to move this piece";
								exit(1);
							}
						}
					}
					else {
						if (col == 2) {
							if (chessboardV[5][1] == "   " or chessboardV[5][3] == "   ") {
								return 0;
							}
							else if (chessboardV[6][4] == "   " or chessboardV[8][4] == "   ") {
								return 0;
							}
							else {
								std::cout << "Error: Unable to move this piece";
								exit(1);
							}
						}
						else {
							if (chessboardV[5][6] == "   " or chessboardV[5][8] == "   ") {
								return 0;
							}
							else if (chessboardV[6][5] == "   " or chessboardV[8][5] == "   ") {
								return 0;
							}
							else {
								std::cout << "Error: Unable to move this piece";
								exit(1);
							}
						}
					}
				}
			}
			else if ((row == 1 or row == 8) and (col == 1 or col == 8)) {
				if (row == 1) {
					if (col == 1) {
						if (chessboardV[2][3] == "   ") {
							return 0;
						}
						else if (chessboardV[3][2] == "   ") {
							return 0;
						}
						else{ 
							std::cout << "Error: Unable to move this piece";
							exit(1);
						}

					}
					else {
						if (chessboardV[2][6] == "   ") {
							return 0;
						}
						else if (chessboardV[3][7] == "   ") {
							return 0;
						}
						else {
							std::cout << "Error: Unable to move this piece";
							exit(1);
						}
					}
				}
				else if (row == 8) {
					if (col == 1) {
						if (chessboardV[7][3] == "   ") {
							return 0;
						}
						else if (chessboardV[6][2] == "   ") {
							return 0;
						}
						else {
							std::cout << "Error: Unable to move this piece";
							exit(1);
						}
					}
					else {
						if (chessboardV[7][6] == "   ") {
							return 0;
						}
						else if (chessboardV[6][7] == "   ") { // tuff
							return 0;
						}
						else {
							std::cout << "Error: Unable to move this piece";
							exit(1);
						}
					}
				}
			}
			else if ((row > 1 and row < 8) and (col == 1 or col == 8)) {
				if (row == 2) {
					if (col == 1) {
						if (chessboardV[1][3] == "   " or chessboardV[3][3] == "   ") {
							return 0;
						}
						else if (chessboardV[4][2] == "   ") {
							return 0;
						}
						else {
							std::cout << "Error: Unable to move this piece";
							exit(1);
						}
					}
					else {
						if (chessboardV[1][6] == "   " or chessboardV[3][6] == "   ") {
							return 0;
						}
						else if (chessboardV[4][7] == "   ") {
							return 0;
						}
						else {
							std::cout << "Error: Unable to move this piece";
							exit(1);
						}
					}
				}
				else  if (row == 7) {
					if (col == 1) {
						if (chessboardV[6][3] == "   " or chessboardV[8][3] == "   ") {
							return 0;
						}
						else if (chessboardV[5][2] == "   ") {
							return 0;
						}
						else {
							std::cout << "Error: Unable to move this piece";
							exit(1);
						}
					}
					else {
						if (chessboardV[6][6] == "   " or chessboardV[8][6] == "   ") {
							return 0;
						}
						else if (chessboardV[5][7] == "   ") {
							return 0;
						}
						else {
							std::cout << "Error: Unable to move this piece";
							exit(1);
						}
					}
				}
				else {
					startingR = row - 2;
					if (col == 1) {
						for (int i = startingR; i <= row + 2; i++) {
							if (i == row) {
								continue;
							}
							for (int j = 2; j <= 3; j++) {
								if ((row - i == 2 or row - i == -2) and j == 3) {
									continue;
								}
								else {
									if (chessboardV[i][j] == "   ") {
										return 0;
									}
								}
							}
						}
						std::cout << "Error: Unable to move this piece";
						exit(1);
					}
					else {
						for (int i = startingR; i <= row + 2; i++) {
							if (i == row) {
								continue;
							}
							for (int j = 6; j <= 7; j++) {
								if ((row - i == 2 or row - i == -2) and j == 6) {
									continue;
								}
								else {
									if (chessboardV[i][j] == "   ") {
										return 0;
									}
								}
							}
						}
						std::cout << "Error: Unable to move this piece";
						exit(1);
					}
				}
			}
			else if ((row == 1 or row == 8) and (col > 1 and col < 8)) {
				startingC = col - 2;
				if (row == 1) {
					if (col != 7) {
						for (int i = 2; i <= 3; i++) {
							for (int j = startingC; j <= 4; j++) {
								if (i == 2) {
									if (j == col - 2 or j == col + 2) {
										if (chessboardV[i][j] == "   ") {
											return 0;
										}
									}
									else {
										continue;
									}
								}
								else {
									if (j == col + 1 or j == col - 1) {
										if (chessboardV[i][j] == "   ") {
											return 0;
										}
									}
									else {
										continue;
									}
								}
							}
						}
						std::cout << "Error: Unable to move this piece";
						exit(1);
					}
					else {
						for (int i = 2; i <= 3; i++) {
							for (int j = startingC; j <= 8; j++) {
								if (i == 2) {
									if (j == col - 2 or j == col + 2) {
										if (chessboardV[i][j] == "   ") {
											return 0;
										}
										else {
											break;
										}
									}
								}
								else {
									if (j == col + 1 or j == col - 1) {
										if (chessboardV[i][j] == "   ") {
											return 0;
										}
									}
									else {
										continue;
									}
								}
							}
						}
						std::cout << "Error: Unable to move this piece";
						exit(1);
					}
				}
				else {
					startingR = row - 2;
					if (col != 7) {
						for (int i = startingR; i <= 8; i++) {
							for (int j = startingC; j <= 4; j++) {
								if (i == 7) {
									if (j == col - 2 or j == col + 2) {
										if (chessboardV[i][j] == "   ") {
											return 0;
										}
									}
									else {
										if (j != 4) {
											continue;
										}
										else {
											std::cout << "Error: Unable to move this piece";
											exit(1);
										}
									}
								}
								else {
									if (j == col + 1 or j == col - 1) {
										if (chessboardV[i][j] == "   ") {
											return 0;
										}
									}
									else {
										continue;
									}
								}
							}
						}
					}
					else {
						for (int i = startingR; i <= 8; i++) {
							for (int j = startingC; j <= 8; j++) {
								if (i == 7) {
									if (j == col - 2 or j == col + 2) {
										if (chessboardV[i][j] == "   ") {
											return 0;
										}
										else {
											std::cout << "Error: Unable to move this piece";
											exit(1);
										}
									}
								}
								else {
									if (j == col + 1 or j == col - 1) {
										if (chessboardV[i][j] == "   ") {
											return 0;
										}
									}
									else {
										continue;
									}
								}
							}
						}
					}
				}
			}
		}

}