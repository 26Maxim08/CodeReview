/**
@file main.cpp
@brief Главный файл программы для обработки выражений
*/

#include "Tree.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

/**
 * @brief Основная функция программы
 * @return Код завершения (0 - успех)
 * 
 * Программа выполняет:
 * 1. Чтение выражения из файла FN1.txt
 * 2. Построение дерева выражений
 * 3. Вычисление значения при заданном x
 * 4. Преобразование дерева
 * 5. Запись результатов в файл FN2.txt
 */
int main() {
    try {
        const string inputFileName = "FN1.txt";
        const string outputFileName = "FN2.txt";

        string expression;
        int x;
        readInputFile(inputFileName, expression, x);

        Tree tree;
        tree.buildFromExpression(expression);
        int result = tree.evaluate(x);
        tree.transform();

        writeOutputFile(outputFileName, result, tree);
        
        cout << "Processing complete. Results written to " << outputFileName << endl;
        return 0;
    } 
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}