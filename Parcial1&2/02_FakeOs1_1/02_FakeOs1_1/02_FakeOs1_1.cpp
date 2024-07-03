#include <iostream>  // Incluye la biblioteca iostream para entrada y salida
#include <cstdlib>   // Incluye la biblioteca cstdlib para comandos del sistema
#include <string>    // Incluye la biblioteca string para manipulación de cadenas

using namespace std; // Usa el espacio de nombres estándar para simplificar el código

int main() {
    string usuario;     // Declara una variable string para almacenar el nombre del usuario
    int opcion;         // Declara una variable entera para almacenar la opción del menú del usuario
    string directorio;  // Declara una variable string para almacenar el comando de creación de directorio

    cout << "Introduce usuario: ";  // Solicita al usuario que introduzca su nombre
    cin >> usuario;                 // Lee el nombre del usuario

    directorio = "mkdir -p " + usuario; // Construye el comando de creación de directorio
    system(directorio.c_str());         // Ejecuta el comando de creación de directorio

    cout << "\nBienvenido " + usuario;      // Da la bienvenida al usuario
    cout << "\n¿Qué quieres hacer?";        // Muestra el menú
    cout << "\n1) Crear un archivo.";       // Opción para crear un archivo
    cout << "\n2) Ver archivos.";           // Opción para ver archivos
    cout << "\n3) Salir.";                  // Opción para salir
    cout << "\n>> ";                        // Solicita la entrada del usuario
    cin >> opcion;                          // Lee la opción del menú del usuario

    switch (opcion) {  // Inicia una declaración switch para manejar las opciones del menú
    case 1: {      // Caso 1: Crear un archivo
        string archivo;                        // Declara una variable string para almacenar el nombre del archivo
        cout << "\nIntroduce el nombre del archivo: ";  // Solicita al usuario que introduzca el nombre del archivo
        cin >> archivo;                        // Lee el nombre del archivo
        string comando = "touch " + usuario + "/" + archivo; // Construye el comando de creación de archivo
        system(comando.c_str());               // Ejecuta el comando de creación de archivo
        break;                                 // Sale de la declaración switch
    }
    case 2: {      // Caso 2: Ver archivos
        string comando = "ls " + usuario;      // Construye el comando para listar archivos en el directorio del usuario
        system(comando.c_str());               // Ejecuta el comando para listar archivos
        break;                                 // Sale de la declaración switch
    }
    case 3:        // Caso 3: Salir
    default:       // Caso por defecto: Salir del programa
        exit(EXIT_SUCCESS);  // Sale del programa exitosamente
    }

    return 0;  // Retorna 0 para indicar ejecución exitosa
}
