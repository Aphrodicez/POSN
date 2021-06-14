/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Matrix Chain Multiplication [Top Down]
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

const int N = 1e1 + 10;
const int M = 2e5 + 10;

int row[N], col[N], dp[N][N], path[N][N];

void print(int l, int r) {
    int mid = path[l][r];
    if(l == r) {
        cout << "A" << l;
        return ;
    }    
    cout << "(";
    print(l, mid);
    cout << " x ";
    print(mid + 1, r);
    cout << ")";
}

int divide(int l, int r) {
    if(l == r)
        return dp[l][r] = 0;
    if(dp[l][r] != 1e9)
        return dp[l][r];
    for(int mid = l; mid <= r - 1; mid++) {
        divide(l, mid);
        divide(mid + 1, r);
        if(dp[l][r] > dp[l][mid] + dp[mid + 1][r] + row[l] * col[mid] * col[r]) {
            dp[l][r] = dp[l][mid] + dp[mid + 1][r] + row[l] * col[mid] * col[r];
            path[l][r] = mid;
        }
    }
    return dp[l][r];
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> row[i] >> col[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = 1e9;
        }
    }
    divide(1, n);
    cout << dp[1][n] << '\n';
    print(1, n);
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
3
5 10
10 20
20 35
*/