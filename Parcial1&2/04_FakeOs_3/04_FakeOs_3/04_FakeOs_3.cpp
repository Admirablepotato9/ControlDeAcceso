#include <iostream> // Incluye la biblioteca estándar para la entrada y salida
#include <list> // Incluye la biblioteca estándar para listas enlazadas
#include <string> // Incluye la biblioteca estándar para el manejo de cadenas de texto

using namespace std; // Utiliza el espacio de nombres estándar para simplificar el uso de sus componentes

// Define la estructura Users
struct Users {
    string User; // Almacena el nombre de usuario
    list<string> Files; // Almacena una lista de archivos asociados al usuario
};

int main()
{
    list<Users> users; // Declara una lista de estructuras Users
    Users user, * localUser; // Declara una variable de tipo Users y un puntero a Users
    string username; // Declara una variable para almacenar el nombre de usuario ingresado
    int salir, menu; // Declara variables para controlar el flujo del programa
    string tmp; // Declara una variable temporal para almacenar el nombre de archivo ingresado

    do
    {
        cout << "Ingresa username:"; // Solicita al usuario ingresar un nombre de usuario
        cin >> username; // Lee el nombre de usuario ingresado

        localUser = nullptr; // Inicializa el puntero localUser a nullptr

        // Recorre la lista de usuarios para verificar si el usuario ya existe
        for (auto i : users)
        {
            if (i.User == username)
            {
                localUser = &i; // Si el usuario existe, guarda su dirección en localUser
                cout << "User exists" << endl; // Informa que el usuario ya existe
                break; // Sale del bucle
            }
        }

        // Si el usuario no existe, crea uno nuevo
        if (localUser == nullptr)
        {
            user.User = username; // Asigna el nombre de usuario a la estructura user
            user.Files.clear(); // Limpia la lista de archivos de user

            users.push_back(user); // Agrega el nuevo usuario a la lista de usuarios
            localUser = &(users.back()); // Asigna la dirección del nuevo usuario a localUser
        }

        do
        {
            // Muestra el menú de opciones
            cout << "Opciones:" << endl << "\t1) Listar" << endl << "\t2) Crear" << endl << "\t3) Salir" << endl << "Selecciona una opcion:";
            cin >> menu; // Lee la opción seleccionada

            switch (menu)
            {
            case 1: // Listar archivos
                cout << "01" << endl; // Muestra un mensaje de depuración

                // Recorre la lista de archivos del usuario y los muestra
                for (auto i : localUser->Files)
                {
                    cout << i << " - ";
                }
                cout << endl << endl; // Salta a la siguiente línea y agrega un salto de línea adicional
                break;

            case 2: // Crear un nuevo archivo
                cout << "02" << endl; // Muestra un mensaje de depuración
                cout << "Ingresa archivo:"; // Solicita al usuario ingresar el nombre del archivo
                cin >> tmp; // Lee el nombre del archivo ingresado
                localUser->Files.push_back(tmp); // Agrega el archivo a la lista de archivos del usuario
                break;

            case 3: // Salir del menú
            default:
                cout << "03" << endl; // Muestra un mensaje de depuración
                break;
            }
        } while (menu != 3); // Repite el menú hasta que el usuario elija salir

        cout << "Quieres salir? (0:yes 1:no) :"; // Pregunta al usuario si desea salir del programa
        cin >> salir; // Lee la respuesta del usuario
        cout << endl; // Salta a la siguiente línea

    } while (salir == 1); // Repite todo el proceso hasta que el usuario decida salir

    // Muestra la lista de usuarios y sus archivos
    for (auto i : users)
    {
        cout << i.User << " - "; // Muestra el nombre de usuario

    }
    cout << endl << endl; // Salta a la siguiente línea y agrega un salto de línea adicional

    return 0; // Finaliza el programa
}
