#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

struct Node {
    string val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(string v) : val(v) {}
};

// Проверка приоритета операций
int precedence(const string& op) {
    if (op == "^") return 3;
    if (op == "*" || op == "/" || op == "%") return 2;
    if (op == "+" || op == "-") return 1;
    return 0;
}

// Является ли токен оператором
bool isOperator(const string& c) {
    return c == "+" || c == "-" || c == "*" || c == "/" || c == "%" || c == "^";
}

// Парсинг выражения в токены
vector<string> tokenize(const string& expr) {
    vector<string> tokens;
    for (size_t i = 0; i < expr.length();) {
        if (isspace(expr[i])) {
            ++i;
        } else if (isdigit(expr[i])) {
            string num;
            while (i < expr.size() && isdigit(expr[i])) {
                num += expr[i++];
            }
            tokens.push_back(num);
        } else if (isalpha(expr[i])) {
            tokens.push_back(string(1, expr[i++]));
        } else {
            tokens.push_back(string(1, expr[i++]));
        }
    }
    return tokens;
}

// Преобразование инфиксной записи в постфиксную (обратная польская запись)
vector<string> toPostfix(const vector<string>& tokens) {
    vector<string> output;
    stack<string> ops;

    for (const string& token : tokens) {
        if (isdigit(token[0]) || isalpha(token[0])) {
            output.push_back(token);
        } else if (isOperator(token)) {
            while (!ops.empty() && isOperator(ops.top()) &&
                   ((precedence(ops.top()) > precedence(token)) ||
                    (precedence(ops.top()) == precedence(token) && token != "^"))) {
                output.push_back(ops.top());
                ops.pop();
            }
            ops.push(token);
        } else if (token == "(") {
            ops.push(token);
        } else if (token == ")") {
            while (!ops.empty() && ops.top() != "(") {
                output.push_back(ops.top());
                ops.pop();
            }
            ops.pop();
        }
    }
    while (!ops.empty()) {
        output.push_back(ops.top());
        ops.pop();
    }
    return output;
}

// Построение дерева по постфиксной записи
Node* buildTree(const vector<string>& postfix) {
    stack<Node*> st;
    for (const string& token : postfix) {
        if (isOperator(token)) {
            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();
            Node* node = new Node(token);
            node->left = left;
            node->right = right;
            st.push(node);
        } else {
            st.push(new Node(token));
        }
    }
    return st.top();
}

// Вычисление выражения
int eval(Node* root, int x) {
    if (!root->left && !root->right) {
        if (root->val == "x") return x;
        return stoi(root->val);
    }

    int l = eval(root->left, x);
    int r = eval(root->right, x);

    if (root->val == "+") return l + r;
    if (root->val == "-") return l - r;
    if (root->val == "*") return l * r;
    if (root->val == "/") return r != 0 ? l / r : 0;
    if (root->val == "%") return r != 0 ? l % r : 0;
    if (root->val == "^") return pow(l, r);
    return 0;
}

// Замена x*A → A*x
void transform(Node*& root) {
    if (!root) return;
    transform(root->left);
    transform(root->right);

    if (root->val == "*" && root->left && root->left->val == "x") {
        swap(root->left, root->right);
    }
}

// Печать дерева в многострочном виде
void printTree(Node* root, int indent, ofstream& out) {
    if (root) {
        printTree(root->right, indent + 4, out);
        out << setw(indent) << root->val << "\n";
        printTree(root->left, indent + 4, out);
    }
}

int main() {
    ifstream fin("FN1.txt");
    ofstream fout("FN2.txt");
    if (!fin) {
        cerr << "Ошибка открытия FN1\n";
        return 1;
    }

    string expr;
    getline(fin, expr);
    int xVal;
    fin >> xVal;
    vector<string> tokens = tokenize(expr);
    vector<string> postfix = toPostfix(tokens);
    Node* tree = buildTree(postfix);

    int result = eval(tree, xVal);
    fout << "Результат: " << result << "\n\n";

    transform(tree);

    fout << "Дерево после преобразования:\n";
    printTree(tree, 0, fout);

    return 0;
}
