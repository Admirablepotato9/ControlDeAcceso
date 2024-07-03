#include <iostream>
#include <list>
#include <fstream>
using namespace std;

// Estructura que representa a un usuario y su lista de archivos
struct Users {
    string User;              // Nombre del usuario
    list<string> Files;       // Lista de archivos del usuario
};

int main() {
    list<Users> users;        // Lista que contiene todos los usuarios
    Users user, *localUser;   // Estructura temporal para el usuario y puntero para el usuario local
    string username;          // Variable para almacenar el nombre del usuario ingresado
    int salir, menu, optUser; // Variables para controlar la salida y la selección del menú
    string tmp, user_root, file_user; // Variables temporales para almacenar nombres de usuario y archivos
    ofstream fuser, ofRoot;   // Variables para escribir en archivos de usuario y en el archivo raíz
    ofstream tmpFile;         // Variable para crear un archivo temporal
    ifstream ifRoot("root");  // Variable para leer del archivo raíz
    
    // Si el archivo raíz existe, cargar usuarios y sus archivos
    if (ifRoot.is_open()) {
        while (getline(ifRoot, user_root)) { // Leer cada línea del archivo raíz
            cout << "Loading user: " << user_root << endl;
            user.User = user_root;   // Asigna el nombre del usuario
            user.Files.clear();      // Limpia la lista de archivos del usuario

            ifstream fuser(user_root + ".usr"); // Abre el archivo del usuario para leer sus archivos
            cout << "Archivos dentro del usuario: ";
            while (getline(fuser, file_user)) { // Leer cada archivo del usuario
                cout << file_user << " - ";
                user.Files.push_back(file_user); // Añade el archivo a la lista del usuario
            }
            cout << endl;
            users.push_back(user); // Añade el usuario a la lista de usuarios
        }
        ifRoot.close(); // Cierra el archivo raíz
    } else { // Si el archivo raíz no existe
        tmpFile.open("root"); // Crear el archivo raíz
        tmpFile.close(); 
    }

    // Bucle principal del menú
    do {
        cout << "\nMENU: " << endl << "1) Listar" << endl << "2) Agregar usuario" << endl;
        cin >> optUser;

        switch (optUser) {
        case 1:
            // Listar todos los usuarios
            for (auto i : users) {
                cout << "user_: " << i.User << endl;
            }
            break;
        
        case 2:
            // Solicita el nombre del usuario
            cout << "Ingresa username: ";
            cin >> username;

            localUser = nullptr; // Inicializa el puntero a null

            // Busca si el usuario ya existe en la lista
            for (auto& i : users) { // Se usa referencia para evitar copia innecesaria
                if (i.User == username) {
                    localUser = &i; // Si encuentra el usuario, apunta a él
                    cout << "User exists" << endl;
                    break; // Sale del bucle si encuentra el usuario
                }
            }

            // Si el usuario no existe, crea uno nuevo
            if (localUser == nullptr) {
                user.User = username; // Asigna el nombre ingresado al nuevo usuario
                user.Files.clear(); // Limpia la lista de archivos del nuevo usuario

                users.push_back(user); // Añade el nuevo usuario a la lista de usuarios
                localUser = &(users.back()); // Apunta al nuevo usuario añadido
            }

            // Bucle para manejar las opciones del submenú
            do {
                cout << "Opciones:" << endl
                     << "\t1) Listar" << endl
                     << "\t2) Crear" << endl
                     << "\t3) Mostrar todos los usuarios y archivos" << endl
                     << "\t4) Salir" << endl
                     << "Selecciona una opcion: ";
                cin >> menu;

                switch (menu) {
                case 1: // Listar archivos del usuario actual
                    cout << "Archivos del usuario " << localUser->User << ":" << endl;
                    for (const auto& file : localUser->Files) {
                        cout << file << " - ";
                    }
                    cout << endl << endl;
                    break;

                case 2: // Crear un nuevo archivo para el usuario actual
                    cout << "Ingresa archivo: ";
                    cin >> tmp;
                    localUser->Files.push_back(tmp); // Añade el nuevo archivo a la lista del usuario
                    break;

                case 3: // Mostrar todos los usuarios y sus archivos en forma de tabla
                    cout << "Usuarios y sus archivos:" << endl;
                    for (const auto& i : users) {
                        cout << i.User << ":\t"; // Imprime el nombre del usuario seguido de dos puntos y una tabulación
                        for (const auto& file : i.Files) {
                            cout << file << "\t"; // Imprime cada archivo del usuario separado por tabulación
                        }
                        cout << endl; // Imprime un salto de línea para el siguiente usuario
                    }
                    break;

                case 4: // Salir del menú
                    break;

                default:
                    cout << "Opción no válida" << endl;
                    break;
                }
            } while (menu != 4); // Repite el menú hasta que el usuario elija salir
            break;
        }

        // Pregunta al usuario si desea salir del programa principal
        cout << "Quieres salir? (0: yes 1: no): ";
        cin >> salir;
        cout << endl;

    } while (salir == 1); // Repite el bucle principal hasta que el usuario decida salir

    // Guardar en archivo
    ofRoot.open("root"); // Abre el archivo raíz para escritura
    for (const auto& i : users) {
        cout << i.User << " - ";
        ofRoot << i.User << endl; // Escribe el nombre del usuario en el archivo raíz
        fuser.open(i.User + ".usr"); // Abre el archivo del usuario para escritura
        
        for (const auto& file : i.Files) {
            fuser << file << endl; // Escribe cada archivo del usuario en su archivo correspondiente
            cout << file << " ";
        }
        cout << endl;
        fuser.close(); // Cierra el archivo del usuario
    }
    ofRoot.close(); // Cierra el archivo raíz
    cout << "Guardado" << endl;

    return 0;
}
