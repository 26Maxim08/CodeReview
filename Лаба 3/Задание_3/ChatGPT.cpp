#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::string fileName = "FileName.txt"; // замените на свой путь при необходимости
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл." << std::endl;
        return 1;
    }

    int n;
    file >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    std::vector<int> degrees(n, 0);

    // Считываем матрицу смежности и считаем степени вершин
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file >> matrix[i][j];

            if (matrix[i][j]) {
                if (i == j)
                    degrees[i] += 2; // петля
                else
                    degrees[i] += matrix[i][j]; // обычное ребро
            }
        }
    }

    file.close();

    // Вывод степеней вершин
    std::cout << "Степени вершин:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Вершина " << i + 1 << ": " << degrees[i] << std::endl;
    }

    return 0;
}
