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

const int N = 1e1 + 10;
const int M = 2e5 + 10;

int row[N], col[N];

int dp[N][N], path[N][N];

void print(int l, int r) {
    if(l == r) {
        cout << "A" << l;
        return ;
    }
    int mid = path[l][r];
    cout << "(";
    print(l, mid);
    cout << " x ";
    print(mid + 1, r);
    cout << ")";
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = 1e9;
        }
    }
    for(int i = 1; i <= n; i++) {
        cin >> row[i] >> col[i];
        dp[i][i] = 0;
    }
    for(int sz = 2; sz <= n; sz++) {
        for(int start = 1; start + sz - 1 <= n; start++) {
            int l = start, r = start + sz - 1;
            for(int mid = l; mid < r; mid++) {
                int cost = row[l] * col[mid] * col[r];
                if(dp[l][r] > dp[l][mid] + dp[mid + 1][r] + cost) {
                    dp[l][r] = dp[l][mid] + dp[mid + 1][r] + cost;
                    path[l][r] = mid;
                }
            }
        }
    }
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