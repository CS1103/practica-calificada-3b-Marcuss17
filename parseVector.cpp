#include "parseVector.h"

void parseVector1(vector<string> fileRead, int**& table, int& numRect){
    int n,m;
    string line;
    for(auto it = fileRead.begin(); it  != fileRead.end(); it++){
        if(it == fileRead.begin()){
            for(int i = 0; i < 3; i++){
                line = "";
                auto it2 = find(it->begin(), it->end(),' ');
                auto it3 = it->begin();
                if(i == 0) {
                    while (it3 != it2) {
                        line += *it3;
                        it3++;
                    }
                    numRect= stoi(line);
                    it->erase(0,3);
                }
                if(i == 1){
                    while (it3 != it2){
                        line += *it3;
                        it3++;
                    }
                    n = stoi(line);
                    it->erase(0,3);
                }
                if(i == 2){
                    while (it3 != it2){
                        line += *it3;
                        it3++;
                    }
                    m = stoi(line);
                }
            }
            table = createTable(n,m);
        }
    }
}

void parseVector2(vector<string> fileRead, vector<rectangulos>& rectangles){
    char accion;
    string sr, sc, sx, sy;
    int rr,c,x,y;
    for(auto it = fileRead.begin(); it != fileRead.end();it++){
        if(it != fileRead.begin()){
            rectangulos r;
            accion = '\0';
            sr = "";
            sc = "";
            sx = "";
            sy = "";
            auto it1 = it->begin();
            auto it2 = find(it->begin(), it->end(),' ');
            it2++;
            auto it3 = find(it2, it->end(),' ');
            it3++;
            auto it4 = find(it3, it->end(),' ');
            it4++;
            auto it5 = find(it4, it->end(), ' ');
            it5++;
            while(it1 != it2){
                accion += *it1;
                it1++;
            }
            while(it2 != it3){
                sx += *it2;
                it2++;
            }
            x = stoi(sx);
            while(it3 != it4){
                sy += *it3;
                it3++;
            }
            y = stoi(sy);
            while(it4 != it5){
                sr += *it4;
                it4++;
            }
            rr = stoi(sr);
            while(it5 != it->end()){
                sc += *it5;
                it5++;
            }
            c = stoi(sc);
            r.accion = accion; r.r = rr; r.c = c; r.posx = x; r.posy = y;
            rectangles.push_back(r);
        }
    }
}

int** createTable(int n, int m){
    int** table = new int*[n];
    for(int i = 0; i < n; i++)
        table[i] = new int[m];
    return table;
}

void destroyTable(int**& table, int n){
    for(int i = 0; i < n; i++)
        delete[] table[i];
    delete[] table;
}
