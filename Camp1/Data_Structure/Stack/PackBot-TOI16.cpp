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

stack <int> stOperand, stOperator;

void solve() {
    int opr = stOperator.top();
    stOperator.pop();
    int b = stOperand.top();
    stOperand.pop();
    int a = stOperand.top();
    stOperand.pop();
    int val = (a + b) * ((100 + (1 << (opr + 1)))) / 100;
    stOperand.push(val);
}

int main() {
    scanf(" %s", s);
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        if(isalpha(s[i])) {
            stOperand.push(20);
            continue;
        }
        if(s[i] == '[') {
            stOperator.push(-1);
            continue;
        }
        if(isdigit(s[i])) {
            while(!stOperator.empty() && stOperator.top() != -1 && (s[i] - '0') <= stOperator.top()) {
                solve();
            }
            stOperator.push(s[i] - '0');
            continue;
        }
        if(s[i] == ']') {
            while(!stOperator.empty() && stOperator.top() != -1) {
                solve();
            }
            stOperator.pop();
        }
    }
    while(!stOperator.empty()) {
        solve();
    }
    printf("%d\n", stOperand.top());
    return 0;
}

/*
A3C1D2E

A3C1[F1G3H]3D
*/