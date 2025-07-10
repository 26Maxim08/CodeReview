#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    string FileName = "FileName.txt"; // Имя файла с матрицей смежности
    ifstream inputFile(FileName);

    if (!inputFile.is_open()) {
        cerr << "Не удалось открыть файл " << FileName << endl;
        return 1;
    }

    int n;
    inputFile >> n; // Читаем количество вершин

    vector<vector<int>> adjacencyMatrix(n, vector<int>(n));

    // Читаем матрицу смежности
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> adjacencyMatrix[i][j];
        }
    }

    inputFile.close();

    vector<int> degrees(n, 0);

    // Вычисляем степени вершин
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adjacencyMatrix[i][j] != 0) {
                degrees[i]++;
                if (i == j) { // Если петля, добавляем еще единицу
                    degrees[i]++;
                }
            }
        }
    }

    // Выводим степени вершин в порядке возрастания их номеров
    for (int i = 0; i < n; ++i) {
        cout << "Вершина " << i << ": степень = " << degrees[i] << endl;
    }

    return 0;
}