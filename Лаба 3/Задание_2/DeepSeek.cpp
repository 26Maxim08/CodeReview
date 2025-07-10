#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <sstream>
#include <stdexcept>

using namespace std;

// Класс узла дерева выражения
class Node {
public:
    virtual ~Node() {}
    virtual int evaluate(int x) const = 0;
    virtual string toString() const = 0;
    virtual Node* clone() const = 0;
    virtual bool isVariable() const { return false; }
};

// Класс для числовых значений
class ValueNode : public Node {
    int value;
public:
    ValueNode(int v) : value(v) {}
    int evaluate(int) const override { return value; }
    string toString() const override { return to_string(value); }
    Node* clone() const override { return new ValueNode(value); }
};

// Класс для переменной x
class VariableNode : public Node {
public:
    int evaluate(int x) const override { return x; }
    string toString() const override { return "x"; }
    Node* clone() const override { return new VariableNode(); }
    bool isVariable() const override { return true; }
};

// Класс для операций
class OperatorNode : public Node {
    char op;
    Node* left;
    Node* right;
public:
    OperatorNode(char o, Node* l, Node* r) : op(o), left(l), right(r) {}
    ~OperatorNode() { delete left; delete right; }
    
    int evaluate(int x) const override {
        int l = left->evaluate(x);
        int r = right->evaluate(x);
        switch(op) {
            case '+': return l + r;
            case '-': return l - r;
            case '*': return l * r;
            case '/': return l / r;
            case '%': return l % r;
            case '^': return (int)pow(l, r);
            default: throw runtime_error("Unknown operator");
        }
    }
    
    string toString() const override {
        return string(1, op);
    }
    
    Node* clone() const override {
        return new OperatorNode(op, left->clone(), right->clone());
    }
    
    Node* getLeft() const { return left; }
    Node* getRight() const { return right; }
    char getOperator() const { return op; }
    
    void setLeft(Node* l) { left = l; }
    void setRight(Node* r) { right = r; }
};

// Функция для определения приоритета операций
int precedence(char op) {
    static map<char, int> prec = {
        {'^', 4},
        {'*', 3}, {'/', 3}, {'%', 3},
        {'+', 2}, {'-', 2}
    };
    return prec[op];
}

// Функция для проверки, является ли символ оператором
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

// Функция для преобразования инфиксной записи в постфиксную (Обратная польская запись)
vector<string> infixToPostfix(const string& expr) {
    vector<string> output;
    stack<char> ops;
    
    for (size_t i = 0; i < expr.size(); ) {
        char c = expr[i];
        
        if (isspace(c)) {
            i++;
            continue;
        }
        
        // Обработка чисел
        if (isdigit(c)) {
            string num;
            while (i < expr.size() && isdigit(expr[i])) {
                num += expr[i++];
            }
            output.push_back(num);
            continue;
        }
        
        // Обработка переменной x
        if (c == 'x') {
            output.push_back("x");
            i++;
            continue;
        }
        
        // Обработка операторов
        if (isOperator(c)) {
            while (!ops.empty() && ops.top() != '(' && 
                   (precedence(ops.top()) > precedence(c) || 
                    (precedence(ops.top()) == precedence(c) && c != '^'))) {
                output.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.push(c);
            i++;
            continue;
        }
        
        // Обработка скобок
        if (c == '(') {
            ops.push(c);
            i++;
            continue;
        }
        
        if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                output.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.pop(); // Удаляем '('
            i++;
            continue;
        }
    }
    
    // Оставшиеся операторы
    while (!ops.empty()) {
        output.push_back(string(1, ops.top()));
        ops.pop();
    }
    
    return output;
}

// Функция для построения дерева выражения из постфиксной записи
Node* buildExpressionTree(const vector<string>& postfix) {
    stack<Node*> st;
    
    for (const string& token : postfix) {
        if (token.size() == 1 && isOperator(token[0])) {
            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();
            st.push(new OperatorNode(token[0], left, right));
        } else if (token == "x") {
            st.push(new VariableNode());
        } else {
            st.push(new ValueNode(stoi(token)));
        }
    }
    
    return st.top();
}

// Функция для преобразования дерева (x*A → A*x)
void transformTree(Node* node) {
    if (OperatorNode* opNode = dynamic_cast<OperatorNode*>(node)) {
        // Рекурсивно преобразуем поддеревья
        transformTree(opNode->getLeft());
        transformTree(opNode->getRight());
        
        if (opNode->getOperator() == '*' && 
            opNode->getLeft()->isVariable() && 
            !opNode->getRight()->isVariable()) {
            // Меняем местами левый и правый узлы
            Node* temp = opNode->getLeft();
            opNode->setLeft(opNode->getRight());
            opNode->setRight(temp);
        }
    }
}

// Функция для печати дерева в указанном формате
void printTree(ostream& out, Node* node, int level = 0) {
    if (!node) return;
    
    printTree(out, dynamic_cast<OperatorNode*>(node) ? dynamic_cast<OperatorNode*>(node)->getRight() : nullptr, level + 1);
    
    out << string(4 * level, ' ');
    if (level > 0) out << "---";
    out << node->toString() << endl;
    
    printTree(out, dynamic_cast<OperatorNode*>(node) ? dynamic_cast<OperatorNode*>(node)->getLeft() : nullptr, level + 1);
}

// Основная функция
int main() {
    ifstream fin("FN1.txt");
    ofstream fout("FN2.txt");
    
    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }
    
    // Чтение выражения из файла
    string expression;
    getline(fin, expression);
    
    // Чтение значения x
    int x;
    fin >> x;
    fin.close();
    
    try {
        // Преобразование в постфиксную запись
        vector<string> postfix = infixToPostfix(expression);
        
        // Построение дерева выражения
        Node* root = buildExpressionTree(postfix);
        
        // Вычисление значения выражения
        int result = root->evaluate(x);
        fout << "Result: " << result << endl << endl;
        
        // Преобразование дерева
        transformTree(root);
        
        // Печать преобразованного дерева
        fout << "Transformed tree:" << endl;
        printTree(fout, root);
        
        delete root;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        fout << "Error: " << e.what() << endl;
        return 1;
    }
    
    fout.close();
    return 0;
}