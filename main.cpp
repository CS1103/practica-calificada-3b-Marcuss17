#include "readAndWrite.h"
#include "parseVector.h"
#include "vectorOut.h"

int main() {
    string ruta1 = "/home/eduardo/Desktop/Utec/Poo2/practica-calificada-3b-Marcuss17/set1.in";
    string ruta2 = "/home/eduardo/Desktop/Utec/Poo2/practica-calificada-3b-Marcuss17/set1.out";
    auto fileRead = readFile(ruta1);
    int numRect, n, m;
    parseVector1(fileRead,numRect,n,m);
    auto table = createTable(n,m); //Constructor del tablero
    vector<rectangulos> rectangles;
    parseVector2(fileRead,rectangles);
    auto setOut1 = setOut(rectangles);
    writeFile(ruta2,setOut1);
    destroyTable(table,n); //Destructor del tablero
    return 0;
}
