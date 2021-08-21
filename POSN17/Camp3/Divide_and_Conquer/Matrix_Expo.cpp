/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Matrix Exponentation
    Status	: Accepted
    Created	: 19 August 2021 [10:55]
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

int R1, C1, R2, C2;

i64 MOD;

struct MATRIX {
    i64 a[5][5];
    MATRIX operator* (const MATRIX &o) const {
        MATRIX tmp;
        for(int i = 0; i < R1; i++) {
            for(int j = 0; j < C2; j++) {
                tmp.a[i][j] = 0;
                for(int k = 0; k < R2; k++) {
                    tmp.a[i][j] += a[i][k] * o.a[k][j];
                    tmp.a[i][j] %= MOD;
                }
            }
        }
        return tmp;
    }
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

MATRIX Identity = {{{1, 0, 0, 0, 0}, 
                    {0, 1, 0, 0, 0}, 
                    {0, 0, 1, 0, 0}, 
                    {0, 0, 0, 1, 0}, 
                    {0, 0, 0, 0, 1}}};

MATRIX Base;

void TESTCASE() {
    
}

MATRIX ModOfPower(i64 b) {
    if(b == 0)
        return Identity;
    if(b == 1)
        return Base;
    MATRIX prod = ModOfPower(b / 2);
    prod = prod * prod;
    if(b % 2)
        prod = prod * Base;
    return prod;
}

void solve() {
    int n;
    cin >> n;
    R1 = C1 = R2 = C2 = n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> Base.a[i][j];
        }
    }
    i64 b, c;
    cin >> b >> c;
    MOD = c;
    MATRIX ans = ModOfPower(b);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans.a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    setIO();
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
2
5 8
21 6
2 100
*/