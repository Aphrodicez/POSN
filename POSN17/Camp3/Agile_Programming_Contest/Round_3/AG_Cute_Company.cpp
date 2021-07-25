/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Stairs]
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

const int MOD = 1e9 + 7;

void TESTCASE() {
    
}

int n;

int dp[N];

int DP(int k) {
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= min(k, i); j++) {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
    }
    return dp[n];
}

void solve() {
    memset(dp, 0, sizeof dp);
    int m, k;
    cin >> n >> k >> m;
    cout << (DP(k) - DP(m - 1) + MOD) % MOD << "\n";
}

int main() {
    setIO();
    int q;
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
4 1 1
10 7 7
3 3 2
*/