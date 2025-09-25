#include "checkP.h"


int checkP(std::vector<std::string> pieces,std::string piece) {

	if (std::find(pieces.begin(), pieces.end(), piece) == pieces.end()) {
		return 0;
	}
	else {
		return 1;
	}
}