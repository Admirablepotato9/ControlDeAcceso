// Incluimos las librerías necesarias para operaciones de entrada y salida y manejo de archivos
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    string line; // Variable para almacenar cada línea leída del archivo

    // Creamos un objeto ifstream para leer del archivo "example.txt"
    ifstream myfile ("example.txt");

    // Verificamos si el archivo se abrió correctamente
    if (myfile.is_open())
    {
        // Mientras haya líneas en el archivo, las leemos una a una
        while ( getline (myfile, line) )
        {
            // Mostramos la línea leída en la consola
            cout << line << '\n';
        }
        // Cerramos el archivo después de terminar de leer
        myfile.close();
    }
    else 
        // Si no se pudo abrir el archivo, mostramos un mensaje de error
        cout << "Unable to open file";

    return 0; // Finalizamos el programa
}
