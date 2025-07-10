/**
 * @file graph_degree.h
 * @brief Заголовочный файл для работы со степенями вершин графа
 */

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/**
 * @class Graph
 * @brief Класс, представляющий неориентированный граф на основе матрицы смежности
 */
class Graph {
private:
    int vertexCount;                 ///< Количество вершин в графе
    vector<vector<int>> adjacencyMatrix;  ///< Матрица смежности графа

public:
    /**
     * @brief Конструктор класса Graph
     * @param fileName Имя файла с матрицей смежности
     * @throws runtime_error Если файл не может быть открыт
     */
    Graph(const string& fileName);

    /**
     * @brief Вычисляет степени всех вершин графа
     * @return Вектор, где каждый элемент - степень соответствующей вершины
     * @note Петли учитываются дважды
     */
    vector<int> calculateDegrees() const;

    /**
     * @brief Выводит степени вершин в консоль
     */
    void printDegrees() const;
};
