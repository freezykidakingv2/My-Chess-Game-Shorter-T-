#include "checkP.h"

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