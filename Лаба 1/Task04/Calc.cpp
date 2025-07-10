# include <string>
#include "Task04.h"

using namespace std;

int Calc(string s) {
    int i = s.length() - 1;
    int level = 0;
    int pos = -1;
    while (i >= 0) {
        if (s[i] == ')') {
            level++;
        }
        else if (s[i] == '(') {
            level--;
        }
        else if (level == 0 && (s[i] == '+' || s[i] == '-')) {
            pos = i;
            break;
        }
        i--;
    }

    if (pos == -1) {
        return Term(s);
    }

    char op = s[pos];
    if (op == '+') {
        return Calc(s.substr(0, pos)) + Term(s.substr(pos + 1));
    }
    if (op == '-') {
        return Calc(s.substr(0, pos)) - Term(s.substr(pos + 1));
    }

    return 0;
}