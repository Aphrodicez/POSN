/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Ad - Hoc]
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

const int N = 1e2 + 10;
const int M = 2e5 + 10;
const int MOD = 1e9 + 7;

i64 dp[N][N];

void TESTCASE() {
    
}

void solve() {
    memset(dp, 0, sizeof dp);
    int n, k;
    cin >> n >> k;
    dp[1][2] = dp[2][1] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if((i == 1 && j == 2) || (i == 2 && j == 1))
                continue;
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            dp[i][j] %= MOD;
            for(int it = 1; it <= k && j - it - 1 >= 0; it++) {
                dp[i][j] += dp[i - 1][j - it - 1] + 1;
                dp[i][j] %= MOD;
            }
            for(int it = 1; it <= k && i - it - 1 >= 0; it++) {
                dp[i][j] += dp[i - it - 1][j - 1] + 1;
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n][n] << "\n";
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
5
1 1
2 1
3 2
10 10
50 6
*/