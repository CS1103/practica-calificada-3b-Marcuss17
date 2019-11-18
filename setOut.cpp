#include "setOut.h"

bool compare(const rectangulos& a, const rectangulos& b){
    return a.posx < b.posx;
}

vector<rectangulos> setOut(vector<rectangulos> rectangles){
    vector<rectangulos>setOut;
    auto it = rectangles.begin();
    setOut.push_back(*it);
    it++;
    bool notIn;
    for(;it != rectangles.end();it++){
        for(auto it2 : setOut){
            notIn = false;
            /*if((it->posx == it2.posx && it->posy == it2.posy) && (it->r < it2.r)){
                cout << "hola";
                notIn = true;
            }*/
            if((it->posx == it2.posx && it->posy == it2.posy)){
                notIn = true;
                break;
            }

        }
        if(!notIn){
            cout << "Voy a meter a: " << it->posx << ' ' << it->posy << endl;
            setOut.push_back(*it);
        }
    }
    sort(setOut.begin(),setOut.end(),compare);
    return setOut;
}