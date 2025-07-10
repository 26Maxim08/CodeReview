#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random password
string generatePassword(int length, bool useLower, bool useUpper, bool useDigits, bool useSpecial) {
    const string lowerChars = "abcdefghijklmnopqrstuvwxyz";
    const string upperChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string digitChars = "0123456789";
    const string specialChars = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    string chars;
    if (useLower) chars += lowerChars;
    if (useUpper) chars += upperChars;
    if (useDigits) chars += digitChars;
    if (useSpecial) chars += specialChars;

    string password;
    srand(time(0)); // Seed the random number generator

    for (int i = 0; i < length; ++i) {
        int randomIndex = rand() % chars.length();
        password += chars[randomIndex];
    }

    return password;
}

int main() {
    int choice;
    cout << "Choose password complexity level:" << endl;
    cout << "1. Low (8 characters, only lowercase letters)" << endl;
    cout << "2. Medium (12 characters, lowercase and uppercase letters, digits)" << endl;
    cout << "3. High (16 characters, lowercase and uppercase letters, digits, and special characters)" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    string password;
    switch (choice) {
        case 1:
            password = generatePassword(8, true, false, false, false);
            break;
        case 2:
            password = generatePassword(12, true, true, true, false);
            break;
        case 3:
            password = generatePassword(16, true, true, true, true);
            break;
        default:
            cout << "Invalid choice. Exiting." << endl;
            return 1;
    }

    cout << "Generated Password: " << password << endl;

    return 0;
}
