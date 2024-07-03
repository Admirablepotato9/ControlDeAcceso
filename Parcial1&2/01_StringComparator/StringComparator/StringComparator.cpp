// Example program
#include <iostream>
#include <string>

using namespace std;

int main() {
    string access_key = "esquites";
    string user_key;

    cout << "enter your secret key:";
    cin >> user_key;

    if (user_key == access_key) {
        cout << "access granted!!!";
        return 5;
    }
    else {
        cout << "pinche perro metiche";
        return 1;
    }
}
