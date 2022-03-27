/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Stack [ Infix to Propostfix ]
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e4 + 10;

char s[MaxN];

stack <int> stackOperand, stackOperator;

void solve() {
    int a = stackOperand.top();
    stackOperand.pop();
    int b = stackOperand.top();
    stackOperand.pop();
    int val = (a + b) * (100 + (1 << (stackOperator.top() + 1))) / 100;
    stackOperator.pop();
    stackOperand.push(val);
}

int main() {
    scanf(" %s", s);
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        if(isalpha(s[i])) {
            stackOperand.push(20);
            continue;
        }
        if(s[i] == '[') {
            stackOperator.push(-1);
            continue;
        }
        if(isdigit(s[i])) {
            while(!stackOperator.empty() && stackOperator.top() != -1 && (s[i] - '0') < stackOperator.top()) {
                solve();
            }
            stackOperator.push(s[i] - '0');
            continue;;
        }
        if(s[i] == ']') {
            while(!stackOperator.empty() && stackOperator.top() != -1) {
                solve();
                continue;
            }
            stackOperator.pop();
        }
    }
    while(!stackOperator.empty()) {
        solve();
    }
    printf("%d\n", stackOperand.top());
    return 0;
}

/*
A3C1D2E

A3C1[F1G3H]3D
*/