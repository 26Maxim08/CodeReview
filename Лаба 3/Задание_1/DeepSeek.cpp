#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// Function to generate a random character from a given character set
char getRandomChar(const string& charSet) {
    int randomIndex = rand() % charSet.length();
    return charSet[randomIndex];
}

// Function to generate a password based on complexity level
string generatePassword(int complexity) {
    string password;
    int length;
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string digits = "0123456789";
    string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    // Determine character sets and length based on complexity
    string charSet;
    switch (complexity) {
        case 1: // Low complexity - only lowercase letters, length 6-8
            length = 6 + rand() % 3;
            charSet = lowercase;
            break;
        case 2: // Medium complexity - letters and digits, length 8-10
            length = 8 + rand() % 3;
            charSet = lowercase + uppercase + digits;
            break;
        case 3: // High complexity - all character types, length 12-16
            length = 12 + rand() % 5;
            charSet = lowercase + uppercase + digits + symbols;
            break;
        default:
            return "Invalid complexity level";
    }

    // Generate password
    for (int i = 0; i < length; ++i) {
        password += getRandomChar(charSet);
    }

    // For medium and high complexity, ensure at least one character from each required set
    if (complexity >= 2) {
        // Ensure at least one uppercase letter
        if (password.find_first_of(uppercase) == string::npos) {
            int pos = rand() % password.length();
            password[pos] = getRandomChar(uppercase);
        }
        
        // Ensure at least one digit
        if (password.find_first_of(digits) == string::npos) {
            int pos = rand() % password.length();
            password[pos] = getRandomChar(digits);
        }
    }

    // For high complexity, ensure at least one symbol
    if (complexity == 3) {
        if (password.find_first_of(symbols) == string::npos) {
            int pos = rand() % password.length();
            password[pos] = getRandomChar(symbols);
        }
    }

    return password;
}

int main() {
    // Seed the random number generator
    srand(time(0));

    cout << "Password Generator" << endl;
    cout << "==================" << endl;
    cout << "Choose complexity level:" << endl;
    cout << "1. Low (6-8 characters, lowercase letters only)" << endl;
    cout << "2. Medium (8-10 characters, letters and digits)" << endl;
    cout << "3. High (12-16 characters, letters, digits and symbols)" << endl;
    cout << "Enter your choice (1-3): ";

    int choice;
    cin >> choice;

    if (choice < 1 || choice > 3) {
        cout << "Invalid choice. Please select between 1 and 3." << endl;
        return 1;
    }

    string password = generatePassword(choice);
    cout << "\nYour generated password is: " << password << endl;
    cout << "Password length: " << password.length() << " characters" << endl;

    return 0;
}