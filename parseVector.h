#ifndef PC3B_PARSEVECTOR_H
#define PC3B_PARSEVECTOR_H

#include "rectangulos.h"
#include "allIncludes.h"
#include <algorithm>

void parseVector1(vector<string>, int**&, int&);
void parseVector2(vector<string>, vector<rectangulos>& rectangles);

int** createTable(int,int);

void destroyTable(int**&,int,int);

#endif //PC3B_PARSEVECTOR_H
