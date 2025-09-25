#include "checkP.h"

int checkP(std::vector<std::string> pieces,std::string piece) {

	bool skip;

	for (int i = 0; i < pieces.size(); i++) {
		if (std::find(pieces.begin(), pieces.end(), piece) != pieces.end()) {
			skip = true;
			break;
		}
		else {
			return 0;
		}
		
		if (skip == true) {
			continue;
		}
	}
	
}