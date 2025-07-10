/**
 * @file graph_degree.cpp
 * @brief Реализация функций для работы со степенями вершин графа
 */

#include "graph.h"

using namespace std;

Graph::Graph(const string& fileName) {
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        throw runtime_error("Failed to open file " + fileName);
    }

    inputFile >> vertexCount;
    adjacencyMatrix.resize(vertexCount, vector<int>(vertexCount));

    for (int i = 0; i < vertexCount; ++i) {
        for (int j = 0; j < vertexCount; ++j) {
            inputFile >> adjacencyMatrix[i][j];
        }
    }

    inputFile.close();
}

vector<int> Graph::calculateDegrees() const {
    vector<int> degrees(vertexCount, 0);

    for (int i = 0; i < vertexCount; ++i) {
        for (int j = 0; j < vertexCount; ++j) {
            if (adjacencyMatrix[i][j] != 0) {
                degrees[i]++;
                if (i == j) { 
                    degrees[i]++;
                }
            }
        }
    }

    return degrees;
}

void Graph::printDegrees() const {
    vector<int> degrees = calculateDegrees();
    cout << "Vertex degrees:" << endl;
    for (int i = 0; i < vertexCount; ++i) {
        cout << "Vertex " << i << ": " << degrees[i] << endl;
    }
}