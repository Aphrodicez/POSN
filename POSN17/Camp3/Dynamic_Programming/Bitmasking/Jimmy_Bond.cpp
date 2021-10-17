/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Bitmasking
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

const int MaxN = 20;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

double a[MaxN][MaxN], dp[(1 << MaxN)];

void solve() {
    memset(dp, 0, sizeof dp);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j] /= 100;
        }
    }
    dp[0] = 1;
    for(int i = 0; i <= (1 << n) - 1; i++) {
        int cnt = __builtin_popcount(i);
        for(int j = 0; j < n; j++) {
            if(i & (1 << j))
                continue;
            dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] * a[cnt][j]);
        }
    }
    cout << fixed << setprecision(2) << dp[(1 << n) - 1] * 100 << "\n";
}

int main() {
    setIO();
    int q = 1;
    for(int i = 1; i <= q; i++) {
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
100 100
50 50

2
0 50
50 0

3
25 60 100
13 0 50
12 70 90
*/