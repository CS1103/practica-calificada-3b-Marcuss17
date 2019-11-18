#include "readAndWrite.h"

vector<string> readFile(const string& ruta1){
    vector<string> fileRead;
    ifstream file;
    file.open(ruta1);
    if(!file.is_open()){cout << "Error no se pudo abrir el archivo";}
    else{
        string fila;
        string myStr;
        while(getline(file,fila)){
            stringstream ss(fila);
            getline(ss,myStr);
            fileRead.push_back(myStr);
        }
    }
    file.close();
    return fileRead;
}

void writeFile(const string& ruta2, vector<rectangulos> rects){
    ofstream file2;
    file2.open(ruta2);
    for(auto it : rects){
        char a =toupper(it.accion);
        if(a != 'A' || (it.posx > 60 || it.posy > 60))
            file2 << "ERROR" << endl;
        else
            file2 << a << ' ' << it.posx << ' ' << it.posy << ' ' << it.r << ' ' << it.c << endl;
    }
    file2.close();
}
