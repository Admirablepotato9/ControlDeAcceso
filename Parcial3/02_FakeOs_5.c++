#include <iostream>
#include <list>
#include <fstream>
#include <string>

using namespace std;

// Definimos una estructura para almacenar la información de los usuarios
struct Users {
    string User;           // Nombre del usuario
    list<string> Files;    // Lista de archivos del usuario
};

// Función para guardar la lista de usuarios y sus archivos en archivos
void saveToFile(const list<Users>& users) {
    // Abrimos el archivo "users.usr" para guardar la lista de usuarios
    ofstream userListFile("users.usr");

    // Recorremos la lista de usuarios
    for (const auto& user : users) {
        // Guardamos el nombre del usuario en el archivo "users.usr"
        userListFile << user.User << endl;

        // Abrimos un archivo específico para el usuario (nombre_usuario.usr)
        ofstream outfile(user.User + ".usr");

        // Guardamos cada archivo del usuario en su archivo específico
        for (const auto& file : user.Files) {
            outfile << file << endl;
        }
        // Cerramos el archivo del usuario
        outfile.close();
    }

    // Cerramos el archivo "users.usr"
    userListFile.close();
}

// Función para cargar la lista de usuarios y sus archivos desde archivos
void loadFromFile(list<Users>& users) {
    // Abrimos el archivo "users.usr" para leer la lista de usuarios
    ifstream userListFile("users.usr");
    if (!userListFile.is_open()) return;

    string username;
    // Leemos cada línea (nombre de usuario) del archivo "users.usr"
    while (getline(userListFile, username)) {
        Users user;
        user.User = username;

        // Abrimos el archivo específico del usuario para leer sus archivos
        ifstream infile(user.User + ".usr");
        string line;
        // Leemos cada archivo del usuario y lo agregamos a su lista de archivos
        while (getline(infile, line)) {
            user.Files.push_back(line);
        }
        infile.close();

        // Agregamos el usuario a la lista de usuarios
        users.push_back(user);
    }

    // Cerramos el archivo "users.usr"
    userListFile.close();
}

// Función para mostrar la lista de todos los usuarios y sus archivos
void displayList(const list<Users>& users) {
    cout << "Lista de todos los usuarios y sus archivos:" << endl;
    for (const auto& user : users) {
        cout << "Usuario: " << user.User << " - Archivos: ";
        for (const auto& file : user.Files) {
            cout << file << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    list<Users> users;    // Lista de usuarios
    loadFromFile(users);  // Cargamos la lista de usuarios desde archivos

    string username;
    int menu;
    string tmp;
    bool salir = false;

    while (!salir) {
        // Mostramos el menú de opciones al usuario
        cout << "Opciones:" << endl 
             << "\t1) Ingresar usuario" << endl 
             << "\t2) Ver todos los usuarios y archivos" << endl 
             << "\t3) Salir" << endl 
             << "Selecciona una opcion:";
        cin >> menu;

        switch (menu) {
            case 1: { // Ingresar usuario
                Users* localUser = nullptr;

                // Solicitamos el nombre de usuario
                cout << "Ingresa username:";
                cin >> username;

                // Buscamos si el usuario ya existe
                for (auto& i : users) {
                    if (i.User == username) {
                        localUser = &i;
                        cout << "Usuario existe" << endl;
                        break;
                    }
                }

                // Si el usuario no existe, lo creamos
                if (localUser == nullptr) {
                    Users newUser;
                    newUser.User = username;
                    newUser.Files.clear();
                    users.push_back(newUser);
                    localUser = &(users.back());
                }

                int subMenu;
                do {
                    // Mostramos el submenú de opciones para el usuario
                    cout << "Opciones:" << endl 
                         << "\t1) Listar archivos del usuario" << endl 
                         << "\t2) Crear archivo" << endl 
                         << "\t3) Volver al menu principal" << endl 
                         << "Selecciona una opcion:";
                    cin >> subMenu;

                    switch (subMenu) {
                        case 1: // Listar archivos del usuario
                            cout << "Archivos de " << localUser->User << ":" << endl;
                            for (const auto& file : localUser->Files) {
                                cout << file << " ";
                            }
                            cout << endl << endl;
                            break;

                        case 2: // Crear archivo
                            cout << "Ingresa archivo:";
                            cin >> tmp;
                            localUser->Files.push_back(tmp);
                            break;

                        case 3: // Volver al menú principal
                        default:
                            break;
                    }
                } while (subMenu != 3);

                break;
            }

            case 2: { // Ver todos los usuarios y archivos
                displayList(users);
                break;
            }

            case 3: // Salir
                salir = true;
                cout << "Saliendo..." << endl;
                saveToFile(users); // Guardamos la lista de usuarios antes de salir
                break;

            default:
                cout << "Opcion invalida. Intenta de nuevo." << endl;
                break;
        }
    }

    return 0;
}
