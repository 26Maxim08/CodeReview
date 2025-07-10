/**
 * @file password_generator.cpp
 * @brief Функциональный файл для генератора паролей
 */

#include "Generate_Password.h"

void initRandomGenerator() {
    srand(static_cast<unsigned int>(time(0)));
}

string generatePassword(int length, const string& chars) {
    string password;
    for (int i = 0; i < length; ++i) {
        password += chars[rand() % chars.size()];
    }
    return password;
}

bool getPasswordParameters(int choice, string& chars, int& length) {
    switch (choice) {
        case 1:
            chars = "abcdefghijklmnopqrstuvwxyz";
            length = 6;
            return true;
        case 2:
            chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
            length = 10;
            return true;
        case 3:
            chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789
            !@#$%^&*()-_=+[]{}<>?/|";
            length = 16;
            return true;
        default:
            return false;
    }
}

void displayMenu() {
    cout << "Password Generator\n";
    cout << "Select password strength:\n";
    cout << "1 - Easy (only lowercase letters, 6 characters)\n";
    cout << "2 - Medium (lowercase + uppercase + digits, 10 characters)\n";
    cout << "3 - Strong (all symbols, 16 characters)\n";
    cout << "Enter your choice (1/2/3): ";
}