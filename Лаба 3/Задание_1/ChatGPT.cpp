#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция генерации пароля
string generatePassword(int length, const string& chars) {
    string password;
    for (int i = 0; i < length; ++i) {
        password += chars[rand() % chars.size()];
    }
    return password;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

    cout << "Password Generator\n";
    cout << "Select password strength:\n";
    cout << "1 - Easy (only lowercase letters, 6 characters)\n";
    cout << "2 - Medium (lowercase + uppercase + digits, 10 characters)\n";
    cout << "3 - Strong (all symbols, 16 characters)\n";
    cout << "Enter your choice (1/2/3): ";

    int choice;
    cin >> choice;

    string chars;
    int length = 0;

    switch (choice) {
        case 1:
            chars = "abcdefghijklmnopqrstuvwxyz";
            length = 6;
            break;
        case 2:
            chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
            length = 10;
            break;
        case 3:
            chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}<>?/|";
            length = 16;
            break;
        default:
            cout << "Invalid choice. Exiting.\n";
            return 1;
    }

    string password = generatePassword(length, chars);
    cout << "Generated password: " << password << endl;

    return 0;
}
