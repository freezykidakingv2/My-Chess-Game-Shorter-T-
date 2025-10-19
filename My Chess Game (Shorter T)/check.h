#include <iostream>
#include <vector>
#include <algorithm>

int checkP(std::vector<std::string> pieces, std::string piece);
void checkM(std::string pieceID, std::string locationTo);
int checkSurroundings(std::vector<std::vector<std::string>> chessboardV, std::string piece, int row, int col);