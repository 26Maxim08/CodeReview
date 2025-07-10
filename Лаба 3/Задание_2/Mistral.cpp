#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cctype>
#include <cmath>
#include <iomanip>

using namespace std;

// Структура для узла дерева выражения
struct Node {
    string value;
    Node* left;
    Node* right;

    Node(const string& val) : value(val), left(nullptr), right(nullptr) {}
};

// Функция для проверки, является ли символ оператором
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

// Функция для получения приоритета оператора
int getPriority(char op) {
    if (op == '^') return 4;
    if (op == '*' || op == '/' || op == '%') return 3;
    if (op == '+' || op == '-') return 2;
    return 0;
}

// Функция для построения дерева выражения
Node* buildExpressionTree(const string& expression) {
    stack<Node*> st;
    stack<char> operators;

    for (size_t i = 0; i < expression.size(); ++i) {
        if (expression[i] == ' ') continue;
        if (expression[i] == '(') {
            operators.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                Node* right = st.top();
                st.pop();
                Node* left = st.top();
                st.pop();

                Node* node = new Node(string(1, op));
                node->left = left;
                node->right = right;
                st.push(node);
            }
            operators.pop(); // Удаляем '(' из стека
        } else if (isOperator(expression[i])) {
            while (!operators.empty() && getPriority(operators.top()) >= getPriority(expression[i])) {
                char op = operators.top();
                operators.pop();

                Node* right = st.top();
                st.pop();
                Node* left = st.top();
                st.pop();

                Node* node = new Node(string(1, op));
                node->left = left;
                node->right = right;
                st.push(node);
            }
            operators.push(expression[i]);
        } else {
            string operand;
            while (i < expression.size() && isalnum(expression[i])) {
                operand += expression[i++];
            }
            --i;
            st.push(new Node(operand));
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();

        Node* right = st.top();
        st.pop();
        Node* left = st.top();
        st.pop();

        Node* node = new Node(string(1, op));
        node->left = left;
        node->right = right;
        st.push(node);
    }

    return st.top();
}

// Функция для вычисления значения выражения
int evaluateExpression(Node* root, int x) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) {
        if (root->value == "x") return x;
        return stoi(root->value);
    }

    int leftVal = evaluateExpression(root->left, x);
    int rightVal = evaluateExpression(root->right, x);

    if (root->value == "+") return leftVal + rightVal;
    if (root->value == "-") return leftVal - rightVal;
    if (root->value == "*") return leftVal * rightVal;
    if (root->value == "/") return leftVal / rightVal;
    if (root->value == "%") return leftVal % rightVal;
    if (root->value == "^") return static_cast<int>(pow(leftVal, rightVal));

    return 0;
}

// Функция для преобразования дерева
Node* transformTree(Node* root) {
    if (root == nullptr) return nullptr;

    root->left = transformTree(root->left);
    root->right = transformTree(root->right);

    if (root->left && root->left->value == "x" && root->value == "*") {
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }

    return root;
}

// Функция для печати дерева в файл
void printTreeToFile(Node* root, ofstream& out, int level = 0) {
    if (root == nullptr) return;

    printTreeToFile(root->right, out, level + 1);

    out << setw(level * 4) << "" << root->value << endl;

    printTreeToFile(root->left, out, level + 1);
}

int main() {
    ifstream inFile("FN1.txt");
    ofstream outFile("FN2.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    string expression;
    getline(inFile, expression);
    int x;
    inFile >> x;

    Node* root = buildExpressionTree(expression);
    int result = evaluateExpression(root, x);
    outFile << "Result: " << result << endl;

    root = transformTree(root);
    printTreeToFile(root, outFile);

    inFile.close();
    outFile.close();

    return 0;
}
