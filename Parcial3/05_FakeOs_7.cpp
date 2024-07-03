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
    int salir, menu, optUser; // Variables para controlar la salida y la selección del menú
    string username, tmp, user_root, file_user; // Variables temporales para nombres de usuario y archivos
    ofstream fUser, ofRoot;   // Variables para escribir en archivos de usuario y en el archivo raíz
    ifstream ifRoot("root");  // Variable para leer del archivo raíz

    // Solicitar y verificar la contraseña maestra
    string biosPass;
    cout << "Ingresar master password_: ";
    cin >> biosPass;
    if (biosPass != "input") {
        return 2; // Salir si la contraseña es incorrecta
    }

    // Si el archivo raíz existe, cargar usuarios y sus archivos
    if (ifRoot.is_open()) {
        while (getline(ifRoot, user_root)) { // Leer cada línea del archivo raíz
            cout << "Loading user: " << user_root << '\n';
            user.User = user_root;   // Asigna el nombre del usuario
            user.Files.clear();      // Limpia la lista de archivos del usuario

            ifstream ifUser(user_root + ".usr"); // Abre el archivo del usuario para leer sus archivos
            while (getline(ifUser, file_user)) { // Leer cada archivo del usuario
                cout << file_user << " - ";
                user.Files.push_back(file_user); // Añade el archivo a la lista del usuario
            }
            cout << endl;
            users.push_back(user); // Añade el usuario a la lista de usuarios
        }
        ifRoot.close(); // Cierra el archivo raíz
    } else { // Si el archivo raíz no existe
        ofRoot.open("root"); // Crear el archivo raíz
        ofRoot.close();
    }

    // Bucle principal del menú
    do {
        cout << "MENU" << endl << "1) Listar" << endl << "2) add user" << endl;
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
                for (auto i : users) {
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
                         << "\t3) Salir" << endl
                         << "Selecciona una opcion: ";
                    cin >> menu;

                    switch (menu) {
                        case 1: // Listar archivos del usuario actual
                            cout << "01" << endl;
                            for (auto i : localUser->Files) {
                                cout << i << " - ";
                            }
                            cout << endl << endl;
                            break;

                        case 2: // Crear un nuevo archivo para el usuario actual
                            cout << "02" << endl;
                            cout << "Ingresa archivo: ";
                            cin >> tmp;
                            localUser->Files.push_back(tmp); // Añade el nuevo archivo a la lista del usuario
                            break;

                        case 3: // Salir del submenú
                        default:
                            cout << "03" << endl;
                            break;
                    }
                } while (menu != 3); // Repite el submenú hasta que el usuario elija salir
                break;
        }

        // Pregunta al usuario si desea salir del programa principal
        cout << "Quieres salir? (0:yes 1:no): ";
        cin >> salir;
        cout << endl;

    } while (salir == 1); // Repite el bucle principal hasta que el usuario decida salir

    // Guardar datos en el archivo raíz y en archivos individuales de usuarios
    ofRoot.open("root"); // Abre el archivo raíz para escritura
    for (auto i : users) {
        cout << "user_: " << i.User << endl;
        ofRoot << i.User << endl; // Escribe el nombre del usuario en el archivo raíz
        fUser.open(i.User + ".usr"); // Abre el archivo del usuario para escritura

        for (auto j : i.Files) {
            cout << "\t" << j << endl;
            fUser << j << endl; // Escribe cada archivo del usuario en su archivo correspondiente
        }

        cout << endl;
        fUser.close(); // Cierra el archivo del usuario
    }
    ofRoot.close(); // Cierra el archivo raíz
    cout << endl << endl;

    return 0;
}
