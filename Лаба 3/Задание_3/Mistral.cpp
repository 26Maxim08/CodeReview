#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream inputFile("FileName"); // Открываем файл для чтения

    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    int n;
    inputFile >> n; // Читаем количество вершин

    std::vector<std::vector<int>> m(n, std::vector<int>(n));

    // Читаем матрицу смежности
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> m[i][j];
        }
    }

    // Подсчитываем степень для каждой вершины
    for (int i = 0; i < n; ++i) {
        int degree = 0;
        for (int j = 0; j < n; ++j) {
            if (m[i][j] != 0) {
                degree++;
            }
        }
        // Петля учитывается дважды
        if (m[i][i] != 0) {
            degree++;
        }
        std::cout << "Степень вершины " << i << ": " << degree << std::endl;
    }

    inputFile.close(); // Закрываем файл
    return 0;
}
