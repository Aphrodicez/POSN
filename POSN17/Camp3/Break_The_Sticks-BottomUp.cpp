/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Matrix Chain Multiplication [Bottom Up]
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

const int N = 5e1 + 10;
const int M = 2e5 + 10;

int a[N], dp[N][N];

void solve() {
    int l, n;
    cin >> l >> n;
    for(int i = 2; i <= n + 1; i++) {
        cin >> a[i];
    }
    a[n + 2] = l;
    n += 2;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = 1e9;
        }
    }
    for(int i = 1; i <= n; i++) {
        dp[i][i] = dp[i][i + 1] = 0;
    }
    for(int sz = 3; sz <= n; sz++) {
        for(int start = 1; start + sz - 1 <= n; start++) {
            int l = start, r = start + sz - 1;
            int mn = 1e9;
            for(i64 mid = l + 1; mid <= r - 1; mid++) {
                mn = min(mn, dp[l][mid] + dp[mid][r]);
            }
            dp[l][r] = a[r] - a[l] + mn;
        }
    }
    cout << dp[1][n];
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
100 3
25 50 75

10 4
4 5 7 8
*/