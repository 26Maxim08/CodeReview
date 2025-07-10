/**
 * @file main.cpp
 * @brief Основной файл программы генератора паролей
 */

#include "Generate_Password.h"

int main() {
    initRandomGenerator();
    
    displayMenu();

    int choice;
    cin >> choice;

    string chars;
    int length = 0;

    if (!getPasswordParameters(choice, chars, length)) {
        cout << "Invalid choice. Exiting.\n";
        return 1;
    }

    string password = generatePassword(length, chars);
    cout << "Generated password: " << password << endl;

    return 0;
}