#include <iostream>
#include <utility>
#include "pieces.h"
#include "printBoard.h"

#pragma once

int conversionRM(char letM, char numM, std::string& pM);
int conversionCM(char letM, char numM, std::string& pM);
int abilities(std::string pA, int rowA, int colA, int rowP, int colP);