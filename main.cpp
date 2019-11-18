#include "readAndWrite.h"
#include "parseVector.h"
#include "setOut.h"

int main() {
    string ruta1 = "/home/eduardo/Desktop/Utec/Poo2/practica-calificada-3b-Marcuss17/rectangulos.in";
    string ruta2 = "/home/eduardo/Desktop/Utec/Poo2/practica-calificada-3b-Marcuss17/rectangulosFinales.out";
    auto fileRead = readFile(ruta1);
    int numRect;
    int** table;
    parseVector1(fileRead,table,numRect);
    vector<rectangulos> rectangles;
    parseVector2(fileRead,rectangles);
    auto setOut1 = setOut(rectangles);
    writeFile(ruta2,setOut1);
    //destroyTable(table,);


    return 0;
}
