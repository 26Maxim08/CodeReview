# include <string>
#include "Task04.h"

using namespace std;

int Num(string s) {
    if (s[0] == '(' && s[s.length() - 1] == ')') {
        return Calc(s.substr(1, s.length() - 2));
    }
    else {
        return stoi(s);
    }
}