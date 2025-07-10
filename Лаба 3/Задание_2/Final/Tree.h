/**
@file Tree.h
@brief Заголовочный файл для работы с деревьями выражений
*/

#include "Node.h"
#include <vector>
#include <string>
#include <stack>
#include <cctype>

/**
 * @class Tree
 * @brief Дерево выражений
 * 
 * Класс представляет дерево выражений с методами для построения,
 * вычисления и преобразования выражения
 */
class Tree {
private:
    Node* root; ///< Корень дерева

    static bool isOperator(char c);
    static int getPriority(char op);
    vector<string> infixToPostfix(const string& expr) const;
    Node* buildTree(const vector<string>& postfix);
    void clear(Node* node);

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Tree();

    /**
     * @brief Деструктор дерева
     */
    ~Tree();

    /**
     * @brief Строит дерево из инфиксного выражения
     * @param expr Строка с выражением
     */
    void buildFromExpression(const string& expr);

    /**
     * @brief Вычисляет значение выражения
     * @param x Значение переменной x
     * @return Результат вычисления
     */
    int evaluate(int x) const;

    /**
     * @brief Преобразует дерево по правилу x*A → A*x
     */
    void transform();

    /**
     * @brief Печатает дерево в указанный поток
     * @param out Выходной поток
     */
    void print(ostream& out) const;
};

/**
 * @brief Чтение входных данных из файла
 * @param filename Имя входного файла
 * @param expression Строка для сохранения выражения
 * @param x Переменная для сохранения значения x
 * @throws runtime_error Если файл не может быть открыт или данные некорректны
 */
void readInputFile(const string& filename, string& expression, int& x);

/**
 * @brief Запись результатов в выходной файл
 * @param filename Имя выходного файла
 * @param result Результат вычисления выражения
 * @param tree Дерево выражения для печати
 * @throws runtime_error Если файл не может быть открыт
 */
void writeOutputFile(const string& filename, int result, const Tree& tree);