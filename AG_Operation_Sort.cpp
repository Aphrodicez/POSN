/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Prefix To Postfix
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
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

char Operator[] = {'+', '-', '*', '/'};

stack <string> st;

void solve() {
    while(!st.empty())
        st.pop();
    string s;
    cin >> s;
    bool isOperator;
    string a, b;
    string Operand;
    for(int i = s.size(); i >= 0; i--) {
        isOperator = false;
        for(char x : Operator) {
            if(s[i] == x) {
                isOperator = true;
                break;
            }
        }
        if(!isOperator) {
            Operand = s[i];
            st.push(Operand);
            continue;
        }
        a = st.top();
        st.pop();
        b = st.top();
        st.pop();
        st.push(a + b + s[i]);
    }
    cout << st.top() << "\n";
    st.top();
}

int main() {
    setIO();
    int q = 1;
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
2
*-A/BC-/AKD
*+AB+CD
*/
