#include "stack.h"
   

int main() {
    setlocale(LC_ALL, "Ru");

    Stack stack;

    while (appWork(stack)) {
        cout << "\nВозвращение в меню..." << endl;
    }

    return 0;
}
