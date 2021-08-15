/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Infix to Propostfix
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define i first
#define j second
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define pc(x) putchar(x)
#define MP make_pair
#define dec(x) fixed << setprecision(x)
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct GRAPH {
    
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

stack <int> Operand, Operator;

int cost[] = {104, 108, 116};

void solve() {
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(isalpha(s[i])) {
            Operand.push(20);
            continue;
        }
        if(isdigit(s[i])) {
            int now = cost[s[i] - '1'];
            while(!Operator.empty() && now <= Operator.top()) {
                int b = Operand.top();
                Operand.pop();
                int a = Operand.top();
                Operand.pop();
                Operand.push((a+b)*Operator.top()/100);
                Operator.pop();
            }
            Operator.push(now);
            continue;
        }
        if(s[i] == '[') {
            Operator.push(-1);
            continue;
        }
        if(s[i] == ']') {
            while(!Operator.empty() && Operator.top() != -1) {
                int b = Operand.top();
                Operand.pop();
                int a = Operand.top();
                Operand.pop();
                Operand.push((a+b)*Operator.top()/100);
                Operator.pop();
            }
            Operator.pop();
        }
    }
    while(!Operator.empty() && Operator.top() != -1) {
        int b = Operand.top();
        Operand.pop();
        int a = Operand.top();
        Operand.pop();
        Operand.push((a+b)*Operator.top()/100);
        Operator.pop();
    }
    Operator.pop();
    cout << Operand.top() << "\n";
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
A3C1D2E

A3C1[F1G3H]3D
*/