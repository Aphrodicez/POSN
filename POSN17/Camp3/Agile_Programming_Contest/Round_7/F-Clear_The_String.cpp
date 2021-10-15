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

const int MaxN = 5e2 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

int dp[MaxN][MaxN];

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i - 1; j++) {
            dp[i][j] = 0;
        }
        for(int j = i; j <= n; j++) {
            dp[i][j] = 1e9;
        }
        dp[i][i] = 1;
    }
    string a;
    cin >> a;
    a = " " + a;
    for(int sz = 2; sz <= n; sz++) {
        for(int l = 1; l + sz - 1 <= n; l++) {
            int r = l + sz - 1;
            dp[l][r] = 1 + dp[l + 1][r];
            for(int mid = l + 1; mid <= r; mid++) {
                if(a[l] != a[mid])
                    continue;
                dp[l][r] = min(dp[l][r], dp[l + 1][mid - 1] + dp[mid][r]);
            }
        }
    }
    cout << dp[1][n] << "\n";
}

int main() {
    setIO();
    int Q = 1;
    for(int i = 1; i <= Q; i++) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

/*
3 5
12
7 2 6 6 6 6 6 6 6 6 6 6
10
5 2 5 7 3 8 3 1 2 7
5
8 8 4 4 4
*/