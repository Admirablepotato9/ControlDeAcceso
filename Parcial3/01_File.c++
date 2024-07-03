// Incluimos las librerías necesarias para operaciones de entrada y salida
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Declaramos un objeto de tipo ofstream para manejar la escritura en archivos
    ofstream myfile;

    // Abrimos (o creamos si no existe) el archivo "example.txt"
    myfile.open("example.txt");

    // Escribimos una línea de texto en el archivo
    myfile << "Writing this to a file.\n";

    // Cerramos el archivo para asegurarnos de que se guarden los cambios
    myfile.close();

    // Finalizamos el programa
    return 0;
}
