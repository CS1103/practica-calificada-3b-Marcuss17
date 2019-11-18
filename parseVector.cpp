#include "parseVector.h"

void parseVector1(vector<string> fileRead, int& numRect, int& n, int& m){
    string line;
    for(auto it = fileRead.begin(); it  != fileRead.end(); it++){
        if(it == fileRead.begin()){
            for(int i = 0; i < 3; i++){
                line = "";
                auto it2 = find(it->begin(), it->end(),' ');
                auto it3 = it->begin();
                if(i == 0) {
                    iterate(line,it3,it2);
                    numRect= stoi(line);
                    it->erase(0,3);
                }
                if(i == 1){
                    iterate(line,it3,it2);
                    n = stoi(line);
                    it->erase(0,3);
                }
                if(i == 2){
                    iterate(line,it3,it2);
                    m = stoi(line);
                }
            }
        }
    }
}

void parseVector2(vector<string> fileRead, vector<rectangulos>& rectangles){
    int count  = 0;
    char accion;
    string sr, sc, sx, sy;
    int rr,c,x,y;
    for(auto it = fileRead.begin(); it != fileRead.end();it++){
        if(it != fileRead.begin()){
            count++;
            rectangulos r;
            accion = '\0';
            sr = "";
            sc = "";
            sx = "";
            sy = "";
            auto it1 = it->begin();
            auto it2 = find(it->begin(), it->end(),' '); it2++;
            auto it3 = find(it2, it->end(),' '); it3++;
            auto it4 = find(it3, it->end(),' '); it4++;
            auto it5 = find(it4, it->end(), ' '); it5++;
            while(it1 != it2){
                accion += *it1;
                it1++;
            }
            try {
                if(accion != 'a')
                    throw "La instrucción no ha sido detallada!";
                else
                    r.accion = accion;
            }catch(const char* msg){
                std::cerr << msg << endl;
                break;
            }
            iterate(sx,it2,it3);
            x = stoi(sx);
            iterate(sy,it3,it4);
            y = stoi(sy);
            try{
                if(x > 60 || y > 60)
                    throw "Fuera de la tabla!";
                else{
                    r.posx = x;
                    r.posy = y;
                }
            }catch(const char* msg){
                std::cerr << msg << endl;
                break;
            }
            iterate(sr,it4,it5);
            rr = stoi(sr);
            iterate(sc,it5,it->end());
            c = stoi(sc);
            r.r = rr; r.c = c; r.posx = x; r.posy = y;
            rectangles.push_back(r);
        }
    }
    /*try{
        if(count != numRects)
            throw "Input distinto al número de rectángulos ó hubo error en el parseo";
        }catch(const char* msg){
            std::cerr << msg << endl;
        }*/
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
