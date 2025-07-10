/**
@file Node.h
@brief Заголовочный файл для работы с узлами дерева
*/

#include <string>
#include <ostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * @class Node
 * @brief Узел дерева выражений
 * 
 * Класс представляет узел дерева выражений, который может содержать
 * оператор, число или переменную x
 */
class Node {
    string value; ///< Значение узла (оператор, число или "x")
    Node* left;       ///< Указатель на левое поддерево
    Node* right;      ///< Указатель на правое поддерево

public:
    /**
     * @brief Конструктор узла
     * @param val Значение узла
     */
    explicit Node(const string& val);

    /**
     * @brief Деструктор узла
     */
    ~Node();

    /**
     * @brief Вычисляет значение поддерева
     * @param x Значение переменной x
     * @return Результат вычисления
     */
    int evaluate(int x) const;

    /**
     * @brief Преобразует поддеревья вида x*A в A*x
     */
    void transform();

    /**
     * @brief Печатает дерево в указанный поток
     * @param out Выходной поток
     * @param depth Глубина узла (для форматирования)
     */
    void print(ostream& out, int depth = 0) const;

    friend class Tree;
};