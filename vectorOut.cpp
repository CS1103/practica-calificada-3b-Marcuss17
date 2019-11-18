#include "vectorOut.h"

bool compare(const rectangulos& a, const rectangulos& b){
    return a.posx < b.posx;
}

vector<rectangulos> setOut(vector<rectangulos> rectangles){
    vector<rectangulos>setOut;
    auto it = rectangles.begin();
    setOut.push_back(*it);
    it++;
    bool In;
    for(;it != rectangles.end();it++){
        for(auto it2 : setOut){
            In = false;
            if((it->posx == it2.posx && it->posy == it2.posy) && (it->r > it2.r || it->c > it2.c)){
                In = true;
                break;
            }
        }
        if(!In){
            setOut.push_back(*it);
        }
    }
    sort(setOut.begin(),setOut.end(),compare);
    return setOut;
}