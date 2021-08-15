/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Matrix Exponentation
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

const int N = 1e6 + 10;
const int M = 2e5 + 10;
const int MOD = 98765431;

int r1 = 3, r2 = 3, c2 = 3;

struct MATRIX {
    long long a[3][3];
    MATRIX operator * (const MATRIX &o) const {
        MATRIX tmp;
        for(int i = 0; i < r1; i++) {
            for(int j = 0; j < c2; j++) {
                tmp.a[i][j] = 0;
                for(int k = 0; k < r2; k++) {
                    tmp.a[i][j] += (a[i][k] * o.a[k][j]);
                    tmp.a[i][j] %= MOD;
                }
            }
        }
        return tmp;
    }
};

void TESTCASE() {
    
}
/*
[1, 1, 1][a]
[1, 0, 1][b]
[1, 1, 0][c]
*/

MATRIX dp0 = {{{1, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
/*
[1]
[0]
[0]
*/

MATRIX baseCase = {{{1, 1, 1}, {1, 0, 1}, {1, 1, 0}}};
/*
[1, 1, 1]
[1, 0, 1]
[1, 1, 0]
*/

MATRIX mIdentity = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};
/*
[1, 0, 0]
[0, 1, 0]
[0, 0, 1]
*/

MATRIX mxpo(MATRIX a, i64 b) {
    if(b == 0)
        return mIdentity;
    if(b == 1)
        return baseCase;
    MATRIX newMatrix = mxpo(a, b / 2);
    newMatrix = newMatrix * newMatrix;
    if(b % 2)
        newMatrix = newMatrix * baseCase;
    return newMatrix;
}

void solve() {
    i64 n;
    cin >> n;
    MATRIX ans = mxpo(baseCase, n) * dp0;
    i64 sum = 0;
    for(int i = 0; i < 3; i++) {
        sum += ans.a[i][0];
        sum %= MOD;
    }
    cout << sum << "\n";
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
3
1
2
3
*/