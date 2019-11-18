#ifndef PC3B_PARSEVECTOR_H
#define PC3B_PARSEVECTOR_H

#include "rectangulos.h"
#include "allIncludes.h"
#include <algorithm>

void parseVector1(vector<string>, int&, int&, int&);
void parseVector2(vector<string>, vector<rectangulos>& rectangles);
int** createTable(int,int);
void destroyTable(int**&,int);

template<typename forward, typename T>
void iterate(T& s, forward a, forward b){
    while(a != b){
        s += *a;
        a++;
    }
}

#endif //PC3B_PARSEVECTOR_H
