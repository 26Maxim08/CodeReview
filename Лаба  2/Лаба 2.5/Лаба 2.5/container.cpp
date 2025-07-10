#include "Container.h"


template <typename Container>
void Input(Container& container, int size) {
    int choice, value;
    cout << "Выберите метод ввода для контейнера:" << endl;
    cout << "1) Ввод с клавиатуры." << endl;
    cout << "2) Случайная генерация." << endl;
    cout << "3) Ввод из текстового файла." << endl;
    cin >> choice;

    if (size < 2 || size % 2 != 0) {
        cout << "Ошибка: Недопустимый размер. Размер должен быть четным и не менее 2." << endl;
        return;
    }

    switch (choice) {
    case 1:
        for (int i = 0; i < size; ++i) {
            cout << "Введите элемент " << i + 1 << ": ";
            cin >> value;
            container.insert(container.end(), value);
        }
        break;
    case 2:
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(-50, 50);
        for (int i = 0; i < size; ++i) {
            container.insert(container.end(), dis(gen));
        }
        break;
    case 3:
        ifstream file("a.txt", ios::in);
        if (!file) {
            cout << "Ошибка: Файл не может быть открыт." << endl;
            return;
        }
        for (int i = 0; i < size; ++i) {
            if (!(file >> value)) {
                cout << "Ошибка: В файле недостаточно элементов." << endl;
                return;
            }
            container.insert(container.end(), value);
        }
        file.close();
        break;
    default:
        cout << "Ошибка: Недопустимый метод ввода." << endl;
        break;
    }
}

template <typename Container>
void Print(const Container& container) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

template <typename Container>
void MiddleElement(Container& container) {
    auto it = container.begin();
    auto size = container.size();
    for (int i = 0; i < size / 2 - 1; ++i) {
        ++it;
    }
    auto average1 = it;
    ++it;
    auto average2 = it;
    Swap(*average1, *average2);
}
