/**
@file Tree.cpp
@brief Реализация операций с деревьями выражений и ввода/вывода
*/

#include "Tree.h"
#include <fstream>

Tree::Tree() : root(nullptr) {}

Tree::~Tree() {
    clear(root);
}

void Tree::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

void Tree::buildFromExpression(const string& expr) {
    vector<string> postfix = infixToPostfix(expr);
    root = buildTree(postfix);
}

int Tree::evaluate(int x) const {
    return root ? root->evaluate(x) : 0;
}

void Tree::transform() {
    if (root) root->transform();
}

void Tree::print(ostream& out) const {
    if (root) root->print(out);
}

bool Tree::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

int Tree::getPriority(char op) {
    if (op == '^') return 4;
    if (op == '*' || op == '/' || op == '%') return 3;
    if (op == '+' || op == '-') return 2;
    return 0;
}

vector<string> Tree::infixToPostfix(const string& expr) const {
    vector<string> output;
    stack<char> operators;
    string numBuffer;
    
    for (size_t i = 0; i < expr.size(); ++i) {
        char c = expr[i];
        
        if (isdigit(c)) {
            numBuffer += c;
            if (i + 1 == expr.size() || !isdigit(expr[i+1])) {
                output.push_back(numBuffer);
                numBuffer.clear();
            }
        }
        else if (c == 'x') {
            output.push_back("x");
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                output.push_back(string(1, operators.top()));
                operators.pop();
            }
            operators.pop();
        }
        else if (isOperator(c)) {
            if (c == '-' && (i == 0 || expr[i-1] == '(')) {
                numBuffer += c;
                continue;
            }
            
            while (!operators.empty() && getPriority(operators.top()) >= getPriority(c)) {
                output.push_back(string(1, operators.top()));
                operators.pop();
            }
            operators.push(c);
        }
    }
    
    while (!operators.empty()) {
        output.push_back(string(1, operators.top()));
        operators.pop();
    }
    
    return output;
}

Node* Tree::buildTree(const vector<string>& postfix) {
    stack<Node*> st;
    
    for (const string& token : postfix) {
        if (isOperator(token[0]) && token.size() == 1) {
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

void readInputFile(const string& filename, string& expression, int& x) {
    ifstream inputFile(filename);
    if (!inputFile) {
        throw runtime_error("Cannot open input file " + filename);
    }
    
    getline(inputFile, expression);
    if (expression.empty()) {
        throw runtime_error("Expression is empty in file " + filename);
    }
    
    if (!(inputFile >> x)) {
        throw runtime_error("Failed to read x value from file " + filename);
    }
    
    inputFile.close();
}


void writeOutputFile(const string& filename, int result, const Tree& tree) {
    ofstream outFile(filename);
    if (!outFile) {
        throw runtime_error("Cannot open output file " + filename);
    }
    
    outFile << "Result: " << result << endl << endl;
    outFile << "Transformed tree:" << endl;
    tree.print(outFile);
    outFile.close();
}