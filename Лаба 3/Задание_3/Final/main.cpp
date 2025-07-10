/**
 * @file main.cpp
 * @brief Основная программа для вычисления степеней вершин графа
 */

#include "graph.h"

using namespace std;

/**
 * @brief Точка входа в программу
 * @return 0 в случае успешного выполнения, 1 при ошибке
 */
int main() {
    string fileName="FileName.txt";

    try {
        Graph graph(fileName);
        graph.printDegrees();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}