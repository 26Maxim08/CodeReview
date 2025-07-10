# include <string>
#include "Task04.h"

using namespace std;

int Term(string s) {
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
        else if (level == 0 && s[i] == '*') {
            pos = i;
            break;
        }
        i--;
    }
    if (pos == -1) {
        return Num(s);
    }
    return Term(s.substr(0, pos)) * Num(s.substr(pos + 1));
}

